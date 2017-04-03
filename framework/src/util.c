/****************************************************************************
**
** Copyright (C) 2015 Stiftung Secure Information and
**                    Communication Technologies SIC and
**                    Graz University of Technology
** Contact: http://opensource.iaik.tugraz.at
**
**
** Commercial License Usage
** Licensees holding valid commercial licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and SIC. For further information
** contact us at http://opensource.iaik.tugraz.at.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** This software is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this software. If not, see http://www.gnu.org/licenses/.
**
**
****************************************************************************/

#include "util.h"
#include "config.h"
#include <string.h>

const char hex_lookup[] = {'0', '1', '2', '3',
        		 	 '4', '5', '6', '7',
        		 	 '8', '9', 'a', 'b',
        		 	 'c', 'd', 'e', 'f'};

#define UART_BASE 0x40000000
#define TX_OFFSET 20
#define TCTL_OFFSET 0x000004
#define CYCLE_COUNT_ADDR 0xE000ED80

#if (ARCHITECTURE == ARCH_X86 || ARCHITECTURE == ARCH_X86_64)
#include <stdio.h>
#endif

/**
 * Prints a message.
 * @param msg the message to be printed
 */
void print(const char *msg) {
#if (ARCHITECTURE == ARCH_X86 || ARCHITECTURE == ARCH_X86_64)
	printf("%s", msg);
	fflush(stdout);
#elif (ARCHITECTURE == ARCH_CORTEXM0)
	byte *uart = (byte*) UART_BASE;
	byte *txbuf = uart + TX_OFFSET;
	volatile unsigned short *tctl = (unsigned short *) (uart + TCTL_OFFSET);

	int length = strlen(msg);
	int i;
	for (i = 0; i < length; i++) {
		while ((*tctl >> 8) == 0)
			;  // wait for uart to be ready
		*txbuf = *(msg + i);
	}
#endif
}

/**
 * Prints a processor word to a string.
 * @param buffer the buffer that is written to
 * @param w	the processor word
 * @return a pointer to the buffer
 */
char *print_word(char *buffer, const word_t w) {
#if (BYTES_PER_WORD > 2)
    *buffer++ = hex_lookup[ (w >> 28) & 0xF ];
    *buffer++ = hex_lookup[ (w >> 24) & 0xF];
    *buffer++ = hex_lookup[ (w >> 20) & 0xF];
    *buffer++ = hex_lookup[ (w >> 16) & 0xF];
#endif

#if (BYTES_PER_WORD > 1)
	*buffer++ = hex_lookup[(w >> 12) & 0xF ];
	*buffer++ = hex_lookup[(w >> 8) & 0xF];
#endif

	*buffer++ = hex_lookup[(w >> 4) & 0xF];
	*buffer++ = hex_lookup[(w & 0xF)];

	return buffer;
}

/**
 * Prints a multi-precision integer of defined length.
 * @param value the value to be printed
 * @param len the number of words of the value
 */
void print_value(const word_t *value, length_t len) {
    char buf[10];
    char *buf_ptr;
    int cnt, i;

    cnt = len / WORDS_PER_BITS(32);
    i = len-1;
    if (!(len % WORDS_PER_BITS(32)))
    	cnt--;
    for(; cnt >= 0; cnt--) {
    	buf_ptr = buf;
    	for (; i >= (cnt*WORDS_PER_BITS(32)); i--) {
    		buf_ptr = print_word(buf, value[i]);
    	}
    	*(buf_ptr++) = ' ';
    	*(buf_ptr++) = '\0';
    	print(buf);
    }
}

/**
 * Prints an array of bytes of arbitrary length.
 * @param value the byte array to be printed
 * @param len the length of the array
 */
void print_bytes(const byte *value, length_t len) {
	int i;
	char buf[3];

	buf[2] = 0;
	for (i = len-1; i >= 0; i--) {
		buf[0] = hex_lookup[(value[i] >> 4) & 0xF];
		buf[1] = hex_lookup[(value[i] & 0xF)];
		print(buf);
	}
}

/**
 * Compares two byte arrays of defined length.
 * @param a the first array to be compared
 * @param b the second array to be compared
 * @param len the length of the arrays
 * @return 0 if equal, 1 if the first is larger, -1 otherwise
 */
int compare_bytes(const byte *a, const byte* b, length_t len) {
	int i = len - 1;

	while (i >= 0) {
		if (*(a+i) > *(b+i))
			return 1;
		if (*(a+i) < *(b+i))
			return -1;
		i--;
	}

	return 0;
}

/**
 * Determines the processor's current cycle.
 * @return the number of the current cycle
 */
unsigned long long get_cycles() {
#if (ARCHITECTURE == ARCH_X86)
	unsigned long long int x;
	asm(".byte 0x0f, 0x31\n\t":"=A" (x));
	return x;
#elif (ARCHITECTURE == ARCH_X86_64)
	unsigned int hi, lo;
	asm("rdtsc\n\t":"=a" (lo), "=d"(hi));
	return ((unsigned long long) lo) | (((unsigned long long) hi) << 32);
#elif (ARCHITECTURE==ARCH_CORTEXM0)
	// very simple extension to the cortex-m0 simulator that returns the actual cycle
	unsigned long *cycle_ptr = (unsigned long*) CYCLE_COUNT_ADDR;
	return *cycle_ptr;
#endif

}
