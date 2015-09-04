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
#include "config.h"

.macro mulacc
	uxth r6, r1
	uxth r7, r2
	lsr  r1, r1, #16
	lsr  r2, r2, #16

	mov r0, r6
	mul r0, r0, r7  @ low * low
	mul r6, r6, r2  @ low * high
	mul r2, r2, r1  @ high * high
	mul r1, r1, r7  @ high * low

	lsl r7, r6, #16
	lsr r6, r6, #16
	add r0, r7, r0
	adc r2, r6, r2

	lsl r7, r1, #16
	lsr r6, r1, #16
	add r0, r7, r0
	adc r2, r6, r2

	mov r7, #0

	add r5, r5, r0
	adc r4, r4, r2
	adc r3, r3, r7
.endm

.macro loadMultiply idxA, idxB
	mov r1, r8
	ldr r1, [r1, #\idxA*4]
	mov r2, r9
	ldr r2, [r2, #\idxB*4]
#ifdef ASM_UNROLL_MULACC
	mulacc
#else
	bl multiply_acc_words
#endif
.endm

.macro storeAndShiftAcc idx
	mov r6, r10
	str r5, [r6, #\idx*4]
	mov r5, r4
	mov r4, r3
	mov r3, #0
.endm

.macro storeRemAcc idx1, idx2
	mov r6, r10
	str r5, [r6, #\idx1*4]
	str r4, [r6, #\idx2*4]
.endm


.global bi_multiply_cm0_256_opt
.type bi_multiply_cm0_256_opt, function
.text 1
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_cm0_256_karatsuba:
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	push {r4, r5, r6}

	mov r8, r1
	mov r9, r2
	mov r10, r0
	@mov r10, sp		@ this is somewhat dangerous (imagine an interrupt coming in...)
	@mov sp, r0

	ldr r3, =0
	mov r4, r3
	mov r5, r3
	mov r7, r3

	loadMultiply 0, 0
	storeAndShiftAcc 0

	loadMultiply 1, 0
	loadMultiply 0, 1
	storeAndShiftAcc 1

	loadMultiply 2, 0
	loadMultiply 1, 1
	loadMultiply 0, 2
	storeAndShiftAcc 2

	loadMultiply 3, 0
	loadMultiply 2, 1
	loadMultiply 1, 2
	loadMultiply 0, 3
	storeAndShiftAcc 3

	loadMultiply 4, 0
	loadMultiply 3, 1
	loadMultiply 2, 2
	loadMultiply 1, 3
	loadMultiply 0, 4
	storeAndShiftAcc 4

	loadMultiply 5, 0
	loadMultiply 4, 1
	loadMultiply 3, 2
	loadMultiply 2, 3
	loadMultiply 1, 4
	loadMultiply 0, 5
	storeAndShiftAcc 5

	loadMultiply 6, 0
	loadMultiply 5, 1
	loadMultiply 4, 2
	loadMultiply 3, 3
	loadMultiply 2, 4
	loadMultiply 1, 5
	loadMultiply 0, 6
	storeAndShiftAcc 6

	loadMultiply 7, 0
	loadMultiply 6, 1
	loadMultiply 5, 2
	loadMultiply 4, 3
	loadMultiply 3, 4
	loadMultiply 2, 5
	loadMultiply 1, 6
	loadMultiply 0, 7
	storeAndShiftAcc 7

	loadMultiply 7, 1
	loadMultiply 6, 2
	loadMultiply 5, 3
	loadMultiply 4, 4
	loadMultiply 3, 5
	loadMultiply 2, 6
	loadMultiply 1, 7
	storeAndShiftAcc 8

	loadMultiply 7, 2
	loadMultiply 6, 3
	loadMultiply 5, 4
	loadMultiply 4, 5
	loadMultiply 3, 6
	loadMultiply 2, 7
	storeAndShiftAcc 9

	loadMultiply 7, 3
	loadMultiply 6, 4
	loadMultiply 5, 5
	loadMultiply 4, 6
	loadMultiply 3, 7
	storeAndShiftAcc 10

	loadMultiply 7, 4
	loadMultiply 6, 5
	loadMultiply 5, 6
	loadMultiply 4, 7
	storeAndShiftAcc 11

	loadMultiply 7, 5
	loadMultiply 6, 6
	loadMultiply 5, 7
	storeAndShiftAcc 12

	loadMultiply 7, 6
	loadMultiply 6, 7
	storeAndShiftAcc 13

	loadMultiply 7, 7
	storeRemAcc 14, 15

	@mov sp, r10

	pop {r4, r5, r6}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7, pc}

.global multiply_acc_words_v2
.type   multiply_acc_words_v2, %function
.text
.thumb
.code   16
@ Input: r4, r5
@ accumulator: r8, r9, r10 (lsw: r10, msw: r8)
@ zero: r7
multiply_acc_words_v2:

	uxth r6, r1
	uxth r7, r2
	lsr  r1, r1, #16
	lsr  r2, r2, #16

	mov r0, r6
	mul r0, r0, r7  @ low * low
	mul r6, r6, r2  @ low * high
	mul r2, r2, r1  @ high * high
	mul r1, r1, r7  @ high * low

	mov r7, #0

	add r5, r5, r0
	adc r4, r4, r2
	adc r3, r3, r7

	lsl r0, r6, #16
	lsr r2, r6, #16
	add r5, r5, r0
	adc r4, r4, r2
	adc r3, r3, r7

	lsl r0, r1, #16
	lsr r2, r1, #16
	add r5, r5, r0
	adc r4, r4, r2
	adc r3, r3, r7

	bx lr
