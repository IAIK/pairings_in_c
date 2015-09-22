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

#ifndef FP12_STD_H_
#define FP12_STD_H_

#include "types.h"

void fp12_add_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_sub_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_neg_std(fp12_t res, const fp12_t a);
void fp12_mul_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_mul_tk3_std(fp12_t res, const fp12_t a, const fp12_t b);
void fp12_sqr_std(fp12_t res, const fp12_t a);
void fp12_sqr_cyclotomic_std(fp12_t res, const fp12_t a);
void fp12_sqr_cyclotomic_compressed(fp12_t res, const fp12_t a);
void fp12_mul_sparse_std(fp12_t res, const fp12_t a, const fp4_t b0, const fp2_t b10);
void fp12_inv_std(fp12_t res, const fp12_t a);
void fp12_exp_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_masked_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_montyladder_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_exp_cyclotomic_masked_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_final_exp_std(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_final_mulexp_std(fp12_t res, fp12_t a, const bigint_t b);
void fp12_final_exp_bn254(fp12_t res, const fp12_t a, const bigint_t b);
void fp12_hlv_std(fp12_t res, const fp12_t a);
void fp12_frobenius_map_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_frobenius_map_precomp_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_conjugate_std(fp12_t res, const fp12_t a, const word_t i);
void fp12_decompress_std(fp12_t a);

void fp12_to_montgomery_std(fp12_t res, const fp12_t a);
void fp12_from_montgomery_std(fp12_t res, const fp12_t a);

void fp12_rdc_std(fp12_t a);

void fp12_clear_std(fp12_t a);
void fp12_copy_std(fp12_t res, const fp12_t a);

#endif /* FP12_STD_H_ */
