/*
 * util.h
 *
 *  Created on: May 2, 2013
 *      Author: thomas
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "types.h"

void print(const char *msg);
void print_value(const word_t *value, const length_t len);
void print_bytes(const byte *value, const length_t len);

int compare_bytes(const byte *a, const byte* b, const length_t len);

unsigned long long get_cycles(void);

#endif /* UTIL_H_ */
