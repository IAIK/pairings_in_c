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

#ifndef FP2_H_
#define FP2_H_

#include "fp/fp2_std.h"

#define fp2_add(res, a, b) 				fp2_add_std(res, a, b)
#define fp2_dbl(res, a) 				fp2_add_std(res, a, a)
#define fp2_sub(res, a, b)				fp2_sub_std(res, a, b)
#define fp2_neg(res, a)					fp2_neg_std(res, a)
#ifdef LAZY_REDUCTION
  #define fp2_mul(res, a, b)				fp2_mul_lazy(res, a, b)
#else
  #define fp2_mul(res, a, b)				fp2_mul_std(res, a, b)
#endif
#define fp2_mulfp(res, a, b)			fp2_mulfp_std(res, a, b)
#define fp2_sqr(res, a)					fp2_sqr_std(res, a)
#define fp2_inv(res, a)					fp2_inv_std(res, a)
#define fp2_hlv(res, a)					fp2_hlv_std(res, a)
#define fp2_exp(res, a, b)				fp2_exp_std(res, a, b)
#define fp2_frobenius_map(res, a, i)	fp2_frobenius_map_std(res, a, i)
#define fp2_mul_qnr(res, a)				fp2_mul_qnr_std(res, a)
#define fp2_div_qnr(res, a)				fp2_div_qnr_std(res, a)
#define fp2_sqrt(res, a)				fp2_sqrt_std(res, a)
#define fp2_legendre(a)					fp2_legendre_std(a)

#define fp2_to_montgomery(r, a)			fp2_to_montgomery_std(r, a)
#define fp2_from_montgomery(r, a)		fp2_from_montgomery_std(r, a)

#define fp2_rdc(a)						fp2_rdc_std(a)

#define fp2_clear(a)					fp2_clear_std(a)
#define fp2_copy(res, a)				fp2_copy_std(res, a)

#endif /* FP2_H_ */
