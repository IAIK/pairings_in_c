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

.macro loadAndAdd reg, idx
.if \reg == sp || \reg == r0
	ldr r6, [\reg, #\idx*4]
.else
	mov r0, \reg
	ldr r6, [r0, #\idx*4]
.endif
	add r5, r5, r6
	adc r4, r4, r7
.endm

.macro loadAndSub reg, idx
.if \reg == sp || \reg == r0
	ldr r6, [\reg, #\idx*4]
.else
	mov r0, \reg
	ldr r6, [r0, #\idx*4]
.endif
	sub r5, r5, r6
	sbc r4, r4, r7
.endm

.macro loadAndAddIfCarry carryReg, opReg, idx
	ldr r0, [\opReg, #\idx*4]
	mov r1, \carryReg
	and r0, r0, r1
	add r5, r5, r0
	adc r4, r4, r7
.endm

.macro loadMultiply regA, regB, idxA, idxB
.if \regA == sp
	ldr r1, [sp, #\idxA*4]
.else
	mov r1, \regA
	ldr r1, [r1, #\idxA*4]
.endif
.if \regB == sp
	ldr r2, [sp, #\idxB*4]
.else
	mov r2, \regB
	ldr r2, [r2, #\idxB*4]
.endif
	mulacc
.endm

.macro storeAndShiftAcc regDst, idx
.if \regDst == sp || \regDst == r0
	str r5, [\regDst, #\idx*4]
.else
	mov r6, \regDst
	str r5, [r6, #\idx*4]
.endif
	mov r5, r4
	mov r4, r3
	asr r3, r4, #32
.endm

.macro storeRemAcc regDst, idx1, idx2
.if \regDst == sp
	str r5, [sp, #\idx1*4]
	str r4, [sp, #\idx2*4]
.else
	mov r6, \regDst
	str r5, [r6, #\idx1*4]
	str r4, [r6, #\idx2*4]
.endif
.endm

.macro resetAccumulator
	ldr r3, =0
	mov r4, r3
	mov r5, r3
.endm

.macro multiplyLow
	loadMultiply r8,r9,0,0
	storeAndShiftAcc r10, 0

	loadMultiply r9,r8,1,0
	loadMultiply r9,r8,0,1
	storeAndShiftAcc r10, 1

	loadMultiply r8,r9,2,0
	loadMultiply r8,r9,1,1
	loadMultiply r8,r9,0,2
	storeAndShiftAcc r10, 2

	loadMultiply r9,r8,3,0
	loadMultiply r8,r9,1,2
	loadMultiply r8,r9,2,1
	loadMultiply r8,r9,3,0
	storeAndShiftAcc r10, 3

	loadMultiply r9,r8,1,3
	loadMultiply r9,r8,2,2
	loadMultiply r9,r8,3,1
	storeAndShiftAcc sp, 8

	loadMultiply r8,r9,2,3
	loadMultiply r8,r9,3,2
	storeAndShiftAcc sp, 9

	loadMultiply r9,r8,3,3
	storeRemAcc sp, 10, 11
.endm

.macro multiplyHigh
	loadMultiply r8,r9,4,4
	storeAndShiftAcc r10, 8

	loadMultiply r9,r8,5,4
	loadMultiply r9,r8,4,5
	storeAndShiftAcc r10, 9

	loadMultiply r8,r9,6,4
	loadMultiply r8,r9,5,5
	loadMultiply r8,r9,4,6
	storeAndShiftAcc r10, 10

	loadMultiply r9,r8,7,4
	loadMultiply r8,r9,5,6
	loadMultiply r8,r9,6,5
	loadMultiply r8,r9,7,4
	storeAndShiftAcc r10, 11

	loadMultiply r9,r8,5,7
	loadMultiply r9,r8,6,6
	loadMultiply r9,r8,7,5
	storeAndShiftAcc r10, 12

	loadMultiply r8,r9,6,7
	loadMultiply r8,r9,7,6
	storeAndShiftAcc r10, 13

	loadMultiply r9,r8,7,7
	storeRemAcc r10, 14, 15
.endm

.macro multiplyMiddle
	mov r7, #0
	mov r0, r10
	loadAndAdd sp, 8
	loadAndSub r0,8
	loadAndSub r0,0
	asr r3, r4, #32
	loadMultiply sp,sp,0,4
	storeAndShiftAcc r10,4

	mov r0, r10
	loadAndAdd sp, 9
	loadAndSub r0,9
	loadAndSub r0,1
	asr r3, r4, #32
	loadMultiply sp,sp,1,4
	loadMultiply sp,sp,0,5
	storeAndShiftAcc r10,5

	mov r0, r10
	loadAndAdd sp, 10
	loadAndSub r0,10
	loadAndSub r0,2
	asr r3, r4, #32
	loadMultiply sp,sp,2,4
	loadMultiply sp,sp,1,5
	loadMultiply sp,sp,0,6
	storeAndShiftAcc r10,6

	mov r0, r10
	loadAndAdd sp, 11
	loadAndSub r0,11
	loadAndSub r0,3
	asr r3, r4, #32
	loadMultiply sp,sp,3,4
	loadMultiply sp,sp,2,5
	loadMultiply sp,sp,1,6
	loadMultiply sp,sp,0,7
	storeAndShiftAcc r10,7

	loadAndAddIfCarry  r11, sp, 4
	loadAndAddIfCarry r12, sp, 0
	mov r0, r10
	loadAndAdd r0,8
	loadAndSub r0,12
	loadAndSub sp,8
	asr r3, r4, #32
	loadMultiply sp,sp,3,5
	loadMultiply sp,sp,2,6
	loadMultiply sp,sp,1,7
	storeAndShiftAcc r10,8

	loadAndAddIfCarry  r11, sp, 5
	loadAndAddIfCarry r12, sp, 1
	mov r0, r10
	loadAndAdd r0,9
	loadAndSub r0,13
	loadAndSub sp,9
	asr r3, r4, #32
	loadMultiply sp,sp,3,6
	loadMultiply sp,sp,2,7
	storeAndShiftAcc r10,9

	loadAndAddIfCarry  r11, sp, 6
	loadAndAddIfCarry r12, sp, 2
	mov r0, r10
	loadAndAdd r0,10
	loadAndSub r0,14
	loadAndSub sp,10
	asr r3, r4, #32
	loadMultiply sp,sp,3,7
	storeAndShiftAcc r10,10

	loadAndAddIfCarry  r11, sp, 7
	loadAndAddIfCarry r12, sp, 3
	mov r0, r10
	loadAndAdd r0,11
	loadAndSub r0,15
	loadAndSub sp,11
	asr r3, r4, #32
	storeAndShiftAcc r0,11

	addCarries
	loadRegAndAdd r1,12
	str r5, [r1, #12*4]
	mov r5, r4
	loadRegAndAddNoAcc r1,13
	str r5, [r1, #13*4]
	loadRegAndAddCarry r1,14
	str r5, [r1, #14*4]
	loadRegAndAddCarry r1,15
	str r5, [r1, #15*4]
.endm

.macro loadRegAndAddCarry baseReg, idx
	ldr r5, [\baseReg, #\idx*4]
	adc r5, r5, r7
.endm

.macro loadRegAndAddNoAcc baseReg, idx
	ldr r6, [\baseReg, #\idx*4]
	add r5, r5, r6
.endm

.macro loadRegAndAdd baseReg, idx
	ldr r6, [\baseReg, #\idx*4]
	add r5, r5, r6
	adc r4, r4, r7
.endm

.macro addCarries
	mov r6, r11
	mov r0, r12
	and r6, r6, r0
	neg r6, r6
	add r5, r5, r6
	adc r4, r4, r7
	mov r1, r10
.endm

.macro sumA
	@ to use: r3, r4, r5, r6, r7
	ldm r1, {r0, r1, r2, r3, r4, r5, r6, r7}

	add r4, r4, r0
	adc r5, r5, r1
	adc r6, r6, r2
	adc r7, r7, r3

	sbc r3, r3, r3
	mvn r3, r3
	mov r11, r3

	mov r1, sp
	stm r1, {r4, r5, r6, r7}
.endm

.macro sumB
	@ to use: r3, r4, r5, r6, r7
	mov r1, r9
	ldm r1, {r0, r1, r2, r3, r4, r5, r6, r7}

	add r4, r4, r0
	adc r5, r5, r1
	adc r6, r6, r2
	adc r7, r7, r3

	sbc r3, r3, r3
	mvn r3, r3
	mov r12, r3

	add r1, sp, #16
	stm r1, {r4, r5, r6, r7}
.endm

.global bi_multiply_cm0_256_karatsuba
.type bi_multiply_cm0_256_karatsuba, function
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
	mov r7, r11
	push {r4, r5, r6, r7}
	mov r4, r12
	push {r4}

	sub sp, sp, #64

	mov r8, r1
	mov r9, r2
	mov r10, r0

	sumA
	sumB

	resetAccumulator

	multiplyLow

	resetAccumulator

	multiplyHigh

	resetAccumulator

	multiplyMiddle

	add sp, sp, #64

	pop {r4}
	mov r12, r4
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7, pc}
