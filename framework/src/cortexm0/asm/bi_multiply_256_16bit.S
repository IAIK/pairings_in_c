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

.macro storeAndShiftAcc16 idx
	strh r5, [r0, #\idx*2]
	lsr r5, r5, #16
	lsl r4, r6, #16
	orr r5, r5, r4
	asr r6, r6, #16
.endm

.macro storeAndShiftAcc reg, idx
	str r5, [\reg, #\idx*4]
	mov r5, r6
	mov r6, #0
.endm

.macro storeRemAcc idx
	str r5, [r0, #\idx*4]
.endm

.macro loadAndAdd reg, idx
	ldr r4, [\reg, #\idx*4]
	add r5, r5, r4
	adc r6, r6, r7
.endm

.macro loadAndSub reg, idx
	ldr r4, [\reg, #\idx*4]
	sub r5, r5, r4
	sbc r6, r6, r7
.endm

.macro loadAndAddIfCarry carryReg, opReg, idx
	ldr r4, [\opReg, #\idx*4]
	mov r3, \carryReg
	and r4, r4, r3
	add r5, r5, r4
	adc r6, r6, r7
.endm

.macro addCarries
	mov r3, r9
	mov r4, r10
	and r3, r3, r4
	neg r3, r3
	add r5, r5, r3
	adc r6, r6, r7
.endm

.macro loadAndAdd16 reg, idx
	ldrh r4, [\reg, #\idx*2]
	add r5, r5, r4
	adc r6, r6, r7
.endm

.macro multiplyLow
	loadMultiply r1,r2,0,0
	storeAndShiftAcc16 0

	regLoadMultiply r2,1
	loadMultiply r2,r1,0,1
	storeAndShiftAcc16 1

	regLoadMultiply r1,2
	loadMultiply r1,r2,1,1
	loadMultiply r1,r2,0,2
	storeAndShiftAcc16 2

	regLoadMultiply r2,3
	loadMultiply r2,r1,2,1
	loadMultiply r2,r1,1,2
	loadMultiply r2,r1,0,3
	storeAndShiftAcc16 3

	regLoadMultiply r1,4
	loadMultiply r1,r2,3,1
	loadMultiply r1,r2,2,2
	loadMultiply r1,r2,1,3
	loadMultiply r1,r2,0,4
	storeAndShiftAcc16 4

	regLoadMultiply r2,5
	loadMultiply r2,r1,4,1
	loadMultiply r2,r1,3,2
	loadMultiply r2,r1,2,3
	loadMultiply r2,r1,1,4
	loadMultiply r2,r1,0,5
	storeAndShiftAcc16 5

	regLoadMultiply r1,6
	loadMultiply r1,r2,5,1
	loadMultiply r1,r2,4,2
	loadMultiply r1,r2,3,3
	loadMultiply r1,r2,2,4
	loadMultiply r1,r2,1,5
	loadMultiply r1,r2,0,6
	storeAndShiftAcc16 6

	regLoadMultiply r2,7
	loadMultiply r1,r2,1,6
	loadMultiply r1,r2,2,5
	loadMultiply r1,r2,3,4
	loadMultiply r1,r2,4,3
	loadMultiply r1,r2,5,2
	loadMultiply r1,r2,6,1
	loadMultiply r1,r2,7,0
	storeAndShiftAcc16 7

	add r0,sp,#16

	regLoadMultiply r2,1
	loadMultiply r2,r1,2,6
	loadMultiply r2,r1,3,5
	loadMultiply r2,r1,4,4
	loadMultiply r2,r1,5,3
	loadMultiply r2,r1,6,2
	loadMultiply r2,r1,7,1
	storeAndShiftAcc16 8

	regLoadMultiply r1,2
	loadMultiply r1,r2,3,6
	loadMultiply r1,r2,4,5
	loadMultiply r1,r2,5,4
	loadMultiply r1,r2,6,3
	loadMultiply r1,r2,7,2
	storeAndShiftAcc16 9

	regLoadMultiply r2,3
	loadMultiply r2,r1,4,6
	loadMultiply r2,r1,5,5
	loadMultiply r2,r1,6,4
	loadMultiply r2,r1,7,3
	storeAndShiftAcc16 10

	regLoadMultiply r1,4
	loadMultiply r1,r2,5,6
	loadMultiply r1,r2,6,5
	loadMultiply r1,r2,7,4
	storeAndShiftAcc16 11

	regLoadMultiply r2,5
	loadMultiply r2,r1,6,6
	loadMultiply r2,r1,7,5
	storeAndShiftAcc16 12

	regLoadMultiply r1,6
	loadMultiply r1,r2,7,6
	storeAndShiftAcc16 13

	regLoadMultiply r2,7
	storeRemAcc 7
.endm

.macro multiplyHigh
	loadMultiply r1,r2,8,8
	storeAndShiftAcc16 16

	regLoadMultiply r2,9
	loadMultiply r2,r1,8,9
	storeAndShiftAcc16 17

	regLoadMultiply r1,10
	loadMultiply r1,r2,9,9
	loadMultiply r1,r2,8,10
	storeAndShiftAcc16 18

	regLoadMultiply r2,11
	loadMultiply r2,r1,10,9
	loadMultiply r2,r1,9,10
	loadMultiply r2,r1,8,11
	storeAndShiftAcc16 19

	regLoadMultiply r1,12
	loadMultiply r1,r2,11,9
	loadMultiply r1,r2,10,10
	loadMultiply r1,r2,9,11
	loadMultiply r1,r2,8,12
	storeAndShiftAcc16 20

	regLoadMultiply r2,13
	loadMultiply r2,r1,12,9
	loadMultiply r2,r1,11,10
	loadMultiply r2,r1,10,11
	loadMultiply r2,r1,9,12
	loadMultiply r2,r1,8,13
	storeAndShiftAcc16 21

	regLoadMultiply r1,14
	loadMultiply r1,r2,13,9
	loadMultiply r1,r2,12,10
	loadMultiply r1,r2,11,11
	loadMultiply r1,r2,10,12
	loadMultiply r1,r2,9,13
	loadMultiply r1,r2,8,14
	storeAndShiftAcc16 22

	regLoadMultiply r2,15
	loadMultiply r1,r2,9,14
	loadMultiply r1,r2,10,13
	loadMultiply r1,r2,11,12
	loadMultiply r1,r2,12,11
	loadMultiply r1,r2,13,10
	loadMultiply r1,r2,14,9
	loadMultiply r1,r2,15,8
	storeAndShiftAcc16 23

	regLoadMultiply r2,9
	loadMultiply r2,r1,10,14
	loadMultiply r2,r1,11,13
	loadMultiply r2,r1,12,12
	loadMultiply r2,r1,13,11
	loadMultiply r2,r1,14,10
	loadMultiply r2,r1,15,9
	storeAndShiftAcc16 24

	regLoadMultiply r1,10
	loadMultiply r1,r2,11,14
	loadMultiply r1,r2,12,13
	loadMultiply r1,r2,13,12
	loadMultiply r1,r2,14,11
	loadMultiply r1,r2,15,10
	storeAndShiftAcc16 25

	regLoadMultiply r2,11
	loadMultiply r2,r1,12,14
	loadMultiply r2,r1,13,13
	loadMultiply r2,r1,14,12
	loadMultiply r2,r1,15,11
	storeAndShiftAcc16 26

	regLoadMultiply r1,12
	loadMultiply r1,r2,13,14
	loadMultiply r1,r2,14,13
	loadMultiply r1,r2,15,12
	storeAndShiftAcc16 27

	regLoadMultiply r2,13
	loadMultiply r2,r1,14,14
	loadMultiply r2,r1,15,13
	storeAndShiftAcc16 28

	regLoadMultiply r1,14
	loadMultiply r1,r2,15,14
	storeAndShiftAcc16 29

	regLoadMultiply r2,15
	storeRemAcc 15
.endm

.macro multiplyMiddle

	loadMultiply r1,r1,0,8
	loadAndAdd sp, 8
	loadAndSub r0,8
	loadAndSub r0,0
	storeAndShiftAcc16 8

	loadMultiply r1,r1,1,8
	loadMultiply r1,r1,0,9
	storeAndShiftAcc16 9

	loadMultiply r1,r1,2,8
	loadMultiply r1,r1,1,9
	loadMultiply r1,r1,0,10
	loadAndAdd sp, 9
	loadAndSub r0,9
	loadAndSub r0,1
	storeAndShiftAcc16 10

	loadMultiply r1,r1,3,8
	loadMultiply r1,r1,2,9
	loadMultiply r1,r1,1,10
	loadMultiply r1,r1,0,11
	storeAndShiftAcc16 11

	loadMultiply r1,r1,4,8
	loadMultiply r1,r1,3,9
	loadMultiply r1,r1,2,10
	loadMultiply r1,r1,1,11
	loadMultiply r1,r1,0,12
	loadAndAdd sp, 10
	loadAndSub r0,10
	loadAndSub r0,2
	storeAndShiftAcc16 12

	loadMultiply r1,r1,5,8
	loadMultiply r1,r1,4,9
	loadMultiply r1,r1,3,10
	loadMultiply r1,r1,2,11
	loadMultiply r1,r1,1,12
	loadMultiply r1,r1,0,13
	storeAndShiftAcc16 13

	loadMultiply r1,r1,6,8
	loadMultiply r1,r1,5,9
	loadMultiply r1,r1,4,10
	loadMultiply r1,r1,3,11
	loadMultiply r1,r1,2,12
	loadMultiply r1,r1,1,13
	loadMultiply r1,r1,0,14
	loadAndAdd sp, 11
	loadAndSub r0,11
	loadAndSub r0,3
	storeAndShiftAcc16 14

	loadMultiply r1,r1,7,8
	loadMultiply r1,r1,6,9
	loadMultiply r1,r1,5,10
	loadMultiply r1,r1,4,11
	loadMultiply r1,r1,3,12
	loadMultiply r1,r1,2,13
	loadMultiply r1,r1,1,14
	loadMultiply r1,r1,0,15
	storeAndShiftAcc16 15

	loadMultiply r1,r1,7,9
	loadMultiply r1,r1,6,10
	loadMultiply r1,r1,5,11
	loadMultiply r1,r1,4,12
	loadMultiply r1,r1,3,13
	loadMultiply r1,r1,2,14
	loadMultiply r1,r1,1,15
	loadAndAddIfCarry r9, r1, 4
	loadAndAddIfCarry r10, r1, 0
	loadAndAdd r0,8
	loadAndSub r0,12
	loadAndSub sp,8
	storeAndShiftAcc16 16

	loadMultiply r1,r1,7,10
	loadMultiply r1,r1,6,11
	loadMultiply r1,r1,5,12
	loadMultiply r1,r1,4,13
	loadMultiply r1,r1,3,14
	loadMultiply r1,r1,2,15
	storeAndShiftAcc16 17

	loadMultiply r1,r1,7,11
	loadMultiply r1,r1,6,12
	loadMultiply r1,r1,5,13
	loadMultiply r1,r1,4,14
	loadMultiply r1,r1,3,15
	loadAndAddIfCarry r9, r1, 5
	loadAndAddIfCarry r10, r1, 1
	loadAndAdd r0,9
	loadAndSub r0,13
	loadAndSub sp,9
	storeAndShiftAcc16 18

	loadMultiply r1,r1,7,12
	loadMultiply r1,r1,6,13
	loadMultiply r1,r1,5,14
	loadMultiply r1,r1,4,15
	storeAndShiftAcc16 19

	loadMultiply r1,r1,7,13
	loadMultiply r1,r1,6,14
	loadMultiply r1,r1,5,15
	loadAndAddIfCarry r9, r1, 6
	loadAndAddIfCarry r10, r1, 2
	loadAndAdd r0,10
	loadAndSub r0,14
	loadAndSub sp,10
	storeAndShiftAcc16 20

	loadMultiply r1,r1,7,14
	loadMultiply r1,r1,6,15
	storeAndShiftAcc16 21

	loadMultiply r1,r1,7,15
	loadAndAddIfCarry r9, r1, 7
	loadAndAddIfCarry r10, r1, 3
	loadAndAdd r0,11
	loadAndSub r0,15
	loadAndSub sp,11
	storeAndShiftAcc r0,11

	addCarries
	loadRegAndAdd r0, 12, r4, r5
	str r5, [r0, #12*4]
	loadRegAndAddCarry r0, 13, r4, r5
	str r5, [r0, #13*4]
	loadRegAndAddCarry r0, 14, r4, r5
	str r5, [r0, #14*4]
	loadRegAndAddCarry r0, 15, r4, r5
	str r5, [r0, #15*4]
.endm

.macro loadRegAndAdd baseReg, idx, tmpReg, dstReg
	ldr \tmpReg, [\baseReg, #\idx*4]
	add \dstReg, \dstReg, \tmpReg
.endm

.macro loadRegAndAddCarry baseReg, idx, tmpReg, dstReg
	mov r5, #0
	ldr \tmpReg, [\baseReg, #\idx*4]
	adc \dstReg, \dstReg, \tmpReg
.endm

.macro sumA
	@ to use: r3, r4, r5, r6, r7
	ldr r3, [r1, #0]
	ldr r4, [r1, #16]
	add r4, r3, r4
	str r4, [sp, #0]

	ldr r3, [r1, #4]
	ldr r4, [r1, #20]
	adc r4, r3, r4
	str r4, [sp, #4]

	ldr r3, [r1, #8]
	ldr r4, [r1, #24]
	adc r4, r3, r4
	str r4, [sp, #8]

	ldr r3, [r1, #12]
	ldr r4, [r1, #28]
	adc r4, r3, r4
	str r4, [sp, #12]

	sbc r4, r4, r4
	mvn r4, r4
	mov r9, r4

	@ ignore carry for now (performance evaluation)
.endm

.macro sumB
	@ to use: r3, r4, r5, r6, r7
	ldr r3, [r2, #0]
	ldr r4, [r2, #16]
	add r4, r3, r4
	str r4, [sp, #16]

	ldr r3, [r2, #4]
	ldr r4, [r2, #20]
	adc r4, r3, r4
	str r4, [sp, #20]

	ldr r3, [r2, #8]
	ldr r4, [r2, #24]
	adc r4, r3, r4
	str r4, [sp, #24]

	ldr r3, [r2, #12]
	ldr r4, [r2, #28]
	adc r4, r3, r4
	str r4, [sp, #28]

	sbc r4, r4, r4
	mvn r4, r4
	mov r10, r4
	@str r4, [sp, #32]

	@ ignore carry for now (performance evaluation)
.endm

.global bi_multiply_cm0_256_16bit
.type bi_multiply_cm0_256_16bit, function
.text 1
.thumb

@ res: 			r0
@ operand a:	r1
@ operand b:	r2
bi_multiply_cm0_256_16bit:
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	push {r4, r5, r6}

	sub sp, sp, #64

	mov r8, r0

	@ initialize acc
	ldr r5, =0
	mov r6, r5

	@ set r7 to zero
	mov r7, r5

	multiplyLow

	mov r0, r8

	mov r5, r7
	mov r6, r7

	multiplyHigh

	sumA

	sumB

	mov r1, sp

	mov r5, r7
	mov r6, r7

	multiplyMiddle

	add sp, sp, #64

	pop {r4, r5, r6}
	mov r8, r4
	mov r9, r5
	mov r10, r6
	pop {r4, r5, r6, r7, pc}
