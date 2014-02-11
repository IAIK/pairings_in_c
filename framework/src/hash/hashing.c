/*
 * hashing.c
 *
 *  Hashing operations for protocols.
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#include "hash/sha256.h"
#include "types.h"
#include <string.h>

/**
 * Hash a fp12_t element to a 128-bit key. The user must
 * ensure that the array represented by res is of appropriate
 * size.
 * @param res the resulting 128-bit key
 * @param key the element to be hashed
 */
void hash_key(byte *res, fp12_t key) {
	byte hash[SHA256_HASH_BYTES];
	sha256(hash, key, BYTES_PER_WORD*BI_WORDS*12*8);
	memcpy(res, hash, SHA256_HASH_BYTES/2);
}

/**
 * Hash a an identity string to a big integer.
 * @param res the resulting big integer
 * @param id the identity string of arbitrary length
 */
void hash_id(bigint_t res, const char *id) {
	byte hash[SHA256_HASH_BYTES];
	sha256(hash, id, strlen(id)*8);
	memcpy(res, hash, BI_BYTES);
}
