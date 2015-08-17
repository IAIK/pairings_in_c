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


.global fp_rdc_cm0_256
.type fp_rdc_cm0_256, %function
.text
.thumb

.macro loadStore
	ldm r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
.endm

.macro subcarry
	ldm r0!, {r3, r4}
	ldm r1!, {r5, r6}
	sbc r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}
.endm

@ a: 			r0
@ prime:		r1
fp_rdc_cm0_256:
	push {r4, r5, r6}

	sub sp, sp, #32

	mov r2, sp

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	ldr r3, =0
	sbc r3, r3, r3

	sub r2, r2, #32
	sub r0, r0, #32

	mov r1, r0
	and r1, r1, r3
	mvn r3, r3
	and r2, r2, r3
	orr r1, r1, r2

	loadStore
	loadStore

	add sp, sp, #32

	pop {r4, r5, r6}
	bx lr
