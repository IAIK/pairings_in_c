/*
 * hashing.h
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#ifndef HASHING_H_
#define HASHING_H_

#include "types.h"
#include "hash/sha256.h"

void hash_key(byte *res, fp12_t key);
void hash_id(bigint_t bi, const char* text);

void md_update_G1(sha256_ctx_t *ctx, const ecfp_pt g1);
void md_update_GT(sha256_ctx_t *ctx, const fp12_t gt);

#endif /* HASHING_H_ */
