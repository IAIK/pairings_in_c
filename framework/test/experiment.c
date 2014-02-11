/*
 * experiment.c
 *
 *  Created on: May 28, 2013
 *      Author: thomas
 */

#include "fp/fp.h"
#include "fp/fp2.h"
#include "bigint/bi.h"

int main() {

#if PRECISION == 256
	static const bigint_t a = {0x3738D309, 0xEEF17F2F, 0xDA371D40, 0x4F840389, 0x2CD5A846, 0xB889814C, 0x820350BE, 0xA2D8BE21};

	bigint_t a_monty;
	bigint_t one_monty;
	bigint_t a_one_monty;
	bigint_t result;
	bigint_t minus_one;
	bigint_t minus_one_monty;
	bigint_t neg_a;
	bigint_t neg_a_monty;
	bigint_t a2;
	bigint_t a2_monty;
	bigint_t a_and_a_monty;
	bigint_t monty2_a;
	bigint_t two;
	bigint_t two_monty;

	fp_mul_monty(a_monty, a, MONTY_PRIME.r2);
	fp_mul_monty(one_monty, bi_one, MONTY_PRIME.r2);
	fp_neg(minus_one, bi_one);
	fp_mul_monty(minus_one_monty, minus_one, MONTY_PRIME.r2);
	fp_neg(neg_a, a);
	fp_neg(neg_a_monty, a_monty);
	fp_dbl(a2, a);
	fp_mul_monty(a2_monty, a2, MONTY_PRIME.r2);
	fp_add(a_and_a_monty, a_monty, a_monty);

	fp_copy(two, bi_zero);
	two[0] = 2;

	fp_mul_monty(two_monty, two, MONTY_PRIME.r2);

	fp_mul_monty(monty2_a, two_monty, a_monty);

	print("a:            "); print_value(a, BI_WORDS); print("\n");
	print("-a:           "); print_value(neg_a, BI_WORDS); print("\n");
	print("a monty:      "); print_value(a_monty, BI_WORDS); print("\n");
	print("1 monty:      "); print_value(one_monty, BI_WORDS); print("\n");
	print("-1:           "); print_value(minus_one, BI_WORDS); print("\n");
	print("neg(a monty): "); print_value(neg_a_monty, BI_WORDS);  print("\n");
	print("-1 monty:     "); print_value(minus_one_monty, BI_WORDS); print("\n");
	print("monty(2a):    "); print_value(a2_monty, BI_WORDS); print("\n");
	print("a_monty+a_mty:"); print_value(a_and_a_monty, BI_WORDS); print("\n");
	print("2mty * a_mty: "); print_value(monty2_a, BI_WORDS); print("\n");

	fp_mul_monty(a_one_monty, a_monty, one_monty);

	print("a*1 monty:    "); print_value(a_one_monty, BI_WORDS); print("\n");

	fp_mul_monty(result, a_one_monty, bi_one);
	print("a*1:          "); print_value(result, BI_WORDS); print("\n");

	fp_mul_monty(a_one_monty, a_monty, minus_one_monty);

	print("a*-1 monty:   "); print_value(a_one_monty, BI_WORDS); print("\n");

	fp_mul_monty(result, a_one_monty, bi_one);

	print("a*-1:         "); print_value(result, BI_WORDS); print("\n");

#endif

	return 0;
}
