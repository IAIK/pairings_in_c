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

#ifndef BI_STD_H_
#define BI_STD_H_

#include "types.h"

int bi_add_var_std(word_t *res, const word_t *a, const word_t *b, const length_t length);
int bi_add_carry_var_std(word_t *res, const word_t *a, const word_t *b, const int carry, const length_t length);
int bi_add_word_var_std(word_t *res, const word_t *a, const word_t b, const length_t length);
int bi_subtract_var_std(word_t *res, const word_t *a, const word_t *b, const length_t length);
int bi_subtract_vl_std(word_t *res, const word_t *a, const word_t *b, const length_t length_a, const length_t length_b);
int bi_subtract_word_var_std(word_t *res, const word_t *a, const word_t b, const length_t length);
void bi_clear_var_std(word_t *a, const length_t length);
void bi_xor_var_std(word_t *res, const word_t *a, const word_t *b, const length_t length);
void bi_shift_right_var_std(word_t *res, const word_t *a, const uint right, const length_t length);
void bi_shift_right_one_var_std(word_t *res, const word_t *a, const length_t length);
void bi_shift_left_one_var_std(word_t *res, const word_t *a, const length_t length);
void bi_div3_var_std(word_t *res, const word_t *a, length_t length);
int bi_compare_var_std(const word_t *a, const word_t *b, const length_t length);
int bi_compare_vl_std(const word_t *a, const word_t *b, const length_t length_a, const length_t length_b);
void bi_multiply_var_std(word_t *result, const word_t *a, const word_t *b, const length_t length_a, const length_t length_b);
void bi_multiply_word_var_std(word_t *result, const word_t *a, const word_t b, const length_t length_a);
void bi_copy_var_std(word_t *dest, const word_t *source, const length_t length);
void bi_set_bit_var_std(word_t* a, const uint bit, const length_t length);
int bi_test_bit_var_std(const word_t* a, const uint bit, const length_t length);
int bi_get_msb_var_std( const word_t* a, const length_t length);
byte bi_get_byte_var_std(const word_t* a, const length_t length, const uint index);
void bi_set_byte_var_std(word_t* a, const length_t length, const uint index, const byte value);
void bi_negate_var_std(word_t* res, const word_t *a, const length_t length);

int bi_get_nafw_std(sbyte *nafw, word_t *a, word_t width);
int bi_get_nafb_std(sbyte *naf, word_t *a);

#endif /* BI_STD_H_ */
