@ bi_add

.global bi_compare_cm0_256_nc
.type bi_compare_cm0_256_nc, %function
.text
.thumb

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


@ operand a:	r0
@ operand b:	r1
bi_compare_cm0_256_nc:
	push {r4, r5}

	add r0, #24
	add r1, #24

   	compareTwo
   	subtractAddr
	compareTwo
	subtractAddr
	compareTwo
	subtractAddr
	compareTwo

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

