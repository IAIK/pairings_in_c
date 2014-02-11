/*
 * BB1-KEM as proposed in the IEEE P1363.3 draft.
 *
 * bbkem.h
 *
 *  Created on: May 23, 2013
 *      Author: Thomas Unterluggauer
 */

#ifndef BBKEM_H_
#define BBKEM_H_

#include "types.h"

typedef struct {
	ecpoint_fp c0;
	ecpoint_fp c1;
} bbkem_ciphertext;

typedef struct {
	ecpoint_fp g;
	ecpoint_fp g1;
	ecpoint_fp g3;
	fp12_t v0;
} bbkem_public;

typedef struct {
	ecpoint_fp2 d0;
	ecpoint_fp2 d1;
} bbkem_pk;

/**
 * Generates and encapsulates a 128-bit key based on the BB1-KEM scheme
 * as proposed in the IEEE P1363.3 draft standard.
 * @param key		[out] the key that is generated during this routine (128-bit)
 * @param cipher	[out] ciphertext that encapsulates the key
 * @param id		[in]  id of the party that the cipher is destined for
 */
void encapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id);

/**
 * Decapsulates the key that is contained by the ciphertext. This process is based
 * on the BB1-KEm as proposed in the IEEE P1363.3 draft standard. The key is associated
 * with the given identity.
 * @param key		[out] the decapsulated key
 * @param cipher	[in]  ciphertext that encapsulates the key
 * @param id		[in]  the id of the party that the cipher is destined for
 */
void decapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id);

#endif /* BBKEM_H_ */
