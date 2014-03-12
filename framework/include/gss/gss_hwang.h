/*
 * gss_hwang.h
 *
 *  Created on: Mar 10, 2014
 *      Author: Raphael Spreitzer
 */

#ifndef GSS_HWANG_H_
#define GSS_HWANG_H_

#include "types.h"
#include "ec/ec.h"


#define DEBUG_PRINT 1

/** Print a bigint_t variable. */
#define PRINT_BIGINT(TAG, num) \
          print(TAG); print_value(num, BI_WORDS); print("\n");

/** Print an element in \mathbb{G}_1. */
#define PRINT_G1(TAG, g1) \
          print(TAG); print("\n"); \
          print("   x: "); print_value(g1.x, FP_WORDS); print("\n"); \
          print("   y: "); print_value(g1.y, FP_WORDS); print("\n");

/** Print an element in \mathbb{G}_2. */
#define PRINT_G2(TAG, g2) \
          print(TAG); print("\n"); \
          print("   x[0]: "); print_value(g2.x[0], FP_WORDS); print("\n"); \
          print("   x[1]: "); print_value(g2.x[1], FP_WORDS); print("\n"); \
          print("   y[0]: "); print_value(g2.y[0], FP_WORDS); print("\n"); \
          print("   y[1]: "); print_value(g2.y[1], FP_WORDS); print("\n");

/** Print an element in \mathbb{G}_T. */
#define PRINT_GT(TAG, gt) \
         print(TAG); print("\n"); \
         print("   0 0 0 "); print_value(R_2[0][0][0], FP_WORDS); print("\n"); \
         print("   0 0 1 "); print_value(R_2[0][0][1], FP_WORDS); print("\n"); \
         print("   0 1 0 "); print_value(R_2[0][1][0], FP_WORDS); print("\n"); \
         print("   0 1 1 "); print_value(R_2[0][1][1], FP_WORDS); print("\n"); \
         print("   1 0 0 "); print_value(R_2[1][0][0], FP_WORDS); print("\n"); \
         print("   1 0 1 "); print_value(R_2[1][0][1], FP_WORDS); print("\n"); \
         print("   1 1 0 "); print_value(R_2[1][1][0], FP_WORDS); print("\n"); \
         print("   1 1 1 "); print_value(R_2[1][1][1], FP_WORDS); print("\n"); \
         print("   2 0 0 "); print_value(R_2[2][0][0], FP_WORDS); print("\n"); \
         print("   2 0 1 "); print_value(R_2[2][0][1], FP_WORDS); print("\n"); \
         print("   2 1 0 "); print_value(R_2[2][1][0], FP_WORDS); print("\n"); \
         print("   2 1 1 "); print_value(R_2[2][1][1], FP_WORDS); print("\n"); \


/** Private signing key. */

struct hwang_signing_key_s {
  bigint_t x, y, z;
  ecpoint_fp A;
};
typedef struct hwang_signing_key_s hwang_signing_key;
typedef struct hwang_signing_key_s *hwang_signing_key_ptr;


/** Resulting group signature. */

struct hwang_signature_s {
  bigint_t c, s_alpha, s_x, s_gamma, s_y;
  ecpoint_fp D_1, D_2, D_3;
};
typedef struct hwang_signature_s hwang_signature;
typedef struct hwang_signature_s *hwang_signature_ptr;


/** Public parameters. */

struct hwang_public_parameters_s {
  bigint_t order_p, theta;   //TODO: theta is not required on TAG
  ecpoint_fp g, u, w, d, g1, g2;
  ecpoint_fp2 h1, h_theta, U; //TODO: U is not required on TAG
};
typedef struct hwang_public_parameters_s hwang_public_parameters;
typedef struct hwang_public_parameters_s *hwang_public_parameters_ptr;

/**
 * Generates a signature according to the scheme of HWANG.
 * @param sig    [out] computed signature.
 * @param data   [in]  public data of HWANG scheme.
 * @param usk    [in]  user secret key to generate a valid signature.
 *
 * @return       1 on success; -1 on ERROR;
 */
sbyte hwang_sign(hwang_signature_ptr sig, hwang_public_parameters_ptr data, hwang_signing_key_ptr usk);

#endif /* GSS_HWANG_H_ */
