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
.global bi_subtract_cm0_160
.type bi_subtract_cm0_160, %function
.text
.thumb

.macro subcarry
	ldm r1, {r1, r3, r4}
	ldm r2, {r2, r5, r6}
	sbc r1, r1, r2
	sbc r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r1, r3, r4}
.endm


@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_subtract_cm0_160:
	push {r4, r5, r6}

    @ subtract the first two words
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}

	subcarry @ subtract words 3-5

	ldr r0, =0
	sbc r0, r0, r0
	neg r0, r0

	pop {r4, r5, r6}
	bx lr
