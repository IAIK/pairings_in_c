.global bi_shift_left_one_cm0_256
.type bi_shift_left_one_cm0_256, %function
.text
.thumb

.macro shiftElement current, next, tmp
	lsr \tmp, \next, #31
	lsl \current, \current, #1
	orr \current, \current, \tmp
.endm

@ res: 			r0
@ operand a:	r1
bi_shift_left_one_cm0_256:
	push {r4, r5, r6, r7}

    @ copying 4 words each
	ldm	r1!, {r2, r3, r4, r5}
	lsr r7, r5, #31
	shiftElement r5, r4, r6
	shiftElement r4, r3, r6
	shiftElement r3, r2, r6
	lsl r2, r2, #1

	stm r0!, {r2, r3, r4, r5}
	ldm r1, {r1, r2, r3, r4}

	shiftElement r4, r3, r5
	shiftElement r3, r2, r5
	shiftElement r2, r1, r5
	lsl r1, r1, #1
	orr r1, r1, r7
	stm r0!, {r1, r2, r3, r4}

	pop {r4, r5, r6, r7}
	bx lr
