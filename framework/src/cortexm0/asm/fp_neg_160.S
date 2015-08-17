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
.macro subcarry
	ldm r2, {r2, r4, r5}
	ldm r1!, {r6, r7}
	orr r3, r3, r6
	orr r3, r3, r7
	sbc r2, r2, r6
	sbc r4, r4, r7
	ldm r1!, {r6}
	orr r3, r3, r6
	sbc r5, r5, r6
	stm r0!, {r2, r4, r5}
.endm

.macro loadStore
	ldm r1, {r1, r2, r3, r4, r5}
	stm r0!, {r1, r2, r3, r4, r5}
.endm

.global fp_neg_cm0_160
.type fp_neg_cm0_160, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
@ modulus:		r2
fp_neg_cm0_160:
	push {r4, r5, r6, r7}
	push {r0}

	sub sp, sp, #20

	mov r3, #0
	mov r0, sp

    @ subtract the first two words
	ldm	r2!, {r4, r5}
	ldm	r1!, {r6, r7}
	orr r3, r3, r6
	orr r3, r3, r7
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry @ subtract words 3-5

	mov r5, #0
	mov r4, #0

	cmp r5, r3
	sbc r4, r4, r4
	cmp r3, r5
	sbc r4, r4, r5

	ldr r0, [sp, #20]
	sub r1, r1, #20

	mov r2, sp
	and r2, r2, r4
	mvn r4, r4
	and r1, r1, r4
	orr r1, r1, r2

	loadStore

	add sp, sp, #24

	pop {r4, r5, r6, r7}
	bx lr
