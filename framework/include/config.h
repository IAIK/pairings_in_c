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

#ifndef CONFIG_H_
#define CONFIG_H_

#include "arch.h"

#define BN158 1
#define BN254 2
#define BN256 3

#define BM_CYCLE 1
#define BM_CLOCK 2

// Decide on benchmarking primitive (BM_CYCLE - cyclec ounts, BM_CLOCK - clock)
#ifndef BENCHMARK_SRC
#define BENCHMARK_SRC BM_CYCLE
#endif

// Decide on target architecture
#ifndef ARCHITECTURE
  #define ARCHITECTURE 	ARCH_X86_64
#endif

// Decide on the elliptic curve to be used
#ifndef BNCURVE
#define BNCURVE BN254
#endif

// Activate assembly optimizations if available
#define ASM_OPTIMIZATION

// Activate montgomery arithmetic
#define MONTGOMERY_ARITHMETIC

// Activate unrolling of multiply-accumulates in assembly
#define ASM_UNROLL_MULACC

// Perform fast reduction in FP2. Note that this must only be activated
// if the quadratic non-residue used to define FP2 is -1.
#define FAST_QNR

// Skip computations in elliptic curve doubling due to zero parameter a (y^2 = x^3 + ax + b)
#define OPTIMIZE_ZERO_A

// Use a precomputed constant for the Miller loop in optimal Ate pairings
#define OPT_ATE_LOOP_CONSTANT

// Use a precomputed constant for the value 4b (from the elliptic curve equation's b)
#define USE_PREDEFINED_4B

// Use the lazy reduction technique by Sanchez in Fp2 mult
#define LAZY_REDUCTION

// Randomize projective coordinates.
#define RAND_PROJECTIVE_COORDINATES

// Depending on the curve, set which quadratic and cubic non-residue in Fp2
// needs to be used and whether the BN parameter x is negative
#if (BNCURVE == BN254)
#define NEGATIVE_PARAM_X
#define INVERSE_RESIDUE
#endif
#if (BNCURVE == BN158)
#define INVERSE_RESIDUE
#endif

#if defined(LAZY_REDUCTION) && BNCURVE == BN256
#error "Lazy reduction is not available for BN256."
#endif

// Set global constants for precision, bytes and bits per word (architecture dependent)

#define BYTES_PER_WORD	4
#define BITS_PER_WORD	(8*BYTES_PER_WORD)

#if BNCURVE == BN254 || BNCURVE == BN256
#define PRECISION		256
#elif BNCURVE == BN158
#define PRECISION		160
#endif


#endif /* CONFIG_H_ */
