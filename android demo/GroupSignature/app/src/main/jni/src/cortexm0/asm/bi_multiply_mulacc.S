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

.macro loadMultiply idxA, idxB
	ldr r3, [r1, #\idxA*4]
	ldr r4, [r2, #\idxB*4]
	tst r3, r4 @ MUL-ACC
.endm

.macro loadMultiplyOverwriteR1 idxA, idxB
	ldr r1, [r1, #\idxA*4]
	ldr r4, [r2, #\idxB*4]
	tst r1, r4 @ MUL-ACC
.endm

.macro loadMultiplyR6 idxA, idxB
	ldr r4, [r1, #\idxA*4]
	ldr r6, [r2, #\idxB*4]
	tst r4, r6 @ MUL-ACC
.endm

.macro loadMultiplyR3R5 idxA, idxB
	ldr r3, [r1, #\idxA*4]
	ldr r5, [r2, #\idxB*4]
	tst r3, r5 @ MUL-ACC
.endm

.macro regLoadMultiply regA, regB, baseB, idxB
	ldr \regB, [\baseB, #\idxB*4]
	tst \regA, \regB
.endm

.macro regMultiply regA, regB
	tst \regA, \regB
.endm

.macro storeAndShiftAcc idx
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r4, r8
	str r4, [r0, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r11
.endm

.macro storeRemAcc idx1, idx2
#ifdef ASM_4CYCLE_MULACC
    nop
    nop
    nop
#endif
	mov r4, r8
	str r4, [r0, #\idx1*4]
	mov r4, r9
	str r4, [r0, #\idx2*4]
.endm


.global bi_multiply_mulacc_cm0_256
.type bi_multiply_mulacc_cm0_256, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_mulacc_cm0_256:
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

	@ clear accumulator
	ldr r6, =0
	mov r8, r6
	mov r9, r6
	mov r10, r6
	mov r11, r6

	loadMultiplyR3R5 0, 0
	storeAndShiftAcc 0

	regLoadMultiply r5, r6, r1, 1
	regLoadMultiply r3, r7, r2, 1
	storeAndShiftAcc 1

	regLoadMultiply r5, r4, r1, 2
	regMultiply r6, r7
	regLoadMultiply r3, r4, r2, 2
	storeAndShiftAcc 2

	regLoadMultiply r5, r4, r1, 3
	regLoadMultiply r7, r4, r1, 2
	regLoadMultiply r6, r4, r2, 2
	regLoadMultiply r3, r4, r2, 3
	storeAndShiftAcc 3

	regLoadMultiply r5, r4, r1, 4
	regLoadMultiply r7, r4, r1, 3
	regLoadMultiply r6, r4, r2, 3
	regLoadMultiply r3, r4, r2, 4
	loadMultiply 2, 2
	storeAndShiftAcc 4

	regLoadMultiply r5, r4, r1, 5
	regLoadMultiply r7, r4, r1, 4
	regLoadMultiply r6, r4, r2, 4
	regLoadMultiply r3, r4, r2, 3
	loadMultiply 3, 2
	loadMultiply 0, 5
	storeAndShiftAcc 5

	regLoadMultiply r5, r4, r1, 6
	regLoadMultiply r7, r4, r1, 5
	regLoadMultiply r6, r4, r2, 5
	regLoadMultiply r3, r4, r2, 6
	loadMultiply 4, 2
	loadMultiply 3, 3
	loadMultiply 2, 4
	storeAndShiftAcc 6

	regLoadMultiply r3, r4, r2, 5
	loadMultiply 5, 2
	loadMultiply 4, 3
	loadMultiply 3, 4
	regLoadMultiply r5, r3, r1, 7
	regLoadMultiply r7, r5, r1, 6
	regLoadMultiply r6, r7, r2, 6
	loadMultiplyR6 0, 7
	storeAndShiftAcc 7

	regLoadMultiply r3, r4, r2, 1
	regLoadMultiply r5, r4, r2, 2
	regLoadMultiply r7, r4, r1, 2
	regLoadMultiply r6, r4, r1, 1
	loadMultiply 4, 4
	loadMultiply 3, 5
	loadMultiply 5, 3
	storeAndShiftAcc 8

	regLoadMultiply r5, r4, r2, 3
	regLoadMultiply r3, r4, r2, 4
	regLoadMultiply r7, r4, r1, 3
	regLoadMultiply r6, r4, r1, 2
	loadMultiply 4, 5
	loadMultiply 7, 2
	storeAndShiftAcc 9

	regLoadMultiply r3, r4, r2, 3
	regLoadMultiply r5, r4, r2, 4
	regLoadMultiply r7, r4, r1, 4
	regLoadMultiply r6, r4, r1, 3
	loadMultiply 5, 5
	storeAndShiftAcc 10

	regLoadMultiply r6, r4, r1, 4
	loadMultiplyOverwriteR1 7, 4
	regLoadMultiply r5, r2, r2, 5
	regMultiply r3, r7
	storeAndShiftAcc 11

	regMultiply r1, r2
	regMultiply r5, r7
	regMultiply r6, r3
	storeAndShiftAcc 12

	regMultiply r1, r7
	regMultiply r5, r6
	storeAndShiftAcc 13

	regMultiply r1, r6
	storeRemAcc 14, 15

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
