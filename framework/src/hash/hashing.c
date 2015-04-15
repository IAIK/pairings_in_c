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

/**
 * Updates the given SHA256 context with the given element in \mathbb{G}_1.
 * @param ctx the SHA256 context to be used.
 * @param g1 the elliptic curve point to be hashed.
 */
void sha256_update_G1(sha256_ctx_t *ctx, const ecfp_pt g1)
{
  byte block[SHA256_BLOCK_BYTES];  // TODO: we might use a global variable or a reference instead!!

#if FP_BITS * 2 <= SHA256_BLOCK_BITS

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block, g1->x, FP_BYTES);
  memcpy(block+FP_BYTES, g1->y, FP_BYTES);
  sha256_nextBlock(ctx, block);

#elif FP_BITS  <= SHA256_BLOCK_BITS

  print_value(g1->x, FP_WORDS);
  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block, g1->x, FP_BYTES);
  sha256_nextBlock(ctx, block);

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block, g1->y, FP_BYTES);
  sha256_nextBlock(ctx, block);

#else

  #error "Currently we do not support FP_BYTES > SHA256_BLOCK_BYTES!"

#endif
}

void sha256_update_GT(sha256_ctx_t *ctx, const fp12_t gt)
{
  byte block[SHA256_BLOCK_BYTES]; // TODO: we might use a global variable or a reference instead!!

#if FP_BITS * 3 <= SHA256_BLOCK_BITS

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block,              gt[0][0][0], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[0][0][1], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[0][1][0], FP_BYTES);
  sha256_nextBlock(ctx, block);

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block,              gt[0][1][1], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[1][0][0], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[1][0][1], FP_BYTES);
  sha256_nextBlock(ctx, block);

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block,              gt[1][1][0], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[1][1][1], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[2][0][0], FP_BYTES);
  sha256_nextBlock(ctx, block);

  memset(block, 0, SHA256_BLOCK_BYTES);
  memcpy(block,              gt[2][0][1], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[2][1][0], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[2][1][1], FP_BYTES);
  sha256_nextBlock(ctx, block);

#elif FP_BITS  <= SHA256_BLOCK_BITS

  memset(block, 0, 64); memcpy(block, gt[0][0][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[0][0][1], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[0][1][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[0][1][1], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[1][0][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[1][0][1], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[1][1][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[1][1][1], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[2][0][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[2][0][1], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[2][1][0], FP_BYTES); sha256_nextBlock(&ctx, block);
  memset(block, 0, 64); memcpy(block, gt[2][1][1], FP_BYTES); sha256_nextBlock(&ctx, block);

#else

  #error "Currently we do not support FP_BYTES > SHA256_BLOCK_BYTES!"

#endif
}
