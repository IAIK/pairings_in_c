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
#include "fp/fp12.h"
#include "fp/fp4.h"
#include "fp/fp2.h"
#include "bigint/bi.h"
#include "param.h"

/**
 * Adds two elements in Fp12.
 * @param res the destination of the sum
 * @param a first operand
 * @param b second operand
 */
void fp12_add_std(fp12_t res, const fp12_t a, const fp12_t b) {
	fp4_add(res[0], a[0], b[0]);
	fp4_add(res[1], a[1], b[1]);
	fp4_add(res[2], a[2], b[2]);
}

/**
 * Subtracts two elements in Fp12.
 * @param res the destination of the sum
 * @param a first operand
 * @param b second operand
 */
void fp12_sub_std(fp12_t res, const fp12_t a, const fp12_t b) {
	fp4_sub(res[0], a[0], b[0]);
	fp4_sub(res[1], a[1], b[1]);
	fp4_sub(res[2], a[2], b[2]);
}

/**
 * Negates one element in Fp12.
 * @param res the destination of the negative a
 * @param a the value to be negated
 */
void fp12_neg_std(fp12_t res, const fp12_t a) {
	fp4_neg(res[0], a[0]);
	fp4_neg(res[1], a[1]);
	fp4_neg(res[2], a[2]);
}

/**
 * Halves one element in Fp12.
 * @param res the destination for the result
 * @param a the value to be halved
 */
void fp12_hlv_std(fp12_t res, const fp12_t a) {
	fp4_hlv(res[0], a[0]);
	fp4_hlv(res[1], a[1]);
	fp4_hlv(res[2], a[2]);
}

/**
 * Performs a multiplication of one element in Fp12 with a sparse element in Fp12.
 * @param res the resulting product
 * @param a the non-sparse operand
 * @param b0  Fp4 part of the sparse operand (least significant Fp4 element)
 * @param b10 Fp2 part of the sparse operand (least significant Fp2 element of the second Fp4 element)
 */
void fp12_mul_sparse_std(fp12_t res, const fp12_t a, const fp4_t b0, const fp2_t b10) {
	fp4_t d0, d1;
	fp4_t t0;
	fp4_t v0;

	fp4_mul(d0, a[0], b0);
	fp4_mulfp2(d1, a[1], b10);

	fp4_add(v0, a[1], a[2]);
	fp4_mulfp2(v0, (const fp2_t*) v0, (const fp_t*) b10);
	fp4_sub(v0, (const fp2_t*) v0, (const fp2_t*) d1);
	fp4_mul_adj_root(v0, (const fp2_t*) v0);
	fp4_add(v0, (const fp2_t*) d0, (const fp2_t*) v0);

	fp2_add(t0[0], b0[0], b10);
	fp2_copy(t0[1], b0[1]);
	fp4_add(res[1], a[0], a[1]);
	fp4_mul(res[1], (const fp2_t*) res[1], (const fp2_t*) t0);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) d1);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) d0);

	fp4_add(res[2], a[0], a[2]);
	fp4_mul(res[2], (const fp2_t*) res[2], (const fp2_t*) b0);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d0);
	fp4_add(res[2], (const fp2_t*) res[2], (const fp2_t*) d1);

	fp4_copy(res[0], (const fp2_t*) v0);
}

/**
 * Squares one element in Fp12. Uses the complex squaring by Chung-Hasan.
 * @param res the destination for the result
 * @param a the element to be squared
 */
void fp12_sqr_std(fp12_t res, const fp12_t a) {
	// CH-SQR3 from Multiplication and Squarings on Pairing-friendly fields (Devegili), Chung-Hasan
	fp4_t s0, s1;
	fp4_t t1;

	fp4_sqr(s0, a[0]);

	fp4_add(s1, a[0], a[2]);
	fp4_sub(t1, (const fp2_t*) s1, a[1]);
	fp4_add(s1, (const fp2_t*) s1, a[1]);

	fp4_sqr(s1, (const fp2_t*) s1);
	fp4_sqr(t1, (const fp2_t*) t1);

	fp4_mul(res[0], a[1], a[2]);
	fp4_dbl(res[0], (const fp2_t*) res[0]);

	fp4_add(t1, (const fp2_t*) s1, (const fp2_t*) t1);
	fp4_hlv(t1, (const fp2_t*) t1);

	fp4_sqr(res[1], a[2]);

	fp4_sub(res[2], (const fp2_t*) t1, (const fp2_t*) s0);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) res[1]);

	fp4_mul_adj_root(res[1], (const fp2_t*) res[1]);

	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*) s1);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) res[0]);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) t1);

	fp4_mul_adj_root(res[0], (const fp2_t*) res[0]);
	fp4_add(res[0], (const fp2_t*) res[0], (const fp2_t*) s0);
}

/**
 * Decompression from Karabina in "Squaring in cyclotomic subgroups".
 * Warning: zero case probably not tested!!
 * Warning: not side-channel secure
 * @param a
 */
void fp12_decompress_std(fp12_t a) {
	if (bi_compare((const word_t*) a[1][0], bi_zero) == 0) {
		fp2_t t0;
		fp2_mul(a[0][1], (const fp_t*) a[2][0], (const fp_t*) a[2][1]);
		fp2_dbl(a[0][1], (const fp_t*) a[0][1]);
		fp2_inv(t0, (const fp_t*) a[1][2]);
		fp2_mul(a[0][1], (const fp_t*) a[0][1], (const fp_t*) t0);

		fp2_sqr(a[0][0], (const fp_t*) a[0][1]);
		fp2_dbl(a[0][0], (const fp_t*) a[0][0]);
		fp2_mul(t0, (const fp_t*) a[1][1], (const fp_t*) a[2][0]);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_mul_qnr(a[0][0], (const fp_t*) a[0][0]);
		fp2_add(a[0][0], (const fp_t*) a[0][0], (const fp_t*) FP_ONE);
	} else {
		fp2_t t0, t1;
		fp2_sqr(a[0][1], (const fp_t*) a[2][1]);
		fp2_mul_qnr(a[0][1], (const fp_t*) a[0][1]);

		fp2_sqr(t0, (const fp_t*) a[2][0]);
		fp2_add(a[0][1], (const fp_t*) a[0][1], (const fp_t*) t0);
		fp2_dbl(t0, (const fp_t*) t0);
		fp2_add(a[0][1], (const fp_t*) a[0][1], (const fp_t*) t0);

		fp2_sub(a[0][1], (const fp_t*) a[0][1], (const fp_t*) a[1][1]);
		fp2_sub(a[0][1], (const fp_t*) a[0][1], (const fp_t*) a[1][1]);

		fp2_dbl(t0, (const fp_t*) a[1][0]);
		fp2_dbl(t0, (const fp_t*) t0);
		fp2_inv(t0, (const fp_t*) t0);
		fp2_mul(a[0][1], (const fp_t*) a[0][1], (const fp_t*) t0);

		fp2_sqr(a[0][0], (const fp_t*) a[0][1]);
		fp2_dbl(a[0][0], (const fp_t*) a[0][0]);
		fp2_mul(t0, (const fp_t*) a[1][0], (const fp_t*) a[2][1]);
		fp2_add(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_mul(t0, (const fp_t*) a[1][1], (const fp_t*) a[2][0]);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_sub(a[0][0], (const fp_t*) a[0][0], (const fp_t*) t0);
		fp2_mul_qnr(a[0][0], (const fp_t*) a[0][0]);
		fp2_add(a[0][0], (const fp_t*) a[0][0], (const fp_t*) FP_ONE);
	}
}

/**
 * Compressed squaring as presented by Karabina in
 * "Squaring in Cyclotomic Subgroups".
 * @param res
 * @param a
 */
void fp12_sqr_cyclotomic_compressed(fp12_t res, const fp12_t a) {
	fp2_t a45, a23, b45, b23, t;

	fp2_add(a45, a[2][0], a[2][1]);
	fp2_mul_qnr(b45, a[2][1]);
	fp2_add(b45, (const fp_t*)  b45, a[2][0]);
	fp2_mul(a45, (const fp_t*)  a45, (const fp_t*)  b45);

	fp2_add(a23, a[1][0], a[1][1]);
	fp2_mul_qnr(b23, a[1][1]);
	fp2_add(b23, (const fp_t*) b23, a[1][0]);
	fp2_mul(a23, (const fp_t*) a23, (const fp_t*) b23);

	fp2_mul(b45, a[2][0], a[2][1]);
	fp2_mul(b23, a[1][0], a[1][1]);

	fp2_sub(a45, (const fp_t*) a45, (const fp_t*) b45);
	fp2_mul_qnr(b45, (const fp_t*) b45);
	fp2_sub(a45, (const fp_t*) a45, (const fp_t*) b45);
	fp2_dbl(t, (const fp_t*) a45);
	fp2_add(t, (const fp_t*) t, (const fp_t*) a45);
	fp2_sub(t, (const fp_t*) t, a[1][1]);
	fp2_sub(res[1][1], (const fp_t*) t, a[1][1]);

	fp2_sub(a23, (const fp_t*) a23, (const fp_t*) b23);
	fp2_mul_qnr(t, (const fp_t*) b23);
	fp2_sub(a23, (const fp_t*) a23, (const fp_t*) t);
	fp2_dbl(t, (const fp_t*) a23);
	fp2_add(t, (const fp_t*) t,(const fp_t*)  a23);
	fp2_sub(t, (const fp_t*) t, a[2][0]);
	fp2_sub(res[2][0], (const fp_t*) t, a[2][0]);

	fp2_add(res[1][0], a[1][0], (const fp_t*) b45);
	fp2_dbl(b45, (const fp_t*) b45);
	fp2_add(res[1][0], (const fp_t*) res[1][0], (const fp_t*) b45);
	fp2_dbl(res[1][0], (const fp_t*) res[1][0]);

	fp2_add(res[2][1], a[2][1], (const fp_t*) b23);
	fp2_dbl(b23, (const fp_t*) b23);
	fp2_add(res[2][1], (const fp_t*) res[2][1], (const fp_t*) b23);
	fp2_dbl(res[2][1], (const fp_t*) res[2][1]);
}

/**
 * Squares one element of cyclotomic subgroup in Fp12. Uses the specialized formulas by Granger and Scott.
 * @param res the destination for the result
 * @param a the element to be squared
 */
void fp12_sqr_cyclotomic_std(fp12_t res, const fp12_t a) {
	// Algorithm 24 from Beuchat et. al, derived from Granger & Scott
	fp4_t x, y, z;
	fp2_t t;

	fp4_sqr(x, a[0]);
	fp4_sqr(y, a[1]);
	fp4_sqr(z, a[2]);

	fp2_mul_qnr(z[1], (const fp_t*) z[1]);

	fp2_neg(res[0][0], a[0][0]);
	fp2_dbl(res[0][0], (const fp_t*) res[0][0]);
	fp2_dbl(t, (const fp_t*) x[0]);
	fp2_add(res[0][0], (const fp_t*) res[0][0], (const fp_t*) t);
	fp2_add(res[0][0], (const fp_t*) res[0][0], (const fp_t*) x[0]);

	fp2_dbl(res[0][1], a[0][1]);
	fp2_dbl(t, (const fp_t*) x[1]);
	fp2_add(res[0][1], (const fp_t*) res[0][1], (const fp_t*) t);
	fp2_add(res[0][1], (const fp_t*) res[0][1], (const fp_t*) x[1]);

	fp2_neg(res[1][1], (const fp_t*) a[1][1]);
	fp2_dbl(res[1][1], (const fp_t*) res[1][1]);
	fp2_dbl(t, (const fp_t*) z[0]);
	fp2_add(res[1][1], (const fp_t*) res[1][1], (const fp_t*) t);
	fp2_add(res[1][1], (const fp_t*) res[1][1], (const fp_t*) z[0]);

	fp2_dbl(res[1][0], (const fp_t*) a[1][0]);
	fp2_dbl(t, (const fp_t*) z[1]);
	fp2_add(res[1][0], (const fp_t*) res[1][0], (const fp_t*) t);
	fp2_add(res[1][0], (const fp_t*) res[1][0], (const fp_t*) z[1]);

	fp2_neg(res[2][0], a[2][0]);
	fp2_dbl(res[2][0], (const fp_t*) res[2][0]);
	fp2_dbl(t, (const fp_t*) y[0]);
	fp2_add(res[2][0], (const fp_t*) res[2][0], (const fp_t*) t);
	fp2_add(res[2][0], (const fp_t*) res[2][0], (const fp_t*) y[0]);

	fp2_dbl(res[2][1], a[2][1]);
	fp2_dbl(t, (const fp_t*) y[1]);
	fp2_add(res[2][1], (const fp_t*) res[2][1], (const fp_t*) t);
	fp2_add(res[2][1], (const fp_t*) res[2][1], (const fp_t*) y[1]);
}


/**
 * Simple multiplication in Fp12 using an extended Karatsuba method.
 * @param res the resulting product
 * @param a the first operand
 * @param b the second operand
 */
void fp12_mul_std(fp12_t res, const fp12_t a, const fp12_t b) {
	fp4_t d0, d1, d2;
	fp4_t t0;
  fp4_t v0;

  /*
   * Formulas
   * D0 = a0 b0 , D1 = a1 b1 , D2 = a2 b2
   * D0,1 = (a0 +	fp4_mul(d1, a[1], b[1]); a1 )(b0 + b1 ), D0,2 = (a0 + a2 )(b0 + b2 ), D1,2 = (a1 + a2 )(b1 + b2 )
   * C(x) = D2 x4 + (D1,2 - D1 - D2 )x3 + (D0,2 - D2 - D0 + D1 )x2 + (D0,1 - D1 - D0 )x + D0
   *
   */

	fp4_mul(d0, a[0], b[0]);
	fp4_mul(d1, a[1], b[1]);
	fp4_mul(d2, a[2], b[2]);

	fp4_add(v0, a[1], a[2]);
	fp4_add(t0, b[1], b[2]);
	fp4_mul(v0, (const fp2_t*)t0, (const fp2_t*)v0);
	fp4_sub(v0, (const fp2_t*)v0, (const fp2_t*)d1);
	fp4_sub(v0, (const fp2_t*)v0, (const fp2_t*)d2);
	fp4_mul_adj_root(v0, (const fp2_t*)v0);	    // mult res[0] with qnr
	fp4_add(v0,(const fp2_t*) d0, (const fp2_t*)v0);

	fp4_add(t0, b[0], b[1]);
	fp4_add(res[1], a[0], a[1]);
	fp4_mul(res[1], (const fp2_t*)res[1], (const fp2_t*)t0);
	fp4_sub(res[1], (const fp2_t*)res[1], (const fp2_t*)d1);
	fp4_sub(res[1], (const fp2_t*)res[1], (const fp2_t*)d0);
	fp4_mul_adj_root(t0, (const fp2_t*)d2);			// mult d2 with qnr into t0
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*)t0);

	fp4_add(t0, b[0], b[2]);
	fp4_add(res[2], a[0], a[2]);
	fp4_mul(res[2], (const fp2_t*) res[2], (const fp2_t*) t0);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d2);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d0);
	fp4_add(res[2], (const fp2_t*) res[2], (const fp2_t*) d1);

	fp4_copy(res[0], (const fp2_t*) v0);
}

/**
 * Multiplication of two elements from the extension field Fp12, which
 * uses less memory.
 * WARNING: b must NOT be the same as res, otherwise it will end
 * in a false result.
 * @param res the resulting product
 * @param a the operand a
 * @param b the operand b
 */
void fp12_mul_distinct_b_std(fp12_t res, const fp12_t a, const fp12_t b) {
	fp4_t d0, d1, d2;
	fp4_t t0;

  /*
   * Formulas
   * D0 = a0 b0 , D1 = a1 b1 , D2 = a2 b2
   * D0,1 = (a0 +	a1 )(b0 + b1 ), D0,2 = (a0 + a2 )(b0 + b2 ), D1,2 = (a1 + a2 )(b1 + b2 )
	 * C(x) = D2 x4 + (D1,2 - D1 - D2 )x3 + (D0,2 - D2 - D0 + D1 )x2 + (D0,1 - D1 - D0 )x + D0
   *
   */

	// trying to use less memory
	fp4_mul(d0, a[0], b[0]);
	fp4_mul(d1, a[1], b[1]);
	fp4_mul(d2, a[2], b[2]);

	fp4_add(t0, a[1], a[2]);
	fp4_add(res[1], a[0], a[1]);
	fp4_add(res[2], a[0], a[2]);
	fp4_copy(res[0], (const fp2_t*) t0);

	fp4_add(t0, b[1], b[2]);
	fp4_mul(res[0], (const fp2_t*)t0, (const fp2_t*)res[0]);
	fp4_sub(res[0], (const fp2_t*)res[0], (const fp2_t*)d1);
	fp4_sub(res[0], (const fp2_t*)res[0], (const fp2_t*)d2);
	fp4_mul_adj_root(res[0], (const fp2_t*) res[0]);	// mult res[0] with qnr
	fp4_add(res[0],(const fp2_t*) d0, (const fp2_t*)res[0]);

	fp4_add(t0, b[0], b[1]);
	fp4_mul(res[1], (const fp2_t*)res[1], (const fp2_t*)t0);
	fp4_sub(res[1], (const fp2_t*)res[1], (const fp2_t*)d1);
	fp4_sub(res[1], (const fp2_t*)res[1], (const fp2_t*)d0);
	fp4_mul_adj_root(t0, (const fp2_t*)d2);			// mult d2 with qnr into t0
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*)t0);

	fp4_add(t0, b[0], b[2]);
	fp4_mul(res[2], (const fp2_t*) res[2], (const fp2_t*) t0);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d2);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d0);
	fp4_add(res[2], (const fp2_t*) res[2], (const fp2_t*) d1);
}

/**
 * Multiplication based on the Toom-Cook Method, but with the result
 * being factored by 6. Can be used in the pairing process during the Miller
 * loops since constant multiples vanish in the final exponentiation.
 * @param res the resulting product
 * @param a the operand a
 * @param b the operand b
 */
void fp12_mul_tk3_std(fp12_t res, const fp12_t a, const fp12_t b) {
	fp4_t v0, v1, v2, v3, v4;
	fp4_t c, d, e;

	// calculating v0 - v4
	fp4_add(v1, a[0], a[2]);
	fp4_sub(v2, (const fp2_t*) v1, a[1]);
	fp4_add(v1, (const fp2_t*) v1, a[1]);
	fp4_dbl(v4, a[2]);
	fp4_add(v3, (const fp2_t*) v1, a[1]);
	fp4_add(v3, (const fp2_t*) v3, (const fp2_t*) v4);
	fp4_add(v3, (const fp2_t*) v3, a[2]);

	fp4_add(v0, b[0], b[2]);
	fp4_sub(v4, (const fp2_t*) v0, b[1]);
	fp4_mul(v2, (const fp2_t*) v2, (const fp2_t*) v4);
	fp4_add(v0, (const fp2_t*) v0, b[1]);
	fp4_mul(v1, (const fp2_t*) v1, (const fp2_t*) v0);
	fp4_add(v0, (const fp2_t*) v0, b[1]);
	fp4_dbl(v4, b[2]);
	fp4_add(v0, (const fp2_t*) v0, (const fp2_t*) v4);
	fp4_add(v0, (const fp2_t*) v0, b[2]);
	fp4_mul(v3, (const fp2_t*) v3, (const fp2_t*) v0);

	fp4_mul(v0, a[0], b[0]);
	fp4_mul(v4, a[2], b[2]);

	// calculating result

	fp4_dbl(d, (const fp2_t*) v0);
	fp4_add(d, (const fp2_t*) d, (const fp2_t*) v0);	// 3v0

	fp4_dbl(e, (const fp2_t*) v1);
	fp4_add(e, (const fp2_t*) e, (const fp2_t*) v1);	// 3v1

	fp4_dbl(c, (const fp2_t*) v4);
	fp4_add(c, (const fp2_t*) c, (const fp2_t*) v4);
	fp4_dbl(c, (const fp2_t*) c);		// 6v4

	fp4_sub(res[0], (const fp2_t*) d, (const fp2_t*) e);
	fp4_sub(res[0], (const fp2_t*) res[0], (const fp2_t*) v2);
	fp4_add(res[0], (const fp2_t*) res[0], (const fp2_t*) v3);
	fp4_sub(res[0], (const fp2_t*) res[0], (const fp2_t*) c);
	fp4_sub(res[0], (const fp2_t*) res[0], (const fp2_t*) c);
	fp4_mul_adj_root(res[0], (const fp2_t*) res[0]);
	fp4_add(res[0], (const fp2_t*) res[0], (const fp2_t*) d);
	fp4_add(res[0], (const fp2_t*) res[0], (const fp2_t*) d);

	fp4_sub(res[2], (const fp2_t*) e, (const fp2_t*) c);		// 3v1 - 6v4
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d);
	fp4_sub(res[2], (const fp2_t*) res[2], (const fp2_t*) d);		// 3v1 - 6v4 - 6v0
	fp4_add(res[2], (const fp2_t*) res[2], (const fp2_t*) v2);	// 3v1 - 6v4 - 6v0 + v2

	fp4_dbl(v2, (const fp2_t*) v2);

	fp4_add(res[2], (const fp2_t*) res[2], (const fp2_t*) v2);	// 3v1 - 6v4 - 6v0 + 3v2

	fp4_mul_adj_root(res[1], (const fp2_t*) c);
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*) c);
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*) c);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) v3);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) v2);
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*) e);
	fp4_add(res[1], (const fp2_t*) res[1], (const fp2_t*) e);
	fp4_sub(res[1], (const fp2_t*) res[1], (const fp2_t*) d);
}

/**
 * Exponentiation in the cyclotomic subgroup of Fp12. The exponentiation uses masking
 * mechanisms that counteract timing attacks.
 * WARNING: this masking mechanism makes some trouble on some architectures. An array indexing
 * approach would fix this!
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_cyclotomic_masked_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	word_t mask;
	fp4_t *ptr;
	fp12_t tmp;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp12_sqr_cyclotomic(res, (const fp4_t*) res);
		mask = (word_t) (-bi_test_bit(b, i));
		ptr = (fp4_t*)(((word_t)res & mask)  | ((word_t)tmp & (~mask)));
		fp12_mul(ptr, (const fp4_t*) res, (const fp4_t*) a);
	}
}

/**
 * Exponentiation in the cyclotomic subgroup of Fp12. The exponentiation uses
 * a Montgomery ladder to prevent timing, SPA, and some fault attacks.
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_cyclotomic_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	word_t bit;
	fp4_t *r[2];
	fp12_t tmp;

	// copy a
	fp12_copy(tmp, a);

	r[0] = res;
	r[1] = tmp;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		bit = (word_t) bi_test_bit(b,i);
		fp12_mul(r[((~bit) & 1)], (const fp4_t*) r[(~bit) & 1], (const fp4_t*) r[(bit) & 1]);
		fp12_sqr_cyclotomic(r[bit], (const fp4_t*) r[bit]);
	}
}

/**
 * Exponentiation in the cyclotomic subgroup of Fp12, which is not secured against any attack, but uses
 * dummy operations.
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_cyclotomic_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	fp12_t tmp;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp12_sqr_cyclotomic(res, (const fp4_t*) res);
		if (bi_test_bit(b, i)) {
			fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);
		} else { // else side channel dummy
			fp12_mul(tmp, (const fp4_t*) res, (const fp4_t*) a);
		}
	}
}

/**
 * Exponentiation of elements in Fp12. The exponentiation uses
 * a Montgomery ladder to prevent timing, SPA, and some fault attacks.
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	fp12_t tmp;
	fp4_t *r[2];
	word_t bit;

	// copy a
	fp12_copy(tmp, a);

	r[0] = res;
	r[1] = tmp;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		bit = (word_t) bi_test_bit(b,i);
		fp12_mul(r[((~bit) & 1)], (const fp4_t*) r[((~bit) & 1)], (const fp4_t*) r[((bit) & 1)]);
		fp12_sqr(r[bit], (const fp4_t*) r[bit]);
	}
}

/**
 * Exponentiation of elements in Fp12. The exponentiation uses masking
 * mechanisms that counteract timing attacks.
 * WARNING: this masking mechanism makes some trouble on some architectures. An array indexing
 * approach would fix this!
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_masked_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	fp12_t tmp;
	fp4_t *ptr;
	word_t mask;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp12_sqr(res, (const fp4_t*) res);
		mask = (word_t) (-bi_test_bit(b, i));
		ptr = (fp4_t*)(((word_t)res & mask)  | ((word_t)tmp & (~mask)));
		fp12_mul(ptr, (const fp4_t*) res, (const fp4_t*) a);
	}
}

/**
 * Exponentiation of elements in Fp12, which is not secured against any attack,
 * but uses dummy operations.
 * @param res the result
 * @param a the operand a
 * @param b the exponent b
 */
void fp12_exp_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;
	fp12_t tmp;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp12_sqr(res, (const fp4_t*) res);
		if (bi_test_bit(b, i)) {
			fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);
		} else { // else side channel dummy
			fp12_mul(tmp, (const fp4_t*) res, (const fp4_t*) a);
		}
	}
}

/**
 * Performs an exponentiation involved in the final exponentiation of
 * the pairing. It is specialized for BN254, i.e. the exponent
 * is always 2^62+2^55+1
 * Must NOT be used with Fuentes final exponentiation method as memory
 * locations would overlap and cause failure.
 * @param res the result of the exponentiation
 * @param a the value to be exponentiated
 * @param b the exponent
 */
void fp12_final_exp_bn254(fp12_t res, const fp12_t a, const bigint_t b) {
	int i;
	fp12_t tmp;

	// does compression of elements according to Karabina
	// who uses specialized formulas for squaring in the cyclotomic subgroup
	fp12_sqr_cyclotomic_compressed(res, a);

	for (i = 1; i < 55; i++) {
		fp12_sqr_cyclotomic_compressed(res, (const fp4_t*) res);
	}

	fp12_decompress(res);
	fp12_sqr_cyclotomic(tmp, (const fp4_t*) res);

	for (i = 0; i < 6; i++)
		fp12_sqr_cyclotomic(tmp, (const fp4_t*) tmp);

	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) tmp);
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);
}

/**
 * Performs an exponentiation involved in the final exponentiation of
 * the pairing. The exponent is a constant, therefore it is safe
 * to skip the side-channel dummy or a Montgomery ladder implementation.
 * WARNING: To safe memory, the parameter a must not overlap with the
 * result.
 * @param res the result of the exponentiation
 * @param a the value to be exponentiated
 * @param b the exponent
 */
void fp12_final_exp_std(fp12_t res, const fp12_t a, const bigint_t b) {
	int i = 0;

	// init one
	fp4_clear(res[2]);
	fp4_clear(res[1]);
	fp2_clear(res[0][1]);
	fp_clear(res[0][0][1]);
	fp_copy(res[0][0][0], FP_ONE);

	for (i = bi_get_msb(b); i >= 0; i--) {
		fp12_sqr_cyclotomic(res, (const fp4_t*) res);
		if (bi_test_bit(b, i)) {
			fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);
		}
	}
}

/**
 * Exponentiates a by b and directly multiplies the result with the
 * result. This function is intended to be used from within
 * the final exponentiation of the pairing calculation and can help
 * to reduce memory requirements. The exponent is known beforehand and
 * hence we do not need care about side-channel resistance.
 * WARNING: res and a must not overlap.
 * @param res
 * @param a
 * @param b
 */
void fp12_final_mulexp_std(fp12_t res, fp12_t a, const bigint_t b) {
	int i = 0;
	for (; i <= bi_get_msb(b); i++) {
		if (bi_test_bit(b, i))
			fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);
		fp12_sqr_cyclotomic(a, (const fp4_t*) a);
	}
}

/**
 * Inversion of an element in Fp12 using direct inversion formulas.
 * @param res the resulting inverse
 * @param a the element to be inverted
 */
void fp12_inv_std(fp12_t res, const fp12_t a) {
	fp4_t t0, t1, t2, t3;

	// formulas:	Delta = a0³ - 3*a0*a1*a2*p0 + a1³p0 + a2³p0²
	//				res0  = (a0² - a1*a2*p0) / Delta
	//				res1  = (a2²*p0 - a0a1) / Delta
	//				res2  = (a1² - a0a2) / Delta

	// (a0² - a1*a2*p0)
	fp4_sqr(t0, a[0]);
	fp4_mul(t1, a[1], a[2]);
	fp4_mul_adj_root(t2, (const fp2_t*) t1);
	fp4_sub(t1, (const fp2_t*) t0, (const fp2_t*) t2);

	// (a2²*p0 - a0a1)
	fp4_sqr(t0, a[2]);
	fp4_mul_adj_root(t3, (const fp2_t*) t0);
	fp4_mul(t2, a[0], a[1]);
	fp4_sub(t2, (const fp2_t*) t3, (const fp2_t*) t2);

	// (a1² - a0a2)
	fp4_sqr(t0, a[1]);
	fp4_mul(t3, a[0], a[2]);
	fp4_sub(t3, (const fp2_t*) t0, (const fp2_t*) t3);

	// res1 = a1 * (a1² - a0a2) * p0
	fp4_mul(t0, a[1], (const fp2_t*) t3);
	fp4_mul_adj_root(res[1], (const fp2_t*) t0);

	// res0 = a0 * (a0² - a1*a2*p0)
	fp4_mul(res[0], a[0], (const fp2_t*) t1);

	// res2 = a2 * (a2²*p0 - a0a1) * p0
	fp4_mul(t0, a[2], (const fp2_t*) t2);
	fp4_mul_adj_root(res[2],(const fp2_t*)  t0);

	// t0 = (a0 * (a0² - a1*a2*p0) + a1 * (a1² - a0a2) * p0 +  a2 * (a2²*p0 - a0a1) * p0)^{-1}
	//    = (a0³ - a0a1a2p0 + a1³p0 - a0a1a1p0 + a2³p0² - a0a1a2p0)^{-1}
	//	  = (a0³ - 3*a0*a1*a2*p0 + a1³p0 + a2³p0²)^{-1} = Delta^{-1}
	fp4_add(t0, (const fp2_t*) res[0], (const fp2_t*) res[1]);
	fp4_add(t0, (const fp2_t*) t0, (const fp2_t*)  res[2]);
	fp4_inv(t0, (const fp2_t*) t0);

	fp4_mul(res[0], (const fp2_t*) t1, (const fp2_t*) t0);
	fp4_mul(res[1], (const fp2_t*) t2, (const fp2_t*) t0);
	fp4_mul(res[2], (const fp2_t*) t3, (const fp2_t*) t0);
}

/**
 * Computes the frobenius map of an element in Fp12. The function uses precomputed
 * roots of the quadratic non-residue in Fp2.
 * @param res the result of the frobenius map
 * @param a the input element
 * @param i the order of frobenius
 */
void fp12_frobenius_map_precomp_std(fp12_t res, const fp12_t a, const word_t i) {
	fp4_t* elements = (fp4_t*)a;

	// map the coefficients
	fp2_frobenius_map(res[0][0], a[0][0], i);

	// iterate the map (map for x^{p^i})
	word_t j = i;
	while (j > 0) {
		fp2_frobenius_map(res[1][0], (const fp_t*) elements[1][0], 1);
		fp2_frobenius_map(res[2][0], (const fp_t*) elements[2][0], 1);
		fp2_frobenius_map(res[0][1], (const fp_t*) elements[0][1], 1);
		fp2_frobenius_map(res[1][1], (const fp_t*) elements[1][1], 1);
		fp2_frobenius_map(res[2][1], (const fp_t*) elements[2][1], 1);
		fp2_mul(res[1][0], (const fp_t*) res[1][0], ROOT_RESIDUE_FP4[0]);
		fp2_mul(res[2][0], (const fp_t*) res[2][0], ROOT_RESIDUE_FP4[1]);
		fp2_mul(res[0][1], (const fp_t*) res[0][1], ROOT_RESIDUE_FP4[2]);
		fp2_mul(res[1][1], (const fp_t*) res[1][1], ROOT_RESIDUE_FP4[3]);
		fp2_mul(res[2][1], (const fp_t*) res[2][1], ROOT_RESIDUE_FP4[4]);
		elements = (fp4_t*)res;
		j--;
	}
}



/**
 * Computes the frobenius map of an element in Fp12. The function computes everything
 * from scratch.
 * @param res the result of the frobenius map
 * @param a the input element
 * @param i the order of frobenius
 */
void fp12_frobenius_map_std(fp12_t res, const fp12_t a, const word_t i) {
	fp2_t 		q, q2, q3, q4, q5;
	bigint_t 	e;

	fp2_clear(q);
	q[0][0] = 1;
	fp2_mul_qnr(q2, (const fp_t*) q);
	bi_copy(e, PRIME_P);
	bi_subtract(e, e, bi_one);
	bi_div3(e,e);
	bi_shift_right_one(e,e);
	fp2_exp(q, (const fp_t*) q2, (const word_t*) e);			// qnr^{(p-1)/6}

	fp2_sqr(q2, (const fp_t*) q);
	fp2_mul(q3, (const fp_t*) q, (const fp_t*) q2);
	fp2_sqr(q4, (const fp_t*) q2);
	fp2_mul(q5, (const fp_t*) q4, (const fp_t*) q);

	// map the coefficients
	fp2_frobenius_map(res[0][0], a[0][0], i);
	fp2_frobenius_map(res[1][0], a[1][0], 1);
	fp2_frobenius_map(res[2][0], a[2][0], 1);
	fp2_frobenius_map(res[0][1], a[0][1], 1);
	fp2_frobenius_map(res[1][1], a[1][1], 1);
	fp2_frobenius_map(res[2][1], a[2][1], 1);

	// multiply with exponentiated qnr
	fp2_mul(res[1][0], (const fp_t*) res[1][0], (const fp_t*) q);
	fp2_mul(res[2][0], (const fp_t*) res[2][0], (const fp_t*) q2);
	fp2_mul(res[0][1], (const fp_t*) res[0][1], (const fp_t*) q3);
	fp2_mul(res[1][1], (const fp_t*) res[1][1], (const fp_t*) q4);
	fp2_mul(res[2][1], (const fp_t*) res[2][1], (const fp_t*) q5);

	// iterate the map (map for x^{p^i})
	word_t j = i;
	while (j > 1) {
		fp2_frobenius_map(res[1][0], (const fp_t*) res[1][0], 1);
		fp2_frobenius_map(res[2][0], (const fp_t*) res[2][0], 1);
		fp2_frobenius_map(res[0][1], (const fp_t*) res[0][1], 1);
		fp2_frobenius_map(res[1][1], (const fp_t*) res[1][1], 1);
		fp2_frobenius_map(res[2][1], (const fp_t*) res[2][1], 1);
		fp2_mul(res[1][0], (const fp_t*) res[1][0], (const fp_t*) q);
		fp2_mul(res[2][0], (const fp_t*) res[2][0], (const fp_t*) q2);
		fp2_mul(res[0][1], (const fp_t*) res[0][1], (const fp_t*) q3);
		fp2_mul(res[1][1], (const fp_t*) res[1][1], (const fp_t*) q4);
		fp2_mul(res[2][1], (const fp_t*) res[2][1], (const fp_t*) q5);
		j--;
	}
}

/**
 * Computes the conjugate of an element in Fp12, which are special
 * cases of the frobenius operation. The function uses precomputed
 * roots of the quadratic non-residue in Fp2.
 * @param res the conjugate
 * @param a the input element
 * @param i the order of the conjugate
 */
void fp12_conjugate_std(fp12_t res, const fp12_t a, const word_t i) {

	if (i != 3)
		return;

	// Frb(6)
	fp2_copy(res[0][0], a[0][0]);
	fp2_neg(res[1][0], a[1][0]);
	fp2_copy(res[2][0], a[2][0]);
	fp2_neg(res[0][1], a[0][1]);
	fp2_copy(res[1][1], a[1][1]);
	fp2_neg(res[2][1], a[2][1]);

}

/**
 * Clears one Fp12 element.
 * @param a the element to be set to zero
 */
void fp12_clear_std(fp12_t a) {
	fp4_clear(a[0]);
	fp4_clear(a[1]);
	fp4_clear(a[2]);
}

/**
 * Copies one Fp12 element.
 * @param res the destination
 * @param a the source
 */
void fp12_copy_std(fp12_t res, const fp12_t a) {
	fp4_copy(res[0], a[0]);
	fp4_copy(res[1], a[1]);
	fp4_copy(res[2], a[2]);
}

/**
 * Reduces an element in Fp12 with the fixed modulus.
 * @param a the operand
 */
void fp12_rdc_std(fp12_t a) {
	fp4_rdc(a[0]);
	fp4_rdc(a[1]);
	fp4_rdc(a[2]);
}

/**
 * Converts an element in Fp12 to the Montgomery domain.
 * @param res the resulting value in Montgomery form
 * @param a the value to be converted
 */
void fp12_to_montgomery_std(fp12_t res, const fp12_t a) {
	fp2_to_montgomery(res[0][0], a[0][0]);
	fp2_to_montgomery(res[0][1], a[0][1]);
	fp2_to_montgomery(res[1][0], a[1][0]);
	fp2_to_montgomery(res[1][1], a[1][1]);
	fp2_to_montgomery(res[2][0], a[2][0]);
	fp2_to_montgomery(res[2][1], a[2][1]);
}

/**
 * Converts an element in Fp12 (Montgomery domain) back to normal.
 * @param res the resulting normal value
 * @param a the value in Montgomery domain to be converted back
 */
void fp12_from_montgomery_std(fp12_t res, const fp12_t a) {
	fp2_from_montgomery(res[0][0], a[0][0]);
	fp2_from_montgomery(res[0][1], a[0][1]);
	fp2_from_montgomery(res[1][0], a[1][0]);
	fp2_from_montgomery(res[1][1], a[1][1]);
	fp2_from_montgomery(res[2][0], a[2][0]);
	fp2_from_montgomery(res[2][1], a[2][1]);
}
