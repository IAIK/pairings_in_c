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

#ifndef BBKEM_H_
#define BBKEM_H_

#include "types.h"

typedef struct {
	ecpoint_fp c0;
	ecpoint_fp c1;
} bbkem_ciphertext;

typedef struct {
	ecpoint_fp g;
	ecpoint_fp g1;
	ecpoint_fp g3;
	fp12_t v0;
} bbkem_public;

typedef struct {
	ecpoint_fp2 d0;
	ecpoint_fp2 d1;
} bbkem_pk;

/**
 * Generates and encapsulates a 128-bit key based on the BB1-KEM scheme
 * as proposed in the IEEE P1363.3 draft standard.
 * @param key		[out] the key that is generated during this routine (128-bit)
 * @param cipher	[out] ciphertext that encapsulates the key
 * @param id		[in]  id of the party that the cipher is destined for
 */
void encapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id);

/**
 * Decapsulates the key that is contained by the ciphertext. This process is based
 * on the BB1-KEm as proposed in the IEEE P1363.3 draft standard. The key is associated
 * with the given identity.
 * @param key		[out] the decapsulated key
 * @param cipher	[in]  ciphertext that encapsulates the key
 * @param id		[in]  the id of the party that the cipher is destined for
 */
void decapsulate_key(byte *key, bbkem_ciphertext *cipher, const char *id);

#endif /* BBKEM_H_ */
