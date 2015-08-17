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
#include "fp/fp.h"
#include "fp/fp2.h"
#include "fp/fp12.h"
#include "pbc/pbc.h"
#include "ec/ec.h"
#include "param.h"

/**
 * Evaluation of the line function.
 * @param res the result of the line function evaluation
 * @param a the starting point of the line
 * @param b the ending point of the line
 * @param p the point necessary for evaluation
 */
void pbc_eval_line_function(fp12_t res, ecfp2_proj_pt a, ecfp2_pt b, ecfp_pt p) {
	if (a->infinity || b->infinity || p->infinity) {
		fp12_clear(res);
		res[0][0][0][0] = 1;
	} else {
		fp2_t n, d;
		fp2_t az3, t;

		fp2_sqr(az3, (const fp_t*) a->z);
		fp2_mul(az3, (const fp_t*) az3, (const fp_t*) a->z);

		// calculate slope of line between a and b
		fp2_mul(d, (const fp_t*) b->x, (const fp_t*) az3);
		fp2_mul(n, (const fp_t*) a->x, (const fp_t*) a->z);
		fp2_sub(d, (const fp_t*) d, (const fp_t*) n);

		fp2_mul(n, (const fp_t*) b->y, (const fp_t*) az3);
		fp2_sub(n, (const fp_t*) n, (const fp_t*) a->y);

		fp_clear(t[1]);
		fp_copy(t[0], p->y);
		fp2_neg(t, (const fp_t*) t);
		fp2_mul(res[0][0], (const fp_t*) d, (const fp_t*) t);
		fp2_mul(res[0][0], (const fp_t*) res[0][0], (const fp_t*) az3);

		fp_copy(t[0], p->x);
		fp2_mul(res[1][0], (const fp_t*) t, (const fp_t*) n);
		fp2_mul(res[1][0], (const fp_t*) res[1][0], (const fp_t*) az3);

		fp2_mul(t, (const fp_t*) a->x, (const fp_t*) n);
		fp2_mul(t, (const fp_t*) t, (const fp_t*) a->z);
		fp2_mul(res[0][1], (const fp_t*) d,(const fp_t*)  a->y);
		fp2_sub(res[0][1], (const fp_t*) res[0][1], (const fp_t*) t);
	}
}

/**
 * Evaluation of the tangent line function.
 * @param res the result of the line function evaluation
 * @param a the point in which the tangent line is placed
 * @param p the point necessary for evaluation
 */
void pbc_eval_tangent_function(fp12_t res, ecfp2_proj_pt a, ecfp_pt p) {
	if (a->infinity || p->infinity) {
		fp12_clear(res);
		res[0][0][0][0] = 1;
	} else {
		fp2_t n, d;
		fp2_t az3, t;

		fp2_sqr(az3, (const fp_t*) a->z);
		fp2_mul(az3, (const fp_t*) az3, (const fp_t*) a->z);

		// calculating tangent slope
		fp2_sqr(n, (const fp_t*) a->x);
		fp2_dbl(d, (const fp_t*) n);
		fp2_add(n, (const fp_t*) n, (const fp_t*) d);

		fp2_dbl(d, (const fp_t*) a->y);
		fp2_mul(d, (const fp_t*) d, (const fp_t*) a->z);

		fp_clear(t[1]);
		fp_copy(t[0], p->y);
		fp2_neg(t, (const fp_t*) t);
		fp2_mul(res[0][0], (const fp_t*) d, (const fp_t*) t);
		fp2_mul(res[0][0], (const fp_t*) res[0][0], (const fp_t*) az3);

		fp_copy(t[0], p->x);
		fp2_mul(res[1][0], (const fp_t*) t, (const fp_t*) n);
		fp2_mul(res[1][0], (const fp_t*) res[1][0], (const fp_t*) az3);

		fp2_mul(t, (const fp_t*) a->x, (const fp_t*) n);
		fp2_mul(t, (const fp_t*) t, (const fp_t*) a->z);
		fp2_mul(res[0][1], (const fp_t*) d, (const fp_t*) a->y);
		fp2_sub(res[0][1], (const fp_t*) res[0][1], (const fp_t*) t);
	}
}

/**
 * Optimal Ate Pairing over BN curves.
 * WARNING: old implementation with less efficient formulas.
 * Pairing is E(F_p) x E'(F_p2) -> F_p12
 * E' denotes the sextic twist of the curve E
 */
void pbc_map_opt_ate_std(fp12_t res, ecfp_pt p, ecfp2_pt q) {
	ecpoint_fp2_proj 	t;
	ecpoint_fp2			q1;
	word_t				e[2*BI_WORDS];
	fp12_t				tmp, v0, f1, f2, f3;
	int len, i;

	// Actually, the pairing over BN curves is defined as
	// E(F_p) x E'(F_p12) -> F_p12
	// but there is an efficient isomorphism from E(F_p2) to E(F_p12)

	ecfp2_get_homogeneous_projective(&t, q);
	fp12_clear(res); res[0][0][0][0] = 1;
	fp12_clear(tmp);

#ifdef OPT_ATE_LOOP_CONSTANT
	const word_t	*s 			= OPTATE_LOOP_CONST;
#else
	word_t				s[BI_WORDS+1];
	bi_multiply_word(s, EC_PARAM_X, 6);
	bi_add_word(s, s, 2);
#endif

	len = bi_get_msb(s);

	if (!p->infinity && !q->infinity) {
		// len is the msb -> -1 instead of -2
		for (i = len - 1; i >= 0; i--) {
			fp12_sqr(res, (const fp4_t*) res);
			pbc_eval_tangent_function(tmp, &t, p);
			fp12_mul(res, (const fp4_t*) res, (const fp4_t*) tmp);

			ecfp2_dbl_proj(&t, &t);

			if (bi_test_bit(s, i)) {
				pbc_eval_line_function(tmp, &t, q, p);
				fp12_mul(res, (const fp4_t*) res, (const fp4_t*) tmp);

				ecfp2_add_proj(&t, &t, q);
			}
		}
	}

	ecfp2_frobenius_map(&q1, q, 1);
	pbc_eval_line_function(tmp, &t, &q1, p);
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) tmp);
	ecfp2_add_proj(&t, &t, &q1);

	ecfp2_frobenius_map(&q1, &q1, 1);
	ecfp2_neg_affine(&q1);
	pbc_eval_line_function(tmp, &t, &q1, p);
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) tmp);

	// Final exponentiation:

	// easy part
	fp12_inv(tmp, (const fp4_t*) res);
	fp12_frobenius_map(res, (const fp4_t*)res, 6);	          // res^{p^6}
	fp12_mul(res, (const fp4_t*)res, (const fp4_t*)tmp);			// res^{p^6 - 1}
	fp12_frobenius_map(tmp, (const fp4_t*)res, 2);
	fp12_mul(res, (const fp4_t*)res, (const fp4_t*)tmp);			// res^{(p^6-1)(p^2+1}


	fp12_t ft1, ft2, ft3;
	fp12_t fp1, fp2, fp3;

	fp12_t y0, y1, y2, y3, y4, y5, y6;
	fp12_t t0, t1;

	fp12_exp(ft1, (const fp4_t*)res, EC_PARAM_X);
	fp12_exp(ft2, (const fp4_t*)ft1, EC_PARAM_X);
	fp12_exp(ft3, (const fp4_t*)ft2, EC_PARAM_X);

	fp12_frobenius_map(fp1, (const fp4_t*)res, 1);
	fp12_frobenius_map(fp2, (const fp4_t*)fp1, 1);
	fp12_frobenius_map(fp3, (const fp4_t*)fp2, 1);

	fp12_mul(y0, (const fp4_t*)fp1, (const fp4_t*)fp2);
	fp12_mul(y0, (const fp4_t*)y0, (const fp4_t*)fp3);

	fp12_frobenius_map(y1, (const fp4_t*)res, 6);
	fp12_frobenius_map(y2, (const fp4_t*)ft2, 2);
	fp12_frobenius_map(y3, (const fp4_t*)ft1, 1);
	fp12_frobenius_map(y3, (const fp4_t*)y3, 6);
	fp12_frobenius_map(y4, (const fp4_t*)ft2, 1);
	fp12_mul(y4, (const fp4_t*)y4, (const fp4_t*)ft1);
	fp12_frobenius_map(y4, (const fp4_t*)y4, 6);
	fp12_frobenius_map(y5, (const fp4_t*)ft2, 6);
	fp12_frobenius_map(y6, (const fp4_t*)ft3, 1);
	fp12_mul(y6, (const fp4_t*)y6, (const fp4_t*)ft3);
	fp12_frobenius_map(y6, (const fp4_t*)y6, 6);

	fp12_sqr(t0, (const fp4_t*)y6);
	fp12_mul(t0, (const fp4_t*)t0, (const fp4_t*)y4);
	fp12_mul(t0, (const fp4_t*)t0, (const fp4_t*)y5);

	fp12_mul(t1, (const fp4_t*) y3, (const fp4_t*) y5);
	fp12_mul(t1, (const fp4_t*) t1, (const fp4_t*) t0);

	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) y2);

	fp12_sqr(t1, (const fp4_t*) t1);
	fp12_mul(t1, (const fp4_t*) t1, (const fp4_t*) t0);
	fp12_sqr(t1, (const fp4_t*) t1);

	fp12_mul(t0, (const fp4_t*) t1, (const fp4_t*) y1);

	fp12_mul(t1, (const fp4_t*) t1, (const fp4_t*) y0);

	fp12_sqr(t0, (const fp4_t*) t0);

	fp12_mul(res, (const fp4_t*) t1, (const fp4_t*) t0);
}

/**
 * Interleaved doubling of an elliptic curve point and evaluation
 * of the tangent line function for computing a pairing.
 * @param l the result of the tangent line function evaluation
 * @param t the intermediate elliptic curve point that is updated
 * @param q the projective point to be doubled
 * @param p the point necessary for line function evaluation
 */
void pbc_point_dbl_line_eval(fp12_t l, ecfp2_proj_pt t, ecfp2_proj_pt q, ecfp_pt p) {
	fp2_t t0, t1, t2, t3, t4, t5;

	fp2_sqr(t0, (const fp_t*) q->x);
	fp2_copy(t4, (const fp_t*) t0);
	fp2_dbl(t1, (const fp_t*) t0);
	fp2_add(t1, (const fp_t*) t1, (const fp_t*) t0);	  	// t1 = 3x²
	fp2_copy(t3, (const fp_t*) t1);

	fp2_dbl(t0, (const fp_t*) q->y);						          // t0 = 2 * y
	fp2_mul(t->z, (const fp_t*) t0, (const fp_t*) q->z);	// res->z = 2*y*z

	fp2_sqr(t0, (const fp_t*) t0);							          // t0 = 4 * y²
	fp2_copy(t5, (const fp_t*) t0);
	fp2_mul(t2, (const fp_t*) t0, (const fp_t*) q->x);		// t2 = 4*x*y²

	fp2_copy(t->y, (const fp_t*) t1);						          // res->y = (3x² + az⁴)
	fp2_dbl(t1, (const fp_t*) t2);							          // t1 = 8*x*y²

	fp2_sqr(t->x, (const fp_t*) t->y);						        // res->x = (3x² + az⁴)²
	fp2_sub(t->x, (const fp_t*) t->x, (const fp_t*) t1);	// res->x = (3x² + az⁴)² - 8*x*y²

	fp2_sub(t2, (const fp_t*) t2, (const fp_t*) t->x);		// 4xy² - res->x
	fp2_mul(t->y, (const fp_t*) t->y, (const fp_t*) t2);	// res->y = (3x² + az⁴)(4xy² - res->x)

	fp2_sqr(t0, (const fp_t*) t0);
	fp2_hlv(t0, (const fp_t*) t0);							          // t0 = 8 * y⁴

	fp2_sub(t->y, (const fp_t*) t->y, (const fp_t*) t0);	// res->y = (3x² + az⁴)(4xy² - res->x) - 8y⁴

	fp2_sqr(l[0][0], (const fp_t*) q->z);
	fp2_mul(l[0][0], (const fp_t*) l[0][0], (const fp_t*) t->z);
	fp2_dbl(l[0][0], (const fp_t*) l[0][0]);
	fp2_mulfp(l[0][0], (const fp_t*) l[0][0], p->y);

	fp2_sqr(l[1][0], (const fp_t*) q->z);
	fp2_mul(l[1][0], (const fp_t*) l[1][0], (const fp_t*) t3);
	fp2_dbl(l[1][0], (const fp_t*) l[1][0]);
	fp2_neg(l[1][0], (const fp_t*) l[1][0]);
	fp2_mulfp(l[1][0], (const fp_t*) l[1][0], p->x);

	fp2_add(l[0][1], (const fp_t*) q->x, (const fp_t*) t3);
	fp2_sqr(l[0][1], (const fp_t*) l[0][1]);
	fp2_sqr(t3, (const fp_t*) t3);
	fp2_sub(l[0][1], (const fp_t*) l[0][1], (const fp_t*) t3);
	fp2_sub(l[0][1], (const fp_t*) l[0][1], (const fp_t*) t4);
	fp2_sub(l[0][1], (const fp_t*) l[0][1], (const fp_t*) t5);
}

/**
 * Optimized formulas by Costello that interleave the doubling of an
 * elliptic curve point and the evaluation of the tangent line function
 * for computing a pairing.
 * @param l the result of the tangent line function evaluation
 * @param t the intermediate elliptic curve point that is updated
 * @param q the projective point to be doubled
 * @param p the point necessary for line function evaluation
 */
void pbc_point_dbl_line_costello_eval(fp12_t l, ecfp2_proj_pt t, ecfp2_proj_pt q, ecfp_pt p) {
	fp2_t b, c, e, h;

	fp2_sqr(h, (const fp_t*) q->x);

	fp2_dbl(l[1][0], (const fp_t*) h);
	fp2_add(l[1][0], (const fp_t*) l[1][0], (const fp_t*) h);
	fp2_mulfp(l[1][0], (const fp_t*) l[1][0], (const word_t*) p->x);

	fp2_sqr(b, (const fp_t*) q->y);
	fp2_sqr(c, (const fp_t*) q->z);

	fp2_add(e, (const fp_t*) q->x, (const fp_t*) q->y);
	fp2_sqr(e, (const fp_t*) e);
	fp2_sub(e, (const fp_t*) e, (const fp_t*) h);
	fp2_sub(e, (const fp_t*) e, (const fp_t*) b);

	fp2_add(h, (const fp_t*) q->y, (const fp_t*) q->z);
	fp2_sqr(h, (const fp_t*) h);
	fp2_sub(h, (const fp_t*) h, (const fp_t*) b);
	fp2_sub(h, (const fp_t*) h, (const fp_t*) c);

	fp2_dbl(t->z, (const fp_t*) b);
	fp2_dbl(t->z, (const fp_t*) t->z);
	fp2_mul(t->z, (const fp_t*) t->z, (const fp_t*) h);

	fp2_mulfp(l[0][0], (const fp_t*) h, (const word_t*) p->y);
	fp2_neg(l[0][0], (const fp_t*) l[0][0]);

	fp2_dbl(h, (const fp_t*) c);
	fp2_add(c, (const fp_t*) h, (const fp_t*) c);
	fp2_mulfp(c, (const fp_t*) c, EC_PARAM_B);
	fp2_div_qnr(c, (const fp_t*) c);

	fp2_dbl(h, (const fp_t*) c);
	fp2_add(h, (const fp_t*) h, (const fp_t*) c);

	fp2_sub(t->x, (const fp_t*) b, (const fp_t*) h);
	fp2_mul(t->x, (const fp_t*) t->x, (const fp_t*) e);

	fp2_add(t->y, (const fp_t*) b, (const fp_t*) h);
	fp2_sqr(t->y, (const fp_t*) t->y);

	fp2_sqr(h, (const fp_t*) c);
	fp2_dbl(h, (const fp_t*) h);
	fp2_dbl(h, (const fp_t*) h);

	fp2_sub(t->y, (const fp_t*) t->y, (const fp_t*)h);
	fp2_dbl(h, (const fp_t*) h);
	fp2_sub(t->y, (const fp_t*) t->y, (const fp_t*) h);

	fp2_sub(l[0][1], (const fp_t*) c, (const fp_t*) b);
}

/**
 * Optimized formulas by Costello that interleave adding two elliptic
 * curve points and evaluation of the line function for computing
 * a pairing.
 * @param l the result of the line function evaluation
 * @param t the intermediate elliptic curve point that is updated
 * @param r the projective point to be added
 * @param q the affine point to be added
 * @param p the point necessary for line function evaluation
 */
void pbc_point_add_line_costello_eval(fp12_t l, ecfp2_proj_pt t, ecfp2_proj_pt r, ecfp2_pt q, ecfp_pt p) {
	fp2_t a, b, d, e, f;

	fp2_mul(a, (const fp_t*) q->y, (const fp_t*) r->z);
	fp2_sub(a, (const fp_t*) r->y, (const fp_t*) a);

	fp2_mul(b, (const fp_t*) q->x, (const fp_t*) r->z);
	fp2_sub(b, (const fp_t*) r->x, (const fp_t*) b);

	// l00 = a*q.x - b*q.y
	// l01 = b
	// l10 = -a

	fp2_mulfp(l[0][0], (const fp_t*) b, (const word_t*) p->y);			  	// l01
	fp2_mul(l[0][1], (const fp_t*) b, (const fp_t*) q->y);
	fp2_mul(l[1][0], (const fp_t*) a, (const fp_t*) q->x);
	fp2_sub(l[0][1], (const fp_t*) l[1][0], (const fp_t*) l[0][1]);			// l00
	fp2_neg(l[1][0], (const fp_t*) a);
	fp2_mulfp(l[1][0], (const fp_t*) l[1][0], (const word_t*) p->x);		// l10

	fp2_sqr(f, (const fp_t*) b);
	fp2_mul(d, (const fp_t*) b, (const fp_t*) f);
	fp2_mul(e, (const fp_t*) f, (const fp_t*) r->x);

	fp2_sqr(f, (const fp_t*) a);
	fp2_mul(f, (const fp_t*) f, (const fp_t*) r->z);
	fp2_add(f, (const fp_t*) f, (const fp_t*) d);
	fp2_dbl(t->x, (const fp_t*) e);
	fp2_sub(f, (const fp_t*) f, (const fp_t*) t->x);

	fp2_mul(t->x, (const fp_t*) b, (const fp_t*) f);

	fp2_sub(e, (const fp_t*) e, (const fp_t*) f);
	fp2_mul(e, (const fp_t*) e, (const fp_t*) a);
	fp2_mul(t->y, (const fp_t*) d, (const fp_t*) r->y);
	fp2_sub(t->y, (const fp_t*) e, (const fp_t*) t->y);

	fp2_mul(t->z, (const fp_t*) d, (const fp_t*) r->z);
}

/**
 * Calculates the easy part of the final exponentiation involved in the
 * pairing, i.e. res^{(p^6-1)(p^2+1)}.
 * @param res
 */
void pbc_map_opt_ate_optimized_final_exp_easy(fp12_t res) {
	fp12_t a;

	fp12_inv(a, (const fp4_t*) res);
	fp12_conjugate(res, (const fp4_t*) res, 3);						// res^{p^6}
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);	// res^{p^6 - 1}
	fp12_frobenius_map(a, (const fp4_t*) res, 2);
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);	// res^{(p^6-1)(p^2+1}
}

/**
 * Calculates the final exponentiation of the optimal ate pairing (hard part).
 * It calculates a fixed multiple of the actual pairing, which is a valid
 * thing to do. It is a modified version from the final exponentiation
 * presented by Fuentes-Castaneda which takes one more frobenius action and
 * one more multiplication but saves one temporary variable.
 * @param res both the input and the output to this exponentiation
 * @param a   a temporary variable (reuse of memory)
 * @param b   a temporary variable (reuse of memory)
 */
void pbc_map_opt_ate_optimized_final_exp_fuentes(fp12_t res) {
	fp12_t t0, a, b;

	// hard part
	fp12_frobenius_map(t0, (const fp4_t*) res, 1);					  // (f)^p

	fp12_final_exp(b, (const fp4_t*) res, EC_PARAM_X);				// f^(x)
#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(b, (const fp4_t*) b, 3);
#endif
	fp12_sqr_cyclotomic(b, (const fp4_t*) b);						      // f^(2x)
	fp12_sqr_cyclotomic(a, (const fp4_t*) b);						      // f^(4x)
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) b);				  // f^(6x)
	fp12_mul(b, (const fp4_t*)b, (const fp4_t*) res);				  // f^2x * f
	fp12_conjugate(b, (const fp4_t*)b, 3);							      // f^(-2x) * f^(-1)

	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) t0);			// f * (f^2)^p
	fp12_final_exp(t0, (const fp4_t*) a, EC_PARAM_X);	  			// f^{6x^2}
#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(t0, (const fp4_t*) t0, 3);
#endif
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) t0);			// f^{6x^2} * f * (f^2)^p
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) t0);
	fp12_sqr_cyclotomic(t0, (const fp4_t*) t0);				    		// f^{12x^2}
#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(t0, (const fp4_t*) t0, 3);
#endif
	fp12_final_mulexp(a, t0, EC_PARAM_X);
	fp12_mul(b, (const fp4_t*) b, (const fp4_t*) a);		  		// a * f^(-2x) * f^(-1)

	fp12_frobenius_map(t0, (const fp4_t*) b, 1);
	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) a);
	fp12_frobenius_map(t0, (const fp4_t*) t0, 1);
	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) b);
	fp12_frobenius_map(t0, (const fp4_t*) t0, 1);
	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) res);
	fp12_mul(res, (const fp4_t*) t0, (const fp4_t*) a);
}

/**
 * Calculates the final exponentiation of the optimal ate pairing.
 * (as presented by Scott).
 * @param res both the input and the output to this exponentiation
 * @param a   a temporary variable (reuse of memory)
 * @param b   a temporary variable (reuse of memory)
 */
void pbc_map_opt_ate_optimized_final_exp_std(fp12_t res, fp12_t a, fp12_t b) {
	fp12_t c, t0;
	// Final exponentiation:

	// easy part
	fp12_inv(a, (const fp4_t*) res);
	fp12_conjugate(res, (const fp4_t*) res, 3);				    		// res^{p^6}
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);			// res^{p^6 - 1}
	fp12_conjugate(a, (const fp4_t*) res, 1);
	fp12_mul(res, (const fp4_t*) res, (const fp4_t*) a);			// res^{(p^6-1)(p^2+1}

	// hard part
#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(t0, (const fp4_t*) res, 3);
	fp12_final_exp(a, (const fp4_t*) t0, EC_PARAM_X);
	fp12_conjugate(t0, (const fp4_t*) a, 3);
	fp12_final_exp(b, (const fp4_t*) t0, EC_PARAM_X);
	fp12_conjugate(t0, (const fp4_t*) b, 3);
	fp12_final_exp(c, (const fp4_t*) t0, EC_PARAM_X);
#else
	fp12_final_exp(a, (const fp4_t*) res, EC_PARAM_X);
	fp12_final_exp(b, (const fp4_t*) a, EC_PARAM_X);
	fp12_final_exp(c, (const fp4_t*) b, EC_PARAM_X);
#endif

	fp12_frobenius_map(t0, (const fp4_t*) c, 1);
	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) c);
	fp12_conjugate(t0, (const fp4_t*) t0, 3);

	fp12_sqr_cyclotomic(t0, (const fp4_t*) t0);

	fp12_frobenius_map(c, (const fp4_t*) b, 1);						// ft2
	fp12_mul(c, (const fp4_t*) c, (const fp4_t*) a);			// ft1
	fp12_conjugate(c, (const fp4_t*) c, 3);

	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*)c);

	fp12_frobenius_map(a, (const fp4_t*) a, 1);						// ft1
	fp12_conjugate(a, (const fp4_t*) a, 3);

	fp12_conjugate(c, (const fp4_t*) b, 3);						  	// ft2

	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) c);

	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) c);
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) t0);

	fp12_conjugate(c, (const fp4_t*) b, 1);						  	// ft2
	fp12_mul(t0, (const fp4_t*) t0, (const fp4_t*) c);

	fp12_sqr_cyclotomic(a, (const fp4_t*) a);
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) t0);
	fp12_sqr_cyclotomic(a, (const fp4_t*) a);

	fp12_conjugate(c, (const fp4_t*) res, 3);
	fp12_mul(t0, (const fp4_t*) a, (const fp4_t*) c);

	fp12_frobenius_map(c, (const fp4_t*) res, 1);					// f^p
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) c);
	fp12_frobenius_map(b, (const fp4_t*) c, 1);						// f^{p²}
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) b);
	fp12_frobenius_map(c, (const fp4_t*) b, 1);						// f^{p³}
	fp12_mul(a, (const fp4_t*) a, (const fp4_t*) c);

	fp12_sqr_cyclotomic(t0, (const fp4_t*) t0);

	fp12_mul(res, (const fp4_t*) a, (const fp4_t*) t0);
}

/**
 * Calculates the miller loop involved in the optimal ate pairing.
 * @param res the resulting point
 * @param p point from G1 (elliptic curve over prime field)
 * @param q point from G2 (twisted curve over quadratic extension of prime field)
 */
void pbc_map_opt_ate_optimized_miller_std(fp12_t res, ecfp_pt p, ecfp2_pt q) {
	ecpoint_fp2_proj 	t;
	ecpoint_fp2			q1;
	int 	len, i;
	fp12_t 	a;

	// Actually, the pairing over BN curves is defined as
	// E(F_p) x E'(F_p12) -> F_p12
	// but there is an efficient isomorphism from E(F_p2) to E(F_p12)

	ecfp2_get_homogeneous_projective(&t, q);
	fp12_clear(res); res[0][0][0][0] = 1;
	fp12_clear(a);

#ifdef OPT_ATE_LOOP_CONSTANT
	const word_t	*s 			= OPTATE_LOOP_CONST;
#else
	word_t				s[BI_WORDS+1];
	bi_multiply_word(s, EC_PARAM_X, 6);
  #ifdef NEGATIVE_PARAM_X
	bi_subtract_word(s, s, 2);
  #else
	bi_add_word(s, s, 2);
  #endif
#endif

	len = bi_get_msb(s);

	if (!p->infinity && !q->infinity) {
		// len is the msb -> -1 instead of -2
		for (i = len - 1; i >= 0; i--) {	// interleaved evaluation according to Costello et.al.
			fp12_sqr(res, (const fp4_t*) res);
			pbc_point_dbl_line_costello_eval(a, &t, &t, p);
			fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t*) a[0], (const fp_t*) a[1][0]);

			if (bi_test_bit(s, i)) {
				pbc_point_add_line_costello_eval(a, &t, &t, q, p);
				fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t*) a[0], (const fp_t*) a[1][0]);
			}
		}
	}

#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(res, (const fp4_t*) res, 3);
	ecfp2_neg_proj(&t);
#endif

	// final steps of optimal ate pairing
	ecfp2_frobenius_map(&q1, q, 1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q1, p);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_frobenius_map(&q1, &q1, 1);
	ecfp2_neg_affine(&q1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q1, p);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);
}

/**
 * Computes the Miller loop for the ratio of two pairings.
 * @param p1 elliptic curve point operand of first pairing
 * @param q1 elliptic curve point operand (quadratic extension) of first pairing
 * @param p2 elliptic curve point operand of second pairing
 * @param q2 elliptic curve point operand (quadratic extension) of second pairing
 */
void pbc_map_opt_ate_div_miller_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2) {
	ecpoint_fp2_proj 	t;
	ecpoint_fp2			q_f1;
	fp12_t 				a, r2;
	int len, i;

	// Actually, the pairing over BN curves is defined as
	// E(F_p) x E'(F_p12) -> F_p12
	// but there is an efficient isomorphism from E(F_p2) to E(F_p12)


#ifdef OPT_ATE_LOOP_CONSTANT
	const word_t	*s 			= OPTATE_LOOP_CONST;
#else
	word_t				s[BI_WORDS+1];
	bi_multiply_word(s, EC_PARAM_X, 6);
  #ifdef NEGATIVE_PARAM_X
	bi_subtract_word(s, s, 2);
  #else
	bi_add_word(s, s, 2);
  #endif
#endif
	len = bi_get_msb(s);

	ecfp2_get_homogeneous_projective(&t, q1);
	fp12_clear(res); res[0][0][0][0] = 1;
	fp12_clear(a);

	// len is the msb -> -1 instead of -2
	if (!p1->infinity && !q1->infinity) {
		for (i = len - 1; i >= 0; i--) {	// interleaved evaluation according to Castello et.al.
			fp12_sqr(res, (const fp4_t*) res);
			pbc_point_dbl_line_costello_eval(a, &t, &t, p1);
			fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *) a[1][0]);

			if (bi_test_bit(s, i)) {
				pbc_point_add_line_costello_eval(a, &t, &t, q1, p1);
				fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *)a[1][0]);
			}
		}
	}

#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(res, (const fp4_t*) res, 3);
	ecfp2_neg_proj(&t);
#endif

	// final steps of optimal ate pairing
	ecfp2_frobenius_map(&q_f1, q1, 1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q_f1, p1);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_frobenius_map(&q_f1, &q_f1, 1);
	ecfp2_neg_affine(&q_f1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q_f1, p1);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_get_homogeneous_projective(&t, q2);
	fp12_clear(r2); r2[0][0][0][0] = 1;

	// len is the msb -> -1 instead of -2
	if (!p2->infinity && !q1->infinity) {
		for (i = len - 1; i >= 0; i--) {	// interleaved evaluation according to Castello et.al.
			fp12_sqr(r2, (const fp4_t*) r2);
			pbc_point_dbl_line_costello_eval(a, &t, &t, p2);
			fp12_mul_sparse(r2, (const fp4_t*) r2, (const fp2_t*) a[0], (const fp_t*) a[1][0]);

			if (bi_test_bit(s, i)) {
				pbc_point_add_line_costello_eval(a, &t, &t, q2, p2);
				fp12_mul_sparse(r2, (const fp4_t*) r2, (const fp2_t*) a[0], (const fp_t*) a[1][0]);
			}
		}
	}

#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(r2, (const fp4_t*) r2, 3);
	ecfp2_neg_proj(&t);
#endif


	ecfp2_frobenius_map(&q_f1, q2, 1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q_f1, p2);
	fp12_mul_mloop(r2, (const fp4_t*) r2, (const fp4_t*) a);

	ecfp2_frobenius_map(&q_f1, &q_f1, 1);
	ecfp2_neg_affine(&q_f1);
	pbc_point_add_line_costello_eval(a, &t, &t, &q_f1, p2);
	fp12_mul_mloop(r2, (const fp4_t*) r2, (const fp4_t*) a);

	fp12_inv(r2, (const fp4_t*) r2);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) r2);
}

/**
 * Computes the Miller loop for the product of two pairings, which is
 * optimized by interleaving such that the squaring steps are shared.
 * @param res the result of the Miller loop
 * @param p1 elliptic curve point operand of first pairing
 * @param q1 elliptic curve point operand (quadratic extension) of first pairing
 * @param p2 elliptic curve point operand of second pairing
 * @param q2 elliptic curve point operand (quadratic extension) of second pairing
 */
void pbc_map_opt_ate_mul_miller_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2) {
	ecpoint_fp2_proj 	t1, t2;
	ecpoint_fp2			q_f1;
	fp12_t 				a;
	int len, i;

	// Actually, the pairing over BN curves is defined as
	// E(F_p) x E'(F_p12) -> F_p12
	// but there is an efficient isomorphism from E(F_p2) to E(F_p12)

	ecfp2_get_homogeneous_projective(&t1, q1);
	ecfp2_get_homogeneous_projective(&t2, q2);
	fp12_clear(res); res[0][0][0][0] = 1;
	fp12_clear(a);

#ifdef OPT_ATE_LOOP_CONSTANT
	const word_t	*s 			= OPTATE_LOOP_CONST;
#else
	word_t				s[BI_WORDS+1];
	bi_multiply_word(s, EC_PARAM_X, 6);
  #ifdef NEGATIVE_PARAM_X
	bi_subtract_word(s, s, 2);
  #else
	bi_add_word(s, s, 2);
  #endif
#endif

	len = bi_get_msb(s);

	// len is the msb -> -1 instead of -2
	for (i = len - 1; i >= 0; i--) {	// interleaved evaluation according to Castello et.al.
		fp12_sqr(res, (const fp4_t*) res);
		if (!p1->infinity && !q1->infinity) {
			pbc_point_dbl_line_costello_eval(a, &t1, &t1, p1);
			fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *) a[1][0]);
		}
		if (!p2->infinity && !q2->infinity) {
			pbc_point_dbl_line_costello_eval(a, &t2, &t2, p2);
			fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *) a[1][0]);
		}
		if (bi_test_bit(s, i)) {
			if (!p1->infinity && !q1->infinity) {
				pbc_point_add_line_costello_eval(a, &t1, &t1, q1, p1);
				fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *) a[1][0]);
			}
			if (!p2->infinity && !q2->infinity) {
				pbc_point_add_line_costello_eval(a, &t2, &t2, q2, p2);
				fp12_mul_sparse(res, (const fp4_t*) res, (const fp2_t *)a[0], (const fp_t *) a[1][0]);
			}
		}
	}

#ifdef NEGATIVE_PARAM_X
	fp12_conjugate(res, (const fp4_t*) res, 3);
	ecfp2_neg_proj(&t1);
	ecfp2_neg_proj(&t2);
#endif

	// final steps of optimal ate pairing
	ecfp2_frobenius_map(&q_f1, q1, 1);
	pbc_point_add_line_costello_eval(a, &t1, &t1, &q_f1, p1);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_frobenius_map(&q_f1, &q_f1, 1);
	ecfp2_neg_affine(&q_f1);
	pbc_point_add_line_costello_eval(a, &t1, &t1, &q_f1, p1);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_frobenius_map(&q_f1, q2, 1);
	pbc_point_add_line_costello_eval(a, &t2, &t2, &q_f1, p2);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);

	ecfp2_frobenius_map(&q_f1, &q_f1, 1);
	ecfp2_neg_affine(&q_f1);
	pbc_point_add_line_costello_eval(a, &t2, &t2, &q_f1, p2);
	fp12_mul_mloop(res, (const fp4_t*) res, (const fp4_t*) a);
}


/**
 * Computes an optimal Ate pairing.
 * @param res the result
 * @param p elliptic curve point operand of first pairing
 * @param q elliptic curve point operand (quadratic extension) of first pairing
 */
void pbc_map_opt_ate_optimized_std(fp12_t res, ecfp_pt p, ecfp2_pt q) {
	pbc_map_opt_ate_optimized_miller_std(res, p, q);		// miller loop
	pbc_map_opt_ate_optimized_final_exp_easy(res);			// easy part of final exponentiation
	pbc_map_opt_ate_optimized_final_exp_fuentes(res);		// hard part of final exponentiation
}

/**
 * Computes the product of two optimal Ate pairings.
 * @param res the result
 * @param p1 elliptic curve point operand of first pairing
 * @param q1 elliptic curve point operand (quadratic extension) of first pairing
 * @param p2 elliptic curve point operand of second pairing
 * @param q2 elliptic curve point operand (quadratic extension) of second pairing
 */
void pbc_map_opt_ate_mul_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2) {
	pbc_map_opt_ate_mul_miller_std(res, p1, q1, p2, q2);
	pbc_map_opt_ate_optimized_final_exp_easy(res);
	pbc_map_opt_ate_optimized_final_exp_fuentes(res);
}

/**
 * Computes the ratio of two optimal Ate pairings.
 * @param res the result
 * @param p1 elliptic curve point operand of first pairing
 * @param q1 elliptic curve point operand (quadratic extension) of first pairing
 * @param p2 elliptic curve point operand of second pairing
 * @param q2 elliptic curve point operand (quadratic extension) of second pairing
 */
void pbc_map_opt_ate_div_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2) {
	pbc_map_opt_ate_div_miller_std(res, p1, q1, p2, q2);
	pbc_map_opt_ate_optimized_final_exp_easy(res);
	pbc_map_opt_ate_optimized_final_exp_fuentes(res);
}
