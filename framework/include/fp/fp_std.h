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

#ifndef FP_STD_H_
#define FP_STD_H_

#include "types.h"

void fp_add_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod);
void fp_add_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t multipleMod);
void fp_sub_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod);
void fp_sub_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t multipleMod);
void fp_dbl_std(fp_t res, const fp_t a, const bigint_t mod);
void fp_neg_std(fp_t res, const fp_t a, const bigint_t mod);
void fp_neg_lazy(fp_t res, const fp_t a, const bigint_t mod, const bigint_t multipleMod);
void fp_mul_std(fp_t res, const fp_t a, const fp_t b, const bigint_t mod, const bigint_t mu);
void fp_mul_scalar_std(fp_t res, const fp_t a, const word_t b, const bigint_t mod);
void fp_mul_monty_std(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const bigint_t n0);
void fp_mul_monty_twostep(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const word_t n0);
void fp_mul_monty_twostep_lazy(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const word_t n0, const bigint_t multipleMod);
void fp_mul_monty_fips_std(fp_t res, const fp_t a, const fp_t b, const bigint_t modulo, const word_t n0);
void fp_inv_std(fp_t res, const fp_t a, const bigint_t mod);
void fp_inv_exp_std(fp_t res, const fp_t a);
void fp_inv_exp_var_std(fp_t res, const fp_t a, const bigint_t mod, const bigint_t mu);
void fp_inv_bn(fp_t res, const fp_t a);
void fp_hlv_std(fp_t res, const fp_t a, const bigint_t mod);
void fp_exp_monty(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const bigint_t n0, const bigint_t r2);

#ifdef MONTGOMERY_ARITHMETIC

void fp_exp_std(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0);
void fp_sqrt_std(fp_t res, const fp_t a, const bigint_t mod, const word_t n0);
int  fp_legendre_std(const fp_t a, const bigint_t mod, const word_t n0);
void fp_exp_lazy(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const word_t n0, const bigint_t multipleMod);
void fp_sqrt_lazy(fp_t res, const fp_t a, const bigint_t mod, const word_t n0, const bigint_t multipleMod);
int  fp_legendre_lazy(const fp_t a, const bigint_t mod, const word_t n0, const bigint_t multipleMod);

#else

void fp_exp_std(fp_t res, const fp_t a, const bigint_t b, const bigint_t mod, const bigint_t mu);
void fp_sqrt_std(fp_t res, const fp_t a, const bigint_t mod, const bigint_t mu);
int  fp_legendre_std(const fp_t a, const bigint_t mod, const bigint_t mu);

#endif


void fp_rdc_2l_std(word_t *a, const bigint_t mod, const word_t *mu);
void fp_rdc_std(fp_t a, const bigint_t mod);
void fp_rdc_monty_std(fp_t res, word_t *a, const bigint_t mod, const word_t n0);
void fp_rdc_monty_lazy(fp_t res, word_t *a, const bigint_t mod, const word_t n0, const bigint_t multipleMod);

void fp_clear_std(fp_t a);
void fp_copy_std(fp_t a, const fp_t b);

void fp_to_montgomery_std(fp_t res, const fp_t a);
void fp_from_montgomery_std(fp_t res, const fp_t a);


#endif /* FP_STD_H_ */
