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
	ldr r7, [\baseA, #\idxA*4]
	mov r6, #1
	tst r7, r6 @ MUL-ACC
.endm

.macro loadRegR3R5 baseA, idxA
	ldr r5, [\baseA, #\idxA*4]
	mov r3, #1
	tst r3, r5 @ MUL-ACC
.endm

.macro loadRegR5 baseA, idxA
	ldr r5, [\baseA, #\idxA*4]
	tst r5, r3 @ MUL-ACC
.endm

.macro addReg reg
	mov r6, #1
	tst r6, \reg
.endm

.macro loadMultiply baseA, baseB, idxA, idxB
	ldr r7, [\baseA, #\idxA*4]
	ldr r6, [\baseB, #\idxB*4]
	tst r7, r6 		@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadMultiplyR4R5 baseA, baseB, idxA, idxB
	ldr r4, [\baseA, #\idxA*4]
	ldr r5, [\baseB, #\idxB*4]
	tst r4, r5 		@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadMultiplyR3R5 baseA, baseB, idxA, idxB
	ldr r3, [\baseA, #\idxA*4]
	ldr r5, [\baseB, #\idxB*4]
	tst r3, r5 		@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro loadMultiplyR0R3 baseA, baseB, idxA, idxB
	ldr r0, [\baseA, #\idxA*4]
	ldr r3, [\baseB, #\idxB*4]
	tst r0, r3 		@ warning: this is interpreted as multiply-accumulate (MUL-ACC)
.endm

.macro regLoadMultiply regA, regB, baseB, idxB
	ldr \regB, [\baseB, #\idxB*4]
	tst \regA, \regB
.endm

.macro regMultiply regA, regB
	tst \regA, \regB
.endm

.macro multN0StoreMAndShiftAcc baseM, baseMod idxM, regDest
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov \regDest, r8		@ acc[0]
	mul \regDest, \regDest, r3	@ n0' * acc[0] mod wordsize	(32-bit multiply)

	str \regDest, [\baseM, #\idxM*4]

	tst \regDest, r0 @ MUL-ACC

#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif

	mov r8, r9		@ acc[0] = acc[1]
	mov r9, r10		@ acc[1] = acc[2]
	mov r10, r11	@ acc[2] = 0
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
	mov r10, r11
.endm

.macro subcarry
	ldm r1!, {r3, r4}
	ldm r2!, {r5, r6}
	sbc	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}
.endm

.macro addcarry
	ldm r1!, {r3, r4}
	ldm r2!, {r5, r6}
	adc r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}
.endm

.macro loadStore
	ldm r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
.endm

.global fp_rdc_monty_cm0_mulacc_256
.type fp_rdc_monty_cm0_mulacc_256, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand (2*BI_WORDS length)
@ r2: modulus
@ r3: n0
fp_rdc_monty_cm0_mulacc_256:
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
	push {r0, r7}

	sub sp, sp, #32			@ needed for dummy subtract (side-channel)

	@ clear accumulator
	mov r4, #0
	mov r10, r4
	mov r9, r4
	mov r8, r4

	@mov r0, #1

	@ i = 0
	ldm r1!, {r0, r5, r7}
	addReg r0
	ldr r0, [r2, #0]
	multN0StoreMAndShiftAcc sp, r2, 0, r4	@ m[i] * n[0]

	@ i = 1
	addReg r5
	regLoadMultiply r4, r5, r2, 1
	multN0StoreMAndShiftAcc sp, r2, 1, r6	@ m[i] * n[0]

	@ i = 2
	@loadMultiply sp, r2, 1, 1
	regMultiply r5, r6
	addReg r7
	@loadMultiply sp, r2, 0, 2
	regLoadMultiply r4, r7, r2, 2
	multN0StoreMAndShiftAcc sp, r2, 2, r6

	@ i = 3
	@loadMultiply sp, r2, 2, 1
	regMultiply r5, r6
	regLoadMultiply r7, r6, sp, 1
	loadReg r1, 0
	@loadMultiply sp, r2, 0, 3
	regLoadMultiply r4, r7, r2, 3
	@loadMultiply sp, r2, 1, 2
	multN0StoreMAndShiftAcc sp, r2, 3, r6

	@ i = 4
	regMultiply r5, r6
	regLoadMultiply r7, r6, sp, 1
	loadReg r1, 1
	loadMultiply sp, r2, 2, 2
	regLoadMultiply r4, r7, r2, 4
	multN0StoreMAndShiftAcc sp, r2, 4, r6

	@ i = 5
	regMultiply r5, r6
	regLoadMultiply r7, r6, sp, 1
	loadReg r1, 2
	loadMultiply sp, r2, 2, 3
	loadMultiply sp, r2, 3, 2
	regLoadMultiply r4, r7, r2, 5
	multN0StoreMAndShiftAcc sp, r2, 5, r6

	@ i = 6
	regMultiply r5, r6
	regLoadMultiply r7, r6, sp, 1
	loadReg r1, 3
	loadMultiply sp, r2, 2, 4
	loadMultiply sp, r2, 3, 3
	loadMultiply sp, r2, 4, 2
	regLoadMultiply r4, r7, r2, 6
	multN0StoreMAndShiftAcc sp, r2, 6, r6

	@ i = 7
	regMultiply r5, r6
	regLoadMultiply r7, r6, sp, 1
	loadReg r1, 4
	loadMultiply sp, r2, 3, 4
	loadMultiply sp, r2, 4, 3
	loadMultiply sp, r2, 2, 5
	regLoadMultiply r4, r7, r2, 7
	loadMultiplyR4R5 sp, r2, 5, 2
	multN0StoreMAndShiftAcc sp, r2, 7, r6

	@ i = 8
	regLoadMultiply r6, r5, r2, 1
	regLoadMultiply r7, r5, sp, 1
	loadRegR3R5 r1, 5
	regLoadMultiply r4, r5, r2, 3
	loadMultiplyR0R3 sp, r2, 2, 6
	loadMultiplyR0R3 sp, r2, 3, 5
	loadMultiplyR0R3 sp, r2, 4, 4
	loadMultiplyR0R3 sp, r2, 6, 2
	storeShiftAcc sp, 0

	@ i = 9
	regMultiply r6, r3
	regLoadMultiply r7, r5, sp, 2
	regLoadMultiply r4, r5, r2, 4
	regLoadMultiply r0, r5, r2, 3
	loadRegR3R5 r1, 6
	loadMultiplyR0R3 sp, r2, 4, 5
	loadMultiplyR0R3 sp, r2, 3, 6
	storeShiftAcc sp, 1

	@ i = 10
	regMultiply r0, r7
	regLoadMultiply r3, r5, sp, 4
	regLoadMultiply r4, r5, r2, 5
	loadRegR3R5 r1, 7
	regLoadMultiply r6, r5, r2, 3
	loadMultiplyR0R3 sp, r2, 6, 4
	storeShiftAcc sp, 2

	@ i = 11
	regLoadMultiply r7, r5, sp, 4
	regMultiply r6, r3
	regLoadMultiply r4, r5, r2, 6
	loadRegR3R5 r1, 8
	regLoadMultiply r0, r3, r2, 5
	storeShiftAcc sp, 3

	@ i = 12
	regMultiply r6, r3
	regMultiply r4, r7
	loadRegR3R5 r1, 9
	regLoadMultiply r0, r4, r2, 6
	storeShiftAcc sp, 4

	@ i = 13
	regMultiply r0, r7
	regMultiply r4, r6
	loadRegR5 r1, 10
	storeShiftAcc sp, 5

	@ i = 14
	loadRegR5 r1, 11
	regMultiply r6, r7
	storeShiftAcc sp, 6

	@ i = 15 .. store last element
	loadRegR5 r1, 12
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r5, r8
	str r5, [sp, #28]

	@sub r1, r1, #64
	@sub r1, r1, #12
	mov r9, r1
	mov r1, sp

	ldr r0, [sp, #32]

	@ final reduction (subtraction result referenced by r8)
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}

	subcarry
	subcarry
	subcarry

	mov r7, #0
	sbc r7, r7, r7

	sub r1, r1, #32
	sub r2, r2, #32
	sub r0, r0, #32

	mov r8, r0

	@ addition result referenced by r9

	mov r0, r9

	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	add	r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}

	addcarry
	addcarry
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
	loadStore

	add sp, sp, #32			@ needed for dummy subtract (side-channel)

	@ deactivate mulacc
	pop {r0, r7}
	msr CONTROL, r7

	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7}
	bx lr
