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

extern const bbkem_pk BB1_PK;
extern const bbkem_public BB1_PUBLIC;

/**
 * Encapsulation routine of the BB1 IBE KEM. Uses the recipient's identity
 * string to establish a session key and a ciphertext decryptable only by the
 * intended recipient.
 * @param key 		the resulting session key
 * @param cipher	the resulting ciphertext
 * @param id		the identity string of the recipient
 */
void encapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id) {
	bigint_t s, factor, id_bi;
	ecpoint_fp p;
	fp12_t k;

	cprng_get_bytes(s, BI_BYTES);

	fp_rdc_n(s);		                          // reduce random number s by group order (constant time!)

	hash_id(id_bi, id);

	// this multiplication needs to have constant runtime
	fp_mul_barett_var(factor, id_bi, s, EC_PARAM_N, EC_PARAM_MU_N);

	// s*g3 + factor*g1 ... => interleaved calculation?
	ecfp_mul(&(cipher->c1), (const ecfp_pt) &(BB1_PUBLIC.g3), s);

	ecfp_mul(&(cipher->c0), (const ecfp_pt) &(BB1_PUBLIC.g1), factor);
	ecfp_add_affine(&(cipher->c1), &(cipher->c1), &(cipher->c0));

	ecfp_mul(&(cipher->c0), (const ecfp_pt) &(BB1_PUBLIC.g), s);

	fp12_exp_cyclotomic(k, BB1_PUBLIC.v0, s);	// precompute v0^(bits/2) and interleave?

#ifdef MONTGOMERY_ARITHMETIC
	ecfp_from_montgomery(&(cipher->c0), &(cipher->c0));
	ecfp_from_montgomery(&(cipher->c1), &(cipher->c1));
	fp12_from_montgomery(k, (const fp4_t *) k);
#endif

#ifdef REAL_LAZY_REDUCTION
	fp12_rdc(k);
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
void decapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id) {
	fp12_t p_res;

#ifdef MONTGOMERY_ARITHMETIC
	ecpoint_fp c0, c1;

	ecfp_to_montgomery(&c0, &(cipher->c0));
	ecfp_to_montgomery(&c1, &(cipher->c1));
	ecfp_neg_affine(&c1);
	pbc_map_opt_ate_mul(p_res, &c0, &(BB1_PK.d0), &c1, &(BB1_PK.d1));
	fp12_from_montgomery(p_res, (const fp4_t*) p_res);
#else
	pbc_map_opt_ate_div(p_res, &(cipher->c0), &(BB1_PK.d0), &(cipher->c1), &(BB1_PK.d1));
#endif

#ifdef REAL_LAZY_REDUCTION
	fp12_rdc(p_res);
#endif

	hash_key(key, p_res);
}
