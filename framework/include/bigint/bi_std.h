/*
 * bi.h
 *
 *  Created on: Apr 19, 2013
 *      Author: thomas
 */

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
/*void bi_shift_left_var_std(word_t *res, const word_t *a, const uint left, const length_t length);*/
void bi_shift_right_var_std(word_t *res, const word_t *a, const uint right, const length_t length);
//void bi_shift_right_arith_var_std(word_t *res, const word_t *a, const uint right, const length_t length);
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
