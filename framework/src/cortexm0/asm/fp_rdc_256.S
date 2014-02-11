/*
 * fp_rdc_256.S
 *
 *  Created on: Aug 12, 2013
 *      Author: thomas
 */

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
