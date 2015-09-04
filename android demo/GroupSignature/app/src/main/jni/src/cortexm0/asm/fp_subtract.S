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


.global fp_subtract_cm0_256
.type fp_subtract_cm0_256, %function
.text
.thumb

.macro addcarry
	ldm r0!, {r4, r5}
	ldm r3!, {r6, r7}
	adc r4, r4, r6
	adc r5, r5, r7
	stm r1!, {r4, r5}
.endm

.macro subcarry
	ldm r1!, {r4, r5}
	ldm r2!, {r6, r7}
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}
.endm

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
fp_subtract_cm0_256:
	push {r4, r5, r6, r7}

	sub sp, sp, #32

    @ subtract the first two words
	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	ldr r7, =0
	sbc r7, r7, r7

	sub r0, r0, #32

	and r0, r0, r7
	mvn r7, r7
	mov r1, sp
	and r1, r1, r7
	orr r0, r0, r1

	mov r1, r0
	ldm	r0!, {r4, r5}
	ldm	r3!, {r6, r7}
	add	r4, r4, r6
	adc r5, r5, r7
	stm r1!, {r4, r5}

	addcarry
	addcarry
	addcarry

	add sp, sp, #32

	pop {r4, r5, r6, r7}
	bx lr

