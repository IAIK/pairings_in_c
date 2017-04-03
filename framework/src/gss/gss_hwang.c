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

#include "types.h"
#include "rand.h"
#include "fp/fp.h"
#include "bigint/bi.h"
#include "ec/ec.h"
#include "util.h"
#include "pbc/pbc.h"
#include "fp/fp12.h"
#include "gss/gss_hwang.h"
#include "hash/hashing.h"
#include <string.h>

#define DEBUG_PRINT 1

/**
 * Generates a signature according to the scheme of HWANG.
 * @param sig    [out] computed signature.
 * @param data   [in]  public data of HWANG scheme.
 * @param usk    [in]  user secret key to generate a valid signature.
 *
 * @return       0 on success; -1 on ERROR;
 */
sbyte hwang_sign(hwang_signature_ptr sig, hwang_public_parameters_ptr data, hwang_signing_key_ptr usk)
{
  hashState state;
  unsigned char block[64];
  unsigned char hash[HASH_BYTES];
  unsigned char msg[1] = {0x01};

  bigint_t alpha, r_alpha, r_gamma, r_x, r_y;
  word_t bigint_tmp_dbl[2*BI_WORDS], bigint_tmp_dbl2[2*BI_WORDS];

  bigint_t gamma, bi_tmp;

  ecpoint_fp G1_tmp1, G1_tmp2, R_1, R_3;

  fp12_t R_2, GT_tmp1;

  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_clear_var_std(bigint_tmp_dbl2, 2*BI_WORDS);

  // Generate blinding values.
  do {
    cprng_get_bytes(alpha, BI_BYTES); fp_rdc_n(alpha);
  } while (bi_compare(alpha, bi_zero) == 0);

  do {
    cprng_get_bytes(r_alpha, BI_BYTES); fp_rdc_n(r_alpha);
  } while (bi_compare(r_alpha, bi_zero) == 0);

  do {
    cprng_get_bytes(r_gamma, BI_BYTES); fp_rdc_n(r_gamma);
  } while (bi_compare(r_gamma, bi_zero) == 0);

  do {
    cprng_get_bytes(r_x, BI_BYTES); fp_rdc_n(r_x);
  } while (bi_compare(r_x, bi_zero) == 0);

  do {
    cprng_get_bytes(r_y, BI_BYTES); fp_rdc_n(r_y);
  } while (bi_compare(r_y, bi_zero) == 0);

#if DEBUG_PRINT == 1
  PRINT_BIGINT("alpha: ", alpha);
  PRINT_BIGINT("order: ", EC_PARAM_N);
  PRINT_BIGINT("r_alpha: ", r_alpha);
  PRINT_BIGINT("r_gamma: ", r_gamma);
  PRINT_BIGINT("r_x: ", r_x);
  PRINT_BIGINT("r_y: ", r_y);
#endif

  bi_copy_var(bigint_tmp_dbl2, usk->z, BI_WORDS);
  bi_multiply(bigint_tmp_dbl, usk->x, alpha);
  bi_subtract_dbl_len(bigint_tmp_dbl, bigint_tmp_dbl, bigint_tmp_dbl2);
  fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(gamma, bigint_tmp_dbl, BI_WORDS);

  ecfp_mul(&sig->D_1, &data->u, alpha);             // D1 = u^{alpha}

  ecfp_mul(&sig->D_2, &data->w, alpha);
  ecfp_add_affine(&sig->D_2, &sig->D_2, &usk->A);   // D2 = A * w^{alpha}

  ecfp_mul(&sig->D_3, &data->g, usk->y);            // D3 = g^y
  ecfp_mul(&G1_tmp1, &data->d, alpha);              // tmp = d^{alpha}
  ecfp_add_affine(&sig->D_3, &sig->D_3, &G1_tmp1);  // D3 = g^y * d^{alpha]}

  ecfp_mul(&R_1, &data->u, r_alpha);                // R1 = u^{r_alpha}

#if DEBUG_PRINT == 1
  PRINT_G1("[sign] R_1: ", R_1);
#endif

  // R_2 = e(D_2^{r_x} * w^{-r_{gamma}} * g_2^{r_y}, h_1) * e(w^{-r_{alpha}}, h_{theta});
  bi_subtract(bi_tmp, data->order_p, r_gamma);

  ecfp_mul(&G1_tmp1, &sig->D_2, r_x);
  ecfp_mul(&G1_tmp2, &data->w, bi_tmp);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);

  ecfp_mul(&G1_tmp2, &data->g2, r_y);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);

  pbc_map_opt_ate(R_2, &G1_tmp1, &data->h1);  // e(D_2^{r_x} * w^{-r_{gamma}} * g_2^{r_y}, h_1)

  bi_subtract(bi_tmp, data->order_p, r_alpha);
  ecfp_mul(&G1_tmp1, &data->w, bi_tmp);

  pbc_map_opt_ate(GT_tmp1, &G1_tmp1, &data->h_theta);

  fp12_mul(R_2, R_2, GT_tmp1);

#if DEBUG_PRINT == 1
  PRINT_GT("[sign] R_2: ", R_2);
#endif

  //R_3 = g^{r_y} * d^{r_{alpha}}
  ecfp_mul(&R_3, &data->g, r_y);
  ecfp_mul(&G1_tmp1, &data->d, r_alpha);
  ecfp_add_affine(&R_3, &R_3, &G1_tmp1);

#if DEBUG_PRINT == 1
  PRINT_G1("[sign] R_3: ", R_3);
#endif

  hash_init(&state);

  // hash message M
  memset(block, 0, 64); memcpy(block, msg, 1); hash_update(&state, block, 64);

  // hash D1
  hash_update_G1(&state, &sig->D_1);

  // hash D2
  hash_update_G1(&state, &sig->D_2);

  // hash D3
  hash_update_G1(&state, &sig->D_3);

  // hash R1
  hash_update_G1(&state, &R_1);

  // hash R2
  hash_update_GT(&state, R_2);

  // hash R3
  hash_update_G1(&state, &R_3);

  hash_final(&state , hash, HASH_BYTES);

  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, HASH_BYTES/4);
  fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(sig->c, bigint_tmp_dbl, BI_WORDS);


  bi_multiply(bigint_tmp_dbl, sig->c, alpha); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_alpha, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_alpha, sig->s_alpha, r_alpha); fp_rdc_n(sig->s_alpha);

  bi_multiply(bigint_tmp_dbl, sig->c, usk->x); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_x, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_x, sig->s_x, r_x); fp_rdc_n(sig->s_x);

  bi_multiply(bigint_tmp_dbl, sig->c, gamma); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_gamma, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_gamma, sig->s_gamma, r_gamma); fp_rdc_n(sig->s_gamma);
  bi_multiply(bigint_tmp_dbl, sig->c, usk->y); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
  bi_copy_var_std(sig->s_y, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_y, sig->s_y, r_y); fp_rdc_n(sig->s_y);

#if DEBUG_PRINT == 1
   print(" --------- Signature --------- \n");
   PRINT_BIGINT("c: ", sig->c);
   PRINT_BIGINT("s_alpha: ", sig->s_alpha);
   PRINT_BIGINT("s_x :", sig->s_x);
   PRINT_BIGINT("s_gamma: ", sig->s_gamma);
   PRINT_BIGINT("s_y: ", sig->s_y);

   PRINT_G1("D_1: ", sig->D_1);
   PRINT_G1("D_2: ", sig->D_2);
   PRINT_G1("D_3: ", sig->D_3);
#endif

  return 0;
}


/**
 * Initializes the public parameters, the master issuing key (MIK),
 * the master opening key (MOK), and the master linking key (MLK).
 *
 */
void hwang_init_parameters(hwang_public_parameters_ptr data)
{
  bigint_t eta, xi;

  // We need the order (p) of the groups G1 and G2 to compute in Z_p
  bi_copy_var_std(data->order_p, EC_PARAM_N, BI_WORDS);

  ecfp2_rand(&data->h1); // h1 \in_R \mathbb{G_2}

  ecfp_rand(&data->g); ecfp_rand(&data->g1); ecfp_rand(&data->g2); ecfp_rand(&data->u); // g, g_1, g_2, u \in_R \mathbb{G_1}

  do {
    cprng_get_bytes(eta, BI_BYTES); fp_rdc_n(eta);
  } while (bi_compare(eta, bi_zero) == 0);

  do {
    cprng_get_bytes(xi, BI_BYTES); fp_rdc_n(xi);
  } while (bi_compare(xi, bi_zero) == 0);

  do {
    cprng_get_bytes(data->theta, BI_BYTES); fp_rdc_n(data->theta);
  } while (bi_compare(data->theta, bi_zero) == 0);


  ecfp_mul(&data->w, &data->u, eta);                 // w = u^{eta}

  ecfp_mul(&data->d, &data->u, xi);                  // d = u^{xi}

  ecfp2_mul(&data->U, &data->h1, xi);                // U = h1^{xi}

  ecfp2_mul(&data->h_theta, &data->h1, data->theta); // h_{theta} = h1^{theta}

#if DEBUG_PRINT == 1
  print("\n\n// -------------- Parameters/GPK --------------\n");
  PRINT_G1("GPK_g", data->g);
  PRINT_G2("GPK_h1", data->h1);
  PRINT_G2("GPK_h_theta", data->h_theta);
  PRINT_G1("GPK_g1", data->g1);
  PRINT_G1("GPK_g2", data->g2);
  PRINT_G1("GPK_u", data->u);
  PRINT_G1("GPK_w", data->w);
  PRINT_G1("GPK_d", data->d);

  print("\n\n// -------------- MIK --------------\n");
  PRINT_BIGINT("MIK_theta: ", data->theta);

  print("\n\n// -------------- MOK --------------\n");
  PRINT_BIGINT("MOK_eta: ", eta);
  PRINT_BIGINT("MOK_xi: ", xi);

  print("\n\n// -------------- MLK --------------\n");
  PRINT_G2("MLK_U", data->U);
#endif

}

/**
 * Generates a tuple (x, y, z, A) --- with x, y, z \in \mathbb{Z}_p^*
 * and A \in \mathbb{G}_1 --- that acts as a user's signing key.
 * @param usk  [out] the generated signing key for one user.
 * @param data [in] the public parameters.
 */
void hwang_generate_usk(hwang_signing_key_ptr usk, hwang_public_parameters_ptr data)
{
  bigint_t bi_tmp, bi_tmp1, inv;
  ecpoint_fp G1_tmp;

  // x, y, z \in_R \mathbb{Z}_p
  do {
    cprng_get_bytes(usk->x, BI_BYTES); fp_rdc_n(usk->x);
  } while (bi_compare(usk->x, bi_zero) == 0);

  do {
    cprng_get_bytes(usk->y, BI_BYTES); fp_rdc_n(usk->y);
  } while (bi_compare(usk->y, bi_zero) == 0);

  do {
    cprng_get_bytes(usk->z, BI_BYTES); fp_rdc_n(usk->z);
  } while (bi_compare(usk->z, bi_zero) == 0);


  // A = g1 * g2^{-y} * w^{-z}
  bi_subtract(bi_tmp, data->order_p, usk->y);   // negate y
  bi_subtract(bi_tmp1, data->order_p, usk->z);  // negate z
  ecfp_mul(&usk->A, &data->g2, bi_tmp);         // A = g2^{-y}
  ecfp_mul(&G1_tmp, &data->w, bi_tmp1);         //   = w^{-z}
  ecfp_add_affine(&usk->A, &usk->A, &G1_tmp);
  ecfp_add_affine(&usk->A, &usk->A, &data->g1);


  bi_add(bi_tmp, data->theta, usk->x); fp_rdc_n(bi_tmp);

  fp_inv_n(inv, bi_tmp);

  ecfp_mul(&usk->A, &usk->A, inv);    // A = (g1 * g2^{-y} * w^{-z})^{1/(theta + x)}

#if DEBUG_PRINT == 1
  print("\n\n// -------------- USK --------------\n");

  PRINT_BIGINT("USK_x: ", usk->x);
  PRINT_BIGINT("USK_y: ", usk->y);
  PRINT_BIGINT("USK_z: ", usk->z);
  PRINT_G1("USK_A: ", usk->A);
#endif
}


/**
 * Verify a group signature.
 *
 * @param data the parameters of the group-signature scheme.
 * @param sig the generated signature to be verified.
 *
 * @return 1 if the signature is VALID; -1 otherwise.
 */
sbyte hwang_verify(hwang_public_parameters_ptr data, hwang_signature_ptr sig)
{
  hashState state;
  unsigned char block[64];
  unsigned char hash[HASH_BYTES];
  unsigned char msg[1] = {0x01};

  sbyte ret = -1;
  ecpoint_fp R_1, R_3, g1_tmp1, g1_tmp2;

  fp12_t R_2, gt_tmp1, gt_tmp2, gt_tmp3;

  bigint_t bi_tmp, c;
  word_t bigint_tmp_dbl[2*BI_WORDS];

  // BEGIN: Check signature

  ecfp_mul(&R_1, &data->u, sig->s_alpha);     // R_1 = u^{s_{alpha}}

  bi_subtract(bi_tmp, data->order_p, sig->c); // negate c (mod order p);

  ecfp_mul(&g1_tmp1, &sig->D_1, bi_tmp);
  ecfp_add_affine(&R_1, &R_1, &g1_tmp1);      // R_1 = u^{s_{alpha}} * D_1^{-c}

#if DEBUG_PRINT == 1
  PRINT_G1("[verify] R_1: ", R_1);
#endif


  ecfp_mul(&g1_tmp1, &sig->D_2, sig->s_x);
  bi_subtract(bi_tmp, data->order_p, sig->s_alpha); // negate s_alpha (mod order p)
  ecfp_mul(&g1_tmp2, &data->w, bi_tmp);
  pbc_map_opt_ate_mul(gt_tmp1, &g1_tmp1, &data->h1, &g1_tmp2, & data->h_theta); // R_2 = e(D_2, h_1)^{s_x} * e(w, h_theta)^{-s_{alpha}}

  bi_subtract(bi_tmp, data->order_p, sig->s_gamma); // negate s_gamma (mod order p)
  ecfp_mul(&g1_tmp1, &data->w, bi_tmp);
  ecfp_mul(&g1_tmp2, &data->g2, sig->s_y);
  pbc_map_opt_ate_mul(gt_tmp2, &g1_tmp1, &data->h1, &g1_tmp2, &data->h1);
  fp12_mul_std(gt_tmp3, (const fp4_t*)gt_tmp1, (const fp4_t*)gt_tmp2);

  pbc_map_opt_ate_div(gt_tmp1, &sig->D_2, &data->h_theta, &data->g1, &data->h1);
  fp12_exp_std(gt_tmp2, (const fp4_t*)gt_tmp1, sig->c);
  fp12_mul_std(R_2, (const fp4_t*)gt_tmp3, (const fp4_t*)gt_tmp2);

#if DEBUG_PRINT == 1
  PRINT_GT("[verify] R_2:", R_2);
#endif

  ecfp_mul(&R_3, &data->g, sig->s_y);
  ecfp_mul(&g1_tmp1, &data->d, sig->s_alpha);
  ecfp_add_affine(&R_3, &R_3, &g1_tmp1);
  bi_subtract(bi_tmp, data->order_p, sig->c);
  ecfp_mul(&g1_tmp1, &sig->D_3, bi_tmp);
  ecfp_add_affine(&R_3, &R_3, &g1_tmp1);


#if DEBUG_PRINT == 1
  PRINT_G1("[verify] R_3:", R_3);
#endif

   hash_init(&state);

   // hash message M
   memset(block, 0, 64); memcpy(block, msg, 1); hash_update(&state, block, 64);

   // hash D1
   hash_update_G1(&state, &sig->D_1);

   // hash D2
   hash_update_G1(&state, &sig->D_2);

   // hash D3
   hash_update_G1(&state, &sig->D_3);

   // hash R1
   hash_update_G1(&state, &R_1);

   // hash R2
   hash_update_GT(&state, R_2);

   // hash R3
   hash_update_G1(&state, &R_3);

   hash_final(&state , hash, HASH_BYTES);

   bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, HASH_BYTES/4);
   fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM_MU_N);
   bi_copy_var_std(c, bigint_tmp_dbl, BI_WORDS);

#if DEBUG_PRINT == 1
   PRINT_BIGINT("[verify]: c ", c);
   PRINT_BIGINT("[signature: c ", sig->c);
#endif

   if (bi_compare(sig->c, c) == 0)
     ret = 1;

   return ret;
}
