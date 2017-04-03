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

#include "bigint/bi.h"


/**
 * Returns a binary NAF representation of the input
 * @param naf	an array for the resulting NAF representation
 * @param a		the value to be converted into NAF
 * @return the number of elements in the NAF representation
 */
int bi_get_nafb_std(sbyte *naf, word_t *a) {
	uint i = 0;
	word_t carry, tmp;

	carry = 0;

	while (bi_compare(a, bi_zero) > 0) {
		if (bi_is_odd(a)) {
			// at this point, no carry can exist
			naf[i] = 2 - (a[0]&3);
			tmp = a[0] >> (BITS_PER_WORD-1);
			a[0] -= (word_t) naf[i];
			carry = tmp & ~(a[0] >> (BITS_PER_WORD-1));
		} else {
			naf[i] = 0;
		}

		// carry propagation
		tmp = a[1] & 0x01 & carry;
		a[1] = a[1] ^ carry;
		carry = tmp;

		bi_shift_right_one(a, a);
		i++;
	}
	return i;
}

/**
 * Adds two big integers of specified length, i.e. res = a + b.
 * @param res 	the result (sum) of the addition
 * @param a		operand a
 * @param b		operand b
 * @param length	length of a, b, and res
 * @return	carry
 */
int bi_add_var_std(word_t *res, const word_t *a, const word_t *b, length_t length) {
	uint	i;
	word_t	c, carry, r;

	carry = 0;
	for (i = 0; i < length; i++) {
		r = *a + *b++;
		c = r < *a++;
		*res = r + carry;
		carry = (*(res++) < r) | c;
	}
	return carry;
}

/**
 * Adds two big integers of specified length and an additional carry, i.e. res = a + b + cin.
 * @param res	the result (sum) of the addition
 * @param a		operand a
 * @param b		operand b
 * @param cin	carry input
 * @param length	length of a, b, and res
 * @return	carry
 */
int bi_add_carry_var_std(word_t *res, const word_t *a, const word_t *b, const int cin, length_t length) {
	uint	i;
	word_t	c, cout, r;

	cout = cin;
	for (i = 0; i < length; i++) {
		r = *(a+i) + *(b+i);
		c = r < *(a+i);
		*(res+i) = r + cout;
		cout = (*(res+i) < r) | c;
	}

	return cout;
}

/**
 * Adds a single word to an big integer of specified length, i.e. res = a + b.
 * @param res	the result of the addition (big integer)
 * @param a		operand a (big integer)
 * @param b		operand b (single word)
 * @param length	length of a and res
 * @return carry
 */
int bi_add_word_var_std(word_t *res, const word_t *a, const word_t b, length_t length) {
	uint 	i = 0;
	word_t 	r, c;

	r = *(a+i) + b;
	c = r < *(a+i);
	*(res+i) = r;
	for (i = 1; i < length && c; i++) {
		r = *(a+i) + c;
		c = r < *(a+i);
		*(res+i) = r;
	}

	return c;
}

/**
 * Subtracts two big integers of specified length, i.e. res = a - b.
 * @param res 	the result (difference) of the subtraction
 * @param a		operand a
 * @param b		operand b
 * @param length	length of a, b, and res
 * @return	carry
 */
int bi_subtract_var_std(word_t *res, const word_t *a, const word_t *b, length_t length) {
	uint	i;
	word_t	c, carry, r;

	carry = 0;
	for (i = 0; i < length; i++) {
		r = *(a+i) - *(b+i);
		c = (*(a+i) < *(b+i));
		*(res+i) = r - carry;
		carry = c | (!r && carry);
	}

	return carry;
}

/**
 * Subtracts two big integers of different length, i.e. res = a - b.
 * Beware that |res| >= MAX(length_a, length_b)
 * @param res	the result of the subtraction
 * @param a		operand a
 * @param b		operand b
 * @param length_a	length of a
 * @param length_b	lenght of b
 * @return
 */
int bi_subtract_vl_std(word_t *res, const word_t *a, const word_t *b, length_t length_a, length_t length_b) {
	// lenght_a must be greater than or equal to length_b to yield a correct result
	uint	i;
	word_t	carry, r;

	carry = 0;
	for (i = 0; i < length_b && i < length_a; i++) {
		r = *(a+i) - *(b+i);
		*(res+i) = r - carry;
		carry = (*(a+i) < (*b+i)) | (!r && carry);
	}

	for (; i < length_a; i++) {
		r = *(a+i) - carry;
		*(res+i) = r;
		carry = !(*(a+i)) && carry;
	}

	return carry;
}

/**
 * Subtracts a single word from an big integer of specified length, i.e. res = a - b.
 * @param res	the result of the subtraction (big integer)
 * @param a		operand a (big integer)
 * @param b		operand b (single word)
 * @param length	length of a and res
 * @return carry
 */
int bi_subtract_word_var_std(word_t *res, const word_t *a, const word_t b, length_t length) {
	uint 	i = 0;
	word_t 	r, c;

	r = *(a+i) - b;
	c = *(a+i) < b;
	*(res+i) = r;
	for (i = 1; i < length && c; i++) {
		r = *(a+i) - c;
		c = !r && c;
		*(res+i) = r;
	}

	return c;
}

/**
 * Sets each element of the big integer to zero.
 * @param a	the big integer to be reset
 * @param length length of a
 */
void bi_clear_var_std(word_t *a, length_t length) {
	uint i;
	for (i = 0; i < length; i++) {
		*a++ = 0;
	}
}

/**
 * Performs an XOR operation on two big integers, i.e. res = a XOR b.
 * @param res the result
 * @param a operand a
 * @param b operand b
 * @param length length of a, b, and res
 */
void bi_xor_var_std(word_t *res, const word_t *a, const word_t *b, length_t length){
	uint i;
	for (i = 0; i < length; i++) {
		*(res+i) = *(a+i) ^ *(b+i);
	}
}

/**
 * Shifts an big integer to the right by the specified amount of bits.
 * @param res the result of the shift operation
 * @param a	the value to be shifted
 * @param right number of bits to shift
 * @param length length of a and res
 */
void bi_shift_right_var_std(word_t *res, const word_t *a, uint right, length_t length) {
	int 	i;
	uint 	wordNum = right >> LD_BITS_PER_WORD;
	uint 	bitNum = right & (BITS_PER_WORD-1);
	word_t 	shift_in;

	for(i = length-1; i >= (int)(length-wordNum); i--)
		res[i] = 0;

	if (bitNum == 0) {
		a += wordNum;
		for (i = 0; i < (int)(length-wordNum); i++) {
			*(res+i) = *(a+i);
		}
	} else {
		a += wordNum;
		for (i = 0; i < (int)(length-wordNum -1); i++) {
			shift_in = *(a+i+1) << (BITS_PER_WORD - bitNum);
			*(res+i) = (*(a+i) >> bitNum) | shift_in;
		}
		*(res+i) = *(a+i) >> bitNum;
	}
}

/**
 * Performs a division by 3.
 * @param res result of the division
 * @param a value to be divided
 * @param length length of a and res
 */
void bi_div3_var_std(word_t *res, const word_t *a, length_t length) {
	word_t t[length];
	word_t r[2*length];
	uint i;

	// define the constant that has the same effect as 1/3
#if BYTES_PER_WORD == 4
	t[0] = 0xaaaaaaab;
	for (i = 1; i < length; i++) {
		t[i] = 0xaaaaaaaa;
	}
#elif BYTES_PER_WORD == 2
	t[0] = 0xaaab;
	for (i = 1; i < length; i++) {
		t[i] = 0xaaaa;
	}
#elif BYTES_PER_WORD == 1
	t[0] = 0xab;
	for (i = 1; i < length; i++) {
		t[i] = 0xaa;
	}
#endif
	bi_multiply_var(r, a, t, length, length);
	bi_copy_var(res, r, length);
}

/**
 * Shifts a big integer right by one bit.
 * @param res the result of the shift operation
 * @param a the value to be shifted
 * @param length length of a and res
 */
void bi_shift_right_one_var_std(word_t *res, const word_t *a, length_t length) {
	uint i;
	word_t shift_in;
	for (i = 0; i < (length-1); i++) {
		shift_in = a[i+1] << (BITS_PER_WORD-1);
		res[i] = (a[i] >> 1) | shift_in;
	}
	res[length-1] = a[length-1] >> 1;
}

/**
 * Shifts a big integer left by one bit.
 * @param res the result of the shift operation
 * @param a the value to be shifted
 * @param length length of a and res
 */
void bi_shift_left_one_var_std(word_t *res, const word_t *a, length_t length) {
	uint i;
	word_t shift_in = 0, shift_out;
	for (i = 0; i < length; i++) {
		shift_out = a[i] >> (BITS_PER_WORD-1);
		res[i] = (a[i] << 1) | shift_in;
		shift_in = shift_out;
	}
}

/**
 * Compares two values, a and b, and returns 0 if equal, 1 if a > b, and -1 otherwise.
 * @param a parameter a
 * @param b parameter b
 * @param length length of a and b
 * @return 0 if equal, 1 if a > b, -1 otherwise
 */
int bi_compare_var_std(const word_t *a, const word_t *b, length_t length) {
	int i = length - 1;

	while (i >= 0) {
		if (*(a+i) > *(b+i))
			return 1;
		if (*(a+i) < *(b+i))
			return -1;
		i--;
	}

	return 0;
}

/**
 * Compares two values, a and b, of different length.
 * @param a parameter a
 * @param b parameter b
 * @param length_a length of big integer a
 * @param length_b length of big integer b
 * @return 0 if equal, 1 if a > b, -1 otherwise
 */
int bi_compare_vl_std(const word_t *a, const word_t *b, length_t length_a, length_t length_b) {
	// lenght_a must be greater than or equal to length_b to yield a correct result

	for (length_t i = length_a - 1; i >= length_b; --i) {
		if (a[i] != 0)
			return 1;
	}

	for (length_t i = length_b - 1;; --i) {
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		if (i == 0)
			return 0;
	}
}

/**
 * Multiplies two values a and b, i.e. res = a * b.
 * Beware that |res| >= length_a + length_b
 * @param result the product of a and b
 * @param a operand a
 * @param b operand b
 * @param length_a length of a
 * @param length_b length of b
 */
void bi_multiply_var_std(word_t *result, const word_t *a, const word_t *b, length_t length_a, length_t length_b)
{
	dword_t tmp;
	word_t carry;
	uint i, j;
	bi_clear_var(result, length_a + length_b);

	// many carries ... bad performance -> comba is better :)
	for (i = 0; i < length_a; i++) {
		carry = 0;
		for (j = 0; j < length_b; j++) {
			tmp = *(result+i+j);
			tmp += ((dword_t)*(a+i)) * ((dword_t)*(b+j));
			tmp += carry;
			*(result+i+j) = (word_t) tmp;
			carry = (tmp >> BITS_PER_WORD);
		}
		*(result + i + length_b) = carry;
	}
}

/**
 * Multiplies a big integer with a single word, i.e. res = a * b.
 * Beware that |res| >= length_a + 1.
 * @param result the resulting product (big integer)
 * @param a parameter a (big integer)
 * @param b parameter b (word)
 * @param length_a length of big integer a
 */
void bi_multiply_word_var_std(word_t *result, const word_t *a, const word_t b, length_t length_a) {
	bi_multiply_var(result, a, &b, length_a, 1);
}

/**
 * Copies a big integer.
 * @param dest destination
 * @param source source
 * @param length length of source and destination
 */
void bi_copy_var_std(word_t *dest, const word_t *source, length_t length) {
	uint i;
	for (i = 0; i < length; i++) {
		*dest++ = *source++;
	}
}

/**
 * Sets a single bit in a big integer.
 * @param a the big integer to be manipulated
 * @param bit the number of the bit to be set
 * @param length length of a
 */
void bi_set_bit_var_std(word_t* a, uint bit, length_t length) {
	if (bit >= length*BITS_PER_WORD)
		return;

	uint wordNum = bit >> LD_BITS_PER_WORD;
	uint bitNum = bit & (BITS_PER_WORD-1);

	a[wordNum] |= 1 << bitNum;
}

/**
 * Tests whether a bit is set, i.e. returns 1 if the specified bit is set, 0 otherwise.
 * @param a big integer that is to be tested
 * @param bit number of the bit to be tested
 * @param length length of parameter a
 * @return 1 if set, 0 otherwise
 */
int bi_test_bit_var_std(const word_t* a, uint bit, length_t length) {
	if (bit >= length * BITS_PER_WORD)
		return 0;

	uint wordNum = bit >> LD_BITS_PER_WORD;
	uint bitNum = bit & (BITS_PER_WORD-1);

	return (a[wordNum] >> bitNum) & 1;
}

/**
 * Returns the index of the most significant bit set.
 * @param a parameter where the MSB is to be determined
 * @param length length of a
 * @return index of the MSB, -1 if a is 0
 */
int bi_get_msb_var_std( const word_t* a, length_t length)
{
	int wordIdx = length-1;
	while (wordIdx >= 0 && !(*(a+wordIdx)))
		wordIdx--;

	if (wordIdx < 0)
		return -1;

	word_t val = a[wordIdx];
	int bitIdx = BITS_PER_WORD-1;
	while (!(val >> bitIdx))
		bitIdx--;

	return (wordIdx*BITS_PER_WORD + bitIdx);
}

/**
 * Returns the byte of the given big integer at the specified index.
 * @param a the big integer
 * @param length length of a
 * @param index the index of the byte to be read
 * @return the byte at the specified index
 */
byte bi_get_byte_var_std(const word_t* a, length_t length, uint index)
{
	uint wordNum = index >> LD_BYTES_PER_WORD;

#if BYTES_PER_WORD == 1
	return a[wordNum];
#else
	uint bitShift = (index & (BYTES_PER_WORD - 1)) << 3;

	return (byte)((a[wordNum] >> bitShift) & 0xFF);
#endif
}

/**
 * Sets the byte of the given big integer at the specified index.
 * @param a the big integer
 * @param length lenght of a
 * @param index the index of the byte to be written
 * @param value the value to be written at the specified index
 */
void bi_set_byte_var_std(word_t* a, length_t length, uint index, byte value)
{
	uint wordNum = index >> LD_BYTES_PER_WORD;
	uint bitShift = (index & (BYTES_PER_WORD - 1)) << 3;

#if BYTES_PER_WORD == 1
	a[wordNum] = value;
#else
	word_t tmp = a[wordNum] & ~(0xFF << bitShift);
	a[wordNum] = tmp | (((word_t)value) << bitShift);
#endif
}

/**
 * Negates a big integer
 * @param res 	the negate of a
 * @param a		the big integer to be negated
 * @param length length of a and res
 */
void bi_negate_var_std(word_t* res, const word_t *a, length_t length) {
	uint i;
	for (i = 0; i < length-1; i++) {
		res[i] = ~a[i];
	}
	bi_add_var(res, res, bi_one, length);
}

