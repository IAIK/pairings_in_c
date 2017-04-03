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

#include "ibe/bbkem.h"
#include "ec/ec.h"
#include "param.h"
#include "rand.h"
#include "fp/fp.h"
#include "fp/fp12.h"
#include "hash/hashing.h"
#include "pbc/pbc.h"
#include "bigint/bi.h"
#include "util.h"

/**
 * Generation of the master secret key and the public parameters
 * for the BB1 IBE key encapsulation mechanism.
 * @param msk the master secret key
 * @param params the public parameters
 */
void generate_params(bbkem_msk *msk, bbkem_public *params)
{
	ecpoint_fp2 q;

	print("prime:"); print_value(PRIME_P, BI_WORDS); print("\n");

	do {
		cprng_get_bytes(msk->alpha, BI_BYTES); fp_rdc_n(msk->alpha);
	} while (bi_compare(msk->alpha, bi_zero) == 0);

	do {
		cprng_get_bytes(msk->beta, BI_BYTES); fp_rdc_n(msk->beta);
	} while (bi_compare(msk->beta, bi_zero) == 0);

	do {
		cprng_get_bytes(msk->gamma, BI_BYTES); fp_rdc_n(msk->gamma);
	} while (bi_compare(msk->gamma, bi_zero) == 0);

	ecfp_mul(&(params->g1), &ECFP_GENERATOR, msk->alpha);
	ecfp_mul(&(params->g3), &ECFP_GENERATOR, msk->gamma);

	ecfp2_mul(&q, &ECFP2_GENERATOR, msk->beta);
	pbc_map_opt_ate(params->v0, &(params->g1), &q);
}

/**
 * Derives a user private key to be used in the BB1 IBE key encapsulation
 * mechanism from the master secret key, the public parameters, and the
 * identity string.
 * @param upk the generated user private key
 * @param msk the master secret key
 * @param params the public parameters
 * @param id the identity string
 */
void derive_private_key(bbkem_pk *upk, bbkem_msk *msk, bbkem_public *params, const char *id)
{
	bigint_t id_bi;
	fp_t r, k;

	do {
		cprng_get_bytes(r, BI_BYTES); fp_rdc_n(r);
	} while (bi_compare(r, bi_zero) == 0);

	ecfp2_mul(&(upk->d1), &ECFP2_GENERATOR, r);

	hash_id(id_bi, id);

	fp_mul_barett_var(k, id_bi, msk->alpha, EC_PARAM_N, EC_PARAM_MU_N);
	fp_add_var(k, k, msk->gamma, EC_PARAM_N);
	fp_mul_barett_var(k, k, r, EC_PARAM_N, EC_PARAM_MU_N);
	fp_mul_barett_var(r, msk->alpha, msk->beta, EC_PARAM_N, EC_PARAM_MU_N);
	fp_add_var(k, k, r, EC_PARAM_N);
	ecfp2_mul(&(upk->d0), &ECFP2_GENERATOR, k);
}

/**
 * Encapsulation routine of the BB1 IBE KEM. Uses the recipient's identity
 * string to establish a session key and a ciphertext decryptable only by the
 * intended recipient.
 * @param key 		the resulting session key
 * @param cipher	the resulting ciphertext
 * @param id		the identity string of the recipient
 */
void encapsulate_key(byte *key, bbkem_ciphertext *cipher, bbkem_public *params, const char *id) {
	bigint_t s, factor, id_bi;
	fp12_t k;

	cprng_get_bytes(s, BI_BYTES);

	fp_rdc_n(s); // reduce random number s by group order (constant time!)

	hash_id(id_bi, id);

	// this multiplication needs to have constant runtime
	fp_mul_barett_var(factor, id_bi, s, EC_PARAM_N, EC_PARAM_MU_N);

	// s*g3 + factor*g1 ... => interleaved calculation?
	ecfp_mul(&(cipher->c1), &(params->g3), s);

	ecfp_mul(&(cipher->c0), &(params->g1), factor);
	ecfp_add_affine(&(cipher->c1), &(cipher->c1), &(cipher->c0));

	ecfp_mul(&(cipher->c0), &ECFP_GENERATOR, s);

	fp12_exp_cyclotomic(k, (const fp4_t*)params->v0, s);
#ifdef MONTGOMERY_ARITHMETIC
	ecfp_from_montgomery(&(cipher->c0), &(cipher->c0));
	ecfp_from_montgomery(&(cipher->c1), &(cipher->c1));
	fp12_from_montgomery(k, (const fp4_t *) k);
#endif

	hash_key(key, k);
}


/**
 * Decapsulation routine of the BB1 IBE KEM. Takes the identity's private key
 * and the received ciphertext to compute the session key to be used. Note that
 * the current implementation does not use the identity string, but always
 * takes the same private key.
 * @param key		the resulting session key
 * @param cipher	the ciphertext to be decrypted
 * @param id		the identity string used
 */
void decapsulate_key(byte *key, bbkem_ciphertext *cipher, bbkem_public *params, bbkem_pk *upk) {
	fp12_t p_res;

#ifdef MONTGOMERY_ARITHMETIC
	ecpoint_fp c0, c1;

	ecfp_to_montgomery(&c0, &(cipher->c0));
	ecfp_to_montgomery(&c1, &(cipher->c1));
	ecfp_neg_affine(&c1);
	pbc_map_opt_ate_mul(p_res, &c0, &(upk->d0), &c1, &(upk->d1));
	fp12_from_montgomery(p_res, (const fp4_t*) p_res);
#else
	pbc_map_opt_ate_div(p_res, &(cipher->c0), &(upk->d0), &(cipher->c1), &(upk->d1));
#endif

	hash_key(key, p_res);
}
