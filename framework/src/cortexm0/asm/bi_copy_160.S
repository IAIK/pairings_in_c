.global bi_copy_cm0_160
.type bi_copy_cm0_160, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
bi_copy_cm0_160:
    @ copying 2 words first, then the remaining three
	ldm	r1!, {r2, r3}
	stm r0!, {r2, r3}
	ldm	r1, {r1, r2, r3}
	stm r0!, {r1, r2, r3}

	bx lr
