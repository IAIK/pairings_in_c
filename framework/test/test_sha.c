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

#include "hash/hashing.h"
#include "types.h"

int main(void) {
	byte var_res[16];
	bigint_t var_res_bi;

#if PRECISION == 256

	{
		static const char *var_a = "";
		static const bigint_t var_expected = {0x5CA5CEA3, 0x32449FFD, 0xE39A3FAD, 0x12AE7336, 0xD1665F66, 0xF51AA150, 0x7F7C004E, 0xA6C9F726};
		hash_id(var_res_bi, var_a);
		assert_bi_equal(var_expected, var_res_bi, "hash_id 1 hash");
	}

#endif
	return 0;
}


