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

#ifndef FP4_STD_H_
#define FP4_STD_H_

#include "types.h"

void fp4_add_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_sub_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_neg_std(fp4_t res, const fp4_t a);
void fp4_mul_std(fp4_t res, const fp4_t a, const fp4_t b);
void fp4_sqr_std(fp4_t res, const fp4_t a);
void fp4_mulfp2_std(fp4_t res, const fp4_t a, const fp2_t b);
void fp4_inv_std(fp4_t res, const fp4_t a);
void fp4_exp_std(fp4_t res, const fp4_t a, const bigint_t b);
void fp4_hlv_std(fp4_t res, const fp4_t a);
void fp4_frobenius_map_std(fp4_t res, const fp4_t a, const word_t i);
void fp4_frobenius_map_precomp_std(fp4_t res, const fp4_t a, const word_t i);
void fp4_mul_adj_root_std(fp4_t res, const fp4_t a);

void fp4_to_montgomery_std(fp4_t res, const fp4_t a);
void fp4_from_montgomery_std(fp4_t res, const fp4_t a);

void fp4_rdc_std(fp4_t a);

void fp4_clear_std(fp4_t a);
void fp4_copy_std(fp4_t res, const fp4_t a);

#endif /* FP4_STD_H_ */
