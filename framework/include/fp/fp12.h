/****************************************************************************
**
** Copyright (C) 2015 Stiftung Secure Information and
**                    Communication Technologies SIC and
**                    Graz University of Technology
** Contact: http://opensource.iaik.tugraz.at
**
**
** Commercial License Usage
** Licensees holding valid commercial licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and SIC. For further information
** contact us at http://opensource.iaik.tugraz.at.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** This software is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this software. If not, see http://www.gnu.org/licenses/.
**
**
****************************************************************************/

#ifndef FP12_H_
#define FP12_H_

#include "fp/fp12_std.h"

#define fp12_add(res, a, b) 			fp12_add_std(res, a, b)
#define fp12_dbl(res, a) 				fp12_add_std(res, a, a)
#define fp12_sub(res, a, b)				fp12_sub_std(res, a, b)
#define fp12_neg(res, a)				fp12_neg_std(res, a)
#define fp12_mul(res, a, b)				fp12_mul_distinct_b_std(res, a, b)
#ifdef TK3_MUL_OPT
 #define fp12_mul_mloop(res, a, b)		fp12_mul_tk3_std(res, a, b)
#else
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

#define fp12_final_exp(res, a, b)		fp12_final_exp_std(res, a, b)

#define fp12_frobenius_map(res, a, i)	fp12_frobenius_map_precomp_std(res, a, i)
#define fp12_conjugate(res, a, i)		fp12_conjugate_std(res, a, i)

#define fp12_decompress(res)			fp12_decompress_std(res)

#define fp12_to_montgomery(r, a)		fp12_to_montgomery_std(r, a)
#define fp12_from_montgomery(r, a)		fp12_from_montgomery_std(r, a)

#define fp12_rdc(a)						fp12_rdc_std(a)

#define fp12_clear(a)					fp12_clear_std(a)
#define fp12_copy(a, b)					fp12_copy_std(a,b)

#endif /* FP12_H_ */
