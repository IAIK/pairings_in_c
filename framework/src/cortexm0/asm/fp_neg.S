/*
 * fp_neg.S
 *
 *  Created on: Jun 10, 2013
 *      Author: thomas
 */

.macro subcarry
	ldm r2!, {r4, r5}
	ldm r1!, {r6, r7}
	orr r3, r3, r6
	orr r3, r3, r7
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}
.endm

.macro loadStore
	ldm r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
.endm

.global fp_neg_cm0_256
.type fp_neg_cm0_256, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
@ modulus:		r2
fp_neg_cm0_256:
	push {r4, r5, r6, r7}
	push {r0}

	sub sp, sp, #32

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

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	mov r5, #0
	mov r4, #0

	cmp r5, r3
	sbc r4, r4, r4
	cmp r3, r5
	sbc r4, r4, r5

	ldr r0, [sp, #32]
	sub r1, r1, #32

	mov r2, sp
	and r2, r2, r4
	mvn r4, r4
	and r1, r1, r4
	orr r1, r1, r2

	loadStore
	loadStore

	add sp, sp, #36

	pop {r4, r5, r6, r7}
	bx lr
