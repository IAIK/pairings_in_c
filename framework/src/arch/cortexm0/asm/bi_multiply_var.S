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
.global bi_multiply_cm0_var
.type bi_multiply_cm0_var, %function
.text
.thumb

@ r0: target
@ r1: op A
@ r2: op B
@ r3: length A
@ 1st element on stack: length B
bi_multiply_cm0_var:
	@ function prolog (push elements to stack)
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	@ get second length argument from stack
	ldr r4, [sp, #36]	@ before the function prolog, the 5th parameter was top on stack

	@ clear target
	push {r0, r1, r2, r3} @ save arguments
	mov r1, r4
	add r1, r1, r3
	bl bi_clear_var_std
	pop {r0, r1, r2, r3}

	@ adjust lengths of operands (multiply by 4)
	lsl r3, r3, #2
	lsl r4, r4, #2
	mov r8, r3	@ boundary inner loop
	mov r9, r4	@ boundary outer loop

	@ start multiplication
	ldr r7, =0	@ reset outer loop index

outer_loop:

	ldr r6, =0	@ reset inner loop index
	mov r3, r6  @ reset carry
	mov r11, r7 @ backup outer loop index
inner_loop:
	mov r10, r6 @ backup inner loop index

	@ do the actual multiplication

	ldr r4, [r1, r6]
	ldr r5, [r2, r7]
	add r6, r6, r7

	ldr r7, =0
	bl multiply_words

	add r5, r5, r3
	adc r4, r4, r7

	ldr r3, [r0, r6]

	add r5, r5, r3
	adc r4, r4, r7

	str r5, [r0, r6]

	mov r3, r4

	@ get outer loop index
	mov r7, r11				@ outer loop index @ r11

	@ adjust inner loop index
	mov r6, r10				@ inner loop index @ r10
	add r6, r6, #4
	mov r5, r8				@ get inner loop boundary
	cmp r5, r6
	bhi inner_loop

end_inner_loop:

	@ store carry word
	add r5, r6, r7
	str r4, [r0, r5]

	@ increment index
	add r7, r7, #4
	mov r4, r9
	cmp r4, r7
	bhi outer_loop

end_outer_loop:

	@ function epilog (pop saved elements from stack)
	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7, pc}


.global multiply_words
.type   multiply_words, %function
.text
.thumb
.code   16
@ Input: r4, r5
@ Output: r4, r5
@ zero: r7
multiply_words:
	push {r0, r1, r2, r3}

	mov r2, r7

	@ low hw1 x low hw2
	uxth r3, r4
	uxth r1, r5

	mul r3, r3, r1

	@ high hw1 x low hw2
	lsr r0, r4, #16

	mul r0, r0, r1
	lsr r1, r0, #16
	lsl r0, r0, #16
	add r3, r3, r0
	adc r2, r2, r1

	@ high hw1 x high hw2
	lsr r0, r4, #16
	lsr r1, r5, #16

	mul r0, r0, r1
	add r2, r2, r0

	@ low hw1 x high hw2
	uxth r0, r4
	mul r0, r0, r1
	lsr r4, r0, #16
	lsl r5, r0, #16
	add r5, r3, r5
	adc r4, r2, r4

	pop {r0, r1, r2, r3}
	bx lr
