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

#ifndef FP_CORTEXM0_H_
#define FP_CORTEXM0_H_

#include "config.h"
#include "bigint/bi.h"

#if (BNCURVE == BN256 || BNCURVE == BN254)
#ifdef ASM_OPTIMIZATION

void fp_add_cm0_256(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo);
void fp_subtract_cm0_256(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo);
void fp_mul_monty_cm0_256(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res);
void fp_mul_monty_cm0_bn254(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res);
void fp_mul_monty_mulacc_cm0_256(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res);
void fp_square_monty_mulacc_cm0_256(fp_t res, const fp_t a, const bigint_t modulo, word_t n0);
void fp_hlv_cm0_256(fp_t res, const fp_t a, const bigint_t modulo);
void fp_rdc_monty_cm0_256(fp_t res, const word_t* t, const bigint_t modulo, word_t n0);
void fp_rdc_monty_cm0_mulacc_256(fp_t res, const word_t* t, const bigint_t modulo, word_t n0);
void fp_rdc_monty_cm0_bn254(fp_t res, const word_t* t, const bigint_t modulo, word_t n0);

void fp_add_lazy_cm0_bn254(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const bigint_t multMod);
void fp_subtract_lazy_cm0_bn254(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const bigint_t multMod);
void fp_neg_lazy_cm0_bn254(fp_t res, const fp_t a, const bigint_t modulo, const bigint_t multMod);
void fp_mul_monty_lazy_cm0_bn254(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res, const bigint_t multMod);

void fp_rdc_cm0_256(fp_t a, const bigint_t modulo);
void fp_rdc_cm0_bn254(fp_t a, const bigint_t modulo);

/** The following two save code and branches as those are identical. */
#ifdef fp_clear
#undef fp_clear
#endif

#define fp_clear(res) bi_clear_cm0_256(res)

#ifdef fp_copy
#undef fp_copy
#endif

#define fp_copy(res, a) bi_copy_cm0_256(res, a)

#ifdef fp_add
#undef fp_add
#endif

#ifdef fp_add_var
#undef fp_add_var
#endif

#if defined(REAL_LAZY_REDUCTION) && (BNCURVE == BN254)

#define fp_add(res, a, b)						fp_add_lazy_cm0_bn254(res, a, b, PRIME_P, LAZYR_PRIMEC)
#define fp_add_var(res, a, b, mod, multMod)		fp_add_lazy_cm0_bn254(res, a, b, mod, multMod)

#else

#define fp_add(res, a, b)				fp_add_cm0_256(res, a, b, PRIME_P)
#define fp_add_var(res, a, b, mod)		fp_add_cm0_256(res, a, b, mod)

#endif

#ifdef fp_dbl
#undef fp_dbl
#endif

#ifdef fp_dbl_var
#undef fp_dbl_var
#endif

#if defined(REAL_LAZY_REDUCTION) && (BNCURVE == BN254)

#define fp_dbl(res, a)						fp_add_lazy_cm0_bn254(res, a, a, PRIME_P, LAZYR_PRIMEC)
#define fp_dbl_var(res, a, mod, multMod)	fp_add_lazy_cm0_bn254(res, a, a, mod, multMod)

#else

#define fp_dbl(res, a)					fp_add_cm0_256(res, a, a, PRIME_P)
#define fp_dbl_var(res, a, mod)			fp_add_cm0_256(res, a, a, mod)

#endif


#ifdef fp_sub
#undef fp_sub
#endif

#ifdef fp_sub_var
#undef fp_sub_var
#endif

#if defined(REAL_LAZY_REDUCTION) && (BNCURVE == BN254)

#define fp_sub(res, a, b)						fp_subtract_lazy_cm0_bn254(res, a, b, PRIME_P, LAZYR_PRIMEC)
#define fp_sub_var(res, a, b, mod, multMod)		fp_subtract_lazy_cm0_bn254(res, a, b, mod, multMod)

#else

#define fp_sub(res, a, b)				fp_subtract_cm0_256(res, a, b, PRIME_P)
#define fp_sub_var(res, a, b, mod)		fp_subtract_cm0_256(res, a, b, mod)

#endif

#ifdef fp_hlv
#undef fp_hlv
#endif

#ifdef fp_hlv_var
#undef fp_hlv_var
#endif

#define fp_hlv_var(res, a, mod)			fp_hlv_cm0_256(res, a, mod)
#define fp_hlv(res, a)					fp_hlv_cm0_256(res, a, PRIME_P)

#ifdef fp_neg
#undef fp_neg
#endif

#ifdef fp_neg_var
#undef fp_neg_var
#endif

#if defined(REAL_LAZY_REDUCTION) && (BNCURVE == BN254)

#define fp_neg_var(res, a, mod, multMod)	fp_neg_lazy_cm0_bn254(res, a, mod, multMod)
#define fp_neg(res, a)						fp_neg_lazy_cm0_bn254(res, a, PRIME_P, LAZYR_PRIMEC)

#else

#define fp_neg_var(res, a, mod)		fp_neg_cm0_256(res, a, mod)
#define fp_neg(res, a)				fp_neg_cm0_256(res, a, PRIME_P)

#endif

#ifdef fp_rdc
#undef fp_rdc
#endif

#ifdef fp_rdc_n
#undef fp_rdc_n
#endif

#if (BNCURVE == BN256)
  #define fp_rdc(a)					fp_rdc_cm0_256(a, PRIME_P)
  #define fp_rdc_n(a)				fp_rdc_cm0_256(a, EC_PARAM_N)
#elif (BNCURVE == BN254)
  #define fp_rdc(a)					fp_rdc_cm0_bn254(a, PRIME_P)
  #define fp_rdc_n(a)				fp_rdc_cm0_bn254(a, EC_PARAM_N)
#endif

#ifndef LAZY_REDUCTION

#ifdef fp_mul_monty
#undef fp_mul_monty
#endif

#ifdef fp_mul_monty_var
#undef fp_mul_monty_var
#endif

#ifdef ASM_MULACC_EXTENSION
 #define fp_mul_monty(res, a, b)				fp_mul_monty_mulacc_cm0_256(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
 #define fp_mul_monty_var(res, a, b, mod, n0) 	fp_mul_monty_mulacc_cm0_256(n0, a, b, mod, res)
#else
 #if (BNCURVE == BN256)
  #define fp_mul_monty(res, a, b)				fp_mul_monty_cm0_256(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
  #define fp_mul_monty_var(res, a, b, mod, n0) 	fp_mul_monty_cm0_256(n0, a, b, mod, res)
 #elif (BNCURVE == BN254)
  #ifdef REAL_LAZY_REDUCTION
   #define fp_mul_monty(res, a, b)							fp_mul_monty_lazy_cm0_bn254(MONTY_PRIME_N0[0], a, b, PRIME_P, res, LAZYR_PRIMEC)
   #define fp_mul_monty_var(res, a, b, mod, n0, multMod)	fp_mul_monty_lazy_cm0_bn254(n0, a, b, mod, res, multMod)
  #else
   #define fp_mul_monty(res, a, b)				fp_mul_monty_cm0_bn254(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
   #define fp_mul_monty_var(res, a, b, mod, n0)	fp_mul_monty_cm0_bn254(n0, a, b, mod, res)
  #endif
 #endif
#endif

#endif

#ifdef fp_rdc_monty
#undef fp_rdc_monty
#endif


#ifdef ASM_MULACC_EXTENSION
  #define fp_rdc_monty(res, t, mod, n0)	fp_rdc_monty_cm0_mulacc_256(res, t, mod, n0)
#else
 #if (BNCURVE == BN256)
  #define fp_rdc_monty(res, t, mod, n0)	fp_rdc_monty_cm0_256(res, t, mod, n0)
 #elif (BNCURVE == BN254)
  #define fp_rdc_monty(res, t, mod, n0)	fp_rdc_monty_cm0_bn254(res, t, mod, n0)
 #endif
#endif

#ifndef LAZY_REDUCTION

#ifdef MONTGOMERY_ARITHMETIC

 #ifdef fp_mul
 #undef fp_mul
 #endif
 #ifdef fp_mul_var
 #undef fp_mul_var
 #endif
 #ifdef fp_sqr
 #undef fp_sqr
 #endif
 #ifdef fp_sqr_var
 #undef fp_sqr_var
 #endif

 #ifdef ASM_MULACC_EXTENSION
  #define fp_mul(res, a, b) 				fp_mul_monty_mulacc_cm0_256(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
  #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_mulacc_cm0_256(n0, a, b, mod, res)

  #ifdef DEDICATED_SQUARING
   #define fp_sqr(res, a)					fp_square_monty_mulacc_cm0_256(res, a, PRIME_P, MONTY_PRIME_N0[0])
   #define fp_sqr_var(res, a, mod, n0)		fp_square_monty_mulacc_cm0_256(res, a, mod, n0)
  #else
   #define fp_sqr(res, a)					fp_mul_monty_mulacc_cm0_256(MONTY_PRIME_N0[0], a, a, PRIME_P, res)
   #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_mulacc_cm0_256(n0, a, a, mod, res)
  #endif
 #else
  #if (BNCURVE == BN256)
   #define fp_mul(res, a, b) 				fp_mul_monty_cm0_256(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
   #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_cm0_256(n0, a, b, mod, res)

   #define fp_sqr(res, a)					fp_mul_monty_cm0_256(MONTY_PRIME_N0[0], a, a, PRIME_P, res)
   #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_cm0_256(n0, a, a, mod, res)
  #elif (BNCURVE == BN254)
   #ifdef REAL_LAZY_REDUCTION
    #define fp_mul(res, a, b) 				fp_mul_monty_lazy_cm0_bn254(MONTY_PRIME_N0[0], a, b, PRIME_P, res, LAZYR_PRIMEC)
    #define fp_mul_var(res, a, b, mod, n0, multMod)	fp_mul_monty_lazy_cm0_bn254(n0, a, b, mod, res, multMod)

    #define fp_sqr(res, a)					fp_mul_monty_lazy_cm0_bn254(MONTY_PRIME_N0[0], a, a, PRIME_P, res, LAZYR_PRIMEC)
    #define fp_sqr_var(res, a, mod, n0, multMod)	fp_mul_monty_lazy_cm0_bn254(n0, a, a, mod, res, multMod)
   #else
    #define fp_mul(res, a, b) 				fp_mul_monty_cm0_bn254(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
    #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_cm0_bn254(n0, a, b, mod, res)

    #define fp_sqr(res, a)					fp_mul_monty_cm0_bn254(MONTY_PRIME_N0[0], a, a, PRIME_P, res)
    #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_cm0_bn254(n0, a, a, mod, res)
   #endif
  #endif
 #endif
#endif

#endif

#endif
#elif (BNCURVE == BN158)
#ifdef ASM_OPTIMIZATION

void fp_add_cm0_160(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo);
void fp_subtract_cm0_160(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo);
void fp_mul_monty_cm0_160(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res);
void fp_mul_monty_mulacc_cm0_160(const word_t n0, const fp_t a, const fp_t b, const bigint_t modulo, fp_t res);
void fp_square_monty_mulacc_cm0_160(fp_t res, const fp_t a, const bigint_t modulo, word_t n0);
void fp_hlv_cm0_160(fp_t res, const fp_t a, const bigint_t modulo);
void fp_rdc_monty_cm0_160(fp_t res, const word_t* t, const bigint_t modulo, word_t n0);
void fp_rdc_monty_cm0_mulacc_160(fp_t res, const word_t* t, const bigint_t modulo, word_t n0);

void fp_rdc_cm0_bn158(fp_t a, const bigint_t modulo);

/** The following two save code and branches as those are identical. */
#ifdef fp_clear
#undef fp_clear
#endif

#define fp_clear(res) bi_clear_cm0_160(res)

#ifdef fp_copy
#undef fp_copy
#endif

#define fp_copy(res, a) bi_copy_cm0_160(res, a)

#ifdef fp_add
#undef fp_add
#endif

#ifdef fp_add_var
#undef fp_add_var
#endif

#define fp_add(res, a, b)				fp_add_cm0_160(res, a, b, PRIME_P)
#define fp_add_var(res, a, b, mod)		fp_add_cm0_160(res, a, b, mod)

#ifdef fp_dbl
#undef fp_dbl
#endif

#ifdef fp_dbl_var
#undef fp_dbl_var
#endif

#define fp_dbl(res, a)					fp_add_cm0_160(res, a, a, PRIME_P)
#define fp_dbl_var(res, a, mod)			fp_add_cm0_160(res, a, a, mod)

#ifdef fp_sub
#undef fp_sub
#endif

#ifdef fp_sub_var
#undef fp_sub_var
#endif

#define fp_sub(res, a, b)				fp_subtract_cm0_160(res, a, b, PRIME_P)
#define fp_sub_var(res, a, b, mod)		fp_subtract_cm0_160(res, a, b, mod)

#ifdef fp_hlv
#undef fp_hlv
#endif

#ifdef fp_hlv_var
#undef fp_hlv_var
#endif

#define fp_hlv_var(res, a, mod)			fp_hlv_cm0_160(res, a, mod)
#define fp_hlv(res, a)					fp_hlv_cm0_160(res, a, PRIME_P)

#ifdef fp_neg
#undef fp_neg
#endif

#ifdef fp_neg_var
#undef fp_neg_var
#endif

#define fp_neg_var(res, a, mod)		fp_neg_cm0_160(res, a, mod)
#define fp_neg(res, a)				fp_neg_cm0_160(res, a, PRIME_P)



#if (BNCURVE == BN158)
  #ifdef fp_rdc
  #undef fp_rdc
  #endif

  #ifdef fp_rdc_n
  #undef fp_rdc_n
  #endif

  #define fp_rdc(a)					fp_rdc_cm0_bn158(a, PRIME_P)
  #define fp_rdc_n(a)				fp_rdc_cm0_bn158(a, EC_PARAM_N)
#endif

#ifndef LAZY_REDUCTION

#ifdef fp_mul_monty
#undef fp_mul_monty
#endif

#ifdef fp_mul_monty_var
#undef fp_mul_monty_var
#endif

#ifdef ASM_MULACC_EXTENSION
 #define fp_mul_monty(res, a, b)				fp_mul_monty_mulacc_cm0_160(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
 #define fp_mul_monty_var(res, a, b, mod, n0) 	fp_mul_monty_mulacc_cm0_160(n0, a, b, mod, res)
#else
 #define fp_mul_monty(res, a, b)				fp_mul_monty_cm0_160(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
 #define fp_mul_monty_var(res, a, b, mod, n0) 	fp_mul_monty_cm0_160(n0, a, b, mod, res)
#endif

#endif

#ifdef fp_rdc_monty
#undef fp_rdc_monty
#endif

#ifdef ASM_MULACC_EXTENSION
  #define fp_rdc_monty(res, t, mod, n0)	fp_rdc_monty_cm0_mulacc_160(res, t, mod, n0)
#else
  #define fp_rdc_monty(res, t, mod, n0)	fp_rdc_monty_cm0_160(res, t, mod, n0)
#endif

#ifndef LAZY_REDUCTION

#ifdef MONTGOMERY_ARITHMETIC
 #ifdef fp_mul
 #undef fp_mul
 #endif
 #ifdef fp_mul_var
 #undef fp_mul_var
 #endif
 #ifdef fp_sqr
 #undef fp_sqr
 #endif
 #ifdef fp_sqr_var
 #undef fp_sqr_var
 #endif

 #ifdef ASM_MULACC_EXTENSION
  #define fp_mul(res, a, b) 				fp_mul_monty_mulacc_cm0_160(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
  #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_mulacc_cm0_160(n0, a, b, mod, res)

  #define fp_sqr(res, a)					fp_mul_monty_mulacc_cm0_160(MONTY_PRIME_N0[0], a, a, PRIME_P, res)
  #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_mulacc_cm0_160(n0, a, a, mod, res)
 #else
   #define fp_mul(res, a, b) 				fp_mul_monty_cm0_160(MONTY_PRIME_N0[0], a, b, PRIME_P, res)
   #define fp_mul_var(res, a, b, mod, n0)	fp_mul_monty_cm0_160(n0, a, b, mod, res)

   #define fp_sqr(res, a)					fp_mul_monty_cm0_160(MONTY_PRIME_N0[0], a, a, PRIME_P, res)
   #define fp_sqr_var(res, a, mod, n0)		fp_mul_monty_cm0_160(n0, a, a, mod, res)
 #endif
#endif
#endif
#endif

#endif

#endif /* FP_CORTEXM0_H_ */
