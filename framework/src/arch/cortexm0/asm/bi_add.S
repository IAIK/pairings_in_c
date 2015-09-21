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
.global bi_add_cm0_256
.type bi_add_cm0_256, %function
.text
.thumb

.macro addcarry
	ldm r1!, {r3, r4}
	ldm r2!, {r5, r6}
	adc r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}
.endm


@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_add_cm0_256:
	push {r4, r5, r6}

    @ adding the first two words
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	add	r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}

	addcarry @ adding words 3-4
	addcarry @ adding words 5-6
	addcarry @ adding words 7-8

	ldr r0, =0
	adc r0, r0, r0

	pop {r4, r5, r6}
	bx lr
