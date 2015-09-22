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

#include "ec/ec.h"
#include "types.h"

int main (void) {
	ecpoint_fp var_res, var_tmp;
	ecpoint_fp_proj var_res_proj;
#if (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp var_a = {{0x920C375C, 0xA2AEB97B, 0xAA9CE5E2, 0xCD92F393, 0x6CA2951A, 0x9AE8C0B3, 0x93ACFC1D, 0x12C359CE},
	{0x91E36C9D, 0x28E16D84, 0x3367F638, 0xE4FF5005, 0x3560D8DB, 0x5C4F4496, 0xBE01C0D2, 0x15B1255F},
	0};
		static bigint_t var_k = {0xE4F1B68E, 0x9C1ED28A, 0x5BCA32C0, 0xBEA93771, 0x9D27E570, 0xCA990488, 0xC124E9D2, 0x196798D0};
		static ecpoint_fp var_expected = {{0x84014DC9, 0x6778DD78, 0x8D5151F4, 0x3D5035A5, 0xC1CA60C6, 0x89BC9EB8, 0x3B5C7965, 0x21860EAC},
	{0xDFD1EF6C, 0xA9A3B0CE, 0x3DAF61E7, 0x8FD91F44, 0xB73BD00E, 0x8CF11352, 0x712FB0FC, 0x217236E2},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4901 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4902 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4903 infinity");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp var_a = {{0x53082B66, 0x66816264, 0x357B1F2D, 0x0DD7D7FD, 0x2331E2BF},
	{0x1430C4B7, 0xF55557C4, 0xBE9EBCAC, 0x3290E95B, 0x0C7EFF46},
	0};
		static bigint_t var_k = {0x917BC168, 0x8685329C, 0xEC87C5DD, 0x8FC42FE1, 0x09256C46};
		static ecpoint_fp var_expected = {{0x512473A2, 0xBEC077DE, 0x292D2002, 0xF5DC6EE7, 0x0A3ABB44},
	{0xACD37059, 0x21E976FC, 0x58B6ACC0, 0x5E107ABF, 0x21C5922D},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4907 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4908 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4909 infinity");
	}
#endif
#endif

}
