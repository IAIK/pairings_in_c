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

.macro subcarry
	ldm r1, {r1, r4, r5}
	ldm r3, {r3, r6, r7}
	sbc r1, r1, r3
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r1, r4, r5}
.endm

.macro loadMultiply baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	tst r5, r6						@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadMultiplyR4 baseA, baseB, idxA, idxB
	ldr r4, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	tst r4, r6						@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadMultiplyR7 baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r7, [\baseB, #\idxB*4]
	tst r5, r7						@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro regLoadMultiply regA, regB, baseB, idxB
	ldr \regB, [\baseB, #\idxB*4]
	tst \regA, \regB
.endm

.macro regMultiply regA, regB
	tst \regA, \regB
.endm

.macro multN0StoreMAndShiftAcc baseM, baseMod idxM
	mov r4, r8		@ acc[0]
	mul r4, r4, r0	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	str r4, [\baseM, #\idxM*4]
	ldr r6, [\baseMod, #0]

	tst r4, r6		@ MUL-ACC

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r11	@ acc[2] = 0
.endm

.macro multN0StoreMAndShiftAccR0R6 baseM, baseMod idxM
	mov r6, r8		@ acc[0]
	mul r0, r6, r0	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	str r0, [\baseM, #\idxM*4]
	ldr r6, [\baseMod, #0]

	tst r0, r6		@ MUL-ACC

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r11	@ acc[2] = 0
.endm

.macro storeShiftAcc baseM, idx
	mov r6, r8
	str r6, [\baseM, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r11
.endm

.macro loadStore
	ldm r1, {r1, r2, r3, r4, r5}
	stm r0!, {r1, r2, r3, r4, r5}
.endm

.global fp_mul_monty_mulacc_cm0_160
.type fp_mul_monty_mulacc_cm0_160, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand A
@ r2: operand B
@ r3: modulus
@ 1st element on stack: n0
fp_mul_monty_mulacc_cm0_160:
	@ prolog: save registers
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6
	push {r7}

	sub sp, sp, #20			@ needed for dummy subtract (side-channel)

	@ clear accumulator
	mov r4, #0
	mov r10, r4
	mov r9, r4
	mov r8, r4
	mov r11, r4

	@ i = 0
	@loadMultiply r1, r2, 0, 0			@ a[i] * b[0]
	loadMultiplyR7 r1, r2, 0, 0
	multN0StoreMAndShiftAcc sp, r3, 0	@ m[i] * n[0]

	@ i = 1
	@loadMultiply r1, r2, 0, 1			@ a[j] * b[i-j]
	regLoadMultiply r5, r6, r2, 1		@ a[0] * b[1]
	@loadMultiply sp, r3, 0, 1			@ m[j] * n[i-j]
	regLoadMultiply r4, r6, r3, 1
	@loadMultiplyR7 r1, r2, 1, 0			@ a[i] * b[0]
	regLoadMultiply r7, r5, r1, 1
	multN0StoreMAndShiftAcc sp, r3, 1	@ m[i] * n[0]

	@ i = 2
	regLoadMultiply r5, r6, r2, 1
	regLoadMultiply r7, r5, r1, 2
	regLoadMultiply r4, r6, r3, 1
	loadMultiply sp, r3, 0, 2
	loadMultiply r1, r2, 0, 2
	multN0StoreMAndShiftAcc sp, r3, 2

	@ i = 3
	regLoadMultiply r5, r6, r2, 3
	loadMultiply r1, r2, 2, 1
	loadMultiply r1, r2, 1, 2

	regLoadMultiply r4, r6, r3, 1
	loadMultiply sp, r3, 1, 2
	loadMultiply sp, r3, 0, 3

	regLoadMultiply r7, r5, r1, 3
	multN0StoreMAndShiftAcc sp, r3, 3

	@ i = 4
	regLoadMultiply r5, r6, r2, 1
	loadMultiply r1, r2, 0, 4
	loadMultiply r1, r2, 2, 2
	regLoadMultiply r7, r5, r1, 4

	regLoadMultiply r4, r6, r3, 1
	loadMultiply sp, r3, 1, 3
	loadMultiplyR4 sp, r3, 2, 2
	loadMultiplyR7 sp, r3, 0, 4

	loadMultiply r1, r2, 1, 3
	multN0StoreMAndShiftAccR0R6 sp, r3, 4

	@ i = 5
	regLoadMultiply r0, r6, r3, 1
	regLoadMultiply r5, r0, r2, 4
	loadMultiply r1, r2, 2, 3
	loadMultiply r1, r2, 3, 2

	regLoadMultiply r4, r6, r3, 3
	loadMultiplyR4 sp, r3, 3, 2
	regLoadMultiply r7, r5, sp, 1

	loadMultiply r1, r2, 4, 1		@ a[4] * b[1]
	storeShiftAcc sp, 0

	@ i = 6
	regLoadMultiply r5, r6, r2, 2
	regLoadMultiply r0, r5, r1, 2
	@loadMultiply sp, r3, 2, 4
	regLoadMultiply r7, r5, sp, 2
	regLoadMultiply r4, r6, r3, 3
	loadMultiplyR4 sp, r3, 4, 2
	loadMultiply r1, r2, 3, 3
	storeShiftAcc sp, 1

	@ i = 7
	regMultiply r5, r0
	regLoadMultiply r7, r5, sp, 3
	regLoadMultiply r4, r6, r3, 3
	loadMultiply r1, r2, 4, 3
	storeShiftAcc sp, 2

	@ i = 8
	regMultiply r5, r0
	regMultiply r4, r7
	storeShiftAcc sp, 3

	@ i = 9 .. store last element
	mov r5, r8
	str r5, [sp, #16]

	@ ready for final subtract (which is done anyway (sidechannel))
	mov r1, sp
	ldr r0, [sp, #56]

    @ subtract the first two words
	ldm	r1!, {r4, r5}
	ldm	r3!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry

	mov r2, #0
	sbc r2, r2, r2
	mov r3, r9
	sub r3, r3, #1
	and r2, r2, r3

	sub r0, r0, #20

	mov r3, sp
	and r3, r3, r2
	mvn r1, r2
	and r1, r1, r0

	orr r1, r1, r3

	loadStore

	add sp, sp, #20			@ needed for dummy subtract (side-channel)
	@ deactivate mulacc
	pop {r7}
	msr CONTROL, r7
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7}
	bx lr
