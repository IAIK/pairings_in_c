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

#include "ibe/bbkem.h"
#include "rand.h"
#include "util.h"

int main(void) {
	byte key1[16], key2[16];
	bbkem_ciphertext ct;
	bbkem_public params;
	bbkem_msk msk;
	bbkem_pk upk;
	const char *id = "Bob";

	cprng_get_bytes(key1, 16);

	generate_params(&msk, &params);

	print("Generating parameters...\n");

	derive_private_key(&upk, &msk, &params, id);

	print("Group Private Key: \n");
	PRINT_G2("d0: ", upk.d0);
	PRINT_G2("d1: ", upk.d1);

	encapsulate_key(key1, &ct, &params, id);

	print("Generated symmetric key: \n");
	print("k: "); print_bytes(key1, 16); print("\n");
	print("Ciphertext: \n");
	PRINT_G1("c0:", ct.c0);
	PRINT_G1("c1:", ct.c1);

	decapsulate_key(key2, &ct, &params, &upk);
	print("Restored symmetric key: "); print_bytes(key2, 16); print("\n");
}
