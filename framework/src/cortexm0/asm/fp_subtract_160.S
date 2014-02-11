@ fp_subtract

.global fp_subtract_cm0_160
.type fp_subtract_cm0_160, %function
.text
.thumb

.macro addcarry
	ldm r0, {r0, r4, r5}
	ldm r3, {r3, r6, r7}
	adc r3, r3, r0
	adc r4, r4, r6
	adc r5, r5, r7
	stm r1!, {r3, r4, r5}
.endm

.macro subcarry
	ldm r1, {r1, r4, r5}
	ldm r2, {r2, r6, r7}
	sbc r1, r1, r2
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r1, r4, r5}
.endm

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
fp_subtract_cm0_160:
	push {r4, r5, r6, r7}

	sub sp, sp, #20

    @ subtract the first two words
	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry @ subtract words 3-5

	ldr r7, =0
	sbc r7, r7, r7

	sub r0, r0, #20

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

	add sp, sp, #20

	pop {r4, r5, r6, r7}
	bx lr
