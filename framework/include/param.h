/*
 * param.h
 *
 *  Created on: Apr 21, 2013
 *      Author: thomas
 */

#ifndef PARAM_H_
#define PARAM_H_

#include "types.h"

extern const structPrime 		PRIME;
extern const bigint_t			LAZYR_PRIMEC;
extern const structMontyParam	MONTY_PRIME;
extern const structECParam 		EC_PARAM;
extern const fp_t				EC_PARAM_4B;
extern const structGLVParam 	GLV_PARAM;

extern const fp2_t				ROOT_RESIDUE_FP4[5];
extern const fp_t				FP_ONE;

extern const bigint_t 			OPTATE_LOOP_CONST;
extern const bigint_t			MOD_INV_EXPONENT;	// (prime-2)

extern const bigint_t			BN_INV_CONST;

extern const ecpoint_fp			ECFP_GENERATOR;
extern const ecpoint_fp2		ECFP2_GENERATOR;

#endif /* PARAM_H_ */
