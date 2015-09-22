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

#if (BNCURVE == BN256)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp2 var_a = { { {0xF45CCB9B, 0xAECD5BDF, 0xDA5E363C, 0x564FC390, 0x0ECFAE9B, 0x3A265E23, 0x92AD6F22, 0x11AFBD6C},
	{0x71EAFF4E, 0xAABC31FA, 0xB600E61C, 0x9E130727, 0x0E34699F, 0xC61D98C7, 0x38531397, 0x57A5AF40} } ,
	 { {0xC63E748B, 0xE33D20DE, 0xBB01B226, 0x15CC07E4, 0xC0AD8F9B, 0xB15154B2, 0xA0647C7A, 0x0D7C7075},
	{0x72A277A1, 0x2C311A02, 0x5EE30515, 0x03C278B2, 0xF9E0E036, 0xBF0C083D, 0x263C98D6, 0x3A86E1CB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 502 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 503 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 504 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 505 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 506 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 507 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 508 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 509 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 510 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 511 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4CB8953B, 0xDD399BA1, 0xA7C760CE, 0xCC094E73, 0x7EC24593, 0xE7E2692E, 0xB9E550D0, 0xB7233F26},
	{0x96E04161, 0x568DC416, 0x36537FB8, 0xC91847C3, 0x8E6DEA9C, 0x03B62C70, 0x1C2C8FDA, 0x23B74E26} } ,
	 { {0x4DB7D04A, 0x767B4BDC, 0x11B0EA68, 0x7F42F04E, 0xAF95BD77, 0x1FEACD1A, 0xE947E112, 0xABB5308E},
	{0x5D9C254F, 0x252693B9, 0x29719C59, 0xB4A4B43D, 0x31A2A977, 0x0FA9C870, 0x88EA288F, 0x29FC39D9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 512 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 513 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 514 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 515 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 516 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 517 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 518 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 519 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 520 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 521 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6E20C831, 0xC7764433, 0xD4636D7B, 0x5E7C69A5, 0xA93BD114, 0xE1BB736A, 0x3D1017E7, 0x09A79532},
	{0x917BCF17, 0xCD34E758, 0x04267F54, 0x63E93B5C, 0x27754B0E, 0x7B65F6AB, 0x192E7131, 0x783D0083} } ,
	 { {0x934B6552, 0x27D8B2B2, 0x0E7DE671, 0xDBAB3668, 0x00888CF7, 0xF8E0E061, 0x03212B29, 0x32F7B900},
	{0x93886765, 0xCB6ACD63, 0x08E8228C, 0x2D621B80, 0xA90DABE9, 0x3B41DC43, 0xF897DA86, 0x5F6A35CE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 522 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 523 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 524 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 525 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 526 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 527 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 528 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 529 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 530 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 531 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x81272674, 0x32261192, 0x47DF3321, 0x94B18164, 0x367A9212, 0x7145C662, 0x886A5B77, 0x0E2C3E26},
	{0x8A6A6DB1, 0xD7C5EA39, 0x07BADECE, 0xF75805F5, 0x81D7A5A0, 0x7522B2EC, 0x95DBA564, 0x5B63398A} } ,
	 { {0xC2671E0B, 0xBDF75B4E, 0x9BDE9E27, 0xB2C4FE65, 0x5CFEEBF5, 0x85AD47DE, 0x5857DDF9, 0xABC40865},
	{0x7AD74485, 0xEA740F93, 0x3D9FC4D7, 0xD09BB11F, 0x62628606, 0x912A14D7, 0x5CF22960, 0x6EA74E9F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 532 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 533 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 534 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 535 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 536 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 537 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 538 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 539 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 540 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 541 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x71EC1AB8, 0xE6496B91, 0x92E9D311, 0x1BBD1C65, 0x77787B8B, 0xD31B0172, 0x81452211, 0x437039EA},
	{0x45E4BB49, 0x3D68BFB3, 0x536C325B, 0xF88D6F21, 0xEFB2D49E, 0x3E4720AA, 0xB9EBF7CE, 0x1D642AB5} } ,
	 { {0x00AC997D, 0x01021200, 0x9E5EC621, 0x8B2DED34, 0x6B6691AB, 0x0F0BF212, 0x4F268B12, 0x1E461497},
	{0x9A32844A, 0x478CB087, 0x83EE93FB, 0x378DB828, 0x58FE8BB2, 0x55A26C24, 0x5C59DA23, 0x18E804AD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 542 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 543 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 544 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 545 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 546 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 547 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 548 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 549 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 550 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 551 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x696909FB, 0xAA8BD751, 0x9E56D6B3, 0x7B6EE8C6, 0x125E9B00, 0x51591996, 0x908364BB, 0xAFAD3B6A},
	{0xB2596C17, 0xC514EE7E, 0x78960272, 0x1445A4B0, 0xC34166B6, 0x13122D47, 0x6FC7B59B, 0x38DA1C59} } ,
	 { {0x76ECCF26, 0xB9A27701, 0x029BE27F, 0xEF6A69DE, 0xD52102ED, 0xDDF8F6E6, 0x519D515A, 0x9247F01C},
	{0x1CCBC5DE, 0xAC0D42C4, 0xC24865EF, 0xEBC380BC, 0x33D0DC9F, 0xCF48D2DB, 0x6161447B, 0x6671C600} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 552 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 553 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 554 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 555 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 556 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 557 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 558 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 559 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 560 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 561 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x68474C3A, 0x484EFD7D, 0xD2A6E7CB, 0x0449CFE4, 0xB59E1494, 0x40406F12, 0x5E832CDC, 0x2D86A605},
	{0xF792B032, 0x38EAB8F2, 0x603243BD, 0xD480D5DA, 0xA369B487, 0x3EC5CAE8, 0x1DEDA8BA, 0xB45C3AFF} } ,
	 { {0x4C31BF69, 0xAE0919EB, 0xAC4566D4, 0x65E5DF37, 0x42869D35, 0x36BA86BE, 0xC59F51DF, 0x1039EF45},
	{0x2886A1D1, 0xE0596B24, 0xE2B4089F, 0x73319846, 0x9B3A3EA5, 0x4782AF52, 0xD1F2EA1B, 0x5FACF030} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 562 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 563 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 564 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 565 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 566 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 567 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 568 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 569 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 570 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 571 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1F9A64B3, 0x86FE9B53, 0x6DB52727, 0x8A2E7DA9, 0x56D10EFD, 0xD6F5DBE4, 0x524E2EFB, 0xADCD6150},
	{0x76B99AE0, 0x5E2DED99, 0x48E4374D, 0x9A7F353B, 0x90C5AE6E, 0x10A7ADAB, 0xABF04545, 0x267F6EA2} } ,
	 { {0xA9B6141E, 0xA8EA7D9B, 0x8624CBA4, 0x76E9035B, 0x59DDA6FF, 0x64D6DCF4, 0x13E529E9, 0x9F2EC482},
	{0xE6FC9012, 0xABD53BD4, 0xCCCDA393, 0x582B4CFB, 0x3714644D, 0x05771E8A, 0x164A35EF, 0x0C2632DB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 572 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 573 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 574 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 575 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 576 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 577 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 578 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 579 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 580 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 581 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8F724AF4, 0x2E0592C7, 0xD52A8F75, 0x5B67AACD, 0xA255B50C, 0x694316B6, 0x15E8AD25, 0x086CD31C},
	{0xBC2B91E3, 0xFFF3661F, 0xED47A1B8, 0x001B5F16, 0x85075604, 0xCCE1C6B8, 0xC11738D5, 0x50346453} } ,
	 { {0xB7ECD6BB, 0x707D3B0F, 0x7711ACFE, 0xAAA71167, 0xC3644FE9, 0xAE183237, 0xA4F870D0, 0x48E0A476},
	{0x7E7CD927, 0xD4E97C58, 0x68C20B52, 0x226B2BBF, 0xB0A73AD3, 0x51131B36, 0x98F7289F, 0x748FECF7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 582 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 583 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 584 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 585 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 586 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 587 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 588 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 589 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 590 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 591 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x44C7D4F0, 0x070B5C1D, 0xC9A22265, 0x13684D56, 0x9404AEF5, 0x3CB61C7C, 0x4DA5F85A, 0x00404D6C},
	{0xF0D0E6D3, 0xE468BB47, 0x38161EA5, 0x8F7EA2A3, 0x2C745EEB, 0xBA0386CB, 0xC8DC2910, 0x397FEB1D} } ,
	 { {0x9C770FA4, 0xCC7D06AA, 0x67FADEA1, 0x8834100B, 0x294EC026, 0x5C90AE40, 0xDE392F1B, 0x12AA6B41},
	{0x17067622, 0x25030428, 0x9C551FEE, 0x580E88F7, 0xAEB3300B, 0x7307B545, 0xBDDF2308, 0xA0BD9686} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 592 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 593 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 594 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 595 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 596 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 597 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 598 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 599 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 600 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 601 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6496DEC1, 0xD94DF525, 0x30552F24, 0x3A77FB0F, 0xD6C9F1C8, 0x97BFD9F8, 0x648F0DEF, 0x9EB798BD},
	{0xD71844E2, 0xD4CC0A82, 0x3C2503E5, 0xBB280801, 0xD7E1F9A0, 0x27FF8B2A, 0xE5EFFEFB, 0x3072DB91} } ,
	 { {0x812F7506, 0x862BC570, 0x3FE18E3F, 0x99881359, 0x30BF24C1, 0xB6905B77, 0x2CDC585E, 0x068CB982},
	{0xDA4E01CF, 0x65920456, 0x52DE2053, 0x8296F9C3, 0xD96A81B9, 0xB3C7416C, 0xEF3A960F, 0x98A91E13} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 602 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 603 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 604 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 605 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 606 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 607 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 608 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 609 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 610 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 611 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB5E67149, 0x6DA16A20, 0x1E15E59A, 0x44ADAAB7, 0xBAA3568B, 0xC6B49677, 0x816498BE, 0x30D0981C},
	{0xC0D41A1F, 0x961C8447, 0x5EBA97F1, 0x4640AFF9, 0x2C245380, 0x4D0A26FF, 0x45CE5AC4, 0x6A960F32} } ,
	 { {0x8E2016E4, 0x644AA1B4, 0xE6DB554E, 0x64807E62, 0x83D1B322, 0x04B115EA, 0xF3E64764, 0x2B2A1896},
	{0xEFBF9FA3, 0x5D0C62CD, 0x714710C1, 0x2AE9DE20, 0xD9737ED5, 0x598C8E2B, 0x9695BC5F, 0x63704B94} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 612 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 613 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 614 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 615 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 616 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 617 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 618 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 619 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 620 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 621 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2674BCA0, 0x89269019, 0x24346E95, 0xDF3D28A9, 0x912741AE, 0x0A4ED9DE, 0x8D145C8B, 0x316963B1},
	{0x4B59C80B, 0xF4D64A24, 0x356E4B5D, 0x6BD769DB, 0x81526BA9, 0x867F10A9, 0x4D746517, 0x08087453} } ,
	 { {0xEA8A01AF, 0x30221AAF, 0x451457F3, 0x72DC441D, 0xC992BA6F, 0x8ECC7E2F, 0x9D353618, 0x8BCC1B88},
	{0x7E76E9EA, 0xD3E9019D, 0xE10F05FF, 0xD54FE072, 0x55E9D939, 0xAD5112DF, 0x18D05988, 0x0A531F23} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 622 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 623 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 624 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 625 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 626 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 627 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 628 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 629 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 630 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 631 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDBDB43EE, 0xF5A9E629, 0x29262CC5, 0x9418797F, 0x03207D33, 0xA8CB1608, 0xEF24E0ED, 0xAADCD179},
	{0xC5E1E3D1, 0xB5FFCE7B, 0x24AFD33A, 0xECDF2BBA, 0x7B286F3B, 0x0C1D30E3, 0x250A0F24, 0x40989B11} } ,
	 { {0xBFE2F106, 0xB07E168F, 0x42C85880, 0x4A412D12, 0xA904A62C, 0x9C02F0A5, 0x9177B7B6, 0x2B5F8544},
	{0xAF43D4AB, 0x90A71DD5, 0x8B4A88C2, 0x0D7871FB, 0xF659F041, 0xF8D71F48, 0xDF1E7104, 0x94B6390B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 632 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 633 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 634 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 635 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 636 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 637 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 638 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 639 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 640 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 641 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3B92FBA0, 0x7B9A2DFF, 0x6D8151F9, 0xC5F29BCD, 0x1083C7E9, 0xF3EB11F4, 0x8FB06A98, 0x2FFF1844},
	{0x58D999E4, 0xA0D8456A, 0x161D4145, 0x51764FBD, 0xC12E19C6, 0x2845A889, 0x35ABB0EE, 0x19FE65A6} } ,
	 { {0x33D0F612, 0xAEAFF676, 0xC749DE06, 0x75371354, 0xCC1C0DB1, 0x76B66B94, 0x373033C3, 0x1572647D},
	{0xA9AC9DCE, 0x5CC69475, 0x569EEECB, 0x5A7353B6, 0x64C812D4, 0x80A3171B, 0x520A00A5, 0x0A2439B4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 642 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 643 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 644 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 645 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 646 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 647 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 648 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 649 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 650 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 651 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCEC58290, 0xE2B8A1EB, 0xAD5AD90E, 0x0C98AC92, 0xB3E20942, 0x2ED52916, 0x1604476B, 0x80878B6A},
	{0x67064BD9, 0x7EC5FB9D, 0x49F6C30E, 0xFBFC4203, 0x559D0F2F, 0x2A5EE843, 0x658E22FD, 0x28EB8A32} } ,
	 { {0x6F2F1FF8, 0xF188A6EB, 0xBCFE4180, 0x7B2B2940, 0xDAC4BAE7, 0x648F8FAC, 0xF8B65E42, 0x513939CB},
	{0x96EAB4FE, 0xFFCA3EED, 0x2B46B237, 0x44B71620, 0x47ABD058, 0x8FFC990D, 0xDA6EB8E0, 0x73481DE4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 652 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 653 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 654 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 655 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 656 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 657 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 658 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 659 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 660 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 661 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7491C9F3, 0x48ACAB49, 0x46D002D7, 0xF7823D80, 0x7BCED4B7, 0x123A54F0, 0x42D824E7, 0x9BC2EB89},
	{0x50331C59, 0xCA6D72F0, 0xDC73567F, 0x6F87927A, 0xE89C5107, 0xA07C2E07, 0xF40A86E2, 0x7B34C40B} } ,
	 { {0x4229ED22, 0xAAA6E25C, 0xD9F062C2, 0xAF62BE53, 0xD66583A7, 0x6D85095C, 0x313DA506, 0x2FDC7233},
	{0xD967008A, 0x0B86D9D2, 0xD0327C94, 0xACD14C04, 0x7AA78D7E, 0xAAD22EB2, 0x99C126A7, 0x738106B1} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x525DDE7C, 0xAC5426AB, 0xB9A02D1F, 0xD7E1A042, 0x9CB5F422, 0x33505573, 0x65FF9C29, 0x81556C2E},
	{0xB1CBE173, 0x3A7EA8A5, 0x1DDAC735, 0x1BFF18F9, 0xEDAE1BB2, 0x6DF466C9, 0xA7848B92, 0xA3DE207B} } ,
	 { {0x6A18E3B5, 0x74F00656, 0x912ED146, 0xAA4DE74F, 0xDF100DFE, 0x73B70A86, 0x324B82FF, 0x0C0AE6B9},
	{0x9CDA4DC4, 0x398F75FB, 0x38B9A547, 0x94093BCB, 0xDFBD5CC9, 0xA0033E8D, 0x5292B469, 0x69D8F7B2} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x4431474E, 0x3699EC00, 0xB5A52FC2, 0xD93282DB, 0xDA35E311, 0x70303FB1, 0x1F78C1E2, 0x56778E5E},
	{0x82CFB09A, 0xD2536AB7, 0xEC89888F, 0x7E156EBF, 0xD2D895BB, 0xA6A077BE, 0x4DA6F82F, 0x17389105} } ,
	 { {0x5690E1DE, 0x4093BB2B, 0x942EBB7D, 0x72C0422A, 0x0993448F, 0x758B05EC, 0xD7D547FF, 0x1632FB40},
	{0x1FF87B25, 0x9FC171B3, 0x0E60A7D8, 0xA66084E7, 0xF7B0F711, 0xC89E1E9D, 0x95822417, 0x52551F30} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 662 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 663 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 664 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 665 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 666 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x700B4C3F, 0x7F72B4F9, 0x4781C197, 0x8E5F8216, 0xA4B8EF8C, 0xF1D1B840, 0x25CB2964, 0x166BCA31},
	{0x796C449B, 0x88264B80, 0x2F048424, 0x56C08600, 0x994CF6FE, 0x34BAA82C, 0x718E9D47, 0x4A738B25} } ,
	 { {0x346A68EC, 0x5476D575, 0xB0BDC992, 0xF63C7918, 0xDA33D401, 0x43549B7F, 0xBCFFBE76, 0x61F5673B},
	{0xE896822A, 0x6DE1D3B1, 0x074F5303, 0xAB47C67C, 0xC291F24E, 0xD346103D, 0x0A5DED1B, 0x5BF18A9E} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x080D5192, 0x19D09D2B, 0xB0701F19, 0x0627D28C, 0x13FB9F57, 0x2459F74A, 0x70BA8456, 0xAFB853B6},
	{0xA92795E6, 0x6C67524D, 0xECA04025, 0x374C138E, 0x04B43A75, 0xA70D47BE, 0xDAF803DC, 0x86BB8BA1} } ,
	 { {0x1F1A32AD, 0x161F1487, 0x59AC0CC2, 0x615C5E13, 0x849D999D, 0xEE50EE0D, 0x1AE453B9, 0xAF3F3672},
	{0x024F0083, 0x2F6E8FC7, 0x7A2EA871, 0x7CE1A63B, 0x837C8AE3, 0xF01FDBC4, 0xE86FC02F, 0xAAE83D24} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3D1E4E36, 0x0E88A1A7, 0xAA055751, 0x5375F238, 0x76FD37C0, 0x9D2FF6BC, 0x02345DA5, 0xAC19BB10},
	{0x19F436FD, 0x43A58024, 0xF42F607F, 0xC44B5E39, 0x5F61D02B, 0xC00341FE, 0x92B5BA78, 0x1217260A} } ,
	 { {0xC1068DAB, 0xAB897951, 0xD07631E5, 0x5823B3FB, 0x65798301, 0x7CECC23A, 0x9A5869D0, 0x5ECB3AAF},
	{0xA074ADF3, 0x210E4B84, 0x7CF7F51D, 0x8599C3AA, 0x2E18D378, 0xEA674D3A, 0x567EFB0A, 0x2FB1D51E} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 667 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 668 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 669 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 670 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 671 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBA4FEC21, 0x3304340B, 0xFCD8C245, 0x51923BDF, 0x9A24999F, 0x52A40E02, 0x7B62F5FC, 0x746D5B50},
	{0x8405F673, 0xF65500BB, 0xDA190FE9, 0xC0E5B9EA, 0xE530D8C9, 0x25296383, 0x3C3EF235, 0x827F1CE1} } ,
	 { {0x06BAE128, 0x935DBD5D, 0x494B1439, 0x08639A66, 0x0398C1BB, 0x2382C8EA, 0xF80E8066, 0x893C7033},
	{0xB19D3139, 0x317FB12E, 0x729F61AC, 0x72C25A47, 0xA1D024E5, 0xA2ADA521, 0x2C390511, 0xB259E568} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE5FFA189, 0xB153E132, 0xA653B5DA, 0xDEC92260, 0xD283D859, 0x8C6F9973, 0x7D8DB088, 0x8BF038F7},
	{0x8DECFE0F, 0xB618F9AA, 0xDA03B869, 0x87AD1064, 0xF31849D4, 0xE189F9D9, 0x0EBE894E, 0x463F457A} } ,
	 { {0xCDEB101B, 0x2B5555C2, 0x5BD04948, 0x4399CC8F, 0x8B6A6BA2, 0xED350B89, 0xF254A305, 0xB3B48349},
	{0x00933A36, 0xB6C9CBCD, 0xE5650AE4, 0xAA0306F2, 0x512870F7, 0x8C06983A, 0x676F1920, 0x53661E33} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB1F413D5, 0x8C71D7B2, 0xCE236AD8, 0x5572725B, 0xD09873FA, 0x504D0976, 0xC7A06089, 0x084980D2},
	{0x0D2AA389, 0x98E30764, 0xED790B05, 0x4B0DE0E5, 0xE189E189, 0xB1A0946E, 0xD581506A, 0x15B0314B} } ,
	 { {0x8AA894BA, 0x8B756A6E, 0x83FA1529, 0x8E6CE847, 0x3F167D40, 0x0A0DF239, 0xB001C9D3, 0x56090144},
	{0x629F5535, 0x32F7EAF1, 0x431A71D5, 0x05D732E8, 0x0DB11F1B, 0xD9107A70, 0x8FC52DE9, 0x9D9C810A} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 672 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 673 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 674 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 675 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 676 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x50826581, 0x2CC10CE2, 0x31F69837, 0xF48F8FFE, 0x0903B7C4, 0xFBA39F7E, 0x518D0DFA, 0x1AA2DE9D},
	{0x5C2619E7, 0xE2CAE9BE, 0xCD8567BF, 0x2E0F1A56, 0xFBB68111, 0x42B131A5, 0xBDBBA85E, 0x23770757} } ,
	 { {0xAD77BA35, 0x3245F8B5, 0x2964C7CD, 0xF3E9C69E, 0x63C9424B, 0x8FBFB132, 0x16309F4C, 0x70FF1966},
	{0xAF8568C4, 0x9871AAA6, 0x87CBFB76, 0xE487CDFE, 0x8AB2F604, 0x9E07D73D, 0xE000E151, 0x2234DCA6} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x9BF43D3C, 0x1E50AA9D, 0xDA05C925, 0x7255A121, 0xE9901CB1, 0x78D6FA4C, 0xA0BA14E7, 0x1615F5C2},
	{0xF0F69AD8, 0x87ABBFE2, 0xA3B05E7C, 0x8D583314, 0x054AC830, 0x49B3F4BE, 0x986FC1D9, 0x4A17BA01} } ,
	 { {0xBD7DBB18, 0xE97EA467, 0xB10AE6AD, 0x2D0B7C82, 0x0FA8B807, 0xF2110BB1, 0x431B0DB0, 0x087200B9},
	{0x65B2B426, 0x12AF4460, 0xE3C6686D, 0x663A6F8B, 0x362F9B10, 0x776432AC, 0x9679B425, 0xAA02BBD6} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xEC54D2F0, 0xE076A829, 0xB2C76E39, 0x7588D599, 0xA063AF71, 0x6FC33344, 0x56F12BB9, 0x18377385},
	{0xC4460F5E, 0x3AC30517, 0x0D9E757D, 0x7011D58F, 0xA72AC518, 0x904FB9EB, 0x1A54CE79, 0x7B34B881} } ,
	 { {0xD2BD179B, 0xFB1A50E1, 0xDE5D076A, 0x79B9F209, 0x60CDF176, 0x804EF024, 0xB9A2220E, 0x591CE1E1},
	{0x94FF943C, 0x06625603, 0x639BC017, 0x35314945, 0xBCC355C7, 0xEEB2FEF1, 0x40F0E832, 0x65CC7112} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 677 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 678 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 679 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 680 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 681 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC50843EA, 0x5393A89B, 0x92D89EC1, 0xCC42ABF5, 0xDD560E9B, 0x55BC150D, 0x5A4DD67C, 0x0F48B03E},
	{0x51220E5D, 0xF1AFF25E, 0x55915B7F, 0x2A0B9E06, 0xFF9EB534, 0x435C2BD3, 0xF139DFB4, 0x9D376320} } ,
	 { {0xEC57B16E, 0x670B1AD3, 0x7FA0FFD3, 0xD05D5D2E, 0x4BDE0C20, 0xF33204B7, 0xEFCB0BDE, 0x29E002A4},
	{0x64735992, 0x5F196C03, 0x545B3D27, 0x7663E622, 0xAF8D4554, 0x1F10A99E, 0x77F48937, 0x7B369389} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC8C332F8, 0x04F2416E, 0x3166AAAE, 0xC2E44218, 0x2716AAD5, 0xFA0C016E, 0x746C4F82, 0x28EBA9AA},
	{0x5B514FCD, 0xD1400C40, 0x2C76574D, 0xB3EADCDF, 0x5349DD9C, 0x7C5B3F13, 0x0A0AF120, 0x69912D98} } ,
	 { {0xCDC4D73F, 0x841BEABD, 0x432302BE, 0xE1C7424C, 0x83D815D2, 0x12FDB51B, 0xDFDB7CCD, 0x447F1F3E},
	{0x8F253019, 0x82ED5B7D, 0xFC6CBF86, 0x4583599E, 0x60151258, 0xE468BDC6, 0x94885032, 0x84DF3583} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA93AF045, 0x5007A22F, 0x2A53C2AB, 0xB08DF8FF, 0xE36A961E, 0x0C715CFE, 0xD785C443, 0x2B6B76D1},
	{0x38FED930, 0x4D32A133, 0x1A5B37CB, 0x6325E80F, 0x579C5B6D, 0x6C474ECC, 0xDCCA0BD8, 0xB010D94D} } ,
	 { {0xCDA8BEA3, 0xC502A1FB, 0x627FCE6F, 0x93B4131C, 0x766ED561, 0x012158D9, 0xD411B41D, 0x37E6159A},
	{0xAE235060, 0x4060FD11, 0x45D28F24, 0xD64E7C8B, 0xA63F5E4A, 0xD04EDC9C, 0x04A764A5, 0x866A1FC4} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 682 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 683 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 684 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 685 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 686 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x895C5963, 0x89520174, 0x30B01D1A, 0xC0F7572F, 0xAFEA155E, 0x986FBC07, 0xF1D9D0C6, 0x2BD2E153},
	{0x991B3271, 0x7E9D1717, 0xA4EC8A0B, 0x011AE727, 0x0D070325, 0xF8DD962B, 0xDB8876C8, 0x51284B1C} } ,
	 { {0x237D2581, 0xA7105C10, 0x3CED3D3E, 0xEE1B27EA, 0x1743E395, 0x80DCD8CD, 0x9E49A613, 0x3015E9C9},
	{0x6D8F30CF, 0x539FF610, 0xF6A68D41, 0xF8A1786F, 0x6CBA4B8A, 0x2E591ECE, 0xB1D85BAF, 0x2564FBF0} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xDCD2F957, 0xFC782A96, 0x5B5DF54A, 0x7A9ED174, 0x85265703, 0x39BDA919, 0x6180A34D, 0x38A6CF70},
	{0x605692C3, 0xFECAFE33, 0xBAA850A8, 0x619B1E72, 0x12EA4B6E, 0x0102E126, 0xF0CD12F6, 0x3AFA6E62} } ,
	 { {0x884E7E41, 0x53597FFE, 0xA522A550, 0xF8332C30, 0xFA67A5C5, 0xAE4064B1, 0x70789121, 0x78947F33},
	{0x8EDFD796, 0x03EC22CA, 0xEE98A224, 0x42BDB314, 0x4782E78F, 0xB913363A, 0x0F3CE7A0, 0x493FFB43} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC4DAB666, 0x565DA917, 0xA121E5F1, 0x8BCC28AF, 0x5015074C, 0x2D57966E, 0xC0CEA4E5, 0x4A70308F},
	{0xCBAED13C, 0xA8859248, 0x612851DB, 0xAB4BAAEC, 0x6C376562, 0xCE23CB5B, 0x4A555D13, 0x3462FA70} } ,
	 { {0xE107EE10, 0x27F14B1C, 0x73C7BC66, 0xBB461343, 0x53B6B8CB, 0xE9E50FDA, 0x03640C4A, 0x347E75C2},
	{0x6EB5331D, 0xB339B13D, 0x858F8AA7, 0x1BDB2924, 0x4D54D1BE, 0xDAE0D6EB, 0xF4187C4C, 0x9A46A9C0} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 687 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 688 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 689 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 690 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 691 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE2EF0A89, 0xF02FFA05, 0x904A5D91, 0x8A6C38EE, 0x91FF817E, 0x8A28A7BE, 0x204AA9EC, 0x603BC3E9},
	{0x6F9425C0, 0xC89179CC, 0xD2B2B509, 0x25788C06, 0xA8B1E2AC, 0x2D350543, 0xDBFB92BF, 0x354D6CC5} } ,
	 { {0xDC7BE83C, 0xB0209FDA, 0x2530C368, 0x45CF277F, 0xCA407645, 0x549CB1AC, 0x8FF8C6C0, 0x5B46CD21},
	{0xEB31C00E, 0xD7B8C893, 0x51F7AF96, 0x94DD7A1A, 0xA275462C, 0xFDFB44EB, 0xF8F114A5, 0xA8D82E32} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xDE9F2333, 0xC7A505E0, 0x6C0DC99A, 0xDB93B38B, 0x8B10A14E, 0x35C39287, 0x31BD4546, 0xB39148AF},
	{0xC035073A, 0xB911F815, 0xBD855295, 0xC97FB2AE, 0x75C7FB16, 0xF1F6FCF1, 0x9B1E02DC, 0x3D2C0603} } ,
	 { {0x57AC1053, 0x7656D0AC, 0x6244CCC3, 0x870E0EA7, 0x90AFB652, 0x0370846E, 0xF16230D3, 0x495734A7},
	{0x5E8BC0FF, 0x666D80EF, 0xC17CA402, 0xE776BF6E, 0x32BAE58C, 0xFD62D37A, 0x98B316B0, 0x61C4D244} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x86055FA2, 0x6AFA2AF3, 0xF6598C98, 0xD7468749, 0x462B0F14, 0x8C35B00C, 0x9E659C3A, 0x23CEF051},
	{0xB4AAD7F8, 0x1F8A519E, 0x66DE1896, 0x3DE33A3E, 0xD3272EB1, 0xD776C217, 0x927114CA, 0x380844CA} } ,
	 { {0x5EDE021A, 0x3147C66B, 0x942349A2, 0x7BB60412, 0x4CC3B40A, 0xBD9F1619, 0x70B33D44, 0x50CF7656},
	{0xF37D9BCE, 0x454CEE6B, 0x885A1637, 0xE9B51B0E, 0x30B8226F, 0x57BF4481, 0xB1EAE982, 0x148A9D92} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 692 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 693 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 694 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 695 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 696 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFD059CD0, 0x6D30EA58, 0xDA732102, 0x74ED01EA, 0xE4ED65AD, 0x23B2C61A, 0x81D2F8BB, 0x7328A5F4},
	{0xB32D17CF, 0x35DA6935, 0xDFB95D3B, 0x0BEC6483, 0x90B0F710, 0x48EE52E4, 0x8BC9ADF9, 0x235E0362} } ,
	 { {0xC6BA30E6, 0x8C678D1E, 0x29FAB499, 0x52CC13A1, 0x018A0C59, 0x85E60F75, 0x661CD959, 0x5B4B8CD7},
	{0xD17C43BC, 0xF436F7F4, 0x2E0478D0, 0x9493A3DF, 0x3111AD1F, 0x9D0366F8, 0x07336EF5, 0x44D007AB} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x615CE846, 0xF7D27EE5, 0xE5107381, 0x124F38A0, 0x19582B7D, 0xBD86ADFE, 0x5D2E28A9, 0x61F3E116},
	{0xC5E4AB19, 0x003BDF11, 0x60285787, 0xF9AD0C2B, 0x068B26D0, 0x60BA6160, 0xF71B7875, 0x550C1F30} } ,
	 { {0xF7B71B20, 0x708747DD, 0x8F1AC45B, 0xE6A03BC0, 0xC5521A83, 0xEDB3129B, 0x1E9FB9FF, 0x22394244},
	{0xA5DC2C29, 0x515AA523, 0x26A5C1F3, 0xE39BC288, 0xE5AA0F93, 0xFA4E5531, 0x34371B7F, 0x6BC68A56} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB47A7CAA, 0x3F6F2656, 0x4E6589DF, 0xB0E9F5BD, 0x77877CA0, 0x95689F83, 0xF65186A1, 0x02C04656},
	{0x33984E1E, 0xB303EC31, 0x358C6442, 0xE31CF21A, 0x6E1EE3D5, 0x9CCF8C86, 0x23F05229, 0x94042C94} } ,
	 { {0x85133BC2, 0xFED60B8A, 0x17CB94D0, 0x838C494C, 0x95214F8B, 0x9FD371AC, 0xA3190B60, 0x78E18C68},
	{0xDB12AB7A, 0x015C515C, 0x213058A2, 0x26679804, 0xC270D622, 0x571023FF, 0xC1D562BF, 0x8E88D9FA} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 697 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 698 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 699 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 700 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 701 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x87B15C6B, 0x5EF7D501, 0xC5BE2EF1, 0x8D8F4373, 0xB91A08AF, 0xEB7A74E8, 0x9EB62343, 0x99313A42},
	{0x509B6505, 0x993C67D5, 0x11102AEE, 0xF5E1C07D, 0x00319623, 0x93741750, 0x51485E43, 0x861435FF} } ,
	 { {0xBBA31125, 0x83D277D9, 0xA80539F1, 0x911F58B1, 0x024BCCAB, 0x982110BF, 0x4ED6B5D3, 0x0C7F6CCF},
	{0xB730EEF2, 0x9086ABE6, 0x6A2932B5, 0xF9264073, 0x0F6C76EB, 0xB3BEFDFF, 0xDF17C514, 0x6CC12599} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x1443D11F, 0xE5E837FD, 0x08DA9BAC, 0x1BEB0D11, 0xF286C7DA, 0xCD01A010, 0xA805908C, 0x9CC5F162},
	{0xDEB8DB62, 0xCB6876AF, 0x1DE9621C, 0x50E6F841, 0xA5275AAB, 0xCEF9FED0, 0xBB0D55BD, 0x7F9213B5} } ,
	 { {0x9BFFAD4B, 0x5CF3E267, 0x632EAA7E, 0x3E4C6E95, 0xC3D4EF6E, 0x0C3C49EC, 0xF13978D8, 0x8758ABC7},
	{0x27D72043, 0xFE64FF70, 0x39599A90, 0x691260DA, 0x9C6489D6, 0xBC303288, 0x93FA9184, 0x7CF72B9F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x4BC00647, 0x5F053951, 0x140EF744, 0x2E28C5F1, 0x3185EABD, 0x8AFA2B42, 0x049FB1BE, 0x13AC36D2},
	{0xD91F2DBE, 0x7D50D0CB, 0xC746C692, 0x0DBAA84B, 0xACF6B2AC, 0x52095467, 0xE4AC22BC, 0x65DE6BC4} } ,
	 { {0x1417ABC0, 0xDA293F4A, 0x1AE1D849, 0xD97716E6, 0x75E75520, 0xB4FB64AA, 0xBA099621, 0x14F8DDBC},
	{0xC0A014C0, 0x030F1C54, 0x21C4CA6E, 0x9807A92F, 0x11A3F123, 0xE5AE3B61, 0xB4B4ACD1, 0x48EAB4CF} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 702 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 703 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 704 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 705 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 706 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x06889ACF, 0x411CA717, 0x2D3C76AD, 0x1F981364, 0x1F951076, 0x13A7E8B4, 0xE8ED76B4, 0x640AD78C},
	{0x99121B91, 0x786F9823, 0xBDF7666D, 0xAEA5A31C, 0x45D593BF, 0xD8302D5E, 0x46ACFEF5, 0xB21B83D2} } ,
	 { {0x56CBD987, 0x684AA630, 0x5A32A596, 0x95A6A056, 0xE24F77F6, 0xE4BF928A, 0xB217E466, 0xA4DF257E},
	{0x2D546937, 0x1597918A, 0x8EE2CAFD, 0xD1149331, 0x99AEC143, 0xA1B21264, 0xE5E2DFBC, 0x0C0445AD} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x854AD80A, 0xA414E267, 0x7C6DF2EC, 0xB8B4F8C2, 0xCD346322, 0xE356DA4D, 0xC6F627E0, 0x6A996375},
	{0xA3EC0AB8, 0xFE468321, 0x441B7415, 0x10C79B8D, 0xAA68B278, 0x13DA1845, 0x990F2342, 0x7770FC28} } ,
	 { {0x23448E2F, 0xB74EAC78, 0x4F07514C, 0xEA4D2305, 0xE7CA1D44, 0x4D23F5F1, 0x83135ABE, 0x0A4CF103},
	{0x6D028E13, 0xAD327A4A, 0xAC065F59, 0xBC5EF286, 0xEF44B707, 0xD60CC39E, 0x074FB980, 0xA754C346} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xDC67130B, 0xDE2E537B, 0x982BC016, 0x43038BED, 0x60E1E5CA, 0x05C7EB17, 0x80BAE087, 0x4DCA7B74},
	{0x379E76AD, 0x9C943686, 0x61A90446, 0xCE9D4D19, 0xBF610B16, 0xB8ACFA78, 0xC951FD2E, 0x37E7527B} } ,
	 { {0xC3157F75, 0x28BE6CEA, 0xE9B494B4, 0x53455C01, 0x50AB4897, 0xD0196B56, 0xD2DB21A2, 0x232D4500},
	{0x8D14BF15, 0xE615A2E0, 0x7DC30F42, 0xB80B3F4A, 0x983189CD, 0xE1A995D1, 0xC07BB679, 0x1F2BCEED} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 707 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 708 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 709 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 710 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 711 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3E004F3D, 0x53D38722, 0xFF1621F4, 0x681296B5, 0x5F29D359, 0x0B4E8B11, 0x4D62E13B, 0x02AA2588},
	{0xF88ED8F3, 0x669EA61F, 0x2E0E997E, 0xFABEE37C, 0x0DFC5B62, 0x3254BFD2, 0x87A126A7, 0x2AD46D89} } ,
	 { {0xC380829C, 0x79BF5B79, 0x1E34053D, 0xED767046, 0x15B3A2E0, 0xEA573C7D, 0x0B3DD7F0, 0x3099E9E4},
	{0x18A425F4, 0x9020076F, 0x31A50B2B, 0x13C6D7B5, 0x0E0EF6F8, 0xB43FCB76, 0x1E995D16, 0x1D3F257E} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x78E82C26, 0x1E6EB7AF, 0x2E570581, 0x264E89A2, 0x2B34BF28, 0x55CB032E, 0xC877085C, 0x738FA703},
	{0x0C537C72, 0xFF78A2B2, 0x1310CADA, 0x193831FD, 0x15019F59, 0xB4E21826, 0xF8AD0594, 0x6CEE356F} } ,
	 { {0xAE143280, 0x4B7934DD, 0xED6D81C8, 0xFB308195, 0x89919AF1, 0xD00FA9A5, 0xE4E406FF, 0xA8054163},
	{0xB139990E, 0x1C7B6244, 0xD0CFBE0A, 0x930F06C1, 0x3174FB92, 0x9302AD48, 0xEC8EC2CD, 0x877F0455} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA309F61A, 0x506E7927, 0x3DFFD267, 0xD5F61F86, 0x722E1414, 0xF4207EE0, 0x11E37231, 0x1211FF5D},
	{0xF8DBCDB7, 0x20CF52F7, 0x44AD2FBF, 0x93F55F8B, 0x5B035E5E, 0x20F37B30, 0xE6D7AA37, 0x3555EC72} } ,
	 { {0x7DCDBD92, 0x17E78575, 0x368977CA, 0x964A4C17, 0x90CDF5D7, 0x0C98BE99, 0xBD9D659F, 0x17F7CA46},
	{0xDC0588CE, 0xBF00A509, 0xD63840AD, 0xE7F4941C, 0x628F470E, 0x45EF5E7F, 0xB89F3310, 0xB2484796} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 712 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 713 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 714 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 715 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 716 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBC24F4E6, 0xB6ED48F2, 0xDB7C3A88, 0xCCB561C1, 0x96A7A040, 0x4A59241B, 0xE2DFCC63, 0x3B75DA1D},
	{0x65B65ED0, 0x1C671AEC, 0xAAEDA665, 0xA20503B3, 0x60AD7F76, 0x6CDF3865, 0x675887CD, 0x93A2FAC7} } ,
	 { {0x76FCA0EE, 0x06853092, 0x29127A7E, 0xED7AE7C9, 0x057168C7, 0x612723C5, 0xEFD2ACAF, 0x1718C21A},
	{0x0EA9BE37, 0x6FD39858, 0x4ACBEA37, 0x87866DBF, 0x6C1EB5E9, 0xD5723925, 0xBDE9D4F7, 0x889DA952} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x9622C0E3, 0xC6E3BC98, 0x479AACF1, 0x7808EDBB, 0x94BEFAFB, 0x1EA66129, 0x2D8D8F73, 0x3C51F953},
	{0x33EFDE95, 0x254831C6, 0xAEFF9DCB, 0x662CD141, 0x73E63CFA, 0x2F88BA8A, 0xD9CA25D3, 0x1AB71856} } ,
	 { {0x43ED67B7, 0x654A480F, 0x7B1CC324, 0x1C0A261D, 0x2C9E5E63, 0x55D0F2D1, 0x0E198149, 0x42E7D7CC},
	{0x4296C63C, 0xDDD19334, 0xEEFA1233, 0x6663B4F6, 0xA625C25B, 0x45EAC96B, 0x1E089A0A, 0x9AD8887D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2DCC3E9D, 0x28A4A36A, 0x72705A3E, 0x9A73F154, 0xB9A65085, 0x96BEB459, 0x0486823F, 0xA4FA0112},
	{0x982A0C16, 0xC6802A75, 0x688D709D, 0xC6F279BD, 0xDD5C9828, 0x2C25E8B1, 0x7E47CC1E, 0x8A484125} } ,
	 { {0x6EAFD39D, 0x5388767D, 0xC569FFB3, 0x1B036037, 0x2CD53773, 0xE8E2A1D7, 0xADC07F70, 0x8B43E662},
	{0x5F11394B, 0x907341EA, 0xE7212D5E, 0xF5CC7016, 0x5DA0DEED, 0x22451B00, 0x4BE41E9D, 0x4F2A6725} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 717 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 718 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 719 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 720 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 721 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x24BBE5E2, 0x4CF8F78B, 0xE61A0B96, 0x736F41BD, 0x8F2BDDEF, 0x3BD73D02, 0x34665463, 0xB48A4856},
	{0xAE18EB87, 0x6E9A2C80, 0xCC257CD7, 0x04C03B0D, 0x58EB2225, 0xDA0F9B01, 0xEB14F47C, 0x3C931333} } ,
	 { {0xD136E58E, 0x195E5750, 0xFEE9A0AC, 0x60B434E2, 0x074310E2, 0x05ED0819, 0x7CE1AE71, 0x915627AF},
	{0x8F290A95, 0x6500FEDE, 0xEE91AD90, 0x5F96D845, 0x19945B90, 0xDDE95348, 0x343662B3, 0x5011F1EA} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x1450385C, 0x20D659FA, 0x8AA8A794, 0x8DE564E0, 0xF7C7CA32, 0x11CA025B, 0x7E149A03, 0x779FE045},
	{0xF0B7153D, 0xB4933E5B, 0x6D645E8D, 0x79D4D7F4, 0xD5F66583, 0x977AF181, 0x9185AFCB, 0x7A215065} } ,
	 { {0xC5CDE9FB, 0x3E66C15C, 0x290DF1E1, 0x17605319, 0xBAE8DCE2, 0x994AAFB3, 0xBA9B5563, 0x4CA6D732},
	{0x21D10311, 0x8615C2FE, 0x78FA155E, 0xA9B7F54A, 0x47FD2889, 0x4A7F4DD4, 0x29DA7A1F, 0x99CDF13D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAB9F44F6, 0x58686D08, 0x353D45CB, 0x57FFF7AE, 0x77E123BA, 0xFDB055BA, 0x786FEF6A, 0x5D1BB101},
	{0x20BC0DDB, 0x3731D6E9, 0xAEC4FD37, 0x5AE1937F, 0x979C0BD4, 0xCE69D96C, 0xF8C2FC82, 0x752EAF90} } ,
	 { {0x9EB302C1, 0xEC5BF06C, 0xCAA45F3A, 0xCDF8061E, 0x1108F3B3, 0x0C7CFC73, 0x5DC1FE20, 0x29DA1A2F},
	{0xC20A26B0, 0xEE8492F9, 0x3BA87AB9, 0x2D29AFBF, 0x0223B5EC, 0x8B494C11, 0x43C4F867, 0x87BF2EB5} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 722 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 723 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 724 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 725 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 726 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7B439F8C, 0xC513A355, 0x8C50B17F, 0x199B8C94, 0x182393E9, 0x70306404, 0xAF5CB3A9, 0x2D475380},
	{0x3FACFA4D, 0x97008BA9, 0x3D684799, 0x840669FD, 0x85F39D55, 0xBCD5E667, 0x5CFA9AA1, 0x488D7314} } ,
	 { {0x479FF731, 0x66D3EB1F, 0xDFA5B8C0, 0x2555CE4A, 0x2EB07A6B, 0x234624C3, 0x24B84888, 0xBA1082A5},
	{0x704535A7, 0x770E7BFF, 0xA3ADA5C7, 0xBDF0EACE, 0xAFD3AAEC, 0x88DB8CD3, 0x875FCE37, 0x9466B721} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD6544964, 0x410C8E46, 0xED4AAFDF, 0x60611B4C, 0x8D8DE24B, 0x8521A92E, 0x3FBADEAF, 0x31C2E80B},
	{0x0C898D54, 0xEC3BD65A, 0x2436264C, 0x56E51EEE, 0x2D1F7055, 0xBF6E9412, 0xFF08FCC6, 0x75A8CC9E} } ,
	 { {0x1BF07521, 0x51B772DA, 0x1091CC2F, 0xE2B32DFA, 0x23AFC10B, 0x378CDD8A, 0x18C96938, 0x1181FFE5},
	{0x2EA57D5E, 0xC0619552, 0x3E2CFD89, 0x9351677D, 0x3AB540B1, 0x6A95F95B, 0xC728A63F, 0x18C726AA} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x45D735FD, 0xD42B5F07, 0x24CC3CA1, 0xC8F80158, 0x8874AF0A, 0x1A34CB70, 0xE199C68C, 0x0606ED15},
	{0x001776E1, 0x26041248, 0x88C358B8, 0x57239C98, 0xD4B79A26, 0x39508EE3, 0x1046BE59, 0x20AB849E} } ,
	 { {0x6300A023, 0x5C07263E, 0x7EA9C0EF, 0xE5089AD5, 0x6895EF41, 0x52A347DD, 0xC6630BAE, 0x3C15AFB6},
	{0x13EF6EE0, 0xCFD4EEFB, 0xFBF2B5E6, 0xD78BA9EA, 0xF1D4B082, 0x7433B9C1, 0xCE9A57D0, 0x43ECD472} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 727 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 728 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 729 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 730 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 731 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8075D9E4, 0x5BA94C11, 0xA644AE9A, 0x434F693E, 0xA5306AF8, 0x13803573, 0x8E936045, 0x8EFC2815},
	{0x52915AD5, 0x77430AA3, 0x8217C5D5, 0x52971D02, 0x9AED744C, 0x4AF86775, 0xCCDE9CDC, 0x57842B87} } ,
	 { {0x9445F095, 0x5DCFD7B2, 0x6F3BA852, 0x0E334BBD, 0x4A4745AA, 0x7A0CCA1D, 0xE23519B4, 0x99DA4D06},
	{0x5BEEEE4D, 0x1F6A1A0D, 0x48384A28, 0xC98FBFD7, 0xCD3B3178, 0x4595F723, 0xD9466070, 0x6963B5E6} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2F00A4F6, 0x0F10ABAB, 0xF9BD9F61, 0x8F60BC66, 0x33075F21, 0x9ED58D8D, 0x493EA5B6, 0x0E030536},
	{0x622AB8AB, 0xCF2223CA, 0x6027AF04, 0xEBC42111, 0xD9C635AD, 0x3865B432, 0x803B0E29, 0x7D564309} } ,
	 { {0x7021BF30, 0xDC059450, 0x9C96D456, 0x766D59BB, 0x0D52A5E7, 0xC55F9A02, 0x4A12510A, 0x522821F8},
	{0xD817C0F1, 0x19290C8F, 0xE00FF628, 0xBA04A718, 0x372793E5, 0x841C8670, 0xAB955EB2, 0x8468B922} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x9ABC2B27, 0x8CCDB682, 0x2A8F4014, 0x46236914, 0xC057F81B, 0xFF3111D6, 0x9E0E4BB4, 0xA5CAAD9A},
	{0xB46412BA, 0xF824DC34, 0xB486628C, 0xDCD31486, 0x1046CE70, 0x38CA5A13, 0xCCC615D1, 0xA489BC62} } ,
	 { {0x62D46BAF, 0x0882E175, 0x8F52E70D, 0x0CFFDA17, 0xC81F1C4A, 0x08CE9747, 0x851243A5, 0x36F6BC46},
	{0xA34D626B, 0x7A55D624, 0x88881ECA, 0x51548D2B, 0x9B4B38DA, 0xD42041CE, 0xEE472167, 0x82093823} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 732 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 733 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 734 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 735 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 736 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0D4FD990, 0xDE5DEDE5, 0xA78F3EAE, 0x8FCC3D6B, 0xF3F83DBA, 0x9FD59AAF, 0x9007BC72, 0x268E6198},
	{0x93FF1820, 0x7F121001, 0x4F017F04, 0x00F2ECC6, 0x722D7AE4, 0xD24C6355, 0xE6149B3B, 0x5790362A} } ,
	 { {0x389B5477, 0xECDD96D3, 0x75902614, 0x19E971F2, 0xD49166D1, 0x0C0833FB, 0xC5979DC5, 0x0F9F6A26},
	{0xD8FF2840, 0x84742A43, 0x174D4B10, 0x1FA3A89D, 0xD0BB99EF, 0xDAED2CD6, 0x59CEA3F8, 0x98183901} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE161D4F7, 0x4CE6246E, 0x6B82A14A, 0x7FD1D6F6, 0x3A454395, 0x33E17C5C, 0x73C8AE8B, 0x909D5B8F},
	{0x06BB80B0, 0x7BEB86D0, 0x11C717D7, 0x049AFB51, 0x5C9AC9CC, 0x173F00EF, 0xF34C18E9, 0x4D006F8E} } ,
	 { {0xBFA3569A, 0x7506547D, 0x343E667F, 0x00E20D9A, 0x5740A092, 0x679036A1, 0xB7588E99, 0xA363266E},
	{0xC1AAF6CD, 0x7E6D1005, 0xF3E677AA, 0x826A9660, 0x8BFA607E, 0xC6DBAEFE, 0x701AE176, 0x0EAEC96C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAA0094DE, 0x22A8626E, 0x781B382D, 0x22673627, 0xF0861DEE, 0x3BDA703C, 0xA758FEB0, 0x5EAC5140},
	{0x5A207D19, 0xADFC99EA, 0xBE929BA8, 0x5B7C3414, 0x0EC73BE0, 0xFDEA494C, 0xA275F99A, 0x42A7C680} } ,
	 { {0x989289FE, 0xD42BEA91, 0x56731A30, 0x9029D2DC, 0x4BA52D85, 0xBE595E67, 0xC69B4D76, 0x06485183},
	{0x37B25D87, 0xDA2294EA, 0x6BB6F5B3, 0x03C0B4D8, 0xD7427052, 0x849E42B6, 0x2F1EA3E5, 0x36F9D500} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 737 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 738 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 739 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 740 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 741 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0FE5595, 0xDF28BD5B, 0xFEFC202E, 0x45FDEF71, 0xA86F0603, 0x3936EA7E, 0x97594DC1, 0x0FF79471},
	{0x10533B42, 0x881FDD5A, 0xEC8A7C50, 0x68267A95, 0x9520E274, 0x4E4D4B30, 0x07F0BABA, 0x3B4783DF} } ,
	 { {0xAF8E8E5A, 0xB1948C26, 0x8AC402AC, 0x3586D057, 0x830F53E5, 0x8C05526F, 0xF3DB9D53, 0x47B47363},
	{0x5FE0A8DC, 0x04B38B19, 0x7D8BE948, 0xCC1F4A9D, 0xA79918BB, 0x4ABEF01F, 0x05D8D3C6, 0x75FF35DD} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF0FE5595, 0xDF28BD5B, 0xFEFC202E, 0x45FDEF71, 0xA86F0603, 0x3936EA7E, 0x97594DC1, 0x0FF79471},
	{0x10533B42, 0x881FDD5A, 0xEC8A7C50, 0x68267A95, 0x9520E274, 0x4E4D4B30, 0x07F0BABA, 0x3B4783DF} } ,
	 { {0xAF8E8E5A, 0xB1948C26, 0x8AC402AC, 0x3586D057, 0x830F53E5, 0x8C05526F, 0xF3DB9D53, 0x47B47363},
	{0x5FE0A8DC, 0x04B38B19, 0x7D8BE948, 0xCC1F4A9D, 0xA79918BB, 0x4ABEF01F, 0x05D8D3C6, 0x75FF35DD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2931D197, 0x69C94D32, 0xA70994B8, 0x04A4AC44, 0x505BCE4E, 0x596D4EEE, 0x18FF04D9, 0x64ED50E2},
	{0xA0C2C246, 0x87DADE02, 0x58D69600, 0x6DDFD50F, 0xC7953B26, 0xBF9DBE94, 0xB77AFFE9, 0x92585BDE} } ,
	 { {0xD4E1E130, 0x50D00E13, 0xEE90C157, 0x87542E4D, 0xDCA25816, 0x2BD8CAAB, 0x266DC5C8, 0x583A5B39},
	{0x30F07774, 0x1C71A841, 0x47436E28, 0xA5B6BAEA, 0x7152BFA0, 0xA6D27BFA, 0x5C80759E, 0x8FAEE5CA} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 742 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 743 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 744 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 745 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 746 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCEDDA954, 0xA2A4774D, 0x91DC628D, 0x7019DA05, 0xB58F6570, 0xEA46F685, 0x4E2E02A7, 0x43078C16},
	{0x89F8D11F, 0x49DF63F3, 0x18746554, 0x7D499376, 0x8E9A72C6, 0x7D8D38D1, 0x279AB4F2, 0x852CE4D0} } ,
	 { {0x273E959F, 0x4E2E705B, 0xCCB87C63, 0x68A8BE0D, 0x03B1F850, 0xC62A3AB4, 0x97715207, 0x9895A17E},
	{0x3019ECEA, 0xA5886096, 0xCB2717F4, 0x0B8EAB08, 0x0CD63C8A, 0x15C02928, 0xAEE6AD35, 0x27649406} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xCEDDA954, 0xA2A4774D, 0x91DC628D, 0x7019DA05, 0xB58F6570, 0xEA46F685, 0x4E2E02A7, 0x43078C16},
	{0x89F8D11F, 0x49DF63F3, 0x18746554, 0x7D499376, 0x8E9A72C6, 0x7D8D38D1, 0x279AB4F2, 0x852CE4D0} } ,
	 { {0x273E959F, 0x4E2E705B, 0xCCB87C63, 0x68A8BE0D, 0x03B1F850, 0xC62A3AB4, 0x97715207, 0x9895A17E},
	{0x3019ECEA, 0xA5886096, 0xCB2717F4, 0x0B8EAB08, 0x0CD63C8A, 0x15C02928, 0xAEE6AD35, 0x27649406} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x10274E15, 0x16BE5AEE, 0x46911552, 0xBF71F1CE, 0x1B07CD15, 0x056A6F01, 0x4E20AEFA, 0x9561E2EB},
	{0x6FB995B9, 0xEA53B76D, 0x913D4ED7, 0x41A5B928, 0x35B7C557, 0xA0D2235B, 0x7E56B273, 0x2A420F33} } ,
	 { {0xB3D968B8, 0x467B6441, 0xF9A12DA2, 0xF64B6D2A, 0xED72FCFF, 0x2354958D, 0xAA7E56E6, 0x0B2C2F4C},
	{0x3077ECD3, 0xD65C9DF4, 0xECBE177B, 0x275C7F3B, 0xB709580A, 0x9D64EB85, 0xA33D93AD, 0x3A4474F6} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 747 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 748 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 749 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 750 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 751 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xD77F5D63, 0x4CF410B3, 0xD849C651, 0x254F3200, 0x66BF40AC, 0xA94B6E4C, 0xD7395256, 0x9576C144},
	{0x18559F17, 0xC2DC0747, 0x7513561B, 0x2E7C4361, 0x72DBFA4F, 0xD11F37AD, 0xA90CC110, 0x28DCC452} } ,
	 { {0x48726F5A, 0x01864CF7, 0xEB0A95A2, 0x77A1708D, 0x364574EE, 0x87B56ACC, 0x6B87CFDE, 0x7F843835},
	{0xDE232E05, 0xE252DAC9, 0x1D04E305, 0xF3E1B47B, 0xF205D652, 0x3247C126, 0xB7E53531, 0x3BD251FB} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD77F5D63, 0x4CF410B3, 0xD849C651, 0x254F3200, 0x66BF40AC, 0xA94B6E4C, 0xD7395256, 0x9576C144},
	{0x18559F17, 0xC2DC0747, 0x7513561B, 0x2E7C4361, 0x72DBFA4F, 0xD11F37AD, 0xA90CC110, 0x28DCC452} } ,
	 { {0x48726F5A, 0x01864CF7, 0xEB0A95A2, 0x77A1708D, 0x364574EE, 0x87B56ACC, 0x6B87CFDE, 0x7F843835},
	{0xDE232E05, 0xE252DAC9, 0x1D04E305, 0xF3E1B47B, 0xF205D652, 0x3247C126, 0xB7E53531, 0x3BD251FB} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB38C5615, 0x2DDF8235, 0x3212686D, 0x79D4D731, 0x721A83DC, 0x1D2B6ECA, 0x3690AA96, 0x2AE81019},
	{0x6459A045, 0x7312AA3F, 0x4C15B9DB, 0xF0132B25, 0xC3DB6279, 0xDBE7C465, 0xFC0B069D, 0x60F1EA8E} } ,
	 { {0xDD625043, 0xDAC69D87, 0xD28C1B02, 0xE178BA12, 0xDEE8C561, 0x61BF12DE, 0xC0F0FAC2, 0x795AB485},
	{0xAD6EFF22, 0x2582F8D9, 0x7CCDFA47, 0xD90261A4, 0x2660A205, 0xCC68BDF0, 0x16F6E434, 0xB49D846A} } ,
	 { {0x26447F1D, 0xA0EF0EB4, 0xED079F54, 0x203E9878, 0x7BD77E21, 0x34DA4209, 0x860FCDEA, 0x3FCBB569},
	{0x4A485A11, 0xAD4A2A03, 0x1C643711, 0xAEBD7BFE, 0x0190ED2A, 0x232DBB12, 0x205B14D3, 0x4DDA2B86} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 752 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 753 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 754 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 755 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 756 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 757 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 758 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x69FA9284, 0x64258C81, 0xDB6AFA26, 0xF9E695E9, 0x78F091AE, 0x5CBDFB64, 0xB63F148A, 0x337FA780},
	{0xE42BD351, 0xD4B7494B, 0x27B8E4C1, 0x21367839, 0xB949651F, 0xD6320562, 0xEF2C9C73, 0x8E5170AC} } ,
	 { {0xD4F28FF4, 0x88F93406, 0x90725E51, 0x43E88021, 0xC540E6DD, 0xFF6CAD9F, 0x387B2173, 0x4C83E40A},
	{0x623ACD47, 0xE3E5A573, 0x407625B5, 0x4E6E4C86, 0x0F1BFF72, 0x4E482048, 0x59A40808, 0x0FB2A587} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x69FA9284, 0x64258C81, 0xDB6AFA26, 0xF9E695E9, 0x78F091AE, 0x5CBDFB64, 0xB63F148A, 0x337FA780},
	{0xE42BD351, 0xD4B7494B, 0x27B8E4C1, 0x21367839, 0xB949651F, 0xD6320562, 0xEF2C9C73, 0x8E5170AC} } ,
	 { {0xD4F28FF4, 0x88F93406, 0x90725E51, 0x43E88021, 0xC540E6DD, 0xFF6CAD9F, 0x387B2173, 0x4C83E40A},
	{0x623ACD47, 0xE3E5A573, 0x407625B5, 0x4E6E4C86, 0x0F1BFF72, 0x4E482048, 0x59A40808, 0x0FB2A587} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x768258D2, 0x7101E114, 0x978549C2, 0xC7F8C4DB, 0x92B337C9, 0x74565BD1, 0x745D0386, 0x59AB509E},
	{0x66AE26FE, 0x3A6A110E, 0xC2CB7A98, 0x36C757DE, 0x298832AA, 0xB2D1D9F8, 0xD0E799AF, 0x81A23AE9} } ,
	 { {0x59B347EA, 0x53A3882A, 0x2D5E3B99, 0x57D6DDC7, 0x86CB46BA, 0xE25835B8, 0x91B7F3E5, 0x29175786},
	{0x60134BDB, 0x92083818, 0xB5A706B0, 0x165FB9D6, 0x4E7AF45E, 0xCA17C9B7, 0x01CF3166, 0x69E4DE3F} } ,
	 { {0xD3EA76DF, 0xEF84C6BC, 0xBDE376A2, 0x36DEEE2C, 0xA0D787D1, 0x367B6822, 0x4F5F6248, 0x2C17CCE9},
	{0x8BB173C2, 0x3B848EA6, 0x8F89E4DA, 0x8251D913, 0x6641F011, 0xD2130B5F, 0x8B70EAB2, 0xB589764D} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 759 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 760 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 761 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 762 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 763 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 764 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 765 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF12085DB, 0xAEDFD1C6, 0x6F847636, 0x7F01A524, 0xA0F920A8, 0xF527C2DA, 0xDC4A7E0F, 0x059621E9},
	{0xA7FD25A8, 0xF9C8A0EC, 0xF6A7AE46, 0x9B700959, 0x064191C5, 0xC0FFB1DE, 0x9C34C1F8, 0x43DB8A8A} } ,
	 { {0xFB71B28C, 0x63F058EF, 0x5EE2CC9A, 0x1C3B014B, 0x0B79BDDD, 0x47D54BC2, 0x996C1F92, 0x82A5F502},
	{0xD0A17742, 0x3AA3C59E, 0x2445F09D, 0x89B40497, 0x7445DD12, 0x11EEA8F7, 0xF92D0049, 0x80CC3F56} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF12085DB, 0xAEDFD1C6, 0x6F847636, 0x7F01A524, 0xA0F920A8, 0xF527C2DA, 0xDC4A7E0F, 0x059621E9},
	{0xA7FD25A8, 0xF9C8A0EC, 0xF6A7AE46, 0x9B700959, 0x064191C5, 0xC0FFB1DE, 0x9C34C1F8, 0x43DB8A8A} } ,
	 { {0xFB71B28C, 0x63F058EF, 0x5EE2CC9A, 0x1C3B014B, 0x0B79BDDD, 0x47D54BC2, 0x996C1F92, 0x82A5F502},
	{0xD0A17742, 0x3AA3C59E, 0x2445F09D, 0x89B40497, 0x7445DD12, 0x11EEA8F7, 0xF92D0049, 0x80CC3F56} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x61273D10, 0x64BB7C43, 0x57F213C8, 0xB0EAA1E5, 0xE2E6E1F1, 0xEB4BEF2F, 0x03CDCC0F, 0x79F9BC6D},
	{0x8E3102A8, 0xA9D9A8F9, 0xDD477FAE, 0xFBB35774, 0xC88790F8, 0xA17778A2, 0x703F490C, 0x98009B2C} } ,
	 { {0x504B9AD0, 0x16C130E0, 0xDF0AF07C, 0xE02F01E5, 0xDCA188F8, 0xE76CAA59, 0xF0B4EDCD, 0x89ED1A76},
	{0xB0CB4E39, 0x9C71A65A, 0xAEDBC744, 0x1560EA9E, 0x69490AC5, 0x563F393B, 0x906480A8, 0xAE173CC3} } ,
	 { {0xF3D5E84C, 0x1C3D4303, 0x9882DE2B, 0x50A62ED9, 0xF6185274, 0x56709B48, 0x5810BA15, 0x65E8540B},
	{0xB929834E, 0x93788F1F, 0xB980A0FE, 0x4E5FA9E6, 0xBAE82CE6, 0x5DBADA11, 0xB63EFCDE, 0x373F67C4} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 766 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 767 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 768 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 769 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 770 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 771 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 772 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x90DE0786, 0xFA9CB06D, 0x5768B70F, 0x9A0C4E40, 0x76C5FA24, 0xED906652, 0xE6BDC6FC, 0x7E046EB4},
	{0xB172800E, 0x887CA668, 0x405033A0, 0x50D919E0, 0x8BCB637A, 0x82963414, 0x010DA695, 0x80DC0EBB} } ,
	 { {0x965A0747, 0x0CF50BB6, 0x596C57F8, 0x3C78D173, 0x5FD791E2, 0xBBB2F8EB, 0x7B30A0DA, 0x5E616320},
	{0xC1DFB6FB, 0x0EABADB0, 0xB1E8EED9, 0xB8F93FBC, 0x64C6E0F2, 0x88BDB36C, 0xE3534EE2, 0x65089343} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x90DE0786, 0xFA9CB06D, 0x5768B70F, 0x9A0C4E40, 0x76C5FA24, 0xED906652, 0xE6BDC6FC, 0x7E046EB4},
	{0xB172800E, 0x887CA668, 0x405033A0, 0x50D919E0, 0x8BCB637A, 0x82963414, 0x010DA695, 0x80DC0EBB} } ,
	 { {0x965A0747, 0x0CF50BB6, 0x596C57F8, 0x3C78D173, 0x5FD791E2, 0xBBB2F8EB, 0x7B30A0DA, 0x5E616320},
	{0xC1DFB6FB, 0x0EABADB0, 0xB1E8EED9, 0xB8F93FBC, 0x64C6E0F2, 0x88BDB36C, 0xE3534EE2, 0x65089343} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x6026A7F7, 0x08FE8DD6, 0xB22EFF52, 0x6DFD4CE7, 0x1359A32D, 0xA2BB7D8A, 0xA1F6AAFD, 0x0A6FB1D6},
	{0xEFAE8AE5, 0xE4F3859D, 0x34340991, 0xFBE4E61D, 0x2F964D10, 0x6FF7BD15, 0x37A464E7, 0x1048C656} } ,
	 { {0xC476EF6B, 0xEE662EBE, 0xF1AE702B, 0x8C835579, 0xB4402432, 0x7FE7E75E, 0x3BE2137F, 0x3E0B0D36},
	{0x694CAD0C, 0x4B2415B5, 0x566CCDD8, 0xAA885477, 0xE5A3076E, 0xFDD45A39, 0xE4DC9F6D, 0x38BC3512} } ,
	 { {0x6DCC2746, 0x74B81664, 0x7F725952, 0xA3CACAB0, 0xB0FBBD87, 0xDF4EA499, 0x1EF402D7, 0x3BA73C61},
	{0x0782C4E0, 0x86D88229, 0x0DE3077A, 0xA42E285E, 0x41E6E5C8, 0x1D333AE6, 0xCDC1B88D, 0xB9899F64} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 773 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 774 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 775 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 776 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 777 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 778 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 779 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x2BD05F94, 0x19E2F287, 0x5EBECA7A, 0x4926A24E, 0x69181CD6, 0xDD53B574, 0xA6E3E999, 0x7A99B371},
	{0x86F8B6D6, 0x32DBA4A6, 0x70F6F0CF, 0x25ED8A55, 0x492A14CE, 0xD5F2B107, 0xE6E32CA7, 0x9BBCBD2B} } ,
	 { {0x2C69CA9B, 0xC4AE6AB3, 0x049B84E4, 0x31EADA2E, 0x59194D46, 0x45AD6ADE, 0xE3427714, 0x5E7D4A7B},
	{0x034A3A83, 0x83348438, 0x1278D105, 0xD7F0F519, 0x66A82623, 0x9943072D, 0xC826203C, 0xA4DF14FE} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2BD05F94, 0x19E2F287, 0x5EBECA7A, 0x4926A24E, 0x69181CD6, 0xDD53B574, 0xA6E3E999, 0x7A99B371},
	{0x86F8B6D6, 0x32DBA4A6, 0x70F6F0CF, 0x25ED8A55, 0x492A14CE, 0xD5F2B107, 0xE6E32CA7, 0x9BBCBD2B} } ,
	 { {0x2C69CA9B, 0xC4AE6AB3, 0x049B84E4, 0x31EADA2E, 0x59194D46, 0x45AD6ADE, 0xE3427714, 0x5E7D4A7B},
	{0x034A3A83, 0x83348438, 0x1278D105, 0xD7F0F519, 0x66A82623, 0x9943072D, 0xC826203C, 0xA4DF14FE} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7E421AC5, 0xB56ABFE4, 0x8A291974, 0xFBDBB2D2, 0xDED9242C, 0x26B01C6B, 0x821924A8, 0x5E9DD90B},
	{0x5762204C, 0x9A021E57, 0x3EA24F33, 0xF010A6E1, 0x6EE7F616, 0xCCD34B83, 0x5931C3F8, 0x3515CAC4} } ,
	 { {0xAFEEF1BE, 0xEDFDF860, 0xF7EAEF49, 0x664FE10F, 0x96549F12, 0xBD1F7C78, 0x2FAD5972, 0x49A0204B},
	{0x2AA345E0, 0xADF72EA4, 0x47C20E78, 0xD2D35FEF, 0x7C118303, 0x14DBB3DF, 0xD332B9EA, 0x1F2D1054} } ,
	 { {0xB3CB9516, 0x78D6703C, 0x976E2355, 0xD214573B, 0xCA6090F8, 0x31889C56, 0x4228BFEB, 0x848914BA},
	{0x4B76C7A1, 0x614F1A6B, 0xA02A95C5, 0xCA75F27D, 0x619FCC17, 0xBE24390B, 0xE6B26FF1, 0x832DEE35} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 780 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 781 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 782 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 783 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 784 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 785 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 786 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x2BFC0375, 0xC83E5C71, 0x2C62A44F, 0x93A05205, 0xB92CBE0C, 0x5EB2A8A7, 0xDFCDFA70, 0x385C9FA1},
	{0x4479258A, 0x80159CDC, 0x5A05838F, 0x6EEF1B35, 0xA8D1CD19, 0xC393FFB0, 0xFE787458, 0x0C37CABF} } ,
	 { {0x09314448, 0x299D3B2D, 0x704D2FA3, 0xA66C9B42, 0x2AF07D02, 0xB1375CE9, 0x2E25A9A3, 0x3AC036A5},
	{0x2C7BEB4B, 0x6B3076B6, 0x2B6D6702, 0x1DDF40E3, 0xD1FAECD4, 0x7C40F08B, 0xB06D046B, 0x22FBB4E0} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2BFC0375, 0xC83E5C71, 0x2C62A44F, 0x93A05205, 0xB92CBE0C, 0x5EB2A8A7, 0xDFCDFA70, 0x385C9FA1},
	{0x4479258A, 0x80159CDC, 0x5A05838F, 0x6EEF1B35, 0xA8D1CD19, 0xC393FFB0, 0xFE787458, 0x0C37CABF} } ,
	 { {0x09314448, 0x299D3B2D, 0x704D2FA3, 0xA66C9B42, 0x2AF07D02, 0xB1375CE9, 0x2E25A9A3, 0x3AC036A5},
	{0x2C7BEB4B, 0x6B3076B6, 0x2B6D6702, 0x1DDF40E3, 0xD1FAECD4, 0x7C40F08B, 0xB06D046B, 0x22FBB4E0} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3ECFF17B, 0xBD8E2A49, 0x357949D3, 0x4D419156, 0x53EE9785, 0x2498FB42, 0x6BFA9338, 0x325843B6},
	{0xAE16347E, 0x8405C9C5, 0x71F44970, 0x1A041F8C, 0x5AEC7279, 0xB8081C7E, 0x7C15D644, 0x43ED8942} } ,
	 { {0x2CE27B25, 0x2CAB88EF, 0x1517AD59, 0xA09E8BF9, 0xB0C29931, 0xDACF99D5, 0x660EEA8A, 0x03D5DDED},
	{0x5B9CE58B, 0x2B74F690, 0xB1956EEB, 0x494D7043, 0xF79E3880, 0xCD391B28, 0xBB113BC3, 0x8EC137F5} } ,
	 { {0xD49ACC8E, 0xD999DCC0, 0x6AA428CD, 0x5B394A74, 0x708DD954, 0x41240943, 0xCFEBE42A, 0xB9AADE3C},
	{0x37972894, 0xA8FF8D6A, 0x6F0BC931, 0x89B9B453, 0x07AB7C37, 0x653EEF08, 0x896A960A, 0x185A4CF9} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 787 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 788 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 789 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 790 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 791 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 792 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 793 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5DC35560, 0xAB046063, 0x90377DF7, 0x3F6A7C90, 0x1A6CFC94, 0x470F2C32, 0x2F8122AA, 0x907FDF23},
	{0x306DE831, 0x366CE99D, 0xD5E7E3AA, 0xEDA807D1, 0x947DCD88, 0x0D38BBB2, 0xADF7BE6B, 0x862624EC} } ,
	 { {0x650DED03, 0xDC6FE3C4, 0xC5926261, 0x9B197FCA, 0xBE5BA94E, 0x7247975E, 0x595BCA7B, 0x271B1806},
	{0x0729CB09, 0x4D5C07E7, 0xD267D49E, 0x2311103B, 0xDD2F2CEF, 0x831A0E49, 0xD4ED8A7D, 0x4CDDE3DA} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x5DC35560, 0xAB046063, 0x90377DF7, 0x3F6A7C90, 0x1A6CFC94, 0x470F2C32, 0x2F8122AA, 0x907FDF23},
	{0x306DE831, 0x366CE99D, 0xD5E7E3AA, 0xEDA807D1, 0x947DCD88, 0x0D38BBB2, 0xADF7BE6B, 0x862624EC} } ,
	 { {0x650DED03, 0xDC6FE3C4, 0xC5926261, 0x9B197FCA, 0xBE5BA94E, 0x7247975E, 0x595BCA7B, 0x271B1806},
	{0x0729CB09, 0x4D5C07E7, 0xD267D49E, 0x2311103B, 0xDD2F2CEF, 0x831A0E49, 0xD4ED8A7D, 0x4CDDE3DA} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x98A5E4DE, 0x5A575ECA, 0x3184ED1C, 0x2BFA6D0A, 0x63B407E7, 0xAB6EC527, 0xB6F5BF0E, 0x3FD55D02},
	{0x9A251E2B, 0xCC5D53A1, 0x57F75697, 0x9DAD194A, 0xBBEC18BF, 0xB26763BA, 0x5AF6FF30, 0x4717A213} } ,
	 { {0xA4DABE9D, 0xAF5BAB69, 0xFC969927, 0x6D9CB898, 0x01E8CC4E, 0xFC21B38B, 0x297756EF, 0x674D15F4},
	{0x443624D6, 0xE8A1E91B, 0xFB7E3909, 0x4801EB20, 0x737AA5F0, 0xB5E95E53, 0x74401787, 0x3D2516E1} } ,
	 { {0xDFFA87BD, 0xA7CBA4A8, 0xF8FB8B55, 0x9F836BAB, 0xC979D908, 0xE9DA02B1, 0x4C61C981, 0x058F9F36},
	{0x365E34C0, 0xA9374ED5, 0x4D1AEA23, 0xBD929E30, 0x151377B4, 0x4E782FB1, 0x6B07672D, 0x61D70C9B} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 794 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 795 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 796 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 797 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 798 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 799 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 800 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xE8592003, 0x89E0FF55, 0xB41F78DA, 0x86875BD0, 0x4641BE3E, 0x625BDD24, 0x5BA90A66, 0x26172EB6},
	{0x2EF1DA9F, 0x591296A6, 0x4BDEADF4, 0x72357B30, 0x7C6F2D24, 0x20E4B2DF, 0x9A556D88, 0x532E58E1} } ,
	 { {0x4BCD7E62, 0x4B73DD28, 0x7062EBE9, 0xD03D80C8, 0x12076E26, 0x1993C72A, 0x9686ADA3, 0x8A3B55EC},
	{0xC1BA5017, 0xDFE54A02, 0x4B6D09B1, 0xE361822A, 0x1BD25FCD, 0x1669B24E, 0x0C1ACCA5, 0x60B03DE2} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE8592003, 0x89E0FF55, 0xB41F78DA, 0x86875BD0, 0x4641BE3E, 0x625BDD24, 0x5BA90A66, 0x26172EB6},
	{0x2EF1DA9F, 0x591296A6, 0x4BDEADF4, 0x72357B30, 0x7C6F2D24, 0x20E4B2DF, 0x9A556D88, 0x532E58E1} } ,
	 { {0x4BCD7E62, 0x4B73DD28, 0x7062EBE9, 0xD03D80C8, 0x12076E26, 0x1993C72A, 0x9686ADA3, 0x8A3B55EC},
	{0xC1BA5017, 0xDFE54A02, 0x4B6D09B1, 0xE361822A, 0x1BD25FCD, 0x1669B24E, 0x0C1ACCA5, 0x60B03DE2} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x2D1E7388, 0x6F8A1E0E, 0x032CA070, 0x56B0BB48, 0x7F59542F, 0x144FCFC4, 0x68FDF3BB, 0x4A057497},
	{0x7A219751, 0x5F6EC979, 0x1E2E53A2, 0xF6FD0C99, 0x5BDF6805, 0xD37083D5, 0x9439F7E9, 0x96B22153} } ,
	 { {0x673BAEED, 0x3E405318, 0x0E6E8210, 0xD62A7D37, 0xC60F48B8, 0xCD577D71, 0x74E19849, 0xB0CD6CB2},
	{0x733535B4, 0xE2709A35, 0xBB98BD02, 0x94CBD6FB, 0xB7BCD9AF, 0x4A5114CB, 0x050D91A8, 0x4D41C494} } ,
	 { {0x0EC86789, 0xEC30338F, 0x06FA9A18, 0xCB8EFE06, 0x8B411F99, 0x767B2E5F, 0x3213FE0E, 0x275801FE},
	{0xC099AB01, 0x83AD7EFE, 0x8D590995, 0x76DA3A08, 0xB0FA2346, 0x2849C283, 0x539CCEA9, 0x50DFED14} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 801 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 802 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 803 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 804 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 805 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 806 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 807 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF0854DDB, 0x4208A3E3, 0x03A856E8, 0x682F60E9, 0x436109CB, 0x3B136ACF, 0xB5C35342, 0x2DCB5666},
	{0x04E64B41, 0xB99D7A11, 0xE552C222, 0x884BFD3A, 0x1506B9FA, 0xF6CB1405, 0x408B0E2A, 0x21D016EF} } ,
	 { {0x08389E74, 0x5BE60557, 0xA52BDECE, 0x2CBA7FAC, 0xA0328528, 0x67DD5735, 0x5C7AA382, 0x56F16A0C},
	{0x9AD674FD, 0xABBB93A0, 0xCFD5DB58, 0x4A9FCA73, 0x65C4EB1B, 0x4EB44C26, 0xE5F6FB44, 0x89EE6424} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF0854DDB, 0x4208A3E3, 0x03A856E8, 0x682F60E9, 0x436109CB, 0x3B136ACF, 0xB5C35342, 0x2DCB5666},
	{0x04E64B41, 0xB99D7A11, 0xE552C222, 0x884BFD3A, 0x1506B9FA, 0xF6CB1405, 0x408B0E2A, 0x21D016EF} } ,
	 { {0x08389E74, 0x5BE60557, 0xA52BDECE, 0x2CBA7FAC, 0xA0328528, 0x67DD5735, 0x5C7AA382, 0x56F16A0C},
	{0x9AD674FD, 0xABBB93A0, 0xCFD5DB58, 0x4A9FCA73, 0x65C4EB1B, 0x4EB44C26, 0xE5F6FB44, 0x89EE6424} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x07B68470, 0xFD145DD9, 0xE3E3169B, 0x2BE8FCE4, 0xAA328C0E, 0x838B286B, 0x0AC96AF8, 0x81522F18},
	{0x8CE64A51, 0xF511E7E6, 0x546467F6, 0xA0D82C58, 0x3CCCD62D, 0x5DE6813D, 0xE46602D1, 0xA22ABD5F} } ,
	 { {0x0F5FD6C4, 0x5DCB34FA, 0xA969FB28, 0xB6E4529E, 0x24F9A236, 0x7A5A3647, 0x7DE03498, 0x84577334},
	{0x128FF5ED, 0x12B1CE52, 0x54E4E2B6, 0xE09DFC3B, 0x29D94690, 0x86D21DA4, 0xFA2EAC0B, 0xB37D45D9} } ,
	 { {0x7CDD7BF9, 0x4B030FB9, 0x60796ACA, 0x691D99D6, 0x976CAFBC, 0x1D694324, 0x5F5CEB6B, 0xB8997DED},
	{0xE8DFB583, 0x7486F5B7, 0x91354C17, 0x688FB622, 0x65C75D4A, 0xE8C1AB6F, 0xCC68EB9E, 0x6BFCECAE} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 808 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 809 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 810 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 811 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 812 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 813 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 814 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9AEBD49A, 0xAE417EB1, 0xA90D3484, 0x9C8191AF, 0xB1BF8E57, 0x4BFBCD93, 0x5DC548D0, 0x3ADF2899},
	{0x15A583CE, 0xB6FA9D99, 0x96D0AACC, 0x71244258, 0xAA3BB8AF, 0x859FEE52, 0x10191929, 0x74ABC90B} } ,
	 { {0x2B473AD1, 0xDA294016, 0x89400809, 0xA2870A2C, 0x729130FA, 0x06DEAE03, 0x1591BA08, 0x37839B9F},
	{0x82667B5A, 0xA08B5C50, 0x32F082B4, 0x18882D73, 0x6B565BB0, 0x3E1F2052, 0xCAFF173A, 0xA7F167F6} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x9AEBD49A, 0xAE417EB1, 0xA90D3484, 0x9C8191AF, 0xB1BF8E57, 0x4BFBCD93, 0x5DC548D0, 0x3ADF2899},
	{0x15A583CE, 0xB6FA9D99, 0x96D0AACC, 0x71244258, 0xAA3BB8AF, 0x859FEE52, 0x10191929, 0x74ABC90B} } ,
	 { {0x2B473AD1, 0xDA294016, 0x89400809, 0xA2870A2C, 0x729130FA, 0x06DEAE03, 0x1591BA08, 0x37839B9F},
	{0x82667B5A, 0xA08B5C50, 0x32F082B4, 0x18882D73, 0x6B565BB0, 0x3E1F2052, 0xCAFF173A, 0xA7F167F6} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x334CABBD, 0xC125DE5C, 0xFA9EF27E, 0x38C5CE8F, 0xF2BC5E32, 0x9176AF03, 0x132189DE, 0xA34D0506},
	{0x5A5A314D, 0x6B5658AF, 0x24766A47, 0x3B85AADE, 0x2A68609D, 0x1C3CF165, 0x76125466, 0x42F6FF88} } ,
	 { {0xF3EEB40E, 0x08126F25, 0xFF817EAE, 0x3C8C984B, 0xBE82D5D6, 0x857B26DF, 0x5AA7C36D, 0x37AABDDD},
	{0xDF50D65E, 0x433A4AE7, 0xCA0E7ABD, 0xA94A8BAE, 0x33DAF7F7, 0x961E9105, 0x9696555A, 0x09B12974} } ,
	 { {0x80C53C3F, 0x33860034, 0xEF427C39, 0xAAFBF249, 0x94275471, 0xBAC36C2F, 0xEC684E50, 0x6EE44A1A},
	{0x0900ABDB, 0x5EB3F5F8, 0x2DD4AE42, 0x0DDE1139, 0x8A788024, 0x91BA1F88, 0x517FC0A7, 0x5171FF53} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 815 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 816 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 817 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 818 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 819 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 820 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 821 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x91CD93E9, 0x9CB938CB, 0xBAF75AF5, 0x4E84F14B, 0xA9785703, 0x187B6EC5, 0x677665C6, 0x52FDCEB2},
	{0x1C5E0632, 0x0F378A70, 0x25B14D38, 0x9CEBE73B, 0x406F3070, 0xCBD24555, 0x7637A13B, 0x19AFE58C} } ,
	 { {0x966E827A, 0x9195CA92, 0x950FAADE, 0x49F5E2C8, 0x62327624, 0xF70CC932, 0x7DB752C9, 0x41A7983D},
	{0xF0A84498, 0x1EBC90D9, 0xDE1A2347, 0x7699A416, 0x5A77AFBE, 0xDF3ECF0D, 0xEAFE2385, 0x2B27899D} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x91CD93E9, 0x9CB938CB, 0xBAF75AF5, 0x4E84F14B, 0xA9785703, 0x187B6EC5, 0x677665C6, 0x52FDCEB2},
	{0x1C5E0632, 0x0F378A70, 0x25B14D38, 0x9CEBE73B, 0x406F3070, 0xCBD24555, 0x7637A13B, 0x19AFE58C} } ,
	 { {0x966E827A, 0x9195CA92, 0x950FAADE, 0x49F5E2C8, 0x62327624, 0xF70CC932, 0x7DB752C9, 0x41A7983D},
	{0xF0A84498, 0x1EBC90D9, 0xDE1A2347, 0x7699A416, 0x5A77AFBE, 0xDF3ECF0D, 0xEAFE2385, 0x2B27899D} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x53B5D5AA, 0xAF8DE9ED, 0xAB31EF4E, 0xABAFC363, 0x70974B56, 0x865EB5F7, 0x3D76AEE9, 0x6E6556BA},
	{0xCCC8D756, 0xBB6756B2, 0xF3F0BDA8, 0x6DCFAAD8, 0xDD2D2A29, 0x41E98E58, 0x598347A4, 0xB9393663} } ,
	 { {0x764F0FFA, 0x963F4F42, 0x1112CC08, 0x3B168D57, 0xEEB70D45, 0x3358E35E, 0x0E6F6801, 0x05A8AB5C},
	{0xD761BFFE, 0x8E72DB8D, 0x4C7DB2FC, 0x17D817CD, 0xD5980025, 0x9C33BE79, 0x57E6E4AE, 0xACEB75F8} } ,
	 { {0x94C4B8B7, 0xED518D40, 0x4C9E4E48, 0x30E4E489, 0x90F18547, 0xC45D60DE, 0xADC525DB, 0x0E8644E9},
	{0x9FD673CB, 0x1FBA2E04, 0xAA6E1D2C, 0x1317F4C3, 0x77AE36F1, 0x6378102F, 0xBE9661BF, 0x097BE58B} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 822 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 823 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 824 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 825 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 826 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 827 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 828 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x243104C9, 0xF7A0599A, 0x8B0C1824, 0x9B2F987A, 0x13E4CCD9, 0x93F8FC00, 0x0F72B6B6, 0x50F43B0B},
	{0x224A703D, 0x4F0FFC32, 0x510DBD1C, 0x03BAFD69, 0x6BDBBEEE, 0x8A4A82B1, 0x344AF376, 0xB329B888} } ,
	 { {0x2975984E, 0xF0361229, 0xB39A3CEA, 0x8283EB29, 0xC7390467, 0x92CA97B2, 0x7EA91D82, 0x3BC65B51},
	{0x81901CB1, 0x8C359850, 0x1FD98581, 0xE270A3A4, 0x909E2209, 0xA5AD2009, 0xB1BF2307, 0x2EC47E35} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x243104C9, 0xF7A0599A, 0x8B0C1824, 0x9B2F987A, 0x13E4CCD9, 0x93F8FC00, 0x0F72B6B6, 0x50F43B0B},
	{0x224A703D, 0x4F0FFC32, 0x510DBD1C, 0x03BAFD69, 0x6BDBBEEE, 0x8A4A82B1, 0x344AF376, 0xB329B888} } ,
	 { {0x2975984E, 0xF0361229, 0xB39A3CEA, 0x8283EB29, 0xC7390467, 0x92CA97B2, 0x7EA91D82, 0x3BC65B51},
	{0x81901CB1, 0x8C359850, 0x1FD98581, 0xE270A3A4, 0x909E2209, 0xA5AD2009, 0xB1BF2307, 0x2EC47E35} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x452357A2, 0xCDADC9E5, 0x6F5BB7C7, 0x0192E375, 0x6FE8538F, 0x18A9A696, 0x336B5817, 0x2D9E54BE},
	{0x432F725E, 0x297EB355, 0x18B467B9, 0xAE6A29EA, 0x27F31ADB, 0x8FEB21EE, 0xF291A15A, 0x3F1C339A} } ,
	 { {0xB0EF6534, 0xEADA4BCA, 0x96497997, 0xAE724C69, 0xE053B9F6, 0x3B968F2E, 0xE3F30151, 0x4564054C},
	{0x1E5BE5F3, 0x39801D1D, 0xFDDD89B1, 0x56F6D70A, 0x86F247C0, 0x0E75C424, 0x1E50A382, 0x7F7D07C7} } ,
	 { {0x1EAEC6D9, 0x3A442B95, 0xCF1088B3, 0x97229B00, 0xA63210E8, 0x0535B133, 0x99B598E5, 0x18E6D307},
	{0x3D1A1FD9, 0x977D3367, 0x6C63F2A3, 0xF2AC7A32, 0xC06E53A3, 0x58939964, 0x6DDDBC0B, 0x2A937C63} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 829 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 830 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 831 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 832 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 833 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 834 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 835 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA292150F, 0x95B2690E, 0x26862FA9, 0x55B2278B, 0xEE40D85B, 0xD639B9AF, 0xCB676B3D, 0x1C99A4AF},
	{0x0A43459C, 0x50C6EC91, 0x3987B87C, 0x662954C9, 0x1804DF63, 0xD3758961, 0xD472CA5C, 0x8AFF3CFD} } ,
	 { {0xA306F13E, 0x351B1F30, 0x4F7928F8, 0x7A5C24F5, 0x1D5E2722, 0xE411A1AF, 0x05C5CAC6, 0x4B89A8BB},
	{0xCE86A30F, 0xC5C9E672, 0xA0112188, 0x77AD23A3, 0xADD2A43E, 0xB8492FC3, 0x5F363342, 0x11A42AD5} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xA292150F, 0x95B2690E, 0x26862FA9, 0x55B2278B, 0xEE40D85B, 0xD639B9AF, 0xCB676B3D, 0x1C99A4AF},
	{0x0A43459C, 0x50C6EC91, 0x3987B87C, 0x662954C9, 0x1804DF63, 0xD3758961, 0xD472CA5C, 0x8AFF3CFD} } ,
	 { {0xA306F13E, 0x351B1F30, 0x4F7928F8, 0x7A5C24F5, 0x1D5E2722, 0xE411A1AF, 0x05C5CAC6, 0x4B89A8BB},
	{0xCE86A30F, 0xC5C9E672, 0xA0112188, 0x77AD23A3, 0xADD2A43E, 0xB8492FC3, 0x5F363342, 0x11A42AD5} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8BD5FA39, 0xFA6D1798, 0x87E1B0AB, 0x67E0D949, 0xEBFDBCFE, 0xCC9C5A66, 0xBA726C90, 0x342E6661},
	{0xF63F0CCD, 0x2734E38E, 0x96565630, 0xA9C0DA9F, 0xDAAD94B4, 0x623E70AD, 0x72AB920D, 0x4A013925} } ,
	 { {0xDA68F479, 0x8292871D, 0x99A97604, 0x226F65B5, 0x71E814B4, 0x10FE2F92, 0x4DA68653, 0x945F7771},
	{0xBC97E7EB, 0x6D7E7AB9, 0xB79F445E, 0x52C6A827, 0xF3ACD036, 0xC1856CE2, 0x39D25B97, 0x0D6BAB67} } ,
	 { {0x0396D4E0, 0x447C6C83, 0xFC1F4EDA, 0x1C9B70C7, 0xFADBEAE0, 0xE738510A, 0xDF9D08AA, 0x4BFE4B7B},
	{0x058B042B, 0x30B1D4FA, 0x605BD389, 0xBC384385, 0x42D52763, 0x68878BB6, 0x12466E1D, 0x99A8A813} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 836 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 837 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 838 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 839 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 840 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 841 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 842 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xD7156791, 0xCC750D74, 0xA2E0C2CD, 0xC25E3BD2, 0xF398281D, 0xB96BC79C, 0xF9B3D0AA, 0xAEF5D305},
	{0x4B65CFCD, 0xD7C0F1CE, 0x26D09848, 0x38FD584D, 0x342770E4, 0xF8DA68AA, 0x6F07814B, 0x1D58C594} } ,
	 { {0x23D6ACFA, 0x2C72D05C, 0x46D78061, 0xA354C5F9, 0x84F041F8, 0x655638D9, 0xBE9F7AE0, 0x4016FC21},
	{0x88935B81, 0x6916DE9F, 0x61076695, 0x0B6933CF, 0x5D3F81C8, 0x86D069A5, 0xA698A29F, 0x5F9614C6} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD7156791, 0xCC750D74, 0xA2E0C2CD, 0xC25E3BD2, 0xF398281D, 0xB96BC79C, 0xF9B3D0AA, 0xAEF5D305},
	{0x4B65CFCD, 0xD7C0F1CE, 0x26D09848, 0x38FD584D, 0x342770E4, 0xF8DA68AA, 0x6F07814B, 0x1D58C594} } ,
	 { {0x23D6ACFA, 0x2C72D05C, 0x46D78061, 0xA354C5F9, 0x84F041F8, 0x655638D9, 0xBE9F7AE0, 0x4016FC21},
	{0x88935B81, 0x6916DE9F, 0x61076695, 0x0B6933CF, 0x5D3F81C8, 0x86D069A5, 0xA698A29F, 0x5F9614C6} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xAF3332AF, 0xD59C0275, 0x9224146C, 0x52ABBF8F, 0xFE5C1B44, 0xEB906FD0, 0x0A334356, 0x54E8CD9D},
	{0x17D50C7A, 0x60C44079, 0x3B40DC50, 0x1EA5EE7D, 0x2EA3F44C, 0x97F3356E, 0x9BCCD9B0, 0x066C1349} } ,
	 { {0x58838B02, 0x334E1BBD, 0x87393900, 0x655EC595, 0x567F6A93, 0xB682FCBD, 0x3B21D26C, 0x1F7A125D},
	{0x8E2155B4, 0xF18304E7, 0xF851F659, 0xA5B7E7EE, 0x278EAEE4, 0xC1372BB3, 0x67B3FC33, 0x8BB52F69} } ,
	 { {0x1F4AAF25, 0x43CE143B, 0x1851AE3C, 0xB6F41D8B, 0x388D4A0D, 0xE5878184, 0xA6DA14E1, 0x947C3BD7},
	{0x63B7527A, 0xFC6B9FC3, 0x2B355664, 0x5EEEE5C3, 0xBF7B23B7, 0x63392D2C, 0xAC35CCCF, 0x1F402450} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 843 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 844 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 845 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 846 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 847 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 848 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 849 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5248EEA6, 0x1D41E627, 0xBC132239, 0x57A88C58, 0x95751003, 0xD80D5648, 0xCE83D411, 0x1BA21F39},
	{0xF5E61743, 0x305E3944, 0x62DE3E00, 0xB237186D, 0xDE361CC2, 0x41346089, 0x2CBDF491, 0xAFD6DE60} } ,
	 { {0x5866BA2A, 0x095C6A56, 0xAD62A99E, 0x376B2019, 0x7DCB37D1, 0x9AC03D96, 0xB515F11B, 0x744C1735},
	{0x6372E886, 0x5423357B, 0x94E4FFED, 0xC9DC3823, 0x4FCF03A9, 0x8BB52CAF, 0x8CD0E716, 0x1EFC5269} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x5248EEA6, 0x1D41E627, 0xBC132239, 0x57A88C58, 0x95751003, 0xD80D5648, 0xCE83D411, 0x1BA21F39},
	{0xF5E61743, 0x305E3944, 0x62DE3E00, 0xB237186D, 0xDE361CC2, 0x41346089, 0x2CBDF491, 0xAFD6DE60} } ,
	 { {0x5866BA2A, 0x095C6A56, 0xAD62A99E, 0x376B2019, 0x7DCB37D1, 0x9AC03D96, 0xB515F11B, 0x744C1735},
	{0x6372E886, 0x5423357B, 0x94E4FFED, 0xC9DC3823, 0x4FCF03A9, 0x8BB52CAF, 0x8CD0E716, 0x1EFC5269} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3FEA71D1, 0xCFB66EF4, 0x4F672697, 0xC9767773, 0xC5FA6FA6, 0xCFF14A42, 0xE1DC3EF7, 0xB582318A},
	{0x12B51811, 0x6EE726C1, 0xBB36E91D, 0x94BDD76A, 0x11028545, 0x15A488DD, 0x51775643, 0x79371479} } ,
	 { {0x79ED117D, 0x0052807B, 0x8690AA07, 0xC2AC7B0A, 0xF2E1558F, 0xF16CD879, 0x2BA138F8, 0x3A6440BB},
	{0x357F5AA5, 0xEC16CEC8, 0x4BDB6337, 0x9F3CA2A5, 0xC127EC57, 0x9F01A662, 0x976670DE, 0x59F90ABA} } ,
	 { {0xE1C70527, 0xCCEEC37F, 0xC352A3E7, 0xA3F47C78, 0x85EA490D, 0xCC7573C8, 0x3D93A41F, 0x2646C0BF},
	{0x8BAD0657, 0xCAB54D21, 0x03C5CBEC, 0xC74AC358, 0x919F9197, 0x472F7A54, 0xCEBFA693, 0xAF33C559} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 850 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 851 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 852 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 853 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 854 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 855 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 856 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF365D5E9, 0xC621A7A9, 0x20EA9DA2, 0xE749F3E8, 0x4FD719D8, 0xC77EDBB3, 0x3496B2DB, 0x6A6A9E4F},
	{0x2481F983, 0xE4D71A84, 0x83849503, 0xF05B4FF7, 0xF0306B15, 0xA08F6E74, 0x27B92877, 0x60AAFFBF} } ,
	 { {0x9870275C, 0xA09D5CE0, 0x53A1B88E, 0x146D95D3, 0x513D60AC, 0x768B3290, 0x808D80D5, 0x3AECD558},
	{0xC04C558B, 0x31771BD5, 0x72240E25, 0x861184BD, 0x9E8B47C5, 0xCBB3903D, 0x6D26B093, 0xB227F827} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF365D5E9, 0xC621A7A9, 0x20EA9DA2, 0xE749F3E8, 0x4FD719D8, 0xC77EDBB3, 0x3496B2DB, 0x6A6A9E4F},
	{0x2481F983, 0xE4D71A84, 0x83849503, 0xF05B4FF7, 0xF0306B15, 0xA08F6E74, 0x27B92877, 0x60AAFFBF} } ,
	 { {0x9870275C, 0xA09D5CE0, 0x53A1B88E, 0x146D95D3, 0x513D60AC, 0x768B3290, 0x808D80D5, 0x3AECD558},
	{0xC04C558B, 0x31771BD5, 0x72240E25, 0x861184BD, 0x9E8B47C5, 0xCBB3903D, 0x6D26B093, 0xB227F827} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0A0CB6B9, 0xCDF847D0, 0x50DE8ED9, 0xDD101E77, 0xC0880F51, 0x7CDF4F99, 0xF437C6EB, 0xAC8359D2},
	{0x49F93599, 0x378974FF, 0x66EB179D, 0x568D4B4A, 0xEF5B5BE3, 0xE589DF0F, 0x7BC454D7, 0x18642E85} } ,
	 { {0xE9F100EC, 0x959440ED, 0x3D7B2E0E, 0xECA2AC61, 0xD4DF5A2A, 0xA9DD2C6A, 0x3049339C, 0x7C54AA73},
	{0x30C0F9E6, 0x2EFA3DA1, 0x396299E4, 0x9821E2B0, 0x7B148FEB, 0xDB679FB8, 0x8F03B985, 0x5F4A4C69} } ,
	 { {0xD49E02C1, 0x47BC1DF0, 0x231FC6E6, 0xE79B9720, 0x3B135F40, 0xF438C88B, 0x40ADD935, 0x367633A1},
	{0x1BF0EC13, 0x0DA5327A, 0xD167D156, 0x18DD56B4, 0xFA62F0DF, 0x7423398C, 0xDFF36FBB, 0xAA4D90E0} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 857 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 858 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 859 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 860 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 861 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 862 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 863 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBE1E4D47, 0x4507CD75, 0x15DD9626, 0xE93D69B6, 0xC270583C, 0x31EA0829, 0x3BD51031, 0x07A2AABB},
	{0x5D45EC4F, 0x6E8D3CA7, 0xAC989E0C, 0x86FA49E8, 0x0326CBF2, 0xAC68167F, 0xDD483021, 0x6CB66194} } ,
	 { {0x4D73658A, 0x3985844B, 0x6B67CDCE, 0x84CA9E48, 0xD7CDC65A, 0x76C0B620, 0x9BC5A3EC, 0x6A4D294A},
	{0xDFBCDEB5, 0x6ADB807B, 0xC206CF85, 0x819DA253, 0xC6373064, 0x776DD020, 0x6BFF25E8, 0x60A660E3} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xBE1E4D47, 0x4507CD75, 0x15DD9626, 0xE93D69B6, 0xC270583C, 0x31EA0829, 0x3BD51031, 0x07A2AABB},
	{0x5D45EC4F, 0x6E8D3CA7, 0xAC989E0C, 0x86FA49E8, 0x0326CBF2, 0xAC68167F, 0xDD483021, 0x6CB66194} } ,
	 { {0x4D73658A, 0x3985844B, 0x6B67CDCE, 0x84CA9E48, 0xD7CDC65A, 0x76C0B620, 0x9BC5A3EC, 0x6A4D294A},
	{0xDFBCDEB5, 0x6ADB807B, 0xC206CF85, 0x819DA253, 0xC6373064, 0x776DD020, 0x6BFF25E8, 0x60A660E3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x5895E264, 0x230DCFE3, 0x46F11DAE, 0x286130F1, 0x41B9A516, 0x6FEBFA77, 0x98609893, 0x5121C1E7},
	{0x66368409, 0x3E4929DB, 0x39DBFF54, 0x762F4AA5, 0xB16C3CBA, 0x71DA2B5B, 0x0C636CF2, 0x96D0F13F} } ,
	 { {0x363ADCF5, 0xFA7CEC26, 0x4931CDF5, 0x6F46CED7, 0x0BDB6819, 0xE49DB78C, 0xB9A3CA77, 0x5C44BF6A},
	{0xA92A0973, 0x5B553832, 0x31E21143, 0xDC739CD7, 0x6D255607, 0x439CE0D4, 0x7B68BC70, 0x7F77F6F7} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 864 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 865 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 866 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 867 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 868 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x068F0573, 0x14F52929, 0x7AB5754F, 0xC832DCDD, 0xF65C204A, 0xBE7AE802, 0x6F579F64, 0x7B31A2A5},
	{0x8E68436B, 0xA46346AE, 0xE8C7E25E, 0x5A315DE0, 0x5A4F4A03, 0x28BCC12D, 0x8B845921, 0xB47FDF31} } ,
	 { {0x26FC2612, 0x7FC40222, 0xC7D54BBA, 0x31DD8521, 0xB724D002, 0xDF25BDCB, 0x27CC5D5B, 0x6825BC1F},
	{0x7B3EFF9B, 0xF7855D91, 0xB4328464, 0xA21FA708, 0x7B49726A, 0x6E21D9A4, 0xBCB31BEB, 0x3D26B2D9} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x068F0573, 0x14F52929, 0x7AB5754F, 0xC832DCDD, 0xF65C204A, 0xBE7AE802, 0x6F579F64, 0x7B31A2A5},
	{0x8E68436B, 0xA46346AE, 0xE8C7E25E, 0x5A315DE0, 0x5A4F4A03, 0x28BCC12D, 0x8B845921, 0xB47FDF31} } ,
	 { {0x26FC2612, 0x7FC40222, 0xC7D54BBA, 0x31DD8521, 0xB724D002, 0xDF25BDCB, 0x27CC5D5B, 0x6825BC1F},
	{0x7B3EFF9B, 0xF7855D91, 0xB4328464, 0xA21FA708, 0x7B49726A, 0x6E21D9A4, 0xBCB31BEB, 0x3D26B2D9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xBE509841, 0xD3B6B92B, 0x83450A39, 0xEF97EA10, 0x9CCDFFEB, 0x539B7376, 0x1BD6C3C2, 0x8549CA64},
	{0x04404D6E, 0x7CCC7C15, 0xB21E1763, 0x74829B6D, 0x8905945C, 0x4609C254, 0x590781E3, 0x37712036} } ,
	 { {0x92F1740D, 0x3B88FAD3, 0x4F2F91B5, 0xA56A578F, 0xCC3DC340, 0x60826B4C, 0x605BE52A, 0x2A0592B3},
	{0x9170C8CC, 0xC94AC200, 0x1E8A8319, 0xF87098FE, 0x2476AC27, 0x09B6DEA6, 0x8E67D471, 0x27E9CF8B} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 869 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 870 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 871 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 872 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 873 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x017EFDC9, 0xF6F89C59, 0x2F69C264, 0x550929A1, 0xD51718B5, 0xEE471AFF, 0x0DA46AD6, 0x8FE9C5BF},
	{0x7E8241C5, 0xFE3156B0, 0x2E77F1D9, 0x525DC8D7, 0x8DA9C1A4, 0x2F6D6F1A, 0xC1B58D49, 0xA7D33A05} } ,
	 { {0xB5071DBB, 0x821DA121, 0xA518FC2E, 0x2765F42C, 0x8D650BD2, 0xC8E2820A, 0x99BB8984, 0x7E62C0AB},
	{0x8CC127C4, 0x91A70051, 0xFF32692E, 0xC3A9C95A, 0x2394D938, 0x69AE1E9C, 0x441848BE, 0xACE7F528} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE087DFC3, 0x140849DB, 0xEEFD2CE2, 0x28BE4517, 0x8BC79E2D, 0x72D46801, 0xCD28565A, 0x452087E6},
	{0x836A17B6, 0x5C2DCFED, 0x76413CDE, 0x3A6F6E04, 0xD17C1AA1, 0x278B1DC8, 0x7D31D296, 0x9250AA75} } ,
	 { {0xD69F70DA, 0x8C64DBF6, 0x32F33419, 0x7B3CF97D, 0x4A2E3058, 0x53860A2F, 0xE3EE7178, 0x996FECF3},
	{0xC2E224E8, 0xDB4FF011, 0xA9F57C73, 0x100DDB33, 0xD779A614, 0x2C64B765, 0xDAF8FEA9, 0x9FF00B56} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 874 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 875 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 876 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 877 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 878 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0234CC5D, 0x63C86CA8, 0x15128284, 0xE39A373E, 0x8360AB80, 0x5DCB1293, 0xB7A8F09D, 0x26EE965F},
	{0x49168AEF, 0xF48C342F, 0xBFFE705D, 0xA146A8A7, 0xF0C98EE3, 0xEFD3200B, 0x6173CD00, 0x7738DA37} } ,
	 { {0xE2321333, 0x576B33E3, 0xFA42E0A4, 0xF56CAB2A, 0x8E46D9F6, 0x1EA83471, 0xF5E1A325, 0x3AE41406},
	{0x6F3511C1, 0xCDE26CE1, 0x8420AE71, 0xB7568D2B, 0x07FF8A66, 0xBDF276FC, 0xE5EFFC20, 0x42C0C6BF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x437F3394, 0xE8B337E4, 0xA8D51A9E, 0x962548E9, 0x5CA77B51, 0xE4F34E5F, 0x5247C597, 0x571B3DC8},
	{0x09BC6347, 0xCB9E9EDB, 0x3F67B460, 0x3713F923, 0x428AE553, 0xDAE64948, 0xDD6DA919, 0x06DC91FA} } ,
	 { {0x4FB01AF4, 0x0073E3AE, 0xFF037381, 0xB9A2F8CD, 0x29FC1706, 0xE633086A, 0x3261FEE4, 0x5698C26C},
	{0xE0A3B688, 0x4DE97E0D, 0x8D881607, 0x35CD4AAE, 0xFA367FFE, 0x844BBAD1, 0xF6F73323, 0xAD101C0E} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 879 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 880 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 881 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 882 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 883 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1001781D, 0x7EA1E570, 0x777D08E6, 0x2D7D555B, 0x85315E22, 0x105A3163, 0x47291C38, 0x96270A75},
	{0xA6833B35, 0x756C2B20, 0x4C06E57B, 0x203C1601, 0x1537FE58, 0xD5139135, 0x151B8E6A, 0x9085C8EA} } ,
	 { {0x211CC75D, 0x3D8E5FCA, 0x332B9A2D, 0x9806CB0A, 0xE066EC4E, 0xB454FDBF, 0x6BF1EDC1, 0x5A3F2B07},
	{0xD2F60F77, 0x34F1D755, 0xBD5D699B, 0x031C2CF4, 0x984786C4, 0x755137ED, 0xA7F364B5, 0x3BD8ED97} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x58661808, 0x7026161C, 0x2113FE0F, 0x3838D123, 0x29E371C6, 0xB9A41F81, 0x51512124, 0x67CB2EF9},
	{0x9A27526A, 0xAB52EDAE, 0xCC38341E, 0x55384AC1, 0xF1B7EC38, 0xBCD6255A, 0xD1497274, 0x9F3D6946} } ,
	 { {0xAE970796, 0xD41E4065, 0x624F479A, 0x1D0227E9, 0xD546EE45, 0x3F296C05, 0x610617B1, 0x5A0FB88A},
	{0xD5C5C2EE, 0xF6B352E4, 0x0F602A25, 0xCDD71C96, 0x688DEB32, 0x80B29083, 0x1B687CB0, 0x190B1DC9} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 884 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 885 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 886 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 887 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 888 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x184A6B21, 0xFCA682B5, 0x43C86786, 0x985B6A33, 0x30377257, 0xC261B4E7, 0x871A1156, 0x26635C36},
	{0x6A4550DA, 0xB52C8893, 0xD62D64B4, 0xF2E00E22, 0x38D79867, 0x41D502B4, 0x0CF04C6A, 0x9C187F5F} } ,
	 { {0xA1E2EB5A, 0xA3BA0E29, 0xCD36C354, 0x53FF97A9, 0x62CAA974, 0xE4052D1E, 0xC9DC3D0B, 0x31D044FF},
	{0x77C45F08, 0x7AFDD4C0, 0x6226E086, 0x55BE90D3, 0x6B953CBF, 0x5B894E53, 0x6DABE4E0, 0x78899AFD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xCB11326E, 0xB6A8A2EA, 0x44453E0C, 0x64E3CAC6, 0xA49C7413, 0x2C1EEAC6, 0xE2C73A27, 0x0449E3AD},
	{0x734FFF75, 0x5FD55960, 0x6E40343C, 0x9C97F1E2, 0x779EB8CF, 0xB9A352B1, 0xA7106E05, 0x6CA90890} } ,
	 { {0x3AA4E1C2, 0x26DAC0DD, 0xAE3D0823, 0x2D429B78, 0x7E2D2C01, 0x882A846A, 0x68ECDDBD, 0x707752FA},
	{0x40B79F0D, 0x53DE020B, 0xC0440BE4, 0xBD772647, 0xA7193C18, 0xD64BAA3B, 0xE29FE3A9, 0x8BECC96D} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 889 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 890 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 891 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 892 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 893 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFF0136DC, 0xD3569333, 0x0495BCFF, 0xC9C0180A, 0x513E294F, 0xD92BE1EE, 0x715BCB2A, 0x3C152856},
	{0x1E69B8AF, 0x0289B012, 0x843D07E7, 0xBCFE9507, 0xDE99F295, 0xF55EFAD6, 0xD9863623, 0x735549CB} } ,
	 { {0xB8F63070, 0xDAD79CFB, 0xB5937E62, 0xF3BA3512, 0xBC43D65B, 0x1AEBA8EC, 0x3625609C, 0x236992AE},
	{0xB552EC98, 0x7B724637, 0x6C6C7707, 0xE554C7B4, 0x16172F84, 0x96185006, 0xF2C62B50, 0x5C2B8E6A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x32BAF2CE, 0x720B1056, 0x0CEABA2E, 0xBA77F0F8, 0x490F01DD, 0xC8012594, 0x8218F7A8, 0x397531FA},
	{0x203224E9, 0xEC1677BE, 0x34E73FB6, 0x5F897E3A, 0xE6AB8F42, 0xDAD56DC1, 0x261FA59C, 0x3735DAA0} } ,
	 { {0x16119118, 0xB812B040, 0x13F7D9FC, 0x1AEEAE41, 0x433EB93F, 0x170C15B1, 0x0F02FBB2, 0x928A7BEE},
	{0x79ED7D50, 0x85332541, 0xB6AA105B, 0x334D570E, 0x530B07E9, 0x8DC1EDB7, 0x025B3AEE, 0x3D3321BD} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 894 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 895 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 896 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 897 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 898 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x64CE47AF, 0x23954ECB, 0x4446FCB2, 0x61203531, 0xA5BE442F, 0xCDF8F2AD, 0x88A025CB, 0x9C155750},
	{0xB9BE5A99, 0x5A6AE855, 0xA484EC8E, 0x20DDF7AF, 0x2945193D, 0x3B2A9339, 0xE0ED10B5, 0x0FB6F855} } ,
	 { {0x89F13B98, 0x2DB770C4, 0xEB4B69FE, 0xF1D68003, 0xB1B1B144, 0x2C741915, 0x410F5F61, 0x06DFB39B},
	{0xC11FE6ED, 0x903FE1A7, 0x670A9A0B, 0xCCB2EAF7, 0x361E58C3, 0x3C567458, 0x05B8FA28, 0x86754C8F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x276241DE, 0x53D96C62, 0xCDCF8017, 0x07D4D3D8, 0xC2411A06, 0x8FF7BC9D, 0x1CC59CCF, 0x24F4E84F},
	{0x4CDEBD88, 0xAD558628, 0xA3B14926, 0x6A975260, 0x2E993CDA, 0x247E57D4, 0x13A7EFC9, 0x3F9A4821} } ,
	 { {0x95A4AF34, 0xC71557B4, 0x35D97AF9, 0xDACAE65C, 0x87E12ECE, 0x05BC4076, 0xC0022AF1, 0x68D8CACC},
	{0xDDFE66D9, 0xFBBBBCEB, 0x14FAB2D0, 0x3391359A, 0x412AFD25, 0xB465B6FE, 0xD8AAEB60, 0x2F9F17B4} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 899 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 900 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 901 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 902 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 903 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x15581207, 0x770CA757, 0x40A5E818, 0x41171172, 0xEF177841, 0x52FBAFD6, 0x0AFF48BF, 0x1E93EF91},
	{0xAF32C1CA, 0x48B9EAA8, 0x2CA8FABE, 0x6E29EED5, 0x743D4838, 0x246C3F8C, 0x31A9C778, 0x734C95FF} } ,
	 { {0xD2BE5B93, 0x517764B9, 0xA693F23C, 0x7F8A8680, 0x0290C122, 0x2C03639C, 0x93AD92BC, 0x6EB5FF85},
	{0xA4FC5FA2, 0x31FF4B3C, 0x8ADCDBAB, 0x57C26D20, 0x51CB3458, 0x50E10EAD, 0x154760C9, 0x94F12727} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x4908D483, 0x0F420EC5, 0xB2B39499, 0x813503E3, 0x6498C570, 0xD79A0E73, 0x8753FE0F, 0xA01F21BA},
	{0xC5C33FAD, 0xA95EC76D, 0xA71A71D4, 0x89557D66, 0xFFD0D716, 0xDF3A584D, 0xAD1D7B5E, 0xB13EB873} } ,
	 { {0x99C0E3A4, 0x68CBD5D9, 0x7F483A51, 0x66D254ED, 0x45644320, 0x41400EF8, 0x330BB861, 0x5871D3EA},
	{0xD4FB4B07, 0xF9B7D23C, 0xCFD201CB, 0x51CFB4C5, 0xFC5A7120, 0x15D33AE1, 0x90DC6735, 0x7F8F7B1E} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 904 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 905 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 906 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 907 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 908 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x339A7254, 0xE6B1BE20, 0xCDE62F83, 0x73A3FE9E, 0xD4364CD8, 0xAC5418C9, 0xBC6FCC94, 0x0A45589B},
	{0x7B2FEB9A, 0xB4450E4C, 0xAAF0F641, 0xEC1D014F, 0xA69DF267, 0x43CA93B9, 0x3AA2BC64, 0x87025BA9} } ,
	 { {0xFE48AC2C, 0x4CE49A36, 0x879BF8F7, 0x02B7AD3D, 0x3EC85F10, 0x95304E60, 0xF9FA3FFC, 0x577C94E8},
	{0x6C20B7AB, 0xB261B5EF, 0xCEB7C444, 0x8D181EB3, 0x70BF745A, 0xB0D6BF9A, 0x8B646DAC, 0x71AB75C3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE1DA5B82, 0x5C9142F1, 0xA93E17E8, 0x77E8036B, 0x6FC23D41, 0xC1C4E0FA, 0xAC501D01, 0x1A32CC67},
	{0x9977266C, 0x6F32F2D9, 0x90F9AFA0, 0x28874D31, 0x85FCABF7, 0x52402782, 0x99B4D026, 0xB94D3D43} } ,
	 { {0xD69D56D8, 0xC458BC09, 0xC04102F1, 0xACE31B6C, 0x17D7ED1E, 0x718BAB42, 0x604D6E8C, 0x42D790EE},
	{0x0126F273, 0x2ADF39E5, 0xC744989F, 0xA278D239, 0x1F05FD32, 0x0F8E51F4, 0x0BAD92AE, 0x96AD2FB2} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 909 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 910 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 911 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 912 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 913 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDBEC557A, 0x7BB34052, 0x18AE66B1, 0x46587C54, 0x899C0228, 0x4F9DC6A1, 0xA6BDD467, 0xB849D1E0},
	{0x3CDE4E17, 0xB81473F3, 0xB9404253, 0x69429293, 0xFDD99D11, 0x7098DC44, 0x5CC4C9D0, 0x38EE97E5} } ,
	 { {0x70E9DAC4, 0xCB30FECE, 0x78E11015, 0x835E4694, 0x2E4BB109, 0x3E4E2C6E, 0xEA0AE768, 0x158759AB},
	{0xF9058138, 0xAAA994E0, 0x9B11C3D8, 0x6D7C5F07, 0x76E1C473, 0x47D3B6B4, 0xAA8C8BFA, 0x92C7545B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x340EC5A5, 0x52A38DAA, 0xE984B1D0, 0xFF22AFC9, 0xD1D6232B, 0xB663B9E4, 0xD35D0B4A, 0x9A1CAD5F},
	{0x9D2BCCCF, 0x20A6FF76, 0x54841FBB, 0x1696E86F, 0x8A4A1CAD, 0xA00E8D33, 0xFE9C9344, 0x4E7BA6CE} } ,
	 { {0xDDC06B43, 0xBF0E518D, 0xD43CC740, 0x5A650EE4, 0x6F856BE9, 0x48D5EE39, 0x2195A796, 0x5EB4BF6E},
	{0xF787F71C, 0xCCFBBAC1, 0xCA7A8E2B, 0xBA3A136F, 0xB454733A, 0x7703712D, 0xECD5CC49, 0x1630DDD7} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 914 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 915 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 916 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 917 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 918 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8CC01A06, 0x0C07D704, 0x208E6C53, 0x2BF2A435, 0x170D885B, 0xADE76DB2, 0x4E28062B, 0xB8621B71},
	{0x47157790, 0xC81E22CF, 0xD4B093D9, 0xAE18E622, 0xBF41568A, 0x7B228893, 0x98BFB71A, 0x1987587F} } ,
	 { {0xA1F6D61F, 0x07CC3CCC, 0x6CDA51A8, 0x4243D881, 0xD0698AF9, 0x1C1F37F7, 0x58A9BFEC, 0xA75F59D7},
	{0xD1A97182, 0xD2F58A0B, 0x55E80E85, 0x87ACB9AF, 0x3905D50D, 0x16D95513, 0x9596BE7D, 0x5CD53989} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8ED9D059, 0x7D395A59, 0x5E06ECB6, 0x9B2BFC01, 0x8666FF06, 0xBD6757F2, 0xF045303D, 0x230B3C4B},
	{0xC1934979, 0xDC88B246, 0x68D16FF9, 0x5E0368EF, 0x9CB22418, 0xB0D591F5, 0x0D61BDF6, 0x2464320F} } ,
	 { {0xF762F6EF, 0x818C6543, 0x1072445C, 0x427D47AF, 0xCF1324E8, 0xCB0E6FF1, 0xFA875B51, 0x34C7C622},
	{0x1A0DCEDE, 0xD2AE9FD4, 0x185CF72C, 0xB2C8400C, 0xD0A692BF, 0x9A34039B, 0x76475A24, 0x5A13B70D} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 919 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 920 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 921 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 922 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 923 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0DF619B, 0x6187CA1A, 0x96BA70BD, 0x3471D6EE, 0xF4D3E57D, 0x023B5577, 0xD33F8BFA, 0x200B4EFB},
	{0x4885B799, 0x18D4A316, 0xFBFF5E6B, 0x16698B24, 0xC196FBC4, 0x240CE6D4, 0xE8F6E55E, 0x0F9FB74D} } ,
	 { {0xCE40BD9A, 0x0751165B, 0xE9A17217, 0xB097145B, 0xB3FCEDCA, 0x2394F343, 0xB00D7555, 0x1F82A943},
	{0x1709222A, 0x43C72240, 0xCB12C6E7, 0xF5971B69, 0x9B7BFDA5, 0x1281C37C, 0xD8B9CE73, 0x225B4A25} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x529F325D, 0xDDD70B7A, 0x0AF2AE44, 0xA6A48F9C, 0x7135A773, 0x805ACAF6, 0x31CD5073, 0xA0F17AA8},
	{0xFE315D5A, 0x52657240, 0xF37FD5D2, 0xD5E116B6, 0x1F954676, 0xA1293A85, 0xC4C6034E, 0x14D24208} } ,
	 { {0xCAD380F9, 0x92A3D971, 0x73A591CA, 0x56ACFE35, 0x0F796BA5, 0xFA2C0D8F, 0xEB2D6ABB, 0x83F55474},
	{0xAB29396A, 0x74EFCDCA, 0x54D787DD, 0xE352DEF2, 0xBEEEBC65, 0xA2FD5066, 0xA8E93329, 0x613D8081} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 924 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 925 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 926 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 927 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 928 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5484EC62, 0x2185AE77, 0x739D8C58, 0xEAA96EC7, 0x860AC679, 0x3814F6AF, 0x62B7DE1B, 0x524A87C8},
	{0xD99A10A5, 0x6C8DA924, 0x8C669CBC, 0x976BE61E, 0x5F69B5D7, 0xE851D87D, 0x749335DF, 0x68DC3B62} } ,
	 { {0x460537D2, 0x822A3263, 0x499C86A9, 0x0BA4A1DF, 0x8A4744F1, 0x960E5D76, 0x1F46502D, 0x779AB114},
	{0xFA0892A5, 0xD17DFE7D, 0x6AC472CA, 0x2CCEF6D7, 0xEA7E55E9, 0xBD476C5C, 0x410B018A, 0x0FD54E0F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x364E5D1C, 0xED0E3A70, 0xE2527575, 0x5BE969BD, 0x5136CA5E, 0xCC658992, 0x971AC423, 0x6E8EE0D2},
	{0x65A09D8E, 0x72EA92DE, 0x68F30949, 0xB79AB9EF, 0xC669C65C, 0x75CA5FB5, 0xB1235B3A, 0xB2066786} } ,
	 { {0xD0BB53BB, 0x9BACAB27, 0x6CC347DB, 0x4F17492C, 0x180D2BA9, 0xAFB272FD, 0x14677D30, 0x50474444},
	{0x4091345D, 0x005B737D, 0x36D2ACED, 0x239CD17F, 0x6DBF18CC, 0xF0F3C4A6, 0x0D6A367D, 0x5E1E7574} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 929 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 930 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 931 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 932 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 933 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDD196511, 0xE088464F, 0x71390E8C, 0xD7BD6257, 0x974A6982, 0x634302DC, 0x94D7E7B3, 0x91A75A26},
	{0xC9B67958, 0x424F63DE, 0xEB85E26A, 0x01240F78, 0x6434837D, 0x9E9994EA, 0x3402D702, 0x2EB14C1A} } ,
	 { {0x1D682C2E, 0x5AF8510C, 0x85FE8245, 0xDE4407BE, 0x65BCB332, 0x4C8A303D, 0x33983763, 0x062A8ECB},
	{0xFA42A474, 0xD3A70D52, 0xD8E83C68, 0x203C5EA7, 0x5B89DEE8, 0x5392AA96, 0x5661FA8F, 0x112EE033} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x22D7D019, 0xDD51B264, 0xA99A81A5, 0xC5166889, 0x4EA39019, 0xEF718087, 0x231C3F2C, 0x22E30EC9},
	{0x897FDC0F, 0xE787D868, 0x482026FB, 0xE2ED62B3, 0x13A4906E, 0x16820F16, 0x573A962F, 0xAD5C601B} } ,
	 { {0x612C79B7, 0xDFD4901F, 0xD1AF964D, 0x54CD6780, 0xF66208C4, 0x20FB549A, 0xA9662AA7, 0x813B934F},
	{0x31EF2EB2, 0x523B800F, 0xD8742410, 0x2B9E351B, 0xE5766583, 0x6CBC41FF, 0x75F70423, 0x6A53B765} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 934 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 935 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 936 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 937 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 938 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x08D48337, 0x539D5625, 0x8C71743C, 0x93611D4E, 0x569FB0FE, 0x82599AFE, 0x80C7F408, 0x0C022A30},
	{0x81167634, 0xC49762C0, 0x3723317B, 0xE01A4EF8, 0x8C37EDC1, 0x37568990, 0xC84FF6C2, 0x3C886301} } ,
	 { {0x0744562B, 0xD3B20C58, 0xF7AACFDE, 0xC68CE6EE, 0xB8896FC7, 0x3610185E, 0x0F16F1AB, 0x499385E5},
	{0x4272D0E6, 0xEBDC23F4, 0x84F7522C, 0xF0967ACE, 0x8AF430F9, 0x28BB3C70, 0x03F58DE1, 0x3E5E4534} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x4B9A0BA8, 0x2E1EAEE6, 0x7F82FF39, 0x74BABB6E, 0x0BE51A8D, 0xA7D64453, 0x07965AE6, 0x780CD82D},
	{0x30963D35, 0xD80E8D6D, 0x23CBD7FD, 0xDD916219, 0x8C648956, 0x84F784D3, 0x8593A9C8, 0x981106EE} } ,
	 { {0x152B37AF, 0xA8AD0F6A, 0xBC7C9B35, 0x6D4241F7, 0x6F306563, 0x74330993, 0x3B150F4E, 0x891F5238},
	{0x15E8FDF6, 0x92DB89AD, 0x1F00FF30, 0x59EEE14F, 0x82B6C396, 0x87E111DA, 0xEA791313, 0x7FD8482D} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 939 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 940 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 941 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 942 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 943 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCD6B82E0, 0x66B2386A, 0x3A0A6AE8, 0x6B60CB07, 0x5D16C0E1, 0x7E203AFE, 0x1985B27D, 0x4DA90E0D},
	{0x8C94123E, 0x9B3AE2EC, 0x5F569276, 0xE4F529F2, 0x7C761D63, 0x17DD6BC7, 0xFA467574, 0xA49ED253} } ,
	 { {0x53F4EA31, 0xACEA4492, 0xE11977DD, 0x989225B4, 0x5CD0D399, 0xB61190BC, 0x6C700EAE, 0x7DC1FBA9},
	{0x738845D8, 0xE0B7ADC1, 0xE30BD118, 0x6CA176DF, 0xB1490B6E, 0xBB214221, 0xE719A80D, 0x0075D176} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8D93C249, 0x2B467269, 0xA0C04208, 0xA3C2020F, 0x546360F3, 0xD4736995, 0xD449A6BC, 0xAEE4E7A7},
	{0x2B9F53EC, 0x378ECBF8, 0xAE56F6FF, 0xF3C13B04, 0xA9CDC37A, 0x3E718D11, 0x190A3118, 0x9E1D96B6} } ,
	 { {0x37241E67, 0x19398AE2, 0xEAD22C6D, 0xFCDC895C, 0xF5551E62, 0xFDE3DC35, 0x5BF35216, 0x19C34EB7},
	{0x9ED7E880, 0x12708D3B, 0x4AC6A705, 0x83B1483D, 0x637697CB, 0xA6C9B6F9, 0xB8EE187D, 0x96CCD305} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 944 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 945 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 946 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 947 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 948 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2F4FF91A, 0x5335DEF9, 0x4949B87E, 0xCA4C23D8, 0x80F57A78, 0xD79997AE, 0x48000215, 0x4818DD55},
	{0x5B8B1D5F, 0x83372181, 0x2FC6F7F3, 0x2128421E, 0xFB27D725, 0xC827B37C, 0xD571AE9B, 0x7F32AF98} } ,
	 { {0xA99B966C, 0x8E185342, 0xC89A8701, 0xA694097E, 0x303D4958, 0xA45C6B05, 0x3568E6D3, 0x990724FF},
	{0xD877967A, 0xC822D86F, 0x2D601628, 0x8DC2B361, 0x1E5C4EE7, 0x9C05DBEE, 0x5C2A2707, 0x669AB100} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x71AF8C4F, 0xCA2FDE16, 0x4E9C5A46, 0x0A078E61, 0x44B70387, 0x0889ECB0, 0xD8503FAD, 0x6B004126},
	{0x8ABADE5E, 0xBBCDD36D, 0x21FA4191, 0x49B3BA19, 0xC58CF874, 0xC94DEFD0, 0x8CBE297B, 0x35A228BE} } ,
	 { {0x6D31BCB8, 0x8784E928, 0x40F717D7, 0x26077E90, 0x11E0DC2E, 0x680C0240, 0xEFC39AFD, 0x897F264B},
	{0xA6472058, 0x746CF93A, 0xF480ED31, 0x2E7DA558, 0x04D6FFD6, 0x4059D692, 0x2BF814BD, 0x4021491B} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 949 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 950 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 951 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 952 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 953 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x84AF14F4, 0x77B09186, 0x693F58AB, 0xEB0222FD, 0x4A5BC66A, 0xF06521C8, 0xDC86B771, 0x848F931F},
	{0x48C4DED8, 0xCBC9E908, 0x57DAD4A1, 0xFD0E7ED5, 0x37599B0A, 0xCE5FF606, 0x6808D395, 0xAB291086} } ,
	 { {0xF43F92B5, 0x1E888BF1, 0xC6959D75, 0xD880AFD3, 0xB5971E69, 0x04765CE9, 0x2EC0FA89, 0xA888A4BA},
	{0xDD5E3201, 0x7219A7C4, 0x98DF87D5, 0x091C4B9A, 0x7E3AEDAA, 0xD7F3881A, 0x69DC934B, 0x2DDFDC71} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x074D4B05, 0x3EF77918, 0x833FD623, 0xB4848B7E, 0x97F574F7, 0xD881F544, 0x28113590, 0x654CE1EC},
	{0xD3D06E7F, 0x99473B2A, 0x90A19C5E, 0x9F036BAD, 0xC04830F6, 0xF0567198, 0xA2A6F1DA, 0x36644352} } ,
	 { {0x738B082C, 0xE21827BF, 0xA9948FEE, 0x9B736C51, 0x43481B18, 0xC394EC9F, 0x212BE0E7, 0x07C8FD14},
	{0x0710E008, 0xC17D4E42, 0xF031E82D, 0x3EBB73E3, 0x9EC2FDFC, 0x51D73DA8, 0xEEE6FDA7, 0x643B4199} } ,
	 { {0x8652F0CF, 0x3E228E32, 0xB8B35BA3, 0x9DEFB306, 0x174BB31E, 0x0D8C5D68, 0x1D6318E9, 0x96FDAAB2},
	{0xBABC6402, 0xE4334F89, 0x31BF0FAA, 0x12389735, 0xFC75DB54, 0xAFE71034, 0xD3B92697, 0x5BBFB8E2} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 954 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 955 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 956 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 957 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 958 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 959 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 960 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF3739B4E, 0xD8180E4D, 0xFFB6180C, 0x3E448485, 0x9431EB65, 0xD527AE06, 0xCB836B41, 0x59C4701B},
	{0xC1D35D33, 0x1BB9EE31, 0x02248E7B, 0xECAAC671, 0x986E985E, 0x93F7AE2F, 0xCA3D94A8, 0xA13F7AD2} } ,
	 { {0xB550480F, 0xB56E5BC9, 0x37C14E13, 0x326079B6, 0xA5DE44F8, 0xBA7FD59B, 0xA6F54FFF, 0x44CB4AFD},
	{0x6BF5673C, 0xEA5CCD5A, 0xCE1F5D23, 0x721A8159, 0xA009DCED, 0x75BC6C61, 0xDE8F0404, 0x9BE49163} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x91FF3F9A, 0xE3E032C9, 0x0C8299B3, 0x61AD267C, 0x8FBF30D2, 0x7936484E, 0x95C6220F, 0x9506810C},
	{0x588C4B19, 0x66E7D056, 0xDE70AA78, 0x2C384C2F, 0x0DEFC993, 0x98B21C00, 0x726A83F5, 0x287A514D} } ,
	 { {0x54B78853, 0x78503FC4, 0x005EE6B6, 0x02393EE2, 0x2DCF803C, 0x0F55FEB1, 0xFF03D056, 0x1E3CB79B},
	{0x33A24435, 0x01AA32A5, 0xECB7D476, 0xA1D64B99, 0xFE2CCE1E, 0x1B5FA918, 0x5778463E, 0x6BF0815C} } ,
	 { {0x6AA0901E, 0x6ADCB793, 0x6F829C27, 0x64C0F36C, 0x4BBC89F0, 0x74FFAB37, 0x4DEA9FFF, 0x899695FB},
	{0x75BE99DD, 0xD5CB1103, 0xC7C6DB00, 0xD1235612, 0xEC313025, 0xF0187C57, 0x7CFF2BDF, 0x7DB58405} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 961 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 962 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 963 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 964 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 965 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 966 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 967 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x935542E4, 0xC8A6D627, 0x3C505D7C, 0x352B105B, 0xAB089F4F, 0xBE74C2B2, 0xBE994348, 0x928A6378},
	{0x203D51E9, 0x09216588, 0x0B08831C, 0x3684EA2C, 0x85C92EE5, 0x31A045CC, 0x1110C045, 0x134FA0C0} } ,
	 { {0x08774D76, 0xFAF3A49D, 0x7104100A, 0x30E11B0B, 0x0FD7532C, 0x55F0F5EA, 0x86D0B71E, 0xA1A9C77D},
	{0x4893C118, 0xBAAEE7E4, 0xB431A190, 0x8CFE2847, 0xDA613AEF, 0xE9B91088, 0x59E7F046, 0x001EE3D3} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x16EF2BEF, 0xE49BCDFD, 0xBD44A994, 0x35253AAD, 0x0C6F634E, 0x23C7A625, 0x002AD1EC, 0x8036F327},
	{0x55ABE26B, 0x22DB71C1, 0xFD68925B, 0xA904E7AA, 0x3FA6CDD4, 0x845F6F56, 0xB5BC8DFD, 0x8BA807E1} } ,
	 { {0x2F642BD1, 0x857B8B79, 0x66892832, 0x10C432F4, 0x448A9432, 0x49BD8612, 0xBB8C940F, 0x8597C3E0},
	{0x15F946BA, 0x92DED0A2, 0xDDD70A81, 0x808CD8CF, 0xB091CCD2, 0x39A98814, 0x56217D3E, 0x0F1C9820} } ,
	 { {0xAEC26651, 0xF6F8BF88, 0x0D9040CE, 0x4EB08976, 0xCBCC1CA3, 0xB0818F68, 0xCD829213, 0x893FF038},
	{0x91278230, 0x755DCFC8, 0x68634321, 0x19FC508F, 0xB4C275DF, 0xD3722111, 0xB3CFE08D, 0x003DC7A6} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 968 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 969 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 970 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 971 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 972 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 973 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 974 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8932FBBE, 0x2F386FAD, 0x693D07FF, 0x049A4A05, 0xAE722E61, 0xA0E5600E, 0xA44C4B0A, 0x4A028369},
	{0x9B9270B1, 0x3B59F862, 0x61A1B727, 0x11D8D6E5, 0xD4C4FEB8, 0x755835A5, 0xE72125CE, 0x22D73247} } ,
	 { {0xB0F11197, 0x559E094A, 0x2C22DC0A, 0xB2AE1946, 0xC801B51B, 0x992DC44A, 0x26DB123A, 0x02952C48},
	{0xC4AF9A98, 0x19392D8F, 0x1BF7723B, 0xE3BD6D2E, 0x4D3A6813, 0x67B11412, 0xD678BF54, 0x4918A308} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x973C19BA, 0xB3A8FA4F, 0xA235C2D6, 0x0DE9E986, 0x7E1926DE, 0x09091D8D, 0x0F3E9201, 0x715F5C74},
	{0xB8777EBE, 0x53922395, 0x5FD42EB5, 0x5F0663C7, 0x3F62D796, 0xB640E12E, 0x1ADB47A6, 0x8F9ABF99} } ,
	 { {0x3D97DCDB, 0x756F4CCB, 0xAFAD3A74, 0x64A4ACB1, 0xA34D083F, 0x2B5000F5, 0x7805EE7F, 0x51341521},
	{0xEFE1FAFF, 0x8AEBD7B8, 0xA605A944, 0xE15400D1, 0x5F9D5C5D, 0xC7DB9F31, 0x0877F342, 0x908E4BE6} } ,
	 { {0x61E2232E, 0xAB3C1295, 0x5845B814, 0x655C328C, 0x90036A37, 0x325B8895, 0x4DB62475, 0x052A5890},
	{0x895F3530, 0x32725B1F, 0x37EEE476, 0xC77ADA5C, 0x9A74D027, 0xCF622824, 0xACF17EA8, 0x92314611} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 975 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 976 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 977 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 978 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 979 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 980 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 981 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xEB1F2A55, 0x94C87780, 0xA82AE580, 0x61742BD9, 0xAC473382, 0x498D64BE, 0x7544FFAD, 0x1B84A65C},
	{0x7097DBF9, 0x612F7D87, 0x6827E059, 0xEB445DA1, 0x8BA25338, 0x0FAB430B, 0x10F3FDBF, 0x256C5F72} } ,
	 { {0x30ED8849, 0xAF7874B9, 0x823E2C46, 0x0997589B, 0xD66C7088, 0x5539D716, 0x89B4CE0F, 0x5A26F5F7},
	{0xAF3E77A6, 0x01A43FFD, 0xAAED9732, 0x3B11DDA1, 0xB8BEDA54, 0x896D9417, 0x1F7039F5, 0xAA0ED7DB} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x04208AEA, 0x7F315280, 0x1AACCB11, 0x11CE8A93, 0x5FCFB573, 0x27473ABF, 0x87C87347, 0x6A86BE84},
	{0x859C7051, 0xAA4BD789, 0x5D42D967, 0x1500644C, 0x31A7C130, 0xE401F217, 0x723CAF80, 0xAC4BAA1E} } ,
	 { {0x903989BA, 0x0060B988, 0x01CF23C8, 0x610DD31F, 0x9BB25BC6, 0xB38ED8A6, 0xBF3EBE9E, 0x20672E53},
	{0x39FA5357, 0x484A4D00, 0x6E202DAE, 0x5F00B39B, 0x2094C76F, 0xE8A87E2B, 0xDD368A1E, 0x7148ABAD} } ,
	 { {0x61DB1092, 0x5EF0E972, 0x047C588D, 0x132EB137, 0xACD8E110, 0xAA73AE2D, 0x13699C1E, 0xB44DEBEF},
	{0xFC50BAB1, 0x0459F649, 0x81634F1D, 0x63120EA2, 0x1D9B2AF3, 0x177ACBC4, 0xFEC197C2, 0x9A0A10F3} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 982 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 983 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 984 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 985 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 986 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 987 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 988 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6D8C4426, 0x695BC0DF, 0x8EFA0044, 0x4F47A0D9, 0x41B19878, 0x1669F968, 0x711C8947, 0x4C7B2DCA},
	{0x37A979EC, 0xC889B813, 0xB7929DD7, 0xBAC8C1E2, 0x4F11B1D6, 0x0D376773, 0x4303099B, 0xB53E2ED2} } ,
	 { {0x4CF5B406, 0xD160C8DB, 0x9309F45A, 0x458C6888, 0x65D463B6, 0x9788CF84, 0x9270D5ED, 0xAC5DB90E},
	{0xB60B21AD, 0xDA69A39C, 0x19B4B2D4, 0x3A075A0A, 0xAE5792CD, 0x21384132, 0x3B3A73A9, 0x9F1F97C7} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xF7E8C466, 0xD3656A4F, 0x7C8295AC, 0xD9D4C872, 0xD81B9665, 0xA161A3FA, 0x4D94179F, 0x29C026E7},
	{0x971ED0B4, 0xD463C470, 0xB36811EC, 0x110588C5, 0x9F4BFF43, 0xEBBD0D27, 0x0B864704, 0x6830BA59} } ,
	 { {0x5C76F55A, 0x87E4CEA0, 0xF17E02B2, 0x7802B339, 0x566A3FC5, 0x097E8917, 0xE59ECAFE, 0x7C593719},
	{0xC5DB0943, 0x7EC80DD5, 0x7BC2040F, 0x75F9E76E, 0x2C9F96B5, 0x77752388, 0x6ECBC9EC, 0x5C41B848} } ,
	 { {0x37BF3371, 0xA3D30805, 0x519C096E, 0x78072470, 0x77C63DB7, 0x33B1429D, 0xE4C2CFB2, 0x9EA7D35A},
	{0x09EA0EBF, 0xB5E4BD88, 0x5EF18662, 0x60FD0773, 0x08CC9BE5, 0x471025FA, 0x36560B29, 0x842B90CC} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 989 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 990 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 991 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 992 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 993 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 994 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 995 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x32D5918A, 0x57AE2E6A, 0x7F8905AC, 0x5435FEA4, 0x330C1B8C, 0x12C4B626, 0x54E37FB3, 0x705FE541},
	{0xE858ADE5, 0xFBD772E9, 0xA7004A48, 0x482D6D84, 0xC31AD40A, 0x770EE88F, 0x08741EF3, 0x2422CDD0} } ,
	 { {0xBA582C94, 0xDB02A8A7, 0xF55517F3, 0x8F5E6790, 0x34CED08F, 0x61B8EDA0, 0x624EAE06, 0x40856403},
	{0x6F699363, 0x108CA0FA, 0x0B37FE40, 0x3D3067E6, 0x0DF4577E, 0x42B3AC0F, 0x6B82B0BF, 0xA665D9A8} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xEDE3303C, 0xDD0B7573, 0x5E5142C9, 0x5ACF40CC, 0x02B56F9F, 0x31B7F395, 0x9FDBF148, 0xA42B73E4},
	{0xED6D7A30, 0xA46B9711, 0xC7A942E6, 0x66256FEA, 0xF548C3A1, 0xFFAC5016, 0xC42277B2, 0xADA9615F} } ,
	 { {0x7D5C0BE6, 0xF7876899, 0xFD7D22F6, 0x8182FAA8, 0x1EF82881, 0x7D60AFA6, 0x44C5BE0B, 0x239E28B8},
	{0xBF1EF4AB, 0xA8154739, 0x1CF0D218, 0xFC88F7FE, 0x7550F0AD, 0x9883CAAE, 0xC6E17B87, 0x012800AA} } ,
	 { {0x74B05928, 0xB605514F, 0xEAAA2FE7, 0x1EBCCF21, 0x699DA11F, 0xC371DB40, 0xC49D5C0C, 0x810AC806},
	{0x7CA6F22B, 0x222AB843, 0x41F81D39, 0x674F232B, 0xC8062547, 0x8A06FBB2, 0x96E68555, 0x92B8148E} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 996 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 997 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 998 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 999 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1000 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1001 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1002 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9A75B07D, 0x02CA02CB, 0x3215BCE0, 0x526D8160, 0xE696CAF7, 0x3C4D4485, 0xBF4A9894, 0x6435720E},
	{0xB404A77C, 0xF5913AA2, 0xEB342FA9, 0x6E7B303A, 0xD494585E, 0x6561E07B, 0x176359B1, 0x49D160E2} } ,
	 { {0x8E8908A9, 0xF4731180, 0xD9109F33, 0x11860DAE, 0xA0ACF991, 0xE7C5048A, 0xF82F8444, 0x70A129AA},
	{0x5261747B, 0x764F6CF0, 0xDAA2B86D, 0x9A6FAE04, 0x11827EAF, 0xC2FFAC9D, 0x54B4AFEC, 0x749D3206} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xFAEA9C14, 0xF76FCECC, 0x2750F62E, 0xEB9A5464, 0xFAF50E6B, 0x8C64272A, 0x5FA68297, 0x63032495},
	{0xFE50EAAE, 0x76AD3336, 0xE7D50EC5, 0xEA51DD17, 0x400381DA, 0xE608E9BB, 0x36014AA1, 0x23DD41C8} } ,
	 { {0xD7A0C489, 0xAFAC4090, 0x5FB62716, 0x0809EC2F, 0x1EAEF954, 0xAEE9C423, 0x7B64BEB5, 0x7778CD93},
	{0x50BE245E, 0x13CEA498, 0xF6AA839D, 0x92C5219F, 0xCB31330E, 0x2F6A741F, 0x3E352B4B, 0x655ECEDB} } ,
	 { {0xBAE5DCB7, 0xE9F7994F, 0xDDA95F20, 0x0FFA6EBC, 0xED77696D, 0xD429ACA9, 0xB0402C60, 0x272EB493},
	{0x4296B45B, 0xEDB0502F, 0xE0CD9193, 0x21CDAF68, 0xCF2273AA, 0x8A9EFCCE, 0x694A83B0, 0x2F26C54A} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1003 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1004 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1005 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1006 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1007 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1008 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1009 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xD4C903AF, 0xAC26A1EC, 0x6965A50C, 0x7D48218B, 0x7B9D2FE4, 0x9BAC106E, 0x78D3B6DD, 0x7B000BDA},
	{0x0445710B, 0x8434766B, 0xC5F46AFD, 0xC38E6945, 0xB0A4212D, 0x4454A394, 0x974CFC59, 0x9C3CF982} } ,
	 { {0x8BE32199, 0xB91F4467, 0xE5903569, 0x0F294401, 0xBCFE5456, 0xC8F89F9A, 0xC3D95A92, 0x18CC140D},
	{0x66A77D42, 0x6D95C669, 0x0CD64B60, 0xF90D1326, 0x3022CD8E, 0xA2A3840E, 0xDF4BF92B, 0x8BC35904} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7A419C5A, 0x494A8C44, 0x350833FE, 0xE1185AE1, 0x79CC9A1B, 0x3F023965, 0x0B7C9207, 0x79936C88},
	{0x15557412, 0xB51F8719, 0x94095CCC, 0xE9E7E2D9, 0x5AA140E8, 0x283AC120, 0xFC5A7E14, 0x5EF1990F} } ,
	 { {0x421446B4, 0x0F06F72B, 0x31AB1DFA, 0x5ABDFADA, 0xE04DB7F3, 0x3CA8FCED, 0x019F1D65, 0x2FDCA717},
	{0x83F29BAB, 0xECDA6A10, 0x182D4F03, 0x01A430BC, 0x6E4E6788, 0xA9877E2D, 0x9A8E6342, 0x9E29AC86} } ,
	 { {0x17C64332, 0x723E88CF, 0xCB206AD3, 0x1E528803, 0x79FCA8AC, 0x91F13F35, 0x87B2B525, 0x3198281B},
	{0x6B22C5E9, 0xDC3D0321, 0x4534B779, 0xDF0879AB, 0x0C631168, 0x49E6ABB1, 0x7E79162E, 0x5D731347} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1010 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1011 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1012 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1013 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1014 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1015 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1016 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB1445613, 0xA00861C5, 0x7014B291, 0xBE0DFCA5, 0xBC92C19C, 0x999AD20B, 0x370B55B4, 0x9A244A99},
	{0x6E31B826, 0xF8F993B5, 0xECDF07FB, 0xC6B63D59, 0xFF2D40D8, 0x8A6A705D, 0x2718F2E9, 0x8E78F20E} } ,
	 { {0x2A9D0165, 0x15F3F0D6, 0x62AC2B14, 0xDCF3F1E8, 0xF24F70B0, 0x7CB0D4B9, 0x8CE5CF48, 0xA77CB083},
	{0x67F4677B, 0xF6CBFFF3, 0x79A82140, 0x0238D011, 0x5F9D681A, 0x53202BE7, 0x1AC28207, 0x693F60A6} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x13071633, 0x0733A3E5, 0x6B51B927, 0x3F146967, 0x57B3AED6, 0xDEE36972, 0xBCEDC8D1, 0x42BF51B6},
	{0x29024BDB, 0x32509B39, 0x5AF9EB90, 0x363D843F, 0xB586661E, 0x9F16858D, 0xF7B03C17, 0x3B25A532} } ,
	 { {0x5F2C063B, 0xA6877B1E, 0xF842DC94, 0xDACAA67F, 0x200DBCBB, 0x39F6DD41, 0xCF4C9991, 0x0BC74B10},
	{0xD40205D6, 0xE32450E8, 0x28C83A81, 0x19952D0C, 0x4138C832, 0xF54E3A9B, 0x6211F5A7, 0x13C2FF80} } ,
	 { {0xF30DCE2F, 0x2CF957FA, 0xF0E076E1, 0xA6D6372F, 0x90BC57AC, 0xFE014D08, 0xD9ACC267, 0x94E5C244},
	{0x6DBC9A5B, 0xEEA97635, 0x1ED8633A, 0xF15FF382, 0x6B58467E, 0xAADFFB63, 0xF56627E5, 0x186B2289} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1017 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1018 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1019 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1020 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1021 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1022 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1023 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8BBD2954, 0x7DB54379, 0xAE430107, 0xAB7CCDA8, 0xCC182FB5, 0x50B9B4AB, 0x05B10459, 0x466B07B8},
	{0x995EE114, 0x8714A034, 0x21493268, 0xC87E183B, 0x973E47D0, 0x662D92CD, 0x0A00DBAB, 0x71686BAD} } ,
	 { {0x6585E960, 0xFD2F6658, 0x4DC72F88, 0xA0F67BA3, 0x12DD9402, 0x647ECCE6, 0xE1FD6C1C, 0x4123A6E7},
	{0x1864154A, 0xEFA432F6, 0x761252D6, 0xDC27DAE3, 0xA2E61974, 0x9593A2FB, 0x611B4053, 0x53EFAB07} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7BA186AE, 0xD017BDE5, 0xF0A30AAA, 0x6F54AC4B, 0x862B8ADC, 0x2694E978, 0xAC19790A, 0x1987B570},
	{0x832BECB5, 0xC18B8A83, 0xB1D40FF1, 0x5A943D49, 0xF16A81A6, 0x6AB0DEB9, 0x424FAABE, 0xA03129DC} } ,
	 { {0x0B4C853A, 0xC95A3646, 0x56980D3E, 0xB973C1E1, 0x480E1A22, 0x48C3D9F6, 0xEF6082C1, 0x490BF805},
	{0xC557478A, 0xE6CE5B42, 0xC5D2D7FB, 0x3AEF3FE8, 0x5A713186, 0x70546DB5, 0xFDD17AAC, 0x0CA25A06} } ,
	 { {0xCB0BD2C0, 0xFA5ECCB0, 0x9B8E5F11, 0x41ECF746, 0x25BB2805, 0xC8FD99CC, 0xC3FAD838, 0x82474DCF},
	{0x30C82A94, 0xDF4865EC, 0xEC24A5AD, 0xB84FB5C6, 0x45CC32E9, 0x2B2745F7, 0xC23680A7, 0xA7DF560E} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1024 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1025 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1026 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1027 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1028 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1029 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1030 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x0E711C82, 0x1A4AE837, 0xF3F1D8D4, 0x162243BB, 0x72CCA284, 0xF4430F7E, 0x07D72CCB, 0x365E3112},
	{0x5983569D, 0x0C31E838, 0xD93E570A, 0xD1B9197E, 0x60C859F6, 0x19FF1410, 0x3A007326, 0x7937D4C1} } ,
	 { {0xF8E234D9, 0x5FDFF320, 0xE3575035, 0x1551E71C, 0xFAD1EB6C, 0xB443728F, 0x631EE46A, 0x994EA37E},
	{0x15003D77, 0x53AF9320, 0x270FDCBA, 0x668E5DE0, 0xDD93648F, 0x97ABEADE, 0xE97BF18E, 0x2F7A0D32} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x75FDDF15, 0x7A1B3CAF, 0x273BE6DB, 0x2DCC76F6, 0x16CC5102, 0x73B74C6F, 0xAE373E48, 0x596ECC64},
	{0xFF7E593F, 0xA4389E10, 0x0B90F16A, 0xEDDA1C2F, 0x9A39C926, 0x7E234C21, 0xF6CD6179, 0x5DADA1B4} } ,
	 { {0xAE648A39, 0xAB4C893F, 0x7B031011, 0x064D576B, 0x0232949A, 0x1D63963C, 0x660D9E64, 0x017F1F84},
	{0x9895AD01, 0xFF4FE047, 0xBA8A8F06, 0x2C2910E3, 0x3BD3D545, 0x4B958AC3, 0xDBC6A838, 0xADA9D523} } ,
	 { {0x8F983517, 0xC0D15C90, 0xF236C123, 0x17922198, 0xA1C14D23, 0x6D2688B4, 0x861EECAC, 0x7889A83A},
	{0x2A007AEE, 0xA75F2640, 0x4E1FB974, 0xCD1CBBC0, 0xBB26C91E, 0x2F57D5BD, 0xD2F7E31D, 0x5EF41A65} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1031 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1032 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1033 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1034 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1035 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1036 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1037 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xDE3445F1, 0xAA9E5390, 0x76AE3B3C, 0x5BF68F6C, 0x24FA7C95, 0x959A34E7, 0x7D606122, 0x0CD95AD5},
	{0xA35F5253, 0x7D00A566, 0xBC382565, 0xC82AF85B, 0xFA2C1065, 0xA7A2A576, 0x063EA6EF, 0x4BF8BDA7} } ,
	 { {0x040F3E02, 0x9B4C8C2D, 0x25C845DF, 0x0BAD4BDD, 0x65E7EF65, 0xA210A046, 0xB6178173, 0x1B7830CA},
	{0x281C677D, 0xFD9C635A, 0x3379FAE2, 0x4DCB03CF, 0x9AE4FE2D, 0x19E34075, 0x2304A717, 0x788C980E} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x620F0BBD, 0x36BE272D, 0xE256AC58, 0x67A0F2C7, 0xFC26D00B, 0xCB1D6655, 0x1562DD8A, 0x282A47DA},
	{0x94FFF57F, 0x20B21B4A, 0xA181AD12, 0x7E36A35A, 0x55A74FCF, 0x7B8BEF2E, 0x375968F3, 0x36249133} } ,
	 { {0x04754F49, 0xA4FCEAA3, 0xD446949D, 0x06EAFB56, 0x35F071BD, 0x747FD7CF, 0x45BAE104, 0x6E086AAC},
	{0x0FDD15A0, 0x3A8575C1, 0x18C77EF3, 0x1C682FF6, 0xE78A9FC9, 0x31455795, 0xC375FE9B, 0x7CB4E342} } ,
	 { {0x081E7C04, 0x3699185A, 0x4B908BBF, 0x175A97BA, 0xCBCFDECA, 0x4421408C, 0x6C2F02E7, 0x36F06195},
	{0xEE0C9A5F, 0xFC4A3D02, 0x927C167E, 0x88845AFD, 0xE1E772A5, 0x3866247F, 0x05EA7205, 0x3705915A} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1038 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1039 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1040 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1041 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1042 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1043 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1044 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x47F4181C, 0xA7DAC3F7, 0x82CEED06, 0xF687F3D6, 0x18BFE6F6, 0x123350E0, 0xB4DA3A52, 0x7028BDDF},
	{0x255C538D, 0x3DA6D909, 0x8CA28111, 0x47FD45B9, 0xD6B4CC31, 0x386EE6D2, 0x0688ADA6, 0x92A42BC2} } ,
	 { {0x1022E346, 0x487EB57F, 0x21099F0F, 0xB2A0D9C6, 0x16CCBFB2, 0x01294D39, 0x95DA15B1, 0x20A3276B},
	{0x4C0DE37F, 0x00598EA0, 0xAF213F94, 0x35724508, 0xB78C7C9C, 0x8D9B92DB, 0x2AB5237E, 0x35488A9F} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x81EAF044, 0x58693426, 0xCFE0F808, 0x1B0F63C3, 0x7A23815B, 0xB54919D1, 0xB18AAD0C, 0x99DC9FEC},
	{0x250F7928, 0x9A46DA5A, 0xF8A1367C, 0x1ACFCDB7, 0xD968FD2C, 0x0F52C5A7, 0x94E20C7D, 0x926A7A1B} } ,
	 { {0xED8115CE, 0x5E014E91, 0x6047CB31, 0x25BEED91, 0x7AB64A14, 0x31D09CA0, 0xAB2BD239, 0x2B602B17},
	{0x795593B5, 0xAD805884, 0x1A475B9D, 0xCAB3E186, 0x5C5E4E72, 0x6E23F690, 0x4B0C3176, 0x9A14115B} } ,
	 { {0x2045C68C, 0x90FD6AFE, 0x42133E1E, 0x6541B38C, 0x2D997F65, 0x02529A72, 0x2BB42B62, 0x41464ED7},
	{0x981BC6FE, 0x00B31D40, 0x5E427F28, 0x6AE48A11, 0x6F18F938, 0x1B3725B7, 0x556A46FD, 0x6A91153E} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1045 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1046 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1047 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1048 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1049 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1050 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1051 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1A272E2C, 0x7E3BBD60, 0x2C7D7822, 0xD62B841A, 0xD82E94C3, 0x230C817A, 0xDE8AB5EB, 0x8D3F32E3},
	{0x7CF28B52, 0xCEEA8433, 0x688E8983, 0xD2DB615D, 0x32A52EA5, 0xF75DE2D5, 0xDE8E756A, 0x04CAD7CD} } ,
	 { {0x4443D48C, 0xE522040E, 0x6974F38B, 0xA61D0194, 0x444DF9EC, 0x269171B0, 0xCD0999E7, 0x82E68100},
	{0x84BA3E4D, 0x99025CE0, 0x56145100, 0xB05258B0, 0x6CC7A1E0, 0x6EFCE27F, 0xA36B1A71, 0x29D5C3FA} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x5F528F03, 0x405AA7B7, 0x7B20D672, 0x5A9167D9, 0x29B9803D, 0xD3EB6DF1, 0xFF92C73B, 0x4C8859AF},
	{0xD5B9D77B, 0x190717A0, 0xD9019A0E, 0x27E0F98F, 0x60B5AF27, 0xE495D4CB, 0x1F0864CD, 0x73A96D2E} } ,
	 { {0xBC795AA3, 0x568EF6F0, 0x0CFF75E0, 0x4A494B81, 0x59373BDC, 0x036FFDDD, 0x58227DC4, 0x4CD4AF65},
	{0x6DEEA0CA, 0x2F6BED0A, 0x48B24ACB, 0x772551D4, 0xDDD936BE, 0xE3C3F469, 0xB2126D27, 0x446CC6CD} } ,
	 { {0x265B747D, 0xCB557E6B, 0xFE7207D0, 0x39285687, 0x34B96A24, 0x51C286F5, 0x59F457A5, 0x4BB9633F},
	{0x09747C9A, 0x3204B9C1, 0xAC28A201, 0x60A4B160, 0xD98F43C1, 0xDDF9C4FE, 0x46D634E2, 0x53AB87F5} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1052 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1053 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1054 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1055 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1056 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1057 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1058 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x2BECB697, 0x2856DF31, 0x16A8EACE, 0x19C4EC0E, 0x7D8B4E71, 0xD357BA44, 0x73C93400, 0xA1499E2B},
	{0xC00664C3, 0x36E1E780, 0xDF8C27E7, 0xB258BBF4, 0x1A6F28E6, 0xB20ACE10, 0xD5019A52, 0x389D3A75} } ,
	 { {0x16126783, 0x7ADB4122, 0xE155EC0A, 0x62BD5F7D, 0x6DC6449D, 0x49651BB1, 0xCD81648F, 0x5E7AE6D4},
	{0xF57311A0, 0xD5898316, 0x001CADD8, 0xF8454DEB, 0x3B5D4E79, 0x0666190C, 0x7701BAB6, 0x09F1CE39} } ,
	 { {0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7342B7A3, 0x85226C2B, 0xE38E426A, 0x0064BA60, 0x2791BC9A, 0x165203C7, 0x0ED64D08, 0x56CD9FA8},
	{0x68AC9819, 0xD1301B11, 0xC4B73AE4, 0xBDB92EFE, 0x8CBAA724, 0x3098A223, 0x1719ADD2, 0xB8D0F94E} } ,
	 { {0x0D76EF5B, 0xAD689B42, 0x277A9A09, 0xA815B485, 0x67FAB9C0, 0x6056E12F, 0xE17D3E85, 0x544B20C3},
	{0x05BE75DC, 0x38E8B3D2, 0xB6DF3E4E, 0x46C3549A, 0xC11CFB37, 0x8639E935, 0xE0B5CF21, 0x81FFD171} } ,
	 { {0xC9F89A6B, 0xF6C7F892, 0xEE33F8CD, 0xB269125A, 0x87A9FF85, 0x9769DAF7, 0x5AE3ECF5, 0x02E22EE7},
	{0xEAE62340, 0xAB13062D, 0x00395BB1, 0xF08A9BD6, 0x76BA9CF3, 0x0CCC3218, 0xEE03756C, 0x13E39C72} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 1059 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 1060 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 1061 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 1062 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 1063 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 1064 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 1065 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6896D31E, 0xF502844C, 0x3D4CDCF2, 0xC6C1441A, 0x2018F99A, 0x8A68638A, 0x2E4CBDAC, 0x48C0DDE7},
	{0x818A397A, 0x2581A1D8, 0x03BCC47A, 0xF48B6E06, 0xA142349E, 0x07C027D3, 0x3CE75473, 0x257095D5} } ,
	 { {0x61753153, 0xEC150848, 0x0F9976B8, 0x928EED12, 0x9B179458, 0x31F820A5, 0x232B9A79, 0xAC2D08B5},
	{0xA98CF482, 0x865A8A46, 0x33AF6084, 0xE44DB075, 0x8934719E, 0x767F7A98, 0x84659E32, 0x704E16C9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x6896D31E, 0xF502844C, 0x3D4CDCF2, 0xC6C1441A, 0x2018F99A, 0x8A68638A, 0x2E4CBDAC, 0x48C0DDE7},
	{0x818A397A, 0x2581A1D8, 0x03BCC47A, 0xF48B6E06, 0xA142349E, 0x07C027D3, 0x3CE75473, 0x257095D5} } ,
	 { {0x00B70348, 0x12D98169, 0xC4DE688E, 0x8082BF8E, 0xB8CAF55C, 0xC9683BC5, 0x1CF341AF, 0x0DE6960D},
	{0xB89F4019, 0x7893FF6A, 0xA0C87EC2, 0x2EC3FC2B, 0xCAAE1816, 0x84E0E1D2, 0xBBB93DF6, 0x49C587F8} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1066 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1067 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1068 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1069 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1070 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xEC28A5C0, 0x59E11134, 0x159197FF, 0xF06CEF2C, 0x1C18C9AE, 0x9BC1FD39, 0xAA9EF3BB, 0x63E835CC},
	{0xED795AE3, 0xEDA9C0EA, 0x56F36448, 0x55AB72BA, 0xEF82A0B0, 0xA0FB1996, 0x3E1DAB97, 0x729D9BE7} } ,
	 { {0xE998FEA4, 0x5293D90F, 0x7A4845C9, 0xF5B7A408, 0x11790BA6, 0x03EF5549, 0x4810D9A0, 0xA7CF59A3},
	{0x3933B7DF, 0x11AD026F, 0x5B2FC5BD, 0xEA9848E9, 0x33DE7E0D, 0x1E4F3254, 0x50520DA3, 0x287D6A71} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xEC28A5C0, 0x59E11134, 0x159197FF, 0xF06CEF2C, 0x1C18C9AE, 0x9BC1FD39, 0xAA9EF3BB, 0x63E835CC},
	{0xED795AE3, 0xEDA9C0EA, 0x56F36448, 0x55AB72BA, 0xEF82A0B0, 0xA0FB1996, 0x3E1DAB97, 0x729D9BE7} } ,
	 { {0x789335F7, 0xAC5AB0A1, 0x5A2F997D, 0x1D5A0898, 0x42697E0E, 0xF7710722, 0xF80E0288, 0x1244451E},
	{0x28F87CBC, 0xED418742, 0x79481989, 0x287963B7, 0x20040BA7, 0xDD112A17, 0xEFCCCE85, 0x91963450} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1071 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1072 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1073 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1074 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1075 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7DAAB514, 0xD90D9129, 0x47D5D293, 0xFEED8CCF, 0x1484A309, 0x1BD0A082, 0xC28F6FE3, 0x2BBC5F7E},
	{0x2CF60B0A, 0x94F33889, 0xA8CE1CBE, 0x2FA52D3D, 0x7DB0F2B8, 0xDF364E85, 0x1E06A176, 0x9298362C} } ,
	 { {0x6565CB23, 0xD578F57B, 0x19E47E34, 0x430795A5, 0x87C2BEE4, 0x75AACC2F, 0xECF54F6D, 0x7BBD8B47},
	{0x1CA1881F, 0x44FF0F24, 0x5234A97F, 0xE333FFDE, 0xBC5DBFF2, 0x8091F718, 0xE0D71042, 0xB1927B51} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7DAAB514, 0xD90D9129, 0x47D5D293, 0xFEED8CCF, 0x1484A309, 0x1BD0A082, 0xC28F6FE3, 0x2BBC5F7E},
	{0x2CF60B0A, 0x94F33889, 0xA8CE1CBE, 0x2FA52D3D, 0x7DB0F2B8, 0xDF364E85, 0x1E06A176, 0x9298362C} } ,
	 { {0xFCC66978, 0x29759435, 0xBA936112, 0xD00A16FB, 0xCC1FCAD0, 0x85B5903B, 0x53298CBB, 0x3E56137A},
	{0x458AAC7C, 0xB9EF7A8D, 0x824335C7, 0x2FDDACC2, 0x9784C9C2, 0x7ACE6552, 0x5F47CBE6, 0x08812370} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1076 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1077 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1078 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1079 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1080 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x15326FD3, 0xBD909F6A, 0xF7C56311, 0x25F31109, 0x4BB43D73, 0x64C0B440, 0xF0E1414E, 0x281596A6},
	{0x510C1F90, 0xEAE5B019, 0xF77000EF, 0xF5644E2E, 0x414BCD09, 0x8E56E434, 0x3D5B1B51, 0x1EF92C57} } ,
	 { {0xC077C000, 0x84111CEE, 0x1BEE8F1F, 0x6E45E0C6, 0x8958CFAF, 0xD185BA6A, 0xAD7E7BF6, 0x827FD732},
	{0xC37A5173, 0xA28C5591, 0x927C064A, 0xC827F66A, 0xD40599DF, 0xDC8A320F, 0x10871AAF, 0x35372799} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x15326FD3, 0xBD909F6A, 0xF7C56311, 0x25F31109, 0x4BB43D73, 0x64C0B440, 0xF0E1414E, 0x281596A6},
	{0x510C1F90, 0xEAE5B019, 0xF77000EF, 0xF5644E2E, 0x414BCD09, 0x8E56E434, 0x3D5B1B51, 0x1EF92C57} } ,
	 { {0xA1B4749B, 0x7ADD6CC2, 0xB8895027, 0xA4CBCBDA, 0xCA89BA05, 0x29DAA200, 0x92A06032, 0x3793C78F},
	{0x9EB1E328, 0x5C62341F, 0x41FBD8FC, 0x4AE9B636, 0x7FDCEFD5, 0x1ED62A5B, 0x2F97C179, 0x84DC7729} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1081 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1082 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1083 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1084 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1085 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7241860E, 0x10A1AA52, 0x26572B26, 0xDB2BFDDA, 0xA5005A22, 0xF13E8DD1, 0xDFF51546, 0x1FA4F630},
	{0x7D6422BB, 0x85792DDF, 0xC3D22609, 0x1EA3DF4E, 0xB737AACC, 0x784C09B9, 0x1AFB75B4, 0x5B15A97D} } ,
	 { {0x92350051, 0xF28C642F, 0x359B0E7B, 0x4F2A299D, 0xC1B02899, 0xB1A1C4D1, 0x02C8EF8F, 0x1DCD3141},
	{0x76354184, 0xA93DE67E, 0x05FD09BC, 0x10482613, 0x5A6569BC, 0x5CFB6228, 0xCBFF28AE, 0xA72BD806} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7241860E, 0x10A1AA52, 0x26572B26, 0xDB2BFDDA, 0xA5005A22, 0xF13E8DD1, 0xDFF51546, 0x1FA4F630},
	{0x7D6422BB, 0x85792DDF, 0xC3D22609, 0x1EA3DF4E, 0xB737AACC, 0x784C09B9, 0x1AFB75B4, 0x5B15A97D} } ,
	 { {0xCFF7344A, 0x0C622581, 0x9EDCD0CB, 0xC3E78303, 0x9232611B, 0x49BE9799, 0x3D55EC99, 0x9C466D81},
	{0xEBF6F317, 0x55B0A332, 0xCE7AD58A, 0x02C9868D, 0xF97D1FF9, 0x9E64FA42, 0x741FB37A, 0x12E7C6BB} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1086 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1087 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1088 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1089 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1090 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE63A5C9D, 0x547848B1, 0x9EA83D90, 0xC8EF9F2E, 0x9BBDD907, 0xA448713D, 0xC85D3840, 0x75DDFB1D},
	{0xD3B64ADE, 0x8047D93B, 0xE18FE92D, 0x19C054B5, 0xEDF51F21, 0xC7A1D3AE, 0xE286C500, 0x81C5F799} } ,
	 { {0x6280FC45, 0xE6C47306, 0x2AEB8320, 0xF4769D1F, 0x9F8DBBEE, 0xDF6A33A4, 0x38F9A5A3, 0x4607CC8D},
	{0xB75DC024, 0x9E90DDFD, 0x9A065951, 0xC881DEF9, 0x03B5952D, 0x810342DD, 0xB3A3C675, 0xA3AFFED4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE63A5C9D, 0x547848B1, 0x9EA83D90, 0xC8EF9F2E, 0x9BBDD907, 0xA448713D, 0xC85D3840, 0x75DDFB1D},
	{0xD3B64ADE, 0x8047D93B, 0xE18FE92D, 0x19C054B5, 0xEDF51F21, 0xC7A1D3AE, 0xE286C500, 0x81C5F799} } ,
	 { {0xFFAB3856, 0x182A16AA, 0xA98C5C26, 0x1E9B0F81, 0xB454CDC6, 0x1BF628C6, 0x07253685, 0x740BD235},
	{0xAACE7477, 0x605DABB3, 0x3A7185F5, 0x4A8FCDA7, 0x502CF487, 0x7A5D198E, 0x8C7B15B3, 0x16639FED} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1091 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1092 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1093 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1094 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1095 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBE55D681, 0x95C9EB84, 0x63C7952D, 0xAB408370, 0x87421964, 0x79E8F1AC, 0x009E2BDF, 0x669CA48A},
	{0x4B2E2882, 0x384AEE47, 0xC70F2DA3, 0xEBAC0F89, 0x3D27ED2A, 0xD50BC6A1, 0x078F6E49, 0x5F61FA65} } ,
	 { {0x90999905, 0xC6819C22, 0xC2CB7839, 0xC2830B1E, 0x387E2905, 0x418D36B9, 0x2E9A1F08, 0x430E523E},
	{0xDAD50AF3, 0x11D49124, 0x4665E4C6, 0xE65731BA, 0xD5E447B3, 0x817A165F, 0xAB1190BD, 0x55BFFAD3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xBE55D681, 0x95C9EB84, 0x63C7952D, 0xAB408370, 0x87421964, 0x79E8F1AC, 0x009E2BDF, 0x669CA48A},
	{0x4B2E2882, 0x384AEE47, 0xC70F2DA3, 0xEBAC0F89, 0x3D27ED2A, 0xD50BC6A1, 0x078F6E49, 0x5F61FA65} } ,
	 { {0xD1929B96, 0x386CED8E, 0x11AC670D, 0x508EA182, 0x1B6460AF, 0xB9D325B2, 0x1184BD20, 0x77054C84},
	{0x875729A8, 0xED19F88C, 0x8E11FA80, 0x2CBA7AE6, 0x7DFE4201, 0x79E6460B, 0x950D4B6B, 0x6453A3EE} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1096 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1097 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1098 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1099 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1100 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7FAF9FAC, 0x02B0AC31, 0x9CCA872B, 0xC1786C3F, 0x5882CC1D, 0x49CCC9A1, 0x995111E9, 0x40B4BF01},
	{0x170BE0BD, 0xBF724437, 0x4095F334, 0x4C87B958, 0x8D4E32EC, 0x42C84396, 0xEAADD4D1, 0x4FC092DB} } ,
	 { {0x6006A434, 0x47B8451D, 0xDB61EB2F, 0xF1200D42, 0xC3B964E3, 0x69DB02CD, 0x7F0D35F8, 0x8628DFEC},
	{0xBAF82BE0, 0xEB62D892, 0x15512F2B, 0x9A186EB0, 0x48498DD4, 0xE99E0D97, 0xE29D599F, 0x9FD2BE67} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7FAF9FAC, 0x02B0AC31, 0x9CCA872B, 0xC1786C3F, 0x5882CC1D, 0x49CCC9A1, 0x995111E9, 0x40B4BF01},
	{0x170BE0BD, 0xBF724437, 0x4095F334, 0x4C87B958, 0x8D4E32EC, 0x42C84396, 0xEAADD4D1, 0x4FC092DB} } ,
	 { {0x02259067, 0xB7364494, 0xF915F417, 0x21F19F5D, 0x902924D1, 0x9185599D, 0xC111A630, 0x33EABED5},
	{0xA73408BB, 0x138BB11E, 0xBF26B01B, 0x78F93DF0, 0x0B98FBE0, 0x11C24ED4, 0x5D818289, 0x1A40E05A} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 1101 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 1102 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 1103 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 1104 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 1105 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x831F567C, 0x54A94AB2, 0x5545E16C, 0x41A45BE5, 0x6B11CDFE, 0x09F57091, 0xB3FD0581, 0x09978C97},
	{0x2B972DCD, 0x348142FC, 0x95E5930B, 0x331629EB, 0x8146146E, 0xC91CB851, 0x523B538A, 0x45C25FC6} } ,
	 { {0x218A3B23, 0xCF9CD571, 0x82546BD7, 0x36EA2D17, 0x713E5E8A, 0x0B9D1D6D, 0xE5B681E8, 0x8B400AAE},
	{0x8BC2E925, 0x314980AD, 0x60BB389F, 0x9D62F951, 0x559ABC20, 0x838828A8, 0xE0C1D994, 0x2266C097} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x831F567C, 0x54A94AB2, 0x5545E16C, 0x41A45BE5, 0x6B11CDFE, 0x09F57091, 0xB3FD0581, 0x09978C97},
	{0x2B972DCD, 0x348142FC, 0x95E5930B, 0x331629EB, 0x8146146E, 0xC91CB851, 0x523B538A, 0x45C25FC6} } ,
	 { {0x40A1F978, 0x2F51B440, 0x5223736F, 0xDC277F89, 0xE2A42B2A, 0xEFC33EFD, 0x5A685A40, 0x2ED39413},
	{0xD6694B76, 0xCDA50903, 0x73BCA6A7, 0x75AEB34F, 0xFE47CD94, 0x77D833C2, 0x5F5D0294, 0x97ACDE2A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1106 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1107 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1108 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1109 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1110 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1111 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1112 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC2AFC3F3, 0x590510A9, 0xC1F6EA5C, 0x7442369E, 0xFF8F7D48, 0x345181AC, 0x06260FDC, 0x6F054CCB},
	{0x92CAFEBD, 0xCDA21CB6, 0xBF3D9DBF, 0x995D2343, 0x8A15BB76, 0xCEA188B5, 0x6846EFE0, 0x2CB8884D} } ,
	 { {0x55F58E55, 0x045BA9DB, 0xD3E8A7F7, 0x0A0F40BB, 0x197E510E, 0x60A0FBA6, 0xC298D2B9, 0x02D21CDE},
	{0x8A793B15, 0xFF08F7FF, 0xB31BC8E7, 0xB98CFE32, 0x6A3BED6F, 0xB9338407, 0x4F5652F9, 0x46602F11} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xC2AFC3F3, 0x590510A9, 0xC1F6EA5C, 0x7442369E, 0xFF8F7D48, 0x345181AC, 0x06260FDC, 0x6F054CCB},
	{0x92CAFEBD, 0xCDA21CB6, 0xBF3D9DBF, 0x995D2343, 0x8A15BB76, 0xCEA188B5, 0x6846EFE0, 0x2CB8884D} } ,
	 { {0x0C36A646, 0xFA92DFD6, 0x008F374F, 0x09026BE5, 0x3A6438A7, 0x9ABF60C5, 0x7D86096F, 0xB74181E3},
	{0xD7B2F986, 0xFFE591B1, 0x215C165E, 0x5984AE6E, 0xE9A69C45, 0x422CD863, 0xF0C8892F, 0x73B36FB0} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1113 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1114 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1115 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1116 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1117 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1118 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1119 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB2E5BE90, 0x87070663, 0x9BF20BE3, 0xF7CE2494, 0x19A6D013, 0xF5E7B8D8, 0xDD8D835E, 0x91FDD773},
	{0x4B036BE0, 0x3293CE58, 0x81D4CD95, 0x1B95BB8D, 0xF48303BD, 0x149A88FB, 0xE9AF418A, 0x56F1C0B7} } ,
	 { {0x003E0E9D, 0x0280CE12, 0x8BC87AEF, 0xFC07100C, 0x14ADF5FD, 0xADC20635, 0xA144EFFD, 0x884FA117},
	{0xB6127D1C, 0x014251AF, 0x50DFB06A, 0xA2675D3C, 0x9C97BF0F, 0x082ED46D, 0xB251CECE, 0xB65AFD80} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB2E5BE90, 0x87070663, 0x9BF20BE3, 0xF7CE2494, 0x19A6D013, 0xF5E7B8D8, 0xDD8D835E, 0x91FDD773},
	{0x4B036BE0, 0x3293CE58, 0x81D4CD95, 0x1B95BB8D, 0xF48303BD, 0x149A88FB, 0xE9AF418A, 0x56F1C0B7} } ,
	 { {0x61EE25FE, 0xFC6DBB9F, 0x48AF6457, 0x170A9C94, 0x3F3493B7, 0x4D9E5636, 0x9ED9EC2B, 0x31C3FDAA},
	{0xAC19B77F, 0xFDAC3801, 0x83982EDC, 0x70AA4F64, 0xB74ACAA5, 0xF33187FD, 0x8DCD0D5A, 0x03B8A141} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1120 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1121 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1122 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1123 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1124 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1125 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1126 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x71933EB0, 0x459D9207, 0xC773ADE4, 0x4A978EE1, 0x4AB3EB7B, 0x12945D97, 0x69086409, 0x12DDEDBC},
	{0xB9017859, 0xA9D8AB65, 0x60A1B7F6, 0x6D1F4799, 0x4C9113B2, 0xFDACD190, 0xB20E5E48, 0x4F33B37C} } ,
	 { {0x242ADDF0, 0x9875BBE6, 0x6E0736EB, 0xFFA1C3DA, 0x8B8DE5D4, 0xD910757B, 0x66DDF18B, 0x84F6F522},
	{0x8A681176, 0xD84882F2, 0xC8DD61FE, 0x94A06028, 0x0DBF633D, 0x6D779196, 0x027BDA6F, 0x8811B2FE} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x71933EB0, 0x459D9207, 0xC773ADE4, 0x4A978EE1, 0x4AB3EB7B, 0x12945D97, 0x69086409, 0x12DDEDBC},
	{0xB9017859, 0xA9D8AB65, 0x60A1B7F6, 0x6D1F4799, 0x4C9113B2, 0xFDACD190, 0xB20E5E48, 0x4F33B37C} } ,
	 { {0x3E0156AB, 0x6678CDCB, 0x6670A85B, 0x136FE8C6, 0xC854A3E0, 0x224FE6EF, 0xD940EA9D, 0x351CA99F},
	{0xD7C42325, 0x26A606BE, 0x0B9A7D48, 0x7E714C78, 0x46232677, 0x8DE8CAD5, 0x3DA301B9, 0x3201EBC4} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1127 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1128 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1129 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1130 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1131 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1132 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1133 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x09E9BE7C, 0xD067D965, 0x431C4BD9, 0x4F9BAEF7, 0x15097C54, 0x308F31CD, 0x6AC389C2, 0x759A10F4},
	{0x8E768904, 0xFCA11E57, 0x30E187E7, 0xEA80126C, 0x4F038A46, 0x2CD24EF1, 0xD3E6D787, 0x8B5B926B} } ,
	 { {0xBD0F1643, 0xD4B8553D, 0x5D6C85BB, 0x09758D5A, 0xDBD383B2, 0x887955AC, 0xD987F693, 0x901B10A6},
	{0x16528CFB, 0xD73B3D94, 0x00F42DB1, 0x5F444DCF, 0xC74C268B, 0xE0A8E37E, 0xA8347CE4, 0x873E28A5} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x09E9BE7C, 0xD067D965, 0x431C4BD9, 0x4F9BAEF7, 0x15097C54, 0x308F31CD, 0x6AC389C2, 0x759A10F4},
	{0x8E768904, 0xFCA11E57, 0x30E187E7, 0xEA80126C, 0x4F038A46, 0x2CD24EF1, 0xD3E6D787, 0x8B5B926B} } ,
	 { {0xA51D1E58, 0x2A363473, 0x770B598B, 0x099C1F46, 0x780F0603, 0x72E706BE, 0x6696E595, 0x29F88E1B},
	{0x4BD9A7A0, 0x27B34C1D, 0xD383B195, 0xB3CD5ED1, 0x8C966329, 0x1AB778EC, 0x97EA5F44, 0x32D5761C} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1134 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1135 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1136 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1137 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1138 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1139 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1140 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x7F4BCBD7, 0xEC53F76C, 0x5F72E20B, 0x8319BDB2, 0x1D2D39B1, 0x11AAD22F, 0x5A786FFA, 0xAF62AFCF},
	{0xDFC2E3FD, 0x38626C65, 0xFF2B07C5, 0xBB3AC948, 0x21B8837D, 0xFBC76D61, 0x98A3950A, 0x04211C4B} } ,
	 { {0x56338CD1, 0x1617F678, 0xFD8F5DAF, 0xA02427D5, 0xCEE699F7, 0x9CF22271, 0xB238AA99, 0xB3D6D6CD},
	{0x2C686B41, 0xD698465A, 0x58601727, 0x8A2D56A1, 0xE1DEEC31, 0xEFEC33D4, 0x1AB1E666, 0x1D731623} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7F4BCBD7, 0xEC53F76C, 0x5F72E20B, 0x8319BDB2, 0x1D2D39B1, 0x11AAD22F, 0x5A786FFA, 0xAF62AFCF},
	{0xDFC2E3FD, 0x38626C65, 0xFF2B07C5, 0xBB3AC948, 0x21B8837D, 0xFBC76D61, 0x98A3950A, 0x04211C4B} } ,
	 { {0x0BF8A7CA, 0xE8D69339, 0xD6E88197, 0x72ED84CA, 0x84FBEFBD, 0x5E6E39F9, 0x8DE6318F, 0x063CC7F4},
	{0x35C3C95A, 0x28564357, 0x7C17C81F, 0x88E455FF, 0x72039D83, 0x0B742896, 0x256CF5C2, 0x9CA0889F} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1141 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1142 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1143 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1144 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1145 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1146 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1147 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x02847709, 0xCEE7EA87, 0xB090B41E, 0x0B2A9862, 0x47D8A20C, 0x81BBB308, 0xB8E0C91E, 0x83C553D2},
	{0x6D6BF639, 0xABEDD5FB, 0x87BAA03B, 0x3EBAF36A, 0x2D4829E7, 0x92898DD8, 0xC6C055FD, 0x406EC988} } ,
	 { {0x5245684C, 0x52ADB402, 0x850C87E7, 0x6B89D5A3, 0x4B91A62E, 0xA8D2CDA7, 0x862338E2, 0x0F8A85C1},
	{0x181168FA, 0xD7E24F1A, 0xCC00330F, 0xCFF98307, 0xE9D268ED, 0x25AE2250, 0xCAD6ED28, 0x31ED37BE} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x02847709, 0xCEE7EA87, 0xB090B41E, 0x0B2A9862, 0x47D8A20C, 0x81BBB308, 0xB8E0C91E, 0x83C553D2},
	{0x6D6BF639, 0xABEDD5FB, 0x87BAA03B, 0x3EBAF36A, 0x2D4829E7, 0x92898DD8, 0xC6C055FD, 0x406EC988} } ,
	 { {0x0FE6CC4F, 0xAC40D5AF, 0x4F6B575F, 0xA787D6FD, 0x0850E386, 0x528D8EC4, 0xB9FBA346, 0xAA891900},
	{0x4A1ACBA1, 0x270C3A97, 0x0877AC37, 0x43182999, 0x6A1020C7, 0xD5B23A1A, 0x7547EF00, 0x88266703} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1148 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1149 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1150 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1151 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1152 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1153 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1154 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA81689DE, 0x6B519581, 0xA5042A22, 0x23461381, 0xA2CCCF62, 0x5DC889FB, 0x7A004464, 0x0E10DCF1},
	{0x0DA36C23, 0x9189A430, 0xCCF3DF9B, 0xAB3E6AB5, 0x25BC9BDA, 0x2046224E, 0xB01B0888, 0x4DAF537B} } ,
	 { {0xB2F7E1A1, 0x39CF2532, 0x27D3DF2A, 0x8A6772D7, 0x71DB2389, 0x3C334B4F, 0x5D0A4228, 0x12109938},
	{0x8DCED569, 0x9311FCE1, 0x4A100425, 0x76F7E338, 0x7371D220, 0xCE1BDAC3, 0x2954D042, 0xABCB19DF} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA81689DE, 0x6B519581, 0xA5042A22, 0x23461381, 0xA2CCCF62, 0x5DC889FB, 0x7A004464, 0x0E10DCF1},
	{0x0DA36C23, 0x9189A430, 0xCCF3DF9B, 0xAB3E6AB5, 0x25BC9BDA, 0x2046224E, 0xB01B0888, 0x4DAF537B} } ,
	 { {0xAF3452FA, 0xC51F647E, 0xACA4001C, 0x88AA39C9, 0xE207662B, 0xBF2D111B, 0xE3149A00, 0xA8030589},
	{0xD45D5F32, 0x6BDC8CCF, 0x8A67DB21, 0x9C19C968, 0xE070B794, 0x2D4481A7, 0x16CA0BE6, 0x0E4884E3} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 1155 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 1156 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 1157 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 1158 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 1159 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 1160 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 1161 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1162 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1163 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1164 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1165 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1166 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0x0064FD84, 0x8B135350, 0xEA32A23E, 0x3857748A, 0xC9A5CA82, 0x69B5A041, 0x944FDA38, 0x1781A4FD},
	{0xFE2CFE50, 0x05D4DDB8, 0xF6FEDAAE, 0x93C0FD19, 0x63EFFDE3, 0x46DAEA5A, 0xDA84A42C, 0x1BEFBA94} } ,
	 { {0xAC17408E, 0x81D4EACB, 0xE0A423F4, 0x251CBE89, 0x17BA8F0E, 0x284D1C44, 0xC66A4521, 0x5C4B58D2},
	{0xF259F224, 0x3E705BE3, 0x92FA9BC8, 0x85F8C96F, 0x593A4B3A, 0xC5079ABA, 0x69AEF095, 0x22E51011} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1167 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1168 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1169 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1170 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1171 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0xED88EDCD, 0xFEBD0E1B, 0x05FB1ADC, 0x44BBCBF4, 0x32E39884, 0xD7042C09, 0x3CB22E2E, 0x980DA10C},
	{0xAA650FB4, 0x057DCDD0, 0x53F14C75, 0xA538CB5B, 0xC0B0D166, 0x0F1D5E56, 0x3DCF8B1B, 0xB33CB5D5} } ,
	 { {0x809E647C, 0x9A294B8E, 0x99BBEFDB, 0x18198F95, 0x6CF33D15, 0xF7F05CD4, 0x0D22CC2A, 0x3CB9744E},
	{0x8EEA6518, 0x7A7FB17E, 0xF215575B, 0x68927624, 0x9E3BDBA5, 0xE9CE57E1, 0x0C981AC7, 0x82B90553} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1172 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1173 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1174 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1175 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1176 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0xF2A53FFD, 0x04247D2C, 0x368D3E63, 0x6A6E6A24, 0xBDCC5503, 0x3C94E6A4, 0xE95A1FCA, 0xABEFC387},
	{0xF4704A59, 0x06A4BD04, 0x0D8004FF, 0x5A951B0C, 0x7ED9667B, 0x241B69F8, 0x55E35869, 0x2BDCB0B1} } ,
	 { {0x8C35979E, 0xB567C8BD, 0x9A9D1966, 0x306B3F72, 0x059412BD, 0xFE7D0F83, 0x4C102E88, 0x5FC4F429},
	{0x1FDCD576, 0xB41774D3, 0xBAEF3CEE, 0xE28C7ABE, 0x5191C6FA, 0x69B611BC, 0x7B2093D4, 0xAD72BD4E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1177 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1178 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1179 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1180 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1181 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0x8DBF6D39, 0x3FE5512E, 0x948AFA6C, 0xB12B35DD, 0xDD24CDCE, 0x3EAF1A78, 0x37E9815C, 0x47BFDA3E},
	{0xF4EEADC2, 0xB50F226F, 0xCC98D32F, 0x11CD80D3, 0xD28EC9FD, 0xBD5747A1, 0xAD0888BB, 0x75183153} } ,
	 { {0x7F8B0EF5, 0xA4E634B5, 0x0C0D44F2, 0xFD4A9FDE, 0xA3AC9DFD, 0xBDF02424, 0x7C7C154F, 0xA04C6F5A},
	{0xFA66C7E6, 0x73955FA3, 0xFD106938, 0x65995942, 0x7F06D119, 0x9D1BA0BD, 0x8385BC6F, 0x41F72668} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1182 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1183 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1184 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1185 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1186 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF448E74E, 0x089C9483, 0x7FCDE796, 0xAA32FFB9, 0x0D4300CE, 0x05AB3311, 0xCD3E3429, 0x499F9609},
	{0xE4CA057A, 0xAAD5311B, 0x2939F1B2, 0x809B3867, 0xB20B6E22, 0xFDD00B2B, 0xBD306454, 0x030ABA5D} } ,
	 { {0xF1414CF5, 0x70BE07E8, 0xBAA85EDB, 0x0E8E5BAC, 0x5A044C45, 0x460A5B9F, 0x70786AF9, 0x487D8AD7},
	{0xF4332F93, 0xC9B27EB3, 0x2BBC71A2, 0xB0093756, 0x894F67A4, 0xF1C9D537, 0x9DAB54D5, 0x776E6F73} } ,
	0};
		static bigint_t var_k = {0xFD983ED0, 0x1A26E1F8, 0xF12357A7, 0xC801F1FB, 0xB737A25E, 0x134A2ACF, 0x02BC7901, 0x020CA097};
		static ecpoint_fp2 var_expected = { { {0xBC66157B, 0x7BF2C087, 0xDF0ACC03, 0x36E726EF, 0xCD7E70EB, 0x8998DAD3, 0x4CD5F913, 0x028DDD0F},
	{0x09125263, 0xDF2BD497, 0x6957A20E, 0xB5B58AC1, 0xE6B71AFB, 0xB2873517, 0x77DD6755, 0x96B54B41} } ,
	 { {0x51DED614, 0x12DCFDF3, 0x6B4DC652, 0x80ED81D9, 0x1FBEEEE6, 0x19D8BAF5, 0xF81033BB, 0x0109B3AE},
	{0x39BA855B, 0x96FA1E4D, 0x5C6C8FBD, 0x4A29A715, 0xEE41FCC0, 0x32A2C722, 0x1CC276A6, 0x5C471A8D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1187 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1188 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1189 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1190 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1191 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xAABD7667, 0x6D7EC159, 0xB854C3B3, 0x75939A49, 0xCD85353D, 0x02FF306D, 0x675CB44B, 0x5551CEE6},
	{0x5B66F439, 0x5E5459AC, 0xD7EDB3B0, 0xDF774E6B, 0xEFC1E2A4, 0x777D0F5E, 0x05883D2B, 0x408CE4E8} } ,
	 { {0x366DF3B8, 0x28563A2C, 0x13A30685, 0x2760879F, 0x11B97CC5, 0x0133AA13, 0x98974C93, 0x74B931D2},
	{0x9C72FFC3, 0xEE583758, 0x5821CBA6, 0x639B7283, 0xB2D42495, 0x391717EF, 0x347C4820, 0x43E1B93A} } ,
	0};
		static bigint_t var_k = {0x813EDDF6, 0xC7D4EA42, 0xF8C45B43, 0xFF1B0BE7, 0x0BA128F7, 0xC54F6D50, 0xA1636A5F, 0x35B83467};
		static ecpoint_fp2 var_expected = { { {0x9DCD16DE, 0x5E47761B, 0x173233AF, 0x1490D993, 0x5A760932, 0xC5DAD55E, 0xDC5ED7EA, 0x7579B576},
	{0x71CA24E1, 0x4272CDAA, 0x8040CFD0, 0x2D738426, 0x91E8324F, 0x0321CD0D, 0xF4D09504, 0x61C0DE41} } ,
	 { {0x6328D5BF, 0xB067ECCB, 0x8E657492, 0xB048AF4C, 0xA34D5073, 0x2CA11757, 0x6B1BFA04, 0xB394DE08},
	{0xD90E8F58, 0xD8ABC327, 0xECDAA4FC, 0x25EC43B3, 0x142F3EF3, 0xDC4FDFB5, 0xA07D86A1, 0x7D79392D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1192 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1193 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1194 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1195 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1196 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1913DE5D, 0x83E6D9C3, 0x67DD56C7, 0xF4E5F084, 0xC3824303, 0x660338EF, 0xB885B691, 0x8177BB5A},
	{0xB45F3E36, 0x81D4801D, 0x4F8325C9, 0xF1DCE92C, 0xCF411EC4, 0x84F9E7DE, 0xD80C5863, 0xA168E0B5} } ,
	 { {0x3B0A1C37, 0x7D949253, 0x045B1C69, 0xA0DE5099, 0x81F89E77, 0x607E5E1C, 0x9FFF0D59, 0x4CF1BC27},
	{0xEED945EE, 0xF3CB12E2, 0xCE233DE5, 0x76B5EABF, 0x74884774, 0xBB7DD945, 0xBE20A7B9, 0x30535224} } ,
	0};
		static bigint_t var_k = {0x683DA532, 0xE8113558, 0x389DE376, 0xABC989A5, 0x4375FE7E, 0xF6999A26, 0x5C34E7C5, 0x937AB7B5};
		static ecpoint_fp2 var_expected = { { {0x83B7F860, 0x32023390, 0x319E812E, 0x744326BC, 0x2E85FD3B, 0xF7783E1B, 0x01C12751, 0x2B4FC6B1},
	{0xFC60B553, 0xB9C34FF5, 0x7A1975AD, 0x64DCFE22, 0x6566408F, 0xF3D20B3E, 0x92D009E3, 0x932A53A1} } ,
	 { {0x4CE407FE, 0xDE15E9BD, 0xA96486F5, 0x653018DA, 0x737E2131, 0x46567493, 0xFAE053BF, 0x5ED9768B},
	{0x00E74E60, 0xC3F23DD9, 0x1E2C2B6E, 0xECB1473C, 0xB3C3C103, 0x96DBAFBF, 0xCA62C6BF, 0x67F6949F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1197 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1198 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1199 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1200 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1201 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDABA0515, 0xAD3CE768, 0xF2BC25F0, 0xD0F95C09, 0xD41E5BD2, 0x0FD126AC, 0x60B51217, 0x822C1E3E},
	{0x10CF81E7, 0x32BAB11D, 0x84864745, 0x48CE3527, 0x21772C39, 0xA560B825, 0x9C38B933, 0x4DEFADEE} } ,
	 { {0x706FDF87, 0x65A1FE8D, 0x733DBDF5, 0x47683D81, 0xE9C25F7B, 0xED425A49, 0x94C685D2, 0x95A92A41},
	{0x31903CA8, 0x2A6B85B5, 0xE6BB5055, 0xBC07CD64, 0x757A8BC7, 0xA757B439, 0xDBD8C8E2, 0x8F3FE8F0} } ,
	0};
		static bigint_t var_k = {0x3643BC74, 0xF531F507, 0x6EFB30F6, 0x5E224DE0, 0x93C34773, 0x8F171444, 0x1EBB1160, 0x9D83C903};
		static ecpoint_fp2 var_expected = { { {0x349C4A51, 0xC35A2531, 0x6584F89E, 0x1C75875F, 0xC8F5EB9E, 0xCC41ED65, 0x68A9CB1B, 0x11E1DD01},
	{0xC995BC89, 0x8107A134, 0x854C75C1, 0xF17520F1, 0x8253A356, 0xC98426CE, 0x7CD242DD, 0x91EE8802} } ,
	 { {0x197AFE57, 0xFA8AED9A, 0xD06B3CFD, 0xD48BC858, 0x7EFC7408, 0x9E184D3D, 0x7257BDA5, 0x666CFBFF},
	{0x21788176, 0xF689F100, 0x9C059325, 0x4DF4D808, 0xA88E272B, 0x7C1D590F, 0xD2945B78, 0x20610D66} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1202 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1203 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1204 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1205 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1206 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8795EEE5, 0x5E02A2CD, 0x6198834E, 0xEF09FE9D, 0x8592D0D8, 0x1048DDD0, 0x3D9FCFCD, 0x18C7E070},
	{0x07ECA4EF, 0x3AFA24E6, 0xA203338D, 0x37CB8770, 0x7CC42C84, 0x19587C29, 0x60F05040, 0x1FF9B86C} } ,
	 { {0x38FFC7E9, 0x312DEC93, 0xC0C6836F, 0x438186DC, 0x5C8CFC45, 0x972CAA8E, 0x57E5D8EA, 0x2008554A},
	{0xF70D8F58, 0x2259A86A, 0x3B02D328, 0x97CFFAE6, 0x9E148409, 0xB9AA9B66, 0xF682DF8E, 0x2E472A27} } ,
	0};
		static bigint_t var_k = {0xB06852C3, 0xA9993200, 0x95575B98, 0xE7431E46, 0x71D24EA6, 0xBA432999, 0x169AEC1F, 0x14262D97};
		static ecpoint_fp2 var_expected = { { {0x39F654C9, 0xC26162AB, 0xC997E364, 0xB2F37D20, 0xE5303390, 0xCA42231B, 0xA2247A19, 0xA9C0A62F},
	{0x4B1AAE9B, 0x7A119EA8, 0x22B23875, 0xD3771AC8, 0x58F19012, 0xFF9D67A5, 0x11551C2D, 0x0ADDB9DE} } ,
	 { {0xAF9AAA5F, 0x393C133F, 0xC2EA7946, 0x24308F9B, 0xF6C6AFE1, 0xB5F11F5C, 0x8FBFB000, 0x59E3F652},
	{0xDA8C4C45, 0x8C417C67, 0x56CBB844, 0xB045D839, 0x0B9421B5, 0x3954330B, 0x5AD46C58, 0x8512B96F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1207 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1208 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1209 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1210 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1211 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x52AC9DED, 0x99ABDBB4, 0x96015ADA, 0xB5AB76E8, 0x9098BA9D, 0x90E6D21E, 0x57375F5C, 0x7CB25E46},
	{0x604B7F69, 0xB97E7FB0, 0x89FADEFA, 0x69506647, 0xEAF9A483, 0x724B27F4, 0x09958137, 0xB325EE05} } ,
	 { {0x31B7FC89, 0x28485360, 0x649AF19A, 0xD82CE255, 0x8A9120E4, 0xFE2203A2, 0x184198DF, 0x88EA7504},
	{0xA24B07D8, 0x62FD85A0, 0x1CD9CB57, 0xB8CFB290, 0x0DA51DCE, 0x150EDE57, 0x75F5F085, 0x4E393DF8} } ,
	0};
		static bigint_t var_k = {0xDC81132A, 0xFB4D6B83, 0xEC22EC67, 0x5962FDAC, 0x906F80DE, 0xE0B592F7, 0xB058CBD9, 0xF8E6528A};
		static ecpoint_fp2 var_expected = { { {0x9D0C21D9, 0x7D11895D, 0x2A32696F, 0xAB532641, 0xB7911C0A, 0x3728769F, 0xD4BB9613, 0x116835ED},
	{0x0A1E9972, 0x7C4DAA7D, 0x78C10ACF, 0x9BC670CB, 0x03A1272F, 0x7364F32D, 0x0939A4C1, 0x6D6C0670} } ,
	 { {0x738CE689, 0x1AD859B8, 0xE05C152D, 0x5A5F69F5, 0x420AF62F, 0x68FA37EF, 0xB30FA237, 0x6EF0FE97},
	{0x9F7DB52B, 0x0F0C6EEE, 0x8D2E7D85, 0x849E7CD7, 0x20235E63, 0xB74F5088, 0xFBFF4279, 0x486B5534} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1212 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1213 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1214 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1215 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1216 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB1ED7506, 0x4049B8D3, 0x9F2ED497, 0x1913FA1C, 0xC9319909, 0x99B7C7FE, 0xD068881C, 0xB785EE7B},
	{0xE44C5E14, 0xC0C8B457, 0xA2953D5A, 0x463BC2C9, 0xC825A5A0, 0xD340B2D1, 0xB74CBD02, 0x8BB2CBD5} } ,
	 { {0xBAF3BB3D, 0xA9AE399E, 0xCD8B6DD3, 0x3C24DB20, 0x55209DF7, 0x5D05DC7C, 0xB8F0AF37, 0x2E53A6CE},
	{0xB3DE7CEA, 0xBB8F997A, 0x7A71176C, 0x6AFB1C86, 0x57EE617C, 0x99924304, 0x072DE49F, 0x69D89B79} } ,
	0};
		static bigint_t var_k = {0xFE6D8CE9, 0x24847C10, 0xEF974F54, 0x04D81363, 0xE73F1C6D, 0xA9B1F10B, 0x9933565B, 0x8C8D4A19};
		static ecpoint_fp2 var_expected = { { {0x25CADA53, 0xA4FC2E99, 0xA2ADED43, 0x037683D5, 0xB0D86070, 0x39DFE213, 0x0A566831, 0x2CDE5926},
	{0xD926AE00, 0x3551E87B, 0xCBFB7976, 0x5E715739, 0x1588EDA8, 0x9ECC3A16, 0x5E3B2B93, 0x1869613C} } ,
	 { {0xE26FDCC5, 0x732C1533, 0x4A5B0634, 0x4139FEFC, 0x7412867E, 0xE2DC8310, 0xAE705F4F, 0x3664A77C},
	{0xC23DEB95, 0xAB0922ED, 0x2BB04444, 0x77DFDB47, 0x384743EC, 0x430337C2, 0xC628BEAD, 0x00415BA0} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1217 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1218 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1219 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1220 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1221 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB5AA1415, 0xE24ABD14, 0x1C2F9067, 0xDEA1BD49, 0x152BF3E9, 0xD5BBDB05, 0x71E4CC27, 0x2A1D2B05},
	{0xCE491DC3, 0x1935BCCE, 0x77F41B00, 0x0DBCBB51, 0xAE329491, 0x490E063C, 0x394DB39C, 0x7CA43D88} } ,
	 { {0xC80B048D, 0x6BFB8AD5, 0x06BC6EF4, 0x4D7B9CA6, 0xEAD5AD2C, 0x17F1CEB6, 0x6DCA95AD, 0xB1C81C3C},
	{0x9F82CDA2, 0x7F9EFE2C, 0x68CDCD8C, 0x464A3FF6, 0x5B5B1FAA, 0xFB6492BD, 0x7D203A59, 0x732D97DD} } ,
	0};
		static bigint_t var_k = {0x9C67848A, 0x9F31CF15, 0x5C8A1961, 0x79354AE0, 0xAA0F9911, 0xFEB653F6, 0xBEEC218B, 0x4F33184D};
		static ecpoint_fp2 var_expected = { { {0xB31D7E39, 0xCC3C615A, 0x6BFAB64F, 0x3DCBDC2E, 0x45A2190E, 0xA6409EAE, 0xA6CD1255, 0x6F0B68AD},
	{0xC053A407, 0xA8F0EA94, 0x41D6C1D6, 0xC7C55E7B, 0xEE1B46D0, 0x34FCAD44, 0x1ABB7528, 0x5B0DCC75} } ,
	 { {0xB6A2F16C, 0x6EA332CE, 0xB5794F7E, 0xDE58C28F, 0x68A684C7, 0x47446EBC, 0xB57077DA, 0x5DC0EEF2},
	{0x6CB2FEFC, 0xF3F816BA, 0xAB00379D, 0xB18F6469, 0xB2CD8766, 0x9B043D45, 0x4E9153CC, 0x01BBC20D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1222 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1223 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1224 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1225 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1226 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6767CC29, 0x96DCC54D, 0x994AE52D, 0xB84AA1A8, 0x8E443A9D, 0xA9285334, 0xE428597D, 0x2FBB267C},
	{0x5312AE3B, 0x0465C21C, 0x801A675E, 0xC8B69767, 0x0BEE99B7, 0x4CF48446, 0xC18B4030, 0x5BC74A19} } ,
	 { {0xDBC79FE4, 0xCE11D176, 0x1C8FFC39, 0x785E4F27, 0x2E46142C, 0xD66EEBFB, 0xC479DEB5, 0xB110D2F6},
	{0xEFB9304A, 0x4690E72D, 0xCDE2B35E, 0x8F735EF8, 0x7FB20CCC, 0x350793FE, 0xDB6584A8, 0x1CE40235} } ,
	0};
		static bigint_t var_k = {0x7A544ABA, 0x239CC808, 0x2E371E70, 0x89518249, 0x4E22BDBE, 0x0912BA4A, 0x4C9BDBDD, 0x04546D66};
		static ecpoint_fp2 var_expected = { { {0xD4D7479E, 0xE548E376, 0x30138404, 0xBD5D00AE, 0x48C2D7A1, 0x439FD516, 0xAE774B35, 0x87BE2698},
	{0x63DF9AC4, 0x3DEF3795, 0x977849F5, 0xE0D31FBD, 0x2C8930C6, 0x58F0D81E, 0x4C1D177F, 0x59232CE3} } ,
	 { {0x4A6340B5, 0xD4AF5520, 0x212E8823, 0xC589D667, 0x808D9AF2, 0x773B1F81, 0x5AFDB55A, 0x314ECF15},
	{0x0A8431BF, 0xDE600885, 0xD36CACF8, 0x9969D463, 0xAD449794, 0xF8141602, 0x95C8DC27, 0x76894A27} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1227 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1228 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1229 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1230 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1231 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF93DC550, 0x67D59869, 0xC746FC16, 0xE038E73A, 0x87E67C6A, 0xB45C6A03, 0x18AA9C7E, 0x4DBB0496},
	{0x52DA2F78, 0x19A6ED08, 0x13D2678D, 0xC0CC902E, 0x3D7E36CE, 0x21E042F0, 0x435C12CD, 0x6B0A7AF2} } ,
	 { {0x8DC9FDE4, 0x6A24F60B, 0x57EC2DCF, 0xC7B70B11, 0xE8586D3D, 0x0916DA12, 0x75E0CBAC, 0x89FDDB86},
	{0x2715C5C6, 0x5EF7C7B5, 0xCD96579B, 0x8886309F, 0x7596CC64, 0x9FC1CC49, 0x8668A46E, 0x5C383F6A} } ,
	0};
		static bigint_t var_k = {0x9E15F614, 0xAAE97E7A, 0xA5145F03, 0x46597576, 0x89826A16, 0x336BA582, 0xB07B08AE, 0xAADDC5A8};
		static ecpoint_fp2 var_expected = { { {0xB6712BE5, 0xAFC096A8, 0x768D4919, 0x128AA6F8, 0xD4E09B53, 0x0FDFF369, 0xC3D5924D, 0x5555FE01},
	{0x91227558, 0x3706BC1B, 0x57AA3A1C, 0x30183F50, 0xF3F9F939, 0xEDC9272E, 0x2B79990B, 0x9AC6AF14} } ,
	 { {0x5F4A2836, 0x1097F5B8, 0xD661F423, 0x15A4897F, 0x8849356C, 0xC7312CDF, 0x37F1F530, 0x01F5AD68},
	{0xAB221277, 0x0DDFC7F9, 0x7DC3A10A, 0x8C6F7F65, 0x29D03E0C, 0x5C4696FB, 0xE697B991, 0x2BB80403} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1232 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1233 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1234 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1235 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1236 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD6DE556B, 0x534669E9, 0x5AE18C7F, 0x5E8DFCF3, 0x3AFC3921, 0x64E7CE7C, 0x6CF4ED11, 0x75F9501C},
	{0x64D167F8, 0x9C6FE8A1, 0xE9954A09, 0xA8EBB980, 0x703ADEA6, 0xE3F23A2B, 0x680CA7BD, 0xB9EEF78F} } ,
	 { {0xC6A08103, 0x4F2F8ECA, 0xCE6044A9, 0xFCF8668B, 0xEA6E1955, 0x5A71C760, 0xFDE55EE4, 0xB9C30C13},
	{0x7797B8EE, 0x4EDBFA38, 0x5BDA1B32, 0x6B150AD3, 0x4A7B66E5, 0xFAFDD66C, 0x0BCE6BB9, 0xA349A1A9} } ,
	0};
		static bigint_t var_k = {0x4CD79D42, 0x6DB0B102, 0x3BA2CB93, 0xFFDF356B, 0x4E521FB1, 0x2457A528, 0x97BF5943, 0x8340E966};
		static ecpoint_fp2 var_expected = { { {0x964BF7EA, 0x6EE97214, 0xE9EF4C02, 0xA3C9C565, 0x77ECE287, 0xEBE6B0CD, 0x29D152D2, 0x47F31734},
	{0xFB15C3C7, 0xC9B0D2AC, 0xBEF30857, 0x822AD8BF, 0x70B049C4, 0x54F5F045, 0xFCA9FBD7, 0x8FC0C3C9} } ,
	 { {0x8750ED8E, 0xBE4BE16F, 0x419F0B57, 0x8E7BA61D, 0x35D64F24, 0x78A4C945, 0x68C40C8F, 0x5967C206},
	{0x2F66FBA5, 0xD8D63571, 0x5EE9AEDA, 0xC17E4037, 0x85BEE5DA, 0xCEF7946D, 0x7DDCC004, 0x48E89868} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1237 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1238 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1239 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1240 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1241 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFC87AD2E, 0xB716402B, 0xFB52F004, 0x16039EF4, 0xA88CF11C, 0xE1ECE739, 0x19D4E5EB, 0x21A55333},
	{0x78BBFED2, 0xF008F8B5, 0xE81B58BB, 0x4C04F302, 0xA951705A, 0x1C9F7D02, 0x92914CC6, 0x0E38201C} } ,
	 { {0x28BA6D93, 0x4A08E561, 0x1F20C391, 0x1B1A2A30, 0xD808D5BD, 0xAFC7729F, 0x072E0FE9, 0x3133CA4D},
	{0x191C71AD, 0xFACCD9CA, 0x48CB6534, 0x5E2C6633, 0x04ED434F, 0xC9561FCB, 0x3A0C9255, 0x6D546C8C} } ,
	0};
		static bigint_t var_k = {0x0A617F0C, 0xE586061A, 0xAF38D659, 0x47EF5576, 0xD41A2A86, 0xC5E6EB46, 0xEE5D9496, 0x107FCF71};
		static ecpoint_fp2 var_expected = { { {0xD5385062, 0xEE1CED7F, 0x0DA71F66, 0x0FB62232, 0xFF504E3A, 0x92A653EA, 0x11319F74, 0x429CE832},
	{0x8BA73B1D, 0xE8C55666, 0xD8C0FD5D, 0x85116DC4, 0x502E1D95, 0xAD40DDF4, 0x559A2379, 0xAEB7E09F} } ,
	 { {0xE0B570A2, 0xCCB1E370, 0xAE10623B, 0xBC45781A, 0xD378A720, 0x0AE29DA2, 0x598F1DA7, 0x04A727E3},
	{0x467A0864, 0xFEFF2662, 0xA7761A3A, 0xA53D74F2, 0xFB17E2F2, 0xE711BDFB, 0x3A8A64B6, 0x1FA4230E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1242 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1243 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1244 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1245 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1246 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFD2A18EC, 0xE45BF999, 0x9A94A3F4, 0xF1C2C6EC, 0xDA700FB6, 0x75A71932, 0xFD231DCA, 0x71D5454A},
	{0x38B36378, 0x966E6FBB, 0x7591154E, 0x9A1133D2, 0xD1DE47CF, 0x8C99B282, 0x1716DFFE, 0x9E4FF0E7} } ,
	 { {0xC9F62340, 0x071971C9, 0xB85122D1, 0x801B62FE, 0x02697E86, 0x0DFB9AE0, 0x40876FBC, 0xB36AAFE5},
	{0x3653824D, 0xF3D85DD8, 0x6375899B, 0xCB190F46, 0x7FF4CC2C, 0x04BC2E7B, 0xA536D587, 0x0B79D577} } ,
	0};
		static bigint_t var_k = {0x9C651D4F, 0xCA93893C, 0xFDD9DCA4, 0xEE16B164, 0x8F1C9209, 0x4137E5E1, 0xE3E20C1F, 0x123EEA4A};
		static ecpoint_fp2 var_expected = { { {0x6786E3F2, 0x9735DD86, 0x4CF74F41, 0x9E98B8D3, 0xBD9E1DFA, 0x3A0C8310, 0x4E576876, 0x941B65C1},
	{0x96E4A77C, 0x1434B9C9, 0x22037425, 0x1A503264, 0xBAF02AA5, 0xAE5617B9, 0x8EF738AF, 0x9F5D93D8} } ,
	 { {0x64AC772F, 0xB1A58D93, 0xCEEE785B, 0x1C40B2B8, 0xD4502D39, 0xAEF4AFBE, 0x953ED48D, 0x80F1F1A8},
	{0xD07CB499, 0xB19BB543, 0xE0E1AE8D, 0xC7FA8F5C, 0xC2816864, 0x351541B3, 0xC8793DC6, 0x4743591C} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1247 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1248 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1249 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1250 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1251 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD14BB9DA, 0x8FECBA0A, 0x33CE9433, 0x7BBA1C57, 0x938AF202, 0xECB03550, 0xC0CFFA90, 0x508B3BC9},
	{0xD39ED78C, 0xAA96986D, 0x3DDE8EBB, 0x45A622D3, 0xDF448118, 0x23015DC5, 0x81F12AB5, 0x34BE80BA} } ,
	 { {0xE6B2C640, 0x29435D81, 0xD01BA4B8, 0x89E81FC2, 0x15E9876E, 0x035ADC4A, 0x433CD3CC, 0x3A8C98EC},
	{0xEC54398D, 0x4CDE4931, 0x2A4C3663, 0x249C220F, 0x42E3C8CF, 0x87C545E7, 0xB37E9AD6, 0xA212203B} } ,
	0};
		static bigint_t var_k = {0x07D350EE, 0x161E72ED, 0x6301661E, 0x047DDA7B, 0x349FB3D4, 0xFE01D387, 0xE13FB736, 0x8AD4D1BA};
		static ecpoint_fp2 var_expected = { { {0x7488DD4E, 0xAE73E28B, 0xDAFEBEA8, 0x07F32C36, 0x0844DDC7, 0xE5A2A1B0, 0x92A1F6ED, 0x19EBEEC6},
	{0x837CF0BB, 0x812FF285, 0x08C95E52, 0x8D76DB23, 0xAB48E453, 0x9176566A, 0xF81E4391, 0x046C59C1} } ,
	 { {0x00CC60A0, 0xE603A62D, 0x7283DA41, 0xF5750A73, 0xA829FF4E, 0x7AA08A71, 0xE3D61638, 0x915096BC},
	{0xB04D0D6F, 0x7293BF31, 0xB1ABAFF4, 0xA5072150, 0x8004FCC4, 0x452A4DE9, 0x22D87E2C, 0x11825175} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1252 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1253 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1254 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1255 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1256 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFF42F4A4, 0x76D863BE, 0x6BFCACDD, 0x67E7A8DD, 0x80AD2EE8, 0x0504F624, 0x7DC2AD8D, 0x40226E10},
	{0xDE731D6F, 0xF640EF24, 0xB0A9E2C9, 0x88B72F36, 0xF70CB9B4, 0x7E3AA154, 0xDC551015, 0x89E305F4} } ,
	 { {0x3D322862, 0x06A57BCD, 0x8625F8CE, 0x3B0B3199, 0x9E226BEA, 0x923441CA, 0xFB21BC45, 0x4A8DAB77},
	{0xE29F09C5, 0x03F744D1, 0x895BF7ED, 0x7F1E20B1, 0x234EF0E7, 0x0FA5227A, 0x55E37BD7, 0x1438E52B} } ,
	0};
		static bigint_t var_k = {0x91224E30, 0x021D2B75, 0x5C733196, 0xDCED2E2C, 0xB84190EE, 0xA72C6C3E, 0x979BCAE1, 0xB85B56AD};
		static ecpoint_fp2 var_expected = { { {0xA0E4420C, 0x5539A60D, 0xCFBD0E05, 0x4CBF2BBA, 0x924E700C, 0x43A71465, 0xC48FD948, 0x30B2A19F},
	{0xFAF6AC44, 0x43F04488, 0xC577D731, 0x490A0192, 0xBB29EF3E, 0x35A3A6CB, 0xC9A61075, 0xAA8FFF1C} } ,
	 { {0xD4FD24D6, 0xDEC25E93, 0x8D0907AC, 0x07E386EF, 0xFCE3AC23, 0x35A7FE2F, 0xACCCBABA, 0x2B577FBC},
	{0x8A10F7F4, 0xBC8AC5FC, 0x06056F10, 0x89A43B12, 0x4B09FDD9, 0xF893FAB5, 0x7B873BBF, 0x0089B87E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1257 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1258 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1259 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1260 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1261 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4CD0E65A, 0x756CEB23, 0x02DE455B, 0x27EC6357, 0xEB434CA9, 0x0778C4C9, 0x5707F1B2, 0x4DC2F2B7},
	{0x7F1807B3, 0xC41A65AD, 0x4DF476C8, 0xD9734D2E, 0x4A6E5CC4, 0xE24CFF41, 0xAED19B58, 0xB3D31EF0} } ,
	 { {0xC1544938, 0x026FA3D4, 0x9EA649AD, 0xC873BF38, 0x3533B629, 0x2AA08536, 0xC919DB40, 0x0A430EC1},
	{0x1613422C, 0x91BCC9D2, 0x77AAB60A, 0xCAFCFBBC, 0xE45A4438, 0xC7819F3D, 0xAC48E44D, 0x72AF84BE} } ,
	0};
		static bigint_t var_k = {0xBFA89E24, 0x07C89F72, 0xA70D1D34, 0x07EC8AAB, 0x514AD308, 0x25598057, 0xF021F906, 0x1FBFF473};
		static ecpoint_fp2 var_expected = { { {0x60B515DE, 0x460CE4B3, 0x386B90CA, 0x51763653, 0xD0CC5FB5, 0x2EAC69AD, 0x21E88ED7, 0x02B823F6},
	{0xF666D67B, 0x05B3963C, 0x15433735, 0x9E0782EC, 0xCA916CAF, 0x76D00532, 0x514E6384, 0x38D0514A} } ,
	 { {0x38682C11, 0x025601DC, 0x3F3B3ABF, 0xE44FB776, 0x3CD3E716, 0x26CCB20B, 0x386B4BDF, 0x00C66BF0},
	{0xC8092BB9, 0xEE5AFE50, 0x3F1B5967, 0x74FEE16A, 0x173ABAF9, 0xD8C238F4, 0x7975957A, 0x0FF8D6C1} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1262 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1263 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1264 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1265 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1266 infinity");
	}
	{
		static const bigint_t var_t = {0xA901D8BA, 0x31EB0BA1, 0x32297255, 0xB07B9BF4, 0x97DCA53F, 0x2DA6D54D, 0x80250831, 0xAC178B4F};
		static ecpoint_fp2 var_expected = { { {0x05A23C55, 0x05E5C816, 0xDBCB1433, 0x055C54B6, 0x7EBF75F0, 0xD9319AEE, 0xC559844A, 0x59E97011},
	{0x9DC4A938, 0xE8C9BFEE, 0x2A3CDBAC, 0x14A6AEE2, 0x48483DA3, 0x505000C8, 0x8CEAAAEF, 0xADEF251E} } ,
	 { {0x88DFFE30, 0x5D535DA9, 0xF4D06436, 0x31F07699, 0xDB08B757, 0x77C00D80, 0xA9477140, 0x5A37DC6D},
	{0xBDFBC5F0, 0x2C095C4C, 0x02AD2054, 0xF11572F7, 0x650B1C8E, 0xA5B559D7, 0xBE6D922E, 0x0F3F761E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1267 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1268 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1269 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1270 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1271 infinity");
	}
	{
		static const bigint_t var_t = {0x29C91FA4, 0x4A9CFFAF, 0xA97F640F, 0x576CC835, 0xC442D15B, 0xC60CFECF, 0xC4E9D58E, 0x7A8435A1};
		static ecpoint_fp2 var_expected = { { {0x7BD6B5B9, 0x95783B60, 0x38F4E91C, 0x951686FC, 0xD19E939A, 0x7E83A971, 0x56D2EFE1, 0x1B116C0B},
	{0x9FEE5522, 0xF43C406A, 0xBFD1B55E, 0x977563CF, 0x8B054D78, 0x691B92E9, 0xBC1DC6BD, 0x3F211201} } ,
	 { {0x422420C0, 0x7AD5716A, 0xBDA73E00, 0x207D1B23, 0xCB1F317B, 0x64A3CB68, 0x88EEE829, 0x617A487E},
	{0x10ADE4F8, 0xFF0DBFC5, 0x062B3F72, 0xA39A1415, 0x3305A905, 0x20D5B4AE, 0xC11BE69E, 0xA538F31E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1272 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1273 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1274 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1275 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1276 infinity");
	}
	{
		static const bigint_t var_t = {0x7DAD7EA9, 0x8C3BD9C0, 0x0ED29ABB, 0xEDBB44E5, 0xE93C6595, 0xAE7DF88E, 0x18070976, 0x08D9B6C6};
		static ecpoint_fp2 var_expected = { { {0x1B3A23D0, 0x8E60F0D2, 0xBC168F76, 0x40E8F7A2, 0xACEBA293, 0x5F126916, 0xE39199C0, 0x1047860A},
	{0x0D510846, 0x15564009, 0x06B55EEA, 0xC5C69ED8, 0x99612269, 0x2876ACA3, 0x984F1C7B, 0x9F4B0817} } ,
	 { {0x7E972B5A, 0x37836A08, 0x713D0144, 0x1F4B9A51, 0xEB41DD74, 0xA87D1F3B, 0xE3069C7B, 0x23E207B1},
	{0x57D20243, 0xE63970B4, 0x494B81F8, 0x3AB7D101, 0xD74BBFCD, 0x7851F0C5, 0xEAC02D5C, 0x812ACDFD} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1277 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1278 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1279 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1280 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1281 infinity");
	}
	{
		static const bigint_t var_t = {0x1A5822AC, 0x862D0440, 0x74ECDC62, 0x14E701BA, 0x268023A4, 0x66FB4A87, 0x9A8BA87F, 0x1D767321};
		static ecpoint_fp2 var_expected = { { {0x7511ED9E, 0x03D78C5C, 0xD5F0A0D6, 0x8D5430E9, 0xF1825DBB, 0x53485D23, 0xAA4FBE03, 0x7E41E222},
	{0x81503F21, 0xE41E8CCE, 0xDDACFCCB, 0x0B20CA37, 0x1D4FC20E, 0x9741F5B9, 0xCEDC9D06, 0x6165C123} } ,
	 { {0xC8704D8A, 0xD6056736, 0x0B05E162, 0x6CC444F6, 0xD46A57EC, 0xA8D3434F, 0x0D469DE4, 0x85345F7D},
	{0x1D40E0EE, 0xEEF24ED3, 0x0C04DFCA, 0xCC3EB1E5, 0xD6A199CC, 0xCD3926C4, 0x9840CE2A, 0x0B8E774E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1282 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1283 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1284 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1285 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1286 infinity");
	}
	{
		static const bigint_t var_t = {0x3956A982, 0x97565AEE, 0x7B4F2012, 0x6020A342, 0x09737EDE, 0xF9C6059D, 0xB0509400, 0x9FD6DE88};
		static ecpoint_fp2 var_expected = { { {0x8D04B64A, 0x96CB9255, 0x6E8EFA0A, 0xCF26D412, 0x628D1EE2, 0xDE7C7DEC, 0x0D3AA5FF, 0x69D19B0B},
	{0x39115E1F, 0x9FD6ADFD, 0x93E8B4BF, 0xDF5772CE, 0x71FCCF49, 0x8BDB4EA9, 0xD0864D4F, 0x0FB7F693} } ,
	 { {0xDA2782EC, 0x49FCF9B2, 0xB31916CF, 0x9DE1A730, 0xCED1849C, 0x3D3F6C50, 0xA01FDDCB, 0x5AADEBC0},
	{0x03CE9D39, 0x71924DF1, 0x06BD8D81, 0x6EFE8E47, 0x419518F9, 0x98AA4994, 0x8058575F, 0x7011D80F} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1287 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1288 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1289 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1290 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1291 infinity");
	}
	{
		static const bigint_t var_t = {0xA12AFB56, 0x43AE944F, 0x49F28073, 0xD82E477B, 0xBB9E6F10, 0xB7C6AAD4, 0x3417DE44, 0x0CC9226A};
		static ecpoint_fp2 var_expected = { { {0xC7CE0E5B, 0x845712A3, 0x07D50C66, 0xAB8A720A, 0xDF14EA6B, 0x8E8AC8E6, 0x6DCC76B5, 0x7016AB44},
	{0x5C5397E1, 0xF89794B2, 0x007BE491, 0x7FC04345, 0xBDCE0679, 0xBA11A30F, 0x44F100EC, 0x9DACE42C} } ,
	 { {0xB8C98F18, 0x26FD653E, 0x85BDAB2B, 0xC6AAD606, 0x7856C431, 0x8EE9D3DC, 0xE696E83A, 0x8AB906E9},
	{0xC788C72A, 0x7FDA02CE, 0xE0F03DA3, 0x8F596CE6, 0x6E60FB13, 0x1C91EF41, 0x8DD7A377, 0x4F761DEC} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1292 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1293 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1294 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1295 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1296 infinity");
	}
	{
		static const bigint_t var_t = {0xED8E6938, 0xB0DD6A39, 0x4C43B762, 0x65DAD48B, 0x69FA3492, 0x2744FE1A, 0x3C7B4570, 0x8FDD9FFA};
		static ecpoint_fp2 var_expected = { { {0x4CE667E0, 0x2420B911, 0x442D091A, 0x552187F8, 0x3579F2BF, 0x63C1CBB7, 0x58191994, 0x42A3FE16},
	{0x77E1254A, 0x64345814, 0x547F4326, 0xD0114C37, 0xD2A595C1, 0x7C25A39C, 0xAD7D5229, 0x9AA3B414} } ,
	 { {0x77F3DEA0, 0xF7FEBEB7, 0xE52B9F40, 0x79201489, 0xC6441EB8, 0x5BA941A6, 0x83E0C1A2, 0x1241E122},
	{0x4D6B801B, 0x36D49406, 0xFD035E07, 0x39F33B75, 0x335E5882, 0x6E41B489, 0xE601871A, 0x30CC0DC1} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1297 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1298 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1299 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1300 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1301 infinity");
	}
	{
		static const bigint_t var_t = {0x3F8199B9, 0xC2C560B3, 0x379F0269, 0xF7E9DFDD, 0x1E464B77, 0x706AE7DF, 0x4890943D, 0x3FFCBF1A};
		static ecpoint_fp2 var_expected = { { {0x3CBE85A0, 0xD2461941, 0x0B7946BB, 0x2D5CDE8C, 0x5FD99D8D, 0xBAC2D19F, 0x87A3CC0E, 0x6750D4EC},
	{0xC0B168F0, 0x12FE4248, 0x7BA7BA54, 0xDB00C714, 0x70E56F10, 0xC0D772C2, 0x20B18AF4, 0x5FD4877B} } ,
	 { {0xE60FF58B, 0x0A2B243B, 0x2DEB532D, 0x7983315A, 0xDF996CDE, 0xB500A06B, 0xFE4B0E63, 0x0F93884F},
	{0x15EB7806, 0xCDF923F6, 0xC3911568, 0x54898417, 0x05B53D1D, 0xBA28E428, 0xFCB4D0FE, 0xA2245FAB} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1302 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1303 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1304 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1305 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1306 infinity");
	}
	{
		static const bigint_t var_t = {0x155F4830, 0xC2DF1B95, 0x6F023388, 0x7B14131F, 0x77FEC798, 0x085D4B36, 0xA4D309CF, 0x09E1C47E};
		static ecpoint_fp2 var_expected = { { {0x5E56891F, 0x72D01196, 0x68090D2B, 0x1CE9C22F, 0x28F7FB09, 0x583B269B, 0xB00639E2, 0xABEB1178},
	{0x034ABA3A, 0xB1E62945, 0x99CDB2EE, 0x634B5B9C, 0x0E08DD0B, 0xA9320310, 0x6B1308AA, 0x64744697} } ,
	 { {0x9A112A27, 0x6DD2DF8C, 0x44BA27FB, 0xCBE961D0, 0x0F5B3111, 0xD8F9CCCE, 0x63836573, 0x5EE1E661},
	{0x6D9B6F06, 0xB2EF2F59, 0x28D9620B, 0x8C721BB5, 0xFAA34984, 0xF152932A, 0xC05A006D, 0x97C2081D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1307 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1308 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1309 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1310 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1311 infinity");
	}
	{
		static const bigint_t var_t = {0x39CD7D63, 0x93BCD52A, 0xD31E85B1, 0x1CDB2461, 0x77670ECC, 0x67199016, 0xC66B545A, 0x66461FC1};
		static ecpoint_fp2 var_expected = { { {0xBF0381A2, 0xFC8E4491, 0x77D55FEA, 0x6912BC8F, 0xB7FCB567, 0xF13DAECD, 0xCD54ED1F, 0x31CFE6AC},
	{0xBE1B3481, 0x75E1B296, 0xA7A26BD1, 0x30346EF0, 0xA6231C50, 0xFA3A415C, 0x8C7494A1, 0xA52CD001} } ,
	 { {0xC6800420, 0xF27D5B53, 0xAF3BA0CA, 0x3BDD4155, 0xA104A88D, 0xC046B1DC, 0x2177B8B7, 0x32544297},
	{0xC0D93397, 0xEF90DB7B, 0x73F5EADE, 0x8F7891C8, 0xCDF8276F, 0x569A201D, 0xC13776CE, 0x1BAFEA66} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1312 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1313 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1314 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1315 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1316 infinity");
	}
	{
		static const bigint_t var_t = {0xD9A2FC72, 0x5EC76263, 0x34E226D2, 0x3145B872, 0x34ED2D16, 0x9AC9A1F9, 0x570B095B, 0x32427ED7};
		static ecpoint_fp2 var_expected = { { {0xA99A777D, 0x32BAA021, 0xF0FEB257, 0xECE53D67, 0x721EF8DA, 0x290E0AF2, 0x25BB75F4, 0x55003EAB},
	{0xCFF6B711, 0xF1B41517, 0x2C1A8224, 0x7AD811F7, 0x1BBA02AC, 0xBD87B9CC, 0xD38F631F, 0x2060FF0B} } ,
	 { {0xBDFD28F9, 0xA3B8E421, 0xF2DA4DB2, 0xEA23B59F, 0x42D2BA11, 0xFE9C88C8, 0x40619697, 0x33230658},
	{0x60680B0C, 0xA54CF741, 0x536FBE59, 0x63EA835D, 0x6EBEA692, 0x65375D18, 0x4A47F2DC, 0x66FA35A1} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1317 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1318 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1319 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1320 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1321 infinity");
	}
	{
		static const bigint_t var_t = {0xC96B649F, 0xBC24FADD, 0x5601CA62, 0x1FFDBCCA, 0x96C22819, 0xA006BD86, 0x61475D83, 0x4DAD5D5B};
		static ecpoint_fp2 var_expected = { { {0x45AA11F0, 0x0D9ED3A7, 0x42EE6ABA, 0x870439E7, 0xFBAEADA2, 0x275CFAC6, 0x7FB943D6, 0x6230855A},
	{0x170E86E5, 0xB601EB5F, 0xF8DA2E38, 0xE4936610, 0xECA578C3, 0xF91E4851, 0xF61DDD9D, 0x438D4716} } ,
	 { {0x4CE22027, 0x63FB930B, 0x4D1DC51D, 0x1B6ECF13, 0xFD6CA617, 0xBC1F5583, 0xBA2255FB, 0x5D2C37E7},
	{0x431E6D78, 0x7C296CFE, 0xBE5944A6, 0x42DF60D5, 0x36B46746, 0x3530DE13, 0xB45982DB, 0x283B8D99} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1322 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1323 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1324 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1325 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1326 infinity");
	}
	{
		static const bigint_t var_t = {0x70062473, 0x0E831128, 0x6146538E, 0x881837D8, 0x3283FCA1, 0x0F4F2C49, 0xB8F26B91, 0x402DAD17};
		static ecpoint_fp2 var_expected = { { {0x01BE6A89, 0xAF1B4304, 0xA12D1BDB, 0x38351FE5, 0xD0807463, 0x1B478CF4, 0xAD86F2AB, 0x74EAA30E},
	{0xBF8105E8, 0x79AC7F07, 0x9F53DA63, 0xB87C4C15, 0x4EDE3B65, 0x666087DB, 0xF4F6E267, 0x48C0AA48} } ,
	 { {0xC2756B07, 0xFBFA3EAA, 0x1A74348E, 0xC68DABDE, 0x95D14D6E, 0xBBA5B34D, 0xA94472B0, 0x53F51D35},
	{0x7038602E, 0xF10CAD1C, 0x58496035, 0x2FE74CB5, 0x25972DCB, 0x306E963D, 0x05179666, 0x53F2943A} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1327 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1328 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1329 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1330 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1331 infinity");
	}
	{
		static const bigint_t var_t = {0xD16992BF, 0x659196CD, 0xC009CAC8, 0xD0041E73, 0x31F4C735, 0x4FE33595, 0x65745272, 0x33FCECF0};
		static ecpoint_fp2 var_expected = { { {0x8CBBD5EB, 0xA5EA9B09, 0x07540D47, 0xAE230A7A, 0x1F04D2F0, 0x9E611239, 0x466655B3, 0x9FF203C3},
	{0x153E1CDF, 0xAEF80C63, 0xF3900733, 0x304A4281, 0x427E8893, 0x831E27D0, 0x4BB66435, 0x230EC058} } ,
	 { {0x217F9128, 0x3D263359, 0xA78815C8, 0x1B9ABFD1, 0x9457DB19, 0xC96F6B2A, 0x301C117B, 0x73EC8C9F},
	{0xC56E78CB, 0xC75612C4, 0xED554CB3, 0x9F8C7D24, 0x4B4B051A, 0x795834A6, 0x4651F063, 0x2A1E9E6E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1332 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1333 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1334 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1335 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1336 infinity");
	}
	{
		static const bigint_t var_t = {0xDF2DE9BD, 0x7AB345E3, 0xC4DDCF4D, 0x938B145B, 0x0BA06C85, 0xBE84594E, 0xBFBCDE30, 0x659D6BFC};
		static ecpoint_fp2 var_expected = { { {0xE037D871, 0x47D17EDA, 0xCB07C149, 0x71C35F7A, 0xFF8CDCAF, 0x04E50CF4, 0xF016AF86, 0x66683BC2},
	{0x2115FBC0, 0xC4A8FB5A, 0x97607D35, 0x25C3D07E, 0x5F35D077, 0x3334EA42, 0x0846F0FB, 0x63B0EAF9} } ,
	 { {0x56570218, 0xD1BC7458, 0x00E08D68, 0xAD27B97F, 0xCDF0D7C9, 0x698121DC, 0x91E5AEF7, 0x0B021D88},
	{0x6AA09F4B, 0xB03912FC, 0xB6243EBC, 0x4D51D1FC, 0x67721181, 0x4ACFD066, 0xBDEA6E48, 0x502D3FAD} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1337 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1338 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1339 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1340 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1341 infinity");
	}
	{
		static const bigint_t var_t = {0x783C06DC, 0x50E79632, 0xCAE6728E, 0x86B292FC, 0x6016C5F1, 0x78FFCA2B, 0x606FB1F5, 0x61648F8B};
		static ecpoint_fp2 var_expected = { { {0x3E730038, 0x58D1A45E, 0x03C3BCA8, 0x6E8C77B6, 0x65B106D8, 0xCB696038, 0x95CFC336, 0x4A71E63F},
	{0x4C23C7DE, 0x9E8D5BD1, 0x5903B715, 0x14599537, 0x83E5B93D, 0x620D3553, 0xAD82ED82, 0x6E209D21} } ,
	 { {0xCE7BD329, 0xC4555479, 0x76085A5D, 0x24910267, 0xF24C46CB, 0xB9DC0A36, 0x0939B951, 0x1C22C73B},
	{0x620D00CB, 0x47EE19EE, 0x4EEC29FF, 0xD91EF767, 0x56A1D5F1, 0x2AFA7119, 0x06DB7095, 0x0D944F21} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1342 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1343 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1344 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1345 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1346 infinity");
	}
	{
		static const bigint_t var_t = {0xACA4CC1E, 0x1B635609, 0xE36A4D2E, 0x3EDC80BA, 0x9952779F, 0xC11E07F4, 0xF06D50A5, 0x5A98E04F};
		static ecpoint_fp2 var_expected = { { {0x658F1D4C, 0xA5266CB2, 0xEEB5C587, 0x7C621640, 0xFF16D3BF, 0xBF8B89F1, 0x59A16A19, 0x76A1011A},
	{0xA6E44E2D, 0x18692DD9, 0x17FADEAB, 0x70F3EA34, 0xD9414730, 0xABA95C3C, 0xC1F14C50, 0x96A2CA9F} } ,
	 { {0x386010EB, 0x03568B5F, 0xFD7BB68D, 0x9C1E03A5, 0xE178E193, 0x7F96BB86, 0x2F4F8E46, 0x389E0270},
	{0x1156EEC2, 0x036EF25E, 0xA2053683, 0x6EA9F383, 0xDB49A5B6, 0xA4D9B461, 0x58EEFACA, 0x5B50C64C} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1347 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1348 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1349 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1350 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1351 infinity");
	}

#else

	{
		static ecpoint_fp2 var_a = { { {0xF7BA218A, 0xC5D0D381, 0x2D9569A7, 0xA563FE7F, 0xB1A6FFA0, 0xA98DB77C, 0xCF5986EC, 0x0E2A5239},
	{0x84704F45, 0x77D7CEDA, 0xA189CE63, 0x5D4B7BBB, 0x19154ED5, 0x801F3214, 0x6C28AC6E, 0x3EEF964E} } ,
	 { {0xD4B5C16A, 0x9FD1CDC7, 0x6F316B79, 0xBB982C82, 0x0D55509A, 0xA3C25AF5, 0xFB14E0A4, 0x03E6B50B},
	{0xAB2A99BE, 0x5BE3BF8E, 0x9B290B93, 0xFE60CCF4, 0x3723283E, 0xA570544F, 0x8204DC43, 0x2FBD4B0C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4792 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4793 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4794 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4795 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4796 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4797 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4798 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4799 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4800 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4801 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC7ABB55C, 0x4D29BF70, 0xED3CF62B, 0x6C6D710B, 0xDCE760CB, 0x4E1D7FEA, 0x57297C40, 0xAE80CAB7},
	{0x7207D00D, 0x1A5ACEE4, 0x43C5AEFC, 0x773994B0, 0xB9B5B565, 0x3C5B3528, 0x6623D39E, 0x630CCDDC} } ,
	 { {0x50652695, 0xEBBC70CA, 0x0A6FFB78, 0xAE42C61C, 0x79D2A8CA, 0x4130BEFE, 0x2ED795BA, 0x01DF6E6B},
	{0x59CB8F87, 0xEDD95D35, 0x6FAD880D, 0xF23CAB89, 0xE937432C, 0xF83951A8, 0x4556CACA, 0xA7BC52F6} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4802 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4803 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4804 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4805 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4806 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4807 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4808 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4809 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4810 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4811 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB64B7DAB, 0xD2E53763, 0xB5CF12D4, 0x062C5A45, 0xCB50C6C2, 0x3FC24851, 0x10B5D9E6, 0x17437D8A},
	{0x47D753E9, 0x4D4E1BA5, 0xB1EFF549, 0x13FC5907, 0x52A32581, 0xBB834907, 0x4C1156A6, 0x37FA7012} } ,
	 { {0x1EE03DFD, 0x9956E371, 0x4D305D36, 0x24AA6852, 0xA74B1B0E, 0x537EEE26, 0x88E80A28, 0x92F48B6D},
	{0xA0A069F8, 0xF4D52BCA, 0x30D4CBEF, 0x98EB217A, 0x1463D817, 0xB67B0E03, 0x689F74F8, 0x1BEBA98A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4812 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4813 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4814 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4815 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4816 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4817 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4818 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4819 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4820 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4821 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xED3692B4, 0x1B9AA7CB, 0x6D73F6E0, 0xFACB4287, 0x248BD9C3, 0xC5E3D377, 0x6414E5FB, 0x52654694},
	{0x8E0521C6, 0xD8E78CB2, 0xA97BB1CD, 0xCBDA99A4, 0xE0F6AEEC, 0x41010542, 0xC6ADABD5, 0x803A34C9} } ,
	 { {0xC84716F8, 0x71A34546, 0xF35CDC22, 0xB93ECFC2, 0x9506B9B4, 0x1DD64F9B, 0xB028366B, 0x78410CBA},
	{0x31EB9D9F, 0x34971955, 0x1801566C, 0xC5581D1A, 0xAF61AC96, 0x14606AB5, 0x54E3E892, 0x7A59357C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4822 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4823 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4824 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4825 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4826 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4827 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4828 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4829 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4830 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4831 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x943D17E4, 0xF25DF530, 0xFB6129A6, 0xD15D2E45, 0x8F34E241, 0x262D4DE6, 0xBA320CF4, 0x667F7490},
	{0x703FC521, 0x816F9AA0, 0x11F8EF5E, 0x286FA53F, 0x0A5BC020, 0x15A0F39D, 0x3DE93C12, 0x445ECDE7} } ,
	 { {0x149A11F7, 0x3A4E8A6C, 0x1000C47A, 0xE130D5C6, 0x9577824E, 0xECE3D47A, 0xCE0F1B71, 0x025C159D},
	{0x0E70001E, 0x785E0419, 0x91E57827, 0xC75C2145, 0x672EB350, 0x6A35074E, 0xB09E3520, 0x9EAC343F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4832 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4833 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4834 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4835 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4836 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4837 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4838 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4839 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4840 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4841 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD363E2B4, 0x1ECD976F, 0x49E99E8B, 0x13D6DACF, 0xB6DECF70, 0xAB8D401A, 0x7ACF5E10, 0x5CCDEA14},
	{0x12E63330, 0x11323741, 0xD387F9DB, 0xB2B6810B, 0x7AEEFAFF, 0x7EF02481, 0x1808FBC8, 0x8B1AF887} } ,
	 { {0x50BA4E8A, 0xBA414474, 0x081C35AB, 0x5EDD4507, 0x4C942C08, 0xFA1B9669, 0x0B5FEC16, 0x66CD4E6A},
	{0xC155742C, 0x872876C8, 0x56A6CA39, 0x3A78BA7C, 0x38C5BBAB, 0xFA8DF5A1, 0x241F2354, 0x4B00FA9C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4842 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4843 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4844 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4845 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4846 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4847 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4848 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4849 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4850 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4851 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD1E1262E, 0x6707A7EB, 0x3E6BCF24, 0x470D0360, 0x3F0F449C, 0x9D388B9B, 0x0D7E0898, 0x3B2F434D},
	{0x9F0EB0A4, 0x51802447, 0xD7E1A94A, 0xF0126928, 0xD6437C45, 0xC6465EF3, 0xC0A2191D, 0x5E48D733} } ,
	 { {0x7DB5BF8C, 0xBD52D54C, 0x48F2059F, 0x7F18DC9F, 0x65F247CB, 0x9CF0B19E, 0x0DFC6C13, 0x7D4C4DA0},
	{0x724B4C6B, 0x2908C6E3, 0x5184A2B8, 0xA57E1E96, 0xCAB28DD9, 0x0B609865, 0x19E71B95, 0x877FB045} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4852 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4853 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4854 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4855 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4856 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4857 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4858 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4859 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4860 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4861 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB8231F7E, 0x95B0EE33, 0xC35DD2DC, 0xF6BFA0EA, 0xD33F9CCB, 0x42A54D72, 0xDAA5CA56, 0x0C29F0EE},
	{0xDC56819C, 0x08C0B9C7, 0x2ED9EAE6, 0x5737A15D, 0x737E9F2B, 0x395AEFB5, 0x5C86ECD2, 0x0BD0B7BA} } ,
	 { {0x267E67CD, 0x099663B6, 0x8BBB166A, 0xDEE2C6C4, 0xDEA82D06, 0x179C50E2, 0x7E1583AA, 0x0A836BCD},
	{0x48B4E9D1, 0x26147417, 0x6954D25C, 0x91A7DB5A, 0xC4F73B4E, 0xE765B30A, 0xF6CC439B, 0x5A79DD84} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4862 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4863 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4864 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4865 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4866 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4867 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4868 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4869 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4870 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4871 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4C9D8196, 0x720275E4, 0xEAD29970, 0x947C819D, 0xC6FC717D, 0xE92E8111, 0x09639AB7, 0x1DCEC024},
	{0xB492B2CE, 0xFE285F44, 0x6D3C8C48, 0x9771AC5F, 0xA1E06A05, 0x13CA5B6F, 0xD433126B, 0x0CFCEFA5} } ,
	 { {0x730E7A7D, 0x65B5B98B, 0xBA4B8E22, 0x030F0A96, 0x5DDFD7EC, 0xB13B4D71, 0xC690E5F1, 0x14AB50F7},
	{0x0A7AF165, 0x47797187, 0xB307A190, 0x727D2D8F, 0x7B266579, 0xD9BCC109, 0xE3DCD562, 0x134CA38A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4872 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4873 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4874 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4875 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4876 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4877 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4878 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4879 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4880 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4881 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDCA73489, 0xC0724323, 0x1AD064A7, 0xE3FDE9E8, 0xBC4B56F1, 0xC9F4B72C, 0xC2226719, 0xA328193D},
	{0x50F3F103, 0xFA14290D, 0x787E4040, 0x354F7459, 0x08562D72, 0xA133B0A0, 0x9039E1B8, 0x6D11213E} } ,
	 { {0x8C94BB9E, 0x9BDE62E0, 0xBC8A5338, 0x7853EDB9, 0x8CB1F581, 0xB4300300, 0x4C27F295, 0xA4A23111},
	{0xA5C48AF1, 0x52321A62, 0xBD8A2355, 0xF721B44A, 0x40EC2537, 0x226A13FF, 0xC8D1CE0F, 0x2EB9201A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4882 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4883 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4884 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4885 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4886 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4887 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4888 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4889 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4890 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4891 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6AC6E469, 0x4E670BA7, 0xBC9F28F9, 0x32761568, 0x61DE789B, 0x3B1A7315, 0xAE6AFB83, 0x796AE7B8},
	{0xB1DB4738, 0xC61AAA6B, 0xBD3F1784, 0x838C1460, 0x549B3EC0, 0x35DC6C35, 0x39284672, 0x043C0460} } ,
	 { {0x37467618, 0x73D4B2EE, 0xA4FCC893, 0xAF39123F, 0xBD4CEC43, 0x6BC06407, 0x3847CB50, 0x08D7D3E5},
	{0x3E0DBFD0, 0x1062558C, 0x726EB49E, 0xA8F80F45, 0xB9A52C92, 0x0771C051, 0x0E7EDA06, 0xB278327F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4892 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4893 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4894 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4895 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4896 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4897 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4898 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4899 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4900 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4901 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7F61C26C, 0xE081A50D, 0x8E7F5B53, 0x1B443A20, 0xB0DF1414, 0x8186B0F0, 0x751110D3, 0x60BCF2B3},
	{0x2865D58A, 0x296C1462, 0x9F7FB25B, 0x40B2781C, 0x282E1D63, 0x0C0BE2D5, 0xF6983A51, 0x09455A52} } ,
	 { {0xC13EA9CC, 0xB29909DA, 0xD918BF32, 0x6C739251, 0x945B0DA2, 0x12F4353D, 0xB2AF9EDB, 0x75AC4A04},
	{0x3C32E4AF, 0x49536787, 0x10E8D788, 0xE6A6ED82, 0xE65E8D2F, 0xDBDC46A0, 0x9CCB8DF7, 0x33435FDB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4902 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4903 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4904 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4905 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4906 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4907 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4908 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4909 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4910 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4911 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x45E9218A, 0x3FFA6CBC, 0x7749B6CB, 0x26986A9E, 0x528DC930, 0xE2040F74, 0x7DA27941, 0x61D6E6AD},
	{0xDAE2F37A, 0xEA6EB7F0, 0x0670C5F6, 0xF47CC282, 0x2D59E30C, 0x6BAF37A2, 0x2F19C2AB, 0x83DDBAC5} } ,
	 { {0xCC96F3D7, 0x232C7898, 0xF1237EAC, 0xE81D5C5F, 0x6B4C3F35, 0x01789068, 0x23192A58, 0x0B9AC38B},
	{0x284610DE, 0xC51E7533, 0x532869E1, 0x4D695FC0, 0xC53E3307, 0xE19B1996, 0x1B53ED57, 0x752FCB6C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4912 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4913 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4914 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4915 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4916 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4917 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4918 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4919 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4920 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4921 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE2015BE2, 0x348CDC5A, 0x60EB2C91, 0xDC8683A2, 0xEF182EAC, 0xA8A41C8E, 0x307D7E2E, 0x83141416},
	{0x2BF93F01, 0xD3B4DAE1, 0x33E34DD1, 0x02E582CD, 0x63161ACD, 0xA5B6E6AF, 0xCD51808F, 0x07B394B9} } ,
	 { {0xA4D29D50, 0x8D96DDCF, 0x4FBD8F76, 0xE7B4610A, 0xE5B2032C, 0x73E05966, 0xB1EABF36, 0x014CDB58},
	{0x29E4AE21, 0x4DF32E16, 0x237CFBAA, 0x64CF2F64, 0xFCFD87D8, 0x6100DBB5, 0xF2E23695, 0x7D64A287} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4922 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4923 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4924 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4925 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4926 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4927 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4928 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4929 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4930 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4931 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1D573D88, 0x868916DB, 0x5BEF2964, 0xB1F6C2D1, 0xDBC6522F, 0x1F58EC17, 0xB5B57456, 0x1562F30C},
	{0xA68A973E, 0xAB9CC16B, 0xE0A74BD9, 0x057E9355, 0xC67AB472, 0xFEF5C721, 0x7799BFE4, 0x57D2AA58} } ,
	 { {0x7221B064, 0xB79A154E, 0xDF309ED9, 0xEF629984, 0xA96BA8CD, 0xB2DF1935, 0xC701A35B, 0x5FD40805},
	{0x685B2013, 0xA7032C70, 0x68C492F6, 0xB4CC8F3E, 0x35C9C6DD, 0xA3206C7E, 0x899DF7B5, 0x562D997B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4932 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4933 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4934 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4935 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4936 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4937 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4938 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4939 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4940 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4941 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x447AC40B, 0xFC7FA81C, 0xCFD2004D, 0x68FA65F6, 0xBA5477E9, 0x80D9D56B, 0x34B18845, 0x4DA15EE8},
	{0x73002D82, 0x3A9BD525, 0xF7A89C51, 0x842DE9B2, 0xFE2C3279, 0xBCA5CE09, 0x957CBA06, 0x7A58FA47} } ,
	 { {0x9A935A6C, 0x6CA014CD, 0xDCEEF6C6, 0x621275E2, 0xB8885A51, 0x0DB0D135, 0x4BD1E676, 0xB8BFDEB0},
	{0x0DAF23D9, 0x9D86BC70, 0x0B767DEB, 0xC4B818D0, 0x1641C6F5, 0xF0D69EE5, 0x48F945F8, 0x06F9CD4E} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4942 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4943 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4944 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4945 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4946 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4947 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4948 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4949 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4950 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4951 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1513EE79, 0x7EEB2647, 0x96A4733A, 0xBCF40197, 0x22F37441, 0x08B10603, 0x78507037, 0x2764D228},
	{0xA66A68BF, 0x639D71BD, 0x4CA7A299, 0xC5FD1E2D, 0x35DCEE85, 0x2C99CF3A, 0xD082E91D, 0x25969C80} } ,
	 { {0x0FDFAFBF, 0x359B893D, 0x0621D209, 0x454B2D5B, 0xDA3C3E34, 0x19D44A66, 0x5905F1BA, 0x84F765A3},
	{0x33A5C5FE, 0xB5F99A91, 0xC61E08E1, 0x3BEF8261, 0x040026AD, 0xCD1146D3, 0xE57263AD, 0x9FB8EBED} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x018E98E2, 0xC0C02571, 0xCF75D8A7, 0xBC36E990, 0x067CA6B6, 0x4D73F15A, 0x506B457A, 0x767159C3},
	{0xCC79BBD5, 0xAF9A92FB, 0xB0839ADB, 0xB4A7F5DA, 0xDD8B5BFB, 0x41759FBF, 0xC3218AC0, 0x10AFC5CA} } ,
	 { {0x7D0B771C, 0x3BBD414A, 0xC823E0CE, 0xA8EFF96E, 0x3B3821BB, 0x5041DBCC, 0xDADC6E2B, 0x0A8A2204},
	{0xC14B8BB3, 0x4E54A291, 0x748093DC, 0xFE8595D7, 0xB985EDCF, 0x8769760B, 0xEECA25C1, 0xAF8447B0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC327287C, 0x77477C64, 0x5124FAF3, 0x2302012F, 0xCF9092AB, 0x682491F7, 0x734F61C1, 0x522099F0},
	{0xCDB4FF21, 0xCE68D7D0, 0xDD457266, 0xE68CC0DB, 0x9E851B8D, 0xD6F5B519, 0xFAC3BC25, 0xA04FA8DD} } ,
	 { {0x374C7620, 0x698DD3E2, 0x0630C1E0, 0x45291251, 0xF1CD0A67, 0x7018CF45, 0x38C97037, 0x21B28696},
	{0x4EA58FC8, 0xF47D44F3, 0xF94C2F23, 0x9D9213FE, 0x1A004FA6, 0x00720B40, 0x68E9EF1D, 0x2A02F40D} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4952 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4953 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4954 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4955 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4956 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCE2FFB2C, 0x9237CE2F, 0xE32D095B, 0x3AE45CB5, 0x622C3620, 0xD4AB719F, 0x339F92F1, 0x92D98AB9},
	{0x10F47B78, 0xD1D36EAB, 0x7B0E8F90, 0x00282F33, 0xA9B3FC31, 0x91BCAAEC, 0xB28D9B4A, 0x553871FF} } ,
	 { {0x542D68ED, 0x7B758BA6, 0xD7823D3A, 0xC253D1A1, 0x7E2352CD, 0x605B5D22, 0x0E158774, 0x14A7BFED},
	{0x54D69646, 0x2E2CF2BD, 0x90338E42, 0x8FDA5056, 0xFE64A92E, 0x879756BA, 0xC8E12FD6, 0xA10005F7} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x9B6486B5, 0x3FAE8C4A, 0x578E750D, 0x614A7887, 0x3AAD2293, 0x18D8D9B8, 0x68B35598, 0x86342E97},
	{0xEB0C1D40, 0x4409A9FF, 0xE7CADBBF, 0x4A922377, 0x477AD203, 0x1AB51F1F, 0x4639F96E, 0x545DFB56} } ,
	 { {0xDF579503, 0xBD4494B1, 0x3792341A, 0x34F86437, 0x9C43552A, 0x61918E67, 0x73E5465E, 0x1D8C058A},
	{0x2EB42395, 0xC9D0E9A6, 0x3B8B3F04, 0x82ECDF91, 0x21FB07E1, 0xEFC00437, 0x8FE2C39C, 0x92A7FB8C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC1BC98C1, 0xC904EE79, 0x7C1886AD, 0xED98BD81, 0x147D1B02, 0x8FCA71BB, 0x4379E666, 0x72E3FC3D},
	{0xCBA78746, 0x46A9187C, 0xA08893EE, 0x95FE9A76, 0xB6BDE40B, 0xC3023605, 0x56CE33E7, 0x620E1403} } ,
	 { {0x7E2C4C97, 0xE88FCF2F, 0x9DF640C8, 0xDDBB282E, 0x7D49CADD, 0x0C325E45, 0xF887B0F8, 0xB918619A},
	{0x478D4BFD, 0x82DE995D, 0x059AA81C, 0x9C170495, 0x576A139F, 0x580C9428, 0x43A1C36B, 0x11EA8211} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4957 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4958 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4959 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4960 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4961 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFB029BB9, 0x9F56DC6C, 0xACFC907D, 0xCE91C8E6, 0x0F3C2527, 0x86B78023, 0x7B07144A, 0xB72073D3},
	{0x76E2F98E, 0x4BA737CA, 0x9D2404D2, 0xB7C6B3A0, 0xE4E2C883, 0x08703D6F, 0x6C0DD182, 0x2FDBE633} } ,
	 { {0xAA93BCA7, 0xB7BCEB6E, 0x8E5F401F, 0x5D4F8757, 0xE351437C, 0x794AABB6, 0x4E75945F, 0x9BCDFD70},
	{0xC10A0A21, 0x97E1CF97, 0x4498DD7C, 0x9521B352, 0x7ABD7BFF, 0x13773134, 0xF2C83E87, 0x4C124629} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2EFC2B3F, 0xF49860E1, 0x1EE17277, 0x327B5457, 0xBA503FC7, 0x707E79F7, 0xF5E91139, 0x71F9D4DD},
	{0x86B90064, 0x64E8E77A, 0x1AEA089F, 0x8833422A, 0x40FB2DDE, 0x32847E86, 0xFCE3B7CE, 0x762AE171} } ,
	 { {0x13E9A3E8, 0x97A5935F, 0x5952483F, 0x85EC701B, 0xF64DD889, 0x465931F5, 0xA8C3163A, 0x0DD3331A},
	{0xDED81E26, 0xFDD00ACF, 0x3DB482E3, 0x45E70B2A, 0xD16CEF12, 0x9D5AD0EE, 0x22184243, 0x0142CE8C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA911CCF9, 0x14D00B40, 0x8E1FE383, 0x53E68073, 0x8A7B9560, 0x5A213ADC, 0xF8453623, 0x5B8876C0},
	{0x73EDE7CD, 0x3AE29AB7, 0x0FC4ADD3, 0xEA8F17B3, 0x9F63E82E, 0x6B1C834D, 0xCBB4D50D, 0xB0AD6184} } ,
	 { {0x6DA09A9B, 0x41315153, 0xAED25A36, 0xF829938B, 0x773E3427, 0x2EAB748D, 0x675F1475, 0x1FC21BE1},
	{0x355D9900, 0x83DCCE5F, 0xD9459595, 0x8700E823, 0x8C5D26F6, 0x83FC4FCA, 0x992913BB, 0x4F238F5A} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4962 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4963 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4964 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4965 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4966 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF4A60673, 0x031F7970, 0x6F3EA411, 0xB254C6AF, 0x3ECAEFF1, 0xE0F70934, 0x49B3F10D, 0x7017A81B},
	{0xB1B4726B, 0xFA10EFF2, 0x75E3030A, 0x7E5487B3, 0x975943B9, 0xC92A991F, 0x2F3316E2, 0x4B8DD607} } ,
	 { {0xAA67EAA3, 0x0E3DBFF6, 0xC1160102, 0xF333B4C9, 0x1975FDCF, 0xB2FEC6C6, 0x1D23A18F, 0x44E9675B},
	{0xBDD64021, 0x2562BB0E, 0x2449F972, 0xD369BF4D, 0x7CEA1092, 0xDABA713E, 0x1571E199, 0xA77F63D2} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x0DA589B1, 0x007B7500, 0x939B4111, 0xAF94849E, 0x05C6711C, 0x453AD559, 0xECBD224B, 0x7C756063},
	{0x9A95947D, 0x3886C50D, 0xF7C530B6, 0x7D325555, 0xE9217FFC, 0x8A53D9AE, 0xC77844EA, 0x5D9C803C} } ,
	 { {0x7DF27ADD, 0x3F5BF58F, 0x5BBBF92D, 0xA2BFDCDB, 0x55598AD6, 0xEA157856, 0xBD8A3EFD, 0xB2D60A7B},
	{0x9646C4B0, 0x8AE92F3C, 0xCB02FC1A, 0x3D54C797, 0xDF3D5B23, 0x3CEAC59E, 0x5B3E9DA7, 0x57D2D9B8} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA02011DA, 0xBA265ED1, 0xDC596970, 0xC8D8651A, 0xD4CB0FB1, 0x45642D39, 0xA3FF9F3C, 0x4072F570},
	{0xC676F2AC, 0xDFE49106, 0xD80BAA8A, 0xC1742B22, 0x1F2AD90A, 0xB4BC6BCC, 0xEEF85E84, 0x1A94BF78} } ,
	 { {0xF9B303E0, 0xD8E94742, 0x2B45F737, 0xC9683842, 0x04F01A5F, 0x477EF22A, 0x70561289, 0x13607D92},
	{0xA8C2596B, 0x3751144A, 0x04470F7D, 0xFE8638CB, 0x7777FDD9, 0x6F6881C4, 0x7010DBE5, 0x536A68D0} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4967 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4968 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4969 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4970 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4971 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x21C0DEB8, 0x9DF1CE57, 0xB3B6A90B, 0x74F1FE85, 0xBA1AD2DA, 0x9483D4E7, 0xF02946ED, 0x5DB4311F},
	{0xD9B77378, 0xFD8036EF, 0xF3722832, 0x00836C0D, 0xD3AFE67B, 0x45DE0B87, 0xCEFA8A14, 0x4EFB3A39} } ,
	 { {0x2E381BAF, 0x81395BC3, 0x3B88F72C, 0x86093496, 0x4EDB3AA9, 0x1623C290, 0x236A0B3D, 0x3860F29D},
	{0xF231C072, 0x06F16EEC, 0xFFF7C2A6, 0xB2E77EF0, 0xCD3A2C6A, 0xE3DC5EF6, 0x3EB2665D, 0x7BCB697A} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x31E4A337, 0x65462BD2, 0x4BAEDE4B, 0x62074692, 0x43F550A1, 0x513EB04B, 0xA4ED2247, 0x29FAD103},
	{0x32853989, 0x3203D633, 0x1AE10EC1, 0xAA7DDE0B, 0x43A4C8DD, 0xB61153FB, 0x92B0C301, 0x192FB56D} } ,
	 { {0x12D464F3, 0xCAA38888, 0x386E2C7E, 0x6BC8C4AE, 0x8D67D024, 0xC5320506, 0xE9228F0A, 0xAFAB80A7},
	{0x3D5DD06E, 0x51A2BAEB, 0xFFE63BB5, 0x958CC2D7, 0xC564E901, 0xA799A282, 0x1AAE65F6, 0x5D40DB7C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE9B25400, 0x6B62F01A, 0x79E40C17, 0x6F0C2B74, 0x83791D00, 0xC4059394, 0x3D2DBC70, 0x43D40714},
	{0x88AAD754, 0x0ACDFFF6, 0xB3B8FC21, 0xD6AA2071, 0xDF41F045, 0x614C4C03, 0x98EF7B9E, 0x4263E207} } ,
	 { {0x3E9E0E5F, 0x5CB84212, 0x5999A8CC, 0xD17BD431, 0xD3F46047, 0x49D0F275, 0x0CDAA70D, 0x40A8AB6F},
	{0x34F60C60, 0x69ACA0B9, 0x14345116, 0xC9FF44FC, 0xF43CFCDC, 0xDCECAE14, 0xE03980A2, 0x4604DD24} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4972 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4973 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4974 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4975 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4976 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5AC997F8, 0x6FC20A7C, 0x1396C968, 0x79892E93, 0x68AEF4E6, 0x192EA600, 0x2BBD4471, 0x3859F20E},
	{0x316E40A8, 0xAACF135E, 0x65B406AB, 0x32916D08, 0x98342F06, 0x89920BA9, 0xC92772BC, 0xA5480FB5} } ,
	 { {0x6C9CB008, 0x4D2FED6B, 0xF4740980, 0x9D809DE9, 0x0AEF9F10, 0x6601DEA5, 0xA2A52EC4, 0x434DE0D3},
	{0x61692488, 0x1F6C2BE0, 0x9C93A842, 0x2D5C5FE6, 0x1B52A3A5, 0xB28C8BEC, 0x5731ECEB, 0x1FCDB860} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2CBEAA61, 0x9A3C8A3F, 0x762706A4, 0xB31605DF, 0xDD791978, 0x6EF0FA88, 0x3BC65EA8, 0xA82976F6},
	{0x40268F64, 0x956934DF, 0x65EF05E5, 0xA491A6AF, 0xE28BA51F, 0xD5AC13A1, 0x43EC629F, 0x05C56250} } ,
	 { {0xF77B8D3D, 0x8D5440D5, 0x1AED3D11, 0x30A2467C, 0x11F0C08F, 0x4871BA38, 0x0B1A0330, 0x716ED2F3},
	{0xBA0A0A2F, 0xF88E5A12, 0xB7A45C5E, 0x452AEAD4, 0x26E9FC81, 0xC2286048, 0x7CE178D7, 0x94E7AB1D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2FA68287, 0x2D177D9A, 0x4B42A5B1, 0x4656B68B, 0x10D67B59, 0xF1689DB9, 0xB7AFDFAB, 0xAF9C0E35},
	{0x75986167, 0xE2663E53, 0xE24A06ED, 0x5163D370, 0x5EE0D5C1, 0x59FFB380, 0x0D5FD1D7, 0x9FE14F81} } ,
	 { {0x18653975, 0x456A164E, 0x9110C5A5, 0x25CCFDC6, 0xE2066EED, 0xCFF84B5C, 0x6E4EAFFA, 0x8D3F374E},
	{0x74AA75EB, 0x3DB26B09, 0xB0E7A923, 0x2789CC86, 0x6D5FAA6B, 0xE872C8EE, 0xA3BFE0A4, 0x03B0C197} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4977 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4978 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4979 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4980 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4981 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x19075BA4, 0x01F6CCD6, 0x4EC80E1F, 0x5161D049, 0xBE81A730, 0xAEF6D565, 0x586FE551, 0x400EA43A},
	{0x11924958, 0x630516D0, 0x24363DD6, 0xCCC196C9, 0x2F93639E, 0xF392B53A, 0x84157861, 0x09B034B1} } ,
	 { {0xB5B9E617, 0x4E65E8B8, 0xF378DBFE, 0xF28F550C, 0xBD2BD5A7, 0xE820A4DA, 0xC0E239F9, 0x9C7882F2},
	{0x8D47A556, 0xBBAB0E3C, 0x790C195B, 0xC8E4B407, 0x25E08AEC, 0xE44D2735, 0x2F8610EE, 0x08A989FC} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x75B352A7, 0x4DC5CA6E, 0xF5FC56AA, 0x158AC34B, 0x155026C9, 0x1B2C3B31, 0x83486440, 0x37B4D666},
	{0x31F20FEB, 0x1B795E87, 0x3367CC70, 0x22793E37, 0x109C3878, 0xF958991F, 0x77E7838D, 0xAFA6B5DC} } ,
	 { {0xC183E63C, 0x79687180, 0xB768A3B0, 0x9015F04E, 0x15398BB5, 0x7FA39335, 0x64E5F300, 0x2B595097},
	{0x1FEA14E2, 0x4A342581, 0x463BA52E, 0xF01EC632, 0xB9CC2661, 0x807AA05B, 0x6CA602A0, 0xA38B54C8} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xDCD538AB, 0xC2AED530, 0xC2BD00A8, 0x6860F0EC, 0xF0207847, 0xF44D5F3B, 0x7F899147, 0x6F87071B},
	{0x0A32BB8C, 0x43FC32C8, 0x77310FDC, 0x1E05F6ED, 0xA228D74E, 0x623B41FD, 0x80334C3F, 0x2DA3E1ED} } ,
	 { {0x8BF50CAE, 0xAC79F8CD, 0xE22FD649, 0xBE10927D, 0x69183EFB, 0x2712C904, 0x979370E9, 0x93CF5822},
	{0x87D934A2, 0xDF02624A, 0xA9DF5107, 0x26B3A80E, 0xDC728329, 0x70704E47, 0xA8FE54D6, 0x41097E6A} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4982 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4983 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4984 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4985 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4986 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x171F2154, 0xCD3EF7A0, 0x3E03D8A5, 0xB6004B00, 0x0B5EE15B, 0xE2A6F623, 0x040535CC, 0x427D1F39},
	{0xF282F5D9, 0x0181B91B, 0x7E5DF368, 0x079B938F, 0xAEFCF382, 0x59509C5A, 0xA0A171C6, 0x5C288531} } ,
	 { {0xFD424272, 0x53D75253, 0xD46C53EC, 0xCA0A832A, 0x0D6BACE2, 0x0D01F8B3, 0x33521772, 0x09CC8EEE},
	{0xC155B865, 0x368B9C13, 0x986C8AB5, 0xDDBD4614, 0x3953B609, 0x7F05274A, 0xEF052AA6, 0x19159295} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x90C76C09, 0x046CD731, 0xBAA0A410, 0xB560CFCB, 0xAE21F40C, 0xC2D1A73F, 0x1D3897C6, 0x08F86D8F},
	{0xA9C609E0, 0xCCF7F39E, 0xE205B7CD, 0x808D79EE, 0xA0B639F2, 0x594813F6, 0x185775A4, 0x0663D322} } ,
	 { {0x6DAC88E7, 0x90ECF0B2, 0x6CE7746A, 0x673A3F02, 0xB0E399BE, 0x5E927D15, 0x38A69E46, 0xB0A837DF},
	{0x54F87FAB, 0x82BFF5CB, 0x30D77F01, 0x408F0E8D, 0x15486069, 0x4FA420EA, 0x3CC73E3D, 0x114D7695} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7036B58B, 0x945ED48A, 0x596AC171, 0x6FE05522, 0x147F2312, 0xE51D99C7, 0xE78DB872, 0x8C56B1DA},
	{0x82B366A9, 0x93D909AC, 0x1D722723, 0xA1370EE1, 0x495CEF81, 0xC03F2DF9, 0xD1E0D994, 0xAB4FA258} } ,
	 { {0xDA83BA2A, 0xF81E83D7, 0x9BD85D88, 0x50CD44C3, 0x5E84210C, 0xBDA70777, 0xDF74F77F, 0x3A150629},
	{0xED7D4E47, 0x13E5CABE, 0xAA483813, 0xFE03DE73, 0x0F6E2D49, 0xE792E41B, 0x88E67667, 0x388EE067} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4987 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4988 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4989 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4990 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4991 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC04C4713, 0x466E69C4, 0xB4A08A9A, 0x79A9B9B7, 0x776AD6D0, 0xEEA0C35B, 0x7197455E, 0x2F03BFDD},
	{0x2E2AF363, 0xC4E0EA66, 0x961F61AC, 0xC5030476, 0x8C99137A, 0x357B5DB5, 0x8EFD2755, 0x64AB5A4E} } ,
	 { {0xA1C2B660, 0xE823AEF3, 0x4F450142, 0x3DACA10A, 0xF4318AAC, 0x47ADC757, 0xA2987B1C, 0x01E16370},
	{0x9C32A3DD, 0x771ACA36, 0x2C78D896, 0xF1211A8B, 0x816F761B, 0x7983407F, 0xE83B09B4, 0x1121F75F} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xB10BDC7A, 0xBF015657, 0x2E56824E, 0xC3DC2BF2, 0xB05562B0, 0x5E0A012E, 0x865D3AA1, 0x50BBBDA2},
	{0x1A46BB4D, 0x6B3B975F, 0x5A997228, 0x6E59766E, 0xDC5D7234, 0x750A40D7, 0x95087431, 0x9B6DF3CD} } ,
	 { {0x1BDD6114, 0x905A53C1, 0x16836463, 0x97DC963E, 0xA0F24FEA, 0x76B1E4C8, 0x1BF68AEA, 0x01F4D8C5},
	{0x7A0F2503, 0x0A02E1A8, 0x5D79931F, 0x7F5D8009, 0xAB642AEB, 0x610748AB, 0x2A729835, 0x32CCDACB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB45BB677, 0xE9717499, 0x6A27F027, 0xED62A35F, 0xE91CD48B, 0xC55CE49D, 0x298F1E68, 0x68E001A5},
	{0x92D100FE, 0xEA074548, 0x164B9551, 0x3822102E, 0xFB21E6BA, 0xA2CBEE83, 0xC17688BF, 0x540A03B2} } ,
	 { {0x2D143384, 0x23658F09, 0x6F32A581, 0xDB61C0C1, 0xA2FE6206, 0x16386F55, 0x6F7EA941, 0x9140B028},
	{0xD11297D6, 0xAFAFAD8F, 0xB9761B1C, 0xF549A6E8, 0x5787C901, 0x02046FAD, 0xA7FDF13C, 0x08395DD9} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4992 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4993 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4994 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 4995 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 4996 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4211AAE2, 0xEBA17556, 0xDF0A2DA8, 0x48812B89, 0xF3891263, 0x37ADCE6A, 0x5E25723B, 0x52589B03},
	{0xD403EA41, 0x0C683002, 0x464E07A7, 0x7C960029, 0x399672BC, 0x1D463321, 0x01018565, 0x31267E1A} } ,
	 { {0x7948E0A2, 0x0D924A51, 0x63FE62F5, 0x117E4860, 0xD55476A2, 0x5CCD58E3, 0x5E3E1447, 0x5039B37D},
	{0x5C736AE8, 0xE9430427, 0x568EACE3, 0xDF499998, 0x7CBFB7D6, 0x4ABA785B, 0x53D7F86F, 0x3610673E} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF4BE32FD, 0x81AE2E73, 0x359D6EF2, 0x7AC49553, 0x8DE0A683, 0x9D6352B2, 0xD77859A1, 0x17D56D38},
	{0xF6CB77E6, 0x660F49A1, 0x715B9892, 0x1A850D09, 0x21A12051, 0x97235564, 0x08F4C042, 0x53B8074E} } ,
	 { {0xC657E91B, 0x412ACB2E, 0xB49E187B, 0x532C05BD, 0x225769ED, 0x429D783C, 0x7D24DF4C, 0x67ACF4FB},
	{0xFB0F2480, 0xC9918798, 0x7F529175, 0xD602DADD, 0x35376661, 0x545FAED8, 0x708594EC, 0x3397A8FD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x76E8E83B, 0x053B21D4, 0xCA6028D6, 0xF09E7D19, 0xADCD222D, 0x4C1B9839, 0xAC101899, 0x0EF224BA},
	{0xB290D33B, 0xAD455705, 0x54960A53, 0x0435DE35, 0xC5EBF323, 0xF4BD6759, 0x6D934300, 0x904198D9} } ,
	 { {0x744D1A05, 0xC0768C2B, 0x0A89A945, 0xE53A1EB6, 0x91628ABE, 0xEE1861B6, 0x85DE1754, 0xAE773980},
	{0xBC1738E8, 0x22BBD51D, 0xBC95759B, 0x508AC306, 0x1136169F, 0x0EEE62BC, 0x43D9B853, 0xAD9761C2} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 4997 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 4998 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 4999 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5000 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5001 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA1B5F165, 0x6299E0A2, 0x500F72DD, 0xA8A38610, 0x2D3F96F1, 0x9C222B4B, 0x1D0213C0, 0x0DA6EC67},
	{0x866F89DE, 0x740E314C, 0x01407273, 0x63C201AB, 0xE83C1AEE, 0x297A2B57, 0xD6CEEA10, 0x64EEB87C} } ,
	 { {0x0F816919, 0x4CDCCECF, 0xFFC6FCEF, 0x92493311, 0xC7B86DA8, 0xFA2A4F66, 0x47F29992, 0x15768EDD},
	{0x724BAAB8, 0x8090B2E5, 0x27E419C3, 0xC97D491F, 0x6ACB968B, 0xBC95BB81, 0x67FBAF61, 0x0413016D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF38A8745, 0xB8A02FF9, 0xE0965C99, 0xE4BDBC34, 0x864F3D83, 0x8356A53E, 0xBD11F995, 0x8B9C31C3},
	{0x20C37952, 0x668AF3E2, 0xA066A222, 0xFA0CBCFE, 0x2067F381, 0xFE6B8904, 0xDD44B136, 0x9CB13FC3} } ,
	 { {0x181550C5, 0x66AC06C1, 0xE4B9116C, 0xA62DDA5D, 0xF3A73B60, 0xAA2BF0D8, 0x3DB17279, 0x8508C48C},
	{0xDBBC22F8, 0x036645E6, 0xBCB58C33, 0x35AE5441, 0xB33704FA, 0x6AC6518F, 0x31334EE6, 0x7EA512D6} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8AD77A74, 0xBD401ED4, 0xA13D2BD7, 0x2D53A2CA, 0x164C6D87, 0xCE34FABA, 0x1CB2C7DD, 0x7D89CB0E},
	{0x78F3B693, 0xB16E84EB, 0x78901D0B, 0x84A506EA, 0x40CB53E2, 0xF9A53359, 0x55BC8956, 0x2882E4A3} } ,
	 { {0xFDB4AE99, 0xD3A88EC2, 0x7B636DE0, 0x69E3DFF4, 0x419BB450, 0x59B3CA11, 0x014ABE5D, 0x4CC574B8},
	{0x244A9F24, 0xFC82FAA8, 0x9FC70CE0, 0x6A81939C, 0xA46C2C64, 0x33D524A6, 0xB23EBCB1, 0x24195C4D} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5002 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5003 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5004 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5005 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5006 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xEACD12F6, 0xE180FCAA, 0x80C1045C, 0x10AA425F, 0xE1A10507, 0xA40F9C18, 0x755D51A1, 0xB137A6AF},
	{0x2D435E14, 0xB13513A5, 0x118938FB, 0x3616CE0E, 0xB09EFDE8, 0x4A6031D4, 0xD1DEE9B7, 0xB0A18A1E} } ,
	 { {0x4FDB9E25, 0xAFBF7CB2, 0x9805568C, 0xD21F429A, 0x88F88828, 0x65CF0BEA, 0x7B2FC915, 0x4325DF09},
	{0x513D17BC, 0x872B4570, 0x8F75319E, 0xE53A17D7, 0x53824E2D, 0x137C3EDB, 0xF7F66A82, 0x3831CB26} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xDCD66B50, 0x17081DD9, 0x3071F604, 0x7A96646A, 0xE41E86FB, 0x38B51130, 0x9E2B413A, 0x4D28AB08},
	{0x98BC381E, 0x4294F2C5, 0xB18827F0, 0xF9EEE148, 0xB15F868A, 0xFBD5843E, 0x345096FB, 0x6BBBFB64} } ,
	 { {0xA3C9DBEB, 0xF1B304F9, 0x10F6A5C1, 0x7E1FF7B2, 0x408C734A, 0x27A54433, 0x5126B27C, 0x2904B697},
	{0x8057C499, 0x8E7CBFF2, 0x9AD97DC7, 0x2B4F877F, 0xF9E626B8, 0xC798BA22, 0x2CE9011F, 0x8334E134} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xCE6842CC, 0xC2717F96, 0x9079D37A, 0xE17FFFFE, 0xFD435545, 0x023E1F94, 0xC0E043E2, 0x7CF659DA},
	{0x06A0FD0D, 0x3DDAC5C9, 0xE0247F34, 0x674AA1E1, 0x00D00E08, 0x84DF504E, 0xB6755166, 0x8E37FD63} } ,
	 { {0x10E2DEF9, 0x95B7B025, 0x135DEDB4, 0x21D7C2F9, 0x3413754A, 0x7DB4535C, 0x20755268, 0x8ACFD9F6},
	{0xEE688E21, 0x64E606D8, 0x94D3DD50, 0xB77A2A07, 0x1087F3FD, 0x75FCAC7B, 0x0E6A3F4A, 0x41E99B1C} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5007 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5008 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5009 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5010 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5011 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x076F908B, 0xEFD192EE, 0xFF27BC83, 0xC9199B7C, 0x54B5D643, 0x15264C81, 0x22A42F56, 0x97BF1FB0},
	{0x8D9BA872, 0x2AC6E1D6, 0x1564E7D9, 0xB2CEBA4B, 0xC228E2FA, 0x6A5E47E4, 0xE57A3AAD, 0x35B9C57B} } ,
	 { {0xBF8525FA, 0x9A897BD5, 0xBE63F8D8, 0xE4B5892D, 0x46ECB417, 0x33E92A52, 0xC205A1F8, 0x5B80C2B6},
	{0xA7EF6EE3, 0xAE07BA32, 0x3077B0FC, 0x9A2F5CD4, 0x2FC6A370, 0xD6D1EACC, 0xDC2D3E65, 0x907B955A} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x23D6DE6E, 0xEFEFD198, 0x2BBD3900, 0x17E4A909, 0xA7B47485, 0x1DB75A8D, 0x8194E1CF, 0x3536009C},
	{0x4F0EC619, 0xD646F30B, 0x030F2E4D, 0xE752CF2D, 0x40DA23BD, 0x6DA74B49, 0xAC3EE7B2, 0x59A5B1C1} } ,
	 { {0xDB797BDC, 0x2EB0CFEB, 0x0493B9E5, 0x8BD747C4, 0x9D718142, 0x8EAF98CF, 0x826B0B77, 0x813D9F07},
	{0x3070696D, 0x8AFCFBD4, 0x19FE59BD, 0xC1636A76, 0x303FCBC1, 0xC91D866E, 0x3B07DB79, 0x3DEEB1AA} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x691F7976, 0x0EB80F7F, 0x58931A7E, 0xEA7DC640, 0x38650955, 0x7FF7B344, 0x7A4D512D, 0x2048CBFD},
	{0x2325CAA0, 0xE1B62F61, 0xABA9630B, 0x154D867A, 0xD9EC8A01, 0x469DFDDD, 0xB0802CEB, 0x4A8629B1} } ,
	 { {0x7ED8B5C5, 0xD72C633B, 0x85509A2D, 0xE0AC3B1E, 0x966E8BD0, 0xB9E67AD3, 0xBDBF47E7, 0x783C5F04},
	{0xE850224B, 0x5BAB8CEB, 0xB57E42A9, 0x68F2671B, 0xE839B718, 0x1C0663BC, 0xD023FE94, 0x962E08E8} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5012 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5013 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5014 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5015 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5016 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB75895C5, 0x19CFC590, 0x93B135B4, 0x38F6CAE6, 0x1B8EC16F, 0x2848D929, 0x9004158E, 0x2AAD8901},
	{0x81E3A1FD, 0xE4475837, 0x30FA43D6, 0xF7927C84, 0x673075EA, 0x0774BBB0, 0x3D256DE0, 0x777E1F6C} } ,
	 { {0xACCE04D3, 0x497F946C, 0x869FDDDA, 0x87C89529, 0xB5D0E124, 0x0C67FF89, 0xEE52E95C, 0x4CB999FA},
	{0x693D4684, 0x002BB618, 0x8245897A, 0x79CFCC49, 0xB79ADB47, 0x758BADFD, 0xB7D63BF3, 0x7FAEDBCF} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC3DEE949, 0x67B02069, 0x9DBF7EFE, 0xB45E7069, 0x728CE832, 0xBF2C2CA1, 0xCE9EE9CD, 0x1CA5B617},
	{0x2BA19963, 0xD7F62280, 0x2B11220B, 0xBABA5A53, 0x0FD31B00, 0x15BA32D8, 0xC386A0D9, 0x5AE19588} } ,
	 { {0x2F4F60D8, 0xC972ABCF, 0xCEA9C71C, 0x18CF5A45, 0x8695B83A, 0x7F2FD971, 0x637E3BE7, 0x85009394},
	{0x95F59FCD, 0xD88687EE, 0x5BF839AF, 0xB56BD6C8, 0x22B942D6, 0x7004C576, 0x52C6DD73, 0x7D55C566} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE552BBF6, 0x2A63F2DB, 0x69C6A3C1, 0xC4EB1F98, 0x6EDD3B47, 0xBFEAD4B1, 0xC2F45A87, 0x1C2A0481},
	{0x2BD9B89F, 0x372A8134, 0x35C626D2, 0x692897CB, 0x8DD811F3, 0xAFC04DF7, 0xD2C6A14F, 0x46104437} } ,
	 { {0x54DB0183, 0x55B22D57, 0xA7B5CEBF, 0x5718090B, 0x5740437A, 0x3D42A589, 0x253BBD80, 0x3847EFEF},
	{0xD6DC4DC5, 0x4F414D7F, 0x3D9E4515, 0xC533A640, 0xBAF3E95F, 0xFC358AB9, 0xDD118D73, 0x1F22DA9B} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5017 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5018 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5019 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5020 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5021 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE79C4161, 0x65703DDD, 0x3647FBE0, 0x698B3472, 0x1E91941C, 0x98F402F1, 0x3CA0610A, 0x60304B05},
	{0xB0287CE6, 0x51785E3F, 0x799A5EFF, 0x17848411, 0x87D2FC3E, 0xF3A4C73E, 0xFC1D72D8, 0xAC5F21BA} } ,
	 { {0x3684EE95, 0x7CAE6B65, 0x0D58AADE, 0x73B654E6, 0x4CC028B7, 0x9657F7D3, 0xDE163646, 0x96E56153},
	{0x54396740, 0xB81E6A9E, 0x93B79208, 0xF043FDA1, 0x7925B13C, 0xD80CEABB, 0x552FE71E, 0x03304251} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x72F076D3, 0x0AC482C7, 0xD840DFCD, 0x700B49E3, 0xD12240F9, 0xCE97304D, 0x9E4C9EEB, 0x18606F93},
	{0x69703773, 0xE1020460, 0x311D41B1, 0x6BEEED6F, 0x2618401A, 0x522ECEA6, 0xBC148C83, 0x34E7CCA0} } ,
	 { {0x1AEA980E, 0x5BA0E479, 0xB34E186D, 0x8518E0F3, 0x31CA51F8, 0x75641839, 0xAE332272, 0x1C3FFE52},
	{0x66E2F583, 0x89B651BC, 0xEB30DA2E, 0x114F65A7, 0x61DB79D1, 0x24557D44, 0xAAC67F8F, 0x8E2A0FE9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE1A1749C, 0x492EF01A, 0xDA5B94A3, 0x684B2FDB, 0x765A620D, 0xBB3D7279, 0xD9904E35, 0x2A82074E},
	{0xE26DC64F, 0x334DACCA, 0x0DF3D201, 0xE0741729, 0x6A6B648F, 0xF03E3FFD, 0x180FC6AD, 0x60C55673} } ,
	 { {0xC1E94DF7, 0x33BE7860, 0xEA679BC5, 0x767F735E, 0xA9D4528E, 0x9211CF29, 0xBB11060D, 0x2AA0303F},
	{0x9E55427B, 0xC67B51A3, 0x7EFFFA9F, 0x148EEB03, 0x7935E0E0, 0x1F8DC1DA, 0xDC7EAFFC, 0xA683C3ED} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5022 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5023 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5024 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5025 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5026 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x47CB0C7D, 0x1C2820E1, 0x53AA4605, 0x4D10114D, 0x85549624, 0x358055D7, 0x651BE27F, 0x09353CB2},
	{0x90601BFE, 0x42ED19CD, 0x6ACEC773, 0x85FACA34, 0x49F42F70, 0xA2235323, 0xD52E50B4, 0x24A1C8D6} } ,
	 { {0x7B0435A9, 0x49255579, 0x3008DFAD, 0x94B8FBA8, 0xDEF57BF7, 0x0A0FBC0B, 0x36030020, 0x04C67DFB},
	{0x77DEE9C5, 0x432918C8, 0x4B93B048, 0x6730BE37, 0x18882229, 0xA7C3F774, 0x2386C579, 0xB0B04425} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x495AA5A4, 0xF1C3F50F, 0x304995E3, 0xBB30A2F0, 0x15B4DF79, 0xC09AAE3C, 0x64631540, 0x8D5BA51D},
	{0x75FF0767, 0xFA843F56, 0x6FC3E45F, 0xE0B7C2A1, 0x06C98F9F, 0x0C357169, 0x8D59FEA1, 0x0B249A81} } ,
	 { {0xEA908FAF, 0x44C09A00, 0x64C6B24A, 0xD0D700A2, 0x48FFD301, 0x3A676360, 0x12D217DE, 0x6420DEA4},
	{0x6FD523F8, 0xC43EEF9A, 0x41FD7AED, 0x3E84EE08, 0x2C58D73F, 0xCDDDE74A, 0x7B0D4EF3, 0x05B983C2} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB2E3962C, 0xCE2905AC, 0x811137C6, 0x66ED2652, 0x7819A9B7, 0xB48C629E, 0xA1FAC914, 0xB5CB5612},
	{0x63992FEE, 0x09F6EDCD, 0xF8C6D62C, 0x44339494, 0x32EE731E, 0x2789F93F, 0x868AB5FE, 0xA035B635} } ,
	 { {0x95283873, 0x0B0F36E4, 0x8626C431, 0x3795FB10, 0x7CD53D80, 0xAFFCB70A, 0x44FD8221, 0x9D0F132D},
	{0xD92F64E6, 0x15447F36, 0xB9945166, 0xEE4C46B7, 0xFBE194C6, 0x1EAF31DB, 0x693C428F, 0x692D94D1} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5027 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5028 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5029 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5030 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5031 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC297DA86, 0xD821E326, 0x3B81745B, 0x8CB8874D, 0x10FAE2ED, 0xCF2D6812, 0xBFFCE58D, 0x9E7D556B},
	{0xBB7CDCF5, 0xD8E24FC0, 0x56407600, 0xD65B461E, 0xE9D7EF7D, 0x5F2AD75C, 0x70CAB6B1, 0xAA218057} } ,
	 { {0x275FE83B, 0x512C42DA, 0x238C63D0, 0xC93891C7, 0x3545EE49, 0x482787DA, 0x0BC83C22, 0x76675431},
	{0x485F55B3, 0x467FA48A, 0x4994BE20, 0x4DF35F00, 0x32904F8A, 0x63AA2A68, 0x2AC40CB8, 0x1273FD11} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x052E1AF2, 0xA2ECE527, 0xAEB926C7, 0x94C30585, 0x575C8E0E, 0xEDC88E2C, 0x14E943C9, 0x1FEADA14},
	{0x6C4060A2, 0x86B75523, 0x8B44B37D, 0xE0FAB47A, 0x357DC5CC, 0x3D4358FB, 0x85F43A0E, 0x32B93CE4} } ,
	 { {0xE97367F2, 0x2F710F53, 0x13FADB2C, 0x037E63C8, 0x4ECC8E3B, 0x662E01BA, 0x1B60E6A3, 0x8E913256},
	{0xCD5E6B19, 0x172608D4, 0xADF13BDE, 0x224ECB43, 0xEF6D9E9A, 0xE1F90DD7, 0x26713C74, 0x6B723803} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3E5B1D98, 0xDF4694C4, 0xA0883A61, 0xF144470A, 0xC88464A0, 0x7D1F3A17, 0x458B45AD, 0x002CBFA9},
	{0x716BF688, 0xE6C7C689, 0x5E025394, 0x3DD66938, 0xB74ED408, 0xF246E1BB, 0xE7E1CA6D, 0xA980146B} } ,
	 { {0xAF5717FA, 0x7F273240, 0xE5968DCC, 0xBD6489C1, 0x224EB169, 0x6A71D8A9, 0x028A0C52, 0x0FB0CD59},
	{0x3C5E96EF, 0x796B6B76, 0x1C8F790D, 0x8152FE99, 0x2F3CF3A5, 0xF3C46D32, 0xB6D73AF2, 0x7FDB6EF7} } ,
	 { {0xA4C27507, 0xC9B98BB1, 0x47AF91B2, 0x1B1C2AD9, 0x9A4434D6, 0x19FB8285, 0x950B3A65, 0x3B81236A},
	{0x12EFB848, 0xACC38F14, 0x097C1CC3, 0x1DB11AFD, 0x9F886004, 0xD978DE09, 0x55485F85, 0x42AB5B4F} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5032 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5033 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5034 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5035 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5036 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5037 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5038 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x4E3AA3D8, 0x350AC87A, 0x580D85CB, 0xBC296DAA, 0x45E04F94, 0xB3C9D9A5, 0x76C80B65, 0x093D337A},
	{0x54A774FA, 0x15AF376C, 0xE07A9D76, 0x830B3F22, 0x775615E5, 0xE1420C3E, 0x846702BA, 0xADA54E13} } ,
	 { {0x4312E0D9, 0xE1222B56, 0x59BA376C, 0x733E472E, 0xA3A9C8E3, 0xAA9F9E80, 0x95C8F8A9, 0xAC070316},
	{0xDC0A8514, 0x2DDDED18, 0xF586C008, 0x855D3737, 0xFCAAA00C, 0xE34E3097, 0xC9CA49AC, 0x8B479ABB} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x7269CE33, 0x04A9E443, 0x567D723C, 0x80F328DE, 0xC17A0711, 0xD8C6A21F, 0xFD8947C1, 0xAAA36EAD},
	{0x6050D74D, 0xAFFF5D14, 0x515562DC, 0xE3C8ADCC, 0xE859AF79, 0x55760271, 0x99506938, 0x32C13F3B} } ,
	 { {0x90B9A268, 0x0259B8F4, 0x41C10423, 0x386C1C79, 0xB0603071, 0x26481BF9, 0x828161F0, 0x55737F55},
	{0x2B3CA718, 0xF36D16F5, 0xFEF824CB, 0xDCAF40CF, 0x673DA569, 0x9D8C6581, 0xCAD82A6B, 0xA4010123} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xEA08AF0B, 0xC4612660, 0x0345AEE9, 0x4D25626F, 0x61937472, 0xAF7BB691, 0xD7746B41, 0xAC3EA041},
	{0x26AB2A16, 0x47B7ADDE, 0xE89F45E5, 0xB2C8EE53, 0xB97B536D, 0x3FD07464, 0x393FB86A, 0x4F4C6833} } ,
	 { {0x8E24759E, 0x25E25F24, 0x2DC3E7F9, 0x7F75DC5B, 0x75CCE223, 0x89822B1D, 0x96C3CA19, 0x26FC1209},
	{0xE678EB25, 0x321FF93C, 0x144DE98D, 0xAC178823, 0x707D7F88, 0x5C8C1BB4, 0x1A16A3F5, 0x3EBDFF45} } ,
	 { {0x242F2A5B, 0xCF9F1BC9, 0xFE6FEC70, 0xC4C9BB33, 0x7B99B77C, 0x24FCC87A, 0x86C13C5C, 0xA1663B33},
	{0x6DD596EE, 0x993EAF59, 0x4552A4AD, 0x73CF1B4A, 0xC4E62349, 0x6F94529E, 0x550842A6, 0x3F2F8FEA} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5039 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5040 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5041 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5042 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5043 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5044 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5045 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xE74287EB, 0xB5F616A4, 0x41FB9294, 0x48B91993, 0x9B93327A, 0x51A0A1FF, 0xE8D88D91, 0x376CA165},
	{0x8FA7EF2B, 0x0F262FFC, 0x8D43873D, 0xF45C6C8D, 0x14EC5C63, 0x12A3CEF6, 0xA5015352, 0xA944CB8B} } ,
	 { {0x4E640095, 0x77EBE87D, 0x39593B2E, 0xD8DCD8AE, 0xD4BF7904, 0x25CB1600, 0xD7C128F2, 0x4B7F6F07},
	{0x4BB998A1, 0x97217735, 0x315A8719, 0x3F0DD1B0, 0xBB0DA25E, 0xAF624E7A, 0xE7AEAADB, 0x91FB0B57} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE5D4574F, 0x6C44B8E8, 0xFF12D465, 0x29197864, 0x23F50D4C, 0xEE56376B, 0x02C2211A, 0x312B330B},
	{0x40F99121, 0xDFDC915E, 0xB7053518, 0xED61E043, 0xB6021FD0, 0x2ECF055F, 0xE6C65977, 0x08221E6F} } ,
	 { {0xBF5F6016, 0xCE00BF2D, 0x9090FE55, 0x1F129A4F, 0x24A591A1, 0xF6F7B588, 0x983D6D7B, 0x6161E1F5},
	{0xC753B214, 0xC2C5076C, 0xAB7ECF4B, 0x1340B328, 0xB2A8EB1D, 0xD7546729, 0x53E0854A, 0x4DE5DE9F} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xEEBF9E1B, 0x5526ECC6, 0x1809B010, 0x7D2C9360, 0xCD52F3F5, 0xDAE21AB1, 0xDA9664D1, 0x112B1BC0},
	{0x93A11F9E, 0xD131C29D, 0xC3FD9C03, 0x8A800CD4, 0x0E258894, 0x5328DB21, 0xEE2C4E33, 0x09B9CBB0} } ,
	 { {0x9AD6612D, 0x2AFE0708, 0xE5FEECBC, 0x03BC8CF3, 0xA8397C16, 0xB1AA15D7, 0x09042610, 0x2FFC95CF},
	{0x046F3C9E, 0x7FB47FE7, 0xB81B0B15, 0x70F40388, 0xB7140A82, 0xE2B13A84, 0x132A6838, 0x7BA3A30E} } ,
	 { {0x60BE03FF, 0xB53D2BF5, 0x918F2117, 0xF3720B72, 0xDC446486, 0x9815F1D6, 0x5A086FB2, 0xB3D23067},
	{0x137DD691, 0xCFA4EB13, 0xFE398D22, 0x0C172056, 0xF4F84D22, 0x178B92D4, 0x81E3E24E, 0x18F0F1A6} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5046 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5047 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5048 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5049 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5050 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5051 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5052 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1C16EA02, 0xBF50FC4A, 0xD897842E, 0x45CA2F87, 0x53DECF1B, 0x113A64E5, 0xE85BC81D, 0x41607629},
	{0x9035A962, 0xC7DA9B4C, 0xEC35FF5D, 0x4D19B8CA, 0x5BA81C4A, 0x312E3725, 0xBA95348E, 0x04292946} } ,
	 { {0x172287BF, 0x64185F74, 0xD44ECAFF, 0xEC759D11, 0x23240FBB, 0x38E0832A, 0x2EF0D60C, 0x4F4AC638},
	{0x5DBB0DF7, 0x188FF7C8, 0x974328A0, 0x6C5F3720, 0x00342BB1, 0x63F7D412, 0x510CDEB6, 0xAD79480C} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC0B9F7F7, 0xD69D49E4, 0xF3158F2B, 0x09CC8575, 0x2F87A616, 0x5B1D1343, 0x9FB86487, 0x7953CF73},
	{0xA6247E67, 0xDC7F29B7, 0x975E1041, 0xA86876AA, 0x4A319250, 0x02DD95D6, 0xE346A55D, 0x2C746F09} } ,
	 { {0xBBDA35BE, 0x4BFB54B3, 0x70DED4FB, 0xC02DEEB5, 0x9B39A6A4, 0x484482D0, 0xBC5BE676, 0x22F87288},
	{0x17CC8EA6, 0xDCB30966, 0x40811476, 0xB33A048A, 0x5ACBB926, 0xF09DDB9E, 0x868CF1F5, 0xA6A95EDF} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x9C86B60E, 0x624AAC55, 0x3E308075, 0x0406B750, 0x06D66267, 0xA8984230, 0x9C66D6A7, 0x766B6B36},
	{0x3419EE69, 0xEA59C46F, 0x4BF17143, 0x2DCC2FD3, 0x77AA3353, 0x9178C5CD, 0x5980A626, 0x23B1558E} } ,
	 { {0x821E97E4, 0xC960A966, 0x8452CD85, 0x7B2C59C5, 0xCA11B461, 0xAE075C21, 0xE37CF1C9, 0x9D0080FB},
	{0x0B3B5294, 0xCCF5B9AB, 0xF2E6FC4A, 0x1597CB82, 0xDE8032B5, 0x78EA2A36, 0x14447D8F, 0x193A364E} } ,
	 { {0xA4A30DF5, 0x174C4D9A, 0x1A7E0AFD, 0xC40255EE, 0xDBA8D6FA, 0x49E2AE5D, 0xB75C9C6A, 0x37F35949},
	{0x15EED505, 0x14A48E6B, 0xAB2810E4, 0x5B4EBDDF, 0xEE897606, 0xD1AF5EB0, 0x28B170CE, 0x284B45C3} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5053 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5054 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5055 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5056 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5057 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5058 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5059 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF9EB40D7, 0x756EC87F, 0x9839FE71, 0x7C029C59, 0x4C0368BC, 0xDE17B300, 0x7E3BA9F3, 0x2E9A3F9F},
	{0xC4CCEAE5, 0x02D01C5B, 0x3999DD36, 0xBAB52879, 0xA5762ACA, 0x79B82829, 0xDB32F940, 0x1FE4B4BF} } ,
	 { {0xA6DCC8AC, 0x63E55C9D, 0x3865CF43, 0xA538CA4D, 0x6415FB4E, 0x568AD994, 0xF1229DB4, 0x3238EFE2},
	{0xCB6F707B, 0xB1E1D1F3, 0x0F52ACFC, 0xFE279027, 0x08F74FCF, 0x8A25C730, 0x2283A36D, 0x115C1D79} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x8FA6CCFF, 0x661AA114, 0xE952320D, 0x903719F6, 0x67C2FBB8, 0x3BC74452, 0xA67FB434, 0x24E0D3A8},
	{0xE6D5D93E, 0x52FB7CD0, 0x1470777D, 0x18505026, 0x1FC985E6, 0x1C16EF22, 0x1F049848, 0x4B7CE520} } ,
	 { {0x14A0C34B, 0x73F37715, 0xDF75BFD6, 0xBA0CB64C, 0x0632FFDA, 0x94E2FF95, 0xA82E305C, 0x6809E40F},
	{0x9C62A370, 0xFB67E9A9, 0x8F981273, 0xDF84B059, 0xDE7FD8BA, 0x5471D546, 0xEC9426ED, 0x9E0627E5} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA97249A9, 0xF145B7CF, 0x4CD6F3E6, 0x081BA1DC, 0x536CCBBE, 0xACE79797, 0xBCFB686C, 0x4CF2B8B1},
	{0xD1BB4842, 0xF94F02DE, 0xE4F4578B, 0xE035FCD3, 0xC53BC69E, 0xD1E4611B, 0x7251A8DA, 0xA23A5A80} } ,
	 { {0x948DFDAB, 0x378B0AE0, 0x5C3E053C, 0xEC7069A7, 0x6ECB4C68, 0xBA54D365, 0x0A065A33, 0xB6C3BCCD},
	{0xE0A7FD1B, 0x0822B7C5, 0xF853A080, 0x312ED391, 0x6A6A582D, 0x0CDDE8DF, 0x51E05A2B, 0x477DE084} } ,
	 { {0xF7E7C0C3, 0xEF9A6245, 0x259012E2, 0x27462A3E, 0x6FA21CB1, 0x590FEDBD, 0x6862E669, 0xB05A32CB},
	{0x2208EE59, 0x502B6075, 0xDAD69A47, 0x5D9B27AC, 0x7A535B1B, 0xA25EC6F8, 0x43D19F07, 0x2B983060} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5060 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5061 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5062 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5063 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5064 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5065 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5066 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1FFD81ED, 0x61478F69, 0x8B8BD83F, 0xB78EC450, 0x5175D926, 0xDEC5BCBB, 0xE88B28FB, 0x7B60849D},
	{0x343949E3, 0xFE342EFD, 0xFD43EE5E, 0x3876CB0A, 0x0B84DCBC, 0x57BEBD85, 0xBBA2F409, 0x8B80E60C} } ,
	 { {0x1EF3A024, 0xAAC98CFD, 0xAC1EF24E, 0xB10DBAB0, 0x1B950B70, 0x28962689, 0xFEE347B1, 0x498181F2},
	{0x96A86A1C, 0xE5EE145D, 0x3BD2346C, 0xF2B0E2DA, 0xF1A2112B, 0xB307F7F7, 0x2B2BB358, 0x14FACB23} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE68D202B, 0xF54B1429, 0x3EAC5E49, 0x438250DC, 0x72DB92E5, 0x2ECCE94B, 0x020439A0, 0xB9018872},
	{0x1C37F080, 0xAAB80A96, 0x0972F6BF, 0x85593CA2, 0x3FD63FCB, 0x45AEB500, 0x36C19531, 0x9E6335BF} } ,
	 { {0x470353EE, 0xB69A5CF1, 0x1FCB7A0D, 0x10AE5B30, 0x5628A807, 0x55789BA4, 0x54377F3D, 0x4A2F7934},
	{0xFD26A3F8, 0xFF6ED53F, 0xC3A9B356, 0x058024B1, 0xE39F1B57, 0x1473ABB3, 0x534C396F, 0x8C14ECA1} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xCBDFD900, 0xC8A09417, 0x8510F973, 0x5264F89C, 0x8DF49AE2, 0x8BAEF0FF, 0x1E3AA567, 0x4BCAD98F},
	{0xD3AC4442, 0xC6DF0DB9, 0xB3752D9C, 0x6FA5D132, 0x439117E9, 0x31251446, 0xE482A20B, 0xA1AF7DA2} } ,
	 { {0x3DE99DBB, 0x354A5667, 0xE43952DA, 0x3271C24F, 0x15E02381, 0x07B86672, 0xD2B2E595, 0x24CEC6C6},
	{0x79ED59A8, 0xC274C867, 0x2D9F228A, 0xAD8B34CE, 0xA8F9656C, 0xB64AAD62, 0xD51E52D5, 0xB09C8A33} } ,
	 { {0xC68F9E3E, 0x940384C0, 0xB320860A, 0x8BF38C8B, 0x2165B9BE, 0x50072C90, 0x197910A4, 0x3DA103D4},
	{0xE7FEA69D, 0xAC83DB98, 0x0C2F0860, 0x4CE27197, 0x3451630F, 0xEDEFF77B, 0x7B1EA127, 0x12E24FB2} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5067 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5068 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5069 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5070 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5071 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5072 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5073 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8F2A75B4, 0x3621D2B0, 0x77FCBD02, 0xE9208AF7, 0x8B832509, 0xF92783C2, 0x571555B4, 0x0A076DF4},
	{0x25CBFC18, 0x541D48CE, 0x45F08E37, 0xB216EAE1, 0xAA76B747, 0x14D68859, 0x2E3D28EF, 0xB2BB35F6} } ,
	 { {0x269CB579, 0x9A7D8A66, 0x154FA37A, 0x25CE04F7, 0x9C713942, 0x8716E64A, 0x546F970B, 0x0D293AEB},
	{0xA797CA88, 0x09708D3F, 0xE7BBFB03, 0xE8F66994, 0x855C0AE4, 0xF1EF050B, 0xD9684D3D, 0x4D52DE56} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x192403F5, 0xD6BACD36, 0x43E1F941, 0x9931C228, 0x3D59FE2E, 0x1915F2A9, 0xCDD39C85, 0x7F60520D},
	{0xB9A3A15B, 0xFCA13257, 0x7B46F41F, 0x502D3B49, 0x325066F6, 0x6FEA721A, 0x8C0EB561, 0x19B36FA5} } ,
	 { {0xE4D6B710, 0xDF9EF20C, 0x965AFE60, 0x9A1FE639, 0x1743C5B2, 0xEE3B5B9E, 0x094476C9, 0x65DFAE4F},
	{0xC73CFF90, 0xCD1CCB2B, 0xF95201AD, 0x1D331B61, 0x0B88D162, 0xC67B0349, 0xDBAAE6B6, 0x9CF5DBB4} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xBF738050, 0x5436CF4A, 0x3F45D6F2, 0xDC1ECF25, 0x079F8413, 0x8D1B77E1, 0xD542524F, 0x721E18BE},
	{0xC93C6F8C, 0x7B168444, 0xAB71CCB8, 0x89BC83BB, 0x48D6B9D4, 0xA9DA9D2A, 0xB3DB5CE1, 0x40076709} } ,
	 { {0x28119167, 0x0939B454, 0x156834FF, 0xDF24CCB5, 0xA5B55908, 0x4466734C, 0x20B50B59, 0x203F6993},
	{0x55B7C381, 0x5A3EE27F, 0xE219593A, 0x5CE96519, 0x8943E571, 0x6F31653F, 0x8C432744, 0xB7F3C779} } ,
	 { {0x89F98E41, 0xA098FA85, 0xCBE53C3F, 0xB0113730, 0xB1D6D924, 0x1FEE6EE6, 0x76BE46D0, 0x7558E419},
	{0xF603D9DE, 0xA772733A, 0x09CE452F, 0xB127FD09, 0xDBBC3963, 0x5674462B, 0x9DF0689B, 0x210BD871} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5074 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5075 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5076 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5077 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5078 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5079 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5080 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x7B887852, 0xAD873B27, 0x562191C1, 0xD51C49DE, 0x20A83BDE, 0x4FF27306, 0x8E6AE2DA, 0x7EDBB960},
	{0xF159D9F9, 0x3312E3AE, 0xD2B398B6, 0x7EABAC67, 0x2578E6A2, 0x48726708, 0x916A656B, 0x21688F04} } ,
	 { {0x2A30550A, 0x945CD130, 0x906E4A67, 0x300A180A, 0xD7B0F21F, 0xD8977E50, 0x22471E73, 0x8856B721},
	{0xA90170AE, 0x696E5AD5, 0x8F8E5F3D, 0x496212EC, 0x6B2BFD2C, 0x5C88D9B1, 0x99392029, 0x59780249} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFEC5BFA7, 0x3DEC3301, 0x241DC38A, 0x272039D5, 0x5711CE9A, 0xF604201C, 0x9A8FA722, 0x9323C294},
	{0x794D966B, 0x88E39C97, 0x86D2EA46, 0xD786C42F, 0xB05026A8, 0x4DE562BD, 0xB281B374, 0x5FA62C33} } ,
	 { {0x983F22BF, 0x8F55230C, 0xFE0221E2, 0x5F684497, 0x1872BFDE, 0x0E791CDF, 0x8BA44067, 0x68AB9BDD},
	{0x48FBF567, 0xEDA56313, 0xECE58D50, 0xAD8E53B0, 0x4EDAD478, 0x8D65A499, 0xFFAD880A, 0x24B37C96} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x1F0968AD, 0x571B115A, 0xBC7D42A9, 0x14DCF04D, 0x5916597A, 0x68D46BD1, 0xFE24FD8E, 0x6849F8A7},
	{0x51E85B2C, 0x4A7F6102, 0xE4CA50B4, 0xBFAC3897, 0x815CDF0B, 0x964239EA, 0x1523E61D, 0x4135BF41} } ,
	 { {0x273E6FDF, 0x3AD06BD8, 0x5F851773, 0x1B21731A, 0x29EDA598, 0x23E1B981, 0xFC1184DD, 0x74FB309D},
	{0x9A82250A, 0xDCA7F5C8, 0x96B4429B, 0xEB42A066, 0xCD1B3905, 0x722D9A58, 0x83960FC4, 0x7A561B48} } ,
	 { {0x833D4755, 0x9064F7DA, 0xCDFC31C8, 0x5203EFF6, 0x366992BB, 0xA611AD16, 0x0C24C448, 0x14480934},
	{0x87F3BC72, 0x55D0B8E8, 0xB41F5190, 0x58DB17C7, 0x8AD74006, 0x0572FBB5, 0x21174E09, 0x3E3D9D2F} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5081 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5082 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5083 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5084 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5085 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5086 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5087 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF46F0540, 0x6134B363, 0x0C834FF8, 0x1D5D5B0F, 0xF0E97446, 0x0EBAD400, 0x8CFDDA90, 0x3EB24DAE},
	{0x61A862AA, 0x7B372B09, 0x5C61544E, 0x627EFB8B, 0xCDD5CBBA, 0xA0E4DD1E, 0xBD957EAF, 0x1D82F839} } ,
	 { {0xD8E247AD, 0x3702D2F3, 0x2C2EE1FC, 0xDB5369A4, 0x630BCB79, 0x030617C2, 0x0183EE37, 0x82FAE220},
	{0x989BADB5, 0xCD7C73EB, 0xCBDEA14A, 0x6A6687BB, 0xA5A1027B, 0x13B95B0F, 0x216D5438, 0x551CCC31} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF85D5099, 0x56509B8C, 0x0C553712, 0x98586B2E, 0x936537E6, 0xAA59100B, 0x04624F55, 0x352EDE4D},
	{0x30F742BF, 0xF1693CAA, 0x9E5C45DF, 0x28417AE7, 0x97FCE13F, 0xB8F93279, 0x566C1007, 0x477A3964} } ,
	 { {0x5F5F2C73, 0x91C79E0E, 0xB1365944, 0xE69B9437, 0x1A92227F, 0xD688B6E4, 0x4591DCEC, 0x6483035C},
	{0x93C2B77E, 0xCCB75648, 0x9AEF282B, 0xA46F77E1, 0x01DE87FD, 0x26145B4E, 0x095CE5F7, 0x517F8419} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA5879EA7, 0x1EF5DC81, 0x5C277278, 0x6E6312C8, 0x6B82CFD0, 0x4EC0EEE1, 0x629C14B1, 0x11FDF28E},
	{0xB539AA8F, 0x0D632D1A, 0x770BFEFC, 0x36E2F340, 0x34D8635C, 0xDDC073E0, 0xF721D038, 0x6E3AD3A6} } ,
	 { {0x8460F953, 0x8FBB9417, 0x96B23425, 0xA0C97CE7, 0x732CFC9A, 0xFFA23EFC, 0xD39D0FCD, 0x34AA9157},
	{0xA756839B, 0x0B06F2F4, 0xDBDE7008, 0x3CDD60AB, 0x1BC9B2E1, 0xB3A5EB58, 0xDF2A021C, 0x3BA97EA1} } ,
	 { {0x661A7FF4, 0xF40A71DA, 0xD449C660, 0x8E0CBCBF, 0xF65E4D55, 0x96FE9875, 0xB78350EE, 0xB0902F60},
	{0xCF4EE015, 0x763211A0, 0x41FAF191, 0xC5C27F5C, 0xCA271584, 0x1814555A, 0x98D69158, 0x29F7412A} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5088 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5089 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5090 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5091 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5092 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5093 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5094 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x072BADAB, 0x4551A510, 0x75A725A0, 0x882F7B6A, 0xDB98EE8E, 0x7A1F9FD7, 0x145A4ED6, 0x5887D3C3},
	{0x6F11CC19, 0x33C3051A, 0x2641D611, 0x440ED4A8, 0x834EFFED, 0xA8942D21, 0xBA458FEA, 0x66F79C99} } ,
	 { {0xA8E49C11, 0xBC02C738, 0x6B2B9BEC, 0x6E4313E3, 0x4ED8EE3C, 0x9B949BB7, 0xB085177A, 0x0BDF2F89},
	{0x14B96BCF, 0x48A362A0, 0x639A37FA, 0xB70F7BE4, 0xBA630E5E, 0x5C5343E8, 0x2331C290, 0x3EB82C36} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x08F5A42D, 0x7E23949F, 0x8099B0C2, 0x575274A1, 0x8022F358, 0x56C01070, 0x8C63D629, 0x8B7D1449},
	{0x1CC1829B, 0xB8F4C7A0, 0xC3C5A3B6, 0xE05EFED0, 0x7DC1B60F, 0xF5DE17A7, 0xEE3F46D6, 0x8A8C8B4D} } ,
	 { {0x088BD6E3, 0x32DC4037, 0x6BA41EDD, 0xCE5DA3E9, 0xDDCEDFDF, 0x453BA5B6, 0x428C275A, 0x26059928},
	{0x65C3C3F1, 0x7810932C, 0xC1F16AC6, 0x0525E756, 0x228FF513, 0xAFEE4D2D, 0x6E5D5FF1, 0x700EDF93} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8F01E0E1, 0xD349A39E, 0xC10FD271, 0x4A7DD538, 0xD5BF84B2, 0x2806C78B, 0xB1D82B8B, 0x28D91E43},
	{0xC8B4F305, 0x23A4E690, 0x0E46A6CE, 0x46B36EDC, 0x8988A034, 0xB9D93F9E, 0xDA922D25, 0x1DABDF05} } ,
	 { {0xB594103B, 0x66E4A6F1, 0xE4DCAE1A, 0x74560EE5, 0xEE45DF84, 0x0D35F3B2, 0xB2053920, 0x2776C16E},
	{0x724D28F2, 0x73CB75FC, 0x02F3DCAD, 0xCDEBA694, 0xB7A9BDFB, 0x3D38DBFA, 0xC1CD71DE, 0x68DF7F8A} } ,
	 { {0x01C9F682, 0x38D1EF8F, 0x0AF28B22, 0xCF22F937, 0xA48A04C9, 0xDCA07098, 0x78098752, 0x32F54086},
	{0xADAFB682, 0x8531C285, 0x9D83CDA5, 0x9C502A28, 0xFA72B622, 0x4D49EA85, 0x33F9B6EC, 0x2394EEB4} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5095 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5096 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5097 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5098 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5099 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5100 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5101 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xE1639F45, 0x4E88EC1D, 0x22A018E5, 0x3095F9FF, 0x8497BC25, 0x0DF4FDEF, 0xAF850DD3, 0xB1DE329D},
	{0xDB81E527, 0x592F7DDE, 0x054C00F7, 0x229F1F4E, 0x5C52A267, 0xE36905F1, 0xB985C9AD, 0x87C0C704} } ,
	 { {0x4F1C0DC0, 0x6017EEF7, 0x524010A3, 0xFD83BB8D, 0x07F7F14D, 0x11873534, 0xB4181344, 0x42D491ED},
	{0x599F5AFE, 0x511C6420, 0xA2B39978, 0xBF2F6E74, 0x40E991A1, 0xEBBE9C0A, 0xE64D84C9, 0x1008ADB4} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF7357434, 0xABF2A1B3, 0x3930C116, 0x565B9DED, 0x56E682D5, 0x120B4C53, 0xBA04E5A3, 0xA733D8E8},
	{0xA75355E4, 0x7B00F38A, 0x00D161A0, 0x406A192F, 0x572C924C, 0x7ABDC180, 0xA13DA2F4, 0xAE52696B} } ,
	 { {0xBE5F3456, 0x6BFA3D75, 0xD85EA769, 0x459A3E7F, 0x09409DD7, 0x94764A38, 0x878B50A1, 0x47C34F94},
	{0xDAA1F860, 0x8E127BC6, 0x5721771A, 0xEC57197B, 0x00A5C820, 0x0C40B69B, 0x7048413C, 0x4DE2904E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x4A7E0F5C, 0x78B88987, 0xEE105C32, 0x42CFFC5C, 0xC89CFDBC, 0xAE3631A9, 0x897367BB, 0x708208DC},
	{0xBA72DCC1, 0x077B0190, 0x230AE667, 0xE0484ED2, 0x96C03603, 0xEE094B29, 0x53D01C44, 0x15EA3B3C} } ,
	 { {0x0BDE1CCA, 0x0B15C309, 0x5FBDDF80, 0x3BE495B2, 0x03DE827D, 0x2463C628, 0x00C1F2B2, 0xB59CDF35},
	{0xDB1F4EE0, 0x9DBE9657, 0x05D24980, 0x6A903409, 0x9B651EC5, 0xADFF5962, 0x99DD77B3, 0x33C5A2B2} } ,
	 { {0x77FE098A, 0x5C583F47, 0xEB088778, 0x38D7508E, 0x26315065, 0xFF76AACF, 0x4A9EB3F8, 0xAF69450D},
	{0xCBD170BD, 0x21D175AB, 0xFB8560A9, 0x1DCAF9E0, 0xFAD9EFE5, 0x9754BB8E, 0xE7B7D946, 0x2691A266} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5102 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5103 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5104 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5105 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5106 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5107 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5108 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5D663E79, 0x73C9E394, 0xF2B7599E, 0xDC7784B5, 0x256B1107, 0x32D21C9C, 0x632986A8, 0x052A4E33},
	{0xE8CEA0A3, 0x73EF52FE, 0x2BBECEC3, 0x5385D54B, 0xACC95139, 0x13F51E1C, 0x0A732D57, 0x687A4049} } ,
	 { {0x86A59B3B, 0x06FFE8FC, 0xD5009248, 0x75E05116, 0x8D03EEDE, 0x3BAD7CC6, 0x519BB7B7, 0x21EB0CFE},
	{0x4FE7A099, 0x111FF235, 0x4A686736, 0x2D8013D2, 0xD50C0684, 0x34B8A3A8, 0xD788AAC2, 0x273DA58E} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2A7A174C, 0x86430D6C, 0x76D94309, 0x389B4FBD, 0x21A387B1, 0xB76574F7, 0x57637127, 0x90E55E30},
	{0xEC2B2E4D, 0xEF5FDC43, 0x9EC689B6, 0x5459F0F1, 0xBDD4E52B, 0xEE07F53D, 0xBEE6DE3E, 0xA346115E} } ,
	 { {0xE0AC4065, 0xF6D2B4FC, 0x6240BB42, 0xBAAB682C, 0xDB359915, 0x2C08876D, 0x2CDAC658, 0x15978BB1},
	{0xED630C18, 0x4A259901, 0xE6732223, 0x4327D7C1, 0x9E089BAB, 0x92A882B9, 0xDDAD7EBE, 0xB39DC7A5} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xF2A2F142, 0xCEC369AB, 0x8DF7B918, 0x809E4B96, 0xC3BE30A0, 0x2281B823, 0xBEA9C8AF, 0x55BB8F10},
	{0x5D578632, 0x0E362FBE, 0x4273DA87, 0x7D47A7F9, 0x5D2FCCF5, 0x54AC9C53, 0x81EF943A, 0xB739BECE} } ,
	 { {0x8AE6C29E, 0x5AA532B4, 0x78822314, 0xE0450085, 0x10FC020A, 0x4A6E4E21, 0x1383C366, 0x44D5C34A},
	{0xF7DCC7A3, 0xFCECC799, 0x882877D5, 0x16F61BF6, 0x158CF3B1, 0x74084F96, 0x4DEAABA1, 0x0FF3B91A} } ,
	 { {0xCD13D8D3, 0x127929D7, 0x8421E96B, 0x5C23CB07, 0xFC3876A9, 0x8493585A, 0xF439EA7F, 0x8BBB0FFC},
	{0x035C8DAA, 0x7B708945, 0x7307BAF3, 0x00D41BA6, 0x110B93F2, 0xDA12D721, 0xB473B0E7, 0x3ACBD115} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5109 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5110 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5111 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5112 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5113 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5114 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5115 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xBC25FF5D, 0x776B0642, 0xC8E0BCE7, 0x7E7683EB, 0x62F2DC21, 0xD3701C8A, 0x1554EC12, 0x5BEF6E8A},
	{0x16DA31B0, 0x7A1808F6, 0x3D7A3917, 0x18D79987, 0x14CEFD94, 0xD5352B22, 0xA51A1157, 0x26A558C7} } ,
	 { {0xC9EA388F, 0x36A71B69, 0x8B1BC502, 0x01C7A929, 0x8F6E9716, 0x38A42F05, 0xBE33B0CA, 0x99CB7E72},
	{0x82325B15, 0x8CD679CB, 0xDEACBD28, 0xAE7053EA, 0x593ACA0A, 0x694B454D, 0xFAEFED8F, 0x51CF8E30} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xECC9F231, 0x0DA63C30, 0x5E5D4954, 0xC959C8E7, 0xBE828023, 0x4EE5C432, 0xDE45776A, 0x9B81B014},
	{0x21FE5A6B, 0xA58E15CA, 0x122AC5F4, 0xD6A5F1C1, 0x89BB52BA, 0x6BCF7FE1, 0x4824B8DC, 0xAC1DA024} } ,
	 { {0x12F28EB5, 0x4E2B874D, 0x4FFCD256, 0x5C7AC159, 0xD02C4190, 0x69DB8DE0, 0x6653EDA8, 0xB10FB59D},
	{0xC7227D6E, 0xEECF6B58, 0x15D82F8E, 0x45222A0B, 0x3EE92F31, 0x56A1B24C, 0xF7027561, 0x274DC90E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xAA7FD7BA, 0xDC4744F0, 0xB43920DB, 0x757FA5E3, 0xE2AF0D32, 0xBA079FAD, 0xC69E0625, 0x41558A72},
	{0x571919C3, 0x041DE03C, 0xA928B0DE, 0xC1F0CA35, 0xB8AAADA7, 0x9077A726, 0x21B735BE, 0xB639260B} } ,
	 { {0xA7E9C049, 0xBB633461, 0x5907EF76, 0xEB1AEC61, 0xBB2FCF5C, 0x74BFDECC, 0x3541E7F4, 0x2C9F08F1},
	{0x83BA27C4, 0x574829D0, 0x39B9ED15, 0x6616F3A4, 0x035D9DA4, 0x2D96FEA5, 0x95308313, 0xB1503BF4} } ,
	 { {0x30A3F2D4, 0x963B35EE, 0x957C8C6C, 0x4AE344FB, 0x5B8FA402, 0x7B75A7A8, 0xC8F08B57, 0x3F92418A},
	{0x0B2428BB, 0x2B760CD4, 0xD4B08CDD, 0xBDCE5839, 0x74EC5526, 0x969A54BF, 0xA30AA784, 0x8578475C} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5116 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5117 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5118 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5119 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5120 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5121 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5122 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x54BD50EF, 0x2DBAF1C4, 0x9C10F83C, 0x6C1D2B39, 0x15AD6417, 0x565B2FDC, 0xD4CAD3D5, 0x1C70AD0C},
	{0x8F29A1AE, 0xAC32A03D, 0x5444696E, 0xAB16509F, 0xDB60D654, 0x94B8868F, 0xC735833E, 0x79517B77} } ,
	 { {0x1A73E78B, 0x6302DB90, 0x983B0AD7, 0x479804CE, 0xD36800D0, 0x61288A9F, 0xF3D88E87, 0xB11E2E0A},
	{0xB9AD440F, 0x17B8F7C8, 0x4EEA546C, 0xDA7CAB99, 0xED571177, 0xD3ACFACE, 0x1861E668, 0x15AAEAD0} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC5B78F93, 0xAF8FBF83, 0x17F40D6F, 0xE02C035D, 0x13C47544, 0xB6ADAE7D, 0x6FC85434, 0x8735F56A},
	{0x7EAD4DE0, 0x29F8F2B0, 0x0573A436, 0xF03E9B34, 0x141463F4, 0x14CEA09E, 0x9CAB1AAE, 0x507404B4} } ,
	 { {0xAA5E8489, 0xB83ACFEE, 0x72B745E7, 0x589F5AD4, 0xE83DBCB2, 0xCAE5A53F, 0xB8150489, 0xAF57AA19},
	{0xD33151CA, 0x016592C9, 0x97859399, 0xD4394356, 0xA384B6FC, 0xCD39F27F, 0x4DF3B6E8, 0x92ADFA5E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x91FB3C13, 0x297C3F0B, 0x55352941, 0x0FB60DC8, 0xE8E8586D, 0x0F947BDF, 0x407192DA, 0x8DDA09E1},
	{0xF8BE4992, 0x9395268C, 0x16089A5D, 0xA125E5F3, 0x0C319D11, 0xB8DE47B0, 0x6E242A5B, 0x400151EE} } ,
	 { {0xCC2AD17A, 0x08F0903F, 0x5F86738B, 0x37693871, 0x10A87DDD, 0x6F9B6949, 0x8A9865B5, 0x66DFDE1F},
	{0x5AF44268, 0xAA99D04F, 0x8C796D78, 0xDD98192E, 0xCA08E240, 0x8D01029A, 0x1D76C759, 0x8C210805} } ,
	 { {0x70FA3EA4, 0x81D4CDBF, 0x7BE31533, 0x740ED823, 0xFE17112D, 0x60527EA0, 0x9AFD805F, 0x6AC5485D},
	{0x51AFE0CD, 0x7CB4DC24, 0x85A71A0E, 0x5839F735, 0x8C961755, 0x7B767679, 0x15947398, 0x913627FF} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5123 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5124 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5125 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5126 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5127 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5128 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5129 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xDC4F9776, 0xD4F88B25, 0x91DE6D9E, 0x2543F5D6, 0xE875B5B4, 0x071F1C86, 0x9425C70E, 0xB1BB3E14},
	{0xF5234280, 0x47E469A8, 0xC9975C5E, 0x6C01A110, 0xF7180FB9, 0xB79644DB, 0x33351C22, 0x56FB0D23} } ,
	 { {0xDD52AE8B, 0x854E357D, 0x9589B8C8, 0x94B5D22E, 0x407EC3B0, 0xD0D05257, 0x68BFA7E8, 0x95605DD3},
	{0x270FED81, 0xC2D5193C, 0x093C2713, 0x190FA125, 0x21C3CD11, 0x5CE5ABEA, 0x90370172, 0x7031728C} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC6A43967, 0xC8E5A8E4, 0xE1FEE01F, 0xADC70814, 0x9F7D5C30, 0x9F61664F, 0x01BE91B0, 0x85FE42F8},
	{0xCA9855EA, 0xEB3E5696, 0x71152CCA, 0x1F8BF668, 0x4B3941CE, 0xC0A538D1, 0x7F88E2B9, 0xB1DD7535} } ,
	 { {0x7BC18BA9, 0x718525DE, 0x051AEA3A, 0xE264C209, 0x3A90BDEE, 0xFB02AF68, 0xACCEB9D7, 0x05B463F0},
	{0x27E382F5, 0xF81D24F7, 0x7EA65334, 0x85C09F26, 0x2EB4258A, 0x520F2575, 0xAC004EFC, 0x139AFE51} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x437C5BBB, 0x1C4C991C, 0xC2038EBF, 0xFBEFE71C, 0x28E34851, 0x8D82E3F1, 0x977E0D9F, 0x37F8FA35},
	{0x462C9E8B, 0xC2D5D0BA, 0x7EFC021B, 0x089EA0B1, 0xFB4AEB0A, 0x800FA8A7, 0x101C089B, 0x5109FD91} } ,
	 { {0x9B36C419, 0xE491D8CE, 0x8FEE4941, 0x2CDB80CB, 0xDCFCCA5F, 0xADCB728A, 0xFF170DCB, 0x4429CE3C},
	{0xDDCB9234, 0x0B20E572, 0xAE3D7C02, 0x3C8D2B75, 0xA1BE1918, 0xC1B5D8FD, 0x5B9B771E, 0x6D6F0603} } ,
	 { {0x4C80D68C, 0xF2DBA770, 0x249851C7, 0x9B94BEDF, 0x0AEA3031, 0x93A2A634, 0xADB7A6CB, 0x8E56A3A5},
	{0xD575136A, 0xA359ECED, 0xA77DD06C, 0xB38A5557, 0x54213214, 0x090EF3F5, 0x4C53C697, 0x5AE26812} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5130 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5131 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5132 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5133 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5134 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5135 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5136 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x0663F917, 0x7BDA4F39, 0xDFD69D89, 0xAEF9BC10, 0x2843FD9C, 0xD2E6A3CF, 0xCBCE5F59, 0x4E9FECEC},
	{0x1DA8BDF1, 0x2EB2D6D4, 0xB7BD06A4, 0x276A9710, 0x91DB16A0, 0xC0D3B7B5, 0xABC9D3F1, 0xB177FC4F} } ,
	 { {0x9B80135B, 0x4665780F, 0x41CD7A25, 0xED38DD8A, 0x299D1BEF, 0x6AAF30B9, 0xB9E0FF8A, 0x0791B01A},
	{0x1C8B2286, 0x0931E310, 0x22BF2F30, 0x6F2EA51E, 0x6AF5A4CB, 0xA9DE69CC, 0xEEC597DB, 0x863F3B37} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFF9380CB, 0x8C0C3A0D, 0x457CDC34, 0x57C33745, 0x492CCFBF, 0x545229FB, 0xA9E40490, 0x898CC1B9},
	{0x95357911, 0x24234E16, 0x45F73EC7, 0x69D5E696, 0x42E72CFA, 0xF124D841, 0x4E64D78B, 0x6794ED4A} } ,
	 { {0xA1375EDF, 0xEDA4E499, 0x9266B9E8, 0xA3C872A9, 0xEE50C97C, 0xF4F08A61, 0x3095FD66, 0x93994557},
	{0xB5668E38, 0xC871DC2E, 0x66F3A860, 0x4374558D, 0xE69FC483, 0xE559C9AF, 0xDB19B354, 0xB040BA27} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x2A0D6BD7, 0x653447C8, 0x80C2CA49, 0x045150E0, 0x67E70FCC, 0x2D0D461B, 0xCEAC4D71, 0x1FE6FB7D},
	{0xC80044D2, 0x7C7E0687, 0x30A1DD5A, 0x1718B2B9, 0x0CFE3DF5, 0x090F147B, 0xC3F024F6, 0x40882698} } ,
	 { {0x8BCF4548, 0x7FA1EEEA, 0x4F1BDDA3, 0x8C3B62D1, 0x82AD859B, 0x236D6F45, 0xB526FEB0, 0x8CFD8B30},
	{0xE3EC60A3, 0x1E087E4A, 0xE0967020, 0x56D1B36C, 0xBF531EC8, 0xE1819C13, 0xA7044132, 0x5935717D} } ,
	 { {0xF92F87B4, 0x1031EAD4, 0x65A63EAB, 0xA8C97B34, 0x20E8D222, 0x816B862C, 0xDE15A536, 0x3AECD4CC},
	{0xD9B8EFBB, 0xF45F00F3, 0x62B21769, 0x557CFC26, 0x04EEA00F, 0x2BB17CF7, 0xE2B9DFC3, 0x70308FBC} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 5137 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 5138 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 5139 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 5140 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 5141 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 5142 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 5143 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x39B2B52E, 0x89E5710A, 0xDE2265BF, 0xD208E68C, 0xAC5968B7, 0xFFED8FC4, 0x1F1EEBD4, 0x1BA8EA77},
	{0xFC7EDAD1, 0xEB556518, 0xC5D8B87F, 0x0CEE592D, 0x55C19D4B, 0x45A750BA, 0x0A01A0A5, 0x0934BB09} } ,
	 { {0x0F0E7765, 0x7171D5F0, 0x3555A809, 0x14382001, 0xCE408C62, 0x781F37B5, 0x875052A9, 0x10ECD8A0},
	{0x9A0A4596, 0xD3D81957, 0x40BEBD2B, 0xC6630527, 0xADCB3C91, 0x1817D609, 0xC6A9B139, 0x621C8EA5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD60A3E72, 0xFF69E7E7, 0x5FD52CE3, 0xAD74AAFA, 0x2EAB223F, 0x376114FB, 0x219ABCFC, 0x9F9A82FA},
	{0xB75845FB, 0xE0A59858, 0xE835EAAC, 0x43E75A13, 0x8BEF8EC6, 0x0D4DDFFE, 0x38E29149, 0x2F7357AA} } ,
	 { {0x4540515D, 0xF2B71F49, 0x7ED7228E, 0xB12AA8D4, 0xFD1C5BC7, 0xEBA67C72, 0x03F6F7B6, 0x55E38E11},
	{0x6369222D, 0x3CE9ED27, 0xF45A80CD, 0x7A84A303, 0xC135D7DB, 0x7EA663C2, 0x828DE3E3, 0x0A5CC544} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5144 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5145 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5146 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5147 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5148 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x9A806C85, 0xE1241D27, 0x52A73CE7, 0x65838594, 0x76D9CF77, 0xC9AFA45E, 0x27167BF3, 0x34F36804},
	{0x0976365B, 0x28DD7CE2, 0xB9AF661E, 0x20B9D222, 0x77F199ED, 0x7C138575, 0x8394BEE0, 0x4D58D113} } ,
	 { {0x24B53E6A, 0x62AD57C5, 0x5627AA65, 0x0A9A978D, 0xE175CE4B, 0x9F0D4314, 0x55579CF0, 0x040C9942},
	{0x57B7E79C, 0xC2FFB211, 0x73B15E38, 0x033210CA, 0xA20825A7, 0x404D0CC7, 0xE8D22B30, 0x1A5220EF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2A78B6EB, 0x3DC090CD, 0x238AB5FB, 0x17D7758D, 0x2C28E88B, 0x257F3C10, 0x4312A364, 0x9DDC6779},
	{0x87D4FC8D, 0x36931C5A, 0xB7B2F7F9, 0xA3625CFD, 0x5F9BDD35, 0xBAA137A7, 0x781E5E80, 0x13791C79} } ,
	 { {0x26DCC46F, 0x893F2786, 0xD57D6418, 0x34077F6C, 0x35608D92, 0xF6B5F610, 0xC5F1C800, 0x9A45DFE2},
	{0x29C67F56, 0x634DCEE5, 0x3B621B07, 0x43100DB0, 0xCCBF3293, 0x19AD5B27, 0xEB86A500, 0x85AA5C93} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5149 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5150 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5151 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5152 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5153 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x645885A5, 0x08984F78, 0x20BD5937, 0x3C0EB7B4, 0x510297C4, 0xE0522A2F, 0xC36F4DC8, 0x5BBEA2CC},
	{0x14DF6040, 0x312A7C69, 0xF62C2320, 0x3DA1CCED, 0x49750C1C, 0xC353383E, 0x51C09AA9, 0x7BF7DDD3} } ,
	 { {0xBB862691, 0x441FFAF8, 0x9396519E, 0xEC3BBE90, 0x3BB1787E, 0x9579976E, 0x3979A8D7, 0x8740FB00},
	{0xB909598D, 0xE3C233E1, 0x52A0613C, 0x22CFA783, 0x66147911, 0xB383B57C, 0x20A1042D, 0x112893D1} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xBC6099F1, 0x785CFAEC, 0xE3AB7777, 0x976DC1E5, 0x50B455A8, 0x5CE46F39, 0x820F9A3B, 0x36BCAB92},
	{0x7E2F1749, 0xBBFFC993, 0x530495B4, 0x3AD86619, 0x0E69942B, 0xA09B5BC0, 0x78BDCE04, 0x96C7BFA2} } ,
	 { {0x93533E52, 0x31710754, 0x98ECE033, 0x1FB5BAE5, 0xD9AA5C31, 0xF1736DDC, 0xBDC3E554, 0x4609DAAD},
	{0x19402243, 0x67268985, 0x35FA1451, 0xD384097B, 0x307F9331, 0x44AC7DB6, 0xC15C87AA, 0x835F6131} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5154 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5155 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5156 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5157 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5158 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x82427F01, 0x2CFF4ABE, 0x20E8E9C8, 0x3707DA6F, 0x3E891A81, 0x4C9C317D, 0xC1380758, 0x4A737359},
	{0x40C0D999, 0x27D4549D, 0x56EA6914, 0x375F0631, 0x285F6534, 0x91E76D27, 0xEA7C8295, 0x64F86CBB} } ,
	 { {0x4D7D2151, 0x9CBC49F1, 0xC696C23C, 0x2255DC00, 0x19EF24A2, 0xC4482437, 0x35C47020, 0x2356BA05},
	{0x3A15A6E5, 0x635B634A, 0x7C862A77, 0x225E6F56, 0x550740DF, 0x444B6B7C, 0xD266C770, 0xA167B697} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE9B16509, 0xE0EE9B17, 0x89A061AD, 0x052AF64A, 0x9B174415, 0x2F12A134, 0xB79889BC, 0x6726D77A},
	{0xE814E4C9, 0xC8A6645D, 0x8F994A07, 0x616C4DAB, 0x544A595F, 0xFB8B1197, 0xEE3A00A2, 0x84422661} } ,
	 { {0x25467319, 0x8389F7B4, 0xA029A3B1, 0xDD1A2799, 0x9C67AF85, 0x3918ADFD, 0x4A103514, 0x5CA45C18},
	{0x58C997D6, 0xC7BA78CF, 0xD445DE2D, 0xA1E4D25A, 0x6B097E7D, 0x358A3489, 0x30FE4654, 0x323AE9C6} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5159 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5160 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5161 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5162 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5163 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x66B2B3C4, 0x8D0F40C3, 0x2A326D60, 0xAA437903, 0x7563CBA3, 0x80600A44, 0x150B4927, 0x434710D8},
	{0xC4DEC23C, 0xE4A4EFDD, 0x547578CA, 0xA92663BE, 0x4BF9465C, 0x564AAF86, 0x48693362, 0xAA6210C6} } ,
	 { {0xEDAE259B, 0x01D255C7, 0x1F1EDFCC, 0xBAD0DB5E, 0x54C71A17, 0xF06FD792, 0x895B2527, 0x8EEC32A8},
	{0x6D9F2F59, 0xEE8781E1, 0x646F41D4, 0x324E5588, 0x775D4A2D, 0xE1362225, 0x6F59B9B5, 0x90BA63C5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x902B8088, 0x039FED39, 0x0ACBF212, 0x5CE6B574, 0x1E5EADFD, 0xD1D49E04, 0xC425B151, 0x8B34D158},
	{0x5C4B6F08, 0x5132E81A, 0x7B001A42, 0xC295F3CC, 0xA0800905, 0x8BEB41AF, 0xEBC959CF, 0x5B8FEFE6} } ,
	 { {0x8B2F4852, 0x483B6306, 0xC0D621AC, 0x8E646BA4, 0x19AE40FC, 0x60ADC31F, 0xF89C9BB2, 0x918D3933},
	{0xA1E194BF, 0x176FECC5, 0xD108553D, 0x63B54052, 0xA91F68FB, 0x5BC48334, 0xB20E2DA7, 0x835491AD} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5164 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5165 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5166 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5167 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5168 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE4378557, 0xCD46B22E, 0x1F818157, 0x2D6AD378, 0xF0CDD393, 0xE74E3C19, 0xB84B1C92, 0x302E6092},
	{0x942D1B59, 0x6E4CA6D2, 0x925CDF51, 0x19404A2E, 0xFC018790, 0x5D78B11C, 0x1F764513, 0x480013A9} } ,
	 { {0x3887E793, 0xC9DC4A38, 0x465A5BA7, 0x0AFB9FB9, 0xA54B586E, 0x06A7B5B6, 0x063ED32E, 0xA91EB4DA},
	{0xB0564CA1, 0x9746BF2E, 0x90BFE333, 0x0890D17E, 0xA873AD19, 0x572CA90D, 0xAB675116, 0x8096DD1A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x46DDC6AC, 0x7A5C87BB, 0x0AAEEF81, 0xE2A59CA4, 0x8C83E687, 0x9D20C942, 0x3AF175C6, 0x4B049482},
	{0xE0DA50AF, 0x663593A0, 0xC0EE1AC0, 0x2A926E99, 0x093EAF5D, 0x633CDAB7, 0xF9958B36, 0x4EF3AE72} } ,
	 { {0xB42A7073, 0x855BA8FE, 0x5B85B528, 0x19DB7758, 0x3A32DF56, 0x30B0FAA8, 0xC9132AA4, 0x3BC16CA7},
	{0xD3C5A15F, 0xA3C5087B, 0x3EAA03D5, 0x651B0071, 0x45EC7AD9, 0x08FCCFFE, 0x4807494D, 0x0630B721} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5169 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5170 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5171 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5172 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5173 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3CD1EBC6, 0x005BE2C4, 0xF3EE9D30, 0x8A74CECD, 0x399E9606, 0xBA2ECF0A, 0xCE7A4F5D, 0x61A4C11D},
	{0x0049B792, 0x932FF5DA, 0x945E10B4, 0x4424FC6E, 0x27390B29, 0x53B2F070, 0x114D5FBA, 0x1D9DF0B4} } ,
	 { {0x3738A914, 0x83C37E12, 0xF57421D1, 0xDBB03DB7, 0x7521B949, 0x1BBB5E38, 0x8E7DB22C, 0x91ECE165},
	{0x6BD31D11, 0x433C46E0, 0x3E07B557, 0x963D50EB, 0x3882FEB6, 0x2D0D2111, 0x7B68222F, 0x501D7B21} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xF779B5A4, 0x7FDC2A77, 0x014ECF0A, 0xDEAA1BD3, 0x814C9499, 0x271B356E, 0x0F46F033, 0x5E213790},
	{0x406FEBAD, 0x41099EFB, 0xC3538718, 0xD5A8BA7E, 0x38318AEF, 0xF88C9DD6, 0xDA9788E2, 0x0B74A808} } ,
	 { {0xE42AB197, 0xE3E05BE2, 0x5F8749FD, 0x04B15FB7, 0x6AB52B52, 0xBFB03A73, 0x0AB62547, 0x3A1FC752},
	{0xD1216D2F, 0xE662A5A0, 0xAAD9DCF7, 0x15C12280, 0xE9D2A064, 0x410BD634, 0xE4BB8379, 0x52292D14} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5174 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5175 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5176 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5177 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5178 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF7B4B136, 0x17BE65E2, 0x38BE45BB, 0x3B270DDE, 0x8369BAB2, 0x40538E6A, 0xDE6574FE, 0x8EEC80D7},
	{0x981ED1FA, 0x882B9E27, 0x617FCF9E, 0x8580A81B, 0x84B4B44B, 0xFB130D52, 0x1146E0D9, 0x7260DC8B} } ,
	 { {0x22EB13B3, 0x69F251EA, 0x87226B6D, 0xCE7B459A, 0xA14E321E, 0x74C7AE17, 0x04DF0102, 0x3D0472E5},
	{0x31ABDC87, 0x321EFB2B, 0x275CF806, 0x25ABB54D, 0x23235307, 0x0159159F, 0xCE59816D, 0x6024549D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA202416C, 0x9F226209, 0xD61C012B, 0x21D10F5E, 0x1EB97B8F, 0xC091EEC4, 0x81F5EDC0, 0x2C7410EA},
	{0x2578438B, 0x2AF08AD0, 0xE37F3EA4, 0x78B3308B, 0x1147F6BA, 0x4CE53761, 0xA321703D, 0x7D77CA52} } ,
	 { {0xE697BC00, 0x00065C93, 0x892A70D3, 0xF8FD7F7F, 0x90C3BB47, 0xD0297FBC, 0x0A4768DB, 0x52B10CF4},
	{0x33BD532A, 0x3976273F, 0x98DA8C6C, 0x5A92980A, 0x1DA5F751, 0x663F4C49, 0xC2C0D6CA, 0x9E3182B6} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5179 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5180 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5181 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5182 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5183 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x646F6FBF, 0x6363F401, 0xB51E6380, 0xBCC0B518, 0x084654D8, 0x7A40B115, 0xDD3AB8FC, 0x61A10E9B},
	{0x50B34403, 0xCCE9202E, 0xC8ECC5A1, 0xFDF9C422, 0x7AA7A4BD, 0xE643407E, 0x60BB1881, 0x8AF3E5CD} } ,
	 { {0x42C3BF78, 0xC3A8881D, 0x3464FD85, 0x2D4903A9, 0x13E2E589, 0x55905523, 0x2267B467, 0x1FB7A9DE},
	{0x996978E4, 0x4DD8530E, 0x6F819F41, 0x3083CE9B, 0xC36C1A77, 0xE637042E, 0x9BBEBB74, 0x7C9EAC97} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x9C0D323F, 0x7189E5B1, 0x6E9C5DA9, 0x8E3221CE, 0x926DEEC8, 0xBCA3E099, 0xF357C7B4, 0x585AF4F8},
	{0xFB3F88F6, 0x43161F6F, 0x5671DF44, 0x8F61C4FC, 0xC34825B6, 0xD1FEFE79, 0x33416470, 0xAC3EFDF5} } ,
	 { {0xC6DF1775, 0x78B46381, 0xB16C27B5, 0x76A086FE, 0xA27EC93D, 0xF3D58EF4, 0xC6DF31A3, 0x83FFC0B9},
	{0x7D82AE9E, 0x06821D17, 0x756C191B, 0x46F01566, 0x0DCC4A43, 0xDA4C6997, 0xA8EA0772, 0x7EA3DB4F} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5184 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5185 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5186 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5187 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5188 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBC1CC375, 0xD5AF3BD1, 0x1577621D, 0x32DD24AD, 0xF0D767DF, 0x49F612A4, 0x9946C806, 0x4352D8CA},
	{0x35B8D5C0, 0xFEF7D096, 0x26A8D660, 0x26185AFC, 0x3B33F7A3, 0xD3C220CD, 0xE7D99648, 0x6AE90875} } ,
	 { {0xFAFC72BC, 0x0CAEA2EB, 0x761EF40C, 0x1BA1C7EB, 0xD7D68837, 0xF126AAFB, 0x3E957941, 0x64EEF233},
	{0x4BFB4719, 0x6DEC7D9A, 0x1F560689, 0x5D445C3F, 0xE9918200, 0xC6024330, 0x62810992, 0x1D533A54} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x851FA15E, 0x61E4B6FF, 0x24B6F8D6, 0x4C83AECA, 0xAE98E0D9, 0xE1E56539, 0x9114B1A1, 0x96069D3E},
	{0xC9BB19BE, 0xC92EFE77, 0x36DC14DE, 0x26765F55, 0x0C44C104, 0xE938A78A, 0xD3924198, 0xA2936E41} } ,
	 { {0x31CBA706, 0x1F3A659A, 0x3C7359FE, 0x76251BA8, 0x389EECD7, 0xDAF6E6B3, 0x684EDB13, 0x19D66D44},
	{0x653BE544, 0x6DB2D1D1, 0x866267E9, 0xDAD0CEC4, 0xB3491B1D, 0x1DFD7D9C, 0x57D9EE41, 0x311B91E7} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5189 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5190 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5191 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5192 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5193 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1F2C4A85, 0xE2057F80, 0x57852476, 0xB7E85366, 0xD2BE8DAB, 0xF97BC81C, 0x3D87103D, 0x4BA119C8},
	{0x103EFA66, 0x58BF878A, 0xDFD2E991, 0xB56A10F4, 0xA2C97460, 0x31390FDE, 0x60DA23F7, 0xA359798C} } ,
	 { {0x361308EA, 0x023F5336, 0xF0131B07, 0x2C29C6AE, 0x905BD1FA, 0x2B0B04E1, 0x549A08F2, 0x8826ED58},
	{0x147FFCAC, 0xD79D73D3, 0x3E1DBBAE, 0xC3FF7840, 0x6E855BD9, 0x39564FC8, 0xFBCF2FA9, 0x413E9046} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3D58683F, 0x962A8FEB, 0xA8416B93, 0xB51973FE, 0x4D06C693, 0xB1C7EF91, 0xAEF852B9, 0x02770AC0},
	{0x5366E54B, 0xFBA12E45, 0x38535BD0, 0xD1B1B94C, 0x04862671, 0x5BE35A4E, 0xF353C363, 0x74C51848} } ,
	 { {0x39693E74, 0x7A3500EB, 0x5233F9F8, 0x3CC901C2, 0x96ABB1C7, 0xC1377897, 0xDA25F3E8, 0x48A83385},
	{0x8DDDF41F, 0xA360A7F4, 0x045F5D84, 0xCCC957C1, 0x9ECF0879, 0x52612248, 0x892753AC, 0x2186D9BF} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5194 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5195 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5196 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5197 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5198 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x54FBC7A4, 0xF70FBB32, 0xF38143F6, 0x667FB0A0, 0x6ACDA881, 0x1B7DEB4C, 0x8C9291CA, 0x0D9EE1A0},
	{0xA49F2C47, 0x1F5A12A2, 0x233E1DA7, 0x66722E86, 0x57584485, 0x35DFADC6, 0x290E79E6, 0x001A83E7} } ,
	 { {0x17E040D7, 0x8B47B6C2, 0x917C76C2, 0xB18FB97A, 0x65F3F73F, 0xE0D25438, 0x4E8E867C, 0x1EAED085},
	{0x5A11D8C2, 0xBB55C6FD, 0x4B64D25C, 0x49C64232, 0xF84D7E74, 0x6B8D7391, 0xA175C3D2, 0x8FB54389} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA10B3987, 0x67FB0BAB, 0x79A8A2C8, 0x8966FD40, 0xAC283EA5, 0xF29D570F, 0xF008173A, 0x47DF732F},
	{0xAADDEE74, 0x773A35EC, 0xCF6DF71F, 0x8F71D4F5, 0x5535380B, 0x4BE834FC, 0x366E5F87, 0x2900B3B4} } ,
	 { {0x295FD805, 0x1BD77326, 0x75101E6C, 0xCD63B599, 0xBEB9DC1B, 0x841201E6, 0xB03AB5A4, 0x0283A0E7},
	{0xB6DE9356, 0xBB52ADF9, 0x1596A974, 0xA23C5D3D, 0xDA10C681, 0xDE7D9949, 0xE6EFEAEA, 0x0D5C64F9} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5199 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5200 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5201 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5202 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5203 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCF425A4B, 0xCDD9BFB1, 0xCBDEFC3E, 0xDC4470D0, 0xD64B756F, 0x099DB0CA, 0x92400E20, 0x77DEC14F},
	{0xE43C860E, 0x2FE5D22E, 0x78B1D154, 0x8C968F79, 0x00B91CC3, 0x3D59307B, 0x94ED81FF, 0x9E3E7568} } ,
	 { {0x91C428B3, 0x73F72413, 0xC7EFFCB4, 0xBEF2475E, 0x293DCE5E, 0x70C4FBF8, 0x23F89973, 0x9D7E133E},
	{0x79165672, 0x8072AFC4, 0x2D48B40B, 0xF0E96FFF, 0x61D36361, 0xC315EFBF, 0x8A60915A, 0x51B993C5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x888FC34C, 0xAC23B3EB, 0xD79A1B24, 0x675B432B, 0xD3F9C5A2, 0x6CD81A83, 0xCED76B99, 0x45B5C6FB},
	{0x31678673, 0x626B316D, 0xE3313B80, 0x2DEDD9FA, 0x08D79879, 0x69C81048, 0x3BAE10A1, 0xA37CA3C1} } ,
	 { {0x471F0E36, 0xFBE38004, 0x5BCF90CE, 0xE1ACBD91, 0x7A179DA0, 0xBEFADB42, 0x48AEA03C, 0xA5E747ED},
	{0xFFD5F306, 0x922EA429, 0xC61A4A5B, 0x1EAB8D2E, 0x089BF728, 0x2B7A4FFC, 0x231F13EF, 0x7EF849D2} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5204 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5205 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5206 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5207 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5208 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3DC2C385, 0xBDABC013, 0xEA75CCB5, 0xA5C805CC, 0x02059ABA, 0x12DF7C17, 0x09EB90A5, 0x4D4C4C80},
	{0x5785D2FB, 0x75A4C120, 0x79352F3E, 0x78E05789, 0x76CCBE1A, 0xF976E029, 0x03D9FE07, 0x12BFE405} } ,
	 { {0x21A8C255, 0x8747B51A, 0xDA15D65D, 0xF0E93836, 0x8710C909, 0x68979D4D, 0x7B7558B9, 0x13ED3A95},
	{0xAD6D2712, 0x1E0AF4D4, 0xB4F3E0C5, 0xADD4AE56, 0xD72F1A5B, 0xE66D5877, 0x772B9EE9, 0x37A14D40} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x0EEFFE03, 0x5B6B808A, 0x291C48E7, 0x24D0C190, 0x58D61708, 0xB125FEBD, 0x328514D9, 0x21368CC2},
	{0xCC82A8F9, 0x48F753FC, 0xE024DAE1, 0x11FD62DB, 0xB967A0D1, 0x765A5B97, 0xA9DA5C54, 0x4A21A80F} } ,
	 { {0xB5A12A73, 0x9219AD8E, 0x79F4F88E, 0x926C7CBD, 0x6A3DC02A, 0xF062F205, 0x9E9F7E67, 0x09C04F99},
	{0x36BF255A, 0x25B70B0E, 0xA5D09437, 0x690DA69E, 0x9880F675, 0x604175F7, 0x4B83FF06, 0x3B086D03} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5209 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5210 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5211 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5212 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5213 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x05073EBB, 0xC5D0FC10, 0x073EB30F, 0xDF2ABB3D, 0x91863E63, 0xB8BEC610, 0x4836E45C, 0x6CF987BB},
	{0xC1EAE5DB, 0x1A4EBE73, 0x4A37F84C, 0x88D7CAEA, 0xA5B32AB8, 0x49C132F1, 0x3E454889, 0xA9B2F05C} } ,
	 { {0x2CB0CB26, 0x20AD5DCF, 0x26B76859, 0x8988CE9A, 0x97540279, 0x7999F36C, 0x89856380, 0x874198D0},
	{0x906477CA, 0xEB6BE702, 0x9FF5EC4E, 0x01C4A3E9, 0x4B97B9C3, 0x2C7CA836, 0x6BFEDAF9, 0x0E7343C3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x60C5BD5A, 0xE6DF1DE9, 0xAE45F5E9, 0xF29C7BBC, 0xB612834F, 0x826709E9, 0xBC02AB37, 0x6837C15F},
	{0x50DD70F7, 0x12916CA6, 0xEF7A1132, 0xFC21C79A, 0x128094E6, 0x28CCE747, 0x6FFBA9DC, 0x5C5D6264} } ,
	 { {0x13E2B976, 0x552859E1, 0x39875A69, 0x3CE2134A, 0x9FBE22DB, 0xA2F5AFA0, 0x0A8ACF85, 0x0EAD2C30},
	{0x75B1140E, 0x6AA4B0EB, 0x5BB8C770, 0x95ABB7C4, 0x7F10137E, 0x8719B9D5, 0xA0A39BA0, 0x4D83B145} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5214 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5215 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5216 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5217 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5218 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE0DBDDC2, 0x000CEDF3, 0x9E2F6D04, 0xB733D60B, 0x3BADECB2, 0xE1D7AE3C, 0xD2F97843, 0xB6D4194F},
	{0xB58772B2, 0xC45A21AF, 0xC7EDD3E4, 0x68175819, 0x3FDC399B, 0x2E235F89, 0xE30E2CB5, 0x207599ED} } ,
	 { {0x61EA53BD, 0x749900B5, 0x7FC8CAAE, 0xD312D62A, 0x6469AE7B, 0x823C9E59, 0xF751B2A4, 0x02606F7D},
	{0xE4DAB63A, 0x83A338E6, 0x96CCC933, 0x1B79EDA2, 0x5015F51F, 0x1BF048D7, 0x8728F272, 0x023B693A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x957E7078, 0x19185645, 0xA7D23C0E, 0x5490F668, 0x8599F719, 0x62BDA1B7, 0xD73F863C, 0x8B604F7C},
	{0x5AA29674, 0xBAE19CD7, 0x522D1DD3, 0xA5052205, 0x2A7D78C6, 0x77FE72B3, 0x7761ED5F, 0x9DC5B868} } ,
	 { {0xF2AD46B1, 0xEB9B8DCC, 0x5D0FF69A, 0xA5C11C10, 0xE5AA7CAD, 0x55D5364F, 0x7E8CD2BE, 0x61B41953},
	{0x1487E76C, 0xE53EDC82, 0xCDD3DD4C, 0x469F0855, 0x3E7E3E06, 0x558BDF5E, 0xE4802193, 0x9E607B90} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5219 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5220 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5221 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5222 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5223 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x423BEF50, 0xF7F3AB07, 0x927BE7A5, 0x0E9DC39D, 0xA04F9B19, 0x0538282A, 0xC909D5B6, 0x7E359FE3},
	{0xC63D2C99, 0x42780858, 0xED0822CD, 0x9CFE36E2, 0xA74C65E6, 0x84273E24, 0xD7787301, 0x35894EA6} } ,
	 { {0x53F09948, 0x4931322F, 0x5F5BD53F, 0x0E47DDC6, 0x0744E543, 0x304068CB, 0x16F8F6DF, 0x18B8466A},
	{0x343B14E0, 0x9FA237C9, 0x5A968E0B, 0x20E8C123, 0x3C731739, 0x3352B9F5, 0xD36B6CD1, 0x078EDD31} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB8207E4E, 0x9C1839A1, 0x1E3D9163, 0x960F31EA, 0x0D80ACED, 0xE0D72D0D, 0x4EA99E0C, 0xB240ED54},
	{0x7D555849, 0x03AD1198, 0x66D407DA, 0x2555F570, 0x2F87123B, 0x88DF95CF, 0x5B4FE1AF, 0x3813ACA6} } ,
	 { {0xCEA3D828, 0x3F130786, 0x8A00FF51, 0x5540A0A8, 0xBDA1AF9E, 0x2D373A2C, 0x65646BCC, 0x9F4A58D1},
	{0x21762B1F, 0xC7A41294, 0x66341BCF, 0xA4A9D66C, 0x82887661, 0x4B2EA15F, 0xC931A062, 0x4ECB8278} } ,
	 { {0xA7E13290, 0x9262645E, 0xBEB7AA7E, 0x1C8FBB8C, 0x0E89CA86, 0x6080D196, 0x2DF1EDBE, 0x31708CD4},
	{0x687629C0, 0x3F446F92, 0xB52D1C17, 0x41D18246, 0x78E62E72, 0x66A573EA, 0xA6D6D9A2, 0x0F1DBA63} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5224 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5225 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5226 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5227 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5228 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5229 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5230 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x0F098598, 0xF1D6AF29, 0x273D64F6, 0xC269F333, 0xB5EC527E, 0xC6039553, 0xFB94F77F, 0xBA09EFBC},
	{0xDEF91494, 0x03F7FCFF, 0x5CFD0A88, 0xD135D188, 0x8CE0CB60, 0x487980DE, 0x2FB2BE46, 0x69517B67} } ,
	 { {0x02BE7960, 0x7D370862, 0xA811507B, 0xF32D1D42, 0xBDFBE0B5, 0xCC9F96B6, 0x7B25BF99, 0xB1ABBE92},
	{0x560F1481, 0x3B2CF373, 0x7534862A, 0x9946AC5B, 0xD135BAD6, 0x9B1F2912, 0x0444B3A2, 0x3648C5A1} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x617AF2DE, 0x10BE8E9B, 0x0DC5778E, 0xB91DB370, 0x729B50D4, 0x102A958C, 0xA2853828, 0x033F786B},
	{0x614517C5, 0x8C94AD7E, 0x345E0BC1, 0x289B3CDE, 0xFF9907BF, 0x5D1DD407, 0x7335EA05, 0x52B908A1} } ,
	 { {0x90861AB8, 0xC2211A68, 0x131EEE26, 0xDE4E6444, 0x75F13C4C, 0x2C43AA49, 0x0E41097D, 0x6C0104B2},
	{0xA6396F99, 0x61220E09, 0xAF0536EB, 0xC6318239, 0x48EFA083, 0x0A72653D, 0x04C9DAA0, 0x76F18206} } ,
	 { {0xA350BE25, 0xFB7F8712, 0x7BAAC1AF, 0xD3488DE4, 0x281537B6, 0x9DDED102, 0xB62CA30A, 0xA943DE62},
	{0xAC1E2902, 0x7659E6E6, 0xEA690C54, 0x328D58B6, 0xA26B75AD, 0x363E5225, 0x08896745, 0x6C918B42} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5231 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5232 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5233 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5234 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5235 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5236 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5237 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x23091F43, 0x2B07B0F8, 0x0F049353, 0xF7056CC9, 0x9CB7EA29, 0x510279B5, 0x51268957, 0x4AF2D7F5},
	{0xBB7215F3, 0x4636DC7A, 0xE280C485, 0xED9C26DD, 0x18AE4858, 0xDBCBCC73, 0xD2028F91, 0x99B4281F} } ,
	 { {0x1FB8FAF7, 0xCAEE0E10, 0xF20FFC40, 0x94D94F26, 0x8E36B199, 0x76EF7B46, 0xC8B8149A, 0x09D4F2F5},
	{0x7CD90A3B, 0x07791306, 0xC0D3245B, 0x0599540A, 0xA6AD3DED, 0xE4FDE169, 0x1E07C19E, 0x6A30BC08} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x2E898C53, 0x3D7EEE0F, 0x4780995F, 0x5BBF80E3, 0xA3AABCFC, 0xA68FC927, 0xEA9CD5D2, 0x2DA7EE81},
	{0x8AC94F80, 0xB81D1EA8, 0x4F53CD1A, 0xDCA7E163, 0xBBBE7AC1, 0xF0B5F515, 0x2FA94F9F, 0x2B8CE53E} } ,
	 { {0x738AF402, 0xCD643781, 0xC924EFD7, 0x7C50335C, 0xA85139DB, 0xCD92C3B0, 0x390C8502, 0x46448093},
	{0x4C1BBE24, 0x7B2F872E, 0x7334B924, 0x0CB2406B, 0x7BE27073, 0xE533B3DF, 0x4D8B4BFC, 0x7798CD5D} } ,
	 { {0x3F71F5EE, 0x95DC1C20, 0xE41FF881, 0x29B29E4D, 0x1C6D6333, 0xEDDEF68D, 0x91702934, 0x13A9E5EB},
	{0x9785DFDB, 0x10039C5B, 0xAD2E696F, 0xF820FB74, 0xF977F224, 0xCE9B6667, 0xFBF0A714, 0x1A4DD94D} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5238 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5239 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5240 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5241 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5242 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5243 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5244 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3DF1E357, 0xBA323ABC, 0x7E226649, 0xB40AF927, 0x052E29A0, 0x137DF154, 0xE344DEB1, 0x61DAAF3C},
	{0x3142469E, 0xD161537A, 0xA1548E35, 0x7DE0F31D, 0x869C3F89, 0xCA4607C8, 0xA833FEB9, 0x4E7461A3} } ,
	 { {0xC3A16F73, 0x9EDC7CCC, 0x2A40B2DC, 0x9EB231E9, 0x12CC03A4, 0x85D738A9, 0x57427F7C, 0x05A47D76},
	{0xEB1AAF47, 0x5740D8B4, 0x92D9A952, 0xD8845F7E, 0x91848BAA, 0x07BF67A8, 0x7986E7CF, 0x65F6389B} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA8893F77, 0x16B54156, 0x9B6E7F9C, 0xB084A325, 0x6E58A329, 0x2D0C3C41, 0xB2C994D2, 0x21E96F96},
	{0xB9EC5465, 0xC5A13486, 0x3D993103, 0x38DB9664, 0xA6A1E144, 0xFDB005FE, 0x441F4747, 0x108C6BB9} } ,
	 { {0x4D51191D, 0x9C3745EC, 0xB367127F, 0xB2DD243B, 0x78BD40AD, 0x210AB70B, 0xE81D204B, 0x02E19624},
	{0x1D09A7FE, 0x77A37687, 0xB4960B70, 0xB9DB0EC9, 0x7C88A9BF, 0x1FD99F90, 0x4FD88126, 0x2E9393E8} } ,
	 { {0x8742DEE6, 0x3DB8F999, 0x548165B9, 0x3D6463D2, 0x25980749, 0x0BAE7152, 0xAE84FEF9, 0x0B48FAEC},
	{0x740929F3, 0xAF9327B8, 0x513B735D, 0x9DF7125C, 0xCF268DA0, 0x141E72E5, 0xB2EEF375, 0x11D8D274} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5245 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5246 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5247 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5248 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5249 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5250 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5251 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAE7AB7F3, 0xADBF344D, 0xE6208A73, 0x844887DA, 0x4B0BBECD, 0x506F0E78, 0xCF24CFA7, 0x07ACEECB},
	{0x8318EDA0, 0x51042058, 0x763C5DF6, 0x88AE589E, 0x6DBE58E6, 0x62C7989C, 0x6DC21AFE, 0x5C22792B} } ,
	 { {0xAD319A03, 0xB143DB8D, 0xEE0A9D7F, 0x63A1FCF6, 0xC8F79CA1, 0xDB122798, 0x42C2270F, 0x83AB41DB},
	{0xEE6CD004, 0x3725AC5D, 0x1CC2C9EF, 0x2D98C72B, 0x14A37757, 0x8C97C8FB, 0x7B25C6DE, 0x4D8D84D5} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x9012A651, 0x18B243FA, 0x358EE59F, 0xF0B6786A, 0x2AAA0D20, 0x565792E9, 0x3C20E14E, 0x43A9742A},
	{0xA0DF25E3, 0x09DA634D, 0xF8F215A9, 0xD83DD7E9, 0x39564DEA, 0xB2E03291, 0x20CA5274, 0x0DEA563D} } ,
	 { {0x2324F72E, 0x94C86A3F, 0x5C743780, 0x7877E4D0, 0xCD483318, 0xC2080501, 0x242E2971, 0x1AEA348B},
	{0x6641B443, 0x4CF0E7D3, 0x5C8C8F40, 0xF5556C25, 0xBBD620DA, 0x1CE97A23, 0xE91FC977, 0x7DD960B8} } ,
	 { {0xF836FF6B, 0x63992D69, 0x079D5BB8, 0xB4324D4D, 0x3E0CAF8D, 0xBAC3F2C6, 0x456571F6, 0x4D42E4F4},
	{0xDCD9A008, 0x6E4B58BB, 0x398593DE, 0x5B318E56, 0x2946EEAE, 0x192F91F6, 0xF64B8DBD, 0x9B1B09AA} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5252 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5253 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5254 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5255 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5256 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5257 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5258 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x60AC38F1, 0x0854BCE5, 0xCB458BB1, 0x8DE0FBA4, 0x5CEE5AD9, 0x7CBFC2C6, 0x239ABF24, 0x6D165963},
	{0xA114C3EE, 0xFE9C9032, 0x673230ED, 0x7B34E717, 0x65E44DD4, 0x1582C795, 0xC0ABCD7E, 0xA8F8B403} } ,
	 { {0x3DFBE579, 0x4B32B683, 0x85152D14, 0xCA4FC3A3, 0xF38F69FC, 0x1850AF20, 0x3E29247C, 0x237A03C0},
	{0x24046E16, 0x9A85CCAA, 0xAD1D1BC4, 0x273A607C, 0x56693743, 0x24C8A33D, 0x9859ACDD, 0x01CF0480} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x01FB9A17, 0x746D58F1, 0xBCA9796E, 0xF39A39D5, 0x932B0C1D, 0xF1C5A7AF, 0x0F565049, 0xA93A760D},
	{0xF56FC962, 0xF7E1F6F1, 0xA84AA039, 0x6956321E, 0x5AAD0F1E, 0xED3CF166, 0x96FBFF70, 0x67C06484} } ,
	 { {0x137C893C, 0x151CDD51, 0x676F0CA7, 0xC461AE84, 0xA843419A, 0x8A7D3B4D, 0x3EC243D1, 0x0827D462},
	{0x4392040E, 0x056EC4A1, 0x0F520B84, 0xA810392A, 0x63C0BB49, 0xCD37E268, 0xD452DF8B, 0x1C0558B2} } ,
	 { {0x7BF7CAF2, 0x96656D06, 0x0A2A5A28, 0x949F8747, 0xE71ED3F9, 0x30A15E41, 0x7C5248F8, 0x46F40780},
	{0x4808DC2C, 0x350B9954, 0x5A3A3789, 0x4E74C0F9, 0xACD26E86, 0x4991467A, 0x30B359BA, 0x039E0901} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5259 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5260 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5261 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5262 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5263 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5264 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5265 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6F8D0453, 0x6EEFFDD6, 0xF8767CF4, 0x340F332D, 0xE31434E0, 0x95D0EB03, 0x7AE388B1, 0x2AC5DF36},
	{0x18D67879, 0xE9442FE3, 0xD2041EF3, 0xD659AE2E, 0xCFDF0DDD, 0xAD1E6C93, 0xDE90EAA4, 0x2D3B4E8B} } ,
	 { {0x349A15AE, 0x785B2866, 0x26AC5CA2, 0x973B01AB, 0x0A58649D, 0x782FA7A2, 0x464CE068, 0x320E046E},
	{0xF226592E, 0x2E513760, 0x408D8665, 0x511DEE62, 0x26028152, 0xAFDC225B, 0x7F5DAB81, 0x6982E3F9} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x49408E62, 0x90F234ED, 0x5526F894, 0x569CC14A, 0xC70AF7E0, 0x2A78988B, 0x631EB604, 0x659892DD},
	{0xC1C5051E, 0x38BC0417, 0xE1885231, 0x7E49B2EE, 0x67E3E5D9, 0xF5D96603, 0x9210A650, 0xAAAFD57D} } ,
	 { {0xDF8BF53F, 0x90D6B392, 0x6E9101C7, 0xA03CE00B, 0xF939648C, 0x8DC37F80, 0x4F4B0CF8, 0x4816E191},
	{0x61411C9B, 0xE9B9CBF5, 0x239AAD03, 0x646497CD, 0xD6DFB90B, 0x8CE6E0BF, 0xB1F302CB, 0xB72E8836} } ,
	 { {0x69342B5C, 0xF0B650CC, 0x4D58B944, 0x2E760356, 0x14B0C93B, 0xF05F4F44, 0x8C99C0D0, 0x641C08DC},
	{0x82207DC1, 0x5DB3E510, 0xACA32D83, 0x8F2A3023, 0xF82278EF, 0x6457E84A, 0xBE9C7ADA, 0x18F22930} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5266 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5267 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5268 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5269 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5270 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5271 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5272 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x98EE25B4, 0x67871913, 0xED16ED8F, 0x2254D1C9, 0x01E14910, 0x017AEF06, 0x69CA4368, 0x0E1BB3EB},
	{0xD1F76129, 0x233DA29D, 0x1EE0D4BA, 0x890ECFA5, 0xF72800FD, 0xA649DA07, 0x31504462, 0x8CA5D4E7} } ,
	 { {0x3756D9C2, 0x10044BF9, 0x06BBFE71, 0x4133EBBD, 0x4CBB8E98, 0xF9D4926E, 0x332B0AFF, 0x0C3AC2D5},
	{0x3667DDC3, 0x9B024979, 0xE5D844F3, 0xE58B3B14, 0xC92B1E70, 0xF7C49312, 0x72BCBF47, 0x2C87362E} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3FA8C436, 0x7C548566, 0x86AD4752, 0xDCAD41D1, 0xE3F9BB5E, 0x07069D31, 0xCE52ADE8, 0x07E93EFD},
	{0x87294062, 0x721547C8, 0x1965DD69, 0x213F569B, 0xD15028CB, 0xB563A74C, 0x4EF04812, 0x2329ADEB} } ,
	 { {0x518C385E, 0xEA5981FA, 0x5961BDA9, 0x721EABBD, 0x1297A269, 0xA7C4C4B4, 0xF0296AFF, 0x09E41EB6},
	{0xFE75FE1A, 0xCB156BAC, 0x837077B0, 0x802AFEC2, 0x5BFDE2B8, 0x1D2C323C, 0xE319A269, 0x5C47F924} } ,
	 { {0x6EADB384, 0x200897F2, 0x0D77FCE2, 0x8267D77A, 0x99771D30, 0xF3A924DC, 0x665615FF, 0x187585AA},
	{0x6CCFBB86, 0x360492F2, 0xCBB089E7, 0xCB167629, 0x92563CE1, 0xEF892625, 0xE5797E8F, 0x590E6C5C} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5273 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5274 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5275 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5276 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5277 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5278 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5279 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x4BE09C1E, 0x6BF58EB2, 0x11049D1B, 0xD79DAD42, 0x0AEA2167, 0x490C15C1, 0xDD4B173B, 0x0803D79B},
	{0xCA468BEB, 0x236E39DF, 0x1FA96141, 0x50C43C2E, 0xC3927871, 0xEA6C6C6D, 0x101DBCA1, 0x073CC835} } ,
	 { {0xE5950342, 0xD1B82E14, 0xDCE52E30, 0xB0AF2356, 0xE9883BA4, 0xEC50D840, 0x1C96BEC1, 0x337D64AA},
	{0xBB338A1A, 0xC5444F67, 0x6CD592B6, 0x26E973B5, 0xD0069ADC, 0xBBD3E37F, 0xA1726409, 0x1AD0B9D0} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xF7E7F557, 0x112A24F0, 0x40D271CD, 0x257DE2DE, 0xA3001B1F, 0xB0DD8840, 0x89AD03EE, 0x9024EF98},
	{0x624F6FE9, 0x7857B93C, 0x0823EDB1, 0x43B4513E, 0xF67F3128, 0x67E42537, 0x53DD5688, 0x665381AF} } ,
	 { {0x5DB7073E, 0x60BEA075, 0x2BA55FF7, 0x6F86DF30, 0xAB4B85A9, 0x5BE9751E, 0xDAC68F4D, 0x91627FC9},
	{0x85E72FAA, 0x62A1C2F1, 0x1AC5CB66, 0x98E3ED8C, 0xFD2E2858, 0x97DAEEB5, 0x96CF312D, 0xB7BD7208} } ,
	 { {0xCB2A0684, 0xA3705C29, 0xB9CA5C61, 0x615E46AD, 0xD3107749, 0xD8A1B081, 0x392D7D83, 0x66FAC954},
	{0x76671434, 0x8A889ECF, 0xD9AB256D, 0x4DD2E76A, 0xA00D35B8, 0x77A7C6FF, 0x42E4C813, 0x35A173A1} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5280 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5281 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5282 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5283 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5284 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5285 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5286 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAA3158C8, 0x32E66EAE, 0x32841DEB, 0x4DF221E2, 0x3FADF241, 0x04957B89, 0xA3145E46, 0x2845D710},
	{0x35550758, 0x429678EF, 0x0FB3FE23, 0x4FA8097D, 0xC196F83E, 0x524E950E, 0x47B7D691, 0x8DCC5006} } ,
	 { {0x3EE8572B, 0x0FBB4EEB, 0x7F50B948, 0x545BA515, 0xE54ABDA6, 0x491C5A6C, 0x782E242C, 0xACF25E20},
	{0xEB52FD8F, 0x1D18B4E4, 0x0EDC742A, 0x1893E4BC, 0x7A15B50B, 0x7043405B, 0x6C7253BE, 0x87525FFD} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x26774C78, 0x86F06051, 0xDBEAFC41, 0x670FAE17, 0x6D3F581E, 0xA62E5500, 0xECBA8382, 0xA4444F91},
	{0x38BED3BB, 0xDC7DF45A, 0x2C6F6A01, 0x9610BBDF, 0xAD0643B5, 0x2495BE7D, 0x1DF157F1, 0x59D99D71} } ,
	 { {0xB5184410, 0x9FD4E385, 0x936A5126, 0x8961EA3F, 0x80352B39, 0x92932978, 0x9DA32F0A, 0x4EFAF1C7},
	{0x20CD5D9B, 0x994D2CC5, 0x3354F7AB, 0xD06B740F, 0x4C2AD5B3, 0xF57440D4, 0x4DFFC8A3, 0x6C5A6BE0} } ,
	 { {0x1BA479BB, 0x20881425, 0x2A299349, 0x95A59D8A, 0x76B2F197, 0x96D8586E, 0xB03D6C2F, 0x9FD11D7E},
	{0x7479C683, 0x3B42E018, 0x4941090D, 0x1E161CD7, 0xA048E061, 0xE526244B, 0x98C5CB53, 0x54912138} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5287 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5288 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5289 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5290 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5291 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5292 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5293 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x104453F0, 0x8B4E740D, 0xCBFA8A02, 0x7FF4C964, 0x97EBBC8F, 0x391D4C1F, 0x9E70CEBE, 0xB46C1ACD},
	{0xD3582FCB, 0xA12B6131, 0xD8837AAE, 0x812FB0DF, 0x33154E21, 0x168E1C2E, 0xF5C4A043, 0x815B9024} } ,
	 { {0x7391D847, 0x4EE58FE3, 0x84A91198, 0xFA6F79FC, 0x50FE389C, 0xCF57C2F3, 0x93D2C0D8, 0x44CF82DB},
	{0x354C8F67, 0xE647B172, 0x17F97372, 0xBB07D96E, 0xD0A57480, 0xDB97CC51, 0x4F73AC12, 0x6F35D511} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x036F9369, 0x0B9C274A, 0xC78CF42A, 0xC98BC857, 0x6A6646AE, 0x897C25FF, 0x921E6FAC, 0x26E628DA},
	{0xF8547D6A, 0x512EA493, 0xD534B6B0, 0x56E6F74D, 0x0ABC8FBE, 0x9AEC8A4B, 0x6E990C70, 0x4BC5E7CE} } ,
	 { {0xFDADB422, 0xBD8B694E, 0xD858C389, 0x18AF56E6, 0x69DFA127, 0xDB50DE76, 0xA5DAF4AF, 0x21E29746},
	{0x982D1733, 0x2C57D3C9, 0x24CF2730, 0x690F1A91, 0xAD975BB1, 0xF6B82870, 0xF9AA21E1, 0x841575D5} } ,
	 { {0xE723B08E, 0x9DCB1FC6, 0x09522330, 0xF4DEF3F9, 0xA1FC7139, 0x9EAF85E6, 0x27A581B1, 0x899F05B7},
	{0x086CEA33, 0xCDA0D933, 0x5B7B079E, 0x62FE063B, 0x4D685F4C, 0xBBCF3C38, 0x5EC87BFC, 0x24580B60} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5294 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5295 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5296 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5297 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5298 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5299 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5300 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x287D8912, 0x9AEE6C1D, 0x61C0F27C, 0xFFB078B0, 0x4E3A90F4, 0x00C3BC90, 0x4E95D122, 0x3CB7908D},
	{0x6C75CB21, 0x237EFA4A, 0x215FF16A, 0x31A2BF41, 0x5D0AD798, 0x13617E54, 0x7CF65E37, 0x7BCCB7E4} } ,
	 { {0xE243E411, 0xA7DF8F68, 0x6706E5DF, 0x480FB13F, 0x8A072F72, 0x662B6C3B, 0xF8ACBDD5, 0x1B36C732},
	{0xB3925209, 0xC9DD754A, 0x8E4BA940, 0x546CBF7C, 0xB866F667, 0xD211CFC0, 0xE0351A8D, 0xB6D299C0} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xE2EE369C, 0x6BD4F333, 0x604295BE, 0xF426394A, 0x1D42DCD3, 0x01C2C52B, 0xCAA76D86, 0x8370D542},
	{0xEDAC07FC, 0x8DA71595, 0x25B13CED, 0xD223AC76, 0x345A10B9, 0x3AC11C4A, 0x87BECECB, 0x0DD53037} } ,
	 { {0xF176F047, 0x68663672, 0x629B1400, 0x2668318E, 0x42159C9C, 0xF2FD3F54, 0x829F97BF, 0x15FF1472},
	{0xE5E69E2D, 0xDD85B2F8, 0x0F870D7D, 0xC23CA606, 0x59B71898, 0x5486637F, 0x1BDB669C, 0x1D8253A5} } ,
	 { {0xC487C822, 0x4FBF1ED1, 0xCE0DCBBF, 0x901F627E, 0x140E5EE4, 0xCC56D877, 0xF1597BAA, 0x366D8E65},
	{0x04F86F77, 0x94CC60E4, 0x481F733A, 0x95C7D258, 0x1CEB6319, 0xA8C34316, 0x804B58F2, 0xB39194BF} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5301 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5302 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5303 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5304 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5305 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5306 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5307 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xECFB3836, 0xE24151C4, 0xF87DEFE2, 0xD45020DB, 0x36321E77, 0xA4DE79BD, 0x86CCA861, 0x439E878F},
	{0xFA08B9A2, 0xCE780877, 0xBB8F6A88, 0x954A3BAA, 0xE53895AA, 0x5FBB37C7, 0x4D735941, 0x1E7EAA35} } ,
	 { {0xD42C158E, 0x7E9C99D7, 0xA4915A4A, 0x84A5D2A5, 0xC6596C45, 0xB9299A6E, 0x1A992A25, 0xA435E374},
	{0x720A02C9, 0xB50D9E6A, 0x00144D55, 0x1D308C36, 0x803EAE73, 0x8EC477D6, 0x9D7C84B3, 0x081F1239} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x5794DD33, 0x313E27EC, 0x433174AC, 0xCF5F8C34, 0x2D720453, 0x9C68019E, 0x098574C7, 0x8E3F52A6},
	{0x8B5AA4EB, 0x9ABBDE4E, 0xC7750C4B, 0x0595A0C8, 0x94EA615E, 0x1640EE36, 0x104D8CA9, 0x6589ECD8} } ,
	 { {0x41D93CDB, 0x46F67DC8, 0xA15ABEA4, 0x8AD090C2, 0xD0152DAA, 0xA556C7DD, 0x56383A52, 0x5D70EC93},
	{0x2118D510, 0xB3DE9C49, 0x9B97737F, 0xEA503975, 0x8EB9A65B, 0xCA5CF1D2, 0x49E42CA7, 0x24494485} } ,
	 { {0x462BF681, 0xFE4AA9FE, 0x74AAD54D, 0xF639F8AA, 0x38D04ED5, 0x76F2D872, 0xF5137822, 0x8E582825},
	{0xE4140592, 0x6A1B3CD4, 0x00289AAB, 0x3A61186C, 0x007D5CE6, 0x1D88EFAD, 0x3AF90967, 0x103E2473} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5308 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5309 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5310 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5311 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5312 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5313 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5314 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xE3ABC61C, 0xB7983044, 0xF0A21D2E, 0x002EA4A2, 0x62E25906, 0x6AE38729, 0xDC257546, 0x358FE86A},
	{0xDCF0203C, 0x78589C2D, 0x9E6AE382, 0xD4411B62, 0x3F4AB4CE, 0xE37F1640, 0xA45CE9CB, 0x9D188E31} } ,
	 { {0xCCF25D99, 0xF07973CD, 0xC5D643D8, 0xF9D2F8CC, 0xDD1ED452, 0x571BE0A1, 0xFE61CD2B, 0x535C3D20},
	{0xD4AF6727, 0xA54ED35C, 0x15F72C19, 0x23F32E65, 0x7D7232BF, 0x9B53F8D4, 0x6125790F, 0x3F58E01E} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA6C825B8, 0x5E6EDE29, 0xDE87545D, 0x62A0E71C, 0xB9C10E23, 0x22E3CFC0, 0xA1A690EB, 0x40C8FFB7},
	{0x40949CAA, 0x5CF7B5CB, 0xE6B548BE, 0x32BD7A16, 0x8ADED6D8, 0x474EEE61, 0xD43A3C49, 0x7B7173CD} } ,
	 { {0x9048E04C, 0x2B92F3C3, 0xECD2D001, 0xCED39E0E, 0x1688C7B5, 0x37BFDF58, 0xF22C86F2, 0x4F1860BC},
	{0xC833BF41, 0x1B576E87, 0xB4E1A299, 0x9BC4AA47, 0x41336A59, 0x17D48E90, 0xC175FFDA, 0xA50A29AA} } ,
	 { {0x99E4BB32, 0xE0F2E79B, 0x8BAC87B1, 0xF3A5F199, 0xBA3DA8A5, 0xAE37C143, 0xFCC39A56, 0xA6B87A41},
	{0xA95ECE4E, 0x4A9DA6B9, 0x2BEE5833, 0x47E65CCA, 0xFAE4657E, 0x36A7F1A8, 0xC24AF21F, 0x7EB1C03C} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5315 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5316 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5317 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5318 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5319 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5320 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5321 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x47886842, 0xDE69CB3D, 0xD604F1D3, 0x81A8001C, 0xBB281D88, 0xC5CDE35A, 0x3FFBE29A, 0xB51DD514},
	{0x2D1A0DBE, 0x8745E9B5, 0xC596A162, 0xA467549B, 0x6042CC89, 0x2894A7CC, 0xAABC549E, 0x209696C8} } ,
	 { {0xF89143BE, 0xC8DCDBA2, 0x315A0529, 0xD7BC5F7E, 0xF527BE2A, 0x66C04048, 0xEEA999EE, 0x0750EF6F},
	{0x86B12383, 0x721BA1CC, 0xDAA594B5, 0x37CC17B7, 0x344F330C, 0x83BDB5C7, 0x58F35862, 0x94F81FE3} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x72CC8C82, 0xB56E705C, 0x138322C2, 0x5E3EE923, 0xB658BED2, 0x622870DF, 0x2F64180A, 0x0469C309},
	{0x7DD48191, 0xFDA00E41, 0xB897E86F, 0xD04DB953, 0x4A3C96F5, 0x3E4A82C2, 0x267725EA, 0x46A7FC4F} } ,
	 { {0x406AD477, 0xFC0C9F69, 0x6C03779E, 0x7E7395A8, 0x22327AA2, 0xFE7F201A, 0xE779A3DE, 0x26D72209},
	{0x1F83D725, 0xF31D9D9A, 0x46FA87D3, 0x633316C6, 0x23B2F6EF, 0x440B5657, 0xA761B23A, 0x8BA50A76} } ,
	 { {0xF122877C, 0x91B9B745, 0x62B40A53, 0xAF78BEFC, 0xEA4F7C55, 0xCD808091, 0xDD5333DC, 0x0EA1DEDF},
	{0xAB36126B, 0xE548B9E7, 0xE0D34A23, 0x5C8682CE, 0x14BBDC63, 0x0C1B0F23, 0x71C7D49C, 0x6FDCA104} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5322 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5323 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5324 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5325 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5326 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5327 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5328 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x239036E0, 0x66A9E425, 0x94D8444B, 0x2B14DDC9, 0xC4A56960, 0x7C33384F, 0x42AF2114, 0x63934CFC},
	{0xB26A0948, 0xF2B215AD, 0xECE8F209, 0x873FAAE1, 0x7BB9405A, 0x443A3B7B, 0xCCAB7991, 0x2000E9F5} } ,
	 { {0x62EF6726, 0xF28720DD, 0xC46D24C1, 0xD1679E7B, 0x0A57F8AB, 0x72ACD0B3, 0xD9F60D1E, 0x6D914F12},
	{0xB4B0D939, 0xF28950EA, 0xC0253980, 0xCF5A1E9D, 0x2B8C7A58, 0x091564C1, 0xF06ABBC0, 0x44F92FA0} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7323202A, 0xE724D033, 0x06A7718E, 0x655A788E, 0x267D6E95, 0xFFAE7321, 0x5CE9C0B7, 0x6EF9BFAB},
	{0x10F9D874, 0x8B7E6CA3, 0x67B6EAEC, 0x0AD9BC40, 0x0EE4E925, 0x24CBC156, 0xF241C874, 0x4927C74A} } ,
	 { {0xA059060D, 0x42F5AD7B, 0xE09580DC, 0x7EB69CB7, 0xB65A8604, 0x95DD690A, 0x91D72253, 0x87BA94E2},
	{0x265A1C50, 0x471DE6BB, 0xD98665A4, 0xB76D857F, 0x73C650AC, 0x414540F7, 0x1ABE7C5E, 0x84301828} } ,
	 { {0x63B299B1, 0xE61FB809, 0xB4626A3C, 0x8FBD9056, 0xC0CD67A2, 0xE9F944FA, 0x73CD3E13, 0x210EFF63},
	{0x6961B272, 0xE512A1D5, 0x804A7301, 0x9EB43D3B, 0x5718F4B1, 0x122AC982, 0xE0D57780, 0x89F25F41} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5329 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5330 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5331 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5332 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5333 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5334 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5335 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x14A26563, 0x4B5A007B, 0x29A3AAC8, 0x403C20B5, 0x1E2AC9C6, 0x81DCEA2C, 0x9381D5E3, 0x7C2F2D55},
	{0xEF7E8D6A, 0x79B0F116, 0x95A83F73, 0xA7463CA0, 0xD29F1E81, 0xBBEE4E8F, 0x3738D0C9, 0x637F9ECC} } ,
	 { {0x8E68FA04, 0x1D45770D, 0x8889C1FD, 0xEE32B1F5, 0xA6BE2AB4, 0x403CE3F5, 0xA33C58F6, 0x9D150692},
	{0x6C9BE59A, 0xD4DAE73C, 0xFFEF5797, 0x685F6BDD, 0xFC02100F, 0x56CE6F45, 0x9FB4475F, 0x288B572D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x14A26563, 0x4B5A007B, 0x29A3AAC8, 0x403C20B5, 0x1E2AC9C6, 0x81DCEA2C, 0x9381D5E3, 0x7C2F2D55},
	{0xEF7E8D6A, 0x79B0F116, 0x95A83F73, 0xA7463CA0, 0xD29F1E81, 0xBBEE4E8F, 0x3738D0C9, 0x637F9ECC} } ,
	 { {0xD3C33A97, 0xE1A912A3, 0x4BEE1D49, 0x24DEFAAB, 0xAD245F00, 0xBB237875, 0x9CE28332, 0x1CFE982F},
	{0xF5904F01, 0x2A13A274, 0xD48887AF, 0xAAB240C2, 0x57E079A5, 0xA491ED25, 0xA06A94C9, 0x91884794} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5336 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5337 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5338 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5339 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5340 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0B50FAB3, 0x3BE098F4, 0xE3A9EA6D, 0x5D1A0293, 0x50E2D4E1, 0x2AC7716F, 0x3B203841, 0x701C1B92},
	{0x96F0F81C, 0xBAD78BB0, 0x2434E6F6, 0x274AE210, 0xA2F53EDA, 0x148DE946, 0x6D144971, 0x09500CA4} } ,
	 { {0x7795DF1D, 0x585F3195, 0x599CCE23, 0xBA0D7F40, 0x5001712F, 0xFA0CED8B, 0xCB1C428E, 0x38B65E6D},
	{0x0F85FBCD, 0x5082B292, 0x0DF71A31, 0xD8C1F513, 0x3F1BB5FC, 0x980CE9F9, 0xC591F76F, 0x19B6C607} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x0B50FAB3, 0x3BE098F4, 0xE3A9EA6D, 0x5D1A0293, 0x50E2D4E1, 0x2AC7716F, 0x3B203841, 0x701C1B92},
	{0x96F0F81C, 0xBAD78BB0, 0x2434E6F6, 0x274AE210, 0xA2F53EDA, 0x148DE946, 0x6D144971, 0x09500CA4} } ,
	 { {0xEA96557E, 0xA68F581B, 0x7ADB1123, 0x59042D60, 0x03E11885, 0x01536EE0, 0x7502999A, 0x815D4054},
	{0x52A638CE, 0xAE6BD71F, 0xC680C515, 0x3A4FB78D, 0x14C6D3B8, 0x63537272, 0x7A8CE4B9, 0xA05CD8BA} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5341 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5342 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5343 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5344 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5345 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x28248349, 0x63C929E4, 0xF400B212, 0x5DC2785F, 0xF0F5D002, 0x99C5A502, 0x8C4A278B, 0xA95BB22A},
	{0x6FA0D7BF, 0xD9EB31DF, 0x57B47A24, 0xA1888E4C, 0x3A62FFF0, 0x07F64059, 0xE909E563, 0x310A8DAF} } ,
	 { {0xD245CD3D, 0x66DAF7E7, 0xE22A6BE6, 0x057352E1, 0x4C21B8DF, 0xD5078AEF, 0x939A44B0, 0x11A2BF97},
	{0xE865412A, 0xB48FD58E, 0xB6385773, 0x3FC5AD43, 0x75ACC882, 0xC02F7C02, 0x7497B4ED, 0x92570C2D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x28248349, 0x63C929E4, 0xF400B212, 0x5DC2785F, 0xF0F5D002, 0x99C5A502, 0x8C4A278B, 0xA95BB22A},
	{0x6FA0D7BF, 0xD9EB31DF, 0x57B47A24, 0xA1888E4C, 0x3A62FFF0, 0x07F64059, 0xE909E563, 0x310A8DAF} } ,
	 { {0x8FE6675E, 0x981391C9, 0xF24D7360, 0x0D9E59BE, 0x07C0D0D6, 0x2658D17C, 0xAC849778, 0xA870DF2A},
	{0x79C6F371, 0x4A5EB422, 0x1E3F87D3, 0xD34BFF5D, 0xDE35C132, 0x3B30E068, 0xCB87273B, 0x27BC9294} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5346 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5347 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5348 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5349 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5350 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8D6DA417, 0xF4FC14FA, 0x5049491B, 0xD87EA6EC, 0x25665208, 0xB02085CD, 0x30480FD8, 0x5F9F87C4},
	{0xD7776E5F, 0x141D087E, 0x3E7FE010, 0xC8A17268, 0xE079E8AB, 0xBF84041A, 0x10FBA8AB, 0x0FCF3D90} } ,
	 { {0x4DEC0190, 0x48380198, 0x2509A21D, 0x1DF23C44, 0xAA864805, 0xE97CAA2D, 0x32EC0EF4, 0x62EF7388},
	{0xEA00F6A7, 0xB8CABFE8, 0x30681677, 0x25B2735A, 0x2D19988E, 0xE85D5F4A, 0xB2BFFB92, 0x7CFA0C0A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8D6DA417, 0xF4FC14FA, 0x5049491B, 0xD87EA6EC, 0x25665208, 0xB02085CD, 0x30480FD8, 0x5F9F87C4},
	{0xD7776E5F, 0x141D087E, 0x3E7FE010, 0xC8A17268, 0xE079E8AB, 0xBF84041A, 0x10FBA8AB, 0x0FCF3D90} } ,
	 { {0x1440330B, 0xB6B68819, 0xAF6E3D29, 0xF51F705C, 0xA95C41AF, 0x11E3B23D, 0x0D32CD34, 0x57242B3A},
	{0x782B3DF4, 0x4623C9C8, 0xA40FC8CF, 0xED5F3946, 0x26C8F126, 0x1302FD21, 0x8D5EE096, 0x3D1992B7} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5351 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5352 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5353 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5354 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5355 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x00ED8B5B, 0xE3BE80A9, 0x3236FA6A, 0x0079FC82, 0xA0F57661, 0x2EA673A6, 0x3D7C6971, 0x08BDD581},
	{0x6378DFBA, 0x6F11CC89, 0x581755E9, 0xD6F67F48, 0x80BFAE76, 0x1F4BECB2, 0x54A241F9, 0x858688D3} } ,
	 { {0x2CE1DEB3, 0xC60D6883, 0x0B1DF3F1, 0xA1129C82, 0xB96BF3A9, 0x1FF2D49B, 0x6C9771E7, 0xB33CAD64},
	{0xE6C3A453, 0xEE9C25F9, 0x3AEC31E4, 0x6F4192B5, 0x3CBE9BC1, 0x8D4B0F10, 0x5304605E, 0x4A927C5D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00ED8B5B, 0xE3BE80A9, 0x3236FA6A, 0x0079FC82, 0xA0F57661, 0x2EA673A6, 0x3D7C6971, 0x08BDD581},
	{0x6378DFBA, 0x6F11CC89, 0x581755E9, 0xD6F67F48, 0x80BFAE76, 0x1F4BECB2, 0x54A241F9, 0x858688D3} } ,
	 { {0x354A55E8, 0x38E1212E, 0xC959EB55, 0x71FF101E, 0x9A76960B, 0xDB6D87CF, 0xD3876A41, 0x06D6F15D},
	{0x7B689048, 0x105263B7, 0x998BAD62, 0xA3D019EB, 0x1723EDF3, 0x6E154D5B, 0xED1A7BCA, 0x6F812264} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5356 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5357 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5358 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5359 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5360 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x797B4344, 0x3B18F75C, 0xBD76AFC3, 0x90B5B18C, 0x766F8033, 0x021EBC42, 0x10DB2C2E, 0x90C1C494},
	{0x2B5B3A6A, 0x67742C23, 0x7C62B94F, 0x8B3104E8, 0x7A61305C, 0x924B5B36, 0x39899CD6, 0xA1B6B34B} } ,
	 { {0x2173E9E0, 0x4B65D960, 0x8481006C, 0xC055C8E2, 0x5ED45408, 0x91FFE024, 0x19EDE4D6, 0x60BF1AF6},
	{0x340BD0C3, 0x623CAEB2, 0x22B44F16, 0xF39EA72D, 0xA2917C6A, 0x3BE12000, 0xF2FC7AB4, 0x0AF19080} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x797B4344, 0x3B18F75C, 0xBD76AFC3, 0x90B5B18C, 0x766F8033, 0x021EBC42, 0x10DB2C2E, 0x90C1C494},
	{0x2B5B3A6A, 0x67742C23, 0x7C62B94F, 0x8B3104E8, 0x7A61305C, 0x924B5B36, 0x39899CD6, 0xA1B6B34B} } ,
	 { {0x40B84ABB, 0xB388B051, 0x4FF6DEDA, 0x52BBE3BE, 0xF50E35AC, 0x69607C46, 0x2630F752, 0x595483CC},
	{0x2E2063D8, 0x9CB1DAFF, 0xB1C39030, 0x1F730573, 0xB1510D4A, 0xBF7F3C6A, 0x4D226174, 0xAF220E41} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5361 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5362 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5363 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5364 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5365 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3D428908, 0x15776234, 0x6737753A, 0xCAA24DE4, 0x47B40B05, 0x03CD441F, 0x93C6E6F2, 0x6CF5B2BF},
	{0x55380110, 0x95325378, 0xA792DE9D, 0x8A00320C, 0xFD9AE413, 0x87B21EDE, 0xA5BAEB4A, 0xAA7CF22D} } ,
	 { {0xC5285A5F, 0xF6774A79, 0x3C28BB1C, 0x2CF91607, 0xFACBDCF3, 0x81AC84A3, 0x0594E95A, 0x45A5A227},
	{0xD14EED82, 0x67840712, 0xC93782AA, 0x9BF05A22, 0x55D2E253, 0xFA7FA068, 0x69BB7A94, 0x351805FE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3D428908, 0x15776234, 0x6737753A, 0xCAA24DE4, 0x47B40B05, 0x03CD441F, 0x93C6E6F2, 0x6CF5B2BF},
	{0x55380110, 0x95325378, 0xA792DE9D, 0x8A00320C, 0xFD9AE413, 0x87B21EDE, 0xA5BAEB4A, 0xAA7CF22D} } ,
	 { {0x9D03DA3C, 0x08773F37, 0x984F242A, 0xE6189699, 0x5916ACC1, 0x79B3D7C7, 0x3A89F2CE, 0x746DFC9B},
	{0x90DD4719, 0x976A829E, 0x0B405C9C, 0x7721527E, 0xFE0FA761, 0x00E0BC02, 0xD6636194, 0x84FB98C3} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5366 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5367 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5368 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5369 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5370 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD880EA32, 0x598B173B, 0x91A316AB, 0xE1998AE6, 0x291186B0, 0xB5CE8110, 0x772E565A, 0x82060F75},
	{0x17F74AEB, 0x4ECE1B8B, 0x82D7CD2B, 0xC45B56B7, 0x6E1E9B2F, 0xAB265DE6, 0xD22E3703, 0x159AC80E} } ,
	 { {0xEF08D5C6, 0x17C79836, 0x0F4A46ED, 0xECFB2AC7, 0x1DF925BA, 0x6D5059BF, 0x96B103C3, 0x1DBC6433},
	{0x0AEC3B03, 0xF2595AA3, 0xFEB73367, 0xBD9DD575, 0xF7B1682A, 0x0B9C7BD2, 0x215E9844, 0x13E87418} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD880EA32, 0x598B173B, 0x91A316AB, 0xE1998AE6, 0x291186B0, 0xB5CE8110, 0x772E565A, 0x82060F75},
	{0x17F74AEB, 0x4ECE1B8B, 0x82D7CD2B, 0xC45B56B7, 0x6E1E9B2F, 0xAB265DE6, 0xD22E3703, 0x159AC80E} } ,
	 { {0x73235ED5, 0xE726F17A, 0xC52D9859, 0x261681D9, 0x35E963FA, 0x8E1002AC, 0xA96DD865, 0x9C573A8E},
	{0x573FF998, 0x0C952F0E, 0xD5C0ABDF, 0x5573D72A, 0x5C31218A, 0xEFC3E098, 0x1EC043E4, 0xA62B2AAA} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5371 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5372 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5373 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5374 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5375 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x085F457A, 0xFCB92132, 0x1A343810, 0x3182CCDD, 0x0AFAAE40, 0x6355DBA3, 0x7FEABAFB, 0x8977BB5D},
	{0x3C460269, 0x058B06F7, 0xF3923913, 0x606809CD, 0x94E76B07, 0x8D4EA463, 0x07922E7C, 0x2E7DDEF6} } ,
	 { {0x8405FE40, 0xA96EF885, 0x9D4B2653, 0x266F25C0, 0x0C2059C1, 0x8259F8FD, 0xDDEB0096, 0x64CA36A7},
	{0x84DA5D19, 0x679BAA50, 0xD5496368, 0x05EB3E6D, 0x94C0D5B9, 0x7CDBC5A7, 0x82EED732, 0x2D1D703E} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x085F457A, 0xFCB92132, 0x1A343810, 0x3182CCDD, 0x0AFAAE40, 0x6355DBA3, 0x7FEABAFB, 0x8977BB5D},
	{0x3C460269, 0x058B06F7, 0xF3923913, 0x606809CD, 0x94E76B07, 0x8D4EA463, 0x07922E7C, 0x2E7DDEF6} } ,
	 { {0xDE26365B, 0x557F912B, 0x372CB8F3, 0xECA286E0, 0x47C22FF3, 0x7906636E, 0x6233DB92, 0x5549681A},
	{0xDD51D782, 0x9752DF60, 0xFF2E7BDE, 0x0D266E32, 0xBF21B3FC, 0x7E8496C3, 0xBD3004F6, 0x8CF62E83} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5376 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5377 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5378 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5379 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5380 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5381 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5382 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x4BEA496A, 0x386B2D8C, 0x1F6EFA61, 0x22A92332, 0x97932810, 0x69AD5146, 0xC38B5626, 0x68FA142B},
	{0xEC00C8DF, 0x6F5DE277, 0x698C372B, 0xDAEF7237, 0x08F2EB1B, 0xC8ABFACA, 0x0AFC017D, 0x373B153D} } ,
	 { {0x956EB3DF, 0x3C6C3CF1, 0x0CB98FBD, 0x4E34BAFF, 0xE9584CB0, 0x28A22A5D, 0x202CB0B3, 0x3B166528},
	{0x192D2A0D, 0xB1C116E5, 0x852307F2, 0x4D504A0D, 0x42FD3C5D, 0x7EB0C1D7, 0xA663D3A1, 0x37C09A04} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x4BEA496A, 0x386B2D8C, 0x1F6EFA61, 0x22A92332, 0x97932810, 0x69AD5146, 0xC38B5626, 0x68FA142B},
	{0xEC00C8DF, 0x6F5DE277, 0x698C372B, 0xDAEF7237, 0x08F2EB1B, 0xC8ABFACA, 0x0AFC017D, 0x373B153D} } ,
	 { {0xCCBD80BC, 0xC2824CBF, 0xC7BE4F89, 0xC4DCF1A1, 0x6A8A3D04, 0xD2BE320D, 0x1FF22B75, 0x7EFD399A},
	{0x48FF0A8E, 0x4D2D72CC, 0x4F54D754, 0xC5C16293, 0x10E54D57, 0x7CAF9A94, 0x99BB0887, 0x825304BD} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5383 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5384 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5385 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5386 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5387 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5388 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5389 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x25DD59B5, 0xEE14C8B8, 0xA69B9A51, 0x66F3820E, 0xA780EB1C, 0x0B1BAD8E, 0x43F3F215, 0xABFB9831},
	{0x8106E413, 0xF10B7343, 0xB5296F54, 0xEF03B246, 0x7F42B7E3, 0x92CC85DA, 0xE0473754, 0x10940995} } ,
	 { {0xDCF44148, 0x0DA5B291, 0x1B3D9D50, 0xCDF88936, 0x08CD1D9F, 0x3E6461FD, 0xE1327893, 0x456D49EE},
	{0x4274ADC1, 0x17854AC4, 0xDC353FD0, 0xA1ECB78B, 0xC181730C, 0x2E35728B, 0x0E50DB61, 0x5A22FE53} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x25DD59B5, 0xEE14C8B8, 0xA69B9A51, 0x66F3820E, 0xA780EB1C, 0x0B1BAD8E, 0x43F3F215, 0xABFB9831},
	{0x8106E413, 0xF10B7343, 0xB5296F54, 0xEF03B246, 0x7F42B7E3, 0x92CC85DA, 0xE0473754, 0x10940995} } ,
	 { {0x8537F353, 0xF148D71F, 0xB93A41F6, 0x4519236A, 0x4B156C15, 0xBCFBFA6E, 0x5EEC6395, 0x74A654D3},
	{0x1FB786DA, 0xE7693EED, 0xF8429F76, 0x7124F514, 0x926116A8, 0xCD2AE9DF, 0x31CE00C7, 0x5FF0A06F} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5390 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5391 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5392 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5393 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5394 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5395 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5396 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6A6D80F8, 0x49EACF0E, 0xEAE260EE, 0x56967DD6, 0x2B89D72C, 0xAA1E5E18, 0xFAD23C31, 0xAD04FBA6},
	{0x0C9D9F36, 0x46F9086B, 0xB1FD116D, 0xA0E9DBF1, 0xE6EE83FC, 0xCD882699, 0x12E2515B, 0x04F643C2} } ,
	 { {0x3A3AAA4A, 0x5CB2CCC2, 0xC3032EF3, 0xF9EA9F35, 0x39E62E7D, 0xBD978F8D, 0xEFB3B2A8, 0x7D781D9F},
	{0x8BEE7F20, 0xE90D023A, 0x707B6306, 0x5A0CB42A, 0xD7689E30, 0x44F07178, 0xFEFCB460, 0x63A5DB66} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x6A6D80F8, 0x49EACF0E, 0xEAE260EE, 0x56967DD6, 0x2B89D72C, 0xAA1E5E18, 0xFAD23C31, 0xAD04FBA6},
	{0x0C9D9F36, 0x46F9086B, 0xB1FD116D, 0xA0E9DBF1, 0xE6EE83FC, 0xCD882699, 0x12E2515B, 0x04F643C2} } ,
	 { {0x27F18A51, 0xA23BBCEF, 0x1174B053, 0x19270D6B, 0x19FC5B37, 0x3DC8CCDE, 0x506B2980, 0x3C9B8122},
	{0xD63DB57B, 0x15E18776, 0x63FC7C40, 0xB904F876, 0x7C79EB84, 0xB66FEAF2, 0x412227C8, 0x566DC35B} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5397 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5398 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5399 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5400 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5401 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5402 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5403 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x29084D69, 0xFDF218A9, 0x12D86079, 0xBBD5D8D4, 0x7CDBA8DE, 0x15BD26C5, 0x318CEE82, 0x08420775},
	{0x251C3A65, 0x79F728CB, 0x70677AE4, 0x637A412D, 0xC4DC2770, 0xFBEC9B75, 0xD1F9C8F4, 0x95FD9BF9} } ,
	 { {0xD8F7474E, 0x4D72E513, 0xAFAD2FD3, 0x9C761F27, 0x005F1B2A, 0x51AEFEFD, 0x9ACE2806, 0x3F7CCFDE},
	{0x644D1580, 0x4C89E792, 0x1B97974F, 0x93BDF44F, 0x9CC74765, 0x609AC5D3, 0x1DD1139B, 0x5CF92C54} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x29084D69, 0xFDF218A9, 0x12D86079, 0xBBD5D8D4, 0x7CDBA8DE, 0x15BD26C5, 0x318CEE82, 0x08420775},
	{0x251C3A65, 0x79F728CB, 0x70677AE4, 0x637A412D, 0xC4DC2770, 0xFBEC9B75, 0xD1F9C8F4, 0x95FD9BF9} } ,
	 { {0x8934ED4D, 0xB17BA49D, 0x24CAAF73, 0x769B8D79, 0x53836E8A, 0xA9B15D6E, 0xA550B422, 0x7A96CEE3},
	{0xFDDF1F1B, 0xB264A21E, 0xB8E047F7, 0x7F53B851, 0xB71B424F, 0x9AC59697, 0x224DC88D, 0x5D1A726E} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5404 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5405 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5406 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5407 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5408 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5409 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5410 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3DC0A047, 0x0ECC68EF, 0xF21AF7F5, 0x6777521C, 0x8A60EE6C, 0xF55F954F, 0x4D3BB44C, 0x26A81610},
	{0x4640EF67, 0x5682890B, 0xC2B4386E, 0x5BCF13B5, 0x142B9494, 0xC2B8863B, 0xE8119827, 0x5AFF87A0} } ,
	 { {0x15E99365, 0x082758FA, 0x8E69213D, 0xC3324764, 0x5AFD5D58, 0xCD8849FF, 0x77467481, 0x37DABBCD},
	{0x5B936DCE, 0xFF6B7756, 0x4A644DA9, 0x30301670, 0xF9EB5359, 0x48ECCC09, 0x29F77CEA, 0x4CF5CA78} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3DC0A047, 0x0ECC68EF, 0xF21AF7F5, 0x6777521C, 0x8A60EE6C, 0xF55F954F, 0x4D3BB44C, 0x26A81610},
	{0x4640EF67, 0x5682890B, 0xC2B4386E, 0x5BCF13B5, 0x142B9494, 0xC2B8863B, 0xE8119827, 0x5AFF87A0} } ,
	 { {0x4C42A136, 0xF6C730B7, 0x460EBE09, 0x4FDF653C, 0xF8E52C5C, 0x2DD8126B, 0xC8D867A7, 0x8238E2F4},
	{0x0698C6CD, 0xFF83125B, 0x8A13919C, 0xE2E19630, 0x59F7365B, 0xB2739061, 0x16275F3E, 0x6D1DD44A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5411 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5412 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5413 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5414 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5415 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5416 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5417 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAD48E9FB, 0x2A7E67D6, 0xA5A10A49, 0x91A61386, 0xBAD784CA, 0x55A852DD, 0x6E367E32, 0x9D65FCCF},
	{0xEB68BFE1, 0x343F9BE3, 0x3AC1D4B3, 0x2500840E, 0xCDF28E55, 0xF300E1E7, 0xC4C7CF6C, 0x81D9ABD0} } ,
	 { {0x513B4EFD, 0x1F561E24, 0x201990B1, 0xFE59EDC8, 0xFC4D4EAE, 0x164BB16D, 0x4F0344AD, 0x04E44574},
	{0xC75C13BE, 0x1A0EB804, 0xAD12A0F9, 0x10567B62, 0x4004DA33, 0x5968E2C1, 0xE07F9C1D, 0x15E95D9F} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xAD48E9FB, 0x2A7E67D6, 0xA5A10A49, 0x91A61386, 0xBAD784CA, 0x55A852DD, 0x6E367E32, 0x9D65FCCF},
	{0xEB68BFE1, 0x343F9BE3, 0x3AC1D4B3, 0x2500840E, 0xCDF28E55, 0xF300E1E7, 0xC4C7CF6C, 0x81D9ABD0} } ,
	 { {0x10F0E59E, 0xDF986B8D, 0xB45E4E95, 0x14B7BED8, 0x57953B06, 0xE514AAFD, 0xF11B977B, 0xB52F594D},
	{0x9AD020DD, 0xE4DFD1AC, 0x27653E4D, 0x02BB313E, 0x13DDAF82, 0xA1F779AA, 0x5F9F400B, 0xA42A4122} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5418 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5419 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5420 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5421 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5422 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5423 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5424 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8EEAA8E4, 0x4E16AB4D, 0x49519395, 0x63D7CB5E, 0xDE95552E, 0xD6724C7B, 0x0E75AA3C, 0x075D8862},
	{0xD29A4428, 0xE1847EEF, 0x89F45F75, 0x0692FCCF, 0x338F6519, 0xDA44E3EC, 0xC2BE98AC, 0x0449216D} } ,
	 { {0xFC312B06, 0xC6BF57ED, 0x660CBD82, 0x85176233, 0x167E0C95, 0x572C13A4, 0x18CB146D, 0x53D63693},
	{0xE03CE22F, 0xA7D477FC, 0x04FA09EE, 0x4A3AD725, 0xA18B8E0F, 0xE0BD3EFF, 0xB4B9AB2E, 0x8EA17F57} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8EEAA8E4, 0x4E16AB4D, 0x49519395, 0x63D7CB5E, 0xDE95552E, 0xD6724C7B, 0x0E75AA3C, 0x075D8862},
	{0xD29A4428, 0xE1847EEF, 0x89F45F75, 0x0692FCCF, 0x338F6519, 0xDA44E3EC, 0xC2BE98AC, 0x0449216D} } ,
	 { {0x65FB0995, 0x382F31C3, 0x6E6B21C4, 0x8DFA4A6D, 0x3D647D1F, 0xA43448C7, 0x2753C7BB, 0x663D682F},
	{0x81EF526C, 0x571A11B4, 0xCF7DD558, 0xC8D6D57B, 0xB256FBA5, 0x1AA31D6B, 0x8B6530FA, 0x2B721F6A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5425 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5426 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5427 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5428 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5429 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5430 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5431 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5432 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5433 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5434 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5435 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5436 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0x9B4B229E, 0x8713215B, 0x21DCAC37, 0x14CC2C47, 0xE12F7342, 0x2F532213, 0x4645A982, 0x875EF897},
	{0x01ABC06C, 0x63C4341E, 0x8B8051C9, 0x21990463, 0xD16ED649, 0xF0B6C9D8, 0x8B772478, 0x9B10B6EF} } ,
	 { {0xCD6CB02B, 0xA5F80739, 0x4E5473B8, 0x9E92767F, 0x504677FB, 0x3BED2325, 0x12D4A179, 0x77A1FA06},
	{0xEBDB98CF, 0x677B616A, 0x999D473E, 0x0DBDF309, 0x26925630, 0x310B9879, 0x3C2B5FA4, 0x9A8805F7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5437 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5438 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5439 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5440 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5441 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0xAE4A7AAD, 0x8420183E, 0xFCA864F9, 0x877B7807, 0xCB484931, 0xD292082A, 0xDC38A24D, 0xA8074636},
	{0x00738CD7, 0x2B2D8B42, 0xC986B4E8, 0x9315ACBD, 0x19E5FF3B, 0x01355B49, 0x1198758E, 0x7684CC32} } ,
	 { {0x7B7F0BFE, 0xD335D9CF, 0xE1126889, 0x2AAAB2E6, 0x7F7F9C1A, 0xDD6253CD, 0x60EA6D21, 0xAA29F74E},
	{0x8A56ACF5, 0x8DF4DABE, 0xB65DFD14, 0xE25A65C6, 0x6C6491F3, 0x55B5C993, 0x46DED3BE, 0x82395740} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5442 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5443 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5444 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5445 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5446 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0x62B5DD34, 0x2A705444, 0x449F1AB7, 0x906B02D8, 0xF233DC75, 0xF9DCC242, 0x5536246B, 0x5A45DC1B},
	{0x414EF64D, 0x40400FA0, 0x5A31AC70, 0xB4089614, 0x1569ADDB, 0xF49435B8, 0x00F2D1BE, 0x16A1CF92} } ,
	 { {0x6B38584A, 0xD1CFF3A1, 0x3F16A788, 0xB6CD86BE, 0x248CFC5B, 0xFE40D6A8, 0x06DE0B88, 0xA0AA72A6},
	{0x1A681950, 0x3EBB86E8, 0x4650953A, 0x5DA463D5, 0xDF9AB342, 0x5726BC82, 0xB87342D4, 0x345DC4E6} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5447 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5448 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5449 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5450 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5451 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDE4A4459, 0x88C92DD4, 0xCE4795B0, 0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176},
	{0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2, 0xB6436EE8, 0x2180F37C, 0x6B994492} } ,
	 { {0xBDEEBD2F, 0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786, 0x1C93D08B},
	{0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633} } ,
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static ecpoint_fp2 var_expected = { { {0x57BB86E7, 0x3177F534, 0x56F4C0C5, 0xC0D87743, 0x21E1D7E4, 0x4C1D1CAD, 0x0E2CDCD6, 0xA6BBCFB6},
	{0x457D0BA6, 0x2875C1F9, 0x64820883, 0xB4185F27, 0xF1856CA6, 0x8F62D480, 0xAB2881D8, 0x24B642FC} } ,
	 { {0xC7B23B8D, 0x37D8BF10, 0x982158AC, 0xF0EB0879, 0x54E24FC7, 0x4FD6A27D, 0x65624305, 0x9723FC7B},
	{0x1ABD4F7F, 0x16ECB0C2, 0x9E2CDDD9, 0x359187FD, 0xB30A4DDF, 0xBFE64C04, 0xB34C33A0, 0x6AEDA9E7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5452 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5453 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5454 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5455 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5456 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x55D9A7C1, 0x824B570A, 0x378AF4DF, 0xB7A867B9, 0x70E3250C, 0x23478187, 0xB091E8A7, 0x93A9A0D0},
	{0x091B84DA, 0x528F5C60, 0xD9C79EF7, 0x0B5AB59E, 0x58AFD9C7, 0x869C5B62, 0xA26724D7, 0xB0B45E11} } ,
	 { {0x3F5B4390, 0xBA480ED5, 0xB27BDA16, 0x62A854D2, 0x3DDD9106, 0x359985AD, 0x18515ECE, 0x8A57F501},
	{0x38CD0BA5, 0xB5BD33A6, 0x0F438D70, 0xD1FDBDC5, 0x358A384D, 0x0E8C06D9, 0xB789926C, 0x4659124F} } ,
	0};
		static bigint_t var_k = {0x0A1557B6, 0x376EC235, 0x216F0663, 0x8B636481, 0xC03DF2BC, 0xEEA3CB3B, 0xBF131E29, 0x6BE37F6A};
		static ecpoint_fp2 var_expected = { { {0xC4DEC83F, 0xF900B3C4, 0xBCAA11A1, 0xE69C9ECE, 0x63321B92, 0xF170BBF3, 0xE668367C, 0x6EDD4232},
	{0x0DE0FF86, 0xC4949FE9, 0x1B7B0DF6, 0xFC9482E4, 0xF5672EF4, 0xFBB623AB, 0xEF82E45E, 0xB4FAA53C} } ,
	 { {0xF387CC9F, 0x3BE0E44F, 0x42E4584B, 0x8718B835, 0x2326089E, 0xD4C8CA32, 0xFFD84A1A, 0xA8F74BB7},
	{0x24CC5ACC, 0x6AF85CE0, 0x7858708D, 0xD5334639, 0x379A96D2, 0x3A0F8F1C, 0x131FBB31, 0x0B425368} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5457 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5458 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5459 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5460 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5461 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x671E2A02, 0x33BBA0CC, 0xC88D2681, 0x7C0359B9, 0xBFEB5802, 0x1E1C6722, 0x59C7E7FC, 0x86CDF7FD},
	{0xF5555C4E, 0x98C5A8BA, 0xA9EE5B65, 0x136583BA, 0xCE0F90B5, 0x3DB026D9, 0x3CEDBE1F, 0x222CEF10} } ,
	 { {0x792E9567, 0x7D9FA655, 0x60FBAF24, 0x5C0F0F9E, 0x0FBAE59B, 0xBEF023EC, 0x3A3875A3, 0x1CB82A9F},
	{0x0A068AB6, 0x1E1A351A, 0xB51F41CE, 0x9665E42D, 0x5CF9AD65, 0x4B7B2482, 0x3DFC45B9, 0x7CCA7FB9} } ,
	0};
		static bigint_t var_k = {0x15750A3E, 0xA3DBB2B5, 0xA3B4BB13, 0xCDF46F01, 0x457EE9BA, 0xE5066365, 0x90A1F750, 0xB54D28BB};
		static ecpoint_fp2 var_expected = { { {0x3F238F16, 0x2A59550C, 0xBA8B5151, 0x729D2FDE, 0xCD4F1E44, 0x92D849F3, 0x769A2D28, 0x34AB69BE},
	{0x3D7EF43A, 0x4C5F6EDF, 0xFD1181B3, 0x923C585C, 0xA648AE2C, 0x3250974F, 0xAFAA0C5A, 0x14B3E34E} } ,
	 { {0xF884F6F3, 0x00E83633, 0x225BAD18, 0xE1711648, 0x6447A88C, 0x939CE3EE, 0xB2CC6BB3, 0xB13813AD},
	{0xF649E27F, 0xCD5CF2DD, 0x38BF2095, 0xB15802E3, 0xF9344772, 0x2AC68E1D, 0x689D5599, 0x9956B50A} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5462 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5463 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5464 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5465 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5466 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7876C5C4, 0x32EA8D8F, 0x069E0805, 0x018A35A9, 0x3790E9CE, 0x3DBB75A8, 0x4CFF6131, 0x9E6B0480},
	{0x504EBBB0, 0x8DCCDB82, 0x5FF07F1C, 0x9CE069CE, 0x7AFFC839, 0xF84D7D3F, 0x9199F74F, 0x30FA99F8} } ,
	 { {0x7602713B, 0x53B163D3, 0xB4639506, 0xD33A4619, 0x3174E8CD, 0x2FAB5D2C, 0x0D376F7C, 0x7BBBDEDB},
	{0xDCC6B3DE, 0x4038DF68, 0xAD44D041, 0x1AE013AA, 0x0400B395, 0x03A61055, 0x8E172902, 0xA5C9E2DC} } ,
	0};
		static bigint_t var_k = {0x15CE2D3F, 0x82B52999, 0xF8B3334D, 0xAC2189E3, 0x104668D0, 0x6A3AA49F, 0x67B73930, 0xE1B114B0};
		static ecpoint_fp2 var_expected = { { {0x544DD6EF, 0xF7B1F270, 0x194B1CDD, 0xFE9A12A6, 0x8FD84CE6, 0x6137C317, 0x1663CA7B, 0x823181A4},
	{0x44B76138, 0x031C1C0D, 0x54DC769B, 0x4165E5E5, 0xF7C5153C, 0x08917E83, 0xB0AD1CE4, 0x813D4E93} } ,
	 { {0xCA31316E, 0xCF31F8B7, 0x443AFFDA, 0x159DDD91, 0xCAC1573C, 0xDF8B0545, 0x7AD29FC6, 0x35F9F52E},
	{0x930C76B1, 0xA60786B4, 0x6D97EDFD, 0x8B34FF1E, 0xD27755CB, 0x5CCB84ED, 0x1DE61DD7, 0x24096B5B} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5467 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5468 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5469 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5470 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5471 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE84E5C63, 0x7A02D698, 0x78E157AF, 0x4DB01F17, 0xC732B76C, 0xC6E79016, 0xE265FD0C, 0x76731575},
	{0x56947C79, 0x3360CE6E, 0x051C7FDA, 0x722268F6, 0xE9FAA7FB, 0x807E51FB, 0xC9497741, 0x59AC5374} } ,
	 { {0xB8265833, 0x5FBAAD09, 0xE9FB0959, 0x20E255C6, 0xD64D13C9, 0x28A73041, 0x50A08542, 0x1B60A8C0},
	{0xE182AECF, 0x5E8177B9, 0xD5D0AFCF, 0x43BC60F3, 0x5EC47FA3, 0xFB2F1CC2, 0xBAE5250D, 0x922CE984} } ,
	0};
		static bigint_t var_k = {0x50D869B8, 0x0DCE1B84, 0x9D98D2E0, 0x77598E1E, 0x1683AEF5, 0x274FB862, 0xF1725784, 0x309C129A};
		static ecpoint_fp2 var_expected = { { {0x6E11F9A1, 0xE523F9F6, 0x0D690A7B, 0x7017E651, 0x6EEAE708, 0xA8086384, 0xEF25FAE5, 0x68C2C8BE},
	{0x881D6E57, 0xFCA0950C, 0xD0386008, 0xBFD54AC2, 0xD671374E, 0xBB236F15, 0xAD899286, 0x474D648E} } ,
	 { {0xBD99A56F, 0xCCF4A0CA, 0xE22A0730, 0xB8400335, 0x2D389E33, 0xFC648CB2, 0xF548D6C5, 0x5DEF319C},
	{0x6379575D, 0x8DD1C149, 0x28AC693A, 0xD2F248BA, 0x7C11D7EA, 0x586A8E74, 0x23E9A3AD, 0xA606D7E8} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5472 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5473 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5474 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5475 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5476 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0AD6F4AC, 0xB907ADB6, 0xDC4B351C, 0x77E92F1D, 0xB3A08E0F, 0xB9E83E68, 0xC4FC4742, 0x7CC2940F},
	{0x20DBFC55, 0x25C89B59, 0x61570E3C, 0x307380AA, 0x3BFACFB6, 0x4DD6BE03, 0x1BDCDD6C, 0x8E231D4D} } ,
	 { {0x7E45E8B6, 0x447579E1, 0x39D5BBF5, 0x3193F17A, 0x8552026D, 0x7B64E71B, 0x1B982F86, 0x1E1ADD53},
	{0x06178CA7, 0x515E8477, 0xDC41399B, 0x9F2946A9, 0x5C8E65EB, 0x9075B9F6, 0xC8F91603, 0xA1D39FD8} } ,
	0};
		static bigint_t var_k = {0x4BE74903, 0xBCF72AA3, 0x50670256, 0xC0818CEE, 0x8D8AD765, 0x04D2C16F, 0x1BB72AA0, 0x222BDF85};
		static ecpoint_fp2 var_expected = { { {0x2F04D695, 0x9F01866E, 0x444D040B, 0xB9AF17B7, 0x5C364D82, 0x738B4DC6, 0x6C8EE585, 0x64F363CC},
	{0x4AFE53F9, 0xE4111F79, 0xDD89A71D, 0x935E5D83, 0xB2354173, 0xFDB6240D, 0x997F8551, 0x8D67A25D} } ,
	 { {0x314D6401, 0x1489A56B, 0x148B47E9, 0x8B94F93C, 0x0AC9F927, 0xAC1DB2DD, 0xEFC189BF, 0xB041A2EE},
	{0xE4087A3B, 0xB0909E1D, 0x12DABE6F, 0x241F7A46, 0x39C9A267, 0x6E4C1A4E, 0x4A5DB967, 0x2FD6757B} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5477 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5478 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5479 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5480 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5481 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFF84210F, 0xC17BA710, 0x3FD56053, 0x2B47C03F, 0x371FABFF, 0x4EBE8A96, 0x0E6C7A8D, 0x022FAFD3},
	{0x1B5BA286, 0xC05AD8F9, 0x07AE130C, 0xB7059C38, 0x3DE49D45, 0x75D3A23B, 0xB7C307B6, 0x14739E02} } ,
	 { {0xC7B00101, 0xCD0119E3, 0x3EF393BB, 0x742F23A2, 0xBA178D72, 0xE83F0F7B, 0x613692F6, 0x931CD8CB},
	{0x494F0CFD, 0x1A3FCD05, 0x925AC60E, 0x3EB54457, 0xF7C7BB28, 0xE69B3BD2, 0xAB03D144, 0x39FE1FD0} } ,
	0};
		static bigint_t var_k = {0xC93919AB, 0x4995E64D, 0x0CCE5BE8, 0x59064912, 0xE96882D5, 0x2B5C344F, 0x12FC2FF4, 0x7A1F305C};
		static ecpoint_fp2 var_expected = { { {0xD9BBFD05, 0x4E28F6D6, 0xABE01F05, 0x9540D720, 0x485ACCBE, 0xB620E63E, 0x9306770F, 0x8175F4AE},
	{0xC2524803, 0x7D3DD1E0, 0x4A3BEEDB, 0x94F0C6EB, 0x75A8D9BE, 0x269655F7, 0xB1CB18D0, 0x72AEFF7D} } ,
	 { {0xE0B2BBAA, 0xB3F89CC0, 0x1AAA4D69, 0xD3447F82, 0x0A24B3D9, 0xF7697B75, 0x0B9638BB, 0x9D5A9679},
	{0x1E3ED363, 0x32802BFC, 0x52E82E95, 0xF585DF58, 0x4893ECC1, 0x35BF68C5, 0x5FDE1208, 0x88FBE7C7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5482 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5483 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5484 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5485 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5486 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1C030AC1, 0x9F537AD0, 0x9669C2BC, 0xEB6C6E62, 0x133D78D3, 0x44817F57, 0x5499CA3E, 0x2B9989BB},
	{0xC627ED97, 0xFA9FB988, 0xE1D3B705, 0xC49665B9, 0x90C7CB69, 0xC91E4E07, 0xD6463894, 0x08D11073} } ,
	 { {0xBF4F2B3F, 0x1DEBDF90, 0xB5ECCC46, 0x4F9BDB7A, 0x58C6938A, 0xFA9634CA, 0x0FCB0C15, 0x81A6C97E},
	{0x23EE3F9F, 0xC938EDF2, 0xB7D56227, 0xAD9B0FFB, 0x959D6F5D, 0xFD508520, 0xAA51F9AF, 0x224E68D9} } ,
	0};
		static bigint_t var_k = {0xD249B4F5, 0xAD2950FA, 0x11F4A2A1, 0x51E96FBF, 0xDF312EE4, 0x05233054, 0x431F565D, 0x37EC2056};
		static ecpoint_fp2 var_expected = { { {0xEB883E4B, 0x126D8EA7, 0xA8038725, 0xFCE384E2, 0x07EF04AC, 0xB329AAA0, 0x6DF809D6, 0x56A426CF},
	{0xA68074A4, 0xB8979431, 0xE505CF75, 0x38180B59, 0x77749E09, 0x940A43C9, 0xAB9C4D1F, 0x0BE99BB8} } ,
	 { {0x07816F2C, 0x3F6DAE73, 0x97CAF769, 0x7029B5E9, 0x1B8A37A0, 0x96567E74, 0x02B8A1B9, 0xAEA63F05},
	{0x26FF63EF, 0x31138838, 0x95A3463F, 0x9E728708, 0x1424E357, 0x41206E2F, 0x669242D8, 0x0B0817EF} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5487 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5488 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5489 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5490 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5491 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x793B305B, 0x4722422C, 0x29040ABC, 0xE4783A1E, 0x8B159474, 0x059FDFB1, 0x57033330, 0x2CE05621},
	{0xFF456CF6, 0x2BC23747, 0x75BC007E, 0x4FD07DB7, 0x37CE89D6, 0xCDEDF491, 0x2098D0FD, 0x5B2A7202} } ,
	 { {0xABAC88A5, 0x2A8CD3F4, 0xAA375968, 0x51D0D471, 0xABB2EBBF, 0xCBA80FAA, 0x212B9C65, 0x0A7FE89A},
	{0x12362D63, 0xC424A584, 0xF42C1FBF, 0x7F1E1F19, 0x6EC72ABD, 0x989A3D0B, 0x81A72861, 0x02BE0B7D} } ,
	0};
		static bigint_t var_k = {0xA81C4E83, 0x21E8A35A, 0xD949982C, 0xFBD2653E, 0x64504ADD, 0x3A88E16D, 0x5B336207, 0x9CC603A7};
		static ecpoint_fp2 var_expected = { { {0xEDEEE467, 0x19682926, 0xBD518FF6, 0x0DBDC4AF, 0x26A395B8, 0x53D8F7A7, 0xA4014DE5, 0x6DD6E3A5},
	{0xACE50471, 0xBC36AF17, 0x3E18B5D3, 0x4AE68FCA, 0xC6FFBAF6, 0xDCA50E35, 0x2C1CD672, 0x47EA460D} } ,
	 { {0x1C125D20, 0x6E7B0C62, 0x105F58B8, 0xF708634F, 0x8A168618, 0xA066DC5D, 0x51F52719, 0x136651E9},
	{0x9498FDBB, 0x9216E783, 0xEDE20068, 0xE793FECC, 0x42308562, 0x2895B443, 0xCF4A7479, 0x2167C4B5} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5492 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5493 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5494 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5495 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5496 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x348A558B, 0x9FCC0E12, 0x2B1D71F4, 0xA0220C13, 0x22EF4035, 0xD21A10DC, 0xEC14C173, 0x8A0971C8},
	{0xB948EF55, 0xD6679710, 0x3B4D9A2F, 0x11077931, 0x09B26C42, 0xE0186B63, 0xBAFD2E20, 0x2DDD4015} } ,
	 { {0xEEF925FD, 0x1C969EA8, 0x6BC25727, 0x3A2858AB, 0x1CA57CED, 0x1F5DD033, 0xBB96355B, 0xB5C724B0},
	{0x47B99250, 0xD6109F92, 0x4702D038, 0xC8EB12FE, 0x3632E436, 0x82BB66A8, 0x6E84DF53, 0x3C33D9E7} } ,
	0};
		static bigint_t var_k = {0xD29229AA, 0x1D4465BE, 0x23599D3D, 0xE721BE5E, 0xADD6FA1D, 0xB3A9E44F, 0x4850E7EF, 0x28B6967C};
		static ecpoint_fp2 var_expected = { { {0x43F5DCB4, 0x3F900F9D, 0x6FBE818E, 0x118EDBB6, 0xE97DDFB4, 0x6A4DE525, 0xF7B99CB8, 0x67B09A0E},
	{0x33B723D3, 0xACC22E2B, 0x80A144C2, 0x3B1D911A, 0xC0237C72, 0x10DB8805, 0x1BB275B0, 0x66DFC15C} } ,
	 { {0x5F0599C1, 0x48F3E86E, 0xB5E2240C, 0xB7950553, 0xD91ED502, 0x50633A3D, 0xB5999087, 0x1A4B1F1E},
	{0x2643B4B2, 0xD67BDA09, 0x4AFBD08D, 0x8BFEA12D, 0x5013E4EB, 0xEA73DD54, 0xA38BE083, 0x30D9170F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5497 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5498 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5499 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5500 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5501 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFA9CFAFB, 0x8A23C87F, 0x290704D3, 0xD5879B38, 0x2F430AE0, 0xAB950456, 0x3CBFE1DE, 0x7E4591E7},
	{0x05A4AE38, 0x41DBF265, 0x6082D68F, 0x6BDB2E03, 0xCB854E8E, 0x1842627B, 0x34FCB900, 0x5D4D5AD1} } ,
	 { {0xC3A9FCF9, 0xAD35CB79, 0x8386523F, 0x051221F6, 0x28BF0ECC, 0x9E51D30E, 0x60480664, 0x6C275E66},
	{0xF908596E, 0xE17A3A3C, 0x3D245810, 0x25B73BB0, 0x410669ED, 0xF2C3737D, 0xA3CD1B6A, 0x5200CD12} } ,
	0};
		static bigint_t var_k = {0x15B84673, 0x5C81AF0F, 0xEB942DAE, 0xE6FA5435, 0x30CE90B4, 0x9AF1ACBA, 0x3563D256, 0x9DA49CB6};
		static ecpoint_fp2 var_expected = { { {0x25EA1A95, 0xA7135BEF, 0xE68B5E1E, 0xBFEB50A7, 0x649C93C2, 0xE53A11A7, 0x094865F8, 0x579CAC77},
	{0x43A5DEC9, 0x46754852, 0xE862864B, 0xA67E08C9, 0xF07A6224, 0x694D0DEE, 0x3F5F76A3, 0x2DB46237} } ,
	 { {0x0D7FADFF, 0x75CD7398, 0x578FC63F, 0x615FD77D, 0x894C3D5D, 0x6F6AE6D1, 0x46258B45, 0x3703E5FE},
	{0x4A17477F, 0x5CCC9D95, 0x7F8E14A0, 0x85EC1205, 0x571CE2AA, 0x4ACB562D, 0x2AF4EC64, 0x2EE65772} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5502 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5503 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5504 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5505 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5506 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB2CCF9B0, 0xC84E1320, 0x17DC4259, 0xC022D05A, 0x6A6AB1BE, 0x699D1326, 0x13A094B3, 0xA5B331A4},
	{0xC7AAA7CD, 0x8B11579A, 0x8F0AE61A, 0x2D0096EA, 0x1B2F9ED0, 0xE07A8973, 0x1A263F1C, 0x3DBADC7B} } ,
	 { {0x4603DFDC, 0xDD69DF4F, 0x105FEE98, 0xC2F7CCBE, 0x1AD18F07, 0xDAF7E68A, 0x95A5C2C3, 0x22C235AB},
	{0x5A5F0649, 0x6347768B, 0x2CFFADF0, 0xC9C54D5E, 0xCD34F188, 0xC94CA94D, 0xD6339F94, 0x2A9F172A} } ,
	0};
		static bigint_t var_k = {0x7513045D, 0xD543CA05, 0x6F292BA8, 0x09590DD5, 0xA087B60E, 0x57A6F0EC, 0x91FE89A9, 0xFC6DDAF6};
		static ecpoint_fp2 var_expected = { { {0xA31474A7, 0xA295396F, 0x2C4F4DB8, 0x6241D577, 0xA1DEF6AC, 0x3FF935E5, 0x88B3B6E3, 0x3B675AF1},
	{0x9777CFA4, 0x62EDB225, 0x6F36C060, 0xE0909C1F, 0xA6832CC5, 0x53C33B9F, 0xA95D0DD2, 0x4211F52E} } ,
	 { {0x1F49885F, 0xE7A57FE5, 0x3E69417B, 0xD5404350, 0x45C35148, 0x1B2CF72F, 0x191B701A, 0x2D3A61D4},
	{0x2492BA32, 0x0F0646BE, 0x01C6195B, 0xDB2DA262, 0xCE5F00E7, 0xC1B7D19B, 0x9A5F21A1, 0x2D6EC4AF} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5507 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5508 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5509 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5510 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5511 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xEE301556, 0x7C31058B, 0x896F53D9, 0x83A0BAA7, 0x27420D4B, 0x2FB12B97, 0x1FFC8773, 0x312C5813},
	{0x62FF136A, 0xA63424DC, 0x33CAFE39, 0x56DFAEB0, 0xFD4FB540, 0xB1F4121F, 0xB2A380B7, 0x9FC4AC09} } ,
	 { {0xA6CFC6E8, 0xDB7ADE09, 0x6ABE5141, 0x69DAF6B2, 0xF551E665, 0x38142FB9, 0x273F6DB4, 0x21B8848B},
	{0x92424CA4, 0xFD48C5FE, 0x1526B65B, 0x9B88FC62, 0x371E00EF, 0x3906E661, 0x3F4E7B07, 0x0B2F19C7} } ,
	0};
		static bigint_t var_k = {0x38F7B348, 0xC11F0266, 0x2BCCFF7D, 0xA21D33F3, 0xF4EA4FCB, 0x947A1887, 0x072AA2B5, 0x86F077EA};
		static ecpoint_fp2 var_expected = { { {0x87A59D1E, 0x87027F54, 0x0D971EA6, 0x708348B2, 0x7832B9B4, 0xE63CC91B, 0x61DFC74B, 0x169BFDAA},
	{0xD975234A, 0x191C6253, 0xE86985BE, 0xA05D1D8C, 0xD25FC84B, 0x9F928D34, 0x1DE190CD, 0x6C6C34B0} } ,
	 { {0xBBB9E748, 0x1669E105, 0x12C5D3CB, 0x042BC1D4, 0xE3C32AED, 0x915A8EC9, 0xE3BDAB61, 0x1FE7B99B},
	{0xD35F3B82, 0x8BAD1F14, 0xD58260C3, 0x39429B4F, 0xCEAFA9F1, 0x627F4889, 0x5CDF3CF2, 0x1F26CBBF} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5512 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5513 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5514 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5515 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5516 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF0E4177E, 0xDF90F74E, 0x81F4BB55, 0xAFCF7879, 0x0847BDAC, 0xA0C373E6, 0xEE74E11C, 0x8A407F9E},
	{0xDD094DE2, 0x1172E7BE, 0x2675B14C, 0xF88B0A95, 0x8A93B92E, 0x7901D68D, 0x5CBC6006, 0x7163E71C} } ,
	 { {0xC9D54278, 0x5BFC376C, 0x4E94E894, 0x6EDDA09F, 0xDC987099, 0x242AEEF2, 0x5C0A8DB0, 0x425027C3},
	{0x20E07439, 0x458BC0A6, 0xBF803276, 0xFE79546C, 0x452B4267, 0x08FBD765, 0xD98986B1, 0x544C5890} } ,
	0};
		static bigint_t var_k = {0xE2D02538, 0x9B29C56B, 0xDC8B910C, 0x402081A8, 0x60C70E05, 0x3A1DB369, 0x86322430, 0xBC1CC5ED};
		static ecpoint_fp2 var_expected = { { {0xF1562C76, 0x1DEA8698, 0x6359822B, 0xE28F02A2, 0x80889873, 0x49424DFB, 0x5FE7EE88, 0x8AF10BCD},
	{0xCD9CC54F, 0xAE1BEE1A, 0xC7DA48B1, 0x71ABFE24, 0x32F7390E, 0xB4C33C13, 0xF07C990A, 0x50D79237} } ,
	 { {0x07436A7D, 0x2F4DC141, 0x2816B0F9, 0xA6EF0097, 0x3C48D266, 0x10708360, 0x07DB9910, 0x14ACA0EE},
	{0xCFD430C3, 0x02CF3E87, 0x6FA382A3, 0x2968A6DD, 0x9512E41C, 0x37A769B0, 0x2CC7B116, 0x1AE6470E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5517 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5518 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5519 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5520 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5521 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5AF4C5E9, 0x7F6EED41, 0xFDA6C4CE, 0x2669A840, 0xF6BB730B, 0x2A09CC0F, 0x42C477B0, 0x4F279E09},
	{0xAFD5F8AD, 0x0D3018B1, 0x8AB9F01B, 0xF80719BB, 0x2C537B8A, 0xF86A6386, 0xD43D594A, 0x8058E8B8} } ,
	 { {0xADBA68C5, 0x7C5CAF5E, 0x8BFCD031, 0x3939F0EB, 0x8A4F5658, 0x83ABD27A, 0x6A0FBA44, 0x49183D1C},
	{0x5B37BFC0, 0x1DD9AEA2, 0x31E1CEB2, 0xB72DA261, 0xC7EE34E4, 0x9884E804, 0xC293255C, 0xA1A49B58} } ,
	0};
		static bigint_t var_k = {0x387923C0, 0x1A8603B1, 0x7FA00BC4, 0xB63ECBBF, 0x5A23BBAA, 0x71C9EC57, 0x3A7A6ADE, 0x5F05636B};
		static ecpoint_fp2 var_expected = { { {0x2FAFEB03, 0x2D313959, 0xFEC08C10, 0xE0FF1A7C, 0x055E323A, 0xABC08ACB, 0x924965AF, 0x5A432746},
	{0x4601323A, 0x04C7E81E, 0xE4DDB79E, 0x92B3CC7E, 0xD6903AB6, 0x86B972C9, 0x52D3E42A, 0x07812B8F} } ,
	 { {0xDD1A8728, 0x104136F0, 0xAF13198B, 0x499B18C4, 0xB5F7C4F4, 0x2EC7F693, 0xE394AED3, 0x584F2265},
	{0x0B999CF3, 0x712D682F, 0x41DECDF7, 0x9A1ABBA6, 0x4364B941, 0x6501E600, 0x04799E02, 0x198FD460} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5522 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5523 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5524 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5525 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5526 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF816AB1C, 0x7B73B6F3, 0x3FA4FDCA, 0x88AF8F15, 0x6140537D, 0x1D51F65D, 0xAC07C628, 0x2D0BBB08},
	{0x07E734AD, 0xAD96501B, 0xF1C11012, 0x38F22C26, 0x21CE6661, 0x3C0669A0, 0x0B44B5C7, 0xB707BDFB} } ,
	 { {0xEDA5733C, 0x46EC8FB5, 0xFE29E1E9, 0x76E955EE, 0x63F62BE0, 0x64B7E9BE, 0x7A597032, 0x1000D65C},
	{0x2105D35A, 0xEAB2DCC2, 0xB1E11017, 0xCC41BF81, 0xECD333BD, 0xEEF972D1, 0xF8D874EB, 0x04DD26DA} } ,
	0};
		static bigint_t var_k = {0x4084E254, 0x38FAD32F, 0x523B7BB4, 0x136D4C43, 0x958C2FBA, 0xA2D60A67, 0x8F4890ED, 0x70EFD097};
		static ecpoint_fp2 var_expected = { { {0x96090EEF, 0x3E9DB966, 0x594441E8, 0x5FB331E2, 0xA8DB8A9F, 0x8627E674, 0x1A88D3AE, 0x8D0C576A},
	{0xDFD1DD80, 0x927B237E, 0x816D6612, 0xDFE32935, 0x0ED374EC, 0x2B1F46B5, 0x50D6C9DE, 0x79085B08} } ,
	 { {0x825B38B1, 0x7ABF7EAE, 0x7876275C, 0xD4AF891B, 0xD8C0A289, 0xD360D8E4, 0x2814A5AA, 0x30CDA0E1},
	{0xFE232A05, 0x877EFFCC, 0xDF997488, 0x70DBFC67, 0xD5FEF4C5, 0xAD5054D1, 0x9482C19F, 0x4A6E1E05} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5527 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5528 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5529 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5530 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5531 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3A8584FB, 0xA9078452, 0x79DBF129, 0xCD7FEA66, 0xAC383583, 0x2119C4F2, 0x798D29D8, 0xA91912F0},
	{0x9F939E6A, 0x87AFA3E1, 0x0D59FC61, 0x141484F0, 0x1711CD52, 0xAF85974F, 0xDDB3BE5E, 0xA159A0B0} } ,
	 { {0x7E49D0BF, 0xBA740494, 0x726B6B68, 0x167CC3AE, 0x54792D2F, 0x45E417C5, 0x00A6E35F, 0x9F388FA5},
	{0xB9F09D32, 0x6D4559F8, 0x8CFBD3D6, 0xC893E23E, 0xC693386A, 0x508A0437, 0x68C4DA87, 0xB23A211E} } ,
	0};
		static bigint_t var_k = {0x3E9169D5, 0x2E7B5C36, 0xD256403B, 0xAAC59839, 0x08680973, 0x7748EB83, 0x349A7545, 0x2F625D6A};
		static ecpoint_fp2 var_expected = { { {0x3993EA5B, 0x36A0E5DF, 0xE806F720, 0xF40B76BF, 0x8FED1AAD, 0xB9056301, 0xCCD5DFDF, 0x5AC6B5FD},
	{0xE20BEB7A, 0xDCFAC4E5, 0x52A73D71, 0x54604F51, 0xA61EAEC3, 0xA7DB93A7, 0xA110F91B, 0x521E8C02} } ,
	 { {0xD191F7D4, 0x165BB18B, 0x53436170, 0xE3B4D4EF, 0x7EF65104, 0xFFEB2135, 0x76854AEF, 0x025BF98B},
	{0x5895AED5, 0x6E3D2DBB, 0x5645F527, 0x72353964, 0x62ECB763, 0xB18C28B4, 0x7A3245A9, 0xB1DDCD46} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 5532 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 5533 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 5534 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 5535 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 5536 infinity");
	}
	{
		static const bigint_t var_t = {0x7A08D752, 0x662FB523, 0x90E4C641, 0xD09D2286, 0x772D4EBD, 0x6579AC15, 0x73395F3B, 0x25371FC0};
		static ecpoint_fp2 var_expected = { { {0x185973F6, 0x11D819C1, 0xD12A3B42, 0xAED1B99C, 0xCBD34097, 0x45A3817E, 0x99CD60F4, 0x6CC308F8},
	{0xFFAC5200, 0x4738F2E1, 0x849C67B4, 0xC73D2E47, 0xE2B293FD, 0xE2B5FFA3, 0xAF7B295A, 0x3DAC7E56} } ,
	 { {0x4E2A2C43, 0x5B17B09B, 0x99C6CDB6, 0x7125E1E5, 0x95526D28, 0xC886F30F, 0x168F32E1, 0x6D551E05},
	{0xC4029583, 0xE8519594, 0x468CD0B6, 0x419138AA, 0x42C58566, 0xFD272221, 0xC58903A5, 0x2FE9851E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1233 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1234 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1235 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1236 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1237 infinity");
	}
	{
		static const bigint_t var_t = {0xAC29228A, 0x3F11A613, 0xC80BE206, 0x57485084, 0x6F3634A6, 0xED62FAD5, 0xD4269403, 0xFCABB6D7};
		static ecpoint_fp2 var_expected = { { {0x62371A02, 0x3B6F2A52, 0x3BDB202A, 0x8D5C3E14, 0x60319AC3, 0xB8A87E7A, 0x8F8010A0, 0x8667D9BA},
	{0xCE3CB40E, 0x46BD75EB, 0x50F0BAFD, 0x5BB2539E, 0x7D659167, 0x480A6978, 0x6672F431, 0x7DDF7A6F} } ,
	 { {0x41A53474, 0xB60E8B46, 0xEA7F1435, 0xDF022CC0, 0x5FCB4153, 0xE2034493, 0x51CEC2DB, 0x4E0F27D6},
	{0xFC116C51, 0x2A9DDDD2, 0xBD02E1EC, 0x4766C09D, 0x317275C1, 0x9BEA00FE, 0x954CA173, 0xAD71A0DE} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1238 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1239 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1240 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1241 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1242 infinity");
	}
	{
		static const bigint_t var_t = {0x500B5BAA, 0xE9D8EE49, 0xFD83E84D, 0x8D172583, 0x90CB1DF4, 0xE3CDBF2B, 0xD8A5C6EF, 0x2D675567};
		static ecpoint_fp2 var_expected = { { {0x7C3D0E24, 0x2B22EEA2, 0xD4E37C6C, 0x4F3E8FED, 0x98D6BB8D, 0xBA28CC76, 0x0828C58C, 0x36DD89EE},
	{0xD2E95152, 0x4AB0F55A, 0x60024DF1, 0xCFB85CF3, 0x2A53BB3D, 0xD28C29F9, 0xDA41A61E, 0x734CB6C1} } ,
	 { {0x6D5F1576, 0x858FE02E, 0xCDF45306, 0x529E5AE8, 0x6F930E19, 0x57B66FFE, 0x16519B32, 0x9EB51FB9},
	{0x007B23E3, 0x123A7339, 0xEAA247DF, 0xB0180E9A, 0x4A7DD72F, 0xE8349479, 0x5F7863AE, 0x4B37FE58} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1243 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1244 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1245 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1246 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1247 infinity");
	}
	{
		static const bigint_t var_t = {0xD127BFC2, 0xFF464CA4, 0x37EF8BC6, 0xEE71F7F1, 0xB33FD567, 0x0BC3585F, 0xB957B61B, 0x3DBED8EE};
		static ecpoint_fp2 var_expected = { { {0x57E6399E, 0x9BFD16CF, 0x90E4C09F, 0xA2EBC2D1, 0x62945CA3, 0x6ED08E3E, 0xF6FE34EB, 0x5C9713BC},
	{0xCC1A7FA2, 0xF8F63826, 0xEB507A6C, 0xBD71844E, 0x91CCC0C1, 0xC2624E85, 0xFFC49C5E, 0x6A69FEEC} } ,
	 { {0xB6FCE993, 0x572A85B5, 0xC7751D1C, 0xAD632E9D, 0xC93ADD76, 0xF41CA872, 0x68CFDEA8, 0x7DA1179F},
	{0x5336975F, 0x51B87CA6, 0x2AC07B00, 0xC8300207, 0x7A49349B, 0x6923DEAC, 0x02205D33, 0x8781B568} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1248 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1249 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1250 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1251 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1252 infinity");
	}
	{
		static const bigint_t var_t = {0xA6DB0B98, 0xE00D277A, 0x0FA60B22, 0xA91CF07D, 0x1EB4EB47, 0x0CE4AF01, 0xB02D2A2C, 0xB166866F};
		static ecpoint_fp2 var_expected = { { {0xE90858F5, 0xD763DEA7, 0xEB94CA0E, 0x35646FCE, 0x5312EF29, 0xE23607EE, 0x8C818678, 0x93585A72},
	{0x02DD74CD, 0xD20A3BC8, 0x38BEEA63, 0x1CB68990, 0xFA908C95, 0x80B2A368, 0xF24283DD, 0x5B86C72A} } ,
	 { {0x1D49A5CC, 0x2DEF5778, 0x0A3CF2E4, 0xC8C46C02, 0x6AEBC317, 0xD60A8511, 0x40D10C0D, 0x61F0A02D},
	{0xE9915AB4, 0x4E3E8170, 0x524462D9, 0x58016015, 0x9E10186F, 0xBEA32C82, 0xD031DA7C, 0x0294667B} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1253 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1254 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1255 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1256 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1257 infinity");
	}
	{
		static const bigint_t var_t = {0x0AAF2F7D, 0x3FB0F942, 0x446EC019, 0x2198E540, 0x99019E8E, 0x9F05BAB6, 0xD7BB95A7, 0x0246A3FA};
		static ecpoint_fp2 var_expected = { { {0x43FC0262, 0x638AD9E3, 0xD0AB0116, 0x2BC411B3, 0x8F578A2F, 0x3F379C8B, 0x58CA1624, 0x180BA957},
	{0x9764CE41, 0xBC8460ED, 0x39866150, 0xB31ED45E, 0x0205BC0B, 0x73974FDB, 0xD5A1D0C1, 0x74FF99E3} } ,
	 { {0x539B7867, 0x53403F38, 0x9EAFB288, 0xA23B77FA, 0x62111D10, 0x01B18253, 0x5A684082, 0x8327CF74},
	{0xCD0BAACF, 0xE583B16B, 0x031278FA, 0xA46E37C8, 0x9E6E4587, 0xD54946A0, 0x196BEFF2, 0x62E3E106} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1258 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1259 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1260 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1261 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1262 infinity");
	}
	{
		static const bigint_t var_t = {0x7C8AF2B2, 0xA4B712F1, 0x387B475F, 0x6CD2DC98, 0xF3A45A88, 0x12FE59BA, 0xB031CD8B, 0x1CFC65AA};
		static ecpoint_fp2 var_expected = { { {0x37C9C043, 0xCD7F19C6, 0x2FAA81C3, 0x22709877, 0x8B5D68C2, 0xE46F4D69, 0x9158A50B, 0x0CB23878},
	{0x699514FF, 0x9ABD6DD7, 0x1B6F5782, 0x13C973F8, 0x0CDD598F, 0x85320594, 0x90C96526, 0x00B75D24} } ,
	 { {0xC2E7604F, 0xF07AC225, 0xCBEA0B2D, 0x21FAFC99, 0x8B57A38F, 0x2C28DEE2, 0xE803B521, 0x0B9E670C},
	{0xED151D3B, 0xCC0EED34, 0xC42DF7F4, 0x86401149, 0x80C62FD9, 0x6F9B20B0, 0x4019A19D, 0x8F158421} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1263 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1264 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1265 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1266 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1267 infinity");
	}
	{
		static const bigint_t var_t = {0x3FFBBF4B, 0xEA3AF7A4, 0x71FEDCD9, 0xD5A9FD2A, 0x7CBB681F, 0xC6C37FD7, 0x9FE20FCC, 0xE13DC0E1};
		static ecpoint_fp2 var_expected = { { {0x7686EFBA, 0x21985C21, 0x238CCFDE, 0x9E60773F, 0xDBD75910, 0x9D9988A8, 0xA4F7273C, 0x4AB62AF6},
	{0xEF4D2DC5, 0x3562307C, 0x86F58C5C, 0x1EC643BE, 0x9C9D5793, 0xDA33E940, 0xB8CFF7AB, 0x8FA8A3C2} } ,
	 { {0x6F07B0E8, 0xF49C8842, 0x837D6642, 0x0ED1A06F, 0x45BF6B02, 0xFDEC50E8, 0x553194BC, 0x834D1EEA},
	{0x2FEEC96D, 0xB8069950, 0xEC123145, 0x75DF03C4, 0x0499CDA7, 0x91AD4BDF, 0xFF77B7DD, 0x6882151F} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1268 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1269 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1270 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1271 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1272 infinity");
	}
	{
		static const bigint_t var_t = {0xDB87C58F, 0xC2B41FEF, 0x1A484831, 0x5B3FA57E, 0x890FC251, 0xB2DB9C7F, 0x6B5EAB55, 0xA4FF0829};
		static ecpoint_fp2 var_expected = { { {0x858672D3, 0xF26E1026, 0x7416466F, 0xB1403644, 0x5323281B, 0x22520AF7, 0xD8DE964F, 0x4DFB00BA},
	{0x860DF0D4, 0xEF76CC02, 0xF84EE863, 0x770D3F55, 0xA680F7E1, 0xABE2CAD1, 0x6C50FD01, 0x376A154A} } ,
	 { {0x5F96A3FE, 0xA18B4043, 0xD5C76E11, 0x43200C22, 0x973B35AF, 0xDBBAE312, 0xB84EF42A, 0x0DFAC866},
	{0x20D19CEB, 0xE2DD97F9, 0x4D641D49, 0x909C5C1C, 0xFF3C5CDC, 0x56061591, 0xC4BA5C24, 0x0C2DF31D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1273 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1274 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1275 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1276 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1277 infinity");
	}
	{
		static const bigint_t var_t = {0x9A14D771, 0x2F2A0913, 0x7F77FB90, 0x2F1980C8, 0xF434721E, 0xDD17C899, 0xC119B9FF, 0xAE6FD1F4};
		static ecpoint_fp2 var_expected = { { {0xE413EF80, 0xAAC0958A, 0xE85CBA44, 0x2DEF9D0F, 0xC9135128, 0x9C77D7D6, 0x5932A263, 0xA5E3EAAC},
	{0x26696390, 0x30EF35DA, 0x84F51F61, 0x35AF845D, 0x202EB641, 0xDF8C01BD, 0x820FD0F3, 0x4184A9E0} } ,
	 { {0xFEF2DEFD, 0x73D54A90, 0x01CC048D, 0xD0FAA42A, 0x5CFAAAE2, 0xB228FFE0, 0x1921E12E, 0x74328632},
	{0x6D5D33B6, 0x0AED00FF, 0xEE4BD58A, 0xAAD67670, 0x0C26B330, 0x40EC701B, 0x56BE85EA, 0x200B670E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1278 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1279 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1280 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1281 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1282 infinity");
	}
	{
		static const bigint_t var_t = {0x0C58CB81, 0x09A1D463, 0x95BB4880, 0x3A15D6D0, 0x99B50CD0, 0xE7A52A72, 0xB1A6B818, 0xBDC06E43};
		static ecpoint_fp2 var_expected = { { {0x8901D476, 0x6BE2992D, 0xE10CB541, 0xB2706447, 0xDE1AB7E5, 0xC2ACD17D, 0x6B6A94C8, 0x20ECC4DB},
	{0x7C0855F9, 0x4466E7F3, 0x172B517C, 0x7045FF0E, 0xC23A59FD, 0xD9D4999F, 0x2245A02F, 0x5954CD23} } ,
	 { {0x9B77791C, 0x12A5FF20, 0x951A4DF9, 0x2456096C, 0x84EB6F32, 0x34B7DE24, 0x1E50672F, 0x203C3F86},
	{0x05BE2E79, 0x4621274F, 0xDB471D00, 0xF93E8D0C, 0x980A87D4, 0x3835D8D5, 0xCB67D10A, 0x55AFE2E8} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1283 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1284 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1285 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1286 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1287 infinity");
	}
	{
		static const bigint_t var_t = {0x835F42ED, 0x7AE6EEDF, 0x6F23CFA6, 0x942B725B, 0xDA4D0CEA, 0x816D90EB, 0x2F7D081B, 0x80C40245};
		static ecpoint_fp2 var_expected = { { {0x70023499, 0xE52C2A70, 0x6FCCA932, 0x5AEFEC61, 0xAA9020EF, 0x6BC302AA, 0x73C38363, 0xA7B0F59B},
	{0x579E6B4B, 0x6B04E4FD, 0x3F286F5F, 0x02063423, 0x8905A912, 0xC60C079A, 0x4F0D5176, 0x10C7DBD8} } ,
	 { {0x0BECC3A3, 0x9FF23876, 0x17C8B138, 0x210D9723, 0x3B657937, 0x6D0BFB34, 0xBBA68D48, 0x43E3558D},
	{0xE6AB25CE, 0x030F6C6B, 0xDD76F9A7, 0x73AC719A, 0x8F3E4519, 0xB3A1C8EB, 0x85CACF59, 0x6E506D7F} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1288 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1289 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1290 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1291 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1292 infinity");
	}
	{
		static const bigint_t var_t = {0x9823088C, 0x83A57AA6, 0xCAFE8056, 0x0E01D01A, 0x1C392D27, 0xF0BE35B6, 0x93537F6F, 0x1C560D31};
		static ecpoint_fp2 var_expected = { { {0x4CFF80D8, 0xB3992F29, 0xD424AC62, 0x717BDFB8, 0x3C9BA7C9, 0x02B3D03A, 0xE4195EE2, 0xB256C627},
	{0x53F6D80C, 0x10A83B31, 0x0307FD69, 0x9319A28B, 0x3E5ADBAD, 0x62BE2B59, 0xC4D8F909, 0x2D70B956} } ,
	 { {0xADF88D92, 0xA65B97A3, 0x26DC0294, 0xD14ACC51, 0xEDCC7697, 0xF18CA007, 0xB89E3F65, 0x87928B68},
	{0x58E7ABCA, 0x88FEE7EC, 0x8073F954, 0x38F7841B, 0x02E6DFA8, 0x9B2696E5, 0xCB901D50, 0x97B11529} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1293 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1294 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1295 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1296 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1297 infinity");
	}
	{
		static const bigint_t var_t = {0xA42C85A9, 0x78CD76BE, 0x82CEE5BE, 0xA9497903, 0x488E14E7, 0x8E512CD8, 0x1907A80B, 0xAA94D003};
		static ecpoint_fp2 var_expected = { { {0x18F14941, 0xB0371CD0, 0xFD973D8D, 0x2A728916, 0x0AA486B6, 0x08A95F8B, 0x9586AF39, 0x71E1846F},
	{0xEBFAF1E7, 0xC4523920, 0x7EF4DFE4, 0x6BD83B3F, 0x71D9F17A, 0x1629E9A0, 0x41DB4BC5, 0x6851FB46} } ,
	 { {0x7687E38D, 0x2E5B7BBA, 0x8079B46B, 0xB481A392, 0xEC8B0EAA, 0xEEF1A71F, 0xFF730B9E, 0x6D20B459},
	{0xC95DBE43, 0x0D66E707, 0xC154B7A9, 0xC2A3CEE9, 0x3EEB76A4, 0x89D179D8, 0x0B24E0E8, 0xA37A9F3D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1298 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1299 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1300 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1301 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1302 infinity");
	}
	{
		static const bigint_t var_t = {0x4847EF38, 0x8048DBEC, 0x1AC579BF, 0x1DFBBCC7, 0x4BACD621, 0x4992F144, 0x62146227, 0xB6ED111D};
		static ecpoint_fp2 var_expected = { { {0x5E9EFA43, 0xD996C4B6, 0x48CA0A3E, 0x873E4357, 0x0DFC347D, 0x51DDA74A, 0x60521B0E, 0x1CF055A3},
	{0xF0FAFDB0, 0xBDD06719, 0x82089E4C, 0x40DDD392, 0xE5C5CFD4, 0xFFF4CE85, 0x1D01F842, 0x5C13CE0F} } ,
	 { {0x6207F9C4, 0x88EF53B4, 0xE90778BF, 0xAD6F913E, 0x28ECD559, 0x41B639F6, 0x1D48B96D, 0x7FB9103C},
	{0x6E39F013, 0x6353C62B, 0x70F2B690, 0x2132A458, 0xA8CB057E, 0xAE65EF44, 0x62B8B1B8, 0x698E2207} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1303 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1304 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1305 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1306 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1307 infinity");
	}
	{
		static const bigint_t var_t = {0xE6482C66, 0x16022604, 0x39D74C69, 0x534F2A5F, 0x96B62E78, 0x2342109B, 0xF29FE83B, 0xC2F701A1};
		static ecpoint_fp2 var_expected = { { {0x59960CDA, 0x58220822, 0x58EEEBC4, 0x3D825B12, 0x237EF305, 0xFEA01BEE, 0x7CD6AA4F, 0x41922E69},
	{0x9145B4F7, 0x1FB92A19, 0x27E007A8, 0xECF94050, 0x71913204, 0xCBDC43EB, 0x147A34C3, 0xB236A024} } ,
	 { {0xED97DA21, 0xDC515553, 0x4319017F, 0x54AFC0DD, 0xD8D21615, 0x7CAA4C55, 0x3F52157A, 0xAE402262},
	{0x94E2DAF6, 0x5F808BD5, 0x2C4FBADD, 0x97B5F035, 0x33264D74, 0x0162BB62, 0x3548D899, 0x62FA2347} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1308 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1309 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1310 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1311 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1312 infinity");
	}
	{
		static const bigint_t var_t = {0x25E49801, 0x8B3D122D, 0x285C4362, 0xEB9679C0, 0x9E21793F, 0xB064E75F, 0xB00E82FC, 0xC11C550B};
		static ecpoint_fp2 var_expected = { { {0x6711A1A0, 0x7658A5EF, 0x5DEFB409, 0x3F038388, 0x649C2047, 0xD9DB276A, 0x87A2533E, 0xB284353B},
	{0xCCB03E3B, 0xD2034870, 0x7E94E0EC, 0xDFC29E87, 0xB8E555A7, 0x9577B02D, 0x1C24B099, 0x5B6F47DB} } ,
	 { {0xA68B9EAF, 0x9679901B, 0xE12F53F1, 0x6943995E, 0x86896F3C, 0xEE437EBE, 0xA6A80C0C, 0xAD444E7F},
	{0x6724523E, 0x39B6ED9D, 0xDA9409B2, 0xEB70BFC4, 0x0565F426, 0x1241BD1E, 0x461A506D, 0x07A1154F} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 1313 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 1314 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 1315 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 1316 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 1317 infinity");
	}

#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp2 var_a = { { {0x9FB64D41, 0x997EB0AB, 0xD6C39AFB, 0x218FA488, 0x68307DD8, 0x639DD22B, 0xF2B11426, 0x113126D8},
	{0x6C4B6442, 0x34DBC43C, 0x4C007160, 0xB522EF3F, 0xEEB65336, 0xE26BBD17, 0xFD9F2E82, 0x09E26FF9} } ,
	 { {0xCE8F88DC, 0x665ECDA3, 0x9A8B185A, 0x7CE59373, 0x38B9A0C4, 0xB19FE126, 0x3EF40EB1, 0x1EF51821},
	{0xD4A17453, 0x43EAB64A, 0x20E36F48, 0x88D32B8B, 0x9CE93DA9, 0x49323DD7, 0xA8FB29B8, 0x01C17D5E} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4982 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4983 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4984 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4985 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4986 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4987 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4988 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4989 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4990 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4991 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE23573E5, 0x8BF1A25F, 0x7115EEBA, 0x3C534D74, 0x8393BEC8, 0x5008450D, 0xA5A65E54, 0x1E95C3F6},
	{0x308D19A6, 0x042D1876, 0xD234AEC4, 0x771DB4A3, 0xEC299AD0, 0xE1D289D9, 0x10D4A12F, 0x0FAD012C} } ,
	 { {0x49BC29FA, 0x6CF85AE8, 0xBE99B6B1, 0x710BBF0F, 0xE825AA39, 0x01DE425D, 0xFB73D82D, 0x1B28F2DD},
	{0x8D41817A, 0xFA254F60, 0x64F54922, 0xF3DE58F0, 0x1C3515BF, 0xD0ABFFDA, 0xEA64EA9C, 0x084971D1} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4992 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4993 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4994 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4995 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4996 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4997 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4998 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4999 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5000 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5001 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xAFEBD5A6, 0x1E7685B9, 0x27340986, 0x06C99CC0, 0x42B8012E, 0xF7A18AB5, 0xD6385820, 0x03FFBFB0},
	{0x3710B301, 0x939B5640, 0x1D30256E, 0x1644D176, 0xA891A8F7, 0x3B78A5C6, 0x6CBBDDB6, 0x250C3404} } ,
	 { {0x001207EE, 0x18C12D2C, 0x91330313, 0x7A108027, 0xAF43A942, 0xD25F732C, 0x8B4EEB99, 0x124F7B69},
	{0xBB37114C, 0xB3B46415, 0x824BFF03, 0x3A45B750, 0x4D5FA480, 0x54C9A7E5, 0x0A1200BC, 0x07C19D0B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5002 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5003 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5004 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5005 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5006 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5007 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5008 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5009 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5010 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5011 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6BD2A1A4, 0x3A905311, 0x216A3669, 0xF95EE3DA, 0x8C4299B5, 0xB570206F, 0xAFE02EB9, 0x0129A12C},
	{0xE7B3EE72, 0xE1FF7511, 0x575982B6, 0x7BA4AB74, 0x08277EB0, 0xA7A6AAC9, 0x781758E6, 0x00777FB9} } ,
	 { {0x5CF55FE7, 0xA80DC81C, 0x3D7D10BD, 0xAD40CA4F, 0x758001C7, 0xC1A845B0, 0xD636E1FE, 0x1FE23D42},
	{0xC80D38F2, 0xB885BCFC, 0xA166446C, 0x0799CF6C, 0x17AB87C3, 0xFE2D4FB1, 0xEE43FBCC, 0x030CBE59} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5012 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5013 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5014 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5015 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5016 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5017 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5018 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5019 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5020 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5021 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8038E025, 0xB8E56E01, 0x8835BAC4, 0x695A3D94, 0x49EABED9, 0xC9AB73B2, 0xD709ADF2, 0x19AE344D},
	{0xAB2B3684, 0x0ADBF292, 0xA6CBBCA0, 0x29277CD3, 0xF7B66A26, 0x4E32A3CD, 0x5E224E0E, 0x0BEB1BA2} } ,
	 { {0xC41E4DDF, 0x3B56E35F, 0xE8CE60F6, 0x468D83D4, 0x235E2B7F, 0xB3A90696, 0xC4D0198B, 0x0210F714},
	{0x1C21558F, 0x6B2C931B, 0xEA7B2D7A, 0xC4AB41AF, 0x63EF7EAE, 0x9CA44419, 0xFEAAF89E, 0x1BFA3C77} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5022 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5023 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5024 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5025 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5026 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5027 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5028 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5029 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5030 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5031 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x55C0A1D4, 0x074181E8, 0x8248FE14, 0x9A7C1FE4, 0x617B320C, 0xD42FE420, 0xF513C475, 0x023671EF},
	{0xE8FE1897, 0x2151F2BD, 0x33568069, 0xC61B2307, 0x5AA2F281, 0x8BF3A23A, 0x04888EEC, 0x1E956D6F} } ,
	 { {0xA09A709F, 0xF039D251, 0xBAB48B32, 0xC8749443, 0xA072CE5C, 0xD6851A1C, 0x7DB7BA19, 0x221DF296},
	{0x1DA30815, 0xC8DD3E52, 0x86741802, 0x5BD02148, 0x1897C6F1, 0xE633921A, 0xA46EEBC5, 0x0AAE4B85} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5032 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5033 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5034 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5035 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5036 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5037 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5038 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5039 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5040 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5041 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x526047B8, 0x2D945E04, 0x3789B1D9, 0x548AEB5B, 0xBDD5C8D8, 0x5E8998A0, 0xB25216E6, 0x0339D058},
	{0x0889C600, 0x5C2B64B0, 0x267C96F9, 0x44A3FB54, 0x1BDEA32D, 0xE600251F, 0xD36943CC, 0x1C5508A1} } ,
	 { {0x59C9B085, 0xFB77E29C, 0xDDEEE766, 0x6C31FCE8, 0xD467DB64, 0xF40A6753, 0xA878C30D, 0x0BB99FF6},
	{0x35992D58, 0x4773D1BD, 0x9AED9602, 0xEE1D4359, 0x1FA175D3, 0x4B334446, 0xC62AE79A, 0x12AB98D9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5042 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5043 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5044 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5045 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5046 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5047 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5048 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5049 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5050 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5051 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE062B26B, 0x75EFE6A5, 0xD11100F1, 0x457281CB, 0x44ED14AC, 0x91338D70, 0xF60D81EE, 0x1E291F13},
	{0x72F98727, 0x8BD424BB, 0xA774557A, 0x6271A9B8, 0x21F3F09B, 0x14F110FF, 0x735ABC04, 0x202C70D7} } ,
	 { {0x565FF7CE, 0x16F5BE29, 0x78713A20, 0xEFC5E2BB, 0xA8FBA5CE, 0xDEA6622F, 0x2F94129C, 0x116CE1CF},
	{0xCBDCD8C7, 0x1C6BBA92, 0x51385812, 0x6DF792B3, 0x5FA0D2F5, 0x5413680E, 0xCEEC6961, 0x14B97FAB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5052 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5053 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5054 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5055 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5056 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5057 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5058 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5059 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5060 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5061 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x66667FD6, 0xBB8AE8FD, 0x7630B38C, 0x0897D296, 0xDEC9F2BC, 0xF541F84E, 0xA880A6C1, 0x027DB249},
	{0x8E533A25, 0x515D1F29, 0xDE2A00C9, 0x6EC8EE99, 0x54FE0AA0, 0x893717CC, 0x8C65380C, 0x088DF16B} } ,
	 { {0xFF64E71C, 0x33BCD1E8, 0xB2645CC8, 0xA9CEA63C, 0x0300FFAB, 0xBCE8D5DF, 0x7881701E, 0x03C11403},
	{0x481B4EBE, 0xE0E968F0, 0xD259136F, 0x94515AA5, 0xC0BBAD47, 0xE61CE90A, 0x6236A66B, 0x06A3929B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5062 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5063 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5064 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5065 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5066 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5067 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5068 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5069 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5070 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5071 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4D5D45B3, 0x3FBF0103, 0x4F675C60, 0x6E53723C, 0x74872C1E, 0xE593AA1E, 0x72DA77F9, 0x209998AA},
	{0xC56EC8AC, 0x26796F3F, 0xF23D3A49, 0x88847BD3, 0x9DB0BAF1, 0xB268C786, 0x0505B0EA, 0x1A244DEC} } ,
	 { {0xBC3698AC, 0x43F9A5F4, 0xB424E630, 0xAA66F1C3, 0xCD5A4E68, 0x75F796EA, 0xACAA99A3, 0x0AAFF732},
	{0x13D6FED5, 0x16B1ED2D, 0x440B7195, 0x15DBA559, 0x2AAEBF9A, 0xFEF00997, 0x6B00CDCC, 0x1300C219} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5072 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5073 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5074 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5075 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5076 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5077 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5078 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5079 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5080 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5081 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFB8DCB41, 0xC50F83F0, 0x846C83F9, 0x5AD7288D, 0xED550F78, 0x44401825, 0xBA40BF97, 0x075378EB},
	{0x7EF6A47D, 0x978083F6, 0x0C016D99, 0x42B6C28A, 0xE34E3FD5, 0x5FF8048C, 0x072C9F1F, 0x0EBF6D28} } ,
	 { {0xF6844F90, 0xEBFC498D, 0xA641D917, 0x3BEACEC2, 0xEF05AD98, 0x7A753C9C, 0x736B48AA, 0x0335CE3C},
	{0x94627EC4, 0xD02E9D1F, 0xD0B9F53B, 0x973D8248, 0x86C6FF82, 0xF4484A6C, 0xD0B457D2, 0x12F1EA78} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5082 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5083 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5084 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5085 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5086 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5087 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5088 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5089 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5090 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5091 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDA9244D9, 0xE71C51DE, 0x3D2AD168, 0x3C638214, 0x317906EF, 0xB3B9B53F, 0xE9C9A974, 0x0371D662},
	{0x216A446F, 0x756E3EEC, 0x547B31F3, 0x5B21C858, 0x0FB21EA5, 0x470C7109, 0x3B3DCFD6, 0x066F508F} } ,
	 { {0x14543BEB, 0xFB3CB16C, 0xB07F49F3, 0x1DACB573, 0x500FFFDA, 0x817452B5, 0x74163F50, 0x09E368D3},
	{0x33EA8054, 0xC86EB1D5, 0x9E86EAEB, 0x1F3F5F38, 0xBBE7FE8F, 0xDC7B0510, 0xBB3152D1, 0x0380AFFE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5092 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5093 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5094 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5095 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5096 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5097 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5098 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5099 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5100 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5101 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x525A88B0, 0xCDADC6F1, 0xA2BE3022, 0x70AC6832, 0x29493525, 0x2E1037AD, 0x678051E2, 0x0CC6834B},
	{0x171D9727, 0x0AE4190F, 0xF267BF92, 0x8237F643, 0x07470900, 0x92DDD495, 0x861221AE, 0x02D9EFCA} } ,
	 { {0x7FFC2B2B, 0xBD5116F4, 0xF9D60B0D, 0xFD32A07C, 0xD8980DEA, 0xB49134E8, 0x98F15181, 0x225DDEB5},
	{0x596AD021, 0x6123EC53, 0xD6464C71, 0x12D35750, 0xB188418C, 0x8575FC3B, 0x92CAA446, 0x079DB156} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5102 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5103 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5104 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5105 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5106 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5107 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5108 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5109 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5110 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5111 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC9264E0B, 0xADAD96A7, 0xDA7B03AF, 0xEE80AA65, 0xBB3111AA, 0x3B4B4262, 0x9C6547C4, 0x062E38BB},
	{0xC73682DB, 0x27264882, 0x0E364D42, 0x75C5ED0A, 0xB50EAF02, 0xFA5B3BFB, 0x93F856D6, 0x2097B9AE} } ,
	 { {0x9E2A4EAA, 0x9EF85CB2, 0xAA73561A, 0x1F5B1B02, 0x70D8A0C9, 0xB378A29B, 0x88367125, 0x004FE561},
	{0x6DB44C39, 0xE3A338C2, 0x9F83AB74, 0x21B285BB, 0x51B49939, 0x19C358A4, 0x3E445EE8, 0x21D3B010} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5112 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5113 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5114 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5115 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5116 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5117 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5118 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5119 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5120 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5121 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA98E66FB, 0x562BAEB6, 0x0EE845F9, 0x72BB9747, 0xD2B2FBCE, 0x937955DB, 0x306D1DB6, 0x0C24B515},
	{0x99B25E94, 0xEB1AD63A, 0xCF0884CB, 0x71D25740, 0x009E9A1C, 0x62F67D26, 0x49AEDEC0, 0x2280296F} } ,
	 { {0xD9DEE3E6, 0xDD1274C3, 0xECB574C1, 0x53185BAB, 0xFF179A5A, 0xD82D5C78, 0xEA12B365, 0x124FFC90},
	{0xD86DE141, 0xBDE84D96, 0x227A1FCB, 0x8D70565D, 0x82098108, 0x377AA431, 0x67DBFD05, 0x052FDDEF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5122 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5123 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5124 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5125 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5126 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5127 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5128 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5129 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5130 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5131 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x597CF586, 0x835A160C, 0x67BDBA5B, 0x02868BB8, 0x5360DCDA, 0x49C32681, 0x4A7EF0B4, 0x1F400026},
	{0xF65F6928, 0x034FCDD5, 0x5EB7E409, 0xE262BAB7, 0xD11D0B7A, 0x528ADEBC, 0xCF6A9BCF, 0x1DC36231} } ,
	 { {0x986D02C4, 0x56A4B788, 0xE4316C3E, 0x35684917, 0x6DB50CEC, 0xAAB408C1, 0xA6A75DE7, 0x0A963496},
	{0x00108151, 0x9C8F5036, 0x881B2FB5, 0x824CDA16, 0x2CBB71FC, 0x221F8493, 0xF53EBD05, 0x1E35907F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5132 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5133 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5134 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5135 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5136 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5137 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5138 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5139 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5140 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5141 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1B257F5B, 0xD732B49A, 0xFB2DC0FD, 0x1ABF364F, 0x3781E0F5, 0x02759091, 0x6CEA7E37, 0x2082E10C},
	{0x259265FC, 0x35B39481, 0xADD4436B, 0x3D324C46, 0x8D398C06, 0x9EEE349A, 0x07CC006A, 0x147E74F8} } ,
	 { {0xE5472867, 0x3225A366, 0x1491ACC3, 0x482A1754, 0x718CA352, 0x15CDD938, 0x36B9786F, 0x16DE8525},
	{0xBBFE4919, 0xC442E498, 0x22928DB1, 0xA9E2C878, 0x75B4299C, 0xF5EEEB99, 0xE6727217, 0x0F561A40} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xAA679CF3, 0xD7E9EC0B, 0x9F400476, 0x83C487C0, 0x9D5E8575, 0x47E5E7C6, 0x2073324B, 0x12AA1A26},
	{0x2FA2183B, 0x771BED6D, 0xCA247238, 0x269A5516, 0xA7696519, 0xFC2A6922, 0xFAED44EB, 0x041E25B2} } ,
	 { {0x81485D3D, 0xA6A22E95, 0xDE40F25F, 0x1F6A1219, 0xBB84D755, 0x3FBFF64D, 0x6154A459, 0x1C42E1A2},
	{0x3ABD79D7, 0xB7571859, 0x2F71C3B7, 0x1044A2AD, 0xC4AB668C, 0xE08E9E6A, 0x84EBA8B0, 0x20DF1813} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x655BE37D, 0x0DC8A535, 0xD23D06DD, 0x8BB9057B, 0x8F41A967, 0xC851B2DE, 0xA429E696, 0x0667480F},
	{0xD72AEC66, 0x7A16D7E1, 0x14C06289, 0x3C491B61, 0xE77BA4BE, 0xC551D2D8, 0xA990EB8C, 0x0B28AA96} } ,
	 { {0x52BFC6C6, 0x3AF987D9, 0xD2F7C467, 0x176F5FB0, 0xD7A4A310, 0x509F83F8, 0xA4F73447, 0x0B5A5A17},
	{0xA5D2579D, 0x1798A248, 0x4613AA20, 0x14AF738E, 0x8FBB0EA3, 0x61556415, 0x14056392, 0x08217B2D} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5142 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5143 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5144 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5145 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5146 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xAA71CC96, 0xCC9ACFE9, 0x7886B195, 0x856FD3EE, 0xDC45E2EF, 0x85CAAC21, 0xEC324C2F, 0x1C2E2FB9},
	{0x944A3BD2, 0x6C402735, 0x381D055C, 0x7493B265, 0x35386189, 0x534657A9, 0x24280706, 0x15F772AA} } ,
	 { {0x02AEC0ED, 0xE3D56527, 0x4EBEB8E0, 0x23F7ED9C, 0x80A53F40, 0x4459104E, 0xAD5F2D67, 0x1300086E},
	{0xA0D30FFF, 0x4474AF21, 0xA63DA033, 0x7CB6E63B, 0xEF8FD327, 0x1D5C70B5, 0x848B80B9, 0x04081DC4} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFE83E7E5, 0x8E88B30B, 0x1A86824D, 0xD71C4B0F, 0xFBB017D4, 0xA7A6FEC9, 0xF4D3861F, 0x0B5D675A},
	{0xAEC8B2AA, 0x73D601E1, 0x4B36A7A5, 0x2A6CE6E7, 0xB0C43EA9, 0xA5C44DC6, 0xA4C9D4CC, 0x088EC038} } ,
	 { {0x7EA9E254, 0x4962E32C, 0x7F486B3D, 0xFD837753, 0x8CE6E5C1, 0xB5DAD5BA, 0xD5793FA9, 0x0FE405DA},
	{0x623771AE, 0x468124B5, 0x426EA323, 0x2F51692B, 0xAE384DA3, 0x59510967, 0x49DD0440, 0x038445B0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3EF4A0FE, 0xDD7CE490, 0xC543724A, 0x171B7420, 0xE24BDF14, 0x6FEE02F1, 0x4E5F3390, 0x20F9330E},
	{0x86F97CF4, 0xFCE61932, 0xC86E0ECB, 0x7989F8B7, 0x6E8AC9BD, 0xCAEB3B7A, 0x4FB9A877, 0x237B5F8A} } ,
	 { {0x94AD97DC, 0x6AC204B6, 0xC60B1294, 0xC7A8C50C, 0x518B937D, 0xE61551D3, 0x620D0CC8, 0x2114FF9A},
	{0x11A89BE6, 0x49E2CAA7, 0x74A1F30B, 0x21541D58, 0xF63893D8, 0xA7B6A0C6, 0x18C72D16, 0x1946F694} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5147 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5148 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5149 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5150 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5151 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x06076084, 0x1CDE13BE, 0x8C2EC3BC, 0xD8EE04CA, 0xB297D4B1, 0x7364128C, 0x699A26DC, 0x14D7EC93},
	{0xBEC88D8B, 0xE5895F0D, 0x58524711, 0x7F410F2B, 0x684FB7C6, 0x29ECC1DF, 0x8E16BEF0, 0x0AB6F10C} } ,
	 { {0xFEED621C, 0x74E60634, 0x94E1BA9C, 0xD3485FC6, 0x5F5952F8, 0x3FCE4430, 0x1C88B4D1, 0x19D3654C},
	{0x8196526A, 0xA7CFB247, 0xF5F6F3B2, 0x420B1C58, 0x43609376, 0x301A895B, 0x6E93C520, 0x11959BD3} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x89191E4D, 0xB7DFE470, 0x01562F5D, 0xFCE07004, 0xAE6EF77B, 0x67BD799B, 0xE9E1B8DD, 0x0D801841},
	{0xE2A8934B, 0xFC290A73, 0x97D5EDB9, 0xB9EF7B58, 0xC45679BF, 0x4E684738, 0x31C97228, 0x05DAA88B} } ,
	 { {0x2BA67896, 0x21210011, 0x7BF55991, 0x365FB509, 0x44411E51, 0x0B745BC9, 0xFB44515D, 0x171049D8},
	{0xECAE3F8D, 0x0066CEC8, 0xB1C37912, 0xFDCEC054, 0xE1A2A85F, 0x2DCE059B, 0x7F0F20F9, 0x0C1EB266} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x39C93A6D, 0xEA4AA6FC, 0x9400A1D3, 0xC218A9E8, 0x83E9A806, 0x3FD1E76A, 0xDC86C83D, 0x1ADEB442},
	{0x85CE4E3C, 0xFB3B17F6, 0x2381FF1C, 0x2367FF00, 0x76C564E0, 0xF265B5BB, 0x21C6B81B, 0x1C7FF350} } ,
	 { {0x15E97035, 0x0A06ED2D, 0x2FE1D63E, 0x74981F89, 0xBD2CC42F, 0xD47C8DD6, 0x027615B9, 0x03009E79},
	{0x39AB3C2E, 0x49888C37, 0xFE8F0FC8, 0x88A0DF8A, 0xE00B88BF, 0x633E85D2, 0x0E91AB5E, 0x02F75C87} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5152 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5153 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5154 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5155 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5156 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8744B4C2, 0x4F3C273E, 0x85704ADF, 0xCF4EA32F, 0xB752AF5F, 0x632DF61E, 0x9387599A, 0x0F4313FB},
	{0xF12E42ED, 0xAA1282EC, 0x9EF8345E, 0x7088F183, 0x601A35E4, 0x062ECCEA, 0xD4104843, 0x24E28334} } ,
	 { {0x25FDC89D, 0xFAC8B6B4, 0x4217E90B, 0x92990452, 0xD47CFFC4, 0xE6CC8E04, 0x993A6C90, 0x0C9C74F6},
	{0x6A8B2DBE, 0x8DE79D4D, 0x2A5F1DF4, 0x3BC86546, 0x950DF3CA, 0xB650243E, 0x3915122A, 0x175C7AE3} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x78B0B147, 0x19ED39EC, 0x1E906868, 0x75BC2260, 0x2AFD5BFD, 0xF42112BA, 0x23765B53, 0x02A0D5A2},
	{0x9AA74915, 0x580D40DC, 0x5250C0D4, 0xACB064A7, 0xBC0962D8, 0xB9B9AFBD, 0x9E648E74, 0x1F5FC16E} } ,
	 { {0x8B437CA9, 0x47AFE3C9, 0x7C0D86AF, 0x544A3F65, 0xBD1C9C31, 0x2B456C43, 0x7476F660, 0x250FCDC5},
	{0xE42CE3AF, 0xB8A13123, 0x46A15A67, 0xD7817B53, 0xB8B011DE, 0x79993209, 0x02BC8DCB, 0x07F0A0A3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8AEF8456, 0x9F309218, 0xAF028A95, 0x4E3188DC, 0xC747CEE5, 0x40FEF77B, 0x9251AE19, 0x16256ADF},
	{0xEB1EF4B5, 0xECD2ECA5, 0x8A780FC6, 0xE1F91820, 0x93FE455D, 0x7B1DDBE6, 0xDEC671C8, 0x117CA725} } ,
	 { {0x411F09E0, 0xDBC42D86, 0x50F90A28, 0x155F7400, 0x8EE468EE, 0xE8BBBB47, 0x058583C1, 0x00EE77C6},
	{0x904CB385, 0x9D411696, 0x480EB3EB, 0x7444E17E, 0x51D68012, 0x14485796, 0xB85A1632, 0x2256B422} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5157 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5158 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5159 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5160 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5161 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8C89D368, 0xE75FE90E, 0x4A8624CB, 0x3277D8D0, 0x307CC6FD, 0x25D97288, 0xC06C5B55, 0x1E42E82E},
	{0x764765B9, 0xBA9B221C, 0x20FE0AE9, 0x86B6F733, 0xC4C62A81, 0xAA655C94, 0x7E4B0E62, 0x00B96544} } ,
	 { {0xEA0A3EF5, 0x4C5C20F4, 0xFDD0CC89, 0x39F2B4BB, 0x15246F3F, 0x290EE7AB, 0x2722C77C, 0x008359BC},
	{0x53BCAD06, 0x3195C89F, 0x8B7BA90D, 0xE6617EB5, 0x106AFD3D, 0x8722F05C, 0x323F91C2, 0x12172733} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x086576CE, 0x0874694C, 0xD3AFBFFA, 0x642EE9EE, 0x9C88138B, 0x8645EB68, 0x687A1F21, 0x240E88A3},
	{0xCD44A8D3, 0x065AA639, 0x4245E7B6, 0x21DDF11F, 0x72B5AEAF, 0x2FBDBDB6, 0xA48B4D0C, 0x0F305A9A} } ,
	 { {0xDC6604F1, 0xBA8ED3B7, 0x070FCD46, 0xC9E36ACC, 0x2BFD3437, 0xF2350C2A, 0xDA061660, 0x01278B97},
	{0x924981FF, 0xD73FF777, 0x01A560B0, 0x70AF1E80, 0x54759924, 0xC95DA089, 0x84F2A6D5, 0x0AE243D3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA8F711E5, 0x80827C64, 0x65F99BD1, 0xB50316F5, 0x439A4915, 0xDA5C9744, 0x2EDD2BD1, 0x00E28076},
	{0xA1115B26, 0xAC08AF46, 0xDAA30E7F, 0x9FD17CEF, 0x009C6D01, 0x908FEEBB, 0x376A1130, 0x1321F2F9} } ,
	 { {0xEE7DDACE, 0x4695654C, 0xC1B23C42, 0xA1E89AE4, 0xF9B042CF, 0xA11DC5E8, 0x8A63BFCE, 0x101F97B8},
	{0x05737D83, 0x9BBC133E, 0x960D70E3, 0x4BFD42D2, 0x7EA5AEDA, 0x6B71C56A, 0x5268BBF6, 0x18E6F275} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5162 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5163 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5164 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5165 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5166 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8009F496, 0x4A5DC7C6, 0x93D3C189, 0x1C3B6A90, 0x4C0357D5, 0xB9A1AF95, 0xDBC4BB1D, 0x11C36D79},
	{0x7C15D6F5, 0x99BD53E6, 0x982A69E9, 0x82BEDFAA, 0x033C068B, 0x7A696275, 0x6E23E089, 0x0306039E} } ,
	 { {0x830E6CE5, 0x513C0B33, 0x15312D90, 0xBED49155, 0x0974A5E6, 0x828C40C2, 0xE5FCDE5E, 0x20731239},
	{0x93C86FB5, 0xE556FAC6, 0xD331282A, 0xE89CA5AC, 0x7345A8A7, 0x81A2AA1A, 0x21476457, 0x1F0043A1} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x99841D64, 0x55D74D53, 0xA79DDA12, 0x60171535, 0x6491B7D9, 0x8A881505, 0x0F15C2F6, 0x1AB3D995},
	{0xC1BBE6BD, 0xAFB8E362, 0xBE964C14, 0x2750B69F, 0x091AE6D0, 0xD0512ABA, 0xA327B5F0, 0x1E9FC871} } ,
	 { {0x5936CA37, 0xE2E429A0, 0x13F3FBDE, 0x5FEBB4BB, 0x0AA73051, 0x5EFCA0E3, 0x0B675FE8, 0x011D476D},
	{0xC126BBA5, 0x27105CF8, 0xEEAAB819, 0x2B8DF1E3, 0xA276B21A, 0xA80B85B1, 0x9D6872CE, 0x1B7B28E4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x821F3859, 0x994550CC, 0x72CA2A45, 0xF98DD30C, 0x941D98FD, 0xFEB5B848, 0x57261A32, 0x23F131FE},
	{0x3DD65A76, 0x2268C16A, 0x63BA82BE, 0xE1D22D3D, 0x852AEDDD, 0xF947FB86, 0x329C259E, 0x133378DB} } ,
	 { {0x8A751267, 0x8ABE6B17, 0x96961F0E, 0xE621CAC0, 0xAF3A920E, 0xEDA3BFAA, 0x7AA255E3, 0x22A57B14},
	{0xD42E3A61, 0x8B886FF5, 0xA975BF87, 0x3293667D, 0xCF3ABFA3, 0x9BA97A5A, 0xDB5685D6, 0x06CC0F91} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5167 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5168 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5169 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5170 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5171 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x9FC0C769, 0xF53EFA47, 0x5D541896, 0xD8086120, 0x38A7C2A7, 0x71B92C5D, 0x513506B5, 0x1D23E875},
	{0xC7C83664, 0x86CE4F33, 0xEAB0817E, 0x704989CE, 0x56C794A6, 0xD5F5CF93, 0x8B2E804F, 0x061638EA} } ,
	 { {0x46AD7B3F, 0x0BD246E5, 0x71446545, 0xD7606AE5, 0x1F9BA583, 0x15EE052D, 0x3BD7E593, 0x24A91518},
	{0x02D26243, 0xB7FE09A4, 0xD37BA188, 0xE8C5DA43, 0xDF4B79D6, 0xDAEC0C9C, 0xFB1A31B5, 0x12835EB0} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x13E910DF, 0x08DDA59B, 0x19C0BDE7, 0x1A0D5D58, 0xAE1DC520, 0x1418F2CF, 0x2702A1CC, 0x219AE843},
	{0x9C1383E3, 0x6B52E4E7, 0x9A42268C, 0xBE682D6B, 0xBE76112F, 0x0425B32B, 0x7F46718D, 0x132338F3} } ,
	 { {0x9D76E2CB, 0xE1DDE619, 0x88914CAA, 0xC58C5BE6, 0x3BE9A31F, 0xBA48B613, 0x368B39C9, 0x23787378},
	{0x397474F6, 0x8B97E703, 0xBD67584C, 0x27C2639A, 0xF8E8CF13, 0x5914B8B1, 0xC79FB525, 0x23123649} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x5C9BD90E, 0x0F10A33C, 0x857CE340, 0x99BF4E01, 0xF2248790, 0xE5661CAA, 0x4FAF9106, 0x1B5B18F9},
	{0xFDC50425, 0x422B9EFF, 0xBAC72885, 0x8016A81F, 0x12111ECD, 0xFDA67B2A, 0xF03404E5, 0x188F1BDF} } ,
	 { {0x1C34FC8F, 0x146C2317, 0x36DD20A9, 0xBC9C8782, 0xF2E6CD83, 0x95C6995B, 0x6B4B32D1, 0x0A7A0004},
	{0x3B636233, 0x63FA097C, 0x75B1A3CC, 0xBDF02676, 0xC1475356, 0xD48A3FFB, 0xA806E3F1, 0x0F157716} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5172 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5173 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5174 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5175 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5176 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5070AE63, 0x1C018AF5, 0x532A9A31, 0xEE17894C, 0x74377B91, 0x93888D43, 0xD67CDF4B, 0x0EA59677},
	{0x9C657F97, 0x0257B18E, 0x37290EA8, 0x5DD378B7, 0x7082D2A8, 0x6CFCDBF3, 0x287E0C7E, 0x1025471D} } ,
	 { {0x584D3FF8, 0x5DB8F3EB, 0xE51F0BC3, 0x7DB0A505, 0xEBAB7D49, 0x36440B03, 0x850C4B77, 0x17544F87},
	{0xBBDADC98, 0xA347E8C5, 0xEA465674, 0x42275765, 0x4D3453A4, 0x77C11E32, 0xAA7749D4, 0x1F92F4EB} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x4EC04203, 0x337E444D, 0x37270160, 0x99F8952F, 0x3253741A, 0x6BD27F43, 0xBC93B397, 0x0E5EAB0E},
	{0xAAC3C4E6, 0xE3BD4E8C, 0x3C59D07F, 0xFDA8DD17, 0x545DF237, 0x5C23846A, 0xE6758BF8, 0x1D4D239A} } ,
	 { {0xDB5BF1D5, 0x64624CB6, 0x1E8E48E8, 0xF81B0A5E, 0x6E89BB6F, 0x98B9C032, 0xFD84F417, 0x0BA47D56},
	{0x3AFEEF5B, 0x86D81559, 0xC437A06F, 0x8617FEF1, 0x0D58B12A, 0x56EFD866, 0xC0F12AC6, 0x22E3DD35} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD0FFED04, 0x1DBA87F3, 0x8674B639, 0xE6FF8579, 0xAD047D67, 0xE4B52FBC, 0x6CDAB307, 0x08A0BB5C},
	{0x9634E0A5, 0x23C84BC1, 0x2FB64942, 0xF80FFAA3, 0x9CBE5356, 0xC303D5A5, 0x0B05D8BA, 0x24C3F99A} } ,
	 { {0xE62D55B5, 0x444FEE1F, 0x14FB6EC6, 0x9FD29369, 0x9050055A, 0x406BF633, 0x3AA20DFD, 0x0FCF8723},
	{0x1341D17A, 0xF6620659, 0x5D46A925, 0xE1AAA65E, 0x3B11FFCB, 0xF46A29D6, 0x8E2417FE, 0x22ED8FE9} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5177 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5178 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5179 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5180 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5181 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD98C097F, 0x764D4B26, 0x8B5D966E, 0xB2E38A18, 0x818F7B63, 0xAAF6E93A, 0xD0F917CF, 0x10DC0FEA},
	{0x95B3461D, 0xBE93BDA3, 0x4E79E184, 0xBA5B7683, 0xDFFA3284, 0x07E52703, 0x6B9D9A7D, 0x190B5337} } ,
	 { {0xC5956B43, 0x1B61C3E6, 0xC55CFA46, 0x9B70061D, 0x909656F3, 0x06CB71DF, 0xEE999824, 0x1D9CC750},
	{0x0139ECA1, 0x081063C0, 0x65CB471A, 0x6811C32E, 0x0F4B8627, 0xB49D1549, 0x3E08D7D3, 0x03532F06} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xA6FD40DE, 0xBF482526, 0xABC5AEA9, 0x6ACE9484, 0xAECDD602, 0x1691524B, 0x76F01416, 0x23AA0CBD},
	{0x02916A26, 0x73EC9E39, 0xB08AF0BB, 0xFBE7229D, 0x8A605B12, 0xB4CFD676, 0xCFE5D5F6, 0x046ACCFE} } ,
	 { {0xDB3C8926, 0xC44FB0D1, 0x15082043, 0x57236CA9, 0x6B976A0C, 0xCF33EEF5, 0x5D19C9D3, 0x0E720A9D},
	{0x0D9CB995, 0x8F180849, 0x2B42AD6E, 0xB2D27EAC, 0x933D4951, 0xE5F0D151, 0xC556D2F4, 0x0E4C7FA7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x587CE2DA, 0x289366A8, 0x19F3256E, 0x120A8CDA, 0x25AF97A5, 0xD74C2D8D, 0x7E3B0F8B, 0x23B5CDE8},
	{0xE59EA44E, 0x1F419516, 0xEDA5FE99, 0x36C77729, 0x8ED0BF52, 0x7C95E60D, 0x71C6D942, 0x19ABB863} } ,
	 { {0x269E7C7F, 0xF51031BB, 0x0615689A, 0xF6F07B0E, 0xFE6D5574, 0xA19C11CE, 0xFB0FE712, 0x0F58D3BC},
	{0x628BBA68, 0xC7AC3168, 0x562109CD, 0x99A6A344, 0xB1325A9E, 0x014A5DD0, 0x3292F5C5, 0x23021956} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5182 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5183 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5184 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5185 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5186 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x75BFC602, 0xE03FD312, 0xCA286463, 0xD7629878, 0x17C04792, 0xAFDC3E59, 0x0C0DD1C2, 0x0C3736DE},
	{0xB38D4890, 0x9E324BE0, 0xF4640BD9, 0xA3528606, 0xE3491B34, 0x1795964F, 0x69247BA0, 0x03B825CB} } ,
	 { {0xD1223791, 0xB4540936, 0x7794FDB8, 0x86A1C18A, 0x5703610F, 0x6EF2735B, 0x6B8A8712, 0x15EF1BB5},
	{0xD92F3062, 0x031B4236, 0x71987D4C, 0xC39921A8, 0x24B180B0, 0x1F9114BC, 0x73A842CC, 0x1A22C503} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x3A2D027B, 0xBEBF788A, 0x00C1A57A, 0x6B301A04, 0xBF4A8E0E, 0xDDFD9B36, 0x014B1FE9, 0x1D2730C4},
	{0x7E1AEE53, 0x5D8DD315, 0xADE4D6D0, 0x55D86DFD, 0xD83E5DB5, 0x07999926, 0x13AAECDF, 0x166EA818} } ,
	 { {0x173D57F4, 0x98578C4D, 0x92A6A855, 0x50420A90, 0x1558C0B7, 0x23ED80E7, 0xEB24ABC9, 0x1190A787},
	{0x78B69C43, 0x18C86DF3, 0x3C282423, 0xFE04C946, 0x8E674A74, 0x0D276C8D, 0x059890AD, 0x0B119882} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xCFBFE713, 0xED5E62F1, 0x4F716F35, 0xF8C53AB7, 0x6B0DAAB9, 0xB9CB46B0, 0xFF6054E1, 0x01B670E5},
	{0xE9D8FF2D, 0x8C0A86D1, 0x014932EF, 0x2C5B0567, 0x00B36579, 0xA90B8470, 0x25B3F541, 0x0197990F} } ,
	 { {0x80E8DC85, 0x7C14C6AD, 0xECF9D941, 0x9B5D0730, 0x2681B4AA, 0x160130E2, 0x522948F2, 0x1C0EF3A1},
	{0xB000309C, 0x771BD9DF, 0xE009FF9B, 0xF7204065, 0xF9F26B40, 0xB87B58AF, 0x809D15FB, 0x13AEFE5D} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5187 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5188 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5189 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5190 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5191 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x74FE974E, 0x0D7432A4, 0x3AAFFFD5, 0x5EECDDB1, 0xE0AF8808, 0x65B8C1DD, 0xBDC396E5, 0x041CCE38},
	{0xD505CFEE, 0x255D61CB, 0x4E235846, 0x353843B0, 0x655531E1, 0x16325C22, 0xD9A51CA9, 0x0EC5FF52} } ,
	 { {0x6CFEAB8E, 0xCAE4B275, 0xCAD5D1F2, 0xD68E125E, 0xADB3E35C, 0x936883ED, 0x3BED77CD, 0x00CB0219},
	{0xC2B24AB3, 0xD697A78C, 0xAA07188A, 0x3D8D355B, 0x6A9324B7, 0x9FFC899F, 0x3E17C83E, 0x0616D8DB} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xEBD7B450, 0x04CA1964, 0x68CF13C0, 0x53D163C8, 0xCCFBBCFD, 0x9A008C33, 0xB313BDEE, 0x07EC4A89},
	{0x9A53ACBC, 0xAC19ECE2, 0x1D125143, 0x44FE590E, 0x1170F608, 0xF8F35614, 0xC4999115, 0x063ED71A} } ,
	 { {0xC6C7098C, 0xF55D2ABE, 0x835C61D5, 0xB1331825, 0x8E7D537D, 0x7BCAB62B, 0x0C7F3DCC, 0x0C6024F6},
	{0xB57112CB, 0x341859D5, 0x7F591594, 0x1BD1A943, 0x9C168FA5, 0x1C075439, 0xBD85A1A8, 0x07A63EEF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD73CAEB8, 0x0F278632, 0x2B44864F, 0xBB412F4B, 0xB308E615, 0x598C1D6D, 0xFD17236F, 0x1643835E},
	{0xD6F0CD2E, 0x7C5F5F69, 0x23F2DB40, 0xFE598628, 0xBD9D9639, 0xF964D540, 0xC9DD8077, 0x18CF7D27} } ,
	 { {0x3411C9D7, 0x9B1F501D, 0x8621F3E7, 0x7F2C02EA, 0x8F02318F, 0x73E31F28, 0xB0F5A211, 0x0FD7A726},
	{0x4E80450A, 0xCA7A731A, 0x2A3B553F, 0x5E933DED, 0x256FC76E, 0xC51CD966, 0x66A58493, 0x0501C34F} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5192 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5193 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5194 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5195 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5196 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x11C61921, 0xA4CB8123, 0x5E4287FE, 0x05BB1DB3, 0xE6EA8452, 0x98009B44, 0x9419A48F, 0x12881F94},
	{0xB78B853D, 0x8E073F43, 0x3CF696B0, 0x02EBD8A0, 0x4C14728A, 0x3DAD9613, 0x0B604F41, 0x048559E8} } ,
	 { {0x83F6CBD3, 0x817D12E7, 0xECE987BD, 0xDA20C2A3, 0x95DFE1C7, 0x2EB04361, 0x7121D359, 0x0017EC45},
	{0xE34ABEB8, 0xF48317FF, 0x3FEE64B7, 0x6A4301C1, 0xD1B16F5C, 0x72E5EE62, 0x0EEDBB14, 0x1DC1BA72} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF88F15EA, 0xA3449B9E, 0x81357335, 0x7CDA2CE9, 0x1F089C74, 0xF0D72B03, 0x844F3711, 0x1173BCED},
	{0xD5E3F170, 0x533E6447, 0x3D585F07, 0x873A03D4, 0x7B359664, 0x17E0F201, 0x3DA3937B, 0x218D1F34} } ,
	 { {0x07D4E49A, 0xBAF7F422, 0x767C375F, 0xCC3DEB71, 0x31F1E4EC, 0x2F87CFF4, 0xF305555F, 0x15655B71},
	{0xD7D73E6D, 0xD63042FF, 0x9FBABA1F, 0x13888AF1, 0x9A66ADA0, 0xD723935E, 0x361D3FAB, 0x1D473F2E} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x27485417, 0x014BAA3C, 0xC5633EDD, 0xBEBCBC82, 0x33FA6C06, 0xB6043CE7, 0xA9F11B08, 0x24C75A22},
	{0xA14C043D, 0x237F0E6E, 0x19D9DA7A, 0x6B6AECA7, 0x92ED16E9, 0x5BFC627F, 0xC8DB5678, 0x2040EC6C} } ,
	 { {0x8AF6F635, 0x3C2019DB, 0xCDBA74DA, 0xF9B0765E, 0x46A3ED3B, 0x1C8FC6EB, 0x2F39AB88, 0x0F150076},
	{0x8220A49D, 0xFD44234B, 0x765C791A, 0x42C22D41, 0x821FF53C, 0xC0FBF05D, 0x78C00AE9, 0x0CE8AC07} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5197 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5198 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5199 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5200 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5201 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x29FBC5DB, 0x9CE0D5E1, 0x179F0F91, 0xF61A32AF, 0x31F72A75, 0xA0ED0D3E, 0xF7862649, 0x1758FA08},
	{0xEABE2996, 0x562A6F3A, 0xBDB77DB7, 0x75A50F50, 0xD878281E, 0xF34EA0C1, 0x3F9CD2F2, 0x0245E71D} } ,
	 { {0xDC072843, 0x4364C1B5, 0x308AF36E, 0xD6B80141, 0x7EC068F7, 0xA37A586D, 0x348EBD97, 0x0597C94A},
	{0xD06EEA0D, 0x7F0B3B20, 0x3704611C, 0x8BB6DB25, 0xF81061D1, 0x83E196C9, 0xC8708F8E, 0x0EDC4BB5} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x5CEF114E, 0x4B87132F, 0xA065F45F, 0x8D52E2B7, 0x7EEDAF80, 0x36EC7A25, 0x0E42685E, 0x12C6D396},
	{0x45670F53, 0xD4DCA434, 0x86415568, 0x205DF85B, 0xCD072BAF, 0x51576614, 0x7AC02AD6, 0x02F7FB86} } ,
	 { {0x2B16740C, 0x8ADC31B1, 0x94A39B95, 0xADD4FD44, 0x27BD77B0, 0xDF480EC1, 0xFEC60152, 0x06FE80B0},
	{0xD0FA5219, 0xCA074E2C, 0xF75408B0, 0x63459E12, 0xE51C5C20, 0xB98B56BA, 0x8C97EB6D, 0x1069EAE5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7C4FE636, 0x0920047D, 0xDFFA1D53, 0xCD5134B3, 0xB807009A, 0x510F7DD2, 0x5FA77E78, 0x14EFB670},
	{0x56249557, 0xA5FEFBBE, 0x53D52ACE, 0x63BA16BA, 0xF4F72FB4, 0xA56E6F83, 0x99C177FA, 0x10F8BE45} } ,
	 { {0xDFFAE467, 0x9973C0F0, 0xFBF3071A, 0xBACE79FB, 0x2B7B4761, 0xF48E723B, 0x4B13A020, 0x017D4208},
	{0xDB7B875F, 0x1D1320CE, 0x2C821183, 0xDC0C088B, 0x494726BC, 0x302A4ACD, 0xD2C52035, 0x242DBF8A} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5202 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5203 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5204 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5205 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5206 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8406DAD1, 0xF65CB936, 0x29BC47A7, 0xCB2CC699, 0x83D61990, 0x780049F2, 0xE2BDC2BE, 0x1033B41B},
	{0xE1F06C82, 0x15540F0F, 0x967329CC, 0x47014C37, 0x959DCC10, 0xB3251BBB, 0xD7B6A3BC, 0x15941E49} } ,
	 { {0x27EC56E5, 0xA4B6BEEC, 0x3F90B298, 0xD6B4EC83, 0xEAE46C5B, 0xCF931F9F, 0x57B2963B, 0x017A5F0C},
	{0xC4624340, 0x069BE34C, 0xC7A6B432, 0x2C401B7B, 0xF65623E0, 0x56258BFB, 0x40A73077, 0x11667A52} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF9A9A2A0, 0x5B91EDA2, 0xC990067C, 0x21BF8E1B, 0xAE5A190F, 0x9692D01A, 0x476C015F, 0x1E33BEB8},
	{0x045A1E69, 0xBEDD6413, 0xDCE02E42, 0x4B0BAEAF, 0xB03E48B0, 0x1EBCB35E, 0x5EB96F99, 0x0A052520} } ,
	 { {0xAB7626F8, 0x9311E91A, 0x989BEC20, 0xE4134BBA, 0xE3AB5E54, 0x484DEE27, 0x5709098C, 0x0181FEB0},
	{0xBBE391A3, 0x94653FCC, 0x7513994B, 0xD81EA306, 0x53A258D0, 0x96888447, 0xD2E20735, 0x0A245F44} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8AB3F42F, 0xCECBCF3F, 0x3C3954A0, 0x18D43B52, 0xB51F5AA2, 0x4B4AC91E, 0x1414876F, 0x158D9131},
	{0x8BBFA0EF, 0xB81B6DAC, 0xE916A765, 0x469C8C8B, 0xF0C3959A, 0x9058384F, 0x949FD8A5, 0x0A873C61} } ,
	 { {0x3362E4F8, 0x25E2589E, 0xB5B1922C, 0xCA3E89C8, 0x7000A1BA, 0xC136E24B, 0x0459C45D, 0x1720A6AD},
	{0xEBBD0FCC, 0xD0BAC47B, 0x85779085, 0x0A927F19, 0x7A893642, 0x37F03CF1, 0x63F6F2E2, 0x0EF517D0} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5207 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5208 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5209 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5210 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5211 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x739EF35D, 0x1DA7AF82, 0x97803BA3, 0xD333381D, 0x787B8A35, 0x9FF682B1, 0xED02A2B4, 0x1ADDA1DF},
	{0x5C583EC4, 0x7E59EDE5, 0x276B07E5, 0xB175EE7C, 0xD1E176CF, 0xF6C9FF38, 0xBC755274, 0x11250E41} } ,
	 { {0xFC58DB0B, 0xA77FCCC3, 0xBE6FF085, 0x3A7A59C8, 0x06B46566, 0xA711D78D, 0xE5575B59, 0x1ED7844D},
	{0xC907601F, 0x2E2BF264, 0x3910D005, 0xAFFA19D7, 0xE87A8EE0, 0x282B16AF, 0xB5E303EC, 0x0F72B060} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x896B9D2D, 0x38407BDB, 0x568DD898, 0x87814AA8, 0x91A274FE, 0xD058DA99, 0x761F0EF6, 0x00A842F3},
	{0x22E149F7, 0x82DF1E3F, 0x5FEB3A12, 0xF3F653E6, 0xCD47CF4A, 0x9C9383D9, 0x1F3AB4A7, 0x0B144283} } ,
	 { {0x71F1280C, 0xD336B6E8, 0x89823280, 0xEE668E08, 0xC6A355B9, 0x2CA44FCC, 0xD8DAE6E2, 0x03B9008D},
	{0x07B0CEC8, 0x2794A8E4, 0xCD542E8A, 0x0AD07223, 0x1054D41E, 0x14752E02, 0x366FB4E2, 0x15B13BCB} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3508E311, 0xFFE518D0, 0x56738601, 0x04894159, 0xE5E0F485, 0xD77ADEAF, 0x9CACDCFF, 0x1228FCFD},
	{0x0EB83115, 0xC60416B8, 0xA6DDE7E2, 0x943D1EC9, 0x51F7C915, 0xC6ED88D2, 0x04B84DB7, 0x24F08216} } ,
	 { {0x89505EAC, 0xB421AD5F, 0x98E8F6CB, 0x78A1EF0D, 0x1650BFB6, 0x4F779AC7, 0x9C739EE0, 0x0312A802},
	{0x2F5A3E04, 0xF70FAED0, 0x18DA33C3, 0x5C49A1E2, 0xD76C1A0B, 0xA4308E6E, 0x2B546967, 0x222983FF} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5212 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5213 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5214 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5215 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5216 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x6E5E07D5, 0xD77A391A, 0xE4734280, 0xE81D4833, 0xBA8A931D, 0x433DE5C5, 0x5AE3A984, 0x1A3EB7A4},
	{0x899EEC1E, 0x0245D57C, 0x5FB52ED1, 0xC05E3087, 0x4146B86C, 0x34DFCA4C, 0x75BF5787, 0x0EA5F503} } ,
	 { {0x907A1FC5, 0x517A92B4, 0x06BE3E9B, 0x299FAA45, 0xB97435D9, 0x92DD11DB, 0xA8C3C185, 0x03AE67EA},
	{0xEA25C4FD, 0xB9948F60, 0x17CE36AD, 0xAB3D4D29, 0x1283C460, 0x79E8BCDC, 0x5DEEA13D, 0x0A41D57D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x798F390B, 0xC80C032E, 0x126000A9, 0x5FBF9018, 0x227ECDE6, 0x9F3FB3DC, 0x6620FB24, 0x21970877},
	{0x5119C289, 0xC0E1AF05, 0x74DF885A, 0xF181AA25, 0x4308B59E, 0x860879D9, 0x21D98C40, 0x12492F9E} } ,
	 { {0xC421DD64, 0x84FDBE1F, 0x8F309F16, 0x2B135FC8, 0xDDF1B6A8, 0x6F36FA67, 0x7E36CD53, 0x1BF62814},
	{0x002702C9, 0xD38DD055, 0x5D0ED80A, 0x7A4778F5, 0x406F4C12, 0x2EE15FB6, 0x0FA39351, 0x24EA2D0C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC5D79497, 0x2A80282F, 0xD6490DD7, 0x1ED6B930, 0x8BEA824C, 0x24994D6D, 0x5C03D8E3, 0x15ED8C8C},
	{0x49564C0B, 0x5A4B2E4E, 0x045BAE84, 0xA576ECCC, 0x2C3FADAD, 0xD15D463F, 0x062EA008, 0x04A2D53E} } ,
	 { {0x95B175E2, 0xF466FE15, 0x72A9EF2E, 0xE34723F7, 0x08AD3FD4, 0x085E5A5E, 0x19C85FFF, 0x050F8B9D},
	{0x55A69A8D, 0x896F498E, 0xE17B7461, 0x351A9408, 0x3827B9AD, 0x7A149951, 0xD7371C7D, 0x1320ADF8} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5217 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5218 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5219 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5220 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5221 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD0E34DBB, 0x9FDC6298, 0xC6F119BB, 0x0D326D3E, 0x88E48E47, 0xB7CBF297, 0xC817142B, 0x00E88C64},
	{0x81B3EAE9, 0x800CE4A4, 0x021A7819, 0xCEA444FB, 0x44955FBB, 0x4DA33992, 0x7F4CB58C, 0x12A60CD9} } ,
	 { {0x6528B00D, 0xCB33DAC1, 0xE27F976E, 0xEE2B424B, 0x680EB0F8, 0x4ED856D4, 0xE1C204E8, 0x02BC37F2},
	{0x2C5E6F7A, 0xF3BE1C21, 0x0D0A954B, 0x5763085D, 0x58B31855, 0x2870561B, 0x0F8E26E0, 0x1C20C2CF} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD0E34DBB, 0x9FDC6298, 0xC6F119BB, 0x0D326D3E, 0x88E48E47, 0xB7CBF297, 0xC817142B, 0x00E88C64},
	{0x81B3EAE9, 0x800CE4A4, 0x021A7819, 0xCEA444FB, 0x44955FBB, 0x4DA33992, 0x7F4CB58C, 0x12A60CD9} } ,
	 { {0x6528B00D, 0xCB33DAC1, 0xE27F976E, 0xEE2B424B, 0x680EB0F8, 0x4ED856D4, 0xE1C204E8, 0x02BC37F2},
	{0x2C5E6F7A, 0xF3BE1C21, 0x0D0A954B, 0x5763085D, 0x58B31855, 0x2870561B, 0x0F8E26E0, 0x1C20C2CF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x1E6ECE93, 0x0EDA6B92, 0x01ABC983, 0x1CBEEF6E, 0x16605673, 0x299A6914, 0x481B7ED3, 0x232C3DDE},
	{0x6CE81671, 0xA13A8181, 0x1FF18366, 0xE4A34435, 0x2623224B, 0xC05E926A, 0x4632569F, 0x13A97FC6} } ,
	 { {0x11E5796C, 0x328DB927, 0xD49E8669, 0x8AE9B1C5, 0x0D83E713, 0x874048CB, 0xB2231B02, 0x01AC771A},
	{0x91791A88, 0x671F5545, 0xE9362AC0, 0xD6B4EB5F, 0xC4D9BDF0, 0x61BB9D6A, 0xD636CC34, 0x19ADD845} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5222 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5223 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5224 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5225 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5226 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xDDF8E5DE, 0xBF278851, 0x18E3CEE7, 0x4A2A7F10, 0xE1E8E122, 0xC5F10339, 0x10C160E4, 0x040EDF9E},
	{0x7EC91875, 0x05433D4E, 0x1A254FDD, 0xC3BD571C, 0xF62813C9, 0x965E925B, 0x23BC317A, 0x04457D15} } ,
	 { {0x3715E6A2, 0x3EA49B15, 0x744739F1, 0x9410B7B5, 0x0E4F111F, 0x1981059A, 0x5D965E32, 0x0B01CB7A},
	{0x4B970715, 0xEEB72D61, 0x6D68AA6C, 0xFEF72B36, 0xAA5963EF, 0x5D01FFBB, 0x8D2F6278, 0x1E8FAE6A} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xDDF8E5DE, 0xBF278851, 0x18E3CEE7, 0x4A2A7F10, 0xE1E8E122, 0xC5F10339, 0x10C160E4, 0x040EDF9E},
	{0x7EC91875, 0x05433D4E, 0x1A254FDD, 0xC3BD571C, 0xF62813C9, 0x965E925B, 0x23BC317A, 0x04457D15} } ,
	 { {0x3715E6A2, 0x3EA49B15, 0x744739F1, 0x9410B7B5, 0x0E4F111F, 0x1981059A, 0x5D965E32, 0x0B01CB7A},
	{0x4B970715, 0xEEB72D61, 0x6D68AA6C, 0xFEF72B36, 0xAA5963EF, 0x5D01FFBB, 0x8D2F6278, 0x1E8FAE6A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x891532E2, 0xA9526430, 0xC122D1E5, 0xFAAD8AC2, 0xF29D0BFA, 0xE3FAEE7E, 0xDA710022, 0x13462B8F},
	{0xC645B023, 0x19786B96, 0x944C2446, 0x4BA295E7, 0x0A404336, 0x71E636FE, 0x3E340CD7, 0x0952B1A8} } ,
	 { {0x8F8C82DE, 0x891AEC91, 0x39E264E9, 0xA725EE4A, 0x4C54F995, 0x7996D47F, 0x35D932A5, 0x13F96B32},
	{0xF1CA0220, 0x1A4E6976, 0x1C48F30F, 0x4620BE58, 0x07EDAF6F, 0x3A816769, 0x9E156C24, 0x17DC4077} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5227 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5228 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5229 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5230 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5231 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1850C30F, 0xB8B8981D, 0xE0D99CBE, 0x3BA4C2DB, 0xB43C2F55, 0xB1B839F5, 0x14477BFE, 0x0B7CD652},
	{0x0CE80609, 0xF67AAC95, 0x68CE6D9A, 0x821160BE, 0x97552DD7, 0x0A11B539, 0x94BB212F, 0x00230599} } ,
	 { {0x6B18E514, 0xB83C97D5, 0xF4A714FE, 0x21701D58, 0x27444799, 0x26607755, 0xBADF2B3C, 0x037A9A4D},
	{0x1B823AE5, 0x34C69A55, 0x6D0E0A53, 0x1D9297CC, 0xE4D82C9D, 0x31A2DD25, 0x0EFBF760, 0x1CCD530B} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x3495E4E3, 0x980FC052, 0x1720FEFA, 0x8028029A, 0x6218E66B, 0xD17284FB, 0xB97900A3, 0x208FA12C},
	{0x55A4364F, 0x9B699676, 0xDB24F80D, 0x5A096555, 0x869A1E39, 0xFF3918D4, 0xC252554B, 0x1B3F292C} } ,
	 { {0x54F91DF6, 0x69139D99, 0x7BCB4B08, 0xBC5F9061, 0xEB940C8F, 0x31BDA551, 0xB56DB425, 0x03F71BDA},
	{0x9F4A5364, 0x7D46ADB4, 0x93462EE0, 0x75198C2F, 0x67BA1C04, 0x9F118DEE, 0xB086B5FD, 0x01CE3536} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x04E50261, 0xB794C2DE, 0x91A8B312, 0x340EEE53, 0x9099C1A1, 0x11FAB8DA, 0xEA6EF612, 0x20591254},
	{0xA1AB9B8A, 0xE318FD43, 0x9661CEC5, 0x925702DF, 0xDF29B993, 0x04A373DB, 0xE792A2E1, 0x0D280A92} } ,
	 { {0x99D24C4F, 0xB9837E95, 0x3C94628D, 0x8BCB01B0, 0x390B9CFF, 0xB89FDB3C, 0xA5B58FC9, 0x1301883C},
	{0xC0598069, 0x855277A2, 0xB4B99998, 0x2276C734, 0xD8F9FB9E, 0x7249E7E6, 0xE14B2DE3, 0x1F135D2E} } ,
	 { {0x1C4521D4, 0xDF572835, 0x3647623B, 0x44833FBE, 0xADDCB716, 0x1FBA4B05, 0xA53184A5, 0x1512CADA},
	{0x48BC3046, 0xA4EEE9E1, 0x72568A72, 0xD7F80497, 0xEF44F061, 0xF527639A, 0x2D97341C, 0x1B1C2393} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 515 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 516 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 517 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 518 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 519 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 520 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 521 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9DFEA218, 0x66522DC4, 0x1F5C85A7, 0xDA45D226, 0x090C0397, 0x3AA06D61, 0xEE7E6414, 0x17D8E1BD},
	{0x785AD7F1, 0xE4742E5D, 0x19646CC2, 0xB040D1BA, 0xE5164280, 0xE037ABD9, 0x991DA2E4, 0x2425FDEC} } ,
	 { {0xAE877676, 0x517E9F18, 0x65360470, 0xC57D6856, 0x7445A5E7, 0x56B15A6E, 0x57131704, 0x2448E781},
	{0x16946B43, 0x09E5D027, 0x856CD273, 0x16A246E9, 0xFF1EA617, 0xA545DE25, 0xDCEB1A6A, 0x0842210A} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC820A69E, 0x1A80E1AA, 0xDE55A70A, 0x6E5F2C93, 0x6990EE1B, 0x726C2FC5, 0x0AC24323, 0x1A603EF2},
	{0x7617460C, 0x6FA392A6, 0x73DB91CB, 0xBF1F6917, 0xDE4BBB9B, 0x767E4000, 0xB04DD2B1, 0x13F982F6} } ,
	 { {0x23372218, 0x48CDCDBF, 0x5CD46B38, 0xF12B0BBF, 0x1622101C, 0xE2D4C2C4, 0xE3C3D329, 0x1CFCFA28},
	{0xD2F96D9E, 0x694F056F, 0x8CA147F4, 0x4638A525, 0xCB5ACB83, 0xB799749D, 0x8009C2F3, 0x1ACA73CB} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x46EE5C29, 0xC145DFFE, 0xECAFFC69, 0xB006C5FD, 0x9629B999, 0x3DF4B626, 0xE039E41F, 0x1EEAE6B2},
	{0xEF6ABAE1, 0x429D4EB9, 0xB7A1331C, 0x298169A3, 0xBAC6229D, 0x82A029BE, 0x2A3DBBFF, 0x0C2D4F4E} } ,
	 { {0x1F38A810, 0x7B5AF0EF, 0x9205A553, 0xC46F7CEA, 0x4B1B151E, 0x10CCCE16, 0x3252B1BC, 0x1AAB9FB5},
	{0x72B727D9, 0xCDDBC695, 0x503D11CA, 0x861D3BFE, 0x28B08E04, 0xAD897A4E, 0xE334C246, 0x24E7A769} } ,
	 { {0x2A220486, 0xB42EB3E6, 0xBEF92162, 0x94195A6D, 0x6084EA83, 0x37CBC264, 0x1C43DF0F, 0x02875D34},
	{0xFDBC6E2E, 0x322F6448, 0x5A77251C, 0x6FFF975D, 0xF9357923, 0x507AE1A6, 0x57302FCE, 0x14F6E98C} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 522 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 523 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 524 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 525 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 526 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 527 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 528 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x999A10CE, 0x2DE44204, 0xA15479E5, 0x8C454863, 0x163C46EC, 0x442C175C, 0xCF435E6A, 0x192FC571},
	{0x3F685D7F, 0xCB46D238, 0x0AF63808, 0x05F65FC8, 0x6681BD2A, 0x4930C30F, 0x5DAC153F, 0x00C6DF4D} } ,
	 { {0x96002C36, 0x81752A7B, 0xF7649E2C, 0x88E76DDA, 0x3BD132DB, 0x4A090ADB, 0x8AF399F1, 0x09044A07},
	{0xE524F7B8, 0xFD6B4116, 0x7E646377, 0xAFB0F43C, 0x08B963FD, 0x3FB204C5, 0x6CF885D0, 0x1929829E} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xBA32ED5B, 0xC7F80EB0, 0x204F5264, 0x1244086B, 0xC44132C7, 0x87A50233, 0x503D715C, 0x192A512F},
	{0x995CC405, 0xB2162D05, 0x1EF92535, 0x807F1CF6, 0xA4C50DDE, 0xCA9D0F63, 0xE919C592, 0x0909616F} } ,
	 { {0x5432982C, 0xDE305758, 0x6B48E192, 0xA72B21A4, 0xD0F8A076, 0xDFBBE311, 0x5F5D706F, 0x0D1F49F2},
	{0x3A145BDD, 0x9758514F, 0x73C4EBAE, 0x84E1A21A, 0x26F74A9D, 0xD2C94DF6, 0x659E1106, 0x0E7B6AF6} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x17E0021B, 0xB95850F9, 0xDD479528, 0x1E49BEF4, 0x09E41911, 0xDB0B5F6C, 0x3AE745CA, 0x0ECA1C2B},
	{0xC403C77E, 0x20D055B3, 0x270208B6, 0xCB1121FD, 0xDD4A4E52, 0xD297CAA6, 0x92540952, 0x06309A77} } ,
	 { {0x566AA5A8, 0xCCB9BF18, 0xDCA49ADD, 0x68C69E8D, 0x64DF9EBB, 0xA67C7C10, 0xBCB53735, 0x1BF3AE7A},
	{0xA3B6602E, 0xA11D9E7E, 0x7D45969E, 0xAFD49C12, 0x3B6A1E1A, 0xBF815A9E, 0xB51A6A62, 0x0CC686AA} } ,
	 { {0x2098DCA0, 0x4113CCAC, 0x7EFAD893, 0xE71FC007, 0xAE04EBE2, 0xFDAD3857, 0xC0FA12F3, 0x251DF03F},
	{0x59F46686, 0xE6CF5ACD, 0x1402ED2C, 0x7A88BD2E, 0x3E4350B4, 0x816C4C54, 0x8B6DB053, 0x08428222} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 529 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 530 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 531 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 532 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 533 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 534 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 535 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x2104990C, 0xA3C2B1D9, 0x040FF1E8, 0xB9C5D080, 0x81FD0C07, 0x1C4B1EA6, 0x7A62C8A5, 0x104F0112},
	{0x8B383A24, 0x89939E9A, 0x3B91D248, 0x8209BD7E, 0xBB4D68E6, 0x9A053185, 0x172A0740, 0x1EA0B142} } ,
	 { {0x0076D5D9, 0x9B9254F6, 0x7C5744F1, 0xA83BCEBD, 0x0339455E, 0xF6E617F0, 0xFB21E7A2, 0x08336A82},
	{0x65866ACB, 0x8024EDFB, 0x03C7B06F, 0xFB199D65, 0x2D75D8BE, 0xA4663E4D, 0x5E3F4D08, 0x139F8D40} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x4BFFCF68, 0x7A566D69, 0x4854C428, 0xE3FAE384, 0x6DDC1EAC, 0xD4852724, 0x4496D10D, 0x1692FC2B},
	{0x249A41ED, 0xB7709F2A, 0xE2C046EB, 0x0BB6F24C, 0x391AB63A, 0x1C830036, 0xF82790B5, 0x2514C68D} } ,
	 { {0x17B87AFE, 0x3FBFA375, 0x9FD538ED, 0x06584312, 0x6E78767E, 0xF616DE76, 0x3723131C, 0x1CF173D3},
	{0x921FD943, 0xB1771383, 0xAB46068C, 0xF48B6661, 0x5F62DF6A, 0xAE288084, 0x51C21C94, 0x24B68CBF} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x66924CC2, 0x689297E3, 0x75575A0D, 0xD92A29B4, 0x901E64B8, 0xBE57F595, 0x52F689C5, 0x0620B8AD},
	{0xB401AA38, 0x12F02816, 0x4AC1ABDE, 0x95B1F46B, 0xA363CEE7, 0x80ADCC07, 0xDCB8A1DE, 0x0FD9943F} } ,
	 { {0xFC43BC8B, 0x4FF89F4B, 0xDE17DDDA, 0x5A356FAA, 0x02ABDD16, 0xBE7ED9DC, 0x58D515AC, 0x195960D7},
	{0x7AB29D05, 0xC8439958, 0x04E9EAD9, 0x00185C56, 0xD98A7D55, 0x6F97DE8F, 0x9E74C3AE, 0x1EBFB598} } ,
	 { {0x2AFB365C, 0xD693BB90, 0x4444D23F, 0x2A351304, 0xEBDF12A5, 0xB83A087D, 0xCA340868, 0x0643FB18},
	{0x996207C9, 0x2DDD008F, 0xA72E74A3, 0x89AD34CE, 0x7DCD4D53, 0x827DCEB0, 0xE0FD8974, 0x0674154B} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 536 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 537 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 538 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 539 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 540 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 541 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 542 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x00A74A71, 0xE827BDF3, 0x83DD163C, 0xCF836874, 0x627969C5, 0x7BB98970, 0x61FFB470, 0x1DD829BC},
	{0x9EEA9990, 0xEF6C2731, 0x58EC781D, 0xB44AF61F, 0xB47F7BC5, 0x0F2BEA0A, 0x967035C5, 0x0CDFBA36} } ,
	 { {0xFCBC2A52, 0x2EF04638, 0xFF201863, 0x4B8B10E3, 0x3ECC57C8, 0xE573F298, 0x403629FE, 0x03CF1EC8},
	{0x7B8B2EE8, 0xAF27E3BB, 0x6DFB107B, 0x17D9C08D, 0xFD5A8FEC, 0xB3578107, 0x03AB420D, 0x0D6151C3} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD1ECA38E, 0x2B40B680, 0x7E679D32, 0xB04DD519, 0x8DF3E3BF, 0x47B04D52, 0xE2E32514, 0x1DDE35A7},
	{0xDE9F45BC, 0xB06A5F65, 0x3D194C0D, 0x30CD35BF, 0xCD99EE42, 0xAD7AE544, 0x4AE15D18, 0x1B271337} } ,
	 { {0xDF086537, 0xCC1E8110, 0xB7F8C211, 0x0F84B45E, 0x47BC5296, 0xCC643212, 0x4E346133, 0x11AFDCD7},
	{0x61BB9115, 0xA85753DB, 0xA83F37D0, 0x1A77CA0D, 0xE97751C5, 0x6D7F9EBF, 0x786EBCAE, 0x21939CF4} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x423ED2E5, 0xCDD0CE79, 0xE2954388, 0xD173F500, 0xF956945B, 0xDC753F3C, 0x34C7E19A, 0x014DFD50},
	{0x95061D8F, 0xB40B6139, 0xA3010D21, 0x9C121DBE, 0x3E4C6553, 0x11E2AB30, 0x3183EA75, 0x1F819BB5} } ,
	 { {0x2D2A0EC8, 0x131BDAE0, 0x20613E98, 0xE424E490, 0x300BCFBF, 0x352E9F99, 0x88FE8BD7, 0x0F3679A9},
	{0x985CEE47, 0x696C1361, 0xD7D35EBC, 0xAF37B5CF, 0x4638AAB2, 0xB8A5719A, 0xFEDE534E, 0x229D078A} } ,
	 { {0xD145591D, 0x4318F88D, 0xFA8A86F5, 0xE0CA6CA4, 0x2B7A79F9, 0xCBF6C3E2, 0x80E370A3, 0x00060BEB},
	{0x3FB4AC2C, 0xC0FE3834, 0xE42CD3EF, 0x7C823F9F, 0x191A727C, 0x9E4EFB3A, 0xB4712753, 0x0E475900} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 543 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 544 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 545 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 546 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 547 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 548 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 549 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF8963FAE, 0x1CEB1400, 0xA0DC1A92, 0x5302A797, 0x8F2FE360, 0x46049241, 0xEAF95DA7, 0x116FBBD4},
	{0xC73FCC49, 0x3C016F24, 0x824A20B3, 0xF8952DC5, 0x66F47A7F, 0x6CBC2086, 0x266EA1C6, 0x0E95FB96} } ,
	 { {0x836CEB76, 0x66D4391C, 0x09902B58, 0x14D4790E, 0x41AC4809, 0x18EDD7D0, 0xEFD0D42C, 0x166DFCB0},
	{0x9C45AACE, 0xB6FC5165, 0xB3968E28, 0xFC926C4D, 0x0A6B5ED9, 0x3ABF1170, 0x9E90800E, 0x0F97D3AA} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE4819A5F, 0xB47CD4A5, 0x5F2AD3F8, 0x4219F83D, 0x0251DCD9, 0xFB64F629, 0xC4846625, 0x00C4D16B},
	{0xB6E4A219, 0x193CC35C, 0xB5CE30E7, 0xEC465C0D, 0x7314BC46, 0x425D62E6, 0x114A25D9, 0x0B45E3FF} } ,
	 { {0x1E9363C0, 0xF7DB19C1, 0x3E530193, 0xB61C2C7F, 0x229A6E4B, 0x74442E9A, 0x47A9ACF5, 0x16527E36},
	{0x55ED47E3, 0x0BC538C6, 0xEE043677, 0x134101A8, 0xB0CC5C92, 0xFE0A69B4, 0xA8F6C8D0, 0x031A1DCC} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0xA9F8ACC2, 0x7EF08BC9, 0xD4B70262, 0xA470F85A, 0x71DF1560, 0xFF1E3013, 0x49114B37, 0x068BF30A},
	{0x71FF55E9, 0xCC4798EB, 0x2450A813, 0x4D23B67A, 0x0FEB7014, 0xB6E0688D, 0xECDC23CC, 0x1548E049} } ,
	 { {0xFF520E23, 0x3A0F5E55, 0x94ED86E3, 0x0ECCBAC7, 0xC106F4CC, 0x54C57779, 0x05FA0072, 0x2452AFDB},
	{0x023096A8, 0x82D6BF07, 0xE366B812, 0x9DC3A5A7, 0x9696CBCE, 0xEF5EAE57, 0xC451A5D0, 0x19C1EBAA} } ,
	 { {0xEBEB5AC4, 0x3E91C0A4, 0xBE4EB97A, 0x503850A5, 0x7321F981, 0x6F94B167, 0x198B0880, 0x14787A19},
	{0xEFA4D5E3, 0x843B5437, 0x33841047, 0x54D22E48, 0x0C2041CF, 0x8FD58FE0, 0x2ADB8414, 0x21D34CEB} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 550 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 551 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 552 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 553 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 554 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 555 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 556 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x51DC540E, 0x49188ECF, 0x44934298, 0x2757E2EB, 0x3F85B428, 0x16832702, 0x1CCA373D, 0x03F6D7A5},
	{0xBA1D76D7, 0x0E10A216, 0xF25171B9, 0x8069FB06, 0x6D693C8C, 0xCBADD351, 0x90FE5CCA, 0x060A4944} } ,
	 { {0x3A41A32B, 0x20DBCC4E, 0xDA2228C4, 0xD0FCE36A, 0x8D279E1D, 0x1DE011B0, 0x185EF87F, 0x15D5997F},
	{0x6F4A62BB, 0xAE5CC40E, 0xD9247A50, 0xA10FA3F7, 0x7720F2E3, 0x3FE8CFF6, 0x47EF198F, 0x0D214036} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xEE4052E3, 0xC6C32B4F, 0x9A96EADC, 0xB1A390BF, 0x1D1AA5B6, 0xE5D8398E, 0x0237CAC3, 0x112E4410},
	{0xC62BEA25, 0xF7DB7B50, 0x65779814, 0xF875711D, 0x6F2607A5, 0xA2921912, 0xA4BF5535, 0x0EB289CF} } ,
	 { {0x3221BCD7, 0x46663044, 0x85E87520, 0x81E9B787, 0x87399BA6, 0x479C0E32, 0x74EB0F03, 0x0273CD90},
	{0xFD99C4AA, 0x80E98752, 0xED716913, 0x64CB3493, 0xA364DFA4, 0x375F8767, 0x4795CC5A, 0x12A79FBC} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0xDA7342E2, 0x4307659F, 0xDF4EC61E, 0x544C9B51, 0xDB8DE8B9, 0x54C725BF, 0x6CE7BB48, 0x008FC32B},
	{0x35F0FE55, 0x1344273B, 0xE6CD1F5C, 0xF7087C92, 0x462A9B2B, 0xC26F00DA, 0xC09CC4E5, 0x058BB1F9} } ,
	 { {0x85EC4A48, 0x62E1350D, 0xA16E23D6, 0x822C3E66, 0xDD957585, 0x864380C0, 0xD1270B8F, 0x05FFBEF8},
	{0xE2CEB7A6, 0x5E52D89C, 0x58B91FA1, 0xD5779C2E, 0xAF6305FC, 0x81827616, 0x2C78CA05, 0x1E4E8174} } ,
	 { {0x9C63FED5, 0x7DAA9C80, 0x5603A844, 0x8A4BADD4, 0xDD94F18E, 0xCF55128B, 0xE56D9386, 0x0D376C6A},
	{0x0C0E734E, 0xE9CAD93A, 0x7326265B, 0x780B7616, 0x01BCCB19, 0xD6E445C1, 0x13C0F86A, 0x08A8408B} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 557 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 558 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 559 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 560 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 561 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 562 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 563 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF30EE052, 0x14749DC3, 0xE56F1500, 0x22896EBC, 0x4D9A42CC, 0x3FC5F549, 0xE031BEAF, 0x1D5DC498},
	{0x2CD2D1DA, 0x630C7290, 0xAFF8CC83, 0x8B3084AF, 0xBBAADB8A, 0xFA3EA6D8, 0xB16D7F25, 0x10958B32} } ,
	 { {0x9A32ED67, 0x85C7D3AB, 0x81343F9A, 0xA986AF53, 0xF83CDA61, 0x2AA2C770, 0xCC8BF718, 0x191623A8},
	{0x1930FA4B, 0xD78132BD, 0xFF9BF5CD, 0x5755F0ED, 0x9D844673, 0x1E7CF87C, 0x30925BC2, 0x07D3DBA3} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xA9EC209C, 0x8A8314EE, 0xB624F3B8, 0x66084370, 0x5D498D63, 0xA1E3BEDF, 0x6C4897DF, 0x06F8B6A5},
	{0xCA59F647, 0x10BA085F, 0xE9A1DEE3, 0x8108D28E, 0xFB087AEC, 0x202BE30B, 0xC2E2189E, 0x13F905FA} } ,
	 { {0x6ABB8658, 0x10483526, 0xF625CAFC, 0xD1EEDFF2, 0x07C2F04C, 0x148DFDC2, 0x7AB71617, 0x0D1F7F16},
	{0xC32EFA64, 0x01BAC73C, 0x4B560031, 0xDE46F5CE, 0x4B86BBEE, 0xF6A96EAC, 0x5F56D0C0, 0x0BDC0280} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x88302F96, 0x7D9B47EF, 0x7514F8C4, 0x18FEEAE6, 0xE7D1478E, 0xC1FDEC24, 0x5FDBF625, 0x2040184C},
	{0x9DB12C3A, 0xA4272A7E, 0xF89C0546, 0x9265E92B, 0x08103BDA, 0xFD829519, 0x15EF2D0A, 0x11223C8A} } ,
	 { {0xE277DA0D, 0x745138B9, 0xDA353B62, 0x3252D85E, 0x6C2F5FDE, 0xFB1C8F02, 0x590BAD81, 0x1354F522},
	{0xA5876A41, 0xD0DD1DD8, 0x033E297F, 0x6BC8CFD0, 0x4BD437C9, 0x0BE21ADC, 0xB456564F, 0x24B3D1DF} } ,
	 { {0xB6DD405D, 0x1D0E772A, 0xD0B5DECC, 0xA49FD4B3, 0x0FAF4A9F, 0x1C521716, 0xCC16D932, 0x0EBE568E},
	{0x9D87246D, 0xADAD95CF, 0x39A9125F, 0xF5D84DDF, 0x3F5D9F61, 0x25ED3C33, 0x11749978, 0x03637AC8} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 564 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 565 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 566 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 567 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 568 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 569 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 570 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5D2A36DD, 0x9DAF9515, 0xB4502A04, 0xB2D00701, 0x7947006F, 0x1C0F29AC, 0x6E10A283, 0x1CE35A2D},
	{0x507E8B74, 0x0C062F25, 0xD20663B4, 0xCEFD59EC, 0xBBC23ED9, 0x4CFE4E96, 0x4402D6BB, 0x04EB7D14} } ,
	 { {0xFC1D6B1F, 0x3614636C, 0x7F882520, 0x997C98D0, 0x99C8E9CF, 0x3ECCB471, 0x882CE9F4, 0x1E587AFE},
	{0x2714530A, 0x040491BE, 0x64A004F7, 0x96EC7324, 0xC03E7506, 0x3FDB6806, 0xCD97FFA7, 0x0CC8FF11} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x4A9EAC97, 0xC6D4F854, 0xE258C8CB, 0x41D2C7F4, 0x8AC17752, 0xED1FE050, 0x7C67ECED, 0x183DFEDD},
	{0xCC0D2F57, 0xB6FD06C8, 0x1C61D71A, 0x7BD940A0, 0xBA770504, 0x89BF35DD, 0x542B9302, 0x2318313F} } ,
	 { {0xF2E09A9C, 0x4254CBE5, 0x74134585, 0xDB019F88, 0xA3709F9E, 0xB47B214D, 0xC56F7298, 0x1442E729},
	{0xBC3E1058, 0x6FE83B18, 0x4D66CA7A, 0x43BEB6A2, 0x74FEC555, 0x1B0E4795, 0xFA037B9A, 0x215B62A7} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x92330CD9, 0xBAD6CCDC, 0x4C400008, 0xF25A1850, 0xC33F8FFD, 0x333FFF8C, 0x1A36660B, 0x088DAB83},
	{0xF9F26E52, 0x789BF141, 0x1420D140, 0xEE988059, 0xD548036E, 0xEE66D95C, 0x4399A14F, 0x11C77291} } ,
	 { {0xD3CE08A2, 0xCAF82ECE, 0x4A0DF6F6, 0x37C67732, 0xF068A9C8, 0xFEAA6983, 0xAA9F50AC, 0x03B6A2A2},
	{0x6250686F, 0xED2893A4, 0x15BE4F67, 0x238E743A, 0x14D7CCF3, 0xBDB0FE96, 0x445B1A36, 0x027BE4C1} } ,
	 { {0xED7475CD, 0xD025633E, 0x2E089EDA, 0xF023C0F3, 0x117A76EA, 0x8B450424, 0x4E574A6C, 0x207E0932},
	{0x7B8EA3E3, 0xAAF6D7A3, 0x4A5B7366, 0xACDBE6B3, 0xFEB4C62A, 0x3CC0E746, 0x1028BC47, 0x1E2CB42B} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 571 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 572 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 573 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 574 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 575 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 576 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 577 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3FFC68D8, 0xC13DB7D3, 0xF95F5AD5, 0x3D073D88, 0x5B3ACE89, 0x96249D48, 0xC6AC09E6, 0x03AAD57F},
	{0x6D1961E4, 0x613DB34F, 0x004ACC1F, 0x49F372E2, 0x162E959D, 0xA57A44ED, 0xF1C1B91E, 0x1F720A57} } ,
	 { {0x84218D32, 0x81DCE6AC, 0xEF241729, 0x27BDEDBF, 0x1880F7FB, 0x86DBC42F, 0x7634518D, 0x05B6E109},
	{0xCB502BEA, 0xA6CA3374, 0x49F9BB96, 0x13A7A30B, 0xBDBD8FD8, 0xA944D306, 0x1AD3FBA3, 0x085923AA} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD1588E54, 0xC0AAC32B, 0x439FD246, 0xC33A65E6, 0x8DAE8B63, 0xAD1420D2, 0xF983705E, 0x16292C77},
	{0x0D173F70, 0x08617EF5, 0xEE89DC2D, 0xB8C66314, 0xD4F9F7F1, 0x952DC18D, 0x49295CBB, 0x1C8E2F68} } ,
	 { {0x474F514C, 0xD4CE6389, 0xE02FDF6A, 0x80CDC259, 0x1C389843, 0xC3FBD81F, 0xE0C6030E, 0x19F2529E},
	{0x241DB12F, 0x68785894, 0xA8663D21, 0x2AE6F696, 0xFB9F717D, 0x9A9A4AF0, 0x0311057E, 0x08BA9E34} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x502C5195, 0xB377F664, 0xC0F68748, 0x7F154BBF, 0x2172D897, 0xE8D252EE, 0xB333DAA1, 0x02696F65},
	{0xA704AB04, 0xFFD54037, 0xE39C2AEE, 0x97CCCECB, 0x9B22841A, 0x4DBF9677, 0xE2F3DAAA, 0x1A4EABDC} } ,
	 { {0x630ECBDC, 0x63A5F127, 0x848FB154, 0x25DBBD86, 0x1CB3270F, 0x5B6D1A15, 0xE5A8123B, 0x250349CB},
	{0xA3B7D8B9, 0xABF98EDC, 0x4427B58C, 0x1072D841, 0x44564C3F, 0x52119B0E, 0x9735F331, 0x0A050457} } ,
	 { {0x915C257C, 0xFF6D0B58, 0x4A407770, 0x8633285D, 0x3273BCDA, 0x16EF838A, 0x32D76678, 0x127E56F8},
	{0x9FFDDD9F, 0x4E23CBA5, 0xEE3F1021, 0xCFF3F032, 0xBECB625C, 0xA9E7CA20, 0x9767A39E, 0x223F8992} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 578 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 579 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 580 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 581 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 582 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 583 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 584 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8DD460CB, 0xA703A05E, 0xF55F5758, 0x4A0C0771, 0xC8E3475C, 0x6DD81875, 0x9611031A, 0x12EBC238},
	{0x19CAF198, 0xF0DC9D53, 0xB9FE7D5B, 0x50675204, 0xAF7B9B99, 0xAA61B5F2, 0x224552F1, 0x016EE121} } ,
	 { {0xA16F2FD4, 0xC1F82EFA, 0xB909F4EF, 0xF58E5DD7, 0xD07C8F3A, 0xEA4B49B1, 0x352E331B, 0x1F39A15C},
	{0x74EBF7B0, 0x16CED289, 0x72BF8651, 0x8F440257, 0xC5033D74, 0xB497A649, 0xF70EA66F, 0x12BA7DC7} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x7D6C41DA, 0xBC5F0F44, 0x13AE8A40, 0x9EF7AD87, 0x45FC14F5, 0x71403E6D, 0x6E8AE774, 0x170D9598},
	{0x6FAEA6CF, 0x358DA508, 0xA87E391C, 0xFCCAB9AA, 0xDB913C98, 0x17488B41, 0x1CBF7ADD, 0x156E3EEA} } ,
	 { {0x30C06BEF, 0x99959664, 0xBBA3F710, 0x1197167E, 0x5C5C8F45, 0x350F3505, 0x77D2E0FA, 0x0B90090F},
	{0x607D496E, 0x3A3267A7, 0x9519C92F, 0x1440F9F9, 0xFBCB0324, 0x53564D3D, 0xA7412155, 0x06CA5EA7} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x70BF5826, 0x07D53960, 0x060D2441, 0x8FEBF3B0, 0x3B891A95, 0x48BD5D1B, 0xE9DA543B, 0x0FF7B14F},
	{0x04F1755A, 0x6345C024, 0xD5B62D0B, 0xCC58E801, 0xD4FDC113, 0xDCEF1CB8, 0xFD2EEE72, 0x14D08481} } ,
	 { {0x6B87CB3E, 0x40A9869E, 0xBD9DA573, 0xC35D3D08, 0x76B1515A, 0x6BBE9F3A, 0xF60B0490, 0x09E9CDA8},
	{0xACBE797E, 0x89A8D1D4, 0x1B689FEC, 0x42B019ED, 0xBB1CB32B, 0xFED70E35, 0x38CDCFB9, 0x1EDB144F} } ,
	 { {0xEF97E10F, 0x155B6EE5, 0x1E4F32E8, 0x54EBA615, 0x7D18CD99, 0x036825F7, 0xD879E45A, 0x0421D35F},
	{0x55E3B537, 0x44B107B5, 0xEE7FBBC0, 0xAC6367A5, 0x2C15A0FF, 0x6CE6D54F, 0xFA7A27EB, 0x13FF5DC8} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 585 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 586 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 587 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 588 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 589 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 590 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 591 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8E36BD54, 0xDE6A4A93, 0xCB756FA4, 0xAB195807, 0x397AA83A, 0x83386B43, 0x5BA7214F, 0x18A64643},
	{0x489F4589, 0x52D35F7B, 0x870A1871, 0x1AC42D33, 0x3E7D8F56, 0x3E9FF969, 0x5523775F, 0x0D6F7673} } ,
	 { {0x2C72850A, 0xDEA35E1A, 0xDE23F908, 0xB1D49FDF, 0xD7972BA8, 0x6B47A948, 0xAE004B28, 0x20AC9B72},
	{0x2C3BF78B, 0x3AABAC2D, 0x741DCFF6, 0xA928584B, 0x7336BBAF, 0x121F5A81, 0x32001B5C, 0x20DED527} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x8396C5C2, 0x9343FE49, 0xA3C39904, 0x385A33FC, 0x67666591, 0x223EC632, 0x3CDA6BDF, 0x083FBB9A},
	{0x296DBEBC, 0xAC49E866, 0x378395E8, 0x085658B3, 0xEAF01B40, 0xC791B04E, 0x186FD330, 0x1B8259B6} } ,
	 { {0xF90B7134, 0x10EC8F4C, 0x28458DCA, 0x7729BCA5, 0xD50EB7C0, 0x9508AA21, 0xA74050FF, 0x0E00F779},
	{0x794B1D42, 0xC8F73F9A, 0x4889EC60, 0x00E0A73D, 0xA6F50960, 0x32950C48, 0x7B99BB9E, 0x238E17EE} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0xEB6F52B9, 0xAB287458, 0xC0950D60, 0x332B9317, 0xA586EC38, 0xC59878DF, 0x72499DFE, 0x1307D64E},
	{0x6B480B1E, 0x7FBF064B, 0x0D30A3B4, 0x631FBC51, 0xE02D61DC, 0x6775FE79, 0xFB8CF3DC, 0x1DD2EB47} } ,
	 { {0xA81D7C79, 0xD7A39DB9, 0x46FFC3CD, 0x92AD25B1, 0xEF0655E2, 0xD76BE850, 0x496D99B0, 0x218A1900},
	{0xDCD24CA4, 0xD77F9BE1, 0x672D660A, 0xA1D23774, 0xD7782E6B, 0x196EE42A, 0x2F7BC156, 0x1349FCAE} } ,
	 { {0xF5600881, 0x5BD9B3B5, 0xD84E2973, 0xEE61DBF4, 0x2DEBBD5E, 0x593AA86F, 0x21334A91, 0x14BCD9D9},
	{0xE0CE7933, 0x597688EA, 0xB0797D77, 0xED922B7F, 0xAC728BE9, 0x88F1B6E5, 0xC34C5BD1, 0x0E12E342} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 592 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 593 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 594 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 595 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 596 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 597 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 598 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x21DF3DB5, 0xF89FCE95, 0x58791196, 0xAC1BA2D6, 0x8A938776, 0x8D2929D2, 0x2AB81E53, 0x10898EE8},
	{0x74FD2757, 0x4C0323CD, 0x8191F0F4, 0xD019A380, 0xE62AC7F3, 0x1F9C3B1C, 0xF7889F1B, 0x0FD89514} } ,
	 { {0xBCB991CD, 0xBE5B5477, 0x744281E0, 0x3AB4DC3C, 0x8C8DFD18, 0x2BFF943E, 0x5EA576E0, 0x06460058},
	{0x8903D5BE, 0x2989DB7B, 0x2BED5762, 0x25A22E1C, 0xB4452089, 0xA7D66ED4, 0xBEB1CDCD, 0x1054BC32} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xB0D38169, 0xE76CE3D5, 0x9F45E419, 0xFAB0F703, 0xE6AE42BA, 0xFB1480DE, 0x2F34EE52, 0x149C3C78},
	{0xC12AD267, 0xE2A983FA, 0x0EF9F9B5, 0x62BCC8F9, 0x27188CFE, 0xBE3B213D, 0xCDA2C612, 0x1DA2D8A5} } ,
	 { {0x81069038, 0x82D8A774, 0x816AEB52, 0x40D6E70A, 0x1563F929, 0x8CF96DD3, 0x04809D8B, 0x131B746D},
	{0x56F826CE, 0x95AC432D, 0x82B7C24E, 0x1A3161DB, 0x7EC25785, 0x771CB68B, 0x7D48574D, 0x16EE399E} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x8FDD7E2C, 0xF7B3B993, 0x404A5A24, 0xF4AE3B0B, 0xB5D2C8B0, 0x9F27D1F4, 0x6BEF8F61, 0x16BB90AE},
	{0x93A7AB71, 0x57B6A511, 0x624543BA, 0x02AEFEF0, 0x395027E0, 0x40212376, 0xE00818F8, 0x1B163BA5} } ,
	 { {0x6D9C569D, 0x723F6611, 0x155BB09C, 0x7BF6C0A7, 0xCED441E0, 0x909BD52F, 0xC9C79887, 0x08430219},
	{0xC420E386, 0x6F14AA1B, 0xE0CD7EE1, 0x4F1C417B, 0x86007479, 0xEF23B7B7, 0x2A6F9E8D, 0x2466BF24} } ,
	 { {0x8EF443B4, 0xEECD1540, 0x46CCD282, 0x4E95542D, 0x5C1ABB44, 0x6DEB570C, 0x047CCFFF, 0x0412AD90},
	{0x4C2DAB10, 0x96A6602D, 0x8D6808C1, 0x92A32578, 0x40EDC50A, 0x9E9EE620, 0xD61A26F7, 0x0DCA4390} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 599 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 600 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 601 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 602 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 603 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 604 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 605 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x7154E1E1, 0xCCCFAF8C, 0xEC24D58B, 0xF625B079, 0xE8E0327F, 0x9752FA3C, 0x414D1EA0, 0x042EEA0F},
	{0xCDF87097, 0xB7AF1B7C, 0xFCE506BA, 0xD7F1A4F7, 0x444CD9A7, 0x0609D5D1, 0xCAD6135C, 0x134BE54D} } ,
	 { {0x9E6BBCBF, 0x24AD04BA, 0xA95826B5, 0x57E6DE14, 0x2BA97FDC, 0x9F864F7D, 0x95BE8DC9, 0x1221F8BF},
	{0x33EE4A89, 0x27ABD0D6, 0x6B6954A1, 0x363ECB59, 0x8268DEA8, 0x85AC225C, 0x2F6B8EDF, 0x24E5AD52} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x2D31D0FC, 0x3012770B, 0x128AE26E, 0x58DFF5A1, 0xE38397B1, 0xBB27CFA3, 0x06C59DB2, 0x1795F0B6},
	{0xF5078062, 0x83AC2233, 0x6C918111, 0x79026FD9, 0xB9319440, 0x739308F4, 0x895B5686, 0x1C79DB85} } ,
	 { {0x6CE25A74, 0xCC8F3928, 0x623AE921, 0xE32DF15C, 0x02F05818, 0xF0529FD0, 0xC1AA4196, 0x1FE1C38A},
	{0xF4D2C1AA, 0x2A79F839, 0xF78F2224, 0x688CD2CA, 0x76F285A1, 0x7C03C266, 0x30E8A2C4, 0x10DFB554} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0x375A3956, 0x1B757F53, 0x1D487B04, 0xF8DF9595, 0x798880F0, 0x23C74456, 0xEB496B9D, 0x17343F61},
	{0x565823CD, 0x38804435, 0xF414DD18, 0xDA0F81C4, 0xC824AF1B, 0x0BE1AA36, 0xCB3DD3A3, 0x0FCB4C14} } ,
	 { {0xE07C32B2, 0xEF92259D, 0xDEEAD041, 0x2DFCF4D6, 0x22030AEB, 0xF9D68BE2, 0xF44F6E0F, 0x00F90F7F},
	{0x91C42002, 0x7248FEA1, 0xCB141E35, 0x85A28DB0, 0x3DE32250, 0xE895FC19, 0x386BBA63, 0x0EF5D92A} } ,
	 { {0xBBDCEF1B, 0x6342C77E, 0x26660CE2, 0x62BA4527, 0xFAA36531, 0x23D4D566, 0xC5787F12, 0x136706A6},
	{0x270F0FCB, 0xCBFD06B7, 0x6FAC7A56, 0xA110CAE1, 0x74E4BA98, 0x6D893323, 0xBE85432A, 0x092DF637} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 606 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 607 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 608 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 609 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 610 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 611 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 612 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x0AA6370D, 0xE7428F00, 0x34F627F4, 0x4A15B628, 0x331A326E, 0xFD3EFCE8, 0x2B0FC307, 0x157EDEA8},
	{0x65573804, 0x25A75BE9, 0xE90EC751, 0xFFAE7E76, 0xD22140CF, 0xFC5F9DE7, 0x0D17DDBA, 0x127B5925} } ,
	 { {0x83C57CE1, 0xDF5DF756, 0x3D23E984, 0xC8AE6D1D, 0xFDF8A527, 0x1E642434, 0xB968B3A3, 0x0AAAEA69},
	{0xB9D5B690, 0xD88716AF, 0x0FAB7C3B, 0x4252D1DD, 0x4ABF9352, 0xC7A580B0, 0x0AB9AC61, 0x1316F7B1} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x7913C155, 0xD4681364, 0x10DD9091, 0x983155D3, 0xE1A43AF6, 0x6F8D82B6, 0x90AE1921, 0x12580667},
	{0xC98A297A, 0x9BA1F83F, 0x96BED85F, 0xF0C39B82, 0x886D7E0C, 0x0E3DE828, 0x91B2BE75, 0x197D4F6A} } ,
	 { {0xFA9FDA1D, 0x683697EA, 0x15CD2A86, 0x4B394789, 0x2E7D1A0A, 0x72BE8EBF, 0xDB4F6A1F, 0x17E2EE5C},
	{0xA7F463A6, 0x81894B2A, 0xE532B124, 0x89BE8D99, 0xB9D5FA17, 0xCFBC776A, 0xB16555F5, 0x0B85E707} } ,
	0};
		static const ecpoint_fp2_proj var_expected = { { {0xDB287CCB, 0xBDE228AB, 0xCD5869F7, 0x5FA8CE13, 0xAD0A3F8C, 0x1D0D803B, 0xB2914FEC, 0x0F3CB38E},
	{0x1DBD1C8E, 0x824258C8, 0x33502FF1, 0x712177E6, 0xE765A860, 0x63E1B889, 0x4D077034, 0x2078175D} } ,
	 { {0x7A7EFC48, 0xDC07CB2F, 0xA29FDF7D, 0xCBE60265, 0x36EAA0EC, 0xE7181CFD, 0x3C8501EB, 0x207F76EE},
	{0x0D4A4792, 0x8C4D1FB1, 0xD2BC79D6, 0x05D26869, 0x0BF65307, 0x1B1A40FE, 0xADC10BDA, 0x0658347D} } ,
	 { {0x6E6D8A5B, 0x94258464, 0xDBE768B0, 0xAF3C9FAA, 0xAE8A0890, 0x2C82D34E, 0xA59E561B, 0x21FC8C41},
	{0x6432F176, 0x75FA9C56, 0xADB0110E, 0xF1151D0B, 0xB64C3D3C, 0x11DE4A40, 0x849AE0BA, 0x0701F645} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 613 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 614 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 615 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 616 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 617 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 618 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 619 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x549907D8, 0x6BDB13AA, 0xCDA22F90, 0x0576FD2E, 0x5FA750EC, 0x275742EE, 0x2BF80E9B, 0x0685D795},
	{0x46E327CC, 0xBD5CB89C, 0xC13920E4, 0xD71ED5F4, 0x3CB4643E, 0xA71A6EAD, 0x4F620AD0, 0x11C152C1} } ,
	 { {0x9CFE24F4, 0x7379CF5F, 0x1D25B3A0, 0xD6A9E55D, 0x09617697, 0x7709F984, 0x20986C14, 0x0E36D715},
	{0x972F687E, 0xDC05AA69, 0x19194AE6, 0x4F40B4FE, 0xAA761D57, 0x8250A9AE, 0x8F8AC1BA, 0x1447EF57} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x7ADA90A3, 0x44EB35F5, 0x59825FB8, 0xCCBD1FB6, 0xD117D1F0, 0x16790990, 0xE83CCBCC, 0x0D04F2C3},
	{0xDD7F34E4, 0x43836986, 0x5D3869AD, 0x47F9AF24, 0x30432479, 0xFCE96798, 0x259DBF23, 0x0F56DB66} } ,
	 { {0xBB9A2009, 0x2B231883, 0xBD2EDFF2, 0xC45FE8DD, 0x8B846AAD, 0x083E0128, 0x7AF72DC0, 0x15D2ACEA},
	{0x6FDED996, 0xC72F32D2, 0x06D56438, 0x975F102C, 0x31903F8D, 0xF368B19B, 0xDD754FC6, 0x0429B0B8} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8F5D5819, 0x9FE35B43, 0xDEBE71EA, 0x1612118B, 0x58CABF01, 0xE9F17817, 0x6C51DF23, 0x16090F46},
	{0xAFF7BEB9, 0xB0DD1394, 0x806147C9, 0x400AA634, 0x5F753542, 0xA88F5A33, 0x0C4F70CA, 0x171AFFB9} } ,
	 { {0x3A88465F, 0x32EE2730, 0xEE35F476, 0xDEDA16B3, 0x3B903756, 0xF1355F9A, 0x7D2A24E3, 0x16D61146},
	{0x188A131D, 0xFD886EA0, 0x76500A34, 0xC3B92DE4, 0x3798E81E, 0x10090E48, 0x8F1FC8B9, 0x00B1F0F4} } ,
	 { {0x264188CB, 0xD910224B, 0x8BE03027, 0xC7462287, 0x71708104, 0xEF21C6A2, 0xBC44BD30, 0x067F1B2E},
	{0x969C0D2B, 0x2D26B0EA, 0x9BFF48DC, 0xD1FBD92F, 0xF38EC042, 0x1003466A, 0x163BB455, 0x22B8ED27} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 620 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 621 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 622 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 623 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 624 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 625 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 626 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD344FF26, 0x5410CB1E, 0xC48311B3, 0x3464B6B8, 0xC2480547, 0x4FAA0996, 0x7101EA7B, 0x2520DEBE},
	{0x1297EA71, 0x16741E24, 0xDD33BEB6, 0xFE7CA247, 0x108E07CA, 0x8854D374, 0xB5CEE67F, 0x216E8480} } ,
	 { {0x77508B4F, 0xF47862A9, 0x6D0DCDB9, 0xC52E3D1F, 0xD39B91AA, 0xED4A5598, 0xC76A2A54, 0x026539E4},
	{0x8A931CC0, 0x1C16779B, 0xF8259A12, 0x154257D1, 0xC2A6660F, 0x022FD9BC, 0x24087FE0, 0x1C46255D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD344FF26, 0x5410CB1E, 0xC48311B3, 0x3464B6B8, 0xC2480547, 0x4FAA0996, 0x7101EA7B, 0x2520DEBE},
	{0x1297EA71, 0x16741E24, 0xDD33BEB6, 0xFE7CA247, 0x108E07CA, 0x8854D374, 0xB5CEE67F, 0x216E8480} } ,
	 { {0x77508B4F, 0xF47862A9, 0x6D0DCDB9, 0xC52E3D1F, 0xD39B91AA, 0xED4A5598, 0xC76A2A54, 0x026539E4},
	{0x8A931CC0, 0x1C16779B, 0xF8259A12, 0x154257D1, 0xC2A6660F, 0x022FD9BC, 0x24087FE0, 0x1C46255D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xEC433B42, 0xD8848F4F, 0x15FE7DD8, 0x172987FE, 0xAF37AB32, 0x01CFD78F, 0x594A8909, 0x11560072},
	{0x30BEA5A9, 0x9E4FA744, 0xCAB6B535, 0x3CA0EB9E, 0x023E6BFF, 0xF8BF76C0, 0xC349DBAA, 0x0ABFFD4A} } ,
	 { {0xB656BA1C, 0x5BF6BAE7, 0x95C59D61, 0x20630C0C, 0xE9752158, 0x2CCA8BA3, 0x247BBFD2, 0x0484F6A0},
	{0x7E6581AD, 0xC80A37D9, 0x0778D688, 0x183CC297, 0x4B1AE617, 0x172759CA, 0x00524493, 0x0258B2D1} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5344 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5345 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5346 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5347 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5348 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE86C5CB3, 0x020211FA, 0x4DD5CECA, 0x74F2D4EC, 0x6C9AAE7C, 0x02CE0A32, 0x51A23D4E, 0x0F398D5A},
	{0x6E6CCA90, 0xB771BC64, 0xE6147800, 0x75F2FEE8, 0xA4283E45, 0xC34F4998, 0xDDEF37A2, 0x1FDDDF1B} } ,
	 { {0x31850C75, 0xD45D1469, 0x1A70B088, 0x258B72F1, 0xF0ADEAF6, 0x839BB8B0, 0x4DCCAE2E, 0x0DEA5AA8},
	{0xAEB2D21C, 0xCBD95DEC, 0xAA6533CC, 0xF9AD76B9, 0x65AA7184, 0xE4FFBB4E, 0xFB8E12B6, 0x046BC04D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE86C5CB3, 0x020211FA, 0x4DD5CECA, 0x74F2D4EC, 0x6C9AAE7C, 0x02CE0A32, 0x51A23D4E, 0x0F398D5A},
	{0x6E6CCA90, 0xB771BC64, 0xE6147800, 0x75F2FEE8, 0xA4283E45, 0xC34F4998, 0xDDEF37A2, 0x1FDDDF1B} } ,
	 { {0x31850C75, 0xD45D1469, 0x1A70B088, 0x258B72F1, 0xF0ADEAF6, 0x839BB8B0, 0x4DCCAE2E, 0x0DEA5AA8},
	{0xAEB2D21C, 0xCBD95DEC, 0xAA6533CC, 0xF9AD76B9, 0x65AA7184, 0xE4FFBB4E, 0xFB8E12B6, 0x046BC04D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x69E09427, 0xABA93A41, 0x902317C2, 0x7071EE4A, 0x264E5048, 0x7A6BFCF9, 0x0A5A5C6D, 0x19BD34A2},
	{0xC1C9CEE3, 0x0A82C4B2, 0x1CDE96A4, 0xC629D819, 0x5238AC2F, 0x891F3AD5, 0x80B4954A, 0x02F718BB} } ,
	 { {0x965CBB76, 0xBA1FE02D, 0x924EA459, 0x4D1AE07E, 0x528E60EA, 0x95E881A0, 0xE29AE458, 0x0923210C},
	{0x83C28C5F, 0x8D6BC208, 0x0C80B66D, 0xB9148BA3, 0x112ECDBA, 0xCA920821, 0x69A33EAE, 0x1BABBB63} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5349 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5350 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5351 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5352 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5353 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD5E3F45A, 0x876B8AED, 0x1AF8D284, 0x7C8FF17D, 0xB62BDBBD, 0x9B3ABE5E, 0x0D5C0F78, 0x047619A3},
	{0x18C22533, 0xBCBE2B94, 0xA1194C77, 0xF00FC514, 0x67D5C8EA, 0x00566019, 0x1AF23B3A, 0x23A44772} } ,
	 { {0x390F6A18, 0x7C1F58CE, 0xBC0C90AE, 0x622DDC46, 0x0F91906F, 0x8F032292, 0x910F4020, 0x07D154EF},
	{0xF230249A, 0x3E0C0432, 0x49FDCD67, 0xE4183C68, 0xA12A6EF4, 0x2D37136E, 0xEC7236E9, 0x13A1DCB7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x42A50204, 0x72C1D412, 0x1B89FF76, 0xCDDF6642, 0xFA4806AB, 0x25EAA145, 0x07A446D8, 0x15528156},
	{0x0D645768, 0x5CB50C98, 0x79AAED1A, 0xFD9E22B1, 0x2C4DFF38, 0x90FD8D01, 0x5C42EE3F, 0x1E78C019} } ,
	 { {0xD735E41B, 0xBD75CF14, 0xEE879EBB, 0x148005C6, 0xBECBE11E, 0xF2FB95A4, 0x775C2965, 0x01B8E733},
	{0xB6371C18, 0x9FFF00B4, 0xEECF6A99, 0x38128347, 0xF99C4D6E, 0x5CF057D1, 0x4CE58B13, 0x22362D38} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5354 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5355 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5356 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5357 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5358 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8CED2123, 0xC1AF3276, 0x2BD6B65C, 0xB72CD133, 0xB72C5E4B, 0x7BCBFC9C, 0x4C704B6E, 0x13E9DB76},
	{0x001C4CF7, 0xC4A3AF33, 0xD9139FC8, 0x711314F9, 0x2E3975F1, 0x2D8A0413, 0xDB938BE3, 0x24535E3B} } ,
	 { {0x3CA245C6, 0x8516CA0D, 0x27CD47D4, 0xC6EA7A75, 0x5E595A17, 0xACF68810, 0xFF4A6E2D, 0x19222367},
	{0x93940F86, 0x56E8CC13, 0x47697A55, 0x50A494EE, 0x26AFAB25, 0xCD11F6EC, 0xE400CD2A, 0x21234058} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x02C6EC67, 0x1BCAA80C, 0xBBC86027, 0x86A4CF6F, 0xB225484E, 0xB968A6ED, 0x3B604BCF, 0x15A6975D},
	{0x1BF78C75, 0x5253EC1D, 0xFCE0A640, 0xAE922E71, 0x3C8EAE2C, 0x727D8F38, 0x1C996D62, 0x1C03A05D} } ,
	 { {0x64D49DC4, 0xBEE0E172, 0xF23805E2, 0xF5917986, 0x25264315, 0x4FBA2F57, 0x8226B18C, 0x1A3F83B6},
	{0x178B982B, 0x66CA47EE, 0x04FFC35E, 0xA666E01D, 0xAA75BF4F, 0xFD2A632F, 0x713FBC0F, 0x176ECA2A} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5359 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5360 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5361 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5362 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5363 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x95143272, 0x21EBEF54, 0x8AD99C6D, 0x010653D4, 0x29DB131F, 0x90A58268, 0xB1609EF1, 0x1ABC0ABD},
	{0x25A1D2A1, 0x30571F2E, 0x853445FC, 0xCAEBA3C6, 0x5A361D8F, 0x276FC437, 0x8E18C939, 0x11D75607} } ,
	 { {0x7AA7CB5B, 0xD833E5DF, 0x6F1DE12E, 0xFE7B80BD, 0x0F763E3D, 0xB92DBF31, 0xE2A69D45, 0x00427986},
	{0x26357C17, 0x7B565767, 0x0625EB95, 0xEF4EFD27, 0x6F99977A, 0x7A6FF4AE, 0xEE70B04C, 0x0A13FC56} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAEC6A4D2, 0x74E46BF6, 0x5BBD54EF, 0xDA86F4A7, 0x500EF1AF, 0xA5A32C79, 0xEE50D941, 0x1281D6A0},
	{0x1E67F675, 0x2F2B941B, 0x9E604C9C, 0x0E698B0D, 0x688F4017, 0xCC60D608, 0x6231D4E1, 0x08B3A409} } ,
	 { {0x74A570E1, 0x5A0ADC1D, 0x068E3B47, 0x9F51F709, 0x56A881C7, 0x1FAC569D, 0x0E659854, 0x0286BF60},
	{0x41F1C8BA, 0xA8351370, 0x7D551AB5, 0x011EFFD1, 0x863705A4, 0x8D3BBC4D, 0x982CB939, 0x0AA31654} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5364 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5365 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5366 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5367 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5368 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x52A03FF2, 0x09560D26, 0xF0049E77, 0x48EDB6E7, 0x662F8025, 0x88D95DC0, 0xBFDE3D31, 0x0CA9BF3C},
	{0xBD374B18, 0x85F2BF56, 0x777FE3FC, 0xA2DAB2C5, 0xC9BFF2E1, 0x4D121DB2, 0x81A1B676, 0x06FA03B0} } ,
	 { {0xA70BA71A, 0x0F5A3899, 0xAF207C8F, 0xDFF8D135, 0x430880E8, 0xC30AF726, 0x2F15217F, 0x0F3FECEE},
	{0xE162DFEF, 0x54E07FDE, 0x0ACF7B8D, 0x26F1CC3F, 0x0AE38433, 0x5679EF1E, 0x43FEE8DA, 0x233D923D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x045A8744, 0x3D4D3A0E, 0xA0F77909, 0x3C1D9DEC, 0x49EC5D2D, 0x54EF86B4, 0x42ABFB02, 0x16B0AB5C},
	{0x91293787, 0x44AAD97C, 0x9D9240DA, 0x413635E2, 0x78EBDBB7, 0xF00B83B3, 0x077304BD, 0x22417E4A} } ,
	 { {0xBC78549A, 0xA7F25105, 0xABE876B1, 0xEB9A551F, 0x27961E05, 0x0F408B2F, 0xA06C7E03, 0x181ED079},
	{0xBDDD8CCB, 0xD4CD197D, 0x458241D9, 0x411ED9FE, 0x26187965, 0x326BD474, 0x67119F99, 0x1AC9F0B9} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5369 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5370 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5371 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5372 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5373 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x197820D4, 0x943F5250, 0xD8E24032, 0x1E6DDD39, 0x8289EA78, 0xA97C5EBB, 0xD7E7817B, 0x0C491261},
	{0xEB1C2FA7, 0x002C57D8, 0x48EDCAAE, 0x6327D04F, 0xC5D0A18C, 0xF5AE24CA, 0x756C0B67, 0x056EE40A} } ,
	 { {0x45D4330B, 0xD04078E4, 0x271269E5, 0x703FD81D, 0x380A4274, 0xC657B570, 0x7E58C65D, 0x1DE8A0BE},
	{0x8BAA2818, 0x6A54391E, 0xC58B29F5, 0x53D49D0C, 0x7FF5B27B, 0xFBEB82E6, 0x278AE6CE, 0x1E92F32D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x98CC9F7D, 0xD23D1084, 0x46D1B99F, 0xF628C797, 0x51897C59, 0xBCC706AC, 0xB456AAE6, 0x017F5986},
	{0xE9CDEFB1, 0x3C9DE107, 0x8C5EEBA4, 0x72B34A3F, 0x168CBD63, 0x345DA822, 0x4D010641, 0x14D22618} } ,
	 { {0x6B3B59C5, 0xBFA3C8D4, 0xD4EFEE67, 0xED58E730, 0xE848DE85, 0xE16314B9, 0xA1794D3C, 0x050A760C},
	{0x743BC76E, 0xC3C2E5CB, 0x650C5849, 0x42CCE513, 0x53068D58, 0x51EBA6AA, 0x0D192194, 0x1CE870FC} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5374 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5375 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5376 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5377 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5378 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0123BC0F, 0x9E8AC348, 0xEE94EA7B, 0x43B96A67, 0x62933A0C, 0x05DD390B, 0x12AB6393, 0x08492FAB},
	{0x90794D48, 0x18DEEB8A, 0x37A52CFD, 0xFF4763AA, 0x7AF76A78, 0x677D9F30, 0x4341ACFA, 0x008793A3} } ,
	 { {0xAC7F72B3, 0xCEC8718E, 0x53E7458D, 0x6B2BF2C3, 0x54C32927, 0x1C5286E0, 0x988F8DB5, 0x0CE87A06},
	{0x419535B1, 0x56FCCB49, 0x4A203756, 0xF53311EB, 0x39185541, 0x6E406672, 0x30B50FA1, 0x1D63A51F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB90E3592, 0x5A4C9DAC, 0xBD3C643E, 0x09889D7A, 0xE8DA7B96, 0x624F608D, 0x293AFE2D, 0x2038F4F4},
	{0x0053C9F2, 0x81B12F82, 0xAF8AE9AC, 0x6D60B6F8, 0x16F046F1, 0x3E0D9726, 0xBC85025A, 0x0E7A7F21} } ,
	 { {0x6BC2EBFF, 0x445B0262, 0xEE689352, 0xACB8FA4B, 0x8C8A66F4, 0x98EE30AD, 0x03E324F3, 0x0A8A5D94},
	{0x14884EE0, 0x8EF82227, 0xE0C3A306, 0xF9064DCB, 0x0FA2C44E, 0xAFACEE5E, 0xD5167D8B, 0x12B855A2} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5379 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5380 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5381 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5382 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5383 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x39C5B449, 0x37894437, 0xEA2EFF47, 0x746F1A79, 0x0AE88131, 0xCDFDB051, 0x2E5245E4, 0x054B5A9C},
	{0x2BF53EFD, 0x97E33C78, 0x032C5E09, 0x15689791, 0xF2FA06B5, 0x5B5EFA27, 0x7D3198B3, 0x04C64FE3} } ,
	 { {0x9DD890B2, 0xE72BAB33, 0x894A2E43, 0x317BDA12, 0x65276AE1, 0xBF051FBD, 0xF0C8B25E, 0x0EADFDAB},
	{0xE7C898EE, 0xE50FCD8F, 0x40CA8398, 0x2331EB6C, 0x8BE82E0D, 0x8E934279, 0xF08C3BD5, 0x030928C5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xEE0DA421, 0x8C13F2A6, 0x6D2510D5, 0xAD0816E4, 0x0C1447BF, 0xB60E759D, 0x66B03ED7, 0x18E96E73},
	{0x387EB44E, 0xB527674E, 0x4460891D, 0x31BD5B75, 0xA9E9BF78, 0x354395BF, 0xF63BFA4D, 0x116FD56A} } ,
	 { {0xB72A2749, 0x5CB38373, 0x50C0F1A7, 0xE104D8C7, 0xB83E3AB8, 0x4A22CAA2, 0xF3C4C0C9, 0x0A23D06F},
	{0xDA24C772, 0x475416A9, 0x7C2A39E1, 0x60B4CCCB, 0x5FD77893, 0x6BB81E54, 0xBEAB1A8A, 0x05305459} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5384 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5385 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5386 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5387 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5388 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE94BA64A, 0xB1F7F526, 0xDC0814DE, 0xDCE4424D, 0xE67E7FB6, 0x507259F7, 0x656FE0C6, 0x0175F6B6},
	{0xE94B343B, 0x0BA95661, 0x7766A837, 0x14003047, 0xC2A074F4, 0x299BAF92, 0xB75CF8FA, 0x0F04C7C8} } ,
	 { {0x438B4C96, 0xC36E9E11, 0x8D682B7D, 0x3474AE76, 0x0EF7E16D, 0x7B078B9E, 0xB82DF8A8, 0x08C3BEF7},
	{0x7873B552, 0x8C711854, 0x75EFC403, 0xEF690E8B, 0x3A1B6A36, 0x11536151, 0xE307D762, 0x084707AE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xF83562EF, 0x6E664470, 0x47D123E9, 0xD05C0849, 0xF10F4E65, 0xA9360A20, 0x7A6F979A, 0x1BC532A1},
	{0xAF886CA9, 0xA2D3E933, 0xF892B102, 0xEEF43BF9, 0xE4EFA4D8, 0xD4E2C451, 0xD18F464A, 0x0E4C49AE} } ,
	 { {0x14D42FE6, 0x1B143349, 0xD3877C63, 0x92C5F89C, 0xA83C7149, 0xA5C3FEA4, 0x16762A9F, 0x248DA49A},
	{0x0FA7EB0B, 0x7888A80C, 0xA16350F6, 0x015EED53, 0x8DD4DB8F, 0x78D3E48B, 0xC0248426, 0x0042D886} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5389 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5390 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5391 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5392 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5393 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x403CAD92, 0x25287AD6, 0x660EFC08, 0x361F5F53, 0x1BFDB0C6, 0x5D976C54, 0x5F1A0129, 0x248BF237},
	{0xA9C02F41, 0x5DA9E077, 0x058E6063, 0xAA0CE38B, 0x0DC1117E, 0x4F861E01, 0x6FEF0C79, 0x03D790B8} } ,
	 { {0xDDF5DECD, 0x9F8285BA, 0xBF6EFC6B, 0xE7029FE9, 0x74160BCD, 0x85CADEA5, 0x9E9E7432, 0x1B382142},
	{0x25C6FABC, 0xB1686D46, 0x0890D484, 0x1DF94FF0, 0x9ACD2B9A, 0x9B188C4D, 0x954F5B72, 0x1454CE13} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE9FA7A3C, 0x028EE2E6, 0x52628208, 0x6D4B5413, 0x9AEE2504, 0xC8EB87FD, 0xABEECF00, 0x0C8EDC5E},
	{0x9D8A10D7, 0xAB6442DB, 0x42D60B5F, 0x56E9DA19, 0xE88FE342, 0x8E716D65, 0x89D2D43B, 0x15C898D7} } ,
	 { {0xE9405F8D, 0x113A0112, 0x390E9391, 0xDBB90A73, 0xDD8993FE, 0xF8914AF9, 0xDF4B291A, 0x1CCB92EA},
	{0x9D0B1920, 0x2FD92A14, 0x093014DD, 0xA5A95CFA, 0xB35943A3, 0xA918A4A1, 0xAF42B180, 0x21C2A523} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5394 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5395 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5396 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5397 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5398 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2999315A, 0xBDE2B1BC, 0x2B8FCF21, 0x9A081404, 0x3FF9B051, 0x5060482E, 0xFBFFC8CD, 0x10E51965},
	{0xEF2B128B, 0xE2392841, 0xEFDC128A, 0x28036CBA, 0x6EC2E854, 0x1378873E, 0x7F20EB18, 0x1E6DEE66} } ,
	 { {0x5455E325, 0xE56325E5, 0x5131538F, 0x33681E7E, 0x0E7BF831, 0x77865AC6, 0x06026B30, 0x21392A30},
	{0x1E40F7FC, 0xB9C455DC, 0x4E9AC64F, 0xC67BA388, 0x5E3747F8, 0x50688B6A, 0xD0C32D2D, 0x1AA88B83} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x5BE72866, 0xDCAED2F6, 0xEF8F1605, 0x74952289, 0xCFC04FFD, 0xF05D759B, 0xC59AD0CD, 0x17F1DEA3},
	{0x34050625, 0x1C4E4361, 0xACB95116, 0x1EBC9588, 0xED64A22B, 0xA437F7CA, 0x14DC5D44, 0x0348B9EB} } ,
	 { {0x21ADDDC7, 0x3F5F4905, 0xA4015B52, 0xD649352F, 0x7032AC8C, 0xD0E3D296, 0x49E26DE3, 0x21FA13EC},
	{0x701EBA58, 0x026ECF73, 0xF8254A7B, 0x45DA46D5, 0xEEB2D780, 0x21B151B6, 0x47D80FF7, 0x1F7BFB46} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5399 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5400 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5401 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5402 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5403 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x18024543, 0x206E8584, 0xDB855EB9, 0x456A4404, 0x9F28D1BD, 0xE4473034, 0x2E68BB39, 0x251C54AD},
	{0xF005BC96, 0x65D87432, 0x1E668097, 0x9792A84B, 0xE09D310A, 0x85266B98, 0xAD411865, 0x1A0AFF52} } ,
	 { {0x309BA6ED, 0xC1542075, 0xC0C97B63, 0x923E27BB, 0x1E168A32, 0xD2CE6FAF, 0xACB2E052, 0x1AF48E7A},
	{0x7951D100, 0x2210BF82, 0x25C508C9, 0x277CE36F, 0x3E3B13A9, 0x8A8BC134, 0x26CC4DA5, 0x1D78E590} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2E7464CF, 0x9110EEDE, 0x2453FA2F, 0x88EA620C, 0x1667939A, 0x35312E63, 0x09C59DAB, 0x043241D2},
	{0x5B9AD66B, 0xB72054C3, 0xE2CC6ACE, 0x59AC0FB7, 0x17F04C09, 0x8AA5E99F, 0x946D54B3, 0x03767238} } ,
	 { {0xA383100D, 0xF3454EA9, 0xD56CB2B7, 0x19C9C9F7, 0x13728AFE, 0xE42DED7A, 0x90BE425B, 0x0FBB0112},
	{0x9E567627, 0x5B40238B, 0x12B6F856, 0xB6671736, 0x47E9C41F, 0x5FED88ED, 0xCBEA146A, 0x0B7A83FB} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5404 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5405 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5406 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5407 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5408 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD0F0D231, 0x3B473CF9, 0x751ED0F7, 0xD52121F4, 0x41282742, 0xA254056C, 0xCA59F093, 0x054DCD9B},
	{0x8C63BD32, 0xEABA10C1, 0xC6BAF98C, 0xCF50B664, 0x082FF346, 0x57DB4F22, 0x6F3F5E6F, 0x1FB90AF0} } ,
	 { {0xFB37DC31, 0x9B68D17D, 0x6B0542AD, 0xDA88884A, 0xF2AE732C, 0xDF5D0A4D, 0x5612F0E3, 0x04E8E59D},
	{0x8A178C87, 0x3010E4EA, 0xE487656B, 0xE10F2A01, 0x6F07AD6B, 0x87953EA9, 0x1561405C, 0x0E6456E8} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA38EE027, 0x876099E8, 0xDC75E9FA, 0x2AACD733, 0x13E36A9D, 0x7B85E25E, 0x70FADC01, 0x18D80097},
	{0xAF125F28, 0x9A05B723, 0x0729FFF1, 0xBC246B19, 0xC426978C, 0x1A185E2C, 0x21D5B390, 0x1C8954A7} } ,
	 { {0xEE644B77, 0x3F841299, 0xE0731B7E, 0x8A91E656, 0x39C13FF2, 0x58D04833, 0x8CDA2DC2, 0x038C26ED},
	{0x500291B7, 0x54785C05, 0x2A1FFD90, 0xF19BE847, 0x607A0E59, 0xFF55D68C, 0xBB096240, 0x14732449} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5409 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5410 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5411 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5412 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5413 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x550F1E66, 0xED0834BA, 0x5E8D815D, 0xA6C68C5F, 0xC02AD62E, 0xFD475BB5, 0x39EB27A2, 0x23C1C10A},
	{0xC054234A, 0x65C82775, 0xC03D5EB5, 0xBE0877BF, 0x8D3AF86C, 0x16B2AE72, 0xC512611E, 0x146ACEDA} } ,
	 { {0xA233084E, 0x2E77526C, 0x91798BD5, 0x8528A2AB, 0x2A44DA9B, 0xDEB6515D, 0xF4FF1BF5, 0x0D23B0A5},
	{0x8963FFD1, 0xBAA53A22, 0x820E4B87, 0x4B730B4B, 0x951A468A, 0x9D31DF3B, 0x0458FAD2, 0x14736ABC} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3D63CFE7, 0xC8BD093E, 0xF6FB2D9A, 0x55FC7046, 0x026DC23A, 0xAEAE2AF1, 0x7AD443E4, 0x1BBE3E0F},
	{0xD77087E3, 0xD099E8EB, 0x68332275, 0x1D9BBA32, 0xEEF86BEA, 0x2DF8B084, 0xB4FFF8C7, 0x0758EFC2} } ,
	 { {0x94291D9E, 0x96D8AC7C, 0xE587E685, 0xD8AAA1C3, 0xCD1FF4C5, 0x31956F8F, 0xBB9AEFC8, 0x12E702E5},
	{0x5099D5FD, 0x5C9CD84C, 0x4B127F25, 0x7C4887F0, 0xD59B6D26, 0x93D7F1F5, 0x50A7FB87, 0x16B78208} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5414 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5415 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5416 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5417 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5418 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA593FAB9, 0x32C97D56, 0x956B223B, 0x202F26B2, 0x678C282E, 0xB7BD7C0B, 0xD175F3DD, 0x1C9F8EF6},
	{0x369E3A3F, 0xE102EC50, 0xEBDCE865, 0x0B696DA8, 0x6854A752, 0x63AD8CD6, 0xFF7F210F, 0x22D35E20} } ,
	 { {0x7CA64420, 0x7793BC07, 0x2B612B6F, 0xF98BE7A1, 0x7DD11C96, 0xA6453CE7, 0xD1E346C6, 0x0064F132},
	{0xEEAB74C4, 0xDF7CE8B3, 0x9B67658B, 0x7FB3E739, 0xF803AEFA, 0x16182E39, 0xADD7CB53, 0x083CA7A3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3801C8B1, 0x72DC2A72, 0x82749A7B, 0x478A7839, 0x5991AA88, 0xFFE592F8, 0x69E34B39, 0x04302A27},
	{0x9D3272C0, 0xD10B4BE3, 0x2FABE96A, 0x98482535, 0x7E53DFAE, 0x8A64FE6F, 0x3D60D0D7, 0x078FBAD8} } ,
	 { {0x54918756, 0xF18BE749, 0xA552AF1B, 0x1D7E7618, 0xCD15BCD8, 0xDFFF34BB, 0xB0306A8B, 0x013F2E74},
	{0x798C9B52, 0xCD7ED8ED, 0xFB2E265F, 0x63727E66, 0xE65FCC01, 0xF5B3EE0E, 0x92D433D5, 0x1B3D762E} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5419 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5420 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5421 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5422 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5423 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE517D3E5, 0x55F4C315, 0x2F432553, 0x8F17C816, 0xC911B7AA, 0x05828DB4, 0x87B6CA93, 0x11D3DF3E},
	{0x6CCA0845, 0xD277CDBA, 0x4E8CA06A, 0x2C975577, 0xC955079B, 0x876164E8, 0xD82CDB35, 0x22A7EF2E} } ,
	 { {0x49238C6E, 0x92A77346, 0x56F15F6F, 0xD7AA2323, 0x9D9AACCF, 0x21574DEE, 0x4337EBB1, 0x2257B42E},
	{0x6304C805, 0x4958BAC9, 0x38F603A3, 0x5678F85D, 0xB854E7EE, 0x1DA2CCE9, 0x1C13EF25, 0x219B0823} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x1567BE68, 0xD7AB5546, 0x6D41AC3D, 0x52D44524, 0xF0454B63, 0x14127F3B, 0xC5197702, 0x0DFE25F8},
	{0x1A8DE8E3, 0x3E47E822, 0x1990EE17, 0x0EDAC37C, 0x2CAD926A, 0xFD37D9BA, 0x36C3C5F2, 0x12B96852} } ,
	 { {0x1A7F0906, 0xEF3644D9, 0xD603F9AF, 0x533D11B4, 0x554F6BF9, 0x6084757C, 0xB0033B48, 0x0F4B422E},
	{0x0B3C0930, 0xFF5D0EE8, 0x18E5F88F, 0xF8EB2B3C, 0xC99EFA87, 0x206A7965, 0xF3A56DED, 0x068063B9} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5424 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5425 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5426 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5427 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5428 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA91644E0, 0xE086154A, 0x28447D1F, 0x17735BEE, 0x7095173A, 0x3BB7F75E, 0x67B1B93F, 0x0E93FB96},
	{0x4EECB5EA, 0xEEA657DF, 0x76AF69E7, 0x5BA1AED8, 0x59886EA4, 0x19CAF7A4, 0xE2F02A6C, 0x0F0134B2} } ,
	 { {0x24A7585A, 0x9A5E2A24, 0xB03131BB, 0xD704D161, 0x1A01D140, 0x37247D7D, 0x11C405B7, 0x16DA2D6B},
	{0x0C1A751B, 0xBAF62A70, 0xC2C1F2B3, 0x071F5160, 0xAC107890, 0x460F7CEF, 0xD2E14834, 0x2503C35A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x320FB3D3, 0x37669A24, 0xE8895016, 0x40B4DC86, 0xC87C6F59, 0xD154325E, 0x7B44AEEE, 0x21C67D48},
	{0xD4FFAD72, 0x73EEB106, 0xFE89DCD8, 0x42362642, 0xBC75696E, 0x451294C9, 0xB92BA905, 0x0AD345FD} } ,
	 { {0xD1A2C8E4, 0x9CDDDA88, 0xC72847EF, 0x6A9AFA7D, 0xA2894169, 0x0163BA97, 0x2CE095F0, 0x0458CB98},
	{0x67E96961, 0xF370003D, 0x8B156267, 0x67365B23, 0x07F2121A, 0x2A045B3F, 0x77777FFE, 0x0D0E3FEF} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5429 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5430 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5431 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5432 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5433 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC43ADD7F, 0xF2BD1C3B, 0x99B3E031, 0xAB17BC1C, 0xB9BB55C7, 0xAD6B7A4F, 0x93A0AFC2, 0x148C21F6},
	{0x515C10FD, 0x8A4AAA3E, 0x987FEAAE, 0xC663840C, 0x2320C9ED, 0x7DC4C24B, 0xFD179E1E, 0x01618C04} } ,
	 { {0x3C2A592A, 0xF9896E15, 0x1F66E309, 0x26681FAA, 0x3FDF6078, 0xC684EC9E, 0x8E44D76A, 0x1E9EF87A},
	{0xDD2882A3, 0xBFACB2BF, 0xE2BC3F8D, 0xBCAE75DE, 0xCC4B746F, 0x051A3329, 0xE2A4E084, 0x242BE0C1} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0623A382, 0x860C2A69, 0xF686564E, 0x0BE37CF3, 0x19F71990, 0xA9470BD3, 0x14DAE854, 0x1E1A1EEB},
	{0xD4AAFE0F, 0xEB5C948A, 0xC0F8DAFE, 0x4B39C7FA, 0x64608C33, 0xBF2F2E23, 0x31B88519, 0x1AE16142} } ,
	 { {0xFEF37CA8, 0x50422C82, 0x73FC6A5C, 0xC06C11C1, 0xACBDF049, 0x6B4FE157, 0xC74D3E2C, 0x13FB3BB8},
	{0xFD7B025B, 0x4F2ABA07, 0x2D7F129F, 0x33AFC0F1, 0x58F6D3A0, 0x1BBC90E0, 0xF14D078B, 0x1E780B32} } ,
	 { {0x7854B241, 0x4C12DC2A, 0x3ECDC600, 0xEBAF3F54, 0x7FBEC0E7, 0xD2D58BBC, 0xDC89AED3, 0x181A8C72},
	{0xBA510533, 0xD859657F, 0xC5787F07, 0x183BEBBD, 0x9896E8D7, 0x500018D3, 0x8549C106, 0x23345D01} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5434 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5435 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5436 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5437 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5438 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5439 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5440 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x32A96E99, 0xB5DE3388, 0x09CD0CE5, 0x646E81D5, 0xF4C358B2, 0x509496AC, 0x8943CDC7, 0x22E3DFC0},
	{0xE0BCA218, 0xF383CA32, 0x866977E5, 0xF6ED3CD7, 0x32E1C04B, 0xA2000479, 0xDF06CB0A, 0x06AD7646} } ,
	 { {0x99636134, 0xB81F4518, 0x6B22F5AB, 0x497F356B, 0xB16DEC92, 0xB13FC005, 0x31980842, 0x05DBA378},
	{0x46334C15, 0x7177C63D, 0xCF56FD25, 0x8A312243, 0x98B43F29, 0xE4E659CA, 0xE8801A04, 0x0F3F0483} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB135A0FF, 0x4AEDD7A6, 0xE2306AA1, 0x35DFF0F9, 0xCD224F98, 0x22B82D0C, 0x7587263D, 0x0CFDFFAC},
	{0x8D5E76F5, 0x71D29BC7, 0xB34CBF54, 0x9FAF60DE, 0xB7B6C70E, 0xF67128AB, 0xAF08A796, 0x236BD386} } ,
	 { {0x467FC725, 0xA2832692, 0xB5576F87, 0x3320D1C0, 0xAE80FBEA, 0xE849340C, 0x57E4E2CF, 0x1795AF57},
	{0x63F8FD55, 0xD56A0D77, 0x28F53B3F, 0x960F0738, 0xED5B7C28, 0x053B0991, 0x976D5E14, 0x1BDDF70F} } ,
	 { {0x32C6C268, 0x703E8A31, 0xD645EB57, 0x92FE6AD6, 0x62DBD924, 0x627F800B, 0x63301085, 0x0BB746F0},
	{0x8C66982A, 0xE2EF8C7A, 0x9EADFA4A, 0x14624487, 0x31687E53, 0xC9CCB395, 0xD1003409, 0x1E7E0907} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5441 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5442 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5443 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5444 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5445 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5446 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5447 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x74B33A87, 0xE8BA540D, 0x68CEF5B7, 0x0F41400E, 0xD73CC275, 0xBBA11375, 0xAAC4E5BC, 0x19108710},
	{0x273EE14A, 0xCE78FD52, 0x46CA0868, 0x87B1AA6E, 0x256A3A1B, 0x0248BD27, 0x436DDD28, 0x010B9BE0} } ,
	 { {0x5226D504, 0x13217D31, 0xCBFD4A76, 0x3D40C8FE, 0xD33017C2, 0xE03C1757, 0x2FBBE9CE, 0x0FEDEE5B},
	{0x8EB4DFEC, 0x8F9D36F5, 0x95D33AF1, 0xC0A81ECD, 0xBC2FAA4C, 0x4EA050E9, 0x077CA364, 0x19BC61C3} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x6D8AB84A, 0x5A71F051, 0x7BAB7837, 0x89ED2539, 0xFC8FBB03, 0x5C292195, 0xC4EC0A99, 0x1B529EF4},
	{0x7238F281, 0xE8FF17ED, 0x8DB39D67, 0xFEF94E37, 0x5E515F3F, 0x1EB07D19, 0xA495D648, 0x01A207F0} } ,
	 { {0xB6A3F1E3, 0x50EC92B0, 0x6FAEDACE, 0x8554F494, 0xF71A79B7, 0xA53452D8, 0x10E6F701, 0x1BECBE81},
	{0x1A7F64F3, 0x99914EC8, 0xF1DA8F10, 0x76E56924, 0xA7F8C80B, 0x3B3FE1A4, 0x75863B52, 0x09F3ABAD} } ,
	 { {0xA44DAA08, 0x2642FA62, 0x97FA94EC, 0x7A8191FD, 0xA6602F84, 0xC0782EAF, 0x5F77D39D, 0x1FDBDCB6},
	{0x1D69BFC5, 0x783A6DEB, 0x2BA675CF, 0x202F3D9B, 0x785F5491, 0xE30C5453, 0xCEF946C6, 0x0E555F03} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5448 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5449 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5450 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5451 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5452 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5453 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5454 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5B9CCB7F, 0x11DE2ADA, 0x029FA7E2, 0x1FF01543, 0x3775ACCC, 0x3D09C610, 0xCFA3C960, 0x03C6932C},
	{0x4FABB4D9, 0xBCD37D16, 0x70A829F7, 0xCDABA1CC, 0x9CECA3C9, 0x019BA4ED, 0x7A1D4407, 0x0F309C31} } ,
	 { {0x4DD4F5CF, 0xE4B98F8B, 0x40540A01, 0x81B3CAB7, 0x9335B09E, 0xD0A939F4, 0x47641A42, 0x00AD1E5A},
	{0x32857AE1, 0x407E40A0, 0xE897CFAC, 0x24C96683, 0x96D26E60, 0xC18BB659, 0x8FB37C7E, 0x1931FFED} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xDEBAC585, 0x643CF639, 0x09D6CFA4, 0x3149ACBF, 0xE6DDD257, 0x261D6E71, 0x3D8130ED, 0x24E20678},
	{0x4E6C29A4, 0x7E699CB3, 0x54BD91AA, 0x3E7D3E41, 0xDE6EE10D, 0xBD6BB6A6, 0x64388DE8, 0x1934620E} } ,
	 { {0xA52B1145, 0x46CF375E, 0x2B650815, 0x303C9FB7, 0xC0950541, 0x8B809E2B, 0x8EE75E8C, 0x184FDC6D},
	{0x48095559, 0x359447E6, 0xF7C06536, 0xD0BE5084, 0x715593FA, 0x1BEBEC73, 0xB1068A90, 0x1C851F34} } ,
	 { {0x9BA9EB9E, 0xC9731F16, 0x80A81403, 0x0367956E, 0x266B613D, 0xA15273E9, 0x8EC83485, 0x015A3CB4},
	{0x650AF5AF, 0xD9FC8140, 0xD12F9F44, 0xE871CD07, 0x2DA4DCB7, 0xC8E31F33, 0xDF66F8FB, 0x0D409B58} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5455 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5456 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5457 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5458 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5459 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5460 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5461 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x78F58C51, 0x8CF17467, 0xAADE00CC, 0xD32991E2, 0x92FC522E, 0xDC44A3EE, 0x0E64C3AE, 0x1EAB90DE},
	{0x83BCDF75, 0xE4E359E1, 0x1E7B6544, 0x01682580, 0xF966CFE5, 0xDE097F5B, 0x9EB633CE, 0x1B7CD8BE} } ,
	 { {0x8127A252, 0x8D4CF947, 0x6A84F0F9, 0x6B248AA0, 0xF5031E2E, 0xD605CFD9, 0xCE56452D, 0x1FB8B227},
	{0x105B60FD, 0x23E57175, 0x7C06FE74, 0xCFA67B5A, 0xBFE68E5C, 0xACA654B4, 0x97DD66C3, 0x0C6DE230} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xCF4D0D49, 0x1878EA5C, 0x72EB4FFD, 0xA2FCF418, 0xF18D2CF3, 0xDAFCD881, 0xD39354B7, 0x1A45068E},
	{0x2972EB12, 0x8C3EB922, 0xA8D1FF32, 0x5801EBB0, 0x1B84DD03, 0x361E59EA, 0x7570A4A5, 0x192DD742} } ,
	 { {0xE4356375, 0xEB7D334C, 0xE97F693D, 0xA4E7C2EE, 0xAB455D4C, 0xF0E59032, 0x5C13A485, 0x08411BE8},
	{0x91C277A1, 0xAF852F84, 0xCE4458F6, 0xA67F087A, 0x4A7467DB, 0x1E31A5C7, 0x38006F70, 0x19E998EE} } ,
	 { {0x024F4491, 0x7399F28F, 0xD509E1DF, 0x75281540, 0xEA063C54, 0xF1D75233, 0x5CAC8A59, 0x1A4DFFCD},
	{0x20B6C1FA, 0x47CAE2EA, 0xF80DFCE8, 0x9F4CF6B4, 0x7FCD1CB9, 0x594CA969, 0x2FBACD87, 0x18DBC461} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5462 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5463 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5464 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5465 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5466 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5467 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5468 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8597D8A4, 0x3291CA2E, 0x662DA7AE, 0xA046E1BF, 0xAEA54874, 0xB45A3EBB, 0x3B7A3A99, 0x03AD6113},
	{0x68E85193, 0x7285A477, 0x69984FF6, 0x782A583C, 0x92D5A2B8, 0x6E30C191, 0x5D577022, 0x149165EA} } ,
	 { {0x518514BC, 0x975395F9, 0x3D8A2FE3, 0x589A80A0, 0x3325EFFA, 0x9D1CCCD8, 0x38EE69C0, 0x01B61B3A},
	{0xCB318EDF, 0x9EDBD721, 0xEA117C8A, 0xF4398B0E, 0x6FF9B22A, 0x6A009E4E, 0xD8BA0B3D, 0x161E5F41} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB7B79F1E, 0x285DC71B, 0x7E2845B2, 0x70386DB3, 0xA14CBD66, 0x8DAD8729, 0xCA2239CC, 0x0DB5A447},
	{0x8291A410, 0xA9A826B5, 0x70A81623, 0xD0239C7C, 0xFD368BD8, 0x318D1B10, 0x0F631985, 0x10D68EAC} } ,
	 { {0xE8A010A4, 0x5161F1F6, 0xA861AE6A, 0xBCD088B5, 0x2AF837D7, 0x63C1CE48, 0x96CB68B8, 0x124E798C},
	{0xA5870C93, 0x102D73BD, 0x0D0FA47F, 0x9F601DFF, 0x3FFD5B46, 0xD2169651, 0xA10BE291, 0x09DA177C} } ,
	 { {0xA30A2978, 0x2EA72BF2, 0x7B145FC7, 0xB1350140, 0x664BDFF4, 0x3A3999B0, 0x71DCD381, 0x036C3674},
	{0x96631DAB, 0x96B7AE43, 0xD422F901, 0x8752161D, 0xDFF3644D, 0x19CCEF1C, 0x71741679, 0x07195A01} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5469 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5470 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5471 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5472 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5473 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5474 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5475 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA376124E, 0x5CA5CFFB, 0x9B020244, 0x7FEE4313, 0x9DDC9F42, 0x5A94BE5D, 0x6ECA7D1A, 0x0C33B4C8},
	{0xFAEF4678, 0x9E83F853, 0x5FE53894, 0x70D68E51, 0x98DDE6E2, 0x025E4BB5, 0x519D306A, 0x04759755} } ,
	 { {0x5636A725, 0x659FD2BC, 0xEA436086, 0x9331A25E, 0x000A3EDF, 0x3896FA60, 0xDA89F2C0, 0x0F2E98A7},
	{0x16C4A070, 0xB1CD413D, 0x1D96A531, 0xF544E98F, 0x74C909BD, 0x71A7D3BE, 0x72FC58CD, 0x16350DEC} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xEA27C7CF, 0x54418CEC, 0x7B5F1287, 0xC7AB1F32, 0xFBBC02D7, 0xEC3B1769, 0xE5E71C65, 0x01569421},
	{0x9684427C, 0xB66EC882, 0xCC290F05, 0xAC8A89BD, 0x79FA7B72, 0x70ED7071, 0xE2739E17, 0x0507557C} } ,
	 { {0x6F15A11C, 0x941DF329, 0x7278CFAB, 0x863BA2FB, 0xEB3B8572, 0x38C16EF2, 0x2D85E5EC, 0x04352873},
	{0x130E49F8, 0xF642B8A2, 0x4B6FC014, 0x501DF7C1, 0x8FBF0BAC, 0x046F6353, 0x60787406, 0x215861C5} } ,
	 { {0xAC6D4E4A, 0xCB3FA578, 0xD486C10C, 0x266344BD, 0x00147DBF, 0x712DF4C0, 0xB513E580, 0x1E5D314F},
	{0x2D8940CD, 0xBC9A827A, 0x3B2D4A4F, 0x8968D31E, 0xE9921373, 0x291B59FC, 0xA5F8B199, 0x0746B756} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5476 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5477 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5478 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5479 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5480 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5481 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5482 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAB89E20C, 0x5E087DF0, 0xD90ECFD8, 0xC6DD241D, 0xFE1F66EB, 0x91FC10EA, 0x058C3EF9, 0x201281BA},
	{0xE57B43B3, 0xB835B302, 0x556CC98E, 0x79C2DF9C, 0x6F4A0694, 0xE7B994EA, 0x6C0BD218, 0x09DAEB99} } ,
	 { {0x2B7C42F1, 0xF09234D5, 0x7589A055, 0x3ED85A95, 0x1F187BFB, 0x6450BA23, 0xE6438E6F, 0x0D2C63F8},
	{0x53346167, 0x08000969, 0x658B480F, 0xB81DDC30, 0x5B240357, 0x44676475, 0x0D8CB15A, 0x06494D21} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x642388F4, 0x80D8F877, 0x5E18D12F, 0x3BE69A1E, 0x9B67402E, 0x3A1A0B69, 0x75DBC702, 0x140BB077},
	{0xC12E82D7, 0xB5B35842, 0x3AE0FA64, 0xBCDA308B, 0x15CCE771, 0x656C2FF3, 0xD3A36064, 0x0112EA9B} } ,
	 { {0x126F8776, 0x869B5D40, 0x3403AFDE, 0xE32730ED, 0xC7E20C90, 0x8FD09633, 0x02A47E68, 0x0B5C4A71},
	{0x5D517611, 0x5BA4E958, 0x16BD8408, 0x44049EDD, 0x4350ECBB, 0x2B74D3B9, 0x18FF8837, 0x10770617} } ,
	 { {0x56F885E2, 0xE12469AA, 0xEB1340AB, 0x7DB0B52A, 0x3E30F7F6, 0xC8A17446, 0xCC871CDE, 0x1A58C7F1},
	{0xA668C2CE, 0x100012D2, 0xCB16901E, 0x703BB860, 0xB64806AF, 0x88CEC8EA, 0x1B1962B4, 0x0C929A42} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5483 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5484 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5485 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5486 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5487 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5488 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5489 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x8AAB011A, 0x1F01E5FE, 0xC00AF881, 0x71114148, 0x3A8EACA3, 0x761D0882, 0x86921A59, 0x0E9CFD68},
	{0x4BE97A1C, 0xDF9F1568, 0xDC087949, 0xE19404DB, 0x35837141, 0x7C7FAA13, 0x91CA2978, 0x116CE7A6} } ,
	 { {0x9F625DAF, 0x58B6BC10, 0xBE947C0A, 0x082D2E91, 0x7D3CE04D, 0xBD2C5E3D, 0x4F9C2D37, 0x0BF5E2AC},
	{0x4B8DE0CC, 0xAB3CB511, 0x70BC5407, 0x24644E13, 0x4DC3FE91, 0x3EC93B94, 0xCCB84B53, 0x1A9B0FCC} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x4DF90361, 0xB53156D6, 0x2D58EA27, 0xF325ECDC, 0x087F34FA, 0x30543710, 0xC743CD83, 0x20DCFB68},
	{0xF8304DCB, 0x6903A9FE, 0x641D22E3, 0x0CE2492E, 0xEC31BFFE, 0x42A354AB, 0x7F0E07A4, 0x20396AB9} } ,
	 { {0x20B1966A, 0xA64DBCC1, 0xE6952FC7, 0x5048F8E8, 0xAE5A00E2, 0xA367310D, 0xC8B911BB, 0x14E89B52},
	{0x54B7E30B, 0x723C5321, 0x839D2D85, 0x1510883B, 0x3AEFB36E, 0x7DE56749, 0x55E919DB, 0x211D63B5} } ,
	 { {0x3EC4BB5E, 0xB16D7821, 0x7D28F814, 0x105A5D23, 0xFA79C09A, 0x7A58BC7A, 0x9F385A6F, 0x17EBC558},
	{0x971BC185, 0xAF796A22, 0xE178A7FB, 0xE7A79C26, 0x9B87FD19, 0xC35E29A8, 0x597096A4, 0x1012BB17} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5490 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5491 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5492 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5493 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5494 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5495 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5496 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x939DA630, 0x3A43664E, 0x02EBC966, 0xBB2A0952, 0xAFE5F2A5, 0x2FE1A521, 0x25483CEB, 0x072BEE68},
	{0x20FF72DD, 0x41EA2AAF, 0x21DDAECB, 0x6A77FEC5, 0x94067869, 0x0C357BFB, 0x160CF290, 0x21BA1D41} } ,
	 { {0x66CDEF0F, 0x1DF2B26D, 0xA854218A, 0xBBCBE4BD, 0xBC81B676, 0xF3ADBC75, 0xF83E12D7, 0x0A6089E0},
	{0x77EBB76F, 0xBFC6DCA8, 0xB1DC4181, 0x6E8B5F4C, 0x64D5BF28, 0x3F3311E6, 0x5A7755F2, 0x22286016} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xFCC708C3, 0x62101999, 0xA74E99B5, 0xEB0E8332, 0xFBEBF02E, 0xE5F42B5E, 0xF8D225D5, 0x0787737F},
	{0x058DF4E8, 0xB900FF58, 0xB582E4CA, 0x8A23211F, 0x15A004E5, 0xF48724B6, 0x9A4640C6, 0x1A470101} } ,
	 { {0xDB81D080, 0x8FF66F5F, 0xCE536017, 0xB4E57DAB, 0xCAF03BDD, 0x66AF5A1E, 0x570CD48A, 0x11402ED3},
	{0x2C382C03, 0x21A2961B, 0x45C734EE, 0xE60EE1F3, 0xF2F60EDF, 0x0D7FC4EC, 0xFCA27EBB, 0x187F5671} } ,
	 { {0xCD9BDE1E, 0x3BE564DA, 0x50A84314, 0x7797C97B, 0x79036CED, 0xE75B78EB, 0xF07C25AF, 0x14C113C1},
	{0xEFD76ECB, 0xD88DB950, 0x63B882EF, 0x7BF5BE99, 0xC9AB7E48, 0xC431D64C, 0x74EEABE2, 0x1F2D5BAA} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5497 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5498 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5499 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5500 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5501 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5502 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5503 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xF3026CDD, 0xDA4B4E3C, 0x0669B749, 0x42AF2C05, 0x318D4351, 0xD7C9413C, 0x85CA03BB, 0x0964CB24},
	{0x3426EE4A, 0x8E78ECBE, 0xCD29084D, 0xFC04520F, 0x8CDDB672, 0x0894A1AA, 0xE37D391D, 0x0FF7BCA8} } ,
	 { {0x55D6B37B, 0xF8F88D92, 0xD476527B, 0x2468F50E, 0xE3520EC6, 0x7A8A735D, 0x3454A390, 0x142F672C},
	{0x8C2AE1D5, 0x015D6B52, 0xCAC999E6, 0x45FABE14, 0xB556BFFC, 0x70B707B1, 0xBA4D6358, 0x0373D38D} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x41DD968A, 0xDB8B03DD, 0x70A94977, 0xEB6A930E, 0xD4598863, 0x79013A19, 0x3565F51A, 0x117CB860},
	{0x1C7973DE, 0xE03A36FF, 0xB358DBD2, 0xF98555E4, 0xD29431ED, 0xB332B8D9, 0x566CEE3F, 0x0D090E55} } ,
	 { {0x1BAB4650, 0xCCB22B87, 0x6BC8507F, 0xCDE6D15D, 0x2B809A8B, 0x60E03058, 0x855664DC, 0x138AFF0F},
	{0x42BCE433, 0x83763706, 0x1DF1ED8C, 0xDC7B1DD6, 0x276B21BF, 0xAF0BD997, 0x722E2993, 0x1CA41B2C} } ,
	 { {0xABAD66E3, 0x4AF11B24, 0xA8ECA4E4, 0xE7B0EA1D, 0xC6A41D83, 0x3AE0993B, 0x28A9471F, 0x033B69D6},
	{0x1855C3AA, 0x02BAD6A5, 0x959333CC, 0x8BF57C29, 0x6AAD7FF8, 0xE16E0F63, 0x749AC6B0, 0x06E7A71B} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5504 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5505 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5506 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5507 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5508 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5509 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5510 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9C0C95E7, 0x1259DA0A, 0x896853BE, 0x273CB0C9, 0x14EAF711, 0xCBBC86B7, 0x2BF8D6B7, 0x02153B44},
	{0xF64F8959, 0x332D14E2, 0x317DCA55, 0xCB7CB5AC, 0xB77B7C57, 0x295E869D, 0xECA5E944, 0x24E85381} } ,
	 { {0xB229467F, 0x3D41B0A6, 0xEC895DF3, 0x8C484D43, 0x95264648, 0x7A0E5386, 0xBE7DD5DF, 0x074BB352},
	{0x6BAC4861, 0x5F094CD6, 0xEFEFDD03, 0x127CD41E, 0x7E177D0C, 0x33A35396, 0x980F44D6, 0x05C4DF82} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xC7444F18, 0xF282D139, 0xAFB237BB, 0x2DA02B11, 0xF45907E4, 0xB9F5F106, 0x76A0AE2B, 0x1F7C2FDB},
	{0xB5E87F41, 0xCC697DF7, 0xDF630F13, 0xCEB86BE0, 0x6D4700BC, 0x86A079A5, 0x005AE0FE, 0x1C049375} } ,
	 { {0x2BD126AD, 0x5EDED84C, 0x6DD8BA8A, 0xC0222E76, 0xD2A7F8D8, 0xB8508451, 0xD75EA22B, 0x01C8A249},
	{0x2A8E7600, 0x36C84E56, 0x5B8D9137, 0x9CF82DF7, 0xABE15E4B, 0xFAE87F22, 0x1C4F77EE, 0x075DC044} } ,
	 { {0x64528CFE, 0x7A83614D, 0xD912BBE6, 0x18909A87, 0x2A4C8C91, 0xF41CA70D, 0x7CFBABBE, 0x0E9766A5},
	{0xD75890C2, 0xBE1299AC, 0xDFDFBA06, 0x24F9A83D, 0xFC2EFA18, 0x6746A72C, 0x301E89AC, 0x0B89BF05} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5511 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5512 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5513 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5514 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5515 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5516 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5517 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC26ADBA9, 0x8F478C15, 0x5DF8FA6E, 0x832583EE, 0x65F2245D, 0xBA79531A, 0x4C94BDEB, 0x20F997E2},
	{0x2BEA3954, 0xE2DEAAF3, 0x7FC3E0FA, 0x02E9E8DA, 0xEF3E4728, 0x1AC8BC89, 0x0DB2EBA2, 0x095927C9} } ,
	 { {0xFE468CBF, 0x2162CD45, 0xF482B14E, 0x1DE76FF6, 0x129C2D89, 0xB2EA9BD4, 0x180B1BE8, 0x0FCD1B32},
	{0x65CBE165, 0xA81224E2, 0xE3C08597, 0x1ED81855, 0x4233EEB0, 0x36F71682, 0x12CB68FE, 0x06C207C2} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xD4E99107, 0xB003DC6E, 0x4F2615F8, 0x60A52056, 0xBB8BC6F1, 0xD0381E51, 0xE92261CE, 0x19E92D98},
	{0x70BBEDE5, 0x7223E60C, 0x26D67413, 0x4AF0A695, 0x75E851AF, 0x07C22C43, 0xB5A28C6F, 0x2077E186} } ,
	 { {0xF81149CF, 0xE95494AC, 0x9CC5750D, 0x168BE47C, 0x5C2A6378, 0x554D7A0B, 0xC6D1145B, 0x14C68E69},
	{0x0CF92847, 0x8AF49B22, 0xC74A524A, 0x466C0D5A, 0xF4BBB8B7, 0x300B920D, 0x8D87097E, 0x2123552A} } ,
	 { {0xFC8D197E, 0x42C59A8B, 0xE905629C, 0x3BCEDFED, 0x25385B12, 0x65D537A8, 0x301637D1, 0x1F9A3664},
	{0xCB97C2CA, 0x502449C4, 0xC7810B2F, 0x3DB030AB, 0x8467DD60, 0x6DEE2D04, 0x2596D1FC, 0x0D840F84} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5518 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5519 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5520 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5521 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5522 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5523 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5524 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xDA79F84D, 0xAC3CB8B6, 0xD658404D, 0x10626978, 0x36C182D9, 0x455798E5, 0xED372A9C, 0x2169953C},
	{0x93AE41C6, 0xE8FE0545, 0x0BB2D05F, 0x3745864F, 0xFA7DAEAB, 0xDAD274A7, 0x0C0EB25D, 0x22BEAA71} } ,
	 { {0x0C588F26, 0xF50309A0, 0x76D3ADD8, 0x8559A8B8, 0xAB672274, 0x9F45C3A8, 0x88D44D7C, 0x0CDDCE89},
	{0xCBBA5D82, 0x552AA4DA, 0x7A7656CE, 0x59D70D3A, 0x746429F1, 0x715C2DBE, 0xD7C29621, 0x1ADF4FA8} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x532DFEBD, 0xC55D827B, 0xA35A9797, 0x6415D16D, 0x342100E3, 0x6AF3E1B9, 0x871BDB9C, 0x115A30FF},
	{0x37A23D75, 0x13CC0C51, 0xAD866C83, 0x6BAF55D1, 0xC1105935, 0xC0FBA40C, 0x39BCCD59, 0x14F3949E} } ,
	 { {0xA4F60B27, 0x89873C86, 0xCEFF1E4D, 0xCC50CD62, 0x57553C8F, 0xDCD1BEB1, 0xFE95E3A5, 0x05D8171F},
	{0x0C8F77AD, 0x388B4A32, 0xEA11F11C, 0x605926FF, 0x519CB949, 0x8BE336D6, 0x5D39756A, 0x1A5BD592} } ,
	 { {0x18B11E4C, 0xEA061340, 0xEDA75BB1, 0x0AB35170, 0x56CE44E9, 0x3E8B8751, 0x11A89AF9, 0x19BB9D13},
	{0x9774BAF1, 0x035549B5, 0xF4ECAD89, 0x528D1A74, 0xE8C853DA, 0x28840DFC, 0x6F852C41, 0x109B3ACF} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5525 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5526 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5527 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5528 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5529 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5530 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5531 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x5247774E, 0x1C49E8C2, 0xD7F46922, 0xF85B3874, 0xA1E9F214, 0x078B8B55, 0x684D3D2F, 0x05F48CFE},
	{0x407DC571, 0x1C904337, 0x78BE2296, 0xC4FFC032, 0x802F527E, 0x8FF6023C, 0x8AA1783E, 0x219A2EC5} } ,
	 { {0x9D7EF755, 0xC8B9DA99, 0x3FE9FDF1, 0x965CBFA5, 0xEED63371, 0x7628B647, 0x1B224A2E, 0x01366791},
	{0xDD7E330C, 0x77103446, 0xD3BB0AF0, 0xA50DC0EC, 0x58182C40, 0xA35DDF3E, 0x935F2D2E, 0x21BA246D} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x9F8A7BE5, 0xAB6E6F7D, 0x5968FE58, 0x2E3D3016, 0xC1C4E7B0, 0x0D465ECC, 0x7AB4B847, 0x15B42E5D},
	{0xFE9D93A5, 0x10D9C493, 0x8396C673, 0x4178C264, 0xD5A0E6A2, 0x12678B19, 0xC398B3E7, 0x2455DC81} } ,
	 { {0xFCB88F92, 0xFFBBD29E, 0x2555A59B, 0xE9FA5E73, 0xCBB8F258, 0x476D43CE, 0x74CA732C, 0x18CAC36F},
	{0xC96449FC, 0xDD7756DF, 0x6FF78C4F, 0x8B705DF8, 0xFF7E8089, 0xB0BC3F12, 0xB75BECE1, 0x000DA2CF} } ,
	 { {0x3AFDEEAA, 0x9173B533, 0x7FD3FBE3, 0x2CB97F4A, 0xDDAC66E3, 0xEC516C8F, 0x3644945C, 0x026CCF22},
	{0xBAFC6605, 0x4720688D, 0xA77615CD, 0xE8FA81D9, 0xB0305878, 0x8C8770FC, 0xE6BE5A5B, 0x1E50E458} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5532 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5533 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5534 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5535 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5536 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5537 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5538 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xEED41692, 0x22056158, 0xAA30E873, 0x79DCF305, 0xD46D310B, 0x312147DE, 0xEADF6350, 0x1A24A7B8},
	{0xF12093CE, 0x68D2B73F, 0x7659F460, 0xFC91CBD5, 0x31E4AAE6, 0x08E799C2, 0xE08F6E45, 0x05D35759} } ,
	 { {0x6E51B255, 0xD9EE60C4, 0xF3426EAC, 0x4D4EAB29, 0x70A70C78, 0xF57D00A2, 0x0E3EAD8C, 0x085F6E14},
	{0x1AC32D77, 0x10D109DE, 0xB3C45236, 0xA225D6F1, 0xFE8C8F14, 0x06422498, 0x7D3C3957, 0x11D61436} } ,
	 { {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0D7273B3, 0x1DD148BF, 0x826A4C90, 0x085FE48C, 0xB975B697, 0x23879CA7, 0xBE5F62F4, 0x1DBDFCED},
	{0x3E58D6C7, 0xA0EC2FAA, 0x9DE17471, 0xEC0D7046, 0xBAF29C56, 0x07F13C3A, 0xE09FA561, 0x022199BD} } ,
	 { {0xF8564C04, 0x10003399, 0x38B0F800, 0x79FB30FC, 0x803E71B3, 0xD0B81F8B, 0xB74BEB1F, 0x13B73A59},
	{0xBE7D25C1, 0xE3BBEFCA, 0x684C165D, 0x0AB18F04, 0x367C18B3, 0x3E016FED, 0xDAB6B6C2, 0x220178BF} } ,
	 { {0xDCA364AA, 0xB3DCC188, 0xE684DD59, 0x9A9D5653, 0xE14E18F0, 0xEAFA0144, 0x1C7D5B19, 0x10BEDC28},
	{0x35865AEE, 0x21A213BC, 0x6788A46C, 0x444BADE3, 0xFD191E29, 0x0C844931, 0xFA7872AE, 0x23AC286C} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5539 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5540 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5541 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5542 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5543 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5544 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5545 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x97F931DC, 0xEA67C41A, 0x17ACC8A3, 0x8F9F8F52, 0xDC3B8D86, 0x15AC9B1C, 0x991F1E6D, 0x2482D399},
	{0xD9CB9725, 0xF019B775, 0xAD55BFE4, 0xEDE4D743, 0xF62D0220, 0xC08E0461, 0xAACD8682, 0x1614249E} } ,
	 { {0x00097F98, 0xBC4A2BED, 0xB62AE411, 0xD33F4EB4, 0x21DAF919, 0x74A83DBE, 0xD2D4D2E4, 0x0ECCF696},
	{0x0A7FBB68, 0x7F784AAC, 0x4350B10F, 0x22AEC485, 0x6BD7DA8C, 0xC08C62F0, 0x12410302, 0x20B8BBDD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x97F931DC, 0xEA67C41A, 0x17ACC8A3, 0x8F9F8F52, 0xDC3B8D86, 0x15AC9B1C, 0x991F1E6D, 0x2482D399},
	{0xD9CB9725, 0xF019B775, 0xAD55BFE4, 0xEDE4D743, 0xF62D0220, 0xC08E0461, 0xAACD8682, 0x1614249E} } ,
	 { {0xFFF6807B, 0xEAB5D412, 0x49D51C01, 0x8DE1B14B, 0xDE2506EE, 0x458C0FC1, 0x6D2B2D1D, 0x16566DEB},
	{0xF58044AB, 0x2787B553, 0xBCAF4F04, 0x3E723B7A, 0x9428257C, 0xF9A7EA8F, 0x2DBEFCFE, 0x046AA8A5} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5546 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5547 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5548 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5549 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5550 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7DE22742, 0x021B0460, 0x54DFF1E7, 0x42107376, 0xAB430FCB, 0x773F60E0, 0xA5396158, 0x16465E0D},
	{0x281BCB0A, 0xEA6B7C82, 0xE34CD20C, 0xCB0153AF, 0x9903BA30, 0xE249EDEC, 0x7ADC1AFA, 0x12451278} } ,
	 { {0xE442C0CE, 0x8E32256C, 0x419277D7, 0xEB932653, 0x3D38F985, 0x0F242D68, 0xBBC96CE8, 0x01C7D471},
	{0xDBC0CF4A, 0x7E8C5AF2, 0xCE6E24F9, 0x97B7F18F, 0x21FDE0D5, 0xB441C50F, 0x82FDAB14, 0x16E59867} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7DE22742, 0x021B0460, 0x54DFF1E7, 0x42107376, 0xAB430FCB, 0x773F60E0, 0xA5396158, 0x16465E0D},
	{0x281BCB0A, 0xEA6B7C82, 0xE34CD20C, 0xCB0153AF, 0x9903BA30, 0xE249EDEC, 0x7ADC1AFA, 0x12451278} } ,
	 { {0x1BBD3F45, 0x18CDDA93, 0xBE6D883C, 0x758DD9AC, 0xC2C70682, 0xAB102017, 0x84369319, 0x235B9010},
	{0x243F30C9, 0x2873A50D, 0x3191DB1A, 0xC9690E70, 0xDE021F32, 0x05F28870, 0xBD0254ED, 0x0E3DCC1A} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5551 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5552 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5553 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5554 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5555 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD6655F96, 0xFE0A748C, 0x8A6B2A32, 0x786A82F2, 0x9238FDED, 0x6709B02D, 0xEFE87CAA, 0x19929D35},
	{0xF133004B, 0xF71F1E1C, 0x0E22B9DF, 0x5ABC6071, 0xDA928FAF, 0xAFFC0C4F, 0x7A5D5AAE, 0x115EAD97} } ,
	 { {0x23671094, 0xE35187C7, 0x8DE32C74, 0x207C48B4, 0xDA49490C, 0xD8E1046F, 0x9D0BEDFD, 0x0CE898DB},
	{0xAA34C5E0, 0xD9A76088, 0x57474E33, 0xD3FC9A24, 0xB9768E37, 0xCB3B654E, 0x97CBF88B, 0x059EC4B0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD6655F96, 0xFE0A748C, 0x8A6B2A32, 0x786A82F2, 0x9238FDED, 0x6709B02D, 0xEFE87CAA, 0x19929D35},
	{0xF133004B, 0xF71F1E1C, 0x0E22B9DF, 0x5ABC6071, 0xDA928FAF, 0xAFFC0C4F, 0x7A5D5AAE, 0x115EAD97} } ,
	 { {0xDC98EF7F, 0xC3AE7838, 0x721CD39E, 0x40A4B74B, 0x25B6B6FC, 0xE1534910, 0xA2F41203, 0x183ACBA6},
	{0x55CB3A33, 0xCD589F77, 0xA8B8B1DF, 0x8D2465DB, 0x468971D0, 0xEEF8E831, 0xA8340775, 0x1F849FD1} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5556 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5557 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5558 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5559 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5560 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3C4A6828, 0x3E99E4D2, 0x2739E344, 0x223C9D93, 0xFBB2DF8A, 0x758E1FAE, 0x79C438B5, 0x07ED173A},
	{0xC94B1524, 0xA834FB30, 0x80CFBE27, 0x4EB658D1, 0xDCB4A073, 0xFBD9B7D7, 0x035C6075, 0x22B9E4B1} } ,
	 { {0xE60B2181, 0xF4CAA7FA, 0x335AC955, 0xA293EFA8, 0x272F832D, 0xA257B4FB, 0x88185A84, 0x173BCE85},
	{0x78A0D5D8, 0x48156AD3, 0x2369BB01, 0x83A21C38, 0xF2AE57B6, 0xAF6B8E1C, 0x7C476A25, 0x1CBAEAF7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3C4A6828, 0x3E99E4D2, 0x2739E344, 0x223C9D93, 0xFBB2DF8A, 0x758E1FAE, 0x79C438B5, 0x07ED173A},
	{0xC94B1524, 0xA834FB30, 0x80CFBE27, 0x4EB658D1, 0xDCB4A073, 0xFBD9B7D7, 0x035C6075, 0x22B9E4B1} } ,
	 { {0x19F4DE92, 0xB2355805, 0xCCA536BD, 0xBE8D1057, 0xD8D07CDA, 0x17DC9884, 0xB7E7A57D, 0x0DE795FC},
	{0x875F2A3B, 0x5EEA952C, 0xDC964512, 0xDD7EE3C7, 0x0D51A851, 0x0AC8BF63, 0xC3B895DC, 0x0868798A} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5561 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5562 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5563 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5564 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5565 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x08DF9772, 0xEFA8C5C5, 0xEDCF00A4, 0x024CC866, 0x9F0BD91A, 0x1C2D160D, 0x8EB8CBA6, 0x06F9783D},
	{0x4C3BE2DE, 0x0FF99F9E, 0x86C73170, 0x11D12152, 0x45468D30, 0x565B6063, 0x652AC6D1, 0x1E002965} } ,
	 { {0x7F413F00, 0x95A95C72, 0xCCB5A82C, 0x8394FE6A, 0x779DBFA6, 0x749648D6, 0x21A5CCE2, 0x1EE3C2E0},
	{0xC6C01098, 0x5AF8D6B5, 0x339DDC6F, 0x5309589C, 0x266AE68D, 0xA2B5FC91, 0x8369F2B1, 0x0E238495} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x08DF9772, 0xEFA8C5C5, 0xEDCF00A4, 0x024CC866, 0x9F0BD91A, 0x1C2D160D, 0x8EB8CBA6, 0x06F9783D},
	{0x4C3BE2DE, 0x0FF99F9E, 0x86C73170, 0x11D12152, 0x45468D30, 0x565B6063, 0x652AC6D1, 0x1E002965} } ,
	 { {0x80BEC113, 0x1156A38D, 0x334A57E7, 0xDD8C0195, 0x88624061, 0x459E04A9, 0x1E5A331F, 0x063FA1A2},
	{0x393FEF7B, 0x4C07294A, 0xCC6223A4, 0x0E17A763, 0xD995197B, 0x177E50EE, 0xBC960D50, 0x16FFDFEC} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5566 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5567 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5568 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5569 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5570 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x542ED08D, 0x39FEF130, 0xD857FA1A, 0xC2DA9970, 0x4DB38E29, 0x8262C34A, 0x054065DB, 0x0753F180},
	{0x42B02ADB, 0xAA7D0DAE, 0x918DCE9F, 0xBCF9C1A3, 0x02734AE4, 0xCCADF9C7, 0xBBFC8792, 0x0D121C59} } ,
	 { {0x5C2D849F, 0x05D45391, 0xCD5B48A2, 0x7F6A20F3, 0xD835D33C, 0x9EBA8647, 0xC1407120, 0x01EB12C1},
	{0x8C69C938, 0xD2916289, 0x857FE98A, 0x7EE52BA4, 0xA01CD54B, 0xD9E89CB8, 0x60BB5C5E, 0x05E1EF76} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x542ED08D, 0x39FEF130, 0xD857FA1A, 0xC2DA9970, 0x4DB38E29, 0x8262C34A, 0x054065DB, 0x0753F180},
	{0x42B02ADB, 0xAA7D0DAE, 0x918DCE9F, 0xBCF9C1A3, 0x02734AE4, 0xCCADF9C7, 0xBBFC8792, 0x0D121C59} } ,
	 { {0xA3D27B74, 0xA12BAC6E, 0x32A4B771, 0xE1B6DF0C, 0x27CA2CCB, 0x1B79C738, 0x7EBF8EE1, 0x233851C0},
	{0x739636DB, 0xD46E9D76, 0x7A801688, 0xE23BD45B, 0x5FE32ABC, 0xE04BB0C7, 0xDF44A3A2, 0x1F41750B} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5571 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5572 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5573 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5574 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5575 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x849777DF, 0xD24A6978, 0xA27733B7, 0xBD2B30C4, 0x71E65CF6, 0xFCB0E2B1, 0x9BE4EE84, 0x2185C908},
	{0x8FAF5605, 0xD259873E, 0xE4959D03, 0xAD32BB71, 0x7E4ACDF4, 0xAC5D9829, 0x9CCEE26D, 0x0BD4117C} } ,
	 { {0x644F1A61, 0x4B5E018B, 0x3304FF9E, 0xF1ED31C5, 0x7F0329D0, 0x8D57FF5D, 0x9D88EA44, 0x1F1F2334},
	{0xD991A614, 0x152CF34D, 0x9A4C3F9B, 0xC34C0F0B, 0xC76F72C9, 0xAEB9F25F, 0x40207067, 0x200089BA} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x849777DF, 0xD24A6978, 0xA27733B7, 0xBD2B30C4, 0x71E65CF6, 0xFCB0E2B1, 0x9BE4EE84, 0x2185C908},
	{0x8FAF5605, 0xD259873E, 0xE4959D03, 0xAD32BB71, 0x7E4ACDF4, 0xAC5D9829, 0x9CCEE26D, 0x0BD4117C} } ,
	 { {0x9BB0E5B2, 0x5BA1FE74, 0xCCFB0075, 0x6F33CE3A, 0x80FCD637, 0x2CDC4E22, 0xA27715BD, 0x0604414D},
	{0x266E59FF, 0x91D30CB2, 0x65B3C078, 0x9DD4F0F4, 0x38908D3E, 0x0B7A5B20, 0xFFDF8F9A, 0x0522DAC7} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5576 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5577 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5578 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5579 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5580 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFB47C06E, 0x66F08221, 0xD4BAA1A2, 0xBAD53F59, 0x4A24F2EA, 0x0E95E611, 0xB7524716, 0x0F4E469E},
	{0xB92E9B2B, 0xC7185260, 0x7170CED5, 0x03E171FC, 0x955EBC06, 0x5333B21D, 0x8B2C7058, 0x1D0ACCCD} } ,
	 { {0x31A25983, 0xB38AC453, 0xC2FB09BD, 0xC42E7AD4, 0x0AA4AC46, 0xBF5FEE7A, 0x9817E4FE, 0x18187A25},
	{0xA4C5B410, 0x4BBD28C5, 0x94BA745F, 0xED267989, 0xD5E91FA2, 0xE541215C, 0xD53823CC, 0x1A8317C9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xFB47C06E, 0x66F08221, 0xD4BAA1A2, 0xBAD53F59, 0x4A24F2EA, 0x0E95E611, 0xB7524716, 0x0F4E469E},
	{0xB92E9B2B, 0xC7185260, 0x7170CED5, 0x03E171FC, 0x955EBC06, 0x5333B21D, 0x8B2C7058, 0x1D0ACCCD} } ,
	 { {0xCE5DA690, 0xF3753BAC, 0x3D04F655, 0x9CF2852B, 0xF55B53C1, 0xFAD45F05, 0xA7E81B02, 0x0D0AEA5C},
	{0x5B3A4C03, 0x5B42D73A, 0x6B458BB4, 0x73FA8676, 0x2A16E065, 0xD4F32C23, 0x6AC7DC34, 0x0AA04CB8} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5581 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5582 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5583 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5584 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5585 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x006D8E5B, 0xF3A8C792, 0xC5CD7112, 0xD0F4E307, 0xCB72D411, 0xF0789751, 0xECF1F176, 0x02C99BD5},
	{0x4DF7E65C, 0x3182D5A2, 0x2EE3795E, 0xCFBAA508, 0x1652975E, 0x29A9FED0, 0x1AFC0401, 0x1D7458F7} } ,
	 { {0xC14F4122, 0x2E78AE81, 0x043D3476, 0xB0C9CD70, 0xF7E63649, 0x414B8CDD, 0x1CABAAE9, 0x1072E44C},
	{0x00B813F4, 0x6DA8E2F7, 0xAF0DCCAE, 0x63D4265C, 0x9B6799D3, 0x90E236FA, 0xEB6AED34, 0x0A18E712} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x006D8E5B, 0xF3A8C792, 0xC5CD7112, 0xD0F4E307, 0xCB72D411, 0xF0789751, 0xECF1F176, 0x02C99BD5},
	{0x4DF7E65C, 0x3182D5A2, 0x2EE3795E, 0xCFBAA508, 0x1652975E, 0x29A9FED0, 0x1AFC0401, 0x1D7458F7} } ,
	 { {0x3EB0BEF1, 0x7887517E, 0xFBC2CB9D, 0xB057328F, 0x0819C9BE, 0x78E8C0A2, 0x23545518, 0x14B08036},
	{0xFF47EC1F, 0x39571D08, 0x50F23365, 0xFD4CD9A3, 0x64986634, 0x29521685, 0x549512CD, 0x1B0A7D6F} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5586 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5587 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5588 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5589 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5590 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5591 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5592 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB203EDF6, 0x2FB31525, 0x5869C83D, 0x184A6B7C, 0xBF40BCC5, 0x3FCCE40E, 0xD8A99BD2, 0x0880D8A7},
	{0x2760F402, 0xA6CDAB53, 0xA5C49DFB, 0x22E0F0BB, 0xEE7A9E7D, 0xDE0DCCB9, 0xF70FF091, 0x20B84630} } ,
	 { {0xFE915031, 0xF69FFF49, 0x688FA4ED, 0x52E9BD08, 0x70440712, 0xCC31BE4A, 0x63539FBC, 0x1AD39DDB},
	{0x0D11BC45, 0xF9B52513, 0xB80E02E0, 0xFBE83292, 0x0274ED5B, 0xE1FA2202, 0x2B55D6A1, 0x12A56C66} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB203EDF6, 0x2FB31525, 0x5869C83D, 0x184A6B7C, 0xBF40BCC5, 0x3FCCE40E, 0xD8A99BD2, 0x0880D8A7},
	{0x2760F402, 0xA6CDAB53, 0xA5C49DFB, 0x22E0F0BB, 0xEE7A9E7D, 0xDE0DCCB9, 0xF70FF091, 0x20B84630} } ,
	 { {0x016EAFE2, 0xB06000B6, 0x97705B25, 0x0E3742F7, 0x8FBBF8F6, 0xEE028F35, 0xDCAC6044, 0x0A4FC6A6},
	{0xF2EE43CE, 0xAD4ADAEC, 0x47F1FD32, 0x6538CD6D, 0xFD8B12AC, 0xD83A2B7D, 0x14AA295F, 0x127DF81C} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5593 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5594 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5595 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5596 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5597 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5598 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5599 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAA9E0AB6, 0x17AC3EE9, 0x9EF6973C, 0x2EFC5DF3, 0xAD66F37A, 0x1E0A8178, 0xF38C648E, 0x050BFF18},
	{0xA46D5F18, 0xDB6CEFED, 0xA0FC1780, 0xD5E8F27D, 0xC6BC7003, 0x89414139, 0x01AE73AD, 0x1C97914A} } ,
	 { {0xBAD5F9DE, 0xF6326F2E, 0x6794E64A, 0x4D9CE86E, 0xAB572AA3, 0x0D118BBB, 0x2A1832BB, 0x05575E88},
	{0xB5CEDEBC, 0xD7C93743, 0xB0283362, 0x5609AD43, 0x24F9FB2A, 0x873B9D54, 0x79585AC3, 0x02F96104} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xAA9E0AB6, 0x17AC3EE9, 0x9EF6973C, 0x2EFC5DF3, 0xAD66F37A, 0x1E0A8178, 0xF38C648E, 0x050BFF18},
	{0xA46D5F18, 0xDB6CEFED, 0xA0FC1780, 0xD5E8F27D, 0xC6BC7003, 0x89414139, 0x01AE73AD, 0x1C97914A} } ,
	 { {0x452A0635, 0xB0CD90D1, 0x986B19C8, 0x13841791, 0x54A8D565, 0xAD22C1C4, 0x15E7CD46, 0x1FCC05FA},
	{0x4A312157, 0xCF36C8BC, 0x4FD7CCB0, 0x0B1752BC, 0xDB0604DE, 0x32F8B02B, 0xC6A7A53E, 0x222A037D} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5600 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5601 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5602 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5603 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5604 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5605 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5606 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x598BC55B, 0x2BFAFA86, 0x5A59745F, 0x7F2AE605, 0x6A34F79E, 0x2A2F96EC, 0x5CA7D76A, 0x165A51B7},
	{0x24168188, 0x7F1CF373, 0xF0AC5498, 0x527C3791, 0xB05BAC70, 0x2A779F39, 0x6F65CF9C, 0x2014574B} } ,
	 { {0xD672C3CC, 0x2FE30340, 0x877052C6, 0xC025D2CD, 0x8C417781, 0x198B4053, 0x545B53AC, 0x0D404DE5},
	{0xAAC38426, 0x526BB039, 0xBC9E1166, 0x062387CC, 0xF623D82F, 0xA021E7AC, 0xF35E6CAC, 0x1080AC8A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x598BC55B, 0x2BFAFA86, 0x5A59745F, 0x7F2AE605, 0x6A34F79E, 0x2A2F96EC, 0x5CA7D76A, 0x165A51B7},
	{0x24168188, 0x7F1CF373, 0xF0AC5498, 0x527C3791, 0xB05BAC70, 0x2A779F39, 0x6F65CF9C, 0x2014574B} } ,
	 { {0x298D3C47, 0x771CFCBF, 0x788FAD4D, 0xA0FB2D32, 0x73BE8886, 0xA0A90D2C, 0xEBA4AC55, 0x17E3169C},
	{0x553C7BED, 0x54944FC6, 0x4361EEAD, 0x5AFD7833, 0x09DC27D9, 0x1A1265D3, 0x4CA19355, 0x14A2B7F7} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5607 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5608 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5609 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5610 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5611 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5612 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5613 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xAAB23AD2, 0xE1D380A6, 0x5BE1B4D6, 0xB9F7A2E9, 0xA265DE11, 0x5C4E3FBA, 0xB41BC50E, 0x1F36BFFE},
	{0x8F35C6BE, 0xFA65D56A, 0x1405BFA9, 0x84459582, 0x17C074B8, 0x3F960663, 0x9635F6BA, 0x1F6B14CB} } ,
	 { {0x38BD3083, 0x7D41058F, 0xD78B929C, 0xBBB18EB3, 0x8552DB10, 0xAADFBDE4, 0x29BC8089, 0x1DE716F0},
	{0xE13B3D88, 0xE500B2A4, 0x3D1E8C95, 0x9E0AA5EF, 0xCC75FCE8, 0x10BC1697, 0x6A7669E3, 0x164FEF7A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xAAB23AD2, 0xE1D380A6, 0x5BE1B4D6, 0xB9F7A2E9, 0xA265DE11, 0x5C4E3FBA, 0xB41BC50E, 0x1F36BFFE},
	{0x8F35C6BE, 0xFA65D56A, 0x1405BFA9, 0x84459582, 0x17C074B8, 0x3F960663, 0x9635F6BA, 0x1F6B14CB} } ,
	 { {0xC742CF90, 0x29BEFA70, 0x28746D77, 0xA56F714C, 0x7AAD24F7, 0x0F548F9B, 0x16437F78, 0x073C4D92},
	{0x1EC4C28B, 0xC1FF4D5B, 0xC2E1737D, 0xC3165A10, 0x338A031F, 0xA97836E8, 0xD589961E, 0x0ED37507} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5614 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5615 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5616 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5617 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5618 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5619 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5620 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB832D587, 0x415FDDA2, 0x23091DF0, 0x26CD45C7, 0x0FE356EC, 0xA7A03418, 0x0DE0C404, 0x05F4C775},
	{0xADB23B0B, 0xFB5572DC, 0x6900E835, 0x6614D0BB, 0x1A93CE36, 0xD992A722, 0xC22B83ED, 0x19740186} } ,
	 { {0xA6127257, 0x952E1BFF, 0xDF371F1D, 0xB58A2680, 0xB3E5CA31, 0x3E196AAF, 0xC94C9DE3, 0x05CB971B},
	{0x8DB9C835, 0x23DC39C2, 0x252F2BD6, 0x2FFD5E8C, 0x913BDFA7, 0x47F5B5A6, 0x8172846B, 0x16AB4A8A} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB832D587, 0x415FDDA2, 0x23091DF0, 0x26CD45C7, 0x0FE356EC, 0xA7A03418, 0x0DE0C404, 0x05F4C775},
	{0xADB23B0B, 0xFB5572DC, 0x6900E835, 0x6614D0BB, 0x1A93CE36, 0xD992A722, 0xC22B83ED, 0x19740186} } ,
	 { {0x59ED8DBC, 0x11D1E400, 0x20C8E0F6, 0xAB96D97F, 0x4C1A35D6, 0x7C1AE2D0, 0x76B3621E, 0x1F57CD66},
	{0x724637DE, 0x8323C63D, 0xDAD0D43D, 0x3123A173, 0x6EC42061, 0x723E97D9, 0xBE8D7B96, 0x0E7819F7} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5621 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5622 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5623 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5624 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5625 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5626 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5627 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3C48DEB8, 0xE01EA709, 0x52CE1F8B, 0x4A0BBD06, 0x2A20813F, 0x7A10DC7D, 0xFD5EBB44, 0x13A1C2C4},
	{0xAF59BEB1, 0x349F24B2, 0x8D27829B, 0x789E6432, 0xAB5DB6D3, 0x3FF93048, 0x2DA5CFBE, 0x0D5B799C} } ,
	 { {0x953A8A0D, 0xD9B470FB, 0xCB9BF9B4, 0x3E5EE692, 0xA860CF9A, 0x467E7400, 0xBBCB12CC, 0x1743F3CD},
	{0x8E879EF8, 0x1AB3020A, 0x64FCB7AF, 0x56294748, 0xDAD121CC, 0xC18A8C24, 0x0B9EB98C, 0x05B94498} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3C48DEB8, 0xE01EA709, 0x52CE1F8B, 0x4A0BBD06, 0x2A20813F, 0x7A10DC7D, 0xFD5EBB44, 0x13A1C2C4},
	{0xAF59BEB1, 0x349F24B2, 0x8D27829B, 0x789E6432, 0xAB5DB6D3, 0x3FF93048, 0x2DA5CFBE, 0x0D5B799C} } ,
	 { {0x6AC57606, 0xCD4B8F04, 0x3464065E, 0x22C2196D, 0x579F306E, 0x73B5D97F, 0x8434ED35, 0x0DDF70B4},
	{0x7178611B, 0x8C4CFDF5, 0x9B034864, 0x0AF7B8B7, 0x252EDE3C, 0xF8A9C15B, 0x34614674, 0x1F6A1FEA} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5628 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5629 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5630 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5631 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5632 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5633 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5634 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xE4970697, 0x0EE8DC98, 0x19F79CD7, 0xFDC14CD8, 0x1905857B, 0x85EDFC53, 0x9A3BB3B0, 0x1EA5F006},
	{0x3FDB8FB8, 0xE717BC19, 0x77D308DF, 0x80A6D0C5, 0xFDD53F45, 0x745F79AD, 0x68695D44, 0x0393EAA6} } ,
	 { {0x96A0E7CF, 0x67D81139, 0x7FD776A5, 0x05F34607, 0x3E5723B6, 0xED30B021, 0xD62E24EA, 0x1C7BF80B},
	{0x4944D332, 0xBFDF9DEF, 0xF09C1EF8, 0x14914775, 0xC405BCED, 0xD563713A, 0x55C14ABF, 0x01CC8961} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xE4970697, 0x0EE8DC98, 0x19F79CD7, 0xFDC14CD8, 0x1905857B, 0x85EDFC53, 0x9A3BB3B0, 0x1EA5F006},
	{0x3FDB8FB8, 0xE717BC19, 0x77D308DF, 0x80A6D0C5, 0xFDD53F45, 0x745F79AD, 0x68695D44, 0x0393EAA6} } ,
	 { {0x695F1844, 0x3F27EEC6, 0x8028896E, 0x5B2DB9F8, 0xC1A8DC52, 0xCD039D5E, 0x69D1DB16, 0x08A76C76},
	{0xB6BB2CE1, 0xE7206210, 0x0F63E11A, 0x4C8FB88A, 0x3BFA431B, 0xE4D0DC45, 0xEA3EB541, 0x2356DB20} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5635 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5636 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5637 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5638 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5639 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5640 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5641 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 925 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 926 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 927 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 928 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 929 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x960F14FF, 0x8AA6ABD6, 0x87EFEFE5, 0x16F4A65A, 0xC857B2F0, 0x7A9E7DF1, 0x03B186C6, 0x12562644},
	{0x8EB899FA, 0x7D9A9BDC, 0x782B19CD, 0x55956D8D, 0x19D2FE11, 0xE6B96044, 0x79D9BDEF, 0x0601323C} } ,
	 { {0xDA674DEE, 0x187C276E, 0xF35872B7, 0xC043B8D9, 0x67A35C1F, 0x5EFAC0F8, 0x3CAFCF7B, 0x084A96C2},
	{0xBE7030AA, 0x71453EE4, 0x04EF2AA9, 0xDBB33875, 0x990571EB, 0x9DCC4511, 0x74A0A3B6, 0x108174C7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 930 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 931 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 932 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 933 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 934 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x7C0EDFD6, 0xBDE9C986, 0xDF1B22F8, 0x7D69F700, 0xB5BA4082, 0x7F38E3E3, 0xA7CF9D28, 0x0E8FED82},
	{0x40B6E156, 0x0E42FF53, 0xBD937151, 0x1035EB63, 0xDF257459, 0x7251CF34, 0x66F9712F, 0x1D534411} } ,
	 { {0x2267D23B, 0x09C4629C, 0xF8A9D9D9, 0x7A038AAE, 0x162AA739, 0x85D1CBDA, 0xA720FCFE, 0x06728192},
	{0x6E691F8A, 0x409B12E3, 0x4322E184, 0x81B7BD08, 0xA8B0BFB0, 0xF7EC2192, 0x2A003910, 0x11A0F46A} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 935 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 936 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 937 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 938 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 939 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x59B1391D, 0x3CD78D37, 0x53B574E6, 0x31E61DC0, 0xD0C36228, 0x82232625, 0x95FED2A0, 0x21A13784},
	{0x0FAFDCAF, 0x8AB12F6E, 0x85B3FF80, 0xFA8DE058, 0x0BEA1089, 0x6E823007, 0xD2DF98A0, 0x216916D7} } ,
	 { {0x2265C5C0, 0xF3DDA53E, 0xDA098F2A, 0x0E862C50, 0x36A2103F, 0x1E602831, 0xA78273B6, 0x1FA14D2C},
	{0x47D29637, 0xE90A0E5D, 0x8096C3BD, 0x859557C8, 0x053169AB, 0x4928E4E5, 0x4678192A, 0x2475C522} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 940 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 941 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 942 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 943 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 944 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0xC02E6D70, 0x1856E61B, 0x75ABD774, 0x783F1E11, 0x676D3ADD, 0x0B27A11C, 0x4694167C, 0x2342C4AD},
	{0x5E77EF6E, 0x98E8A3EF, 0xC39D9E0D, 0x525365C8, 0x964CBE80, 0xC510575E, 0x962830C1, 0x1C60A199} } ,
	 { {0x9BC04A45, 0x0490FD41, 0x52688845, 0xA3284298, 0x6EC26CD3, 0x3D8EABD8, 0x4EC46D3A, 0x1BB3ED09},
	{0x625E5E7C, 0xFF2B094C, 0x15D99E11, 0xAAC36149, 0x9378F489, 0x7F95532F, 0xA5E25130, 0x0593D315} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 945 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 946 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 947 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 948 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 949 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xED7AEF1F, 0x1798CAA5, 0xC7387955, 0x69EA7FB5, 0xF5BB8996, 0xB152DD62, 0xAA93BA1D, 0x14F4B11F},
	{0x09EF5AB9, 0x215C7DCE, 0x0A60F17C, 0xFA0C8761, 0x6DF2070A, 0xFF6BF904, 0x58910D37, 0x00E99AFA} } ,
	 { {0x14DFDF25, 0xC9FF07C7, 0xA47BC2DA, 0xFE7D6C0C, 0x28E1D42C, 0xA6EF422A, 0xA51EBAA8, 0x1B2D2224},
	{0x8E26748A, 0x485A86F9, 0x1415A148, 0x3D9AE250, 0xC889EE46, 0xD91939B9, 0x09886B8F, 0x12B8520A} } ,
	0};
		static bigint_t var_k = {0xE27D9E35, 0x9B84ABE8, 0xBBC097C5, 0xCE493AA0, 0x04F8CEAF, 0x0ACEC155, 0xF09CA1ED, 0x1A7721AD};
		static const ecpoint_fp2 var_expected = { { {0x74D7D6AB, 0x762D8CF9, 0x437743D6, 0x29026E5F, 0xCE90C46E, 0x93605987, 0x4CE5ADAB, 0x06A7B185},
	{0x9F2AEDAB, 0x73D1E8EE, 0x0DC3F932, 0x610B3531, 0x115BFD99, 0xEBFDD558, 0x55C5166A, 0x08ABF7E9} } ,
	 { {0x56CD361F, 0xAEEF346C, 0x200E5594, 0x84C6FE2B, 0xD48E90E7, 0xBD132E9A, 0x729614BF, 0x010EF248},
	{0x42DFFF90, 0x403213DE, 0x242283DD, 0x37A8AF00, 0xD83086FF, 0xBD62AF7F, 0x7D9119A8, 0x178E008A} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 950 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 951 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 952 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 953 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 954 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE753BCEA, 0x0776673D, 0x9B4A19B2, 0x8D01A14C, 0x44365C64, 0xB4F571C9, 0xE2668C83, 0x0459979B},
	{0xC9D07730, 0x77F049F4, 0x7AA4B3CB, 0x30F88341, 0x0B356C3F, 0xC2A5D793, 0x0BAED316, 0x23919AE1} } ,
	 { {0x84602508, 0x5BAE7CCB, 0xB8CAE5F4, 0x5CCC8E15, 0x65E38189, 0x20185D6C, 0xE2BFFA9A, 0x06C8E722},
	{0x23E3BEAD, 0xFE57A0D1, 0x41D468B1, 0x8001CCA2, 0x16CB5457, 0xB0320CAA, 0x54594C6F, 0x15FF51EB} } ,
	0};
		static bigint_t var_k = {0x8F4A2630, 0xDC19CCDA, 0xCA781A22, 0x947B0FA6, 0xB10DA0F2, 0x23E5E318, 0x1C3B58EB, 0x073DA0E0};
		static const ecpoint_fp2 var_expected = { { {0x9D66A9AE, 0xD0216346, 0x1356AEB5, 0x5F390A12, 0xBC1EA977, 0x48551256, 0x6F8F8A5A, 0x17614D32},
	{0xCB955EAB, 0xEE4F361A, 0xB2B69C4B, 0xB29EBEFB, 0xE14C28D0, 0x6FBA7281, 0x781EB227, 0x0E6990F9} } ,
	 { {0x0CFDE9F9, 0x75A8070A, 0x4A7D3922, 0x2909843C, 0xAADA466B, 0x670EA353, 0x44C6CC86, 0x0468237D},
	{0x8A36090A, 0x57AAF55C, 0xB0DCFBF6, 0x5CC9331F, 0xE98DD964, 0xB9510F03, 0xA8767B39, 0x1DD3B519} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 955 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 956 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 957 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 958 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 959 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xF3F4E08F, 0xA0333CEC, 0x918600A9, 0xBAEB6CD7, 0xDBFD8F65, 0x6823820E, 0x14EEC61B, 0x08CE7A84},
	{0x43F092C3, 0xDB76ED67, 0xE602F8A3, 0x9D02EC90, 0xA6EBCCF9, 0x39BAFDF6, 0xC0B721BA, 0x1480D8FD} } ,
	 { {0xF2C8C3CF, 0x62738A64, 0xFD8B2A90, 0x6BA9FF87, 0xDC23233C, 0x306EE4D3, 0x67F2B728, 0x237EE141},
	{0x472461BA, 0xD1618912, 0x5C42B06C, 0xBCD20B4F, 0xA53544C9, 0x73723DB6, 0x77F7A039, 0x24879542} } ,
	0};
		static bigint_t var_k = {0x78EEDDDE, 0x4CEAEA0B, 0xA9496878, 0xE6764A5B, 0xC197E158, 0xF85BBE7F, 0xB2425DD1, 0x03CA9D33};
		static const ecpoint_fp2 var_expected = { { {0x76252CAB, 0x99411EA4, 0x8EC98064, 0x7EF1206D, 0xDD09F8A8, 0xC9AE7CDD, 0x9E738D13, 0x2148AA33},
	{0x3B9F633A, 0x037CED64, 0x799E3E0E, 0x95199EDC, 0x57A88E97, 0xE018DB6A, 0xB616473E, 0x00794304} } ,
	 { {0x13C83B06, 0xBB7313CD, 0x050D1894, 0x589771B4, 0x11E4B08D, 0xDBF0F21C, 0x52FA1824, 0x01DC1D32},
	{0xA4AE7966, 0xDE2ECDD0, 0x2070B796, 0x38C13543, 0x4FC90E79, 0x7036D8A7, 0xE344BC77, 0x11574FF5} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 960 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 961 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 962 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 963 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 964 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x33C490F6, 0xE91B0EC1, 0xE64EFB10, 0x185FA5C7, 0x4751DBFA, 0x7749F915, 0x1AEA7C30, 0x157B81BB},
	{0xBF2EA018, 0x3006F8D6, 0x913D746C, 0x416FC2C5, 0xD55D2883, 0x5BB490D0, 0x9945165F, 0x0F2700BE} } ,
	 { {0x7DC8D7A7, 0xB224909A, 0xCF58314C, 0x5BC59CCA, 0x743AD521, 0x91DEE204, 0xEDB07FE2, 0x05D30A09},
	{0xCACC3754, 0x174A9394, 0xF0073CA0, 0xBCDCCAE4, 0x332384FB, 0x4E809CC2, 0xC52BF9C3, 0x0B112A50} } ,
	0};
		static bigint_t var_k = {0xCAC064E6, 0xAEB3423B, 0x7E99A711, 0x5D45FD65, 0x9184E155, 0x361F851A, 0x872F812F, 0x1A9194CA};
		static const ecpoint_fp2 var_expected = { { {0x94350E0B, 0x48E38D71, 0xC39902DA, 0x18B2877D, 0x230FF7A4, 0x4D10D91C, 0x277128F4, 0x187EF357},
	{0x888E1C01, 0x470113FE, 0x75D3B938, 0x36449278, 0x0D529901, 0x1FB3F775, 0xE207CA49, 0x209CD24B} } ,
	 { {0x96861536, 0xFA2F86F6, 0xA7947486, 0x94254D01, 0x57349F7A, 0x3F05F4F3, 0x5257F5B2, 0x22659036},
	{0x413C20B9, 0x965072AF, 0x55228D60, 0x796AB73D, 0x7655D602, 0x1573B3DE, 0x17E7877B, 0x1D24189D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 965 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 966 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 967 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 968 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 969 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1204E708, 0xE8C66A18, 0xFCABDDFB, 0x5564A917, 0xB0125977, 0x6C91834A, 0xE9F526E9, 0x0E82D9DE},
	{0xB864547D, 0x9DF772B4, 0x9F23483F, 0xE93C3BBF, 0x9C09FAE0, 0x9CF7F70C, 0x7947D1DC, 0x02FAAF8C} } ,
	 { {0xCF5BFC43, 0x8146CE73, 0x7459D838, 0x78E96801, 0x5C0CBF8F, 0xDA6FC4B9, 0x01A31574, 0x1559E170},
	{0x3EC3C758, 0x2C1242A1, 0xF0AC7073, 0x68FF8DBA, 0x4E9E0027, 0x614F7019, 0xBA93296A, 0x0C703502} } ,
	0};
		static bigint_t var_k = {0xF23DC0E6, 0xF6A2A8DF, 0xAFA128B4, 0xF66F28B6, 0xBE136A43, 0xFE8E2106, 0x709F330D, 0x01850FA0};
		static const ecpoint_fp2 var_expected = { { {0xADB83AAE, 0xB7893409, 0xA7437A53, 0xA74E82D4, 0xDF060078, 0x02986AC3, 0x288B23D3, 0x11AA0B41},
	{0x85D98B7A, 0xF9CDF361, 0xACD9C64D, 0xAF05589D, 0x91E736F0, 0x6DCD690B, 0xF3899B02, 0x06BE87BF} } ,
	 { {0xD69C4776, 0x3C2709F7, 0xC869FC47, 0xA5FDB8FF, 0x5D5BCFA5, 0x9CCF8199, 0x0F0F4A12, 0x0F9E5E83},
	{0x606E5FC7, 0x6A076395, 0x27F8AC7B, 0x6A54855A, 0x672F9DAE, 0x1747D61E, 0xF40E5938, 0x1CF22DA7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 970 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 971 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 972 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 973 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 974 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0C6C17B0, 0x996CF6AE, 0x6EFFE25A, 0x9FCA3643, 0x47F039F3, 0x97F69FA9, 0xEC66B6E8, 0x2260F075},
	{0xDFE4944B, 0xB83B4D0A, 0xBEB0EC7B, 0x9EEE99E1, 0x155FC478, 0x5ED805A5, 0x613B664C, 0x0FD663DA} } ,
	 { {0x1981EA0F, 0x4D7C5167, 0x90A32D46, 0xAFFBAC87, 0x378E7B94, 0x4E7323D8, 0xFE28AA22, 0x0499BB3F},
	{0x401D0F56, 0xA18281A5, 0xF9A5DFEC, 0x6644D32D, 0xE813315B, 0xE43CD4CC, 0xFDE43AF2, 0x1C8E3DCD} } ,
	0};
		static bigint_t var_k = {0x9ED7AEBC, 0x2E670D08, 0xDFBE8064, 0xC0B870DA, 0x25A6781D, 0xB0A48D7F, 0xC19F89AC, 0x1AB587FE};
		static const ecpoint_fp2 var_expected = { { {0xAECBF45D, 0x58B49894, 0xC6E90023, 0xAA44B416, 0x3335EC98, 0x4BC56CB9, 0x3CB8BF37, 0x0C3DFE2E},
	{0xE18113AA, 0x4F498181, 0xFFFB3D24, 0xD36471C2, 0xDECB1397, 0x4AD12039, 0x7DF7DD09, 0x18C20096} } ,
	 { {0xA339B530, 0x84305BC0, 0xBE467FF8, 0xEB08CDEA, 0x8F656D54, 0x557CBC5D, 0xEC741ACC, 0x1B71ED72},
	{0x2A807263, 0x4B13BBD5, 0xDBCC18EB, 0x8F1EF361, 0x0C996608, 0x4790CDDF, 0xC63D0E85, 0x1AEEEC67} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 975 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 976 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 977 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 978 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 979 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB538AD60, 0x41F8E9B1, 0x9CB06AE6, 0x9E8E6713, 0xB1C3D7FF, 0xF8F3AC60, 0x788AE716, 0x1DEA9B41},
	{0xF34E74E8, 0x9674917A, 0xD80457B5, 0xEEC94DCA, 0x8773C28E, 0x34AAAF83, 0xE4B23502, 0x2207C9D9} } ,
	 { {0x83B10CE2, 0xCAE2ED94, 0x272BF594, 0x0F3F932A, 0x1E9DAD87, 0x9E915320, 0x06F4B247, 0x10563B5F},
	{0xC807DC3E, 0xBE510DD8, 0x86FDB953, 0xB92DED2F, 0xC3D1FE2B, 0x45CDF360, 0x4261CBB8, 0x1A8C6097} } ,
	0};
		static bigint_t var_k = {0xB9C49964, 0xC145629E, 0xF4C01961, 0x5CEA982F, 0xE38D4851, 0x1A2819B7, 0x90FB778B, 0x0C5A3042};
		static const ecpoint_fp2 var_expected = { { {0x010AABB2, 0x7A62576E, 0x93FB6978, 0x024B2FAD, 0x7106EC51, 0xFB01721F, 0x4F821A62, 0x0BAAF990},
	{0xFCEDAF22, 0xF1AA0064, 0xF19280BE, 0x79E24A2C, 0x9BDF6982, 0xBA9B52CB, 0x3894CB96, 0x03761448} } ,
	 { {0x1F7C58AD, 0xE4272152, 0x18773ADC, 0x62C11E3C, 0xCF82C664, 0x9CBBD715, 0xB179C709, 0x12B30E22},
	{0x55D41C62, 0xBA6E804A, 0xDAC5B35D, 0xA29AA024, 0x3CFB371A, 0xD3E5E571, 0x2F7EF29D, 0x06633F4F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 980 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 981 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 982 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 983 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 984 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x93049CCC, 0x0CAEA486, 0x98622F36, 0xA981D0FC, 0x28312FC7, 0x5C19D314, 0x84599825, 0x11BA3D94},
	{0xB6B607B1, 0xE2793741, 0x00B134C9, 0x9F3F4A2F, 0x64D6F7B9, 0x96CD1A06, 0x06BB4E7E, 0x0AA2F587} } ,
	 { {0x797DBD00, 0xE83614DC, 0xB50E82FA, 0xEB0AE809, 0xF0F2C235, 0x05CAB4F5, 0x203D3F75, 0x23AF35FF},
	{0x08209964, 0x838F70AA, 0x1C764A74, 0x8872B5CB, 0x3B8B52E9, 0x14ECCA78, 0x80A5CE4D, 0x1875D917} } ,
	0};
		static bigint_t var_k = {0x71D101A3, 0x1721E26D, 0x133B354D, 0xC3F4C323, 0x54DEB17A, 0xA7D781C0, 0xF28C4124, 0x05B9F161};
		static const ecpoint_fp2 var_expected = { { {0x1839A441, 0xFADCC721, 0x1077D306, 0x668AA15F, 0x51491B31, 0x45584316, 0x672F3AF5, 0x12B05B78},
	{0x541E10E4, 0x86ADD1E1, 0x7B03D476, 0x2984F90A, 0xBFCC491D, 0xF706DD09, 0x7D729C93, 0x09AF51CA} } ,
	 { {0x753F383F, 0x1BAD82FC, 0x84D8A92D, 0x6EB1AE83, 0xD2A0B2D2, 0x3DDDC33F, 0x82EF3602, 0x1DB3B783},
	{0xB1B3EAA5, 0xE8CB3A6B, 0x2E411B11, 0x87686FDC, 0x3C43AC1B, 0xC51B8550, 0x89C00CEB, 0x2513887E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 985 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 986 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 987 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 988 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 989 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA50A6664, 0x573F79B2, 0x8E761703, 0x6D8E2D7D, 0x738CC77B, 0xE1F4D524, 0xAA32E0AF, 0x0E08D71A},
	{0x2A4D091A, 0xCE05F9CE, 0x8C56298D, 0x4A55A125, 0x19EF04C4, 0xC6F1DBC3, 0x42CF09EB, 0x0F6B3E6F} } ,
	 { {0x8C9896EB, 0xFB604399, 0x52737DF7, 0x98461805, 0x96608B48, 0xA69C33EE, 0x004F3C22, 0x1C4DD19F},
	{0xEC2EBA51, 0x812CAD80, 0x1302800D, 0x33069844, 0x462F3B84, 0xDE26351E, 0x3D7884E3, 0x10BCD1B6} } ,
	0};
		static bigint_t var_k = {0x342F9ED2, 0xE290BE8D, 0xA2D362EE, 0x0DB77306, 0x163CDBEE, 0xD3E3849B, 0x7B8D190F, 0x05082F1A};
		static const ecpoint_fp2 var_expected = { { {0x446D5562, 0x1BF15AF1, 0x7BE73A72, 0xDF3E4160, 0x64D7FCFB, 0x58894BBC, 0x7938BA12, 0x1E3EB131},
	{0x918A727D, 0x584617AC, 0xE4741A74, 0x4308118C, 0x0A9ECD3D, 0x3DAE28ED, 0x78E94965, 0x10AC1920} } ,
	 { {0xEEC9359C, 0x4D2B59EB, 0xADAF97B2, 0xE6E474A4, 0xB463DC2D, 0x06B6AA5F, 0xFC6E4BFB, 0x0FD7973A},
	{0xEF864DB6, 0xB5EA2896, 0x1C46AE74, 0x3D920E2B, 0x65FD6FAC, 0x03D049D7, 0xEBFFE2C7, 0x16328425} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 990 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 991 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 992 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 993 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 994 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8F57429F, 0x3D192205, 0x41E32356, 0x6EA5FAF7, 0x3F590ED9, 0xD3D797BA, 0xFB9F4796, 0x232DF958},
	{0x7BD299D5, 0x21C4E5E2, 0xB13F21CD, 0x6E899CE2, 0x7E8BB3B2, 0x29EA1E74, 0x2CE4F98A, 0x22823D9E} } ,
	 { {0xEFE1D97B, 0x01B106D4, 0x9FD884A7, 0x2E686065, 0x9714F025, 0xFB4D74D2, 0xB413A753, 0x06DD2AA1},
	{0x192450C0, 0x570E723C, 0x3989A824, 0x7EDED89C, 0xB0A85462, 0x7B95B003, 0x91E53A6C, 0x182A6091} } ,
	0};
		static bigint_t var_k = {0xAD44F687, 0x5AEE3011, 0x44947038, 0x75A4511E, 0x06AD4576, 0x00A071C4, 0x41E9F9CE, 0x030C6A6F};
		static const ecpoint_fp2 var_expected = { { {0x8903D90E, 0xBED74F73, 0x680187AD, 0x9EE0D1A2, 0x8BED6038, 0x110B3D43, 0x4A140D6E, 0x12C996BC},
	{0x402C8B35, 0x52657793, 0x02BBEE78, 0x66EBBE58, 0x9C10F347, 0x3C6E4A6B, 0x9083859E, 0x0CE6551C} } ,
	 { {0xA8B46B5C, 0x1D090DF8, 0xF971F085, 0x65BEFE58, 0x553FE245, 0x003873C0, 0x8F8768E2, 0x17E67D7E},
	{0xCFA8F746, 0x60991B98, 0xD1829C15, 0xE7DCD935, 0x8125EB7C, 0x58257173, 0x92660C49, 0x224C59EF} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 995 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 996 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 997 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 998 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 999 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x85DA61EB, 0x59DDE16D, 0xC17AB3DE, 0x333AE423, 0x5BBBFA84, 0xBBD54DC3, 0xF727224A, 0x1111A402},
	{0xCBA07B72, 0xD74BC40A, 0x48B9FDBD, 0x65DE205B, 0x99014EAD, 0xB1D3715B, 0xBECD0502, 0x03C3D110} } ,
	 { {0x0FA370D3, 0x04EA4F10, 0xB2375897, 0xDCD226E5, 0xD4900B6D, 0xC87B380F, 0x2155DFA2, 0x0A0BB1DA},
	{0xE93ED2CC, 0x8DD7F77D, 0xD9CF3DFB, 0xE522C4DF, 0x7620AF95, 0x28256C1F, 0x2815D823, 0x23648E38} } ,
	0};
		static bigint_t var_k = {0xCB7D9A16, 0xBC65EF1D, 0xDF39C088, 0x709CB6FD, 0x41681DBE, 0xF9ED7DC0, 0x9986ADE3, 0x0DE7210D};
		static const ecpoint_fp2 var_expected = { { {0xA84608F0, 0x9AFF1A2A, 0x02BBC84A, 0xA197C58C, 0xF8AD8BB3, 0x952D5CF3, 0x760137C7, 0x2091E320},
	{0xE02645AC, 0x3ABAE749, 0x0875DBDC, 0x6EC967B5, 0x38A119DB, 0x63C36B96, 0xB2084FC6, 0x09E06F0C} } ,
	 { {0x3B9941B3, 0x931E73FE, 0x5226512F, 0x6F03917A, 0xFE7B2D50, 0x74A2488E, 0xFCA047A5, 0x1412F114},
	{0xEFA1EF6E, 0x608D3B03, 0xCE8A3C55, 0xABEB2866, 0x77E68798, 0x347F77EE, 0x31627D7B, 0x18D53B56} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1000 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1001 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1002 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1003 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1004 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD45CBBA8, 0xA7B3F95D, 0xB124DF11, 0xE00F9CD7, 0xEBF295AA, 0xFDAAA3CA, 0x9C8EC651, 0x12046DE8},
	{0xE2F72EBA, 0xE4BC76F4, 0x4A7F04B6, 0xE3F6BFE2, 0xE10319EB, 0x113DDAB2, 0x9A1BDB0F, 0x18ECB21A} } ,
	 { {0x4EDAD62D, 0x012072ED, 0x1495E1BF, 0xE9CE7227, 0xAEE7F092, 0xE4352F08, 0x7F190898, 0x099A7CC0},
	{0x7BEB20AC, 0x7594710E, 0x88BBE93B, 0xADB49CA8, 0x8D265DAF, 0x31419D45, 0x4988E5CD, 0x23C69D25} } ,
	0};
		static bigint_t var_k = {0xB91BF5AE, 0x210206CA, 0x988423E9, 0x340AFF4E, 0x24A6F258, 0xB6BBC805, 0x189D0E65, 0x0B4A14A6};
		static const ecpoint_fp2 var_expected = { { {0x10612CA9, 0x871C41FA, 0x60CC9071, 0x95F4437A, 0x407137DE, 0x559ECEA1, 0x90A8A53A, 0x0517462D},
	{0x0FF5F556, 0xDA87041E, 0x81F80DDA, 0xE917B71F, 0x650C9239, 0x624F2E00, 0x4E2DBCC7, 0x03FCE54A} } ,
	 { {0xA6B0EBBD, 0xEF81065C, 0x3789C754, 0x413EE959, 0x5966C747, 0x503E3983, 0xF93C864C, 0x01793ACC},
	{0x82D4494D, 0x266EB7D2, 0xF75F324F, 0xAFBF9C0A, 0xF7D4F897, 0xD6C39256, 0x85DBC3B1, 0x16917348} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1005 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1006 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1007 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1008 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1009 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBCA1DB66, 0xC8D2DEE3, 0xAD3F0576, 0x5DA0ED38, 0x2DCFD470, 0x5DAADE0F, 0x7328390B, 0x1AFBEF86},
	{0xD13F50E1, 0xA0DB9E02, 0xF06F2DC3, 0x9F2FBAC6, 0x82DCCCE9, 0xA3764BAA, 0x62E94CC9, 0x1882F4AD} } ,
	 { {0x36F0CA69, 0x77B2533A, 0xC0BB59E7, 0x752DECEB, 0xD544D8CC, 0x8314F197, 0x5F783F5D, 0x17D97C8C},
	{0x4C24C638, 0x1BDC2E3B, 0xDDA3A16E, 0xB8420569, 0xE83F4E7A, 0xF6563FC7, 0x49DA0C0A, 0x09203FF0} } ,
	0};
		static bigint_t var_k = {0xE604A61B, 0x75C71362, 0xD487232F, 0xE1DC9891, 0x4B70B6FB, 0x85B4D7D3, 0x5205790A, 0x227578E5};
		static const ecpoint_fp2 var_expected = { { {0x7F98DC06, 0x810DC4BF, 0x95CABF55, 0x8EBF44C1, 0xA13591FC, 0xDCB91C58, 0xB1E7EFFF, 0x17AB5C6A},
	{0x08F8B7F3, 0x0861484E, 0x5D39C1DA, 0x73B53A40, 0x26867833, 0x218448FC, 0x3963E917, 0x075020B6} } ,
	 { {0x3A6A7EE1, 0x0775034E, 0xD555549F, 0x3E926148, 0x06E3624D, 0x8E8FB846, 0x045A0233, 0x12F491F4},
	{0x373333A3, 0xCBE16800, 0xEAA23A45, 0x3CE56D2C, 0xF6A3683D, 0xF4E5AEAC, 0xAB2DB72F, 0x0F29DD37} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1010 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1011 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1012 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1013 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1014 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7255B1F1, 0xFA22726D, 0x6700D925, 0x9B31DCFA, 0x8CED59D3, 0xF0198A67, 0xA83A6A32, 0x115388DD},
	{0x6A903B52, 0xF1586B98, 0x7691EA64, 0x4EA47695, 0x3DF8A5F1, 0x0B80FE63, 0x7C2452F4, 0x0DFE7B9E} } ,
	 { {0x07BF175C, 0xE0DE52A1, 0x88FE735D, 0xAC1EDCD3, 0xBFBBDD42, 0x0C021137, 0xD0FC4887, 0x01129C87},
	{0x9F014CA8, 0x37728505, 0x5725A180, 0x59B57D51, 0x3355AB88, 0x9ADE45CA, 0x91FECA99, 0x02D66F1D} } ,
	0};
		static bigint_t var_k = {0xFE947707, 0xB7B5EBF8, 0x38FAB1F5, 0xACB9D780, 0x957117A2, 0xF5A3CFBC, 0x5D84701D, 0x21457413};
		static const ecpoint_fp2 var_expected = { { {0x004A9164, 0x1B03BCC5, 0x2A29F73C, 0xA3BEF2F2, 0x7D9DD053, 0xDA33E6AC, 0x45CB2924, 0x095DA934},
	{0xB6251D71, 0xFE551D16, 0x48ABD5EE, 0xB2FC640D, 0x8B815471, 0xE2A58658, 0xB2D7CE5F, 0x0A66EC22} } ,
	 { {0x4C223A59, 0xEDFF6D57, 0xBEB58F64, 0x0D7DFB07, 0xBAF3193F, 0xCBC3732F, 0xE19DBAC6, 0x1C1CE065},
	{0xE27E2F89, 0x365A0654, 0x03F13E85, 0x8BF0467C, 0x26CDFC94, 0xAFEC9C57, 0x1301CE37, 0x24E5008B} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1015 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1016 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1017 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1018 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1019 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x26CB433F, 0x6AE28B7C, 0x63E3195B, 0x58A8EFC1, 0x6E5F1639, 0xE31F1B39, 0x4AF38784, 0x05A56E77},
	{0x62670503, 0xC07445DF, 0x75549BDD, 0x1A2A5DA7, 0x97351FB0, 0x0685E73B, 0xB717BA41, 0x133C2811} } ,
	 { {0xBBDD1739, 0xC93B1F06, 0xA59CFBE6, 0xA329979F, 0xEA2F2595, 0x057D9FF6, 0x08E15583, 0x04BABCCB},
	{0xDFD7DC88, 0xDF8C162A, 0x202D8741, 0x54BF9E6C, 0x0F942DF6, 0x2924F257, 0x28A13B03, 0x1D1E1709} } ,
	0};
		static bigint_t var_k = {0xEE6CE613, 0xB4E09961, 0xA88566AB, 0xAFEA961D, 0x1DC6228B, 0xEB31BA81, 0x4E207B5B, 0x1C4540BB};
		static const ecpoint_fp2 var_expected = { { {0x0B75DAB0, 0x38000949, 0xAC9A947F, 0x343D5F19, 0x8B1BA4AB, 0xD078CF70, 0x4EF69D6B, 0x0036D3BB},
	{0x9DF8DC87, 0x683E027F, 0x88F03C54, 0x52F1709C, 0x22B778C5, 0xA8ACFC20, 0xD453E16B, 0x180CC0CB} } ,
	 { {0x3B923807, 0x00123F73, 0x717DF481, 0xEB5E58F3, 0xD31F6384, 0xA2489996, 0x269857B9, 0x17A8AE02},
	{0x48268922, 0x410E16FE, 0x288977FC, 0x2D515704, 0x70F8FE05, 0xFCF679D1, 0x225D1C1D, 0x1A58A7BC} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1020 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1021 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1022 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1023 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1024 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA8E2016D, 0x4D3BCE14, 0xEED57B0D, 0x08C787C4, 0x5B6EA297, 0x763BE4CF, 0x956F090C, 0x2415314A},
	{0x713D1157, 0x013D8A90, 0x6BB5A809, 0xE2EDA2F0, 0x8D8ED6D6, 0x46AC7712, 0x1CA2876A, 0x01667E21} } ,
	 { {0xD41317EA, 0x847FB077, 0x999AE27C, 0xA7CB4286, 0x033FA0E8, 0x1886D6D5, 0x14D33BCD, 0x0F2524C5},
	{0x93B606F1, 0x9E1FF479, 0x21B0BE05, 0x531EFE9F, 0xEBF62F65, 0x59E532AC, 0x5E1EAE6D, 0x0D264B76} } ,
	0};
		static bigint_t var_k = {0xE3423D60, 0x2E81CCF4, 0x4B17183F, 0x84BE9293, 0x41CB4CA8, 0x1719CA0D, 0xF96E2F54, 0x1CFB3A07};
		static const ecpoint_fp2 var_expected = { { {0x680CFE26, 0x15EE1571, 0x016DBE08, 0xCB00A060, 0x605FA5CF, 0xDB70C6D6, 0x98DCE622, 0x0D432213},
	{0xD935BC84, 0x8995FF86, 0x30E298E0, 0x8A515D96, 0xD6511DA6, 0xC4EC81DA, 0xF7CC2704, 0x11CB2810} } ,
	 { {0x9458A178, 0x1B15922F, 0xCF894016, 0x9BA1F15C, 0x924068D1, 0x54A62DA9, 0x18007597, 0x123FFE17},
	{0x7748D475, 0xBFC29C32, 0x5D948196, 0x238A61B3, 0x7B801FC9, 0x4A5D8CF5, 0xC8CAD200, 0x03A89693} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 1025 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 1026 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 1027 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 1028 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 1029 infinity");
	}
	{
		static const bigint_t var_t = {0x33333383, 0x8A333333, 0x00000052, 0x97F10000, 0x66666689, 0xDADBABE6, 0xD99999A0, 0x026172EF};
		static ecpoint_fp2 var_expected = { { {0xDBDD83CB, 0x9B84D0D8, 0xBD52DC6A, 0x1ADF42C7, 0x3351251D, 0x3C866AF8, 0x6FE5F4AF, 0x0B8E6D28},
	{0x00BDFBE9, 0x6DE0FDD2, 0xCB0BEE34, 0x79ACB053, 0xF8584BDF, 0x5F764DA4, 0xC4675AD2, 0x08DCFC53} } ,
	 { {0xA7A38F3B, 0x79380AC4, 0xC7E89FA4, 0xADA8C5D5, 0x77919903, 0x546C9A94, 0xBF32352C, 0x02D5AC2B},
	{0x78F258BA, 0xFA3BD0DE, 0x626A52E2, 0xB304848E, 0xBAA3A1E4, 0x1ACC71D4, 0x45399B80, 0x1BA30AA4} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5747 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5748 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5749 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5750 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5751 infinity");
	}
	{
		static const bigint_t var_t = {0x01B99804, 0x157744FE, 0xBD79E815, 0x4E9C4B1A, 0x5081B8B1, 0xB2F5AA51, 0xB17EDB82, 0x031FCA57};
		static ecpoint_fp2 var_expected = { { {0xFC63D860, 0x8F67A53C, 0xB6913F05, 0xFECBAD73, 0x1F5C09F0, 0x9E75EDEB, 0xE0B1C03F, 0x10C391BE},
	{0x7899DCCB, 0x39466A39, 0xC74D126A, 0xAFABA209, 0x0661BF3E, 0x720646D1, 0xA7839A1D, 0x208100E7} } ,
	 { {0xD2C65CF0, 0x1DADA099, 0x21BE0693, 0x0020B856, 0x9AE4578A, 0xBE64B35F, 0x623D797B, 0x02A914BF},
	{0x6BCC9FDD, 0x5459900F, 0xF2CCFF30, 0x34791879, 0x837502E5, 0x075A0784, 0x3D074496, 0x1A399EE4} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5752 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5753 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5754 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5755 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5756 infinity");
	}
	{
		static const bigint_t var_t = {0xCA8D11D3, 0x7D0B5B79, 0x7C8467D5, 0x8D7A437A, 0xC811129D, 0x3787F398, 0x52D7A614, 0x06BB1DBF};
		static ecpoint_fp2 var_expected = { { {0x364C41C4, 0x094EF07D, 0xA97042B3, 0x26B7BB46, 0x8FD7363D, 0x0FD80B86, 0xF26E7FCF, 0x0E227B6C},
	{0xCE88CA51, 0x0444E8AD, 0xC8494C77, 0xB535E6F9, 0x2A8795FB, 0x48AA8DD4, 0x4F050CAE, 0x2346EAAD} } ,
	 { {0x811C271E, 0x280A944F, 0xB778D5F3, 0x25E4768D, 0xD5886367, 0xFAF0E7C3, 0x867254B6, 0x2122A4FA},
	{0x25C37132, 0x43418A32, 0xD73E9C7A, 0xB6387E0B, 0x0460CDA2, 0xCB8527AF, 0x3AD135E4, 0x0DCC9323} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5757 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5758 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5759 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5760 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5761 infinity");
	}
	{
		static const bigint_t var_t = {0x13A1C392, 0x61E25623, 0xDEA74A19, 0x9FD71A27, 0x1099E521, 0x9959908E, 0x1CD54579, 0x10FE1389};
		static ecpoint_fp2 var_expected = { { {0xB971859D, 0x0DBE1741, 0x1733F6A6, 0x0CBEB5A9, 0x7116B624, 0x54333068, 0x1E7807F8, 0x231C2404},
	{0x383B9CD2, 0xB5D840E7, 0x1D47527C, 0xC1F18D88, 0xC46228F8, 0x99AB0681, 0x8B2B1E3B, 0x1FBCAEBC} } ,
	 { {0x2D7CB386, 0xAB247BA7, 0xC341EF04, 0x91923DA5, 0x923DB305, 0x93CD2F10, 0x1C5D2D56, 0x0C778A2E},
	{0xEEE012EE, 0x6B1EFDBA, 0x6287D559, 0xDB218067, 0x4E137459, 0x7C394571, 0x8C4DD70F, 0x07BFA7D0} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5762 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5763 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5764 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5765 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5766 infinity");
	}
	{
		static const bigint_t var_t = {0xDD7477A5, 0x77E62481, 0x90C465D3, 0x3B465B93, 0x9DCD77B4, 0x20DD6FFF, 0x43F40B0C, 0x1C7FF4E8};
		static ecpoint_fp2 var_expected = { { {0x5ED73798, 0x3B06F733, 0xC2D1C207, 0xA0F850AB, 0x14DF4FF7, 0x875C5D94, 0xAAE31D3F, 0x013EE7AF},
	{0xD691540E, 0x1CC43EF9, 0xECBB53F9, 0xFE6FEA4A, 0xDAC22988, 0x7B69BAB6, 0x0B60C246, 0x14F6F459} } ,
	 { {0x48BC9FDC, 0xF3318396, 0xB3B10543, 0x9B4BC137, 0xD47785ED, 0x988C08AD, 0x9ACF8061, 0x149442CD},
	{0xA806396C, 0x2D196B2A, 0xDCFFE449, 0xD7E3E829, 0xBB1C6CCC, 0xE88D91DE, 0xD161A84B, 0x1EFF9A80} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5767 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5768 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5769 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5770 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5771 infinity");
	}
	{
		static const bigint_t var_t = {0xEEB25AD3, 0x11B53BE3, 0xAA54AE61, 0xB6DFC86F, 0x00E96DB7, 0xBC78AC91, 0x108B307C, 0x1DCA089B};
		static ecpoint_fp2 var_expected = { { {0x6DFA6A4C, 0x6A9E60AC, 0xC807CD94, 0x8045BE51, 0xA82E6BB4, 0x13B8A64C, 0xAD355D98, 0x23F4AF39},
	{0xC912B664, 0x0B0F43B1, 0x5D380089, 0x076CAB0D, 0xC195F927, 0x69625DF1, 0x018D379D, 0x237292F0} } ,
	 { {0x63C00E97, 0x0ACA8B32, 0xB341B9BE, 0xF8D06F97, 0x70AA5AB0, 0x26F48A2B, 0x71F43CA9, 0x0A60313B},
	{0x857C0796, 0x83124F39, 0xF1EFDE6A, 0x320619DC, 0xF26E2A2C, 0x38622A4F, 0xDAD6B64E, 0x0E2CC704} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5772 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5773 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5774 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5775 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5776 infinity");
	}
	{
		static const bigint_t var_t = {0xD90D74DF, 0xB8A3B6BC, 0x2C5AED19, 0xC2136908, 0x12613270, 0x7F45D7E8, 0xBF5CF85B, 0x038A6622};
		static ecpoint_fp2 var_expected = { { {0x5ECEE584, 0x9F296903, 0x80FF1A97, 0xEC8F54F1, 0x5B22A275, 0x79F1F44B, 0xB97CB5F6, 0x1C49AA03},
	{0x4AFE76AA, 0x2C77BAF1, 0xC712ADBD, 0xBC822C9E, 0x15F3A191, 0x72FB1AEB, 0xC1D0DD45, 0x17FBFECA} } ,
	 { {0x15784F8E, 0x1CB5F4E5, 0x5FE256E2, 0xB09D7D88, 0x9DD4B5CB, 0xE3B44A7D, 0x730EE64C, 0x033EC241},
	{0x2288FDC2, 0xB8FE57AE, 0xBB50A212, 0xC9D3FBFD, 0xF063B8D9, 0x327D5967, 0x31880534, 0x23E5A23D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5777 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5778 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5779 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5780 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5781 infinity");
	}
	{
		static const bigint_t var_t = {0x50D51604, 0x4D2D8FB0, 0x7374EA59, 0x1323F3E0, 0xBA3B1E6E, 0xBB7A8138, 0x837FBE06, 0x036EC63B};
		static ecpoint_fp2 var_expected = { { {0xA8B975A2, 0x337AAE17, 0xDCBF339A, 0x6CC47967, 0x855B9A24, 0x27A12A4F, 0x879F9CAC, 0x107B78F8},
	{0xEFD273CF, 0xDC538C29, 0x7D5AE36F, 0xF0C7BC82, 0x96D7DB42, 0xB0DEAD15, 0x49AC4520, 0x0DF88687} } ,
	 { {0xBF05D573, 0xCC7B5438, 0x936B41D7, 0xE939F3FB, 0x158100BB, 0x1E66CDA4, 0xDC795B53, 0x03CA5481},
	{0x23EAEB2D, 0x9C522206, 0x68969F15, 0x0FF83436, 0xB58DDB47, 0xF70C94D7, 0xF4810D65, 0x020FC443} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5782 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5783 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5784 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5785 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5786 infinity");
	}
	{
		static const bigint_t var_t = {0x4B95FB1F, 0x9E2C0A1B, 0x012A058A, 0x3085058A, 0x71D04467, 0x9752C0A6, 0x4D236801, 0x0F22EA07};
		static ecpoint_fp2 var_expected = { { {0x0A0EAE79, 0x92969A66, 0x926AD7AD, 0x4C1BDCB4, 0xF39841AB, 0xED851FED, 0x4F9D4EB4, 0x1CEB8366},
	{0x3F4FCA36, 0xC6AE5B44, 0xD0EE98C8, 0x2AB5197F, 0x78EBC17E, 0x5A42711F, 0xE8515187, 0x1D23A968} } ,
	 { {0xA3F4FE5C, 0xD1ABAD26, 0xD663F939, 0x2B40B7F3, 0x12AA9007, 0x48730181, 0x38667801, 0x1CA1A8A9},
	{0xD349E589, 0x2123CC65, 0xEC9C4C87, 0x1FBA00C6, 0x2971AA7D, 0x1ACB81BE, 0x055EA4FB, 0x2339032B} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5787 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5788 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5789 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5790 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5791 infinity");
	}
	{
		static const bigint_t var_t = {0x6A996948, 0xC12D25A8, 0x06EB8345, 0xBFD3CEE0, 0xBED0B9E6, 0x0401699F, 0xAFB2D4F2, 0x178BF7AB};
		static ecpoint_fp2 var_expected = { { {0xED3AC393, 0x09E6ABB4, 0xD7996E38, 0x03B660BE, 0xFC474345, 0x6C070A86, 0xAEB1406E, 0x0F932B83},
	{0xCE9D43ED, 0x8CB8CA3D, 0xFFDC278E, 0x4751FA74, 0x451D7DF7, 0x5CB4E557, 0x170E4A02, 0x0AC741A9} } ,
	 { {0xF7582FA0, 0x4B0D85AF, 0x8CC9BB08, 0x8183A9B1, 0xE4269C28, 0x10D05911, 0x92B30E89, 0x21862A46},
	{0x333FE6AC, 0xAE0DE33E, 0x43A7FD8C, 0x32134243, 0x1AE43D7A, 0x544ACDFC, 0xAE56F761, 0x07D463AE} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5792 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5793 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5794 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5795 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5796 infinity");
	}
	{
		static const bigint_t var_t = {0xF15FB649, 0x10281867, 0x2EBD7D03, 0x0CEE5A1D, 0x1539D2A5, 0x78CDF669, 0x13BD2F09, 0x0A5BB1A0};
		static ecpoint_fp2 var_expected = { { {0x4A6097A6, 0xCB0A8AAF, 0x1BD20064, 0x27D1BC55, 0x7CC95218, 0x4C3B36CD, 0xE99E0CD8, 0x0AB8805F},
	{0x305CCE6A, 0x67D3833B, 0x133D7F42, 0xC7AD411D, 0x3A8E1432, 0x953CE30B, 0xFBB379C3, 0x1F3C6504} } ,
	 { {0xC2F763B0, 0x9DA97C7A, 0x7005EB55, 0x7CC97748, 0x2C41D30D, 0x62082674, 0x27CAA0B0, 0x1853A186},
	{0x9AB023AC, 0x538C2105, 0x0E844817, 0x4A1FF38B, 0x5DF66398, 0x8832CE3A, 0x5740E92E, 0x1FF359D1} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5797 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5798 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5799 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5800 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5801 infinity");
	}
	{
		static const bigint_t var_t = {0x8BAB6B92, 0xE63980C6, 0x1999931F, 0xCB16A6EA, 0x02947BC3, 0xBB89F884, 0xA0322F9D, 0x204EAC1F};
		static ecpoint_fp2 var_expected = { { {0x0F89A081, 0xC06DD6BC, 0xB629AF59, 0x95A8B5AD, 0x1F25385D, 0xA96098F4, 0xD3866E7F, 0x16689AED},
	{0x3EFA7C47, 0x87CC912F, 0xDA19BE40, 0x0E8995A9, 0x7E4F9E7C, 0xF87E800C, 0xCD71E4E5, 0x12182D51} } ,
	 { {0x52183C4F, 0xD9386394, 0xC4674AAF, 0x4F07483D, 0x34C2D606, 0x6EFD081F, 0x6C9EAF5B, 0x08D2AB16},
	{0x45D99193, 0x55B0C8B6, 0x084F09F8, 0xEE9666D0, 0x62D16172, 0xC3AD52C7, 0xB22478FC, 0x215E6F3A} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5802 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5803 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5804 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5805 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5806 infinity");
	}
	{
		static const bigint_t var_t = {0x0BD056FB, 0xDFF67F64, 0x33CD124B, 0x4EE2D413, 0x23BF9CE6, 0xE6FB1768, 0x8098E328, 0x23B8B4C4};
		static ecpoint_fp2 var_expected = { { {0x2BD85DCF, 0x3A35C1C8, 0xA874246F, 0x795BEF48, 0xFE52D4A8, 0x9BEBF0CA, 0xBDAB210E, 0x000CE395},
	{0xE0809C9B, 0x906A1C76, 0xE7D5FD64, 0x824FFDFF, 0xB0604A62, 0x5E661019, 0x942167DE, 0x0F174089} } ,
	 { {0xF196E6BC, 0x11F5EE65, 0xD753BAE2, 0x8B2E18C6, 0x6BA897A0, 0x1BD9DB55, 0x1914DBB0, 0x1E854AA0},
	{0xE1025091, 0x82080BAF, 0x5716BDA1, 0xFAC83A8F, 0xABF2C8CE, 0xEA5ED168, 0x7E87D539, 0x1AA79E20} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5807 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5808 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5809 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5810 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5811 infinity");
	}
	{
		static const bigint_t var_t = {0x377C51A3, 0x9B544F06, 0xAA5D420D, 0x4E4C67A4, 0xFF1D4E7E, 0x01B1CD2E, 0xB762C361, 0x2082A46F};
		static ecpoint_fp2 var_expected = { { {0x070B8115, 0xF2BB63A6, 0x2D198539, 0x09841A5D, 0xDB0577B3, 0xBA6B1122, 0x9216A4B9, 0x075A3E03},
	{0x959CEE1B, 0xCBACF19F, 0xCAAE1EE5, 0xEFA2EC12, 0x27A0B974, 0x9E09E20F, 0x5B4F625C, 0x22B21419} } ,
	 { {0x0CC18AD4, 0xBA321BB6, 0x16E1C47D, 0x23E341D4, 0x942BEA9D, 0xD165B5E9, 0xCBAF6CF1, 0x08707D2B},
	{0xF3FE2A29, 0x32FF4A79, 0xC6B45E85, 0x46FB5598, 0x2E2E0563, 0x336E08D6, 0x1A4F14A0, 0x1D253497} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5812 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5813 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5814 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5815 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5816 infinity");
	}
	{
		static const bigint_t var_t = {0xECA27A2D, 0xF70AB106, 0x45567F5E, 0xC47ACC3A, 0xD03E3F4E, 0x9E9EEFCD, 0x3850C7AF, 0x0D75678F};
		static ecpoint_fp2 var_expected = { { {0x5F3975C8, 0xC66011E0, 0xC39D1D87, 0x409A0EAF, 0xC951BEF0, 0x3E211D6D, 0xFC62026F, 0x23DA568D},
	{0x89CA9686, 0x598A0954, 0xFE714FFA, 0xB70089F9, 0xC6A613D7, 0x710EF3AE, 0x705AB674, 0x157B5B4A} } ,
	 { {0x242FF32A, 0x2131516A, 0x9A5CC0E7, 0x66723E20, 0xA853371F, 0xEC0BCFBC, 0xB5FADBD2, 0x231E9461},
	{0x8400A3F7, 0x97E75CFD, 0xC7C82196, 0xD60273C6, 0xC21F98FB, 0x5450F9EC, 0x8DC2155E, 0x0AB44B4D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5817 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5818 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5819 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5820 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5821 infinity");
	}
	{
		static const bigint_t var_t = {0x3F0F1AB4, 0x94185DEF, 0x86CB69DD, 0xE33FEC66, 0xCF4371C8, 0xF56382DC, 0x288F73CB, 0x094FE3CD};
		static ecpoint_fp2 var_expected = { { {0x2B8E9E54, 0xD6AAE2C6, 0x6B174CEE, 0x4B5868AA, 0xFA842983, 0x636758CD, 0xA4BD95D1, 0x1F7F2B02},
	{0xB10B0D95, 0x1098E2B3, 0x09CC46AA, 0x1590D33F, 0x4ECD20B8, 0x45D08303, 0x0CDC5DC3, 0x0CE8125E} } ,
	 { {0xF87B04CC, 0x11654A72, 0x29D41F88, 0x3AD22CFB, 0x1A993CAC, 0x4711ECC8, 0x6A88B0A9, 0x01453506},
	{0x3E03356B, 0x51BA84DC, 0x83D6B7B4, 0x56776A0E, 0x5A8B0C36, 0x35E7FE13, 0x4D456B17, 0x22B44D81} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5822 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5823 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5824 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5825 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5826 infinity");
	}
	{
		static const bigint_t var_t = {0x74DC5C0E, 0x61538321, 0xB6C39E56, 0xD1A417E6, 0xEB6783AC, 0x4823ABD6, 0x8FC37A11, 0x0F073D4F};
		static ecpoint_fp2 var_expected = { { {0xF22734C1, 0x68CCBDCE, 0x5191EC9A, 0xF7946DA6, 0xDBBF574E, 0x5C443BE8, 0x99B2A9D6, 0x12295B29},
	{0x65A356D4, 0x5BAA983D, 0x543E736C, 0xFF313E48, 0x3A7470AC, 0x2E875201, 0xDF1C0783, 0x1B0A570D} } ,
	 { {0x5F37DE14, 0x7ED385DA, 0x85BC2191, 0xF13A4206, 0x4B17EC34, 0xDB3F4493, 0xEEDE0080, 0x0757AC2B},
	{0x559BC871, 0x6638D2B4, 0xAACCC15E, 0xB5794B58, 0x01174315, 0x4BE1ECD8, 0x0EBCFB3A, 0x1E6F24B3} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5827 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5828 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5829 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5830 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5831 infinity");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static ecpoint_fp2 var_a = { { {0x5514A659, 0x53997E0A, 0x8A2D2C15, 0xFBD883E7, 0x07E66B03},
	{0x9BC7EDBD, 0xB799101C, 0x47ADE4C1, 0xA8BEA88E, 0x1FAF17FF} } ,
	 { {0xD371BF08, 0x1DD01DA4, 0xD886DB25, 0xA04DE7C2, 0x177CEC95},
	{0x6D80740E, 0x907D8E47, 0x07B86C36, 0xDB1B182A, 0x08C83A7A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4982 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4983 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4984 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4985 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4986 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4987 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4988 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4989 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 4990 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 4991 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3BA5BC2A, 0x5334B160, 0xD1946D21, 0xC557D1C3, 0x12EA4E11},
	{0xA022C03E, 0x0BBE4527, 0x585DA5B2, 0x905CDEE2, 0x202D2A18} } ,
	 { {0xDC6C6625, 0x7BF4F3DB, 0x09085052, 0x5AADB64D, 0x0D1EBEE8},
	{0x65237038, 0x6D2D2F01, 0x2C98701F, 0x86719FDF, 0x1383E0E7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 4992 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 4993 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 4994 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 4995 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 4996 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 4997 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 4998 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 4999 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5000 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5001 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC950BC36, 0xBD2F84C2, 0xBA7E3562, 0xDD9BB693, 0x18A66B14},
	{0x03AD1329, 0xAB96128F, 0xBE4383BC, 0xDD62B883, 0x048ECE5D} } ,
	 { {0x43E58949, 0x9B0C1595, 0x08B32AF5, 0xF6E4EB3D, 0x12FE70F2},
	{0x9B866DE0, 0x72EE4571, 0x4F79388C, 0xAC77D785, 0x0A9C2DF3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5002 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5003 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5004 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5005 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5006 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5007 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5008 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5009 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5010 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5011 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xABE37A2D, 0x53584DE5, 0xAC10CF38, 0x5E97C070, 0x14AA5B0C},
	{0xCDAE87BC, 0x5D6B296A, 0x01354151, 0x33BFA5C3, 0x1E998205} } ,
	 { {0x4E0312FB, 0x2E8337EF, 0x6236A599, 0x157C8AFE, 0x041E3CBF},
	{0x173BAE0C, 0xFD9C9873, 0xF883B6AF, 0x62B9A709, 0x0D8EE9EA} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5012 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5013 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5014 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5015 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5016 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5017 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5018 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5019 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5020 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5021 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0D272546, 0x8412A61C, 0xF51C415F, 0xC419E302, 0x1FB3AE0F},
	{0x8162BB26, 0xA1B14121, 0x532B4FD8, 0x5DB8A73D, 0x16D4CBFF} } ,
	 { {0x8DED315E, 0x143BC4BA, 0x5C330517, 0xC4E6CBFA, 0x1E9AD9B4},
	{0x5C238E94, 0x485A83E1, 0x9BA8A089, 0x19E5F9EF, 0x13DECCC0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5022 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5023 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5024 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5025 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5026 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5027 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5028 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5029 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5030 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5031 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE432AFAE, 0x1C64F94C, 0x8AACD575, 0xA895B314, 0x1C9CC955},
	{0x6214E9D0, 0xED83BD66, 0xE788BA77, 0xFD7257B6, 0x0C4F925B} } ,
	 { {0xF84DEDDD, 0x691960B9, 0x38828865, 0x8BD43C05, 0x15E5C721},
	{0x42A8B07A, 0xFE257FAA, 0x536F5D54, 0xCF3EB42E, 0x13125D54} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5032 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5033 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5034 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5035 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5036 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5037 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5038 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5039 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5040 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5041 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x9016C761, 0xEEB4C4E5, 0xBE155B44, 0x76F7A017, 0x0D68EE03},
	{0x9AF1D5F2, 0xDED68AB1, 0x39E5D540, 0x50E5325D, 0x0809C590} } ,
	 { {0xC717C95E, 0xBF0A9EBC, 0xF8E08451, 0x29BD5B28, 0x16B71D60},
	{0xB33D648A, 0xF3361DA9, 0xECF3C0A5, 0x8E59ADB4, 0x13F542F5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5042 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5043 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5044 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5045 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5046 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5047 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5048 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5049 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5050 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5051 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x78C77D09, 0xBA09B349, 0xC056ECDF, 0xBB3B7589, 0x15E34155},
	{0xA1A65689, 0x17EB655F, 0x25378CBA, 0xFB81F3CC, 0x0E7AAE66} } ,
	 { {0x78D28061, 0x7ABC5914, 0xA6E05E80, 0xBE81810B, 0x1670722C},
	{0xE9CD1B45, 0xC31F609A, 0xE7D94F50, 0xB27BC656, 0x0759DCA4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5052 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5053 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5054 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5055 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5056 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5057 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5058 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5059 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5060 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5061 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x003A173E, 0xDE824629, 0xCD795D75, 0x4B6E6179, 0x228D59AA},
	{0xE238193C, 0xABF62482, 0x6BD5839D, 0x5DA663DA, 0x0FF56085} } ,
	 { {0x3433DAA6, 0xBB672D5F, 0xAD585F9B, 0x8F44AD13, 0x20C435D4},
	{0x0B667720, 0xFB391C0A, 0xF610241B, 0xB83EA5FC, 0x20B2CCC7} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5062 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5063 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5064 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5065 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5066 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5067 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5068 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5069 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5070 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5071 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC6D6FA69, 0x603E5045, 0x838D3197, 0x03860E21, 0x06B1CA7E},
	{0xD67BD482, 0xFC53C702, 0x2BA5BCB1, 0x9A525672, 0x10ED03AC} } ,
	 { {0xAF2119F0, 0xC65ED87C, 0x15FC7564, 0xD149BD6B, 0x0D6F40F3},
	{0xAF687520, 0xE7606E00, 0xD070D15F, 0x218B2EBF, 0x018174D0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5072 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5073 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5074 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5075 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5076 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5077 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5078 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5079 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5080 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5081 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBB1B26B1, 0x061FE05A, 0x7F8493EF, 0x11AA9E23, 0x10DBD175},
	{0x22D00BBA, 0x100AF397, 0x6B071734, 0x375EF63B, 0x0353A0F0} } ,
	 { {0x5E18080D, 0x5FDEA603, 0x67D6CDF1, 0xBE0CF2EA, 0x0FC0890A},
	{0x91A00A18, 0x241FCF0B, 0x393BDAB8, 0x74EEC96D, 0x055121D3} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5082 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5083 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5084 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5085 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5086 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5087 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5088 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5089 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5090 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5091 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD583D65F, 0x04C17E5E, 0x79E7850D, 0x1B50CF84, 0x1843C051},
	{0xF7F2D593, 0x06738A1A, 0xD98154E9, 0x75FCDF05, 0x0F4E44AB} } ,
	 { {0x68328BB3, 0x5A13DAD6, 0x54325AD6, 0xF7A39E34, 0x0331E41E},
	{0x05D897F6, 0xD6B7A2A9, 0x168ED204, 0x12AE7B66, 0x16E614BF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5092 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5093 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5094 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5095 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5096 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5097 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5098 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5099 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5100 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5101 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0DC6121C, 0xBFE8E3F0, 0x64143169, 0x55746F44, 0x1BC78262},
	{0x2AA6C9C3, 0xB464076B, 0x36C9EC5B, 0xB9E5BF59, 0x07738DC8} } ,
	 { {0xB732D8C8, 0x7B367826, 0x0FE4E524, 0x6B4119F9, 0x06402D05},
	{0x5A64ED17, 0x3E482E01, 0xD3861B55, 0x7908F745, 0x02C2F362} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5102 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5103 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5104 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5105 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5106 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5107 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5108 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5109 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5110 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5111 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBA83D89C, 0x11FE693B, 0xA75914D7, 0x8603977F, 0x1F47B401},
	{0xB9F35984, 0x7553E3E2, 0x611ACBE7, 0xAFDC46C2, 0x125382FC} } ,
	 { {0x634451BD, 0x3C2AD11D, 0x440D5BD0, 0xE039954B, 0x0EEFFA47},
	{0x8BABB56F, 0x4BD55D19, 0x987A728B, 0x8DE5B46F, 0x1135407B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5112 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5113 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5114 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5115 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5116 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5117 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5118 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5119 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5120 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5121 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x14C7CAED, 0xB4E2E23C, 0xC98D90E3, 0x2EB1FE73, 0x22057CCA},
	{0x75D01DAD, 0xC303D800, 0xB1447FEC, 0x0A3BFA51, 0x01D70B13} } ,
	 { {0x2E2EC6C6, 0x5A0D4534, 0x50B85DC4, 0x8C9A7D28, 0x0123847A},
	{0x1E6FD970, 0x813B3DFF, 0x1E52E534, 0xE15C9AC4, 0x0E48A0D0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5122 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5123 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5124 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5125 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5126 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5127 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5128 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5129 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5130 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5131 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x055297F6, 0x10BF1172, 0x5D8D1E20, 0x5B9B48DD, 0x19CE1D39},
	{0x007ADD4F, 0x0D6A08CC, 0x0DCAFDB0, 0x51F7C436, 0x166E2646} } ,
	 { {0xB5FCBCFB, 0xE6D2B721, 0xBB0A4B0E, 0xE3ED5AD5, 0x00D3867A},
	{0xBEB78A46, 0xD45A0C5A, 0xF3C8B2C7, 0x1DC2403B, 0x18B32AB5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	 { {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_copy(&var_tmp, &var_a);
		assert_bi_equal(var_a.x[0], var_tmp.x[0], "ecfp2_clear 5132 a.x[0]");
		assert_bi_equal(var_a.x[1], var_tmp.x[1], "ecfp2_clear 5133 a.x[1]");
		assert_bi_equal(var_a.y[0], var_tmp.y[0], "ecfp2_clear 5134 a.y[0]");
		assert_bi_equal(var_a.y[1], var_tmp.y[1], "ecfp2_clear 5135 a.y[1]");
		assert_equal(var_a.infinity,var_tmp.infinity, "ecfp2_clear 5136 infinity");
		ecfp2_clear(&var_tmp);
		assert_bi_equal(var_expected.x[0], var_tmp.x[0], "ecfp2_clear 5137 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_tmp.x[1], "ecfp2_clear 5138 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_tmp.y[0], "ecfp2_clear 5139 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_tmp.y[1], "ecfp2_clear 5140 a.y[1]");
		assert_equal(var_expected.infinity,var_tmp.infinity, "ecfp2_clear 5141 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x858EABA1, 0x9641D7F6, 0x3B29174B, 0x347F3E73, 0x181A771C},
	{0x445826E4, 0xA2D0D02D, 0xD3B3E08C, 0x37D5A1E0, 0x04770AAD} } ,
	 { {0x9F36631A, 0x398E008D, 0x441898F1, 0x86AF9417, 0x216D023D},
	{0x8AAC96D8, 0xE49A1055, 0x7D90D7CB, 0x1E65BDE6, 0x1B45F0C6} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x52077148, 0x420ADD54, 0x0E0CD1FF, 0x1885BFC2, 0x1ABBF948},
	{0x07F16F44, 0xE8A10BB5, 0xB541CE9B, 0xD4A21E9C, 0x0A7F13A1} } ,
	 { {0x1A4A74D1, 0x61149D61, 0x6512953B, 0x1046FCD6, 0x11CE3213},
	{0xA533F5AF, 0xB79E54E7, 0xD1FD0F15, 0xC4064B7C, 0x18A45D40} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x0ED8B766, 0x85D9829C, 0x406BDD7C, 0xD9A3B2B8, 0x1DF25BD3},
	{0x4184C09B, 0x6794AC3D, 0xF94D0563, 0x72FB5036, 0x15A20358} } ,
	 { {0xD28EB919, 0x343AA5E3, 0xDC5C57FA, 0x0969B8F4, 0x1B840628},
	{0xFC5940B7, 0x94785E5B, 0x9AEFDAD7, 0xC275E256, 0x10AB7235} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5142 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5143 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5144 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5145 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5146 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4F5B11F6, 0x9F061A1D, 0x48B2582D, 0x22A889CE, 0x1EA3F22E},
	{0x6D74F03F, 0xA8E7C7DB, 0x5A6E8A4B, 0x9474F33C, 0x0C068E2B} } ,
	 { {0xC6CE3C5B, 0x999423A9, 0x265F001B, 0x523A264A, 0x0DB9195E},
	{0xBB378A4E, 0x2F7ECA15, 0x0121A158, 0xE031F6AA, 0x06660169} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF2F1E596, 0xFC3250A4, 0x2B5E15E2, 0xBAFBD11C, 0x0E0BDCEC},
	{0x192D93F7, 0x642B49E0, 0x31C6EA1E, 0x7FA6FE53, 0x09B96004} } ,
	 { {0xD045944F, 0x848DD218, 0xE8BD75FB, 0x53C0D000, 0x01199AD1},
	{0x00997E9E, 0x677D856B, 0xEA5B5E37, 0x12DC56FF, 0x07CD6147} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAD46E1AD, 0x3D80EE99, 0x220CD595, 0x0131C9BE, 0x0544E08C},
	{0x987F1A54, 0xE459983E, 0xED9CC838, 0x871F80BD, 0x19F64E85} } ,
	 { {0xCD235F36, 0x12E9B1F6, 0x25C67851, 0x7F568165, 0x23E789F6},
	{0x2A1EE0A8, 0xA5837AD7, 0xDE889603, 0xBED00521, 0x07515B16} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5147 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5148 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5149 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5150 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5151 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE617C952, 0x17A29219, 0xED57524A, 0xAA4F96BE, 0x02CD8A3A},
	{0x346E5786, 0x96F09C3B, 0xB9AF5BC5, 0x7519DD1A, 0x1940B3BA} } ,
	 { {0x010A9E8C, 0xBD734622, 0x17DCA496, 0x9CC80D18, 0x06C67015},
	{0x68618707, 0xF2AC4CE1, 0x8509663B, 0x66074FB3, 0x09046E3A} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFE3AFA10, 0xD7852EC9, 0x9807D98C, 0xA386529C, 0x186C5CD4},
	{0x51A1969A, 0x39E75362, 0x1EFD4676, 0x2A3B6C35, 0x15683FC9} } ,
	 { {0x6289E1AB, 0xABD8F328, 0xA22BE1D9, 0x532FB510, 0x1CFDD5E6},
	{0x50735475, 0x736A1FA4, 0x549BEBA2, 0x0EA842A3, 0x2087B11C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x0B8D6729, 0x95682BE5, 0xB85B816B, 0xD219330F, 0x20F72882},
	{0xD7E30A8D, 0x06F3333C, 0xA9ABFE94, 0xC4680AB8, 0x19037158} } ,
	 { {0xE57E08E5, 0xFC33D677, 0xFF855A82, 0xE64DCB38, 0x0ECEDC75},
	{0xC015FCCD, 0x3F0BC343, 0xFB03A013, 0xDB65A677, 0x0C966E47} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5152 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5153 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5154 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5155 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5156 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC8B11617, 0xAB3A50BE, 0xA4D8A774, 0x440887CC, 0x0A0D6765},
	{0x5D88DBD5, 0xF38391DA, 0xA790A8F7, 0x23FF94C4, 0x0B551C1C} } ,
	 { {0x3B8C6ED7, 0xE78DB1DA, 0x61F103FB, 0x2862A249, 0x0502E7B0},
	{0x0420AFC9, 0x535258DA, 0x766C7AEA, 0xF0BA4D04, 0x1C9C5B2B} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x387F0DBD, 0xB6FEFA06, 0x9229508C, 0xD9A33FD9, 0x007EC7C0},
	{0xB244EA23, 0x60B270FD, 0x92207177, 0x00B0A761, 0x021C317A} } ,
	 { {0x8CA21485, 0x5EE8DCD0, 0xD8F322FB, 0xAACB90EB, 0x1719A64F},
	{0x1EC71FC0, 0x984BB5FB, 0x8651B037, 0xAE5B39A1, 0x18DB181A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x7EF86B9C, 0xBE6BE3BB, 0xD28B9BE3, 0x6E77A0E7, 0x16EDF81D},
	{0x4C02BF28, 0x4003DE08, 0x3BE7F4FA, 0x31772AE1, 0x12918AD2} } ,
	 { {0x05CFE29F, 0x882B056E, 0x896C7E12, 0x77E9802F, 0x148F6F3E},
	{0x94DEE308, 0x4CA9C58F, 0x72743F90, 0xDF5C970F, 0x040D59B1} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5157 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5158 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5159 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5160 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5161 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC5CF2F34, 0x50D6075E, 0x59F4E6BC, 0xAC4C80CC, 0x05199743},
	{0x0BE31C2D, 0xB0B5086A, 0xB4A06D7E, 0x0F7BEE6B, 0x0E6211DF} } ,
	 { {0xAD7F1F35, 0xA5651C5E, 0x028CDC43, 0x123192CA, 0x02418316},
	{0x5978E7D2, 0x25DFF927, 0x811AA6B0, 0x363C3CD3, 0x12EC86D1} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFDE288CE, 0x2D959498, 0x26159617, 0x4D017C6C, 0x02AC912C},
	{0xB18CDE93, 0x6CE0DF47, 0x64C585FD, 0xEE7481E3, 0x1566BE75} } ,
	 { {0xCAA65AA7, 0x9F47EE42, 0xCB6689E0, 0x13B7DB6C, 0x1FEF8BCF},
	{0xF41F4DF5, 0x5A68FA76, 0xFF61550E, 0xCCCBE4D6, 0x0F795A70} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x985710AE, 0xF274CDD5, 0xE7509ACC, 0x6FC6F3B4, 0x04DC1EDB},
	{0x394D6603, 0x94AAEE28, 0x4F7C9196, 0x10F0D196, 0x0FA98AEB} } ,
	 { {0x795A13A8, 0xDCAFFD33, 0xEDAFE6FF, 0x2E330CB1, 0x03B3D773},
	{0x4F7BDCE0, 0xC2264450, 0xE8B7F358, 0xF99B74C8, 0x2004FC58} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5162 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5163 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5164 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5165 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5166 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x15211B7D, 0xBB0007A4, 0x3E019B70, 0x617075F8, 0x198B082F},
	{0xC35E39E1, 0x1647A9E3, 0xD2D41D44, 0x7508FC88, 0x1B5B6303} } ,
	 { {0xF356125D, 0x9C1180AA, 0xAF10D2F2, 0x7E27983B, 0x0F33D186},
	{0xC1BAA73D, 0xDE3D3891, 0x5C0812C2, 0x959610EB, 0x00B618FB} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x5AC59770, 0x84F6A73C, 0x98F7A75E, 0xC970F7A6, 0x181E811D},
	{0x6056DF19, 0xC36816CB, 0xCC5CB707, 0x75661944, 0x01044E0F} } ,
	 { {0x0FCE9ED0, 0xE1680458, 0xCDADD793, 0xC87AF739, 0x1EF7A3DE},
	{0xD42EB0CC, 0xE8B8AF3C, 0x006BDD5A, 0x112FA322, 0x0E078DBD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x95AABA43, 0x36BA39A4, 0xFBDBEF7E, 0xF1320785, 0x0F7D56D0},
	{0x13183ABA, 0x2E594E70, 0x24FFC3AA, 0xBD3153D8, 0x04AB67A6} } ,
	 { {0x57C4277B, 0x44071349, 0x9D89CF4F, 0x63DD4F3B, 0x17D1F1FF},
	{0x8F5C6C36, 0xD30D31A5, 0xE3B415D0, 0x0F97A527, 0x23D57ECC} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5167 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5168 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5169 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5170 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5171 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC1C7F45C, 0x69EC155F, 0xB23F07AB, 0xD2ED0FF9, 0x01A4472D},
	{0xF5023F3E, 0x89B9771A, 0xD0C841BC, 0xD8B98EDD, 0x0A5D0359} } ,
	 { {0x8922DFD6, 0x0BF2150A, 0x265BC09E, 0x2807BA3B, 0x0F4A4012},
	{0x4F0D4C6E, 0xACA820B2, 0xC1593236, 0x7F2361FA, 0x12D77995} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xFFCB0E33, 0x1BC4BC90, 0x436FB1E7, 0xFC504741, 0x1AF70156},
	{0x96F5EE34, 0x1E48E64C, 0x29FE7E69, 0x953494F5, 0x11C541FA} } ,
	 { {0xDA3A3BDA, 0x1FDF6A1F, 0x7D0FC03F, 0x7BDBA49D, 0x1FA8DFBC},
	{0x2FA5A195, 0x2CA91D7E, 0xDB3FFB69, 0x16A20053, 0x13400B0F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xB8CB3C4D, 0x2746B704, 0x8AF236FB, 0x4733F6DB, 0x21D12D9D},
	{0x786E9C6D, 0x10BEAEC5, 0xD741855D, 0x6D62AF03, 0x1D00A551} } ,
	 { {0x6C8352B1, 0xF9B47B16, 0x2236E41C, 0x298D17E1, 0x14A9C689},
	{0xE7B6A294, 0xF03C1D78, 0x0DE11369, 0x89ECA5EF, 0x235DB093} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5172 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5173 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5174 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5175 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5176 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0D39EEAD, 0x66650234, 0x27D0CD1E, 0xFEF0D4E6, 0x0B2A39CD},
	{0x5CE4AEC0, 0x46814F6A, 0xCD473ACE, 0x285788A8, 0x0261831F} } ,
	 { {0xE614EB0C, 0x199A6446, 0xD2EE4071, 0x7254AA96, 0x09BC175B},
	{0xD3861691, 0x389DCF3D, 0x0B76276C, 0x9B2404E7, 0x1F5AB2C9} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE89CA82B, 0x7D855F38, 0xF021084B, 0x5ACDC04F, 0x04EC19ED},
	{0x4D0136A1, 0xB374B747, 0xBAC907CC, 0xE5B5F841, 0x0BEDE899} } ,
	 { {0xC7AD146D, 0x6A36A9D7, 0x04F9A96D, 0x96C8ABF5, 0x154DDB5E},
	{0x8727369F, 0x0E838F7B, 0xFD072691, 0x363641FC, 0x1F2AE5C5} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x3E4D1EAE, 0x7FD6AEEB, 0x5750352E, 0xEE12319B, 0x0E010D68},
	{0xEE97B2F4, 0xF290DC0D, 0x7E01AFE4, 0x59BF359C, 0x05314615} } ,
	 { {0x3B2D48C6, 0x44D3BD6F, 0x87BE129C, 0x69FA4810, 0x1848E864},
	{0x8C2EBECF, 0x3193B1C9, 0x77B92422, 0x66DCF2FD, 0x23B9EC76} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5177 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5178 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5179 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5180 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5181 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD6DC0FB5, 0xB95EB28F, 0x7944922F, 0xBCD54C0C, 0x1801BB0D},
	{0xD09CB7BE, 0xDBE00E8B, 0xBD3DEC3B, 0xC94615AD, 0x1CBFC28E} } ,
	 { {0x6F311355, 0x348A057B, 0x2FFE5405, 0x9C66B604, 0x1CF95D99},
	{0x61942173, 0xBFFF6042, 0xCF644835, 0x4779A590, 0x08977BD8} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xA4438730, 0x28A4A70C, 0x7C919164, 0xFE6299C1, 0x0DEAA271},
	{0x5CFE72D6, 0xE2F35E1F, 0x54E3A59B, 0x4374EC28, 0x1F5888A3} } ,
	 { {0x558B3F00, 0xAF6EB292, 0xCB78D1F0, 0x0E3E19E5, 0x1F323A42},
	{0xD847FE95, 0xECA368DE, 0xE1A75189, 0x9C61A3DA, 0x01C5C6F2} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAEE9D89B, 0x3B33D1F6, 0x49EE17F2, 0x10100F5C, 0x21047109},
	{0x0DB47F03, 0x47E96EA0, 0x8B40871B, 0x560BF38C, 0x15F4D890} } ,
	 { {0xE824092C, 0xA3925F73, 0x3E935174, 0xEA2C84EC, 0x110BE4E5},
	{0x0E4791E4, 0xBCF9CA69, 0x7C53349F, 0x5C81702B, 0x07FDEFEF} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5182 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5183 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5184 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5185 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5186 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xEF9F396A, 0x71F804A2, 0xD9FBFB75, 0xFD10B0DB, 0x0C8FDC3A},
	{0xC4C3051F, 0x3A3EBBAE, 0xAD4E25E8, 0x41E76247, 0x07DA165A} } ,
	 { {0x69F3C52C, 0x39521986, 0x0E7C840A, 0xA2F21D9C, 0x14E45204},
	{0x34895E98, 0x9CCCB0F6, 0x2155CE4D, 0x6B9B9B58, 0x0AB52D78} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x4D9476E5, 0x1EC62598, 0x8073E74F, 0x638AFAAA, 0x162E7285},
	{0x83FFAF21, 0x19382508, 0x9B54AD81, 0xEF7014B4, 0x0CCF052A} } ,
	 { {0x4E19F14B, 0x3D8B5B01, 0x1B921F6F, 0x6750BE00, 0x0E53E7E6},
	{0x6435A677, 0xA75DEF20, 0x5FEE963D, 0x8AE22030, 0x1A9D6A60} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x698F3F1D, 0xF65D0EC9, 0x0242BAC8, 0xACA82C82, 0x0896DC2A},
	{0x9F419B47, 0xAD29ACED, 0xEC257818, 0xAD9079B5, 0x02D01559} } ,
	 { {0xEB75C810, 0x216EAC6D, 0x49AF7B5C, 0xC128D41B, 0x00A61593},
	{0xFF97F023, 0xB2C260FF, 0x6CA941E9, 0x922DE72B, 0x131D1326} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5187 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5188 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5189 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5190 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5191 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD30DE39C, 0x184598BA, 0xA4CDBE18, 0xB2525BB8, 0x12D45971},
	{0x7CA40928, 0x64D096B2, 0x8316B5A9, 0x50C226EE, 0x0EEAD0B7} } ,
	 { {0x6E113802, 0xA727B527, 0xECED1D4E, 0x8664E653, 0x1A66D1D9},
	{0x3046BCD7, 0xE068166E, 0x65D29E2C, 0x8BF22660, 0x0923C5E6} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x59A2A251, 0x29867971, 0x12059BB0, 0xA5145FDE, 0x190B451C},
	{0xED3798A8, 0xEBC96279, 0xABBDA52F, 0xC28FC3EA, 0x11E4E2DF} } ,
	 { {0xED16D1A0, 0x7E6C3ADB, 0x4C223D52, 0xFDDC6DF9, 0x08F44031},
	{0x693F0CFF, 0x4497B4FC, 0x5D9B2FCA, 0x4740E84A, 0x03D6BB0A} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x6DF12ECF, 0xA4834651, 0xC069502D, 0x04B6A077, 0x1EADCB59},
	{0x5F3916F0, 0xD78C18AD, 0xB7D95A46, 0x0D95D3E3, 0x23CF8844} } ,
	 { {0x8684FF37, 0xF09B3C95, 0x34D9F438, 0xE664B3FF, 0x11AD7E1D},
	{0x09A0C75D, 0x23F7D51E, 0x7084FDC5, 0x3ABD4E6F, 0x0CFB4105} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5192 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5193 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5194 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5195 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5196 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4428C4A1, 0x974AFA25, 0xD7B30FA0, 0x8113362A, 0x0C3E0C4F},
	{0x72329316, 0xF62E3C16, 0x36718227, 0xC4A26110, 0x1A240958} } ,
	 { {0x3B42B370, 0xEC7C1E8A, 0x9DEF7629, 0x76205A34, 0x207D238E},
	{0x8E22D659, 0xFDA79E7E, 0x65FB13CB, 0xD825D098, 0x1671DD15} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x377907DF, 0x879B4F70, 0xD940F0CD, 0xD65A942B, 0x1B987E94},
	{0x400EAE78, 0xA41170C9, 0x523B3833, 0x4BF97748, 0x04F54BE6} } ,
	 { {0xE585541B, 0x893BEB7F, 0x0DB05C25, 0x760D5649, 0x1126CFB7},
	{0xA7B4A390, 0x43D1E544, 0x51B3207B, 0xF22A93BD, 0x0F215255} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x53860917, 0xFD7CBFB3, 0xC600215A, 0x8FE5BE96, 0x0B29BC7B},
	{0xFE1AB1E2, 0xF8A47C93, 0x28EA88C1, 0xB457FBB8, 0x1091124F} } ,
	 { {0xE43FE481, 0x71697A4E, 0xA639ED72, 0x2BF49761, 0x1A09AFFD},
	{0x72774E01, 0xAA179C03, 0x79BAB6C5, 0x1CD91299, 0x0084FDA1} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5197 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5198 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5199 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5200 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5201 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x35F4A50E, 0x7CE0D0FE, 0xEAB84437, 0xB4F9595C, 0x02559ADB},
	{0xDF019845, 0x272424E6, 0x4C371301, 0xFDC276EE, 0x150EBF9A} } ,
	 { {0x4DE0DEE0, 0xB0C069C7, 0x7819AA2E, 0x297F5CAC, 0x0FD1F6DF},
	{0x0C8DFCBF, 0x7978B57A, 0x2FEF79A6, 0xB2904472, 0x04FDCD27} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x15E98754, 0x10C0227E, 0x8F42B987, 0x9A3062EB, 0x23150BD9},
	{0x5166EE02, 0xBF774898, 0x26CFA582, 0xE824FAFD, 0x08D31AB8} } ,
	 { {0x084363E7, 0xEF2AB7AF, 0xC2E4B5CC, 0xB7947852, 0x1C39B108},
	{0xE2C3B80F, 0x4C9DD9CA, 0xE9417C10, 0x535CA851, 0x20185F68} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x79695D84, 0xCBD1DCE8, 0xF9CFE4CB, 0x28280E0A, 0x20F0585D},
	{0x898ABB7F, 0x54C85FE8, 0x6C44D93D, 0x6F8E1D10, 0x0AB584BF} } ,
	 { {0x95911126, 0x02E53699, 0x56A3C13A, 0xFB335852, 0x11900CB0},
	{0xB693EFB4, 0x94B1770B, 0x6C651A2F, 0x08AC91E1, 0x052AD72C} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5202 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5203 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5204 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5205 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5206 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x33335B2B, 0x8A2B9399, 0xE99C2CE0, 0xA11E5F64, 0x13F4AB52},
	{0x5716B826, 0x39DB648D, 0x60064FB3, 0x9ED5BED7, 0x1DFEDD42} } ,
	 { {0x369CCDD9, 0x4561BFA6, 0x9B740A42, 0x68A3416A, 0x1231BCA2},
	{0x9B65EC73, 0x7A9D78A6, 0x7D3EEA42, 0x335C694B, 0x23B3D1FC} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xEE1378A8, 0x5FC98A4B, 0x67C73CFC, 0xC5C736C5, 0x0F52290A},
	{0xA22F2CFE, 0xDB2EA11D, 0x8E57563A, 0xE17290E8, 0x0B09B3AC} } ,
	 { {0x8FD973B7, 0xC10D765D, 0x577F2438, 0x00C03B2A, 0x0A4EB13A},
	{0x4609CF1D, 0xB2E31C34, 0xCDC47E0E, 0x4FA12281, 0x0495DF47} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xE806BD6D, 0x34F2742A, 0x40AD2F15, 0x248A5E46, 0x14D5FAAC},
	{0x136E0EA3, 0x5AB99867, 0x935BD942, 0x39BE37BD, 0x1F032137} } ,
	 { {0x263DB3D0, 0x93FD8F6A, 0x3BB011DA, 0x58C44851, 0x2376FB12},
	{0x5E8B2A01, 0x9DAF32DC, 0xBB90FDCB, 0x2294259E, 0x049DE224} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5207 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5208 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5209 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5210 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5211 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x865356C1, 0x0468FF05, 0xACE618A6, 0x8C5946B7, 0x1244493A},
	{0xAB531DD2, 0x5E001ACA, 0x6F49EA70, 0xDDFD45BE, 0x00B5C6D1} } ,
	 { {0xE9245F1A, 0xE9EAB2E5, 0x8854F789, 0x015DCF77, 0x0CB74829},
	{0x4CB3B2DD, 0xC0A5AEEB, 0x52E1A146, 0x3C4C9196, 0x145D94FD} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC0152059, 0x4E41FA0D, 0xFB1C5315, 0x6D7052AC, 0x144D13B8},
	{0x2FF7EC90, 0x4A10C99B, 0x6495E288, 0x366CCBEF, 0x024EEA4C} } ,
	 { {0x3C7609AB, 0x3A79ADA8, 0x1805E2DD, 0x5B8CF6C0, 0x0960B235},
	{0xD4460000, 0x8BAD7798, 0x5B1E3B93, 0x7920B2CC, 0x0A82DF53} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA07FB0CC, 0x3A162BB4, 0xE7D4AAE7, 0xC9249D97, 0x1AB5D71C},
	{0x798E0329, 0x9A131524, 0x32A3C8F4, 0xDC12CD43, 0x08A6FD39} } ,
	 { {0x8B4372FB, 0xC059ED0D, 0xAF64478D, 0x22F85705, 0x0C033AC3},
	{0x8DB420A1, 0xA3EA955B, 0x88329269, 0xDF68BA86, 0x06B4926D} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5212 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5213 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5214 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5215 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5216 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x92D0D353, 0x1B9FBFFB, 0x60A64CF2, 0xBF5529B0, 0x23715A9C},
	{0x72A3C876, 0x4A01B7F3, 0x269CE48D, 0x3C731AB4, 0x20195B81} } ,
	 { {0xFB8AD22F, 0x5DFE355F, 0x01A26E0D, 0x20DB3F2F, 0x0D1DF7BD},
	{0x7ED5E70F, 0x2D9203C9, 0x9C6CFE02, 0x31C5B556, 0x1906B55D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x92645F35, 0xE2DB39C9, 0xFD6E9F34, 0xC45F2B91, 0x0E8C3BB3},
	{0xEAE6AF10, 0x9F917A55, 0xA20CFBB3, 0x76BEDDDA, 0x00535E97} } ,
	 { {0x3CBA4290, 0x507630A9, 0x9B1E561E, 0x7CD572FC, 0x0D40738C},
	{0x21D94522, 0xD9CA0F0E, 0x789D998A, 0x8028C498, 0x01AD6423} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD6DEF0C3, 0x7BBFBC85, 0x9EEDC75E, 0x8FD0BDA3, 0x0959A811},
	{0x6A2C16B5, 0xF0B1FF04, 0xFAB28715, 0x64468DE5, 0x0D30C1C2} } ,
	 { {0x6D0BA01F, 0x77117C90, 0x6B143650, 0x6AC77DB0, 0x17ADC84E},
	{0x98F6B587, 0x470B4C32, 0x3373F8E5, 0xE05CD994, 0x130BDC95} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5217 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5218 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5219 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5220 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5221 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x11CBF344, 0x23839407, 0xEA775AC3, 0xC410E0FE, 0x12E9786F},
	{0x7E51B080, 0xD0ED6580, 0x749D5D3F, 0x878BC446, 0x14E26D35} } ,
	 { {0x8CA70802, 0x4C60DBDC, 0x26B3DBEA, 0x3A3EED1B, 0x14741281},
	{0x77171B9A, 0xCB099B20, 0x3A73BA0E, 0x62A9BE51, 0x094FAB6D} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x11CBF344, 0x23839407, 0xEA775AC3, 0xC410E0FE, 0x12E9786F},
	{0x7E51B080, 0xD0ED6580, 0x749D5D3F, 0x878BC446, 0x14E26D35} } ,
	 { {0x8CA70802, 0x4C60DBDC, 0x26B3DBEA, 0x3A3EED1B, 0x14741281},
	{0x77171B9A, 0xCB099B20, 0x3A73BA0E, 0x62A9BE51, 0x094FAB6D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x196741FD, 0x44355BA1, 0x18264C50, 0x06FE2C04, 0x1A8EDC3B},
	{0x633E0159, 0xB0C4D60A, 0x435B749C, 0xFA523711, 0x0DA5A8EF} } ,
	 { {0xF84C5E08, 0xE8998BA8, 0x61E44A5D, 0x01B0B82E, 0x098A5944},
	{0xB042157A, 0xA27A2ACC, 0x14B7A79D, 0x65F1324F, 0x1793704B} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5222 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5223 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5224 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5225 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5226 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5BD29060, 0x15488893, 0x1D9426DE, 0x8D599D58, 0x1234FF5D},
	{0x775CE9D9, 0x12F4CCE8, 0xBC7C2B76, 0xECFF2856, 0x023A1522} } ,
	 { {0x4DFB74CB, 0xE4EDF342, 0x1A841357, 0x6AAC22C3, 0x09C230D6},
	{0x5A7604B5, 0xDC5E5919, 0x774E1280, 0x5A38FEB5, 0x179AD3DC} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x5BD29060, 0x15488893, 0x1D9426DE, 0x8D599D58, 0x1234FF5D},
	{0x775CE9D9, 0x12F4CCE8, 0xBC7C2B76, 0xECFF2856, 0x023A1522} } ,
	 { {0x4DFB74CB, 0xE4EDF342, 0x1A841357, 0x6AAC22C3, 0x09C230D6},
	{0x5A7604B5, 0xDC5E5919, 0x774E1280, 0x5A38FEB5, 0x179AD3DC} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x59728D66, 0xC5E76EB8, 0xFE9C9366, 0x17B32C80, 0x0777792C},
	{0x2592725A, 0xF8ACE113, 0x24B30DED, 0x3BE69C88, 0x1501AA59} } ,
	 { {0x1BA5335C, 0xF72ED0E1, 0xCAF44613, 0x4E361DBE, 0x007A5415},
	{0xCCF11ABE, 0x59199142, 0xCBAA897A, 0x4FADD5FE, 0x06B8D778} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5227 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5228 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5229 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5230 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5231 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC1639ECF, 0xC25FF9C7, 0xC7ED98B5, 0x6FBD0E75, 0x08795F94},
	{0xAAA23BA6, 0xD5367EFC, 0xE2EF93DB, 0x20732B63, 0x038B58A9} } ,
	 { {0xA2EB34AE, 0x0140188D, 0xD4E0B904, 0xEB9F6D8E, 0x00B3D072},
	{0xF06797A9, 0x87F0E1AA, 0xAF722556, 0x094DEAA1, 0x08509CD7} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xB5B54FD5, 0x29394AA5, 0xAC35E72C, 0xE200C389, 0x214C68ED},
	{0x97401F8B, 0x4B4513A5, 0xA709DDC4, 0x97BF7EA7, 0x1AE64885} } ,
	 { {0x7A9CC6F3, 0xDAD9BC4D, 0x27DFBF77, 0x4698C559, 0x11A2935B},
	{0x1DCE18C7, 0x54F747B7, 0x93ABB2E3, 0xA0E2A183, 0x059302D0} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xBD2A6454, 0x5D7DCF71, 0x33CE857E, 0x5A7A97A5, 0x10EA6849},
	{0x192C3F2E, 0x8F40C8CA, 0x32FE92BD, 0xB8B5DA27, 0x1FD3A4D9} } ,
	 { {0x9C076329, 0x70225FAE, 0xBEF86683, 0xA1C05B24, 0x13379997},
	{0xE20D8F8C, 0x5BD8DC13, 0xDEE194DD, 0x0F91D4CF, 0x20A17E7D} } ,
	 { {0xF451B106, 0x66D950DD, 0xE4484E76, 0x7243B513, 0x18D30959},
	{0xEC9DE3E5, 0x760E94A8, 0xC41A49E8, 0x774C5343, 0x175AEFDC} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 251 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 252 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 253 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 254 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 255 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 256 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 257 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xCF0D5055, 0x3D5DC91A, 0x679B93D8, 0xFDED3F52, 0x16573CCE},
	{0xA185D35D, 0xDAF9C4EA, 0x494A9F05, 0x7E9CBC34, 0x101F7CBC} } ,
	 { {0x81BEF080, 0x0131E08F, 0x3F437333, 0xA4382C64, 0x11AC7483},
	{0xFD2641CC, 0xD9F6A15D, 0x7F1CFDFB, 0xEE842FB1, 0x17920BAD} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xBFB787B5, 0x8903C403, 0x045263F8, 0xD7FA672A, 0x00966FE9},
	{0x97E8B265, 0x26CC5272, 0xEB47E2B1, 0xBEC9A89C, 0x046AC1F0} } ,
	 { {0xA8C0930C, 0x691690F3, 0x85E4393B, 0x7F57234B, 0x137724D0},
	{0x8EF8FCF9, 0xC3ED7F1A, 0x65FC7BC1, 0x53F06E86, 0x21FCB2A7} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x2EDFFEDB, 0x85BA4928, 0xA417B957, 0xADA96DCA, 0x0A2C7C60},
	{0x3997AD04, 0xC69CF7E2, 0xBE8CB00E, 0x59D99E83, 0x1BC57C5E} } ,
	 { {0x4ACAFD1A, 0x3022F100, 0xD85C98B5, 0x1F0CF021, 0x088794BE},
	{0x114FD645, 0x39647A55, 0xD6D0D85A, 0x2555EFD8, 0x04042EB8} } ,
	 { {0x3CFA89BB, 0x69D34F89, 0xD60190BE, 0x896383BD, 0x0E40531E},
	{0x42B33163, 0x69FFE228, 0xDB480449, 0xEF83484E, 0x184C6537} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 258 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 259 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 260 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 261 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 262 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 263 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 264 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x55C3F42E, 0x69D09941, 0x829BE463, 0xA70D403A, 0x208ADC68},
	{0x3BE4624A, 0x32E4CB64, 0x2BFCBCC5, 0xF19D53F1, 0x01258717} } ,
	 { {0x2B636B04, 0xCAEDA466, 0x8DF514F5, 0x691E69F5, 0x04459DA7},
	{0x3873F990, 0x0DCBA716, 0x43F577B2, 0xAF4A5D4F, 0x091D6C00} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x48566D95, 0x0314876C, 0x6664BC47, 0xC89917EC, 0x029E7AE7},
	{0xC46825E0, 0x6ADD2595, 0x87CC6283, 0x6D95E526, 0x07BAA1D5} } ,
	 { {0xEB30EBD9, 0x921A011A, 0xFE5492D5, 0x9879025D, 0x1A3577DB},
	{0xA1652D64, 0x0612C881, 0x5943F183, 0xA998A39C, 0x2196613A} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xACE38D89, 0x1050533C, 0x9001BF3D, 0x74320065, 0x20A8D78C},
	{0xC098EC71, 0xF79DE3F5, 0x7BB07EB1, 0x27652100, 0x0287610A} } ,
	 { {0x919A70CF, 0xFE2E8E33, 0x26994C46, 0xCE770459, 0x08B15E0C},
	{0x375A9206, 0x118AC5C7, 0x65413A98, 0xF4E005C7, 0x1B1AC12A} } ,
	 { {0x3EE2CBC2, 0xB77142CB, 0x1D139881, 0xD0E23398, 0x0614BE82},
	{0x8883C396, 0x37F85A31, 0x5BCFA5BE, 0x7BF89135, 0x06951ABD} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 265 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 266 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 267 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 268 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 269 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 270 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 271 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xD57D6046, 0x18F0049B, 0x9305A593, 0xCDD0B49A, 0x16E3C98A},
	{0x83DBCB31, 0x9FB3629D, 0x7D636447, 0x91E81646, 0x18495BD6} } ,
	 { {0x2A8DBB9B, 0xA2675167, 0xDDBE3DF7, 0x6825E3D5, 0x1129151B},
	{0x57D483DC, 0x477CDBD2, 0xE0E357D8, 0x0C61F63C, 0x0E6DC22A} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x29F1F312, 0x9686E361, 0xFD50E666, 0xFFB3D027, 0x1EC25CD9},
	{0xDD904ADF, 0xA108C937, 0xEE11A922, 0xE31E4B1D, 0x0744F36A} } ,
	 { {0xABBD9254, 0x65780058, 0xDA571C88, 0xF1E77921, 0x200173FB},
	{0x1B36A9D6, 0x5C6DBB22, 0xB18F9D13, 0x659E7071, 0x0D50F2A2} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xFBC9C9AA, 0xD5CF05F6, 0x98EF96EA, 0xE2B10546, 0x1B70E29A},
	{0xE84B7EF4, 0x0E823C7A, 0x11CC10E8, 0x04DD631B, 0x071666A6} } ,
	 { {0xC8EAF903, 0xDB5C8A4B, 0x76E3861D, 0x93EE011F, 0x09876EB1},
	{0x8E42BD66, 0xBC03DE08, 0x4A7DD478, 0x4ABE0A0E, 0x1862F88D} } ,
	 { {0x547492CC, 0x7D96DEC5, 0x6A4B40D3, 0x31E31B8D, 0x07DE934F},
	{0xA604D209, 0x1F82BB3A, 0xA9F90579, 0x008C90BD, 0x12FCB798} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 272 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 273 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 274 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 275 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 276 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 277 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 278 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6E0B9623, 0xD3482F8B, 0xFD597F41, 0x1C77D060, 0x11EEF1AB},
	{0x427CB964, 0xE140E88B, 0xFA350257, 0xC7FDE115, 0x04DA625A} } ,
	 { {0xABF4A444, 0xE3C8EAEA, 0x7736C345, 0xB193F073, 0x00F26F8B},
	{0x6ABAFE21, 0x030979DA, 0xE0147C8A, 0xA16B5936, 0x04D03089} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xCD1C4D03, 0xEA707577, 0x7342B744, 0x1082118A, 0x06A34769},
	{0x690CF9B0, 0xE4332371, 0x426D757E, 0x5750706A, 0x0E99D6CF} } ,
	 { {0x6E963737, 0xF6093866, 0xC1924BB0, 0x5F1CB1C8, 0x1BC1349A},
	{0x816E157C, 0xDCF096A5, 0xE6B789D1, 0xC8FA81F2, 0x0AB0934B} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xE5C14382, 0x1525FA6D, 0xC22000BC, 0x5B23C865, 0x12B8B9F4},
	{0xC3EDFD86, 0x95D5F575, 0x4A920D24, 0xAA2BB3BC, 0x0E6C0C4B} } ,
	 { {0xE9CFE3EE, 0xD3E14383, 0xEC827F81, 0xF5A2B240, 0x1E87C774},
	{0xAE8068B9, 0x70AB9BD7, 0xA3F5214B, 0xE74BB704, 0x1169E019} } ,
	 { {0xAB61093B, 0x35559A8C, 0xAF33F8A1, 0xA3609D0F, 0x18B575C1},
	{0x2690404C, 0x02F23AE6, 0x48387327, 0x8F528F54, 0x09BF7474} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 279 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 280 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 281 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 282 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 283 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 284 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 285 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x18390054, 0x2956C639, 0xA9A8CFFB, 0xD83A1DA8, 0x224EBFBA},
	{0x7B247DA7, 0x34F85B3B, 0xAA6770D9, 0x5EAD8B40, 0x201D29B1} } ,
	 { {0x4FC10CAD, 0xCDB62DED, 0xC46832F0, 0xF6AD0DD6, 0x1F94D98C},
	{0x2E2A31A8, 0x4EE91271, 0x45D7F936, 0x5FBE154B, 0x1B8D9D25} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xE181A3CC, 0xA0C8E574, 0x165C5013, 0xF8D61909, 0x142B31C9},
	{0x6164227C, 0x11709A43, 0x6EBEB0F2, 0x323A542B, 0x0584101D} } ,
	 { {0x567C4BA4, 0x8CC74001, 0xE28E781F, 0xCB1FFA2C, 0x17D7B8E1},
	{0x85B4C4AA, 0xF8B92266, 0x419D53A0, 0x4002D10F, 0x059C4925} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8DE3F552, 0xCAF9D9F9, 0xA6515C38, 0x7E847273, 0x0E5E66B6},
	{0xD85077DF, 0xB840C48C, 0x5E38F58D, 0x2A5BFD9A, 0x0007D371} } ,
	 { {0x02A2E7B5, 0xCA7E1A18, 0x40F4EC17, 0x35606AF3, 0x1C29D095},
	{0xA54168E2, 0x06631DE6, 0x944C15FF, 0xE763EF08, 0x0E72DB5B} } ,
	 { {0x1598F5D3, 0x959F73DC, 0xA5FE40B6, 0xCFF25746, 0x15DD9212},
	{0x328FF730, 0xFAA593A8, 0xFDA200B6, 0x82E324D0, 0x0968066F} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 286 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 287 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 288 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 289 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 290 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 291 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 292 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x74698867, 0xAF3EF01D, 0x3B66B5D3, 0xB9630F41, 0x16AAD52E},
	{0x183FFE5C, 0x603235F8, 0x0074DA4B, 0xC2FA2CBF, 0x0F4583A4} } ,
	 { {0x02036B19, 0xB518F389, 0x64F8E40E, 0x59C55E0D, 0x0D21D1DF},
	{0x5C981A62, 0xA3BD132D, 0xF6E6D7E4, 0xBB4C23FC, 0x0FC08038} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x17313BDA, 0x66D2D7D3, 0xE610F381, 0xC65C22D8, 0x23853FE7},
	{0x7D4062B7, 0x2D386979, 0x543563F0, 0xF4D2D33F, 0x09273DE4} } ,
	 { {0x58149CBB, 0x9FAFC6A5, 0xEAE393DF, 0xA5F16AD8, 0x1DAEDEF8},
	{0xB7650091, 0x72E2DA8E, 0xF88FE517, 0xD77887BF, 0x06AEE9C7} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x154A51C5, 0xD21CF4B3, 0xED5D4778, 0xC98546C9, 0x1231C102},
	{0x254EC83D, 0xF38ACE3A, 0x73904656, 0xFED8D4DC, 0x111696BB} } ,
	 { {0x0B5B8B12, 0x9D0EFADC, 0xB7630187, 0x31FB3E2A, 0x1F781CCE},
	{0x25F04C39, 0x43D32E52, 0xDD05C0A5, 0x7B7C8E39, 0x1AA7E2CC} } ,
	 { {0xA2C7B373, 0xB793E7B5, 0xAAAA3DAD, 0x0CF91397, 0x0CDA6AB9},
	{0xB150B6B6, 0xEB338821, 0x8D0B4A42, 0xE12F0266, 0x1DE2DA43} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 293 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 294 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 295 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 296 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 297 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 298 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 299 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x34E6B347, 0xFC6BB08E, 0xE49E8FA8, 0x0F0A04BA, 0x093A3D93},
	{0xEE41E501, 0x5D856CB8, 0x814E34A4, 0x390D0CF0, 0x0ED168F7} } ,
	 { {0xE668EB83, 0x7988E12F, 0xD2CE5D74, 0xB012B511, 0x12981710},
	{0x5DF4A3C8, 0x538A8C57, 0x5DEEFBED, 0x51ED9659, 0x19AB4DDD} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x33352C8C, 0x53387C7A, 0x5062C35B, 0xD3FF16E7, 0x03E6CFE4},
	{0x52A28006, 0x8EE23A34, 0x87D950BC, 0x69B0D278, 0x17F501FF} } ,
	 { {0x512C0BE8, 0x8CE1CF95, 0x8962719A, 0x1C16E453, 0x197215A9},
	{0xCFF96048, 0x4CE7A03B, 0xD092F3EB, 0x6ECE16F1, 0x1409034E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8937698A, 0x8A45EA8E, 0x98EAE56B, 0xDC0B3633, 0x0AEC0C9C},
	{0xE68EB46C, 0xBEF9CAA0, 0xD7FBABDB, 0x03D742D9, 0x1A9401C2} } ,
	 { {0x77AD871C, 0xE8FB49BE, 0xFE88DA2B, 0xE6996732, 0x02EE9B28},
	{0x1B54B7BF, 0xDADDD660, 0xEBC252F8, 0x6ADFEFFA, 0x00D39479} } ,
	 { {0x4A9ECBA0, 0x74FA208C, 0xA50EF450, 0x744B6E12, 0x1EADB255},
	{0x64609B05, 0x315CCD7B, 0x068B1C18, 0x30A3C588, 0x09239908} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 300 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 301 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 302 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 303 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 304 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 305 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 306 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3D44420C, 0xB0C824D2, 0x62F973EE, 0x011F20D8, 0x21DF862A},
	{0x34F321B8, 0xAC3874CC, 0x14BB319E, 0x530C7048, 0x169C3FC1} } ,
	 { {0x95175B72, 0x30DADB5E, 0xCB044119, 0xBA8CFFF1, 0x028DBE55},
	{0x0EC66950, 0xFAB5BF0B, 0xFE2F53A5, 0xED6ABA38, 0x10AAB315} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xA92EA560, 0x62B5C565, 0x68243552, 0x91545BAD, 0x1C800C43},
	{0xB4FE9C66, 0x9E8DE01A, 0x3CCBD0B5, 0xBCEF9FBC, 0x216ABE40} } ,
	 { {0xD52D9B52, 0x297676E7, 0xBB293ECA, 0xBF4512FA, 0x0FFB9A39},
	{0x9CC39E9F, 0x6BF74077, 0xACD52491, 0xA245E14E, 0x0E933711} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0B4B24DA, 0x2004F31C, 0xAED9F2E2, 0x68B5A6A9, 0x1F16ECBE},
	{0x47933716, 0x4B3A482B, 0xE581D4EE, 0xA2D1AED9, 0x1D516DB4} } ,
	 { {0xDD921EDB, 0xA11BBFAD, 0x73D1D2FD, 0x694D70A1, 0x11B68D81},
	{0xB9C8C380, 0x8E06FB2D, 0x7DA0DFA6, 0x6AF27ADC, 0x068E55F9} } ,
	 { {0xB83AB5AF, 0xD01AF533, 0x3E758201, 0x3F8B96BB, 0x1EA1A61D},
	{0x800B7AAE, 0xF2556B4E, 0x28109F16, 0x69E32F74, 0x0ACE7E7F} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 307 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 308 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 309 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 310 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 311 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 312 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 313 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1CB17FBF, 0x46915762, 0x8BD6E07B, 0x0CF8F82B, 0x08A180D1},
	{0x454A8372, 0xB08211BD, 0xB8776E16, 0xA48A267D, 0x194624DF} } ,
	 { {0xB0D7F7FE, 0x78CE3E9C, 0x407D399A, 0xF613A5F2, 0x0BD7B984},
	{0x6AFC3B8B, 0x24A970F4, 0x9D6C838C, 0x155E920E, 0x1F2C30EE} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xF20E4F9C, 0xB244A6A4, 0x2CA05BED, 0x8A429F31, 0x12CFDA76},
	{0x86A5AF01, 0x37391AED, 0xDE92C481, 0x7DFA0C4D, 0x1E354302} } ,
	 { {0xC17B2737, 0x5EA837F9, 0x739F2BBC, 0x5314A7A5, 0x1098A383},
	{0x41A894C5, 0x0B201252, 0xCA56F725, 0xDA549FBC, 0x20153EC3} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xC5774719, 0xD9EAE7DF, 0x8CD1148A, 0x8D35F92C, 0x08A34C75},
	{0x12EE85E8, 0x6694155A, 0xD869CFD5, 0x10E0E18A, 0x1A3AEA4F} } ,
	 { {0xE4FC570C, 0x073F8896, 0x92AAE36B, 0xA06C32A2, 0x2063B9C1},
	{0xC1D581DD, 0x8E99ABB8, 0x1127BB36, 0x5214CC7B, 0x1ACF2E41} } ,
	 { {0xD55CCFDD, 0x6BB34F42, 0xA0C97B72, 0x7D49A705, 0x0A2E59A5},
	{0x415B2B8F, 0x86B70930, 0x261B566A, 0xD96FE5D0, 0x04EF1E22} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 314 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 315 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 316 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 317 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 318 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 319 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 320 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x4EB53BB3, 0xBBC0FE4E, 0x3353CF55, 0x19F52211, 0x10EFCC98},
	{0x5637B8D2, 0x9C64A36C, 0x3E9C0CDD, 0xF7214A78, 0x10D547C8} } ,
	 { {0xE3B5A5C9, 0xCE8A9910, 0x1CD4EC03, 0x76F96A45, 0x1D9D7330},
	{0xD46B1AA1, 0x592EA424, 0xA13C3551, 0x968C9E62, 0x09247A42} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x26883B2C, 0xD90C051B, 0xE4F5E071, 0x2DA26DDF, 0x1BC4E666},
	{0x314E08F1, 0x8190A559, 0x05A6FFD8, 0x5A67520B, 0x149EF5CE} } ,
	 { {0x415A220E, 0x88B0EE6A, 0x8399C65C, 0x77E11DC2, 0x1154B04B},
	{0x90963029, 0x759A2AAD, 0xF5169F45, 0xF07C820A, 0x1037823E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x58FA4586, 0x8C1E9D81, 0x1A590D70, 0x3013C1B8, 0x06E32AFB},
	{0x1CFE6417, 0x682FEB85, 0x7E419C33, 0xC7A78AFE, 0x14484545} } ,
	 { {0xB5F0AE7C, 0x0DE65754, 0x3DB76A17, 0x96E7D039, 0x19CBFD3D},
	{0xB7C21FFD, 0xF899419A, 0x27D3AA69, 0xFACD68D1, 0x06A0AD5E} } ,
	 { {0xD7D2FF79, 0x1D4B06CC, 0xB1A2111C, 0x13AD4BCE, 0x0AD519CE},
	{0xDB16501F, 0xE52C01EC, 0xC70AF2FA, 0x63460792, 0x03C9AE05} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 321 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 322 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 323 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 324 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 325 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 326 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 327 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6C0BD62D, 0x8859E435, 0xA74B06AE, 0x3C30FB50, 0x00D1B7E6},
	{0x74F19DDD, 0xAEAAEDB2, 0x59C4D5B3, 0x161C1328, 0x154928FF} } ,
	 { {0xD2413E04, 0xD1EF05AC, 0x7CDF2616, 0x5C368D33, 0x1579B740},
	{0xA63FFA93, 0x9F5F1482, 0x170E5BB5, 0x572D14ED, 0x1BE6762B} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x1C590EDC, 0xC76BDED1, 0x6D0E8BEC, 0x383EDE9E, 0x09168A61},
	{0x94A11176, 0x6F694CAF, 0x156F6D91, 0xEE1C39F1, 0x155E9764} } ,
	 { {0x49A07712, 0x85008FE3, 0xB04C0D9B, 0x5A30EF4F, 0x130F897B},
	{0x33BDA298, 0xB377E588, 0xF63D8AB7, 0xBB9B2046, 0x135FAF7D} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xF14D478B, 0xAFDFE159, 0x7B8D6FA5, 0x7ED47851, 0x183E6EE4},
	{0x4D63D571, 0x9377A3A0, 0xCAC8BFFB, 0x4281AF23, 0x16139816} } ,
	 { {0x021AABF0, 0xD910E5F6, 0x3CEB9798, 0x574389C3, 0x0E41C6DC},
	{0xB1A80ABF, 0x921A4F5A, 0x1910AA32, 0xE92ABB65, 0x1B918B1C} } ,
	 { {0xB04D38AF, 0x3F11FA9B, 0xC5C3853E, 0xFC0DE34D, 0x0844D27A},
	{0x1FAF7399, 0xC0BE5EFD, 0xBBAA97DD, 0xD80026C8, 0x00156E65} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 328 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 329 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 330 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 331 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 332 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 333 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 334 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xD9327556, 0x7C26D0B8, 0xE170F9FC, 0x38B2DE51, 0x0384C297},
	{0xA3483379, 0x9229DB07, 0xC2EBD2A1, 0x995E6571, 0x2328C56E} } ,
	 { {0x4D2029B3, 0xEBF09F99, 0xF6FB947E, 0xC27E32E4, 0x231857F5},
	{0xB8E84221, 0x3173937F, 0x2F6AA8F0, 0xA3D06FAA, 0x022EA6E4} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x76A9027F, 0x9B72CED0, 0x92271110, 0x90150A39, 0x036DDD4B},
	{0xB3165942, 0x72EAC06A, 0x0C08DCCC, 0xA7D34CF6, 0x1C5BF5BA} } ,
	 { {0xB124A48E, 0x6140B28B, 0x98A936CC, 0x1BF59969, 0x1B62A13E},
	{0xEEECB8D1, 0x9E678E1A, 0xBC6533FF, 0xF60E0FD2, 0x0105FC25} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xD05E1347, 0xD24415B1, 0x2721D933, 0x95A02519, 0x1407B2F0},
	{0x9A6D4A57, 0xD6F6F128, 0xA939F74A, 0xA22DCF1E, 0x122BA3D4} } ,
	 { {0xE6191A81, 0xC8A8F978, 0xAD46AD19, 0xADD9A33B, 0x0739FBE0},
	{0x64110EB0, 0x8BCEDAF8, 0x9AE10DBD, 0xD775AABF, 0x204A547B} } ,
	 { {0xE9C6DF84, 0x3D7952B7, 0xEA00D7B2, 0x06B887CD, 0x23EA3AB8},
	{0x5C1E7824, 0xFEEE3A03, 0x8267CAC8, 0xBDCB436A, 0x1D34504F} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 335 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 336 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 337 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 338 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 339 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 340 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 341 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC80398CC, 0x5FA7900F, 0x7E26FEFD, 0x21171B13, 0x0BB43AEE},
	{0xAE7FF45D, 0x7690E12A, 0x0BD8EBFF, 0xAD315E18, 0x125DA0D9} } ,
	 { {0x9259B36A, 0xA0A23A9C, 0x5C1E0464, 0x17ECF03F, 0x1E4E303D},
	{0xE6C135F2, 0xED3DB8C3, 0x911A0B38, 0x5636616B, 0x1F743DD7} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xAF704F66, 0x1FEC8599, 0xC9FDFD99, 0x6AA2C22D, 0x15F64E63},
	{0x8582C1DF, 0x27E3C4F6, 0xA27F96BC, 0xF0714950, 0x187765B9} } ,
	 { {0xB38BEE47, 0x66E6359F, 0xC9A4DAB8, 0x2BB0C040, 0x0C478D43},
	{0x80EB356A, 0xFEBBBDAA, 0xFFF1C415, 0x75752E7E, 0x217DE61E} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xBD578B58, 0xEB2BA3AC, 0xC89832E0, 0x476D7962, 0x177F1ED3},
	{0x951E06A7, 0x957B4A25, 0x7327685F, 0x30C4C4B0, 0x18EB96BD} } ,
	 { {0x1E7032E8, 0xCBAD9EF1, 0x4FC07A97, 0x8FB3535A, 0x108A46FE},
	{0xE84DC7EF, 0xC62D605F, 0x3603DE95, 0x8F8F2C34, 0x207907D4} } ,
	 { {0xE76CB69A, 0xC044F589, 0x4BD6FE9B, 0x498BA71A, 0x0A421375},
	{0xD702CD82, 0xB152E3CB, 0x96A6AABC, 0x433FEB38, 0x0619C4E0} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 342 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 343 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 344 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 345 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 346 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 347 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 348 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6C3355CA, 0xC47867ED, 0xB5D713C3, 0xC1A67EE6, 0x0E525316},
	{0x1E8FA009, 0xA6CD3A9D, 0xF5F1D21D, 0xBF910928, 0x0F9BCA4F} } ,
	 { {0x92008ACD, 0x62792B7A, 0x9DBF3B55, 0x8B2DD2F8, 0x01177282},
	{0x25AE7B9E, 0x08574341, 0x8754378D, 0xD33B2BB2, 0x217B7816} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0x6E7DD2B1, 0xB47FAA5C, 0xC9ADC596, 0x121F2885, 0x0B33F950},
	{0xA1186A10, 0x3D27ABD1, 0xE7E969BB, 0xFCD22038, 0x2176AF5F} } ,
	 { {0xEC77908E, 0x399A5B57, 0xC44FB420, 0x4066DAA6, 0x115D58E5},
	{0x0208E739, 0x8CC69FF7, 0x47751331, 0xA558EDE1, 0x2171FC8A} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xBD8DB4D0, 0x39014201, 0x1B782ABB, 0xBFE11419, 0x0FF7C6AE},
	{0x672ABF6A, 0xE9A108BD, 0x74820894, 0x816FF7FD, 0x042A6D1D} } ,
	 { {0xAD6EFAD9, 0x8FA51478, 0x9E5FBD17, 0xEE953196, 0x0D5BB023},
	{0x5ED4C158, 0x3159DA3A, 0xC9162E17, 0x6F1A16E2, 0x1CEF09FC} } ,
	 { {0x4E9ACF42, 0x0E34970F, 0x4D217271, 0xFFCF0585, 0x20E2C63C},
	{0x8288CA07, 0x965A7134, 0xF1F7979D, 0x3D41170F, 0x11DAE510} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 349 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 350 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 351 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 352 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 353 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 354 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 355 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xFB8446D4, 0x0BC1D8D8, 0x3EC15448, 0x58847FA0, 0x19A43916},
	{0xE04DE0B4, 0x6A395DEE, 0xA8CB0C6F, 0xF0FAC147, 0x04B691D9} } ,
	 { {0xB69B435A, 0x338AC867, 0x3ED96AEC, 0xEFA2A796, 0x100D9938},
	{0x768A68EE, 0xBCB0BBAB, 0x07D7DB3A, 0xCDCD66F1, 0x013444BC} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xCA8B2D64, 0x3DFDABA5, 0xB9BEF85B, 0x626CB681, 0x1B264DCE},
	{0xA71C9C8E, 0x218B50C7, 0x0A0B28C2, 0xD6ED577C, 0x182D8780} } ,
	 { {0x7895069A, 0x2A1A295C, 0x095D0CF1, 0x8D046BB5, 0x0CD858F0},
	{0xD48F9DF7, 0x420EEC2A, 0x7BCBD1D7, 0x262DB108, 0x1DD04B99} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0333C412, 0x81D00E9A, 0xC51A87C1, 0xFF1EA581, 0x1D886ED6},
	{0x154045C6, 0xB2ED3893, 0xDAD465E3, 0x52777F9F, 0x0924B6C7} } ,
	 { {0x2A20984B, 0x42DF354F, 0x772721EC, 0x4C8CBA0C, 0x0629BD4B},
	{0xC9964883, 0xEA09CA0D, 0xF7831889, 0x85CBDAEB, 0x02992D0A} } ,
	 { {0xCF06E690, 0x323BD2CC, 0x7AFDA413, 0x09E836E1, 0x018214B8},
	{0xC6CEBBDA, 0xB751F2D8, 0x61401C52, 0xE5F29634, 0x1376F5A6} } ,
	0};
		ecfp2_add_proj(&var_res_proj, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_add_proj 356 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_add_proj 357 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_add_proj 358 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_add_proj 359 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_add_proj 360 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_add_proj 361 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_add_proj 362 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD13BCEAB, 0x43F78F10, 0xD166FAB7, 0x8D1831C3, 0x20BF5C15},
	{0xFFC023FC, 0x9993213A, 0x58F7B2A1, 0x9D9E2074, 0x1929AA09} } ,
	 { {0x8BE6B407, 0x916B1455, 0xDC18284A, 0x51C28846, 0x084E74B5},
	{0xD133BCB5, 0xB78B5A4D, 0x0B21B759, 0xD6E6B9DA, 0x193586FF} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xD13BCEAB, 0x43F78F10, 0xD166FAB7, 0x8D1831C3, 0x20BF5C15},
	{0xFFC023FC, 0x9993213A, 0x58F7B2A1, 0x9D9E2074, 0x1929AA09} } ,
	 { {0x8BE6B407, 0x916B1455, 0xDC18284A, 0x51C28846, 0x084E74B5},
	{0xD133BCB5, 0xB78B5A4D, 0x0B21B759, 0xD6E6B9DA, 0x193586FF} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD0A9D0C4, 0x74E4D09F, 0xF6BE07BB, 0x21C75CAF, 0x0DC77317},
	{0xB39E357A, 0x2E1C4326, 0xA861EE43, 0xD3647696, 0x019B4567} } ,
	 { {0xBDD34490, 0x4F2ECE09, 0xC41B82DB, 0xBEF3C4AF, 0x118C3994},
	{0x6EEE5FAE, 0x7AFCCD34, 0x420CE146, 0x298E3544, 0x1BCC3727} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5344 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5345 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5346 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5347 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5348 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC5981035, 0xC119C7F7, 0x8BA742A1, 0x6B864271, 0x1FC94346},
	{0x30CA3ABC, 0x2CD55714, 0xDB5C0323, 0xE73FFC2F, 0x1BBE00E6} } ,
	 { {0x2720CC77, 0x2297638C, 0x24F25B37, 0x1DEBED5D, 0x08F6E4C6},
	{0xE4EA8E3E, 0x0033692E, 0x5735AAE5, 0x2D24AD13, 0x0EF24873} } ,
	0};
		static ecpoint_fp2 var_b = { { {0xC5981035, 0xC119C7F7, 0x8BA742A1, 0x6B864271, 0x1FC94346},
	{0x30CA3ABC, 0x2CD55714, 0xDB5C0323, 0xE73FFC2F, 0x1BBE00E6} } ,
	 { {0x2720CC77, 0x2297638C, 0x24F25B37, 0x1DEBED5D, 0x08F6E4C6},
	{0xE4EA8E3E, 0x0033692E, 0x5735AAE5, 0x2D24AD13, 0x0EF24873} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x1CD12A1B, 0x52016338, 0xF8971F14, 0x93C0B4E0, 0x04EA5D30},
	{0x50067F67, 0x64BEBD76, 0x5FFF47AF, 0xA0AF3D52, 0x1EAEEDAB} } ,
	 { {0xC87A3DAA, 0x35427A86, 0x0928B0B4, 0x38063EFF, 0x20B57F4F},
	{0x9385E1A2, 0x003E223D, 0xE0C5DCB0, 0x14788B17, 0x1E201FD8} } ,
	0};
		ecfp2_add_affine(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_add_affine 5349 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_add_affine 5350 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_add_affine 5351 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_add_affine 5352 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_add_affine 5353 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3A665708, 0xBB6416DC, 0xFEC1D9AA, 0xC33F844F, 0x227F0298},
	{0x19A5C63C, 0x88E3A6E0, 0xE2627172, 0x5C494B2F, 0x0BC8C69E} } ,
	 { {0x7DF48E47, 0x61FAECAA, 0xAA87D8D8, 0x085BE037, 0x1D189956},
	{0xEE7A2135, 0xBC89991F, 0x9AF9D0A5, 0x002B22D2, 0x0930E75D} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x47647649, 0x0CBE3EDA, 0x0DBC1264, 0x07FC1D4B, 0x09F077BE},
	{0x0BFBD0AA, 0x3BA570DE, 0x74B5FC7A, 0xC8DEA27E, 0x19E70943} } ,
	 { {0x067E9F28, 0xB2846D24, 0xC60B1360, 0x3050C28B, 0x0E510E3D},
	{0xE6082086, 0xBF4F2618, 0x1D882CC0, 0x2D1D13D9, 0x122D66DB} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5354 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5355 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5356 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5357 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5358 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xD93A95D7, 0x9E1393E1, 0x99E97209, 0x5DCA8AF5, 0x0F87852C},
	{0x6ACA14A2, 0x6B2C97BD, 0x53E9CF21, 0x4C59BCCD, 0x0BDC8761} } ,
	 { {0x3BA65F31, 0x1F9A2AC5, 0x88204A16, 0x8C065D72, 0x2006596E},
	{0xB5B20AE8, 0x34D729AD, 0x7313E52E, 0xF538F565, 0x0E34C2AA} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC1AE905D, 0x9DE8826B, 0x3CA26006, 0x69CD70A4, 0x0E99A85C},
	{0xF3004112, 0x1A47419E, 0x8A671448, 0x678622D0, 0x110FCCB9} } ,
	 { {0xC6041123, 0xADBD7819, 0xD9E1949A, 0x28670DF0, 0x008D5C6F},
	{0xF2C5F068, 0x555359AF, 0xE0CABB1D, 0x134B5A74, 0x04B5FAF0} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5359 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5360 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5361 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5362 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5363 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x852C2472, 0x9459FE2F, 0xE1D31A92, 0x3F270116, 0x0ED3EC32},
	{0xBD87EE32, 0x8909DBC9, 0x626A7B88, 0x980BA431, 0x181C4822} } ,
	 { {0xB79D95DF, 0x081BA9EA, 0x02708807, 0x87DCBC24, 0x09D0F2A9},
	{0x73CEEEA1, 0x1C7DBB40, 0xE4F11F13, 0x1C3041DA, 0x15A907A9} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x5AF1769D, 0x6A662E32, 0x70A3D665, 0x56FA5E92, 0x173951BB},
	{0xE21069BC, 0x4EB5DB4F, 0xDCA70A0B, 0xB478DC78, 0x14DF08D3} } ,
	 { {0x4178E7E2, 0xAE82CC7E, 0x0D9B98E5, 0xCDFAD48A, 0x21DE097B},
	{0x597C0332, 0xAB801179, 0x5875098F, 0x1D67EF5D, 0x02B54A9A} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5364 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5365 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5366 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5367 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5368 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA8C5BB57, 0xF202DCE8, 0x87EC79AB, 0xD7C52209, 0x07CB382A},
	{0x9BBF2578, 0xAF06B6C9, 0x2336D20A, 0x13A60AAE, 0x0640B5A6} } ,
	 { {0x4ACF950F, 0xC1A392BC, 0xD6F789D1, 0x19B9BE0B, 0x142A7FF3},
	{0x649C20AA, 0x21FF8E46, 0xE3ACB1CE, 0x89671BF4, 0x0056D697} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xBB377097, 0x09DC7C0F, 0xB44E552D, 0x7CCE0F40, 0x04BBC7FF},
	{0xD20983B2, 0x6360737D, 0x228DC5B4, 0x95AC3A7B, 0x0717465E} } ,
	 { {0xC47A1615, 0xB12E85CE, 0xC504D1FA, 0x97CC0363, 0x08586C99},
	{0x198718F2, 0x46F249C3, 0x8004A320, 0xC0E3BA55, 0x0126C10A} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5369 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5370 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5371 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5372 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5373 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x05878AC3, 0x4251C624, 0xE0F6357F, 0x86A195F5, 0x1DE28050},
	{0x88D550AA, 0x500E12FB, 0xB3D262F3, 0x3ED41341, 0x1E2E05CD} } ,
	 { {0x2E550047, 0x1CF0D174, 0x0F233BD8, 0x38D17354, 0x146CEAA3},
	{0x187FA433, 0xEDA28477, 0x2D0B812E, 0xD5521AEE, 0x1585DFD0} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x75F1D1C2, 0x38D39DD7, 0xF0173AEB, 0x799098AE, 0x001D4F16},
	{0x440BE54A, 0xDF0D0E51, 0x90D0313F, 0xA27CF248, 0x201BB88A} } ,
	 { {0x6B32FFA3, 0xC474170B, 0xF895B45D, 0xBE43A6F7, 0x1ACA60F5},
	{0xBCA49E20, 0x9D33E543, 0x58E26714, 0x3DFE6294, 0x0BD6EB21} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5374 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5375 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5376 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5377 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5378 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE7DB76CC, 0xF54B5D8E, 0xDB703326, 0x7B04A288, 0x0724A917},
	{0x3D1AC46C, 0x52916A84, 0xA27B6B7B, 0x372BA54F, 0x0711DDFE} } ,
	 { {0xBEAADC66, 0x0FD5F005, 0x9F22B936, 0x4DCD69D4, 0x05BBF477},
	{0xF1D585A9, 0x8BE34C4E, 0x68C413AD, 0x4F63A686, 0x036BA3DC} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC4D3764C, 0x82428CB6, 0xF8D0334B, 0x4C55A70D, 0x1C547C94},
	{0xFE64DDEB, 0xC078EAA1, 0xB0852D46, 0xF2B8740E, 0x1BF12A75} } ,
	 { {0xBE4034B7, 0x8506F4C7, 0xD2690259, 0x9A0ACF5E, 0x0FF05CB4},
	{0xAFC7C93F, 0x4DFA8142, 0xCDB4E317, 0xAF8D0D58, 0x13D25631} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5379 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5380 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5381 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5382 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5383 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4C59A15F, 0x5AB515CE, 0xD95432B8, 0x0AECE424, 0x230846E6},
	{0x5E5C51B9, 0xB8F31956, 0xF03EBDE1, 0xE076E6C7, 0x11BF1BC0} } ,
	 { {0xC06A1C7E, 0x7E67D10A, 0xE0C73FD5, 0x0A74537F, 0x1E76F87A},
	{0x55850FCD, 0x8C56E0DD, 0xE289E672, 0x9254300F, 0x0B66C4ED} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA533965F, 0xA9445A14, 0x9CE96A45, 0xEA5DDF6E, 0x029104D4},
	{0x28A06667, 0x554D2DC8, 0xE5452567, 0x9CD61BD6, 0x126AE931} } ,
	 { {0x8364872C, 0x30C98841, 0x1892EE4B, 0xD97EFFA8, 0x087E1A78},
	{0xB315BCCE, 0x682F8BCB, 0x1F462CC5, 0x2735F76E, 0x21E211DF} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5384 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5385 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5386 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5387 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5388 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0CD06BE3, 0xADF72AB9, 0xFE0C05A5, 0x6A945678, 0x21642322},
	{0x71685B98, 0xD4D7336F, 0x2427E4B9, 0x48E7C8EC, 0x03AD95AE} } ,
	 { {0x7CFB540C, 0x006A4212, 0xE7ECA1F5, 0x4EA32DBB, 0x03B6AA50},
	{0xECF7CD7F, 0xDB4D9937, 0x932A0467, 0x06757C7E, 0x0DB922C4} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xD40E03C3, 0x9C614866, 0xCDA16284, 0x898B70C8, 0x0CE4BE8E},
	{0x4970CBBC, 0x81A1FE69, 0x1D3BB85F, 0xE2D93D2E, 0x0266C6C3} } ,
	 { {0xB8C0972A, 0x7987D63F, 0x3DAEDA71, 0x028D264F, 0x20BDFEB6},
	{0xC7B5FD4E, 0xE34FF6D8, 0xA815A188, 0x899BB982, 0x16BCFB21} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5389 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5390 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5391 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5392 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5393 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA7F0CC49, 0x800B49FF, 0xFDCA98F3, 0x29A76CF6, 0x09E54F2D},
	{0x932F7A76, 0xEDDBEE5A, 0x747FCC53, 0x9447981B, 0x1DC92B34} } ,
	 { {0xEAFA335B, 0xA0AC7F7B, 0x01B2CBCF, 0x9DE0E4E2, 0x195BF955},
	{0x9E5E07F0, 0x62853943, 0xF3006F2D, 0xB148FBD7, 0x061AFD4B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xAFC46CA6, 0x28D81636, 0xDE57F7C0, 0x1BC44543, 0x0C4FD2A6},
	{0x4573AAD3, 0x58E94DE2, 0xEA0D169D, 0xD3109FFD, 0x1288B695} } ,
	 { {0xF9AB0038, 0x3426432E, 0xA9DC9F84, 0x7D550154, 0x080B8D1D},
	{0xCE01D163, 0x48656E6A, 0x8BF09597, 0x3A264BFB, 0x1AC52521} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5394 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5395 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5396 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5397 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5398 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xB8096533, 0xCD5CC160, 0xFC9A74A3, 0x13E3472A, 0x15841BD2},
	{0x2C83425A, 0x0C133EE6, 0x2FEA40DA, 0xFBFE29F0, 0x064BC731} } ,
	 { {0xDA1EFF3A, 0x11922DFB, 0x3462F6C7, 0x42AE850E, 0x04021D5C},
	{0xE620B601, 0x16769303, 0x6F71020C, 0x9E2B6546, 0x1732B8E6} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x819F4D5C, 0x75953A68, 0xA66140B6, 0xB2663687, 0x1A7A2EDF},
	{0xA7294759, 0xF4E68C3E, 0x3A17DAC7, 0xD99C88C5, 0x18E6163B} } ,
	 { {0x938988BF, 0x40C075CC, 0x9F8D2058, 0xD99DC414, 0x16330511},
	{0x48F903C9, 0xF8C41597, 0x50EDA30D, 0x4268FEF3, 0x014A87C7} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5399 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5400 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5401 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5402 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5403 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4F4D5377, 0xA1E12199, 0xE0F39901, 0xB77445C6, 0x018C7818},
	{0x6B23875C, 0xD028211C, 0x62232EC1, 0xC33C1444, 0x13CEE5CB} } ,
	 { {0xCE942DF0, 0x1C38587E, 0x4EFECA16, 0xDF767C7A, 0x037DFEE6},
	{0xABB1CD11, 0x3ED6B79D, 0x1D27A7B7, 0xDF99049B, 0x11FE804F} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8A29E3DB, 0x57E8EF42, 0x73D874F1, 0x95FC338B, 0x1ED0C0BF},
	{0x12F986B4, 0x4E04179D, 0xB6D62FFE, 0x68E43C91, 0x150BE6C2} } ,
	 { {0x4AB7058F, 0xC0868154, 0x739ED732, 0x26BE08C7, 0x197FDD1E},
	{0xAA354293, 0xFC8EBE9F, 0xB1536953, 0x097B0214, 0x0931AAF3} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5404 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5405 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5406 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5407 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5408 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2888B1BA, 0x47BA128B, 0xB2466E4F, 0x74FB9760, 0x1B1FEFE9},
	{0xC66E6264, 0xDC477FD5, 0xF429997D, 0xFF33A601, 0x14F6532F} } ,
	 { {0x7AB8AF35, 0xC092B331, 0xB0207B87, 0x339BA201, 0x0F50A3AC},
	{0x0CEA32EA, 0x6FA8DB39, 0x3C814699, 0x74C50392, 0x0AA47318} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xF7BB0D3A, 0xAA57827E, 0xB0634D27, 0xFC2353C9, 0x040FBE60},
	{0x8AF9F2D1, 0x89697392, 0x56B3DE9F, 0xE4F1E0A6, 0x124460A4} } ,
	 { {0x5B37460F, 0x4DDC80BD, 0xF02D76A3, 0x6B203D2A, 0x109F5886},
	{0x15E3054A, 0xA827DAD3, 0x1CE0C76A, 0x1D42A581, 0x0674BFBC} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5409 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5410 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5411 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5412 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5413 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xAF65CF54, 0x554B2CD2, 0xA316F4F9, 0x00F1ABAB, 0x02CCAA00},
	{0x272D758F, 0xF999BC85, 0xEA8315A5, 0xF8A22BCC, 0x11357AD8} } ,
	 { {0x6B6FFDAC, 0x189378A1, 0xA3C05738, 0x5D54FE3F, 0x09C3D35D},
	{0xDF1771DC, 0x3040A804, 0x863C8CE9, 0x02332DF7, 0x02FFFE67} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xA242B62E, 0x0E8660D1, 0x3C2B92B1, 0x52CBAB31, 0x22D62426},
	{0x405F6257, 0x91B8101A, 0x33694B99, 0x997317DB, 0x193FA968} } ,
	 { {0xB0D303D0, 0x9F4A4D22, 0x1F78486F, 0xDD2398AE, 0x06F597AE},
	{0x9A926A7C, 0xAD9DE758, 0xCA7D7DB0, 0x3138753D, 0x13E80C56} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5414 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5415 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5416 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5417 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5418 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x09F10862, 0x1B5F49B0, 0x4980DB7A, 0x26AB53A6, 0x13896CDF},
	{0x54270AA6, 0x444D4202, 0x75DA1860, 0x1017EF5F, 0x07F6027C} } ,
	 { {0x78E5C064, 0xF5173293, 0x3FAA2610, 0xA5A5F25E, 0x18C52BA5},
	{0xF0D86D71, 0x98F51AF2, 0x1C0376DF, 0xFDAFA2EC, 0x0A42713C} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x86501235, 0x282A7C07, 0xF634663D, 0xBDBF5737, 0x014BEB8E},
	{0xF365F4DE, 0x24FBF008, 0xB4E82DDF, 0xEB326DE3, 0x1E1B021B} } ,
	 { {0x49505B9A, 0xBE10E53A, 0xA2ED593B, 0x872757D4, 0x1FC9706C},
	{0xFB6F224A, 0x099BC593, 0xB6C8B619, 0x55311391, 0x164300AD} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5419 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5420 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5421 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5422 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5423 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2A06A482, 0x447E3206, 0xB8AE5A61, 0x026BA83A, 0x1276DB61},
	{0xE80A5E45, 0xA92F61EF, 0x95FFF580, 0x9997E6F5, 0x0EEC2713} } ,
	 { {0xF4EA4151, 0xAE2F5D83, 0x86EA8A2E, 0x895D19D6, 0x225DF9BD},
	{0xC1019A36, 0x027BE386, 0xCA65071A, 0xA23A91C6, 0x11579921} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x371E6A07, 0xF3EBAE6B, 0xE18610D3, 0x3B7E152F, 0x086EA7CA},
	{0xECF622EC, 0xE690B4FE, 0xA6C19121, 0x79BD432D, 0x11E167C7} } ,
	 { {0x4C670BE1, 0x93A707A3, 0xEFD108C1, 0x2184CBFF, 0x1BDA47BA},
	{0xFFD608BF, 0xF572B205, 0x9BF30BB5, 0x698C4E7C, 0x1A2277A6} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5424 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5425 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5426 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5427 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5428 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xBB613CE8, 0x9DA67053, 0x7D3F7432, 0xB420F647, 0x13F18ADC},
	{0x64B67E1C, 0x7E2140D0, 0x0C989D40, 0xA1A13B9F, 0x11AFC576} } ,
	 { {0x1A45409C, 0x1A550C3E, 0x0D14AB0B, 0x6268859A, 0x13817273},
	{0x18EB37CA, 0x79E10C4B, 0x8C163861, 0x646A9AB2, 0x2105D8DC} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x4CAB5785, 0xADBBA9B2, 0x926A736E, 0x9DE3AD04, 0x1A5673C3},
	{0x84DA46AA, 0xD6C26026, 0xB23BF618, 0xC34283C7, 0x15AF48CF} } ,
	 { {0xA5FA14DE, 0x2B69DC6B, 0xDD269100, 0x2D9DE85B, 0x182F85FE},
	{0xAD95B051, 0x00D238BD, 0xF54DC955, 0xD0C56331, 0x0F298FC2} } ,
	0};
		ecfp2_dbl_affine(&var_res, &var_a);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_dbl_affine 5429 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_dbl_affine 5430 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_dbl_affine 5431 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_dbl_affine 5432 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_dbl_affine 5433 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA652771C, 0xCDFB12AB, 0xA6C88597, 0xE2FC6833, 0x17702108},
	{0x48793548, 0x1F6A94B3, 0x93988262, 0x2027D42E, 0x1630A189} } ,
	 { {0x111D8D84, 0x3DCC1B81, 0xDB23F57A, 0x5F3DF817, 0x22B02064},
	{0xFC7FB0B8, 0xB64D79B3, 0x70C31FDD, 0x03FF93FB, 0x08BC847B} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x682ABBC4, 0x9BD94D8E, 0xF6CB565E, 0xF2C88FD5, 0x168634EF},
	{0x91321BEF, 0x1CFFD743, 0x625A204A, 0x77B569C9, 0x0631DDE3} } ,
	 { {0x3596A9F1, 0xCFB32102, 0xBAC46016, 0xB8EEB588, 0x1C60ECBD},
	{0xEDFE2003, 0x9498635A, 0xFB0FFEC1, 0xE07631FA, 0x15E216AC} } ,
	 { {0xD5EAC8AD, 0x5D6AE261, 0x7CFD2A56, 0x0F259449, 0x215F20C5},
	{0xF8FF6170, 0x6C9AF367, 0xE1863FBB, 0x07FF27F6, 0x117908F6} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5434 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5435 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5436 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5437 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5438 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5439 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5440 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3C5A851D, 0x354D50AB, 0x88CC3D01, 0xC3F4A8D9, 0x192EA7E8},
	{0x182C0E17, 0xB0FE59EE, 0xE7F31F26, 0x8F2236AC, 0x1397964D} } ,
	 { {0xE92ADC1C, 0xD81BA090, 0xC6B64ED4, 0x70E7695E, 0x1230EA0E},
	{0xF1C31F7C, 0x46F8DD75, 0xA3D3B58A, 0xEC98E5B3, 0x17AF57B1} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x42BADFCC, 0x8C0B0FD8, 0xB278D475, 0x7D3E99F8, 0x01BB8AB8},
	{0x712F0D21, 0x7585F879, 0xB14F23B4, 0xCB5CB3A6, 0x0CD9431E} } ,
	 { {0xF1B3F769, 0x75CC7E2A, 0xCBC22223, 0xF07AB731, 0x0B23AA56},
	{0xC2ECA318, 0xE31D6A9F, 0x6E78A5F5, 0xFECE685F, 0x0F9E68CF} } ,
	 { {0x860565DD, 0x9209EC81, 0x5421DD0B, 0x327876D7, 0x0060B419},
	{0x9735EC9D, 0x6FC4664B, 0x0E5CAA76, 0x29DB6F81, 0x0B5D8F60} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5441 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5442 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5443 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5444 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5445 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5446 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5447 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9D27F7D2, 0x10A62A5F, 0x593535A9, 0x4BAACF66, 0x1C58F64E},
	{0x6D03D3A5, 0x044A5B76, 0x089C2D0E, 0x8E1521FF, 0x1F2C8972} } ,
	 { {0xD72E3BD6, 0xD38DDAE7, 0xA3214845, 0xD252365F, 0x1618A202},
	{0xC7A48112, 0xFEF9031A, 0x61ED6BCD, 0x8DF4C79F, 0x0CB79324} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x7DAAF4B9, 0x9D9FA0F3, 0xA37D46A2, 0xB794BAEF, 0x10405D29},
	{0x4AB02ADB, 0x5C7DE205, 0xF83CCF6B, 0xEC517622, 0x1D5BB38F} } ,
	 { {0x5D16E401, 0x9F016B5B, 0x885372D6, 0xC8CF3E4A, 0x0CD5C20C},
	{0x94FD3247, 0x1212FDDA, 0x6E37CD8E, 0x146E0F9E, 0x14BF0D3F} } ,
	 { {0x620C2551, 0x88EE612F, 0x0CF7CFED, 0xF54E10D9, 0x08302401},
	{0x8F490224, 0xFDF20635, 0xC3DAD79B, 0x1BE98F3E, 0x196F2649} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5448 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5449 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5450 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5451 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5452 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5453 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5454 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB9C7FA4A, 0xE6761232, 0xEDC3C838, 0xA1E3AD86, 0x08EF03EB},
	{0x052710CE, 0x17E453C9, 0x994A50B7, 0x9C90EA2B, 0x153A79E0} } ,
	 { {0x6E1C2515, 0x61945D95, 0x4C7967DA, 0xF0E646A9, 0x02CCAE9F},
	{0x89A5F46C, 0xEA3AA5DF, 0xFCD2F4A7, 0xF1F63C96, 0x13888C21} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xCBD57474, 0x25995535, 0x9D92B83B, 0x108EC8D3, 0x08773EB4},
	{0x4E67ED85, 0xD6E68CB6, 0x6C8CEBA0, 0x7A50B2B7, 0x0BD76786} } ,
	 { {0x83706B4B, 0x1CAFCCE7, 0xE03D1FAC, 0x7A6327D4, 0x15FE2005},
	{0x037A819E, 0xD939D07E, 0xF6E24F78, 0xB3B2B2EE, 0x18B4D588} } ,
	 { {0xDC384A2A, 0xC328BB2A, 0x98F2CFB4, 0xE1CC8D52, 0x05995D3F},
	{0xC6FB967D, 0xB647F71E, 0xC05B28B1, 0x34961D47, 0x030FF840} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5455 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5456 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5457 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5458 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5459 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5460 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5461 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xCA803F00, 0x2D5D7E74, 0x627C75BD, 0x841176EB, 0x1282F196},
	{0x48A84D1F, 0x754E5C08, 0x453ED8D7, 0x19C0B5A0, 0x2184FC1C} } ,
	 { {0x77EF9CD4, 0x3A907222, 0x2151CAB0, 0x8983CF4B, 0x09166C51},
	{0xF720FE48, 0x847429D3, 0x21BF5523, 0x158AF81A, 0x11769CDE} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x2F06893B, 0x3F0C783A, 0x224FEDE3, 0x1C628FC5, 0x223AAE9E},
	{0xBEADDB70, 0x72EEB53C, 0xE01E3249, 0x69C47DC9, 0x14094DAE} } ,
	 { {0x3FAFDDB2, 0xCD83888B, 0xE16AB578, 0xDD7B02A7, 0x1F29CE30},
	{0xADFCF99A, 0x23AC1021, 0xA0310ECA, 0xB6132D2B, 0x1CF43A15} } ,
	 { {0xEFDF39A8, 0x7520E444, 0x42A39560, 0x13079E96, 0x122CD8A3},
	{0xEE41FC90, 0x08E853A7, 0x437EAA47, 0x2B15F034, 0x22ED39BC} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5462 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5463 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5464 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5465 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5466 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5467 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5468 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x27196CA0, 0xAD2049EC, 0xA1444253, 0xF4281EA6, 0x0CAF1A37},
	{0xFD879FBD, 0x2CC50964, 0x4E75ACC1, 0xBC38CE21, 0x053112C3} } ,
	 { {0xCA40E586, 0xD29FDE72, 0x975F27CD, 0xFE33A8B4, 0x0C14CA41},
	{0x5F2447FE, 0x791CA3CA, 0xCC58D300, 0x4DDAD51F, 0x1148AEF2} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB756B7D9, 0xFAECAF39, 0xBD2F08CD, 0x298D280D, 0x23B018A2},
	{0xBD683901, 0x9846D6BB, 0x2A230F35, 0x0B118F85, 0x11BCA106} } ,
	 { {0x9581DFEE, 0x27E2726D, 0x0A0480C8, 0x4828EB97, 0x0F475EF4},
	{0x9830BDB4, 0xB971E75C, 0x5EB9CEAD, 0xFF6B6CD2, 0x0FE68EE8} } ,
	 { {0x9481CB0C, 0xA53FBCE5, 0x2EBE4F9B, 0xFC675169, 0x18299483},
	{0xBE488FFC, 0xF2394794, 0x98B1A600, 0x9BB5AA3F, 0x22915DE4} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5469 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5470 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5471 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5472 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5473 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5474 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5475 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x836403D9, 0xE719D325, 0xE44BA1A4, 0xFE9B6007, 0x1839F01E},
	{0x57D7F772, 0x5196014D, 0xAFA224D8, 0x65C6CE36, 0x05B33B03} } ,
	 { {0x49ECFA02, 0x4FFB0818, 0x09F6255D, 0x53AE3B57, 0x0D1DAADE},
	{0xAF3B1E8B, 0x266AA5A9, 0x0E11D862, 0x5C7C30A6, 0x21E20DC5} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xD6561F9D, 0x9946D721, 0x2EB09E6A, 0xBE7DF29A, 0x02B7B0E6},
	{0xC0CD33D4, 0xB8C75533, 0x899C2FCC, 0xE7DEE2CA, 0x196514FD} } ,
	 { {0x6065032F, 0x562F5872, 0x95985710, 0x16FB0A84, 0x02E3AAB9},
	{0x6040B5A4, 0x99E0BE28, 0x0D0E05DA, 0x8557D46B, 0x06D63F63} } ,
	 { {0x93D9F404, 0x9FF61030, 0x13EC4ABA, 0xA75C76AE, 0x1A3B55BC},
	{0x1225EABB, 0x2EA7F6B3, 0xE2D8F026, 0x09A20565, 0x1FC2FB87} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5476 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5477 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5478 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5479 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5480 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5481 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5482 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x09D008A5, 0x377ACA87, 0x9FB16CF2, 0x77DD30E0, 0x19D26F1A},
	{0x798C71A0, 0x5CD75E95, 0x150084BB, 0x60CE40DC, 0x07642775} } ,
	 { {0xDBD6225C, 0xB12073D2, 0x3429B6A0, 0xB0C90BDE, 0x0C539F30},
	{0x5F677CB2, 0xDB961AF2, 0xBC19D4AD, 0x72800EC0, 0x0E097C84} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA2D93868, 0x3532DD8D, 0x0F543346, 0x7C681F30, 0x0EE013B5},
	{0xCBAF3EC5, 0x9414BE0A, 0x27271514, 0x16392BC8, 0x2357B563} } ,
	 { {0xCF41DB14, 0x54C18D71, 0x9F359BA3, 0xE35013EB, 0x1874F718},
	{0x8DBDAF92, 0x6D38C66D, 0x37E82A44, 0xD3853EDD, 0x23646F73} } ,
	 { {0xB7AC44B8, 0x6240E7A5, 0x68536D41, 0x619217BC, 0x18A73E61},
	{0xBECEF964, 0xB72C35E4, 0x7833A95B, 0xE5001D81, 0x1C12F908} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5483 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5484 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5485 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5486 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5487 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5488 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5489 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x94EC419C, 0xD2040FB8, 0x49FF0344, 0xA5746FD4, 0x14B0096D},
	{0x7EF9157C, 0xD937EEF0, 0x4BE36B50, 0x844760DC, 0x22A09FEF} } ,
	 { {0x33AD8F43, 0x8524A29E, 0xBDD75C48, 0x82437E69, 0x183C0ABD},
	{0xCD5152C4, 0xAF953DDA, 0x341F2326, 0xF5635796, 0x1B02D2A7} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x0B6D316F, 0xCED51058, 0x0BFBA1DD, 0x4119C35B, 0x1234F25A},
	{0x38FDF2F4, 0x923391FA, 0xE7C3DD19, 0xFD95D1B5, 0x1E10FE38} } ,
	 { {0xB50D5EEE, 0x5B664957, 0x02207A51, 0xC0440442, 0x1676DE7E},
	{0xA7EC524C, 0x079F1C22, 0xF24F533D, 0xA771803D, 0x21FAE2FA} } ,
	 { {0x1B0ACC2B, 0xEC1BF09C, 0x4263F7F2, 0x5530A0ED, 0x0C76F577},
	{0x4E52532D, 0x40FD2715, 0x2EF385AF, 0x3B705346, 0x1204854C} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5490 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5491 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5492 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5493 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5494 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5495 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5496 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA9D126E1, 0xA1DB44B6, 0xB55EB9D3, 0xBDFBC4A6, 0x1B9F38A3},
	{0xD3C79CA1, 0x49493C22, 0xF373ED13, 0xF95AAFD3, 0x03CF0350} } ,
	 { {0x02AEE489, 0xE7F97295, 0xC918C0B6, 0x02EDE398, 0x1A25AD19},
	{0x2BB2EA3B, 0x712A923F, 0x8950B904, 0x631F588A, 0x078AF8B9} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x8977AF99, 0x1E3E5E46, 0x5A97B482, 0x617AFD38, 0x129255F7},
	{0x2856E476, 0x926EE5E2, 0x3C2B9058, 0x0C627E06, 0x0CDF153F} } ,
	 { {0xD8BD5BE1, 0xACBE5F76, 0xAE624BD9, 0x30DBE537, 0x0BDF9DB9},
	{0xCBF3ECAC, 0x69121297, 0x0602121D, 0xB88D8064, 0x1D6A6B0F} } ,
	 { {0xB90D76B7, 0xB1C59089, 0x58E6C0CF, 0x56856B4B, 0x104A3A2E},
	{0x5765D476, 0xE255247E, 0x12A17208, 0xC63EB115, 0x0F15F172} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5497 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5498 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5499 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5500 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5501 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5502 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5503 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3642578C, 0xCA652634, 0x64A54921, 0x10CF9E8F, 0x0F746A4F},
	{0x8AE51B6A, 0xB16ED3B1, 0x02C3FCED, 0xCAD5D896, 0x19785B70} } ,
	 { {0x5D0165FF, 0xD8A46B62, 0x6998C1C3, 0xF38DB733, 0x0385FE08},
	{0x73E2C61F, 0x6F6CC75F, 0xA0E589A7, 0xA64815D3, 0x04287028} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x75F5F4D8, 0xFABCC4D2, 0x94BED6BA, 0x12104220, 0x208E42BD},
	{0x94EBD6C7, 0x8FFE80C5, 0xA884BB46, 0x3D1858C6, 0x10C209F1} } ,
	 { {0x24B69CCF, 0x94A5331D, 0x2B2F811E, 0x71CDA7E7, 0x1C4E1A81},
	{0x3A5B1993, 0xC95E4ABB, 0x9B9FB8EB, 0x074C3141, 0x16FA431B} } ,
	 { {0xBA02CBFE, 0xB148D6C4, 0xD3318387, 0xE71B6E66, 0x070BFC11},
	{0xE7C58C3E, 0xDED98EBE, 0x41CB134E, 0x4C902BA7, 0x0850E051} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5504 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5505 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5506 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5507 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5508 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5509 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5510 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA559195F, 0x41ABBD02, 0x49DB900E, 0xFEB92316, 0x22541BB8},
	{0xC087CCE6, 0x2DD51E97, 0x61580F40, 0x06A833BF, 0x0B63EC6C} } ,
	 { {0x8C4FB313, 0x9A31758A, 0xD10895EA, 0x1DE2645F, 0x152F7567},
	{0x7F457A8D, 0x11B20F39, 0x9C0A91FD, 0xF2182D5D, 0x0851E9F9} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x80D6D700, 0x4C05C779, 0x61B391DE, 0x92022B1B, 0x1450792C},
	{0x4899FC40, 0x036E47E1, 0xBB8C6AEC, 0x6DC6C62D, 0x03AC007A} } ,
	 { {0x14E99836, 0x803BFA2B, 0x4D1D6A27, 0x6392481B, 0x11D620D1},
	{0x51A04681, 0x185E51D2, 0xEFEC93C1, 0xD17E9A4A, 0x1932D900} } ,
	 { {0xCC4F13CB, 0x16359674, 0x68C66B37, 0x8C6E6CD9, 0x065DCACA},
	{0xFE8AF51A, 0x23641E72, 0x381523FA, 0xE4305ABB, 0x10A3D3F3} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5511 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5512 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5513 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5514 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5515 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5516 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5517 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xDC1AD065, 0xB2AE60A1, 0x94139329, 0xE362AFBB, 0x01475BD4},
	{0x800195C3, 0x7610020F, 0xF7AF00A3, 0x14C97F73, 0x13034511} } ,
	 { {0x9AC08E27, 0x7E3ADF7E, 0x02A552F8, 0x898E4395, 0x0843900D},
	{0x0FE3793A, 0x192ED2D9, 0x3A21C5BC, 0x382A0E03, 0x18AAD627} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xB7EEFE59, 0x708C2F52, 0xDA022AC6, 0x847CB5F5, 0x03126BF1},
	{0x619BC079, 0x95ED6C21, 0xCADEA053, 0x470DA15C, 0x21C94418} } ,
	 { {0xA94F11DF, 0x4E2CC7F2, 0xDF189F70, 0xE39BEFF1, 0x23E27EC2},
	{0x55EB3D3A, 0x8D719FA1, 0xB1EA83BA, 0x1C8A20D8, 0x12FF7F7F} } ,
	 { {0x35811C4E, 0xFC75BEFD, 0x054AA5F0, 0x131C872A, 0x1087201B},
	{0xD376A019, 0x14305111, 0x3AF8CADA, 0xC0FDC020, 0x0D548C4A} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5518 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5519 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5520 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5521 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5522 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5523 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5524 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xB7E42D0D, 0xCD5C04A2, 0x3F5C7059, 0x8D7788E3, 0x22812771},
	{0x96259CC6, 0x1EABF30C, 0xD3A48AB3, 0x533CE458, 0x21F51189} } ,
	 { {0xDEA82FFF, 0x3B5E6C69, 0x2D49D195, 0x7253FFC7, 0x15A7034C},
	{0xC0F5A147, 0x7F2B4E3E, 0x02C40F51, 0x81642679, 0x1468CB1D} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xDF9D0CF8, 0x646B56E8, 0x2A2C4AEC, 0x32621B17, 0x0D02216D},
	{0x351E8714, 0xCF35D58D, 0x1ED22522, 0xDBECE2C6, 0x137DC5F8} } ,
	 { {0x4D313316, 0xFC746D54, 0xE9921D4D, 0x4DE85578, 0x00716A3A},
	{0xE6C32214, 0xF17839DB, 0x5A820090, 0x7D3CCD28, 0x0BBC30E3} } ,
	 { {0x71000DA3, 0x588F8433, 0x2148E28C, 0x3551A3A8, 0x074CE695},
	{0x359AF033, 0xE02947DD, 0xCC3D5E04, 0x5371F10B, 0x04D07637} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5525 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5526 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5527 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5528 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5529 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5530 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5531 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x1FD2FF2C, 0x57A7FE97, 0x6587E92D, 0xA71DB104, 0x0A797A96},
	{0xD7D38F31, 0xDE842B6B, 0xA6A2B7B8, 0x02A68947, 0x16BA6E5B} } ,
	 { {0x78A08C34, 0x712A811A, 0x61EC3359, 0x9B36715F, 0x03C0D8ED},
	{0x59DC5D55, 0xA2184F6D, 0x9D866EEA, 0x0F057092, 0x180D5A84} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x79FC432C, 0x765727DB, 0xC7A4528C, 0x77C4DE41, 0x211A86C2},
	{0x4FAE45DB, 0x37387914, 0xF1B11097, 0xDFBBC209, 0x196E8073} } ,
	 { {0xCB832571, 0x7D8B123F, 0xAD726C34, 0xDEB08C35, 0x01D4E505},
	{0xAA1913B0, 0x79B6B90A, 0x7ED53747, 0xAE2131EF, 0x13768647} } ,
	 { {0xF1411868, 0xE2550234, 0xC3D866B2, 0x366CE2BE, 0x0781B1DB},
	{0x6768684F, 0x26034A3A, 0x01C21D37, 0x6EB4853F, 0x0C199504} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5532 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5533 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5534 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5535 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5536 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5537 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5538 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x850A3E59, 0xBE36F13C, 0x2787E210, 0xC074F759, 0x11B7D103},
	{0x601A7208, 0x7279FE20, 0x3A68D653, 0x474224A1, 0x1D763D96} } ,
	 { {0xF9703365, 0x57237300, 0x2D3C2151, 0x6571BA60, 0x11000DAC},
	{0xC92D5B4D, 0x34CF7B41, 0x97EB0172, 0x8B0B7EE8, 0x0854FD5C} } ,
	 { {0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x5CC3EB70, 0xE49962D6, 0x97112E4D, 0xD60AD818, 0x03874608},
	{0x81240500, 0x39F492BD, 0x9F93CD5C, 0x1C832578, 0x0D4A16C9} } ,
	 { {0x01E5CAD2, 0xE8F936A2, 0x1F92B457, 0x2527A33D, 0x105D655B},
	{0x9DFC3963, 0x0B58A823, 0x856F1D0E, 0x8FF99DD9, 0x05512054} } ,
	 { {0xF2E066CA, 0xAE46E601, 0x5A7842A2, 0xCAE374C0, 0x22001B58},
	{0x925AB69A, 0x699EF683, 0x2FD602E4, 0x1616FDD1, 0x10A9FAB9} } ,
	0};
		ecfp2_dbl_proj(&var_res_proj, &var_a);
		assert_bi_equal(var_expected.x[0], var_res_proj.x[0], "ecfp2_dbl_proj 5539 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res_proj.x[1], "ecfp2_dbl_proj 5540 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res_proj.y[0], "ecfp2_dbl_proj 5541 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res_proj.y[1], "ecfp2_dbl_proj 5542 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_res_proj.z[0], "ecfp2_dbl_proj 5543 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_res_proj.z[1], "ecfp2_dbl_proj 5544 a.z[1]");
		assert_equal(var_expected.infinity,var_res_proj.infinity, "ecfp2_dbl_proj 5545 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5EA9498E, 0x2F4670D4, 0xEB9C728C, 0xE9D0CD0D, 0x1AA19E6B},
	{0xE04141FE, 0xDF189497, 0x74019A4F, 0x6430096E, 0x0B18596B} } ,
	 { {0x40FCBF24, 0x08C7FA61, 0x6A520857, 0xF0F81EF8, 0x08B84BE4},
	{0xC260C45B, 0x6B14248B, 0x3EE471B7, 0x9205A1A8, 0x05971557} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x5EA9498E, 0x2F4670D4, 0xEB9C728C, 0xE9D0CD0D, 0x1AA19E6B},
	{0xE04141FE, 0xDF189497, 0x74019A4F, 0x6430096E, 0x0B18596B} } ,
	 { {0x0B539337, 0x15655A3F, 0xCEF8B847, 0xBE5E3CED, 0x1B48D41E},
	{0x89EF8E00, 0xB3193014, 0xFA664EE6, 0x1D50BA3D, 0x1E6A0AAC} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5546 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5547 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5548 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5549 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5550 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x1A3F89A9, 0x08EA533C, 0xADAB8C60, 0xBEA61920, 0x0F6610BA},
	{0x5884D01C, 0xA9C4111B, 0xBB8A22C2, 0x1788EA0E, 0x0E8A017D} } ,
	 { {0x7879F5C8, 0xDBEBF477, 0x91F1E749, 0xAC588E9F, 0x0F4D130C},
	{0xE0C78986, 0xC8D563B6, 0xCD9DDABC, 0x67653E01, 0x166B89DE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x1A3F89A9, 0x08EA533C, 0xADAB8C60, 0xBEA61920, 0x0F6610BA},
	{0x5884D01C, 0xA9C4111B, 0xBB8A22C2, 0x1788EA0E, 0x0E8A017D} } ,
	 { {0xD3D65C93, 0x42416028, 0xA758D954, 0x02FDCD46, 0x14B40CF7},
	{0x6B88C8D5, 0x5557F0E9, 0x6BACE5E1, 0x47F11DE4, 0x0D959625} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5551 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5552 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5553 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5554 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5555 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x839E157E, 0x6381C1C4, 0xF846D823, 0x8F262538, 0x1C76B1D2},
	{0x8E95697F, 0xCC1180CE, 0xB3DC736C, 0x1D959B61, 0x0F6861BF} } ,
	 { {0x5B8EFB54, 0x56CEFE3C, 0xE92D7E6E, 0xEB1D2BDC, 0x1825F830},
	{0x14D5FA50, 0x964F1186, 0xAF8D8367, 0x0005DB20, 0x23F889AE} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x839E157E, 0x6381C1C4, 0xF846D823, 0x8F262538, 0x1C76B1D2},
	{0x8E95697F, 0xCC1180CE, 0xB3DC736C, 0x1D959B61, 0x0F6861BF} } ,
	 { {0xF0C15707, 0xC75E5663, 0x501D422F, 0xC4393009, 0x0BDB27D2},
	{0x377A580B, 0x87DE431A, 0x89BD3D36, 0xAF5080C5, 0x00089655} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5556 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5557 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5558 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5559 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5560 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xC5FA4328, 0x8AE099F5, 0x24D650FE, 0xC0954DE7, 0x0E04F386},
	{0xA2462E67, 0x73C8C5EE, 0x4FC163F0, 0x292BFE53, 0x062F0EB8} } ,
	 { {0x5F6C8039, 0xD5747386, 0xAA99875D, 0xBF0EB58D, 0x1B30ECFD},
	{0x1F80BAD5, 0x15566180, 0xE3C789C1, 0x3E0CF8C2, 0x070A0766} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0xC5FA4328, 0x8AE099F5, 0x24D650FE, 0xC0954DE7, 0x0E04F386},
	{0xA2462E67, 0x73C8C5EE, 0x4FC163F0, 0x292BFE53, 0x062F0EB8} } ,
	 { {0xECE3D222, 0x48B8E119, 0x8EB13940, 0xF047A658, 0x08D03305},
	{0x2CCF9786, 0x08D6F320, 0x558336DD, 0x71496323, 0x1CF7189D} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5561 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5562 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5563 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5564 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5565 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x0F7F716F, 0x78DF76BA, 0x4612EA41, 0xC4CD75FD, 0x003ECDAD},
	{0x26142E79, 0xB3EB217F, 0x442A8D96, 0xF8B53978, 0x04B07EB7} } ,
	 { {0xF4F6B903, 0xC20E1FBB, 0x1AA38458, 0x8E8F89F6, 0x00ADE356},
	{0xA0A995D5, 0x74E01013, 0x689D3D75, 0xB5982A54, 0x20FE20FD} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x0F7F716F, 0x78DF76BA, 0x4612EA41, 0xC4CD75FD, 0x003ECDAD},
	{0x26142E79, 0xB3EB217F, 0x442A8D96, 0xF8B53978, 0x04B07EB7} } ,
	 { {0x57599958, 0x5C1F34E4, 0x1EA73C45, 0x20C6D1F0, 0x23533CAD},
	{0xABA6BC86, 0xA94D448C, 0xD0AD8328, 0xF9BE3191, 0x0302FF05} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5566 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5567 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5568 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5569 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5570 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x2787CA2E, 0xC69688BB, 0x615811F3, 0x05696ECC, 0x122FDEBF},
	{0x1A8699CB, 0x5608311F, 0x63765572, 0x5A43B496, 0x18371BBC} } ,
	 { {0x5146B2AF, 0x00B32A3A, 0xB0CB6F65, 0x90B5761A, 0x16EFB01F},
	{0xC5D43EE4, 0x1AD632B7, 0xB66E0844, 0xAA466CA9, 0x1E9AA513} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x2787CA2E, 0xC69688BB, 0x615811F3, 0x05696ECC, 0x122FDEBF},
	{0x1A8699CB, 0x5608311F, 0x63765572, 0x5A43B496, 0x18371BBC} } ,
	 { {0xFB099FAC, 0x1D7A2A65, 0x887F5139, 0x1EA0E5CB, 0x0D116FE4},
	{0x867C1377, 0x035721E8, 0x82DCB85A, 0x050FEF3C, 0x05667AF0} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5571 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5572 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5573 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5574 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5575 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x8A2E2EFF, 0x33AD6CCC, 0xDCCFD792, 0x9E8BBB6E, 0x0781F437},
	{0xB7A10CB9, 0x2BB921AD, 0x1B2B9A5A, 0xCD32C7E7, 0x04A46775} } ,
	 { {0xDB610E08, 0x9AFDC731, 0x0174A5F8, 0xE5E978A9, 0x2050E32B},
	{0x018A2193, 0xE481584A, 0xCDBC5B3D, 0x79AE1E01, 0x049131A8} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x8A2E2EFF, 0x33AD6CCC, 0xDCCFD792, 0x9E8BBB6E, 0x0781F437},
	{0xB7A10CB9, 0x2BB921AD, 0x1B2B9A5A, 0xCD32C7E7, 0x04A46775} } ,
	 { {0x70EF4453, 0x832F8D6E, 0x37D61AA5, 0xC96CE33D, 0x03B03CD7},
	{0x4AC630C8, 0x39ABFC56, 0x6B8E6560, 0x35A83DE4, 0x1F6FEE5B} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5576 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5577 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5578 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5579 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5580 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x27A60F04, 0xB58B2822, 0xBCA1EF5F, 0x104C4A91, 0x1FC30C1A},
	{0xA0A110C9, 0xA374EFB5, 0x3A84848F, 0x2A9D4068, 0x12AAA473} } ,
	 { {0xCC5B6D80, 0xA6C61593, 0x5CB00B8B, 0x07A0A258, 0x20981DD5},
	{0x0841D67A, 0x093F7E54, 0x0E443FC0, 0xCFF619D8, 0x1A93865B} } ,
	0};
		static ecpoint_fp2 var_expected = { { {0x27A60F04, 0xB58B2822, 0xBCA1EF5F, 0x104C4A91, 0x1FC30C1A},
	{0xA0A110C9, 0xA374EFB5, 0x3A84848F, 0x2A9D4068, 0x12AAA473} } ,
	 { {0x7FF4E4DB, 0x77673F0C, 0xDC9AB512, 0xA7B5B98D, 0x0369022E},
	{0x440E7BE1, 0x14EDD64C, 0x2B0680DE, 0xDF60420E, 0x096D99A7} } ,
	0};
		ecfp2_neg_affine(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_affine 5581 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_affine 5582 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_affine 5583 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_affine 5584 a.y[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_affine 5585 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xA8C92CA1, 0x9CCF5E97, 0x5527754D, 0x74ABB040, 0x0502079F},
	{0x2A0AC61B, 0x91879AEE, 0x2916C950, 0x6EBB06E0, 0x1C59F78C} } ,
	 { {0xEBF9CFA1, 0xDABF6906, 0x41B1A4A8, 0xE4DCD3C1, 0x200D5936},
	{0x248FB75F, 0x3D5DDC23, 0xC99788AB, 0x46C15F7F, 0x0B8C32EA} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xA8C92CA1, 0x9CCF5E97, 0x5527754D, 0x74ABB040, 0x0502079F},
	{0x2A0AC61B, 0x91879AEE, 0x2916C950, 0x6EBB06E0, 0x1C59F78C} } ,
	 { {0x605682BA, 0x436DEB99, 0xF7991BF5, 0xCA798824, 0x03F3C6CC},
	{0x27C09AFC, 0xE0CF787D, 0x6FB337F2, 0x6894FC66, 0x1874ED19} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5586 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5587 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5588 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5589 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5590 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5591 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5592 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x491E9354, 0x67FDA1A7, 0xBA703675, 0x9DB1C7FB, 0x18374A98},
	{0x9EDC4486, 0xE3720BE1, 0xA22E90B6, 0x6935BC53, 0x070AB1F2} } ,
	 { {0x1E738356, 0xD2D431ED, 0x23CBBE6B, 0x9C816EE6, 0x0B35DD3C},
	{0x6F6C4EAF, 0x5951DBEF, 0x2344B2A0, 0x02F0CB81, 0x1E660430} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x491E9354, 0x67FDA1A7, 0xBA703675, 0x9DB1C7FB, 0x18374A98},
	{0x9EDC4486, 0xE3720BE1, 0xA22E90B6, 0x6935BC53, 0x070AB1F2} } ,
	 { {0x2DDCCF05, 0x4B5922B3, 0x157F0232, 0x12D4ED00, 0x18CB42C7},
	{0xDCE403AC, 0xC4DB78B0, 0x16060DFD, 0xAC659065, 0x059B1BD3} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5593 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5594 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5595 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5596 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5597 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5598 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5599 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x67910923, 0x1CD6CFE0, 0xE381D9E9, 0x6215E314, 0x08AA4E62},
	{0xA5C64633, 0x69A717DC, 0x42D80A37, 0x56644E6D, 0x15C20EC6} } ,
	 { {0x347702B7, 0x813302BC, 0xD4855F36, 0x2D552714, 0x16122924},
	{0xE321CE19, 0x0F159EF3, 0x3FBF1C9C, 0x276EE5D4, 0x11772A39} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x67910923, 0x1CD6CFE0, 0xE381D9E9, 0x6215E314, 0x08AA4E62},
	{0xA5C64633, 0x69A717DC, 0x42D80A37, 0x56644E6D, 0x15C20EC6} } ,
	 { {0x17D94FA4, 0x9CFA51E4, 0x64C56167, 0x820134D1, 0x0DEEF6DF},
	{0x692E8442, 0x0F17B5AC, 0xF98BA402, 0x87E77611, 0x1289F5CA} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5600 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5601 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5602 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5603 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5604 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5605 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5606 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x9BEBCFA0, 0x30100FBA, 0xBD7FE30D, 0x6B1964A6, 0x15C3D3A1},
	{0xC007D087, 0x737F55AE, 0x7DC93AA7, 0xC1223DF1, 0x10DA58CC} } ,
	 { {0x4DC6A922, 0x44551767, 0x4A043D72, 0x7056633C, 0x03E13BB2},
	{0x5B768336, 0xCAD98B6C, 0xB7E35AF3, 0x5043E20F, 0x1FA6DF60} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x9BEBCFA0, 0x30100FBA, 0xBD7FE30D, 0x6B1964A6, 0x15C3D3A1},
	{0xC007D087, 0x737F55AE, 0x7DC93AA7, 0xC1223DF1, 0x10DA58CC} } ,
	 { {0xFE89A939, 0xD9D83D38, 0xEF46832B, 0x3EFFF8A9, 0x201FE451},
	{0xF0D9CF25, 0x5353C933, 0x816765AA, 0x5F1279D6, 0x045A40A3} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5607 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5608 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5609 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5610 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5611 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5612 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5613 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0xC2439B91, 0x71079EF6, 0x88D54B41, 0xA09B7ABC, 0x21F268DA},
	{0xE96E7903, 0xED4F6481, 0x3D742372, 0x6A580863, 0x004E7625} } ,
	 { {0x665FE0C4, 0xEDD79915, 0x6C976A7E, 0x84C678AC, 0x13CBF308},
	{0x42CECDD4, 0x48A78B05, 0x75F631C5, 0xF79E3BEE, 0x165A1211} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0xC2439B91, 0x71079EF6, 0x88D54B41, 0xA09B7ABC, 0x21F268DA},
	{0xE96E7903, 0xED4F6481, 0x3D742372, 0x6A580863, 0x004E7625} } ,
	 { {0xE5F07197, 0x3055BB8A, 0xCCB3561F, 0x2A8FE339, 0x10352CFB},
	{0x09818487, 0xD585C99B, 0xC3548ED8, 0xB7B81FF7, 0x0DA70DF1} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5614 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5615 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5616 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5617 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5618 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5619 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5620 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x6C19A777, 0x63817E4F, 0x98E1DBFD, 0x9D2DE5DF, 0x208855C0},
	{0x41E1EE2C, 0x48F482F0, 0x3AD46B3B, 0xA052A575, 0x0967DEA1} } ,
	 { {0xD3DD334A, 0xF9EC5843, 0xDAE95E73, 0x7B9F5911, 0x0BBF427F},
	{0xC572B5D3, 0x655A6D7B, 0x7A77769F, 0x82917267, 0x23BD630C} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x6C19A777, 0x63817E4F, 0x98E1DBFD, 0x9D2DE5DF, 0x208855C0},
	{0x41E1EE2C, 0x48F482F0, 0x3AD46B3B, 0xA052A575, 0x0967DEA1} } ,
	 { {0x78731F11, 0x2440FC5C, 0x5E61622A, 0x33B702D4, 0x1841DD84},
	{0x86DD9C88, 0xB8D2E724, 0xBED349FE, 0x2CC4E97E, 0x0043BCF7} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5621 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5622 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5623 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5624 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5625 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5626 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5627 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x3E48A979, 0x2DAC515A, 0x3DF8F737, 0x66232EE5, 0x033B85B7},
	{0x8F964654, 0xF0982C2F, 0x9654526F, 0x014C4378, 0x101ECC1F} } ,
	 { {0xDB2A4BA9, 0xE0F2D23B, 0xE536F159, 0xA9366568, 0x12B6A5AF},
	{0x1EBD67AF, 0x54106968, 0x4E90A059, 0xBF46F8C3, 0x1ED5B602} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x3E48A979, 0x2DAC515A, 0x3DF8F737, 0x66232EE5, 0x033B85B7},
	{0x8F964654, 0xF0982C2F, 0x9654526F, 0x014C4378, 0x101ECC1F} } ,
	 { {0x712606B2, 0x3D3A8264, 0x5413CF44, 0x061FF67D, 0x114A7A54},
	{0x2D92EAAC, 0xCA1CEB38, 0xEABA2044, 0xF00F6322, 0x052B6A00} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5628 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5629 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5630 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5631 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5632 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5633 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5634 infinity");
	}
	{
		static ecpoint_fp2_proj var_a = { { {0x71B4878B, 0xFCC213BA, 0xB4F3EF29, 0x65BC0D2B, 0x159D3794},
	{0xFB62F2F6, 0xF9CC0098, 0xA78AE8B2, 0xEF9BEEB3, 0x183AE1CD} } ,
	 { {0xB6D66896, 0xF2AA805E, 0x492D4ED4, 0xBDC416FA, 0x046955F3},
	{0xBD8FE5C7, 0x5FCD0C70, 0x13B2AAC0, 0xA372051F, 0x19B06E9F} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		static ecpoint_fp2_proj var_expected = { { {0x71B4878B, 0xFCC213BA, 0xB4F3EF29, 0x65BC0D2B, 0x159D3794},
	{0xFB62F2F6, 0xF9CC0098, 0xA78AE8B2, 0xEF9BEEB3, 0x183AE1CD} } ,
	 { {0x9579E9C5, 0x2B82D441, 0xF01D71C9, 0xF19244EB, 0x1F97CA0F},
	{0x8EC06C94, 0xBE60482F, 0x259815DD, 0x0BE456C7, 0x0A50B164} } ,
	 { {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000},
	{0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000} } ,
	0};
		ecfp2_neg_proj(&var_a);
		assert_bi_equal(var_expected.x[0], var_a.x[0], "ecfp2_neg_proj 5635 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_a.x[1], "ecfp2_neg_proj 5636 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_a.y[0], "ecfp2_neg_proj 5637 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_a.y[1], "ecfp2_neg_proj 5638 a.y[1]");
		assert_bi_equal(var_expected.z[0], var_a.z[0], "ecfp2_neg_proj 5639 a.z[0]");
		assert_bi_equal(var_expected.z[1], var_a.z[1], "ecfp2_neg_proj 5640 a.z[1]");
		assert_equal(var_expected.infinity,var_a.infinity, "ecfp2_neg_proj 5641 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static bigint_t var_k = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 661 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 662 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 663 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 664 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 665 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static bigint_t var_k = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0xEE4EFE3F, 0x3A409E98, 0x08F069CB, 0x7CB616CF, 0x07F6DC45},
	{0xBAEB2292, 0x05C6B853, 0x60D4DD6C, 0xEF06B458, 0x15DE4EE9} } ,
	 { {0x46B81F17, 0xD41429BF, 0x431C5942, 0x0A9937BC, 0x10D5B467},
	{0x46D88A9D, 0x12DDBBA0, 0xD24ADAD3, 0x305B58E6, 0x1E5970F9} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 666 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 667 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 668 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 669 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 670 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static bigint_t var_k = {0x00000004, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0xB1091583, 0xC24468F1, 0xA4C4CC7C, 0x48E9E95D, 0x081AFF72},
	{0x81B77722, 0x4AAF1B3D, 0xEBB99197, 0xAFB9F3FD, 0x0B889C3E} } ,
	 { {0x74A365D4, 0x9F8E0DDC, 0xFFBE2E5C, 0x84C6F603, 0x1171FAFC},
	{0x81578339, 0xEAE5D0E4, 0x3C372173, 0x84AE363C, 0x0295622E} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 671 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 672 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 673 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 674 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 675 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static bigint_t var_k = {0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x8C1A4CB5, 0x825E4019, 0x4C5246BF, 0xCF32B7D3, 0x23C68112},
	{0xA10D6B3E, 0x7ED385BC, 0x5EE9400E, 0xF298F6DB, 0x21FE0BC6} } ,
	 { {0x56DFCD5B, 0xDF775D06, 0xCCF4A95F, 0xCFA059A4, 0x139D1B1B},
	{0x4D8D1673, 0x710BDE2C, 0xCEA8E9EE, 0xB6AA9638, 0x021BB2C2} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 676 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 677 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 678 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 679 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 680 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static bigint_t var_k = {0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const ecpoint_fp2 var_expected = { { {0x6CE2C97D, 0x13174C11, 0x9A3B852B, 0xCC4EC370, 0x03DB9371},
	{0xBE8383EE, 0x1590A98F, 0x33B9829B, 0x4B911B31, 0x090BA6E4} } ,
	 { {0xBC3E6A5E, 0xB06FF30A, 0x7EE6411E, 0x1B0B307F, 0x0AF866EB},
	{0xF8CF82EF, 0xAED084DF, 0xC70964C3, 0x2A2F3DD4, 0x15DBEE01} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 681 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 682 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 683 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 684 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 685 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xA65161E7, 0xB92A8E89, 0x745021E8, 0x23F8A355, 0x214FCD9E},
	{0xA8FE444A, 0x308D40A5, 0x6F1AEEAC, 0x9A4DAB01, 0x1A73FB56} } ,
	 { {0x0F842193, 0x3F7F110F, 0x832DC365, 0x606EBF1C, 0x0B3F6064},
	{0x8EC33C6A, 0x73686F8E, 0x4426FC87, 0x736756D9, 0x04E3F937} } ,
	0};
		static bigint_t var_k = {0xDF26F950, 0x459A3A91, 0x6CC1DC38, 0x9A08F41C, 0x04840EB4};
		static const ecpoint_fp2 var_expected = { { {0xF32F315C, 0x7CF1194E, 0xD872D432, 0xF11C20A4, 0x065700B9},
	{0x371013A7, 0x1A49107C, 0xF9172B85, 0x8E44052B, 0x1E9A51DB} } ,
	 { {0x34460B52, 0x325AE6A1, 0x6C19AF0C, 0x0F8E71C6, 0x1E39D879},
	{0xD68036B2, 0xBA32F218, 0xF1845742, 0x7A691EC4, 0x20774FB9} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 686 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 687 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 688 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 689 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 690 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3B54E50A, 0x0B2D1689, 0x08DAA5CD, 0xA04E618B, 0x0E6539DE},
	{0xC7FEBA51, 0x1BCE8A27, 0x01B06925, 0xF578F1F5, 0x01B01185} } ,
	 { {0x880D614F, 0xA10EB10D, 0x4AEA24A3, 0x6DECF006, 0x05F293C1},
	{0x50296E3B, 0x9AEFB1E8, 0x6C80DABA, 0x20597B23, 0x08DCC4B1} } ,
	0};
		static bigint_t var_k = {0x7CA94266, 0x4C30B843, 0x5D60075C, 0x7DE4DCEF, 0x11905E47};
		static const ecpoint_fp2 var_expected = { { {0xB99278AD, 0x8BDCDB91, 0x3F666B7F, 0x1D756A20, 0x067A09CE},
	{0x2831890F, 0x3A9DDBCF, 0x44994778, 0x90B77F86, 0x054FBD3B} } ,
	 { {0x2D87E0EB, 0x3AE7768B, 0x8DA91588, 0x3F293A5D, 0x174813CD},
	{0x6039A527, 0x0C39C6AB, 0x99E4978B, 0xC1FD6450, 0x172D9117} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 691 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 692 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 693 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 694 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 695 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x60FC33A5, 0x856517B1, 0xF25821C3, 0xA0BED65E, 0x00C41DB6},
	{0x98990E7B, 0x0C669F07, 0xF89DBA5B, 0x913BADDA, 0x0127B119} } ,
	 { {0xE1EBEF21, 0xB8BE5BBB, 0xA6679807, 0xACBFB601, 0x1AF3BAAD},
	{0x883AAAD2, 0x670572D5, 0xFDAE88A9, 0xE9E6D00F, 0x1966B70F} } ,
	0};
		static bigint_t var_k = {0x5EDE5422, 0x57D0082A, 0x626E59B8, 0x98A387CE, 0x18A92D11};
		static const ecpoint_fp2 var_expected = { { {0xB67F72A6, 0x8D281A85, 0x47CD4ED8, 0x583A4673, 0x12B21A30},
	{0xAAA16480, 0x281E2871, 0x55D6A2D6, 0xE38C1C1E, 0x0F3ABC90} } ,
	 { {0xF161AFDA, 0x2C3B6F4B, 0xAE3FA96A, 0x8095B26A, 0x1A7DC5C7},
	{0x6BBD9D19, 0x81F5230A, 0xBFD212F2, 0x3E17C9A8, 0x15683811} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 696 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 697 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 698 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 699 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 700 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x567781BC, 0xC030BD91, 0xD00A5AD1, 0x722BDD61, 0x1FAB3E72},
	{0x42CC2845, 0xF08875D4, 0x20D63740, 0xF9D85DDF, 0x23F32C53} } ,
	 { {0xAA68338C, 0x3710BFF2, 0xAE74E27F, 0x0C282ECB, 0x22BDBCD7},
	{0x09ABDD8D, 0x9CFD4119, 0xDD7F3500, 0x792134AF, 0x1A34FBD6} } ,
	0};
		static bigint_t var_k = {0xC1433ED7, 0xF1F7E58C, 0x360E0C47, 0x10F3E5BF, 0x1D1DA9F3};
		static const ecpoint_fp2 var_expected = { { {0x5C167C4C, 0x12E336A1, 0x8483A1F4, 0xD63188B2, 0x0FBFFCDA},
	{0xDF2E3769, 0xE74BCF14, 0x0F277A91, 0x5AD1D52C, 0x113B6918} } ,
	 { {0x729F6FE6, 0x16E0E246, 0x33112BC7, 0x74793F0F, 0x19EDC67F},
	{0x48CC492F, 0x809D99FD, 0xCDB0CEE7, 0x64916E2F, 0x1D9EDA6F} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 701 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 702 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 703 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 704 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 705 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFA84A2B6, 0xAAE55B70, 0xA57BBAAF, 0x94EE3B7F, 0x11A8BB9C},
	{0x154BA811, 0x3EA5AE21, 0x5A468702, 0xBD744BD7, 0x065285D9} } ,
	 { {0x2653F8D2, 0x99263438, 0x2DD734E6, 0x8E26169B, 0x0EA7B296},
	{0x279CBF96, 0xEB04FBF8, 0xA617BA3F, 0xF843E2B4, 0x223E4BCB} } ,
	0};
		static bigint_t var_k = {0x6D2B21AC, 0x35EEFA0D, 0x079F1CF3, 0xF2EDC44B, 0x1483951B};
		static const ecpoint_fp2 var_expected = { { {0x4329EFB2, 0x2883E14F, 0x8B60C369, 0xE20403FF, 0x01359796},
	{0x6B56DFC8, 0xD7EA9AA1, 0xB904EB5A, 0xD0B34A61, 0x0A40D3BC} } ,
	 { {0x7A50E4FD, 0x2208D0DF, 0xC0ED07FC, 0x95B85D94, 0x16598584},
	{0x068F8C1F, 0xA3246E5B, 0xFD936630, 0xEFA4D4DB, 0x223710A4} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 706 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 707 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 708 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 709 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 710 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x3ED1E69F, 0xAF7A1B10, 0x09E85E17, 0xBBF76894, 0x17ACAD0E},
	{0x89E857BB, 0x18375C59, 0x0E604B53, 0xF1A229D7, 0x0229C80C} } ,
	 { {0x54132E21, 0x26E0E2E9, 0x30D52061, 0x97C6C848, 0x06CD20FC},
	{0x4242FFBD, 0xF46C89D4, 0x456C556C, 0xD412DFE9, 0x0EB0A21C} } ,
	0};
		static bigint_t var_k = {0xF116B8EF, 0xFDC711F4, 0x153B1D48, 0xF0CF0A7D, 0x04DEDEE7};
		static const ecpoint_fp2 var_expected = { { {0x6546A189, 0xF1DFC38F, 0xD9A35C2D, 0x5BEC2032, 0x0594FA04},
	{0xB60410B2, 0x85F8AA23, 0x16211625, 0xFD8B65FF, 0x00018A34} } ,
	 { {0xDEFD83D8, 0x9F481C3C, 0x796E80CA, 0x0DFE768D, 0x0124255C},
	{0xAA1EE04B, 0xB56CEB8B, 0xEA532856, 0xB4E29D4C, 0x178D46D9} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 711 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 712 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 713 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 714 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 715 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x45826445, 0xE4724CD8, 0xFFC4A1EA, 0x646DD570, 0x02808C77},
	{0x89C41A8B, 0xC309A1FA, 0x360C1A19, 0x5E751F06, 0x008BFFF0} } ,
	 { {0xEB6BD0BA, 0x68BB9161, 0x2282FCCD, 0x11D320BA, 0x03039668},
	{0x710506EB, 0xCDFFC7E0, 0x544643B6, 0x22608779, 0x21A79E37} } ,
	0};
		static bigint_t var_k = {0xF43B913E, 0xACFBDE52, 0x99F267D1, 0x26348CA9, 0x0C96A345};
		static const ecpoint_fp2 var_expected = { { {0x764250B4, 0x6CEE9D55, 0x2D6D82BC, 0x30B12310, 0x08043D98},
	{0x5E3AA38C, 0x25681949, 0x1F67BEAD, 0xA3C0D152, 0x0D624F69} } ,
	 { {0x70404A43, 0xDB55E4AB, 0xAC9A5EC4, 0x2D951CC3, 0x167042FB},
	{0xA14EE562, 0xB79AF0A6, 0xFE70C03A, 0x4760480F, 0x209EE59C} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 716 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 717 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 718 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 719 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 720 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x5C450603, 0x0EB1783F, 0x7E56CE69, 0x4D00B54C, 0x097EE771},
	{0x7076658D, 0x04F6469F, 0x7BA4425A, 0xD9F703CE, 0x1A0B54DC} } ,
	 { {0xFF1CF36F, 0x23976137, 0x691CD2FC, 0xFE14202A, 0x15612155},
	{0x54465332, 0xB8A9CBE3, 0xB913E008, 0xF98CFCA7, 0x090E4F0D} } ,
	0};
		static bigint_t var_k = {0x5F5113E5, 0x46420B63, 0xE9E27240, 0x4AC7E550, 0x08C2652B};
		static const ecpoint_fp2 var_expected = { { {0xCAEDCE50, 0x760EE298, 0x13F8B6AA, 0x07575933, 0x04D77460},
	{0xBE4664E8, 0x17A5CDC5, 0x681A6E50, 0x002C62D6, 0x07C909A4} } ,
	 { {0x31E88DAE, 0x35239298, 0x502BAE60, 0xF6B55104, 0x22C7834D},
	{0xBFF3E4BB, 0x94C7B69D, 0xC0ABAB64, 0x267BE884, 0x0A76F3EB} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 721 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 722 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 723 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 724 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 725 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xFE1F6C51, 0x4CA94AFA, 0xFD7EFF39, 0x934814B1, 0x13087CC9},
	{0x74C7FD68, 0x85770C72, 0x0E2218D6, 0x39F07A3A, 0x1EBCF7E9} } ,
	 { {0xB22CFCCF, 0x580F2629, 0x673C8294, 0xF34ED002, 0x0C214143},
	{0x3FB7B643, 0x57ED477A, 0xDF494911, 0xFCA91336, 0x1A7CB9C4} } ,
	0};
		static bigint_t var_k = {0x8C2CF3D1, 0x1AD7CB93, 0xD71DA93F, 0xE3F816B8, 0x0DA4EA65};
		static const ecpoint_fp2 var_expected = { { {0xB324DF60, 0x067623B7, 0x6D7117FD, 0xF6CB05E2, 0x17DB3708},
	{0x6FAECE6D, 0xA7FFBEF0, 0x3B75B58C, 0xDE2DF194, 0x10AD68E6} } ,
	 { {0x11AC43DD, 0x54690063, 0xE737CCB7, 0x068EBE56, 0x0C77E7E7},
	{0x01ABD397, 0xB60DABFD, 0x5B0306B2, 0x85D7F568, 0x22D853B4} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 726 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 727 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 728 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 729 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 730 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x531DD416, 0xB38F22D3, 0xF3882106, 0xAFD78701, 0x1294C1DD},
	{0xFBA80481, 0xEED3BBB8, 0xF14D280F, 0xBD164E32, 0x013EEF6C} } ,
	 { {0x493F2D69, 0x4C10E808, 0xA7ADB544, 0xD96336B9, 0x10B4BF81},
	{0xEF168FEF, 0x5D52EE4A, 0x07C692BA, 0x0E0E9355, 0x129CF54B} } ,
	0};
		static bigint_t var_k = {0xEA2C50E0, 0x7806D065, 0xCC3F1085, 0xEFBAE85E, 0x0DFC747D};
		static const ecpoint_fp2 var_expected = { { {0x22E6CEA3, 0x3FC480B6, 0xFE5FEF3E, 0x24CA3938, 0x09FA9C61},
	{0xDD0F2CAC, 0x86EBFAB6, 0x112D92BF, 0xF686348E, 0x075D5DF0} } ,
	 { {0x9E018C99, 0x70BEFE5E, 0x8202AA7D, 0x81CCCBC2, 0x23E8309E},
	{0x42DD9C8C, 0x87C36567, 0x59E9F2BE, 0x6EB402F4, 0x1D2EE99C} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 731 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 732 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 733 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 734 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 735 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x86353B9C, 0x38EB6056, 0x9EBA7A81, 0x2D7C1E30, 0x07D0E666},
	{0x2641E21F, 0x62A6B13E, 0xE9EC4D62, 0xF1F46E75, 0x0AC3DBEE} } ,
	 { {0x0E24015D, 0xA88CD1B7, 0xAB2A5E25, 0x2955AB27, 0x058837D4},
	{0xEB8FD0DB, 0xADC9284A, 0xB5D59AC0, 0x64774A28, 0x20A0944C} } ,
	0};
		static bigint_t var_k = {0xEE18F9D9, 0x99196DF4, 0x84414966, 0x6ACCC7DE, 0x1A01E315};
		static const ecpoint_fp2 var_expected = { { {0x1225A86F, 0x76986346, 0xD74C68F4, 0x94715E4F, 0x06C0AA7D},
	{0xE67E3D25, 0x28C85074, 0xD49A4FDE, 0x2A2466B9, 0x0ACE00DD} } ,
	 { {0x6622245A, 0x8E154241, 0x72909C66, 0x1418F0BB, 0x1471CD58},
	{0x5E5CA559, 0x0381251F, 0x78009049, 0x9ADE4F4A, 0x01342CB7} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 736 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 737 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 738 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 739 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 740 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xCF49C15B, 0x43522213, 0x96261C25, 0xDD2C1975, 0x1B6CB534},
	{0xBC429EC3, 0x40CA2DFA, 0x2694EA73, 0x30268289, 0x202D3D4A} } ,
	 { {0x2A191427, 0x4D465AE9, 0x0C661FAA, 0xD4877DB2, 0x1B7BF95A},
	{0x198F4373, 0x77BF6FD6, 0x3167CDAD, 0x8DCE60D6, 0x0841977A} } ,
	0};
		static bigint_t var_k = {0x29146851, 0x75B3B215, 0x50A096E1, 0xA0E887DD, 0x02715AFF};
		static const ecpoint_fp2 var_expected = { { {0x674E0E42, 0xFE54061E, 0x0B9FE631, 0x5DB84E98, 0x102A7522},
	{0xA45CDFE6, 0x730C7E49, 0x835F25EC, 0xF122A412, 0x1C252EDE} } ,
	 { {0xDD5EE073, 0x62989238, 0x892ED08C, 0xAC767081, 0x1401F62B},
	{0xF919D812, 0x5CEB888E, 0xBDBCA94E, 0x697E4F08, 0x09D66645} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 741 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 742 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 743 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 744 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 745 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x4744629F, 0xBB3F9395, 0x8C3609C2, 0x7AEF5B85, 0x1E6C0083},
	{0x3BB4694A, 0x9A42F3A5, 0x91895733, 0x69B69976, 0x223572FE} } ,
	 { {0x5B0D0CFD, 0x71D6E9C7, 0x04C87334, 0x22D08BDC, 0x186F44C6},
	{0xE0A003C2, 0x769203E8, 0xF7B7BA6A, 0x9117B8C3, 0x19663F7B} } ,
	0};
		static bigint_t var_k = {0xEF3C8797, 0xF6000230, 0xAFB4AD6E, 0xDC922420, 0x23E81843};
		static const ecpoint_fp2 var_expected = { { {0x0E1F4192, 0x35446875, 0x40E58B24, 0xA128DECE, 0x09E97B14},
	{0x8620F39F, 0x7E3C5A0A, 0x309837A7, 0x6FF034B8, 0x16F67E7B} } ,
	 { {0xEBD97EFC, 0x6C3ADA14, 0xFD0D2B1E, 0x01E0007C, 0x0FDC2EF1},
	{0xCDAAB921, 0x1FBC49E2, 0x97BDEB95, 0xA9EE286F, 0x0D9EA42D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 746 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 747 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 748 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 749 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 750 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x27860095, 0x94A1697E, 0xBB7B9A2A, 0xC3042076, 0x0671A786},
	{0x10540952, 0x58289082, 0x421614BC, 0x31978A9B, 0x19B80A41} } ,
	 { {0xBB5622D3, 0x9B58CCD8, 0x82B9BDAB, 0x16DFD858, 0x0ECF29F3},
	{0xC18A275F, 0xBA8BBBDC, 0xC627FBC5, 0x8458CB61, 0x19954E15} } ,
	0};
		static bigint_t var_k = {0xC223FFA6, 0xE70DCCB4, 0x58E91A61, 0xF56E07EE, 0x20F8B5B9};
		static const ecpoint_fp2 var_expected = { { {0x5A94594E, 0x81757DBC, 0x6AAFF3CC, 0x390C0ACC, 0x195C89B1},
	{0x399EC4D5, 0xE62EE741, 0xC86F9AB7, 0xE5FC69CA, 0x228E1DFB} } ,
	 { {0xD786D7F6, 0xADC046E6, 0xACFBDA34, 0x7C449C4D, 0x0D29EBD6},
	{0xABC0790D, 0x3D5CD02F, 0x61B336A5, 0x51CA2CE8, 0x197AFC7D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 751 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 752 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 753 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 754 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 755 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0xE2B509FB, 0x1BF1B4BF, 0x10613554, 0x06DD36E2, 0x03905B65},
	{0xD2D9E2B9, 0x85F811E2, 0x0791342E, 0x4D3401F7, 0x18F1D72B} } ,
	 { {0xCB077B18, 0x30C37AB8, 0x101FB790, 0x50385619, 0x035ABE31},
	{0xF4B6F987, 0x701F7E63, 0xBB74AB5F, 0x6EA4545A, 0x02ACC697} } ,
	0};
		static bigint_t var_k = {0xAAF734AD, 0x27CA237E, 0xDBF75334, 0xC73F3F2A, 0x0DB496FF};
		static const ecpoint_fp2 var_expected = { { {0x36DA98CB, 0xDB19CDAE, 0xA1B89408, 0xB4B85D5E, 0x1044645E},
	{0xEBFE0514, 0x1A0B9483, 0x3F69864C, 0xD34C20D4, 0x176B667C} } ,
	 { {0xED30AA7A, 0xBE1E9071, 0x91005924, 0xF212F008, 0x0045813F},
	{0x340A4E04, 0xCCBA30E9, 0xEDDE5272, 0x14F88F41, 0x02289513} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 756 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 757 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 758 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 759 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 760 infinity");
	}
	{
		static ecpoint_fp2 var_a = { { {0x61E59AE4, 0x40DD9BC6, 0x03F9D8D8, 0x438CB834, 0x22AD9F57},
	{0xB4F295D0, 0x4CC3AD2D, 0x1229C77A, 0xE823A969, 0x0B585F4C} } ,
	 { {0xFDCF150A, 0x178F1F1E, 0x54C97B2A, 0x881714DB, 0x1688CAA5},
	{0x804778D7, 0xD7D50C1F, 0xDF8868C4, 0x3F9553BD, 0x1609B55A} } ,
	0};
		static bigint_t var_k = {0xF1306A42, 0x0E1E8C54, 0x4E55970D, 0xD41CB2F8, 0x03858C25};
		static const ecpoint_fp2 var_expected = { { {0xF8C69967, 0xF66CCB63, 0x3803C88D, 0x8849E34C, 0x227887C5},
	{0x62184F44, 0xEE8C04E7, 0xEF6E3A57, 0xADCCEE2D, 0x1094ADDE} } ,
	 { {0x25AA6AFF, 0x8FF36ECD, 0x27815ACE, 0x19ADB299, 0x065F5191},
	{0xD730FC70, 0x278BB159, 0xF9265EF8, 0xD266D3BB, 0x06052B9D} } ,
	0};
		ecfp2_mul(&var_res, &var_a, var_k);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_mul 761 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_mul 762 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_mul 763 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_mul 764 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_mul 765 infinity");
	}
	{
		static const bigint_t var_t = {0xC00812A6, 0x03521E74, 0x5D1E5003, 0x5C8DDDE0, 0x219F7346};
		static ecpoint_fp2 var_expected = { { {0x3BE8910B, 0x3D5E864F, 0x65602C25, 0x6DAF8F47, 0x0608025E},
	{0x7835BA41, 0x82A9BC90, 0xC2DCE382, 0xCCF7FFF5, 0x0E388291} } ,
	 { {0xFA8AD816, 0x172308C2, 0x8BA76F60, 0x4CD2D9CF, 0x0FB3AB72},
	{0x9536A012, 0xA4594CBF, 0x927F92A0, 0xD8658888, 0x00832E43} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5747 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5748 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5749 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5750 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5751 infinity");
	}
	{
		static const bigint_t var_t = {0x50CB74E7, 0x791C6478, 0xCA368A35, 0x55FAF153, 0x036D38EC};
		static ecpoint_fp2 var_expected = { { {0x0D6041B2, 0x5AD9D5D7, 0xB31EBB6E, 0xFD47DB9B, 0x0B76D6BF},
	{0x78382DD7, 0xE8FD7DD8, 0x5A5A5F9F, 0x8425B19E, 0x18B60804} } ,
	 { {0x079A7600, 0x8C2EE3AF, 0x7CCC3C72, 0xB6A9E8F6, 0x0DFBA25D},
	{0x9F0A6A47, 0xC20CDEC9, 0x4A53E6FD, 0x8D4FF214, 0x235BD2E0} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5752 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5753 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5754 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5755 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5756 infinity");
	}
	{
		static const bigint_t var_t = {0x34182CBB, 0xCC1137C8, 0x4C8630F8, 0x40064027, 0x0F7367D3};
		static ecpoint_fp2 var_expected = { { {0x3CAAC7B6, 0x82B41533, 0x150EE3C0, 0x0E4FB104, 0x22D5F73C},
	{0xF38ABA7F, 0xD29FAAC9, 0x9DB25A27, 0xE448B350, 0x103E5A83} } ,
	 { {0xC2C1BC64, 0x6A0D403F, 0xE106FFB9, 0x7D99AE7C, 0x1CB2E8BB},
	{0x21BCA3F4, 0xAD7E513C, 0xDA4F6346, 0x3899A15F, 0x0FF0D772} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5757 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5758 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5759 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5760 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5761 infinity");
	}
	{
		static const bigint_t var_t = {0xA58D4F43, 0x55FCFB41, 0x1916B4F8, 0x140FC3C7, 0x05B830E5};
		static ecpoint_fp2 var_expected = { { {0x8EC1EDB3, 0xEEF0744A, 0xDACEC856, 0xD3FD0524, 0x0CE4BEF9},
	{0xA462CB91, 0xF8C8ABDE, 0xC694F504, 0x3CB6805C, 0x03EEDE5E} } ,
	 { {0x33C336E0, 0x6EB4AC4D, 0x361A72D0, 0x34052E40, 0x149B62CF},
	{0xF927CFEE, 0xC8EDF255, 0xFD4E0323, 0xC42E0342, 0x2338029E} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5762 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5763 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5764 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5765 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5766 infinity");
	}
	{
		static const bigint_t var_t = {0xD8A5BC6C, 0xE50E671F, 0xA1BDAED4, 0x2C67F3EA, 0x10F30E8E};
		static ecpoint_fp2 var_expected = { { {0x7636C894, 0x1B648743, 0xEB193D48, 0xBA46D55A, 0x06D929DD},
	{0xBB25B192, 0xC7132500, 0x9D923C2F, 0x11A89238, 0x2394BC11} } ,
	 { {0xD3F97024, 0xF30E788D, 0x67B4DE34, 0xB87D2819, 0x0C796D2A},
	{0x8AA4E863, 0xCD0A163D, 0x9BF46C56, 0xBFEEEE5B, 0x00C2FB7D} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5767 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5768 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5769 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5770 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5771 infinity");
	}
	{
		static const bigint_t var_t = {0x1E22BB69, 0xCB7246A8, 0xDC68D1C7, 0xD2B7E57B, 0x02C887D0};
		static ecpoint_fp2 var_expected = { { {0x546F177E, 0x61110F0D, 0xE0C4B4F1, 0xF5433871, 0x1B1D9F3B},
	{0x5D097D93, 0xFEB1B986, 0x69261E31, 0x76BAFBAE, 0x17E76717} } ,
	 { {0xC72F1F2B, 0xA77D4505, 0x64AE84B6, 0x731926A7, 0x10BE973A},
	{0x6139A84F, 0x8276A64D, 0xA8D08B7C, 0x593E4BBD, 0x0136C72A} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5772 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5773 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5774 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5775 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5776 infinity");
	}
	{
		static const bigint_t var_t = {0x2CD3305D, 0xE793EDA5, 0xC0F77C66, 0xC89B3030, 0x1C8B98C9};
		static ecpoint_fp2 var_expected = { { {0x975D96E6, 0xC97CB06C, 0x03D51A7A, 0x900FCAC4, 0x1E12BE32},
	{0x0B1EA354, 0xB3F0E1CA, 0xFC273549, 0xB22E87EE, 0x1D4274AF} } ,
	 { {0x29BC7DFC, 0xC61AC5A1, 0x4ADC9CF9, 0xF89CECEA, 0x1826A7FA},
	{0xC3271899, 0xE0032585, 0xF0B88662, 0x48590B05, 0x0DF47D74} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5777 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5778 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5779 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5780 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5781 infinity");
	}
	{
		static const bigint_t var_t = {0xE64FF4EC, 0x904C3A47, 0x3DA25383, 0x29B397DC, 0x0F31EE07};
		static ecpoint_fp2 var_expected = { { {0x41D02949, 0x051A3141, 0x40BAC4BE, 0xDC1052B7, 0x0599E3FB},
	{0xC0B05067, 0xA90B42A9, 0x5F337778, 0xE099A340, 0x0E40DA85} } ,
	 { {0x1BC01AD8, 0xFF97E58F, 0xD2721661, 0xD562597A, 0x1D210243},
	{0x3D320124, 0x727BA41A, 0xA0852C7D, 0xD75520C9, 0x158DA54B} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5782 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5783 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5784 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5785 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5786 infinity");
	}
	{
		static const bigint_t var_t = {0xF395DF29, 0xB81FC244, 0x16F37E50, 0x717B006C, 0x0A53C19B};
		static ecpoint_fp2 var_expected = { { {0x0C0A56FF, 0xBBF5A318, 0x051A1F98, 0x5E8554C2, 0x17B896C6},
	{0x117CB1B8, 0x101A0A61, 0x23D119D5, 0x3C887626, 0x14352C22} } ,
	 { {0x40B903A2, 0xF77E31F7, 0x4D37B4AB, 0xE3860ED7, 0x1C8561E7},
	{0x24404540, 0x70B58230, 0x6F3851F9, 0x728691ED, 0x14EB728B} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5787 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5788 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5789 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5790 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5791 infinity");
	}
	{
		static const bigint_t var_t = {0x64BDB9E3, 0xACE170FF, 0x9456289D, 0xBEEF305E, 0x1A84A1F9};
		static ecpoint_fp2 var_expected = { { {0xAA6E512C, 0x0979B606, 0x7BE59D41, 0x514169F5, 0x141E8A26},
	{0x6B08776E, 0x7684319F, 0x6666B06F, 0x9B4583D9, 0x18E6F037} } ,
	 { {0xC69DF210, 0x07FDD273, 0xFC5F28A1, 0x8F13C7B1, 0x10C8A6EA},
	{0xFFE31919, 0x5FA33D00, 0xB153A5C1, 0xE843AEEB, 0x12F7AA5A} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5792 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5793 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5794 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5795 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5796 infinity");
	}
	{
		static const bigint_t var_t = {0x59F51C38, 0x14551795, 0x652821A5, 0x24286BAD, 0x081ED183};
		static ecpoint_fp2 var_expected = { { {0xE4D806CC, 0xB43EB8DC, 0x0993DA6B, 0x7AB05D87, 0x0C362222},
	{0x5455D015, 0xB546F0B3, 0xAD39A6D9, 0xC25F83DF, 0x1C7F679C} } ,
	 { {0x14E29A16, 0xB255019E, 0xFC955A47, 0x4EABFB6E, 0x08C20012},
	{0x8E7B3EC1, 0x866D8AF7, 0x251BB0E1, 0xF94DF104, 0x05948D62} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5797 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5798 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5799 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5800 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5801 infinity");
	}
	{
		static const bigint_t var_t = {0x821D8C44, 0xB927FE66, 0xA01A9A39, 0x3F312FB1, 0x15CB2E3B};
		static ecpoint_fp2 var_expected = { { {0x387F6C76, 0x2451CB5F, 0x73ED54FE, 0x43F814FC, 0x0D490DBE},
	{0x7F43520D, 0x534DB79D, 0x720F30CB, 0x0CD8E5EE, 0x1FBA7EA9} } ,
	 { {0x76EE79E0, 0x34EC27A5, 0xA64F1D66, 0x9E09E883, 0x15E601E5},
	{0xA0437884, 0x664CFFDA, 0x5C79B6CB, 0x319FA405, 0x098B8F07} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5802 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5803 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5804 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5805 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5806 infinity");
	}
	{
		static const bigint_t var_t = {0x286795FD, 0x9F18D4FA, 0xCE8D794D, 0x94B88EE9, 0x0B34D3DB};
		static ecpoint_fp2 var_expected = { { {0xFCA8B769, 0xFB884CAE, 0x9ADBA2D3, 0x420B2DB1, 0x0601DA00},
	{0x8BC620D8, 0x6038751E, 0xC6736DD3, 0x03E84EBC, 0x0EEC5BE4} } ,
	 { {0xCC9007DF, 0x69A92216, 0xA7AC4F2B, 0x0F0FA61D, 0x2006B786},
	{0x424A7CA2, 0xE78FB627, 0x55DC56F9, 0xDECC06D4, 0x1304873B} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5807 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5808 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5809 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5810 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5811 infinity");
	}
	{
		static const bigint_t var_t = {0x8B76318E, 0xC865FAB1, 0x1535B249, 0x61CD7319, 0x0BEEDF29};
		static ecpoint_fp2 var_expected = { { {0xE2D31A8E, 0x562A20A1, 0x81FF1044, 0x9AE9CFC5, 0x1221DA28},
	{0x10CD0CBA, 0x5BF2F7D2, 0xD4541E6A, 0x803B20F3, 0x1B772DE1} } ,
	 { {0xA05EE51E, 0xC8E5E6B4, 0x7224E49D, 0xB191C97C, 0x11F2FA6C},
	{0x379C02CE, 0x7132E19F, 0x41ABA8FC, 0x7B1D60C2, 0x184E16D1} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5812 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5813 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5814 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5815 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5816 infinity");
	}
	{
		static const bigint_t var_t = {0x3C8C5612, 0x6AFDD3C7, 0xCC109728, 0x7DD35FC2, 0x00BF0E20};
		static ecpoint_fp2 var_expected = { { {0x4CF730C6, 0xAA5858FD, 0x89054EF1, 0x85DA31A5, 0x155443D2},
	{0xD6E5A355, 0xF52C6F7D, 0xA1FFEEE3, 0x8F25C0A0, 0x1C3FCFF0} } ,
	 { {0x0A7AE369, 0x517E17FE, 0xC1BBA5D3, 0xBCFAA8EB, 0x0317B66A},
	{0x48C36D18, 0xE6B1E13E, 0x9D3AF7C6, 0xFC0048BF, 0x2110B583} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5817 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5818 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5819 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5820 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5821 infinity");
	}
	{
		static const bigint_t var_t = {0x7E4081E2, 0x3216BAF5, 0x5B26A72A, 0x3BF0CBB5, 0x041BEC52};
		static ecpoint_fp2 var_expected = { { {0x9EFCF386, 0xDC7B1C4B, 0x5F00C4DE, 0x90E05BF2, 0x0E28035A},
	{0x8E382143, 0x9EA0DDBF, 0xE1BC9BBC, 0x19C21811, 0x0F8ADD8A} } ,
	 { {0xF648CF11, 0x701946E8, 0xCC08F95C, 0xEDD4AB5A, 0x0775D3AC},
	{0x0DB512D2, 0xC8B721CE, 0xCB98EA28, 0xC7657787, 0x0F80BED2} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5822 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5823 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5824 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5825 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5826 infinity");
	}
	{
		static const bigint_t var_t = {0xF5A025DE, 0x2179E122, 0x65851581, 0x7FE829FC, 0x1F86FB73};
		static ecpoint_fp2 var_expected = { { {0x04475739, 0x8A56054D, 0x0EF8F316, 0x10B83607, 0x18F6E5E1},
	{0x668BD48A, 0xE7141E78, 0x9A7829DF, 0x26BC5AE5, 0x1F93B9A7} } ,
	 { {0xAA0B6BAB, 0x09534AB9, 0xD199AAD7, 0x3D4B8597, 0x0C09FBD5},
	{0x23000512, 0x2ED0CDEB, 0xBCC0C11A, 0xF1F39AE8, 0x04A4EBFE} } ,
	0};
		ecfp2_hash_to_point(&var_res, var_t);
		assert_bi_equal(var_expected.x[0], var_res.x[0], "ecfp2_hash_to_point 5827 a.x[0]");
		assert_bi_equal(var_expected.x[1], var_res.x[1], "ecfp2_hash_to_point 5828 a.x[1]");
		assert_bi_equal(var_expected.y[0], var_res.y[0], "ecfp2_hash_to_point 5829 a.y[0]");
		assert_bi_equal(var_expected.y[1], var_res.y[1], "ecfp2_hash_to_point 5830 a.y[1]");
		assert_equal(var_expected.infinity,var_res.infinity, "ecfp2_hash_to_point 5831 infinity");
	}
#endif
#endif
	return 0;
}
