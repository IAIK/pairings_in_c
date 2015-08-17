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

#ifndef BI_H_
#define BI_H_

#include "bigint/bi_std.h"
#include "config.h"

extern const bigint_t bi_one;
extern const bigint_t bi_zero;

#define bi_add(res,a,b)							bi_add_var_std(res, a, b, BI_WORDS)
#define bi_add_var(res,a,b,length)				bi_add_var_std(res, a, b, length)
#define bi_add_carry_var(res,a,b,length,carry)	bi_add_carry_var_std(res, a, b, length, carry)
#define bi_add_word(res, a, b)					bi_add_word_var_std(res, a, b, BI_WORDS)
#define bi_subtract(res,a,b)					bi_subtract_var_std(res, a, b, BI_WORDS)
#define bi_subtract_var(res,a,b,length)			bi_subtract_var_std(res, a, b, length)
#define bi_subtract_vl(res,a,b,len_a,len_b)		bi_subtract_vl_std(res, a, b, len_a, len_b)
#define bi_subtract_word(res, a, b)				bi_subtract_word_var_std(res, a, b, BI_WORDS)
#define bi_subtract_dbl_len(res, a, b)			bi_subtract_var_std(res, a, b, 2*BI_WORDS)
#define bi_clear(a)								bi_clear_var_std(a,BI_WORDS)
#define bi_clear_var(a,length)					bi_clear_var_std(a,length)
#define bi_xor(res,a,b)							bi_xor_var_std(res, a, b, BI_WORDS)
#define bi_xor_var(res,a,b,length)				bi_xor_var_std(res, a, b, length)
#define bi_shift_right(res,a,right)				bi_shift_right_var_std(res, a, right, BI_WORDS)
#define bi_shift_right_var(res,a,right,length)	bi_shift_right_var_std(res, a, right, length)
#define bi_shift_right_one(res, a)				bi_shift_right_one_var_std(res, a, BI_WORDS)
#define bi_shift_right_one_var(res, a, length)	bi_shift_right_one_var_std(res, a, length)
#define bi_shift_left_one(res, a)				bi_shift_left_one_var_std(res, a, BI_WORDS)
#define bi_div3(res, a)							bi_div3_var_std(res, a, BI_WORDS)
#define bi_div3_var(res, a, length)				bi_div3_var_std(res, a, length)
#define bi_compare(a,b)							bi_compare_var_std(a,b,BI_WORDS)
#define bi_compare_var(a,b,length)				bi_compare_var_std(a,b,length)
#define bi_compare_vl(a,b,len_a, len_b)			bi_compare_vl_std(a, b, len_a, len_b)
#define bi_multiply_word(res, a, b)				bi_multiply_word_var_std(res, a, b, BI_WORDS)
#define bi_multiply(res,a,b)					bi_multiply_var_std(res, a, b, BI_WORDS, BI_WORDS)
#define bi_multiply_var(res,a,b,len_a,len_b)	bi_multiply_var_std(res, a, b, len_a, len_b)
#define bi_square(res,a)						bi_multiply_var_std(res, a, a, BI_WORDS, BI_WORDS)
#define bi_square_var(res,a,len)				bi_multiply_var_std(res, a, a, len, len);
#define bi_copy(dest,src)						bi_copy_var_std(dest, src, BI_WORDS)
#define bi_copy_var(dest,src,len)				bi_copy_var_std(dest, src, len)
#define bi_set_bit(a,bit)						bi_set_bit_var_std(a,bit,BI_WORDS)
#define bi_set_bit_var(a,bit,length)			bi_set_bit_var_std(a,bit,length)
#define bi_test_bit(a,bit)						bi_test_bit_var_std(a,bit,BI_WORDS)
#define bi_test_bit_var(a,bit,length)			bi_test_bit_var_std(a,bit,length)
#define bi_get_msb(a)							bi_get_msb_var_std(a,BI_WORDS)
#define bi_get_msb_var(a,length)				bi_get_msb_var_std(a,length)
#define bi_set_byte(a,index,value)				bi_set_byte_var_std(a,BI_WORDS,index,value)
#define bi_set_byte_var(a,length,index,value)	bi_set_byte_var_std(a,length,index,value)
#define bi_get_byte(a,index)					bi_get_byte_var_std(a,BI_WORDS,index)
#define bi_get_byte_var(a,length,index)			bi_get_byte_var_std(a,length,index)

#define bi_is_even(a)							(!(a[0] & 0x01))
#define bi_is_odd(a)							(a[0] & 0x01)

#define bi_get_nafw(nafw, a, width)				bi_get_nafw_std(nafw, a, width)
#define bi_get_nafb(naf, a)						bi_get_nafb_std(naf, a)

#define bi_negate_var(res, a, length)			bi_negate_var_std(res, a, length)
#define bi_negate(res, a)						bi_negate_var_std(res, a, BI_WORDS)

#if ARCHITECTURE==ARCH_CORTEXM0
#include "arch/cortexm0/bi.h"
#endif

#endif /* BI_H_ */
