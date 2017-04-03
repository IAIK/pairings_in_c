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

#include "gss/sdh_zk.h"
#include "bigint/bi.h"
#include "fp/fp.h"
#include "ec/ec.h"
#include "fp/fp12.h"
#include "pbc/pbc.h"
#include "hash/hashing.h"
#include "rand.h"

/**
 * Generates the keys according to the scheme of short group signature by BBS.
 *
 * @param number_of_members  [in]   number of secret keys that should be generated.
 * @param gpk                [out]  public key of sgs scheme.
 * @param gsk                [out]  different user secret keys to generate a valid signatures.
 * @param gmsk               [out]  group master secret key to trace a valid signature.
 *
 *
 */
void sgs_init(length_t number_of_members, group_public_key *gpk, group_master_secret_key *gmsk, group_secret_key *gsk)
{
  bigint_t inv_1, inv_2, gamma, bi_tmp, k;

  ecfp_copy_std(&gpk->g1, &ECFP_GENERATOR);
  ecfp2_copy_std(&gpk->g2, &ECFP2_GENERATOR);

  do {
    cprng_get_bytes(k, BI_BYTES); fp_rdc_n(k);
  } while (bi_compare(k, bi_zero) == 0 || bi_compare(k, bi_one) == 0);

  // generate h
  ecfp_mul(&gpk->h, &gpk->g1, k);


  do {
    cprng_get_bytes(&gmsk->xi1, BI_BYTES); fp_rdc_n(gmsk->xi1);
  } while (bi_compare(gmsk->xi1, bi_zero) == 0);

  do {
    cprng_get_bytes(&gmsk->xi2, BI_BYTES); fp_rdc_n(gmsk->xi2);
  } while (bi_compare(gmsk->xi2, bi_zero) == 0);

  fp_inv_n(inv_1, gmsk->xi1);
  fp_inv_n(inv_2, gmsk->xi2);

  // generate u, v
  ecfp_mul(&gpk->u, &gpk->h, inv_1);
  ecfp_mul(&gpk->v, &gpk->h, inv_2);

  do {
    cprng_get_bytes(gamma, BI_BYTES); fp_rdc_n(gamma);
  } while (bi_compare(gamma, bi_zero) == 0);

  // generate w
  ecfp2_mul(&gpk->w, &gpk->g2, gamma);
/*
  print("   h:   "); print_value(&gpk->h.x, BI_WORDS); print("\n");
  print("        "); print_value(&gpk->h.y, BI_WORDS); print("\n");
  print("   u:   "); print_value(&gpk->u.x, BI_WORDS); print("\n");
  print("        "); print_value(&gpk->u.y, BI_WORDS); print("\n");
  print("   v:   "); print_value(&gpk->v.x, BI_WORDS); print("\n");
  print("        "); print_value(&gpk->v.y, BI_WORDS); print("\n");
  print("   w:   "); print_value(&gpk->w.x, 2*BI_WORDS); print("\n");
  print("        "); print_value(&gpk->w.y, 2*BI_WORDS); print("\n");
  print("   xi1: "); print_value(&gmsk->xi1, BI_WORDS); print("\n");
  print("   xi2: "); print_value(&gmsk->xi2, BI_WORDS); print("\n");
*/
  for(length_t i = 0; i < number_of_members; i++) {
    do {
      cprng_get_bytes((&(gsk+i)->x), BI_BYTES); fp_rdc_n((gsk+i)->x);
    } while (bi_compare((gsk+i)->x, bi_zero) == 0);

    bi_add(bi_tmp, gamma, (gsk+i)->x); fp_rdc_n(bi_tmp);
    fp_inv_n(inv_1, bi_tmp);
    ecfp_mul((&(gsk+i)->A), &gpk->g1, inv_1);
/*
    print("   x:   "); print_value(&(gsk+i)->x, BI_WORDS); print("\n");
    print("   A:   "); print_value(&(gsk+i)->A.x, BI_WORDS); print("\n");
    print("        "); print_value(&(gsk+i)->A.y, BI_WORDS); print("\n");
*/ 
  }
}

/**
 * Generates a signature according to the scheme of short group signature by BBS.
 *
 * @param gpk        [in]  public key of sgs scheme.
 * @param gsk        [in]  user secret key to generate a valid signature.
 * @param sig        [out] computed signature.
 * @param message    [in]  the message for signature generation .
 *
 *
 */
void sgs_sign(group_public_key gpk, group_secret_key gsk, sdh_signiture *sig, const char *message) {
  bigint_t alpha, beta, delta1, delta2, bi_tmp, bi_tmp1, r_alpha, r_beta, r_x, r_delta1, r_delta2;
  ecpoint_fp G1_tmp1, G1_tmp2, R_1, R_2, R_4, R_5;
  fp12_t  GT_tmp1, R_3;
  unsigned char hash[HASH_BYTES];
  word_t bigint_tmp_dbl[2*BI_WORDS], bigint_tmp_dbl2[2*BI_WORDS];

  hashState state;

  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_clear_var_std(bigint_tmp_dbl2, 2*BI_WORDS);

  // get random values
  do {
    cprng_get_bytes(alpha, BI_BYTES); fp_rdc_n(alpha);
  } while (bi_compare(alpha, bi_zero) == 0);

  do {
    cprng_get_bytes(beta, BI_BYTES); fp_rdc_n(beta);
  } while (bi_compare(beta, bi_zero) == 0);

  // delta1
  bi_multiply(bigint_tmp_dbl, gsk.x, alpha); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(delta1, bigint_tmp_dbl, BI_WORDS);

  // delta2
  bi_multiply(bigint_tmp_dbl, gsk.x, beta); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(delta2, bigint_tmp_dbl, BI_WORDS);

  // T1
  ecfp_mul(&sig->T_1, &gpk.u, alpha);

  // T2
  ecfp_mul(&sig->T_2, &gpk.v, beta);

  // T3
  bi_add(bi_tmp, alpha, beta); //fp_rdc(bi_tmp);
  ecfp_mul(&G1_tmp1, &gpk.h, bi_tmp);
  ecfp_add_affine(&sig->T_3, &gsk.A, &G1_tmp1);

  // get random values
  do {
    cprng_get_bytes(r_alpha, BI_BYTES); fp_rdc_n(r_alpha);
  } while (bi_compare(r_alpha, bi_zero) == 0);

  do {
    cprng_get_bytes(r_beta, BI_BYTES); fp_rdc_n(r_beta);
  } while (bi_compare(r_beta, bi_zero) == 0);

  do {
    cprng_get_bytes(r_x, BI_BYTES); fp_rdc_n(r_x);
  } while (bi_compare(r_x, bi_zero) == 0);

  do {
    cprng_get_bytes(r_delta1, BI_BYTES); fp_rdc_n(r_delta1);
  } while (bi_compare(r_delta1, bi_zero) == 0);

  do {
    cprng_get_bytes(r_delta2, BI_BYTES); fp_rdc_n(r_delta2);
  } while (bi_compare(r_delta2, bi_zero) == 0);

  // R1
  ecfp_mul(&R_1, &gpk.u, r_alpha);

  // R2
  ecfp_mul(&R_2, &gpk.v, r_beta);

  // R3
  ecfp_mul(&G1_tmp1, &sig->T_3, r_x);

  bi_subtract(bi_tmp, EC_PARAM_N, r_delta1);
  bi_subtract(bi_tmp1, EC_PARAM_N, r_delta2);
  bi_add(bi_tmp, bi_tmp, bi_tmp1); fp_rdc_n(bi_tmp);
  ecfp_mul(&G1_tmp2, &gpk.h, bi_tmp);

  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);
  pbc_map_opt_ate(R_3, &G1_tmp1, &gpk.g2);

  bi_subtract(bi_tmp, EC_PARAM_N, r_alpha);
  bi_subtract(bi_tmp1, EC_PARAM_N, r_beta);
  bi_add(bi_tmp, bi_tmp, bi_tmp1); fp_rdc_n(bi_tmp);
  ecfp_mul(&G1_tmp1, &gpk.h, bi_tmp);

  pbc_map_opt_ate(GT_tmp1, &G1_tmp1, &gpk.w);

  fp12_mul(R_3, R_3, GT_tmp1);

  // R4
  ecfp_mul(&R_4, &sig->T_1, r_x);
  bi_subtract(bi_tmp, EC_PARAM_N, r_delta1);
  ecfp_mul(&G1_tmp1, &gpk.u, bi_tmp);
  ecfp_add_affine(&R_4, &R_4, &G1_tmp1);

  // R5
  ecfp_mul(&R_5, &sig->T_2, r_x);
  bi_subtract(bi_tmp, EC_PARAM_N, r_delta2);
  ecfp_mul(&G1_tmp1, &gpk.v, bi_tmp);
  ecfp_add_affine(&R_5, &R_5, &G1_tmp1);

  hash_init(&state);

  // hash message
  hash_update_message(&state, message);

  // hash T1
  hash_update_G1(&state, &sig->T_1);

  // hash T2
  hash_update_G1(&state, &sig->T_2);

  // hash T3
  hash_update_G1(&state, &sig->T_3);

  // hash R1
  hash_update_G1(&state, &R_1);

  // hash R2
  hash_update_G1(&state, &R_2);

  // hash R3
  hash_update_GT(&state, (const fp4_t*)R_3);

  // hash R4
  hash_update_G1(&state, &R_4);

  // hash R5
  hash_update_G1(&state, &R_5);

  hash_final(&state , hash, HASH_BYTES);
  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, HASH_BYTES/4);
  fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->c, bigint_tmp_dbl, BI_WORDS);

  // calculate signature values
  bi_multiply(bigint_tmp_dbl, sig->c, alpha); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_alpha, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_alpha, sig->s_alpha, r_alpha); fp_rdc_n(sig->s_alpha);

  bi_multiply(bigint_tmp_dbl, sig->c, beta); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_beta, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_beta, sig->s_beta, r_beta); fp_rdc_n(sig->s_beta);

  bi_multiply(bigint_tmp_dbl, sig->c, gsk.x); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_x, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_x, sig->s_x, r_x); fp_rdc_n(sig->s_x);

  bi_multiply(bigint_tmp_dbl, sig->c, delta1); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_delta1, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_delta1, sig->s_delta1, r_delta1); fp_rdc_n(sig->s_delta1);

  bi_multiply(bigint_tmp_dbl, sig->c, delta2); fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_delta2, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_delta2, sig->s_delta2, r_delta2); fp_rdc_n(sig->s_delta2);
}

/**
 * Verifies a signature according to the scheme of short group signatureb by BBS.
 *
 * @param gpk        [in]  public key of sgs scheme.
 * @param sig        [in]  computed signature.
 * @param message    [in]  the message for signature generation .
 *
 * @return       0 on valid signature; -1 on invalid signature;
 *
 *
 */
sbyte sgs_verify(group_public_key gpk, sdh_signiture sig, const char *message) {
  bigint_t bi_tmp, bi_tmp1, c;
  ecpoint_fp G1_tmp1, G1_tmp2, R_1, R_2, R_4, R_5;
  fp12_t  GT_tmp1, GT_tmp2, GT_tmp3, R_3;
  unsigned char hash[HASH_BYTES];
  word_t bigint_tmp_dbl[2*BI_WORDS];

  hashState state;

  // R1
  bi_subtract(bi_tmp, EC_PARAM_N, sig.c);
  ecfp_mul(&G1_tmp1, &sig.T_1, bi_tmp);
  ecfp_mul(&G1_tmp2, &gpk.u, sig.s_alpha);
  ecfp_add_affine(&R_1, &G1_tmp1, &G1_tmp2);

  // R2
  ecfp_mul(&G1_tmp1, &sig.T_2, bi_tmp);
  ecfp_mul(&G1_tmp2, &gpk.v, sig.s_beta);
  ecfp_add_affine(&R_2, &G1_tmp1, &G1_tmp2);

  // R3
  ecfp_mul(&G1_tmp1, &sig.T_3, sig.s_x);

  bi_subtract(bi_tmp, EC_PARAM_N, sig.s_delta1);
  bi_subtract(bi_tmp1, EC_PARAM_N, sig.s_delta2);
  bi_add(bi_tmp, bi_tmp, bi_tmp1); fp_rdc_n(bi_tmp);
  ecfp_mul(&G1_tmp2, &gpk.h, bi_tmp);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);
  pbc_map_opt_ate(GT_tmp1, &G1_tmp1, &gpk.g2);

  bi_subtract(bi_tmp, EC_PARAM_N, sig.s_alpha);
  bi_subtract(bi_tmp1, EC_PARAM_N, sig.s_beta);
  bi_add(bi_tmp, bi_tmp, bi_tmp1); fp_rdc_n(bi_tmp);
  ecfp_mul(&G1_tmp2, &gpk.h, bi_tmp);
  pbc_map_opt_ate(GT_tmp2, &G1_tmp2, &gpk.w);
  fp12_mul_std(GT_tmp3, (const fp4_t*)GT_tmp1, (const fp4_t*)GT_tmp2);

  ecfp_mul(&G1_tmp1, &sig.T_3, sig.c);
  ecfp_mul(&G1_tmp2, &gpk.g1, sig.c);

  pbc_map_opt_ate(GT_tmp1, &G1_tmp1, &gpk.w);

  pbc_map_opt_ate(GT_tmp2, &G1_tmp2, &gpk.g2);
  fp12_inv(GT_tmp2, (const fp4_t*)GT_tmp2);

  fp12_mul_std(GT_tmp2, (const fp4_t*)GT_tmp1, (const fp4_t*)GT_tmp2);

  fp12_mul_std(R_3, (const fp4_t*)GT_tmp3, (const fp4_t*)GT_tmp2);

  // R4
  bi_subtract(bi_tmp, EC_PARAM_N, sig.s_delta1);
  ecfp_mul(&G1_tmp1, &gpk.u, bi_tmp);
  ecfp_mul(&G1_tmp2, &sig.T_1, sig.s_x);
  ecfp_add_affine(&R_4, &G1_tmp1, &G1_tmp2);

  // R5
  bi_subtract(bi_tmp, EC_PARAM_N, sig.s_delta2);
  ecfp_mul(&G1_tmp1, &gpk.v, bi_tmp);
  ecfp_mul(&G1_tmp2, &sig.T_2, sig.s_x);
  ecfp_add_affine(&R_5, &G1_tmp1, &G1_tmp2);

  hash_init(&state);

  // hash message
  hash_update_message(&state, message);

  // hash T1
  hash_update_G1(&state, &sig.T_1);

  // hash T2
  hash_update_G1(&state, &sig.T_2);

  // hash T3
  hash_update_G1(&state, &sig.T_3);

  // hash R1
  hash_update_G1(&state, &R_1);

  // hash R2
  hash_update_G1(&state, &R_2);

  // hash R3
  hash_update_GT(&state, (const fp4_t*)R_3);

  // hash R4
  hash_update_G1(&state, &R_4);

  // hash R5
  hash_update_G1(&state, &R_5);

  hash_final(&state , hash, HASH_BYTES);
  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, HASH_BYTES/4);
  fp_rdc_2l_var(bigint_tmp_dbl, EC_PARAM_N, EC_PARAM_MU_N);
  bi_copy_var_std(c, bigint_tmp_dbl, BI_WORDS);

  unsigned int i = 0;
  for (i = 0; i < BI_WORDS; ++i) {
    if(sig.c[i] != c[i]) {
      return -1;
    }
  }
  return 0;
}

/**
 * Trace a signature to a signer.
 *
 * @param gmsk       [in]  group master secret key to trace a valid signature.
 * @param sig        [in]  computed signature.
 * @param A          [in]  part of user secret key.
 *
 *
 */
void sgs_open(group_master_secret_key gmsk, sdh_signiture sig, ecpoint_fp *A) {
  ecpoint_fp G1_tmp1, G1_tmp2;
  ecfp_mul(&G1_tmp1, &sig.T_1, gmsk.xi1);
  ecfp_mul(&G1_tmp2, &sig.T_2, gmsk.xi2);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);

  ecfp_neg_affine(&G1_tmp1);

  ecfp_add_affine(A, &sig.T_3, &G1_tmp1);
}
