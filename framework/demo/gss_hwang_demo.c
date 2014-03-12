/*
 * gss_demo.c
 *
 *  Created on: Mar 10, 2014
 *      Author: Raphael Spreitzer
 */


#include "pbc/pbc.h"
#include "bigint/bi.h"
#include "types.h"
#include "gss/gss_hwang.h"
#include "hash/sha256.h"
#include <string.h>

/**
 * Initializes the public parameters, the master issuing key (MIK),
 * the master opening key (MOK), and the master linking key (MLK).
 *
 * TODO: currently we only use one struct (we should add different
 * ones for MIK, MOK, and MLK.)
 */
void hwang_init_parameters(hwang_public_parameters_ptr data)
{
  bigint_t eta, xi, bi_tmp;

  // We need the order (p) of the groups G1 and G2 to compute in Z_p
  bi_copy_var_std(data->order_p, EC_PARAM.n, BI_WORDS);

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


  ecfp_mul(&data->w, &data->u, eta); // w = u^{eta}

  ecfp_mul(&data->d, &data->u, xi); // d = u^{xi}

  ecfp2_mul(&data->U, &data->h1, xi); // U = h1^{xi}

  ecfp2_mul(&data->h_theta, &data->h1, data->theta); // h_{theta} = h1^{theta}

#if DEBUG_PRINT == 1
  print("\n\n// -------------- Parameters/GPK --------------\n");
  PRINT_G1("GPK_g", data->g);
  PRINT_G1("GPK_h1", data->h1);
  PRINT_G1("GPK_h_theta", data->h_theta);
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
  bigint_t bi_tmp, bi_tmp1, inv, bi_tmp3;
  word_t bi_tmp_mul[2*BI_WORDS];
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
  bi_subtract(bi_tmp, data->order_p, usk->y);  // negate y
  bi_subtract(bi_tmp1, data->order_p, usk->z); // negate z
  ecfp_mul(&usk->A, &data->g2, bi_tmp);  // A = g2^{-y}
  ecfp_mul(&G1_tmp, &data->w, bi_tmp1);  //   = w^{-z}
  ecfp_add_affine(&usk->A, &usk->A, &G1_tmp);
  ecfp_add_affine(&usk->A, &usk->A, &data->g1);
  //bn_sub(bn_tmp, data->order_p, usk->y);   // negate y
  //bn_sub(bn_tmp1, data->order_p, usk->z);  // negate z
  //g1_mul_sim(usk->A, data->g2, bn_tmp, data->w, bn_tmp1);
  //g1_add(usk->A, usk->A, data->g1);

  bi_add(bi_tmp, data->theta, usk->x); fp_rdc_n(bi_tmp);

  //fp_t fp_tmp;
  //fp_to_montgomery_std(fp_tmp, bi_tmp);

  fp_inv_n(inv, bi_tmp);
  //fp_inv_var(inv, fp_tmp, data->order_p);

  //bigint_t inv2;
  //fp_from_montgomery(inv2, inv);
  //fp_inv_var(inv, bi_tmp, data->order_p);
  //fp_inv(inv, bi_tmp);

  //bn_gcd_ext(bn_tmp1, inv, bn_tmp3, bn_tmp, data->order_p);  // invert bn_tmp (mod order p)
  // TODO: test if inv is negative and add order if necessary!!!
  //if (bn_sign(inv) == BN_NEG) {
  //  bn_add(inv, inv, data->order_p);
  //}

//#if DEBUG_PRINT == 1
//  PRINT_BIGINT("\inv  : ", inv);
//#endif

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
  sha256_ctx_t ctx;
  unsigned char block[64];
  unsigned char hash[SHA256_HASH_BYTES];
  unsigned char msg[1] = {0x01};

  sbyte ret = -1;
  ecpoint_fp R_1, R_3, g1_tmp1, g1_tmp2;

  fp12_t R_2, gt_tmp1, gt_tmp2, gt_tmp3, gt_tmp4;

  bigint_t bi_tmp, c;
  word_t bigint_tmp_dbl[2*BI_WORDS];

  // BEGIN: Check signature

  ecfp_mul(&R_1, &data->u, sig->s_alpha); // R_1 = u^{s_{alpha}}
  //g1_mul(R_1, data->u, sig->s_alpha);    // R_1 = u^{s_{alpha}}

  bi_subtract(bi_tmp, data->order_p, sig->c); // negate c (mod order p);
  //bn_sub(bn_tmp, data->order_p, sig->c); // negate c (mod order p)

  ecfp_mul(&g1_tmp1, &sig->D_1, bi_tmp);
  ecfp_add_affine(&R_1, &R_1, &g1_tmp1);   // R_1 = u^{s_{alpha}} * D_1^{-c}
  //g1_mul(g1_tmp, sig->D_1, bn_tmp);
  //g1_add(R_1, R_1, g1_tmp);              // R_1 = u^{s_{alpha}} * D_1^{-c}

#if DEBUG_PRINT == 1
  PRINT_G1("[verify] R_1: ", R_1);
#endif

  // TODO: this was rewritten to support sim pairing and multiplication of results.
  ecfp_mul(&g1_tmp1, &sig->D_2, sig->s_x);
  bi_subtract(bi_tmp, data->order_p, sig->s_alpha); // negate s_alpha (mod order p)
  ecfp_mul(&g1_tmp2, &data->w, bi_tmp);
  pbc_map_opt_ate_mul(gt_tmp1, &g1_tmp1, &data->h1, &g1_tmp2, & data->h_theta); // R_2 = e(D_2, h_1)^{s_x} * e(w, h_theta)^{-s_{alpha}}
  //pc_map(R_2, sig->D_2, data->h1);
  //gt_exp(R_2, R_2, sig->s_x);                   // R_2 = e(D_2, h_1)^{s_x}
  //bn_sub(bn_tmp, data->order_p, sig->s_alpha);  // negate s_alpha (mod order p)
  //pc_map(gt_tmp, data->w, data->h_theta);
  //gt_exp(gt_tmp, gt_tmp, bn_tmp);
  //gt_mul(R_2, R_2, gt_tmp);                     // R_2 *= e(w, h_theta)^{-s_{alpha}}


  // TODO: this was rewritten to support sim pairing and multiplication of results.
  // TODO: there is one pairing that might be collapsed here (including h1).
  bi_subtract(bi_tmp, data->order_p, sig->s_gamma); // negate s_gamma (mod order p)
  ecfp_mul(&g1_tmp1, &data->w, bi_tmp);
  ecfp_mul(&g1_tmp2, &data->g2, sig->s_y);
  pbc_map_opt_ate_mul(gt_tmp2, &g1_tmp1, &data->h1, &g1_tmp2, &data->h1);
  fp12_mul_std(gt_tmp3, gt_tmp1, gt_tmp2);

  //bn_sub(bn_tmp, data->order_p, sig->s_gamma);  // negate s_gamma (mod order p)
  //pc_map(gt_tmp, data->w, data->h1);
  //gt_exp(gt_tmp, gt_tmp, bn_tmp);
  //gt_mul(R_2, R_2, gt_tmp);                     // R_2 *= e(w, h_1)^{-s{gamma}}
  //pc_map(gt_tmp, data->g2, data->h1);
  //gt_exp(gt_tmp, gt_tmp, sig->s_y);
  //gt_mul(R_2, R_2, gt_tmp);                     // R_2 *= e(g_2, h_1)^{s_y}


  pbc_map_opt_ate_div(gt_tmp1, &sig->D_2, &data->h_theta, &data->g1, &data->h1);
  fp12_exp_std(gt_tmp2, gt_tmp1, sig->c);
  fp12_mul_std(R_2, gt_tmp3, gt_tmp2);
  //pc_map(gt_tmp2, sig->D_2, data->h_theta);
  //pc_map(gt_tmp3, data->g1, data->h1);
  //gt_inv(gt_tmp4, gt_tmp3);
  //gt_mul(gt_tmp, gt_tmp2, gt_tmp4);
  //gt_exp(gt_tmp, gt_tmp, sig->c);
  //gt_mul(R_2, R_2, gt_tmp);                     // R_2 *= (e(D_2, h_theta) / e(g_1, h_1))^c

#if DEBUG_PRINT == 1
  PRINT_GT("[verify] R_2:", R_2);
#endif

  ecfp_mul(&R_3, &data->g, sig->s_y);
  ecfp_mul(&g1_tmp1, &data->d, sig->s_alpha);
  ecfp_add_affine(&R_3, &R_3, &g1_tmp1);
  bi_subtract(bi_tmp, data->order_p, sig->c);
  ecfp_mul(&g1_tmp1, &sig->D_3, bi_tmp);
  ecfp_add_affine(&R_3, &R_3, &g1_tmp1);

/*
  g1_mul_sim(R_3, data->g, sig->s_y, data->d, sig->s_alpha);
  g1_norm(R_3, R_3);
  bn_sub(bn_tmp, data->order_p, sig->c);
  g1_mul(g1_tmp, sig->D_3, bn_tmp);
  g1_norm(g1_tmp, g1_tmp);
  g1_add(R_3, R_3, g1_tmp);
  g1_norm(R_3, R_3);
  util_printf("[verify] R_3:\n"); g1_print(R_3);
*/

#if DEBUG_PRINT == 1
  PRINT_G1("[verify] R_3:", R_3);
#endif

   sha256_init(&ctx);

   // hash message M
   memset(block, 0, 64); memcpy(block, msg, 1); sha256_nextBlock(&ctx, block);

   // hash D1
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

   sha256_ctx2hash(hash, &ctx);

   bi_clear_var_std(bigint_tmp_dbl, 2*BI_WORDS); bi_copy_var_std(bigint_tmp_dbl, (const word_t *) hash, SHA256_HASH_BYTES);
   fp_rdc_2l_var(bigint_tmp_dbl, data->order_p, EC_PARAM.mu_n);
   bi_copy_var_std(c, bigint_tmp_dbl, BI_WORDS);

#if DEBUG_PRINT == 1
   PRINT_BIGINT("[verify]: c ", c);
   PRINT_BIGINT("[signature: c ", sig->c);
#endif

   if (bi_compare(sig->c, c) == 0)
     ret = 1;

   return ret;
}

int main(void) {
  hwang_signing_key sk;
  hwang_public_parameters parameters;
  hwang_signature sig;

  hwang_init_parameters(&parameters);

  hwang_generate_usk(&sk, &parameters);

  hwang_sign(&sig, &parameters, &sk);

  if (hwang_verify(&parameters, &sig) != 1)
    print("Signature is invalid!");
  else
    print("Signature is VALID!\n");

}
