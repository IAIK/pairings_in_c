/*
 * debug.c
 *
 *  Simple assertion framework to verify the correctness of results.
 *
 *  Created on: May 2, 2013
 *      Author: thomas
 */

#include "util.h"
#include "bigint/bi.h"

/**
 * Verifies that the parameter is not equal zero (= true)
 * @param c the parameter that is checked to be true
 * @param msg the message to be printed
 * @return 0 if the parameter is true, 1 otherwise
 */
int assert_true(const int c, const char *msg) {
    if(c) {
    	print(msg);
    	print(": success\n");
        return 0;
    } else {
    	print(msg);
    	print(": failure\n");
        return 1;
    }
}

/**
 * Verifies that two byte arrays are equal
 * @param ex the expected array
 * @param tst the tested array
 * @param length the length of the two arrays
 * @param msg the message to be printed
 * @return 0 if successful, 1 on failure
 */
int assert_bytearr_equal(const byte* ex, const byte* tst, const length_t length, const char *msg) {
    print(msg);
    if(compare_bytes(ex, tst, length)) {
    	print(": failure\n     expected:  ");
    	print_bytes(ex, length);
    	print("\n     actual:  ");
    	print_bytes(tst, length);
        print("\n");
        return 1;
    } else {
        print(": success\n");
        return 0;
    }
}

/**
 * Verifies that two big integers are equal.
 * @param ex the expected big integer
 * @param tst the tested big integer
 * @param msg the message to be printed
 * @return 0 if successful, 1 on failure
 */
int assert_bi_equal(const bigint_t ex, const bigint_t tst, const char *msg) {
    bigint_t t;

    print(msg);
    if(bi_compare(ex, tst)) {
    	print(": failure\n     expected:  ");
    	print_value(ex, BI_WORDS);
    	print("\n     actual:  ");
    	print_value(tst, BI_WORDS);
        print("\n    diff:  ");
        bi_xor(t, tst, ex);
        print_value(t, BI_WORDS);
        print("\n");
        return 1;
    } else {
        print(": success\n");
        return 0;
    }
}

/**
 * Verifies that two big integers of defined length are equal.
 * @param ex the expected big integer
 * @param tst the tested big integer
 * @param len the length of the two big integers
 * @param msg the message to be printed
 * @return 0 if successful, 1 otherwise
 */
int assert_bi_equal_var(const word_t *ex, const word_t *tst, const length_t len, const char *msg) {
    word_t t[len];

    print(msg);
    if(bi_compare_var(ex, tst, len)) {
    	print(": failure\n     expected:  ");
    	print_value(ex, len);
    	print("\n     actual:  ");
    	print_value(tst, len);
        print("\n    diff:  ");
        bi_xor_var(t, tst, ex, len);
        print_value(t, len);
        print("\n");
        return 1;
    } else {
        print(": success\n");
        return 0;
    }
}

/**
 * Verifies that two processor words are equal.
 * @param ex the expected word
 * @param tst the tested word
 * @param msg the message to be printed
 * @return 0 if successful, 1 otherwise
 */
int assert_equal(word_t ex, word_t tst, const char *msg) {
	word_t t;

    print(msg);
    if(ex != tst) {
    	print(": failure\n     expected:  ");
    	print_value(&ex, 1);
    	print("\n     actual:  ");
    	print_value(&tst, 1);
        print("\n    diff:  ");
        t = ex ^ tst;
        print_value(&t, 1);
        print("\n");
        return 1;
    } else {
        print(": success\n");
        return 0;
    }
}
