/* Copyright (C) 2011 IAIK
 * http://jce.iaik.tugraz.at
 *
 * Copyright (C) 2011 Stiftung Secure Information and
 *                  Communication Technologies SIC
 * http://www.sic.st
 *
 * All rights reserved.
 *
 * This source is provided for inspection purposes and recompilation only,
 * unless specified differently in a contract with IAIK. This source has to
 * be kept in strict confidence and must not be disclosed to any third party
 * under any circumstances. Redistribution in source and binary forms, with
 * or without modification, are <not> permitted in any case!
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __SHA1_H__
#define __SHA1_H__

#include <stdint.h>
#include "types.h"

typedef struct HASH_SHA1_ {
    uint32_t H0;
    uint32_t H1;
    uint32_t H2;
    uint32_t H3;
    uint32_t H4;
} HASH_SHA1;

void sha1_hash(word_t* result, const uint8_t* message, uint32_t length);
void sha1_init_state(HASH_SHA1* state);
void sha1_process_block(HASH_SHA1* state, uint32_t *w);
void sha1_process_message(HASH_SHA1* state, const uint8_t *message);
void sha1_process_message_final(HASH_SHA1* state, const uint8_t *message, uint32_t remaining_length, uint32_t total_length);
void sha1_state_to_byte_array(HASH_SHA1* state, uint8_t *message);
void sha1_state_to_bigint(HASH_SHA1* state, word_t* result);

#endif

