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

.macro loadReg baseA, idxA
	ldr r5, [\baseA, #\idxA*4]
	tst r5, r7 @ MUL-ACC
.endm

.macro loadMultiply baseA, baseB, idxA, idxB
	ldr r5, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	tst r5, r6					@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm


.macro multN0StoreMAndShiftAcc baseM, baseMod idxM
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r5, r8		@ acc[0]
	mul r5, r5, r3	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	str r5, [\baseM, #\idxM*4]
	ldr r6, [\baseMod, #0]

	tst r5, r6	@ MUL-ACC

#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r4	@ acc[2] = 0
.endm

.macro storeShiftAcc baseM, idx
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r5, r8
	str r5, [\baseM, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r4
.endm

.macro loadStore
	ldm r1, {r1, r2, r3, r4, r5}
	stm r0!, {r1, r2, r3, r4, r5}
.endm

.macro subcarry
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	sbc	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}
	ldm r1!, {r3}
	ldm r2!, {r5}
	sbc	r3, r3, r5
	stm r0!, {r3}
.endm

.macro addcarry
	ldm r1, {r1, r3, r4}
	ldm r2, {r2, r5, r6}
	adc r1, r1, r2
	adc r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r1, r3, r4}
.endm

.global fp_rdc_monty_cm0_mulacc_160
.type fp_rdc_monty_cm0_mulacc_160, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand (2*BI_WORDS length)
@ r2: modulus
@ r3: n0
fp_rdc_monty_cm0_mulacc_160:
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6
	@ save registers
	mov r6, r10
	push {r4, r5, r6, r7}

	sub sp, sp, #20			@ needed for dummy subtract (side-channel)

	@ clear accumulator
	mov r4, #0
	mov r10, r4
	mov r9, r4
	mov r8, r4

	mov r7, #1

	loadReg r1, 0						@ t[0]
	multN0StoreMAndShiftAcc sp, r2, 0	@ m[i] * n[0]

	@ i = 1
	loadReg r1, 1
	loadMultiply sp, r2, 0, 1			@ m[j] * n[i-j]
	multN0StoreMAndShiftAcc sp, r2, 1	@ m[i] * n[0]

	@ i = 2
	loadReg r1, 2
	loadMultiply sp, r2, 0, 2
	loadMultiply sp, r2, 1, 1
	multN0StoreMAndShiftAcc sp, r2, 2

	@ i = 3
	loadReg r1, 3
	loadMultiply sp, r2, 0, 3
	loadMultiply sp, r2, 2, 1
	loadMultiply sp, r2, 1, 2
	multN0StoreMAndShiftAcc sp, r2, 3

	@ i = 4
	loadReg r1, 4
	loadMultiply sp, r2, 0, 4
	loadMultiply sp, r2, 1, 3
	loadMultiply sp, r2, 2, 2
	loadMultiply sp, r2, 3, 1
	multN0StoreMAndShiftAcc sp, r2, 4

	@ i = 5
	loadReg r1, 5
	loadMultiply sp, r2, 1, 4
	loadMultiply sp, r2, 2, 3
	loadMultiply sp, r2, 3, 2
	loadMultiply sp, r2, 4, 1
	storeShiftAcc sp, 0

	@ i = 6
	loadReg r1, 6
	loadMultiply sp, r2, 2, 4
	loadMultiply sp, r2, 3, 3
	loadMultiply sp, r2, 4, 2
	storeShiftAcc sp, 1

	@ i = 7
	loadReg r1, 7
	loadMultiply sp, r2, 3, 4
	loadMultiply sp, r2, 4, 3
	storeShiftAcc sp, 2

	@ i = 8
	loadReg r1, 8
	loadMultiply sp, r2, 4, 4
	storeShiftAcc sp, 3

	@ i = 9
	loadReg r1, 9
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r5, r8
	str r5, [sp, #16]

	mov r9, r1
	mov r1, sp

	@ final reduction (subtraction result referenced by r8)
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}

	subcarry

	mov r7, #0
	sbc r7, r7, r7

	sub r1, r1, #20
	sub r2, r2, #20
	sub r0, r0, #20

	mov r8, r0

	@ addition result referenced by r9

	mov r0, r9

	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	add	r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}

	addcarry

	mov r3, #0
	sbc r3, r3, r3

	mov r1, sp
	and r1, r1, r7

	mvn r7, r7
	mvn r2, r3
	and r2, r2, r7
	and r3, r3, r7

	mov r5, r8
	and r3, r3, r5

	mov r5, r9
	and r2, r2, r5

	orr r1, r1, r2
	orr r1, r1, r3

	mov r0, r8

	loadStore

	add sp, sp, #20			@ needed for dummy subtract (side-channel)
	pop {r4, r5, r6, r7}
	@ deactivate mulacc
	msr CONTROL, r7
	mov r8, r4
	mov r9, r5
	mov r10, r6
	pop {r4, r5, r6, r7}
	bx lr
