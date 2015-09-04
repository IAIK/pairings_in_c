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

#ifndef FP_H_
#define FP_H_

#include "fp/fp_std.h"
#include "param.h"

/*
 * Definitions for prime field arithmetic.
 */

#ifdef REAL_LAZY_REDUCTION
 #define fp_add(res, a, b)			fp_add_lazy(res, a, b, PRIME_P, LAZYR_PRIMEC)
 #define fp_dbl(res, a)				fp_add_lazy(res, a, a, PRIME_P, LAZYR_PRIMEC)
 #define fp_sub(res, a, b)			fp_sub_lazy(res, a, b, PRIME_P, LAZYR_PRIMEC)
 #define fp_neg(res, a)				fp_neg_lazy(res, a, PRIME_P, LAZYR_PRIMEC)
 #define fp_mul_monty(res, a, b)		fp_mul_monty_twostep_lazy(res, a, b, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
 #define fp_mul_monty_var(res, a, b, mod, n0, multPrime) 	fp_mul_monty_twostep_lazy(res, a, b, mod, n0, multPrime);
#else
 #define fp_add(res, a, b)			fp_add_std(res, a, b, PRIME_P)
 #define fp_dbl(res, a)				fp_dbl_std(res, a, PRIME_P)
 #define fp_sub(res, a, b)			fp_sub_std(res, a, b, PRIME_P)
 #define fp_neg(res, a)				fp_neg_std(res, a, PRIME_P)
 #define fp_mul_monty(res, a, b)		fp_mul_monty_twostep(res, a, b, PRIME_P, MONTY_PRIME_N0[0])
 #define fp_mul_monty_var(res, a, b, mod, n0) 	fp_mul_monty_twostep(res, a, b, mod, n0);
#endif

#define fp_add_var(res, a, b, mod) 	fp_add_std(res, a, b, mod)
#define fp_dbl_var(res, a, mod) 	fp_dbl_std(res, a, mod)
#define fp_sub_var(res, a, b, mod)	fp_sub_std(res, a, b, mod)
#define fp_neg_var(res, a, mod)		fp_neg_std(res, a, mod)
#define fp_mul_barett_var(res, a, b, mod, mu)	fp_mul_std(res, a, b, mod, mu)
#define fp_sqr_barett_var(res, a, mod, mu)		fp_mul_std(res, a, a, mod, mu)
#define fp_inv_var(res, a, mod)		fp_inv_exp_var_std(res, a, mod, mu)
#define fp_inv_n(res, a)			fp_inv_exp_var_std(res, a, EC_PARAM_N, EC_PARAM_MU_N)

#ifdef NEGATIVE_PARAM_X
#define fp_inv(res, a)				fp_inv_exp_std(res, a)
#else
#define fp_inv(res, a)				fp_inv_bn(res, a)		// only works for positive parameter x yet
#endif


#define fp_hlv_var(res, a, mod)		fp_hlv_std(res, a, mod)
#define fp_hlv(res, a)				fp_hlv_std(res, a, PRIME_P)

#ifdef MONTGOMERY_ARITHMETIC

 #ifdef REAL_LAZY_REDUCTION
  #define fp_mul(res, a, b)					fp_mul_monty_twostep_lazy(res, a, b, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
  #define fp_mul_var(res, a, b, mod, n0, multPrime)		fp_mul_monty_twostep_lazy(res, a, b, mod, n0, multPrime)
  #define fp_sqr(res, a)					fp_mul_monty_twostep_lazy(res, a, a, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
  #define fp_sqr_var(res, a, mod, n0, multPrime)		fp_mul_monty_twostep_lazy(res, a, a, mod, n0, multPrime)
  #define fp_sqrt_var(res, a, mod, n0, multPrime)		fp_sqrt_lazy(res, a, mod, n0, multPrime)
  #define fp_sqrt(res, a)					fp_sqrt_lazy(res, a, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
  #define fp_legendre_var(a, mod, n0, multPrime)		fp_legendre_lazy(a, mod, n0, multPrime)
  #define fp_legendre(a)					fp_legendre_lazy(a, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
  #define fp_exp(res, a, b)					fp_exp_lazy(res, a, b, PRIME_P, MONTY_PRIME_N0[0], LAZYR_PRIMEC)
  #define fp_exp_var(res, a, b, mod, n0, multPrime)	fp_exp_lazy(res, a, b, mod, n0, multPrime)
 #else
  #define fp_mul(res, a, b)					fp_mul_monty_twostep(res, a, b, PRIME_P, MONTY_PRIME_N0[0])
  #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_twostep(res, a, b, mod, n0)
  #define fp_sqr(res, a)					fp_mul_monty_twostep(res, a, a, PRIME_P, MONTY_PRIME_N0[0])
  #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_twostep(res, a, a, mod, n0)
  #define fp_sqrt_var(res, a, mod, n0)		fp_sqrt_std(res, a, mod, n0)
  #define fp_sqrt(res, a)					fp_sqrt_std(res, a, PRIME_P, MONTY_PRIME_N0[0])
  #define fp_legendre_var(a, mod, n0)		fp_legendre_std(a, mod, n0)
  #define fp_legendre(a)					fp_legendre_std(a, PRIME_P, MONTY_PRIME_N0[0])
  #define fp_exp(res, a, b)					fp_exp_std(res, a, b, PRIME_P, MONTY_PRIME_N0[0])
  #define fp_exp_var(res, a, b, mod, n0)	fp_exp_std(res, a, b, mod, n0)
 #endif

#else

 #define fp_mul(res, a, b)				fp_mul_std(res, a, b, PRIME_P, PRIME_MU)
 #define fp_mul_var(res, a, b, mod, mu)	fp_mul_std(res, a, b, mod, mu)
 #define fp_sqr(res, a)					fp_mul_std(res, a, a, PRIME_P, PRIME_MU)
 #define fp_sqr_var(res, a, mod, mu)	fp_mul_std(res, a, a, mod, mu)
 #define fp_sqrt_var(res, a, mod, mu)	fp_sqrt_std(res, a, mod, mu)
 #define fp_sqrt(res, a)				fp_sqrt_std(res, a, PRIME_P, PRIME_MU)
 #define fp_legendre_var(a, mod, mu)	fp_legendre_std(a, mod, mu)
 #define fp_legendre(a)				fp_legendre_std(a, PRIME_P, PRIME_MU)
 #define fp_exp(res, a, b)			fp_exp_monty(res, a, b, PRIME_P, MONTY_PRIME_N0, MONTY_PRIME_R2)
 #define fp_exp_var(res, a, b, mod, mu)	fp_exp_std(res, a, b, mod, mu)

#endif

#define fp_rdc_2l_var(a, mod, mu)	fp_rdc_2l_std(a, mod, mu)
#define fp_rdc_2l(a)				fp_rdc_2l_std(a, PRIME_P, PRIME_MU)
#define fp_rdc_var(a, mod)			fp_rdc_std(a, mod)
#define fp_rdc(a)					fp_rdc_std(a, PRIME_P)
#define fp_rdc_n(a)					fp_rdc_std(a, EC_PARAM_N)
#define fp_rdc_monty(res, a, mod, n0)	fp_rdc_monty_std(res, a, mod, n0)

#define fp_clear(a)					fp_clear_std(a)
#define fp_copy(a, b)				fp_copy_std(a,b)

#define fp_to_montgomery(res, a)	fp_to_montgomery_std(res, a);
#define fp_from_montgomery(res, a)	fp_from_montgomery_std(res, a);

#if ARCHITECTURE==ARCH_CORTEXM0
#include "arch/cortexm0/fp.h"
#endif

#endif /* FP_H_ */
