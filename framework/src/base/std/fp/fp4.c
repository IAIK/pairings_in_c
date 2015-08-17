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
#include "fp/fp4.h"
#include "fp/fp2.h"
#include "bigint/bi.h"
#include "param.h"

/**
 * Adds two elements in Fp4.
 * @param res the destination of the sum
 * @param a first operand
 * @param b second operand
 */
void fp4_add_std(fp4_t res, const fp4_t a, const fp4_t b) {
	fp2_add(res[0], a[0], b[0]);
	fp2_add(res[1], a[1], b[1]);
}

/**
 * Subtracts two elements in Fp4.
 * @param res the destination of the difference.
 * @param a first operand
 * @param b second operand
 */
void fp4_sub_std(fp4_t res, const fp4_t a, const fp4_t b) {
	fp2_sub(res[0], a[0], b[0]);
	fp2_sub(res[1], a[1], b[1]);
}

/**
 * Negates one element in Fp4.
 * @param res the destination of the negative a
 * @param a the value to be negated
 */
void fp4_neg_std(fp4_t res, const fp4_t a) {
	fp2_neg(res[0], a[0]);
	fp2_neg(res[1], a[1]);
}

/**
 * Halves one element in Fp4.
 * @param res the destination for the result
 * @param a the value to be halved
 */
void fp4_hlv_std(fp4_t res, const fp4_t a) {
	fp2_hlv(res[0], a[0]);
	fp2_hlv(res[1], a[1]);
}

/**
 * Squares one element in Fp4.
 * @param res the destination for the result
 * @param a the element to be squared
 */
void fp4_sqr_std(fp4_t res, const fp4_t a) {
	fp2_t v0, v1;

	fp2_mul(v0, a[0], a[1]);

	fp2_mul_qnr(v1, a[1]);
	fp2_add(v1, a[0], (const fp_t*) v1);

	fp2_add(res[0], a[0], a[1]);
	fp2_mul(res[0], (const fp_t*) res[0], (const fp_t*) v1);
	fp2_sub(res[0], (const fp_t*) res[0], (const fp_t*) v0);

	fp2_dbl(res[1], (const fp_t*) v0);

	fp2_mul_qnr(v0, (const fp_t*) v0);
	fp2_sub(res[0], (const fp_t*) res[0], (const fp_t*) v0);
}

/**
 * Simple multiplication in Fp4 using Karatsuba method.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 */
void fp4_mul_std(fp4_t res, const fp4_t a, const fp4_t b) {
	fp2_t x, y;
	// Multiplication via Karatsuba method
	// formulas:
	// res0 = a0*b0 + zeta * a1*b1
	// res1 = (a1+a0)(b1+b0) - a0*b0 - a1*b1
	// zeta: a quadratic non-residue in F_{p^2} used to construct F_{p^4} towering F_{p^2}
	//       by defining F_{p^2}[Y]/(Y^2 + zeta)

	fp2_add(x, a[1], a[0]);			                        // x = a1 + a0
	fp2_add(y, b[1], b[0]); 		                        // y = b1 + b0
	fp2_mul(y, (const fp_t*) x, (const fp_t*) y);				// y = x * y = (a1+a0)(b1+b0)

	fp2_mul(res[0], a[0], b[0]);	                      // res0 = a0*b0
	fp2_mul(x, a[1], b[1]);			                        // x = a1*b1

	fp2_sub(res[1], (const fp_t*) y, (const fp_t*) res[0]);		// res1 = y - res0 = (a1+a0)(b1+b0) - a0*b0
	fp2_sub(res[1], (const fp_t*) res[1], (const fp_t*) x);		// res1 = res1 - x = (a1+a0)(b1+b0) - a0*b0 - a1*b1

	fp2_mul_qnr(x, (const fp_t*) x);
	fp2_add(res[0], (const fp_t*) res[0], (const fp_t*) x);
}

/**
 * Multiplies one element in Fp4 with one element in Fp2.
 * @param res the result (Fp4)
 * @param a the first factor (Fp4)
 * @param b the second factor (Fp2)
 */
void fp4_mulfp2_std(fp4_t res, const fp4_t a, const fp2_t b) {
	fp2_mul(res[0], a[0], b);
	fp2_mul(res[1], a[1], b);
}

/**
 * Performs non-SCA-secure square-and-multiply exponentiation in Fp4 that includes dummy operations.
 * @param res the result
 * @param a the operand to be exponentiated
 * @param b the exponent
 */
void fp4_exp_std(fp4_t res, const fp4_t a, const bigint_t b) {
	fp4_t tmp;
	int i;

	fp2_clear(res[1]);
	fp_clear(res[0][1]);
	fp_copy(res[0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp4_sqr(res, (const fp2_t*) res);
		if (bi_test_bit(b, i)) {
			fp4_mul(res, (const fp2_t*) res, (const fp2_t*) a);
		} else { // else side channel dummy
			fp4_mul(tmp, (const fp2_t*) res, (const fp2_t*) a);
		}
	}
}

/**
 * Inversion of an element in Fp4 using direct inversion formulas.
 * @param res the resulting inverse
 * @param a the element to be inverted
 */
void fp4_inv_std(fp4_t res, const fp4_t a) {
	fp2_t t0, t1;

	// formulas: 	res0 = 	a0 / (a0^2 - p0*a1^2)
	// 				    res1 = -a1 / (a0^2 - p0*a1^2)
	//				    for: P(x) = x² - p0

	fp2_sqr(t0, a[0]);
	fp2_sqr(t1, a[1]);
	fp2_mul_qnr(t1, (const fp_t*) t1);
	fp2_sub(t0, (const fp_t*) t0, (const fp_t*) t1);
	fp2_inv(t0, (const fp_t*) t0);

	fp2_mul(res[0], a[0], (const fp_t*) t0);
	fp2_mul(res[1], a[1], (const fp_t*) t0);
	fp2_neg(res[1], (const fp_t*) res[1]);
}

/**
 * Computes the frobenius map of an element in Fp4. The function uses precomputed
 * roots of the quadratic non-residue in Fp2.
 * @param res the result of the frobenius map
 * @param a the input element
 * @param i the order of frobenius
 */
void fp4_frobenius_map_precomp_std(fp4_t res, const fp4_t a, const word_t i) {
	// map the coefficients
	fp2_frobenius_map(res[0], a[0], i);
	fp2_frobenius_map(res[1], a[1], 1);

	// multiply with exponentiated qnr
	fp2_mul(res[1], (const fp_t*) res[1], ROOT_RESIDUE_FP4[2]);

	// iterate the map (map for x^{p^i})
	word_t j = i;
	while (j > 1) {
		fp2_frobenius_map(res[1], (const fp_t*) res[1], 1);
		fp2_mul(res[1], (const fp_t*) res[1], ROOT_RESIDUE_FP4[2]);
		j--;
	}
}

/**
 * Computes the frobenius map of an element in Fp4. The function computes everything
 * from scratch.
 * @param res the result of the frobenius map
 * @param a the input element
 * @param i the order of frobenius
 */
void fp4_frobenius_map_std(fp4_t res, const fp4_t a, const word_t i) {
	fp2_t 		q, q_exp;
	bigint_t 	e;

	fp2_clear(q);
	q[0][0] = 1;
	fp2_mul_qnr(q, (const fp_t*) q);
	bi_copy(e, PRIME_P);
	bi_subtract(e, e, bi_one);
	bi_shift_right_one(e, e);
	fp2_exp(q_exp, (const fp_t*) q, (const word_t*) e);			// qnr^{(p-1)/2} (maybe frobenius, inverse + root is cheaper?)

	// map the coefficients
	fp2_frobenius_map(res[0], a[0], i);
	fp2_frobenius_map(res[1], a[1], 1);

	// multiply with exponentiated qnr
	fp2_mul(res[1], (const fp_t*) res[1], (const fp_t*) q_exp);

	// iterate the map (map for x^{p^i})
	word_t j = i;
	while (j > 1) {
		fp2_frobenius_map(res[1], (const fp_t*) res[1], 1);
		fp2_mul(res[1], (const fp_t*) res[1], (const fp_t*) q_exp);
		j--;
	}
}

/**
 * Multiplies an element in Fp4 with the root of the quadratic non-residue
 * in Fp2 that was adjoined to define Fp4.
 * @param res the resulting product
 * @param a the operand
 */
void fp4_mul_adj_root_std(fp4_t res, const fp4_t a) {
	// fp4: a + bz, where z = adjoined root
	// mult: (a+bz)*z = az + b*qnr
	// note: z is the residue of fp12
	fp2_t tmp;

	fp2_copy(tmp, a[1]);
	fp2_copy(res[1], a[0]);
	fp2_mul_qnr(res[0], (const fp_t*) tmp);
}

/**
 * Clears one Fp4 element.
 * @param a the element to be set to zero
 */
void fp4_clear_std(fp4_t a) {
	fp2_clear(a[0]);
	fp2_clear(a[1]);
}

/**
 * Copies one Fp4 element.
 * @param res the destination
 * @param a the source
 */
void fp4_copy_std(fp4_t res, const fp4_t a) {
	fp2_copy(res[0], a[0]);
	fp2_copy(res[1], a[1]);
}

/**
 * Reduces an element in Fp4 with the fixed modulus.
 * @param a the operand
 */
void fp4_rdc_std(fp4_t a) {
	fp2_rdc(a[0]);
	fp2_rdc(a[1]);
}

/**
 * Converts an element in Fp4 to the Montgomery domain.
 * @param res the resulting value in Montgomery form
 * @param a the value to be converted
 */
void fp4_to_montgomery_std(fp4_t res, const fp4_t a) {
	fp2_to_montgomery(res[0], a[0]);
	fp2_to_montgomery(res[1], a[1]);
}

/**
 * Converts an element in Fp4 (Montgomery domain) back to normal.
 * @param res the resulting normal value
 * @param a the value in Montgomery domain to be converted back
 */
void fp4_from_montgomery_std(fp4_t res, const fp4_t a) {
	fp2_from_montgomery(res[0], a[0]);
	fp2_from_montgomery(res[1], a[1]);
}
