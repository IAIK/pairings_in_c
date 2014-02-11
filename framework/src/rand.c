/*
 * rand.c
 *
 *  Implementation of a simple random number generator.
 *
 *  Created on: May 22, 2013
 *      Author: thomas
 */

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
    /*while(len >= 64) {
    	sha1_process_message(state, msg);
        msg += 64;
        len -= 64;
    }*/
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
