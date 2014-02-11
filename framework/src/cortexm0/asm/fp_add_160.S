@ fp_add

.global fp_add_cm0_160
.type fp_add_cm0_160, %function
.text
.thumb

.macro addcarry
	ldm r1, {r1, r4, r5}
	ldm r2, {r2, r6, r7}
	adc r1, r1, r2
	adc r4, r4, r6
	adc r5, r5, r7
	stm r0!, {r1, r4, r5}
.endm

.macro subcarry
	ldm r0!, {r4, r5}
	ldm r3, {r3, r6, r7}
	sbc r4, r4, r3
	sbc r5, r5, r6
	ldm r0!, {r6}
	sbc r6, r6, r7
	stm r1!, {r4, r5, r6}
.endm

.macro loadStore
	ldm r1, {r1, r2, r3, r4, r5}
	stm r0!, {r1, r2, r3, r4, r5}
.endm

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
@ modulus: 		r3
fp_add_cm0_160:
	push {r4, r5, r6, r7}

	sub sp, sp, #20

    @ add the first two words
	ldm	r1!, {r4, r5}
	ldm	r2!, {r6, r7}
	add	r4, r4, r6
	adc r5, r5, r7
	stm r0!, {r4, r5}

	addcarry @ add words 3-5

	mov r2, #0
	sbc r2, r2, r2 	@ save carry

	mov r1, sp
	sub r0, r0, #20
	ldm	r0!, {r4, r5}
	ldm	r3!, {r6, r7}
	sub	r4, r4, r6
	sbc r5, r5, r7
	stm r1!, {r4, r5}

	subcarry

	mov r1, #0
	sbc r1, r1, r1	@ carry from subtracting modulus

	sub r0, r0, #20

	and r1, r1, r2
	mov r3, sp
	mvn r4, r1
	and r3, r3, r4
	and r1, r0, r1
	orr r1, r1, r3

	loadStore

	add sp, sp, #20

	pop {r4, r5, r6, r7}
	bx lr
