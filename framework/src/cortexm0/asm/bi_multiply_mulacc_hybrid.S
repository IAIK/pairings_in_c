@ bi_multiply_mulacc
#include "config.h"

.macro mulacc regA, regB
	tst \regA, \regB
.endm

.macro shiftAndStore offset idx
	mov r12, r0
	mov r0, r8
	str r0, [sp, #\offset+\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r11
	mov r0, r12
.endm


.macro shiftAcc
	mov r8, r9
	mov r9, r10
	mov r10, r11
.endm

.macro ProductDiamond offset

	ldm r0, {r0, r1, r2, r3}
	ldm r4, {r4, r5, r6, r7}

	@ clear accumulator
	mov r8, r11
	mov r9, r11
	mov r10, r11

	mulacc r0, r4
	shiftAndStore \offset 0

	mulacc r0, r5
	mulacc r1, r4
	shiftAndStore \offset 1

	mulacc r0, r6
	mulacc r1, r5
	mulacc r2, r4
	shiftAndStore \offset 2

	mulacc r0, r7
	mulacc r1, r6
	mulacc r2, r5
	mulacc r3, r4
	mov r0, r8
	shiftAcc

	mulacc r1, r7
	mulacc r2, r6
	mulacc r3, r5
	mov r1, r8
	shiftAcc

	mulacc r2, r7
	mulacc r3, r6
	mov r2, r8
	shiftAcc

	mulacc r3, r7
	mov r3, r8
	mov r4, r9

	add r5, sp, #\offset + 3*4
	stm r5!, {r0, r1, r2, r3, r4}
.endm

.global bi_multiply_mulacc_hybrid_cm0_256
.type bi_multiply_mulacc_hybrid_cm0_256, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_mulacc_hybrid_cm0_256:
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4, r5, r6, r7}

	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6
	push {r7}

	push {r0, r1, r2}

	sub sp, sp, #128

	ldr r0, [sp, #128+4]
	ldr r4, [sp, #128]

	ProductDiamond 0

	ldr r0, [sp, #128+4]
	add r0, r0, #16
	ldr r4, [sp, #128]

	ProductDiamond 8

	ldr r0, [sp, #128+4]
	ldr r4, [sp, #128]
	add r4, r4, #16

	ProductDiamond 16

	ldr r0, [sp, #128+4]
	ldr r4, [sp, #128]
	add r0, r0, #16
	add r4, r4, #16

	ProductDiamond 24

	@@@@@@@

	mov r0, sp
	ldm r0!, {r1, r2, r3, r4}
	ldr r5, [sp, #128+8]
	stm r5!, {r1, r2, r3, r4}

	add r7, sp, #32
	ldm r0!, {r1, r2}
	ldm r7!, {r3, r4}
	add r1, r1, r3
	adc r2, r2, r4
	stm r5!, {r1, r2}
	ldm r0!, {r1, r2}
	ldm r7!, {r3, r4}
	adc r1, r1, r3
	adc r2, r2, r4
	stm r5!, {r1, r2}

	add r0, sp, #96
	ldm r0!, {r1, r2}
	ldm r7!, {r3, r4}
	adc r1, r1, r3
	adc r2, r2, r4
	/*stm r5!, {r1, r2}
	ldm r0!, {r1, r2}
	ldm r7!, {r3, r4}
	adc r1, r1, r3
	adc r2, r2, r4
	stm r5!, {r1, r2}
	/*ldm r0!, {r1, r2, r3, r4}
	stm r5!, {r1, r2, r3, r4}*/

	add sp, sp, #128+12

	@ deactivate mulacc
	pop {r7}
	msr CONTROL, r7

	pop {r4, r5, r6, r7}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7}
	bx lr
