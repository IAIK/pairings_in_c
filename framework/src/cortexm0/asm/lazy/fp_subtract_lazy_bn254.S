@ fp_add
.global fp_subtract_lazy_cm0_bn254
.type fp_subtract_lazy_cm0_bn254, %function
.text
.thumb

.macro addcarry
	ldm r1!, {r4, r5}
	ldm r2!, {r6, r7}
	adc r4, r4, r6
	adc r5, r5, r7
	stm r0!, {r4, r5}
.endm

.macro subcarry
	ldm r1!, {r4, r5}
	ldm r2!, {r6, r7}
	sbc r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}
.endm

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
@ modulus: 		r3
@ multMod:      first element on stack
fp_subtract_lazy_cm0_bn254:
	push {r4, r5, r6, r7}

	sub sp, sp, #32

    @ subtract the first two words
	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r0!, {r4, r5}

	subcarry @ subtract words 3-4
	subcarry @ subtract words 5-6
	subcarry @ subtract words 7-8

	mov r4, #0
	sbc r4, r4, r4 	@ save carry

	ldr r2, [sp, #48]
	sub r0, r0, #32

	mov r1, r0
	mov r5, sp
	and r0, r0, r4		@ we got a carry
	mvn r4, r4
	and r5, r5, r4		@ no carry (result will end up in tmp)
	orr r0, r0, r5

	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	add	r4, r4, r6
	adc r5, r5, r7
	stm r0!, {r4, r5}

	addcarry
	addcarry
	addcarry

	mov r4, #0
	sbc r4, r4, r4 	@ save carry

	mov r2, r3
	sub r0, r0, #32

	mov r1, r0
	mov r5, sp
	and r0, r0, r4		@ no carry
	mvn r4, r4
	and r5, r5, r4		@ carry (result will end up in tmp)
	orr r0, r0, r5

	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	add	r4, r4, r6
	adc r5, r5, r7
	stm r0!, {r4, r5}

	addcarry
	addcarry
	addcarry

	add sp, sp, #32
	pop {r4, r5, r6, r7}
	bx lr
