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

#include "fp/fp.h"

int main (void) {
	fp_t var_tmp, var_res;

#if (BNCURVE == BN256)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const bigint_t var_a = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_b = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_expected = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 84 ");
	}
	{
		static const bigint_t var_a = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_b = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_expected = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 85 ");
	}
#else
	{
		static const bigint_t var_a = {0x7D8020E8, 0xC18BB9A7, 0x0303D628, 0xF9CFCB32, 0x80A3254C, 0x6AA8A533, 0x1F956828, 0x0C4BB169};
		static const bigint_t var_b = {0x926B3C73, 0x61ECED90, 0x7E93E430, 0x96824F04, 0xD45FB76E, 0xA92F69A8, 0xC38E5E06, 0x73ECB042};
		static const bigint_t var_expected = {0x814C2B68, 0x77ACF093, 0x8013E88D, 0x9E90FB58, 0xFF4B6815, 0x70744788, 0x07FFB592, 0x24D96BA2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 334 ");
	}
	{
		static const bigint_t var_a = {0xE9FA3C9C, 0xAAF8138B, 0xE829CDE1, 0x0E37FDA4, 0xF0591E6F, 0xC483CDE1, 0xF148570D, 0x7FC3E4A3};
		static const bigint_t var_b = {0x31B2DDAC, 0x72CC955D, 0x7CB25C62, 0xBC7242B2, 0xB8A8F741, 0x9397EC66, 0xB0AE5DAE, 0x32E778EA};
		static const bigint_t var_expected = {0x8858578A, 0x76D4B5DE, 0x54F250DD, 0xE0D77E7E, 0x2EB7CEBB, 0xF53F9C9C, 0x2E3CF394, 0x6F7E395C};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 335 ");
	}
#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const bigint_t var_a = {0xC6B4217C, 0xADD90733, 0x7797CFAA, 0x0DCAD064, 0xB900D6E0, 0x2095DCEB, 0x4B1639D2, 0x015DB287};
		static const bigint_t var_b = {0x2632D2BE, 0x9D04EA4A, 0xC1B7695E, 0x9A5F5010, 0xB27C0C4E, 0x97A5F258, 0x075FE1AC, 0x22F9B7D1};
		static const bigint_t var_expected = {0xC94D2E5F, 0x15DD89D0, 0xA5AF57A1, 0xF9C5DE99, 0x4810D44F, 0x497F429D, 0x43C48CF0, 0x113DAD46};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 383 ");
	}
	{
		static const bigint_t var_a = {0x8987B32D, 0xF84B8A29, 0x38920F9E, 0x3EBA6BDC, 0x9ED1478A, 0x0173C0E2, 0xCBBB0349, 0x09860481};
		static const bigint_t var_b = {0x1F4C3886, 0xB8A51181, 0x4C3C09B4, 0x4212DF9C, 0xC2895491, 0xA6C4D1FF, 0xB058E5B1, 0x157E92F6};
		static const bigint_t var_expected = {0x281439C2, 0x2A878848, 0xCC8AA6CA, 0xE97FD741, 0x86440DCB, 0xBBBA7496, 0xB58CFE21, 0x1785FAE8};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 385 ");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const bigint_t var_a = {0x9635C118, 0xEF28B329, 0xC908F232, 0xB68CB445, 0x0B75D4F1};
		static const bigint_t var_b = {0x6977119E, 0x0F277BD5, 0x69528DA1, 0x2CB224FC, 0x0A103B27};
		static const bigint_t var_expected = {0x5D2DA447, 0x385CC22E, 0x5B3F1161, 0x39DA908E, 0x13E1897E};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 387 ");
	}
	{
		static const bigint_t var_a = {0x2157AFC4, 0xC6A8B3A0, 0xBE474DA8, 0x8E296EC6, 0x2376D943};
		static const bigint_t var_b = {0x551DE6D4, 0x0D6FDAF2, 0x53EDEFE9, 0xF93D8A8C, 0x07C76E11};
		static const bigint_t var_expected = {0xF3435332, 0x1892FB96, 0xC24F14DD, 0xE01FBC20, 0x1A605D31};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 388 ");
	}
#endif
#endif

	return 0;
}
