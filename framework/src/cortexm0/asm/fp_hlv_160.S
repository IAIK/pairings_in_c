 .macro addinitial
	ldm r1!, {r4, r5}
	ldm r2!, {r6, r7}
	add r4, r4, r6
	adc r5, r5, r7
	stm r3!, {r4, r5}
.endm

 .macro addcarry
	ldm r1!, {r4, r5}
	ldm r2, {r2, r6, r7}
	adc r4, r4, r2
	adc r5, r5, r6
	ldm r1!, {r6}
	adc r6, r6, r7
	stm r3!, {r4, r5, r6}
.endm

.macro shiftElement current, next
	lsl r6, \next, #31
	lsr \current, \current, #1
	orr \current, \current, r6
.endm

.global fp_hlv_cm0_160
.type fp_hlv_cm0_160, %function
.text
.thumb

fp_hlv_cm0_160:
	push {r4, r5, r6, r7}

	sub sp, sp, #20

	ldr r3, [r1, #0]
	lsl r3, #31
	asr r3, #31
	push {r3}		@ -1 if odd, 0 if even

	add r4, sp, #4
	mvn r5, r3
	and r4, r4, r5
	and r3, r3, r0
	orr r3, r3, r4

	addinitial
	addcarry

	mov r7, #0
	adc r7, r7, r7
	lsl r7, r7, #31
	pop {r5}
	and r7, r7, r5

	sub r1, r1, #20

	mov r4, r0
	and r4, r4, r5
	mvn r5, r5
	and r1, r5, r1
	orr r1, r4, r1

	ldm	r1, {r1, r2, r3, r4, r5}
	shiftElement r1, r2
	shiftElement r2, r3
	shiftElement r3, r4
	shiftElement r4, r5
	lsr r5, r5, #1
	@ integrate carry in last word
	orr r5, r5, r7
	stm r0!, {r1, r2, r3, r4, r5}

	add sp, sp, #20

	pop {r4, r5, r6, r7}
	bx lr
