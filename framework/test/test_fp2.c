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

#include "types.h"
#include "fp/fp2.h"

int main (void) {
	fp2_t var_tmp, var_res;

#if BNCURVE == BN256
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const fp2_t var_a =  { {0x4EFD229C, 0x01F43296, 0x559983D5, 0xC2110816, 0xA23057B1, 0x75F9F38F, 0xFE4F3292, 0x5AB9B865},
	{0x47A5A23E, 0x8777789B, 0x866F8B62, 0x694F0C3B, 0xF464CEE5, 0xA6561155, 0x43B25859, 0xA9FD4C7E} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 1 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 2 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 3 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 4 a1");
	}
	{
		static const fp2_t var_a =  { {0xD9DDF819, 0xBC99E3FA, 0xD4F2FD85, 0x0855D590, 0xAD3F4164, 0x470F17A5, 0xD2B3CC1C, 0x7B3B1BD5},
	{0x30F51F0A, 0x12B3081C, 0x85D888A9, 0xD818AA36, 0x6579E7FA, 0xE72D3A9D, 0x3441957E, 0x062C3EAC} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 5 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 6 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 7 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 8 a1");
	}
	{
		static const fp2_t var_a =  { {0x43F5E2DE, 0xB105712D, 0x611B7E4C, 0xDAAA600B, 0x163AA25E, 0x77295FE0, 0x746AA75C, 0x035632FE},
	{0x689B2C47, 0xEFD90BF2, 0x05E13476, 0x02391B4F, 0xF370D0B8, 0xE99F7002, 0x603BFB42, 0x8821536A} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 9 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 10 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 11 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 12 a1");
	}
	{
		static const fp2_t var_a =  { {0xD5AE8057, 0xDF10A3A6, 0x70C64E51, 0xADBDBEF5, 0xEC2C95DE, 0xABC0313D, 0x0B40F753, 0x8D9E9B73},
	{0x09D964A0, 0xC42C6058, 0x9F935662, 0x8A587DDA, 0xD1F511F3, 0x1167D66C, 0x8EB56478, 0x0CFE6450} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 13 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 14 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 15 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 16 a1");
	}
	{
		static const fp2_t var_a =  { {0xC76FAB24, 0x92CBEBC2, 0xC0C8FC23, 0xC654A52C, 0x83B7CC44, 0xE8A4CF32, 0x83B154A0, 0x98A96942},
	{0xF5B2A3DB, 0x769723D3, 0x82920394, 0xA1D9F7D9, 0xC5ADCD6B, 0xEFFCB142, 0xC9F5B1D2, 0x990DFA7C} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 17 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 18 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 19 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 20 a1");
	}
	{
		static const fp2_t var_a =  { {0xBC41226E, 0x4E2B4B1D, 0xC7DECF33, 0xE0C6EC4D, 0x6D19F1DC, 0x60ACB31E, 0xC3966C33, 0x118B83D5},
	{0x8CF777FC, 0x2B6D613E, 0x71D9076F, 0x923BF24F, 0x2BF6BA8C, 0x5CAA8E17, 0xD8487670, 0x03217DB4} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 21 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 22 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 23 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 24 a1");
	}
	{
		static const fp2_t var_a =  { {0xBAD849B3, 0xD45A4787, 0xBD3CA6EA, 0x33CAD82D, 0x7442CF7A, 0x7E085110, 0xB4ADF7FF, 0x53AB00C3},
	{0xF65869A9, 0x454C9F2E, 0xC4177F03, 0x3157AF6B, 0xF147BE54, 0x6017E513, 0xC6487AAE, 0x45D9FD7F} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 25 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 26 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 27 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 28 a1");
	}
	{
		static const fp2_t var_a =  { {0xBC1EECC5, 0x2CAC0EAE, 0x1EE84703, 0xC3A128CA, 0xB0E4439D, 0x022C5BE0, 0x001BF9A3, 0x9EDB8010},
	{0x4CC15FBB, 0x6C224FFD, 0x159C4A1D, 0x237A7BF4, 0x4C66068C, 0x5DDB3FCC, 0x5B3E00F7, 0x3DA8132F} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 29 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 30 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 31 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 32 a1");
	}
	{
		static const fp2_t var_a =  { {0x86F5CEF0, 0x9B34B65F, 0xF6F57FB4, 0x1EA2C0EA, 0xC5651AC7, 0xDEE48743, 0x902857D1, 0x57F5E604},
	{0x0FF24E50, 0x85D9DDCC, 0xBF10CCC0, 0x84D9F328, 0xAC6D89FE, 0xE92C5AE9, 0x5FC0E28B, 0x395BA3C6} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 33 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 34 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 35 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 36 a1");
	}
	{
		static const fp2_t var_a =  { {0xB86D11ED, 0xA576665E, 0xBFC37060, 0x03A712F6, 0x457E6C44, 0x45C7AA0E, 0x4C3E9290, 0x6C4255BB},
	{0xC668362D, 0xB3BDE1A5, 0x0098BF23, 0xD94FE95C, 0x6BFC4299, 0xCDD0EC74, 0x5D299E53, 0x39D68177} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 37 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 38 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 39 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 40 a1");
	}
	{
		static const fp2_t var_a =  { {0x3402ACE2, 0x10A0B14B, 0x32FF62F1, 0x6FF56244, 0x002DE79C, 0xAEDEA8FA, 0x5E90A880, 0x0B6278BB},
	{0x71B8F74E, 0x5B101922, 0xB78020A0, 0xBDE49270, 0x7ABAF8F1, 0x23EF7ED3, 0x9DA949B0, 0x0B914DEA} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 41 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 42 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 43 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 44 a1");
	}
	{
		static const fp2_t var_a =  { {0x1AA89FF6, 0xE0D954EF, 0x4836FA8C, 0x9D0B35EA, 0x07C72874, 0xCDFDC4D4, 0x2EAF21FF, 0xA018C7D1},
	{0x8DA34DC9, 0x23580522, 0x4FCC7343, 0xE99CC497, 0x61694AE5, 0x44590008, 0x27D784A7, 0x4867D8D1} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 45 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 46 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 47 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 48 a1");
	}
	{
		static const fp2_t var_a =  { {0x69B1D368, 0x5CAA643F, 0x64EFCE76, 0xF95FDF96, 0x572539C7, 0x9BAE442F, 0x24F84281, 0x1D0BB7F5},
	{0x9AD30615, 0xF26D22B5, 0x23A731F4, 0x7893298B, 0x927D0D7E, 0xC962E5B0, 0xC6BB59C4, 0x3CBC2230} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 49 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 50 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 51 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 52 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9BF16BA, 0x05EBA2A9, 0x7F90832B, 0x798601C9, 0x7D20E1B5, 0x4162EDD6, 0xEDC16AC5, 0x9FF63F96},
	{0x811A02F0, 0xE9B6F389, 0x49706976, 0x00D7D35E, 0xBA102F6B, 0x76917CF5, 0x427F0E3E, 0xA35A87BD} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 53 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 54 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 55 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 56 a1");
	}
	{
		static const fp2_t var_a =  { {0x540FE6B4, 0xA3CCC2F2, 0xD340143D, 0xDF55AA47, 0x4EC9914F, 0x4001DBD3, 0xEFB3984B, 0x24B1A0B7},
	{0x1BF28531, 0x6F172297, 0x1E0A68D8, 0xE7A05841, 0xCDFC56A5, 0x7084C6A1, 0x24E8E12E, 0x1B94D3E9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 57 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 58 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 59 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 60 a1");
	}
	{
		static const fp2_t var_a =  { {0xCC1F0B94, 0x3C84C964, 0x59AFECF2, 0x6A512A93, 0xDB6E2B54, 0x4F9AD10C, 0x936F3C8B, 0x19B48726},
	{0x0C48DB08, 0x2A8F4ADE, 0x8D22B907, 0x1CD0195B, 0x51C3EAA4, 0x070E72F4, 0x341AA2A4, 0x6CD62DD9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 61 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 62 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 63 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 64 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 65 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 66 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 67 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 68 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 69 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 70 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 71 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 72 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 73 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 74 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_b =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 75 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 76 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 77 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 78 a1");
	}
	{
		static const fp2_t var_a =  { {0xD7BB3E71, 0x12A09846, 0xC8A275C6, 0xD078A45E, 0x72A98FDB, 0x53B712E4, 0x43205AB7, 0x59EC3160},
	{0x7383088F, 0xFFF3A208, 0x1CEEF4D6, 0xA8521312, 0x624E9668, 0xD43E3748, 0xFD71055D, 0x28052F09} } ;
		static const fp2_t var_b =  { {0xF083D127, 0xACEF8C41, 0x1B5305D5, 0x937E5DDA, 0xA67FFE29, 0x9043A122, 0x27F2EF99, 0xA3CF943C},
	{0x379F6806, 0x0FDB8386, 0xE28CCB6D, 0x225C13C2, 0xAE536F71, 0x9EF6C036, 0x47C5D855, 0x0BC078B0} } ;
		static const fp2_t var_expected =  { {0x6612DAFD, 0xC0A19AD7, 0x0F7D9C54, 0x50E55598, 0xC5470450, 0xE89A579B, 0x2AF46E27, 0x43A826DA},
	{0xAB227095, 0x0FCF258E, 0xFF7BC044, 0xCAAE26D4, 0x10A205D9, 0x7334F77F, 0x4536DDB3, 0x33C5A7BA} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 79 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 80 a1");
	}
	{
		static const fp2_t var_a =  { {0xF983F592, 0xCF3AC553, 0x0C2FCB19, 0xB2310B01, 0x4A60CA41, 0x7B44B91A, 0x69BBDA9E, 0x24E83812},
	{0x337E546F, 0xC492D660, 0x39E2DCDB, 0xEE8A8413, 0x2A839E7F, 0x897403B3, 0x9BCEEF8C, 0xB46D7E60} } ;
		static const fp2_t var_b =  { {0x38480D82, 0x7E9183BA, 0x1071248F, 0xA34DDC2F, 0x6A3CD1B7, 0xBB29BC7C, 0x318C01C8, 0x779F197C},
	{0xA78B228B, 0xC1DA1FA3, 0x3B65EA37, 0xE95150E4, 0x0796688F, 0xE906A23C, 0x82C2EFD1, 0x2FBD1CD6} } ;
		static const fp2_t var_expected =  { {0x31CC0314, 0x4DCC490E, 0x1CA0EFA9, 0x557EE730, 0xB49D9BF9, 0x366E7596, 0x9B47DC67, 0x9C87518E},
	{0x78DD425F, 0x877E6C52, 0xA0D0E7CC, 0xC4CA2856, 0xDE377D5A, 0x771A4983, 0xDE730335, 0x2A16FC74} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 81 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 82 a1");
	}
	{
		static const fp2_t var_a =  { {0xE95C0079, 0x0035A939, 0xE46E5910, 0xA8B04DBB, 0x5B97CFD0, 0x52B49108, 0x6825C8D3, 0x1C5E8A79},
	{0xDA9A76D9, 0xEA3FAA70, 0xEA34123C, 0x56B661D3, 0x5D76F8BA, 0x49FAECB8, 0x44CB044E, 0x3E621E37} } ;
		static const fp2_t var_b =  { {0x0E1A6654, 0xDA3D63D0, 0xD4E134D5, 0x93D697E9, 0x03787FD0, 0x7210980B, 0x39C1DB96, 0xB8206B45},
	{0x8C4A562F, 0x65BA80BA, 0xDEC42F8F, 0x91E06E3B, 0xDDCBAF2C, 0x816EFECE, 0xEC1487A4, 0x6D96EBD0} } ;
		static const fp2_t var_expected =  { {0x954A3232, 0xDB848358, 0xE4D7AE9E, 0x29753904, 0x0B2DC5EC, 0xC964CCA8, 0x61C8C840, 0x1A6B56FC},
	{0x66E4CD08, 0x4FFA2B2B, 0xC8F841CC, 0xE896D00F, 0x3B42A7E6, 0xCB69EB87, 0x30DF8BF2, 0xABF90A08} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 83 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 84 a1");
	}
	{
		static const fp2_t var_a =  { {0x88D576D8, 0xD040B62B, 0x9A1AC776, 0x6053DB19, 0x310856F2, 0x8F40DE20, 0xCA061EE5, 0x79E5AD57},
	{0xF91476C7, 0x97F30520, 0x48777E0F, 0x12E2CBE1, 0xD201C3C5, 0xAD9C7C00, 0x42679497, 0x16E9D990} } ;
		static const fp2_t var_b =  { {0x16F2EBF7, 0xE99EAFDB, 0x5A92CB9F, 0x3AA27D02, 0xA3A490D7, 0x646DE057, 0x479AE043, 0x137B8553},
	{0x630CBFAC, 0x2658279B, 0x42027DFA, 0xB7D34632, 0x6BEA2126, 0x21B101D1, 0xCF299E7D, 0x455DF863} } ;
		static const fp2_t var_expected =  { {0x9FC862CF, 0xB9DF6606, 0xF4AD9316, 0x9AF6581B, 0xD4ACE7C9, 0xF3AEBE77, 0x11A0FF28, 0x8D6132AB},
	{0x5C213673, 0xBE4B2CBC, 0x8A79FC09, 0xCAB61213, 0x3DEBE4EB, 0xCF4D7DD2, 0x11913314, 0x5C47D1F4} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 85 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 86 a1");
	}
	{
		static const fp2_t var_a =  { {0x41D2C7D3, 0x66803CA9, 0xCBD1A941, 0xD64FB6A3, 0xA75D985B, 0xD51AC6D6, 0x164971AE, 0x60B844A8},
	{0x711B9961, 0xF4506637, 0xA07CFCD7, 0xD4B14AFC, 0x15ACE052, 0x6776A2E4, 0x1C13E7AF, 0x76522199} } ;
		static const fp2_t var_b =  { {0x8122F3A8, 0xCFCEDFE7, 0xE952B1DD, 0xB815DB3D, 0xD125F5E4, 0x28AEEAFD, 0x6361C4C4, 0x1E7D7FD2},
	{0xBE8485E6, 0x2936F236, 0x7FB62986, 0x8D93A2AD, 0x86DD7040, 0x60460D06, 0x72A8EB91, 0x0899E39F} } ;
		static const fp2_t var_expected =  { {0xC2F5BB7B, 0x364F1C90, 0xB5245B1F, 0x8E6591E1, 0x78838E40, 0xFDC9B1D4, 0x79AB3672, 0x7F35C47A},
	{0x2FA01F47, 0x1D87586E, 0x2033265E, 0x6244EDAA, 0x9C8A5093, 0xC7BCAFEA, 0x8EBCD340, 0x7EEC0538} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 87 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 88 a1");
	}
	{
		static const fp2_t var_a =  { {0x1BAFD141, 0xE9DA22CB, 0x40BFFAEB, 0xF15EF15F, 0x46C3AA52, 0xCC87512C, 0x947A55C3, 0x36512D03},
	{0xADAE0F56, 0x2AEB7248, 0x8C7704E0, 0x9425551F, 0x036D2669, 0x1C1AB879, 0x5AFCA4B4, 0x81114F1D} } ;
		static const fp2_t var_b =  { {0x2F91AC97, 0xB901E5C1, 0xCA288448, 0xBDBDFE73, 0x176F2588, 0x766E646F, 0x156926B7, 0x14CD0D41},
	{0x1D28CFBF, 0x9B99A94D, 0x0D3F9407, 0xB11312D7, 0x6962516E, 0xF6997C64, 0x1D888DA9, 0x3500E4E8} } ;
		static const fp2_t var_expected =  { {0x4B417DD8, 0xA2DC088C, 0x0AE87F34, 0xAF1CEFD3, 0x5E32CFDB, 0x42F5B59B, 0xA9E37C7B, 0x4B1E3A44},
	{0xCAD6DF15, 0xC6851B95, 0x99B698E7, 0x453867F6, 0x6CCF77D8, 0x12B434DD, 0x7885325E, 0xB6123405} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 89 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 90 a1");
	}
	{
		static const fp2_t var_a =  { {0x1F6C394B, 0x83EBDAB7, 0xBF11C84F, 0x99CD3594, 0x95C80558, 0x1B4090EC, 0x8DEDEA90, 0x657E5BB3},
	{0xB5C74B56, 0x5F9AF61B, 0xD6A7600D, 0x3C3F0AA2, 0x243DECAF, 0x74ADBCB8, 0x44767B66, 0x9E590BA1} } ;
		static const fp2_t var_b =  { {0x8B7DD1FD, 0xCCDB770E, 0x9AFCB9D3, 0x43034B21, 0x52E5060F, 0xF1413971, 0xE5445C82, 0x16B873D7},
	{0x10F6F26B, 0x9D6FC325, 0x0440B56D, 0x57E44B6C, 0xEA2CD150, 0x790BF5E0, 0x18FA3C6B, 0x1CC3B14F} } ;
		static const fp2_t var_expected =  { {0xAAEA0B48, 0x50C751C5, 0x5A0E8223, 0xDCD080B6, 0xE8AD0B67, 0x0C81CA5D, 0x73324713, 0x7C36CF8B},
	{0x64920926, 0xFE1C2F8F, 0x06703633, 0x8111A96E, 0xBA88344A, 0xF259562D, 0x1D51DBA8, 0x01091E2E} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 91 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 92 a1");
	}
	{
		static const fp2_t var_a =  { {0x55AD8CA6, 0x5A01CBE2, 0x12FC0689, 0xB67C9DD7, 0x1D6188C4, 0x6B706328, 0x47B89097, 0x546212B0},
	{0x90839890, 0xBB6A1366, 0x44D11ED4, 0xB314F8AA, 0xFFF8D8BF, 0x174ABB75, 0x2218EB50, 0x36326447} } ;
		static const fp2_t var_b =  { {0x9C9D40A4, 0x31C650C5, 0x21439A85, 0x32D133C0, 0x096EBC21, 0x40CF0E4B, 0x1B2D5795, 0x8CCA217B},
	{0x16A90900, 0x5E62F87F, 0xDC1CB4E6, 0x1A20FBBD, 0x41C18010, 0xA5EE2A5B, 0xAB7AFE2C, 0x3E40902B} } ;
		static const fp2_t var_expected =  { {0x901E98AF, 0x8CD992F6, 0x5FC7C1C7, 0xD63C24F6, 0xD2EDBB30, 0xB0DF1507, 0x22C70C03, 0x27189569},
	{0xA72CA190, 0x19CD0BE5, 0x20EDD3BB, 0xCD35F468, 0x41BA58CF, 0xBD38E5D1, 0xCD93E97C, 0x7472F472} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 93 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 94 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4BA638D, 0x971FB848, 0xFFB465A9, 0x31E18C9A, 0x65E47990, 0x64B947E0, 0x0BB59665, 0x6C731EBB},
	{0x47237C67, 0x689CEC65, 0xA03BA2D2, 0xE1CF3519, 0x1D612408, 0xACFDD4B8, 0x3CBD39A9, 0xAF7647BE} } ;
		static const fp2_t var_b =  { {0x091FA063, 0x11F0115B, 0x52FD8EC3, 0x5F9497FB, 0x7070284D, 0x11D18F76, 0xBFFFD671, 0x25D06FDE},
	{0x5D59E8D5, 0x02D978CE, 0xD90796CB, 0x1B707C7E, 0xF3BC43B5, 0x132ACF97, 0xDEA578D8, 0x303B9630} } ;
		static const fp2_t var_expected =  { {0xCDDA03F0, 0xA90FC9A3, 0x52B1F46C, 0x91762496, 0xD654A1DD, 0x768AD756, 0xCBB56CD6, 0x92438E99},
	{0x425130A1, 0x6C87DB82, 0xA4CB5A56, 0xEA2E04F7, 0xBD3ADE08, 0xC4C847E4, 0xDB43D658, 0x259E3F2C} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 95 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 96 a1");
	}
	{
		static const fp2_t var_a =  { {0x748083EA, 0x61FD2F29, 0x50771DBD, 0xF1038DA3, 0xF60D8CC3, 0xAE2F1F5B, 0x2182EFD2, 0x137C0F24},
	{0xE10B1A82, 0x8CA350A2, 0xB1B2B5DE, 0xAFAE7D02, 0x051AD97C, 0xDCC94A64, 0xDA84648E, 0x73D6FC6E} } ;
		static const fp2_t var_b =  { {0x00850427, 0x91F4E220, 0x740FD491, 0xEC957A39, 0x0D412003, 0xFEF57E55, 0xDAD7E304, 0x763B7253},
	{0xEEC0F868, 0xB0A1B88A, 0xC34E1051, 0x425CB5B3, 0x88F0B9DB, 0x6B7C8C4B, 0xF9F9D172, 0x5A0D7627} } ;
		static const fp2_t var_expected =  { {0x75058811, 0xF3F21149, 0xC486F24E, 0xDD9907DC, 0x034EACC7, 0xAD249DB1, 0xFC5AD2D7, 0x89B78177},
	{0x6D9FDE4F, 0x3E567F7C, 0xA088E6E9, 0xDEF98615, 0x3A2909A2, 0x4CE57A44, 0x945F59D8, 0x13D0D3D4} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 97 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 98 a1");
	}
	{
		static const fp2_t var_a =  { {0x6E8EFF40, 0xE205F3BC, 0xCC81C4A0, 0xDF812501, 0x58FDDC0D, 0xF15BFBA9, 0xD281E2FD, 0xB39A72B0},
	{0x059A601A, 0x5239D992, 0x6A0EBDBC, 0xF0F19AA5, 0xECC98CD8, 0x55442B3B, 0x04B33501, 0x30C100B1} } ;
		static const fp2_t var_b =  { {0x62EC88CF, 0xDB8EF779, 0xD0920EBD, 0x87469E70, 0x694A8B60, 0xBC206F0A, 0xF2DE709B, 0xB9567D9C},
	{0x0D5F4600, 0x93E021FE, 0xBBD3F974, 0x525C5BE5, 0xDF5581AC, 0x5FD2D9CF, 0xC400F586, 0xB0BA16ED} } ;
		static const fp2_t var_expected =  { {0x6F4F5374, 0xBEA66184, 0xC89BF417, 0x53B616D1, 0x6E65DDB9, 0xB21C0E48, 0x85417770, 0xB2DD518B},
	{0xB0CD717F, 0xE72B71DE, 0x516AD7E9, 0x303C49EA, 0x783C84D0, 0xB9B6A8A0, 0x88954E5E, 0x276778DC} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 99 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 100 a1");
	}
	{
		static const fp2_t var_a =  { {0xBA185CCC, 0x40585E69, 0x3A172028, 0xE18BB6F0, 0x1236F909, 0xD43AE7D8, 0x64DABD88, 0xB4410C29},
	{0xE0FF6F47, 0xDD064789, 0x118A29F1, 0xC832E0B5, 0x568453E8, 0xAE762ABF, 0xC24C8332, 0x7BC999D1} } ;
		static const fp2_t var_b =  { {0x99C7FAB0, 0x17E6DCAC, 0x0484591E, 0x2BF39DC0, 0x63E4470B, 0xEF279FA1, 0x917B1D89, 0x111316D6},
	{0x23606F4B, 0xD2BAF029, 0x5B643FB8, 0x4532EFA2, 0xD56CAEC1, 0x91306112, 0xC7E158D4, 0x5559A411} } ;
		static const fp2_t var_expected =  { {0xF1B422E1, 0x5950B164, 0x6A2399FF, 0xFA6DA80F, 0x2238B65F, 0xC8022B0E, 0xB636FEE9, 0x0B40843D},
	{0xA233A9F7, 0xB0D2AE01, 0x98768A63, 0xFA5423B6, 0xD80E78F4, 0x44462F66, 0x4A0EFFDE, 0x170F9F21} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 101 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 102 a1");
	}
	{
		static const fp2_t var_a =  { {0x5FF7AF59, 0xA5C7D5F0, 0x647EF615, 0xE1E6523A, 0xAD9FDDA7, 0x013DB14C, 0x21768898, 0x7C37120C},
	{0x5589F208, 0x594FC8DF, 0xF115C75B, 0xE4B78851, 0xCEF29E7D, 0x9E1E1082, 0x9DDF874D, 0x8EDF1B79} } ;
		static const fp2_t var_b =  { {0x4BD44354, 0x6EF927D9, 0x01F35B82, 0xAE593AB4, 0x2E067220, 0x44961DF1, 0xBD9A4342, 0x2A8CF19C},
	{0x39E7B0B2, 0x959A3557, 0x6CDAF38B, 0x03A2A2B8, 0xF1B7652D, 0xAA2E12CB, 0x4BEAFDAE, 0xB0BE119F} } ;
		static const fp2_t var_expected =  { {0xABCBF2AD, 0x14C0FDC9, 0x66725198, 0x903F8CEE, 0xDBA64FC8, 0x45D3CF3D, 0xDF10CBDA, 0xA6C403A8},
	{0x2D456E1F, 0xEFFB7485, 0x8978DB9F, 0xD5487E69, 0x6CC779F5, 0x4CEBC6E3, 0xA9ABA8D3, 0x85898E56} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 103 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 104 a1");
	}
	{
		static const fp2_t var_a =  { {0x66A6C659, 0x37DB2D20, 0x1102E164, 0xC7EB9981, 0xB085F940, 0x1E47B5CD, 0x4F03B414, 0x759665E4},
	{0xCE5788CB, 0xEC45060F, 0xA60593CD, 0x3F208B1A, 0x312CE357, 0xCA6D5D3B, 0x1BBA6DD4, 0x8B169989} } ;
		static const fp2_t var_b =  { {0xA92540F9, 0x05349BFC, 0x0FD7D273, 0x3010C240, 0x4B94208E, 0x53EA406E, 0x806A51E1, 0x9D846932},
	{0x563BFE41, 0x041E8976, 0xB793C2D1, 0x74839F5C, 0xBC9D2716, 0x52580958, 0x96ABBCCC, 0x2A94B032} } ;
		static const fp2_t var_expected =  { {0xAD9FD2B7, 0x3E213F6B, 0x4C62D490, 0xE4EAAF20, 0xA8379019, 0x76D199D0, 0x8F4F29CC, 0x59073054},
	{0x2493870C, 0xF0638F86, 0x5D99569E, 0xB3A42A77, 0xEDCA0A6D, 0x1CC56693, 0xB2662AA1, 0xB5AB49BB} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 105 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 106 a1");
	}
	{
		static const fp2_t var_a =  { {0xD74542AC, 0x1ECE1579, 0x09F11D61, 0x7A87910B, 0xA49730D5, 0xD4B1A6BF, 0x38F4CEA7, 0x07CDCCC5},
	{0xF057F013, 0xC1739357, 0x24408C21, 0xADFBAB5A, 0xB2669DFF, 0xDCC92CE5, 0x4531184F, 0x212DA199} } ;
		static const fp2_t var_b =  { {0x9168605E, 0x0721AD1C, 0x785632A9, 0x60DAA86F, 0x4A89847D, 0xD4D64BBA, 0x6121621F, 0xA196FFEA},
	{0x83C7E212, 0x461736AC, 0x02728146, 0x81C2A110, 0xBE689226, 0x312D1A3B, 0xF2FAB70A, 0x2A572B59} } ;
		static const fp2_t var_expected =  { {0x68ADA30A, 0x25EFC296, 0x8247500A, 0xDB62397A, 0xEF20B552, 0xA987F279, 0x9A1630C7, 0xA964CCAF},
	{0x741FD225, 0x078ACA04, 0x26B30D68, 0x2FBE4C6A, 0x70CF3026, 0x0DF64721, 0x382BCF5A, 0x4B84CCF3} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 107 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 108 a1");
	}
	{
		static const fp2_t var_a =  { {0xB999BDA3, 0x848F8159, 0x149E6213, 0xE13A8079, 0x10E9DCF0, 0xCA495A06, 0x237F3601, 0x989D2D6E},
	{0x871F6F28, 0xFC634823, 0xDA9B23D2, 0x3F24EE9D, 0x81634831, 0x75AC09CF, 0xE4386222, 0x29F4D80A} } ;
		static const fp2_t var_b =  { {0x6F9F4B21, 0x9BB7D50B, 0xD77EA88C, 0x3A54A4CA, 0x06CDCDD4, 0x6B025D7F, 0xE73609FF, 0x5A034EA2},
	{0xC71A644F, 0x848C6339, 0x17DBC29D, 0x125F9158, 0x7E472406, 0xEE205924, 0xA5F1CED3, 0x18597F6F} } ;
		static const fp2_t var_expected =  { {0xC70CD429, 0x2158CCB3, 0x17A52B59, 0x087D78A3, 0xC3D52110, 0x39EB5B19, 0xCA9663D8, 0x388CDD4E},
	{0x4E39D377, 0x80EFAB5D, 0xF276E670, 0x51847FF5, 0xFFAA6C37, 0x63CC62F3, 0x8A2A30F6, 0x424E577A} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 109 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 110 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 111 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 112 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 113 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 114 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 115 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 116 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 117 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 118 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 119 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 120 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_b =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 121 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 122 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 123 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 124 a1");
	}
	{
		static const fp2_t var_a =  { {0x140AEEC2, 0x90C21320, 0xFA5FAD7C, 0xE71AC7F8, 0x7DF1D0BB, 0xAA4F9017, 0x589EC8D7, 0x921EC78B},
	{0x9D0F2C92, 0xC6F33615, 0x937DF0BA, 0xDB635F2A, 0x2803E888, 0x3DC32C3C, 0x3ECCC3A0, 0x11E74E5A} } ;
		static const fp2_t var_b =  { {0x4A448100, 0xE8B4C604, 0xF6E816AE, 0xA59CA412, 0x06C9FB7E, 0xBD27E66F, 0x5CC73713, 0x2F4BA63B},
	{0x2BE8E34D, 0xE6B73E42, 0xBCB867CE, 0x0D6D1CC6, 0x844CFD5A, 0x339BA509, 0xF9EC0EA8, 0x5CBFF688} } ;
		static const fp2_t var_expected =  { {0xC9C66DC2, 0xA80D4D1B, 0x037796CD, 0x417E23E6, 0x7727D53D, 0xED27A9A8, 0xFBD791C3, 0x62D3214F},
	{0xD3527DE0, 0xDF2A8184, 0xAB3D6832, 0xE107EF04, 0xF79974E3, 0x0587E39D, 0x84FF9121, 0x6F3AF693} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 125 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 126 a1");
	}
	{
		static const fp2_t var_a =  { {0xF1A2C5B2, 0x69BE87CD, 0x84911723, 0x71D0BB67, 0x738C59B1, 0x1A78BEB9, 0x1E10962D, 0x5DBA6BA8},
	{0x11285F50, 0x4A6DD4FD, 0x986AE366, 0x3162717B, 0x3162CBB9, 0xE98F2910, 0xDDCF6733, 0x0D176AAC} } ;
		static const fp2_t var_b =  { {0x2B752E39, 0x178ADF2B, 0x9C31436F, 0x8966DBEF, 0xD34AE9DD, 0x757553B7, 0x07B34A3C, 0x88426A91},
	{0xB7060246, 0x940725F1, 0xBB783110, 0x5C1451D9, 0x5A6EA1D4, 0xA6F733CB, 0x348E2545, 0x5F8322DA} } ;
		static const fp2_t var_expected =  { {0x2859CC14, 0x51223254, 0xBCD7B2FB, 0xFB7B8C18, 0xF423F988, 0xA063C76C, 0x567C2819, 0x8F8B9FD9},
	{0xBC4E91A5, 0xB55538BC, 0xB16A919C, 0xE85FCC42, 0x2AD6B399, 0x3DF851B0, 0xE9601E17, 0x67A7E694} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 127 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 128 a1");
	}
	{
		static const fp2_t var_a =  { {0x581495F1, 0x388E1BA3, 0x7891A76F, 0x699882EF, 0x79F93F81, 0xC3EBD9EF, 0xBF569454, 0x5F2FBB39},
	{0x76C3BC9E, 0xACD3FC06, 0x02B2125B, 0x7359E0C8, 0x74B527E5, 0x0E2894D6, 0x0840B716, 0x70FA8689} } ;
		static const fp2_t var_b =  { {0xB8C89AA7, 0x516D8DEA, 0xBC814933, 0xBCE66915, 0xA0A1453A, 0x3F2DF901, 0xF07F6014, 0x13FE2744},
	{0x72717E1E, 0xB61DCE76, 0xDB0C540A, 0xE6903736, 0x8587BABF, 0xF08517E5, 0xA0BAD2EF, 0x8872D428} } ;
		static const fp2_t var_expected =  { {0x9F4BFB4A, 0xE7208DB8, 0xBC105E3B, 0xACB219D9, 0xD957FA46, 0x84BDE0ED, 0xCED73440, 0x4B3193F4},
	{0x667E731B, 0xF5A4B741, 0xFC1D9D97, 0x9FDB5631, 0x430FF6DA, 0x1903D95C, 0xA7A4C04F, 0xA29B5122} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 129 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 130 a1");
	}
	{
		static const fp2_t var_a =  { {0x50B22DBB, 0x25F1F93D, 0x9FC2225D, 0xB743E892, 0x17DCCB99, 0x4D472192, 0x82B84F34, 0x02905C56},
	{0xAC29FD81, 0x17D61667, 0x1EE0932D, 0x5219540C, 0x7EDFD4BD, 0x62F5FD0C, 0x468941A9, 0x734AC89A} } ;
		static const fp2_t var_b =  { {0x1E27D403, 0xBB04E730, 0x9CE54BC8, 0x5E2E175E, 0xF209C35D, 0xB3882BF0, 0x1FF1D7D1, 0x68356A04},
	{0x64471BD4, 0x74D07567, 0xE4EA07B3, 0x93326CAF, 0x9056DAA2, 0xB989CCAD, 0x849B5A5E, 0x3F2E19C1} } ;
		static const fp2_t var_expected =  { {0x94B68E53, 0x69DB9BBE, 0xD754B5DB, 0x6C277DD4, 0x79B591F1, 0x951F520C, 0xA2E5538B, 0x546E9114},
	{0x47E2E1AD, 0xA305A100, 0x39F68B79, 0xBEE6E75C, 0xEE88FA1A, 0xA96C305E, 0xC1EDE74A, 0x341CAED8} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 131 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 132 a1");
	}
	{
		static const fp2_t var_a =  { {0xE27403AA, 0x575AA4AF, 0xC18BDFF7, 0x41373C32, 0xD63BC5DA, 0x609BE613, 0xAF3F9D50, 0xAD423890},
	{0x1D787C56, 0xB113AAF3, 0x86E42779, 0xC8CDE9CD, 0x2B347B9C, 0x89D5F7B4, 0x21D52398, 0x39E7642E} } ;
		static const fp2_t var_b =  { {0xDCEC0964, 0x8021A9DB, 0xB3262A74, 0x0B654492, 0x01F3B63E, 0x8E8F904F, 0xDCBA0C9C, 0x0469A708},
	{0x359F4A5E, 0xF63A7D44, 0xC9943D19, 0x394C0D04, 0xAC9BB2AF, 0xADDA6635, 0xE8801B9A, 0x331793AC} } ;
		static const fp2_t var_expected =  { {0x0587FA46, 0xD738FAD4, 0x0E65B582, 0x35D1F7A0, 0xD4480F9C, 0xD20C55C4, 0xD28590B3, 0xA8D89187},
	{0xE7D931F8, 0xBAD92DAE, 0xBD4FEA5F, 0x8F81DCC8, 0x7E98C8ED, 0xDBFB917E, 0x395507FD, 0x06CFD081} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 133 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 134 a1");
	}
	{
		static const fp2_t var_a =  { {0xB4CC19F6, 0xFA01D261, 0xD2DFB7E7, 0xDE597DE3, 0xEAA1ED3C, 0xA90BFD8A, 0x4E9B6FE8, 0x0EEE13B1},
	{0xD2C39704, 0xA37057C7, 0x04BBEFD3, 0xBDA4EC7A, 0x02082413, 0x2B3A4E7D, 0xE072AEDE, 0x297006D7} } ;
		static const fp2_t var_b =  { {0x867542FB, 0xC6C035DF, 0x19D1EBC4, 0xF7D260BA, 0xA446A1FE, 0x64C1D314, 0x6F436F8D, 0x390F3F40},
	{0xAE38E135, 0x6379B7D4, 0xFD77A841, 0xE577049B, 0x0CA1FEC3, 0x6C6487D0, 0x93547054, 0x3FA0F13C} } ;
		static const fp2_t var_expected =  { {0x90830B96, 0x32302633, 0x8D85AB6A, 0xF998C9CA, 0x9A3DD4F2, 0x3FAA86E1, 0x1F76DC84, 0x8FF27333},
	{0x86B6EA6A, 0x3EE529A4, 0xDBBC26D9, 0xEB3F947E, 0x4948AF04, 0xBA362318, 0x8D3D1AB2, 0xA3E2B45D} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 135 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 136 a1");
	}
	{
		static const fp2_t var_a =  { {0x904EFA75, 0x2FA2066F, 0x431D592D, 0x9B5CE8E2, 0x82A22528, 0xC552F3FD, 0x289CFEA1, 0x02C84369},
	{0xD34543B1, 0x15050DA8, 0x5EE35D60, 0x1AE09C95, 0x8C930505, 0xF0886F3C, 0xCBF5329C, 0xAB58E25F} } ;
		static const fp2_t var_b =  { {0xFB90F3A0, 0xB60A69E1, 0x1A2EFA23, 0xD2DB2443, 0x671CA91A, 0xEC70863C, 0x60E7D0DD, 0x4062F00D},
	{0x7872BEDE, 0xE50F6179, 0x711F1E6F, 0x6D2F9D43, 0xE2F209E5, 0xA0E5CB6F, 0x8EF2FAB4, 0x11D32BFB} } ;
		static const fp2_t var_expected =  { {0xF6EA3B70, 0x7886263E, 0xFD663E50, 0xDB93713F, 0x6F6805C2, 0xD442CA2C, 0x07D409EC, 0x7C78F21E},
	{0x5AD284D3, 0x2FF5AC2F, 0xEDC43EF0, 0xADB0FF51, 0xA9A0FB1F, 0x4FA2A3CC, 0x3D0237E8, 0x9985B664} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 137 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 138 a1");
	}
	{
		static const fp2_t var_a =  { {0x1FB897C2, 0x23D8B689, 0x073ED96B, 0x4E4EC432, 0xD38F386A, 0x627CB827, 0x437945DF, 0x371F3509},
	{0x275B6C2C, 0x2F1DB0D9, 0x5E614888, 0xC6D549D9, 0x50F3C4D2, 0x801B764C, 0x2A35F621, 0x27E83343} } ;
		static const fp2_t var_b =  { {0xA560D994, 0x78977098, 0x526A0C2D, 0x96BB5ABC, 0x277D00E1, 0xC9E4617A, 0x383C0BC8, 0x3B435FB1},
	{0x98FB8429, 0xA1A26CBB, 0xEE0D9BE6, 0xB714C516, 0xB6D999D7, 0xF573B0C9, 0x23928175, 0x129F00C5} } ;
		static const fp2_t var_expected =  { {0xDC83F2C9, 0xAA2FCFA1, 0x894CAC84, 0xCAA51616, 0xFFF4C13D, 0x93F8B318, 0x4B5C163F, 0xB5EF741A},
	{0x8E5FE803, 0x8D7B441D, 0x7053ACA1, 0x0FC084C2, 0x9A1A2AFB, 0x8AA7C582, 0x06A374AB, 0x1549327E} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 139 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 140 a1");
	}
	{
		static const fp2_t var_a =  { {0x678D4533, 0xFDE9E3CA, 0xE4BC06C7, 0xDDE3EBF0, 0x65FE055A, 0x2869CCA9, 0xE84D346C, 0x13AA15F9},
	{0xD6845B38, 0x1939C78D, 0xCABCFAA8, 0xAAEF6B73, 0xD727B8CF, 0x823F32B4, 0x454C22E2, 0x063AB6E5} } ;
		static const fp2_t var_b =  { {0x8D7E9888, 0x34C4034E, 0x893E1CA8, 0x2C31D732, 0x6CF2B905, 0xA277C3A0, 0x3D7EE5D3, 0x93D2B7EA},
	{0x7BD36D0D, 0xC0FAA7FE, 0x10C8DEB9, 0xC0ECAF2F, 0x656EAF5F, 0x0B7737D5, 0xD7CF6A6C, 0x63DEE6D0} } ;
		static const fp2_t var_expected =  { {0x3C3AE146, 0xC8146A2D, 0x2FF5C966, 0xC4C3C15F, 0x4CEDD60A, 0x81526574, 0xEAED2AC1, 0x39EAFCD1},
	{0xBCDD22C6, 0x572DA940, 0x8E6BFB35, 0xFD1468E5, 0xC59B9324, 0x7228574A, 0xAD9B949F, 0x5C6F6ED6} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 141 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 142 a1");
	}
	{
		static const fp2_t var_a =  { {0x70FBA0F6, 0xE5CDF68F, 0xA70E5BB6, 0x3267048C, 0xBFECF527, 0xBF6DBBB8, 0x5EF577A1, 0x00727E0F},
	{0xEA67162A, 0xFA0C2470, 0x6C014830, 0xACABBED1, 0xA8152880, 0xA036349D, 0x649AB8BF, 0xAF3D1E17} } ;
		static const fp2_t var_b =  { {0xBB2893C5, 0x12A2D748, 0x886797BD, 0x7A8F8089, 0xBD69D35B, 0x20F85279, 0xB8AD229C, 0xAF840613},
	{0x016C3922, 0x6E5C3E14, 0x237294F4, 0x374A100D, 0x7B1E9916, 0x99C88BBE, 0x340FD8F1, 0x3DEEF179} } ;
		static const fp2_t var_expected =  { {0x17FF41CC, 0xD219A8F8, 0xF31EA340, 0xCAE930A3, 0x5665AB80, 0x99D5C5AA, 0xE667312E, 0x0B0216BD},
	{0xE8FADD08, 0x8BAFE65C, 0x488EB33C, 0x7561AEC4, 0x2CF68F6A, 0x066DA8DF, 0x308ADFCE, 0x714E2C9E} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 143 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 144 a1");
	}
	{
		static const fp2_t var_a =  { {0xA6FEEC29, 0x021EB5AD, 0xE82DAC27, 0x48C4FAA0, 0xBD9B83B6, 0xCAB33AEA, 0x31340E9A, 0x1FEC3C7D},
	{0x69CDC162, 0xFC808DD0, 0x0BBF9CAA, 0xB69B5A85, 0x4C859220, 0x8036D696, 0xCFC2833F, 0x8BB69457} } ;
		static const fp2_t var_b =  { {0xD3155715, 0x3B07FF0F, 0x412ED2AD, 0x58ABFC44, 0x4F522E8D, 0xF147F034, 0xB26FD742, 0x3D0E5414},
	{0x59650C45, 0xCED33C12, 0x6A88AF12, 0x3B3C6AB6, 0x7B8E124E, 0x3A793632, 0x40B3BAC9, 0x3A79FC6C} } ;
		static const fp2_t var_expected =  { {0x3615C9AF, 0xC605404F, 0x7B76B8C0, 0x032AAAFD, 0xC22BDEDE, 0xD4CBA721, 0xBEE31380, 0x9CF1872A},
	{0x1068B51D, 0x2DAD51BE, 0xA136ED98, 0x7B5EEFCE, 0xD0F77FD2, 0x45BDA063, 0x8F0EC876, 0x513C97EB} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 145 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 146 a1");
	}
	{
		static const fp2_t var_a =  { {0x4BB25F1B, 0x7D5B83B2, 0xC8AC80A4, 0xE04A2EAA, 0x400A21A0, 0xFAB5817D, 0x24318CDD, 0x64A01FB4},
	{0x5BA20322, 0x45B169E9, 0x6E091142, 0xB065CFBA, 0x4A23ECF5, 0xCB684626, 0xCEAC091A, 0x003C3062} } ;
		static const fp2_t var_b =  { {0xA422102B, 0xD34AFCE2, 0x2546D77B, 0xD123BAB0, 0x52263A47, 0xAFE06EDB, 0xF18C0C32, 0x1AB2D713},
	{0x28D24CB7, 0x0AE95EA9, 0xDD252FA4, 0xA3A3F927, 0x9AB6ADED, 0x9A0C06D2, 0x03E6A27D, 0x04AC7631} } ;
		static const fp2_t var_expected =  { {0xA7904EF0, 0xAA1086CF, 0xA365A928, 0x0F2673FA, 0xEDE3E759, 0x4AD512A1, 0x32A580AB, 0x49ED48A0},
	{0x94FBEB06, 0x39B694F1, 0x655BC0E5, 0x1FD38333, 0x034FC8BD, 0x2CBC9BBF, 0x0AE442C6, 0xB5A358F4} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 147 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 148 a1");
	}
	{
		static const fp2_t var_a =  { {0x672E49BB, 0x7F998059, 0x0E113FB7, 0xE1FEABD8, 0xD05FE0B4, 0xF924E6A6, 0x8217143A, 0x38964127},
	{0xC9F76431, 0xFEED67C3, 0x5F787A2E, 0x80C33DC7, 0x2B80E2E6, 0x29EB9023, 0xAA837DAE, 0x78396F7C} } ;
		static const fp2_t var_b =  { {0x34792591, 0x069AF930, 0xFC7A5C2B, 0xCF07F30C, 0x4DFFBF6E, 0x08EA1171, 0xBF4BA473, 0xACE39AA9},
	{0x77158C6E, 0x4A45EABF, 0x3F652248, 0x57839D7D, 0x5F5D3C5C, 0x605A6C01, 0xC835833C, 0x049C6D13} } ;
		static const fp2_t var_expected =  { {0x94E158C5, 0x77ED10DA, 0xE60EC2D3, 0x2608656B, 0xD642AAFB, 0xEB9B31A0, 0x02EA4BF0, 0x45C64540},
	{0x52E1D7C3, 0xB4A77D04, 0x201357E6, 0x293FA04A, 0xCC23A68A, 0xC9912421, 0xE24DFA71, 0x739D0268} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 149 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 150 a1");
	}
	{
		static const fp2_t var_a =  { {0x29B46ED9, 0x2D6C7AB8, 0x0050DF8B, 0x6FAFB04B, 0xF0CE0454, 0x5E4803D5, 0x5130E841, 0x3063E3BA},
	{0xBA02B4E8, 0x4EBB2A36, 0xA5277E96, 0x1083714A, 0x77101EDE, 0x41CFA963, 0xA9B6B1D6, 0x5BEEB10A} } ;
		static const fp2_t var_b =  { {0x6664A67C, 0xFC092893, 0x132E35AB, 0x00C54F83, 0xCCB3E513, 0xAEE379A1, 0xA264B01E, 0x30289508},
	{0xAFE263F5, 0xB4B7D3EB, 0x2F5C2BF6, 0x500581CF, 0xA7089705, 0x308EFE25, 0x1590278F, 0x5C478FCF} } ;
		static const fp2_t var_expected =  { {0xC34FC85D, 0x31635224, 0xED22A9DF, 0x6EEA60C7, 0x241A1F41, 0xAF648A34, 0xAECC3822, 0x003B4EB1},
	{0x6C4C858E, 0x98F1DFFC, 0x4A4331E6, 0xD38F9C1C, 0x23EA118D, 0x0CA107A9, 0xD4456670, 0xB9BABFFD} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 151 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 152 a1");
	}
	{
		static const fp2_t var_a =  { {0x721E4D0B, 0xB2817D85, 0xE98DE19B, 0x3753778B, 0x2DA02AE0, 0xE1953BF2, 0x1BD35EE2, 0x867A16B8},
	{0x371C660B, 0x5FD1F185, 0x08B7A261, 0x4786FB65, 0xB52C8475, 0xBC1A772F, 0x14F9099C, 0x0F6EB4E9} } ;
		static const fp2_t var_b =  { {0x66DAC6A9, 0xDAF987F4, 0xAB9B8095, 0x85C55C03, 0x54CB79E1, 0x3D002E1E, 0xA4076172, 0x39D6F420},
	{0x158C87F8, 0x7473C512, 0xCB3C995D, 0x5231F6E0, 0x527F3679, 0xBCA79747, 0xB1CE2D8A, 0x0142A72E} } ;
		static const fp2_t var_expected =  { {0x0B438662, 0xD787F591, 0x3DF26105, 0xB18E1B88, 0xD8D4B0FE, 0xA4950DD3, 0x77CBFD70, 0x4CA32297},
	{0x218FDE13, 0xEB5E2C73, 0x3D7B0903, 0xF5550484, 0x62AD4DFB, 0xFF72DFE8, 0x632ADC11, 0x0E2C0DBA} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 153 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 154 a1");
	}
	{
		static const fp2_t var_a =  { {0xAD9D4E50, 0x35F8A2F3, 0x65D6DAED, 0x34BDCBD0, 0x6209AC42, 0x247B284B, 0x67942D58, 0x5DF223D8},
	{0xE695C563, 0x582DBA6C, 0x7BD28334, 0xFBB19EE8, 0x1A2EEFB4, 0x48677D9C, 0xF4239124, 0x448B694A} } ;
		static const fp2_t var_b =  { {0x40F1A1C7, 0xCAB5EFF4, 0x91951B85, 0x47D7C816, 0x6D8EABBA, 0x5BC6A648, 0x0CCD7983, 0x315A4A01},
	{0x120DE47C, 0xAFAD8342, 0xB12436BA, 0x575923EB, 0x3B1231B9, 0xA6BA076F, 0x2669A539, 0x14324ECA} } ;
		static const fp2_t var_expected =  { {0x6CABAC89, 0x6B42B2FF, 0xD441BF67, 0xECE603B9, 0xF47B0087, 0xC8B48202, 0x5AC6B3D4, 0x2C97D9D7},
	{0xD487E0E7, 0xA880372A, 0xCAAE4C79, 0xA4587AFC, 0xDF1CBDFB, 0xA1AD762C, 0xCDB9EBEA, 0x30591A80} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 155 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 156 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 157 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 158 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 159 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 160 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 161 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 162 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 163 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 164 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_b =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 165 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 166 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_b =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 167 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 168 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 169 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 170 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_b =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 171 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 172 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_b =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 173 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 174 a1");
	}
	{
		static const fp2_t var_a =  { {0x2962ECB1, 0x2EB690BB, 0x67085388, 0xA8865D02, 0x70E6E0EC, 0x6A6B47BA, 0x807ED193, 0x291C30CA},
	{0xCFECEC0B, 0xAC51D257, 0xD59A780E, 0x7E5E44E5, 0x8E09EFC1, 0xF33321C9, 0x24B9DFAC, 0x4A97FE7D} } ;
		static const fp2_t var_b =  { {0xA702D359, 0x957115CF, 0x81C666D1, 0x9F9D3349, 0x5D7BF120, 0xF2A8C08E, 0x8C14F5BB, 0x7BA62F16},
	{0xC7DB2B90, 0xE4E222A9, 0x09CCCA56, 0x0566E3B4, 0xE9922D47, 0xC1EB2409, 0x7A7E5BE3, 0x42B4E84E} } ;
		static const fp2_t var_expected =  { {0x62349232, 0x5E38BEE9, 0x02690D22, 0x113D5C65, 0x310E3593, 0x77410593, 0x333882B0, 0x0BA5104E},
	{0x49BE7B34, 0xFD9B696C, 0x9B96C75F, 0x8B3D588A, 0x1B18C3EB, 0x4D591664, 0x81288F36, 0x473AEE35} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 175 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 176 a1");
	}
	{
		static const fp2_t var_a =  { {0x46D20609, 0xE1D9D794, 0x153A009C, 0x17445D82, 0x74D1D613, 0x9BB73A76, 0x8E4E7075, 0x1D7AD0AD},
	{0x2233BF39, 0x89999F68, 0xC1464C94, 0x1248ACC0, 0x650C636F, 0xE0014CC5, 0x857378FE, 0x70D8EB23} } ;
		static const fp2_t var_b =  { {0xE6BC3413, 0x116E9B06, 0x3902EF92, 0x7E77B5C8, 0x79C0C375, 0xC440FD38, 0x5750C47E, 0x1443D4ED},
	{0x0A8E7685, 0x22E9A746, 0xD49980C0, 0x09CA8187, 0xCBD61421, 0x239986E8, 0xE3D07CB7, 0x2678DC5B} } ;
		static const fp2_t var_expected =  { {0xAD1991DB, 0xFE97D181, 0xF7F30532, 0x7C543741, 0x323168EE, 0xBB39DB5C, 0x00414D1B, 0x9916A6A4},
	{0x23BF20FB, 0x7CBA5DCA, 0x85312D12, 0x16CFBF93, 0x4B9A2D89, 0x5A580A9A, 0x9EAA09F0, 0x0E7C1DBF} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 177 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 178 a1");
	}
	{
		static const fp2_t var_a =  { {0xF92FF612, 0x91437C32, 0xA6010AB9, 0x63568CCC, 0x146E49A0, 0x89442241, 0xE7BD6D92, 0x8E5D3686},
	{0x06F42307, 0xB919EE8D, 0x562A93A0, 0x3BD26EC2, 0x7F724A54, 0x8C24B5AD, 0x89F76175, 0x5F8DF627} } ;
		static const fp2_t var_b =  { {0x93B130DF, 0xF2D579FB, 0x4962FDC7, 0xAF18B0AD, 0xF8D3D796, 0xF9C237A8, 0x36E865FC, 0x50EE1A6F},
	{0xCDF59262, 0x972C63E0, 0xAF383B22, 0x9410E4E5, 0x6A83C6BB, 0x6049C4BA, 0xD189C01D, 0x94E7BD09} } ;
		static const fp2_t var_expected =  { {0x6B6B476D, 0x079474AB, 0x418AE85C, 0xC34D9118, 0x9AA87117, 0x751E489A, 0x08B73B59, 0x366A6AFC},
	{0x718A4B03, 0x85BFF1EF, 0x01D067D3, 0x2294B9E3, 0x0E0E670B, 0xF27A79D0, 0xAA81A994, 0x8E32CA86} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 179 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 180 a1");
	}
	{
		static const fp2_t var_a =  { {0x847DF004, 0xA2F0CC76, 0x67141BE9, 0x0C6B07E9, 0xF4934F31, 0xF11DA837, 0x1C0DCF85, 0x0012122E},
	{0x6C253D2C, 0x8A3E2982, 0x0716B5F6, 0xC0E3282D, 0xE6E10FD6, 0x837122A1, 0x8AF47BD0, 0x99A3DDB0} } ;
		static const fp2_t var_b =  { {0xF319B41E, 0x8AABF385, 0xFB3F0CA0, 0x5251A6ED, 0xA6E2AA15, 0x22D4F0C6, 0xFAF92DA7, 0x344CEB94},
	{0x5D82B21E, 0xFF61C0B8, 0x413981CC, 0x96710739, 0x7033528E, 0xAD9F918A, 0xBC9611A6, 0xB9543B42} } ;
		static const fp2_t var_expected =  { {0x83166463, 0x5A3EC50A, 0x49960642, 0xE9E697A5, 0xE6832C2B, 0x38EF6DFD, 0x63461BEB, 0x8CE689C6},
	{0x5F226FC8, 0x08561F61, 0x4E37270B, 0x83B48B8C, 0x430A338B, 0x7A186D43, 0x95044DB0, 0x387BEA22} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 181 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 182 a1");
	}
	{
		static const fp2_t var_a =  { {0xDEC233CE, 0xD2594AEB, 0x20054EE9, 0x426C0885, 0x845B5019, 0x2DEB1919, 0x2DD7D85C, 0x9F218E20},
	{0x92796927, 0x00432167, 0xA71FAA85, 0x59416E9A, 0x32B6446E, 0x95B010B7, 0xE3FEFA30, 0x19409629} } ;
		static const fp2_t var_b =  { {0x7B4E7BC9, 0x2F4CE840, 0x1D8FC82F, 0x4962D304, 0x8AC2759C, 0x9E50F1F7, 0x152F9053, 0x1118EAD3},
	{0x9AD8861D, 0xC2A7A29D, 0x1316A30D, 0xD323CB83, 0x61746CEC, 0x15A8B136, 0xA712E484, 0x64BCF72D} } ;
		static const fp2_t var_expected =  { {0x4BC2155C, 0xEF3CF487, 0x5EA5BF96, 0x85712F70, 0x87FB84F9, 0xC79FA470, 0x4EF046A4, 0x4257B15C},
	{0x73D0100B, 0x3CA408BA, 0x6F1165DD, 0x723B52D5, 0xF5A3E03A, 0x4C8B6677, 0x47CA931F, 0x00EFE559} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 183 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 184 a1");
	}
	{
		static const fp2_t var_a =  { {0xA87AA553, 0x392EADDB, 0x3790A92D, 0x5205AA1B, 0x6ABE24CA, 0xED77F0B0, 0xD7010520, 0x92BA2359},
	{0xAA77DB30, 0xB598FAD4, 0x5FC3BF36, 0x0C3E2BE4, 0xA3051338, 0x333385CF, 0x5B439D76, 0xA963B551} } ;
		static const fp2_t var_b =  { {0x7BBD0B58, 0x684039AC, 0x0CA4D710, 0xEE6214DE, 0x4AA9EDD7, 0xB72A3EFB, 0x7F73B32E, 0xAC4BDB1F},
	{0x364DDBED, 0x328FBA80, 0x8C5679FC, 0xBF9A9FED, 0xE5FAA9B0, 0xFF5B326F, 0xFE248357, 0x0C2B2774} } ;
		static const fp2_t var_expected =  { {0xFB47EB48, 0xC71394B0, 0xF22322A5, 0xEDF51A1C, 0xBC30A82A, 0xD592A880, 0x3FD4E9E0, 0x90C98081},
	{0x40D34732, 0x26E6D754, 0x3EF6BE3C, 0x0A905149, 0x60217593, 0x3E83A674, 0x07CFD381, 0x09ACF2CF} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 185 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 186 a1");
	}
	{
		static const fp2_t var_a =  { {0x94302247, 0xBE53B72E, 0xB2D48E2C, 0x6881CD94, 0x68F63A45, 0x13452D23, 0xD453DF00, 0x3D5AD8D4},
	{0xB8EFB75D, 0x373F010C, 0x6C632925, 0x69BE07FF, 0x34D5C5E8, 0x1734AD70, 0x390E3F4F, 0x29BBF950} } ;
		static const fp2_t var_b =  { {0xA3CE633E, 0xE428CD98, 0x8AAE793A, 0x47E7705C, 0x720CF9C2, 0xFF834960, 0x4307DB81, 0x7B38A561},
	{0x30766AD2, 0x5B137C54, 0x8BA8FFA4, 0x94A51BAA, 0xCD660181, 0x5A89F3A2, 0x53BC5284, 0x8E0F98D2} } ;
		static const fp2_t var_expected =  { {0x96117796, 0x9245F6FE, 0xB3147D6D, 0xEC68D712, 0xB307435A, 0x843743BC, 0x0D0364D4, 0x463FD2B4},
	{0xF2A6A1FB, 0xB1A9C014, 0xB2891A32, 0x293DB7F2, 0xB57F31E5, 0x13AC27F6, 0xFD5DD81B, 0x8CA5428E} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 187 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 188 a1");
	}
	{
		static const fp2_t var_a =  { {0xE05389CA, 0xBFB64482, 0xEA886F9E, 0x428DBFFB, 0x1707159C, 0x4EAC9D0D, 0x12E2438D, 0x68FABBFC},
	{0xE124ED2C, 0xC44F827B, 0x6EBE7524, 0x4390344B, 0x0DDBB42F, 0xCB8750CC, 0xDECEE1E1, 0x3C59F5A6} } ;
		static const fp2_t var_b =  { {0xAB212145, 0x10CB4F6E, 0x9AF1F7CA, 0x7AFD15B1, 0x6F611FE2, 0x4B3807EC, 0x741B1B42, 0x1E6E9E42},
	{0xF44C7ABD, 0xC63A1C82, 0x7E9B33FD, 0xA8FA46C7, 0x08A3B05B, 0xD352E8F4, 0x338BCDA9, 0x692E1BFA} } ;
		static const fp2_t var_expected =  { {0x293BCED2, 0x28A0F6CB, 0x8CFFE892, 0x6C6B79B6, 0xD77471C6, 0xA649E6F9, 0xB8211BD0, 0x8D86D9A7},
	{0x1EF41F48, 0x395B4FFF, 0xE695AA1A, 0x6A64F174, 0x1F2470FB, 0xC5D2CE42, 0xF12883D4, 0x73FDFE4F} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 189 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 190 a1");
	}
	{
		static const fp2_t var_a =  { {0xC5FFFDA2, 0x3382B547, 0x2EF4AE76, 0x6DFC4887, 0x79E198F3, 0x680A1996, 0x75249B66, 0x86B88780},
	{0xCD70E317, 0xFB97B1F6, 0x07860830, 0xD54088A5, 0x8FC73AC6, 0x6E18516E, 0xCE4E5B6D, 0x3840476A} } ;
		static const fp2_t var_b =  { {0x9C90D694, 0xC7779A2D, 0x935352B3, 0xFC917659, 0xEB8CFC3A, 0x853BFB2B, 0x7FFB7BE4, 0x12988D27},
	{0x93F67E47, 0x12250B10, 0x5E4F6183, 0xA9FDB17B, 0x22C394BD, 0xE0FB3654, 0xD1C9BA90, 0x4255DAD3} } ;
		static const fp2_t var_expected =  { {0xAA34A37F, 0x6CCFC5A6, 0xD227F73F, 0x312BF6CB, 0x5602FD3D, 0x827F2E61, 0x654793E4, 0x912C1E08},
	{0xC49A2093, 0x884A1A3E, 0x1F51B37B, 0x5D075264, 0xFEA3A306, 0x884EE5E6, 0x32F3F3DB, 0x1F2B38EA} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 191 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 192 a1");
	}
	{
		static const fp2_t var_a =  { {0xD337BEF8, 0xA0E5CB78, 0xC380BB8B, 0xEFCC8268, 0x83544639, 0xC59B95B3, 0xE5356523, 0x4BDE7241},
	{0x001E15B1, 0x8839C6B0, 0x4E47AF9B, 0x5688550D, 0x0BAE9817, 0xB3071AE2, 0x926F0C95, 0xA42B474B} } ;
		static const fp2_t var_b =  { {0xDB9CE256, 0x2E5FC72F, 0xAC6EBBBB, 0xAF7099E8, 0x6695E671, 0x3AB9D87C, 0x6843521B, 0x57CA42C0},
	{0xDB258FD8, 0xA1EDC1F8, 0x1EB941B2, 0xB814BEEB, 0x2E74F268, 0xA19FF4D8, 0xBDF63052, 0x64DC8502} } ;
		static const fp2_t var_expected =  { {0x0CC3BFC2, 0x05039AF1, 0xD836F8F9, 0x06B02F5C, 0xF6832DE2, 0xEA88DE22, 0xAC25CB14, 0x6F4D051A},
	{0xE28C24D1, 0x040307A0, 0x59ED5C8D, 0xF3099C8D, 0xFAE309DF, 0x5DBAB3AB, 0x893C9DF2, 0x868276A7} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 193 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 194 a1");
	}
	{
		static const fp2_t var_a =  { {0x79157C20, 0x8A1ED4B2, 0x8A1EF35E, 0xEEDF70D8, 0x9ADCD5EE, 0xFD54115C, 0x1AB27F1A, 0x57237E79},
	{0xDF7D0851, 0xF08D527A, 0x01DE3CB8, 0xAB38AD4A, 0x3D8712DD, 0x2BCEE7CE, 0xA05D3FE0, 0x3F049669} } ;
		static const fp2_t var_b =  { {0x8EEDD818, 0xAA4CDF40, 0xC150C54D, 0x16CDCD10, 0xBD15C290, 0x14C43CE7, 0x053E0CD7, 0x5714373F},
	{0x6B0497D4, 0xF922382A, 0x59DD2E88, 0xCCF4F589, 0x3CF39D7C, 0x95DF6E4E, 0xB8AFEA9F, 0x1F6B7200} } ;
		static const fp2_t var_expected =  { {0xA15C91E9, 0x01275A7B, 0xFF422041, 0x8F31A7A2, 0xFDA6C5D3, 0x127B7C50, 0x7AE5D7BB, 0x47ACF80A},
	{0x437C07A8, 0x02FDE9B0, 0x305C1B4B, 0x6DE82B3A, 0x797CB7B6, 0x05FE1590, 0xF3A0C3DC, 0xB08820B1} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 195 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 196 a1");
	}
	{
		static const fp2_t var_a =  { {0xD0C9BF7D, 0x4B648234, 0xDDBF8D59, 0xA03D4CFA, 0x222848C8, 0xCEECEF3E, 0x46CE550F, 0x4C9ABA7B},
	{0x97AA3535, 0xE706FAB4, 0x946D0A6A, 0xBC91CECC, 0xFD7EB3E7, 0x46506403, 0xA9F8ADD5, 0x3A9F35BF} } ;
		static const fp2_t var_b =  { {0xF686CE55, 0x4A6A79CC, 0x02129FDB, 0xB646DDC5, 0x1CF7A4B5, 0xD7CA89E7, 0x89B55042, 0xB9194175},
	{0xAF2BF790, 0xA1CBCADB, 0x46DE5BA3, 0x12B2BB89, 0x4E2F3064, 0x4FD908B0, 0x884104F7, 0x4268FAA5} } ;
		static const fp2_t var_expected =  { {0x5045EC81, 0x994EC737, 0x73467EBE, 0x872A0786, 0x75081996, 0xFFE616B8, 0xCA8686A4, 0x726795FE},
	{0xC5AE8D9B, 0x4321F2C4, 0x76EA1274, 0xEA6284AC, 0xB7708449, 0x9AA3D7D3, 0xB05A312F, 0x69BF547C} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 197 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 198 a1");
	}
	{
		static const fp2_t var_a =  { {0xBDA9B0BF, 0x6AD3E76C, 0x06C6E97E, 0x71683EFD, 0xC8117105, 0x42833965, 0xC7C95BC0, 0x78BBDB50},
	{0x59B17C86, 0x8CE7D19F, 0xF7103CD2, 0xBB230752, 0x8D570442, 0x895E2272, 0x747831A9, 0x6CABAADF} } ;
		static const fp2_t var_b =  { {0xA253889E, 0xFC6AC330, 0xA3B89355, 0x40A8D8A0, 0xC76535AB, 0xCA4BBBF0, 0x72335A71, 0x7778B345},
	{0x291284C4, 0x174C77F9, 0xB8E006DC, 0x727E078B, 0x221BFF52, 0x797B51A5, 0xDA9E9962, 0x5B148C94} } ;
		static const fp2_t var_expected =  { {0xA64FFB2F, 0x4F70D8FD, 0x009C3961, 0xA7385494, 0x7307C26C, 0x98E126BB, 0x4F3A8A07, 0x4932314D},
	{0xA64B7DDB, 0x637B4357, 0x2F8ECDD3, 0x70A82FB0, 0xB94EA73F, 0x2CDC84C0, 0xDD2AA83F, 0xA07D3026} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 199 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 200 a1");
	}
	{
		static const fp2_t var_a =  { {0x81DD0E4D, 0x341D339E, 0x2B4834FE, 0xC4E466D1, 0xF4754228, 0xF124DB18, 0xAD646B63, 0x2E855B1B},
	{0x7C2081C2, 0xC06E7660, 0x896C5997, 0x9096DAA0, 0x9AF74A13, 0x86892751, 0xF14E1383, 0x0F09521B} } ;
		static const fp2_t var_b =  { {0x6AD53A16, 0x572B3630, 0x80FD176E, 0x949AC338, 0x581298B6, 0xA4308C67, 0x47FCC06A, 0xB8ACF439},
	{0x46726111, 0xAC917E62, 0x1344EAAB, 0x4DFCE365, 0xFCAB9746, 0xEC561B0D, 0xC8196404, 0x25CE8D47} } ;
		static const fp2_t var_expected =  { {0xBBD08385, 0xF3CD9EE1, 0x75378391, 0x271BA814, 0x095CAC3A, 0x710B3FDB, 0xC5782C37, 0xB8B91CEA},
	{0x4DC8E798, 0x73A0668E, 0xECDCCEFF, 0x78529E16, 0x6A05A1A3, 0xF3E32772, 0x6E6829B3, 0x44C787A5} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 201 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 202 a1");
	}
	{
		static const fp2_t var_a =  { {0x739DEAE8, 0x10DD8AD8, 0x37F2CE43, 0x28D5F348, 0x08EF8AAC, 0xF17FB382, 0xD14418DB, 0x6663D031},
	{0xA83C9E02, 0x83139C42, 0x2BC0898A, 0x771276F7, 0x877A40AB, 0x73258865, 0x0567CA1A, 0x73054C38} } ;
		static const fp2_t var_b =  { {0xB22F2CAF, 0xB29D896E, 0xA679BD57, 0x944640E3, 0x299888C2, 0xAE908561, 0x928C48F5, 0x27CEFFDE},
	{0xDAB46E74, 0xC9883550, 0x12269766, 0x339F8058, 0x2E4EFEAB, 0x919A1492, 0x1E52D155, 0xA58FF6CA} } ;
		static const fp2_t var_expected =  { {0xE46F07DE, 0x62DDED23, 0xE90F2E88, 0x52BF470E, 0x8F345ADE, 0x11EE2E8F, 0xE81BC4D6, 0x91C94FE9},
	{0x5FE4A77C, 0xC446224B, 0x8888136E, 0xC2F98B00, 0x1EC46356, 0xB983B91E, 0xF4994D7D, 0x28F3028C} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 203 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 204 a1");
	}
	{
		static const fp2_t var_a =  { {0x4E1489D2, 0x8497477A, 0x128D7CF9, 0x612A070C, 0xEB414DD4, 0x1E2DAC4A, 0x31D7A8A1, 0x19FA1C4C},
	{0x1EDE5A46, 0x8A0BBC95, 0xA3D1C44E, 0x4EE60487, 0x7D8A5E9F, 0x3F72160A, 0x55CC7615, 0x303E97E8} } ;
		static const fp2_t var_b =  { {0x18E34BA8, 0x0708B204, 0x028A4C14, 0x72F015EF, 0x805646C0, 0x9E85B90B, 0x1784A246, 0x5D6808CD},
	{0x264B6558, 0x5E7B799B, 0xDCDAAB0B, 0x47D8BE4F, 0x62DDBBDA, 0xDAAA2B34, 0xFDAF7FE7, 0x3F566773} } ;
		static const fp2_t var_expected =  { {0x932DF437, 0x7EC42B49, 0xA7E5B16C, 0x96F3AF0C, 0xC2AACA60, 0xDE138CA5, 0x0B3BE05F, 0x1632AB0B},
	{0xD743BA08, 0x30A9F884, 0x1D38BF3B, 0x24E445CE, 0x3B645946, 0x3C057E32, 0xFAC11F44, 0x1BB15F9E} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 205 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 206 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 207 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 208 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 209 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 210 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_expected =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 211 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 212 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 213 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 214 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x26849DD1, 0xFCCB9D14, 0x7D679DD4, 0x393505E2, 0xFBA79D1F, 0xF2211541, 0xC05C947A, 0x2E3ADC46} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 215 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 216 a1");
	}
	{
		static const fp2_t var_a =  { {0xF3BB96EC, 0x4CC3421E, 0x6F60FFB5, 0x9113839D, 0x77683735, 0x808B3754, 0xA293C2D9, 0x7F05DEEA},
	{0xBFF1E2A5, 0xF650E632, 0x73E8E67E, 0xF472A444, 0x9BB55AAC, 0x2692028F, 0xD042F909, 0xA866497F} } ;
		static const fp2_t var_expected =  { {0xB2AA90E4, 0xF8DA34BC, 0x0F81ECC2, 0x08A00882, 0xF0399841, 0x415F0581, 0x212F4941, 0x0B5CC551},
	{0x189ED2B3, 0x48AB7185, 0x5315F545, 0x8E6FCC25, 0xFB490B80, 0x10ADDAB0, 0xE093E7FA, 0x745AE612} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 217 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 218 a1");
	}
	{
		static const fp2_t var_a =  { {0x7D16BBB7, 0x0843D7CD, 0x95532DCE, 0xFA9B8F3C, 0xEDD2AED5, 0xE14FA49C, 0x6FDD763C, 0x12A907D2},
	{0x576C8DCF, 0xF64CBA42, 0x3A295C85, 0xEABDC60B, 0xDD150F64, 0xBC9182DE, 0xDA7E310D, 0x9326FBD9} } ;
		static const fp2_t var_expected =  { {0x99350712, 0x9B5002E6, 0xC31F3442, 0x3C1AFCE4, 0xCFE6B25F, 0x4504F8D4, 0xDF98648C, 0x7590FCC3},
	{0x13E73F33, 0xDC63CF0B, 0x142D0393, 0x8A564DAD, 0x371C7134, 0x41E2A6C1, 0x4610D991, 0x0C7B7214} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 219 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 220 a1");
	}
	{
		static const fp2_t var_a =  { {0xC24A47DF, 0x5519A1AA, 0xE1CC7DF3, 0x89CCA066, 0x807E0B40, 0xDAED8393, 0xC0194F4D, 0xB04C67FD},
	{0xD2B955E7, 0xA2B8EFB6, 0xB8514443, 0xCFC7B9D8, 0x71A54F0D, 0xB88D0A3A, 0x9481F706, 0x819CD25B} } ;
		static const fp2_t var_expected =  { {0x26031CE5, 0x09E8AF22, 0x46B685A2, 0x1A39B521, 0x66774441, 0x6A99C5BC, 0x19B1DFB7, 0xA02AA95B},
	{0x0923481F, 0x901B18D4, 0x19DED88C, 0x8844CE7D, 0x27A3B2D3, 0xD3C19B73, 0x1D30D4F1, 0x6B8465D4} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 221 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 222 a1");
	}
	{
		static const fp2_t var_a =  { {0x4B4C43D9, 0xF5A2D535, 0xC3ADB24C, 0x5AD40A7D, 0x2586CF0C, 0xE0B1FB89, 0x02D0484A, 0xA3E8E9DD},
	{0x722B886B, 0xEDA4A742, 0x4FE40F1B, 0x856AF262, 0x6D804CAC, 0x54BD74D6, 0x18775DB9, 0x777B79B9} } ;
		static const fp2_t var_expected =  { {0x4BAA3838, 0x24DACB77, 0x701FA99B, 0xAD1D1AE8, 0xA64FABB1, 0xF45EC857, 0xBE36E247, 0x8FE15E70},
	{0x2753A9AA, 0x5FCE421E, 0x62A1CC33, 0x8F918B3A, 0x01129609, 0x8A34876C, 0xA9672F86, 0xBA0BBCB8} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 223 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 224 a1");
	}
	{
		static const fp2_t var_a =  { {0xD3317CB9, 0x62E801C8, 0xDE544B87, 0x66BEAF1A, 0x62C7BE90, 0xFCE6E1CE, 0xFC88FE3F, 0x0FE563B8},
	{0xFC74FDD1, 0xBD525ED0, 0xCE8D8114, 0x783D588B, 0xBF5A9FF7, 0x116B83FE, 0x48AEE773, 0x2604C5E3} } ;
		static const fp2_t var_expected =  { {0x93A1E54F, 0xC9FF7398, 0xF91B8229, 0xEA15F915, 0x25745F3D, 0x68B5D6DD, 0xEE68F5C1, 0x0FBE86BB},
	{0x65FDDE52, 0x77E3ADD0, 0xEA2CD732, 0x6B16E591, 0x3EFF7D7A, 0xDCAB9701, 0x27313180, 0x438467D8} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 225 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 226 a1");
	}
	{
		static const fp2_t var_a =  { {0x8BD8458F, 0xAA0C553A, 0x5B54E71D, 0x8103A26D, 0x7F5C4C01, 0x47F1C74B, 0x105C91C4, 0x84CF24CE},
	{0x69F21CDC, 0xE1C5CD71, 0x4C704BF5, 0xE9B29E39, 0xDD137B88, 0x6642C8F6, 0x8AE8358B, 0x5E8E19AE} } ;
		static const fp2_t var_expected =  { {0x377E6BD6, 0xAE1094CD, 0xFF5270FF, 0xA55F1660, 0x34D68DE8, 0xF58BA5ED, 0x29227B7D, 0x1AAC3F8D},
	{0x1CE626EF, 0xA6E1AC40, 0x2B662F3C, 0x1EEFAE30, 0x71A2E480, 0xAAFE51C7, 0x4A611C6F, 0x5561E3DC} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 227 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 228 a1");
	}
	{
		static const fp2_t var_a =  { {0x73A37A50, 0x6B0A2F83, 0x19D035F3, 0x26C8107C, 0xE562D434, 0xB5E9BEE7, 0xC98A8C94, 0x083DC4B6},
	{0x9E9C4E60, 0x7762CCB8, 0x1C17F6F6, 0xC2ACD76B, 0x0459C8FB, 0x67A722D7, 0x8E6A4821, 0x1D6AFC03} } ;
		static const fp2_t var_expected =  { {0x8F64AB50, 0x8C5478FA, 0x84EDC7E3, 0xB2F57AB1, 0x934EDADA, 0x39344C46, 0x263A6C69, 0x8A397BF5},
	{0x3A000F13, 0xF45A6FA0, 0x7F0508CD, 0x20D103AE, 0xC0BC9731, 0x314F19BD, 0xD2B061C1, 0x14FB4A8B} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 229 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 230 a1");
	}
	{
		static const fp2_t var_a =  { {0x050C3F01, 0x42949809, 0x0AF37D52, 0xE663D5D6, 0xB5FB8A7D, 0xE8BE3405, 0xDC1F6A48, 0x822FCCD4},
	{0x155D6E7D, 0xE669615E, 0x054EA10C, 0xF549F22D, 0x93E8A1D4, 0x7EECF309, 0xFE0F3B4B, 0x0B8D0BE9} } ;
		static const fp2_t var_expected =  { {0x1DB0B899, 0xE2D42098, 0xE0FBBE83, 0x901876C1, 0xC5DCC4B2, 0xFF820376, 0x11609C63, 0x651138A7},
	{0xE1A83512, 0x539288B3, 0x5F4B5F15, 0xE5723D1A, 0x09696352, 0xE73B51AA, 0x2605B856, 0x0D87C20D} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 231 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 232 a1");
	}
	{
		static const fp2_t var_a =  { {0xA15D5F25, 0xFC585712, 0xB23A4946, 0x6B5421EE, 0x0F863EF6, 0x6BC9DB99, 0xE873FD55, 0x1E978554},
	{0xC1DE4691, 0x38C17973, 0xFE307AB8, 0x76052C86, 0x20FAE67C, 0x440E4E77, 0xBC9F8B1E, 0x6AFD6E4A} } ;
		static const fp2_t var_expected =  { {0x116FE216, 0x6321B7E4, 0xA4CB1059, 0xB64DA0FF, 0xD82AAE9E, 0xEDA724D3, 0x9A4578BC, 0xB6399DCB},
	{0x2CCDBB6D, 0xEB052D5D, 0xDF7511F6, 0x29B5E7CC, 0xCCBA1808, 0x31197DD4, 0x746C0EA8, 0x817A7D17} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 233 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 234 a1");
	}
	{
		static const fp2_t var_a =  { {0x35F0D207, 0x8C61D774, 0x2E6431B4, 0xF0130C24, 0x61641A4B, 0xBB19FE91, 0x4161533D, 0x62D656CA},
	{0x8BB69325, 0x45CD2114, 0x477BAA66, 0x5C1D3D0A, 0xDCA13D9E, 0xF7A27EB2, 0x8613AB91, 0xB5FC7014} } ;
		static const fp2_t var_expected =  { {0x4A6ACFC3, 0xB11E484C, 0x447840C9, 0x20C005A5, 0xBD07D248, 0x0A75D915, 0x91A46702, 0x3EB764DA},
	{0x48887184, 0x502F118D, 0x383C9F94, 0x51F929F4, 0x1ACE57DD, 0xBFA00724, 0x04BB4768, 0xA699C1AA} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 235 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 236 a1");
	}
	{
		static const fp2_t var_a =  { {0xEE6B841C, 0xB54512EA, 0x39361693, 0x33300674, 0xBFA1995D, 0x207D57DB, 0xC2698E2C, 0xA0A00CF2},
	{0x90A92487, 0x5FC56961, 0x7D4A3214, 0x974C82BA, 0x76B0A36B, 0x1E78F44A, 0xA1DE5D73, 0x42808D13} } ;
		static const fp2_t var_expected =  { {0x458C2960, 0xBA59E798, 0x418772EB, 0x53F3D0B8, 0x58E8BBAB, 0xA89A4554, 0x76D71B3E, 0x80EC49B5},
	{0x4C9DB4BE, 0xC6620DC6, 0xAEAC1F8D, 0x1C892CC9, 0x1D72E2B5, 0x8E4706C3, 0x9CA89DA6, 0x5C7719D3} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 237 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 238 a1");
	}
	{
		static const fp2_t var_a =  { {0x84FE103E, 0x38C29277, 0x8D386A21, 0xCC541334, 0x359D160F, 0xDA4B46AE, 0xE02681EF, 0x82E98560},
	{0xF6E78201, 0xD92AD74A, 0xCF60BD54, 0x3739DEDA, 0x09E36AFF, 0x7099C1F5, 0x77E2C3EE, 0x7324195C} } ;
		static const fp2_t var_expected =  { {0x2743F962, 0xC4160165, 0xA5485587, 0xD9B7AFBC, 0x83C86BAE, 0x9A13EA31, 0x20D36F4E, 0x227C4631},
	{0x659C006B, 0x9633FBEC, 0xB1A66A63, 0xAA50A05B, 0x9DE9CF4C, 0x1B430674, 0x3FC6E9D4, 0x1288F989} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 239 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 240 a1");
	}
	{
		static const fp2_t var_a =  { {0x9872BB13, 0x29569635, 0xE77BF026, 0x8D4F4771, 0xB231FC4F, 0x4FC10FC3, 0x1D4F2D93, 0x4C0A039F},
	{0x5A310C1F, 0xD83E8212, 0x246AE511, 0x59B0883D, 0xC030B954, 0x9862AF63, 0x88445219, 0xB1D01187} } ;
		static const fp2_t var_expected =  { {0x8E75DBB1, 0x9254DF44, 0xE4CF8B04, 0xFF26FBA4, 0x4F86FF50, 0xA713EA08, 0xE35D1683, 0x6C2DC5F1},
	{0x120C9E3D, 0x15B11E2B, 0xA5F93E08, 0xCFF0C1CA, 0x9E0958CA, 0x3F17A483, 0x06B47A8A, 0x88AD1387} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 241 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 242 a1");
	}
	{
		static const fp2_t var_a =  { {0x4A86A96A, 0xA2491315, 0xDC2256E7, 0x18FD61C7, 0x252EA4DF, 0x2B1B2A4D, 0xFEA498AE, 0x3306EA57},
	{0x5BFD8097, 0x8491A072, 0xBAA40CCA, 0x13B35650, 0x1376EE83, 0xA2C58CBF, 0xE17995DD, 0x822EA41D} } ;
		static const fp2_t var_expected =  { {0xB269F247, 0xAC1157F3, 0x5AD96663, 0x2E6B1C8B, 0xFCB15F49, 0x5DC1E54F, 0x50134A5E, 0x14C4C21A},
	{0x7E02E568, 0x44364EAD, 0xFFA5B6B4, 0xFE3449E6, 0x7B0CD9DD, 0x7CC7A4A6, 0xAA94A40E, 0x10CACFE9} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 243 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 244 a1");
	}
	{
		static const fp2_t var_a =  { {0x5064B5A6, 0x16199B00, 0xE7E51BC1, 0x7D0D99FF, 0x88405C40, 0x3A9A7095, 0x20EBDB83, 0xA993BA7B},
	{0x394B0EEC, 0x6745DB68, 0xCFF591EE, 0x28BA99BA, 0x8D0E66B4, 0x9AF0C91E, 0xCC144D53, 0x2D251608} } ;
		static const fp2_t var_expected =  { {0x24EEA6AF, 0xC8BDAD1D, 0x5F7C8D78, 0x9ED1CF29, 0xA9ECC08F, 0xAF0B0BA1, 0x021BC217, 0x628830BF},
	{0xB11462F8, 0x041DA2A1, 0x20ED5255, 0x494A8987, 0x63053783, 0x644DA6B7, 0x4542AAF0, 0x96C59D2A} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 245 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 246 a1");
	}
	{
		static const fp2_t var_a =  { {0x9C73EACF, 0x713CFFF3, 0xA8F6E494, 0xC3093EA1, 0xF100550E, 0xC076988B, 0x16AE3AB6, 0x636A5CEC},
	{0xEBBA4E59, 0xA3AD75C5, 0xB2328F68, 0x470DB284, 0xF97C9149, 0x32AED04E, 0x84FDD99E, 0x11382285} } ;
		static const fp2_t var_expected =  { {0x677BEAEF, 0xB79059C4, 0x04717C5A, 0x2DAA39F6, 0x19C315BE, 0xB682140B, 0xEF4289E5, 0x1A6109C6},
	{0x3C65BF0D, 0xB13A086A, 0x1F6443A5, 0x0482ED11, 0x32F5283D, 0xFFCA7552, 0xBDE33777, 0x01441F7E} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 247 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 248 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 249 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 250 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 251 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 252 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 253 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 254 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 255 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 256 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 257 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 258 a1");
	}
	{
		static const fp2_t var_a =  { {0x847CA71B, 0x38F5B4A1, 0x5E5AF469, 0x5FEF0008, 0x0FB3F7F4, 0x11DE4256, 0x92D05574, 0x80038DBD},
	{0xA6F2EDDB, 0xEBD93935, 0x4FDEE2D7, 0x2A0DF869, 0xFA143B20, 0x9F93A32C, 0x87F65B2B, 0xA49F4A2D} } ;
		static const fp2_t var_expected =  { {0x73546DDB, 0x1BF21F29, 0x996969D8, 0xB9805654, 0xB1CB40D4, 0x869F4F60, 0xE97798CE, 0x9D0B963F},
	{0x848F913B, 0x7563E173, 0x122B610F, 0x9E8FD285, 0x26FB626A, 0x4D79FFCC, 0xE40A9BAA, 0xAF597477} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 259 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 260 a1");
	}
	{
		static const fp2_t var_a =  { {0x1F09A8AF, 0xED872295, 0xAA2F01F3, 0x7CE0F333, 0x18F4E528, 0x42134DA7, 0xA801EBE3, 0x316724A8},
	{0xA323E2BD, 0xAF83989E, 0x06A4ACA8, 0xD6FB4FEB, 0x51BA2574, 0x751B1949, 0x7BDFF84A, 0x45763825} } ;
		static const fp2_t var_expected =  { {0x409AEEA5, 0x763AD623, 0x3F53709D, 0xC7F94FEA, 0x366BB76E, 0x1EB9D509, 0x74106406, 0x75BD61B5},
	{0x02A80BAC, 0xD7391128, 0xED8E45F7, 0xF5067E45, 0x52CE5794, 0xB83DBADA, 0xDDFF6A39, 0x7FC4EB73} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 261 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 262 a1");
	}
	{
		static const fp2_t var_a =  { {0xDD2775AB, 0x5A6F3551, 0x2CAEDED5, 0xCBD6F36E, 0xA7DFF4F3, 0x47971DC4, 0x8AE8376B, 0x3D711ED4},
	{0xABE2FDD3, 0x46BF0031, 0x1316137F, 0x973BD616, 0x9D043B8F, 0x96D81E0C, 0xA8297381, 0x172322C9} } ;
		static const fp2_t var_expected =  { {0x9FA9D523, 0x2CAEDF81, 0x80935F0E, 0x6F745007, 0xFDE13F54, 0x217BBD17, 0x658389CA, 0x7BC25ECB},
	{0x87079937, 0x22D6C4F1, 0x73C6F963, 0x5526C15B, 0xF87362A2, 0x491C3D3B, 0xF42427D5, 0x689B60C5} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 263 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 264 a1");
	}
	{
		static const fp2_t var_a =  { {0xE0D8D258, 0x845AA9B5, 0xDF448AA3, 0x88E6A446, 0xCFF893E6, 0xD662B9AE, 0xA51329C3, 0x111C027A},
	{0xFD153C51, 0x55371159, 0x8FC630F4, 0x494BB109, 0x0D6854F5, 0x5945FA2B, 0x9967AF18, 0x25A1B81C} } ;
		static const fp2_t var_expected =  { {0xF06C692C, 0xC22D54DA, 0x6FA24551, 0x44735223, 0x67FC49F3, 0xEB315CD7, 0x528994E1, 0x088E013D},
	{0xAFA0B876, 0xAA12CD85, 0x321F081D, 0x2E2EAED5, 0x30A56F55, 0xAA532B4B, 0x6CC345A0, 0x6FDAAB6F} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 265 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 266 a1");
	}
	{
		static const fp2_t var_a =  { {0x63A6E0F4, 0xB2F9295C, 0x7BE72E6A, 0xF777B21C, 0xE5006C29, 0xF0E54243, 0xDF207533, 0x2C9B9113},
	{0xBA8A5D37, 0xC39AA269, 0xFF875D69, 0xF80A1D32, 0xBFE53B23, 0x54BB6C5D, 0xD6C21339, 0x02B52650} } ;
		static const fp2_t var_expected =  { {0x31D3707A, 0x597C94AE, 0x3DF39735, 0xFBBBD90E, 0xF2803614, 0xF872A121, 0xEF903A99, 0x164DC889},
	{0x8E5B48E9, 0x6144960D, 0xE9FF9E58, 0x858DE4E9, 0x89E3E26C, 0x280DE464, 0x8B7077B1, 0x5E646289} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 267 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 268 a1");
	}
	{
		static const fp2_t var_a =  { {0x8D6B0455, 0x659ABFE9, 0xCE517251, 0x22C70646, 0xC7DE4C96, 0xBB17AAAB, 0x21811A36, 0x63F5C38B},
	{0xC7DD9616, 0xB0975CC5, 0x79542AE8, 0x38DC05FC, 0x5F8290E5, 0x53A3CA7E, 0x271EAA3A, 0x6A1F1E0B} } ;
		static const fp2_t var_expected =  { {0x77CB9C78, 0x3244A4CD, 0xD164A8CC, 0x9AEC5973, 0x8DE06B25, 0xDB3C038B, 0xB0CFFB2F, 0x8F04B126},
	{0xE3EECB0B, 0x584BAE62, 0x3CAA1574, 0x9C6E02FE, 0x2FC14872, 0x29D1E53F, 0x938F551D, 0x350F8F05} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 269 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 270 a1");
	}
	{
		static const fp2_t var_a =  { {0x1BF2BC71, 0x66734101, 0x12092838, 0xCCC0A560, 0x4D54CC73, 0xB6866D61, 0xD45C532A, 0xB5B67771},
	{0x9EAE5E96, 0x86E71F6E, 0x84B72A79, 0x5BC03630, 0x8FA63F86, 0x79A5902E, 0xD7630439, 0x429407DE} } ;
		static const fp2_t var_expected =  { {0x3F0F7886, 0xB2B0E559, 0x734083BF, 0x6FE92900, 0x509BAB14, 0xD8F364E6, 0x0A3D97A9, 0xB7E50B1A},
	{0x4F572F4B, 0xC3738FB7, 0x425B953C, 0x2DE01B18, 0x47D31FC3, 0xBCD2C817, 0x6BB1821C, 0x214A03EF} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 271 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 272 a1");
	}
	{
		static const fp2_t var_a =  { {0x90F3892A, 0xB92E340C, 0x14120676, 0x458F2FFE, 0xDBBE0059, 0x94C80542, 0xA27105F2, 0x49A32EFA},
	{0x083AF21E, 0xE69AE6E6, 0x8C632E4B, 0x8A1E5589, 0xD0670F8D, 0x0C997402, 0x6DCCFFF0, 0x7EB26E1E} } ;
		static const fp2_t var_expected =  { {0x4879C495, 0x5C971A06, 0x0A09033B, 0xA2C797FF, 0x6DDF002C, 0x4A6402A1, 0x513882F9, 0x24D1977D},
	{0x041D790F, 0xF34D7373, 0xC6319725, 0xC50F2AC4, 0x683387C6, 0x064CBA01, 0x36E67FF8, 0x3F59370F} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 273 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 274 a1");
	}
	{
		static const fp2_t var_a =  { {0xEA1A30F0, 0xA3A57416, 0x3AB2D5FA, 0xF803C8E3, 0x6FDDB844, 0x4F89F00B, 0xF3EC990E, 0x130BDCB3},
	{0x60DF11D1, 0xB772EE81, 0x6CBC1D23, 0xA998065E, 0x965A334B, 0xAD34F574, 0xF4B74029, 0x3EACDDD0} } ;
		static const fp2_t var_expected =  { {0x750D1878, 0x51D2BA0B, 0x9D596AFD, 0x7C01E471, 0xB7EEDC22, 0x27C4F805, 0xF9F64C87, 0x0985EE59},
	{0x6185A336, 0x5B30BC19, 0xA099FE35, 0x5E54D97F, 0xF51E5E80, 0x544AA8EF, 0x9A6B0E29, 0x7C603E49} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 275 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 276 a1");
	}
	{
		static const fp2_t var_a =  { {0xF01A5F16, 0xA6C44786, 0x7ACE5BEB, 0xDACDE8EF, 0x9432C8BD, 0x0B20BED0, 0x72B12467, 0x2C16B6FE},
	{0x66E14D85, 0x207CCFA8, 0xBD155987, 0x14853799, 0x93777699, 0x321E08A4, 0x7460B14D, 0x0EDC5555} } ;
		static const fp2_t var_expected =  { {0x780D2F8B, 0xD36223C3, 0xBD672DF5, 0xED66F477, 0x4A19645E, 0x85905F68, 0x39589233, 0x160B5B7F},
	{0xE486C110, 0x0FB5ACAC, 0x48C69C67, 0x13CB721D, 0xF3AD0027, 0x16BF3287, 0xDA3FC6BB, 0x6477FA0B} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 277 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 278 a1");
	}
	{
		static const fp2_t var_a =  { {0x5D0CE95A, 0x8B8FCE15, 0x0ECD8E54, 0xAF9E3730, 0x2133688B, 0x4E150E41, 0x85B8DC08, 0x95C5AA52},
	{0xE24F69A0, 0x83771981, 0xFFCA5128, 0x90AC5602, 0x604D9DC5, 0xA4DA19F6, 0xB5550F3D, 0x3081073B} } ;
		static const fp2_t var_expected =  { {0xAE8674AD, 0x45C7E70A, 0x0766C72A, 0xD7CF1B98, 0x9099B445, 0x270A8720, 0x42DC6E04, 0x4AE2D529},
	{0xF127B4D0, 0x41BB8CC0, 0x7FE52894, 0xC8562B01, 0x3026CEE2, 0xD26D0CFB, 0xDAAA879E, 0x1840839D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 279 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 280 a1");
	}
	{
		static const fp2_t var_a =  { {0xB62F0536, 0x55BD204D, 0xC6D38585, 0xC8A5B51C, 0x7A37EF3E, 0xC73C779E, 0xD7D0B6A9, 0x7392D63B},
	{0x11609077, 0x8566C76F, 0x4EF03C76, 0xF8DAD1D8, 0x2D824E3B, 0x5B9E1776, 0x428968D5, 0xB1403A93} } ;
		static const fp2_t var_expected =  { {0xDB17829B, 0xAADE9026, 0x6369C2C2, 0x6452DA8E, 0x3D1BF79F, 0xE39E3BCF, 0xEBE85B54, 0x39C96B1D},
	{0x39C66289, 0xC22AA890, 0x91B40DDE, 0x85F63F3C, 0xC0B26BF8, 0x2B7F39F0, 0xC154227F, 0xB5A9ECAA} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 281 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 282 a1");
	}
	{
		static const fp2_t var_a =  { {0x592459BC, 0x49625579, 0xD9009438, 0xA10A9F9D, 0xF01A26AE, 0x6B20BADD, 0x11972DA0, 0x75D63C3F},
	{0xB386B3A3, 0x0DE64E1C, 0x59E2174D, 0x44A5AA80, 0xC4E346E2, 0xF59C338B, 0x63E88CAA, 0x69F5D47B} } ;
		static const fp2_t var_expected =  { {0xAC922CDE, 0x24B12ABC, 0xEC804A1C, 0x50854FCE, 0xF80D1357, 0x35905D6E, 0x88CB96D0, 0x3AEB1E1F},
	{0x0AD9741F, 0x066A6BE7, 0x972CFB4A, 0xABDBAB90, 0x8C62E84B, 0xF87E47FB, 0xD203B469, 0x9204B99E} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 283 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 284 a1");
	}
	{
		static const fp2_t var_a =  { {0xE923250F, 0xEE2DB56A, 0xC272E474, 0xF7CD2CE7, 0x142F7773, 0x6FB1D107, 0x1B243033, 0x87B0CEAB},
	{0xE95B5F40, 0x3E1FD530, 0x8D2DBA36, 0xE498AC3B, 0x2AE86238, 0x41399C6C, 0x617E50DC, 0x9FE20052} } ;
		static const fp2_t var_expected =  { {0x25A7ACD5, 0xF68E1F8E, 0x4B7561DD, 0x856F6CC4, 0x34090094, 0x358916B9, 0xADA1862E, 0xA0E236B6},
	{0x74ADAFA0, 0x1F0FEA98, 0xC696DD1B, 0x724C561D, 0x1574311C, 0x209CCE36, 0x30BF286E, 0x4FF10029} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 285 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 286 a1");
	}
	{
		static const fp2_t var_a =  { {0xE3E5EB02, 0x07CCCE4B, 0x63609B4A, 0xB587D142, 0x6368AF39, 0x4D37FF1B, 0xDF7E5DC4, 0x1CC0C78F},
	{0xB5FE133A, 0x7F60FE6E, 0xC33EDFDB, 0x75C2F0F7, 0x4F30F3D8, 0x55D52DA7, 0x848C9496, 0x223558D5} } ;
		static const fp2_t var_expected =  { {0xF1F2F581, 0x03E66725, 0x31B04DA5, 0xDAC3E8A1, 0xB1B4579C, 0x269BFF8D, 0xEFBF2EE2, 0x0E6063C7},
	{0x5AFF099D, 0xBFB07F37, 0xE19F6FED, 0x3AE1787B, 0xA79879EC, 0x2AEA96D3, 0xC2464A4B, 0x111AAC6A} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 287 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 288 a1");
	}
	{
		static const fp2_t var_a =  { {0x3060FCF5, 0x99F12A92, 0x5F8898F2, 0x3D7FA587, 0x96FC0E74, 0xB124582F, 0x45A48FFB, 0x1548BAB2},
	{0xF723D66F, 0x756D59FD, 0x3FF36BF6, 0xC07D6452, 0x11995C6C, 0x8B21C89E, 0x1719458C, 0x43D29E4B} } ;
		static const fp2_t var_expected =  { {0xC94698C8, 0xCC6FDA21, 0x1A003C1C, 0xA848A914, 0x756F4C14, 0x56425A4D, 0x42E1B612, 0x67AE2CBA},
	{0xACA80585, 0xBA2DF1D7, 0x8A35A59E, 0xE9C78879, 0xB2BDF310, 0xC3411284, 0xAB9C10DA, 0x7EF31E86} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 289 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 290 a1");
	}
	{
		static const fp2_t var_a =  { {0x36D7B404, 0xA379BB78, 0xE1E7CAE6, 0xEE9674B0, 0xFF5DC44C, 0x64B1FE98, 0x1551A570, 0x91F6D43E},
	{0xA0752750, 0xC136426D, 0xF9CEB19B, 0x55A536EB, 0x81FB91F2, 0xE29DD69D, 0x141DA90D, 0x5F4AD065} } ;
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 291 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 292 a1");
	}
	{
		static const fp2_t var_a =  { {0x380C3060, 0xE37FB005, 0x66CFDE09, 0x924FCCE7, 0xB83F62C0, 0xB7EA4628, 0x8C1B3A84, 0xA6723BD1},
	{0xB8DF07B6, 0xCD5627CE, 0x39B40CD1, 0x2D73CD5D, 0x965A919A, 0x2A26DD53, 0xAADEAF20, 0x8BB0D36D} } ;
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x380C3060, 0xE37FB005, 0x66CFDE09, 0x924FCCE7, 0xB83F62C0, 0xB7EA4628, 0x8C1B3A84, 0xA6723BD1},
	{0xB8DF07B6, 0xCD5627CE, 0x39B40CD1, 0x2D73CD5D, 0x965A919A, 0x2A26DD53, 0xAADEAF20, 0x8BB0D36D} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 293 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 294 a1");
	}
	{
		static const fp2_t var_a =  { {0x68F4EAC1, 0x2D25E10E, 0x756B13F4, 0x4E82D5BB, 0xEE78350F, 0x577699AD, 0x73A210A2, 0xA50D9674},
	{0x148A829A, 0x9E849293, 0xCF0E0D85, 0xCF3813D2, 0x5B9B4825, 0x7D31BE84, 0x7639FFB6, 0x01989C7D} } ;
		static const bigint_t var_b = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x22F608CC, 0x63F3D172, 0xBC3C8F1C, 0xAA2A34D3, 0x5DB213B0, 0x3481B341, 0xF25DD508, 0x47322390},
	{0x4472B4F0, 0xE3D5C0CB, 0x58B7CEB5, 0x46C8636C, 0xC65E2E6C, 0x44E64250, 0xB68423B3, 0x82D16D91} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 295 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 296 a1");
	}
	{
		static const fp2_t var_a =  { {0x1DCCD208, 0x04CEB0F6, 0x19CF4A64, 0xE90C2397, 0x2A9544EF, 0x4864334F, 0x670E19E4, 0x81A12735},
	{0x81928D56, 0x798E3A67, 0xFFAD965C, 0xE8949EC9, 0x120F983E, 0xFFD28798, 0x5AE7D128, 0x2D73D290} } ;
		static const bigint_t var_b = {0x06A48E88, 0xBF4CD5CF, 0x942B692F, 0x8D4FE570, 0x30B382E6, 0xF6D611AF, 0x24B74BD9, 0x0A6543BA};
		static const fp2_t var_expected =  { {0x1B4D8711, 0x4AD990A6, 0xD4F7CCB7, 0x097DCC9F, 0x71A0682F, 0x731E9C81, 0xF34C782C, 0x081430D1},
	{0x3D1D4221, 0x3D5F5DD8, 0x1D15E979, 0x4194451C, 0x3BF07D8B, 0xCB4479EE, 0xC78BDD5A, 0x88066B2C} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 297 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 298 a1");
	}
	{
		static const fp2_t var_a =  { {0xF25A0E15, 0xC170E739, 0x6648D6E0, 0xB328523F, 0x90C99925, 0xB7D1D5DF, 0x139A15EB, 0xB5D6B78B},
	{0xEAC1CE31, 0xF6C0646B, 0x27B5A9F1, 0x86554FA0, 0xAB7BD39C, 0xDAD69EA8, 0x340AB6FC, 0x83CCB8CD} } ;
		static const bigint_t var_b = {0x8433AA26, 0x8AEE519E, 0x315B2CB4, 0xC575E060, 0xDDF14DF6, 0x1CC5133C, 0x1B7CA017, 0xBA5CCA8F};
		static const fp2_t var_expected =  { {0x36B2BECF, 0x3C6C0F07, 0xDF415654, 0x0BC5D34A, 0x2E982318, 0x5D571A67, 0xB60F11C9, 0x6E462889},
	{0x59BAE1C0, 0x32CAA0E7, 0x9DB5BE7D, 0xF2097B52, 0x32BE1F57, 0x75DC4C90, 0x26355901, 0x7214FF5E} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 299 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 300 a1");
	}
	{
		static const fp2_t var_a =  { {0x1230A0DF, 0xF60D0503, 0x1922DBA8, 0x29520BC1, 0x783F7C37, 0x9C5255AA, 0x5143A85A, 0x59D2A1F7},
	{0xA641DE67, 0x5E52DC9D, 0x7CCD6048, 0xD1CBAF6A, 0x82BF047D, 0xF026FF69, 0x2A226160, 0x58AEF349} } ;
		static const bigint_t var_b = {0x6CEF94EF, 0x1484338E, 0x45B2AE50, 0x6FC4BC04, 0x42EB92FB, 0x91E47114, 0x48EC513A, 0x19908765};
		static const fp2_t var_expected =  { {0x1C59A989, 0x9C6F83D1, 0x2EF1CE68, 0x9402325A, 0x7DC373CF, 0x54CB8DF1, 0x04029303, 0x35BEBC98},
	{0xA2E5FCF2, 0x93E0D814, 0x1D537535, 0x62F87BE6, 0xB201861D, 0xB1745549, 0x382C4B28, 0x57F22B54} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 301 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 302 a1");
	}
	{
		static const fp2_t var_a =  { {0x870A50D3, 0x26C29AC8, 0x812E5BC4, 0xE71ED227, 0x6185278D, 0x975FE097, 0xA0E22456, 0x16900772},
	{0xC9A8651F, 0x777DB965, 0xC1D02CB0, 0x5398F7B7, 0xD8C250F4, 0x3648BC9E, 0x11145615, 0x24F96004} } ;
		static const bigint_t var_b = {0x80234699, 0xC86A2194, 0x999A4608, 0x851D06EB, 0xCBCB75E1, 0xD0D30211, 0x917375CC, 0x61A3286E};
		static const fp2_t var_expected =  { {0x1ADD3642, 0xEB40D3D8, 0x260A94C3, 0x5BBFFDED, 0x0FF4A176, 0xE06DC470, 0x0A8100D6, 0x2C433979},
	{0xA6D25119, 0x39DDA9AD, 0xA2BF2D20, 0x089D48D6, 0xFE2468E2, 0x662424F4, 0xCC39505C, 0x0CE83CA9} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 303 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 304 a1");
	}
	{
		static const fp2_t var_a =  { {0x9E8A271E, 0xFCAE25EB, 0x40C57F41, 0x47EE1A7F, 0x7E63F5EC, 0xB7AC6A23, 0x2BC4B1E9, 0x268CEE80},
	{0x707FF7FE, 0x221CEDD1, 0x19EB008B, 0xAE1889FB, 0x8B5EA389, 0x81A3DC0E, 0xFDF2A321, 0x465EB36A} } ;
		static const bigint_t var_b = {0x65CCFAFB, 0x04B62EA7, 0x3C63C6D5, 0xD1E21971, 0x87EA5A71, 0x0C302499, 0xDC56068E, 0x6025514C};
		static const fp2_t var_expected =  { {0xE64A9686, 0x50B7344D, 0xFA35C67D, 0xDAFBA8F5, 0xB3376129, 0xDC5E4D3F, 0x24A658A8, 0x6B2466D7},
	{0x46CEC502, 0x0B112C40, 0xDD2FC9E3, 0xFC69F544, 0xA2119EFF, 0xAFF90031, 0x2742F1C9, 0x727B26A7} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 305 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 306 a1");
	}
	{
		static const fp2_t var_a =  { {0x3AECA19B, 0xAB75809F, 0xD25CDFBC, 0x9794A973, 0x94015622, 0x887F2E00, 0x1BD09775, 0x8702782C},
	{0xC5C9E845, 0x00C59123, 0xDACB9EF7, 0xD1A58A93, 0x3FD097EC, 0x4AD03D3E, 0x79868143, 0x3D61329B} } ;
		static const bigint_t var_b = {0x24713AE0, 0x9B7E685D, 0x001E088A, 0x74D94516, 0xA90A794F, 0xA8ECCA93, 0x98B956A8, 0xF83A1A03};
		static const fp2_t var_expected =  { {0xED0E7A62, 0x2D72F283, 0x1865A03A, 0xAB2CB542, 0x9C41DCB8, 0xA0E85ACF, 0xC89C9AA0, 0x2C5D7D49},
	{0x6F4577F7, 0x6DAE9591, 0xADADE92A, 0xF08AE58F, 0x4E9D8AD2, 0x75C98629, 0xA66C2D87, 0xA5CD829B} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 307 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 308 a1");
	}
	{
		static const fp2_t var_a =  { {0xC1A28464, 0x6755DFEB, 0x2FFF0E85, 0x5EE10D75, 0x1BCD132E, 0x7D963EB4, 0xF7F966CA, 0x239D57B4},
	{0x08C6A7D0, 0xBFB9C702, 0x0F1F4C8E, 0xADCF1DC3, 0x439E3DA3, 0x2562D1F7, 0xC2EC024E, 0x6042504E} } ;
		static const bigint_t var_b = {0xAB0CC388, 0x5582BD80, 0xFC0CA6B6, 0x61DD2B1B, 0x09AD011A, 0xBFFAF7D0, 0x33330444, 0x9E1A2A53};
		static const fp2_t var_expected =  { {0xE538BF02, 0xF75ED1B7, 0xFBA05674, 0xAE9FFA7C, 0x145AE30B, 0x3EEF49D9, 0x2D778DCE, 0x261F198D},
	{0xE2FA725B, 0x82429B79, 0x0528C3EE, 0x6699FD41, 0xA9F868E7, 0xD480CCEB, 0x210852CB, 0x649E6DA2} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 309 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 310 a1");
	}
	{
		static const fp2_t var_a =  { {0x98A5760C, 0x5034390F, 0x595F1EF2, 0x3DD90B51, 0x7155EF43, 0x68D7F184, 0x8A671F8E, 0x7D71C2EC},
	{0xA8C86A92, 0x846E1182, 0x9C22FB2F, 0x5CC7A6AE, 0xF2743408, 0xFA2FA74C, 0x2B6773C3, 0x52C8DC58} } ;
		static const bigint_t var_b = {0x4B0792E8, 0x6B138D63, 0x0AA0A510, 0xE06488A4, 0xA171B5A3, 0x9C40FFF9, 0xA2F4D55B, 0xDD57A1A5};
		static const fp2_t var_expected =  { {0x2A510400, 0x09EE7A66, 0x40EC74ED, 0xDA00CC05, 0x5232DA27, 0x224A18DD, 0xD101F6FF, 0x1123EF0F},
	{0x2AE782C2, 0xEE5BE90E, 0xEB46D934, 0xB7E1BEF0, 0x18CCDBCE, 0x9F763F09, 0x90981834, 0x1C3F434E} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 311 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 312 a1");
	}
	{
		static const fp2_t var_a =  { {0x364726F0, 0xC3F344CC, 0x68DFFDD9, 0x4264D0E7, 0x90A8C96F, 0xAF257DCB, 0xFDDDDCCD, 0x17172159},
	{0xB870B4BF, 0xC27AE11A, 0x9CFB6E76, 0x588820CE, 0x1FFECA54, 0x6DE6A364, 0xE0F9BB83, 0x22548B1B} } ;
		static const bigint_t var_b = {0x3940802F, 0x0D586BF7, 0x48021BD7, 0x0ED4B911, 0x1289FAD8, 0x41E14E1E, 0xDF7D2A44, 0xD1FE5B0B};
		static const fp2_t var_expected =  { {0xE5DFA578, 0x71688BB3, 0xF3677C73, 0xBECF3157, 0x0302CFAB, 0xF70477C2, 0x9BD14213, 0x9D9BE7BC},
	{0x658A6B47, 0xC30AEB5D, 0x22F8A3E9, 0x152293D4, 0x9225D356, 0xC224DD3D, 0x7F6E961A, 0x474FB580} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 313 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 314 a1");
	}
	{
		static const fp2_t var_a =  { {0x860FEB19, 0x195899EA, 0xED5D814F, 0x1B8AD664, 0xD5B6AD37, 0x7D3C9D58, 0x64D8ADE2, 0x4E4834B0},
	{0x3C006267, 0xD809AA04, 0xB6C12A22, 0xCA0BC775, 0xDB238A2B, 0x01B40594, 0x48AF297A, 0xB00F9DD4} } ;
		static const bigint_t var_b = {0x1027272A, 0xDED9E85B, 0x98370B42, 0x59A0A668, 0x1F36CB0C, 0xE2D3A4F1, 0x65E3DAD2, 0xAF7F4474};
		static const fp2_t var_expected =  { {0x38A4A9FD, 0xAECA562A, 0x8528750B, 0x43BFC4C4, 0xBD3EF8BA, 0x115F2323, 0x34C1AF72, 0x5E6BB833},
	{0xEEB5684D, 0x8569E2F8, 0x741EAA0B, 0x3097C581, 0xAF442139, 0x807BA8BF, 0x171B6393, 0x830BA8CA} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 315 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 316 a1");
	}
	{
		static const fp2_t var_a =  { {0x58FB1254, 0xD7ACD6DE, 0x1901CE66, 0xFFFD72D6, 0x71C98A5F, 0x125D6048, 0xB8A2CB2E, 0x79936A71},
	{0x2F9271E7, 0xFA1D9269, 0x9A8994A6, 0xC3C4B6E3, 0xE2091579, 0x18148273, 0x47D1CFE6, 0x39517483} } ;
		static const bigint_t var_b = {0x4BE504DC, 0x75656BC6, 0x22CA12CE, 0x0644E0A1, 0x305F1231, 0x68CBE0C7, 0xB4A3B95F, 0x3A6AB617};
		static const fp2_t var_expected =  { {0x8A419478, 0x36587A70, 0xD3103F94, 0xFB800713, 0x06ECF141, 0x6488D562, 0x2E3A5FFE, 0x3D9586E5},
	{0x2F84B864, 0x846190BB, 0x62324076, 0xEEB89906, 0x6D1C0870, 0xC4FE30B3, 0x0A058B76, 0x501D0AC1} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 317 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 318 a1");
	}
	{
		static const fp2_t var_a =  { {0x5B54FF6E, 0xFED1005C, 0x7FC80CE5, 0xCB1E382A, 0x883D5403, 0x8322B3A9, 0x508FF6A0, 0x70863369},
	{0x84501B69, 0x6B6B62BD, 0x7A9F6D8F, 0xB2884FCD, 0x1D41ADFE, 0x6348E251, 0x12B2C6EB, 0xAECC56FB} } ;
		static const bigint_t var_b = {0xCD9715BD, 0xDC396647, 0xD0079761, 0xAD012141, 0xCE2F4CDC, 0xF16DE049, 0xD10C13FA, 0x4DF92E14};
		static const fp2_t var_expected =  { {0xFEC3FC08, 0xAA239B93, 0x669FC1EB, 0x3F93D14E, 0x9FE8E029, 0x3ADBE72B, 0x485DB603, 0x461C8C58},
	{0x7F93F0F9, 0x62C3075D, 0x4A3A16F7, 0x492E53DA, 0xA6421CBE, 0xD17AB343, 0xF9770F73, 0x48731997} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 319 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 320 a1");
	}
	{
		static const fp2_t var_a =  { {0x79E8660D, 0xAEF436F2, 0x5DF7F937, 0x02A3BB6A, 0x2D92A115, 0xDDEB3C4F, 0xB67C3919, 0x544C1C88},
	{0xBD503041, 0x0F893508, 0xFEBE3104, 0x84FF15C3, 0x9BFB57B2, 0x80E01FB4, 0x5CF99239, 0x0C6929F3} } ;
		static const bigint_t var_b = {0x5C98571E, 0x13887F0C, 0xCFCF87C8, 0xBA7782FF, 0x2BCA80F4, 0x4CDC13C6, 0xC431D52B, 0x566EC991};
		static const fp2_t var_expected =  { {0x48A8EEA1, 0xB7CC3FA3, 0xF19CFB55, 0x0405D7A7, 0x595F94C5, 0x127E5464, 0xDA97B292, 0x04CAB24B},
	{0xA5318B75, 0x2E528FA9, 0x0668E82D, 0x3FC98136, 0x0CFCC6B4, 0xF7015E2C, 0xEC1A4256, 0x9436BE9E} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 321 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 322 a1");
	}
	{
		static const fp2_t var_a =  { {0xDC2A681D, 0x56C3BC3B, 0x5E052494, 0x38C80A7A, 0x32E5C149, 0x3F0AA126, 0x5D729089, 0x14CE754F},
	{0x1BAEEAE4, 0x70E688C0, 0xD7447259, 0x7ADDF28D, 0x0F18BC4F, 0x560A45CC, 0x1EA16781, 0xAF3B4EF4} } ;
		static const bigint_t var_b = {0x1FD7F06A, 0x8C427152, 0x12F0F7DB, 0xEC030B5E, 0x9908EF65, 0x8089B8DE, 0x1A704577, 0xD63C4530};
		static const fp2_t var_expected =  { {0x1E674579, 0x077A1DC8, 0x52346E09, 0xDA349A71, 0x8DA99AEB, 0xD24599D4, 0xCA8FD914, 0xB39ACD61},
	{0xF3CE9AEB, 0xAC007152, 0x631389AB, 0x1E93A16C, 0x2E5456DD, 0x402825C0, 0x8580BA81, 0x945A1009} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 323 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 324 a1");
	}
	{
		static const fp2_t var_a =  { {0x52130D70, 0x3BCD8ECD, 0x2A5D771D, 0x14479802, 0x63FC2612, 0x280FDE1A, 0x0845CBD1, 0xA7D24040},
	{0xDC60C003, 0xF9D262AF, 0xE33D7B62, 0x78569AFF, 0xF3FFAFEF, 0x64EDAE3B, 0xE6396867, 0x9425A3A0} } ;
		static const bigint_t var_b = {0x2644EB45, 0xAE3CB344, 0xD01212DB, 0xD7F66FC0, 0x104FFD71, 0x4562E82E, 0x63856968, 0xE405943E};
		static const fp2_t var_expected =  { {0x6B05301B, 0x90D349A8, 0x3089FE49, 0x3090F361, 0x7DFC217A, 0x17CAAC01, 0xD15C8F3C, 0x3E941B29},
	{0xD5F3C309, 0x89177738, 0x9C8BBE1B, 0x06785FC5, 0x13D1A22F, 0x041AB47C, 0xD5815912, 0xB7BA832C} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 325 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 326 a1");
	}
	{
		static const fp2_t var_a =  { {0x2EBA5FDB, 0x27D5D270, 0x7541428A, 0xB113F4B2, 0x0C930E31, 0x86CAE69F, 0xE98674A2, 0x32FE6E08},
	{0x33EF1BF1, 0xC5FA0423, 0x066015A4, 0xFD72EE7D, 0x1408E2C8, 0x6BA1B307, 0xEBB3838D, 0xB449F04C} } ;
		static const bigint_t var_b = {0xE048BEE6, 0x549A3C8C, 0x033C3003, 0x64972A31, 0xAB6C46E1, 0x8744EB4E, 0xB4348A97, 0xAA632D27};
		static const fp2_t var_expected =  { {0x0A5E90C2, 0xF668CFB5, 0x70B62895, 0x8A5944B6, 0xF88A0641, 0x2CA97744, 0x0C02752A, 0x08E7C804},
	{0x82DA77F9, 0x428FF50C, 0xD6CE766D, 0x91C7FE85, 0x21312984, 0x349BBFC1, 0x4523A9CF, 0x1ECBB619} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 327 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 328 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 329 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 330 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 331 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 332 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 333 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 334 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 335 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 336 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 337 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 338 a1");
	}
	{
		static const fp2_t var_a =  { {0x84631496, 0xBABE5BB3, 0xCE300E0D, 0x9AAF50EA, 0xFED69245, 0x8DDC17D1, 0x6A046F94, 0xB02FFD35},
	{0xB80AC43A, 0xA68D6B69, 0x22437F8F, 0xB11D518D, 0x74AD9E14, 0xAE18148C, 0xB17E4BCF, 0x197354F4} } ;
		static const fp2_t var_expected =  { {0xDDC92005, 0x44302DFD, 0x0647D139, 0x78625BB6, 0x550BF76F, 0x6D844499, 0xD61A6C94, 0x09E3A18C},
	{0xAA217061, 0x58611E47, 0xB2345FB7, 0x61F45B13, 0xDF34EBA0, 0x4D4847DE, 0x8EA09059, 0xA0A049CD} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 339 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 340 a1");
	}
	{
		static const fp2_t var_a =  { {0x4224E6F6, 0x4EA16098, 0x155E3C0E, 0x3BE49089, 0xD5AB4F04, 0xED661BFB, 0xE45D992D, 0x2B7107DE},
	{0x4859A098, 0x1C8C9C3E, 0x990F0F54, 0xBA4BB217, 0x24B77DDB, 0x492E773F, 0x222E23C1, 0x8D50AE91} } ;
		static const fp2_t var_expected =  { {0x20074DA5, 0xB04D2919, 0xBF19A338, 0xD72D1C17, 0x7E373AB0, 0x0DFA406F, 0x5BC142FB, 0x8EA296E3},
	{0x19D29403, 0xE261ED73, 0x3B68CFF2, 0x58C5FA89, 0x2F2B0BD9, 0xB231E52C, 0x1DF0B867, 0x2CC2F031} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 341 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 342 a1");
	}
	{
		static const fp2_t var_a =  { {0x6F76810C, 0x31BCCE73, 0x259C3726, 0x0CB5E060, 0xCDA7D25A, 0x481992FA, 0x8EFCB52D, 0x0F0DA606},
	{0x2B67B396, 0xDC6E5AAC, 0x8653BCAD, 0xA5914BA7, 0x6E3AFC08, 0x3C50D842, 0x505A66F6, 0x67984B97} } ;
		static const fp2_t var_expected =  { {0xF2B5B38F, 0xCD31BB3D, 0xAEDBA820, 0x065BCC40, 0x863AB75B, 0xB346C970, 0xB12226FB, 0xAB05F8BB},
	{0x36C48105, 0x22802F05, 0x4E242299, 0x6D8060F9, 0xE5A78DAC, 0xBF0F8428, 0xEFC47532, 0x527B532A} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 343 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 344 a1");
	}
	{
		static const fp2_t var_a =  { {0xEA829F34, 0x271590CC, 0xB9A1BB55, 0x0AF4C08A, 0xB96D26BD, 0x1284155C, 0x9390D796, 0x8A62C0FA},
	{0xC4C63878, 0x4BDA8A45, 0x94FC35BF, 0x203562C6, 0x9883164E, 0x9628010E, 0xC5EB35D1, 0x2B33C20A} } ;
		static const fp2_t var_expected =  { {0x77A99567, 0xD7D8F8E4, 0x1AD623F1, 0x081CEC16, 0x9A7562F8, 0xE8DC470E, 0xAC8E0492, 0x2FB0DDC7},
	{0x9D65FC23, 0xB313FF6B, 0x3F7BA987, 0xF2DC49DA, 0xBB5F7366, 0x65385B5C, 0x7A33A657, 0x8EDFDCB7} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 345 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 346 a1");
	}
	{
		static const fp2_t var_a =  { {0x12D8EBFB, 0x370B453C, 0x1E54BAE8, 0x4CC8D48A, 0x016E19D6, 0x0D7F0D82, 0xD923B8A0, 0x9608B93D},
	{0xF2751E67, 0x0FFA1D8C, 0x09EF8702, 0xF6BA7C0C, 0x7E3696E2, 0xB3506CA9, 0xC871D3D1, 0x2FAEAC64} } ;
		static const fp2_t var_expected =  { {0x4F5348A0, 0xC7E34475, 0xB623245E, 0xC648D816, 0x52746FDE, 0xEDE14EE9, 0x66FB2388, 0x240AE584},
	{0x6FB71634, 0xEEF46C24, 0xCA885844, 0x1C573094, 0xD5ABF2D2, 0x480FEFC1, 0x77AD0857, 0x8A64F25D} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 347 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 348 a1");
	}
	{
		static const fp2_t var_a =  { {0xAA522793, 0xA656FB3C, 0x63B3B78F, 0x63D85375, 0x4A6706CC, 0x2659D3BF, 0x4B4B9BDB, 0x980A237E},
	{0xF9C682FF, 0x0B771FAB, 0xE7F2FE64, 0x6A0C1AE8, 0x3AD006BD, 0x1B8121E0, 0xA349EF77, 0x327313F5} } ;
		static const fp2_t var_expected =  { {0xB7DA0D08, 0x58978E74, 0x70C427B7, 0xAF39592B, 0x097B82E8, 0xD50688AC, 0xF4D3404D, 0x22097B43},
	{0x6865B19C, 0xF3776A05, 0xEC84E0E2, 0xA90591B7, 0x191282F7, 0xDFDF3A8B, 0x9CD4ECB1, 0x87A08ACC} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 349 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 350 a1");
	}
	{
		static const fp2_t var_a =  { {0x527D5F58, 0xF99BFF13, 0x00879D0E, 0x0BD23A1F, 0x25EC615B, 0x94A840DA, 0xD238860A, 0x7F648276},
	{0x3A6B4F37, 0x65334EDC, 0xF46A3F0F, 0xC5DF5BA2, 0x285EE318, 0xAAA0C56C, 0x1F7E04E5, 0x0718149A} } ;
		static const fp2_t var_expected =  { {0x0FAED543, 0x05528A9E, 0xD3F04238, 0x073F7281, 0x2DF6285A, 0x66B81B91, 0x6DE6561E, 0x3AAF1C4B},
	{0x27C0E564, 0x99BB3AD5, 0xE00DA037, 0x4D3250FD, 0x2B83A69C, 0x50BF96FF, 0x20A0D743, 0xB2FB8A28} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 351 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 352 a1");
	}
	{
		static const fp2_t var_a =  { {0xEBCC0D79, 0xF3AA545F, 0xB0662ABA, 0x424CB12F, 0x64559E10, 0xCAFAC46F, 0x966AC2B9, 0x76E7B591},
	{0x16617B99, 0x8140154F, 0xD945B569, 0xB9E260F0, 0x8F08CF6D, 0x71F9D589, 0xC6E4B3B2, 0x369B726F} } ;
		static const fp2_t var_expected =  { {0x76602722, 0x0B443551, 0x2411B48C, 0xD0C4FB71, 0xEF8CEBA4, 0x306597FB, 0xA9B4196F, 0x432BE930},
	{0x4BCAB902, 0x7DAE7462, 0xFB3229DD, 0x592F4BAF, 0xC4D9BA47, 0x896686E1, 0x793A2876, 0x83782C52} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 353 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 354 a1");
	}
	{
		static const fp2_t var_a =  { {0x3584B22E, 0x9DE00A97, 0x95D2E76C, 0x3185EA10, 0xC2EF9F63, 0x83C47626, 0xC11CAD7C, 0x31F5B895},
	{0x0B21ACFA, 0x068995C5, 0x0A320846, 0xFB2A3F27, 0xF6A79DD9, 0xCD9E8FA0, 0x9F20FBB6, 0x58CC07AD} } ;
		static const fp2_t var_expected =  { {0x2CA7826D, 0x610E7F1A, 0x3EA4F7DA, 0xE18BC290, 0x90F2EA51, 0x779BE644, 0x7F022EAC, 0x881DE62C},
	{0x570A87A1, 0xF864F3EC, 0xCA45D700, 0x17E76D79, 0x5D3AEBDB, 0x2DC1CCCA, 0xA0FDE072, 0x61479714} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 355 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 356 a1");
	}
	{
		static const fp2_t var_a =  { {0xB6A18C70, 0x371DC772, 0x681A9B03, 0x8E8CE261, 0x8E77104A, 0xA891FC17, 0xBB70B362, 0x8DB7AD35},
	{0xFCBB6F83, 0xD8B4106F, 0xB4FDF6F6, 0xBC76BC45, 0x222E59CF, 0x4F07E676, 0xB4E2789C, 0x73931918} } ;
		static const fp2_t var_expected =  { {0xAB8AA82B, 0xC7D0C23E, 0x6C5D4443, 0x8484CA3F, 0xC56B796A, 0x52CE6053, 0x84AE28C6, 0x2C5BF18C},
	{0x6570C518, 0x263A7941, 0x1F79E850, 0x569AF05B, 0x31B42FE5, 0xAC5875F5, 0x8B3C638C, 0x468085A9} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 357 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 358 a1");
	}
	{
		static const fp2_t var_a =  { {0xE93327A0, 0x49C82848, 0x233FF1A9, 0xDD5EDA97, 0x5B5142A2, 0x7895CFEC, 0xAECE6CD2, 0x462138A1},
	{0xAA38D6B5, 0x1CC164C2, 0x6E4737BF, 0x59B3983E, 0xC527179B, 0xCBD72526, 0x0F028D7A, 0x157290BD} } ;
		static const fp2_t var_expected =  { {0x78F90CFB, 0xB5266168, 0xB137ED9D, 0x35B2D209, 0xF8914712, 0x82CA8C7E, 0x91506F56, 0x73F26620},
	{0xB7F35DE6, 0xE22D24EE, 0x6630A787, 0xB95E1462, 0x8EBB7219, 0x2F893744, 0x311C4EAE, 0xA4A10E05} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 359 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 360 a1");
	}
	{
		static const fp2_t var_a =  { {0x1225DEE9, 0x976CEA8C, 0x5331D000, 0x2F6A19E4, 0x50717D96, 0x66BA550C, 0x02A4EB29, 0x448DC6F9},
	{0x16D07227, 0x363EAD3E, 0x13867737, 0x6FDF8DA2, 0xD0AF9DD9, 0x57949244, 0xF7294FD0, 0x0A675C49} } ;
		static const fp2_t var_expected =  { {0x500655B2, 0x67819F25, 0x81460F46, 0xE3A792BC, 0x03710C1E, 0x94A6075F, 0x3D79F0FF, 0x7585D7C9},
	{0x4B5BC274, 0xC8AFDC73, 0xC0F1680F, 0xA3321EFE, 0x8332EBDB, 0xA3CBCA26, 0x48F58C58, 0xAFAC4278} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 361 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 362 a1");
	}
	{
		static const fp2_t var_a =  { {0xEF410447, 0x297457A9, 0x1E9203BF, 0xACF1C223, 0x2A1D5245, 0x29B1F97B, 0xE13D506E, 0x3A128CDC},
	{0x81FD8C2D, 0xCD9FCEAE, 0xBB9845BB, 0xDBDAF6E3, 0x747FA37A, 0x48F0DC39, 0xF6692C0F, 0x60BE4E98} } ;
		static const fp2_t var_expected =  { {0x72EB3054, 0xD57A3207, 0xB5E5DB87, 0x661FEA7D, 0x29C5376F, 0xD1AE62F0, 0x5EE18BBA, 0x800111E5},
	{0xE02EA86E, 0x314EBB02, 0x18DF998B, 0x3736B5BD, 0xDF62E63A, 0xB26F8031, 0x49B5B019, 0x59555029} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 363 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 364 a1");
	}
	{
		static const fp2_t var_a =  { {0x084F5F1C, 0x3E0C2DF2, 0x3A12A16C, 0x0D4A8A02, 0x334A0666, 0xAC853F4E, 0xB30EB1CB, 0x03CF7D17},
	{0x6C8EB537, 0xC58C75A6, 0xBF56B91C, 0xB936CA11, 0x21FE3313, 0x331ECDDD, 0xD6C50848, 0x64E107B4} } ;
		static const fp2_t var_expected =  { {0x59DCD57F, 0xC0E25BBF, 0x9A653DDA, 0x05C7229E, 0x2098834F, 0x4EDB1D1D, 0x8D102A5D, 0xB64421AA},
	{0xF59D7F64, 0x3962140A, 0x1521262A, 0x59DAE28F, 0x31E456A1, 0xC8418E8E, 0x6959D3E0, 0x5532970D} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 365 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 366 a1");
	}
	{
		static const fp2_t var_a =  { {0xD76645BC, 0x6029D0EE, 0xA153BA7C, 0xD4F488AF, 0x04D60846, 0x2F25D746, 0xA20F45F6, 0x5EEBF34C},
	{0x97B2BF39, 0x422F8A7D, 0xB91FE3D7, 0x6805E986, 0x885137D1, 0xEC1F2156, 0x9EC5E4A3, 0xA226F9E5} } ;
		static const fp2_t var_expected =  { {0x8AC5EEDF, 0x9EC4B8C2, 0x332424CA, 0x3E1D23F1, 0x4F0C816E, 0xCC3A8525, 0x9E0F9632, 0x5B27AB75},
	{0xCA797562, 0xBCBEFF33, 0x1B57FB6F, 0xAB0BC31A, 0xCB9151E3, 0x0F413B14, 0xA158F785, 0x17ECA4DC} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 367 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 368 a1");
	}
	{
		static const fp2_t var_a =  { {0x9FBBB120, 0x53233EEB, 0xE327C838, 0x112546B6, 0xBF6DCE16, 0x2478863F, 0x167FC4F4, 0x33374C31},
	{0xA2DFEA2B, 0xAC958D9D, 0xACF41EF7, 0x709914A9, 0x488A94EC, 0x8DB642FD, 0x58E62B68, 0x2E8DDC0C} } ;
		static const fp2_t var_expected =  { {0xC270837B, 0xABCB4AC5, 0xF150170E, 0x01EC65E9, 0x9474BB9F, 0xD6E7D62B, 0x299F1734, 0x86DC5291},
	{0xBF4C4A70, 0x5258FC13, 0x2783C04F, 0xA27897F7, 0x0B57F4C8, 0x6DAA196E, 0xE738B0C0, 0x8B85C2B5} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 369 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 370 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 371 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 372 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 373 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 374 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 375 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 376 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 377 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 378 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 379 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 380 a1");
	}
	{
		static const fp2_t var_a =  { {0x20A1F9CB, 0x1C7152E0, 0x235061FC, 0xEF23DFE4, 0x234FB4B5, 0x436D102D, 0x39BB0B9D, 0x337F2F91},
	{0xF5BEA3B9, 0xA4ADA6C0, 0x305A6858, 0xE8AA4620, 0x8C24B356, 0x5E925BB6, 0x4EC6A9CD, 0x42F4F4AC} } ;
		static const fp2_t var_expected =  { {0x4143F396, 0x38E2A5C0, 0x46A0C3F8, 0xDE47BFC8, 0x469F696B, 0x86DA205A, 0x7376173A, 0x66FE5F22},
	{0xEB7D4772, 0x495B4D81, 0x60B4D0B1, 0xD1548C40, 0x184966AD, 0xBD24B76D, 0x9D8D539A, 0x85E9E958} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 381 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 382 a1");
	}
	{
		static const fp2_t var_a =  { {0xE0AADDC3, 0xFD8C7797, 0x18E1B46F, 0x22881453, 0x7BABFDB9, 0x748A1E82, 0x7387138B, 0x3AD4DF36},
	{0x875574FE, 0x124F84E6, 0x4ACC7B20, 0xA16A8CDF, 0x76538335, 0x0682D72A, 0x485D5090, 0x44078084} } ;
		static const fp2_t var_expected =  { {0xC155BB86, 0xFB18EF2F, 0x31C368DF, 0x451028A6, 0xF757FB72, 0xE9143D04, 0xE70E2716, 0x75A9BE6C},
	{0x0EAAE9FC, 0x249F09CD, 0x9598F640, 0x42D519BE, 0xECA7066B, 0x0D05AE54, 0x90BAA120, 0x880F0108} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 383 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 384 a1");
	}
	{
		static const fp2_t var_a =  { {0x5BF62C03, 0x7FF8AC3C, 0xBC1A4212, 0x315B5CF0, 0x5ED6D61E, 0xFA7C198E, 0xEE6D2B8E, 0x08962972},
	{0xA2AD9605, 0x198DB55D, 0xE8496858, 0x4357C9FB, 0x0663A519, 0x47677C7C, 0x4E61C994, 0xA8445015} } ;
		static const fp2_t var_expected =  { {0xB7EC5806, 0xFFF15878, 0x78348424, 0x62B6B9E1, 0xBDADAC3C, 0xF4F8331C, 0xDCDA571D, 0x112C52E5},
	{0xE32EF76F, 0x342CE109, 0xFC1AF169, 0x739DE756, 0xB8E4C07D, 0x936E9C8C, 0x5CA4B6FF, 0x96750168} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 385 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 386 a1");
	}
	{
		static const fp2_t var_a =  { {0xD2007493, 0x65D8473C, 0x9FB05D67, 0x29944D2A, 0xF036C281, 0x4629ED84, 0x137E6A37, 0x820856EE},
	{0x214DCEDC, 0x1F054CA5, 0x63E4C38A, 0x340386C4, 0x32769B02, 0x45DDE239, 0xEB01CF9C, 0x0E97E5B5} } ;
		static const fp2_t var_expected =  { {0x41D4B48B, 0xCCC204C8, 0x6AE8DB87, 0x4016EDB4, 0x8C8AFB4D, 0x90F37E9E, 0xE6DDF845, 0x49FD0F19},
	{0x429B9DB8, 0x3E0A994A, 0xC7C98714, 0x68070D88, 0x64ED3604, 0x8BBBC472, 0xD6039F38, 0x1D2FCB6B} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 387 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 388 a1");
	}
	{
		static const fp2_t var_a =  { {0x69D471FA, 0xB59E924B, 0xB8FDD3AC, 0x4992BB33, 0x42E794D4, 0x0B1B1757, 0x49453ED9, 0x17C15FC7},
	{0xA72D00FA, 0xC973F49E, 0xA97442AF, 0x62AAA656, 0x7E5B0C80, 0x50B28463, 0xE6CF5D23, 0x3D09BCB1} } ;
		static const fp2_t var_expected =  { {0xD3A8E3F4, 0x6B3D2496, 0x71FBA759, 0x93257667, 0x85CF29A8, 0x16362EAE, 0x928A7DB2, 0x2F82BF8E},
	{0x4E5A01F4, 0x92E7E93D, 0x52E8855F, 0xC5554CAD, 0xFCB61900, 0xA16508C6, 0xCD9EBA46, 0x7A137963} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 389 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 390 a1");
	}
	{
		static const fp2_t var_a =  { {0x7F45B0A2, 0xB3489C91, 0x420D12C5, 0x0DFEB3A2, 0xA6A75258, 0x4035933D, 0x3C7D26B0, 0x738A75A2},
	{0xB5EEDDA4, 0xFD59E418, 0x13D427B6, 0xEBA7A482, 0x5D2C9B62, 0xFC5239BC, 0x0AB1A915, 0x812EBE21} } ;
		static const fp2_t var_expected =  { {0x9C5F2CA9, 0x67A2AF71, 0xAFA24644, 0x08EBBAA3, 0xF96C1AFB, 0x850ACA0F, 0x38DB7137, 0x2D014C82},
	{0x09B186AD, 0xFBC53E80, 0x53307026, 0xC43D9C63, 0x6676AD10, 0xFD44170D, 0xD5447602, 0x4849DD7F} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 391 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 392 a1");
	}
	{
		static const fp2_t var_a =  { {0xB502CB48, 0xE5AE71BA, 0xB42AB27D, 0x3299A3E4, 0xABEE231B, 0x1802205F, 0xD39B9898, 0x83347284},
	{0x0C12341B, 0xDE3B7721, 0x3BE4B404, 0x2C582A53, 0x7D4018D1, 0x1E7B107F, 0x5E8FBF94, 0x680786CD} } ;
		static const fp2_t var_expected =  { {0x07D961F5, 0xCC6E59C4, 0x93DD85B4, 0x52219B28, 0x03F9BC81, 0x34A3E454, 0x67185507, 0x4C554647},
	{0xB5F8339B, 0xBD886490, 0xA35188C2, 0x459EA805, 0xA69DA7ED, 0x4195C493, 0x7D00A2FF, 0x15FB6ED8} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 393 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 394 a1");
	}
	{
		static const fp2_t var_a =  { {0xECA49A88, 0x0FD54A8B, 0xC7714CD2, 0xB60E4F45, 0x24F9EF1F, 0x0A03378F, 0x3763E744, 0x7464E875},
	{0x49DF3337, 0xD4022C24, 0x24A69B24, 0xAFD6A8EC, 0x7E5AC3AE, 0xD224A85C, 0xEDCAF261, 0x04BD73F4} } ;
		static const fp2_t var_expected =  { {0x771D0075, 0x20BC0B66, 0xBA6ABA5D, 0x590AF1EA, 0xF611548A, 0x18A612B2, 0x2EA8F25F, 0x2EB63228},
	{0x93BE666E, 0xA8045848, 0x494D3649, 0x5FAD51D8, 0xFCB5875D, 0xA44950B8, 0xDB95E4C3, 0x097AE7E9} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 395 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 396 a1");
	}
	{
		static const fp2_t var_a =  { {0x46BF434B, 0x363AAC1C, 0x765E8BC4, 0xD5C29FE5, 0x20DA9AE0, 0xCB00B9FB, 0xD2712EFC, 0xB364C281},
	{0xD8515452, 0x7EF35120, 0x66266E96, 0x892850C1, 0x8B28EDC7, 0x5CBDE087, 0xFE60F765, 0x91D8923F} } ;
		static const fp2_t var_expected =  { {0x2B5251FB, 0x6D86CE87, 0x18453841, 0x9873932A, 0xEDD2AC0C, 0x9AA1178A, 0x64C381D0, 0xACB5E641},
	{0x4E767409, 0xFEF81890, 0xF7D4FDE5, 0xFF3EF4E1, 0xC26F51D9, 0xBE1B64A3, 0xBCA312A1, 0x699D85BD} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 397 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 398 a1");
	}
	{
		static const fp2_t var_a =  { {0xC1C2F47C, 0xA139F26D, 0x23E4A55B, 0xF991979F, 0x9EA85D65, 0x52FAF273, 0x0DB36502, 0x33E0D719},
	{0x0F6D97CA, 0xC7B1146E, 0xDC54C8EF, 0xA057373D, 0x1A73A806, 0x61AB5BCD, 0x9C4D9A61, 0x2D444152} } ;
		static const fp2_t var_expected =  { {0x8385E8F8, 0x4273E4DB, 0x47C94AB7, 0xF3232F3E, 0x3D50BACB, 0xA5F5E4E7, 0x1B66CA04, 0x67C1AE32},
	{0x1EDB2F94, 0x8F6228DC, 0xB8A991DF, 0x40AE6E7B, 0x34E7500D, 0xC356B79A, 0x389B34C2, 0x5A8882A5} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 399 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 400 a1");
	}
	{
		static const fp2_t var_a =  { {0x25ECC682, 0xD2050CD2, 0xC75954D4, 0x19F62612, 0x2AFBFD1F, 0xCA597B86, 0x908BA150, 0x0F1ACC39},
	{0x130833C3, 0xD2DCC29C, 0xF34C9F2E, 0x62F75D3C, 0x2F0E65AF, 0xB1686535, 0x0F4A3007, 0x21EA5742} } ;
		static const fp2_t var_expected =  { {0x4BD98D04, 0xA40A19A4, 0x8EB2A9A9, 0x33EC4C25, 0x55F7FA3E, 0x94B2F70C, 0x211742A1, 0x1E359873},
	{0x26106786, 0xA5B98538, 0xE6993E5D, 0xC5EEBA79, 0x5E1CCB5E, 0x62D0CA6A, 0x1E94600F, 0x43D4AE84} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 401 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 402 a1");
	}
	{
		static const fp2_t var_a =  { {0x2C98654B, 0x90A2158A, 0x9C51008A, 0xF82BB3D8, 0x99209502, 0xB37A6851, 0xC430710C, 0x46EE3CB3},
	{0xE5FF9D89, 0x04B973A9, 0x84894B0A, 0x6D9ADD32, 0xBC789A87, 0x60EDA9DA, 0x9FC5A2CF, 0x371D1549} } ;
		static const fp2_t var_expected =  { {0x5930CA96, 0x21442B14, 0x38A20115, 0xF05767B1, 0x32412A05, 0x66F4D0A3, 0x8860E219, 0x8DDC7967},
	{0xCBFF3B12, 0x0972E753, 0x09129614, 0xDB35BA65, 0x78F1350E, 0xC1DB53B5, 0x3F8B459E, 0x6E3A2A93} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 403 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 404 a1");
	}
	{
		static const fp2_t var_a =  { {0xF7E38D35, 0xE09C2346, 0x9B69BA9B, 0xD39C487E, 0xFD2537C2, 0xC36301F8, 0x13529734, 0x455D40E6},
	{0xC673343B, 0x026E5CE3, 0xA8ED8DCB, 0x9EB47D1D, 0xF2CFD186, 0xC4604724, 0xD793290E, 0x7E7DD5D0} } ;
		static const fp2_t var_expected =  { {0xEFC71A6A, 0xC138468D, 0x36D37537, 0xA73890FD, 0xFA4A6F85, 0x86C603F1, 0x26A52E69, 0x8ABA81CC},
	{0x2ABA33DB, 0x05EE3016, 0x7D633C4F, 0x2A574D9A, 0x91BD1958, 0x8D6031DE, 0x6F0775F4, 0x42E80CDF} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 405 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 406 a1");
	}
	{
		static const fp2_t var_a =  { {0xAC8C535B, 0x066799DB, 0xA75EC81E, 0x4E9CDEBF, 0x4DFEDA83, 0xE4B19BD3, 0xA6892D2B, 0x2E434ECA},
	{0x37D50C8E, 0xB1560FA8, 0xB9547AB4, 0x126BEE19, 0x41DF4933, 0x7269B82F, 0x7E7CAC8D, 0x43C841FA} } ;
		static const fp2_t var_expected =  { {0x5918A6B6, 0x0CCF33B7, 0x4EBD903C, 0x9D39BD7F, 0x9BFDB506, 0xC96337A6, 0x4D125A57, 0x5C869D95},
	{0x6FAA191C, 0x62AC1F50, 0x72A8F569, 0x24D7DC33, 0x83BE9266, 0xE4D3705E, 0xFCF9591A, 0x879083F4} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 407 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 408 a1");
	}
	{
		static const fp2_t var_a =  { {0x8A268E11, 0x88085AEA, 0x6346F3A0, 0x12E7BA94, 0xC835BF74, 0x5308A70E, 0x25505B9B, 0x32C63BCF},
	{0xF9F730B9, 0x36512FEE, 0x4E222678, 0x256457C3, 0x5B30BFAF, 0x3E7DF2C9, 0x9FCBA889, 0x13A89008} } ;
		static const fp2_t var_expected =  { {0x144D1C22, 0x1010B5D5, 0xC68DE741, 0x25CF7528, 0x906B7EE8, 0xA6114E1D, 0x4AA0B736, 0x658C779E},
	{0xF3EE6172, 0x6CA25FDD, 0x9C444CF0, 0x4AC8AF86, 0xB6617F5E, 0x7CFBE592, 0x3F975112, 0x27512011} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 409 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 410 a1");
	}
	{
		static const fp2_t var_a =  { {0xD20A1FA0, 0x280A422E, 0x5D76D533, 0x2FC36B0D, 0x9159D5B3, 0x7E451D48, 0xF928AABF, 0x3A89028F},
	{0xAAF60682, 0xF7200D71, 0x6E5A3AF4, 0x62858D6F, 0xDD38CE56, 0x42D15BC0, 0x42C2BEC2, 0x00713DDF} } ;
		static const fp2_t var_expected =  { {0xA4143F40, 0x5014845D, 0xBAEDAA66, 0x5F86D61A, 0x22B3AB66, 0xFC8A3A91, 0xF251557E, 0x7512051F},
	{0x55EC0D04, 0xEE401AE3, 0xDCB475E9, 0xC50B1ADE, 0xBA719CAC, 0x85A2B781, 0x85857D84, 0x00E27BBE} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 411 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 412 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 413 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 414 a1");
	}
	{
		static const fp2_t var_a =  { {0x76C656ED, 0x6B2B4271, 0xA990CF74, 0x57BD8680, 0xD4679F20, 0x0951E9D2, 0x3F132EAC, 0x37348C45},
	{0x02DE3A74, 0x342CCF40, 0x8E2E64A7, 0x2CAFAA28, 0xB1927D8E, 0x7E2D32E9, 0x5744D8AE, 0x7DA1DFEF} } ;
		static const fp2_t var_expected =  { {0x76C656ED, 0x6B2B4271, 0xA990CF74, 0x57BD8680, 0xD4679F20, 0x0951E9D2, 0x3F132EAC, 0x37348C45},
	{0x5F4DFA27, 0xCAC1BA71, 0x46497A9F, 0xE6620278, 0xA2500C26, 0x7D332981, 0xE8DA037A, 0x3C71BED2} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 415 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 416 a1");
	}
	{
		static const fp2_t var_a =  { {0x04F53100, 0xC2ACFADB, 0x179086DF, 0xC609898F, 0xD563C7AA, 0x0C978F05, 0x25F823AA, 0xB58784DA},
	{0x0BCD7455, 0x602DBCF0, 0xB8939B61, 0x048D5BF8, 0x7B2955BC, 0xFE521114, 0xF6658972, 0x668EE29A} } ;
		static const fp2_t var_expected =  { {0x04F53100, 0xC2ACFADB, 0x179086DF, 0xC609898F, 0xD563C7AA, 0x0C978F05, 0x25F823AA, 0xB58784DA},
	{0x565EC046, 0x9EC0CCC1, 0x1BE443E5, 0x0E8450A8, 0xD8B933F9, 0xFD0E4B56, 0x49B952B5, 0x5384BC27} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 417 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 418 a1");
	}
	{
		static const fp2_t var_a =  { {0x736E1E08, 0x3FE2CD85, 0x24CE9FD2, 0x225D1D73, 0xC29CE743, 0xFE8AC845, 0x73A1617D, 0x326A38F7},
	{0x627D93D3, 0xC30F69CF, 0xD7CE8E29, 0xE763B737, 0x8B532B25, 0xF88675B6, 0xA2D9AF2D, 0x9889820B} } ;
		static const fp2_t var_expected =  { {0x736E1E08, 0x3FE2CD85, 0x24CE9FD2, 0x225D1D73, 0xC29CE743, 0xFE8AC845, 0x73A1617D, 0x326A38F7},
	{0x627D93D3, 0xC30F69CF, 0xD7CE8E29, 0xE763B737, 0x8B532B25, 0xF88675B6, 0xA2D9AF2D, 0x9889820B} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 419 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 420 a1");
	}
	{
		static const fp2_t var_a =  { {0xDE0EC95E, 0xE6F71925, 0x574B3DE5, 0xF8EEC240, 0xAF1C6B89, 0x05A2E178, 0x4B7A9F23, 0x79913F46},
	{0xFA09845E, 0x115523C9, 0xEC7D13A8, 0xDB1500D3, 0xCDB509AD, 0x7F060641, 0xBEAC1E85, 0x3EF7A3CB} } ;
		static const fp2_t var_expected =  { {0xDE0EC95E, 0xE6F71925, 0x574B3DE5, 0xF8EEC240, 0xAF1C6B89, 0x05A2E178, 0x4B7A9F23, 0x79913F46},
	{0xFA09845E, 0x115523C9, 0xEC7D13A8, 0xDB1500D3, 0xCDB509AD, 0x7F060641, 0xBEAC1E85, 0x3EF7A3CB} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 421 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 422 a1");
	}
	{
		static const fp2_t var_a =  { {0x730B9E11, 0x27C039DC, 0x647AD97A, 0xA9AFDD77, 0x4087C363, 0xF65E790B, 0xA9E480D0, 0x2030806A},
	{0x656B7387, 0xFA90AE8B, 0x81EF585B, 0x8037A449, 0x5E29EFA7, 0x143C8B6B, 0x875180B6, 0x540EFA74} } ;
		static const fp2_t var_expected =  { {0x730B9E11, 0x27C039DC, 0x647AD97A, 0xA9AFDD77, 0x4087C363, 0xF65E790B, 0xA9E480D0, 0x2030806A},
	{0x656B7387, 0xFA90AE8B, 0x81EF585B, 0x8037A449, 0x5E29EFA7, 0x143C8B6B, 0x875180B6, 0x540EFA74} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 423 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 424 a1");
	}
	{
		static const fp2_t var_a =  { {0x3308D349, 0x75735F7D, 0xC83F6E47, 0x68B934FB, 0x781E269B, 0xB1F02E0C, 0xAFEAEDE4, 0x102F65E8},
	{0x2BB4425E, 0xB7877757, 0x5C64F158, 0x8F7DDB80, 0xC50E06C9, 0x97B2C81D, 0x0A0459AB, 0x008460EE} } ;
		static const fp2_t var_expected =  { {0x3308D349, 0x75735F7D, 0xC83F6E47, 0x68B934FB, 0x781E269B, 0xB1F02E0C, 0xAFEAEDE4, 0x102F65E8},
	{0x3677F23D, 0x4767125A, 0x7812EDEE, 0x8393D120, 0x8ED482EB, 0x63AD944D, 0x361A827D, 0xB98F3DD4} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 425 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 426 a1");
	}
	{
		static const fp2_t var_a =  { {0x09D5665A, 0x3AAFCE41, 0x7D1698C0, 0xBFE09E71, 0xD593DF20, 0xF957AC8A, 0x32E28E72, 0x71BDD78B},
	{0xF6F94F10, 0xEAF2B9C1, 0x538FDD35, 0xB6742F82, 0xEC8EDF42, 0xF3113BCA, 0x49906711, 0x1ABE53E1} } ;
		static const fp2_t var_expected =  { {0x09D5665A, 0x3AAFCE41, 0x7D1698C0, 0xBFE09E71, 0xD593DF20, 0xF957AC8A, 0x32E28E72, 0x71BDD78B},
	{0xF6F94F10, 0xEAF2B9C1, 0x538FDD35, 0xB6742F82, 0xEC8EDF42, 0xF3113BCA, 0x49906711, 0x1ABE53E1} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 427 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 428 a1");
	}
	{
		static const fp2_t var_a =  { {0xA51DC665, 0xF4C19B8B, 0xA54124BB, 0xA194D779, 0x9A60E412, 0xA6417650, 0xBBC23F86, 0x128A557A},
	{0xD95BCA7F, 0xEAF8221A, 0x96835C46, 0x6964C84F, 0x7879FFC7, 0x47224852, 0x15A0C7ED, 0x00469768} } ;
		static const fp2_t var_expected =  { {0xA51DC665, 0xF4C19B8B, 0xA54124BB, 0xA194D779, 0x9A60E412, 0xA6417650, 0xBBC23F86, 0x128A557A},
	{0x88D06A1C, 0x13F66796, 0x3DF48300, 0xA9ACE451, 0xDB6889ED, 0xB43E1418, 0x2A7E143B, 0xB9CD075A} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 429 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 430 a1");
	}
	{
		static const fp2_t var_a =  { {0x70702FA4, 0x54B49E70, 0x9794614A, 0xA5520D9B, 0x32E78B75, 0xED3246DB, 0x570F14ED, 0x21FDD01A},
	{0x3C915E63, 0x2D0AE74B, 0x410A43AB, 0xD78BDD98, 0x9367D88A, 0x0E0D64EB, 0xF8C1A900, 0x210A9540} } ;
		static const fp2_t var_expected =  { {0x70702FA4, 0x54B49E70, 0x9794614A, 0xA5520D9B, 0x32E78B75, 0xED3246DB, 0x570F14ED, 0x21FDD01A},
	{0x259AD638, 0xD1E3A266, 0x936D9B9B, 0x3B85CF08, 0xC07AB12A, 0xED52F77F, 0x475D3328, 0x99090981} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 431 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 432 a1");
	}
	{
		static const fp2_t var_a =  { {0x58DBFC13, 0x9B62B2BB, 0x27CF254D, 0x08C108D4, 0xF9139EAD, 0x10C915AD, 0x3FC408E1, 0x85C361D1},
	{0x7841B1E5, 0x1E71F25F, 0x2D1F3DAB, 0x9E801D89, 0x153FAEB3, 0x37541F6F, 0x4FA5CD90, 0x77999842} } ;
		static const fp2_t var_expected =  { {0x58DBFC13, 0x9B62B2BB, 0x27CF254D, 0x08C108D4, 0xF9139EAD, 0x10C915AD, 0x3FC408E1, 0x85C361D1},
	{0xE9EA82B6, 0xE07C9751, 0xA758A19B, 0x74918F17, 0x3EA2DB01, 0xC40C3CFC, 0xF0790E98, 0x427A067F} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 433 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 434 a1");
	}
	{
		static const fp2_t var_a =  { {0xADA662D1, 0x3644E0CD, 0xEAFA4761, 0x430E42A9, 0xEC9252E9, 0x83FB2E3D, 0x2262F4B0, 0xA8FB6586},
	{0x38D01319, 0x9A12839B, 0x72C65508, 0xFFEB92A1, 0xB9E5E285, 0x59A2857E, 0xEED5F719, 0x1DB67E56} } ;
		static const fp2_t var_expected =  { {0xADA662D1, 0x3644E0CD, 0xEAFA4761, 0x430E42A9, 0xEC9252E9, 0x83FB2E3D, 0x2262F4B0, 0xA8FB6586},
	{0x38D01319, 0x9A12839B, 0x72C65508, 0xFFEB92A1, 0xB9E5E285, 0x59A2857E, 0xEED5F719, 0x1DB67E56} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 435 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 436 a1");
	}
	{
		static const fp2_t var_a =  { {0x624BBFF6, 0x5FAC8BB8, 0x895E972E, 0x86BA60E3, 0xA43FE7F2, 0x96C831B4, 0x9F219DB7, 0x0709A9FD},
	{0xB4C1921E, 0xEDA23447, 0xEC716C37, 0xB38B8785, 0x6407E173, 0xBE98AA1E, 0x3F2F3026, 0x0C2B0F8C} } ;
		static const fp2_t var_expected =  { {0x624BBFF6, 0x5FAC8BB8, 0x895E972E, 0x86BA60E3, 0xA43FE7F2, 0x96C831B4, 0x9F219DB7, 0x0709A9FD},
	{0xAD6AA27D, 0x114C5569, 0xE806730F, 0x5F86251A, 0xEFDAA841, 0x3CC7B24C, 0x00EFAC02, 0xADE88F36} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 437 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 438 a1");
	}
	{
		static const fp2_t var_a =  { {0xB95329CC, 0x1BC433DD, 0x51A10EDB, 0xB4BEE8F8, 0x77E255A6, 0x11E321B9, 0x38D10860, 0x9C494DA5},
	{0x734A34BB, 0xA7538B43, 0xC6CDA868, 0xD55E88D8, 0x10006D08, 0x73211013, 0xA033B884, 0x1383A00E} } ;
		static const fp2_t var_expected =  { {0xB95329CC, 0x1BC433DD, 0x51A10EDB, 0xB4BEE8F8, 0x77E255A6, 0x11E321B9, 0x38D10860, 0x9C494DA5},
	{0x734A34BB, 0xA7538B43, 0xC6CDA868, 0xD55E88D8, 0x10006D08, 0x73211013, 0xA033B884, 0x1383A00E} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 439 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 440 a1");
	}
	{
		static const fp2_t var_a =  { {0xA93FD751, 0x94793F87, 0x0BDF901F, 0x0017BFC4, 0x17EF3928, 0x231F7917, 0x6D61410F, 0x5EC71144},
	{0x6158C7A2, 0x8B13D917, 0xDEC893D8, 0xC16118FD, 0x6FEEED9A, 0x6767B1CF, 0xC43A5896, 0x19DA4979} } ;
		static const fp2_t var_expected =  { {0xA93FD751, 0x94793F87, 0x0BDF901F, 0x0017BFC4, 0x17EF3928, 0x231F7917, 0x6D61410F, 0x5EC71144},
	{0x00D36CF9, 0x73DAB09A, 0xF5AF4B6E, 0x51B093A2, 0xE3F39C1A, 0x93F8AA9B, 0x7BE48392, 0xA0395548} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 441 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 442 a1");
	}
	{
		static const fp2_t var_a =  { {0x5DC6ED9E, 0xCECF3E19, 0xDAD7525A, 0x5E856AB0, 0x8C26CD26, 0xF17C284A, 0x10BDADB9, 0x3805944A},
	{0x918D1845, 0xDD59650B, 0x85FEBCDB, 0x4A630EB6, 0x33EDA4CE, 0xF8C32DB3, 0xEC8FC96A, 0x519ADC7E} } ;
		static const fp2_t var_expected =  { {0x5DC6ED9E, 0xCECF3E19, 0xDAD7525A, 0x5E856AB0, 0x8C26CD26, 0xF17C284A, 0x10BDADB9, 0x3805944A},
	{0x918D1845, 0xDD59650B, 0x85FEBCDB, 0x4A630EB6, 0x33EDA4CE, 0xF8C32DB3, 0xEC8FC96A, 0x519ADC7E} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 443 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 444 a1");
	}
	{
		static const fp2_t var_a =  { {0xCF66829C, 0xF6CB5A0F, 0x64AFA7A6, 0x08CEDA06, 0xA70B24E2, 0x9B4ECB5F, 0xBFE8B0FC, 0x949BD254},
	{0x754D3607, 0x872FED7D, 0xB3BA6BF2, 0xFFCE5B68, 0x45EDAE4B, 0x05016735, 0x60166C9A, 0x447FA74B} } ;
		static const fp2_t var_expected =  { {0xCF66829C, 0xF6CB5A0F, 0x64AFA7A6, 0x08CEDA06, 0xA70B24E2, 0x9B4ECB5F, 0xBFE8B0FC, 0x949BD254},
	{0xECDEFE94, 0x77BE9C33, 0x20BD7354, 0x13435138, 0x0DF4DB69, 0xF65EF536, 0xE0086F8E, 0x7593F776} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 445 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 446 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C860E0F, 0xF79F0B97, 0xB9CF73C9, 0xC37E3C69, 0xE2F321D7, 0xD64F4994, 0xD2626E68, 0x49F060A8},
	{0x6AC6A11E, 0xE65BC0DA, 0xD1C398BF, 0x11F81471, 0x273E7913, 0x94B223FB, 0xD41DE592, 0x3AFA9F0E} } ;
		static const fp2_t var_expected =  { {0x4C860E0F, 0xF79F0B97, 0xB9CF73C9, 0xC37E3C69, 0xE2F321D7, 0xD64F4994, 0xD2626E68, 0x49F060A8},
	{0x6AC6A11E, 0xE65BC0DA, 0xD1C398BF, 0x11F81471, 0x273E7913, 0x94B223FB, 0xD41DE592, 0x3AFA9F0E} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 447 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 448 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 449 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 450 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 451 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 452 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 453 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 454 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 455 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 456 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84},
	{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84} } ;
		static const fp2_t var_expected =  { {0x622C349B, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0x3A139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 457 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 458 a1");
	}
	{
		static const fp2_t var_a =  { {0xF1C7B246, 0xAAF540C8, 0x32BDC7D6, 0x6B39607F, 0x5E0CA08D, 0x5F4642CB, 0x7A812827, 0xB266198B},
	{0xBE575B70, 0x19C80B3F, 0xD166627A, 0xD2C0BA10, 0xB914BB7A, 0x4BC0D685, 0x7860F147, 0x4B2AEA97} } ;
		static const fp2_t var_expected =  { {0x80F05220, 0x8F05B647, 0xE0A38AFD, 0xC4B34860, 0xC9F71EE9, 0x7EEE5B8D, 0xBA410A46, 0x6898F7AB},
	{0x14E75E6D, 0x35D99842, 0x8BDDC8AB, 0x61DEA6BD, 0x9A7A6283, 0x38AB9101, 0xF04C6D60, 0x949B9DD9} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 459 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 460 a1");
	}
	{
		static const fp2_t var_a =  { {0x4F784AE5, 0x0155D05F, 0x4A3FDA02, 0xB1936602, 0x10504179, 0x8EBF2CFD, 0xB14B6698, 0x732C69DA},
	{0x4E0A83B0, 0x8FA9A947, 0xBDC848A2, 0x566AAEE4, 0x8CB2DA4C, 0x832E1D30, 0x97A80B35, 0x250A5232} } ;
		static const fp2_t var_expected =  { {0x01F41761, 0xCD2F6D1E, 0xB54B5ABD, 0x0326CEC3, 0x22EDFB73, 0x3F6C7E04, 0x54A3CCB8, 0x33283549},
	{0xC54F9C5E, 0xA07D1BC4, 0x30D604E5, 0xBED2D737, 0x82F73270, 0x107ECEAD, 0x5F470339, 0xA81AE3D1} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 461 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 462 a1");
	}
	{
		static const fp2_t var_a =  { {0x95B1CCCA, 0x893601DC, 0x3AA561AE, 0x2081DD3E, 0xBFF07234, 0x29DCA17F, 0xCB0C92BD, 0x642CA71F},
	{0x5C781E40, 0x7417C842, 0xE10F441C, 0x71E1B80C, 0x31386EE2, 0x2AC33C2C, 0x84EDE6E3, 0x411DE99C} } ;
		static const fp2_t var_expected =  { {0xA2A36C1C, 0xBE023EF3, 0x0C59EC73, 0x777027AA, 0x18473CA8, 0x8FB052E9, 0x70BFA1A2, 0x6CFC6902},
	{0x0EF6C4DC, 0x97FD6590, 0xEC869509, 0xB5522E32, 0x3CD9C387, 0xE9F51A19, 0xF75B3F88, 0x00525CCB} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 463 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 464 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DEEB46A, 0x0AF4FA44, 0x43A7ECF2, 0xB7C72207, 0x80C3534D, 0x7C09DA36, 0xA47149B0, 0xB19279DA},
	{0x2FF535EE, 0xC93B3656, 0x81D597F5, 0x7417B037, 0x2E6182CD, 0x30FD99F5, 0xB2B188A2, 0xB62806F7} } ;
		static const fp2_t var_expected =  { {0x5788C9B2, 0x68FA3772, 0xA23CD05B, 0x6012A120, 0x4F34C7BA, 0xD0B44160, 0x252969CC, 0x518A1AF3},
	{0xBFDD9C66, 0x9A06608C, 0x40D27E33, 0x00D50A7E, 0xF03BAF46, 0xC37A83F0, 0x1948D004, 0x845B6976} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 465 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 466 a1");
	}
	{
		static const fp2_t var_a =  { {0xFCF76686, 0x012D9E58, 0x7A311096, 0xCE9D49AA, 0x052055C2, 0x03D436CF, 0x9D27221A, 0x2D72E127},
	{0xE6A81839, 0x6490D182, 0xFF39CD63, 0x8692E335, 0xD5FA8066, 0xE1659E6C, 0x6689336C, 0x14019B25} } ;
		static const fp2_t var_expected =  { {0xF84D9636, 0xF2549055, 0xD4DC4FF6, 0xE831934D, 0xA80105FE, 0x87AD91F3, 0x2799E083, 0x82F55460},
	{0xEA84636D, 0x05C9DA17, 0xB4810E2D, 0x54967F0C, 0xD1BAB75E, 0x781BD330, 0xED5A3921, 0x4893348E} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 467 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 468 a1");
	}
	{
		static const fp2_t var_a =  { {0x152EC612, 0x9FFA014F, 0x4403458A, 0xDC073627, 0x27C11B53, 0x31899BD7, 0x9F46F9EA, 0x8A1E191C},
	{0xEA21100E, 0x3194576B, 0x7DAEF00C, 0x8706F937, 0xB7B7E201, 0x6683D533, 0xC9DD5549, 0x080711E3} } ;
		static const fp2_t var_expected =  { {0x1B330E9A, 0x0ACFA9FD, 0xA73DE980, 0xEA32FF76, 0x07A8C7F1, 0x0F3349C2, 0x0D4E29C4, 0xB823C756},
	{0x55966317, 0xB549F960, 0xE1AC84DB, 0x94279EF2, 0x5E7DC7A3, 0xBADBE1DF, 0xC5B7C7EC, 0x7505F210} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 469 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 470 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFD2D668, 0xC9694EDA, 0x735F7B40, 0xF085EA0F, 0x04D11532, 0xD9CE4611, 0xE89DCCB9, 0xA8E909DF},
	{0x62CED58A, 0xCFF5886D, 0xE8638031, 0x53D26049, 0x3B62CDEC, 0xBBFD9D7B, 0xA1694EEC, 0x8AA9F822} } ;
		static const fp2_t var_expected =  { {0x3FDD6812, 0x1C967558, 0xF912A95F, 0x18150CCE, 0xD6E3D066, 0x64FE3584, 0x4B04375E, 0x6F8B2ADE},
	{0xC54566C3, 0x309C09A0, 0x1410B3F9, 0x2326F216, 0x35EAF6FA, 0xEC60711A, 0xA114E53F, 0x4979C80E} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 471 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 472 a1");
	}
	{
		static const fp2_t var_a =  { {0x6FCA831E, 0xC6B05160, 0xBDEEB3E5, 0x52A831A6, 0xC50DF8C1, 0x8CCD8661, 0xB74D71D1, 0x74E1DF3F},
	{0x5798BD20, 0x9FE1077A, 0x0F138DA9, 0x96BD4DC0, 0x3BB122B2, 0x353DD140, 0x90CF395E, 0x77A72E79} } ;
		static const fp2_t var_expected =  { {0x07BAD726, 0x97D770C9, 0x42C3845F, 0x0D4A1499, 0xCF73EE76, 0x18F61FEA, 0x66DB9DEB, 0x06BFB904},
	{0xBE8979EC, 0x329EB5FC, 0xDC9EC00F, 0x02504FA8, 0x69CB36F1, 0xB96EC14C, 0x9331CAEC, 0x85914C9E} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 473 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 474 a1");
	}
	{
		static const fp2_t var_a =  { {0xAE43B7CC, 0x56BD6D53, 0xF54D0D6A, 0xA790EBF2, 0x38C37443, 0x2F5A83DA, 0xFFB7AFA5, 0x4AEB48D5},
	{0x8940CAE3, 0x9219C32C, 0x62BEF3A2, 0x34ACD97D, 0x44125DB2, 0x3237972F, 0x5588D4B0, 0xA322BB0E} } ;
		static const fp2_t var_expected =  { {0x3B6F4A89, 0xD3A95046, 0x90CB312E, 0xD7D7A3F4, 0xE21E99E4, 0xFE4F5879, 0x3B2E1833, 0x6B8683EB},
	{0xF6542B0A, 0x478A4852, 0xEB98A69D, 0x3063D7E1, 0x418F9CCA, 0x20150ADE, 0xE0CF9D60, 0x65CE8281} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 475 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 476 a1");
	}
	{
		static const fp2_t var_a =  { {0x23F50E38, 0x4BF5BF11, 0x08815B14, 0xC6BE45AC, 0xDDA8258D, 0xA81395A9, 0x22005D5F, 0x069E8A8C},
	{0x7DFEDD45, 0xC3C0D73E, 0x1D041F14, 0x3BF05318, 0x6932D049, 0xCED7AD13, 0xD9C3DBEB, 0xADEB6ADF} } ;
		static const fp2_t var_expected =  { {0x3D193437, 0x451C1F45, 0x7E80864A, 0xDB49592B, 0xEE94AAF3, 0x8DB662D5, 0xBDAACFF7, 0x36B7E4D1},
	{0xF4965182, 0x30E721BC, 0x50236F1C, 0x2FBACD4A, 0x01F4F882, 0x47B6B3DB, 0xE472E661, 0x8E87A620} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 477 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 478 a1");
	}
	{
		static const fp2_t var_a =  { {0x75317ACB, 0x50B98609, 0x89DE0DC8, 0x453B3BC1, 0x7722BCCF, 0x79C15250, 0x08382D4B, 0x7906A484},
	{0x64410F71, 0x2F24DEC2, 0x9CE2F495, 0x6B3B0DFC, 0x1C05D7B2, 0x7DC36F61, 0x6FDE6CC2, 0x74A9AC18} } ;
		static const fp2_t var_expected =  { {0x1C7CBEE2, 0x5231A56E, 0x3C0DA03A, 0xB88CAED2, 0xE0DF66B8, 0xBEC9182F, 0x185A492B, 0xA2FD902D},
	{0x3CC29261, 0xD24D27F3, 0x530B0B37, 0xB5F82106, 0x2076E8C2, 0xB877AA14, 0x788362C3, 0xA9A2B823} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 479 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 480 a1");
	}
	{
		static const fp2_t var_a =  { {0x1CA54D0A, 0x36E92810, 0x647C3D6A, 0x7A51E4A0, 0xCEA52211, 0xED24CE33, 0x5CC4B35C, 0x7FFBDDAD},
	{0xE6D4727D, 0x05FD6EF7, 0xE0E26DD6, 0x5A545BF1, 0x8048B6F6, 0x531D42C3, 0x4BA0A34A, 0x86551724} } ;
		static const fp2_t var_expected =  { {0x09C8CD06, 0x23B766BE, 0x5376E2BF, 0xE0A03F9E, 0xEA37E4A7, 0xDEB8F6B7, 0xA8CAD8BC, 0x39A9BABA},
	{0x92C4810B, 0x38C9B9C6, 0xE6439791, 0x317BBB07, 0xBA32C527, 0x8013543F, 0xBB2A8E7D, 0x9EEEF387} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 481 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 482 a1");
	}
	{
		static const fp2_t var_a =  { {0x2BF1EEE2, 0xE6017F50, 0x65A55C11, 0x32E38834, 0x7D74238F, 0xE8E9BDCB, 0xD091C015, 0x35BB0AB6},
	{0x2E9FA380, 0x7E616E7E, 0x2D1489AE, 0x0BC6F57C, 0x06E55C4F, 0x44978251, 0xC9BF3FA8, 0x36F360EB} } ;
		static const fp2_t var_expected =  { {0x526A9E98, 0x4139DF5B, 0xC9D21A84, 0x97F2A922, 0x905D020B, 0xB1CCB52F, 0xC3898980, 0xAACDCBC2},
	{0x6B4BEDED, 0xB25D33BC, 0x1046DEFB, 0xA112C582, 0x161B07B4, 0x8FBD54E9, 0x9134EA23, 0x876350FA} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 483 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 484 a1");
	}
	{
		static const fp2_t var_a =  { {0x9CE99706, 0xBD56DBB7, 0x2ACB75E5, 0xB32CEE8E, 0xE5137E0A, 0x913F7A2F, 0xCF0B9ADE, 0x6456C201},
	{0x3515899C, 0x53A00E40, 0x8EC5C9D7, 0x0C415EAA, 0x1E90F39E, 0x0DCD3539, 0xD58B2D27, 0x7DE85AB5} } ;
		static const fp2_t var_expected =  { {0x04760CCE, 0x7D3F9FF0, 0x0A17DC12, 0xD60650F0, 0x90C53DDA, 0xA0DFCDCA, 0xB1ABAAFF, 0x5D844DCB},
	{0xE74CBFD3, 0x1D789311, 0xF45ABBDF, 0x072B3DAD, 0x794262B3, 0xF3863394, 0x3DD23855, 0x335CDC32} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 485 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 486 a1");
	}
	{
		static const fp2_t var_a =  { {0x38049873, 0xDBA72E0C, 0x2FB9E81B, 0xAFD720F8, 0x14F95409, 0xCA040D44, 0x35E9DF4C, 0x1D752272},
	{0x921AF8B0, 0xF181E356, 0x19B578F0, 0x33F0A2CB, 0xA2BB6A46, 0x9731360F, 0x85AEC9BB, 0xACE08B30} } ;
		static const fp2_t var_expected =  { {0x3369C27B, 0x83A9A029, 0x9E440FDC, 0xD92970AF, 0x7E54FB63, 0x9E84B6E4, 0x98D5F2A8, 0x85D1CF1D},
	{0x844DCED5, 0xA43BCF68, 0x06FA177B, 0x7C148939, 0xB0D501CD, 0x4901D199, 0xB8C6F29D, 0x5E31ACCF} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 487 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 488 a1");
	}
	{
		static const fp2_t var_a =  { {0x2FCEFC9C, 0x68AB53DA, 0xA7C85359, 0x951E5458, 0x98D4B57B, 0xA107D665, 0x3DB934FC, 0x850C27E5},
	{0x0073D2C8, 0xC0E956C1, 0xEEB53CCE, 0x18E8C9C0, 0x968460E1, 0x12232CA3, 0xE3982481, 0x4D599188} } ;
		static const fp2_t var_expected =  { {0x0B4FB53E, 0xC9F8840C, 0x96829A23, 0x582473C6, 0xE24E26E2, 0x988F8C7F, 0x00F6F1D7, 0x4BEFC33C},
	{0x962B1BDE, 0x87A1EDF2, 0x4B1EEE44, 0x199DEDF0, 0x33A5E800, 0x19AC8851, 0x72D90B4A, 0x7F22252D} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 489 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 490 a1");
	}
	{
		static const fp2_t var_a =  { {0x62FE950E, 0xA0FA3299, 0xE014A003, 0x674BE672, 0xB7607E34, 0x49BA0497, 0x9588EC64, 0x02FE63C1},
	{0x02538EDF, 0x520B56D4, 0xE7916536, 0x76BE342D, 0xA214FB51, 0xACEBAFA2, 0x37844FD7, 0x4747094C} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 491 ");
	}
	{
		static const fp2_t var_a =  { {0xEF6463E6, 0xCBA84805, 0x50E07238, 0x8C5905F3, 0x6C71A546, 0x0C0FE0D0, 0x712D7368, 0x03AAE38C},
	{0x468BE827, 0x133C4CF4, 0x12CADF6C, 0xF59A5A59, 0xC47D9E84, 0xA30BF434, 0xF69F6EFC, 0x7FD98AA7} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 492 ");
	}
	{
		static const fp2_t var_a =  { {0xC0B7CD17, 0x229A4ADF, 0x972E5C28, 0xA083837C, 0x786EF7D8, 0x86D827D8, 0x9D4B6C9C, 0x9A8C3737},
	{0x543C2743, 0xBD4F4E98, 0x2D8CFD62, 0xC75A1688, 0x09219439, 0x9044D679, 0x4B8AC8B5, 0xAD4FD34D} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 493 ");
	}
	{
		static const fp2_t var_a =  { {0x61779C51, 0xA44FB001, 0x54883A80, 0xC78CC4D3, 0x2B7BEAA1, 0x4ED20B6A, 0x687A6742, 0x91AC6BD3},
	{0xD83FA519, 0x18D56C4F, 0xB78E6262, 0xA3FC9B0B, 0xAECCDDD0, 0x7A8AAA31, 0x4797F07A, 0x9510A7E3} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 494 ");
	}
	{
		static const fp2_t var_a =  { {0xF9FCA982, 0x3D176AFA, 0x7E8D4099, 0x72BCBDED, 0x8F3E60C0, 0xC17C1E23, 0x23033A4A, 0xB06A2B38},
	{0x89543EF5, 0x0EF2E986, 0xB3DA382F, 0x170C516E, 0xD53E23B4, 0x365572B9, 0x83C82BA0, 0x0D8836E2} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 495 ");
	}
	{
		static const fp2_t var_a =  { {0xBF678D8C, 0x0FA43DDE, 0xB14D0E3B, 0x5522C718, 0xE15FC32F, 0xC7B3A95C, 0x9FEB2E52, 0x73631A1D},
	{0x6943EB41, 0xCD2280F7, 0x2CB65CBE, 0xFAF81F4F, 0xCA3DD355, 0x1563BBE0, 0xD856835F, 0x6B23F330} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 496 ");
	}
	{
		static const fp2_t var_a =  { {0x94AFE800, 0xB8B9F61E, 0x5792A95D, 0x95D427AD, 0x36F293DE, 0x150B906C, 0x08CFD43F, 0xB751A553},
	{0x039158C0, 0x46E7D0F1, 0xEFD82E9C, 0xB25BE9BD, 0x5387CB6A, 0x666347F1, 0xE619EDE5, 0x59E4E72F} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 497 ");
	}
	{
		static const fp2_t var_a =  { {0x4168D068, 0xEB46540C, 0xE9A82B76, 0xEF0592F5, 0x8241A9F8, 0x6027D08E, 0x2B6F00B3, 0x59791B0E},
	{0x9D845C3E, 0xCF58A7F6, 0x4836E518, 0x989A7D16, 0x3B2AD2D5, 0xF43E71F1, 0xAF529396, 0x9C26D67A} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 498 ");
	}
	{
		static const fp2_t var_a =  { {0xC84A8401, 0x003D9CC3, 0x673AF953, 0xC5F64FBE, 0x2C45AD39, 0xBF19DBDF, 0xE508869A, 0x2B5104BF},
	{0x41ED64F4, 0x7CAAE2B3, 0xF6807C64, 0x67EEE761, 0xD98E51A1, 0x07254B4F, 0xF42718BB, 0x85B27478} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 499 ");
	}
	{
		static const fp2_t var_a =  { {0xF3B3B2DE, 0xFE320DBB, 0xD13B2D42, 0xF21DE0D9, 0x65BA2551, 0xA164DA26, 0x1F9A1180, 0x837FFBF1},
	{0x4F26E1B4, 0xB133F79C, 0x55BCA35F, 0x10DDA548, 0xEF8E2292, 0x74E41C7C, 0x9B671A07, 0x29154D09} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 500 ");
	}
	{
		static const fp2_t var_a =  { {0x4F56BB70, 0xC05E68E1, 0x3DE3DBEB, 0x14523005, 0xFD49390C, 0x60C36CDF, 0x6D8E4F4B, 0x9CEBF608},
	{0x1308BAA6, 0x05192193, 0xF50C9C2A, 0x8529976D, 0xAE98217A, 0x13401C86, 0xA63A84ED, 0x7C87E212} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 501 ");
	}
	{
		static const fp2_t var_a =  { {0x77A9E9E6, 0xB03AADB0, 0x01260487, 0x113D1CCF, 0x42946B0A, 0x4F44F8D6, 0xDCB94136, 0x5516592A},
	{0x72CACC5B, 0x528A7F84, 0x44F0C3E1, 0x2150560A, 0xCB4DACEA, 0xD97DAA01, 0x2CD47DF4, 0x1A3FEA4E} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 502 ");
	}
	{
		static const fp2_t var_a =  { {0x5A1C1355, 0x84240E84, 0xB4A86E8D, 0x321DA858, 0x53766D3A, 0x9D746B62, 0xF6EDBADC, 0x1937D83D},
	{0x2ED2633D, 0x5DF1C2F2, 0x3CF4A79F, 0x08F66D9B, 0x96EE1CDB, 0x40A25DEC, 0x4E192EC0, 0x3CFC7B2D} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 503 ");
	}
	{
		static const fp2_t var_a =  { {0x683DF24C, 0xE6F02D89, 0x3B0494DE, 0x424D5436, 0x78B553C6, 0xC0EFD20C, 0x8881912A, 0x3356E666},
	{0x1255B1E5, 0x35D1A72E, 0x4310B68B, 0x776B5B5F, 0x8A056937, 0xBBC615DB, 0x645E4024, 0x7041D406} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 504 ");
	}
	{
		static const fp2_t var_a =  { {0x9EF2A179, 0xB47CAAC1, 0xC11F8C3C, 0x44B509C9, 0x60F6EF9A, 0xFAF77527, 0xEFEEBCE3, 0x88DBD6B8},
	{0x613D3F44, 0x756C1C75, 0x04050619, 0x7AC8913D, 0x08C36963, 0x2C0F83D6, 0xBFF168D9, 0x0E60DB1B} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 505 ");
	}
	{
		static const fp2_t var_a =  { {0x14A5BB76, 0x6A5FA22A, 0x2815F85C, 0x6BB8F123, 0xBEBFD425, 0xCB1EDCE3, 0x5460C0DA, 0xB413615E},
	{0x58075CC1, 0x81A20833, 0x5C2DFDD7, 0x82614453, 0x9358A177, 0x03102F47, 0xEDA9DB43, 0x891069D5} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 506 ");
	}
	{
		static const fp2_t var_a =  { {0xBDB0A436, 0x19FA61FC, 0x6856F8ED, 0x184E7324, 0xE8217FE9, 0x7EE33586, 0x4D58FD6B, 0x5C472C33},
	{0x2B483AD0, 0x39210759, 0x3DF539CE, 0x255160D2, 0xD45CFFC1, 0xEE227BBD, 0xF6E90786, 0xA81FAD7F} } ;
		static const fp2_t var_expected =  { {0x7823EB0B, 0x580501AD, 0xF336CCD9, 0x7C7E07B3, 0x83529F22, 0xF206B1EF, 0x6AB6651A, 0x496E35FE},
	{0x1AC75DAD, 0xEAEEA151, 0x35294238, 0xA2885C86, 0xA2637A17, 0x6220276F, 0xF99917B3, 0x93F64401} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 507 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 508 a1");
	}
	{
		static const fp2_t var_a =  { {0xFB7B7AC5, 0x37A7962F, 0x43964FAB, 0x8489D0DD, 0xDDB1B977, 0x306EE99F, 0xF8837C1D, 0x6C90BD07},
	{0x5B52C445, 0x6F1C8DDE, 0xCF22F779, 0x34BB6AF2, 0x1C72747E, 0x7213B9DE, 0x78C60202, 0xB6A160E1} } ;
		static const fp2_t var_expected =  { {0x02B8710B, 0x870A833D, 0xAA1424E2, 0x06330840, 0xEDD86F61, 0x06410C1D, 0x9366C047, 0x318E73B2},
	{0x245D438A, 0x6AACA02B, 0xD7DF71BD, 0xDEFB607A, 0xB86E90FB, 0x3AC0FF12, 0xD5037DD2, 0x41AB3894} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 509 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 510 a1");
	}
	{
		static const fp2_t var_a =  { {0xE3E5A44B, 0xA6E38B86, 0xE2306C68, 0xF65CD2CB, 0xF67A11E7, 0xDD79101F, 0xD493B520, 0x90E07757},
	{0x950F5083, 0x25B74892, 0x596F9E11, 0xCEA64384, 0x9C128C38, 0xD338CD9F, 0x460B7EC6, 0x402F5075} } ;
		static const fp2_t var_expected =  { {0x9B3F8DAE, 0xBCB08869, 0xB7427CAC, 0x5E302E07, 0xFA4109C9, 0x6D8FF544, 0x6A00A668, 0x6524A601},
	{0x5079B5C7, 0xBD4BF377, 0x7D9E36B5, 0xEA27365F, 0x7CB56C44, 0xF947C70F, 0xF942F822, 0x0DEDEAF3} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 511 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 512 a1");
	}
	{
		static const fp2_t var_a =  { {0x550A5A9E, 0xBE136E50, 0xB22F660F, 0xFEED62EA, 0x6078B2E3, 0x390AFBB6, 0x7472EFA5, 0x0A9D9E75},
	{0x1D392A00, 0xF8C5D461, 0x1C620923, 0xC3FF7B45, 0x7BF006A9, 0xCB0A2004, 0x3E1A73AC, 0x5C52C839} } ;
		static const fp2_t var_expected =  { {0xE1819C50, 0xF54DBBDF, 0x86337F98, 0xF43A7791, 0xAC35E14C, 0xDA19BB6B, 0x21D2C254, 0x086CA915},
	{0x155F8AB8, 0x909D68EF, 0x0C8B618B, 0xB11FC4DD, 0x58028D15, 0xD981AA23, 0x50012872, 0x57D77527} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 513 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 514 a1");
	}
	{
		static const fp2_t var_a =  { {0x4EC8ACF0, 0x81E3B8B9, 0xE7B32E45, 0xEC5B3FB0, 0x5FD104B8, 0x35EEE525, 0x099D7D54, 0x609B1DDA},
	{0x516FC472, 0xB054972D, 0x2157F666, 0x4F6416DA, 0x525062B4, 0x748B63D7, 0x4153A0D6, 0x6AF6E3A3} } ;
		static const fp2_t var_expected =  { {0xC0123695, 0x226374C6, 0x8428FA88, 0x3DAEAFD3, 0x99740C99, 0x9CEB8637, 0xD0DC9233, 0xA05A0C5D},
	{0x5B27E5FE, 0x7167759C, 0xB34C834B, 0xC347FB60, 0x2541BF4A, 0x6E806CF3, 0x5ABE26A2, 0x884970C4} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 515 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 516 a1");
	}
	{
		static const fp2_t var_a =  { {0x1066B197, 0x458DACFA, 0xDC8C7981, 0xB22813AC, 0x981A7ED1, 0xD53F3E10, 0x9EAD7A41, 0x7C8F346D},
	{0x011BF0B7, 0x61030840, 0xC1D3D58D, 0x62EEBDE3, 0x63000ADF, 0x4EF0A098, 0x0C795FEA, 0x4512E1CF} } ;
		static const fp2_t var_expected =  { {0x84C6CAB5, 0xD422047D, 0x79F0258F, 0x0A7A7765, 0xDE9163C8, 0x64D4A988, 0x769CA556, 0x76B3F87E},
	{0x25CB3718, 0x209BE14E, 0x6408332E, 0xD0AC3118, 0x5E643383, 0x86F338B1, 0x9062A23C, 0x80FA6C18} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 517 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 518 a1");
	}
	{
		static const fp2_t var_a =  { {0x31881F78, 0xF0A6AE9C, 0x20B3565D, 0x31A6C506, 0x957E1BDF, 0xC5E8695F, 0x7D3D663B, 0x1DCBD167},
	{0xB97E6140, 0x9EA40599, 0x3EF4A700, 0xB969C472, 0xF9BD26E2, 0xEE2540D3, 0xB4EDFF03, 0x1C064266} } ;
		static const fp2_t var_expected =  { {0xCAF581FE, 0x53B5A9EC, 0x59E18D37, 0x888105F1, 0x10F66846, 0xD57C5A17, 0x84170FB3, 0x12B0A907},
	{0x51796EE2, 0x717C364D, 0x28421EAC, 0x0109BD3A, 0x81CBC1B9, 0x5932D5AD, 0x272D7C1C, 0xB68A6722} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 519 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 520 a1");
	}
	{
		static const fp2_t var_a =  { {0x7F1747EE, 0x8E68C416, 0x831C5EE6, 0xD9420D12, 0x71B64D70, 0x04963ECD, 0x8F966572, 0x712FF238},
	{0x79D7AF00, 0xCFAB746E, 0xC3DCF0B8, 0x97538192, 0x52AF6FC7, 0xB6C2CFBB, 0x73B0C8A2, 0x276A1C80} } ;
		static const fp2_t var_expected =  { {0xBA362D0E, 0x943151F9, 0x3D173C36, 0xD1B92C8C, 0xD3267DD4, 0xCA3A374E, 0xA1758DA9, 0x7F49F1CB},
	{0xD0F62648, 0xA2DB0D9D, 0x3F81FB18, 0xC3626164, 0x1088A2DE, 0xAC4CBAE4, 0xDF3ED694, 0x5AABE9BD} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 521 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 522 a1");
	}
	{
		static const fp2_t var_a =  { {0x2F0A8688, 0x8ADEE65F, 0xB9EDB0C1, 0x301355FF, 0x6AA7F4DC, 0x35D83ECC, 0x59254F71, 0x976B5D09},
	{0x4A27C983, 0x3FE0905A, 0x84A1BD3F, 0xD7119FB3, 0xBBB26171, 0xBDB9F71E, 0x5A834B0C, 0x5A52EAF1} } ;
		static const fp2_t var_expected =  { {0x3261AA7D, 0x2D97B79B, 0xE8F444DF, 0xCFC9199E, 0xF9AE2B57, 0x76AE445B, 0x11C3B1F3, 0xB27E0849},
	{0x3B7FC26A, 0x6A87B738, 0xD2332D06, 0x66609FBE, 0x341707FD, 0x2D99A331, 0x6D4B0014, 0x4E425E2E} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 523 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 524 a1");
	}
	{
		static const fp2_t var_a =  { {0x5E832E64, 0x0920673D, 0xE660E2FC, 0x8658896A, 0xAF811EDC, 0xB99418EB, 0xABC83100, 0xAD7F77E9},
	{0x27AC1972, 0x4E21B84F, 0xBC297B99, 0xFF690CF2, 0x18AA418D, 0xBE41E234, 0x3F61D979, 0x5970E2FF} } ;
		static const fp2_t var_expected =  { {0xE7272C86, 0xC84BE98E, 0xC9A6C40A, 0x44C76BE9, 0xF8DD554A, 0xE35FAB16, 0x418D9F32, 0xAB977DE3},
	{0x598B29A5, 0xCDA91CC5, 0x577E6166, 0x44F3FA64, 0x9ABB828B, 0xAE612A70, 0xE9A02AEE, 0x4612832D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 525 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 526 a1");
	}
	{
		static const fp2_t var_a =  { {0xDC69A4FC, 0xEA73A95D, 0x929DFC8D, 0xAB7A31BB, 0xE09171F4, 0x5003E58B, 0x7D8E719A, 0x17305F49},
	{0x58508FCF, 0x70B07B85, 0x604E5528, 0x596BB92D, 0xA15D4C74, 0x884F8140, 0xA7DDEA0A, 0x7F8FEAEF} } ;
		static const fp2_t var_expected =  { {0x28106F34, 0x60785878, 0xF65CDFBC, 0x1F32903C, 0x11469AB8, 0x52496335, 0x030C6D58, 0xAEBC1AE3},
	{0xB66C24F4, 0x5A158CE9, 0xBCDA0611, 0x1E89AF8C, 0x680111F4, 0xE9A6CDCF, 0x2A5BEC4E, 0x4E1B1EB3} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 527 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 528 a1");
	}
	{
		static const fp2_t var_a =  { {0x53C99256, 0x64426BFC, 0x0C437B49, 0x593432D8, 0x8C3DFAF8, 0xAAD5CE1A, 0x690C0603, 0x5EB01C9F},
	{0x89DE02D6, 0x6DF32F44, 0x947D6D7C, 0xAE62A6F8, 0xFC4DCBE6, 0x0900B21B, 0x9BCADE94, 0x32A26FA4} } ;
		static const fp2_t var_expected =  { {0xAEBEC1D6, 0x5A81A3F2, 0x755C1652, 0x04FB9AA9, 0x94035ED4, 0xDCA5C05E, 0xB4BD5536, 0xA36914DB},
	{0x96ED04E4, 0xAE0BF25B, 0x617A3299, 0x89F68C18, 0xA8FB6BC1, 0x6216093A, 0x83F0E830, 0xA4A3AF46} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 529 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 530 a1");
	}
	{
		static const fp2_t var_a =  { {0xD340477F, 0x2D072E1E, 0xC45293DD, 0xB0F3CFF8, 0xB554AF52, 0xFDC934DC, 0xAA7B8AF7, 0x7591A33E},
	{0x1FACE452, 0xB1D05C08, 0xADED3047, 0xA3893A7D, 0x0C38910D, 0x2DA32DA3, 0x9089BE5F, 0x625FC99F} } ;
		static const fp2_t var_expected =  { {0x87873CFA, 0x644E06F4, 0xA7E175EB, 0x0B8CA2BF, 0x35BCEE3D, 0xB812D10D, 0x99BBC188, 0x459B8252},
	{0x08E3BC28, 0x293ACE69, 0x774E8669, 0x158F0140, 0x53B33E25, 0x2FE37097, 0x071B89B5, 0x5F94AEE9} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 531 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 532 a1");
	}
	{
		static const fp2_t var_a =  { {0x30DE5218, 0xF822424B, 0x2FF75423, 0xA878468F, 0x8CDBD974, 0xBC614E0B, 0x82F7D2A3, 0x0E281DB8},
	{0x6E3B32C0, 0xAD966639, 0x856EFB5F, 0xCA9EB33A, 0x17949F23, 0xBE136457, 0x4A58600E, 0x3CF96D06} } ;
		static const fp2_t var_expected =  { {0x3EA8670D, 0x78B012B1, 0xA63D2512, 0xACAACA05, 0x0A93CB50, 0x52490468, 0xAE329745, 0x9158699C},
	{0x83A9F986, 0xEEF476D5, 0x71B9A48D, 0x3B4E05E0, 0x54EC7BD2, 0x48F80523, 0xAE04FB7A, 0x25E38C61} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 533 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 534 a1");
	}
	{
		static const fp2_t var_a =  { {0x71921369, 0xA40EB07A, 0xD4CEF7AB, 0x5BCAC4B2, 0x295952B6, 0x1FB58765, 0xFF8EF48A, 0x070FE41D},
	{0x5FC29B5A, 0x081D7505, 0xCC0CC500, 0xEF8FD4C7, 0x52402A2F, 0x6AC30291, 0xD518299D, 0x95941B08} } ;
		static const fp2_t var_expected =  { {0x1E08A5C4, 0x093A7381, 0x56220177, 0xA436B63F, 0x7157E328, 0xB5D1E0F0, 0x74CED18F, 0x5BC5AAFF},
	{0x8F995549, 0xAD713A1A, 0x11D0ED46, 0x91DBC930, 0x95514F44, 0x9EC94A29, 0xB172A5FA, 0x6A39C597} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 535 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 536 a1");
	}
	{
		static const fp2_t var_a =  { {0x99CB829D, 0x3FC9A58E, 0x61150459, 0xC82736D0, 0xF70C5800, 0x02AC5C21, 0x843C3A01, 0x2B9A73DA},
	{0x87D171CE, 0x9FE57B17, 0xDC9D375A, 0xD8287921, 0x679D315A, 0xA1BD315E, 0x0BE2435F, 0x1D7EF8DB} } ;
		static const fp2_t var_expected =  { {0x28D421F7, 0x77CB75D2, 0x176A71F6, 0xD3265FB2, 0x50E9056C, 0x425E90BD, 0x1917B99B, 0x13D958D0},
	{0x7F61CB7B, 0x5B7F0AE7, 0x9616F306, 0xD0AE7551, 0xCB0AFADC, 0x41AB59D6, 0x63B541A9, 0x2FEEFAFE} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 537 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 538 a1");
	}
#else

	{
		static const fp2_t var_a =  { {0xADA13AD9, 0xB78731BE, 0xE7D55EBA, 0xCDA4B1B8, 0x38E7D29E, 0xC1AEC3AF, 0x36A44ED5, 0x31A875E6},
	{0x476723AC, 0x6C63614D, 0x8AFFA6E8, 0x4099278E, 0x137D927B, 0x719A26EA, 0x9B83CCE4, 0x4B88FC2B} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 1 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 2 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 3 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 4 a1");
	}
	{
		static const fp2_t var_a =  { {0x839304A7, 0x9A79A409, 0x769BCF2F, 0xEF854FF5, 0x006EC4EC, 0x48BE8285, 0xE0C86D83, 0x40849B34},
	{0xE886B3AA, 0x7DAAE5A0, 0xE6FF197D, 0x962F501F, 0x83A46503, 0x03577319, 0x8A859474, 0x09B42AFD} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 5 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 6 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 7 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 8 a1");
	}
	{
		static const fp2_t var_a =  { {0xDC8BCBB0, 0x255815BC, 0xE4E5E79E, 0x95B7DA0D, 0xD130BBA8, 0xF81AEC8A, 0x40E4B528, 0x5DC6BF2C},
	{0x29BA198C, 0xF60C2F9E, 0xC99937A3, 0x6C3EDEF3, 0x50E5C075, 0x9578F9D9, 0x5051BB51, 0x287B8472} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 9 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 10 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 11 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 12 a1");
	}
	{
		static const fp2_t var_a =  { {0x63C9FA47, 0x2218B5AC, 0xE7127D6D, 0x99B07E5E, 0xB873D0D0, 0xCA09CE49, 0x68CF7C82, 0xB7550DD1},
	{0x362D40BA, 0x3D99B66E, 0xE01DBA98, 0x4B4286E4, 0xFB6603A5, 0xBB484DDF, 0x5CE84836, 0x31D3ED4E} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 13 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 14 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 15 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 16 a1");
	}
	{
		static const fp2_t var_a =  { {0xA1C38739, 0xA10DDE6C, 0xA142BEED, 0xFD906008, 0xAE370165, 0xFB677FD0, 0x675AD2C9, 0x038CADD9},
	{0xB95FD673, 0x043B331F, 0x6A2F715E, 0xD976AD01, 0x9EEA6182, 0x532CDBD8, 0xE3ABF3F0, 0x78B79B60} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 17 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 18 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 19 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 20 a1");
	}
	{
		static const fp2_t var_a =  { {0x5FE6C804, 0xEDA90B8F, 0x72DFD64A, 0x08847122, 0xECAD602F, 0x09DC6C90, 0x907B0E43, 0x369AD7E1},
	{0xD6B49404, 0x3881FB0F, 0x3FD44C8D, 0xD526E9E4, 0xE96E111E, 0x827D62B9, 0xD26C0E8A, 0x1F793EAC} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 21 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 22 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 23 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 24 a1");
	}
	{
		static const fp2_t var_a =  { {0xA5219BE2, 0x944B5C72, 0xFBAD9565, 0x3F1088DD, 0xEAC70453, 0xB1A51D80, 0x735F27F5, 0x86D8F4CF},
	{0x19E18DDD, 0x041E9E4E, 0xF5DB383D, 0x775653C4, 0xC91CE761, 0xA036974E, 0x1D18D375, 0xB5767BBF} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 25 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 26 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 27 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 28 a1");
	}
	{
		static const fp2_t var_a =  { {0xBE790B21, 0x620E2732, 0x1EDDF768, 0x66676D21, 0x62C736AF, 0xEE6D0C08, 0xE178AB22, 0x671679CF},
	{0xEAC8A519, 0xD7F93AD3, 0x8D107BBE, 0x25CB3D03, 0x1754E3FC, 0x4C43CFCE, 0xB3492329, 0x4E1903C9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 29 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 30 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 31 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 32 a1");
	}
	{
		static const fp2_t var_a =  { {0x329784FC, 0x659BA5E6, 0xFB1598D7, 0x82B6DEC7, 0x4DCEE7AF, 0xFF165417, 0xEB905F35, 0x8EEA6EB1},
	{0xF33C1634, 0x5DF2200F, 0x48BED3E6, 0x826DBACE, 0xED1C322D, 0x61B0D654, 0xC57BB31D, 0x4039F681} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 33 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 34 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 35 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 36 a1");
	}
	{
		static const fp2_t var_a =  { {0x682A4BC4, 0xEB0A27F2, 0x201321CC, 0xC663D63A, 0x908BDFAF, 0x652BD492, 0xA2B7A3E4, 0x35EF1A06},
	{0x1C8AC2D6, 0x83AA75B7, 0xA7C3226A, 0x7499EA06, 0xA3B7651F, 0xFE7BBAFA, 0xC5167F61, 0x206EE013} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 37 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 38 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 39 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 40 a1");
	}
	{
		static const fp2_t var_a =  { {0x2D2D8896, 0x7D6C0F31, 0xD4950856, 0xDDA724D7, 0x4B58E140, 0xD431F779, 0x17D1CEBC, 0x096062D5},
	{0x2CDD5A89, 0x776BE818, 0x9629919F, 0x0D5D15B9, 0x7E49EC1C, 0x83058B11, 0x24628402, 0x084B47EF} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 41 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 42 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 43 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 44 a1");
	}
	{
		static const fp2_t var_a =  { {0xCA94F81F, 0xEAF0FC43, 0xFC0F3E9A, 0x8A7EF54A, 0x385736D3, 0x48980D0D, 0x1C09623C, 0x7B0C6CDF},
	{0xB4B0BC88, 0xA39F2E55, 0x948A5B44, 0xEA1D401B, 0x53DD7EF2, 0x7FBD9C22, 0x9330CD05, 0x3D11281A} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 45 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 46 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 47 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 48 a1");
	}
	{
		static const fp2_t var_a =  { {0xA2B5F56A, 0x42CC4C24, 0x38505DFD, 0x9BEEEC05, 0x5421B280, 0x0D23EDB8, 0x00C4644B, 0x138A4A31},
	{0xD37513B9, 0xB95D852A, 0x8FFD0905, 0x662C6AEA, 0xEC2FC5C3, 0xE2D5577C, 0x4298D937, 0x2926B8B2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 49 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 50 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 51 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 52 a1");
	}
	{
		static const fp2_t var_a =  { {0x068F4A5E, 0xCE517851, 0x3D31426B, 0xA104AACA, 0x2837D4C3, 0x8D86624D, 0x16E7CA1B, 0xAE534852},
	{0xFBB84FB2, 0xA039AF4F, 0x5C26B895, 0xB118D0AF, 0xF18CAAE3, 0xB7B1B72B, 0xA2D7899B, 0x4C908142} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 53 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 54 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 55 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 56 a1");
	}
	{
		static const fp2_t var_a =  { {0xD9ED9071, 0x1DC0BBE9, 0x2D229329, 0xE72A1CD7, 0x30224F85, 0x93E9BED0, 0x2E33E20D, 0x530001E6},
	{0x2E2276BC, 0x8A137AFE, 0x3E4AA024, 0xB7F85AE9, 0xFF165D6C, 0x69155A4E, 0xA69060D8, 0x4B150F59} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 57 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 58 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 59 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 60 a1");
	}
	{
		static const fp2_t var_a =  { {0xC6E44312, 0xFC4A2EB9, 0xBF5B0F5C, 0x463F8C65, 0x7AC94467, 0x17E05269, 0x59ACE1DB, 0x326DA583},
	{0xD5B71E1D, 0xE23E3848, 0x3504C924, 0xDD6B6B34, 0xEF2F82D9, 0x93B5D3AD, 0x3D116800, 0x3C595550} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 61 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 62 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 63 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 64 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 65 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 66 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 67 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 68 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 69 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 70 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 71 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 72 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 73 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 74 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_b =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 75 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 76 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 77 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 78 a1");
	}
	{
		static const fp2_t var_a =  { {0xF551CE8F, 0x7956D628, 0x4021DC53, 0xAF773A46, 0xABADA048, 0x5AF68C45, 0x67EE7F09, 0x449672B1},
	{0xC06EDFC6, 0x544D74C9, 0xFF596B7E, 0x00EB4F41, 0xD708CDAE, 0x070CCCD0, 0x5863A2E8, 0xA2291937} } ;
		static const fp2_t var_b =  { {0x53799B70, 0xDDDF3CAC, 0x8B9F35B3, 0xA119FB31, 0xF8CC264D, 0xCEC14033, 0x6DF87829, 0xAE614B1D},
	{0x5007B6F3, 0xCF92DEB4, 0xCC1CFC5A, 0xBB637B95, 0xBF5AF723, 0xF35CCAD3, 0x6A250424, 0x29095381} } ;
		static const fp2_t var_expected =  { {0xE69F3564, 0x58478923, 0xF74932C0, 0x3D7F88D6, 0x50973CE1, 0x2E57700E, 0x95C81B0A, 0x38E41F0C},
	{0xAE4A621E, 0x24F1C9CC, 0xF6FE8892, 0xA93D1E36, 0x42813B1C, 0xFF093B39, 0x8269CAE3, 0x111ECDF6} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 79 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 80 a1");
	}
	{
		static const fp2_t var_a =  { {0xC4D858FB, 0xB8F785E8, 0xC84E0BE6, 0x671F07D3, 0xDE5137C4, 0x3BF1090C, 0x370405B2, 0x76201633},
	{0x342D93AB, 0x7EEC33E4, 0xAFFE6C97, 0x7D970259, 0x9039EFBD, 0xA135632D, 0x226A128F, 0x90A74F16} } ;
		static const fp2_t var_b =  { {0x9147AEF1, 0xD8F8C5C9, 0xD5391620, 0xC6208583, 0x1521FEF5, 0xA07C49C0, 0x99AF3567, 0x12999D1F},
	{0x5046894C, 0xD1A61398, 0x5825C1FD, 0x614AA78E, 0xD47F25CF, 0xC12D7A9E, 0x71DEFBF7, 0x00F5C15E} } ;
		static const fp2_t var_expected =  { {0x562007EC, 0x91F04BB2, 0x9D872207, 0x2D3F8D57, 0xF37336BA, 0xDC6D52CC, 0xD0B33B19, 0x88B9B352},
	{0x84741CF7, 0x5092477C, 0x08242E95, 0xDEE1A9E8, 0x64B9158C, 0x6262DDCC, 0x94490E87, 0x919D1074} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 81 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 82 a1");
	}
	{
		static const fp2_t var_a =  { {0x69869BCE, 0x4758A041, 0x5109F8E7, 0xFDA7FF30, 0x93691CB1, 0x2A75CC9F, 0x630C4994, 0x635788E7},
	{0x719B63F4, 0x724917A5, 0x83401B50, 0x43A34664, 0x9F9C3E57, 0x22622153, 0x49A483BC, 0x029F46E3} } ;
		static const fp2_t var_b =  { {0xEF3F7BDC, 0x540E1B31, 0x20E7621B, 0x17DEB3DE, 0x9536B771, 0x6575F27C, 0x2697DD04, 0x32427BA7},
	{0x812C2061, 0x4E160761, 0xB3E64DCC, 0x0AC2D581, 0x4A561FAF, 0xE27FA9DF, 0x1B2F825B, 0x2691A1B2} } ;
		static const fp2_t var_expected =  { {0x58C617AA, 0x9B66BB73, 0x71F15B02, 0x1586B30E, 0x289FD423, 0x8FEBBF1C, 0x89A42698, 0x959A048E},
	{0xF2C78455, 0xC05F1F06, 0x3726691C, 0x4E661BE6, 0xE9F25E06, 0x04E1CB32, 0x64D40618, 0x2930E895} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 83 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 84 a1");
	}
	{
		static const fp2_t var_a =  { {0x8E547CCC, 0x8CBCC372, 0xB832BB90, 0xAD8FADF7, 0xE7E006FA, 0x09319845, 0xB37F2167, 0x6DBAAA7F},
	{0x82406E49, 0x95DA05CF, 0x2AAE9F24, 0xA019957F, 0x72501AF6, 0x6B94BB68, 0xD85336F6, 0x154F52FC} } ;
		static const fp2_t var_b =  { {0x908C811A, 0xBCD2D380, 0xF93E854A, 0x8322B3FF, 0x442E16BB, 0x14655DEC, 0xDB1CC01A, 0x8983DC08},
	{0x0385189B, 0xB11C2AED, 0x696EB96A, 0xA558CD83, 0xED95BC0B, 0x4C41F61D, 0x306D6E22, 0x11F1037C} } ;
		static const fp2_t var_expected =  { {0xBCB4C94B, 0x4AA10D41, 0xDCF96194, 0x1DA0B556, 0xD82B9401, 0x223699C6, 0x4E7D0558, 0x3D2AE7C6},
	{0x85C586E4, 0x46F630BC, 0x941D588F, 0x45726302, 0x5FE5D702, 0xB7D6B186, 0x08C0A518, 0x27405679} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 85 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 86 a1");
	}
	{
		static const fp2_t var_a =  { {0x7C54C421, 0xF04DA45F, 0x05D9F3E2, 0x9FF733F6, 0xA3C40076, 0xC207EFCD, 0xAF1B9C77, 0x3B28D209},
	{0xAE0EBF89, 0x4F8EF835, 0xAE145731, 0xBC1BD5CC, 0xD332A6A1, 0x612766DB, 0x555C5290, 0x71C3F579} } ;
		static const fp2_t var_b =  { {0x1C4DC60C, 0x7588AB65, 0x3C587B39, 0x45BB7D6B, 0x3EBAEBFE, 0x9118C83F, 0x818F515F, 0x794AC936},
	{0xA81596F0, 0x5ECAD5CD, 0xD33402DB, 0xA54E4DB1, 0xD5A6984E, 0xD316EDC2, 0x37AEFD0C, 0x54AADE88} } ;
		static const fp2_t var_expected =  { {0x98A28A2D, 0x65D64FC4, 0x42326F1C, 0xE5B2B161, 0xE27EEC74, 0x5320B80C, 0x30AAEDD7, 0xB4739B40},
	{0xF3F821DE, 0xAF6B4451, 0xACD07AC5, 0x4E5876DD, 0x54F6B53B, 0x38DDF833, 0x4CEC7374, 0x0C5B353F} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 87 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 88 a1");
	}
	{
		static const fp2_t var_a =  { {0x79DBC6E4, 0xD9098F3E, 0x3FAE48EB, 0xFBB4E58D, 0x8D2542EF, 0x3D70C690, 0xE0015C73, 0x77F3AF11},
	{0x7B630C2D, 0x0BCB3380, 0x6D6BBDC6, 0x98D685B3, 0xE0E05C77, 0xF8C36EEA, 0xC84C9F3D, 0x4AD46C42} } ;
		static const fp2_t var_b =  { {0xDCB8BCA9, 0xE9564916, 0xF0769C17, 0x8517E613, 0x4BAD35A0, 0xC3909398, 0x9F82E060, 0xAAE30C80},
	{0x91319199, 0xC1017A15, 0x7D8F3263, 0xFA9940F0, 0xCE45A371, 0x6E131253, 0xF9100691, 0x67BB706A} } ;
		static const fp2_t var_expected =  { {0xF4684EF2, 0xC3714EA3, 0x5BAD05BC, 0x6DBB1F00, 0x84EFEEDB, 0x05A0FDBD, 0x3F6560AB, 0x68C31CD0},
	{0x0C949DC6, 0xCCCCAD96, 0xEAFAF029, 0x936FC6A3, 0xAF25FFE9, 0x66D6813E, 0xC15CA5CF, 0xB28FDCAD} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 89 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 90 a1");
	}
	{
		static const fp2_t var_a =  { {0x6D569F00, 0xB3D2D968, 0x9A902AEA, 0xD53E8287, 0x1B35F951, 0x651584C7, 0x8E983FCA, 0x0DCEFD29},
	{0x92E5686E, 0x2E153384, 0x443AA3E9, 0x71E2497E, 0xB7225372, 0x124BA40C, 0xFAF19C74, 0x0189518B} } ;
		static const fp2_t var_b =  { {0xB71F3884, 0x804ABB05, 0x490BBB95, 0x5749011B, 0xDFFBF093, 0x97021ED7, 0x7ECE97B4, 0x08FBFF40},
	{0x67A150EE, 0x40B144E1, 0x42D75D38, 0xE0ACD7FE, 0xF43C1506, 0x01E2F33C, 0x3D15AFE8, 0xAD651732} } ;
		static const fp2_t var_expected =  { {0x2475D784, 0x341D946E, 0xE39BE680, 0x2C8783A2, 0xFB31E9E5, 0xFC17A39E, 0x0D66D77E, 0x16CAFC6A},
	{0xFA86B95C, 0x6EC67865, 0x87120121, 0x528F217C, 0xAB5E6879, 0x142E9749, 0x38074C5C, 0xAEEE68BE} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 91 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 92 a1");
	}
	{
		static const fp2_t var_a =  { {0x61FB7449, 0xE12C05A2, 0xC869F3D8, 0x7CF6D548, 0xBBD3C372, 0x1A55CDB4, 0xC0085345, 0x1A1D3FA9},
	{0x3BD32543, 0x2357BB0D, 0x3AB49674, 0x6DF95C44, 0x1E62A201, 0x98507FF3, 0x73DECFED, 0x40C9A981} } ;
		static const fp2_t var_b =  { {0x1AC3673B, 0xA0FF9C53, 0xCC08A45E, 0x1D5BED3C, 0xBE279D94, 0xE7B66F7D, 0x652CCD9A, 0x6E03690A},
	{0x12995C78, 0x443EA0FE, 0x5699C5CD, 0x6A0A24F3, 0xBC164BAD, 0x78801B1A, 0x4CE08A33, 0x14B6A290} } ;
		static const fp2_t var_expected =  { {0x7CBEDB84, 0x822BA1F5, 0x94729837, 0x9A52C285, 0x79FB6106, 0x020C3D32, 0x253520E0, 0x8820A8B4},
	{0x4E6C81BB, 0x67965C0B, 0x914E5C41, 0xD8038137, 0xDA78EDAE, 0x10D09B0D, 0xC0BF5A21, 0x55804C11} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 93 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 94 a1");
	}
	{
		static const fp2_t var_a =  { {0xA2EBE2BC, 0xCD8E04B5, 0xCFD72FEA, 0x19CD3821, 0x371B500D, 0x44650E3B, 0xFF9C0517, 0x468CF990},
	{0xBE2EB91A, 0x4FCF9E3F, 0x5730A433, 0xB4096B4C, 0xDF8C84DB, 0x717C1876, 0xBA8860F7, 0xAD701052} } ;
		static const fp2_t var_b =  { {0x2624B5B3, 0xB34C389A, 0x05388621, 0xC6A482BD, 0xB468AB92, 0xA94A6FAD, 0x1DFE6967, 0x5167199D},
	{0xFFC1EF4A, 0x331E2942, 0x3F66784F, 0xF9ADD0E5, 0xE76616FF, 0xAD805013, 0x6DF800CB, 0x720019DC} } ;
		static const fp2_t var_expected =  { {0xC910986F, 0x80DA3D4F, 0xD50FB60C, 0xE071BADE, 0xEB83FB9F, 0xEDAF7DE8, 0x1D9A6E7E, 0x97F4132E},
	{0x5BC473C9, 0x83FF3DD1, 0xC21F3D3B, 0x9AA58F90, 0x73101226, 0x239C0C1F, 0xE861859A, 0x655C8B6C} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 95 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 96 a1");
	}
	{
		static const fp2_t var_a =  { {0x4E074050, 0xE17BAEC9, 0x3BB5581E, 0x9931E055, 0x5A8624A5, 0xD7E977D5, 0x12ACCEF7, 0x0A0456C9},
	{0x00923AA9, 0x1D226E37, 0xCFB1598B, 0x5D240E0B, 0x6D325C96, 0x8A2A65FB, 0x182D00FF, 0x373AA0B8} } ;
		static const fp2_t var_b =  { {0x87B5C9D0, 0x209858E0, 0xCFE4CE5E, 0x8D767674, 0xDD83B390, 0xC06E6193, 0x6E8686C4, 0x1558E4B2},
	{0x507F1529, 0x778004BA, 0x8723F907, 0x7E6009A0, 0x45FD6289, 0x96481715, 0x690CF7D1, 0x40108A47} } ;
		static const fp2_t var_expected =  { {0xD5BD0A20, 0x021407A9, 0x0B9A267D, 0x26A856CA, 0x3809D836, 0x9857D969, 0x813355BC, 0x1F5D3B7B},
	{0x51114FD2, 0x94A272F1, 0x56D55292, 0xDB8417AC, 0xB32FBF1F, 0x20727D10, 0x8139F8D1, 0x774B2AFF} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 97 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 98 a1");
	}
	{
		static const fp2_t var_a =  { {0xD37CDB70, 0x82E19037, 0x924F5516, 0x5DB3C631, 0xE8E0CB0A, 0xB15E9CF6, 0x42A871C4, 0x3D560807},
	{0x710C1F16, 0xF1FF5EFF, 0x293F0162, 0xC8D25448, 0x8CEFF733, 0xBC4AA43D, 0xD464FC1F, 0xB42799A7} } ;
		static const fp2_t var_b =  { {0x840277F8, 0x502D18E9, 0x3387EEC6, 0x9AC3685D, 0x026094BC, 0x1408F0EB, 0xDF4C1FB9, 0x6166529C},
	{0x4D7DBB31, 0x79B6735E, 0x37427BE1, 0x1F523AE6, 0x9BD02C3A, 0x1B720A25, 0xC80DD015, 0x27E3B045} } ;
		static const fp2_t var_expected =  { {0x577F5368, 0xD30EA921, 0xC5D743DC, 0xF8772E8E, 0xEB415FC6, 0xC5678DE1, 0x21F4917D, 0x9EBC5AA4},
	{0x5C5DA5AC, 0x6CC748AC, 0x8C099DFD, 0xD512E28D, 0xD4DD99B8, 0xDC5C51F7, 0x5C53F00B, 0x21F7AB2B} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 99 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 100 a1");
	}
	{
		static const fp2_t var_a =  { {0x7B39A3B5, 0x19B50CEB, 0xD93047E3, 0x8F5F8F06, 0xA9534931, 0xB6B28B95, 0x160BB9A5, 0x888DFB59},
	{0x3367D753, 0x37D92CBE, 0xED33D2FA, 0xE36B33A9, 0x0897C13A, 0xFFA05218, 0xB7F75DC6, 0x9DB2B3A2} } ;
		static const fp2_t var_b =  { {0x03AEA8FE, 0xAA3D5A40, 0x64C37B34, 0x02224DCD, 0x9605455F, 0x932F049E, 0xB91E1724, 0x25826A53},
	{0x0285A9FC, 0x9D4004C7, 0xFE466A7B, 0x2B090D8F, 0x5A20FF23, 0x1A6B980B, 0x910CD21F, 0x43955EAD} } ;
		static const fp2_t var_expected =  { {0x7EE84CB3, 0xC3F2672B, 0x3DF3C317, 0x9181DCD4, 0x3F588E90, 0x49E19034, 0xCF29D0CA, 0xAE1065AC},
	{0xD3C14CB4, 0xD62AA7D3, 0x17025E2E, 0xFB629499, 0x0ED636A8, 0x1EAB8DB8, 0x08E553BD, 0x2734738E} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 101 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 102 a1");
	}
	{
		static const fp2_t var_a =  { {0xC915BF50, 0x0FE2E32B, 0x72970214, 0x2FD31A31, 0xBD46FEB5, 0xDAA88012, 0x9773DEB9, 0x1D01454A},
	{0xEEE09558, 0x552AACEA, 0xF9EE83F3, 0xEABE6637, 0xFD08B3AE, 0x35856A8E, 0x880A4EA0, 0x569BE1C7} } ;
		static const fp2_t var_b =  { {0x725060FA, 0x9686F183, 0xE7C0ADC1, 0x252036CD, 0x5C0A5D2A, 0x161273E1, 0x43A68532, 0x35629783},
	{0xB8CAE8E6, 0x4D17222A, 0xE4EA4344, 0xCB1D5E52, 0x4BEFE40C, 0x7CF5ABD6, 0x4DC4F714, 0x3C09085D} } ;
		static const fp2_t var_expected =  { {0x3B66204A, 0xA669D4AF, 0x5A57AFD5, 0x54F350FF, 0x19515BDF, 0xF0BAF3F4, 0xDB1A63EB, 0x5263DCCD},
	{0xA7AB7E3E, 0xA241CF15, 0xDED8C737, 0xB5DBC48A, 0x48F897BB, 0xB27B1665, 0xD5CF45B4, 0x92A4EA24} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 103 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 104 a1");
	}
	{
		static const fp2_t var_a =  { {0x67B311FB, 0xCBF4DA3D, 0x39CD12D7, 0x7A95CDDD, 0x40CDA33C, 0xFFB71292, 0x8D4254CA, 0x5EB77F6B},
	{0xEB4FF67F, 0xB3D557BD, 0x547BD733, 0x05BE414D, 0x33C73698, 0x47032BDB, 0xD08786A4, 0x8581BC8C} } ;
		static const fp2_t var_b =  { {0xF3BB9363, 0x7C05C18A, 0x487CCDEF, 0xF399FC78, 0x21BA7933, 0x92303210, 0x463C200B, 0x0DB53AE6},
	{0xF1EDEB4C, 0xF2AAD108, 0x4A1B0408, 0xFE39E73B, 0x8CF97A53, 0x3227C69D, 0x03923202, 0x46F2CF36} } ;
		static const fp2_t var_expected =  { {0x5B6EA55E, 0x47FA9BC8, 0x8249E0C7, 0x6E2FCA55, 0x62881C70, 0x91E744A2, 0xD37E74D6, 0x6C6CBA51},
	{0x7B11AD30, 0xA7919F15, 0xCA1EFBF5, 0xF0E67BE7, 0x6CDE2736, 0x7DCA960D, 0x93FADC7D, 0x1260ED00} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 105 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 106 a1");
	}
	{
		static const fp2_t var_a =  { {0x3B9F9F7F, 0xB7700691, 0x60D0FDD0, 0x83BE1D42, 0xA638F054, 0x122ABD4D, 0x3EFEFC51, 0x3B030043},
	{0x1022B0B5, 0xBA228B3F, 0x329078D8, 0x497DD707, 0x1EF4B9C8, 0x1FDAB371, 0xD72014F3, 0x19E50FCF} } ;
		static const fp2_t var_b =  { {0x30B83232, 0xC5438F2F, 0x62750811, 0xA7636CFC, 0x02EE7CEF, 0xEC1FD74F, 0x8916D5E7, 0x0DF0ADEC},
	{0xF6AB9B32, 0xF59A9205, 0x37DA0072, 0xEF5D9E42, 0xE7482486, 0x23EA8A07, 0x3BF71D14, 0x081E0DF4} } ;
		static const fp2_t var_expected =  { {0x6C57D1B1, 0x7CB395C0, 0xC34605E2, 0x2B218A3E, 0xA9276D44, 0xFE4A949C, 0xC815D238, 0x48F3AE2F},
	{0x06CE4BE7, 0xAFBD1D45, 0x6A6A794B, 0x38DB7549, 0x063CDE4F, 0x43C53D79, 0x13173207, 0x22031DC4} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 107 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 108 a1");
	}
	{
		static const fp2_t var_a =  { {0xB35B400D, 0x3765FF98, 0x6F2223F7, 0xAC5E8500, 0xB36B2332, 0xEC606436, 0xF60DD1AD, 0x89FAD6F7},
	{0x6A0E1E4E, 0xD179DEC0, 0x46705D52, 0x037BD517, 0x2EE165A0, 0xA0000BF9, 0xA4C08CE7, 0x2E74E004} } ;
		static const fp2_t var_b =  { {0x0EF7DAAB, 0xD9C24A48, 0x69E05B7D, 0x56E29FF3, 0x71BE1F26, 0x1049427A, 0x5591A43B, 0x24D451FC},
	{0x3607B89A, 0xBAA89E8B, 0x31B12719, 0xFDF00712, 0x1F0DAA5F, 0x2C5C3228, 0x3FB31823, 0x5A89F3FD} } ;
		static const fp2_t var_expected =  { {0xC2531AB8, 0x112849E0, 0xD9027F75, 0x034124F3, 0x25294259, 0xFCA9A6B1, 0x4B9F75E8, 0xAECF28F4},
	{0xA015D6E8, 0x8C227D4B, 0x7821846C, 0x016BDC29, 0x4DEF1000, 0xCC5C3E21, 0xE473A50A, 0x88FED401} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 109 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 110 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 111 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 112 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 113 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 114 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 115 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 116 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 117 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 118 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 119 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 120 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_b =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 121 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 122 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 123 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 124 a1");
	}
	{
		static const fp2_t var_a =  { {0x8F78C7DB, 0xB732F05F, 0x1AA1C42E, 0xD0C2068F, 0xE0176BF5, 0x89ABB7B8, 0x3962F57F, 0x079D4703},
	{0x3F37E12A, 0x5FB9B93C, 0x94924BA1, 0x5D455149, 0x2B990032, 0xAFBBF765, 0xBF0380B5, 0x6CADD50C} } ;
		static const fp2_t var_b =  { {0xFE230453, 0x1D90B9B4, 0xE374EDD2, 0x60777856, 0x34D1FB38, 0xD728A483, 0xF2E9CBF1, 0x27E512F1},
	{0xD1C135CF, 0xAC4FD4EB, 0xC2848E91, 0x1928D52E, 0x00B27388, 0x406F6D34, 0xD5B3D3E0, 0xB4AE0679} } ;
		static const fp2_t var_expected =  { {0xF381F823, 0x9890C05B, 0x0BA4B5A3, 0x835C3AD9, 0xFF27FA72, 0xADE36FA0, 0x869805B6, 0x99CBD2D3},
	{0xCFA2DFF6, 0xB2586E01, 0xA6859C56, 0x572E28BB, 0x7EC9165F, 0x6AACE69C, 0x296E88FE, 0x72136D55} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 125 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 126 a1");
	}
	{
		static const fp2_t var_a =  { {0x9F2C94B5, 0x9B81A320, 0xBC90BB17, 0x65743040, 0x42054E65, 0xBFF4F409, 0x914919A2, 0x46FC5D12},
	{0x142A9D28, 0xCE3584D7, 0x7DA2B909, 0x577AF20B, 0x35EA7E0F, 0x3DA8886E, 0x3224396E, 0x06D6CDFB} } ;
		static const fp2_t var_b =  { {0x1F1EE892, 0xFDF89999, 0x5ABF7C01, 0xB6CB45D5, 0x16820463, 0x3990BB1F, 0x27062EC7, 0x92A4FC23},
	{0x720F7AAF, 0x331BCA8B, 0xC638862D, 0x7CB04624, 0xA5ACFB56, 0x43A911D5, 0xC64323EB, 0x794B5A0F} } ;
		static const fp2_t var_expected =  { {0xE239E0BE, 0x9C779338, 0x36491E5C, 0xC1BA970C, 0x7F65D3B6, 0x81C49555, 0xAA61C704, 0x6E6AFFB1},
	{0x04475714, 0x9A0843FD, 0x8BE21223, 0xEDDC5887, 0xE4200C6D, 0xF55FD303, 0xABFFF1AB, 0x479F12AD} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 127 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 128 a1");
	}
	{
		static const fp2_t var_a =  { {0xA490B156, 0x5057DFF4, 0x0A142CBB, 0x45283B85, 0x54F25649, 0x86B47CB8, 0x857C3B0E, 0x06005243},
	{0x94BDA955, 0x866495F3, 0xDED60EC6, 0x2D22797B, 0x69CC4762, 0x2F968AFA, 0xC29FD2CC, 0x60667921} } ;
		static const fp2_t var_b =  { {0xBA9249BD, 0xE0E7EB8D, 0xD6575651, 0x7E73461E, 0xDFD82842, 0x1D03EED3, 0x7D8E12D4, 0x0B429C11},
	{0x62BC87E7, 0xB6FBDB12, 0x465EA461, 0x4F5A7AE4, 0xD81430CF, 0x1E446A36, 0x9973F9B3, 0x50FD8020} } ;
		static const fp2_t var_expected =  { {0x4C2A9C34, 0x6E5E7E18, 0x0834B5B0, 0xD9C6A207, 0xC8FCB7BB, 0x6510EA4F, 0x480D0463, 0xB4D154F4},
	{0x3201216E, 0xCF68BAE1, 0x98776A64, 0xDDC7FE97, 0x91B81692, 0x115220C3, 0x292BD919, 0x0F68F901} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 129 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 130 a1");
	}
	{
		static const fp2_t var_a =  { {0x0A3461B8, 0x3A1774F4, 0x8A4039C8, 0xD2BE16E7, 0xDACD7FCD, 0xBC9A94EA, 0x5DF31122, 0x1C8E1961},
	{0x0660F5F4, 0xEE1F46B6, 0xBF120753, 0x0767379F, 0x8DD99ECC, 0x6D09AB1C, 0xFAB88321, 0x20B66D57} } ;
		static const fp2_t var_b =  { {0x3EF36A03, 0x2BE96FCF, 0xDCE17A25, 0x1AE90C00, 0x53842550, 0x5CBD2638, 0x3BE92755, 0x69A0C5CF},
	{0x862C30B0, 0x9E46E4F4, 0x763223EA, 0xA6181468, 0x0CA384A5, 0xBD2D50CB, 0x9618A704, 0x2941970C} } ;
		static const fp2_t var_expected =  { {0x2D6D2C50, 0x0D1C8ED6, 0x81D69EEA, 0xCAE6B787, 0xDB2BE432, 0x5B3DCB1D, 0x6228C5F6, 0x6D00F254},
	{0xE260F9DF, 0x4EC6EB72, 0x1D57C2B0, 0x7460CFD8, 0xD518A3DB, 0xAB3CB6BC, 0xA4BEB845, 0xB188750D} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 131 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 132 a1");
	}
	{
		static const fp2_t var_a =  { {0x1A6B83D5, 0xC227D391, 0x4461EC5D, 0x34999110, 0x9AE425B7, 0x45CA2A5D, 0xA4A8EDD3, 0x32C5800A},
	{0x4F17B6AE, 0x6FA82A73, 0x52E59570, 0xF9963A88, 0x164D36D2, 0xE239138F, 0x207762E8, 0x34FCAEE1} } ;
		static const fp2_t var_b =  { {0xCBF020D5, 0x4AC346FE, 0xF7D5E4F8, 0x79F4DDD3, 0x3EEF86CA, 0xEE4867E6, 0x2A2BC81E, 0x269ACFE7},
	{0xE90D1AFD, 0x51731E21, 0x057DC5E3, 0xD1449C74, 0xB13F2D02, 0xFE86B9D1, 0xC74A8E6C, 0x1EC6C450} } ;
		static const fp2_t var_expected =  { {0x4E7B6300, 0x77648C92, 0x4C8C0765, 0xBAA4B33C, 0x5BF49EEC, 0x5781C277, 0x7A7D25B4, 0x0C2AB023},
	{0x660A9BB1, 0x1E350C51, 0x4D67CF8D, 0x28519E14, 0x650E09D0, 0xE3B259BD, 0x592CD47B, 0x1635EA90} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 133 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 134 a1");
	}
	{
		static const fp2_t var_a =  { {0x5971343B, 0x51EB9296, 0x9779B5D9, 0x6DAAEFED, 0xB6C2DC86, 0x143A82A5, 0x5EC22203, 0x7A1012A3},
	{0xDF5E250A, 0x6F4AFE34, 0x1FE1209E, 0x6674D675, 0xC96F7203, 0x69F3CF9D, 0x7C4277B5, 0x75B65024} } ;
		static const fp2_t var_b =  { {0x0D2ED826, 0xA3CCCE4A, 0x043065D7, 0xD555D365, 0xBC0DD464, 0xB5474757, 0x114694D5, 0xA4D08A3B},
	{0x7349B51B, 0x397CA0BC, 0x27C5F778, 0xE33C1C24, 0x3BA5EFAD, 0xCF67A43B, 0x71A43AE0, 0x1DF19666} } ;
		static const fp2_t var_expected =  { {0xAE6E90B0, 0xAD0D4DFD, 0x67C12F48, 0xAB66C929, 0x4E9791D6, 0x5A5397B9, 0x8D9A6956, 0x8F53272A},
	{0x6C146FEF, 0x35CE5D78, 0xF81B2926, 0x8338BA50, 0x8DC98255, 0x9A8C2B62, 0x0A9E3CD4, 0x57C4B9BE} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 135 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 136 a1");
	}
	{
		static const fp2_t var_a =  { {0x6F4C4DA7, 0x4E611A6C, 0x60976F3A, 0xB7CC3520, 0x489F76ED, 0x0D956469, 0x5524CD68, 0x578A7B3B},
	{0xD76B1E90, 0x58127A04, 0xAFEDB008, 0x3B950CDE, 0x71C09827, 0xF8D5CF9B, 0xD7ABDBC4, 0x59DAD28D} } ;
		static const fp2_t var_b =  { {0x4A667D80, 0x9E406C01, 0x0B186868, 0x5870E960, 0x95F6B328, 0x998EFBE8, 0x797129DC, 0x8A44F5BE},
	{0xCDEA71FE, 0xBC93D0B9, 0xBAA38A73, 0x18AF2414, 0xC6E4F0E2, 0x12BAFE43, 0x5FE8F462, 0x8B4417B3} } ;
		static const fp2_t var_expected =  { {0x871204C2, 0xAF0F381C, 0x29F6E618, 0x726CF861, 0x068B4D7A, 0x6F66C4EC, 0x1BD27FB4, 0x8759243F},
	{0x6BACE12D, 0x9A6D32FC, 0xC9C204DB, 0x35F7956A, 0xFEBE30FA, 0xE17B2DC2, 0xB7E1C38B, 0x88AA599C} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 137 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 138 a1");
	}
	{
		static const fp2_t var_a =  { {0xA6190053, 0x216F732B, 0xA6F480FE, 0x3C7D5FF8, 0x1AD32DFF, 0x17BA0577, 0x10F8E672, 0x71AD5C0F},
	{0xE1E8E34E, 0x9118F2B2, 0xDEF5841B, 0xB40379F4, 0x29CBC4DA, 0x73151910, 0xF9A41F45, 0x44A4D8AE} } ;
		static const fp2_t var_b =  { {0xCC98A410, 0xA42E8D84, 0x135AF6DB, 0x285B1502, 0x91C448E8, 0x83868D5F, 0xEA48FFE4, 0x826AA268},
	{0x7B38F2F8, 0x446F6397, 0x1C6CC662, 0x724E2048, 0x72E10B95, 0xB959F775, 0x965BAEE0, 0x99F8C846} } ;
		static const fp2_t var_expected =  { {0x3BAC90DE, 0x7C2F6F58, 0x68116969, 0x2733F797, 0xDCF16ECC, 0x8F93D482, 0x66CEC2B6, 0xA9565868},
	{0xC8DC24F1, 0x4B9818CC, 0x97009D00, 0x54C7064D, 0x0ACD42FA, 0xB51B7E06, 0xA3674C8D, 0x64BFAF2A} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 139 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 140 a1");
	}
	{
		static const fp2_t var_a =  { {0x453A7FE6, 0x33CECEA9, 0x726F5DDD, 0x22EDF558, 0xF3BA807D, 0x1A1CBB30, 0x18CBA5DA, 0x70682FBD},
	{0xE1EC936B, 0x84ED53B0, 0xE018BC3B, 0xE6DB6D74, 0x67DB3E75, 0xC6393902, 0x29C5DD1C, 0x251BFDC4} } ;
		static const fp2_t var_b =  { {0xD9087B05, 0x1C7A235A, 0x2566D749, 0x6EE1AE26, 0x789601CC, 0x5A2CB56E, 0xEBCB6983, 0x322B858D},
	{0x27C37128, 0x39E656FC, 0x2900FCA5, 0x2C3402A5, 0x5CAE235E, 0xA7593E52, 0xE1857512, 0xAA7762AD} } ;
		static const fp2_t var_expected =  { {0x6C3204E1, 0x1754AB4E, 0x4D088694, 0xB40C4732, 0x7B247EB0, 0xBFF005C2, 0x2D003C56, 0x3E3CAA2F},
	{0x1C5556DE, 0x49F58666, 0x8B8F9EDD, 0xCDB91770, 0x5F0FA4CC, 0x1A40571B, 0x885F4433, 0x34B839D8} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 141 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 142 a1");
	}
	{
		static const fp2_t var_a =  { {0x31273B57, 0xEC1CF527, 0xF71148EC, 0x7EF04D91, 0x46D4F9C8, 0x0460F8D6, 0xB4702051, 0x4209F366},
	{0xE7D3DFA0, 0x963F132C, 0x660194A8, 0x1FA47F35, 0x9A66BFF7, 0xCEFDAD39, 0x6FE5CAFA, 0x167877A4} } ;
		static const fp2_t var_b =  { {0xBB3DB946, 0x6EDA1E7E, 0x4850B349, 0x5282DAD7, 0x128F6C31, 0x0611B338, 0x045E9B65, 0x43E3B9E9},
	{0x19B3274D, 0x0235835F, 0xEAEC6E0B, 0x6E9C403C, 0x4AFF0CD4, 0xC57FAE66, 0xC6B34293, 0x650B6080} } ;
		static const fp2_t var_expected =  { {0xD815B6AC, 0x7C316059, 0x833874EA, 0x3F7F1F5B, 0x8828174C, 0xF9AFA209, 0xF0306114, 0xB839D83F},
	{0x304CECEE, 0x92F8197F, 0x4F8D05E4, 0xC419EB99, 0xA34A3CD7, 0x04DE5B3E, 0xE9516490, 0x6B80B5E5} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 143 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 144 a1");
	}
	{
		static const fp2_t var_a =  { {0x7822246F, 0xB29B63F8, 0xE5F1789E, 0xA142221E, 0x854AA9EA, 0xB1E6201A, 0xED7A40E1, 0x0290F286},
	{0xD83F84CD, 0x304723B0, 0xA4170DE8, 0x73E09C34, 0x36C2C5D5, 0x7B144FAF, 0x15654FAD, 0x06AAEADC} } ;
		static const fp2_t var_b =  { {0xB9029510, 0x02DBE679, 0x85D03444, 0xFC70F3D2, 0x28D5085B, 0x70592A42, 0xBEC6A6B7, 0x5C6350D6},
	{0x99F4ACAC, 0x08ECDE84, 0x66E395AA, 0x5FF72A58, 0x050C2A55, 0xFAA5C38D, 0xCD15170A, 0x74F1AB8D} } ;
		static const fp2_t var_expected =  { {0x214BC3FA, 0xAEAE0730, 0x349923A1, 0xB7E2DAED, 0xB0582B43, 0x3CED5243, 0x6ED27653, 0x60414072},
	{0xA0770CBC, 0x2648CEDD, 0x11AB5785, 0x26FB1E7D, 0x85992535, 0x7BCEE88D, 0x886F14CB, 0x4BCCDE10} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 145 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 146 a1");
	}
	{
		static const fp2_t var_a =  { {0x61591C00, 0xEE7C9EFB, 0x47D95240, 0xAF3021F8, 0x7786C555, 0x0CD904AA, 0x4AA3FC4A, 0x5947F368},
	{0x5DE7047E, 0xB96CEC0C, 0x75D32E5E, 0x1E6D9E61, 0x568ADBC6, 0xAEFEC4FF, 0xE1C595C4, 0x56BD0A3D} } ;
		static const fp2_t var_b =  { {0x1B67B3EF, 0x41DBD4C0, 0xE3422BFD, 0x9394F58E, 0x80931871, 0x7EBEFA5A, 0xA131812F, 0x27F0152C},
	{0xEF372EDA, 0xB1EF382F, 0xA6B87CD0, 0x28E99304, 0x56907C91, 0x2FBAB458, 0x80C03EF4, 0x7D5BA889} } ;
		static const fp2_t var_expected =  { {0x45F16811, 0xACA0CA3B, 0x64972643, 0x1B9B2C69, 0xF6F3ACE4, 0x8E1A0A4F, 0xA9727B1A, 0x3157DE3B},
	{0xD0DC0A3F, 0x066C3D8D, 0xA39290D5, 0x0895B7FD, 0x53DCE8EA, 0x7AA46D12, 0xA12432F9, 0x93750076} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 147 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 148 a1");
	}
	{
		static const fp2_t var_a =  { {0x70E45FC0, 0x09EF2005, 0x7946194E, 0xAD99D6C7, 0x3C2EFDC0, 0x043C4FFF, 0xD4CAD013, 0x7BC47E49},
	{0xF9C64F13, 0x9CA2CA70, 0x3A6F82A9, 0x22241083, 0x1C36752C, 0x5935416D, 0xDB0F00A5, 0x3C740B53} } ;
		static const fp2_t var_b =  { {0x29BE1A9E, 0x920EAED1, 0x6BA7ACD6, 0x4188E73E, 0xE4F87253, 0x1B8D1AFC, 0x342E0442, 0x4B425F53},
	{0x63F19D7F, 0x6778F236, 0xB26526C5, 0xF1497B34, 0x03CCB704, 0x4ABE8D8E, 0x64AC92B8, 0x286F398E} } ;
		static const fp2_t var_expected =  { {0x47264522, 0x77E07134, 0x0D9E6C77, 0x6C10EF89, 0x57368B6D, 0xE8AF3502, 0xA09CCBD0, 0x30821EF6},
	{0x95D4B194, 0x3529D83A, 0x880A5BE4, 0x30DA954E, 0x1869BE27, 0x0E76B3DF, 0x76626DED, 0x1404D1C5} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 149 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 150 a1");
	}
	{
		static const fp2_t var_a =  { {0xED78D0B5, 0x6BCE841A, 0x854C00DE, 0xC13245DD, 0x9CB2F0E2, 0x83664196, 0x1372BAA3, 0x103AA9FC},
	{0x5720B2E4, 0x3FF987D0, 0xCEAC3B38, 0xBA4964DE, 0xA36ABF70, 0x606451E2, 0xCC8C12E4, 0x18C3E44B} } ;
		static const fp2_t var_b =  { {0x2B9F2441, 0x5E7C1D9D, 0x24A2374D, 0x2C9B4451, 0x1A3856BC, 0x2CA6709A, 0x00B0EF00, 0x6F86D200},
	{0x3D59E6A7, 0x9112B985, 0x9107EFE9, 0xE225B804, 0xD68252E1, 0x35C84940, 0x04B6BA83, 0x1F46CFE6} } ;
		static const fp2_t var_expected =  { {0x2405E10F, 0x0C40F02F, 0x3521A8D8, 0xA7A8AE2D, 0xD65D23DB, 0x52202D67, 0x52E0A7CC, 0x5AC776BE},
	{0x7BF300D8, 0xADD557FC, 0x121C2A95, 0xEB35597B, 0x20CAF643, 0x25FC650D, 0x07F4348A, 0xB390B328} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 151 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 152 a1");
	}
	{
		static const fp2_t var_a =  { {0xE46966CF, 0x7BAA766B, 0x198DDA6D, 0x3A86D55F, 0x074F84ED, 0x660317AB, 0x0EBDB5A7, 0x34795B6B},
	{0xBFCDB40C, 0x0BE76D7B, 0x3AFB97A2, 0x0E446DF6, 0xB36D0908, 0xA9EB0192, 0x3C4BC515, 0x937D60CF} } ;
		static const fp2_t var_b =  { {0x69E56F88, 0x0C002EB1, 0x177BD52C, 0x7DD066EC, 0xEC873934, 0x9B7EAE6E, 0x8D0EEC21, 0x3C5D311F},
	{0xC66B1B0A, 0x989E4077, 0x4CDFEDB0, 0x23BDA29B, 0x95FC98EC, 0xD801EDF1, 0xE59D6F6D, 0x09EE6FA9} } ;
		static const fp2_t var_expected =  { {0xDCB02BE2, 0x6E98D16B, 0xD689E488, 0xCFC81B13, 0x6EAAD56D, 0xC5E4C5A7, 0xC1CDA5AE, 0xB22FC90D},
	{0xF9629902, 0x73492D03, 0xEE1BA9F1, 0xEA86CB5A, 0x1D70701B, 0xD1E913A1, 0x56AE55A7, 0x898EF125} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 153 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 154 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DF1CD41, 0xA0089289, 0x41682D7F, 0x40B48528, 0x457C0A48, 0x9691E8FE, 0x4EF5CF39, 0x8E992083},
	{0x7A6D0380, 0x663609D1, 0x86EDA086, 0x46AD334A, 0x1509E129, 0x1E3FD506, 0xB23D22EF, 0x556B43B1} } ;
		static const fp2_t var_b =  { {0x2BB0D22D, 0x0449C4A9, 0x4C1E3CFF, 0x5BDFF0E7, 0x21239F56, 0x4F1F2A32, 0x62058CAE, 0x5ADB2266},
	{0x44E9ACD5, 0xE350FD1E, 0xEA5157ED, 0xDB83BE25, 0x0A05BFCB, 0x1AA99E58, 0x9208BD66, 0x8D68C19C} } ;
		static const fp2_t var_expected =  { {0x7240FB14, 0x9BBECDE0, 0xF549F080, 0xE4D49440, 0x24586AF1, 0x4772BECC, 0xECF0428B, 0x33BDFE1C},
	{0x97AF8B46, 0x81D39664, 0x711427DF, 0x7E3B21C5, 0x5EE6AB12, 0xFEF69319, 0x605341B1, 0x821620D7} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 155 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 156 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 157 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 158 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 159 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 160 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 161 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 162 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 163 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 164 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 165 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 166 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 167 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 168 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 169 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 170 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_b =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 171 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 172 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 173 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 174 a1");
	}
	{
		static const fp2_t var_a =  { {0x9C3BD9DD, 0x446451EB, 0x59E8E6DB, 0xD468DDFD, 0x76F095AC, 0x0464057F, 0xDA89A995, 0x53037009},
	{0xCE611E4A, 0xBB056469, 0xB93A0EB5, 0x895320D0, 0x8F8AA486, 0xA7E65D9B, 0xB63A0749, 0x0648D76D} } ;
		static const fp2_t var_b =  { {0xB9624C56, 0xAEDA1866, 0xCA1BF032, 0xF03238C3, 0x8048E6E7, 0x3025B850, 0x07B44EDD, 0x7089FD1D},
	{0x0056987F, 0xDAB1DDF2, 0x74E8DEFC, 0x3422646F, 0xFCEBF141, 0xE30FC32D, 0x917E4371, 0x54AB13EB} } ;
		static const fp2_t var_expected =  { {0x4DC98451, 0xE0A74223, 0xAC115F94, 0xB971A094, 0xA75BE322, 0xD8D96782, 0x57C35C38, 0xB8A98687},
	{0x88DB04ED, 0xD21BC514, 0x5E7B3789, 0x70AD311A, 0x0FB48BBE, 0x8A180E27, 0x86143990, 0x7ECB628A} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 175 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 176 a1");
	}
	{
		static const fp2_t var_a =  { {0x290CC803, 0xD0EB353A, 0x6AB06EE0, 0x2029826C, 0x632D7427, 0x9820C44F, 0x3B8C67D9, 0x2BB873F6},
	{0x04D10C0B, 0x6FC73FE2, 0xDBBD2777, 0x0039264E, 0xEAC3142E, 0x2A7ED847, 0xD2FCE7AB, 0x4DC374B3} } ;
		static const fp2_t var_b =  { {0x5BA4F753, 0x730C3283, 0x9AA7667B, 0x62EAAE18, 0xD33A1D3C, 0x27C1850F, 0x059EA193, 0x28649190},
	{0x43FA9A10, 0xE69D045B, 0xF14F194A, 0x54746B9B, 0x33856ADF, 0x1B9C1597, 0x6A6C7A9F, 0x06A06A22} } ;
		static const fp2_t var_expected =  { {0x6A817272, 0xE307FD16, 0x512C6509, 0xF50E8CFB, 0xC80BACCD, 0xEC3700EF, 0x8F9765C7, 0x34F213A5},
	{0x2FC51567, 0xB71C38EA, 0xB40C8EBD, 0x9E856B6F, 0x55E9AC8F, 0x748A18B0, 0xC953D13A, 0x4F9FF4D3} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 177 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 178 a1");
	}
	{
		static const fp2_t var_a =  { {0x50C5B4C4, 0xA87BBB60, 0x26F54E29, 0x705326EF, 0x7A7B7ADB, 0x2FC4D959, 0x78B03A0C, 0x325952A6},
	{0x0378D99B, 0xED52C620, 0x21FDC826, 0xC0823F6E, 0x9A285D71, 0x965568D9, 0x4B03B4BB, 0x196C6EB7} } ;
		static const fp2_t var_b =  { {0x5A60FC48, 0xBA095E9B, 0xC39927EA, 0xDBD84D0E, 0xE140D36E, 0x1BB8F228, 0xE4AAE210, 0x28DCF1A6},
	{0x53E26374, 0x6E4583A6, 0x6A59DEA7, 0x648AD576, 0x76287FA1, 0xAAC7C2A3, 0xA622F25D, 0x4B248801} } ;
		static const fp2_t var_expected =  { {0xEF476AC3, 0xE22315E8, 0xC4E1104A, 0xEE850191, 0x6FCC7E9B, 0x0378B176, 0xDF67A1AF, 0x38556B8F},
	{0x376025DE, 0xF025A439, 0x6F6C9A31, 0x0F03D776, 0xCEDC13B7, 0xCBA80D75, 0xCF5CC1F3, 0x3784D0F6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 179 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 180 a1");
	}
	{
		static const fp2_t var_a =  { {0x5AB43BB9, 0x37EC34D1, 0x94A3521D, 0xEDD1BDC9, 0x84663AF6, 0xB51D3EE8, 0x1AD066EA, 0x10CEFC7C},
	{0x388D4E91, 0x998F705B, 0x0F869B88, 0x2ACEF873, 0x64395737, 0xC3508402, 0x6C2EE521, 0x4118B621} } ;
		static const fp2_t var_b =  { {0xFCC5812B, 0xEBD1ACCA, 0x4E6EEF40, 0x8185FE42, 0x72A5EAEB, 0xF4626B5D, 0x2B266242, 0x19D63F34},
	{0x18B290AE, 0xDB3D8A34, 0x1381CABE, 0x7896CA49, 0x3BCF2B4E, 0x7DC025F3, 0x8DB6B95C, 0x0FF657CF} } ;
		static const fp2_t var_expected =  { {0x2E55B825, 0x4DE686C6, 0xDE172843, 0x129848BE, 0x37B07A9F, 0x6B399565, 0xCEFC39BA, 0x2BF45CD9},
	{0xF429CD36, 0xA52916B7, 0xCA546621, 0xA2144621, 0xBEF415C9, 0xF9EE3DC4, 0xED1384EA, 0x410F1C06} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 181 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 182 a1");
	}
	{
		static const fp2_t var_a =  { {0x66E5AF4A, 0xE5193275, 0x3EDF51C5, 0x8612BB84, 0x4ED0BF66, 0x1D6E32B8, 0xE9CBF214, 0x3E3AD9AA},
	{0xC4FA9376, 0xDE1EE7F0, 0x31354898, 0x2D86D8E4, 0x12ADB95E, 0xA927EBF5, 0xFB86A81B, 0x3D15302D} } ;
		static const fp2_t var_b =  { {0x8A48A0AA, 0x6F386AF8, 0x4345D1FC, 0x7C2B05B9, 0x4EB76AC9, 0x9BAE4279, 0x63BF6440, 0xA3AA736D},
	{0xFF82E9B3, 0x922CD025, 0x6F4A03FD, 0xF346A003, 0x4580D501, 0x7048B0F4, 0x669EEDB6, 0x2D16100F} } ;
		static const fp2_t var_expected =  { {0x9277410D, 0x8735480C, 0x3C43C46F, 0x111F37C2, 0x55BDE73E, 0x103FB39B, 0xDAA46AE6, 0x6EC15DDD},
	{0x8C1331E9, 0x7B260EAD, 0x8AD84376, 0xCF70F52F, 0x375628FD, 0xF0AA083B, 0xFB907982, 0x6DDC639A} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 183 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 184 a1");
	}
	{
		static const fp2_t var_a =  { {0x49DF9BC8, 0x183BE22E, 0x7FBA84A8, 0xAFB1BB8C, 0xEED64A58, 0x3C2D3256, 0x6CBFBE6B, 0x4EC243CA},
	{0x5324F554, 0x24B295AE, 0x61EE09F7, 0x038E4B9B, 0xC2470D80, 0x2A26E3B9, 0xC07639C2, 0x6FF773F5} } ;
		static const fp2_t var_b =  { {0x4D9F5374, 0xADE49765, 0xA9E2589A, 0xF6B96A3D, 0x3DC95172, 0xF71B8C4F, 0x138A2574, 0x6E26270E},
	{0x2A287FAC, 0xFF70F29A, 0x0A88D4B7, 0xC211CB28, 0x6078F98A, 0x75F56872, 0xFA78607E, 0x1A030E1A} } ;
		static const fp2_t var_expected =  { {0x081A3503, 0x88A21B5C, 0xCD1A39F9, 0xEEB1DF76, 0x0BD6820B, 0x28B2BBEE, 0x3975B9BA, 0xB9691B00},
	{0x459C8B53, 0xCF81E664, 0xAF2D370D, 0x7C503BFF, 0x572C7B1D, 0x4BF6C96D, 0x24EE89B3, 0x0633A959} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 185 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 186 a1");
	}
	{
		static const fp2_t var_a =  { {0x20365E92, 0x3AD78149, 0xE1A3F17C, 0x5682FB7E, 0x32651657, 0x0AC63AA8, 0x6B55FD7B, 0xB86E2525},
	{0x2C0489F3, 0xD15F38E4, 0xAA4037CC, 0xD5EB6DCC, 0x3A6F8DBD, 0x2E4C0106, 0x442C57F7, 0x81323BF9} } ;
		static const fp2_t var_b =  { {0x8BC56C5C, 0x0D526700, 0x88AEAC92, 0x15D466CC, 0x07326722, 0xF0BFF529, 0xC4FDD7E6, 0x218A5FAA},
	{0x42EAF056, 0x887A8822, 0xC113D7AF, 0x21E940D7, 0xA901A2E5, 0x72F1A093, 0x104676C1, 0x3A7E0DBB} } ;
		static const fp2_t var_expected =  { {0xD230CF7E, 0x75A7CC6E, 0x5EEA488D, 0xFDDCBE3F, 0x4ACF0CF5, 0x05E354A8, 0x70DE4605, 0x88FBE4DA},
	{0x60B9DF8E, 0x3577DC2A, 0x58F48FE8, 0x7D9D21F0, 0xBB790545, 0xC4C3A986, 0x777B557D, 0x5CDED672} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 187 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 188 a1");
	}
	{
		static const fp2_t var_a =  { {0x36479BEE, 0xB312B88E, 0x6C15C975, 0xA54201C2, 0xE2150C71, 0x6E56CA38, 0x6FF64F2C, 0x24FA75A8},
	{0x965819F5, 0x50929E3F, 0x12DF0268, 0xCBD9E1AE, 0x440D4405, 0x9EAD20FA, 0x0FBAE2CF, 0x192E8A33} } ;
		static const fp2_t var_b =  { {0x8EFA83E4, 0xF7CFB3FC, 0xE9B4AF91, 0x03D1C972, 0x744C0DB3, 0x6F43A22D, 0xFEF5A939, 0x668A57AD},
	{0x91A994D4, 0x951D31B4, 0x9C72F0C6, 0x38E1C68C, 0xE607C784, 0x4E1A402A, 0x31CA19F5, 0x35291CAF} } ;
		static const fp2_t var_expected =  { {0x6466C6DA, 0x278E5379, 0xB5E63140, 0xA60A15B3, 0x285FBB46, 0xB7FA37C8, 0x308EDC64, 0x350D36C3},
	{0x4C1587BA, 0x64F1B78A, 0xB0B64633, 0x0D787D87, 0x73F058DA, 0xE30134B9, 0x5C9C209E, 0x884C7E72} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 189 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 190 a1");
	}
	{
		static const fp2_t var_a =  { {0xF738B973, 0xE9B390EC, 0xA5940746, 0xFB96889A, 0xBE291BE0, 0x41B43486, 0xC0CD43B9, 0x6BD18024},
	{0x79779F81, 0x071A5B6B, 0xCD287DF1, 0xFAB54D3C, 0x53AD1198, 0x66129FD3, 0x67F7C5B5, 0x26319B3E} } ;
		static const fp2_t var_b =  { {0x3B95B609, 0xD592F280, 0x002D441E, 0xD3A9B98C, 0xF8948984, 0x6082A5C9, 0x0893E99D, 0x293BAAC3},
	{0x5E0ADE19, 0x8F82D533, 0xA34D9538, 0x2F424748, 0xE0FAE9CD, 0xF2613B99, 0xE4ADDA9C, 0xB2994183} } ;
		static const fp2_t var_expected =  { {0x0305D517, 0x08E94C30, 0x8D6D2DB7, 0x467CAB0E, 0x916CF73C, 0x11EC656B, 0xBD0FD609, 0x1C1BE868},
	{0x70DD1A37, 0x8850F80E, 0xB82206C3, 0x83C3D59B, 0xFC47AEEF, 0x10B9D2E8, 0x1710C7C1, 0x7B33E14E} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 191 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 192 a1");
	}
	{
		static const fp2_t var_a =  { {0x876B711C, 0x46BB9CF1, 0x177C3C9E, 0x487156C8, 0x979DA75D, 0x7A03BF40, 0x26AF20AB, 0x0359A131},
	{0x422C00D4, 0x5DD3AF7B, 0x6180D8D6, 0xC352E299, 0x2BE8F008, 0x5FD6C97B, 0x981CFD07, 0x7EC9830D} } ;
		static const fp2_t var_b =  { {0xFFE19D16, 0x0C5F5EBB, 0x50D5CA24, 0xE7537D3F, 0x581588F3, 0x9C70B19E, 0x2AD6536B, 0x4177387C},
	{0xF1749044, 0xDD256329, 0xDC712BE4, 0x2E887B28, 0x5FCE2750, 0x44CEAEE4, 0xB27D2F93, 0x5B5989FC} } ;
		static const fp2_t var_expected =  { {0x215E4C57, 0x2E97A495, 0x89E939EC, 0x229231B5, 0x1C47313E, 0x06E3B84E, 0xAB44DCD0, 0x20786190},
	{0x56FAAAD4, 0xF90B3D9F, 0xC9842E00, 0xF28F4CED, 0x95954577, 0xAC464A3F, 0x7FBC49F6, 0x0AAD07C0} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 193 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 194 a1");
	}
	{
		static const fp2_t var_a =  { {0x8F345682, 0x32B94FE7, 0x9FA9E665, 0xC7BBE5E0, 0x87F74881, 0xFD7F95B5, 0x674FFABC, 0x51BCB95F},
	{0x13FCA970, 0xBC5A6419, 0x579D86AF, 0x1456CC64, 0x978C253B, 0x8029D2A0, 0x668AC95E, 0x9BFC87DA} } ;
		static const fp2_t var_b =  { {0xFE66373E, 0x05330E64, 0x663B8A13, 0x2D0C2495, 0x5E8D8A0B, 0x1B504A91, 0x2E697D7A, 0x2811BCBD},
	{0x2FE9BD57, 0xE9E8FC2C, 0x7E588C29, 0x4951EA06, 0xD917C137, 0x34199B6A, 0xE38BDB71, 0x1CD16D8A} } ;
		static const fp2_t var_expected =  { {0x5F5B89D9, 0x1239C3AD, 0x86667F93, 0xF4285536, 0x8FD8558D, 0x96A336E3, 0x0AD6312A, 0xB0D23842},
	{0xE8EFB8D5, 0xED3484FB, 0xE9357914, 0xEB6FC3E8, 0x2D622CAD, 0x49B0C852, 0x2CBAB51F, 0x8B5FC84F} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 195 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 196 a1");
	}
	{
		static const fp2_t var_a =  { {0xF4D50686, 0x1434BEE7, 0x70AFDA7F, 0x8BF243CC, 0x02FDDBD8, 0xB637FB39, 0xCE8A0E9E, 0x4171C7B7},
	{0x34B52622, 0x8D69D97F, 0xB8C30079, 0x17C869DC, 0x6193A81F, 0xB26EB01C, 0x5AE32761, 0x25033C80} } ;
		static const fp2_t var_b =  { {0xE19FE0B7, 0x299DD24E, 0x1D748BB9, 0xE20BB28E, 0x274A1DA5, 0xBF7A4634, 0xD9D66D59, 0x3FA2C809},
	{0x27B0C380, 0x17CED7AA, 0x3706E580, 0xCFA64152, 0xB99853B8, 0x9D30714E, 0x7E68A18F, 0x129D5ED3} } ;
		static const fp2_t var_expected =  { {0xAD8B5B22, 0x88C6AACF, 0xF21D40F5, 0xA9E7E807, 0x87F5CB50, 0xE21C84C1, 0x4A972B2A, 0x219AC3C6},
	{0xC121C6DB, 0xA7E36E4B, 0xBAB292A4, 0x89EB23C4, 0xA13D9023, 0x4BBD29FD, 0x3C5E0235, 0x29573EA4} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 197 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 198 a1");
	}
	{
		static const fp2_t var_a =  { {0x2683DBDE, 0x5342D3C4, 0x10A31C5A, 0xFA890493, 0xCC04110E, 0x7F50CECD, 0xA1166F8C, 0xAAB4E643},
	{0xB24393A6, 0x35ECB8AA, 0x3747C0AD, 0x180BCD13, 0xF8422BF7, 0xD1E05CF8, 0x7DECB60A, 0x372F6FD5} } ;
		static const fp2_t var_b =  { {0xF01F44A4, 0xDF10FE69, 0x7EBF5EB7, 0x2C2E29D8, 0x7CBAF7C0, 0x707DD55D, 0xB6EE5444, 0x30237A94},
	{0xBC52524D, 0xD25EC425, 0x3B3CDB26, 0xD58BF844, 0x78EAB060, 0x6DF601BF, 0xCC305CAE, 0x2B0C1073} } ;
		static const fp2_t var_expected =  { {0xEE0DF95E, 0x32E75341, 0xC2062E30, 0xB39D4934, 0xC04E930B, 0x541E7531, 0xD29EA7F3, 0x596E1E62},
	{0x29112AC7, 0x43801740, 0x55ED664C, 0x9DDE17E7, 0x0595D475, 0x183F48C8, 0x4B22D2C8, 0x080FEE2F} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 199 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 200 a1");
	}
	{
		static const fp2_t var_a =  { {0x46AF4D18, 0x5A34E7DC, 0x096FD108, 0xFE43724E, 0xB1155BD3, 0x4E3E46CC, 0xA95CEABB, 0x06BB65DB},
	{0xD3FA86CC, 0x1C450823, 0xD9B5AD91, 0x40912C24, 0x24978BB9, 0xC808F996, 0x58100D00, 0x7BA339C2} } ;
		static const fp2_t var_b =  { {0x73BE7FF6, 0x90D56825, 0x91011DD2, 0x3402A0B7, 0x2351586F, 0x1679B735, 0x4BE468BC, 0xA100DE92},
	{0x38465B72, 0x81680249, 0x94576CE6, 0x834FA870, 0xDC1717DD, 0x8DC00A07, 0x53FDB20A, 0x0E7901A6} } ;
		static const fp2_t var_expected =  { {0x0044A948, 0xF27D52C3, 0x67BE259D, 0xC998A660, 0x3FF196D7, 0x1D45F151, 0x7335FBF2, 0x83810861},
	{0xEE8FFFB2, 0xF28B5720, 0xDE3FA55D, 0x857DA844, 0xC555C4A1, 0xCF1DA723, 0x47737056, 0x303F49AF} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 201 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 202 a1");
	}
	{
		static const fp2_t var_a =  { {0xFEBE7350, 0x8EEA1C53, 0x37819163, 0xD4DA3177, 0xCDC7A47C, 0x068DE920, 0xAD9F26EB, 0xB67F4510},
	{0x1C9FBBBD, 0xAC4C62A3, 0xFDCDF846, 0x91DC163E, 0x05555CEF, 0x87C76940, 0xF15E7A8F, 0x234986FC} } ;
		static const fp2_t var_b =  { {0xB29616A3, 0xA206EBED, 0x5DC289B8, 0x22CBAB59, 0xE684D6D3, 0x9A22174D, 0x204FE81E, 0x3B1BBDF4},
	{0x43F65627, 0x8CF70494, 0x1B5154A0, 0x1483BB77, 0x008447F2, 0xE0584A10, 0xDFF05511, 0x1F4587A8} } ;
		static const fp2_t var_expected =  { {0x4830BC1E, 0x4A7CA29F, 0xA532DF41, 0xF6D3E2CD, 0x194EBD3D, 0xD78C7F4E, 0xB8A413C2, 0x1A74D159},
	{0x05B2485B, 0xFBA65B85, 0xAF7D5925, 0xA66DA40A, 0x6D3823EE, 0x49F73A32, 0xDCFE7591, 0x8912F279} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 203 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 204 a1");
	}
	{
		static const fp2_t var_a =  { {0x962F6EFF, 0x592AAAE5, 0xA373B2F4, 0xA4ABCFF7, 0xE8D3F014, 0x8FFB19F6, 0x3569D7ED, 0x645D6822},
	{0x373ACE92, 0x4DFCE2E7, 0x82DA5C4F, 0x45D9F3BA, 0xB7672D57, 0xF130BF3C, 0x102A1207, 0x923CB88A} } ;
		static const fp2_t var_b =  { {0xF507E32F, 0x7F93D6ED, 0xEA2D3501, 0x1E80CA9A, 0x8CD0347A, 0xE3C263AB, 0xBE2A1CE5, 0xA6C765CB},
	{0x62099695, 0x5CA5032E, 0x33DEE70F, 0x89B65D52, 0x057A67F9, 0x577D33B6, 0x74B0D939, 0x908A586C} } ;
		static const fp2_t var_expected =  { {0x6B07097A, 0x1372636C, 0x4DED0A6B, 0x714657FF, 0x9D07E554, 0x673B9296, 0x10262D62, 0x512ABCA6},
	{0x2668657B, 0x171E6F81, 0x515757AE, 0x71CFD97E, 0xEC92A769, 0xEA42B1A9, 0x2DFFCBEC, 0xA2E4D036} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 205 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 206 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 207 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 208 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 209 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 210 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 211 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 212 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 213 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 214 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 215 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 216 a1");
	}
	{
		static const fp2_t var_a =  { {0x57C20D03, 0x228D5B72, 0x5484C70A, 0x96C755C6, 0xCAF63540, 0xD2DCCA16, 0xCBA61B1B, 0xB6227B6F},
	{0x6D6E1B33, 0x66B2395F, 0x6ED2832E, 0x85957FE5, 0x035DF5D3, 0xEE0C5DE9, 0x3D8800A4, 0x6F79B80A} } ;
		static const fp2_t var_expected =  { {0x2F3F586D, 0xA1846395, 0x23067729, 0xB7084B63, 0xCD4DB71B, 0x7AE007B2, 0x663E2A34, 0x7EE08470},
	{0xF0DAED81, 0x1BD56EDC, 0xD3ACE4D6, 0x5836A96C, 0x079CAB86, 0x5790FF88, 0xB55EF44E, 0xB0520333} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 217 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 218 a1");
	}
	{
		static const fp2_t var_a =  { {0x84B50825, 0x8F3F7192, 0x42149EE1, 0x50CCCCCD, 0xDCB2327C, 0xD9362B50, 0xACD6590D, 0x89CE75DD},
	{0xDE4482BD, 0x593A6156, 0xE0C7DDE6, 0x0CD28ADC, 0xB488CDBF, 0xD9BECB0C, 0x9C043C9A, 0x0A7EB4E4} } ;
		static const fp2_t var_expected =  { {0x2FD95494, 0xF131236B, 0xF7F732F7, 0x29BE8246, 0x0E4FA3A2, 0x7591C327, 0x73A472BA, 0x146F9205},
	{0xFBE47E3C, 0xEE84C37C, 0x88873E1A, 0xCCE556D7, 0x7D4A3132, 0x849E45DD, 0x092C2379, 0x0C9ECFEA} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 219 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 220 a1");
	}
	{
		static const fp2_t var_a =  { {0x877C4530, 0x52808ECE, 0x5395437C, 0xD1F33519, 0x3BF1B079, 0xB617DB9A, 0xF4A9FFFA, 0x55123F8D},
	{0x04A2A67D, 0x5F216DF9, 0xCAD0C786, 0x7A53A0C2, 0xAF462D19, 0x6737F142, 0x027427D7, 0x64EF1ECD} } ;
		static const fp2_t var_expected =  { {0x83132316, 0xF8B7F2C9, 0x3D90668F, 0xFA9341D9, 0xE2D591A5, 0x0C6A74AD, 0x0C0632A6, 0x4CA69F0E},
	{0x4D0D852D, 0xC2AE8150, 0x55207AEA, 0xC8ED9841, 0x7810ECC9, 0x3693A086, 0xE9E755BA, 0x74E727AD} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 221 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 222 a1");
	}
	{
		static const fp2_t var_a =  { {0xA786E6DE, 0x38A26E56, 0x6AE9531E, 0xDF0E40FF, 0xA0AE5EF8, 0x65EFF3A9, 0x7416052D, 0x8E6CA4E7},
	{0x23B30470, 0xE99CF3FA, 0xAC628B26, 0xFC2765FD, 0xD06A98F5, 0x42E6217F, 0x9FF706A0, 0x63870B95} } ;
		static const fp2_t var_expected =  { {0x9C8538CF, 0x8DA007F5, 0x1285ACE3, 0xA16B0D7F, 0xEC1332FE, 0x788A3AC2, 0xF063BD0A, 0x3B900F4F},
	{0x60E8EF7D, 0x33094EE4, 0x41CA2CB0, 0xB9C17419, 0x96A6A3E6, 0xBABE631B, 0xBADD86FE, 0x15C1B2C2} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 223 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 224 a1");
	}
	{
		static const fp2_t var_a =  { {0x0D7B67EA, 0x5156A173, 0xD3B43C9D, 0x6B9786B8, 0xB0A5AD2E, 0x28C7135C, 0xFB0A23B3, 0x2FCF348D},
	{0x46FFCB97, 0xA14F156A, 0x9D141588, 0x4A899096, 0x84BA6252, 0x43A00DD8, 0xE4CBE069, 0x1782BCBB} } ;
		static const fp2_t var_expected =  { {0x30043B06, 0x8369F5CC, 0xB1E55747, 0x9468418D, 0x03910DFE, 0x6DB5EA18, 0xEAE8DD0E, 0x1043E3CC},
	{0x7F212E5D, 0xE5F31D49, 0x69DD6B69, 0xDF1B8672, 0x5BD4CF94, 0x95637D15, 0x43E84B3C, 0x6721ABF3} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 225 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 226 a1");
	}
	{
		static const fp2_t var_a =  { {0xA7A60841, 0xE4266A51, 0x6DC518B4, 0xF45AD835, 0x9F4AE859, 0x6EF11682, 0x9B1192AB, 0x5B528C0A},
	{0x551ED938, 0x7673E3B4, 0x1E586C8D, 0x49D2C924, 0x2511E985, 0x878A31D7, 0x44BCD479, 0x15867160} } ;
		static const fp2_t var_expected =  { {0xA63E0900, 0x4AD5C400, 0x64B61A0A, 0x5862E53D, 0xD5FC16A3, 0x436A9228, 0x716920FD, 0xA6A9D6EF},
	{0x74C0D96D, 0x600F77F8, 0xC6539EAF, 0x105252CB, 0x844822E0, 0x7CC44F8D, 0x6A687D4E, 0x5FA38E05} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 227 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 228 a1");
	}
	{
		static const fp2_t var_a =  { {0x57D0A07E, 0x84F19E53, 0x5A7466D7, 0xC5154E50, 0xEB838525, 0x021A4BAA, 0x263B87D7, 0x1ABF0143},
	{0x7974F27C, 0x9397950F, 0xEF00CC77, 0x1DE10847, 0x4BD2C9FB, 0x6A4BC210, 0x6E52C02B, 0x3109254D} } ;
		static const fp2_t var_expected =  { {0x668F25B7, 0xD717E71C, 0x684ACB17, 0x4761B3A3, 0x8715240D, 0x9BC7B100, 0xF1F9F1C3, 0x44A325EC},
	{0x448A4204, 0x91F7DF7D, 0x38351ADA, 0x1BE0F3F8, 0xF91AEACE, 0x828AF46B, 0x558ED84C, 0x184DC7B4} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 229 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 230 a1");
	}
	{
		static const fp2_t var_a =  { {0xCA841ACA, 0xFB0C610C, 0x516403BA, 0xB777DA2F, 0xA11172F1, 0xDDD599DD, 0xAC5387A6, 0x99A475E5},
	{0x1DC2D34E, 0x6770C9EB, 0x13553FA0, 0x2D67BDD2, 0xCF7957C5, 0x8BDA8ED1, 0x53E62A52, 0x81A0DE03} } ;
		static const fp2_t var_expected =  { {0xC1842E95, 0xCCC743F0, 0x63924DD5, 0xCF518E67, 0x4307A774, 0xBB22D60F, 0x05589223, 0x2F04A677},
	{0xF62C9207, 0x71A15C11, 0xCF2B6FE9, 0xCE324C83, 0xA3E058D3, 0x833369B4, 0x4B1EFA6C, 0x4A2BF61C} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 231 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 232 a1");
	}
	{
		static const fp2_t var_a =  { {0x88C85708, 0x566ED5DA, 0x723A0394, 0xCE19AA15, 0xB9B198E1, 0x3A932CDB, 0x3D6078B0, 0x8F458301},
	{0xE7B33D4F, 0x9DA756FF, 0xCA1CA3D1, 0x1D396A1A, 0xCA2BCF6B, 0xC550374B, 0x26AE55A9, 0x5A503905} } ;
		static const fp2_t var_expected =  { {0xFE064D22, 0x6521B4A0, 0xEF5031A3, 0xBC2243CE, 0xBE16411F, 0xFDB38EA9, 0x606D9733, 0x4D3FDD3D},
	{0x3B3128A2, 0xFCC64941, 0xDF5C1A0B, 0x7C2E92E3, 0x45AB0EA5, 0x25DB2721, 0x278A0545, 0x1B0AA5B3} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 233 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 234 a1");
	}
	{
		static const fp2_t var_a =  { {0xF8A8A3ED, 0xE478A269, 0x49AEC2B5, 0x3DCED87C, 0x1AB059A9, 0x9D68ABE8, 0xECADA3D5, 0x36E7811B},
	{0xC272096D, 0x24ACB6E7, 0x94B20A65, 0xD29EB451, 0x964453FD, 0x36B8B77B, 0x56CE6F6E, 0x51DC1D05} } ;
		static const fp2_t var_expected =  { {0xF0784D63, 0x86758290, 0xA51A7CEC, 0xEB38E2B4, 0xDAF004F3, 0x4FBEE938, 0x0CD86EED, 0x6D2A123E},
	{0x94B4E782, 0x499F2211, 0x9476A237, 0x5EA73871, 0x3D555DE9, 0x0A06FD5C, 0x0EE07FEA, 0x058EF0B3} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 235 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 236 a1");
	}
	{
		static const fp2_t var_a =  { {0xE6797CFB, 0x308AAA0F, 0x23785761, 0xAE38CF96, 0xE4006E7D, 0xB968C79A, 0xC95ACC05, 0x3774B04A},
	{0xD73340E9, 0x288200B7, 0x34138981, 0x71A3E753, 0xCBE8A98D, 0x3BDC464D, 0x9469EE6B, 0x3A17B102} } ;
		static const fp2_t var_expected =  { {0x2FA71AD3, 0x63C6CD6C, 0x97755216, 0x754D4687, 0x4FB73474, 0x0B98D750, 0xA08BAF75, 0x0B67BAAF},
	{0xF79D38F7, 0x47FEE3CA, 0x6F0ED0FD, 0xBD9F7C92, 0xA920CB3E, 0x79AB3A87, 0x126DD5E0, 0x6E95A50C} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 237 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 238 a1");
	}
	{
		static const fp2_t var_a =  { {0x9D8C0372, 0x061FFBFA, 0xDD0E18D2, 0xE7C37ED8, 0xCE5F3B4C, 0x898D5055, 0xA6CE2C0D, 0x08658C15},
	{0x8EC836D0, 0x169378F7, 0xA9ED5D20, 0x5E65EB51, 0x4295BFA3, 0x701989AB, 0xD2B0080C, 0x2B337678} } ;
		static const fp2_t var_expected =  { {0x988F0852, 0xC87C98E4, 0x8A3A19E3, 0x1F3651DD, 0xA890C46A, 0x52AE151F, 0x75F715F2, 0x07F5DF0E},
	{0x3D4E7F59, 0x9EF67599, 0x2A6BD50D, 0x4B8BC562, 0x45DA3B78, 0x61F0B9E4, 0x4665CFA8, 0x07E93EEE} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 239 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 240 a1");
	}
	{
		static const fp2_t var_a =  { {0x7F93C63F, 0x77B50657, 0x1E3570CC, 0xB3E045FB, 0xD907850E, 0x5B28962F, 0xD2AC882B, 0x2DFC45C2},
	{0x912EAD30, 0x9B7DB4F2, 0x35B386B6, 0x4066B02C, 0x14AFED4C, 0xB42D178B, 0x41F35742, 0x7911A519} } ;
		static const fp2_t var_expected =  { {0x6A43D3E2, 0x7102A4D0, 0xD737BE54, 0xC7DCDC9B, 0x7E3B7A2A, 0xCAC8160F, 0x54E497EB, 0x1856239E},
	{0x9B07BD4E, 0x14547AFD, 0x3D206ECC, 0xC6C3DF7F, 0xA042237B, 0x785E88FF, 0x6CDB4C48, 0x43D4372A} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 241 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 242 a1");
	}
	{
		static const fp2_t var_a =  { {0xDDE84F97, 0xCCEDCBB5, 0x95C648A7, 0xA3053818, 0x891061F9, 0x987698F3, 0xA0125884, 0x8860C789},
	{0xC81FF299, 0xA4E55249, 0x59A7B3A4, 0xFADA0E81, 0x9B1305CF, 0x22085920, 0x52AE9B5D, 0xB892B4D1} } ;
		static const fp2_t var_expected =  { {0x42FADD75, 0xCC4F0434, 0x9FE3CC3D, 0xC1F1D396, 0x9017E008, 0x100984E5, 0xE86B65FA, 0x5AA709A1},
	{0xA8D4BE02, 0x6305CB96, 0x35AE37FB, 0xC04889AF, 0x931F9B50, 0x70C77601, 0xD32E5789, 0x73735454} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 243 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 244 a1");
	}
	{
		static const fp2_t var_a =  { {0x99B54D9B, 0x94523123, 0x6A2B4B5F, 0x040C20AE, 0x5FA275ED, 0x0A2E5C3D, 0xDFFFF302, 0x1CD58E51},
	{0xFA75D60F, 0x5F55BD76, 0x0277C187, 0xA0E96D0A, 0x1BC5927D, 0x1E395857, 0x757EC4E9, 0x04D27A39} } ;
		static const fp2_t var_expected =  { {0x1EC47255, 0x44D2104A, 0x66B0E164, 0xD68C7A98, 0x065E606A, 0x24AC7A45, 0xF20ACE04, 0x05759105},
	{0xF12A63B5, 0x50B2388F, 0xD46FD9A3, 0x847DF16E, 0x61DBE99A, 0xAA3B2BFB, 0x7EA73C71, 0xA5CC3A94} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 245 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 246 a1");
	}
	{
		static const fp2_t var_a =  { {0x60685ABF, 0x9B63E7CA, 0x5099F0C5, 0xAD3C5D23, 0x673FF718, 0xAB6D1C8E, 0xA2B3E5F5, 0x1AE3B2E4},
	{0xB898DDB4, 0x36B8B9A8, 0xADA4D3FA, 0xCE53E73E, 0x69EB231B, 0x34A21039, 0x5BCB5151, 0xA0DC3502} } ;
		static const fp2_t var_expected =  { {0xB69F43C0, 0x30936C68, 0xDB8AE6ED, 0x57124AF8, 0xF6102986, 0x2C81FCEF, 0xA27D751E, 0x9CE2B65B},
	{0xF206CC10, 0xDA4E5D99, 0xD85D0D2C, 0xA57B0F6B, 0xFFCF342E, 0x998732E8, 0x0EED3222, 0xA270F324} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 247 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 248 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 249 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 250 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 251 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 252 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 253 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 254 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 255 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 256 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 257 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 258 a1");
	}
	{
		static const fp2_t var_a =  { {0xBA67052B, 0xEFBFC0EE, 0x68C76E33, 0xA44AE333, 0x9AE74B75, 0xB7AD895A, 0xF9241887, 0x3547B832},
	{0x825163CD, 0xDAD47A27, 0x1FE0BADB, 0xF211CAD0, 0xA38239B0, 0x5086AB6C, 0x779FDEB4, 0xB23285E9} } ;
		static const fp2_t var_expected =  { {0x0E499CE3, 0x77572550, 0x1E9FA6BD, 0x5BAE47EA, 0xF764EA95, 0x5986F2E2, 0x9CA17A58, 0x77ADAB7A},
	{0x723ECC34, 0x6CE181EC, 0x7A2C4D11, 0x0291BBB8, 0xFBB261B3, 0xA5F383EB, 0xDBDF5D6E, 0xB6231255} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 259 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 260 a1");
	}
	{
		static const fp2_t var_a =  { {0x70CE98DE, 0xDDE359DC, 0x1377CBD3, 0x2DB43C7E, 0x308B2D7E, 0xACEF0600, 0x3531D684, 0x6455D077},
	{0xA617D9B9, 0x35730BA1, 0xACCE34E3, 0x025802EF, 0x74CCC57F, 0x8C1946BF, 0x78F018A0, 0x8AE6F063} } ;
		static const fp2_t var_expected =  { {0x38674C6F, 0xEEF1ACEE, 0x09BBE5E9, 0x16DA1E3F, 0x184596BF, 0x56778300, 0x9A98EB42, 0x322AE83B},
	{0x8422072A, 0x1A30CAA9, 0x40A30A15, 0x0AB4D7C8, 0x6457A79A, 0xC3BCD195, 0xDC877A64, 0xA27D4792} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 261 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 262 a1");
	}
	{
		static const fp2_t var_a =  { {0x29CEF969, 0xF309C103, 0x1F0C1498, 0xBB0127CF, 0x50B7FC96, 0x4B2E021C, 0xA78CB465, 0x21348E88},
	{0xE896C400, 0x7792AEAD, 0x434797FA, 0x117A3413, 0x238CCFEE, 0x49114616, 0xCFF50C2D, 0x4370C2B7} } ;
		static const fp2_t var_expected =  { {0x45FD9702, 0xF8FC255A, 0xF9C1F9EF, 0xE7096A37, 0xD24D4325, 0x23472F43, 0x73D5C847, 0x6DA416A5},
	{0xF44B6200, 0x3BC95756, 0xA1A3CBFD, 0x08BD1A09, 0x11C667F7, 0xA488A30B, 0xE7FA8616, 0x21B8615B} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 263 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 264 a1");
	}
	{
		static const fp2_t var_a =  { {0x54224CF1, 0xF9A56DA1, 0xE9F3B58A, 0x4B6B3116, 0xAD96921B, 0x820D4BBE, 0xE16E483F, 0x0F940AE5},
	{0xDA443456, 0x08D34A85, 0x5F325FB0, 0xBEA35C67, 0x85EA4F97, 0x14B45647, 0x2FEAE5A5, 0x207A80F1} } ;
		static const fp2_t var_expected =  { {0x5B2740C6, 0xFC49FBA9, 0xDF35CA68, 0x2F3E6EDB, 0x00BC8DE8, 0x3EB6D415, 0x10C69234, 0x64D3D4D4},
	{0xED221A2B, 0x0469A542, 0xAF992FD8, 0xDF51AE33, 0xC2F527CB, 0x8A5A2B23, 0x97F572D2, 0x103D4078} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 265 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 266 a1");
	}
	{
		static const fp2_t var_a =  { {0x53DAFB01, 0x02DF36AD, 0x1407A362, 0xAA7D2BFA, 0x44A042E6, 0x9EEAD304, 0x326A9C06, 0xB5306986},
	{0xFC3EF5F6, 0x9AF0CA47, 0xC6EB1CEC, 0x737D21E7, 0xB5243680, 0xDAE9F314, 0x07F71EE9, 0x4761AEE4} } ;
		static const fp2_t var_expected =  { {0x5B0397CE, 0x80E6E02F, 0x743FC154, 0xDEC76C4D, 0xCC41664D, 0xCD2597B7, 0x3944BC17, 0xB7A20424},
	{0xFE1F7AFB, 0x4D786523, 0xE3758E76, 0x39BE90F3, 0x5A921B40, 0xED74F98A, 0x03FB8F74, 0x23B0D772} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 267 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 268 a1");
	}
	{
		static const fp2_t var_a =  { {0xF1833E1B, 0x59C69AEC, 0x02CFEFE2, 0x1C0360CA, 0x50265D1D, 0x1B0C2200, 0xED959F78, 0x09DBE131},
	{0x9C8CE0B2, 0x18E8D8DC, 0xCD004EFA, 0x29270CFC, 0x62FDF4D6, 0xB3CB80A5, 0x0869F682, 0x08552D4B} } ;
		static const fp2_t var_expected =  { {0x29D7B95B, 0xAC5A924F, 0x6BA3E794, 0x178A86B5, 0xD2047369, 0x8B363F35, 0x16DA3DD0, 0x61F7BFFA},
	{0x4E467059, 0x0C746C6E, 0x6680277D, 0x1493867E, 0xB17EFA6B, 0x59E5C052, 0x8434FB41, 0x042A96A5} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 269 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 270 a1");
	}
	{
		static const fp2_t var_a =  { {0x5CB133BC, 0x8827408D, 0xD39A7A64, 0x6058AED7, 0x44E116A9, 0xA77152FF, 0x62997B63, 0x6CC9DF7F},
	{0xE0D51D37, 0xAE1C1872, 0x36E973A0, 0x05331FBF, 0x24DCBFB4, 0xFC934844, 0xE52D2E14, 0x383F7F5C} } ;
		static const fp2_t var_expected =  { {0xAE5899DE, 0x4413A046, 0xE9CD3D32, 0xB02C576B, 0xA2708B54, 0xD3B8A97F, 0xB14CBDB1, 0x3664EFBF},
	{0x2180A8E9, 0xD6855112, 0x05B0A973, 0x8C226630, 0xBC5FA4B4, 0xFBF9D257, 0x92A6051E, 0x79298F0F} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 271 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 272 a1");
	}
	{
		static const fp2_t var_a =  { {0xB704BACB, 0x61F1B21F, 0xE84E9B1F, 0x0119822F, 0xDE8BEA95, 0x4F44B360, 0xA2ACD1C1, 0x272D4C17},
	{0xD1F36EC1, 0xCC27A603, 0x2B16F263, 0x58F53E07, 0x805E3D82, 0x566EA18C, 0x4CE236DD, 0x31155946} } ;
		static const fp2_t var_expected =  { {0x8C9877B3, 0x30701DE8, 0x5E633D33, 0x0A159768, 0x19373A25, 0x255287E6, 0xF165D6F5, 0x70A0756C},
	{0x9A0FD1AE, 0x658B17DA, 0xFFC768D5, 0xB6037553, 0xEA20639B, 0x28E77EFB, 0x46808983, 0x75947C04} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 273 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 274 a1");
	}
	{
		static const fp2_t var_a =  { {0xED71A683, 0xED5B7191, 0x372D4DB0, 0x1724974D, 0x6B4A66DE, 0x4A660C02, 0xFED6F1D0, 0xA8514742},
	{0x3F598485, 0x1B54DBBB, 0x6C5EACE4, 0x032A6402, 0x8C53AFB9, 0x912731FC, 0x317ECC37, 0x778A84FB} } ;
		static const fp2_t var_expected =  { {0xA7CEED8F, 0xF624FDA1, 0x05D2967B, 0x951B21F7, 0xDF967849, 0xA2E33436, 0x9F7AE6FC, 0xB1327302},
	{0x50C2DC90, 0x8D21B2B6, 0xA06B4615, 0x0B1E0851, 0xF01B1CB7, 0x4643C733, 0xB8CED430, 0x98CF11DE} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 275 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 276 a1");
	}
	{
		static const fp2_t var_a =  { {0x65C93C0F, 0x7D1F6F4C, 0x4E114526, 0xD57FE154, 0xD0ECADA3, 0x1A02F63F, 0x8748F47C, 0x2B70B355},
	{0xEAF0462D, 0x8B179958, 0xFD55F1E2, 0xAF993CD2, 0xA474CAD0, 0xD73D1CC6, 0x432CD1DF, 0x719BA3D9} } ;
		static const fp2_t var_expected =  { {0xE3FAB855, 0xBE06FC7E, 0x91449236, 0x7448C6FA, 0x92679BAC, 0x8AB1A955, 0xE3B3E852, 0x72C2290B},
	{0x268E3D64, 0xC5031185, 0xE8E6E894, 0xE15574B9, 0xFC2BAA42, 0x694EBC98, 0xC1A5D704, 0x95D7A14D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 277 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 278 a1");
	}
	{
		static const fp2_t var_a =  { {0x4E519E7F, 0x99D91D94, 0x495065A2, 0xF81580F2, 0x81CCB1C1, 0x6D9F571F, 0x8E24C8CB, 0x117CE282},
	{0x5F5F3975, 0x4839DF28, 0x73163E02, 0x95149D68, 0xB5CC1755, 0x8170C011, 0x74927EF2, 0xADA295B6} } ;
		static const fp2_t var_expected =  { {0xD83EE98D, 0xCC63D3A2, 0x8EE42274, 0x859396C9, 0x6AD79DBB, 0x347FD9C5, 0x6721D27A, 0x65C840A2},
	{0xE0C5B708, 0xA394346C, 0xA3C70EA4, 0x54132504, 0x84D75085, 0xBE688E3E, 0x5A58AD8D, 0xB3DB1A3C} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 279 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 280 a1");
	}
	{
		static const fp2_t var_a =  { {0xCB997905, 0x1191F9A1, 0x8D1A1E42, 0x0D4FE143, 0x3C850C52, 0x5029F5FF, 0x25592440, 0xA3A30774},
	{0x06BACEB5, 0xBFF6EEE9, 0xCEF24D39, 0x1A6D6131, 0x98DC05E2, 0x2CB059B4, 0xB545D59E, 0x4246BEEE} } ;
		static const fp2_t var_expected =  { {0x96E2D6D0, 0x884041A9, 0x30C8FEC4, 0x9030C6F2, 0x4833CB03, 0xA5C52935, 0x32BC0034, 0xAEDB531B},
	{0x347381A8, 0x5F72BC4D, 0x51B51640, 0x96BF86E9, 0xF65F47CB, 0x94085B0F, 0x7AB258E3, 0x7E2D2ED8} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 281 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 282 a1");
	}
	{
		static const fp2_t var_a =  { {0xC7C8516C, 0xF2D1DBA5, 0x103A2711, 0x2B174D7C, 0x4E5CEA1A, 0xFB87074E, 0x9BE74EA4, 0x4F6FCAC3},
	{0x8942FE5D, 0x9EC237E1, 0x5100CBA0, 0xE3D8C27C, 0x670DF98D, 0xB54E2531, 0x36F958B2, 0x83DB3AE0} } ;
		static const fp2_t var_expected =  { {0xE3E428B6, 0xF968EDD2, 0x081D1388, 0x158BA6BE, 0x272E750D, 0x7DC383A7, 0xCDF3A752, 0x27B7E561},
	{0x75B7997C, 0xCED860C9, 0x92BC5573, 0x7B75378E, 0x5D7841A1, 0xD85740CE, 0x3B8C1A6D, 0x9EF76CD1} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 283 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 284 a1");
	}
	{
		static const fp2_t var_a =  { {0x0B4C3B08, 0x89D75CD1, 0x32CB0552, 0x98D34DB7, 0xF0642014, 0xE98B3F22, 0x4358A297, 0x0AAA3BEC},
	{0xD0F6A6A9, 0xD0144F65, 0x7B2683D1, 0xD540774A, 0x7A4096D0, 0x39CF7C4D, 0x688E14F5, 0x05B7AC35} } ;
		static const fp2_t var_expected =  { {0x85A61D84, 0x44EBAE68, 0x996582A9, 0x4C69A6DB, 0x7832100A, 0xF4C59F91, 0x21AC514B, 0x05551DF6},
	{0x99916DA2, 0x67816C8B, 0xA7CF318C, 0xF42911F5, 0x67119042, 0x1A97EC5C, 0xD456788F, 0x5FE5A57B} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 285 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 286 a1");
	}
	{
		static const fp2_t var_a =  { {0xA095557A, 0x624A7EAB, 0x95C4B22E, 0xD8C415CB, 0x9AF2C2EA, 0xD91EC77B, 0xADE9DF69, 0x09C638E4},
	{0x0521F7F7, 0x833A7CD4, 0x0E2F017A, 0x1591445B, 0x6A5FD1D0, 0x14B64421, 0xFE24C2CE, 0x9E7C37B8} } ;
		static const fp2_t var_expected =  { {0xD04AAABD, 0x31253F55, 0xCAE25917, 0x6C620AE5, 0xCD796175, 0xEC8F63BD, 0x56F4EFB4, 0x04E31C72},
	{0xB3A71649, 0xC1148342, 0xF1537060, 0x9451787D, 0x5F212DC2, 0x880B5046, 0x9F21CF7B, 0xAC47EB3D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 287 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 288 a1");
	}
	{
		static const fp2_t var_a =  { {0x6D7F605B, 0x4C22580D, 0x448F671B, 0x9E447FFA, 0xB346ED37, 0xCBB35DD5, 0x6A816D6E, 0x081945F2},
	{0x91E7D7CA, 0x2526D885, 0x0BD689CC, 0x0709080E, 0x11ECBF93, 0xE458AF60, 0xE72A17C6, 0x636FB3DD} } ;
		static const fp2_t var_expected =  { {0x67D5CA7B, 0x258870DF, 0x8C83A331, 0x58AB164D, 0x8394BB76, 0xE389DD20, 0x555024CB, 0x6116725A},
	{0xC8F3EBE5, 0x12936C42, 0x05EB44E6, 0x83848407, 0x08F65FC9, 0x722C57B0, 0xF3950BE3, 0x31B7D9EE} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 289 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 290 a1");
	}
	{
		static const fp2_t var_a =  { {0xBF8CDA34, 0x512D85CF, 0x0AF5A69C, 0x145E6311, 0xDAA978F3, 0xF6961668, 0x0B398496, 0x2E7B32DB},
	{0x1CDD5CB8, 0x613F0182, 0xB3D97CA6, 0x528B31CD, 0x86902FC5, 0x86AE53DC, 0x546C34AB, 0xA9C11388} } ;
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 291 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 292 a1");
	}
	{
		static const fp2_t var_a =  { {0x5F9CCDAD, 0xBF3ED9DF, 0x49DE5791, 0x7FC3C87F, 0x48902D1C, 0xD3DDABCB, 0xE2D14507, 0x7234E6DC},
	{0x8F9037D7, 0x26336310, 0x870A1A92, 0xD9EDB211, 0x24AF0013, 0x171F9874, 0xB8233A7E, 0x05E500AB} } ;
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x5F9CCDAD, 0xBF3ED9DF, 0x49DE5791, 0x7FC3C87F, 0x48902D1C, 0xD3DDABCB, 0xE2D14507, 0x7234E6DC},
	{0x8F9037D7, 0x26336310, 0x870A1A92, 0xD9EDB211, 0x24AF0013, 0x171F9874, 0xB8233A7E, 0x05E500AB} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 293 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 294 a1");
	}
	{
		static const fp2_t var_a =  { {0x93782426, 0x25F5C821, 0xF7571C22, 0x3F1E77F7, 0xD029D68D, 0x2A3773BE, 0xFEC4C218, 0x944CED6E},
	{0x141D2F6F, 0xA0C31266, 0x485BAA03, 0xC3496340, 0x84F24454, 0xF45371FD, 0xC2090063, 0x4BDAA6CC} } ;
		static const bigint_t var_b = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x7D2CBB56, 0x97A08B08, 0x90884DBE, 0x4D08D356, 0x7079754C, 0xE9A4496F, 0xEEC41E5D, 0x0F11CAE5},
	{0x7EDC1A62, 0xFDC60950, 0x77595554, 0x6AF86146, 0xC53A8DA0, 0xEC6F2F19, 0xFCAD67FE, 0xA3105680} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 295 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 296 a1");
	}
	{
		static const fp2_t var_a =  { {0xA21954EB, 0x4F4C1C54, 0xF68D068F, 0x19A81EAC, 0x297ACBA9, 0xF83A97C6, 0x32D11405, 0x0A2A419B},
	{0x14BA9BF6, 0x3C983D03, 0xF6F00C73, 0x744BD6E6, 0x7DDD21F5, 0xBA0775CF, 0x6365F132, 0x9081B796} } ;
		static const bigint_t var_b = {0x3C5DF213, 0x48561155, 0xE54896B3, 0x4A887B20, 0x49D0227B, 0x6C9A150C, 0x4E2589E1, 0xB5F5E271};
		static const fp2_t var_expected =  { {0xB2BBDDCC, 0x1E18E950, 0xD1674B61, 0x646E3A7E, 0x889295D1, 0xC5E1F2DA, 0x7B1476E8, 0x639E9EC7},
	{0x1CA16020, 0x6AD007DF, 0xC9FBB670, 0xD6565FD9, 0x60EE6858, 0x5A43239C, 0xD14B0578, 0xB943377B} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 297 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 298 a1");
	}
	{
		static const fp2_t var_a =  { {0x374BE6A5, 0xA70D2E8C, 0xD432A832, 0x9082A71C, 0x2A5B7760, 0x45D64003, 0xCD1B0D7E, 0x2BEAA0EC},
	{0x0411B817, 0x5FAE3042, 0xA6D2E93C, 0xDE8AA456, 0x6D57BD3F, 0x1190E626, 0xE360D59F, 0x5E39F459} } ;
		static const bigint_t var_b = {0x66F00B2A, 0xCD05E32A, 0x61DABE24, 0xFDB1390E, 0xE34E4A60, 0xB30C3594, 0x71C0090C, 0xAFA2F73B};
		static const fp2_t var_expected =  { {0x9BD037EE, 0x031EE2A8, 0xA1CD94BC, 0xB9FEA0CA, 0x0F6AAACE, 0x7D72717D, 0xD1175BF8, 0x5523A11A},
	{0xDE76A3E8, 0x0F12152D, 0x35DB5A1F, 0xDC671D67, 0xB3D02FA2, 0x0583F534, 0x394E5BE6, 0x58178FF2} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 299 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 300 a1");
	}
	{
		static const fp2_t var_a =  { {0x0308C5CD, 0x22A6E8AF, 0xDC3276B6, 0x5B097AC5, 0x0EA64E2D, 0xA50F8B76, 0x82B369E3, 0x39E0B2DF},
	{0x6968F0A4, 0xDFC8B215, 0x8B8B4A69, 0xCE0E3E54, 0xED4269F8, 0x6619277B, 0xC086C105, 0x37F47739} } ;
		static const bigint_t var_b = {0xA8AF895A, 0x5B1A6302, 0xE343D751, 0xBE3FF3E1, 0xE048C8C7, 0x159620CE, 0xBCF1AFA9, 0xE98B9106};
		static const fp2_t var_expected =  { {0x776E2502, 0x2EB03BA0, 0x18CB3EEF, 0xC927F11E, 0xC5AC95CB, 0x1F842A0B, 0x3DE507D1, 0x9A240103},
	{0x232B291B, 0x1A305B0B, 0xB2FB5D57, 0xC607DF76, 0x5E925835, 0x6574675B, 0x22D57F5C, 0x6D4145B4} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 301 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 302 a1");
	}
	{
		static const fp2_t var_a =  { {0xCF83F33B, 0x4480B79B, 0xD03B7195, 0x9FE5B708, 0x1E5F102B, 0xEC3B9274, 0x6AE9EA75, 0x099AE991},
	{0xF4E3219B, 0x1AED0B8C, 0x8C13C2F8, 0xC1E69CD5, 0x8D7BB598, 0xB238B367, 0xA26B4662, 0x3C14CD47} } ;
		static const bigint_t var_b = {0x1AEF6CD7, 0xADB0C908, 0xF3935585, 0xDD3F5F1B, 0x922B3D7C, 0x3195B28B, 0xE18B0F98, 0x4842030D};
		static const fp2_t var_expected =  { {0x89097100, 0x49F46041, 0x7E50CE36, 0x6D00A3D4, 0xF163285B, 0x620ADF05, 0xFB4D3118, 0x52B57CCE},
	{0x1CBE36AA, 0xE14CA7F1, 0x12EF55A2, 0x099D82D8, 0x319E1E78, 0x8014A170, 0x2F517DE0, 0x15AB4123} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 303 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 304 a1");
	}
	{
		static const fp2_t var_a =  { {0x39145FAF, 0xA8D1A301, 0x89F8B453, 0xF492F2B7, 0x9E003EF2, 0xE5196862, 0x86D171F7, 0x0D0E3FC4},
	{0x968853B1, 0x0660C190, 0x4AAEAC99, 0x81DEE804, 0xF6ED8BFE, 0x4CB72B78, 0xD578D99C, 0x45ADC772} } ;
		static const bigint_t var_b = {0x58432AF3, 0x96253DDB, 0xFF9C4CCD, 0xA3F5636B, 0x906453EA, 0x7B8FA8AC, 0x376F5831, 0x65E43F66};
		static const fp2_t var_expected =  { {0x2D3CCCAD, 0xCFF1BD4F, 0x5A837D9B, 0xB91561B0, 0xB9F88024, 0x1B62CE52, 0xBA91AF0F, 0x40CFBB47},
	{0x2F32F777, 0xC4E17CA1, 0xC514212B, 0x13838CA2, 0x92189A03, 0x29F05924, 0xE7BD8BF1, 0x3758DD3C} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 305 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 306 a1");
	}
	{
		static const fp2_t var_a =  { {0x08E196CB, 0x7D4BBBBB, 0xC257CECA, 0x9B230062, 0x8FF03A9B, 0xA1353D0F, 0xB87BC275, 0x1B8243CA},
	{0xFD75BC43, 0xB0FB4E73, 0xA1344394, 0xA7F3E128, 0x6F511D7A, 0x6B1C83D0, 0xC89342D5, 0x720C65E3} } ;
		static const bigint_t var_b = {0x02D7F43B, 0x7D51632F, 0xD7EEA2F2, 0xCAC8CBA9, 0x335F68E9, 0xBCB49F58, 0x3BEB38B1, 0x0C16E86F};
		static const fp2_t var_expected =  { {0x23C70236, 0x8500D8F1, 0x80973681, 0x009F43F8, 0x213EC0EF, 0x07EE1EFF, 0x7388C88F, 0x0C79C3EE},
	{0x3C76356F, 0x0056C98D, 0x333AF25A, 0xAC860A0A, 0x59CE6BD6, 0x99B40F5B, 0x78D38BB7, 0x788C9785} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 307 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 308 a1");
	}
	{
		static const fp2_t var_a =  { {0x4F3CE2A8, 0x0357B423, 0xBDBD6E75, 0xF289E1E1, 0xE1CB82FF, 0xF7FABE19, 0x08E6E054, 0x2FD962ED},
	{0x066B8FA3, 0xB4EB3453, 0x50C5EF6D, 0x7A841616, 0xFEFF7572, 0x8AFAEF7E, 0xCE8026C0, 0x40F72A2F} } ;
		static const bigint_t var_b = {0x3E503B59, 0xDA9330F7, 0x33E01C96, 0x01856F11, 0x1B126E75, 0x8F3212C7, 0x0B30829F, 0xBF471796};
		static const fp2_t var_expected =  { {0x838B445C, 0x852B0C31, 0x91D29475, 0x99353B10, 0x5EFA1F40, 0x655F9046, 0xCF83C657, 0x448AF256},
	{0x8A37ABFE, 0x82C3AFCC, 0x4C31A263, 0xD698D963, 0xFE3616CD, 0x5666763B, 0x277D74E3, 0x7E6E03FB} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 309 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 310 a1");
	}
	{
		static const fp2_t var_a =  { {0x5D0B9A2D, 0x105516B0, 0x81DE902D, 0xA304717E, 0x9D9AF6E3, 0x237EA5F2, 0x23A1CD74, 0x0602C772},
	{0xAB5FACDD, 0xC5E1773F, 0x244F698F, 0x2026670E, 0x9A54B6A7, 0xFC9D746C, 0x9F363ACE, 0x2A80570E} } ;
		static const bigint_t var_b = {0x3246FCA5, 0xBDAE7235, 0x2AA8EFE7, 0x6AE9A350, 0xAA1C4B96, 0xE357F38E, 0xEBCFE475, 0x334EDFE4};
		static const fp2_t var_expected =  { {0x904D45D7, 0xDC077754, 0xCED75329, 0x28DE6D29, 0x4F56BF8E, 0x40C7DEEF, 0x2582985B, 0x676903FD},
	{0xEDD7BB10, 0xF62E9C0F, 0xC2B57AA3, 0x59326406, 0xFCD32E88, 0xAFD58CCF, 0x8FC13A4A, 0x1744084A} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 311 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 312 a1");
	}
	{
		static const fp2_t var_a =  { {0x42627CED, 0x8F69FED1, 0x4687D962, 0x281E225C, 0x6A1D1342, 0x37856ABB, 0xD601CBDA, 0x9EF4DE8E},
	{0x8C58FCD1, 0x28D099BB, 0x790A4195, 0x2114F7CD, 0xA828B610, 0x6E10CAE1, 0xD6C12267, 0x217E71E8} } ;
		static const bigint_t var_b = {0x8D46D816, 0x4672D5F5, 0xBB87D358, 0x1D88F826, 0x85743F81, 0x7E88C860, 0xC2505B7C, 0xD049A0C7};
		static const fp2_t var_expected =  { {0xA3EDF400, 0x6FB86087, 0xAEBF5A86, 0x6D611C31, 0x11F65622, 0x45890FAF, 0x50CB88F2, 0x49C30146},
	{0xAE77FC68, 0x72726E71, 0x379EB1E4, 0x6F1B008F, 0x52182096, 0x0B350BCC, 0xF8B26BF7, 0xB3E4AA40} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 313 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 314 a1");
	}
	{
		static const fp2_t var_a =  { {0x39A1F84C, 0xFDC16590, 0x2CCF8317, 0xA6514E4B, 0xAE16DF3C, 0x9055018D, 0xD6FE3A9F, 0x54761761},
	{0x53AF1943, 0x3620D2EA, 0xE3592F9A, 0x454AC37F, 0x24529C43, 0x4DD16F63, 0xB2C8F374, 0xB5BB84CC} } ;
		static const bigint_t var_b = {0xFD6A0767, 0x2B385F50, 0x4603CBA5, 0xA5F595EC, 0x19A31329, 0x76005DAF, 0x9BCD1836, 0x33DEAA49};
		static const fp2_t var_expected =  { {0x42922004, 0x6DCE6C6A, 0x71ACD31E, 0xD9B2FE7D, 0x60102195, 0xB9EB802E, 0x2CDC64A3, 0x71DE0050},
	{0xC02CB925, 0xC9D1D2CE, 0xBAF6EFE7, 0xE91B3A61, 0x1FBB9498, 0xBC6BEEE9, 0x3AAE294F, 0xA80FBE73} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 315 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 316 a1");
	}
	{
		static const fp2_t var_a =  { {0x9E835C88, 0xED443FE3, 0x5F21CED5, 0x2466A596, 0xC02E8D9B, 0x62E282F1, 0x3905C562, 0x826D4089},
	{0x6242C2E3, 0xDEB73C7C, 0x5DB5610C, 0x56DF2818, 0xD45FFF40, 0x78AF315D, 0x18687075, 0x4C3F8AAA} } ;
		static const bigint_t var_b = {0xB87E98CB, 0x372FA30D, 0x112C15BA, 0x8048C97A, 0x129318F2, 0xB8676E24, 0x27A811AF, 0xADB9DA12};
		static const fp2_t var_expected =  { {0x1A699F95, 0x81302A4D, 0xBB5DD5F9, 0x3B040476, 0x2818FC64, 0x2E81063E, 0x82EB853D, 0x4934FEF6},
	{0x4593F654, 0x3C306389, 0xE027CAB6, 0x3FB970DB, 0x386789FF, 0x00E129F8, 0x1E469142, 0x53579C2E} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 317 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 318 a1");
	}
	{
		static const fp2_t var_a =  { {0xD2A2F78C, 0x83BCE034, 0x72AE3AB2, 0x1E6F862F, 0xBAD321C7, 0x33B1E45A, 0x3B798E83, 0xB5EDBF88},
	{0xC69409C1, 0x238D1029, 0x448A6DBC, 0x4A0765E3, 0xBEC6429D, 0x92A669AC, 0x4D4AE022, 0x306E4BE9} } ;
		static const bigint_t var_b = {0xF5B39F88, 0xC7762766, 0xC5F90015, 0xA1E88A80, 0xE3ED3D17, 0x8435F0CF, 0x384A7488, 0xC36C173A};
		static const fp2_t var_expected =  { {0x415BAFCF, 0x29C146DB, 0x5E8859FF, 0x0E46DB06, 0x445BE509, 0x9E5BB96A, 0x3DE36F5C, 0x25394300},
	{0xDC8849CF, 0x30B28C5B, 0xED32643A, 0x67B42515, 0xA128AD99, 0x452727C3, 0x5D64463E, 0xB88CBFD1} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 319 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 320 a1");
	}
	{
		static const fp2_t var_a =  { {0xB95B5BF2, 0xFBE1C0F2, 0xD975E41F, 0x010CC1CB, 0xFAC6E7B9, 0x612DF5F6, 0xBC277A30, 0x2E7F8690},
	{0xB5D99FC3, 0x979CBE99, 0xD9F4ACEC, 0xC6C26E0F, 0xA89504BB, 0x871DDE46, 0x7ED23B39, 0x0ABFC780} } ;
		static const bigint_t var_b = {0x72E93AB8, 0x4E0ABD74, 0xF1B397AB, 0xF0AE0E59, 0x4309C57D, 0xEDE3C3C9, 0x45F7A7C8, 0xAE91E9DE};
		static const fp2_t var_expected =  { {0x3F949DCB, 0xF74CFF4E, 0x19EEA415, 0xECF533D6, 0xA88B0539, 0xAAAAF7C9, 0xE25C3A24, 0x996C2F03},
	{0xF5275830, 0xF57ECCAB, 0x697B8CF7, 0x60D29026, 0x611D3565, 0x44C432FD, 0x9341F8E2, 0x96E40E7A} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 321 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 322 a1");
	}
	{
		static const fp2_t var_a =  { {0x3A4492D4, 0x2139916F, 0x6E5F7D9E, 0xB1F7391F, 0xA33A833E, 0x9BCB96E1, 0xBFC79F44, 0x61B65126},
	{0x3AE95FAD, 0xE968C2DA, 0x6DDB9BFB, 0xDC2A0C45, 0x51F60277, 0x343B52D4, 0xBA13E999, 0x24FD2C6F} } ;
		static const bigint_t var_b = {0xEE7F915F, 0xD07CC748, 0x846B54A0, 0xC654ABFD, 0xAC64563D, 0x5BF3037F, 0xEBADA731, 0xDA43924A};
		static const fp2_t var_expected =  { {0x0C2A0501, 0x0A4B93DA, 0x32C12006, 0x898B4BBD, 0xA3145178, 0x75A6DAF7, 0xBF0BF253, 0x09B17897},
	{0xF38C50ED, 0xDAAE96A0, 0xFD073C2C, 0x09A7E044, 0xFE2AED80, 0xB7424BB0, 0x653479DD, 0x99A58DF0} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 323 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 324 a1");
	}
	{
		static const fp2_t var_a =  { {0xC43035CA, 0xD8BB7165, 0xEE64EB6C, 0x04E88066, 0x1B7F2977, 0x64FD17B4, 0xEA8B91F2, 0x771B6BC1},
	{0x17D8D3A9, 0x549ED141, 0x89559966, 0x99B8E736, 0x886116AC, 0xAA08AB64, 0xF4C89B58, 0x13B36A19} } ;
		static const bigint_t var_b = {0xAEBF3592, 0x6984B212, 0x55845EA5, 0x7433A7A7, 0xDCB67F02, 0x0ABE3F1D, 0x6819CF36, 0x6AE75220};
		static const fp2_t var_expected =  { {0xFCB944AD, 0x76C34814, 0xCAD54D0C, 0x6F4C1F04, 0x928068C6, 0x64105E1A, 0x6ECD2A76, 0x753EFC8C},
	{0xAF705523, 0x3F6466B6, 0x65A0DD2F, 0xCD3E3F01, 0x96F88703, 0xD6829D9C, 0x703D6407, 0xB5E6E0A4} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 325 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 326 a1");
	}
	{
		static const fp2_t var_a =  { {0x639D4E82, 0x9666B2AB, 0xA753DBA6, 0x33ABF8F9, 0x385E3998, 0x9A946926, 0xCBA568FC, 0x134DB32B},
	{0x03DF785A, 0x293EDF38, 0x456F3D72, 0xAF27A224, 0x0E586182, 0xE208C551, 0xC44ACC6A, 0x32FE2B25} } ;
		static const bigint_t var_b = {0xFBCD8DE0, 0xC55513AA, 0x9D4EFD6F, 0xBB53B829, 0x568BE0A9, 0x8A1B467F, 0x20936F99, 0xB040D3E3};
		static const fp2_t var_expected =  { {0x07048BA4, 0x79DC4A9C, 0xBC25397E, 0xEE686EE9, 0xDCB70C43, 0x2B195643, 0x546C395B, 0x5A150658},
	{0x8DD52E4B, 0x214386EE, 0x0D23C0C9, 0x3BBFDD5F, 0xADE34C5E, 0xBDB5F351, 0x1FC9C2F9, 0x6FFA26E3} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 327 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 328 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 329 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 330 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 331 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 332 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 333 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 334 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 335 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 336 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 337 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 338 a1");
	}
	{
		static const fp2_t var_a =  { {0x33B1E633, 0xE32E2665, 0x1A6DDB04, 0xB601DB41, 0x6554FF6D, 0xDA3618AB, 0x8F8EBAF2, 0x75EFF9EF},
	{0x83AF859C, 0x4E738A2A, 0xC5F12299, 0x6EC87E68, 0x12AD1ACE, 0x20F76294, 0x65B1B836, 0x8BF2A29F} } ;
		static const fp2_t var_expected =  { {0x2E7A4E68, 0x1BC0634C, 0xBA0A0442, 0x5D0FD15F, 0xEE8D8A47, 0x212A43BF, 0xB0902136, 0x4423A4D2},
	{0xDE7CAEFF, 0xB07AFF86, 0x0E86BCAD, 0xA4492E38, 0x41356EE6, 0xDA68F9D7, 0xDA6D23F2, 0x2E20FC22} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 339 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 340 a1");
	}
	{
		static const fp2_t var_a =  { {0xA0322AA2, 0xA7CF33AA, 0x79B03A4E, 0x52CD45F4, 0xE06F8B02, 0x3FD45CA8, 0x1A34C339, 0xB7DBD3D3},
	{0x063881AB, 0xDFC83402, 0x34125F68, 0x05B9B3E3, 0xD9169CC2, 0x330113C2, 0x0B9AA98A, 0xB2B49834} } ;
		static const fp2_t var_expected =  { {0xC1FA09F9, 0x571F5606, 0x5AC7A4F8, 0xC04466AC, 0x7372FEB2, 0xBB8BFFC2, 0x25EA18EF, 0x0237CAEF},
	{0x5BF3B2F0, 0x1F2655AF, 0xA0657FDE, 0x0D57F8BD, 0x7ACBECF3, 0xC85F48A8, 0x3484329E, 0x075F068E} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 341 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 342 a1");
	}
	{
		static const fp2_t var_a =  { {0x7485F281, 0xC0F2191B, 0x98152A3B, 0xDE695F2C, 0x0AA8E33E, 0x883A56B9, 0xF6A9F2A8, 0xA98997F8},
	{0x0CC0FB3E, 0x65877BE6, 0x97680B6A, 0x53650B79, 0xB0CFD7D9, 0xE683A5D0, 0x42D7379F, 0x01AFFC04} } ;
		static const fp2_t var_expected =  { {0xEDA6421A, 0x3DFC7095, 0x3C62B50B, 0x34A84D74, 0x4939A676, 0x732605B2, 0x4974E980, 0x108A06C9},
	{0x556B395D, 0x99670DCB, 0x3D0FD3DC, 0xBFACA127, 0xA312B1DB, 0x14DCB69A, 0xFD47A489, 0xB863A2BD} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 343 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 344 a1");
	}
	{
		static const fp2_t var_a =  { {0xBAA3B82A, 0xBBE844AD, 0x17DB2EA8, 0xDC7F0AB3, 0x5D586D1F, 0x737BBE83, 0xB5F6E1B1, 0x7F531C4B},
	{0xE3A1C249, 0x0A715B09, 0x2A6B1EB1, 0xB454A8AF, 0x2D70C90D, 0x874E84E3, 0x7CAEBAA0, 0x7BAB1B93} } ;
		static const fp2_t var_expected =  { {0xA7887C71, 0x43064503, 0xBC9CB09E, 0x3692A1ED, 0xF68A1C95, 0x87E49DE7, 0x8A27FA77, 0x3AC08276},
	{0x7E8A7252, 0xF47D2EA7, 0xAA0CC095, 0x5EBD03F1, 0x2671C0A7, 0x7411D788, 0xC3702188, 0x3E68832E} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 345 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 346 a1");
	}
	{
		static const fp2_t var_a =  { {0xB91B3C70, 0x673FBAE9, 0xD7298F5E, 0x13E3688B, 0x92AC6F57, 0xFB919B79, 0x26E72CB8, 0xAE8AC85C},
	{0xCF03D729, 0x3E53A147, 0x74B9ED92, 0x55FBDF02, 0x2CDBE4C9, 0xC2BBD08B, 0xE9F71D19, 0x0797CC55} } ;
		static const fp2_t var_expected =  { {0xA910F82B, 0x97AECEC7, 0xFD4E4FE8, 0xFF2E4414, 0xC1361A5D, 0xFFCEC0F1, 0x1937AF6F, 0x0B88D666},
	{0x93285D72, 0xC09AE869, 0x5FBDF1B4, 0xBD15CD9E, 0x2706A4EB, 0x38A48BE0, 0x5627BF0F, 0xB27BD26C} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 347 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 348 a1");
	}
	{
		static const fp2_t var_a =  { {0x9A731BD3, 0xD0A35915, 0x25AC82A4, 0x75D14FF9, 0x4D4D9E75, 0x63D1AFCA, 0x1BFFD443, 0x31B39EEC},
	{0xDB2D6770, 0xAD2C8189, 0x88D0C9D9, 0xEEB4F8FE, 0x1AA58F89, 0x6E4BA014, 0xFB666B27, 0xB3A0837E} } ;
		static const fp2_t var_expected =  { {0xC7B918C8, 0x2E4B309B, 0xAECB5CA2, 0x9D405CA7, 0x0694EB3F, 0x978EACA1, 0x241F07E5, 0x885FFFD6},
	{0x86FECD2B, 0x51C20827, 0x4BA7156D, 0x245CB3A2, 0x393CFA2B, 0x8D14BC57, 0x44B87101, 0x06731B43} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 349 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 350 a1");
	}
	{
		static const fp2_t var_a =  { {0x4B972F23, 0x405867C8, 0xE0F97D98, 0x7F98BE96, 0xC46023F2, 0x1C9AE8A0, 0xA7256BB4, 0x2B3BB93D},
	{0xEF36BD3B, 0x4452AC3F, 0xE9C8E5BB, 0x64BF371A, 0x51384A95, 0xAA8D1498, 0x23FE912E, 0x152256ED} } ;
		static const fp2_t var_expected =  { {0x16950578, 0xBE9621E9, 0xF37E61AE, 0x9378EE09, 0x8F8265C2, 0xDEC573CA, 0x98F97074, 0x8ED7E584},
	{0x72F57760, 0xBA9BDD71, 0xEAAEF98B, 0xAE527585, 0x02AA3F1F, 0x50D347D3, 0x1C204AFA, 0xA4F147D5} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 351 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 352 a1");
	}
	{
		static const fp2_t var_a =  { {0xAEAC4D81, 0x48B82412, 0x2BF058C8, 0x7D3A25EF, 0x7439D96F, 0xED5F37CB, 0x987C064C, 0xA4FB27AE},
	{0x34C26A92, 0x302E37C5, 0x56DDDFDC, 0xDC9B71D2, 0x6947D8E6, 0xD153F728, 0x123E7AA6, 0x0104E729} } ;
		static const fp2_t var_expected =  { {0xB37FE71A, 0xB636659E, 0xA887867E, 0x95D786B1, 0xDFA8B045, 0x0E01249F, 0xA7A2D5DC, 0x15187713},
	{0x2D69CA09, 0xCEC051EC, 0x7D99FF6A, 0x36763ACE, 0xEA9AB0CE, 0x2A0C6542, 0x2DE06182, 0xB90EB799} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 353 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 354 a1");
	}
	{
		static const fp2_t var_a =  { {0x0E338046, 0xB565A5AA, 0xE701DAEE, 0x355777DC, 0x16E50383, 0xD5E31A13, 0xC08B216F, 0x104450D8},
	{0x148F4491, 0xDF0F895F, 0xD17ACE03, 0xBB5E6128, 0x3B5DA3BD, 0x81804DDE, 0xB8356282, 0x8E0EE94A} } ;
		static const fp2_t var_expected =  { {0x53F8B455, 0x4988E407, 0xED760458, 0xDDBA34C3, 0x3CFD8631, 0x257D4258, 0x7F93BAB9, 0xA9CF4DE9},
	{0x4D9CF00A, 0x1FDF0052, 0x02FD1143, 0x57B34B78, 0x1884E5F7, 0x79E00E8D, 0x87E979A6, 0x2C04B577} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 355 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 356 a1");
	}
	{
		static const fp2_t var_a =  { {0x1893DFFF, 0x901DEEED, 0xB2425FD8, 0xE5801D38, 0x9FB775DE, 0x05FFB6FE, 0xF0466D59, 0x522569F4},
	{0x3809624F, 0xFCFBDF59, 0x9B50B1AE, 0xA6FF73DF, 0xE06CE150, 0x97D73D29, 0x46925D26, 0x0F39D502} } ;
		static const fp2_t var_expected =  { {0x4998549C, 0x6ED09AC4, 0x22357F6E, 0x2D918F68, 0xB42B13D6, 0xF560A56C, 0x4FD86ECF, 0x67EE34CD},
	{0x2A22D24C, 0x01F2AA58, 0x39272D98, 0x6C1238C1, 0x7375A864, 0x63891F41, 0xF98C7F02, 0xAAD9C9BF} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 357 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 358 a1");
	}
	{
		static const fp2_t var_a =  { {0x711F1FE8, 0x2A204822, 0x6F417B6F, 0x98E8C444, 0x4BE71EAB, 0x04149087, 0xBA188523, 0x31111465},
	{0x88D82001, 0x757C6849, 0x356046A4, 0x82A90787, 0xB1617F98, 0x2FCE4BB2, 0x2FAFF9FC, 0x1AFAD486} } ;
		static const fp2_t var_expected =  { {0xF10D14B3, 0xD4CE418E, 0x653663D7, 0x7A28E85C, 0x07FB6B09, 0xF74BCBE4, 0x86065705, 0x89028A5C},
	{0xD954149A, 0x89722167, 0x9F1798A2, 0x9068A519, 0xA2810A1C, 0xCB9210B8, 0x106EE22C, 0x9F18CA3C} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 359 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 360 a1");
	}
	{
		static const fp2_t var_a =  { {0x83607C81, 0x0E57E6FE, 0x96C620F3, 0xE662FB08, 0xE8F31C05, 0x8D9EE167, 0xED169EE5, 0x9DEF7737},
	{0x2D712C23, 0x7870E9C6, 0x600D43E5, 0x740A1F92, 0x48AFCF65, 0xA85AE63A, 0x22A605FE, 0x8397E044} } ;
		static const fp2_t var_expected =  { {0xDECBB81A, 0xF096A2B2, 0x3DB1BE53, 0x2CAEB198, 0x6AEF6DAF, 0x6DC17B03, 0x53083D43, 0x1C24278A},
	{0x34BB0878, 0x867D9FEB, 0x746A9B61, 0x9F078D0E, 0x0B32BA4F, 0x53057631, 0x1D78D62A, 0x367BBE7E} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 361 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 362 a1");
	}
	{
		static const fp2_t var_a =  { {0x96C6239C, 0x0A7A89EE, 0x058D8B6D, 0x955D9B28, 0x2FCBF9D9, 0x9D236ED8, 0x5C80F4D7, 0x090CBE2E},
	{0x91A389B6, 0x71DC032B, 0x1C2EF19D, 0xE1A38802, 0x7DE1FC44, 0x9DC44A40, 0x105F7EB7, 0x6076119E} } ;
		static const fp2_t var_expected =  { {0xCB6610FF, 0xF473FFC2, 0xCEEA53D9, 0x7DB41178, 0x24168FDB, 0x5E3CED93, 0xE39DE751, 0xB106E093},
	{0xD088AAE5, 0x8D128685, 0xB848EDA9, 0x316E249E, 0xD6008D70, 0x5D9C122A, 0x2FBF5D71, 0x599D8D24} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 363 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 364 a1");
	}
	{
		static const fp2_t var_a =  { {0x356652AD, 0x2BCE73B6, 0xDFC94FFD, 0xA9413A90, 0x193B6AA5, 0x6F6147EA, 0x17EA0591, 0x2C79FD3B},
	{0x5D2CA6D6, 0x0CBA061A, 0xAC1A30F9, 0x6E1A7A6C, 0x6A2C40E0, 0xED74BB5C, 0x2CA09EA9, 0x066B281A} } ;
		static const fp2_t var_expected =  { {0x2CC5E1EE, 0xD32015FB, 0xF4AE8F49, 0x69D0720F, 0x3AA71F0F, 0x8BFF1481, 0x2834D697, 0x8D99A187},
	{0x04FF8DC5, 0xF2348397, 0x285DAE4D, 0xA4F73234, 0xE9B648D4, 0x0DEBA10E, 0x137E3D7F, 0xB3A876A8} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 365 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 366 a1");
	}
	{
		static const fp2_t var_a =  { {0xC65C9306, 0xBF075C68, 0xB0C48DBA, 0x54B23151, 0x8A9F3D39, 0x86BEB2BF, 0x2F30B704, 0x404C9C5C},
	{0x79446C32, 0x38C856EC, 0x8FBDD9F5, 0x00869F57, 0x66FCDBDD, 0xB3C50AA4, 0xE51D1307, 0x090948C9} } ;
		static const fp2_t var_expected =  { {0x9BCFA195, 0x3FE72D48, 0x23B3518C, 0xBE5F7B4F, 0xC9434C7B, 0x74A1A9AB, 0x10EE2524, 0x79C70266},
	{0xE8E7C869, 0xC62632C4, 0x44BA0551, 0x128B0D49, 0xECE5ADD8, 0x479B51C6, 0x5B01C921, 0xB10A55F8} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 367 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 368 a1");
	}
	{
		static const fp2_t var_a =  { {0x7839BA6F, 0x4EC0B5DE, 0x973E46B0, 0x5532A55F, 0xF8DDC655, 0x93FE0BD5, 0xF52147BD, 0xA8541F43},
	{0x0F315A31, 0x215B6A40, 0x88A38B9F, 0xBBC19E42, 0x0C86DA71, 0x4DD27978, 0xEC8A522A, 0x40F3E2C8} } ;
		static const fp2_t var_expected =  { {0xE9F27A2C, 0xB02DD3D2, 0x3D399896, 0xBDDF0741, 0x5B04C35F, 0x67625095, 0x4AFD946B, 0x11BF7F7E},
	{0x52FADA6A, 0xDD931F71, 0x4BD453A7, 0x57500E5E, 0x475BAF43, 0xAD8DE2F3, 0x539489FE, 0x791FBBF9} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 369 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 370 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 371 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 372 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 373 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 374 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 375 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 376 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 377 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 378 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 379 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 380 a1");
	}
	{
		static const fp2_t var_a =  { {0x6DDB5251, 0xAAFAE90A, 0xF6D37A9A, 0x38C966D4, 0x201E8487, 0x9D4812BD, 0x7A59FF64, 0xAC9C5B7D},
	{0x25A76932, 0x353DCF92, 0xC193F504, 0xF3AA622D, 0xE0740666, 0x5BE78F28, 0xF3893D28, 0x04183F5D} } ;
		static const fp2_t var_expected =  { {0x798A7007, 0x57074863, 0x192F15EE, 0x5E812109, 0xEC5A7F59, 0x3F2FC90E, 0xB49522A0, 0x9F251838},
	{0x4B4ED264, 0x6A7B9F24, 0x8327EA08, 0xE754C45B, 0xC0E80CCD, 0xB7CF1E51, 0xE7127A50, 0x08307EBB} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 381 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 382 a1");
	}
	{
		static const fp2_t var_a =  { {0x30877435, 0xE04FF4FA, 0xEF42C893, 0x01EC9451, 0xFB4F32FF, 0xE45FE3CC, 0xD065DFBE, 0x00752AA2},
	{0x280CFFD1, 0x1F3B76CC, 0x277EE375, 0x72B53633, 0xA4FF5899, 0xB4D20DDE, 0xAB352F46, 0x1E5048AB} } ;
		static const fp2_t var_expected =  { {0x610EE86A, 0xC09FE9F4, 0xDE859127, 0x03D928A3, 0xF69E65FE, 0xC8BFC799, 0xA0CBBF7D, 0x00EA5545},
	{0x5019FFA2, 0x3E76ED98, 0x4EFDC6EA, 0xE56A6C66, 0x49FEB132, 0x69A41BBD, 0x566A5E8D, 0x3CA09157} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 383 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 384 a1");
	}
	{
		static const fp2_t var_a =  { {0x4D4F0E73, 0x3AD5A1BD, 0x8C032AAC, 0x1BC07298, 0x69D3D0AD, 0xDB13354E, 0xC6B7525E, 0x0CAB9AB9},
	{0x032D0D3C, 0xCC48B92C, 0x3839DF49, 0x1CE64970, 0xB01653ED, 0x73D30427, 0x859E7428, 0x254CFF0D} } ;
		static const fp2_t var_expected =  { {0x9A9E1CE6, 0x75AB437A, 0x18065558, 0x3780E531, 0xD3A7A15A, 0xB6266A9C, 0x8D6EA4BD, 0x19573573},
	{0x065A1A78, 0x98917258, 0x7073BE93, 0x39CC92E0, 0x602CA7DA, 0xE7A6084F, 0x0B3CE850, 0x4A99FE1B} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 385 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 386 a1");
	}
	{
		static const fp2_t var_a =  { {0xCDF120EB, 0x462F4CD0, 0x6E78039A, 0x0C22366F, 0xE48D45AD, 0x3D873EEF, 0xEF39F66C, 0x0790F85C},
	{0x18C432E5, 0x6B51A783, 0x0E887F70, 0xF2220241, 0xF4E9CBEA, 0xFE69FB97, 0xB1D03446, 0x78E437C4} } ;
		static const fp2_t var_expected =  { {0x9BE241D6, 0x8C5E99A1, 0xDCF00734, 0x18446CDE, 0xC91A8B5A, 0x7B0E7DDF, 0xDE73ECD8, 0x0F21F0B9},
	{0xCF5C312F, 0xD7B4C554, 0x48991F99, 0xD13257E1, 0x95F10E20, 0x01739AC4, 0x23818C65, 0x37B4D0C7} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 387 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 388 a1");
	}
	{
		static const fp2_t var_a =  { {0xD33C0A64, 0xD4734616, 0xF886ABAF, 0x60E3BD78, 0x2983E3A5, 0x17AA9F18, 0x5B4195E4, 0x382A67DE},
	{0xD3C5BFF5, 0x69C40B97, 0xAA13A825, 0x57C672BF, 0x4D06AABF, 0xF2A6E6B6, 0x2066ED0A, 0x2CB80746} } ;
		static const fp2_t var_expected =  { {0xA67814C8, 0xA8E68C2D, 0xF10D575F, 0xC1C77AF1, 0x5307C74A, 0x2F553E30, 0xB6832BC8, 0x7054CFBC},
	{0xA78B7FEA, 0xD388172F, 0x5427504A, 0xAF8CE57F, 0x9A0D557E, 0xE54DCD6C, 0x40CDDA15, 0x59700E8C} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 389 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 390 a1");
	}
	{
		static const fp2_t var_a =  { {0x6F55A685, 0xEC4A451B, 0x9E55760D, 0x66CFBA29, 0x8150224C, 0x95C4FFDF, 0x1BD14535, 0x3A590337},
	{0x9DE6E4F9, 0x7260E307, 0xF575A973, 0x17F39D3E, 0x76E93EB0, 0x24FFFFDF, 0x8595A22F, 0x0C7CECB7} } ;
		static const fp2_t var_expected =  { {0xDEAB4D0A, 0xD8948A36, 0x3CAAEC1B, 0xCD9F7453, 0x02A04498, 0x2B89FFBF, 0x37A28A6B, 0x74B2066E},
	{0x3BCDC9F2, 0xE4C1C60F, 0xEAEB52E6, 0x2FE73A7D, 0xEDD27D60, 0x49FFFFBE, 0x0B2B445E, 0x18F9D96F} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 391 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 392 a1");
	}
	{
		static const fp2_t var_a =  { {0xE4B7CD0C, 0xE0C8720E, 0x6E56D019, 0x1AECDFA7, 0xD46A2280, 0x42A8901A, 0x80D99A89, 0x1BEF329C},
	{0x64840D44, 0x715137A2, 0x6F6B48A4, 0x189B64C8, 0xCDFE2F03, 0xB1967E68, 0x4FC5C25C, 0xAB00AA22} } ;
		static const fp2_t var_expected =  { {0xC96F9A18, 0xC190E41D, 0xDCADA033, 0x35D9BF4E, 0xA8D44500, 0x85512035, 0x01B33512, 0x37DE6539},
	{0x66DBE5ED, 0xE3B3E593, 0x0A5EB201, 0x1E251CF0, 0x4819D451, 0x67CCA066, 0x5F6CA890, 0x9BEDB582} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 393 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 394 a1");
	}
	{
		static const fp2_t var_a =  { {0x60577A30, 0x3930A664, 0x875C6CBA, 0x37DA4FBC, 0x99F69DF1, 0xD21F1E84, 0xDB1C5AA1, 0x403346B6},
	{0x8A2C21C0, 0x97F6C219, 0x33E3A638, 0x57CFBDE8, 0x41395F2B, 0xFD1016CA, 0xB09B9EAC, 0x6B78D88F} } ;
		static const fp2_t var_expected =  { {0xC0AEF460, 0x72614CC8, 0x0EB8D974, 0x6FB49F79, 0x33ED3BE2, 0xA43E3D09, 0xB638B543, 0x80668D6D},
	{0xB22C0EE5, 0x30FEFA81, 0x934F6D2A, 0x9C8DCF2F, 0x2E9034A1, 0xFEBFD129, 0x21186130, 0x1CDE125D} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 395 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 396 a1");
	}
	{
		static const fp2_t var_a =  { {0x2C7757DE, 0xC57A55B1, 0xC9FD8895, 0x856B1740, 0x878AA6C3, 0x3EFF09F2, 0xFD0148EC, 0x1B685368},
	{0xDA0EBFB7, 0x4E62CB4D, 0x1466EE4F, 0x4D6A9BEB, 0xFF093A81, 0xA34597FF, 0xD8AA51C8, 0x1A34C2DF} } ;
		static const fp2_t var_expected =  { {0x58EEAFBC, 0x8AF4AB62, 0x93FB112B, 0x0AD62E81, 0x0F154D87, 0x7DFE13E5, 0xFA0291D8, 0x36D0A6D1},
	{0xB41D7F6E, 0x9CC5969B, 0x28CDDC9E, 0x9AD537D6, 0xFE127502, 0x468B2FFF, 0xB154A391, 0x346985BF} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 397 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 398 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB39DF0D, 0x931EE474, 0xD9A2C5CC, 0xCCFC600A, 0x9CAC099A, 0xD3F39DBF, 0x38AE362C, 0x341BE970},
	{0xFEDAAD76, 0x456DC040, 0x5547837D, 0xA0174B89, 0x2168F941, 0x7E8CA53E, 0xF9031234, 0x0F9FDD4B} } ;
		static const fp2_t var_expected =  { {0x5673BE1A, 0x263DC8E9, 0xB3458B99, 0x99F8C015, 0x39581335, 0xA7E73B7F, 0x715C6C59, 0x6837D2E0},
	{0xFDB55AEC, 0x8ADB8081, 0xAA8F06FA, 0x402E9712, 0x42D1F283, 0xFD194A7C, 0xF2062468, 0x1F3FBA97} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 399 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 400 a1");
	}
	{
		static const fp2_t var_a =  { {0x2EEC05AF, 0xED387900, 0x6A45AA32, 0xA27052E8, 0x60485CCD, 0xFC13DDED, 0xDB43518F, 0x693FBA1B},
	{0x7D501F25, 0x688693CE, 0xA0B519C8, 0x20A4F42E, 0xAB5FCD0D, 0xB18E30B1, 0x434813EE, 0x238FF818} } ;
		static const fp2_t var_expected =  { {0xFBABD6C3, 0xDB82684E, 0x0013751E, 0x31CEF930, 0x6CAE2FE6, 0xFCC75F6F, 0x7667C6F6, 0x186BD575},
	{0xFAA03E4A, 0xD10D279C, 0x416A3390, 0x4149E85D, 0x56BF9A1A, 0x631C6163, 0x869027DD, 0x471FF030} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 401 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 402 a1");
	}
	{
		static const fp2_t var_a =  { {0x35FD50A5, 0x645D6C0F, 0xCB7A318B, 0x3D761728, 0xFDF5D32F, 0x870F1E3A, 0x79228BDD, 0x054A6FAF},
	{0xA4ACFC42, 0xE32D551A, 0x361D8C80, 0x2CA8E9C8, 0x321278CB, 0x89F6151D, 0x2950E0E0, 0x59FCAC30} } ;
		static const fp2_t var_expected =  { {0x6BFAA14A, 0xC8BAD81E, 0x96F46316, 0x7AEC2E51, 0xFBEBA65E, 0x0E1E3C75, 0xF24517BB, 0x0A94DF5E},
	{0x4959F884, 0xC65AAA35, 0x6C3B1901, 0x5951D390, 0x6424F196, 0x13EC2A3A, 0x52A1C1C1, 0xB3F95860} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 403 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 404 a1");
	}
	{
		static const fp2_t var_a =  { {0x9452C38F, 0xC05075BD, 0x2C014CD9, 0xAEF4A6DD, 0x7DB01056, 0x5FFFA9C4, 0xE2E9601A, 0x67CD6FAA},
	{0xB97E28AC, 0x256F5176, 0x9993FDF2, 0xF0225406, 0x9365A750, 0xB47F9ED2, 0xDA0CE473, 0x9A81C6B6} } ;
		static const fp2_t var_expected =  { {0xC6795283, 0x81B261C9, 0x838ABA6C, 0x4AD7A119, 0xA77D96F8, 0xC49EF71D, 0x85B3E40B, 0x15874093},
	{0x10D01CBD, 0x4BF0193C, 0x5EB01C9D, 0xCD32FB6C, 0xD2E8C4EC, 0x6D9EE139, 0x73FAECBE, 0x7AEFEEAB} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 405 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 406 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB3FFC11, 0x12E24A0F, 0x35CA3750, 0xC155B400, 0xDA228721, 0xCF95FF8F, 0x67B58666, 0x15921CB2},
	{0x62C7A30B, 0xDB17FE05, 0x0B13F65F, 0x116E1E32, 0xE8933A81, 0x0E273E20, 0x87A7809B, 0x396796C6} } ;
		static const fp2_t var_expected =  { {0x567FF822, 0x25C4941F, 0x6B946EA0, 0x82AB6800, 0xB4450E43, 0x9F2BFF1F, 0xCF6B0CCD, 0x2B243964},
	{0xC58F4616, 0xB62FFC0A, 0x1627ECBF, 0x22DC3C64, 0xD1267502, 0x1C4E7C41, 0x0F4F0136, 0x72CF2D8D} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 407 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 408 a1");
	}
	{
		static const fp2_t var_a =  { {0x44D0F1E6, 0xA706B950, 0x43B98E6A, 0xBC805C12, 0x510E91F8, 0x53ADF015, 0x5964CD02, 0x05B746A5},
	{0x4F5CACB1, 0xF0991426, 0xB41C2834, 0x9A769572, 0x31CEF771, 0xA999FD66, 0x2277A2B5, 0x40DF541D} } ;
		static const fp2_t var_expected =  { {0x89A1E3CC, 0x4E0D72A0, 0x87731CD5, 0x7900B824, 0xA21D23F1, 0xA75BE02A, 0xB2C99A04, 0x0B6E8D4A},
	{0x9EB95962, 0xE132284C, 0x68385069, 0x34ED2AE5, 0x639DEEE3, 0x5333FACC, 0x44EF456B, 0x81BEA83A} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 409 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 410 a1");
	}
	{
		static const fp2_t var_a =  { {0x8D5D2B2E, 0x07AF7CA8, 0x78B378B7, 0x5D2F0FD5, 0x52DF730F, 0x9D1DF2F7, 0x0AAA030F, 0x98FC23B5},
	{0xA7C648D4, 0x911AABC2, 0x57DEFBE4, 0xB0CE8019, 0x075362A2, 0xE3892820, 0x5C92E8B6, 0x83FDCCF8} } ;
		static const fp2_t var_expected =  { {0xB88E21C1, 0x10706F9F, 0x1CEF1227, 0xA74C730A, 0x51DC5C69, 0x3EDB8983, 0xD53529F6, 0x77E4A8A7},
	{0xED605D0D, 0x2346CDD3, 0xDB461882, 0x4E8B5391, 0xBAC43B90, 0xCBB1F3D4, 0x7906F544, 0x4DE7FB2E} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 411 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 412 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 413 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 414 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB849B8B, 0x052F4595, 0x3679F525, 0x2E9A5FB1, 0x9F3EBDD0, 0xB4210F7D, 0x8904C49E, 0x17645FC6},
	{0x0FD39981, 0x2D4C04E7, 0x4B4CFCFB, 0x92F34FEE, 0x9BEA7CD9, 0x6375C0B8, 0xA6DF6050, 0xA411C995} } ;
		static const fp2_t var_expected =  { {0xAB849B8B, 0x052F4595, 0x3679F525, 0x2E9A5FB1, 0x9F3EBDD0, 0xB4210F7D, 0x8904C49E, 0x17645FC6},
	{0x52589B1A, 0xD1A284CA, 0x892AE24B, 0x801E5CB2, 0xB7F80CDB, 0x97EA9BB2, 0x993F7BD8, 0x1601D52C} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 415 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 416 a1");
	}
	{
		static const fp2_t var_a =  { {0x2750BC7E, 0xAC749218, 0x9DECAD08, 0x376BE1D7, 0x2D9FAB08, 0xD9911B63, 0xE8E66024, 0x36310D7C},
	{0x93FF4828, 0x71DF9F27, 0xA783057A, 0xF8FC2BD8, 0x5BF101F0, 0x015F1165, 0x70C1B408, 0xB254BAA7} } ;
		static const fp2_t var_expected =  { {0x2750BC7E, 0xAC749218, 0x9DECAD08, 0x376BE1D7, 0x2D9FAB08, 0xD9911B63, 0xE8E66024, 0x36310D7C},
	{0x93FF4828, 0x71DF9F27, 0xA783057A, 0xF8FC2BD8, 0x5BF101F0, 0x015F1165, 0x70C1B408, 0xB254BAA7} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 417 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 418 a1");
	}
	{
		static const fp2_t var_a =  { {0x42EB0BC5, 0xEEC2501E, 0x46D8B85E, 0x8D21D759, 0xF30DF393, 0x34CEECA1, 0x77AE8971, 0x3AC4B1D3},
	{0xC4859D4D, 0x1B5A16C2, 0x489C0E29, 0xEAFBFBD2, 0xC7A36123, 0x9F5886B6, 0xD9195B82, 0x2BA9BC1D} } ;
		static const fp2_t var_expected =  { {0x42EB0BC5, 0xEEC2501E, 0x46D8B85E, 0x8D21D759, 0xF30DF393, 0x34CEECA1, 0x77AE8971, 0x3AC4B1D3},
	{0xC4859D4D, 0x1B5A16C2, 0x489C0E29, 0xEAFBFBD2, 0xC7A36123, 0x9F5886B6, 0xD9195B82, 0x2BA9BC1D} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 419 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 420 a1");
	}
	{
		static const fp2_t var_a =  { {0x8A4684BB, 0x2849BF68, 0xE4D9CBCC, 0x65853491, 0x29372780, 0xB05C6074, 0x3085DC0C, 0x5C91CE95},
	{0x337EDE9E, 0x6A613D71, 0xD13C75E6, 0xE01F074D, 0xD60E45C3, 0x23A4A170, 0x001A1209, 0x4A7A9CC6} } ;
		static const fp2_t var_expected =  { {0x8A4684BB, 0x2849BF68, 0xE4D9CBCC, 0x65853491, 0x29372780, 0xB05C6074, 0x3085DC0C, 0x5C91CE95},
	{0x2EAD55FD, 0x948D4C40, 0x033B6960, 0x32F2A553, 0x7DD443F1, 0xD7BBBAFA, 0x4004CA1F, 0x6F9901FC} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 421 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 422 a1");
	}
	{
		static const fp2_t var_a =  { {0xEF25567F, 0x7C979624, 0x7A819E2D, 0xB4D72DCF, 0xD3A0380F, 0x261631D6, 0x46A5D2C1, 0x2DDB2D69},
	{0x1E0FA549, 0xFD784371, 0xBD4D8A2E, 0x1EDEF72A, 0xA7AC85E8, 0x6C08C4F6, 0x730D080F, 0x57C7F24E} } ;
		static const fp2_t var_expected =  { {0xEF25567F, 0x7C979624, 0x7A819E2D, 0xB4D72DCF, 0xD3A0380F, 0x261631D6, 0x46A5D2C1, 0x2DDB2D69},
	{0x441C8F52, 0x01764640, 0x172A5518, 0xF432B576, 0xAC3603CC, 0x8F579774, 0xCD11D419, 0x624BAC73} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 423 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 424 a1");
	}
	{
		static const fp2_t var_a =  { {0xBE1A52D4, 0xA663A146, 0x32F86DC5, 0x8D96A27A, 0xE7F64751, 0x9D6D4CC7, 0xA5299B4B, 0xB99E1011},
	{0x51A4602C, 0xB5EB8F41, 0xFC512262, 0xB4625995, 0xAAE0BEB5, 0x48FA7F81, 0xED363BA9, 0x5B929726} } ;
		static const fp2_t var_expected =  { {0xBE1A52D4, 0xA663A146, 0x32F86DC5, 0x8D96A27A, 0xE7F64751, 0x9D6D4CC7, 0xA5299B4B, 0xB99E1011},
	{0x51A4602C, 0xB5EB8F41, 0xFC512262, 0xB4625995, 0xAAE0BEB5, 0x48FA7F81, 0xED363BA9, 0x5B929726} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 425 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 426 a1");
	}
	{
		static const fp2_t var_a =  { {0xBFD828B8, 0x8D8690F6, 0x8CEB9A6B, 0x1F330844, 0xF5C98D55, 0x4626C3FB, 0x110C329A, 0x08E770F1},
	{0x2A9C3E60, 0x2AB19CC9, 0x2C9A97B4, 0xAF3E9748, 0x30BD6F5A, 0x6383901F, 0x71E650F8, 0x20E6719F} } ;
		static const fp2_t var_expected =  { {0xBFD828B8, 0x8D8690F6, 0x8CEB9A6B, 0x1F330844, 0xF5C98D55, 0x4626C3FB, 0x110C329A, 0x08E770F1},
	{0x378FF63B, 0xD43CECE8, 0xA7DD4792, 0x63D31558, 0x23251A5A, 0x97DCCC4C, 0xCE388B30, 0x992D2D22} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 427 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 428 a1");
	}
	{
		static const fp2_t var_a =  { {0x92AA438A, 0xC7DB4406, 0x894D8415, 0xEBA474EA, 0x9EAE1527, 0x8D8C5CE5, 0x9A79995D, 0x0135B9DE},
	{0x3BC8746F, 0x359F1CBA, 0x676C9455, 0x006A67FA, 0x1EC3C3CE, 0xA03A7CBE, 0x64111E5E, 0x11E1E007} } ;
		static const fp2_t var_expected =  { {0x92AA438A, 0xC7DB4406, 0x894D8415, 0xEBA474EA, 0x9EAE1527, 0x8D8C5CE5, 0x9A79995D, 0x0135B9DE},
	{0x2663C02C, 0xC94F6CF7, 0x6D0B4AF1, 0x12A744A6, 0x351EC5E7, 0x5B25DFAD, 0xDC0DBDCA, 0xA831BEBA} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 429 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 430 a1");
	}
	{
		static const fp2_t var_a =  { {0x705747B4, 0x3D917720, 0xFF69C97F, 0xF5590D11, 0x44EE5F5F, 0xA1882531, 0x1B8F3EA0, 0x32419E09},
	{0x281BB80C, 0x0E9A36F0, 0x50138CA6, 0x04BEDB97, 0xEDD4E1A3, 0x230D64BF, 0xBEF1B074, 0x25B2E3F0} } ;
		static const fp2_t var_expected =  { {0x705747B4, 0x3D917720, 0xFF69C97F, 0xF5590D11, 0x44EE5F5F, 0xA1882531, 0x1B8F3EA0, 0x32419E09},
	{0x3A107C8F, 0xF05452C1, 0x846452A0, 0x0E52D109, 0x660DA812, 0xD852F7AB, 0x812D2BB4, 0x9460BAD1} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 431 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 432 a1");
	}
	{
		static const fp2_t var_a =  { {0xE78D0EAC, 0xA2ABE797, 0x1E75A11A, 0x7A6E8BB1, 0x528CD3F2, 0x3DC48755, 0x0F903E23, 0x09DAD527},
	{0x8C251D76, 0x470DBCC9, 0xF519CE93, 0x0EE29EE7, 0xE5984F75, 0x4D9CE53C, 0xE19A9DA7, 0x1A4637AC} } ;
		static const fp2_t var_expected =  { {0xE78D0EAC, 0xA2ABE797, 0x1E75A11A, 0x7A6E8BB1, 0x528CD3F2, 0x3DC48755, 0x0F903E23, 0x09DAD527},
	{0x8C251D76, 0x470DBCC9, 0xF519CE93, 0x0EE29EE7, 0xE5984F75, 0x4D9CE53C, 0xE19A9DA7, 0x1A4637AC} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 433 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 434 a1");
	}
	{
		static const fp2_t var_a =  { {0x162FFE18, 0xB9563C3B, 0x6D575AA5, 0x99697366, 0xD7381617, 0x90C9641A, 0xFC4EF41C, 0x7C080D19},
	{0xE434E231, 0xB1D45B15, 0x4CB7300A, 0x0C48C8C0, 0x2E6C7DEA, 0x7F464267, 0xCB2608A9, 0xA9878524} } ;
		static const fp2_t var_expected =  { {0x162FFE18, 0xB9563C3B, 0x6D575AA5, 0x99697366, 0xD7381617, 0x90C9641A, 0xFC4EF41C, 0x7C080D19},
	{0x7DF7526A, 0x4D1A2E9B, 0x87C0AF3C, 0x06C8E3E0, 0x25760BCB, 0x7C1A1A04, 0x74F8D37F, 0x108C199D} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 435 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 436 a1");
	}
	{
		static const fp2_t var_a =  { {0x8C7F6D21, 0xF9A42569, 0x9F864B38, 0x624125AD, 0xF09EAAEE, 0xD8202A61, 0x5FF35BBF, 0x3F6F09D3},
	{0x47C78DC1, 0x87B5507E, 0x95493D92, 0x0AACAAE6, 0xB8BF4016, 0x3B512587, 0x8E181397, 0x75FEF039} } ;
		static const fp2_t var_expected =  { {0x8C7F6D21, 0xF9A42569, 0x9F864B38, 0x624125AD, 0xF09EAAEE, 0xD8202A61, 0x5FF35BBF, 0x3F6F09D3},
	{0x1A64A6DA, 0x77393933, 0x3F2EA1B4, 0x086501BA, 0x9B23499F, 0xC00F36E3, 0xB206C891, 0x4414AE88} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 437 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 438 a1");
	}
	{
		static const fp2_t var_a =  { {0x203EADFE, 0xDE0ED138, 0x5F3E227D, 0x51904D86, 0x9A224B6E, 0xFE4B132B, 0xB3027642, 0x336C9AE5},
	{0xF86FB077, 0x076BCB83, 0x944A43F6, 0x244DC1EE, 0x8DC7E57A, 0xEE754B5F, 0x4E746D60, 0x60C64535} } ;
		static const fp2_t var_expected =  { {0x203EADFE, 0xDE0ED138, 0x5F3E227D, 0x51904D86, 0x9A224B6E, 0xFE4B132B, 0xB3027642, 0x336C9AE5},
	{0x69BC8424, 0xF782BE2D, 0x402D9B50, 0xEEC3EAB2, 0xC61AA43A, 0x0CEB110B, 0xF1AA6EC8, 0x594D598C} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 439 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 440 a1");
	}
	{
		static const fp2_t var_a =  { {0xCC6A9528, 0x716C230E, 0x144D5CC0, 0xA462D2BE, 0x5D08E423, 0xC0E37828, 0xB511276E, 0x1434DF04},
	{0xE7EF9FF7, 0x696353CD, 0x843D0556, 0x9E6FD96D, 0x27B0A627, 0x22540CAA, 0x10722AA9, 0xABF1D9EC} } ;
		static const fp2_t var_expected =  { {0xCC6A9528, 0x716C230E, 0x144D5CC0, 0xA462D2BE, 0x5D08E423, 0xC0E37828, 0xB511276E, 0x1434DF04},
	{0xE7EF9FF7, 0x696353CD, 0x843D0556, 0x9E6FD96D, 0x27B0A627, 0x22540CAA, 0x10722AA9, 0xABF1D9EC} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 441 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 442 a1");
	}
	{
		static const fp2_t var_a =  { {0xD88072FB, 0x71CEBF50, 0xFA969D9E, 0x4311ED7F, 0xBC59F885, 0x6D26F865, 0xBA64DD19, 0x656082F8},
	{0x379E8A41, 0x4693DD6C, 0x789AA74A, 0x5DA76622, 0x26CD032A, 0xABA6BA77, 0x15AA76D8, 0x044205CB} } ;
		static const fp2_t var_expected =  { {0xD88072FB, 0x71CEBF50, 0xFA969D9E, 0x4311ED7F, 0xBC59F885, 0x6D26F865, 0xBA64DD19, 0x656082F8},
	{0x2A8DAA5A, 0xB85AAC45, 0x5BDD37FC, 0xB56A467E, 0x2D15868A, 0x4FB9A1F4, 0x2A746550, 0xB5D198F7} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 443 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 444 a1");
	}
	{
		static const fp2_t var_a =  { {0xDA6C5F42, 0x99C4DF34, 0xE145FC03, 0x2092ECAA, 0xBC9FFBB8, 0xB6951A5D, 0xC31EB270, 0x156476F9},
	{0x8396ECD2, 0x13D0CCDF, 0x7282F43A, 0x303FFDEE, 0x688549FD, 0x44947634, 0xAE1DBF1D, 0x3A878410} } ;
		static const fp2_t var_expected =  { {0xDA6C5F42, 0x99C4DF34, 0xE145FC03, 0x2092ECAA, 0xBC9FFBB8, 0xB6951A5D, 0xC31EB270, 0x156476F9},
	{0x8396ECD2, 0x13D0CCDF, 0x7282F43A, 0x303FFDEE, 0x688549FD, 0x44947634, 0xAE1DBF1D, 0x3A878410} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 445 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 446 a1");
	}
	{
		static const fp2_t var_a =  { {0x0B0E4A61, 0x84BD2075, 0xF39A7C5E, 0x78F3C94D, 0x1C37F41D, 0x66C71BE6, 0x5A6085E3, 0x1B3E1627},
	{0xD7B85C3B, 0x36C85091, 0x5FAC57E5, 0x02D5F086, 0x26566466, 0x98EF4E31, 0x40D7F4FD, 0x831DA3CD} } ;
		static const fp2_t var_expected =  { {0x0B0E4A61, 0x84BD2075, 0xF39A7C5E, 0x78F3C94D, 0x1C37F41D, 0x66C71BE6, 0x5A6085E3, 0x1B3E1627},
	{0xD7B85C3B, 0x36C85091, 0x5FAC57E5, 0x02D5F086, 0x26566466, 0x98EF4E31, 0x40D7F4FD, 0x831DA3CD} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 447 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 448 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 449 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 450 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 451 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 452 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 453 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 454 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 455 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 456 a1");
	}
	{
		static const fp2_t var_a =  { {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2},
	{0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2} } ;
		static const fp2_t var_expected =  { {0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61},
	{0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 457 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 458 a1");
	}
	{
		static const fp2_t var_a =  { {0x30EB7C66, 0xE8FE5398, 0x1E18EFF5, 0x2C6D5BC4, 0x6F7EF38F, 0x6DBA4474, 0x918436EE, 0x9D48195D},
	{0xB80470B3, 0xD84022E9, 0x80370F1D, 0x65FF7B2B, 0xD207F737, 0x1388F5ED, 0x7626F97D, 0x13F11707} } ;
		static const fp2_t var_expected =  { {0x651CC2DA, 0xB21C9765, 0xA7BCE151, 0x6ACD9213, 0xD1D5CA6E, 0xE17259B2, 0xC7D8D2AF, 0x423F3A46},
	{0x176D1CC7, 0x23A3F223, 0xE633A42F, 0x9C9D5189, 0xB325C645, 0xEDC18AD0, 0xC648F720, 0x9560158D} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 459 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 460 a1");
	}
	{
		static const fp2_t var_a =  { {0xFEEBDFA1, 0x17BBE4E5, 0x48271A70, 0xC87F3F6F, 0x3FCE0F5A, 0xCF698817, 0xCF8920F9, 0xB584FC6D},
	{0x0E9CF227, 0x6AAC6B83, 0x820FE148, 0x4928B74D, 0x4F909B6C, 0x694FEB2A, 0x07201AB4, 0x8C297D60} } ;
		static const fp2_t var_expected =  { {0x2053B5A9, 0x4E00DB27, 0x0F943AF1, 0x8A90C64E, 0xF209C32B, 0xDB6F51FD, 0xD85B6F36, 0x8EE0FE31},
	{0xFA0BEBB0, 0x08EDDC8F, 0x1D2D9AA1, 0x72371340, 0x6859DACC, 0x655225CA, 0x439CC390, 0xA3C69588} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 461 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 462 a1");
	}
	{
		static const fp2_t var_a =  { {0x37FAF4C8, 0x66CC303A, 0xE37F25B3, 0x8D428A0B, 0xA09A1292, 0x3F7C3C4A, 0xEF4FF416, 0x16425380},
	{0x292E57E2, 0xFA22AD2F, 0x6AC8DA8A, 0x5DD8CFEA, 0xFF2198E8, 0xC984C51E, 0xFB1F7E74, 0x07F454AA} } ;
		static const fp2_t var_expected =  { {0xEA2FC382, 0x1F712982, 0x9A0B814D, 0xC2FDCFBD, 0x19AA55A0, 0xAC75DE72, 0xBEB2F2B2, 0xAF5A4EA8},
	{0x1EA76AAE, 0x9CCA2265, 0x5AE8BC32, 0xCFA9CD53, 0xBA1EB187, 0x6B1B7347, 0xDC072296, 0x7C4F54DE} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 463 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 464 a1");
	}
	{
		static const fp2_t var_a =  { {0x6214E409, 0xE2C9864C, 0x10B1974C, 0x80A01CA6, 0x8DFB2022, 0xFBE13DB3, 0x032610B2, 0x75F5AB48},
	{0xD726495F, 0x34FD5458, 0xF6BB9AB7, 0x7FAC7C52, 0xF6213320, 0x00261B63, 0x4441727F, 0x08027C39} } ;
		static const fp2_t var_expected =  { {0xD98EA9DB, 0xF8DA4E5C, 0x7BE5153C, 0xFD180BB4, 0x9DF8AEAA, 0x120F3A2D, 0xF4D66881, 0x683C7825},
	{0xC315394A, 0x3C15FC38, 0xD2C0D5DC, 0x77F1968E, 0x582C9D51, 0x7B5B0C67, 0x00CC0262, 0x61B2BB24} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 465 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 466 a1");
	}
	{
		static const fp2_t var_a =  { {0xE7C1B087, 0xD83963E4, 0x5CDCCE2C, 0xD13D8003, 0xEA171F4F, 0x83B3CDBA, 0x1D22DC93, 0x0D9680BC},
	{0x7AB75A9C, 0x08517099, 0x550FBDDF, 0x48B7239C, 0x3D7CEE16, 0x3FFC4D92, 0x523923CC, 0x39B98A0F} } ;
		static const fp2_t var_expected =  { {0x7D1669BC, 0x27012794, 0xEC5A1FCC, 0x64F15F53, 0x2F27E9F9, 0x4D5FF956, 0x9968321C, 0x2B1B3458},
	{0x979762C6, 0xB45692C2, 0x15AFFAB8, 0x34499BC1, 0x2A61438A, 0x6C06A9FD, 0x1E49B704, 0x96BA6867} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 467 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 468 a1");
	}
	{
		static const fp2_t var_a =  { {0xF67BD934, 0xD307D4B4, 0xE71CF087, 0x41220D9B, 0x291CC3C7, 0x89E69385, 0x8DCD5CCB, 0x4155261B},
	{0xC200DA09, 0x9FBDD1D2, 0x99C857EB, 0x29DBA17F, 0xBE7BF52F, 0xD215EE97, 0xD82D7B29, 0x5AB02610} } ;
		static const fp2_t var_expected =  { {0x4E0D3565, 0xAF6B48CC, 0x9A6A8DFE, 0x0E5C6037, 0x4F9CB48B, 0x8A4E8E03, 0xE18EF5C7, 0xA574292B},
	{0x9FE3AA94, 0x9A032654, 0x86A8C20E, 0x645620C6, 0xFE301DDE, 0x4CB5AD24, 0x019DEE6C, 0x71800A50} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 469 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 470 a1");
	}
	{
		static const fp2_t var_a =  { {0xB08B5DA6, 0xA208DB11, 0x12E9B1A3, 0x5954EEEC, 0x0CFDC8E0, 0x15540CDC, 0x64FC838C, 0x591F1FBC},
	{0xF3086F69, 0x6944B139, 0x47D9AA13, 0x4D153E3A, 0x550D35EB, 0x62F1AC29, 0x04FF57F4, 0x50CD0108} } ;
		static const fp2_t var_expected =  { {0x5A99F68F, 0xF70FE5E7, 0x3E018ED4, 0x55416C74, 0x9C60CEC2, 0xD3A0C1AF, 0xDA8559EC, 0x6B5941B5},
	{0xFE21B57A, 0xE8F48BCE, 0x36C1E546, 0xCAF4AA8D, 0x8A55B447, 0x2CF5DA59, 0x8810023B, 0x8558C3EE} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 471 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 472 a1");
	}
	{
		static const fp2_t var_a =  { {0xA02039A5, 0x53282163, 0xFF588BBC, 0x20CCDEAE, 0x89F1B9B4, 0x64F2A29D, 0xB2F67C26, 0x09A6EE2E},
	{0x173424D6, 0x1254DCF7, 0x7454F49C, 0x6E8AA48D, 0x6F1325C6, 0xC86EF2E1, 0x4AA440C7, 0x2A781B7F} } ;
		static const fp2_t var_expected =  { {0x8282B68C, 0xA7BA7553, 0x6D27B781, 0x71B8C3DB, 0xEBB53879, 0xB1885C48, 0xA436B98B, 0x97CA1DCC},
	{0xCD168B3F, 0xA96EE2E6, 0x9FAF62CB, 0x456409B6, 0xE1D9ABC6, 0x01360B8E, 0xC6A763E8, 0x08FC30C1} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 473 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 474 a1");
	}
	{
		static const fp2_t var_a =  { {0xB3E086ED, 0x303AE439, 0x8B360143, 0x14C3D3A1, 0xD60C101E, 0xE79F649E, 0x8B88D989, 0x74B00594},
	{0x18F61F08, 0x87F2DB4B, 0xA027A350, 0x7081845E, 0x6585C69A, 0x20BF0E9C, 0x19A57C5D, 0x7F835439} } ;
		static const fp2_t var_expected =  { {0x93304F49, 0xCA08AE3E, 0x99F6A2AE, 0x2414163A, 0x05C59427, 0xF479C14E, 0x62F6158F, 0x8C824EB6},
	{0x5CF296BE, 0x463ADA3A, 0xD146CDEA, 0x4ACCFA8E, 0xE54779D3, 0xCB9C7D2F, 0x01850A5D, 0x31A80F22} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 475 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 476 a1");
	}
	{
		static const fp2_t var_a =  { {0xCDF146C4, 0xC86A1FB7, 0xDCD6E6B1, 0x80617FB5, 0x70CECAB9, 0x689444CC, 0xBDF8B48F, 0xA1B0D883},
	{0x1E8FA1F3, 0xF67AEAB7, 0x8EA23030, 0x77C4B01B, 0xD1E29A39, 0xC894E4C8, 0x23477892, 0x2291EBFF} } ;
		static const fp2_t var_expected =  { {0x7A4C5AD7, 0x11DB296F, 0xA2C62CE2, 0xEC3F175A, 0x13FC7155, 0xB8F7B699, 0xF76E4897, 0x67676C86},
	{0x6C33A5A5, 0x8335C749, 0x0609AE2A, 0x03012C8A, 0xB1A2E30E, 0x9FEBC810, 0x927175A1, 0x4660D3EB} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 477 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 478 a1");
	}
	{
		static const fp2_t var_a =  { {0x380F67AB, 0xE96C7B05, 0xD3604DF8, 0x2AB1F450, 0x10B0F84E, 0xE48FB40C, 0x1A32E1C1, 0x05CEC584},
	{0x939BCC8D, 0xCA6DF3F1, 0x3D877D11, 0xEAF00607, 0x8AC3D6C7, 0x5DF38B89, 0x589E70E9, 0x29628F9D} } ;
		static const fp2_t var_expected =  { {0xE92F3572, 0xD0EABA91, 0x14E1A15C, 0x7D8E0B96, 0x695C043B, 0x04843377, 0x650AE2BA, 0xB340C871},
	{0x3A23AC5A, 0xA576A781, 0x0CB61B9F, 0x0BED5E2B, 0xFC4DBC13, 0x9FE86CA7, 0xECBA4938, 0x386DAD7D} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 479 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 480 a1");
	}
	{
		static const fp2_t var_a =  { {0xA11E70FE, 0x9C4E7331, 0x0CDD72BE, 0x4EED23F3, 0xAAB5AB2A, 0x89AFD1D5, 0x74D30906, 0x84352679},
	{0xBD784400, 0xB3519D61, 0x1BA1B405, 0x5AB61E26, 0x5784CE9A, 0xC19EEC8D, 0xAA7D676F, 0x2F130681} } ;
		static const fp2_t var_expected =  { {0x04E1D42C, 0x04E90225, 0x69EF1033, 0x6FD5798F, 0x2F84E265, 0x5A6261AF, 0x97B05F5B, 0x53A5B874},
	{0x112A7F8D, 0x64223C32, 0x2F616982, 0xB9EEBBA6, 0x8948D1AF, 0x643D76F3, 0xD9171059, 0x79A2DF48} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 481 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 482 a1");
	}
	{
		static const fp2_t var_a =  { {0x4B03A545, 0x33F33945, 0x9797D23F, 0xE81D97EF, 0x291CCE94, 0xE972C8CA, 0x1B07DBF3, 0x2A9AD658},
	{0x4A80CF78, 0x9A3F9963, 0x51B9E954, 0xD169C8A3, 0x3964D8C4, 0x07707A71, 0x0A0487FD, 0x3CBB234B} } ;
		static const fp2_t var_expected =  { {0xC7D0C39F, 0x7F83E174, 0x67418283, 0x31A36E47, 0xF95999C9, 0x4572AD1F, 0x3246F2F8, 0x09741B34},
	{0xFBE320E3, 0xB8451F25, 0x2D760F90, 0xD106C7DA, 0x4E9D1EDA, 0x5801303E, 0x2C70287E, 0x81B0D478} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 483 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 484 a1");
	}
	{
		static const fp2_t var_a =  { {0xC5C7D020, 0x36DF1171, 0x6835F9AB, 0xC776F5E3, 0x533BB825, 0xAC3A18BC, 0xA067529D, 0x14BCFD03},
	{0x63C92EDA, 0xAE07ADE2, 0xA1454A8F, 0x7505F91D, 0xC7A319AD, 0x8C3B0649, 0x2810F2F0, 0x26595D98} } ;
		static const fp2_t var_expected =  { {0xB34F6930, 0x19657D6F, 0x6837FD7D, 0xAD017C43, 0x6BDD0C91, 0x7D863391, 0xE2D31260, 0x3BEB812C},
	{0xEC4EA8DB, 0xE5DE3C9B, 0x5ED6F95A, 0x85F17E54, 0x93B4971F, 0x2579A06C, 0xAE0A3C17, 0x4670CC38} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 485 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 486 a1");
	}
	{
		static const fp2_t var_a =  { {0x34946C5A, 0x7611AD2C, 0xE2BE0C55, 0x77984146, 0xE8C3D28B, 0xDF69C84F, 0x143BD972, 0x8981E22A},
	{0xACA4EFE8, 0x5C01039E, 0x62820A35, 0x866E772E, 0x3415C90A, 0xF6AAB0DA, 0x7650F624, 0x8E23ABDF} } ;
		static const fp2_t var_expected =  { {0x665FAEA5, 0x3B9CB4DD, 0x58C23F08, 0xED631FAF, 0x6B4AED66, 0xA5800D16, 0x6B9C5825, 0x26CE9846},
	{0x0428B3BF, 0xEDA4224C, 0x4E7C3E91, 0x9D15C49F, 0x7CFC4DEA, 0x9FC14FA5, 0x4D419D35, 0xAA8ADAB0} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 487 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 488 a1");
	}
	{
		static const fp2_t var_a =  { {0x1EFA67A4, 0x001EFF8E, 0x275DFDA7, 0xFE95ECB6, 0xDF320922, 0xBD008B86, 0x88BB95BB, 0x3E16FFB8},
	{0x30195A1A, 0x5286BFC6, 0xAAD40ED6, 0xBA246EF3, 0xED1CE7FC, 0x1EE8FE9F, 0x65EFC200, 0x823BBADB} } ;
		static const fp2_t var_expected =  { {0xC04D0BC5, 0xA407F4CC, 0x26AF36F7, 0xC1D7CFE5, 0x35E23903, 0x9EA55BD6, 0xE7391AB6, 0x692A6E32},
	{0x8388EE6C, 0x446E93B5, 0x025A9F6B, 0x045E9AEB, 0x26631EE9, 0xF15CE4E1, 0xE16743C5, 0x328BC138} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 489 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 490 a1");
	}
	{
		static const fp2_t var_a =  { {0x77846A2F, 0x1D08D003, 0x126FED37, 0xD93F1B7D, 0x6E57088F, 0xB667083E, 0x0D27B8FC, 0x573B915F},
	{0xD9BC7E34, 0x7C06516F, 0xFAFB26EA, 0xF74855D3, 0x49B4E057, 0x22EE03DB, 0x6526776D, 0x98ADBA8E} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 491 ");
	}
	{
		static const fp2_t var_a =  { {0xBB8C8EC5, 0x5FB1FA1F, 0xF5E0BD32, 0x42CA1CE6, 0xBF17725B, 0x9B806961, 0x3497D880, 0x20C8A794},
	{0xCF7153F0, 0x07C705BA, 0x129A05A3, 0x63FFB28A, 0xE3DCA741, 0x5DB9AB21, 0x286DA741, 0xA5D57C7A} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 492 ");
	}
	{
		static const fp2_t var_a =  { {0x5C3389EE, 0x8FC5A8F3, 0x2FD46D06, 0x360C0FA7, 0x8452341E, 0x57B65E58, 0x8FC699DD, 0x3C1CCE52},
	{0x1ACA696F, 0x61C42180, 0x20CADE68, 0x4EADF5A4, 0x3F4D7CA5, 0x70B7A22B, 0x5E6A4D95, 0x039A84F0} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 493 ");
	}
	{
		static const fp2_t var_a =  { {0xE13D692C, 0xBB2FC3D9, 0xE0FB73D1, 0xBA243D5A, 0xB8A630AA, 0x2D0D4CB7, 0x2EE8527F, 0x60A08120},
	{0x8975E8A6, 0x3428C4C9, 0xE38CA119, 0x97A3D023, 0x7271B3DC, 0x2E77B53A, 0xF99F0416, 0x37230BFD} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 494 ");
	}
	{
		static const fp2_t var_a =  { {0x51C91CF2, 0x32DA4F77, 0xBF25913A, 0xEEDBE16D, 0xEDDA31FD, 0x9E5250B3, 0xE2D6C3C1, 0x0D2B31ED},
	{0xDE156B8D, 0x70CD4B93, 0x5C208C5B, 0xEAB9E840, 0xD91930B6, 0xBEB8298C, 0xAA428512, 0xA55CE2BF} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 495 ");
	}
	{
		static const fp2_t var_a =  { {0x16BD50BE, 0x7F291AA1, 0x43A1FF07, 0x6A4892CB, 0xEEDD2A0B, 0x65CD7D1D, 0x7CC1F1A8, 0x33B86CCD},
	{0x425DD872, 0x426D8CC2, 0x4E50A5CD, 0x6C41CDC2, 0x0F09DA0F, 0x7F9D3292, 0x226398FB, 0x25005BDE} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 496 ");
	}
	{
		static const fp2_t var_a =  { {0x78A8F561, 0x6F109032, 0x4C70B45C, 0xF2DA86E5, 0x74CCF587, 0x7E8DB6A4, 0xCDBDDB97, 0x46663156},
	{0xE37728EF, 0x168634B4, 0x6209F4AF, 0xA842A359, 0x91A07707, 0x05182C89, 0xD1DF9C4A, 0x3ECD2759} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 497 ");
	}
	{
		static const fp2_t var_a =  { {0xA0531D7D, 0x12E0DBF1, 0x2756FCF5, 0x78AD8C86, 0x26807781, 0x2B3BC828, 0xA6D849C9, 0x41C66541},
	{0x6ADB8F04, 0x97692925, 0xD98A67D4, 0x43853718, 0x7CE3A76B, 0x2A3C0F55, 0xE8F28CBC, 0x468B977F} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 498 ");
	}
	{
		static const fp2_t var_a =  { {0x7C286636, 0xAFC2C3A6, 0xB24361B1, 0x7B2D4C5D, 0x3790B951, 0xDBCB2A21, 0x18C28BA4, 0x47932532},
	{0xFBEA8219, 0xB5169F27, 0x8C76B6E9, 0xFCDF477A, 0x7E06D755, 0x180FADD3, 0x5A4CAC10, 0x5E597FF9} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 499 ");
	}
	{
		static const fp2_t var_a =  { {0xEE10CDB5, 0xD9358831, 0x11AF4C12, 0x46B75F70, 0x250034E8, 0x598829A6, 0xF5A4F5ED, 0x60336FCD},
	{0x2156C751, 0x9DAA7568, 0x1038F0C7, 0x0BE38DDC, 0x867094DA, 0x26370B8C, 0x16B497C4, 0x156174C1} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 500 ");
	}
	{
		static const fp2_t var_a =  { {0xA3B82A84, 0x5A309DD4, 0xFA5B17F9, 0xB29AE334, 0xFDB02072, 0x9DA617C4, 0x4D6F33DA, 0xB9D6F234},
	{0x46FDAABD, 0xBB795164, 0x66359D7F, 0xD5DF3622, 0x6CBDE269, 0xF04BD598, 0x0DA2C122, 0x7FD7A17C} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 501 ");
	}
	{
		static const fp2_t var_a =  { {0x234417C0, 0x3F476298, 0x8D0FD69B, 0xC310D697, 0xB880FE4B, 0xE534EFEA, 0x30465A1F, 0x09604340},
	{0xB1811391, 0xBCDF6E78, 0xF9DEC0A5, 0xEC387E75, 0xF54F6DC2, 0x58A6943D, 0x324D8287, 0x374D4F9C} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 502 ");
	}
	{
		static const fp2_t var_a =  { {0x360C914C, 0xD66C2AC6, 0x2B194D92, 0xBF9D7978, 0x8EBD93E4, 0xAD4AEED0, 0xF1B4C64E, 0x44C9756B},
	{0x70AE9B85, 0x8CB5BB8C, 0xCB169744, 0x6D0C1EC9, 0x7748342C, 0x6F1004D6, 0xB4579816, 0x0261B6B9} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 503 ");
	}
	{
		static const fp2_t var_a =  { {0xE72DF263, 0xACC0CD4C, 0x7662E745, 0x2A61FEDA, 0xF9B5AABA, 0xB2D8ABBC, 0x20BDC28A, 0x9F73D584},
	{0x87569710, 0x5AD56FB1, 0x1C92AC48, 0x46CF0FD2, 0x8E47E803, 0x9ED55C24, 0x84A6E700, 0x854ABAED} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 504 ");
	}
	{
		static const fp2_t var_a =  { {0x7E1A6A13, 0x8D5F4FAD, 0x4E7F918D, 0xC9651F58, 0xB2481283, 0xF27800BE, 0x8FE6CF31, 0x90774C70},
	{0xC09642AE, 0x923600A6, 0xC397BCBB, 0xEE5146F6, 0x67CBCFE1, 0x7E521B8C, 0xD4A98E81, 0x90EF40F5} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 505 ");
	}
	{
		static const fp2_t var_a =  { {0x21FBC72C, 0x88450DEB, 0x014598EF, 0x8FE0074E, 0x5E92585A, 0xADDE66C7, 0x0D30B907, 0x11E0E113},
	{0xC48CD752, 0xE11791AD, 0x02B9E9FD, 0x09B6B7FD, 0x1B595C43, 0xEBE4BC65, 0xD5D039CD, 0x78D16DFB} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 506 ");
	}
	{
		static const fp2_t var_a =  { {0xC11EFC55, 0xE7C33FC7, 0x6B36AE7A, 0xFAD5349C, 0x31E904D2, 0x54865A34, 0xADBB71EB, 0x4462A0CD},
	{0x1BE6B2AA, 0x35CEADB2, 0x83E1B2A7, 0x6BBF3D17, 0xB10C34DF, 0x08BC9A1F, 0xB899E735, 0x175D2CF3} } ;
		static const fp2_t var_expected =  { {0x66B582D4, 0x105695A1, 0x968C4503, 0x57B25849, 0x935E3890, 0x5D94560F, 0x81825F62, 0xB83415C9},
	{0x63537749, 0xF51BD64E, 0x0923C589, 0x45AD1B16, 0xD29DAEDC, 0xAB7C4000, 0x37C49B2C, 0x9591A02D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 507 ");
	}
	{
		static const fp2_t var_a =  { {0x5D4A5A13, 0x20F3BC78, 0xB16B88C3, 0x6CBF3312, 0x61D9E164, 0x1076D890, 0x8A221077, 0x8833DBED},
	{0x630933EC, 0xED800E53, 0x73D6BA98, 0x6EFD3C3C, 0x664546C3, 0x15D1DB95, 0x6604B7C7, 0x0CC6612B} } ;
		static const fp2_t var_expected =  { {0x6B60714C, 0x20485FE0, 0x5FF0EC55, 0xA51CE660, 0xDA0528A3, 0x8FADA834, 0x6663EF4F, 0x10E27A42},
	{0xED7E3DF9, 0x2BA5F7C8, 0x73EF0132, 0x74A9AA1F, 0xDB3A718E, 0x2E583172, 0xCA1530F2, 0x0D078162} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 508 ");
	}
	{
		static const fp2_t var_a =  { {0x443C7FE4, 0xD0588A88, 0xEA6D300F, 0xFE8220BC, 0xA16A0C9E, 0x3BE6632B, 0x5A175E89, 0x675FE858},
	{0x1B11ECF8, 0xD4E238B6, 0x0A88A0AB, 0x1DF010EE, 0xBA5DAFAE, 0x713464E1, 0xC1F5C96B, 0x5539F906} } ;
		static const fp2_t var_expected =  { {0xFEF83FFE, 0xDB17E80D, 0x4C297943, 0xCAFF9306, 0xA19E2C86, 0xD9D87694, 0xDF4DA307, 0x0DC26E4A},
	{0x68A41F76, 0x111A36C3, 0x50EF0AC9, 0x1EA8AF82, 0x7158A6EE, 0xF131E13A, 0x27288F1F, 0x197CDE83} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 509 ");
	}
	{
		static const fp2_t var_a =  { {0x06F243C4, 0x63154705, 0x88A461E6, 0x57070406, 0xDBF98930, 0x40826314, 0xFDC244CB, 0x67A24230},
	{0x403F0780, 0x30ABC1FF, 0x23A1A40E, 0x0DC1D94D, 0xCC6F7DED, 0x615CB54E, 0x2BAB4801, 0x1678EB2C} } ;
		static const fp2_t var_expected =  { {0xCFC1A88C, 0xDBB13DD4, 0xC39055E4, 0xE99DDBCA, 0x7693DD18, 0xF58538F1, 0x5565BADE, 0x55EBDC98},
	{0x3EDA748C, 0xC7D8EC9F, 0xD4B898CE, 0x0160E60B, 0x78FFCF99, 0xDEFB2391, 0x1E55DADF, 0x943AC055} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 510 ");
	}
	{
		static const fp2_t var_a =  { {0x13C2B4F6, 0x7DE87170, 0xAAE019C9, 0x80BDF45B, 0x9F6BFBDE, 0x9DD2F005, 0x519C863B, 0x5207D3D8},
	{0x463F9080, 0x59B24E30, 0xA1F81C73, 0x80BA650A, 0x2B4A5F35, 0x5BC5C560, 0x6D0E14BD, 0x01E0C84A} } ;
		static const fp2_t var_expected =  { {0xA71EB7D4, 0xC2D22C78, 0x711A8E89, 0x6B173B59, 0x2B34DC1C, 0xE5DF6B06, 0xDC232838, 0xB95F8723},
	{0x650E2FA7, 0xA20FB789, 0x66B93E11, 0xE05948CC, 0x9D9FF040, 0xCAF052B6, 0x45C8B9A0, 0x62304415} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 511 ");
	}
	{
		static const fp2_t var_a =  { {0x62A9ABC3, 0x10D8BC43, 0x7B27AB77, 0xE3793FCA, 0x107DFA17, 0xCE2E1EC5, 0x6C6276DD, 0x1EFFCF16},
	{0x568C5CF0, 0x94DAA9FE, 0x7FAA0E3D, 0xD804F4C9, 0x51A03833, 0xB693DDB5, 0x81CC02D2, 0x08625D08} } ;
		static const fp2_t var_expected =  { {0xBD62704C, 0xEF19D7F0, 0x9C93277D, 0xCD263071, 0x63A756FE, 0xEE100E46, 0xE3266DFC, 0x42633378},
	{0x20236191, 0xEEE9017C, 0xECF71377, 0xABB11E48, 0xCBF78490, 0xA3B7ED85, 0x4393A4B6, 0x1ED3641F} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 512 ");
	}
	{
		static const fp2_t var_a =  { {0x2883EA28, 0xA45FE96D, 0x3F0E0D5E, 0x95B92CEE, 0xA1C1C731, 0xF23FDD71, 0xB6154140, 0x16FA55A9},
	{0xDD04B98B, 0x843DDAA8, 0x3D85CBA0, 0x4DB0BC02, 0x8E190854, 0x8C1CBA0C, 0xEAA31C2B, 0x22E9B266} } ;
		static const fp2_t var_expected =  { {0x2256C28A, 0x53ABCB1D, 0x37A195D6, 0xF8888814, 0x3D226F93, 0x7A6F4C46, 0x506AFE05, 0x4E5F9E5C},
	{0xC00D6DC7, 0x61955499, 0xF7361717, 0x4A6D762E, 0x554934E3, 0x60963327, 0x54A217FC, 0x686B53A8} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 513 ");
	}
	{
		static const fp2_t var_a =  { {0x104A544B, 0x4402F645, 0x287E4D03, 0x8F7FEA2A, 0xB8C3025C, 0x45E600A6, 0x7052DE6C, 0x660D04E4},
	{0x44695929, 0x01472960, 0xC4E7FD89, 0xE5D3C92C, 0xAF62C350, 0xBF811EA8, 0xEECFCEE9, 0x0476C2B2} } ;
		static const fp2_t var_expected =  { {0xC5140849, 0x449BB335, 0x4C9F2D9B, 0x66B72857, 0xA9FB6E9B, 0x615CE870, 0xFCC4D3A4, 0x04BDE918},
	{0x61C6B54C, 0xAA49FB2A, 0xB4650B43, 0xE7A3E0D0, 0xB163166F, 0xCFE7AB96, 0x5EBE090A, 0x84AE35CA} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 514 ");
	}
	{
		static const fp2_t var_a =  { {0x05929F8F, 0xA8CADF0B, 0x2847AFB4, 0xB66A4C79, 0xB15231D8, 0x2489166F, 0xEC4A9A2C, 0x05C50380},
	{0x7B946CB2, 0x7EF8540D, 0x0B15111F, 0x5FD4B17E, 0x8255FE05, 0xC42B73F4, 0x1683D010, 0x38BD103B} } ;
		static const fp2_t var_expected =  { {0x0FC5771C, 0x7DFE5991, 0xE5D14ACC, 0x36172E94, 0x6CCEDBEA, 0xB4864C73, 0xABCD85C4, 0x2AB573DA},
	{0x686024D0, 0x9BB30000, 0x5DE83449, 0x5DB1F981, 0x0690EAA9, 0xBFFF6DB8, 0x72B50C7E, 0x5021AF0A} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 515 ");
	}
	{
		static const fp2_t var_a =  { {0xD833425A, 0x9AFA7EF1, 0x724B01EC, 0x1BCB77DE, 0x93392A4D, 0x781CD4C2, 0xFB9D0E0E, 0x527982DC},
	{0x899FFC2E, 0x6AF5AF8F, 0x3A71AA52, 0x0C802648, 0x8AB3B1F1, 0x3EB02AD7, 0x112FA376, 0x178AB762} } ;
		static const fp2_t var_expected =  { {0xD725D484, 0x0479592C, 0xF214FFB8, 0xF4AD4814, 0xF7D863D1, 0x8C790096, 0x96E473B9, 0x49EED98A},
	{0x7F36EC85, 0x02FC7E19, 0x8E99F9B0, 0x103E1FE4, 0x67E7987E, 0x3BAB5519, 0x4F353B08, 0x03D4142E} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 516 ");
	}
	{
		static const fp2_t var_a =  { {0x8AC7F45D, 0x2A6A3378, 0xD6A34DA7, 0x78E2C7CC, 0x0895E293, 0x904BB34C, 0xAECC3A84, 0x192C5037},
	{0x786C6826, 0x6F361416, 0x6852CD53, 0xA468660A, 0x3629F05D, 0x06063BCD, 0x50DEF78D, 0xB0C6577A} } ;
		static const fp2_t var_expected =  { {0x4F9DC2E4, 0xF691A17A, 0x4CDCDDC8, 0xED52CB9E, 0x62D98E5A, 0xEC06EB8F, 0x1FFFB5FB, 0x70855F57},
	{0x533BE87E, 0x65CA9FD7, 0x407345D7, 0xC6A96323, 0x0A8E123E, 0x560F52DE, 0xC62CAD39, 0x6E6415E5} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 517 ");
	}
	{
		static const fp2_t var_a =  { {0x619993F5, 0x92D720BD, 0x27BA6A34, 0x183AB6C2, 0xC2725285, 0x18129D93, 0xC54E8AA7, 0xB3C58B93},
	{0xF4ADFD9D, 0xC21FDE9F, 0xE0301705, 0x09B9797C, 0x773C55B2, 0x47A7DD6D, 0x62920781, 0x06FA816E} } ;
		static const fp2_t var_expected =  { {0x51C43C04, 0xAC7ADADF, 0xF930994B, 0x95FB12F6, 0x35A83030, 0x782FB06B, 0x28EE62BA, 0xB753F4A2},
	{0x370328E5, 0xBFCA7092, 0xB19BE899, 0xE088615E, 0x835203CD, 0x76600E96, 0x14AA6912, 0x3F3F2B3E} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 518 ");
	}
	{
		static const fp2_t var_a =  { {0x551C1B60, 0xDBBF575A, 0xD7B135A8, 0xA2474F1C, 0xFE7771C8, 0x3A708399, 0x8B9C8932, 0xA1DE889F},
	{0x835CFB8E, 0xAE3A580C, 0xC06008A1, 0x5CEBAA60, 0x1786F5DF, 0xC64C1BB4, 0x73ECB4B9, 0x365D19FA} } ;
		static const fp2_t var_expected =  { {0xB9B723DD, 0x5BEC89A3, 0xF01D5A01, 0x1F633B38, 0xF2F9ADC3, 0xADA17DEA, 0xA333BCCB, 0x5CEEE105},
	{0x8CF6F62B, 0xDFD62007, 0xBE293F55, 0x9719FFB1, 0xD40CFA54, 0x2D1F9FED, 0xCFDF622E, 0x81F5ED77} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 519 ");
	}
	{
		static const fp2_t var_a =  { {0x372C0353, 0x5326DA9E, 0xBEE48F5D, 0x4C537B4E, 0x9214F476, 0xBA438576, 0x8EA54053, 0x5322C109},
	{0x5B58CEC0, 0xEE2E5DD6, 0xBEAC1108, 0xC44F9456, 0xE755D959, 0x3F9C9CA3, 0x28D2D95F, 0x60444604} } ;
		static const fp2_t var_expected =  { {0x22A6D33D, 0x326B7E1D, 0x2A2EEC47, 0x9962BACE, 0x5C0F3A78, 0xC560704C, 0x42AB3B69, 0x9F638153},
	{0xF07371CB, 0x6CB637F3, 0x3C9FDCC6, 0x57FE272B, 0x2AD00E78, 0x4BBACB27, 0x9A58BCB4, 0x019A5E39} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 520 ");
	}
	{
		static const fp2_t var_a =  { {0x1EF493EB, 0x77C5C654, 0x538BB121, 0xCA2CF8FF, 0x93A6529C, 0x147D3CAE, 0xF1AD1494, 0x3AC29B18},
	{0x745D078D, 0x3966FE99, 0x3207D5C0, 0x9AF47F39, 0x98492089, 0x09CB7CE1, 0x7DEE734C, 0xB19DA21D} } ;
		static const fp2_t var_expected =  { {0xE0800AA0, 0x2A6D82A6, 0x5456ED87, 0xA6E0775F, 0xAFD94A44, 0xCA2C642E, 0x3460F675, 0x66CD4D2E},
	{0x844B5DDC, 0x9631630C, 0x7C142E42, 0x00546F60, 0x8554C5A0, 0x4B2598D4, 0xBB6D69AB, 0x94360145} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 521 ");
	}
	{
		static const fp2_t var_a =  { {0x9451A591, 0x532F5CD8, 0xB63B706D, 0x2182597E, 0xFB34B28E, 0x85573C07, 0xC49BE0E2, 0x0BC6035D},
	{0x7911DF84, 0x3AC7E346, 0x5D49DE38, 0x84634504, 0x45EEE130, 0x015F52EB, 0xA27814ED, 0x80D26C76} } ;
		static const fp2_t var_expected =  { {0x07664A03, 0xECCD1A65, 0xDCD29FDD, 0xEBA6ED7B, 0x993F2512, 0x50DC11DF, 0xB9C56B87, 0x7296D726},
	{0x9F103E23, 0x40DA45E1, 0xBB6C1717, 0xECA899C8, 0xA53491E4, 0x8142F139, 0x987D8BC3, 0x795BB57E} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp2_sqrt 522 ");
	}
#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const fp2_t var_a =  { {0x0CF07D61, 0x6BB066BD, 0x4EB0CE02, 0x0D946453, 0x1A6FD10E, 0x1D71F3FE, 0xC9C7E77F, 0x20B51BF7},
	{0x92610933, 0x16EE0BA8, 0x0A2E4E8D, 0x836178F9, 0x1C368EC4, 0x8B63F62F, 0xE1C05FEA, 0x1311EB90} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 539 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 540 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 541 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 542 a1");
	}
	{
		static const fp2_t var_a =  { {0xF74019B8, 0x5FFAAE62, 0x58686954, 0xE927545B, 0x1DBC1B2E, 0xA02853FF, 0xFB8B5604, 0x06D945A8},
	{0xC71663CE, 0x88535D4D, 0xEDD245AD, 0x8EDBBAD4, 0x48035EC2, 0xA72523A3, 0xB8888693, 0x201B08D2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 543 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 544 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 545 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 546 a1");
	}
	{
		static const fp2_t var_a =  { {0xB0E615D8, 0x6EBA2DC7, 0x0277C6DF, 0x0FAC6A02, 0xA7DEBC8D, 0xB3F28F2A, 0xC11D6F42, 0x1DA592BA},
	{0x02F02E5B, 0x71A26B87, 0xD69FA4CA, 0xB2BF815E, 0xABAA4FD0, 0x8EDB3461, 0x019A0ED6, 0x2058BDB8} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 547 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 548 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 549 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 550 a1");
	}
	{
		static const fp2_t var_a =  { {0x36FEC993, 0x5674CE24, 0x2897BBC9, 0xBBD2EC79, 0xA895976E, 0xB2D5190E, 0x262B44EF, 0x0D88E2A1},
	{0x6449AC7C, 0xE1A466F2, 0xBD716166, 0x09530B04, 0x56780A79, 0xC62F62DC, 0x64E3CBAD, 0x11A18059} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 551 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 552 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 553 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 554 a1");
	}
	{
		static const fp2_t var_a =  { {0xCBE6C069, 0x63902AE5, 0xE0EB5608, 0x2D70DA1A, 0x513EF046, 0xAC69FAAB, 0xF2C906BD, 0x08860DD1},
	{0x4DC960F2, 0xEE334DE8, 0xDC55B64C, 0xE39E388F, 0x9ADE54D1, 0x44005908, 0xCA000102, 0x0A61D74D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 555 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 556 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 557 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 558 a1");
	}
	{
		static const fp2_t var_a =  { {0xF05190A7, 0xBDA9C8E1, 0x8490C907, 0x668E2FE2, 0x15E41022, 0xD79E631F, 0x2DFE67CB, 0x174DD8F3},
	{0x5E707F5A, 0xE980C6AB, 0xAD19D2B0, 0xAF9C4CC1, 0x09862A36, 0x25A06CDD, 0xDDCA62E6, 0x2128C9C9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 559 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 560 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 561 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 562 a1");
	}
	{
		static const fp2_t var_a =  { {0x6653117C, 0x46DCCF72, 0xAE281625, 0xDE706CB1, 0xA350112B, 0x692384E5, 0xA2567E5E, 0x0B17BACF},
	{0x79A92ACD, 0x0E69EF3B, 0xE6DAC47B, 0x9D768C68, 0x735D766A, 0x98C1BA1C, 0x46E31F0C, 0x136381B9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 563 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 564 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 565 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 566 a1");
	}
	{
		static const fp2_t var_a =  { {0x2D71FD29, 0x581C2FD1, 0x3670831C, 0x55AF7F10, 0xEC1BC38E, 0xA16A5AD5, 0x59722F0F, 0x1FF6415E},
	{0xBE59AC9C, 0x17C81BF6, 0x8397B56C, 0x299BA64D, 0xE8A97058, 0xDF7E74A7, 0xED4DECA2, 0x00BD8650} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 567 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 568 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 569 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 570 a1");
	}
	{
		static const fp2_t var_a =  { {0x88B3EF8E, 0x497D3891, 0x36CBD269, 0xE561F56D, 0x23BCC15C, 0x624D40E0, 0x5A971D35, 0x19D8610D},
	{0x8EF087D8, 0xCCBF8B6A, 0xBBBD5A40, 0x9C0AF495, 0xBB16A1BC, 0x347B1B0D, 0xFCF41012, 0x0B841D73} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 571 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 572 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 573 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 574 a1");
	}
	{
		static const fp2_t var_a =  { {0xF6B4C950, 0xC886B03A, 0x05D639C0, 0xA3CA861A, 0xB795A5FF, 0x6F2F5DB5, 0x703C1936, 0x1B339296},
	{0x8B776D0D, 0xB4101509, 0x09BCB617, 0xB0569377, 0x7CC584EF, 0xCDB88610, 0x5B417F2C, 0x20671178} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 575 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 576 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 577 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 578 a1");
	}
	{
		static const fp2_t var_a =  { {0x3AB27C7B, 0x69845143, 0x3EF5255D, 0xFF05F77C, 0x590B6126, 0x4069AAD1, 0xA3A01692, 0x05FF20AA},
	{0x95A21466, 0xB564C08A, 0x23911859, 0xFB8D475C, 0xFD5DD8F0, 0x91189940, 0xF3A9E803, 0x1D6A118C} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 579 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 580 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 581 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 582 a1");
	}
	{
		static const fp2_t var_a =  { {0x539A35E0, 0x63D3C2F0, 0xB9E5B411, 0x6743493B, 0xFB8DB213, 0xEB2AA124, 0x7C53A7C9, 0x0B71D57A},
	{0xCEDF0043, 0xDEA25A3D, 0x055C5FDC, 0x96023CD0, 0x4D1E8601, 0x09BEEB05, 0x6F3EDA36, 0x00CD26AE} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 583 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 584 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 585 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 586 a1");
	}
	{
		static const fp2_t var_a =  { {0x831EF326, 0x473704E7, 0x904C0536, 0x01484356, 0xCEACCED5, 0x21D1E4BB, 0x03CBF776, 0x19E9F2C4},
	{0x96672040, 0x323BFA95, 0xE7EB8739, 0xD00396D9, 0xBFEA3762, 0x406E2628, 0xF53EDC09, 0x12ECB8E9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 587 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 588 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 589 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 590 a1");
	}
	{
		static const fp2_t var_a =  { {0x4BC27074, 0x04234D68, 0x1A473CE7, 0xC4E04A74, 0x43251F26, 0x48DFF0BE, 0x43F250E8, 0x0D25CBE3},
	{0x8E4C54CA, 0x6E7C78AF, 0x41506FF4, 0xB8B5D295, 0xE25D8D15, 0x82D628AD, 0xB0A1954A, 0x159913CB} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 591 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 592 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 593 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 594 a1");
	}
	{
		static const fp2_t var_a =  { {0x6CEB89D0, 0xC911608B, 0xF2FA54BD, 0xEDD890D8, 0x0AF32BA6, 0x09288A11, 0x84B61DA3, 0x044F3007},
	{0x988BDB63, 0xB0DCDE99, 0xCD68ED02, 0xE8F8063A, 0x89D8F59E, 0x8A77829A, 0x89AFF3F6, 0x0F6827CF} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 595 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 596 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 597 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 598 a1");
	}

	{
		static const fp2_t var_a =  { {0xE7F1F108, 0x4BCA51ED, 0xF125B398, 0xDB7599C3, 0x1560A7BB, 0xEB243C71, 0x8F98745D, 0x157D5A98},
	{0xD41BA236, 0x284EC89F, 0x837524A9, 0xCAEEE7D2, 0xC4912EA4, 0x0E8CBE7F, 0xA88A55A0, 0x053DA017} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 599 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 600 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 601 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 602 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 603 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 604 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 605 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 606 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 607 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 608 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 609 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 610 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 611 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 612 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_b =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 613 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 614 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 615 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 616 a1");
	}
	{
		static const fp2_t var_a =  { {0xFD2F56B8, 0x70BFC4A3, 0x2EAE79D2, 0x4DFE133A, 0x94149EDA, 0xE5D6E0EB, 0x2D4025B2, 0x08422A6C},
	{0xA3FE7338, 0xF191B6E6, 0x9EA619E1, 0xB06EAD61, 0xE4A664CD, 0x026BBF49, 0xF7C0BAFE, 0x0D67FDC3} } ;
		static const fp2_t var_b =  { {0x2E12E30D, 0xE6519874, 0x0432A57B, 0x5B7EFA6E, 0xF926CAFB, 0xBDDA1DE9, 0x26094ACE, 0x003D03C2},
	{0xA74F1400, 0x1E7E5B0F, 0x95AC9594, 0xFDFAC732, 0x7A2BFBA7, 0xB2FF26C7, 0x1EDCFBEE, 0x17F75002} } ;
		static const fp2_t var_expected =  { {0x2B4239C5, 0x57115D18, 0x32E11F4E, 0xA97D0DA8, 0x8D3B69D5, 0xA3B0FED5, 0x53497081, 0x087F2E2E},
	{0x4B4D8725, 0x691011F6, 0x3452AF62, 0x4D487494, 0x5ED2606D, 0xFB369891, 0xD69DB6EA, 0x003BE943} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 617 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 618 a1");
	}
	{
		static const fp2_t var_a =  { {0x3D272CCB, 0x6F250C98, 0x0B98E9E9, 0xE4D11D4E, 0xF52B106A, 0x2FCD8F4C, 0x85915D30, 0x1D65C995},
	{0xC15438DA, 0xBA59D6BA, 0x22484096, 0x94FA668B, 0x5839F58F, 0x38FB566B, 0x87F6F7C0, 0x0ACCFEDB} } ;
		static const fp2_t var_b =  { {0x29307E75, 0x5873578A, 0x1C9F594C, 0xCE21F1E3, 0x78461103, 0xAF9679C7, 0x124BD4DD, 0x0E793890},
	{0x108E6666, 0x5724E519, 0x3EDA03CC, 0xA11CD70A, 0x8D000447, 0xA4576C95, 0x9A41DA35, 0x01C27A72} } ;
		static const fp2_t var_expected =  { {0x6657AB2D, 0x20986422, 0x28384322, 0x51D20F31, 0x6D712166, 0x252FBB94, 0x57DD320C, 0x06BB9DA3},
	{0xD1E29F40, 0x117EBBD3, 0x61224463, 0x36173D95, 0xE539F9D7, 0xDD52C300, 0x2238D1F5, 0x0C8F794E} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 619 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 620 a1");
	}
	{
		static const fp2_t var_a =  { {0x34308676, 0x7358B4B1, 0x516EC2ED, 0x662BB39F, 0xB437F56E, 0xD59CB86B, 0x56103A64, 0x21016A84},
	{0xF7C5B98F, 0xC2E909EB, 0x22F4BF40, 0x6B31B35C, 0x6CD73861, 0x312FEB13, 0x819C5409, 0x1E047872} } ;
		static const fp2_t var_b =  { {0xE07C707F, 0x2B21DFDD, 0x0225E57A, 0x9533E8AC, 0x1A6F49CF, 0x7F44FE26, 0x9AABD377, 0x15B0F281},
	{0x17218872, 0xC30EA48C, 0x46E7273B, 0x93FCE918, 0x854A5BED, 0xB8C27614, 0x6424E474, 0x0393218E} } ;
		static const fp2_t var_expected =  { {0x14ACF6E2, 0xF77A948F, 0x5394A853, 0x9A3E9C4B, 0xCEA73F35, 0x9AAD6911, 0xB0BC0DDA, 0x118EF883},
	{0x0EE74201, 0x85F7AE78, 0x69DBE67C, 0xFF2E9C74, 0xF221944E, 0xE9F26127, 0xE5C1387D, 0x21979A00} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 621 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 622 a1");
	}
	{
		static const fp2_t var_a =  { {0xECCD5C05, 0x1FA209E6, 0xC86A5590, 0xED6828E1, 0x5A1A0A7F, 0x3AAF8214, 0x676BC3FC, 0x0463E7D6},
	{0x502EEDE2, 0x4AA6FD07, 0x6455FE15, 0x8D7C8FEE, 0xA92CE2FB, 0xF24A14B1, 0x6DC11837, 0x246645B3} } ;
		static const fp2_t var_b =  { {0x5A4D3C16, 0x257F42EA, 0x7CFF3B34, 0x1DA642FB, 0x6635CEFD, 0xBE697CF0, 0x06B7B778, 0x0F4F8285},
	{0xC3F63D8F, 0x94BD4C3A, 0x75C083D1, 0x9C7A9876, 0xE9A696BB, 0x67DEE8DB, 0x04B6E046, 0x15635FB7} } ;
		static const fp2_t var_expected =  { {0x471A981B, 0x45214CD1, 0x456990C4, 0x0B0E6BDD, 0xC04FD97D, 0xF918FF04, 0x6E237B74, 0x13B36A5B},
	{0x14252B5E, 0x38644942, 0xDA1681D3, 0xC8D62864, 0x92D379AE, 0x9FF4B00D, 0x3277F87C, 0x14A640E8} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 623 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 624 a1");
	}
	{
		static const fp2_t var_a =  { {0x6AA711B5, 0x868150FD, 0x384BBDA0, 0xAB03B530, 0x6E9A1767, 0x62AC890A, 0x80950EC3, 0x11EDAE9D},
	{0xD20D5210, 0xF2ACA880, 0xB11A352E, 0x1B5F4D4B, 0x9648CC37, 0xDD730D45, 0x1336D8BB, 0x13DC81CA} } ;
		static const fp2_t var_b =  { {0x9F1A9AA5, 0x8DE4013C, 0x53EE42DD, 0xE5D27846, 0xE411C7D1, 0x89D295F9, 0x5E42910F, 0x19C9C77E},
	{0x1DA1C48B, 0xE866F38B, 0x9356BE1C, 0xC4D0A641, 0x411751A6, 0x88FCCA1E, 0x82EC9C43, 0x0D567745} } ;
		static const fp2_t var_expected =  { {0x09C1AC47, 0x6D65523A, 0x8C3A006A, 0x2FB52D76, 0x52ABDF31, 0x324AD184, 0x9ED79FD1, 0x06941199},
	{0xEFAF169B, 0xDB139C0B, 0x4470F34B, 0xE02FF38D, 0xD7601DDD, 0x666FD763, 0x962374FF, 0x2132F90F} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 625 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 626 a1");
	}
	{
		static const fp2_t var_a =  { {0xB98751CE, 0xC3A8EF96, 0x6951705A, 0xA82E19B2, 0x7962B481, 0x2390A702, 0xA9C0A41C, 0x1F674C55},
	{0x85880A41, 0x26CBB641, 0xD2F6448A, 0xDEE071E1, 0xBC9EF1E6, 0x3E612436, 0xFB91256F, 0x0DBC3493} } ;
		static const fp2_t var_b =  { {0xB881DFBD, 0xA2DEB4D3, 0x5035E699, 0x48803180, 0x1E616AF8, 0xE5929A6C, 0x2A6504DA, 0x100200AB},
	{0x2C5671B8, 0x2BF3F5CE, 0x689EE718, 0xDB0C4F79, 0x1701AD59, 0x69499153, 0x677C1DE7, 0x0F29FEA0} } ;
		static const fp2_t var_expected =  { {0x72093178, 0xBF87A46A, 0xB98756E0, 0x8F8D4B32, 0x97C41F71, 0x4EEEF3EE, 0x9425A8F5, 0x0A45E87E},
	{0xB1DE7BF9, 0x52BFAC0F, 0x3B952BA2, 0xB9ECC15B, 0xD3A09F40, 0xA7AAB589, 0x630D4356, 0x1CE63334} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 627 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 628 a1");
	}
	{
		static const fp2_t var_a =  { {0xDF5DED01, 0x78FD998A, 0x2343CE13, 0x047C2BFD, 0x03010785, 0xE0A375A5, 0xAA68FF33, 0x209D71DC},
	{0x726607AB, 0x1985F251, 0x8EA086DC, 0xA08F876B, 0xA2067DC3, 0x8C969CE1, 0xAE2E444B, 0x0B90906D} } ;
		static const fp2_t var_b =  { {0xAD43574A, 0x1E2CB425, 0x3A9C2146, 0x1B485E5D, 0x99633F5E, 0xD5F3B007, 0xB2793A3C, 0x0B1D11E8},
	{0xF9EF588A, 0x8D00E6BF, 0xBC90D594, 0xA3CCA990, 0xF02DD64A, 0x7FC16841, 0x39E4D06D, 0x11D3B39E} } ;
		static const fp2_t var_expected =  { {0x8CA14438, 0xF02A4DB0, 0x5DDFEF45, 0xBEA38A5A, 0x9C6446DA, 0xFC62D82C, 0x1CE2396E, 0x06971F43},
	{0x6C556035, 0xA686D911, 0x4B315C70, 0x445C30FC, 0x9234540E, 0x0C580523, 0xE81314B9, 0x1D64440B} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 629 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 630 a1");
	}
	{
		static const fp2_t var_a =  { {0xE43CC69D, 0x6B997826, 0x2E6AB7F4, 0x2A667BE1, 0x93E886F0, 0x29FE0A1C, 0xCB4AF58D, 0x13239052},
	{0xA11325BC, 0x8F11AFEB, 0xACD2A198, 0xC97B04CD, 0xD1BBBC2F, 0x5B79FBCF, 0x722ADA9F, 0x083108FB} } ;
		static const fp2_t var_b =  { {0x8545AD70, 0xC4C3C336, 0xD86E1C6E, 0xCC6D5234, 0xE03D6078, 0xEE45EA9F, 0x3E20D4E0, 0x05D6D83A},
	{0x8BECE70D, 0x44DF72D2, 0x572A7190, 0xE440F935, 0x56CB8354, 0x47D7E500, 0x8165C147, 0x0E9D5002} } ;
		static const fp2_t var_expected =  { {0x6982740D, 0x305D3B5D, 0x06D8D463, 0xF6D3CE16, 0x7425E768, 0x1843F4BC, 0x096BCA6E, 0x18FA688D},
	{0x2D000CC9, 0xD3F122BE, 0x03FD1328, 0xADBBFE03, 0x28873F84, 0xA351E0D0, 0xF3909BE6, 0x16CE58FD} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 631 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 632 a1");
	}
	{
		static const fp2_t var_a =  { {0xD15BA9DD, 0x74CC54CA, 0x52941EC1, 0x3FB3E8FE, 0xB16FC310, 0x33736AB0, 0xD4662DDD, 0x148CF18E},
	{0x19A04E65, 0xD15B3293, 0xF64B551E, 0xD9971764, 0xD15D2F14, 0xC63AC598, 0x5068A2CC, 0x1EFEB23B} } ;
		static const fp2_t var_b =  { {0x49904AF1, 0xFECABC55, 0xF47C35C0, 0x2765DFEF, 0x79F8BB82, 0x7808956F, 0x563BDB94, 0x21E52777},
	{0xEB6D8E3F, 0x139453B6, 0x016C0992, 0x071113CF, 0xD16A7AB2, 0x4FDF70E2, 0x8801C797, 0x021E07D9} } ;
		static const fp2_t var_expected =  { {0x1AEBF4BB, 0xCC971120, 0x4710546E, 0x05F8C8EE, 0x2B687E8A, 0xF147B2A0, 0xEAA2096F, 0x114EB483},
	{0x050DDCA4, 0xE4EF864A, 0xF7B75EB0, 0xE0A82B33, 0xA2C7A9C6, 0x161A367B, 0xD86A6A64, 0x211CBA14} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 633 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 634 a1");
	}
	{
		static const fp2_t var_a =  { {0xAE153827, 0x4217C25F, 0x571396C6, 0xF8C83BB3, 0xE7D01BC0, 0xEC3F8F71, 0x8D02914A, 0x00EAC6ED},
	{0xE3BF9F67, 0xE5021FAA, 0x33CF5222, 0x21BE8C50, 0x29F07FFE, 0xFF2FAEF2, 0xD18D1E92, 0x0629AC44} } ;
		static const fp2_t var_b =  { {0x0051BD78, 0xB29E37F2, 0x551A1B7B, 0x2E726D97, 0xEC7F58B9, 0x779BEBC1, 0x02F2B499, 0x0E6CF34A},
	{0x213A5CDC, 0x42DA3099, 0x835AA57A, 0x8BD2AD2A, 0xE9010DF5, 0xB5F782C9, 0x5482B8FD, 0x05726AF5} } ;
		static const fp2_t var_expected =  { {0xAE66F59F, 0xF4B5FA51, 0xAC2DB241, 0x273AA94A, 0xD44F747A, 0x63DB7B33, 0x8FF545E4, 0x0F57BA37},
	{0x04F9FC43, 0x27DC5044, 0xB729F79D, 0xAD91397A, 0x12F18DF3, 0xB52731BC, 0x260FD790, 0x0B9C173A} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 635 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 636 a1");
	}
	{
		static const fp2_t var_a =  { {0x82E9BF4E, 0xC530482F, 0x06BDE6C0, 0x34CCC0DC, 0xBA2A8BA2, 0x27E0D770, 0x3EA7BD05, 0x16A05C3F},
	{0x06CB860C, 0xF459DEFF, 0x2B230C73, 0x8B339D2F, 0x62DA8D8C, 0xAF4632F2, 0x3B0549C8, 0x23F8BD91} } ;
		static const fp2_t var_b =  { {0xB3D8102A, 0xF2CF3510, 0xC31ED34D, 0x135313EC, 0xC2A493FC, 0xF2997753, 0x0BB11309, 0x11F0093C},
	{0x34BBA89F, 0xB81C8FA5, 0xA3FE550F, 0x2E25C0E6, 0x25EAA36B, 0x383906EC, 0xAF74A2CA, 0x1EC9D062} } ;
		static const fp2_t var_expected =  { {0x36C1CF65, 0x10FF7D40, 0xC9DCB9FB, 0xE6FED4C8, 0x7CCF1F95, 0x60460144, 0x0A58D00D, 0x036D00F9},
	{0x3B872E98, 0x05766EA4, 0xCF216170, 0x58385E15, 0x88C530EF, 0x2D4AEC5E, 0xAA79EC91, 0x1D9F2971} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 637 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 638 a1");
	}
	{
		static const fp2_t var_a =  { {0x567A25BE, 0xE2028D92, 0x25EB9BE2, 0xF35FE5F1, 0xB57F6589, 0xEE6CEA7E, 0xF023773F, 0x02524FA2},
	{0x8BBDE650, 0x3C680ADF, 0xA512865C, 0xB70AD4CC, 0x03E86479, 0x23AC47F4, 0x58FD4679, 0x0231BF43} } ;
		static const fp2_t var_b =  { {0x6A9C3977, 0xF121CCD8, 0x06E6D681, 0x97B3B79A, 0x831B6AD4, 0x62B61195, 0xF726E95A, 0x2481B135},
	{0x2CFFAA54, 0xDF7DB83E, 0x2B65881C, 0x0299DB0B, 0x0DE13408, 0x68D69608, 0x6027EF00, 0x17A95551} } ;
		static const fp2_t var_expected =  { {0xC1165F22, 0x2C245A6A, 0x2CD27251, 0x29F29D8B, 0x389AD056, 0x96EEAE94, 0xA74A6098, 0x01B09C56},
	{0xB8BD90A4, 0x1BE5C31D, 0xD0780E79, 0xB9A4AFD7, 0x11C99881, 0x8C82DDFC, 0xB9253579, 0x19DB1494} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 639 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 640 a1");
	}
	{
		static const fp2_t var_a =  { {0x318FC6C2, 0x3CAA7E03, 0x7D7BA015, 0x0F86CAED, 0x5EB61AC6, 0x5B94D281, 0x298619DB, 0x10F86EE4},
	{0x79373974, 0xE5E8D717, 0x6B6C2A8E, 0x8BB0E047, 0x9548491E, 0x0038D035, 0x6F681AE0, 0x0AC28819} } ;
		static const fp2_t var_b =  { {0x2C3572E6, 0x3A8CCCC7, 0xE64F2038, 0x1F312283, 0xB67CAFB2, 0x86655AAE, 0x0F4558F4, 0x19E948F0},
	{0x13B824EF, 0x22D1A679, 0xE19E5716, 0xD54B845D, 0x2A08CFAC, 0x92259B02, 0xEEAFA231, 0x131ABF78} } ;
		static const fp2_t var_expected =  { {0x5DC53995, 0xD0374ACA, 0x63CAC039, 0xCD96ED71, 0x1532CA6F, 0x27C5DFB0, 0xF8CB72CE, 0x05BE5351},
	{0x8CEF5E63, 0x08BA7D90, 0x4D0A81A5, 0x60FC64A5, 0xBF5118CB, 0x925E6B37, 0x5E17BD11, 0x1DDD4792} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 641 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 642 a1");
	}
	{
		static const fp2_t var_a =  { {0x1C1353B9, 0xCD7B7D08, 0xD7CFC206, 0x4042E791, 0x3D99F80C, 0x161ACE4E, 0x73270BBA, 0x120932D4},
	{0xD97CAFA3, 0x0C4A8087, 0x44039A2B, 0x1689712F, 0x9F8FB41F, 0x1DD47798, 0x87FC5380, 0x1257FC6A} } ;
		static const fp2_t var_b =  { {0x02609DD1, 0xA83D70F6, 0x2BC03BB4, 0xD1C01B94, 0xE44459CD, 0x9377A653, 0x1C45A714, 0x1104EC32},
	{0xEE3B03F4, 0x44A2ED52, 0x8FC0DDDC, 0x13C98DDF, 0x04E517B5, 0x43BF5DEC, 0xA3E58740, 0x0C59CF23} } ;
		static const fp2_t var_expected =  { {0x1E73F18A, 0x75B8EDFE, 0x038FFDBB, 0x12030326, 0x21DE51DA, 0xA99274A2, 0x8F6CB2CE, 0x230E1F06},
	{0xC7B7B397, 0x50ED6DDA, 0xD3C47807, 0x2A52FF0E, 0xA474CBD4, 0x6193D584, 0x2BE1DAC0, 0x1EB1CB8E} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 643 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 644 a1");
	}
	{
		static const fp2_t var_a =  { {0x1E15B8D5, 0x5AFB857D, 0xFACD5129, 0xF5969D7C, 0xDBD6EC1E, 0xAFC1A396, 0x149E2E51, 0x00E40E69},
	{0xB3755971, 0x74B1AB9C, 0xF9AD7DBC, 0xC2AD1211, 0xAAB4584B, 0x0E12E014, 0xEA33C506, 0x18177EC5} } ;
		static const fp2_t var_b =  { {0xF3FDAC96, 0x91930103, 0x9D1E5F41, 0xC21484BC, 0x94D4C08D, 0x2F5C6064, 0x24A231AD, 0x075845D6},
	{0xC884FDB5, 0x0A2DA421, 0xFBE28A8C, 0x2A386F10, 0x2261CEA4, 0x0FB09102, 0xC6656358, 0x01F3565F} } ;
		static const fp2_t var_expected =  { {0x1213656B, 0xEC8E8681, 0x97EBB06A, 0xB7AB2239, 0x70ABACAC, 0xDF1E03FB, 0x39405FFE, 0x083C543F},
	{0x7BFA5726, 0x7EDF4FBE, 0xF5900848, 0xECE58122, 0xCD1626EF, 0x1DC37116, 0xB099285E, 0x1A0AD525} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 645 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 646 a1");
	}
	{
		static const fp2_t var_a =  { {0x40C80115, 0x4FE55ABA, 0xADDFA9C6, 0xFBBBD294, 0xC0014731, 0x7277F35C, 0x96C854F3, 0x00DFE2DD},
	{0x0EAE3D12, 0x51F4DA58, 0x50475D04, 0x55E302FE, 0x3D1321EF, 0x488C04D7, 0x1F4B325E, 0x1280072F} } ;
		static const fp2_t var_b =  { {0x0814FA61, 0xCC238615, 0x04D7719E, 0x154B7271, 0x4F70DC83, 0x8ECA315F, 0xF11A5A5E, 0x1E6BC94D},
	{0xA730367C, 0x2D624FC7, 0xEF226D35, 0xEEB8A558, 0x0DCA4C2C, 0xFA60980D, 0x9F8F2542, 0x07042459} } ;
		static const fp2_t var_expected =  { {0x48DCFB76, 0x1C08E0CF, 0xB2B71B65, 0x11074505, 0x0F7223B5, 0x014224BC, 0x87E2AF52, 0x1F4BAC2B},
	{0xB5DE738E, 0x7F572A1F, 0x3F69CA39, 0x449BA857, 0x4ADD6E1C, 0x42EC9CE4, 0xBEDA57A1, 0x19842B88} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 647 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 648 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 649 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 650 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 651 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 652 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 653 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 654 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 655 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 656 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 657 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 658 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_b =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 659 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 660 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 661 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 662 a1");
	}
	{
		static const fp2_t var_a =  { {0x8A8334A2, 0x4B25AF15, 0xBAF2C7AA, 0x6F10904A, 0x73907A50, 0xC10CE8FB, 0xBFC7AEBD, 0x0311B65B},
	{0xF3558585, 0x7D9DD14E, 0x12AE67D7, 0xF5A50E85, 0xE16A39D9, 0x027D6D92, 0xEE4804A5, 0x20897C9A} } ;
		static const fp2_t var_b =  { {0x48CBB00B, 0x57B56881, 0x28D928BA, 0x886A4549, 0x9C408BAE, 0x59994894, 0x0AB27C89, 0x235ACA25},
	{0x9381E21F, 0x91E7CB1C, 0x32A18C56, 0x1D64062F, 0x4CD10AE8, 0xC3A32235, 0xF6881C32, 0x22B4E4C9} } ;
		static const fp2_t var_expected =  { {0x41B784AA, 0x9A704694, 0x92199F03, 0x47C74B01, 0xD74FEEAA, 0x21A7EDE6, 0xF5153236, 0x04DA50B8},
	{0x5FD3A379, 0x92B60632, 0xE00CDB94, 0x39620855, 0x94992EFA, 0xF90E98DD, 0x37BFE873, 0x22F7FC53} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 663 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 664 a1");
	}
	{
		static const fp2_t var_a =  { {0x03C238AB, 0x15E04F45, 0xE878DB62, 0xBCD4972C, 0x7DDDE0C9, 0x2D2389B4, 0xD90140F6, 0x08570B89},
	{0x69419923, 0x84EDFF1D, 0x07C54E6E, 0x03C16EA1, 0x1EDF05AE, 0xF93611EB, 0x9FEFFA47, 0x1437C685} } ;
		static const fp2_t var_b =  { {0xBC702D4F, 0x86452384, 0xD19813E6, 0x2F63C72B, 0x0452D265, 0x3811BB36, 0x76B0E0E9, 0x16241C8B},
	{0x955DE873, 0x3116381C, 0x8C8237F1, 0x722C1F72, 0x688C1F3F, 0x12CB6845, 0x53372654, 0x227A29C4} } ;
		static const fp2_t var_expected =  { {0x47520B6F, 0x369B2BC0, 0x16E0C78F, 0xEE91D001, 0x798B0E6C, 0xAF461BFE, 0xA250600E, 0x17565380},
	{0xD3E3B0C3, 0xFAD7C700, 0x7B431690, 0xF2B64F2E, 0xB652E676, 0xA09EF725, 0x8CB8D3F5, 0x16E10143} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 665 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 666 a1");
	}
	{
		static const fp2_t var_a =  { {0xB322B89D, 0x70694E1B, 0xFF67D7F3, 0x525CFD52, 0x65277B33, 0x464F0752, 0x2B1E50BA, 0x0B5E66C8},
	{0x79E84475, 0x62D6ECEA, 0xF872142C, 0xF7A79A1E, 0x7BF72E0B, 0x90B690AE, 0x7ACADE10, 0x151C134F} } ;
		static const fp2_t var_b =  { {0x6B755F70, 0xA103E9A0, 0xC80DAF69, 0x87A64197, 0x0F951F2A, 0x4859E2A8, 0x3F9FAA9E, 0x11D40E7C},
	{0xB54E8196, 0xD3FBDD47, 0xC4EF59E0, 0x59818B76, 0xE974C334, 0x79B8C4CF, 0xFE4AE209, 0x0332654E} } ;
		static const fp2_t var_expected =  { {0x47AD5940, 0x7665647B, 0x375A289D, 0x2BD7BBBB, 0x55925C11, 0xB829722A, 0x2B7EA61D, 0x1EADBCCE},
	{0xC499C2DF, 0x8EDB0FA2, 0x3382BA4B, 0x9E260EA8, 0x92826AD7, 0x16FDCBDE, 0x7C7FFC07, 0x11E9AE00} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 667 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 668 a1");
	}
	{
		static const fp2_t var_a =  { {0xA4680002, 0x8E4D2A20, 0xC6390938, 0xF127C71E, 0xB490B435, 0x86AB2552, 0x3D0CDDDF, 0x03B379F2},
	{0x2A67D81B, 0xB8FF9F54, 0xABA2DD5F, 0xEE8626F1, 0x819F9E8E, 0x2AFB8195, 0x47283301, 0x170D2BC8} } ;
		static const fp2_t var_b =  { {0x5E6E2B50, 0xFE535019, 0xD3B377CA, 0xA74D977A, 0x44DE8BEF, 0x2EA37F24, 0x6C50CE15, 0x17109FE4},
	{0xFA82DCFB, 0xF6571DCE, 0xA415C6DB, 0x5AC7504A, 0x5668D2F4, 0xE4B3F34C, 0xFF2FE449, 0x095ECA5E} } ;
		static const fp2_t var_expected =  { {0x45F9D4C5, 0x36F9DA07, 0xF2859181, 0xAAFB2FA3, 0x6FB2284E, 0x123BF3AE, 0x10BC0FCC, 0x11C63E90},
	{0x2FE4FB20, 0xC2A88185, 0x078D1683, 0x93BED6A7, 0x2B36CB9A, 0x46478E49, 0x47F84EB7, 0x0DAE6169} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 669 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 670 a1");
	}
	{
		static const fp2_t var_a =  { {0xDC7AE50B, 0x4A48FB89, 0x07ECA026, 0xC1EC80CE, 0xF11F24DE, 0x207A311B, 0xD6FC0C93, 0x0FD65057},
	{0x857D49F0, 0x4CC40B67, 0xE942C48C, 0x51EFA104, 0xB7268360, 0x574D1F4E, 0x4E1AE882, 0x1527CD86} } ;
		static const fp2_t var_b =  { {0x9D14CD56, 0x3FCEFC02, 0xBC8AFBD1, 0xA8D06324, 0x2CE61C09, 0x4FC953A7, 0xC5D50056, 0x1A68D75C},
	{0x6DCCC013, 0x28A155EA, 0xF3249034, 0xD88F37AD, 0x37A84D98, 0x13DEF0A2, 0x9E1DE512, 0x0768D35C} } ;
		static const fp2_t var_expected =  { {0x3F6617C8, 0xB179FF87, 0x4B61A468, 0x7A3D1DA9, 0xC43908DD, 0x8AE52AF4, 0x51270C3E, 0x1A90DD7D},
	{0x17B089DD, 0x2422B57D, 0xF61E3458, 0x79606956, 0x7F7E35C7, 0x436E2EAC, 0xAFFD0370, 0x0DBEFA29} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 671 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 672 a1");
	}
	{
		static const fp2_t var_a =  { {0x6364A2F8, 0xC14E9B10, 0x89004CEB, 0xD01AD667, 0xA5BF4E56, 0xEBF8C647, 0x0063A001, 0x08D1D0A1},
	{0x928F5A20, 0x4F34770A, 0x7B46A99D, 0xE92065FE, 0xA6405193, 0x8FFBB6A7, 0x17780C68, 0x0AE3A3DC} } ;
		static const fp2_t var_b =  { {0x2F45395B, 0x2840497A, 0x4916ECD5, 0xF9870FC7, 0x4E49075C, 0x3A74CF30, 0x9285AA28, 0x183405C7},
	{0x15A12E26, 0xD200D002, 0x79525AF0, 0xA02B273E, 0x15DADD15, 0x52A3EA93, 0x630AF67F, 0x1D50ADAF} } ;
		static const fp2_t var_expected =  { {0x341F69B0, 0x400E5196, 0x3FE9602A, 0x37B4C6A0, 0x57764702, 0x6BB84497, 0xADDDF5DB, 0x15C12F5B},
	{0x7CEE2C0D, 0x2433A708, 0x01F44EC0, 0xAA163EC0, 0x90657486, 0xF78C1994, 0xF46D15EA, 0x12B65AAE} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 673 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 674 a1");
	}
	{
		static const fp2_t var_a =  { {0x4254BFFB, 0xCD83D01E, 0x147DC7B0, 0x408F3376, 0x583E6934, 0x1C524971, 0x82FB63A4, 0x09CECF28},
	{0x58A5B2B0, 0x2D11E86F, 0x28A406B4, 0x80F27B75, 0xD604C6DE, 0x206CFCE6, 0x2BDC7FF3, 0x1728694D} } ;
		static const fp2_t var_b =  { {0x1D01803B, 0xECA8F171, 0x445E2FAC, 0x5EFBEC11, 0x3388F000, 0x69D8B7C6, 0x5BFBD8C0, 0x08A0F944},
	{0xFB1A0261, 0x6B52A903, 0xFFD6AC1A, 0x5C1A7E5D, 0x780755DD, 0xBB48E8A0, 0x16B4B1AB, 0x00FC3F72} } ;
		static const fp2_t var_expected =  { {0x25533FC0, 0xE0DADEAD, 0xD01F9803, 0xE1934764, 0x24B57933, 0xB27991AB, 0x26FF8AE3, 0x012DD5E4},
	{0x5D8BB04F, 0xC1BF3F6B, 0x28CD5A99, 0x24D7FD17, 0x5DFD7101, 0x65241446, 0x1527CE47, 0x162C29DB} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 675 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 676 a1");
	}
	{
		static const fp2_t var_a =  { {0x809DEED3, 0x314377E0, 0x71EB6822, 0x7E02591E, 0x914E19FE, 0x40DECD98, 0xA4C0A2B5, 0x11A05800},
	{0xDF6A09D8, 0x72D48CFA, 0xB756C1C7, 0x7DAC6D1F, 0xCEEEE8E5, 0xC7A5B2D0, 0xD0A3A4E1, 0x0FF27059} } ;
		static const fp2_t var_b =  { {0x6E6D2DFF, 0x863CBD9F, 0x74EEF654, 0x4CB54F5F, 0x6207311D, 0x4028DA51, 0x68183117, 0x11CB1F38},
	{0x26F89455, 0x1A28BC76, 0x4BEF3DA1, 0xF5306C44, 0xE79D30BF, 0xF81B5D56, 0x009A6E33, 0x175F47AC} } ;
		static const fp2_t var_expected =  { {0x1230C0E7, 0x5206BA41, 0xFCFC71E1, 0x926E09BE, 0x2F46E8E9, 0xBAEA40C7, 0x7CA8719F, 0x24F89D4A},
	{0xB8717596, 0xFFABD084, 0x6B678439, 0xE99D00DB, 0xE751B82D, 0x89BEA2F9, 0x100936AF, 0x1DB68D30} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 677 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 678 a1");
	}
	{
		static const fp2_t var_a =  { {0x26B7EDAB, 0x911CACAD, 0x6659BA4D, 0xA772F606, 0xD8863CB5, 0xBD118D8A, 0x2FF59724, 0x13FCD0B4},
	{0x30304427, 0xF7A72626, 0xF25CFB4C, 0x04672772, 0x16DE0DA9, 0xB984C2E0, 0xCFF1116F, 0x0FD937AB} } ;
		static const fp2_t var_b =  { {0x2BD3AFEC, 0x09622806, 0xA0D6C789, 0x3896ABF7, 0x640F16DA, 0x07A2CA3A, 0xC1FEE0A9, 0x2298B59C},
	{0x9F9A609E, 0x35C78AD8, 0x26DC4D71, 0xC6484BD1, 0xEB6E1AED, 0xF66B7189, 0x6700719C, 0x0C192751} } ;
		static const fp2_t var_expected =  { {0xFAE43DD2, 0x2EBA84A6, 0xC582F2D8, 0xCFFD4A0E, 0x747725E3, 0x6FA310D0, 0xADF6B67D, 0x16877F99},
	{0x9095E389, 0xC1DF9B4D, 0xCB80ADDB, 0x3E1EDBA1, 0x2B6FF2BB, 0xC3195156, 0x68F09FD2, 0x03C0105A} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 679 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 680 a1");
	}
	{
		static const fp2_t var_a =  { {0x3C3C71AE, 0xD1CFF552, 0xBC580776, 0x798D4596, 0xB761A0F3, 0x51042C5F, 0xE91EE114, 0x13526BA2},
	{0x53E99865, 0x826973EA, 0xA0B9E595, 0x8099CB3A, 0x3716D74D, 0x849743A3, 0x71AB4589, 0x159E2962} } ;
		static const fp2_t var_b =  { {0x5B9FB463, 0x21B80E9B, 0x92AA9664, 0xD80EA7E9, 0xC1CC2368, 0xADFBDC5D, 0x2E159250, 0x1985405D},
	{0x6E08A0EC, 0x472929AA, 0x58E2F332, 0xEBCFFE88, 0x0BB06F93, 0x2F4F4FFC, 0x55F01CA2, 0x07698125} } ;
		static const fp2_t var_expected =  { {0xE09CBD5E, 0x5717E6B6, 0x29AD7126, 0x029F9DAD, 0xF5957D93, 0x5D3C9D81, 0xFB094EC5, 0x1EF08FC7},
	{0xE5E0F779, 0x3B404A3F, 0x47D6F263, 0x94C9CCB2, 0x2B6667B9, 0x5547F3A7, 0x1BBB28E7, 0x0E34A83D} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 681 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 682 a1");
	}
	{
		static const fp2_t var_a =  { {0xC9EBF867, 0x03546FB6, 0x3BFFEF7E, 0x6791A504, 0xB33DCE9F, 0x46A32DFD, 0xDB05F037, 0x0305686E},
	{0x4F2EAFE2, 0x44AE971B, 0x897391B7, 0xB76390A9, 0xB93E3797, 0xA5734FC9, 0x3C7B56A3, 0x1A5BC4D6} } ;
		static const fp2_t var_b =  { {0x07638A83, 0xA90D558B, 0x1182D3B8, 0x4D153FF7, 0x00505735, 0x68665B47, 0x78075B51, 0x1234B636},
	{0x9AEBF0F7, 0x09FA26C0, 0xAA4A71BA, 0x3A45454D, 0xD0FAB851, 0xA82E6DF0, 0x103528BE, 0x2107088F} } ;
		static const fp2_t var_expected =  { {0xC2886DF7, 0x01471A2B, 0x2A7D1BD9, 0x7B9D650D, 0xB2ED7772, 0x98712036, 0xA2FE94E7, 0x15F416BA},
	{0xB442BEFE, 0xE1B4705A, 0xDF292010, 0xDE3F4B5B, 0xE8437F4E, 0xB7792F58, 0x6C462DE6, 0x1E7820C9} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 683 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 684 a1");
	}
	{
		static const fp2_t var_a =  { {0xD6A8BC29, 0x92D3F159, 0xACE6FAC8, 0x3FA732C4, 0x575DC817, 0xE84AC1AE, 0x8DB77C2C, 0x045D6F7D},
	{0x2D3BC787, 0x93BC8847, 0x7595C665, 0xBF4A9652, 0x23637311, 0xC3FA2BDF, 0x3AD1A513, 0x1D74134A} } ;
		static const fp2_t var_b =  { {0x36D38765, 0x6466939B, 0xE5F88131, 0x067DD817, 0xA98D68C0, 0xC548123C, 0xE5C5B128, 0x09F50BCC},
	{0x2B92F9BB, 0xF19C794E, 0xE2618325, 0x5F0E1948, 0xC24C367E, 0x7C8EEB2D, 0x625FCC09, 0x0A7E09D4} } ;
		static const fp2_t var_expected =  { {0x9FD534D7, 0xD56D5DBE, 0xC6EE79AA, 0x9A4A5AAC, 0xADD05F5F, 0xDD36FCF1, 0xE7F1CB05, 0x1F8BC832},
	{0x01A8CDCC, 0xA2200EF9, 0x9334433F, 0x603C7D09, 0x61173C93, 0x476B40B1, 0xD871D90A, 0x12F60975} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 685 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 686 a1");
	}
	{
		static const fp2_t var_a =  { {0x6A7A8890, 0xB0AB3E3A, 0xD52C270E, 0xC60561BD, 0x29E7CC8A, 0xB0AB39BF, 0x8886F7DB, 0x0F57C3BD},
	{0xF5EFD0F4, 0x808F7690, 0x2C2ECCBF, 0x09C9C7A3, 0xFEF22465, 0x26CE5BB6, 0x72DD91B1, 0x0EB967C2} } ;
		static const fp2_t var_b =  { {0xF2C86971, 0x9DFABE25, 0xD62E418E, 0x807E5D0F, 0x465E0C8A, 0xE24D8995, 0x7E815D07, 0x1B1935C2},
	{0x2BEE053B, 0xA2246631, 0xCA78B57C, 0x2F8E098C, 0x68075CDF, 0xC9ACB86B, 0xD2C4F8AB, 0x0F346339} } ;
		static const fp2_t var_expected =  { {0x77B21F32, 0xB9B08014, 0xFEFDE593, 0xA6A804AD, 0xE389C008, 0x8891FDA9, 0x4A059AD5, 0x1961F27D},
	{0xCA01CBCC, 0x856B105F, 0x61B61756, 0x3B5CBE16, 0x96EAC78E, 0x1755F0CB, 0xE0189907, 0x24A8690A} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 687 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 688 a1");
	}
	{
		static const fp2_t var_a =  { {0x8E8BA400, 0xB46F298B, 0x80737E69, 0x0FC099E0, 0xB1E51799, 0x46423A2E, 0xD205FB56, 0x23BADFE1},
	{0xAED09C2F, 0x06D73504, 0x7650440B, 0x0FAEAB4F, 0xD1C13B84, 0x35EDA8FB, 0x2B98276F, 0x1658F1CB} } ;
		static const fp2_t var_b =  { {0x4041B6D3, 0x0037D433, 0xACC7673B, 0x70D9569A, 0x5C7E3673, 0xACFDC8DA, 0x0CB367FC, 0x1F6D35F6},
	{0x9F95A933, 0x2C5C6BF3, 0x28E4B237, 0x1EE090E9, 0x4BF0552A, 0xDA1473AE, 0x677A849D, 0x1EBB2CBE} } ;
		static const fp2_t var_expected =  { {0x4E49ED2D, 0xB4375558, 0xD3AC172E, 0x9EE74345, 0x5566E125, 0x99447154, 0xC5529359, 0x044DA9EB},
	{0x0F3AF30F, 0x817AC911, 0x4D6B91E7, 0x51EF1A66, 0x85D0E662, 0x160D82CD, 0x041DA2D3, 0x1CC1298F} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 689 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 690 a1");
	}
	{
		static const fp2_t var_a =  { {0x492BAD6C, 0x97E4C1D0, 0x73E0A5A3, 0xDA2FCB8C, 0x7847A500, 0x53035FE6, 0xF510BEEA, 0x13104DA0},
	{0x6005EEF4, 0x22F5A9F0, 0x1B13F8E4, 0x8A61482D, 0x2507007E, 0x951A3673, 0xEFBAD4F2, 0x01A09706} } ;
		static const fp2_t var_b =  { {0x2A5D1E88, 0x30BB8037, 0x2FEB1069, 0xF2CD06AF, 0x768E5B13, 0x87B98C3D, 0x56161388, 0x0BC74076},
	{0x92C2669A, 0xD0BF2B10, 0xC6FC97F2, 0x8A127179, 0xF2308964, 0xB3BA1890, 0xAB5F6013, 0x18AE889E} } ;
		static const fp2_t var_expected =  { {0x1ECE8EE4, 0x67294199, 0x43F5953A, 0xE762C4DD, 0x01B949EC, 0xCB49D3A9, 0x9EFAAB61, 0x07490D2A},
	{0xCD43886D, 0xF9367EDF, 0x54176104, 0x616FD6B3, 0x32D67722, 0x9B946B62, 0x845B74E0, 0x0E1572EA} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 691 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 692 a1");
	}
	{
		static const fp2_t var_a =  { {0xA4CC7E38, 0x56057ED5, 0x781D75DF, 0x96B0124B, 0x06DFF299, 0x378C6783, 0x37C385E8, 0x01E74D35},
	{0x145AAC9B, 0x75022FB5, 0xE390AF54, 0x50F9F40C, 0x825E142A, 0x62707B6F, 0x45C2191A, 0x1B899BA6} } ;
		static const fp2_t var_b =  { {0xB861E03A, 0x985CCDDE, 0x27452F3D, 0xD39E8353, 0x1A13B344, 0xBCE8EF53, 0xE3A9C30E, 0x02E8F952},
	{0x0A534BD3, 0x448057F4, 0x6B1F499B, 0x47890F5C, 0xE65616D9, 0x5A4802F5, 0xE513C991, 0x12691A20} } ;
		static const fp2_t var_expected =  { {0xEC6A9E11, 0x64A8B0F6, 0x50D846B5, 0x24328EF8, 0xECCC3F5D, 0x34D7C5AF, 0x9419C2DB, 0x2421B864},
	{0x0A0760C8, 0x3081D7C1, 0x787165B9, 0x0970E4B0, 0x9C07FD51, 0x08287879, 0x60AE4F89, 0x09208185} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 693 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 694 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 695 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 696 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 697 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 698 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 699 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 700 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 701 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 702 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_b =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 703 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 704 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_b =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 705 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 706 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 707 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 708 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_b =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF09, 0x84FFFFFF, 0xFFFFFF00, 0x1152FFFF, 0xFFFFFF93, 0x8B58107F, 0xBFFFFFE9, 0x1D33E562} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 709 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 710 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_b =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF09, 0x84FFFFFF, 0xFFFFFF00, 0x1152FFFF, 0xFFFFFF93, 0x8B58107F, 0xBFFFFFE9, 0x1D33E562} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 711 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 712 a1");
	}
	{
		static const fp2_t var_a =  { {0x7844657E, 0x1DB4E596, 0x7D340588, 0x522873DA, 0x3CEC0130, 0x44812586, 0xB1007FA1, 0x00B96D01},
	{0x15E68F24, 0x749104E2, 0x051665D1, 0x5CFE4319, 0x2D962383, 0x0FEFD2C7, 0xBFC8D468, 0x00AC0BE7} } ;
		static const fp2_t var_b =  { {0x94ADE593, 0xDFE0859B, 0x0CB7C9A5, 0x29DAD3FB, 0x8AF650FC, 0xE71180B7, 0x496A2D6E, 0x20A63AAB},
	{0x63C30FC3, 0x224C46BD, 0x90A4BE62, 0x92F08812, 0x4560FFD7, 0x1D607C2A, 0x91F101FE, 0x027235F2} } ;
		static const fp2_t var_expected =  { {0x324AD05A, 0xD7D88227, 0xA266008F, 0x7204193D, 0x18F2E6B2, 0x4790E361, 0xB2F780C6, 0x1F55494D},
	{0xA2233BF0, 0x2F45DBC5, 0x814E95B6, 0x665583E3, 0xD6DCF803, 0x841A2437, 0x72A68FBE, 0x0C8B541E} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 713 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 714 a1");
	}
	{
		static const fp2_t var_a =  { {0xF61527A8, 0x416259BF, 0x4FC5447B, 0xEF2CBA26, 0xD6C4776E, 0x0AFCD452, 0xE110A48F, 0x1902EE0C},
	{0xE4C18F70, 0xF103654A, 0xA1DBAFD8, 0xA1BC4DCB, 0x5FF16B41, 0x7A2A7C6E, 0x89086C5D, 0x1CCC99DC} } ;
		static const fp2_t var_b =  { {0x30E2A485, 0xE350E2B0, 0xDF7D0103, 0x8E0B72B9, 0xDCAB15D4, 0x15F0B9E5, 0x2F7B2B8E, 0x2136821C},
	{0xFE053C5D, 0x155F6661, 0x1756DB0A, 0xB0B8B0F5, 0x08A28190, 0x80DB1D73, 0x0758C36B, 0x19F155EA} } ;
		static const fp2_t var_expected =  { {0xF88675D5, 0x60210832, 0xC2A241D3, 0x37BC2FEE, 0xFF0E125D, 0x0105B9BF, 0x10AAAC39, 0x22A9A5F0},
	{0x0BEC3EC8, 0x5184AD2D, 0x9A3DCBD3, 0x3937395C, 0x992153BB, 0x6D9725D6, 0xB652384A, 0x23EB34B5} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 715 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 716 a1");
	}
	{
		static const fp2_t var_a =  { {0x2607431F, 0x97AF53CF, 0x9976F9B4, 0xA105043D, 0x9F7E5C67, 0x2BCBFF4E, 0x74D52319, 0x1D5DC1F7},
	{0x06E98C4F, 0x783E1136, 0xA920E564, 0xCDDDB38D, 0x10EF2DEF, 0x2B035740, 0x153E36AB, 0x228E4BDE} } ;
		static const fp2_t var_b =  { {0xC71E9C1C, 0x9A2FE1CD, 0xD77A098E, 0x2E42729F, 0xF178F93D, 0x9845BE70, 0x0D4E5361, 0x15191017},
	{0xC8848E16, 0x84FEFEB6, 0x511A22BB, 0x10A401CF, 0x23686BF8, 0xCBB44889, 0x1002D046, 0x07511CF9} } ;
		static const fp2_t var_expected =  { {0xF83DCDE7, 0x465C9249, 0x8485DE9F, 0x33B16AD2, 0x60B7A1AA, 0x44F97178, 0x4A1B6540, 0x1661ADBA},
	{0x9D5CEF72, 0x87161E58, 0x3FBCAADA, 0x3C1DB30B, 0xC12066B7, 0x41D7D56A, 0xAB023167, 0x171CB3B6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 717 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 718 a1");
	}
	{
		static const fp2_t var_a =  { {0xCC79A4BC, 0xDC01140D, 0x5604BAEA, 0x1CBA2847, 0x32D66968, 0x3C800AAC, 0xA52B1544, 0x20E28B1F},
	{0x63C70BC7, 0xA480D484, 0xA1BBB5D8, 0x6740B543, 0xC6DE40DA, 0x91ED6CBB, 0x9C643612, 0x11857D88} } ;
		static const fp2_t var_b =  { {0x922A7F78, 0x45A5E834, 0x95F955BB, 0xE782F50D, 0xC1B661ED, 0x4A138926, 0x4953AC1C, 0x23F8C8E0},
	{0xED5510D5, 0x9B26A3F0, 0x8B1A2B0B, 0xB898EDA1, 0xE190A855, 0x8A2C64E8, 0x5C09FA39, 0x1EC69D71} } ;
		static const fp2_t var_expected =  { {0x7E768814, 0xC11ADD09, 0x6B2D1DFB, 0xA1B0BD92, 0xF4338955, 0x0FD5A6FD, 0x14654471, 0x0CC9600E},
	{0xDDC2A4EC, 0x7759DE2D, 0x62764468, 0x11C94080, 0x46B584FF, 0x0B797659, 0xC4A015EB, 0x00B41391} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 719 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 720 a1");
	}
	{
		static const fp2_t var_a =  { {0xB206B608, 0x09B1DF6A, 0x6ABDCAF3, 0x1BFC84A3, 0x3B5EA8AA, 0x5CBAE8D4, 0x8D28BCFF, 0x16E551E4},
	{0xA478A277, 0x742D37D1, 0xE77D8EEC, 0xCA7C5C1D, 0x0E60C541, 0x9744BA17, 0x8608DA1B, 0x21FBC810} } ;
		static const fp2_t var_b =  { {0x06BA69BC, 0x2ED6FBC8, 0xD79E448F, 0x4315C6B2, 0x2967FED6, 0x5144B03E, 0x24D69815, 0x12B123CC},
	{0xD99A2B6F, 0x2BA79535, 0xF98CCBC1, 0xCBC6D0B2, 0x614B1A02, 0xA7117B11, 0x76DEF566, 0x0CBC6625} } ;
		static const fp2_t var_expected =  { {0x47B0D6F7, 0xDBF8E368, 0x880E42F3, 0xA0C3E78D, 0x68C7DA4A, 0x92BA4057, 0x5CC7739C, 0x04CB8385},
	{0xAF4F14AF, 0x7B2256E0, 0xE1494F9C, 0x90A8009B, 0xCE06DA02, 0x6B4A7AEC, 0x7EB606FE, 0x0C71CDFE} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 721 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 722 a1");
	}
	{
		static const fp2_t var_a =  { {0xFCE87043, 0xC9F89665, 0x8C038FAC, 0x4948F3F4, 0x91D376DF, 0x1714977E, 0x8FCABC64, 0x0E544AA4},
	{0x85F9EB18, 0x6A1C8132, 0x6C228FEA, 0x9E721FC8, 0x97BE604D, 0xFC0FBA60, 0x089C35AD, 0x1627DCA9} } ;
		static const fp2_t var_b =  { {0x131505F7, 0x6D3FE742, 0xDFE315A3, 0x7FC592F4, 0x4EE8D8B5, 0x859046CA, 0x6B2E5280, 0x075F6B35},
	{0xA3F37790, 0xF6D1938A, 0x7E0FAA1E, 0x8326EFC6, 0x13F34DAD, 0xE9EDD020, 0xBCF0C2D1, 0x016BBC9D} } ;
		static const fp2_t var_expected =  { {0x1D01A4AB, 0x16715B23, 0xE0974AFC, 0x554FFA52, 0x4802E1BF, 0xF2F657A9, 0x192408AC, 0x03974D02},
	{0x80A35B82, 0xCB917481, 0x62731FE8, 0x038B29EB, 0x0348F5D9, 0xE3B4A397, 0x4D631482, 0x058DDE28} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 723 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 724 a1");
	}
	{
		static const fp2_t var_a =  { {0xEA068E87, 0x8B2148FE, 0xE3093824, 0xFEEEB794, 0xC59AD691, 0x804463DD, 0xF74EB0F5, 0x19B819E8},
	{0xF7599554, 0x5DE181D0, 0xC2644A96, 0x3D9C3162, 0x363F1A29, 0x426999EA, 0xE603794D, 0x174A6CDC} } ;
		static const fp2_t var_b =  { {0x14477E4D, 0x54E2520D, 0xDF469645, 0x37B607E3, 0x79199A5B, 0x8DFA7647, 0x7AAF02E3, 0x009C7583},
	{0x6D15611B, 0x0FB7AB68, 0xB227FA0F, 0xE1DDE026, 0x98237ABE, 0x4FB8E983, 0x4A43B8D7, 0x1140D0B0} } ;
		static const fp2_t var_expected =  { {0xA69FBC2C, 0x891D8FF3, 0x3987AB92, 0x29C9B2AC, 0x9E91CEE5, 0xFDB905BF, 0x45D72FB2, 0x00E52F7D},
	{0xDFABD08B, 0xD7280D4F, 0xCD8FBB5A, 0x6621E184, 0xC8D38552, 0x01F4FF9C, 0x68678AD7, 0x1A2EA5A3} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 725 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 726 a1");
	}
	{
		static const fp2_t var_a =  { {0x924B1C47, 0x3AA2F6B3, 0x397C6D84, 0x17405FB3, 0x7586F822, 0x7648F2AB, 0x349017BF, 0x0C780DD4},
	{0x2111B046, 0xC8D9717D, 0x355B8022, 0xB737B6E6, 0x596C9472, 0x73982CD7, 0x76930AB8, 0x12C1541B} } ;
		static const fp2_t var_b =  { {0x84FEA7CC, 0x4C8572B2, 0xB8EA85FE, 0x94F3321F, 0x2411B4B1, 0x0E840DA6, 0x50038735, 0x18CA513E},
	{0xBD641F34, 0x29D47C0A, 0xA8B704E0, 0x5F1DF5C5, 0x068640C0, 0x6DEA6EEC, 0x8C635D91, 0x1AEC59CD} } ;
		static const fp2_t var_expected =  { {0xDBE79EF7, 0xF1944524, 0x34807A2B, 0x69B8D406, 0x11D8C1D1, 0x2A63E9B8, 0x93DEFB81, 0x01EEFCD4},
	{0x65D7DCE4, 0xF88E9954, 0x4541DF55, 0x19C39C3D, 0xE40A2BD4, 0x012751AA, 0x67629C57, 0x22124C12} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 727 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 728 a1");
	}
	{
		static const fp2_t var_a =  { {0x9F57CB0B, 0xFD2DD6A0, 0x62773892, 0xC442D452, 0x10533155, 0xB4FCE82B, 0x95FF1DC9, 0x054C96E6},
	{0xE677AA09, 0x2F81D9E4, 0x17086D1C, 0xD788F4B0, 0x0F3E1609, 0x545D9D0A, 0x1FBBE69B, 0x0DD53D53} } ;
		static const fp2_t var_b =  { {0x687BBA8D, 0x6586E46C, 0x7F93E773, 0x55E611FF, 0xAE465FB1, 0x560476D1, 0x387EEE2C, 0x1CEF3BBF},
	{0xFD2202D6, 0x68D37B58, 0x9242AA21, 0x84E4F723, 0xB0AAF792, 0x61355738, 0x092D648B, 0x00335615} } ;
		static const fp2_t var_expected =  { {0x637C1B3A, 0xD738AA42, 0xAA213A29, 0x4F66D459, 0x97F424BE, 0x1CD03C1E, 0xCCB6A9E7, 0x1DF1F9EE},
	{0xFDE70879, 0x6A232393, 0xF27AA9DF, 0x5DA7DEC3, 0x7E9B41BD, 0x9E26312D, 0xF3436FF9, 0x0D5F2FFC} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 729 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 730 a1");
	}
	{
		static const fp2_t var_a =  { {0xC429C568, 0x8232624E, 0x05AEA736, 0x055B73CF, 0xFED5F60F, 0x3A2117B8, 0x47588CE9, 0x11E7ADDB},
	{0xD47185DD, 0x94D44637, 0x3429A198, 0x0964633E, 0xB28AE30B, 0xA59FAF8C, 0x8F577139, 0x1771EE7D} } ;
		static const fp2_t var_b =  { {0xE969AC37, 0xC0299BE4, 0x8728AFBF, 0xA3F59BC2, 0x49EF4B18, 0x217E342F, 0x30C25D4C, 0x1D1AC691},
	{0x72F3B285, 0xC8661851, 0x970F6F2D, 0x3421733D, 0xBDABEA15, 0xC7B745FA, 0x85635361, 0x2470F9E1} } ;
		static const fp2_t var_expected =  { {0x5B447C91, 0xAD73A2F2, 0x15AD5467, 0x4257A73F, 0x5B0AE2B2, 0x3FBAE2F4, 0xDA5C2675, 0x14BAB49B},
	{0x67D2E376, 0x800B48B1, 0x17BAB67E, 0xB751B9CF, 0x94270F1B, 0xF7F4E8D6, 0x627C8FFC, 0x22BBA214} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 731 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 732 a1");
	}
	{
		static const fp2_t var_a =  { {0x708DF269, 0x7C192EBC, 0xD11400A3, 0x2AD8FCB6, 0xA577CEB6, 0xC3BC8C99, 0x72DA0F04, 0x0AB7A618},
	{0x51439EBE, 0xE6D3AA9F, 0x3AEBC248, 0xA555C267, 0x0762BE21, 0x29C827AB, 0x5530942A, 0x019D93CD} } ;
		static const fp2_t var_b =  { {0xD15976AB, 0x9C2A06F5, 0x2A9E5025, 0x5B316987, 0x5DE6F3B6, 0x2CD82F8A, 0x90414CEC, 0x086F77CE},
	{0x1334C525, 0xB2238AD2, 0xE717050B, 0x025D49A0, 0xF85A2055, 0xEB3AD806, 0xFF1DE903, 0x0EB34B03} } ;
		static const fp2_t var_expected =  { {0xB6661AB8, 0xF9428DCB, 0x6B36CE35, 0x2B67FC12, 0x3B00C5E2, 0x04033F06, 0xDBE8B314, 0x20EDD907},
	{0x4E5C9981, 0xCB205FBB, 0xB592D4DB, 0x5C0705AC, 0xB50C712B, 0x09F5D093, 0xE1B47FD8, 0x14BF37A1} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 733 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 734 a1");
	}
	{
		static const fp2_t var_a =  { {0xE88639AB, 0xD3DC3428, 0x7694AA5D, 0xF43D08EB, 0xE1C3838D, 0x126B8B84, 0x32EC4C36, 0x09B4C536},
	{0xE7F283F9, 0x277C40B5, 0x1FC3725B, 0xCE531497, 0x6AAB5F54, 0x6DD20CFE, 0x1C6935DB, 0x02173218} } ;
		static const fp2_t var_b =  { {0x26000C12, 0x7ED41F38, 0x2F8A7310, 0xA895BB35, 0x41164915, 0x1426BA14, 0x6AAF920E, 0x036885B5},
	{0xE7262F89, 0x4CDEC927, 0x0B7FCA8B, 0x61D690D8, 0xF7B18C2A, 0x6A48E993, 0x56520E4C, 0x0DB30E87} } ;
		static const fp2_t var_expected =  { {0x5F531493, 0x0F7E9CCD, 0x041BDCFF, 0x60BF6978, 0x44AA7969, 0xA60A6984, 0xAB3AFCC4, 0x0BC12756},
	{0x7F6FD1FC, 0x912857D1, 0x231DCED7, 0xDA7F184C, 0xEB52E090, 0x30BDCB79, 0xA64C7409, 0x18AC00E6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 735 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 736 a1");
	}
	{
		static const fp2_t var_a =  { {0x0233D9A2, 0xB15F7868, 0x9D5B1CF7, 0xCF47C8AE, 0x56ADC852, 0xD1DC02AE, 0x25778FA8, 0x05DE93E6},
	{0x985A3B4D, 0x3E7E58CB, 0x9BBBB70C, 0x3010A1E1, 0x15656E96, 0x5AB85268, 0x2746A52B, 0x07F11F5D} } ;
		static const fp2_t var_b =  { {0xC101B4A6, 0xF2D25944, 0xC6DAD346, 0x83D0AF61, 0x3A704B7A, 0x9E330CF0, 0xC79F17C0, 0x12CAF7AE},
	{0xAE5D1A26, 0x1DCF98A4, 0x0D73D0DA, 0xE31FECA3, 0xD007E728, 0x47AFE11E, 0x6BE4C171, 0x18481F17} } ;
		static const fp2_t var_expected =  { {0xA3D97C60, 0xF2C08147, 0xD8D2E041, 0x02AF85B2, 0xD7066809, 0x18360E7B, 0xF0D0041C, 0x200250BD},
	{0xF9DBD19A, 0x322B52ED, 0x7EC34F23, 0x5CAE5556, 0xF0DA9C95, 0x3A85269F, 0xC79F7B92, 0x16302457} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 737 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 738 a1");
	}
	{
		static const fp2_t var_a =  { {0x46D04396, 0x18259D98, 0x6867D501, 0x77529CD3, 0xE0FF9B73, 0x7639E3D3, 0x81E5ED85, 0x0D7474D6},
	{0xB6D2FD5A, 0x9D09F6BB, 0x0C06AD41, 0x6D8D37BA, 0xB1250386, 0x11FA7D7D, 0xAD8E1C37, 0x07B71796} } ;
		static const fp2_t var_b =  { {0xF04203C1, 0x9936FE26, 0x78F72A9D, 0x12D4394E, 0x018A93C9, 0xCE83CD69, 0x934BE262, 0x09F93782},
	{0x4BFD960B, 0x89CF9653, 0xBE07C477, 0x2E32278F, 0x268DBE69, 0x5D517ACC, 0xF7E29403, 0x0A3D6EAF} } ;
		static const fp2_t var_expected =  { {0xCC26C4E2, 0xEEF931DA, 0xA2A08AB7, 0x473650D9, 0xBF33FE13, 0x3FEDBF55, 0xDAB8CB11, 0x0C7D3E1D},
	{0x9C23CC2C, 0xA6A89447, 0x7C90005E, 0xFF27CCBE, 0xB2D75521, 0x4340B0F2, 0xE6957874, 0x113C9C34} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 739 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 740 a1");
	}
	{
		static const fp2_t var_a =  { {0xC5A438E9, 0xFBBCE823, 0x1D1F8043, 0xC7EFB1A7, 0x8F3C67BA, 0x90252F0B, 0xB6B15FC3, 0x1162D8D3},
	{0xF23C358E, 0xA6B31552, 0x2034EE58, 0xC457C521, 0xA279664F, 0xDBB1C69F, 0x9E9E9562, 0x0F4B04EC} } ;
		static const fp2_t var_b =  { {0xDF4A34E8, 0x43694B03, 0xE552CA93, 0x79F8BFC8, 0xFFF231EA, 0xFA6F3FD9, 0xD3B687F6, 0x20147C60},
	{0x2B9EE63B, 0xC7F7EA53, 0xE3ED64FD, 0x4D57A96B, 0xE767FF8F, 0xD7122C8B, 0x212A2FF1, 0x1437F163} } ;
		static const fp2_t var_expected =  { {0x4891EF31, 0x34EE3027, 0xD708D23A, 0x4196A89E, 0xDB692B05, 0x327BD933, 0xEE3E8926, 0x14C43A8D},
	{0x94ABDAE7, 0xE348967F, 0x5A9CD7CB, 0xB775768A, 0x8B9585C7, 0x7286F7C5, 0xC7F93E67, 0x1BFE343B} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 741 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 742 a1");
	}
	{
		static const fp2_t var_a =  { {0xE4D6813A, 0x28DEE2B7, 0xD0836B82, 0x0A200544, 0xA0C5EC12, 0x49C5BD8F, 0x4BC56CCC, 0x2135E3FA},
	{0x22B08E41, 0xDC4A7F3B, 0xC3B21F3F, 0x3D968669, 0x7D402312, 0xA2E8CE35, 0x65225B53, 0x0FD66324} } ;
		static const fp2_t var_b =  { {0x5BAD9862, 0xC3EF7B65, 0x30011020, 0xC80F0238, 0xAE7BF18E, 0x25902CC7, 0x12557B78, 0x0D3EC533},
	{0xDB022AE7, 0x35463E69, 0x99ABC521, 0x0C7E0266, 0x85105E20, 0x6709A457, 0x3F7324BA, 0x0C39AC1C} } ;
		static const fp2_t var_expected =  { {0x9FEB238C, 0xCAD83957, 0xEFC94FCB, 0xB63261B0, 0x93C97687, 0xEA4ADB0E, 0xDCC4A04F, 0x17E4DCE9},
	{0xE432A8C0, 0xDB8E988E, 0x60EE79B9, 0xC7926944, 0x9DBC57F4, 0x203B7C0E, 0x1B349859, 0x0B07A074} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 743 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 744 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 745 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 746 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 747 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 748 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_expected =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 749 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 750 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 751 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 752 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000010A, 0x22000000, 0x00000113, 0x4FCE0000, 0x00000075, 0x2EDC3D00, 0x80000018, 0x07EF7F1F} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 753 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 754 a1");
	}
	{
		static const fp2_t var_a =  { {0x461ACC07, 0x4E16D43D, 0x91A2D730, 0xBD4E3000, 0x4FEF7D42, 0x5A0EECE8, 0x7B0CBD44, 0x08377E29},
	{0x45788F91, 0xCCE1350B, 0x1A7EE424, 0x3870C567, 0x04899A71, 0xC6F9CDA9, 0x7A17A85C, 0x21A80993} } ;
		static const fp2_t var_expected =  { {0xB5F15F87, 0x51EB5A6F, 0xC0C55FF0, 0x8B4EF1A4, 0x72D7DF74, 0x5430E212, 0x6295A33E, 0x05EA535C},
	{0x06C72BC1, 0x77591814, 0x84B63DCF, 0xCFE5BEBF, 0xD5555DF5, 0xFB930A89, 0x7551E9FB, 0x12F3C359} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 755 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 756 a1");
	}
	{
		static const fp2_t var_a =  { {0xCDB3B968, 0x058B8C4E, 0x3E953A20, 0x52D2423C, 0x82294E47, 0x20D93B4E, 0xE6793B75, 0x2482AA9B},
	{0x4B39B7BF, 0x48E66C90, 0x461955DF, 0xAE0EFC4C, 0x4A166B8D, 0xD2348163, 0x3E012538, 0x0B214044} } ;
		static const fp2_t var_expected =  { {0x328F8843, 0xCE982295, 0xE416FC6A, 0x6C1D76D2, 0x9DFF2868, 0xFC796535, 0x23EBEEA6, 0x08E32970},
	{0xFFAFCE58, 0xE3D3C223, 0x8F984EFC, 0xD01D25D6, 0x118277BF, 0x9570365D, 0x148AD483, 0x1E72BD91} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 757 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 758 a1");
	}
	{
		static const fp2_t var_a =  { {0xB3DAFDAE, 0x821E708D, 0x19EC5AB9, 0x5207A389, 0x3256C3AC, 0xA766AC09, 0x116537F8, 0x24AD6C34},
	{0x274CD259, 0x9D111CC5, 0xF424D0D3, 0xE356BCFF, 0x398F18DE, 0x9F090B31, 0xCA1DFB2C, 0x1A340E3C} } ;
		static const fp2_t var_expected =  { {0x5FAB1815, 0xB24CEEC7, 0x28977027, 0xB573CC8E, 0x5B0B0B96, 0x0C33253A, 0x8833CE6E, 0x04197F67},
	{0xE6ACDA9D, 0x2745CB42, 0x63F5B919, 0xE76CABA5, 0x8E4D1532, 0x5B3A8945, 0x47ADB9E2, 0x22E9B4DC} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 759 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 760 a1");
	}
	{
		static const fp2_t var_a =  { {0x0E2E403B, 0x760C47FF, 0x2EDE20A6, 0xB408B83C, 0x668A150F, 0x6D6D4A20, 0xD4A0B661, 0x1EEBF03C},
	{0x30BA121C, 0x6FDF94F7, 0xB4B1B204, 0xB7A93FB6, 0xFB1C2E3F, 0xDB1BD8CE, 0x8B38DCBF, 0x04E7037C} } ;
		static const fp2_t var_expected =  { {0x1DBBD987, 0x986420B6, 0x94517A4A, 0xD6C92865, 0x9A4E92FD, 0xD3DD831B, 0x25318BEF, 0x05B2B8EA},
	{0x04313F23, 0xB7A05741, 0xD97EE15B, 0xA5843290, 0x98366846, 0xE498F1AD, 0x70E814ED, 0x146AB9E0} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 761 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 762 a1");
	}
	{
		static const fp2_t var_a =  { {0x159A591A, 0xCAAFEAC1, 0x616CD3CF, 0xE9278912, 0x4AB8792E, 0x8B0DA53E, 0xAFA948FE, 0x219BC600},
	{0x69D28D1E, 0x8480595E, 0xABEACCC5, 0xEF3C543C, 0xE18C2FA8, 0x57B485AB, 0xFBBDDF4F, 0x046E8113} } ;
		static const fp2_t var_expected =  { {0x2ABC1681, 0x42F4F9A9, 0xD2FB4D6C, 0x7F3EF779, 0x3C7D6E2E, 0x6F315769, 0x5286DA40, 0x0DF63CC3},
	{0x06882228, 0x9D888C6D, 0x06F645F1, 0x63EC9061, 0xBA527ADC, 0x553EC043, 0xBED74151, 0x1440235C} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 763 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 764 a1");
	}
	{
		static const fp2_t var_a =  { {0x1CD305DA, 0x83BF84F7, 0xBEFD90DC, 0x0D05109D, 0x11933EAF, 0xB0DDCA46, 0x37829E61, 0x0B3EF82F},
	{0xD8913BF1, 0xC70CABD3, 0xAA7C76C9, 0x46B72495, 0x3849213A, 0xFA2E8F63, 0xA6782E45, 0x038C08C0} } ;
		static const fp2_t var_expected =  { {0xBA015644, 0x16E8EF3D, 0x433C0931, 0x1D66FDB4, 0x1C7BCC3E, 0x3AC1C67C, 0xD2908F70, 0x1C5581F9},
	{0xD8065A93, 0x1DC848DE, 0x11CF51A2, 0x970144E4, 0x4A42173B, 0xD0030C06, 0xFB493EAB, 0x09BF6C75} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 765 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 766 a1");
	}
	{
		static const fp2_t var_a =  { {0xBE48756C, 0x9ED6827B, 0x2F2533D0, 0xD87D932E, 0xB348ACF4, 0x90DEECDF, 0xA5E89258, 0x0F631E89},
	{0x8512F00E, 0x500F217D, 0xC609D015, 0xEDBE049B, 0x59145D2F, 0x0CD99BFD, 0xBA4EA4F7, 0x12F6F6BD} } ;
		static const fp2_t var_expected =  { {0xCEF5DAD2, 0xBBD53CC8, 0xA741C2C7, 0x3695667B, 0xD36249D7, 0xF4AC1C44, 0xC1A00474, 0x19E4C69A},
	{0x793704A2, 0xF4AEA12E, 0x4307799E, 0x9EA94FD6, 0xA35FE6B6, 0x51DA7052, 0xF7AA4F2D, 0x23B5BA78} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 767 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 768 a1");
	}
	{
		static const fp2_t var_a =  { {0x0EB65859, 0x69E899DD, 0x0F0F0118, 0xA2F6C9BF, 0x5ADBDB5F, 0x0F41E0E5, 0xE0ECDDF0, 0x1230035C},
	{0x8A41C5FA, 0x75CDECB0, 0xEABC93F2, 0x373688C2, 0xEA66DDA0, 0xB1A51CD9, 0xB927EE61, 0x08E69FA3} } ;
		static const fp2_t var_expected =  { {0xE3A4FD29, 0x82F6A5EA, 0x1B51761C, 0xE74F8853, 0x64C930C7, 0x6FBCC1A6, 0x93598C9C, 0x0867A79F},
	{0x095197A2, 0xC71E406A, 0x11A1E44E, 0x0DE96CC9, 0x4DF01A78, 0x0F373E99, 0xB917676F, 0x0CAA586C} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 769 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 770 a1");
	}
	{
		static const fp2_t var_a =  { {0xFB18CAE2, 0xD02341B2, 0x0A0FC67C, 0xF9535FDD, 0xEC7DBED4, 0x00FF62E7, 0x7BA3D81B, 0x12482829},
	{0x30183F35, 0x7F3AF248, 0x8DFC2294, 0x598C9EC5, 0x99CF6DD2, 0x7A1B96FA, 0x81DBAABD, 0x088289F8} } ;
		static const fp2_t var_expected =  { {0x093D4613, 0x1BA39406, 0x2E6958C2, 0x3F70BAB3, 0xFBC85BF6, 0xF0DA6821, 0x615BA766, 0x1FD2DBCC},
	{0xA73EFF0D, 0x88E4839F, 0x4A09F5BF, 0xDC6D6D73, 0x346C7A4E, 0x7A3F6D44, 0xE28488F7, 0x22050A55} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 771 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 772 a1");
	}
	{
		static const fp2_t var_a =  { {0xCCFE746F, 0x4285566B, 0x346DB7BD, 0x7C8AB7DD, 0xF984E10F, 0x9D1196E9, 0x4BD64984, 0x0E3FD67B},
	{0x3C25659A, 0x954D84DD, 0x8B685FB3, 0xA4F63D13, 0xFE6110D1, 0x8B6FB648, 0x2BD68791, 0x22157A8E} } ;
		static const fp2_t var_expected =  { {0x4BEE9E7C, 0x38EA10F7, 0xD2C97FF8, 0x78FF5ED8, 0x9CDC1161, 0xFF1968D1, 0xD3A0A6BB, 0x221A54CF},
	{0xC24AC6D4, 0xB899815B, 0xA74717C7, 0xC09D0CAF, 0x6B61BCC0, 0x6A2B7B5B, 0xC596CB12, 0x19C16F07} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 773 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 774 a1");
	}
	{
		static const fp2_t var_a =  { {0x7D5542E6, 0x9ACD306D, 0xBF6595F2, 0x9CC1BA5D, 0xFE5ABF9E, 0xC4DEEBFA, 0xA5DDB02C, 0x0C24EE84},
	{0x191C68B4, 0x7378B356, 0x4E98B82F, 0x46217DA5, 0x64BDC67F, 0x53F4E8E5, 0xD92E06A2, 0x169D1496} } ;
		static const fp2_t var_expected =  { {0xD8F012A8, 0x1FBB6FAE, 0x26293CE3, 0x56A823A6, 0x5D30CD55, 0x9976B10E, 0x601AFD80, 0x1ECA1B59},
	{0x10FA8DEF, 0x4760699D, 0x1130FA05, 0x8DA151E7, 0xE3C5EDC4, 0x2FF19713, 0x97597399, 0x22E3810F} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 775 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 776 a1");
	}
	{
		static const fp2_t var_a =  { {0x5D78398C, 0x588F80EF, 0x269FAFE6, 0xCAA05C8B, 0x26A75F62, 0x5894D1BF, 0x3C874BDA, 0x1144DFCC},
	{0xCDBA9FE9, 0x05153AA7, 0x1BA8548B, 0x307A00D6, 0x35E3FDB5, 0xD6EBBFB0, 0x449F351D, 0x1BE3B6D8} } ;
		static const fp2_t var_expected =  { {0xD6889B29, 0x804CA7DF, 0x281B7D2F, 0x7634FD7B, 0x36463E18, 0x7738697D, 0x7DFD0463, 0x1BBB8BB0},
	{0xEF02AEDF, 0xA164BABC, 0x0A3830E2, 0xE50FF598, 0x1ABFC2D0, 0xE55BD13F, 0x5C5BF36B, 0x04A09E62} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 777 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 778 a1");
	}
	{
		static const fp2_t var_a =  { {0x186FB490, 0x91782285, 0x3B58EFEC, 0x467E0340, 0x45307694, 0x6F9B5330, 0x6FF06879, 0x1B2539E0},
	{0xB1237AAF, 0x57EDAF64, 0xEBB3E5C6, 0x4B7D3860, 0x4087FFBE, 0xB698E42E, 0x108A85C7, 0x0C7AC0BA} } ;
		static const fp2_t var_expected =  { {0xB4208716, 0xF8E066D8, 0x0A1B0763, 0xB85411E8, 0x3265CCC0, 0xD67A25B4, 0x2AA3ECAF, 0x00701876},
	{0x0CB3527F, 0x6D74E7F4, 0x3C1BEB94, 0x102B179B, 0x208CBE76, 0x9621A42D, 0x7E505D70, 0x1226EE67} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 779 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 780 a1");
	}
	{
		static const fp2_t var_a =  { {0xD29F1203, 0x60DE0DF1, 0x57C1B5D0, 0xAB79A6F0, 0x1600D9D8, 0x274C4575, 0x670F95EA, 0x0BA7B615},
	{0x0E9CFA79, 0x3FC14704, 0x2A0EAA6C, 0xEDB6DF42, 0x56297350, 0x87C8A9CA, 0x7C976BB4, 0x19AAE499} } ;
		static const fp2_t var_expected =  { {0x9D5D187A, 0x4A4D5C13, 0x4586DB1C, 0xC5798A4E, 0x0CFB0D7A, 0x6C9D10AB, 0x8703CCE6, 0x0D510CEF},
	{0x3C3A2174, 0xF9E80FF0, 0x543C9C29, 0x05DC9061, 0x3EDD387C, 0x225636F7, 0x94567EE7, 0x1B574E9F} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 781 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 782 a1");
	}
	{
		static const fp2_t var_a =  { {0xCACFC0F4, 0xAE7E5175, 0x523EB708, 0xC8C605B9, 0xFF98A75A, 0x73A5FA58, 0xDB38C431, 0x0BA2F0A5},
	{0xD4A92837, 0xF8FED31A, 0x21ACE221, 0x04B3ED86, 0xD65A1544, 0x91B64C68, 0xAF1E2195, 0x15E54D57} } ;
		static const fp2_t var_expected =  { {0xC9D65396, 0xD2FF2BF5, 0xA9E1426A, 0xBB9A2533, 0x67FD15FC, 0xA5E12FBD, 0xD73A89DB, 0x07135AB1},
	{0x7AC9F5FC, 0xB71B2778, 0x2A1A321B, 0xC0AC00B2, 0x25CCCEDF, 0x27EC36CF, 0xF4F997C4, 0x242F6BE1} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 783 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 784 a1");
	}
	{
		static const fp2_t var_a =  { {0x6FC32D53, 0x24574F28, 0xF57CB7BB, 0x68211656, 0x435947FC, 0xB18448CD, 0xDEFABA33, 0x20AD4C1E},
	{0xBA12BDB5, 0x0EC73DA9, 0x15B53F2C, 0x6DAF154B, 0x045CC873, 0x54438BCE, 0x0A935308, 0x1CEF4EA5} } ;
		static const fp2_t var_expected =  { {0xC7828032, 0x898902F0, 0xC99274D6, 0x56401087, 0x7B458D7E, 0x4FD7F4F7, 0x7D1862B8, 0x11046BE6},
	{0xBC31072A, 0x6CF87601, 0x62B63C3C, 0x41E471CE, 0x21911D72, 0x7E2A9782, 0xFAC55F5F, 0x156120CB} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 785 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 786 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 787 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 788 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x0000000A, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 789 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 790 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x0000000A, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 791 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 792 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000009, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 793 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 794 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x0000000A, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241},
	{0x00000009, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 795 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 796 a1");
	}
	{
		static const fp2_t var_a =  { {0x813C015C, 0xE058A05A, 0xBD86BF8F, 0xC9042992, 0xD6F8E586, 0xFB45045D, 0x54E4ADE3, 0x24B309EB},
	{0x0F45C211, 0xCBD7C23D, 0x1A585662, 0x01815153, 0x51E8E421, 0xB2C07856, 0x7DA98987, 0x02DC85B1} } ;
		static const fp2_t var_expected =  { {0x409E00AE, 0xF02C502D, 0x5EC35FC7, 0x648214C9, 0xEB7C72C3, 0xFDA2822E, 0xAA7256F1, 0x125984F5},
	{0x87A2E112, 0x396BE11E, 0x8D2C2B3B, 0xB15128A9, 0x28F47214, 0xB67A62EB, 0xDED4C4C4, 0x13FFF519} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 797 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 798 a1");
	}
	{
		static const fp2_t var_a =  { {0x9E33D5C1, 0x8FEAA2D8, 0x2959A934, 0x4E46F918, 0xEBCC9951, 0x989B51F0, 0xC8C1C1E4, 0x144F7856},
	{0xB774FDE3, 0x7A028669, 0x9F410E71, 0xDBBA97EA, 0xCF4CCD7E, 0xCB511E98, 0x16909333, 0x12468F57} } ;
		static const fp2_t var_expected =  { {0x4F19EAEA, 0x1B75516C, 0x14ACD4A4, 0xD7B3FC8C, 0x75E64CAC, 0x2967CFB8, 0x8460E0F3, 0x1CB96E6C},
	{0xDBBA7EFB, 0x90814334, 0x4FA08742, 0x9E6DCBF5, 0x67A666C3, 0xC2C2B60C, 0xAB48499A, 0x1BB4F9EC} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 799 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 800 a1");
	}
	{
		static const fp2_t var_a =  { {0x08706A7A, 0xCD5445F9, 0xB6DEB874, 0xC1DB819D, 0x075F3CD5, 0x73DD15D2, 0x1000DE94, 0x25150F2B},
	{0xE448A652, 0x844849AB, 0xAABFEDB6, 0xCB27A4B7, 0x040454D4, 0x470EFEC9, 0xA164EB43, 0x01BDAFEC} } ;
		static const fp2_t var_expected =  { {0x8438353D, 0x66AA22FC, 0xDB6F5C3A, 0xE0EDC0CE, 0x03AF9E6A, 0x39EE8AE9, 0x88006F4A, 0x128A8795},
	{0xF2245329, 0x422424D5, 0xD55FF6DB, 0x6593D25B, 0x82022A6A, 0xA3877F64, 0x50B275A1, 0x00DED7F6} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 801 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 802 a1");
	}
	{
		static const fp2_t var_a =  { {0xC02E71B3, 0x6FBB9045, 0x3DF25348, 0x184D4269, 0x1A8E7B14, 0x8D7371A0, 0xB76FE2FF, 0x1F3D02E2},
	{0xB73DDD16, 0x46146E58, 0x33CF627B, 0xAAF1E80E, 0x017A2F6D, 0x1EAD4519, 0x4635D796, 0x17FF8E27} } ;
		static const fp2_t var_expected =  { {0xE01738E3, 0x0B5DC822, 0x9EF929AE, 0x3CB72134, 0x0D473D8E, 0xA3D3DF90, 0x7BB7F180, 0x223033B2},
	{0x5B9EEE8B, 0xA30A372C, 0x19E7B13D, 0xD578F407, 0x80BD17B6, 0x0F56A28C, 0xA31AEBCB, 0x0BFFC713} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 803 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 804 a1");
	}
	{
		static const fp2_t var_a =  { {0x07EF5ABC, 0xAB26E4F8, 0xD7D66069, 0xD6D7E2F5, 0x55D76EAD, 0x4FD5ED90, 0x0442990E, 0x144122E5},
	{0x92199279, 0x1CE0CCB3, 0x759D61D0, 0xB163D94E, 0x17413D5F, 0xEAAFA2C2, 0x2EBED3F8, 0x24C8F5EF} } ;
		static const fp2_t var_expected =  { {0x03F7AD5E, 0xD593727C, 0xEBEB3034, 0xEB6BF17A, 0x2AEBB756, 0x27EAF6C8, 0x82214C87, 0x0A209172},
	{0xC90CC946, 0xE1F06659, 0x3ACEB0F1, 0x09426CA7, 0x0BA09EB4, 0x5271F821, 0xB75F69FD, 0x24F62D38} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 805 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 806 a1");
	}
	{
		static const fp2_t var_a =  { {0x5E822AC0, 0x18D1333B, 0xDEC730AF, 0x593E6753, 0x2B663BC5, 0xDB206DFB, 0x42A20E55, 0x0776F74A},
	{0x15FDE597, 0x1B7C8E52, 0xE7172059, 0x4312BFA4, 0xD8219849, 0xF666A51F, 0x03F89714, 0x172EFFD8} } ;
		static const fp2_t var_expected =  { {0xAF411560, 0x8C68999D, 0xEF639857, 0xAC9F33A9, 0x95B31DE2, 0xED9036FD, 0x2151072A, 0x03BB7BA5},
	{0x0AFEF2D5, 0x613E4729, 0x738B9036, 0xD219DFD2, 0xEC10CC28, 0x584D794F, 0x21FC4B8B, 0x1E29322D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 807 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 808 a1");
	}
	{
		static const fp2_t var_a =  { {0x861CAE6B, 0xE578BCA9, 0xE9882E58, 0xD7A4C9D2, 0x4B24DC19, 0xD70CBB6F, 0xB93980F1, 0x15FF29C8},
	{0x2273777D, 0x0966F9A9, 0x437CF757, 0x5E1145CC, 0x142B5291, 0xB92E3F0D, 0xEEA71C55, 0x1D9FE411} } ;
		static const fp2_t var_expected =  { {0xC30E573F, 0x463C5E54, 0x74C41736, 0x1C62E4E9, 0xA5926E11, 0xC8A08477, 0x7C9CC079, 0x1D914725},
	{0x9139BBC8, 0x58337CD4, 0x21BE7BB5, 0xDF9922E6, 0x8A15A94C, 0xB9B14646, 0x17538E2B, 0x2161A44A} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 809 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 810 a1");
	}
	{
		static const fp2_t var_a =  { {0x80631C0D, 0x0AAF2AB3, 0xD4F55099, 0x96C7D0B1, 0xA6C90CF9, 0x6F7E2990, 0x71C8C12C, 0x10192C79},
	{0xD980915C, 0x4E1833EB, 0x81E8A366, 0xB92CEA26, 0xDBC1D2B6, 0xFC5801E0, 0x57EAA750, 0x0E226641} } ;
		static const fp2_t var_expected =  { {0xC0318E10, 0x58D79559, 0xEA7AA856, 0xFBF46858, 0x53648680, 0x14D93B88, 0xD8E46097, 0x1A9E487D},
	{0xECC048AE, 0x270C19F5, 0x40F451B3, 0x5C967513, 0x6DE0E95B, 0x7E2C00F0, 0xABF553A8, 0x07113320} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 811 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 812 a1");
	}
	{
		static const fp2_t var_a =  { {0x8C7F15C1, 0x2B29368C, 0xB59251C6, 0x74A14EC5, 0x6FEC5ED3, 0xF957FCA9, 0xF5B42BE2, 0x029BFADE},
	{0x9CB53EC8, 0x2557F591, 0xDCEAB783, 0xF61B42C8, 0x80B1D84D, 0xE6BB6E83, 0xA7CFDCD8, 0x08A9F97A} } ;
		static const fp2_t var_expected =  { {0x463F8AEA, 0xE9149B46, 0xDAC928EC, 0xEAE12762, 0xB7F62F6D, 0x59C62514, 0x9ADA15F2, 0x13DFAFB0},
	{0xCE5A9F64, 0x92ABFAC8, 0x6E755BC1, 0xFB0DA164, 0xC058EC26, 0x735DB741, 0x53E7EE6C, 0x0454FCBD} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 813 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 814 a1");
	}
	{
		static const fp2_t var_a =  { {0x2D2B088D, 0x640EB1C1, 0xE71BA6EA, 0xDD2DA95E, 0x151164CC, 0x202EAF31, 0x4D960C48, 0x0EA26A78},
	{0x0A3B4098, 0x2880374B, 0xCB1159DA, 0x8C4C0854, 0x943B2087, 0x4CBFD29C, 0x49DFCDF9, 0x18AFE6A2} } ;
		static const fp2_t var_expected =  { {0x96958450, 0x058758E0, 0x738DD37F, 0x9F2754AF, 0x8A88B26A, 0xED317E58, 0x46CB0624, 0x19E2E77D},
	{0x851DA04C, 0x14401BA5, 0x6588ACED, 0xC626042A, 0x4A1D9043, 0xA65FE94E, 0x24EFE6FC, 0x0C57F351} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 815 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 816 a1");
	}
	{
		static const fp2_t var_a =  { {0x22C3FAA3, 0xDA490BAD, 0x011644FF, 0xE60CBBE9, 0x49BA0F3A, 0x7567F52D, 0x42CB9E21, 0x17BE95E9},
	{0x07E5E816, 0x4AE0CB18, 0x087C44E5, 0xA1010CCB, 0xE627AD23, 0xA4FC8FC0, 0x23AE1933, 0x05A07391} } ;
		static const fp2_t var_expected =  { {0x9161FD5B, 0xC0A485D6, 0x808B2289, 0xA396DDF4, 0xA4DD07A1, 0x97CE2156, 0xC165CF11, 0x1E70FD35},
	{0x03F2F40B, 0xA570658C, 0x843E2272, 0xD0808665, 0x7313D691, 0xD27E47E0, 0x91D70C99, 0x02D039C8} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 817 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 818 a1");
	}
	{
		static const fp2_t var_a =  { {0x6D56B7FD, 0xE8DA4950, 0xDF5D1946, 0x97E90000, 0xFD782E3F, 0x7EFE5234, 0x1C0382F5, 0x0286AE8A},
	{0xB141DC81, 0x57FCF0D6, 0x8B680E9E, 0x6C87E8A3, 0x88D4B7F5, 0xD42F5198, 0xA06FFC38, 0x11A85AA3} } ;
		static const fp2_t var_expected =  { {0x36AB5C08, 0x47ED24A8, 0x6FAE8CAD, 0xFC850000, 0x7EBC1723, 0x9C994FDA, 0x2E01C17B, 0x13D50986},
	{0x58A0EE4A, 0xFF7E786B, 0xC5B40758, 0xE6D47451, 0x446A5BFE, 0x4731CF8C, 0xF037FE1D, 0x1B65DF92} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 819 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 820 a1");
	}
	{
		static const fp2_t var_a =  { {0x50B6615B, 0x6A21725E, 0x97B85C7A, 0xD76823EE, 0x62FC06C6, 0x6656F176, 0x66D5B853, 0x064099F8},
	{0x6BA9B138, 0x3BE6D688, 0x8FC6AA23, 0xCB9A99CC, 0xCC45441D, 0x88415A04, 0xA97E7960, 0x0F69E4A2} } ;
		static const fp2_t var_expected =  { {0x285B30B7, 0x0890B92F, 0x4BDC2E47, 0x9C4491F7, 0x317E0367, 0x90459F7B, 0x536ADC2A, 0x15B1FF3D},
	{0x35D4D89C, 0x9DF36B44, 0x47E35511, 0xE5CD4CE6, 0x6622A20E, 0x4420AD02, 0x54BF3CB0, 0x07B4F251} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 821 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 822 a1");
	}
	{
		static const fp2_t var_a =  { {0x4A8661ED, 0xE0336975, 0x8463932D, 0x45DDD8E8, 0xE9211E78, 0xA8037D09, 0xE84A2AF0, 0x03432F69},
	{0xD54E7B5B, 0x23891811, 0x8BC53E46, 0xDA13DF71, 0x41364ECF, 0xAFC84A0B, 0x66F67992, 0x108D1E9E} } ;
		static const fp2_t var_expected =  { {0xA5433100, 0xC399B4BA, 0x4231C9A0, 0x537F6C74, 0xF4908F40, 0x311BE544, 0x14251579, 0x143349F6},
	{0xEAA73DB7, 0xE5448C08, 0xC5E29F2C, 0x1D9A6FB8, 0xA09B276C, 0x34FE4BC5, 0x537B3CCA, 0x1AD84190} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 823 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 824 a1");
	}
	{
		static const fp2_t var_a =  { {0x1D4CCA42, 0xEB2847CE, 0x3EA46039, 0x75CD046E, 0x42051F2B, 0xD408DBF1, 0x2B70A6FC, 0x145D27FF},
	{0xD14E309E, 0x2CFF283B, 0x39652C9F, 0x366E76A9, 0xBA26AD9A, 0x05E3C043, 0xC13DF5E1, 0x1E465483} } ;
		static const fp2_t var_expected =  { {0x0EA66521, 0xF59423E7, 0x1F52301C, 0xBAE68237, 0xA1028F95, 0x6A046DF8, 0x95B8537E, 0x0A2E93FF},
	{0xE8A7184F, 0x967F941D, 0x9CB2964F, 0x1B373B54, 0xDD1356CD, 0x82F1E021, 0xE09EFAF0, 0x0F232A41} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 825 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 826 a1");
	}
	{
		static const fp2_t var_a =  { {0xC97F0911, 0x106D1EE9, 0x9E5818A5, 0x53AA498F, 0x5F10E729, 0x2BF09A11, 0xF7EA74E7, 0x0EF40633},
	{0x7FC00025, 0x51D9B43A, 0x92056CF9, 0x4167245C, 0x476E8DCC, 0x6FCD13EB, 0xE2951CBD, 0x14FF5462} } ;
		static const fp2_t var_expected =  { {0xE4BF8492, 0x5BB68F74, 0xCF2C0C5C, 0xDA65A4C7, 0xAF887398, 0x731273C8, 0x1BF53A74, 0x1A0BB55B},
	{0x3FE0001C, 0x7C6CDA1D, 0x4902B686, 0x5144122E, 0xA3B746EA, 0x9500B0B5, 0x914A8E5F, 0x1D115C72} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 827 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 828 a1");
	}
	{
		static const fp2_t var_a =  { {0x3BBCD218, 0x6EEAE733, 0x54280F5E, 0x2A2F5B1B, 0x6C801149, 0x672DF5E9, 0xD615704D, 0x12CCD6FD},
	{0xFA63BE81, 0x9240902A, 0xA75BCAD6, 0x8DD8F48F, 0xF8966FDD, 0x1DFFC4CF, 0x7AB9459A, 0x0864677C} } ;
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 829 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 830 a1");
	}
	{
		static const fp2_t var_a =  { {0x67DB5EB7, 0xA94DA0F6, 0xD77BA08C, 0x2C8DB22B, 0xCB9F1380, 0x8A15F1F3, 0xB3854681, 0x14AA83F7},
	{0xEA829E53, 0xA222F091, 0x0778DEE0, 0x35963C04, 0xB1BDA3FF, 0x6F66B90C, 0x55152221, 0x219DBC19} } ;
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0x67DB5EB7, 0xA94DA0F6, 0xD77BA08C, 0x2C8DB22B, 0xCB9F1380, 0x8A15F1F3, 0xB3854681, 0x14AA83F7},
	{0xEA829E53, 0xA222F091, 0x0778DEE0, 0x35963C04, 0xB1BDA3FF, 0x6F66B90C, 0x55152221, 0x219DBC19} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 831 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 832 a1");
	}
	{
		static const fp2_t var_a =  { {0x58DD2D48, 0xBBB82836, 0x7EB23504, 0x7EC8ED98, 0xB4B65154, 0x5BCF8BFC, 0x3799A0FC, 0x0A5C9ED3},
	{0x21891691, 0xB84E181F, 0x0620835A, 0x4C81A778, 0xAA1A973D, 0x400E1D26, 0x9388E573, 0x0E696366} } ;
		static const bigint_t var_b = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0xBCFDD1FA, 0x1BDE5137, 0x2574B839, 0x357228FB, 0x04F8344D, 0xDEE3ED6D, 0x40CE2CBF, 0x174FC509},
	{0xE8D8523A, 0x339B428D, 0x7A7D7F85, 0x2F2EAFE2, 0x901CD583, 0x67E0E2A5, 0x58456AE4, 0x1063B742} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 833 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 834 a1");
	}
	{
		static const fp2_t var_a =  { {0xB86D925C, 0x7B324AB0, 0xDF1C716A, 0x5A74D021, 0xE2299B16, 0xD6167BCB, 0x018A2E5C, 0x071A0DDB},
	{0x62C86CB3, 0x5F47CB5F, 0x383CD831, 0x8F654CF6, 0xB04F423E, 0x86309FC9, 0xD713BA55, 0x0B220A76} } ;
		static const bigint_t var_b = {0x9177DDCC, 0xA93527BB, 0x687B17D5, 0x71ACE39D, 0xD85DF9C9, 0x8E7ED0AB, 0x09CA265E, 0x15AF06C5};
		static const fp2_t var_expected =  { {0x4AF40227, 0x7B0E4F91, 0xED922C17, 0x56CEEA94, 0x3B121514, 0x0A54057C, 0xC97176E1, 0x0E5B7A5C},
	{0xCC640A4D, 0x245EF16F, 0x1AE20F7D, 0xFB38C1FB, 0x026F9B55, 0xFAED196B, 0x428DD4EF, 0x212EDCD5} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 835 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 836 a1");
	}
	{
		static const fp2_t var_a =  { {0x85581B35, 0x40E758D7, 0x22FE073C, 0x4620AAD6, 0x8C0043A4, 0x3B74632C, 0x7C5E3FA7, 0x24381EB8},
	{0x93185166, 0x8B3F0434, 0x77D5549A, 0x967668C4, 0x2E5614AB, 0x139C60DD, 0x91870992, 0x0AF86F9F} } ;
		static const bigint_t var_b = {0xEEB82FB5, 0x8BCD48CF, 0xA0F3F3FE, 0xEBC8837C, 0x747F6DE4, 0x58EE4332, 0x6ABF807D, 0x080CBA54};
		static const fp2_t var_expected =  { {0x0941D724, 0x6D3186E2, 0x123478A8, 0x53CCE494, 0xD6E1573A, 0xD1592EE5, 0xD3459E43, 0x1F63DA21},
	{0xB7585CD2, 0x8C95B833, 0xA63A1F80, 0x1C10179E, 0x4DD094A1, 0x41673962, 0xD6E4542E, 0x0D097AE1} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 837 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 838 a1");
	}
	{
		static const fp2_t var_a =  { {0x364C1EC6, 0x38473217, 0x60382325, 0x0258F7C7, 0x57ADF7F6, 0x5D6D2062, 0x0DC7CD87, 0x17CB1F06},
	{0x9A0DC0F7, 0x08A34949, 0xD1598FD1, 0x6916B0FE, 0x0B62C312, 0x2C16ADE9, 0xA25EB7DC, 0x05A98EC5} } ;
		static const bigint_t var_b = {0xCC963894, 0x6CD1684C, 0x39FFFF7C, 0x23B04150, 0x40086D52, 0x5C2088D0, 0xFF24BB67, 0x0EC164B6};
		static const fp2_t var_expected =  { {0x2F79DF47, 0xF583BCF9, 0x1D24B096, 0x06441FD2, 0x0DAA3E01, 0xABDE93CC, 0xCE81BD9D, 0x09E19CF8},
	{0x7C239EF9, 0x7FC20475, 0x586F65AD, 0x48ECD8B9, 0xFC72C64C, 0xD0483469, 0x2AE68C42, 0x205A88A6} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 839 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 840 a1");
	}
	{
		static const fp2_t var_a =  { {0xBEEA91AA, 0xA4EC2FAC, 0xFAC91C17, 0xE2AA84DB, 0x717BF38F, 0x1B8780D9, 0x27A8BEC0, 0x229FF8F2},
	{0xB9A747E8, 0x24E33CB8, 0x0953FBD7, 0x8A92B9DB, 0xDF2C84DC, 0xEE51C7AD, 0xD04C713C, 0x0892B91D} } ;
		static const bigint_t var_b = {0xFFF549CE, 0x9D7F2529, 0xF2AD75CC, 0x53D946F8, 0x7B144808, 0xBA0DB2C9, 0x5F554B5F, 0x66FB00D9};
		static const fp2_t var_expected =  { {0x004E87FA, 0x9CBD1A82, 0x93783FD9, 0xEDC7BBF7, 0x4A1ED56B, 0x77AB455E, 0xF4EED913, 0x11157856},
	{0xCDF547A9, 0xF9F9D435, 0xE336B531, 0x9B953B32, 0x101CAC62, 0x4FD66A32, 0xC81A9E7A, 0x17003F00} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 841 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 842 a1");
	}
	{
		static const fp2_t var_a =  { {0xA701D783, 0x5A0D32BD, 0x6187CCFC, 0x2CF7B393, 0x01FF0CFD, 0x1C194CA8, 0xA0A71188, 0x07547FB6},
	{0x674F0B35, 0x05C04581, 0x4ED51746, 0xD75D1B7A, 0x4F09C9FB, 0xB17A2AB8, 0x1745CC85, 0x1BF9D6FD} } ;
		static const bigint_t var_b = {0xC107EFE8, 0xDFA5AFD7, 0x4C440309, 0x0C19ECFA, 0x89CE8751, 0xC8EFF108, 0xA7DB6664, 0x60D8A130};
		static const fp2_t var_expected =  { {0xA9249931, 0x1DA976B2, 0x62C346E7, 0xC390BDA9, 0xFB26C42E, 0x75280662, 0xF53D1AC6, 0x23371324},
	{0xAAADF6D2, 0x1C77D088, 0x857AF705, 0x6054BED6, 0x83520B6A, 0x9B198F39, 0x098FA8A0, 0x124DB037} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 843 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 844 a1");
	}
	{
		static const fp2_t var_a =  { {0x6BB70C98, 0xCF9A5D2B, 0x7D3EED9C, 0x9A60F0AC, 0x6B031B45, 0x3994048A, 0xF2876848, 0x20D3F972},
	{0x6CD7E618, 0x21DD956D, 0x5455D446, 0x5A1E577A, 0x43D8E0CD, 0x6DB8DC50, 0xD8E7553F, 0x0C622118} } ;
		static const bigint_t var_b = {0x30F372CA, 0xEA00003D, 0x0E6970A5, 0xB314C535, 0x72808535, 0x8EA7F967, 0xF9C89827, 0xE4A036CD};
		static const fp2_t var_expected =  { {0x8BDCF37A, 0x0E079408, 0x12D03989, 0x0D9F1A2D, 0x25063209, 0x003EF18E, 0x1E015699, 0x12EE20DA},
	{0x870DAAA0, 0x6EF28AF5, 0x00A030DE, 0xD243E727, 0xB500B3D3, 0x2B3338ED, 0x99DB9994, 0x10310845} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 845 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 846 a1");
	}
	{
		static const fp2_t var_a =  { {0x180FFC97, 0x34F17BE6, 0x1FB5A364, 0x99928AF2, 0x658C97E5, 0xB234116C, 0x5890E670, 0x073C598A},
	{0x678697AB, 0xA3108332, 0x4D52B531, 0x13806A4E, 0x9720A3D6, 0x7B3D7136, 0x881C28AA, 0x24E29A80} } ;
		static const bigint_t var_b = {0xCB8E4C28, 0xE9EB9BD8, 0xC3E2BD5F, 0xFE85B64D, 0x5FB5B55D, 0x4A759D2E, 0xF6994854, 0xEBD44B41};
		static const fp2_t var_expected =  { {0xC39FFE82, 0x4A883E8B, 0xBC200A9D, 0xBDD569E5, 0x3E25A504, 0x0DEFE99E, 0x77D20DAB, 0x041022EF},
	{0xCA0DA974, 0xFE052C13, 0x8DB84DF5, 0xBC81D158, 0x61A62535, 0x28E7A502, 0xBB11DFC1, 0x0BE66A7A} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 847 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 848 a1");
	}
	{
		static const fp2_t var_a =  { {0x6B3F9450, 0xBE60468F, 0x2ADEADC5, 0xBC0C9DC8, 0x1B9FECE2, 0x159B093F, 0xD80F9D30, 0x1413ADCB},
	{0xB0F564E8, 0x18ABB294, 0x43A46F4E, 0x47654026, 0x99F4504D, 0x520781A9, 0x132817C1, 0x21464DD4} } ;
		static const bigint_t var_b = {0xFA29E5E1, 0xFA5F779E, 0x38E5C517, 0x794E7536, 0x226BBDEF, 0xEBFF5C70, 0x4AACD815, 0x02074816};
		static const fp2_t var_expected =  { {0x1077DC1E, 0xE2766A40, 0xB7497C6D, 0x2D2AE5D9, 0xDD5E28D1, 0xB9C7DEEB, 0x8B4FFC38, 0x1C369E50},
	{0x22BE974D, 0xDAAAA14E, 0xC464F1B1, 0x6C775203, 0xAEF71DD9, 0xA91729B7, 0xDE731E2F, 0x1195D23B} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 849 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 850 a1");
	}
	{
		static const fp2_t var_a =  { {0x032C07C1, 0xE1FB3FD9, 0x65476FC3, 0x171D64E4, 0x0EF1CC16, 0x79A96328, 0x703A203B, 0x0B1092C8},
	{0xB60A278E, 0x43224CA2, 0x0142255F, 0xE2569AA9, 0x5C0E8044, 0x0F53A781, 0x7BD0F92E, 0x06B21B65} } ;
		static const bigint_t var_b = {0x866670F7, 0xB043C257, 0x01EFA2C7, 0x065B0CFA, 0xAD53A71B, 0x98ACC28B, 0x1F44424E, 0xCC87E2C8};
		static const fp2_t var_expected =  { {0xD153E5DE, 0x174AADA3, 0x6275CA68, 0x7435CC96, 0xF0526199, 0x690ED9B4, 0x38F47407, 0x10093802},
	{0xAA9F9629, 0x1C221864, 0x0B76CD4B, 0x82466EF7, 0x6FA56166, 0xB48CAF79, 0x42798525, 0x01F442B0} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 851 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 852 a1");
	}
	{
		static const fp2_t var_a =  { {0xDFEAB432, 0x3234F80F, 0xB0C6949A, 0xDE169629, 0x4002ED73, 0xCB28A58F, 0x3E75E5E3, 0x17C8429F},
	{0x37931A70, 0xC84F4DCE, 0x76E9F8BD, 0x20682ABE, 0x191860A6, 0x38FAE34B, 0x9BD13A59, 0x0F57A21B} } ;
		static const bigint_t var_b = {0x1B22CBD6, 0x920AAF2A, 0xF43663CD, 0x56574772, 0x9826CF04, 0x2846C7A6, 0xA6215561, 0x7FE1D1BD};
		static const fp2_t var_expected =  { {0x0E724973, 0x6236340B, 0x3A291BCC, 0x731E8942, 0xABED2477, 0x7967569E, 0x659B3A8E, 0x1FC34A2B},
	{0x5BADAEBE, 0xBE46A6A6, 0x380377FC, 0xFC17A23F, 0x6CF71A63, 0xDCE60E8D, 0xC06D3CA7, 0x01380175} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 853 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 854 a1");
	}
	{
		static const fp2_t var_a =  { {0x2A81ADFA, 0x0FB56646, 0x935CE63C, 0xC88FCFF4, 0xCE9D66F6, 0x59FC2553, 0xE7A39655, 0x151423A0},
	{0x66860B98, 0x89BCD1AD, 0x2452DC5E, 0x9E7A574B, 0xC085290A, 0x37D1B1B8, 0x02EE311B, 0x0F11B04B} } ;
		static const bigint_t var_b = {0xCB6F97DA, 0x9CA4802C, 0xAAA9CEFD, 0x733120E7, 0x9E02592A, 0xA9F4A792, 0x93A600BC, 0x6423F04B};
		static const fp2_t var_expected =  { {0x19BF20C8, 0xFC62CEA1, 0x786EA7BA, 0xE152795E, 0x644B3C58, 0x4629AC4F, 0xDCF65E67, 0x197B035D},
	{0xB6111615, 0xFC00E0B1, 0x5C2A1BE8, 0x1C8E6B31, 0xD7054A7D, 0xBE67553D, 0x23C36A38, 0x075944F0} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 855 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 856 a1");
	}
	{
		static const fp2_t var_a =  { {0x363FC356, 0x1177DCFF, 0xD7D92E37, 0xE413D454, 0xB1F2213D, 0x64A813BA, 0x19A0695D, 0x0451C822},
	{0xBA128C94, 0xE3E69A5C, 0xD743389B, 0x845DC7E9, 0xA1A11B9F, 0xF014AB30, 0x8577E2CA, 0x04DBC4E8} } ;
		static const bigint_t var_b = {0x8CA10B12, 0xBBBD6D9C, 0x03774598, 0x386D8D7E, 0x1FDF4A8A, 0xDC84DC08, 0x9F8B4C5B, 0x59FD52DE};
		static const fp2_t var_expected =  { {0xB0180424, 0x1084FC11, 0xFB4D62E1, 0xB5C20FA7, 0x94FFF581, 0x1B79A352, 0xDE166062, 0x0EFBA50B},
	{0x94EF81B2, 0x4E86B70C, 0x946C4FD6, 0x8863CA0B, 0x2E527D74, 0x2D6AC2AA, 0x070AECF4, 0x0AECBC32} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 857 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 858 a1");
	}
	{
		static const fp2_t var_a =  { {0x0E4558C4, 0x9E17834F, 0x2447FD2D, 0x5F55A6B5, 0x703F7320, 0x7C1A2036, 0x2FAFE9B4, 0x02453609},
	{0x0581F6B1, 0xC9BD44A4, 0x6A9286B4, 0x55E5BD35, 0xBCF040CB, 0x266A4BFC, 0x81D7AB5F, 0x0CA7D8A6} } ;
		static const bigint_t var_b = {0xB6612ABA, 0x534D2799, 0xA02FFD2B, 0xD4474F1B, 0x9D0D9E68, 0xB5FF1BB2, 0x0626E78A, 0x51AB154E};
		static const fp2_t var_expected =  { {0x3F83DF10, 0xA0396446, 0x78E7E9D1, 0x25575217, 0x5B961D7A, 0x6173CFD2, 0x3E88EAEA, 0x03C23480},
	{0x078A9FF6, 0x147B4F1F, 0x2B58F1D4, 0x43889194, 0xB5922342, 0xA06E4A7A, 0x08082551, 0x100F7F19} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 859 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 860 a1");
	}
	{
		static const fp2_t var_a =  { {0x037B2E44, 0x903AF2A3, 0x4DE4698F, 0x144D1739, 0x9C0B0FC9, 0x185636E5, 0x9F5575E0, 0x04DA4973},
	{0x5127D5B9, 0xF453AB71, 0xAA687E87, 0x72625450, 0x9B8AFC72, 0x4386B7E8, 0x701AFACF, 0x0BE7FC67} } ;
		static const bigint_t var_b = {0x88DC593B, 0xBB7510CE, 0x697222CF, 0x4DAB99B1, 0x40CBDEE9, 0xDD919DDF, 0x093D6FDF, 0xD0B0D2E8};
		static const fp2_t var_expected =  { {0x43A0F4E6, 0x55BEF13A, 0x7CE93833, 0x907CD19E, 0x38B5ACEE, 0x01B1E7FE, 0xD04F8E51, 0x13D97ED7},
	{0x6DB06D3E, 0xB9BF2C44, 0x24969786, 0x5FE0584E, 0xEEB0075B, 0xEE927357, 0xD86E8E60, 0x16C9E500} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 861 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 862 a1");
	}
	{
		static const fp2_t var_a =  { {0xBBB13F74, 0x08085327, 0xDDF0FF5F, 0x729F0E44, 0x7188D9E2, 0x28DD9A0B, 0x5B50D802, 0x18675E8A},
	{0x75B8CB1F, 0xC1DB991A, 0xE7D33518, 0x33B653EC, 0xEF5110B7, 0x48A854C4, 0x35BAAE76, 0x249BE58A} } ;
		static const bigint_t var_b = {0xA2F98F00, 0xBDB375B8, 0x072AA5B0, 0xFAF1B839, 0x54E22F8F, 0x32C3034E, 0x6C6FDF14, 0x72640B26};
		static const fp2_t var_expected =  { {0x767BD94D, 0x82228E15, 0x8CCE1ED8, 0x4866655F, 0x5C0092FD, 0x80971E83, 0x12C1F801, 0x0EE034DE},
	{0x495C09C8, 0xABD54DBD, 0x630DFFA3, 0xC4234BC3, 0x8E747AA1, 0xC68CC193, 0x1B0F33A2, 0x001CC4F7} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 863 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 864 a1");
	}
	{
		static const fp2_t var_a =  { {0x69FFF366, 0x193DAB54, 0x288B2DBC, 0x0E9EB1CC, 0x7E52B33D, 0x9F1E5D24, 0x24FA53FE, 0x029DCE25},
	{0xB2FA75DD, 0x5E58E008, 0x861CF0B0, 0x1E43BF84, 0xAA2FC688, 0x7487C617, 0xD724B044, 0x198964F9} } ;
		static const fp2_t var_expected =  { {0x52F45AA8, 0x07E81F55, 0xC13E643B, 0x4F99DD2C, 0x53FABD54, 0xA019F45C, 0x5539786D, 0x0B80E652},
	{0x63DCFFB9, 0x73133FEC, 0x869288F5, 0xC2132E08, 0x76698D8C, 0xDBFC7187, 0x280601E8, 0x03DF258D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1045 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1046 a1");
	}
	{
		static const fp2_t var_a =  { {0xF759F66E, 0xEA4C19F4, 0x9B5018C6, 0x9F22180A, 0x81FAD0F4, 0xFEDCBD24, 0xAD2BF34B, 0x08668C8B},
	{0x50897463, 0xE8B43A4B, 0xD05BEF91, 0xA7E561C0, 0x907AB4DA, 0xCBB1B315, 0xCF999D00, 0x230F99E2} } ;
		static const fp2_t var_expected =  { {0xBD746F45, 0xF03A77AF, 0x75E97B7C, 0x9B71310D, 0x9E3C38A8, 0x7FDA8079, 0xDC76DA89, 0x0F1BAFFD},
	{0xF4D6B017, 0xFE57607E, 0x080D000A, 0x2A6A152D, 0x27BEDC7E, 0x30C17643, 0xEBBC8D81, 0x10C7DB89} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1047 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1048 a1");
	}
	{
		static const fp2_t var_a =  { {0x4A9FFE33, 0x248D9E95, 0x25783415, 0x6911574D, 0xFD05D476, 0x293698D7, 0x7B779978, 0x21372ED3},
	{0xB12D70D3, 0xC1A5F19B, 0x0BE68B16, 0xF13734CC, 0x1E9C2FB6, 0x918D24AE, 0x7E7529C0, 0x07F8FCA1} } ;
		static const fp2_t var_expected =  { {0x28C4B169, 0xAD0737BB, 0xD4E7C9BA, 0x8821466D, 0x2F7D7129, 0x393B7998, 0x8FE280A4, 0x081E7F6B},
	{0x651D024E, 0x9F72026D, 0x81848E72, 0xC88A52C2, 0xB8BCF48B, 0xEA9B0A09, 0xC848841F, 0x0106A7F1} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1049 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1050 a1");
	}
	{
		static const fp2_t var_a =  { {0xA1C9C5AF, 0xD18D68F2, 0xE342EF60, 0x9FBB5061, 0xBB6AC521, 0x1836E3B6, 0x040D9EC6, 0x18B5EB47},
	{0x0B25B59B, 0xC6460D55, 0xBC41D2B1, 0x4EBE2492, 0x8B441740, 0xABEE68FF, 0xD52CAE06, 0x09538B59} } ;
		static const fp2_t var_expected =  { {0x8C0F24C5, 0xD555C292, 0x582F002F, 0xE827EBA5, 0x24BADE46, 0x49299D12, 0x743F0AC2, 0x05D9A982},
	{0xC4D24741, 0x64B81F48, 0x3FE38A53, 0x8CFFA481, 0xA8213198, 0xE7A68EE5, 0x382831C6, 0x21DF94B4} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1051 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1052 a1");
	}
	{
		static const fp2_t var_a =  { {0x477BAE72, 0x54D3C666, 0xE97477DF, 0x02D2B04D, 0xBCCA3645, 0x4B6DA5E7, 0x0198468D, 0x0464E18D},
	{0x34815BF0, 0x66A1641C, 0xCA78E3A0, 0x722FC81A, 0x06EE31B3, 0xA1DA5F84, 0x6AFA9D60, 0x0D617526} } ;
		static const fp2_t var_expected =  { {0xFEBC152A, 0x5EA78BB6, 0xA4E4996B, 0x7A94EB84, 0x0B645A1C, 0xDBE11E69, 0x4F44B03D, 0x0BBBB0DC},
	{0xA1B19632, 0x0B0732F7, 0xE458D394, 0x36A74F8B, 0x57E6990A, 0x1A4C8DC1, 0xCF56B1B8, 0x18525FB5} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1053 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1054 a1");
	}
	{
		static const fp2_t var_a =  { {0xF5D0BC87, 0x30635EA4, 0x420D3997, 0xEEEF57EC, 0xE4BE2EF7, 0x6530E5E9, 0x0FEB423B, 0x13C1C3EE},
	{0x01F1D8EA, 0x6BA16B8C, 0xE438D8D8, 0x0EE6CFAB, 0x20F6CB5A, 0x394EFAAF, 0xAA8F6EDA, 0x1293A733} } ;
		static const fp2_t var_expected =  { {0x4F52ED88, 0x40D471E5, 0xDD2ADBD6, 0xC25B755D, 0x3968CF73, 0x934758CD, 0x37605A9B, 0x2285EA32},
	{0x901F10C9, 0x427901C6, 0xFA55F41B, 0x9E732146, 0x85B5EAF9, 0x396ECC04, 0xE63326BF, 0x238311D3} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1055 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1056 a1");
	}
	{
		static const fp2_t var_a =  { {0xDB1C8C5D, 0xD62B7BE9, 0xEA095710, 0x342D825E, 0xD9C4DAE2, 0x5AF0D6A8, 0xDCD64F8F, 0x04A99B59},
	{0x1576A901, 0x20D977D1, 0x24EEF82D, 0xF11C8210, 0xCF90A2EE, 0xD4A3B9A8, 0xFD6322AB, 0x169F8EDF} } ;
		static const fp2_t var_expected =  { {0xFEE0C279, 0x846530CE, 0x4C9997A3, 0xB33A85DE, 0x0DEC36D4, 0x90ACD98A, 0x709DF592, 0x19F91BA6},
	{0xE539E6B7, 0x3FF29DC1, 0x0724B094, 0x2FE614E7, 0xAFD6F65F, 0xE1FD864C, 0x995EF076, 0x012A6F2D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1057 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1058 a1");
	}
	{
		static const fp2_t var_a =  { {0x42A53827, 0xB940AAE5, 0xA6DC93D6, 0x646D8C51, 0x81EC794F, 0x1F6D4697, 0x088FBA36, 0x1249113B},
	{0xD0C118E2, 0xED8FC781, 0xCB8CC64E, 0x154A5467, 0x22F92456, 0x0E3079A3, 0xB0749F59, 0x1C040DE5} } ;
		static const fp2_t var_expected =  { {0xF42C8C4B, 0xB4E0127E, 0x1C01905D, 0xE3D27D9C, 0x3D7E8F84, 0xC624F4F6, 0x96363F0D, 0x23452DB1},
	{0xDD4B275D, 0x53D62062, 0x8C496F23, 0xF2A51D1C, 0xEC50511A, 0x26D63554, 0xFD88761B, 0x1855283D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1059 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1060 a1");
	}
	{
		static const fp2_t var_a =  { {0xD45A78C4, 0x8596E715, 0xCA69F1B0, 0x0F48BEB7, 0x7DD77C3C, 0xA94F95F0, 0x875BB155, 0x079A6107},
	{0x83603ADE, 0x333CEF31, 0x8E4B5809, 0x7354A8E1, 0x4CE65B16, 0x5B150B02, 0x1B4D440E, 0x19933C55} } ;
		static const fp2_t var_expected =  { {0x3E717636, 0x94B3C44A, 0x4778F8F1, 0x8A988B55, 0xE03E53A7, 0x00A6C0A5, 0x01098127, 0x0E7E7675},
	{0xCFF30503, 0x6D886E23, 0x03B191B6, 0x6739143F, 0x5AC1BAD3, 0x73E3ABD1, 0xEF1C843F, 0x214156D7} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1061 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1062 a1");
	}
	{
		static const fp2_t var_a =  { {0xF19D0642, 0x36A59733, 0xBF249DB6, 0x43A85FAC, 0x6DF734CE, 0x88E22B93, 0x22501FD0, 0x026A99A5},
	{0xA08E289E, 0x1E6744EB, 0xE43A2C96, 0x360EF742, 0x60580608, 0x43B44784, 0x5F7EBC39, 0x013C7E07} } ;
		static const fp2_t var_expected =  { {0x63155D01, 0xF5B02DF6, 0x3BFD51B4, 0x6E1832ED, 0x84A1FAB7, 0x7AB9ADAC, 0x0E0FCF55, 0x020D0B57},
	{0xF960CF51, 0x4DC9E8D2, 0x9EBF56A5, 0x27A51E7F, 0xE683750D, 0x66C428C5, 0x9A6016BC, 0x055AC5AC} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1063 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1064 a1");
	}
	{
		static const fp2_t var_a =  { {0x7EF9421C, 0xC88402BB, 0xFB1F26DE, 0x21E31A99, 0x95DDC212, 0xCAB4D9CD, 0x8BBA1656, 0x0817BA49},
	{0x6EDBD0BE, 0xA41EAC28, 0x7DCCDAB9, 0x8D95AA78, 0x3CE9155F, 0x86EC4DF1, 0x72E6A00C, 0x2066C5BC} } ;
		static const fp2_t var_expected =  { {0xC54AE1D9, 0x4844CFA7, 0x212E8972, 0xC5DB4A37, 0x18C6FB74, 0xC27DF1B0, 0xA6C9D4C3, 0x178EBFEF},
	{0x5D8B04B5, 0x22DFA43D, 0x4AE80511, 0x2E8E218A, 0xB35C7AA4, 0x17CBE25C, 0xBFB3A866, 0x1830384B} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1065 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1066 a1");
	}
	{
		static const fp2_t var_a =  { {0x1A370EDD, 0x5908939F, 0x5D31167D, 0xC4D9D636, 0xC5D2073B, 0x2C7D109C, 0xBA1392C2, 0x0284E6F1},
	{0xCF4B22BC, 0xE3876F81, 0x8DC83ECD, 0xEFB00761, 0x16E6BF80, 0xBF4D9CCA, 0xB4D1F4F7, 0x1A49E217} } ;
		static const fp2_t var_expected =  { {0x2A7EB191, 0x6B6F061C, 0xC79A964B, 0x7E41420D, 0x242C6F08, 0x6E3CF38B, 0xA3B45074, 0x06AF1D7C},
	{0x39E7ED89, 0xBF5EF582, 0x7FD2B6A6, 0xB9F41F83, 0x94A75530, 0x3EB43615, 0xBA203BE8, 0x0855D922} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1067 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1068 a1");
	}
	{
		static const fp2_t var_a =  { {0x45A993DF, 0x970EED30, 0x70731E03, 0xA71AAF0C, 0x3A9A3D95, 0xF687EC24, 0x8BF29F8E, 0x1048F5D3},
	{0x6A05D0CF, 0xF12F7052, 0x44B9724B, 0xB1824BCA, 0xFBE6B38E, 0xC8AAF0C0, 0x5557C0CC, 0x0F3DBDAB} } ;
		static const fp2_t var_expected =  { {0x083D94D6, 0x08436D33, 0x6B33AAEB, 0xA6980513, 0x07D9548E, 0x7FE02C80, 0x4D15104B, 0x03C76564},
	{0x53F58C6E, 0x370B1A14, 0x938897CD, 0xB0230C23, 0x2E6A8944, 0xE0416F40, 0x33A5FE8D, 0x10EC3048} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1069 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1070 a1");
	}
	{
		static const fp2_t var_a =  { {0x4734225E, 0xF5629B52, 0x5C0E28BC, 0x99B0A3F9, 0x1D7D2613, 0x20E2D0B1, 0x80F19D81, 0x20422E90},
	{0x8B19B866, 0x515AADA0, 0xC52E4927, 0x2111A1C3, 0xF73DB534, 0xAD68A9EF, 0x848EC155, 0x24034F76} } ;
		static const fp2_t var_expected =  { {0xA82BEDCE, 0x57B238BA, 0x18BA82FD, 0xE22C7758, 0x0E99F686, 0x2DFB44F3, 0xA306554E, 0x06319C2D},
	{0xEAFC2DB7, 0x52C307BE, 0x8BA2E9C0, 0xA9F0384E, 0x71336A35, 0x8F057A73, 0x0B823398, 0x0F599981} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1071 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1072 a1");
	}
	{
		static const fp2_t var_a =  { {0x8C5E8244, 0x1C79B7E0, 0xF604FB55, 0xF0A0E78C, 0xF0BA5532, 0x0C2BEF43, 0x6976A376, 0x09066B6F},
	{0x8780D290, 0x32AD4C7A, 0xE10B3B3A, 0x160AE52C, 0x270F6F74, 0x03B7ACC1, 0x9E3D3B16, 0x0B5CFB19} } ;
		static const fp2_t var_expected =  { {0x98B17904, 0xEB1B7F66, 0xCDA3D024, 0x687A1857, 0x79A1FBE9, 0x1C9EE37F, 0xBE8C7BDA, 0x21CF874F},
	{0xCE021BD8, 0x55EB3192, 0x99D7F2C7, 0xD8EF57B6, 0xE6224011, 0x22101070, 0x86EEEE21, 0x0428E944} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1073 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1074 a1");
	}
	{
		static const fp2_t var_a =  { {0x59C8E030, 0x0D2BFF6A, 0x4F175725, 0x5A953C02, 0xB60DBD29, 0xBE37BE52, 0x54A8E1A7, 0x17DA0C69},
	{0x907705AE, 0x3827B42A, 0xA0EEF9B8, 0x3AB73D9E, 0x8ABC28F9, 0x3FF84260, 0x39758F11, 0x0B7AAFA8} } ;
		static const fp2_t var_expected =  { {0x6A9C38B7, 0xA152C7DA, 0xA8EE3256, 0xCFAF4957, 0x7FF732E6, 0x7BA34086, 0xD4715BC7, 0x1EF39D98},
	{0x6D9CB781, 0x87446017, 0x33C67CE2, 0xA8A08B2B, 0x01975A9D, 0x9084B716, 0xC474F06F, 0x0C2CF957} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1075 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1076 a1");
	}
	{
		static const fp2_t var_a =  { {0xE2538549, 0x582AE0E5, 0xB411E225, 0x2C3A1006, 0x6C295004, 0x109557A9, 0xC692FC4A, 0x064428F0},
	{0xF74310DB, 0xC6609640, 0xB581C7A9, 0x65CF141A, 0xA531B956, 0x4286FE8A, 0xDAEC3692, 0x11F9268B} } ;
		static const bigint_t var_b = {0x8BA58917, 0x185E51C0, 0x695AB50D, 0x067A0F42, 0xC85BC817, 0x43FE9FB0, 0xF728C1F5, 0x634BFBD2};
		static const fp2_t var_expected =  { {0x904CFE69, 0x0A16A839, 0x2B3A27B3, 0x6C33F9E0, 0x88207704, 0x9A8296BA, 0xC48D76DF, 0x175EE797},
	{0xE9C54108, 0xB7324A1B, 0xBAD70DA3, 0x541C3106, 0x83023B60, 0x830B44E7, 0xBA3D5FAD, 0x23542E4B} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 865 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 866 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 867 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 868 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 869 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 870 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 871 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 872 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 873 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 874 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 875 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 876 a1");
	}
	{
		static const fp2_t var_a =  { {0x5C8A037A, 0xC683A0AE, 0x90ECD847, 0xE122EC39, 0x263A9AF0, 0xACE24A4D, 0xBDE5826B, 0x21805539},
	{0x1294EA57, 0xAFE3DD5C, 0x55C9EE95, 0x68515A21, 0x7FAD4E2D, 0xD9BADED0, 0x95CE403B, 0x135F1CC6} } ;
		static const fp2_t var_expected =  { {0xA375FC99, 0xE07C5F51, 0x6F1327CB, 0x7FFE13C6, 0xD9C56517, 0x0D520332, 0x821A7D96, 0x03A30F48},
	{0xED6B15BC, 0xF71C22A3, 0xAA36117D, 0xF8CFA5DE, 0x8052B1DA, 0xE0796EAF, 0xAA31BFC5, 0x11C447BB} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 877 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 878 a1");
	}
	{
		static const fp2_t var_a =  { {0x2B2BC2C9, 0x16756B73, 0x417E3676, 0xAA420AB3, 0xAF404128, 0x7A2E2B22, 0x77270DBA, 0x07703A6C},
	{0xC8BD9F81, 0x00932A93, 0xE1147B12, 0xE2FF139E, 0xF7319252, 0x392EB093, 0x1EBB1733, 0x0D87444D} } ;
		static const fp2_t var_expected =  { {0xD4D43D4A, 0x908A948C, 0xBE81C99D, 0xB6DEF54C, 0x50BFBEDF, 0x4006225D, 0xC8D8F247, 0x1DB32A15},
	{0x37426092, 0xA66CD56C, 0x1EEB8501, 0x7E21EC61, 0x08CE6DB5, 0x81059CEC, 0x2144E8CE, 0x179C2035} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 879 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 880 a1");
	}
	{
		static const fp2_t var_a =  { {0x31501667, 0x97829704, 0x460F1D46, 0xC854250D, 0x7AFB1656, 0x2B25045F, 0x890A89EB, 0x1C73B5F6},
	{0x4F9D2759, 0x58C1E2BC, 0x8674AF49, 0x2B5AE8A0, 0xC16B4924, 0xC2015775, 0x7C92DFBF, 0x17D4B271} } ;
		static const fp2_t var_expected =  { {0xCEAFE9AC, 0x0F7D68FB, 0xB9F0E2CD, 0x98CCDAF2, 0x8504E9B1, 0x8F0F4920, 0xB6F57616, 0x08AFAE8B},
	{0xB062D8BA, 0x4E3E1D43, 0x798B50CA, 0x35C6175F, 0x3E94B6E4, 0xF832F60A, 0xC36D2041, 0x0D4EB210} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 881 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 882 a1");
	}
	{
		static const fp2_t var_a =  { {0x31C7B908, 0x622CF22C, 0x39ED7936, 0x00BCF3F0, 0x384EAFD2, 0x08A960E4, 0xFC2301F0, 0x06A05F5A},
	{0x8897882C, 0x51EE7321, 0xFCEF71CE, 0xC9B3E2F7, 0xAEA38489, 0xA7E0016C, 0xD7417205, 0x1BF14597} } ;
		static const fp2_t var_expected =  { {0xCE38470B, 0x44D30DD3, 0xC61286DD, 0x60640C0F, 0xC7B15036, 0xB18AEC9B, 0x43DCFE11, 0x1E830527},
	{0x776877E7, 0x55118CDE, 0x03108E45, 0x976D1D08, 0x515C7B7E, 0x12544C13, 0x68BE8DFC, 0x09321EEA} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 883 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 884 a1");
	}
	{
		static const fp2_t var_a =  { {0x2A50AD6D, 0x84456DF6, 0xF1FD7C86, 0x0A5B7C08, 0xD96A95BD, 0x9C39119C, 0x1A9D65B4, 0x0D646BD0},
	{0x920B1FC7, 0xD814EF83, 0x3DEF0D5F, 0x8A5CEA0A, 0xD0F8ABB9, 0x3EDA6AA4, 0x589395E5, 0x1028A5E8} } ;
		static const fp2_t var_expected =  { {0xD5AF52A6, 0x22BA9209, 0x0E02838D, 0x56C583F7, 0x26956A4B, 0x1DFB3BE3, 0x25629A4D, 0x17BEF8B2},
	{0x6DF4E04C, 0xCEEB107C, 0xC210F2B3, 0xD6C415F5, 0x2F07544E, 0x7B59E2DB, 0xE76C6A1C, 0x14FABE99} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 885 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 886 a1");
	}
	{
		static const fp2_t var_a =  { {0x5EADD40A, 0x4844DA74, 0x894F6F9F, 0x6AC571CA, 0x8FE1F2AA, 0x3ADD8F3F, 0xEAC5197E, 0x0CD9DB76},
	{0xD0625547, 0x4AFADD2B, 0x82CA4C7D, 0x5B8D300D, 0x767021E9, 0xDA8102C3, 0xEABDAA53, 0x18F2E9DB} } ;
		static const fp2_t var_expected =  { {0xA1522C09, 0x5EBB258B, 0x76B09074, 0xF65B8E35, 0x701E0D5D, 0x7F56BE40, 0x553AE683, 0x1849890B},
	{0x2F9DAACC, 0x5C0522D4, 0x7D35B396, 0x0593CFF2, 0x898FDE1F, 0xDFB34ABC, 0x554255AD, 0x0C307AA6} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 887 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 888 a1");
	}
	{
		static const fp2_t var_a =  { {0x4EB3FBC0, 0x679419F6, 0x59A84D2C, 0xCD65D808, 0xCBB06D22, 0x31CD14D6, 0x36A00522, 0x11AF85FF},
	{0xE3203147, 0x09810C0E, 0x445AD1E6, 0xABDC5C88, 0x330687EA, 0x81FF1BE0, 0xF3F4614C, 0x19BDA2C1} } ;
		static const fp2_t var_expected =  { {0xB14C0453, 0x3F6BE609, 0xA657B2E7, 0x93BB27F7, 0x344F92E5, 0x886738A9, 0x095FFADF, 0x1373DE83},
	{0x1CDFCECC, 0x9D7EF3F1, 0xBBA52E2D, 0xB544A377, 0xCCF9781D, 0x3835319F, 0x4C0B9EB5, 0x0B65C1C0} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 889 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 890 a1");
	}
	{
		static const fp2_t var_a =  { {0xBB58443D, 0xFBE0BDDC, 0xFB1627A4, 0xB0B80AC0, 0x3D551BC5, 0x88FA9D61, 0xC8742BD1, 0x14FFE966},
	{0xABF3D6F4, 0xC5F645FA, 0x3C87BD09, 0xBE9B985E, 0xD7BBA844, 0x05C5E0ED, 0x1FF671EC, 0x20D5F5C2} } ;
		static const fp2_t var_expected =  { {0x44A7BBD6, 0xAB1F4223, 0x04E9D86E, 0xB068F53F, 0xC2AAE442, 0x3139B01E, 0x778BD430, 0x10237B1B},
	{0x540C291F, 0xE109BA05, 0xC3784309, 0xA28567A1, 0x284457C3, 0xB46E6C92, 0x20098E15, 0x044D6EC0} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 891 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 892 a1");
	}
	{
		static const fp2_t var_a =  { {0xA6C6E8F6, 0x7F6B23AA, 0x47823F69, 0x6B2906E3, 0xD7D99DF2, 0xF46132E2, 0x675CC183, 0x0826EA17},
	{0x49C3E9C1, 0x776106F3, 0x62DA8C75, 0xF3B26EA0, 0x73A90A22, 0x4B369C3F, 0x949E5364, 0x09014C37} } ;
		static const fp2_t var_expected =  { {0x5939171D, 0x2794DC55, 0xB87DC0AA, 0xF5F7F91C, 0x28266215, 0xC5D31A9D, 0xD8A33E7D, 0x1CFC7A6A},
	{0xB63C1652, 0x2F9EF90C, 0x9D25739E, 0x6D6E915F, 0x8C56F5E5, 0x6EFDB140, 0xAB61AC9D, 0x1C22184A} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 893 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 894 a1");
	}
	{
		static const fp2_t var_a =  { {0x50687B25, 0xAD56FBFC, 0x5639F5B2, 0x95011822, 0xC9E762CF, 0x6C2A173E, 0x1DD8CEE9, 0x17CA3D67},
	{0x1EC2C4A4, 0x70D51F14, 0xF00C474E, 0xA50C77D3, 0x580D1B2D, 0x174ABF71, 0x3E7401B9, 0x0FE563FF} } ;
		static const fp2_t var_expected =  { {0xAF9784EE, 0xF9A90403, 0xA9C60A60, 0xCC1FE7DD, 0x36189D38, 0x4E0A3641, 0x22273118, 0x0D59271B},
	{0xE13D3B6F, 0x362AE0EB, 0x0FF3B8C5, 0xBC14882C, 0xA7F2E4DA, 0xA2E98E0E, 0x018BFE48, 0x153E0083} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 895 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 896 a1");
	}
	{
		static const fp2_t var_a =  { {0x3AFB6C2F, 0x83FA4A89, 0x81837088, 0xBC33D5E8, 0x85D60CC3, 0xE5B06527, 0xF45C4E52, 0x06DF5C57},
	{0xCC7CAC94, 0x34C153AD, 0x5F98E750, 0x9091E186, 0x185C083C, 0x9FC43FD4, 0x033DBBBC, 0x2318B3BD} } ;
		static const fp2_t var_expected =  { {0xC50493E4, 0x2305B576, 0x7E7C8F8B, 0xA4ED2A17, 0x7A29F344, 0xD483E858, 0x4BA3B1AE, 0x1E44082A},
	{0x3383537F, 0x723EAC52, 0xA06718C3, 0xD08F1E79, 0xE7A3F7CB, 0x1A700DAB, 0x3CC24445, 0x020AB0C5} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 897 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 898 a1");
	}
	{
		static const fp2_t var_a =  { {0x249F100B, 0xB530DF4E, 0x623007F2, 0x2BEF6610, 0xBCBBF0C9, 0x8F61FC82, 0xF3DFD2A1, 0x13B38201},
	{0x34EAD4C0, 0x933FE075, 0x67460F9F, 0x8E30C852, 0x82503B66, 0x2B3C1F9C, 0x4F88CDF5, 0x001C77A8} } ;
		static const fp2_t var_expected =  { {0xDB60F008, 0xF1CF20B1, 0x9DCFF820, 0x353199EF, 0x43440F3F, 0x2AD250FD, 0x4C202D60, 0x116FE280},
	{0xCB152B53, 0x13C01F8A, 0x98B9F074, 0xD2F037AD, 0x7DAFC4A1, 0x8EF82DE3, 0xF077320C, 0x2506ECD9} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 899 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 900 a1");
	}
	{
		static const fp2_t var_a =  { {0x11E6F35F, 0x38A53393, 0xD1277E78, 0x2AB22E03, 0x5E7BCC54, 0x977C8707, 0x256EB171, 0x0C84CDB6},
	{0x757B51C9, 0x246301FE, 0x03C1F893, 0x8359619F, 0xA9FB744B, 0x8421688A, 0x49415D96, 0x17F7D0B1} } ;
		static const fp2_t var_expected =  { {0xEE190CB4, 0x6E5ACC6C, 0x2ED8819B, 0x366ED1FC, 0xA18433B4, 0x22B7C678, 0x1A914E90, 0x189E96CC},
	{0x8A84AE4A, 0x829CFE01, 0xFC3E0780, 0xDDC79E60, 0x56048BBC, 0x3612E4F5, 0xF6BEA26B, 0x0D2B93D0} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 901 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 902 a1");
	}
	{
		static const fp2_t var_a =  { {0x40E4A0AA, 0x5A2BCE63, 0xE7F9F08A, 0xF451C34E, 0x9DD79138, 0x0B76FA04, 0x51BAAE41, 0x2346F7DE},
	{0xF32BE8D2, 0x9A8E66C3, 0x6A22B11B, 0x46BAFCD0, 0xDCD490A1, 0x8B18A73E, 0xDA42378F, 0x12B9E74C} } ;
		static const fp2_t var_expected =  { {0xBF1B5F69, 0x4CD4319C, 0x18060F89, 0x6CCF3CB1, 0x62286ECF, 0xAEBD537B, 0xEE4551C0, 0x01DC6CA3},
	{0x0CD41741, 0x0C71993C, 0x95DD4EF8, 0x1A66032F, 0x232B6F67, 0x2F1BA641, 0x65BDC872, 0x12697D35} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 903 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 904 a1");
	}
	{
		static const fp2_t var_a =  { {0x3340C30C, 0x62050EA6, 0xFD6E97AA, 0x23EF31E1, 0xEA805B5F, 0x9A7C5988, 0x42A730E0, 0x1299FE77},
	{0x4C91C7DF, 0x22BC9B8D, 0x16859422, 0xF3DEDBB5, 0xAEC9EA02, 0x2DD70AEA, 0x2CDFA3B4, 0x044FBA46} } ;
		static const fp2_t var_expected =  { {0xCCBF3D07, 0x44FAF159, 0x02916869, 0x3D31CE1E, 0x157FA4A9, 0x1FB7F3F7, 0xFD58CF21, 0x1289660A},
	{0xB36E3834, 0x84436472, 0xE97A6BF1, 0x6D42244A, 0x51361605, 0x8C5D4295, 0x13205C4D, 0x20D3AA3C} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 905 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 906 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB42B162, 0x293A6FF9, 0xAD173FA2, 0x50AFA36E, 0xF52585D1, 0xA23688D1, 0x7FDEF390, 0x1B9238A2},
	{0x63EB26BC, 0x12D366F7, 0xBF930DF7, 0x31C5D652, 0xEF4D690E, 0xF7FDF21A, 0x27793E62, 0x1C120E21} } ;
		static const fp2_t var_expected =  { {0x54BD4EB1, 0x7DC59006, 0x52E8C071, 0x10715C91, 0x0ADA7A37, 0x17FDC4AE, 0xC0210C71, 0x09912BDF},
	{0x9C14D957, 0x942C9908, 0x406CF21C, 0x2F5B29AD, 0x10B296FA, 0xC2365B65, 0x1886C19E, 0x09115661} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 907 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 908 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 909 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 910 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 911 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 912 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 913 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 914 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 915 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 916 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 917 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 918 a1");
	}
	{
		static const fp2_t var_a =  { {0xA9E657CD, 0xA3E541F1, 0xCFDC8DDF, 0xC3734CBC, 0xB083E777, 0x507F4855, 0x135D45C8, 0x0F817333},
	{0x5834BBD7, 0x2AF4184A, 0x60199FEB, 0x5657DB6B, 0xB06B2BE0, 0xFDC1514D, 0xF50FD1A7, 0x0E15B0C6} } ;
		static const fp2_t var_expected =  { {0x53CCAF9A, 0x47CA83E3, 0x9FB91BBF, 0x86E69979, 0x6107CEEF, 0xA0FE90AB, 0x26BA8B90, 0x1F02E666},
	{0xB06977AE, 0x55E83094, 0xC0333FD6, 0xACAFB6D6, 0x60D657C0, 0xFB82A29B, 0xEA1FA34F, 0x1C2B618D} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 919 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 920 a1");
	}
	{
		static const fp2_t var_a =  { {0x6EE98FEF, 0x1D84D56A, 0x7C8F0CF7, 0xB8B5B4CD, 0x4C7538B1, 0xB4A9C6BA, 0xC505C07E, 0x20B18D2E},
	{0x8D30249D, 0xBDCFD30F, 0x309122AE, 0xBC0B4065, 0x43D3DA59, 0x02198480, 0x7EC8338D, 0x17EAD7B5} } ;
		static const fp2_t var_expected =  { {0xDDD31FCB, 0x9409AAD4, 0xF91E19DA, 0x104A699A, 0x98EA715B, 0xAF1F3FF4, 0x4A0B80FB, 0x1C3FB5DB},
	{0x1A604927, 0xD49FA61F, 0x61224549, 0x16F580CA, 0x87A7B4AB, 0x49FEBB80, 0xBD906718, 0x0AB24AE8} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 921 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 922 a1");
	}
	{
		static const fp2_t var_a =  { {0x7BDACD4C, 0x50471805, 0x0D79EB9D, 0x1F955431, 0x39048FC1, 0x63921205, 0xA02C8ECD, 0x025EAD73},
	{0xA27E2EA3, 0x37EAC201, 0xA9B65E8A, 0x6798E45A, 0x37EBA12D, 0x9A7AAE7E, 0x2C8D30D1, 0x056557D0} } ;
		static const fp2_t var_expected =  { {0xF7B59A98, 0xA08E300A, 0x1AF3D73A, 0x3F2AA862, 0x72091F82, 0xC724240A, 0x40591D9A, 0x04BD5AE7},
	{0x44FC5D46, 0x6FD58403, 0x536CBD14, 0xCF31C8B5, 0x6FD7425A, 0x34F55CFC, 0x591A61A3, 0x0ACAAFA0} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 923 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 924 a1");
	}
	{
		static const fp2_t var_a =  { {0x912B3B8A, 0x3362AAFE, 0x1CEB94DA, 0xE52B7DE9, 0x29780B87, 0xEB1839F5, 0xAB2B2F8C, 0x01649678},
	{0x79A7FFA9, 0x75FA4837, 0x8415D328, 0x0C132C8A, 0x5FE0C55F, 0xDCDB580E, 0xA88D6AB4, 0x2486748E} } ;
		static const fp2_t var_expected =  { {0x22567714, 0x66C555FD, 0x39D729B4, 0xCA56FBD2, 0x52F0170F, 0xD63073EA, 0x56565F19, 0x02C92CF1},
	{0xF34FFF3F, 0x44F4906E, 0x082BA63D, 0xB7055915, 0xBFC18AB5, 0xFF82629C, 0x111AD567, 0x23E9849B} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 925 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 926 a1");
	}
	{
		static const fp2_t var_a =  { {0xB0403884, 0x425D65FF, 0x81CFFED7, 0x5E10A4AE, 0x0C67A330, 0x040C8A31, 0xB1F2C044, 0x0B5A5090},
	{0x322E2531, 0x232D21BB, 0xB999CCCF, 0x4C31CB6B, 0xCAB5E439, 0x39E8D9C7, 0x9AD9494C, 0x06EAF793} } ;
		static const fp2_t var_expected =  { {0x60807108, 0x84BACBFF, 0x039FFDAE, 0xBC21495D, 0x18CF4660, 0x08191462, 0x63E58088, 0x16B4A121},
	{0x645C4A62, 0x465A4376, 0x7333999E, 0x986396D7, 0x956BC872, 0x73D1B38F, 0x35B29298, 0x0DD5EF27} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 927 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 928 a1");
	}
	{
		static const fp2_t var_a =  { {0x1B803902, 0x0C635792, 0x5538C26D, 0xAD07F387, 0x14C5118A, 0x61A5904C, 0xB993CD6B, 0x0A91B2A4},
	{0x2EA0870D, 0xC87F74EB, 0x821FC30A, 0x85B6691A, 0xCB54D78D, 0x48B8D8AD, 0xEBEAEA45, 0x14352E02} } ;
		static const fp2_t var_expected =  { {0x37007204, 0x18C6AF24, 0xAA7184DA, 0x5A0FE70E, 0x298A2315, 0xC34B2098, 0x73279AD6, 0x15236549},
	{0x5D410E07, 0xE9FEE9D6, 0x043F8601, 0xAA4BD235, 0x96A9AF12, 0xD73D63DB, 0x97D5D488, 0x0346F783} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 929 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 930 a1");
	}
	{
		static const fp2_t var_a =  { {0x51620D38, 0xAD903255, 0xF2EFF100, 0x419334F7, 0xB2F4EA99, 0xAE0A3954, 0xCED59C93, 0x214C4DAA},
	{0x0FA5415D, 0x4204E349, 0x5803EC26, 0x17F511E3, 0xF29C3700, 0x830E4E68, 0x453812BA, 0x1375CF37} } ;
		static const fp2_t var_expected =  { {0xA2C41A5D, 0xB42064AA, 0xE5DFE1ED, 0x220569EF, 0x65E9D52A, 0xA1E02529, 0x5DAB3925, 0x1D7536D3},
	{0x1F4A82A7, 0xDD09C692, 0xB007D838, 0xCEC923C6, 0xE5386DF7, 0x4BE84F51, 0x4A702573, 0x01C839EC} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 931 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 932 a1");
	}
	{
		static const fp2_t var_a =  { {0x1482855E, 0x13483022, 0xEF08BF41, 0x27531335, 0x97D6D4AB, 0xA9138653, 0xB8C10915, 0x06A66846},
	{0xB50E5B8A, 0x1F3E81A0, 0xF4B123E7, 0xF5897F1C, 0x10748A3A, 0x8E7507A8, 0xD1C623EF, 0x08DAEA4F} } ;
		static const fp2_t var_expected =  { {0x29050ABC, 0x26906044, 0xDE117E82, 0x4EA6266B, 0x2FADA956, 0x52270CA7, 0x7182122B, 0x0D4CD08D},
	{0x6A1CB714, 0x3E7D0341, 0xE96247CE, 0xEB12FE39, 0x20E91475, 0x1CEA0F50, 0xA38C47DF, 0x11B5D49F} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 933 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 934 a1");
	}
	{
		static const fp2_t var_a =  { {0x66AC836F, 0xAE7D68B9, 0x276ED738, 0xD6A6B13A, 0xB3D9E259, 0x37CE9083, 0xFF39DCF6, 0x1AB7226C},
	{0x41E96786, 0x3867C9A0, 0x4F3812B0, 0xE8953BA2, 0x36D60D85, 0xD9164A06, 0xF7B21E3F, 0x1F3E74CB} } ;
		static const fp2_t var_expected =  { {0xCD5906CB, 0xB5FAD172, 0x4EDDAE5D, 0x4C2C6274, 0x67B3C4AB, 0xB568D387, 0xBE73B9EA, 0x104AE057},
	{0x83D2CEF9, 0xC9CF9340, 0x9E70254C, 0x70097744, 0x6DAC1B03, 0xF7F8468C, 0xAF643C7D, 0x19598515} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 935 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 936 a1");
	}
	{
		static const fp2_t var_a =  { {0x86F06A38, 0xD5089DAE, 0xB3728D14, 0x6CF08495, 0x370B16D7, 0x3BA7FEAF, 0xAE7FA64F, 0x1F080DB1},
	{0x158B0B46, 0x3FC98061, 0xA1D38AA0, 0xC8958890, 0xB6E52A66, 0x41113A84, 0xA0CA9CBD, 0x008D7C27} } ;
		static const fp2_t var_expected =  { {0x0DE0D45D, 0x03113B5D, 0x66E51A16, 0x78C0092B, 0x6E162DA6, 0xBD1BAFDE, 0x1CFF4C9C, 0x18ECB6E1},
	{0x2B16168C, 0x7F9300C2, 0x43A71540, 0x912B1121, 0x6DCA54CD, 0x82227509, 0x4195397A, 0x011AF84F} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 937 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 938 a1");
	}
	{
		static const fp2_t var_a =  { {0xF6AFF46E, 0x1FF378A0, 0xEA61C204, 0x44439A42, 0x962601B3, 0xD4909DE1, 0x0CCC26F8, 0x173EF659},
	{0xD1A45FAF, 0xB1049160, 0x64814220, 0x72E92E1E, 0x1FFB8B11, 0x28B783F6, 0x7614D60F, 0x069AA3C9} } ;
		static const fp2_t var_expected =  { {0xED5FE8C9, 0x98E6F141, 0xD4C383F4, 0x27663485, 0x2C4C035E, 0xEEECEE43, 0xD9984DEF, 0x095A882F},
	{0xA348BF5E, 0x620922C1, 0xC9028441, 0xE5D25C3C, 0x3FF71622, 0x516F07EC, 0xEC29AC1E, 0x0D354792} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 939 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 940 a1");
	}
	{
		static const fp2_t var_a =  { {0x76AE68A5, 0xBCCD43FE, 0x670F94E0, 0x9512240E, 0x7FA5900E, 0xA80E346D, 0x64DA2C5E, 0x1FCBB919},
	{0x57513FA7, 0x7168D5ED, 0x518FBAF7, 0x7ACB0DB1, 0x44B5D619, 0x7A5C4770, 0x6265A87B, 0x12E628DD} } ;
		static const fp2_t var_expected =  { {0xED5CD137, 0xD29A87FC, 0xCE1F29AD, 0xC903481C, 0xFF4B2014, 0x95E81B5A, 0x89B458BB, 0x1A740DB0},
	{0xAEA27F3B, 0x3BD1ABDA, 0xA31F75DB, 0x94751B62, 0x896BAC2A, 0x3A844160, 0x84CB50F5, 0x00A8ED38} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 941 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 942 a1");
	}
	{
		static const fp2_t var_a =  { {0x09223F28, 0x33F708E1, 0x0267D499, 0x4D545A34, 0xE3CFF670, 0xFD4446F0, 0x7E7B0372, 0x0E38B40F},
	{0xC72575B6, 0x0D3CDC23, 0x602B7AA4, 0xEB258B8A, 0x35090A79, 0x30FDCE85, 0x4CEDA2DD, 0x03B750BC} } ;
		static const fp2_t var_expected =  { {0x12447E50, 0x67EE11C2, 0x04CFA932, 0x9AA8B468, 0xC79FECE0, 0xFA888DE1, 0xFCF606E5, 0x1C71681E},
	{0x8E4AEB6C, 0x1A79B847, 0xC056F548, 0xD64B1714, 0x6A1214F3, 0x61FB9D0A, 0x99DB45BA, 0x076EA178} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 943 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 944 a1");
	}
	{
		static const fp2_t var_a =  { {0xEFC217A3, 0xAEF532BD, 0xD5FC34DB, 0x5AA3AF40, 0xF5CBBB6A, 0xB03E4D5D, 0xA3245E5E, 0x0BDBE2F7},
	{0x8241D2AB, 0xD2159CD3, 0xCCF380C1, 0x1A3BDAA8, 0x43528029, 0x130AD976, 0x1DC9150B, 0x187DAE89} } ;
		static const fp2_t var_expected =  { {0xDF842F46, 0x5DEA657B, 0xABF869B7, 0xB5475E81, 0xEB9776D4, 0x607C9ABB, 0x4648BCBD, 0x17B7C5EF},
	{0x0483A543, 0xFD2B39A7, 0x99E7016F, 0xD356B551, 0x86A50049, 0x6BE1656C, 0xFB922A14, 0x0BD7F88F} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 945 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 946 a1");
	}
	{
		static const fp2_t var_a =  { {0xA8DB28E3, 0x55C09AF1, 0x379D5087, 0xBEDF6168, 0x24AEF101, 0xFC740E24, 0xDB7CCA6F, 0x21E906D3},
	{0x2A5E202B, 0x31231D08, 0x0C8708B2, 0x0E5304BA, 0xFF619539, 0xB22BFB23, 0x3F9225FC, 0x1CAE27AB} } ;
		static const fp2_t var_expected =  { {0x51B651B3, 0x048135E3, 0x6F3AA0FB, 0x1C9DC2D0, 0x495DE1FB, 0x3EB3CEC8, 0x76F994DE, 0x1EAEA925},
	{0x54BC4043, 0xBB463A10, 0x190E1150, 0xBB850974, 0xFEC32A69, 0xAA23A8C7, 0x3F244BF7, 0x1438EAD4} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 947 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 948 a1");
	}
	{
		static const fp2_t var_a =  { {0xF6580312, 0x09130B79, 0xC3DC59C6, 0xF45E50DD, 0x21898BF6, 0x11650E87, 0xF1F0A5BB, 0x215F4145},
	{0x9FDFFBCB, 0x26811607, 0xDA137FA6, 0x12A8DD3D, 0x3A90F06D, 0x9A7AEE4B, 0x1BEDE2C0, 0x0E66317D} } ;
		static const fp2_t var_expected =  { {0xECB00611, 0x6B2616F3, 0x87B8B378, 0x879BA1BB, 0x431317E5, 0x6895CF8E, 0xA3E14B74, 0x1D9B1E09},
	{0x3FBFF796, 0x4D022C0F, 0xB426FF4C, 0x2551BA7B, 0x7521E0DA, 0x34F5DC96, 0x37DBC581, 0x1CCC62FA} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 949 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 950 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 951 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 952 a1");
	}
	{
		static const fp2_t var_a =  { {0x4ED0DF79, 0xDA892E38, 0x9BCF0A6F, 0x5E16F8CA, 0xE3A6CDF6, 0x79712618, 0xED5A0DBA, 0x00D22A63},
	{0x9DDE858B, 0xE2971E77, 0xD4DF9084, 0x777F889A, 0x142FC195, 0x538A334F, 0x45F53031, 0x192486EA} } ;
		static const fp2_t var_expected =  { {0x4ED0DF79, 0xDA892E38, 0x9BCF0A6F, 0x5E16F8CA, 0xE3A6CDF6, 0x79712618, 0xED5A0DBA, 0x00D22A63},
	{0x62217A88, 0xC468E188, 0x2B206F8E, 0xE9A17765, 0xEBD03E72, 0x66AA1A30, 0xFA0ACFD0, 0x0BFEDD97} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 953 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 954 a1");
	}
	{
		static const fp2_t var_a =  { {0xC47753DE, 0x4BFCAFFA, 0x516FD90E, 0x8A2E610C, 0xB046BA29, 0xEC4572F5, 0xE0FD8A4F, 0x01EF560C},
	{0x65EE7DAF, 0x4AD616B4, 0x3A8EB9C6, 0x28B911BC, 0x6404B729, 0xBD4FCFB6, 0x6C4B3D68, 0x037C6E16} } ;
		static const fp2_t var_expected =  { {0xC47753DE, 0x4BFCAFFA, 0x516FD90E, 0x8A2E610C, 0xB046BA29, 0xEC4572F5, 0xE0FD8A4F, 0x01EF560C},
	{0x9A118264, 0x5C29E94B, 0xC571464D, 0x3867EE43, 0x9BFB48DF, 0xFCE47DC9, 0xD3B4C298, 0x21A6F66B} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 955 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 956 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB7A4D0C, 0xDE0728FB, 0x84D9ACDE, 0x4707F970, 0x3C17743A, 0xE73D005A, 0x05EA47BF, 0x1132E36B},
	{0xE7E79D92, 0xB400D0C9, 0x0F9ADC47, 0xF841C75A, 0x258EEB88, 0x1D7428FC, 0x73804E84, 0x065D374C} } ;
		static const fp2_t var_expected =  { {0xAB7A4D0C, 0xDE0728FB, 0x84D9ACDE, 0x4707F970, 0x3C17743A, 0xE73D005A, 0x05EA47BF, 0x1132E36B},
	{0x18186281, 0xF2FF2F36, 0xF06523CB, 0x68DF38A5, 0xDA71147F, 0x9CC02483, 0xCC7FB17D, 0x1EC62D35} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 957 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 958 a1");
	}
	{
		static const fp2_t var_a =  { {0x128EC4AA, 0x979EA39A, 0xC4E7F40D, 0x51AF5B1F, 0x4A85B9C4, 0x14B5BE2C, 0xE37D0026, 0x094EE2DF},
	{0x7FB5A2AC, 0x01A278C4, 0xF56F1F5B, 0x8987A7E1, 0x2A3D0C1F, 0x46F8518F, 0xF8ED2345, 0x1C80A5D4} } ;
		static const fp2_t var_expected =  { {0x128EC4AA, 0x979EA39A, 0xC4E7F40D, 0x51AF5B1F, 0x4A85B9C4, 0x14B5BE2C, 0xE37D0026, 0x094EE2DF},
	{0x7FB5A2AC, 0x01A278C4, 0xF56F1F5B, 0x8987A7E1, 0x2A3D0C1F, 0x46F8518F, 0xF8ED2345, 0x1C80A5D4} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 959 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 960 a1");
	}
	{
		static const fp2_t var_a =  { {0xD4FCC803, 0xA8652553, 0xDBD5748E, 0x4DCC03F8, 0x9981E2F2, 0x751B9FD4, 0x10DED8DA, 0x211057A7},
	{0x8F89494E, 0x4BC967AA, 0xCAA15475, 0x320D7C29, 0x52B982C0, 0x9BF4906F, 0x8A0DBB2F, 0x20B19D6C} } ;
		static const fp2_t var_expected =  { {0xD4FCC803, 0xA8652553, 0xDBD5748E, 0x4DCC03F8, 0x9981E2F2, 0x751B9FD4, 0x10DED8DA, 0x211057A7},
	{0x7076B6C5, 0x5B369855, 0x355EAB9E, 0x2F1383D6, 0xAD467D48, 0x1E3FBD10, 0xB5F244D2, 0x0471C715} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 961 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 962 a1");
	}
	{
		static const fp2_t var_a =  { {0x35D95F28, 0x0EF4AA40, 0xDE11B8FD, 0x33E6643B, 0x242F5E9F, 0x7CD2C2A3, 0x1CEF203D, 0x1E27DAF5},
	{0x33F2B978, 0x71F24A89, 0xB8A1E1FF, 0x88B67026, 0x75914D23, 0xCE7493CA, 0x54C46856, 0x00F30173} } ;
		static const fp2_t var_expected =  { {0x35D95F28, 0x0EF4AA40, 0xDE11B8FD, 0x33E6643B, 0x242F5E9F, 0x7CD2C2A3, 0x1CEF203D, 0x1E27DAF5},
	{0xCC0D469B, 0x350DB576, 0x475E1E14, 0xD86A8FD9, 0x8A6EB2E4, 0xEBBFB9B5, 0xEB3B97AA, 0x2430630E} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 963 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 964 a1");
	}
	{
		static const fp2_t var_a =  { {0x0280544B, 0xF40FED25, 0x70CB6665, 0xAB983D06, 0x100C0955, 0x5497A1E9, 0x8FC01944, 0x1C8FE735},
	{0x91A9B5B3, 0xE835BD9B, 0x77E25DE2, 0xC6A0C712, 0x0014CB24, 0xA5B9FE60, 0xEF8AAEAF, 0x0A2CF5D3} } ;
		static const fp2_t var_expected =  { {0x0280544B, 0xF40FED25, 0x70CB6665, 0xAB983D06, 0x100C0955, 0x5497A1E9, 0x8FC01944, 0x1C8FE735},
	{0x6E564A60, 0xBECA4264, 0x881DA230, 0x9A8038ED, 0xFFEB34E3, 0x147A4F1F, 0x50755152, 0x1AF66EAE} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 965 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 966 a1");
	}
	{
		static const fp2_t var_a =  { {0x76E034E5, 0x51E5C875, 0x055A4873, 0x8E5B708F, 0x840077D9, 0xEF07C98A, 0xA922CB3A, 0x210D81E2},
	{0x2C5BF8E7, 0xBDE60A10, 0xCFA52BF6, 0xFB3E6079, 0xD1ABC674, 0x8611E39E, 0x4E9E69F3, 0x08C65BBD} } ;
		static const fp2_t var_expected =  { {0x76E034E5, 0x51E5C875, 0x055A4873, 0x8E5B708F, 0x840077D9, 0xEF07C98A, 0xA922CB3A, 0x210D81E2},
	{0x2C5BF8E7, 0xBDE60A10, 0xCFA52BF6, 0xFB3E6079, 0xD1ABC674, 0x8611E39E, 0x4E9E69F3, 0x08C65BBD} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 967 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 968 a1");
	}
	{
		static const fp2_t var_a =  { {0x22DEDF75, 0x8A1D0437, 0xEA04499C, 0xAAC0CC57, 0x7C6F4FC2, 0x5362F926, 0xE8767C2D, 0x0E2C1C9F},
	{0x7D4CD372, 0x997CD985, 0x5F6306FD, 0xBA653EAC, 0x211968F7, 0x6908B7AB, 0x00CB7AF8, 0x17851CF6} } ;
		static const fp2_t var_expected =  { {0x22DEDF75, 0x8A1D0437, 0xEA04499C, 0xAAC0CC57, 0x7C6F4FC2, 0x5362F926, 0xE8767C2D, 0x0E2C1C9F},
	{0x7D4CD372, 0x997CD985, 0x5F6306FD, 0xBA653EAC, 0x211968F7, 0x6908B7AB, 0x00CB7AF8, 0x17851CF6} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 969 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 970 a1");
	}
	{
		static const fp2_t var_a =  { {0x0BF4BA12, 0x21230489, 0x5A338C03, 0xE0C63073, 0x0FA31A63, 0x15F54C69, 0xECAD8849, 0x0D3F120E},
	{0x81F388E6, 0x3CA51A6E, 0xA96F3E7A, 0x35E8B6C5, 0x80DF6098, 0xB92CE517, 0x57EF250C, 0x065BABE8} } ;
		static const fp2_t var_expected =  { {0x0BF4BA12, 0x21230489, 0x5A338C03, 0xE0C63073, 0x0FA31A63, 0x15F54C69, 0xECAD8849, 0x0D3F120E},
	{0x81F388E6, 0x3CA51A6E, 0xA96F3E7A, 0x35E8B6C5, 0x80DF6098, 0xB92CE517, 0x57EF250C, 0x065BABE8} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 971 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 972 a1");
	}
	{
		static const fp2_t var_a =  { {0x85906A27, 0x7EA31470, 0x30E404DD, 0xBC194439, 0x7A0FD2B8, 0x51998B04, 0x078C428F, 0x180675BC},
	{0xC67E79BB, 0x31B59AF8, 0x022EF39A, 0xD30E2BF1, 0x8CAC42FD, 0xF1E70B91, 0xD000ED35, 0x235899CB} } ;
		static const fp2_t var_expected =  { {0x85906A27, 0x7EA31470, 0x30E404DD, 0xBC194439, 0x7A0FD2B8, 0x51998B04, 0x078C428F, 0x180675BC},
	{0x39818658, 0x754A6507, 0xFDD10C79, 0x8E12D40E, 0x7353BD0A, 0xC84D41EE, 0x6FFF12CB, 0x01CACAB6} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 973 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 974 a1");
	}
	{
		static const fp2_t var_a =  { {0x710678FD, 0xE616B3AA, 0x5E7DF84B, 0x3383AB7A, 0x26776520, 0xA886836B, 0xBD38B570, 0x026BB6B5},
	{0x7EB3FA7F, 0xE0496B40, 0x8DCCFB9B, 0xEB266A87, 0x8ADE7CD4, 0x978BFA59, 0x677218E3, 0x10D90554} } ;
		static const fp2_t var_expected =  { {0x710678FD, 0xE616B3AA, 0x5E7DF84B, 0x3383AB7A, 0x26776520, 0xA886836B, 0xBD38B570, 0x026BB6B5},
	{0x814C0594, 0xC6B694BF, 0x72330477, 0x75FA9578, 0x75218333, 0x22A85326, 0xD88DE71E, 0x144A5F2D} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 975 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 976 a1");
	}
	{
		static const fp2_t var_a =  { {0x26392E64, 0x577A97B4, 0xF3016E4E, 0xD1FAC4E6, 0xBEF8DFF0, 0xEBDD1E08, 0xA6F5E3EB, 0x1662CF8C},
	{0xAFC005F7, 0xA0C08F42, 0x6615376B, 0xB201DB87, 0x30847B69, 0x32F4AEE9, 0xE6970FCB, 0x136ECF0B} } ;
		static const fp2_t var_expected =  { {0x26392E64, 0x577A97B4, 0xF3016E4E, 0xD1FAC4E6, 0xBEF8DFF0, 0xEBDD1E08, 0xA6F5E3EB, 0x1662CF8C},
	{0xAFC005F7, 0xA0C08F42, 0x6615376B, 0xB201DB87, 0x30847B69, 0x32F4AEE9, 0xE6970FCB, 0x136ECF0B} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 977 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 978 a1");
	}
	{
		static const fp2_t var_a =  { {0xF1829F3B, 0x5B579B3A, 0x92C3D4A8, 0xBDA4852B, 0x5B81FD76, 0x5EEA5830, 0x5333D8FE, 0x1DECCCF0},
	{0x1C8E75C7, 0x546F15ED, 0xC0EC8E65, 0x0BBD8F86, 0x64C09CC6, 0xBE0D4EB5, 0xF74DBE7F, 0x08828961} } ;
		static const fp2_t var_expected =  { {0xF1829F3B, 0x5B579B3A, 0x92C3D4A8, 0xBDA4852B, 0x5B81FD76, 0x5EEA5830, 0x5333D8FE, 0x1DECCCF0},
	{0x1C8E75C7, 0x546F15ED, 0xC0EC8E65, 0x0BBD8F86, 0x64C09CC6, 0xBE0D4EB5, 0xF74DBE7F, 0x08828961} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 979 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 980 a1");
	}
	{
		static const fp2_t var_a =  { {0x607FB470, 0x69F942C3, 0x67762776, 0xB608B46A, 0x8EDB4194, 0x9E129B28, 0xA6F2E21D, 0x0AA8DE75},
	{0x85083592, 0xEA920F4D, 0x97F6E426, 0xAB65D204, 0xEE07CF4A, 0x3BA2D929, 0xC2EA1642, 0x2016A688} } ;
		static const fp2_t var_expected =  { {0x607FB470, 0x69F942C3, 0x67762776, 0xB608B46A, 0x8EDB4194, 0x9E129B28, 0xA6F2E21D, 0x0AA8DE75},
	{0x7AF7CA81, 0xBC6DF0B2, 0x68091BEC, 0xB5BB2DFB, 0x11F830BD, 0x7E917456, 0x7D15E9BF, 0x050CBDF9} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 981 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 982 a1");
	}
	{
		static const fp2_t var_a =  { {0x52E40D4D, 0x35A02B00, 0x1E667834, 0x18CF6130, 0xF3AD4EC8, 0xA6E957B2, 0x1F7C63FD, 0x004B26E6},
	{0x17ABF8A9, 0x16159518, 0x3BE5B6FA, 0xFEF76892, 0xD7C8CDDD, 0x9706D19A, 0x4E1291D4, 0x19102F24} } ;
		static const fp2_t var_expected =  { {0x52E40D4D, 0x35A02B00, 0x1E667834, 0x18CF6130, 0xF3AD4EC8, 0xA6E957B2, 0x1F7C63FD, 0x004B26E6},
	{0xE854076A, 0x90EA6AE7, 0xC41A4919, 0x6229976D, 0x2837322A, 0x232D7BE5, 0xF1ED6E2D, 0x0C13355D} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 983 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 984 a1");
	}
	{
		static const fp2_t var_a =  { {0xAD62A1D7, 0xF9E02686, 0x5CCA5EEA, 0x44AF6F3A, 0x18A24432, 0xF808B7DA, 0x46FF3305, 0x0D43EE17},
	{0x8721A29E, 0xD4879B0D, 0x289A1D20, 0xF424C9AF, 0xE698E45E, 0x2E8B2EA8, 0x4A9409C0, 0x1854D28D} } ;
		static const fp2_t var_expected =  { {0xAD62A1D7, 0xF9E02686, 0x5CCA5EEA, 0x44AF6F3A, 0x18A24432, 0xF808B7DA, 0x46FF3305, 0x0D43EE17},
	{0x78DE5D75, 0xD27864F2, 0xD765E2F2, 0x6CFC3650, 0x19671BA9, 0x8BA91ED7, 0xF56BF641, 0x0CCE91F4} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 985 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 986 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 987 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 988 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 989 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 990 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 991 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 992 a1");
	}
	{
		static const fp2_t var_a =  { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0xFFFFFFC7, 0x0AFFFFFF, 0xFFFFFFC5, 0xDC9CFFFF, 0xFFFFFFE6, 0xD163177F, 0x3FFFFFFA, 0x1095D279},
	{0xFFFFFFC7, 0x0AFFFFFF, 0xFFFFFFC5, 0xDC9CFFFF, 0xFFFFFFE6, 0xD163177F, 0x3FFFFFFA, 0x1095D279} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 993 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 994 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F} } ;
		static const fp2_t var_expected =  { {0x0000004C, 0x9C000000, 0x0000004E, 0x84840000, 0x00000021, 0xE8D13600, 0x00000006, 0x148D9209},
	{0xFFFFFFC7, 0x0AFFFFFF, 0xFFFFFFC5, 0xDC9CFFFF, 0xFFFFFFE6, 0xD163177F, 0x3FFFFFFA, 0x1095D279} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 995 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 996 a1");
	}
	{
		static const fp2_t var_a =  { {0x101B5972, 0x7350E892, 0x783A052A, 0x0DD75426, 0x715A8237, 0x17221240, 0x97A0B039, 0x09F2C75C},
	{0xC85096D7, 0x7E8251E9, 0x310980B3, 0xD8B927F1, 0x80F4E25F, 0x3BE1C18E, 0x64546BED, 0x0E60E131} } ;
		static const fp2_t var_expected =  { {0xA2FA752C, 0x69B47E10, 0x71034B88, 0xDD93C3D1, 0x12C58645, 0x48E583DD, 0xC1A78367, 0x0099F136},
	{0x55620A5E, 0xEF0CB6BD, 0x31EC55AE, 0x8B5C620A, 0xEFDDE0F2, 0x0DC7A12F, 0x5D814F7B, 0x21227B04} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 997 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 998 a1");
	}
	{
		static const fp2_t var_a =  { {0x6E827E5C, 0x309F505B, 0x6B70E665, 0x263402E0, 0x60475B02, 0x1E2B9347, 0x3E65C791, 0x24C266D0},
	{0xFAC3091A, 0x48B7F8F6, 0x3AAE68CB, 0x876A23BE, 0xCC5500B3, 0x262B6CE5, 0x791B4A39, 0x185001B0} } ;
		static const fp2_t var_expected =  { {0xD5B3127B, 0x43E832E5, 0x9A58BFB6, 0x0472AE2C, 0x498C2882, 0x750AFCC6, 0xE73AAB98, 0x1DF4B0E2},
	{0x6D62B84C, 0xE0D61985, 0x08753ECD, 0x962C8B79, 0xE4E8D4DB, 0xD957A0E1, 0x4717104D, 0x084962CA} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 999 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1000 a1");
	}
	{
		static const fp2_t var_a =  { {0xE231753C, 0x3E6B7E10, 0x745C8E0A, 0x282F3327, 0xED67CEC3, 0xA6110CCA, 0x67EA7B14, 0x0BC46DFB},
	{0x5FB07380, 0x29A96962, 0x02BACB04, 0x450C725F, 0x8B09F89B, 0xFEF32F37, 0xC04DD7D4, 0x15A2C345} } ;
		static const fp2_t var_expected =  { {0x04685498, 0xD4E8F3BF, 0x347E7D0E, 0x156DA1CD, 0x97FB5255, 0x6A11F8D3, 0xFBAB314B, 0x1AE7AA96},
	{0xD10600AB, 0x95191289, 0x51C431BB, 0x36363B24, 0x93A3AF91, 0xECC5B690, 0xFADA6F47, 0x175B8563} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1001 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1002 a1");
	}
	{
		static const fp2_t var_a =  { {0x08627542, 0x3DC2F62A, 0x6D20786F, 0x4368A889, 0x39A114F9, 0x9B458FD3, 0xEEE5504D, 0x1846A220},
	{0x7EDA0BE7, 0x74A6969C, 0xFC19EDC6, 0x1F3F5B92, 0x12376475, 0x48F673CF, 0x4CFE15F8, 0x1997DBD9} } ;
		static const fp2_t var_expected =  { {0x7209B92A, 0xAC8A9AD9, 0x8B8DC3BF, 0xA785CEC0, 0xCAC7CE57, 0xCE1BA3C7, 0x258BE728, 0x19C1A0A8},
	{0x1B15EC2E, 0x462DBADD, 0x9834D82C, 0xF38372BD, 0x7212A0CF, 0x922659B9, 0x3A171EAF, 0x1BAF19E3} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1003 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1004 a1");
	}
	{
		static const fp2_t var_a =  { {0x5D9AA210, 0x65C9FD00, 0x5E1D1FEC, 0xF0B545B8, 0x06F9B200, 0x1482A017, 0xE10F3677, 0x129F7587},
	{0xB8635F39, 0x6A2C071C, 0x8350138B, 0x3FB967A8, 0x6F94209F, 0x6287BB55, 0x6C90C37C, 0x122A1447} } ;
		static const fp2_t var_expected =  { {0xCF740D50, 0x923B21E4, 0x2BBA1977, 0xA17FF3C8, 0x5D82CE59, 0x12609164, 0x4BA7F77D, 0x0D17D0B7},
	{0xA8F24BD3, 0x1BE0EDFB, 0xC2F5ED3C, 0x0AA7BF05, 0xA3A9F389, 0x5D37A254, 0x9FE9CC7D, 0x1F0994EC} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1005 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1006 a1");
	}
	{
		static const fp2_t var_a =  { {0x91EAC07C, 0x2AAD8854, 0x5673B412, 0x359CED88, 0x32E26997, 0x2EF2CCD4, 0x43F8F151, 0x1299EA6A},
	{0xA0CC0556, 0x6B4C4CB9, 0xFF7E5636, 0xD84F5999, 0x5462D314, 0xD3F8DA1E, 0x4DB30FB0, 0x1A7D9368} } ;
		static const fp2_t var_expected =  { {0x5C1B7144, 0x985DE1BF, 0x9C241913, 0x9A8C8E26, 0x7BBCEFBB, 0xD0DECB0F, 0x14858533, 0x0380651C},
	{0x4570E6AA, 0x48CE1A89, 0xCF7902F7, 0xB55C1C1F, 0x4A9BE690, 0x83A8FCC8, 0xD6650ED4, 0x01135155} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1007 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1008 a1");
	}
	{
		static const fp2_t var_a =  { {0xF5F8AF99, 0x465EDB3A, 0x8CEC15AA, 0x6133584E, 0xCA9B8C74, 0x37D6C988, 0xBBF6A9CD, 0x154A748F},
	{0x1BC1D4B1, 0xD7BE817C, 0xD21D1BAE, 0xF4494AE9, 0x980B550B, 0xE30F4BC9, 0x8BDA69C5, 0x1530B8E9} } ;
		static const fp2_t var_expected =  { {0xA5EDB01F, 0x827AC8A3, 0x8FD29A4C, 0xF80F3E4D, 0x97D83191, 0x78980E6A, 0x049C54D2, 0x1A0589B5},
	{0xF51576EE, 0xD25A6F79, 0x0C7B2AEF, 0xC2635AC6, 0x310CED9C, 0xBD787558, 0xAB3C8391, 0x06B876B5} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1009 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1010 a1");
	}
	{
		static const fp2_t var_a =  { {0xEC9E43B0, 0x954A7613, 0x28797E41, 0x2F55E14A, 0x6F1341E9, 0xDE1EE7B4, 0x2B2B6C15, 0x246F92D9},
	{0x3591E93B, 0x85ADB953, 0x8CA05D4D, 0x70A8E631, 0x8C5CD407, 0x2404AA7D, 0xE38907B6, 0x0D47A7F7} } ;
		static const fp2_t var_expected =  { {0xF3480C2E, 0xA7C52AB6, 0xD9609246, 0x64E0E8FE, 0x6946E717, 0x0D40AB70, 0xED18669B, 0x15FB4B87},
	{0x99D241BA, 0xE013C4A1, 0x7B96B7CE, 0x5A572CBC, 0x6235E13B, 0x4B163127, 0x4A1054FD, 0x0BB413B4} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1011 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1012 a1");
	}
	{
		static const fp2_t var_a =  { {0x56F1E9E4, 0xD7336572, 0x7CD03784, 0x798BC611, 0x8E2A7436, 0xAADFDD6C, 0xADB2C65F, 0x23BD240A},
	{0x4C46BD5D, 0xC3150721, 0x06549233, 0x974B060B, 0xDC6DF814, 0x2EFAF7BF, 0xF8C950B2, 0x02FB088D} } ;
		static const fp2_t var_expected =  { {0x35114011, 0x30C6A091, 0x3A9F24B1, 0x3B60F0C3, 0x1C0B1111, 0x7282526F, 0xC902256B, 0x0E247698},
	{0xBB998602, 0x6AE564EC, 0xDA6E6B95, 0xAC7F848F, 0x33A99C1A, 0x5F1A55CD, 0x6982C9C1, 0x22A768CA} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1013 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1014 a1");
	}
	{
		static const fp2_t var_a =  { {0x1C6B8A20, 0x2ACEF67E, 0xEA0D208F, 0x7A5AD9EF, 0x14FF8015, 0xD79B8CBF, 0xF8A13CE0, 0x214B891B},
	{0x966C2FDE, 0x44F72F21, 0x172EF2F7, 0xF6C9F285, 0xC3288365, 0x84166194, 0xD680D80A, 0x20AA5B58} } ;
		static const fp2_t var_expected =  { {0x6C694797, 0x127864A3, 0xE8432050, 0xEBD7F1B5, 0xBB12D7ED, 0xD1D3A572, 0x3C95EE7C, 0x1244C588},
	{0xDB3F0989, 0xDEEE0BF8, 0x19977592, 0x614C9A71, 0x63B62D19, 0x3F6E5376, 0x36D6B3BE, 0x07292D52} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1015 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1016 a1");
	}
	{
		static const fp2_t var_a =  { {0x4E80CE29, 0xABFC7FC4, 0x0280AEC0, 0xDA7D45DC, 0x780E05BE, 0x5A70C741, 0x1F2A25F7, 0x050D84E6},
	{0xFD70A95B, 0x0A654DF6, 0x40D0FAEA, 0x3A7BEE3D, 0x35177E8F, 0x0892953B, 0xB31D1979, 0x1F816145} } ;
		static const fp2_t var_expected =  { {0x0189CB37, 0xBEEDD713, 0xE8664CBF, 0x876EA96A, 0xD638B387, 0xB31AAC0E, 0x73DFC854, 0x164C6C7C},
	{0x2442592E, 0xFF1DEB73, 0x130FB0D7, 0x2B90E64A, 0xEF6D26A2, 0xA1FD5099, 0xBB07ABBB, 0x1F4A2A85} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1017 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1018 a1");
	}
	{
		static const fp2_t var_a =  { {0x91600886, 0x38227AF7, 0xAD845732, 0x47B2A156, 0xA287A952, 0x7A782671, 0x00A635B7, 0x134292D2},
	{0x88DD0C1A, 0x23A3601D, 0xF06F3F41, 0x28ACA8C2, 0x078D19F3, 0xD2735440, 0x5AA7CDF8, 0x0FFE9816} } ;
		static const fp2_t var_expected =  { {0x2B381B1E, 0xD5711AFF, 0x8D7BF8E5, 0x09C891C3, 0x940BC5B2, 0xF19F2CD4, 0xEACEBF19, 0x16C0FBE3},
	{0xD54CEA63, 0x1DA2FB30, 0x05DC6EA2, 0xFA24CF80, 0x7F18BB31, 0x8087B791, 0xE7141DA9, 0x10505797} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1019 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1020 a1");
	}
	{
		static const fp2_t var_a =  { {0x7FA00A73, 0xD86529F4, 0x0E55C3D4, 0x0A5842CC, 0x0D5E2C45, 0xB2CBEBDE, 0xF1FC3594, 0x15CBD578},
	{0x6D11AC0A, 0x0CBB8515, 0xCB5A382B, 0x9EFFD27E, 0x7ED2E205, 0xFE6C75BE, 0xA79D4759, 0x0BF5FA86} } ;
		static const fp2_t var_expected =  { {0x83652CAE, 0xC337C3D0, 0x9459206A, 0xEBD107A4, 0x0B706841, 0x171FAD93, 0x0C065147, 0x00E240FF},
	{0x98C1F4D5, 0xD1BEABFC, 0x3DDCC6E0, 0xBD402393, 0xA9B35520, 0xB46B858D, 0x3F5378D7, 0x1E923BCE} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1021 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1022 a1");
	}
	{
		static const fp2_t var_a =  { {0xBE80751A, 0xECED8615, 0xFD0F3EF5, 0x47A3E603, 0xB357FF80, 0x775AF326, 0x866D7116, 0x1D55A3E2},
	{0xC27FD4D8, 0x71DA310A, 0x9A4D012B, 0x8EB6CD2A, 0xD3DE2BD5, 0x689EA196, 0x8A7400C5, 0x108A2BE4} } ;
		static const fp2_t var_expected =  { {0xC4F28CB8, 0xE9E6D82A, 0x8D3659E4, 0xCB6FF9E1, 0xD816DBFB, 0x4BF90CAC, 0x2A160CDC, 0x174C04A9},
	{0xE3009A72, 0xDBC42C8C, 0x9E30C53B, 0x76E989FC, 0xAB84D12A, 0x57DACF6C, 0xF5CBE342, 0x094D5F7A} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1023 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1024 a1");
	}
	{
		static const fp2_t var_a =  { {0x0951C2FB, 0x53194226, 0x599A6BB2, 0xF36F1AAC, 0x81FB7C70, 0xB54B53EE, 0xFC7AED09, 0x1847B7BC},
	{0xAA2EFD6C, 0xB11E617D, 0xCDF81D4F, 0xD93C7E5A, 0x9580BD84, 0x76D5869F, 0xDF261580, 0x0120D372} } ;
		static const fp2_t var_expected =  { {0xBD2470F0, 0xA81048B4, 0xFB43B196, 0xF5618DD9, 0x69DCFAC4, 0x9A7203ED, 0x6DDE349B, 0x123DB6C3},
	{0x910BADBD, 0xF8064E9C, 0xA5070A94, 0x64160550, 0x632C08AD, 0x18B34211, 0x4C25486E, 0x125A2416} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1025 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1026 a1");
	}
	{
		static const fp2_t var_a =  { {0x7F6C2D75, 0xEB41B5E1, 0xDF1E340E, 0x4224889E, 0xBD8D5A2D, 0x42691286, 0xC80D8B20, 0x01601E7E},
	{0x45094760, 0xED06489D, 0x49B21448, 0x3095DD30, 0x2FF33292, 0xBB8F7BD8, 0xF256AE31, 0x1929F00E} } ;
		static const fp2_t var_expected =  { {0x739A7270, 0x0ED33C6E, 0xD9FBCCEB, 0x1E7B1478, 0xC754635D, 0x5761A1E9, 0x7A5E54EF, 0x0DDDA90E},
	{0x5D5B1560, 0x73329B84, 0x183392EF, 0x4FD158C2, 0x947BBA6D, 0x12052678, 0xFA153C00, 0x1CE36D22} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1027 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1028 a1");
	}
	{
		static const fp2_t var_a =  { {0xD92A3AE7, 0xAD845A81, 0xF507C4C2, 0xE23DC0AC, 0x69DE5F4F, 0x8014DAD5, 0x84873B0C, 0x0CE88BD2},
	{0x3DF00E88, 0xFA2115F2, 0x26D3168A, 0x2DD8EAE9, 0x8653B4B0, 0x8BCA2FE9, 0xB5B37DBA, 0x1A6B6FDE} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1029 ");
	}
	{
		static const fp2_t var_a =  { {0x40A7C0B3, 0xEC89C4E1, 0x4E5C0F89, 0xD7D2DF89, 0x50E6883F, 0xEF6840AD, 0xCE0B6350, 0x1AFD1137},
	{0x0FA0288E, 0x675A4634, 0xD0DA998D, 0x78130DAB, 0x8CF89BDC, 0xC05C2BAF, 0x8A6CE5CD, 0x2048045D} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1030 ");
	}
	{
		static const fp2_t var_a =  { {0x5D67FAF9, 0xB27030D2, 0x75DCA233, 0x7A08D60B, 0xBBB54D9B, 0x28DC41CF, 0x8FC1C6AC, 0x0C8AF546},
	{0x4770B58F, 0x17670FB2, 0xE6F9CAB0, 0x4AC343E7, 0x045715C8, 0xCA3BE16D, 0x5A1C2179, 0x11B6DEDD} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1031 ");
	}
	{
		static const fp2_t var_a =  { {0xBDD0BBF5, 0x1CD9EE77, 0x8996DFD2, 0x30E34555, 0xF5F8CF5B, 0x1D6664E2, 0x0DE5B318, 0x227319A5},
	{0x73A89B1F, 0x89E7FC44, 0x490C31AC, 0xDFD96E9C, 0xF8C93ED9, 0x25389643, 0xA1A8B15B, 0x1E049027} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1032 ");
	}
	{
		static const fp2_t var_a =  { {0xF8F1A67B, 0x152742C1, 0xC94528C7, 0xA339D12C, 0xE1288ED4, 0xAC5AD130, 0xFF3BEB2A, 0x0D75A338},
	{0x9EC3CA14, 0x7197F2C9, 0x2E47525A, 0xE7CD9D1F, 0xABEDA036, 0x960AE04A, 0xE9EAD5AD, 0x17B8738B} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1033 ");
	}
	{
		static const fp2_t var_a =  { {0xC2E31661, 0x50C883E9, 0xD5E6853C, 0xA3D88447, 0xA6CDA655, 0x31EE460A, 0x4DE73BA6, 0x0210AEB6},
	{0x82F371F9, 0xA2333E83, 0x5C6957BD, 0xC6FC861A, 0xB7630DA1, 0xD7E1C1C2, 0xFABF3784, 0x0DBE3C21} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1034 ");
	}
	{
		static const fp2_t var_a =  { {0x26F5D8A9, 0x13EEF63E, 0xDE48351D, 0x7896EBF8, 0x56C7C521, 0xF400F84A, 0x5B65E88E, 0x1A6A3478},
	{0xB1B980D2, 0xEA93AFDF, 0xA7434266, 0x5D20EA4D, 0x6FB5D500, 0xAA946631, 0xBAD9FA69, 0x1608E13B} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1035 ");
	}
	{
		static const fp2_t var_a =  { {0xB7294BE7, 0x5FE6F3F0, 0xC171E3DF, 0x007D7CCD, 0xEF80DA43, 0x5DAFB1B3, 0x6707C2B4, 0x08B697EB},
	{0x1773B885, 0xD289AD39, 0xD9A852FC, 0x20D00651, 0xE84525E5, 0xC26EBACE, 0x5869DDBF, 0x09E27C1D} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1036 ");
	}
	{
		static const fp2_t var_a =  { {0x27926C0F, 0x0D7B67AF, 0xFFFD724C, 0x55342596, 0x91338445, 0xC8BFF47A, 0x86DCEA1D, 0x0DF4C09F},
	{0x50251039, 0xD99804E4, 0xF699B902, 0xE4404108, 0x6CFDE14F, 0x9E039DA2, 0xE95AF5BD, 0x169C7AF7} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1037 ");
	}
	{
		static const fp2_t var_a =  { {0x1F0DB1F0, 0x0A719AF8, 0x55283998, 0x5BAE4897, 0x8D00A6E7, 0x0C338D08, 0xDBA02DC7, 0x1B3054C2},
	{0x125AAE0B, 0x5AA5E6AA, 0x2E9A7637, 0x58C8EB12, 0x5D4AB185, 0x9CFEB954, 0xA96E1113, 0x00BB84CF} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1038 ");
	}
	{
		static const fp2_t var_a =  { {0x1ED63755, 0x892A118B, 0x7394A174, 0x5AEB115A, 0x8F585174, 0xCFE7B425, 0x8A6CE918, 0x0C534D7A},
	{0x62C38355, 0x7240BFD6, 0x589CDBF6, 0x74670272, 0x6B853846, 0x81A9155D, 0xA8387173, 0x0575DDA5} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1039 ");
	}
	{
		static const fp2_t var_a =  { {0x2799BF25, 0x66735BC1, 0xC825CBC7, 0x10B1CC43, 0xB4AD92EC, 0x47110692, 0xE1DDE628, 0x00756E19},
	{0xA7103CB8, 0x9221D269, 0x259E8A8A, 0xBE395292, 0x0DDCC42E, 0x808332B0, 0x54AD7BAE, 0x0C6974A2} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1040 ");
	}
	{
		static const fp2_t var_a =  { {0x0C2E3CE2, 0x080CAEE0, 0xE5E86406, 0xBB660C46, 0x8C895348, 0x72F6F33B, 0x1E51271B, 0x1E54E85B},
	{0xD26F7D71, 0x60AFB12E, 0xFBBECFBF, 0x7021436C, 0x87457677, 0xF42B8A2B, 0xD13E76FA, 0x239B37F8} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1041 ");
	}
	{
		static const fp2_t var_a =  { {0xCBA67AC6, 0x12998BC3, 0x4C42BC9D, 0xE89604D9, 0xFD525E27, 0x17D3C473, 0xEE19D8FD, 0x01B3092D},
	{0x39B4D363, 0xFB9A20A7, 0x2FC34D58, 0xF012F2F3, 0xECF17D93, 0xB88F536B, 0x0B426538, 0x0A790DCC} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1042 ");
	}
	{
		static const fp2_t var_a =  { {0xCEDC36CC, 0x22617CBA, 0x258C31E5, 0x80037E7B, 0x5DE3EC73, 0xDF83F2A7, 0x1162C8D5, 0x0B33E483},
	{0x8189E78D, 0xE4320B09, 0xD61311ED, 0x7D6F6618, 0xDEFE0673, 0x8B10622C, 0xAC9990B7, 0x0DCE4F01} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1043 ");
	}
	{
		static const fp2_t var_a =  { {0x2FA5E3B7, 0x0BAB03E2, 0xDEE9BA2F, 0xB68989D2, 0x52B476F4, 0xF6A2D189, 0x5635A506, 0x1A3FEECC},
	{0x77FB536B, 0x3FCC9A25, 0x31AD7547, 0xA9B02EC1, 0x6F514AD9, 0x182D07E6, 0x1F34F460, 0x136FFFA8} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1044 ");
	}

#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const fp2_t var_a =  { {0x2334B9D4, 0x00092311, 0xD6ABD0E6, 0x4F173780, 0x0C7A44DA},
	{0x8FCFDCC5, 0x5B469487, 0xB493A867, 0xD474BE3A, 0x137A4EA4} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 539 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 540 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 541 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 542 a1");
	}
	{
		static const fp2_t var_a =  { {0x20671C43, 0x0A5B5589, 0x4BE581E7, 0xC8381A68, 0x17238688},
	{0xC7943BAA, 0x815A1E41, 0x4BD886B1, 0x63EAB50E, 0x11CB9C9D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 543 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 544 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 545 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 546 a1");
	}
	{
		static const fp2_t var_a =  { {0x3508C87D, 0xD0F789A7, 0xA5EBFF27, 0x3C5C121F, 0x1956AF63},
	{0xF2C52E05, 0x7F830A48, 0x51F760CF, 0x8A7CAF6A, 0x0C7B970A} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 547 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 548 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 549 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 550 a1");
	}
	{
		static const fp2_t var_a =  { {0xE4F31891, 0x1A9D0D29, 0x667B4D74, 0xC083DC06, 0x1181CBE2},
	{0x6E766C5F, 0x59ECC395, 0xE4A7AF7B, 0xA013150E, 0x0C076A1D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 551 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 552 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 553 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 554 a1");
	}
	{
		static const fp2_t var_a =  { {0xAB957BE9, 0xEB61F12B, 0x5F799200, 0x93DEC4AC, 0x158D8615},
	{0x697DCAD6, 0xAA0144C4, 0xE2E21285, 0x106BDBE6, 0x025A0C07} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 555 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 556 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 557 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 558 a1");
	}
	{
		static const fp2_t var_a =  { {0x3251018C, 0x1CE650C4, 0x578DA362, 0x78883894, 0x16FE6401},
	{0xD646603E, 0x963D122B, 0xF6C03170, 0x92137B62, 0x2113575B} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 559 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 560 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 561 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 562 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9631831, 0x3693EA0B, 0xCB2A2C94, 0xE53713A9, 0x09D65A06},
	{0x7AED0459, 0x3AAF479F, 0x0013C602, 0x2AC6EA8B, 0x041CE34D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 563 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 564 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 565 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 566 a1");
	}
	{
		static const fp2_t var_a =  { {0xAD6CA4F7, 0xEEAAA853, 0xD5B146C6, 0xEA7F0B53, 0x08F36C33},
	{0x862E9DD5, 0x7EC7DB53, 0x32BCE4B9, 0x7C38393F, 0x15EF158A} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 567 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 568 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 569 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 570 a1");
	}
	{
		static const fp2_t var_a =  { {0x2CDCBC9F, 0x227EA663, 0xC47B5475, 0xB3BF104E, 0x0383A674},
	{0x3A18F87F, 0x668CBCFD, 0x5B98948C, 0x56BE4D91, 0x0F7A1DC0} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 571 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 572 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 573 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 574 a1");
	}
	{
		static const fp2_t var_a =  { {0x8DF30439, 0x9E35FA1A, 0xF2C7A617, 0x3E8CE283, 0x170DD5D9},
	{0xC334A2A0, 0x40DC455F, 0xF863C3DF, 0x1E6566CE, 0x0F07AC0D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 575 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 576 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 577 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 578 a1");
	}
	{
		static const fp2_t var_a =  { {0x44D7C941, 0x1733C355, 0xBB8BE0D5, 0x277FC445, 0x210EB265},
	{0xCF676665, 0x346E3013, 0x01C3268C, 0xCE03C86C, 0x1F7496DA} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 579 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 580 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 581 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 582 a1");
	}
	{
		static const fp2_t var_a =  { {0x8D3B1C04, 0x6321B097, 0xE91CC342, 0xD1429C11, 0x1B753426},
	{0x9C02FEE2, 0x279E1E4E, 0x11098345, 0x18AB2068, 0x1CA522F8} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 583 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 584 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 585 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 586 a1");
	}
	{
		static const fp2_t var_a =  { {0x3EB66822, 0x56B35FC2, 0x3A60C8CB, 0xE8E4BC78, 0x0A7A8ED7},
	{0x7E7F70AE, 0xFDDD7978, 0x58AF1C58, 0x5E9CF4DD, 0x0B4C447A} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 587 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 588 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 589 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 590 a1");
	}
	{
		static const fp2_t var_a =  { {0x3F19D236, 0xE3743EAF, 0x4A6BDF8C, 0xC6FFE17D, 0x130FC8E4},
	{0xD372DA73, 0xA3AD0202, 0x8FE5699C, 0xB56E842F, 0x09D805E9} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 591 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 592 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 593 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 594 a1");
	}
	{
		static const fp2_t var_a =  { {0x3BB1A263, 0x66D029F4, 0x5DD19FD1, 0x4A971588, 0x1F4F21DC},
	{0xC9CB42BD, 0xCA5E430A, 0x74123651, 0xBB8011D6, 0x14513987} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 595 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 596 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 597 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 598 a1");
	}
	{
		static const fp2_t var_a =  { {0xF5F61493, 0x72301C08, 0xAD9EEDDF, 0xE8815BCA, 0x11EE1962},
	{0x8FBA12C8, 0xFD650D32, 0xA2BD7B5F, 0x1E343C85, 0x23AA6623} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp[0], var_a[0], "fp2_clear 599 a0");
		assert_bi_equal(var_tmp[1], var_a[1], "fp2_clear 600 a1");
		fp2_clear(var_tmp);
		assert_bi_equal(var_expected[0], var_tmp[0], "fp2_clear 601 a0");
		assert_bi_equal(var_expected[1], var_tmp[1], "fp2_clear 602 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 603 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 604 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 605 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 606 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 607 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 608 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 609 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 610 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 611 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 612 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_b =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 613 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 614 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 615 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 616 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DE64504, 0x307C91EA, 0xD50798EA, 0x0C7E871B, 0x1A08D697},
	{0x85BB24EC, 0x8C030F11, 0x32EC0E20, 0x81A277DF, 0x1D6E74FB} } ;
		static const fp2_t var_b =  { {0x70DA8924, 0x8A878D30, 0xAF75265F, 0xC3765663, 0x1A29B9E4},
	{0x492C4D29, 0xF2CD057B, 0x5F569FA3, 0x7B4E9DCF, 0x16584E69} } ;
		static const fp2_t var_expected =  { {0xC2707BCD, 0x9CD6CA7A, 0x4B31FEAB, 0x209E8199, 0x10317078},
	{0x82971FBA, 0x60A2BFEC, 0x58F7ED26, 0x4D9AB9C8, 0x0FC5A361} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 617 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 618 a1");
	}
	{
		static const fp2_t var_a =  { {0xD48FD1E1, 0x57FECE21, 0xB6613C82, 0x9C2D5892, 0x04821469},
	{0x20C01358, 0x034E704D, 0x24D8F618, 0x3A49F123, 0x06BB6578} } ;
		static const fp2_t var_b =  { {0xBC75EA8C, 0x9D0467EF, 0x8E0E92BA, 0xE8AAA0B5, 0x0AB0B3BE},
	{0x735A5E7E, 0x5072B967, 0x24A1AE75, 0xA0D1D6E5, 0x12067030} } ;
		static const fp2_t var_expected =  { {0x9105BC6D, 0xF5033611, 0x446FCF3C, 0x84D7F948, 0x0F32C828},
	{0x941A71D6, 0x53C129B4, 0x497AA48D, 0xDB1BC808, 0x18C1D5A8} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 619 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 620 a1");
	}
	{
		static const fp2_t var_a =  { {0xFF9A7945, 0x772B0324, 0xBEF3FB03, 0xFAC5A99F, 0x21D21C81},
	{0x925AC1E8, 0x73675D2D, 0x17BEEEC0, 0xB8BC364C, 0x1F3DBE1F} } ;
		static const fp2_t var_b =  { {0x12F13727, 0x746BF3C2, 0x29C09F2E, 0x78B1FEF5, 0x0427E579},
	{0xB1A913F2, 0x7A733BA9, 0x03857864, 0xCF48681E, 0x05C027E4} } ;
		static const fp2_t var_expected =  { {0xC63B5E11, 0xCD69A246, 0xAF69D993, 0xC4214CAE, 0x01F8E1F7},
	{0xF7B3837F, 0xCFAD4436, 0xE1F9A686, 0xD8AE4283, 0x00FCC600} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 621 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 622 a1");
	}
	{
		static const fp2_t var_a =  { {0x065C9C11, 0x0774C2F2, 0x72C959DE, 0x4B0D6C45, 0x14251DED},
	{0xAB304D04, 0x98B37F72, 0x6A759D10, 0xA8FCA61B, 0x14DD4DE4} } ;
		static const fp2_t var_b =  { {0x3DC1817D, 0x26F07F0C, 0x99A4CC62, 0x1B599F08, 0x0D6BA5B0},
	{0x98F22FDB, 0xDBBB97BD, 0x15929447, 0x5A22C486, 0x1F9A057F} } ;
		static const fp2_t var_expected =  { {0x441E1D8E, 0x2E6541FE, 0x0C6E2640, 0x66670B4E, 0x2190C39D},
	{0xF7D22A84, 0x5641C28F, 0x46BD70BA, 0x53C90EBB, 0x10763360} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 623 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 624 a1");
	}
	{
		static const fp2_t var_a =  { {0xA763B918, 0x7A3DA6E5, 0x53575594, 0xF3EA0753, 0x16203E67},
	{0x5EA589FF, 0xDD066A4D, 0x873E0B6B, 0x23E818C0, 0x1FC582DB} } ;
		static const fp2_t var_b =  { {0xB5C2BC0E, 0x389A23F3, 0xC78478F3, 0xC1DE095E, 0x09D9EA3E},
	{0xF54FCEC4, 0xB5F87B4B, 0x87AB3199, 0xDCBEE3E7, 0x06537FAE} } ;
		static const fp2_t var_expected =  { {0x5D267526, 0xB2D7CAD9, 0x1ADBCE87, 0xB5C810B2, 0x1FFA28A6},
	{0x07A50668, 0x74D190F9, 0xD59E7C67, 0x5150A0C1, 0x0217E286} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 625 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 626 a1");
	}
	{
		static const fp2_t var_a =  { {0xA3797C97, 0xB2CA43E6, 0xF28053AE, 0x83809DB4, 0x16B3BEE2},
	{0x750B18CB, 0xAFC17235, 0x0E04DA5D, 0x5C6FECAB, 0x175D52E6} } ;
		static const fp2_t var_b =  { {0x0DFD3EC0, 0xBE9D0A9E, 0x9FF21EBC, 0xA593EB77, 0x1E9AB209},
	{0xD2B238EA, 0xF4D82020, 0x0E6FE78D, 0x487F91A6, 0x226074AD} } ;
		static const fp2_t var_expected =  { {0x652668FC, 0x5339F9E4, 0x5927B1CD, 0x79BE2D46, 0x114D50E8},
	{0xFB6CFF5A, 0x866C3DB5, 0xE32A014D, 0xF599226A, 0x15BCA78F} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 627 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 628 a1");
	}
	{
		static const fp2_t var_a =  { {0x1FB5105D, 0xC5F12F03, 0x417AFEBC, 0xEA11A261, 0x13A3A805},
	{0xE378A86E, 0x4F607AEE, 0x0E471FB7, 0x36423672, 0x03FAB48F} } ;
		static const fp2_t var_b =  { {0xDCD43773, 0x5269857C, 0x71C0D33D, 0xADF2D76F, 0x1F8FF431},
	{0x8E388053, 0xB1E57681, 0xA6B70525, 0x6CEC7EFA, 0x04C3EB85} } ;
		static const fp2_t var_expected =  { {0xB038F575, 0xFA2D5FDF, 0x79F1115B, 0xE8AE1DEA, 0x0F327C33},
	{0x71B128C1, 0x0145F170, 0xB4FE24DD, 0xA32EB56C, 0x08BEA014} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 629 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 630 a1");
	}
	{
		static const fp2_t var_a =  { {0xE6E8FDE6, 0xE7DFCC9C, 0x566CE3B0, 0x40F0D913, 0x028CEB0B},
	{0x82435640, 0xD670A419, 0x810436FB, 0x83D61908, 0x22184B69} } ;
		static const fp2_t var_b =  { {0xBB3D19AE, 0x3B0A67B9, 0x24572DAA, 0x2C518657, 0x104C6DD5},
	{0x6D1A9162, 0x76205EB9, 0x55261091, 0x132ADD82, 0x015FCFE2} } ;
		static const fp2_t var_expected =  { {0xA2261794, 0x22EA3456, 0x7AC4115B, 0x6D425F6A, 0x12D958E0},
	{0xEF5DE7A2, 0x4C9102D2, 0xD62A478D, 0x9700F68A, 0x23781B4B} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 631 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 632 a1");
	}
	{
		static const fp2_t var_a =  { {0x4A959052, 0x2521901D, 0xBC59D52A, 0x5295F940, 0x133D2310},
	{0xC4DEF3A3, 0x64938DFE, 0x3610C42C, 0x67818C2E, 0x0C3CA73F} } ;
		static const fp2_t var_b =  { {0x8F79AF54, 0x521EF597, 0xC1995E35, 0xE7D4B9A1, 0x0C86C3D2},
	{0x5ED1FF74, 0x251E8DE7, 0xCDBAB703, 0x89C9A324, 0x113B09DA} } ;
		static const fp2_t var_expected =  { {0xDA0F3FA6, 0x774085B4, 0x7DF3335F, 0x3A6AB2E2, 0x1FC3E6E3},
	{0x23B0F317, 0x89B21BE6, 0x03CB7B2F, 0xF14B2F53, 0x1D77B119} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 633 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 634 a1");
	}
	{
		static const fp2_t var_a =  { {0x2EAF94C6, 0x4993DFA5, 0x69908DE1, 0x4F3D0E63, 0x0A905C05},
	{0xE3923FAF, 0x5D2D2261, 0x88586A0E, 0xAF03CB17, 0x0AEF82FA} } ;
		static const fp2_t var_b =  { {0xEF665D35, 0x39CF699A, 0x1865A1C6, 0x3FCD1EDA, 0x1FD6FC31},
	{0x17D20CDC, 0x62EB1BC0, 0x30BCE7F2, 0x9050DBF0, 0x19A72D50} } ;
		static const fp2_t var_expected =  { {0xD1C59FA0, 0x6535F49F, 0x48AB6F09, 0xDFB3D157, 0x06663832},
	{0xAF13FA30, 0xA1EAE981, 0x7FCA9162, 0x8FFE4B21, 0x00959047} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 635 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 636 a1");
	}
	{
		static const fp2_t var_a =  { {0xC0794B4C, 0x088A6E54, 0x5E014A20, 0x4137624D, 0x1DB3A9B6},
	{0x49CDA5C5, 0xDA2349A8, 0x25109532, 0x2987E42D, 0x0E3EFC2F} } ;
		static const fp2_t var_b =  { {0x0077A897, 0xC79049A8, 0x965DF1B4, 0x5AEE4732, 0x1268F728},
	{0xC14B805F, 0x811A7949, 0x898D8F0C, 0x10A4AD4C, 0x0278C591} } ;
		static const fp2_t var_expected =  { {0x74A0A188, 0xB1ED635C, 0xBB147B36, 0xECCF4D99, 0x0C1B80DA},
	{0x0B192624, 0x5B3DC2F2, 0xAE9E243F, 0x3A2C9179, 0x10B7C1C0} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 637 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 638 a1");
	}
	{
		static const fp2_t var_a =  { {0xCDF8AD89, 0x8F0ACF90, 0xE2AF3A24, 0x34D9B203, 0x10556DBA},
	{0xEDD2528F, 0x1DA3C827, 0xCCF0A7CA, 0xF6C4BA4C, 0x0233F0E3} } ;
		static const fp2_t var_b =  { {0xFD2BC284, 0xC08E5C96, 0x662E066C, 0xF4089D6E, 0x03D054E1},
	{0xD6983F93, 0xF39A2932, 0xBAEAA754, 0x04B5865C, 0x0FEE98E1} } ;
		static const fp2_t var_expected =  { {0xCB24700D, 0x4F992C27, 0x48DD4091, 0x28E24F72, 0x1425C29C},
	{0xC46A9222, 0x113DF15A, 0x87DB4F1F, 0xFB7A40A9, 0x122289C4} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 639 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 640 a1");
	}
	{
		static const fp2_t var_a =  { {0xCCB52308, 0x6B18ECEB, 0x8BE29B5E, 0x7AD4507C, 0x07DD0A76},
	{0x614AD4D2, 0xD719673F, 0x759E8FE5, 0xA2664C49, 0x0743B62B} } ;
		static const fp2_t var_b =  { {0xB3BA89B7, 0x0CB9BE9C, 0xD97105BE, 0xAA5D9EE4, 0x18FC8CCD},
	{0x84A91486, 0x3A018544, 0x63ADCD8A, 0x73045D9D, 0x04B4ADEB} } ;
		static const fp2_t var_expected =  { {0x806FACBF, 0x77D2AB88, 0x6553A11C, 0x2531EF61, 0x20D99744},
	{0xE5F3E958, 0x111AEC83, 0xD94C5D70, 0x156AA9E6, 0x0BF86417} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 641 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 642 a1");
	}
	{
		static const fp2_t var_a =  { {0xC5DA93B0, 0xBDAC0664, 0xC8535B16, 0x08F12D39, 0x17B0A6AE},
	{0xFF087898, 0xB55D9345, 0x4A28F7EF, 0xD3F081CF, 0x0115966E} } ;
		static const fp2_t var_b =  { {0x2A6AC928, 0x95780B16, 0xC6437528, 0xFCE27558, 0x149D5701},
	{0x9F8CD84C, 0x69B2C182, 0x39CC5DC0, 0xE4417591, 0x13ED1E05} } ;
		static const fp2_t var_expected =  { {0xA3F50A7D, 0x34F6BCDA, 0x554C0FA1, 0x567D46AC, 0x084CDDAC},
	{0x9E9550E4, 0x1F1054C8, 0x83F555B0, 0xB831F760, 0x1502B474} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 643 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 644 a1");
	}
	{
		static const fp2_t var_a =  { {0xAD96C9FF, 0xDC3C2B5F, 0x3D8A8856, 0x9303BFE1, 0x0C35B23A},
	{0xA05F378F, 0x7BA0DF2D, 0x1FBA62B0, 0x1BEA77A5, 0x1C79A72B} } ;
		static const fp2_t var_b =  { {0x88723BA1, 0xF5A5826B, 0x9ED2EE6C, 0x76813FA3, 0x19BF46AD},
	{0x9468637C, 0x397EBCDD, 0xC08B2953, 0xCB6EB222, 0x18087071} } ;
		static const fp2_t var_expected =  { {0xE9B8B345, 0xB3B4592A, 0xA312B625, 0x5A2EA39E, 0x01F3D8E4},
	{0xE87748B0, 0x96F2476A, 0xA6FACB65, 0x3802CDE1, 0x1080F799} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 645 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 646 a1");
	}
	{
		static const fp2_t var_a =  { {0x758A2DCE, 0x869633B0, 0x59855DED, 0x5F171FA6, 0x220A62AF},
	{0x4E2BEF1E, 0xB3D1E512, 0x8988E9F5, 0x7FE2E9D3, 0x07BCD4BF} } ;
		static const fp2_t var_b =  { {0xBEB69236, 0x37567D73, 0x2C3AD4F3, 0xC12369A9, 0x14DDBCFB},
	{0xB7DA3076, 0x6CFD8565, 0x0345CA3E, 0xED06A03D, 0x09CF97E8} } ;
		static const fp2_t var_expected =  { {0xE7F06DA9, 0x9FBF5C83, 0x4C757242, 0x70E42D69, 0x12E6FFA7},
	{0x06061F94, 0x20CF6A78, 0x8CCEB434, 0x6CE98A10, 0x118C6CA8} } ;
		fp2_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_add 647 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_add 648 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 649 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 650 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 651 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 652 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 653 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 654 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 655 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 656 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 657 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 658 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_b =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 659 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 660 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 661 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 662 a1");
	}
	{
		static const fp2_t var_a =  { {0x382D479C, 0xFFC682AB, 0x217FD4AF, 0xB696F24D, 0x0B4F67BA},
	{0xF7837807, 0x080F4015, 0x1CFDB39B, 0x08721822, 0x14DAE52E} } ;
		static const fp2_t var_b =  { {0x7F6B184D, 0xA33A0339, 0x1BDEC888, 0x5E15CB2B, 0x1DABCE7B},
	{0x35E8CFCB, 0xC4782984, 0xAC16F5F6, 0xD7E2455A, 0x041CC390} } ;
		static const fp2_t var_expected =  { {0x051281AA, 0x7AB9D412, 0x3EEBCCC5, 0x07D78308, 0x11A4B943},
	{0xC19AA83C, 0x43971691, 0x70E6BDA4, 0x308FD2C7, 0x10BE219D} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 663 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 664 a1");
	}
	{
		static const fp2_t var_a =  { {0x7FCB67DA, 0x5781CB4D, 0xD9E7517B, 0x952F50F5, 0x04218FB2},
	{0x28BF006B, 0x1078C6D9, 0xF26B5BBA, 0xDFE6955D, 0x0C2BE683} } ;
		static const fp2_t var_b =  { {0x61791517, 0xA75C64F9, 0xEB1644E5, 0xE716823C, 0x21F2DC50},
	{0xD9090140, 0x42DDFA23, 0xB8E05F0A, 0x7C38AB78, 0x0F28F3B9} } ;
		static const fp2_t var_expected =  { {0x6AA2A51E, 0xCE52BAF4, 0x281BCD33, 0x5D6F2A9F, 0x062FD365},
	{0x9C065186, 0xEBC82155, 0x72D5BD4D, 0x130445CB, 0x210412CE} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 665 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 666 a1");
	}
	{
		static const fp2_t var_a =  { {0x2AADC547, 0x691C05B0, 0xF41E6F4D, 0x9533632F, 0x159F4C23},
	{0xB3829507, 0xC1325982, 0xC5D98783, 0x265711A3, 0x20420449} } ;
		static const fp2_t var_b =  { {0xA83B906B, 0x974929DE, 0x78D13DE2, 0x495DF1DC, 0x1DF5C7CE},
	{0x4B5AAE01, 0x2763A146, 0x2C4205DF, 0x686DB9D3, 0x1332C529} } ;
		static const fp2_t var_expected =  { {0xCEC28737, 0xF0003071, 0xB497F208, 0xFB2BCD39, 0x1BAAA458},
	{0x6827E706, 0x99CEB83C, 0x999781A4, 0xBDE957D0, 0x0D0F3F1F} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 667 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 668 a1");
	}
	{
		static const fp2_t var_a =  { {0xFD8A832D, 0xE721FA6F, 0x16290D80, 0x75B04799, 0x227506AA},
	{0xC8B0B97D, 0x86C3603B, 0x0E46B495, 0x6BF31518, 0x0C24A010} } ;
		static const fp2_t var_b =  { {0x0D40442E, 0x5FD60EAB, 0x4DEBF7E0, 0xC579FA2C, 0x1475C639},
	{0x5612006E, 0xB4DC75EF, 0x459F32CC, 0xE3F4D75E, 0x1C047EE8} } ;
		static const fp2_t var_expected =  { {0xF04A3EFF, 0x874BEBC4, 0xC83D15A0, 0xB0364D6C, 0x0DFF4070},
	{0xBEEF0B6A, 0xF0143EEC, 0x01F24266, 0x375499A0, 0x1421412B} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 669 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 670 a1");
	}
	{
		static const fp2_t var_a =  { {0xB17A179A, 0xBC1D3105, 0x84D3312E, 0x2C33224F, 0x1BBFC784},
	{0x627FCAD4, 0x39A63313, 0xE3836660, 0x9979B5CE, 0x17D612AB} } ;
		static const fp2_t var_b =  { {0xE4B89D56, 0x7FF82A99, 0xCB9B0F6B, 0x70EA62C0, 0x01F06DF5},
	{0x88BFE7E4, 0xA7159FFA, 0x0D2CC1AC, 0x5FBE8A99, 0x0D71E563} } ;
		static const fp2_t var_expected =  { {0xCCC17A44, 0x3C25066B, 0xB93821C3, 0xBB48BF8E, 0x19CF598E},
	{0xD9BFE2F0, 0x92909318, 0xD656A4B3, 0x39BB2B35, 0x0A642D48} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 671 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 672 a1");
	}
	{
		static const fp2_t var_a =  { {0x324EE11D, 0x08BAAF98, 0x8D1146EF, 0xA6235035, 0x202D7206},
	{0xF51C2CE2, 0x03B7920F, 0x9A44F9B3, 0x88E0C6D5, 0x18AE9471} } ;
		static const fp2_t var_b =  { {0x48544B79, 0x09697CF1, 0x241165B3, 0x8AD3B373, 0x1A05FBE9},
	{0x442E9EE9, 0x1C5A7E0D, 0xD790E1D7, 0xEE001CB8, 0x216992FC} } ;
		static const fp2_t var_expected =  { {0xE9FA95A4, 0xFF5132A6, 0x68FFE13B, 0x1B4F9CC2, 0x0627761D},
	{0xFD3DE054, 0x058A68A2, 0xFBFED87A, 0x4A370602, 0x1B462178} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 673 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 674 a1");
	}
	{
		static const fp2_t var_a =  { {0xC9544904, 0x1644747D, 0xA0D270ED, 0xE3C42E0F, 0x129A5DC5},
	{0xCDB91E58, 0x93C2D5BC, 0x88A221C9, 0xAF9043D9, 0x10D7A8E1} } ;
		static const fp2_t var_b =  { {0x0B8929F2, 0xC629DAA2, 0xC4C45797, 0x63B3F3CF, 0x07F46435},
	{0xE1699E94, 0x99EAA3E4, 0x4A7CAC61, 0x36805144, 0x1C818815} } ;
		static const fp2_t var_expected =  { {0xBDCB1F12, 0x501A99DB, 0xDC0E1955, 0x80103A3F, 0x0AA5F990},
	{0x389FD21F, 0x18058678, 0x77703606, 0x28664E7B, 0x185740D0} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 675 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 676 a1");
	}
	{
		static const fp2_t var_a =  { {0x8DB90FAE, 0xBA7438C7, 0x0CDD0435, 0x89BB63AC, 0x109BD7E2},
	{0x9F0B573B, 0x4E89A5B3, 0xE120A768, 0x34CEBE16, 0x03729593} } ;
		static const fp2_t var_b =  { {0x1B2F51B1, 0x676ABAEB, 0x53E340D6, 0xAA0AB96C, 0x17E14941},
	{0x1A565417, 0x39A99820, 0x7F9565D9, 0x4E19D792, 0x222CCA8C} } ;
		static const fp2_t var_expected =  { {0xBEDA1058, 0x7136D27C, 0xF24483FD, 0x8F070625, 0x1CBBAEA4},
	{0xD105557F, 0x330D6233, 0x9AD6022D, 0x960B426A, 0x0546EB0A} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 677 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 678 a1");
	}
	{
		static const fp2_t var_a =  { {0x721925FE, 0xE34B54D7, 0x9A3845D1, 0xCFAF626B, 0x15BFCBEC},
	{0x8591B680, 0xA3EBE094, 0x189DA9B1, 0xB3BBA89A, 0x0F94390D} } ;
		static const fp2_t var_b =  { {0x5C8A564A, 0x69200450, 0xABF59EB4, 0x3D89B030, 0x126CDE71},
	{0x4E3DBEFE, 0x9A184B25, 0x49BC7318, 0x5EB56431, 0x11777BEB} } ;
		static const fp2_t var_expected =  { {0x158ECFB4, 0x7A2B5087, 0xEE42A71D, 0x9225B23A, 0x0352ED7B},
	{0x83A449DD, 0x2800EA0F, 0x082BF737, 0x045CA04F, 0x221DDD26} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 679 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 680 a1");
	}
	{
		static const fp2_t var_a =  { {0x42DF72F0, 0x224CD822, 0x495BC9D3, 0xE019A53C, 0x213C2B39},
	{0x29CB639F, 0xBEB9FA3A, 0x0EEC32BE, 0x70ECA037, 0x22FB5AB0} } ;
		static const fp2_t var_b =  { {0x142FA8D8, 0x11B37405, 0x012EE0C9, 0x172454CB, 0x0A9557E3},
	{0x97FFE45C, 0x945F08B6, 0x388208F0, 0xE9665392, 0x05EC30C0} } ;
		static const fp2_t var_expected =  { {0x2EAFCA18, 0x1099641D, 0x482CE90A, 0xC8F55071, 0x16A6D356},
	{0x91CB7F43, 0x2A5AF183, 0xD66A29CE, 0x87864CA4, 0x1D0F29EF} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 681 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 682 a1");
	}
	{
		static const fp2_t var_a =  { {0x3128A7D9, 0xE6593D53, 0x8407CB46, 0xC113D4BD, 0x23AA2985},
	{0xA4A762EE, 0xC1E72D39, 0x3CBD6640, 0xF09E13C5, 0x18D3F677} } ;
		static const fp2_t var_b =  { {0x2E887AAA, 0x704EEB9D, 0x46C1594A, 0xAA0B1516, 0x19B02866},
	{0x4846B399, 0xD0B6560B, 0x5C37B1AE, 0x3E4F010F, 0x11362619} } ;
		static const fp2_t var_expected =  { {0x02A02D2F, 0x760A51B6, 0x3D4671FC, 0x1708BFA7, 0x09FA011F},
	{0x5C60AF55, 0xF130D72E, 0xE085B491, 0xB24F12B5, 0x079DD05E} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 683 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 684 a1");
	}
	{
		static const fp2_t var_a =  { {0x424EADA0, 0x2C598E94, 0x37355D84, 0x3C97C8B2, 0x0A7F792C},
	{0xDBF04F49, 0x3A52BD72, 0x696E0B11, 0x4C3B7A6A, 0x01A47207} } ;
		static const fp2_t var_b =  { {0x501B7980, 0xBA2601A2, 0x36D88801, 0xB1B0BFF9, 0x0FF6654F},
	{0x6065CC3D, 0x8954F5E2, 0xBB6BF625, 0x2245F8A2, 0x0F8E4B9A} } ;
		static const fp2_t var_expected =  { {0x3E83867B, 0x9060E192, 0x39A79620, 0x3A3D649F, 0x1E8A33E0},
	{0xC7DAD567, 0xCF2B1C30, 0xE74CD589, 0xD94BDDAD, 0x16174670} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 685 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 686 a1");
	}
	{
		static const fp2_t var_a =  { {0xF7E2D548, 0xF9142DD4, 0x861A5867, 0xD67772B2, 0x16371AEF},
	{0x3ABF222F, 0x9F5D38F6, 0x12D1D672, 0x44D066E3, 0x1486A27D} } ;
		static const fp2_t var_b =  { {0x5354A019, 0x79B3798D, 0xBE000D47, 0x892625E7, 0x206425DA},
	{0x498892D4, 0x79B25489, 0x2DF4E0A6, 0xB8746F79, 0x1CBB8FDD} } ;
		static const fp2_t var_expected =  { {0xF0DE878A, 0x9D8E08E7, 0x01650BBE, 0xFCA7A8B1, 0x19D41518},
	{0x3D86E1B6, 0x43D8390D, 0x1E27B66A, 0x3BB25350, 0x1BCC32A3} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 687 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 688 a1");
	}
	{
		static const fp2_t var_a =  { {0xCCD5EBC2, 0xF80B5284, 0x136F50BE, 0x6DD8C03B, 0x18AD4D2D},
	{0xA976AD61, 0xDF9369A1, 0x02DA9A41, 0x11A5C9D5, 0x08A7D4DB} } ;
		static const fp2_t var_b =  { {0x33D01827, 0xFABFD450, 0x0C0CED16, 0xA535BAB6, 0x04FE97BE},
	{0x0B5F14CE, 0x765A162F, 0xEF749DD1, 0x8EEE29DF, 0x11FD8334} } ;
		static const fp2_t var_expected =  { {0x9905D39B, 0xFD4B7E34, 0x076263A7, 0xC8A30585, 0x13AEB56E},
	{0xEA67EAEE, 0x8766A812, 0x4CB0BD0E, 0x320DFBDB, 0x1AAB71AA} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 689 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 690 a1");
	}
	{
		static const fp2_t var_a =  { {0x30FD0D55, 0x779E882C, 0xC6BDB1F5, 0xC12C469F, 0x1412BF70},
	{0x15300357, 0xB6C40145, 0xA41FC1E6, 0x73617F14, 0x12B351C0} } ;
		static const fp2_t var_b =  { {0x4FBBC369, 0x32DD5186, 0xEB6AC60F, 0xD2420F37, 0x1F54BFAA},
	{0xB787C216, 0x51309675, 0xE962C279, 0xC4CAA629, 0x0E658699} } ;
		static const fp2_t var_expected =  { {0x2D919C47, 0x62EE8B46, 0x149DAC84, 0x9E40934E, 0x18BF1FC9},
	{0x5DA84141, 0x65936ACF, 0xBABCFF6D, 0xAE96D8EA, 0x044DCB26} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 691 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 692 a1");
	}
	{
		static const fp2_t var_a =  { {0xF5A6ECE4, 0x40B9EF5B, 0xEE23076C, 0xDE7D6267, 0x1FF9E161},
	{0x5F2DD66C, 0x290826C8, 0xFCD726B4, 0x9C574098, 0x0B694490} } ;
		static const fp2_t var_b =  { {0xBD705285, 0x2694BF91, 0x0597350A, 0x58B7D110, 0x18AA8489},
	{0xC70D7A33, 0x71C8B292, 0x40DE6B0B, 0x94AA5938, 0x1929FAB6} } ;
		static const fp2_t var_expected =  { {0x38369A5F, 0x1A252FCA, 0xE88BD262, 0x85C59157, 0x074F5CD8},
	{0xE470AE94, 0xD56CC8D5, 0xF5437C46, 0xB7034346, 0x164069DD} } ;
		fp2_sub(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sub 693 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sub 694 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 695 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 696 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 697 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 698 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 699 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 700 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 701 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 702 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_b =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 703 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 704 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_b =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 705 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 706 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_b =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 707 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 708 a1");
	}
	{
		static const fp2_t var_a =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_b =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xD39B7F06, 0x59855F3B, 0xDDE9775A, 0x6946F968, 0x07F03FCC} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 709 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 710 a1");
	}
	{
		static const fp2_t var_a =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_b =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xD39B7F06, 0x59855F3B, 0xDDE9775A, 0x6946F968, 0x07F03FCC} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 711 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 712 a1");
	}
	{
		static const fp2_t var_a =  { {0xB916C7A4, 0xC050491C, 0x1C907977, 0x7A15FD78, 0x223F504C},
	{0x14564EEC, 0x9F87F47E, 0xAF7E43B5, 0x81C8B9EC, 0x0F9D1D21} } ;
		static const fp2_t var_b =  { {0xF0621B7F, 0x7A58A5D3, 0xCE8703AA, 0xCB82CCA3, 0x08B35DEF},
	{0x1EFBD8C6, 0x15DBEFEB, 0x8DB6A839, 0xA7EF323B, 0x0A3E342F} } ;
		static const fp2_t var_expected =  { {0x015F4FE8, 0x3C1861A1, 0xCF51348C, 0x2E9BA601, 0x2295DCE9},
	{0xBD102D82, 0xE3A84796, 0xA2B013CB, 0x1FCDA3BF, 0x1A8F6EDB} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 713 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 714 a1");
	}
	{
		static const fp2_t var_a =  { {0xB0C26F15, 0x46911FEB, 0x50C43FD2, 0xB1645921, 0x071886E2},
	{0x8CDA734B, 0xB10CAB26, 0x210DE44F, 0xA3E1BC82, 0x16569D14} } ;
		static const fp2_t var_b =  { {0xB64DA4F9, 0x4E766A01, 0x3C01CB68, 0xBF7B7A8F, 0x0C044ECE},
	{0x0E240727, 0x924151D3, 0xBC5F1F71, 0x82998E92, 0x0B732188} } ;
		static const fp2_t var_expected =  { {0x4823DBCA, 0x385E2EE8, 0x4BBCFF9E, 0xF0B3EF71, 0x215CEEDA},
	{0x4AB76005, 0x9D2DAB82, 0x455C56E0, 0x9AAF7324, 0x039BD884} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 715 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 716 a1");
	}
	{
		static const fp2_t var_a =  { {0x055F864B, 0x40780E1E, 0x3C0E76F3, 0x0E0DE2B1, 0x0AC1D861},
	{0xB7BC7B4E, 0xC9A94E41, 0x0BCEAE18, 0x87F512BC, 0x0DF630F3} } ;
		static const fp2_t var_b =  { {0x0429FE97, 0xAD72EC0E, 0xDFB00B53, 0x13F5A738, 0x12BBE44C},
	{0x4F5DDAE1, 0x6CC60852, 0x8AD9140C, 0xD02343A2, 0x1E9DC996} } ;
		static const fp2_t var_expected =  { {0x34013865, 0x7FBB61A3, 0x4A97C256, 0xE166E2FB, 0x0EE5BA75},
	{0x4D5547F7, 0x34A119A9, 0x60BEA6DE, 0x9DCFB2D6, 0x206EF4D2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 717 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 718 a1");
	}
	{
		static const fp2_t var_a =  { {0x47980A11, 0x0B07D4BC, 0xE4FF9FB6, 0x2D2BD2C9, 0x20A575F7},
	{0x0E9ED4EF, 0x5016E5AF, 0x387E6C45, 0x4A419128, 0x06DAB81F} } ;
		static const fp2_t var_b =  { {0x39AC86BB, 0x212F15DD, 0x510A0282, 0xE8BD9945, 0x1F2E44DD},
	{0x5B817490, 0xA47877DC, 0xB948E80D, 0x4567097C, 0x04205B25} } ;
		static const fp2_t var_expected =  { {0xBF488273, 0xDAFE839F, 0xB67A9C30, 0xA7B48B4A, 0x0AD0FF51},
	{0x3734F19E, 0xE1F76ED9, 0x12B6563E, 0x5700A9A1, 0x05A550ED} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 719 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 720 a1");
	}
	{
		static const fp2_t var_a =  { {0xD0E50217, 0x50B8E901, 0x1515A57F, 0xA18E4495, 0x08642C88},
	{0xAF1D8E20, 0x12147CE5, 0x27007159, 0xB958734F, 0x1E8FB9A8} } ;
		static const fp2_t var_b =  { {0x422D5951, 0xF6C69F8E, 0x261E8CD9, 0xF2C9B3C7, 0x12BD9FC7},
	{0x28FF08C4, 0x266F17C3, 0x83525A19, 0xA53EE684, 0x164A9588} } ;
		static const fp2_t var_expected =  { {0xFB5B012D, 0xF66FCFFA, 0x5A51F57B, 0x4171B28B, 0x09354880},
	{0xFAC26BCC, 0x99BE3A45, 0x67C8C915, 0xF2676748, 0x017CDD61} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 721 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 722 a1");
	}
	{
		static const fp2_t var_a =  { {0x43725705, 0xBE73F857, 0xCF7FCF73, 0xD9950B57, 0x183CC5C5},
	{0x4FB171D8, 0x3F38022F, 0x46021771, 0xA924D894, 0x1710C7D1} } ;
		static const fp2_t var_b =  { {0xFA5A1C8B, 0x1B3CA927, 0xAEC4A6C9, 0xAD90BC96, 0x220985FD},
	{0x3240ED37, 0x428D22DD, 0x3195E362, 0x95DE3851, 0x1E5DC7EF} } ;
		static const fp2_t var_expected =  { {0x21A56C54, 0x57E4FF2C, 0xCE59D0E6, 0x496F0B3D, 0x106BF46A},
	{0xF3EFA936, 0x5C06E4AA, 0xD8958F8E, 0xE3C95FEC, 0x02B4CD72} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 723 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 724 a1");
	}
	{
		static const fp2_t var_a =  { {0x230B6304, 0x340B4E5D, 0xA09EA6C1, 0xD99B503C, 0x02D6AFEE},
	{0x83421FF6, 0x18765A0A, 0xE6F9EDBC, 0x838107FB, 0x1AF09960} } ;
		static const fp2_t var_b =  { {0xDA1A06E1, 0x9989388F, 0xA99E3FE2, 0xC75EE479, 0x042D590C},
	{0xEED08B9B, 0x0F15FFAF, 0x61E89297, 0xDAF51E17, 0x0BB9E4C0} } ;
		static const fp2_t var_expected =  { {0x72DB8295, 0x1B3F4FC6, 0x107A0C67, 0x414C3722, 0x14EACDBE},
	{0x10837BAD, 0x3B9BE53A, 0x7F645D8F, 0x09AAC094, 0x01553D3C} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 725 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 726 a1");
	}
	{
		static const fp2_t var_a =  { {0xB380091E, 0xE089B8A9, 0x87AD8304, 0x8EADB911, 0x1BB30457},
	{0x59D2A9EC, 0xC47D757A, 0xA89D5208, 0xD6DEB146, 0x1C7B41CC} } ;
		static const fp2_t var_b =  { {0xFED2879F, 0x4949E919, 0xA342D115, 0x2CB289EA, 0x188454FE},
	{0xA3A4C12E, 0x868E3E29, 0xFB13C0BF, 0x0DE20487, 0x21300302} } ;
		static const fp2_t var_expected =  { {0xE744C67C, 0xA79BE5F7, 0x9C6813F3, 0x83C950F1, 0x2247B7DB},
	{0x686F506A, 0x6D319D92, 0x34DF69DE, 0x199974C2, 0x03DE3FC4} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 727 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 728 a1");
	}
	{
		static const fp2_t var_a =  { {0x21E18CF4, 0x96397C32, 0x72F9C2E0, 0x9FDABA6A, 0x0C6D8D3C},
	{0xD557B4BD, 0x5AD0F3CB, 0xCE4341A8, 0xC24FB81D, 0x0370DAF1} } ;
		static const fp2_t var_b =  { {0xB661449E, 0xC8C2E478, 0xA836E466, 0x948C558A, 0x0C8E5DD6},
	{0x0A06486D, 0x52C7E079, 0xB596D9D6, 0x47E5CC1A, 0x045E7C05} } ;
		static const fp2_t var_expected =  { {0xD6327D56, 0xBC7F86A0, 0x48629C73, 0x9E591BF8, 0x1D81F6F2},
	{0x159199FB, 0x6D9DBBAA, 0xF12E2697, 0xBBDF1BAE, 0x0FEEA250} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 729 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 730 a1");
	}
	{
		static const fp2_t var_a =  { {0x50BAC9AB, 0xF0F1E32C, 0x1FF2CEEE, 0x1775863E, 0x088D8429},
	{0x79A658B1, 0x596D5675, 0xF97C5335, 0x74F581FE, 0x0305CFC1} } ;
		static const fp2_t var_b =  { {0x593AE34E, 0x5A48C745, 0x38B5367F, 0x579C16E6, 0x0F0FBA93},
	{0x0E463FDA, 0x37306098, 0xA748930F, 0xEDCE6157, 0x114EED22} } ;
		static const fp2_t var_expected =  { {0x4565A1C0, 0x739474C5, 0xA2B81FFC, 0x2EEF1BC0, 0x0D9138F1},
	{0x3F3C1666, 0x7ED9B03E, 0x9012D8AC, 0x539F4C06, 0x1C2EE6D6} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 731 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 732 a1");
	}
	{
		static const fp2_t var_a =  { {0x7B6E73A4, 0x9D806F68, 0xEA8002C5, 0xAF270BEC, 0x01616244},
	{0xC35AA9BE, 0x90691609, 0xA2B962D8, 0x36DDD1C7, 0x0D584A14} } ;
		static const fp2_t var_b =  { {0x5951BE29, 0x2129B6E5, 0x8E5D6C52, 0x4ED4D6E1, 0x1B4D297F},
	{0xBE9D7221, 0x96BD9ABF, 0x5303570A, 0xBD90A08D, 0x1B4DE245} } ;
		static const fp2_t var_expected =  { {0x928239A0, 0x1952F01B, 0x028B91CC, 0xFD6A9AA5, 0x080B4924},
	{0xAA96B200, 0x17712D9E, 0xC4871730, 0x2E19D91C, 0x0F1D23F9} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 733 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 734 a1");
	}
	{
		static const fp2_t var_a =  { {0x46075407, 0x82731B68, 0x3C957E91, 0x3743F9E7, 0x08BFDA40},
	{0x748A391E, 0x60063000, 0xFFC12A2B, 0xC8B7BEBA, 0x20BCAFD5} } ;
		static const fp2_t var_b =  { {0xD9472D5F, 0xEF915EAB, 0x72DF93C9, 0x09E1C87D, 0x0004C4F9},
	{0x75C78C59, 0x408FB0EF, 0x37C1F042, 0x368989B4, 0x23ABFEE5} } ;
		static const fp2_t var_expected =  { {0xAA153ABC, 0x2924053D, 0x724C9000, 0x25E5434E, 0x08C6A913},
	{0x077A4652, 0x0C95F52A, 0x663116E3, 0x53827C0E, 0x0CCE5F31} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 735 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 736 a1");
	}
	{
		static const fp2_t var_a =  { {0xB2F29601, 0x8ED17650, 0x926172F3, 0x6C5FA66A, 0x068C172C},
	{0x36C87D4B, 0xE4D69850, 0x78EA3D73, 0x42AB02CC, 0x23B05C44} } ;
		static const fp2_t var_b =  { {0x719052AF, 0xD7815E34, 0xF16138C9, 0xDA87E0B1, 0x1DF7BFE8},
	{0x4A0C9D52, 0xF2258EDF, 0x91B76ADA, 0xDA161332, 0x0F653BB3} } ;
		static const fp2_t var_expected =  { {0xBB6B556A, 0x9D5B5C15, 0x2D41DB1C, 0x102F813C, 0x19405FFE},
	{0xEB701B81, 0xA6674752, 0xF8851C80, 0x209C8894, 0x1AA98C3B} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 737 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 738 a1");
	}
	{
		static const fp2_t var_a =  { {0xD7D40759, 0xC2D06AC8, 0x81E02DB6, 0x0FCC841B, 0x04B0C364},
	{0x954F031D, 0xCA7530B6, 0x8A31FC49, 0x5CAB3E2E, 0x03802C09} } ;
		static const fp2_t var_b =  { {0xE255E057, 0x5F79F29A, 0xA908C943, 0xA6088B5A, 0x0925748A},
	{0xACABAE63, 0x06EFDDB0, 0x16655A65, 0x373B9666, 0x17D1486D} } ;
		static const fp2_t var_expected =  { {0xFB038186, 0x877F8648, 0xF21D164F, 0x281596D2, 0x0A29CE94},
	{0x3C3C22E9, 0xC6E90C0A, 0x6BF02A72, 0x3E386DA6, 0x10E419E2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 739 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 740 a1");
	}
	{
		static const fp2_t var_a =  { {0x96DC6945, 0x3B87D42C, 0x85AB16A3, 0x2223445E, 0x1197BFCF},
	{0x11B32559, 0x429A7D44, 0x7B31E3AC, 0x9588E4D6, 0x024A89A8} } ;
		static const fp2_t var_b =  { {0xC29B84BF, 0xE8C219D3, 0x7C63DC58, 0x4AFD7029, 0x0B05DD0F},
	{0x414B12C5, 0xCE29FC29, 0xA3C95D65, 0x3AFAE1CC, 0x06B3CAB3} } ;
		static const fp2_t var_expected =  { {0x3AD9C60B, 0x0220526C, 0x5A24B700, 0xCB0B8625, 0x1D36C1FE},
	{0x855CC256, 0x3768C916, 0x0156442C, 0x41D3430A, 0x08DBE5A2} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 741 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 742 a1");
	}
	{
		static const fp2_t var_a =  { {0x7F9DDBCF, 0xB7BD426C, 0xD0E4E276, 0xB3AF2EB3, 0x22A7BBBB},
	{0xFC8624B7, 0x0F36A705, 0x0C454648, 0x8318215B, 0x1EE3D393} } ;
		static const fp2_t var_b =  { {0x9A12196C, 0x8E5FF71C, 0x05959C2B, 0x475CD4FD, 0x0D295254},
	{0xF3503B51, 0x5B316605, 0x31BFCEB2, 0x1EAC80DD, 0x221E6B69} } ;
		static const fp2_t var_expected =  { {0xBE25C107, 0x27F7FE4F, 0x959B2BE7, 0x70AC4A4F, 0x036E0691},
	{0x88EC8314, 0x55C37AF4, 0x999A1A82, 0x9D3B3643, 0x0510AC41} } ;
		fp2_mul(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_mul 743 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_mul 744 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 745 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 746 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 747 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 748 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_expected =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 749 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 750 a1");
	}
	{
		static const fp2_t var_a =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 751 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 752 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x78B4D355, 0xC4A7F564, 0x5B614943, 0x460F627D, 0x1C10E037} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 753 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 754 a1");
	}
	{
		static const fp2_t var_a =  { {0x3DC5DF31, 0xED3C687F, 0xAD4D9745, 0xE88BBFB9, 0x1F3AB817},
	{0x94FA7E3D, 0xE8BF6F2A, 0x10EB308B, 0xFE5EFDFA, 0x11CB0096} } ;
		static const fp2_t var_expected =  { {0x90EF472F, 0x5542006F, 0x9B047854, 0x074C6395, 0x08BC555B},
	{0x18D0C129, 0xE60A47EA, 0x24974300, 0x96DDDC1B, 0x22F2E0C3} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 755 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 756 a1");
	}
	{
		static const fp2_t var_a =  { {0xC0F16D7C, 0x7681A236, 0x294D7FA1, 0x1116E392, 0x04CE5F4F},
	{0x322CF870, 0x343D81F0, 0xC1AF53A6, 0x7DEC26C8, 0x22FD40A6} } ;
		static const fp2_t var_expected =  { {0xA60167A3, 0x63C7D13B, 0x652F7A0E, 0xFB8CE2FB, 0x06D93EDF},
	{0x1B89BBFE, 0xA164EDE8, 0x4BCFC582, 0xCA6D2803, 0x159D6CB6} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 757 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 758 a1");
	}
	{
		static const fp2_t var_a =  { {0x883E38A3, 0x2C4BB80A, 0x2FCE6D53, 0x25BC5CB5, 0x061CCCAF},
	{0x7B4C3FFD, 0xF4F13BED, 0xD06F60DC, 0xC19C45F8, 0x0E7A350D} } ;
		static const fp2_t var_expected =  { {0xD0176049, 0x6EB91FFB, 0xE1C1CFAB, 0x96562FC7, 0x001ACBC1},
	{0x5105BBFE, 0xFA0BE14B, 0x814DEF0D, 0xC25DAEDF, 0x0DC56793} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 759 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 760 a1");
	}
	{
		static const fp2_t var_a =  { {0xFE5BFD07, 0x741990E1, 0x64DC8313, 0x2A77CD8C, 0x10F083E4},
	{0xAC8AF17F, 0xAA747ABB, 0x64749F46, 0xE0A245B8, 0x13CD2D57} } ;
		static const fp2_t var_expected =  { {0xDE5D9205, 0xD0D1001A, 0x334AB31A, 0x4B4A5714, 0x154730F3},
	{0xBE780648, 0x8D2ECDE8, 0x810B76DD, 0x394C4E01, 0x04349FCB} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 761 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 762 a1");
	}
	{
		static const fp2_t var_a =  { {0x34AA93E0, 0xFF2B0950, 0xDD158F72, 0x14CA1193, 0x10AA92AB},
	{0xDAC74B43, 0x663636F4, 0x172D0759, 0xDC85BFAA, 0x21D4082F} } ;
		static const fp2_t var_expected =  { {0xF469DD8F, 0x8DB24ACC, 0x379AC166, 0x3D72DA68, 0x00DB1274},
	{0xD4566494, 0x18C36E91, 0x575B93C6, 0xB491A72F, 0x1DAE65D1} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 763 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 764 a1");
	}
	{
		static const fp2_t var_a =  { {0xE95001D0, 0x17C82EB6, 0xF85D537D, 0xA6514B34, 0x20C29A94},
	{0x160FB171, 0x3B2D642B, 0x9DF37644, 0x16F3399C, 0x06669830} } ;
		static const fp2_t var_expected =  { {0x2C29FEB2, 0x5F20EA86, 0xE0996450, 0x221FD08E, 0x099A850E},
	{0x54E22503, 0x4D2F81D7, 0xF667FC6B, 0x2436E692, 0x1FE62F7F} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 765 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 766 a1");
	}
	{
		static const fp2_t var_a =  { {0x2D51F68D, 0x66A0F05D, 0x504D784E, 0x1245A54C, 0x03E79118},
	{0x385DE92D, 0xD8FEC8BB, 0xE76D46E1, 0xB187D896, 0x06FD000E} } ;
		static const fp2_t var_expected =  { {0x5A8E4F0A, 0x2E62EE1A, 0xDB78D455, 0x24130A87, 0x177D4F58},
	{0x1D5DABCC, 0x7F38EDE9, 0xCF805DC6, 0x75084471, 0x2074BEC8} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 767 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 768 a1");
	}
	{
		static const fp2_t var_a =  { {0x35E3943E, 0x3EB02707, 0xE761C1B0, 0x6995132B, 0x10048B52},
	{0x633A2767, 0xF6CF9EA6, 0x6A8718F2, 0x5B6B2A36, 0x18FEA68A} } ;
		static const fp2_t var_expected =  { {0xD8830419, 0x9CB7FCC7, 0x0002F42D, 0x2D5E1F01, 0x1FA2A1BB},
	{0x7C34DB45, 0x06C7D5D8, 0x573E25F8, 0x2AD4130C, 0x17BBC04D} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 769 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 770 a1");
	}
	{
		static const fp2_t var_a =  { {0x3F6003D7, 0x46CAE589, 0x45698665, 0x6482D9E6, 0x07BAD6FA},
	{0xC681154E, 0xB2047954, 0xAE987FB1, 0x03BB9598, 0x0A152CDE} } ;
		static const fp2_t var_expected =  { {0x5D64D97C, 0x50640029, 0xCAA1F8DC, 0xF7E3BDB9, 0x1EF91073},
	{0x120D9FBB, 0x5DD29058, 0x5CA3F117, 0x0775FC88, 0x1A889827} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 771 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 772 a1");
	}
	{
		static const fp2_t var_a =  { {0x1883ED5B, 0xF9DA0814, 0xC9C6216A, 0x5D1D6F10, 0x0519A5EE},
	{0xE73FFDF2, 0x58E54FAE, 0x02F97CD1, 0x8703EC8A, 0x0A40C980} } ;
		static const fp2_t var_expected =  { {0x32C161C1, 0x670FB2EC, 0x14153EC0, 0x9356702A, 0x1A5202BB},
	{0x150CB886, 0xB5A8630B, 0x962B7E87, 0xFC07DE1A, 0x1CC5A846} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 773 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 774 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C3AC7F6, 0xA333E2EC, 0xC74CE13F, 0x45CB1825, 0x146E1F18},
	{0x60D53E2F, 0xE0AE1BE7, 0xCB5955FF, 0xF5D09053, 0x020C5D8F} } ;
		static const fp2_t var_expected =  { {0x0666E7D4, 0x9BA9455D, 0xB0B969AD, 0x338512E3, 0x0B53B1D2},
	{0xDFC2AC0B, 0xF7434A7E, 0x31C16AD5, 0x5A09B56A, 0x010C0C26} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 775 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 776 a1");
	}
	{
		static const fp2_t var_a =  { {0xA6104576, 0x1416171C, 0xFC29537D, 0xF78F81E3, 0x05ED5ACE},
	{0xF123CC93, 0xF2B3FBB1, 0x115FB378, 0xFC548F2B, 0x11F86F9C} } ;
		static const fp2_t var_expected =  { {0xFD39321E, 0x410A9E83, 0x7921E5BD, 0xF542117A, 0x2383F13F},
	{0xD5E27C24, 0x92D00E0E, 0x68BA778D, 0x3A1A5F3C, 0x0260D9E7} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 777 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 778 a1");
	}
	{
		static const fp2_t var_a =  { {0x09FFE9D9, 0x21F2188E, 0xEC12B435, 0xF1D5E8C9, 0x07FE4477},
	{0x61904754, 0xE69B85CE, 0x2D593A43, 0xF730C5B0, 0x20DEF497} } ;
		static const fp2_t var_expected =  { {0x15CF9868, 0x7034B650, 0x0C2A0F81, 0x78962BEE, 0x0A67B6E4},
	{0xDF72CD46, 0x0DF56C05, 0xDDD4CDD9, 0x48E9AF6A, 0x1FAA2B57} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 779 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 780 a1");
	}
	{
		static const fp2_t var_a =  { {0x4FCB84FD, 0xFF9A3832, 0x1BB6C64E, 0x921690E6, 0x1A2B2FAB},
	{0xEB35535F, 0xA83EC218, 0xE562E721, 0xEE76847F, 0x0D0B698D} } ;
		static const fp2_t var_expected =  { {0xBAE6869B, 0x95489493, 0xD68AA4E6, 0x95836C0A, 0x10CF7556},
	{0x342B1517, 0x3FB39C61, 0x2921DD12, 0xA90B9FEF, 0x07D341F5} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 781 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 782 a1");
	}
	{
		static const fp2_t var_a =  { {0x59CF0E25, 0x3BD1ABAC, 0x7E0BE1A1, 0xC78B9E24, 0x105CE399},
	{0x964E7BE4, 0xC164FE9C, 0xBED937F2, 0xFA62E5C7, 0x003AF9F2} } ;
		static const fp2_t var_expected =  { {0x3B32BB25, 0x63C41C93, 0x5AE19A6F, 0x8D76DAE8, 0x110BD900},
	{0xD0BC35ED, 0x70D3FDFE, 0x4BEDF38F, 0x1A961FCF, 0x11EF1913} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 783 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 784 a1");
	}
	{
		static const fp2_t var_a =  { {0x153B7804, 0x47F38FE5, 0xF790A484, 0x231FE36E, 0x02B02431},
	{0xD1DA2E97, 0x31A90D89, 0x3424FDFA, 0xB285EAC4, 0x18999886} } ;
		static const fp2_t var_expected =  { {0xFB868AE3, 0xAF3F2FDC, 0x795CED66, 0xB3E87E80, 0x040251BB},
	{0xB27691E1, 0x8B913EBB, 0xEF4B1CEF, 0x5A8EFDE4, 0x0C8966FA} } ;
		fp2_sqr(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqr 785 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqr 786 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 787 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 788 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x2628292E, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 789 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 790 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x2628292E, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 791 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 792 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x2628292D, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 793 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 794 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x2628292E, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001},
	{0x2628292D, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 795 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 796 a1");
	}
	{
		static const fp2_t var_a =  { {0x94433B85, 0x7EED03E9, 0x20CB03B2, 0xA3ACFF2C, 0x10CB6121},
	{0x77946521, 0x79447F9C, 0x55D1B2D3, 0x94EB23E5, 0x08CE880F} } ;
		static const fp2_t var_expected =  { {0xF049C6F0, 0x4E8D2C44, 0x2D0AE228, 0xA981AD89, 0x1A664092},
	{0x61F25BBE, 0xCBB8EA1E, 0xC78E39B8, 0xA220BFE5, 0x1667D409} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 797 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 798 a1");
	}
	{
		static const fp2_t var_a =  { {0x343DC2CB, 0x52A31ECC, 0xB9B82DB6, 0xC132E127, 0x119BC32D},
	{0xF2C918EC, 0x34A799FE, 0x4895BF54, 0xBCF28A08, 0x1ECB8B67} } ;
		static const fp2_t var_expected =  { {0x40470A93, 0x386839B6, 0xF981772A, 0xB8449E86, 0x1ACE7198},
	{0x79648C76, 0x1A53CCFF, 0x244ADFAA, 0xDE794504, 0x0F65C5B3} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 799 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 800 a1");
	}
	{
		static const fp2_t var_a =  { {0x542B46F4, 0x2DD591EC, 0xCB67A6D4, 0xE1740411, 0x0A52F0AE},
	{0x6F27A24E, 0xC28EEC9E, 0x986D9752, 0x3E663DC9, 0x12E277C3} } ;
		static const fp2_t var_expected =  { {0x2A15A37A, 0x16EAC8F6, 0xE5B3D36A, 0x70BA0208, 0x05297857},
	{0x3793D127, 0x6147764F, 0xCC36CBA9, 0x9F331EE4, 0x09713BE1} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 801 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 802 a1");
	}
	{
		static const fp2_t var_a =  { {0x97467370, 0xE6BC7A33, 0xA6B68A44, 0x2EC7380C, 0x1044C011},
	{0xDCC5E503, 0xCED8AE53, 0x8B4F6676, 0x9A445EF1, 0x205A940E} } ;
		static const fp2_t var_expected =  { {0xCBA339B8, 0x735E3D19, 0x535B4522, 0x97639C06, 0x08226008},
	{0x148B1BAF, 0x7683017A, 0xE24D138A, 0x24CD5D6B, 0x222DDA09} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 803 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 804 a1");
	}
	{
		static const fp2_t var_a =  { {0x944A6E77, 0x51354FF1, 0x5BA0CD6D, 0x2A3A4816, 0x11E14B71},
	{0x64EDDC74, 0xC9805A84, 0x1F0562D6, 0x154B3B01, 0x02666559} } ;
		static const fp2_t var_expected =  { {0xF04D6069, 0xB7B15248, 0x4A75C705, 0x6CC851FE, 0x1AF135BA},
	{0x3276EE3A, 0x64C02D42, 0x8F82B16B, 0x8AA59D80, 0x013332AC} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 805 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 806 a1");
	}
	{
		static const fp2_t var_a =  { {0x14B68BFB, 0x7F2A451B, 0x868A0C5C, 0x361669FB, 0x04ED3082},
	{0x97D0BF8D, 0x3CC407F0, 0x172C2515, 0x741670F7, 0x0E90E1EA} } ;
		static const fp2_t var_expected =  { {0xB0836F2B, 0x4EABCCDD, 0xDFEA667D, 0xF2B662F0, 0x14772842},
	{0x721088F4, 0xAD78AE48, 0xA83B72D9, 0x11B6666E, 0x194900F7} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 807 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 808 a1");
	}
	{
		static const fp2_t var_a =  { {0xE1CC855C, 0xDE00B26D, 0x1900BBB4, 0xBF45A4D0, 0x03399030},
	{0xCDB19422, 0x9229F30C, 0x895DA965, 0x6DAE8831, 0x1760E41A} } ;
		static const fp2_t var_expected =  { {0xF0E642AE, 0x6F005936, 0x0C805DDA, 0x5FA2D268, 0x019CC818},
	{0x66D8CA11, 0xC914F986, 0xC4AED4B2, 0x36D74418, 0x0BB0720D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 809 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 810 a1");
	}
	{
		static const fp2_t var_a =  { {0x96514AAE, 0x9456028D, 0x45AAC51B, 0x83903223, 0x065E2A88},
	{0xC5EB9E12, 0x22E0C3F9, 0x5FF6CE71, 0xA5B261A8, 0x076198C2} } ;
		static const fp2_t var_expected =  { {0xCB28A557, 0xCA2B0146, 0xA2D5628D, 0x41C81911, 0x032F1544},
	{0xE2F5CF09, 0x917061FC, 0x2FFB6738, 0x52D930D4, 0x03B0CC61} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 811 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 812 a1");
	}
	{
		static const fp2_t var_a =  { {0x3BAE7B4B, 0x8D8ED8A6, 0xD89AB231, 0x2E8C937B, 0x123A23F6},
	{0xDDF3588C, 0x667BD1CC, 0x72238703, 0x1842E2F6, 0x0E578EC0} } ;
		static const fp2_t var_expected =  { {0x43FF66D3, 0xD5DE16A3, 0x08F2B967, 0xEEF177B1, 0x1B1DA1FC},
	{0x6EF9AC46, 0xB33DE8E6, 0x3911C381, 0x0C21717B, 0x072BC760} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 813 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 814 a1");
	}
	{
		static const fp2_t var_a =  { {0x0E9F89DC, 0xC3D7C087, 0xCB14376D, 0x1577C5A0, 0x01B4F403},
	{0x49B9E7D5, 0x1B90CC0A, 0xF5CF92BE, 0xE7501ED0, 0x0B9D8479} } ;
		static const fp2_t var_expected =  { {0x874FC4EE, 0xE1EBE043, 0x658A1BB6, 0x8ABBE2D0, 0x00DA7A01},
	{0x4B051D18, 0x1CDF1055, 0x978D29AE, 0xCB533D5B, 0x17CF523E} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 815 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 816 a1");
	}
	{
		static const fp2_t var_a =  { {0x358B7C43, 0xE33DF6E1, 0xBF0969E6, 0xD653E7FD, 0x116546AC},
	{0xE90F53C2, 0x626C9D1E, 0xA0036300, 0x4718006C, 0x07C93C1B} } ;
		static const fp2_t var_expected =  { {0xC0EDE74F, 0x80B5A5C0, 0xFC2A1542, 0x42D521F1, 0x1AB33358},
	{0x7487A9E1, 0x31364E8F, 0x5001B180, 0xA38C0036, 0x03E49E0D} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 817 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 818 a1");
	}
	{
		static const fp2_t var_a =  { {0x4E66B4FF, 0x37634ECA, 0x61CACB9D, 0x63282566, 0x0FD033B1},
	{0x532A6684, 0x9AC33397, 0x2C117B10, 0x192DBE28, 0x1CE3FC54} } ;
		static const fp2_t var_expected =  { {0x4D5B83AD, 0xAAC851B5, 0x4D8AC61D, 0x893F40A6, 0x19E8A9DA},
	{0xA9953342, 0x4D6199CB, 0x1608BD88, 0x0C96DF14, 0x0E71FE2A} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 819 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 820 a1");
	}
	{
		static const fp2_t var_a =  { {0x20910D5B, 0xD0438A73, 0x2EA89BFC, 0xFED4E6A6, 0x146BE483},
	{0x23010B3F, 0x822DF52B, 0x7F5C5EEE, 0x5D35F786, 0x09C0D792} } ;
		static const fp2_t var_expected =  { {0xB670AFDB, 0x77386F89, 0x33F9AE4D, 0xD715A146, 0x1C368243},
	{0xB7A8AECD, 0x502DA4E5, 0x5C538FC6, 0x064629B6, 0x16E0FBCB} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 821 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 822 a1");
	}
	{
		static const fp2_t var_a =  { {0xDD937C03, 0x6D7AA89F, 0x19F00852, 0x4B11D5CC, 0x117A30EA},
	{0x201D73B3, 0x33F67D67, 0x6666B043, 0x3E6A61E6, 0x18D9F768} } ;
		static const fp2_t var_expected =  { {0x14F1E72F, 0x45D3FEA0, 0x299D6478, 0xFD3418D9, 0x1ABDA876},
	{0xB636E307, 0xA911E903, 0x4FD8B870, 0xF6E05EE6, 0x1E6D8BB5} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 823 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 824 a1");
	}
	{
		static const fp2_t var_a =  { {0xC7BE8AF1, 0x8160FA21, 0xE5F38E97, 0x15DC8050, 0x083E6933},
	{0x2C978466, 0xE2EBCF5A, 0x0ABBE86C, 0x5E2FE286, 0x1498D406} } ;
		static const fp2_t var_expected =  { {0x0A076EA6, 0xCFC72761, 0x8F9F279A, 0x62996E1B, 0x161FC49B},
	{0x164BC233, 0x7175E7AD, 0x055DF436, 0x2F17F143, 0x0A4C6A03} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 825 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 826 a1");
	}
	{
		static const fp2_t var_a =  { {0xB8F50466, 0x19405476, 0x48CF3D1C, 0xE8559FB5, 0x0B221BBB},
	{0x460C9294, 0x4D9A2471, 0x5900C67C, 0x957ACAEC, 0x00898BFA} } ;
		static const fp2_t var_expected =  { {0x5C7A8233, 0x0CA02A3B, 0xA4679E8E, 0xF42ACFDA, 0x05910DDD},
	{0xA306494A, 0x26CD1238, 0x2C80633E, 0x4ABD6576, 0x0044C5FD} } ;
		fp2_hlv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_hlv 827 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_hlv 828 a1");
	}
	{
		static const fp2_t var_a =  { {0x6BEC779E, 0x6AE3D132, 0xA002AD4E, 0x9C8CA791, 0x099162F4},
	{0x39B19AF1, 0xC7AE27D7, 0x97140C82, 0x071D7ED2, 0x175C0582} } ;
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 829 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 830 a1");
	}
	{
		static const fp2_t var_a =  { {0xB94A74B7, 0xA158E434, 0xE9EE298C, 0x96CFBC8D, 0x1B4B2C85},
	{0xAD3BB348, 0x74BCA944, 0xF56FC82B, 0x0760FD8D, 0x09222BB1} } ;
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0xB94A74B7, 0xA158E434, 0xE9EE298C, 0x96CFBC8D, 0x1B4B2C85},
	{0xAD3BB348, 0x74BCA944, 0xF56FC82B, 0x0760FD8D, 0x09222BB1} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 831 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 832 a1");
	}
	{
		static const fp2_t var_a =  { {0x94C265A1, 0x09B63939, 0x0FD6627D, 0x51E9CEA2, 0x21DEB221},
	{0xD8B00907, 0x55C2D7C1, 0x6202EDC1, 0x4FD216B7, 0x0FDBCFF0} } ;
		static const bigint_t var_b = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const fp2_t var_expected =  { {0xE6E7CC7E, 0xC0465696, 0xC753F5CA, 0x633FDAFF, 0x0AC8291E},
	{0x560625E2, 0x2D8D6446, 0x31BB9CDF, 0x257AC49D, 0x0AE69368} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 833 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 834 a1");
	}
	{
		static const fp2_t var_a =  { {0xB6139E1D, 0x1FB6643D, 0x15DB1955, 0x47FE2C8C, 0x1F98749E},
	{0x0A8689DC, 0x13F1CD40, 0x1348C767, 0xDA306C42, 0x0915BC1F} } ;
		static const bigint_t var_b = {0xF5296785, 0x4A73572C, 0xD2BDD2AE, 0xBBCB36DB, 0x61F0EB90};
		static const fp2_t var_expected =  { {0xF1C752C9, 0xBEBC343C, 0x0CEAA942, 0xE5062477, 0x13745235},
	{0xD6E3D55A, 0xEC6BE9BE, 0x9FC77BE2, 0x0451BC7B, 0x09561E55} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 835 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 836 a1");
	}
	{
		static const fp2_t var_a =  { {0x4FDBFB55, 0xD0942E36, 0xE01ACE70, 0x566FC7E8, 0x0CAB894F},
	{0x68887518, 0xC8F42A21, 0x9887E065, 0xB7AAE774, 0x0444223C} } ;
		static const bigint_t var_b = {0x6792B76F, 0xB41CD33E, 0x9A5CFA57, 0x23318C86, 0x8452D362};
		static const fp2_t var_expected =  { {0x2F09AB77, 0x4D251F61, 0x1D8C0D56, 0x665F018C, 0x1945E5C0},
	{0xBF1BBA09, 0x38B2A4FD, 0x953D3D65, 0x30C8955E, 0x22F25D1C} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 837 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 838 a1");
	}
	{
		static const fp2_t var_a =  { {0xC52FEAC8, 0x5CE0E8D0, 0x93D42842, 0xD4E9CE60, 0x02828EFB},
	{0x723E837F, 0x9D8D8349, 0x0E1AEF6F, 0xB199EA71, 0x1E1541D4} } ;
		static const bigint_t var_b = {0x7A61B734, 0x65F32949, 0xCC50F7AE, 0x5571F561, 0x434F9D3E};
		static const fp2_t var_expected =  { {0x41928AFA, 0x667DCA68, 0x9874C4E6, 0x3017C0F4, 0x10844BDF},
	{0x96E7F7D4, 0x31F055CB, 0x072FC6DC, 0x7E4861EA, 0x0A1A0C1C} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 839 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 840 a1");
	}
	{
		static const fp2_t var_a =  { {0x15ED8142, 0xE27306F7, 0xFC798263, 0x7FA4F86E, 0x0FFB8253},
	{0x8094E0C6, 0xAC07ED8C, 0x38186AE4, 0x41B69A20, 0x1C3E8796} } ;
		static const bigint_t var_b = {0x227477E4, 0x53A43F04, 0x94FB8750, 0xA10A1B38, 0x7C09F584};
		static const fp2_t var_expected =  { {0xB4E74166, 0x402F36F7, 0x2009DD58, 0x6D0B6105, 0x1DDBADDE},
	{0x861FA584, 0xD18192C9, 0x1199D3F6, 0x9DBD448B, 0x03D298A2} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 841 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 842 a1");
	}
	{
		static const fp2_t var_a =  { {0xCA61930C, 0x4BB90671, 0xDC8D8799, 0x681B2BAD, 0x02F2C933},
	{0x30CF278A, 0x2B4448BB, 0xAA58CE7C, 0x20F4E802, 0x108D6F9A} } ;
		static const bigint_t var_b = {0xF2B08A0A, 0xC1BB6E01, 0x79321561, 0x947C4E96, 0xCB426919};
		static const fp2_t var_expected =  { {0x5F3D3C2A, 0x9B1C0131, 0x405B5D7D, 0x8D595144, 0x05BCBF48},
	{0x301E9962, 0xC16A0E46, 0x852EF9BF, 0x2392076C, 0x06C22FDE} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 843 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 844 a1");
	}
	{
		static const fp2_t var_a =  { {0x01529529, 0x25370DE2, 0xE87509E0, 0x80A734AF, 0x0653BCD3},
	{0x7CBB516A, 0x46F662FD, 0x8BABAD2C, 0x52E49C33, 0x1A51BDF8} } ;
		static const bigint_t var_b = {0x9615B968, 0x5B27E46D, 0x5821AB07, 0x8564B4B7, 0x18E3E615};
		static const fp2_t var_expected =  { {0xCEB90584, 0x2BE921BC, 0x4A5FDC70, 0x6CF2B01C, 0x1091E266},
	{0x57312383, 0x17AF1E32, 0x17F7D213, 0x217118C8, 0x20BC8235} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 845 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 846 a1");
	}
	{
		static const fp2_t var_a =  { {0xBAA189C8, 0x6ADFDE43, 0x0C9CEBF2, 0xF4415B0B, 0x077BE8E1},
	{0x716E2A45, 0x44F34E09, 0x91B76D98, 0x669193A5, 0x043F7F60} } ;
		static const bigint_t var_b = {0x18906DFB, 0x3D4BC25D, 0x35BF474A, 0xBFAC31A6, 0x8AB04023};
		static const fp2_t var_expected =  { {0x571AA0B5, 0xD1793D91, 0xC9F36FDA, 0xBD33D24B, 0x1738B0FA},
	{0xB1D5DE5C, 0x147E218F, 0xEE141B13, 0x00E930FE, 0x0F344C46} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 847 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 848 a1");
	}
	{
		static const fp2_t var_a =  { {0x70DC61F5, 0x0DA43023, 0x08B2D47A, 0xAC76FFF9, 0x1CAB14AA},
	{0x26E54774, 0x9FFB1696, 0x034EB085, 0xD274FDBC, 0x1F3BF941} } ;
		static const bigint_t var_b = {0xF814CB6A, 0x444B635C, 0x7CA0C0E1, 0x4D774D05, 0x6CC7F896};
		static const fp2_t var_expected =  { {0x4A749937, 0x1D902109, 0x012B5405, 0x534A5CD4, 0x1F34E261},
	{0xFA6265F7, 0xAA8A9ED9, 0xADE87915, 0x69970E7E, 0x1FC31BD4} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 849 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 850 a1");
	}
	{
		static const fp2_t var_a =  { {0x9D573023, 0x12B62BB3, 0xE83348D9, 0xCC065A23, 0x05042BED},
	{0x38E64B3D, 0x434632C0, 0x8B0A87F4, 0x5DF860A5, 0x2080DDF1} } ;
		static const bigint_t var_b = {0x5AEDC9B8, 0xFC7F73A3, 0x8398D249, 0x2ADF0C2F, 0xADDEDD01};
		static const fp2_t var_expected =  { {0x44A98C61, 0x9BE3A52B, 0xD990236F, 0x79658983, 0x16D682A3},
	{0x8970A4C7, 0x775C1044, 0xAD4C42BB, 0x1D88DECE, 0x116C6982} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 851 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 852 a1");
	}
	{
		static const fp2_t var_a =  { {0x2CF5896C, 0xF7B85571, 0x6426A131, 0xC1F52FE0, 0x03F8C826},
	{0xCE71ABEE, 0x0D79AE27, 0x966BBD2C, 0x020F2892, 0x108D42A8} } ;
		static const bigint_t var_b = {0x2DD201E0, 0xADE62A59, 0x0C993950, 0xEC0D8192, 0x431AA057};
		static const fp2_t var_expected =  { {0x57DC6A2B, 0x5484C1ED, 0x1BEE0B6F, 0xC84D2D38, 0x16CFD02C},
	{0xD4DEA82F, 0xD6689748, 0xB3E85624, 0x09A096C2, 0x1F3F95D0} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 853 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 854 a1");
	}
	{
		static const fp2_t var_a =  { {0x306852AD, 0xCCF4C740, 0x1689C1FF, 0x6558C8A7, 0x2386394E},
	{0x5506EA03, 0xD44CF3C3, 0xF1FC9561, 0x465D32F4, 0x1F179912} } ;
		static const bigint_t var_b = {0x8CD67E2A, 0x38582AAE, 0x744C3FA4, 0xB9D339F6, 0xA765DB9C};
		static const fp2_t var_expected =  { {0xB866958B, 0xF5D99EB5, 0xCDAC951A, 0x3E55FE98, 0x0169BEEA},
	{0xC9EBFF3F, 0x2BCBFC6D, 0xDE3B6F0E, 0xFB0757AB, 0x218D1B04} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 855 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 856 a1");
	}
	{
		static const fp2_t var_a =  { {0x9DF49F63, 0xF02AAE34, 0x714279A3, 0xB948EE22, 0x0A4ED78F},
	{0x25FEE0C6, 0xC4947DFC, 0xF93FD361, 0x4EF4D1B6, 0x236247C4} } ;
		static const bigint_t var_b = {0x1393ED0A, 0x1FCFADA2, 0xC1E5C4C0, 0x0DB01D98, 0x3C3A12CB};
		static const fp2_t var_expected =  { {0x3A89F03A, 0xA5AFD359, 0xC11A8F17, 0xAA54A606, 0x160A327D},
	{0x475FBB3D, 0xE7923CFD, 0x727739BE, 0xB5EEA199, 0x0745D971} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 857 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 858 a1");
	}
	{
		static const fp2_t var_a =  { {0xC241399A, 0xFC6230AC, 0x3CF59128, 0xE8C48E21, 0x068D2B07},
	{0x0A06926A, 0x864E0256, 0x7D381695, 0xC7FEF94B, 0x1A618B9C} } ;
		static const bigint_t var_b = {0x05B36C5B, 0x36A668AF, 0x830E8281, 0xFF351C89, 0xA03F9492};
		static const fp2_t var_expected =  { {0x847BB680, 0x7AFF699F, 0x07D8D1FC, 0x97A78A0F, 0x1AD28E43},
	{0x7F165EAB, 0x8E3FFEA6, 0x0B7BBDE7, 0x8E8CE491, 0x20915DE3} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 859 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 860 a1");
	}
	{
		static const fp2_t var_a =  { {0xD22CE2B5, 0x5E3111FA, 0xBA6E2575, 0x060AF28E, 0x0DD92759},
	{0x28C6E8A8, 0xE9DD0D75, 0x45FAD90A, 0xCD259CF3, 0x14C3BA65} } ;
		static const bigint_t var_b = {0x359CF1DA, 0x7BF6BFC2, 0x141D47B4, 0x57EE1366, 0x791876F8};
		static const fp2_t var_expected =  { {0x31DE893C, 0x09900969, 0xE9F09F6F, 0xBBC4C175, 0x2005975A},
	{0x2E3B7549, 0xD9131A68, 0xA8AE0E2E, 0x433FEB38, 0x1639A95A} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 861 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 862 a1");
	}
	{
		static const fp2_t var_a =  { {0x3A110448, 0x97322C20, 0x984EFA6D, 0xE7A0967C, 0x0AB9A4A2},
	{0x3A8E5BC6, 0x315079FD, 0xE83DD723, 0xEA1B71E6, 0x1C2327F1} } ;
		static const bigint_t var_b = {0xA61B8B39, 0x4FF72983, 0xAF26DF89, 0x1BFCB1CB, 0xC4E80C25};
		static const fp2_t var_expected =  { {0x6FDC89DB, 0x0062DCDB, 0xD190A36C, 0x94CF3619, 0x1E097DD1},
	{0xA9A2DACA, 0x1D2C22B6, 0x3B62A2C6, 0x58B07C6E, 0x09AC1FC6} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 863 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 864 a1");
	}
	{
		static const fp2_t var_a =  { {0x222972D5, 0x12783B47, 0x79AD7A3D, 0x356F00B4, 0x142963A3},
	{0xFE08FD49, 0x44FD7C89, 0x35260B34, 0x469F52C1, 0x19CDD283} } ;
		static const bigint_t var_b = {0xC66BB16C, 0xF262616E, 0x5CF56906, 0xD9B9C745, 0x56A72794};
		static const fp2_t var_expected =  { {0x181B8BD8, 0x744A4D00, 0xCE18EB12, 0xA4FBF65B, 0x06A1AFDC},
	{0x73401EF1, 0xF0BC2987, 0x518F4F51, 0x1CEDF31B, 0x0D350116} } ;
		fp2_exp(var_res, var_a, var_b);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_exp 865 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_exp 866 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 867 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 868 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 869 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 870 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 871 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 872 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 873 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 874 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 875 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 876 a1");
	}
	{
		static const fp2_t var_a =  { {0x9851B32B, 0x44A40D5D, 0x7C73A6FA, 0x6E1564EF, 0x1C785F4E},
	{0x7AF7EBC6, 0xB966EA94, 0x4BBA3E0C, 0xBB78AD9E, 0x1881F95E} } ;
		static const fp2_t var_expected =  { {0xB3FE9F30, 0xD9894742, 0xBCD719A3, 0x4140F6F6, 0x0788C0B5},
	{0xD1586695, 0x64C66A0B, 0xED908291, 0xF3DDAE47, 0x0B7F26A4} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 877 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 878 a1");
	}
	{
		static const fp2_t var_a =  { {0x29B05177, 0xB3D8F62A, 0xE3003DC8, 0x7DB7D266, 0x1F9DFAFA},
	{0x6D3969ED, 0x0AB2A4B4, 0x3A837637, 0x2AD42589, 0x1A0B25FF} } ;
		static const fp2_t var_expected =  { {0x22A000E4, 0x6A545E76, 0x564A82D5, 0x319E897F, 0x04632509},
	{0xDF16E86E, 0x137AAFEB, 0xFEC74A67, 0x8482365C, 0x09F5FA04} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 879 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 880 a1");
	}
	{
		static const fp2_t var_a =  { {0x549A8A46, 0x639621F7, 0x5EBB2243, 0xA664F11F, 0x0CDD4DD0},
	{0xB450F108, 0x0574361B, 0x52F0D3B7, 0x80AF3B7B, 0x1C2178E0} } ;
		static const fp2_t var_expected =  { {0xF7B5C815, 0xBA9732A8, 0xDA8F9E5A, 0x08F16AC6, 0x1723D233},
	{0x97FF6153, 0x18B91E84, 0xE659ECE7, 0x2EA7206A, 0x07DFA723} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 881 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 882 a1");
	}
	{
		static const fp2_t var_a =  { {0xB5F2F60C, 0x2C9FB503, 0x1BCA7EF2, 0x3F61B684, 0x08114EC8},
	{0x4F0FE45E, 0x0272B10F, 0xD13DF6F8, 0x9206B4F9, 0x04385D17} } ;
		static const fp2_t var_expected =  { {0x965D5C4F, 0xF18D9F9C, 0x1D8041AB, 0x6FF4A562, 0x1BEFD13B},
	{0xFD406DFD, 0x1BBAA390, 0x680CC9A6, 0x1D4FA6EC, 0x1FC8C2EC} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 883 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 884 a1");
	}
	{
		static const fp2_t var_a =  { {0x67BE8294, 0x150CBC74, 0x18CFB371, 0x1E0DD1AA, 0x0BA938B1},
	{0x9D9C7EDC, 0x666B03D7, 0x3FA77396, 0x121C6DC4, 0x0FA6E85A} } ;
		static const fp2_t var_expected =  { {0xE491CFC7, 0x0920982B, 0x207B0D2D, 0x91488A3C, 0x1857E752},
	{0xAEB3D37F, 0xB7C250C8, 0xF9A34D07, 0x9D39EE21, 0x145A37A9} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 885 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 886 a1");
	}
	{
		static const fp2_t var_a =  { {0x8425AA84, 0x36BF4400, 0xB229237A, 0x2962F4E3, 0x196FF01D},
	{0x2CBD398E, 0x79EA174E, 0x6C571723, 0xBBDAC3E6, 0x014F574A} } ;
		static const fp2_t var_expected =  { {0xC82AA7D7, 0xE76E109F, 0x87219D23, 0x85F36702, 0x0A912FE6},
	{0x1F9318CD, 0xA4433D52, 0xCCF3A97A, 0xF37B97FF, 0x22B1C8B8} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 887 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 888 a1");
	}
	{
		static const fp2_t var_a =  { {0x5D00258C, 0xA7878463, 0x3C0D18C0, 0x44CFF20A, 0x18F6A085},
	{0x6B3878E3, 0xF894BB6C, 0xB3BE8CA4, 0x707EA039, 0x044D9DEC} } ;
		static const fp2_t var_expected =  { {0xEF502CCF, 0x76A5D03C, 0xFD3DA7DD, 0x6A8669DB, 0x0B0A7F7E},
	{0xE117D978, 0x25989933, 0x858C33F9, 0x3ED7BBAC, 0x1FB38217} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 889 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 890 a1");
	}
	{
		static const fp2_t var_a =  { {0x33ECA630, 0xEB17BB00, 0x9F27C361, 0x41F1BC14, 0x03FB2517},
	{0xAD2E5987, 0x50BF7D7F, 0x492359FF, 0xFDA491A2, 0x02AC66D3} } ;
		static const fp2_t var_expected =  { {0x1863AC2B, 0x331599A0, 0x9A22FD3C, 0x6D649FD1, 0x2005FAEC},
	{0x9F21F8D4, 0xCD6DD720, 0xF027669E, 0xB1B1CA43, 0x2154B92F} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 891 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 892 a1");
	}
	{
		static const fp2_t var_a =  { {0xB9916187, 0x611A3E7F, 0xC204EC1D, 0x684D744A, 0x05B2C111},
	{0x4F9E3726, 0x0A9E9644, 0x6EBCE90F, 0x7BB5269C, 0x1BDAD20A} } ;
		static const fp2_t var_expected =  { {0x92BEF0D4, 0xBD131620, 0x7745D480, 0x4708E79B, 0x1E4E5EF2},
	{0xFCB21B35, 0x138EBE5B, 0xCA8DD78F, 0x33A13549, 0x08264DF9} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 893 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 894 a1");
	}
	{
		static const fp2_t var_a =  { {0xDE465B6C, 0x34700EB3, 0xA55CCD14, 0x797D8C68, 0x0BFD1DE9},
	{0x94539582, 0xE9DDA561, 0xECFA46A3, 0x315DBA69, 0x007726C3} } ;
		static const fp2_t var_expected =  { {0x6E09F6EF, 0xE9BD45EC, 0x93EDF389, 0x35D8CF7D, 0x1804021A},
	{0xB7FCBCD9, 0x344FAF3E, 0x4C5079FA, 0x7DF8A17C, 0x2389F940} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 895 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 896 a1");
	}
	{
		static const fp2_t var_a =  { {0xDE5134D8, 0x8B49CE14, 0x9F91170D, 0x94DBBAA3, 0x105CEAD4},
	{0xC3D8CB48, 0xED083D84, 0xC3A9A809, 0x5439AE36, 0x0B8A073D} } ;
		static const fp2_t var_expected =  { {0x6DFF1D83, 0x92E3868B, 0x99B9A990, 0x1A7AA142, 0x13A4352F},
	{0x88778713, 0x3125171B, 0x75A11894, 0x5B1CADAF, 0x187718C6} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 897 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 898 a1");
	}
	{
		static const fp2_t var_a =  { {0x7AB860E2, 0x75C98A07, 0x7463A36F, 0x889E7B14, 0x1A0CC704},
	{0xF1EC62CE, 0xDC332B91, 0x8D7A1226, 0x0B21A2E1, 0x1FF2DAB6} } ;
		static const fp2_t var_expected =  { {0xD197F179, 0xA863CA98, 0xC4E71D2E, 0x26B7E0D1, 0x09F458FF},
	{0x5A63EF8D, 0x41FA290E, 0xABD0AE77, 0xA434B904, 0x040E454D} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 899 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 900 a1");
	}
	{
		static const fp2_t var_a =  { {0x89FFEB6E, 0xBA931881, 0x64812AC6, 0x8E562DCC, 0x1AFFFAF2},
	{0xCE122A63, 0x8742882E, 0x92FA5581, 0x97BB5BC9, 0x01D2EE64} } ;
		static const fp2_t var_expected =  { {0xC25066ED, 0x639A3C1E, 0xD4C995D7, 0x21002E19, 0x09012511},
	{0x7E3E27F8, 0x96EACC71, 0xA6506B1C, 0x179B001C, 0x222E319F} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 901 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 902 a1");
	}
	{
		static const fp2_t var_a =  { {0x7B2D7B1D, 0x3D75C1BA, 0xBEAD27B8, 0x2453F9E1, 0x1460FB61},
	{0x30EAFB2E, 0x040D1A7F, 0x25CC1477, 0x9BDB81C8, 0x227DCBB7} } ;
		static const fp2_t var_expected =  { {0xD122D73E, 0xE0B792E5, 0x7A9D98E5, 0x8B026204, 0x0FA024A2},
	{0x1B65572D, 0x1A203A21, 0x137EAC27, 0x137ADA1E, 0x0183544C} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 903 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 904 a1");
	}
	{
		static const fp2_t var_a =  { {0x8F8CC896, 0x288A7F37, 0x18245882, 0x276607FA, 0x188E0119},
	{0xE10B0937, 0xA4E3F833, 0x03648A50, 0xEA6497FC, 0x146CBE5D} } ;
		static const fp2_t var_expected =  { {0xBCC389C5, 0xF5A2D568, 0x2126681B, 0x87F053EC, 0x0B731EEA},
	{0x6B454924, 0x79495C6C, 0x35E6364D, 0xC4F1C3EA, 0x0F9461A5} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 905 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 906 a1");
	}
	{
		static const fp2_t var_a =  { {0xE3C3424C, 0x896C602C, 0x48D3893A, 0x6C71AA42, 0x2194B27D},
	{0xDDD82D4E, 0xD4258160, 0x37CAC8A8, 0xE8BDD862, 0x06FCCD03} } ;
		static const fp2_t var_expected =  { {0x688D100F, 0x94C0F473, 0xF0773763, 0x42E4B1A3, 0x026C6D86},
	{0x6E78250D, 0x4A07D33F, 0x017FF7F5, 0xC6988384, 0x1D0452FF} } ;
		fp2_neg(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_neg 907 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_neg 908 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 909 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 910 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 911 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 912 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 913 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 914 a1");
	}
	{
		static const fp2_t var_a =  { {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 915 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 916 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		static const fp2_t var_expected =  { {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 917 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 918 a1");
	}
	{
		static const fp2_t var_a =  { {0x2A0616A0, 0x6771183D, 0x86943EEF, 0xEE281D36, 0x1B50356C},
	{0x9338864E, 0x3C35FA36, 0x444B2C5D, 0x919000B9, 0x0872C56B} } ;
		static const fp2_t var_expected =  { {0x07BBDAE5, 0xB0B4DBDA, 0xD3DDBD40, 0x2CF9DE86, 0x129F4AD6},
	{0x26710C9C, 0x786BF46D, 0x889658BA, 0x23200172, 0x10E58AD7} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 919 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 920 a1");
	}
	{
		static const fp2_t var_a =  { {0xA22779F2, 0x74330479, 0x6496F4DD, 0x56324A39, 0x19BFB6A2},
	{0x35553A36, 0x97640F53, 0x182ABA9E, 0xFFE9850B, 0x01FBB146} } ;
		static const fp2_t var_expected =  { {0xF7FEA189, 0xCA38B452, 0x8FE3291C, 0xFD0E388C, 0x0F7E4D40},
	{0x6AAA746C, 0x2EC81EA6, 0x3055753D, 0xFFD30A16, 0x03F7628D} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 921 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 922 a1");
	}
	{
		static const fp2_t var_a =  { {0x2B27894B, 0x5E45829A, 0xA2F84801, 0x85862449, 0x0F6EE54B},
	{0xFA5E6354, 0xDBF12DE2, 0x7F550ED6, 0x2072AC1D, 0x0C4398BA} } ;
		static const fp2_t var_expected =  { {0x564F1296, 0xBC8B0534, 0x45F09002, 0x0B0C4893, 0x1EDDCA97},
	{0xF4BCC6A8, 0xB7E25BC5, 0xFEAA1DAD, 0x40E5583A, 0x18873174} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 923 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 924 a1");
	}
	{
		static const fp2_t var_a =  { {0x16280658, 0x589A076F, 0xF4D93184, 0x4BE4D6F1, 0x1FBDFDB0},
	{0xB4E36B15, 0xDAC87A8A, 0xEEBE37DA, 0x81843FB9, 0x17C7D838} } ;
		static const fp2_t var_expected =  { {0xDFFFBA55, 0x9306BA3D, 0xB067A26A, 0xE87351FD, 0x1B7ADB5C},
	{0x1D7683CF, 0x9763A075, 0xA431AF17, 0x53B2238D, 0x0B8E906D} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 925 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 926 a1");
	}
	{
		static const fp2_t var_a =  { {0x25B0177B, 0x7CFAFCEA, 0x5330A4A7, 0xA27DAE21, 0x02415D16},
	{0xD1E3A49D, 0x59A86132, 0x42949D64, 0xD23555E2, 0x0B4619B9} } ;
		static const fp2_t var_expected =  { {0x4B602EF6, 0xF9F5F9D4, 0xA661494E, 0x44FB5C42, 0x0482BA2D},
	{0xA3C7493A, 0xB350C265, 0x85293AC8, 0xA46AABC4, 0x168C3373} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 927 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 928 a1");
	}
	{
		static const fp2_t var_a =  { {0x714A2B37, 0x02642591, 0xDB92460A, 0x00940820, 0x00BD605A},
	{0xB14A1614, 0xF8E95970, 0xA64C551F, 0x2634845C, 0x232BB84F} } ;
		static const fp2_t var_expected =  { {0xE294566E, 0x04C84B22, 0xB7248C14, 0x01281041, 0x017AC0B4},
	{0x1643D9CD, 0xD3A55E41, 0x134DE9A1, 0x9D12ACD3, 0x2256509A} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 929 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 930 a1");
	}
	{
		static const fp2_t var_a =  { {0xBDCC1930, 0x9B641059, 0x0541B634, 0x207DF835, 0x113582C3},
	{0x3DB40D55, 0x8D1AD3E5, 0xEB645DD3, 0x383BDF99, 0x1CC54638} } ;
		static const fp2_t var_expected =  { {0x7B983260, 0x36C820B3, 0x0A836C69, 0x40FBF06A, 0x226B0586},
	{0x2F17C84F, 0xFC08532A, 0x9D7DFB08, 0xC121634D, 0x15896C6C} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 931 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 932 a1");
	}
	{
		static const fp2_t var_a =  { {0x74919536, 0x9857C530, 0xB2916CE7, 0x8F3062B7, 0x05CB378C},
	{0x88A3425E, 0x6E5F02CC, 0x819C4637, 0xE74DC5A9, 0x1BE8941F} } ;
		static const fp2_t var_expected =  { {0xE9232A6C, 0x30AF8A60, 0x6522D9CF, 0x1E60C56F, 0x0B966F19},
	{0xC4F63261, 0xBE90B0F8, 0xC9EDCBD0, 0x1F452F6C, 0x13D0083C} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 933 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 934 a1");
	}
	{
		static const fp2_t var_a =  { {0x83A6620C, 0x6DD88637, 0xE84A26BA, 0xD25ACC24, 0x1F341A4A},
	{0xA1F76E78, 0xCBD879C8, 0x6A7DCB27, 0x55CB1B5C, 0x13015DB5} } ;
		static const fp2_t var_expected =  { {0xBAFC71BD, 0xBD83B7CE, 0x97498CD6, 0xF55F3C63, 0x1A671491},
	{0xF79E8A95, 0x79839EF0, 0x9BB0D5B1, 0xFC3FDAD2, 0x02019B66} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 935 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 936 a1");
	}
	{
		static const fp2_t var_a =  { {0x9C0C0272, 0x0DBE1F81, 0x7D6BD5E3, 0xC4D8709F, 0x20B17FDC},
	{0x4052F362, 0xFFCF2A42, 0xFA61D52D, 0xDB3A982A, 0x0A53FBE2} } ;
		static const fp2_t var_expected =  { {0xEBC7B289, 0xFD4EEA62, 0xC18CEB27, 0xDA5A8558, 0x1D61DFB5},
	{0x80A5E6C4, 0xFF9E5484, 0xF4C3AA5B, 0xB6753055, 0x14A7F7C5} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 937 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 938 a1");
	}
	{
		static const fp2_t var_a =  { {0x07209EFA, 0xBFAEDB46, 0x2E681A79, 0x31792842, 0x056003D5},
	{0xC65B4F3B, 0xD961AE9F, 0x27452B95, 0x3251CDB5, 0x187642FA} } ;
		static const fp2_t var_expected =  { {0x0E413DF4, 0x7F5DB68C, 0x5CD034F3, 0x62F25084, 0x0AC007AA},
	{0x40664C1B, 0x9496089F, 0x153F968D, 0xB54D3F84, 0x0CEB65F0} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 939 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 940 a1");
	}
	{
		static const fp2_t var_a =  { {0x3FB9E53B, 0x0FC53C32, 0xCF8A1976, 0xB112C4F5, 0x12A16436},
	{0x05E5AEE0, 0x23D0E397, 0x244B2B12, 0xE007FE86, 0x22354AD8} } ;
		static const fp2_t var_expected =  { {0x3323781B, 0x015D23C4, 0x65C9724E, 0xB2CF2E05, 0x0141A869},
	{0xBF7B0B65, 0x2974728D, 0x0F4B9586, 0x10B9A126, 0x206975AE} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 941 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 942 a1");
	}
	{
		static const fp2_t var_a =  { {0xCAD3E155, 0x9B88CCFD, 0x3DDCCD59, 0x0F47B070, 0x12033D9B},
	{0x17565EEA, 0x3EF01168, 0xE8F79DC7, 0x833CAF76, 0x1B630A7D} } ;
		static const fp2_t var_expected =  { {0x4957704F, 0x18E4455B, 0x426EDA15, 0x6F3904FA, 0x00055B32},
	{0xE25C6B79, 0x5FB2CE2F, 0x98A47AF0, 0x57230307, 0x12C4F4F7} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 943 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 944 a1");
	}
	{
		static const fp2_t var_a =  { {0x44D91381, 0xFC4B18BA, 0xF60129EB, 0x6BB43B45, 0x1B37B4DA},
	{0x86D74928, 0xB03EE5D5, 0x4335F8AF, 0x4921709E, 0x1D7A934C} } ;
		static const fp2_t var_expected =  { {0x3D61D4A7, 0xDA68DCD4, 0xB2B79339, 0x28121AA5, 0x126E49B1},
	{0xC15E3FF5, 0x4250770A, 0x4D2130C1, 0xE2EC8556, 0x16F40694} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 945 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 946 a1");
	}
	{
		static const fp2_t var_a =  { {0xBD935635, 0xAC27DB90, 0x567920C6, 0xBB51C852, 0x23068CC0},
	{0xE5697DE5, 0x9B65CDDB, 0x6A09DAAF, 0xC4BE9D55, 0x072D8E00} } ;
		static const fp2_t var_expected =  { {0x2ED65A0F, 0x3A226281, 0x73A780EF, 0xC74D34BE, 0x220BF97D},
	{0xCAD2FBCA, 0x36CB9BB7, 0xD413B55F, 0x897D3AAA, 0x0E5B1C01} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 947 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 948 a1");
	}
	{
		static const fp2_t var_a =  { {0x806588C6, 0xD79C73FD, 0xBF380240, 0x63F28F6C, 0x09FE16D9},
	{0x8C72CFEA, 0xBF03F5A3, 0xDB2C704A, 0x6CD3AB19, 0x1AF95335} } ;
		static const fp2_t var_expected =  { {0x00CB118C, 0xAF38E7FB, 0x7E700481, 0xC7E51ED9, 0x13FC2DB2},
	{0xCC954D79, 0x5FDA96A6, 0x7D0E1FF7, 0x2A50FA4D, 0x11F18667} } ;
		fp2_dbl(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_dbl 949 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_dbl 950 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 951 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 952 a1");
	}
	{
		static const fp2_t var_a =  { {0xEB0EA360, 0x09CE5F68, 0x0E703A25, 0x10BEEBB6, 0x0FD7E2F4},
	{0x3E074F63, 0xA5BF00A8, 0xDBBBB1DE, 0x95C18B77, 0x0FDCABB1} } ;
		static const fp2_t var_expected =  { {0xEB0EA360, 0x09CE5F68, 0x0E703A25, 0x10BEEBB6, 0x0FD7E2F4},
	{0x0E4902F8, 0x786E53F8, 0x5D8F0EBF, 0x1994D06E, 0x14247452} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 953 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 954 a1");
	}
	{
		static const fp2_t var_a =  { {0xC89E9E0E, 0x82290E88, 0xC2FCE47A, 0x19CEB4C4, 0x184610D8},
	{0x25C1AF66, 0x994467E6, 0x148A9CEE, 0x4F12B455, 0x0AECBEA1} } ;
		static const fp2_t var_expected =  { {0xC89E9E0E, 0x82290E88, 0xC2FCE47A, 0x19CEB4C4, 0x184610D8},
	{0x268EA2F5, 0x84E8ECBA, 0x24C023AF, 0x6043A791, 0x19146162} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 955 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 956 a1");
	}
	{
		static const fp2_t var_a =  { {0x0940CF12, 0x94F8DBFB, 0x1EC69CBC, 0x0ADCD559, 0x2247D6E7},
	{0x28089357, 0xA85904B1, 0x1840600A, 0x161C2C27, 0x0D9F01C0} } ;
		static const fp2_t var_expected =  { {0x0940CF12, 0x94F8DBFB, 0x1EC69CBC, 0x0ADCD559, 0x2247D6E7},
	{0x2447BF04, 0x75D44FEF, 0x210A6093, 0x993A2FBF, 0x16621E43} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 957 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 958 a1");
	}
	{
		static const fp2_t var_a =  { {0x1ABBD5D3, 0xD48A53BA, 0xE060D94B, 0xFC00379F, 0x07F66F33},
	{0xA1081603, 0x381B1A3D, 0x62F1B0DF, 0x565AFFFF, 0x14E46998} } ;
		static const fp2_t var_expected =  { {0x1ABBD5D3, 0xD48A53BA, 0xE060D94B, 0xFC00379F, 0x07F66F33},
	{0xAB483C58, 0xE6123A62, 0xD6590FBE, 0x58FB5BE6, 0x0F1CB66B} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 959 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 960 a1");
	}
	{
		static const fp2_t var_a =  { {0x6E1652A5, 0x18ACAFA5, 0xFBE0515E, 0x7ACE5852, 0x0EA72144},
	{0xF433273D, 0x4D193CA8, 0xF27862B7, 0x5C99C1A8, 0x13DE0C09} } ;
		static const fp2_t var_expected =  { {0x6E1652A5, 0x18ACAFA5, 0xFBE0515E, 0x7ACE5852, 0x0EA72144},
	{0xF433273D, 0x4D193CA8, 0xF27862B7, 0x5C99C1A8, 0x13DE0C09} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 961 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 962 a1");
	}
	{
		static const fp2_t var_a =  { {0x7B9D64DA, 0xD71EAD2B, 0x9981ADD7, 0xFD412775, 0x185FD93D},
	{0xE0F4A323, 0xE599BD9B, 0x5679AE47, 0xFAA74105, 0x0B3A01B1} } ;
		static const fp2_t var_expected =  { {0x7B9D64DA, 0xD71EAD2B, 0x9981ADD7, 0xFD412775, 0x185FD93D},
	{0x6B5BAF38, 0x38939704, 0xE2D11256, 0xB4AF1AE0, 0x18C71E51} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 963 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 964 a1");
	}
	{
		static const fp2_t var_a =  { {0x8ECB5FF2, 0xA49D3C53, 0xB8CA083D, 0x518FD185, 0x0F34968D},
	{0x3865136C, 0xB572ABE2, 0xFC19317A, 0xE72D0782, 0x1DE4F5FA} } ;
		static const fp2_t var_expected =  { {0x8ECB5FF2, 0xA49D3C53, 0xB8CA083D, 0x518FD185, 0x0F34968D},
	{0x13EB3EEF, 0x68BAA8BE, 0x3D318F23, 0xC8295463, 0x061C2A08} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 965 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 966 a1");
	}
	{
		static const fp2_t var_a =  { {0x94806E1D, 0x34254B84, 0xBD0430D2, 0x8AF7D76D, 0x1644AF03},
	{0x24462024, 0xF75F4721, 0x6A7B60AE, 0xE28E74A1, 0x19409D68} } ;
		static const fp2_t var_expected =  { {0x94806E1D, 0x34254B84, 0xBD0430D2, 0x8AF7D76D, 0x1644AF03},
	{0x24462024, 0xF75F4721, 0x6A7B60AE, 0xE28E74A1, 0x19409D68} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 967 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 968 a1");
	}
	{
		static const fp2_t var_a =  { {0xD001EB9A, 0x2060729A, 0x909258FF, 0x4651C27D, 0x0FB9341C},
	{0x01B83827, 0x47C9E046, 0x780AF0B1, 0x978E0784, 0x127A8F2D} } ;
		static const fp2_t var_expected =  { {0xD001EB9A, 0x2060729A, 0x909258FF, 0x4651C27D, 0x0FB9341C},
	{0x01B83827, 0x47C9E046, 0x780AF0B1, 0x978E0784, 0x127A8F2D} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 969 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 970 a1");
	}
	{
		static const fp2_t var_a =  { {0xE1C061AA, 0x645AF47C, 0xD34DC6BF, 0x5597BD93, 0x030F9FED},
	{0x4BBB9D96, 0xDAFB5ABC, 0x74201E3A, 0x2768B311, 0x0E35DEC3} } ;
		static const fp2_t var_expected =  { {0xE1C061AA, 0x645AF47C, 0xD34DC6BF, 0x5597BD93, 0x030F9FED},
	{0x4BBB9D96, 0xDAFB5ABC, 0x74201E3A, 0x2768B311, 0x0E35DEC3} } ;
		fp2_frobenius_map(var_res, var_a, 4);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 971 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 972 a1");
	}
	{
		static const fp2_t var_a =  { {0x5853E687, 0x9FB71A66, 0x9CE65DE9, 0x0130ACDF, 0x062D5681},
	{0x79B76B5A, 0x0FCDB936, 0xCCBD2316, 0x909CEF0E, 0x1781BAA4} } ;
		static const fp2_t var_expected =  { {0x5853E687, 0x9FB71A66, 0x9CE65DE9, 0x0130ACDF, 0x062D5681},
	{0xD298E701, 0x0E5F9B69, 0x6C8D9D88, 0x1EB96CD7, 0x0C7F655F} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 973 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 974 a1");
	}
	{
		static const fp2_t var_a =  { {0xD3E9397D, 0x51E4491D, 0x9161D82E, 0x32FE0DA0, 0x0514393A},
	{0xA4D0C9B6, 0xA50B6AD6, 0xCA8A5B01, 0x31C79523, 0x23269A9B} } ;
		static const fp2_t var_expected =  { {0xD3E9397D, 0x51E4491D, 0x9161D82E, 0x32FE0DA0, 0x0514393A},
	{0xA77F88A5, 0x7921E9C9, 0x6EC0659C, 0x7D8EC6C2, 0x00DA8568} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 975 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 976 a1");
	}
	{
		static const fp2_t var_a =  { {0xFDB4B6BF, 0x12149257, 0x7DD94743, 0xE3CB1998, 0x0108D3A6},
	{0x5ECFBB58, 0x0A08D06F, 0x9F097786, 0xB20F8502, 0x2010A8F1} } ;
		static const fp2_t var_expected =  { {0xFDB4B6BF, 0x12149257, 0x7DD94743, 0xE3CB1998, 0x0108D3A6},
	{0xED809703, 0x14248430, 0x9A414918, 0xFD46D6E3, 0x03F07711} } ;
		fp2_frobenius_map(var_res, var_a, 3);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 977 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 978 a1");
	}
	{
		static const fp2_t var_a =  { {0xF3217158, 0x7A2508E8, 0x266CFB10, 0x88B6CE1E, 0x12FCD622},
	{0x04CD82B9, 0x3DAA4520, 0xDFA0F059, 0xD3B4D59D, 0x171908FF} } ;
		static const fp2_t var_expected =  { {0xF3217158, 0x7A2508E8, 0x266CFB10, 0x88B6CE1E, 0x12FCD622},
	{0x4782CFA2, 0xE0830F80, 0x59A9D044, 0xDBA18648, 0x0CE81703} } ;
		fp2_frobenius_map(var_res, var_a, 5);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 979 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 980 a1");
	}
	{
		static const fp2_t var_a =  { {0x8F7AA637, 0xDE70F1DC, 0x83F81A55, 0x6B2C2097, 0x21F81811},
	{0x94F28698, 0x40E1AD6E, 0x452888D2, 0xF264BAA3, 0x1BAF46E9} } ;
		static const fp2_t var_expected =  { {0x8F7AA637, 0xDE70F1DC, 0x83F81A55, 0x6B2C2097, 0x21F81811},
	{0xB75DCBC3, 0xDD4BA731, 0xF42237CB, 0xBCF1A142, 0x0851D919} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 981 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 982 a1");
	}
	{
		static const fp2_t var_a =  { {0x4B7287F7, 0xF06742D6, 0xA62CE79A, 0x6A59BF3D, 0x14E3EFF2},
	{0x54EB2984, 0xEF5A5F21, 0xE0627433, 0xB76811CD, 0x10F32573} } ;
		static const fp2_t var_expected =  { {0x4B7287F7, 0xF06742D6, 0xA62CE79A, 0x6A59BF3D, 0x14E3EFF2},
	{0xF76528D7, 0x2ED2F57E, 0x58E84C6A, 0xF7EE4A18, 0x130DFA8F} } ;
		fp2_frobenius_map(var_res, var_a, 1);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 983 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 984 a1");
	}
	{
		static const fp2_t var_a =  { {0xBA6B0DD6, 0xEFBB46B2, 0x394E8D13, 0x6987533C, 0x1F9C4C7C},
	{0xADF67148, 0x8997E9FE, 0x067EF6C4, 0x7DB98007, 0x1B8C4B56} } ;
		static const fp2_t var_expected =  { {0xBA6B0DD6, 0xEFBB46B2, 0x394E8D13, 0x6987533C, 0x1F9C4C7C},
	{0xADF67148, 0x8997E9FE, 0x067EF6C4, 0x7DB98007, 0x1B8C4B56} } ;
		fp2_frobenius_map(var_res, var_a, 2);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_frobenius 985 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_frobenius 986 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 987 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 988 a1");
	}
	{
		static const fp2_t var_a =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6} } ;
		static const fp2_t var_expected =  { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 989 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 990 a1");
	}
	{
		static const fp2_t var_a =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		static const fp2_t var_expected =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 991 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 992 a1");
	}
	{
		static const fp2_t var_a =  { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0x1B0F08EF, 0xA578021F, 0x541FBE25, 0xF1FCEC4D, 0x13FC9FF4},
	{0x1B0F08EF, 0xA578021F, 0x541FBE25, 0xF1FCEC4D, 0x13FC9FF4} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 993 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 994 a1");
	}
	{
		static const fp2_t var_a =  { {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D} } ;
		static const fp2_t var_expected =  { {0x3141496C, 0x78B55281, 0xE52B0278, 0xBD596F98, 0x1004800E},
	{0x1B0F08EF, 0xA578021F, 0x541FBE25, 0xF1FCEC4D, 0x13FC9FF4} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 995 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 996 a1");
	}
	{
		static const fp2_t var_a =  { {0x805AA192, 0xF5D89579, 0xEE3BCCA6, 0x6424DDA6, 0x0D7652EF},
	{0xD5F507AA, 0x7C03E3F6, 0xE66DB615, 0xBF0F202D, 0x2262DB9F} } ;
		static const fp2_t var_expected =  { {0xAD20D55F, 0xF87F1D4F, 0xD85AB463, 0x4CFAC5D7, 0x05AD147F},
	{0x3210494B, 0x3F70B56C, 0x0089C99D, 0xAF75C562, 0x06272C5E} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 997 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 998 a1");
	}
	{
		static const fp2_t var_a =  { {0xC0AE1277, 0x93DF54D0, 0x7E768457, 0xD3019D4A, 0x0A1189D7},
	{0xFFBB7D8E, 0xB4B4F10D, 0x4D694999, 0x1F992234, 0x2205B4FA} } ;
		static const fp2_t var_expected =  { {0xF1F6DD77, 0x4DB696B0, 0x1AB2E573, 0xD5FB6308, 0x083E81B3},
	{0x5C24D462, 0x4455BC23, 0xC73804AF, 0xB6142A89, 0x00EBF1D3} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 999 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1000 a1");
	}
	{
		static const fp2_t var_a =  { {0xF62A2860, 0xCEF133A5, 0x1FC04A4D, 0x0B3AA87A, 0x1A24FED7},
	{0x63868F37, 0xC8C106DC, 0x046FFED1, 0x67E8268D, 0x22C5A602} } ;
		static const fp2_t var_expected =  { {0x872345AF, 0xB2674419, 0x13BD8A66, 0x13923AC5, 0x21DC50BC},
	{0x7604F2AB, 0x006ED3A1, 0x8359718E, 0x16B55990, 0x2401171C} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1001 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1002 a1");
	}
	{
		static const fp2_t var_a =  { {0x7FE84422, 0x9C78D1F8, 0xA3BABA3E, 0x3873B88D, 0x04DAC2A4},
	{0xD0C1A80D, 0x6572F78A, 0x0F1203FC, 0x62F15B44, 0x2203CBC0} } ;
		static const fp2_t var_expected =  { {0x27AE64E1, 0xF70AE8EB, 0xEC48981C, 0x4C56BAF3, 0x000DB02E},
	{0x65A15CFF, 0x44C913F3, 0xEE9E4261, 0xC82E087F, 0x16D952F9} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1003 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1004 a1");
	}
	{
		static const fp2_t var_a =  { {0x5C093442, 0x4F305B56, 0x75EAEAC4, 0x56EB8B54, 0x003486F0},
	{0xCA34FD82, 0x1014ACA0, 0x28C0A242, 0x3FF9BC19, 0x1BDB41D0} } ;
		static const fp2_t var_expected =  { {0x6F2068A9, 0x1ADD2A15, 0x6B9BA252, 0xC4203C36, 0x02B04E90},
	{0x7E9DBB99, 0xBABECA7C, 0x8B1EAF25, 0x434FC470, 0x104AE735} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1005 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1006 a1");
	}
	{
		static const fp2_t var_a =  { {0x3FFD527F, 0x03EACB3B, 0x188F9C6A, 0x15A160F0, 0x1D61C01D},
	{0x7F6CE312, 0x19E8F0BC, 0x3C2CFD53, 0xBAA58ED4, 0x1E6FD2AB} } ;
		static const fp2_t var_expected =  { {0x701FFDCD, 0xE0E7385F, 0x5784183E, 0x2404B545, 0x17C87F2A},
	{0xCBA0E42C, 0x092EBE42, 0xB0F6A7B0, 0x1FA1D828, 0x0E454992} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1007 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1008 a1");
	}
	{
		static const fp2_t var_a =  { {0xBE659E83, 0x61A3221F, 0x62CAB36A, 0xF5A81C0D, 0x22FFE507},
	{0xCBB09356, 0x7313609A, 0x4D1C7E9F, 0x328B02A5, 0x0B513FA2} } ;
		static const fp2_t var_expected =  { {0xF1846458, 0x3DB09F26, 0xF06E4103, 0x4C89B68C, 0x1BBB539E},
	{0x46686B7B, 0x078F4654, 0x7901A995, 0x5BE6A81A, 0x137A2D1A} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1009 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1010 a1");
	}
	{
		static const fp2_t var_a =  { {0x636A7ABD, 0xE4947125, 0x51400179, 0x33422A31, 0x1768650A},
	{0x0AAEBBEF, 0xD57EF6F4, 0x4AEA7C34, 0x313ED3D7, 0x13579F5E} } ;
		static const fp2_t var_expected =  { {0x083EAD9A, 0xA2526333, 0xB1108E6E, 0x03376756, 0x1EC3DCB8},
	{0x988DFEDD, 0xAA0947B5, 0x5FCF2371, 0x4C3515F2, 0x2054C48D} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1011 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1012 a1");
	}
	{
		static const fp2_t var_a =  { {0x96833FFB, 0xE741A052, 0x71970FFB, 0x201D30DA, 0x170BEAE8},
	{0xE366DC02, 0xDF5367D6, 0x7FA6BF9F, 0x46CFD106, 0x1878659C} } ;
		static const fp2_t var_expected =  { {0xAF467A67, 0xC92A14CA, 0x82C6A579, 0xD0B102D1, 0x13791D87},
	{0x83B49BAA, 0x313103DF, 0x634EEDE1, 0x80A9FDA0, 0x1BFAF1A8} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1013 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1014 a1");
	}
	{
		static const fp2_t var_a =  { {0x22D99481, 0xDF69EF3F, 0xCE67F7FC, 0xFCFDB429, 0x0C4EDE88},
	{0x23F61331, 0x8E7E487C, 0x2127CECD, 0xB2D70321, 0x08394398} } ;
		static const fp2_t var_expected =  { {0x6359A811, 0xA5211197, 0xBAF1AF26, 0x226FBA36, 0x1D7D116B},
	{0x583F6AE0, 0x3EAF6234, 0x38AAA0E4, 0xE300C2F2, 0x1BD2CC1E} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1015 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1016 a1");
	}
	{
		static const fp2_t var_a =  { {0xBAFAA01F, 0xBCEFF6C1, 0x2B1ED529, 0xC0EC6688, 0x149CC701},
	{0xEF7174EF, 0x5A924E51, 0xBAB5B7FF, 0x166EE60D, 0x1B8FC824} } ;
		static const fp2_t var_expected =  { {0x3503E62B, 0xC94A1B4E, 0x65F93B74, 0x19FAD222, 0x0F647F0F},
	{0xAD779D05, 0x2BB77399, 0x6BF57191, 0x218A43EB, 0x187DCBD1} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1017 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1018 a1");
	}
	{
		static const fp2_t var_a =  { {0x750A6118, 0x8948C4CF, 0x064E08C9, 0xFD329ACA, 0x0C54A674},
	{0x48D9E2E1, 0xC753D6C5, 0xE8F59443, 0x2703C196, 0x000E9F25} } ;
		static const fp2_t var_expected =  { {0x7BB4DBBA, 0x00A8D547, 0x693B10F3, 0x956F350A, 0x0F82E948},
	{0x09245795, 0x84CD83CE, 0x312F82DC, 0x34716F6B, 0x11D24096} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1019 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1020 a1");
	}
	{
		static const fp2_t var_a =  { {0x335FF3E3, 0x125AFADF, 0x02928354, 0x04C40E77, 0x0809C2F9},
	{0x97733A4E, 0x51A0F5B2, 0x46964C82, 0xBA7917D8, 0x114D3ED6} } ;
		static const fp2_t var_expected =  { {0xAA355C5D, 0x9B177837, 0x984984FC, 0x411CE5A0, 0x00BF9388},
	{0xE0E7F7B7, 0xF88834A1, 0x4448FC59, 0x387D3526, 0x0BF21287} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1021 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1022 a1");
	}
	{
		static const fp2_t var_a =  { {0xA9EEEC09, 0x4D2980A1, 0x241AF7DB, 0xF3CD29D1, 0x084F86A8},
	{0x35297FB8, 0xA21EE9F1, 0x5796729D, 0xCAEFC475, 0x190F62DA} } ;
		static const fp2_t var_expected =  { {0xAB9B83DF, 0x9E4C5720, 0x159475A2, 0x32307559, 0x0113C089},
	{0x9A74DBCC, 0x330626A7, 0x64746186, 0x6F929921, 0x00FF33D0} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1023 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1024 a1");
	}
	{
		static const fp2_t var_a =  { {0xBAE98FCC, 0xD7BEEA1D, 0x1883D139, 0xB0DC241C, 0x0C2A0B25},
	{0x943FB7AD, 0xDE0D6F37, 0xA7402AC3, 0xB76A0313, 0x047678F6} } ;
		static const fp2_t var_expected =  { {0x62022A46, 0x85CF0875, 0x46532F95, 0x3595DD22, 0x219E6D17},
	{0x9C029B50, 0x36C4B394, 0x409809CD, 0x949349D0, 0x082A6B00} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1025 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1026 a1");
	}
	{
		static const fp2_t var_a =  { {0x9944E403, 0x82297544, 0x7DA2CC05, 0xC46118DF, 0x009ED05F},
	{0x213CB009, 0x8525FC8E, 0xE5AB494E, 0x5673C44D, 0x03769A89} } ;
		static const fp2_t var_expected =  { {0x5E553F6B, 0x98D3BAC3, 0x3D83C596, 0x24FACF1D, 0x08CC0413},
	{0xB4CC912D, 0x1E01236B, 0x62C977E5, 0xEFBF8FCE, 0x1C7AB243} } ;
		fp2_inv(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_inv 1027 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_inv 1028 a1");
	}
	{
		static const fp2_t var_a =  { {0xDF052272, 0x91D08A01, 0x912C46D6, 0x2483A663, 0x15482608},
	{0xD5CF5202, 0xA399F749, 0x1AD40C67, 0x1C142CBE, 0x0F4AD246} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1029 ");
	}
	{
		static const fp2_t var_a =  { {0x9BA3E1F7, 0x36872E1D, 0x4AB87788, 0x2D8C62CC, 0x0A52D567},
	{0x04A5B9D1, 0x1DA791C8, 0x0AC05B55, 0xDCDAA350, 0x155E404C} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1030 ");
	}
	{
		static const fp2_t var_a =  { {0xD7B03A46, 0x82D31645, 0x37217BCB, 0x591ABA2B, 0x1C767A40},
	{0x4BBE379C, 0x8A141202, 0x419AA9E5, 0x9F0AD2E9, 0x1473098E} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1031 ");
	}
	{
		static const fp2_t var_a =  { {0xF5958432, 0x17E5A4BE, 0xA81586B8, 0xE9226148, 0x1F147977},
	{0x06DCF4B9, 0x435EBBFB, 0xF6E4544E, 0xD15CB45E, 0x0B5EE784} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1032 ");
	}
	{
		static const fp2_t var_a =  { {0xEA9D6EE0, 0x58562370, 0xD74D66D4, 0xE2F6F359, 0x1D8C2CBA},
	{0xB547A1DE, 0x04ABBE80, 0x6B1CA9BB, 0x9625CB5C, 0x0122CA40} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1033 ");
	}
	{
		static const fp2_t var_a =  { {0xE13BD645, 0x17C4E25B, 0x90D7D0CB, 0x1C029113, 0x025ED49A},
	{0x52917ABB, 0xE0F2C44B, 0xD4F1F1E6, 0x8DA689CA, 0x067AD76B} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1034 ");
	}
	{
		static const fp2_t var_a =  { {0x07B72A6D, 0x7F7AE284, 0x2F14F968, 0x54A91DF7, 0x161282C8},
	{0xC604976D, 0xDB6633CA, 0xDFFA646F, 0x5C9B54F9, 0x00D4B737} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1035 ");
	}
	{
		static const fp2_t var_a =  { {0xA8E1AEB7, 0xB6DBC4E4, 0x5826032E, 0xD28D4053, 0x0981C345},
	{0xA84CF54A, 0x229C4D6F, 0xEFF022CC, 0x01DD2EB3, 0x1E778909} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1036 ");
	}
	{
		static const fp2_t var_a =  { {0xC01407DE, 0x823FEBE8, 0x6230AA8D, 0xCDB15AD2, 0x06A63F7A},
	{0xBC3A3F29, 0x2D7C1F14, 0x4CDB0BEC, 0x4AA6900D, 0x18C3A3C7} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1037 ");
	}
	{
		static const fp2_t var_a =  { {0x9C07B000, 0x5990239E, 0xED3646F5, 0xF0D72544, 0x1BCC73F6},
	{0xEE04650D, 0x0625DAAD, 0x07422AE2, 0x48B458BF, 0x0F1B1FC0} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1038 ");
	}
	{
		static const fp2_t var_a =  { {0x47BB9E98, 0x5A36B9BE, 0x3773B066, 0x1FB0A008, 0x0D56532F},
	{0x9F4286E2, 0xD1E988DC, 0xBD423E2D, 0x58B15932, 0x01BB537A} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1039 ");
	}
	{
		static const fp2_t var_a =  { {0x97C0C694, 0xA66BDD6D, 0xF4FDB4C7, 0xA73E6634, 0x1476A044},
	{0xC1CACB89, 0xB6754E09, 0x42A9A551, 0x57915886, 0x15C122C2} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1040 ");
	}
	{
		static const fp2_t var_a =  { {0x9B4BF420, 0x4C0EC861, 0x6E02D2D7, 0xC9FC425A, 0x09A8FD34},
	{0x36C1EA54, 0x5F442E27, 0xF5AB09BC, 0x3367FA31, 0x1E23508A} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1041 ");
	}
	{
		static const fp2_t var_a =  { {0x8B145F82, 0x3E140497, 0x33E20B53, 0x948E99A5, 0x07A59BC9},
	{0x478FA5E4, 0x89777325, 0x41C6B735, 0x8F6C5C2E, 0x0DDA92AD} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1042 ");
	}
	{
		static const fp2_t var_a =  { {0x15244E7C, 0x12B6E9AB, 0x29F30860, 0x51DB6B7D, 0x0E368922},
	{0x1D28233D, 0x54F114FB, 0xAEC11463, 0x440707D7, 0x200A1961} } ;
		assert_true(fp2_legendre(var_a) == 1, "fp2_legendre 1043 ");
	}
	{
		static const fp2_t var_a =  { {0xF6FF9386, 0xDBAB0CE4, 0x2CA26DC9, 0xF5BA4841, 0x2398874E},
	{0xAE1B8202, 0xB33E4D9F, 0x221847E6, 0x076480CB, 0x051DA445} } ;
		assert_true(fp2_legendre(var_a) == -1, "fp2_legendre 1044 ");
	}
	{
		static const fp2_t var_a =  { {0x951A5379, 0xA7F86BC7, 0x528A3871, 0xC890AD17, 0x21B96ADC},
	{0x5FAAB8A7, 0xBA8F18A0, 0xC617BC09, 0x7C70DBF1, 0x1627F7EF} } ;
		static const fp2_t var_expected =  { {0xCBE51D45, 0x98E5D2A4, 0x0E1C940C, 0x7258989D, 0x14ECFAAD},
	{0x174114C2, 0x1907801A, 0x31D39FBA, 0x1FA79812, 0x004AF389} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1045 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1046 a1");
	}
	{
		static const fp2_t var_a =  { {0xEC37D31D, 0x779E23BC, 0x8A7C455E, 0x1F76D124, 0x006A2836},
	{0x43BADCF0, 0x950934F3, 0x02175338, 0x8EC6CA9B, 0x1DF37D16} } ;
		static const fp2_t var_expected =  { {0xC8F885B9, 0x39902B84, 0xEAAF810E, 0x26DE2BE5, 0x21039D03},
	{0xF69E6BBE, 0xE0C3920D, 0xE312A430, 0x7DFFCF68, 0x0D304BC9} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1047 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1048 a1");
	}
	{
		static const fp2_t var_a =  { {0xC6432AEE, 0x5A4CAA13, 0x1C077EE3, 0x8452377C, 0x1B45C89B},
	{0xBA679101, 0xE318A51B, 0xF268D069, 0x228E8233, 0x1F03A308} } ;
		static const fp2_t var_expected =  { {0x2AA4D6C1, 0x6C07B7CE, 0x27BB97D1, 0xDF744002, 0x0E23D6A7},
	{0x7F5D73FA, 0x4ED3F2F5, 0xEEC51807, 0x7F71B695, 0x129447ED} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1049 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1050 a1");
	}
	{
		static const fp2_t var_a =  { {0x58C6CCE1, 0x1049A0B8, 0x4172B378, 0xB6EC83E9, 0x033E3CC0},
	{0x50159B4B, 0x904A0BDE, 0x029209AA, 0xCF8C2E1E, 0x0BAE6AE6} } ;
		static const fp2_t var_expected =  { {0xEF84E862, 0xD40C6476, 0x3043DD93, 0x6908AAAB, 0x0FA139C6},
	{0xDF7EC02D, 0xC6839655, 0xB709BC06, 0xA52D084F, 0x03ED341A} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1051 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1052 a1");
	}
	{
		static const fp2_t var_a =  { {0xA5FC166A, 0xAA7F84D5, 0x546FE365, 0xF3CBD83C, 0x210AB542},
	{0x9F2732D8, 0xC6C7AABC, 0xDBE9DB80, 0x4F377E98, 0x0D623B70} } ;
		static const fp2_t var_expected =  { {0x04BC346C, 0x2A109513, 0x7B4D6903, 0x2993AC9B, 0x084A82FB},
	{0x228EABA5, 0x11BAEA5F, 0xC28A9F87, 0xAD27BAA0, 0x107761CF} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1053 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1054 a1");
	}
	{
		static const fp2_t var_a =  { {0x4D757CC3, 0x24566268, 0xE1C7C4DE, 0xDD7E4BC3, 0x1ADC81C3},
	{0x701EFA2F, 0x9AD76EC4, 0x0BAEC7E8, 0x8B59E696, 0x0CCD3C2F} } ;
		static const fp2_t var_expected =  { {0x0EA26769, 0xC0B8107D, 0xDB4E371B, 0xB47F33DA, 0x23165366},
	{0xB9AF2177, 0x7FE2B7E6, 0xE9473A65, 0xAC65CA6A, 0x071ADBA8} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1055 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1056 a1");
	}
	{
		static const fp2_t var_a =  { {0x1978EBBC, 0x3861E1F2, 0x0AC39EAF, 0xFEFA0E82, 0x0FCE0E8B},
	{0xC3A25929, 0xC8FDB25D, 0x79E2F229, 0x501EF303, 0x0E8700C1} } ;
		static const fp2_t var_expected =  { {0x52F11999, 0xC6702048, 0xC9BE52BA, 0x1A8975D5, 0x19A365B0},
	{0xE54384C4, 0xF02BD7AA, 0x60B308AE, 0x93D54E73, 0x04B73ECD} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1057 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1058 a1");
	}
	{
		static const fp2_t var_a =  { {0xC84562AE, 0x45DFD96A, 0x553947AA, 0xADB468F4, 0x1DB142F3},
	{0xDD14ABF8, 0x27972289, 0x826BC137, 0x6A71ABD9, 0x147BBDCC} } ;
		static const fp2_t var_expected =  { {0x4D043DF8, 0xC4C49EDA, 0xC1B5CF71, 0x38A33822, 0x1E56A87C},
	{0x88478A49, 0x7107F6F8, 0x0B1A39BE, 0xDCFDD64D, 0x23E148D0} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1059 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1060 a1");
	}
	{
		static const fp2_t var_a =  { {0x15B9A02E, 0x0C9562AD, 0x07857CF1, 0x5E8577E3, 0x17F6D5ED},
	{0xC60CFD86, 0x33A1ACCC, 0x51E2A833, 0x9B4B63C6, 0x08F75D44} } ;
		static const fp2_t var_expected =  { {0xF57253BB, 0xFFCD0475, 0x29DD409B, 0x2F6079BB, 0x0605C260},
	{0x4F8F8715, 0x56EA82B1, 0x860C9F0A, 0xFCEDF037, 0x00C4DB8A} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1061 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1062 a1");
	}
	{
		static const fp2_t var_a =  { {0x946DE4AD, 0xF6260144, 0x4F8FBC1F, 0xECECE3BA, 0x0DD37281},
	{0xA4D6160F, 0xBFC24634, 0x3C9A91AB, 0xA0653319, 0x019BC744} } ;
		static const fp2_t var_expected =  { {0xA2D25989, 0x38EF177F, 0x19B923A7, 0xE1B8BCE5, 0x075EF55D},
	{0xAAA5E019, 0x02062D99, 0x410CCA87, 0x605FF877, 0x110EDF04} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1063 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1064 a1");
	}
	{
		static const fp2_t var_a =  { {0x327A25E4, 0xEDCBF74C, 0xA521F7D2, 0x9C1D211B, 0x2278F688},
	{0xD7A4B329, 0xA6395057, 0x1C3045E8, 0xB2953A75, 0x1F7BCE6C} } ;
		static const fp2_t var_expected =  { {0x41064017, 0x82AD7C1B, 0x8EC2E774, 0x57B7FF3B, 0x049F0FDD},
	{0x181F2C1A, 0xF415C6D1, 0x1BFB8642, 0x561CAD36, 0x15359BAF} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1065 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1066 a1");
	}
	{
		static const fp2_t var_a =  { {0x819FE595, 0x25C3FA5F, 0x3D77027C, 0x04B25947, 0x1811339E},
	{0x367B9DBF, 0xCE20D0C5, 0xA0E26DAB, 0xB2C4676F, 0x0BED6C19} } ;
		static const fp2_t var_expected =  { {0x4F8B32E9, 0xACAAE783, 0x30A13756, 0x58001E4A, 0x158695C0},
	{0xB7AD91BB, 0x5515E8CC, 0xA3C1A2C7, 0xB654F0B4, 0x1B78E59F} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1067 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1068 a1");
	}
	{
		static const fp2_t var_a =  { {0xB38222BD, 0x961B88B4, 0xE78D9CB5, 0x1B9B13E3, 0x0893DAD0},
	{0x85E21933, 0x1A30FE7F, 0x3E58965D, 0x9989D61B, 0x077FDA4D} } ;
		static const fp2_t var_expected =  { {0x7750FA97, 0xD526F560, 0x3BCB7FAD, 0x44A2AC0C, 0x15478954},
	{0x791C6EB1, 0x103303AF, 0xA43B3833, 0x6B0FE3E6, 0x092E4552} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1069 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1070 a1");
	}
	{
		static const fp2_t var_a =  { {0xD080D3B3, 0x83B6BF05, 0xF38B1169, 0xAB23C5AD, 0x0875AD4C},
	{0x06312C29, 0xF2A4F766, 0xA323B3D8, 0xCDA38715, 0x18712287} } ;
		static const fp2_t var_expected =  { {0x6A15CC43, 0xFA87BBD5, 0xB9A39609, 0x493A5198, 0x093FA40D},
	{0x9E4D1E7B, 0x9D1B2419, 0x3B5DEF35, 0x0CF3EC0F, 0x1C4A4CF5} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1071 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1072 a1");
	}
	{
		static const fp2_t var_a =  { {0x6CFE4C71, 0xD2B6C965, 0x77129B3A, 0x427C95CC, 0x0802835B},
	{0x9CD5D452, 0x840FCA12, 0x5D2B319B, 0xF31735AC, 0x1D6B4E2D} } ;
		static const fp2_t var_expected =  { {0x14FAA074, 0x8C095EAF, 0xA5655693, 0xD2E94B10, 0x1C8C2798},
	{0x9C1DCF2E, 0x7B2126E8, 0xCAA3FB8A, 0x299223C6, 0x1FE6DD8D} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1073 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1074 a1");
	}
	{
		static const fp2_t var_a =  { {0xF81CB2EF, 0x03EF55CB, 0x6A091E37, 0x1C14DA87, 0x20624C0C},
	{0x28C49847, 0x83B74C97, 0x8D57C481, 0x89D9DA21, 0x0384C0D1} } ;
		static const fp2_t var_expected =  { {0x9E44B1FD, 0x5BD526B3, 0xF1B0722D, 0x9BB4FDDE, 0x133DCA95},
	{0x477CCC30, 0xCF4E244B, 0xCA28F7C4, 0x73922984, 0x00796819} } ;
		fp2_sqrt(var_res, var_a);
		assert_bi_equal(var_expected[0], var_res[0], "fp2_sqrt 1075 a0");
		assert_bi_equal(var_expected[1], var_res[1], "fp2_sqrt 1076 a1");
	}
#endif
#endif
	return 0;
}
