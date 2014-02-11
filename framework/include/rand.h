/*
 * rand.h
 *
 *  Created on: May 23, 2013
 *      Author: thomas
 */

#ifndef RAND_H_
#define RAND_H_

/**
 * Returns the specified number of bytes in the buffer.
 * @param buf the buffer to filled with random bytes
 * @param size number of random bytes to generate
 */
void cprng_get_bytes(void *buf, length_t size);

#endif /* RAND_H_ */
