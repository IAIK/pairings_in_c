.global bi_shift_left_one_cm0_160
.type bi_shift_left_one_cm0_160, %function
.text
.thumb

.macro shiftElement current, next, tmp
	lsr \tmp, \next, #31
	lsl \current, \current, #1
	orr \current, \current, \tmp
.endm

@ res: 			r0
@ operand a:	r1
bi_shift_left_one_cm0_160:
	push {r4, r5, r6, r7}

	ldm	r1, {r1, r2, r3, r4, r5}

	lsr r7, r5, #31
	shiftElement r5, r4, r6
	shiftElement r4, r3, r6
	shiftElement r3, r2, r6
	shiftElement r2, r1, r6
	lsl r1, r1, #1

	stm r0!, {r1, r2, r3, r4, r5}

	pop {r4, r5, r6, r7}
	bx lr
