/*
 * gss_hwang.c
 *
 * Implementation of group-signature scheme by Hwang, Lee, Chung, Cho, and Nyang.
 *
 *  Created on: Mar 10, 2014
 *      Author: Raphael Spreitzer
 */

#include "types.h"
#include "rand.h"
#include "fp/fp.h"
#include "bigint/bi.h"
#include "ec/ec.h"
#include "util.h"
#include "pbc/pbc.h"
#include "fp/fp12.h"
#include "gss/gss_hwang.h"
#include "hash/sha256.h"
#include <string.h>

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
  sha256_ctx_t ctx;
  unsigned char block[64];
  unsigned char hash[SHA256_HASH_BYTES];
  unsigned char msg[1] = {0x01};

  bigint_t alpha, r_alpha, r_gamma, r_x, r_y;
  word_t bigint_tmp_dbl[2*BI_WORDS], bigint_tmp_dbl2[2*BI_WORDS];

  bigint_t gamma, bi_tmp;  //TODO: instead of bi_tmp we might use the larger bigints from above?!

  ecpoint_fp G1_tmp1, G1_tmp2, R_1, R_3;

  fp12_t R_2, GT_tmp1;

  //TODO: shall we initialize all variables to zero?
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
  PRINT_BIGINT("order: ", EC_PARAM.n);
  PRINT_BIGINT("r_alpha: ", r_alpha);
  PRINT_BIGINT("r_gamma: ", r_gamma);
  PRINT_BIGINT("r_x: ", r_x);
  PRINT_BIGINT("r_y: ", r_y);
#endif

//  bi_multiply(gamma, usk->x, alpha); //bi_subtract(gamma, gamma, usk->z); fp_rdc_n(gamma);
  bi_copy_var(bigint_tmp_dbl2, usk->z, BI_WORDS);
  bi_multiply(bigint_tmp_dbl, usk->x, alpha); //bi_subtract(bigint_tmp, bigint_tmp, usk->z); fp_rdc_n(bigint_tmp);
  bi_subtract_dbl_len(bigint_tmp_dbl, bigint_tmp_dbl, bigint_tmp_dbl2);
  fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(gamma, bigint_tmp_dbl, BI_WORDS);

  //TODO: test if gamma is negative -> then add the order (EC_PARAM.n?)
   /* if (gamma->sign == BN_NEG)
            bn_add(gamma, gamma, data->order_p);
    else
            bn_mod(gamma, gamma, data->order_p); // gamma = x * alpha - z (mod p);*/

  ecfp_mul(&sig->D_1, &data->u, alpha);    // D1 = u^{alpha}

  ecfp_mul(&sig->D_2, &data->w, alpha); ecfp_add_affine(&sig->D_2, &sig->D_2, &usk->A); // D2 = A * w^{alpha}


  ecfp_mul(&sig->D_3, &data->g, usk->y);   // D3 = g^y
  ecfp_mul(&G1_tmp1, &data->d, alpha);     // tmp = d^{alpha}
  ecfp_add_affine(&sig->D_3, &sig->D_3, &G1_tmp1);  // D3 = g^y * d^{alpha]}

  ecfp_mul(&R_1, &data->u, r_alpha); // R1 = u^{r_alpha}

#if DEBUG_PRINT == 1
  PRINT_G1("[sign] R_1: ", R_1);
#endif

  // R_2 = e(D_2^{r_x} * w^{-r_{gamma}} * g_2^{r_y}, h_1) * e(w^{-r_{alpha}}, h_{theta});
  bi_subtract(bi_tmp, data->order_p, r_gamma);

  ecfp_mul(&G1_tmp1, &sig->D_2, r_x); ecfp_mul(&G1_tmp2, &data->w, bi_tmp);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);

  ecfp_mul(&G1_tmp2, &data->g2, r_y);
  ecfp_add_affine(&G1_tmp1, &G1_tmp1, &G1_tmp2);

  pbc_map_opt_ate(R_2, &G1_tmp1, &data->h1);  // e(D_2^{r_x} * w^{-r_{gamma}} * g_2^{r_y}, h_1)

  bi_subtract(bi_tmp, data->order_p, r_alpha);
  ecfp_mul(&G1_tmp1, &data->w, bi_tmp);

  pbc_map_opt_ate(GT_tmp1, &G1_tmp1, &data->h_theta);

  //TODO: I guess the computation of R_2 can be performed easier with pbc_map_opt_ate_mul()
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

  sha256_init(&ctx);

  // hash message M
  memset(block, 0, 64); memcpy(block, msg, 1); sha256_nextBlock(&ctx, block);

  // hash D1
  // TODO: we do not hash the infinity byte - however this should not be relevant.
  sha256_update_G1(&ctx, &sig->D_1);

  // hash D2
  sha256_update_G1(&ctx, &sig->D_2);

  // hash D3
  sha256_update_G1(&ctx, &sig->D_3);

  // hash R1
  sha256_update_G1(&ctx, &R_1);

  // hash R2
  sha256_update_GT(&ctx, R_2);

  // hash R3
  sha256_update_G1(&ctx, &R_3);

  // finalize and generate bigint mod order from hash
  sha256_ctx2hash(hash, &ctx);

  bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, SHA256_HASH_BYTES);
  fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(sig->c, bigint_tmp_dbl, BI_WORDS);


  bi_multiply(bigint_tmp_dbl, sig->c, alpha); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(sig->s_alpha, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_alpha, sig->s_alpha, r_alpha); fp_rdc_n(sig->s_alpha); // s_alpha = c * alpha + r_alpha
  // bn_mul(sig->s_alpha, sig->c, alpha); bn_mod(sig->s_alpha, sig->s_alpha, data->order_p);
  // bn_add(sig->s_alpha, sig->s_alpha, r_alpha); bn_mod(sig->s_alpha, sig->s_alpha, data->order_p);// s_alpha = c * alpha + r_alpha


  bi_multiply(bigint_tmp_dbl, sig->c, usk->x); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(sig->s_x, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_x, sig->s_x, r_x); fp_rdc_n(sig->s_x); // s_x = c * x + r_x
  // bn_mul(sig->s_x, sig->c, usk->x); bn_mod(sig->s_x, sig->s_x, data->order_p);
  // bn_add(sig->s_x, sig->s_x, r_x);  bn_mod(sig->s_x, sig->s_x, data->order_p);   // s_x = c * x + r_x

  bi_multiply(bigint_tmp_dbl, sig->c, gamma); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(sig->s_gamma, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_gamma, sig->s_gamma, r_gamma); fp_rdc_n(sig->s_gamma); // s_gamma = c * gamma + r_gamma
   // bn_mul(sig->s_gamma, sig->c, gamma); bn_mod(sig->s_gamma, sig->s_gamma, data->order_p);
   // bn_add(sig->s_gamma, sig->s_gamma, r_gamma); bn_mod(sig->s_gamma, sig->s_gamma, data->order_p);    // s_gamma = c * gamma + r_gamma

  bi_multiply(bigint_tmp_dbl, sig->c, usk->y); fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
  bi_copy_var_std(sig->s_y, bigint_tmp_dbl, BI_WORDS);
  bi_add(sig->s_y, sig->s_y, r_y); fp_rdc_n(sig->s_y); // s_y = c * y + r_y
  // bn_mul(sig->s_y, sig->c, usk->y); bn_mod(sig->s_y, sig->s_y, data->order_p);
  // bn_add(sig->s_y, sig->s_y, r_y);  bn_mod(sig->s_y, sig->s_y, data->order_p); // s_y = c * y + r_y



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


