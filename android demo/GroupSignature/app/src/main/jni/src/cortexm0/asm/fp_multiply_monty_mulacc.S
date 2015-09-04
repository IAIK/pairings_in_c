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
	ldm r1!, {r4, r5}
	ldm r3!, {r6, r7}
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}
.endm

.macro loadMultiply baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	tst r5, r6					@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro multN0StoreMAndShiftAcc baseM, baseMod idxM
	mov r5, r8		@ acc[0]
	mul r5, r5, r0	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	str r5, [\baseM, #\idxM*4]
	ldr r6, [\baseMod, #0]

	tst r5, r6		@ MUL-ACC

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r4	@ acc[2] = 0
.endm

.macro storeShiftAcc baseM, idx
	mov r5, r8
	str r5, [\baseM, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r4
.endm

.macro loadStore
	ldm r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
.endm

.global fp_mul_monty_mulacc_cm0_256
.type fp_mul_monty_mulacc_cm0_256, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand A
@ r2: operand B
@ r3: modulus
@ 1st element on stack: n0
fp_mul_monty_mulacc_cm0_256:
	@ prolog: save registers
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	push {r4, r5, r6}

	sub sp, sp, #32			@ needed for dummy subtract (side-channel)

	@ clear accumulator
	mov r4, #0
	mov r10, r4
	mov r9, r4
	mov r8, r4

	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6

	@ i = 0
	loadMultiply r1, r2, 0, 0			@ a[i] * b[0]
	multN0StoreMAndShiftAcc sp, r3, 0	@ m[i] * n[0]

	@ i = 1
	loadMultiply r1, r2, 0, 1			@ a[j] * b[i-j]
	loadMultiply sp, r3, 0, 1			@ m[j] * n[i-j]
	loadMultiply r1, r2, 1, 0			@ a[i] * b[0]
	multN0StoreMAndShiftAcc sp, r3, 1	@ m[i] * n[0]

	@ i = 2
	loadMultiply r1, r2, 0, 2
	loadMultiply sp, r3, 0, 2
	loadMultiply r1, r2, 1, 1
	loadMultiply sp, r3, 1, 1
	loadMultiply r1, r2, 2, 0
	multN0StoreMAndShiftAcc sp, r3, 2

	@ i = 3
	loadMultiply r1, r2, 0, 3
	loadMultiply sp, r3, 0, 3
	loadMultiply r1, r2, 2, 1
	loadMultiply sp, r3, 2, 1
	loadMultiply r1, r2, 1, 2
	loadMultiply sp, r3, 1, 2
	loadMultiply r1, r2, 3, 0
	multN0StoreMAndShiftAcc sp, r3, 3

	@ i = 4
	loadMultiply r1, r2, 0, 4
	loadMultiply sp, r3, 0, 4
	loadMultiply r1, r2, 1, 3
	loadMultiply sp, r3, 1, 3
	loadMultiply r1, r2, 2, 2
	loadMultiply sp, r3, 2, 2
	loadMultiply r1, r2, 3, 1
	loadMultiply sp, r3, 3, 1
	loadMultiply r1, r2, 4, 0
	multN0StoreMAndShiftAcc sp, r3, 4

	@ i = 5
	loadMultiply r1, r2, 0, 5
	loadMultiply sp, r3, 0, 5
	loadMultiply r1, r2, 1, 4
	loadMultiply sp, r3, 1, 4
	loadMultiply r1, r2, 2, 3
	loadMultiply sp, r3, 2, 3
	loadMultiply r1, r2, 3, 2
	loadMultiply sp, r3, 3, 2
	loadMultiply r1, r2, 4, 1
	loadMultiply sp, r3, 4, 1
	loadMultiply r1, r2, 5, 0
	multN0StoreMAndShiftAcc sp, r3, 5

	@ i = 6
	loadMultiply r1, r2, 0, 6
	loadMultiply sp, r3, 0, 6
	loadMultiply r1, r2, 1, 5
	loadMultiply sp, r3, 1, 5
	loadMultiply r1, r2, 2, 4
	loadMultiply sp, r3, 2, 4
	loadMultiply r1, r2, 3, 3
	loadMultiply sp, r3, 3, 3
	loadMultiply r1, r2, 4, 2
	loadMultiply sp, r3, 4, 2
	loadMultiply r1, r2, 5, 1
	loadMultiply sp, r3, 5, 1
	loadMultiply r1, r2, 6, 0
	multN0StoreMAndShiftAcc sp, r3, 6

	@ i = 7
	loadMultiply r1, r2, 0, 7
	loadMultiply sp, r3, 0, 7
	loadMultiply r1, r2, 1, 6
	loadMultiply sp, r3, 1, 6
	loadMultiply r1, r2, 2, 5
	loadMultiply sp, r3, 2, 5
	loadMultiply r1, r2, 3, 4
	loadMultiply sp, r3, 3, 4
	loadMultiply r1, r2, 4, 3
	loadMultiply sp, r3, 4, 3
	loadMultiply r1, r2, 5, 2
	loadMultiply sp, r3, 5, 2
	loadMultiply r1, r2, 6, 1
	loadMultiply sp, r3, 6, 1
	loadMultiply r1, r2, 7, 0
	multN0StoreMAndShiftAcc sp, r3, 7

	@ i = 8
	loadMultiply r1, r2, 1, 7
	loadMultiply sp, r3, 1, 7
	loadMultiply r1, r2, 2, 6
	loadMultiply sp, r3, 2, 6
	loadMultiply r1, r2, 3, 5
	loadMultiply sp, r3, 3, 5
	loadMultiply r1, r2, 4, 4
	loadMultiply sp, r3, 4, 4
	loadMultiply r1, r2, 5, 3
	loadMultiply sp, r3, 5, 3
	loadMultiply r1, r2, 6, 2
	loadMultiply sp, r3, 6, 2
	loadMultiply r1, r2, 7, 1
	loadMultiply sp, r3, 7, 1
	storeShiftAcc sp, 0

	@ i = 9
	loadMultiply r1, r2, 2, 7
	loadMultiply sp, r3, 2, 7
	loadMultiply r1, r2, 3, 6
	loadMultiply sp, r3, 3, 6
	loadMultiply r1, r2, 4, 5
	loadMultiply sp, r3, 4, 5
	loadMultiply r1, r2, 5, 4
	loadMultiply sp, r3, 5, 4
	loadMultiply r1, r2, 6, 3
	loadMultiply sp, r3, 6, 3
	loadMultiply r1, r2, 7, 2
	loadMultiply sp, r3, 7, 2
	storeShiftAcc sp, 1

	@ i = 10
	loadMultiply r1, r2, 3, 7
	loadMultiply sp, r3, 3, 7
	loadMultiply r1, r2, 4, 6
	loadMultiply sp, r3, 4, 6
	loadMultiply r1, r2, 5, 5
	loadMultiply sp, r3, 5, 5
	loadMultiply r1, r2, 6, 4
	loadMultiply sp, r3, 6, 4
	loadMultiply r1, r2, 7, 3
	loadMultiply sp, r3, 7, 3
	storeShiftAcc sp, 2

	@ i = 11
	loadMultiply r1, r2, 4, 7
	loadMultiply sp, r3, 4, 7
	loadMultiply r1, r2, 5, 6
	loadMultiply sp, r3, 5, 6
	loadMultiply r1, r2, 6, 5
	loadMultiply sp, r3, 6, 5
	loadMultiply r1, r2, 7, 4
	loadMultiply sp, r3, 7, 4
	storeShiftAcc sp, 3

	@ i = 12
	loadMultiply r1, r2, 5, 7
	loadMultiply sp, r3, 5, 7
	loadMultiply r1, r2, 6, 6
	loadMultiply sp, r3, 6, 6
	loadMultiply r1, r2, 7, 5
	loadMultiply sp, r3, 7, 5
	storeShiftAcc sp, 4

	@ i = 13
	loadMultiply r1, r2, 6, 7
	loadMultiply sp, r3, 6, 7
	loadMultiply r1, r2, 7, 6
	loadMultiply sp, r3, 7, 6
	storeShiftAcc sp, 5

	@ i = 14
	loadMultiply r1, r2, 7, 7
	loadMultiply sp, r3, 7, 7
	storeShiftAcc sp, 6

	@ i = 15 .. store last element
	mov r5, r8
	str r5, [sp, #28]

	@ deactivate mulacc
	msr CONTROL, r7

	@ ready for final subtract (which is done anyway (sideschannel))
	mov r1, sp
	ldr r0, [sp, #60]

    @ subtract the first two words
	ldm	r1!, {r4, r5}
	ldm	r3!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry
	subcarry
	subcarry

	mov r2, #0
	sbc r2, r2, r2
	mov r3, r9
	sub r3, r3, #1
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
	pop {r4, r5, r6}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	pop {r4, r5, r6, r7}
	bx lr
