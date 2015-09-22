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


.global fp_rdc_cm0_bn158
.type fp_rdc_cm0_bn158, %function
.text
.thumb

.macro loadStore
	ldm r2, {r2, r3, r4, r5, r6}
	stm r0!, {r2, r3, r4, r5, r6}
.endm

.macro subcarry
	ldm r0!, {r3, r4}
	ldm r1!, {r5, r6}
	sbc r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}
.endm

.macro subcarrySingle
	ldm r0!, {r3}
	ldm r1!, {r5}
	sbc r3, r3, r5
	stm r2!, {r3}
.endm

.macro trySubtract

	mov r0, sp
	mov r2, sp
	sub r1, r1, #20

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarrySingle @ subtract word 5

	ldr r5, =0
	sbc r5, r5, r5

	mov r6, r8
	orr r5, r5, r6
	mov r8, r5

	sub r2, r2, #20

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore
.endm

.macro branchSubtract
	bl rdc_cm0_bn158_sub
.endm

@ a: 			r0
@ prime:		r1
fp_rdc_cm0_bn158:
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	push {r4}

	sub sp, sp, #20

	mov r2, sp
	mov r7, r0

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarrySingle @ subtract words 5

	ldr r5, =0
	sbc r5, r5, r5
	mov r8, r5

	sub r2, r2, #20

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore

	branchSubtract
	branchSubtract
	branchSubtract
	branchSubtract
	branchSubtract
	branchSubtract

	add sp, sp, #20

	pop {r4}
	mov r8, r4
	pop {r4, r5, r6, r7, pc}


rdc_cm0_bn158_sub:
	mov r0, sp
	mov r2, sp
	sub r1, r1, #20

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarrySingle @ subtract word 5

	ldr r5, =0
	sbc r5, r5, r5

	mov r6, r8
	orr r5, r5, r6
	mov r8, r5

	sub r2, r2, #20

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore
	bx lr
