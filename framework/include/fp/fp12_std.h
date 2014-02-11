/*
 * fp12_std.h
 *
 *  Created on: Apr 24, 2013
 *      Author: thomas
 */

#ifndef FP12_STD_H_
#define FP12_STD_H_

#include "types.h"

void fp12_add_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_sub_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_neg_std(fp12_t res, const fp12_t a);
void fp12_mul_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_mul_tk3_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_sqr_std(fp12_t res, const fp12_t a);
void fp12_sqr_cyclotomic_std(fp12_t res, const fp12_t a);
void fp12_sqr_cyclotomic_compressed(fp12_t res, const fp12_t a);
void fp12_mul_sparse_std(fp12_t res, const fp12_t a, const fp4_t b0, const fp2_t b10);
void fp12_inv_std(fp12_t res, const fp12_t a);
void fp12_exp_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_masked_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_masked_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_final_exp_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_final_mulexp_std(fp12_t res, fp12_t a, const bigint_t b);
void fp12_final_exp_bn254(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_hlv_std(fp12_t res, const fp12_t a);
void fp12_frobenius_map_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_frobenius_map_precomp_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_conjugate_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_decompress_std(fp12_t a);

void fp12_to_montgomery_std(fp12_t res, const fp12_t a);
void fp12_from_montgomery_std(fp12_t res, const fp12_t a);

void fp12_rdc_std(fp12_t a);

void fp12_clear_std(fp12_t a);
void fp12_copy_std(fp12_t res, const fp12_t a);

#endif /* FP12_STD_H_ */
