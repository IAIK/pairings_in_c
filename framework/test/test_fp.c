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
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 197 ");
	}
	{
		static const bigint_t var_a = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_expected = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 198 ");
	}
	{
		static const bigint_t var_a = {0xB184E14D, 0x1C7D94EE, 0xB83B9590, 0x968672DC, 0x5B8696C8, 0xD7802006, 0x09822701, 0xA4721CD9};
		static const bigint_t var_expected = {0x2F72023E, 0x31C22856, 0x01A5EB68, 0xCC6A4DAF, 0xE38858E4, 0x5884F25A, 0x95205D24, 0x65ED97E8};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 199 ");
	}
	{
		static const bigint_t var_a = {0x693BA239, 0x1391D11D, 0xF2B1D5E7, 0x1C955D55, 0xB886E9AA, 0xAAAF93C4, 0xF91EEC07, 0x544465A4};
		static const bigint_t var_expected = {0xEE6E9C54, 0xEF3805EF, 0x577DAB00, 0x7FE555E0, 0x9A9C761C, 0xFFDD046A, 0x9692AC07, 0x75613D61};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 200 ");
	}
	{
		static const bigint_t var_a = {0x417EE5FB, 0xA33F87D1, 0x7863A440, 0x318F82BB, 0xDB7045F5, 0xFBC6D425, 0xB6B2E6E0, 0xA24C53F9};
		static const bigint_t var_expected = {0x40F516A3, 0xE89E6223, 0xB15468C3, 0x50C6570C, 0x7489183F, 0x5395667A, 0x754F90AC, 0x26552593};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 201 ");
	}
	{
		static const bigint_t var_a = {0x275A2D3B, 0x7BEFDC48, 0x1E06FB17, 0x417DD202, 0x5F090945, 0xC571A4B7, 0x05170281, 0x8B2B2DDB};
		static const bigint_t var_expected = {0xE1411252, 0x7C1181A4, 0x0B3C9592, 0xC5353B45, 0xF9D57EFA, 0x2AD2EE77, 0xCA8DE0A6, 0x51697AF8};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 202 ");
	}
	{
		static const bigint_t var_a = {0xB1F9F7E7, 0xF2224BF4, 0x07C8B5C7, 0x91E8D5E5, 0x71111752, 0xA875DC71, 0x00F11935, 0x52E66BD7};
		static const bigint_t var_expected = {0xBDE00575, 0x967618B4, 0xA983B2DE, 0x40BB4C13, 0x20E154FD, 0x1D3493C2, 0x6049C287, 0x472F3DD2};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 203 ");
	}
	{
		static const bigint_t var_a = {0x5E509F80, 0xD5BC3AA4, 0x79874A53, 0x5E9DA4C0, 0x068A088B, 0x934500B9, 0x8F08F6F2, 0x46C00141};
		static const bigint_t var_expected = {0xAD33934B, 0x423DE8BD, 0xF732AA4F, 0xF9BC91EC, 0x6CCE5793, 0x61995BC4, 0x93B92DA0, 0x92F9D95B};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 204 ");
	}
	{
		static const bigint_t var_a = {0xCE707AB8, 0xDA3DA47F, 0xAAF94190, 0x87664EDC, 0xC324E72E, 0x1EED7F07, 0xA95CB198, 0x865366B7};
		static const bigint_t var_expected = {0xE8D5CA82, 0xB7468FCB, 0x712CBAA5, 0xD81AB18E, 0x41F15753, 0x92B07B32, 0x2CB6AF73, 0x822F8C39};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 205 ");
	}
	{
		static const bigint_t var_a = {0x516055CA, 0xF7815AC4, 0x79DD557D, 0x2DD97976, 0x2C5DA9B1, 0x6AEB22EC, 0x3A54C061, 0x740AB0A5};
		static const bigint_t var_expected = {0xB13717CB, 0x121FD2F4, 0x8FFEF949, 0x2A0C3565, 0x00F86092, 0xBB1F92FD, 0x9517E396, 0x9753F3A6};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 206 ");
	}
	{
		static const bigint_t var_a = {0x912EFE29, 0x723D55BF, 0x5C3E6F5C, 0x6CF8ACE3, 0x42FF8B5E, 0x3A222074, 0x898E5E5F, 0x7E6E65E4};
		static const bigint_t var_expected = {0xA3D7CF25, 0x7995943A, 0x5BA82F01, 0xFA989680, 0xFBD0D420, 0x96D9CBC2, 0x2D47C100, 0x6527FCE0};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 207 ");
	}
	{
		static const bigint_t var_a = {0xA6F72070, 0xBD22544E, 0xF966C8BB, 0xFE1B2B28, 0x8123F47D, 0x5A00767C, 0xE7E5705F, 0x657A4EEA};
		static const bigint_t var_expected = {0x19AF0331, 0x90682801, 0x074A13B3, 0x7D1C21C0, 0xA13C9A4E, 0x1567A6A6, 0x89F79421, 0x1FC0CB7D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 208 ");
	}
	{
		static const bigint_t var_a = {0x131B46BC, 0xCB547F50, 0x56C2EB0E, 0x8B41FD26, 0xD626D742, 0xE589C9E7, 0x44D715B0, 0x98F7336F};
		static const bigint_t var_expected = {0xE1CAAF6B, 0xB822C067, 0xF981D5B8, 0xED91C9A1, 0xE9D73CE5, 0xD642C3B3, 0xC484B599, 0x0494A1E8};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 209 ");
	}
	{
		static const bigint_t var_a = {0x71311353, 0xF4B064F1, 0x4DA1FD86, 0xC106D7F0, 0x10469D53, 0xCA14B1F2, 0xFA8598D6, 0x1CD1A85C};
		static const bigint_t var_expected = {0x0C878A84, 0xB6AB50FC, 0xE96C5F51, 0x86647117, 0x4416969F, 0xD58898EA, 0x7B1798F0, 0x1A84F108};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 210 ");
	}
	{
		static const bigint_t var_a = {0x2BFCBD7F, 0xBFAFFFC7, 0x4B8D1EB4, 0xC089F426, 0xB7CCD90E, 0x63BF351C, 0x55F8E712, 0xA53ED682};
		static const bigint_t var_expected = {0xF2767881, 0x9C2E5958, 0xA8B31CBD, 0x2D5DA7B6, 0x3D7B959D, 0xC8056935, 0xAF7A4E58, 0x98A64292};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 211 ");
	}
	{
		static const bigint_t var_a = {0xC82434AA, 0xD4F6F74B, 0xF8BDA9F8, 0x3ACB91B2, 0xA58838EA, 0xA354A164, 0x05C609C2, 0xA85B60DA};
		static const bigint_t var_expected = {0xA673E3D2, 0x93B46B6E, 0x3C9B9CA8, 0x51B56583, 0x8ED3713A, 0x613F9187, 0x8CB38778, 0x274F8B45};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 212 ");
	}
	{
		static const bigint_t var_a = {0x7239D6BF, 0x65EAB724, 0x8EB229ED, 0x3CC67195, 0x8ECB5325, 0x137B4E06, 0x3D7CFBF7, 0x03350FDF};
		static const bigint_t var_expected = {0xA876B817, 0x326BCBBE, 0x8BDB77B6, 0xA4815816, 0x1C6A9F8D, 0x8738472D, 0x2474F991, 0x1740E3CD};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 213 ");
	}
	{
		static const bigint_t var_a = {0x5DAFA745, 0x07C7224A, 0x900C5620, 0xA3501F26, 0xBD80CD60, 0x1165CE7B, 0x5496F4CA, 0x2F205C1E};
		static const bigint_t var_expected = {0x4F2D3BAF, 0x388A1047, 0xC826E881, 0xD099D93D, 0x8CE653AB, 0x75738BE0, 0x23431270, 0x4E75F4D9};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 214 ");
	}
	{
		static const bigint_t var_a = {0x3CB4A454, 0x5C2919DB, 0x250F30F5, 0x8677DCE5, 0x3100A2C9, 0xCCA8E2C8, 0xB21521CA, 0x2AC083FF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 1 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 2 ");
	}
	{
		static const bigint_t var_a = {0x73615CBA, 0xD3EE1AD6, 0x6854BC11, 0xEE801B20, 0x7205A5CD, 0xBB8995E0, 0x7507225C, 0x9FFE9B95};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 3 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 4 ");
	}
	{
		static const bigint_t var_a = {0xAA0FA746, 0xD3B7B066, 0xFA7EAB27, 0x0712E14A, 0xF28A49B5, 0xE73B9BDD, 0x55B1109B, 0xFDC34F86};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 5 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 6 ");
	}
	{
		static const bigint_t var_a = {0x4FFFF465, 0x15DFEE5C, 0x0E9E8348, 0x12DF01AB, 0x92A97E74, 0x9742B606, 0x8CACC5FA, 0xE0AA0496};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 7 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 8 ");
	}
	{
		static const bigint_t var_a = {0xC115D591, 0x9AEFBA85, 0xACD7D33C, 0xF059B6DE, 0xE977AC57, 0x1995F5AE, 0xE6A30BE1, 0x49394B81};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 9 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 10 ");
	}
	{
		static const bigint_t var_a = {0xD6078160, 0x24E9BF67, 0x30EF2803, 0xA7428F41, 0xC28C6AAF, 0x3F9BE57B, 0x457230B3, 0x1B69E3CB};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 11 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 12 ");
	}
	{
		static const bigint_t var_a = {0x5754D438, 0xBA94F6BB, 0xC91B9CFD, 0xE1C73B17, 0x9C5194AA, 0xDD3934DD, 0x1F912BA0, 0x9FC0997B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 13 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 14 ");
	}
	{
		static const bigint_t var_a = {0x800E389F, 0x28E9335A, 0xFB2EF608, 0x6C37C34F, 0x2925A57E, 0x4CEF19AB, 0xFED6B306, 0x00FB7E8B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 15 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 16 ");
	}
	{
		static const bigint_t var_a = {0x81784D57, 0x7C7F6F2E, 0x1E0BA15D, 0xBB3E14AA, 0xCF4D8651, 0xEAFF1979, 0xFF85DE27, 0xD0403C32};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 17 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 18 ");
	}
	{
		static const bigint_t var_a = {0xFF6D6185, 0x8B17B4EF, 0xDC69E127, 0x63BB0BF4, 0x2ABC38D3, 0x98B2EB8A, 0x54AA2190, 0x81F085EC};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 19 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 20 ");
	}
	{
		static const bigint_t var_a = {0x939EF291, 0x6A2CECBD, 0xB7F2123A, 0x9F1B5529, 0x889D0419, 0x3A9D9E81, 0xC2C8D341, 0xEDF6EE9A};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 21 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 22 ");
	}
	{
		static const bigint_t var_a = {0x4A98D4D0, 0xF598FC7F, 0x80A1E018, 0xCD4EC63C, 0x6BBE1817, 0x3B014CC7, 0x24DD8235, 0xCFB79EE8};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 23 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 24 ");
	}
	{
		static const bigint_t var_a = {0x23A2B9D4, 0x4B4CDFD7, 0xE17CB3E6, 0xEF45196A, 0x0BBDC308, 0x0638E777, 0xE6A8BC35, 0x4886AB9E};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 25 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 26 ");
	}
	{
		static const bigint_t var_a = {0x94662DE7, 0x4F0EB0C6, 0xD59CD160, 0x2B042508, 0xD10BB132, 0x8E2FFF05, 0x8A512275, 0x5BAD1B7E};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 27 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 28 ");
	}
	{
		static const bigint_t var_a = {0x066E4A54, 0x2954DDA6, 0x2A81E735, 0x4B3FF8F5, 0xDDC3D3AD, 0xC7F68222, 0x264FE17E, 0x7008CFB8};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 29 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 30 ");
	}
	{
		static const bigint_t var_a = {0x5469B418, 0xC324EFF6, 0x06B8F57A, 0x3E9077E7, 0x8247E954, 0x2A5ADB7E, 0xE4AAEB4A, 0xD52BD327};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 31 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 32 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 159 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 160 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 161 ");
	}
	{
		static const bigint_t var_a = {0x3EF7CBC7, 0x13079BEA, 0xD1388B5B, 0xC10D15FF, 0x8D10D18B, 0x9AE49AE0, 0x7A81D5F3, 0x9A7E7140};
		static const bigint_t var_expected = {0x233468D4, 0xEBE6EDC7, 0x033F53EB, 0x520496A1, 0xC6D1B829, 0x607BC18A, 0xC59D0635, 0x1F952D81};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 162 ");
	}
	{
		static const bigint_t var_a = {0x894A9D44, 0xC0BBAF5B, 0xF9D2550F, 0x859FD0B0, 0xC18A94FA, 0xF8DFCAD5, 0x6A5FA34E, 0x5FC31F86};
		static const bigint_t var_expected = {0xD8E19757, 0x3E32DA55, 0xDAA58A37, 0x8D71DBEF, 0x9257F4BA, 0x02809195, 0xD5BF38DA, 0x5A507F3B};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 163 ");
	}
	{
		static const bigint_t var_a = {0xCF93BFC3, 0xB7941587, 0x02F413E4, 0x50267A8D, 0xC445FA9D, 0x814173CF, 0x2DD73E84, 0x5F1DFA1F};
		static const bigint_t var_expected = {0x929874D8, 0x475A7429, 0xD183CB62, 0xC2EB3213, 0x8F9C8F17, 0x7A1EE89B, 0x12479DA4, 0x5AF5A4A3};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 164 ");
	}
	{
		static const bigint_t var_a = {0x327C2236, 0xB597A6FA, 0xB26F257E, 0xC4E0C370, 0xEC5FEAA9, 0x434FF95B, 0x53E5977D, 0x5B939B60};
		static const bigint_t var_expected = {0x2FB01265, 0x4956E2B7, 0x2208B9C8, 0x4E30E930, 0x67829F0B, 0xB810630F, 0xEC3944AB, 0x5E800361};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 165 ");
	}
	{
		static const bigint_t var_a = {0xE308989E, 0x3FE90540, 0x5237C7E3, 0x9422307F, 0x70CC8375, 0xD2775598, 0x3B0F769D, 0x3CE436C2};
		static const bigint_t var_expected = {0x7F239BFD, 0xBF058470, 0x82401763, 0x7EEF7C21, 0xE316063F, 0x28E906D2, 0x050F658B, 0x7D2F6800};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 166 ");
	}
	{
		static const bigint_t var_a = {0x926EB4F9, 0x1AC7CFAD, 0x4E870B78, 0x63CAFB37, 0x8B16D197, 0xB63ED5A2, 0xDD6D822F, 0x39022217};
		static const bigint_t var_expected = {0xCFBD7FA2, 0xE426BA03, 0x85F0D3CE, 0xAF46B169, 0xC8CBB81D, 0x452186C8, 0x62B159F9, 0x81117CAA};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 167 ");
	}
	{
		static const bigint_t var_a = {0x142A65A3, 0xD4A0299B, 0x6C5F1F72, 0x8747B89C, 0xB2A290AD, 0x169989C8, 0xC1333BEA, 0x10F6C96A};
		static const bigint_t var_expected = {0x4E01CEF8, 0x2A4E6016, 0x6818BFD4, 0x8BC9F404, 0xA13FF907, 0xE4C6D2A2, 0x7EEBA03E, 0xA91CD557};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 168 ");
	}
	{
		static const bigint_t var_a = {0x5B2019CF, 0x3BE9926E, 0xC52FE876, 0x317373F9, 0x0E9F8B31, 0x0F7A5AA9, 0xC6D5A63D, 0x11C8F212};
		static const bigint_t var_expected = {0x070C1ACC, 0xC304F743, 0x0F47F6D0, 0xE19E38A7, 0x4542FE83, 0xEBE601C2, 0x794935EB, 0xA84AACAF};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 169 ");
	}
	{
		static const bigint_t var_a = {0xF10DB37F, 0xE09FF557, 0x409FDF5D, 0xF065A122, 0xF4C5C912, 0x350F5B6E, 0x9C648D7C, 0x9E4DD8A4};
		static const bigint_t var_expected = {0x711E811C, 0x1E4E9459, 0x93D7FFE9, 0x22AC0B7E, 0x5F1CC0A2, 0xC65100FC, 0xA3BA4EAC, 0x1BC5C61D};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 170 ");
	}
	{
		static const bigint_t var_a = {0x0931907D, 0x9D7D1331, 0xA16BFCDF, 0x87342A4B, 0x76F26096, 0x3AAD7094, 0x0A2C5287, 0x21C686A9};
		static const bigint_t var_expected = {0x58FAA41E, 0x61717680, 0x330BE267, 0x8BDD8255, 0xDCF0291E, 0xC0B2EBD6, 0x35F289A1, 0x984D1819};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 171 ");
	}
	{
		static const bigint_t var_a = {0x6FE3C9E6, 0x0D015499, 0x7B062CC6, 0x12837EF5, 0xD9823267, 0x488C788F, 0xA9C0FDF7, 0x167E91DA};
		static const bigint_t var_expected = {0xF2486AB5, 0xF1ED3517, 0x5971B280, 0x008E2DAB, 0x7A60574E, 0xB2D3E3DB, 0x965DDE31, 0xA3950CE7};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 172 ");
	}
	{
		static const bigint_t var_a = {0x0B75D99F, 0x0B1E1FB9, 0xB34B0DFF, 0x8D055438, 0x0D81581C, 0x7D349E24, 0x6653E221, 0x8C474589};
		static const bigint_t var_expected = {0x56B65AFC, 0xF3D069F8, 0x212CD147, 0x860C5868, 0x46613198, 0x7E2BBE47, 0xD9CAFA07, 0x2DCC5938};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 173 ");
	}
	{
		static const bigint_t var_a = {0xEB46BD58, 0x3FA5A15D, 0x875151AA, 0xA5ED2B1B, 0x43BB9708, 0x999AC991, 0xC4359F5F, 0x18C843EB};
		static const bigint_t var_expected = {0x76E57743, 0xBF48E853, 0x4D268D9C, 0x6D248185, 0x1026F2AC, 0x61C592DA, 0x7BE93CC9, 0xA14B5AD6};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 174 ");
	}
	{
		static const bigint_t var_a = {0x9801978B, 0x8F6466B1, 0x5B6D107E, 0xF83FF303, 0xAC639CDF, 0x4D6C4A56, 0xD800D463, 0x9CE03617};
		static const bigint_t var_expected = {0xCA2A9D10, 0x6F8A22FF, 0x790ACEC8, 0x1AD1B99D, 0xA77EECD5, 0xADF41214, 0x681E07C5, 0x1D3368AA};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 175 ");
	}
	{
		static const bigint_t var_a = {0xB00160A2, 0xA565C122, 0x13833CBD, 0x32AA62EF, 0x5B4C9AA9, 0xD1CCCEBA, 0x8B377E04, 0x266EFC25};
		static const bigint_t var_expected = {0xB22AD3F9, 0x5988C88E, 0xC0F4A289, 0xE06749B1, 0xF895EF0B, 0x29938DB0, 0xB4E75E24, 0x93A4A29C};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 176 ");
	}
	{
		static const bigint_t var_a = {0xC49EC5D0, 0x70D024CB, 0x6673D495, 0xA8553265, 0x173BCA92, 0x6361CBD7, 0x5CF4BE51, 0x25171993};
		static const bigint_t var_expected = {0x9D8D6ECB, 0x8E1E64E5, 0x6E040AB1, 0x6ABC7A3B, 0x3CA6BF22, 0x97FE9094, 0xE32A1DD7, 0x94FC852E};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 177 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 178 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 179 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 180 ");
	}
	{
		static const bigint_t var_a = {0x75E99649, 0xA700FA72, 0x8CEA5083, 0xBA25DB9F, 0x8648DFCF, 0xC7AD43B4, 0x9BA8FAA0, 0x327F7B9E};
		static const bigint_t var_expected = {0xEBD32C92, 0x4E01F4E4, 0x19D4A107, 0x744BB73F, 0x0C91BF9F, 0x8F5A8769, 0x3751F541, 0x64FEF73D};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 181 ");
	}
	{
		static const bigint_t var_a = {0xE543A881, 0x3945888A, 0xE34DFAF4, 0xBEF2AF2C, 0x53636D84, 0xB7C0E7BC, 0x2FE74E24, 0x3587CAA9};
		static const bigint_t var_expected = {0xCA875102, 0x728B1115, 0xC69BF5E8, 0x7DE55E59, 0xA6C6DB09, 0x6F81CF78, 0x5FCE9C49, 0x6B0F9552};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 182 ");
	}
	{
		static const bigint_t var_a = {0x5830849C, 0xE8AEF5E3, 0x1FF4E10D, 0xB845BEDF, 0x6551DBAE, 0x88504559, 0x91AAA94E, 0x9BE6B342};
		static const bigint_t var_expected = {0x4E34D49D, 0xD26F6215, 0x6B71E2D4, 0x5D79D11D, 0x76C12DA8, 0x15402E47, 0xE3367674, 0x7DB9C7C2};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 183 ");
	}
	{
		static const bigint_t var_a = {0x9067B2B9, 0xB29A1255, 0x1C0A23DA, 0x9C0D02EF, 0xA643E44E, 0x84673F59, 0xCF5B3466, 0x1EF3BC14};
		static const bigint_t var_expected = {0x20CF6572, 0x653424AB, 0x381447B5, 0x381A05DE, 0x4C87C89D, 0x08CE7EB3, 0x9EB668CD, 0x3DE77829};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 184 ");
	}
	{
		static const bigint_t var_a = {0x6325A0B8, 0x584BE325, 0x38C27A61, 0x71D564F3, 0xE1E73879, 0x7A80FDD9, 0xCA54D493, 0xA3C1D7C1};
		static const bigint_t var_expected = {0x641F0CD5, 0xB1A93C99, 0x9D0D157B, 0xD0991D45, 0x6FEBE73D, 0xF9A19F48, 0x548ACCFD, 0x8D7010C1};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 185 ");
	}
	{
		static const bigint_t var_a = {0x994FA6F3, 0xE32C7F1B, 0xA1A23155, 0xE2F61C96, 0x949E398C, 0x41F3F7C5, 0xF86DE9AF, 0x72530B3A};
		static const bigint_t var_expected = {0xD073194B, 0xC76A7485, 0x6ECC8364, 0xB2DA8C8C, 0xD559E964, 0x8887931F, 0xB0BCF735, 0x2A9277B3};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 186 ");
	}
	{
		static const bigint_t var_a = {0x70405118, 0x1E39EB33, 0xDBAB3A94, 0xBC4A5308, 0x739DEE25, 0x3111ED25, 0xE3BC9F7D, 0xB63E57C3};
		static const bigint_t var_expected = {0x7E546D95, 0x3D854CB5, 0xE2DE95E1, 0x6582F970, 0x93595296, 0x66C37DDF, 0x875A62D1, 0xB26910C5};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 187 ");
	}
	{
		static const bigint_t var_a = {0x1761E763, 0x176C2C88, 0x3DCFA09C, 0x72699E5A, 0xE3E1F172, 0xA751AD6B, 0xA7A24A1E, 0x01E7333E};
		static const bigint_t var_expected = {0x2EC3CEC6, 0x2ED85910, 0x7B9F4138, 0xE4D33CB4, 0xC7C3E2E4, 0x4EA35AD7, 0x4F44943D, 0x03CE667D};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 188 ");
	}
	{
		static const bigint_t var_a = {0xD1680444, 0xA359FA8B, 0x9F3DDD80, 0x8669C882, 0x2D112A7F, 0x8B2E3469, 0x380BC6ED, 0x0B321285};
		static const bigint_t var_expected = {0xA2D00888, 0x46B3F517, 0x3E7BBB01, 0x0CD39105, 0x5A2254FF, 0x165C68D2, 0x70178DDB, 0x1664250A};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 189 ");
	}
	{
		static const bigint_t var_a = {0xFA43CC31, 0xD77D8029, 0x295D0D5C, 0x59895045, 0x439442CB, 0xB5F049BE, 0xDA9927B8, 0x212ED775};
		static const bigint_t var_expected = {0xF4879862, 0xAEFB0053, 0x52BA1AB9, 0xB312A08A, 0x87288596, 0x6BE0937C, 0xB5324F71, 0x425DAEEB};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 190 ");
	}
	{
		static const bigint_t var_a = {0xA14A65B5, 0x8D360E0D, 0xAFD8C99B, 0x49C0CCB4, 0xAC8E2B06, 0x922CF313, 0x6706FB90, 0x009D22E6};
		static const bigint_t var_expected = {0x4294CB6A, 0x1A6C1C1B, 0x5FB19337, 0x93819969, 0x591C560C, 0x2459E627, 0xCE0DF721, 0x013A45CC};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 191 ");
	}
	{
		static const bigint_t var_a = {0x00115E7C, 0xE87707DC, 0x2F561160, 0x3149999E, 0xF6107998, 0x962E4DF3, 0xCD75D07D, 0x5362D57A};
		static const bigint_t var_expected = {0x0022BCF8, 0xD0EE0FB8, 0x5EAC22C1, 0x6293333C, 0xEC20F330, 0x2C5C9BE7, 0x9AEBA0FB, 0xA6C5AAF5};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 192 ");
	}
	{
		static const bigint_t var_a = {0x8DC7D3AD, 0xCB4D5BEF, 0xA75CE0EF, 0x38F228EB, 0x8AA45F27, 0xB3F74D3B, 0x8D8BF719, 0x1FE53AEA};
		static const bigint_t var_expected = {0x1B8FA75A, 0x969AB7DF, 0x4EB9C1DF, 0x71E451D7, 0x1548BE4E, 0x67EE9A77, 0x1B17EE33, 0x3FCA75D5};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 193 ");
	}
	{
		static const bigint_t var_a = {0x74B907DE, 0x59AB85DC, 0x8BAA3C20, 0x50BE0BBD, 0x301DB782, 0xD5C99091, 0x3D5DB57C, 0x3FA31E5C};
		static const bigint_t var_expected = {0xE9720FBC, 0xB3570BB8, 0x17547840, 0xA17C177B, 0x603B6F04, 0xAB932122, 0x7ABB6AF9, 0x7F463CB8};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 194 ");
	}
	{
		static const bigint_t var_a = {0x92DBDF9F, 0x7F9D7970, 0x03FD9177, 0x64D14D35, 0x3AB7FB80, 0x75448F95, 0x0733481B, 0x010C50B6};
		static const bigint_t var_expected = {0x25B7BF3E, 0xFF3AF2E1, 0x07FB22EE, 0xC9A29A6A, 0x756FF700, 0xEA891F2A, 0x0E669036, 0x0218A16C};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 195 ");
	}
	{
		static const bigint_t var_a = {0xF4F0CBF7, 0x6E357C84, 0x5C06CED7, 0xE2305D17, 0x0680A4A7, 0x1811AED0, 0x281635B8, 0x9F384F47};
		static const bigint_t var_expected = {0x87B56353, 0xDD7C6F58, 0xE395BE67, 0xB14F0D8D, 0xB91EBF9A, 0x34C30134, 0x100D8F47, 0x845CFFCC};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 196 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 33 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 34 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 35 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 36 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 37 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 38 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 39 ");
	}
	{
		static const bigint_t var_a = {0x504CA107, 0x4D0D968B, 0x5FD4DCE8, 0x95336108, 0xC4B4BD81, 0x3590EBD8, 0x828D8950, 0x381DE4EB};
		static const bigint_t var_b = {0x3E38FBAD, 0xBA25F423, 0x81B401DA, 0x075AD8A6, 0xE1279C02, 0xE9F5CA60, 0xD01D1E6B, 0x2E9C1B3B};
		static const bigint_t var_expected = {0x8E859CB4, 0x07338AAE, 0xE188DEC3, 0x9C8E39AE, 0xA5DC5983, 0x1F86B639, 0x52AAA7BC, 0x66BA0027};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 40 ");
	}
	{
		static const bigint_t var_a = {0x5736E50E, 0x41255207, 0x8C18C4B4, 0xED08DAD8, 0xC5CD9493, 0x4ADB49F0, 0x34AF3946, 0xB0FA10BD};
		static const bigint_t var_b = {0x48C22CD5, 0xDC86B247, 0xF488C18C, 0xC68A3D5A, 0x94C68232, 0xE35F93BC, 0x294053CF, 0x9985EBFC};
		static const bigint_t var_expected = {0x3DCCDD48, 0x1EBD7A9D, 0xAC29A6FA, 0xA0816B92, 0x06B18D11, 0x32DA8142, 0x1DD0B0ED, 0x906C5DF7};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 41 ");
	}
	{
		static const bigint_t var_a = {0xB02472BC, 0xCCBDF480, 0xFF8C1E4A, 0xB56F2233, 0x24D8FBD7, 0x3F5F7E22, 0xBB48C3DC, 0x297D2927};
		static const bigint_t var_b = {0xA59D11C4, 0x137A7A70, 0x4B315093, 0xFE1DEE10, 0x80F0937A, 0x716D5FEE, 0x0DD9D9D2, 0x859D1D7F};
		static const bigint_t var_expected = {0x55C18480, 0xE0386EF1, 0x4ABD6EDD, 0xB38D1044, 0xA5C98F52, 0xB0CCDE10, 0xC9229DAE, 0xAF1A46A6};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 42 ");
	}
	{
		static const bigint_t var_a = {0x305F1735, 0xF8FC808D, 0x45DE1F0B, 0x8CF23A9E, 0x66781EC5, 0x8DE36D08, 0xD3072A91, 0x343765B6};
		static const bigint_t var_b = {0xCC57C8A3, 0x877DA0DE, 0xB27EE331, 0x6EF15A90, 0xCA75D793, 0x2DFC0DBF, 0xD8B0645B, 0xA3D7D896};
		static const bigint_t var_expected = {0x9A8AAB3D, 0x818B97BA, 0x23E522F6, 0xE8D1E88E, 0xDD0B6CA3, 0xC07F1E5C, 0x6B98B2C3, 0x1DFB9F8B};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 43 ");
	}
	{
		static const bigint_t var_a = {0xEBCC89DC, 0x0E9D23A5, 0x2AF6235E, 0x56065093, 0x517E9E1F, 0xEDFF9100, 0x7A835CC2, 0xA281B93D};
		static const bigint_t var_b = {0x0F98FC80, 0xA3FC9E6A, 0xC46F4C87, 0x06C3AF16, 0x83972404, 0xF320E84B, 0xE94231A2, 0x2B617DBA};
		static const bigint_t var_expected = {0x993951C1, 0xB3AB385E, 0x1AED909E, 0x49B85309, 0x8133386E, 0xE5C01CE0, 0x23A6B23C, 0x13CF9836};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 44 ");
	}
	{
		static const bigint_t var_a = {0x37440A03, 0x987CC06D, 0xBCCB38C9, 0x311A8985, 0xE934751D, 0x57ACCD1A, 0xEB0BC1B2, 0x858BD7D6};
		static const bigint_t var_b = {0x8952118D, 0x0C8B7750, 0xA9574824, 0x3E9BD06A, 0x4CC389A9, 0xCF9C4556, 0xDB24ABB8, 0x7C1870EA};
		static const bigint_t var_expected = {0x5E69E6F5, 0xA619AE0C, 0x91AAA1A6, 0x5CA4AD4F, 0xE2157511, 0x2BE8B605, 0x86119142, 0x4790A9FF};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 45 ");
	}
	{
		static const bigint_t var_a = {0xA9DA3F89, 0x5D2E0404, 0x4733BC43, 0x80A7BBBB, 0x74B2C843, 0x05D185E2, 0xA57A9646, 0x2C6ACE1D};
		static const bigint_t var_b = {0xE826ACC3, 0xB02F79BC, 0xFE876E99, 0x4C16F98B, 0xBA299993, 0x2D432ECE, 0xCC89A182, 0x1FBA18FB};
		static const bigint_t var_expected = {0x9200EC4C, 0x0D5D7DC1, 0x45BB2ADD, 0xCCBEB547, 0x2EDC61D6, 0x3314B4B1, 0x720437C8, 0x4C24E719};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 46 ");
	}
	{
		static const bigint_t var_a = {0x1535466F, 0x6789F9EB, 0x59AE0D6B, 0xE441023D, 0x7628B5A4, 0x70D6FD1F, 0x6502295C, 0x2A2951D9};
		static const bigint_t var_b = {0x274F5BDD, 0xB3F50CE0, 0x402664E9, 0x3D833FBE, 0x41511631, 0x93332752, 0x19D82B57, 0xAC222C86};
		static const bigint_t var_expected = {0xDA586DB1, 0x1C907D19, 0xC55C930E, 0x0EB2955A, 0x63974221, 0x08A9C806, 0x3EBB788B, 0x1C37DF9D};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 47 ");
	}
	{
		static const bigint_t var_a = {0x91D7EF83, 0x00392392, 0xBE3B5487, 0x3DA73751, 0xB5330A62, 0x5035F8E9, 0x27FFDADA, 0x4FDAA080};
		static const bigint_t var_b = {0x752E7FF8, 0x838CD333, 0x8C7E94A4, 0xC6D295CE, 0xF8417500, 0xED648542, 0x5F9439EC, 0x2D1DD7AA};
		static const bigint_t var_expected = {0x07066F7B, 0x83C5F6C6, 0x4AB9E92B, 0x0479CD20, 0xAD747F63, 0x3D9A7E2C, 0x879414C7, 0x7CF8782A};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 48 ");
	}
	{
		static const bigint_t var_a = {0x72753CA9, 0xAF4C1986, 0x8427588D, 0xACCF5556, 0x352CFC99, 0x9F069BA0, 0x28C601D6, 0xACA51A50};
		static const bigint_t var_b = {0xEC32588F, 0xC5D97512, 0x0AD88DA5, 0x61B71E59, 0x8013735C, 0x44D5C837, 0x3AFB246F, 0x00A150AC};
		static const bigint_t var_expected = {0x5EA79538, 0x75258E99, 0x8EFFE633, 0x0E8673AF, 0xB5406FF6, 0xE3DC63D7, 0x63C12645, 0xAD466AFC};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 49 ");
	}
	{
		static const bigint_t var_a = {0x4C410363, 0x3FC8AAD7, 0xF8DA708A, 0x92FDB8EB, 0x3C75C922, 0x969398AA, 0xE5759660, 0x92D969DD};
		static const bigint_t var_b = {0xC1699723, 0x632E0A82, 0xAA9B19FA, 0x8EFBFA0C, 0xBB6FC1D6, 0xF45EA120, 0xC99D0517, 0x971207DF};
		static const bigint_t var_expected = {0xAB7E65EB, 0xA4082BA8, 0xCEFDAB3D, 0x0EE80657, 0xA4030144, 0x8F91DD5F, 0x6EF3BF4F, 0x6FD7D2FB};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 50 ");
	}
	{
		static const bigint_t var_a = {0xF53CD1A4, 0xB733833F, 0xA6AC8627, 0x91CD46B4, 0x4ECD53BA, 0xAEE59B0D, 0x1CC6BAEE, 0x92FA5D5C};
		static const bigint_t var_b = {0xA604EC06, 0x87CF65B3, 0xEE91913D, 0xEAADF9E6, 0x28BBEFD7, 0x9E9EC4A5, 0xE74FEF6C, 0x2F71C785};
		static const bigint_t var_expected = {0x3915890F, 0x40145F42, 0xC0C6381E, 0x696993FA, 0x23A6B9DD, 0x52240347, 0xC3F7CE32, 0x0858861F};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 51 ");
	}
	{
		static const bigint_t var_a = {0x8289FB13, 0x622B54FC, 0x5BB02830, 0x8A467930, 0x309EAD8E, 0xA056F93A, 0xC9D71162, 0x7ED36405};
		static const bigint_t var_b = {0xB07D19D7, 0x9A2795AB, 0x19143301, 0x87814C9F, 0x81D5121A, 0x166DE40F, 0x7394D2E8, 0x73C484F9};
		static const bigint_t var_expected = {0xD0DAE04F, 0xFD6460F6, 0xA04C7BEA, 0xFEB6192E, 0x5E9135F3, 0xBB6480DE, 0xFD4D0821, 0x38844A3C};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 52 ");
	}
	{
		static const bigint_t var_a = {0x48B7E532, 0xC7EF828D, 0x2687B64A, 0x9DE94D71, 0xE84C9B44, 0x6420A3A9, 0x2905ED1D, 0x6585A84E};
		static const bigint_t var_b = {0xD63AE3E0, 0x449F8724, 0xD6F73976, 0xA89A9902, 0x69DFF289, 0x75EA382E, 0x47F008CD, 0x93DEABF6};
		static const bigint_t var_expected = {0xBCC69477, 0x0DA08000, 0x2907107A, 0x337239D3, 0xFE4A0419, 0xDEAA7F6C, 0x30D719C1, 0x3F50B582};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 53 ");
	}
	{
		static const bigint_t var_a = {0xDB157C2A, 0xB0F559B4, 0x522F9E4E, 0x2BC218A5, 0xBB8908E1, 0x34ED6116, 0xBAB14CC0, 0x9A97D1E8};
		static const bigint_t var_b = {0x4C09B63B, 0x6F1B6CFF, 0x14D8E646, 0xCCAFCC20, 0xC76C6581, 0x146F96F9, 0x83D97AB9, 0x0080B6CC};
		static const bigint_t var_expected = {0x271F3265, 0x2010C6B4, 0x67088495, 0xF871E4C5, 0x82F56E62, 0x495CF810, 0x3E8AC779, 0x9B1888B5};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 54 ");
	}
	{
		static const bigint_t var_a = {0x1104E226, 0x2776BE64, 0x6CD4ADE5, 0xD5753BBF, 0x2DA0713A, 0x89675183, 0x381AB55C, 0xAD076DB0};
		static const bigint_t var_b = {0x876DD08F, 0x438D88E0, 0xFEE43A42, 0xB519A0EE, 0xBED4905E, 0x8D1BECB0, 0x83873E7E, 0x6D674330};
		static const bigint_t var_expected = {0x36467E1A, 0x6C15BD93, 0x974108E0, 0x777D300D, 0x989277E4, 0x1B22E1C8, 0x7B8317B2, 0x605B121E};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 55 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 56 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 57 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 58 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 59 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 60 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 61 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 62 ");
	}
	{
		static const bigint_t var_a = {0xFF3F547C, 0x73FE698E, 0x429F7965, 0x7D54C0BB, 0x03C740D7, 0x1CCAA04F, 0xA124D755, 0x6F59F604};
		static const bigint_t var_b = {0xDBC6EA5C, 0x2B938BFE, 0x2F3C6867, 0x51D1DCFA, 0x619F19FD, 0xBD0829E7, 0xA3A3ADEA, 0x0F4DB341};
		static const bigint_t var_expected = {0x23786A20, 0x486ADD90, 0x136310FE, 0x2B82E3C1, 0xA22826DA, 0x5FC27667, 0xFD81296A, 0x600C42C2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 63 ");
	}
	{
		static const bigint_t var_a = {0x970A0A6E, 0x20121F36, 0x0D0DF5C6, 0x31572C9F, 0xEF8D95A9, 0xEA0F3A94, 0xF011310A, 0x3792E673};
		static const bigint_t var_b = {0x617DCC0D, 0xCDB31D49, 0xCF0F130E, 0x1ADA0C7D, 0x4F41FFCC, 0xAEB7152B, 0x82B5FDB3, 0x455AA4E4};
		static const bigint_t var_expected = {0x97B872FC, 0x514D8B9E, 0x1276C1FE, 0x298ECCC2, 0xF42E1F92, 0x36B881D4, 0xAD7A0F80, 0xAC4BE051};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 64 ");
	}
	{
		static const bigint_t var_a = {0x9555898A, 0xF2609722, 0x951B6319, 0x89854398, 0x31993BFD, 0x1E64DD94, 0x64E5AB0E, 0x84B021FB};
		static const bigint_t var_b = {0x2A968687, 0x149861DF, 0x4FC80E68, 0x589D6DB0, 0x7294D8A7, 0xC8E17873, 0x7BBA3756, 0x536A3F97};
		static const bigint_t var_expected = {0x6ABF0303, 0xDDC83543, 0x455354B1, 0x30E7D5E8, 0xBF046356, 0x55836520, 0xE92B73B7, 0x3145E263};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 65 ");
	}
	{
		static const bigint_t var_a = {0x462ADD3C, 0xF81C6684, 0x17E85406, 0xDC48E0B6, 0xFE37F7B8, 0x4591AB0F, 0xB9E64B51, 0x00D9165A};
		static const bigint_t var_b = {0x0CBF75DE, 0x28F13EE5, 0xAF82245A, 0xDEAECBD3, 0x44FF497B, 0xA0C84B36, 0x2C2ECA02, 0xA4E91693};
		static const bigint_t var_expected = {0x9B979BF9, 0xCE19B150, 0x3CDE0EF3, 0x10ABC183, 0x0D1B37F2, 0xA029BC45, 0xCDD65D77, 0x16039E89};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 66 ");
	}
	{
		static const bigint_t var_a = {0x47986037, 0x767C4CA2, 0xB2937CF4, 0x5781420E, 0x6DF7C676, 0x04366A84, 0xEE3C0AF5, 0x6298ACD0};
		static const bigint_t var_b = {0xBCC0E9F0, 0x735D9C7A, 0x5E895588, 0xAF829E77, 0x2859DB7B, 0x0EE639F6, 0x313E7AC3, 0x297ED74F};
		static const bigint_t var_expected = {0x8AD77647, 0x031EB027, 0x540A276C, 0xA7FEA397, 0x459DEAFA, 0xF550308E, 0xBCFD9031, 0x3919D581};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 67 ");
	}
	{
		static const bigint_t var_a = {0xC661914E, 0xF757F7DC, 0xF5FE6375, 0xE18BFAF2, 0x84AFF019, 0x63AB296D, 0x7DEEC553, 0x8FC62C6A};
		static const bigint_t var_b = {0x30FBB9A2, 0x9DE7D8AD, 0x089CEE32, 0x0A8F9629, 0xC41C7D89, 0x2BDC14CE, 0x69B9D728, 0x122CD71A};
		static const bigint_t var_expected = {0x9565D7AC, 0x59701F2F, 0xED617543, 0xD6FC64C9, 0xC0937290, 0x37CF149E, 0x1434EE2B, 0x7D995550};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 68 ");
	}
	{
		static const bigint_t var_a = {0xBB3D6949, 0x45F43C49, 0x01CBDBEB, 0xEE174C58, 0xDE8C03C6, 0x95BE96D2, 0x240850B3, 0x9170FC57};
		static const bigint_t var_b = {0x3989253C, 0x91A83566, 0xC7476FBA, 0x5F4B3598, 0xA9D56E1E, 0x55A55298, 0xAFC04B7A, 0x17518AC7};
		static const bigint_t var_expected = {0x81B4440D, 0xB44C06E3, 0x3A846C30, 0x8ECC16BF, 0x34B695A8, 0x4019443A, 0x74480539, 0x7A1F718F};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 69 ");
	}
	{
		static const bigint_t var_a = {0x981872AD, 0x68FDB6B8, 0x9055B530, 0x0DCBF6B3, 0xAD12A588, 0x18FC6D44, 0x61B1BCAD, 0x3F7167DD};
		static const bigint_t var_b = {0x746EA059, 0x75FD7E9B, 0x420E484E, 0xA695D79B, 0xF8DBCEB9, 0x17047A46, 0x2233A42B, 0x161CD7D6};
		static const bigint_t var_expected = {0x23A9D254, 0xF300381D, 0x4E476CE1, 0x67361F18, 0xB436D6CE, 0x01F7F2FD, 0x3F7E1882, 0x29549007};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 70 ");
	}
	{
		static const bigint_t var_a = {0x9A6F863B, 0xA8AF572F, 0xEB58042A, 0x57BDFF07, 0xADB8CE0E, 0x998081C0, 0xF0B7D30A, 0x98FC8442};
		static const bigint_t var_b = {0x0CFF11EB, 0xB5DD1AA2, 0x970F263C, 0x950553E2, 0xC6EB0EB1, 0x5CF38CA6, 0x5D2631D2, 0x19B99C02};
		static const bigint_t var_expected = {0x8D707450, 0xF2D23C8D, 0x5448DDED, 0xC2B8AB25, 0xE6CDBF5C, 0x3C8CF519, 0x9391A138, 0x7F42E840};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 71 ");
	}
	{
		static const bigint_t var_a = {0xEEE4739F, 0x9011E498, 0xA20D7EC1, 0xB4D48D47, 0xED6352CB, 0x1CC94B4E, 0x4E2794EF, 0x7FE0CE4A};
		static const bigint_t var_b = {0x82C913CE, 0xF65C1DF5, 0xC4DF984D, 0xB9018B9D, 0x08B3C9F5, 0x2DD698F3, 0x3E8B914A, 0x399880C2};
		static const bigint_t var_expected = {0x6C1B5FD1, 0x99B5C6A3, 0xDD2DE673, 0xFBD301A9, 0xE4AF88D5, 0xEEF2B25B, 0x0F9C03A4, 0x46484D88};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 72 ");
	}
	{
		static const bigint_t var_a = {0x8B4BF9D9, 0xE7D9B8FB, 0xD7A8619E, 0x99892FAF, 0x038E2C57, 0xD702EA63, 0x3951BEBF, 0x0064CA5B};
		static const bigint_t var_b = {0xE04CC764, 0x25493731, 0x38510DC0, 0x5AC5210D, 0xA7E8F21E, 0xED673799, 0x2129085C, 0xB8464A80};
		static const bigint_t var_expected = {0x0D2B6710, 0xC17F0B7B, 0x73CF3325, 0x51D5BB43, 0xAF87C3EE, 0xE4FC0F34, 0x5847928B, 0x02321E9D};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 73 ");
	}
	{
		static const bigint_t var_a = {0x4819DB21, 0xB854FEAE, 0x16D55C9F, 0xA69CE059, 0x7429A701, 0x44BBFF5C, 0x6D014CF8, 0xAAEF020C};
		static const bigint_t var_b = {0x0031ACB1, 0x6AF4AADF, 0xF66A14A5, 0x4C36217F, 0x1C4C76B0, 0x336C3502, 0xA5C57F46, 0x02637727};
		static const bigint_t var_expected = {0x47E82E70, 0x4D6053CF, 0x206B47FA, 0x5A66BED9, 0x57DD3051, 0x114FCA5A, 0xC73BCDB2, 0xA88B8AE4};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 74 ");
	}
	{
		static const bigint_t var_a = {0x38E36A2C, 0x4BE29BF8, 0x2DFAC0D1, 0xBD3802C2, 0x06D4B144, 0x19D00240, 0xE76CE579, 0x5032636D};
		static const bigint_t var_b = {0x96B8E756, 0x2D1FA6F9, 0x69E14597, 0x909A3605, 0xCC8EAD5D, 0xD75E372B, 0x65582144, 0x084511DD};
		static const bigint_t var_expected = {0xA22A82D6, 0x1EC2F4FE, 0xC4197B3A, 0x2C9DCCBC, 0x3A4603E7, 0x4271CB14, 0x8214C434, 0x47ED5190};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 75 ");
	}
	{
		static const bigint_t var_a = {0xB1AD0D14, 0x28872568, 0x290DED22, 0xFE028A8A, 0xBD26A352, 0x52FF6F74, 0xE5014E82, 0x02319378};
		static const bigint_t var_b = {0x35114549, 0x198851FD, 0x6BE71460, 0x53A8B3EE, 0x08A2FBF0, 0xF802EF96, 0xFFDB8A55, 0x400EBC91};
		static const bigint_t var_expected = {0xDEC7FC66, 0x0DED5D1C, 0x919EB809, 0xBD6B833C, 0x08663117, 0x565CDC4A, 0x2544A055, 0x7C3675A9};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 76 ");
	}
	{
		static const bigint_t var_a = {0x473CF62C, 0x1A7C4D08, 0x5660CB7F, 0xCA2A1532, 0xDF05EED6, 0x267743AF, 0xE337A51A, 0x1157FA4B};
		static const bigint_t var_b = {0x3881EE8B, 0x1322961D, 0x675090A2, 0x51F05428, 0xB0778DD6, 0xDED7E88E, 0x50B5A695, 0x4A210686};
		static const bigint_t var_expected = {0x70E73C3C, 0x0648409C, 0xC3881A24, 0x8B4B6DAA, 0x8270EAB5, 0x42FFB78C, 0xD2A0DAAD, 0x814A9287};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 77 ");
	}
	{
		static const bigint_t var_a = {0xD16113BD, 0x29BED90F, 0x4273630F, 0xC379DFF0, 0xF0F0CA8E, 0x0F66B52E, 0x9E5F7BD7, 0x0E86656F};
		static const bigint_t var_b = {0xEEFBCB69, 0x4758D176, 0x0ABCAD39, 0x10394855, 0xEF707A75, 0x33DFA49C, 0xF554F160, 0xA96289DC};
		static const bigint_t var_expected = {0x44917CEF, 0xE154914A, 0x0C2E951C, 0xC652443C, 0x5562D9CE, 0xD6E76CFD, 0xE929669F, 0x1F377A54};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 78 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 79 ");
	}
	{
		static const bigint_t var_a = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 80 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 81 ");
	}
	{
		static const bigint_t var_a = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_b = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 82 ");
	}
	{
		static const bigint_t var_a = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_b = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 83 ");
	}
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
	{
		static const bigint_t var_a = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_b = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 86 ");
	}
	{
		static const bigint_t var_a = {0x8BAD5EB2, 0xC5EB885F, 0xA162CF89, 0xA67A4E82, 0x797BA5E7, 0x9A80887C, 0x6F86308B, 0x7B2E6091};
		static const bigint_t var_b = {0xDE4C146E, 0xD39204D7, 0xD058879E, 0x4545CE3B, 0xB3A9BA48, 0x389C7FB2, 0xF3497C7C, 0x5C4884E6};
		static const bigint_t var_expected = {0xC10FD745, 0xE46AEC43, 0xBBA96D33, 0x56EC9627, 0xD60C34CA, 0xA74781C5, 0x5B22947B, 0x0570869B};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 87 ");
	}
	{
		static const bigint_t var_a = {0x4B6C1A0F, 0xD6BB4566, 0x7FDDCE86, 0xDC8B4C7D, 0x5D4C74D6, 0xDCFA0D7A, 0x450F1DC8, 0x4546D538};
		static const bigint_t var_b = {0xE0BCB4B8, 0x76840C94, 0x98AD300E, 0xA0B8B2CD, 0x2A5589DA, 0x513859D4, 0xE2598CE0, 0x7586C587};
		static const bigint_t var_expected = {0x72B984F7, 0xB8DF22DC, 0x05A2D055, 0x67F3C324, 0xE16FBD99, 0xDDDD30FB, 0x0220C503, 0x2FF21B06};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 88 ");
	}
	{
		static const bigint_t var_a = {0x7034022A, 0x25E993B9, 0xEC9E91A8, 0xDD754685, 0x8E52CEA9, 0x6B452808, 0xC7E628A9, 0x40CE6B33};
		static const bigint_t var_b = {0x38FAFF8B, 0xE6880F7B, 0xE4BC5F26, 0x24B1F081, 0x26010964, 0x856585D9, 0xE6B71DE6, 0x640DE926};
		static const bigint_t var_expected = {0x862EB6D5, 0x236D3D51, 0xA6763509, 0x7B9849CD, 0x26F6D83C, 0xB7877C24, 0x068703EE, 0x6967F488};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 89 ");
	}
	{
		static const bigint_t var_a = {0x866BD5C0, 0x2512DD41, 0x0907E8D2, 0xFF0F44FF, 0xDC695D99, 0x19D93401, 0xEDD2DDE5, 0x54B54501};
		static const bigint_t var_b = {0x179A34CC, 0x55823740, 0x66432E0A, 0x3D61E4C6, 0x7AAFAD2D, 0xE9382EB8, 0x0632E98F, 0x955F96A4};
		static const bigint_t var_expected = {0x85484D1B, 0x50B2CCD8, 0xE636EE58, 0x5289F646, 0xDD6F315C, 0xD0D9D284, 0x5D717B25, 0x8BCD17C5};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 90 ");
	}
	{
		static const bigint_t var_a = {0x0FE51F8F, 0x9739645C, 0x45975F71, 0x60188DD8, 0x5A29275C, 0x2E529095, 0x4399976A, 0x5F575B5C};
		static const bigint_t var_b = {0x1222D7E5, 0x79B16747, 0xBC645899, 0xF202A273, 0x4059B30D, 0x66B395E0, 0x17307172, 0x11BD5A11};
		static const bigint_t var_expected = {0x7F4C7908, 0x25FCCD42, 0x42905E1D, 0x78436A2D, 0x054BF1F1, 0xF11FAF60, 0x90E858BA, 0xA0D6098E};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 91 ");
	}
	{
		static const bigint_t var_a = {0x7779E4EF, 0x4029980D, 0x27D4FF37, 0x097F0E26, 0x73113F92, 0x178146DB, 0x828702D1, 0x95AEC485};
		static const bigint_t var_b = {0xE602E486, 0xB2DA6580, 0xDC9D188B, 0x60FFB282, 0x65571FB4, 0x665A5249, 0x3F82C349, 0x90D75875};
		static const bigint_t var_expected = {0xAE6D5AA7, 0x1F42A2FC, 0xDA0D3365, 0xE5820E9D, 0x536D475C, 0xBBFD28A4, 0xDA419447, 0x42690253};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 92 ");
	}
	{
		static const bigint_t var_a = {0xC9CCD860, 0x9E9CE23F, 0x7CC0C208, 0x74805C12, 0xEB852435, 0x499EF3DD, 0xD949B093, 0xB2B5A140};
		static const bigint_t var_b = {0x2835C30F, 0x9EA50D1C, 0xA901BB37, 0xE7CACF5C, 0xB7790F09, 0xCDD39610, 0xD2D2874A, 0x0EEB7E23};
		static const bigint_t var_expected = {0x9A8942B7, 0x175B60C9, 0x672E014F, 0x29FA1EED, 0x8596FD87, 0x4D20D9B8, 0x20C42FD0, 0x73B4859E};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 93 ");
	}
	{
		static const bigint_t var_a = {0x4055D6C2, 0x4357D307, 0xFCD8D94F, 0xB9542360, 0xAD2A72C8, 0x17B8BD6B, 0x835FA18F, 0x47D0DA3C};
		static const bigint_t var_b = {0x310B5C38, 0xFF5BDAA2, 0xFEA373E7, 0xD6471582, 0xB2870869, 0x60D3821E, 0x50BE234F, 0x7EA940CC};
		static const bigint_t var_expected = {0x971DF911, 0x86F89FE6, 0xBC34ED3D, 0xE02A59BA, 0xDBCD1F73, 0x577A3B2C, 0x4DE50504, 0x40B1A272};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 94 ");
	}
	{
		static const bigint_t var_a = {0x04DF1810, 0x1E62FF1F, 0xE7878582, 0xADA696CA, 0x5EA5ED6D, 0x603BD139, 0xC20E3CFC, 0x6D08DD07};
		static const bigint_t var_b = {0x3F7777CF, 0xAD85DDB7, 0x3D598E3D, 0xA536C4E5, 0xB4CBD349, 0x4F736B08, 0x4F845BC0, 0x7B44EF8D};
		static const bigint_t var_expected = {0xBBC95A44, 0xC01D95E3, 0x3A984D07, 0xA89A52F5, 0xE2105812, 0x8AF99545, 0x32DEDAF2, 0x1D813C79};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 95 ");
	}
	{
		static const bigint_t var_a = {0xD9F50DDF, 0x578E820E, 0x2119F222, 0xCFAAC89D, 0x2179D99A, 0x76FDA6E4, 0xE553BB9E, 0x8BF5D0C1};
		static const bigint_t var_b = {0xCCE84DAE, 0xB1B5D612, 0x79412596, 0xAC58C492, 0x5623816B, 0x021DD7FA, 0x98516016, 0x12459FDC};
		static const bigint_t var_expected = {0xCEAAB57F, 0xBB9A5976, 0x84D4B811, 0x4DC618A0, 0xBF3D849B, 0x4A328E50, 0x9B4C3415, 0x5B92BB2F};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 96 ");
	}
	{
		static const bigint_t var_a = {0x359F5F35, 0x35629D67, 0xC22AC45B, 0x0C9847A4, 0x76BA03B3, 0xFBC83285, 0x21AF71B6, 0x72CE377F};
		static const bigint_t var_b = {0x5F4813DE, 0xE1AE0DEE, 0xA4AE0FD9, 0xD8AF1D59, 0x2E8C52BF, 0xF0EA3545, 0x70B6B4A9, 0x264E53F8};
		static const bigint_t var_expected = {0xFFEF56A3, 0x5D686DF6, 0x196EE61D, 0xBB41ABC0, 0xB2110BCD, 0x47F589FB, 0x846AF931, 0x2E9E737A};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 97 ");
	}
	{
		static const bigint_t var_a = {0xC93AD368, 0x0912B9AC, 0xA0D3C255, 0x9A4A390D, 0x99A3616D, 0x213087D4, 0x27889E2A, 0xA769F144};
		static const bigint_t var_b = {0x8C82EEED, 0x532C17D1, 0xEDB68A64, 0x0304F06A, 0x053E5DCD, 0x05F15589, 0x2ABAC7D1, 0xB025981C};
		static const bigint_t var_expected = {0x0A3DEC58, 0x9EEAE15C, 0x877D3B23, 0xD87993A6, 0x6CD7AC50, 0x8F60C9A7, 0x4C8CA248, 0x93DA375C};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 98 ");
	}
	{
		static const bigint_t var_a = {0x6438DB72, 0xDB6FFA5A, 0x87134F40, 0x7AC66BE8, 0xA308FDA2, 0x474C2C5B, 0x3C2A8FA2, 0x9E6A55F3};
		static const bigint_t var_b = {0xF1253C63, 0xD6825BA0, 0xFDCF0C6D, 0xF999889F, 0x5ACA8875, 0x88997284, 0x8DD562E0, 0x609C3735};
		static const bigint_t var_expected = {0x2B4DE05C, 0xBBBEDBCE, 0x15823DC8, 0x620F2C73, 0xA9445418, 0xB49B77ED, 0xCA745CF1, 0x88F343E0};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 99 ");
	}
	{
		static const bigint_t var_a = {0xF3668AFC, 0x200DE665, 0x415F1053, 0x3D61DC33, 0x3B75F51E, 0xA27EA785, 0xCC52526F, 0x02A3D936};
		static const bigint_t var_b = {0x0A834F7A, 0xAA95E0E1, 0xF89D2E88, 0x9AA4C7C0, 0x1F3E2C0C, 0xE7C1A53B, 0x0E4472E7, 0x58AB59D5};
		static const bigint_t var_expected = {0x44F0112C, 0x534AF22E, 0xC07F0966, 0xC488DA62, 0x1CBCC94C, 0x12CD55B8, 0x623C1F78, 0x18039AA8};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 100 ");
	}
	{
		static const bigint_t var_a = {0x874EDB04, 0x6C302E56, 0x03BB00BD, 0x3D93E9DE, 0xAFEB1B3E, 0xC8127570, 0xCC0A1FD8, 0x5EFFF03B};
		static const bigint_t var_b = {0x4EA0045C, 0x1448911A, 0x07AC66E0, 0x207943DF, 0x5C1D472C, 0xA49ABD43, 0xCF6F37C5, 0x8AF5AA1A};
		static const bigint_t var_expected = {0x6E6EBCA7, 0x3935A4CE, 0xFB98D3C3, 0x59A47220, 0x8AF3C20E, 0x02F18C8A, 0xC9D2BDFC, 0x7DD82BA8};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 101 ");
	}
	{
		static const bigint_t var_a = {0xCBD9AA07, 0xF24CDB9F, 0x8F4D7E7D, 0x117E0B8A, 0xEB31AE2B, 0x4359DBBD, 0x159CA05F, 0x8D93F738};
		static const bigint_t var_b = {0x72D70C98, 0xF816366C, 0xD058577E, 0xDC1E0E4D, 0x66491CD4, 0x5D37DB80, 0x068768C5, 0x90BDF8C6};
		static const bigint_t var_expected = {0x5075F43D, 0xC74D1BB7, 0x9C0DF744, 0x443F6081, 0x1E5B3F8B, 0x3D2B6F81, 0x2751DD44, 0x777BE98F};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 102 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 103 ");
	}
	{
		static const bigint_t var_a = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 104 ");
	}
	{
		static const bigint_t var_a = {0xC4586936, 0xFDDD1362, 0xA8EFBE8D, 0x26235941, 0xA7C5136A, 0xF6C0B8D6, 0x803DB851, 0x74273D84};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 105 ");
	}
	{
		static const bigint_t var_a = {0xFD5DC488, 0x8B8995F2, 0x4330EACC, 0xA351FAF9, 0x1FDD655C, 0x978BA22E, 0xABC4611A, 0x45623EF2};
		static const bigint_t var_expected = {0x969065E6, 0x5151B2F5, 0x52C04917, 0xCF6DB9EA, 0xC7E87BE8, 0x65408C3B, 0x49E68398, 0x6F791FE9};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 106 ");
	}
	{
		static const bigint_t var_a = {0xF2C6349F, 0x26A4C450, 0xE88B2D8F, 0xC166443A, 0x2CEB7CFE, 0xD58778E0, 0x45B4AB4F, 0x43ADB10D};
		static const bigint_t var_expected = {0x671B48DF, 0xE44B179F, 0x3FF35E9D, 0xDC303FB3, 0x18358471, 0x5127B2C0, 0x5FA3D503, 0x7CF811FF};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 107 ");
	}
	{
		static const bigint_t var_a = {0xAB16875A, 0x4353B3D5, 0xB96CAA47, 0x97324059, 0x255D9B47, 0xEF217DA1, 0x3E8D57DC, 0x49F8197C};
		static const bigint_t var_expected = {0x20DC3797, 0xB8597FE3, 0xDCE6964E, 0x434D8855, 0x55991234, 0xB3473D43, 0x457CDE9D, 0x9A662D66};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 108 ");
	}
	{
		static const bigint_t var_a = {0x44D0AA77, 0x16AF041A, 0x4B5D0177, 0xB287F87C, 0xDF8316FC, 0x5C2BB18B, 0xBFF2B4EE, 0x85344553};
		static const bigint_t var_expected = {0x50369330, 0xC2085BCB, 0x7D335B27, 0x094E7537, 0xDFF1B9AA, 0xC118ABF4, 0x2B7A6F78, 0x489825FA};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 109 ");
	}
	{
		static const bigint_t var_a = {0x5B1F5828, 0xE628FEFD, 0x2CC32C79, 0xFE7C7B17, 0x048B843E, 0x2ED8D002, 0x6E65327D, 0xA28480C6};
		static const bigint_t var_expected = {0x831BC685, 0xD581F844, 0x0E5E8DCA, 0xE77D0503, 0x4AC7C0E7, 0x7EF38A3C, 0x30CDB207, 0x1135A7BD};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 110 ");
	}
	{
		static const bigint_t var_a = {0x1BA1471F, 0x392DD547, 0xD3B4F3A9, 0x4F9FB144, 0xA7368741, 0x651C4768, 0xC9E6199C, 0x89BFFEE9};
		static const bigint_t var_expected = {0xCF08B45A, 0x88C83A84, 0x1F67584F, 0x1240BD2A, 0x6C83F926, 0x48EEE8F6, 0xEE1A7FB6, 0x686DAE9D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 111 ");
	}
	{
		static const bigint_t var_a = {0x21A3B2FD, 0x36FDF910, 0x3BFF997C, 0x567CDA5A, 0x45512A65, 0x661B3AD4, 0xADB0E7D1, 0x347BE9F4};
		static const bigint_t var_expected = {0xCBC25294, 0xC900D23A, 0x2CD9DA82, 0x3F798373, 0xD4590305, 0x87600174, 0x0FA93E13, 0x35CAA12F};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 112 ");
	}
	{
		static const bigint_t var_a = {0xC63A46A6, 0xD5FA7C45, 0x3BE60645, 0x64F0EBAB, 0x075784E4, 0xBC2902E6, 0xF672F04E, 0x2FFFC4AC};
		static const bigint_t var_expected = {0x71B7437A, 0x8A236EEC, 0x982DD53F, 0x963A39E0, 0x7F0D35A3, 0x680FE23B, 0xA65324A0, 0x861A2162};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 113 ");
	}
	{
		static const bigint_t var_a = {0xA20EEC28, 0xF45D9FE5, 0x0CF13F98, 0x8C91DBC8, 0xE7CF714E, 0xAFAAE2FB, 0x02C5E91C, 0x09052B2E};
		static const bigint_t var_expected = {0x219E5155, 0x8C733430, 0x1306E25C, 0x957C0861, 0x4C3ABF1B, 0xE371DFDD, 0x30A360FF, 0xAB15B329};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 114 ");
	}
	{
		static const bigint_t var_a = {0xE544C9C2, 0xFA5EDF09, 0x8EC51180, 0x423520A6, 0x9812CFA9, 0x78FAE625, 0x6D550168, 0x5FAAA329};
		static const bigint_t var_expected = {0x2ABB1EA0, 0x97CD7DC4, 0x91A87A3B, 0xEBD72135, 0x072E1F7E, 0xD9F078FB, 0x99853E4D, 0x7405A930};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 115 ");
	}
	{
		static const bigint_t var_a = {0xA5298D5C, 0x76A7631A, 0x67CBF4FB, 0x5BC64DA6, 0x68A3A840, 0x88B3A746, 0x43506B83, 0xB69E6BC9};
		static const bigint_t var_expected = {0x2BBEFA3B, 0xE490D9F5, 0x05F06926, 0x1B7C6244, 0x4A5E1DB2, 0xF7704B0B, 0x4556B770, 0x78AD146B};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 116 ");
	}
	{
		static const bigint_t var_a = {0x1107D743, 0x212EEB1C, 0x3808B4C7, 0x550A517A, 0xDA4A0D92, 0x72F08DC9, 0x2A38F40B, 0x47EF1BD2};
		static const bigint_t var_expected = {0x8C4E7DA7, 0x3125777D, 0x3B87A022, 0xB9CA80C3, 0x4C667EDF, 0xB065E2AD, 0x63DFDFDE, 0x61DDAC36};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 117 ");
	}
	{
		static const bigint_t var_a = {0x851AB35D, 0xB1BD5DB9, 0xE3098AA4, 0x2A24CA3F, 0x9E9ABE10, 0xC367D7B7, 0x1AA7FDE6, 0x3E89ECF2};
		static const bigint_t var_expected = {0x2B153C0D, 0x870C2E6A, 0xCE5B190A, 0xC8A5193C, 0xB14DE7FA, 0x59A3A73F, 0xDD80C3DE, 0x9C55A982};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 118 ");
	}
	{
		static const bigint_t var_a = {0x5220B1EF, 0xA48E1D9A, 0x6B53F614, 0xB0F3D9E1, 0x54CDF569, 0xBD09B0EC, 0xEA8AF6B9, 0x6311E748};
		static const bigint_t var_expected = {0xA4E9FD6C, 0xDB44CB0D, 0xBFA93AFD, 0x841ED884, 0xC4E88630, 0xF0DAF3B0, 0xB541CB94, 0x950855B7};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 119 ");
	}
	{
		static const bigint_t var_a = {0x48AB7AED, 0xA6330024, 0xF03B5385, 0xF3D9B7B4, 0x233F25F2, 0x6A7BC985, 0x5131E9D6, 0x5003CB3D};
		static const bigint_t var_expected = {0xB19642F2, 0xCDCF65D2, 0xB794351A, 0xCF9CF168, 0x2C052AB0, 0xC2D07AC7, 0x15B3E59D, 0x5832E3E9};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 120 ");
	}
	{
		static const bigint_t var_a = {0x9778F3A8, 0xA5625ED2, 0x9D75CFA1, 0xC34337D4, 0x8287F166, 0xC970DD3D, 0xFFDF8243, 0x5C8A276F};
		static const bigint_t var_expected = {0xA53D8E28, 0x13686F56, 0xDC47AED4, 0x952F452E, 0xF2E268A7, 0xC8EBC5DF, 0xC5581F96, 0x03E86BF8};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 121 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 122 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 123 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 124 ");
	}
	{
		static const bigint_t var_a = {0xC73D1359, 0x04126AA2, 0x01A57372, 0xB7DCE6AC, 0xFAF69529, 0x7693F581, 0x7ED7B845, 0x96992EC9};
		static const bigint_t var_expected = {0x14B4A3FA, 0x81807A2A, 0x6B0EA95C, 0x657749A6, 0xA76C8F6F, 0x38FA28F6, 0xDF7B4A37, 0xA85666C5};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 125 ");
	}
	{
		static const bigint_t var_a = {0x3C92FC86, 0xA4F67B1E, 0xBEB649C7, 0xF3291447, 0x9204A408, 0x06AAB832, 0x145BDF02, 0x987F57A4};
		static const bigint_t var_expected = {0x1E497E43, 0xD27B3D8F, 0xDF5B24E3, 0x79948A23, 0x49025204, 0x03555C19, 0x0A2DEF81, 0x4C3FABD2};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 126 ");
	}
	{
		static const bigint_t var_a = {0x022116B6, 0x5C6BDAFD, 0x9AD2F097, 0xF1F4E794, 0xB8D6E2F4, 0x6275D66B, 0x970E24F8, 0x92A10F4F};
		static const bigint_t var_expected = {0x81108B5B, 0xAE35ED7E, 0x4D69784B, 0x78FA73CA, 0xDC6B717A, 0x313AEB35, 0xCB87127C, 0x495087A7};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 127 ");
	}
	{
		static const bigint_t var_a = {0x8504A045, 0xE7CCC827, 0xC9D1A02E, 0xF0A35999, 0x4FC0279F, 0xD35A340F, 0x3FB5E89A, 0x222CF8A4};
		static const bigint_t var_expected = {0x73986A70, 0xF35DA8EC, 0x4F24BFBA, 0x81DA831D, 0x51D158AA, 0xE75D483D, 0x3FEA6261, 0x6E204BB3};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 128 ");
	}
	{
		static const bigint_t var_a = {0x263C5A96, 0x44E879E2, 0x52E44941, 0xD39AA8BB, 0xEC518E0D, 0xA673BEC3, 0xDC63BCC6, 0x4777FD7A};
		static const bigint_t var_expected = {0x131E2D4B, 0xA2743CF1, 0xA97224A0, 0xE9CD545D, 0xF628C706, 0x5339DF61, 0x6E31DE63, 0x23BBFEBD};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 129 ");
	}
	{
		static const bigint_t var_a = {0x58AAC3B1, 0x3851032C, 0xBB9F51D8, 0x8BB9EBEA, 0x08FA0CE6, 0xB12943D5, 0x0E803836, 0x2C7A8518};
		static const bigint_t var_expected = {0xDD6B7C26, 0x9B9FC66E, 0xC80B988F, 0xCF65CC45, 0x2E6E4B4D, 0xD644D020, 0x274F8A2F, 0x734711ED};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 130 ");
	}
	{
		static const bigint_t var_a = {0x09ED02AE, 0xC65C1A21, 0xB42C27BA, 0xFCD6800D, 0x1CC3A24D, 0xBA23F262, 0x0ACB9B0A, 0x464B2BD7};
		static const bigint_t var_expected = {0x84F68157, 0x632E0D10, 0xDA1613DD, 0xFE6B4006, 0x0E61D126, 0x5D11F931, 0x8565CD85, 0x232595EB};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 131 ");
	}
	{
		static const bigint_t var_a = {0x506CA6A7, 0xBC39D1B9, 0x40BF5366, 0xBCBCCB80, 0xDF9EB837, 0x2AA22723, 0x9CE76E87, 0x94F991F3};
		static const bigint_t var_expected = {0x594C6DA1, 0xDD942DB5, 0x8A9B9956, 0x67E73C10, 0x99C0A0F6, 0x130141C7, 0xEE832558, 0xA786985A};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 132 ");
	}
	{
		static const bigint_t var_a = {0xBFB04A65, 0x29B1BED6, 0x8DBBCED0, 0x4F1CD085, 0x0C30BA0A, 0x586BDA17, 0x1FA1E4E8, 0x6094AD42};
		static const bigint_t var_expected = {0x10EE3F80, 0x94502444, 0x3119D70B, 0xB1173E93, 0x3009A1DF, 0xA9E61B41, 0x2FE06088, 0x8D542602};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 133 ");
	}
	{
		static const bigint_t var_a = {0xFCEFEB37, 0xDF04CA31, 0x462582BA, 0x4C051F82, 0x3E217656, 0x2728BA93, 0xC7ADB7C8, 0x1E8CE763};
		static const bigint_t var_expected = {0xAF8E0FE9, 0xEEF9A9F1, 0x8D4EB100, 0xAF8B6611, 0x49020005, 0x91448B7F, 0x03E649F8, 0x6C504313};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 134 ");
	}
	{
		static const bigint_t var_a = {0x9F738935, 0xF7710808, 0xEB2D0E7A, 0xED57AC24, 0xC2993FB2, 0x7A10B994, 0x577CAE16, 0xA71F58C1};
		static const bigint_t var_expected = {0x00CFDEE8, 0xFB2FC8DD, 0xDFD276E0, 0x0034AC62, 0x0B3DE4B4, 0xBAB88B00, 0xCBCDC51F, 0xB0997BC1};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 135 ");
	}
	{
		static const bigint_t var_a = {0xB4A33031, 0x4BD55F9B, 0x4F9BA924, 0x8FB572F5, 0x1CA0F5C8, 0xBA47C5AA, 0xAB321ABB, 0xB5444468};
		static const bigint_t var_expected = {0x8B67B266, 0xA561F4A6, 0x1209C435, 0xD1638FCB, 0xB841BFBE, 0x5AD4110A, 0x75A87B72, 0xB7ABF195};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 136 ");
	}
	{
		static const bigint_t var_a = {0x3CE16E94, 0xF95F2933, 0x1B7E3883, 0x360175EE, 0x824CA438, 0x5649A1B4, 0x30FCC6B1, 0x6A20403F};
		static const bigint_t var_expected = {0x9E70B74A, 0xFCAF9499, 0x0DBF1C41, 0x1B00BAF7, 0x4126521C, 0xAB24D0DA, 0x987E6358, 0x3510201F};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 137 ");
	}
	{
		static const bigint_t var_a = {0x4903FF97, 0xE76D3D24, 0x74C0345F, 0xF35E9295, 0x0BE89F9B, 0x44055166, 0x27895B73, 0x0FFC5991};
		static const bigint_t var_expected = {0xD5981A19, 0x732DE36A, 0x249C09D3, 0x83381F9B, 0xAFE594A8, 0x1FB2D6E8, 0xB3D41BCE, 0x6507FC29};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 138 ");
	}
	{
		static const bigint_t var_a = {0x6BB47062, 0x38005981, 0xA9D337FF, 0xCB294A36, 0xD22F8900, 0x684CB42F, 0x6699460B, 0x3C40E278};
		static const bigint_t var_expected = {0xB5DA3831, 0x9C002CC0, 0x54E99BFF, 0x6594A51B, 0xE917C480, 0xB4265A17, 0x334CA305, 0x1E20713C};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 139 ");
	}
	{
		static const bigint_t var_a = {0x58F7F694, 0xDB55137E, 0x5FA8DF67, 0x7279DF71, 0x2C16D5A6, 0x4CAD0C6C, 0x560286E9, 0x0DD85A71};
		static const bigint_t var_expected = {0x2C7BFB4A, 0xEDAA89BF, 0xAFD46FB3, 0x393CEFB8, 0x160B6AD3, 0xA6568636, 0xAB014374, 0x06EC2D38};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 140 ");
	}
	{
		static const bigint_t var_a = {0xAD39D0B4, 0x0B211DB5, 0x31ADF982, 0xF53B0BDA, 0xAAC7797C, 0xB9B773F3, 0x796CB53E, 0x75E6138D};
		static const bigint_t var_exp = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xAD39D0B4, 0x0B211DB5, 0x31ADF982, 0xF53B0BDA, 0xAAC7797C, 0xB9B773F3, 0x796CB53E, 0x75E6138D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 141 ");
	}
	{
		static const bigint_t var_a = {0xAD39D0B4, 0x0B211DB5, 0x31ADF982, 0xF53B0BDA, 0xAAC7797C, 0xB9B773F3, 0x796CB53E, 0x75E6138D};
		static const bigint_t var_exp = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 142 ");
	}
	{
		static const bigint_t var_a = {0x7E2836C1, 0x40B5C8D4, 0x34F2683D, 0x3273F36D, 0xC43CFFB5, 0x4450C688, 0x8B48BFF9, 0x76BAF59D};
		static const bigint_t var_exp = {0x17A380F8, 0xD2A03C90, 0x55EF484B, 0x9FA26329, 0x730EE920, 0x4EEC6CB5, 0x1D2D9CC2, 0x8D32AD5C};
		static const bigint_t var_expected = {0x17BDF0F3, 0xC17255B9, 0x8D078056, 0xB37D1FDE, 0x7FC9F576, 0x66DDA83C, 0xED434FFE, 0x1FABCEE7};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 143 ");
	}
	{
		static const bigint_t var_a = {0xC1DE0F98, 0x2EB263A3, 0xCF7D0EB7, 0x0320346E, 0x0B803585, 0xDD12357A, 0xF76F4EE7, 0xA35C4E6F};
		static const bigint_t var_exp = {0x7D50118A, 0x7E90D664, 0xCD36DBF1, 0x5FA9528F, 0x0FB15FB9, 0x540774A1, 0x59A3EC1F, 0x6F372350};
		static const bigint_t var_expected = {0x89B91AEB, 0x06046804, 0xFB85643D, 0x69FB3F83, 0x2FBB757E, 0xD6F93ED4, 0x85BD8DFD, 0x4FFA0E6A};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 144 ");
	}
	{
		static const bigint_t var_a = {0x3A35A2D3, 0x43F7594D, 0x719AB10D, 0xA37A3EB2, 0xD06FAA2C, 0x19214B3F, 0xEFC8A616, 0x35D473A0};
		static const bigint_t var_exp = {0x49270C61, 0x0C31D253, 0x5726F3FF, 0x70BCCD19, 0xCF724CF9, 0xF208BE2E, 0x66D68EBC, 0x24E0B5F2};
		static const bigint_t var_expected = {0x937E1C8A, 0x16155AA3, 0x6B24BDD3, 0x99DD8C54, 0x11F64293, 0x8F3D482F, 0x3DFA75A9, 0xB9DAD5CA};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 145 ");
	}
	{
		static const bigint_t var_a = {0xA7B49A21, 0xC2901DC4, 0x1EEB34DE, 0xC6EBEA33, 0xD0FFF93A, 0x3B2C4338, 0xF515A4E9, 0x61E8124B};
		static const bigint_t var_exp = {0x92DE575A, 0xC34C7348, 0xC1F735AA, 0xB2E0DD85, 0x77F305FA, 0xE3988A82, 0x42ADC5C6, 0x7B158E95};
		static const bigint_t var_expected = {0x2512E9BA, 0x2FB2E52E, 0x6D2A3FDD, 0x012DF9BE, 0x96783981, 0xD41F7753, 0xA5707BCC, 0x7D0DF51F};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 146 ");
	}
	{
		static const bigint_t var_a = {0x3357DFC9, 0x11CEE3C3, 0xB9301F04, 0x6E550308, 0x7E656B06, 0x344F018B, 0x3102E9FA, 0xB568261D};
		static const bigint_t var_exp = {0xAB1C7B2F, 0x2DD2988F, 0x18F2EEA9, 0x4715CB7A, 0x0C4E0E1D, 0x1EBF26F1, 0x29C8FF0D, 0x86969404};
		static const bigint_t var_expected = {0x44F907E9, 0xA08C2481, 0x7F1C066B, 0xB9228464, 0x60304E57, 0x8EDAC2D1, 0xAC3796D4, 0x132AEE03};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 147 ");
	}
	{
		static const bigint_t var_a = {0x8B6EC62A, 0x7EE9C494, 0xBD8FBCC3, 0x4E285C42, 0x57E98A77, 0xA927EBEA, 0x9EB28754, 0x8DDD5BB9};
		static const bigint_t var_exp = {0x29C77647, 0x1464CEE1, 0xA839ADB3, 0x8F63CFFC, 0xD468E846, 0xDD730579, 0x98503896, 0x970814CB};
		static const bigint_t var_expected = {0x3753BD8F, 0x47C8C02A, 0xB1DB6785, 0xB050C670, 0x2731FAB4, 0xDA245D1F, 0x23E21754, 0x82A43071};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 148 ");
	}
	{
		static const bigint_t var_a = {0x22A0CAC1, 0x1C7F3CA0, 0x0359D93A, 0x35728CD2, 0x4B0943E9, 0x31064125, 0xABFBA316, 0x3D8F267E};
		static const bigint_t var_exp = {0xE352D4B2, 0x7FE9E154, 0xFF9FF510, 0x2CEFAD32, 0x5345E1B9, 0x992F1C75, 0x4CC92B05, 0x3E07FF24};
		static const bigint_t var_expected = {0x566ABC73, 0x6E0B0A0B, 0x2F9B94CE, 0x59983720, 0x23CA8CC4, 0x8405B176, 0xA15E2718, 0x8BD1A48C};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 149 ");
	}
	{
		static const bigint_t var_a = {0xCA99A324, 0xE2B94F96, 0xA59FF01D, 0xFD631839, 0x738974D6, 0x43A326FA, 0x753499C5, 0x8310CCDD};
		static const bigint_t var_exp = {0xEC13E887, 0xB81DFD1D, 0xEA73084A, 0xFD052EFF, 0x4E50CD75, 0x0A7B83DF, 0x43DE6006, 0x4B34DA0D};
		static const bigint_t var_expected = {0x12CD54AA, 0xAD608C8C, 0x95A9E741, 0x5FDFA1C4, 0x21334039, 0x411E44AB, 0x7016F903, 0xA8B23098};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 150 ");
	}
	{
		static const bigint_t var_a = {0xC00951A0, 0xD863ED3E, 0xA927DCBB, 0x998CCD40, 0xACA69E9E, 0xBF213CCA, 0x939E1847, 0x1EBCD3DB};
		static const bigint_t var_exp = {0x998D4714, 0x4920434D, 0x7551BB0C, 0x26307A2F, 0xCCB1B941, 0x2A7F5BBD, 0xB9340503, 0xD2474A1E};
		static const bigint_t var_expected = {0xC15845D8, 0x5EB03B76, 0xD2EE63BC, 0x395BD956, 0xF4B0502A, 0xC14D9E11, 0x5A9A52DA, 0xA2B68DF8};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 151 ");
	}
	{
		static const bigint_t var_a = {0x94858638, 0xC5AA7B75, 0xA706B993, 0x3749435B, 0xC363E8A6, 0x9358D135, 0xD9068C48, 0x3DF18934};
		static const bigint_t var_exp = {0x81C27398, 0xF904F2EB, 0xEDF166BD, 0x0540633F, 0x0F9D91C4, 0x3395F48C, 0x2B3B9ECA, 0x21204629};
		static const bigint_t var_expected = {0x2ED77CCE, 0xEB31C451, 0xD28384B1, 0xD33082DC, 0x30A2D27F, 0x20A51F3C, 0x8988BC10, 0x272CAEF1};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 152 ");
	}
	{
		static const bigint_t var_a = {0xAA1BBAB1, 0x827AFFC4, 0xB5616185, 0x41285574, 0xBEF7A2FF, 0x2B5FD7E9, 0x645D9C35, 0x31A35E89};
		static const bigint_t var_exp = {0x7784B782, 0xD2630826, 0xE0FBE85E, 0x3D6287F4, 0x9EA0B751, 0x9BD63BCF, 0x57F98D09, 0xCAD1ECC9};
		static const bigint_t var_expected = {0x50C65754, 0xA0524DA6, 0x0C3CF187, 0x67F76FCC, 0xA5DDB98E, 0x662B1B3A, 0xFD566E76, 0xB61A91CE};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 153 ");
	}
	{
		static const bigint_t var_a = {0x90736FA7, 0x75C8CF83, 0x3BD5A257, 0x0E16C442, 0x68F9CFAB, 0x0EBE8278, 0x5B246E66, 0x86275267};
		static const bigint_t var_exp = {0x91C4395E, 0x1EE96E68, 0x1BD3B9BE, 0xAF2D5D51, 0x3EF6924E, 0x1EAD6B05, 0x39E06BAA, 0x9EB7FF52};
		static const bigint_t var_expected = {0xBF55211A, 0x0F87018F, 0x3A851AF1, 0xCB60BF33, 0x1DF6B40C, 0xC42B81F6, 0xCF04C845, 0x331192D3};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 154 ");
	}
	{
		static const bigint_t var_a = {0x18A027B9, 0xA22F9FB6, 0xFD06F1B1, 0xA565E424, 0x17053A50, 0x016466E7, 0x4FDAA8A2, 0x5A2A3AAF};
		static const bigint_t var_exp = {0x24E343EB, 0x64E5A59C, 0xAA681612, 0x7AB322A1, 0xF3D21056, 0xB36200BC, 0x0F9A317F, 0xAF8200D1};
		static const bigint_t var_expected = {0x2BFCFBB7, 0xA822049D, 0xB5675B2D, 0x786CABBC, 0x767F8CA8, 0x4479E7FD, 0xE601A969, 0x45CF6040};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 155 ");
	}
	{
		static const bigint_t var_a = {0xCDE9B2F2, 0xD78877DA, 0xD0D25881, 0x25EBFBE9, 0x1B4CB2C6, 0xC374EBF2, 0x91CE0D41, 0x7C08246B};
		static const bigint_t var_exp = {0xC4FFBB15, 0x6FDDF6EA, 0xDB0A3E71, 0x028FB09D, 0x02B7197F, 0x94B1F07B, 0x54DA3BCF, 0x4D4AF30F};
		static const bigint_t var_expected = {0x4E4EDC21, 0xC5F35120, 0xE8A0E485, 0x4AB6E63E, 0x6C39D61A, 0xE94335BA, 0x825B8FA7, 0x7501D571};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 156 ");
	}
	{
		static const bigint_t var_a = {0xE1B80CE3, 0xE601222B, 0x8D002969, 0x5DC4A4DD, 0x6FF71883, 0x4A751EB9, 0xB0E943FD, 0x36A2D633};
		static const bigint_t var_exp = {0x4749D3BE, 0x461A2AAC, 0x3A35C4DD, 0xE5F530F0, 0xF1BDFA6A, 0x3A542ABB, 0xC72D1FA7, 0x099CC4D5};
		static const bigint_t var_expected = {0x8F6AE298, 0xC2B88877, 0xB5E25716, 0x17BC445E, 0x22BA1942, 0xFE27FD62, 0x5A92C021, 0x9C2FA0DE};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 157 ");
	}
	{
		static const bigint_t var_a = {0xD38AA119, 0x837768DC, 0x71752B53, 0x25FEB788, 0xCCEA1A38, 0x321D4EF2, 0xA774DF9A, 0x60CC8869};
		static const bigint_t var_exp = {0xC14DE88E, 0x3439C073, 0x9560F6C0, 0x06C8BA8D, 0x84EEC200, 0x5E955225, 0x65CA5007, 0xB48B53C2};
		static const bigint_t var_expected = {0x5B326733, 0x2CCB0FDA, 0x9C90C8A7, 0xFEA901B3, 0xF8940F09, 0x1699AD08, 0x32FB1AAF, 0xB909BC08};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 158 ");
	}
	{
		static const bigint_t var_a = {0xBEBC0A0E, 0x2EFFC680, 0x2DB903BE, 0xE42D7BD8, 0x9AF26F92, 0x2D87576E, 0x4B2B4398, 0x53763346};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 215 ");
	}
	{
		static const bigint_t var_a = {0xE05CDFC6, 0x6A1981C5, 0xB7186899, 0xF0D5BF01, 0x94F4FE3D, 0xF16AB684, 0xC212ACE4, 0x1A19C372};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 216 ");
	}
	{
		static const bigint_t var_a = {0x09FC9857, 0xABE3915E, 0xDF1BE8CD, 0x479A23BF, 0xBA36EB19, 0xE6F12FA0, 0x5D552356, 0x80D7DBBF};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 217 ");
	}
	{
		static const bigint_t var_a = {0x64939829, 0xA1743790, 0xEA42294D, 0x33AB0A39, 0x31B609EB, 0x7FB5E5F8, 0x44F42F62, 0x339A6A00};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 218 ");
	}
	{
		static const bigint_t var_a = {0x91011445, 0xBEAD45FB, 0x53A7D459, 0x59A06A79, 0x277CF419, 0x08600761, 0x8564392C, 0xA80D81C4};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 219 ");
	}
	{
		static const bigint_t var_a = {0xB4E62D3C, 0x5E0C456E, 0x336AF787, 0xCEB4D9CB, 0x4DB7B65B, 0x4C1526D0, 0x46FA184A, 0x9ADB5B6E};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 220 ");
	}
	{
		static const bigint_t var_a = {0xB4C87F19, 0xFC0EB3F2, 0x45F80017, 0x958C2013, 0x8875C605, 0x894CDA82, 0xBBB8071B, 0x39CD556D};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 221 ");
	}
	{
		static const bigint_t var_a = {0xA79B65E3, 0x732AD6AF, 0x5EB7E05E, 0x738CED27, 0x875A0408, 0x8CB9770F, 0xE9CD75D7, 0x4A14A3C4};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 222 ");
	}
	{
		static const bigint_t var_a = {0xA31997A0, 0x79750B95, 0x22755083, 0x08FD5C6A, 0x53417567, 0xFB33D225, 0x192347C6, 0x35EAD738};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 223 ");
	}
	{
		static const bigint_t var_a = {0x4DBC380C, 0x3E56AB24, 0x7B946411, 0x5F041045, 0x6EBEFC41, 0x2595AB0B, 0xDE548611, 0xB46F5D4C};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 224 ");
	}
	{
		static const bigint_t var_a = {0x52A6A672, 0x4E71FE62, 0x0C367C8B, 0x960FF0B9, 0x75FC7B19, 0x251C7B31, 0x21F72E36, 0x57E91C70};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 225 ");
	}
	{
		static const bigint_t var_a = {0x7050A802, 0x481FAA32, 0xF328DA40, 0x39B94686, 0xC90AE149, 0x2AD771BA, 0x290C482C, 0xA2E8DAEC};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 226 ");
	}
	{
		static const bigint_t var_a = {0x66C35FAA, 0xA24C9727, 0xA3799BE7, 0x2FFEC469, 0x906D884E, 0x15A0DABF, 0x45D7C22F, 0x6C8BB752};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 227 ");
	}
	{
		static const bigint_t var_a = {0x5D7038DF, 0xD0736032, 0x10675587, 0xDA7EDA62, 0x065A2E18, 0x3D84BF41, 0xF2FDBE41, 0x9CFA7B42};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 228 ");
	}
	{
		static const bigint_t var_a = {0xF0B58840, 0x0DCCA253, 0xF500B186, 0xD43F5CE1, 0x1CBACEF5, 0x7D3FE7B3, 0xD5373706, 0x93CA5107};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 229 ");
	}
	{
		static const bigint_t var_a = {0xD4256FE1, 0xFD389289, 0x3D263D2E, 0x41662716, 0x239C2992, 0x0B09C458, 0x72CD42A3, 0xA6DD93CF};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 230 ");
	}
	{
		static const bigint_t var_a = {0xE1AE768C, 0xCB95923E, 0x19ED754E, 0x8F42FDDD, 0xE8C8FD3D, 0x8FFD685C, 0x6E2AC52B, 0x0D5AF1E2};
		static const bigint_t var_expected = {0xE1539565, 0x22AD39EF, 0xC64161F9, 0x1D8452A7, 0xFC9DEDEC, 0x58FFF81A, 0x23A80402, 0x07145F14};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 231 ");
	}
	{
		static const bigint_t var_a = {0x7748578F, 0xE8B581A6, 0x11FB05DC, 0x137E1962, 0xF96057C5, 0xD786C7E9, 0x53D3BF49, 0x4A79F442};
		static const bigint_t var_expected = {0x9FD7E35C, 0x98BD9006, 0x3BBC35DB, 0x6C231BC0, 0xD06D5797, 0xF32D8448, 0x48CAB93A, 0x26C44682};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 232 ");
	}
	{
		static const bigint_t var_a = {0x7FCE607C, 0xAAA671E1, 0x3268464F, 0xC297839F, 0x1DE3EA0C, 0xB7514713, 0xAF98035A, 0x736F2B4D};
		static const bigint_t var_expected = {0xDBB6FE36, 0x4D5CFBF0, 0xDD0A933A, 0x0DD88437, 0x479113AF, 0x5AD49A22, 0x6270F3BA, 0x30AC7610};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 233 ");
	}
	{
		static const bigint_t var_a = {0xCA07BD7D, 0xCDB56344, 0xF3C37D56, 0x31571AF8, 0xC0FC676D, 0x119EA16F, 0xDCC72831, 0x16113C1E};
		static const bigint_t var_expected = {0xF6FA1ED6, 0x872DB6D4, 0x3B628553, 0x0C630D44, 0x81F1B506, 0xB9903743, 0x02E76059, 0x6CC9551D};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 234 ");
	}
	{
		static const bigint_t var_a = {0xD0511D41, 0x564D6010, 0x524645DD, 0xC56876EA, 0xC39835AC, 0xF5E5A34C, 0xE8553D2E, 0x3C04FA1F};
		static const bigint_t var_expected = {0x29CE8573, 0xDC3A40A1, 0x35C733CB, 0xFF086592, 0x58D078DB, 0x50D7A42B, 0x62619096, 0x3D7252A6};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 235 ");
	}
	{
		static const bigint_t var_a = {0x4762128A, 0x532DE40A, 0x938DEE86, 0x4559EE22, 0x107DAEBD, 0xD136E03B, 0xDE465E1C, 0x2DB4F4B0};
		static const bigint_t var_expected = {0x49B8A818, 0xB81B84E1, 0x7BC565AD, 0x23B630F1, 0xBF960F74, 0x6E74177A, 0x9A1100DA, 0x34C9FD76};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 236 ");
	}
	{
		static const bigint_t var_a = {0x9B6C442F, 0xC29A479F, 0x6277A308, 0x38520411, 0x3B9F5FFA, 0x7A7DBC97, 0xE9B842E4, 0x6E620996};
		static const bigint_t var_expected = {0x25A2C2B6, 0x5B3740B0, 0x846C4D8F, 0x94CB41DC, 0x55F7D36D, 0xA696F758, 0x244CACEC, 0x8838EA55};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 237 ");
	}
	{
		static const bigint_t var_a = {0x0B944FCA, 0x33662A3B, 0x1D2E0729, 0x5815AB5A, 0xCECF0DCA, 0x4AAF49AA, 0x6AEE33FC, 0x5D5E7260};
		static const bigint_t var_expected = {0x428D23D3, 0xDA9294B6, 0xB9A74534, 0x7891ECEF, 0x456B5B62, 0x873FB6F6, 0xD438CDE8, 0x0D97B66A};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 238 ");
	}
	{
		static const bigint_t var_a = {0xCC5F5097, 0x5BFDF3DB, 0x446E47B7, 0xF87E8ABB, 0x0AE3D8C1, 0xDBFCB087, 0x7345271D, 0x565D35F1};
		static const bigint_t var_expected = {0xBD68CE97, 0x39D8E495, 0xF2BC666E, 0x2844BB3B, 0x35C50D63, 0x1ABD912D, 0x9E54A9B3, 0xA80625D5};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 239 ");
	}
	{
		static const bigint_t var_a = {0x27C48B5C, 0x9086E9CE, 0x11AA53A5, 0x652341AA, 0x6D7D5AE4, 0xAB34EA37, 0x42C7DD9F, 0x7FCF81F1};
		static const bigint_t var_expected = {0x58AC2FB2, 0x6635F5DC, 0xA9F3D526, 0xFC9984AB, 0xFA54A9CF, 0xD20D380D, 0x1386746B, 0x7C1BA5C0};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 240 ");
	}
	{
		static const bigint_t var_a = {0x6FCD9B33, 0x370CB2E4, 0xFFD766C9, 0x1C9B68F8, 0x5B7DC35E, 0xA8D7FB96, 0x4A25D028, 0x8B329110};
		static const bigint_t var_expected = {0x7121EDA9, 0x8204FD38, 0x69DD23D9, 0x06529876, 0xE24B7506, 0x2FEC3D61, 0xF4CFEFD1, 0xAA6C853E};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 241 ");
	}
	{
		static const bigint_t var_a = {0x1F2866CA, 0x85CDF27D, 0x7ACDDFEB, 0x9FAEB8E7, 0x03E5CE08, 0x8E234147, 0x1A391048, 0x554D01E7};
		static const bigint_t var_expected = {0x0E32A9AA, 0x0FC86E58, 0x45D83821, 0xAFD82F7A, 0xE854EAB6, 0x5AA25036, 0x62C6EC58, 0x431E144C};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 242 ");
	}
	{
		static const bigint_t var_a = {0x9087A57D, 0xCFB86048, 0x0A210392, 0x22F78DF7, 0x599ECFE7, 0x7465504E, 0xAEC03227, 0x73B6CD1A};
		static const bigint_t var_expected = {0x4B901EF4, 0x0A30D7E4, 0x164E042F, 0x8BACFEAA, 0x951FCB2A, 0x2CBF4DE9, 0x47E8A432, 0x2BAD15A5};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 243 ");
	}
	{
		static const bigint_t var_a = {0xEECDF412, 0x405A10AA, 0x05A0EF71, 0x68316D75, 0xEDB8C9A9, 0x153CBC25, 0xECA842B2, 0x90E878D8};
		static const bigint_t var_expected = {0x229A4994, 0xD421E485, 0x141B12FD, 0x5394D28C, 0x46C910F7, 0x1E3D7DE2, 0xBF0E31A9, 0x182E75A1};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 244 ");
	}
	{
		static const bigint_t var_a = {0xB0883883, 0x02C3AE74, 0x495AC765, 0x7048A74C, 0xCABD96C7, 0x3E2F01C4, 0x44B3138E, 0x24355A1B};
		static const bigint_t var_expected = {0x2229D70B, 0x1E17E3C7, 0x7C8D7AC6, 0x01EDBC99, 0xC3782C0A, 0xA83E215A, 0x29F494DD, 0x8FD212FD};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 245 ");
	}
	{
		static const bigint_t var_a = {0x0C94ED22, 0x3BECACAD, 0xA94F6FF2, 0x43976E26, 0x8C51E41F, 0x1290D591, 0x976D69A3, 0x28EAA05F};
		static const bigint_t var_expected = {0x04C972FB, 0x6FC22B01, 0x550EABF4, 0xD9774E39, 0x799E8E7B, 0x6CFEA8B2, 0xE88ACA33, 0x2FE9A578};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 246 ");
	}
#else
	{
		static const bigint_t var_a = {0x1BBC5044, 0xB57276D8, 0xB2816B94, 0xBBD6A51E, 0xD3970EBA, 0x7D616700, 0xB7C5F6DB, 0x2C96C56C};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 245 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 246 ");
	}
	{
		static const bigint_t var_a = {0xB86F4B88, 0xCF01E617, 0xBBC77EC3, 0x38D4B50E, 0xBE1EE6D1, 0xB4A19C30, 0xE599139A, 0x726BE3D3};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 247 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 248 ");
	}
	{
		static const bigint_t var_a = {0x6EBE0CFC, 0xA26CFA57, 0x41121DB9, 0x6E903513, 0x44B9E269, 0x448CDF1D, 0xC89CA8C0, 0xC7CFF7E3};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 249 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 250 ");
	}
	{
		static const bigint_t var_a = {0x18C41515, 0xECB626FB, 0xDD307BAB, 0x75264A59, 0xE72E61C6, 0x682FAD33, 0xAE1B92F1, 0x12F9E212};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 251 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 252 ");
	}
	{
		static const bigint_t var_a = {0x22622B5A, 0xCDD3A083, 0x9CD1C630, 0x2811C705, 0x799B1171, 0x7E1A4121, 0x1903F7DF, 0xBAC802ED};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 253 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 254 ");
	}
	{
		static const bigint_t var_a = {0x0EDEE91D, 0x48AEE253, 0x7D5B3003, 0xA6DFC80B, 0xA125E600, 0x88DECEA9, 0x41110221, 0x2D3883B8};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 255 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 256 ");
	}
	{
		static const bigint_t var_a = {0xF3CFBDA3, 0xC5C1135E, 0xF7986579, 0xD3F94183, 0x5D05B203, 0xAC1E3B45, 0x90D89EE6, 0x5DD59FA4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 257 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 258 ");
	}
	{
		static const bigint_t var_a = {0xF9609C78, 0x9242DDE0, 0x7032C762, 0xD474AB25, 0x7BDA3251, 0xB530B6AB, 0x2492E452, 0x3E4FE80B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 259 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 260 ");
	}
	{
		static const bigint_t var_a = {0xDED914DA, 0x5DD66ADE, 0xC6F8E2D5, 0x97F74B6B, 0x1E537E8C, 0x8F4DDA90, 0x50C0187E, 0x4A12DA60};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 261 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 262 ");
	}
	{
		static const bigint_t var_a = {0x748195FF, 0xBCDC9910, 0xCAFFFC06, 0x49AFC6DF, 0x3F220E7E, 0xCE512F05, 0x1BA173DC, 0xFDF46034};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 263 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 264 ");
	}
	{
		static const bigint_t var_a = {0x20CBFDFA, 0xA54799BB, 0xC188B16B, 0xDD53E4A8, 0x2A46E43D, 0x280E362F, 0xBF70106C, 0x58F41066};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 265 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 266 ");
	}
	{
		static const bigint_t var_a = {0x5DD5D7AE, 0xF6037CE6, 0xE2BCF947, 0x8C3CC8E6, 0xFD9E81DA, 0xF6275D4F, 0x2B7CB3F6, 0x62002BF6};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 267 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 268 ");
	}
	{
		static const bigint_t var_a = {0x3738D309, 0xEEF17F2F, 0xDA371D40, 0x4F840389, 0x2CD5A846, 0xB889814C, 0x820350BE, 0xA2D8BE21};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 269 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 270 ");
	}
	{
		static const bigint_t var_a = {0xD1235B50, 0xB26D0BA8, 0x4A625AB2, 0x673E3870, 0x009027DD, 0x8E63DC58, 0x9AEC771E, 0xA7F87B69};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 271 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 272 ");
	}
	{
		static const bigint_t var_a = {0xDFCE61BE, 0xC967A3E2, 0x489C4F6A, 0xD6BA3E38, 0x13FC1FB7, 0xBFBB8099, 0x7E451F08, 0x809403E4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 273 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 274 ");
	}
	{
		static const bigint_t var_a = {0x2C35BB34, 0xA00D5CA3, 0xDA376FB7, 0xE3DAFED2, 0xD5A18C66, 0x368FCA1C, 0xED965DC0, 0x44A5CDC4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 275 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 276 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 277 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 278 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 279 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 280 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 281 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 282 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 283 ");
	}
	{
		static const bigint_t var_a = {0x1626A1F6, 0x08028671, 0x7E43080F, 0x9A756F30, 0x0A8CF863, 0x008261D6, 0xD80617F6, 0x8C05F350};
		static const bigint_t var_b = {0xAB77061A, 0xB43710ED, 0xD0ACCEE2, 0x37BAC0EB, 0xF6DC1BEE, 0xD3BF555D, 0xA72BDAEC, 0x3A89CFD1};
		static const bigint_t var_expected = {0x5F717375, 0xBD4B0DAD, 0x7A77F7AA, 0xBF1E837B, 0xAD868A9C, 0xD8E15AC8, 0x3F1316B9, 0x0C7C2460};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 284 ");
	}
	{
		static const bigint_t var_a = {0x188E4048, 0xBAEFA53C, 0x330209FB, 0x050F5F9F, 0x80FB9B53, 0x7AACF805, 0xF56A68BD, 0x9DA1A702};
		static const bigint_t var_b = {0x4FA8197C, 0x1A56BAC8, 0x01FF58FA, 0x23F1CDDA, 0x6CDC59B9, 0x7B845499, 0x90536F57, 0xAEDA56F1};
		static const bigint_t var_expected = {0x060A2529, 0xD657D653, 0x608983AE, 0x15EF80D8, 0x99F56B57, 0xFAD0F033, 0x459EFBEB, 0x92685F32};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 285 ");
	}
	{
		static const bigint_t var_a = {0x00B3D2B4, 0x335795C3, 0x87CC57AA, 0xAC3BC96E, 0xCD5398CE, 0x73AD06BE, 0x3A19BC02, 0x13F27A53};
		static const bigint_t var_b = {0x10F140D0, 0x46AD4D27, 0x83DC57ED, 0x38DC7056, 0x87D01FA6, 0x9A36677A, 0x2BC7DCAB, 0xAC4340A5};
		static const bigint_t var_expected = {0xAF78DEE9, 0x7B165938, 0x3730D050, 0xD2068D24, 0x01412EBF, 0x128311CE, 0x25C2BC85, 0x06221C36};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 286 ");
	}
	{
		static const bigint_t var_a = {0xB14F0C95, 0xFF10F28F, 0x2C5D6B01, 0xB2F470DB, 0xDA6CD90F, 0x60890AAC, 0x4C29AE5B, 0x788BB694};
		static const bigint_t var_b = {0xAD6A4061, 0xE9B779F5, 0xFF614738, 0x93644632, 0x291CB006, 0xCDC920CD, 0x3DD78C74, 0x67410332};
		static const bigint_t var_expected = {0xFC8D185B, 0xE9D9E2D3, 0x5746D2F3, 0x33470A6D, 0xAFA6FF61, 0x32F1CF0E, 0x49E25EA7, 0x25B91B04};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 287 ");
	}
	{
		static const bigint_t var_a = {0x0338B931, 0xF461ECA5, 0x1AD7027D, 0x06531536, 0xD8E56112, 0x0E270FCC, 0x903AD855, 0x32CEC508};
		static const bigint_t var_b = {0xC313A250, 0xF4901462, 0x8B13BB41, 0x7B35F60C, 0x1EBECAAA, 0xF6FBB8B3, 0x8B2000E1, 0x974C3738};
		static const bigint_t var_expected = {0x642026E6, 0xEA037756, 0xD172DE78, 0x6E775EA1, 0xA3C1A207, 0x09C26C14, 0xDB3BFD0E, 0x10075D7E};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 288 ");
	}
	{
		static const bigint_t var_a = {0x32C277E1, 0x2272AE9D, 0x054B3317, 0x12C3432E, 0x34E9D403, 0x7EBEB858, 0x6ADDA4F5, 0x1D31E6D0};
		static const bigint_t var_b = {0x2FCC9075, 0x98F1E492, 0x7CA4B3F5, 0x7A5E7D7B, 0x74021127, 0x35C5C6B7, 0x1CFB5BEB, 0x377E17C1};
		static const bigint_t var_expected = {0x628F0856, 0xBB64932F, 0x81EFE70C, 0x8D21C0A9, 0xA8EBE52A, 0xB4847F0F, 0x87D900E0, 0x54AFFE91};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 289 ");
	}
	{
		static const bigint_t var_a = {0xE1916971, 0xD75C8E07, 0x600C5D36, 0xB78F125D, 0x9701B569, 0xE5ED706D, 0x41E3DFF9, 0x7FD1125A};
		static const bigint_t var_b = {0x0D25D317, 0x454106F7, 0x67474964, 0x5AE34FB6, 0x7852F3D0, 0xEC6783C5, 0x32CA0F24, 0x7E1FAB4B};
		static const bigint_t var_expected = {0x8C8B07ED, 0x1DAF0B4D, 0xF2DBC754, 0xFF60B572, 0xBB721F84, 0xD6F497C7, 0x348F12F5, 0x43DD1EE3};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 290 ");
	}
	{
		static const bigint_t var_a = {0xA8D9D9A0, 0xA8D90A4C, 0xE3C0F3FA, 0xA6D9D898, 0xF2EA6C06, 0xD05FC6A5, 0x3995EEE8, 0x83481642};
		static const bigint_t var_b = {0x5A03E604, 0xADB6E689, 0x4C86AA58, 0x0F3B5170, 0x62222A1C, 0xC0209552, 0x142D92C8, 0x2B2593F3};
		static const bigint_t var_expected = {0x02DDBFA4, 0x568FF0D6, 0x30479E53, 0xB6152A09, 0x550C9622, 0x90805BF8, 0x4DC381B1, 0xAE6DAA35};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 291 ");
	}
	{
		static const bigint_t var_a = {0xE5E6A9CD, 0x63A2A8C7, 0xD8689141, 0x1AD2AE6D, 0xC743148A, 0xFBA4F7AE, 0xB63CE6A4, 0x7D0A301B};
		static const bigint_t var_b = {0xD752A4F3, 0xC012A56B, 0xBDE98B0D, 0x1D355F2C, 0xFC2C783D, 0x8316E820, 0x47EB3A28, 0x2727D655};
		static const bigint_t var_expected = {0xBD394EC0, 0x23B54E33, 0x96521C4F, 0x38080D9A, 0xC36F8CC7, 0x7EBBDFCF, 0xFE2820CD, 0xA4320670};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 292 ");
	}
	{
		static const bigint_t var_a = {0xD6137490, 0x1BD85E61, 0xF252A5C4, 0x7DF5DC6C, 0x81ECC2A1, 0x695F874E, 0x1FD7219E, 0x458F2BD0};
		static const bigint_t var_b = {0x3C10348D, 0xB05A7D24, 0x929AB3A3, 0xD2DE3CF7, 0x566C7B5B, 0x66AA0190, 0x0F0C2B22, 0x3B219EEA};
		static const bigint_t var_expected = {0x1223A91D, 0xCC32DB86, 0x84ED5967, 0x50D41964, 0xD8593DFD, 0xD00988DE, 0x2EE34CC0, 0x80B0CABA};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 293 ");
	}
	{
		static const bigint_t var_a = {0x94978D05, 0x20145956, 0x546D33FC, 0x649AAB29, 0x7AD8234C, 0x5E52FC0D, 0xD8669E9A, 0x3AE35680};
		static const bigint_t var_b = {0x08DF5A6D, 0xEE3D20C7, 0x35602EC0, 0x0CBE8609, 0x12C1438C, 0xC4476F2B, 0xF15E5BB7, 0x5CD2A725};
		static const bigint_t var_expected = {0x9D76E772, 0x0E517A1D, 0x89CD62BD, 0x71593132, 0x8D9966D8, 0x229A6B38, 0xC9C4FA52, 0x97B5FDA6};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 294 ");
	}
	{
		static const bigint_t var_a = {0xA308AC04, 0x032F85C1, 0xDA74CAC9, 0xDFC9E5CB, 0x4866C4D2, 0x51F77841, 0x45BB39EE, 0x2985BA18};
		static const bigint_t var_b = {0x97F61782, 0x2A7B1920, 0x7B99A096, 0xD20B07E0, 0xBC56F87A, 0x3F94AF09, 0x732FB9BF, 0x00E5A3FD};
		static const bigint_t var_expected = {0x3AFEC386, 0x2DAA9EE2, 0x560E6B5F, 0xB1D4EDAC, 0x04BDBD4D, 0x918C274B, 0xB8EAF3AD, 0x2A6B5E15};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 295 ");
	}
	{
		static const bigint_t var_a = {0xFD498982, 0x94AFEB4A, 0xFAED49EC, 0x177559D8, 0x16C91E75, 0x06A4716A, 0x8D2EAE55, 0xAC9877E4};
		static const bigint_t var_b = {0x25F39692, 0x57F10C4D, 0xA48C291E, 0x5C43F055, 0xCE743CD1, 0xBB7ECCDF, 0x199582D8, 0x297FF753};
		static const bigint_t var_expected = {0xC110EB79, 0xEDB26DE6, 0xCB0193C3, 0x60A79D8D, 0x915AD191, 0xC6C2E1DE, 0x66A55504, 0x1C04D075};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 296 ");
	}
	{
		static const bigint_t var_a = {0x1D6560F6, 0xE6D05D65, 0xBF74BEF0, 0x4D05A901, 0xABCEE954, 0x85A4A353, 0x93EB3F35, 0x276C146A};
		static const bigint_t var_b = {0x54574756, 0xA36739E2, 0xAF96F39E, 0x56FB4B41, 0xFDD2D0DC, 0x51D4511E, 0x69410D87, 0x42263E13};
		static const bigint_t var_expected = {0x71BCA84C, 0x8A379747, 0x6F0BB28F, 0xA400F443, 0xA9A1BA30, 0xD778F472, 0xFD2C4CBC, 0x6992527D};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 297 ");
	}
	{
		static const bigint_t var_a = {0xE12D4360, 0x4A42790B, 0xF46354B5, 0x4046914A, 0x0725AE4D, 0x0B262AEA, 0x3DDF3E00, 0x6D759408};
		static const bigint_t var_b = {0x3F7E7276, 0x81F754AA, 0x302426B4, 0x8E16DBD9, 0x9507709F, 0x6366D3AB, 0xA72EB5E8, 0x86E2710F};
		static const bigint_t var_expected = {0xBE7F813B, 0xCD4B4404, 0x500F9C22, 0xBB4BC083, 0x484A9537, 0x732CA22A, 0xA4EF17BF, 0x3A446655};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 298 ");
	}
	{
		static const bigint_t var_a = {0xA43A39B5, 0x508BECC5, 0xF7CD3BAC, 0xC49B6A98, 0xC3B98D45, 0x1E686994, 0x316B5469, 0x1D7A2D1E};
		static const bigint_t var_b = {0x1E3EF5D9, 0xA22DA156, 0x7D898550, 0xCF4C38A6, 0x286AE743, 0x9DC3EBDD, 0x99DA4393, 0x3EC4E280};
		static const bigint_t var_expected = {0xC2792F8E, 0xF2B98E1B, 0x7556C0FC, 0x93E7A33F, 0xEC247489, 0xBC2C5571, 0xCB4597FC, 0x5C3F0F9E};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 299 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 300 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 301 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 302 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 303 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 304 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 305 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 306 ");
	}
	{
		static const bigint_t var_a = {0x288C41EE, 0xC9C6C34B, 0xEA23F9FC, 0x28EC720C, 0xB4F6FB57, 0x74ABF9D8, 0x1252E4D1, 0x4582EC0A};
		static const bigint_t var_b = {0x1679912F, 0xF66A1F84, 0x0101D6EA, 0xB160D566, 0xD2C42AB2, 0xD007F43C, 0x03C5B1CB, 0x0B3934E1};
		static const bigint_t var_expected = {0x1212B0BF, 0xD35CA3C7, 0xE9222311, 0x778B9CA6, 0xE232D0A4, 0xA4A4059B, 0x0E8D3305, 0x3A49B729};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 307 ");
	}
	{
		static const bigint_t var_a = {0x475CE15C, 0xC51966D6, 0xAAB6E488, 0xC3C3A5FE, 0xF3442C98, 0x1506F011, 0x064C6B23, 0x02F75392};
		static const bigint_t var_b = {0x7B496BF5, 0xB0F86B04, 0xBBF5B84F, 0x6FAFAE57, 0x51D61420, 0x2F42AEAD, 0xE9F06356, 0x006B2464};
		static const bigint_t var_expected = {0xCC137567, 0x1420FBD1, 0xEEC12C39, 0x5413F7A6, 0xA16E1878, 0xE5C44164, 0x1C5C07CC, 0x028C2F2D};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 308 ");
	}
	{
		static const bigint_t var_a = {0xE0C6C931, 0x96693371, 0x025ECFFE, 0x513F17B2, 0x8143EDC2, 0x3C4E976A, 0xF2F2C65A, 0x2A8B8822};
		static const bigint_t var_b = {0xF4A1450B, 0x3E026C2E, 0x95D0AE4E, 0x20D7668F, 0x4151D489, 0x07940269, 0x9422FE4A, 0x3C16D562};
		static const bigint_t var_expected = {0x4E51B8C1, 0x575550F4, 0x410600F7, 0x43795DC3, 0x93D4A2EE, 0x301AF16C, 0x9EEEA439, 0xA8885182};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 309 ");
	}
	{
		static const bigint_t var_a = {0xEDB64C6C, 0xCECA4EC2, 0x7E71D282, 0x94417C1D, 0xA335C408, 0x734AE256, 0x3B765870, 0xA07215E0};
		static const bigint_t var_b = {0xB67EA3D8, 0x53AE7AAB, 0xE5425C0D, 0x933C0211, 0x3564D8F1, 0x09926233, 0xC66490A4, 0x0BEC15BD};
		static const bigint_t var_expected = {0x3737A894, 0x7B1BD417, 0x992F7675, 0x01057A0B, 0x6DD0EB17, 0x69B88023, 0x7511C7CC, 0x94860022};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 310 ");
	}
	{
		static const bigint_t var_a = {0xCCC9DAE7, 0x3D210971, 0x67E7444F, 0xC86F35BF, 0xDA16832F, 0x770640C9, 0x46A6103C, 0xB7633FC9};
		static const bigint_t var_b = {0x5F726EA2, 0xE17B1F13, 0xC044BCB6, 0x104FF9B4, 0xF7622EF5, 0x151F2999, 0x44882363, 0x26E87C2B};
		static const bigint_t var_expected = {0x6D576C45, 0x5BA5EA5E, 0xA7A28798, 0xB81F3C0A, 0xE2B4543A, 0x61E7172F, 0x021DECD9, 0x907AC39E};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 311 ");
	}
	{
		static const bigint_t var_a = {0xBA68504C, 0xF5788635, 0x72C5BF53, 0x57799557, 0x93E610A6, 0x495F37F2, 0x78C75680, 0x48D9EE5D};
		static const bigint_t var_b = {0xF275DDDB, 0x16528EE7, 0xF864DB4A, 0x5B181B14, 0x9291A016, 0x3E773974, 0xD373AFD4, 0xB3E5855C};
		static const bigint_t var_expected = {0x2A1EA70C, 0xDE1480FF, 0x4ED8C350, 0x0F7326E3, 0x5536FA45, 0x06485AE9, 0xE57282D5, 0x4F0807C2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 312 ");
	}
	{
		static const bigint_t var_a = {0x35C61A81, 0x4504BAF0, 0x94E82C0E, 0xEAB98D3C, 0x7C597700, 0x2A7434B6, 0x7601B045, 0x6CB674F3};
		static const bigint_t var_b = {0x03FD9CAE, 0x6643F203, 0xD26B0643, 0xEF192BDD, 0x0326812C, 0xF77FDD91, 0xB9446655, 0x055FCEDF};
		static const bigint_t var_expected = {0x31C87DD3, 0xDEC0C8ED, 0xC27D25CA, 0xFBA0615E, 0x7932F5D3, 0x32F45725, 0xBCBD49EF, 0x6756A613};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 313 ");
	}
	{
		static const bigint_t var_a = {0xF9ADFCE3, 0xC02B7CD3, 0x0255AB49, 0x69C9B10B, 0x80A9FAA6, 0x9BB65D76, 0x25AFFE96, 0x7DD6741C};
		static const bigint_t var_b = {0x795F766F, 0x7F943B0C, 0x72AB00B7, 0x23E2EA3C, 0x2756FB6F, 0xD07CA08A, 0x7A6973E5, 0x7B340A63};
		static const bigint_t var_expected = {0x804E8674, 0x409741C7, 0x8FAAAA92, 0x45E6C6CE, 0x5952FF37, 0xCB39BCEC, 0xAB468AB0, 0x02A269B8};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 314 ");
	}
	{
		static const bigint_t var_a = {0x0355A7FA, 0x359E44B7, 0x3286279F, 0xFD0B3F24, 0xCE65C5BA, 0x5DFACCF8, 0xAAAE350C, 0x129D9420};
		static const bigint_t var_b = {0xC90F1F64, 0x55D00560, 0x72543EE9, 0x06A15FA7, 0xCEDF5E1A, 0xB6752B2D, 0x1C22E38E, 0xA105A702};
		static const bigint_t var_expected = {0x9C72BD31, 0xDEBCC907, 0x94A9C7FC, 0x097B8C1D, 0x5368F156, 0xA2E5FE36, 0xCEAA2DA6, 0x2BAB8BE0};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 315 ");
	}
	{
		static const bigint_t var_a = {0x912927FC, 0xB7608859, 0xD8BEA78C, 0x104228F2, 0xD14228BD, 0x71852C11, 0x6AB17FA8, 0x0686EDFC};
		static const bigint_t var_b = {0x3453AECA, 0x171C8A14, 0xFBE10453, 0x346B2F74, 0x599B6C73, 0xC7706DAB, 0xE326D9C5, 0x29A5D5A1};
		static const bigint_t var_expected = {0xBF01ADCD, 0x9F3287F6, 0xB1558280, 0xEEE8A61E, 0xCB8945FE, 0xA5751AD1, 0xC7A9820B, 0x96F4B71C};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 316 ");
	}
	{
		static const bigint_t var_a = {0x1FA324CF, 0x96DEBB6A, 0xE9584C38, 0x4B182553, 0x38EA6DC6, 0x1820B8EA, 0x0A8CDAD0, 0x72B543A6};
		static const bigint_t var_b = {0xD53323E9, 0x379C2609, 0xA217C821, 0x7579B137, 0x16DB27F5, 0x649DE009, 0x155CF96C, 0x4E41E75E};
		static const bigint_t var_expected = {0x4A7000E6, 0x5F429560, 0x47408417, 0xD59E741C, 0x220F45D0, 0xB382D8E1, 0xF52FE163, 0x24735C47};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 317 ");
	}
	{
		static const bigint_t var_a = {0x6A12F959, 0x63F9F8A1, 0x9A150434, 0x96B7C59E, 0xEFCA4259, 0xD224A214, 0x6F862660, 0xAD870086};
		static const bigint_t var_b = {0x0A7D77F8, 0x66733F94, 0x3BC8F746, 0xD4C89065, 0x921EF1CB, 0x2CC5DD37, 0x3641EDA6, 0x8708A9E0};
		static const bigint_t var_expected = {0x5F958161, 0xFD86B90D, 0x5E4C0CED, 0xC1EF3539, 0x5DAB508D, 0xA55EC4DD, 0x394438BA, 0x267E56A6};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 318 ");
	}
	{
		static const bigint_t var_a = {0x70719741, 0xEF184946, 0x616DF4D6, 0x1B558A1A, 0x23E9B01F, 0x6190DCB1, 0xBDABA91D, 0x5221F16A};
		static const bigint_t var_b = {0x6F8BD269, 0x94D2BA85, 0xDC252258, 0x99AA45BA, 0x99E22BA9, 0x035C7769, 0x0B41013C, 0x8EB9648A};
		static const bigint_t var_expected = {0x6311F973, 0x59341872, 0x59C0B1C5, 0x94BCF100, 0xDDEA0E2A, 0x5994C1B2, 0xF289840A, 0x7D7C2BA2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 319 ");
	}
	{
		static const bigint_t var_a = {0x6D334974, 0x4C3B93DE, 0xF1DF9501, 0x42C2FEE2, 0x41AEAF1E, 0xC711466D, 0x5B1A071B, 0x3AFFC866};
		static const bigint_t var_b = {0xE31C101E, 0xF308A100, 0xD9114AFC, 0x4D541336, 0x3971F8CA, 0x079038DE, 0x9A01B6E1, 0x5B3325F1};
		static const bigint_t var_expected = {0xEC436DF1, 0x58217C8E, 0xED46294B, 0x0880984C, 0x5C1F4009, 0xBAE169FA, 0x01372C63, 0x99E04137};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 320 ");
	}
	{
		static const bigint_t var_a = {0xDE143F1D, 0xC9042EF9, 0x41448461, 0xB4FCD992, 0xF6B8472D, 0x431A3B13, 0xEC53AABE, 0x7C866851};
		static const bigint_t var_b = {0x81209BCC, 0xF393E03C, 0xC96C719B, 0xB86F8912, 0xBEB101A6, 0x9B59C815, 0x28B445C9, 0x29053F6B};
		static const bigint_t var_expected = {0x5CF3A351, 0xD5704EBD, 0x77D812C5, 0xFC8D507F, 0x38074586, 0xA7C072FE, 0xC39F64F4, 0x538128E6};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 321 ");
	}
	{
		static const bigint_t var_a = {0x81EBF5DD, 0xF9CF153C, 0x8518038A, 0x5CBE2131, 0x2FAD4ABC, 0x57ED8AF1, 0x578DA67F, 0x7394E7EA};
		static const bigint_t var_b = {0xA7869C16, 0x462F3682, 0x7F665745, 0xE5AA895B, 0xB6F85EDE, 0x608B70B3, 0x39651D1A, 0x6FFE1CD3};
		static const bigint_t var_expected = {0xDA6559C7, 0xB39FDEB9, 0x05B1AC45, 0x771397D6, 0x78B4EBDD, 0xF7621A3D, 0x1E288964, 0x0396CB17};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 322 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 323 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 324 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 324");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 325 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 326 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 326");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 327 ");
		fp_mul_monty_fips_std(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 327");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 328 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_fips_std(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 328");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 329 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 330 ");
	}
	{
		static const bigint_t var_a = {0x52766F6A, 0xACBDC62E, 0x32D23576, 0x600D522F, 0x19049F3B, 0xC4B0D05E, 0xC0FE0998, 0xB70E64D5};
		static const bigint_t var_b = {0x8FE44968, 0xDEF5AF3C, 0x3D568ABD, 0x09372473, 0x9AF4FFC7, 0x3A822C26, 0x522D6E14, 0x2DAAB214};
		static const bigint_t var_expected = {0xB5754519, 0x57BEA60F, 0x46FAF6AA, 0xC6961194, 0xE01A0515, 0x7783CF4A, 0xBCB93082, 0x34297E15};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 331 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 331");
	}
	{
		static const bigint_t var_a = {0x8E2D3FE5, 0xF3C4BA6E, 0xFE2D0C4A, 0x2BCC8880, 0x21DC1FAA, 0x8B7C300A, 0x8B33A532, 0x217394DF};
		static const bigint_t var_b = {0x3F22C1E3, 0xE91C8ACF, 0xD361F011, 0xE6AD0615, 0x72EE678B, 0x3E15C6C5, 0x391DDB1E, 0x8A46E769};
		static const bigint_t var_expected = {0xC123B6E0, 0xA0AC5880, 0x8563FF30, 0x58ED063A, 0x65A5A6CE, 0xC81D1F37, 0xFAF2F85B, 0x4EE70A76};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 332 ");
	}
	{
		static const bigint_t var_a = {0x50E636FD, 0x20D5018E, 0x0908031F, 0x53380872, 0xA0E58668, 0xF10A1C89, 0x1E3B6AB0, 0x10537F97};
		static const bigint_t var_b = {0xAB8E29D7, 0xDAAD29BC, 0x5B1F5DA0, 0x0CF74AFF, 0x90B8688C, 0xD9E56C97, 0x725535CA, 0x9085013D};
		static const bigint_t var_expected = {0x56AC89BA, 0xE5440156, 0xF51DB274, 0xB0A43833, 0x563B2247, 0x944E46BF, 0x0D9AC4D3, 0x3353663A};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 333 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 333");
	}
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
	{
		static const bigint_t var_a = {0xD3D37642, 0xEE0B3EC1, 0x6A7654A0, 0xFA6145D8, 0x5FDD6D43, 0x021D0E6D, 0xFA4FE8EB, 0x423C3C89};
		static const bigint_t var_b = {0x27C64B9E, 0x3AADB11C, 0x5407AD57, 0x2C80A0C7, 0xF14BC30C, 0xAF1FBF0C, 0xBFB3DBDF, 0x3AC13029};
		static const bigint_t var_expected = {0xA4034A80, 0x4A629120, 0x6A800585, 0xC7EA57D7, 0x13C3FD23, 0x40AA33A8, 0x10D8BF9E, 0x95289B5D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 336 ");
	}
	{
		static const bigint_t var_a = {0xDDD39284, 0xD7A516FB, 0xFB206CC7, 0xA0200CEA, 0x755DAA04, 0x545A0D19, 0xA0E0D887, 0x9DD7A811};
		static const bigint_t var_b = {0x30315C63, 0x2BD046F6, 0xC534C643, 0x9C27C8F2, 0x7777E19F, 0x61F1D7E3, 0xF44A2500, 0x0AB4ECD8};
		static const bigint_t var_expected = {0xB52930B7, 0xAE4E2ED1, 0x81D6617F, 0xEC5F5693, 0xA859BA25, 0xA71A5F0C, 0x5D27485B, 0xB148D061};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 337 ");
	}
	{
		static const bigint_t var_a = {0x3C2C2AF9, 0xFC5A1751, 0x814312B4, 0x9C0CFA1E, 0xCE5F02B6, 0x4FCE1598, 0xC690CD48, 0x0025DE60};
		static const bigint_t var_b = {0xA92F1A86, 0xF7200A2D, 0xA5247499, 0x1578D3D7, 0xD72CF12D, 0x4DF2766C, 0xD498AA6D, 0x1AD4709A};
		static const bigint_t var_expected = {0x619CB9D4, 0x48B98094, 0x0256E416, 0x240979B7, 0x8DF2F13C, 0x1EDF48AB, 0x09DFC519, 0x125D2FF0};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 338 ");
	}
	{
		static const bigint_t var_a = {0x13AA6167, 0x2C87E37E, 0xEBB15466, 0x5102B278, 0x95EAA940, 0xA8119D55, 0x524C5986, 0x32C9F431};
		static const bigint_t var_b = {0x2E4ABEC3, 0x8F5BF3E7, 0x07E015EC, 0xE09594B9, 0xDF256BFF, 0x526F4DB6, 0x256F3A5E, 0x2482B84D};
		static const bigint_t var_expected = {0xA1F0E0AB, 0x3AEAE8CE, 0x80FE9187, 0xFBFA88DB, 0x1D3FC896, 0x08476640, 0x63FACCF0, 0x9D3B5CA5};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 339 ");
		bigint_t var_res2;
		fp_mul_monty_std(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res2, var_res, "fp_mul monty 339");
	}
	{
		static const bigint_t var_a = {0x8556a835, 0xdce2d15e, 0x2c0a8b9d, 0x94a432f5, 0x3c37671b, 0xf3951ad6, 0x17a719f9, 0x8a1595bf};
		static const bigint_t var_b = {0x8556a835, 0xdce2d15e, 0x2c0a8b9d, 0x94a432f5, 0x3c37671b, 0xf3951ad6, 0x17a719f9, 0x8a1595bf};

		bigint_t var_res2;
		fp_mul_monty_std(var_res, var_a, var_b, PRIME_P, MONTY_PRIME_N0);
		fp_mul_monty_var(var_res2, var_a, var_b, PRIME_P, MONTY_PRIME_N0[0]);
		assert_bi_equal(var_res, var_res2, "fp_mul monty 339v2");
	}
	{
		static const bigint_t var_a = {0xA0CF8725, 0x77167E57, 0xF1A51D5D, 0x2706648D, 0x368CF70A, 0x5D0E8571, 0xA97BC6B1, 0x0C44E107};
		static const bigint_t var_b = {0x9E311BB5, 0x241C9CC4, 0x43DF63A6, 0x8649C3C0, 0x9CA959B1, 0x9231FC01, 0xEC9DFE03, 0x2100712E};
		static const bigint_t var_expected = {0x69E5F3DF, 0xD0B2E718, 0xE127D6BD, 0x056304B6, 0xC0722B1C, 0x16AC291D, 0x56E75C23, 0x4B5EF76F};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 340 ");
	}
	{
		static const bigint_t var_a = {0x9CCFC967, 0x317916D3, 0xDD7C5D8D, 0xA2E4BFF6, 0xB6F90AD1, 0xBA70B91D, 0xF067CFA3, 0x349493A1};
		static const bigint_t var_b = {0x76ACA29E, 0x25D9326D, 0xC2D14437, 0xE3A15B58, 0xAF43955D, 0x67EFAED5, 0xAD584E5E, 0x04154B89};
		static const bigint_t var_expected = {0xAD4FB4A1, 0x57C92D3A, 0xDDE6879A, 0x30EC9229, 0x263DA15C, 0x1AF9C936, 0xD256013A, 0x39B10400};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 341 ");
	}
	{
		static const bigint_t var_a = {0xC20F5D82, 0xE9751730, 0xE5EB736F, 0xAB0B02D4, 0x027692F6, 0x40374601, 0x0C0D5ED3, 0x021AA46C};
		static const bigint_t var_b = {0xEE9879A5, 0x474D6667, 0xD996A8DC, 0xC72972C1, 0xA71EEA77, 0x837393D6, 0x2CF84B3D, 0x1735E6AD};
		static const bigint_t var_expected = {0x2B9A5CB1, 0xCBDF7C83, 0x861FEB48, 0x47354567, 0x951B5605, 0x110726F1, 0x931D9751, 0xACFEB4AE};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 342 ");
	}
	{
		static const bigint_t var_a = {0x3720DD98, 0x6F22369A, 0xFCC6B723, 0xA327F76B, 0x4383957A, 0xA022BD92, 0xE2872BC4, 0x3D3CF6BC};
		static const bigint_t var_b = {0xC968FEE2, 0x77D7837B, 0x1E3B9AEE, 0xB42CB119, 0x50B5601B, 0xB8768F8C, 0xF27856B7, 0x42E23D88};
		static const bigint_t var_expected = {0xB60619D4, 0x6FAAADAD, 0xF1C707AE, 0x37C4BC36, 0xA45D9523, 0x71D3B72B, 0x4D2EECE4, 0x7C3BA3BC};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 343 ");
	}
	{
		static const bigint_t var_a = {0x11066AD9, 0xD596D003, 0x571A018C, 0xBA1A427E, 0xEAB46A23, 0xEC656314, 0x174D3A14, 0x903DE2EF};
		static const bigint_t var_b = {0xE470B1AF, 0xE72D7EBF, 0xE31605CB, 0x33A47B8A, 0xB5A259F3, 0x264BF7BE, 0x00B227C8, 0x7E7C9BA8};
		static const bigint_t var_expected = {0x4220BF35, 0x3DA1CD12, 0xBA64BAE0, 0xB6F7A65B, 0x203133C7, 0x372423D7, 0x140A2840, 0xA672D04B};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 344 ");
	}
	{
		static const bigint_t var_a = {0xCE9157DA, 0x6E5A8FB7, 0xEEB08B30, 0x9A25D242, 0xA47DF46F, 0x631641D2, 0x50923E65, 0x15885361};
		static const bigint_t var_b = {0x97DA840C, 0x0A537B9E, 0x168C5317, 0xE7D96559, 0x7C5E2F9A, 0x384DD779, 0x1DCD6B1F, 0x90F0FC6D};
		static const bigint_t var_expected = {0x8CC9FB66, 0xDEEBF392, 0xCA88CB47, 0x0EF1844A, 0x788311B8, 0x3889F163, 0xFFAB70A3, 0x8FE567D7};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 345 ");
	}
	{
		static const bigint_t var_a = {0x502FD298, 0xC778E0F5, 0x7264BBCB, 0x647C418B, 0x5BFF9850, 0x793B5B70, 0x329EBDD7, 0x523813C7};
		static const bigint_t var_b = {0xA35655E1, 0x8F55AEE0, 0x5FB7D4A4, 0xEC51D29A, 0x8573FFFB, 0x8BD38380, 0x0D29CCCE, 0xAAA53C21};
		static const bigint_t var_expected = {0x52BB2AB2, 0x8D92B82B, 0x082C2DCE, 0xF07F77B1, 0xA94EEF51, 0x6540DCF9, 0x2F5B0CF4, 0x2210F753};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 346 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 347 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 348 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 349 ");
	}
	{
		static const bigint_t var_a = {0x6E2F7935, 0xB4293724, 0xDA36C211, 0x093331E4, 0x3EDDF4F4, 0xFC7E03AA, 0x21FFE35C, 0xB2FC3E16};
		static const bigint_t var_expected = {0x024BF5CF, 0x6E26DF42, 0x4A05636F, 0xD4FB1136, 0x86DCF053, 0xFB053895, 0x2D7569B1, 0x305C60C6};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 350 ");
	}
	{
		static const bigint_t var_a = {0xA33AD80E, 0x68A37B55, 0xD4DB6B93, 0x8B120C6A, 0x9EC7BD5D, 0xFFBED339, 0x95312BA9, 0x86BFE53F};
		static const bigint_t var_expected = {0x0B9784AD, 0xF5E86770, 0x1F3244DA, 0x26263E33, 0x42AB5522, 0x08660196, 0xB2566FA8, 0x66108DE9};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 351 ");
	}
	{
		static const bigint_t var_a = {0x651D8B2A, 0x4648A3F2, 0xDCD89E02, 0xF270C0AA, 0xBD0AD444, 0xEE9C1E75, 0x83F44AB3, 0x0E56B3FA};
		static const bigint_t var_expected = {0x64121013, 0xCB8A7BD4, 0xD3512EEA, 0x1027FD98, 0x2BCB3001, 0x64111C48, 0xF1ADF58E, 0x5CBCE5C4};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 352 ");
	}
	{
		static const bigint_t var_a = {0x757DE7B8, 0xC608739F, 0xCA2BD707, 0x4D464084, 0xD34D072A, 0xB5EA0BB6, 0xBBCD21B4, 0x1DC26750};
		static const bigint_t var_expected = {0xF6B08E8C, 0x22B6AB57, 0x37D3345A, 0xBA8E2EA5, 0xC52C4932, 0x1DBD1768, 0x26EFEF10, 0x84866118};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 353 ");
	}
	{
		static const bigint_t var_a = {0xD993013A, 0xCC6233A9, 0xEBF9FC61, 0x00FC006E, 0x7C96E5CD, 0x8173801E, 0xBFBE6E84, 0xAE2CA20A};
		static const bigint_t var_expected = {0xAA6E10B7, 0x97A5FABC, 0x29B9F536, 0xCB593CAC, 0x2E65B3B3, 0xAD82156B, 0xFD0471A5, 0x7FAA9E08};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 354 ");
	}
	{
		static const bigint_t var_a = {0x3687EC69, 0x19C0E30A, 0xD5184A81, 0xFBCB4FF2, 0x72D67FAE, 0x0F3C524B, 0xC4AF941B, 0xA821EF80};
		static const bigint_t var_expected = {0x5BA8B9FC, 0xE6FC9A8F, 0x463C86C1, 0xB3DEC1BA, 0x75F8EA32, 0xBC459DA4, 0x8531041D, 0x728D8DD7};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 355 ");
	}
	{
		static const bigint_t var_a = {0xFF507D55, 0xD9749831, 0xE8EA1862, 0xD01DA784, 0x1DA3A069, 0x4A531600, 0xB6B70E7E, 0x0290B702};
		static const bigint_t var_expected = {0x5EAD75E7, 0x8FAEA724, 0xEC67BF12, 0x76E72226, 0x3BA4E9AF, 0xCD40DB94, 0x4B9FCDE3, 0x7493223D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 356 ");
	}
	{
		static const bigint_t var_a = {0x43019F26, 0x13829471, 0xCBA33B0A, 0x9EC6240A, 0x08DF432C, 0xADB20475, 0x34A53D75, 0xA0D281ED};
		static const bigint_t var_expected = {0x48057BAD, 0x362AB668, 0x95547588, 0x800988AA, 0xB60BA7F8, 0x44F45F2C, 0x459F6A24, 0x218EF72C};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 357 ");
	}
	{
		static const bigint_t var_a = {0x5A9B1DD5, 0x3CF8DF70, 0x9DEE10CE, 0xD838A597, 0x1B7F34BA, 0xF5AE7902, 0x90726C49, 0x8B7D85B5};
		static const bigint_t var_expected = {0x5EC0FF1F, 0xA0698B44, 0x94BE78A5, 0x2873432C, 0x4E6F7CCD, 0xF813AC06, 0xC935ECD7, 0x8427CED8};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 358 ");
	}
	{
		static const bigint_t var_a = {0xD679E294, 0xA6A7160A, 0xED348932, 0x6C1BE00F, 0x0D7FE473, 0x7518980B, 0x90C74C10, 0x03C5C124};
		static const bigint_t var_expected = {0xF33E6F92, 0x712B0442, 0x82069A27, 0x4121548B, 0xEE25C5AA, 0xBA5BEDC2, 0xF9F474BA, 0x058A0A58};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 359 ");
	}
	{
		static const bigint_t var_a = {0xA155D967, 0x09062CEE, 0x6A16F8F2, 0x353CD704, 0x92455A69, 0x992AB6EC, 0xB02165E0, 0x3B257FCD};
		static const bigint_t var_expected = {0xA76B273B, 0xF05F29D8, 0xF685603B, 0xE0B40286, 0x03CC67EA, 0x4C8C1E08, 0x88C714F3, 0x7BB18D80};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 360 ");
	}
	{
		static const bigint_t var_a = {0x91E502CF, 0x00F0E924, 0x37CB2AF2, 0x154AE663, 0x37C62874, 0x7F91281A, 0x5E494A6B, 0x3FC8090D};
		static const bigint_t var_expected = {0x07CF5757, 0xFCE3F3DA, 0x761AB354, 0x87B92B4A, 0xA21DD679, 0x7D7F8C9D, 0x2F1AC9CB, 0x24920F26};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 361 ");
	}
	{
		static const bigint_t var_a = {0xD88A3785, 0x8C513F5A, 0x970578F0, 0xDB534EED, 0x81DDF67F, 0x62B005DD, 0xBDD08236, 0x12C586C0};
		static const bigint_t var_expected = {0x3651180C, 0x202F42BD, 0x36C0D227, 0x932A6C9A, 0x93199722, 0x0CBE5748, 0x606AB02E, 0x17AA2E34};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 362 ");
	}
	{
		static const bigint_t var_a = {0x929160B8, 0x93F4F316, 0x40F53F42, 0x60A269DD, 0xD2160A50, 0x2CCCAE73, 0xE3292FF9, 0x8DAE3F73};
		static const bigint_t var_expected = {0xEBF38CD5, 0xD7AFF21F, 0xEC506EDF, 0xE3F06EBE, 0x74DE785F, 0x38DD15A2, 0xB21286ED, 0x1755B2C2};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 363 ");
	}
	{
		static const bigint_t var_a = {0x97A97B20, 0x5B41F969, 0xDC401832, 0x7A69BAED, 0xD8819E59, 0xDFD6B1AD, 0xDAE4CB09, 0x3B020B48};
		static const bigint_t var_expected = {0x61F4CC8F, 0x35C1B50F, 0x7EB68F8D, 0x2F2E60D4, 0x38620731, 0x275D85B9, 0x2CA02C0A, 0x8C60885E};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 364 ");
	}
	{
		static const bigint_t var_a = {0x0EC7540F, 0x12373EDE, 0x5EA9CF0F, 0x1EC31922, 0x711CEBBE, 0x2AB18ABC, 0xE266E1ED, 0x37D2621B};
		static const bigint_t var_expected = {0x60B31228, 0x50D819D5, 0x1BB405B9, 0x6937EB90, 0x21D3B425, 0xC75D9117, 0xC015FC2D, 0x8CD754D5};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 365 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xB1161A4E, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 366 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 367 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0xB1161A4D, 0x7F7744D8, 0x6A3BEFA3, 0x8988D650, 0xA9F144DA, 0x7DB02E35, 0x200F6E14, 0x5D09CF61};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 368 ");
	}
	{
		static const bigint_t var_a = {0x3B3B0626, 0x463A861E, 0x82A3F982, 0x4F7B5710, 0x184CADD7, 0xCD1ACF6C, 0x6EC3754E, 0x095D0AB3};
		static const bigint_t var_expected = {0x1D9D8313, 0x231D430F, 0x4151FCC1, 0xA7BDAB88, 0x0C2656EB, 0x668D67B6, 0xB761BAA7, 0x04AE8559};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 369 ");
	}
	{
		static const bigint_t var_a = {0xC92B64BF, 0x6DA336F4, 0x25CB7143, 0xD1C822AF, 0xD9914C01, 0x4DD38DEC, 0xE36142EC, 0x26568A5E};
		static const bigint_t var_expected = {0x15ABCCAD, 0x3648E053, 0xFD21A845, 0x726CE7A7, 0x16B9EADB, 0xA499F52C, 0x91C00F8A, 0x70351490};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 370 ");
	}
	{
		static const bigint_t var_a = {0x04D637CC, 0x5C0987E8, 0x3E5840E9, 0xC3D11CA5, 0xAE98559F, 0x2E0A870D, 0xDC853AFF, 0x5659EAC6};
		static const bigint_t var_expected = {0x026B1BE6, 0xAE04C3F4, 0x9F2C2074, 0xE1E88E52, 0xD74C2ACF, 0x97054386, 0x6E429D7F, 0x2B2CF563};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 371 ");
	}
	{
		static const bigint_t var_a = {0xA0FD2562, 0xD2376AF2, 0xE9497FB5, 0x02408E14, 0x1B0ECFBB, 0xB61F6B53, 0xE81BAE42, 0x51001091};
		static const bigint_t var_expected = {0x507E92B1, 0xE91BB579, 0x74A4BFDA, 0x8120470A, 0x8D8767DD, 0x5B0FB5A9, 0xF40DD721, 0x28800848};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 372 ");
	}
	{
		static const bigint_t var_a = {0x6C196796, 0xEFE11DEE, 0x06A17476, 0x7EA1F817, 0x48B97DC8, 0x41B5F658, 0xCA68519B, 0x3A23CD8B};
		static const bigint_t var_expected = {0x360CB3CB, 0x77F08EF7, 0x8350BA3B, 0x3F50FC0B, 0x245CBEE4, 0xA0DAFB2C, 0xE53428CD, 0x1D11E6C5};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 373 ");
	}
	{
		static const bigint_t var_a = {0xEB18792C, 0xB704C254, 0x96DE2B6F, 0x54C7D781, 0xDBCACEE4, 0xCF4DA6C9, 0xB8A40C93, 0x7EDD1C5A};
		static const bigint_t var_expected = {0x758C3C96, 0xDB82612A, 0xCB6F15B7, 0x2A63EBC0, 0xEDE56772, 0xE7A6D364, 0x5C520649, 0x3F6E8E2D};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 374 ");
	}
	{
		static const bigint_t var_a = {0x327E75AF, 0x916D14C3, 0x0E27B771, 0x699B63E9, 0xD1C4A713, 0x88BE1357, 0x1D1CFE38, 0x0E1F0CB2};
		static const bigint_t var_expected = {0x4A555525, 0x482DCF3A, 0xF14FCB5C, 0x3E568844, 0x92D39864, 0xC20F37E1, 0x2E9DED30, 0x641955BA};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 375 ");
	}
	{
		static const bigint_t var_a = {0x0870BC85, 0xCBF382FB, 0x02446D44, 0xD1E31BC5, 0xA5ED8D9D, 0x396F7C82, 0xD7E3716D, 0x252467C2};
		static const bigint_t var_expected = {0x354E7890, 0xE5710656, 0xEB5E2645, 0x727A6432, 0xFCE80BA9, 0x1A67EC76, 0x8C0126CB, 0x6F9C0342};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 376 ");
	}
	{
		static const bigint_t var_a = {0x52263853, 0x12DCA5B6, 0xCB4AA9B7, 0xAF7CF832, 0x77676DA9, 0xC36AF5FA, 0xFB12949A, 0x6B79768B};
		static const bigint_t var_expected = {0xDA293677, 0x08E597B3, 0xCFE1447F, 0x61475269, 0xE5A4FBAF, 0xDF65A932, 0x1D98B861, 0x92C68AA7};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 377 ");
	}
	{
		static const bigint_t var_a = {0xBB0CB662, 0xFDCAD3A9, 0xBDFE8051, 0xF9A1BDF6, 0x4345EA86, 0xC75F9B58, 0xCC060ECD, 0x2FD950C3};
		static const bigint_t var_expected = {0xDD865B31, 0xFEE569D4, 0x5EFF4028, 0x7CD0DEFB, 0x21A2F543, 0xE3AFCDAC, 0xE6030766, 0x17ECA861};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 378 ");
	}
	{
		static const bigint_t var_a = {0x0AADB4A3, 0x83F3EC67, 0xF2730925, 0xB69E0FC1, 0xA8B28FF0, 0xF5B081B3, 0xC7D3EDCA, 0x2BB75311};
		static const bigint_t var_expected = {0x366CF49F, 0x41713B0C, 0x63757436, 0xE4D7DE31, 0x7E4A8CD2, 0xF8886F0F, 0x03F964F9, 0x72E578EA};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 379 ");
	}
	{
		static const bigint_t var_a = {0xB94FBB22, 0x80D403A1, 0xA16DE6E0, 0x1D8CCE8E, 0xC519BDE3, 0xA875217C, 0xDAC08C7E, 0x65A5149D};
		static const bigint_t var_expected = {0xDCA7DD91, 0x406A01D0, 0x50B6F370, 0x8EC66747, 0x628CDEF1, 0x543A90BE, 0xED60463F, 0x32D28A4E};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 380 ");
	}
	{
		static const bigint_t var_a = {0xD5F63187, 0x3520F691, 0x78610321, 0x29875E0A, 0x0FED9A47, 0x5E4A7EC1, 0x27485806, 0x66452AB0};
		static const bigint_t var_expected = {0x9C113311, 0x1A07C021, 0xA66C7134, 0x1E4C8555, 0x31E811FE, 0xACD56D96, 0x33B39A17, 0x902C64B9};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 381 ");
	}
	{
		static const bigint_t var_a = {0x1F4FEB26, 0xC655A8AB, 0x435A442F, 0x06D425E0, 0x79FB01AD, 0x3DF1003A, 0x46AACD4C, 0x01206717};
		static const bigint_t var_expected = {0x8FA7F593, 0xE32AD455, 0x21AD2217, 0x836A12F0, 0x3CFD80D6, 0x1EF8801D, 0xA35566A6, 0x0090338B};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 382 ");
	}
	{
		static const bigint_t var_a = {0x73011D6C, 0xB9847540, 0x9379349C, 0xF1779B8E, 0x9B621EAF, 0x7EC20574, 0x000DF2F4, 0x75094AD2};
		static const bigint_t var_expected = {0x39808EB6, 0x5CC23AA0, 0x49BC9A4E, 0xF8BBCDC7, 0x4DB10F57, 0x3F6102BA, 0x0006F97A, 0x3A84A569};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 383 ");
	}
	{
		static const bigint_t var_a = {0x72ABD83A, 0x7C9F044D, 0xF443A788, 0xF7E2E5B6, 0xE88D3842, 0x190D02CC, 0x5595E249, 0xA95EBE37};
		static const bigint_t var_expected = {0xB955EC1D, 0x3E4F8226, 0x7A21D3C4, 0x7BF172DB, 0x74469C21, 0x8C868166, 0xAACAF124, 0x54AF5F1B};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 384 ");
	}
	{
		static const bigint_t var_a = {0x7C878C74, 0xE11A982D, 0xE1A184D2, 0x23ED77C4, 0x2351EEFC, 0x1D270441, 0x37A3A252, 0x37DC7BA0};
		static const bigint_t var_exp = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x7C878C74, 0xE11A982D, 0xE1A184D2, 0x23ED77C4, 0x2351EEFC, 0x1D270441, 0x37A3A252, 0x37DC7BA0};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 385 ");
	}
	{
		static const bigint_t var_a = {0x7C878C74, 0xE11A982D, 0xE1A184D2, 0x23ED77C4, 0x2351EEFC, 0x1D270441, 0x37A3A252, 0x37DC7BA0};
		static const bigint_t var_exp = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 386 ");
	}
	{
		static const bigint_t var_a = {0xC69A8305, 0x99C832F3, 0x780239AD, 0xEB3DC44D, 0x8E8077D9, 0x314E1C47, 0xCDA561F0, 0x30B6B618};
		static const bigint_t var_exp = {0x55AED7A4, 0xBC6EAECD, 0x98E6EF94, 0x6287AD04, 0x12293515, 0x2BF8414A, 0xF15BAEA7, 0xB4812FBD};
		static const bigint_t var_expected = {0x4ECD83F5, 0x53E13D6B, 0x734B1549, 0x96D75F84, 0xE3362359, 0xCE286400, 0x0D2301D9, 0x7C591C9D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 387 ");
	}
	{
		static const bigint_t var_a = {0x7F57BF94, 0x48BAE82D, 0x751BFFA2, 0xB81AB6DD, 0xC8A60AAE, 0x9033A516, 0xB27031D8, 0x75812AF4};
		static const bigint_t var_exp = {0x541AE3F6, 0x9C58757E, 0x2E1CEC5F, 0x1DE7EA8C, 0x187C0427, 0xF9776961, 0x1370D87C, 0xD6691BD1};
		static const bigint_t var_expected = {0xACEA91CA, 0x081234B7, 0x57700A13, 0x87FCD8BB, 0x0F77CF80, 0x7579B2B9, 0xE1E37812, 0x8EB7F197};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 388 ");
	}
	{
		static const bigint_t var_a = {0x955BCE0A, 0xFD4837E3, 0x030D9D6F, 0xEFE5E788, 0xE97AFC6D, 0xA8A69EF4, 0x8A816E9C, 0x847A078C};
		static const bigint_t var_exp = {0x987A6967, 0x1363B52D, 0xABDDF743, 0x51F1491B, 0x76AE3FA8, 0x047BA759, 0xC2882BA6, 0xB00F0E5B};
		static const bigint_t var_expected = {0x38AD1910, 0xE44E7222, 0x96671BCC, 0xA5446FC2, 0x52D50E71, 0xB49AA904, 0xD8E58EAB, 0x1A101ECB};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 389 ");
	}
	{
		static const bigint_t var_a = {0xC70F9FC9, 0x697F6FB7, 0xCDC3FC2F, 0xAA98B884, 0xCFB1B426, 0x152B451C, 0x19F8B387, 0x902E7688};
		static const bigint_t var_exp = {0x1F7BFAE1, 0xF12F80C5, 0x8685C584, 0x2605A6F3, 0x595606AF, 0x0B98465A, 0x23735053, 0xDC213183};
		static const bigint_t var_expected = {0x78FD7225, 0xCA2688F5, 0x730A407F, 0x5FFC9C0A, 0x1BCE4BDF, 0x6F42CAC7, 0x64940F21, 0x2F687CB0};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 390 ");
	}
	{
		static const bigint_t var_a = {0xB2C21969, 0x7D088DFC, 0xE6933322, 0x33EE7608, 0x4A9A0CF8, 0xB70EBD9A, 0x25418737, 0x5126643D};
		static const bigint_t var_exp = {0x25C10C24, 0x4777478A, 0x72F55694, 0x069E0486, 0x2EEFED04, 0x0F98D8A1, 0x9A8F81C4, 0x3227CB4C};
		static const bigint_t var_expected = {0x4FC42955, 0x602EBC75, 0xEF784678, 0x8A38F7F8, 0x193636B9, 0xF0155198, 0x5AD130D1, 0x57A973D7};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 391 ");
	}
	{
		static const bigint_t var_a = {0xD178C72F, 0x6B3E769E, 0xCF88F8E6, 0x00F4FF58, 0x11EE288A, 0xB479714D, 0x72660AB5, 0x08766767};
		static const bigint_t var_exp = {0x28BBAEF5, 0x66170F88, 0x66E6ED8E, 0x99E3549A, 0xA2A945D1, 0x538667AB, 0xCE21164B, 0xCB0E2694};
		static const bigint_t var_expected = {0xD26E804C, 0xCFE16080, 0x52EC5C2A, 0x4FB32BF2, 0x5B5AC402, 0xF260E212, 0xCACED074, 0x63D5297B};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 392 ");
	}
	{
		static const bigint_t var_a = {0x6695D14A, 0xA0E51116, 0x9B0CACAF, 0x14F4375A, 0x6D0D19BA, 0x5E5E258F, 0x05F6ED6E, 0x1AB502B2};
		static const bigint_t var_exp = {0xE3700B30, 0xDF2443F0, 0x9738B0D3, 0xC939332B, 0xA23BEE9B, 0x57C00A42, 0xA3A081C3, 0x00C03993};
		static const bigint_t var_expected = {0x2B124A37, 0x8B59C8B7, 0xE779C102, 0xD2A65128, 0xDE4E2635, 0x77081CEC, 0xFAF21507, 0x44BE04DF};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 393 ");
	}
	{
		static const bigint_t var_a = {0x47CC1187, 0xD1F7E225, 0xCD119C7D, 0x2B3E5521, 0x9D14EC45, 0x6B692206, 0x6404954A, 0x19AB3B3E};
		static const bigint_t var_exp = {0x5653C3AE, 0x84FA31D9, 0x7843004F, 0xBED0B0B8, 0x5CB0C5F5, 0xDB05E0E3, 0x3D06C7CD, 0x6BAA1A26};
		static const bigint_t var_expected = {0x4EB62113, 0xF3A43B5F, 0xA2599061, 0xAE5F868C, 0x6D263C0C, 0xCB60F449, 0x01FCEC3B, 0x208A939A};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 394 ");
	}
	{
		static const bigint_t var_a = {0x9981C8BE, 0xEDB4C40A, 0xCB682E48, 0xD9C614CD, 0xBBF3DA26, 0xA8B1ADB1, 0x54478888, 0xA5119E4D};
		static const bigint_t var_exp = {0xBB0C1989, 0x64492A10, 0xC025894B, 0xE2341F1C, 0x3B38A753, 0xE2886815, 0x03206049, 0xE3552C48};
		static const bigint_t var_expected = {0x2F11E638, 0xA862EFC9, 0xD4473FB9, 0xF0581F6C, 0x5973870A, 0x9A0D8681, 0xE987FAB8, 0xA780269C};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 395 ");
	}
	{
		static const bigint_t var_a = {0x13057B05, 0x26B2AF30, 0x6E0A0FFE, 0x70A857A7, 0xDAF15D25, 0x44288D7B, 0x1996118E, 0x8BF7DD3A};
		static const bigint_t var_exp = {0x9150F22F, 0xD2283DEF, 0x6215FFDE, 0xDDDEDF25, 0xEDF8FEE8, 0xABFD4986, 0x98DE98D9, 0x84F21783};
		static const bigint_t var_expected = {0x0BB0A83D, 0xC09210B7, 0x99340EC2, 0x7E44A254, 0xF62B2E6F, 0xD86E18EB, 0xC1886C61, 0x6199533E};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 396 ");
	}
	{
		static const bigint_t var_a = {0xD21D5227, 0xEE40077D, 0x4A166550, 0xB7680B7D, 0x475DCDF2, 0xA068765F, 0xF8714AD5, 0x02174753};
		static const bigint_t var_exp = {0x94ABAC4D, 0x5E26A467, 0x95AF9347, 0x99C3378E, 0x60DDF18E, 0xB8AA7328, 0xE3A55E77, 0xA4E88648};
		static const bigint_t var_expected = {0x4E0D3AAA, 0xB75B6E01, 0x2EAA1836, 0xA5A71BFC, 0xF04BF8FE, 0x35F3D3A4, 0x0124D3E9, 0x843E16E5};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 397 ");
	}
	{
		static const bigint_t var_a = {0x59D5B3C0, 0xF279B663, 0xB122818C, 0xF283E4E4, 0x8B5BB3BF, 0x4EC8C5BB, 0x3751850B, 0xB265391C};
		static const bigint_t var_exp = {0xC153C684, 0xD955CBB1, 0xCE481ECF, 0x3EE42602, 0xBF651905, 0xCB78A79A, 0x079D8355, 0xDE68A16F};
		static const bigint_t var_expected = {0x23409FCE, 0xE48EF70F, 0xE0E52A8F, 0xEB43158B, 0x979C1CB4, 0x3D1DDFE6, 0xA09CDDBF, 0x071140A7};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 398 ");
	}
	{
		static const bigint_t var_a = {0x1EC26146, 0x27F091DF, 0x3C56E4FF, 0x2F6481E9, 0x76BB58F1, 0x3F07DAB7, 0xDADFED6C, 0x25F3510A};
		static const bigint_t var_exp = {0x56F85A6A, 0x5461FF53, 0xC03CF808, 0x36DE4355, 0x7977D318, 0xE3026787, 0x6BFE759C, 0x0AFC504F};
		static const bigint_t var_expected = {0x2A44DECE, 0x30E16780, 0xE15AE066, 0x2BF95F7A, 0x0C9FA084, 0xA44D231C, 0x166B85C1, 0x3E80B4AD};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 399 ");
	}
	{
		static const bigint_t var_a = {0x6289C9F4, 0xBC0C1BB4, 0x1366111C, 0x0C9CEAF5, 0x69A6A1E2, 0x8F1F2F3F, 0x277E73FA, 0x103EA6AF};
		static const bigint_t var_exp = {0xCF917459, 0x2099BF70, 0x623E8D7F, 0x2A7B9B21, 0x3A2D2680, 0x41A644D9, 0xB2676BC2, 0x4113472E};
		static const bigint_t var_expected = {0x95EE6FAF, 0x91F253B8, 0x2C30CFB4, 0x6F386CD2, 0xDE97F0B8, 0x37944F00, 0x4C07749E, 0x4531DF35};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 400 ");
	}
	{
		static const bigint_t var_a = {0x40D69A46, 0x24795251, 0xCC8E79A5, 0x502173F3, 0xB2FFE922, 0x9D75F34F, 0x62F9C181, 0xAA61F13D};
		static const bigint_t var_exp = {0xE93130FC, 0xCF03B48D, 0xE7A79F26, 0x0241945E, 0xEFA63775, 0x689298E5, 0xC2290085, 0xDC97C701};
		static const bigint_t var_expected = {0x1D802D35, 0x62F706E2, 0x17488AF0, 0xAB4A63D3, 0x30811A86, 0x10366D67, 0x72A43518, 0x1A67735B};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 401 ");
	}
	{
		static const bigint_t var_a = {0x1655EA2A, 0x0D1DEA4F, 0x3C5CDAB2, 0x06EE2A85, 0xDE1731AF, 0x0C48ABAC, 0x11FA5676, 0x6DB9BF81};
		static const bigint_t var_exp = {0xA2D3B6A7, 0x306E4744, 0xC6CA4027, 0xE701D6B7, 0xC5D9595F, 0x18D999EE, 0xC1984AC9, 0x757B37B4};
		static const bigint_t var_expected = {0xA01FEC4A, 0x0603BCE5, 0x85E81F53, 0x5A87141B, 0x55E8E901, 0x72E8773F, 0xAF820810, 0x7F2B8B24};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 402 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 403 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 404 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 405 ");
	}
	{
		static const bigint_t var_a = {0x80837479, 0x6B2E1135, 0x77F9EFC1, 0x759028DE, 0xBA7CCF22, 0xBDBF5B82, 0xF853AF62, 0x11713F56};
		static const bigint_t var_expected = {0xE1A8C022, 0x93C0787B, 0x5C7DEF85, 0x9D8183C2, 0x9965BA92, 0x3DA100E8, 0x47CB2CC6, 0xA8A25F6B};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 406 ");
	}
	{
		static const bigint_t var_a = {0xD3FED64D, 0x578D5BDA, 0xDFC79E93, 0x305A890C, 0xD57E2061, 0x571E7F31, 0xD23D86BE, 0x2A33D0A9};
		static const bigint_t var_expected = {0x8E2D5E4E, 0xA7612DD6, 0xF4B040B3, 0xE2B72393, 0x7E646953, 0xA441DD39, 0x6DE1556A, 0x8FDFCE18};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 407 ");
	}
	{
		static const bigint_t var_a = {0x5D80343D, 0x6D416401, 0xD4805B9D, 0x28BB56FD, 0x51C940C1, 0xD0FF992F, 0x1D56683F, 0x911455EE};
		static const bigint_t var_expected = {0x04AC005E, 0x91AD25B0, 0xFFF783A9, 0xEA5655A2, 0x021948F3, 0x2A60C33C, 0x22C873E9, 0x28FF48D4};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 408 ");
	}
	{
		static const bigint_t var_a = {0x2276A5D8, 0x91B4DC95, 0xA436BD07, 0xBF9AA3C4, 0xC849468F, 0x56882D58, 0x5BBE5B26, 0x42AFD18E};
		static const bigint_t var_expected = {0x3FB58EC3, 0x6D39AD1C, 0x3041223F, 0x537708DC, 0x8B994325, 0xA4D82F12, 0xE4608102, 0x7763CD33};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 409 ");
	}
	{
		static const bigint_t var_a = {0xC8DB4E12, 0x8558019C, 0xE64BBDC8, 0xE6D4C5B7, 0xF37501C6, 0xA6357E2D, 0xC41A5515, 0x2420F4CB};
		static const bigint_t var_expected = {0x9950E689, 0x79968814, 0xEE2C217E, 0x2C3CE6E8, 0x606D87EE, 0x552ADE3D, 0x7C048713, 0x95F2A9F6};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 410 ");
	}
	{
		static const bigint_t var_a = {0xC21FBD8B, 0x73AB5AA4, 0xF94EF974, 0x2F9274B6, 0x3C088844, 0xAAAF8620, 0x41DEDA44, 0x2F0787AF};
		static const bigint_t var_expected = {0xA00C7710, 0x8B432F0C, 0xDB28E5D2, 0xE37F37E9, 0x17DA0170, 0x50B0D64B, 0xFE4001E4, 0x8B0C1712};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 411 ");
	}
	{
		static const bigint_t var_a = {0x20675014, 0x63F4BF6A, 0x82430368, 0xBA88813A, 0x2BA880A7, 0xE1A87A5B, 0x72D7878F, 0x4490BB7E};
		static const bigint_t var_expected = {0x41C4E487, 0x9AF9CA47, 0x5234DBDE, 0x58892B66, 0x283A090D, 0x19B7E210, 0xCD475499, 0x7582E343};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 412 ");
	}
	{
		static const bigint_t var_a = {0x386A91DB, 0xCAAF4752, 0xA33EE04D, 0xF82BB8C1, 0xABAF14A1, 0x044F765A, 0xA99A4371, 0x704037FA};
		static const bigint_t var_expected = {0x29C1A2C0, 0x343F425F, 0x3138FEF9, 0x1AE5F3DF, 0xA8337513, 0xF710E610, 0x968498B7, 0x49D366C7};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 413 ");
	}
	{
		static const bigint_t var_a = {0x0005C119, 0xF9238DA8, 0xBF2FEBD6, 0xEC55EAEC, 0xC702263A, 0x61CB162F, 0xED2C4F62, 0xAA71D682};
		static const bigint_t var_expected = {0x62267382, 0x05CAFC09, 0x1547F370, 0x26BBC1B4, 0x8CE0637A, 0x9995463B, 0x52F28CC6, 0x0FA1C83F};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 414 ");
	}
	{
		static const bigint_t var_a = {0x9C8C7747, 0xAA93B134, 0xDB739866, 0x48F17203, 0x89E56821, 0x6FB39F3E, 0x38AA77DC, 0xB2A735A6};
		static const bigint_t var_expected = {0xC59FBD54, 0x545AD87C, 0xF90446E0, 0xCA203A9C, 0xC9FD2193, 0x8BACBD2C, 0x0774644C, 0x076C691C};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 415 ");
	}
	{
		static const bigint_t var_a = {0x46790A3A, 0x7894EB4A, 0xF007B965, 0x042093DC, 0xD3756BE0, 0x47498E88, 0x397727AC, 0x4F7120D9};
		static const bigint_t var_expected = {0x1BB32A61, 0x86599E67, 0xE47025E1, 0x0EF118C3, 0x806D1DD5, 0xB416CDE2, 0x06A7B47C, 0x6AA27DE9};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 416 ");
	}
	{
		static const bigint_t var_a = {0x6908AA16, 0x65191793, 0x959BCBD8, 0xC84DB370, 0x83AF35F7, 0x2E8C6024, 0x93045F19, 0x0E313FE6};
		static const bigint_t var_expected = {0xF9238A85, 0x99D5721D, 0x3EDC136E, 0x4AC3F930, 0xD03353BD, 0xCCD3FC46, 0xAD1A7D0F, 0xABE25EDB};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 417 ");
	}
	{
		static const bigint_t var_a = {0x0E39B3DA, 0x50A19787, 0xAA4221F0, 0xCDBEA21B, 0x9D0E0B35, 0xF518542D, 0x9C1DA0B5, 0x6B6C8E31};
		static const bigint_t var_expected = {0x53F280C1, 0xAE4CF22A, 0x2A35BD56, 0x45530A85, 0xB6D47E7F, 0x0648083D, 0xA4013B73, 0x4EA71090};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 418 ");
	}
	{
		static const bigint_t var_a = {0x847E08A4, 0x87037ED2, 0x85F18A8F, 0x9C1F9569, 0x803E7882, 0xB3FAAA03, 0x5F3227D6, 0x09036526};
		static const bigint_t var_expected = {0xDDAE2BF7, 0x77EB0ADE, 0x4E8654B7, 0x76F21737, 0xD3A41132, 0x4765B267, 0xE0ECB452, 0xB110399B};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 419 ");
	}
	{
		static const bigint_t var_a = {0xB73AEDC0, 0x33644F4B, 0xC4256743, 0x4F8EB9BA, 0xB1C740DC, 0x0B8B7929, 0x9BE234B5, 0x7800DBC0};
		static const bigint_t var_expected = {0xAAF146DB, 0xCB8A3A65, 0x10527803, 0xC382F2E6, 0xA21B48D8, 0xEFD4E341, 0xA43CA773, 0x4212C301};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 420 ");
	}
	{
		static const bigint_t var_a = {0xC4EEDBEF, 0xE6C6531A, 0xA2590C57, 0xB1A433AE, 0xB3CA4CD8, 0xCD42FE8F, 0x01843934, 0x105623BC};
		static const bigint_t var_expected = {0x9D3D58AC, 0x18283696, 0x321ED2EF, 0x616D78F2, 0xA0183CDC, 0x2E1D5DDB, 0x3E9AA2F4, 0xA9BD7B06};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 421 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 422 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 423 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C3499, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 424 ");
	}
	{
		static const bigint_t var_a = {0xDCC578E4, 0x12C5BE32, 0x5116AF88, 0xD2FE5A47, 0xDD582069, 0x6B5AF998, 0xF9331B7C, 0x2F1B771A};
		static const bigint_t var_expected = {0xB98AF1C8, 0x258B7C65, 0xA22D5F10, 0xA5FCB48E, 0xBAB040D3, 0xD6B5F331, 0xF26636F8, 0x5E36EE35};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 425 ");
	}
	{
		static const bigint_t var_a = {0xC6434DCE, 0x91E62E48, 0x755EB105, 0x85BF7751, 0xDB3A91C6, 0x7A9A9F4B, 0x1E9AFBBB, 0xB5C90AD2};
		static const bigint_t var_expected = {0x2A5A6701, 0x24DDD2E0, 0x164582C4, 0xF86D4202, 0x629299D7, 0xF9D4E22C, 0xFD171B4D, 0xB17E76E1};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 426 ");
	}
	{
		static const bigint_t var_a = {0x5B43DB00, 0x1D8A8FD6, 0xA7E88428, 0xE124DBF7, 0x2E07FF83, 0x35BCE699, 0xBD7A0331, 0x888ABEA7};
		static const bigint_t var_expected = {0x545B8165, 0x3C2695FB, 0x7B592909, 0xAF380B4E, 0x082D7552, 0x701970C7, 0x3AD52A39, 0x5701DE8D};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 427 ");
	}
	{
		static const bigint_t var_a = {0x0945A1B2, 0xD95D1F90, 0xF329AA69, 0xC12CC69B, 0xA7880704, 0xFA59CD31, 0x5B191E44, 0x1192DB6D};
		static const bigint_t var_expected = {0x128B4364, 0xB2BA3F20, 0xE65354D3, 0x82598D37, 0x4F100E09, 0xF4B39A63, 0xB6323C89, 0x2325B6DA};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 428 ");
	}
	{
		static const bigint_t var_a = {0xEEE1B586, 0xC77913C9, 0x85B8B795, 0x3138244C, 0x9C926809, 0xCF0F23FD, 0xEC4CF254, 0x0478D1D2};
		static const bigint_t var_expected = {0xDDC36B0C, 0x8EF22793, 0x0B716F2B, 0x62704899, 0x3924D012, 0x9E1E47FB, 0xD899E4A9, 0x08F1A3A5};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 429 ");
	}
	{
		static const bigint_t var_a = {0x4A9381AF, 0x4F9EDE8A, 0x514D8920, 0x4D25C094, 0x0373477E, 0xCD6B80E7, 0x9C19882B, 0x7E1B1F81};
		static const bigint_t var_expected = {0x32FACEC3, 0xA04F3363, 0xCE2332F9, 0x8739D487, 0xB3040547, 0x9F76A562, 0xF814342E, 0x4222A040};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 430 ");
	}
	{
		static const bigint_t var_a = {0x1B3FA9A8, 0xBE104E78, 0x4090A0E4, 0x03790838, 0xB0715DC5, 0xCCCE27E6, 0xCA5436D5, 0x48606C50};
		static const bigint_t var_expected = {0x367F5350, 0x7C209CF0, 0x812141C9, 0x06F21070, 0x60E2BB8A, 0x999C4FCD, 0x94A86DAB, 0x90C0D8A1};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 431 ");
	}
	{
		static const bigint_t var_a = {0x8478E58A, 0xC49F1948, 0x0511ACFD, 0x52EE5A98, 0x1C4EBA1B, 0xB65C35E4, 0x0876DA0C, 0x949AE6EA};
		static const bigint_t var_expected = {0xA6C59679, 0x8A4FA8DF, 0x35AB7AB4, 0x92CB088F, 0xE4BAEA81, 0x71580F5C, 0xD0CED7F0, 0x6F222F11};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 432 ");
	}
	{
		static const bigint_t var_a = {0xF45949EA, 0xF656842E, 0x9992B54C, 0x560356DC, 0xE9E8161E, 0x207CDEA0, 0x1D53908C, 0x26C01328};
		static const bigint_t var_expected = {0xE8B293D4, 0xECAD085D, 0x33256A99, 0xAC06ADB9, 0xD3D02C3C, 0x40F9BD41, 0x3AA72118, 0x4D802650};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 433 ");
	}
	{
		static const bigint_t var_a = {0xF6B7CEDD, 0x49F05EC7, 0xC2C4561B, 0x3B69FBA0, 0x5FD32A34, 0xB46B199F, 0x031D6799, 0x2C9C4DA6};
		static const bigint_t var_expected = {0xED6F9DBA, 0x93E0BD8F, 0x8588AC36, 0x76D3F741, 0xBFA65468, 0x68D6333E, 0x063ACF33, 0x59389B4C};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 434 ");
	}
	{
		static const bigint_t var_a = {0xDEEDB7A4, 0x9DE6EC45, 0x3950E9A9, 0xFE63EE76, 0xA118C6A3, 0xD958D80B, 0xE939AA0C, 0x7ED6A501};
		static const bigint_t var_expected = {0x5BAF3AAD, 0x3CDF4EDA, 0x9E29F40C, 0xE9B6304B, 0xEE4F0392, 0xB75153AB, 0x925477F0, 0x4399AB41};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 435 ");
	}
	{
		static const bigint_t var_a = {0x1C5EDADC, 0x30C4B0C8, 0x7F0F85AB, 0xAEA3958F, 0x79F1E88C, 0x099A9BA1, 0x31609C60, 0x6095C0DE};
		static const bigint_t var_expected = {0xD691811D, 0x629AD7DE, 0x29A72C0F, 0x4A357E7E, 0xA0014764, 0x17D4DAD7, 0x22A25C97, 0x0717E2FA};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 436 ");
	}
	{
		static const bigint_t var_a = {0xD2B766CA, 0x260069A7, 0x35122C32, 0x8B1E29AA, 0x2C945C3C, 0x66CA781B, 0xB3ACB624, 0x5D079BFE};
		static const bigint_t var_expected = {0xA56ECD94, 0x4C00D34F, 0x6A245864, 0x163C5354, 0x5928B879, 0xCD94F036, 0x67596C48, 0xBA0F37FD};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 437 ");
	}
	{
		static const bigint_t var_a = {0xB490A5A6, 0x0906BB25, 0x703F6EDD, 0x9667D0FA, 0x579C81E5, 0x36BB61A0, 0x7944E488, 0x877307E3};
		static const bigint_t var_expected = {0x06F516B1, 0x131EEC9A, 0x0C06FE73, 0x19BDF554, 0x5B567A16, 0x721666D5, 0xB26AECE7, 0x54D27104};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 438 ");
	}
	{
		static const bigint_t var_a = {0x2AF759BF, 0x43EFC61F, 0x63D8DA8D, 0x04F19C5E, 0x15FEC599, 0x683422C8, 0x01888391, 0x3A320008};
		static const bigint_t var_expected = {0x55EEB37E, 0x87DF8C3E, 0xC7B1B51A, 0x09E338BC, 0x2BFD8B32, 0xD0684590, 0x03110722, 0x74640010};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 439 ");
	}
	{
		static const bigint_t var_a = {0xBA5E0635, 0xA466AD24, 0x0A9ABD6C, 0x1CCB2C4E, 0x269D0A62, 0xFC84A1FB, 0xFED1F7BE, 0x3C2C1430};
		static const bigint_t var_expected = {0x74BC0C6A, 0x48CD5A49, 0x15357AD9, 0x3996589C, 0x4D3A14C4, 0xF90943F6, 0xFDA3EF7D, 0x78582861};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 440 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 441 ");
	}
	{
		static const bigint_t var_a = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		static const bigint_t var_expected = {0x622C349A, 0xFEEE89B1, 0xD477DF46, 0x1311ACA0, 0x53E289B5, 0xFB605C6B, 0x401EDC28, 0xBA139EC2};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 442 ");
	}
	{
		static const bigint_t var_a = {0x4B16722F, 0xE32C4517, 0x8331D290, 0xDD51F288, 0xD2005859, 0xB6A344CE, 0x17130AFC, 0x432DE88C};
		static const bigint_t var_expected = {0xC1131AA7, 0xF47E05E0, 0x324EC276, 0x6A6D3851, 0x8DEAC62A, 0x2A200914, 0x78C80348, 0x138A1EBF};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 443 ");
	}
	{
		static const bigint_t var_a = {0x6B90184E, 0x146DB975, 0x03AC7EAF, 0xA8C03142, 0x53620260, 0x5C9FDD47, 0x2764A6E0, 0x574D950C};
		static const bigint_t var_expected = {0x5295E8A2, 0x6C253FE3, 0xC1D0D7CD, 0xC7389BFE, 0xB98DF70A, 0xEDB15BAC, 0xA94066C3, 0x9B774784};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 444 ");
	}
	{
		static const bigint_t var_a = {0x0FC872B9, 0x37AE9E1E, 0xE7AB1F40, 0x9BB75003, 0x6F85B8BA, 0x735F3263, 0xFBCD64B9, 0x710B4D58};
		static const bigint_t var_expected = {0xCB44DEC4, 0x5D314CA9, 0x23E50952, 0x290EE896, 0x28B48226, 0xB592BBCA, 0x48B05D78, 0x0836DB5E};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 445 ");
	}
	{
		static const bigint_t var_a = {0xE34AE977, 0xAA97AB1A, 0x7B21DDF0, 0xD194EF55, 0x37ED39CD, 0x9C53AA55, 0x57DA33FF, 0x3878ADAC};
		static const bigint_t var_expected = {0x4D622910, 0x259C88C2, 0x12725433, 0xB409B952, 0x4B3B967D, 0x815372DB, 0x8FDC26C0, 0x98BAB48E};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 446 ");
	}
	{
		static const bigint_t var_a = {0xCFD72DEA, 0xB1FE5E1A, 0x7C2552C9, 0xE228DC47, 0x9197F12E, 0x08F95CBA, 0x72CB1ABA, 0x88A29EBE};
		static const bigint_t var_expected = {0xBD2AAB92, 0x4D01071B, 0x1688C6ED, 0xE3AF15EA, 0x4133EB58, 0x507BD834, 0x1DDFD3EE, 0x0326A57D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 447 ");
	}
	{
		static const bigint_t var_a = {0x04BE3503, 0xF5165E44, 0x236DDB5D, 0xB8D88F37, 0xBC0D8E04, 0x2D8100C2, 0x358459DC, 0x65592922};
		static const bigint_t var_expected = {0x2184F514, 0x1E939475, 0x3618A2A2, 0x57888BE9, 0xF8F8F6CC, 0xBF6C7DAB, 0x49749B30, 0x2F56C742};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 448 ");
	}
	{
		static const bigint_t var_a = {0xEAAAD205, 0x03027C80, 0x17FA8B60, 0xBB1489B6, 0xC7AFD490, 0x15DBD8BE, 0xFF74E370, 0x02742118};
		static const bigint_t var_expected = {0x6231B3B3, 0x8A90811B, 0x446989D9, 0x709D0F51, 0x9540326B, 0x1D60C233, 0x3A3CB6AC, 0x760A3814};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 449 ");
	}
	{
		static const bigint_t var_a = {0xA538E0A3, 0xC787C906, 0xF4699648, 0x4E3DD4B6, 0x115B2099, 0xE1E38AB6, 0x2439C6CC, 0x49692770};
		static const bigint_t var_expected = {0xA7104F56, 0x723D7B87, 0xE3432BD1, 0x23360861, 0xC0B8F9FF, 0x48BB74B5, 0x385100C4, 0xA0B135F7};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 450 ");
	}
	{
		static const bigint_t var_a = {0xBF11C07B, 0x1C09FA97, 0x77583F03, 0x95E2B442, 0x84893C2B, 0x745E5904, 0xE9DBDE2B, 0x0D3809F5};
		static const bigint_t var_expected = {0xF89CDAE7, 0xDE6FAA20, 0x1456068F, 0xE055DD42, 0xD40AA486, 0xEC10EDC5, 0xA9C87E92, 0x2C26A8A4};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 451 ");
	}
	{
		static const bigint_t var_a = {0x66B46009, 0x32596CDA, 0x7759C647, 0x0ED80A42, 0xF9DAE96E, 0xB2ED8E05, 0xCAE0581B, 0x774BF1B3};
		static const bigint_t var_expected = {0x296AEE38, 0xCC29BF18, 0x458089E4, 0xC97F5D87, 0xEDC442AE, 0xB467AC64, 0x01E51E19, 0x3B8A2E30};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 452 ");
	}
	{
		static const bigint_t var_a = {0x2C61DF16, 0x2B257E92, 0xEFA8B094, 0xF9398AC6, 0xD5683BD6, 0x44509EC5, 0x3590571A, 0x9F1F6B81};
		static const bigint_t var_expected = {0xCFEA0F14, 0xB8F6F1F2, 0x258FA02E, 0xF8304D7E, 0xCBC5FDF5, 0x115D889A, 0xBD7A63D5, 0x5B391C70};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 453 ");
	}
	{
		static const bigint_t var_a = {0xC3C7EBFE, 0x85315096, 0xA1DCCC96, 0xA258F13E, 0x1F66CD1B, 0xE2F1CFF7, 0xCC26DA1B, 0x09F746A3};
		static const bigint_t var_expected = {0x8C2E7DD4, 0xBF5D8BAE, 0x8F5A0383, 0xA98008A7, 0x18296C7A, 0xEFE0AA0D, 0x6B2CB509, 0x73C7CB43};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 454 ");
	}
	{
		static const bigint_t var_a = {0x8A4C15DE, 0xA537321C, 0x6DE71640, 0x8992AC47, 0x60EA9220, 0xF00B3745, 0xA7F0E7A3, 0x8064DC1B};
		static const bigint_t var_expected = {0xD8ABDDB4, 0xFBA87C10, 0x126F552A, 0x0F5CFF77, 0xFD735245, 0x2C6B498F, 0x2AED3CB4, 0x503EED4D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 455 ");
	}
	{
		static const bigint_t var_a = {0x79A2AC96, 0x53EDE8A3, 0xA8BBB9DB, 0xF2AAA4F6, 0x725A7982, 0xF29500A7, 0x10EA584C, 0x565B283B};
		static const bigint_t var_expected = {0x327FE8FC, 0x9A1DBB94, 0xD20C8CAC, 0x277E4C5E, 0xBF60B265, 0x04493F62, 0x2EB0A99C, 0x353FB5C2};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 456 ");
	}
	{
		static const bigint_t var_a = {0x365CEB45, 0x3BBEF9B3, 0xC5CD7D15, 0x500D08F8, 0xB25D5355, 0x19069AD1, 0xC4F404B6, 0x2727E136};
		static const bigint_t var_expected = {0x810E05B3, 0x5563CA4C, 0xD5B2E3C1, 0x9D034FB7, 0x89291E07, 0x633D6634, 0x120ADD85, 0x6671712E};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 457 ");
	}
	{
		static const bigint_t var_a = {0x24B168AA, 0x6DC08452, 0x2BBE44B1, 0x15763BD7, 0xCA88CA48, 0xA980DEF1, 0x796D4183, 0x3FDC24CA};
		static const bigint_t var_expected = {0x352F68A8, 0xCDFC262C, 0xDF15F8B2, 0xD4D37484, 0xE1599091, 0xD7CFDA4B, 0xAF8AA6B9, 0x04651025};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 458 ");
	}
	{
		static const bigint_t var_a = {0x5D3A7FE9, 0xA0F02F05, 0x6F90D8E3, 0x83D33FE8, 0x42F3396E, 0xAFC08193, 0x37A05EE2, 0x060F80C3};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 215 ");
	}
	{
		static const bigint_t var_a = {0x34E5C8CC, 0x359617C5, 0x08D2C04F, 0xEE944508, 0xB7A67CE1, 0xD11B2857, 0xFED3A9DE, 0xA5C6D010};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 216 ");
	}
	{
		static const bigint_t var_a = {0xECABBA67, 0x7385FF87, 0xCB538108, 0xF6DEFD2D, 0xA1445A74, 0x6E139CB4, 0x4568F661, 0x654C0EAE};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 217 ");
	}
	{
		static const bigint_t var_a = {0xC9587427, 0xEB097C46, 0x2B35C36F, 0xB1E04FE9, 0x4A9ED3F8, 0x74F50D1D, 0x9701BA63, 0x0E8EAAED};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 218 ");
	}
	{
		static const bigint_t var_a = {0x0880B124, 0xC9B46031, 0xCB600ADE, 0x771AD287, 0x8B53411F, 0x25353055, 0xAD2EE259, 0x58BD8882};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 219 ");
	}
	{
		static const bigint_t var_a = {0x8E94A8B3, 0x69D76E07, 0xB596FC45, 0x9CEF44A0, 0x054FB24D, 0xC77371E8, 0x7BCACD68, 0x29F630E2};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 220 ");
	}
	{
		static const bigint_t var_a = {0x218EE9DC, 0xC1DFB016, 0x490EDBD8, 0x14F38843, 0x90C61ED2, 0xE078EFFB, 0x643B6DE6, 0x01F590D8};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 221 ");
	}
	{
		static const bigint_t var_a = {0x30BBECA2, 0xF15196FC, 0x4CCE2A6B, 0xCB4349CC, 0xC7E72977, 0xF97AD951, 0x00D98907, 0x847E6390};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 222 ");
	}
	{
		static const bigint_t var_a = {0x845E1809, 0xBC83BBC4, 0x89067586, 0x04B5A460, 0x2DEB35BB, 0xEFB746C9, 0x5D4EE504, 0x09DE59B3};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 223 ");
	}
	{
		static const bigint_t var_a = {0xD8D70494, 0x070701AA, 0x2BBB028F, 0x6FF56571, 0x034205A6, 0x869D3F03, 0x3BD8DDC8, 0x6F37C35C};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 224 ");
	}
	{
		static const bigint_t var_a = {0xBD264A5D, 0x5C381AC2, 0x100F5DDF, 0xC12CA7AD, 0x2068DC1C, 0xE5C13FAB, 0xCF0E8C7C, 0x5A5F3AFD};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 225 ");
	}
	{
		static const bigint_t var_a = {0x15915C3D, 0x696F7669, 0x4CE6669F, 0x34987E22, 0x6C22B9CA, 0x1A0C253E, 0x41609F61, 0xB0AF394F};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 226 ");
	}
	{
		static const bigint_t var_a = {0x9A99E7CC, 0x81BFEF83, 0xA4581867, 0x0437F2A3, 0x650DC3E7, 0x936CAB93, 0x2E5B5F0C, 0x1DECA4E5};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 227 ");
	}
	{
		static const bigint_t var_a = {0x55462131, 0x194861AF, 0x14F445B1, 0xF386041B, 0x9D7BCFEF, 0xA5257799, 0x26C99BEF, 0x8F36FBB6};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 228 ");
	}
	{
		static const bigint_t var_a = {0x27B7CFDB, 0x4C158747, 0x4ACF1D86, 0xC550EC3C, 0x39A412B9, 0x08A4EFCC, 0x2F9995DB, 0xBA1323EC};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 229 ");
	}
	{
		static const bigint_t var_a = {0x430CFB04, 0x5890C9E4, 0x286C4450, 0xC584C9DF, 0x742158A5, 0x58E76CA7, 0x409A2A68, 0x947F0266};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 230 ");
	}
	{
		static const bigint_t var_a = {0x5070510E, 0x20924D20, 0x71F2DC3B, 0x2C15BCF8, 0xC6DCD324, 0x9B1A1CF2, 0x86E6F218, 0x1FFDB71F};
		static const bigint_t var_expected = {0x51D82159, 0xAD163F28, 0xA87E33AF, 0x030A0D36, 0x897C096E, 0x6681C10C, 0xDFB596D2, 0x632F8498};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 231 ");
	}
	{
		static const bigint_t var_a = {0xCE7C2447, 0xA79929CE, 0x6D09FC90, 0x044DEA94, 0x0D99237F, 0xA6FC2A10, 0x24DA17F8, 0x8A32725C};
		static const bigint_t var_expected = {0x6B0E4EBD, 0x28AA56C9, 0x743220DA, 0x109C278C, 0xB8122784, 0x76DA2312, 0xE309A36A, 0x971A22F2};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 232 ");
	}
	{
		static const bigint_t var_a = {0xC7547263, 0x9AA0E655, 0x1D7CEFBD, 0xE9275694, 0xC4896019, 0xCF38D3B1, 0x2B05F53B, 0x675EF566};
		static const bigint_t var_expected = {0xE6CDB156, 0xE5A21C13, 0xCDE4FF54, 0x9F86A182, 0x8CDC3D2C, 0x5ABD816A, 0xC2BA00CE, 0x9986779F};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 233 ");
	}
	{
		static const bigint_t var_a = {0x34A73A0B, 0x9F811D03, 0x95023619, 0x7D10AB99, 0x3499A3A9, 0x826D5EE9, 0xD172DC22, 0x8A3DE0B7};
		static const bigint_t var_expected = {0x58546F40, 0xF2718661, 0xCF6A952C, 0xC4C81934, 0x505F0EB5, 0xEB8DAD6E, 0x72C867E7, 0x9759CD90};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 234 ");
	}
	{
		static const bigint_t var_a = {0xAB3FC86C, 0xB930B0FD, 0x5E7F6F0E, 0x696304E8, 0x3D683592, 0x11970B89, 0xDC1C6E05, 0xA99AC2F4};
		static const bigint_t var_expected = {0x91DB21A2, 0x50AF430A, 0x149F71F6, 0xEEF95668, 0x83ECC5B8, 0x73E5091E, 0x2B9622A6, 0x7CD3B901};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 235 ");
	}
	{
		static const bigint_t var_a = {0x05E928BE, 0x4EA86DFC, 0xB2F649AA, 0xF37E9E5A, 0xA8BBDE49, 0xC2FDB199, 0x6DF18778, 0xAB4F1FC1};
		static const bigint_t var_expected = {0x8A0967DD, 0x77DA9E84, 0xA3F36338, 0xF8BD20F2, 0xEA6185C4, 0xA3FBB942, 0x996CED08, 0x0CA58CDA};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 236 ");
	}
	{
		static const bigint_t var_a = {0x17B08261, 0xBD8CFCF0, 0x139EBA6D, 0x8311A5E2, 0x4E9089E0, 0x526AD89C, 0x1B79CAA3, 0xA574563B};
		static const bigint_t var_expected = {0x38E96A31, 0xE957F747, 0x067D44F9, 0xCBECAB89, 0xE8DE290F, 0xE1EC5EA5, 0x610339F3, 0xA310599E};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 237 ");
	}
	{
		static const bigint_t var_a = {0x54A748FD, 0x5666F204, 0x0E0E88EA, 0xEC6921A2, 0x15CBFD3C, 0x704D06F9, 0xF896ACE2, 0x352218DB};
		static const bigint_t var_expected = {0xDA00CB00, 0xCC97EDD4, 0x33FA957C, 0x89E6DD9B, 0x0D1DAFBC, 0x53DD8838, 0x7F272429, 0x351D30D6};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 238 ");
	}
	{
		static const bigint_t var_a = {0x32201E4C, 0x86B7F6B0, 0xA6A17481, 0x54840319, 0x7BB75435, 0x485C879C, 0x1E42DDC6, 0x74C02134};
		static const bigint_t var_expected = {0x81DC6466, 0x3CFED1BA, 0xD4E9EE53, 0xFCB52880, 0x3DA48755, 0xD659252D, 0x403A8C6F, 0x54B575E1};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 239 ");
	}
	{
		static const bigint_t var_a = {0xFDBE835C, 0x0699ED16, 0xC15D315E, 0xDDF34900, 0x1C744A02, 0x4F024C6E, 0x5E09B760, 0x143B3182};
		static const bigint_t var_expected = {0xB64BE3EA, 0x3CFDF8B3, 0x27AB63C2, 0x3BE4F80E, 0x44B1BD41, 0x7B097F5B, 0x3591C1E2, 0x92F7ABED};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 240 ");
	}
	{
		static const bigint_t var_a = {0x8B3D5DCA, 0x6120B663, 0x79ADEA2B, 0x32D6D9C3, 0x41614A2F, 0x2A67F063, 0x92841B2D, 0x3CE3F341};
		static const bigint_t var_expected = {0x55F97595, 0x3C0C4AD3, 0xC71AFBEF, 0x16BB98F1, 0xFF71ADD3, 0x77A75871, 0x8A13B679, 0xB81D5E5D};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 241 ");
	}
	{
		static const bigint_t var_a = {0xAC6AB73D, 0x53C52EE4, 0x4F5A5522, 0x6A5A729E, 0x59370BB4, 0x24E4BBB4, 0xF70B10E6, 0xB0B003E5};
		static const bigint_t var_expected = {0x66C81F9A, 0xB569E94B, 0x9746FCEF, 0x75082F90, 0xC66B1C4C, 0x57FBA525, 0x1093E78E, 0x2382AF7B};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 242 ");
	}
	{
		static const bigint_t var_a = {0x840B2A4E, 0x0E2D1183, 0xBBD1DF08, 0x33D36846, 0xB3C3D686, 0xE9BCD9D6, 0x82781957, 0x5D91BACC};
		static const bigint_t var_expected = {0x1DF2CF5B, 0x3BE44654, 0xD0CBCA78, 0x379CFFC4, 0x0919917C, 0x7265E135, 0x7AF7F5BC, 0x40DA32B6};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 243 ");
	}
	{
		static const bigint_t var_a = {0x4E149C76, 0xB4272AC9, 0xB81D41BA, 0xC46599AF, 0xD574F6FA, 0xEE6D494E, 0x43E6FC5F, 0x36A880B4};
		static const bigint_t var_expected = {0x145F2D61, 0x9F167D2A, 0x9D236642, 0x9F23DCD2, 0x8E014B87, 0xA7FC17C9, 0xF4096228, 0x9BAE6711};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 244 ");
	}
	{
		static const bigint_t var_a = {0xD0C2948A, 0x6FF53BDC, 0xF2DA9AA6, 0x25361185, 0x0CB71262, 0x5CA18FEB, 0x5894E449, 0x45887C04};
		static const bigint_t var_expected = {0x5C7A8517, 0xE9EB627A, 0x76981126, 0x4359B2E4, 0x40FAA2F6, 0xF8FCC481, 0xEE9C05DB, 0x593356DC};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 245 ");
	}
	{
		static const bigint_t var_a = {0x8C804B01, 0x960EF2BC, 0x5786C4D9, 0xDC0E2433, 0xA8B5AD78, 0x080E3AA2, 0x3A98236F, 0x945E35DE};
		static const bigint_t var_expected = {0xAB6EEF1E, 0x10D88FFE, 0xC82363BF, 0x57FC2F2F, 0x2EC6C006, 0x3DC5D679, 0xB4D5C5E9, 0x5744C1B1};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 246 ");
	}
#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const bigint_t var_a = {0x1D3E25AA, 0x46E58929, 0x68F87042, 0xBC6BD2DC, 0x9323115B, 0xDEDB25FF, 0x344C623A, 0xBF4BB419};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 293 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 294 ");
	}
	{
		static const bigint_t var_a = {0x14B5CE59, 0x92660424, 0x9EA24504, 0xF7374DFF, 0x15229889, 0x783122E5, 0xE49D4862, 0x46825F62};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 295 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 296 ");
	}
	{
		static const bigint_t var_a = {0x805C0B04, 0x2AD4FDD9, 0x6ED88555, 0x1F3868DE, 0x88EB4242, 0x034B5C15, 0x29BAB1BF, 0xFE66F787};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 297 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 298 ");
	}
	{
		static const bigint_t var_a = {0x32A36FB6, 0x6C7CEFC6, 0x5CE1E187, 0x9D3473ED, 0xC6BE2739, 0x3DFBB675, 0x9C1B4CD5, 0xFE8B5284};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 299 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 300 ");
	}
	{
		static const bigint_t var_a = {0xD462E9D6, 0x5A8FA3F6, 0x9F36BE16, 0xDFED41D9, 0x3D0002B6, 0x45E462D6, 0x497B295D, 0x23C30D4B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 301 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 302 ");
	}
	{
		static const bigint_t var_a = {0x60E6EAD4, 0x192F2AC4, 0xA0859CC3, 0xD4984904, 0x6ED891F5, 0x2080DBA4, 0x31ABB4EB, 0x8BD24217};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 303 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 304 ");
	}
	{
		static const bigint_t var_a = {0xA6408029, 0x7510308F, 0x7F82B254, 0x736B4155, 0x6F22E182, 0x35B94CE1, 0xC94098B8, 0x1939B180};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 305 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 306 ");
	}
	{
		static const bigint_t var_a = {0xCBF2489B, 0x5CAB589C, 0x8E8A98BF, 0x3439985F, 0x6AAAC781, 0xD212E364, 0x7A0FE0EC, 0xF5028B6E};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 307 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 308 ");
	}
	{
		static const bigint_t var_a = {0xC5E28FA0, 0x5FFB7D87, 0xD4163A1D, 0x951F51C5, 0x1CBC48F5, 0xA561C815, 0x1F73DFB4, 0x09AE57D2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 309 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 310 ");
	}
	{
		static const bigint_t var_a = {0xE0A1FB06, 0x34D0F7E8, 0x8BFE717F, 0x96421952, 0x5601A405, 0x4314CFBB, 0x8A6AA6DB, 0x851E9F31};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 311 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 312 ");
	}
	{
		static const bigint_t var_a = {0x3B0391BD, 0x36AE4C11, 0xA189FCA3, 0x3D99A8B7, 0x80B0332B, 0xA40B0EC7, 0xFF810FE5, 0x5BA34E69};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 313 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 314 ");
	}
	{
		static const bigint_t var_a = {0x4C0202BB, 0xE33EEE08, 0x3B53A98B, 0x14CABF03, 0x110B72EC, 0xA503EF7F, 0xB68DB072, 0xC30A0AC2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 315 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 316 ");
	}
	{
		static const bigint_t var_a = {0x58F9827F, 0x5D51E353, 0x2EFCF62F, 0xA61755E0, 0x182CC08E, 0x858B71C6, 0x5D34383F, 0xB9C6DA60};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 317 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 318 ");
	}
	{
		static const bigint_t var_a = {0xFC27A09E, 0xEA6A8153, 0x85AD82EC, 0x055DC26E, 0xB626C8B2, 0x688EA4BC, 0x95490223, 0x7A21EF5B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 319 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 320 ");
	}
	{
		static const bigint_t var_a = {0xA789CD12, 0x75E79782, 0xFE6AF5B4, 0x471A0617, 0xA2749456, 0xD76B9876, 0x70F8EC63, 0x0B825B3F};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 321 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 322 ");
	}
	{
		static const bigint_t var_a = {0x1DFCAAD9, 0x0AAAAE32, 0x8C3559DB, 0x049169F4, 0xA4B4B620, 0x3EA04B10, 0xFABDB809, 0xB2C00F9A};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 323 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 324 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 325 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 326 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 327 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 328 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_b = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 329 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 330 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 331 ");
	}
	{
		static const bigint_t var_a = {0xF5B53644, 0x685D3AE3, 0xD6FDFFC2, 0xB78D1DA1, 0x1AB91710, 0x3F606AD8, 0xED337D0A, 0x0B2144B8};
		static const bigint_t var_b = {0x1C0D686F, 0xA844E8C5, 0xB7666660, 0x650FA202, 0x76E64A8C, 0x2FA21094, 0xFAA9FC0A, 0x204CC23D};
		static const bigint_t var_expected = {0x11C29EA0, 0x69A223A9, 0x8E64660F, 0xBB7BBFA4, 0x919F6194, 0xB4CE2DEC, 0xA7DD7912, 0x064AA274};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 332 ");
	}
	{
		static const bigint_t var_a = {0x518DEC39, 0x439A6385, 0xBC57BC52, 0x34E80661, 0xBDE17E26, 0x28CA3742, 0x0792E084, 0x020B01EC};
		static const bigint_t var_b = {0xA65E0159, 0xD98336EE, 0xA95FFDCA, 0xCEBB5583, 0x098F6508, 0x269F2D20, 0xECBB28B8, 0x0986DC9F};
		static const bigint_t var_expected = {0xF7EBED92, 0x1D1D9A73, 0x65B7BA1D, 0x03A35BE5, 0xC770E32F, 0x4F696462, 0xF44E093C, 0x0B91DE8B};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 333 ");
	}
	{
		static const bigint_t var_a = {0x05FCA275, 0xCB8FA8AB, 0xF4E6C24A, 0x7545C8C3, 0x0960AD84, 0xFDE50BB3, 0xB5595723, 0x01B0ACFA};
		static const bigint_t var_b = {0xA9398DB7, 0x54C5BCE4, 0x48323A53, 0xE7B4810E, 0x7CF2E4ED, 0xAB8D3C79, 0xA3E1231E, 0x0A235DF8};
		static const bigint_t var_expected = {0xAF36302C, 0x2055658F, 0x3D18FC9E, 0x5CFA49D2, 0x86539272, 0xA972482C, 0x593A7A42, 0x0BD40AF3};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 334 ");
	}
	{
		static const bigint_t var_a = {0xA19BC59F, 0x4748B127, 0x0435E863, 0x51E8EB85, 0xB9FEE949, 0x08EA1073, 0x6BB3BE3B, 0x1C30289D};
		static const bigint_t var_b = {0x50FCA95D, 0x5787A2BC, 0xBA332594, 0x39FC1618, 0x2B962875, 0xE59A4F3E, 0x3597EF88, 0x0F002304};
		static const bigint_t var_expected = {0xF2986EE9, 0xF7D053E3, 0xBE690DE3, 0x2AC4019D, 0xE59511B6, 0x34501231, 0x614BADC2, 0x060CE71F};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 335 ");
	}
	{
		static const bigint_t var_a = {0xF082BD3F, 0x34FB332A, 0xB0367A5D, 0x098391A8, 0xCDB1670F, 0x03B350F0, 0x9E03990B, 0x0A9F8E7E};
		static const bigint_t var_b = {0x0AEAAD2C, 0x027B6071, 0x624C4ABF, 0x319AA092, 0xB210DA77, 0x370274A3, 0x76396A13, 0x13C1D9AE};
		static const bigint_t var_expected = {0xFB6D6A6B, 0x3776939B, 0x1282C51C, 0x3B1E323B, 0x7FC24186, 0x3AB5C594, 0x143D031E, 0x1E61682D};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 336 ");
	}
	{
		static const bigint_t var_a = {0xFF154ADA, 0x7C18D447, 0xFE9B7105, 0x8AE1E02F, 0x7F66A225, 0x2DBD3D8B, 0x0331CA60, 0x1085837E};
		static const bigint_t var_b = {0x83FB6A19, 0x8C937162, 0xE647C4DA, 0x0C88A4BF, 0xEFD91D9B, 0x0212B44A, 0x7D5345BA, 0x0E187A19};
		static const bigint_t var_expected = {0x8310B4F3, 0x08AC45AA, 0xE4E335E0, 0x976A84EF, 0x6F3FBFC0, 0x2FCFF1D6, 0x8085101A, 0x1E9DFD97};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 337 ");
	}
	{
		static const bigint_t var_a = {0x1CD6F298, 0xCD59E5B3, 0x32209740, 0xD245A683, 0x4ED38F2B, 0x4DB90F3F, 0x10000861, 0x1D782182};
		static const bigint_t var_b = {0xA7AE85A7, 0x3416685D, 0x2B25BC72, 0x3EB0D126, 0xFF1A0980, 0x1423F24E, 0x9DEF2FBF, 0x0F8F0D24};
		static const bigint_t var_expected = {0xC485782C, 0x5A704E10, 0x5D46539F, 0xAFD577A9, 0x4DED98A3, 0xA7A8B40E, 0x6DEF381E, 0x07E3CA24};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 338 ");
	}
	{
		static const bigint_t var_a = {0xD4318467, 0x59D312F2, 0xD1D99BD4, 0x0056488B, 0xF747A4A4, 0x098F9266, 0xB857FE61, 0x22FD3AE6};
		static const bigint_t var_b = {0xA5D66594, 0x34AB6697, 0x57665CB0, 0x4ED7ECEC, 0x3F7E71CF, 0x91FECCCC, 0xEBE834F5, 0x03B5050A};
		static const bigint_t var_expected = {0x7A07E9E8, 0xE77E798A, 0x293FF870, 0xEE0D3578, 0x36C6166A, 0xE15A11B3, 0x64403354, 0x018EDB6F};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 339 ");
	}
	{
		static const bigint_t var_a = {0xF354A558, 0xCA06EA7F, 0xA18A2AC2, 0xC41FF5DD, 0x757DAB17, 0x626312EF, 0x72962778, 0x1C4FD15C};
		static const bigint_t var_b = {0xE96BAC7C, 0xC56CFD36, 0xCD60384F, 0x663D8303, 0x4BFF0EFB, 0x847BE082, 0xBE364D72, 0x0446DFFC};
		static const bigint_t var_expected = {0xDCC051D4, 0x8F73E7B6, 0x6EEA6312, 0x2A5D78E1, 0xC17CBA13, 0xE6DEF371, 0x30CC74EA, 0x2096B159};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 340 ");
	}
	{
		static const bigint_t var_a = {0x87F88618, 0xDDE94937, 0xA7EFE324, 0x9C1615A0, 0x07667533, 0x511B2BD2, 0xF2E45807, 0x0BB2F3D1};
		static const bigint_t var_b = {0x205C517F, 0x3EF66A4F, 0x338D27DE, 0x0FED63EA, 0x02BBF781, 0x79E04150, 0xA941262A, 0x141BD750};
		static const bigint_t var_expected = {0xA854D797, 0x1CDFB386, 0xDB7D0B03, 0xAC03798A, 0x0A226CB4, 0xCAFB6D22, 0x9C257E31, 0x1FCECB22};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 341 ");
	}
	{
		static const bigint_t var_a = {0xDC329D65, 0xE600B66A, 0x27115430, 0xE40006E7, 0x29FD5692, 0x55D71625, 0xEE7E02B3, 0x0630FB72};
		static const bigint_t var_b = {0x375A467A, 0x1676416E, 0x6ED79443, 0x0E61D6FB, 0x7FBF604F, 0x55CE0A29, 0x42321CC2, 0x1517834E};
		static const bigint_t var_expected = {0x138CE3DF, 0xFC76F7D9, 0x95E8E873, 0xF261DDE2, 0xA9BCB6E1, 0xABA5204E, 0x30B01F75, 0x1B487EC1};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 342 ");
	}
	{
		static const bigint_t var_a = {0x8047720E, 0x0D698DFC, 0xA692DFFD, 0x269215BC, 0x99177F5F, 0x8CE20402, 0x5909247A, 0x1319F08C};
		static const bigint_t var_b = {0x5BAEB324, 0x2FBE6F1C, 0xA3EE4175, 0x4A419C7C, 0x20DCC66B, 0xF9D77350, 0xDD3E6837, 0x169EF0F4};
		static const bigint_t var_expected = {0xDBF6251F, 0x9627FD18, 0x4A81215E, 0x0FB2B239, 0xB9F445C2, 0xCC8529D2, 0xF6478CB0, 0x04957CFE};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 343 ");
	}
	{
		static const bigint_t var_a = {0x3F778C34, 0x98ED25F2, 0xEA02A1F2, 0x5232C317, 0x53331EFD, 0x9A9B373A, 0x6AE3F4C7, 0x1C39C742};
		static const bigint_t var_b = {0xF905C834, 0x3B51AEF3, 0x36957DE0, 0xDB7CB1E8, 0x82715C47, 0xE1596CE8, 0x10FD82E4, 0x192EB1F2};
		static const bigint_t var_expected = {0x387D5455, 0x2D3ED4E6, 0x20981FBF, 0xCC8E7500, 0xD5A47B3C, 0xC1C056A2, 0x3BE177AA, 0x104514B2};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 344 ");
	}
	{
		static const bigint_t var_a = {0x28D067B8, 0x900CCB43, 0xF72B3640, 0xECC3466E, 0x94476847, 0x2E9A93F5, 0x956F4050, 0x13F9FC05};
		static const bigint_t var_b = {0xBE431C19, 0xE1745029, 0xCEF0D373, 0x54A7D335, 0x8241D19B, 0x5565B926, 0x30B3BA93, 0x0FE2A308};
		static const bigint_t var_expected = {0xE71383D1, 0x71811B6C, 0xC61C09B4, 0x416B19A4, 0x168939E3, 0x84004D1C, 0xC622FAE3, 0x23DC9F0D};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 345 ");
	}
	{
		static const bigint_t var_a = {0x85FD8390, 0xDC14A1EA, 0x136385B1, 0xFB5052A6, 0xDA945B16, 0xE3A387C3, 0x4F677648, 0x17AFB8B9};
		static const bigint_t var_b = {0x984FAB20, 0xEE3E79AF, 0x4FDA22F9, 0xD294CD04, 0x3D3F6DD6, 0x3B776246, 0x52A5FDCF, 0x0F1FCDAE};
		static const bigint_t var_expected = {0x1E4D2E9D, 0x23531B9A, 0x633DA898, 0x6CC41FAA, 0x17D3C8E5, 0x64E69C8A, 0x620D7416, 0x01AC21E5};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 346 ");
	}
	{
		static const bigint_t var_a = {0xE517860E, 0x8C2A6C6D, 0xC2D87B56, 0x4CF82893, 0xE0746F09, 0x32B72C3E, 0x0D2F6FE0, 0x0B0FEE00};
		static const bigint_t var_b = {0xB2E65DA0, 0x24A9B44D, 0xDE2D3C35, 0xEDDE85FA, 0x0F5F7F3F, 0x42DB7082, 0x4A67D86F, 0x1F078685};
		static const bigint_t var_expected = {0x97FDE39B, 0x09D420BB, 0xA105B778, 0xD9B5AE8E, 0xEFD3EE40, 0xBB5E4F40, 0x1797484D, 0x04F41003};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 347 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 348 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 349 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 350 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 351 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_b = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 352 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 353 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 354 ");
	}
	{
		static const bigint_t var_a = {0x15756E81, 0x13613B6D, 0xCAE8B5BC, 0x4374E44A, 0xA62A08CC, 0x0277C7BE, 0x051FE4A0, 0x1A0CE618};
		static const bigint_t var_b = {0x7B6B2A58, 0x8FA1F451, 0xE01ADE1F, 0x5C54CCB9, 0x96662052, 0x3095E91E, 0x6E2CA89C, 0x19E6D733};
		static const bigint_t var_expected = {0x9A0A4429, 0x83BF471B, 0xEACDD79C, 0xE7201790, 0x0FC3E879, 0xD1E1DEA0, 0x96F33C03, 0x00260EE4};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 355 ");
	}
	{
		static const bigint_t var_a = {0x2278E1A8, 0xF6C2F7F2, 0x2F6A25F4, 0x547411F2, 0x66B2C4C9, 0x7C1FF53C, 0xEBD89BCD, 0x1BEEE097};
		static const bigint_t var_b = {0x9EB5C8B5, 0x9D15F2BA, 0xF97339D3, 0x62BAFC36, 0xAFBC49A1, 0x34E168EF, 0xD31601EE, 0x201D7675};
		static const bigint_t var_expected = {0x83C31906, 0x00AD0537, 0x35F6EC35, 0x52DA15BB, 0xB6F67B30, 0x0172D9CC, 0x58C299E1, 0x20F4CEA4};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 356 ");
	}
	{
		static const bigint_t var_a = {0x586189AC, 0xE364D77E, 0x36FFA12C, 0x7A5F85D5, 0x9F919F30, 0x66092D6E, 0x33924A65, 0x01412F42};
		static const bigint_t var_b = {0x0AE2F996, 0x5405F2FC, 0x10FFDB8F, 0x6B764A5E, 0x77394024, 0x4A7F32CE, 0xCD8748D0, 0x196DAD98};
		static const bigint_t var_expected = {0x4D7E9029, 0x365EE482, 0x25FFC5B1, 0x700A3B77, 0x28585F14, 0xD5BE4820, 0xA60B0196, 0x0CF6E62B};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 357 ");
	}
	{
		static const bigint_t var_a = {0x441E8384, 0x7076B41A, 0x656572B5, 0x523D7AEB, 0x0DA7E307, 0x7DB74935, 0xD56D26B8, 0x24ABB0E4};
		static const bigint_t var_b = {0xEB22647E, 0x7593EEC1, 0x48C51420, 0x0FE2E945, 0x4BF652A8, 0x24591C60, 0x32708300, 0x0DA9373E};
		static const bigint_t var_expected = {0x58FC1F06, 0xFAE2C558, 0x1CA05E94, 0x425A91A6, 0xC1B1905F, 0x595E2CD4, 0xA2FCA3B8, 0x170279A6};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 358 ");
	}
	{
		static const bigint_t var_a = {0xB419E3A3, 0x515248F0, 0x80C5CE2D, 0x6756F114, 0xAEFAF3D8, 0x96D9A1DE, 0x83BE2F3B, 0x14736921};
		static const bigint_t var_b = {0xAD8F0265, 0xD5152446, 0x0863CB6F, 0xB6BEED64, 0xC71DEE6B, 0x6E591C3E, 0x17A0589A, 0x0423B0C3};
		static const bigint_t var_expected = {0x068AE13E, 0x7C3D24AA, 0x786202BD, 0xB09803B0, 0xE7DD056C, 0x2880859F, 0x6C1DD6A1, 0x104FB85E};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 359 ");
	}
	{
		static const bigint_t var_a = {0xB50B59BF, 0x238C4A24, 0x8D034DE3, 0xA1AD56B8, 0xBE8DED53, 0x341BE15E, 0x33642DDE, 0x1F4DE138};
		static const bigint_t var_b = {0xFFF42854, 0x2E220232, 0xF357CB83, 0xAD5BEE87, 0xCABB011C, 0x108A02C3, 0x51184738, 0x1182A40D};
		static const bigint_t var_expected = {0xB517316B, 0xF56A47F1, 0x99AB825F, 0xF4516830, 0xF3D2EC36, 0x2391DE9A, 0xE24BE6A6, 0x0DCB3D2A};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 360 ");
	}
	{
		static const bigint_t var_a = {0x93C9CEA5, 0xCC0274F7, 0xD10E4BE9, 0x4C1A678E, 0xBA2A0DFB, 0x3200CD05, 0x9B145DF4, 0x09000E6A};
		static const bigint_t var_b = {0xCDA41BB3, 0x93A48012, 0xF05683EB, 0xF432797C, 0x6F8DBCCE, 0x961E64A6, 0x3455107D, 0x04C0B209};
		static const bigint_t var_expected = {0xC625B2F2, 0x385DF4E4, 0xE0B7C7FE, 0x57E7EE11, 0x4A9C512C, 0x9BE2685F, 0x66BF4D76, 0x043F5C61};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 361 ");
	}
	{
		static const bigint_t var_a = {0xDC153A2B, 0x5BEE656E, 0xCF314368, 0xEFF363BA, 0x5F3503F3, 0xC82D8748, 0xEFA9D76F, 0x0C9365A1};
		static const bigint_t var_b = {0x44463B0B, 0xDCE5D8D0, 0x22963825, 0xDF9936AC, 0x14D19AE7, 0x515BD79D, 0x16A6562A, 0x068C374B};
		static const bigint_t var_expected = {0x97CEFF20, 0x7F088C9E, 0xAC9B0B42, 0x105A2D0E, 0x4A63690C, 0x76D1AFAB, 0xD9038145, 0x06072E56};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 362 ");
	}
	{
		static const bigint_t var_a = {0x5D7063AB, 0x44F17401, 0x4F62190B, 0x37BD7786, 0xAB7AFCEE, 0x21034CA4, 0xA477A96C, 0x026A74BC};
		static const bigint_t var_b = {0xD1A5C46B, 0xBAA5A2CA, 0xF01EAE3D, 0x8383E220, 0x5616C963, 0xC0297AA4, 0x8B776F95, 0x1535DDC1};
		static const bigint_t var_expected = {0x8BCA9F53, 0x314BD136, 0x5F436AE1, 0x155A9565, 0x55643393, 0x1B0E1F80, 0x590039D8, 0x1257FB7D};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 363 ");
	}
	{
		static const bigint_t var_a = {0x22E6DAE8, 0x79295815, 0x539161E4, 0xA77A775D, 0xDA009F37, 0x08F483BD, 0x70999E80, 0x1028FB19};
		static const bigint_t var_b = {0x228523FF, 0x4E23556B, 0xFD1D4035, 0x63F403AA, 0x120EDBB5, 0x9E8FAE36, 0x2AA569B5, 0x083ACC96};
		static const bigint_t var_expected = {0x0061B6E9, 0x2B0602AA, 0x567421AF, 0x438673B2, 0xC7F1C382, 0x6A64D587, 0x45F434CA, 0x07EE2E83};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 364 ");
	}
	{
		static const bigint_t var_a = {0x78E1F069, 0x893EBC3D, 0x23FB9050, 0xEA85D5DA, 0x6AD7BAEF, 0x15EE783A, 0x4641C360, 0x22080D27};
		static const bigint_t var_b = {0x226BDECA, 0xEC332C68, 0x2F3372E9, 0xAE965F1D, 0x645AD677, 0x5C675B91, 0xC6CC4739, 0x10846C78};
		static const bigint_t var_expected = {0x5676119F, 0x9D0B8FD5, 0xF4C81D66, 0x3BEF76BC, 0x067CE478, 0xB9871CA9, 0x7F757C26, 0x1183A0AE};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 365 ");
	}
	{
		static const bigint_t var_a = {0xEEF9C8CF, 0x8F70BA8A, 0x417728D0, 0x6971DA09, 0x17E7EE4D, 0x4F755DFC, 0x9D089887, 0x0337E9D2};
		static const bigint_t var_b = {0xFF730D4A, 0xD04871FF, 0xABC1F793, 0xEAF241EB, 0xAB5E9130, 0x227627C4, 0x74956E5A, 0x1A16246F};
		static const bigint_t var_expected = {0xEF86BB98, 0x6628488A, 0x95B53150, 0xDFA0981D, 0x6C895D24, 0xE73383B7, 0x68732A2E, 0x0E4529E5};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 366 ");
	}
	{
		static const bigint_t var_a = {0x4EC47F3C, 0x99AD3362, 0x74C8D15E, 0x50282D2D, 0xDEC10268, 0xCA73F131, 0xE93EFA34, 0x1E79E9E8};
		static const bigint_t var_b = {0x27216A30, 0x1C8928DC, 0xD63F2194, 0x8614777F, 0x820F6676, 0x510D7CAC, 0x0B0D479A, 0x2038431F};
		static const bigint_t var_expected = {0x27A3151F, 0x24240A86, 0x9E89AFDE, 0x2B34B5AD, 0x5CB19BFA, 0x339AC205, 0x1E31B29C, 0x23650B4C};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 367 ");
	}
	{
		static const bigint_t var_a = {0xA8A264E0, 0x909A0FA6, 0xC1EC6FED, 0x463193A7, 0xFC722E84, 0x80F0AB69, 0x9F3BC0DF, 0x09EE8AAC};
		static const bigint_t var_b = {0x4529F83B, 0x74E1217F, 0x5687D0E9, 0x16961A28, 0xC7C238C9, 0x35A1D825, 0xDEEB14E2, 0x15CB16B4};
		static const bigint_t var_expected = {0x63786CB8, 0xC2B8EE27, 0x6B649F17, 0x90BC797F, 0x34AFF5C3, 0x058320C4, 0x0050ABFF, 0x1946D87A};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 368 ");
	}
	{
		static const bigint_t var_a = {0x4794475F, 0x66A75F28, 0x6C6D2906, 0x74C3F7DE, 0xEF4E2699, 0x224239A9, 0xB4AF09C6, 0x1F90481B};
		static const bigint_t var_b = {0x484839D3, 0xCB0A6E4E, 0x0E25D8DE, 0x071C197B, 0x97FFD29C, 0xDFEF9D02, 0x83E8002C, 0x15E8D284};
		static const bigint_t var_expected = {0xFF4C0D8C, 0x9B9CF0D9, 0x5E475027, 0x6DA7DE63, 0x574E53FD, 0x42529CA7, 0x30C70999, 0x09A77597};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 369 ");
	}
	{
		static const bigint_t var_a = {0xB805DB93, 0x8E1F66AE, 0xFAAE57BB, 0xE2F1B932, 0x73C30047, 0xF730201D, 0x5EEF4385, 0x00FD68D9};
		static const bigint_t var_b = {0x5B0FFACD, 0xBEA237AC, 0x24A9C5F7, 0x9F768673, 0x4E4E9246, 0xD4CC4FA2, 0x4E0D5762, 0x2486721C};
		static const bigint_t var_expected = {0x5CF5E0D9, 0x767D2F02, 0xD60491D7, 0xA49C32BF, 0x25746E09, 0xDC981DFB, 0x50E1EC24, 0x019A5B3F};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 370 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 371 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 372 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 373 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_b = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 374 ");
	}
	{
		static const bigint_t var_a = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		static const bigint_t var_b = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 375 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_b = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		static const bigint_t var_expected = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 376 ");
	}
	/*{
		static const bigint_t var_a = {0xaccf5625, 0x631c0dad, 0x2f4b8a9e, 0x4c13a619, 0xf59be631, 0x29353d2f, 0xe643917a, 0xfe262117};
		static const bigint_t var_b = {0x10a1c1ab, 0x70d98d4a, 0xb880b410, 0x2d880c9a, 0x9385f941, 0x14fbd57f, 0xdd59aeaa, 0xf69b32cc};
		static const bigint_t var_expected = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 377 ");
	}*/
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_b = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 378 ");
	}
	{
		static const bigint_t var_a = {0xAC5354FF, 0xEA8E3766, 0x1641D347, 0xBE0FCFC1, 0x3FE94E1A, 0x79D8DD4C, 0x43F31141, 0x1618F234};
		static const bigint_t var_b = {0x7F07BA4B, 0x80C2E268, 0xC2C536BC, 0x54F2A858, 0x763071F2, 0xB099B4F8, 0xA9C708B1, 0x00601568};
		static const bigint_t var_expected = {0xF4B852FB, 0xF1BFCA25, 0x9EF39D75, 0xAFB3F099, 0xA8A803E8, 0x6E31DE55, 0x9F74CDF4, 0x0EA7CCB6};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 379 ");
	}
	{
		static const bigint_t var_a = {0x617CA929, 0x024A60D7, 0x01F66725, 0xACCD48AC, 0x26340F5F, 0xEA518C58, 0x7E8365DD, 0x200F7DE1};
		static const bigint_t var_b = {0x7153590F, 0xE57BD3F3, 0x3B9293A7, 0x08B0B0FD, 0xF778ED9F, 0xC656A5E3, 0x2037120D, 0x1DC02CF3};
		static const bigint_t var_expected = {0x05419B3C, 0x171D1DEA, 0x058265D3, 0xED8A34AE, 0xF70E664E, 0xB0DBE76E, 0x7887469D, 0x1C5747C8};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 380 ");
	}
	{
		static const bigint_t var_a = {0xDE8EA8D3, 0x99E33F0A, 0x273195DB, 0x3DF9B965, 0x4F025908, 0x43E6CA20, 0x75E10925, 0x093C6057};
		static const bigint_t var_b = {0x3C94DEA7, 0xFA2F9770, 0x91211B2B, 0xA8B0A3B4, 0x8F5B2E44, 0xDE01F62B, 0x90A2B12E, 0x0D6C999D};
		static const bigint_t var_expected = {0x77413515, 0x235222BF, 0xB75B310B, 0x155F21D8, 0xA2E10213, 0x101A915B, 0x5ED06892, 0x034F22AD};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 381 ");
	}
	{
		static const bigint_t var_a = {0xB8A4AF5D, 0x92B6D373, 0xCC921546, 0xABF09E75, 0xD0592A79, 0x1F3E5264, 0x6E824A9C, 0x01E3C183};
		static const bigint_t var_b = {0xF8EC2EC6, 0xF83E5117, 0x77440C56, 0x94FCB67E, 0x5E985C30, 0x387FEC4B, 0xEB2F2D97, 0x06C7290B};
		static const bigint_t var_expected = {0x9758D71F, 0x3CFC3907, 0xD40BC3DD, 0x6393BD74, 0xBBC5C44F, 0x9920D24B, 0x74151246, 0x1D0806F7};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 382 ");
	}
	{
		static const bigint_t var_a = {0xC6B4217C, 0xADD90733, 0x7797CFAA, 0x0DCAD064, 0xB900D6E0, 0x2095DCEB, 0x4B1639D2, 0x015DB287};
		static const bigint_t var_b = {0x2632D2BE, 0x9D04EA4A, 0xC1B7695E, 0x9A5F5010, 0xB27C0C4E, 0x97A5F258, 0x075FE1AC, 0x22F9B7D1};
		static const bigint_t var_expected = {0xC94D2E5F, 0x15DD89D0, 0xA5AF57A1, 0xF9C5DE99, 0x4810D44F, 0x497F429D, 0x43C48CF0, 0x113DAD46};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 383 ");
	}
	{
		static const bigint_t var_a = {0xE10EE727, 0x893FDA80, 0xA3600734, 0x26F7B95A, 0xAF3AF16C, 0x1CFFB00F, 0x12A4B95D, 0x1ECABA95};
		static const bigint_t var_b = {0xB7106992, 0x8519F870, 0x75C8939A, 0xA1293580, 0x56BDD307, 0x20386790, 0x1B8AC7B4, 0x1397238A};
		static const bigint_t var_expected = {0xAFB13E4F, 0xEE5FF9AD, 0xAE51A23E, 0xFE5D92FD, 0x8885C05D, 0x8B7FB935, 0x73AD9AD2, 0x21C34734};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 384 ");
	}
	{
		static const bigint_t var_a = {0x8987B32D, 0xF84B8A29, 0x38920F9E, 0x3EBA6BDC, 0x9ED1478A, 0x0173C0E2, 0xCBBB0349, 0x09860481};
		static const bigint_t var_b = {0x1F4C3886, 0xB8A51181, 0x4C3C09B4, 0x4212DF9C, 0xC2895491, 0xA6C4D1FF, 0xB058E5B1, 0x157E92F6};
		static const bigint_t var_expected = {0x281439C2, 0x2A878848, 0xCC8AA6CA, 0xE97FD741, 0x86440DCB, 0xBBBA7496, 0xB58CFE21, 0x1785FAE8};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 385 ");
	}
	{
		static const bigint_t var_a = {0x9AAD90A9, 0x016449F5, 0x79AF9970, 0xA6F010EA, 0x57CCF915, 0xBBC52262, 0x74A41AAE, 0x13E345D5};
		static const bigint_t var_b = {0xF9C05062, 0x4FE32164, 0x5B997679, 0x084E3603, 0x77492152, 0xCEBC268C, 0x569AAD30, 0x0AB499E1};
		static const bigint_t var_expected = {0x5BEE2231, 0x62691477, 0x4AFD6848, 0x653B8E06, 0xC0AD3628, 0xA8027DF8, 0x16A56DF8, 0x1AD73C3C};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 386 ");
	}
	{
		static const bigint_t var_a = {0x6D315BBA, 0xAD6851E6, 0x10648A1B, 0x8C9B77A0, 0xDBA3FC6B, 0x93528AC0, 0xBB9F1249, 0x1F689B4E};
		static const bigint_t var_b = {0x3BBC7ACB, 0x85739B65, 0x6F84636D, 0x0707124B, 0x0EAC31A8, 0x8C0A7A58, 0xCE85F0E0, 0x032FE1BC};
		static const bigint_t var_expected = {0x2AAF42AD, 0xF4D0D657, 0x87EE2842, 0x16BF8F29, 0xAA8F15FD, 0xF8FA1A6D, 0xCBFD9FA0, 0x07634A5B};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 387 ");
	}
	{
		static const bigint_t var_a = {0xE3552946, 0xBE5BE9C9, 0x0A857D4B, 0x03B60B5A, 0xCAB57CB6, 0x9E3EC052, 0xA10BDE53, 0x182F6CC8};
		static const bigint_t var_b = {0x22C88B7E, 0x66AC0084, 0x1C5D0D10, 0x1FBDE889, 0x4F7CA292, 0x349D8B3E, 0xBEB3F74D, 0x132E6D7C};
		static const bigint_t var_expected = {0xC8D03989, 0xD9D6623D, 0x599276E2, 0x9C67E0B5, 0xFF454F6E, 0xFD10E75F, 0xE67F9631, 0x0EE83373};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 388 ");
	}
	{
		static const bigint_t var_a = {0x028B96E3, 0x7D9F2D58, 0xCDBD9501, 0xBBC2C0FC, 0x92426DBD, 0x4986F3BE, 0x1387CAB3, 0x23CF9E1C};
		static const bigint_t var_b = {0x17325329, 0x5ED17608, 0xC6BB1A7E, 0xDC5CADE1, 0x631F0576, 0xBCB8DC39, 0xE1A7E4EC, 0x01729A5C};
		static const bigint_t var_expected = {0x96C46436, 0x2EDCA00E, 0x3F5B704E, 0x8F03FB2D, 0x0857B475, 0x9C5E39D5, 0x891DC47F, 0x0AE01F08};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 389 ");
	}
	{
		static const bigint_t var_a = {0xC3DD73AB, 0x30402182, 0xE5905B50, 0x32D2FEC0, 0x3CDADAC0, 0xF231B737, 0x2455ABAA, 0x01959506};
		static const bigint_t var_b = {0xACB83811, 0x702B6208, 0x0FF0EE17, 0xEC191D9B, 0x78634417, 0xF506F879, 0x52B445CB, 0x0308607B};
		static const bigint_t var_expected = {0x09C7937D, 0xA3422DC0, 0x0155AE1C, 0x48CC56E2, 0x898FCEE0, 0xA1EE7452, 0xBBF31E7A, 0x0A3BB2A3};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 390 ");
	}
	{
		static const bigint_t var_a = {0x717CA6E9, 0x15F0A034, 0xBF277C7D, 0x29CBFA56, 0x4CD1F6A3, 0x98CAC447, 0xFB07E72F, 0x02307DC8};
		static const bigint_t var_b = {0xBB5242BF, 0x77335816, 0x72BA20A5, 0x5915486C, 0x83A0436A, 0xD1127EE2, 0x44536FE2, 0x05B6BF94};
		static const bigint_t var_expected = {0x4A009B3D, 0x1E730DEE, 0xD5F4851D, 0xA7022203, 0x3CC677E7, 0xE596296F, 0x98B71AFD, 0x1F97D195};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 391 ");
	}
	{
		static const bigint_t var_a = {0x1E8E6E7B, 0x9D81D257, 0x6F015E01, 0x6E9031EB, 0xFFBD9DA1, 0x50C19EB8, 0x63D3493B, 0x16B42C8B};
		static const bigint_t var_b = {0xFD4B445F, 0xD78EFB78, 0x0FA42BD8, 0x17AA92D3, 0x96634313, 0x2344499F, 0x04DF0BDD, 0x18B4D1D5};
		static const bigint_t var_expected = {0xF80B7E92, 0x34584B72, 0x633B28E2, 0x9EA76933, 0x71C54842, 0xFF61CDC8, 0xE9FD0FEE, 0x0489D7F0};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 392 ");
	}
	{
		static const bigint_t var_a = {0xB0981770, 0x0FBB684D, 0x2767CEC0, 0xD49A17D0, 0x5547BFC5, 0xA4D2FA13, 0x29566329, 0x1202219C};
		static const bigint_t var_b = {0x11E4C636, 0x2EC0A70E, 0xFFC8D5F6, 0xAA5B28B5, 0x67E39F82, 0x5391F6CE, 0x1FA91DF5, 0x137649C5};
		static const bigint_t var_expected = {0x8C5118D9, 0xD6A13A74, 0x1D7710FB, 0xB8C55BA8, 0x64E523DC, 0xA24AE055, 0x1B8817DB, 0x10AB56CF};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 393 ");
	}
	{
		static const bigint_t var_a = {0x73E6DE3F, 0xAE2C7ED4, 0x91B1F083, 0x7EEF255A, 0xCBBF8765, 0x92AA2C88, 0x7E66FF8C, 0x102F427E};
		static const bigint_t var_b = {0x4FF4BC76, 0xE9A45D03, 0x993D1181, 0x7CD25500, 0x17C108D1, 0x5DC8B2BF, 0x97955BD7, 0x14C72BD6};
		static const bigint_t var_expected = {0x5DBA7873, 0x9F0ED601, 0x5D7EE24B, 0x732557FD, 0x19A0AD0B, 0x459CACDF, 0xE6FEF5B1, 0x09968243};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 394 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 395 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 396 ");
	}
	{
		static const bigint_t var_a = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 397 ");
	}
	{
		static const bigint_t var_a = {0xE3F5BA2F, 0x96EDCCBB, 0x5B498DA3, 0x464A32A8, 0x50CD4AB7, 0x6DA1D2E2, 0xA7AB4D37, 0x170D0930};
		static const bigint_t var_expected = {0x516A83EE, 0x508D6D50, 0xCF7AAABA, 0xBD41B81D, 0x0B273A79, 0x41AF74D8, 0x1B8016BA, 0x1228C24D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 398 ");
	}
	{
		static const bigint_t var_a = {0xE3C17BFA, 0x9AF6026B, 0x79402B5E, 0x41412CA8, 0x6FFC2B07, 0x15A457DE, 0xB6EE5127, 0x00AE0ED5};
		static const bigint_t var_expected = {0x405FAECE, 0x236C8A92, 0x34CE4D68, 0xE2A98913, 0x6278F477, 0xBCB7D700, 0xC9751820, 0x075A0E12};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 399 ");
	}
	{
		static const bigint_t var_a = {0xBB99D68E, 0xB6F07A9E, 0x11CAB5EB, 0xE3E47333, 0x5313660C, 0x6933262F, 0xC7C8E920, 0x0A2C895B};
		static const bigint_t var_expected = {0x13136957, 0x05D2D6CD, 0x3C132EEA, 0xAC8FB534, 0x18338E29, 0x50DD94EA, 0x6C4CF390, 0x199F7762};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 400 ");
	}
	{
		static const bigint_t var_a = {0x55FEBDF2, 0xC7925C79, 0xC5B1A8C7, 0xE9F1328B, 0x0EAA0684, 0x5DCC9829, 0x845EB0D8, 0x235BC3E7};
		static const bigint_t var_expected = {0x07972198, 0x8F362EE6, 0xF8C6A987, 0x9AE108F8, 0x643276AD, 0xD4641E3D, 0xCACF5D52, 0x08D84E20};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 401 ");
	}
	{
		static const bigint_t var_a = {0xDC03A6DE, 0xF3ABEECD, 0x50DFE3D2, 0x78B54DD4, 0xE17DFDDE, 0xB3EA0B18, 0xFF5EB0EB, 0x11F7E571};
		static const bigint_t var_expected = {0xF5CF697D, 0x1143618F, 0x23EBF0CC, 0x4A641DE5, 0x8C1A8F57, 0xED00A1DB, 0x38DF53F1, 0x0AF05804};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 402 ");
	}
	{
		static const bigint_t var_a = {0x1A859501, 0x6899D922, 0x9E3FCFC8, 0x070DAEE9, 0x87FC6F92, 0xD1B36ABF, 0xCFBD1364, 0x2512D73E};
		static const bigint_t var_expected = {0xE6647310, 0x20F70D97, 0x1AA5DA2B, 0x412C1F98, 0x1AA8EAA3, 0x0E1F5531, 0x42E155D6, 0x01AD8D8A};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 403 ");
	}
	{
		static const bigint_t var_a = {0x0B154D9D, 0x286EEE84, 0xE05C3B6C, 0x3CBBD07A, 0x9C9F0FCF, 0x56308678, 0x1734CD31, 0x1E533A32};
		static const bigint_t var_expected = {0x0B9441A1, 0xA0687AAB, 0x1253685D, 0x004197B1, 0x6E1FB6FB, 0x477C2509, 0x963D2B72, 0x224A9A32};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 404 ");
	}
	{
		static const bigint_t var_a = {0xCD22FE39, 0xF9B842C2, 0xADA73E82, 0x5778A38B, 0x1D8AF093, 0xE22D4945, 0x1B0EAAA2, 0x1ABBE782};
		static const bigint_t var_expected = {0x3DA173FD, 0x53351602, 0x5BC5F0D2, 0xE94BC79A, 0xCC28561E, 0xD5726B54, 0x89272809, 0x232BA8B2};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 405 ");
	}
	{
		static const bigint_t var_a = {0x8C066F06, 0xF27B7657, 0xDC0D3E60, 0x625BDB0E, 0xA4ECB59B, 0xDEF144D1, 0x5714D59E, 0x10DCF9BE};
		static const bigint_t var_expected = {0xEA5D7BA0, 0xF264AFF3, 0xF91FE09C, 0x4489B7D4, 0x4BFA11D9, 0x64A98DC4, 0x3B16E159, 0x16CBE223};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 406 ");
	}
	{
		static const bigint_t var_a = {0x8A1851B3, 0xE5BBBC26, 0x60852E18, 0x9764C077, 0xB23B5693, 0xA35CBA5D, 0xEFF0292E, 0x1EC96F09};
		static const bigint_t var_expected = {0x7DC05DC9, 0xDC3F100B, 0xB9BEE104, 0x06CCDA07, 0x0E33EC11, 0xE04E830D, 0x5B002E79, 0x21D828E0};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 407 ");
	}
	{
		static const bigint_t var_a = {0xF4020C2E, 0xB917B4DD, 0x44C05741, 0x5DB8AFD7, 0xC0770026, 0x0AA0C9EC, 0x62518DC1, 0x1A14B4FE};
		static const bigint_t var_expected = {0x84527ACC, 0xBC7C733F, 0xAF05E6DD, 0x8D140217, 0x34100E60, 0x0A59CE11, 0x94FD2DA3, 0x210DE730};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 408 ");
	}
	{
		static const bigint_t var_a = {0xFCF42304, 0x00F70969, 0xC48794DF, 0x7A8DA8BC, 0x8967A849, 0x94BD90E5, 0x2B7DA3B4, 0x0EBF52F2};
		static const bigint_t var_expected = {0xBC397A41, 0x8A76FCDA, 0x816AF011, 0xB9C4C072, 0x41C5FE46, 0xF5159EB4, 0xA15B607B, 0x213023A4};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 409 ");
	}
	{
		static const bigint_t var_a = {0x1E9751F5, 0xFEE62762, 0xD242B531, 0xE7FD28F6, 0xBFE66763, 0x398DDBAE, 0xD3F461AA, 0x09ADCD65};
		static const bigint_t var_expected = {0xA82C56CF, 0x555A41A1, 0x6DF19490, 0x3DE49D1B, 0x550B85F8, 0x6DD88B9B, 0xE4BE6012, 0x18FFBC3F};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 410 ");
	}
	{
		static const bigint_t var_a = {0xB752EBB4, 0xAC197B4C, 0x59107F7D, 0x8F52C5B3, 0x4E52346E, 0xEFA91EBF, 0x345BA21C, 0x0A2CDF35};
		static const bigint_t var_expected = {0x96EC09F9, 0x4AAEB041, 0x7480E102, 0xE4325960, 0x9247D8F0, 0xF60B2182, 0x2B09D689, 0x06953867};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 411 ");
	}
	{
		static const bigint_t var_a = {0xB4B5B8CE, 0x779A3F0C, 0x744A620C, 0x3E6E4C4C, 0xD9E5E511, 0x50BEA41C, 0xD09675DF, 0x17111D54};
		static const bigint_t var_expected = {0x571D645F, 0x944A8468, 0x000EBCB2, 0xAD4DFF11, 0xD5DF2B1E, 0xB829BDEB, 0x1B3A4730, 0x1AE2B69E};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 412 ");
	}
	{
		static const bigint_t var_a = {0xF1098AAB, 0xFE216648, 0x4E8912FA, 0x508BDE38, 0xFFD88B1E, 0x57E60123, 0xC6089340, 0x02D0E317};
		static const bigint_t var_expected = {0x51CDB196, 0xDC7D0B04, 0x3EA7FCC5, 0xD99092DD, 0xB75B6EA0, 0x787337A0, 0x83EE1A60, 0x11C1249D};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 413 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x0000000A, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 414 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 415 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000009, 0xD3800000, 0x00000009, 0x30908000, 0x00000004, 0xDD1A26C0, 0x20000000, 0x1291B241};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 416 ");
	}
	{
		static const bigint_t var_a = {0xECF4449D, 0x14665B23, 0x0522F7F4, 0xA8FFDA3F, 0x139F3F37, 0x95217F5E, 0x243B389B, 0x0DF3B3B9};
		static const bigint_t var_expected = {0xF67A2258, 0xDDB32D91, 0x82917C03, 0x05106D1F, 0x09CF9FA0, 0xA7AAE66F, 0xB21D9C4E, 0x198B8C1D};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 417 ");
	}
	{
		static const bigint_t var_a = {0xDEE2775C, 0x19F009D3, 0x11DB7366, 0x808DEF43, 0xE7311DE3, 0x52C8C02E, 0x4333CA05, 0x18F9FEA2};
		static const bigint_t var_expected = {0xEF713BAE, 0x0CF804E9, 0x88EDB9B3, 0xC046F7A1, 0x73988EF1, 0xA9646017, 0x2199E502, 0x0C7CFF51};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 418 ");
	}
	{
		static const bigint_t var_a = {0x14F60648, 0xB16C9BE5, 0x09B4F3F9, 0xDDCBAD5B, 0x7DD79E38, 0xE39CC1EC, 0x46E52A13, 0x0D2483B5};
		static const bigint_t var_expected = {0x8A7B0324, 0xD8B64DF2, 0x84DA79FC, 0x6EE5D6AD, 0x3EEBCF1C, 0xF1CE60F6, 0xA3729509, 0x069241DA};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 419 ");
	}
	{
		static const bigint_t var_a = {0x6167C211, 0xC0DB1DB3, 0x6D2E0B38, 0x3BB52ADE, 0xAEF84A31, 0x8F5A0510, 0x8866B9CB, 0x21FA1829};
		static const bigint_t var_expected = {0xB0B3E112, 0x33ED8ED9, 0x369705A6, 0xCE6B156F, 0x577C251C, 0xA4C72948, 0xE4335CE6, 0x238EBE55};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 420 ");
	}
	{
		static const bigint_t var_a = {0x6D1AC2E8, 0x325E14CB, 0x763D09AB, 0x4CF6F9C6, 0xE763CC79, 0xD3AB7AD8, 0x9348F1B4, 0x0F23A509};
		static const bigint_t var_expected = {0xB68D6174, 0x992F0A65, 0x3B1E84D5, 0xA67B7CE3, 0x73B1E63C, 0x69D5BD6C, 0xC9A478DA, 0x0791D284};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 421 ");
	}
	{
		static const bigint_t var_a = {0x34A43DB9, 0xD54AB45B, 0x8E48D3DB, 0x65434F3F, 0xABEB74D5, 0x6F54FE28, 0xAA774894, 0x19CDF811};
		static const bigint_t var_expected = {0x9A521EE6, 0xBE255A2D, 0xC72469F7, 0xE332279F, 0x55F5BA6E, 0x14C4A5D4, 0xF53BA44B, 0x1F78AE49};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 422 ");
	}
	{
		static const bigint_t var_a = {0x85A13F77, 0xE0C68350, 0xD3FDDEBE, 0xD18EAF12, 0x0E55AB6A, 0xB321A5EE, 0x81E4FD4B, 0x20FF4818};
		static const bigint_t var_expected = {0x42D09FC5, 0x43E341A8, 0x69FEEF69, 0x9957D789, 0x072AD5B9, 0xB6AAF9B7, 0x60F27EA6, 0x2311564D};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 423 ");
	}
	{
		static const bigint_t var_a = {0x845D512F, 0x86FCFB7C, 0x99F44908, 0xF0336736, 0x3B9696D0, 0x8D2EE014, 0xBFFB22DE, 0x05395F2A};
		static const bigint_t var_expected = {0x422EA8A1, 0x16FE7DBE, 0x4CFA248E, 0xA8AA339B, 0x1DCB4B6C, 0x23B196CA, 0x7FFD9170, 0x152E61D6};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 424 ");
	}
	{
		static const bigint_t var_a = {0x28C8358E, 0x37D9105A, 0xE51F3290, 0xA7987263, 0xF064A8C8, 0x39F9CE62, 0x83F26913, 0x013AE87D};
		static const bigint_t var_expected = {0x14641AC7, 0x1BEC882D, 0xF28F9948, 0x53CC3931, 0x78325464, 0x9CFCE731, 0xC1F93489, 0x009D743E};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 425 ");
	}
	{
		static const bigint_t var_a = {0xBEBC423F, 0xE15EC017, 0xF210BA11, 0x49569762, 0xFD14CC81, 0x64F04008, 0xDCE28242, 0x1514A067};
		static const bigint_t var_expected = {0xDF5E2129, 0xC42F600B, 0x79085D12, 0xD53BCBB1, 0x7E8A6644, 0x0F9246C4, 0x0E714122, 0x1D1C0275};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 426 ");
	}
	{
		static const bigint_t var_a = {0x64980B85, 0xC8830B06, 0xB0096308, 0x20CBD212, 0xC9C67611, 0x6281B5CB, 0x90B21164, 0x146DED43};
		static const bigint_t var_expected = {0x324C05CC, 0x37C18583, 0x5804B18E, 0xC0F66909, 0xE4E33B0C, 0x0E5B01A5, 0xE85908B3, 0x1CC8A8E2};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 427 ");
	}
	{
		static const bigint_t var_a = {0x8F2058D0, 0xC2A3FAA2, 0x40DFA61A, 0x565E5C62, 0xCDE5CF8D, 0x55C5B875, 0x96CF86EC, 0x10B1BC2B};
		static const bigint_t var_expected = {0x47902C68, 0x6151FD51, 0x206FD30D, 0xAB2F2E31, 0xE6F2E7C6, 0x2AE2DC3A, 0xCB67C376, 0x0858DE15};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 428 ");
	}
	{
		static const bigint_t var_a = {0x85B9A18B, 0xF37E8FED, 0x79ACFB4D, 0x7775DB6A, 0x16F7A067, 0x7D1E5937, 0x9CBB640F, 0x0455D91F};
		static const bigint_t var_expected = {0xC2DCD0CF, 0xCD3F47F6, 0x3CD67DB0, 0xEC4B6DB5, 0x8B7BD037, 0x9BA9535B, 0xEE5DB208, 0x14BC9ED0};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 429 ");
	}
	{
		static const bigint_t var_a = {0xE4EC9042, 0x89CDC6F7, 0x6654AB33, 0xDA129EA1, 0xC7B7DF57, 0x5BC3EF16, 0xC162BC36, 0x0CBB2E43};
		static const bigint_t var_expected = {0xF2764821, 0xC4E6E37B, 0xB32A5599, 0xED094F50, 0x63DBEFAB, 0x2DE1F78B, 0xE0B15E1B, 0x065D9721};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 430 ");
	}
	{
		static const bigint_t var_a = {0x194035E5, 0x385D0B14, 0xC6D42822, 0x8C50DF94, 0x958BED38, 0xA7C2C886, 0x1C4BEA77, 0x06AE34CD};
		static const bigint_t var_expected = {0x0CA01AFC, 0xEFAE858A, 0x636A141A, 0x76B8EFCA, 0x4AC5F6A0, 0xB0FB8B03, 0xAE25F53C, 0x15E8CCA7};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 431 ");
	}
	{
		static const bigint_t var_a = {0xEA5AF12B, 0x66C3BC64, 0x8B68CCE4, 0xC63178FF, 0x493BE67F, 0x11F635BB, 0x738BDEC1, 0x10A5AC0B};
		static const bigint_t var_expected = {0x752D789F, 0x06E1DE32, 0xC5B4667C, 0x13A93C7F, 0xA49DF344, 0x6615419D, 0xD9C5EF61, 0x1AE48846};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 432 ");
	}
	{
		static const bigint_t var_a = {0xF43A78E6, 0x5E61387E, 0xA3BEF259, 0xD092DD3E, 0x52467B8F, 0xB5A62AEF, 0x4D7B1BA6, 0x23B82F9B};
		static const bigint_t var_exp = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xF43A78E6, 0x5E61387E, 0xA3BEF259, 0xD092DD3E, 0x52467B8F, 0xB5A62AEF, 0x4D7B1BA6, 0x23B82F9B};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 433 ");
	}
	{
		static const bigint_t var_a = {0xF43A78E6, 0x5E61387E, 0xA3BEF259, 0xD092DD3E, 0x52467B8F, 0xB5A62AEF, 0x4D7B1BA6, 0x23B82F9B};
		static const bigint_t var_exp = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 434 ");
	}
	{
		static const bigint_t var_a = {0x54AAAA93, 0x3EA0F58D, 0x17307AFB, 0x60A31579, 0xFA33BC40, 0x09CE737E, 0x2A6BB290, 0x19190657};
		static const bigint_t var_exp = {0x0DD2ED82, 0x2EB1A9EC, 0x3E10A691, 0xFF5E2268, 0x5A965DA2, 0x389088E5, 0x8C1C2665, 0xAE4C3BEB};
		static const bigint_t var_expected = {0xCCE0F3C4, 0xB0DF7F83, 0x3021606A, 0x3EF145FF, 0x30C8953C, 0x73BFB1AC, 0x3FF587A1, 0x14DA4ECE};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 435 ");
	}
	{
		static const bigint_t var_a = {0x448C4067, 0x456924CD, 0x08FC48E6, 0x62992C45, 0x16965CB2, 0x48E914BC, 0xB0B6451B, 0x213F4FD3};
		static const bigint_t var_exp = {0xC778638D, 0x561F7F89, 0xB4D4198E, 0xB1654DA7, 0x5B065EB0, 0x31ABF6A2, 0xE7EEDFDE, 0xD4AE06FC};
		static const bigint_t var_expected = {0x417AEC93, 0x35B85839, 0x42031735, 0x62E07CCB, 0x195494E1, 0x290B1182, 0x16DEFEF7, 0x1FFBF165};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 436 ");
	}
	{
		static const bigint_t var_a = {0x5C050981, 0x42C4C9C1, 0xD21B828C, 0x10BE99A8, 0x567116DF, 0x40BDED60, 0x829D4B11, 0x22714670};
		static const bigint_t var_exp = {0xA75BC736, 0xB281FC71, 0x402108A0, 0x41D7BE38, 0x016ED024, 0x9F5BB2E5, 0x8A09C8B5, 0x532D2FBB};
		static const bigint_t var_expected = {0x2DDBC6B0, 0x53140DCD, 0x6D945867, 0x4CF42FC9, 0x4CE5C5E3, 0x4AA8D6FE, 0xDD072EF4, 0x192C7BD4};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 437 ");
	}
	{
		static const bigint_t var_a = {0x0A787C9B, 0x7A93DEC8, 0xEA1F018B, 0x277FA7FB, 0xB94D75B0, 0x5A07E457, 0xE4576356, 0x193EA57D};
		static const bigint_t var_exp = {0x7BE11BF8, 0x239E44F5, 0xA9BA4379, 0x66F46FF8, 0x49118C5E, 0x543B54EB, 0xEA9E38CE, 0x545FD08B};
		static const bigint_t var_expected = {0x0BEFBDA8, 0x2A5529F7, 0xE8A144ED, 0xAF52D67D, 0x919D8843, 0xB52B72FB, 0x90F9291B, 0x024201FB};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 438 ");
	}
	{
		static const bigint_t var_a = {0xAA35755B, 0xBC994562, 0xFC552963, 0x1BE5BDED, 0xBB9B40A0, 0xCDAFB156, 0xFCEB9704, 0x1BE5E47D};
		static const bigint_t var_exp = {0x4FBEAE04, 0xCB74AB7A, 0xF4201EEF, 0x199EFF66, 0x712D65CF, 0x62FA829B, 0xBC688194, 0x3FF8ADAD};
		static const bigint_t var_expected = {0x8B5BF636, 0x662C2185, 0x0E3E85F8, 0x118A4A4E, 0x45016079, 0x17F1CFEB, 0xB2D989CE, 0x12123D8F};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 439 ");
	}
	{
		static const bigint_t var_a = {0x8C6A9FC3, 0xC17C5C19, 0xCE7F2252, 0x6E20E5D7, 0x81940B5E, 0xB5D6F5E6, 0xFE60598C, 0x01FD664C};
		static const bigint_t var_exp = {0x72C38674, 0x0A507955, 0x65DF8CB0, 0x95E55ABB, 0xF4C85DA6, 0x186FA53C, 0xF6F7572E, 0xBE577384};
		static const bigint_t var_expected = {0xAEC8D566, 0xE71DB535, 0xE8755A4F, 0x497AD4DE, 0xFC66617D, 0x0F934EBB, 0x09718D63, 0x0AD82C53};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 440 ");
	}
	{
		static const bigint_t var_a = {0xABBABA8F, 0x1349111A, 0x7A6BE473, 0x9EC0E0A8, 0xF7B944BF, 0x4799F09E, 0x6F7DE6FC, 0x19A81C6A};
		static const bigint_t var_exp = {0x6EAFE525, 0x81D4914F, 0x82DC4210, 0x519CA9EF, 0x9283AAA7, 0x09A638F9, 0xCB04FC28, 0xBA19F76D};
		static const bigint_t var_expected = {0xDB949DC5, 0x7F698CA3, 0x3FEF5AD3, 0x11C531B0, 0x7A5D9098, 0x73AFBD85, 0x9DB82DE6, 0x10CE9427};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 441 ");
	}
	{
		static const bigint_t var_a = {0x37DD74C4, 0x5725F075, 0x8F1E1076, 0x3FC5758A, 0xC62E08E2, 0x51F4748C, 0xE7CDE8E9, 0x0E6A5ECF};
		static const bigint_t var_exp = {0x12FEDD42, 0x1211FF6B, 0x0FAABDC7, 0x07E47E22, 0x45668B4F, 0x05F2C9A6, 0xB2BE0F39, 0x5AA682F0};
		static const bigint_t var_expected = {0xDDE13BA3, 0xA0F36F6A, 0x5520BD91, 0x482FD1F7, 0xCCAF24B8, 0x585B3AD8, 0xBEF0C69B, 0x1142B991};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 442 ");
	}
	{
		static const bigint_t var_a = {0x1EA282B6, 0x950F9BBB, 0x2CD4E5AB, 0x50FEAF7C, 0xA32B1C86, 0x308140C7, 0xC7103328, 0x195094AD};
		static const bigint_t var_exp = {0x6BB8FC97, 0xDD8E60A2, 0x11D546D8, 0xB0BE4DE5, 0x4CB3F89C, 0x1DFC947F, 0x5F1C24E1, 0x0AC21D4A};
		static const bigint_t var_expected = {0xCA8F8E15, 0xC3C6123A, 0xD15DBA8D, 0x1FEE1F69, 0x861519A8, 0x3EF54339, 0x9E96D8D0, 0x1B63DE8D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 443 ");
	}
	{
		static const bigint_t var_a = {0x667D2D34, 0x15CB2F7F, 0x0DCCA145, 0xC7777001, 0xA6EB14F7, 0xC346D53A, 0x75962402, 0x1267BA85};
		static const bigint_t var_exp = {0xC5440729, 0x44613E94, 0xCE35E9EE, 0x859E2151, 0x23B62321, 0xA2D3C5BF, 0xC82BF913, 0x711DDEA9};
		static const bigint_t var_expected = {0xDD670800, 0x64854905, 0x51B00124, 0x1FEA4C12, 0x1B3B74C0, 0xA66FE570, 0x69A53C04, 0x0971D323};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 444 ");
	}
	{
		static const bigint_t var_a = {0x793A95BF, 0x4CB5889E, 0xA80F9798, 0x7E58A123, 0xFCB8E9E2, 0xE7C96E7D, 0x7F696B97, 0x1B679E7D};
		static const bigint_t var_exp = {0xAE36CDB0, 0xE735407D, 0xCA3F5AF0, 0xFEF59AFA, 0x8893CB30, 0x26FE5E57, 0x20627227, 0x78E53A9C};
		static const bigint_t var_expected = {0x95818E3A, 0xE87AB499, 0x4642E507, 0x539E6B5F, 0xF0CB013E, 0x30DBD6D9, 0x0A37D753, 0x2424F314};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 445 ");
	}
	{
		static const bigint_t var_a = {0x0A8BD430, 0x5852B874, 0x7A4C69E6, 0x551E0558, 0x441C60BC, 0x4A2D1A2D, 0x0F4244A8, 0x093E1682};
		static const bigint_t var_exp = {0xF31E0EF9, 0xA86448DF, 0xCB51D791, 0xD5C72F1E, 0x77196654, 0x7887C321, 0xDEEB3EAD, 0x49536473};
		static const bigint_t var_expected = {0x789A1DF8, 0x34527D1E, 0x2D8CEEE0, 0x1094648E, 0x33F27EA0, 0x9026E1DC, 0x2C73A6EF, 0x12DE0CCA};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 446 ");
	}
	{
		static const bigint_t var_a = {0xB86C6CB1, 0xA6C26DCB, 0xE85D7AE9, 0x7174F865, 0xE851A501, 0x1611169E, 0xCB977263, 0x2254A8E6};
		static const bigint_t var_exp = {0xA05B7337, 0xA6FF72AB, 0xD505F723, 0x0337B09D, 0x2D8F1C54, 0xAB11E553, 0xB6FC3506, 0x4C3C9FB4};
		static const bigint_t var_expected = {0xB6D8AF4C, 0x131F7BC2, 0x7E6B21C9, 0xC886CD47, 0x1A5DAB5D, 0x1D0235CF, 0xD9A5FD67, 0x20534F34};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 447 ");
	}
	{
		static const bigint_t var_a = {0xF5BE00B9, 0x75A07A6D, 0x7DCBDD62, 0x541FF78D, 0x8B57E732, 0x89F9C182, 0xE616786D, 0x1A33E3A4};
		static const bigint_t var_exp = {0x03E89DDC, 0x45E3F8E8, 0x2E816EF4, 0xC1160FA8, 0x28859C7C, 0x0FE51512, 0x9D1F67C5, 0x2BA2A4D3};
		static const bigint_t var_expected = {0xC12EF050, 0x4622CBEE, 0x328BF7F4, 0xEABD6411, 0x4932823B, 0x9D882B58, 0xBE66B91C, 0x1F7259A2};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 448 ");
	}
	{
		static const bigint_t var_a = {0x8ED3D85E, 0x8369A2E7, 0x62A6403C, 0xAA7B4B41, 0xDF347F84, 0x8BF46299, 0x64A5BE7F, 0x1B5C74B4};
		static const bigint_t var_exp = {0xA82C4882, 0x23C6F61A, 0x5AC4CAEB, 0x877A6E24, 0x24A5BCF9, 0x35007F5E, 0xC886DE37, 0xCE4205C5};
		static const bigint_t var_expected = {0x51E7651A, 0x3249444F, 0xB9B1B6BF, 0x2A27A1A1, 0x72AFA686, 0x1B742B30, 0x3E4A028A, 0x08BD8EF7};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 449 ");
	}
	{
		static const bigint_t var_a = {0xB1BCCD32, 0xADA602D4, 0xC56DAF2B, 0x60BFB664, 0x16DF4A1E, 0x0922BF17, 0x3563421A, 0x17E3E4FB};
		static const bigint_t var_exp = {0x5DCF7BE5, 0x234918E6, 0x1FFB1D4C, 0x10467039, 0x1E82F563, 0xEE273AD1, 0xAD5B1DA6, 0x5F289130};
		static const bigint_t var_expected = {0xF4BBE24D, 0x30449CB2, 0xF9110DB7, 0x84FDA160, 0x98A6F976, 0xCEFD422E, 0x0F716BAA, 0x06737E71};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 450 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 451 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 452 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 453 ");
	}
	{
		static const bigint_t var_a = {0xBD33557D, 0xFF04BBE8, 0x0B9B0B6B, 0x25846017, 0x61D9B7E4, 0xFA108211, 0xC57E04CF, 0x07BFE2D2};
		static const bigint_t var_expected = {0x42CCAA96, 0xA7FB4417, 0xF464F4A7, 0x3B9C9FE8, 0x9E264824, 0xC023CB6E, 0x7A81FB31, 0x1D6381AF};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 454 ");
	}
	{
		static const bigint_t var_a = {0x2E83DB06, 0xBF0727B7, 0x81CCA0A1, 0xF29CCA89, 0x5368AED4, 0x91C2C24B, 0xC00F4622, 0x22165EC9};
		static const bigint_t var_expected = {0xD17C250D, 0xE7F8D848, 0x7E335F71, 0x6E843576, 0xAC975133, 0x28718B34, 0x7FF0B9DF, 0x030D05B8};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 455 ");
	}
	{
		static const bigint_t var_a = {0x45A297EA, 0xFC53AA7C, 0xC266233A, 0xD503EAC1, 0x8F07FD04, 0xE9EFDD62, 0x769BD09B, 0x1163ECFC};
		static const bigint_t var_expected = {0xBA5D6829, 0xAAAC5583, 0x3D99DCD8, 0x8C1D153E, 0x70F80303, 0xD044701D, 0xC9642F65, 0x13BF7785};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 456 ");
	}
	{
		static const bigint_t var_a = {0x69D80050, 0xA4A67D6B, 0xC5AA47C2, 0x27F321FF, 0x412D5E55, 0xE3BB8B93, 0x76A8FC03, 0x09A4CC2A};
		static const bigint_t var_expected = {0x9627FFC3, 0x02598294, 0x3A55B851, 0x392DDE00, 0xBED2A1B3, 0xD678C1EC, 0xC95703FD, 0x1B7E9857};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 457 ");
	}
	{
		static const bigint_t var_a = {0x56D6C44B, 0x24861C14, 0xB645A82C, 0xAE1BFB85, 0xAC8B398C, 0xCE8DECD2, 0x3E8CA1E8, 0x060CCFCD};
		static const bigint_t var_expected = {0xA9293BC8, 0x8279E3EB, 0x49BA57E7, 0xB305047A, 0x5374C67B, 0xEBA660AD, 0x01735E18, 0x1F1694B5};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 458 ");
	}
	{
		static const bigint_t var_a = {0x9B0CEDEE, 0x8CE55E3C, 0x71234BF3, 0xE63A203C, 0xA4FF7ECE, 0x194EB715, 0x8418FB40, 0x1E4FA277};
		static const bigint_t var_expected = {0x64F31225, 0x1A1AA1C3, 0x8EDCB420, 0x7AE6DFC3, 0x5B008139, 0xA0E5966A, 0xBBE704C1, 0x06D3C20A};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 459 ");
	}
	{
		static const bigint_t var_a = {0x1C52BF30, 0xE150F636, 0x0B112444, 0xAA586BDC, 0x15CFA615, 0x1495353B, 0x3012AAA9, 0x14C02AF0};
		static const bigint_t var_expected = {0xE3AD40E3, 0xC5AF09C9, 0xF4EEDBCE, 0xB6C89423, 0xEA3059F2, 0xA59F1844, 0x0FED5558, 0x10633992};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 460 ");
	}
	{
		static const bigint_t var_a = {0x90DA931D, 0x82AE306E, 0x4A2FAA09, 0x109FDE0E, 0x7A375C62, 0x023A49A4, 0x1F835991, 0x24765AB7};
		static const bigint_t var_expected = {0x6F256CF6, 0x2451CF91, 0xB5D0560A, 0x508121F1, 0x85C8A3A6, 0xB7FA03DB, 0x207CA670, 0x00AD09CB};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 461 ");
	}
	{
		static const bigint_t var_a = {0x037D3643, 0xCF95228F, 0x28350D3E, 0x248116D0, 0x664CCF76, 0x95DE26C4, 0x62CDD285, 0x1CC5DF5D};
		static const bigint_t var_expected = {0xFC82C9D0, 0xD76ADD70, 0xD7CAF2D4, 0x3C9FE92F, 0x99B33092, 0x245626BB, 0xDD322D7C, 0x085D8524};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 462 ");
	}
	{
		static const bigint_t var_a = {0x564A6BAE, 0xB4269B84, 0x54829196, 0x7D26817C, 0xFF25A555, 0x83751B08, 0x3D988A98, 0x15A871D1};
		static const bigint_t var_expected = {0xA9B59465, 0xF2D9647B, 0xAB7D6E7C, 0xE3FA7E83, 0x00DA5AB2, 0x36BF3277, 0x02677569, 0x0F7AF2B1};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 463 ");
	}
	{
		static const bigint_t var_a = {0xBA73A595, 0x017E833B, 0xB0011274, 0x0CD58083, 0x7E5FF56D, 0x80D0AC9B, 0x688CF003, 0x0BB05CD0};
		static const bigint_t var_expected = {0x458C5A7E, 0xA5817CC4, 0x4FFEED9F, 0x544B7F7C, 0x81A00A9B, 0x3963A0E4, 0xD7730FFE, 0x197307B1};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 464 ");
	}
	{
		static const bigint_t var_a = {0x39812332, 0x55BA8BFC, 0xD4DBC9AE, 0x38F9253F, 0xB0E5E771, 0xEB7998B0, 0x11DC0BC7, 0x0000421C};
		static const bigint_t var_expected = {0xC67EDCE1, 0x51457403, 0x2B243665, 0x2827DAC0, 0x4F1A1897, 0xCEBAB4CF, 0x2E23F439, 0x25232266};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 465 ");
	}
	{
		static const bigint_t var_a = {0x2DD8EAF7, 0xEF844701, 0x8AF9D791, 0xDC5B46AD, 0x7815CEC2, 0x785A14BA, 0x989E2E32, 0x1AFAE2EA};
		static const bigint_t var_expected = {0xD227151C, 0xB77BB8FE, 0x75062881, 0x84C5B952, 0x87EA3145, 0x41DA38C5, 0xA761D1CF, 0x0A288197};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 466 ");
	}
	{
		static const bigint_t var_a = {0xC79163CB, 0x77341CCD, 0x50561144, 0xCE7C0BCF, 0x4B2AD13E, 0x6F7EF3CC, 0xD2FBC932, 0x1F9840AE};
		static const bigint_t var_expected = {0x386E9C48, 0x2FCBE332, 0xAFA9EECF, 0x92A4F430, 0xB4D52EC9, 0x4AB559B3, 0x6D0436CF, 0x058B23D3};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 467 ");
	}
	{
		static const bigint_t var_a = {0x89A1799B, 0x2C82A2BC, 0xD9222F1E, 0xBCCB4344, 0xB2FC8FB3, 0xE500D86C, 0xC721AD4B, 0x11E3F092};
		static const bigint_t var_expected = {0x765E8678, 0x7A7D5D43, 0x26DDD0F5, 0xA455BCBB, 0x4D037054, 0xD5337513, 0x78DE52B5, 0x133F73EF};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 468 ");
	}
	{
		static const bigint_t var_a = {0xCC4BA0DB, 0xCDC55D30, 0x8CB75F03, 0xC9EA0750, 0xCB104679, 0xDF7A0237, 0x34183940, 0x05945867};
		static const bigint_t var_expected = {0x33B45F38, 0xD93AA2CF, 0x7348A10F, 0x9736F8AF, 0x34EFB98E, 0xDABA4B48, 0x0BE7C6C0, 0x1F8F0C1B};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 469 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 470 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 471 ");
	}
	{
		static const bigint_t var_a = {0x00000012, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x00000011, 0xA7000000, 0x00000013, 0x61210000, 0x00000008, 0xBA344D80, 0x40000001, 0x25236482};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 472 ");
	}
	{
		static const bigint_t var_a = {0x3BEC0ECD, 0xF1C6EAB1, 0x0357B982, 0xD47A8ED4, 0xC9F45576, 0xD1951CC5, 0x4A525388, 0x0AFE0DED};
		static const bigint_t var_expected = {0x77D81D9A, 0xE38DD562, 0x06AF7305, 0xA8F51DA8, 0x93E8AAED, 0xA32A398B, 0x94A4A711, 0x15FC1BDA};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 473 ");
	}
	{
		static const bigint_t var_a = {0x560C0625, 0x791C0875, 0x8EC031A0, 0x23CA38FC, 0x70EF4FFE, 0x4DFA9D60, 0xED1E211D, 0x1AFD5A9E};
		static const bigint_t var_expected = {0xAC180C37, 0x4B3810EA, 0x1D80632D, 0xE67371F9, 0xE1DE9FF3, 0xE1C0ED40, 0x9A3C4238, 0x10D750BB};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 474 ");
	}
	{
		static const bigint_t var_a = {0xF1C90EE1, 0x74211AA0, 0xAE92051E, 0x5FB62736, 0x99FED58A, 0x9B71EAC0, 0x35DDD556, 0x0101E016};
		static const bigint_t var_expected = {0xE3921DC2, 0xE8423541, 0x5D240A3C, 0xBF6C4E6D, 0x33FDAB14, 0x36E3D581, 0x6BBBAAAD, 0x0203C02C};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 475 ");
	}
	{
		static const bigint_t var_a = {0xB28D76DC, 0x6C700CDA, 0x9A7DB9C4, 0xBFF9FAE4, 0xB425E26F, 0x2161EE2C, 0xB00F1E3E, 0x0CC1FEC7};
		static const bigint_t var_expected = {0x651AEDB8, 0xD8E019B5, 0x34FB7388, 0x7FF3F5C9, 0x684BC4DF, 0x42C3DC59, 0x601E3C7C, 0x1983FD8F};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 476 ");
	}
	{
		static const bigint_t var_a = {0x96116C21, 0x15F6B2B5, 0xBD451F9D, 0x21CD769E, 0x410C6C7D, 0x4019382B, 0x5E2EF1BC, 0x09AE6AD8};
		static const bigint_t var_expected = {0x2C22D842, 0x2BED656B, 0x7A8A3F3A, 0x439AED3D, 0x8218D8FA, 0x80327056, 0xBC5DE378, 0x135CD5B0};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 477 ");
	}
	{
		static const bigint_t var_a = {0x6CB799D4, 0x73920CB5, 0x359607C7, 0x85E12D23, 0x56EC6416, 0x32A2B5FB, 0xB455D45B, 0x05A64397};
		static const bigint_t var_expected = {0xD96F33A8, 0xE724196A, 0x6B2C0F8E, 0x0BC25A46, 0xADD8C82D, 0x65456BF6, 0x68ABA8B6, 0x0B4C872F};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 478 ");
	}
	{
		static const bigint_t var_a = {0x582F1B74, 0x5D4809C9, 0x56A3918F, 0xAAA38945, 0x1CD17831, 0x9F94CEA0, 0x9ABFD728, 0x052D7863};
		static const bigint_t var_expected = {0xB05E36E8, 0xBA901392, 0xAD47231E, 0x5547128A, 0x39A2F063, 0x3F299D40, 0x357FAE51, 0x0A5AF0C7};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 479 ");
	}
	{
		static const bigint_t var_a = {0x526E0808, 0x7CFEB564, 0x259D2DA1, 0xC89DABCF, 0x52252849, 0xDBC585BD, 0x6D0FD920, 0x15EF07E9};
		static const bigint_t var_expected = {0xA4DC0FFD, 0x52FD6AC8, 0x4B3A5B2F, 0x301A579E, 0xA44A508B, 0xFD56BDFA, 0x9A1FB23F, 0x06BAAB50};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 480 ");
	}
	{
		static const bigint_t var_a = {0xA5F42A95, 0xA6CFEF74, 0xDEF1DE12, 0x735D1618, 0xC9911445, 0xEF688A2D, 0xBE6BD44F, 0x16F40279};
		static const bigint_t var_expected = {0x4BE85517, 0xA69FDEE9, 0xBDE3BC11, 0x85992C31, 0x93222882, 0x249CC6DB, 0x3CD7A89E, 0x08C4A071};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 481 ");
	}
	{
		static const bigint_t var_a = {0x70647CFD, 0xE9EA00D0, 0x6F604524, 0xAA82135D, 0xE62B9B5B, 0x18A3FED7, 0x10664E1D, 0x08372EA2};
		static const bigint_t var_expected = {0xE0C8F9FA, 0xD3D401A0, 0xDEC08A49, 0x550426BA, 0xCC5736B7, 0x3147FDAF, 0x20CC9C3A, 0x106E5D44};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 482 ");
	}
	{
		static const bigint_t var_a = {0x286868A5, 0x1005C9FA, 0xFADA6B34, 0xFE51422F, 0x23F41556, 0xEE426368, 0x5EBB2014, 0x15BFDE9D};
		static const bigint_t var_expected = {0x50D0D137, 0x790B93F4, 0xF5B4D654, 0x9B81845F, 0x47E82AA5, 0x22507950, 0x7D764028, 0x065C58B8};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 483 ");
	}
	{
		static const bigint_t var_a = {0x14E92714, 0xB7585373, 0x5739800C, 0xEA6BCF2B, 0x8DA45ECA, 0x22380B3B, 0x93D833B1, 0x1D51C8A2};
		static const bigint_t var_expected = {0x29D24E15, 0xC7B0A6E6, 0xAE730005, 0x73B69E56, 0x1B48BD8D, 0x8A3BC8F7, 0xE7B06760, 0x15802CC2};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 484 ");
	}
	{
		static const bigint_t var_a = {0xD0958D23, 0x4734FC0A, 0x8FBBDE05, 0x15972D07, 0x47CF6C02, 0x50B34C96, 0x0F37EF0E, 0x0FD98F0D};
		static const bigint_t var_expected = {0xA12B1A46, 0x8E69F815, 0x1F77BC0A, 0x2B2E5A0F, 0x8F9ED804, 0xA166992C, 0x1E6FDE1C, 0x1FB31E1A};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 485 ");
	}
	{
		static const bigint_t var_a = {0xCBB812CF, 0x7220883C, 0x625C1B80, 0x47B66271, 0x064D29B6, 0xE6A08AE5, 0xA98B6AE4, 0x1B15E360};
		static const bigint_t var_expected = {0x9770258B, 0x3D411079, 0xC4B836ED, 0x2E4BC4E2, 0x0C9A5364, 0x130CC84A, 0x1316D5C8, 0x1108623F};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 486 ");
	}
	{
		static const bigint_t var_a = {0xC85E16ED, 0x308ACED4, 0xC2F3F246, 0xA4AC3CAD, 0x94FBD0AE, 0xF5DCDB24, 0x28B8A977, 0x12264335};
		static const bigint_t var_expected = {0x90BC2DDA, 0x61159DA9, 0x85E7E48C, 0x4958795B, 0x29F7A15D, 0xEBB9B649, 0x517152EF, 0x244C866A};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 487 ");
	}
	{
		static const bigint_t var_a = {0x61CD9048, 0xC209DAB6, 0x56294E43, 0x70C2F8CB, 0x4ECC807D, 0x65E3CE39, 0xC99E6D54, 0x02B4E2BC};
		static const bigint_t var_expected = {0xC39B2090, 0x8413B56C, 0xAC529C87, 0xE185F196, 0x9D9900FA, 0xCBC79C72, 0x933CDAA8, 0x0569C579};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 488 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		static const bigint_t var_expected = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 489 ");
	}
	{
		static const bigint_t var_a = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		static const bigint_t var_expected = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 490 ");
	}
	{
		static const bigint_t var_a = {0x63A920E9, 0x8CE8B5FD, 0xD2168A25, 0x71593859, 0x6014F682, 0xAA43D5A7, 0x6097047B, 0x08868049};
		static const bigint_t var_expected = {0x40653A84, 0x9358E2E7, 0xE34A592E, 0xD6014739, 0x6A0A57D4, 0x7078BAE2, 0xE1101FED, 0x176E08DB};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 491 ");
	}
	{
		static const bigint_t var_a = {0xABBF4C3C, 0x97A9BC98, 0xE68D1B41, 0xFE8BDE9E, 0x8837B52C, 0xDF2E6FE0, 0xCFA69D4D, 0x231BE821};
		static const bigint_t var_expected = {0x5EADDDEB, 0xB9CFC4F5, 0x2603BB14, 0x58D91E9C, 0x2FD1CFAC, 0x182A22A6, 0x093D6184, 0x16EBDB75};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 492 ");
	}
	{
		static const bigint_t var_a = {0x3368DF18, 0xBB4A1E53, 0x53A244C5, 0xAD438C64, 0x813E03B3, 0x4FF822D4, 0xB184AE6F, 0x1D76E796};
		static const bigint_t var_expected = {0x125801AD, 0x9A38262A, 0x52631482, 0x7C1CA273, 0xB13B3837, 0x52E016F6, 0x99D14F76, 0x211A6645};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 493 ");
	}
	{
		static const bigint_t var_a = {0xEA012F44, 0xBB1BB4F8, 0x9212DDA9, 0x843A0ACC, 0x58AA69C8, 0x5C86EBC2, 0x89D9C6D5, 0x02557254};
		static const bigint_t var_expected = {0x6A91EF6D, 0xFDD6B7CB, 0xDBF7A2DE, 0xE29E1372, 0x0155C325, 0xE2D373A4, 0x2AC19DC3, 0x03A713C6};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 494 ");
	}
	{
		static const bigint_t var_a = {0x87CD5F5F, 0xB7EE007B, 0x73F7564B, 0xAC8FF832, 0x7727B251, 0xC0758E0D, 0x80370A69, 0x15F850C2};
		static const bigint_t var_expected = {0x49779664, 0xD87D28FE, 0x82C4B38F, 0x7154BAD2, 0xCEBB12B7, 0x5E4260D4, 0x5562C64C, 0x0E888F33};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 495 ");
	}
	{
		static const bigint_t var_a = {0x9B0DBD4E, 0x40DBE408, 0x9D85AB98, 0x64CDE488, 0x8622DC7D, 0xFE3C5B2C, 0x04C940CB, 0x08C3D431};
		static const bigint_t var_expected = {0x72730A17, 0x07E00F04, 0x22A4EDCA, 0x0BAF91F4, 0xA17B49DF, 0x5DFFE4D7, 0x53702FD7, 0x2051FB72};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 496 ");
	}
	{
		static const bigint_t var_a = {0xCCE2DA2A, 0xB8D806CF, 0xB046212B, 0xCC65E244, 0x617E5619, 0x164E57C5, 0x34D35C4C, 0x19F98CBB};
		static const bigint_t var_expected = {0x90249247, 0xFB1BD9CB, 0xECC5501A, 0xA06E5FD3, 0x5BE3FE00, 0x1E85813A, 0x0C2DE357, 0x130910EC};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 497 ");
	}
	{
		static const bigint_t var_a = {0xC998CD5B, 0x98F048B5, 0x50FF6346, 0x2B9E4790, 0xAED85160, 0x49C5B1F6, 0xFD59884D, 0x08D3BEF7};
		static const bigint_t var_expected = {0x3F220BA0, 0x5A00FFA8, 0xD2269623, 0xF59BB588, 0xBE11F971, 0xE696411C, 0x3F4B82A8, 0x1B53068C};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 498 ");
	}
	{
		static const bigint_t var_a = {0xE2EC945F, 0x023DEBFA, 0x45F71312, 0xAAA0EF46, 0x7047F1A6, 0x82F61122, 0xF18AD0E4, 0x2373FFA0};
		static const bigint_t var_expected = {0xA6DC1655, 0x41160D7D, 0x8A0118E9, 0x0F5B9E05, 0x04E048C4, 0xD4430A02, 0xA80CBCCC, 0x0E001A22};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 499 ");
	}
	{
		static const bigint_t var_a = {0x3D61731F, 0x4B60D24B, 0x19EF96E1, 0x8187844E, 0xF9362610, 0x8C20DCC0, 0x0C5ED0C8, 0x0362DB0A};
		static const bigint_t var_expected = {0xA4628691, 0x4EF30468, 0x03743A3D, 0x9D501653, 0x4635A653, 0x4F043547, 0xAFAF8D1F, 0x0B366122};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 500 ");
	}
	{
		static const bigint_t var_a = {0xD247013E, 0xE2FBFFD6, 0x8818370F, 0x97D12A07, 0x7BD6EA84, 0xE9BB4042, 0x2C38B044, 0x1A04356F};
		static const bigint_t var_expected = {0x9B06DD0E, 0x1DDEF14C, 0x44F54A6D, 0xEE52E9F7, 0x713D77D4, 0x338DA493, 0xF9ECAC9A, 0x0F2F0095};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 501 ");
	}
	{
		static const bigint_t var_a = {0x6CAC1A7E, 0x81216E35, 0x64A067E8, 0x9DDC8997, 0x7773D0FE, 0x30307F34, 0xB69B7864, 0x06072DA1};
		static const bigint_t var_expected = {0x0892ADA1, 0x1074A9E2, 0xB1AF83F1, 0xABBDB27D, 0x1DEF3832, 0xFAA14FF6, 0x96D35D71, 0x20F15454};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 502 ");
	}
	{
		static const bigint_t var_a = {0xCFC7784C, 0x13747FD4, 0x9EE99723, 0x8FE185D1, 0x3B721A16, 0xF66C84C6, 0x3D1ED2C2, 0x15607D89};
		static const bigint_t var_expected = {0x26310A65, 0xC69F535F, 0xC0CA86F3, 0xFFA3FA33, 0x033DA21B, 0xECD72BE4, 0x1DF7AF8C, 0x0CB28B8D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 503 ");
	}
	{
		static const bigint_t var_a = {0x837F9CC6, 0x2BBD83C8, 0xC8463040, 0x1160A2D4, 0x98F1D8E3, 0x3915E042, 0x2DE7060B, 0x0AAF0D61};
		static const bigint_t var_expected = {0x3F9F2D02, 0x87298E9E, 0x0CC6E753, 0x7204B674, 0x846ADE89, 0xF33457CB, 0x7EC5D961, 0x21004937};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 504 ");
	}
	{
		static const bigint_t var_a = {0xE7E2DFC7, 0xAE0BCAA8, 0x7FFF65C2, 0x2A4C0FFE, 0xA6B263B9, 0x5C764182, 0x4F3E0139, 0x1419690D};
		static const bigint_t var_expected = {0x1555A468, 0xB9672228, 0xEF8C4F51, 0x17CEB9F9, 0x7C74D937, 0x6CBA5041, 0x4A3806BA, 0x243CA256};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 505 ");
	}
	{
		static const bigint_t var_a = {0xE507886F, 0x782841C4, 0x80311430, 0x8F1EB399, 0x08AAB02B, 0x0DD15133, 0xFCA0C707, 0x00FE8893};
		static const bigint_t var_expected = {0x30990892, 0xF12DDBB7, 0x9F8DA136, 0x961EAFF6, 0x267A854E, 0x114A18D1, 0x7418CAF5, 0x1A832C30};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 506 ");
	}
	{
		static const bigint_t var_a = {0x1A0999B1, 0x79B4169F, 0xC2F4E6CD, 0x5D8C0B16, 0xDE2BF508, 0xE3D081D4, 0xD5BD5342, 0x09026522};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 507 ");
	}
	{
		static const bigint_t var_a = {0x39E06A62, 0x81AF9C1D, 0x715E73DB, 0x83B29EDD, 0x44B16DC7, 0x1FC89914, 0x02DA27D3, 0x163C64F7};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 508 ");
	}
	{
		static const bigint_t var_a = {0x38C3829B, 0x4BD818CD, 0x0126C7B2, 0x2FBE7A91, 0xB3B84142, 0xFFA53146, 0x90BAAC30, 0x17DC575A};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 509 ");
	}
	{
		static const bigint_t var_a = {0xC5D9C055, 0xFEA71A71, 0x83CEC7D4, 0x577B6D1D, 0x983F8A97, 0xBE2EAEC0, 0x0DC7F694, 0x1A177DA1};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 510 ");
	}
	{
		static const bigint_t var_a = {0xA1231C71, 0x351A7C48, 0x0A8A4678, 0x457BE02A, 0xC6C26E35, 0xDE7C4A32, 0x62DDBFB9, 0x151F38BA};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 511 ");
	}
	{
		static const bigint_t var_a = {0x06613EB4, 0x2719300F, 0x083E4875, 0x39021C53, 0x787CEEFB, 0x65FF0015, 0x6EA4F2DF, 0x245B631D};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 512 ");
	}
	{
		static const bigint_t var_a = {0x88BC72E7, 0x76342DA7, 0x3A85DF11, 0xA77479C8, 0x36CFD903, 0xA909A564, 0xBFFDF08F, 0x09E03F66};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 513 ");
	}
	{
		static const bigint_t var_a = {0xCA71C0D6, 0xBFC22EAD, 0xB6C1B2E2, 0x10CDBD4B, 0x5FC6948E, 0xE9F33656, 0xADD5187F, 0x0764F328};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 514 ");
	}
	{
		static const bigint_t var_a = {0xAAF80D7F, 0x69A91797, 0x82C77E72, 0x2660202B, 0xAE23FCCA, 0x9432820D, 0x97B195D3, 0x1AB08213};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 515 ");
	}
	{
		static const bigint_t var_a = {0xD7F33C91, 0xFB127998, 0x30E9A373, 0x4D3A98FA, 0x1996D416, 0xD5F34872, 0x872B11B7, 0x16E8623D};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 516 ");
	}
	{
		static const bigint_t var_a = {0xDE490AF2, 0x69C98690, 0xDFF76B8B, 0x4B06D02D, 0x337E94AB, 0x695A8E9B, 0xA6D3BC03, 0x024B4A1C};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 517 ");
	}
	{
		static const bigint_t var_a = {0x14B11471, 0x6D259FBE, 0x25ED3A65, 0x11F745DD, 0x9E82DBF6, 0x9602831D, 0x987C3D83, 0x1E1589FD};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 518 ");
	}
	{
		static const bigint_t var_a = {0xCF21C99A, 0xC0A9E89C, 0x031E47FF, 0xF178DEDC, 0x4BE0E7AB, 0x8B01AAA0, 0xE8A86126, 0x15227185};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 519 ");
	}
	{
		static const bigint_t var_a = {0xEB8DFCBF, 0xF1A9F88B, 0xCDF06872, 0x390F16DF, 0xFD568B81, 0x7AF486BB, 0x6CCED33C, 0x0190D77D};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 520 ");
	}
	{
		static const bigint_t var_a = {0xED81223D, 0xF8FF9B3C, 0xCEFC86AC, 0x3E0817BB, 0x437805B4, 0x06CD16E7, 0xE3BF93EE, 0x0667F4AE};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 521 ");
	}
	{
		static const bigint_t var_a = {0x1A14B7B2, 0xB9E3ECC1, 0x75DAD5E9, 0x5B109062, 0xE050E6A3, 0xC603C2CC, 0xEC8AB4CE, 0x227B0B5C};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 522 ");
	}
	{
		static const bigint_t var_a = {0x59AFF1F2, 0x4E71BA72, 0x1720DA4B, 0xE3AED0D5, 0x246BDB5F, 0x742606AB, 0xE41EB07E, 0x1D83F675};
		static const bigint_t var_expected = {0x438115B6, 0x8FBDE6A6, 0xA1477F9F, 0x645023E3, 0x43C778F1, 0xBC4249D0, 0x44C0BAE1, 0x1FDCE3C2};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 523 ");
	}
	{
		static const bigint_t var_a = {0x204EE12F, 0x779A9CB9, 0xA7E9CCE7, 0x8E54BBA2, 0xD1B10812, 0xD65862E5, 0x44E1BA26, 0x0BD2A43A};
		static const bigint_t var_expected = {0x6B63C957, 0xFCA9DDF4, 0xD4247321, 0x06CF6BFF, 0x339E48CB, 0xA9BE9DFD, 0xCF6385B0, 0x0DDBAD20};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 524 ");
	}
	{
		static const bigint_t var_a = {0xDF9B069D, 0x8E836EB9, 0xB21FF299, 0xDFA49600, 0x9A8B48F5, 0x4484CBD8, 0x48FAA58E, 0x1244A9D1};
		static const bigint_t var_expected = {0xAF17B0A3, 0xB3B3C429, 0x02332E27, 0x76784079, 0x537B12D8, 0x7AE92FA1, 0x7660ECDE, 0x05B1F4F2};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 525 ");
	}
	{
		static const bigint_t var_a = {0xC917425F, 0xC02A1317, 0x2DC7D8FF, 0x749BF173, 0xF2A8EE3A, 0x1ED94C2E, 0xD210C770, 0x19B28BC4};
		static const bigint_t var_expected = {0x9646D71C, 0xDCB4A459, 0xD4B40148, 0xC3027433, 0x7E09AD0C, 0x5354E24C, 0x8A150161, 0x0ED108E5};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 526 ");
	}
	{
		static const bigint_t var_a = {0xCD098924, 0xB61C6F7F, 0x00E89AFD, 0x197F79EC, 0xD4B1116D, 0xA70C364D, 0x7BDD0D7D, 0x096B56B8};
		static const bigint_t var_expected = {0x122F6E81, 0x1EF4C81F, 0xBD8EE28D, 0x5853B007, 0x0B11508D, 0x9E341381, 0x53D98CC8, 0x18F723F0};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 527 ");
	}
	{
		static const bigint_t var_a = {0x31CC62EF, 0xE23E3F8F, 0xF751E43D, 0x958E6F39, 0x8539E61B, 0x88428C02, 0xB3291EB1, 0x2445FC8F};
		static const bigint_t var_expected = {0xDDEB3E66, 0x5E1ACA3B, 0xC9780F0C, 0x11BFB75E, 0xD910332D, 0x16A06740, 0x9C3EC983, 0x0B566134};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 528 ");
	}
	{
		static const bigint_t var_a = {0xB812D11F, 0x2059BD9A, 0x3371F352, 0xF5D0EC9B, 0x08665344, 0xA6561DBA, 0xD626CAB3, 0x03E8D670};
		static const bigint_t var_expected = {0xB8CE3166, 0x22744584, 0xD4A38C62, 0x8A7234B9, 0x3BD5E909, 0xDF773A56, 0x837AE807, 0x205CD43C};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 529 ");
	}
	{
		static const bigint_t var_a = {0x3C462BD3, 0xFA9A0CDB, 0x50ECCC7E, 0x14C2809C, 0x5B51D7CA, 0x54ACD888, 0x1FAB35F1, 0x11AEA547};
		static const bigint_t var_expected = {0x84FBB2EB, 0x65939185, 0x61E37799, 0xCB40DE38, 0xE87BC8FB, 0xFDDA1DE7, 0x4CFD6A6A, 0x0F1E8CB9};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 530 ");
	}
	{
		static const bigint_t var_a = {0x6CB593A8, 0x00228ED8, 0xD0425CFF, 0x67B628D2, 0x66833869, 0xE5B47075, 0x8713E8D6, 0x1FE3BEF7};
		static const bigint_t var_expected = {0x948F63B4, 0x38D86DB2, 0xB4AEC308, 0x600E9DE7, 0x8557F888, 0x9F61D365, 0x4D2B999A, 0x1CCD3F4A};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 531 ");
	}
	{
		static const bigint_t var_a = {0xB3795033, 0x629742D0, 0x71C78523, 0xCB2D6F4C, 0x28F3B106, 0x3CC44211, 0x7F0E1672, 0x18C67BB6};
		static const bigint_t var_expected = {0xD5C379F3, 0xB459D3DD, 0xBC4B5265, 0x942A106B, 0xE67A60C8, 0xEA8CDD01, 0x2D10DF90, 0x08D151EF};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 532 ");
	}
	{
		static const bigint_t var_a = {0x07136657, 0x9D0966EA, 0xF4C28402, 0x02C58726, 0x2DA6289F, 0x6B6FAAD7, 0x14B47DCC, 0x17AADAD1};
		static const bigint_t var_expected = {0x91917047, 0x4F41F5EA, 0x11AEEEAD, 0x4D48945E, 0x6AA64D68, 0x3888E5F2, 0x98528DBC, 0x013DA290};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 533 ");
	}
	{
		static const bigint_t var_a = {0x45731B93, 0x2D9C3657, 0xB7C597E9, 0x6EF976FD, 0x818D5A5A, 0x06D62EF4, 0xFCC70226, 0x19C408A4};
		static const bigint_t var_expected = {0xE8351BD1, 0x5636E6EF, 0x848A7469, 0xAF8FE00F, 0x252627C9, 0x8FBB2594, 0x837D9456, 0x15B3586B};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 534 ");
	}
	{
		static const bigint_t var_a = {0x4412929F, 0xA38B6870, 0x845D46C1, 0x808A3C9B, 0xA3E65786, 0xAEBF1488, 0x0975A025, 0x003E04F2};
		static const bigint_t var_expected = {0xC747C744, 0x3E4F22AF, 0x711806CE, 0xD25DC32D, 0x5942629F, 0xC3517AD1, 0x4A2EB39D, 0x1548C6F0};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 535 ");
	}
	{
		static const bigint_t var_a = {0x7DB09DE1, 0x3118683A, 0x0C927B54, 0xB2840DBD, 0x2CD5C8DF, 0x3818AEF0, 0xB38AFAAE, 0x0274E4C1};
		static const bigint_t var_expected = {0x40D75B13, 0x262F8A58, 0x56ED18E4, 0x71D8F98D, 0xAE224C99, 0x03DDDB62, 0xFC7A4E99, 0x16BF8D72};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 536 ");
	}
	{
		static const bigint_t var_a = {0xB80B91D9, 0xF56DAC28, 0xB56A80C9, 0xC01BD2C9, 0x3C3963A3, 0x0D338052, 0x071BAC2F, 0x0203BC95};
		static const bigint_t var_expected = {0x6B823108, 0x34E80B72, 0xBB368A06, 0xE93F71A3, 0x67E64570, 0x089881EA, 0x0A201C38, 0x0685F345};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 537 ");
	}
	{
		static const bigint_t var_a = {0x649D5DB6, 0x4FE701F8, 0x118E201D, 0xA5D94C4C, 0x1CA37D61, 0xC0B8BC58, 0x7DC4B77C, 0x24F530DE};
		static const bigint_t var_expected = {0x26E7DC2B, 0xD0B4AD47, 0x08439D79, 0x6253095F, 0x8D9FA440, 0x8C64183F, 0xDECF71B5, 0x090E6ABD};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 538 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 247 ");
	}
	{
		static const bigint_t var_a = {0x0000000C, 0xA1000000, 0x00000010, 0xFF9F8000, 0x00000007, 0xBA344D80, 0x40000001, 0x25236482};
		static const bigint_t var_expected = {0x0000000C, 0xA1000000, 0x00000010, 0xFF9F8000, 0x00000007, 0xBA344D80, 0x40000001, 0x25236482};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 248 ");
	}
	{
		static const bigint_t var_a = {0x21282B29, 0x95FD9CB0, 0xD00EB27B, 0x6812ECFA, 0xAAE006C3, 0xDC63D7D5, 0xB973993D, 0x027F8FC5};
		static const bigint_t var_expected = {0x8483852E, 0x35718FB0, 0x563E5E09, 0x50C4ADB1, 0x8DCA0F3C, 0x63FC2938, 0x6A4912BE, 0x203E7F20};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 249 ");
	}
	{
		static const bigint_t var_a = {0x1F13019E, 0xC2322B6F, 0x0899EBE9, 0x9D425C8F, 0x9254AD79, 0x2E7C4005, 0x2FDCEB63, 0x092F9168};
		static const bigint_t var_expected = {0x459DD9C3, 0x26EC3D10, 0xC19C2E85, 0xDC397E22, 0xA103B88D, 0x436C21F7, 0xD10D056B, 0x0C43CE72};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 250 ");
	}
	{
		static const bigint_t var_a = {0x8D50E7F7, 0x6F17E25D, 0x88B9EA94, 0x2BC80896, 0x840D2A1B, 0x48972A31, 0xA80FD56D, 0x02D50E4E};
		static const bigint_t var_expected = {0x6DB5CC31, 0xCCDC6338, 0xFCF57218, 0x5D592E6D, 0xBF8CD454, 0xA022D7FD, 0x81D8ABE0, 0x1181913A};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 251 ");
	}
	{
		static const bigint_t var_a = {0x7A5479B1, 0xE59393C2, 0x88F91482, 0xE8A7D912, 0xC725A059, 0x442ABD76, 0xE3474EF7, 0x24B9C36F};
		static const bigint_t var_expected = {0xBAF6415C, 0x9DB64F9B, 0xAEE9D3DB, 0x0969F1F9, 0x456C5038, 0x9B9FB764, 0xDDDE44CD, 0x1BB80EC6};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 252 ");
	}
	{
		static const bigint_t var_a = {0x6B8838B6, 0xB7FF5C4E, 0x93B58898, 0xCB035950, 0xD5FD7CC2, 0xA80A1B7F, 0xB1C5231D, 0x1E9390AD};
		static const bigint_t var_expected = {0x4C4ED356, 0x08C00224, 0xF4900D7E, 0x60780BA5, 0x8DD6A0B6, 0xF01A448A, 0xE2041B6A, 0x148264CC};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 253 ");
	}
	{
		static const bigint_t var_a = {0xD9054BDF, 0xBB3BB1B5, 0x09B416D6, 0x6D783A05, 0xDE4EDF9A, 0xFF69ACEA, 0x77FEFFC8, 0x04D541B5};
		static const bigint_t var_expected = {0xD4C05CF5, 0x3775E9DD, 0x5F2E7C3B, 0xDAA5803F, 0xCB94E7B3, 0x0CC85EB2, 0x4E7CD73B, 0x11CE3DCD};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 254 ");
	}
	{
		static const bigint_t var_a = {0xB0203E83, 0x34D4E002, 0x9D0B3403, 0x8A2B7D1F, 0x430DDEE1, 0xE58722A9, 0xEF1C3E4A, 0x19520A07};
		static const bigint_t var_expected = {0x7C915A45, 0x6C11C7D0, 0x2A4E252D, 0xC146DB2B, 0xB0969240, 0x5C247558, 0x28627E3B, 0x04C218DB};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 255 ");
	}
	{
		static const bigint_t var_a = {0xD2C196C8, 0x1536D28E, 0xD75901BE, 0x87BAB2C3, 0x1B1BD9AE, 0x6AAF4946, 0x67C81DA3, 0x21336414};
		static const bigint_t var_expected = {0xBF1F10D1, 0xDF9F6A82, 0x32B3FD6F, 0x541AABF6, 0xD41A859B, 0x581BB576, 0xCD914DF5, 0x03E73E12};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 256 ");
	}
	{
		static const bigint_t var_a = {0x929155E7, 0x8CF3DB8F, 0x92490CA6, 0xE8955FDA, 0xB1CA3D05, 0xE302BEC8, 0x004D3243, 0x18778CFC};
		static const bigint_t var_expected = {0xB79148D6, 0x74F14158, 0xFFBCB25F, 0x863AFF81, 0x7EA5B07D, 0x78E1601A, 0xD41108FE, 0x04DF2DE4};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 257 ");
	}
	{
		static const bigint_t var_a = {0x3AF296B9, 0x9514F37A, 0x7F694DAC, 0xDB767E6F, 0x033169C2, 0xE91DF275, 0xB0032704, 0x08A7A7FB};
		static const bigint_t var_expected = {0xECFC9543, 0x4E07353C, 0x4901B421, 0x80A0601D, 0xA70118C5, 0x37537CB3, 0xBF02435D, 0x076C2D80};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 258 ");
	}
	{
		static const bigint_t var_a = {0x85CAECEB, 0xC4839F07, 0xA15293DB, 0xAB1BAD07, 0x4548921D, 0x9A613001, 0x01123371, 0x12BFB8A8};
		static const bigint_t var_expected = {0xAD517ECC, 0x7A12DDED, 0xEB8E5DA9, 0xF3708068, 0x9995BB6A, 0xABCFCEB9, 0x9CB5014A, 0x1E2B6A5E};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 259 ");
	}
	{
		static const bigint_t var_a = {0x25203CAC, 0x087A6883, 0xD01E7214, 0x47F9730E, 0x5CE2E59C, 0x1B6931C2, 0x507AD6E1, 0x20D3D803};
		static const bigint_t var_expected = {0x4BB312CA, 0xE7859F9E, 0x9529F637, 0x08D9B24B, 0xD98F2258, 0x084A10A4, 0x59A33D46, 0x0FEFB8FB};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 260 ");
	}
	{
		static const bigint_t var_a = {0x3E82146C, 0x1209AB45, 0x362F31EF, 0xCBE0B978, 0x646B3DF6, 0x117FD787, 0x0E77BAA1, 0x025A8E3A};
		static const bigint_t var_expected = {0x1012259B, 0xE6C6B26A, 0x88720808, 0x0C5CAD6D, 0xE5A1F8C9, 0x95C93A10, 0xE959108C, 0x16CC2575};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 261 ");
	}
	{
		static const bigint_t var_a = {0xE943EEF2, 0x7BAF0C81, 0xD4429431, 0xED08E99F, 0x2B7C2175, 0xE323E7A4, 0x822ECFC3, 0x0EAE60B4};
		static const bigint_t var_expected = {0xC94C1219, 0xB1DBCAFD, 0x14FB222B, 0x2126A883, 0xDEC29CF2, 0x866D4864, 0x25807371, 0x09804858};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 262 ");
	}
	{
		static const bigint_t var_a = {0xB286B5DF, 0x52F7FB63, 0xFEDC426E, 0x9219359C, 0xB33CECEA, 0x32266CEA, 0x86AA002A, 0x0F6E4C93};
		static const bigint_t var_expected = {0x4139FE7C, 0x65CF3E09, 0xD432FF47, 0x1E1BBDB2, 0x0C61E8F2, 0xEA290202, 0x1AEF173A, 0x0450038F};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 263 ");
	}
	{
		static const bigint_t var_a = {0x1B1588C6, 0xE831F175, 0xDBFB3F9E, 0x31C1122E, 0xB4965F11, 0x4AA483CE, 0x462B1D2A, 0x1B157C91};
		static const bigint_t var_expected = {0xAC0DACC2, 0xF4872519, 0x433105D2, 0x46AF0FE9, 0x708CC316, 0x7003E9AA, 0x2BA21FBB, 0x06363ED6};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 264 ");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const bigint_t var_a = {0x12E45EAB, 0xA123174B, 0x5A60321B, 0x3A38E40F, 0x2E04DF6F};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 293 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 294 ");
	}
	{
		static const bigint_t var_a = {0x76CC6C68, 0x20A2D35E, 0xEC92832C, 0x35E4FF7F, 0x1E8992CC};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 295 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 296 ");
	}
	{
		static const bigint_t var_a = {0x2FCE3F6E, 0x62906BCB, 0xECC831E5, 0x040BEBF9, 0x42B4A78E};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 297 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 298 ");
	}
	{
		static const bigint_t var_a = {0x717B025C, 0x27E7DFC9, 0x67AC4E61, 0xBEBA92C7, 0xA1AE7672};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 299 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 300 ");
	}
	{
		static const bigint_t var_a = {0x73EE608A, 0x84D75004, 0x43A0C247, 0x2A8F9764, 0xEDEB263C};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 301 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 302 ");
	}
	{
		static const bigint_t var_a = {0x9597E374, 0xBE228D74, 0xEA101FC0, 0x400EE1B4, 0x7B24B435};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 303 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 304 ");
	}
	{
		static const bigint_t var_a = {0xF9F2E5FD, 0xA3752E9E, 0xC421F375, 0x9AB30F23, 0x728892A0};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 305 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 306 ");
	}
	{
		static const bigint_t var_a = {0x4AD9FA47, 0x31F808EA, 0x86F45FC4, 0x5934DBD0, 0x94D9496B};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 307 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 308 ");
	}
	{
		static const bigint_t var_a = {0x8F2FB5B2, 0x3CF6D99C, 0x6EE564F3, 0xD56186C2, 0xC46BA312};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 309 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 310 ");
	}
	{
		static const bigint_t var_a = {0x89C861BB, 0x9E54E5AC, 0xE1F7A3F4, 0xE91E6023, 0x25FE5C1F};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 311 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 312 ");
	}
	{
		static const bigint_t var_a = {0x7534092C, 0x5CFE7DCD, 0x8211D6AD, 0xCDCA7EE3, 0xF45E2EC8};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 313 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 314 ");
	}
	{
		static const bigint_t var_a = {0xDBBE2FEA, 0x9174CD5E, 0x3D535043, 0x0E649369, 0x0F9093F6};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 315 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 316 ");
	}
	{
		static const bigint_t var_a = {0xE8FFEF27, 0x683CA491, 0xA793913D, 0x5A25942D, 0x2BBC17A7};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 317 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 318 ");
	}
	{
		static const bigint_t var_a = {0x148E33A1, 0xD53C13E7, 0x1B8E231E, 0x7F199474, 0xF13111D7};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 319 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 320 ");
	}
	{
		static const bigint_t var_a = {0xAD31FDE7, 0xACE723ED, 0x909A73D6, 0xE5894EA2, 0xC3A42042};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 321 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 322 ");
	}
	{
		static const bigint_t var_a = {0x606067EF, 0x0198D893, 0xBF52349F, 0xA06213BD, 0xE82831D1};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "fp_clear 323 ");
		fp_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "fp_clear 324 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 325 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 326 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 327 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 328 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_b = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 329 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 330 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 331 ");
	}
	{
		static const bigint_t var_a = {0x1AB35C5B, 0x659C3EE6, 0x92940D07, 0xE723E269, 0x152E629D};
		static const bigint_t var_b = {0xC21D9B50, 0x8AC0B90D, 0xA9659155, 0xB143EB63, 0x0FAF51B0};
		static const bigint_t var_expected = {0x9080A550, 0xD22FA353, 0x02AEDDBE, 0xE91171E7, 0x00DC944A};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 332 ");
	}
	{
		static const bigint_t var_a = {0x8EDC3995, 0x1C405997, 0x3A5AC5A2, 0xC5BC8E67, 0x071EA4D7};
		static const bigint_t var_b = {0xF111F0E6, 0xF7477C26, 0xB449A4EA, 0xD4D1B2FD, 0x1670CE84};
		static const bigint_t var_expected = {0x7FEE2A7B, 0x1387D5BE, 0xEEA46A8D, 0x9A8E4164, 0x1D8F735C};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 333 ");
	}
	{
		static const bigint_t var_a = {0xA42BCFB0, 0x8FBEB5A3, 0x38A3DF8C, 0xF42C751E, 0x1537158E};
		static const bigint_t var_b = {0xFD19F8FF, 0xF0654494, 0xF5675CA5, 0xB866EDF5, 0x0DB14056};
		static const bigint_t var_expected = {0xA145C8AF, 0x8023FA38, 0x2E0B3C32, 0xAC936314, 0x22E855E5};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 334 ");
	}
	{
		static const bigint_t var_a = {0x2B211C3C, 0x71711EC4, 0x4F25B854, 0xA6BACC12, 0x2161CB5E};
		static const bigint_t var_b = {0x98141B0C, 0x7EED39E1, 0xF290F01C, 0x6E23E721, 0x0BFA4378};
		static const bigint_t var_expected = {0x76E4E4ED, 0xD2310405, 0x086BE7D2, 0x6588574E, 0x095AEED3};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 335 ");
	}
	{
		static const bigint_t var_a = {0x6F1BE2E1, 0x574E4F72, 0x2041A5E7, 0x8C7D3526, 0x187AFB67};
		static const bigint_t var_b = {0x5D4ADC8B, 0x7F3959C7, 0x95D63339, 0xCFC4A64B, 0x22E777A1};
		static const bigint_t var_expected = {0x80166D11, 0xB85A5499, 0x7CCD1882, 0xACEB7F8B, 0x17615305};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 336 ");
	}
	{
		static const bigint_t var_a = {0x79445A64, 0x0D7078F9, 0xB20BDBC5, 0xE795AE6E, 0x0BCFC9D0};
		static const bigint_t var_b = {0xFA0E74B2, 0x4AB3F29F, 0x866A98F8, 0x2A3172E5, 0x182C5382};
		static const bigint_t var_expected = {0x7352CF16, 0x58246B99, 0x387674BD, 0x11C72154, 0x23FC1D53};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 337 ");
	}
	{
		static const bigint_t var_a = {0xBFD5CD0C, 0xC207D0B8, 0x0A6A0D2D, 0xDF1031F4, 0x1D93026E};
		static const bigint_t var_b = {0x500DE382, 0xBB313D4B, 0x7072FAA3, 0x77E33845, 0x13D00D59};
		static const bigint_t var_expected = {0xC3935E33, 0x5F0BB963, 0x41924733, 0xA79D0E53, 0x0D61EFC4};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 338 ");
	}
	{
		static const bigint_t var_a = {0x064BFB2A, 0xC5B8F7CD, 0x2F893C25, 0xD5BAE60B, 0x1F24F750};
		static const bigint_t var_b = {0xD39474F9, 0x9BED7AAC, 0xCE324BEE, 0x235C29BB, 0x17783DDA};
		static const bigint_t var_expected = {0x8D901DC8, 0x43791DD9, 0xC470C776, 0x49C0B3E0, 0x129C1527};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 339 ");
	}
	{
		static const bigint_t var_a = {0x153D7F7E, 0xDDBF4E7B, 0xF2D4F145, 0x9DD24433, 0x0EDF290F};
		static const bigint_t var_b = {0xE5B654EE, 0xA39623AF, 0xC4CC5C56, 0x7549D703, 0x05DAB4C2};
		static const bigint_t var_expected = {0xFAF3D46C, 0x8155722A, 0xB7A14D9C, 0x131C1B37, 0x14B9DDD2};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 340 ");
	}
	{
		static const bigint_t var_a = {0x7BA616B9, 0x32D7C6DC, 0x074B3E7C, 0xA23A2EC1, 0x1B1EACE2};
		static const bigint_t var_b = {0x476307A5, 0x1778D958, 0xD8DAC871, 0x90AC15D4, 0x14FE42DB};
		static const bigint_t var_expected = {0x76B8CC03, 0x2C234B94, 0xA6DB464F, 0x838FE8AF, 0x0C1BCFBA};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 341 ");
	}
	{
		static const bigint_t var_a = {0xE5EADC69, 0xDD623836, 0x8D21351D, 0xBB1D6FE2, 0x2037F7AF};
		static const bigint_t var_b = {0xE7E9FCBE, 0xCD5979C7, 0xC9978BE2, 0x20BF22BD, 0x1484FDC7};
		static const bigint_t var_expected = {0x818486CC, 0x8C8E5D5E, 0x1D6E0062, 0x2C8636BA, 0x10BBD573};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 342 ");
	}
	{
		static const bigint_t var_a = {0xC609F357, 0xBCEF9438, 0x34F05F71, 0x0DB9205D, 0x03BE870E};
		static const bigint_t var_b = {0x1C4BF5AA, 0x7EF8010F, 0x8248837F, 0x322AE672, 0x08FD900E};
		static const bigint_t var_expected = {0xE255E901, 0x3BE79547, 0xB738E2F1, 0x3FE406CF, 0x0CBC171C};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 343 ");
	}
	{
		static const bigint_t var_a = {0x6E922CEF, 0x795A6B9D, 0xCDE49E67, 0x3F8C394B, 0x145C5D22};
		static const bigint_t var_b = {0xD1E72B24, 0x31D04CBC, 0x34BF054C, 0x891F51AE, 0x16EE5A30};
		static const bigint_t var_expected = {0xF42905B8, 0x8CFD63B9, 0xC958E315, 0x19552F13, 0x0749974F};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 344 ");
	}
	{
		static const bigint_t var_a = {0x19B0D149, 0x8F221164, 0xB3E4CC4C, 0xBB62D194, 0x11855D55};
		static const bigint_t var_b = {0x057F0746, 0xC6AE17C6, 0xA558F6F1, 0xD167876E, 0x189BF1AB};
		static const bigint_t var_expected = {0xD2DF8634, 0x37A2D489, 0x1FF302A0, 0xDD73FD1D, 0x06202EFD};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 345 ");
	}
	{
		static const bigint_t var_a = {0xF3534E50, 0x83A37778, 0xEE9618AC, 0x7F149EC6, 0x16996C5A};
		static const bigint_t var_b = {0x9FDB5E60, 0x6A4FA759, 0x412483C8, 0x7D2FE677, 0x18C9EF0F};
		static const bigint_t var_expected = {0x46DE5A55, 0xCFC5CA32, 0xF66FDBD6, 0x4CEE2957, 0x0B623B66};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 346 ");
	}
	{
		static const bigint_t var_a = {0xD15D228B, 0xF1F10CDA, 0x40920987, 0xAFE36ABB, 0x0093865A};
		static const bigint_t var_b = {0xD1E481F1, 0xE3EDC41B, 0x0C8250F9, 0xF55F6A1E, 0x20AFFD77};
		static const bigint_t var_expected = {0xA341A47C, 0xD5DED0F6, 0x4D145A81, 0xA542D4D9, 0x214383D2};
		fp_add(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_add 347 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 348 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 349 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 350 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 351 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_b = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 352 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 353 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 354 ");
	}
	{
		static const bigint_t var_a = {0x7A5DC981, 0xC61B767C, 0x0DA7EFEA, 0x931D20F4, 0x021CD8B8};
		static const bigint_t var_b = {0xD0B2E1E0, 0x1B15509A, 0x1FB74BE8, 0x14B28F2B, 0x193206EA};
		static const bigint_t var_expected = {0xF5FB39FC, 0xC9337A81, 0x273B64A0, 0x2DC0EDAF, 0x0CEBF1D2};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 355 ");
	}
	{
		static const bigint_t var_a = {0x839CCA37, 0x813B24EE, 0x41CDE91D, 0x11B3C921, 0x07230943};
		static const bigint_t var_b = {0x1EBDC74D, 0x6963A20C, 0x50D042BF, 0x45A3BAD1, 0x0FD89CEF};
		static const bigint_t var_expected = {0xB12F5545, 0x3604D782, 0x2A4866FC, 0x7B666A36, 0x1B4B8C57};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 356 ");
	}
	{
		static const bigint_t var_a = {0x02A91058, 0xA5EF9048, 0x004B4464, 0xDA08C765, 0x1294AE49};
		static const bigint_t var_b = {0x8BED7ADA, 0xB552F6A0, 0x21748891, 0xAB75F6FD, 0x13470CB7};
		static const bigint_t var_expected = {0xC30BE7D9, 0x0EC9EE47, 0x18217C71, 0xDDE92C4E, 0x234EC195};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 357 ");
	}
	{
		static const bigint_t var_a = {0xDDCFFD9F, 0x3909B4C0, 0xDAB0BA08, 0x3CC9E293, 0x1C230AE4};
		static const bigint_t var_b = {0x7D3E15C1, 0x9018BC71, 0xAC7F2549, 0xFE02AAA2, 0x141C41E9};
		static const bigint_t var_expected = {0x6091E7DE, 0xA8F0F84F, 0x2E3194BE, 0x3EC737F1, 0x0806C8FA};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 358 ");
	}
	{
		static const bigint_t var_a = {0x5A75CB68, 0x5F8C55CD, 0x6F96C4F9, 0x91D21DE2, 0x1C407F50};
		static const bigint_t var_b = {0xC23E22FA, 0xB53A8CE8, 0x17208E98, 0x63B6D3F8, 0x13E19747};
		static const bigint_t var_expected = {0x9837A86E, 0xAA51C8E4, 0x58763660, 0x2E1B49EA, 0x085EE809};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 359 ");
	}
	{
		static const bigint_t var_a = {0xF0235F8C, 0x45D71E0E, 0x2AEDA479, 0xD08AD5CF, 0x16753F78};
		static const bigint_t var_b = {0x847F48F5, 0x3A8C28AC, 0xBD622E1F, 0x7041F42F, 0x17D373FC};
		static const bigint_t var_expected = {0xB7F468F2, 0x29784A02, 0xA6D636F8, 0x0F9F3D85, 0x22A2EB80};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 360 ");
	}
	{
		static const bigint_t var_a = {0x9C4F7A1A, 0x15994818, 0xB9D878BA, 0xDC4A4792, 0x00C0A0A0};
		static const bigint_t var_b = {0x0FF68DBE, 0x986CED3E, 0xF05970E6, 0xDBECDB84, 0x18A68473};
		static const bigint_t var_expected = {0xD8A93EB7, 0x9B59AF7A, 0x02C9C871, 0xAFB3C7F4, 0x0C1B3C30};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 361 ");
	}
	{
		static const bigint_t var_a = {0xBD67A4B5, 0x06F75792, 0xCDE08F9A, 0x02A9733E, 0x08B92027};
		static const bigint_t var_b = {0xDB678897, 0x8DBD8470, 0x98A22BEA, 0x86944890, 0x1B1820C7};
		static const bigint_t var_expected = {0x2E506E79, 0x976727C2, 0x6E89244D, 0x2B6B8694, 0x11A21F63};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 362 ");
	}
	{
		static const bigint_t var_a = {0x049E3607, 0x1AF248AC, 0xB4151A40, 0x3CD4BE85, 0x1C0B10F9};
		static const bigint_t var_b = {0xAD8BA8E6, 0x0C7A7C87, 0x19539429, 0x3BCAE0F9, 0x0CDC84AD};
		static const bigint_t var_expected = {0x57128D21, 0x0E77CC24, 0x9AC18617, 0x0109DD8C, 0x0F2E8C4C};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 363 ");
	}
	{
		static const bigint_t var_a = {0x11EA5ECC, 0x01DF2CEB, 0x146AB436, 0x7B80390B, 0x0BAD5F4F};
		static const bigint_t var_b = {0xA303FD3E, 0xFC1E8DD6, 0x0089A73B, 0xB63B0F8E, 0x0DBA11EA};
		static const bigint_t var_expected = {0xBB36B3E9, 0x23EDF3B4, 0x4D2BCD98, 0x749B8563, 0x21F46D68};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 364 ");
	}
	{
		static const bigint_t var_a = {0xD019BA8E, 0x130278C7, 0xEE98AA2B, 0x021EC03D, 0x0A7BEA64};
		static const bigint_t var_b = {0xDDCA13F6, 0xB03023BF, 0xD3A0F999, 0x5FADC9D9, 0x1D6456A3};
		static const bigint_t var_expected = {0x3E9FF8F3, 0x80FFA9A8, 0x5442712F, 0x51C7524A, 0x1118B3C4};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 365 ");
	}
	{
		static const bigint_t var_a = {0x8F73F931, 0x6434C7C3, 0x05272F92, 0x2315EE62, 0x1BBB4099};
		static const bigint_t var_b = {0xD836357B, 0x980E0BFF, 0xD0F33113, 0x4DAF4B5C, 0x1751C257};
		static const bigint_t var_expected = {0xB73DC3B6, 0xCC26BBC3, 0x3433FE7E, 0xD566A305, 0x04697E41};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 366 ");
	}
	{
		static const bigint_t var_a = {0xC1508592, 0x73C7FA8A, 0x1D74485A, 0xFF3F94E7, 0x21781387};
		static const bigint_t var_b = {0x4C7449DC, 0x226415AD, 0x99F9E673, 0x13B07668, 0x0162E5E4};
		static const bigint_t var_expected = {0x74DC3BB6, 0x5163E4DD, 0x837A61E7, 0xEB8F1E7E, 0x20152DA3};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 367 ");
	}
	{
		static const bigint_t var_a = {0x9A8DAD5A, 0xE29895CA, 0xCF2E168D, 0xBD0AA845, 0x14247FA1};
		static const bigint_t var_b = {0x8E10A19C, 0x08F31789, 0x2C13C31E, 0x83E5931B, 0x143F6210};
		static const bigint_t var_expected = {0x58CD5E19, 0xF7D2D2E1, 0xDC65140D, 0xE87B7110, 0x23E63D94};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 368 ");
	}
	{
		static const bigint_t var_a = {0xE79B574B, 0x75820867, 0xF12908CE, 0x427DF2D3, 0x0CED1BE9};
		static const bigint_t var_b = {0xABC1C092, 0x48EA7953, 0xF14B5E63, 0xEC8F5E2C, 0x143CB6C6};
		static const bigint_t var_expected = {0x8829E914, 0x4AC4E3B4, 0x39286B09, 0x0544F08D, 0x1CB18526};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 369 ");
	}
	{
		static const bigint_t var_a = {0xD50621CF, 0xEBF13006, 0xB16FA45E, 0x659FA0D5, 0x12D8DFD5};
		static const bigint_t var_b = {0x2A634CFB, 0x1FFD0443, 0xF66A1FD7, 0xF1AE88AA, 0x16730665};
		static const bigint_t var_expected = {0xF6F3272F, 0xEA218063, 0xF4504525, 0x23477410, 0x2066F973};
		fp_sub(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_sub 370 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 371 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 372 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 373 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_b = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 374 ");
	}
	{
		static const bigint_t var_a = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_b = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 375 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_b = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_expected = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 376 ");
	}
	{
		static const bigint_t var_a = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_b = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 377 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_b = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 378 ");
	}
	{
		static const bigint_t var_a = {0xFBB88FB3, 0xF665B692, 0x23F67266, 0x7AC2BD8C, 0x0F756B1B};
		static const bigint_t var_b = {0x289A1709, 0x1D34B4B0, 0xF99D20FC, 0x0A939EFC, 0x167B7B9D};
		static const bigint_t var_expected = {0x84329B91, 0x4E87BB5A, 0x04C3E3C8, 0xAA1CC003, 0x04B4A040};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 379 ");
	}
	{
		static const bigint_t var_a = {0xC076D3B0, 0x6C0E86E6, 0x9BBC3234, 0x3D17F8A2, 0x0019FC0C};
		static const bigint_t var_b = {0xFBAAEEAF, 0x57FCF029, 0xEBD05F90, 0xC3AD407F, 0x1E1E02CA};
		static const bigint_t var_expected = {0x5AA6EA41, 0xB4C8DC00, 0x7450BAED, 0x40905B7B, 0x232AF4D5};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 380 ");
	}
	{
		static const bigint_t var_a = {0xF2731980, 0xA15E2926, 0xF219CFA1, 0xB5F8EDED, 0x02FDC946};
		static const bigint_t var_b = {0x1096D7A4, 0x9791CCE4, 0x4E84DD49, 0x59C4DB69, 0x17A3D2EB};
		static const bigint_t var_expected = {0xF7EC2929, 0xBB2680EE, 0xA922E732, 0x14370A49, 0x046B4644};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 381 ");
	}
	{
		static const bigint_t var_a = {0xCCF2E020, 0xF90AA248, 0x1BCEB903, 0xD590F9CB, 0x0598239C};
		static const bigint_t var_b = {0x8A74F967, 0xA68627C7, 0x85B66C5A, 0x23326B5F, 0x0B009291};
		static const bigint_t var_expected = {0xA8003021, 0x58348A59, 0x7D3FD28B, 0xF69546A3, 0x0B733F45};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 382 ");
	}
	{
		static const bigint_t var_a = {0xBA031E3D, 0x426EF9CD, 0x45D04262, 0x03A4F271, 0x055E5320};
		static const bigint_t var_b = {0x6089F8EE, 0x7CDC017A, 0x275D87BE, 0xB6DFB186, 0x1809A1EB};
		static const bigint_t var_expected = {0x28D51AD0, 0x07AAC676, 0x902825EB, 0xA11CCF6A, 0x1E4E3140};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 383 ");
	}
	{
		static const bigint_t var_a = {0xC295DCDB, 0xD7AF94CE, 0xCE913034, 0xE4944BFA, 0x028ED4DF};
		static const bigint_t var_b = {0x4EB9E483, 0x9AFD2F37, 0x51108EA4, 0x7796472A, 0x172A3503};
		static const bigint_t var_expected = {0x5C29FA62, 0x571A0CC3, 0x05E0F567, 0xF00D9DA2, 0x0CF7C138};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 384 ");
	}
	{
		static const bigint_t var_a = {0xACE3F853, 0x0574D313, 0x387787DE, 0x1DE434E5, 0x1E540293};
		static const bigint_t var_b = {0x13C33353, 0xA84ACA08, 0x992FAD55, 0x02F1D5BB, 0x0BCC1975};
		static const bigint_t var_expected = {0x27CA2710, 0xF427517D, 0xE605F9B9, 0x9697AFDA, 0x0CA5ADC9};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 385 ");
	}
	{
		static const bigint_t var_a = {0x3BB39716, 0xF4E1391D, 0x264A7281, 0x930A91C3, 0x1A1D4BC5};
		static const bigint_t var_b = {0x9DF5500F, 0xD1C264F7, 0x2244C75E, 0xE3AB23F1, 0x04CF34FA};
		static const bigint_t var_expected = {0xE578DDC7, 0xBD1A9D14, 0x0F1BB977, 0x7BA6E786, 0x1E6938C1};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 386 ");
	}
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
	{
		static const bigint_t var_a = {0x255FE6B5, 0x4C175AD2, 0x2EDC0FE3, 0xEDE8B1E2, 0x2051486A};
		static const bigint_t var_b = {0xE768A9DE, 0x7DAEC78A, 0x3FC2DC11, 0x2B10FDE0, 0x00330C38};
		static const bigint_t var_expected = {0x33359598, 0xB89E9E31, 0x1E3614A0, 0xF8CB1CB0, 0x0F592B82};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 389 ");
	}
	{
		static const bigint_t var_a = {0x6D6500C4, 0xE30F6E6C, 0x6A931FBB, 0x847C0966, 0x1A89BC1C};
		static const bigint_t var_b = {0x22A0730A, 0xD00FB0F4, 0x2FEE5066, 0x9D78BCE8, 0x1613BE87};
		static const bigint_t var_expected = {0x037CC802, 0x20B4EB1D, 0x27071858, 0x99DB2745, 0x0A359D1A};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 390 ");
	}
	{
		static const bigint_t var_a = {0xAED62EAC, 0x492057F2, 0xFEC88C5A, 0x63449123, 0x187A15A4};
		static const bigint_t var_b = {0x3A90DB09, 0x3AC32ABA, 0x21B2ACF3, 0x56169A21, 0x13524141};
		static const bigint_t var_expected = {0x888A48F7, 0xB1CE4361, 0x2ED081C2, 0x2924E72A, 0x1059433B};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 391 ");
	}
	{
		static const bigint_t var_a = {0xCBCA2CE0, 0x59B8980D, 0x4CB493CC, 0x924B0C43, 0x12087733};
		static const bigint_t var_b = {0x65196CFD, 0x03C877F8, 0x2ABC4180, 0xDEDF29DF, 0x1D01D4DC};
		static const bigint_t var_expected = {0x6B43373B, 0x4C5479A0, 0x41FF14D7, 0x4BDC63F5, 0x113C8180};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 392 ");
	}
	{
		static const bigint_t var_a = {0xB1B7B048, 0xAD35EDD5, 0x52EB0E72, 0x310A16C0, 0x21647AB6};
		static const bigint_t var_b = {0xF65E4E73, 0xD53A0A7F, 0xF343951A, 0x7BC950C6, 0x03C91C7D};
		static const bigint_t var_expected = {0x814ACE15, 0x3F253958, 0x5475263F, 0x9AEEB5FF, 0x152EF0BF};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 393 ");
	}
	{
		static const bigint_t var_a = {0x3BD0C75F, 0x7D54A9DC, 0x90E97641, 0xAAB5C0CB, 0x1F334688};
		static const bigint_t var_b = {0xFDA55CAB, 0x90D2152C, 0x1CDD2026, 0x840ABD11, 0x0DD6B411};
		static const bigint_t var_expected = {0x2DE48F5D, 0x4798B2BE, 0x1EC0F810, 0xE0B82EA1, 0x1D54C5E5};
		fp_mul(var_res, var_a, var_b);
		assert_bi_equal(var_res, var_expected, "fp_mul 394 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 395 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 396 ");
	}
	{
		static const bigint_t var_a = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 397 ");
	}
	{
		static const bigint_t var_a = {0x10DF1D81, 0x636EC82D, 0x9D761295, 0x02EA602B, 0x1C6C464F};
		static const bigint_t var_expected = {0x588EB497, 0xCC10B760, 0x63EFE325, 0x2BE1D369, 0x157D76DD};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 398 ");
	}
	{
		static const bigint_t var_a = {0xFC899283, 0x5B01404D, 0x6B7D2641, 0x0981086C, 0x181E01A3};
		static const bigint_t var_expected = {0x6CB1B425, 0x14091AB6, 0xFC53DAE5, 0x17613E30, 0x22AF5EC8};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 399 ");
	}
	{
		static const bigint_t var_a = {0xB9B51F72, 0x048D8DEE, 0x717B20B0, 0xFD7DC393, 0x037EF6DC};
		static const bigint_t var_expected = {0x262C89DA, 0x4D249CDE, 0x0268D31B, 0x52D20618, 0x20A2E402};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 400 ");
	}
	{
		static const bigint_t var_a = {0x14B34877, 0x351CC566, 0x77831BBC, 0xDA3AD265, 0x184A4A5E};
		static const bigint_t var_expected = {0x581F15A7, 0x9D603BFB, 0x27ACFDEE, 0x2EFB554C, 0x16834A78};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 401 ");
	}
	{
		static const bigint_t var_a = {0x43AA4826, 0x414FA787, 0x29C61727, 0x56CFE6F8, 0x20BB60F2};
		static const bigint_t var_expected = {0x76FAAF65, 0x0D59BCAD, 0x7849C555, 0xAF383BFA, 0x01A508D1};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 402 ");
	}
	{
		static const bigint_t var_a = {0xFF1E2A8F, 0x714E8DDA, 0x06D4C7DB, 0xAAD07062, 0x080800E5};
		static const bigint_t var_expected = {0xD313B6F0, 0xEC7B1DB2, 0x168914DE, 0xCDF99D36, 0x190ED4D0};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 403 ");
	}
	{
		static const bigint_t var_a = {0xD6277BF8, 0x4CC43B46, 0x70CE5C1A, 0x3B2D0D42, 0x13B91AE9};
		static const bigint_t var_expected = {0x738B1091, 0x8C4DD829, 0x8AD4B61B, 0xF89352FF, 0x130F8809};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 404 ");
	}
	{
		static const bigint_t var_a = {0xB074D307, 0xE5125662, 0x1D5186C9, 0x0C831A2E, 0x0D935A4C};
		static const bigint_t var_expected = {0xE580BEBE, 0x0FA97691, 0x56196B20, 0x36E35E51, 0x1201992B};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 405 ");
	}
	{
		static const bigint_t var_a = {0x2688B8D8, 0x1F4788A7, 0xE8DFF6ED, 0xA5818FE8, 0x1E64C6BF};
		static const bigint_t var_expected = {0xA99D89AC, 0x59DF6121, 0x9F798D2C, 0x0F1D9402, 0x204CAA49};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 406 ");
	}
	{
		static const bigint_t var_a = {0xDC28A70B, 0xEF2E06B9, 0xF8A1E5EB, 0x77A8F1AD, 0x0A81FA30};
		static const bigint_t var_expected = {0x6FFE8D49, 0xC587F52B, 0xB79275D5, 0x70DB8624, 0x13DB2EC0};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 407 ");
	}
	{
		static const bigint_t var_a = {0x9E7413A0, 0xB2392F43, 0x173EE74E, 0x0426FB81, 0x0FDBF8C1};
		static const bigint_t var_expected = {0xE3D63CFE, 0xCFAFE3F6, 0x7D503476, 0xCC93B797, 0x0D1589C5};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 408 ");
	}
	{
		static const bigint_t var_a = {0x3E16CF0C, 0x2B7E9277, 0xD86CDC7A, 0x789C7B05, 0x0FFE7F32};
		static const bigint_t var_expected = {0xD7610F74, 0x56B3A002, 0x5593D171, 0x9CE75213, 0x1B64D1E7};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 409 ");
	}
	{
		static const bigint_t var_a = {0xC525A18C, 0x8FBC71BA, 0xF02A76E2, 0xF10876DB, 0x0A987978};
		static const bigint_t var_expected = {0xDD4E2C3B, 0x567D92E7, 0x8545F444, 0x9A951065, 0x1D77D828};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 410 ");
	}
	{
		static const bigint_t var_a = {0x87D632A3, 0xBE266E98, 0x96E2EDAF, 0x39425227, 0x02C3F917};
		static const bigint_t var_expected = {0x09893B0F, 0x7611853C, 0x36E1BD8C, 0x66B2D90B, 0x075AFAA4};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 411 ");
	}
	{
		static const bigint_t var_a = {0xECDFDBBD, 0xADCEAAFD, 0xE324F103, 0x12B7C181, 0x19B3CF7D};
		static const bigint_t var_expected = {0xF58F5685, 0x0DC748F4, 0xDCB2ECFA, 0xE23A39E8, 0x1482F994};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 412 ");
	}
	{
		static const bigint_t var_a = {0x7154FCBB, 0x41549317, 0x3AE862CC, 0xD0FE7F10, 0x18F51A51};
		static const bigint_t var_expected = {0xC434FAE0, 0xE78DC94F, 0x771F1F70, 0x33852783, 0x1F6B8631};
		fp_sqr(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqr 413 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x2628292E, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 414 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 415 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x2628292D, 0x0F16AA50, 0x1CA5604F, 0xD7AB2DF3, 0x12009001};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 416 ");
	}
	{
		static const bigint_t var_a = {0x01D2C02B, 0x885D461F, 0x775ACE83, 0xB1E11A11, 0x0DDD27AB};
		static const bigint_t var_expected = {0xA7118943, 0xD3454D5F, 0xD852C790, 0xB09BBAFB, 0x18EF23D7};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 417 ");
	}
	{
		static const bigint_t var_a = {0xEAFEFFA4, 0xAC1C399C, 0xD870E4B7, 0x7E4AE264, 0x18926E48};
		static const bigint_t var_expected = {0x757F7FD2, 0xD60E1CCE, 0x6C38725B, 0x3F257132, 0x0C493724};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 418 ");
	}
	{
		static const bigint_t var_a = {0x318F9A7C, 0x8FD0EE4B, 0xA35E695D, 0x35B41157, 0x199DD27B};
		static const bigint_t var_expected = {0x98C7CD3E, 0xC7E87725, 0xD1AF34AE, 0x9ADA08AB, 0x0CCEE93D};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 419 ");
	}
	{
		static const bigint_t var_a = {0x3D8D0681, 0xA1614B4E, 0xD4DDB7AA, 0x64F5BB60, 0x052B7324};
		static const bigint_t var_expected = {0x44EEAC6E, 0x5FC74FF7, 0x87143C24, 0x0A260BA3, 0x14964994};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 420 ");
	}
	{
		static const bigint_t var_a = {0x705D9D3C, 0x72EBB8A8, 0x1054A9FC, 0xA45B0CB3, 0x1509D39E};
		static const bigint_t var_expected = {0x382ECE9E, 0x3975DC54, 0x882A54FE, 0x522D8659, 0x0A84E9CF};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 421 ");
	}
	{
		static const bigint_t var_a = {0xEC2C8DFF, 0x235E16AB, 0x3EA9EEA9, 0xA19E86C3, 0x0286B44D};
		static const bigint_t var_expected = {0x1C3E702D, 0xA0C5B5A6, 0xBBFA57A3, 0xA87A7154, 0x1343EA28};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 422 ");
	}
	{
		static const bigint_t var_a = {0xBBDF0899, 0x91AFEA92, 0xD9DD277A, 0xE8A3099E, 0x14F55867};
		static const bigint_t var_expected = {0x8417AD7A, 0x57EE9F99, 0x8993F40C, 0xCBFCB2C2, 0x1C7B3C35};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 423 ");
	}
	{
		static const bigint_t var_a = {0x95D60E4F, 0xACB52BC4, 0xB09AAD31, 0x78AEAC09, 0x0A2467A5};
		static const bigint_t var_expected = {0x71133055, 0xE5714032, 0xF4F2B6E7, 0x940283F7, 0x1712C3D4};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 424 ");
	}
	{
		static const bigint_t var_a = {0x967FB224, 0xF5B44450, 0x3BE95F00, 0x9962B526, 0x0647FF79};
		static const bigint_t var_expected = {0x4B3FD912, 0x7ADA2228, 0x1DF4AF80, 0xCCB15A93, 0x0323FFBC};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 425 ");
	}
	{
		static const bigint_t var_a = {0x0A2FAD81, 0xAB1D406D, 0xE851AC38, 0x45AD18B5, 0x13CE1DFB};
		static const bigint_t var_expected = {0xAB3FFFEE, 0x64A54A86, 0x10CE366B, 0x7A81BA4E, 0x1BE79EFF};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 426 ");
	}
	{
		static const bigint_t var_a = {0x8980A7DD, 0xD34576E2, 0x8DB90F7D, 0x804470A9, 0x1A40AE03};
		static const bigint_t var_expected = {0x6AE87D1C, 0xF8B965C1, 0xE381E80D, 0x97CD6647, 0x1F20E703};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 427 ");
	}
	{
		static const bigint_t var_a = {0x2D335521, 0xFCF925E7, 0xD164503A, 0x6AE3CC78, 0x214DD477};
		static const bigint_t var_expected = {0xBCC1D3BE, 0x8D933D43, 0x8557886C, 0x8D1D142F, 0x22A77A3D};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 428 ");
	}
	{
		static const bigint_t var_a = {0xF363AD27, 0x39F50097, 0x39DFF7D1, 0x9DE7899E, 0x23E41C6A};
		static const bigint_t var_expected = {0x1FD9FFC1, 0xAC112A9C, 0x39955C37, 0x269EF2C2, 0x23F29E37};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 429 ");
	}
	{
		static const bigint_t var_a = {0x80158070, 0x0AAF285A, 0xCCDD5C88, 0xC6BC4657, 0x121B00D4};
		static const bigint_t var_expected = {0x400AC038, 0x0557942D, 0xE66EAE44, 0x635E232B, 0x090D806A};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 430 ");
	}
	{
		static const bigint_t var_a = {0x4F098F02, 0xA41AA2C7, 0xF2B06895, 0x5C0DE838, 0x18BA710A};
		static const bigint_t var_expected = {0xA784C781, 0xD20D5163, 0x7958344A, 0x2E06F41C, 0x0C5D3885};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 431 ");
	}
	{
		static const bigint_t var_a = {0xF5AF29B4, 0x9EC6516E, 0xD7BD496E, 0xF7CE6772, 0x1FF9A6CA};
		static const bigint_t var_expected = {0x7AD794DA, 0x4F6328B7, 0x6BDEA4B7, 0x7BE733B9, 0x0FFCD365};
		fp_hlv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_hlv 432 ");
	}
	{
		static const bigint_t var_a = {0xAECDFF5F, 0x67715F4C, 0x53AEEDC5, 0x1B204013, 0x1896C75D};
		static const bigint_t var_exp = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xAECDFF5F, 0x67715F4C, 0x53AEEDC5, 0x1B204013, 0x1896C75D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 433 ");
	}
	{
		static const bigint_t var_a = {0xAECDFF5F, 0x67715F4C, 0x53AEEDC5, 0x1B204013, 0x1896C75D};
		static const bigint_t var_exp = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 434 ");
	}
	{
		static const bigint_t var_a = {0xC1EE45CB, 0xAFC17B3F, 0x6D1A1124, 0x0CFF45AB, 0x0A7FF280};
		static const bigint_t var_exp = {0xE8BD6EA6, 0x20B7788F, 0x31EAA6D8, 0xF0B9AB44, 0xED18F109};
		static const bigint_t var_expected = {0xB2880F72, 0x19A1BDAB, 0x5D688FEA, 0xB1838F49, 0x2334BBB4};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 435 ");
	}
	{
		static const bigint_t var_a = {0xBD84A927, 0x39D18F43, 0xDF021088, 0xD6001F2B, 0x1B6B7C67};
		static const bigint_t var_exp = {0x9914C116, 0x122F3242, 0x2A6FAE86, 0x254D3BCD, 0xA8416ABD};
		static const bigint_t var_expected = {0x997230CA, 0xF55090F3, 0xFBFE2544, 0x6DFD2A52, 0x111C9F1B};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 436 ");
	}
	{
		static const bigint_t var_a = {0x7417C51C, 0x140FE21E, 0xD8C4B0CD, 0xA3142FCB, 0x0CCDFD4A};
		static const bigint_t var_exp = {0xB08C61F7, 0x4E1C690D, 0x198AA4AC, 0x1813A4FE, 0xCB379DBF};
		static const bigint_t var_expected = {0x45B01152, 0x69C58479, 0x985AD522, 0xB27F5660, 0x240073CA};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 437 ");
	}
	{
		static const bigint_t var_a = {0x3434EBF7, 0x923D4248, 0xDFAE0AFF, 0xE3DA0EF6, 0x17589CCA};
		static const bigint_t var_exp = {0x6920CCA6, 0x8CF2DEBE, 0x96F90267, 0x819FDD58, 0x50DFE1CF};
		static const bigint_t var_expected = {0x0DE598CD, 0xE82F8689, 0xD8109CFF, 0x1BE01F58, 0x16CD2496};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 438 ");
	}
	{
		static const bigint_t var_a = {0xA1A8C7FE, 0x2676AA6C, 0x99748FB3, 0xD321D426, 0x010181CB};
		static const bigint_t var_exp = {0x8DEC9218, 0x207D69DC, 0x6BE16494, 0xC218807F, 0x63394E4A};
		static const bigint_t var_expected = {0xD8623087, 0x7F116064, 0xF2AD9A39, 0x7B10EF9C, 0x17CF475D};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 439 ");
	}
	{
		static const bigint_t var_a = {0x3F066326, 0x4656B0C4, 0xFE7DA45B, 0x1677B890, 0x00154C75};
		static const bigint_t var_exp = {0x8DF12AC1, 0x5F8715AA, 0x1256A461, 0xCEC420BD, 0x5D35294E};
		static const bigint_t var_expected = {0x5BB3EDB7, 0x8633FA83, 0x2E49B500, 0xEF0CA413, 0x198EABDA};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 440 ");
	}
	{
		static const bigint_t var_a = {0xA49BEDF9, 0x2D787B99, 0x06A83A22, 0x5705725D, 0x01B9A0A5};
		static const bigint_t var_exp = {0xD48665ED, 0x195E0582, 0xD5CEAB31, 0x700A4F57, 0x2D3A92BE};
		static const bigint_t var_expected = {0x914DA699, 0x76D8F974, 0x8A7519B0, 0xF3D0FCA8, 0x14CA0807};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 441 ");
	}
	{
		static const bigint_t var_a = {0xE9829235, 0xF22D63B6, 0x7F3C4906, 0x341F6CE7, 0x09CEF546};
		static const bigint_t var_exp = {0xBA0664E2, 0x2BE992E8, 0xDD740F4F, 0xCAFC0E06, 0x13D8CC94};
		static const bigint_t var_expected = {0x73B7E42A, 0x02548BFF, 0x0BCEEECF, 0x8D32F538, 0x06D831CB};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 442 ");
	}
	{
		static const bigint_t var_a = {0x95FD278F, 0xA013145A, 0xF1EDC0C5, 0xFDF70923, 0x0B023DBD};
		static const bigint_t var_exp = {0xCF5098A8, 0x7208795E, 0x773A6F09, 0x0D091F2E, 0xE0356E86};
		static const bigint_t var_expected = {0xEC2CA331, 0x0DEE4E1A, 0x6AFF5B2E, 0x86D324D3, 0x14542913};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 443 ");
	}
	{
		static const bigint_t var_a = {0x906A3A7A, 0x5558E26C, 0x57088CA3, 0x01F6491B, 0x0B0007E6};
		static const bigint_t var_exp = {0x50B10382, 0xA9CD247C, 0x5265BBA4, 0xB0920B19, 0x0F2AC811};
		static const bigint_t var_expected = {0x4E12AC49, 0xDC7DF0BD, 0x3970ACEC, 0xE4783D8A, 0x012A6740};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 444 ");
	}
	{
		static const bigint_t var_a = {0x42F707F9, 0x3F5FCF4D, 0xCC3367EC, 0xF1002C2D, 0x13FC9D03};
		static const bigint_t var_exp = {0xFF570686, 0xF12C7257, 0x870F09A8, 0xABC04702, 0x7757270D};
		static const bigint_t var_expected = {0x5884E4F4, 0x5F44B6A6, 0xB6AF4169, 0xE0643C9B, 0x0E650E1E};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 445 ");
	}
	{
		static const bigint_t var_a = {0x516B294F, 0xFEB66738, 0xFA33CE98, 0x5AF08B80, 0x198B439F};
		static const bigint_t var_exp = {0xC01DE216, 0x20603699, 0xAAE68448, 0x90866D91, 0x6966B7E9};
		static const bigint_t var_expected = {0x6213942B, 0x0E111FB2, 0x26C910AA, 0xD5D61093, 0x1731E70C};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 446 ");
	}
	{
		static const bigint_t var_a = {0x10B7E36C, 0x353FEE25, 0x7FE66377, 0x3E85C318, 0x02B9B4DB};
		static const bigint_t var_exp = {0xA0B7BC32, 0xFD8C9E25, 0x336DE8FF, 0x6F9EBF7B, 0x735E5E77};
		static const bigint_t var_expected = {0xE2AA03E4, 0x6555CF24, 0xF7A2B23D, 0xFABD130D, 0x2083055C};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 447 ");
	}
	{
		static const bigint_t var_a = {0xBA0BEADA, 0x549A209D, 0xDD5EE747, 0x700C9C46, 0x09A3E4BB};
		static const bigint_t var_exp = {0x33EFA6C0, 0x1AD55503, 0x010A1417, 0xE4C4CA36, 0x1E8A00E7};
		static const bigint_t var_expected = {0x631B7805, 0x36C4BECE, 0xF7823CB8, 0x70EBD227, 0x0CF6A7C3};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 448 ");
	}
	{
		static const bigint_t var_a = {0x2895FC89, 0x3A98586E, 0x2A7A9A78, 0x15ED2B99, 0x0B3D7721};
		static const bigint_t var_exp = {0x6EDBF16A, 0xEFDD999E, 0xC792E75B, 0xC9A614F5, 0x63FD5DFC};
		static const bigint_t var_expected = {0x92116E0B, 0x18B59895, 0x865F857A, 0xFE23F35C, 0x0A992FD5};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 449 ");
	}
	{
		static const bigint_t var_a = {0x53620085, 0xAE135382, 0x70CF5D94, 0xBC50190A, 0x0345FE7E};
		static const bigint_t var_exp = {0x68B2F801, 0x57AA3F2E, 0x9C898735, 0x60A0F74B, 0xAE20C591};
		static const bigint_t var_expected = {0x479F3185, 0x14CE3257, 0x4BF68E97, 0xB41C5CE1, 0x06188947};
		fp_exp(var_res, var_a, var_exp);
		assert_bi_equal(var_res, var_expected, "fp_exp 450 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 451 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 452 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 453 ");
	}
	{
		static const bigint_t var_a = {0xF50A8196, 0xC4B6E03B, 0x649537B0, 0xBF85A18C, 0x1CD0A6ED};
		static const bigint_t var_expected = {0x5745D0C5, 0x59767464, 0xD4B588ED, 0xEFD0BA59, 0x07307915};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 454 ");
	}
	{
		static const bigint_t var_a = {0x75324F5D, 0x32A4DDEC, 0x2A20B696, 0x2BE66CEB, 0x1250B8A3};
		static const bigint_t var_expected = {0xD71E02FE, 0xEB8876B3, 0x0F2A0A07, 0x836FEEFB, 0x11B06760};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 455 ");
	}
	{
		static const bigint_t var_a = {0xFD5D43F5, 0x4366DB2D, 0x3257ADF6, 0x914527F1, 0x1FB0F626};
		static const bigint_t var_expected = {0x4EF30E66, 0xDAC67972, 0x06F312A7, 0x1E1133F5, 0x045029DD};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 456 ");
	}
	{
		static const bigint_t var_a = {0xDEAB8F99, 0x03A7228A, 0x69B988D9, 0x09826A9E, 0x01382464};
		static const bigint_t var_expected = {0x6DA4C2C2, 0x1A863215, 0xCF9137C5, 0xA5D3F147, 0x22C8FB9F};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 457 ");
	}
	{
		static const bigint_t var_a = {0x0ECEB363, 0x7C689085, 0x05B3AC70, 0x53258CC2, 0x153EBA8A};
		static const bigint_t var_expected = {0x3D819EF8, 0xA1C4C41B, 0x3397142D, 0x5C30CF24, 0x0EC26579};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 458 ");
	}
	{
		static const bigint_t var_a = {0xB81DD70E, 0x335D3AA5, 0x8D451007, 0x0FD76396, 0x18F28E6D};
		static const bigint_t var_expected = {0x94327B4D, 0xEAD019FA, 0xAC05B096, 0x9F7EF84F, 0x0B0E9196};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 459 ");
	}
	{
		static const bigint_t var_a = {0xC6B33B0C, 0xDDE2F22D, 0x71D38F67, 0x57FEEDDF, 0x181E8A3E};
		static const bigint_t var_expected = {0x859D174F, 0x404A6272, 0xC7773136, 0x57576E06, 0x0BE295C5};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 460 ");
	}
	{
		static const bigint_t var_a = {0x4ED459B7, 0xCA682C15, 0x1B540452, 0x7C0060D7, 0x23FC8CEA};
		static const bigint_t var_expected = {0xFD7BF8A4, 0x53C5288A, 0x1DF6BC4B, 0x3355FB0F, 0x00049319};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 461 ");
	}
	{
		static const bigint_t var_a = {0x9948057C, 0x38CFF2FD, 0x40B85FE1, 0xA21B0557, 0x0AB8EFB2};
		static const bigint_t var_expected = {0xB3084CDF, 0xE55D61A2, 0xF89260BC, 0x0D3B568E, 0x19483051};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 462 ");
	}
	{
		static const bigint_t var_a = {0xF2275CBD, 0x365B709F, 0x39F70078, 0x45EC6406, 0x0BEDA3C8};
		static const bigint_t var_expected = {0x5A28F59E, 0xE7D1E400, 0xFF53C025, 0x6969F7DF, 0x18137C3B};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 463 ");
	}
	{
		static const bigint_t var_a = {0x6B3C87AA, 0xECA66BAE, 0xACF1A95C, 0x29E9087E, 0x1D891A01};
		static const bigint_t var_expected = {0xE113CAB1, 0x3186E8F1, 0x8C591741, 0x856D5367, 0x06780602};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 464 ");
	}
	{
		static const bigint_t var_a = {0x4E0C4B37, 0xC0E280F7, 0x6A382F2C, 0x573803EA, 0x0CD0FEFE};
		static const bigint_t var_expected = {0xFE440724, 0x5D4AD3A8, 0xCF129171, 0x581E57FB, 0x17302105};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 465 ");
	}
	{
		static const bigint_t var_a = {0x279C069F, 0xED005682, 0x0F64DE79, 0x9C37E70A, 0x07EDA703};
		static const bigint_t var_expected = {0x24B44BBC, 0x312CFE1E, 0x29E5E224, 0x131E74DC, 0x1C137900};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 466 ");
	}
	{
		static const bigint_t var_a = {0x4B94EDA8, 0x9187D1DB, 0xEF8649B8, 0x628AF630, 0x0F2C1AEC};
		static const bigint_t var_expected = {0x00BB64B3, 0x8CA582C5, 0x49C476E5, 0x4CCB65B5, 0x14D50517};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 467 ");
	}
	{
		static const bigint_t var_a = {0xFA983496, 0xC30958CE, 0x2C8E3783, 0x4138F38A, 0x0D4FE3E3};
		static const bigint_t var_expected = {0x51B81DC5, 0x5B23FBD1, 0x0CBC891A, 0x6E1D685C, 0x16B13C20};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 468 ");
	}
	{
		static const bigint_t var_a = {0x84C0FB6D, 0x430472E2, 0x4F558590, 0xE54C4B79, 0x01CA3CF0};
		static const bigint_t var_expected = {0xC78F56EE, 0xDB28E1BD, 0xE9F53B0D, 0xCA0A106C, 0x2236E312};
		fp_neg(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_neg 469 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 470 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 471 ");
	}
	{
		static const bigint_t var_a = {0x4C50525A, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		static const bigint_t var_expected = {0x4C505259, 0x1E2D54A0, 0x394AC09E, 0xAF565BE6, 0x24012003};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 472 ");
	}
	{
		static const bigint_t var_a = {0x598DCB1A, 0x40F0F4F7, 0x9C9D4E85, 0x97F5F364, 0x1DFE2C52};
		static const bigint_t var_expected = {0x66CB43D9, 0x63B4954E, 0xFFEFDC6C, 0x80958AE2, 0x17FB38A1};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 473 ");
	}
	{
		static const bigint_t var_a = {0x22DD014B, 0x115790D6, 0x98E5B858, 0x715D0D99, 0x007FF5E9};
		static const bigint_t var_expected = {0x45BA0296, 0x22AF21AC, 0x31CB70B0, 0xE2BA1B33, 0x00FFEBD2};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 474 ");
	}
	{
		static const bigint_t var_a = {0x064DF828, 0xC0263CF9, 0x075890D5, 0x9CAC0263, 0x15D2ADD2};
		static const bigint_t var_expected = {0xC04B9DF5, 0x621F2551, 0xD566610D, 0x8A01A8DF, 0x07A43BA1};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 475 ");
	}
	{
		static const bigint_t var_a = {0xE7605D80, 0xD2F5FBF9, 0xE511B7C5, 0x29762785, 0x0CDEC33A};
		static const bigint_t var_expected = {0xCEC0BB00, 0xA5EBF7F3, 0xCA236F8B, 0x52EC4F0B, 0x19BD8674};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 476 ");
	}
	{
		static const bigint_t var_a = {0x6C408CD1, 0x1933FF6D, 0xF905F0DB, 0xE7D8242B, 0x20184AC6};
		static const bigint_t var_expected = {0x8C30C747, 0x143AAA3A, 0xB8C12118, 0x2059EC71, 0x1C2F758A};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 477 ");
	}
	{
		static const bigint_t var_a = {0x77A9E60E, 0x24E816E5, 0x0A8C4A08, 0xA2C540D2, 0x13D25B0D};
		static const bigint_t var_expected = {0xA30379C1, 0x2BA2D92A, 0xDBCDD372, 0x963425BD, 0x03A39617};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 478 ");
	}
	{
		static const bigint_t var_a = {0x190E82D4, 0x70FFD932, 0x236B3378, 0x192FADC8, 0x0150CFF3};
		static const bigint_t var_expected = {0x321D05A8, 0xE1FFB264, 0x46D666F0, 0x325F5B90, 0x02A19FE6};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 479 ");
	}
	{
		static const bigint_t var_a = {0x359B2436, 0x5C016124, 0xB3599FEA, 0xF42CB435, 0x1E699478};
		static const bigint_t var_expected = {0x1EE5F611, 0x99D56DA8, 0x2D687F36, 0x39030C85, 0x18D208EE};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 480 ");
	}
	{
		static const bigint_t var_a = {0xD27D4FF4, 0xFE5AB030, 0x264954B6, 0x00F231CF, 0x0B2C7318};
		static const bigint_t var_expected = {0xA4FA9FE8, 0xFCB56061, 0x4C92A96D, 0x01E4639E, 0x1658E630};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 481 ");
	}
	{
		static const bigint_t var_a = {0x35BD972D, 0x50B109FC, 0xC4DCAAEB, 0xA68BA802, 0x202E8A81};
		static const bigint_t var_expected = {0x1F2ADBFF, 0x8334BF58, 0x506E9538, 0x9DC0F41F, 0x1C5BF4FF};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 482 ");
	}
	{
		static const bigint_t var_a = {0x15476CA7, 0x56C5213F, 0xC2907E25, 0xF2F3704B, 0x0A51CD87};
		static const bigint_t var_expected = {0x2A8ED94E, 0xAD8A427E, 0x8520FC4A, 0xE5E6E097, 0x14A39B0F};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 483 ");
	}
	{
		static const bigint_t var_a = {0xB739FAE0, 0x8D39F9D5, 0x10FDEF48, 0x74175560, 0x039166D5};
		static const bigint_t var_expected = {0x6E73F5C0, 0x1A73F3AB, 0x21FBDE91, 0xE82EAAC0, 0x0722CDAA};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 484 ");
	}
	{
		static const bigint_t var_a = {0x86E1C725, 0x3DE4413D, 0xB2AF7335, 0x9F56764E, 0x05635A74};
		static const bigint_t var_expected = {0x0DC38E4A, 0x7BC8827B, 0x655EE66A, 0x3EACEC9D, 0x0AC6B4E9};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 485 ");
	}
	{
		static const bigint_t var_a = {0x5C936776, 0x15626BDA, 0x96055DF4, 0x05BF8565, 0x12DB48B1};
		static const bigint_t var_expected = {0x6CD67C91, 0x0C978314, 0xF2BFFB4A, 0x5C28AEE4, 0x01B5715E};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 486 ");
	}
	{
		static const bigint_t var_a = {0xB6098511, 0xA21F0836, 0x6B93ED1A, 0x43791A85, 0x221BAC1F};
		static const bigint_t var_expected = {0x1FC2B7C7, 0x2610BBCD, 0x9DDD1997, 0xD79BD924, 0x2036383A};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 487 ");
	}
	{
		static const bigint_t var_a = {0x503EF336, 0x755A6213, 0x7EDC6670, 0x96AB0EE3, 0x01DB2A2A};
		static const bigint_t var_expected = {0xA07DE66C, 0xEAB4C426, 0xFDB8CCE0, 0x2D561DC6, 0x03B65455};
		fp_dbl(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_dbl 488 ");
	}
	{
		static const bigint_t var_a = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		static const bigint_t var_expected = {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 489 ");
	}
	{
		static const bigint_t var_a = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		static const bigint_t var_expected = {0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 490 ");
	}
	{
		static const bigint_t var_a = {0x8924F3DC, 0x1FCF1EDD, 0x67BD8C3C, 0xACFEC747, 0x1C4D357A};
		static const bigint_t var_expected = {0xE7E49783, 0xD590541A, 0x7B343853, 0x27305DBA, 0x230A9664};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 491 ");
	}
	{
		static const bigint_t var_a = {0x4A8621D7, 0x13AC9F20, 0x3A7E05EC, 0xDB1B1D17, 0x0F06DDD4};
		static const bigint_t var_expected = {0xDF36A480, 0x9145B7B4, 0x2818F5E4, 0xEEA9001E, 0x1F57EEE8};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 492 ");
	}
	{
		static const bigint_t var_a = {0x777EDA96, 0xC03CB33E, 0xA50226AB, 0xFA91E2B6, 0x1F95A39D};
		static const bigint_t var_expected = {0xE0D8C7BE, 0x3F4A1706, 0x7925C55B, 0xA661279C, 0x0D117EF5};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 493 ");
	}
	{
		static const bigint_t var_a = {0x6051D0C8, 0x2475DD2C, 0x253B1D86, 0x753AF678, 0x16FBC3E4};
		static const bigint_t var_expected = {0x02481E39, 0xD9545001, 0x49EB90E8, 0xDF4A5A2F, 0x0F5419D0};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 494 ");
	}
	{
		static const bigint_t var_a = {0x57EDA57E, 0x24A7C1BA, 0xA95E1363, 0x299FDF82, 0x040A1750};
		static const bigint_t var_expected = {0x10070008, 0xB3ACBFCB, 0xB3ABB8FE, 0x8899F41E, 0x1FA3B3B5};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 495 ");
	}
	{
		static const bigint_t var_a = {0xCA4BE5C1, 0x24A315B3, 0x32C07009, 0x75D0E12A, 0x049EB42A};
		static const bigint_t var_expected = {0xF12445A4, 0xCFA583E1, 0x2DB408F5, 0x1A1F738D, 0x019044B1};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 496 ");
	}
	{
		static const bigint_t var_a = {0x94CC60C3, 0x68CF365E, 0xADDFE780, 0x9D548711, 0x20B0F119};
		static const bigint_t var_expected = {0x77B89666, 0x47163688, 0xE25DFF45, 0x41F101AF, 0x1CE105FB};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 497 ");
	}
	{
		static const bigint_t var_a = {0xD13B6668, 0x205428A6, 0x325270D9, 0xAABC1604, 0x1DF593FD};
		static const bigint_t var_expected = {0xEE99CE3C, 0x3494D89D, 0x0ED60EE8, 0xF050C64B, 0x22C769C5};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 498 ");
	}
	{
		static const bigint_t var_a = {0x0BC99CBD, 0xC9906C68, 0x7CCBB6EB, 0x88E6E95F, 0x147B2B46};
		static const bigint_t var_expected = {0x0408B3C1, 0x57E4054B, 0x69DD9C8E, 0xB9177978, 0x22820886};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 499 ");
	}
	{
		static const bigint_t var_a = {0x56604053, 0xEEC66F3C, 0x51F90A4E, 0x27F71AA9, 0x1B5A7E2E};
		static const bigint_t var_expected = {0xFFE6FFF6, 0xBF453D09, 0x56C7A1EF, 0x5546A274, 0x21CC5F44};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 500 ");
	}
	{
		static const bigint_t var_a = {0x0A6A6559, 0x84FB5962, 0x723F64D6, 0x390C209B, 0x1615831B};
		static const bigint_t var_expected = {0xDFBD54FD, 0xA6A72ED1, 0x82D32F5A, 0xDBA66FB0, 0x1A4A8CB6};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 501 ");
	}
	{
		static const bigint_t var_a = {0x929DCCC4, 0xD68F9FED, 0x9F52A749, 0xABD7E43A, 0x18C1E804};
		static const bigint_t var_expected = {0x5A0833BB, 0x7EFA44A7, 0x9C336487, 0x18E9359D, 0x1A4461A5};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 502 ");
	}
	{
		static const bigint_t var_a = {0x2071164C, 0xB745E6A0, 0x14CA4E67, 0x2A90E2DD, 0x11012C37};
		static const bigint_t var_expected = {0x811E5108, 0x3CCE22C2, 0x93DC07BC, 0x93D1B205, 0x200EE4A2};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 503 ");
	}
	{
		static const bigint_t var_a = {0xA14F1E36, 0x81FB6674, 0x05959834, 0x677E4600, 0x0D55EA60};
		static const bigint_t var_expected = {0x7B4001CC, 0x56730742, 0x8A814C09, 0x695901D5, 0x11A08099};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 504 ");
	}
	{
		static const bigint_t var_a = {0x7C866D64, 0x87572300, 0xF49A054F, 0xE66E44D4, 0x04341924};
		static const bigint_t var_expected = {0x9D63B29E, 0xEF159810, 0x57E2E30B, 0x12A122AC, 0x16200DE3};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 505 ");
	}
	{
		static const bigint_t var_a = {0x82BB23E4, 0x4D1F960C, 0x3014BD8E, 0x5E7EBE8F, 0x18C0052B};
		static const bigint_t var_expected = {0x39DE5D70, 0x579D8A51, 0xEE31C142, 0xBD86014E, 0x1C421698};
		fp_inv(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv 506 ");
	}
	{
		static const bigint_t var_a = {0x7B02D1B2, 0xB22F9C82, 0x7C4C4549, 0x03CCB6A8, 0x2025DFC6};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 507 ");
	}
	{
		static const bigint_t var_a = {0xE4E1C096, 0xC1B81FB8, 0xAF6BD411, 0x6CC29B8D, 0x17E5E975};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 508 ");
	}
	{
		static const bigint_t var_a = {0xB3FF9527, 0xDED1CE39, 0xF57ACE08, 0xD457D409, 0x0CD9DCC8};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 509 ");
	}
	{
		static const bigint_t var_a = {0x5A612063, 0x9BA671B4, 0x92039D49, 0x8036DA97, 0x21D2D808};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 510 ");
	}
	{
		static const bigint_t var_a = {0x12DD16D3, 0x6E851D0F, 0xA72B7E34, 0xEBA33D76, 0x18DF7396};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 511 ");
	}
	{
		static const bigint_t var_a = {0x246D6241, 0x6AA36F2B, 0x3DADE679, 0x0E8DC405, 0x09A00083};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 512 ");
	}
	{
		static const bigint_t var_a = {0x2AEECFC0, 0xF4472E7E, 0x6EA6E7B0, 0x3D6EDF73, 0x153ECBBA};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 513 ");
	}
	{
		static const bigint_t var_a = {0xBE88670A, 0xBEA0971A, 0xBD787F91, 0x65289626, 0x07B9DCDE};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 514 ");
	}
	{
		static const bigint_t var_a = {0xA19ED67E, 0x3BDF6BEE, 0xC149195D, 0xA1AFE684, 0x069A8EFD};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 515 ");
	}
	{
		static const bigint_t var_a = {0xC1C3E0CD, 0xE18A2A50, 0x7B428693, 0x207B04DB, 0x1B9FA4C4};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 516 ");
	}
	{
		static const bigint_t var_a = {0x0911B22F, 0x9BA5A6D9, 0xBDFAF3C9, 0x808912D2, 0x10F15A9C};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 517 ");
	}
	{
		static const bigint_t var_a = {0x58993438, 0x8EB224A6, 0x194CB0D3, 0x52CAE31F, 0x06483D58};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 518 ");
	}
	{
		static const bigint_t var_a = {0xDD6CD379, 0xBD20DD0A, 0xD29D8F4B, 0x34F20777, 0x0604EF84};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 519 ");
	}
	{
		static const bigint_t var_a = {0x5CE1B656, 0xF188D260, 0x1E426FE6, 0xBF84F2DF, 0x011B09AA};
		assert_true(fp_legendre(var_a) == 1, "fp_legendre 520 ");
	}
	{
		static const bigint_t var_a = {0x69036F5B, 0xBAB30D96, 0xB14AF939, 0x9FE3B5B7, 0x05B715B0};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 521 ");
	}
	{
		static const bigint_t var_a = {0x980A4070, 0xA3CC1F9C, 0x339B5513, 0xB0074FAB, 0x14F6E67B};
		assert_true(fp_legendre(var_a) == -1, "fp_legendre 522 ");
	}
	{
		static const bigint_t var_a = {0x18E0A6E4, 0xF5318F55, 0x3844827F, 0x2827DA4B, 0x1718B2FB};
		static const bigint_t var_expected = {0x3CA2FED0, 0xDE9097F4, 0xF18B410B, 0x1218031C, 0x0A0F4004};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 523 ");
	}
	{
		static const bigint_t var_a = {0x5AB2BA60, 0x5D8A1E4D, 0xEE60BDF4, 0x83C2DA19, 0x11777B20};
		static const bigint_t var_expected = {0x9D1956A6, 0x281762BA, 0xA9EEF1EE, 0x275784C2, 0x203796AA};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 524 ");
	}
	{
		static const bigint_t var_a = {0x04792FBC, 0x81CCA332, 0x82A13453, 0xE1215567, 0x193192BB};
		static const bigint_t var_expected = {0x0F8C150B, 0x53B86EA5, 0x0076C0B8, 0x2D74A409, 0x0AE14F9E};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 525 ");
	}
	{
		static const bigint_t var_a = {0x9C97C6DA, 0xC0881DE9, 0x3F9A71D8, 0xB393AABE, 0x0E568A4E};
		static const bigint_t var_expected = {0xC9575594, 0xF1A92C7B, 0x83E4FEF3, 0xB16A2F01, 0x195C78D5};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 526 ");
	}
	{
		static const bigint_t var_a = {0xB8F9CD8C, 0x4B591F19, 0xFA372D8A, 0xB436D848, 0x0D693438};
		static const bigint_t var_expected = {0x0796E6D8, 0xD8FAD61A, 0x582AA204, 0xE353A219, 0x1AEC0A4C};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 527 ");
	}
	{
		static const bigint_t var_a = {0xA9C2ED0D, 0x0D0886B1, 0x7BFD71E7, 0xE3504B86, 0x15C382C7};
		static const bigint_t var_expected = {0x429E1CFE, 0xB0EB8455, 0xAC1C0CBB, 0xB997DD9B, 0x0FAE2935};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 528 ");
	}
	{
		static const bigint_t var_a = {0x9B576100, 0xE10961B1, 0x059E1D01, 0xC8CE255C, 0x14DF6D3D};
		static const bigint_t var_expected = {0xD15D55E2, 0x766D1C32, 0x546EAAE7, 0xDF93CCE6, 0x05D4A50A};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 529 ");
	}
	{
		static const bigint_t var_a = {0x6DA6B4C0, 0xFDB7A3E0, 0xE1404A96, 0x5AFD044C, 0x04D33AB9};
		static const bigint_t var_expected = {0x6F4E1BD9, 0x380C5909, 0x8207EF4D, 0x4B0B77E1, 0x0EC577F8};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 530 ");
	}
	{
		static const bigint_t var_a = {0x64034B19, 0x8AF4CB00, 0x13EB4D94, 0x4A3DEE41, 0x052ED4A4};
		static const bigint_t var_expected = {0x064F2A30, 0x9EE1BC6C, 0xFDDE13FB, 0x5AEAF155, 0x0EDD04BE};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 531 ");
	}
	{
		static const bigint_t var_a = {0x82DBD58B, 0xB603F597, 0x5079B0D1, 0xA5C14B14, 0x045668D6};
		static const bigint_t var_expected = {0x71FC6847, 0xF49A4931, 0x75C00069, 0x95BC78B1, 0x0101C490};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 532 ");
	}
	{
		static const bigint_t var_a = {0x1E1973CE, 0x037BA497, 0xEC533D3F, 0xF496A217, 0x034F9743};
		static const bigint_t var_expected = {0xD18DEBA1, 0x0B94DD82, 0x754C6868, 0x10271604, 0x06EAA7E6};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 533 ");
	}
	{
		static const bigint_t var_a = {0x01E6B523, 0x70F2AEFF, 0x168CEC50, 0x3C3827C0, 0x02A188E8};
		static const bigint_t var_expected = {0xED435FF0, 0x18692798, 0x093D3349, 0xFD68EED5, 0x01248D91};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 534 ");
	}
	{
		static const bigint_t var_a = {0xFE5DDCF8, 0x9B8CE801, 0x5D122C57, 0xD69D1A3C, 0x09287359};
		static const bigint_t var_expected = {0x5AE1E03B, 0xEEE10D45, 0xD509878B, 0x7493A867, 0x212BD698};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 535 ");
	}
	{
		static const bigint_t var_a = {0xE04D6187, 0x44CA9EFD, 0x45A2887F, 0xC90278D1, 0x046FECA3};
		static const bigint_t var_expected = {0xC4A7602A, 0x01CF7DB4, 0x5DCA5E7D, 0x9C73D0D4, 0x0B90CE17};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 536 ");
	}
	{
		static const bigint_t var_a = {0xA5552DBA, 0xA16F4BD5, 0x52846535, 0xD22E10B0, 0x211B6928};
		static const bigint_t var_expected = {0x4B065C17, 0xF8D232F0, 0x259C6E8D, 0x8650E2FE, 0x0CE3B48C};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 537 ");
	}
	{
		static const bigint_t var_a = {0xF7C6210F, 0x5715987C, 0x4BAC5786, 0x36C26C05, 0x1916F6ED};
		static const bigint_t var_expected = {0x581425AB, 0x12EC7F7A, 0xA9458B11, 0xC6B99DC1, 0x206B2813};
		fp_sqrt(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_sqrt 538 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 247 ");
	}
	{
		static const bigint_t var_a = {0x7A5035A4, 0x9E2B6B9F, 0x394A609C, 0xAF565BE6, 0x24012003, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x7A5035A4, 0x9E2B6B9F, 0x394A609C, 0xAF565BE6, 0x24012003, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 248 ");
	}
	{
		static const bigint_t var_a = {0xCC584E6A, 0x7319C625, 0xBC7AA9A4, 0xAFAD9114, 0x0172CD94, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xD8C0B688, 0x53E2C59B, 0x967215B3, 0x9A9D6FBF, 0x1EB0997A, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 249 ");
	}
	{
		static const bigint_t var_a = {0x459F11B6, 0x80749E61, 0x2EB815C3, 0x31EC4A55, 0x09E529BE, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xED9C1F7D, 0x9CA65381, 0xF607200C, 0xE6EFDB3C, 0x1593498D, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 250 ");
	}
	{
		static const bigint_t var_a = {0xCC263413, 0xF2434BC3, 0x20D9727A, 0x94EB5411, 0x01659F13, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFE45A49E, 0xE86917EF, 0xCD0A3F43, 0x8566492C, 0x1F4FD3EA, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 251 ");
	}
	{
		static const bigint_t var_a = {0x5E981DCF, 0xF3A08A88, 0xFB9F2D3B, 0x9222E4A6, 0x13F5EDC4, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x9236722E, 0xEFE47A08, 0x92F79812, 0x6C37FD64, 0x1A943A1C, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 252 ");
	}
	{
		static const bigint_t var_a = {0x4828FBDD, 0x842FF304, 0xC7E0E487, 0x5C1CD9BA, 0x0D7BAA76, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x0F7F1652, 0x03C02215, 0xC1AA8E8A, 0x1CC885C1, 0x09E43F1A, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 253 ");
	}
	{
		static const bigint_t var_a = {0xDF97A55E, 0x0D65F3E5, 0x15289256, 0xB3836AAD, 0x1F1C8412, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x15ADFBFF, 0x17A502B3, 0x94EAB5D7, 0xF650E341, 0x0CAF846B, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 254 ");
	}
	{
		static const bigint_t var_a = {0xBC2C33D1, 0x11D762A4, 0x9B104600, 0x3F04D6CD, 0x1AB9EADC, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x70B33951, 0xF47AC544, 0xBBC7548F, 0xA5AE050C, 0x1E3E6782, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 255 ");
	}
	{
		static const bigint_t var_a = {0x547CB8FE, 0x7ED579AC, 0xE4989049, 0xB94F9297, 0x04FCE4E5, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x83E1C898, 0x2F3F2910, 0xC591B1EA, 0x42270D03, 0x1783B749, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 256 ");
	}
	{
		static const bigint_t var_a = {0x17F0921F, 0xEC479A27, 0xDFD0FD54, 0x1BFFF0EF, 0x20B05652, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xD31AE753, 0xD11DFE06, 0x005BB7CB, 0xA8A35F23, 0x1D5D66F7, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 257 ");
	}
	{
		static const bigint_t var_a = {0x7BD9B24A, 0x7BD20F44, 0x13EA89E6, 0x9183A6BF, 0x05AC029E, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x64E71D7B, 0x01446FCD, 0x5DA57924, 0xD99D701D, 0x1040AC50, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 258 ");
	}
	{
		static const bigint_t var_a = {0x64A458A3, 0x0738F4D2, 0x849AA2C2, 0xDADC5278, 0x0C23382D, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x6CCA3D5E, 0x0857CD63, 0x0B653905, 0x05454476, 0x19AF0BCD, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 259 ");
	}
	{
		static const bigint_t var_a = {0x44821ABC, 0xC4AF68F0, 0xAFFBC57C, 0xAC55A4CB, 0x0E4B1E8A, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFC0B1518, 0xA92F4DDC, 0xF482FF58, 0x1AA6A788, 0x06654A69, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 260 ");
	}
	{
		static const bigint_t var_a = {0xC1EA8184, 0xB215176B, 0x70BF372B, 0x537D1EB0, 0x21C3BDD4, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x80CC40D3, 0x6F0791E0, 0xDF165B8F, 0x24F03DC5, 0x035A8221, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 261 ");
	}
	{
		static const bigint_t var_a = {0x71066E10, 0xEF37D20B, 0x7161EE6F, 0x11EC1768, 0x040B45EB, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x5C1EF97A, 0x8AFE188D, 0x45D08276, 0x6BB724B5, 0x1267D4C7, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 262 ");
	}
	{
		static const bigint_t var_a = {0x628F180D, 0xED7EE45C, 0x942E9DD8, 0x4F2273E7, 0x228808CC, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xE1F5012F, 0x5FABBAAF, 0x7AE4EDC2, 0x3B192749, 0x1C49F5A0, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 263 ");
	}
	{
		static const bigint_t var_a = {0xE26A268C, 0xCA2907E1, 0x036E104F, 0xE3AEF91B, 0x06A66957, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x6E7E6750, 0x2B60F75A, 0xCB0D304D, 0x6791AACD, 0x0552DF24, 0x00000000, 0x00000000, 0x00000000};
		fp_inv_n(var_res, var_a);
		assert_bi_equal(var_res, var_expected, "fp_inv_n 264 ");
	}
#endif
#endif

	return 0;
}
