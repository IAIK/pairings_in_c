/*
 * ec_fp_std.h
 *
 *  Created on: Apr 22, 2013
 *      Author: thomas
 */

#ifndef ECFP_STD_H_
#define ECFP_STD_H_

#include "fp/fp.h"

void ecfp_add_affine_std(ecfp_pt res, const ecfp_pt a, const ecfp_pt b);
void ecfp_add_affine_direct_std(ecfp_pt res, const ecfp_pt a, const ecfp_pt b);
void ecfp_add_proj_std(ecfp_proj_pt res, const ecfp_proj_pt a, const ecfp_pt b);
void ecfp_dbl_affine_std(ecfp_pt res, const ecfp_pt a);
void ecfp_dbl_affine_direct_std(ecfp_pt res, const ecfp_pt a);
void ecfp_dbl_proj_std(ecfp_proj_pt res, const ecfp_proj_pt a);
void ecfp_neg_affine_std(ecfp_pt a);
void ecfp_neg_proj_std(ecfp_proj_pt a);
void ecfp_mul_l2rb_std(ecfp_pt res, const ecfp_pt a, const fp_t k);
void ecfp_mul_montyladder_std(ecfp_pt res, const ecfp_pt a, const fp_t k);
void ecfp_mul_naf_std(ecfp_pt res, const ecfp_pt a, const fp_t k);
void ecfp_mul_glv_std(ecfp_pt res, const ecfp_pt a, const fp_t k);
void ecfp_mul_glv_dec_k_std(bigint_t k1, bigint_t k2, bigint_t k);

void ecfp_get_affine_std(ecfp_pt affine, const ecfp_proj_pt projective);
void ecfp_get_projective_std(ecfp_proj_pt projective, const ecfp_pt affine);

void ecfp_hash_to_point_std(ecfp_pt res, const bigint_t t);

void ecfp_copy_std(ecfp_pt res, const ecfp_pt a);

void ecfp_to_montgomery_std(ecfp_pt res, const ecfp_pt a);
void ecfp_from_montgomery_std(ecfp_pt res, const ecfp_pt a);

#endif /* ECFP_STD_H_ */
