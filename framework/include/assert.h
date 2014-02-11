/*
 * assert.h
 *
 *  Created on: May 2, 2013
 *      Author: thomas
 */

#ifndef ASSERT_H_
#define ASSERT_H_

int assert_true(const int c, const char *msg);
int assert_bytearr_equal(const byte* ex, const byte* tst, const length_t bytes, const char *msg);
int assert_bi_equal(const bigint_t ex, const bigint_t tst, const char *msg);
int assert_bi_equal_var(const word_t *ex, const word_t *tst, const length_t len, const char *msg);
int assert_equal(word_t ex, word_t tst, const char *msg);

#endif /* ASSERT_H_ */
