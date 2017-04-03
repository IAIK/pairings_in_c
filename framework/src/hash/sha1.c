/****************************************************************************
**
** Copyright (C) 2015 Stiftung Secure Information and
**                    Communication Technologies SIC and
**                    Graz University of Technology
** Contact: http://opensource.iaik.tugraz.at
**
**
** Commercial License Usage
** Licensees holding valid commercial licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and SIC. For further information
** contact us at http://opensource.iaik.tugraz.at.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** This software is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this software. If not, see http://www.gnu.org/licenses/.
**
**
****************************************************************************/

#include <stdint.h>
#include <string.h>
#include "types.h"
#include "hash/sha1.h"

/* init SHA1 state */
const uint32_t H0_ROM = 0x67452301;
const uint32_t H1_ROM = 0xEFCDAB89;
const uint32_t H2_ROM = 0x98BADCFE;
const uint32_t H3_ROM = 0x10325476;
const uint32_t H4_ROM = 0xC3D2E1F0;

#define leftrotate(value,bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

/**
 * Performs a SHA1 hash calculation.
 * @param result the resulting big integer to be used by e.g. ECDSA
 * @param message the message to be hashed
 * @param length the number of bytes to be hashed
 */
void sha1_hash(word_t* result, const uint8_t* message, uint32_t length) {
    HASH_SHA1 state;
    sha1_init_state(&state);
    sha1_process_message_final(&state, message, length, length);
    sha1_state_to_bigint(&state, result);
}

/**
 * Initialize the state variable.
 * @param state the state to initialize
 */
void sha1_init_state(HASH_SHA1* state) {
    state->H0 = H0_ROM;
    state->H1 = H1_ROM;
    state->H2 = H2_ROM;
    state->H3 = H3_ROM;
    state->H4 = H4_ROM;
}

/**
 * Process a 512-bit block (w) to update the current hash state
 * @param state the hash state to update
 * @param w already prepared uint32_t[16] array used to update the state (is overwritten during the calculation)
 */
void sha1_process_block(HASH_SHA1* state, uint32_t *w) {
    int i;
    uint32_t ST_A,ST_B,ST_C,ST_D,ST_E,ST_F,ST_K,ST_T;

    /* init state */
    ST_A = state->H0;
    ST_B = state->H1;
    ST_C = state->H2;
    ST_D = state->H3;
    ST_E = state->H4;

    /* perform 80 rounds */
    for (i=0; i<=79; i++) {
        if (i<=19) {
            ST_F = ST_D ^ (ST_B & (ST_C ^ ST_D));
            ST_K = 0x5A827999;
        } else if (i<=39) {
            ST_F = ST_B ^ ST_C ^ ST_D;
            ST_K = 0x6ED9EBA1;
        } else if (i<=59) {
            ST_F = (ST_B & ST_C) | (ST_D & (ST_B | ST_C));
            ST_K = 0x8F1BBCDC;
        } else {
            ST_F = ST_B ^ ST_C ^ ST_D;
            ST_K = 0xCA62C1D6;
        }

        if (i>=16) {
            ST_T = leftrotate(w[(i+13)&15] ^ w[(i+8)&15] ^ w[(i+2)&15] ^ w[i&15], 1);
            w[i&15] = ST_T;
        }

        ST_T = leftrotate(ST_A, 5) + ST_F + ST_E + ST_K + w[i&15];
        ST_E = ST_D;
        ST_D = ST_C;
        ST_C = leftrotate(ST_B, 30);
        ST_B = ST_A;
        ST_A = ST_T;
    }

    state->H0 += ST_A;
    state->H1 += ST_B;
    state->H2 += ST_C;
    state->H3 += ST_D;
    state->H4 += ST_E;
}

/**
 * Converts the message to a block and calls sha1_process_block
 * @param state
 * @param message
 */
void sha1_process_message(HASH_SHA1* state, const uint8_t *message) {
    int i;
    uint32_t w[16];
    uint32_t temp;

    /* copy message into the message block w */
    for (i=0; i<16*4; i+=4) {
        temp =  (((uint32_t)message[i]) & 0xFF) << 24;
        temp |= (((uint32_t)message[i+1]) & 0xFF) << 16;
        temp |= (((uint32_t)message[i+2]) & 0xFF) <<  8;
        temp |= ((uint32_t)message[i+3]) & 0xFF;
        w[i/4] = temp;
    }

    sha1_process_block(state, w);
}

/**
 * Finalizes the sha1 hash calculation.
 * @param state the current state of the hash calculation --> will contain the final hash value.
 * @param message the remaining message to be signed. The buffer must be a multiple of 64 s.t. message padding can be done by this function directly.
 * @param remaining_length the number of remaining bytes within "message"
 * @param total_length the total number of bytes signed
 *
 * (total_length - remaining_length) should already been processed using sha1_process_message or sha1_process_block.
 * (total_length - remaining_length) must be a multiple of 64!!
 */
void sha1_process_message_final(HASH_SHA1* state, const uint8_t *message, uint32_t remaining_length, uint32_t total_length) {
    uint32_t i;
    uint32_t w[16];
    uint32_t temp;

    /* debug_assert(total_length >= remaining_length, "total_length > remaining_length"); */
    /* debug_assert((total_length - remaining_length) % 64 == 0, "(total_length - remaining_length) % 64 == 0"); */

    while(remaining_length >= 64) {
        /* copy message into the message block w */
        for (i=0; i<16*4; i+=4) {
            temp =  (((uint32_t)message[i])   & 0xFF) << 24;
            temp |= (((uint32_t)message[i+1]) & 0xFF) << 16;
            temp |= (((uint32_t)message[i+2]) & 0xFF) <<  8;
            temp |=  ((uint32_t)message[i+3]) & 0xFF;
            w[i/4] = temp;
        }

        sha1_process_block(state, w);
        message += 64;
        remaining_length -= 64;
    }

    for(i=0; i<16; i++)
        w[i] = 0;

    /* copy message into the message block w */
    for (i=0; i<remaining_length; i++) {
        w[i/4] |= (((uint32_t)message[i]) & 0xFF) << ((~i & 3) * 8);
    }

    /* do message padding */
    w[remaining_length >> 2] |= 0x80L << ((~remaining_length & 3)*8);

    if(remaining_length < 56) {
        w[15] = total_length * 8;
        sha1_process_block(state, w);
    } else {
        sha1_process_block(state, w);

        for(i=0; i<15; i++)
            w[i] = 0;

        w[15] = total_length * 8;
        sha1_process_block(state, w);
    }
}

/**
 * Converts the resulted hash state to a uint8_t* message
 * @param state
 * @param message
 */
void sha1_state_to_byte_array(HASH_SHA1* state, uint8_t *message) {
    message[0] = state->H0 >> 24;
    message[1] = state->H0 >> 16;
    message[2] = state->H0 >> 8;
    message[3] = state->H0;
    message[4] = state->H1 >> 24;
    message[5] = state->H1 >> 16;
    message[6] = state->H1 >> 8;
    message[7] = state->H1;
    message[8] = state->H2 >> 24;
    message[9] = state->H2 >> 16;
    message[10] = state->H2 >> 8;
    message[11] = state->H2;
    message[12] = state->H3 >> 24;
    message[13] = state->H3 >> 16;
    message[14] = state->H3 >> 8;
    message[15] = state->H3;
    message[16] = state->H4 >> 24;
    message[17] = state->H4 >> 16;
    message[18] = state->H4 >> 8;
    message[19] = state->H4;
}


/**
 * Converts the given hash (state) to a big integer
 * @param state the hash to convert
 * @param result the big integer memory to use (make sure it is big enough)
 */
void sha1_state_to_bigint(HASH_SHA1* state, word_t* result) {
    #if (BYTES_PER_WORD == 1)
        result[19] = state->H0 >> 24;
        result[18] = state->H0 >> 16;
        result[17] = state->H0 >> 8;
        result[16] = state->H0;
        result[15] = state->H1 >> 24;
        result[14] = state->H1 >> 16;
        result[13] = state->H1 >> 8;
        result[12] = state->H1;
        result[11] = state->H2 >> 24;
        result[10] = state->H2 >> 16;
        result[9] = state->H2 >> 8;
        result[8] = state->H2;
        result[7] = state->H3 >> 24;
        result[6] = state->H3 >> 16;
        result[5] = state->H3 >> 8;
        result[4] = state->H3;
        result[3] = state->H4 >> 24;
        result[2] = state->H4 >> 16;
        result[1] = state->H4 >> 8;
        result[0] = state->H4;
    #elif (BYTES_PER_WORD == 2)
        result[9] = state->H0 >> 16;
        result[8] = state->H0;
        result[7] = state->H1 >> 16;
        result[6] = state->H1;
        result[5] = state->H2 >> 16;
        result[4] = state->H2;
        result[3] = state->H3 >> 16;
        result[2] = state->H3;
        result[1] = state->H4 >> 16;
        result[0] = state->H4;
    #elif (BYTES_PER_WORD == 4)
        result[4] = state->H0;
        result[3] = state->H1;
        result[2] = state->H2;
        result[1] = state->H3;
        result[0] = state->H4;
    #else
    #error to be done
    #endif
}

/* EOF */



