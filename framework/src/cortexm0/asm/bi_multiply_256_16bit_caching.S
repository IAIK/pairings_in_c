@ bi_multiply
#include "config.h"

.macro loadMultiply regA, regB, idxA, idxB
	ldrh r3, [\regA, #\idxA*2]
	ldrh r4, [\regB, #\idxB*2]
	mul r4, r3, r4
	add r5, r5, r4
	adc r6, r6, r7
.endm

.macro regLoadMultiply regB, idxB
	ldrh r4, [\regB, #\idxB*2]
	mul r4, r3, r4
	add r5, r5, r4
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


.global bi_multiply_cm0_256_16bit_caching
.type bi_multiply_cm0_256_16bit_caching, function
.text 1
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_cm0_256_16bit_caching:
	push {r4, r5, r6, r7, lr}

	@ initialize acc
	ldr r5, =0
	mov r6, r5

	@ set r7 to zero
	mov r7, r5

	loadMultiply r1,r2,0,0
	storeAndShiftAcc 0

	regLoadMultiply r2,1
	loadMultiply r2,r1,0,1
	storeAndShiftAcc 1

	regLoadMultiply r1,2
	loadMultiply r1,r2,1,1
	loadMultiply r1,r2,0,2
	storeAndShiftAcc 2

	regLoadMultiply r2,3
	loadMultiply r2,r1,2,1
	loadMultiply r2,r1,1,2
	loadMultiply r2,r1,0,3
	storeAndShiftAcc 3

	regLoadMultiply r1,4
	loadMultiply r1,r2,3,1
	loadMultiply r1,r2,2,2
	loadMultiply r1,r2,1,3
	loadMultiply r1,r2,0,4
	storeAndShiftAcc 4

	regLoadMultiply r2,5
	loadMultiply r2,r1,4,1
	loadMultiply r2,r1,3,2
	loadMultiply r2,r1,2,3
	loadMultiply r2,r1,1,4
	loadMultiply r2,r1,0,5
	storeAndShiftAcc 5

	regLoadMultiply r1,6
	loadMultiply r1,r2,5,1
	loadMultiply r1,r2,4,2
	loadMultiply r1,r2,3,3
	loadMultiply r1,r2,2,4
	loadMultiply r1,r2,1,5
	loadMultiply r1,r2,0,6
	storeAndShiftAcc 6

	regLoadMultiply r2,7
	loadMultiply r2,r1,6,1
	loadMultiply r2,r1,5,2
	loadMultiply r2,r1,4,3
	loadMultiply r2,r1,3,4
	loadMultiply r2,r1,2,5
	loadMultiply r2,r1,1,6
	loadMultiply r2,r1,0,7
	storeAndShiftAcc 7

	regLoadMultiply r1,8
	loadMultiply r1,r2,7,1
	loadMultiply r1,r2,6,2
	loadMultiply r1,r2,5,3
	loadMultiply r1,r2,4,4
	loadMultiply r1,r2,3,5
	loadMultiply r1,r2,2,6
	loadMultiply r1,r2,1,7
	loadMultiply r1,r2,0,8
	storeAndShiftAcc 8

	regLoadMultiply r2,9
	loadMultiply r2,r1,8,1
	loadMultiply r2,r1,7,2
	loadMultiply r2,r1,6,3
	loadMultiply r2,r1,5,4
	loadMultiply r2,r1,4,5
	loadMultiply r2,r1,3,6
	loadMultiply r2,r1,2,7
	loadMultiply r2,r1,1,8
	loadMultiply r2,r1,0,9
	storeAndShiftAcc 9

	regLoadMultiply r1,10
	loadMultiply r1,r2,9,1
	loadMultiply r1,r2,8,2
	loadMultiply r1,r2,7,3
	loadMultiply r1,r2,6,4
	loadMultiply r1,r2,5,5
	loadMultiply r1,r2,4,6
	loadMultiply r1,r2,3,7
	loadMultiply r1,r2,2,8
	loadMultiply r1,r2,1,9
	loadMultiply r1,r2,0,10
	storeAndShiftAcc 10

	regLoadMultiply r2,11
	loadMultiply r2,r1,10,1
	loadMultiply r2,r1,9,2
	loadMultiply r2,r1,8,3
	loadMultiply r2,r1,7,4
	loadMultiply r2,r1,6,5
	loadMultiply r2,r1,5,6
	loadMultiply r2,r1,4,7
	loadMultiply r2,r1,3,8
	loadMultiply r2,r1,2,9
	loadMultiply r2,r1,1,10
	loadMultiply r2,r1,0,11
	storeAndShiftAcc 11

	regLoadMultiply r1,12
	loadMultiply r1,r2,11,1
	loadMultiply r1,r2,10,2
	loadMultiply r1,r2,9,3
	loadMultiply r1,r2,8,4
	loadMultiply r1,r2,7,5
	loadMultiply r1,r2,6,6
	loadMultiply r1,r2,5,7
	loadMultiply r1,r2,4,8
	loadMultiply r1,r2,3,9
	loadMultiply r1,r2,2,10
	loadMultiply r1,r2,1,11
	loadMultiply r1,r2,0,12
	storeAndShiftAcc 12

	regLoadMultiply r2,13
	loadMultiply r2,r1,12,1
	loadMultiply r2,r1,11,2
	loadMultiply r2,r1,10,3
	loadMultiply r2,r1,9,4
	loadMultiply r2,r1,8,5
	loadMultiply r2,r1,7,6
	loadMultiply r2,r1,6,7
	loadMultiply r2,r1,5,8
	loadMultiply r2,r1,4,9
	loadMultiply r2,r1,3,10
	loadMultiply r2,r1,2,11
	loadMultiply r2,r1,1,12
	loadMultiply r2,r1,0,13
	storeAndShiftAcc 13

	regLoadMultiply r1,14
	loadMultiply r1,r2,13,1
	loadMultiply r1,r2,12,2
	loadMultiply r1,r2,11,3
	loadMultiply r1,r2,10,4
	loadMultiply r1,r2,9,5
	loadMultiply r1,r2,8,6
	loadMultiply r1,r2,7,7
	loadMultiply r1,r2,6,8
	loadMultiply r1,r2,5,9
	loadMultiply r1,r2,4,10
	loadMultiply r1,r2,3,11
	loadMultiply r1,r2,2,12
	loadMultiply r1,r2,1,13
	loadMultiply r1,r2,0,14
	storeAndShiftAcc 14

	regLoadMultiply r2,15
	loadMultiply r1,r2,1,14
	loadMultiply r1,r2,2,13
	loadMultiply r1,r2,3,12
	loadMultiply r1,r2,4,11
	loadMultiply r1,r2,5,10
	loadMultiply r1,r2,6,9
	loadMultiply r1,r2,7,8
	loadMultiply r1,r2,8,7
	loadMultiply r1,r2,9,6
	loadMultiply r1,r2,10,5
	loadMultiply r1,r2,11,4
	loadMultiply r1,r2,12,3
	loadMultiply r1,r2,13,2
	loadMultiply r1,r2,14,1
	loadMultiply r1,r2,15,0
	storeAndShiftAcc 15

	regLoadMultiply r2,1
	loadMultiply r2,r1,2,14
	loadMultiply r2,r1,3,13
	loadMultiply r2,r1,4,12
	loadMultiply r2,r1,5,11
	loadMultiply r2,r1,6,10
	loadMultiply r2,r1,7,9
	loadMultiply r2,r1,8,8
	loadMultiply r2,r1,9,7
	loadMultiply r2,r1,10,6
	loadMultiply r2,r1,11,5
	loadMultiply r2,r1,12,4
	loadMultiply r2,r1,13,3
	loadMultiply r2,r1,14,2
	loadMultiply r2,r1,15,1
	storeAndShiftAcc 16

	regLoadMultiply r1,2
	loadMultiply r1,r2,3,14
	loadMultiply r1,r2,4,13
	loadMultiply r1,r2,5,12
	loadMultiply r1,r2,6,11
	loadMultiply r1,r2,7,10
	loadMultiply r1,r2,8,9
	loadMultiply r1,r2,9,8
	loadMultiply r1,r2,10,7
	loadMultiply r1,r2,11,6
	loadMultiply r1,r2,12,5
	loadMultiply r1,r2,13,4
	loadMultiply r1,r2,14,3
	loadMultiply r1,r2,15,2
	storeAndShiftAcc 17

	regLoadMultiply r2,3
	loadMultiply r2,r1,4,14
	loadMultiply r2,r1,5,13
	loadMultiply r2,r1,6,12
	loadMultiply r2,r1,7,11
	loadMultiply r2,r1,8,10
	loadMultiply r2,r1,9,9
	loadMultiply r2,r1,10,8
	loadMultiply r2,r1,11,7
	loadMultiply r2,r1,12,6
	loadMultiply r2,r1,13,5
	loadMultiply r2,r1,14,4
	loadMultiply r2,r1,15,3
	storeAndShiftAcc 18

	regLoadMultiply r1,4
	loadMultiply r1,r2,5,14
	loadMultiply r1,r2,6,13
	loadMultiply r1,r2,7,12
	loadMultiply r1,r2,8,11
	loadMultiply r1,r2,9,10
	loadMultiply r1,r2,10,9
	loadMultiply r1,r2,11,8
	loadMultiply r1,r2,12,7
	loadMultiply r1,r2,13,6
	loadMultiply r1,r2,14,5
	loadMultiply r1,r2,15,4
	storeAndShiftAcc 19

	regLoadMultiply r2,5
	loadMultiply r2,r1,6,14
	loadMultiply r2,r1,7,13
	loadMultiply r2,r1,8,12
	loadMultiply r2,r1,9,11
	loadMultiply r2,r1,10,10
	loadMultiply r2,r1,11,9
	loadMultiply r2,r1,12,8
	loadMultiply r2,r1,13,7
	loadMultiply r2,r1,14,6
	loadMultiply r2,r1,15,5
	storeAndShiftAcc 20

	regLoadMultiply r1,6
	loadMultiply r1,r2,7,14
	loadMultiply r1,r2,8,13
	loadMultiply r1,r2,9,12
	loadMultiply r1,r2,10,11
	loadMultiply r1,r2,11,10
	loadMultiply r1,r2,12,9
	loadMultiply r1,r2,13,8
	loadMultiply r1,r2,14,7
	loadMultiply r1,r2,15,6
	storeAndShiftAcc 21

	regLoadMultiply r2,7
	loadMultiply r2,r1,8,14
	loadMultiply r2,r1,9,13
	loadMultiply r2,r1,10,12
	loadMultiply r2,r1,11,11
	loadMultiply r2,r1,12,10
	loadMultiply r2,r1,13,9
	loadMultiply r2,r1,14,8
	loadMultiply r2,r1,15,7
	storeAndShiftAcc 22

	regLoadMultiply r1,8
	loadMultiply r1,r2,9,14
	loadMultiply r1,r2,10,13
	loadMultiply r1,r2,11,12
	loadMultiply r1,r2,12,11
	loadMultiply r1,r2,13,10
	loadMultiply r1,r2,14,9
	loadMultiply r1,r2,15,8
	storeAndShiftAcc 23

	regLoadMultiply r2,9
	loadMultiply r2,r1,10,14
	loadMultiply r2,r1,11,13
	loadMultiply r2,r1,12,12
	loadMultiply r2,r1,13,11
	loadMultiply r2,r1,14,10
	loadMultiply r2,r1,15,9
	storeAndShiftAcc 24

	regLoadMultiply r1,10
	loadMultiply r1,r2,11,14
	loadMultiply r1,r2,12,13
	loadMultiply r1,r2,13,12
	loadMultiply r1,r2,14,11
	loadMultiply r1,r2,15,10
	storeAndShiftAcc 25

	regLoadMultiply r2,11
	loadMultiply r2,r1,12,14
	loadMultiply r2,r1,13,13
	loadMultiply r2,r1,14,12
	loadMultiply r2,r1,15,11
	storeAndShiftAcc 26

	regLoadMultiply r1,12
	loadMultiply r1,r2,13,14
	loadMultiply r1,r2,14,13
	loadMultiply r1,r2,15,12
	storeAndShiftAcc 27

	regLoadMultiply r2,13
	loadMultiply r2,r1,14,14
	loadMultiply r2,r1,15,13
	storeAndShiftAcc 28

	regLoadMultiply r1,14
	loadMultiply r1,r2,15,14
	storeAndShiftAcc 29

	regLoadMultiply r2,15
	storeRemAcc 15


	@mov sp, r10

	pop {r4, r5, r6, r7, pc}
