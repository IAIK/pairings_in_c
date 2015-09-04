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

#include "hash/sha1.h"
#include "types.h"

#define CPRNG_SIZE 	20
#define HASH_LEN	20


byte CPRNGState[CPRNG_SIZE];		// seed needs to be initialized, for now we assume memory to be initialized randomly

/**
 * One-way function used to create CPRNG. Delegates to
 * SHA-1.
 * @param hash the hash resulting from the one-way function
 * @param msg the message to be hashed
 * @param len the length of the message
 */
void cprng_one_way_func(byte *hash, byte *msg, length_t len) {
    HASH_SHA1 state;
    sha1_init_state(&state);
    sha1_process_message_final(&state, msg, len, len);
    sha1_state_to_byte_array(&state, hash);
}

/**
 * Cryptographically secure pseudo-random number generator
 * based on FIPS186-2 standard.
 * @param buffer the buffer to be filled with random bytes
 * @param size the size of the buffer in byte
 */
void cprng_get_bytes(void *buffer, length_t size) {
	byte carry, c0, c1, r0, r1;
	int i, j;
	byte hash[HASH_LEN];
	byte *buf = (byte*)buffer;

	j = 0;
	while (j < size) {
		// x = G(t, XKEY)
		cprng_one_way_func(hash, CPRNGState, CPRNG_SIZE);

		// XKEY = (XKEY + x + 1) mod 2^b, where b = number of bits of CPRNG
		carry = 1;
		for (i = 0; i < CPRNG_SIZE; i++) {
			r0 = (byte) (CPRNGState[i] + hash[i]);
			c0 = (byte) (r0 < hash[i]);
			r1 = (byte) (r0 + carry);
			c1 = (byte) (r1 < r0);
			carry = (byte) (c0 | c1);
			CPRNGState[i] = r1;
		}
		for (i = 0; i < CPRNG_SIZE && j < size; i++) {
			buf[j] = hash[i];
			j++;
		}
	}
}
