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

#include "fp/fp.h"
#include "bigint/bi.h"

/**
 * Adds two prime field elements.
 * @param res the sum
 * @param a the first operand
 * @param b the second operand
 * @param mod the prime (modulus)
 */
void fp_add_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod) {
	fp_t t;
	int carry = bi_add(res, a, b);

	if (carry || bi_compare(res, mod) >= 0) {
		bi_subtract(res, res, mod);
	} else {
		bi_subtract(t, res, mod);
	}
}

/**
 * Adds two prime field elements using lazy reduction, ie. it subtracts the prime only if an overflow occurs.
 * @param res the sum
 * @param a the first operand
 * @param b the second operand
 * @param mod the prime (modulus)
 * @param multipleMod a multiple of the modulus that, if an overflow occurs, can be subtracted at once if the prime has leading zeros
 */
void fp_add_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t multipleMod) {
	fp_t t;
	int carry = bi_add(res, a, b);

	if (carry) {
		if (!bi_subtract(res, res, multipleMod))
			bi_subtract(res, res, mod);
	}
}

/**
 * Doubles a prime field element.
 * @param res the doubled result
 * @param a the operand
 * @param mod the prime (modulus)
 */
void fp_dbl_std(fp_t res, const fp_t a, const bigint_t mod) {
	fp_t t;

	word_t c = (a[BI_WORDS-1] >> (BITS_PER_WORD-1));
	bi_shift_left_one(res, a);
	if (bi_compare(res, mod) > 0 || c) {
		bi_subtract(res, res, mod);
	} else {
		bi_subtract(t, res, mod);
	}
}

/**
 * Subtracts two prime field elements.
 * @param res the difference
 * @param a the first operand
 * @param b the second operand that is subtracted
 * @param mod the prime (modulus)
 */
void fp_sub_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod) {
	fp_t t;
	if (bi_subtract(res, a, b)) // borrow
		bi_add(res, res, mod);
	else
		bi_add(t, res, mod);
}

/**
 * Subtracts two prime field elements using lazy reduction, ie. it adds the prime only if an underflow occurs.
 * @param res the difference
 * @param a the first operand
 * @param b the second operand that is subtracted
 * @param mod the prime (modulus)
 * @param multipleMod a multiple of the modulus that, if an underflow occurs, can be added at once if the prime has leading zeros
 */
void fp_sub_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t multipleMod) {
	fp_t t;
	if(bi_subtract(res, a, b)) {
		if (!bi_add(res, res, multipleMod))
			bi_add(res, res, mod);
	}
}

/**
 * Negates a prime field element.
 * @param res the negated element
 * @param a the operand
 * @param mod the prime (modulus)
 */
void fp_neg_std(fp_t res, const fp_t a, const bigint_t mod) {
	if (bi_compare(a, bi_zero) != 0)
		bi_subtract(res, mod, a);
	else
		bi_copy(res, a);
}

/**
 * Negates a prime field element using lazy reduction.
 * @param res the negated element
 * @param a the operand
 * @param mod the prime (modulus)
 * @param multipleMod a multiple of the modulus that is used to "mirror" the operand
 */
void fp_neg_lazy(fp_t res, const fp_t a, const bigint_t mod, const bigint_t multipleMod) {
	if (bi_compare(a, bi_zero) != 0) {
		if (bi_subtract(res, multipleMod, a)) {
			bi_add(res, res, mod);
		}
	} else
		bi_copy(res, a);
}

/**
 * Multiplies to prime field elements in two separate steps: multiplication and barrett reduction.
 * @param res the product
 * @param a the first operand
 * @param b the second operand
 * @param mod the prime (modulus)
 * @param mu parameter mu for barrett reduction
 */
void fp_mul_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t mu) {
	// very simple multiplication, definitely needs optimization, maybe barett multiplication
	// definitely asm
	word_t tmp[2 * FP_WORDS];
	bi_multiply(tmp, a, b);
	fp_rdc_2l_var(tmp, mod, mu);
	bi_copy(res, tmp);
}

/**
 * Halves a prime field element.
 * @param res the halved value
 * @param a the operand
 * @param mod the prime (modulus)
 */
void fp_hlv_std(fp_t res, const fp_t a, const bigint_t mod) {
	if (bi_is_even(a)) {
		bi_shift_right_one(res, a);
	} else {
		int carry = bi_add(res, a, mod);
		bi_shift_right_one(res, res);
		// a zero carry has no impact, a carry of value one is placed in
		// the correct place, branching is more expensive than a simple shift
		// (depends on architecture)
		res[BI_WORDS - 1] |= (carry << (BITS_PER_WORD - 1));
	}
}

/**
 * Montgomery reduction using lazy reduction, ie. the final reduction step is performed using lazy reduction.
 * @param res the reduced result
 * @param t the operand to be reduced (length: 2*BI_WORDS)
 * @param mod the prime (modulus)
 * @param n0 the precomputed value n0 of the montgomery reduction
 * @param multipleMod a multiple of the modulus that may be subtracted at once in the final reduction step if the prime has leading zeros
 */
void fp_rdc_monty_lazy(fp_t res, word_t *t, const bigint_t mod, const word_t n0, const bigint_t multipleMod) {
	int i, j, neg;
	word_t m, c, ct, cp;
	dword_t r;
	ct = 0;

	// Taken from the separated operand scanning method
	for (i = 0; i < BI_WORDS; i++) {
		c = 0;
		m = t[i] * n0;
		for (j = 0; j < BI_WORDS; j++) {
			r = t[i+j];
			r += ((dword_t)m*(dword_t)mod[j]);
			r += c;
			t[i+j] = (r & WORD_MAX);
			c = (r >> BITS_PER_WORD);
		}
		for (j = i + BI_WORDS; j < 2*BI_WORDS; j++) {
			r = t[j];
			r += c;
			t[j] = (r & WORD_MAX);
			c = (r >> BITS_PER_WORD);
		}
		ct += c;
	}

	if (ct > 0) {
		bi_subtract(res, t+BI_WORDS, multipleMod);
	} else {
		bi_copy(res, t+BI_WORDS);
	}
}

/**
 * A montgomery reduction routine.
 * @param res the reduced result
 * @param t the operand to be reduced (length: 2*BI_WORDS)
 * @param mod the prime (modulus)
 * @param n0 the precomputed value n0 of the montgomery reduction
 */
void fp_rdc_monty_std(fp_t res, word_t *t, const bigint_t mod, const word_t n0)
{
	int i, j, neg;
	word_t m, c, ct, cp;
	dword_t r;
	ct = 0;

	// Taken from the separated operand scanning method
	for (i = 0; i < BI_WORDS; i++) {
		c = 0;
		m = t[i] * n0;
		for (j = 0; j < BI_WORDS; j++) {
			r = t[i+j];
			r += ((dword_t)m*(dword_t)mod[j]);
			r += c;
			t[i+j] = (r & WORD_MAX);
			c = (r >> BITS_PER_WORD);
		}
		for (j = i + BI_WORDS; j < 2*BI_WORDS; j++) {
			r = t[j];
			r += c;
			t[j] = (r & WORD_MAX);
			c = (r >> BITS_PER_WORD);
		}
		ct += c;
	}

// LAZY reduction in Fp2 multiplication has impact on reduction step
#ifdef LAZY_REDUCTION
	c = bi_subtract(t, t+BI_WORDS, mod);
	cp = bi_add(res, t+BI_WORDS, mod);

	if (!c) {
		if (cp)
			bi_copy(res, res);
		else
			bi_copy(res, t);
	} else {
		bi_copy(res, t+BI_WORDS);
	}
#else

// Lazy reduction in Fp
#ifdef REAL_LAZY_REDUCTION
	if (ct > 0) {
		int carries = 0;
		carries += bi_subtract(res, t+BI_WORDS, mod);
		carries += bi_subtract(res, res, mod);
		carries += bi_subtract(res, res, mod);
		carries += bi_subtract(res, res, mod);
		carries += bi_subtract(res, res, mod);
		carries += bi_subtract(res, res, mod);
	} else {
		bi_copy(res, t+BI_WORDS);
	}
#else
	c = bi_subtract(t, t+BI_WORDS, mod);
	if (ct || !c) {
		bi_copy(res, t);
	} else {
		bi_copy(res, t+BI_WORDS);
	}
#endif
#endif
}

/**
 * Montgomery prime field multiplication using lazy reduction. It is separated into a bigint multiplication and a reduction step.
 * @param res the product
 * @param a the first operand
 * @param b the second operand
 * @param modulo the prime (modulus)
 * @param n0 the precomputed constant for montgomery reduction
 * @param multipleMod a multiple of the modulus for reduction
 */
void fp_mul_monty_twostep_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const word_t n0, const bigint_t multipleMod) {
	word_t t[2*FP_WORDS];

	bi_multiply(t, a, b);
	fp_rdc_monty_lazy(res, t, modulo, n0, multipleMod);
}

/**
 * Montgomery prime field multiplication that is separated into a bigint multiplication and a reduction step.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 * @param modulo the prime (modulus)
 * @param n0 the precomputed constant for montomgery reduction
 */
void fp_mul_monty_twostep(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const word_t n0) {
	word_t t[2*FP_WORDS];

	bi_multiply(t, a, b);
	fp_rdc_monty(res, t, modulo, n0);
}

/**
 * The montgomery multiplication in its FIPS (Finely Integrated Product Scanning) variant.
 * Warning: This one is rather slow in pure C - in assembler it can be nicely optimized.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 * @param n the modulus (prime)
 * @param n0 the precomputed constant for montgomery reduction
 */
void fp_mul_monty_fips_std(fp_t res, const fp_t a, const fp_t b, const bigint_t n, const word_t n0) {
	int 	i, j;
	word_t 	t[3];
	word_t 	tmp[3];
	fp_t	m;

	bi_clear_var(t, 3);
	bi_clear_var(tmp, 3);

	for (i = 0; i < BI_WORDS; i++) {
		for (j = 0; j < i; j++) {
			bi_multiply_var(tmp, a+j, b+i-j, 1, 1);
			bi_add_var(t, tmp, t, 3);
			bi_multiply_var(tmp, m+j, n+i-j, 1, 1);
			bi_add_var(t, tmp, t, 3);
		}
		bi_multiply_var(tmp, a+i, b, 1, 1);
		bi_add_var(t, tmp, t, 3);
		*(m+i) = t[0]*n0;	// mod W
		bi_multiply_var(tmp, m+i, n, 1, 1);
		bi_add_var(t, tmp, t, 3);
		t[0] = t[1];
		t[1] = t[2];
		t[2] = 0;
	}
	for (i = BI_WORDS; i < (2*BI_WORDS); i++) {
		for (j = i-BI_WORDS+1; j < BI_WORDS; j++) {
			bi_multiply_var(tmp, a+j, b+i-j, 1, 1);
			bi_add_var(t, tmp, t, 3);
			bi_multiply_var(tmp, m+j, n+i-j, 1, 1);
			bi_add_var(t, tmp, t, 3);
		}
		m[i-BI_WORDS] = t[0];
		t[0] = t[1];
		t[1] = t[2];
		t[2] = 0;
	}

	bi_copy(res, m);

	if (bi_compare(res, n) >= 0 || t[0])
		bi_subtract(res, res, n);
}

/**
 * Simple and straight forward Montgomery multiplication. Don't expect speed records...
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 * @param modulo the prime (modulus)
 * @param n0 the precomputed constant for montgomery reduction
 */
void fp_mul_monty_std(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const bigint_t n0) {

	// Montgomery multiplication
	word_t tmp[2 * FP_WORDS];
	word_t tmp2[3 * FP_WORDS];
	word_t tmp3[2 * FP_WORDS];

	// Multiplication
	bi_multiply(tmp, a, b); // 2*FP_WORDS

	// Reduction
	// t * n0
	bi_multiply_var(tmp2, tmp, n0, 2 * FP_WORDS, FP_WORDS); // 3*FP_WORDS

	// Multiply by n(=modulo)
	bi_multiply(tmp3, tmp2, modulo); // 2*FP_WORDS

	// Add t
	int carry = bi_add_var(tmp, tmp, tmp3, 2 * FP_WORDS); // 2*FP_WORDS

	// Divide by R(right-shift by R bit)
	bi_shift_right_var(tmp3, tmp, FP_BITS,
			2 * FP_WORDS); // FP_WORDS

	if (carry) {
		bi_subtract(tmp3, tmp3, modulo);
	}

	if (bi_compare_var(tmp3, modulo, FP_WORDS) >= 0) {
		bi_subtract(tmp3, tmp3, modulo);
	}

	bi_copy(res, tmp3);
}

#ifndef REAL_LAZY_REDUCTION

/**
 * Prime field exponentation that converts the operands into the Montgomery domain and converts the result back.
 * @param res the result
 * @param a the operand
 * @param b the exponent
 * @param modulo the prime modulus
 * @param n0 the precomputed constant for Montgomery reduction
 * @param r2 the precomputed constant r^2 for converting into the montgomery domain
 */
void fp_exp_monty(fp_t res, const fp_t a, const bigint_t b,
		const bigint_t modulo, const bigint_t n0, const bigint_t r2) {
	// Montgomery exponentiation

	fp_t x_tilde;
	fp_t a_tilde;
	fp_t tmp;

	fp_mul_monty_var(a_tilde, a, r2, modulo, n0[0]);
	fp_mul_monty_var(x_tilde, bi_one, r2, modulo, n0[0]);

	int num_bits = bi_get_msb(b);
	int i;
	for (i = num_bits; i >= 0; i--) {
		fp_mul_monty_var(tmp, x_tilde, x_tilde, modulo, n0[0]);
		fp_mul_monty_var(x_tilde, a_tilde, tmp, modulo, n0[0]);
		if (bi_test_bit(b, i)) {
			fp_copy(tmp, x_tilde);
		} else {
			fp_copy(x_tilde, tmp);
		}
	}
	fp_mul_monty_var(res, x_tilde, bi_one, modulo, n0[0]);

	if (bi_compare(res, modulo) >= 0) {
		bi_subtract(res, res, modulo);
	}
}

#endif

/**
 * Prime field inversion by exponentiation using Little Fermat. Works for any prime modulus.
 * @param res the resulting inverse
 * @param a the operand
 * @param mod the prime (modulus)
 * @param mu_n the parameter mu for barrett reduction
 */
void fp_inv_exp_var_std(fp_t res, const fp_t a, const bigint_t mod, const bigint_t mu_n) {
	bigint_t e;
	int i;
	fp_t r;

	bi_clear(e); e[0] = 2;
	bi_subtract(e, mod, e);

	fp_copy(r, a);

	// branching is safe as modulus is assumed to be public
	for (i =  bi_get_msb(e)-1; i >= 0; i--) {
		fp_sqr_barett_var(r, r, mod, mu_n);
		if (bi_test_bit(e, i)) {
			fp_mul_barett_var(r, r, a, mod, mu_n);
		}
	}

	fp_copy(res, r);
}

/**
 * Prime field inversion by exponentation using Little Fermat using the default prime and a precomputed exponent.
 * @param res the result
 * @param a the operand
 */
void fp_inv_exp_std(fp_t res, const fp_t a) {
	int i;
	fp_t r;

	fp_copy(r, a);

	for (i =  bi_get_msb(MOD_INV_EXPONENT)-1; i >= 0; i--) {
		fp_sqr(r, r);
		if (bi_test_bit(MOD_INV_EXPONENT, i)) {
			fp_mul(r, r, a);
		}
	}

	fp_copy(res, r);
}

/**
 * Simple square and multiply exponentiation that uses branches and may only be used for known exponents (SCA leakage!).
 * @param res the result
 * @param a the operand
 * @param exp the exponent
 */
void fp_exp_bn(fp_t res, const fp_t a, const bigint_t exp) {
	int i;
	fp_t r;

	fp_copy(r, a);

	for (i =  bi_get_msb(exp)-1; i >= 0; i--) {
		fp_sqr(r, r);
		if (bi_test_bit(exp, i)) {
			fp_mul(r, r, a);
		}
	}

	fp_copy(res, r);
}

/**
 * Special inversion algorithm valid for BN curves.
 * It makes use of the special form of the BN primes
 * to calculate a^(p-2) for side-channel resistant
 * inversion.
 * @param res the inverse of a
 * @param a the value to be inverted
 */
void fp_inv_bn(fp_t res, const fp_t a) {
	fp_t t1, t2;

	fp_exp_bn(t1, a, BN_INV_CONST);	// a^{6x-1}
	fp_mul(t2, t1, a);
	fp_exp_bn(t2, t2, EC_PARAM_X);
	fp_sqr(res, t2);
	fp_sqr(t2, res);        				// a^{24x^2}
	fp_mul(t1, t2, t1);
	fp_mul(res, res, t2);
	fp_exp_bn(t2, res, EC_PARAM_X);	// a^{36x^3}
	fp_mul(res, t1, t2);
	fp_exp_bn(t2, t2, EC_PARAM_X);	// a^{36x^4}
	fp_mul(res, res, t2);
}

#ifndef MONTGOMERY_ARITHMETIC
/**
 * Sliding window prime field exponentiation algorithm based on the precomputation of a table.
 * @param res the result
 * @param a the operand
 * @param b the exponent
 * @param mod the (prime modulus)
 * @param mu the precomputed constant for the barrett reduction
 */
void fp_exp_slide_var(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const bigint_t mu) {
	fp_t tab[FP_EXP_SLW_TBL_SZ];	// precomputation table
	int i;

	bi_copy(tab[0], a);
	fp_sqr_var(res, a, mod, mu);

	// precomputation of table: a, a^3, a^5,...
	for (i = 1; i < FP_EXP_SLW_TBL_SZ; i++) {
		fp_mul_var(tab[i], tab[i - 1], res, mod, mu);
	}

	//fp_set_dig(t, 1);
	bi_clear(res); res[0] = 1;

	int exp;
	int slw_len;
	int bit;
	int step;

	// "step" represents the number of bits that was looked at
	for (bit = bi_get_msb(b); bit >= 0; bit-=step) {
		if (bi_test_bit(b, bit)) {

			slw_len = 1;	// length of sliding window found
			exp 	= 1;	// index of the exponent in the sliding window
			i 		= 1;	// running idx to find sliding window

			// analyze exponent
			while (i < FP_EXP_SLW_WIDTH && (bit-i) >= 0) {
				if (bi_test_bit(b, bit-i)) {
					exp = (exp << (i - slw_len + 1)) + 1;
					slw_len = i+1;
				}
				i++;
			}
			step = i;

			// pre-processing: square
			for (i = 0; i < slw_len; i++) {
				fp_sqr_var(res, res, mod, mu);
			}

			// multiply precomupted
			fp_mul_var(res, res, tab[exp >> 1], mod, mu);

			// post-processing: square
			for (i = slw_len; i < step; i++) {
				fp_sqr_var(res, res, mod, mu);
			}
		} else {
			// simple square in case of zero
			fp_sqr_var(res, res, mod, mu);
			step = 1;
		}
	}
}
#endif

#ifdef MONTGOMERY_ARITHMETIC

#ifdef REAL_LAZY_REDUCTION

/**
 * Square-and-Multiply prime field exponentiation using lazy reduction technique.
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the modulus
 * @param n0 the precomputed constant for the Montgomery reduction
 * @param multipleMod a multiple of the modulus for reduction
 */
void fp_exp_sqrmul_lazy(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0, const bigint_t multipleMod) {
	fp_t r, t;
	int i;

	fp_copy(r, FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp_sqr_var(t, r, mod, n0, multipleMod);
		fp_mul_var(r, t, a, mod, n0, multipleMod);
		if (bi_test_bit(b, i)) {
			fp_copy(t, r);
		} else {// else side channel dummy (not really secure)
			fp_copy(r, t);
		}
	}

	fp_copy(res, r);
}

/**
 * Prime field exponentiation using lazy reduction technique.
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the modulus
 * @param n0 the precomputed constant for the Montgomery reduction
 * @param multipleMod a multiple of the modulus for reduction
 */
void fp_exp_lazy(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0, const bigint_t multipleMod) {
	fp_exp_sqrmul_lazy(res, a, b, mod, n0, multipleMod);
}

/**
 * Prime field square root computation using the lazy reduction technique.
 * @param res the result
 * @param a the operand
 * @param mod the prime modulus
 * @param n0 the precomputed constant for the Montgomery reduction
 * @param multipleMod a multiple of the modulus for reduction
 */
void fp_sqrt_lazy(fp_t res, const fp_t a, const bigint_t mod, const word_t n0, const bigint_t multipleMod) {
	// Warning: this method does not check whether there exists a solution
	bigint_t exp;
	bi_add(exp, mod, bi_one);
	bi_shift_right(exp, exp, 2);
	fp_exp_var(res, a, exp, mod, n0, multipleMod);
}

/**
 * Lazy reduction legendre operation in the prime field, ie. it determines whether the operand is a square or not.
 * @param a the operand
 * @param mod the prime modulus
 * @param n0 the precomputed constnat for the montgomery reduction
 * @param multipleMod a multiple of the modulus for reduction
 * @return 1 if square, -1 if not, 0 if zero
 */
int fp_legendre_lazy(const fp_t a, const bigint_t mod, const word_t n0, const bigint_t multipleMod) {
	bigint_t 	exp;
	fp_t 		tmp;

	if (bi_compare(a, bi_zero) == 0)
		return 0;

	bi_subtract(exp, mod, bi_one);
	bi_shift_right(exp, exp, 1);
	fp_exp_var(tmp, a, exp, mod, n0, multipleMod);

	// actually, monty prime (one) is a parameter...
	if (bi_compare(tmp, FP_ONE) == 0)
		return 1;

	return -1;
}

#else

/**
 * Square-and-Multiply prime field exponentiation.
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the prime (modulus)
 * @param n0 the precomputed constant for the Montgomery reduction
 */
void fp_exp_sqrmul(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0) {
	fp_t r, t;
	int i;

	fp_copy(r, FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp_sqr_var(t, r, mod, n0);
		fp_mul_var(r, t, a, mod, n0);
		if (bi_test_bit(b, i)) {
			fp_copy(t, r);
		} else {// else side channel dummy
			fp_copy(r, t);
		}
	}

	fp_copy(res, r);
}

/**
 * Prime field exponentiation.
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the modulus
 * @param n0 the precomputed constant for the Montgomery reduction
 */
void fp_exp_std(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0) {
	fp_exp_sqrmul(res, a, b, mod, n0);
}

/**
 * Square root computation in the prime field.
 * @param res the result
 * @param a the operand
 * @param mod the prime (modulus)
 * @param n0 the precomputed constant for the montgomery reduction
 */
void fp_sqrt_std(fp_t res, const fp_t a, const bigint_t mod, const word_t n0) {
	// Warning: this method does not check whether there exists a solution
	bigint_t exp;
	bi_add(exp, mod, bi_one);
	bi_shift_right(exp, exp, 2);
	fp_exp_var(res, a, exp, mod, n0);
}

/**
 * Legendre operation in the prime field, ie. it determines whether the operand is a square or not.
 * @param a the operand
 * @param mod the prime modulus
 * @param n0 the precomputed constnat for the montgomery reduction
 * @return 1 if square, -1 if not, 0 if zero
 */
int fp_legendre_std(const fp_t a, const bigint_t mod, const word_t n0) {
	bigint_t 	exp;
	fp_t 		tmp;

	if (bi_compare(a, bi_zero) == 0)
		return 0;

	bi_subtract(exp, mod, bi_one);
	bi_shift_right(exp, exp, 1);
	fp_exp_var(tmp, a, exp, mod, n0);

	// actually, monty prime (one) is a parameter...
	if (bi_compare(tmp, FP_ONE) == 0)
		return 1;

	return -1;
}

#endif

/**
 * Standard prime field inversion using the binary inversion algorithm.
 * @param res the result
 * @param a the operand
 * @param mod the prime (modulus)
 */
void fp_inv_std(fp_t res, const fp_t a, const bigint_t mod) {

	// Algorithm 2.23 from Guide To ECC

	fp_t u, v;
	fp_t x1, x2;
	int k = 0;

	fp_copy(u, a);
	fp_copy(v, mod);

	fp_clear(x1);
	x1[0] = 1;
	fp_clear(x2);

	while (bi_compare(v, bi_zero) > 0) {
		if (bi_is_even(v)) {
			bi_shift_right_one(v, v);
			fp_dbl(x1, x1);
		} else if (bi_is_even(u)) {
			bi_shift_right_one(u, u);
			fp_dbl(x2, x2);
		} else if (bi_compare(v, u) >= 0) {
			bi_subtract(v, v, u);
			bi_shift_right_one(v, v);
			fp_add(x2, x2, x1);
			fp_dbl(x1, x1);
		} else {
			bi_subtract(u, u, v);
			bi_shift_right_one(u, u);
			fp_add(x1, x2, x1);
			fp_dbl(x2, x2);
		}
		k++;
	}

	if (bi_compare(x1, mod) > 0) {
		bi_subtract(x1, x1, mod);
	}

	// Algorithm 2.25 from Guide To ECC


	if (k < BI_BITS) {
		fp_mul(x2, x1, MONTY_PRIME_R2);
		fp_copy(x1, x2);
		k += BI_BITS;
	}

	fp_mul(res, x1, MONTY_PRIME_R2);
	if (k > BI_BITS) {
		k = 2*BI_BITS - k;
		bi_clear(u);
		bi_set_bit(u, k);
		fp_mul(x1, res, u);
		fp_copy(res, x1);
	}
}

#else

/**
 * Square-and-Multiply prime field exponentiation with side-channel dummy (but not SCA secure (use Montgomery ladder instead)).
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the prime (modulus)
 * @param mu the precomputed constant for the Barrett reduction
 */
void fp_exp_sqrmul(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const bigint_t mu) {
	fp_t r, t;
	int i;

	fp_copy(r, FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp_sqr_var(t, r, mod, mu);
		fp_mul_var(r, t, a, mod, mu);
		if (bi_test_bit(b, i)) {
			fp_copy(t, r);
		} else {// else side channel dummy
			fp_copy(r, t);
		}
	}

	fp_copy(res, r);
}

/**
 * Prime field exponentiation (but not SCA secure (use Montgomery ladder instead)).
 * @param res the result
 * @param a the first operand
 * @param b the exponent
 * @param mod the prime (modulus)
 * @param mu the precomputed constant for the Barrett reduction
 */
void fp_exp_std(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const bigint_t mu) {
	fp_exp_sqrmul(res, a, b, mod, mu);
}

/**
 * Prime field square root computation.
 * @param res the result
 * @param a the operand
 * @param mod the prime (modulus)
 * @param mu the precomputed constant for the Barrett reduction
 */
void fp_sqrt_std(fp_t res, const fp_t a, const bigint_t mod, const bigint_t mu) {
	// Warning: this method does not check whether there exists a solution
	bigint_t exp;
	bi_add(exp, mod, bi_one);
	bi_shift_right(exp, exp, 2);
	fp_exp_var(res, a, exp, mod, mu);
}

/**
 * Legendre operation in the prime field, ie. it determines whether the operand is a square or not.
 * @param a the operand
 * @param mod the prime modulus
 * @param mu the precomputed constnat for the Barrett reduction
 * @return 1 if square, -1 if not, 0 if zero
 */
int fp_legendre_std(const fp_t a, const bigint_t mod, const bigint_t mu) {
	bigint_t 	exp;
	fp_t 		tmp;

	if (bi_compare(a, bi_zero) == 0)
		return 0;

	bi_subtract(exp, mod, bi_one);
	bi_shift_right(exp, exp, 1);
	fp_exp_var(tmp, a, exp, mod, mu);

	if (bi_compare(tmp, FP_ONE) == 0)
		return 1;

	return -1;
}

#endif

/***
 * Simple modular reduction function that subtracts the modulus as often as necessary.
 * @param a prime field element to be reduced
 * @param mod the prime (modulus)
 */
void fp_rdc_std(fp_t a, const bigint_t mod) {
	while (bi_compare(a, mod) >= 0)
		bi_subtract(a, a, mod);
}

/**
 * Performs a modular reduction (Barrett reduction) on a big integer that is twice the normal size.
 * @param a the value to be reduced
 * @param mod the prime (modulus)
 * @param mu the constant for Barrett reduction
 */
void fp_rdc_2l_std(word_t *a, const bigint_t mod, const word_t *mu) {
	// perform barrett reduction

    word_t q[2 * (FP_WORDS + 1)];
    word_t q_p[2 * (FP_WORDS + 1)];
    int c1, c2;

    bi_multiply_var(q, a + FP_WORDS - 1, mu, FP_WORDS + 1, FP_WORDS + 1);
    bi_multiply_var(q_p, q + FP_WORDS + 1, mod, FP_WORDS + 1, FP_WORDS);
    bi_subtract_var(a, a, q_p, FP_WORDS + 1);
    bi_copy_var(q, mod, FP_WORDS);
    q[FP_WORDS] = 0;

    // It takes at most two subtractions (this is intended to make it side-channel resistant)
    c1 = bi_subtract_var(q_p, a, q, FP_WORDS+1);
    c2 = bi_subtract_var(q_p+FP_WORDS+1, q_p, q, FP_WORDS+1);

#if (ARCHITECTURE == ARCH_X86_64)
   if (c2)
     	bi_copy(a, q_p);
    if (!(c1 || c2))
    	bi_copy(a, q_p+FP_WORDS+1);
#else
    bi_copy(a, (word_t*)(((-c1) & (int)a) | ((-c2) & (int)q_p) | (~(-c1 | -c2) & (int)(q_p+FP_WORDS+1))));
#endif
}

/**
 * Clears the prime field value.
 * @param a the prime field element
 */
void fp_clear_std(fp_t a) {
	bi_clear(a);
}

/**
 * Copies the prime field element.
 * @param a the destination
 * @param b the source
 */
void fp_copy_std(fp_t a, const fp_t b) {
	bi_copy(a, b);
}

/**
 * Transforms a prime field value into montgomery domain.
 * @param res the result
 * @param a the orignal value
 */
void fp_to_montgomery_std(fp_t res, const fp_t a) {
	fp_t t;
	fp_mul_monty(t, a, MONTY_PRIME_R2);
	fp_copy(res, t);
}

/**
 * Transform a prime field value in montgomery domain back.
 * @param res the result
 * @param a the value in montgomery domain
 */
void fp_from_montgomery_std(fp_t res, const fp_t a) {
	fp_t t;
	fp_mul_monty(t, a, bi_one);
	fp_copy(res, t);
}
