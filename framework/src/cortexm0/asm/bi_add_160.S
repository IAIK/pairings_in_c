@ bi_add

.global bi_add_cm0_160
.type bi_add_cm0_160, %function
.text
.thumb

.macro addcarry
	ldm r1, {r1, r3, r4}
	ldm r2, {r2, r5, r6}
	adc r1, r1, r2
	adc r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r1, r3, r4}
.endm


@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_add_cm0_160:
	push {r4, r5, r6}

    @ adding the first two words
	ldm	r1!, {r3, r4}
	ldm	r2!, {r5, r6}
	add	r3, r3, r5
	adc r4, r4, r6
	stm r0!, {r3, r4}

	addcarry @ adding words 3-5

	ldr r0, =0
	adc r0, r0, r0

	pop {r4, r5, r6}
	bx lr
