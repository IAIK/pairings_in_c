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

int main(void) {
	ecpoint_fp2 var_res, var_tmp;
	ecpoint_fp2_proj var_res_proj;

#if (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp2 var_a = { { {0x2F4FD05A, 0xDD366ECC, 0x2D438E27, 0x8C3DCCBE, 0x814B9B43, 0x06444764, 0x39A9DB1E, 0x007C86BD},
	{0x8C87A86D, 0xFA9FF14E, 0x348172AF, 0x4A1C8F26, 0x7B9B8D90, 0x284ADFBC, 0x8762B70A, 0x07EF95BE} } ,
	 { {0xEE8042D5, 0x2F1B341D, 0x50158CDE, 0xEE587D51, 0x8FD2BC7A, 0x2503B1B4, 0xCB8FB2FB, 0x11980EE7},
	{0x452F7B0D, 0x99DD45B2, 0xE835A5E3, 0x220B0FAC, 0x139F3492, 0x0DC3E5CC, 0xA5066A4B, 0x09E88E4D} } ,
	0};
		static bigint_t var_k = {0x5D2821FF, 0x87ACDA08, 0x6E990FE8, 0xCF76CF8D, 0x5D54D819, 0x86A54FDD, 0xF8F92D73, 0xEB5D74FD};
		static ecpoint_fp2 var_expected = { { {0x103EA664, 0xF890C7E7, 0x50DCCE71, 0xBA9A4F0C, 0x377A40B6, 0xFC8EDC62, 0x28C63D28, 0x0BA74CBC},
	{0x84E64507, 0xF98C04C9, 0x19A147B6, 0xC8AF2CF0, 0xA205E649, 0x740EDB74, 0xD27CB91C, 0x0E8AC1D2} } ,
	 { {0xAC007BAE, 0x85EDBCE4, 0xA9D49661, 0x74F91380, 0x91215C4B, 0x9111DF55, 0x98A2DD87, 0x04723AF9},
	{0x4B2A20E4, 0xEB9630C2, 0x8F740483, 0x16DB474D, 0xA2E17201, 0xA107DDC9, 0x23812FC1, 0x22AF661F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5712 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5713 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5714 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5715 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5716 infinity");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp2 var_a = { { {0xE4BC16B7, 0x7DFF8C11, 0x89D2F558, 0xA97657AC, 0x0C87C76E},
	{0x55052BBC, 0x470EFB88, 0x1BC03897, 0x5239D4C7, 0x117F3D59} } ,
	 { {0xE66284C8, 0xC38B1227, 0x5A89C9A8, 0x55F2B8BF, 0x0151D7ED},
	{0xC1D96468, 0x05C8FC66, 0x40E9E2FA, 0x71C0D057, 0x0D61832D} } ,
	0};
		static bigint_t var_k = {0x04165909, 0x3C09FEC6, 0x94C12B7B, 0xCA40628F, 0xCF21E3C8};
		static ecpoint_fp2 var_expected = { { {0x9D8769D1, 0x11FB5770, 0x8EB5B748, 0x4AF5D038, 0x2347AA00},
	{0xAC819F5D, 0xDC3C2FD1, 0x393ED10A, 0x3662A206, 0x1CF5FA82} } ,
	 { {0x9F6F8D83, 0x9DF93C0E, 0x11A21641, 0xE73E1C88, 0x0BE1AD61},
	{0x1A5DB8E9, 0x6EC5299E, 0xD7622D66, 0x8CD09886, 0x159FCD4C} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5737 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5738 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5739 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5740 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5741 infinity");
	}
#endif
#endif
}
