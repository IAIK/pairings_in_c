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

.macro loadMultiply baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	mul r5, r5, r6					@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadSquare base, idx
	ldr r5, [\base, #\idx*4]
	mul r5, r5, r5
.endm

.macro loadMultiplyDouble baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	mul r5, r5, r6					@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
	mul r5, r5, r6
.endm

.macro multN0StoreMAndShiftAcc baseM, baseMod idxM
	msr CONTROL, r7	@ switch to normal multiplier

	mov r5, r8		@ acc[0]
	mul r5, r5, r3	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	add r6, r7, #4
	msr CONTROL, r6	@ activate mulacc again

	str r5, [\baseM, #\idxM*4]

	mul r5, r5, r4	@ MUL-ACC

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r11	@ acc[2] = 0
.endm

.macro storeShiftAcc baseM, idx
	mov r5, r8
	str r5, [\baseM, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r11
.endm

.global fp_square_monty_mulacc_cm0_256
.type fp_square_monty_mulacc_cm0_256, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand A
@ r2: modulus
@ r3: n0
fp_square_monty_mulacc_cm0_256:
	@ prolog: save registers
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	@ clear accumulator
	mov r7, #0
	mov r10, r7
	mov r9, r7
	mov r8, r7

	@ set constant zero
	mov r11, r7

	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6

	@ load constant n[0]
	ldr r4, [r2, #0]

	@ i = 0
	loadMultiply r1, r1, 0, 0			@ a[i] * a[0]
	multN0StoreMAndShiftAcc r0, r2, 0	@ m[i] * n[0]

	@ i = 1
	loadMultiplyDouble r1, r1, 0, 1		@ a[j] * b[i-j]
	loadMultiply r0, r2, 0, 1			@ m[j] * n[i-j]
	multN0StoreMAndShiftAcc r0, r2, 1	@ m[i] * n[0]

	@ i = 2
	loadMultiplyDouble r1, r1, 0, 2
	loadMultiply r0, r2, 0, 2
	loadSquare r1, 1
	loadMultiply r0, r2, 1, 1
	multN0StoreMAndShiftAcc r0, r2, 2

	@ i = 3
	loadMultiplyDouble r1, r1, 0, 3
	loadMultiply r0, r2, 0, 3
	loadMultiplyDouble r1, r1, 2, 1
	loadMultiply r0, r2, 2, 1
	loadMultiply r0, r2, 1, 2
	multN0StoreMAndShiftAcc r0, r2, 3

	@ i = 4
	loadMultiplyDouble r1, r1, 0, 4
	loadMultiply r0, r2, 0, 4
	loadMultiplyDouble r1, r1, 1, 3
	loadMultiply r0, r2, 1, 3
	loadSquare r1, 2
	loadMultiply r0, r2, 2, 2
	loadMultiply r0, r2, 3, 1
	multN0StoreMAndShiftAcc r0, r2, 4

	@ i = 5
	loadMultiplyDouble r1, r1, 0, 5
	loadMultiply r0, r2, 0, 5
	loadMultiplyDouble r1, r1, 1, 4
	loadMultiply r0, r2, 1, 4
	loadMultiplyDouble r1, r1, 2, 3
	loadMultiply r0, r2, 2, 3
	loadMultiply r0, r2, 3, 2
	loadMultiply r0, r2, 4, 1
	multN0StoreMAndShiftAcc r0, r2, 5

	@ i = 6
	loadMultiplyDouble r1, r1, 0, 6
	loadMultiply r0, r2, 0, 6
	loadMultiplyDouble r1, r1, 1, 5
	loadMultiply r0, r2, 1, 5
	loadMultiplyDouble r1, r1, 2, 4
	loadMultiply r0, r2, 2, 4
	loadSquare r1, 3
	loadMultiply r0, r2, 3, 3
	loadMultiply r0, r2, 4, 2
	loadMultiply r0, r2, 5, 1
	multN0StoreMAndShiftAcc r0, r2, 6

	@ i = 7
	loadMultiplyDouble r1, r1, 0, 7
	loadMultiply r0, r2, 0, 7
	loadMultiplyDouble r1, r1, 1, 6
	loadMultiply r0, r2, 1, 6
	loadMultiplyDouble r1, r1, 2, 5
	loadMultiply r0, r2, 2, 5
	loadMultiplyDouble r1, r1, 3, 4
	loadMultiply r0, r2, 3, 4
	loadMultiply r0, r2, 4, 3
	loadMultiply r0, r2, 5, 2
	loadMultiply r0, r2, 6, 1
	multN0StoreMAndShiftAcc r0, r2, 7

	@ i = 8
	loadMultiplyDouble r1, r1, 1, 7
	loadMultiply r0, r2, 1, 7
	loadMultiplyDouble r1, r1, 2, 6
	loadMultiply r0, r2, 2, 6
	loadMultiplyDouble r1, r1, 3, 5
	loadMultiply r0, r2, 3, 5
	loadSquare r1, 4
	loadMultiply r0, r2, 4, 4
	loadMultiply r0, r2, 5, 3
	loadMultiply r0, r2, 6, 2
	loadMultiply r0, r2, 7, 1
	storeShiftAcc r0, 0

	@ i = 9
	loadMultiplyDouble r1, r1, 2, 7
	loadMultiply r0, r2, 2, 7
	loadMultiplyDouble r1, r1, 3, 6
	loadMultiply r0, r2, 3, 6
	loadMultiplyDouble r1, r1, 4, 5
	loadMultiply r0, r2, 4, 5
	loadMultiply r0, r2, 5, 4
	loadMultiply r0, r2, 6, 3
	loadMultiply r0, r2, 7, 2
	storeShiftAcc r0, 1

	@ i = 10
	loadMultiplyDouble r1, r1, 3, 7
	loadMultiply r0, r2, 3, 7
	loadMultiplyDouble r1, r1, 4, 6
	loadMultiply r0, r2, 4, 6
	loadSquare r1, 5
	loadMultiply r0, r2, 5, 5
	loadMultiply r0, r2, 6, 4
	loadMultiply r0, r2, 7, 3
	storeShiftAcc r0, 2

	@ i = 11
	loadMultiplyDouble r1, r1, 4, 7
	loadMultiply r0, r2, 4, 7
	loadMultiplyDouble r1, r1, 5, 6
	loadMultiply r0, r2, 5, 6
	loadMultiply r0, r2, 6, 5
	loadMultiply r0, r2, 7, 4
	storeShiftAcc r0, 3

	@ i = 12
	loadMultiplyDouble r1, r1, 5, 7
	loadMultiply r0, r2, 5, 7
	loadSquare r1, 6
	loadMultiply r0, r2, 6, 6
	loadMultiply r0, r2, 7, 5
	storeShiftAcc r0, 4

	@ i = 13
	loadMultiplyDouble r1, r1, 6, 7
	loadMultiply r0, r2, 6, 7
	loadMultiply r0, r2, 7, 6
	storeShiftAcc r0, 5

	@ i = 14
	loadSquare r1, 7
	loadMultiply r0, r2, 7, 7
	storeShiftAcc r0, 6

	@ i = 15 .. store last element
	mov r5, r8
	str r5, [r0, #28]

	@ deactivate mulacc
	msr CONTROL, r7

	sub sp, sp, #32			@ needed for dummy subtract (side-channel)

	@ save pointers to result and modulus
	mov r5, r0
	mov r6, r2

	mov r1, r2				@ check if result is larger than modulus
	bl bi_compare_cm0_256
	neg r0, r0
	cmp r0, #1
	bne montysubtract
	mov r4, r9
	cmp r4, #1				@ check acc[1] for overflow bit
	beq montysubtract
	b   montysubtractdummy

montyepilog:
	add sp, sp, #32			@ needed for dummy subtract (side-channel)
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7, pc}

montysubtract:
	mov r0, r5
	mov r1, r5
	mov r2, r6
	bl bi_subtract_cm0_256
	b  montyepilog

montysubtractdummy:
	mov r0, sp
	mov r1, r5
	mov r2, r6
	bl bi_subtract_cm0_256
	b  montyepilog
