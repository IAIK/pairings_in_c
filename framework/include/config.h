/*
 * config.h
 *
 *  Created on: Apr 19, 2013
 *      Author: thomas
 */

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

// Use the multiply-accumulate extensions of the underlying processor
//#define ASM_MULACC_EXTENSION

// Use the area-saving 4-cycle multiply-accumulate extension of the underlying processor
// (only makes sense for the Cortex-M0+)
//#define ASM_4CYCLE_MULACC		// is only recognized if ASM_MULACC_EXTENSION is set

// Use a dedicated assembler-optimized, unrolled squaring routine in Fp.
//#define DEDICATED_SQUARING

// Use the Toom-Cook variant to multiply in cubic extension fields.
//#define TK3_MUL_OPT

// Use the lazy reduction technique by Sanchez in Fp2 mult
#define LAZY_REDUCTION

// Use lazy reduction in Fp arithmetic.
//#define REAL_LAZY_REDUCTION

// Randomize projective coordinates.
#define RAND_PROJECTIVE_COORDINATES

//#define HYBRID_MULTIPLICATION

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

// precomputation constants for sliding window and naf-window exponentiations and multiplications

#define FP_EXP_SLW_WIDTH 		4
#define FP_EXP_SLW_TBL_SZ   	(1 << (FP_EXP_SLW_WIDTH-1))

#define EC_MUL_NAFW_WIDTH		4
#define EC_MUL_NAFW_TBL_SZ		((1 << (EC_MUL_NAFW_WIDTH-1))-1)

#endif /* CONFIG_H_ */
