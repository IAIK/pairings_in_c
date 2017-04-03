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

#ifndef ECFP2_STD_H_
#define ECFP2_STD_H_

#include "types.h"

void ecfp2_add_affine_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const ecpoint_fp2 *b);
void ecfp2_add_affine_direct_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const ecpoint_fp2 *b);
void ecfp2_add_proj_std(ecpoint_fp2_proj *res, const ecpoint_fp2_proj *a, const ecpoint_fp2 *b);
void ecfp2_dbl_affine_std(ecpoint_fp2 *res, const ecpoint_fp2 *a);
void ecfp2_dbl_affine_direct_std(ecpoint_fp2 *res, const ecpoint_fp2 *a);
void ecfp2_dbl_proj_std(ecpoint_fp2_proj *res, const ecpoint_fp2_proj *a);
void ecfp2_neg_affine_std(ecpoint_fp2 *a);
void ecfp2_neg_proj_std(ecpoint_fp2_proj *a);
void ecfp2_mul_l2rb_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const fp_t k);
void ecfp2_mul_montyladder_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const fp_t k);


void ecfp2_get_affine_from_jacobian_std(ecpoint_fp2 *affine, const ecpoint_fp2_proj *projective);

void ecfp2_rand_std(ecpoint_fp2 *res);

void ecfp2_get_affine_std(ecpoint_fp2 *affine, const ecpoint_fp2_proj *projective);

void ecfp2_get_projective_std(ecpoint_fp2_proj *projective, const ecpoint_fp2 *affine);
void ecfp2_get_homogeneous_projective_rnd_std(ecpoint_fp2_proj *projective, const ecpoint_fp2 *affine);
void ecfp2_get_jacobian_projective_rnd_std(ecpoint_fp2_proj *projective, const ecpoint_fp2 *affine);

void ecfp2_frobenius_map_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const word_t i);
void ecfp2_frobenius_map_precomp_std(ecpoint_fp2 *res, const ecpoint_fp2 *a, const word_t i);

void ecfp2_hash_to_point_std(ecpoint_fp2 *res, const bigint_t t);

void ecfp2_copy_std(ecpoint_fp2 *res, const ecpoint_fp2 *a);
void ecfp2_clear_std(ecpoint_fp2 *a);

void ecfp2_to_montgomery_std(ecpoint_fp2 *res, const ecpoint_fp2 *a);
void ecfp2_from_montgomery_std(ecpoint_fp2 *res, const ecpoint_fp2 *a);

#endif /* ECFP2_STD_H_ */
