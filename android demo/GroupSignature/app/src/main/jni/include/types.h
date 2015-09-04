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

#endif /* TYPES_H_ */
