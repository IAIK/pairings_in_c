/*
 * ecfp2_std.h
 *
 *  Created on: Apr 24, 2013
 *      Author: thomas
 */

#ifndef ECFP2_STD_H_
#define ECFP2_STD_H_

#include "types.h"

void ecfp2_add_affine_std(ecfp2_pt res, const ecfp2_pt a, const ecfp2_pt b);
void ecfp2_add_affine_direct_std(ecfp2_pt res, const ecfp2_pt a, const ecfp2_pt b);
void ecfp2_add_proj_std(ecfp2_proj_pt res, const ecfp2_proj_pt a, const ecfp2_pt b);
void ecfp2_dbl_affine_std(ecfp2_pt res, const ecfp2_pt a);
void ecfp2_dbl_affine_direct_std(ecfp2_pt res, const ecfp2_pt a);
void ecfp2_dbl_proj_std(ecfp2_proj_pt res, const ecfp2_proj_pt a);
void ecfp2_neg_affine_std(ecfp2_pt a);
void ecfp2_neg_proj_std(ecfp2_proj_pt a);
void ecfp2_mul_l2rb_std(ecfp2_pt res, const ecfp2_pt a, const fp_t k);
void ecfp2_mul_montyladder_std(ecfp2_pt res, const ecfp2_pt a, const fp_t k);


void ecfp2_get_affine_from_jacobian_std(ecfp2_pt affine, const ecfp2_proj_pt projective);

void ecfp2_rand_std(ecfp2_pt res);

void ecfp2_get_affine_std(ecfp2_pt affine, const ecfp2_proj_pt projective);

void ecfp2_get_projective_std(ecfp2_proj_pt projective, const ecfp2_pt affine);
void ecfp2_get_homogeneous_projective_rnd_std(ecfp2_proj_pt projective, const ecfp2_pt affine);
void ecfp2_get_jacobian_projective_rnd_std(ecfp2_proj_pt projective, const ecfp2_pt affine);

void ecfp2_frobenius_map_std(ecfp2_pt res, const ecfp2_pt a, const word_t i);
void ecfp2_frobenius_map_precomp_std(ecfp2_pt res, const ecfp2_pt a, const word_t i);

void ecfp2_hash_to_point_std(ecfp2_pt res, const bigint_t t);

void ecfp2_copy_std(ecfp2_pt res, const ecfp2_pt a);
void ecfp2_clear_std(ecfp2_pt a);

void ecfp2_to_montgomery_std(ecfp2_pt res, const ecfp2_pt a);
void ecfp2_from_montgomery_std(ecfp2_pt res, const ecfp2_pt a);

#endif /* ECFP2_STD_H_ */
