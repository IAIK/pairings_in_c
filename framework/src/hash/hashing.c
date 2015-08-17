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

#include "hash/hash_function.h"
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
	byte hash[HASH_BYTES];
	byte cache[12*BI_WORDS*4];
	memcpy(cache, key, 12*BI_WORDS*4);
	hash_function(hash, cache, 12*BI_WORDS*4);
	memcpy(res, hash, HASH_BYTES/2);
}

/**
 * Hash a an identity string to a big integer.
 * @param res the resulting big integer
 * @param id the identity string of arbitrary length
 */
void hash_id(bigint_t res, char *id) {
	byte hash[HASH_BYTES];
	hash_function(hash, id, strlen(id)*8);
	memcpy(res, hash, BI_BYTES);
}

/**
 * Updates the given Hash state with the given element in \mathbb{G}_1.
 * @param state the Hash state to be used.
 * @param g1 the elliptic curve point to be hashed.
 */
void hash_update_G1(hashState *state, const ecfp_pt g1)
{
  byte block[BLOCK_BYTES];

#if FP_BITS * 2 <= BLOCK_BITS

  memset(block, 0, BLOCK_BYTES);
  memcpy(block, g1->x, FP_BYTES);
  memcpy(block+FP_BYTES, g1->y, FP_BYTES);

  hash_update(state, block, BLOCK_BITS);

#elif FP_BITS  <= BLOCK_BITS

  print_value(g1->x, FP_WORDS);
  memset(block, 0, BLOCK_BYTES);
  memcpy(block, g1->x, FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

  memset(block, 0, BLOCK_BYTES);
  memcpy(block, g1->y, FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

#else

  #error "Currently we do not support FP_BYTES > BLOCK_BYTES!"

#endif
}

/**
 * Updates the given Hash state with the given element in \mathbb{G}_T.
 * @param state the Hash state to be used.
 * @param g1 the 12th extension field to be hashed.
 */
void hash_update_GT(hashState *state, const fp12_t gt)
{
  byte block[BLOCK_BYTES];

#if FP_BITS * 3 <= BLOCK_BITS

  memset(block, 0, BLOCK_BYTES);
  memcpy(block,              gt[0][0][0], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[0][0][1], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[0][1][0], FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

  memset(block, 0, BLOCK_BYTES);
  memcpy(block,              gt[0][1][1], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[1][0][0], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[1][0][1], FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

  memset(block, 0, BLOCK_BYTES);
  memcpy(block,              gt[1][1][0], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[1][1][1], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[2][0][0], FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

  memset(block, 0, BLOCK_BYTES);
  memcpy(block,              gt[2][0][1], FP_BYTES);
  memcpy(block+FP_BYTES,     gt[2][1][0], FP_BYTES);
  memcpy(block+(2*FP_BYTES), gt[2][1][1], FP_BYTES);
  hash_update(state, block, BLOCK_BITS);

#elif FP_BITS  <= BLOCK_BITS

  memset(block, 0, 64); memcpy(block, gt[0][0][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[0][0][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[0][1][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[0][1][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[1][0][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[1][0][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[1][1][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[1][1][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[2][0][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[2][0][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[2][1][0], FP_BYTES); hash_update(state, block, BLOCK_BITS);
  memset(block, 0, 64); memcpy(block, gt[2][1][1], FP_BYTES); hash_update(state, block, BLOCK_BITS);

#else

  #error "Currently we do not support FP_BYTES > BLOCK_BYTES!"

#endif
}
