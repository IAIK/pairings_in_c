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
#include "fp/fp.h"
#include "bigint/bi.h"
#include "param.h"

void ecfp_add_dbl_coz_std(fp_t x1, fp_t x2, fp_t z, const fp_t x_d);
void ecfp_recover_full_coord_coz_std(fp_t x1, fp_t x2, fp_t z, const fp_t x_d, const fp_t y_d);
int ecfp_verify_coordinates(fp_t x, fp_t y);
int ecfp_verify_homogeneous_projective_coordinates(fp_t x, fp_t y, fp_t z);

/**
 * Adds two points of an elliptic curve group over a prime field using affine coordinates
 * via projective coordinates.
 * @param res the sum of the two points
 * @param a operand a
 * @param b operand b
 */
void ecfp_add_affine_std(ecfp_pt res, const ecfp_pt a, const ecfp_pt b) {
	ecpoint_fp_proj a_proj, res_proj;

	ecfp_get_jacobian_projective(&a_proj, a);
	ecfp_add_proj(&res_proj, &a_proj, b);
	ecfp_get_affine_from_jacobian(res, &res_proj);
}

/**
 * Adds two points of an elliptic curve group over a prime field using affine coordinates.
 * @param res  the sum of the two points
 * @param a operand a
 * @param b operand b
 */
void ecfp_add_affine_direct_std(ecfp_pt res, const ecfp_pt a, const ecfp_pt b) {
	fp_t t0, t1, t2;

	if (a->infinity && !b->infinity) {
		fp_copy(res->x, b->x);
		fp_copy(res->y, b->y);
		res->infinity = 0;
		return;
	} else if (!a->infinity && b->infinity) {
		fp_copy(res->x, a->x);
		fp_copy(res->y, a->y);
		res->infinity = 0;
		return;
	} else if (a->infinity && b->infinity) {
		res->infinity = 1;
		return;
	}

	if (bi_compare(a->x, b->x) == 0) {
		if (bi_compare(a->y, b->y) == 0) {
			ecfp_dbl_affine(res, a);
		} else {
			res->infinity = 1;
		}
		return;
	} else {
		res->infinity = 0;
	}


	fp_sub(t0, b->x, a->x);
	fp_sub(t1, b->y, a->y);
	fp_inv(t0, t0);
	fp_mul(t2, t1, t0);
	fp_sqr(t0, t2);

	fp_sub(t0, t0, a->x);
	fp_sub(t0, t0, b->x);

	fp_sub(t1, a->x, t0);
	fp_mul(res->x, t1, t2);
	fp_sub(res->y, res->x, a->y);

	fp_copy(res->x, t0);
}

#if 0
/**
 * Adds two points of an elliptic curve group over a prime field using mixed affine and projective coordinates.
 * @param res the projective result
 * @param a the projective point operand
 * @param b the affine point operand
 */
void ecfp_add_proj_std(ecfp_proj_pt res, const ecfp_proj_pt a, const ecfp_pt b) {
	// calculation based on jacobian coordinates
	// b in projective coordinates is (b->x, b->y, 1)

	if (a->infinity && !b->infinity) {	// P + Infinity = P
		fp_copy(res->x, b->x);
		fp_copy(res->y, b->y);
		fp_copy(res->z, FP_ONE);
		res->infinity = 0;
		return;
	} else if (!a->infinity && b->infinity) {
		fp_copy(res->x, a->x);
		fp_copy(res->y, a->y);
		fp_copy(res->z, FP_ONE);
		res->infinity = 0;
		return;
	} else if (a->infinity && b->infinity) {
		res->infinity = 1;
		return;
	}

	fp_t t0, t1, t2, t3, t5;

	fp_sqr(t0, a->z);			  // t0 = z²
	fp_mul(t1, t0, a->z);		// t1 = z³

	fp_mul(t2, t0, b->x);		// t2 = b->x*z²
	fp_sub(t0, t2, a->x);		// t0 = b->x*z² - a->x

	fp_mul(t5, t1, b->y);		// t5 = b->y*z³ - a->y
	fp_sub(t5, t5, a->y);

	if (bi_compare(t0, bi_zero) == 0) {
		if (bi_compare(t5, bi_zero) == 0) {	// point a is equal to point b (doubling!)
			ecfp_dbl_proj(res, a);
		} else {					                  // otherwise its point (1,1,0) -> infinity
			res->infinity = 1;
		}
		return;
	} else {
		res->infinity = 0;
	}

	fp_mul(t3, t0, a->z);	  // res->z = (b->x*z² - a->x) * a->z
	fp_copy(res->z, t3);

	fp_add(t2, t2, a->x);		// t2 = b->x * z² + a->x
	fp_sqr(t3, t0);				  // t3 = (b->x*z² - a->x)²
	fp_mul(t1, t2, t3);			// t1 = (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp_mul(t2, t0, t3);			// t2 = (b->x*z² - a->x)³
	fp_mul(t0, t2, a->y);		// t0 = a->y * (b->x*z² - a->x)³
	fp_mul(t2, t3, a->x);		// t2 = a->x * (b->x*z² - a->x)²

	fp_sqr(res->x, t5);			    // res->x = (b->y*z³ - a->y)²
	fp_sub(res->x, res->x, t1);	// res->x = (b->y*z³ - a->y)² -
	                            // (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp_sub(t2, t2, res->x);		  //	a->x * (b->x*z² - a->x)² - res->x
	fp_mul(t3, t2, t5);
	fp_sub(res->y, t3, t0);     // (b->y*z³ - a->y)(a->x * (b->x*z² - a->x)² - res->x) -
	                            // a->y * (b->x*z² - a->x)³
}
#else

/**
 * Adds two points of an elliptic curve group over a prime field using mixed affine and projective coordinates.
 * @param res the projective result
 * @param a the projective point operand
 * @param b the affine point operand
 */
void ecfp_add_proj_std(ecfp_proj_pt res, const ecfp_proj_pt a, const ecfp_pt b) {
	// calculation based on jacobian coordinates
	// b in projective coordinates is (b->x, b->y, 1)

	if (a->infinity && !b->infinity) {	// P + Infinity = P
		fp_copy(res->x, b->x);
		fp_copy(res->y, b->y);
		fp_copy(res->z, FP_ONE);
		res->infinity = 0;
		return;
	} else if (!a->infinity && b->infinity) {
		fp_copy(res->x, a->x);
		fp_copy(res->y, a->y);
		fp_copy(res->z, FP_ONE);
		res->infinity = 0;
		return;
	} else if (a->infinity && b->infinity) {
		res->infinity = 1;
		return;
	}

	fp_t t0, t1, t2, t3;

	fp_sqr(t0, a->z);			  // t0 = z²
	fp_mul(t1, t0, a->z);		// t1 = z³

	fp_mul(t2, t0, b->x);		// t2 = b->x*z²
	fp_sub(t0, t2, a->x);		// t0 = b->x*z² - a->x

	fp_mul(t1, t1, b->y);
	fp_sub(t1, t1, a->y);		// t1 = b->y*z³ - a->y

	if (bi_compare(t0, bi_zero) == 0) {
		if (bi_compare(t1, bi_zero) == 0) {	// point a is equal to point b (doubling!)
			ecfp_dbl_proj(res, a);
		} else {					                  // otherwise its point (1,1,0) -> infinity
			res->infinity = 1;
		}
		return;
	} else {
		res->infinity = 0;
	}

	fp_mul(res->z, t0, a->z);	// res->z = (b->x*z² - a->x) * a->z

	fp_add(t2, t2, a->x);		  // t2 = b->x * z² + a->x
	fp_sqr(t3, t0);			      // t3 = (b->x*z² - a->x)²
	fp_mul(t2, t2, t3);       // t2 = (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp_mul(t0, t0, t3);		    // t0 = (b->x*z² - a->x)³
	fp_mul(t0, t0, a->y);		  // t0 = a->y * (b->x*z² - a->x)³
	fp_mul(t3, t3, a->x);		  // t3 = a->x * (b->x*z² - a->x)²

	fp_sqr(res->x, t1);			    // res->x = (b->y*z³ - a->y)²
	fp_sub(res->x, res->x, t2);	// res->x = (b->y*z³ - a->y)² -
	                            // (b->x*z² - a->x)² * (b->x * z² + a->x)
	fp_sub(t3, t3, res->x);     //	a->x * (b->x*z² - a->x)² - res->x
	fp_mul(t3, t3, t1);
	fp_sub(res->y, t3, t0);     // (b->y*z³ - a->y)(a->x * (b->x*z² - a->x)² - res->x) -
	                            // a->y * (b->x*z² - a->x)³
}
#endif

/**
 * Calculates the double of a point of an elliptic curve group over a prime field
 * using affine coordinates via projective coordinates.
 * @param res the result
 * @param a the point operand
 */
void ecfp_dbl_affine_std(ecfp_pt res, const ecfp_pt a) {
	ecpoint_fp_proj a_proj, res_proj;

	ecfp_get_jacobian_projective(&a_proj, a);
	ecfp_dbl_proj(&res_proj, &a_proj);
	ecfp_get_affine_from_jacobian(res, &res_proj);
}

/**
 * Calculates the double of a point of an elliptic curve group over a prime field
 * using affine coordinates.
 * @param res the result
 * @param a the point operand
 */
void ecfp_dbl_affine_direct_std(ecfp_pt res, const ecfp_pt a) {
	fp_t t0, t1, t2;

	if (a->infinity) {
		res->infinity = 1;
		return;
	}

	fp_sqr(t0, a->x);
	fp_dbl(t1, t0);
	fp_add(t0, t0, t1);
#ifndef OPTIMIZE_ZERO_A
	fp_add(t0, t0, EC_PARAM_A);
#endif

	fp_dbl(t1, a->y);
	fp_inv(t1, t1);
	fp_mul(t2, t1, t0);

	fp_sqr(t0, t2);
	fp_sub(t0, t0, a->x);
	fp_sub(t0, t0, a->x);

	fp_sub(t1, a->x, t0);
	fp_mul(res->x, t1, t2);
	fp_sub(res->y, res->x, a->y);

	fp_copy(res->x, t0);
}

#if 0
/**
 * Calculates the double of a point of an elliptic curve group over a prime field
 * using projective coordinates.
 * @param res the projective result
 * @param a the projective point operand
 */
void ecfp_dbl_proj_std(ecfp_proj_pt res, const ecfp_proj_pt a) {
	// calculation based on jacobian coordinates

	if (a->infinity) {
		res->infinity = 1;
		return;
	} else {
		res->infinity = 0;
	}

	fp_t t0, t1, t2, t3;

	fp_sqr(t0, a->x);

#ifdef OPTIMIZE_ZERO_A
	fp_dbl(t1, t0);
	fp_add(t1, t1, t0);			    // t1 = 3x²
#else
	fp_sqr(t1, a->z);
	fp_sqr(t3, t1);				      // t1 = z⁴
	fp_mul(t1, t3, EC_PARAM_A);	// t1 = a*z⁴

	fp_add(t1, t1, t0);
	fp_add(t1, t1, t0);
	fp_add(t1, t1, t0);			    // t1 = a*z⁴ + 3x²
#endif

	fp_dbl(t0, a->y);			      // t0 = 2 * y
	fp_mul(t3, t0, a->z);
	fp_copy(res->z, t3);    		// res->z = 2*y*z

	fp_sqr(t3, t0);				      // t3 = 4 * y²
	fp_mul(t2, t3, a->x);		    // t2 = 4*x*y²

	fp_copy(res->y, t1);	    	// res->y = (3x² + az⁴)
	fp_dbl(t1, t2);			      	// t1 = 8*x*y²

	fp_sqr(res->x, res->y);	   	// res->x = (3x² + az⁴)²
	fp_sub(res->x, res->x, t1);	// res->x = (3x² + az⁴)² - 8*x*y²

	fp_sub(t2, t2, res->x);		  // 4xy² - res->x
	fp_mul(t0, res->y, t2);    	// t0 = (3x² + az⁴)(4xy² - res->x)

	fp_sqr(t1, t3);
	fp_hlv(t3, t1);				      // t3 = 8 * y⁴

	fp_sub(res->y, t0, t3);		  // res->y = (3x² + az⁴)(4xy² - res->x) - 8y⁴
}
#else
/**
 * Calculates the double of a point of an elliptic curve group over a prime field
 * using projective coordinates.
 * @param res the projective result
 * @param a the projective point operand
 */
void ecfp_dbl_proj_std(ecfp_proj_pt res, ecfp_proj_pt a) {
	// calculation based on jacobian coordinates

	if (a->infinity) {
		res->infinity = 1;
		return;
	} else {
		res->infinity = 0;
	}

	fp_t t0, t1, t2;

	fp_sqr(t0, a->x);

#ifdef OPTIMIZE_ZERO_A
	fp_dbl(t1, t0);
	fp_add(t1, t1, t0);		     	// t1 = 3x²
#else
	fp_sqr(t1, a->z);
	fp_sqr(t1, t1);			       	// t1 = z⁴
	fp_mul(t1, t1, EC_PARAM_A);	// t1 = a*z⁴

	fp_add(t1, t1, t0);
	fp_add(t1, t1, t0);
	fp_add(t1, t1, t0);		     	// t1 = a*z⁴ + 3x²
#endif

	fp_dbl(t0, a->y);			      // t0 = 2 * y
	fp_mul(res->z, t0, a->z);	  // res->z = 2*y*z

	fp_sqr(t0, t0);	        		// t0 = 4 * y²
	fp_mul(t2, t0, a->x);		    // t2 = 4*x*y²

	fp_copy(res->y, t1);				// res->y = (3x² + az⁴)
	fp_dbl(t1, t2);			        // t1 = 8*x*y²

	fp_sqr(res->x, res->y);		  // res->x = (3x² + az⁴)²
	fp_sub(res->x, res->x, t1); // res->x = (3x² + az⁴)² - 8*x*y²

	fp_sub(t2, t2, res->x);		  // 4xy² - res->x
	fp_mul(res->y, res->y, t2); // res->y = (3x² + az⁴)(4xy² - res->x)

	fp_sqr(t0, t0);
	fp_hlv(t0, t0);			        // t0 = 8 * y⁴

	fp_sub(res->y, res->y, t0); // res->y = (3x² + az⁴)(4xy² - res->x) - 8y⁴
}
#endif

/**
 * Performs a left-to-right binary elliptic curve point multiplication
 * @param res the resulting product
 * @param a the point operand
 * @param k the scalar operand
 */
void ecfp_mul_l2rb_std(ecfp_pt res, const ecfp_pt a, const fp_t k) {
	// plain left-to-right binary multiplication
	int msb = bi_get_msb(k);
	int i;

	ecpoint_fp_proj r, tmp;
	r.infinity = 1;

	for (i = msb; i >= 0; i--) {
		ecfp_dbl_proj(&r, &r);
		if (bi_test_bit(k, i)) {
			ecfp_add_proj(&r, &r, a);
		} else {
			ecfp_add_proj(&tmp, &r, a);
		}
	}

	ecfp_get_affine_from_jacobian(res, &r);
}

int ecfp_verify_coordinates(fp_t x, fp_t y)  {
	// y² = x^3 + ax + b
	fp_t r0, r1;

	fp_sqr(r1, x);
	fp_mul(r1, r1, x);

#ifndef OPTIMIZE_ZERO_A
	fp_mul(r0, EC_PARAM_A, x);
	fp_add(r1, r1, r0);
#endif

	fp_add(r1, r1, EC_PARAM_B);
	fp_sqr(r0, y);

	return bi_compare(r0, r1);
}

int ecfp_verify_homogeneous_projective_coordinates(fp_t x, fp_t y, fp_t z) {
	// Y^2 Z = X^3 + a X Z^2 + b Z^3

	fp_t r0, r1, r2;

	fp_sqr(r1, x);
	fp_mul(r1, r1, x);

	fp_sqr(r2, z);
#ifndef OPTIMIZE_ZERO_A
	fp_mul(r0, EC_PARAM_A, x);
	fp_mul(r0, r0, r2);
	fp_add(r1, r1, r0);
#endif

	fp_mul(r0, r2, z);
	fp_mul(r0, r0, EC_PARAM_B);
	fp_add(r1, r1, r0);

	fp_sqr(r0, y);
	fp_mul(r0, r0, z);


	return bi_compare(r0, r1);
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
void ecfp_add_dbl_coz_std(fp_t x1, fp_t x2, fp_t z, const fp_t x_d) {
	/// Algorithm 5 from "Memory-Constrained Implementations of Elliptic Curve Cryptography in Co-Z
	/// Coordinate Representation", Hutter et. al.

	fp_t r1, r2, r3, r4, r5;

	fp_sqr(r2, z);

#ifndef OPTIMIZE_ZERO_A

	fp_mul(r3, EC_PARAM_A, r2);

#endif

	fp_mul(r1, z, r2);

#ifdef USE_PREDEFINED_4B
	fp_mul(r2, EC_PARAM_4B, r1);
#else
	fp_dbl(r2, EC_PARAM_B);
	fp_dbl(r2, r2);
	fp_mul(r2, r2, r1);
#endif

	fp_sqr(r1, x2);

#ifdef OPTIMIZE_ZERO_A

	fp_sqr(r4, r1);

#else

	fp_sub(r5, r1, r3);
	fp_sqr(r4, r5);
	fp_add(r1, r1, r3);

#endif

	fp_mul(r5, x2, r1);

	fp_dbl(r5, r5);
	fp_dbl(r5, r5);
	fp_add(r5, r5, r2);

#ifndef OPTIMIZE_ZERO_A

	fp_add(r1, r1, r3);

#endif

	fp_sqr(r3, x1);
	fp_add(r1, r1, r3);

	fp_sub(x1, x1, x2);
	fp_dbl(x2, x2);
	fp_mul(r3, x2, r2);

	fp_sub(r4, r4, r3);
	fp_sqr(r3, x1);

	fp_sub(r1, r1, r3);
	fp_add(x1, x1, x2);
	fp_mul(x2, x1, r1);

	fp_add(x2, x2, r2);
	fp_mul(r2, z, r3);

	fp_mul(z, x_d, r2);
	fp_sub(x2, x2, z);
	fp_mul(x1, r5, x2);
	fp_mul(x2, r3, r4);
	fp_mul(z, r2, r5);
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
void ecfp_recover_full_coord_coz_std(fp_t x1, fp_t x2, fp_t z, const fp_t x_d, const fp_t y_d) {
	/// Algorithm 7 from "Memory-Constrained Implementations of Elliptic Curve Cryptography in Co-Z
	/// Coordinate Representation", Hutter et. al.

	fp_t r1, r2, r3, r4;

	fp_mul(r1, x_d, z);
	fp_sub(r2, x1, r1);
	fp_sqr(r3, r2);

	fp_mul(r4, r3, x2);
	fp_mul(r2, r1, x1);
	fp_add(r1, x1, r1);
	fp_sqr(x2, z);

#ifndef OPTIMIZE_ZERO_A
	fp_mul(r3, EC_PARAM_A, x2);
	fp_add(r2, r2, r3);
#endif

	fp_mul(r3, r2, r1);
	fp_sub(r3, r3, r4);
	fp_dbl(r3, r3);
	fp_dbl(r1, y_d);
	fp_dbl(r1, r1);

	fp_mul(r2, r1, x1);
	fp_mul(x1, r2, x2);
	fp_mul(r2, x2, z);
	fp_mul(z, r2, r1);

#ifdef USE_PREDEFINED_4B
	fp_mul(r4, EC_PARAM_4B, r2);
#else
	fp_dbl(r4, EC_PARAM_B);
	fp_dbl(r4, r4);
	fp_mul(r4, r4, r2);
#endif

	fp_add(x2, r4, r3);
}

/**
 * Elliptic curve point multiplication using a Montgomery ladder with co-Z coordinates.
 * @param res the resulting product
 * @param a the point operand
 * @param k the scalar operand
 */
void ecfp_mul_montyladder_std(ecfp_pt res, const ecfp_pt a, const fp_t k) {
	int msb = bi_get_msb(k);
	int i;
	fp_t x1, x2, z;
	word_t *x[2];
	word_t bit;

	x[0] = x1;
	x[1] = x2;

	if (ecfp_verify_coordinates(a->x, a->y))
		return;

	cprng_get_bytes(z, FP_BYTES);
#ifndef REAL_LAZY_REDUCTION
	fp_rdc(z);
#endif
	fp_mul(x[1], a->x, z);
	fp_mul(x[0], a->y, z);

	if (ecfp_verify_homogeneous_projective_coordinates(x[1], x[0], z))
		return;

	fp_copy(x[0], bi_zero);

	ecfp_add_dbl_coz_std(x1, x2, z, a->x);

	fp_mul(x1, a->x, z);

	for (i = msb - 1; i >= 0; i--) {
		bit = bi_test_bit(k, i);
		ecfp_add_dbl_coz_std(x[~bit & 1], x[bit], z, a->x);
	}

	ecfp_recover_full_coord_coz_std(x[0], x[1], z, a->x, a->y);

	if (ecfp_verify_homogeneous_projective_coordinates(x[0], x[1], z))
		return;

	fp_inv(z, z);
	fp_mul(res->x, x[0], z);
	fp_mul(res->y, x[1], z);
	res->infinity = 0;

	if (ecfp_verify_coordinates(res->x, res->y))
		return;
}

/**
 * Converts an elliptic curve point in affine coordinates to
 * an elliptic curve point in projective coordinates.
 * @param projective the resulting projective elliptic curve point
 * @param affine the input affine elliptic curve point
 */
void ecfp_get_projective_std(ecfp_proj_pt projective, const ecfp_pt affine) {
 	projective->infinity = affine->infinity;

 	if (affine->infinity)
 		return;

 	fp_copy(projective->x, affine->x);
 	fp_copy(projective->y, affine->y);
 	fp_copy(projective->z, FP_ONE);
 }

 /**
  * Converts an elliptic curve point in affine coordinates to
  * an elliptic curve point in randomized jacobian projective coordinates.
  * @param projective the resulting randomized projective elliptic curve point
  * @param affine the input affine elliptic curve point
  */
 void ecfp_get_jacobian_projective_rnd_std(ecfp_proj_pt projective, const ecfp_pt affine) {
	projective->infinity = affine->infinity;

	if (affine->infinity)
		return;

	// get random value for z and reduce modulo prime
	cprng_get_bytes(projective->z, FP_BYTES);

#ifndef REAL_LAZY_REDUCTION
	fp_rdc(projective->z);
#endif

	fp_t z2;
	fp_sqr(z2, projective->z);

	// adapt x and y coordinates appropriately
	fp_mul(projective->x, affine->x, z2);
	fp_mul(projective->y, affine->y, projective->z);
	fp_mul(projective->y, projective->y, z2);
  }

 /**
  * Converts an elliptic curve point in jacobian projective coordinates to
  * an elliptic curve point in affine coordinates.
  * @param affine the resulting affine elliptic curve point
  * @param projective the input projective elliptic curve point
  */
void ecfp_get_affine_from_jacobian_std(ecfp_pt affine, const ecfp_proj_pt projective) {
 	affine->infinity = projective->infinity;
 	if (projective->infinity)
 		return;

 	fp_t t, z;

 	fp_inv(t, projective->z);
 	fp_sqr(affine->y, t);
 	fp_mul(affine->x, affine->y, projective->x);
 	fp_mul(z, t, affine->y);					// using this extra var allows it to be used for montgomery domain as well
 	fp_mul(affine->y, z, projective->y);
 }

/**
 * Negates an elliptic curve point in affine coordinates, i.e. computes -P.
 * @param a the elliptic curve point (input and result)
 */
void ecfp_neg_affine_std(ecfp_pt a) {
	fp_neg(a->y, a->y);
}

/**
 * Negates an elliptic curve point in projective coordinates, i.e. computes -P.
 * @param a the elliptic curve point (input and result)
 */
void ecfp_neg_proj_std(ecfp_proj_pt a) {
	fp_neg(a->y, a->y);
}

/**
 * Copies a point of an elliptic curve group over a prime field.
 * @param res the resulting copy
 * @param a the affine input point to be copied
 */
void ecfp_copy_std(ecfp_pt res, const ecfp_pt a) {
	fp_copy(res->x, a->x);
	fp_copy(res->y, a->y);
	res->infinity = a->infinity;
}

/**
 * Clears a point of an elliptic curve group over a prime field.
 * @param a the elliptic curve point in affine coordinates
 */
void ecfp_clear_std(ecfp_pt a) {
	fp_clear(a->x);
	fp_clear(a->y);
	a->infinity = 0;
}

#if 0
/**
 * Hashes an integer to a point in an elliptic curve group over a prime field.
 * @param res the resulting elliptic curve point
 * @param t the integer to be hashed
 */
void ecfp_hash_to_point_std(ecfp_pt res, const bigint_t t) {
	fp_t t0, w, v;
	fp_t x[3];

	fp_dbl(t0, FP_ONE);
	fp_add(t0, t0, FP_ONE);
	fp_neg(t0, t0);
	fp_sqrt(t0, t0);		// sqrt(-3)

	fp_sqr(w, t);
	fp_add(w, w, FP_ONE);
	fp_add(w, w, EC_PARAM_B);
	fp_inv(w, w);
	fp_mul(v, w, t0);
	fp_mul(w, v, t);

	fp_sqr(x[2], w);
	fp_inv(x[2], x[2]);
	fp_add(x[2], x[2], FP_ONE);

	fp_sub(x[0], t0, FP_ONE);
	fp_hlv(x[0], x[0]);
	fp_mul(v, w, t);
	fp_sub(x[0], x[0], v);

	fp_neg(x[1], FP_ONE);
	fp_sub(x[1], x[1], x[0]);

	// implementation without blinding (as suggested by Fouque, Tibouchi)
	fp_sqr(t0, x[0]);
	fp_mul(t0, t0, x[0]);
	fp_add(t0, t0, EC_PARAM_B);

	fp_sqr(v, x[1]);
	fp_mul(w, v, x[1]);
	fp_add(w, w, EC_PARAM_B);

	// use the same exponentiations
	int alpha = fp_legendre(t0);
	int beta = fp_legendre(w);

	int idx = ((alpha-1)*beta % 3);
	if (idx < 0)
		idx+=3;

	res->infinity = 0;
	fp_copy(res->x, x[idx]);

	fp_sqr(v, x[idx]);
	fp_mul(t0, v, x[idx]);
	fp_add(t0, t0, EC_PARAM_B);
	fp_sqrt(res->y, t0);

	if (fp_legendre(t) == -1)
		fp_neg(res->y, res->y);
}
#else
/**
 * Hashes an integer to a point in an elliptic curve group over a prime field.
 * @param res the resulting elliptic curve point
 * @param t the integer to be hashed
 */
void ecfp_hash_to_point_std(ecfp_pt res, const bigint_t t) {
	fp_t t0, w;
	fp_t x[3];

	fp_dbl(t0, FP_ONE);
	fp_add(t0, t0, FP_ONE);
	fp_neg(t0, t0);
	fp_sqrt(t0, t0);		// sqrt(-3)

	fp_sqr(w, t);
	fp_add(w, w, FP_ONE);
	fp_add(w, w, EC_PARAM_B);
	fp_inv(w, w);
	fp_mul(w, w, t0);
	fp_mul(w, w, t);

	fp_sqr(x[2], w);
	fp_inv(x[2], x[2]);
	fp_add(x[2], x[2], FP_ONE);

	fp_sub(x[0], t0, FP_ONE);
	fp_hlv(x[0], x[0]);
	fp_mul(w, w, t);
	fp_sub(x[0], x[0], w);

	fp_neg(x[1], FP_ONE);
	fp_sub(x[1], x[1], x[0]);

	// implementation without blinding (as suggested by Fouque, Tibouchi)
	fp_sqr(t0, x[0]);
	fp_mul(t0, t0, x[0]);
	fp_add(t0, t0, EC_PARAM_B);

	fp_sqr(w, x[1]);
	fp_mul(w, w, x[1]);
	fp_add(w, w, EC_PARAM_B);

	// use the same exponentiations
	int alpha = fp_legendre(t0);
	int beta = fp_legendre(w);

	int idx = ((alpha-1)*beta % 3);
	if (idx < 0)
		idx+=3;

	res->infinity = 0;
	fp_copy(res->x, x[idx]);

	fp_sqr(t0, x[idx]);
	fp_mul(t0, t0, x[idx]);
	fp_add(t0, t0, EC_PARAM_B);
	fp_sqrt(res->y, t0);

	if (fp_legendre(t) == -1)
		fp_neg(res->y, res->y);
}
#endif

/**
 * Converts an elliptic curve point to the Montgomery domain.
 * @param res the resulting point in Montgomery domain
 * @param a the elliptic curve point to be converted
 */
void ecfp_to_montgomery_std(ecfp_pt res, const ecfp_pt a) {
	res->infinity = a->infinity;
	fp_to_montgomery(res->x, a->x);
	fp_to_montgomery(res->y, a->y);
}

/**
 * Converts an elliptic curve point in Montgomery domain back.
 * @param res the resulting point in normal number format
 * @param a the elliptc curve point in Montgomery domain to be converted
 */
void ecfp_from_montgomery_std(ecfp_pt res, const ecfp_pt a) {
	res->infinity = a->infinity;
	fp_from_montgomery(res->x, a->x);
	fp_from_montgomery(res->y, a->y);
}

/**
 * Generates a random elliptic curve point.
 * To this end, we generate a random scalar (that is not known by
 * anyone) and multiply it with the base point.
 * @param res     [out] the random point.
 */
void ecfp_rand_std(ecfp_pt res) {
  bigint_t r;
  do {
    cprng_get_bytes(r, BI_BYTES); fp_rdc_n(r);
  } while (bi_compare(r, bi_zero) == 0);

  ecfp_mul(res, (const ecfp_pt)&ECFP_GENERATOR, r);
}
