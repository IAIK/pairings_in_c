@ bi_multiply
#include "config.h"

.macro loadMultiply idxA, idxB
	ldrh r3, [r1, #\idxA*2]
	ldrh r4, [r2, #\idxB*2]
	mul r3, r3, r4
	add r5, r5, r3
	adc r6, r6, r7
.endm

.macro storeAndShiftAcc idx
	strh r5, [r0, #\idx*2]
	lsr r5, r5, #16
	lsl r4, r6, #16
	orr r5, r5, r4
	lsr r6, r6, #16
.endm

.macro storeRemAcc idx
	str r5, [r0, #\idx*4]
.endm


.global bi_multiply_cm0_256_16bit_simple
.type bi_multiply_cm0_256_16bit_simple, function
.text 1
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_cm0_256_16bit_simple:
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	push {r4, r5, r6}

	@ initialize acc
	ldr r5, =0
	mov r6, r5

	@ set r7 to zero
	mov r7, r5

	loadMultiply 0,0
	storeAndShiftAcc 0

	loadMultiply 1,0
	loadMultiply 0,1
	storeAndShiftAcc 1

	loadMultiply 2,0
	loadMultiply 1,1
	loadMultiply 0,2
	storeAndShiftAcc 2

	loadMultiply 3,0
	loadMultiply 2,1
	loadMultiply 1,2
	loadMultiply 0,3
	storeAndShiftAcc 3

	loadMultiply 4,0
	loadMultiply 3,1
	loadMultiply 2,2
	loadMultiply 1,3
	loadMultiply 0,4
	storeAndShiftAcc 4

	loadMultiply 5,0
	loadMultiply 4,1
	loadMultiply 3,2
	loadMultiply 2,3
	loadMultiply 1,4
	loadMultiply 0,5
	storeAndShiftAcc 5

	loadMultiply 6,0
	loadMultiply 5,1
	loadMultiply 4,2
	loadMultiply 3,3
	loadMultiply 2,4
	loadMultiply 1,5
	loadMultiply 0,6
	storeAndShiftAcc 6

	loadMultiply 7,0
	loadMultiply 6,1
	loadMultiply 5,2
	loadMultiply 4,3
	loadMultiply 3,4
	loadMultiply 2,5
	loadMultiply 1,6
	loadMultiply 0,7
	storeAndShiftAcc 7

	loadMultiply 8,0
	loadMultiply 7,1
	loadMultiply 6,2
	loadMultiply 5,3
	loadMultiply 4,4
	loadMultiply 3,5
	loadMultiply 2,6
	loadMultiply 1,7
	loadMultiply 0,8
	storeAndShiftAcc 8

	loadMultiply 9,0
	loadMultiply 8,1
	loadMultiply 7,2
	loadMultiply 6,3
	loadMultiply 5,4
	loadMultiply 4,5
	loadMultiply 3,6
	loadMultiply 2,7
	loadMultiply 1,8
	loadMultiply 0,9
	storeAndShiftAcc 9

	loadMultiply 10,0
	loadMultiply 9,1
	loadMultiply 8,2
	loadMultiply 7,3
	loadMultiply 6,4
	loadMultiply 5,5
	loadMultiply 4,6
	loadMultiply 3,7
	loadMultiply 2,8
	loadMultiply 1,9
	loadMultiply 0,10
	storeAndShiftAcc 10

	loadMultiply 11,0
	loadMultiply 10,1
	loadMultiply 9,2
	loadMultiply 8,3
	loadMultiply 7,4
	loadMultiply 6,5
	loadMultiply 5,6
	loadMultiply 4,7
	loadMultiply 3,8
	loadMultiply 2,9
	loadMultiply 1,10
	loadMultiply 0,11
	storeAndShiftAcc 11

	loadMultiply 12,0
	loadMultiply 11,1
	loadMultiply 10,2
	loadMultiply 9,3
	loadMultiply 8,4
	loadMultiply 7,5
	loadMultiply 6,6
	loadMultiply 5,7
	loadMultiply 4,8
	loadMultiply 3,9
	loadMultiply 2,10
	loadMultiply 1,11
	loadMultiply 0,12
	storeAndShiftAcc 12

	loadMultiply 13,0
	loadMultiply 12,1
	loadMultiply 11,2
	loadMultiply 10,3
	loadMultiply 9,4
	loadMultiply 8,5
	loadMultiply 7,6
	loadMultiply 6,7
	loadMultiply 5,8
	loadMultiply 4,9
	loadMultiply 3,10
	loadMultiply 2,11
	loadMultiply 1,12
	loadMultiply 0,13
	storeAndShiftAcc 13

	loadMultiply 14,0
	loadMultiply 13,1
	loadMultiply 12,2
	loadMultiply 11,3
	loadMultiply 10,4
	loadMultiply 9,5
	loadMultiply 8,6
	loadMultiply 7,7
	loadMultiply 6,8
	loadMultiply 5,9
	loadMultiply 4,10
	loadMultiply 3,11
	loadMultiply 2,12
	loadMultiply 1,13
	loadMultiply 0,14
	storeAndShiftAcc 14

	loadMultiply 15,0
	loadMultiply 14,1
	loadMultiply 13,2
	loadMultiply 12,3
	loadMultiply 11,4
	loadMultiply 10,5
	loadMultiply 9,6
	loadMultiply 8,7
	loadMultiply 7,8
	loadMultiply 6,9
	loadMultiply 5,10
	loadMultiply 4,11
	loadMultiply 3,12
	loadMultiply 2,13
	loadMultiply 1,14
	loadMultiply 0,15
	storeAndShiftAcc 15

	loadMultiply 15,1
	loadMultiply 14,2
	loadMultiply 13,3
	loadMultiply 12,4
	loadMultiply 11,5
	loadMultiply 10,6
	loadMultiply 9,7
	loadMultiply 8,8
	loadMultiply 7,9
	loadMultiply 6,10
	loadMultiply 5,11
	loadMultiply 4,12
	loadMultiply 3,13
	loadMultiply 2,14
	loadMultiply 1,15
	storeAndShiftAcc 16

	loadMultiply 15,2
	loadMultiply 14,3
	loadMultiply 13,4
	loadMultiply 12,5
	loadMultiply 11,6
	loadMultiply 10,7
	loadMultiply 9,8
	loadMultiply 8,9
	loadMultiply 7,10
	loadMultiply 6,11
	loadMultiply 5,12
	loadMultiply 4,13
	loadMultiply 3,14
	loadMultiply 2,15
	storeAndShiftAcc 17

	loadMultiply 15,3
	loadMultiply 14,4
	loadMultiply 13,5
	loadMultiply 12,6
	loadMultiply 11,7
	loadMultiply 10,8
	loadMultiply 9,9
	loadMultiply 8,10
	loadMultiply 7,11
	loadMultiply 6,12
	loadMultiply 5,13
	loadMultiply 4,14
	loadMultiply 3,15
	storeAndShiftAcc 18

	loadMultiply 15,4
	loadMultiply 14,5
	loadMultiply 13,6
	loadMultiply 12,7
	loadMultiply 11,8
	loadMultiply 10,9
	loadMultiply 9,10
	loadMultiply 8,11
	loadMultiply 7,12
	loadMultiply 6,13
	loadMultiply 5,14
	loadMultiply 4,15
	storeAndShiftAcc 19

	loadMultiply 15,5
	loadMultiply 14,6
	loadMultiply 13,7
	loadMultiply 12,8
	loadMultiply 11,9
	loadMultiply 10,10
	loadMultiply 9,11
	loadMultiply 8,12
	loadMultiply 7,13
	loadMultiply 6,14
	loadMultiply 5,15
	storeAndShiftAcc 20

	loadMultiply 15,6
	loadMultiply 14,7
	loadMultiply 13,8
	loadMultiply 12,9
	loadMultiply 11,10
	loadMultiply 10,11
	loadMultiply 9,12
	loadMultiply 8,13
	loadMultiply 7,14
	loadMultiply 6,15
	storeAndShiftAcc 21

	loadMultiply 15,7
	loadMultiply 14,8
	loadMultiply 13,9
	loadMultiply 12,10
	loadMultiply 11,11
	loadMultiply 10,12
	loadMultiply 9,13
	loadMultiply 8,14
	loadMultiply 7,15
	storeAndShiftAcc 22

	loadMultiply 15,8
	loadMultiply 14,9
	loadMultiply 13,10
	loadMultiply 12,11
	loadMultiply 11,12
	loadMultiply 10,13
	loadMultiply 9,14
	loadMultiply 8,15
	storeAndShiftAcc 23

	loadMultiply 15,9
	loadMultiply 14,10
	loadMultiply 13,11
	loadMultiply 12,12
	loadMultiply 11,13
	loadMultiply 10,14
	loadMultiply 9,15
	storeAndShiftAcc 24

	loadMultiply 15,10
	loadMultiply 14,11
	loadMultiply 13,12
	loadMultiply 12,13
	loadMultiply 11,14
	loadMultiply 10,15
	storeAndShiftAcc 25

	loadMultiply 15,11
	loadMultiply 14,12
	loadMultiply 13,13
	loadMultiply 12,14
	loadMultiply 11,15
	storeAndShiftAcc 26

	loadMultiply 15,12
	loadMultiply 14,13
	loadMultiply 13,14
	loadMultiply 12,15
	storeAndShiftAcc 27

	loadMultiply 15,13
	loadMultiply 14,14
	loadMultiply 13,15
	storeAndShiftAcc 28

	loadMultiply 15,14
	loadMultiply 14,15
	storeAndShiftAcc 29

	loadMultiply 15,15
	storeRemAcc 15


	@mov sp, r10

	pop {r4, r5, r6}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	mov r11, r7
	pop {r4, r5, r6, r7, pc}
