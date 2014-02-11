@ bi_add

.global bi_compare_cm0_256
.type bi_compare_cm0_256, %function
.text
.thumb
/*
.macro compareOne regA, regB
	cmp \regA, \regB
	mov r6, #0
	sbc r6, r6, r6		@ is set to -1 if A < B

	cmp \regB, \regA
	mov \regB, #0
	sbc \regB, \regB, \regB
	mvn \regA, \regB
	neg \regB, \regB	@ is set to 1 if A > B

	and r7, r7, \regA	@ clear if it needs to be set to one
	orr r7, r7, \regB	@ integrate  1
	orr r7, r7, r6		@ integrate -1
.endm

.macro compareTwo
	ldm	r0!, {r2, r3}
	ldm	r1!, {r4, r5}

	compareOne r2, r4
	compareOne r3, r5
.endm

bi_compare_cm0_256:
	push {r4, r5, r6, r7}

	mov r6, #0
	mov r7, #0

   	compareTwo
	compareTwo
	compareTwo
	compareTwo

	mov r0, r7

	pop {r4, r5, r6, r7}
	bx lr*/


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

@ operand a:	r0
@ operand b:	r1
bi_compare_cm0_256:
	push {r4, r5, r6}

	compareABFirst r0, r1
	compareAB r0, r1
	compareAB r0, r1
	compareAB r0, r1

	mov r6, #0
	sbc r6, r6, r6

	sub r0, r0, #32
	sub r1, r1, #32

	compareABFirst r1, r0
	compareAB r1, r0
	compareAB r1, r0
	compareAB r1, r0

	mov r0, #0
	sbc r0, r0, r0

	asr r6, r6, #31
	lsr r0, r0, #31

	orr r0, r0, r6

	pop {r4, r5, r6}
	bx lr
