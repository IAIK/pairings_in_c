.global bi_clear_cm0_256
.type bi_clear_cm0_256, %function
.text
.thumb

@ res: 			r0
bi_clear_cm0_256:
	ldr r1, =0
	ldr r2, =0
	ldr r3, =0
	stm r0!, {r1, r2, r3}
	stm r0!, {r1, r2, r3}
	stm r0!, {r1, r2}

	bx lr
