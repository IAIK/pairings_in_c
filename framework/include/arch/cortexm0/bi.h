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

#ifndef BI_CORTEXM0_H_
#define BI_CORTEXM0_H_

#include "config.h"

#if (BNCURVE == BN256 || BNCURVE == BN254)
#ifdef ASM_OPTIMIZATION

void bi_copy_cm0_256(word_t *res, const word_t *a);
void bi_clear_cm0_256(word_t *res);
int bi_add_cm0_256(word_t *res, const word_t *a, const word_t *b);
int bi_subtract_cm0_256(word_t *res, const word_t *a, const word_t *b);
int bi_compare_cm0_256(const word_t *a, const word_t *b);
int bi_shift_right_one_cm0_256(word_t *res, const word_t *a);
int bi_shift_left_one_cm0_256(word_t *res, const word_t *a);
void bi_multiply_cm0_256(word_t * res, const word_t *a, const word_t *b);
void bi_multiply_mulacc_cm0_256(word_t * res, const word_t *a, const word_t *b);
void bi_square_mulacc_cm0_256(word_t * res, const word_t *a);
void bi_subtract_dbllen_cm0_256(word_t * res, const word_t *a, const word_t *b);

#ifdef bi_add
#undef bi_add
#endif

#define bi_add(res, a, b) bi_add_cm0_256(res, a, b)

#ifdef bi_copy
#undef bi_copy
#endif

#define bi_copy(res, a) bi_copy_cm0_256(res, a)

#ifdef bi_clear
#undef bi_clear
#endif

#define bi_clear(res) bi_clear_cm0_256(res)


#ifdef bi_subtract
#undef bi_subtract
#endif

#define bi_subtract(res, a, b) bi_subtract_cm0_256(res, a, b)

#ifdef bi_subtract_dbl_len
#undef bi_subtract_dbl_len
#endif

#define bi_subtract_dbl_len(res, a, b) bi_subtract_dbllen_cm0_256(res, a, b)

#ifdef bi_compare
#undef bi_compare
#endif

#define bi_compare(a, b) bi_compare_cm0_256(a, b)

#ifdef bi_shift_right_one
#undef bi_shift_right_one
#endif

#define bi_shift_right_one(res, a) bi_shift_right_one_cm0_256(res, a)

#ifdef bi_shift_left_one
#undef bi_shift_left_one
#endif

#define bi_shift_left_one(res, a) bi_shift_left_one_cm0_256(res, a)

#ifdef bi_multiply
#undef bi_multiply
#endif

#ifdef bi_multiply_var
#undef bi_multiply_var
#endif

#define bi_multiply_var(res, a, b, len_a, len_b) 	bi_multiply_cm0_var(res, a, b, len_a, len_b)

#ifdef bi_square
#undef bi_square
#endif

#ifdef ASM_MULACC_EXTENSION

 #ifdef LAZY_REDUCTION
  #ifdef DEDICATED_SQUARING
   #define bi_square(res, a) 			bi_square_mulacc_cm0_256(res, a)
  #else
   #define bi_square(res, a) 			bi_multiply_mulacc_cm0_256(res, a, a)
  #endif
   #define bi_multiply(res, a, b) 	    bi_multiply_mulacc_cm0_256(res, a, b)
 #else
  #define bi_square(res, a) 			bi_multiply_cm0_var(res, a, a, BI_WORDS, BI_WORDS)
  #define bi_multiply(res, a, b) 		bi_multiply_cm0_var(res, a, b, BI_WORDS, BI_WORDS)
 #endif

#else
 #if defined(ASM_UNROLL_MULACC) && !defined(MONTGOMERY_ARITHMETIC)
  #define bi_square(res, a) 			bi_multiply_cm0_256(res, a, a)
  #define bi_multiply(res, a, b) 		bi_multiply_cm0_256(res, a, b)
 #else
  #define bi_square(res, a) 			bi_multiply_cm0_var(res, a, a, BI_WORDS, BI_WORDS)
  #ifdef LAZY_REDUCTION
    #define bi_multiply(res, a, b) 		bi_multiply_cm0_256_karatsuba(res, a, b)
  #else
    #define bi_multiply(res, a, b) 		bi_multiply_cm0_var(res, a, b, BI_WORDS, BI_WORDS)
  #endif
 #endif
#endif

#endif
#elif (BNCURVE == BN158)
#ifdef ASM_OPTIMIZATION

void bi_copy_cm0_160(word_t *res, const word_t *a);
void bi_clear_cm0_160(word_t *res);
int bi_add_cm0_160(word_t *res, const word_t *a, const word_t *b);
int bi_subtract_cm0_160(word_t *res, const word_t *a, const word_t *b);
int bi_compare_cm0_160(const word_t *a, const word_t *b);
int bi_shift_right_one_cm0_160(word_t *res, const word_t *a);
int bi_shift_left_one_cm0_160(word_t *res, const word_t *a);
void bi_multiply_cm0_160(word_t * res, const word_t *a, const word_t *b);
void bi_multiply_mulacc_cm0_160(word_t * res, const word_t *a, const word_t *b);
void bi_square_mulacc_cm0_160(word_t * res, const word_t *a);
void bi_subtract_dbllen_cm0_160(word_t * res, const word_t *a, const word_t *b);

#ifdef bi_add
#undef bi_add
#endif

#define bi_add(res, a, b) bi_add_cm0_160(res, a, b)

#ifdef bi_copy
#undef bi_copy
#endif

#define bi_copy(res, a) bi_copy_cm0_160(res, a)

#ifdef bi_clear
#undef bi_clear
#endif

#define bi_clear(res) bi_clear_cm0_160(res)


#ifdef bi_subtract
#undef bi_subtract
#endif

#define bi_subtract(res, a, b) bi_subtract_cm0_160(res, a, b)

#ifdef bi_subtract_dbl_len
#undef bi_subtract_dbl_len
#endif

#define bi_subtract_dbl_len(res, a, b) bi_subtract_dbllen_cm0_160(res, a, b)

#ifdef bi_compare
#undef bi_compare
#endif

#define bi_compare(a, b) bi_compare_cm0_160(a, b)

#ifdef bi_shift_right_one
#undef bi_shift_right_one
#endif

#define bi_shift_right_one(res, a) bi_shift_right_one_cm0_160(res, a)

#ifdef bi_shift_left_one
#undef bi_shift_left_one
#endif

#define bi_shift_left_one(res, a) bi_shift_left_one_cm0_160(res, a)

#ifdef bi_multiply
#undef bi_multiply
#endif

#ifdef bi_multiply_var
#undef bi_multiply_var
#endif

#define bi_multiply_var(res, a, b, len_a, len_b) 	bi_multiply_cm0_var(res, a, b, len_a, len_b)

#ifdef bi_square
#undef bi_square
#endif

#ifdef ASM_MULACC_EXTENSION

 #ifdef LAZY_REDUCTION
   #define bi_square(res, a) 			bi_multiply_mulacc_cm0_160(res, a, a)
   #define bi_multiply(res, a, b) 	    bi_multiply_mulacc_cm0_160(res, a, b)
 #else
   #define bi_square(res, a) 			bi_multiply_cm0_var(res, a, a, BI_WORDS, BI_WORDS)
   #define bi_multiply(res, a, b) 		bi_multiply_cm0_var(res, a, b, BI_WORDS, BI_WORDS)
 #endif

#else
 #if defined(ASM_UNROLL_MULACC) && !defined(MONTGOMERY_ARITHMETIC)
  #define bi_square(res, a) 			bi_multiply_cm0_160(res, a, a)
  #define bi_multiply(res, a, b) 		bi_multiply_cm0_160(res, a, b)
 #else
  #ifdef LAZY_REDUCTION
   #define bi_multiply(res, a, b) 		bi_multiply_cm0_160(res, a, b)
   #define bi_square(res, a) 			bi_multiply_cm0_160(res, a, a)
  #else
   #define bi_square(res, a) 			bi_multiply_cm0_var(res, a, a, BI_WORDS, BI_WORDS)
   #define bi_multiply(res, a, b) 		bi_multiply_cm0_var(res, a, b, BI_WORDS, BI_WORDS)
  #endif
 #endif
#endif
#endif
#endif

#endif /* BI_CORTEXM0_H_ */
