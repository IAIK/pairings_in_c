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

.macro loadStore
	ldm r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
.endm

.macro subcarry
	ldm r1!, {r2, r5}
	ldm r3!, {r6, r7}
	sbc r2, r2, r6
	sbc r5, r5, r7
	stm r0!, {r2, r5}
.endm

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
.endm

.macro loadMultiply baseA, baseB, idxA, idxB
	.if \baseA == sp
	ldr r1, [sp, #\idxA*4]
	.else
	mov r1, \baseA
	ldr r1, [r1, #\idxA*4]
	.endif
	mov r2, \baseB
	ldr r2, [r2, #\idxB*4]
#ifdef ASM_UNROLL_MULACC
	mulacc
#else
	bl multiply_acc_words
#endif
.endm

.macro multN0StoreMAndShiftAcc baseM, baseMod idxM
	mov r1, r8		@ n0'
	mul r1, r1, r5	@ n0' * acc[0] mod wordsize

	.if \baseM == sp
	str r1, [sp, #\idxM*4]
	.else
	mov r2, \baseM
	str r1, [r2, #\idxM*4]
	.endif

	mov r2, \baseMod
	ldr r2, [r2, #0]
#ifdef ASM_UNROLL_MULACC
	mulacc
#else
	bl multiply_acc_words
#endif
	mov r5, r4		@ acc[0] = acc[1]
	mov r4, r3		@ acc[1] = acc[2]
	mov r3, #0		@ acc[2] = 0
.endm

.macro storeShiftAcc baseM, idx
	.if \baseM == sp
	str r5, [sp, #\idx*4]
	.else
	mov r1, \baseM
	str r5, [r1, #\idx*4]
	.endif
	mov r5, r4
	mov r4, r3
	mov r3, #0
.endm

.global fp_mul_monty_cm0_256
.type fp_mul_monty_cm0_256, %function
.text
.thumb

@ Parameters:
@ r0: res -> replaced by n0
@ r1: operand A
@ r2: operand B
@ r3: modulus
@ 1st element on stack: n0 -> replaced by res
fp_mul_monty_cm0_256:
	@ prolog: save registers
	#ifdef ASM_UNROLL_MULACC
	push {r4, r5, r6, r7}
	#else
	push {r4, r5, r6, r7, lr}
	#endif
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	sub sp, sp, #32			@ needed for dummy subtract (side-channel)

	@ save pointers to variables in high registers
	mov r9, r1
	mov r10, r2
	mov r11, r3

	@ load n0
	mov r8, r0

	@ reset accumulator
	ldr r3, =0
	mov r4, r3
	mov r5, r3

	@ i = 0
	loadMultiply r9, r10, 0, 0			@ a[i] * b[0]
	multN0StoreMAndShiftAcc sp, r11, 0	@ m[i] * n[0]

	@ i = 1
	loadMultiply r9, r10, 0, 1			@ a[j] * b[i-j]
	loadMultiply sp, r11, 0, 1			@ m[j] * n[i-j]
	loadMultiply r9, r10, 1, 0			@ a[i] * b[0]
	multN0StoreMAndShiftAcc sp, r11, 1	@ m[i] * n[0]

	@ i = 2
	loadMultiply r9, r10, 0, 2
	loadMultiply sp, r11, 0, 2
	loadMultiply r9, r10, 1, 1
	loadMultiply sp, r11, 1, 1
	loadMultiply r9, r10, 2, 0
	multN0StoreMAndShiftAcc sp, r11, 2

	@ i = 3
	loadMultiply r9, r10, 0, 3
	loadMultiply sp, r11, 0, 3
	loadMultiply r9, r10, 2, 1
	loadMultiply sp, r11, 2, 1
	loadMultiply r9, r10, 1, 2
	loadMultiply sp, r11, 1, 2
	loadMultiply r9, r10, 3, 0
	multN0StoreMAndShiftAcc sp, r11, 3

	@ i = 4
	loadMultiply r9, r10, 0, 4
	loadMultiply sp, r11, 0, 4
	loadMultiply r9, r10, 1, 3
	loadMultiply sp, r11, 1, 3
	loadMultiply r9, r10, 2, 2
	loadMultiply sp, r11, 2, 2
	loadMultiply r9, r10, 3, 1
	loadMultiply sp, r11, 3, 1
	loadMultiply r9, r10, 4, 0
	multN0StoreMAndShiftAcc sp, r11, 4

	@ i = 5
	loadMultiply r9, r10, 0, 5
	loadMultiply sp, r11, 0, 5
	loadMultiply r9, r10, 1, 4
	loadMultiply sp, r11, 1, 4
	loadMultiply r9, r10, 2, 3
	loadMultiply sp, r11, 2, 3
	loadMultiply r9, r10, 3, 2
	loadMultiply sp, r11, 3, 2
	loadMultiply r9, r10, 4, 1
	loadMultiply sp, r11, 4, 1
	loadMultiply r9, r10, 5, 0
	multN0StoreMAndShiftAcc sp, r11, 5

	@ i = 6
	loadMultiply r9, r10, 0, 6
	loadMultiply sp, r11, 0, 6
	loadMultiply r9, r10, 1, 5
	loadMultiply sp, r11, 1, 5
	loadMultiply r9, r10, 2, 4
	loadMultiply sp, r11, 2, 4
	loadMultiply r9, r10, 3, 3
	loadMultiply sp, r11, 3, 3
	loadMultiply r9, r10, 4, 2
	loadMultiply sp, r11, 4, 2
	loadMultiply r9, r10, 5, 1
	loadMultiply sp, r11, 5, 1
	loadMultiply r9, r10, 6, 0
	multN0StoreMAndShiftAcc sp, r11, 6

	@ i = 7
	loadMultiply r9, r10, 0, 7
	loadMultiply sp, r11, 0, 7
	loadMultiply r9, r10, 1, 6
	loadMultiply sp, r11, 1, 6
	loadMultiply r9, r10, 2, 5
	loadMultiply sp, r11, 2, 5
	loadMultiply r9, r10, 3, 4
	loadMultiply sp, r11, 3, 4
	loadMultiply r9, r10, 4, 3
	loadMultiply sp, r11, 4, 3
	loadMultiply r9, r10, 5, 2
	loadMultiply sp, r11, 5, 2
	loadMultiply r9, r10, 6, 1
	loadMultiply sp, r11, 6, 1
	loadMultiply r9, r10, 7, 0
	multN0StoreMAndShiftAcc sp, r11, 7

	@ i = 8
	loadMultiply r9, r10, 1, 7
	loadMultiply sp, r11, 1, 7
	loadMultiply r9, r10, 2, 6
	loadMultiply sp, r11, 2, 6
	loadMultiply r9, r10, 3, 5
	loadMultiply sp, r11, 3, 5
	loadMultiply r9, r10, 4, 4
	loadMultiply sp, r11, 4, 4
	loadMultiply r9, r10, 5, 3
	loadMultiply sp, r11, 5, 3
	loadMultiply r9, r10, 6, 2
	loadMultiply sp, r11, 6, 2
	loadMultiply r9, r10, 7, 1
	loadMultiply sp, r11, 7, 1
	storeShiftAcc sp, 0

	@ i = 9
	loadMultiply r9, r10, 2, 7
	loadMultiply sp, r11, 2, 7
	loadMultiply r9, r10, 3, 6
	loadMultiply sp, r11, 3, 6
	loadMultiply r9, r10, 4, 5
	loadMultiply sp, r11, 4, 5
	loadMultiply r9, r10, 5, 4
	loadMultiply sp, r11, 5, 4
	loadMultiply r9, r10, 6, 3
	loadMultiply sp, r11, 6, 3
	loadMultiply r9, r10, 7, 2
	loadMultiply sp, r11, 7, 2
	storeShiftAcc sp, 1

	@ i = 10
	loadMultiply r9, r10, 3, 7
	loadMultiply sp, r11, 3, 7
	loadMultiply r9, r10, 4, 6
	loadMultiply sp, r11, 4, 6
	loadMultiply r9, r10, 5, 5
	loadMultiply sp, r11, 5, 5
	loadMultiply r9, r10, 6, 4
	loadMultiply sp, r11, 6, 4
	loadMultiply r9, r10, 7, 3
	loadMultiply sp, r11, 7, 3
	storeShiftAcc sp, 2

	@ i = 11
	loadMultiply r9, r10, 4, 7
	loadMultiply sp, r11, 4, 7
	loadMultiply r9, r10, 5, 6
	loadMultiply sp, r11, 5, 6
	loadMultiply r9, r10, 6, 5
	loadMultiply sp, r11, 6, 5
	loadMultiply r9, r10, 7, 4
	loadMultiply sp, r11, 7, 4
	storeShiftAcc sp, 3

	@ i = 12
	loadMultiply r9, r10, 5, 7
	loadMultiply sp, r11, 5, 7
	loadMultiply r9, r10, 6, 6
	loadMultiply sp, r11, 6, 6
	loadMultiply r9, r10, 7, 5
	loadMultiply sp, r11, 7, 5
	storeShiftAcc sp, 4

	@ i = 13
	loadMultiply r9, r10, 6, 7
	loadMultiply sp, r11, 6, 7
	loadMultiply r9, r10, 7, 6
	loadMultiply sp, r11, 7, 6
	storeShiftAcc sp, 5

	@ i = 14
	loadMultiply r9, r10, 7, 7
	loadMultiply sp, r11, 7, 7
	storeShiftAcc sp, 6

	@ i = 15 .. store last element

	str r5, [sp, #28]

	#ifdef ASM_UNROLL_MULACC
	ldr r0, [sp, #64]	@ pointer to result
	#else
	ldr r0, [sp, #68]	@ pointer to result
	#endif
	mov r1, sp
	mov r3, r11

    @ subtract the first two words
	ldm	r1!, {r2, r5}
	ldm	r3!, {r6, r7}
	sub	r2, r2, r6
	sbc r5, r5, r7
	stm r0!, {r2, r5}

	subcarry
	subcarry
	subcarry

	mov r2, #0
	sbc r2, r2, r2
	sub r3, r4, #1
	and r2, r2, r3

	sub r0, r0, #32

	mov r3, sp
	and r3, r3, r2
	mvn r1, r2
	and r1, r1, r0

	orr r1, r1, r3

	loadStore
	loadStore

	add sp, sp, #32			@ needed for dummy subtract (side-channel)
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	#ifdef ASM_UNROLL_MULACC
	pop {r4, r5, r6, r7}
	bx lr
	#else
	pop {r4, r5, r6, r7, pc}
	#endif

