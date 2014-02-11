/*
 * aes_cbc.c
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#include "aes/aes.h"
#include "aes/memxor.h"
#include "types.h"
#include <string.h>

#define BLOCK128 16

const byte iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

/**
 * AES-128 encryption based on CBC mode.
 * Warning: does not support padding.
 */
void aes128_cbc_encrypt(byte *data, const byte *key, const length_t len) {
	byte 		prev_block[16];
	length_t 	num_blocks = len/BLOCK128;
	aes128_ctx_t ctx;

	aes128_init(key, &ctx);

	memcpy(prev_block, iv, BLOCK128);

	while(num_blocks--){
		memxor(data, prev_block, BLOCK128);
		aes128_enc(data, &ctx);
		memcpy(prev_block, data, BLOCK128);
	    data += BLOCK128;
	}
}

/**
 * AES-128 decryption based on CBC mode.
 * Warning: does not support padding.
 */
void aes128_cbc_decrypt(byte *data, const byte *key, const length_t len) {
	byte 		prev_block[16];
	length_t 	num_blocks = len/BLOCK128;
	aes128_ctx_t ctx;

	aes128_init(key, &ctx);

	data += (num_blocks-1)*BLOCK128;

	memcpy(prev_block, iv, BLOCK128);

	while(num_blocks > 1){
		aes128_dec(data, &ctx);
		memxor(data, data-BLOCK128, BLOCK128);
	    data -= BLOCK128;
	    num_blocks--;
	}

	aes128_dec(data, &ctx);
	memxor(data, iv, BLOCK128);
}
