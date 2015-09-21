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
.global bi_shift_left_one_cm0_256
.type bi_shift_left_one_cm0_256, %function
.text
.thumb

.macro shiftElement current, next, tmp
	lsr \tmp, \next, #31
	lsl \current, \current, #1
	orr \current, \current, \tmp
.endm

@ res: 			r0
@ operand a:	r1
bi_shift_left_one_cm0_256:
	push {r4, r5, r6, r7}

    @ copying 4 words each
	ldm	r1!, {r2, r3, r4, r5}
	lsr r7, r5, #31
	shiftElement r5, r4, r6
	shiftElement r4, r3, r6
	shiftElement r3, r2, r6
	lsl r2, r2, #1

	stm r0!, {r2, r3, r4, r5}
	ldm r1, {r1, r2, r3, r4}

	shiftElement r4, r3, r5
	shiftElement r3, r2, r5
	shiftElement r2, r1, r5
	lsl r1, r1, #1
	orr r1, r1, r7
	stm r0!, {r1, r2, r3, r4}

	pop {r4, r5, r6, r7}
	bx lr
