/*
 * types.h
 *
 *  Created on: Apr 19, 2013
 *      Author: thomas
 */

#ifndef TYPES_H_
#define TYPES_H_

#include "config.h"

/*
 * Elementary types for low-level arithmetics based on processor architecture.
 */

#if BYTES_PER_WORD == 1
typedef unsigned char word_t;
typedef unsigned short dword_t;
#elif BYTES_PER_WORD == 2
typedef unsigned short word_t;
typedef unsigned long dword_t;
#elif BYTES_PER_WORD == 4
  #if ARCHITECTURE == ARCH_X86_64
  typedef unsigned int word_t;
  typedef unsigned long long dword_t;
  #else
  typedef unsigned long word_t;
  typedef unsigned long long dword_t;
  #endif
#endif

typedef unsigned int 	length_t;
typedef unsigned int 	uint;
typedef unsigned char 	byte;
typedef signed char 	sbyte;

#if BITS_PER_WORD == 8
    #define LD_BITS_PER_WORD 3
	#define LD_BYTES_PER_WORD 0
	#define WORD_MAX	0xFF
#endif
#if BITS_PER_WORD == 16
    #define LD_BITS_PER_WORD 4
	#define LD_BYTES_PER_WORD 1
	#define WORD_MAX	0xFFFF
#endif
#if BITS_PER_WORD == 32
    #define LD_BITS_PER_WORD 5
	#define LD_BYTES_PER_WORD 2
	#define WORD_MAX	0xFFFFFFFF
#endif
#if BITS_PER_WORD == 64
    #define LD_BITS_PER_WORD 6
	#define LD_BYTES_PER_WORD 3
	#define WORD_MAX	0xFFFFFFFFFFFFFFFF
#endif

#define WORDS_PER_BITS(bits) (((bits-1)/BITS_PER_WORD)+1)

#define FP_BITS		PRECISION
#define FP_BYTES	( (length_t) ( (FP_BITS)/8 + ( (FP_BITS % 8) > 0) ) )
#define FP_WORDS 	( (length_t) ( (FP_BITS)/(BITS_PER_WORD) )  + ( (FP_BITS % 8) > 0) )
#define BI_WORDS 	FP_WORDS
#define BI_BYTES	FP_BYTES
#define BI_BITS		FP_BITS

/* These two types shall mark the difference between parameters which value
 * is an element of Fp and simple big integers.
 */

typedef word_t	bigint_t[BI_WORDS];
typedef word_t	fp_t[FP_WORDS];

/** Types of extension of the finite field. */
typedef fp_t	fp2_t[2];
typedef fp2_t 	fp4_t[2];
typedef fp4_t	fp12_t[3];

/** Structure to keep information on the prime number used. */
typedef struct {
	bigint_t 	p;					// prime
	word_t		mu[FP_WORDS+1];		// constant for barrett multiplication
	int			qnr;		// qnr of prime, i.e. x^2 = qnr mod p is unsolvable
	int			cnr;		// cnr of prime, i.e. x^3 = cnr mod p is unsolvable
} structPrime;

/** Structure for Montgomery parameters. */
typedef struct {
	bigint_t	n0;			// n0 = -p^{-1} mod R, to be used for the Montgomery reduction
	bigint_t	r2;			// r2 = R² mod p, to be used for transformation to Montgomery domain
} structMontyParam;

/** Elliptic curve point. */

typedef struct {
	fp_t x;
	fp_t y;
	byte infinity;
} ecpoint_fp;

typedef ecpoint_fp *ecfp_pt;

typedef struct {
	fp_t x;
	fp_t y;
	fp_t z;
	byte infinity;
} ecpoint_fp_proj;

typedef ecpoint_fp_proj *ecfp_proj_pt;

typedef struct {
	fp2_t x;
	fp2_t y;
	byte infinity;
} ecpoint_fp2;

typedef ecpoint_fp2 *ecfp2_pt;

typedef struct {
	fp2_t x;
	fp2_t y;
	fp2_t z;
	byte infinity;
} ecpoint_fp2_proj;

typedef ecpoint_fp2_proj *ecfp2_proj_pt;

/** Structure for elliptic curve parameters. */

typedef struct {
	// y² = x³ + ax + b
	fp_t a;
	fp_t b;
	bigint_t x;		// parameter for parameterized curve
	//bigint_t t;		// trace
	bigint_t n;		// group order
	word_t mu_n[FP_WORDS+1];	// mu for reducing modulo group order
} structECParam;

typedef struct {
	// vectors for decomposing factor k: (-b1/n, a1,b1), (b2/n, a2,b2);
	bigint_t v1[3];
	bigint_t v2[3];
	// beta (endomorphism: lambda*P = (beta*x, y))
	bigint_t beta;
} structGLVParam;

#endif /* TYPES_H_ */
