.global bi_shift_right_one_cm0_160
.type bi_shift_right_one_cm0_160, %function
.text
.thumb

.macro shiftElement current, next
	lsl r6, \next, #31
	lsr \current, \current, #1
	orr \current, \current, r6
.endm

@ res: 			r0
@ operand a:	r1
bi_shift_right_one_cm0_160:
	push {r4, r5, r6}

	ldm	r1, {r1, r2, r3, r4, r5}
	shiftElement r1, r2
	shiftElement r2, r3
	shiftElement r3, r4
	shiftElement r4, r5
	lsr r5, r5, #1
	stm r0!, {r1, r2, r3, r4, r5}

	pop {r4, r5, r6}
	bx lr
