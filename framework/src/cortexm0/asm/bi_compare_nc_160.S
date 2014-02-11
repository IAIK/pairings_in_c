@ bi_add

.global bi_compare_cm0_160_nc
.type bi_compare_cm0_160_nc, %function
.text
.thumb

.macro compareOne
	ldr	r2, [r0, #0]
	ldr	r4, [r1, #0]

	cmp r2, r4
	bhi a_gt_b
	bne a_lt_b
.endm

.macro compareTwo
	ldm	r0!, {r2, r3}
	ldm	r1!, {r4, r5}

	cmp r3, r5
	bhi a_gt_b
	bne a_lt_b

	cmp r2, r4
	bhi a_gt_b
	bne a_lt_b
.endm

.macro subtractAddr
	sub r0, #16
	sub r1, #16
.endm

.macro subtractAddrOne
	sub r0, #12
	sub r1, #12
.endm


@ operand a:	r0
@ operand b:	r1
bi_compare_cm0_160_nc:
	push {r4, r5}

	add r0, #12
	add r1, #12

   	compareTwo
   	subtractAddr
	compareTwo
	subtractAddrOne
	compareOne

	ldr r0, =0
	pop {r4, r5}
	bx lr
a_gt_b:
	ldr r0, =1
	pop {r4, r5}
	bx lr
a_lt_b:
	ldr r0, =0xffffffff
	pop {r4, r5}
	bx lr

