.global bi_copy_cm0_256
.type bi_copy_cm0_256, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
bi_copy_cm0_256:
	push {r4, r5}

    @ copying 4 words each
	ldm	r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}
	ldm	r1!, {r2, r3, r4, r5}
	stm r0!, {r2, r3, r4, r5}

	pop {r4, r5}
	bx lr
