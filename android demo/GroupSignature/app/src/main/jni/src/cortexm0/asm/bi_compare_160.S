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

.global bi_compare_cm0_160
.type bi_compare_cm0_160, %function
.text
.thumb

.macro compareABFirst baseA, baseB
	ldm	\baseA!, {r2, r3}
	ldm	\baseB!, {r4, r5}

	sub r2, r2, r4
	sbc r3, r3, r5
.endm

.macro compareAB baseA, baseB
	ldm	\baseA!, {r2, r3}
	ldm	\baseB!, {r4, r5}

	sbc r2, r2, r4
	sbc r3, r3, r5
.endm

.macro compareABOne baseA, baseB
	ldm	\baseA!, {r2}
	ldm	\baseB!, {r4}

	sbc r2, r2, r4
.endm

.macro compareABThree baseA, baseB
	ldm	\baseA, {\baseA, r2, r3}
	ldm	\baseB, {\baseB, r4, r5}

	sbc \baseA, \baseA, \baseB
	sbc r2, r2, r4
	sbc r3, r3, r5
.endm

@ operand a:	r0
@ operand b:	r1
bi_compare_cm0_160:
	push {r4, r5, r6}

	compareABFirst r0, r1
	compareAB r0, r1
	compareABOne r0, r1

	mov r6, #0
	sbc r6, r6, r6

	sub r0, r0, #20
	sub r1, r1, #20

	compareABFirst r1, r0
	compareABThree r1, r0

	mov r0, #0
	sbc r0, r0, r0

	asr r6, r6, #31
	lsr r0, r0, #31

	orr r0, r0, r6

	pop {r4, r5, r6}
	bx lr
