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

#ifndef FP2_STD_H_
#define FP2_STD_H_

#include "types.h"

void fp2_add_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_sub_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_neg_std(fp2_t res, const fp2_t a);
void fp2_mul_std(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_mul_lazy(fp2_t res, const fp2_t a, const fp2_t b);
void fp2_mulfp_std(fp2_t res, const fp2_t a, const fp_t b);
void fp2_sqr_std(fp2_t res, const fp2_t a);
void fp2_inv_std(fp2_t res, const fp2_t a);
void fp2_exp_std(fp2_t res, const fp2_t a, const bigint_t b);
void fp2_hlv_std(fp2_t res, const fp2_t a);
void fp2_frobenius_map_std(fp2_t res, const fp2_t a, const word_t i);
void fp2_mul_qnr_std(fp2_t res, const fp2_t a);
void fp2_div_qnr_std(fp2_t res, const fp2_t a);
void fp2_sqrt_std(fp2_t res, const fp2_t a);
int  fp2_legendre_std(const fp2_t a);

void fp2_to_montgomery_std(fp2_t res, const fp2_t a);
void fp2_from_montgomery_std(fp2_t res, const fp2_t a);

void fp2_rdc_std(fp2_t a);

void fp2_clear_std(fp2_t a);
void fp2_copy_std(fp2_t res, const fp2_t a);

#endif /* FP2_STD_H_ */
