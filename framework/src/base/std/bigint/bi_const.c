/*
 * fp_const.c
 *
 *  Created on: Apr 20, 2013
 *      Author: thomas
 */

#include "bigint/bi.h"

/**
 * Defines big integer constants for one and zero that depend on the datatype's size.
 */
#if BYTES_PER_WORD == 4
  #if PRECISION == 256
    const bigint_t bi_one = {0x00000001, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000, 0x00000000,0x00000000, 0x00000000};
    const bigint_t bi_zero= {0x00000000, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000, 0x00000000,0x00000000, 0x00000000};
  #elif PRECISION == 160
    const bigint_t bi_one = {0x00000001, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000};
    const bigint_t bi_zero= {0x00000000, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000};
  #endif
#endif
