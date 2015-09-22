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

#if (BNCURVE == BN256)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp var_a = {{0x5FA410ED, 0x45E9BCF6, 0x21D231E9, 0x3D0A066B, 0xD80FB274, 0xAFFA80DA, 0x4BD3FA0A, 0x7625C7C1},
	{0xB2FF6F6E, 0x3A8D5636, 0xB687754D, 0x220C3751, 0xD8840AB8, 0x9A7809F5, 0x7BA8E9AD, 0x842EBDBA},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 1 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 2 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 3 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 5 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 6 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x16C7592F, 0x1FD3CA02, 0xE714F5CF, 0x0BDB8A8F, 0x8F698C51, 0xE2E46020, 0x2A7F857D, 0x636403C2},
	{0x8F2F94DA, 0x40CAFBC5, 0xE8AF56E6, 0xD27A9FDF, 0x07C06472, 0x34A4F123, 0xA1351E10, 0x9BBD1227},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 7 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 8 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 9 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 10 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 11 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 12 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF46E7F78, 0x9191B949, 0x9EE6613D, 0x53E578BC, 0xDCE568AB, 0xA038BA3D, 0x9BAEED9C, 0x768E08D8},
	{0x72827D93, 0x2828EFAF, 0x2561A7CB, 0xF046A0ED, 0xC2F2669B, 0x1A0A864E, 0xCA6BE022, 0x84FDC295},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 13 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 14 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 15 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 16 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 17 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 18 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x07451C8E, 0xBFCD68E8, 0x4B746E07, 0x0E4B3E1B, 0xFD66B37A, 0xFABE464C, 0x52F8E6D4, 0x178867AE},
	{0x07D6FBA2, 0x33F3D587, 0x1284D214, 0x967882C9, 0xE8294ED0, 0x7C2410C8, 0x4C231A86, 0xC896853B},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 19 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 20 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 21 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 22 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 23 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 24 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9B4FAB4B, 0x07BBE8F5, 0x31363AB4, 0x759EE9D1, 0x6FD8380E, 0x41A778C3, 0x450A3C0F, 0xF0214795},
	{0x3DCDF578, 0xE209B502, 0x947492D4, 0x1C5035F1, 0x9463D82B, 0xCD5B6007, 0xBCF35F8E, 0x306661A8},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 25 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 26 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 27 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 28 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 29 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 30 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3EC2591C, 0x0C27B115, 0xD83FF7EF, 0x00722649, 0xEDFE7B96, 0x079760AC, 0xA7F9C2F0, 0xE9A8B720},
	{0x41A0A4FF, 0xF5ECF952, 0xD051B4C4, 0x1BD64CC5, 0x245F63F9, 0xBB16668B, 0xEF831F6E, 0xC50CE2E6},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 31 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 32 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 33 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 34 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 35 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 36 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xBDCDECCC, 0xAF89BC45, 0x0390C78F, 0x69E87D2A, 0x7648DE6F, 0x1BBA37DB, 0xEF92057C, 0x2C760A43},
	{0x7EEC6376, 0x6FCFE7D8, 0x2B4E4FA9, 0x6C6BC438, 0x356D5FAD, 0x3ACAEB55, 0xF9D90147, 0xD07FD113},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 37 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 38 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 39 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 40 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 41 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 42 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2470BBE2, 0x101587A9, 0xB7608E46, 0xA944DBAF, 0x469C9C88, 0x90D28DDF, 0xD1A99DEE, 0x227F2DEC},
	{0xA28415E0, 0x8FA66808, 0x4AFF6F30, 0x29598536, 0xA43F1620, 0x790977CD, 0x30AB8198, 0xDA987597},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 43 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 44 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 45 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 46 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 47 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 48 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC044BCE4, 0x90C5F152, 0x3A77B570, 0xF979541D, 0xDB2AA07F, 0xB5481B9C, 0x426945EE, 0x73E50A77},
	{0x9A401912, 0xD83942A5, 0x11AE3753, 0xAA60B1B5, 0x8DB9C547, 0xEA954C17, 0x28ACB5C0, 0xACA55169},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 49 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 50 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 51 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 52 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 53 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 54 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2054A743, 0xD171094A, 0x1074E69B, 0xD1BB367E, 0xF13D2359, 0x1D3B37B7, 0x77A39B5A, 0x0887EC6D},
	{0x94CDD8B0, 0x0933AFB6, 0xA7A66F7D, 0x884BB1B5, 0x4FBF0EEF, 0x3D6F983A, 0xB8E04E84, 0x4FF86B07},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 55 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 56 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 57 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 58 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 59 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 60 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0EE42BCE, 0xB3DAB154, 0xFE22B8AF, 0xEC0D57FE, 0x85082AE6, 0x988EF154, 0xE6219C58, 0x0B8EE36E},
	{0xFB7DE7A6, 0x242E5CD3, 0x70889000, 0x9D7B079B, 0x8506B824, 0x64E3B99D, 0xF3EBCAD2, 0x0C77170A},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 61 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 62 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 63 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 64 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 65 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 66 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9A473ADE, 0x57BB343F, 0x0ACB4FDC, 0x41D4A678, 0xD576CF3B, 0x38FED0CB, 0x43F5CB6C, 0xE4003439},
	{0x7E19B6E3, 0x6AC9C8A6, 0x10963D97, 0x007BE6A5, 0x0DE6C461, 0x909EB3AE, 0x2E60DA3B, 0x6C2C417D},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 67 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 68 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 69 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 70 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 71 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 72 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0FAF61AC, 0x1FD9B4A6, 0x797EF6B3, 0x09630C14, 0x5CFE65D7, 0x4C2B3545, 0x82C519B9, 0x3D52C42C},
	{0x08ADDA6E, 0x5CB50CD1, 0x6E0534FE, 0x0C8C8B7B, 0x0426E0A2, 0x31BBBFC7, 0x000FFBCA, 0x38D74168},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 73 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 74 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 75 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 76 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 77 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 78 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFAF74176, 0xAB138586, 0xCF6AA214, 0xBF8E7F07, 0xDA6D6C4C, 0x66AD5C7A, 0xDB2172B3, 0xFFF090C4},
	{0xC85AEC1C, 0xBAC40082, 0xAE4FAEE7, 0x5A395DFB, 0xC7CF1AF2, 0xF9D107A1, 0x3C59463E, 0x797A332D},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 79 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 80 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 81 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 82 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 83 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 84 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2A7D1165, 0xDC746309, 0xD12874C6, 0x1A3C6ADE, 0x49BD5699, 0x58220FFF, 0xC0D007EA, 0x52D823D5},
	{0x2A2AF372, 0x87FCCB70, 0x34813BCE, 0xC1E5CDD8, 0xF2FDFE1D, 0xD80981E0, 0xF87E73CD, 0x78EDCAA8},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 85 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 86 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 87 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 88 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 89 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 90 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA9E63661, 0xD440985F, 0x850C28F4, 0x14F04CD6, 0xE8DD2A80, 0x323EEBCA, 0xE71F50AA, 0x9F1F1098},
	{0xDBD76B85, 0x03A4D410, 0xA7890A6C, 0x5C5C02B3, 0x64ACF69A, 0x0128EC98, 0x88EF0DF6, 0xBE6BB53B},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 91 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 92 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 93 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 94 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 95 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 96 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x453342DD, 0x4AB625DD, 0x8D758C3D, 0xEDCDF986, 0xA134ECB0, 0x06B63ECC, 0x8F32B63B, 0x4C7263AF},
	{0x83838D05, 0xA750B105, 0x0553FE9A, 0x0DE6077E, 0xA70BA836, 0x9473FAED, 0x6ECEE2AC, 0x0C101338},
	0};
		static ecpoint_fp var_b = {{0x303E6388, 0xC44B02B7, 0xA072C726, 0x81C33480, 0xED07CF49, 0xD1842BA3, 0x3DA8F3BD, 0x508A7443},
	{0x3556FD02, 0xC6770792, 0x7FA8A452, 0x3197590D, 0xE3616C04, 0xD9DF27DE, 0xA4B69D96, 0x5D30D111},
	0};
		static ecpoint_fp var_expected = {{0xBE454D90, 0xEA2E48E3, 0xD483478F, 0xC903A4A9, 0xC422A88A, 0x71F9C1D3, 0x9AF0C691, 0x21791486},
	{0x177FBD13, 0xA9BC3F07, 0xF87248DD, 0x9BF518BA, 0x98AC3122, 0xA1A58E92, 0xADCA0139, 0x76B46D42},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 97 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 98 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 99 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x09BA2AE3, 0x0EFA5D11, 0xAF84FF36, 0xD2017D7A, 0x03CC40B7, 0x392808A6, 0x8E7A60F2, 0x524BCC38},
	{0x8BD7E944, 0x3C8D8895, 0xD6CD83DD, 0x61F8119F, 0x7B54939D, 0xC3434D3F, 0xEC2EBB41, 0x411FD42E},
	0};
		static ecpoint_fp var_b = {{0xFFDC7DA4, 0xFE31CB29, 0xBFBFAD01, 0xDDD20A38, 0x8857807D, 0x7CDCE2C1, 0x663D69A9, 0x0B1466AD},
	{0xB7E66496, 0x7AB599E7, 0x9090045D, 0x4ECE9E6A, 0xC9D3C3DF, 0x8EDEC755, 0x19DF30C5, 0x4EA8AA94},
	0};
		static ecpoint_fp var_expected = {{0x0EEC9A8F, 0x0E35805F, 0x967F94D6, 0xAFAF0858, 0x8BD1B87E, 0xA6BB8B5E, 0x38158644, 0x54B7A1B6},
	{0xCAB9938D, 0xD44BE449, 0x534F9E29, 0xC728DFDC, 0x346FF2D3, 0x98D22C41, 0xD78388DC, 0x37717317},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 100 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 101 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 102 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA3494168, 0x3ABD4753, 0x3697662B, 0xDAA4A440, 0x58FCB79B, 0xDD1A8386, 0x256A9C2A, 0x63A0AF2F},
	{0x3862E916, 0x2DB8ECD5, 0xCE662E9D, 0xA64225F1, 0xF4937908, 0xC9E1E2C7, 0xF1342D96, 0x9DAD718C},
	0};
		static ecpoint_fp var_b = {{0x4EE80E83, 0x7BA6EDEE, 0x4DD4281E, 0xB88C1A43, 0xC5EDE5CD, 0xA8DD5948, 0x14254BB8, 0x5F482D08},
	{0x82D8112F, 0xC7357824, 0xDE2F365B, 0xBD2E9AC1, 0x4200A7E8, 0x40A1D686, 0xC774A568, 0x1F8A3AA6},
	0};
		static ecpoint_fp var_expected = {{0x7A769C1C, 0x14519461, 0x2BA0965E, 0x47E7AA45, 0xC1082FE4, 0x729B0582, 0x82CB52B7, 0x7B0D5F98},
	{0x6BD98DB5, 0x39DF0C6D, 0xA8163D5C, 0x4F73AB79, 0x693DADA9, 0x545B8DE7, 0x6A5D0DFE, 0x8F994F1E},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 103 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 104 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 105 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x69543556, 0x64A09F76, 0x640903B9, 0x0513D563, 0x3133668A, 0x75CD975E, 0x942805AE, 0x1247C894},
	{0x3DDB01C5, 0xEA04EE55, 0xA1C0E28A, 0x19F19E61, 0x3DCB4DAD, 0x18A991E9, 0x5E1A4122, 0x0485D2CA},
	0};
		static ecpoint_fp var_b = {{0xD253B009, 0xF890D3A3, 0x46013AF0, 0x2C81F9E4, 0xE40D39EB, 0x29847ACF, 0xF1746C94, 0x347D1BE3},
	{0xBFEED83C, 0xEE11C774, 0xBBF3F0ED, 0xDF208CF4, 0xB5CE7A9F, 0xBE0BE860, 0x6CC92479, 0x0B9F991E},
	0};
		static ecpoint_fp var_expected = {{0xAC59EB59, 0x2A575532, 0x5972287F, 0xC7BA0A69, 0x102C0EC0, 0x5B2435A7, 0x7BD65B4B, 0xAC537E00},
	{0x7FCBCD5B, 0xB4491210, 0x83C30668, 0xDF7DCDD9, 0x310309A9, 0xB85B28C1, 0x65A457EA, 0x18481401},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 106 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 107 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 108 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE5E1FF18, 0xD13F8522, 0xD8C24248, 0x83A8DF06, 0x30CC9AF4, 0x404ED11F, 0xE0B9523B, 0x18684D2D},
	{0xE1F10323, 0xBA3A6388, 0x1FA89EBD, 0xA7EC41B5, 0xF792D9C7, 0xE6965FA6, 0x06582795, 0x05F94E66},
	0};
		static ecpoint_fp var_b = {{0xF6582693, 0xF49F9EC6, 0x1564876A, 0x8E9CE03A, 0xC21FED4B, 0xF7F4953E, 0xA667C90B, 0x5F41B65E},
	{0x07D7F54A, 0xD75B3C65, 0xB25999AA, 0x593E7C2B, 0x850C7448, 0xFF9F10C5, 0xBC1AA945, 0x30FE0F09},
	0};
		static ecpoint_fp var_expected = {{0x2A295513, 0x28E0CB9E, 0x723D40D3, 0xDDFEB8B0, 0x64B53C5F, 0xB4B52106, 0x2A61A58C, 0x3034ABA0},
	{0x24257068, 0x66C5CB09, 0xF1092E5D, 0xC329B1B0, 0xAF46D7DC, 0xD2D370F9, 0xE7AECEBB, 0x0BD25FCD},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 109 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 110 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 111 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0CE85449, 0x83B01CEC, 0xC238A7CF, 0x2FA23E9A, 0xF0AEAD82, 0x66B07E4C, 0xFC440840, 0x1B47C3D0},
	{0x1716CD93, 0xFC1D9225, 0xA4472D96, 0xBAB15D3F, 0x89CAE0E5, 0x04592903, 0x733E3135, 0x9315631E},
	0};
		static ecpoint_fp var_b = {{0xCD0960E7, 0xDDFE72AF, 0xAF9A502B, 0xB548264A, 0xD15A3A77, 0x5A1DE614, 0x765DCFCE, 0x3D8CC5FC},
	{0xF3F94368, 0x96289369, 0x81775916, 0xED8CD373, 0x36009CDC, 0xD42230CE, 0x85BA1D87, 0xB1D25AB6},
	0};
		static ecpoint_fp var_expected = {{0xC1419984, 0xE330ADCA, 0x98841D0D, 0xCBFFF407, 0xAF2FF89C, 0xD671BA94, 0x6BF28760, 0x1D2A6970},
	{0x65E65747, 0x31240252, 0x2BB1F32F, 0xC6EC4D48, 0x2EE920F4, 0x7902BDE4, 0x99EB0FF4, 0x24DC91CE},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 112 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 113 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 114 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8C8C47C9, 0xA6F2CD90, 0x17276FA5, 0xE5C4B66B, 0x9F0F1A6D, 0xCACE87AD, 0xEBE3CE99, 0x31C09010},
	{0xD859B572, 0xF159B9CF, 0x537B562C, 0xCEC7129D, 0x2C74AEDD, 0x33539AD5, 0x29C9A775, 0x8CB90686},
	0};
		static ecpoint_fp var_b = {{0x1594C71F, 0xB8754007, 0x43630FA3, 0xECA8237F, 0x75B77945, 0xE0387FEC, 0x16EE2E2C, 0x07199119},
	{0x2429BE5C, 0x25169CD4, 0xC741FC5A, 0xB6732D44, 0x2AB10A4E, 0x21DC5F4C, 0xCDF853DD, 0x883B0475},
	0};
		static ecpoint_fp var_expected = {{0x997B444B, 0x3FC17034, 0xE896882B, 0x0894456E, 0x0340EED3, 0xCB660C79, 0xE8E23EFE, 0x0D6CA516},
	{0xD692E80D, 0xBB35127A, 0x79A1B3FD, 0x9C7AF0F3, 0x46C430CD, 0xE7247691, 0xC9B2D9AA, 0x60846C76},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 115 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 116 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 117 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x66885678, 0xD1AA0F9F, 0xF51E218B, 0x8C541F59, 0x71B010D7, 0xE3424FC5, 0x01837366, 0x86F82023},
	{0x538DE3FD, 0xF1D8E027, 0x5AF67B63, 0xDEDD1168, 0xB35605A7, 0x2BCDF2B9, 0x106F3A90, 0x848A32BA},
	0};
		static ecpoint_fp var_b = {{0xCD66B0BE, 0x24725215, 0x77EEC152, 0xF4E84552, 0xB06534CA, 0x1B472B90, 0x31BCF604, 0x11F1EBD6},
	{0xD8E58188, 0xDB1C1AEC, 0x7ABA9787, 0x20EF78CB, 0xC336BB00, 0x6747D407, 0x92567776, 0x3E9839F6},
	0};
		static ecpoint_fp var_expected = {{0x48396B24, 0x223307EC, 0x81DF3725, 0xFDC8CDE0, 0x49E0F8E5, 0x291ECDCF, 0x808E17EF, 0x3A7693E3},
	{0x50C0162A, 0x7D3D6B56, 0x720B0FC8, 0x498BC340, 0x9412C94C, 0x3A2D9959, 0xBBEC0EFC, 0xA5E1C618},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 118 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 119 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 120 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xCF76781B, 0xFA10BD77, 0x67FDBD13, 0x7F88CD81, 0x979B7662, 0x8932085B, 0xA188B9B5, 0x6BA04113},
	{0x01D700FE, 0x8E71FFA2, 0xB91CDB8B, 0xB9C4AC42, 0xA21B7A15, 0xE0967303, 0x37F0933E, 0x0CF441C4},
	0};
		static ecpoint_fp var_b = {{0xC690EDC3, 0x6A7F99F7, 0x4280778E, 0x6772DEB0, 0xBB01127D, 0xAC59B116, 0x72BCB4FA, 0x9E42F78E},
	{0xC3630C1A, 0xA5A100AC, 0x0DA3BE9B, 0x890F1732, 0x0C238A30, 0x6F7C15FE, 0x4672CADA, 0x38E1E1C1},
	0};
		static ecpoint_fp var_expected = {{0x218F7635, 0xBD343DBE, 0xE0F80E47, 0x365A0DB8, 0xC3DC0A50, 0x491AAC13, 0x8C4829E7, 0x6C1E2083},
	{0x60B6AAE3, 0x3B30FA4B, 0x88D18D59, 0x650B5839, 0x97547CA6, 0xF8A305E9, 0x00707A4A, 0xAAB0EF4A},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 121 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 122 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 123 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA197A872, 0x63045C32, 0xE29CF4E2, 0x2309B2C9, 0xD493FA68, 0x214C7A9B, 0x5D0B0B9A, 0x482BFAD1},
	{0x174EABB3, 0x0B87208F, 0xEA2B4735, 0xE6123FCF, 0xAF229359, 0x1C855B37, 0xF704836B, 0x4898001F},
	0};
		static ecpoint_fp var_b = {{0xF1F17F0B, 0x5F6C2AE4, 0x472039DD, 0xA77A5603, 0x3E3FDEF1, 0x74B961AE, 0x71F49466, 0x2ACBC3D2},
	{0x09CC7EB3, 0xFF8DDF55, 0xBA69C5A6, 0x84937AAA, 0xDD6CE6DF, 0x5A7AC004, 0x59353DE0, 0xB9772F1E},
	0};
		static ecpoint_fp var_expected = {{0xAE212093, 0x85B19109, 0x5D693085, 0xE4A4666F, 0xE358D55B, 0xF04456C8, 0xCA0DEBC3, 0x3A4EB233},
	{0x562E24E1, 0xFEF3BE87, 0xABDCCB35, 0xACB5C8E4, 0x7282426B, 0x94E9B529, 0x12EEA898, 0xAC521A6E},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 124 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 125 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 126 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5C75FF49, 0x9F91BAA2, 0xD2B6C85E, 0x570AF9D1, 0x92F0B960, 0x846AE9D5, 0xBD12092B, 0x4CF2AACA},
	{0x694A521E, 0x8FADE9BF, 0x9E12C26C, 0x968B60A2, 0x5001F382, 0x7706E443, 0x55BAB1CE, 0x0802BF23},
	0};
		static ecpoint_fp var_b = {{0x5148C5CA, 0xE50A43F3, 0x2B929493, 0x08C0ECF7, 0x5CE57752, 0xDC381D1A, 0x54D2DE98, 0x5AE7AE33},
	{0x13D22C77, 0x38EE637D, 0x91232185, 0xA1491A42, 0x95A561D7, 0x04C3B708, 0x596F738B, 0x01D447F4},
	0};
		static ecpoint_fp var_expected = {{0xF4564ADA, 0x1A4D3EA8, 0x1E6D88C8, 0x33E0D39A, 0xD731F3F8, 0x1E08BB8B, 0xA56CAF71, 0xA5253866},
	{0x8ADFB320, 0xC6EDF8D2, 0x04645E41, 0xEF5A3840, 0x4607061E, 0x3CD7FFD7, 0xA0525F0E, 0x7708137A},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 127 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 128 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 129 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x93866257, 0xBEE89263, 0x1CDA145C, 0x9C01A13A, 0x44B09EB6, 0xC8D6632B, 0x38D22DBB, 0xA9B854A2},
	{0xAA3E7D77, 0x88FCAD73, 0x3D8C79F2, 0x017E36EB, 0x5D6D1818, 0x437F646E, 0x7ABFF308, 0xA4796DF9},
	0};
		static ecpoint_fp var_b = {{0x2A6A3FEE, 0xDA9AE1E1, 0xD3EBACCD, 0x3982C6C7, 0x84A447C0, 0x0EB209E1, 0x7755E5F0, 0x4888E0C4},
	{0x1DC212DA, 0xCD5863A9, 0x84C2A592, 0xB9907B53, 0x77418F96, 0xCA7157F6, 0xB288C089, 0x7AE350DF},
	0};
		static ecpoint_fp var_expected = {{0x16CD368F, 0x6EC04475, 0xF6F0DA79, 0xC20AC3C4, 0xB6C237E8, 0xADD29AF5, 0x29972196, 0x6FC4BF47},
	{0x4A715B20, 0xAD9933E9, 0x931652C5, 0x073A6905, 0x0A18B24C, 0x56F1BD56, 0xB1739506, 0x06FB12D2},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 130 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 131 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 132 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7919E3A9, 0x001E320F, 0x69EDEAA5, 0xE9E2CDB3, 0x3A5A3EAC, 0x04B1B42E, 0xDAA4ABEC, 0x2D97CD6F},
	{0x1E04B0FA, 0x4C46BD29, 0x818C8C21, 0xAA06B7ED, 0x0CE552B7, 0xAE4A131F, 0xBB90D98A, 0x423AB066},
	0};
		static ecpoint_fp var_b = {{0x3BD0EAA3, 0x82D77BB1, 0x9805BE80, 0x57981DCE, 0x479AF1E1, 0xF86F97B4, 0xD0E7E886, 0x9F02D718},
	{0x6CC3A97C, 0x052A871F, 0xF0FBEF01, 0x8EB74B78, 0x941A75CD, 0x294C5373, 0x1A034F72, 0x47923225},
	0};
		static ecpoint_fp var_expected = {{0x0C95EFB8, 0x59249309, 0x6EFDF89E, 0x1C2B90B3, 0x6AA54444, 0xB9994854, 0x01C01CF0, 0x2B2D4F79},
	{0xEAACA209, 0xA710C453, 0x2C78AE64, 0xA0077BCF, 0xE7714A58, 0xB301C04F, 0xAB9B6DA8, 0x4C1A7A91},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 133 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 134 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 135 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1FC9125E, 0x26FC97B2, 0x06A6287A, 0x18AB1BA2, 0x32B31BEA, 0xD829D658, 0xC303F584, 0x97A1086D},
	{0xD1F9623D, 0x24ED0381, 0x2E867BF0, 0x302152EB, 0x8E3F0879, 0x2CF9638C, 0xAD3B59E5, 0xB4D829F4},
	0};
		static ecpoint_fp var_b = {{0xE46ED6F7, 0x06FD1942, 0x001A1E55, 0x510D8D17, 0xFBF14C5B, 0x628C249E, 0x8A4E7257, 0x98AEDC23},
	{0xFD5C8FFF, 0x22353F41, 0x06862B02, 0x020EC42E, 0x2E51B50F, 0xBE2CD29F, 0x4A8E75A6, 0x4DADF589},
	0};
		static ecpoint_fp var_expected = {{0xA003BC94, 0x44F19AC4, 0xD346203C, 0x85AB4526, 0x5AF10C37, 0x0F7ABCAE, 0x97391A94, 0x22B16C2E},
	{0xDFA55D17, 0xF39B6F7B, 0x9B5DC0A0, 0x0BD9B253, 0x2034534B, 0x5DD6093E, 0xAAE1679C, 0x84806746},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 136 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 137 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 138 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2465E4FB, 0xB0ACA596, 0xA0DBD5B2, 0xCC294B42, 0xD1146DEF, 0x37EAC408, 0x1BFECEB3, 0x86051CD7},
	{0x7D6A20F3, 0x216ABD73, 0x3AE57E5C, 0x934E51D7, 0x13374736, 0x8E499CC9, 0x198AFEAE, 0x60F1784F},
	0};
		static ecpoint_fp var_b = {{0xE96158AE, 0xFE01E982, 0x5CB3E6CA, 0x4D398B84, 0x2546A314, 0x78908D92, 0x0F7E08BA, 0x944CE0A0},
	{0x7103BB3A, 0xB2233F88, 0x440B16F3, 0x4C521929, 0x35DAAA4F, 0x98EC0BC6, 0x0C830FD2, 0x681F38BF},
	0};
		static ecpoint_fp var_expected = {{0xB37779F3, 0x944E729B, 0x92BFACC8, 0x26EE728B, 0xC4ACA4C5, 0x67AC06FD, 0x36849B68, 0x3DF148D4},
	{0xBF9A0222, 0x8091E3BB, 0x67BF39C2, 0x764C0C4C, 0x8FD253F8, 0x358B18ED, 0x19E5D85B, 0x15912214},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 139 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 140 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 141 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4333B72F, 0x80A970FC, 0x5F852198, 0x56143B7E, 0xBF9BB24A, 0xC44ED2B7, 0x8ECA0FA5, 0x2048306F},
	{0x824D3AB9, 0xE276163C, 0xF8995C29, 0xEDF28262, 0x5E9082E9, 0xF7A4EEC8, 0xCF6CA0F0, 0x5B947716},
	0};
		static ecpoint_fp var_b = {{0x6BDD3CA1, 0xBD16662E, 0x1FC66AB5, 0x97FB8373, 0x48D6ACB2, 0x1C447490, 0x031753FA, 0x8D46FF1F},
	{0xE66D0E49, 0x1B199960, 0xC80F55C4, 0xF3EBC981, 0xFA06549C, 0x722544B2, 0x347A0D9C, 0x78EFC723},
	0};
		static ecpoint_fp var_expected = {{0x814E40F9, 0x653C5E1C, 0x18575D16, 0xD2D8CF06, 0x55AC0E47, 0x9AA9753A, 0xEA7C5F0C, 0x561EF206},
	{0x84B07ECE, 0x4F214C02, 0x980244EF, 0x2F6EF09C, 0xC15CD5EE, 0x3E8A6012, 0xD91A3EE3, 0x549067E8},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 142 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 143 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 144 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDB01AEF5, 0x907A59F9, 0xA3C1A8D0, 0x4CD13A67, 0xD377253A, 0x63CC7D73, 0x537C3823, 0x860033A8},
	{0xAA12508C, 0x81AEF1A2, 0x283A050A, 0xFE76DE14, 0x0261B8AD, 0x5B1F59E2, 0x4F490F9B, 0x7FBC056D},
	0};
		static ecpoint_fp var_b = {{0xDB01AEF5, 0x907A59F9, 0xA3C1A8D0, 0x4CD13A67, 0xD377253A, 0x63CC7D73, 0x537C3823, 0x860033A8},
	{0xAA12508C, 0x81AEF1A2, 0x283A050A, 0xFE76DE14, 0x0261B8AD, 0x5B1F59E2, 0x4F490F9B, 0x7FBC056D},
	0};
		static ecpoint_fp var_expected = {{0xECA7613B, 0xB5E90C7D, 0x1772A2EE, 0x75DA668B, 0xE1132039, 0x51F2B822, 0x0DDC3812, 0xB19D7881},
	{0xFA259D24, 0x2F1F881F, 0x4F189BB1, 0x98ED1EA1, 0xB986178D, 0x7DCEDE69, 0x9F7931F2, 0x7CD70032},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 145 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 146 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 147 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD6E9CCE2, 0x9B3E2085, 0x5265CCDD, 0x0800F465, 0x110E6329, 0x9D05CE5E, 0x7D0E4756, 0x47F280B9},
	{0x5CC1C0F6, 0x539FCD88, 0xD7B642E9, 0xC9D1D522, 0xCC13255F, 0xBC69576D, 0xF9AD5EE2, 0x9FD64EAC},
	0};
		static ecpoint_fp var_b = {{0xD6E9CCE2, 0x9B3E2085, 0x5265CCDD, 0x0800F465, 0x110E6329, 0x9D05CE5E, 0x7D0E4756, 0x47F280B9},
	{0x5CC1C0F6, 0x539FCD88, 0xD7B642E9, 0xC9D1D522, 0xCC13255F, 0xBC69576D, 0xF9AD5EE2, 0x9FD64EAC},
	0};
		static ecpoint_fp var_expected = {{0x7731D5A6, 0xA1989D4A, 0x2E82E253, 0x25015DFB, 0xCC1B4CD3, 0xDBED19F8, 0xB49388AE, 0x7DBB1473},
	{0xD587788D, 0x312D6C36, 0x6C8EA25A, 0xD66D7463, 0x607C347A, 0x5E8D4262, 0xF91EF844, 0x16556200},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 148 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 149 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 150 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x04EE8618, 0x3B91F4AC, 0x91123B4B, 0xCA6BBF92, 0x24F3E607, 0x538FBE03, 0x71660885, 0x06295E5D},
	{0x5EDF0B3E, 0x628F9C7F, 0x17EBE18F, 0x0684D3E7, 0x54C97B19, 0x561DB11D, 0x3FF8DBED, 0x7CF39DF2},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x4D526FDB, 0x61B60C1D, 0x3F8069AB, 0x22A5C9E3, 0x31C5DC60, 0x8AC05AB5, 0x497FBB12, 0x33FCBF96},
	{0x775F4845, 0xA375EED5, 0xC3510C18, 0x577F9159, 0x5064E1FD, 0xC73E9BBA, 0x492D9764, 0x081EF368},
	0};
		static ecpoint_fp_proj var_expected = {{0xABC9F888, 0x7D7031D0, 0xFBC0C6CA, 0xBDC1C40C, 0xC6B09CC6, 0xB984A3D3, 0xCC7D5C17, 0xB5E2A7D6},
	{0xFF50602B, 0xF6FC4B9C, 0xDF13C8BB, 0x1FB0281F, 0x3A03EB26, 0xD4A04648, 0x48209740, 0x1D1917AE},
	{0x4863E9C3, 0x26241771, 0xAE6E2E60, 0x583A0A50, 0x0CD1F658, 0x37309CB2, 0xD819B28D, 0x2DD36138},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 151 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 152 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 153 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 154 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xBEA63B6B, 0x3877711F, 0x037A326B, 0x55CE6D98, 0xEFB18AA8, 0x8FC78FCE, 0xD9C81D59, 0x592BC6F0},
	{0xBA7405CC, 0xE5B0315F, 0x98AC4550, 0x37641FC6, 0xD519D54E, 0x52A29A76, 0x8E53A2D9, 0x8C7248BF},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x5D7D4183, 0xF22E36E3, 0x179A6537, 0xA4915042, 0x59CD53A6, 0x56587688, 0x5A76B3EA, 0x1084A24A},
	{0xCBC550C8, 0x5590EE19, 0x742AC260, 0x1BB75A0F, 0xB6491E55, 0xC5903B01, 0xEE6E28D8, 0xB40E2B5E},
	0};
		static ecpoint_fp_proj var_expected = {{0x08B5FA35, 0x2DC10B4B, 0x6433FCAF, 0x64035C2D, 0xB2FCD327, 0x188F0CE4, 0x72730F62, 0x0F714510},
	{0xA1346217, 0x4A18CBDB, 0xAB9D305A, 0x723221EC, 0xB5AF24A5, 0x8F49D4DD, 0x6A98C074, 0x62B4AB03},
	{0x01033AB3, 0xB8A54F75, 0xE8981213, 0x61D48F4A, 0xBDFE52B3, 0xC1F14324, 0xC0CD72B9, 0x716C7A1B},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 155 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 156 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 157 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 158 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x01DE3FAE, 0x2DC05140, 0x55C2A1DB, 0xDE5DC185, 0xACDD19F5, 0x5267473F, 0xF7E04036, 0x91DF3921},
	{0x0B6C7973, 0xFF9B22D8, 0x618128E8, 0x5D799C96, 0x7CA46871, 0xD1FE1362, 0x1D92BD36, 0x66B36F7D},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x19CF8872, 0x56BD703B, 0x824F9987, 0x5B4FC75F, 0x08057E69, 0x0188005E, 0x34C4DAF5, 0x4371D316},
	{0x4FFFE33D, 0x905E607F, 0x4CADF31C, 0x0472A744, 0xAD5B304C, 0xC94AC6FA, 0xE1221061, 0x891C87EE},
	0};
		static ecpoint_fp_proj var_expected = {{0x7373AB04, 0xCEA71548, 0x5C01157B, 0x66E84A01, 0xA59F820C, 0x4196453E, 0x875C38DF, 0x639B5347},
	{0x0CABDF87, 0xE94F31BD, 0x37FC7659, 0x36962AC7, 0xC20F2F0F, 0x60477109, 0x42D295B5, 0x5F095D23},
	{0x7A1D7D5F, 0x27EBA8AC, 0x0104D6F3, 0x9003B27B, 0xAF0AEE28, 0xAA811589, 0x7D0376E7, 0x6BA638B6},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 159 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 160 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 161 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 162 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF96BD26D, 0xC9122748, 0x2E3EC5AB, 0x15984F83, 0x8F907CD2, 0x44BF2A8F, 0x72F206AC, 0x883D7075},
	{0x23A1F286, 0x8BF223B7, 0xE337AEFF, 0x5455F547, 0x75557B9D, 0xCA053829, 0x522723FD, 0xA91EF4F0},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xAB38C889, 0x81D5EADA, 0x26DC5598, 0xDA92DA42, 0xDD34A81A, 0x6745ACAD, 0x01CE93FC, 0xB87F524A},
	{0xAC29119D, 0xA4841995, 0x7CCEBB42, 0x649AE726, 0xB426B16C, 0x9500EB2B, 0x5112D2B4, 0x00755891},
	0};
		static ecpoint_fp_proj var_expected = {{0x819D5F63, 0x7C5B40EF, 0xA28C8051, 0xA70DE671, 0x2E63EB5B, 0xE1E3C986, 0xB548A68E, 0x99A9E4B6},
	{0x064DCE93, 0xEDDB129E, 0x9957107C, 0x161863C5, 0x8EDB7F1A, 0x7B53F674, 0xAF73F2E6, 0xB8477D48},
	{0xB1CCF61C, 0xB8C3C391, 0xF89D8FEC, 0xC4FA8ABE, 0x4DA42B48, 0x2286821E, 0x8EDC8D50, 0x3041E1D4},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 163 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 164 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 165 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 166 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x759D4896, 0x4803682E, 0xC84592E0, 0x718206DB, 0xE115E995, 0x04128E6F, 0xCE6ACE83, 0x66BE102C},
	{0x8894ACA1, 0xAB71CF7F, 0x5BE42C34, 0x64DF8770, 0x4013D539, 0xAF39A368, 0x2AAE2DA6, 0x052C2B45},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x14BBA2C2, 0x75239363, 0x40AC333F, 0x754F4A55, 0xA02966B5, 0x71DAA147, 0x87C39B63, 0x1FBD0A18},
	{0x608B36FC, 0x8F8AEDED, 0xC1322AD6, 0xB47F4D1E, 0xE3F7C222, 0x77E008DE, 0x7291BB31, 0xB56614C0},
	0};
		static ecpoint_fp_proj var_expected = {{0x0C1A82E6, 0x28F216B0, 0x876C9E65, 0x6FA830EF, 0x3B71171C, 0x4A446C88, 0x738CBDE6, 0x7A328D9E},
	{0x55FB00C5, 0xE682B5F8, 0x4FDD0571, 0x1912DC48, 0x43DBED4E, 0x02802422, 0x61F05222, 0x43E1FB18},
	{0x014A8EC7, 0x2C0EB4E6, 0x4CDE7FA6, 0x16DEF01A, 0x12F606D5, 0x69286F43, 0xF977A909, 0x731298AD},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 167 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 168 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 169 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 170 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x062C5284, 0x2B65CBD9, 0x8FB47A80, 0x376CF88F, 0x837C8D69, 0xE8689AC2, 0xD6E4DA4C, 0x4DB23B98},
	{0xCE4AF833, 0xB78D4F90, 0x80D5D0B5, 0xFBD0D66D, 0x0195E91C, 0xFA2AD015, 0x68DBD689, 0xB055875E},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xA71DFCDD, 0x5CE7DB56, 0x30075B43, 0x7765DF16, 0x93FEAF6C, 0x22A5412E, 0xE674AF06, 0x0AF33B9C},
	{0xDB6A5A66, 0x45800379, 0x64EA48D0, 0xC69B6858, 0x4DE33D5D, 0x828413BF, 0x6D8D4E77, 0xB5285E4A},
	0};
		static ecpoint_fp_proj var_expected = {{0xC5C2FC13, 0x72B22641, 0x2F352C2D, 0xB88DAE80, 0x9DFB9CEA, 0xBF4E0782, 0x2C690D2B, 0x3B3C58AB},
	{0x332ED240, 0x344CECDA, 0xFC7BDE79, 0x4008889A, 0x2E97A65A, 0xE22F4C9C, 0x2ACC6A11, 0x6BB3C806},
	{0x031DDEF4, 0x3070992F, 0x74CAC00A, 0x530A9327, 0x6464ABB8, 0x359D02D7, 0x4FAEB0E2, 0x77549EC6},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 171 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 172 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 173 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 174 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xFD806A5E, 0x97EAAC66, 0x3EA23386, 0x81433037, 0x2286C23A, 0xAC7DD0C0, 0x1CE57F93, 0x47127C1F},
	{0x6D12320E, 0x43AC2560, 0xC007D8AF, 0xC070C5A7, 0xC700B3A4, 0xD446E347, 0xBCCB3E2B, 0x5F0AB85C},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xC5C3F4FA, 0x1415634A, 0xAE701C35, 0xBAA21317, 0x569A0A38, 0x8D7822F0, 0xB9A54FC2, 0x35CBCF57},
	{0x29B25A63, 0x62891FC3, 0x039F8CF9, 0x53D914FE, 0xD42C9E18, 0x24D60736, 0x109C7972, 0x505E72D7},
	0};
		static ecpoint_fp_proj var_expected = {{0x9C37F480, 0x862CEBA2, 0x299A6018, 0x34670BA7, 0xD11EE6E3, 0x11A9532C, 0xC63DF045, 0x7053BCE7},
	{0x6058156C, 0x3439348B, 0xC7664942, 0xE51BD55F, 0x924DF245, 0xDDA9F713, 0x3448D6CF, 0xB130FFB2},
	{0x2A6FBF37, 0x7B194095, 0x4445C7F5, 0x4C708F81, 0x87F5D1B3, 0xDC5AAE9B, 0xDCDEAC57, 0xA8CCF1FA},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 175 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 176 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 177 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 178 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xFD491E0D, 0xC6932F4B, 0x58C62980, 0x969833A5, 0x6397804B, 0x5C2CA6F6, 0x6F444AC8, 0x993EC85E},
	{0xB4C8D31D, 0x8B56D462, 0x6266FB98, 0x3A675342, 0xE60EFC25, 0xD76E929B, 0x19DE82A4, 0x255A0F71},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x8A3AE09A, 0x18FF3FAD, 0xCB95708B, 0xD262226E, 0xBDB6F945, 0xE8BA9937, 0x3E646F0D, 0x1541EDFD},
	{0xA09B711B, 0xBE9C2CA5, 0xDB78A8D8, 0xEA8DEAED, 0xE81644BB, 0x98D3626D, 0x8D62F278, 0xB716C411},
	0};
		static ecpoint_fp_proj var_expected = {{0x8E77AE4F, 0xF65632B8, 0x5FEC3F7F, 0x111E8EC5, 0xCF9989CC, 0xBAC2ECFA, 0xF8BF946F, 0x37A24245},
	{0x23168D6D, 0x25CB5E1C, 0x78A05C85, 0x8D2D8B7A, 0x2D6A5D24, 0x7A20AC71, 0x0612E74A, 0x0F9A6856},
	{0xEF1DF728, 0x515A9A12, 0x47472651, 0x4EDB9B6A, 0xAE0202AF, 0x87EE4EAC, 0x0F3F006E, 0x3616C461},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 179 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 180 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 181 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 182 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x65417331, 0xEA1DD075, 0xCCDB3761, 0xCC0EA242, 0xCE298273, 0x58B5C34D, 0x81025730, 0x8DC9F12E},
	{0x65A4DD56, 0x44D09C6F, 0x1873EB77, 0xB4875E20, 0x6D5592FB, 0xC4787B3A, 0x44C3939E, 0x6CBFA5A4},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xDE69AAD7, 0x9FDB2098, 0x292BEECA, 0x8AA42FC2, 0xD0E8FED8, 0xDD43CC08, 0x94F32620, 0x40A38AE2},
	{0x8F784B56, 0x7703271C, 0xAAE7F3FD, 0x2EEE08EA, 0xB7D392BD, 0x8064C784, 0x00608E07, 0x81A174F6},
	0};
		static ecpoint_fp_proj var_expected = {{0xAAF933FC, 0xE2BAFBC6, 0xF84CCA3D, 0x60C3ED2B, 0x5CF95FE8, 0xAC68C399, 0x530DF96B, 0x55D1DD0B},
	{0x811537A0, 0x0A3F3DE7, 0xC050E715, 0x3AEE18F7, 0xDBCDEF52, 0x619F5B42, 0x16890FFC, 0x1AF5432E},
	{0xDB546C41, 0xB4ABD9D4, 0x30C896AF, 0xD1A73A20, 0x56A20619, 0x7FEE6526, 0x540FAB19, 0x6CED3876},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 183 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 184 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 185 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 186 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x18EA0159, 0xEB451456, 0x5534C050, 0x5A41952E, 0x447E540C, 0x067137C4, 0xB777486C, 0x36D786A6},
	{0x090A7736, 0x318C7905, 0x233AA069, 0xB714E7E5, 0x8B1A305A, 0x82C2E10F, 0x04FB36C4, 0x7319A258},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xE51BCF14, 0xB0C240EB, 0x63E8F03F, 0xA018E62A, 0x760AA454, 0xA90845D1, 0xC26325ED, 0x734396E7},
	{0xFE5921CF, 0xEF3C3F59, 0xAF42225C, 0x0E0EA2B9, 0xFAFB5610, 0xC13F5BCE, 0x4EE66B00, 0x17536EFA},
	0};
		static ecpoint_fp_proj var_expected = {{0x3B5CE6BC, 0x725FD20D, 0xCD871A1B, 0x1709B84E, 0xD40F298B, 0xC3DEE63E, 0x91E5684E, 0xB0128385},
	{0xB0C98C35, 0x534EE591, 0x4C5CAEE9, 0x5D9E9FAD, 0x98B29A44, 0x25C8B3BB, 0xA31269BA, 0x314D355A},
	{0xCC31CDBB, 0xC57D2C95, 0x0EB42FEE, 0x45D750FC, 0x318C5048, 0xA2970E0D, 0x0AEBDD81, 0x3C6C1041},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 187 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 188 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 189 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 190 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x54DEC203, 0xAA0E8374, 0xAD31F4F3, 0x224A617E, 0x590D3E48, 0x2141DAD9, 0x3D31C122, 0x04E5D1D6},
	{0x2DFD0761, 0xBA78921C, 0x46CF04CB, 0xABD99118, 0x33A2B994, 0x7538669A, 0x3A029E06, 0x20D63099},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xF0C43C05, 0x1F83552F, 0xFC8AF016, 0x0DE62CEF, 0xC8136689, 0x23B144DB, 0xA32B9670, 0xA8A2DC7D},
	{0x3704427B, 0x75B8B464, 0x1300EC25, 0x55855F07, 0xB9393D4E, 0x8EAFB87C, 0x041FF556, 0x8802C169},
	0};
		static ecpoint_fp_proj var_expected = {{0xF2BA4C0F, 0x364B18D0, 0x4752B889, 0x9353FB04, 0xCA53B62E, 0x0901E705, 0xE33FF437, 0x571BA5A3},
	{0x0DC1B3C8, 0x6176B948, 0x5CCEF9CF, 0x1BCC50F6, 0xAF6CBBD3, 0x6574D939, 0x7016BB4B, 0xACBF7D55},
	{0x9BE57A02, 0x7574D1BB, 0x4F58FB22, 0xEB9BCB71, 0x6F062840, 0x026F6A02, 0x65F9D54E, 0xA3BD0AA7},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 191 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 192 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 193 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 194 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF17829FB, 0xE705A319, 0x7AAB7481, 0xAF751012, 0x3BA3D795, 0x7193852E, 0xB535383E, 0x0FF8A0BE},
	{0xC6CE6BF0, 0x26C4E8E8, 0x66AA8DB7, 0x04131E5B, 0x6359AD0A, 0x78927A57, 0x2D2DE4EC, 0x72D1F984},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xC769C8F1, 0xF3EF1E2D, 0xEE304B57, 0x470D7447, 0xDFD61705, 0x25F39F95, 0xCE4A8243, 0x4477C81E},
	{0x3601C07D, 0x1957B21D, 0xE6F586E8, 0xEECEBB68, 0x59CA816C, 0xB01FB2DE, 0x729799C5, 0x8A560568},
	0};
		static ecpoint_fp_proj var_expected = {{0xEFC8C4F5, 0x12453445, 0xCE78F21A, 0xB7A39636, 0x0BE70028, 0x627C8C37, 0x0531C7A4, 0x96715766},
	{0x491F27CD, 0x5CD3AC06, 0x56679B1A, 0x80B6D43B, 0xB50E39B8, 0xFDD76B23, 0xA7434258, 0x464C3E8D},
	{0xD5F19EF6, 0x0CE97B13, 0x7384D6D6, 0x97986435, 0xA4323F6F, 0xB4601A67, 0x19154A04, 0x347F2760},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 195 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 196 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 197 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 198 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8E1E4018, 0xCE9430D6, 0xFEC885B5, 0x2109709B, 0x137A6725, 0x60FDF2B4, 0x70365E4B, 0x7FFA4AE1},
	{0x7917DC9B, 0x17955DA2, 0xEC84D25E, 0x7977DB90, 0xA51AB830, 0x5D025EF7, 0xFBF1552E, 0x0EDA9BD0},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x2C5E054B, 0xF8E9A60E, 0xE6B50095, 0xB6B9B193, 0x854D868C, 0x75281323, 0x2F38AE2D, 0xAD3E91CE},
	{0x3958FFBB, 0xA026DA9F, 0x2E8F4D40, 0x057A2B19, 0x6C40F8C3, 0x3257B396, 0x9BFBA5F7, 0x18D6C6E6},
	0};
		static ecpoint_fp_proj var_expected = {{0x8B131D1E, 0x75813FA6, 0x7B4EA05E, 0xDFEDB1FF, 0x64A46587, 0x288A1146, 0x1FE1F404, 0x3F6F3750},
	{0x0793BAFE, 0x4D77585A, 0xC6B12950, 0x308FB587, 0x2E23872C, 0x4DD75537, 0xD6810A09, 0xA244F95B},
	{0x9E3FC533, 0x2A557537, 0xE7EC7AE0, 0x95B040F7, 0x71D31F67, 0x142A206F, 0xBF024FE2, 0x2D4446EC},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 199 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 200 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 201 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 202 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x4CE4540D, 0x214112E5, 0xB5534B56, 0x8A710141, 0x891A99BB, 0xBF485885, 0xC059548E, 0x172E27C8},
	{0xA21AD03F, 0xC1881539, 0xB335E8DD, 0x48F07CB0, 0xCF4A6B92, 0xEE5245CD, 0xE2C3CF64, 0x2F899A09},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x68F98173, 0x75190976, 0xB45A5100, 0xE0CF784B, 0x2FD28683, 0x36ADF76B, 0xD6F8A2B1, 0x7B08A4EC},
	{0x214FE97C, 0x5666E52B, 0x98DEEB7B, 0xBA1A6AFB, 0x4EF53E85, 0x19A19FEC, 0x0918909F, 0xA584A8C8},
	0};
		static ecpoint_fp_proj var_expected = {{0x1F03FD6D, 0x8820BED8, 0x5E6C9C1E, 0x9BEF3C1F, 0xCB2CE06B, 0x15B4EA2C, 0xE0BBF439, 0x476A1FC1},
	{0xD1D4311E, 0x9501F619, 0x38CAC7D0, 0x0D3A718E, 0xD12D677A, 0xD4EDB7AA, 0x3B51EEA8, 0x1202DC70},
	{0x1C152D66, 0x53D7F691, 0xFF0705AA, 0x565E7709, 0xA6B7ECC8, 0x77659EE5, 0x169F4E22, 0x63DA7D24},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 203 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 204 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 205 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 206 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x9E6A4D43, 0x69360AD6, 0x5795A4D6, 0x0895C299, 0xB7C1B8AC, 0x69252BCA, 0x62D8C8A8, 0x459F13DD},
	{0x73C07B61, 0xB24BF743, 0x24A03330, 0x83325FDA, 0xE0F56E4F, 0x8FBEA0AC, 0xD3E2D803, 0x469F7F2D},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x892F7B57, 0xDFCB9EF9, 0xEA7CD914, 0x56B5704A, 0xCD75D706, 0xE5A56316, 0xCDF4D88D, 0x44992892},
	{0x26458E98, 0x380879F3, 0x7F9E6C13, 0x861988AD, 0x5E3B9A5F, 0xCA29818C, 0xCAEB4CBC, 0x107B5595},
	0};
		static ecpoint_fp_proj var_expected = {{0xA4124491, 0xFE968EDA, 0x995E4CDE, 0x144A31C7, 0x6B153E47, 0x9F2EA718, 0xAD5CCF5E, 0x64AD366B},
	{0x6FF6B02F, 0x3A9AFC75, 0x66A9445C, 0x0810AEAB, 0xC4D7832F, 0x2652DC47, 0x6350EBC9, 0x782AE0A9},
	{0x4CF162AF, 0x75841DD4, 0x675F1385, 0x61315A52, 0x6996A80F, 0x77E093B7, 0xAB3AEC0E, 0xB90DB377},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 207 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 208 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 209 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 210 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x9118363C, 0xCC79FE5A, 0xBC1FEA20, 0x27B5FEE3, 0x2C949303, 0xF9957362, 0xD7569854, 0xB51E323A},
	{0x99E0DAE5, 0xE326D1A2, 0xF33222C4, 0xD2BB632C, 0xB090EC6B, 0xBD82D43A, 0x1D294FFF, 0x69F99838},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0xB8178981, 0x30FF771B, 0xE0E192AC, 0x3D7595EF, 0x7652668A, 0x86043FB7, 0x958CD0EB, 0x0BA8C65C},
	{0x32C15187, 0xFB60BE00, 0xA6B5E62F, 0x502FCECB, 0xC3209435, 0xB673095A, 0x1E4DBD40, 0x98C9347E},
	0};
		static ecpoint_fp_proj var_expected = {{0x48E50632, 0x5EDF01DB, 0xB9EA26D1, 0x40366E54, 0xAA309D96, 0x16238909, 0x356F6031, 0x632126A5},
	{0x573A30EB, 0x000951EE, 0xE2808831, 0x5D8BD7B5, 0x210EACC4, 0xD4CC0298, 0x45A82DD2, 0x4D972CCA},
	{0x892B87E0, 0x63740272, 0xF93987D2, 0x28D143AC, 0x9DA05D3C, 0x87CF28C0, 0xFE5514BF, 0x109E32E3},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 211 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 212 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 213 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 214 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8BD448CC, 0x40197C3D, 0xCBF28A82, 0xA98641A7, 0x1B30B64A, 0x5D9D2B0B, 0x60D028B7, 0x8433C5B5},
	{0x58B88688, 0x78013B9E, 0x008A6E82, 0xC660A69B, 0x012F6920, 0xBD851A5A, 0x5892C3A7, 0xAD1EC719},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x8BD448CC, 0x40197C3D, 0xCBF28A82, 0xA98641A7, 0x1B30B64A, 0x5D9D2B0B, 0x60D028B7, 0x8433C5B5},
	{0x58B88688, 0x78013B9E, 0x008A6E82, 0xC660A69B, 0x012F6920, 0xBD851A5A, 0x5892C3A7, 0xAD1EC719},
	0};
		static ecpoint_fp_proj var_expected = {{0x78F9414F, 0xD03CE877, 0x1D3F3C67, 0xF80630E1, 0xC693B69A, 0x31C2C0D1, 0x9E47C8B9, 0x19441837},
	{0x4A266577, 0xEB2FD324, 0x8CEDD090, 0x64852EDF, 0x2189A6F5, 0x37F1CF28, 0x924CDFF8, 0xA62818F5},
	{0x4F44D875, 0xF113ED8B, 0x2C9CFDBD, 0x79AFA095, 0xAE7C488C, 0x7FA9D848, 0x7106AB26, 0xA029EF70},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 215 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 216 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 217 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 218 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x769AC4F7, 0x4027741F, 0xCF5BD27E, 0x24545A17, 0xC22D627A, 0x2955631C, 0xA74943AC, 0x96C7A913},
	{0xD6509DDF, 0x123DDF4A, 0x6838F9DF, 0x62A96131, 0x409E295C, 0x2EF70AC6, 0x90DF7281, 0x4ABCA1E7},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp var_b = {{0x769AC4F7, 0x4027741F, 0xCF5BD27E, 0x24545A17, 0xC22D627A, 0x2955631C, 0xA74943AC, 0x96C7A913},
	{0xD6509DDF, 0x123DDF4A, 0x6838F9DF, 0x62A96131, 0x409E295C, 0x2EF70AC6, 0x90DF7281, 0x4ABCA1E7},
	0};
		static ecpoint_fp_proj var_expected = {{0xB1E865EB, 0xC4B40033, 0xE4FB5605, 0x124A0188, 0x29C5B797, 0xE4D5491E, 0xE9A1C876, 0xAE2761EF},
	{0x37F197A7, 0x31C6B20A, 0x5173C33D, 0xA8F2EFB7, 0x4209C70F, 0x7D1A76E4, 0x14BFC532, 0x9CD547E9},
	{0xACA13BBE, 0x247BBE95, 0xD071F3BE, 0xC552C262, 0x813C52B8, 0x5DEE158C, 0x21BEE502, 0x957943CF},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 219 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 220 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 221 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 222 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA7C14940, 0xC43CEDAC, 0xEB244D16, 0xC554DE73, 0x066FAC0A, 0xD985DE92, 0xC5C0003F, 0x92C1A73F},
	{0xAD0A245E, 0xDCC8A36F, 0x49BE37B4, 0xBD164670, 0x9E997A83, 0x1423E7C5, 0x7F15F366, 0x2635D62F},
	0};
		static ecpoint_fp var_expected = {{0x14B32DA2, 0xA7699686, 0x45C0CABD, 0xCAEA9D0D, 0xFB297A97, 0xAD2BD904, 0xEBB1DECC, 0xB739B66F},
	{0xFAE62B09, 0xE81AFC94, 0x76486D89, 0xC3EE0BCD, 0x6A76D2AD, 0xD3DD8F63, 0x0310C227, 0x77D46265},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 223 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 224 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 225 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3A120D4F, 0x7CC7F6C7, 0x043331E5, 0xF76256A7, 0xC405618C, 0x70C357CF, 0xF56FA7CA, 0x8AAF792B},
	{0x473DA495, 0x5FD3DD2F, 0xC3E36E5D, 0xEEC7CFFE, 0xBC7D93FD, 0xFD878195, 0x6F28DE92, 0x7170D771},
	0};
		static ecpoint_fp var_expected = {{0xE3247240, 0xD803E662, 0xD2238E36, 0x6F8D4D64, 0x16FF50E3, 0xCF747F1B, 0x0F2FEC75, 0x7817B264},
	{0x26176C34, 0x13CE9C2A, 0x43B41ECA, 0x5BF33E8B, 0x078A699E, 0xB37788C4, 0x5AB1B584, 0x644D761A},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 226 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 227 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 228 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAA1BB2A8, 0x6198759A, 0xDD71DADA, 0x255E810C, 0x6FBC4FB3, 0xC319CF04, 0xC6AC5B2E, 0x5B8B5315},
	{0x7B8B7782, 0x6B334C8D, 0x6D62A920, 0xE7E84E4F, 0x209AC6D4, 0xDFAA0383, 0x8E70D570, 0x7DD427A7},
	0};
		static ecpoint_fp var_expected = {{0x1BA499A8, 0x47D13090, 0x157C1DE4, 0xBF2E718F, 0x06D8CCCA, 0x1627050D, 0x360332A2, 0x160C7855},
	{0xBE4963B9, 0x04C7FAD9, 0x36667072, 0x35E2117C, 0x6CCBDA25, 0x57F25150, 0x6A10BAE0, 0x8CF6376D},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 229 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 230 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 231 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x98E73A9B, 0x8C9A929C, 0xD86E1275, 0x3C3946A9, 0x724A2A6B, 0x8CC8CFE1, 0x9B7975B2, 0x526C4E90},
	{0xD94354C5, 0x67297C57, 0x5508A12D, 0xE5CCE8E7, 0x262C8CC0, 0xE552A4CB, 0x0C7C7BA0, 0x356328E4},
	0};
		static ecpoint_fp var_expected = {{0xB7FD0776, 0x25DCECC4, 0x2F09486F, 0x571E4FF4, 0xB023CAA7, 0xCA2E1B2E, 0x66954C8C, 0x080C8A73},
	{0xCB06AB79, 0xA2720610, 0x15783012, 0x9EE898F8, 0x0BA294A6, 0x66090B4D, 0x8BC13A21, 0x0F6C37A8},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 232 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 233 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 234 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1F260DFB, 0xDB750E85, 0xAE33591D, 0xBA697415, 0x62C8EF2A, 0x36C4A4C0, 0x0D3A627A, 0x67F2511E},
	{0xDA6B9F1D, 0xB8DFD406, 0x4D577460, 0xD692E315, 0xC84173D2, 0xE3736A2A, 0xBA0B6BDB, 0x82B40A77},
	0};
		static ecpoint_fp var_expected = {{0x7C589484, 0x9B627A17, 0x06A65CAE, 0x565BD700, 0x27E95E46, 0x6976DD98, 0x50224C1C, 0x031242A7},
	{0x7E1BB290, 0xF57601E2, 0x103051DF, 0x7FC5EEEF, 0xE0805083, 0xDADF532F, 0x88CBE833, 0x4AD72445},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 235 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 236 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 237 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9E8AB239, 0x1ABBC267, 0xAEBB1E4F, 0x1059E339, 0xCA27C912, 0x55164FDE, 0x4B192628, 0x7A78F058},
	{0xB6B2ADA1, 0x1B909058, 0x68DB9E87, 0x3A821CC2, 0x969DF67E, 0xAD6BEE5A, 0x79E8078C, 0x83D89B8A},
	0};
		static ecpoint_fp var_expected = {{0x31FDDD37, 0x8CC39A32, 0xF478CD9C, 0x2033E83D, 0x540C36A0, 0xD1DCF7B4, 0x043D13DD, 0x9D400372},
	{0xD9C1B13C, 0x28CF54D0, 0x7A33E3DE, 0x2DD68B12, 0x3663B11F, 0x285D5597, 0x4BAF9058, 0x5457A87D},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 238 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 239 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 240 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD984FCEE, 0xBF7223A7, 0x153C590E, 0x952D7916, 0xC67A6996, 0xCEF88E4B, 0xC422335D, 0xA1A00A23},
	{0x6E1B0D6E, 0x9EABD72B, 0xAF546042, 0x5B3CB4FD, 0x56BA7F37, 0x01F5336C, 0x2CD8BAD7, 0x93B0932C},
	0};
		static ecpoint_fp var_expected = {{0x1C00E9B0, 0xA49924B0, 0xEDB49FCA, 0x768E560A, 0x31A973CC, 0x88A08618, 0xA69CE3CE, 0x4AA4D088},
	{0x143539D3, 0xD2BC0735, 0x60E67704, 0xB06C0E5F, 0x3FA33999, 0x7B4BA8F9, 0x518A77B4, 0xA8208C3B},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 241 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 242 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 243 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x09E27B20, 0x733BB024, 0x5C1048DA, 0x506045BF, 0x12E7A068, 0x8D789DDA, 0xFCE9F276, 0x9108CD3F},
	{0x3590C491, 0xC80F5B7A, 0xD52E2E50, 0xF0E0A715, 0x1588ED6C, 0x59C75444, 0x17213C18, 0x0F633064},
	0};
		static ecpoint_fp var_expected = {{0xB407D7F0, 0x3DD9E137, 0x898187C5, 0x9206B733, 0xD841481E, 0x448B2A9A, 0x0E0B37E0, 0xB03E57D5},
	{0x86871FCB, 0x48D00CCC, 0xBE5C16C2, 0x4B73C71A, 0x6D95E3AD, 0x8E31B719, 0x2C158465, 0x1D437E65},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 244 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 245 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 246 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2D1E3ABC, 0xFD9FB977, 0x4D8C875F, 0x9934B8AA, 0x3C593371, 0xAEF71643, 0x5539E75A, 0x183DA659},
	{0xFD1456FA, 0x6D50606D, 0x767E1B8F, 0x94221CB2, 0xD5EA6D93, 0x6E36B660, 0xB2094B6F, 0x8D5C9761},
	0};
		static ecpoint_fp var_expected = {{0xB5CF0551, 0x99F9014A, 0x1CF7DE18, 0x8E04553B, 0xE5D04477, 0x0B1813FA, 0xBF10C779, 0x0CC729A0},
	{0x99D5AC07, 0x4D35639C, 0x3127F345, 0xB394F348, 0x890D6BBD, 0xE1789975, 0x4C34C308, 0x0890FDA6},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 247 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 248 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 249 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1962B6BF, 0x90F7B088, 0x0DC41847, 0x0FFCF56F, 0x7729846E, 0x248C1700, 0xEB41D1F3, 0x09C96506},
	{0x58F3C88A, 0xBE7E0BB1, 0xDB3DCD86, 0x2F3FAF9E, 0x6F983F72, 0x0BA3EF89, 0xE1C0C79B, 0x0AAEE8BE},
	0};
		static ecpoint_fp var_expected = {{0xADB699C7, 0x2A518E1A, 0x34113926, 0xA4A925B6, 0x98624982, 0x3E6CF2D1, 0x2018CC00, 0xA06DDDF1},
	{0x023DC009, 0xE17FDD27, 0xBA6C83E3, 0x281A9857, 0x6B75EB05, 0x7C03ED4E, 0x91FDC2DC, 0xB5E87DEE},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 250 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 251 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 252 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0EC6CE40, 0xD161B313, 0x69DB0E87, 0x7E906A29, 0x2F71B90C, 0x2390EA5A, 0xC83BF121, 0x38DDAADB},
	{0xF0D653D5, 0x4E46AC92, 0x01EAB599, 0x3FCCB97D, 0xB4A2595C, 0x0B416883, 0xC376EDFB, 0xB866760A},
	0};
		static ecpoint_fp var_expected = {{0xE5FD4C9B, 0x92BF83E6, 0x24B5715B, 0xB62F5D7A, 0x36B29C00, 0x95EE0545, 0x0A8F49A9, 0xAE99C459},
	{0x015C5D59, 0xBDE3FD5C, 0x79ED8E9C, 0x626A761E, 0x4717E6DC, 0xABD330DE, 0x2019A51E, 0xA96711ED},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 253 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 254 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 255 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4E421B01, 0x2BB0460D, 0x7AAAAC4A, 0xDC72C409, 0x31ADFDBF, 0x84B291D6, 0x198A1B1A, 0x47A5F6D1},
	{0xBBF04ED4, 0x44A4109D, 0x1F4DC20E, 0xCFD58361, 0x2B463F45, 0x3FFA760C, 0xFA0D543E, 0x3D21220A},
	0};
		static ecpoint_fp var_expected = {{0xFD48F66B, 0x7DC255A2, 0xE7F2325D, 0xBD9A3D4C, 0x3955CBF6, 0x594B7523, 0x852D902E, 0x55E2374A},
	{0x60944B6B, 0x7F43078D, 0x82377327, 0x26B5E143, 0x6F9CD22B, 0x098E20A5, 0x37A3539F, 0x401B6E22},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 256 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 257 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 258 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC339EFC4, 0x17F76244, 0xF54D35A7, 0x3BBA9FA8, 0x9567EA5A, 0x703CD42B, 0x8FCE15FA, 0x629FAFFC},
	{0xE41DED3E, 0x3DCE89E3, 0x2C9003E6, 0x0D65C41F, 0xC12B4EF4, 0x54BAA96B, 0xC99E8D90, 0x205BF477},
	0};
		static ecpoint_fp var_expected = {{0xC8129EFB, 0xAD0A182C, 0x45BBB013, 0xC574F79E, 0x80D1221B, 0x00C87E43, 0xA09788EF, 0x0BF9F0A9},
	{0x3B9B036E, 0x2A81ACDE, 0xB03599BA, 0x543679F5, 0x889B6AF7, 0x77FFAA9A, 0x6A8542FB, 0xB54EE21C},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 259 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 260 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 261 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xEECAAF8A, 0x3730A2F5, 0xAB5D4AB5, 0x74688BC8, 0x4CFCCE18, 0xF3CA0C5A, 0xC5802C7F, 0x6D7C4495},
	{0x9BF56C3F, 0x254F23BA, 0x1A0F50BA, 0xABD69401, 0x6CEE3172, 0x06693076, 0x828430EA, 0x7E2E39D4},
	0};
		static ecpoint_fp var_expected = {{0x3B7B64E3, 0x76AE4706, 0xB9E04A12, 0xA63DE543, 0x1F49DD0B, 0xF00974A5, 0x5173F1DB, 0x665FD662},
	{0x7149701A, 0x35B5DB12, 0x608E0064, 0xA2C31CDB, 0x0616A82E, 0x2AB73DB5, 0x370496DE, 0x490A3E85},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 262 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 263 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 264 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x16F1AB59, 0x1A317706, 0x9884149A, 0x5FC8066E, 0xA86DB7C4, 0xA8FC3491, 0x33F5C5E1, 0x1B30C27C},
	{0x49E917A0, 0xD5B9E4FC, 0xDE26D774, 0x63A3CAF5, 0xC1D91B97, 0xEE8D09E4, 0x83CD41E1, 0x95A629FB},
	0};
		static ecpoint_fp var_expected = {{0x7FEC319A, 0x40069AA4, 0xB53A2B05, 0x8EC7CDDA, 0x47968945, 0xE5504B7C, 0xE13E6D3E, 0xA291EE2D},
	{0xFA0B06CF, 0x1034EF52, 0x5C66EB87, 0x45458101, 0x467C655C, 0xBA996B7C, 0x83003E77, 0x017A68E1},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 265 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 266 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 267 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA79D800D, 0x354F99FA, 0xEEF75C64, 0xD379F6FF, 0x2E6DDFED, 0x46B825E1, 0x8B67AF7E, 0x5FBB8741},
	{0x8AFF2F0F, 0xC01DD199, 0x45890B6C, 0x804B7E01, 0x0DDC2943, 0x532773FE, 0x783DBCB4, 0x4D1AC451},
	0};
		static ecpoint_fp var_expected = {{0xF984A370, 0x02CC5170, 0x957B435C, 0xF60F45E3, 0x28D8BB60, 0xDDBA48F4, 0x32FF75B5, 0xA36C03F0},
	{0xD28AB3F9, 0xA7B9177B, 0x33F82F01, 0xE1D1FAD1, 0xF4456264, 0xFA879C24, 0x4064375B, 0x8AD7121E},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 268 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 269 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 270 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x81EA590B, 0x3D9AD1FC, 0x67FE8281, 0xAAC093F6, 0x4F530B20, 0x238EFA15, 0x93FC9578, 0x0F9BB59F},
	{0x075B635E, 0xBFE56803, 0xDAA78F5A, 0xEB966BD0, 0x2185B645, 0x721B4440, 0x8140A339, 0xAF72A8A9},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x50E2C5F8, 0x671E368A, 0xD6FB8BFB, 0xB32A9F89, 0x382F1EE5, 0x33C19FE0, 0xAD54DE22, 0x03D161EE},
	{0xD6431A94, 0x7B2377DE, 0x08BFBB5B, 0x75677C29, 0xC982B1D6, 0x886F9772, 0x379F17FE, 0x94EEF55B},
	{0xAC8A9221, 0x80DC4654, 0xE0D73F6E, 0xC41B2B00, 0xEF28E2D6, 0xE8D62C14, 0xC2626A49, 0xA4D1B290},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 271 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 272 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 273 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 274 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7426BBED, 0xCCEE1A9F, 0x8548D9E9, 0x20578758, 0x8C4260C5, 0x1732F93F, 0xF5448F32, 0x58EFA849},
	{0x323173BC, 0xDDBD7A5E, 0xF6D05576, 0xD4A54032, 0x5B7CC3B1, 0xF2CC8B98, 0xABC18A29, 0x7B4316A7},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x43CDC378, 0x15954AE9, 0x9ECADF01, 0x3BBB335E, 0xD9E40823, 0xFCB38361, 0x3798D955, 0xB51BD523},
	{0xD387930E, 0x502A8BAC, 0x0AA3E802, 0x239BBA06, 0x0DDD24DA, 0x6E01EDA5, 0xC548E03F, 0x82E50864},
	{0x0236B2DD, 0xBC8C6B0B, 0x1928CBA6, 0x9638D3C5, 0x6316FDAE, 0xEA38BAC5, 0x1764382A, 0x3C728E8D},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 275 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 276 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 277 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 278 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE78E9B54, 0xD72B9AAE, 0xF34F53D8, 0x7A7220E5, 0x93CA1A77, 0xA2A1EF6A, 0xC6B2B991, 0x924C6C54},
	{0x037928C5, 0x1721C695, 0xF6C645DC, 0x2B34A9B9, 0x54C2F376, 0x22B24706, 0x49EEA83B, 0x945E769A},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x0EBA3469, 0xD9B46E87, 0xDD9E24EF, 0xD727442F, 0xFB40763A, 0x3416B7F2, 0x7C36A135, 0x6824526D},
	{0x9BC834FB, 0x66F00D37, 0xCD9169A5, 0xE6DB3CDD, 0x0EE1502D, 0xF2898D71, 0x3904F33F, 0xA6A37E89},
	{0xA4C61CEF, 0x2F550378, 0x1914AC71, 0x4357A6D3, 0x55A35D37, 0x4A0431A1, 0x53BE744D, 0x6EA94E72},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 279 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 280 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 281 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 282 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE6AFC555, 0x2591C187, 0x78E2B3BE, 0xBC5092EC, 0xCC264E76, 0xE5D30494, 0x84C89400, 0x90E660A7},
	{0x74D505AC, 0xA1C9CB60, 0x276559B0, 0x57BEFD4D, 0xB748BA3D, 0xB6551C24, 0xBA3C82DB, 0x51C1564C},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x04D29502, 0x8A5F1540, 0xBD779F63, 0x9B2C5CDF, 0x8AAD9A04, 0x42D69380, 0x1E907E4B, 0xA6079E58},
	{0xF786E377, 0xE414978D, 0x9C51D4A4, 0xCB224696, 0xF9539903, 0x17BFE262, 0x23C7F5D4, 0x7570F3DF},
	{0xE9AA0B58, 0x439396C0, 0x4ECAB361, 0xAF7DFA9A, 0x6E91747A, 0x6CAA3849, 0x747905B7, 0xA382AC99},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 283 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 284 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 285 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 286 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x9CD270AA, 0x819A0EFA, 0x352D027A, 0x677F9459, 0x0F79BE5F, 0x5E52C359, 0xB0EDE31D, 0x42084E7D},
	{0xFA6337DE, 0x61BE5999, 0x9C948AED, 0x17DD7FAE, 0x0EBB7EAF, 0x52D95635, 0xB5DEF50A, 0x2F68CAB6},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0xB6C41422, 0x44717930, 0x346EA095, 0x91E9AF25, 0x7490957F, 0xCF23B887, 0xB8BCAE18, 0x1830BD1B},
	{0x7B2A5A42, 0x3628F2B0, 0x6CF30A54, 0xF29B3FA6, 0x00831CCC, 0xCC64E20E, 0xF8EF100C, 0x48E654AC},
	{0xF4C66FBC, 0xC37CB333, 0x392915DA, 0x2FBAFF5D, 0x1D76FD5E, 0xA5B2AC6A, 0x6BBDEA14, 0x5ED1956D},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 287 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 288 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 289 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 290 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xDFF9EA3D, 0x6C53CF43, 0xDD97DF12, 0xACB4EF4C, 0x6609B0DC, 0x4EAE9073, 0x60BA5CAD, 0x126E6347},
	{0xC9A6F463, 0xC288D892, 0x70C77DD8, 0x0F2F8C48, 0xD4243D30, 0x5B083298, 0x30E0A937, 0x69D77311},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x5E641A98, 0x67D6FFC5, 0x07C7CAC2, 0x1363EFE7, 0x93369627, 0xBEF087E3, 0xD31B7B0A, 0x0EE9FDE5},
	{0xD6AD039A, 0x2442FB34, 0x64089B03, 0x19C925B4, 0x79976EE0, 0xE9F23539, 0x3A9EAF6A, 0x17D84744},
	{0x3121B42B, 0x86232774, 0x0D171C6A, 0x0B4D6BF0, 0x5465F0AB, 0xBAB008C6, 0x21A27645, 0x199B4760},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 291 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 292 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 293 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 294 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x31136D1F, 0x3398D55A, 0x287F56DA, 0x06D41365, 0x38BA893A, 0xC043507A, 0x917290C3, 0x471DDD65},
	{0x32D4AABA, 0x8CA907BF, 0xB011405E, 0xD68D8FC7, 0xEC5600AA, 0xD3316A52, 0xFAF48D3E, 0x14240944},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x0604A73E, 0x1B7B83D4, 0x08C38AF6, 0x25443FC1, 0x22CFA567, 0xD817EC43, 0x57AC6FDC, 0xA875027A},
	{0x19055565, 0x282B58A8, 0xCD7FD832, 0xECA42A33, 0x85E34300, 0xAD862682, 0x8F9A21D3, 0x971BA0FD},
	{0x65A95574, 0x19520F7E, 0x602280BD, 0xAD1B1F8F, 0xD8AC0155, 0xA662D4A5, 0xF5E91A7D, 0x28481289},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 295 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 296 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 297 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 298 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x52252604, 0x660D4318, 0xE83FDB64, 0xA4884834, 0x6F6BA163, 0xBAD97E39, 0x0BBA8FBC, 0x51140AF8},
	{0x71A52B2B, 0x33E5047E, 0x7D2FA0F3, 0x0CA37BC2, 0x8D7E050A, 0xB36EB172, 0x59217CCC, 0x7175DAB8},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x12ACA341, 0xBDCB154E, 0x4F245711, 0x9C42F4C4, 0xED403ECD, 0x01905C2F, 0x97F43105, 0x1400786F},
	{0xE273F31F, 0x58C11D0E, 0x7F6E2579, 0xA7EB2195, 0xD9032230, 0x45EA5BEE, 0x188EB757, 0x23826F08},
	{0x811E21BB, 0x68DB7F4B, 0x25E7629F, 0x06354AE4, 0xC719805F, 0x6B7D0679, 0x72241D70, 0x28D816AE},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 299 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 300 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 301 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 302 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xD28D22AE, 0xE820D457, 0xEA0B44AA, 0xDF8915F7, 0x2AA87505, 0x8E775B4F, 0xDEB13ED1, 0x73C80C88},
	{0x5162ECDD, 0xF753BEAF, 0x0005C7B9, 0x50528EAB, 0x8FBA683A, 0x81B6FCD1, 0x88AE73B7, 0x95E25B34},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x5135C76D, 0x426B4F93, 0x9C31ED51, 0xC1212E6F, 0xA52135F2, 0xA133E11C, 0xD1781CB5, 0x66A66243},
	{0x97EAEDCC, 0x5FAE5C11, 0x80A3F497, 0x25F67644, 0xF9B8BE39, 0x631160E2, 0x18C32B71, 0x67B2E79E},
	{0x4099A51F, 0xEFB8F3AD, 0x2B93B02C, 0x8D9370B5, 0xCB9246BF, 0x080D9D37, 0xD13E0B46, 0x71B117A6},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 303 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 304 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 305 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 306 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x3F0BEC1C, 0x63CA1399, 0x3F5B70F8, 0x34C037DB, 0xEF9D2744, 0xFAFCDBFD, 0x85C81691, 0x3C68DB72},
	{0xF7C63432, 0xA1E227E3, 0x25DAF9FD, 0xE0510B4A, 0xC12E8A67, 0xBC13FB81, 0x55C020FE, 0x84B23DE2},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0xDFFFE81D, 0xD776A18E, 0x08A89050, 0x809F855D, 0x6D5FFBAB, 0xB281069E, 0x78A15BBA, 0x0EB9D813},
	{0xAC54DC75, 0xE7C975B2, 0xF7DB9C26, 0xF1D2FBD1, 0x1B509F66, 0x10E0C825, 0xDB216D98, 0xA6017C48},
	{0x8D6033C9, 0x44D5C616, 0x773E14B4, 0xAD9069F3, 0x2E7A8B1A, 0x7CC79A98, 0x6B6165D4, 0x4F50DD02},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 307 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 308 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 309 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 310 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x40978F43, 0x9E8DD3AD, 0xCF65419F, 0x93ED9980, 0x2C4DE5E7, 0xE0923D82, 0xD07F96A7, 0x437152E6},
	{0xD77FA7B2, 0x88E54284, 0x404F552A, 0x3D0022B8, 0x7B29E2D6, 0x6630ED72, 0xB8593D0A, 0x33928453},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0xD1831F80, 0xCBB085CB, 0x5BCA1346, 0x55B3404E, 0x2812A45A, 0x808A51E7, 0x7A6A5FC4, 0x91FBC2C0},
	{0x168CDD46, 0x59091783, 0x531F6C6A, 0x3ED2037B, 0x9DDB7061, 0xE21A4CE9, 0xDB8F4F4E, 0x194C713D},
	{0xAEFF4F64, 0x11CA8509, 0x809EAA55, 0x7A004570, 0xF653C5AC, 0xCC61DAE4, 0x70B27A14, 0x672508A7},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 311 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 312 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 313 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 314 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x2D86E644, 0xFB74FA3E, 0xE8FADFDD, 0x5CE35274, 0x2076608F, 0xDB07333D, 0x3BA32AAE, 0x0008201F},
	{0xC76D5816, 0x8DEAC38E, 0x08610308, 0x4850A026, 0x90CB180B, 0x231A2556, 0x54382D46, 0x5E5F50ED},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0xBB514ED8, 0xB5A83B55, 0x4FA524BF, 0x340DF7DE, 0x7A0F9DF2, 0xFF6144F4, 0xB8F2620D, 0xADC9924C},
	{0xFD5700A9, 0x2048FC95, 0xA3972E1D, 0xE5EA1F74, 0x5E9C9A95, 0xB06F8856, 0x75F17984, 0xAE427A4C},
	{0x2CAE7B91, 0x1CE6FD6C, 0x3C4A26CA, 0x7D8F93AB, 0xCDB3A661, 0x4AD3EE41, 0x68517E63, 0x02AB0318},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 315 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 316 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 317 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 318 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE1E36A31, 0x74FF09EA, 0xF4582B8A, 0x3A2F3D92, 0x40387FF7, 0x1838C0C9, 0x54B566F8, 0x2D00BCDB},
	{0x0E4A1221, 0x604F1E57, 0x93478017, 0xAEC3E184, 0x51FD0605, 0xBA3BDD5D, 0x2C02C8D0, 0x2768BDE5},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x0F4A02C8, 0xF2C5E539, 0xC1D82F6F, 0x3B48959D, 0x6DACECF9, 0x82A542E7, 0xB28991A8, 0x63270CD7},
	{0xF44217A4, 0x7185241B, 0x17049561, 0x1FE9F73B, 0xC84240CB, 0x5D70FAEC, 0x3E090285, 0xA322389A},
	{0x1C942442, 0xC09E3CAE, 0x268F002E, 0x5D87C309, 0xA3FA0C0B, 0x7477BABA, 0x580591A1, 0x4ED17BCA},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 319 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 320 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 321 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 322 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7D6B29A1, 0x6DDFDC3E, 0xFF9CE30C, 0x42A2013E, 0x487A1329, 0x03995273, 0xB4D61895, 0x748E9120},
	{0x24BC7CF4, 0xAFA850DC, 0x5783CD4F, 0xBFF84435, 0x387632FC, 0xDDFE4253, 0xCF787183, 0x5438E061},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0xBAD49BC5, 0xE668E613, 0x5F7EB845, 0xBACD6E81, 0x4B4B7900, 0x5DFA692D, 0xF3346893, 0x73858EE5},
	{0x754B9C67, 0xE6EE9C2A, 0x797C32A0, 0xD227D166, 0x59DC2718, 0x553D265D, 0x35372D39, 0xACB020CB},
	{0x4978F9E8, 0x5F50A1B8, 0xAF079A9F, 0x7FF0886A, 0x70EC65F9, 0xBBFC84A6, 0x9EF0E307, 0xA871C0C3},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 323 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 324 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 325 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 326 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7EA62B6E, 0xA11E6522, 0xEA17FCE6, 0xBAE356A0, 0xCB082C4C, 0xE3E09D7F, 0x11D3650C, 0x975B45ED},
	{0x9251F2BC, 0xE0AE6EDE, 0x653647F7, 0x65808F47, 0x38E8CB11, 0xE622EC36, 0xFA6FB5CB, 0x1243AD6D},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x53D96BB4, 0xB432599F, 0x72373DFA, 0xF49143E6, 0x998ED42A, 0xAA56F0CB, 0x2A95C2EE, 0x537CAE6D},
	{0x1C840689, 0xA479F06F, 0x07ED6CC5, 0xB5E43998, 0xA5F5C886, 0x32A06D8C, 0xEEFBC2B4, 0x8F327C23},
	{0x24A3E578, 0xC15CDDBD, 0xCA6C8FEF, 0xCB011E8E, 0x71D19622, 0xCC45D86C, 0xF4DF6B97, 0x24875ADB},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 327 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 328 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 329 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 330 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xEC68D6A1, 0x7223B575, 0xE8C0B02F, 0xF175A81F, 0x70BA070B, 0x4BE48085, 0x8CCF69C5, 0x0921D772},
	{0x4BF3CE33, 0x4D6B58E0, 0xA4EE2EA3, 0x361FCAEE, 0xDA0178B2, 0xD5503568, 0x201D7969, 0x87E8193C},
	{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	0};
		static ecpoint_fp_proj var_expected = {{0x2ED3C7EA, 0xAD64A3AE, 0x65239C49, 0x20576C30, 0x4AB05D28, 0xA905237B, 0x851F3D9C, 0xB08306D9},
	{0x89DE7C88, 0xC977A346, 0x5A363ECE, 0x35DC4A53, 0x834C4F0C, 0x5F0533C5, 0x76287D75, 0x99B903D5},
	{0x35BB67CB, 0x9BE8280F, 0x75647DFF, 0x592DE93C, 0x602067AF, 0xAF400E66, 0x001C16AA, 0x55BC93B6},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 331 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 332 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 333 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 334 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x67817C8B, 0x0561FFB1, 0xB6B233A0, 0x8DD03EA2, 0x12FEDF4A, 0xF7817D25, 0x570F4F6F, 0x6B7C380E},
	{0x0FEAB8EA, 0xDA87192D, 0x6D9A4C5D, 0xD91D0627, 0x3BF0AB2D, 0x5D55EE90, 0x0118F9AE, 0x0F4173FA},
	0};
		static ecpoint_fp var_expected = {{0x67817C8B, 0x0561FFB1, 0xB6B233A0, 0x8DD03EA2, 0x12FEDF4A, 0xF7817D25, 0x570F4F6F, 0x6B7C380E},
	{0x52417BB1, 0x24677084, 0x66DD92E9, 0x39F4A679, 0x17F1DE87, 0x9E0A6DDB, 0x3F05E27A, 0xAAD22AC8},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 335 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 336 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 337 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x08598E26, 0x11827529, 0x64C8C525, 0x98EA8C33, 0x079BAFA8, 0x2C122343, 0x461D25C5, 0x0D19F836},
	{0xAE58B42A, 0x66C71DF2, 0x05CFB7DB, 0x73C96B82, 0x40A27B2D, 0x8E663311, 0xECC57F71, 0x4AB1D809},
	0};
		static ecpoint_fp var_expected = {{0x08598E26, 0x11827529, 0x64C8C525, 0x98EA8C33, 0x079BAFA8, 0x2C122343, 0x461D25C5, 0x0D19F836},
	{0xB3D38071, 0x98276BBE, 0xCEA8276B, 0x9F48411E, 0x13400E87, 0x6CFA295A, 0x53595CB7, 0x6F61C6B8},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 338 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 339 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 340 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x18AA4AFF, 0xBF4FC6CE, 0x2FBB3949, 0x82DA4136, 0xE371D7F9, 0x11EB0970, 0x2498C894, 0x185057A1},
	{0xE026E5AC, 0x91BBD39A, 0xB9F8719F, 0x54C2FBE4, 0x35ED942F, 0x19B2117A, 0x7BA0B6A1, 0x86B2C557},
	0};
		static ecpoint_fp var_expected = {{0x18AA4AFF, 0xBF4FC6CE, 0x2FBB3949, 0x82DA4136, 0xE371D7F9, 0x11EB0970, 0x2498C894, 0x185057A1},
	{0x82054EEF, 0x6D32B616, 0x1A7F6DA7, 0xBE4EB0BC, 0x1DF4F585, 0xE1AE4AF1, 0xC47E2587, 0x3360D96A},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 341 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 342 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 343 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3FA192EE, 0x4C157A96, 0x8C940665, 0xF9D82363, 0xB9D815DF, 0xCEF4FD7B, 0x10C6B551, 0x446E8C64},
	{0x8E745DBD, 0x83A85442, 0x909D7E05, 0x752A5419, 0x9221152F, 0x9F4AF990, 0xF6ABDF98, 0x8AB79509},
	0};
		static ecpoint_fp var_expected = {{0x3FA192EE, 0x4C157A96, 0x8C940665, 0xF9D82363, 0xB9D815DF, 0xCEF4FD7B, 0x10C6B551, 0x446E8C64},
	{0xD3B7D6DE, 0x7B46356E, 0x43DA6141, 0x9DE75887, 0xC1C17485, 0x5C1562DA, 0x4972FC90, 0x2F5C09B8},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 344 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 345 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 346 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xCC0C3115, 0x6A794A23, 0xA15E91F4, 0x1F24AF7E, 0xD88F733C, 0x50160BC4, 0xEB94DA7E, 0x64557864},
	{0xBB79C36D, 0xA9A1E05B, 0x8A7A9255, 0x3F891BE4, 0x65BF56A6, 0xC28244FC, 0xAC1E01BD, 0xA1702E85},
	0};
		static ecpoint_fp var_expected = {{0xCC0C3115, 0x6A794A23, 0xA15E91F4, 0x1F24AF7E, 0xD88F733C, 0x50160BC4, 0xEB94DA7E, 0x64557864},
	{0xA6B2712E, 0x554CA955, 0x49FD4CF1, 0xD38890BC, 0xEE23330E, 0x38DE176E, 0x9400DA6B, 0x18A3703C},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 347 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 348 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 349 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x05835D84, 0xDB8BA7B0, 0xDAB7C764, 0xDCD62C5E, 0x45B28A52, 0xCA4E4DA9, 0x08B9D396, 0x37BA8085},
	{0xB368C980, 0x58A7F1B8, 0x00296F57, 0x0BD585F6, 0x2B5E0882, 0xF43C5948, 0xC18952E2, 0x4C995A63},
	0};
		static ecpoint_fp var_expected = {{0x05835D84, 0xDB8BA7B0, 0xDAB7C764, 0xDCD62C5E, 0x45B28A52, 0xCA4E4DA9, 0x08B9D396, 0x37BA8085},
	{0xAEC36B1B, 0xA64697F8, 0xD44E6FEF, 0x073C26AA, 0x28848133, 0x07240323, 0x7E958946, 0x6D7A445E},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 350 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 351 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 352 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7ADD8E67, 0x87C2B256, 0x5F89250E, 0x72AAC4A3, 0x7493D817, 0x42D819E0, 0x6C5A951D, 0xB3941258},
	{0x11013053, 0x07293D5D, 0xA829EDBF, 0x25355444, 0x288276B7, 0xB1FDCFBF, 0x22AA3B58, 0x67A423F5},
	0};
		static ecpoint_fp var_expected = {{0x7ADD8E67, 0x87C2B256, 0x5F89250E, 0x72AAC4A3, 0x7493D817, 0x42D819E0, 0x6C5A951D, 0xB3941258},
	{0x512B0448, 0xF7C54C54, 0x2C4DF187, 0xEDDC585C, 0x2B6012FD, 0x49628CAC, 0x1D74A0D0, 0x526F7ACD},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 353 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 354 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 355 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x26608345, 0x5EE968B4, 0x0626BA58, 0x2E640981, 0x40A418F1, 0xBD0203C7, 0xB0487AE1, 0x8BD4A6FA},
	{0x6152458C, 0x59D18EB6, 0x698AAD6A, 0xDED6A1DD, 0x602215F1, 0x0A317300, 0xEA373FDE, 0x5A7166E9},
	0};
		static ecpoint_fp var_expected = {{0x26608345, 0x5EE968B4, 0x0626BA58, 0x2E640981, 0x40A418F1, 0xBD0203C7, 0xB0487AE1, 0x8BD4A6FA},
	{0x00D9EF0F, 0xA51CFAFB, 0x6AED31DC, 0x343B0AC3, 0xF3C073C3, 0xF12EE96A, 0x55E79C4A, 0x5FA237D8},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 356 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 357 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 358 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5306CE30, 0x7E49BD87, 0x9C085E76, 0xDD77F046, 0xDD82D322, 0x29FD528F, 0xDF93F9D1, 0x54B2FEFE},
	{0xD21D75EA, 0x9EB7313B, 0x7E6C605B, 0x666A4224, 0x3E3AEF6D, 0x3E591BFE, 0xDF9312F3, 0x7127B294},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x5306CE30, 0x7E49BD87, 0x9C085E76, 0xDD77F046, 0xDD82D322, 0x29FD528F, 0xDF93F9D1, 0x54B2FEFE},
	{0x900EBEB1, 0x60375875, 0x560B7EEB, 0xACA76A7C, 0x15A79A47, 0xBD07406D, 0x608BC935, 0x48EBEC2D},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 359 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 360 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 361 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 362 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x699C58D7, 0xBBE96D0B, 0x8BCA2CED, 0x48FB2D77, 0x984C69CA, 0xF2633313, 0x331EC4B4, 0x3778029B},
	{0xF0C63C30, 0x898C61B3, 0x99A8FA43, 0x94499358, 0x9C2D769D, 0x87136605, 0x041AF4D2, 0x780D3F79},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x699C58D7, 0xBBE96D0B, 0x8BCA2CED, 0x48FB2D77, 0x984C69CA, 0xF2633313, 0x331EC4B4, 0x3778029B},
	{0x7165F86B, 0x756227FD, 0x3ACEE503, 0x7EC81948, 0xB7B51317, 0x744CF665, 0x3C03E756, 0x42065F49},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 363 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 364 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 365 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 366 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x1E0537AB, 0xA6DEA505, 0x0A32D74B, 0xFBC05C9A, 0x3493F99B, 0xD29D6303, 0x8547052A, 0x0C9FD98C},
	{0x8B143001, 0x1EA5B483, 0x3E62238D, 0x4B603E1D, 0x91A2E6CC, 0xC0F2281C, 0x47ACF8B2, 0x8CB6696F},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x1E0537AB, 0xA6DEA505, 0x0A32D74B, 0xFBC05C9A, 0x3493F99B, 0xD29D6303, 0x8547052A, 0x0C9FD98C},
	{0xD718049A, 0xE048D52D, 0x9615BBB9, 0xC7B16E83, 0xC23FA2E8, 0x3A6E344E, 0xF871E376, 0x2D5D3552},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 367 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 368 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 369 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 370 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x05D0967B, 0x7F156BE9, 0xEF6B4C31, 0x20C5EA35, 0x198DCDAC, 0x1C6E9F8C, 0xA2D87D19, 0x1C03F1DB},
	{0x51A1D741, 0xEE74277C, 0xDA94905A, 0xEF85FF09, 0xD4692F25, 0x51720B0E, 0xDA4B8D05, 0x362D1126},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x05D0967B, 0x7F156BE9, 0xEF6B4C31, 0x20C5EA35, 0x198DCDAC, 0x1C6E9F8C, 0xA2D87D19, 0x1C03F1DB},
	{0x108A5D5A, 0x107A6235, 0xF9E34EEC, 0x238BAD96, 0x7F795A8F, 0xA9EE515C, 0x65D34F23, 0x83E68D9B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 371 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 372 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 373 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 374 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x056A0DF1, 0x131A827D, 0x58F3CA3B, 0x877244BB, 0xEE1B19D7, 0x1F80CFC0, 0xAECD3246, 0x4BAD8E1E},
	{0x8E73DB84, 0x53BAD06D, 0x69E856FF, 0xC7A3449C, 0x723C7670, 0x86DB4AF2, 0xC63E9349, 0x6CDA5157},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x056A0DF1, 0x131A827D, 0x58F3CA3B, 0x877244BB, 0xEE1B19D7, 0x1F80CFC0, 0xAECD3246, 0x4BAD8E1E},
	{0xD3B85917, 0xAB33B943, 0x6A8F8847, 0x4B6E6804, 0xE1A61344, 0x74851178, 0x79E048DF, 0x4D394D6A},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 375 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 376 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 377 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 378 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xD1585FBC, 0x02B2A57C, 0x6AFDE050, 0x7B83D8FB, 0x7B163336, 0xB3507816, 0x142C100E, 0x49C49D5C},
	{0xE9AC73AD, 0xCD83F25C, 0x4238F638, 0x052466E8, 0xC2C5CE68, 0xF139AF98, 0x838F0C10, 0x72BA53B6},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xD1585FBC, 0x02B2A57C, 0x6AFDE050, 0x7B83D8FB, 0x7B163336, 0xB3507816, 0x142C100E, 0x49C49D5C},
	{0x787FC0EE, 0x316A9754, 0x923EE90E, 0x0DED45B8, 0x911CBB4D, 0x0A26ACD2, 0xBC8FD018, 0x47594B0B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 379 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 380 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 381 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 382 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xEBA2BBAD, 0x932C3637, 0x44436A33, 0x53EA91AF, 0x535CAEF0, 0xBB7ABBA4, 0x71FA56AD, 0xA6A92F7E},
	{0xCDCD5A0A, 0xB15BB019, 0xF3A7CE1A, 0xE8B66654, 0x5F4BB8F9, 0x7C3EF980, 0xA00637AF, 0x27084D92},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xEBA2BBAD, 0x932C3637, 0x44436A33, 0x53EA91AF, 0x535CAEF0, 0xBB7ABBA4, 0x71FA56AD, 0xA6A92F7E},
	{0x945EDA91, 0x4D92D997, 0xE0D0112C, 0x2A5B464B, 0xF496D0BB, 0x7F2162EA, 0xA018A479, 0x930B512F},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 383 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 384 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 385 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 386 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF1CA5E71, 0x804C76AA, 0x99F5C3F1, 0x2F89ADE8, 0x9858D7CA, 0x03EC43FD, 0x4F6483FC, 0x164499AC},
	{0x777C5592, 0x22D20329, 0xEAA7BB5F, 0x1AD852D0, 0xAB9429B0, 0xED9E631B, 0xB50C9C2B, 0x8C5EAF7C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xF1CA5E71, 0x804C76AA, 0x99F5C3F1, 0x2F89ADE8, 0x9858D7CA, 0x03EC43FD, 0x4F6483FC, 0x164499AC},
	{0xEAAFDF09, 0xDC1C8687, 0xE9D023E7, 0xF83959CF, 0xA84E6004, 0x0DC1F94F, 0x8B123FFD, 0x2DB4EF45},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 387 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 388 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 389 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 390 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 391 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 392 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 393 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x04273D84},
	{0x622C349B, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0x8E139EC2},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 394 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 395 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 396 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0xFA09393A, 0xD2DFBEAC, 0x088E6622, 0xB5724A98, 0x1C4AC2C0, 0x6EF1D696, 0xC23CC40B, 0x57C12AEE},
	{0x9F0AE981, 0x4F60531D, 0x5E22297B, 0x6A980A9F, 0xA43EE4BD, 0xDD8EA979, 0xFF7314F3, 0x8B2EA470},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 397 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 398 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 399 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x71901F53, 0xC0963C15, 0x2F5D223C, 0xCE4464C5, 0x539C6EE6, 0x8DD45757, 0xDE1CBB9D, 0xA1B5E990},
	{0x48205AFE, 0xBC40A4D2, 0xFA1523E5, 0x61D5BA25, 0x300B1866, 0xE508E0BE, 0xAB3AFC0B, 0x3E413155},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 400 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 401 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 402 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x6C8A35CE, 0xD6BFA172, 0x27922805, 0x957A3AC8, 0x73E9BC77, 0x06A9E76B, 0x2D6E270C, 0x55BF49B0},
	{0x94D3B480, 0x088354AB, 0x27E68C69, 0x3A35D998, 0x2EA0CC7C, 0xA6983BCA, 0x66F2B134, 0x816EC37E},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 403 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 404 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 405 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x481250C4, 0x17EEBF51, 0x6E562BE6, 0x77C6B7E4, 0xB7F6DC20, 0x34192033, 0xDCE82A5C, 0x92D9E058},
	{0xF4BCC25B, 0x1836C662, 0xE17B61DC, 0x121A489E, 0xB43BE9C2, 0x8340B98A, 0x7EE3BCC7, 0x7FA0F829},
	0};
		static bigint_t var_k = {0xFDE54515, 0x05D89B0B, 0x5C321734, 0x63222200, 0x109D6C5E, 0x794F1EF7, 0x894B8538, 0x70B6BAD4};
		static ecpoint_fp var_expected = {{0x09077D40, 0x3BA48945, 0xA2830B8A, 0x547F32C8, 0x3560E9A5, 0xAAA9AE93, 0x388252EE, 0x27892227},
	{0xC863D7E3, 0x2F28A51E, 0x1D83CEDF, 0xAF5D85D2, 0xC1A2B3DC, 0xC63B2A30, 0xE79D652E, 0xA5C36B95},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 406 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 407 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 408 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB2134846, 0xD7E0F84F, 0x2BBF5A4B, 0x6F48658D, 0x00CA0128, 0xF659AB9F, 0x0DD94E1E, 0x0C051C95},
	{0xB6A09287, 0x20560777, 0x9247B79F, 0xE8DE4FA0, 0x290A21E5, 0xDF756094, 0x3C1528CD, 0x88FBB983},
	0};
		static bigint_t var_k = {0xE515E16A, 0x247ED969, 0x99A21ED0, 0xB8B07ADE, 0xADC42514, 0xEE09110D, 0x92E2A674, 0xB15D305E};
		static ecpoint_fp var_expected = {{0xD8EEADBA, 0x944B292A, 0x4FFB975C, 0x0CD4CC51, 0xC257CAB9, 0xE4630363, 0xF060D3C3, 0x9BF62F4D},
	{0xA6C3F5AE, 0xCE59A608, 0x636440A1, 0xFE477922, 0xFAFF7195, 0x791C6BE4, 0x0910B544, 0x46D416DF},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 409 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 410 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 411 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x83010EBB, 0x7AF0B6EC, 0x29173D0D, 0x4854D9EE, 0x3AE0923F, 0x6ADAC0BC, 0x2B89E413, 0x6E0325B4},
	{0x13D2E8BD, 0x00A80963, 0x13E9D564, 0x4E7DF9C2, 0x2B6D922C, 0x87A9222C, 0x021260D7, 0x0DF16C2C},
	0};
		static bigint_t var_k = {0x1421E4F8, 0x2FDD9ABF, 0xD455F1D6, 0xF5EE4E7E, 0xF97B13DB, 0x188A6868, 0x70018C64, 0x9E345184};
		static ecpoint_fp var_expected = {{0xF17077AC, 0xD162AA57, 0x0BD679A3, 0x5249901B, 0x28AFF68C, 0x82B67995, 0xF2249B92, 0x24A2A13E},
	{0x1198C663, 0xBEE547ED, 0x306AB266, 0xBABC2E0F, 0x2B98A4D4, 0x00BCA6BD, 0x7B34669D, 0x49457E95},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 412 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 413 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 414 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF0E858E6, 0x99FF3165, 0x9C245EE5, 0xA39704B4, 0xDBE255D5, 0x2BFA55BB, 0xACF85C13, 0x13DE58FE},
	{0xC79DF74F, 0xA2FB2341, 0x2660BADC, 0x008FE49D, 0x757273B0, 0xDBE186C7, 0xE19B1A5C, 0xB1102DEB},
	0};
		static bigint_t var_k = {0xB9792535, 0xE757A3FD, 0x309504B0, 0xB377A98C, 0x501C31BC, 0xA9F8AF27, 0xF9D87B98, 0x404EBAEB};
		static ecpoint_fp var_expected = {{0x26C5BE34, 0x2D063054, 0x13C50248, 0x610B4379, 0x69213E62, 0xAE2DE226, 0x4FFF90DC, 0x0D812AB2},
	{0xC53C7F53, 0xF2942381, 0xF02456DF, 0xDECDD2C7, 0x71166998, 0xC04B6CCE, 0xEABF3F2F, 0x4D223E2B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 415 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 416 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 417 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8FB876CB, 0xE8C4B6E3, 0x4066E374, 0x2998C464, 0xBB5E9AA1, 0x6AED7B11, 0x1CA2060F, 0x909B575A},
	{0x53D9E203, 0xEDE18387, 0xBCBD8D72, 0xC8A2CDEC, 0x37BE38C1, 0x96FBBD97, 0x463887C2, 0xA0657F74},
	0};
		static bigint_t var_k = {0xEADB94EF, 0x5F953F99, 0x3FD7B077, 0x93ED97DA, 0xFD2D9DA0, 0x95AC6686, 0x025A9318, 0x277DE8D8};
		static ecpoint_fp var_expected = {{0x8A6B9CA9, 0xCC93C3CB, 0x6A31B7FA, 0x2AE452EC, 0x4CE4FD4B, 0x2B54BFAF, 0x3DC82A32, 0x568D5688},
	{0xA1977A77, 0x7949B97A, 0x3C4CD883, 0xD01CC345, 0xAE1DEEC9, 0x8370DD98, 0x300D31C4, 0xAE02BB9C},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 418 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 419 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 420 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9A803DDE, 0xE047EBFF, 0x62E752A7, 0x19D005E0, 0x37A5BF7A, 0x31FBBCC3, 0x566DC695, 0x22FC4FAC},
	{0x519C8ACF, 0x7917A8E4, 0x9FA180A1, 0xFCC02658, 0x61C19D2F, 0xC245173F, 0xC8D4E90C, 0x006C5169},
	0};
		static bigint_t var_k = {0x562639AE, 0xA136E3D6, 0x230D58AA, 0x589CB12B, 0xD7A3B1E9, 0x031BC962, 0xA02148EA, 0x084BB182};
		static ecpoint_fp var_expected = {{0x3EC3556A, 0x795CEAC6, 0x3AD13458, 0x2EF500B0, 0x1ABC695C, 0xDC600A70, 0x3DBCF5AF, 0x4DB5A21E},
	{0xC5C67F94, 0x576FE6F9, 0x41453219, 0xFBAE31A7, 0xE1977403, 0xED7200BE, 0x840E5ED8, 0x5EECCE04},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 421 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 422 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 423 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9D3C7DB0, 0x642639D0, 0xCF2B0054, 0xA6131BE9, 0x5FB64EA5, 0xB2E82077, 0x8BB8CC0D, 0x280749FC},
	{0xCD070ADF, 0x93C3C989, 0xC2F631B1, 0x9B420798, 0x2D9956B3, 0x49783679, 0xE29DF312, 0xAD106D1E},
	0};
		static bigint_t var_k = {0xE818D469, 0x659B24DD, 0x44F86E54, 0xB0E6C149, 0x01D45B2B, 0x6D2763AA, 0xA790392B, 0x7FB9ED9E};
		static ecpoint_fp var_expected = {{0x10F1F695, 0x9CDDC20C, 0x2CC318E8, 0x4C5842B2, 0xEA466266, 0x1098D129, 0x26C13256, 0x4B7E2CA8},
	{0x7BB99CEE, 0xDF914A58, 0x6019FFA7, 0xE19C8156, 0xBEFA6586, 0x52CFC854, 0xD9280547, 0x8929A7EB},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 424 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 425 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 426 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x74BC6670, 0xDE0D0F47, 0xAE41105D, 0x7B67859B, 0x1273575C, 0x3EF5F83C, 0x15D9CA2B, 0x608932FD},
	{0x7A2D4CB6, 0x9BDD8529, 0x163A450E, 0xAADF1FAF, 0xBA61FD6A, 0x696C5B5E, 0x98F1E4F6, 0x1D2D400F},
	0};
		static bigint_t var_k = {0x233602C0, 0x5B3DCF39, 0x9A74664C, 0x6DF8B69F, 0x2A1F8E11, 0x83F3E9CE, 0x2D54684C, 0x4FA1164B};
		static ecpoint_fp var_expected = {{0x510DE5AC, 0x5FF0BCEC, 0x571BF3C2, 0x71C739D0, 0xDC81516D, 0xFC040C41, 0xEF7B45D6, 0x02CBE601},
	{0x72C75E53, 0x27762266, 0xB12E5FF9, 0xDA18342D, 0xF8C38177, 0xB8E5624A, 0x465A0FED, 0x2CC35DDA},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 427 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 428 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 429 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF2147E20, 0x7FEE9E2B, 0xD62740C0, 0x6C9E710D, 0x29FDF6F8, 0xD70AD398, 0x021B73C9, 0x7314ED8F},
	{0x680C45F3, 0xBAA3E32E, 0x5DCC2917, 0x524D6D8F, 0xFB2E9BD3, 0x8BED9FBF, 0xAC9EB438, 0x61B2325C},
	0};
		static bigint_t var_k = {0x1EEE34FB, 0x952BCAE0, 0xB865B1A3, 0x3075882A, 0x9C7267ED, 0x38AF8298, 0x05FADFE3, 0x07C673FF};
		static ecpoint_fp var_expected = {{0xF153EB50, 0xD56A440E, 0x7E14FF2D, 0x04D73F2E, 0xD41FD8EB, 0x1A2A1519, 0xD394808B, 0x93682C2C},
	{0x7AE5C780, 0x45190D7D, 0xEDF4BFCC, 0x3D905F9B, 0xD8A1BF8D, 0x2FBF9266, 0x9C6A4ECB, 0x772DF705},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 430 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 431 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 432 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x52A31875, 0x4AF50F23, 0x8C435DB0, 0xF5C2DA41, 0x4335B5E6, 0xE9450736, 0x3A823DD3, 0x25263C80},
	{0xB08959C2, 0x5DDD3898, 0x6AF33B30, 0x15D008C8, 0x27B30CB6, 0xF88C712A, 0x71A9A4ED, 0xAFB4E8F1},
	0};
		static bigint_t var_k = {0x8817CCC3, 0x1CB3D37E, 0xBD6985AD, 0xBCE9F519, 0x2F662591, 0xB2E87BF9, 0x49FCE501, 0x5EE243E3};
		static ecpoint_fp var_expected = {{0x7D73A64C, 0xA9A9E001, 0xE56886D6, 0x6507F449, 0x227F6942, 0xF9E0887B, 0xAAA7A501, 0x9F70DB09},
	{0x53332A75, 0x4F05CF3E, 0x73521C5D, 0x216545B3, 0x81AFAAC3, 0xB421FB43, 0x4ED89CB4, 0x15EFC73E},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 433 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 434 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 435 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAF2BF709, 0x7DE1186C, 0x4D684229, 0x40E5D6E6, 0x170A5F87, 0xB997E74B, 0xC1D41C9B, 0x4B6F3524},
	{0xFB90BBFC, 0xF49C9975, 0xF129FBBB, 0x29704AA5, 0xBAADAB10, 0x0B016964, 0x72DD4989, 0x504BF724},
	0};
		static bigint_t var_k = {0xF7083E1C, 0xBD2A7A12, 0x3EC9E3EE, 0x86691ED8, 0xB253434B, 0x727C08C3, 0x89B9BE1D, 0x3654D8FB};
		static ecpoint_fp var_expected = {{0xE1EF4EBB, 0xEF939B24, 0xE29C2CD8, 0xEE4F7FFC, 0x4FC4E3BE, 0x97F8E5F2, 0x2605F202, 0x47402D1C},
	{0xCA7FDDA8, 0x77CC6D8F, 0x7685094E, 0xAED68715, 0x22FC8AF5, 0x4B39625C, 0x7E54AC29, 0x9AAA41D3},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 436 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 437 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 438 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9E10D81C, 0xAC1F493E, 0xE6D96980, 0x969ABA80, 0x500A0F78, 0xD50D3A75, 0xC7B5E652, 0x047D6571},
	{0xA2A0A4A4, 0x35CD52B6, 0x8D90F681, 0xE286926E, 0x42745003, 0xDD41A62D, 0x7D31ACE5, 0x0F4CE029},
	0};
		static bigint_t var_k = {0xEE8C81E3, 0xED0275BC, 0xB3BE3C3B, 0x0B5255C3, 0xD064E8CF, 0x1745869C, 0x9C99016C, 0x7EE35C65};
		static ecpoint_fp var_expected = {{0xF837024C, 0x5184B5DE, 0x49CD5DCC, 0xDAB1E7E1, 0xA8554766, 0x30F553E4, 0x25306879, 0x1AA6C65B},
	{0xE3D154A0, 0x4D36BCD4, 0x9F481E1F, 0xFC673847, 0x34E7803C, 0x0741C90F, 0xDC6CB7C6, 0xAAF751DF},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 439 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 440 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 441 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD727EA3F, 0x023D5F62, 0x5A6C583D, 0xBA95A813, 0x91A23AC9, 0x872C9D94, 0xCFB86495, 0x829DA915},
	{0xA7E7A83A, 0xE40E1C46, 0x68BD40AF, 0x5FB36E58, 0x95F616E3, 0x9BE0F982, 0x29D8E63C, 0x1207A520},
	0};
		static bigint_t var_k = {0xD9922F5E, 0xE5D546B5, 0x02CF464F, 0x7AA789D1, 0x2B2A904F, 0xA18B063D, 0xD68855E3, 0x521B7F23};
		static ecpoint_fp var_expected = {{0x95FB9848, 0x71B9E3DE, 0x9CCE33B4, 0xAC3F06C9, 0xBB182599, 0xD982152A, 0xAC407AD8, 0x3F4DE5AE},
	{0xD63F92AA, 0x9D357E7C, 0x0A04BB71, 0x0E07C17C, 0x22AF5E46, 0xD2731CAB, 0x96B6B9FB, 0x96DECD81},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 442 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 443 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 444 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDE7525AD, 0x0DEC9024, 0x8C9BBE58, 0xFCCA5AD2, 0x5A6A6DBF, 0x94AB13C4, 0xCA5469B8, 0x4D176E56},
	{0xD33C5F17, 0x925EE1A7, 0x56371FC3, 0x13886F18, 0xDD53A173, 0xAD5DFB10, 0x747D16CE, 0x70C218C5},
	0};
		static bigint_t var_k = {0x67111B3A, 0xE8CCA7B9, 0xD213AACA, 0xEBC7CB76, 0xA0386A80, 0x3FD713EC, 0x8D80E02B, 0x3BAA224B};
		static ecpoint_fp var_expected = {{0xFBBDA48B, 0xF99EB36A, 0x2390FC8E, 0x47FE619F, 0x41CDDC47, 0x31CB2EF1, 0xC78696E9, 0x8A538A0D},
	{0xDA8C2F82, 0x42150DAE, 0xF29A6B68, 0x2B8F656B, 0xCC05C45E, 0x1D5C7714, 0xDE9E281A, 0x2103FC1F},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 445 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 446 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 447 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x53132C1A, 0x072865DB, 0x2AB61E44, 0x839D6C53, 0x56E0B718, 0x15AECFAD, 0xB5C57FC5, 0x95637857},
	{0xBF1DAAE9, 0x44BF577E, 0x9424E04B, 0xF4A7282A, 0x9EC1C15B, 0xF0CD7AD5, 0xB8854FB9, 0x8BF4D383},
	0};
		static bigint_t var_k = {0x82D68858, 0x3DB0FFE8, 0x828B5F4D, 0x62F6D7BE, 0x48FEB92F, 0x57FDF089, 0x16D75198, 0x31ED627C};
		static ecpoint_fp var_expected = {{0xC816E9CA, 0xB11B468D, 0x7190A5D2, 0x0DCD3AC3, 0xE30CFDC8, 0xF6EB15F4, 0x5C992EB5, 0x571E46FF},
	{0xBBC9AEA5, 0x66C141DF, 0x1612F42C, 0x2E9D2079, 0x422FB3D3, 0x504A43C5, 0x9EEEB2B7, 0x3703DE49},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 448 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 449 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 450 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5B02EC72, 0x48FE7225, 0x0C5B96E1, 0x117A1510, 0x1F08776F, 0x1C43636D, 0xF4070A3D, 0x2EF4D57E},
	{0xA91C6815, 0xD1E74320, 0x27CBA3EA, 0x06EF2CB5, 0x5952BE46, 0xC5AF3625, 0x918E8C4A, 0xB0461C12},
	0};
		static bigint_t var_k = {0x5AE1D2FB, 0xDD9064DC, 0xBCD48A15, 0xCDA2D173, 0x849CAB77, 0xA6D1C2F0, 0x86766346, 0x0DCF8002};
		static ecpoint_fp var_expected = {{0xF306684D, 0x3284ED9E, 0xFB470454, 0x2D017A38, 0x8F2AB015, 0x62D780A4, 0x3ACE03A5, 0x0C215E78},
	{0xA99F913B, 0x9198C6E3, 0x53E71BEE, 0x1820C5E8, 0xA51F766B, 0x907DBD5B, 0x82328757, 0x0014554C},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 451 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 452 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 453 infinity");
	}
	{
		static const bigint_t var_t = {0xE378DFD0, 0xF7599D49, 0xD0581613, 0x77F91F13, 0x354D81FC, 0xFA3C3C43, 0xEB4F279A, 0x20B091F6};
		static ecpoint_fp var_expected = {{0x057D8E5C, 0x8B11A922, 0x3B60FF4E, 0x6D48E77A, 0xECEBC2C7, 0x65F3FF37, 0xFAD0846B, 0x0C746619},
	{0xFF7E4A7A, 0x63161823, 0x87B35BDB, 0xE6B2BD91, 0x0BA29A9D, 0x3706D12D, 0x4B0A5683, 0x0E51551F},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 454 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 455 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 456 infinity");
	}
	{
		static const bigint_t var_t = {0x8D7C259B, 0x9078265E, 0x159004DC, 0x0E7CCAA8, 0x142756EA, 0x526D76E1, 0x690554C5, 0x68F232E6};
		static ecpoint_fp var_expected = {{0xE0FFA143, 0xB4046BD2, 0x58B06226, 0x21CA8C09, 0x74775726, 0x7C48126B, 0xD0EA421E, 0x6252B1AF},
	{0xC560BC58, 0x8B531773, 0x14F94EB1, 0x8C8AF302, 0x438315EC, 0xD9A3D7D2, 0xBDE0EEF7, 0xB4072393},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 457 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 458 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 459 infinity");
	}
	{
		static const bigint_t var_t = {0x1DB270E0, 0x69D74DEB, 0xAD7EE18A, 0xCE5B7D0C, 0x436EBFEE, 0x9704B286, 0xB38B465E, 0x511980F6};
		static ecpoint_fp var_expected = {{0x832CF5DF, 0x666F9FD2, 0x7DD1419B, 0xBA0B2346, 0xD532190D, 0x34F5E81F, 0xF92BA6DA, 0x405C6526},
	{0xE9684F1F, 0x32E91D45, 0xBCD71B8E, 0x9EFDA123, 0xCBA06347, 0x0CBB5A3A, 0x7AA527F9, 0x7CD61910},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 460 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 461 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 462 infinity");
	}
	{
		static const bigint_t var_t = {0x6F4051F2, 0x30F75CF1, 0x690248CD, 0x6ECF9437, 0xC5401A74, 0x0F24DF0E, 0xAD82CBA7, 0x139BD3F1};
		static ecpoint_fp var_expected = {{0x888D2E2F, 0x1D48C787, 0xF1CC0213, 0xBE8A88F4, 0x526C810B, 0x81A909F1, 0x6FAB8BDC, 0x30FFC7F1},
	{0x8988FFEC, 0x4AE98EF3, 0x4367C169, 0x3D6CBAE2, 0xDFCD386E, 0x800315EA, 0x464A1FF5, 0x1C0BF0C1},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 463 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 464 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 465 infinity");
	}
	{
		static const bigint_t var_t = {0x689F7713, 0xE197B95E, 0x615D48B0, 0x0F6A80A4, 0x6B3C9AD7, 0x322788C2, 0x02E1EDCE, 0x3D72AED7};
		static ecpoint_fp var_expected = {{0xCBF40F4F, 0x8B8D3A03, 0x609D2147, 0x075A1995, 0xA3AAE341, 0x89CC94F5, 0xF27039EE, 0x8A2FA677},
	{0x908562E2, 0xF51DF7AB, 0x9B7E8154, 0x1F95E921, 0xE5B11A44, 0x4F92E0EE, 0x473E7A45, 0x57F324D6},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 466 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 467 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 468 infinity");
	}
	{
		static const bigint_t var_t = {0x0778BE4C, 0x1E21C85C, 0x0B40B7E9, 0xD6A1BEAB, 0x9D1EE659, 0x50605498, 0x90BE1675, 0x86A3DA46};
		static ecpoint_fp var_expected = {{0xED3A54A7, 0xEB8C4BB3, 0xB3D0C2FD, 0xA68352AA, 0x9F5679F0, 0x3E340E1C, 0x54827742, 0x7B1FC862},
	{0x898BCBB3, 0xE998C1BB, 0xE4A77FE0, 0x9FA0AB43, 0xA3A3C865, 0xE3F8ABDE, 0x732374B4, 0x9E9BED49},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 469 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 470 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 471 infinity");
	}
	{
		static const bigint_t var_t = {0x8FFAE899, 0x9B82AE0F, 0xF7D9DAFD, 0x878DD0D7, 0x15D4387C, 0xE13500BB, 0xB6CEA12A, 0x9B0B830B};
		static ecpoint_fp var_expected = {{0xBBF800E9, 0x1674D6D8, 0x4184702E, 0x54C67690, 0x139BFA92, 0xFE59F0B8, 0xE873A7D2, 0x73ACA530},
	{0x5157364E, 0x744BF6F8, 0xCBC1DC4E, 0x3C9BEF07, 0xC0A06347, 0x60E95435, 0x79DEC1BF, 0x877E5C28},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 472 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 473 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 474 infinity");
	}
	{
		static const bigint_t var_t = {0xE2F7A8DD, 0x335E4D61, 0xC1938B0F, 0x04D19480, 0x0245AD83, 0x4CAC87C7, 0x89759673, 0x30B33D87};
		static ecpoint_fp var_expected = {{0x0E6ECF31, 0x736B7880, 0xDAEE1E73, 0xD9410CDD, 0x2BFA4D93, 0x6A8DA5A3, 0x5F40FDDA, 0x044A3047},
	{0xCFB2BAA0, 0xAC6C2AB1, 0xF1F0220C, 0x730D8E50, 0x69F581FB, 0x4564F265, 0x6D2E7441, 0x4224FF69},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 475 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 476 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 477 infinity");
	}
	{
		static const bigint_t var_t = {0x18B85C1E, 0x0A93CD7A, 0xAAA27C60, 0x7AD715FB, 0xAD1B0C18, 0xECB7240A, 0xAA05D6B2, 0x098B0871};
		static ecpoint_fp var_expected = {{0x620D19C3, 0x742CC6F1, 0xD1ED4625, 0xF03355FB, 0x85FD8257, 0x82370E55, 0x486B6AAB, 0xB35F3B84},
	{0x434E6EBA, 0x93CF55F2, 0xC6D91920, 0x26B36ECB, 0x64A738C2, 0xB9A75DD5, 0x4A99448F, 0x2A7807D6},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 478 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 479 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 480 infinity");
	}
	{
		static const bigint_t var_t = {0x9DB7A83B, 0x2C761A46, 0xAF8A37E6, 0x6C975974, 0x40D8EF49, 0xB6616B85, 0xBC9F2438, 0x91119640};
		static ecpoint_fp var_expected = {{0x43BCE1EC, 0x385EBEBC, 0xFE7261EE, 0xEEED5D8B, 0x21A77689, 0x761658BF, 0xF6F94FA3, 0x3C82F187},
	{0x91A979ED, 0xF142D821, 0x5484E7FA, 0x9230E4D2, 0x293ACE87, 0x726D2BEE, 0x2C6B0369, 0x0F95DAB1},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 481 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 482 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 483 infinity");
	}
	{
		static const bigint_t var_t = {0x0AADB50E, 0xFC4ED152, 0x8EAC08B6, 0x56624041, 0x50269ABF, 0x2D586031, 0xBBEE8472, 0x2E2F7C54};
		static ecpoint_fp var_expected = {{0xF2EA5BEF, 0x17203C7B, 0xB69DBCA0, 0x86A7CEEA, 0xE4468DF8, 0xBC20BBDF, 0xB5358CF7, 0x45499DD7},
	{0x96BAE3B0, 0x69AE53F8, 0x0C52F70D, 0x280C5234, 0x5E2EC00C, 0x17D4335F, 0x8E4EBA54, 0x94D8E3F3},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 484 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 485 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 486 infinity");
	}
	{
		static const bigint_t var_t = {0xC8424C00, 0xEE596EC3, 0x22A8F7A0, 0xC3741648, 0xA387E57B, 0x1216B876, 0x4406F469, 0x48DEFBC5};
		static ecpoint_fp var_expected = {{0x93E38170, 0x8E92E613, 0x5D4D0958, 0xDF6A7D6F, 0x912D5F6F, 0x38C3F057, 0x42AFE8C7, 0xA074DAE0},
	{0x2F6CB148, 0x4CD48A9F, 0x154070DA, 0xB499F6B2, 0xA6960CCC, 0x5B2BCED2, 0x7B7B2371, 0xAE984B60},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 487 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 488 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 489 infinity");
	}
	{
		static const bigint_t var_t = {0x3240418B, 0x6A9348F5, 0xB7D0EA0F, 0x599159C7, 0x6B7CFCAB, 0x8B18F087, 0x88B74185, 0x4DD8C24A};
		static ecpoint_fp var_expected = {{0xA236B28C, 0xA8011EC0, 0xB00A7984, 0x7EB2EAEA, 0xBD42EE88, 0xC676A9A6, 0xD249E468, 0x5C4F084C},
	{0x0D637919, 0xE41148AF, 0x15C27098, 0x8171AB47, 0x53B01DB4, 0xFBB2E388, 0x422AD4D3, 0x8C84E423},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 490 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 491 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 492 infinity");
	}
	{
		static const bigint_t var_t = {0x003DA11C, 0x526C4EB6, 0x4E85D8A9, 0xD0777E42, 0x28D37401, 0x0A180F85, 0xBE1D48D8, 0x005536C1};
		static ecpoint_fp var_expected = {{0xE71F808C, 0x74029770, 0x3A48F9DF, 0x3E523F8A, 0x857A6C75, 0x7A229C2A, 0x9D141118, 0x00B91861},
	{0xB90166F4, 0x20608BAA, 0xF14B95B6, 0x44389C69, 0x12BD1D6A, 0xEFE31A76, 0xFB5F368D, 0x31CEDBF4},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 493 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 494 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 495 infinity");
	}
	{
		static const bigint_t var_t = {0x2E8E74FC, 0xD027D55A, 0xC591BEA3, 0xADDCA3F3, 0x550DFBDE, 0x239499D2, 0xE9DF0370, 0x74AA5981};
		static ecpoint_fp var_expected = {{0xFD454FFE, 0xD7AAFB9E, 0xFF9751B8, 0x9B510185, 0xF268E7AB, 0x0F382588, 0xB04222F9, 0x8C0E5A4C},
	{0x4C5B9B8C, 0x8C31C772, 0xA5410AAF, 0xF8ADB260, 0xCA72144C, 0x431E602C, 0xCA7B179C, 0xACABED39},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 496 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 497 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 498 infinity");
	}
	{
		static const bigint_t var_t = {0x5CA848BC, 0xB37A1AA6, 0xE1B79651, 0x767E45F8, 0xB81EE4E0, 0x6B12ED0B, 0x5EFFC9E4, 0x555E85BE};
		static ecpoint_fp var_expected = {{0x8BD31D99, 0xE092C1DF, 0x3DFC9D97, 0xC2E6E693, 0xCE938B54, 0xF51A1BA8, 0x9D7CD9B3, 0x653DCA2B},
	{0xF60FF03E, 0x5CB848A4, 0xA62B2B82, 0xC32D03D4, 0x230E5D01, 0x141D6C15, 0xDF776E51, 0x2564A5CC},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 499 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 500 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 501 infinity");
	}
#else

	{
		static ecpoint_fp var_a = {{0x11FDEE00, 0x4486655F, 0xF970BBA3, 0x9349757B, 0x02BF61B3, 0x03F47C8D, 0x8EFF1E6B, 0x7C3FDB11},
	{0xFCA10D5C, 0x5D2A2ECE, 0x1626897C, 0xF78F2F55, 0x7036C873, 0x0C23DCA6, 0x07B5D6F0, 0x933304F9},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4353 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4354 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4355 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4356 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4357 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4358 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAB5483BC, 0xD7227087, 0x0EDFEC75, 0x240080D4, 0x472FF4D2, 0x7E0F0504, 0x6562F590, 0xA257A95E},
	{0x5368C415, 0xB81EA345, 0x77A4EDB1, 0x9BE48A8E, 0xA12A190C, 0x1E96A605, 0x333656E9, 0x3B3285FD},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4359 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4360 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4361 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4362 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4363 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4364 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3D059E5E, 0xED59F7BF, 0xDA00A37E, 0x25E9187D, 0x6F15698F, 0x59DAECB3, 0xB0698B48, 0xF1DE1057},
	{0x47378C60, 0xC5D5DCD9, 0x32CB3F6D, 0x4D7F60F6, 0xF36E7EE8, 0xBAF6BD8E, 0x4E6369CC, 0xE02A78EF},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4365 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4366 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4367 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4368 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4369 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4370 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x644C537D, 0x7621096A, 0x71C1BBC2, 0xE152E7B9, 0x46BF7470, 0x753DAC19, 0x33A9E338, 0x22C14444},
	{0x1883F691, 0x97B23DF4, 0xFCF22529, 0x75CE6DF7, 0xD35D2915, 0xE008C02E, 0xBBA3A571, 0x5A6792D7},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4371 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4372 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4373 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4374 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4375 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4376 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFC086627, 0xA4CD5017, 0x2AFBE99F, 0xDFAF1621, 0xDA875E74, 0xF41B7BA5, 0xF42F11A4, 0x2E4ADE51},
	{0x40497E12, 0x7EFE3A5F, 0xC80B9268, 0xBCAC3C8E, 0xEEC6BAE6, 0xD092B765, 0x20028D7A, 0xC559C32C},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4377 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4378 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4379 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4380 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4381 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4382 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x248B327E, 0xE8202BA1, 0x98C7CF14, 0xEA26A870, 0x77A7DEDB, 0x36634490, 0x37D84C25, 0x4DB63591},
	{0x7EE0FC1B, 0x0BF9E205, 0xCDECD5E9, 0x0CF11662, 0x31BF0A16, 0x0D6D6101, 0x627CFD9F, 0x772C0F14},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4383 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4384 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4385 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4386 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4387 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4388 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3764EDDF, 0xF35BDE6C, 0x90CF4C84, 0x0A2348DC, 0xAB0310E9, 0xDD1A7D13, 0x8197FE5E, 0xF9C1FEC3},
	{0xCEC8F23E, 0x0FE806E1, 0x7FA46B07, 0x8EFEFD41, 0xCA70849D, 0x5692D532, 0xA653147A, 0x0B522D8C},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4389 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4390 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4391 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4392 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4393 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4394 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD336365F, 0xB54DF66D, 0x289B0029, 0x87E3A7BB, 0x43FF757E, 0xC974DF84, 0x98CEBA7D, 0xEB392947},
	{0x6D7BA40B, 0x9B2709C3, 0x93C8711B, 0xAA54A60E, 0x24EB15E5, 0xAD2F94A0, 0x515C8547, 0x5915EBFD},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4395 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4396 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4397 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4398 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4399 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4400 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD586FE84, 0x5F63C4B7, 0xB5E100AE, 0xEC0B5BC2, 0x4B4A16CB, 0x1CDD0917, 0x809933B5, 0x1B8B05B7},
	{0xD93A0B7C, 0x013A4FF3, 0xFEC5DBFA, 0x091F775A, 0xEDF2B309, 0x53B4F655, 0x084E6679, 0x7A2952EA},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4401 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4402 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4403 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4404 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4405 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4406 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5A89C499, 0x64B803AF, 0xCCD9C3A1, 0x0134392A, 0x11B2A670, 0x350A0240, 0x7F1F1E1C, 0xC452AD25},
	{0xCEE299FB, 0xD0D757CA, 0xF53056DD, 0x95C58D48, 0x13D2714D, 0xC9E104B1, 0xB0136E08, 0xC83993AF},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4407 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4408 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4409 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4410 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4411 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4412 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xBEF421F3, 0x7326A12C, 0x42893EB8, 0xCE774379, 0x21F1CED0, 0xB80C9C06, 0x19E30B8C, 0x5DEEAFFC},
	{0x49B8D529, 0xDBFF74BF, 0xEE14DF46, 0x777CC573, 0xC1272DFD, 0xD0DBADAF, 0x6E1BA8D8, 0xDB79B49D},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4413 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4414 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4415 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4416 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4417 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4418 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA0D0AE02, 0x7D55A722, 0x2B153711, 0x9E070ECC, 0x497F7E6E, 0x835FC5B7, 0x1412386A, 0x9F0B03E3},
	{0x8839C3B4, 0x32072A99, 0x9D4412C8, 0x17D4C2E6, 0x66B8CD58, 0x6838653D, 0xA7A69BB0, 0x8C3504D4},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4419 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4420 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4421 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4422 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4423 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4424 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDB453823, 0xB5CB4E94, 0xDD11CBF7, 0xF9B7ADCD, 0x96615690, 0xB9F7B3C4, 0x74D5487E, 0x85383740},
	{0x07EE26E8, 0x26A92DB1, 0xF7A929AA, 0x1E49036E, 0xAE3D194B, 0xD40F2462, 0x001AE788, 0xF4604FA0},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4425 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4426 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4427 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4428 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4429 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4430 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8D6E4B61, 0x89FD31F2, 0xECD229D0, 0xA79129C6, 0x54FA2691, 0xBB54F9CA, 0x7FA1043C, 0x4673F035},
	{0x83369ACE, 0x4817107D, 0x3196B1DB, 0x77D4F0CC, 0x85361BFE, 0x930CCE73, 0x5D4D4F39, 0x6D28DC58},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4431 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4432 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4433 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4434 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4435 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4436 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x132614BC, 0xAD5DA52B, 0x2EBB8228, 0xB3617068, 0x11D9818B, 0x28907907, 0xB985FB24, 0x5DBAA228},
	{0xFA1C7401, 0x690985CC, 0xC111F1B2, 0x487BF99E, 0x1AB72099, 0x687BFAAA, 0xE5DB42C8, 0x8F8028EA},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4437 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4438 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4439 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4440 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4441 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4442 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x09D98F9B, 0x106D3306, 0xB88C2722, 0x6549D248, 0x998A5F4D, 0xE46D46B5, 0xE87C2427, 0x809C9230},
	{0xA8248684, 0x9BCD516E, 0x5A2C065B, 0xFCDEAAED, 0xD93848B5, 0x525B21BC, 0xFC73D1E1, 0x33B66C91},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4443 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4444 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4445 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4446 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4447 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4448 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5F60C7CC, 0x7F6DE9B8, 0x0D1801B8, 0x0B081CE7, 0x735A1A58, 0xE9D5C9B5, 0x9D4F452C, 0x61CDF78A},
	{0x41BC590E, 0x5C8CB569, 0xD67A63EA, 0x98B952F6, 0x032023B3, 0x4274BB53, 0xDE684316, 0x17F089BD},
	0};
		static ecpoint_fp var_b = {{0x089A09FE, 0xA785F8BF, 0x07410F98, 0xEB61997A, 0x1C9CFFA0, 0x136AA788, 0xDED01443, 0x3040A006},
	{0x56DC33E4, 0xA92C0229, 0xD1420969, 0xC60D9D86, 0x7A36DC83, 0x9AB4470A, 0x31F64E8B, 0x513000B1},
	0};
		static ecpoint_fp var_expected = {{0x54C7EC13, 0xB280336C, 0x1AECFDC9, 0x052E9F72, 0x00245C1B, 0x0E638B6E, 0x1065D9F5, 0xA3C8565A},
	{0xF655943F, 0x6EBAAF03, 0x2570DC78, 0x3F6AFB08, 0x67CE08C4, 0x9EDF9587, 0x3D539680, 0x6A9464C9},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4449 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4450 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4451 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFB3ADAAD, 0x2CC56D33, 0x15250152, 0x464492BF, 0x17D3E20A, 0x54E23C18, 0xAC6BF9E4, 0x2E37932D},
	{0x21EFE86E, 0x488AD6E2, 0xCF9DB5A2, 0x079418E3, 0x7F8C6F9A, 0x8139EBEC, 0x8784E45D, 0x464066FC},
	0};
		static ecpoint_fp var_b = {{0xF7D6C675, 0xE52AF5FF, 0x11DD5D3D, 0x880DE79A, 0xB2EAE30A, 0xC51695EF, 0x469CBD75, 0x1D38750C},
	{0x93E7ABF4, 0x85772A81, 0x2DA06A5D, 0x86E09126, 0xDCFD4CF6, 0x0AE319C7, 0x8C90BF9D, 0x02BEB95D},
	0};
		static ecpoint_fp var_expected = {{0xD5F27838, 0x558E6868, 0xF52BD54F, 0x59ABDF03, 0x862B1F3A, 0x654C35C8, 0xD0B9FDC2, 0x902E903D},
	{0x1EED7C7E, 0xB41F4297, 0xC32EA2F5, 0xD0AA9848, 0xC0E061B7, 0x32994790, 0x57726F57, 0xB3B1596F},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4452 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4453 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4454 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5929A6EF, 0x5BFD695D, 0xD76CDE90, 0x139D7232, 0x4716E4C2, 0x594F1B36, 0x9F0E6340, 0x06D8BE28},
	{0x2060B6E0, 0x7A12FE16, 0xF681ECF1, 0xB1CE61A0, 0xF0717CF2, 0x4D09D8AA, 0xE6157398, 0x6E10D7BF},
	0};
		static ecpoint_fp var_b = {{0xAF28E36D, 0x3BBA7835, 0xD72E1FD0, 0x5B2BA55E, 0xE73A2E19, 0x4AD40613, 0x7564A6F8, 0x330A4497},
	{0xFE4059DC, 0x4C8A2B50, 0xFA380E3B, 0x76B80826, 0xFA36BCB9, 0x449115E3, 0xF1D4F691, 0x6DDC48C7},
	0};
		static ecpoint_fp var_expected = {{0xDDC0E560, 0x36132417, 0xB1C25102, 0x5CB6B4D0, 0x25363578, 0x593E63B9, 0xFA086CC2, 0x3EAA8AF1},
	{0xA93883EC, 0x436D9ABA, 0xBD6AF98F, 0x589EA1FD, 0x57CD34F4, 0x75852A38, 0x9F9FD0C2, 0x42DE533F},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4455 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4456 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4457 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x412A6AF4, 0xD0176D86, 0xC2B3D22F, 0x1BBE40FF, 0xD0FE8BBE, 0x21A0F2B8, 0xF6D89D9B, 0x6121A8CE},
	{0xBB5E9D13, 0x5F659542, 0x6351D900, 0x159D1D97, 0xFC98BBFD, 0xBE22C679, 0xD5981AF0, 0x3901D9D3},
	0};
		static ecpoint_fp var_b = {{0xC76F25BB, 0x39DDD728, 0x79B08132, 0x0AF3C910, 0x7D3D0355, 0xEF2EB3D5, 0x8C72C71D, 0x926CF391},
	{0x35EFCDC1, 0xAB751A91, 0xCC3212BC, 0xAE50DFF8, 0xCAF368A2, 0xA6235DFD, 0xDD6A93B6, 0x18666A4D},
	0};
		static ecpoint_fp var_expected = {{0x64BD3653, 0x5DD4678B, 0xB38A2CCE, 0xF77934A1, 0x3B1E3639, 0x5112895F, 0xE9575D69, 0x2353858D},
	{0x1CD7ACB1, 0x7C1618C5, 0x65552FEF, 0x86D216BD, 0x853A71A8, 0xB7DCFF93, 0x8D0319E9, 0x093A1BF7},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4458 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4459 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4460 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF7BB6592, 0x4AFB9818, 0x3371E6D3, 0xEBD4389F, 0xC2B3D13D, 0x2D526A7A, 0x0BAE8E95, 0xB7FE8569},
	{0xBA5EC95A, 0xB9FA45BA, 0x8403AA88, 0x5DB6D9C6, 0xFBA8C40E, 0xDEB52353, 0xAB4D1483, 0x538AFC59},
	0};
		static ecpoint_fp var_b = {{0xE9F69AEE, 0x8DCD7883, 0x9B416BA5, 0xE909946A, 0xFB1CD705, 0xBB8D5975, 0xC3E77636, 0x58DF92ED},
	{0x6410E611, 0xDC678728, 0xA143B2C8, 0x768525A0, 0xF90538CE, 0xCCB8D0A9, 0xA0AF5C92, 0xB2E68C31},
	0};
		static ecpoint_fp var_expected = {{0x78B5EE1D, 0xAE626A94, 0xFF293C6A, 0xCE9F8760, 0xFF9112A7, 0x0DDC3F0F, 0x17E2A475, 0x65255EA5},
	{0x49335B4F, 0x940EBEAF, 0x19411421, 0xD26CEADC, 0xDA039939, 0xAF220C5F, 0x12139612, 0x8B6BDF72},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4461 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4462 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4463 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3A7421E5, 0x5E917A02, 0xADAF2967, 0x8917AA89, 0xE0AC0CD6, 0x1AAD19DF, 0xBE82F431, 0x425AD2F2},
	{0x024448BB, 0xFACD8989, 0x36314022, 0x630BCB21, 0xF7CE4614, 0xFEC24094, 0x5B09D6DE, 0x4906BF89},
	0};
		static ecpoint_fp var_b = {{0x58A407A9, 0x5B86BD72, 0x150E50DE, 0x6D170466, 0x9C55FDB4, 0xB645093E, 0x58BB36D7, 0x8338015D},
	{0x7733CA14, 0xF5BA98EE, 0xB392D992, 0x6704B61E, 0xF03B0FFE, 0x71DBE76D, 0x0C6D4279, 0x39CBEA58},
	0};
		static ecpoint_fp var_expected = {{0x1184DA0F, 0x30247B5F, 0x2E97D3AE, 0xAA7D7C32, 0x2B306DEA, 0x1A1DA7F9, 0xCAFFD951, 0x4CA02309},
	{0x427C1E8C, 0x4D690944, 0x77AEADCE, 0xBEFE6F97, 0x675374AA, 0xF864B3F9, 0x5F2FAEC9, 0x91E15DA8},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4464 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4465 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4466 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0A4BE450, 0x7E00EFD9, 0xBE755C4C, 0x0B1C0721, 0xABF0742A, 0x835CFCBF, 0x53537C42, 0x3045270E},
	{0xF7F001B1, 0x770B2570, 0x819AF768, 0xEE9645E6, 0x8055CAD4, 0x51B9B6C8, 0x7C328D09, 0x643509E1},
	0};
		static ecpoint_fp var_b = {{0xBE80FDD9, 0xBE493CC4, 0x0D808630, 0x835C65A2, 0xA3AAD8B9, 0xE9A9F5A1, 0x739EA403, 0x2C1CB30C},
	{0x352D316B, 0xD45C5CCA, 0x142E229B, 0x7A7246BE, 0x139D3836, 0xEDDF5ABE, 0x91C15FC5, 0x012A2AC9},
	0};
		static ecpoint_fp var_expected = {{0x561B4171, 0xC3EF7F52, 0x3BB83A75, 0x4066BA03, 0x45362407, 0xB1050F0D, 0x22C19305, 0x18D2EFA3},
	{0x81CDEC65, 0xA0867B1E, 0xBDB02D68, 0xC89AAE44, 0x5980CC3C, 0x91B44BAA, 0x479F601D, 0x6E0D4FB4},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4467 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4468 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4469 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3DB46BD8, 0xA7BA03DF, 0x21F703CE, 0x6D7E2FEC, 0xFFA668A9, 0x369A8DA2, 0x80CA7CE3, 0x9AA6B1CD},
	{0xA794F222, 0xC9742C0F, 0xD1AD4549, 0x5FD8452D, 0x1B535851, 0xA8BA4218, 0x9EA4CF25, 0x91B482BF},
	0};
		static ecpoint_fp var_b = {{0xED8C8593, 0xB684593A, 0xFEEA9D91, 0xB90ECAD6, 0xC296CC1A, 0x47E62899, 0xDDC0C6E1, 0x1EB15007},
	{0x07459792, 0x9EC1D3F0, 0xDC436825, 0x4D7BA270, 0xBFA03ACA, 0x73134D53, 0xDA81F22D, 0x748F5D31},
	0};
		static ecpoint_fp var_expected = {{0x80CA06B4, 0x6085C4AC, 0xA055F093, 0x7BB3753B, 0xCF9572AC, 0x353188BA, 0xD70835FB, 0x95206311},
	{0x9DE1CC1E, 0xB43308BC, 0xD064DFF0, 0xF51C2F82, 0x01381266, 0x86EF079B, 0x125A0DA9, 0xACBB6A1C},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4470 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4471 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4472 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE0C45C08, 0xF75BA79C, 0xF0E57AD0, 0xB1D47EFB, 0xEC5F86C4, 0xD3D4ED4A, 0x43A0D5B3, 0x06F0BE8C},
	{0x52D4CD62, 0xDAC85917, 0x49A22D75, 0xFE72689E, 0x21B1F0CF, 0x733C7C55, 0xDCC4EA51, 0x558A3476},
	0};
		static ecpoint_fp var_b = {{0xF2A98291, 0xCB9ED395, 0xBCECF975, 0xD411CCD8, 0x8C9CA18A, 0x3D32666E, 0x3364E5ED, 0x1F8E5976},
	{0xF22229D2, 0x42026EAA, 0xF7CA8BB5, 0x7E7EEE09, 0xB73198F6, 0x1720C75E, 0x29FA7789, 0x37AF7746},
	0};
		static ecpoint_fp var_expected = {{0x543411A1, 0x75013CE1, 0x7BC58162, 0x34C09265, 0xF163A897, 0x931CACE5, 0xFFE18CC4, 0x68B17C6C},
	{0x2B6765F2, 0x08681827, 0xBF1362CE, 0x14C06901, 0xE0EC3A71, 0xF00DF725, 0x570DDFE2, 0xB3026C03},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4473 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4474 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4475 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA983B3B1, 0x495898F1, 0x9991657D, 0xE53775F6, 0x3E2C20A9, 0x73541BF7, 0x89976282, 0x4C06BA96},
	{0xA32AF8FE, 0x13ABECF1, 0x31FD4A7E, 0xFC27E240, 0x590AC60F, 0xAE6E37E0, 0x3F81396F, 0x85D37227},
	0};
		static ecpoint_fp var_b = {{0x66D1B1BF, 0x60989477, 0xE9DB6F25, 0x307B6031, 0xE175E854, 0xB500AD1E, 0x427A656D, 0x120E61B6},
	{0xBCC1A845, 0x5F21295B, 0x96550DAE, 0x7A6A8238, 0x488FDF94, 0xFC785D7E, 0xE3AD7FB6, 0xAC1C5638},
	0};
		static ecpoint_fp var_expected = {{0x3B0AFEF8, 0xA06C8130, 0x810F6FC0, 0x2E8E6D17, 0x1999E422, 0xE34B6EE2, 0xF9C9B640, 0x4FEF2724},
	{0xE517623C, 0x52B4AE6F, 0xA8E620A5, 0x4448284E, 0x8BF0B449, 0xE6F6A191, 0xCD6D1EA7, 0x48933401},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4476 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4477 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4478 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3EB370C5, 0x5DF5116B, 0x0A87902F, 0x5DC16F6A, 0x04C60B00, 0x53574F21, 0xAFA7DC5B, 0xB13C32C9},
	{0x4592B0E0, 0xB518C25D, 0xA4556C0F, 0xDA83C0FA, 0x7B82A472, 0xD9170756, 0x1986B032, 0x28294921},
	0};
		static ecpoint_fp var_b = {{0x8B8FCD46, 0x0FA43405, 0x7CA57515, 0x1E64D2E4, 0x805068AD, 0x8880624A, 0xE983AA59, 0x7A4D204F},
	{0x2BD9F080, 0x4C1E4D60, 0xE1E32B28, 0xD2D10332, 0xFA8AF0BC, 0xBB81430F, 0x094C7B54, 0xAD21B31F},
	0};
		static ecpoint_fp var_expected = {{0x4FEAEEB2, 0xFB96A8C8, 0x411B1ED3, 0xC0E93461, 0x78B0A071, 0xF54ECED3, 0x8B8AF86D, 0x54F00BDA},
	{0xD6FB1929, 0x7CD919BC, 0x1F8D5631, 0x4DF32D35, 0x278BD7BB, 0xD6D74D65, 0xFB77A351, 0x1BA4AA8C},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4479 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4480 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4481 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x50A8FE40, 0xB4BEC057, 0xD0EA5E87, 0x81B758EC, 0x75694C6D, 0x2A9A8ECE, 0xD8418C22, 0x5AAC8E5D},
	{0x6B3C336D, 0x962446AE, 0xB2745BA5, 0x882CB65C, 0x2832F174, 0x8839E562, 0xBB9E151D, 0x2DF9BBAB},
	0};
		static ecpoint_fp var_b = {{0xC7D6BACE, 0x4363F809, 0x2B9378B2, 0x0A00C341, 0x4B1DBDF8, 0xFF1FAAA5, 0x3077840C, 0x2070E337},
	{0xECA1A824, 0x1928436C, 0xC38773B7, 0x0DFE6FAD, 0xF2D791C0, 0xB732245D, 0x64A809E9, 0x8B4DEDAA},
	0};
		static ecpoint_fp var_expected = {{0x79B05FD2, 0x6BB0555D, 0x8E3BDE2E, 0x0703E25E, 0x481692F2, 0x97ABAB7F, 0x446370FD, 0x68C5C1B2},
	{0xB1371D4D, 0x710E9AC5, 0xF6F30C18, 0x6622DD8D, 0x358EC049, 0x5C11FF10, 0x76DBAFA7, 0x41A6C4F0},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4482 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4483 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4484 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3E141837, 0x62CEFE1C, 0x08172D4F, 0x45EA276F, 0xA79A4BA1, 0x252DD2B4, 0x6E0E7ED1, 0x4B0F8A7B},
	{0xA7E36E55, 0x943BF21D, 0xABC9ECDD, 0x16423DE4, 0xEAFE8255, 0xF9375864, 0xC5CA7D02, 0x3C72CC4A},
	0};
		static ecpoint_fp var_b = {{0xE800E66D, 0x436B43C8, 0x09D61556, 0x4391CCBE, 0x2013C6D6, 0x486C33DD, 0xC26C7026, 0x28B07195},
	{0x2AAAEED2, 0x473D10A0, 0x7C840A6A, 0x5069D71E, 0x715AF055, 0x9DF87E97, 0x9289090E, 0x888A2294},
	0};
		static ecpoint_fp var_expected = {{0x03DAA954, 0xA2A0BEFA, 0xC58A91B4, 0xDE716E9E, 0xBB6B8862, 0xC66CE514, 0x8267AB5A, 0x95C05586},
	{0x64AFC10F, 0x761EE06D, 0x231003BD, 0x8BC60DAF, 0x3CBE7DD1, 0x7E38FDCE, 0x1848BFC4, 0x1A3AF2DC},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4485 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4486 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4487 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x96BBE9C1, 0x7FC8C5D3, 0x37E64398, 0xA13F21A9, 0xEBFEBEB8, 0x0942D2A8, 0xA079B35F, 0x323E4606},
	{0x68AB892B, 0x3E6BC3BC, 0x12EDF297, 0x0A2E4714, 0xA3044129, 0x85102309, 0x165911B2, 0x7F3EBF8D},
	0};
		static ecpoint_fp var_b = {{0x2D76F7F4, 0x162ED315, 0x31526C62, 0xC1569002, 0x37A5CA50, 0x992F78CB, 0x7E4685DD, 0x21AB4EEA},
	{0x0F39108B, 0x2C679382, 0xEEC0FF00, 0xBDEFCD51, 0xBA1D0E01, 0x35E1286C, 0x216BC58D, 0x72E358F9},
	0};
		static ecpoint_fp var_expected = {{0xB7888E14, 0x9266C458, 0xA1599043, 0x7F46A468, 0xA7CA8FA7, 0x70C3939F, 0xEA13B84F, 0x4E0E8DAF},
	{0x93D021FC, 0x06E7F894, 0xEB3E231C, 0x54C1EF40, 0x53C3DCBE, 0x02277502, 0x761A96AC, 0x1E706468},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4488 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4489 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4490 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8D63A7D1, 0x050A425E, 0xB2323AE3, 0x91C0F7AA, 0x26D1E2F8, 0xCB721B02, 0xA163A956, 0x4BCB1D36},
	{0xD41F35A7, 0x10200E4B, 0x4E9B066D, 0xAE97C9AC, 0x7C53903D, 0x82C03500, 0x4386BDC9, 0x438B0963},
	0};
		static ecpoint_fp var_b = {{0xD9875FA7, 0xD703B4BF, 0x44754E24, 0x3AA15236, 0xB0AA0C51, 0xF22C2CCB, 0x3871791B, 0x8796DD3B},
	{0xBD87EC86, 0xAB14CA81, 0x0903FF15, 0xA83BE277, 0x0DA20363, 0x02456FB5, 0x149D847A, 0x53796B15},
	0};
		static ecpoint_fp var_expected = {{0xFFFC30AD, 0xDF9C5CEB, 0x09803837, 0xF9A66C6D, 0x29C62B67, 0x23E7B907, 0x6B5A18E4, 0x293FC7DC},
	{0xC96468AF, 0x132010F5, 0x37147410, 0xBEA95FBD, 0x685F6928, 0xEDD0425C, 0x1AD4649E, 0x5B871B75},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4491 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4492 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4493 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x10830BE6, 0x60B48C2F, 0xA4972071, 0xA22A8D7F, 0xA8DE7037, 0x18757480, 0x7149C299, 0x510E4B75},
	{0x896BE653, 0x86B1BB3B, 0xD090BB6E, 0x8BC83C9A, 0xBEFB5569, 0x40347628, 0x73EAAEB8, 0xACEA776C},
	0};
		static ecpoint_fp var_b = {{0x41DE9C89, 0x542BC9F1, 0x9516ADCA, 0x975DE16B, 0xA5BD847C, 0x94B25935, 0xA674051C, 0xB988FF0F},
	{0x2DA85BAF, 0x35154898, 0xCBD49BFC, 0x873F0713, 0x04DFD717, 0xD6D85B8E, 0x0F2D63C4, 0x4758F735},
	0};
		static ecpoint_fp var_expected = {{0x338BEE31, 0x3DAF6D74, 0x47B30678, 0x288EE565, 0xC93E4035, 0xF86C4497, 0x9925F962, 0xB5CD5A69},
	{0xFB7E17AD, 0x0C85AA8E, 0xA743007A, 0xEB3F1189, 0x2140BF35, 0x54B7F6C1, 0x905AB592, 0x27FD628B},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4494 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4495 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4496 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7673BB4F, 0x755C1833, 0x8D052B22, 0xB0AD5B91, 0x55764011, 0xE828EF50, 0x793C4875, 0xA736A742},
	{0x78538953, 0x6801B7E0, 0x03147120, 0xB45C71B9, 0x852CB853, 0xAEEBE1FF, 0xA80BE3A4, 0xA5ADC010},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x3D40FCD3, 0xDC13555C, 0xFDA3D742, 0x60B5D45A, 0xB9B2CC5B, 0x64D9A308, 0x02739B78, 0x619D6EF6},
	{0x2902B175, 0xD422FD3D, 0x3B43A55C, 0x7DCF9C35, 0x8B1A2E8E, 0x65FA71A3, 0xD3C4E675, 0x0644FEB6},
	0};
		static ecpoint_fp_proj var_expected = {{0xE38DFA9A, 0x5BA59C27, 0x12A69A35, 0x438B23EC, 0xFEC1263A, 0xA61DBE61, 0x290E5373, 0x82E01067},
	{0x370B9D04, 0xDDFBB676, 0xEE394784, 0xCF8C65F7, 0x08D79C45, 0x82408695, 0x3D3EA17A, 0x36C9CD3B},
	{0x28F9761F, 0x65A5C6DA, 0x45168B67, 0xC31A256A, 0xB81F15FE, 0x78111023, 0xC9562F2B, 0x747A6675},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4497 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4498 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4499 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4500 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x6F48371C, 0xF3C413C5, 0x4EBCFECC, 0x77EEAC07, 0x7B21D28A, 0xCBCA7F8B, 0xA77EE6ED, 0x032B5351},
	{0xCC02B36D, 0x35C78AFB, 0xF907C7A9, 0xD0E398AA, 0xA0874AC8, 0x582077CE, 0x9EAA0EC7, 0x255254DB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x741C6147, 0xFFCD3EED, 0x3A0F4533, 0x165C73C4, 0x276EF0FB, 0x01686551, 0x30639826, 0x4ED0104D},
	{0x1B6CCC47, 0x687A5F79, 0x2F5AAB90, 0x919CA2D7, 0xD64C0D5D, 0x2E5358E4, 0xCCE9A696, 0x868C06E4},
	0};
		static ecpoint_fp_proj var_expected = {{0x15F018CC, 0xA1982044, 0x8B8E9414, 0xE081AA09, 0xA9C70B8A, 0x44782BA1, 0x831BD1E1, 0x6BD1566A},
	{0xC5C6A162, 0xCB983DBB, 0x1A41716B, 0x3ACC185A, 0x3B2FB9CE, 0x7387AD38, 0x964C3DCA, 0xB370598F},
	{0x04D42A2B, 0x0C092B28, 0xEB524667, 0x9E6DC7BC, 0xAC4D1E70, 0x359DE5C5, 0x88E4B138, 0x4BA4BCFB},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4501 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4502 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4503 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4504 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x422E018A, 0xC5B3B694, 0xDB3CAA28, 0xF8AE38F2, 0xF66388B6, 0xD9F74F4A, 0xB7F5E3F5, 0x91C9F23D},
	{0xBF206706, 0x48D99D1D, 0xEEDDCD71, 0xCF815DA4, 0x05B6EE7D, 0x2F284F90, 0x9FCCE03B, 0x9A7506BD},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xC1A93189, 0x8C6ACFAD, 0x908BC957, 0xEA5FBBE0, 0x67CDE9A2, 0x28305E5F, 0xFC3D59E8, 0x8D52CB50},
	{0x04631EA3, 0xDD61EFB1, 0xF66DB702, 0xAD20234A, 0x0A4FACA8, 0xAA5BDB29, 0x0B747ADD, 0xAF7C5C4A},
	0};
		static ecpoint_fp_proj var_expected = {{0x7B558F5B, 0x89708204, 0xEDDC5AFA, 0xB085BC43, 0x209CFDAB, 0x66CF24CB, 0xEF124A0A, 0x9C1A8184},
	{0x582DDA14, 0x2C95864C, 0x7A632E60, 0x26839C6C, 0x6102730E, 0x8BB4F1E3, 0xDBDED6BA, 0x95B9B9E2},
	{0xE1A7649A, 0xC5A5A2CA, 0x89C6FE75, 0x04C32F8E, 0xC54CEAA1, 0x49996B7F, 0x8466521B, 0xB59C77D5},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4505 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4506 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4507 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4508 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x68F166AB, 0xDF399C33, 0x6A9DEA04, 0x1489F44F, 0x1A62320F, 0x2B998155, 0x29E5CA0F, 0x83B271B1},
	{0xFA0F1519, 0xD4A43159, 0xC1A49243, 0x3E62E677, 0x3D8D16B6, 0x3996974F, 0xCFFD6C0D, 0x5773DD98},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x162086DA, 0x639F7544, 0x377F6007, 0xE284D831, 0x61B7F2E7, 0x3EC33417, 0x88D7025C, 0xA65C8F0F},
	{0x44198D16, 0x1F90CC2A, 0x89C8B092, 0x6CF6BC49, 0x81E1F6C7, 0xBAF9F8BC, 0xB0E28096, 0x74582B1E},
	0};
		static ecpoint_fp_proj var_expected = {{0x52F56A31, 0x48D70912, 0x6E1EDD95, 0x6F775A9F, 0x017316C9, 0xF769BA95, 0x76ECD040, 0x12A701F8},
	{0x93FF809A, 0x440BD392, 0xCFE11B54, 0x15F6CE67, 0x6BE2D378, 0x187989E9, 0x79C83B81, 0x8F06ECCE},
	{0xAD2F202F, 0x8465D910, 0xCCE17602, 0xCDFAE3E1, 0x4755C0D8, 0x1329B2C2, 0x5EF1384D, 0x22AA1D5E},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4509 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4510 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4511 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4512 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5FE105CA, 0x2B137BA8, 0xEAAA9D5A, 0x713E9A7D, 0x24D0C656, 0xB128DD96, 0x44833386, 0x81505C47},
	{0xA6CA94B0, 0x53A3FF57, 0xCDE79683, 0xC676098E, 0x582BC3C4, 0x36BC2E3B, 0xEA0D554A, 0x7ECA4057},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x6EC2119A, 0xDE3B6178, 0xC32E560D, 0x513D2676, 0x1633144D, 0x1E8B2662, 0xF633962F, 0xA44226EA},
	{0x32A4C0DC, 0xF204DA55, 0xAA9799EF, 0x9B092E8B, 0x849BE496, 0x4266DE4C, 0x494A3C71, 0x57852E48},
	0};
		static ecpoint_fp_proj var_expected = {{0x12B2D2A5, 0x7A94E0D7, 0x117E95BB, 0x88407397, 0x3CBFCEE2, 0xDF38471D, 0x1B485016, 0x0EA4F94C},
	{0xF2D122D8, 0x415F46EB, 0x19BF608A, 0xEE3297D1, 0x9C367DF6, 0xAE666814, 0x2D6AE0E4, 0xB0BAEBD9},
	{0x0EE10BD0, 0xB327E5D0, 0xD883B8B3, 0xDFFE8BF8, 0xF1624DF6, 0x6D6248CB, 0xB1B062A8, 0x22F1CAA3},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4513 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4514 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4515 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4516 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA54E1803, 0xD90F4E9D, 0x6462A702, 0x36A78FED, 0x03CB5F88, 0x82B48620, 0xF38C50DB, 0x6BD6E68C},
	{0xA5A9111B, 0x3222D212, 0x37C83EDF, 0x178A633B, 0xD82EFDB6, 0xA2811118, 0x3FF571CF, 0x94AC3462},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x0640C77E, 0xAD448CC7, 0x6F5A16D0, 0x6411A879, 0x5FEC5CF1, 0x976CAC88, 0x39DB8C2E, 0x163B1DAA},
	{0xBD1A2C38, 0x7B71A5F7, 0x25F2A92D, 0x353ECA94, 0x6C110197, 0x4A72E214, 0xCD566D2C, 0x15DD73DF},
	0};
		static ecpoint_fp_proj var_expected = {{0x135C276B, 0xCE560F25, 0x3C34EEDC, 0x7E537B55, 0x9BC9ACAF, 0x27167117, 0x0ACE1842, 0x8C30C5D7},
	{0x65A87310, 0xDAF785AA, 0x294AFDD3, 0x48515EB1, 0x1CE6AF31, 0xEB95F805, 0x13E7ED63, 0x0FD9BD56},
	{0xC31EE416, 0xD323C7DA, 0xDF6F4F14, 0x407BC52C, 0xB003871E, 0x101882D3, 0x866E177C, 0x6477D5DF},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4517 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4518 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4519 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4520 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x29B2DDD2, 0xEB5AA0BF, 0x87856C16, 0x89C5CB1D, 0x0D38EF95, 0xE9E5C877, 0x2D2A51B1, 0x00D0ABA9},
	{0x75B4246C, 0x29B5C36A, 0x62DEBB19, 0x0B760879, 0xD70A44DC, 0x5F00FD2D, 0x710CDDB7, 0x26252485},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xC0CA4413, 0x7DE71B10, 0xB62421D8, 0xE7C53C64, 0xD0381B51, 0xD2F2E776, 0x8C5446E0, 0x5E6F477D},
	{0xA6E7AD48, 0xC0D89A87, 0x79B7F888, 0x9ADEF9BF, 0xDAEBEC81, 0xC82F0ACF, 0xF3501FF3, 0xB5EAD4C5},
	0};
		static ecpoint_fp_proj var_expected = {{0x6328024A, 0xB5B11F81, 0x424D2470, 0x70629054, 0x7F7585E0, 0xFCD2575C, 0x372C7405, 0x5E2B42F8},
	{0x541F8558, 0xB9335364, 0x3A75A509, 0x6B2AB14B, 0x764A9930, 0x8104FDE1, 0x9EC7813F, 0x162A133A},
	{0x97176641, 0x928C7A51, 0x2E9EB5C1, 0x5DFF7147, 0xC2FF2BBC, 0xE90D1EFF, 0x5F29F52E, 0x5D9E9BD4},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4521 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4522 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4523 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4524 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0B33101B, 0x97B3EB91, 0xD34FA71C, 0x2BB041A7, 0xFA17420E, 0x1F761D83, 0x4D0307EC, 0xB5AFD9B0},
	{0x09014F67, 0x649FDD59, 0xB52151EE, 0x69C1BE43, 0x02884949, 0x5B11FC2E, 0x631F5D15, 0x45306972},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x65E48636, 0x6D91222F, 0xD9C283A2, 0xE2866C6A, 0x2733F53D, 0x633976E1, 0x93147EF7, 0x113663B7},
	{0xA1F9C683, 0x9330365A, 0x445CEF4A, 0x8A00F2B9, 0xCB5C3C3D, 0x225F4174, 0xF84318DC, 0x3CBA1209},
	0};
		static ecpoint_fp_proj var_expected = {{0x7568AE0E, 0xD6DA1925, 0x65124D9D, 0xD2D0D3FA, 0x581940C0, 0x1426A9DA, 0x2E3B83B2, 0x08A213D1},
	{0x63867E61, 0xC9BA34BF, 0x529C4072, 0x9D8D76E6, 0x033F04DF, 0x9A7610F2, 0x83343310, 0x1708F252},
	{0xBCDDAAB6, 0xD4CBC04F, 0xDAEABBCC, 0xC9E7D763, 0x80FF3CE4, 0x3F23B5C8, 0x86305334, 0x159A28C9},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4525 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4526 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4527 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4528 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x17BF131F, 0x88287E6E, 0x2C37649B, 0x20F4BA9E, 0x5AD6C3A4, 0x1EE32D87, 0xF9CD7C46, 0x0120C207},
	{0xFFD3554A, 0xEC8A2141, 0x79401429, 0x04FA343D, 0xB75276CE, 0xD1570212, 0x5703F238, 0x37389D61},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xFC05DC10, 0x004A67F0, 0xE3F598B4, 0x8CF63760, 0xCD26CF41, 0x5C6CD32B, 0xD4D22EE8, 0x4CCF6723},
	{0xA6886FF9, 0xE73F13C7, 0x9065E412, 0x655A531A, 0x2504AA8F, 0x1A8917D8, 0x812B8957, 0x6B085F6E},
	0};
		static ecpoint_fp_proj var_expected = {{0x678364D3, 0xFF385271, 0x6E62D59B, 0x394E0037, 0xFDFA6A80, 0x3376A8BB, 0x6AC0953C, 0x989B8670},
	{0x56575C1A, 0x7EB21A24, 0x439AD188, 0xA2C246D0, 0x1E2C4684, 0x8E713715, 0x8271E91F, 0x3194A73B},
	{0xE446C8F1, 0x7821E982, 0xB7BE3418, 0x6C017CC2, 0x72500B9D, 0x3D89A5A4, 0xDB04B2A2, 0x4BAEA51B},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4529 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4530 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4531 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4532 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x4125B059, 0x9587FF4F, 0x4F87B70A, 0x5E2739DF, 0x2A7C065A, 0x64D248F4, 0xEF2446EC, 0x3A2E1E11},
	{0xD61710CA, 0x8D3DBEE0, 0x0E20DC67, 0x8F51BFB1, 0x65A34009, 0x4DD2B115, 0x208DA4F3, 0x8B29CBDB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xEB73D621, 0x59AE8628, 0x92E4133C, 0xA5EF7FDD, 0x79FDD73C, 0x894F08A3, 0xDE35D1C3, 0xA66EEC45},
	{0xD483FB6C, 0x75113907, 0xC1523BCD, 0xF2BA7367, 0xCD562F45, 0xA039BC68, 0xD929A148, 0x4AE14E23},
	0};
		static ecpoint_fp_proj var_expected = {{0xDC210DE4, 0x1B227BC7, 0x5DEAA5C9, 0xDE0D79F8, 0x1CE1C6E6, 0xD1770591, 0xEAB1D584, 0x8B9485DE},
	{0x2374201F, 0x8AFA4389, 0xBD454172, 0xE04E237C, 0x95025BD8, 0x98F8847C, 0x24E9B97C, 0x7C201F2C},
	{0xAA4E25C8, 0xC42686D9, 0x435C5C31, 0x47C845FE, 0x4F81D0E2, 0x247CBFAF, 0xEF118AD7, 0x6C40CE33},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4533 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4534 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4535 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4536 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xBDA377D1, 0x41AB9502, 0xB36A69DC, 0x790C3D56, 0xEA852C26, 0xE7E86968, 0xD8AB2F4E, 0x1C2F5CD2},
	{0x433F98A3, 0xBEC4FB0E, 0x7BE94FEE, 0x3172E640, 0x14F9A24A, 0xEAB5A036, 0xFBF74EB4, 0x3A7C2761},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xC98A1803, 0xDA2901B3, 0x469FCD0C, 0xA844B838, 0xACCA148F, 0x6656DF55, 0x6BB7FAA8, 0x15A3147D},
	{0x6A902C6E, 0x498739CD, 0x1219A7D9, 0xB9AEE190, 0x7D44A290, 0x9CF87B89, 0x982CA641, 0x31B2F487},
	0};
		static ecpoint_fp_proj var_expected = {{0x70FF8902, 0x0BF98626, 0x6F7B7BA7, 0x46AAC809, 0x681650C1, 0x7CF12388, 0x8E1B8D97, 0x436A6144},
	{0x8A0AE0DF, 0xAD91ED66, 0xE3E25F6F, 0x1046D3F2, 0xED62B9F6, 0xFF16A210, 0xF7EE9A62, 0x3121E911},
	{0x6E12D4CD, 0x976BF662, 0x67AD4277, 0x424A2782, 0x1627721E, 0x79CED258, 0xD32BA782, 0xB387566C},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4537 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4538 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4539 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4540 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF2DC8D08, 0xAB45AAF6, 0x4BC5B058, 0x4DE40C3C, 0xCE9C7FA5, 0xFD45299F, 0x7767F5D2, 0x9664E4BD},
	{0x5A0B13DD, 0x3E3D21F7, 0xC4041678, 0x5A81F248, 0x8F25E66B, 0x81425D0F, 0x982B1C05, 0x070D0162},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x98BAF627, 0x01B543C2, 0xBAB33B00, 0x9C5086A1, 0x727CB339, 0xF26A1C57, 0x3457C422, 0x2E3620E8},
	{0xB3FB34D2, 0x4A5D3D09, 0x120CC5CC, 0xB31D3289, 0x1D336DB2, 0xC54C92BC, 0x8DF4840C, 0x9C3908D9},
	0};
		static ecpoint_fp_proj var_expected = {{0x3D87C1F3, 0xE830B3AA, 0x8829BCBC, 0x0A35BEEE, 0xDCCCFF0A, 0x2AAC23CD, 0xD2BD31FF, 0x0715728A},
	{0x16996217, 0x1D0B8229, 0xA9568324, 0x4D3A415E, 0x4FD4668D, 0xFB84729A, 0x2EB036B5, 0x53F790AA},
	{0x080A9DBA, 0x555E227D, 0x436569EE, 0x617E2706, 0xF7C2BD49, 0xF0854F22, 0xFD0EAA78, 0x51E4DAEC},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4541 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4542 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4543 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4544 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA759F6C8, 0xE6D9C9E5, 0x78F184C4, 0xFECD87AA, 0xEEA62DB0, 0x440F30D0, 0x33079E1D, 0xB657DF04},
	{0xC1B99942, 0x3DD773EB, 0x8F8A6D54, 0xEF46E5F1, 0xA032C91A, 0xA51C680E, 0x2B0A0965, 0x516047AF},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x2BD56BED, 0xE8665EEE, 0x7D2D0776, 0xE268C49B, 0xFF2542D1, 0xE4553A88, 0x823FAB13, 0x8203E41E},
	{0x9D609A1C, 0x31A6FF8B, 0xBDC39582, 0xDB1FDAB5, 0x0CA4A9F9, 0xD68321DC, 0x2CBCA7D8, 0x1C4129E7},
	0};
		static ecpoint_fp_proj var_expected = {{0x74EE1F63, 0xBF08D002, 0x32FB243B, 0xD5185146, 0xB9391ACA, 0x7EB11FA0, 0x4860E493, 0x345A08AE},
	{0x81D481AB, 0x9715C7CB, 0x2F2624A4, 0x55432641, 0x4D2D712A, 0x2CB50285, 0xC7B19F7A, 0x017779C3},
	{0xE6A7A9C0, 0x007B1EB9, 0xD8B361F9, 0xF6ACE991, 0x64619ED5, 0x9BA66623, 0x8F56E91F, 0x85BFA3DC},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4545 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4546 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4547 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4548 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xFD60B9F7, 0xC3DBFA1C, 0x30D27FDD, 0xB4DB9B9F, 0xFD2C365E, 0x332E09F8, 0xAD8851EA, 0x626F2D35},
	{0xD5848A8A, 0xBA434E7A, 0xD4FFFE51, 0x05C576B5, 0xE47A125D, 0x04F2752F, 0xBB6262B9, 0x88FE5C5C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0xB2CF0F55, 0x3B110B75, 0xBDF000C9, 0xBD257E29, 0x8E9C67F0, 0xC1B62C69, 0x374C749A, 0x4DED25F2},
	{0x4F9F43C7, 0x85EBBAC0, 0x3E09F2CD, 0x9E1C39BE, 0x505450B9, 0xDBD10C9B, 0xB9B45ACC, 0x630C3410},
	0};
		static ecpoint_fp_proj var_expected = {{0xB16F0FAC, 0xEC5FD7D9, 0xC9C9100D, 0x5E5AD06D, 0x9C38811E, 0x0CEE6073, 0x15F5E145, 0x067351B9},
	{0xC846900C, 0x07ED82CD, 0xF342F929, 0x992C9874, 0xDEE2AEA6, 0xC10387E0, 0x039913F1, 0x826A1837},
	{0x179A89F9, 0x76239B0A, 0x61956032, 0x1B5B8F2B, 0xE552BB47, 0x89E87EDB, 0xC9E2FED9, 0xA591977E},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4549 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4550 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4551 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4552 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x1BE9303A, 0x5B4C43F9, 0xE31441F6, 0x2B6032D4, 0x109C13D4, 0x84D78EBA, 0x941C21BE, 0x27C21C0C},
	{0x57ADD9A6, 0x463CFC8F, 0x1E0EBD80, 0xAA0A792C, 0xE227EE04, 0xE5CC9BA3, 0x1592DE6A, 0x0E15F06E},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x6BD99AE2, 0xC41D8EF8, 0xEDD54652, 0xB1519D66, 0x1BE1CF3B, 0x7BFD6E88, 0xC59558B3, 0x3DE4ACB7},
	{0xBD34ABFE, 0xCC2D64E0, 0x2D9BE5A6, 0x61B68956, 0xFB2AC9F9, 0x9F71D991, 0xC6FBC5D4, 0x4F2DA003},
	0};
		static ecpoint_fp_proj var_expected = {{0x254DC68D, 0x0EE9FF65, 0xB9010EB7, 0x9A9BBF75, 0x5ABD513C, 0x5E0501F5, 0x826C900C, 0x7F254257},
	{0x11527F1C, 0x37BF8F08, 0xF9346DDF, 0x9F7E7E62, 0x562CE8CC, 0xC30AA17A, 0x7FA29813, 0x174A746A},
	{0x4FF06AA8, 0x68D14AFF, 0x0AC1045C, 0x85F16A92, 0x0B45BB67, 0xF725DFCE, 0x317936F4, 0x162290AB},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4553 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4554 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4555 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4556 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x6AFEBF1B, 0x3FA36FEA, 0x125D7CD6, 0xA67B5428, 0x4F052FBF, 0x647C3357, 0x3826E270, 0x63233FCC},
	{0x5F8BADE7, 0x2AF58127, 0xF3685CC0, 0x9DF1AD2E, 0xBEB38BD1, 0xDDDAC94F, 0xB37EBD6A, 0x04D26CEB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp var_b = {{0x03353E5C, 0x43758C5C, 0x428AA51E, 0xC4209EF6, 0xBE5B3223, 0x1299DD2C, 0xB87351C3, 0x65D39107},
	{0x23298617, 0x0256EB89, 0xFE6FE41D, 0xFB5DB896, 0xEE22D9FA, 0x63D4A008, 0x565E52BB, 0x996D988A},
	0};
		static ecpoint_fp_proj var_expected = {{0x1D83C468, 0x10DF21A8, 0x31BAEDE2, 0x1EDB2CBB, 0x68FC2E90, 0xF2C4F497, 0x66DD96E1, 0x702831DD},
	{0x61090314, 0x53597D2C, 0x2611269C, 0x6BFB8C02, 0x4B3881E9, 0x2BF2A3BA, 0x6D1DC21D, 0x175B8F5E},
	{0x98367F41, 0x03D21C71, 0x302D2848, 0x1DA54ACE, 0x6F560264, 0xAE1DA9D5, 0x804C6F52, 0x02B0513B},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4557 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4558 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4559 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4560 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7B880114, 0x3A2B8569, 0x90415A03, 0x8D3425F6, 0x0695F8BA, 0xA5D1928F, 0x7F14E3A1, 0x66340B23},
	{0xFDA1FF4C, 0x2E072E18, 0xA4B3DAF2, 0x03A28161, 0x58060005, 0x94B41F8F, 0xCF021AA0, 0xB8E485DF},
	0};
		static ecpoint_fp var_expected = {{0xFD55ED29, 0xD64BAD0B, 0xCCF2B434, 0xACE4EFAF, 0xFFCF9A76, 0xC4422AF6, 0x8022DE49, 0xA8D2C866},
	{0x1DFE5930, 0xD0B662C5, 0xB91A6A88, 0xEBC91D82, 0x2D7DA566, 0x15DBA0C4, 0xC5C4225E, 0x6206BFDA},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4561 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4562 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4563 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA9B72345, 0x7338592B, 0x401F3321, 0x861544C6, 0x637E46D0, 0x4C419EBA, 0xEFEC919F, 0x272CA5C3},
	{0x2764B11B, 0xFC8D2861, 0x4139F904, 0xCEEE626D, 0xD61B30E0, 0x63333FCC, 0xAA4D2F6D, 0x51773DBE},
	0};
		static ecpoint_fp var_expected = {{0xE52B0848, 0xD60D32E1, 0x1C97DD60, 0x62324437, 0x68308836, 0x00711564, 0xCD383349, 0x395A5E6C},
	{0x4A8F2F01, 0x4F09A006, 0x8D4C7DE6, 0xFBDB96C5, 0xAFAC8A8A, 0x98C0FEDF, 0x6DA36C9D, 0x86EC9306},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4564 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4565 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4566 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9048AD6F, 0x0C45A936, 0x2F80AF7D, 0x3D0FE036, 0x56C960AE, 0xA82AFE7F, 0xC744FB68, 0x26A13343},
	{0x7A72B9DC, 0x2E9343C1, 0x73A6B1A6, 0xBBE05698, 0xC8D9C147, 0xF9ED6FB2, 0xF8EA5ACD, 0x09D7F6EE},
	0};
		static ecpoint_fp var_expected = {{0x3E94051F, 0x39D83A22, 0x813CD0AF, 0x59EFDA8F, 0x0D5C7251, 0x3F5320C5, 0xABFF2160, 0x96108CD0},
	{0xC8424028, 0x73D3B9CD, 0x49D2C3A3, 0xFBF181E9, 0xC0AA4F9D, 0xEC6E9EFD, 0x254FC4E9, 0x5BF212F1},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4567 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4568 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4569 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB81B7A38, 0x19EB00F4, 0x9ED7E4BF, 0x6D140193, 0xCC2179CC, 0x9BF26534, 0x4C0CF150, 0x339EC5DA},
	{0xC5F0E0F8, 0x82434B25, 0x67A2B7B4, 0xCF5ED99F, 0xBFC7E310, 0x90215364, 0x214B69AD, 0x4FFF95A4},
	0};
		static ecpoint_fp var_expected = {{0xEC7D89A0, 0xDBE61FFC, 0x7DF3415F, 0x3AE0FD56, 0x40D9150F, 0x200E221A, 0xC1BF789F, 0x2AE70217},
	{0x2797974B, 0xCE2981B2, 0x4F0F1746, 0x6CB5D776, 0x3EB6A4A8, 0x69A7E240, 0xAB2A93F4, 0x5D324F0C},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4570 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4571 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4572 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x45295092, 0x9ABA4D47, 0xF8EEA044, 0x81B3C82D, 0x93B5E870, 0xB6080022, 0xB4E8F4CC, 0x4D2F356D},
	{0xA55886A9, 0x0313844E, 0x9812B14A, 0x92E5B51A, 0xDDA1D626, 0xFB72CB8C, 0xB3135FE6, 0x2021EA8C},
	0};
		static ecpoint_fp var_expected = {{0x9C4E80B9, 0xBE263508, 0x544886A1, 0x5642EFD6, 0xD482985A, 0x4F187C52, 0x1F4284C9, 0x87E23A31},
	{0x3DD65F71, 0xFB96DA6F, 0xFECE0BDB, 0xF14B3CD7, 0x5705F4C4, 0x821DBCBB, 0x2EA1F9D2, 0x98E9006D},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4573 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4574 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4575 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7916087F, 0x9BDCAF12, 0x599D467D, 0x3B131C71, 0xE0483486, 0xAA6D06D0, 0xC8F6644C, 0x71AF4AA6},
	{0x1CAB27D9, 0xEB4EC337, 0x2302234E, 0x308F201E, 0x180CB830, 0x5A8BA5F0, 0x0F527E01, 0xB3752711},
	0};
		static ecpoint_fp var_expected = {{0x4932736D, 0x009CAE39, 0x2202BF96, 0xE92421C2, 0x540437C8, 0x4964200E, 0xB3F9B614, 0x14D81FA5},
	{0x423C6184, 0x22DB80F7, 0xB164FC19, 0x8AFF6C3A, 0x89D65BA7, 0xE1BD437E, 0x9486C618, 0x965C723A},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4576 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4577 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4578 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1DFEBBD8, 0x7A46F68B, 0x6FB63271, 0xCFE7B8B1, 0x8B20B96E, 0x108E5C32, 0x2A451B3C, 0x06927ABF},
	{0x8A6E0783, 0xDE3F2E86, 0xCFFBC0B9, 0x22EA2DEF, 0xAC394643, 0xC54E4663, 0x3880694D, 0x13BED20C},
	0};
		static ecpoint_fp var_expected = {{0x9F360C8C, 0x4B29C01F, 0x397E1F69, 0x68C7CCCD, 0xB0D3DF87, 0x53A15CA9, 0xBF5A3660, 0x1620A61E},
	{0x7AD2AA52, 0x44AF3A9A, 0xDE88843C, 0x70724B24, 0x18A57CF5, 0x7BCFAB62, 0x8FF6B475, 0x97BEB7C2},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4579 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4580 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4581 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x573D702E, 0xEC6AE63B, 0x475A153C, 0x9554022F, 0xFDEE8FB5, 0x438BD453, 0xE43A1AF0, 0xA348FFBA},
	{0x6367FBC3, 0x45B659BD, 0x165EDC18, 0xC930C012, 0x95CE1DAF, 0x12666CF7, 0x108645B2, 0x03CC0D46},
	0};
		static ecpoint_fp var_expected = {{0xAB72E4C0, 0x4856CB68, 0x5FCDA2E5, 0x79F96540, 0xAED889EF, 0xE5845412, 0xCFF74E82, 0x4203DA47},
	{0xD13C3996, 0xA9CF55AC, 0x9351A174, 0x3D390FF7, 0x57675323, 0xC02961A3, 0x143C10A5, 0x4F5861D2},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4582 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4583 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4584 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB865B873, 0x2C2D9135, 0x4F433728, 0x398C7E4D, 0xC46EE2F6, 0x0663DCA4, 0xD1DB80F5, 0x52D1E71C},
	{0x0C7D76AF, 0x9D5CB430, 0xCF23BC38, 0xFCDA9DFF, 0x9390F294, 0x5244F696, 0x4AFD2FC4, 0x0041A73E},
	0};
		static ecpoint_fp var_expected = {{0xA5AA3A02, 0x7E84DC78, 0x6F146D1E, 0xE2DECDDA, 0xCC965E7C, 0xE7339B30, 0x30745CE3, 0x031B3188},
	{0xDDD4DBD9, 0x0DBFDD00, 0x56923E25, 0x24652EAB, 0xCF1D5914, 0x97C53681, 0x03827374, 0x10DC0D06},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4585 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4586 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4587 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFE2304F2, 0x0E949E7F, 0x53AA2779, 0x218C51F7, 0x300D29B7, 0xE20BF61C, 0xAEB4C74B, 0x5DFA197C},
	{0xF6ED7713, 0x2C342F02, 0x916BA7A6, 0x0F147A53, 0x4EF0261D, 0xD31A9000, 0xBD62970E, 0x2138AF84},
	0};
		static ecpoint_fp var_expected = {{0x451ED3ED, 0x3694B98F, 0xEBCB0281, 0x7A793953, 0x1B85BC35, 0xF8C1E3EC, 0x9F99E1EB, 0x65E4C96E},
	{0x2FA32832, 0xBB20B4B6, 0x53F3B8A6, 0xE3D064CC, 0x11474C8E, 0x3318F573, 0xAAB99BC2, 0x8BD5A196},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4588 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4589 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4590 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0B514404, 0xA1CF89B4, 0xABC5A779, 0x55F4887A, 0x5CA0F343, 0xBE07392B, 0x9C695DFF, 0x36547D27},
	{0xBB4059D2, 0x03A98D5A, 0x081A02DE, 0xEFD11822, 0x5DDA9186, 0x01404853, 0x10079CC7, 0x157C8270},
	0};
		static ecpoint_fp var_expected = {{0x6499FA45, 0xCA4A604C, 0x07CB7C28, 0x26840654, 0x2D396566, 0x004117D6, 0xE9260100, 0x637384BE},
	{0xCC05C764, 0x0BA34CA1, 0x95E40A20, 0xA635A4FF, 0x0FE169EF, 0xAFEE0C16, 0x51AB23E3, 0x1144ED4F},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4591 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4592 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4593 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2AB15DBB, 0x14288690, 0x8F85B399, 0xCEFDC729, 0x3E583C99, 0xC228800E, 0xDD08B46E, 0x00F495BB},
	{0x5A857EBC, 0xF8070BEF, 0xF1087093, 0xD43B87A4, 0x5CAA8AD2, 0x93EE66C2, 0xE8ED2FA4, 0x2C0DF783},
	0};
		static ecpoint_fp var_expected = {{0xBAD4943E, 0xB0BD5B31, 0x0E7050B4, 0x9B6DA848, 0xC8241AA3, 0x23DC3084, 0x0AB4598C, 0x4C2B3E2A},
	{0x606158AF, 0xA07E5EB8, 0x68AF5339, 0x1EE47476, 0x0455A2BA, 0x1ECD1928, 0x7238F38D, 0x33157330},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4594 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4595 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4596 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAA14B3D2, 0xFD90F5B0, 0x96013023, 0x92B3E77D, 0x746C1DA3, 0x8A58E3CD, 0x303C1440, 0x61537ED0},
	{0x215C06F8, 0x89381CB9, 0x3F7C8F39, 0xDA06ACE9, 0x625CBCC2, 0x822AF658, 0xF3DCF3EA, 0x01AECB70},
	0};
		static ecpoint_fp var_expected = {{0xC56A048C, 0xFBE07584, 0xF0387B3A, 0x421050C5, 0x92DD0C31, 0x9EB4C06C, 0x3C04E774, 0xAEE2273A},
	{0x4F284A6F, 0xA0A80AF6, 0x01CAE06B, 0xF0C33322, 0x6BA109AD, 0x6594199B, 0x0E120030, 0x021DAAC0},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4597 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4598 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4599 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x55CC7157, 0x053D59B5, 0xD53BC4B2, 0xDBF206D2, 0x3352E88F, 0x95086C09, 0x5A9156DA, 0x3377E4CE},
	{0x856051CF, 0x4F7A9987, 0x5BE267CB, 0x10FBCAAB, 0x138D18CC, 0xFDD7A301, 0xAAB93EFB, 0x595EA426},
	0};
		static ecpoint_fp var_expected = {{0x1E63E723, 0x01894F19, 0x8CE6B233, 0x992B06BF, 0x8F08E49E, 0x497875C7, 0x1AA7A5B8, 0x22D02F89},
	{0x0D3A9623, 0x0A8519E1, 0x727F87FE, 0x53073C33, 0x27EBF650, 0x293F10ED, 0x0D051FC8, 0x6F4FDF73},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4600 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4601 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4602 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDDF624F3, 0x39A10435, 0x675EACF0, 0xCF85C229, 0x374936C6, 0x96EA8D55, 0x7D47EBDE, 0x1C514318},
	{0xB38995C6, 0x43FDB0CF, 0x718A534B, 0x799F43C4, 0xCC94914C, 0x25DD711A, 0xFFD31D76, 0xAF7E84A1},
	0};
		static ecpoint_fp var_expected = {{0x0EA8BF4A, 0xA4A77CC1, 0xAF7A717D, 0x96660EE4, 0xDB80152F, 0x11C2662B, 0xF1AF73EF, 0x9DC2A69D},
	{0xCD149FAF, 0x44FDC060, 0x8C130B69, 0x57414F4C, 0x143DEAB6, 0x7204A15D, 0x8E6CBC74, 0x47CF95B1},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4603 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4604 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4605 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x33406CA2, 0xA58ADE97, 0xE184B695, 0x30EF827A, 0x4010969E, 0x1B17731F, 0x47EC5582, 0x0DE8EE5D},
	{0x74BBDD6C, 0x6429BF53, 0x3E0B69F5, 0x729430F9, 0x0138EBCA, 0xD5ED82F4, 0x19C6278A, 0xB0CF6C8F},
	0};
		static ecpoint_fp var_expected = {{0x5633E9D2, 0x0B250BD2, 0x41749183, 0x4DFADB93, 0x536FEFE5, 0xB5F9B950, 0xE542F346, 0xAC5B79A1},
	{0xFF1A566D, 0x63E755CB, 0x6CECA262, 0x39DCCFD6, 0xE7C4B208, 0x795F72E8, 0x64E5BC3F, 0x4965A5C2},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4606 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4607 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4608 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x3F0AE9F0, 0xDF74F490, 0xFCD91C81, 0xD185E062, 0x33532491, 0x006A099B, 0x1B4653E0, 0x093447EF},
	{0xF974B6A3, 0x51355896, 0x9F3F606C, 0xAFCB01A5, 0x2C2ED324, 0xE1C83D9A, 0xC7687C23, 0x0299806C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xD5BF2281, 0x92D0FBE0, 0x01FC6347, 0x50817A8A, 0x6996ABDE, 0x754AB737, 0xBAD44FFA, 0xB5171491},
	{0x61AD2D56, 0x8B33D746, 0xCED968F1, 0x8BD54BB5, 0xE3406D01, 0x385D787A, 0x4A3666DC, 0x179B02AF},
	{0xF2E96D46, 0xA26AB12D, 0x3E7EC0D8, 0x5F96034B, 0x585DA649, 0xC3907B34, 0x8ED0F847, 0x053300D9},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4609 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4610 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4611 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4612 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xC8BE53FF, 0xBE9B645C, 0xF1AFE919, 0xF19F979C, 0x02E06232, 0xCCD7F0FE, 0x2628A2A4, 0x3E9379AE},
	{0x7A8F7938, 0x55AAC645, 0xA59DC5A2, 0xCC0D8798, 0x3A90EE58, 0x2E5BCEBC, 0x16372FE2, 0x5DEA8B46},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xCE4CA39B, 0x2AC26B64, 0xF0D98427, 0x018B7E82, 0x81D1CA24, 0x2DC093E4, 0xCD122D48, 0xB351B38C},
	{0xCFCBA9D7, 0x00396158, 0x5A7213B6, 0xEB784C46, 0x338B9DED, 0x5272977E, 0xB7074875, 0x8D973282},
	{0x92F2BDD5, 0xAC6702D9, 0x76C3ABFD, 0x85096290, 0x213F52FC, 0x6157410D, 0xEC4F839B, 0x01C177C9},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4613 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4614 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4615 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4616 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x2227EBBB, 0x4AAA0707, 0x4561EAF4, 0x8ECA49DF, 0x8522110A, 0xF872AD98, 0x2C83AA19, 0x2FC22A58},
	{0xC65B8131, 0x8C9ACAD3, 0xBE0BC200, 0xE351BF89, 0x74C7EA6F, 0x74880A90, 0x9A4EA265, 0x2319827D},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x349BAA0B, 0x3F1C0836, 0x6A7EE9D1, 0x7BEABB66, 0xBCBA7343, 0x0CE3D73C, 0x8283DAD3, 0x3D3B2DDB},
	{0x39BB5759, 0xD3B05C15, 0x3A47A345, 0xDCD4132A, 0x3435C64E, 0x31630EB1, 0x3E3442CF, 0x8E7C1D54},
	{0x8CB70262, 0x193595A7, 0x7C178401, 0xC6A37F13, 0xE98FD4DF, 0xE9101520, 0x349D44CA, 0x463304FB},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4617 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4618 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4619 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4620 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xB14DC85A, 0xFA7195FC, 0xDB830284, 0x28E5D7FE, 0x1B8B8979, 0x033DB5D4, 0xA33E603C, 0xA99D6F9A},
	{0x0BD9F0CA, 0xB2F8FF2D, 0x6474787C, 0x9471DB4D, 0xC966CE3C, 0x804BC072, 0x19A98D13, 0x775D6F3E},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x7A06B046, 0xC7757025, 0xEC5C9602, 0x6A232519, 0x018EDE36, 0xD526A778, 0xBCEFDD60, 0x10BCE014},
	{0xD77190C7, 0x44FCA746, 0xA8DEE480, 0x93021477, 0xA8D2B80B, 0x7E39F790, 0xE61A5380, 0x8C89B8CD},
	{0xB587ACF9, 0x670374A8, 0xF47111B2, 0x15D209F9, 0x3EEB12C4, 0x0537247A, 0xF3343DFE, 0x34A73FB9},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4621 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4622 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4623 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4624 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x63F800C8, 0x5F885C8E, 0xEF5140F0, 0xFF2E2F6B, 0xD14701A9, 0x92F56008, 0x9A650E57, 0x5B3F6F75},
	{0xEA9F48B4, 0xE2AC8159, 0xDA8E8D45, 0xB9E29A10, 0x78A61F99, 0xE2F2D4F7, 0x2AF68691, 0x15B2FEFC},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x384B1326, 0xAD7A6284, 0x4338160E, 0xD9EEF762, 0x6186AFAB, 0x6BBD3928, 0x62E414EE, 0x92F3B665},
	{0x6D2ADBAB, 0xF660793F, 0x5A9A120F, 0x96D3E6C5, 0xA2F03067, 0xDB2C50FD, 0x157718BA, 0x80875EC3},
	{0xD53E9168, 0xC55902B3, 0xB51D1A8B, 0x73C53421, 0xF14C3F33, 0xC5E5A9EE, 0x55ED0D23, 0x2B65FDF8},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4625 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4626 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4627 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4628 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0B737CE9, 0xDF6AE0D4, 0x13BFCB83, 0xE48C5EC0, 0x65ABBF35, 0x6885CE41, 0x55910A3E, 0x1BAB54A4},
	{0x3EBD0032, 0x5DBE837D, 0xFDACE75B, 0x9AC8CA33, 0xE51C1271, 0xAC78139A, 0xFCF81FF7, 0x775D921A},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xE682F9DB, 0xBC856652, 0xDAFC4745, 0x3E8D9508, 0x9E55F66B, 0x3B4DC9E7, 0xDF4B651D, 0x7A023329},
	{0xE1E88C4D, 0xC58DD780, 0xC588CD4C, 0x23365B4C, 0x57BBDF80, 0x3532275A, 0x05729527, 0x37AFD14E},
	{0x1B4DCBC9, 0xBC8E7D49, 0x26E1EF6F, 0x227FE7C7, 0x76559B2E, 0x5D8FCACA, 0xB9D163C6, 0x34A78573},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4629 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4630 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4631 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4632 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xFBF6C185, 0x37222F19, 0x9DD0947E, 0x35B3E73D, 0xB6B43D2B, 0x29DCD59F, 0x1E4D4A13, 0x5D309FBD},
	{0xDE150208, 0x440CC999, 0xA9C36D16, 0x40089FE0, 0x0C14C218, 0xEC93FCBF, 0x8D42AE2C, 0xA0B4FB7D},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x24CF79CA, 0xA61B6A48, 0xE284043C, 0x6C1CD4BA, 0x49F34F62, 0xBEB23F90, 0x03C22318, 0x7C5AAA9C},
	{0xF2A9F36B, 0x47083D9C, 0x438FCA1B, 0xB7E60154, 0x5AB01987, 0xA4D642EB, 0x3F077D31, 0x1D9203BA},
	{0x59FDCF75, 0x892B0982, 0x7F0EFAE5, 0x6CFF9320, 0xC446FA7B, 0xDDC79D12, 0xDA668030, 0x87565838},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4633 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4634 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4635 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4636 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x90339A02, 0x77A5F94D, 0x9095193C, 0x5F93E96F, 0x81C82004, 0x922A0B3F, 0x400FA756, 0x78BBC5CD},
	{0xC85B4F30, 0xAB3D68CC, 0xB95520C4, 0xDC79F860, 0x218C87CD, 0x80EA08A9, 0x0F15B086, 0x04CB27FB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x4C1B990E, 0xDEC1D09A, 0x50F072D4, 0x6948AD72, 0xA4467CFC, 0x132B2FE3, 0x4F2C7973, 0x44F3E163},
	{0x3B7A9374, 0x0F1791DD, 0x477D59BB, 0x8C7AB827, 0x9AB745A3, 0x6DEEACF2, 0x8C362ADF, 0x80254481},
	{0x90B69E60, 0x567AD199, 0x72AA4189, 0xB8F3F0C1, 0x43190F9B, 0x01D41152, 0x1E2B610D, 0x09964FF6},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4637 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4638 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4639 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4640 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7DB99AAA, 0xB922E4B7, 0xDF318C36, 0x1E06D815, 0xDBAD7CDA, 0x0DAB0E2D, 0x8FD02B5F, 0x88FAFE23},
	{0x173A4375, 0xDE92C6A7, 0x2764B001, 0x5924276A, 0xC9C07F93, 0x62F3B179, 0x5C51BB6B, 0x95988F3A},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xBF43FC5D, 0x058681CD, 0x29287ED9, 0xB3120448, 0x769B5EC5, 0x858840B2, 0x57449FFC, 0x815A0170},
	{0xB66EA845, 0xDAB58C77, 0xC9515C76, 0xF8CFF0EE, 0x6725E331, 0x50C037B7, 0x4E026B3C, 0x3A111544},
	{0xCC48524F, 0xBE37039C, 0x7A5180BC, 0x9F36A233, 0x3F9E7571, 0xCA870688, 0x78849AAD, 0x711D7FB2},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4641 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4642 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4643 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4644 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x76F3882E, 0x6D492D0D, 0xA8B61661, 0x458937AF, 0x32DCEED9, 0x9EFF8C17, 0xCCF738BC, 0x9696A3E0},
	{0x67119D0B, 0x7D94BDF4, 0x1841E3C6, 0x72096C90, 0x1C35B731, 0x45C45ED3, 0xBF9520C4, 0xA9DCFF76},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x4B2FA13F, 0xF5EFA6F9, 0x57A78E8E, 0xDE5AE063, 0x30E2600C, 0x1D51BE17, 0x702AA69C, 0x255C06AF},
	{0x62FA11E0, 0x83B6A018, 0x10FC54C5, 0x995B8276, 0xDF0C6E0E, 0x5A116B6E, 0xBAD3E628, 0x78EB5210},
	{0x6BF7057B, 0xFC3AF237, 0x5C0BE845, 0xD1012C7F, 0xE488E4AD, 0x9028613A, 0x3F0B655F, 0x99A6602B},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4645 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4646 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4647 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4648 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8AAB3A2E, 0x593306C1, 0x944A2085, 0xA325304F, 0xAB5175C8, 0x19D665AD, 0x19E8F9C6, 0x19FB89F9},
	{0xDD546A62, 0xAB97C615, 0x64DEA315, 0x310C5164, 0x4071F103, 0x19F0A070, 0x0C05499F, 0x767914C0},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xC407A099, 0xC5E1EBC8, 0x41537E12, 0x60B5D689, 0xE7C4C3F8, 0x51777B53, 0xA828156E, 0x32A816DC},
	{0x4A483B49, 0x2BCD1906, 0x78AD88CD, 0x576AC9FC, 0x32E8C605, 0x976A1538, 0xAE3579D3, 0x6330381D},
	{0x587CA029, 0x5841027A, 0xF54566E4, 0x4F06F627, 0x2D015851, 0x3880E475, 0xD7EBB715, 0x32DE8ABD},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4649 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4650 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4651 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4652 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xCD6D7004, 0x7F59D591, 0x23EB317D, 0x98264DCD, 0x9C4ADC89, 0x621CDDD2, 0xCCC6A63E, 0x393FF2FC},
	{0x0831C924, 0x90EA604F, 0x8DC4A9CE, 0x13CACF97, 0x59E36FC9, 0x4A4E18B6, 0x7FB07C78, 0x204E10C1},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x9500D03B, 0x17A14DA7, 0x6DF275C9, 0x1B77406C, 0x5EEF4682, 0x14A8155E, 0xDD5F0E54, 0x13BBE3EF},
	{0xD8F661BA, 0xC233821D, 0xC34FED73, 0x2410E5E5, 0x2257624C, 0xCB1C4621, 0x5C6A64C9, 0x7179C1C1},
	{0x10639248, 0x21D4C09E, 0x1B89539D, 0x27959F2F, 0xB3C6DF92, 0x949C316C, 0xFF60F8F0, 0x409C2182},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4653 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4654 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4655 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4656 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA2015C78, 0x124FB4CC, 0xC6F1B1E7, 0x7BA619D5, 0x645CCD0B, 0x79EF2470, 0xF99841A2, 0x0BBA0A2F},
	{0xF48A1CA6, 0xB1D156A3, 0x93431C88, 0xA62E89FF, 0x9F531465, 0x622DFA1F, 0x0A5CC269, 0xA238C3A7},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x966ADD3F, 0xC65583F1, 0x5ED32AA4, 0x36A47653, 0x1E86CCAC, 0x90442FCA, 0x3F64017D, 0xA9FCA948},
	{0x2AD3677B, 0xCAAB48BE, 0xB03D4E37, 0xB1E8DEF7, 0x037DC6A3, 0x80BC14A5, 0xC061E826, 0xA9277649},
	{0x86E804B1, 0x64B42396, 0x520E59CA, 0x394B675E, 0xEAC39F16, 0xC8FB97D3, 0xD49AA8A9, 0x8A5DE88B},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4657 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4658 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4659 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4660 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x29AF637D, 0x03D67471, 0xEC05F586, 0x542B96C5, 0x367315E8, 0x4CB1FF5E, 0xEC498205, 0x4F9498E8},
	{0x6150E719, 0x0FDD3B17, 0xD992563A, 0xAFE195F9, 0x9004FD73, 0xD60A1251, 0x4781D0ED, 0x9A27DA8B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x245A87F2, 0x736AA5D2, 0xCD1AE895, 0x24955A50, 0xEA0E6F90, 0x24E2C6E2, 0xD9D1303D, 0x548EE694},
	{0xFA47DF74, 0xEB16CDFD, 0x3777C377, 0xA8D375A5, 0x566712C2, 0xC4D63471, 0xEB577E46, 0x2AD6302C},
	{0x60759997, 0x20CBEC7D, 0xDEACCD2D, 0x4CB17F52, 0xCC277132, 0xB0B3C837, 0x4EE4C5B2, 0x7A3C1654},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4661 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4662 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4663 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4664 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x9736DB77, 0x985DC0EB, 0x9DD53F28, 0xDB349CB2, 0xAC0476C0, 0x731BA354, 0xCBC6E31B, 0xB26D5BE5},
	{0x090BC9BB, 0xFB243EA4, 0xE7C276FB, 0x456F4413, 0x70059ECA, 0x4E884692, 0x8971F666, 0x0039C1CB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x57E250C9, 0x2C2752F5, 0xC7D43B5A, 0xEDBCF900, 0x12873050, 0x3961AABA, 0x0CAFBE70, 0x9B3B3E29},
	{0x119C62A5, 0x386EF9D6, 0x6B0CCE94, 0x07E2DC7F, 0x49754961, 0x86478322, 0xC3912F47, 0x77F18F31},
	{0x12179376, 0xF6487D48, 0xCF84EDF7, 0x8ADE8827, 0xE00B3D94, 0x9D108D24, 0x12E3ECCC, 0x00738397},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4665 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4666 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4667 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4668 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xB31F9CE5, 0x5CC4B9C1, 0xC79B6C42, 0x17039465, 0x36C92AB0, 0x3318617A, 0x75CFF95A, 0x7428544B},
	{0x3705014F, 0xCDCC537E, 0x433ED2F7, 0xB073BAA2, 0x36462741, 0xC973223F, 0x9BCB8868, 0xA3C46FDF},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x3170B63A, 0xE1C946A5, 0x233241EA, 0xC7E71582, 0xBDA9B150, 0x503E82DD, 0x8E42A4DD, 0x8BDECC22},
	{0x5CF905C1, 0x97EE03FC, 0xCBEF5E5D, 0x8B4092A6, 0xE6B8D831, 0x12B08AFE, 0x5018463B, 0x12D6133F},
	{0x0BDDCE03, 0x9CAA1D4B, 0xB205C6A8, 0x4DD5C8A3, 0x18A9C4CE, 0x9785E813, 0xF77834A8, 0x8D7540FC},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4669 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4670 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4671 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4672 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x15E260F1, 0x024E7D66, 0x1B224A27, 0x9AABBC2E, 0xF85AC908, 0x54A66180, 0x396E199C, 0xA6B26A39},
	{0x6E8F3F54, 0x0A889941, 0x1DD1497D, 0x10C8C970, 0x8F0C612C, 0x3D37DA24, 0x7D5BAD37, 0x6EEF58AF},
	0};
		static ecpoint_fp var_expected = {{0x15E260F1, 0x024E7D66, 0x1B224A27, 0x9AABBC2E, 0xF85AC908, 0x54A66180, 0x396E199C, 0xA6B26A39},
	{0xF39CF547, 0xF465F06F, 0xB6A695C9, 0x0248E330, 0xC4D62889, 0xBE288246, 0xC2C32EF1, 0x4B244612},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4673 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4674 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4675 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x318A9B8A, 0x1045E39F, 0x29374D2F, 0xA4252F86, 0x996C641E, 0xFC9FE9CD, 0xBFAF55AB, 0x959CD966},
	{0x34F0F8C7, 0x2F737A25, 0xF9D11FEE, 0x8CF9FEE5, 0xBDFB55DF, 0x73702FFA, 0x75396C5A, 0x61DFD3EF},
	0};
		static ecpoint_fp var_expected = {{0x318A9B8A, 0x1045E39F, 0x29374D2F, 0xA4252F86, 0x996C641E, 0xFC9FE9CD, 0xBFAF55AB, 0x959CD966},
	{0x2D3B3BD4, 0xCF7B0F8C, 0xDAA6BF58, 0x8617ADBA, 0x95E733D5, 0x87F02C70, 0xCAE56FCE, 0x5833CAD2},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4676 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4677 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4678 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x51A1135E, 0x998E4274, 0x800DEA82, 0x728407C7, 0xF1844D46, 0x93D9773E, 0x0D3B3D79, 0x81F94F1E},
	{0xFA517ED1, 0xCD9C6E00, 0xCAD3E3E9, 0x6893FA59, 0x0A354743, 0x971F87B2, 0x4B0B6016, 0x35F94710},
	0};
		static ecpoint_fp var_expected = {{0x51A1135E, 0x998E4274, 0x800DEA82, 0x728407C7, 0xF1844D46, 0x93D9773E, 0x0D3B3D79, 0x81F94F1E},
	{0x67DAB5CA, 0x31521BB0, 0x09A3FB5D, 0xAA7DB247, 0x49AD4271, 0x6440D4B9, 0xF5137C12, 0x841A57B1},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4679 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4680 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4681 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x6248C8F3, 0x44D70DC6, 0x12720F42, 0x52BAE5F9, 0xF979D2E7, 0x9632D853, 0xD807D03E, 0x2803CECC},
	{0x4812CFEE, 0x5F63DA9E, 0x9B005EAB, 0xBEFDF4D8, 0xE3E68AD4, 0x3A0DAF92, 0xEFCF2602, 0xA89087D4},
	0};
		static ecpoint_fp var_expected = {{0x6248C8F3, 0x44D70DC6, 0x12720F42, 0x52BAE5F9, 0xF979D2E7, 0x9632D853, 0xD807D03E, 0x2803CECC},
	{0x1A1964AD, 0x9F8AAF13, 0x3977809B, 0x5413B7C8, 0x6FFBFEE0, 0xC152ACD8, 0x504FB626, 0x118316ED},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4682 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4683 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4684 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA698B0E4, 0x984F4DA0, 0x1A2A14F6, 0xC43E661E, 0x5983A884, 0xC4617D3A, 0xCB54AB8F, 0x43C4A7F7},
	{0x1049D5F6, 0xEFE81A18, 0x48C52ADF, 0x349F4C27, 0xD68CCF97, 0x673AAA4F, 0x19EC62CD, 0xA398DE3F},
	0};
		static ecpoint_fp var_expected = {{0xA698B0E4, 0x984F4DA0, 0x1A2A14F6, 0xC43E661E, 0x5983A884, 0xC4617D3A, 0xCB54AB8F, 0x43C4A7F7},
	{0x51E25EA5, 0x0F066F99, 0x8BB2B467, 0xDE726079, 0x7D55BA1D, 0x9425B21B, 0x2632795B, 0x167AC083},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4685 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4686 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4687 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFA1CA508, 0xFD4F4978, 0x721A50B1, 0x93F3D560, 0xD948D903, 0xA5AEE780, 0x17AF509E, 0x1710C6B7},
	{0x1877A655, 0x6EBC4735, 0x4389E584, 0x1F35F220, 0x5E58D1E5, 0xEB40455C, 0x8D9DB5EC, 0x8374A0A8},
	0};
		static ecpoint_fp var_expected = {{0xFA1CA508, 0xFD4F4978, 0x721A50B1, 0x93F3D560, 0xD948D903, 0xA5AEE780, 0x17AF509E, 0x1710C6B7},
	{0x49B48E46, 0x9032427C, 0x90EDF9C2, 0xF3DBBA80, 0xF589B7CF, 0x1020170E, 0xB281263C, 0x369EFE19},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4688 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4689 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4690 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8E5E46A2, 0xFC6B972D, 0x1B663880, 0x5511D71C, 0x88C9895A, 0xE3C31EC3, 0xF982B70A, 0x0096CB3C},
	{0x8E49FC94, 0xD611900E, 0x921BCA98, 0x013BBBCC, 0x4973C5D0, 0x44A2F6B3, 0x432815F7, 0xADE159A0},
	0};
		static ecpoint_fp var_expected = {{0x8E5E46A2, 0xFC6B972D, 0x1B663880, 0x5511D71C, 0x88C9895A, 0xE3C31EC3, 0xF982B70A, 0x0096CB3C},
	{0xD3E23807, 0x28DCF9A2, 0x425C14AE, 0x11D5F0D4, 0x0A6EC3E5, 0xB6BD65B8, 0xFCF6C631, 0x0C324521},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4691 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4692 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4693 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0B6D8D08, 0x10BD8673, 0xA0E5915C, 0x9EEF8011, 0x84FB5A28, 0xE2EBBF21, 0x7D4E0B48, 0x493723A7},
	{0x66BCF9AA, 0x58BD05D1, 0xEDF4C6ED, 0xB6860BB2, 0x967B15AD, 0x514FFED1, 0xD6A7F927, 0x9C0C875D},
	0};
		static ecpoint_fp var_expected = {{0x0B6D8D08, 0x10BD8673, 0xA0E5915C, 0x9EEF8011, 0x84FB5A28, 0xE2EBBF21, 0x7D4E0B48, 0x493723A7},
	{0xFB6F3AF1, 0xA63183DF, 0xE6831859, 0x5C8BA0ED, 0xBD677407, 0xAA105D99, 0x6976E301, 0x1E071764},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4694 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4695 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4696 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x04AB872E, 0xF3B39854, 0x96903C95, 0xE31A2DE7, 0x95AD061C, 0x54CAFFAF, 0xDAB4BBF6, 0x6A012F99},
	{0xD7020B71, 0xD807DE8C, 0xFB2D8F3B, 0x0E50E811, 0x941D8FBA, 0x9E7AAEB4, 0xDE485E59, 0x6833C804},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x04AB872E, 0xF3B39854, 0x96903C95, 0xE31A2DE7, 0x95AD061C, 0x54CAFFAF, 0xDAB4BBF6, 0x6A012F99},
	{0x8B2A292A, 0x26E6AB24, 0xD94A500B, 0x04C0C48E, 0xBFC4F9FB, 0x5CE5ADB6, 0x61D67DCF, 0x51DFD6BD},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4697 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4698 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4699 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4700 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x2134168D, 0xB40ADEEF, 0xEDA29C31, 0xD7846154, 0x94FF9D6D, 0x52EF0E3A, 0x85EFCE14, 0x3B0AD045},
	{0x4D5209F1, 0x9A4A7CDF, 0x7CC9C41D, 0x5006F092, 0xA637844A, 0xC019C1A4, 0xF9D230DD, 0xAB427D3D},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x2134168D, 0xB40ADEEF, 0xEDA29C31, 0xD7846154, 0x94FF9D6D, 0x52EF0E3A, 0x85EFCE14, 0x3B0AD045},
	{0x14DA2AAA, 0x64A40CD2, 0x57AE1B29, 0xC30ABC0E, 0xADAB056A, 0x3B469AC6, 0x464CAB4B, 0x0ED12184},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4701 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4702 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4703 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4704 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x975BCCE9, 0x480AD656, 0x2A6C02B4, 0xA135AB5B, 0x10655D6F, 0x4472E2C6, 0x3ED022EC, 0x93A560FB},
	{0xB8D3C707, 0x21E25A73, 0xB6461486, 0xB42E7B75, 0x11E2D9B7, 0x88FFDE0E, 0xA8C7DCC9, 0x70ECC8E1},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x975BCCE9, 0x480AD656, 0x2A6C02B4, 0xA135AB5B, 0x10655D6F, 0x4472E2C6, 0x3ED022EC, 0x93A560FB},
	{0xA9586D94, 0xDD0C2F3D, 0x1E31CAC0, 0x5EE3312B, 0x41FFAFFD, 0x72607E5D, 0x9756FF5F, 0x4926D5E0},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4705 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4706 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4707 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4708 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF09715A3, 0xA6A5EE39, 0x3E510675, 0x4F989493, 0xC9EF3DD3, 0x34D320B8, 0x0A812546, 0x745B25BA},
	{0xD4F7342A, 0xA5B2A32A, 0x96294BE4, 0x6C7F222E, 0xE1787DE4, 0xDA2B267C, 0x739A083B, 0x2D84D185},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xF09715A3, 0xA6A5EE39, 0x3E510675, 0x4F989493, 0xC9EF3DD3, 0x34D320B8, 0x0A812546, 0x745B25BA},
	{0x8D350071, 0x593BE686, 0x3E4E9362, 0xA6928A72, 0x726A0BD0, 0x213535EE, 0xCC84D3ED, 0x8C8ECD3C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4709 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4710 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4711 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4712 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x4FB22E37, 0x3AB19257, 0x561FC8BB, 0x4886E959, 0xB2EBFD06, 0xA84F32C1, 0xDDD85A2F, 0x18801EFB},
	{0x916234FC, 0x9FCF8F3A, 0x6CC4506C, 0xD1A20487, 0x07B3A4BC, 0x4FA0C0DC, 0x6E837F31, 0xA158218F},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x4FB22E37, 0x3AB19257, 0x561FC8BB, 0x4886E959, 0xB2EBFD06, 0xA84F32C1, 0xDDD85A2F, 0x18801EFB},
	{0xD0C9FF9F, 0x5F1EFA76, 0x67B38EDA, 0x416FA819, 0x4C2EE4F8, 0xABBF9B8F, 0xD19B5CF7, 0x18BB7D32},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4713 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4714 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4715 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4716 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF3B57F01, 0x8143024F, 0x81BF945F, 0x52233745, 0x26CB2769, 0x1316C9F6, 0x65797CAC, 0x00EAE773},
	{0xA7DA08F0, 0x42AF712D, 0x6EBE31CE, 0xCE151F00, 0xEB0AB628, 0x2002FCFA, 0x8DEFB44B, 0x0606CF35},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xF3B57F01, 0x8143024F, 0x81BF945F, 0x52233745, 0x26CB2769, 0x1316C9F6, 0x65797CAC, 0x00EAE773},
	{0xBA522BAB, 0xBC3F1883, 0x65B9AD78, 0x44FC8DA0, 0x68D7D38C, 0xDB5D5F70, 0xB22F27DD, 0xB40CCF8C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4717 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4718 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4719 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4720 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA093ED3E, 0x4BB0512E, 0x7E678B9C, 0x105EE2C3, 0x76D2108B, 0xD3C631F6, 0x4DEF3353, 0x8B450B17},
	{0x64D67027, 0x4F86DDF4, 0x319AE5C2, 0x7B4E60D2, 0xD1E2BC47, 0x776233A2, 0xE65062BA, 0x05BC7DFB},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xA093ED3E, 0x4BB0512E, 0x7E678B9C, 0x105EE2C3, 0x76D2108B, 0xD3C631F6, 0x4DEF3353, 0x8B450B17},
	{0xFD55C474, 0xAF67ABBC, 0xA2DCF984, 0x97C34BCE, 0x81FFCD6D, 0x83FE28C8, 0x59CE796E, 0xB45720C6},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4721 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4722 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4723 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4724 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF066C791, 0xB3BA04A9, 0x5CAB69B7, 0xAA52EECB, 0x07654ECB, 0x13E1ABD4, 0x674234C0, 0x9E404E32},
	{0x298E045B, 0xFC50FA6C, 0xCEE13385, 0xECCBA7FE, 0xDA8F9807, 0x55CE800C, 0xA0E5E1EB, 0x8ED78F1F},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xF066C791, 0xB3BA04A9, 0x5CAB69B7, 0xAA52EECB, 0x07654ECB, 0x13E1ABD4, 0x674234C0, 0x9E404E32},
	{0x389E3040, 0x029D8F45, 0x0596ABC1, 0x264604A2, 0x7952F1AD, 0xA591DC5E, 0x9F38FA3D, 0x2B3C0FA2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4725 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4726 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4727 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4728 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4729 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4730 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4731 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x6EADD06F, 0x2FAA8B07, 0x426575C6, 0x95F585F2, 0x8A36CB08, 0xCE8E1CE1, 0xB409A4CC, 0x3A26219C},
	{0x1E13BDF9, 0xDBB75C93, 0xB86FD74E, 0x1910B1DA, 0x82482C94, 0xE2C5988C, 0x9908327A, 0x316D362B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4732 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4733 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4734 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x22590BAC, 0x85F7D891, 0x64AE531B, 0x2DA1EA5D, 0xD2DC9E85, 0x306E3782, 0xB0982801, 0x25385AB2},
	{0x7E023C0D, 0x2A8F88D6, 0x70582EEF, 0x56944981, 0x232E059A, 0x234AEE59, 0xA58341BA, 0x0262DD8C},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4735 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4736 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4737 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x4A43DB13, 0x3A690401, 0x7804B9CD, 0xB4C4534D, 0x1100272F, 0xC7076417, 0x29B1AD8F, 0x397FC04A},
	{0xF236217C, 0xE3A01BFA, 0xB51D9FF5, 0x1C1BC7EB, 0x8B77DA2F, 0x6D0817C0, 0x587E9FE7, 0x715F86D9},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4738 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4739 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4740 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0xEA4DD389, 0x0B98FE4C, 0x17862EA0, 0x99E41EF0, 0x49FD0BF4, 0x8E6641C4, 0xAC552009, 0x61FF1B7C},
	{0x46D20F85, 0x48A3B4D0, 0xEA61C66D, 0x634FC8E7, 0xC73A37B5, 0xD7C28A7C, 0x0E3C9547, 0x55C1E009},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4741 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4742 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4743 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x103FD1F9, 0x4517B2AD, 0x0E0FA9B6, 0x13ABD4B4, 0x657DF833, 0x8CDDC94C, 0x8EC1DB9B, 0x9793E782},
	{0x8AD7FF9B, 0x04BA25CC, 0xF04D9393, 0x7455D24B, 0x94ED7E52, 0xF1ED8AEA, 0x759A5D1C, 0x62578F9E},
	0};
		static bigint_t var_k = {0xAFEDCE38, 0x5FEA2167, 0x140BF143, 0x3BE099E5, 0x88AB5CF1, 0x9185D638, 0xA566C726, 0x169F2C4A};
		static ecpoint_fp var_expected = {{0x43407120, 0xB710DB14, 0x9EC2F197, 0x6123105C, 0x62E319E9, 0x3698B77F, 0x9803F2E2, 0x88683C13},
	{0x87160808, 0xFC64077B, 0xA9359B22, 0x920498ED, 0xC7B9E2DA, 0x21D1DA04, 0x2C05E1B6, 0x64AA5741},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4744 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4745 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4746 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAED623F7, 0x08A40B74, 0xAB37662C, 0x0F7D4F1B, 0xB4BA74EF, 0xDC171C26, 0x26B538B4, 0x94640CF5},
	{0xD2BA03F0, 0x81C4DA1C, 0x60CE1D8F, 0x315BD5DA, 0xFE44ED09, 0x23CFD9A5, 0x8F40BB0C, 0xAEBFC142},
	0};
		static bigint_t var_k = {0x99873F35, 0xD82C8B3C, 0xB8F7C753, 0x0887FEE9, 0x5377701A, 0x204F32BD, 0x2A9DD66E, 0x959DFCAA};
		static ecpoint_fp var_expected = {{0xE06BD3DA, 0xFE31FCD4, 0xBDA9104B, 0x097AF361, 0x1AA68663, 0x7E15558A, 0x575FDE89, 0x2E289E10},
	{0x8CBBF8A4, 0xE8D81D7F, 0x8FA282C9, 0xBDD6E451, 0x182BDE32, 0x0F7E322C, 0x64EFA7B3, 0x6DEA1890},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4747 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4748 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4749 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x13CD410C, 0x5D30D53C, 0x352B5E6A, 0x56AB978E, 0x319909E6, 0x034F9BC3, 0x0CCED8EF, 0x6CC92BFA},
	{0x6E00F995, 0xDBE484E0, 0x293603CC, 0xD8070D36, 0x5083630A, 0xA0C7F0D5, 0x96669DCE, 0x6F49AB8A},
	0};
		static bigint_t var_k = {0x49B6C15F, 0xCB750F86, 0x9E22359D, 0x6BD078D8, 0xE62C9ACB, 0x801D1CEF, 0x0507FA4C, 0x18BA7884};
		static ecpoint_fp var_expected = {{0xAA7FF0DF, 0xCD4FF988, 0x5170BFD4, 0x782024B8, 0x59597297, 0x6EE6F5C4, 0x9C72A314, 0x509AE97F},
	{0x68814E5A, 0x8473519C, 0xA4348FED, 0x51D6FBCF, 0x8E160EB9, 0x73110900, 0xA74A3F9C, 0x745A1796},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4750 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4751 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4752 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x81196FB0, 0xAE4C3371, 0x9638A89D, 0x72514462, 0xB73C18D2, 0x11FBC83F, 0x8BC21EE1, 0x46EAF322},
	{0xD9978671, 0x0010A905, 0x1B7DFC53, 0x834DCF95, 0xD5FC483A, 0x0B1BCE3E, 0x428AF52C, 0x5861F076},
	0};
		static bigint_t var_k = {0xFD4742D1, 0x4BAAC9E5, 0x7A2E50C3, 0xCC5CF626, 0xB0E0C4B4, 0xB216469A, 0x9BB517D5, 0x7A50C775};
		static ecpoint_fp var_expected = {{0x9331C176, 0x78F63014, 0x752B3A1B, 0xCF955FD7, 0xF9AE8519, 0x35DBB33C, 0x3E314B7A, 0xA5FE3BE1},
	{0xAB5DE3D5, 0x66F2080D, 0x95EE5AF0, 0x7E5DFC33, 0xB5944C04, 0xC289333B, 0x92A67559, 0x9F864FC2},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4753 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4754 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4755 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAFCC29E2, 0x21F24872, 0xE53C093B, 0x2014A49F, 0xC16B7BD1, 0xA8568FF2, 0x43FA763C, 0xA6E9C5C8},
	{0x7D2D845B, 0x9CA0C2C0, 0xD752859A, 0x8E06CCA7, 0x1C29D798, 0x7785408A, 0x18C9D05A, 0x40849B2A},
	0};
		static bigint_t var_k = {0xDB7856A6, 0xBB268394, 0x6D6F9CE0, 0x9BE87510, 0x08B9A3C4, 0xFB824F08, 0x50BEA479, 0x1A511270};
		static ecpoint_fp var_expected = {{0x44A5738D, 0xCA9DCC13, 0x75CCB9BC, 0x8B041D4F, 0xFCD2C558, 0xDE0F558B, 0x9F9FFA07, 0x371AC2DF},
	{0xBF9CE384, 0xC8442A07, 0x69F16E41, 0x43ADF6F4, 0x0FF086D3, 0xF4D9152B, 0x8BD17D5A, 0x4FF7932B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4756 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4757 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4758 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1A51B17E, 0x1489237C, 0x8D663C18, 0xBA34EB93, 0xC81B6974, 0x35B5E7CC, 0x99E069E1, 0x0528B129},
	{0x618AECD9, 0xD00DDBC1, 0x2D772061, 0xAB937530, 0x1766A774, 0xFC5263B1, 0x7323CF05, 0x0E6292D1},
	0};
		static bigint_t var_k = {0xA2CB4A2D, 0x737906CB, 0x28389DB7, 0x6DEDF5D0, 0xD92ECB03, 0xCFBCF703, 0xCB260182, 0x7D339D2E};
		static ecpoint_fp var_expected = {{0x35177708, 0x69AC310F, 0x6FC8ED3F, 0xE4BE1F54, 0x4D663D38, 0x56A8269B, 0x58CCC263, 0x6195E37F},
	{0xC59598B2, 0x680AAF8F, 0x23E107E3, 0xE458C987, 0x81FEF48C, 0x67E2543E, 0xEF3E5D2F, 0xADC30324},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4759 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4760 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4761 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x95B1F592, 0x19E22E0A, 0x0D1BEA11, 0x1D5AD1C0, 0xADA57D6D, 0x2C43039C, 0x32F980CA, 0x2614FA0E},
	{0x9A556D50, 0x8C6C7F28, 0x38C805C6, 0x829A64C0, 0x724A1ECF, 0x9580F84C, 0xD43669E3, 0x802F0C41},
	0};
		static bigint_t var_k = {0x4EC8171B, 0x7E1D105A, 0xA52F7E94, 0xC00FD65B, 0x53FC4954, 0xFC804B35, 0x70FC61FE, 0x10C14C3B};
		static ecpoint_fp var_expected = {{0x734E0B84, 0xD05EE179, 0xE2C76B32, 0x982B3B6D, 0x1C64EE32, 0x6FE66A6B, 0x3DF1A650, 0x001860EB},
	{0x526EFE56, 0x396880E8, 0xD0646FF7, 0x9D0CCBFB, 0x0CFD8AB9, 0x39B492A2, 0x1145762E, 0x44E8C907},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4762 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4763 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4764 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x24B37F29, 0xDD01E16D, 0x9B96DE1A, 0x5317EB94, 0xEFCAAA0A, 0xA73AF68A, 0xAEA12C8B, 0x8764BC14},
	{0x07BF3380, 0x19187CA0, 0x3E41CE04, 0x770AD4A0, 0xF5DB3845, 0x36CDE0BE, 0x5997FA71, 0x9B9C992B},
	0};
		static bigint_t var_k = {0x71DD12EC, 0xD8DF9547, 0x6B9BEFF4, 0x35D1A89E, 0x37CE9B2E, 0x7FBE6D25, 0xE3DC6154, 0x656A6094};
		static ecpoint_fp var_expected = {{0xE4A2D13B, 0x0394FC6E, 0xD3D6967B, 0x28B2F168, 0x95AB65CD, 0x4DC913B2, 0xD6E283FB, 0x36448E52},
	{0x8A0FB0DC, 0x3C4A7D4A, 0x8B54104F, 0x3F1FA427, 0xF287E175, 0x80B87496, 0x5B87223A, 0x3F2AF4A7},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4765 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4766 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4767 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5FAE4DD4, 0xFC00D409, 0xC826717F, 0x5E55344D, 0x44D2FDF9, 0x2C8F41E5, 0x07E1C488, 0x420EC553},
	{0xCFA7B24A, 0x5109DCBC, 0x5BBF378B, 0x8490384A, 0x895CB57C, 0xBD9AE6B9, 0xD6488A72, 0x7161042A},
	0};
		static bigint_t var_k = {0x88278545, 0xD444AC3C, 0x71B216CB, 0x760F7890, 0x32A31B9D, 0x99C65A1D, 0xCBA91F93, 0x96749D10};
		static ecpoint_fp var_expected = {{0x13E51160, 0x36FA6027, 0x5CC21CC2, 0x2EE41DD1, 0x61258AD6, 0x378BC5F3, 0xD0BB32CD, 0x7FDB6ABB},
	{0x079CEC5B, 0xFE52174E, 0x51935F5D, 0x21ABA1CB, 0x6E74A907, 0xC4F34715, 0x367589E3, 0x3232F85D},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4768 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4769 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4770 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3E5F44C2, 0x878C56CB, 0x08376B8D, 0x10B9FD35, 0xC181292D, 0x1DF75574, 0x36B29E3A, 0x8A2C6E41},
	{0x1368457C, 0x566311C5, 0xE00610BC, 0x003AA068, 0x154AB31C, 0x678721F1, 0xB412E7C0, 0x3C10436A},
	0};
		static bigint_t var_k = {0xFC411014, 0x1498BC53, 0x16ED128B, 0x3293E82F, 0xDD9CBB89, 0xD15BDD63, 0xCCDA1DC4, 0x418959AE};
		static ecpoint_fp var_expected = {{0x7ED7530B, 0x8437FED0, 0x75A494B7, 0x02F5957D, 0x604DE11A, 0x6B937BCF, 0x863D2659, 0x636CDF1D},
	{0x39AEE356, 0xDC1011A8, 0x3C224769, 0xE4F0313C, 0x235A4FEB, 0x90A4BA37, 0x37174B2E, 0xA879BDA8},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4771 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4772 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4773 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD97460A6, 0xBB13D305, 0xC2958752, 0x6BB88787, 0x6E8DC3B2, 0x9548DC60, 0xDDA80F27, 0x0B064975},
	{0xF08677A3, 0x956D8BAF, 0x4CA20D68, 0xDC8E3961, 0x04AF0B40, 0x846222F5, 0x448482BA, 0xB9DE58B7},
	0};
		static bigint_t var_k = {0xC81AE18A, 0x32A70BB8, 0x4F52119F, 0x3EB63C2B, 0x613B02AB, 0xD6A6B53B, 0xCA5FE284, 0x2DA9640D};
		static ecpoint_fp var_expected = {{0x9CEA2870, 0x2DD1B555, 0xA676DF8B, 0xC8D9A044, 0x65E6FD3D, 0xE38F661C, 0xCB92BB40, 0x3EA3010A},
	{0xAB14D9C8, 0x8A9174CE, 0xFF2A00F9, 0xA2675C90, 0x39A275B3, 0x7666841C, 0x3E50AF9F, 0x6944D72A},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4774 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4775 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4776 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x61C51E99, 0x78BE2257, 0x5DA88120, 0x533BDB7F, 0x72708AA5, 0x147E1584, 0x4B6B35AF, 0x21501B8C},
	{0x26AE1AAB, 0xD90E814E, 0x69969901, 0x3F018FB7, 0x4AF10019, 0x5C4080FC, 0x89D04A54, 0x835FC995},
	0};
		static bigint_t var_k = {0x2ABBC86B, 0x777CDE68, 0x50CD8226, 0x57C7C9CD, 0x30568796, 0xBB7CBADF, 0x6CCC2428, 0x05F76443};
		static ecpoint_fp var_expected = {{0x0CAD2CD6, 0xF62DF343, 0xB4DBDDD4, 0x35CF981C, 0xD188A540, 0x9968D51A, 0xDCD6B0D3, 0xA26B0435},
	{0xFA505EB1, 0x39AD7519, 0x8F3573C4, 0xB735BE22, 0xC86792F0, 0xCE9D4522, 0xEE6896A0, 0x9DFF62C7},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4777 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4778 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4779 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE5BD4F50, 0x4374636D, 0xBB520AFB, 0x6E4BB892, 0xBF3E3848, 0xA511DB92, 0x34618CB9, 0xB14A9EF3},
	{0x714A8FEA, 0xAD2AB5B2, 0xCB0528D4, 0x7E49AA85, 0x6A97B2FB, 0xF085EF45, 0x81279FEB, 0x7ECA51EC},
	0};
		static bigint_t var_k = {0xF51E1120, 0x21C4F536, 0xE5777278, 0x60C6DD3E, 0x49C3CA51, 0xBB38960B, 0x95CCA2DC, 0x9C0C6482};
		static ecpoint_fp var_expected = {{0x2941DD49, 0xEB9DEB94, 0x85F80E4B, 0xDCD6BEA6, 0x95E067B7, 0x1AADCFBF, 0xA2B341B1, 0x44EFCB9F},
	{0xE94B2A9B, 0xDC6DD558, 0xD3B9F4F0, 0x38710602, 0x6616356C, 0x345248DA, 0x3227D3BE, 0x41340976},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4780 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4781 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4782 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x05BC0F2E, 0xE6067A15, 0x4C42D51D, 0x11F1C765, 0xE2B2CCAF, 0xE8EA6B5C, 0x77207EF7, 0x979CB9C9},
	{0xA90F0D03, 0x2F5B7A74, 0x9C3467A9, 0x04B9EBA7, 0xE5E364E2, 0xCABF5349, 0x6B4BE340, 0x178ECE46},
	0};
		static bigint_t var_k = {0xE5003894, 0xC131A707, 0x42EDFE5A, 0x41DE17D8, 0x9ABB8AE2, 0x57E77D84, 0x2BE28225, 0x4C28CECB};
		static ecpoint_fp var_expected = {{0x7F0B2109, 0x857AA6CE, 0x076B9BA2, 0x6EC169ED, 0xB14AC0CE, 0x274ABC9F, 0xBD952204, 0xA03D202B},
	{0xA0172742, 0x322B2137, 0xF570C1AE, 0x591DFB07, 0x3C0F28CF, 0x66FB771F, 0xD480320A, 0x1C933165},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4783 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4784 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4785 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x39F327AC, 0x7DC1A4D7, 0xB60EF26F, 0x90777DDA, 0x7F616003, 0x85DE4984, 0x7CB7B2F2, 0x36B159F1},
	{0x85859875, 0x6AE1489E, 0x5C2B0707, 0x9238B201, 0x66EE102F, 0xDE98F969, 0xB43B735A, 0x1581A10C},
	0};
		static bigint_t var_k = {0xF744434D, 0x297FD07E, 0xDCFF278D, 0x24C6CB6A, 0x518DE9E5, 0x4FB776D1, 0x54D25358, 0xADD0EFF4};
		static ecpoint_fp var_expected = {{0x3ED895B2, 0xAC0F0E31, 0xA7E9912A, 0x26CFA5B0, 0x145291C0, 0x227B48CF, 0x3B06F4BF, 0x7E06E71E},
	{0x955AA7E9, 0xD8BA458C, 0x2A0354E1, 0xCDAD4D32, 0x2C3E6B79, 0x79A81090, 0x22E051B8, 0x91C5F213},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4786 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4787 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4788 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFAF563E2, 0x4487AEEC, 0x8C4CD435, 0x98AD2915, 0x5BF0E58A, 0xBEAF7733, 0x6A7F4F34, 0x3E3F7879},
	{0x800A7F88, 0x4DC0BB35, 0x8C898F19, 0x79DA4EF1, 0xA8B019C7, 0xE6D2C568, 0x835550C8, 0x20158FC0},
	0};
		static bigint_t var_k = {0x68C81D4C, 0x687CE585, 0x68098BCA, 0x71513D23, 0xD96B9DD2, 0xA509A3D4, 0x73F5A380, 0x9864981C};
		static ecpoint_fp var_expected = {{0x48606A6C, 0x16E5AAE0, 0xBE9DFC51, 0xAE6FF26A, 0x58EE7BED, 0x857F5F18, 0xE06C8921, 0x7E967A3A},
	{0x72BDB830, 0x28CD7310, 0x0C9DCDD8, 0xEE719A0A, 0xEFEDA4A7, 0xB7D49F27, 0x7AD98395, 0x6508703F},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4789 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4790 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4791 infinity");
	}
	{
		static const bigint_t var_t = {0xFFCE07D3, 0x5A31796D, 0xB6D73C35, 0x4941A3E4, 0x76D85BAD, 0x2D1F1597, 0x7DF15D12, 0x7F1AA863};
		static ecpoint_fp var_expected = {{0x71DBC155, 0xFEB2DB95, 0xD1D999AD, 0xF5981EA0, 0x0697AACB, 0x327553B1, 0xC7C906FD, 0xB59800AA},
	{0x1122E530, 0x3B477EC8, 0x1FDEE49C, 0x97D38831, 0x57845688, 0x37496D86, 0xA3398812, 0x768A4298},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 440 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 441 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 442 infinity");
	}
	{
		static const bigint_t var_t = {0x658B25E6, 0x0A8EDEC8, 0x5E24A358, 0x3E31F2A0, 0x0A399F6E, 0xCFBE9523, 0xD74B21B3, 0x3C980603};
		static ecpoint_fp var_expected = {{0x8274ACC7, 0x5833E652, 0x54AC89C5, 0x776EB9A3, 0x364D07FD, 0x0A8C734A, 0x6008F82A, 0x9F0ACA9D},
	{0x2F2D303E, 0x797F63BF, 0x531CB6BD, 0xD8BC9A2A, 0x7FD9410C, 0xD6AFA3D8, 0x879CCAA9, 0x82520539},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 443 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 444 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 445 infinity");
	}
	{
		static const bigint_t var_t = {0x82396793, 0x10D4DF04, 0xA2054A28, 0x6E3006FC, 0xB3A07B3E, 0x68268916, 0xCEDB44AD, 0x3CD198FF};
		static ecpoint_fp var_expected = {{0x6D56FA6C, 0xF46C64D9, 0xE979A154, 0x9A155B8A, 0x118A22B8, 0xC867E3D7, 0x7AD75169, 0x06B83A4F},
	{0xA2FC58FD, 0x144E277E, 0x70A45786, 0xFAA84AAD, 0xD40F663F, 0xECCC3CC8, 0x7FDAD31D, 0x6BDA9C58},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 446 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 447 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 448 infinity");
	}
	{
		static const bigint_t var_t = {0x466A7E12, 0xD7FC636A, 0xD345FE8E, 0xF4054177, 0x48067F73, 0x152609C0, 0x3E7F6FA5, 0x2567338F};
		static ecpoint_fp var_expected = {{0x4459C197, 0xC8B624A1, 0xD8A56994, 0xD031DD55, 0x9A9F134B, 0xFF3CD0A3, 0x7A856D71, 0xA030E7EC},
	{0xB5B19A4B, 0xCAF58190, 0x0CF5A5F0, 0x86182DEA, 0x57EB9F8D, 0x0E49D949, 0x275C931C, 0x93B84FB4},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 449 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 450 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 451 infinity");
	}
	{
		static const bigint_t var_t = {0x0D275BA7, 0x6300BF82, 0x872A9E48, 0x0FC1EFF3, 0xC46BADA9, 0x7E6E7B44, 0xB5DD840D, 0x8BE92E68};
		static ecpoint_fp var_expected = {{0x159A69FD, 0x729D4ED0, 0x4291B878, 0x54393C89, 0x11C5F59F, 0xFD3909C8, 0xC2C91F81, 0x66DD9C4B},
	{0xE34B7DBA, 0xA28A9749, 0x7D2E2FD6, 0xCA6F486A, 0x433C7D97, 0x89C9A0DC, 0xF07F29F8, 0xA18C8596},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 452 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 453 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 454 infinity");
	}
	{
		static const bigint_t var_t = {0xC4240CB7, 0x8C027D8F, 0xCC842EA8, 0x7145D5FD, 0x80632E3E, 0x93C1713F, 0x76923D8B, 0x296D7C1B};
		static ecpoint_fp var_expected = {{0xA78F00BF, 0x873B2667, 0xD0EC678D, 0xE326F125, 0x75069983, 0x5E9963DF, 0x28ABB649, 0x30C889D2},
	{0x2E5AB91D, 0xC126079D, 0xFA68103C, 0x8FB251DA, 0x77E417B5, 0xDEF71F1B, 0xEB42F2ED, 0x958E95FB},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 455 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 456 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 457 infinity");
	}
	{
		static const bigint_t var_t = {0xC07DFED4, 0xC4A6C6D6, 0xF985160A, 0xF3178950, 0xF7A74ABF, 0xCF3273CD, 0x7797CBDE, 0xA6BD86D9};
		static ecpoint_fp var_expected = {{0x8B2CB43D, 0x415B1CB0, 0xD4C95713, 0x03850300, 0xF63198A8, 0x5E607E0A, 0x1BC75155, 0x3E6C5A10},
	{0x13029FE4, 0x3B4BB2DB, 0xC08CEBD5, 0x9C8E5928, 0xFB767AEC, 0x81A58796, 0x95B5ADAE, 0x5E9661B7},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 458 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 459 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 460 infinity");
	}
	{
		static const bigint_t var_t = {0x99920329, 0xF202E85E, 0x016D6C72, 0xF7165910, 0xA4B136DC, 0xDA570C6F, 0xA2ABDCE6, 0x7377F22C};
		static ecpoint_fp var_expected = {{0x4CE4F1D2, 0xC24E8A76, 0x87DEFDD3, 0x02A05178, 0xC40BAE8F, 0x1C9D9CE9, 0xA0885F1C, 0x0FF909FB},
	{0x0E7391B5, 0x2EDEDB15, 0x9B53E29C, 0x5F80E709, 0xE46116B0, 0x6C82038C, 0x8DA407A0, 0x3BB8E00B},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 461 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 462 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 463 infinity");
	}
	{
		static const bigint_t var_t = {0xF7E415C4, 0xE3B5B78F, 0xCE66E341, 0x241EA2FD, 0xD8F0C8F3, 0xFD4831D6, 0x9744B392, 0x06A85B11};
		static ecpoint_fp var_expected = {{0x0E0A7106, 0x1C17649B, 0x3F1CA4D9, 0x95292B15, 0xF0E6E3AF, 0xBB66F41C, 0xB4889433, 0x3423FCF8},
	{0xF0295209, 0xFAB7D497, 0x68FE19CD, 0xD51E7677, 0x6CC76E36, 0xF7FCEDB7, 0x2CF19CA0, 0xA7783AF8},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 464 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 465 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 466 infinity");
	}
	{
		static const bigint_t var_t = {0x18A6EC84, 0xC79FE1D3, 0xBBD87731, 0xE6EAD01C, 0x3674491F, 0xA6D1051B, 0x29313B86, 0x576A0993};
		static ecpoint_fp var_expected = {{0x7F0FB590, 0x2098B8D3, 0x9908DB4B, 0xB9FBE7CE, 0xBD66E347, 0xCD2B01A4, 0x66C8C46F, 0xAF01556E},
	{0x9048DC52, 0xBD8DA91A, 0x05F2D6E2, 0x8D8BDE1A, 0x83E70B88, 0xF73DF6B1, 0xD734FA39, 0x01ADC6D2},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 467 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 468 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 469 infinity");
	}
	{
		static const bigint_t var_t = {0x4E95024D, 0xB22AA0F6, 0x1A7B6A0A, 0xEC10EB72, 0x35DF1F20, 0xE8304B62, 0xDD0B200E, 0x6493C811};
		static ecpoint_fp var_expected = {{0x2D7AF956, 0x6CA14E9D, 0xCE256B9C, 0xB3348AC3, 0x3B8FDF96, 0x9792670A, 0xF453C9FE, 0x1BD7ADBE},
	{0xD497B6CF, 0xAAF776A6, 0xE08E88A2, 0x9F3F2B1E, 0x66F21B31, 0xB579EBF5, 0x826B822E, 0x167874A1},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 470 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 471 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 472 infinity");
	}
	{
		static const bigint_t var_t = {0x7F2E2AC3, 0x1C232647, 0xB04394A7, 0xA8FE9139, 0xA2B0D92F, 0xF86995CE, 0x6E7D4F94, 0xAD6EBF1E};
		static ecpoint_fp var_expected = {{0x38709968, 0x4A3E6BC0, 0x4622CBE0, 0x7A5AB439, 0x71EFA053, 0x23613E1F, 0xF94453F0, 0x5E7FD59F},
	{0x7332B1BE, 0x4C301AAF, 0x1AE290A2, 0x77C9FFC8, 0xE5CA08E9, 0xB9C86FA7, 0x0192FD7F, 0x80555F52},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 473 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 474 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 475 infinity");
	}
	{
		static const bigint_t var_t = {0xA42809AA, 0x62203BB1, 0x34205DA4, 0xD211B299, 0x1BD94267, 0xB124AAD7, 0x4B4F91A8, 0xB88A4C55};
		static ecpoint_fp var_expected = {{0x4328CC1F, 0x6AA50E22, 0x815B84B7, 0xE7AE656B, 0x2424F3F4, 0x25A98B67, 0xE8838775, 0x521FA519},
	{0xC8E49EA2, 0x232A949B, 0x372783ED, 0x3780FF52, 0x0866929B, 0x03E9F7A4, 0xF888EF83, 0x224BF95E},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 476 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 477 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 478 infinity");
	}
	{
		static const bigint_t var_t = {0x4A441582, 0x427DCCA8, 0xD380DF9C, 0xE6BB4FF0, 0x94A18A8E, 0x111EAB6D, 0x174E1FBC, 0x8E9542BF};
		static ecpoint_fp var_expected = {{0x7ECB0018, 0xE3BFB01C, 0xCF789B35, 0x8CCE17AA, 0x73E1B03C, 0xDCBD6D41, 0xB6CD2BCB, 0x7AA6633D},
	{0x5D6A83E1, 0x0F03177A, 0xA73D6B77, 0x43BCDC92, 0x80BA6642, 0x3F22B1D5, 0xAD258CC7, 0x939B6DFD},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 479 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 480 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 481 infinity");
	}
	{
		static const bigint_t var_t = {0x146AECC7, 0x63E074FC, 0xAFB2020A, 0xA1B624DD, 0xD6E1AEAD, 0xBA28EE9F, 0x29FC66E2, 0x3C49134D};
		static ecpoint_fp var_expected = {{0x231B7850, 0x329F2357, 0x8C3CD120, 0x9529EAF8, 0xFE8AA7BE, 0x6533272C, 0x00500357, 0xB2C417E3},
	{0x9A281200, 0x6CFE93BF, 0x81242582, 0x22286F2E, 0x9FBD8FA2, 0x8D9BD656, 0x56D48934, 0x1A2C8365},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 482 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 483 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 484 infinity");
	}
	{
		static const bigint_t var_t = {0x361922A1, 0xCB543C61, 0x5B0A9693, 0x8848FFDE, 0xFB86A7A1, 0x72BDA4D9, 0x0A145F44, 0x5468BBAA};
		static ecpoint_fp var_expected = {{0x67586CD2, 0x0D3E10AE, 0x17C4ED0A, 0x33096B1E, 0xE850CF90, 0x3F0AFD80, 0xD184637C, 0x16382AA9},
	{0x8AF27133, 0x59B1D704, 0x0969A77F, 0xF22FF71D, 0x5B6BCADC, 0xC5D79857, 0x03A177E3, 0x686D8F5F},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 485 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 486 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 487 infinity");
	}
#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp var_a = {{0x6B54D66E, 0xB915E992, 0xA343DB89, 0xDAA8933D, 0x7651685A, 0xD62E7D1B, 0x946E12EC, 0x1D712A64},
	{0xF10B22CB, 0x976264FF, 0xDA44C47D, 0x775C136D, 0x81CCCB5D, 0x94D8C92B, 0x25516D10, 0xBB90D9F2},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4481 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4482 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4483 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4484 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4485 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4486 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDA1E392B, 0x61300386, 0xC44FECEA, 0x3B15486C, 0x12C09F03, 0xD7698CB4, 0xB69CCAA3, 0x5CDE9CE0},
	{0x324245C7, 0xA64672A3, 0x22827B69, 0x5232F41F, 0xA4E8E64E, 0x92C2D853, 0x47A1B0AD, 0xA32545E1},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4487 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4488 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4489 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4490 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4491 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4492 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8D93DF15, 0x0575C087, 0x97A5BC21, 0xDECF1537, 0xF6AAB70C, 0x8E31ED70, 0x7924B9F7, 0xE8C71741},
	{0x7DA5FBE2, 0xB50188FC, 0x2C4829CD, 0x72F1FD67, 0x8B5807DA, 0xE4FAF96C, 0x11F2C442, 0xB53E60CB},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4493 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4494 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4495 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4496 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4497 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4498 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1D9C778F, 0x00686744, 0xCC64B066, 0x977C3258, 0x2B84E988, 0x872EE3C9, 0x7BFCE08B, 0x496EBF3F},
	{0x8959E362, 0xC46663F0, 0xC99BF9A0, 0x4A03A58F, 0x6066B539, 0xB8CEF60D, 0x450D7F6F, 0x15C82222},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4499 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4500 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4501 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4502 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4503 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4504 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x63BA50B9, 0xF15E0CE1, 0x55FBA68F, 0x7C5E089F, 0xFA51C3D8, 0x9046D150, 0x9F05E42B, 0x413D8D84},
	{0x50E23E7F, 0x0D0281CA, 0x0A58D7CE, 0x91184F10, 0x8B38B455, 0x7930EAEA, 0xE2AEED3D, 0x28011C65},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4505 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4506 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4507 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4508 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4509 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4510 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7998F2DD, 0xB350A89B, 0x63356BDA, 0xE2A79CCF, 0xEC3E75D5, 0xB56C83B6, 0x061B9215, 0xD71BF15D},
	{0x0BB4CD32, 0x0FE93C1A, 0x403ECE34, 0x3B79337A, 0xB6617154, 0xD687F4AD, 0x2A95BAE9, 0x92CCEDAF},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4511 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4512 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4513 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4514 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4515 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4516 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB798776C, 0x64A583DE, 0x664D4773, 0x5DCA2968, 0xCA29A3AA, 0x44718C78, 0x0F225C45, 0x50BC6624},
	{0x32C3E8B0, 0x868AC79A, 0xFD051144, 0x7D54EF54, 0xCA7078A7, 0xBB8183A4, 0x9D90EF81, 0x3A003CDD},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4517 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4518 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4519 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4520 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4521 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4522 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB665ABBF, 0x6006F543, 0x10FCBC08, 0xC3C6ED41, 0x9D35BA07, 0xCAD1B7E1, 0x5E1AAB05, 0x30ECFEED},
	{0x8014E3DB, 0x707EEE41, 0x106DA3AD, 0xCC10CE8D, 0xEF80EA5B, 0x54E02D8E, 0xFE931FC6, 0x44B50F84},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4523 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4524 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4525 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4526 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4527 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4528 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5082ED29, 0x462E7447, 0x528861FD, 0x297D2C42, 0xAE59CA91, 0x13898F4A, 0xD12D1B42, 0x3CE4DC76},
	{0xEC4CAE54, 0x0956B9D2, 0x8C47A8CD, 0xDE9BC548, 0x8EC9F9B7, 0x104B231A, 0x4DC4F3DF, 0x1498AE54},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4529 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4530 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4531 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4532 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4533 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4534 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9DD9D7FE, 0xF1B800A1, 0x5CD7DD08, 0xE4FC6590, 0x86F1E3BE, 0x2CDFF5C6, 0x8BC09A5F, 0x7A98A763},
	{0xB041C3FC, 0xCE6BDA90, 0xC18F53C6, 0xA7BA2629, 0x512E696E, 0x9B1E30E0, 0xCA881CDA, 0x5138E699},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4535 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4536 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4537 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4538 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4539 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4540 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF64EA993, 0x80F3DC87, 0xA07C1259, 0x88D4C006, 0xEE4CF983, 0x6439D3AD, 0xED806D9A, 0x2E08EF42},
	{0x44884E03, 0x7CB3F3F1, 0x4076807B, 0x5C590167, 0x21CF0FF1, 0xE23C55E2, 0xF89AA6F5, 0xDE58CBE3},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4541 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4542 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4543 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4544 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4545 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4546 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF44D746F, 0x4EAC9C59, 0xCEC95F84, 0xEB61A8D1, 0xF03F447E, 0x46EAD7A7, 0x9677132B, 0xDE8D85F2},
	{0x6206A1D6, 0x118AAF69, 0xDA71EBDF, 0x72DB3C46, 0x269860AB, 0x12DDF3E3, 0x9616B43E, 0xE13FED20},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4547 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4548 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4549 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4550 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4551 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4552 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x715A1124, 0xF9028862, 0xD8DE11DE, 0x21229F73, 0xD3B22F81, 0x9F015232, 0x691714B3, 0x4E2FCD4D},
	{0x0482E492, 0xC985ADAD, 0xA14F1045, 0x9E6B64C4, 0xC9D1F52D, 0x985B8D23, 0xA6899901, 0xC006FDAA},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4553 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4554 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4555 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4556 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4557 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4558 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x84A0D588, 0x5D3852C4, 0xEFB9F0FD, 0x810145A2, 0x2132C5B1, 0x7D1C17C3, 0x874DADB2, 0x84EDF849},
	{0x603114C7, 0x2246430E, 0xE442AC9E, 0xD64B2792, 0xB5B02094, 0x210A1744, 0x69045F01, 0x1EEAE80B},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4559 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4560 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4561 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4562 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4563 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4564 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x89840D50, 0x997E24B8, 0x8447F48B, 0x9EAB91B1, 0xA37E9E98, 0x2D3582FA, 0x50916608, 0xC41442E5},
	{0xF24A39A9, 0xD84311C1, 0x36F5E3EA, 0x4D258DAD, 0xD0E57CAC, 0x9BFFE172, 0x6029A590, 0xE1996B80},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4565 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4566 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4567 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4568 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4569 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4570 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x16333B30, 0x08C9FCA8, 0x47721CA1, 0x4DDB4282, 0x621D5BD3, 0x3B738590, 0x65F487BB, 0x948C118E},
	{0x7195EB12, 0xE8A06B3A, 0x66960D30, 0x7A58DE31, 0x452E88AD, 0x31E81617, 0x4C3DEEED, 0x2E890F7D},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4571 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4572 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4573 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4574 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4575 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4576 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x15DB0010, 0x77A45667, 0x53EB609C, 0xBF5E59E4, 0x24FD6AFA, 0xC7BCB905, 0x459ECB66, 0x1746BE1A},
	{0x908A003F, 0x33E306B9, 0x31A95A75, 0x966776E7, 0x0EE03FD4, 0x02F57B88, 0xC9923C63, 0x1F254732},
	0};
		static ecpoint_fp var_b = {{0x66EFB7DD, 0x58934270, 0xCF6F785A, 0x5069182B, 0xFA8B07F0, 0xD5A871FD, 0x29D2D056, 0x1469E29C},
	{0x8B2578E4, 0xCC1374AE, 0x9F1101B5, 0x8C34B423, 0x007AEA69, 0x466025E4, 0x2D67C32E, 0x1D9CBC2E},
	0};
		static ecpoint_fp var_expected = {{0x34CDDFB7, 0x938D6C31, 0xA25C9CC6, 0x017A784F, 0x38A46BD8, 0x49BBC6AB, 0x761AA396, 0x10195FEC},
	{0x7C7A7F1F, 0x7BA285BE, 0x89B90EE1, 0xABA31F18, 0x6D8EBA8E, 0x3FC05402, 0x4E2162A3, 0x1D6E7838},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4577 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4578 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4579 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF79E8E6F, 0xCF09FD1E, 0x3F8C827C, 0x4D306E91, 0x1E9E9795, 0xAFCEC88E, 0x43E0BE0F, 0x11F0D021},
	{0xDDB95F0A, 0xF7485239, 0x252549BD, 0xF4F7E290, 0xAC3F45C3, 0xC09F1389, 0x805E6DC0, 0x0B09BF6C},
	0};
		static ecpoint_fp var_b = {{0x6EDDCDC7, 0x7142DF04, 0x9AAC13E0, 0xA7FF809C, 0x82E48C1C, 0xFE131229, 0x38A73A20, 0x160315DD},
	{0x373F3BE3, 0x86397559, 0x4923CAC0, 0xFB21F6CA, 0xC380C543, 0xF98DC14D, 0x77575D60, 0x038F025A},
	0};
		static ecpoint_fp var_expected = {{0xCB213C25, 0x7F64E087, 0xB0D02F86, 0x87C0A57C, 0x8F085331, 0x08B93566, 0x97BC2236, 0x09929EE2},
	{0x7DB47768, 0xF7731886, 0xC6E158B4, 0x5C837498, 0x0A4A1E95, 0x5F55028B, 0xD6681009, 0x121FD78F},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4580 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4581 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4582 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x7B82DB98, 0x2E7FB58D, 0xBCF19886, 0xAD246798, 0xB94C2E8D, 0xEEA36C3A, 0xA6040696, 0x0F3E1F59},
	{0xE49E50DA, 0xF0C442FA, 0x75A80BF8, 0x9027EF0C, 0x2B82C722, 0xABEB41ED, 0xB1B18332, 0x163C2623},
	0};
		static ecpoint_fp var_b = {{0x07A3A0C4, 0xCF1F642E, 0x51B7D978, 0x2CAED061, 0xC6203118, 0x9A9D99D2, 0x9E47F022, 0x201FC6F5},
	{0xAF9E13A2, 0x0402809A, 0x51E35544, 0x3C055B4A, 0x6358286E, 0xF42B062B, 0x09F67CFD, 0x046D856E},
	0};
		static ecpoint_fp var_expected = {{0x0404953C, 0x2FDB36A0, 0x931083C5, 0x8923F948, 0x4CF8336E, 0x33B87C48, 0x2E028F6F, 0x01F56D93},
	{0xC3DA0A8C, 0x8C5CF032, 0x52EF48AC, 0x18ED1286, 0xFFEF6652, 0xF0013DB9, 0xE8DBE51B, 0x1DAB79FE},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4583 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4584 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4585 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4A7D1AA0, 0xCDC10B24, 0x4C7BF293, 0x14EF642E, 0x91E1996D, 0x4C3E5383, 0xCB9335B7, 0x143D39BC},
	{0xD8B2CFBF, 0x1438B855, 0x47C77DDD, 0x2F5A8E56, 0x510516F8, 0x59BE7B6D, 0x08017B90, 0x240A9047},
	0};
		static ecpoint_fp var_b = {{0x9F4BA214, 0xF4F31E66, 0x607175AA, 0x5A268CAB, 0x493A2ACE, 0xBDD2476A, 0x7E98B684, 0x181B7FF6},
	{0x6B1B9668, 0xC81A79DF, 0x8C511235, 0x490D0558, 0xEC0968F3, 0xE2536C5B, 0xE22F3F63, 0x0E31AD99},
	0};
		static ecpoint_fp var_expected = {{0x52616E1F, 0xDBEB0155, 0xA913473E, 0x47006F7F, 0x841B1876, 0xAB03BE80, 0x87E9B9C2, 0x07B393CF},
	{0x43A24F90, 0x9CF6EF3F, 0x8608F04C, 0x58BA2142, 0xE7AE2C03, 0x88D35FA4, 0xA9B1D897, 0x1C2EC269},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4586 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4587 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4588 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x15E3AEAE, 0x0A2055F4, 0xC02B7CC7, 0xDB2AF85C, 0x2A00DF2C, 0xFC98A999, 0x6C342274, 0x124EEB5C},
	{0x3529A73E, 0x72DB9544, 0x552282BD, 0x8A0D921A, 0xC5754F17, 0x5BF415CE, 0xE802863F, 0x1931B956},
	0};
		static ecpoint_fp var_b = {{0x04F5FCFF, 0x381CC09B, 0xCE314CB9, 0xE6829E59, 0x101C6B35, 0x2CDB695D, 0x3DF57ABC, 0x05A20620},
	{0x07603CA1, 0xAB0311A9, 0x623B89D3, 0xC03C625E, 0xBA12E320, 0xD0EE8E99, 0x592B2FF2, 0x052CE7F4},
	0};
		static ecpoint_fp var_expected = {{0xF9C52584, 0xD18B7987, 0xCBCFD5D9, 0x89F427D8, 0x90205C01, 0xA5F6AC86, 0x11E34595, 0x1E34E401},
	{0x845501FA, 0x31FD1759, 0x9116C7D9, 0x3CE2BBB1, 0x3C902AD6, 0x0365B955, 0x6FD6C7EA, 0x11028F3D},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4589 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4590 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4591 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4E36BE32, 0x3884A053, 0xB3585B87, 0x7B9F838E, 0x623DF1DE, 0xCC398AF5, 0x1F70CF92, 0x092DF541},
	{0xE5D25359, 0xF0FB0BC6, 0xA6E43787, 0x2B2D5CFC, 0x8419A076, 0x8F93422A, 0x1D0510B2, 0x10B3E453},
	0};
		static ecpoint_fp var_b = {{0x00EA4E49, 0xB3591917, 0x9346167B, 0x66801288, 0x7F7E444E, 0xB331FD3A, 0x9950EADA, 0x239A271B},
	{0xCCBF5CEF, 0x53A47328, 0x550A1632, 0x50895D53, 0xF2A2FF87, 0x6126A794, 0x947A5288, 0x14870403},
	0};
		static ecpoint_fp var_expected = {{0xA903239B, 0x09D12B85, 0x9E8B9B6B, 0x63622E73, 0x983359C4, 0x55D421A0, 0xD5B95684, 0x14C84C14},
	{0x775CC23C, 0xAF6CE29D, 0x3FC85B0C, 0xFBD1241F, 0x0DFC1B5E, 0xFD4FFE20, 0x1977F596, 0x10DB5AD1},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4592 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4593 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4594 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x374618B1, 0x3C0CDB73, 0x9AAF3F78, 0xF3F3C72E, 0x30F9114E, 0xF88A66D0, 0x8CCDA84A, 0x175A6166},
	{0x95E6C98F, 0xD45CF5B5, 0xAEF447BC, 0x2DAECB54, 0x3975F4BD, 0xB6F37DEF, 0x9E84BD42, 0x177C45AC},
	0};
		static ecpoint_fp var_b = {{0xCE6DFB48, 0xBA6AAF4E, 0xBFEF437F, 0x96B5CE8E, 0xC108993F, 0x30FDE8E9, 0x994A4455, 0x135A5CC4},
	{0x7F5ECAE5, 0xC715150E, 0x53A855D1, 0x92CBE9A9, 0x9A177028, 0x985E5333, 0xC0F6D099, 0x1A158330},
	0};
		static ecpoint_fp var_expected = {{0xA3C065E1, 0x995CD795, 0x6CD4FB95, 0xAC28B718, 0x11FED42F, 0x7CD5CD58, 0x0214A916, 0x0013E3F2},
	{0xBC581218, 0x5422D2E9, 0x564164AA, 0xB6F86B44, 0x6B9B19BE, 0x21B09106, 0x8E2177DB, 0x0CEBA850},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4595 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4596 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4597 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8220CF78, 0x999FEC5D, 0xB66D07FA, 0xC96AEEDB, 0x31B14553, 0x4101CBC6, 0xA75A0365, 0x1BD03125},
	{0x3756680B, 0xE7A6B73A, 0xB92C83BF, 0xA9D653D9, 0x7C81224B, 0xC92E7E8E, 0xA3B42FA6, 0x022923CB},
	0};
		static ecpoint_fp var_b = {{0x39487478, 0xBF7B6BD6, 0xA5319A83, 0x680A5DBF, 0x565A34F5, 0x89AB1EE5, 0xBCD2B468, 0x0A5470D4},
	{0x3F3985FB, 0x0A9A0626, 0x60BBA21F, 0xEC601C10, 0xBDF2A5EA, 0xBAFA3D29, 0xB86A8AD8, 0x0DE41B09},
	0};
		static ecpoint_fp var_expected = {{0xACD3FF10, 0x5A91BBDF, 0x6A4E747E, 0x86E44267, 0x502AF7F9, 0xAD03EF11, 0x15D7A495, 0x027F9C51},
	{0xB772C8EC, 0x69AC42C5, 0x8CF2D8AF, 0xF83C3BC9, 0x84B217A1, 0xAB4AF695, 0xDC792635, 0x12A490C5},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4598 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4599 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4600 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x60D8F020, 0xDDAA142A, 0x1A7DFDFA, 0x822C4CDF, 0xA1DE1F43, 0x296B81AE, 0x05AEF928, 0x022E46FD},
	{0xBF5D350E, 0xADD64C70, 0x144CFFBA, 0xD07A5A77, 0xB5414E3C, 0x0D39F6F6, 0xBFD8F4FE, 0x0AAAC5DD},
	0};
		static ecpoint_fp var_b = {{0x0DFD9D07, 0x87D118B2, 0x280FD07F, 0x0D6ABFEB, 0xA6CF5CB5, 0x276A3EF8, 0xC23C1D02, 0x23BBEBB1},
	{0x7377970E, 0x7DF9C439, 0x7F65B6B4, 0x2C599176, 0xB1AE427E, 0x81263F22, 0xF13B896E, 0x065E16D6},
	0};
		static ecpoint_fp var_expected = {{0xB0187753, 0xF407B136, 0x9F53FD3A, 0x99567E08, 0xA5B38E72, 0x74F96A15, 0x2B3D9CA6, 0x09220F37},
	{0x234C747C, 0xFA05C6D2, 0xEE91FFB5, 0xFE34D82C, 0x052D13F6, 0x820F567F, 0xB094A940, 0x179E12BC},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4601 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4602 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4603 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9A0E09E3, 0xB2985169, 0x9393E08F, 0xE43AE4F8, 0x8A3B64D4, 0xCEA9C680, 0x7C097B95, 0x0530F75F},
	{0x2BA6CFA7, 0x703CBAF6, 0xCADE847E, 0xCF079BC8, 0xCE163782, 0xB196A630, 0x5CB32C0D, 0x12353594},
	0};
		static ecpoint_fp var_b = {{0x14AF49EA, 0xFCECF682, 0xFC008B10, 0xC8ED43D9, 0xA0633166, 0x5B1797A5, 0x67F03B58, 0x0087FA57},
	{0xFFC27277, 0xD3E6DC0C, 0x8B441BC7, 0xE9730C8A, 0x1FFFAF37, 0x469616A6, 0x5B086E0F, 0x049F0150},
	0};
		static ecpoint_fp var_expected = {{0x6A0DFFC2, 0xD85976B5, 0x1CCA655A, 0x70C32D19, 0x0B0B13F0, 0x59B1155A, 0xBF4AE666, 0x21843579},
	{0x0E621C6A, 0x441D7C49, 0xA9CB4B1E, 0xD4C0C4C8, 0x3B4F5E52, 0x59F04A0B, 0xB49C9587, 0x0F78611B},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4604 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4605 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4606 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF1E69058, 0xE9C9ED93, 0x17AB33D2, 0xCDD33083, 0x1C8A1A65, 0x0AC85C76, 0xFE5CA01B, 0x0FA6989E},
	{0x2C3197B4, 0xA8F37511, 0x8F08A856, 0xA439DE18, 0xA4E9B116, 0xE613198C, 0x3E516B68, 0x1A1CE1A7},
	0};
		static ecpoint_fp var_b = {{0xF6C8D87F, 0x217B29B7, 0xF39058EF, 0x1AAFA7C1, 0x2E5671E1, 0xAF600D09, 0xE0E973E4, 0x04D5F014},
	{0xFE94D737, 0x34EBF245, 0xE1D1BD67, 0x66EE1BA4, 0x074F4075, 0x8FE27859, 0x5E433298, 0x14E86D4F},
	0};
		static ecpoint_fp var_expected = {{0x10F6FD7A, 0xEE16C218, 0x4890DC35, 0xF216333A, 0xECB968A7, 0x5C9DE070, 0x1DD0CEB2, 0x24D45310},
	{0x3D6436C7, 0x888473E5, 0xD6B9131F, 0xDF254C67, 0xDD74D203, 0x0A40C4AD, 0xCC77CCBA, 0x18D3EC30},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4607 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4608 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4609 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC57C4A75, 0xF36665A9, 0x5BAAA831, 0x430542D8, 0x162D5F6F, 0x2FB79864, 0x9CBDADEA, 0x099DF8BF},
	{0x69DF4E7E, 0xABDB8C9B, 0xB55096C4, 0x6CE2ED34, 0xEC7C5C15, 0xFE30B5F6, 0xA0FB42B9, 0x24B5156E},
	0};
		static ecpoint_fp var_b = {{0x5AF25A03, 0x720AA542, 0xB58322E3, 0xADF1A4A2, 0x34FCA867, 0xCF4FFF62, 0x43AD6ABA, 0x02C61507},
	{0xF47FBB4D, 0xA1A6D1BF, 0x63D8BDAE, 0x267CB4B9, 0x13C221A1, 0x00ED9854, 0xBEE620F4, 0x18019D00},
	0};
		static ecpoint_fp var_expected = {{0x25E09C9C, 0x995777F9, 0x81193121, 0x9AAF20BC, 0x8C24F4AA, 0xA8F85679, 0x27A90E04, 0x003AC341},
	{0xFC5BBA0A, 0x015057BE, 0x43F2F6DF, 0x874203E9, 0x141AD71A, 0xAD107F38, 0xF52DEE1B, 0x0C926DD1},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4610 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4611 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4612 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x394509E9, 0x4BFE651D, 0xE8CD0488, 0xE83090F2, 0x94C4320C, 0x05A27C42, 0xF54FA720, 0x13209A83},
	{0x6645118D, 0xEC4CCFB9, 0x1E238CFD, 0x5A403525, 0x3606D13A, 0x44FAFA59, 0x9152D2BB, 0x011E6055},
	0};
		static ecpoint_fp var_b = {{0x9F455614, 0x9DF0AC03, 0xAE2B5BD1, 0x2D80CA5D, 0x1A153A06, 0x32E6D0AF, 0x5AC36D0C, 0x172089B4},
	{0xD44C8C43, 0x96D2F86E, 0xC795F5EF, 0x40783E7F, 0x354B87DB, 0x4EB50845, 0xE368D8E8, 0x015765E9},
	0};
		static ecpoint_fp var_expected = {{0xF86F1B84, 0xD90F42F4, 0x96EA7BF8, 0x47202011, 0x8F7B7B4E, 0x97E2B119, 0xD9BE87A9, 0x06DAF80F},
	{0xEE26E9CF, 0x8615FE9A, 0x4EC3A13F, 0x01102C57, 0x4EAEFB63, 0xA49FAE4D, 0x86BC4631, 0x0BEBD860},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4613 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4614 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4615 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB7985EC6, 0xBCA3ACDF, 0xA153F438, 0x92055F45, 0x5011128A, 0x46CEE640, 0xE904F8B7, 0x084926AF},
	{0xE637F172, 0x0DD0CAD4, 0xBD3B2066, 0xF1F409EC, 0x3776B29A, 0x95E098F9, 0xAC0DEF29, 0x082E2FB6},
	0};
		static ecpoint_fp var_b = {{0x2BF1204E, 0x6EA94E6B, 0x789F73CF, 0x31C9CA5D, 0x79BB7663, 0xB64B6542, 0x5C200D0C, 0x13BB2893},
	{0x42902394, 0xEEA90314, 0xCC0BF51D, 0x9758E626, 0x3E1230F3, 0xEDDA641D, 0x5CF1E3FC, 0x118A9743},
	0};
		static ecpoint_fp var_expected = {{0x41540833, 0xE524538C, 0xF88F8ED2, 0x9B937641, 0xE480C4CC, 0x597335C6, 0x6DE7EC20, 0x226C31CC},
	{0x652E1DA0, 0x576BB254, 0xC2909EC2, 0x5121EF8E, 0x3A8CF7C5, 0x087665F4, 0x9B2FCE0E, 0x22DA8803},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4616 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4617 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4618 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC0695EAA, 0xF3A35E48, 0x95EB4D24, 0x7121F20C, 0x9924D5E6, 0xC435DF47, 0x561AB811, 0x0AA5B655},
	{0x7B606ABB, 0x1465E898, 0xA5747D8F, 0x989C60D1, 0x19CB3F74, 0x026CF8F4, 0x1CC2FED1, 0x238EE59B},
	0};
		static ecpoint_fp var_b = {{0xA184FE16, 0xF7D004A0, 0x08FD3BC4, 0xEDC15F75, 0x5203BCBD, 0x9B3B20B8, 0xCBA9473E, 0x0656B5B5},
	{0x6E29490F, 0x490E8CC5, 0x7F114701, 0xD67C193D, 0x15AB91A2, 0xCFC4E822, 0xE7334833, 0x0B77B27D},
	0};
		static ecpoint_fp var_expected = {{0x6AF1E672, 0xB1A2DD95, 0x84861D47, 0x5AE4164E, 0x230162CA, 0x1A70EDD6, 0x46AC42BB, 0x12913635},
	{0x53B3D602, 0x7D5F154E, 0x2922701D, 0xF5EFA553, 0x744E3740, 0x4ECE8522, 0xA7032E13, 0x031E745C},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4619 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4620 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4621 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFFA60B9E, 0xBD60B6DC, 0xF029D067, 0x10AEEBA7, 0x1C5D1C4A, 0x2B69DECC, 0x90751815, 0x24BA8628},
	{0x540D1C92, 0x728C8148, 0x750627C9, 0x1A2D89AC, 0xE4EE9C91, 0x90F14C43, 0x733F34D3, 0x13130E9B},
	0};
		static ecpoint_fp var_b = {{0x921D7C4B, 0xA45B374D, 0xDA0474E7, 0x28140AA8, 0x9B21198E, 0xC39DFC43, 0xB592C5FC, 0x185DC86E},
	{0x26E41F2C, 0x7538C02F, 0x4CE5319F, 0x204ACC7A, 0x28D8EF50, 0x7F9257ED, 0xC7DE73D7, 0x087868F8},
	0};
		static ecpoint_fp var_expected = {{0x5ED545EF, 0xD128B9E7, 0x5E77DE5F, 0x4BE8830F, 0xBDF846AC, 0x66CA41B7, 0x119B4D86, 0x22DFF5AC},
	{0xD7CF3636, 0x9A590A33, 0xC7577871, 0x1BD4B8E6, 0x7823442F, 0x45482011, 0xAE17F0CC, 0x136DB7AF},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4622 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4623 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4624 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDAC818FD, 0x123C3566, 0x8DDF4FAB, 0x4BDE2C03, 0xE0128BA7, 0x9F1F1F71, 0x4AD9CEA0, 0x1569D02A},
	{0x9BAFBC97, 0x08110E90, 0x78FEF293, 0x2C8E2B5B, 0x910DCA0F, 0xFE8572DE, 0x4A6C036E, 0x025A8BA9},
	0};
		static ecpoint_fp var_b = {{0xDAC818FD, 0x123C3566, 0x8DDF4FAB, 0x4BDE2C03, 0xE0128BA7, 0x9F1F1F71, 0x4AD9CEA0, 0x1569D02A},
	{0x9BAFBC97, 0x08110E90, 0x78FEF293, 0x2C8E2B5B, 0x910DCA0F, 0xFE8572DE, 0x4A6C036E, 0x025A8BA9},
	0};
		static ecpoint_fp var_expected = {{0x3DBE8CB6, 0x2AC73459, 0x9B5D1BCF, 0xAEB42D76, 0xF5F890CD, 0x851F22C6, 0x64A96844, 0x1737FA42},
	{0x78FEE918, 0x5921F589, 0xC9BED4B1, 0xF51C4894, 0xCD94C240, 0x7BAC6822, 0xEA96F501, 0x0AEB7038},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4625 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4626 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4627 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5F601E8A, 0xF341E203, 0x78423F50, 0x0B45CEED, 0x691B58AF, 0xA958714D, 0xA64DDDD1, 0x18203605},
	{0xC87975E5, 0x9856C1FA, 0x9709DAD0, 0x6CF0B537, 0x9EE4D7B0, 0x6C41F596, 0xA6998AB2, 0x1CA77C33},
	0};
		static ecpoint_fp var_b = {{0x5F601E8A, 0xF341E203, 0x78423F50, 0x0B45CEED, 0x691B58AF, 0xA958714D, 0xA64DDDD1, 0x18203605},
	{0xC87975E5, 0x9856C1FA, 0x9709DAD0, 0x6CF0B537, 0x9EE4D7B0, 0x6C41F596, 0xA6998AB2, 0x1CA77C33},
	0};
		static ecpoint_fp var_expected = {{0x6FF4C385, 0xFA490D81, 0xA816631E, 0xC6F8296B, 0xD8E1A531, 0x3044306B, 0x248F43D4, 0x045A4619},
	{0xAF2469CD, 0xD3B16A4E, 0x87CBB23D, 0x8A6433CA, 0x0A7C2DE1, 0x873D7EE1, 0xD8FFE30F, 0x1D1D4DC3},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4628 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4629 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4630 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x47C1E755, 0xE79101C2, 0xBDB0914B, 0xFFCC6778, 0xD14B3F73, 0xD429EC0F, 0x09884879, 0x0B1BA7DF},
	{0x15CED667, 0xEC73922B, 0xAC05801F, 0xEECDC71A, 0xE9C47E07, 0x4132610C, 0x6AEA5222, 0x14DD92B5},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x2FA2F6B5, 0xB5B4FF4D, 0x99C45A96, 0x7EBAF05D, 0xE782F1C7, 0xD3930579, 0xEA1C5D26, 0x1F7072FD},
	{0x9AA593A5, 0x90CD141C, 0xD94DC0C3, 0xFEC336C6, 0x33E4CB13, 0xAE2E7F83, 0xC9059E58, 0x023BBD57},
	0};
		static ecpoint_fp_proj var_expected = {{0x248E6BC9, 0x4A986955, 0x2AA5D3FF, 0xC4FBFE4B, 0xE44AD295, 0x836E97F1, 0x6758AB86, 0x1469632B},
	{0x166D6E49, 0x78569743, 0xDED3205D, 0xB7D66F47, 0xD5EFF81F, 0x891C620D, 0x7EF7C839, 0x1B5AC7AB},
	{0xE7E10F60, 0xCE23FD8A, 0xDC13C94A, 0x7EEE88E4, 0x1637B253, 0xFF69196A, 0xE09414AC, 0x1454CB1E},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4631 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4632 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4633 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4634 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x3B9568FF, 0xA381792B, 0x4EAC16DC, 0x7CF7E29B, 0x66C71831, 0x8CD684A6, 0x0B07B68A, 0x1AE22D09},
	{0x12995BF5, 0xC3628FC9, 0xA7019F70, 0xDA85C322, 0xD14B5CA0, 0x3FB64BFE, 0xD8F58B69, 0x0B8B5CEB},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xD2512984, 0x0A3B1A06, 0xEB360BDA, 0xCDF89D24, 0xAB8F97EE, 0xFA0965BE, 0x8361CBBF, 0x0635888C},
	{0x317A98C6, 0x1531875B, 0x50A92699, 0x657D71EC, 0xFB22695D, 0xA8DBEA57, 0x0B0A60CB, 0x13167752},
	0};
		static ecpoint_fp_proj var_expected = {{0x8A2CEE86, 0x779D56E4, 0x540A8E9B, 0xD294B0F6, 0x0F9A1CED, 0x45A2F68A, 0xC437676D, 0x1A3801D7},
	{0x5A251587, 0x3212A357, 0x58726529, 0x7C6FFF17, 0x614B7B34, 0x67F6AC13, 0xA839751F, 0x064E9EAE},
	{0x96BBC098, 0x0DB9A0DB, 0x9C89F511, 0xB221BA89, 0x44C87FC5, 0x27672E98, 0xB85A1537, 0x1076C005},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4635 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4636 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4637 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4638 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x45E3CF7A, 0xB73B4F9C, 0xE034869F, 0xA8FA3201, 0x1A811013, 0xE0A093FA, 0xBE35D05D, 0x1EAF654A},
	{0x2DCEE19B, 0xDF3D5BE3, 0x6EEC952D, 0x758D434D, 0x2421C0B8, 0x194B1A0B, 0x2543FA78, 0x085A0AF7},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xF41E07E1, 0xCC4E1F62, 0x71FE206B, 0x92720AE6, 0x68D35E03, 0x874E1D54, 0xF686C13D, 0x11C88BF4},
	{0x3E38EBE8, 0xB27D3451, 0xCD8301F1, 0x5C278FBB, 0x00593DB6, 0x37A01DA9, 0x24714C69, 0x1E6B20B5},
	0};
		static ecpoint_fp_proj var_expected = {{0x83CAEB1E, 0xEEFE0D95, 0x5D135DEC, 0xCD14BAC4, 0x050D318B, 0xE39ECD10, 0x3FCA2881, 0x1F912909},
	{0xF628245C, 0x04FEBED0, 0xA6D98D5A, 0x92FA97A6, 0x0912156D, 0xDC3F7A62, 0x9C1DAE4F, 0x1B49A1DC},
	{0xAE3A387A, 0xBC12CFC6, 0x91C999DF, 0x4A98D8E4, 0x4E524DF8, 0x60E1D6DA, 0x7850F0E1, 0x183C8B2C},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4639 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4640 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4641 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4642 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xD8060E2D, 0xDDC05995, 0x038A8E41, 0x1A5E5A94, 0x35E2AE26, 0xDEB53AD9, 0xD6E89198, 0x1101B6AC},
	{0xB11DC5DB, 0x5BA8827B, 0xCA953839, 0x19A40E1F, 0xCEFE2F76, 0x943654D1, 0x22AE7FDE, 0x0090D466},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x78369556, 0x04187E55, 0xB9ACC37F, 0xD0F87DB2, 0xAE32DA27, 0xBC73D1C8, 0xF0B8397D, 0x0D3DC76C},
	{0x2CAB815F, 0x3007378C, 0x6ADB51F5, 0x6E3964F9, 0x49F2F1F8, 0x023FC54B, 0xFAB275B2, 0x07397514},
	0};
		static ecpoint_fp_proj var_expected = {{0x4761B5FF, 0x8BAC1BC1, 0x9A6F87AA, 0x40F92F9B, 0x4BF3EE14, 0x077114CC, 0xC9030BE0, 0x1443A04C},
	{0xA8E9F5D9, 0x67FFA0D5, 0xAAD4EFBB, 0x0D546750, 0xBD3CCF65, 0x745FF456, 0x09F0A156, 0x100C9314},
	{0xA030873C, 0xCD5824BF, 0xB6223550, 0x17BB231E, 0x78502C0A, 0x97F2E46F, 0x59CFA7E6, 0x215F7542},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4643 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4644 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4645 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4646 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8AA4D9C4, 0x01BBDE3E, 0xE98FF53D, 0x55E70770, 0x578A5BC4, 0xA347224A, 0x515E4502, 0x1B5E1691},
	{0x0F61173E, 0x38B7602A, 0xD4F53125, 0xB9C8BBED, 0xEB1F839D, 0xDC4B3D0F, 0x2146CE5E, 0x04451F49},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x48A9D612, 0xACD096E2, 0xDF00C46F, 0x43651946, 0x1F081DA0, 0xEBF1AD07, 0x3F2F8B45, 0x1D2C71CD},
	{0x530BDB8B, 0xFE90DAFC, 0xCC036411, 0x5567A768, 0xCD09C703, 0xDC75E71B, 0x90701BFA, 0x0AE006FF},
	0};
		static ecpoint_fp_proj var_expected = {{0xFDBE2169, 0xB2356166, 0xC0F76D12, 0xBC1C4617, 0x137388AB, 0x4D63B33C, 0xCD37204A, 0x0FB55A67},
	{0xAA4CE2B7, 0xB34F1580, 0x9EDD945B, 0x506D7F5D, 0x00BD3C6F, 0xF58A05E6, 0xD80FED6C, 0x0DDAC3CA},
	{0xBE04FC4E, 0xAB14B8A3, 0xF570CF32, 0xED7E11D5, 0xC77DC1DB, 0x48AA8ABC, 0xEDD14643, 0x01CE5B3B},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4647 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4648 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4649 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4650 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x12977845, 0x38D6DF3A, 0x2438A8B1, 0xD2647A01, 0x230D1C89, 0x832E7D7B, 0xB09CDF56, 0x0DA6DC7C},
	{0x7E40B662, 0xAC21137C, 0xF269C41C, 0x2832D8E5, 0x7DA358B2, 0xEF84926B, 0x0D7EAF9F, 0x1B40FCFA},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x4CAD5143, 0xC63F96E5, 0x55A20459, 0x68F7569E, 0xF388E3BD, 0xF06E6CCB, 0x74D022FC, 0x111EB209},
	{0xAA205038, 0xC6449A3D, 0x67D986AE, 0x65CF43D2, 0x23DA26FC, 0xA4550663, 0x8EE701CA, 0x2292CC6D},
	0};
		static ecpoint_fp_proj var_expected = {{0x68BE5B5B, 0x9EC74AA7, 0x1CE392DA, 0x4C0C41DC, 0x860CB27C, 0x6BED50ED, 0x61488684, 0x1C7B03C5},
	{0xA112B5FA, 0x4D0570AA, 0x6336E95F, 0xE15838C8, 0xDA53ADB6, 0x43A3363F, 0xBBDBEBD3, 0x192A05E7},
	{0x3A15D8FE, 0x8D68B7AB, 0x31695BA8, 0x9692DC9D, 0xD07BC733, 0x6D3FEF50, 0xC43343A6, 0x0377D58C},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4651 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4652 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4653 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4654 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0D09E2F6, 0xF7F932DE, 0xF475CAC3, 0x768C16AC, 0xCD85C70B, 0x8E182D51, 0x6C8CFEE5, 0x1CE253F6},
	{0x8C455D1B, 0xA2D61E44, 0x0547111A, 0x0B016A7E, 0x439B3FA4, 0x6FEE0ACF, 0x72D8F46A, 0x0A89B480},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x49C4E040, 0x100AE242, 0x8869A5F8, 0x0B7FB40F, 0x4D8B640C, 0x1F3EBC0E, 0xB5B59597, 0x251A4C08},
	{0x20137D36, 0xE747BB49, 0xFFD7463F, 0x4ECDBF9A, 0xFAD309B4, 0x4907DE95, 0xA51378C8, 0x1DF6B592},
	0};
		static ecpoint_fp_proj var_expected = {{0x677133A2, 0x6E8E8907, 0x9A962EEB, 0x723D76DA, 0x9192990A, 0xE9AE37D7, 0xC0F8C8E8, 0x137A6429},
	{0x915A4244, 0x0001030D, 0x2ACA66CE, 0x364550FA, 0xC9D6740A, 0x84692A67, 0x90975D9A, 0x0A278047},
	{0x3CBAFD4A, 0x1811AF64, 0x93F3DB34, 0x94F39D62, 0x80059D00, 0x91268EBC, 0x492896B1, 0x0837F812},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4655 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4656 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4657 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4658 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x22F267FE, 0xFC0C9F72, 0x34D3601E, 0x6DB8CB0C, 0x4EFA29ED, 0x0EE17163, 0xE0251D81, 0x06B7DFA9},
	{0xF6C65740, 0xB7E9284D, 0x78502346, 0xFF2929DA, 0x14102CDD, 0xCC23C668, 0x613202B6, 0x0CB752FC},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x4F951666, 0x02EC0FAB, 0x2E8903B9, 0x016FDBF9, 0x4F24360A, 0xABEF4374, 0x5DB3632C, 0x103566A8},
	{0xC2140B1C, 0x046281A4, 0x1F3CBFA0, 0x7CC7594D, 0x67880B32, 0xF7DAB84B, 0x23549AE3, 0x0586CBE2},
	0};
		static ecpoint_fp_proj var_expected = {{0x5DF5156B, 0x2412305C, 0xB37F4583, 0xAA49BBCD, 0xFE12547E, 0x49B21F75, 0x40A4166F, 0x161F7531},
	{0xABEE0411, 0x0E2AC78B, 0x4935DCCD, 0x41CDE0E1, 0x178991DE, 0x54C94485, 0xE4AECBF1, 0x0CC79A4B},
	{0x2CA2AE68, 0x06DF7039, 0xF9B5A39A, 0x93B710EC, 0x002A0C1C, 0x9D0DD211, 0x7D8E45AB, 0x097D86FE},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4659 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4660 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4661 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4662 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xB9D521EB, 0x737BF169, 0xD4EB9AF8, 0x0A7ECC5F, 0xF2C5892C, 0x4A8116AA, 0x259136B3, 0x1BC06EBA},
	{0x75392B56, 0x80F41C00, 0x25709FFB, 0xB6026595, 0x32AA1217, 0x5E2C67E2, 0x69FB3B52, 0x169105F0},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xBA4FC7BD, 0x085FD2E5, 0x6080F782, 0xD018EEBE, 0x8E5D601C, 0x52B801BE, 0x75520D98, 0x1844F1D9},
	{0xBE36297A, 0xD72F59A2, 0xBB156B3F, 0x2AB25AC7, 0xF59FB022, 0x54BCA398, 0xCC3876AC, 0x1AD7CD36},
	0};
		static ecpoint_fp_proj var_expected = {{0x90D3B10E, 0x46C54A40, 0x07E3C3BE, 0x6CE253F3, 0x1ECF1DF9, 0xF3C133CB, 0xC56FE510, 0x0150AF78},
	{0xFE26C0D2, 0x13E52A81, 0x52491703, 0xD949A916, 0xF2020D5B, 0xB1DEDC40, 0x4335F611, 0x05A08258},
	{0x007AA5E5, 0x3BE3E17C, 0x8B955C9D, 0x26BB225E, 0x9B97D6F9, 0xC26B3893, 0x8FC0D6E6, 0x21A7E7A1},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4663 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4664 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4665 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4666 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x199A6F48, 0x7F406CBF, 0x40C9EB5A, 0xF6FC90F6, 0xAD6C260A, 0x8D27D2C8, 0xA2A603F3, 0x07381428},
	{0xF9CCCE4D, 0xAE09BBDF, 0x1CB2A36B, 0x62941357, 0xB4CED32F, 0x36110C46, 0xA1DD3914, 0x0A364638},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xF7D396AD, 0x59DC010F, 0xBACFDFA2, 0x706ADD6F, 0x41B84D4F, 0x5C5760DF, 0xE480E8E1, 0x05A7F670},
	{0xA5D79624, 0x0C9B4E14, 0xFD79449D, 0x3CA8F277, 0x9BCF48D0, 0x9B2CC55B, 0x129FFF63, 0x1AB63E38},
	0};
		static ecpoint_fp_proj var_expected = {{0xED1F3515, 0x39FD596B, 0xA6FFF129, 0xAE1BFEBF, 0x487A4803, 0xDEF34D32, 0xE15FA0A4, 0x1DC4F13D},
	{0xC153F7EF, 0x28875CD8, 0x8AD05BE0, 0x22C866FB, 0xBC8A1FE9, 0xF1880752, 0x554E15FF, 0x0CAF4D78},
	{0xDE392778, 0x819B9450, 0x7A05F45B, 0xDA8F4C79, 0x944C274C, 0x8963DB96, 0x81DAE4EF, 0x239346CA},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4667 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4668 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4669 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4670 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x132B097B, 0x72534852, 0x619DD3EA, 0x2A73C816, 0xD5630265, 0x9E3A22BB, 0x298E561E, 0x0061825C},
	{0x38ED932B, 0xD55EDBD3, 0xAA652716, 0xB96A0817, 0xB398E376, 0x210B76A0, 0x7CDD5069, 0x054FE6CA},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xF58F808A, 0xC1E5CF4E, 0xBAD6B015, 0x2149EA13, 0x18DC6814, 0xBB11674D, 0xA1F41AE4, 0x07AE2379},
	{0xFBFDA829, 0x300D548F, 0x7F97208F, 0xE18C830E, 0x11FDEE38, 0x6F64D7D6, 0xAC3B276E, 0x0B85CDC4},
	0};
		static ecpoint_fp_proj var_expected = {{0x7DC5D9EB, 0x2A23CFC7, 0x078845ED, 0x4AB9E7A5, 0xEE4D5EA2, 0xA8540DD8, 0x237F5600, 0x15A3A956},
	{0xB8807915, 0xC3CF98F0, 0x40432F1D, 0x2642FA45, 0x422673A3, 0xEB22CF06, 0xEC4D4091, 0x034A85E3},
	{0xE264770F, 0x4F9286FC, 0x5938DC2B, 0xF6D621FD, 0x437965AE, 0x1CD74491, 0x7865C4C6, 0x074CA11D},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4671 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4672 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4673 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4674 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xEEAC2BDB, 0x345B39EA, 0x2B0DE4C2, 0x786CE70D, 0x2E35A330, 0xA594CA36, 0xD7B65FC9, 0x1305A666},
	{0xB60EBA4D, 0xED79BBE7, 0xEE2E90FB, 0x9B145105, 0xFAD2545C, 0xAB33C7E0, 0xBD67E2C6, 0x1E3ADC09},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x9D9193FB, 0x7D4B2F23, 0x9812B16D, 0x0A89276C, 0x2B751B80, 0x7C523282, 0xFF3C9002, 0x0D2A64D0},
	{0xB07AA23D, 0xA60C7E9A, 0x064E8541, 0xCE636809, 0xD7006C96, 0xE7E27FB0, 0x109DD38B, 0x134A2674},
	0};
		static ecpoint_fp_proj var_expected = {{0xA0A74990, 0x2AC29B96, 0x8BC8200F, 0x33372F44, 0xB28D6AD2, 0x1735F2BA, 0x2ECC72A0, 0x1C489815},
	{0x6C0C5B3E, 0x2A7BB6B4, 0xB7C2B8F5, 0x20457E59, 0x54800B1F, 0x878F08AD, 0x4B792162, 0x113183BD},
	{0xAEE56833, 0xEFEFF538, 0x6D04CCBE, 0xF33D405F, 0xFD3F7857, 0x90F1B5CB, 0x6786303A, 0x1F4822EC},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4675 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4676 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4677 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4678 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x89C8C400, 0xECDFDFEC, 0x3621F297, 0xE42B5D71, 0xF1D3D991, 0x852D6C3C, 0xC3E8ABE2, 0x10B796B9},
	{0xEDA440FC, 0xA5C637D4, 0x5F0A316D, 0x09D671A6, 0xDF4AC515, 0xB0A85BDB, 0x3BF4AF7A, 0x245E81B8},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xE3DAFAF2, 0x8DA18706, 0x2E73461C, 0x8A34A1A8, 0x1C0F3451, 0x8817E208, 0x38933989, 0x13831F6E},
	{0x612153B0, 0xD683CCED, 0xD38C3F05, 0x9970FFCE, 0x7FE3A6B3, 0xFC41D675, 0x5C91156A, 0x2465B6BA},
	0};
		static ecpoint_fp_proj var_expected = {{0xD1422328, 0x214387BC, 0xCA6433A3, 0xEC4E332D, 0x6EEBE2E2, 0x256F5220, 0xFB24FDCE, 0x0EB441A0},
	{0x4D1A20A0, 0xE7257BB3, 0x27840AD8, 0xEA485C65, 0x591BAB92, 0xC8AD00A8, 0x34FBBA46, 0x10D69B2D},
	{0x5A1236F2, 0xA0C1A71A, 0xF8515384, 0xA6094436, 0x2A3B5ABF, 0x02EA75CB, 0x74AA8DA7, 0x02CB88B4},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4679 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4680 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4681 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4682 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x09CC57F3, 0x24516A7E, 0x47887B73, 0x22E8945A, 0x0B9C0AE5, 0xFD2822F7, 0xA299A626, 0x07C24C7E},
	{0x91167397, 0x5D6880DB, 0x151F13B1, 0x8C6DFCCA, 0xF6369144, 0xE882562D, 0xFB0D8FA3, 0x0A5F7702},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x60DB3B05, 0x02988EC6, 0xB46B46C3, 0x72117C43, 0xF7D3CB7C, 0xE0C24352, 0x1998B118, 0x1476284D},
	{0x26008543, 0x51E3F721, 0x4842745E, 0xBACF268E, 0x1EC2FE4C, 0xE1C3A7F6, 0xD50ECAB0, 0x100F7CFE},
	0};
		static ecpoint_fp_proj var_expected = {{0x6257DF23, 0x63A2423F, 0x2FEBF7B9, 0x47BD825C, 0xA6A80561, 0x9B76F9E2, 0xD581BAC2, 0x0DDA9E92},
	{0x8AF98DAE, 0x89BFD644, 0x7A8BBA39, 0xD777D939, 0xCDF6B3EB, 0xBB3FBF8E, 0xDAEEF297, 0x0B6030C5},
	{0x570EE312, 0xDE472448, 0x6CE2CB4F, 0x4F28E7E9, 0xEC37C097, 0xE39A205B, 0x76FF0AF1, 0x0CB3DBCE},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4683 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4684 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4685 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4686 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF5B27A6E, 0x523DD487, 0xF671DC29, 0x6E981843, 0xAF39E15E, 0xF042C5DB, 0x73C7DD83, 0x091D414D},
	{0x99C01B5A, 0xA887392B, 0xE7C5EF82, 0x062BF25B, 0x62E2D82C, 0x11A0D7EF, 0x083FB429, 0x0C13F93D},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x21687D6A, 0x4890C6F4, 0xBB1156B2, 0x8E5AB8DF, 0xA2CB968E, 0x0ABC1791, 0x63D8963F, 0x0F847F5E},
	{0x6C7F0787, 0x8AA6F33D, 0x66995E12, 0xDAE26586, 0xBD8FD50A, 0x9D96E029, 0x6F9AA5A3, 0x1BDA1CF6},
	0};
		static ecpoint_fp_proj var_expected = {{0x21F5A898, 0x89501B67, 0x9388BB41, 0x33097B3D, 0xA6851226, 0xF3CFED8C, 0x55841460, 0x0E3B8523},
	{0xF7CED4C7, 0xCFF72DC3, 0x4CF43B24, 0x2550C1E0, 0x370C069A, 0xEB60851E, 0xDE684E4D, 0x14D20298},
	{0x2BB602FC, 0xF652F26C, 0xC49F7A88, 0x1FC2A09B, 0xF391B530, 0x1A7951B5, 0xF010B8BB, 0x06673E10},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4687 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4688 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4689 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4690 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8902FB9E, 0xA7AAA545, 0xE0DDC703, 0x9829FA2D, 0x8A7C545D, 0x07E0843E, 0x158B5254, 0x13018C08},
	{0x4933C5DE, 0xC4FB937A, 0xC46CCCB3, 0xA844BA6D, 0xCDA80855, 0xD87A34C0, 0xD66C199D, 0x0FB3D27C},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xBBFCB10F, 0x6A596E19, 0x5F82F35E, 0xBA46F510, 0xC6D440BC, 0xBBA2943C, 0xD4CAE9B1, 0x149E844F},
	{0xE6AA90EB, 0xD9F18804, 0x6C060073, 0xEDA1E7A3, 0x93122FEE, 0x3A7BB78B, 0x09628486, 0x1654200E},
	0};
		static ecpoint_fp_proj var_expected = {{0x7C12F532, 0x4C8B7297, 0x541F0532, 0x0CD9CAD4, 0xE19521BC, 0xB5DB7D30, 0x33CC625F, 0x00E0D5F1},
	{0x48ABB060, 0x265D831C, 0xE83CD013, 0xC7DAA9F6, 0x94C886F5, 0xD67461CE, 0x793A810B, 0x192ABD7D},
	{0x32F9B571, 0xC2AEC8D4, 0x7EA52C5A, 0x221CFAE2, 0x3C57EC5F, 0xB3C20FFE, 0xBF3F975D, 0x019CF847},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4691 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4692 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4693 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4694 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x643A501E, 0x19DA16A8, 0xFA740DBE, 0x7EA6FA38, 0xC026FB00, 0xE838EDB4, 0xFB7CBBE4, 0x001DFC22},
	{0xA26EC641, 0xE89DE0E5, 0x4B41590D, 0xDF25BAAA, 0x23C6D95F, 0x45600122, 0x67951AB3, 0x1F7FD2CB},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0x643A501E, 0x19DA16A8, 0xFA740DBE, 0x7EA6FA38, 0xC026FB00, 0xE838EDB4, 0xFB7CBBE4, 0x001DFC22},
	{0xA26EC641, 0xE89DE0E5, 0x4B41590D, 0xDF25BAAA, 0x23C6D95F, 0x45600122, 0x67951AB3, 0x1F7FD2CB},
	0};
		static ecpoint_fp_proj var_expected = {{0x14ED5477, 0x06CB0F0B, 0xA40CE073, 0x4C70C85E, 0x3F373BF6, 0x1B23BE8F, 0xE1A2EBAB, 0x04B3E01B},
	{0x5CEE8E30, 0x9A26E667, 0x54E025E6, 0x46D81F34, 0x2F190038, 0x3738CB5E, 0x71D3CCC4, 0x03232870},
	{0x44DD8C6F, 0x2A3BC1CB, 0x9682B208, 0x5D2A7554, 0x478DB2B7, 0xD08BB4C4, 0x8F2A3564, 0x19DC4114},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4695 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4696 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4697 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4698 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xD2147E2D, 0xB6F86258, 0xB8C75977, 0x10914BB1, 0x1492F0E8, 0x34A937A3, 0xF76C6128, 0x1B43447F},
	{0xED57F73E, 0x7EA1F712, 0xF361048A, 0xEF86A3DD, 0x17452586, 0x9A53E71D, 0x06028491, 0x1CBA84BC},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp var_b = {{0xD2147E2D, 0xB6F86258, 0xB8C75977, 0x10914BB1, 0x1492F0E8, 0x34A937A3, 0xF76C6128, 0x1B43447F},
	{0xED57F73E, 0x7EA1F712, 0xF361048A, 0xEF86A3DD, 0x17452586, 0x9A53E71D, 0x06028491, 0x1CBA84BC},
	0};
		static ecpoint_fp_proj var_expected = {{0x53115358, 0xB2221222, 0x0E24E1A5, 0xCEAD3377, 0x7408BCD3, 0x8139E032, 0xB347C678, 0x0EF9E26B},
	{0x1A8CC6CA, 0xAF6E918A, 0x6AF9A356, 0x07DCCE77, 0xCD2ED676, 0xBC4551F1, 0x42998053, 0x1E46C4E7},
	{0xDAAFEE69, 0x5643EE25, 0xE6C20901, 0x7DEC47BB, 0x2E8A4B05, 0x7A7380BA, 0xCC050921, 0x1451A4F5},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4699 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4700 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4701 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4702 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x6B822B34, 0xE462C1F1, 0x83747C57, 0x3C2F8916, 0xD38E9AD4, 0x9175DAD0, 0xFE6A1851, 0x05D48CE3},
	{0x8475B7CC, 0x0313ADFF, 0x92E6DDF2, 0x4912914F, 0x3476AB5B, 0x81CD419B, 0x0FCF71DF, 0x081C2B4E},
	0};
		static ecpoint_fp var_expected = {{0x0D1CA9A1, 0x39B2B02A, 0x37957E9A, 0xBDABE03C, 0x49181654, 0x121A0CAA, 0x8FB084EE, 0x173A0442},
	{0xC6B9BC79, 0xB6B3369C, 0xFEB0D53B, 0x10B88793, 0x688E88B7, 0xCDC8DBEB, 0x02689F40, 0x0362CD98},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4703 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4704 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4705 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1AFEA100, 0xEC35577C, 0xA5277BE9, 0xFE676B3B, 0x17333257, 0xBAFC3267, 0x88405E92, 0x14652870},
	{0x257366F3, 0xF37D6010, 0x1BBF73E6, 0xD61CEDA8, 0x2BB75CEC, 0x9AE76534, 0x25E692D6, 0x18B5F8FF},
	0};
		static ecpoint_fp var_expected = {{0x7D339D41, 0x32556463, 0x1C635873, 0x8EF01647, 0x13576C62, 0xCC9E6A91, 0xEC402B46, 0x09103B44},
	{0xE5050529, 0x23968A83, 0x0D1A1DB2, 0x96E966C7, 0x5AE682D2, 0xC17CD8F5, 0x4D7F9BEF, 0x0BED4A53},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4706 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4707 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4708 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x13EC832B, 0xA8741DA7, 0xCDF66F6F, 0xC5BB114B, 0xFAB5A35D, 0xE79B9F5C, 0xB11EA731, 0x1F785C37},
	{0x74534E5F, 0x45C3E0C8, 0xCD2ECE99, 0x02886D88, 0xC5405397, 0x52924F19, 0xED7B1F54, 0x15E1237E},
	0};
		static ecpoint_fp var_expected = {{0x674D9D55, 0xBFACD510, 0x44261537, 0xFCE53B15, 0x685ED5EF, 0xB79C17C7, 0x3FBE9A37, 0x10D5B0E2},
	{0x2E72BAF3, 0x89D6918E, 0xC2B76E4F, 0x9B7DF225, 0x3F24BE4D, 0x61CEC0C1, 0x4ABCAA7F, 0x0A35D786},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4709 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4710 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4711 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAE719EA0, 0xD7F973E3, 0x75A4E75F, 0xE35D43BA, 0xAB8E394F, 0x439913C6, 0xEC808D55, 0x1539A482},
	{0x54A0A87B, 0x4C80E4B5, 0xF1401631, 0xD9620F01, 0xB101C583, 0x14FCC585, 0x8556A23E, 0x14074037},
	0};
		static ecpoint_fp var_expected = {{0xEF2B8A09, 0xF577D42C, 0xA0F969CA, 0x81F86889, 0x497DAF28, 0xA45585B8, 0xED9C816F, 0x008140B4},
	{0x25618514, 0x219C978E, 0xFF3BD1B5, 0x05914BD2, 0x6602A496, 0x2882FF9D, 0xE0BF740A, 0x1ADB39EE},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4712 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4713 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4714 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8C5D325E, 0xA56A8185, 0x98EBBEE7, 0x16107DB2, 0xC12EC279, 0x508F6E5B, 0xAB4FC294, 0x0037DE87},
	{0x1A558D2A, 0xE77735D3, 0x804BFB88, 0x272CFC87, 0xE6C85B1E, 0xDAD02C28, 0xA564B1D7, 0x232B8965},
	0};
		static ecpoint_fp var_expected = {{0x5A3BB622, 0x4FD0093C, 0xD5670546, 0xAA5666DF, 0x44181BE1, 0x131C649E, 0x0F6E388F, 0x120172E8},
	{0x94DCEA8B, 0x72FCC582, 0x837977D0, 0x7B0C62CD, 0x24CAC70F, 0xB941B072, 0x37A5F42F, 0x0F3C757B},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4715 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4716 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4717 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2785B63C, 0xA3C913B5, 0xF650A2BC, 0x4F820692, 0x49995617, 0xDBA0B1B6, 0x5A610BDC, 0x1184C476},
	{0x7E25AB71, 0xBFEAC981, 0x05DA4468, 0xB09404CC, 0x2B686225, 0xAB8B50F0, 0x6F747E84, 0x1C5A18D6},
	0};
		static ecpoint_fp var_expected = {{0xD7C117F9, 0x184A6A4E, 0x0A217150, 0xCD0B36CD, 0x28230230, 0xEC16C11D, 0x1915A061, 0x1D371C85},
	{0x019B70D7, 0x29B8567B, 0x258CAC4D, 0x11FFB1CD, 0x15703B3E, 0xECEA8D98, 0x983812DB, 0x0735462F},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4718 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4719 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4720 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA8E7FDC4, 0x61CC2772, 0x469142BA, 0x72A0E9CA, 0xDF44DAED, 0x2F8B4A2F, 0x8F9D3356, 0x1FF6529A},
	{0xD52AEE1F, 0x7AB63862, 0xB9CBCB9A, 0xA221AF09, 0x5429A4C6, 0xC8A826AA, 0x6491C2FA, 0x2410BD47},
	0};
		static ecpoint_fp var_expected = {{0xBC7E8E9F, 0x701C0A62, 0x9B9C9428, 0xE90958CA, 0x3F1EE634, 0xB1DAAD5B, 0x84A5B5C3, 0x010003BE},
	{0x1869E545, 0xDE4D104F, 0x9B0A904D, 0xF3A078CB, 0x0320869D, 0x01F8E25C, 0x8BDD19BF, 0x24EB6FDA},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4721 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4722 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4723 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x68FA36EA, 0x350253FC, 0x684E7FE6, 0x611F0539, 0x684FDBF8, 0x36B4A4BF, 0x5E83D771, 0x1F789131},
	{0x88BE0783, 0xEBC32CF4, 0x83887938, 0x5B146768, 0x37BF93F2, 0x71AE25A9, 0x59598730, 0x0E6580D9},
	0};
		static ecpoint_fp var_expected = {{0x37B58006, 0x760A246E, 0x59363D41, 0xD9810F2D, 0xD9DAF0E7, 0xD6DE0FE3, 0xCE0227E3, 0x2038CF47},
	{0xA010269B, 0x7349EDD8, 0x4F800FB5, 0x0E721DC7, 0xF99D7AE9, 0x953ED820, 0x01C945FE, 0x07D9E44C},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4724 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4725 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4726 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD24AC945, 0x80E61F10, 0xFDFBE1BD, 0xF1AF5A64, 0xC1865934, 0x35C4BEDE, 0xD4DE6DA1, 0x1485B383},
	{0x54F7E5B5, 0xF4A870B2, 0xC64A8E51, 0x5BD8BA6D, 0x16E89F5A, 0xD9B81A69, 0x6FA70F96, 0x24B38203},
	0};
		static ecpoint_fp var_expected = {{0xC4B32B8D, 0x39D25DD9, 0xB0E73895, 0x2A37903D, 0x7A468BA0, 0x68DA0D23, 0xDDC19AAF, 0x043A0550},
	{0xE9700254, 0xB8C3FFFB, 0x7551A973, 0xA58BFD77, 0xC1686311, 0x21BE7271, 0x7355CDA8, 0x11F645F0},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4727 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4728 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4729 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB36EC6D3, 0x1EAAE627, 0x0FA2ED8A, 0x13FFC040, 0xBFF51AE6, 0x9DFD7378, 0x3DCCED0C, 0x21A13BA5},
	{0x0CA1A1CF, 0x03034FBE, 0x1608A860, 0xFB966FCC, 0x64B16012, 0x855F584C, 0x50F0DE48, 0x13A42996},
	0};
		static ecpoint_fp var_expected = {{0x70B796F4, 0xEA889FF8, 0x71B2374C, 0x85D9E8BC, 0x51289C3E, 0x383BCD60, 0xF7AF2D05, 0x0FA458A4},
	{0x350BD4EF, 0xDC7524C5, 0xC3E82026, 0x65B0EFCC, 0x304519D3, 0x906AC1F6, 0x6A5C839F, 0x24186A6D},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4730 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4731 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4732 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8BAC9B9D, 0x76CD0AED, 0x42EF6557, 0x7B2E8759, 0xA6CBF18D, 0xD761914F, 0x2B87D8B3, 0x04BB4499},
	{0xE0580C6E, 0x60132C4E, 0xA308F5F3, 0xA393F5DC, 0xF13124AC, 0x1421C0CA, 0x4E528227, 0x0F03D88B},
	0};
		static ecpoint_fp var_expected = {{0x58813685, 0x8F6F55B9, 0x6D79F073, 0xE7F27F20, 0x0149CCDF, 0x56521310, 0x82F6C966, 0x1E9361F6},
	{0x8DDEFA82, 0xA154B3ED, 0x1C4451F4, 0xFEC5CA80, 0x34C85B9F, 0xF4AB2399, 0xAED7503B, 0x1E4CDCEF},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4733 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4734 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4735 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x34E97B39, 0xDE52B1E7, 0x5522A8C0, 0x75E5EB3B, 0xEDD583F5, 0x9786906E, 0xF8026F91, 0x2231B6F9},
	{0x9813FFAD, 0x50EC5D9A, 0xCB8523E9, 0x51BE10AE, 0x1EBEA957, 0x9BE0B896, 0x1FBCF3C4, 0x1692C2A3},
	0};
		static ecpoint_fp var_expected = {{0x941A9A8F, 0x0F475BFB, 0xEFFA209E, 0xEA617B10, 0xCE82722A, 0xBDC8B871, 0x1BCDB71E, 0x000B8871},
	{0xD7DFC0FA, 0xC360E611, 0x909941A8, 0x38644558, 0x9F1274C8, 0xF216AB6C, 0x67C6EB85, 0x0151C37C},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4736 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4737 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4738 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xCE1BB2DA, 0x7B062EBF, 0xEC9FBEDC, 0xE5EDF1C4, 0x4A0FD044, 0xAEB4D56E, 0x3D4CE1ED, 0x236C6BD5},
	{0xE3C566ED, 0x5609B593, 0xC4DF520B, 0xB9363EA1, 0xFD04D955, 0xB0E279F5, 0xCDEACA6D, 0x0DE21CB8},
	0};
		static ecpoint_fp var_expected = {{0x2CE7E72C, 0x3B3E409F, 0x03C59F93, 0x0465E02E, 0xEB7F1F1D, 0xDC4BFEE8, 0x7898B5AA, 0x1CC5732D},
	{0xC1FA4BE4, 0xAF7DB393, 0x836E5B6F, 0x56892FC0, 0xF49F8F7F, 0x5F88A3E9, 0x0CF3D96B, 0x0C002A16},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4739 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4740 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4741 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x22CC23DF, 0x00D04C4F, 0xFDB32339, 0xCA9DA484, 0x23707D6A, 0x6D2A3496, 0xB9E05709, 0x06B97FA4},
	{0x651AE013, 0x5FAF4924, 0x3CD14287, 0xFC801D29, 0x19100330, 0xB0479D64, 0x1A7CF506, 0x1600815D},
	0};
		static ecpoint_fp var_expected = {{0xC31E7938, 0x49418C8D, 0xB6558217, 0x8CE5F8F6, 0xAEB5418D, 0xDE022979, 0xC62D71E6, 0x1DC1A8D1},
	{0x7DAC0729, 0x33D5056E, 0x8BD87842, 0xEFFBA726, 0xDAB1E94E, 0x651B64C2, 0xFF150E70, 0x0F51288D},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4742 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4743 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4744 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xABBE6496, 0xD69B568A, 0x2AAA465E, 0x3C56B004, 0xE611128F, 0xD79D3D43, 0xC056FCCD, 0x183451C8},
	{0xB51B08FC, 0xAC4257EB, 0x235AC4E3, 0xCF1544BA, 0xF52F128B, 0xF8B51B35, 0x0DEAAF4B, 0x06862374},
	0};
		static ecpoint_fp var_expected = {{0x57546614, 0x18373BF8, 0xCAC28F2E, 0xDF438774, 0xD8A0A2F1, 0x90DC3A4F, 0xD3F207F6, 0x0344D1D9},
	{0x04CA6877, 0xA68936DB, 0x1CEE7350, 0x2CE8ABD6, 0x30824778, 0x6DFC2884, 0x7497E12F, 0x041400D4},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4745 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4746 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4747 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC8B9E4C5, 0xE87A26FE, 0xE526B342, 0x2742DD67, 0xEDFF9EA9, 0xA5B69EB4, 0x4FF0B65B, 0x0B488E30},
	{0xF6114C59, 0x47137154, 0x7320A93E, 0x6913C780, 0x9C88E750, 0x701A4F00, 0x2B28E409, 0x1F9D40EA},
	0};
		static ecpoint_fp var_expected = {{0xDCD6C7BE, 0xEA83BBF5, 0xF1B8776A, 0xA7B5B415, 0x7246586B, 0x892B9251, 0x12BA939F, 0x0229E376},
	{0xECB0A55B, 0xED8B24AC, 0x8DCA454C, 0x644DC09C, 0xB551BBEF, 0x2BECC564, 0x17B90237, 0x03F889E4},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4748 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4749 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4750 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xFC9BBCE2, 0xCD4ECFC6, 0xD27B775E, 0x9B9262A4, 0xD204AC5B, 0x06EFBE8E, 0x167441CA, 0x01233E56},
	{0x07DE927D, 0x4C719694, 0x312B28F3, 0x245C5283, 0xE0F448D9, 0x831CD1BC, 0x44495F4D, 0x19654566},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0xE49D6C69, 0x8115C6E2, 0xAACE6E22, 0x02757E5A, 0x9CC52626, 0x1F5BFC1C, 0xE802A815, 0x2348F28D},
	{0x6433DAF3, 0xF1DA41FC, 0x630A9940, 0x53270C98, 0x20483EDE, 0x2AE68C4E, 0x1119285F, 0x21AFDD69},
	{0x0FBD24E7, 0xF1E32D28, 0x625651D2, 0xE797A506, 0xC1E891A9, 0x4C0555F9, 0x4892BE99, 0x0DA7264A},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4751 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4752 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4753 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4754 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE0C8A030, 0xE4BA77DB, 0xF641FB12, 0xFED6DB23, 0x7A84B0C4, 0x3D5052F4, 0xAFA3AB35, 0x124D371E},
	{0x0DD1B24F, 0x7640F09C, 0x2DC6C22A, 0x49745690, 0x1152AA54, 0xF2F39750, 0x6350085A, 0x187E268E},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x7009624C, 0xE7831F7F, 0x4F47AB56, 0x3B492010, 0xC9880AFF, 0x097ECBA7, 0x146ADFAF, 0x076379C5},
	{0xE9B9862B, 0x4013B2EC, 0x160FA87F, 0x507A7C74, 0xB2AE7907, 0xE3FD9677, 0x3F274BF8, 0x242C0F5C},
	{0x1BA3648B, 0x4581E138, 0x5B8D8441, 0x31C7AD20, 0x22A554A0, 0x2BB2E120, 0x86A010B4, 0x0BD8E89A},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4755 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4756 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4757 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4758 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x58BBD7E8, 0x6A6C89F5, 0x70DAE3C7, 0xB51A8B88, 0xD66BFD6A, 0xADB278B3, 0xC2A2D763, 0x146164ED},
	{0x4F69C5E1, 0x498DE0DF, 0xFF7840E9, 0x6714DE43, 0xE8054D42, 0x4DEDD10A, 0xAC61A95D, 0x0336DC2C},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0xC2985887, 0xA55E0988, 0x4855CD46, 0x46604C16, 0xB6A5C621, 0x797223B2, 0x4B1C6FFC, 0x0B53D275},
	{0xCE5EE702, 0x13982700, 0x161032C9, 0xFE63AA7F, 0x1BE26DD3, 0x4156D624, 0x9325EF95, 0x1D5D7A5B},
	{0x9ED38BC2, 0x931BC1BE, 0xFEF081D2, 0xCE29BC87, 0xD00A9A84, 0x9BDBA215, 0x58C352BA, 0x066DB859},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4759 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4760 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4761 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4762 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0951632F, 0xCCE67099, 0xB50012E0, 0x879F339A, 0x3713C4C0, 0xC0D8DB73, 0x415BD654, 0x0F241CEF},
	{0xB8031ADB, 0xBC61EFDF, 0xA773F9AF, 0x98504E27, 0xF7BA59CF, 0xB5FE4E74, 0x6B59CEA7, 0x24B6BD46},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x0FA75F81, 0xB36A30EF, 0x88E97778, 0x8AEE52CF, 0x7F3C51B7, 0x5458A433, 0x29A1D715, 0x0A1A7CC2},
	{0xB076F7B8, 0xD980F435, 0xB9F99160, 0xCEEBBA07, 0x05B862F1, 0xFCF3145C, 0x57B50DC1, 0x12D2702C},
	{0x700635A3, 0xD1C3DFBF, 0x4EE7F34B, 0xCF7F9C4F, 0xEF74B396, 0xB1C84F69, 0x96B39D4D, 0x244A160A},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4763 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4764 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4765 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4766 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA8D7057B, 0x15F9646A, 0x4FDDC6CC, 0x079CBEF2, 0xBF8938C1, 0x1C54C363, 0xCDB98121, 0x0EEA6AAA},
	{0x65D6687D, 0x441CC90C, 0xF1AE4E6C, 0x6FF3B7AC, 0xFB628917, 0xF85024FC, 0x36D7D851, 0x16AE9164},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0xB7B0317C, 0xC95BE8D2, 0x51CDB865, 0x22C717EA, 0xBC79FFC9, 0xCCE78F8B, 0xB1BD7A4F, 0x10F6764D},
	{0x267C091D, 0xB1DFDD93, 0x27389B77, 0x7D4646D6, 0xFDFDDBEE, 0x4CCCD863, 0xCF83D158, 0x1C0FF792},
	{0xCBACD0E7, 0xE1399218, 0xE35C9CC4, 0x7EC66F59, 0xF6C51226, 0x366BFC79, 0x2DAFB0A2, 0x0839BE46},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4767 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4768 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4769 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4770 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xC5E331E5, 0x855792DD, 0xBAE0DE44, 0x961885FF, 0x84BADEDD, 0x3D7EE44F, 0x1A3319CB, 0x19FBDBEA},
	{0xD2CC3A1B, 0x1B0C975C, 0x76A23D5E, 0xFB2D6946, 0x708E5012, 0x1968F5EB, 0x4A9A25DB, 0x132C2246},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x1CCE6AF1, 0x0687AAC1, 0x3D5F7D1E, 0x86213875, 0x37839893, 0x7B9E8F94, 0x7935E691, 0x024A6D4E},
	{0x48D954F6, 0x79D89901, 0x11CF6D36, 0xE7937464, 0x355152FB, 0xCB632B2B, 0x48A578F2, 0x1BE91D22},
	{0xA5987423, 0x8F192EB9, 0xED447AA8, 0x9539D28C, 0xE11CA01D, 0x789D9E56, 0x55344BB4, 0x0134E00A},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4771 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4772 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4773 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4774 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0940B5CB, 0x6F5F90D9, 0xD1650C98, 0x14BA6958, 0x690DC6B3, 0xE764E825, 0xD8DEF97B, 0x0836A262},
	{0xE98C5006, 0x234B3BF7, 0x1A962103, 0xD74FE946, 0x68B551D5, 0xAD909396, 0x109E3D16, 0x03BB7DE4},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x1D1FCC89, 0xA35A4A9A, 0x81B7F447, 0x5444033F, 0xF6BCF2C3, 0x89340284, 0x0E04F760, 0x157BF8C2},
	{0x22E30787, 0x3D37307B, 0xE2A9C66E, 0xF0C6D185, 0xE150CCDA, 0x040A8B3D, 0x7FAB1D70, 0x1E495544},
	{0xD318A00C, 0x469677EF, 0x352C4206, 0xAE9FD28C, 0xD16AA3AB, 0x5B21272C, 0x213C7A2D, 0x0776FBC8},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4775 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4776 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4777 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4778 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x03F1C015, 0x78B6DC03, 0x24765E5D, 0x5CC3D710, 0x3F43D1D0, 0x09E17FF7, 0x09BFCB38, 0x1C563647},
	{0xE57EDAA1, 0xF37B7933, 0xEB79218C, 0xD990B549, 0xF8D339C9, 0xEB9EF96B, 0xDC24D0CB, 0x1B1672C1},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x0C32EAB4, 0x3EEC6484, 0x8B617E45, 0x5B0B6952, 0x19C8F194, 0x673742FE, 0x98B81395, 0x20410575},
	{0xC3848E16, 0xFC86E6D3, 0x4875193E, 0x77AFEFCB, 0x9E543AAD, 0xE39CE907, 0x9C135FE0, 0x1DEC15DD},
	{0xCAFDB52F, 0x3FF6F267, 0xD6F24306, 0x52006A93, 0xF1A6738B, 0x1D09A557, 0x7849A196, 0x11098101},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4779 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4780 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4781 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4782 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7AC9892E, 0xF5E7215C, 0xF2E6710D, 0xAD6230DA, 0xD453B889, 0x1DE31359, 0x128EDE2C, 0x08FE1D61},
	{0x8A54ED04, 0xDF078363, 0x300C0E5A, 0x1B5FC0F5, 0xC4EBF518, 0x4C9C5913, 0xE1FCB2F1, 0x24EBF514},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x4BA553AF, 0x0F5248B9, 0x12B45925, 0xF7C8B542, 0xD90BFCAB, 0x6FD1F6C2, 0x9F1AD672, 0x047F1FAE},
	{0x7D6B899F, 0xFF0AC60E, 0x6A21B7B9, 0xB00F9154, 0xE5AF30E8, 0x75688776, 0xAD3A6BD3, 0x0FC6B307},
	{0x14A9D9F5, 0x170F06C7, 0x60181CA2, 0xD59E81EA, 0x89D7EA27, 0xDF0464A7, 0x83F965E0, 0x24B485A7},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4783 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4784 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4785 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4786 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xB3368201, 0xB1585555, 0x4242A1F5, 0x87DA6A73, 0xA9ED7626, 0xD7821792, 0x15FAB46A, 0x0BCCB484},
	{0x42520F6D, 0xEA048E2A, 0x939FE4F2, 0x35805509, 0x5DD15039, 0x7CBB8BF8, 0x74D1CB29, 0x0DF2DFC9},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x080A0DE6, 0xE140BAB6, 0x2A431756, 0x743BFE29, 0x5E0D7212, 0x9B072FB5, 0xF4C60189, 0x03449A1C},
	{0x76422B40, 0xC70ED11A, 0x6A8239BE, 0x860A9590, 0xA8E038C0, 0x8B614A4F, 0xC31A2B09, 0x00687A85},
	{0x84A41EDA, 0xD4091C54, 0x273FC9E5, 0x6B00AA13, 0xBBA2A072, 0xF97717F0, 0xE9A39652, 0x1BE5BF92},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4787 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4788 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4789 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4790 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA6286BA2, 0x80CB056C, 0xABAB7D1D, 0xAC751C03, 0xB6FCAAD7, 0x47F9DB9A, 0x8CEBE3E4, 0x24125D17},
	{0xE799F9BD, 0xCD245CD4, 0xC9F257D7, 0xBF5C59CF, 0x336D0F36, 0xC34246D1, 0x0EAD0823, 0x0A33D6E4},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x478291F4, 0xDB0C7A1A, 0x66E8A866, 0x20D22268, 0xC550A101, 0x8445BA1B, 0x953B791B, 0x0F637CC5},
	{0x3F942249, 0x2DBB7627, 0x8DBA998B, 0xBD60BB32, 0x12DBAE26, 0x76D15AA2, 0x610FAB3B, 0x1E6F3E33},
	{0xCF33F37A, 0x9A48B9A9, 0x93E4AFAF, 0x7EB8B39F, 0x66DA1E6D, 0x86848DA2, 0x1D5A1047, 0x1467ADC8},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4791 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4792 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4793 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4794 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x2968CDD7, 0x28EBD9C0, 0xAB07CF8E, 0x4787C870, 0x6D84D4CA, 0x4EB46FC4, 0xD1C3ED18, 0x1C2895F9},
	{0xB1DB798B, 0xB7CBD3A2, 0x33508859, 0x2498CA91, 0xA7A62F12, 0xCA5BE353, 0x054715E6, 0x1A2A75EB},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x249930DA, 0x244EB13B, 0x99CD0392, 0x544F3DDB, 0x728B1392, 0x31C159EB, 0xAB959CDD, 0x04FAD8C0},
	{0x82AFB693, 0xE198C30A, 0x24DCDAF0, 0xE74E7C38, 0xE0D05DDE, 0x9761F231, 0xD2817655, 0x1232F5BE},
	{0x63B6F303, 0xC897A745, 0x66A1109F, 0xE8109522, 0x4F4C5E1B, 0xDA837927, 0xCA8E2BCB, 0x0F318753},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4795 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4796 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4797 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4798 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xACA7185A, 0xE668C43D, 0xEA842206, 0x8862A25F, 0xBAE1F005, 0xC743A236, 0x90032D1D, 0x1AC65D42},
	{0x347EC6FF, 0xB3AC03D7, 0x088A4AB3, 0xC0D22179, 0x84290700, 0xA757E5DE, 0x165484EA, 0x24DCC695},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x64291E2B, 0xF52B8DB1, 0x9101B6B6, 0x00AFC942, 0x03233E0C, 0x5420F018, 0xD34D1940, 0x110E1183},
	{0x18C48CCB, 0x66A23A80, 0xD32EA466, 0x94555C2F, 0xD49091ED, 0x9221D904, 0xCC6B9F40, 0x10A58BFD},
	{0x68FD8DEB, 0xC05807AE, 0x11149553, 0x208342F2, 0x08520DF9, 0x947B7E3D, 0xECA909D3, 0x249628A7},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4799 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4800 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4801 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4802 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF38F1C53, 0x449682A7, 0x51E1F616, 0x163F2ACD, 0xDA9BE332, 0x18839E4F, 0xE114B9D7, 0x11443AF0},
	{0x3785603F, 0xC37B163E, 0x67B00561, 0x5C58876E, 0xF8F1B083, 0x779095A8, 0xA4881889, 0x0C5D8E71},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x8E6B153B, 0x6A60934E, 0xF56533FF, 0x763EF6E6, 0x16B80346, 0x58C42C62, 0xB4B03618, 0x06152686},
	{0x2D77AC6E, 0x7D17EBA3, 0x99A922C0, 0x69C5A49E, 0x1F2E4426, 0xD212081A, 0xA00969BE, 0x1F1C239E},
	{0x6F0AC07E, 0x86F62C7C, 0xCF600AC3, 0xB8B10EDC, 0xF1E36106, 0xEF212B51, 0x49103112, 0x18BB1CE3},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4803 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4804 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4805 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4806 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x9903112E, 0x290770AD, 0x20A4E70E, 0xF5D49EE9, 0x7A20A677, 0x11C06741, 0xF3376010, 0x179AC3A4},
	{0x6CA6C628, 0x4649F5FE, 0x3B596B2E, 0x8B5A633A, 0x2BAD98BF, 0xEA151257, 0x2CBBBECA, 0x21602E96},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0xCD5EF139, 0xCA172E56, 0xDBCCB113, 0x678FC39F, 0x145F7BE0, 0x83AA135B, 0x4A1F9CFD, 0x1A2D8B1C},
	{0xD02BB9C3, 0x127D3938, 0x429EC209, 0x808D5E86, 0x7177BFB3, 0x1963BC18, 0xEF12506A, 0x1DF496FE},
	{0xD94D8C3D, 0xE593EBFC, 0x76B2D648, 0xB593C674, 0x575B3176, 0x19F5D72E, 0x19777D94, 0x1D9CF8AA},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4807 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4808 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4809 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4810 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE9421E01, 0x937A97DC, 0xFE7412CE, 0x8937BA09, 0xB1938EC7, 0xE5269BA3, 0x258CEE4F, 0x22E88CFD},
	{0x67187A95, 0x45D30693, 0x9117DC37, 0x7D0DAECA, 0xF3C1E988, 0xBAFF9D29, 0x1BFA2A14, 0x065FB0AB},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static ecpoint_fp_proj var_expected = {{0x74763BE4, 0xEACD30B4, 0x70682377, 0x6C3DA86F, 0x12C96848, 0x08114521, 0x431DAA8F, 0x2396CA62},
	{0xD0E27108, 0x6DE0E4F8, 0x37310DD0, 0x4D731469, 0xAAC1D57D, 0x5A030722, 0xA61813FD, 0x15FC35EF},
	{0xCE30F52A, 0x8BA60D26, 0x222FB86E, 0xFA1B5D95, 0xE783D310, 0x75FF3A53, 0x37F45429, 0x0CBF6156},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4811 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4812 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4813 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4814 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC1E2BB05, 0x399415FE, 0xEE140273, 0x304306EF, 0xCD550173, 0x23BAACF7, 0xCAB6B771, 0x03A864CD},
	{0x8358AD72, 0x43F48E9A, 0x0620843A, 0x0166D01F, 0x2124B6AB, 0x6C99EA1E, 0xEB03552E, 0x0FC77534},
	0};
		static ecpoint_fp var_expected = {{0xC1E2BB05, 0x399415FE, 0xEE140273, 0x304306EF, 0xCD550173, 0x23BAACF7, 0xCAB6B771, 0x03A864CD},
	{0x7CA752A1, 0x630B7165, 0xF9DF7BD9, 0x5FBA2FE0, 0xDEDB495D, 0x4D9A6361, 0x54FCAAD3, 0x155BEF4D},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4815 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4816 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4817 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF4AA3ACB, 0x7A3E4C23, 0xA721F167, 0xB315312D, 0x9B608184, 0xE5C42491, 0x96987F81, 0x010140C0},
	{0xEA7CBDF5, 0x0E6C60C3, 0x539C1ABF, 0xC7A851C1, 0x4FE9CE7B, 0xDA4EBF2B, 0xC1336FA1, 0x19E2E777},
	0};
		static ecpoint_fp var_expected = {{0xF4AA3ACB, 0x7A3E4C23, 0xA721F167, 0xB315312D, 0x9B608184, 0xE5C42491, 0x96987F81, 0x010140C0},
	{0x1583421E, 0x98939F3C, 0xAC63E554, 0x9978AE3E, 0xB016318C, 0xDFE58E54, 0x7ECC905F, 0x0B407D0A},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4818 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4819 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4820 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4BD807E6, 0xB1F3E480, 0x2186A917, 0x09AAF236, 0x2F21E8E7, 0x4F67D9A4, 0x5E04A18A, 0x00749045},
	{0x90E9115F, 0xE6B052B1, 0xD95098B6, 0x3DD205C6, 0xC79636B0, 0xE05AE9E2, 0x338EB3A3, 0x2196EF0B},
	0};
		static ecpoint_fp var_expected = {{0x4BD807E6, 0xB1F3E480, 0x2186A917, 0x09AAF236, 0x2F21E8E7, 0x4F67D9A4, 0x5E04A18A, 0x00749045},
	{0x6F16EEB4, 0xC04FAD4E, 0x26AF675C, 0x234EFA39, 0x3869C958, 0xD9D9639D, 0x0C714C5D, 0x038C7577},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4821 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4822 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4823 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x98CE62AD, 0x08D022CA, 0x3D5E61A9, 0xF2912BB7, 0xE20ADCA9, 0xBA5AD337, 0xDD37C623, 0x0D3AF74D},
	{0xA167838B, 0x819B5785, 0x874308BA, 0x2B36C5C6, 0x4F478586, 0x69DC6C5F, 0x04BF7815, 0x121F5C98},
	0};
		static ecpoint_fp var_expected = {{0x98CE62AD, 0x08D022CA, 0x3D5E61A9, 0xF2912BB7, 0xE20ADCA9, 0xBA5AD337, 0xDD37C623, 0x0D3AF74D},
	{0x5E987C88, 0x2564A87A, 0x78BCF759, 0x35EA3A39, 0xB0B87A82, 0x5057E120, 0x3B4087EC, 0x130407EA},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4824 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4825 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4826 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE757362E, 0x78DB7CD6, 0x3D6E872F, 0xD4C684FF, 0xF91399E8, 0xBFB14E87, 0xEB173AB7, 0x0DC13D5E},
	{0x97C8689D, 0xD00A97EB, 0xD6224FB0, 0xF214E9D9, 0x5A1E00DC, 0x3EF69532, 0x22C278A6, 0x01F057F1},
	0};
		static ecpoint_fp var_expected = {{0xE757362E, 0x78DB7CD6, 0x3D6E872F, 0xD4C684FF, 0xF91399E8, 0xBFB14E87, 0xEB173AB7, 0x0DC13D5E},
	{0x68379776, 0xD6F56814, 0x29DDB062, 0x6F0C1626, 0xA5E1FF2B, 0x7B3DB84D, 0x1D3D875B, 0x23330C91},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4827 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4828 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4829 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x92575BF4, 0x79A73200, 0x31A269ED, 0x3C7B8B5D, 0x870D7221, 0x615CAC84, 0x872BF0C2, 0x0CAD3D0D},
	{0xC46BAAF9, 0xC970F04A, 0x47C64ACE, 0x7511512D, 0x674C1350, 0x104BF869, 0x1B327560, 0x0F7CF4F7},
	0};
		static ecpoint_fp var_expected = {{0x92575BF4, 0x79A73200, 0x31A269ED, 0x3C7B8B5D, 0x870D7221, 0x615CAC84, 0x872BF0C2, 0x0CAD3D0D},
	{0x3B94551A, 0xDD8F0FB5, 0xB839B544, 0xEC0FAED2, 0x98B3ECB7, 0xA9E85516, 0x24CD8AA1, 0x15A66F8B},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4830 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4831 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4832 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x67F7C9B0, 0xAD621388, 0xBFBA2200, 0x1E075F5F, 0x4E4AB86E, 0xC0F5DE2C, 0xE4C0661C, 0x0AD4ABF3},
	{0x8059E486, 0xCFCB76BE, 0x6D775CC4, 0x6450AF54, 0xC9888E62, 0xD76E2C0C, 0x317D919F, 0x0EF29046},
	0};
		static ecpoint_fp var_expected = {{0x67F7C9B0, 0xAD621388, 0xBFBA2200, 0x1E075F5F, 0x4E4AB86E, 0xC0F5DE2C, 0xE4C0661C, 0x0AD4ABF3},
	{0x7FA61B8D, 0xD7348941, 0x9288A34E, 0xFCD050AB, 0x367771A5, 0xE2C62173, 0x0E826E61, 0x1630D43C},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4833 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4834 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4835 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD5C05861, 0x10C0977F, 0xA18D4F63, 0x15A45A64, 0x4A6DB919, 0xDA09792C, 0x95EC1A5D, 0x1D3ACBAD},
	{0x877305B9, 0xE9F62881, 0xBE7C7EB9, 0xEFB75E06, 0x9DF25D5C, 0xD4E7E82F, 0x0170941E, 0x0B201322},
	0};
		static ecpoint_fp var_expected = {{0xD5C05861, 0x10C0977F, 0xA18D4F63, 0x15A45A64, 0x4A6DB919, 0xDA09792C, 0x95EC1A5D, 0x1D3ACBAD},
	{0x788CFA5A, 0xBD09D77E, 0x41838159, 0x7169A1F9, 0x620DA2AB, 0xE54C6550, 0x3E8F6BE2, 0x1A035160},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4836 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4837 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4838 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x33A32FB7, 0x3ADED131, 0xB53C8A78, 0xF3B1525A, 0xA7B36145, 0x4137231D, 0x37E116CD, 0x12A4E441},
	{0x5025AA38, 0x5BDD00D3, 0x9C33FD91, 0x714361C2, 0x6AAB81FF, 0x54CE67EF, 0x6C734793, 0x22B38A49},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x33A32FB7, 0x3ADED131, 0xB53C8A78, 0xF3B1525A, 0xA7B36145, 0x4137231D, 0x37E116CD, 0x12A4E441},
	{0xAFDA55DB, 0x4B22FF2C, 0x63CC0282, 0xEFDD9E3D, 0x95547E08, 0x6565E590, 0xD38CB86E, 0x026FDA38},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4839 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4840 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4841 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4842 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA51B69C7, 0x2F3A56EB, 0x1FF5EE91, 0x389C319B, 0x1D0FC4FB, 0x058885DF, 0xFF2BF659, 0x02166566},
	{0x4C841F7B, 0x1DCB1B43, 0xDE161741, 0x66A173A1, 0xCF3D2D19, 0x88C89782, 0xDB861172, 0x11A700DD},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xA51B69C7, 0x2F3A56EB, 0x1FF5EE91, 0x389C319B, 0x1D0FC4FB, 0x058885DF, 0xFF2BF659, 0x02166566},
	{0xB37BE098, 0x8934E4BC, 0x21E9E8D2, 0xFA7F8C5E, 0x30C2D2EE, 0x316BB5FD, 0x6479EE8F, 0x137C63A4},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4843 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4844 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4845 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4846 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x352C25FB, 0x9042627E, 0x7E9EB2FC, 0x1D98B1CB, 0x1C866EFD, 0x4EC37428, 0xE2A30720, 0x22C42B5E},
	{0xA281E8E1, 0x914AB8C8, 0x7BB69434, 0xD39267B0, 0x7484E9A5, 0x5BC3280F, 0xA8FEB712, 0x18902C66},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x352C25FB, 0x9042627E, 0x7E9EB2FC, 0x1D98B1CB, 0x1C866EFD, 0x4EC37428, 0xE2A30720, 0x22C42B5E},
	{0x5D7E1732, 0x15B54737, 0x84496BDF, 0x8D8E984F, 0x8B7B1662, 0x5E712570, 0x970148EF, 0x0C93381B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4847 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4848 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4849 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4850 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x529A0B9C, 0xEF4A90F2, 0x6C90C534, 0x6F310B3E, 0x72AD48EB, 0xB02B345F, 0xA935B30F, 0x04D47366},
	{0x34959DB7, 0xD3FEA3B8, 0xE88DD8E9, 0x7FCF8AC9, 0x9FEFD346, 0xD24B891D, 0x884CB8D4, 0x06E75DD1},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x529A0B9C, 0xEF4A90F2, 0x6C90C534, 0x6F310B3E, 0x72AD48EB, 0xB02B345F, 0xA935B30F, 0x04D47366},
	{0xCB6A625C, 0xD3015C47, 0x17722729, 0xE1517536, 0x60102CC1, 0xE7E8C462, 0xB7B3472C, 0x1E3C06B0},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4851 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4852 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4853 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4854 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x24F525D8, 0x42FFB518, 0xBD6BC271, 0xB90F5D4D, 0xFB1EA5B4, 0xF77F57E8, 0x272181E0, 0x161CC9E2},
	{0x897C98B2, 0xE1DD5482, 0xABA8D72D, 0x32641D7B, 0xCBA48D8B, 0x2493AC9F, 0xC2AAB061, 0x1EAED237},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x24F525D8, 0x42FFB518, 0xBD6BC271, 0xB90F5D4D, 0xFB1EA5B4, 0xF77F57E8, 0x272181E0, 0x161CC9E2},
	{0x76836761, 0xC522AB7D, 0x545728E5, 0x2EBCE284, 0x345B727D, 0x95A0A0E0, 0x7D554FA0, 0x0674924A},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4855 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4856 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4857 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4858 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7539273E, 0x37252E3F, 0xC8EB8B57, 0x610F3D27, 0xBF3CC75A, 0x10A27D0E, 0x4137C314, 0x097A4415},
	{0xE7171CBB, 0x8225042D, 0x98625038, 0x8DBB103B, 0xBDA8C267, 0x8FB867D9, 0xF3677679, 0x177E7D54},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x7539273E, 0x37252E3F, 0xC8EB8B57, 0x610F3D27, 0xBF3CC75A, 0x10A27D0E, 0x4137C314, 0x097A4415},
	{0x18E8E358, 0x24DAFBD2, 0x679DAFDB, 0xD365EFC4, 0x42573DA0, 0x2A7BE5A6, 0x4C988988, 0x0DA4E72D},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4859 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4860 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4861 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4862 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x1FF214B1, 0xD5FEB153, 0x55B59E72, 0x49D58ACE, 0x02C7C898, 0xE0AD30DD, 0xF6CFACFC, 0x0687EB1C},
	{0xF5CD5DBD, 0xA848F1E5, 0x14C46A3E, 0xCE165C7A, 0x51159A3D, 0x75BBDE88, 0xF39D9599, 0x081D0C26},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x1FF214B1, 0xD5FEB153, 0x55B59E72, 0x49D58ACE, 0x02C7C898, 0xE0AD30DD, 0xF6CFACFC, 0x0687EB1C},
	{0x0A32A256, 0xFEB70E1A, 0xEB3B95D4, 0x930AA385, 0xAEEA65CA, 0x44786EF7, 0x4C626A68, 0x1D06585B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4863 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4864 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4865 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4866 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xA4626548, 0xD2C598D0, 0x3DDDC870, 0x19F260E8, 0x7575BF63, 0xBD0DA99B, 0x020F3952, 0x0DDE0AEA},
	{0xD9F67ED7, 0x4FE2D894, 0x4360F4EA, 0xB82CFEA5, 0x835B9AEC, 0x954B6FBD, 0xA9FE0554, 0x1E8CEBB0},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xA4626548, 0xD2C598D0, 0x3DDDC870, 0x19F260E8, 0x7575BF63, 0xBD0DA99B, 0x020F3952, 0x0DDE0AEA},
	{0x2609813C, 0x571D276B, 0xBC9F0B29, 0xA8F4015A, 0x7CA4651B, 0x24E8DDC2, 0x9601FAAD, 0x069678D1},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4867 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4868 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4869 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4870 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4871 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4872 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4873 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0xFFFFFDD9, 0x14FFFFFF, 0xFFFFFDC6, 0xFF42FFFF, 0xFFFFFF0C, 0xE813387F, 0xBFFFFFCD, 0x0AFD9D3E},
	{0x0000049A, 0x72000000, 0x000004C2, 0x85FE0000, 0x00000207, 0x18AAC500, 0x8000006B, 0x1E92578B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4874 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4875 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4876 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x0847186A, 0xE679AD6D, 0xFC71F4E6, 0x51A55425, 0x83E28B78, 0xD7FAEE4B, 0xAD738850, 0x002004F8},
	{0x55AA2D1D, 0x5D8917BF, 0xCF49DE85, 0x260E7190, 0xF4DFC5C2, 0xE71650B4, 0x0558966C, 0x11340E9A},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4877 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4878 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4879 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x7542C1BF, 0x2E078BE6, 0x621AB3CF, 0x3994D18F, 0xE13BCA88, 0x07ED13DC, 0x134D34D0, 0x0367A748},
	{0x56777832, 0x4AEFB7E8, 0xEF62FC71, 0x4399165C, 0xCC399B3E, 0xF169A334, 0x6EF8D71B, 0x14980AE5},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4880 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4881 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4882 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x081351D2, 0x543102F4, 0x813C3754, 0x353CDCF2, 0x0AF9C5E5, 0x6B57D09F, 0x1442D917, 0x14B9C21A},
	{0x4F14A867, 0x9F362CA5, 0x6930BB6D, 0x6A100935, 0xFA118700, 0x5A86B061, 0x57D70835, 0x114C044F},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4883 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4884 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4885 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xFD164686, 0xA329FC82, 0x7B0018C7, 0x290E454A, 0x7439249B, 0x60BD1625, 0x3E95B89C, 0x225E9F28},
	{0x9EBA7A47, 0x46851C7B, 0xA4EB29EB, 0x8B2D6B79, 0x1AE4FDC6, 0x0C909FE8, 0x83DFC1DA, 0x2512252A},
	0};
		static bigint_t var_k = {0x61AE9362, 0x0772F7DF, 0x2853E90C, 0x7FBBC7D5, 0x741DC446, 0xC7E1C1CF, 0xEFD2B291, 0x13045091};
		static ecpoint_fp var_expected = {{0x4E1387C7, 0x3FFD007C, 0xAA0088F1, 0x6FF3E800, 0xAE9ACB25, 0x4D643074, 0xC315EE50, 0x15D8EFFA},
	{0x969728A2, 0x5A560941, 0x7EE6011D, 0x79A401FF, 0x111D47F1, 0x20817F91, 0x23DA2782, 0x02C7E1FF},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4886 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4887 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4888 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA7AAC053, 0x65B1BE6C, 0xE0E54A17, 0x645182BE, 0x9249CBBC, 0x5878ED9B, 0x211D44A4, 0x10B42EFA},
	{0x3E70E3E9, 0x4BE948A1, 0x48C2DB96, 0xE8799C29, 0x27EA9AE7, 0x9A3FB8D7, 0x01979AA2, 0x1E806D8B},
	0};
		static bigint_t var_k = {0x113E3059, 0x71FA341B, 0xAB27AD9F, 0x82BC6C19, 0xFA70D439, 0x97EED172, 0x265AC7BE, 0x18881C72};
		static ecpoint_fp var_expected = {{0x6E7623DA, 0xB12EEA7C, 0xB1EC3C88, 0x7F1EC596, 0x888FF967, 0x5FDECF45, 0x9F6CDD01, 0x17D81765},
	{0x4F0DC665, 0x9388BB6E, 0x611A764E, 0xDC644D03, 0xB637D06F, 0x32F16E99, 0xA644B4C6, 0x1D5864DF},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4889 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4890 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4891 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x18E1ECF0, 0x198C8F9E, 0xC1FFA1F3, 0xAECB7D13, 0x3AB02FB6, 0xE2A9BD71, 0xB3D1E1A5, 0x123667CB},
	{0x112ADAE1, 0x84570187, 0x7D11BD05, 0x6983D8DC, 0xCF790F8A, 0x32FA3F5F, 0x3D9D96AC, 0x01A8B1E9},
	0};
		static bigint_t var_k = {0x835119A8, 0x9F5E8732, 0x9AEAA614, 0xDBC017EE, 0x5ED794BE, 0x4268D1D9, 0xD0A1E3EB, 0x148BE8ED};
		static ecpoint_fp var_expected = {{0x83A21874, 0x7B625958, 0x24C3B5FD, 0xA7E9622B, 0x03EC766A, 0xB82A71B3, 0x0423A5F3, 0x1534BF92},
	{0x5D97AF1D, 0x91C22703, 0xC60AE266, 0xB4717705, 0x4AEB4FEB, 0xBA8C570A, 0x7D28BE50, 0x0B4071C1},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4892 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4893 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4894 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA2B0F497, 0x1032B970, 0x84D58D92, 0x277214B1, 0x135C863E, 0xB9F53799, 0x3550E4AF, 0x10C4A665},
	{0xB6874AC9, 0x1A16F120, 0xB96116B1, 0x40A3F215, 0x3A251E90, 0x35E5FFCE, 0x5EAFDF46, 0x17000078},
	0};
		static bigint_t var_k = {0xF12E388E, 0xAC8E6019, 0x475FAF53, 0x807A873E, 0x4A9583AF, 0x3025FA73, 0x6C499206, 0x0F3B3AEE};
		static ecpoint_fp var_expected = {{0x460017F4, 0x70B515A6, 0x58E5DD59, 0x5CD35EBD, 0xD35467E7, 0x03BC9E9E, 0x8EDD1B84, 0x2502F2FD},
	{0x54D7AA20, 0xA946D59F, 0x04537491, 0x7291217B, 0x1A4E91C1, 0x7001022C, 0xE0B52480, 0x17FDA158},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4895 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4896 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4897 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC799C3D4, 0x42ACC4F6, 0x068BCD5A, 0xE1CEC7ED, 0xBC66EED1, 0xF67F5FB4, 0xB51A01D5, 0x0E9CC258},
	{0x8970568A, 0x7613FA93, 0x2B3C74BE, 0x3933A417, 0xDC588CAD, 0x49B06209, 0xB4F24873, 0x24129CAF},
	0};
		static bigint_t var_k = {0xD31C28AF, 0xB65331E8, 0x41BF0AAC, 0xA4C36746, 0xA76BCDEF, 0x9557BAA8, 0x3C83BAED, 0x09F4EEBC};
		static ecpoint_fp var_expected = {{0x0A981B4E, 0xB0A766C4, 0x275B9C94, 0x27383FA8, 0x1F856094, 0x34D25F1F, 0xBB6D4E6D, 0x1ADD2303},
	{0x54C46E41, 0x2B5DE4B2, 0x7527601B, 0x12C418B1, 0x5D01E344, 0x39F3EC70, 0xF85BFAA8, 0x0E3B7BBE},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4898 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4899 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4900 infinity");
	}
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
	{
		static ecpoint_fp var_a = {{0x3B6B72EE, 0x2C1CC8EF, 0x1F3E643F, 0x6FC088CF, 0x92DCF9EC, 0xC5017919, 0x0562098E, 0x09C5B4BF},
	{0x4C3955C7, 0xF70D2878, 0xA6DB53F3, 0x4CDC0FEB, 0xD330DF51, 0xE22D8487, 0x5B49FD84, 0x1D122D97},
	0};
		static bigint_t var_k = {0x1BA5A9D0, 0x18DBBF1A, 0xA5D644D9, 0x83E8697C, 0x96321F85, 0x557B045C, 0xFBB4FD9D, 0x0D58A5C5};
		static ecpoint_fp var_expected = {{0x4CBAD416, 0x2FE58101, 0x67B791BB, 0x4FCE12D2, 0xF2E9795E, 0xF73FC296, 0x28604D2D, 0x069718FE},
	{0x49AB7209, 0xD9B22B34, 0xDDA40485, 0xD40B8354, 0x792A7CE8, 0x6EDF5A6C, 0x52879DA0, 0x0DF82DE6},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4904 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4905 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4906 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x713E276F, 0xBD406E41, 0x6ADB5988, 0x43993503, 0x9E9F497B, 0x09AB4AF2, 0x1E608E18, 0x107C5093},
	{0xC97454AA, 0xE4AADEEA, 0x42D6CE5E, 0xA1CB2093, 0xF2B0DB0B, 0xCC0C1043, 0xC5B29587, 0x0D4996DE},
	0};
		static bigint_t var_k = {0xB2DDC444, 0x29BF2C82, 0x70E01366, 0xE68A2F06, 0x3A225120, 0xCC625252, 0x2D7B3B8A, 0x1F13300E};
		static ecpoint_fp var_expected = {{0x043C232C, 0x6BD09A74, 0x73C732DF, 0x356FA7F8, 0x798AC232, 0x82D84395, 0x3A756B59, 0x1CB925E5},
	{0x6C4A4E46, 0x16CCEBCC, 0x2B09ABD7, 0x19AE7FE2, 0xD6CE308E, 0x225DC6B5, 0xB23633F1, 0x1B5D8963},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4907 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4908 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4909 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9A160F0E, 0x2DB2DD69, 0x2592973C, 0xFB3013C5, 0x7759921B, 0xB39DAF59, 0xB7BCECF3, 0x0FBA410D},
	{0x302680EB, 0x03E66F8E, 0x3F519C0F, 0xC9A09E9F, 0xCFF482CE, 0x22D9E120, 0x5E4CD5DC, 0x0DBE0D1F},
	0};
		static bigint_t var_k = {0x21831900, 0xAB16E544, 0x4D9ADE33, 0x1EEA01C2, 0x734875CF, 0xEC50A05B, 0x1695BEAD, 0x069775FA};
		static ecpoint_fp var_expected = {{0x0A5FC0D0, 0xB510BC2B, 0x7467E997, 0x30DAB39A, 0x0277B4AA, 0x77474E31, 0xFDCABC0D, 0x0FAECBB6},
	{0x5E443AB0, 0xFCE48F47, 0x6E87DFBE, 0x76ECC0DF, 0x53841C48, 0x8C2A0819, 0x1F98D325, 0x0BDB9870},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4910 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4911 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4912 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xBBCAEC2E, 0xB5C96E7B, 0xC6022681, 0xEA8DDEAD, 0xAAC59DB8, 0x0FF832E0, 0x14E4896B, 0x1AE51E0E},
	{0xDD04D5EE, 0x60CBDD73, 0x994B08FC, 0xD9D678E6, 0x256F3DD0, 0x922776C9, 0x78C8038C, 0x0BD0560D},
	0};
		static bigint_t var_k = {0x234D95B4, 0x3C19088C, 0x0D7DA966, 0x9ED2D603, 0x694352F0, 0x9EEAD78A, 0xB9FF543C, 0x0A7900D0};
		static ecpoint_fp var_expected = {{0x5D19D16B, 0xFC90A466, 0xE9212BAA, 0x603D9B81, 0x52D9E11F, 0x4342A951, 0x808A8C57, 0x1DD48B1A},
	{0xF7426E1E, 0xF9664758, 0x41D4CF03, 0x6B88C7E1, 0xF7A1BCE2, 0xFDCDA9E5, 0x11A4BD4C, 0x02F33B84},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4913 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4914 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4915 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5ADD91EF, 0x85526C1D, 0x33985565, 0x026C1965, 0x0B336BB8, 0x15AC36D9, 0xF3CF81B9, 0x0FA3B746},
	{0x5DDD8D57, 0xF4BADBA4, 0xCAF84919, 0x1B076566, 0x320DF9EE, 0x669527B2, 0xFBE95A31, 0x066EB607},
	0};
		static bigint_t var_k = {0xAF53D7BD, 0x18B794D1, 0xC2D73C3B, 0x1DB90E62, 0x858D26E2, 0x4E46F87A, 0x15ABBBD2, 0x117CF616};
		static ecpoint_fp var_expected = {{0xD0A1EC65, 0x2971D533, 0xA672C746, 0x8FD7346E, 0x6EEDAAF2, 0x970DCD15, 0x2E04F7E9, 0x1A35DEFD},
	{0x93BEE2BD, 0x48CDB3A3, 0x36744E0E, 0x80E4EF52, 0x160AB971, 0xA38DFAB5, 0xB0A0B621, 0x1AC5C45A},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4916 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4917 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4918 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2265163F, 0x067C2F03, 0x6E013AC7, 0x5612B4CB, 0x8A9CF8A5, 0xC437CCE9, 0x22BC9BFA, 0x0AD98F7E},
	{0x5E15F759, 0xB46343FD, 0x9AB5CBC0, 0xF9EFDFE9, 0x5EDF5DB7, 0x306DD899, 0x8995946C, 0x1AA18D85},
	0};
		static bigint_t var_k = {0xFF9E48CD, 0x1B69CAC8, 0xBBDFC6D4, 0x9009948E, 0x720D5820, 0xEFBB090E, 0x2C893FD5, 0x19E3D494};
		static ecpoint_fp var_expected = {{0x2D3CDF6B, 0xDB0A3A8A, 0xE48AB53D, 0x74A806E0, 0x830415C1, 0xDCE5620B, 0x00C1D980, 0x1ECC5BEC},
	{0x39487294, 0xAE388EF8, 0xB7CB2A6B, 0x78277CC1, 0x9EF675E5, 0x8F68F67B, 0x9DB5595D, 0x0B98905D},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4919 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4920 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4921 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x544D2B5C, 0xDAC472FE, 0x355231AF, 0x3EC24F0C, 0xBAD55E73, 0xE329A83C, 0x8BBB1A58, 0x20A313B4},
	{0xD6F765A1, 0xB795431E, 0xAD6C11F1, 0xECD861C3, 0xFF1AC7DC, 0xD1807E6E, 0xB11BBC21, 0x16A1A10F},
	0};
		static bigint_t var_k = {0x8CB77841, 0x44035E60, 0x8BC02137, 0x2AF7B2B5, 0x16A627C8, 0xE282DA12, 0x009FC200, 0x16513070};
		static ecpoint_fp var_expected = {{0xE780126C, 0x091E2265, 0x46B6CD41, 0x30D8C056, 0xE39558A9, 0xEE82FCC5, 0x17541AB5, 0x2019DC8A},
	{0x13A95E59, 0xD81504C6, 0x4BA609E6, 0xF3963B4B, 0xE9ABB363, 0x276E2EC4, 0xA2273A6D, 0x08044FB9},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4922 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4923 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4924 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xED12810E, 0x9CEB79BD, 0x4E0E36B3, 0xE77DB284, 0xAE16ABAE, 0x3B210CDF, 0xE44F849D, 0x00BAFC95},
	{0x697CCD41, 0xF531B37D, 0xD1203858, 0x26250453, 0xF756EEEB, 0xEE281C59, 0x9D958867, 0x01D25F10},
	0};
		static bigint_t var_k = {0x0E36BECB, 0xF08182FB, 0x02ACBCFD, 0x620C99FF, 0x9DC668E2, 0x9A504B13, 0x10132573, 0x043CFEB6};
		static ecpoint_fp var_expected = {{0x81FD5DC5, 0xDAA6AF76, 0x4531DDAD, 0x8D00C8EB, 0xB5088522, 0x4BCBDF41, 0x5B34EF56, 0x13B17362},
	{0xBA802CFA, 0xF648B871, 0x058047B8, 0x4649EB62, 0x9BC09123, 0xC43DFDC8, 0xEEED83C0, 0x0DC866FC},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4925 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4926 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4927 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC20BB03B, 0x1AC31E2B, 0xDB83D75A, 0x7E520A44, 0xDEF1A82D, 0x96CE5143, 0x6A0ED1B1, 0x214249D1},
	{0x5155F4FE, 0x554FE8C0, 0x73380439, 0x72F3865F, 0xBFAD166D, 0x373FBF10, 0xECFB1F4F, 0x2314862C},
	0};
		static bigint_t var_k = {0x80531B01, 0x5BD7C53E, 0x31EA2EC7, 0xEBFA9EFF, 0x6DFA3C1A, 0x83ED33F3, 0x5D3E12F4, 0x09D840D2};
		static ecpoint_fp var_expected = {{0xCA82BA2B, 0xC96EA201, 0x94B8A096, 0xE641142A, 0xC8518CFE, 0xF45999B8, 0x3C940F6D, 0x07888DC2},
	{0x81D2E27E, 0x98CC9900, 0xF9BE2C63, 0x20E523C5, 0xCE6D2609, 0x2AF28AE8, 0xF1C035B7, 0x19624977},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4928 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4929 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4930 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x64E43114, 0x26B3D989, 0xAD3A91BF, 0x74F3F9B8, 0x71B322D3, 0xB269FB4B, 0xFAA7000D, 0x1E105956},
	{0x52AE923A, 0x7F9BC3C4, 0xCCAD9882, 0xB7AE0CAE, 0x708D75D4, 0x4B0BB4F2, 0xEE700589, 0x020E21AD},
	0};
		static bigint_t var_k = {0x197966EC, 0x03C5C10D, 0x69E95F41, 0xBD4BA92D, 0x3279D3B1, 0x4CDB5985, 0x2ABC3141, 0x0A372940};
		static ecpoint_fp var_expected = {{0xDB385AD9, 0x764253C7, 0x37F4CF6F, 0xCF1A2C16, 0x3B9A3721, 0x73C02990, 0x11D03E99, 0x018959C1},
	{0x25512294, 0x54E78BD0, 0xE2C7DFD4, 0x11677F45, 0xAE8A5AF5, 0xBBADF5A4, 0x1983A8FD, 0x00028F98},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4931 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4932 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4933 infinity");
	}
	{
		static const bigint_t var_t = {0x6FBD6D66, 0xFD3A24D4, 0xE95EA6B7, 0x6805A594, 0x8F2574F6, 0x96118FD8, 0x0ADB79AA, 0x24246498};
		static ecpoint_fp var_expected = {{0x1B67A259, 0x514DE4DF, 0xC00A20A6, 0x13CDE422, 0x8BEE052B, 0x91A53424, 0xDEF57619, 0x05A2AA0B},
	{0xE59FC3C9, 0xB05C4613, 0x0E41D3C7, 0xCE6CE0E5, 0x4F56B6B5, 0xB4B3EB49, 0xF227A7EE, 0x09C754ED},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4934 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4935 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4936 infinity");
	}
	{
		static const bigint_t var_t = {0x234EE2FE, 0x3D872F8A, 0x717F64CC, 0x5DB2ACBF, 0xB08644B2, 0xD8F15339, 0x2F7198CB, 0x03DCFD7C};
		static ecpoint_fp var_expected = {{0xEFE3B34C, 0xE39A622F, 0x43CD5891, 0x0B84B4F7, 0xFF01B2EC, 0x21C11301, 0xE1F980F2, 0x0D2013D9},
	{0x2B28B8C1, 0x135955CE, 0xCCBB2D53, 0xC83814A2, 0xE11D9F3A, 0xDBD35218, 0x450A77C4, 0x1F97579B},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4937 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4938 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4939 infinity");
	}
	{
		static const bigint_t var_t = {0xE3D4512D, 0x4C73CDF8, 0x28C7F7DD, 0x302DC56D, 0x2A0F2E53, 0x653E41EB, 0x4D2351A5, 0x21F3BF70};
		static ecpoint_fp var_expected = {{0x9E18CB9E, 0xB23F9F4E, 0x3E231F1D, 0x9AD6ABEC, 0x3017FCD2, 0xD2910584, 0xA74EB54E, 0x089FD2DE},
	{0x84419DB5, 0x06BE157C, 0xD6614138, 0x2FD30F6E, 0x4DCC0E23, 0x65610304, 0x7BC69CC5, 0x1948D009},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4940 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4941 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4942 infinity");
	}
	{
		static const bigint_t var_t = {0xA931362E, 0x4A62612A, 0xA4FE2330, 0x23AC9C3A, 0xE616E7A3, 0x2E3E7EBA, 0xD6BF7903, 0x0730C893};
		static ecpoint_fp var_expected = {{0x40F1F4FD, 0xAFE4BAF6, 0x8589F51F, 0xD8A334B0, 0xD058BB50, 0x74C0A61B, 0x496D7AE6, 0x02611BD5},
	{0xA6EBE076, 0x7513C3A9, 0x8E8FEE52, 0x3720A849, 0xF1C34C2A, 0x2B2FD817, 0x769B9CBB, 0x0F9238EE},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4943 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4944 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4945 infinity");
	}
	{
		static const bigint_t var_t = {0xFA583B8E, 0x70C4CDF3, 0x3DCE5D69, 0x2BE705D7, 0x340377BD, 0x4FA5CC74, 0x806294A8, 0x0FDBF224};
		static ecpoint_fp var_expected = {{0x78C7832D, 0xBE0B72D2, 0x5C4EA57A, 0x860E6F30, 0xC2E66C6F, 0x5AEF435E, 0x6917296B, 0x15ED5540},
	{0x75B2F57E, 0x7596FC49, 0xD4F0E3F0, 0xEF0AACA6, 0x8A670C21, 0xB95FC769, 0xA69F2932, 0x09E15640},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4946 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4947 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4948 infinity");
	}
	{
		static const bigint_t var_t = {0xB0368DC2, 0x14BFD515, 0xDBE6ABB8, 0x0549776E, 0xC193A3E9, 0x961E09E8, 0x4AA22F6A, 0x0B70AF5F};
		static ecpoint_fp var_expected = {{0xF8762C0A, 0x8B975BE2, 0x65A9A923, 0x5827C4A1, 0xBA4B6741, 0x524F1AEE, 0xAF31C072, 0x0B8317CE},
	{0x308B2C8D, 0x60BAAFE1, 0xD87C40DF, 0xF965A0A5, 0x9879FA9B, 0x47A30A61, 0x14C89C5A, 0x1098A9EC},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4949 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4950 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4951 infinity");
	}
	{
		static const bigint_t var_t = {0xCDAFAF8E, 0x94C24C78, 0x9E2A1DA0, 0x1314A1F1, 0x26B2423D, 0x3A2A9B00, 0x04BAD624, 0x0820B8FE};
		static ecpoint_fp var_expected = {{0xAE9055C8, 0xA3CBA680, 0x45400649, 0xEF1AB911, 0x53704995, 0x4201D761, 0xF1F72348, 0x13266EB9},
	{0xD074C1CB, 0xAC7916B8, 0xE580BA26, 0x3385D2D7, 0xD7CEC2A3, 0x99EEBBE3, 0x5F35AC90, 0x213DAFE9},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4952 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4953 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4954 infinity");
	}
	{
		static const bigint_t var_t = {0x770D4F38, 0x5FF23E5F, 0x72A44FBD, 0x3EB25D76, 0x4F43E00F, 0x05370F82, 0x2A05B9B5, 0x19A7C697};
		static ecpoint_fp var_expected = {{0x3F64455E, 0x6D93F3EA, 0xB8F02051, 0x1F3A7603, 0x5A440251, 0xE428C0CA, 0x7BFB0200, 0x1D4AA7D7},
	{0x8983040D, 0x2300EA7D, 0x9964B227, 0x3221B344, 0xC199878C, 0x595137FA, 0x862936F0, 0x1CA987D5},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4955 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4956 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4957 infinity");
	}
	{
		static const bigint_t var_t = {0x6D67D52A, 0xF2F0ECBD, 0xBD80424A, 0x6836083D, 0xEEA019F2, 0x1A859561, 0xD88D8CFE, 0x04E08A20};
		static ecpoint_fp var_expected = {{0x2AB90FAE, 0xB0120A16, 0xDD528DFD, 0x99E900E1, 0x6FAFEEBD, 0xDBA0F991, 0x85259866, 0x130F90D2},
	{0xF7667217, 0x0B485924, 0x71BE3021, 0xD86D4BA9, 0x9261CF2E, 0x7A9AEE0D, 0x11FB0A07, 0x09DBD644},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4958 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4959 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4960 infinity");
	}
	{
		static const bigint_t var_t = {0x4452AE32, 0x4BC41BE8, 0x7F0D5A01, 0xF1494E6C, 0x3E179E28, 0xEE4D94AC, 0x4F825C31, 0x102FF2DE};
		static ecpoint_fp var_expected = {{0xB59753AD, 0xD4D2C46F, 0xC501C528, 0x0B479EF1, 0x99EEF870, 0x7951C2C7, 0x3ACC9318, 0x03F958DA},
	{0x1FA2EB1B, 0xC51D345F, 0xDE3718ED, 0x0D347A16, 0x12E3B007, 0xDDC5FED9, 0xC2FC4378, 0x0EE61736},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4961 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4962 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4963 infinity");
	}
	{
		static const bigint_t var_t = {0x84B3EA09, 0xBE77B013, 0xD5F23FC7, 0xFBDE66AE, 0x85574F11, 0x9FD24076, 0x5CFBD2B9, 0x11B189B8};
		static ecpoint_fp var_expected = {{0x5736A376, 0xDF26231C, 0xA04A2981, 0xE632BD36, 0x9CBA5CBF, 0x0149192C, 0x78254C7D, 0x08D836F0},
	{0x64054B8C, 0x399FF958, 0x3DEAD857, 0x86B76C14, 0x6106A1AF, 0xDE350853, 0x511C7F9C, 0x22310D3E},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4964 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4965 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4966 infinity");
	}
	{
		static const bigint_t var_t = {0xE8A3F1D5, 0xCDF5C2AC, 0x006B56CC, 0xA1913185, 0xA02F85BC, 0xAECA5921, 0x4A09BD9B, 0x18D401C9};
		static ecpoint_fp var_expected = {{0x46CC7A73, 0x2C0A1960, 0xF10BA68D, 0xB65E5A89, 0x913222DD, 0x4FC142BE, 0xFE1E18C1, 0x089B11BF},
	{0x255D34F6, 0x7EF2AF88, 0x120297B8, 0x6921B0B2, 0x1FB06831, 0xB821998A, 0xAFBF9B00, 0x14AF6FEA},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4967 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4968 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4969 infinity");
	}
	{
		static const bigint_t var_t = {0xA0E7000F, 0x1879E119, 0xD5DD2A51, 0xA4A6C0CB, 0x8F068FEB, 0xAB3D81F5, 0x5C3C48D3, 0x13B12387};
		static ecpoint_fp var_expected = {{0xBC02DE72, 0xFCDAB686, 0x08DE0D9B, 0xEAF27A02, 0x175B9B46, 0xDC8D0C69, 0xA0FF30AF, 0x1A665D5F},
	{0x58668FD1, 0x762E6B43, 0x2CE55E03, 0xB1A2BD50, 0xEE2D3234, 0x90C51477, 0xCD8A41C5, 0x15681300},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4970 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4971 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4972 infinity");
	}
	{
		static const bigint_t var_t = {0x81572F15, 0x446372A0, 0xB05B6EF3, 0x92456791, 0x01309937, 0xC109CE8F, 0x413B36A3, 0x1F0A6B5A};
		static ecpoint_fp var_expected = {{0xC8D6CABC, 0x41C9AA71, 0xD77DE38C, 0x1767AFD2, 0xF21E7FD9, 0x82CACF38, 0xD58A81AE, 0x1FC1C76A},
	{0xDF8D3879, 0x02F12C1A, 0x3C0EC15B, 0x3EF74C32, 0xCB2C7A0A, 0xCDB31195, 0xF7280744, 0x0DAB8A38},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4973 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4974 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4975 infinity");
	}
	{
		static const bigint_t var_t = {0x8FD0E0F0, 0xEF318ED9, 0x714C7BCD, 0x0F0738A6, 0xA4AED8EB, 0x2843C11F, 0x0F372F31, 0x1F918E04};
		static ecpoint_fp var_expected = {{0xC7E668FC, 0x56124BF9, 0x3DBE1421, 0x12B0B747, 0xF9B04BBD, 0xB9271F33, 0x5B4843CC, 0x037A3FBB},
	{0xD46421F3, 0x6EB56621, 0xB1A39E31, 0x1C376444, 0xC89D3032, 0x0E0A64DC, 0x9B2315B3, 0x171CDB44},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4976 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4977 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4978 infinity");
	}
	{
		static const bigint_t var_t = {0xD8D15719, 0x9B847C4A, 0x1D63202B, 0x19A347EB, 0x74C003B2, 0xADBC6B41, 0xE0DA7AE5, 0x1271A4EC};
		static ecpoint_fp var_expected = {{0xECB187DC, 0xBBE5FB3A, 0x7DC22352, 0x2BC4FC87, 0xA26D1AF5, 0x0778A321, 0x5149E4C7, 0x15A28755},
	{0x0E0EB393, 0x5DF6CDC6, 0x89DBE3FF, 0xC6B9DB72, 0xEFB4F7DE, 0xB39A8371, 0xAF218FF6, 0x17A7B9E5},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4979 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4980 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4981 infinity");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp var_a = {{0x7A2AC322, 0xB9C29173, 0xE40A8DBF, 0x298EE394, 0xA27831E5},
	{0xC861AED5, 0x89D9B4DF, 0x9A84FEC1, 0xD8CF50F8, 0x0FF20C43},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4481 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4482 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4483 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4484 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4485 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4486 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5561BBA0, 0x669AC00E, 0x2E79E580, 0x96DCDB9A, 0xC8E7FFE5},
	{0x10BFDDF2, 0x821CA364, 0xB2D8610B, 0x9FE01F4B, 0xD97EF17F},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4487 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4488 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4489 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4490 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4491 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4492 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x03A0A570, 0xD3449D8B, 0x7698C0DB, 0x84932AB1, 0x0C8AF86B},
	{0x1267CD29, 0x15FD7F20, 0x5E1375C3, 0x7F59AAA2, 0x55076374},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4493 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4494 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4495 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4496 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4497 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4498 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB1C3F84E, 0x32C6A1ED, 0xBA01A20A, 0x87D84846, 0x5A2BE91E},
	{0x6BFFD001, 0xE4885121, 0x0A10967D, 0x7164039E, 0xECB6925E},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4499 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4500 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4501 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4502 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4503 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4504 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE9E424D6, 0xD68D9127, 0x0C818122, 0x5FA09DB6, 0x2B60BF97},
	{0x0612AABE, 0xA3AE06F7, 0xE7BC8963, 0x3CAD363E, 0x3D51B10D},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4505 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4506 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4507 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4508 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4509 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4510 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4C0699D7, 0xCD5B454A, 0x6C66BB7E, 0x7125A55E, 0x09557DB4},
	{0xC3268A0D, 0x264D0740, 0xE4160C86, 0xD2319CE9, 0xD89CE462},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4511 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4512 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4513 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4514 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4515 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4516 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4DC82A2D, 0x0FCEA5A9, 0x4368A7BF, 0xB3C5499B, 0x8A54D2ED},
	{0x3AD0F7A6, 0xFCEEB0A0, 0x0699E22D, 0x637DF2DA, 0xCB08CB96},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4517 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4518 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4519 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4520 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4521 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4522 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xC6CCEA05, 0x20CE4E7A, 0x0AC33F80, 0xD00CB24A, 0x1612E413},
	{0x545DBF9B, 0xFAC135A1, 0x82FE8CD2, 0x1A2A4B51, 0x29F4E704},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4523 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4524 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4525 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4526 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4527 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4528 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x631FBEC7, 0x4E035DBB, 0xD8D132AE, 0x5D5825DA, 0xE64D1908},
	{0x9072892B, 0x2268A93D, 0x4796727D, 0xECD956DC, 0xFEFB59F7},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4529 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4530 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4531 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4532 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4533 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4534 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x299454B6, 0xF6D257CB, 0xF90DBAE7, 0x4D97E96B, 0x27BF90B1},
	{0x30094A3D, 0xC25F3CB5, 0xDBDF84DE, 0xE26CCFBD, 0x4ABBB384},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4535 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4536 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4537 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4538 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4539 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4540 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAD2B0A17, 0x72274347, 0xB6471019, 0x0673BD69, 0x22EBFBD3},
	{0x9D874FBD, 0xC8823864, 0xB58CFCA0, 0xC023E0A8, 0xF2C9C78A},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4541 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4542 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4543 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4544 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4545 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4546 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB93CFF9E, 0xA07F8FFD, 0xF09024F5, 0xC787D984, 0xD9BCF4A3},
	{0xC6A55C05, 0x9D915155, 0x7F9E644B, 0xFA271B94, 0xD052567A},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4547 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4548 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4549 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4550 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4551 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4552 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x69F53904, 0x267C2AC5, 0x4BCA52BC, 0x4283365D, 0x7BDE9ED9},
	{0x4AE947D0, 0x0274D6E5, 0xE001F3CB, 0x53AE0E29, 0x449ED703},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4553 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4554 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4555 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4556 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4557 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4558 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0CCAA959, 0xD78C6247, 0xEC9D2120, 0x92DB6C4E, 0x9616F0DF},
	{0xA3887A34, 0xC1E2494E, 0xBD063037, 0x9D272E1A, 0xF93D00AE},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4559 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4560 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4561 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4562 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4563 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4564 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x482EB9D3, 0xE9575474, 0x1FFFAFDC, 0xF7A51B4B, 0xFCCCDAFE},
	{0xB9C10E5D, 0x39178B9D, 0x1C42F22F, 0x73C35E19, 0xB66FE490},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4565 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4566 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4567 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4568 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4569 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4570 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5A8DA638, 0xE1451D94, 0x64942A40, 0xFEB3176C, 0xA96F25E8},
	{0x78F73DB4, 0x08FA8CCA, 0x040B2D53, 0xE37A13A6, 0x74A04619},
	0};
		static ecpoint_fp var_expected = {{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x, var_tmp.x, "ecfp_clear 4571 a.x");
		assert_bi_equal(var_a.y, var_tmp.y, "ecfp_clear 4572 a.y");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp_clear 4573 infinity");
		ecfp_clear(&var_tmp);
		assert_bi_equal(var_expected.x, var_tmp.x, "ecfp_clear 4574 a.x");
		assert_bi_equal(var_expected.y, var_tmp.y, "ecfp_clear 4575 a.y");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp_clear 4576 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x17A609D4, 0xE6D11B6C, 0x93F937C0, 0x1D9A3E64, 0x1864F73A},
	{0x6E2C119C, 0x3357C6AD, 0xBA0A55C3, 0x0C6AEB97, 0x0E0EC43A},
	0};
		static ecpoint_fp var_b = {{0x55C673E5, 0x57DB70B6, 0xD27CD7E8, 0xA7A59231, 0x0CBE1E96},
	{0x62F3F835, 0x6C6ECAB2, 0x5500DA32, 0x292AE5D3, 0x15F3C54B},
	0};
		static ecpoint_fp var_expected = {{0x4BE36E90, 0x22DC6F07, 0xA73937EC, 0x72DE692B, 0x17725AAA},
	{0x9BA08A51, 0x6FE4F160, 0x0E835EFA, 0x096D60FC, 0x0B33382E},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4577 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4578 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4579 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x0441D125, 0xE594C4F7, 0xB0CF68FC, 0x7329CC98, 0x13E70CF0},
	{0xACDBF6FB, 0x35A2EF33, 0xDF01A578, 0xD9D027AD, 0x0F2BB2E7},
	0};
		static ecpoint_fp var_b = {{0x92A72C4F, 0x87515472, 0x31321560, 0xD24DEF93, 0x05D678F7},
	{0x3795B3B8, 0xD803C67E, 0x738F3BD4, 0xB3B26856, 0x1F389937},
	0};
		static ecpoint_fp var_expected = {{0xD9C2B327, 0x6F98134E, 0xCD768791, 0x67882CDC, 0x0DE6CBC5},
	{0xA7366C45, 0x0C20D880, 0x5979EFDA, 0xE464A0F7, 0x0BC4C429},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4580 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4581 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4582 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3611A401, 0x25963252, 0x1CFDD7D5, 0x7CF221AB, 0x114528E1},
	{0xE81C3F60, 0x19A3D410, 0x0BEAD90B, 0x1097D769, 0x1D8EE03E},
	0};
		static ecpoint_fp var_b = {{0xDF38C745, 0x8ACB3A29, 0x2AC331D9, 0xD2D4D508, 0x189A9BF9},
	{0x7C9FFD7F, 0x382C392E, 0x768E44EC, 0x364B2D20, 0x06BFE990},
	0};
		static ecpoint_fp var_expected = {{0xD6137F5F, 0x82FE2897, 0x0670E7BA, 0xE1608FCE, 0x02C2CCCE},
	{0x472BB20F, 0xB79DD88C, 0x8EAF6879, 0xDA5F2B22, 0x134D3CEA},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4583 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4584 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4585 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x1420DE72, 0x61D011AB, 0x375D527A, 0x5CEFCCE3, 0x12161178},
	{0xFFE0C570, 0xFEBD3846, 0xD8D87221, 0xBE222942, 0x2222EA65},
	0};
		static ecpoint_fp var_b = {{0x1F7CE930, 0x6637A720, 0x6E51EDCF, 0x4939FB33, 0x15D9EB51},
	{0x0D5DCA3B, 0xE6A036F6, 0x9ABD6E6F, 0x9B5C2256, 0x1E437652},
	0};
		static ecpoint_fp var_expected = {{0xE2009B1B, 0x23C926BF, 0x4542A63D, 0xA266E4B6, 0x14B6548F},
	{0x893FA56B, 0xC83EAF19, 0xEA155BB4, 0xF46AB333, 0x225FA9C4},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4586 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4587 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4588 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2907D772, 0x3DD0DDC0, 0x68E09F51, 0x4608C935, 0x13B9C72F},
	{0xC8F86769, 0x0B6C9CF4, 0x67FDDAFA, 0x4537F83E, 0x1E98383B},
	0};
		static ecpoint_fp var_b = {{0x2A304ED6, 0x826CD47D, 0x0880F63F, 0x053DA0D7, 0x04842170},
	{0x7C552F5B, 0x5357DA92, 0x6EE56FA3, 0xE54599B2, 0x0FC58316},
	0};
		static ecpoint_fp var_expected = {{0xC61CD165, 0xABE14F39, 0x48D4AC82, 0x262D8736, 0x0E0641C0},
	{0x4C1AEE90, 0x85A93EDE, 0xCFAB33B4, 0x1ED3D0C2, 0x0F558EB9},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4589 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4590 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4591 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x351987A7, 0x4B6C7E40, 0x0DAB1B75, 0x272EE6E0, 0x0D6BE941},
	{0xD16670C6, 0x747182C7, 0xC0CAABB5, 0x26E048F5, 0x149C36C9},
	0};
		static ecpoint_fp var_b = {{0xBAFC2EFD, 0xBA8B27B0, 0x7B02875E, 0xC2729AFE, 0x1D3004BC},
	{0x41E78E87, 0x45C8BD6F, 0xF25179DA, 0x95EE267A, 0x11F167AD},
	0};
		static ecpoint_fp var_expected = {{0xFBD9E4F3, 0xB9CE51EE, 0x6B9A6C2B, 0x262D5BBF, 0x21F33911},
	{0x94CF939C, 0x0B092F3B, 0x3FC3E7CB, 0xDA55171E, 0x0FF401C3},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4592 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4593 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4594 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x67CA6A09, 0x086A5D04, 0xB1F22DFC, 0xA7DEAEE2, 0x02ECBE1E},
	{0xE2693025, 0x7159411F, 0x4B77EAC3, 0x19C2CA03, 0x21E39B38},
	0};
		static ecpoint_fp var_b = {{0xEAA0ED2E, 0x37EB9278, 0x2D97C905, 0x62B5E66F, 0x0E25A07F},
	{0xF6C28153, 0xCB03BCE3, 0x0B45A8AF, 0xE2EB4239, 0x0A597342},
	0};
		static ecpoint_fp var_expected = {{0xF935B115, 0x662A4DE0, 0x5E5A2A06, 0x07E43226, 0x20B26E11},
	{0x3166B60A, 0x43F803E3, 0x95FC3E41, 0x1122F9D2, 0x0776A17C},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4595 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4596 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4597 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF2EF5FEC, 0x8A56A999, 0x6EBF5B58, 0xEAF736A8, 0x23A91E2A},
	{0x73BF7E55, 0xDF410A8A, 0x69EED4A2, 0x8532587F, 0x20B3BC31},
	0};
		static ecpoint_fp var_b = {{0xB6681087, 0x78F2E497, 0xB011BE40, 0x569AE88C, 0x0B146151},
	{0x86544E8B, 0xA61EF2A2, 0xB94A07E6, 0xDA84020A, 0x0374518E},
	0};
		static ecpoint_fp var_expected = {{0x7802A11F, 0x08E032F9, 0x66CB1546, 0x747AAF9A, 0x159EE579},
	{0x7D818853, 0xB2043230, 0x5F401D09, 0x5F73279E, 0x20D9783D},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4598 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4599 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4600 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD6C8D21C, 0x0AF0C931, 0x6FF17466, 0x1AB42237, 0x11BA0917},
	{0xD6320014, 0x29D564FB, 0x27877942, 0x9ABA03D2, 0x18501F99},
	0};
		static ecpoint_fp var_b = {{0x4B6C6BA4, 0x591B7EAE, 0x9632DFBC, 0xCB6284B0, 0x1CD765B2},
	{0x3AB78705, 0xAD23110A, 0x599B3B13, 0x1155F9D6, 0x0ACF4365},
	0};
		static ecpoint_fp var_expected = {{0x7F8C23DE, 0xF0D98B35, 0x13E057EA, 0x7673314A, 0x07F4D380},
	{0x774CC765, 0x47A1D6CA, 0x09EAD1F9, 0xA75C3EBC, 0x15213AAA},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4601 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4602 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4603 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF96AEAE0, 0x63D5262C, 0x4CA49EC4, 0xCEFACC1C, 0x0C179F8F},
	{0x60DE5F6C, 0xD716F9FF, 0xACE38F5E, 0xE56D506C, 0x0139FBA0},
	0};
		static ecpoint_fp var_b = {{0x42054BED, 0x6136E4AE, 0x05131521, 0x8CA2E7D6, 0x1D17FE67},
	{0xF39AB383, 0x887C334B, 0x51F530EB, 0x2DA38FED, 0x132D98C1},
	0};
		static ecpoint_fp var_expected = {{0xFA36FF43, 0x7D6B0516, 0x08AE5539, 0x808AE5FC, 0x054F7AE8},
	{0xFB52D2BB, 0x53865C08, 0x0363EA9D, 0x7B6211E1, 0x133484E3},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4604 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4605 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4606 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x3051B776, 0xD232F225, 0xA0E21172, 0x9A24A303, 0x1E168301},
	{0xA07F85F6, 0xBD84F2D7, 0x6B80E98B, 0xC712E596, 0x0B6EBDEB},
	0};
		static ecpoint_fp var_b = {{0xA0F4C04E, 0xDA7C8D0D, 0xD9211D1A, 0x827D1B32, 0x1E63999A},
	{0x3CFEF6A4, 0x613D756F, 0xD9D5192A, 0xDC4B22E4, 0x04E2D65B},
	0};
		static ecpoint_fp var_expected = {{0x1CF613A5, 0xF5A5F564, 0x110F0C18, 0x8615B33D, 0x02F9FA3A},
	{0xE725EF02, 0x6076E6A6, 0x4791E82C, 0x990CA480, 0x143B321D},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4607 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4608 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4609 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA6AA7929, 0xAC15888F, 0x0D5CE8EF, 0x44FF8229, 0x22910C05},
	{0x9639995C, 0xF7DD4178, 0xACFFA3B5, 0x49E42F02, 0x13D61FFF},
	0};
		static ecpoint_fp var_b = {{0x84AB6427, 0x10BDFD6F, 0x5C272415, 0xEBBC286C, 0x203F9DFD},
	{0xF88039F8, 0xF3D0AC52, 0xA6290AEE, 0x73C124B7, 0x000131ED},
	0};
		static ecpoint_fp var_expected = {{0x4308A930, 0x0E4AFD02, 0x12C7E6FA, 0x639E4C68, 0x047438CB},
	{0x29C075E3, 0x8DC99CB8, 0x765D3466, 0xDEA67FC4, 0x02386613},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4610 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4611 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4612 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA45D5979, 0x231C898A, 0xC79BD99F, 0x5336236A, 0x0B3A7EF1},
	{0xC67CDDBE, 0x407BCF0A, 0xC7373B56, 0x8CAE76E8, 0x1C17EBC1},
	0};
		static ecpoint_fp var_b = {{0x41CB348C, 0x44AEC232, 0x4F6EAFA5, 0x15EC3930, 0x0934D00C},
	{0x8AB08D8E, 0xC529DD31, 0x42D00191, 0x77EF77DC, 0x13AB9297},
	0};
		static ecpoint_fp var_expected = {{0x1A3A81D7, 0x7FDCB857, 0x0F06D1D3, 0x8EAEBC21, 0x2300D4AF},
	{0xCE0EBA17, 0x4F1ADB6D, 0x6A7FBC5D, 0x5FCEF3F2, 0x0CC04CE8},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4613 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4614 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4615 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x737EB24E, 0x1B677575, 0x25F3A2EC, 0x4A1A16EF, 0x0BE805EC},
	{0xB549C920, 0x52CA2CC7, 0x31042C6C, 0xCA2CC804, 0x04433E17},
	0};
		static ecpoint_fp var_b = {{0xA7C57074, 0xC9774A1D, 0xB4BCF11E, 0x22D3E359, 0x0B805DC6},
	{0xB2035B42, 0x9D1D9D54, 0x60472734, 0x93A78CD5, 0x1789D6A8},
	0};
		static ecpoint_fp var_expected = {{0x92BDFBFF, 0x3D4217C8, 0xA7C32547, 0x047174E7, 0x1928B33E},
	{0x3FE1FEA6, 0x0EBD13EB, 0x400EFC33, 0xCB6ECE14, 0x1D7F6070},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4616 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4617 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4618 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xECF7697E, 0x606D9C0C, 0x1A8CFF4A, 0x80EE9DB7, 0x1876024E},
	{0x0B2E7FF9, 0x6CAF39C2, 0xCD83BA28, 0xA5A1B6D7, 0x110618BB},
	0};
		static ecpoint_fp var_b = {{0xD3951721, 0xE97A6009, 0x409006BE, 0x4C9DB7F3, 0x0E240599},
	{0xD973FE97, 0xEC831D2B, 0xCEDD37C1, 0xA73E7819, 0x0B24709E},
	0};
		static ecpoint_fp var_expected = {{0x3F7C1FA6, 0xF1BF929F, 0xC568B225, 0xE0571305, 0x15F8732B},
	{0x9D6735A7, 0x7069708D, 0x0BE613CE, 0xAC13423C, 0x0C6BD5C9},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4619 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4620 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4621 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x065261C4, 0x501A4EF5, 0x0D828282, 0xECC6EA18, 0x2005B17F},
	{0xB9DDEA16, 0x6C8B4D97, 0xD2723AA7, 0x54DC50C2, 0x1EC4F17E},
	0};
		static ecpoint_fp var_b = {{0x11315B87, 0x3A463736, 0x8E6F83ED, 0x7FC63679, 0x1F34E7EA},
	{0xEAE1028A, 0xC1133FEC, 0x39D833FA, 0x68A80ED0, 0x06ECFF0C},
	0};
		static ecpoint_fp var_expected = {{0x99A11BF2, 0x572C4316, 0x68FF6531, 0x9158CF09, 0x222A8A1F},
	{0x283FC7F7, 0x60F2702F, 0x51F93099, 0xF3DE9A47, 0x1F726DAB},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4622 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4623 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4624 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD1C52659, 0xE4013A84, 0xDA55E3AD, 0x1405A138, 0x20828F9A},
	{0x1FC941FD, 0xA103C1CC, 0xA54B3602, 0xC6AE1508, 0x091324CC},
	0};
		static ecpoint_fp var_b = {{0xD1C52659, 0xE4013A84, 0xDA55E3AD, 0x1405A138, 0x20828F9A},
	{0x1FC941FD, 0xA103C1CC, 0xA54B3602, 0xC6AE1508, 0x091324CC},
	0};
		static ecpoint_fp var_expected = {{0xB05592AF, 0x8D7B131C, 0xF9ECDFE9, 0xE9ECAD66, 0x16600AA2},
	{0x84AA30E4, 0xC5ED34EB, 0xC1BE62B9, 0x38E09F40, 0x0E6BE9EA},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4625 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4626 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4627 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA2863BEB, 0xF43FB2D2, 0xFA5175CD, 0x5B697C82, 0x056522DB},
	{0x7A7F205C, 0xF217B590, 0x4D5C2CB7, 0xE4E82AD8, 0x021AD606},
	0};
		static ecpoint_fp var_b = {{0xA2863BEB, 0xF43FB2D2, 0xFA5175CD, 0x5B697C82, 0x056522DB},
	{0x7A7F205C, 0xF217B590, 0x4D5C2CB7, 0xE4E82AD8, 0x021AD606},
	0};
		static ecpoint_fp var_expected = {{0x3E9C060E, 0x3AB3BA18, 0x678E7FAB, 0x065046D0, 0x1ED31864},
	{0x6589BABE, 0x682CE3C6, 0x96722C3E, 0x6BF409F6, 0x118451D4},
	0};
		ecfp_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_add_affine 4628 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_add_affine 4629 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_add_affine 4630 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xE9FFAAE2, 0x0A433A79, 0xA12AB693, 0x2B8B6BB2, 0x02FC1311},
	{0x51539E0A, 0xA769B748, 0x16335EC6, 0x0F987FD7, 0x1CF86523},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x74672115, 0x3E0EF4ED, 0x8F2939A5, 0x16255584, 0x03390332},
	{0x81E7A89D, 0xBEF14B80, 0x764AA634, 0x29E36D30, 0x0DDE4130},
	0};
		static ecpoint_fp_proj var_expected = {{0x8E32E70D, 0x0BE7041A, 0x4F46C491, 0x5D2D0D5E, 0x0958F43A},
	{0xA2260DCD, 0x29EDBCB2, 0x7325313F, 0x30ACAD16, 0x01C39370},
	{0x8A677633, 0x33CBBA73, 0xEDFE8312, 0xEA99E9D1, 0x003CF020},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4631 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4632 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4633 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4634 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x619971AE, 0xF8E18961, 0xE8F90C2F, 0xAD1C478C, 0x23537D5E},
	{0x57C8DDD9, 0x01B8B17E, 0x2E41E063, 0xBF21E740, 0x02AFFFD6},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x18821D72, 0xEC6D4459, 0x3D7DF63C, 0xA7650BD0, 0x2190AB20},
	{0x77EC9948, 0xFC6C0664, 0xDBD90921, 0xD7FFCB38, 0x1D658DC5},
	0};
		static ecpoint_fp_proj var_expected = {{0x0D7E07E0, 0x779CA121, 0xD053CE7F, 0x7DB65B6F, 0x1D26E035},
	{0xDC748F09, 0xABAE22F9, 0xFBDC250B, 0x4A14BF3E, 0x21CB19FD},
	{0x0338FE1F, 0x11B90F98, 0x8DCFAAAB, 0xA99F2029, 0x223E4DC5},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4635 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4636 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4637 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4638 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xBE8B832C, 0x63D5032A, 0xA2EF590F, 0xF9C035E7, 0x21786714},
	{0x06D0F292, 0x7987A2D0, 0xA4C7A649, 0x54861658, 0x18ED3FC7},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x5E678C8C, 0xFF817363, 0x953D1EE7, 0xAD146C77, 0x0DF4A2F1},
	{0x65D13D49, 0xC1662B3F, 0x36AE98AB, 0xED89A375, 0x0D5FD349},
	0};
		static ecpoint_fp_proj var_expected = {{0xCEC8BD8B, 0x72312505, 0xE1D42CC1, 0x81208074, 0x001375F3},
	{0x6B4E08BB, 0x740BA354, 0x1CEF95E2, 0x2234CB36, 0x0EB017AB},
	{0xEC2C5BBB, 0xB9D9C4D8, 0x2B988676, 0x62AA9276, 0x107D5BE0},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4639 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4640 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4641 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4642 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x73CB4AF3, 0x454724E5, 0xAE905AE1, 0x86B7407B, 0x2134B3E6},
	{0x59C168FF, 0x899AFA43, 0xD25FFC85, 0xB734B255, 0x0D81BA93},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x2CD20A82, 0xC27849AC, 0x74DFC1B6, 0xB2C77A49, 0x19D49B1A},
	{0x14962E92, 0x22045F5E, 0x85720252, 0xC53BB496, 0x0CB1A12A},
	0};
		static ecpoint_fp_proj var_expected = {{0xB630CB52, 0x4E3C4E57, 0x21D4C33A, 0x18AE5359, 0x15A3FE2D},
	{0x591B8B13, 0x8C92ACA5, 0x2D18486B, 0x24B038A1, 0x10F20625},
	{0x055711EA, 0x9B5E7967, 0xFF9A2773, 0xDB6695B3, 0x1CA10737},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4643 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4644 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4645 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4646 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x6F693860, 0x7AE2FAD5, 0x7361C999, 0xEF74B1DD, 0x1BA58E6B},
	{0xC74FDC6C, 0xC9B7DDD1, 0xA03C4870, 0x537F5093, 0x081B1243},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x18B4976A, 0x48580A24, 0x07C01C3C, 0x1C53224C, 0x021E0838},
	{0xAA2FA8F0, 0xC09AE85F, 0x03622958, 0x5B3B5ABC, 0x0DEDE5D1},
	0};
		static ecpoint_fp_proj var_expected = {{0x3D4739D3, 0xE669AA88, 0x07485E52, 0xD3E9FBB0, 0x0BEFF78A},
	{0x4743ABEB, 0x30F97E93, 0xD9B077F1, 0xEDCC72AB, 0x0149E5D5},
	{0xF59BB165, 0xEBA263EE, 0xCDA91340, 0xDC34CC54, 0x0A7999CF},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4647 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4648 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4649 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4650 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x81C03DFC, 0x8914CE66, 0xFCE5BE2B, 0xA0395AB9, 0x23FD0D83},
	{0x7555FCED, 0xAB823A03, 0x7F0A58E6, 0x051F0CD2, 0x0E880E34},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x63ACD488, 0xDCED49D6, 0xB3CBED9C, 0x9F27B40A, 0x0DB7F282},
	{0x21B0D63C, 0xA0AF0AA4, 0x9F9E08AD, 0xE619FE11, 0x14126F54},
	0};
		static ecpoint_fp_proj var_expected = {{0x76A48968, 0x974CD6F2, 0x9A4A4742, 0x575154FC, 0x11C15AD4},
	{0xFB6BDD2C, 0xA3BA5FDB, 0xDA3F42A8, 0x0C3251EE, 0x17817B2A},
	{0x2E3CE8E7, 0x7205D010, 0xF030F00F, 0xAE44B536, 0x0DBC0502},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4651 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4652 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4653 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4654 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x1584393B, 0xCB51DC3D, 0xE96C77FC, 0xE03FCF6B, 0x0A89CC90},
	{0x65DC15BF, 0x8FADF6C0, 0xDA00982F, 0x3CC0E044, 0x13213AA0},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0xE7C131FB, 0xAABA9EE8, 0xBCE44285, 0xD08E369D, 0x1C7E84AD},
	{0x7F251333, 0x80C64331, 0x7327277D, 0x4822F624, 0x0868181E},
	0};
		static ecpoint_fp_proj var_expected = {{0xAE562AF7, 0xD039C32E, 0x257A4B06, 0xA868AC18, 0x11B3CDA3},
	{0x5B8D1B14, 0x4D65BC09, 0x216737A7, 0x3ADE0C1A, 0x15098E70},
	{0xD23CF8C0, 0xDF68C2AB, 0xD377CA88, 0xF04E6731, 0x11F4B81C},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4655 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4656 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4657 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4658 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x276E3FA6, 0x4C6FA3FF, 0xE0B09316, 0xF014B348, 0x10D8D51A},
	{0x60E5D5EA, 0x03826D8C, 0x486714C4, 0x59CEC1BC, 0x005F0575},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0xCE18C852, 0xC68346B8, 0xD6D98617, 0xDDB53CEC, 0x23F20D44},
	{0xD8D90A81, 0xAF498EB3, 0x9E1365CA, 0x84339E36, 0x033BAE72},
	0};
		static ecpoint_fp_proj var_expected = {{0xF82952C4, 0x61F68A93, 0xCCF6E613, 0xD102EC2F, 0x08E13216},
	{0x752ACD04, 0xB3012BCD, 0x785950AC, 0xBAFDBB7A, 0x12B31E90},
	{0xA6AA88AC, 0x7A13A2B9, 0xF628F301, 0xEDA089A3, 0x13193829},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4659 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4660 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4661 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4662 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x0BB5CA79, 0x907A2DA1, 0x283ECFDD, 0x84F7A5E1, 0x14CC7ADA},
	{0x8E0F8F0C, 0x60C5DDFA, 0x0CF82202, 0x4036F5E5, 0x15D231ED},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x16A6B522, 0x24AB603B, 0x1FA85835, 0xE8B59B66, 0x1D4E218C},
	{0x75615EA0, 0xCDE9332F, 0x3389F378, 0xDAAF3F43, 0x1C3A3E32},
	0};
		static ecpoint_fp_proj var_expected = {{0xF932A38A, 0x05BD5926, 0xD4DFAF03, 0xA4F07EAA, 0x00251AF0},
	{0x70B0C0F5, 0x028F092E, 0x4FF95D26, 0xBE931600, 0x1B9141DF},
	{0x0AF0EAA9, 0x9431329A, 0xF7698857, 0x63BDF584, 0x0881A6B2},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4663 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4664 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4665 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4666 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x8F3B60C1, 0xC5FEB81D, 0x7CD6B92F, 0x6919ACFF, 0x02EA3278},
	{0x9AEBEE59, 0x9FAAB110, 0x159421F4, 0x4D342528, 0x053DF286},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x7C8881C8, 0x85BDCF52, 0xE0038D5F, 0xF3268CAB, 0x09A208D7},
	{0xA4C475F1, 0x8B44B08C, 0x09909E01, 0xD45F23EA, 0x1EFE9C0D},
	0};
		static ecpoint_fp_proj var_expected = {{0x60163AA2, 0xDAAEB163, 0xD9E50B33, 0x38061394, 0x1B5D90A9},
	{0x8ADA8F9A, 0xF91F4695, 0xF4CBF7CF, 0x71BFF753, 0x13A6FCA1},
	{0xED4D2107, 0xBFBF1734, 0x632CD42F, 0x8A0CDFAC, 0x06B7D65F},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4667 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4668 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4669 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4670 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x11A50D37, 0x5413BCFB, 0x07C6DD75, 0x365AC1DA, 0x119E5171},
	{0xE2856880, 0xA8B5888E, 0x2B28A05C, 0xE94B9895, 0x20348414},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x55569D19, 0x6B31AA6A, 0x7C562D6C, 0xDE56DA7C, 0x152ED16B},
	{0xAB18407A, 0x9727907C, 0x732B7122, 0x830DCA2E, 0x06F5CF21},
	0};
		static ecpoint_fp_proj var_expected = {{0x24662888, 0x0D490C85, 0x7DE45413, 0x492C6AB1, 0x18FF7E18},
	{0xF92D18E3, 0x25E3D229, 0xDF10C1B0, 0xE4BBC260, 0x0C6DA66F},
	{0x43B18FE2, 0x171DED6F, 0x748F4FF7, 0xA7FC18A2, 0x03907FFA},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4671 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4672 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4673 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4674 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x3A3752E3, 0x51984A67, 0x7C4DE7D5, 0xC4723DFB, 0x2089BF64},
	{0x1B062E4A, 0x68749207, 0xA702A0DA, 0x60E20211, 0x007CAB7E},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x7EAA3A57, 0x877AE3B5, 0x1B7442C5, 0x504EB3BD, 0x08C2C465},
	{0xCE91B87A, 0x9A17E6AF, 0xEFD9D3F4, 0x31BC98CE, 0x1BBA4BC5},
	0};
		static ecpoint_fp_proj var_expected = {{0x4CB37CAA, 0xCC16AF7E, 0xA7E0BEB2, 0xFEF9B35B, 0x02069BA8},
	{0x3FBB1FE9, 0x087A14F4, 0xC2EFC22A, 0xEE9EC01C, 0x1096CBFE},
	{0x90C339CF, 0x540FEDEE, 0xD8711B8E, 0x3B32D1A7, 0x0C3A2504},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4675 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4676 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4677 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4678 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x43FC2244, 0x7C86B1D1, 0xCEEC4137, 0xF22FA2A9, 0x18CA5BF8},
	{0x003EB20B, 0x413102CA, 0xA7297048, 0x49A037F2, 0x165E8CD8},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0xE9F3DE85, 0x9F34FA3A, 0x4E55511D, 0x4F321F05, 0x09F594E3},
	{0x354DBB2F, 0xBD09B152, 0x3BF177B1, 0xE04458E7, 0x204822C9},
	0};
		static ecpoint_fp_proj var_expected = {{0xE4C0D042, 0x6F7680B1, 0xA3CE12DF, 0x6F6AEE53, 0x1703155A},
	{0x15A475B3, 0x79D49A8F, 0xD087B5EF, 0xEC05D3E2, 0x0E4D7D1C},
	{0xF2480E9C, 0x40DB9D09, 0xB8B3D084, 0x0C58D841, 0x152C58EE},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4679 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4680 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4681 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4682 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x808687F6, 0x0A72CC14, 0xE82F9137, 0x51EDC6A4, 0x09533C9E},
	{0x46811141, 0xE7223B14, 0x3F8C9BEA, 0xC48FF6E1, 0x2099F8A0},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x295789EE, 0x480C3963, 0xDFD7C7F0, 0x09663E81, 0x1B3815DE},
	{0x863C9BED, 0xE1AE313D, 0x19F6EA0E, 0xA43A2CA1, 0x09B0FD20},
	0};
		static ecpoint_fp_proj var_expected = {{0x842BDB1C, 0xEA290C9A, 0xE834048E, 0x30A8C720, 0x22BECCEE},
	{0x729BD7DE, 0xFB9BF873, 0x79B88FAC, 0x67CD0732, 0x060EE19E},
	{0xA8D101F8, 0x3D996D4E, 0xF7A836B9, 0xB77877DC, 0x11E4D93F},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4683 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4684 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4685 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4686 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x63F0F01D, 0xCCDE196E, 0x3AACA406, 0x67320376, 0x08599EDF},
	{0x67F36B71, 0xBA243A1F, 0x7F839EA4, 0xCBDD2907, 0x1011BF69},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0xB2BAE1D4, 0x009B2519, 0xC1EA68C3, 0xBD5BD9D8, 0x18A76458},
	{0x4DEF612E, 0x939D3C1A, 0x2D613C53, 0xE18F0E45, 0x0811DE13},
	0};
		static ecpoint_fp_proj var_expected = {{0x9B7B677F, 0x9BE85B7C, 0x3F3F761E, 0x4C13E720, 0x0C23298F},
	{0x35E9A3B4, 0xAF584917, 0x2D215041, 0xB07E4CE5, 0x1265E2DE},
	{0x4EC9F1B7, 0x33BD0BAB, 0x873DC4BC, 0x5629D662, 0x104DC579},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4687 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4688 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4689 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4690 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x36DEB7B5, 0x01142349, 0x7F67ADB5, 0x6D454341, 0x1D33CFEA},
	{0x44801E44, 0x1E16FB1F, 0x0C04166D, 0x03DDC5E5, 0x188BC4EC},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0xD95335EE, 0xF5A236E8, 0x4E186109, 0x22DB1A1C, 0x1650A056},
	{0x85CD576F, 0xE97F5BF4, 0xF04F11A1, 0xFD225A97, 0x20196A15},
	0};
		static ecpoint_fp_proj var_expected = {{0xB483A8EB, 0xF2D45FF1, 0xCDC02477, 0xDF9B78B0, 0x1FDA0A3C},
	{0x21D38FB1, 0x6FBAB743, 0x166D1362, 0x02D3E25C, 0x05836F9E},
	{0xEEC4D094, 0x12BB683F, 0x07FB73F3, 0x64EC32C1, 0x1D1DF06F},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4691 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4692 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4693 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4694 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5971E587, 0xB3905DC3, 0x2075B43E, 0x68A6117A, 0x0952884E},
	{0x8DE63C05, 0xE68B31F5, 0x0FEACEC5, 0x49BDF347, 0x1EE8083F},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x5971E587, 0xB3905DC3, 0x2075B43E, 0x68A6117A, 0x0952884E},
	{0x8DE63C05, 0xE68B31F5, 0x0FEACEC5, 0x49BDF347, 0x1EE8083F},
	0};
		static ecpoint_fp_proj var_expected = {{0xBF827E2B, 0x69C08E67, 0x6A96BEF5, 0x47779567, 0x1C2E41C4},
	{0xAEF9E2F6, 0xD1E835E9, 0x9EDC9F85, 0xACE49078, 0x18EA8FC4},
	{0xCF7C25AF, 0xAEE90F4A, 0xE68ADCED, 0xE4258AA7, 0x19CEF07A},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4695 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4696 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4697 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4698 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x341AA45E, 0x59D7EBE8, 0x28F3B4B1, 0xFDE2CAB2, 0x149316AB},
	{0x0B04988A, 0xCF373DF6, 0x5977CB3A, 0x522FDE62, 0x1644C2D6},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp var_b = {{0x341AA45E, 0x59D7EBE8, 0x28F3B4B1, 0xFDE2CAB2, 0x149316AB},
	{0x0B04988A, 0xCF373DF6, 0x5977CB3A, 0x522FDE62, 0x1644C2D6},
	0};
		static ecpoint_fp_proj var_expected = {{0x61547794, 0x8DA6CDFB, 0x92C7C1F1, 0x495BE256, 0x1939FA4D},
	{0x9F4E83F3, 0xF50BD05C, 0xF9C4E994, 0xA09BD427, 0x025B0A83},
	{0xC9B8DEB9, 0x8041274B, 0x79A4D5D7, 0xF50960DE, 0x088865A8},
	0};
		ecfp_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_add_proj 4699 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_add_proj 4700 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_add_proj 4701 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_add_proj 4702 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE6094C28, 0xDD1DBD3A, 0x28DAF701, 0x937193F6, 0x0E2093F7},
	{0xEE18838E, 0x64E5C8B6, 0x43D2A935, 0x98C135F2, 0x048132EF},
	0};
		static ecpoint_fp var_expected = {{0x65403A5A, 0xDB060AD7, 0x260114DF, 0xCC189E3F, 0x0372B4E9},
	{0xA39B7A60, 0x11618217, 0xA06AF3C0, 0xD08C258A, 0x1A417BDB},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4703 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4704 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4705 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xF632A40E, 0xBA94C718, 0x7B921890, 0x34B799D6, 0x14BF08A2},
	{0x1EF6AC19, 0x193FEB0E, 0xA616552C, 0x4885772A, 0x15FEC4FC},
	0};
		static ecpoint_fp var_expected = {{0x2C651FCD, 0xD2138E49, 0xB97E256A, 0xDA81B905, 0x1D9AD4B0},
	{0xFD856108, 0xAC54E0A9, 0x10339FAA, 0xB31120E4, 0x1EDEDC7A},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4706 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4707 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4708 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xBBF6C633, 0x74193151, 0x5E716BC8, 0xEF6278EC, 0x11E6EAA3},
	{0x77F3F62B, 0x8FFF8789, 0x361DB3EE, 0x4DF3729D, 0x1FD09588},
	0};
		static ecpoint_fp var_expected = {{0xD99084F1, 0x1277C623, 0x917C8916, 0x1C5D84DA, 0x0FC677F1},
	{0xCDEBBFF4, 0x1346512F, 0x32427797, 0xF26C538A, 0x20300CEE},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4709 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4710 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4711 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x40A09914, 0x5FE053D1, 0x0BCE06B5, 0x539E019B, 0x0C1E6F81},
	{0xF995843A, 0x496DC034, 0x33448C77, 0xAFF299C8, 0x01FFC69E},
	0};
		static ecpoint_fp var_expected = {{0x54DB8AF2, 0xB3441BAE, 0xD1C86629, 0x43C21F76, 0x169AE361},
	{0x83107575, 0xBF15F30B, 0xAF111A8D, 0x0E7C2CF2, 0x02D6CF7F},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4712 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4713 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4714 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5EE63035, 0xD13D6CB7, 0xFA70B8AA, 0xA02D8121, 0x07809D6A},
	{0x0B2661EC, 0xB48543D8, 0x798C5E28, 0xFDAC12D3, 0x0E8E80E4},
	0};
		static ecpoint_fp var_expected = {{0x8861BCED, 0xD0CB4E28, 0xB3AC08FA, 0xB3694FC3, 0x1253906F},
	{0x4DFB9CC9, 0xDAD32B10, 0x90413F44, 0x4CDB70DE, 0x04622D02},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4715 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4716 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4717 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x94B964D0, 0x734A4397, 0x89364023, 0xE57DE1ED, 0x02450E65},
	{0x88E025AB, 0xCC702D9F, 0x7023E5EB, 0xC60CAB92, 0x23D89FEE},
	0};
		static ecpoint_fp var_expected = {{0x38D851D7, 0xBE931FAA, 0x4CA3CB33, 0x542B32D2, 0x041F2DEB},
	{0x85F14BCC, 0xC1FFA249, 0x3E40E1A2, 0x1AEEAEC1, 0x067E08E5},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4718 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4719 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4720 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA8B2AC3F, 0xCD89FA9B, 0xABAED45B, 0x1512BF1C, 0x0E67B5A9},
	{0xB3D42BD6, 0x56C86E21, 0xD4C83213, 0x5545003B, 0x203170E3},
	0};
		static ecpoint_fp var_expected = {{0x283B0A8C, 0x949D9D09, 0xC6E4ED9C, 0x16EDDDE6, 0x073CC459},
	{0xE7EC6499, 0x52F3DB57, 0x19B3AC30, 0x8D1477E9, 0x0C4EB0C4},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4721 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4722 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4723 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x55B67CCE, 0xC399D6D1, 0x906E1308, 0xFB91D51D, 0x1E86F1FA},
	{0xC98A4D5D, 0xDBC0E7ED, 0x337C9780, 0xE61E8E01, 0x160A8701},
	0};
		static ecpoint_fp var_expected = {{0x0E26E381, 0xCE5BFB70, 0xF4FCF75E, 0xF69D4ED3, 0x081DA8D6},
	{0x47B9F790, 0x4918BCDF, 0xF42824E2, 0x6F48439D, 0x0483F232},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4724 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4725 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4726 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x12306D35, 0x9D5CE24E, 0x3D6918A0, 0x47BD3CF0, 0x08943E37},
	{0x1DBEFABC, 0xB3AE0AF0, 0xCE048AFC, 0xD30B4DA5, 0x211BB268},
	0};
		static ecpoint_fp var_expected = {{0xD2DBB6F1, 0x6E6FF224, 0x882E27EB, 0x63D8B0F1, 0x0ACAB489},
	{0x1F0312C4, 0x081BF416, 0xA5E99D38, 0xF49FCC39, 0x04E0EED7},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4727 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4728 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4729 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xEA53B7FC, 0x39DAD62E, 0x31E06E97, 0x03E79D93, 0x1F65DDFC},
	{0x68D71E90, 0x661BE931, 0xA3FAC452, 0x5038FD28, 0x06821850},
	0};
		static ecpoint_fp var_expected = {{0xF3410DF6, 0x710177CE, 0x54C9186C, 0xB9EED67F, 0x1717AC6D},
	{0x67997281, 0x2950F4A2, 0xBBA8463D, 0xB03168F0, 0x1E4CDF33},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4730 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4731 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4732 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x14EAFEB5, 0xC2D2309C, 0x847283A6, 0xEE2812A8, 0x21381C13},
	{0x4783894C, 0x40AED7A7, 0x9D3045DF, 0x3C2FDFA6, 0x1BD90A28},
	0};
		static ecpoint_fp var_expected = {{0x042F5150, 0x8531B330, 0x864F6091, 0xE0885E60, 0x19696E0D},
	{0x2122A260, 0x35D34D5C, 0x75FB3498, 0xB430D0D8, 0x03A0AB7C},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4733 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4734 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4735 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x826356B5, 0xA2FB6F04, 0x26A168F6, 0x07A14266, 0x1A24A602},
	{0xBDF1D87A, 0xA7010784, 0x05D428B4, 0x4CE2971F, 0x144032F8},
	0};
		static ecpoint_fp var_expected = {{0x15FF737B, 0x95DB7B09, 0x6FEBFBD4, 0x96B7C0BE, 0x12778DBB},
	{0x4CC00CB1, 0x236609A4, 0xAC0762FE, 0x919812B8, 0x10FFC990},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4736 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4737 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4738 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE64688AA, 0xB1E95F74, 0x04CE4CA8, 0x86AF756C, 0x07EA41C1},
	{0x4D3A4666, 0xCE87C865, 0xD366F9CA, 0x8416B464, 0x142F76C2},
	0};
		static ecpoint_fp var_expected = {{0x0F2C511C, 0xC0CB4C75, 0x96B9C348, 0xF3AF52FA, 0x09419BA7},
	{0xE0513BCA, 0x831BB27D, 0x0BEA6DD1, 0x0E136CA7, 0x1DAED86A},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4739 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4740 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4741 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x396E55C6, 0x283C6F2A, 0xB13889DB, 0xD1765DF4, 0x0A15C212},
	{0x1BF413EE, 0x921732C4, 0x2E8CE955, 0x006DFA7F, 0x1607FFCB},
	0};
		static ecpoint_fp var_expected = {{0x6694A88E, 0xE5C2839B, 0xBBDFAE2D, 0xE1B67E33, 0x038F46AD},
	{0x50CEEC41, 0xA43FF5D2, 0xD815A279, 0x508A6FFC, 0x1A40A2B1},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4742 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4743 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4744 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xAAC303ED, 0x104C8AF7, 0x2686AFF6, 0xC279B52D, 0x0D014E37},
	{0x63F92CE6, 0xF854723C, 0xC890AE43, 0xA201D72D, 0x08C0DAC2},
	0};
		static ecpoint_fp var_expected = {{0x1707C46D, 0x37ED4E10, 0x32CA9011, 0xCC3ECF90, 0x1983C84A},
	{0x26180F82, 0xC070C04A, 0xCD620B8A, 0x2586033C, 0x0A90BCE9},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4745 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4746 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4747 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x42C430E0, 0x62D10C6A, 0xFFE744DE, 0x3B3596DF, 0x23DCFD3B},
	{0x466A9C7A, 0x5DB0B27C, 0xA2E6F99E, 0x103E99A8, 0x1E177813},
	0};
		static ecpoint_fp var_expected = {{0xC0EDCBC7, 0x5C400889, 0x33563130, 0x6EB20C94, 0x238B8810},
	{0xE40F5A3A, 0x0A4E6887, 0xC16F467B, 0x7A80C622, 0x03BC45BC},
	0};
		ecfp_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_dbl_affine 4748 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_dbl_affine 4749 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_dbl_affine 4750 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x80D580D0, 0x823FE0CD, 0xA6E08C57, 0x51E47B14, 0x134B4F9B},
	{0x73B09889, 0x176A275A, 0x25F55E9C, 0xEA899F6F, 0x1A4F5D81},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x14BB2588, 0x410060D1, 0xD47E7D20, 0xF365E423, 0x0F80AE69},
	{0x424CFA82, 0x6BA5678E, 0x533C6627, 0x54D9E634, 0x1993C72E},
	{0x9B10DEB7, 0x10A6FA14, 0x129FFC9A, 0x25BCE2F8, 0x109D9B00},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4751 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4752 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4753 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4754 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5AD8F895, 0xC5A19ECD, 0xF67AAE22, 0xB19EF393, 0x15CA8A0B},
	{0x7694F493, 0x1A8B96DC, 0x27335ED5, 0xD57B2ABD, 0x0D95396C},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x136B9968, 0xBE21EF3E, 0xFB6F3819, 0xC0C5AA95, 0x23AC2BE9},
	{0x071A980C, 0xCB4212FF, 0xED36538F, 0xC1992840, 0x1968D876},
	{0xED29E926, 0x35172DB8, 0x4E66BDAA, 0xAAF6557A, 0x1B2A72D9},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4755 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4756 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4757 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4758 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x013797B6, 0xDDBD7114, 0x46FEA2E9, 0x027F4C39, 0x1A153CC1},
	{0xA850E524, 0x0690DD6E, 0x3AA2CC95, 0xA81D6561, 0x218E8EF6},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x8B3E76EC, 0xA0BEC128, 0xDE9A8DEA, 0x15007B48, 0x0714783F},
	{0x6CF71A32, 0xAD29114C, 0xBA12410C, 0xE53B9DC6, 0x04A6B4E9},
	{0x045177ED, 0xEEF4663D, 0x3BFAD88B, 0xA0E46EDC, 0x1F1BFDE9},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4759 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4760 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4761 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4762 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xC1BF1DD2, 0x9F7A75E4, 0xB6FD2E92, 0x7C84B8F8, 0x1ED0783B},
	{0xD9538A07, 0x13A1ABEE, 0xD5A99F3A, 0x7E77C0E4, 0x1E001DF4},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x00F514A6, 0x01BD328B, 0x9C141FCD, 0xEC3453F9, 0x0AE9E688},
	{0xCDF3CE5B, 0x6FC82993, 0xB254B73D, 0x3B51FFD0, 0x23E57977},
	{0x6656C1B3, 0x0916033D, 0x72087DD6, 0x4D9925E3, 0x17FF1BE5},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4763 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4764 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4765 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4766 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x4356E598, 0x0E8DDB3B, 0xFD7B0327, 0x17FD530D, 0x02C25F45},
	{0x709AF903, 0xA38B1CCA, 0x42EB7209, 0xEF64E9A7, 0x17C4597E},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xF0B6406C, 0xAA4625AB, 0xA308FBC0, 0x96C864FE, 0x1C8C8594},
	{0xA7123DBA, 0xECD96E9C, 0x7A3907DC, 0x5452E46B, 0x1B2E47A0},
	{0x94E59FAB, 0x28E8E4F4, 0x4C8C2375, 0x2F737768, 0x0B8792FA},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4767 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4768 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4769 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4770 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xF8569275, 0x30597925, 0xF2A57F9E, 0x19E7B319, 0x0669FC08},
	{0x6B8E6AA2, 0xB1AFF237, 0x85AFE944, 0x23A03BD9, 0x05C4B81C},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xECEFCFB0, 0x3B8B2135, 0x192CE67E, 0xB2A3A4B0, 0x1BF7E82E},
	{0x299406EB, 0xFB2E7059, 0x6E41C289, 0x2A6915DD, 0x0D305E18},
	{0xD71CD544, 0x635FE46E, 0x0B5FD289, 0x474077B3, 0x0B897038},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4771 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4772 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4773 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4774 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xDB88F73D, 0xBD5E18E2, 0xDCE22F15, 0x53636A8A, 0x1286CA4E},
	{0x1524F69B, 0xCDFC350E, 0xEB45EB79, 0x9B6F655E, 0x1BEEF1CE},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xE544EBC2, 0x10794A76, 0x33C36B61, 0x665C493C, 0x078520F1},
	{0xA8C2AE00, 0xA0DBFC13, 0x50A6A99E, 0xD25A52C8, 0x07DC6D07},
	{0xDDF99ADB, 0x7DCB157B, 0x9D411655, 0x87886ED7, 0x13DCC399},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4775 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4776 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4777 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4778 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x6069153D, 0x81A1622E, 0x1150EA46, 0x47095C57, 0x0CA52F41},
	{0xF6FFBCA8, 0x43882C0E, 0xE1668E2D, 0xC99DE9A8, 0x13664751},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xF06B7F4B, 0x24661552, 0xEB42EF21, 0xBA95A0DB, 0x0F26E3CE},
	{0xB6071971, 0x997D1FC3, 0x6D23C85C, 0x270C812D, 0x1265F785},
	{0xA1AF26F5, 0x68E3037D, 0x89825BBC, 0xE3E5776B, 0x02CB6E9F},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4779 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4780 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4781 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4782 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x704F9267, 0x89EFAB82, 0xA24BD52B, 0xCCBB9A3D, 0x153D4043},
	{0xDCEE380E, 0x1FD470A3, 0x87FA41C2, 0xC56389B4, 0x08894D7F},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xB4737924, 0xC05269FC, 0x7482B013, 0x984B6CAD, 0x14FCFCFC},
	{0x72F14538, 0x0D995957, 0xB725063A, 0x7425922F, 0x124A7A6E},
	{0xB9DC701C, 0x3FA8E147, 0x0FF48384, 0x8AC71369, 0x11129AFF},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4783 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4784 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4785 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4786 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x2F1BBBDC, 0xDABA7AFC, 0xB74B194A, 0x278E2829, 0x07892601},
	{0xE72D5916, 0xF80EBC98, 0x32D25641, 0x14366AAF, 0x06E6C222},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xE13A448A, 0x357A4378, 0x848F1D65, 0x167CF259, 0x1ABE9702},
	{0x228B4DA9, 0xA4483B0A, 0x0EBBB2A9, 0xCDDD3850, 0x14B374BB},
	{0xCE5AB22C, 0xF01D7931, 0x65A4AC83, 0x286CD55E, 0x0DCD8444},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4787 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4788 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4789 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4790 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x96DBD6D4, 0x43E08FCC, 0x641175FD, 0xBA58D724, 0x1BE5B847},
	{0x608F8ACA, 0xB74988A2, 0x0071AF07, 0x017E5454, 0x1EC84F16},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x1B823C14, 0x1194689C, 0x71EB712F, 0x4D57B0C4, 0x11AED220},
	{0x64EAF9BC, 0x88D6E0D9, 0x54294C2C, 0x21E69509, 0x2284C2F1},
	{0x74CEC339, 0x5065BCA4, 0xC7989D71, 0x53A64CC1, 0x198F7E28},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4791 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4792 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4793 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4794 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x1F902262, 0x2B7EAC7B, 0xB49AA811, 0x15659560, 0x15A4EEA8},
	{0x4114A500, 0xA36E8385, 0x4DF1E095, 0x2046407E, 0x08AD22A2},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x5ED1179C, 0x21FE94EB, 0xFC5E560C, 0x2C772AE0, 0x1B54B509},
	{0xF2FB2BA2, 0x9F17AEB9, 0xF4EC8B45, 0xEAFDD5A2, 0x027105B0},
	{0x82294A00, 0x46DD070A, 0x9BE3C12B, 0x408C80FC, 0x115A4544},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4795 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4796 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4797 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4798 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x80805085, 0x84A53437, 0x59ACDC77, 0xE0FEBC9C, 0x00B93D2A},
	{0x1467E9BF, 0xC66E0805, 0x8B591C48, 0x8F45EDC4, 0x15966232},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x8C11EEE4, 0x59F771B5, 0x13C0CBAF, 0xEF852A97, 0x22B9A08D},
	{0xF25796F9, 0x6B8BDFF3, 0x97FC45AC, 0x48CDA37F, 0x015B321F},
	{0xDC7F8123, 0x6EAEBB69, 0xDD6777F3, 0x6F357FA2, 0x072BA461},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4799 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4800 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4801 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4802 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x7296B63E, 0x76195444, 0x23A67782, 0x86721F34, 0x18421231},
	{0x31051DA2, 0x431BFAB9, 0x268C9F38, 0x61588052, 0x14F6C4BE},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x73624F60, 0x7A2697EC, 0x00DBF465, 0x60B9FA0F, 0x16C2C2CE},
	{0x32A53893, 0xF499E383, 0xBF1739D6, 0x98FF80B0, 0x2189B082},
	{0x15B9E8E9, 0x680AA0D2, 0x13CE7DD2, 0x135AA4BE, 0x05EC6979},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4803 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4804 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4805 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4806 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x6164DBC2, 0x51ACA552, 0x9D94CC61, 0x4EED47AC, 0x08666412},
	{0x9E87F99A, 0x7CF98A0C, 0x119A43FA, 0x3F992A43, 0x14506CE8},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0x1158BD1A, 0xA1FC92AA, 0x61484137, 0x2C268BB3, 0x1C83816F},
	{0x198661E5, 0x2BE715D3, 0xB8825F53, 0x8D9C6324, 0x03E59A86},
	{0xF0BFA0D9, 0xDBC5BF78, 0xE9E9C756, 0xCFDBF89F, 0x049FB9CC},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4807 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4808 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4809 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4810 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x13462197, 0xEC2961B6, 0x47EC9BFE, 0xC4A833A7, 0x12AF86E4},
	{0xDA5248F3, 0x50D9F211, 0xB32F2789, 0x01880C0A, 0x109F60C1},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static ecpoint_fp_proj var_expected = {{0xA2F05CA6, 0x72855576, 0xE6ED6780, 0xFEB311A3, 0x042AA3E0},
	{0xEA363923, 0xC550CF00, 0x2BCD9794, 0xE9D1935E, 0x11917A62},
	{0xB4A491E6, 0xA1B3E423, 0x665E4F12, 0x03101815, 0x213EC182},
	0};
		ecfp_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x, var_res_proj.x, "ecfp_dbl_proj 4811 a.x");
		assert_bi_equal(var_expected.y, var_res_proj.y, "ecfp_dbl_proj 4812 a.y");
		assert_bi_equal(var_expected.z, var_res_proj.z, "ecfp_dbl_proj 4813 a.z");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp_dbl_proj 4814 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA964FAFB, 0x7FA44F06, 0xF92E9FDE, 0xFE0729A6, 0x0CE230FB},
	{0x0FB1AF89, 0xEAE58653, 0xF9F05C8C, 0xB42AAC04, 0x16AE621F},
	0};
		static ecpoint_fp var_expected = {{0xA964FAFB, 0x7FA44F06, 0xF92E9FDE, 0xFE0729A6, 0x0CE230FB},
	{0x3C9EA2D2, 0x3347CE4D, 0x3F5A6411, 0xFB2BAFE1, 0x0D52BDE3},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4815 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4816 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4817 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xA8751EA4, 0xE9846003, 0xA10825FF, 0xFC355CF8, 0x0FEC0AE6},
	{0xA8AB6338, 0x093E8523, 0xC79D9F48, 0x6E749D04, 0x045C0B55},
	0};
		static ecpoint_fp var_expected = {{0xA8751EA4, 0xE9846003, 0xA10825FF, 0xFC355CF8, 0x0FEC0AE6},
	{0xA3A4EF23, 0x14EECF7C, 0x71AD2156, 0x40E1BEE1, 0x1FA514AE},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4818 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4819 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4820 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x82D58420, 0x5863B5A0, 0xB7C339B3, 0x334E1D95, 0x073CC6DE},
	{0x78CE6E18, 0x4028856A, 0xA5054A63, 0x88F28C8E, 0x12EB8E7A},
	0};
		static ecpoint_fp var_expected = {{0x82D58420, 0x5863B5A0, 0xB7C339B3, 0x334E1D95, 0x073CC6DE},
	{0xD381E443, 0xDE04CF35, 0x9445763A, 0x2663CF57, 0x11159189},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4821 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4822 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4823 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x4E7CD4EB, 0x6A14DFE7, 0xE151EEDF, 0x4A539E5A, 0x2271A956},
	{0xD46E0CCC, 0x0CBEE2A2, 0x7569508D, 0x709E9B8E, 0x1A06F48F},
	0};
		static ecpoint_fp var_expected = {{0x4E7CD4EB, 0x6A14DFE7, 0xE151EEDF, 0x4A539E5A, 0x2271A956},
	{0x77E2458F, 0x116E71FD, 0xC3E17011, 0x3EB7C057, 0x09FA2B74},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4824 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4825 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4826 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2B7D7D3B, 0x44A01282, 0xC88E0721, 0xD1AE62D6, 0x0AF32392},
	{0x649507E4, 0x69F82478, 0xB236F4E6, 0x7098AE9B, 0x0168FB84},
	0};
		static ecpoint_fp var_expected = {{0x2B7D7D3B, 0x44A01282, 0xC88E0721, 0xD1AE62D6, 0x0AF32392},
	{0xE7BB4A77, 0xB4353027, 0x8713CBB7, 0x3EBDAD4A, 0x2298247F},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4827 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4828 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4829 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xD540E37C, 0x87336BC9, 0x43A41312, 0x93FD6B17, 0x1909573D},
	{0x79AB62ED, 0x648B365E, 0xDFD82B69, 0x90B31CB9, 0x08965DDF},
	0};
		static ecpoint_fp var_expected = {{0xD540E37C, 0x87336BC9, 0x43A41312, 0x93FD6B17, 0x1909573D},
	{0xD2A4EF6E, 0xB9A21E41, 0x59729534, 0x1EA33F2C, 0x1B6AC224},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4830 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4831 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4832 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x91729920, 0xFF0F401F, 0x4ADF4F80, 0x5D914366, 0x031655E0},
	{0x6023ABF8, 0x68374485, 0xB44D638C, 0xD563A5BA, 0x00A402AF},
	0};
		static ecpoint_fp var_expected = {{0x91729920, 0xFF0F401F, 0x4ADF4F80, 0x5D914366, 0x031655E0},
	{0xEC2CA663, 0xB5F6101A, 0x84FD5D11, 0xD9F2B62B, 0x235D1D53},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4833 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4834 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4835 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x81AB2B8E, 0x3FDFB3F9, 0x61B9C476, 0x5A346718, 0x1CE958EB},
	{0x3BFA4113, 0x4D836ECA, 0x0901E27D, 0x0276A1A7, 0x05699B72},
	0};
		static ecpoint_fp var_expected = {{0x81AB2B8E, 0x3FDFB3F9, 0x61B9C476, 0x5A346718, 0x1CE958EB},
	{0x10561148, 0xD0A9E5D6, 0x3048DE20, 0xACDFBA3F, 0x1E978491},
	0};
		ecfp_neg_affine(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_affine 4836 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_affine 4837 a.y");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_affine 4838 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x985BBEAF, 0x949EFCEB, 0x3927D3CD, 0x952EB09E, 0x0750BDFF},
	{0xFCFE9575, 0xAEFBDAD2, 0x7F13DDF2, 0x1C15AA4C, 0x06D77EEF},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x985BBEAF, 0x949EFCEB, 0x3927D3CD, 0x952EB09E, 0x0750BDFF},
	{0x4F51BCE6, 0x6F3179CD, 0xBA36E2AB, 0x9340B199, 0x1D29A114},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4839 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4840 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4841 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4842 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xDC613352, 0xAFF9D346, 0x7DB17B75, 0x889652F1, 0x1B103008},
	{0x2CEB569E, 0xA32153A4, 0x960C0637, 0xBE2B67D3, 0x114F0FE2},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xDC613352, 0xAFF9D346, 0x7DB17B75, 0x889652F1, 0x1B103008},
	{0x1F64FBBD, 0x7B0C00FC, 0xA33EBA66, 0xF12AF412, 0x12B21020},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4843 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4844 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4845 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4846 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x493BD6CD, 0xDEC197B4, 0xF30D5B42, 0x63EC4DF1, 0x199E2625},
	{0xB65B1B87, 0x4B386F9B, 0x816D76E6, 0x7D0F3495, 0x06B7721B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x493BD6CD, 0xDEC197B4, 0xF30D5B42, 0x63EC4DF1, 0x199E2625},
	{0x95F536D4, 0xD2F4E504, 0xB7DD49B7, 0x32472750, 0x1D49ADE8},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4847 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4848 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4849 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4850 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x179EBE5F, 0x6A26AA6B, 0xBE0BC98C, 0xE81097DE, 0x189F596B},
	{0x1CAABC3A, 0xCFDD8A45, 0xECA33880, 0x5F494E67, 0x1886B85C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x179EBE5F, 0x6A26AA6B, 0xBE0BC98C, 0xE81097DE, 0x189F596B},
	{0x2FA59621, 0x4E4FCA5B, 0x4CA7881D, 0x500D0D7E, 0x0B7A67A7},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4851 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4852 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4853 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4854 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xAC29EE71, 0xC5AD54E0, 0x2F4AA968, 0xBBD143B7, 0x22DF92D5},
	{0xBC502D84, 0x3BCCEC24, 0xB956C9A3, 0xA0E8CAF3, 0x03F2D889},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xAC29EE71, 0xC5AD54E0, 0x2F4AA968, 0xBBD143B7, 0x22DF92D5},
	{0x900024D7, 0xE260687B, 0x7FF3F6FA, 0x0E6D90F2, 0x200E477A},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4855 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4856 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4857 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4858 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0xDF7E4E1E, 0x70B725CA, 0xEB0FDBEF, 0xAD756B34, 0x17445181},
	{0x8B5BA5C8, 0x328BCE58, 0x3BD6D6BA, 0x75C5255F, 0x07BDC1C7},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0xDF7E4E1E, 0x70B725CA, 0xEB0FDBEF, 0xAD756B34, 0x17445181},
	{0xC0F4AC93, 0xEBA18647, 0xFD73E9E3, 0x39913686, 0x1C435E3C},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4859 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4860 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4861 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4862 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5BEB636B, 0xFAE0A716, 0xC3BACBF5, 0x0B3DE1EF, 0x0817F68E},
	{0x76868DA0, 0x00FF3129, 0x02BD1EF2, 0x274F9ED2, 0x0FCE949B},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x5BEB636B, 0xFAE0A716, 0xC3BACBF5, 0x0B3DE1EF, 0x0817F68E},
	{0xD5C9C4BB, 0x1D2E2376, 0x368DA1AC, 0x8806BD14, 0x14328B68},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4863 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4864 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4865 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4866 infinity");
	}
	{
		static ecpoint_fp_proj var_a = {{0x5D77E8E6, 0x17173865, 0x0D0C6C7C, 0xF0414B67, 0x1692FB00},
	{0xA52CECA6, 0x56E24593, 0x8DEF5E72, 0x4805ECC5, 0x02015263},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		static ecpoint_fp_proj var_expected = {{0x5D77E8E6, 0x17173865, 0x0D0C6C7C, 0xF0414B67, 0x1692FB00},
	{0xA72365B5, 0xC74B0F0C, 0xAB5B622B, 0x67506F20, 0x21FFCDA0},
	{0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	0};
		ecfp_neg_proj(&var_a);
		assert_bi_equal(var_expected.x, var_a.x, "ecfp_neg_proj 4867 a.x");
		assert_bi_equal(var_expected.y, var_a.y, "ecfp_neg_proj 4868 a.y");
		assert_bi_equal(var_expected.z, var_a.z, "ecfp_neg_proj 4869 a.z");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp_neg_proj 4870 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4871 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4872 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4873 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x0E965956, 0x76B01537, 0x493D6D78, 0x73E13B05, 0x07DE3F91},
	{0x141496C0, 0x8B552813, 0x52B02787, 0xD596F98E, 0x204800EB},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4874 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4875 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4876 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x017D0CC0, 0xFF8FA61A, 0x1C15C81F, 0xB89E1282, 0x01DB55E4},
	{0x414A1CDD, 0x73255D09, 0x8C9EFFDD, 0xE1C22136, 0x0B7CC37B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4877 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4878 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4879 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x349B1BD2, 0xFA88436D, 0x18BA48AD, 0x59B28289, 0x1DCCB45F},
	{0xD6990ED2, 0x65DEED8F, 0x1EBECA5C, 0xDA6EFF35, 0x16AFCE98},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4880 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4881 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4882 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp var_expected = {{0x60F97B7A, 0x6E9C238E, 0x2B51DFB6, 0xE4FAB8D5, 0x13558169},
	{0xEF9C5717, 0xF2DACA50, 0x629ABF4C, 0x9B912A50, 0x22C4C2B7},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4883 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4884 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4885 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x01B82898, 0x1DBA695A, 0x5B6B1754, 0x2FE4F0FE, 0x0B25B91D},
	{0x842E376C, 0x3417FA2D, 0x41062EB1, 0x556CA058, 0x08D1CDCA},
	0};
		static bigint_t var_k = {0xB55565B2, 0xE915D896, 0x8071688A, 0x6D420E35, 0x09B7830C};
		static ecpoint_fp var_expected = {{0x3B2E30DE, 0x94CB12DC, 0x6E0964FB, 0x31482A5C, 0x0D3D6BF9},
	{0x88741CC9, 0x8221F800, 0xC4F55D15, 0xFF3FADA6, 0x03DAD365},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4886 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4887 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4888 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE6F62F61, 0xF4B9DF3C, 0x5CCFE8A8, 0x8DD7C4D1, 0x02C2EAA8},
	{0x4F9F22E4, 0xEA296ABD, 0x7AC9950B, 0x8E858A25, 0x02B2DC23},
	0};
		static bigint_t var_k = {0xA9D3EB7A, 0xD51BED5A, 0xE19293B5, 0x1B06061B, 0x014481A4};
		static ecpoint_fp var_expected = {{0x8B1F17DD, 0xDE39EE7B, 0x341CBEC1, 0xB8A15D18, 0x126D41C7},
	{0xB0C43C1F, 0xA444CD68, 0xBFDE7A53, 0x7FB7FAF2, 0x1570D52B},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4889 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4890 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4891 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2088FA66, 0x7940A103, 0x54074CEB, 0x5EB35C6A, 0x0EEB3871},
	{0xB10EEAE0, 0x268417F8, 0xFF946B55, 0xEE1DBA6E, 0x21D11665},
	0};
		static bigint_t var_k = {0x4F5AE889, 0xAB6AAD9E, 0x78EA2BED, 0xD9A08C6E, 0x051DA2DF};
		static ecpoint_fp var_expected = {{0x4F99E092, 0x597DB91B, 0xE10359B5, 0xD831FED3, 0x1BA83EC8},
	{0xBB759431, 0xBABC8A9B, 0x0022876F, 0xC81F5F4E, 0x0325BB37},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4892 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4893 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4894 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8925A3F8, 0x0B9FA060, 0xFAE5F8F0, 0x155B13BA, 0x1E0CE3E6},
	{0x989046AA, 0x368CEE57, 0xC00D2251, 0x38851D19, 0x1C1A7E24},
	0};
		static bigint_t var_k = {0x1B9E6637, 0xB9A30E15, 0xC29A2DF2, 0x460D68B2, 0x12B8F411};
		static ecpoint_fp var_expected = {{0x74C5F30C, 0x5937E5B7, 0x0AD68298, 0xAD62080C, 0x23891058},
	{0x36471CE4, 0x001CB2EB, 0xFA35B1F3, 0xAEACFF09, 0x2168F28C},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4895 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4896 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4897 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x9D1119A8, 0xC873346F, 0x604073FD, 0xCFDE6410, 0x0428BF61},
	{0x81AB887B, 0x12BE7F88, 0x52727CB8, 0x0E276296, 0x17C86EE4},
	0};
		static bigint_t var_k = {0x0A0F0269, 0xAFC5565F, 0xEE5DE810, 0x2465AB45, 0x22CAC226};
		static ecpoint_fp var_expected = {{0x238E32A7, 0xADEFA35A, 0x537C6758, 0x242188B7, 0x159DED54},
	{0xECEFA357, 0x4FCC427B, 0x6C1CF61C, 0xE8E53670, 0x1ACCC2F9},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4898 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4899 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4900 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5713DCCC, 0x88C7A6E0, 0x120D4758, 0x619B2260, 0x034B3D66},
	{0x9C86D82F, 0x851126D4, 0x2EC077E5, 0xC6B9BFCC, 0x18F7D70D},
	0};
		static bigint_t var_k = {0x53EAE0FE, 0x3F62CB24, 0x6703B6C1, 0x5D3886A9, 0x12CD6D2E};
		static ecpoint_fp var_expected = {{0xD853994F, 0x90F71DBF, 0x3EAF595B, 0x1FBAA53C, 0x1BB50B81},
	{0x1FA5AC34, 0xC8D42526, 0x7732BB03, 0x8ADF13C3, 0x1958356F},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4901 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4902 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4903 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xB7044C1F, 0xE2D82676, 0xB5D5783A, 0x833FC6DC, 0x182AFB89},
	{0xF3C9EDF0, 0x6B14162E, 0xE055547E, 0xCE819638, 0x1A15B72B},
	0};
		static bigint_t var_k = {0x59B7CD9C, 0x36A0CEF9, 0xB64EF603, 0x770DB984, 0x0B634075};
		static ecpoint_fp var_expected = {{0x4CC7A87B, 0xE109A656, 0x11E73244, 0xC50C4D96, 0x1A9B4168},
	{0xF39560D7, 0x1A9B9325, 0x62C9C5C3, 0xDE9C4FA1, 0x0FF9F3A2},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4904 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4905 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4906 infinity");
	}
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
	{
		static ecpoint_fp var_a = {{0x00B7B9F3, 0xEF5A58C1, 0x8EBB2B23, 0xB97ADE18, 0x10C7C306},
	{0x36FFC116, 0xEB043456, 0x85A6C7F3, 0x2B97371E, 0x09939F22},
	0};
		static bigint_t var_k = {0x607DA3FC, 0xD757621E, 0xE2B3935C, 0x4D7C7E30, 0x058B1256};
		static ecpoint_fp var_expected = {{0xBF2E2626, 0xCF8702B1, 0x0EA6AC33, 0xF40CBAF5, 0x1FED0193},
	{0x775DA5B7, 0x518BCC82, 0xC5BBE95A, 0xA27D383B, 0x237072DF},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4910 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4911 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4912 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2A05D464, 0x9930203E, 0xF17B959F, 0x469B57BD, 0x0A43B2B7},
	{0xE0FEEC0C, 0x4BE75818, 0x98249A2F, 0x4F24E8D3, 0x0AF0C9CF},
	0};
		static bigint_t var_k = {0x74B68993, 0xFD032AC0, 0x0937F685, 0x78D450D0, 0x02E47FA6};
		static ecpoint_fp var_expected = {{0x2C104A73, 0x2B8F30F2, 0xA187DC48, 0xE2EFF257, 0x024B8912},
	{0x80D8512C, 0x7B54D998, 0x797787B7, 0xFAD9868A, 0x0C7AFCB8},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4913 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4914 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4915 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x5B703469, 0x00D34F0C, 0x5322DFD2, 0xCF05EDC1, 0x0E75EC9A},
	{0xB6477B37, 0x9AB38952, 0xE4D1913F, 0x889AEF6E, 0x008A9CAB},
	0};
		static bigint_t var_k = {0xAC54FF87, 0xC07E0800, 0xDDA8C9DB, 0x498C43A0, 0x0266989E};
		static ecpoint_fp var_expected = {{0xA080B9B5, 0x3F098E93, 0xA674B6C3, 0xDFD9944D, 0x0FDFD579},
	{0xE7E73750, 0x6F16D514, 0x563D72CA, 0x17740BB8, 0x166C4FCA},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4916 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4917 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4918 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xE029585A, 0xADF13BDE, 0xA9697F12, 0xDF801684, 0x02FA86D0},
	{0xC65E94B3, 0xF9D6E8D9, 0x812AB1F0, 0x48684273, 0x192F6260},
	0};
		static bigint_t var_k = {0x5DE272AE, 0x99EDDC58, 0x185EF2B8, 0xDA6546DC, 0x132028C6};
		static ecpoint_fp var_expected = {{0x6688DE9E, 0x63273D50, 0x548A5CC3, 0xC943C8B5, 0x0A1D2A26},
	{0x49F30C5E, 0x58710E28, 0xCEC30D3A, 0xED7BAB91, 0x1D1852D6},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4919 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4920 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4921 infinity");
	}
	{
		static ecpoint_fp var_a = {{0xDE271EDA, 0x83B26A41, 0x3B663572, 0xDA42AE64, 0x0749C12C},
	{0x174DEA3E, 0xD604E61A, 0xFDAD5779, 0x4EDEAC83, 0x195981DF},
	0};
		static bigint_t var_k = {0x1CAD64F3, 0xA5F73750, 0xB22AFC1A, 0x0D2C9049, 0x05B80860};
		static ecpoint_fp var_expected = {{0xB57430A1, 0xA9F5624A, 0x7B75CD2C, 0x0AF57B32, 0x05C8F942},
	{0x97830F6D, 0xFF64E583, 0xC4CE4774, 0xC2838925, 0x153B092D},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4922 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4923 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4924 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x2A239A1D, 0x972D8A95, 0x0DD2D79D, 0xDDE7ADD9, 0x194A95BA},
	{0x452F61A4, 0x9AF8AC22, 0xADC01550, 0x40D428E7, 0x01DE120D},
	0};
		static bigint_t var_k = {0xD45C7D84, 0x890A9169, 0x9581254A, 0x85032647, 0x1DABFA9D};
		static ecpoint_fp var_expected = {{0x096FCFD6, 0x56B0357D, 0x5D799A5E, 0xFDBE74A7, 0x11AB9C4B},
	{0x123C94AB, 0x8F8398CC, 0x51B417B6, 0x3125420C, 0x2231AEA9},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4925 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4926 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4927 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x8EBA8AD8, 0x4EC897C3, 0xEF4ECC8E, 0xF66DF8B3, 0x00EE25F5},
	{0xF3617F1C, 0x957A2E35, 0xE9CC547E, 0x3941455D, 0x1EAA78AC},
	0};
		static bigint_t var_k = {0xE8724D71, 0x70EAB8AD, 0x70CD8750, 0x04FC35F5, 0x17D775DD};
		static ecpoint_fp var_expected = {{0xA95BED50, 0x1B72B187, 0x90793DD2, 0xB8704CC5, 0x1CCDE8E8},
	{0x27EEA9CD, 0x9A6D2E62, 0x95B02BEE, 0x89D24F06, 0x04119517},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4928 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4929 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4930 infinity");
	}
	{
		static ecpoint_fp var_a = {{0x02A99256, 0x2F8D1352, 0x792DD8DA, 0x0319865D, 0x126E9F27},
	{0x70C6F293, 0x907B16AD, 0x7666662E, 0x15153595, 0x1066FE72},
	0};
		static bigint_t var_k = {0x693CA13E, 0xE91272D3, 0xA8A750BD, 0xA0167791, 0x1780CF15};
		static ecpoint_fp var_expected = {{0xE652988A, 0x02B00F81, 0x5F3AEDA7, 0x58D76ACC, 0x15F39B4C},
	{0x3ED44E92, 0xD2A021BF, 0x5FE7EF0F, 0x13EE2800, 0x03002372},
	0};
		ecfp_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_mul 4931 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_mul 4932 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_mul 4933 infinity");
	}
	{
		static const bigint_t var_t = {0xB8E7A221, 0xCB666AA3, 0x8226627C, 0x5E26722B, 0x05BFC8ED};
		static ecpoint_fp var_expected = {{0x2F49594E, 0xB6D176DC, 0x1DE8D5C6, 0x5F38FFED, 0x141C9ACE},
	{0x67F37A32, 0xF8AFB36A, 0x0677998D, 0xA3FD0B2B, 0x00A93C75},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4934 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4935 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4936 infinity");
	}
	{
		static const bigint_t var_t = {0xA2F70F2D, 0x1C0FD833, 0x6ED7F47A, 0x4375E55E, 0x088BFA5F};
		static ecpoint_fp var_expected = {{0xC0221B0E, 0xBE2D1DF4, 0xBF43CCF3, 0xDFCC8F30, 0x23115127},
	{0xE47ED3B3, 0x2F2B3397, 0x6305103C, 0xF5886C55, 0x0F46C01E},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4937 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4938 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4939 infinity");
	}
	{
		static const bigint_t var_t = {0x1D37CEC4, 0xFBBC096A, 0x8D264CD9, 0xFC38BAFF, 0x1AEBAA70};
		static ecpoint_fp var_expected = {{0x5978ECB8, 0xF3106089, 0x76312B48, 0x65209DBF, 0x2003945F},
	{0x22336652, 0xF75ED622, 0x1213397F, 0xCCA13C49, 0x00F9FB78},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4940 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4941 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4942 infinity");
	}
	{
		static const bigint_t var_t = {0x120D4691, 0x026B6FDF, 0x6F172E1B, 0x5167DFF9, 0x0080120D};
		static ecpoint_fp var_expected = {{0x1D903EA1, 0x6C93AAF9, 0x1742DFA0, 0x5117C619, 0x03E7F1B9},
	{0xD969B6EB, 0xED138024, 0x7300BFE7, 0xC4A9C08C, 0x195F9007},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4943 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4944 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4945 infinity");
	}
	{
		static const bigint_t var_t = {0x91CE50C2, 0x73E6628D, 0x5FA04A00, 0x5B27347E, 0x13BB6F35};
		static ecpoint_fp var_expected = {{0x1332DD60, 0xD2B73F0C, 0xB677EE1A, 0x0E5E82FC, 0x1D4D51C4},
	{0x68A5B7A9, 0x9A60A172, 0xB6535451, 0x53CA299C, 0x221E6886},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4946 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4947 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4948 infinity");
	}
	{
		static const bigint_t var_t = {0x2CFFC7B8, 0x25B71D94, 0xAD316C36, 0x5719A8E7, 0x2330E00A};
		static ecpoint_fp var_expected = {{0xC9B3B99F, 0xDF699B1B, 0x2F920BB2, 0x4F153E7A, 0x23007BD8},
	{0xD4D4F7D9, 0x5B8EBAB3, 0xCC928669, 0x95ACF4BE, 0x1EFD556A},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4949 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4950 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4951 infinity");
	}
	{
		static const bigint_t var_t = {0xEF61796C, 0xA8AA833B, 0xD7F86E99, 0x523A40D8, 0x23566A1A};
		static ecpoint_fp var_expected = {{0xDACFEEA4, 0x06EB3131, 0xD7F32746, 0xEB492D13, 0x156049E2},
	{0x122D37CF, 0xEE0E9107, 0xA90D762D, 0x61A2E0ED, 0x0DA827AA},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4952 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4953 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4954 infinity");
	}
	{
		static const bigint_t var_t = {0xD086D4B7, 0x7312BF56, 0x466EAC2D, 0xD81E84F2, 0x18C155EE};
		static ecpoint_fp var_expected = {{0x5E65FE75, 0xFBBAD7E3, 0x9456C120, 0xCF231A77, 0x1196F520},
	{0xC03E1E26, 0xE3986AFB, 0xEE95C6C7, 0x70843CE3, 0x135BC2A0},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4955 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4956 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4957 infinity");
	}
	{
		static const bigint_t var_t = {0xE9616B90, 0x39C11695, 0x1E11D928, 0x315BD6E6, 0x21A74C1B};
		static ecpoint_fp var_expected = {{0x00618537, 0x1A788C52, 0x5A560268, 0x611ACE09, 0x1F489A1C},
	{0x8EF80CEB, 0x34C15D29, 0x021E702B, 0xFC6C7217, 0x1644375E},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4958 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4959 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4960 infinity");
	}
	{
		static const bigint_t var_t = {0xDE4526FD, 0x7E9E93B7, 0xA3C42F71, 0x50E16D7B, 0x21E3A785};
		static ecpoint_fp var_expected = {{0x9CEB804A, 0xFD114919, 0xCC3A3B51, 0x73E257DD, 0x1E5D7967},
	{0xEDC3FF10, 0x20E533CF, 0xA64EE5CD, 0xEC90F555, 0x0C05311D},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4961 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4962 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4963 infinity");
	}
	{
		static const bigint_t var_t = {0x3DDA2FAF, 0x1F1F5D13, 0x0B6A4B26, 0xB1F0649F, 0x02B87DBE};
		static ecpoint_fp var_expected = {{0xB196548A, 0x4592A295, 0xEBB2CDDC, 0x73C3C913, 0x120FB191},
	{0xEF8AE9EE, 0x6750C437, 0xFC2E4DD7, 0x0B2CD2E2, 0x184628CE},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4964 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4965 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4966 infinity");
	}
	{
		static const bigint_t var_t = {0xCC144085, 0xCA04F1A8, 0xA9C7C999, 0x5CBC03AE, 0x1EA34F9D};
		static ecpoint_fp var_expected = {{0x768E0C2B, 0x1A235B42, 0x3D73D48A, 0x6D294C97, 0x1AA81B64},
	{0x25381B59, 0xE55F1090, 0xAB461D3A, 0xA0DB98CF, 0x1C609344},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4967 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4968 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4969 infinity");
	}
	{
		static const bigint_t var_t = {0x9041783D, 0xB099E5F9, 0x243E62AB, 0xD5201368, 0x13031F90};
		static ecpoint_fp var_expected = {{0x61D084A3, 0x78D1C5FE, 0xE18EB627, 0x7955B3ED, 0x0685524F},
	{0xA5CE9784, 0xB13AE009, 0x0D230826, 0x05064971, 0x0BC1A1D5},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4970 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4971 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4972 infinity");
	}
	{
		static const bigint_t var_t = {0x4A0CC7B5, 0x4B5184CF, 0x8809150A, 0xB5D58A8D, 0x21F01A85};
		static ecpoint_fp var_expected = {{0xBCE6BD64, 0x48EC8635, 0xFD0E6671, 0xFA9E60E2, 0x03ED83B4},
	{0xBD7B1F0E, 0xF346D1AC, 0xD1D0B34E, 0x280BC325, 0x0D731828},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4973 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4974 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4975 infinity");
	}
	{
		static const bigint_t var_t = {0xD785ED5D, 0x814A7ED6, 0x8350BC3D, 0x8B6A1D1C, 0x09DDA268};
		static ecpoint_fp var_expected = {{0x47E51C42, 0xAB0B0CE2, 0x2076418C, 0x82432B90, 0x11C3815C},
	{0xEF3036C7, 0x315C55AE, 0x9F523736, 0x611C7A4B, 0x0FB9473E},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4976 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4977 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4978 infinity");
	}
	{
		static const bigint_t var_t = {0xCA8423AC, 0xCA3BA5D0, 0x2525CE03, 0x6A6F5D16, 0x1EBD0AD3};
		static ecpoint_fp var_expected = {{0x7F05714D, 0x7849EC38, 0x7116E055, 0xAE1372D6, 0x1814B052},
	{0x1E29A850, 0xF73999AC, 0xC4A5E3B3, 0x5B6919D3, 0x1B4210F3},
	0};
		ecfp_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x, var_res.x, "ecfp_hash_to_point 4979 a.x");
		assert_bi_equal(var_expected.y, var_res.y, "ecfp_hash_to_point 4980 a.y");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp_hash_to_point 4981 infinity");
	}
#endif
#endif
	return 0;
}
