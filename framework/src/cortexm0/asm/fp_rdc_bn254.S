/*
 * fp_rdc_256.S
 *
 *  Created on: Aug 12, 2013
 *      Author: thomas
 */

.global fp_rdc_cm0_bn254
.type fp_rdc_cm0_bn254, %function
.text
.thumb

.macro loadStore
	ldm r2!, {r3, r4, r5, r6}
	stm r0!, {r3, r4, r5, r6}
.endm

.macro subcarry
	ldm r0!, {r3, r4}
	ldm r1!, {r5, r6}
	sbc r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}
.endm

.macro trySubtract

	mov r0, sp
	mov r2, sp
	sub r1, r1, #32

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	ldr r5, =0
	sbc r5, r5, r5

	mov r6, r8
	orr r5, r5, r6
	mov r8, r5

	sub r2, r2, #32

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore
	loadStore
.endm

.macro branchSubtract
	bl rdc_cm0_bn254_sub
.endm

@ a: 			r0
@ prime:		r1
fp_rdc_cm0_bn254:
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	push {r4}

	sub sp, sp, #32

	mov r2, sp
	mov r7, r0

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	ldr r5, =0
	sbc r5, r5, r5
	mov r8, r5


	sub r2, r2, #32

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore
	loadStore

	branchSubtract
	branchSubtract
	branchSubtract
	branchSubtract
	branchSubtract

	add sp, sp, #32

	pop {r4}
	mov r8, r4
	pop {r4, r5, r6, r7, pc}

rdc_cm0_bn254_sub:
	mov r0, sp
	mov r2, sp
	sub r1, r1, #32

    @ subtract the first two words
	ldm	r0!, {r3, r4}
	ldm	r1!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r2!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	ldr r5, =0
	sbc r5, r5, r5

	mov r6, r8
	orr r5, r5, r6
	mov r8, r5

	sub r2, r2, #32

	mov r0, r7

	mov r3, r0
	and r3, r3, r5
	mvn r5, r5
	and r2, r2, r5
	orr r2, r2, r3

	loadStore
	loadStore
	bx lr
