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


#include "ec/ec.h"
#include "fp/fp2.h"
#include "fp/fp.h"
#include "bigint/bi.h"
#include "rand.h"

/**
 * Adds two points of an elliptic curve group over the quadratic extension of
 * a prime field using affine coordinates via projective coordinates.
 * @param res the sum of the two points
 * @param a operand a
 * @param b operand b
 */
void ecfp2_add_affine_std(ecfp2_pt res, const ecfp2_pt a, const ecfp2_pt b) {
	ecpoint_fp2_proj a_proj, res_proj;

	ecfp2_get_jacobian_projective(&a_proj, a);
	ecfp2_add_proj(&res_proj, &a_proj, b);
	ecfp2_get_affine_from_jacobian(res, &res_proj);
}

/**
 * Adds two points of an elliptic curve group over the quadratic extension of
 * a prime field using affine coordinates.
 * @param res the sum of the two points
 * @param a operand a
 * @param b operand b
 */
void ecfp2_add_affine_direct_std(ecfp2_pt res, const ecfp2_pt a, const ecfp2_pt b) {
	fp2_t t0, t1;

	if (a->infinity && !b->infinity) {
		fp2_copy(res->x, (const fp_t*) b->x);
		fp2_copy(res->y, (const fp_t*) b->y);
		res->infinity = 0;
		return;
	} else if (!a->infinity && b->infinity) {
		fp2_copy(res->x, (const fp_t*) a->x);
		fp2_copy(res->y, (const fp_t*) a->y);
		res->infinity = 0;
		return;
	} else if (a->infinity && b->infinity) {
		res->infinity = 1;
		return;
	}

	if (bi_compare(a->x[0], b->x[0]) == 0 &&
		bi_compare(a->x[1], b->x[1]) == 0	) {
		if (bi_compare(a->y[0], b->y[0]) == 0 &&
			bi_compare(a->y[1], b->y[1]) == 0) {
			ecfp2_dbl_affine(res, a);
		} else {
			res->infinity = 1;
		}
		return;
	} else {
		res->infinity = 0;
	}

	fp2_sub(t0, (const fp_t*) b->x, (const fp_t*) a->x);
	fp2_sub(t1, (const fp_t*) b->y, (const fp_t*) a->y);
	fp2_inv(t0, (const fp_t*) t0);
	fp2_mul(t1, (const fp_t*) t1, (const fp_t*) t0);
	fp2_sqr(t0, (const fp_t*) t1);

	fp2_sub(t0, (const fp_t*) t0, (const fp_t*) a->x);
	fp2_sub(t0, (const fp_t*) t0, (const fp_t*) b->x);

	fp2_sub(res->x, (const fp_t*) a->x, (const fp_t*) t0);
	fp2_mul(res->x, (const fp_t*) res->x, (const fp_t*) t1);
	fp2_sub(res->y, (const fp_t*) res->x, (const fp_t*) a->y);

	fp2_copy(res->x, (const fp_t*) t0);
}

/**
 * Adds two points of an elliptic curve group over the quadratic extension of
 * a prime field using mixed affine and projective coordinates.
 * @param res the projective sum of the two points
 * @param a the projective point operand
 * @param b the affine point operand
 */
void ecfp2_add_proj_std(ecfp2_proj_pt res, const ecfp2_proj_pt a, const ecfp2_pt b) {
	// calculation based on jacobian coordinates
	// b in projective coordinates is (b.x, b.y, 1)

	if (a->infinity && !b->infinity) {	// P + Infinity = P
		fp2_copy(res->x, (const fp_t*) b->x);
		fp2_copy(res->y, (const fp_t*) b->y);
		fp_copy(res->z[0], FP_ONE);
		fp_copy(res->z[1], bi_zero);
		res->infinity = 0;
		return;
	} else if (!a->infinity && b->infinity) {
		fp2_copy(res->x, (const fp_t*) a->x);
		fp2_copy(res->y, (const fp_t*) a->y);
		fp_copy(res->z[0], FP_ONE);
		fp_copy(res->z[1], bi_zero);
		res->infinity = 0;
		return;
	} else if (a->infinity && b->infinity) {
		res->infinity = 1;
		return;
	}

	fp2_t t0, t1, t2, t3;

	fp2_sqr(t0, (const fp_t*) a->z);			                // t0 = z²
	fp2_mul(t1, (const fp_t*) t0, (const fp_t*) a->z);		// t1 = z³

	fp2_mul(t2, (const fp_t*) t0, (const fp_t*) b->x);		// t2 = b->x*z²
	fp2_sub(t0, (const fp_t*) t2, (const fp_t*) a->x);		// t0 = b->x*z² - a->x

	fp2_mul(t1, (const fp_t*) t1, (const fp_t*) b->y);
	fp2_sub(t1, (const fp_t*) t1, (const fp_t*) a->y);		// t1 = b->y*z³ - a->y

	if (bi_compare(t0[0], bi_zero) == 0 && bi_compare(t0[1], bi_zero) == 0) {
		if (bi_compare(t1[1], bi_zero) == 0 && bi_compare(t1[1], bi_zero) == 0) {
			// point a is equal to point b (doubling!)
			ecfp2_dbl_proj(res, a);
		} else {							                              // otherwise its point (1,1,0) -> infinity
			res->infinity = 1;
		}
		return;
	} else {
		res->infinity = 0;
	}

	fp2_mul(res->z, (const fp_t*) t0, (const fp_t*) a->z);	// res->z = (b->x*z² - a->x) * a->z

	fp2_add(t2, (const fp_t*) t2, (const fp_t*) a->x);		  // t2 = b->x * z² + a->x
	fp2_sqr(t3, (const fp_t*) t0);							            // t3 = (b->x*z² - a->x)²
	fp2_mul(t2, (const fp_t*) t2, (const fp_t*) t3);		    // t2 = (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp2_mul(t0, (const fp_t*) t0, (const fp_t*) t3);		    // t0 = (b->x*z² - a->x)³
	fp2_mul(t0, (const fp_t*) t0, (const fp_t*) a->y);		  // t0 = a->y * (b->x*z² - a->x)³
	fp2_mul(t3, (const fp_t*) t3, (const fp_t*) a->x);		  // t3 = a->x * (b->x*z² - a->x)²

	fp2_sqr(res->x, (const fp_t*) t1);							        // res->x = (b->y*z³ - a->y)²
	fp2_sub(res->x, (const fp_t*) res->x, (const fp_t*) t2);// res->x = (b->y*z³ - a->y)² -
																                          // (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp2_sub(t3, (const fp_t*) t3, (const fp_t*) res->x);		//	a->x * (b->x*z² - a->x)² - res->x
	fp2_mul(t3, (const fp_t*) t3, (const fp_t*) t1);
	fp2_sub(res->y, (const fp_t*) t3, (const fp_t*) t0);		// (b->y*z³ - a->y)(a->x * (b->x*z² - a->x)² - res->x) -
																                          // a->y * (b->x*z² - a->x)³
}

/**
 * Calculates the double of a point of an elliptic curve group over
 * the quadratic extension of a prime field using affine coordinates
 * via projective coordinates. Uses the elliptic curve twist of the
 * originally defined curve.
 * @param res the result
 * @param a the point operand
 */
void ecfp2_dbl_affine_std(ecfp2_pt res, const ecfp2_pt a) {
	ecpoint_fp2_proj a_proj, res_proj;

	ecfp2_get_jacobian_projective(&a_proj, a);
	ecfp2_dbl_proj(&res_proj, &a_proj);
	ecfp2_get_affine_from_jacobian(res, &res_proj);
}

/**
 * Calculates the double of a point of an elliptic curve group over
 * the quadratic extension of a prime field using affine coordinates.
 * Uses the elliptic curve twist of the originally defined curve.
 * @param res the result
 * @param a the point operand
 */
void ecfp2_dbl_affine_direct_std(ecfp2_pt res, const ecfp2_pt a) {
	fp2_t t0, t1;

	if (a->infinity) {
		res->infinity = 1;
		return;
	}

	fp2_sqr(t0, (const fp_t*) a->x);
	fp2_dbl(t1, (const fp_t*) t0);
	fp2_add(t0, (const fp_t*) t0, (const fp_t*) t1);

#ifndef OPTIMIZE_ZERO_A
	fp_clear(t2[1]);							// calc a' of twisted curve
	fp_copy(t2[0], EC_PARAM_A);
	fp2_div_qnr(t2, (const fp_t*) t2);
	fp2_add(t0, t0, t2);
#endif

	fp2_dbl(t1, (const fp_t*) a->y);
	fp2_inv(t1, (const fp_t*) t1);
	fp2_mul(t1, (const fp_t*) t1, (const fp_t*) t0);

	fp2_sqr(t0, (const fp_t*) t1);
	fp2_sub(t0, (const fp_t*) t0, (const fp_t*) a->x);
	fp2_sub(t0, (const fp_t*) t0, (const fp_t*) a->x);

	fp2_sub(res->x, (const fp_t*) a->x, (const fp_t*) t0);
	fp2_mul(res->x, (const fp_t*) res->x, (const fp_t*) t1);
	fp2_sub(res->y, (const fp_t*) res->x, (const fp_t*) a->y);

	fp2_copy(res->x, (const fp_t*) t0);
}

/**
 * Calculates the double of a point of an elliptic curve group over
 * the quadratic extension of a prime field using mixed affine
 * and projective coordinates. Uses the elliptic curve twist of
 * the originally defined curve.
 * @param res the result
 * @param a the point operand
 */
void ecfp2_dbl_proj_std(ecfp2_proj_pt res, const ecfp2_proj_pt a) {
	// calculation based on jacobian coordinates

	if (a->infinity) {
		res->infinity = 1;
		return;
	} else {
		res->infinity = 0;
	}

	fp2_t t0, t1, t2;

	fp2_sqr(t0, (const fp_t*) a->x);

#ifdef OPTIMIZE_ZERO_A
	fp2_dbl(t1, (const fp_t*) t0);
	fp2_add(t1, (const fp_t*) t1, (const fp_t*) t0);			  // t1 = a*z⁴ + 3x²
#else
	fp2_sqr(t1, a->z);
	fp2_sqr(t1, (const fp_t*) t1);				                  // t1 = z⁴

	fp_clear(t2[1]);							                          // calc a' of twisted curve
	fp_copy(t2[0], EC_PARAM_A);
	fp2_div_qnr(t2, (const fp_t*) t2);
	fp2_mul(t1, t1, t2);						                        // t1 = a*z⁴

	fp2_add(t1, t1, t0);
	fp2_add(t1, t1, t0);
	fp2_add(t1, t1, t0);						                        // t1 = a*z⁴ + 3x²
#endif

	fp2_dbl(t0, (const fp_t*) a->y);							          // t0 = 2 * y
	fp2_mul(res->z, (const fp_t*) t0, (const fp_t*) a->z);  // res->z = 2*y*z

	fp2_sqr(t0, (const fp_t*) t0);								          // t0 = 4 * y²
	fp2_mul(t2, (const fp_t*) t0, (const fp_t*) a->x);		  // t2 = 4*x*y²

	fp2_copy(res->y, (const fp_t*) t1);							        // res->y = (3x² + az⁴)
	fp2_dbl(t1, (const fp_t*) t2);								          // t1 = 8*x*y²

	fp2_sqr(res->x, (const fp_t*) res->y);						      // res->x = (3x² + az⁴)²
	fp2_sub(res->x, (const fp_t*) res->x, (const fp_t*) t1);// res->x = (3x² + az⁴)² - 8*x*y²

	fp2_sub(t2, (const fp_t*) t2, (const fp_t*) res->x);		// 4xy² - res->x
	fp2_mul(res->y, (const fp_t*) res->y, (const fp_t*) t2);// res->y = (3x² + az⁴)(4xy² - res->x)

	fp2_sqr(t0, (const fp_t*) t0);
	fp2_hlv(t0, (const fp_t*) t0);								          // t0 = 8 * y⁴

	fp2_sub(res->y, (const fp_t*) res->y, (const fp_t*) t0);// res->y = (3x² + az⁴)(4xy² - res->x) - 8y⁴
}

/**
 * Negates a point of an elliptic curve group defined over the
 * quadratic extension of a prime field, i.e., computes -P.
 * @param a the affine elliptic curve point (out: the negated point)
 */
void ecfp2_neg_affine_std(ecfp2_pt a) {
	fp2_neg(a->y, (const fp_t*) a->y);
}

/**
 * Negates a point of an elliptic curve group defined over the
 * quadratic extension of a prime field, i.e., computes -P.
 * @param a the projective elliptic curve point (out: the negated point)
 */
void ecfp2_neg_proj_std(ecfp2_proj_pt a) {
	fp2_neg(a->y, (const fp_t*) a->y);
}

/**
 * Performs the multiplication of a point of an elliptic curve group
 * defined over the quadratic extension of a prime field with a scalar.
 * @param res the resulting product
 * @param a the elliptic curve point to be multiplied
 * @param k the scalar operand
 */
void ecfp2_mul_l2rb_std(ecfp2_pt res, const ecfp2_pt a, const fp_t k) {
	// plain left-to-right binary multiplication
	int msb = bi_get_msb(k);
	int i ;

	ecpoint_fp2_proj r, tmp;
	r.infinity=1;

	for (i = msb; i >= 0; i--) {
		ecfp2_dbl_proj(&r, &r);
		if (bi_test_bit(k, i)) {
			ecfp2_add_proj(&r, &r, a);
		} else {
			ecfp2_add_proj(&tmp, &r, a);
		}
	}

	ecfp2_get_affine_from_jacobian(res, &r);
}

/**
 * Performs a mixed add and double operation in co-Z coordinates to be used
 * in a specialize Montgomery ladder implementation of the elliptic curve
 * point multiplication. Note that the function updates the parameters!
 * @param x1 the x-coordinate of the first point in the Montgomery ladder
 * @param x2 the x-coordinate of the second point in the Montgomery ladder
 * @param z the common z-coordinate of the two points in the Montgomery ladder
 * @param x_d the constant difference of the x-coordinates of the two points in the Montgomery ladder
 */
void ecfp2_add_dbl_coz_std(fp2_t x1, fp2_t x2, fp2_t z, const fp2_t x_d) {
	/// Algorithm 5 from "Memory-Constrained Implementations of Elliptic Curve Cryptography in Co-Z
	/// Coordinate Representation", Hutter et. al.

	fp2_t r1, r2, r3, r4, r5;

	fp2_sqr(r2, (const fp_t*) z);

#ifndef OPTIMIZE_ZERO_A

	fp_clear(r3[1]);							// calc a' of twisted curve
	fp_copy(r3[0], EC_PARAM_A);
	fp2_div_qnr(r3, (const fp_t*) r3);
	fp2_mul(r3, r3, r2);

#endif

	fp2_mul(r1, (const fp_t*) z, (const fp_t*) r2);

#ifdef USE_PREDEFINED_4B
	fp_clear(r2[1]);							// calc 4b' of twisted curve
	fp_copy(r2[0], EC_PARAM_4B);
	fp2_div_qnr(r2, (const fp_t*) r2);
	fp2_mul(r2, (const fp_t*) r2, (const fp_t*) r1);
#else
	fp_clear(r2[1]);							// calc 4b' of twisted curve
	fp_copy(r2[0], EC_PARAM_B);
	fp2_div_qnr(r2, (const fp_t*) r2);
	fp2_dbl(r2, (const fp_t*) r2);
	fp2_dbl(r2, (const fp_t*) r2);
	fp2_mul(r2, (const fp_t*) r2, (const fp_t*) r1);
#endif

	fp2_sqr(r1, (const fp_t*) x2);

#ifdef OPTIMIZE_ZERO_A

	fp2_sqr(r4, (const fp_t*) r1);

#else

	fp2_sub(r5, r1, r3);
	fp2_sqr(r4, r5);
	fp2_add(r1, r1, r3);

#endif

	fp2_mul(r5, (const fp_t*) x2,(const fp_t*)  r1);

	fp2_dbl(r5, (const fp_t*) r5);
	fp2_dbl(r5, (const fp_t*) r5);
	fp2_add(r5, (const fp_t*) r5, (const fp_t*) r2);

#ifndef OPTIMIZE_ZERO_A

	fp2_add(r1, r1, r3);

#endif

	fp2_sqr(r3, (const fp_t*) x1);
	fp2_add(r1, (const fp_t*) r1, (const fp_t*) r3);

	fp2_sub(x1, (const fp_t*) x1, (const fp_t*) x2);
	fp2_dbl(x2, (const fp_t*) x2);
	fp2_mul(r3, (const fp_t*) x2, (const fp_t*) r2);

	fp2_sub(r4, (const fp_t*) r4, (const fp_t*) r3);
	fp2_sqr(r3, (const fp_t*) x1);

	fp2_sub(r1, (const fp_t*) r1, (const fp_t*) r3);
	fp2_add(x1, (const fp_t*) x1, (const fp_t*) x2);
	fp2_mul(x2, (const fp_t*) x1, (const fp_t*) r1);

	fp2_add(x2, (const fp_t*) x2, (const fp_t*) r2);
	fp2_mul(r2, (const fp_t*) z, (const fp_t*) r3);

	fp2_mul(z, (const fp_t*) x_d, (const fp_t*) r2);
	fp2_sub(x2, (const fp_t*) x2, (const fp_t*) z);
	fp2_mul(x1, (const fp_t*) r5, (const fp_t*) x2);
	fp2_mul(x2, (const fp_t*) r3, (const fp_t*) r4);
	fp2_mul(z, (const fp_t*) r2, (const fp_t*) r5);
}

/**
 * Recovers the coordinates of the result of the Montgomery ladder elliptic curve
 * point multiplication using co-Z coordinates.
 * @param x1 the first point in the Montgomery ladder implementation (out: the x-coordinate of the resulting point)
 * @param x2 the second point in the Montgomery ladder implementation (out: the y-coordinate of the resulting point)
 * @param z the common z-coordinate of the two points in the Montgomery ladder
 * @param x_d the constant difference of the x-coordinates of the two points in the Montgomery ladder
 * @param y_d the difference of the y-coordinates of the two input points
 */
void ecfp2_recover_full_coord_coz_std(fp2_t x1, fp2_t x2, fp2_t z, const fp2_t x_d, const fp2_t y_d) {
	/// Algorithm 7 from "Memory-Constrained Implementations of Elliptic Curve Cryptography in Co-Z
	/// Coordinate Representation", Hutter et. al.

	fp2_t r1, r2, r3, r4;

	fp2_mul(r1, (const fp_t*) x_d, (const fp_t*) z);
	fp2_sub(r2, (const fp_t*) x1, (const fp_t*) r1);
	fp2_sqr(r3, (const fp_t*) r2);

	fp2_mul(r4, (const fp_t*) r3, (const fp_t*) x2);
	fp2_mul(r2, (const fp_t*) r1, (const fp_t*) x1);
	fp2_add(r1, (const fp_t*) x1, (const fp_t*) r1);
	fp2_sqr(x2, (const fp_t*) z);

#ifndef OPTIMIZE_ZERO_A
	fp_clear(r3[1]);							// calc a' of twisted curve
	fp_copy(r3[0], EC_PARAM_A);
	fp2_div_qnr(r3, (const fp_t*) r3);

	//fp2_mul(r3, EC_PARAM_A, x2);
	fp2_mul(r3, r3, x2);
	fp2_add(r2, r2, r3);
#endif

	fp2_mul(r3, (const fp_t*) r2, (const fp_t*) r1);
	fp2_sub(r3, (const fp_t*) r3, (const fp_t*) r4);
	fp2_dbl(r3, (const fp_t*) r3);
	fp2_dbl(r1, (const fp_t*) y_d);
	fp2_dbl(r1, (const fp_t*) r1);

	fp2_mul(r2, (const fp_t*) r1, (const fp_t*) x1);
	fp2_mul(x1, (const fp_t*) r2, (const fp_t*) x2);
	fp2_mul(r2, (const fp_t*) x2, (const fp_t*) z);
	fp2_mul(z, (const fp_t*) r2, (const fp_t*) r1);

#ifdef USE_PREDEFINED_4B
	fp_clear(r4[1]);							// calc 4b' of twisted curve
	fp_copy(r4[0], EC_PARAM_4B);
	fp2_div_qnr(r4, (const fp_t*) r4);
	fp2_mul(r4, (const fp_t*) r4, (const fp_t*) r2);
#else
	fp_clear(r4[1]);							// calc b' of twisted curve
	fp_copy(r4[0], EC_PARAM_B);
	fp2_div_qnr(r4, (const fp_t*) r4);
	fp2_dbl(r4, (const fp_t*) r4);
	fp2_dbl(r4, (const fp_t*) r4);
	fp2_mul(r4, (const fp_t*) r4, (const fp_t*) r2);
#endif

	fp2_add(x2, (const fp_t*) r4, (const fp_t*) r3);
}

int ecfp2_verify_coordinates(fp2_t x, fp2_t y)  {
	// y² = x^3 + a'x + b'
	fp2_t r0, r1;

	fp2_sqr(r1, (const fp_t*) x);
	fp2_mul(r1, (const fp_t*) r1, (const fp_t*) x);

#ifndef OPTIMIZE_ZERO_A
	fp_clear(r0[1]);							// calc a' of twisted curve
	fp_copy(r0[0], EC_PARAM_A);
	fp2_div_qnr(r0, (const fp_t*) r0);
	fp2_mul(r0, r0, x);
	fp2_add(r1, r1, r0);
#endif

	fp_clear(r0[1]);							// calc b' of twisted curve
	fp_copy(r0[0], EC_PARAM_B);
	fp2_div_qnr(r0, (const fp_t*) r0);
	fp2_add(r1, (const fp_t*) r1, (const fp_t*) r0);

	fp2_sqr(r0, (const fp_t*) y);

	return (bi_compare(r0[0], r1[0]) || bi_compare(r0[1], r1[1]));
}

int ecfp2_verify_homogeneous_projective_coordinates(fp2_t x, fp2_t y, fp2_t z) {
	// Y^2 Z = X^3 + a' X Z^2 + b' Z^3

	fp2_t r0, r1, r2, r3;

	fp2_sqr(r1, (const fp_t*) x);
	fp2_mul(r1, (const fp_t*) r1, (const fp_t*) x);

	fp2_sqr(r2, (const fp_t*) z);
#ifndef OPTIMIZE_ZERO_A
	fp_clear(r0[1]);							// calc a' of twisted curve
	fp_copy(r0[0], EC_PARAM_A);
	fp2_div_qnr(r0, (const fp_t*) r0);
	fp2_mul(r0, r0, x);
	fp2_mul(r0, r0, r2);
	fp2_add(r1, r1, r0);
#endif


	fp_clear(r3[1]);							// calc b' of twisted curve
	fp_copy(r3[0], EC_PARAM_B);
	fp2_div_qnr(r0, (const fp_t*) r3);
	fp2_mul(r0, (const fp_t*) r0, (const fp_t*) r2);
	fp2_mul(r0, (const fp_t*) r0, (const fp_t*) (const fp_t*) z);
	fp2_add(r1, (const fp_t*) r1, (const fp_t*) r0);

	fp2_sqr(r0, (const fp_t*) y);
	fp2_mul(r0, (const fp_t*) r0, (const fp_t*) z);

	return (bi_compare(r0[0], r1[0]) || bi_compare(r0[1], r1[1]));
}

/**
 * Elliptic curve point multiplication using a Montgomery ladder with co-Z coordinates.
 * @param res the resulting product
 * @param a the point operand
 * @param k the scalar operand
 */
void ecfp2_mul_montyladder_std(ecfp2_pt res, const ecfp2_pt a, const fp_t k) {
	int msb = bi_get_msb(k);
	int i;
	fp2_t x1, x2, z;
	fp_t *x[2];
	word_t bit;

	x[0] = x1;
	x[1] = x2;

	if (ecfp2_verify_coordinates(a->x, a->y))
		return;

	cprng_get_bytes(z, 2*FP_BYTES);
#ifndef REAL_LAZY_REDUCTION
	fp_rdc(z[0]);
	fp_rdc(z[1]);
#endif

	fp2_mul(x[1], (const fp_t*) a->x, (const fp_t*)z);
	fp2_mul(x[0], (const fp_t*) a->y, (const fp_t*)z);

	if (ecfp2_verify_homogeneous_projective_coordinates(x[1], x[0], z))
		return;

	fp2_clear(x[0]);

	ecfp2_add_dbl_coz_std(x1, x2, z, (const fp_t*) a->x);

	fp2_mul(x1, (const fp_t*) a->x, (const fp_t*) z);

	for (i = msb - 1; i >= 0; i--) {
		bit = bi_test_bit(k, i);
		ecfp2_add_dbl_coz_std(x[~bit & 1], x[bit], z, (const fp_t*) a->x);
	}

	ecfp2_recover_full_coord_coz_std(x[0], x[1], z, (const fp_t*) a->x, (const fp_t*) a->y);

	if (ecfp2_verify_homogeneous_projective_coordinates(x[0], x[1], z))
		return;

	fp2_inv(z, (const fp_t*) z);
	fp2_mul(res->x, (const fp_t*) x[0], (const fp_t*) z);
	fp2_mul(res->y, (const fp_t*) x[1], (const fp_t*) z);
	res->infinity = 0;

	if (ecfp2_verify_coordinates(res->x, res->y))
		return;
}

/**
 * Converts an elliptic curve point in jacobian projective coordinates to
 * an elliptic curve point in affine coordinates.
 * @param affine the resulting affine elliptic curve point
 * @param projective the input projective elliptic curve point
 */
void ecfp2_get_affine_from_jacobian_std(ecfp2_pt affine, const ecfp2_proj_pt projective) {
	affine->infinity = projective->infinity;
	if (projective->infinity)
		return;

	fp2_t t;

	fp2_inv(t, (const fp_t*) projective->z);
	fp2_sqr(affine->y, (const fp_t*) t);
	fp2_mul(affine->x, (const fp_t*) affine->y, (const fp_t*) projective->x);
	fp2_mul(affine->y, (const fp_t*) t, (const fp_t*) affine->y);
	fp2_mul(affine->y, (const fp_t*) affine->y, (const fp_t*) projective->y);
}

/**
 * Converts an elliptic curve point in affine coordinates to
 * an elliptic curve point in projective coordinates.
 * @param projective the resulting projective elliptic curve point
 * @param affine the input affine elliptic curve point
 */
void ecfp2_get_projective_std(ecfp2_proj_pt projective, const ecfp2_pt affine) {
	projective->infinity = affine->infinity;

	if (affine->infinity)
		return;

	fp2_copy(projective->x, (const fp_t*) affine->x);
	fp2_copy(projective->y, (const fp_t*) affine->y);
	fp_copy(projective->z[0], FP_ONE);	fp_clear(projective->z[1]);
}

/**
 * Converts an elliptic curve point in affine coordinates to
 * a randomized elliptic curve point in jacobian projective coordinates.
 * @param projective the resulting randomized, projective elliptic curve point
 * @param affine the input affine elliptic curve point
 */
void ecfp2_get_jacobian_projective_rnd_std(ecfp2_proj_pt projective, const ecfp2_pt affine) {
	projective->infinity = affine->infinity;

	if (affine->infinity)
		return;

	// get random value for z and reduce modulo prime
	cprng_get_bytes(projective->z, 2*FP_BYTES);

#ifndef REAL_LAZY_REDUCTION
	fp_rdc(projective->z[0]);
	fp_rdc(projective->z[1]);
#endif

	fp2_t z2;
	fp2_sqr(z2, (const fp_t*) projective->z);

	// adapt x and y coordinates appropriately
	fp2_mul(projective->x, (const fp_t*) affine->x, (const fp_t*) z2);
	fp2_mul(projective->y, (const fp_t*) affine->y, (const fp_t*) projective->z);
	fp2_mul(projective->y, (const fp_t*) projective->y, (const fp_t*) z2);
}

/**
 * Converts an elliptic curve point in affine coordinates to
 * a randomized elliptic curve point in homogeneous projective coordinates.
 * @param projective the resulting randomized, projective elliptic curve point
 * @param affine the input affine elliptic curve point
 */
void ecfp2_get_homogeneous_projective_rnd_std(ecfp2_proj_pt projective, const ecfp2_pt affine) {
	projective->infinity = affine->infinity;

	if (affine->infinity)
		return;

	// get random value for z and reduce modulo prime
	cprng_get_bytes(projective->z, 2*FP_BYTES);

#ifndef REAL_LAZY_REDUCTION
	fp_rdc(projective->z[0]);
	fp_rdc(projective->z[1]);
#endif

	// adapt x and y coordinates appropriately
	fp2_mul(projective->x, (const fp_t*) affine->x, (const fp_t*) projective->z);
	fp2_mul(projective->y, (const fp_t*) affine->y, (const fp_t*) projective->z);
}

/**
 * Copies a point of an elliptic curve group over the
 * quadratic extension of a prime field.
 * @param res the resulting copy
 * @param a the affine input point to be copied
 */
void ecfp2_copy_std(ecfp2_pt res, const ecfp2_pt a) {
	res->infinity = a->infinity;
	fp2_copy(res->x, (const fp_t*) a->x);
	fp2_copy(res->y, (const fp_t*) a->y);
}

/**
 * Clears a point of an elliptic curve group over the
 * quadratic extension of a prime field.
 * @param a the elliptic curve point in affine coordinates
 */
void ecfp2_clear_std(ecfp2_pt a) {
	fp2_clear(a->x);
	fp2_clear(a->y);
	a->infinity = 0;
}

/**
 * Computes the frobenius map of a point of an elliptic curve group
 * over the quadratic extension of a prime field. Uses a precomputed
 * table for the roots of the quadratic non-residue in Fp2.
 * @param res the resulting elliptic curve point
 * @param a the operand point
 * @param i the order of frobenius
 */
void ecfp2_frobenius_map_precomp_std(ecfp2_pt res, const ecfp2_pt a, const word_t i) {
	fp2_t 		q, q2, q3;
	bigint_t 	e;
	uint 		j;

	ecfp2_copy(res, a);	// TODO: extract i = 1 to save copy

	// map coefficients and multiply with the corresponding roots resulting from the
	// frobenius map in GFp12, i.e. untwist the curve, perform frobenius map, and twist again
	for (j = 0; j < i; j++) {
		fp2_frobenius_map(res->x, (const fp_t*) res->x, 1);
		fp2_mul(res->x, (const fp_t*) res->x, ROOT_RESIDUE_FP4[1]);

		fp2_frobenius_map(res->y, (const fp_t*) res->y, 1);
		fp2_mul(res->y, (const fp_t*) res->y, ROOT_RESIDUE_FP4[2]);
	}
}

/**
 * Computes the frobenius map of a point of an elliptic curve group
 * over the quadratic extension of a prime field. The function computes
 * everything from scratch.
 * @param res the resulting elliptic curve point
 * @param a the operand point
 * @param i the order of frobenius
 */
void ecfp2_frobenius_map_std(ecfp2_pt res, const ecfp2_pt a, const word_t i) {
	fp2_t 		q, q2, q3;
	bigint_t 	e;
	uint 		j;

	fp_copy(q[0], FP_ONE);
	fp_clear(q[1]);
	fp2_mul_qnr(q2, (const fp_t*) q);
	bi_copy(e, PRIME_P);
	bi_subtract(e, e, bi_one);
	bi_div3(e,e);
	bi_shift_right_one(e,e);
	fp2_exp(q, (const fp_t*) q2, e);			// qnr^{(p-1)/6}

	fp2_sqr(q2, (const fp_t*) q);
	fp2_mul(q3, (const fp_t*) q, (const fp_t*) q2);

	ecfp2_copy(res, a);	// TODO: extract i = 1 to save copy

	// map coefficients and multiply with the corresponding roots resulting from the
	// frobenius map in GFp12, i.e. untwist the curve, perform frobenius map, and twist again
	for (j = 0; j < i; j++) {
		fp2_frobenius_map(res->x, (const fp_t*) res->x, 1);
		fp2_mul(res->x, (const fp_t*) res->x, (const fp_t*) q2);

		fp2_frobenius_map(res->y, (const fp_t*) res->y, 1);
		fp2_mul(res->y, (const fp_t*) res->y, (const fp_t*) q3);
	}
}

/**
 * Compares two points of an elliptic curve group defined
 * over the quadratic extension of a prime field. Note that
 * the check for equality does merely check the absolute values
 * of the coordinates, i.e., it does not recognize equal projective
 * points in different representations.
 * @param a the first projective elliptic curve point
 * @param b the second projective elliptic curve point
 * @return 0 if equal, 1 otherwise
 */
int ecfp2_compare_std(ecfp2_proj_pt a, const ecfp2_proj_pt b) {
	return a->infinity != b->infinity ||
			bi_compare(a->x[0], b->x[0]) || bi_compare(a->x[1], b->x[1]) ||
			bi_compare(a->y[0], b->y[0]) || bi_compare(a->y[1], b->y[1]) ||
			bi_compare(a->z[0], b->z[0]) || bi_compare(a->z[1], b->z[1]);
}

/**
 * Hashes an integer to a point in the elliptic curve group
 * over the quadratic extension of a prime field.
 * @param res the resulting elliptic curve point
 * @param t the integer to be hashed
 */
void ecfp2_hash_to_point_std(ecfp2_pt res, const bigint_t t) {
	fp_t sqrtM3;
	fp2_t w, t0;
	fp2_t x[3];
	ecpoint_fp2 px;
	ecpoint_fp2_proj tp;

	// Firstly: Hash to a random point

	fp_dbl(sqrtM3, FP_ONE);
	fp_add(sqrtM3, sqrtM3, FP_ONE);
	fp_neg(sqrtM3, sqrtM3);
	fp_sqrt(sqrtM3, sqrtM3);		// sqrt(-3)

	fp_clear(w[1]);
	fp_sqr(w[0], t);
	fp_add(w[0], w[0], FP_ONE);

	fp_clear(t0[1]);				// calc b' of twisted curve
	fp_copy(t0[0], EC_PARAM_B);
	fp2_div_qnr(t0, (const fp_t*) t0);

	fp2_add(w, (const fp_t*) w, (const fp_t*) t0);
	fp2_inv(w, (const fp_t*) w);
	fp2_mulfp(w, (const fp_t*) w, sqrtM3);
	fp2_mulfp(w, (const fp_t*) w, (const word_t*) t);

	fp2_sqr(x[2], (const fp_t*) w);
	fp2_inv(x[2], (const fp_t*) x[2]);
	fp_add(x[2][0], x[2][0], FP_ONE);

	fp_clear(x[0][1]);
	fp_sub(x[0][0], sqrtM3, FP_ONE);
	fp2_hlv(x[0], (const fp_t*) x[0]);
	fp2_mulfp(w, (const fp_t*) w, (const word_t*) t);
	fp2_sub(x[0], (const fp_t*) x[0], (const fp_t*) w);

	fp_clear(x[1][1]);
	fp_neg(x[1][0], FP_ONE);
	fp2_sub(x[1], (const fp_t*) x[1], (const fp_t*) x[0]);

	// implementation without blinding (as suggested by Fouque, Tibouchi)
	fp2_sqr(w, (const fp_t*) x[0]);
	fp2_mul(w, (const fp_t*) w, (const fp_t*) x[0]);
	fp2_add(w, (const fp_t*) w, (const fp_t*) t0);			// t0 = b'

	int alpha = fp2_legendre((const fp_t*) w);

	fp2_sqr(w, (const fp_t*) x[1]);
	fp2_mul(w, (const fp_t*) w, (const fp_t*) x[1]);
	fp2_add(w, (const fp_t*) w, (const fp_t*) t0);

	int beta = fp2_legendre((const fp_t*) w);

	int idx = ((alpha-1)*beta % 3);
	if (idx < 0)
		idx+=3;

	res->infinity = 0;
	fp2_copy(res->x, (const fp_t*) x[idx]);
	fp2_sqr(w, (const fp_t*) x[idx]);
	fp2_mul(w, (const fp_t*) w, (const fp_t*) x[idx]);
	fp2_add(w, (const fp_t*) w, (const fp_t*) t0);
	fp2_sqrt(res->y, (const fp_t*) w);

	if (fp_legendre(t) == -1)
		fp2_neg(res->y, (const fp_t*) res->y);

	// Secondly: multiply by cofactor to have correct order

    ecfp2_mul(&px, res, EC_PARAM_X);
#ifdef NEGATIVE_PARAM_X
    ecfp2_neg_affine(&px);
#endif
    ecfp2_frobenius_map(res, res, 3);
    ecfp2_get_jacobian_projective(&tp, res);
    ecfp2_add_proj(&tp, &tp, &px);

    ecfp2_frobenius_map(res, &px, 2);
    ecfp2_add_proj(&tp, &tp, res);

    ecfp2_dbl_affine(res, &px);
    ecfp2_add_affine(res, res, &px);
    ecfp2_frobenius_map(res, res, 1);
    ecfp2_add_proj(&tp, &tp, res);

    ecfp2_get_affine_from_jacobian(res, &tp);
}

/**
 * Converts an elliptic curve point to the Montgomery domain.
 * @param res the resulting point in Montgomery domain
 * @param a the elliptic curve point to be converted
 */
void ecfp2_to_montgomery_std(ecfp2_pt res, const ecfp2_pt a) {
	res->infinity = a->infinity;
	fp2_to_montgomery(res->x, (const fp_t*) a->x);
	fp2_to_montgomery(res->y, (const fp_t*) a->y);
}

/**
 * Converts an elliptic curve point in Montgomery domain back.
 * @param res the resulting point in normal number format
 * @param a the elliptc curve point in Montgomery domain to be converted
 */
void ecfp2_from_montgomery_std(ecfp2_pt res, const ecfp2_pt a) {
	res->infinity = a->infinity;
	fp2_from_montgomery(res->x, (const fp_t*) a->x);
	fp2_from_montgomery(res->y, (const fp_t*) a->y);
}

/**
 * Generate random point.
 * To this end, we generate a random scalar (that is not known by
 * anyone) and multiply it with the base point.
 * @param res the randomly generated point.
 */
void ecfp2_rand_std(ecfp2_pt res) {
  bigint_t r;
    do {
      cprng_get_bytes(r, BI_BYTES); fp_rdc_n(r);
    } while (bi_compare(r, bi_zero) == 0);
  ecfp2_mul(res, (const ecfp2_pt) &ECFP2_GENERATOR, r);
}
