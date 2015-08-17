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

#ifndef PARAM_H_
#define PARAM_H_

#include "types.h"

extern const bigint_t PRIME_P;  // prime
extern const word_t   PRIME_MU[FP_WORDS+1]; // constant for barrett multiplication
extern const int PRIME_QNR; // qnr of prime, i.e. x^2 = qnr mod p is unsolvable
extern const int PRIME_CNR; // cnr of prime, i.e. x^3 = cnr mod p is unsolvable

extern const bigint_t			LAZYR_PRIMEC;

extern const bigint_t MONTY_PRIME_N0; // n0 = -p^{-1} mod R, to be used for the Montgomery reduction
extern const bigint_t MONTY_PRIME_R2; // r2 = R² mod p, to be used for transformation to Montgomery domain

// y² = x³ + ax + b
extern const fp_t EC_PARAM_A;
extern const fp_t EC_PARAM_B;
extern const bigint_t EC_PARAM_X; // parameter for parameterized curve
extern const bigint_t EC_PARAM_N; // group order
extern const word_t EC_PARAM_MU_N[FP_WORDS+1]; // mu for reducing modulo group order

extern const fp_t				EC_PARAM_4B;

extern const fp2_t				ROOT_RESIDUE_FP4[5];
extern const fp_t				FP_ONE;

extern const bigint_t 			OPTATE_LOOP_CONST;
extern const bigint_t			MOD_INV_EXPONENT;	// (prime-2)

extern const bigint_t			BN_INV_CONST;

extern const ecpoint_fp			ECFP_GENERATOR;
extern const ecpoint_fp2		ECFP2_GENERATOR;

#endif /* PARAM_H_ */
