/*
 * fp2_std.h
 *
 *  Created on: Apr 20, 2013
 *      Author: thomas
 */

#ifndef FP2_STD_H_
#define FP2_STD_H_

#include "types.h"

void fp2_add_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_sub_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_neg_std(fp2_t res, const fp2_t a);
void fp2_mul_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_mul_lazy(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_mulfp_std(fp2_t res, const fp2_t a, const fp_t b);
void fp2_sqr_std(fp2_t res, const fp2_t a);
void fp2_inv_std(fp2_t res, const fp2_t a);
void fp2_exp_std(fp2_t res, const fp2_t a, const bigint_t b);
void fp2_hlv_std(fp2_t res, const fp2_t a);
void fp2_frobenius_map_std(fp2_t res, const fp2_t a, const word_t i);
void fp2_mul_qnr_std(fp2_t res, const fp2_t a);
void fp2_div_qnr_std(fp2_t res, const fp2_t a);
void fp2_sqrt_std(fp2_t res, const fp2_t a);
int  fp2_legendre_std(const fp2_t a);

void fp2_to_montgomery_std(fp2_t res, const fp2_t a);
void fp2_from_montgomery_std(fp2_t res, const fp2_t a);

void fp2_rdc_std(fp2_t a);

void fp2_clear_std(fp2_t a);
void fp2_copy_std(fp2_t res, const fp2_t a);

#endif /* FP2_STD_H_ */
