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
	ldr r5, [r1, #\idxA*4]
	ldr r6, [r2, #\idxB*4]
	tst r5, r6	@ mulacc
.endm

.macro storeAndShiftAcc idx
#ifdef ASM_4CYCLE_MULACC
	nop
	nop
	nop
#endif
	mov r5, r8
	str r5, [r0, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r4
.endm

.macro storeRemAcc idx1, idx2
#ifdef ASM_4CYCLE_MULACC
	nop
	nop
	nop
#endif
	mov r6, r8
	str r6, [r0, #\idx1*4]
	mov r6, r9
	str r6, [r0, #\idx2*4]
.endm


.global bi_multiply_mulacc_cm0_160
.type bi_multiply_mulacc_cm0_160, function
.text 1
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_mulacc_cm0_160:
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	push {r4, r5, r6}

	mov r4, #0
	mov r8, r4
	mov r9, r4
	mov r10, r4

	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6

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

	loadMultiply 4, 1
	loadMultiply 3, 2
	loadMultiply 2, 3
	loadMultiply 1, 4
	storeAndShiftAcc 5

	loadMultiply 4, 2
	loadMultiply 3, 3
	loadMultiply 2, 4
	storeAndShiftAcc 6


	loadMultiply 4, 3
	loadMultiply 3, 4
	storeAndShiftAcc 7

	loadMultiply 4, 4
	storeRemAcc 8, 9

	msr CONTROL, r7

	pop {r4, r5, r6}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	pop {r4, r5, r6, r7}
	bx lr
