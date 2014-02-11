/*
 * fp12.h
 *
 *  Created on: Apr 20, 2013
 *      Author: thomas
 */

#ifndef FP12_H_
#define FP12_H_

#include "fp/fp12_std.h"

#define fp12_add(res, a, b) 			fp12_add_std(res, a, b)
#define fp12_dbl(res, a) 				fp12_add_std(res, a, a)
#define fp12_sub(res, a, b)				fp12_sub_std(res, a, b)
#define fp12_neg(res, a)				fp12_neg_std(res, a)
//#define fp12_mul(res, a, b)				fp12_mul_std(res, a, b)
#define fp12_mul(res, a, b)				fp12_mul_distinct_b_std(res, a, b)
#ifdef TK3_MUL_OPT
 #define fp12_mul_mloop(res, a, b)		fp12_mul_tk3_std(res, a, b)
#else
 //#define fp12_mul_mloop(res, a, b)		fp12_mul_std(res, a, b)
 #define fp12_mul_mloop(res, a, b)		fp12_mul_distinct_b_std(res, a, b)
#endif
#define fp12_mul_sparse(res, a, b0, b10)	fp12_mul_sparse_std(res, a, b0, b10)
#define fp12_sqr_cyclotomic(res, a)		fp12_sqr_cyclotomic_std(res, a)
#define fp12_sqr(res, a)				fp12_sqr_std(res, a)
#define fp12_inv(res, a)				fp12_inv_std(res, a)
#define fp12_hlv(res, a)				fp12_hlv_std(res, a)
#define fp12_exp(res, a, b)				fp12_exp_montyladder_std(res, a, b)
#define fp12_exp_cyclotomic(res, a, b)	fp12_exp_cyclotomic_montyladder_std(res, a, b)
#define fp12_final_mulexp(res, a, b)	fp12_final_mulexp_std(res, a, b)

//#if BNCURVE == BN254
//#define fp12_final_exp(res, a, b)		fp12_final_exp_bn254(res, a, b)
//#else
#define fp12_final_exp(res, a, b)		fp12_final_exp_std(res, a, b)
//#endif

#define fp12_frobenius_map(res, a, i)	fp12_frobenius_map_precomp_std(res, a, i)
#define fp12_conjugate(res, a, i)		fp12_conjugate_std(res, a, i)

#define fp12_decompress(res)			fp12_decompress_std(res)

#define fp12_to_montgomery(r, a)		fp12_to_montgomery_std(r, a)
#define fp12_from_montgomery(r, a)		fp12_from_montgomery_std(r, a)

#define fp12_rdc(a)						fp12_rdc_std(a)

#define fp12_clear(a)					fp12_clear_std(a)
#define fp12_copy(a, b)					fp12_copy_std(a,b)

#endif /* FP12_H_ */
