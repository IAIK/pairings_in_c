/*
 * ibe_demo.c
 *
 *  Created on: May 31, 2013
 *      Author: thomas
 */

#include "ibe/bbkem.h"

int main(void) {
	byte key1[16], key2[16];
	bbkem_ciphertext cipher;
	const char *id = "cm0 in public";

	encapsulate_key(key1, &cipher, id);

	decapsulate_key(key2, &cipher, id);
}
