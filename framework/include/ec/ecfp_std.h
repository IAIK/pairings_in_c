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

#ifndef ECFP_STD_H_
#define ECFP_STD_H_

#include "fp/fp.h"

void ecfp_add_affine_std(ecpoint_fp *res, const ecpoint_fp *a, const ecpoint_fp *b);
void ecfp_add_affine_direct_std(ecpoint_fp *res, const ecpoint_fp *a, const ecpoint_fp *b);
void ecfp_add_proj_std(ecpoint_fp_proj *res, const ecpoint_fp_proj *a, const ecpoint_fp *b);
void ecfp_dbl_affine_std(ecpoint_fp *res, const ecpoint_fp *a);
void ecfp_dbl_affine_direct_std(ecpoint_fp *res, const ecpoint_fp *a);
void ecfp_dbl_proj_std(ecpoint_fp_proj *res, const ecpoint_fp_proj *a);
void ecfp_neg_affine_std(ecpoint_fp *a);
void ecfp_neg_proj_std(ecpoint_fp_proj *a);
void ecfp_mul_l2rb_std(ecpoint_fp *res, const ecpoint_fp *a, const fp_t k);
void ecfp_mul_montyladder_std(ecpoint_fp *res, const ecpoint_fp *a, const fp_t k);
void ecfp_mul_naf_std(ecpoint_fp *res, const ecpoint_fp *a, const fp_t k);
void ecfp_mul_glv_std(ecpoint_fp *res, const ecpoint_fp *a, const fp_t k);
void ecfp_mul_glv_dec_k_std(bigint_t k1, bigint_t k2, bigint_t k);

void ecfp_get_affine_from_jacobian_std(ecpoint_fp *affine, const ecpoint_fp_proj *projective);
void ecfp_rand_std(ecpoint_fp *res);
void ecfp_get_affine_std(ecpoint_fp *affine, const ecpoint_fp_proj *projective);

void ecfp_get_projective_std(ecpoint_fp_proj *projective, const ecpoint_fp *affine);
void ecfp_get_jacobian_projective_rnd_std(ecpoint_fp_proj *projective, const ecpoint_fp *affine);

void ecfp_hash_to_point_std(ecpoint_fp *res, const bigint_t t);

void ecfp_copy_std(ecpoint_fp *res, const ecpoint_fp *a);
void ecfp_clear_std(ecpoint_fp *a);

void ecfp_to_montgomery_std(ecpoint_fp *res, const ecpoint_fp *a);
void ecfp_from_montgomery_std(ecpoint_fp *res, const ecpoint_fp *a);

#endif /* ECFP_STD_H_ */
