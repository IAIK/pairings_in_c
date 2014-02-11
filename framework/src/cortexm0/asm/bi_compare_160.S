@ bi_add

.global bi_compare_cm0_160
.type bi_compare_cm0_160, %function
.text
.thumb

.macro compareABFirst baseA, baseB
	ldm	\baseA!, {r2, r3}
	ldm	\baseB!, {r4, r5}

	sub r2, r2, r4
	sbc r3, r3, r5
.endm

.macro compareAB baseA, baseB
	ldm	\baseA!, {r2, r3}
	ldm	\baseB!, {r4, r5}

	sbc r2, r2, r4
	sbc r3, r3, r5
.endm

.macro compareABOne baseA, baseB
	ldm	\baseA!, {r2}
	ldm	\baseB!, {r4}

	sbc r2, r2, r4
.endm

.macro compareABThree baseA, baseB
	ldm	\baseA, {\baseA, r2, r3}
	ldm	\baseB, {\baseB, r4, r5}

	sbc \baseA, \baseA, \baseB
	sbc r2, r2, r4
	sbc r3, r3, r5
.endm

@ operand a:	r0
@ operand b:	r1
bi_compare_cm0_160:
	push {r4, r5, r6}

	compareABFirst r0, r1
	compareAB r0, r1
	compareABOne r0, r1

	mov r6, #0
	sbc r6, r6, r6

	sub r0, r0, #20
	sub r1, r1, #20

	compareABFirst r1, r0
	compareABThree r1, r0

	mov r0, #0
	sbc r0, r0, r0

	asr r6, r6, #31
	lsr r0, r0, #31

	orr r0, r0, r6

	pop {r4, r5, r6}
	bx lr
