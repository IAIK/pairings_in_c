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
#include "param.h"
#include "bigint/bi.h"
#include "fp/fp2.h"

/**
 * Clears one Fp2 element.
 * @param a the element to be set to zero
 */
void fp2_clear_std(fp2_t a) {
	fp_clear(a[0]);
	fp_clear(a[1]);
}

/**
 * Copies one Fp2 element.
 * @param res the destination
 * @param a the source
 */
void fp2_copy_std(fp2_t res, const fp2_t a) {
	fp_copy(res[0], a[0]);
	fp_copy(res[1], a[1]);
}

/**
 * Adds two elements in Fp2.
 * @param res the destination of the sum
 * @param a first operand
 * @param b second operand
 */
void fp2_add_std(fp2_t res, const fp2_t a, const fp2_t b) {
	fp_add(res[0], a[0], b[0]);
	fp_add(res[1], a[1], b[1]);
}

/**
 * Subtracts two elements in Fp2.
 * @param res the destination of the difference.
 * @param a first operand
 * @param b second operand
 */
void fp2_sub_std(fp2_t res, const fp2_t a, const fp2_t b) {
	fp_sub(res[0], a[0], b[0]);
	fp_sub(res[1], a[1], b[1]);
}

/**
 * Negates one element in Fp2.
 * @param res the destination of the negative a
 * @param a the value to be negated
 */
void fp2_neg_std(fp2_t res, const fp2_t a) {
	fp_neg(res[0], a[0]);
	fp_neg(res[1], a[1]);
}

/**
 * Halves one element in Fp2.
 * @param res the destination for the result
 * @param a the value to be halved
 */
void fp2_hlv_std(fp2_t res, const fp2_t a) {
	fp_hlv(res[0], a[0]);
	fp_hlv(res[1], a[1]);
}

/**
 * Multiplies one element in Fp2 with one element in Fp.
 * @param res the result (Fp2)
 * @param a the first factor (Fp2)
 * @param b the second factor (Fp)
 */
void fp2_mulfp_std(fp2_t res, const fp2_t a, const fp_t b) {
#if 0
	fp_t t;
	fp_mul(t, a[0], b);
	fp_copy(res[0], t);
	fp_mul(t, a[1], b);
	fp_copy(res[1], t);
#else
	fp_mul(res[0], a[0], b);
	fp_mul(res[1], a[1], b);
#endif
}

/**
 * Squares one element in Fp2.
 * @param res the destination for the result
 * @param a the element to be squared
 */
void fp2_sqr_std(fp2_t res, const fp2_t a) {
	fp_t v0, v1;

	fp_mul(v0, a[0], a[1]);

#ifdef FAST_QNR
	fp_sub(v1, a[0], a[1]);
#else
	fp_copy(v1, a[0]);
	int i;
	for (i = 0; i > PRIME_QNR; i--) {
		fp_sub(v1, v1, a[1]);
	}
#endif

	fp_add(res[1], a[0], a[1]);
	fp_mul(res[0], res[1], v1);

#ifndef FAST_QNR
	int i;
	for (i = -1; i > PRIME_QNR; i--) {
		fp_add(res[0], res[0], v0);
	}
#endif

	fp_dbl(res[1], v0);
}

/**
 * Multiplies two element in Fp2 using the lazy reduction technique by Sanchez-Henriquez.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 */
void fp2_mul_lazy(fp2_t res, const fp2_t a, const fp2_t b) {
	word_t d0[2*FP_WORDS], d1[2*FP_WORDS], d2[2*FP_WORDS];

	bi_add(d1, a[0], a[1]);
	bi_add(d1+FP_WORDS, b[0], b[1]);

	bi_multiply(d0, d1, d1+FP_WORDS);
	bi_multiply(d1, a[0], b[0]);
	bi_multiply(d2, a[1], b[1]);

	bi_subtract_dbl_len(d0, d0, d1);
	bi_subtract_dbl_len(d0, d0, d2);
	bi_subtract_dbl_len(d1, d1, d2);

	fp_rdc_monty(res[1], d0, PRIME_P, MONTY_PRIME_N0[0]);
	fp_rdc_monty(res[0], d1, PRIME_P, MONTY_PRIME_N0[0]);
}


/**
 * Simple multiplication in Fp2 using Karatsuba method.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 */
void fp2_mul_std(fp2_t res, const fp2_t a, const fp2_t b) {
	fp_t x, y;

	// using Karatsuba method
	// formulas:
	// res0 = a0*b0 + beta * a1*b1
	// res1 = (a1+a0)(b1+b0) - a0*b0 - a1*b1
	// beta: a quadratic non-residue in F_p used to construct F_{p^2} towering F_p
	//       by defining F_p[X]((X^2 - beta)

	fp_add(x, a[1], a[0]);	// x = a1 + a0
	fp_add(y, b[1], b[0]);	// y = b1 + b0

#if 0
	fp_t z;

	fp_mul(z, x, y);		        // montgomery mult does not allow multiplication into the same var

	fp_mul(y, a[0], b[0]);	    // montgomery mult side effect as above...
	fp_copy(res[0], y);

	fp_mul(x, a[1], b[1]);			// x = a1*b1

	fp_sub(res[1], z, res[0]);	// res1 = y - res0 = (a1+a0)(b1+b0) - a0*b0
#else
	fp_mul(y, x, y);				    // y = x * y = (a1+a0)(b1+b0)

	fp_mul(res[0], a[0], b[0]);	// res0 = a0*b0
	fp_mul(x, a[1], b[1]);			// x = a1*b1

	fp_sub(res[1], y, res[0]);	// res1 = y - res0 = (a1+a0)(b1+b0) - a0*b0

#endif
	fp_sub(res[1], res[1], x);	// res1 = res1 - x = (a1+a0)(b1+b0) - a0*b0 - a1*b1


	//print_value(x, BI_WORDS); print("\n");
	// res0 = res0 + beta * x = a0*b0 + beta * a1*b1
	// note that beta (PRIME_QNR) is expected to be negative
#ifdef FAST_QNR
	fp_sub(res[0], res[0], x);
#else
	int i;
	for (i = 0; i > PRIME_QNR; i--) {
		fp_sub(res[0], res[0], x);
	}
#endif
}

/**
 * Computes the frobenius map of an element in Fp2. The function assumes that the quadratic non-residue is -1.
 * @param res the result of the frobenius map
 * @param a the input element
 * @param i the order of frobenius
 */
void fp2_frobenius_map_std(fp2_t res, const fp2_t a, const word_t i) {
	bi_copy(res[0], a[0]);	// a0 stays the same any way
	if (i%2) {	            // odd: negate
		fp_neg(res[1], a[1]);
	} else {
		bi_copy(res[1], a[1]);
	}
}

/**
 * Inversion of an element in Fp2 based on Itoh Tsujii that uses the map of frobenius.
 * @param res the resulting inverse
 * @param a the element to be inverted
 */
void fp2_inv_frb_std(fp2_t res, const fp2_t a)
{
	// previous implementation based on Itoh Tsujii, replaced by direct formula
	fp2_t tmp;
	fp_t  t1, t2;
	int i;

	// calculate inverse based on inverse of subfield
	// formula:
	// a^{-1} = (a^r)^{-1} * a^{r-1} where r = p+1

	fp2_frobenius_map(tmp, a, (word_t) 1);	// a^p = a^{r-1}

	// calculate a^r = a^{p+1}
	// we know that the result is in F_p, hence we can simplify...
	fp_mul(t1, a[0], a[0]);
	fp_mul(t2, a[1], a[1]);

#ifdef FAST_QNR
	fp_sub(t1, t1, t2);
#else
	for (i = 0; i > PRIME_QNR; i--) {
		fp_sub(t1, t1, t2);
	}
#endif


	// a^{-r}
	fp_inv(t2, t1);

	// t2 * tmp = a^{-r} * a^{r-1}
	fp_mul(res[0], tmp[0], t2);
	fp_mul(res[1], tmp[1], t2);
}

/**
 * Inversion of an element in Fp2 using direct inversion formulas.
 * @param res the resulting inverse
 * @param a the element to be inverted
 */
void fp2_inv_std(fp2_t res, const fp2_t a) {
	fp_t t0, t1;
	int i;

	// formulas: 	res0 = 	a0 / (a0^2 - p0*a1^2)
	// 				    res1 = -a1 / (a0^2 - p0*a1^2)
	//				    for: P(x) = x² - p0

	fp_sqr(t0, a[0]);
	fp_sqr(t1, a[1]);
	// multiply with qnr and subtract (p0*a1²)
	// is simplified because qnr is negative -> addition

#ifdef FAST_QNR
	fp_add(t0, t0, t1);
#else
	for (i = 0; i > PRIME_QNR; i--) {
		fp_add(t0, t0, t1);
	}
#endif
	fp_inv(t1, t0);

#if 0
	// fp_mul in montgomery form needs separate areas in memory
	fp_mul(t0, a[0], t1);
	fp_copy(res[0], t0);
	fp_mul(t0, a[1], t1);
	fp_neg(res[1], t0);
#else
	fp_mul(res[0], a[0], t1);
	fp_mul(res[1], a[1], t1);
	fp_neg(res[1], res[1]);
#endif
}

/**
 * Performs non-SCA-secure square-and-multiply exponentiation in Fp2 that includes dummy operations.
 * @param res the result
 * @param a the operand to be exponentiated
 * @param b the exponent
 */
void fp2_exp_sqrmul_std(fp2_t res, const fp2_t a, const bigint_t b) {
	int i = 0;
	fp2_t r, t;

	fp_clear(r[1]);
	fp_copy(r[0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp2_sqr(r, (const fp_t*) r);

		if (bi_test_bit(b, i)) {
			fp2_mul(r, (const fp_t*) r, (const fp_t*) a);
		} else {
			fp2_mul(t, (const fp_t*) r, (const fp_t*) a);
		}
	}

	fp2_copy(res, (const fp_t*) r);
}

#ifdef MONTGOMERY_ARITHMETIC

/**
 * Computes the square root in Fp2 based on Tonelli-Shanks algorithm.
 * It needs to be ensured prior to invocation that a square root exists
 * @param res the resulting square root
 * @param a the operand
 */
void fp2_sqrt_std(fp2_t res, const fp2_t a) {
	// Warning: this method does not check whether there exists a solution
	bigint_t exp;
	fp2_t a1, alpha;
	fp_t t; // test

	bi_clear(exp);
	exp[0] = 3;
	bi_subtract(exp, PRIME_P, exp);
	bi_shift_right(exp, exp, 2);
	fp2_exp(a1, a, exp);

	fp2_sqr(alpha, (const fp_t*) a1);
	fp2_mul(alpha, (const fp_t*) alpha, (const fp_t*) a);

	fp2_mul(res, (const fp_t*) a1, (const fp_t*) a);
	bi_subtract(exp, PRIME_P, bi_one);

	fp_mul(t, exp, MONTY_PRIME_R2);

	if (bi_compare(alpha[0], t) == 0 &&
		bi_compare(alpha[1], bi_zero) == 0) {
		fp_copy(t, res[0]);
		fp_copy(res[0], res[1]);
		fp_neg(res[1], t);
	} else {
		fp_add(alpha[0], alpha[0], FP_ONE);
		bi_shift_right(exp, exp, 1);
		fp2_exp(a1, (const fp_t*) alpha, (const word_t*) exp);
		fp2_mul(res, (const fp_t*) res, (const fp_t*) a1);
	}
}

/**
 * Determines for an element in Fp2 whether a square root exists or not. (Legendre operation)
 * @param a the element to check for being a square.
 * @return 1 if the square root exists, 0 if the input is zero, -1 otherwise
 */
int fp2_legendre_std(const fp2_t a) {
	bigint_t 	exp;
	fp2_t 		t0, t1;

	if (bi_compare(a[0], bi_zero) == 0 &&
		bi_compare(a[1], bi_zero) == 0)
		return 0;

	bi_subtract(exp, PRIME_P, bi_one);
	bi_shift_right(exp, exp, 1);
	fp2_exp(t0, a, exp);

	bi_add(exp, PRIME_P, bi_one);
	fp2_exp(t1, (const fp_t*) t0, (const word_t*) exp);

	if (bi_compare(t1[0], FP_ONE) == 0 &&
		bi_compare(t1[1], bi_zero) == 0)
		return 1;

	return -1;
}


#else

/**
 * Computes the square root in Fp2 based on Tonelli-Shanks algorithm.
 * It needs to be ensured prior to invocation that a square root exists
 * @param res the resulting square root
 * @param a the operand
 */
void fp2_sqrt_std(fp2_t res, const fp2_t a) {
	// Warning: this method does not check whether there exists a solution
	bigint_t exp;
	fp2_t a1, alpha;
	fp_t t;

	bi_clear(exp);
	exp[0] = 3;
	bi_subtract(exp, PRIME_P, exp);
	bi_shift_right(exp, exp, 2);
	fp2_exp(a1, a, exp);

	fp2_sqr(alpha, (const fp_t*) a1);
	fp2_mul(alpha, (const fp_t*) alpha, (const fp_t*) a);

	fp2_mul(res, (const fp_t*) a1, a);
	bi_subtract(exp, PRIME_P, bi_one);

	if (bi_compare(alpha[0], exp) == 0 &&
			bi_compare(alpha[1], bi_zero) == 0) {
		fp_copy(t, res[0]);
		fp_copy(res[0], res[1]);
		fp_neg(res[1], t);
	} else {
		fp_add(alpha[0], alpha[0], FP_ONE);
		bi_shift_right(exp, exp, 1);
		fp2_exp(a1, (const fp_t*) alpha, exp);
		fp2_mul(res, (const fp_t*) res, (const fp_t*) a1);
	}
}

/**
 * Determines for an element in Fp2 whether a square root exists or not. (Legendre operation)
 * @param a the element to check for being a square.
 * @return 1 if the square root exists, 0 if the input is zero, -1 otherwise
 */
int fp2_legendre_std(const fp2_t a) {
	bigint_t 	exp;
	fp2_t 		t0, t1;

	if (bi_compare(a[0], bi_zero) == 0 &&
		bi_compare(a[1], bi_zero) == 0)
		return 0;

	bi_subtract(exp, PRIME_P, bi_one);
	bi_shift_right(exp, exp, 1);
	fp2_exp(t0, a, exp);

	bi_add(exp, PRIME_P, bi_one);
	fp2_exp(t1, (const fp_t*) t0, exp);

	if (bi_compare(t1[0], FP_ONE) == 0 &&
		bi_compare(t1[1], bi_zero) == 0)
		return 1;

	return -1;
}

#endif


/**
 * Performs non-SCA-secure exponentiation in Fp2 that includes dummy operations.
 * @param res the result
 * @param a the operand to be exponentiated
 * @param b the exponent
 */
void fp2_exp_std(fp2_t res, const fp2_t a, const bigint_t b) {
	fp2_exp_sqrmul_std(res, a, b);
}

/**
 * Multiplies an element in Fp2 with a quadratic non-residue in Fp2 which is used to build Fp4.
 * @param res the resulting product
 * @param a the operand
 */
void fp2_mul_qnr_std(fp2_t res, const fp2_t a) {
	fp_t x;

#ifdef INVERSE_RESIDUE
	// QNR: 1+i	(in case p = 3 mod 8 / x0 = 7 or 11 mod 11) (ideally we use this one)
	fp_neg(x, a[1]);
	fp_add(res[1], a[0], a[1]);  	//  1*(a1*i) + i*a0
	fp_add(res[0], a[0], x);  		//  i*(i*a1) + a0 = a0 - a1
#else
	// QNR: 1 / (1+i) (for simple impl. of bn curves (zeta!))
	fp_neg(x, a[0]);
	fp_add(res[0], a[0], a[1]);
	fp_add(res[1], a[1], x);
	fp_hlv(res[0], res[0]);
	fp_hlv(res[1], res[1]);
#endif
}

/**
 * Multiplies an element in Fp2 with the inverse of the quadratic non-residue in Fp2 that is used to build Fp4.
 * @param res the resulting quotient
 * @param a the operand
 */
void fp2_div_qnr_std(fp2_t res, const fp2_t a) {
	fp_t x;

#ifdef INVERSE_RESIDUE
	fp_neg(x, a[0]);
	fp_add(res[0], a[0], a[1]);
	fp_add(res[1], a[1], x);
	fp_hlv(res[0], res[0]);
	fp_hlv(res[1], res[1]);
#else
	// QNR: 1 / (1+i) => 1/QNR = 1+i
	fp_neg(x, a[1]);
	fp_add(res[1], a[0], a[1]);  	//  1*(a1*i) + i*a0
	fp_add(res[0], a[0], x);  		//  i*(i*a1) + a0 = a0 - a1
#endif
}

/**
 * Reduces an element in Fp2 with the fixed modulus.
 * @param a the operand
 */
void fp2_rdc_std(fp2_t a) {
	fp_rdc(a[0]);
	fp_rdc(a[1]);
}

/**
 * Converts an element in Fp2 to the Montgomery domain.
 * @param res the resulting value in Montgomery form
 * @param a the value to be converted
 */
void fp2_to_montgomery_std(fp2_t res, const fp2_t a) {
	fp_t tmp;
	fp_mul_monty(tmp, a[0], MONTY_PRIME_R2);
	fp_copy(res[0], tmp);
	fp_mul_monty(tmp, a[1], MONTY_PRIME_R2);
	fp_copy(res[1], tmp);
}

/**
 * Converts an element in Fp2 (Montgomery domain) back to normal.
 * @param res the resulting normal value
 * @param a the value in Montgomery domain to be converted back
 */
void fp2_from_montgomery_std(fp2_t res, const fp2_t a) {
	fp_t tmp;
	fp_mul_monty(tmp, a[0], bi_one);
	fp_copy(res[0], tmp);
	fp_mul_monty(tmp, a[1], bi_one);
	fp_copy(res[1], tmp);
}
