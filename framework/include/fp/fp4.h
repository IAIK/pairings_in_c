/*
 * fp4.h
 *
 *  Created on: Apr 20, 2013
 *      Author: thomas
 */

#ifndef FP4_H_
#define FP4_H_

#include "fp/fp4_std.h"

#define fp4_add(res, a, b) 				fp4_add_std(res, a, b)
#define fp4_dbl(res, a) 				fp4_add_std(res, a, a)
#define fp4_sub(res, a, b)				fp4_sub_std(res, a, b)
#define fp4_neg(res, a)					fp4_neg_std(res, a)
#define fp4_mul(res, a, b)				fp4_mul_std(res, a, b)
#define fp4_mulfp2(res, a, b)			fp4_mulfp2_std(res, a, b)
#define fp4_sqr(res, a)					fp4_sqr_std(res, a)
#define fp4_inv(res, a)					fp4_inv_std(res, a)
#define fp4_hlv(res, a)					fp4_hlv_std(res, a)
#define fp4_exp(res, a, b)				fp4_exp_std(res, a, b)
#define fp4_frobenius_map(res, a, i)	fp4_frobenius_map_precomp_std(res, a, i)
#define fp4_mul_adj_root(res, a)		fp4_mul_adj_root_std(res, a)

#define fp4_to_montgomery(r, a)			fp4_to_montgomery_std(r, a)
#define fp4_from_montgomery(r, a)		fp4_from_montgomery_std(r, a)

#define fp4_rdc(a)						fp4_rdc_std(a)

#define fp4_clear(a)					fp4_clear_std(a)
#define fp4_copy(res, a)				fp4_copy_std(res,a)

#endif /* FP4_H_ */
