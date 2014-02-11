@ bi_subtract

.global bi_subtract_dbllen_cm0_160
.type bi_subtract_dbllen_cm0_160, %function
.text
.thumb

.macro subcarry
	ldm r1!, {r3, r4}
	ldm r2!, {r5, r6}
	sbc r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}
.endm


@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_subtract_dbllen_cm0_160:
	push {r4, r5, r6}

    @ subtract the first two words
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	sub	r3, r3, r5
	sbc r4, r4, r6
	stm r0!, {r3, r4}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8
	subcarry @ subtract words 9-10

	ldr r0, =0
	sbc r0, r0, r0
	neg r0, r0

	pop {r4, r5, r6}
	bx lr
