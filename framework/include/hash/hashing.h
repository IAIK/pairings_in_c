/*
 * hashing.h
 *
 *  Created on: May 21, 2013
 *      Author: thomas
 */

#ifndef HASHING_H_
#define HASHING_H_

#include "types.h"

void hash_key(byte *res, fp12_t key);
void hash_id(bigint_t bi, const char* text);

#endif /* HASHING_H_ */
