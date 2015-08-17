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

.macro loadReg baseA, idxA
	.if \baseA == sp
	ldr r1, [sp, #\idxA*4]
	.else
	mov r1, \baseA
	ldr r1, [r1, #\idxA*4]
	.endif

	mov r7, #0
	add r5, r5, r1
	adc r4, r4, r7
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
	mulacc
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
	mulacc
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

.macro loadStore
	ldm r1, {r1, r2, r3, r4, r5}
	stm r0!, {r1, r2, r3, r4, r5}
.endm

.macro subcarry
	ldm r1!, {r2, r5}
	ldm r3!, {r6, r7}
	sbc r2, r2, r6
	sbc r5, r5, r7
	stm r0!, {r2, r5}
	ldm r1!, {r2}
	ldm r3!, {r6}
	sbc r2, r2, r6
	stm r0!, {r2}
.endm

.macro addcarry
	ldm r1, {r1, r2, r5}
	ldm r3, {r3, r6, r7}
	adc r1, r1, r3
	adc r2, r2, r6
	adc r5, r5, r7
	stm r0!, {r1, r2, r5}
.endm

.global fp_rdc_monty_cm0_160
.type fp_rdc_monty_cm0_160, %function
.text
.thumb

@ Parameters:
@ r0: res
@ r1: operand (2*BI_WORDS length)
@ r2: modulus
@ r3: n0
fp_rdc_monty_cm0_160:
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	sub sp, sp, #20			@ needed for dummy subtract (side-channel)

	@ save pointers to variables in high registers
	mov r9, r0
	mov r10, r1
	mov r11, r2

	@ load n0
	mov r8, r3

	@ reset accumulator
	ldr r3, =0
	mov r4, r3
	mov r5, r3

	loadReg r10, 0						@ t[0]
	multN0StoreMAndShiftAcc sp, r11, 0	@ m[i] * n[0]

	@ i = 1
	loadReg r10, 1
	loadMultiply sp, r11, 0, 1			@ m[j] * n[i-j]
	multN0StoreMAndShiftAcc sp, r11, 1	@ m[i] * n[0]

	@ i = 2
	loadReg r10, 2
	loadMultiply sp, r11, 0, 2
	loadMultiply sp, r11, 1, 1
	multN0StoreMAndShiftAcc sp, r11, 2

	@ i = 3
	loadReg r10, 3
	loadMultiply sp, r11, 0, 3
	loadMultiply sp, r11, 2, 1
	loadMultiply sp, r11, 1, 2
	multN0StoreMAndShiftAcc sp, r11, 3

	@ i = 4
	loadReg r10, 4
	loadMultiply sp, r11, 0, 4
	loadMultiply sp, r11, 1, 3
	loadMultiply sp, r11, 2, 2
	loadMultiply sp, r11, 3, 1
	multN0StoreMAndShiftAcc sp, r11, 4

	@ i = 5
	loadReg r10, 5
	loadMultiply sp, r11, 1, 4
	loadMultiply sp, r11, 2, 3
	loadMultiply sp, r11, 3, 2
	loadMultiply sp, r11, 4, 1
	storeShiftAcc sp, 0

	@ i = 6
	loadReg r10, 6
	loadMultiply sp, r11, 2, 4
	loadMultiply sp, r11, 3, 3
	loadMultiply sp, r11, 4, 2
	storeShiftAcc sp, 1

	@ i = 7
	loadReg r10, 7
	loadMultiply sp, r11, 3, 4
	loadMultiply sp, r11, 4, 3
	storeShiftAcc sp, 2

	@ i = 8
	loadReg r10, 8
	loadMultiply sp, r11, 4, 4
	storeShiftAcc sp, 3

	@ i = 15
	loadReg r10, 9
	str r5, [sp, #16]

	@ final reduction (subtraction result referenced by r9)
	mov r0, r9
	mov r1, sp
	mov r3, r11

	ldm	r1!, {r2, r5}
	ldm	r3!, {r6, r7}
	sub	r2, r2, r6
	sbc r5, r5, r7
	stm r0!, {r2, r5}

	subcarry

	mov r4, #0
	sbc r4, r4, r4

	sub r1, r1, #20
	sub r3, r3, #20

	@ addition result referenced by r10

	mov r0, r10

	ldm	r1!, {r2, r5}
	ldm	r3!, {r6, r7}
	add	r2, r2, r6
	adc r5, r5, r7
	stm r0!, {r2, r5}

	addcarry

	mov r3, #0
	sbc r3, r3, r3

	mov r1, sp
	and r1, r1, r4

	mvn r4, r4
	mvn r2, r3
	and r2, r2, r4
	and r3, r3, r4

	mov r0, r9
	and r3, r3, r0

	mov r0, r10
	and r2, r2, r0

	orr r1, r1, r2
	orr r1, r1, r3

	mov r0, r9

	loadStore

	add sp, sp, #20			@ needed for dummy subtract (side-channel)
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7

	pop {r4, r5, r6, r7}
	bx lr
