/*
 * aes_cbc.h
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#ifndef AES_CBC_H_
#define AES_CBC_H_

void aes128_cbc_encrypt(byte *res, const byte *data, const byte *key, const length_t len);
void aes128_cbc_decrypt(byte *res, const byte *cipher, const byte *key, const length_t len);

#endif /* AES_CBC_H_ */
