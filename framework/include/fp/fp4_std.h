/*
 * fp4_std.h
 *
 *  Created on: Apr 24, 2013
 *      Author: thomas
 */

#ifndef FP4_STD_H_
#define FP4_STD_H_

#include "types.h"

void fp4_add_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_sub_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_neg_std(fp4_t res, const fp4_t a);
void fp4_mul_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_sqr_std(fp4_t res, const fp4_t a);
void fp4_mulfp2_std(fp4_t res, const fp4_t a, const fp2_t b);
void fp4_inv_std(fp4_t res, const fp4_t a);
void fp4_exp_std(fp4_t res, const fp4_t a, const bigint_t b);
void fp4_hlv_std(fp4_t res, const fp4_t a);
void fp4_frobenius_map_std(fp4_t res, const fp4_t a, const word_t i);
void fp4_frobenius_map_precomp_std(fp4_t res, const fp4_t a, const word_t i);
void fp4_mul_adj_root_std(fp4_t res, const fp4_t a);

void fp4_to_montgomery_std(fp4_t res, const fp4_t a);
void fp4_from_montgomery_std(fp4_t res, const fp4_t a);

void fp4_rdc_std(fp4_t a);

void fp4_clear_std(fp4_t a);
void fp4_copy_std(fp4_t res, const fp4_t a);

#endif /* FP4_STD_H_ */
