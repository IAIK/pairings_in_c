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

#ifndef HASH_FUNCTION_H_
#define HASH_FUNCTION_H_

#include "hash/Keccak-compact.h"

#define KECCAK_SHA

#define HASH_BITS cKeccakFixedOutputLengthInBytes*8
#define HASH_BYTES cKeccakFixedOutputLengthInBytes
#define BLOCK_BITS cKeccakB
#define BLOCK_BYTES (BLOCK_BITS/8)

#ifdef KECCAK_SHA
  #define hash_function(dest, msg, length) crypto_hash(dest, (const unsigned char*) msg, length)
  #define hash_init(state)  Init(state)
  #define hash_update(state, data, databitlen) Update(state, data, databitlen)
  #define hash_final(state, hashval, hashbytelen) Final(state, hashval, hashbytelen)
#else

#endif

#endif /* HASH_FUNCTION_H_ */
