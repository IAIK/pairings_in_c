@ bi_multiply_mulacc

.macro loadMultiply idx
	ldr r3, [r1, #\idx*4]
	mul r3, r3, r3			@ mulacc
.endm

.macro loadMultiplyDouble idxA, idxB
	ldr r3, [r1, #\idxA*4]
	ldr r2, [r1, #\idxB*4]
	mul r3, r3, r2			@ mulacc
	mul r3, r3, r2
.endm

.macro storeAndShiftAcc idx
	mov r2, r8
	str r2, [r0, #\idx*4]
	mov r8, r9
	mov r9, r10
	mov r10, r6
.endm

.macro storeRemAcc idx1, idx2
	mov r2, r8
	str r2, [r0, #\idx1*4]
	mov r2, r9
	str r2, [r0, #\idx2*4]
.endm


.global bi_square_mulacc_cm0_256
.type bi_square_mulacc_cm0_256, %function
.text
.thumb

@ res: 			r0
@ operand a:	r1
bi_square_mulacc_cm0_256:
	push {r6, r7}
	mov r2, r8
	mov r6, r9
	mov r7, r10
	push {r2, r6, r7}

	@ activate mulacc
	mrs r7, CONTROL
	add r6, r7, #4
	msr CONTROL, r6

	@ clear accumulator
	ldr r6, =0
	mov r8, r6
	mov r9, r6
	mov r10, r6

	loadMultiply 0
	storeAndShiftAcc 0

	loadMultiplyDouble 1, 0
	storeAndShiftAcc 1

	loadMultiplyDouble 2, 0
	loadMultiply 1
	storeAndShiftAcc 2

	loadMultiplyDouble 3, 0
	loadMultiplyDouble 2, 1
	storeAndShiftAcc 3

	loadMultiplyDouble 4, 0
	loadMultiplyDouble 3, 1
	loadMultiply 2
	storeAndShiftAcc 4

	loadMultiplyDouble 5, 0
	loadMultiplyDouble 4, 1
	loadMultiplyDouble 3, 2
	storeAndShiftAcc 5

	loadMultiplyDouble 6, 0
	loadMultiplyDouble 5, 1
	loadMultiplyDouble 4, 2
	loadMultiply 3
	storeAndShiftAcc 6

	loadMultiplyDouble 7, 0
	loadMultiplyDouble 6, 1
	loadMultiplyDouble 5, 2
	loadMultiplyDouble 4, 3
	storeAndShiftAcc 7

	loadMultiplyDouble 7, 1
	loadMultiplyDouble 6, 2
	loadMultiplyDouble 5, 3
	loadMultiply 4
	storeAndShiftAcc 8

	loadMultiplyDouble 7, 2
	loadMultiplyDouble 6, 3
	loadMultiplyDouble 5, 4
	storeAndShiftAcc 9

	loadMultiplyDouble 7, 3
	loadMultiplyDouble 6, 4
	loadMultiply 5
	storeAndShiftAcc 10

	loadMultiplyDouble 7, 4
	loadMultiplyDouble 6, 5
	storeAndShiftAcc 11

	loadMultiplyDouble 7, 5
	loadMultiply 6
	storeAndShiftAcc 12

	loadMultiplyDouble 7, 6
	storeAndShiftAcc 13

	loadMultiply 7
	storeRemAcc 14, 15

	@ deactivate mulacc
	msr CONTROL, r7

	pop {r2, r6, r7}
	mov r8, r2
	mov r9, r6
	mov r10, r7
	pop {r6, r7}
	bx lr
