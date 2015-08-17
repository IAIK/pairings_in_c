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

