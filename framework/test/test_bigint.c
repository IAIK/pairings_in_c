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

#include "bigint/bi.h"

int main (void) {
	bigint_t var_tmp;
	word_t   var_res[2*BI_WORDS];

#if PRECISION == 256
	{
		static const bigint_t var_a = {0xDD2201F8, 0x3060854B, 0x812712C8, 0xD9E3F220, 0x76DC58E5, 0x995D0C4A, 0x3DD3D846, 0xC3A474A2};
		static const bigint_t var_b = {0xA041697E, 0xCB0EF7AB, 0xB367F31C, 0xD4EE6070, 0x4688DBA6, 0x19A654AD, 0x7CF5A363, 0x4CEB0DBD};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 141 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 128 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 131 ");
		//assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 131b ");
	}
	{
		static const bigint_t var_a = {0x9D882303, 0x7B56E883, 0x599E1EEF, 0x3F19870B, 0xFD9998DB, 0x0918352C, 0x59F0B395, 0x0C3F2E09};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 1 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 2 ");
	}
	{
		static const bigint_t var_a = {0xEAF714B8, 0x69893982, 0xE594B095, 0xC37EEB58, 0x01D05EDD, 0x3CB905F8, 0x1F29C9DA, 0x93B2F89E};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 3 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 4 ");
	}
	{
		static const bigint_t var_a = {0x879EBF2D, 0xE3187D4A, 0xA9C26C71, 0xDF024E5F, 0x5E57FF63, 0x03801264, 0x4EA86908, 0x6C2180FC};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 5 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 6 ");
	}
	{
		static const bigint_t var_a = {0x7C993A71, 0x7E73CAA6, 0x28B0817F, 0xAF9C8652, 0xDB9ACDAF, 0xEBA0AC1A, 0x76525248, 0x38DEB573};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 7 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 8 ");
	}
	{
		static const bigint_t var_a = {0xB45295CB, 0xC249B07C, 0x29078C75, 0x226F44E3, 0xE00B5E57, 0x311B5731, 0x2C61AC79, 0x2D12C4CA};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 9 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 10 ");
	}
	{
		static const bigint_t var_a = {0x80B99631, 0xAC585762, 0x38F7D740, 0x7CEFCF7F, 0xFDD27A44, 0x48DBE993, 0x897FF9EC, 0x957BD2FF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 11 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 12 ");
	}
	{
		static const bigint_t var_a = {0x150BFB19, 0x2C044438, 0x24AABA11, 0xD45B7B53, 0x6410CE4B, 0x57AD0623, 0xACF6B6E1, 0x4D7C34C0};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 13 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 14 ");
	}
	{
		static const bigint_t var_a = {0x092B72F5, 0xA8C1C00E, 0x7FC8F5B7, 0x97813BAE, 0x6AAC634A, 0xB8FF49D0, 0x33EA89FF, 0x4778DAF8};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 15 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 16 ");
	}
	{
		static const bigint_t var_a = {0xDA8BE0E9, 0x78523BB5, 0x220E5701, 0x03D42273, 0x0AB86436, 0x7B75E125, 0xC6A406AD, 0x08842007};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 17 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 18 ");
	}
	{
		static const bigint_t var_a = {0x67A7A460, 0x67CE1E11, 0xA6EE0500, 0xADD2B889, 0x615DAE1A, 0xE14872F2, 0x8DF46496, 0x2A63541A};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 19 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 20 ");
	}
	{
		static const bigint_t var_a = {0x7507E36D, 0x387EF4C0, 0xEB49319A, 0xFBBF6713, 0x33602687, 0xE17D7945, 0xB497B3EE, 0xDBD68C47};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 21 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 22 ");
	}
	{
		static const bigint_t var_a = {0x2BDE1A15, 0x1F86D59F, 0x95300F89, 0xABA77A53, 0x652EEF99, 0xA6E48F83, 0xEEB85CF6, 0x5D3CACAA};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 23 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 24 ");
	}
	{
		static const bigint_t var_a = {0x962E85F5, 0x44607774, 0x8AB860F9, 0x4AB565CD, 0x8180DD67, 0x0EEC3B1D, 0xEF7B0D1A, 0x847BA8B0};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 25 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 26 ");
	}
	{
		static const bigint_t var_a = {0x268500F7, 0x44275D76, 0x75E1EB53, 0xBEDA521A, 0x358AD134, 0x2D443B5E, 0xF199528D, 0x3B457250};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 27 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 28 ");
	}
	{
		static const bigint_t var_a = {0x2F408B26, 0xAFB0F75A, 0x46899D50, 0xBDC62C5C, 0xD4BAD59E, 0xC8506EDE, 0x300E7C9C, 0xFFA11589};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 29 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 30 ");
	}
	{
		static const bigint_t var_a = {0x69688E0F, 0x8B77BE4B, 0xB070455B, 0x532BA201, 0xD30D2599, 0xDB6BCF58, 0x6ED29911, 0x62D0EDF4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 31 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 32 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 41 ");
		assert_true(carry == 1, "bi_add 42 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 33 ");
		assert_true(carry == 0, "bi_add 34 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 35 ");
		assert_true(carry == 0, "bi_add 36 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 37 ");
		assert_true(carry == 0, "bi_add 38 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 39 ");
		assert_true(carry == 0, "bi_add 40 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 43 ");
		assert_true(carry == 1, "bi_add 44 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 45 ");
		assert_true(carry == 1, "bi_add 46 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 47 ");
		assert_true(carry == 0, "bi_add 48 (carry)");
	}
	{
		static const bigint_t var_a = {0x71197B85, 0xCF568B7D, 0xAA4F1E7D, 0x6054DBC3, 0x4DEB7AD6, 0x14F81F10, 0x70ABA3F0, 0x897306A3};
		static const bigint_t var_b = {0x467A7CFF, 0xE913C320, 0xEFF99372, 0x180EDC63, 0x80984E0C, 0x55433574, 0x7E051E7F, 0xAF1104B1};
		static const bigint_t var_expected = {0xB793F884, 0xB86A4E9D, 0x9A48B1F0, 0x7863B827, 0xCE83C8E2, 0x6A3B5484, 0xEEB0C26F, 0x38840B54};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 49 ");
		assert_true(carry == 1, "bi_add 50 (carry)");
	}
	{
		static const bigint_t var_a = {0xCC45405E, 0x39B91409, 0x7E93F950, 0x81DBCBB2, 0x4E38DC4A, 0x35390F6E, 0xE7E0CD03, 0xA0E22D51};
		static const bigint_t var_b = {0x4CE31732, 0x94C0D9BA, 0x1AD52124, 0xF87C9EDD, 0xBD5B1D80, 0x80E52294, 0x7BCE4DEB, 0x3EEE7201};
		static const bigint_t var_expected = {0x19285790, 0xCE79EDC4, 0x99691A74, 0x7A586A8F, 0x0B93F9CB, 0xB61E3203, 0x63AF1AEE, 0xDFD09F53};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 51 ");
		assert_true(carry == 0, "bi_add 52 (carry)");
	}
	{
		static const bigint_t var_a = {0xF20EF45D, 0xC20D6183, 0xCA600B38, 0xADC6D6C9, 0x7722131E, 0xB3C6828B, 0x0FFC9506, 0x007B84B9};
		static const bigint_t var_b = {0x4E12FD41, 0xFFB8AEE0, 0x5A261357, 0x22C75D8E, 0x4BEB03C7, 0x81F0CE05, 0xFD50C968, 0x6ECC5FBF};
		static const bigint_t var_expected = {0x4021F19E, 0xC1C61064, 0x24861E90, 0xD08E3458, 0xC30D16E5, 0x35B75090, 0x0D4D5E6F, 0x6F47E479};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 53 ");
		assert_true(carry == 0, "bi_add 54 (carry)");
	}
	{
		static const bigint_t var_a = {0xD48CC96E, 0x7EA97AC4, 0xD9D75E21, 0xAF3DA8B8, 0xAA948ED4, 0x50FE161F, 0xA19AD901, 0xA631E1A2};
		static const bigint_t var_b = {0x5CCC7540, 0xE1FF772D, 0x196E71C6, 0x0161A41B, 0x2B4DB588, 0xBCD5175A, 0xDDC8D473, 0xDA633A9A};
		static const bigint_t var_expected = {0x31593EAE, 0x60A8F1F2, 0xF345CFE8, 0xB09F4CD3, 0xD5E2445C, 0x0DD32D79, 0x7F63AD75, 0x80951C3D};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 55 ");
		assert_true(carry == 1, "bi_add 56 (carry)");
	}
	{
		static const bigint_t var_a = {0xA2B51DA7, 0xC3502F29, 0x33BD1BD6, 0x97F5295B, 0x07F441BA, 0x14397F1C, 0x953AEDC8, 0xD034661A};
		static const bigint_t var_b = {0xC73C7BD0, 0x2EAFF58F, 0x00193B92, 0x44B4E643, 0x9D0926D8, 0xD8291F58, 0x341A8FA0, 0x618DF30F};
		static const bigint_t var_expected = {0x69F19977, 0xF20024B9, 0x33D65768, 0xDCAA0F9E, 0xA4FD6892, 0xEC629E74, 0xC9557D68, 0x31C25929};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 57 ");
		assert_true(carry == 1, "bi_add 58 (carry)");
	}
	{
		static const bigint_t var_a = {0xCE6DAB5C, 0x2587CAB3, 0xA009F826, 0xB0000145, 0xEF2FB831, 0x411B3B01, 0x26CA1422, 0xFABBC18D};
		static const bigint_t var_b = {0x20055C46, 0x1C4826CA, 0xF70F7773, 0xD7EFEA0D, 0x243BF18B, 0xB9F4580D, 0x5C61EC83, 0x1E138820};
		static const bigint_t var_expected = {0xEE7307A2, 0x41CFF17D, 0x97196F99, 0x87EFEB53, 0x136BA9BD, 0xFB0F930F, 0x832C00A5, 0x18CF49AD};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 59 ");
		assert_true(carry == 1, "bi_add 60 (carry)");
	}
	{
		static const bigint_t var_a = {0x0998E3AC, 0x7ADF0310, 0x2B7A2D99, 0x889E1F68, 0x04D20A2E, 0x5EE43FF9, 0xCB37403E, 0xE1D74237};
		static const bigint_t var_b = {0x384D063D, 0x1E03AF86, 0x28484C5C, 0xE7D7C4E1, 0x7F9E21BA, 0x84010F40, 0xED827410, 0x6E80DF39};
		static const bigint_t var_expected = {0x41E5E9E9, 0x98E2B296, 0x53C279F5, 0x7075E449, 0x84702BE9, 0xE2E54F39, 0xB8B9B44E, 0x50582171};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 61 ");
		assert_true(carry == 1, "bi_add 62 (carry)");
	}
	{
		static const bigint_t var_a = {0x4325690B, 0xD74B21AF, 0x1C20F37B, 0xEB0B6BC3, 0x260EBD58, 0x30BF95C0, 0x3E020CD9, 0x8342C2F8};
		static const bigint_t var_b = {0x21D3F551, 0xEB1FF8D8, 0xFB521D8D, 0xE1956518, 0xB0A25EF8, 0x9D2E58C9, 0xC0BBC5DF, 0xF0F1FE18};
		static const bigint_t var_expected = {0x64F95E5C, 0xC26B1A87, 0x17731109, 0xCCA0D0DC, 0xD6B11C51, 0xCDEDEE89, 0xFEBDD2B8, 0x7434C110};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 63 ");
		assert_true(carry == 1, "bi_add 64 (carry)");
	}
	{
		static const bigint_t var_a = {0xAE24B1A7, 0x916D4D71, 0xFCF07A8F, 0xE7527546, 0x77D27AA4, 0xBB11E966, 0x77C8059A, 0x1C2F5F02};
		static const bigint_t var_b = {0x2AFBC5F8, 0x7735FD3C, 0x1AEEA767, 0x7288BFCE, 0xF8787D41, 0xABBD839B, 0xEE30DB21, 0x80E58F9D};
		static const bigint_t var_expected = {0xD920779F, 0x08A34AAD, 0x17DF21F7, 0x59DB3515, 0x704AF7E6, 0x66CF6D02, 0x65F8E0BC, 0x9D14EEA0};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 65 ");
		assert_true(carry == 0, "bi_add 66 (carry)");
	}
	{
		static const bigint_t var_a = {0xBAD3C6BA, 0x3CE52191, 0x935673A6, 0xC81A4B57, 0x57D7BB4D, 0x44CD0F5A, 0xB1D93490, 0x291A10E2};
		static const bigint_t var_b = {0xE6DF6797, 0xF781D16B, 0x6D932889, 0x87137E09, 0xD82476A1, 0x91A3F879, 0xD17F172B, 0x3A0ABBCC};
		static const bigint_t var_expected = {0xA1B32E51, 0x3466F2FD, 0x00E99C30, 0x4F2DC961, 0x2FFC31EF, 0xD67107D4, 0x83584BBB, 0x6324CCAF};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 67 ");
		assert_true(carry == 0, "bi_add 68 (carry)");
	}
	{
		static const bigint_t var_a = {0x19AE330E, 0xAEA265C6, 0xECBE0CEB, 0x1C7855A7, 0x67AF4A8A, 0x51BE825C, 0x63C5E6E0, 0x689907D9};
		static const bigint_t var_b = {0x2562FC5B, 0xE03AD899, 0x1D0982F4, 0x4D705176, 0x118CBC08, 0x76D888A7, 0x014E13DA, 0x7C105780};
		static const bigint_t var_expected = {0x3F112F69, 0x8EDD3E5F, 0x09C78FE0, 0x69E8A71E, 0x793C0692, 0xC8970B03, 0x6513FABA, 0xE4A95F59};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 69 ");
		assert_true(carry == 0, "bi_add 70 (carry)");
	}
	{
		static const bigint_t var_a = {0xBC7D0B4D, 0xFC34FFD4, 0x4F2C83B0, 0xB0BC4F44, 0x89D7AF68, 0xA7DCCA4C, 0x47EBBF02, 0xD52BED93};
		static const bigint_t var_b = {0xF738527D, 0xE7DCB0F3, 0x95F16855, 0x317DCE57, 0xA486FDE7, 0xBDA73810, 0x57D92F4E, 0xE3796B7F};
		static const bigint_t var_expected = {0xB3B55DCA, 0xE411B0C8, 0xE51DEC06, 0xE23A1D9B, 0x2E5EAD4F, 0x6584025D, 0x9FC4EE51, 0xB8A55912};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 71 ");
		assert_true(carry == 1, "bi_add 72 (carry)");
	}
	{
		static const bigint_t var_a = {0xD36A1CF0, 0x7A1A1BFD, 0x45C52BFA, 0x90475112, 0xDDC680A0, 0x499BE2E2, 0x560B101E, 0xAD09EAA2};
		static const bigint_t var_b = {0xB00108D7, 0x027CD76E, 0x7B5B93A5, 0xE08DE268, 0xD2EE3F75, 0x0D007AB3, 0xEC87EDA7, 0x4C6907FD};
		static const bigint_t var_expected = {0x836B25C7, 0x7C96F36C, 0xC120BF9F, 0x70D5337A, 0xB0B4C016, 0x569C5D96, 0x4292FDC5, 0xF972F2A0};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 73 ");
		assert_true(carry == 0, "bi_add 74 (carry)");
	}
	{
		static const bigint_t var_a = {0xD00B43D6, 0xBF108601, 0x97640621, 0x0A55EB1B, 0xC5FE9254, 0x7F388BC8, 0xC8D56A6B, 0x6EF4894E};
		static const bigint_t var_b = {0xDE4F5212, 0x6513F942, 0xBA51ECBC, 0x483BDBC4, 0x1CB169BB, 0x49C3DB53, 0x1A7806CC, 0xD4726CBA};
		static const bigint_t var_expected = {0xAE5A95E8, 0x24247F44, 0x51B5F2DE, 0x5291C6E0, 0xE2AFFC0F, 0xC8FC671B, 0xE34D7137, 0x4366F608};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 75 ");
		assert_true(carry == 1, "bi_add 76 (carry)");
	}
	{
		static const bigint_t var_a = {0x6475E2D9, 0x9D643BB9, 0x4E29D340, 0xAACE5A65, 0xE11A1308, 0xCB0D96B1, 0x187B84A9, 0xD40670A6};
		static const bigint_t var_b = {0x53BD65CC, 0x85D5FBA0, 0x7B6BCB95, 0x94330221, 0x42DC28D5, 0x98162DB1, 0x79104D62, 0xD76B8D49};
		static const bigint_t var_expected = {0xB83348A5, 0x233A3759, 0xC9959ED6, 0x3F015C86, 0x23F63BDE, 0x6323C463, 0x918BD20C, 0xAB71FDEF};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 77 ");
		assert_true(carry == 1, "bi_add 78 (carry)");
	}
	{
		static const bigint_t var_a = {0x7F4A80F4, 0x2C422761, 0xB206AC55, 0x3E1BCE2F, 0x12E17F47, 0xF4DF2159, 0xFD3B5203, 0xDC84DFE6};
		static const bigint_t var_b = {0x21FA846B, 0x177CBB7C, 0x265C304E, 0x330ACDE4, 0x46B140F4, 0x5DB214D2, 0xE38F4E89, 0xF43AE12C};
		static const bigint_t var_expected = {0xA145055F, 0x43BEE2DD, 0xD862DCA3, 0x71269C13, 0x5992C03B, 0x5291362B, 0xE0CAA08D, 0xD0BFC113};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 79 ");
		assert_true(carry == 1, "bi_add 80 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 81 ");
		assert_true(carry == 0, "bi_subtract 82 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 83 ");
		assert_true(carry == 0, "bi_subtract 84 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 85 ");
		assert_true(carry, "bi_subtract 86 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 87 ");
		assert_true(carry == 0, "bi_subtract 88 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 89 ");
		assert_true(carry == 0, "bi_subtract 90 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 91 ");
		assert_true(carry, "bi_subtract 92 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 93 ");
		assert_true(carry == 0, "bi_subtract 94 (carry)");
	}
	{
		static const bigint_t var_a = {0x53CC84C1, 0xBF041D23, 0x4E542233, 0xD2EEBED9, 0x7A5189C6, 0xFF2ECC88, 0x70F96EFF, 0xC4AB1892};
		static const bigint_t var_b = {0x97DCB293, 0x1198797E, 0x6583022F, 0xD007A1ED, 0x6AB33A16, 0x3E321C22, 0x6F9DB9F7, 0x06A889D1};
		static const bigint_t var_expected = {0xBBEFD22E, 0xAD6BA3A4, 0xE8D12004, 0x02E71CEB, 0x0F9E4FB0, 0xC0FCB066, 0x015BB508, 0xBE028EC1};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 95 ");
		assert_true(carry == 0, "bi_subtract 96 (carry)");
	}
	{
		static const bigint_t var_a = {0x51EA1E71, 0xEC860187, 0xEA5DE0BD, 0xB51A60C9, 0x79B6D3F3, 0x3086D68E, 0xACC4C351, 0x078289DA};
		static const bigint_t var_b = {0x4871086C, 0xA6E10171, 0x217D5442, 0x5AFA2A0B, 0x2DB87B87, 0x20652F69, 0x78D88884, 0x2B2CCEA0};
		static const bigint_t var_expected = {0x09791605, 0x45A50016, 0xC8E08C7B, 0x5A2036BE, 0x4BFE586C, 0x1021A725, 0x33EC3ACD, 0xDC55BB3A};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 97 ");
		assert_true(carry, "bi_subtract 98 (carry)");
	}
	{
		static const bigint_t var_a = {0x29524C7C, 0x887229C3, 0x8FF3CE10, 0x715D1F0E, 0xB0B49E43, 0x0DCC3FC8, 0x286F74A8, 0x65A7D23A};
		static const bigint_t var_b = {0x040BAF25, 0x4D8882C1, 0x81B1AB41, 0xFD044B81, 0x51F7BC95, 0x289D8FE1, 0x9668F14E, 0xBFC1EAA5};
		static const bigint_t var_expected = {0x25469D57, 0x3AE9A702, 0x0E4222CF, 0x7458D38D, 0x5EBCE1AD, 0xE52EAFE7, 0x92068359, 0xA5E5E794};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 99 ");
		assert_true(carry, "bi_subtract 100 (carry)");
	}
	{
		static const bigint_t var_a = {0xCD7F05AB, 0xA790EB20, 0x86F9BE76, 0xD5323BA6, 0x015B50B2, 0x5A92D123, 0x9E1A10CD, 0xD824A058};
		static const bigint_t var_b = {0xDC527E75, 0xBA8218E6, 0xF1E44BE5, 0x2670941C, 0xD71AE912, 0xBBFF3AF1, 0xA28D15FF, 0x61B43285};
		static const bigint_t var_expected = {0xF12C8736, 0xED0ED239, 0x95157290, 0xAEC1A789, 0x2A4067A0, 0x9E939631, 0xFB8CFACD, 0x76706DD2};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 101 ");
		assert_true(carry == 0, "bi_subtract 102 (carry)");
	}
	{
		static const bigint_t var_a = {0x6ECD8D3D, 0x9F1967EA, 0x58F89661, 0xEEA36C95, 0x8C32E43F, 0x1C6621C3, 0x07C905B3, 0x9F3C568F};
		static const bigint_t var_b = {0x21583EF1, 0xE3DE0FC0, 0x18C886DD, 0x827961A6, 0x004F5D89, 0x7ED5C74B, 0xB62F7BD8, 0xED7087C1};
		static const bigint_t var_expected = {0x4D754E4C, 0xBB3B582A, 0x40300F83, 0x6C2A0AEF, 0x8BE386B6, 0x9D905A78, 0x519989DA, 0xB1CBCECD};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 103 ");
		assert_true(carry, "bi_subtract 104 (carry)");
	}
	{
		static const bigint_t var_a = {0x7C83E749, 0x05057E96, 0xCEAC04C8, 0x0817A539, 0xB34E3E65, 0x991F861E, 0x9CEC5C4C, 0x363A92BF};
		static const bigint_t var_b = {0x65A08D81, 0xFB11D84E, 0xDF870FFF, 0xFE237BC5, 0x4C528E42, 0x56DAB381, 0x2A6F4697, 0x7F55238D};
		static const bigint_t var_expected = {0x16E359C8, 0x09F3A648, 0xEF24F4C8, 0x09F42973, 0x66FBB022, 0x4244D29D, 0x727D15B5, 0xB6E56F32};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 105 ");
		assert_true(carry, "bi_subtract 106 (carry)");
	}
	{
		static const bigint_t var_a = {0xA9E86B9E, 0xAE590328, 0xF197B292, 0xB11FE08A, 0x165D62C4, 0x55320151, 0xD5F7B13D, 0x5B427F40};
		static const bigint_t var_b = {0x77376B59, 0x7948AC48, 0x705D526B, 0xC7075598, 0x7E851181, 0x688D2742, 0x97343851, 0x7581B8A2};
		static const bigint_t var_expected = {0x32B10045, 0x351056E0, 0x813A6027, 0xEA188AF2, 0x97D85142, 0xECA4DA0E, 0x3EC378EB, 0xE5C0C69E};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 107 ");
		assert_true(carry, "bi_subtract 108 (carry)");
	}
	{
		static const bigint_t var_a = {0xE55187BA, 0xAE7D1DF5, 0x0A8F0102, 0xB64E0933, 0x97B58E94, 0x16FD1B71, 0x6CED76CA, 0x0A23FF0F};
		static const bigint_t var_b = {0x6ABF6424, 0x11B6EF6D, 0x331ED0BD, 0x4A22DD95, 0x96FB098F, 0x19812DD4, 0xD6C070D3, 0x6CA5E3E3};
		static const bigint_t var_expected = {0x7A922396, 0x9CC62E88, 0xD7703045, 0x6C2B2B9D, 0x00BA8505, 0xFD7BED9D, 0x962D05F6, 0x9D7E1B2B};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 109 ");
		assert_true(carry, "bi_subtract 110 (carry)");
	}
	{
		static const bigint_t var_a = {0x623299AE, 0x5B86DC4B, 0xA24B4635, 0x2302F6AA, 0x556A3B8B, 0xE019B91B, 0x5AF07792, 0x8023A79E};
		static const bigint_t var_b = {0x8E80685C, 0xB8E53DAC, 0xD2CB7D87, 0x34A6DF81, 0xD489F981, 0x0EAB5D8C, 0x013DF635, 0x41D3F2B9};
		static const bigint_t var_expected = {0xD3B23152, 0xA2A19E9E, 0xCF7FC8AD, 0xEE5C1728, 0x80E04209, 0xD16E5B8E, 0x59B2815D, 0x3E4FB4E5};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 111 ");
		assert_true(carry == 0, "bi_subtract 112 (carry)");
	}
	{
		static const bigint_t var_a = {0x912BF8F3, 0x498804A9, 0x82FB8A3C, 0x463573C9, 0xB457FD42, 0xF9ADD995, 0xD8D3A3F9, 0x3BD490D4};
		static const bigint_t var_b = {0x74793BF8, 0xA3092F66, 0x352428A1, 0x73CBFE81, 0xBAD7F5D4, 0x2CB4FC43, 0x704AFF9D, 0x104E0076};
		static const bigint_t var_expected = {0x1CB2BCFB, 0xA67ED543, 0x4DD7619A, 0xD2697548, 0xF980076D, 0xCCF8DD51, 0x6888A45C, 0x2B86905E};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 113 ");
		assert_true(carry == 0, "bi_subtract 114 (carry)");
	}
	{
		static const bigint_t var_a = {0x221D1A8E, 0x4FE70B76, 0xB3D0D45D, 0xAB506771, 0x52344D61, 0xE5B9562A, 0x5EAB1853, 0xF7DEFE2B};
		static const bigint_t var_b = {0xED6E93E3, 0x484BD074, 0x8631DB1D, 0x329F3EA0, 0x096F413A, 0x98488F16, 0xBC920168, 0x385A612D};
		static const bigint_t var_expected = {0x34AE86AB, 0x079B3B01, 0x2D9EF940, 0x78B128D1, 0x48C50C27, 0x4D70C714, 0xA21916EB, 0xBF849CFD};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 115 ");
		assert_true(carry == 0, "bi_subtract 116 (carry)");
	}
	{
		static const bigint_t var_a = {0x0735E005, 0x80A64D83, 0x7E91ED76, 0x20FA074C, 0x12A132FC, 0x6A698EA8, 0xA75A7428, 0xB1D6D5FE};
		static const bigint_t var_b = {0x0AFCD4F1, 0x5B1BD0B7, 0x2EDA4DE6, 0xE0D32448, 0xC3CB4845, 0xB667E1EA, 0xBF578432, 0x540D69CF};
		static const bigint_t var_expected = {0xFC390B14, 0x258A7CCB, 0x4FB79F90, 0x4026E304, 0x4ED5EAB6, 0xB401ACBD, 0xE802EFF5, 0x5DC96C2E};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 117 ");
		assert_true(carry == 0, "bi_subtract 118 (carry)");
	}
	{
		static const bigint_t var_a = {0x71FF0610, 0x31B86FB3, 0x6C28B1A4, 0xB1E423BC, 0x1539D300, 0x8C630529, 0xAA256936, 0xA607E963};
		static const bigint_t var_b = {0x1CA2753C, 0xD1815E49, 0xD5705146, 0x28916C8B, 0x276C03CE, 0x2DB4818C, 0x9003B782, 0x421E7F71};
		static const bigint_t var_expected = {0x555C90D4, 0x6037116A, 0x96B8605D, 0x8952B730, 0xEDCDCF32, 0x5EAE839C, 0x1A21B1B4, 0x63E969F2};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 119 ");
		assert_true(carry == 0, "bi_subtract 120 (carry)");
	}
	{
		static const bigint_t var_a = {0xD076BAEF, 0xF94DFD8C, 0x4634DF98, 0xACA08077, 0xBAA1E59B, 0x901AFC7C, 0xA04096F7, 0x54471B39};
		static const bigint_t var_b = {0xB5D8011E, 0xDF6DC1AA, 0x644445F5, 0xF9434E3B, 0xB6E0B82E, 0xE1C3B05A, 0x8AB8CBFB, 0x1FB58A0E};
		static const bigint_t var_expected = {0x1A9EB9D1, 0x19E03BE2, 0xE1F099A3, 0xB35D323B, 0x03C12D6C, 0xAE574C22, 0x1587CAFB, 0x3491912B};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 121 ");
		assert_true(carry == 0, "bi_subtract 122 (carry)");
	}
	{
		static const bigint_t var_a = {0xD6134EE6, 0xAB2835A7, 0x15987047, 0x9E6B4C73, 0xA59A08E5, 0xFC1BF8ED, 0x0460A4D6, 0x77C45337};
		static const bigint_t var_b = {0xA41DC73A, 0xFA059D7E, 0x05308E62, 0x7F6E5B23, 0x33DC29BD, 0xF66FC4D1, 0x46E11562, 0x483BB136};
		static const bigint_t var_expected = {0x31F587AC, 0xB1229829, 0x1067E1E4, 0x1EFCF150, 0x71BDDF28, 0x05AC341C, 0xBD7F8F74, 0x2F88A200};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 123 ");
		assert_true(carry == 0, "bi_subtract 124 (carry)");
	}
	{
		static const bigint_t var_a = {0x74DD1841, 0x5DE80B27, 0x230B71D4, 0x5300A410, 0xB40DFE4D, 0x95604132, 0x8D48A660, 0x0DD7462D};
		static const bigint_t var_b = {0xFC042248, 0xD8F7EFA5, 0x212B124F, 0x2678EEF2, 0x9E431D20, 0xD324FF73, 0x9BC0ECE2, 0x592B696C};
		static const bigint_t var_expected = {0x78D8F5F9, 0x84F01B81, 0x01E05F84, 0x2C87B51E, 0x15CAE12D, 0xC23B41BF, 0xF187B97D, 0xB4ABDCC0};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 125 ");
		assert_true(carry, "bi_subtract 126 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 127 ");
	}

	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 129 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 130 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 132 ");
	}
	{
		static const bigint_t var_a = {0xDA7875D6, 0x635C62C1, 0xF7A85CEB, 0xD9662CB6, 0x0A1FCA96, 0x5F9C53BB, 0x355FBD10, 0x52D012BE};
		static const bigint_t var_b = {0xDA7875D6, 0x635C62C1, 0xF7A85CEB, 0xD9662CB6, 0x0A1FCA96, 0x5F9C53BB, 0x355FBD10, 0x52D012BE};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 133 ");
	}
	{
		static const bigint_t var_a = {0x0D497083, 0x6CC8C3D4, 0x60D9B7FC, 0x9D7D2EA2, 0x373E5162, 0x1B32DBD6, 0xA401525A, 0x31E1E02B};
		static const bigint_t var_b = {0x0D497083, 0x6CC8C3D4, 0x60D9B7FC, 0x9D7D2EA2, 0x373E5162, 0x1B32DBD6, 0xA401525A, 0x31E1E02B};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 134 ");
	}
	{
		static const bigint_t var_a = {0x7A39E602, 0x53D36FF7, 0x5B8101E9, 0x7CC4C043, 0x073DB647, 0x9F8E43C3, 0x3539028E, 0xC3CAB040};
		static const bigint_t var_b = {0x7A39E602, 0x53D36FF7, 0x5B8101E9, 0x7CC4C043, 0x073DB647, 0x9F8E43C3, 0x3539028E, 0xC3CAB040};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 135 ");
	}
	{
		static const bigint_t var_a = {0x68DAA609, 0xED2391F3, 0xAB1AEA7C, 0xD020A75F, 0x8145D0E3, 0xB51ACAD9, 0xB9475C8F, 0xEB69B9D9};
		static const bigint_t var_b = {0x68DAA609, 0xED2391F3, 0xAB1AEA7C, 0xD020A75F, 0x8145D0E3, 0xB51ACAD9, 0xB9475C8F, 0xEB69B9D9};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 136 ");
	}
	{
		static const bigint_t var_a = {0x04315D77, 0x026B6082, 0x5828E580, 0xCA2B340D, 0x4D3038F2, 0xDB5118BE, 0x062CB174, 0x1E7A399D};
		static const bigint_t var_b = {0x04315D77, 0x026B6082, 0x5828E580, 0xCA2B340D, 0x4D3038F2, 0xDB5118BE, 0x062CB174, 0x1E7A399D};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 137 ");
	}
	{
		static const bigint_t var_a = {0xDEEF8B80, 0xCF2D58E2, 0x2C9B1FE7, 0xEC587453, 0x3B35AA8A, 0xC4E4674B, 0x73BE65A0, 0xE5531516};
		static const bigint_t var_b = {0xDEEF8B80, 0xCF2D58E2, 0x2C9B1FE7, 0xEC587453, 0x3B35AA8A, 0xC4E4674B, 0x73BE65A0, 0xE5531516};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 138 ");
	}
	{
		static const bigint_t var_a = {0x6A3FA869, 0x85602723, 0x37462EC7, 0x8F6C2749, 0xBC2BBDB9, 0xD7AB1814, 0x60DD9A03, 0x5EFBFD44};
		static const bigint_t var_b = {0x6A3FA869, 0x85602723, 0x37462EC7, 0x8F6C2749, 0xBC2BBDB9, 0xD7AB1814, 0x60DD9A03, 0x5EFBFD44};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 139 ");
	}
	{
		static const bigint_t var_a = {0x811695C2, 0xC8D06C72, 0x4C636680, 0x5E4202C5, 0x675B11D4, 0xAE692282, 0xACA9FE17, 0xBC7EFB30};
		static const bigint_t var_b = {0x811695C2, 0xC8D06C72, 0x4C636680, 0x5E4202C5, 0x675B11D4, 0xAE692282, 0xACA9FE17, 0xBC7EFB30};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 140 ");
	}
	{
		static const bigint_t var_a = {0xCD87C1D0, 0x99D54255, 0x004DC615, 0xF54BA4CE, 0xDB79587B, 0x657371FC, 0xD603C698, 0xC7D5F99D};
		static const bigint_t var_b = {0xCEDA06FB, 0x0F5127B4, 0x4B19B644, 0x39352C18, 0x591E6708, 0xE809D6E3, 0x3CC639A5, 0xB48B947D};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 142 ");
	}
	{
		static const bigint_t var_a = {0xED183B6F, 0x953B9E3C, 0xBBFBF5F5, 0x6F8C1076, 0x8CD5B927, 0xC094A552, 0xA3653B92, 0x29C76414};
		static const bigint_t var_b = {0xDAD18D71, 0x08B81EE9, 0x3CF5EFE3, 0xBB8107A1, 0x6122E414, 0x41C8FD34, 0x85084A18, 0x4F13DC2C};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 143 ");
	}
	{
		static const bigint_t var_a = {0x2B8FB37E, 0x396CEE12, 0xFCCCBB17, 0x158AF9A5, 0x6B6B86EE, 0x705403CF, 0x5F7F10C3, 0xE55A705C};
		static const bigint_t var_b = {0xD7ACADAD, 0x6B6B8B08, 0xEF14D090, 0xC8A5AD43, 0x5F4B01DC, 0x89271A41, 0x31010784, 0xBCC6E8D7};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 144 ");
	}
	{
		static const bigint_t var_a = {0xBBC18434, 0xD9F0789E, 0x4C3E1FFB, 0xF3F647AE, 0x9871126B, 0x7A80F3A0, 0x01F8DFCB, 0x39ECF737};
		static const bigint_t var_b = {0x1598B7E5, 0x2EEAF875, 0x0EBE12AF, 0x0BA894A2, 0x9412FD02, 0x65D15B1E, 0x58DD1173, 0xD64B7DCC};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 145 ");
	}
	{
		static const bigint_t var_a = {0x0CB660B2, 0x0A527CDC, 0x75411673, 0x57225938, 0x74E81F9D, 0x2272F2DD, 0xC32610B2, 0xA01F08CE};
		static const bigint_t var_b = {0x257654FB, 0x845AD4F5, 0x82F2A4FA, 0x739425D0, 0x80C31A4D, 0xBA22358F, 0x5342052A, 0xBA797556};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 146 ");
	}
	{
		static const bigint_t var_a = {0xCFAFB9C1, 0xA3676E5A, 0x7ECC0AEB, 0xCEC860CE, 0xA1AAE584, 0xED5D8946, 0x1EA31F87, 0xD9B2C38A};
		static const bigint_t var_b = {0xD9EFDE95, 0xE4D92472, 0x73004C42, 0x2B4C8892, 0xE68B7B6B, 0xAD7B2DCF, 0xBCDDC395, 0xC72875C9};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 147 ");
	}
	{
		static const bigint_t var_a = {0xF6404E79, 0xB7A86E9B, 0xB169E458, 0x24E4DE3E, 0xFF7CFA0E, 0xA1A33B7C, 0xCAD435BC, 0xE14C1C02};
		static const bigint_t var_b = {0x408461C7, 0x02CDF79D, 0x4B12515B, 0xA2550372, 0xC58B5BB5, 0xA38F287B, 0x6AF58AAA, 0x9902EB93};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 148 ");
	}
	{
		static const bigint_t var_a = {0xB259D99D, 0x9C7BECFE, 0x98C79504, 0x667B2909, 0xB01E2411, 0x431E68CD, 0xC183F7BA, 0xF44D5F32};
		static const bigint_t var_b = {0xAD98382D, 0xD32F818C, 0xB2BE3097, 0x84ACEF5E, 0x5FE5B2A9, 0x41B5215A, 0x78F7C8EC, 0x0C526758};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 149 ");
	}
	{
		static const bigint_t var_a = {0x7458E6CE, 0xE78581DD, 0xFA482E8E, 0xE3720A40, 0x14590A59, 0x16741EFC, 0x3C689F9C, 0x8F9F96C3};
		static const bigint_t var_b = {0xB08858BD, 0x8CE5EF90, 0x92984E44, 0xBE9140FC, 0x35CD3A5B, 0x6C365B0B, 0x3F0AB81C, 0x3ED3464A};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 150 ");
	}
	{
		static const bigint_t var_a = {0xEC19C9D0, 0x6CFCFFD0, 0xE1946FDB, 0x255C718F, 0xCD0FCE0D, 0xA166E8A4, 0xB4BA5A18, 0x6F84BD20};
		static const bigint_t var_b = {0x19B637B1, 0xA308F6FB, 0x13BFAC02, 0x7D5B9FDB, 0x089AD627, 0x49A001DF, 0x569CBC3D, 0x8C83B14A};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 151 ");
	}
	{
		static const bigint_t var_a = {0x0C09BA84, 0x41F3B45C, 0x9726E7D5, 0xFC453952, 0xBA5084E5, 0xA922872A, 0xE2C3E901, 0x9268C987};
		static const bigint_t var_b = {0xFB985C3F, 0xCC3A058C, 0x9F6DA7F5, 0x2E451B38, 0xD9D4605C, 0x3D13435E, 0x98F48772, 0x9371ED82};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 152 ");
	}
	{
		static const bigint_t var_a = {0x042F1660, 0xBBADDE6A, 0xA3DD8B22, 0x738C02E5, 0xFF6395EF, 0x3290A44B, 0xBE6C84F1, 0x34B1866D};
		static const bigint_t var_b = {0xA7CF8F14, 0xFCF43EA5, 0xDE8BB41B, 0x7E3F6DFC, 0xE948DCA5, 0xEC92DA47, 0x1DC2FE66, 0x308D0579};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 153 ");
	}
	{
		static const bigint_t var_a = {0x4643C373, 0x6FEE5654, 0xCF8DDF3B, 0xD7A820A3, 0xFADBFFF4, 0x82A278C7, 0x82CE02EE, 0xD38C49D2};
		static const bigint_t var_b = {0xAC2EB2BD, 0x68D718A6, 0xBA3D2755, 0x5AC0CF21, 0xB9130971, 0x3D560F06, 0x3EACE340, 0x7F77C4DB};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 154 ");
	}
	{
		static const bigint_t var_a = {0x83BBB754, 0x31477167, 0x258F9497, 0xB6019C3A, 0x4EA57FAF, 0x1DA862B6, 0xA7C24932, 0x2AC37264};
		static const bigint_t var_b = {0xDCD03673, 0x85F9B4ED, 0x5B73F7E2, 0xEF926AB4, 0x09B55D99, 0x541728E3, 0x95E24550, 0xDE520383};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 155 ");
	}
	{
		static const bigint_t var_a = {0xACDBA676, 0x17690D23, 0xEC4DB7C0, 0xDDBA4744, 0xDC169958, 0xC89A767B, 0xE572FB66, 0x3885C88D};
		static const bigint_t var_b = {0x492741F7, 0x093AEE68, 0x2B798D66, 0xABA7520A, 0xDC1E6408, 0x95635281, 0xFAACB3F8, 0xEA924C61};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 156 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 157 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 158 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 159 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 160 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 161 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		word_t var_expected[16] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 162 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 163 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 164 ");
	}
	{
		static const bigint_t var_a = {0xF1C5D0C9, 0x7574DD9A, 0xAFDA5B8F, 0x5885EB4C, 0xC3018851, 0x896FFE73, 0x37E96BE9, 0x3A3DA3C8};
		static const bigint_t var_b = {0x43096777, 0xE88E18BB, 0xD28791AB, 0x39E41DFA, 0x71C57A26, 0xA7EBFD5A, 0x86FB308C, 0x80CCD263};
		word_t var_expected[16] = {0xEC05EC6F, 0x14C5FAB8, 0xFBB51619, 0xEE372BCF, 0x0BB1184A, 0x5F0CB16D, 0x3B13BD8C, 0x14117CC7, 0x52AADA43, 0xEBFBA5F8, 0x5B86166F, 0x70E72CB4, 0x8246E26D, 0xCDCDD4EA, 0xD4674177, 0x1D4D6ADF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 165 ");
	}
	{
		static const bigint_t var_a = {0xC38AF6AC, 0xE148E0B9, 0x357ACFE6, 0x756F81BC, 0x66C112E5, 0xA566EFC9, 0xD49FD9F8, 0xAC5EEED9};
		static const bigint_t var_b = {0x5AC416A3, 0x57557557, 0x3A54BFC4, 0x88F30A1E, 0x4AAFF93D, 0x6DD3AB50, 0x92F6F110, 0xBD85BB7D};
		word_t var_expected[16] = {0xC65DD784, 0x63C20EA6, 0xDD82EE53, 0x31ED914D, 0x83776F08, 0xB5A0D39F, 0x86476FEC, 0x5CBBB5AE, 0xC755F386, 0x8A436315, 0xB73BB59B, 0xB6BB6519, 0x58F0DBFE, 0x95E368BB, 0xCEEDA368, 0x7F9C21E6};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 166 ");
	}
	{
		static const bigint_t var_a = {0xD5387284, 0x30D50F58, 0x89354EA3, 0xC1B48748, 0x664B4164, 0xA05B530E, 0x3611EAE2, 0x4B36FDCC};
		static const bigint_t var_b = {0x612CA167, 0xCBA15B20, 0x8C9FBD44, 0xC315BD70, 0x2885BB31, 0x0E023289, 0xB88ED92A, 0xFE05BE5B};
		word_t var_expected[16] = {0xFC6B171C, 0x5936506D, 0xA3029E12, 0x72E9D7CD, 0x86BFF8E6, 0xE3C71002, 0xC0D60244, 0x1DAE68FC, 0x2244EDD1, 0xEF5645F1, 0xB94FFAC5, 0xD21FB717, 0x1D5817E8, 0x7CA2B305, 0x55C61BD8, 0x4AA23FD1};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 167 ");
	}
	{
		static const bigint_t var_a = {0x15ED7287, 0x77674358, 0xF2693CA0, 0x088E66DE, 0xA33FF81E, 0x3F15A680, 0x15486A88, 0x14BA33CE};
		static const bigint_t var_b = {0x69ABE702, 0xF98F1461, 0x30C7F99B, 0x59F08BD0, 0x0CA20A28, 0xED717229, 0xD00CBCA1, 0xDF25167D};
		word_t var_expected[16] = {0x4D5FB60E, 0x5DBBFD35, 0x57B6A274, 0x61F4155B, 0x6CC21C9F, 0x129444B4, 0x8AB87026, 0xA8E1F3DA, 0xF25A06C6, 0x6F08CBDB, 0xA0B5A73B, 0xED4DAA55, 0xF0AEA0AF, 0x6B7C07B2, 0x318A7BD0, 0x121133DC};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 168 ");
	}
	{
		static const bigint_t var_a = {0xB7E25C94, 0x0BFD4543, 0xFB58E4FF, 0x5701EA32, 0x3EF877F9, 0x88952628, 0x6C6F53D3, 0x45598341};
		static const bigint_t var_b = {0xC151AE5D, 0xD7926B37, 0xCF5487E4, 0xF65D6736, 0x3723F20A, 0xB18086A8, 0xF3A1653D, 0x3E1FCBAE};
		word_t var_expected[16] = {0x86FC39C4, 0xAEE0C6CC, 0x7814F139, 0xD69A782E, 0xF64388BE, 0xEE81E01D, 0x44F47A32, 0xA0E3891B, 0x1E2037F2, 0x81B23A4E, 0xEE3112B3, 0x85A6DF29, 0x071B1810, 0x0A1B0A53, 0x1D1ADF8C, 0x10D44ACE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 169 ");
	}
	{
		static const bigint_t var_a = {0x2A834D1D, 0x80922015, 0x6BB8B71D, 0xFCB1CF63, 0x9999BF9F, 0xBF691C24, 0x726213F7, 0x5ACCBBB1};
		static const bigint_t var_b = {0xFBE591DE, 0x99C4F2C1, 0x538E03A5, 0x873E4FAD, 0x2AF8F2FE, 0x3D3F5EC5, 0x7AF764F0, 0x395D4A26};
		word_t var_expected[16] = {0xA67B4C26, 0x4198205B, 0x29130C07, 0xF3A27968, 0xC30C1D8B, 0x0CACCD2C, 0x7D30AEFE, 0x381A357C, 0xF1A99D1C, 0x9E10BBEB, 0xFEDA7653, 0x513AA758, 0xA0DF0EF9, 0x96A62875, 0x8630DC43, 0x1458AC77};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 170 ");
	}
	{
		static const bigint_t var_a = {0x2076C37D, 0xAB739831, 0x4D4215D4, 0x84B06858, 0x5422D497, 0x69FA10D8, 0xA13C1994, 0x10E5AF75};
		static const bigint_t var_b = {0xE9F4A126, 0xB436FBA7, 0xE4057D53, 0x39475F57, 0xA6F21C31, 0xB7C1D362, 0xFFBE998A, 0x2B4C56B8};
		word_t var_expected[16] = {0x9AB6A18E, 0xAAC19B5F, 0xE380D4FF, 0xB4739177, 0x1037FE4B, 0x9F61B800, 0x1BC4BD99, 0x9050701E, 0xBFC7EEE0, 0xBBBA045C, 0x1567E673, 0x735FB23B, 0x5BA665CB, 0x6C5E1BBD, 0x37E9F53A, 0x02DB9E62};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 171 ");
	}
	{
		static const bigint_t var_a = {0x8AB16A4A, 0xA38BE1B4, 0xE84492FE, 0xBB4A4FCE, 0x517BEBB3, 0x4DDBFCD8, 0xB2E9A517, 0x655E2E28};
		static const bigint_t var_b = {0x9BE19E68, 0xDD4141D0, 0xEC295FA1, 0x79D26E0D, 0xABD68B9D, 0x846F32CF, 0x5A42876C, 0xB12949E9};
		word_t var_expected[16] = {0x10B6DA10, 0x10B5965B, 0xEBD0383C, 0x70B20FA1, 0xDD36F4DE, 0xEE608FC2, 0x30004015, 0x401923F5, 0x87CC0E1E, 0xF6F7453C, 0x8172F88F, 0xC5D89344, 0xB96D138E, 0xDC334503, 0xC9D744C1, 0x46267743};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 172 ");
	}
	{
		static const bigint_t var_a = {0x98890C6C, 0xBBB48495, 0xC732C861, 0xAFDB303F, 0xB0877BA5, 0x6D1B69C0, 0x9DB5E0F0, 0x95ACCE4F};
		static const bigint_t var_b = {0x61F5DB4B, 0x0AD64C5B, 0x14D561D9, 0xF4AF4466, 0x7C6A48AF, 0x4953323C, 0xA4F36AF4, 0xAAD4ABD3};
		word_t var_expected[16] = {0xBD2307A4, 0x7FF53492, 0x983B3543, 0xB2F31BCC, 0xD2A5651D, 0x76000173, 0xA51AD2A6, 0x3EC93203, 0xC3FDB275, 0xE2FD8E4A, 0xBFB5C155, 0x075A95A8, 0xA5F5D9B3, 0xA1534C21, 0xE457A1B0, 0x63E11891};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 173 ");
	}
	{
		static const bigint_t var_a = {0xBCC0A316, 0x89087A4C, 0xB232A661, 0xAD9BAB0C, 0xD2342DB2, 0x1095844A, 0x9CDC2F74, 0x1DCD91D3};
		static const bigint_t var_b = {0xCE6FC58B, 0x6ECA8536, 0x44DE7CD8, 0x97F45E32, 0x98868DDA, 0xEC6A676C, 0x37FD169E, 0x319D2022};
		word_t var_expected[16] = {0x24A27AF2, 0xBD992451, 0xFBB04563, 0xB89159B7, 0xD9B033CE, 0xE70A80FA, 0xCE6A5E0E, 0xE7171825, 0x58AA77FA, 0x13C1E2B3, 0x4532C7A2, 0xA08065B6, 0xBA22EA35, 0x6C4B02FB, 0x9DD9CAF4, 0x05C6A3B9};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 174 ");
	}
	{
		static const bigint_t var_a = {0xA69794ED, 0xE22F77F8, 0xB1AF462F, 0x4170409F, 0x588AB3CB, 0xBB3D2D64, 0x281BD585, 0xBB165719};
		static const bigint_t var_b = {0xB3960AC5, 0x802DFCDC, 0xA5A8DF6A, 0x8FCA4EB9, 0xC1257192, 0x90F724DB, 0xAAD1900E, 0xA414A299};
		word_t var_expected[16] = {0x1854DC61, 0x1FEAEA79, 0x36BFA84C, 0x4094B68B, 0xBC14AAB7, 0xD44DF039, 0x18EBAF97, 0xAA3C78B5, 0x576B065A, 0x2A26592D, 0x3D5BF8F7, 0x4867D823, 0x5A5766C2, 0xF67B6235, 0x5BF6ECBB, 0x77E9645F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 175 ");
	}
	{
		static const bigint_t var_a = {0x48DD08E6, 0xDAB27131, 0x0FE94857, 0x39BC5865, 0x25BA868B, 0x3176ED0D, 0xFA3DCE64, 0x6B0925EB};
		static const bigint_t var_b = {0x1FC66B21, 0xF494E41A, 0xA1B3EC15, 0x4941A845, 0xF874F13A, 0x9BCDD4E3, 0xD9BB7384, 0xA1DD15F1};
		word_t var_expected[16] = {0x831A47A6, 0xE9990F33, 0x4FC5C07C, 0xD5C34EF8, 0x428A845A, 0x9985BE8F, 0x1798C415, 0x2A37B8D8, 0xBAD627BA, 0x39EFBDF5, 0xD80EDC6B, 0x8B2ED910, 0xDB0F197A, 0x1E1B5A9C, 0x03DA15F6, 0x43AD30EC};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 176 ");
	}
	{
		static const bigint_t var_a = {0xD3FE6FB8, 0xC7485501, 0x5382AED9, 0xA12F60DF, 0x573083D3, 0x7A5AED38, 0x0BB2F92E, 0x6A1E4680};
		static const bigint_t var_b = {0x64802CD3, 0xBF6DC8E8, 0xE12A3998, 0x731D86CC, 0x7EE365F8, 0xB2A4C2AD, 0xDA6E1766, 0x027C33F3};
		word_t var_expected[16] = {0x31E9B4A8, 0xA628C28D, 0x068A4E55, 0xC900122F, 0x0221DB54, 0x81E8F23D, 0xC6175496, 0x5B24A021, 0x88439515, 0x060E7520, 0xDAA5ABB0, 0xB6DE6E63, 0x0C0C4017, 0x716D23AB, 0x4370E941, 0x0107B8C0};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 177 ");
	}
	{
		static const bigint_t var_a = {0xB71723F2, 0x3E28EEB6, 0x48133D34, 0xC797F225, 0x51A36C14, 0xD911D802, 0x93147FF7, 0x36983947};
		static const bigint_t var_b = {0x147E2991, 0x174C6AB3, 0x4D7690A8, 0xF8A8A1BD, 0xD432547D, 0xBA675BE1, 0x07967AE6, 0xE724BF27};
		word_t var_expected[16] = {0x01F91E12, 0x8B8EBB39, 0x55608AD2, 0x43A52DD0, 0xB48EB8B1, 0x876E2DA4, 0xDBA5B91C, 0x966A038B, 0x2430D561, 0x10B4861C, 0x21524EC9, 0xDDFF15D5, 0xD77FFEDA, 0x9C18FE80, 0x89538FF6, 0x314B31DB};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 178 ");
	}
	{
		static const bigint_t var_a = {0xA6012DF8, 0x13570788, 0xF6B76308, 0x37AF1D97, 0xB323557B, 0xD31EB5F5, 0x0CC37B88, 0x8B52784D};
		static const bigint_t var_b = {0xFEBD9284, 0x6F3B5EA5, 0x0ECAFBBC, 0x0783FE48, 0xBB86A937, 0xD784E06B, 0xFA64F1F9, 0xAC8E1881};
		word_t var_expected[16] = {0x44EB23E0, 0x4D8F3C75, 0x3C250347, 0x000291A6, 0x65F364F0, 0x5002BB6C, 0x59116BD5, 0x29654165, 0x749F8BE1, 0x9A947569, 0x9C612825, 0xB2333838, 0x1F783D36, 0x0E25D3AE, 0xF76BBCD7, 0x5DE8BDE8};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 179 ");
	}
	{
		static const bigint_t var_a = {0x9164368C, 0x5CFABC37, 0xA5A0A445, 0xBFEDB697, 0x5F2CE886, 0x2EAFB530, 0x2F6BF328, 0x66920D62};
		static const bigint_t var_b = {0x35954959, 0x7E0E56C7, 0x8EB6CDE2, 0x0B702AA7, 0x3475577E, 0x703D8FD6, 0x8B279813, 0xEDC01DCB};
		word_t var_expected[16] = {0xDAE0E2AC, 0x732A1539, 0x8CBA6E7D, 0xAFAD0846, 0x6E1E2D70, 0xEF369A1E, 0xA1ADAE45, 0x210AAEAB, 0xF738BDBE, 0x435A7F88, 0xC6E822ED, 0x04F432A7, 0xA0D4C722, 0x41F7BDE0, 0x08A067C0, 0x5F422FDE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 180 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 157 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 158 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 159 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 160 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 161 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		word_t var_expected[16] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 162 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 163 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 164 ");
	}
	{
		static const bigint_t var_a = {0xD0557071, 0x17D1A2D0, 0x7279507D, 0xA908FBE4, 0xA0DB502A, 0xC57797D4, 0x524BC56C, 0x699F472C};
		static const bigint_t var_b = {0x864A59B5, 0xAA7A2D86, 0x665DF893, 0x6E8FD9C7, 0xB8AC6E01, 0x8F393EFE, 0xFBDFEBA5, 0x5A93071A};
		word_t var_expected[16] = {0xA729C8E5, 0xC7925FC4, 0xB3A1FFBD, 0x8AC77C9C, 0xCCE16CAB, 0xB0DF1497, 0x9B6F45AA, 0x92001AD1, 0x8E0D30F2, 0x17985113, 0x48535B31, 0x950B96F4, 0xC1ACB124, 0x025B9664, 0xF06CE36C, 0x255EA869};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 165 ");
	}
	{
		static const bigint_t var_a = {0x1440DD05, 0x62A5DCC1, 0x0709FB0C, 0x31E2C9AB, 0x962CF95A, 0xE19D8E67, 0x9EC159B4, 0x75F060FB};
		static const bigint_t var_b = {0xC73A640F, 0x71305F70, 0x2D2DEC3F, 0xFD43BD7E, 0xE5649B93, 0x019C982C, 0xC1C32CC1, 0x69925104};
		word_t var_expected[16] = {0x7C44E74B, 0x40C5EAEA, 0xA75C7D61, 0x09E9DFA6, 0xD0131940, 0xDC161944, 0xBCD6DBBB, 0x32D413D7, 0x561A22D5, 0xF2511825, 0xD07D271E, 0xAA360F73, 0x2FC86495, 0xD0161156, 0xC3531D0F, 0x30A30031};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 166 ");
	}
	{
		static const bigint_t var_a = {0x91EE2DCB, 0xBD729164, 0xB510EE9B, 0x6F733470, 0xB61C2426, 0xAE4FE0AE, 0xAFB7051F, 0x3AFFC668};
		static const bigint_t var_b = {0x898F124F, 0x62FD8873, 0x01CD4453, 0x39095409, 0xFDA0121E, 0x97934AB7, 0xF8E0583F, 0xC0DD81FF};
		word_t var_expected[16] = {0xFF1D67A5, 0x9BCB5509, 0xE549A09F, 0xA24E2E90, 0xE8BE6BEA, 0x7B9216A1, 0x2BF9E411, 0x8A84E9A0, 0x7E61C898, 0x92BEA660, 0x3F34D4AA, 0x5FAC6382, 0x39FAD455, 0x09E02241, 0xAD45D403, 0x2C72E192};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 167 ");
	}
	{
		static const bigint_t var_a = {0x69325DF9, 0x2E2E66FC, 0x769A642A, 0xA126B616, 0x131DC4C6, 0xE26B129E, 0xEF79A8A0, 0x26BC8128};
		static const bigint_t var_b = {0x0FBD612C, 0x2492D540, 0xFE2CCD98, 0xFF7353C0, 0x3283C3B4, 0xA64011C3, 0x2B48DB82, 0x6B26B3A1};
		word_t var_expected[16] = {0x22187FCC, 0x284CA02F, 0xB0530A74, 0x778BF452, 0x86295CCA, 0xBA94AA03, 0x527CB64E, 0x70646F45, 0x60559784, 0x839A55F0, 0x53D96565, 0x77537C52, 0x1E740F39, 0x2E0C3AEE, 0x7994EFA8, 0x1036A525};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 168 ");
	}
	{
		static const bigint_t var_a = {0xFC66B0DF, 0xF9176BE6, 0x84204422, 0x426F1D9D, 0xFC04FEB4, 0x71E8E3DF, 0x064121E3, 0xE40CDAD1};
		static const bigint_t var_b = {0xD8C90867, 0x9A124114, 0x7A75404F, 0x6C0A24E9, 0xF51BDE23, 0xC282B6A4, 0x213E183D, 0xB87AF256};
		word_t var_expected[16] = {0xC9EF21B9, 0xF1BAE41B, 0xCADEC6DA, 0xF904496E, 0xD1EE3EFA, 0xB98A95F9, 0x02BCA799, 0xCA11A160, 0xC88C7C71, 0xF73AB13E, 0x3C3A9D38, 0x121FD747, 0xBC076E59, 0x7575E572, 0x64E3DE71, 0xA456C347};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 169 ");
	}
	{
		static const bigint_t var_a = {0xEC816EF1, 0xA40B85E3, 0x551D99F3, 0x119A6046, 0x04228FAC, 0x9022C19F, 0xDEC122D3, 0x639C8152};
		static const bigint_t var_b = {0xA65E016D, 0xEB65DC44, 0x1097C882, 0xDD138099, 0xF679EB76, 0xC148BFA6, 0xE4CB22CC, 0x33169103};
		word_t var_expected[16] = {0x37092D9D, 0xE7483F73, 0x1EBE6381, 0x5F63BCF3, 0xDB18D343, 0x9FCC6148, 0x48AE2A81, 0x03AE8412, 0x039D7F76, 0xE696DA2F, 0x6785FF21, 0x64C04F43, 0x795973E8, 0xF5168E8E, 0xC89B807F, 0x13E0F5A3};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 170 ");
	}
	{
		static const bigint_t var_a = {0x19237BAE, 0xF4CFCA0F, 0xA59B5709, 0x0B9D46A5, 0xFB47D758, 0xB42EECD8, 0x9FBD0A49, 0xCEAA4EBB};
		static const bigint_t var_b = {0x7AD674F5, 0x7A8684AC, 0x97DA4003, 0xEE686600, 0x27BA09B6, 0xB8E04DD7, 0xBE4EF6B0, 0xAA318A1E};
		word_t var_expected[16] = {0x72743586, 0x65B5F559, 0x16480B1C, 0xFBA6B983, 0xFFA90BB4, 0x01BCF27A, 0x63CC9FA8, 0x7E1E5FC7, 0x1B3255B9, 0x5D4048F8, 0xB7860BC6, 0x7A5AD1FD, 0xCF607B89, 0x192C7833, 0x4A059F96, 0x89651662};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 171 ");
	}
	{
		static const bigint_t var_a = {0xA4A4D528, 0xEC66D6AB, 0x6CC65FAF, 0x6CE7E3E2, 0xF2E08657, 0x92285900, 0xB391BDD6, 0x94DD8BF3};
		static const bigint_t var_b = {0x954E0D71, 0xEDD10DAC, 0x2B713CB0, 0x7D436111, 0xB9174CAA, 0xFB473853, 0x36083447, 0x2AD3FC70};
		word_t var_expected[16] = {0x45C51EA8, 0xECA5D249, 0x7C1AF006, 0x22779B50, 0x15DEE1F9, 0x3964C260, 0x21E5D2E1, 0x6AF172D4, 0x6CCE6A97, 0x75AF82B8, 0x80F597EC, 0xC9B1261A, 0xAE233D4B, 0x55F3A9AF, 0xAB6F8A7F, 0x18E79E5B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 172 ");
	}
	{
		static const bigint_t var_a = {0xEF2AFC27, 0xD45D0A1D, 0xE278C6C2, 0xB131EBDD, 0x3BFDF082, 0x20833E1E, 0xC3C78503, 0x610FDC1F};
		static const bigint_t var_b = {0x78B6AA70, 0x2A59E3D0, 0x2204D113, 0xA70E21CF, 0x1CFC3EBA, 0x207B52C3, 0x17AE6427, 0xFF9DB9E7};
		word_t var_expected[16] = {0xB9FA3710, 0x6AE2F15C, 0x5AC171C0, 0x8D1E0E49, 0x9C279F70, 0x7096B338, 0xCF6A316E, 0x47336AAB, 0x685E341D, 0x59F90892, 0xCBCD31FD, 0x96CDF322, 0xA2543DC5, 0x085BA112, 0xB7DBEF87, 0x60EA9979};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 173 ");
	}
	{
		static const bigint_t var_a = {0x9AB4322B, 0x2E1DCBC9, 0x81CE6145, 0x974DD2FF, 0x656301B5, 0x925859AC, 0xB7A5F77E, 0x2120B2C9};
		static const bigint_t var_b = {0xE3DF7B63, 0x54301A61, 0x17452585, 0xC9366BB2, 0x020F902F, 0xFCC5EC00, 0x69FABDDC, 0xB7A2E423};
		word_t var_expected[16] = {0x3C3F0FA1, 0xDEAA980A, 0x18B58D41, 0xE1D47EA1, 0x74A6C97F, 0x3A954AA9, 0x84D5030B, 0x5B277B73, 0xC98364F4, 0x56DAFF37, 0x116028D3, 0xE1AEA26E, 0xEE95F23B, 0x16F21DDF, 0x0A58CFEB, 0x17C37405};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 174 ");
	}
	{
		static const bigint_t var_a = {0x862AAECB, 0xC138ACB6, 0x01B3992D, 0x1CF6CAE4, 0x43A0D673, 0x5DBAE5CD, 0xB8BDD813, 0x03C55C14};
		static const bigint_t var_b = {0xD98E7B4D, 0xD1BEF852, 0xE27DC34B, 0x80F95CEA, 0x5B46DA76, 0xA4138616, 0x743B6CD7, 0x1E2FABB7};
		word_t var_expected[16] = {0xE46C1C0F, 0xA6AAE439, 0xED05ADBA, 0x68435F24, 0x1AC3ADB7, 0x2F32305C, 0x4916B7CF, 0xBC1D6E7B, 0xCBBD8FFF, 0xA63F70D0, 0x4A969435, 0x392152A8, 0xA6A2DD7C, 0xDC14E74F, 0xDDC12233, 0x0071D48D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 175 ");
	}
	{
		static const bigint_t var_a = {0xD56FA33F, 0x92BF9109, 0x5D727C0B, 0x7C9F8F33, 0xE4160039, 0x36014BB6, 0x307E0B64, 0x7358A68C};
		static const bigint_t var_b = {0x99895157, 0x460FF274, 0x9C20B07C, 0xA9350273, 0x5AF6952A, 0x6C3EB211, 0xC3E35FC4, 0x429E0D3C};
		word_t var_expected[16] = {0xDF4E6969, 0x0469DEBA, 0xFC15467B, 0x37140682, 0x2BA03B4E, 0x3D7F7A10, 0xF93FFFA2, 0xE45E30CC, 0xFB1A1AFA, 0xE0A8EEE8, 0x00A41533, 0xDA9A2AC3, 0xE0A3FBFA, 0x7F969E48, 0xD0858DAB, 0x1E04119D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 176 ");
	}
	{
		static const bigint_t var_a = {0xE8713AFF, 0xE58BC5D7, 0xCC48175C, 0x34470442, 0x9B106044, 0x121D7C53, 0xC7C17EB6, 0x1EAA0860};
		static const bigint_t var_b = {0xA6A89758, 0x981F15CB, 0x9E57448A, 0x603B403F, 0x6DE12CFA, 0xEA5F345B, 0x1D1A9FB3, 0x7028BDAC};
		word_t var_expected[16] = {0xC210B0A8, 0x58AA0617, 0xC3F69BD2, 0xF2F7C094, 0x3E0BC31E, 0xB96DB2CC, 0x5B9DFD2A, 0xFA4DDC67, 0x01B49357, 0xED5340BF, 0x19DA1D1F, 0xC6440F96, 0x59D982F7, 0x7D8D4879, 0xCC6D6584, 0x0D6F44F3};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 177 ");
	}
	{
		static const bigint_t var_a = {0x5E3865CC, 0x3F9300E4, 0xC8F212A4, 0x0244AB63, 0xF8CCB12B, 0x27E50B91, 0x675F2160, 0xF2CE7408};
		static const bigint_t var_b = {0xBFE682BD, 0xEC30F066, 0x8295CCBF, 0x039C14F3, 0x484832BE, 0xF2204D8A, 0x8D491BB6, 0x34B30DB7};
		word_t var_expected[16] = {0xDC9CBF9C, 0x559C2A58, 0x7F33963A, 0x3996E429, 0x61C03182, 0x7115AF18, 0x3280B77F, 0x524CB74F, 0x8005C078, 0x8914EE96, 0x5B19F97E, 0x075F23AA, 0x97FC183D, 0x9A0736B0, 0x6A5A069E, 0x31FBC2EF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 178 ");
	}
	{
		static const bigint_t var_a = {0x1AF59A9E, 0x66366831, 0x0A3D94AA, 0xE215EEFE, 0xCC91B397, 0xE967F5C8, 0x39BAD990, 0x1AF1AEB9};
		static const bigint_t var_b = {0xE670F068, 0xA717E83E, 0x2025EB21, 0x2FFA27EB, 0xDAF9BE4A, 0x9B093DE8, 0x5BB10ADC, 0x5BA1FBE8};
		word_t var_expected[16] = {0xCDDAF030, 0x4D4973DA, 0x82CD1715, 0x7E5F4602, 0x167FD410, 0xFBC962D6, 0xFB331655, 0x0AB180BE, 0xD44F0E2F, 0xD2BC3FFC, 0xC173DD30, 0x3B01BF4D, 0xA49AC3B9, 0x2A2E05AF, 0x24FF38AA, 0x09A4F59E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 179 ");
	}
	{
		static const bigint_t var_a = {0x3D147733, 0x5F917F90, 0x8A94606D, 0x11363AC6, 0x29BBF4DF, 0x0D3B1837, 0xA551818D, 0x04203E1D};
		static const bigint_t var_b = {0x5CB6D673, 0x6E8B03CA, 0x92B9BE6C, 0xC1D9B48E, 0x5563F1D0, 0x38D1FA18, 0x0FF5C5BC, 0xF4A245ED};
		word_t var_expected[16] = {0x9E182DE9, 0x27BA4F7B, 0xAF2F6BAE, 0x26A0A6A6, 0x51B70A20, 0xF4E68660, 0xEF3B35EA, 0x6E8143F5, 0x8BF549EB, 0xAE8117DB, 0x6DE48D7E, 0xC333655A, 0x87A9897C, 0x77B28226, 0x132DA5BE, 0x03F158BC};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 180 ");
	}
	{
		static const bigint_t var_a = {0x274C3C45, 0x6DCB0C8B, 0x839646A7, 0x0DE7F1B1, 0x5ECB4776, 0x88CB6884, 0x5451E49F, 0x5D20F029};
		static const bigint_t var_b = {0xA2781AEB, 0x26772A65, 0x2FFECC28, 0xD66FC228, 0x29A091E0, 0x5EAE1D9E, 0x74AC29F1, 0x49859A41};
		word_t var_expected[16] = {0xBB725557, 0x9DCD68D3, 0x992B9579, 0xE474BC54, 0x55A8822B, 0x4F941FA9, 0x80C57B41, 0x2CD5D778, 0xABB94C2A, 0xA87BC20E, 0x8766A5F9, 0x29515180, 0x35EF3687, 0x1C1AFEA7, 0x2ECB8E2B, 0x1ABEFEB6};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 181 ");
	}
	{
		static const bigint_t var_a = {0x79AD3BA8, 0x1867F253, 0x6CA0CA01, 0x92043198, 0xFE7AD852, 0x90ADD4BE, 0x3021C545, 0x133CF123};
		static const bigint_t var_b = {0x79DBC7EC, 0xF448D9C6, 0x9226B10F, 0xCA72B3C5, 0x088AD95A, 0xE4A6FB28, 0x91F37B29, 0xEA02DB13};
		word_t var_expected[16] = {0x45CA96E0, 0xE9EBCCDE, 0xBB514091, 0x469262C2, 0x4E8F778B, 0xF428F0D0, 0x36894E5C, 0x6CF589FB, 0xF51C8052, 0x7965D7E2, 0xCA68C605, 0x07F39DC6, 0xBD7311BB, 0xD7855775, 0xA70C0F0D, 0x1195EB5A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 182 ");
	}
	{
		static const bigint_t var_a = {0x14B31FD0, 0x2292FC9F, 0xFF5F174B, 0x9DD3657F, 0xD8C8E5D1, 0x98ECDA52, 0x62F5E367, 0x51127812};
		static const bigint_t var_b = {0xE274AFC5, 0x3D424806, 0x937E8E39, 0x3CEA28D2, 0xE3C860E7, 0xDDDFFBF0, 0xB1FAD5C7, 0xA2936F33};
		word_t var_expected[16] = {0x6AD6AB10, 0x9EEDE7B1, 0xA702DAB2, 0x4CF70340, 0x0BA92265, 0x952ACB3D, 0x4360ABD5, 0x24D22B93, 0x2B8A7AE2, 0x303B654C, 0x5F2ABC35, 0xFE4FD7EC, 0x087B00AB, 0x19C014A0, 0xF649866D, 0x337C60CD};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 183 ");
	}
	{
		static const bigint_t var_a = {0x1A521B7E, 0x9375A28C, 0x34633249, 0x6CD2BD08, 0xFF0920B4, 0x575BD8DB, 0x525E0AA2, 0x86670538};
		static const bigint_t var_b = {0x1D5D67F0, 0xA6C706FB, 0x4BFA46CC, 0x07FF3878, 0xEAE22CBC, 0x9FED1C83, 0x5C961128, 0x7E3CB243};
		word_t var_expected[16] = {0xF8CF7820, 0x4CA7876A, 0x5AC75C7F, 0x7C83C515, 0x01120BD8, 0x2D3E7F0F, 0x719CE49C, 0x8C256D5C, 0xCD95BA84, 0x2282BC82, 0xD33E6DDE, 0x0FE290BE, 0xDBBB07C3, 0xCF0F6D45, 0xF0F0ED88, 0x4246924D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 184 ");
	}
	{
		static const bigint_t var_a = {0xEC09FD98, 0xAD85BBF9, 0x46A87403, 0x7B88668F, 0xC3F9AA32, 0xC1E307E0, 0xAAD81AE5, 0x5EF5375A};
		static const bigint_t var_b = {0xAD3EB016, 0x14B10AFA, 0x14C67525, 0x49CBF9F7, 0x8F4CE5C9, 0xBE23AFBF, 0x5BCF3AFE, 0xCC5F6C9C};
		word_t var_expected[16] = {0x4A044B10, 0x61857AFC, 0x557A5501, 0x24A061CD, 0x63E8DB14, 0xC74BE9B4, 0x951ECD55, 0x80C1AAFB, 0x86041AB4, 0xDE84253E, 0x10D32EC6, 0xB4453901, 0x659A0C14, 0x6236D819, 0x3D9F9FCB, 0x4BCECD65};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 185 ");
	}
	{
		static const bigint_t var_a = {0x2AF42570, 0xF7D128FB, 0xAC2D479B, 0x8756A2D9, 0xB5C9C357, 0x0BD736CD, 0x525D24FC, 0xC63A34E6};
		static const bigint_t var_b = {0x51663E76, 0xAB993335, 0x86D62DB8, 0x5F2A6078, 0x82782B9D, 0x11E542FB, 0xB6728574, 0x198D6885};
		word_t var_expected[16] = {0x483A61A0, 0x66F1257C, 0x28B99231, 0xC6CF4909, 0xB4CB25DD, 0x4AE346D1, 0xF66F2613, 0xE17DDC21, 0x08DBF155, 0xA34140CF, 0x70945531, 0x5B9CB932, 0x997091D7, 0x083B1004, 0xCFE791E6, 0x13C92E28};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 186 ");
	}
	{
		static const bigint_t var_a = {0xB5D464EA, 0x36557247, 0x2082230D, 0x8E46B178, 0xA6310B0D, 0xAB3D2DCB, 0x73F179BD, 0xEA4BA03E};
		static const bigint_t var_b = {0x0BD3E649, 0xD22F4242, 0x7A787C17, 0xE688720D, 0xB5E71686, 0xABF3CA77, 0xB8A1C6F1, 0x315118BA};
		word_t var_expected[16] = {0xE71902BA, 0xA6B15A88, 0x864A4B15, 0x65EE3620, 0xBD57E832, 0x4CBB0621, 0x74D4A965, 0x5FC2A0C9, 0x36BEB104, 0x842E5F85, 0x3F56AB32, 0x892251AA, 0x7BA464C5, 0x0AC465F1, 0xA2E69AC4, 0x2D22B23B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 187 ");
	}
	{
		static const bigint_t var_a = {0xAE29B561, 0x6E4558C8, 0x9A54D872, 0xCCDB8D34, 0xA87F7390, 0x5427CA38, 0x7836CEF0, 0x39A233C0};
		static const bigint_t var_b = {0x1C463018, 0x2D85438E, 0x0AE1AFE6, 0xBAB4CFF0, 0x5939D5D6, 0xE1C0F2AA, 0xE96172B1, 0x22064E62};
		word_t var_expected[16] = {0x5A713118, 0x5F122184, 0xFC2E55AC, 0x790332BE, 0x47B51BED, 0xDBE86022, 0xAF90A261, 0x387898DC, 0xBE0A0399, 0x53204FF2, 0x8EAC32D0, 0x2D8DAFAD, 0xEEFCCED2, 0x8D339FEB, 0x76E11E75, 0x07A8F652};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 188 ");
	}
	{
		static const bigint_t var_a = {0x773BE22C, 0xE46358B2, 0x550412A0, 0xBEE27D20, 0x0AA8D240, 0xFDFAD3E8, 0x07FA5233, 0x5FECDA49};
		static const bigint_t var_b = {0x06534808, 0xA05E70C2, 0x8DBD61A8, 0xFAAC8929, 0xDF3A6E4A, 0x4ABDA806, 0x122D1D96, 0x39A30AED};
		word_t var_expected[16] = {0xEDBF7160, 0x1F31AC2B, 0x6981CF2E, 0xF839BB90, 0x7CC0D071, 0xFCDA3459, 0xA6906A03, 0x86BD2937, 0x4C27CC17, 0x30413617, 0x7A6079B4, 0xAA0AB0FB, 0xEE42766B, 0xBB856757, 0x54E34FAD, 0x1598D481};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 189 ");
	}
	{
		static const bigint_t var_a = {0xB12C0E18, 0x1E4D27C8, 0xC8302732, 0x22417735, 0x5F5518F3, 0xDAC67C73, 0x0BC6DC62, 0x49DE6F55};
		static const bigint_t var_b = {0x876F5C9E, 0x5284805F, 0x9EC345A5, 0x01725420, 0xF7F7ABE4, 0xB9A8DC38, 0x3B8181DF, 0x028D5F7A};
		word_t var_expected[16] = {0xF2A952D0, 0x3E22F5F9, 0x84BF2804, 0xD0A38E52, 0xF7C5E01E, 0xC7734377, 0x5A0F10ED, 0xBA7B883D, 0x9B6B32E8, 0xA085B833, 0x5A8ED037, 0xEDE3EA72, 0xC7C90799, 0xE8B6D494, 0xCC6C4A5E, 0x00BC87EE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 190 ");
	}
	{
		static const bigint_t var_a = {0x3C0A1D4D, 0xE1C81DAF, 0xAD49296C, 0xF4C5588F, 0x77F82741, 0x61909A31, 0xAD700A59, 0x250105EE};
		static const bigint_t var_b = {0xA3035780, 0xA6117214, 0x1541BC63, 0x6DD508DD, 0x93CA26DC, 0x43E27117, 0xAF7009AD, 0x4A6564C1};
		word_t var_expected[16] = {0xD3EAD180, 0xE4611DCF, 0x13188E4A, 0xF0E824DA, 0xEC881C59, 0xB4D04A4E, 0x8F74F372, 0x8E8BF1C7, 0xAAA3CB7C, 0x19E241E9, 0x897A25A8, 0x8A9F57D2, 0x827E6F5C, 0x46ABE067, 0xBABF69C9, 0x0AC0F3AE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 191 ");
	}
	{
		static const bigint_t var_a = {0x39DB036D, 0x301A9A79, 0xFD1E3978, 0x71F9F6A9, 0x63D85683, 0x45A493B6, 0x55AC70FF, 0x5E83C510};
		static const bigint_t var_b = {0x9A790024, 0x42C5C495, 0x0CAC2869, 0x1B4A7BEA, 0xE36A755F, 0x3FB865AD, 0xF631DC75, 0x1FDB409F};
		word_t var_expected[16] = {0x53517B54, 0xCBD14411, 0xE98CF761, 0x80CCCA8B, 0xF98EF779, 0x78F7A7B2, 0xD59C8C59, 0x0EAEEC02, 0x2F615445, 0x9FC9F71A, 0x7FB43A3B, 0x35C19E9B, 0xF88C39F9, 0xD7B7380F, 0x8F59AEBE, 0x0BC2E772};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 192 ");
	}
	{
		static const bigint_t var_a = {0x09B1FBDA, 0x534F55CC, 0xF0701FE7, 0x17EDFC3A, 0x74228E65, 0x7DE6FEDD, 0xAD97C905, 0xA2086945};
		static const bigint_t var_b = {0xED4D8487, 0x0C5129FA, 0xDB320C3E, 0x27B4A61D, 0x59FF8046, 0x40B8291E, 0xD9AF6FDF, 0xCE7A4ABC};
		word_t var_expected[16] = {0x754A37F6, 0x6B8C012E, 0x8200B1F6, 0x76B73177, 0xBC555C1F, 0x2C7CEF69, 0x7209C2DF, 0x09263C29, 0xF40768F9, 0x662387BA, 0xF7381336, 0x75C105B2, 0xA2718C0E, 0x8E38001B, 0x33487D3C, 0x82B02C06};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 193 ");
	}
	{
		static const bigint_t var_a = {0x4EB7987A, 0xCC91AC43, 0x00802987, 0xA20BA185, 0x3BFA1049, 0x3D22F8C1, 0x9D4D28C3, 0xDF793B7B};
		static const bigint_t var_b = {0x5C1F5A55, 0x27AAA4E1, 0x1B4CE4ED, 0xF0382BBD, 0xA62CFD00, 0x1CFF3154, 0x61199E9B, 0xE37D36F4};
		word_t var_expected[16] = {0xFD568482, 0xD36D8A46, 0x582E3C3B, 0x1BEF433E, 0xF53100E0, 0x2ADE7279, 0x92FFAC75, 0xB0A63E77, 0x4652A1B4, 0xD7ABCF4E, 0xB90A9A93, 0x9EBB5E4B, 0x2502773C, 0x1AC8D4DF, 0x8EB34BA7, 0xC695CDE9};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 194 ");
	}
	{
		static const bigint_t var_a = {0xE843C561, 0x6376DEFD, 0xE69C49EB, 0x0FE92D45, 0x8989E6E3, 0xFA59282F, 0x4F75300B, 0x40D5B877};
		static const bigint_t var_b = {0xE9BE9214, 0xF95827EC, 0xA546CD7B, 0x110F21C6, 0xBA250453, 0xE788B7AF, 0xD7713F37, 0x2C9B5F6E};
		word_t var_expected[16] = {0x92DABD94, 0xCD3207AA, 0x077D8DA2, 0x342970EC, 0x9676E319, 0x3673A654, 0x4F04B377, 0x62494E1B, 0x2375C5E9, 0xE6278626, 0xD59912D6, 0xA0E03824, 0x465F89E9, 0x28CFF3B7, 0x93BEF63C, 0x0B4C1546};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 195 ");
	}
	{
		static const bigint_t var_a = {0xF9E6A03F, 0x1A4D3C6F, 0x9BB87B3B, 0x9C125F8B, 0x7010E8CE, 0x6917826B, 0x2BD25100, 0x34FEBC63};
		static const bigint_t var_b = {0xD63F8946, 0x28C99844, 0x92D9E804, 0x684E3F4B, 0xC7BBD6B0, 0xF880AE2A, 0xC4204702, 0xB6D61F93};
		word_t var_expected[16] = {0xDA52883A, 0xFACAB5CC, 0x8184BEFC, 0x7FFC26E2, 0xEB691DBC, 0x20B1251C, 0x1CD9D668, 0xC1222066, 0x9FFB2D99, 0x7623C6C2, 0xC70A7AE3, 0xFF707D5A, 0xF89E5A7E, 0x6043047D, 0x6BBE0D6D, 0x25D96D69};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 196 ");
	}
	{
		static const bigint_t var_a = {0xE17A4379, 0x38714FE5, 0x58F46D27, 0xC4DE912F, 0x40F572F3, 0x80BBB164, 0xDBD3072C, 0x668D4744};
		static const bigint_t var_b = {0xA207F892, 0x97995645, 0x3CB48889, 0x12C0562B, 0x3E6EC04A, 0xE291F0A6, 0xF081657A, 0xCD513E4B};
		word_t var_expected[16] = {0x7366B302, 0x28EEA230, 0x5E0D8509, 0xCBF8003A, 0xF5CB68F6, 0x9CF1E323, 0xD2D2EAD9, 0x5B82DD3C, 0x2443F955, 0x279436B7, 0xDA38A7A1, 0x7E6CF1C4, 0x22B3524A, 0xD9B8D69A, 0x53D06195, 0x523FADBA};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 197 ");
	}
	{
		static const bigint_t var_a = {0x4234643D, 0x4299F25D, 0x95316D14, 0x473DCAAB, 0x89D4BE09, 0x72CE419B, 0x47261D66, 0xC5A0D36B};
		static const bigint_t var_b = {0x0FDE7163, 0x6CEC277B, 0x3B0E1D96, 0x6CAE209C, 0xCF7A1F1A, 0x7A359B5B, 0x66752DE1, 0xFE1A7136};
		word_t var_expected[16] = {0x3A67B097, 0x47F1D3E7, 0xC8EA5628, 0xEAF734CA, 0x21C93D22, 0xBAE9D36A, 0xB52EE05D, 0xA5DEF1F1, 0x05172811, 0x2108D490, 0xF8EC74E7, 0x40F67DAA, 0xE1B66428, 0x2B91223D, 0xE5D4883C, 0xC429FB7F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 198 ");
	}
	{
		static const bigint_t var_a = {0xFCB1E40F, 0xFC265F97, 0x0CA295DF, 0x1F878B84, 0x1E91D798, 0xB64F735F, 0x9941F353, 0x7DAB4331};
		static const bigint_t var_b = {0x1EFD3E8F, 0x0CB7A48B, 0x6937E744, 0x13B56146, 0x6CED9080, 0xD704A296, 0x6EEFBDE6, 0x18FEF2C5};
		word_t var_expected[16] = {0x616D0661, 0x52D139C6, 0x8ADB048E, 0xC91F3360, 0x86B035F0, 0x10432DE1, 0x72931927, 0xD4BB8299, 0x29F79545, 0x7E4F1582, 0xB98690A0, 0x9323DC5A, 0x3BA8DFD4, 0x5B1B3B29, 0x22591D46, 0x0C453566};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 199 ");
	}
	{
		static const bigint_t var_a = {0x300D408E, 0x6B772E7E, 0xB65747CD, 0x8B4E8598, 0x0F643B29, 0x0006CA34, 0x39FACD88, 0xFB456179};
		static const bigint_t var_b = {0x10219EF8, 0x1C1211C4, 0xDD277051, 0xE39060F0, 0x45B0404A, 0x4C089547, 0x9188EF91, 0x25542D68};
		word_t var_expected[16] = {0xECFC2D90, 0x48D6CC5C, 0x4A98FF52, 0x81A849EA, 0x75CB4F15, 0x8EE688A5, 0x33B6310F, 0xFBC7723F, 0x03274EF8, 0xF85BE55F, 0x773FAB55, 0xF113D3FF, 0xA830A1C8, 0x91D0A8C7, 0x5652E2A6, 0x24A3A66C};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 200 ");
	}
	{
		static const bigint_t var_a = {0x40E9DD6D, 0xD5324F5E, 0xCCD4DE7E, 0x072F14F5, 0xAEEC1C9B, 0x46CF4C71, 0xD1102390, 0xEBFDF0DF};
		static const bigint_t var_b = {0x6698693C, 0x8189AC55, 0xF20FC336, 0xFAEFB0F3, 0xCC9B5D24, 0x6F079B08, 0x980D06CF, 0x75D37532};
		word_t var_expected[16] = {0x09599A8C, 0x62ECBCFD, 0x5CF6CC4C, 0xFF993BBF, 0x16D5C1F9, 0x22F52271, 0xFD1F6820, 0x644D62E1, 0x78B94B4A, 0x23EA4A41, 0xCC4D8766, 0x5FA1491A, 0xED7C2011, 0xC1835273, 0x85DFD002, 0x6C9DFD6D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 201 ");
	}
	{
		static const bigint_t var_a = {0xCC8349F5, 0xBE9CEE7B, 0xC69BB107, 0x519D960C, 0x8A4049D1, 0xBBF0796D, 0x4AC2ED6A, 0x3D265A8D};
		static const bigint_t var_b = {0xE05320D5, 0x606C7584, 0x40E86B91, 0xB54152FB, 0xB286B1D8, 0x14D99F9A, 0x8C0FE64D, 0x935FE0B5};
		word_t var_expected[16] = {0xECEA28D9, 0x6353312C, 0xE91ABB04, 0xCA3D1FDD, 0xEBFBD34D, 0xE3BA82EE, 0x1A26A85C, 0x71E02681, 0x077CF9DC, 0xEA042CCF, 0x2ECC8912, 0xBD1E0234, 0xB8D76AD7, 0x421F3882, 0xA92B19C2, 0x2333ECE7};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 202 ");
	}
	{
		static const bigint_t var_a = {0xB5C44C71, 0xECE355F9, 0x5EBF4E7A, 0x65B7956B, 0x76FBB121, 0xD666EFD9, 0xCB570649, 0x1BA7E205};
		static const bigint_t var_b = {0x81F65252, 0x1E1D604D, 0xA1013A3E, 0xB18622C7, 0xE8555DDF, 0x51B3B609, 0xB673CE98, 0x4CD924EC};
		word_t var_expected[16] = {0x7EF2AE32, 0x546A7958, 0x596AE9DD, 0x5EF5DE18, 0x0C994D5D, 0x434D1264, 0x8F8597BE, 0x275D1DC1, 0x2EA54550, 0x7F4BD7BB, 0xC4F9A3AA, 0xDA92A33A, 0x5FB00F96, 0x24E616E0, 0x7D8A3DFE, 0x084D4C65};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 203 ");
	}
	{
		static const bigint_t var_a = {0x1D4EEF66, 0x6372BB2E, 0x8D720387, 0x8014C249, 0x814F9B3C, 0x4B35C70F, 0xC0B67D87, 0xF3CD7E7F};
		static const bigint_t var_b = {0x88E57485, 0x60610249, 0x2C95C6EE, 0xCB20A5F1, 0x9E0CB917, 0x7B7BB0EE, 0x9F03968C, 0xAEEE9869};
		word_t var_expected[16] = {0x54BA97FE, 0x86455B1D, 0xDE53FD5C, 0x7D908EDE, 0x885CFFC2, 0xAC74D0FA, 0xE017C6F6, 0xD05572E9, 0x199C68E8, 0xDC319C9B, 0x0BAD2541, 0x3B05C496, 0xE2B60937, 0x14927557, 0x0995FC27, 0xA698E62D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 204 ");
	}
	{
		static const bigint_t var_a = {0x648C5983, 0x693D08D9, 0x8C98A304, 0x2095C493, 0xFE146E7B, 0x0FB7A770, 0xD0F0FC3C, 0x721D358B};
		static const bigint_t var_b = {0x775811C5, 0x0BB2B2CF, 0x3C54BF2C, 0x20A31DF5, 0x46DC57B9, 0x2716E682, 0x10FD6C9B, 0x06EB3D41};
		word_t var_expected[16] = {0x5BFA94CF, 0xE3D583BF, 0x8397AA1E, 0x82992378, 0xB5BEE303, 0x66685E8B, 0x8D142E2B, 0xEF414421, 0x31201B9D, 0x8F288D10, 0x1142E2E4, 0x5B60A57D, 0x873DE83E, 0x90BAB4A7, 0x64FE270A, 0x03158B5F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 205 ");
	}
	{
		static const bigint_t var_a = {0x2CC69B8A, 0x821591C4, 0xD354967C, 0x0133E34A, 0x7DDA2DC8, 0x57EE872B, 0xE4D328DD, 0x851D161F};
		static const bigint_t var_b = {0x106964A7, 0x438B1BA4, 0x6AF8F404, 0x0CA2FEEC, 0x903430CE, 0x29B7367B, 0x12A22283, 0xE086E247};
		word_t var_expected[16] = {0x35EB5F06, 0x88D6B20D, 0x52A0D517, 0xD0D77592, 0x5A77C971, 0x5DD7065E, 0x3D6453A7, 0xFEBEA93E, 0x839E7095, 0x868605CA, 0xF82ACE9D, 0xEDC0C353, 0xA42CA3A1, 0x40399C04, 0x1F342F0C, 0x74BF963E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 206 ");
	}
	{
		static const bigint_t var_a = {0x552C59C6, 0x74F6C3D8, 0x1C9B2613, 0x20D17957, 0xCFF4928E, 0x99D427FB, 0x267A09BC, 0x5A2BC84D};
		static const bigint_t var_b = {0x522358D5, 0x6FBC42A9, 0x8DD32DD3, 0x2D83ACD0, 0x6ED3E7C6, 0x97313ADF, 0xEEC8EE5F, 0x0AB858A3};
		word_t var_expected[16] = {0xCED4C1BE, 0xA75379CD, 0x13070A53, 0x2F049A02, 0x330B4AD6, 0x9A3182AA, 0x948622E3, 0x506E0E3F, 0x0C45C4CF, 0x8B3018FA, 0xD32B8EB4, 0xDD9B4927, 0x98A82C10, 0x66619F12, 0xC5CAF4D4, 0x03C6A483};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 207 ");
	}
	{
		static const bigint_t var_a = {0x00EA56B5, 0x4357C9A9, 0x60BF1765, 0xBA0B472B, 0x058FC867, 0x88AA3CB3, 0xFED9757A, 0x5C49A738};
		static const bigint_t var_b = {0x7F95E5D6, 0x33B80469, 0xC05FBCE7, 0x604D9424, 0x11D543FA, 0xC647A751, 0x2D6CBF44, 0x9081BFD2};
		word_t var_expected[16] = {0xA5CD644E, 0x7428EEBD, 0x1D1FBE63, 0x97827B1B, 0x8C423C04, 0x0A95889A, 0x3D3456E1, 0xB1562F7D, 0x7A46CDFD, 0x04A92A6F, 0x96730BC2, 0xDD4727A4, 0x2E23FB88, 0xBC4DE529, 0x0BA196F9, 0x34183454};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 208 ");
	}
	{
		static const bigint_t var_a = {0x8F34EFFC, 0x357A19F5, 0xD8057E33, 0x4D088DD0, 0x70BACE71, 0x1B4851B1, 0x165683A4, 0x3AEF7809};
		static const bigint_t var_b = {0x17E0D9F9, 0x73E40370, 0x5BCFD9FF, 0xC278965E, 0xE9C3BC20, 0x4AFBED7E, 0x983A0AC2, 0xC0C3E09C};
		word_t var_expected[16] = {0xCA6A081C, 0x80E8685D, 0x339B2263, 0x1D762A76, 0x308AD7C3, 0x2E8A8012, 0x46DE4D5F, 0x52D3F8EF, 0x4D14C272, 0xB47400BF, 0xC62136DF, 0x71075EBA, 0x0383B935, 0x571DCCEB, 0xD5AD8BB7, 0x2C60B224};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 209 ");
	}
	{
		static const bigint_t var_a = {0xA25B68DD, 0xCDBC05AE, 0xFD32DBF6, 0x95450643, 0xA27E8083, 0x866C5A86, 0x574DF90A, 0xE0D9B300};
		static const bigint_t var_b = {0xDD45FFB3, 0x56EA0BC4, 0xF79CC4C9, 0xB0BEC57A, 0xA8A8361D, 0xF9DC05A7, 0x39272204, 0x270CA391};
		word_t var_expected[16] = {0x9FEF7587, 0xC1DB6132, 0x18E3EA10, 0x72D5D38A, 0x1E115F82, 0x5663DF3F, 0x0910D4F8, 0x4EC7C785, 0xA85A4322, 0xA5DE2869, 0x371DE1D4, 0x567DEB23, 0x8EC308F1, 0x00D41182, 0x9BCB6B47, 0x224C4423};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 210 ");
	}
	{
		static const bigint_t var_a = {0x1BD92FAA, 0xD3E7357F, 0x871B7FB2, 0x906BAE2F, 0x6BE93DAE, 0x3F0EFF6D, 0xE9AAC8A0, 0x7ADB5BE5};
		static const bigint_t var_b = {0xD13BAA21, 0x3F06E9F9, 0x6E1BA3ED, 0xC7E9797D, 0x3E1ADDA3, 0xE85C7077, 0x57F91072, 0x91658F0B};
		word_t var_expected[16] = {0x96D408EA, 0xAAF91F32, 0x535000E9, 0xF1E7C7A0, 0x2AB1F1BD, 0x18647265, 0x8AC7FE64, 0x7486C190, 0x82D8ADD0, 0x8EF8DCCF, 0x6B66BA6D, 0x6CAD35FF, 0xBEDDA3D4, 0xBB524612, 0x75095FE7, 0x45C6FC3E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 211 ");
	}
	{
		static const bigint_t var_a = {0x1A61F906, 0x4A7F19E6, 0x70342CA1, 0x7A1B5F78, 0xDB1E3ABE, 0xF9AA9468, 0x357687E5, 0x77AB7163};
		static const bigint_t var_b = {0x3379AA81, 0xD557B3AF, 0xD7052A54, 0xE3A5B6DF, 0xDE4D2390, 0x6C1A6FAA, 0x7CDCF4F5, 0x0C286BDE};
		word_t var_expected[16] = {0x40927806, 0x2F65447D, 0x1944E72F, 0xE2FF1AF4, 0x7F4D8196, 0x1DFBDEE1, 0xD25EA6A3, 0xED501E3E, 0xDFD6F845, 0xE9BCD3F2, 0x60F143B6, 0xA314D1A6, 0xCFB4187A, 0x8C10186E, 0x07710908, 0x05AEEE87};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 212 ");
	}
	{
		static const bigint_t var_a = {0x00F2C1EA, 0x77124D4D, 0xF1220094, 0xD0BF4018, 0x45696DAA, 0xAB97CF0C, 0xE562F025, 0x83B6F625};
		static const bigint_t var_b = {0x8607A0CF, 0xFB318E70, 0x8D0F07A4, 0x2250E622, 0xF626E8FA, 0x19346E20, 0x71F0E157, 0xE4C8E51F};
		word_t var_expected[16] = {0x46E30C36, 0xC1455C5F, 0xFD537324, 0xCA6C86DD, 0xFBD68755, 0xF6678CCF, 0x13ABCCCE, 0xA15480FC, 0xCA2259A3, 0x9FD2289F, 0xAC84E258, 0xE45BE873, 0x3721EA5A, 0x8E52902B, 0xE5DEBA13, 0x75B6500C};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 213 ");
	}
	{
		static const bigint_t var_a = {0x6FE4B6A9, 0xE08BF3CA, 0x824CA01C, 0x505C0F46, 0x39492B25, 0x89502766, 0xE260661B, 0x8BEE84B9};
		static const bigint_t var_b = {0x8952B4DD, 0xD86ADB46, 0x29740F2F, 0xE1C6E808, 0x3A47BE61, 0xC597A268, 0x3FD94754, 0xA7AA5AB7};
		word_t var_expected[16] = {0x5C0283E5, 0x27BB8EA8, 0xC178EF08, 0x76E4DE3E, 0x3EA81E11, 0x55EBC916, 0x8377DE59, 0xBF76CF6B, 0xA3423DF1, 0x70B24486, 0xBB70B769, 0x58790A0C, 0xC513A632, 0x39064B1A, 0x6B2DE7EC, 0x5BA5B68F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 214 ");
	}
	{
		static const bigint_t var_a = {0x47FB0087, 0x49810368, 0xDE66AADB, 0xF55D33F1, 0x88855CBE, 0x08C9EE74, 0x542C7CB3, 0xBC9A7A84};
		static const bigint_t var_b = {0x3E38B78E, 0xCFABE281, 0x828732C8, 0xBD39762D, 0x991E5870, 0x8452DCED, 0x2F4FDB56, 0x21EDA6A1};
		word_t var_expected[16] = {0x2A22CBE2, 0x5E5D6A5C, 0xDC1F72E0, 0x52821931, 0xB3A7B286, 0x50519001, 0x732D3748, 0x1983D1D0, 0x7BBCEB8B, 0xAA447087, 0x398D5C24, 0x836DE4B7, 0x357BABDD, 0x4D32E37B, 0x66CFB6D2, 0x18FEFF91};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 215 ");
	}
	{
		static const bigint_t var_a = {0xA973738F, 0xB8838815, 0xFC07698C, 0xFF6AAEF6, 0x443B5D48, 0xDEBB2025, 0xA5DD7F08, 0x8327BA61};
		static const bigint_t var_b = {0xE618A011, 0x86C1EC73, 0xB345303B, 0x93F9D5FD, 0x45FB173D, 0xADE08C3C, 0xCBAE0303, 0x603D1316};
		word_t var_expected[16] = {0xB84C0C7F, 0x3442ED3A, 0x9AD028B0, 0x45D16028, 0xBE0A348F, 0x3DB8D1A7, 0x2A85F024, 0x485B1D8D, 0xC88A3D19, 0x549736CF, 0x90F0274E, 0x6856DB0A, 0x4249A921, 0xC0BA69DE, 0xA8108075, 0x314E3023};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 216 ");
	}
	{
		static const bigint_t var_a = {0xF7141FBE, 0x716FD8B4, 0x1636CCA6, 0xE832DCAA, 0xBCED7E70, 0xFEFADFD0, 0x7D790AD4, 0x8DF6FDAA};
		static const bigint_t var_b = {0x02E7723F, 0xE2EBD22D, 0x14E3135F, 0x7F48E94B, 0xAE19C409, 0xD37D0117, 0xDA88CCF2, 0xB1A551F9};
		word_t var_expected[16] = {0xE4886BC2, 0x7E3D765D, 0x62AAB696, 0x7974A392, 0x5B29462C, 0x66B62911, 0xB665D297, 0x417D1C4F, 0x780F3C9E, 0xE54CF280, 0x6CFAA91D, 0xAF191361, 0xA4BA6ECA, 0x03100241, 0x14536CEA, 0x6283730A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 217 ");
	}
	{
		static const bigint_t var_a = {0xD240C9AB, 0xFABBBCD7, 0xA4F7A5B0, 0x6F3E0795, 0x83962EBC, 0x9FBFABA3, 0xC58093E4, 0xC82EC0BF};
		static const bigint_t var_b = {0x5337897C, 0x092E027D, 0x3F5C72FC, 0xE0298AF9, 0x86B45ED9, 0xCB74D14C, 0x66325B55, 0xA05D8F4B};
		word_t var_expected[16] = {0x480B31D4, 0xE177F3DB, 0x344A528C, 0x73E344C1, 0xEC5A0D20, 0xD356EF80, 0x84376D92, 0x8E96C232, 0x8A4C3FAF, 0x68C62A88, 0x3510610C, 0x65331499, 0x1852FC57, 0x107641BB, 0xF462B500, 0x7D666180};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 218 ");
	}
	{
		static const bigint_t var_a = {0x1903474A, 0x17CC8F1D, 0x61E32A97, 0x90BFD179, 0x69B5BE5B, 0x35FA4773, 0xA780085F, 0x5F8CB655};
		static const bigint_t var_b = {0xDA503FBE, 0x5E9EF2B0, 0x0B066D00, 0x51323E79, 0xBE14226C, 0xAC6F808A, 0xB854E855, 0xFB999A7E};
		word_t var_expected[16] = {0xAA1A1EEC, 0xF8BFF35B, 0x85B778A3, 0xEC980560, 0xFBA32D08, 0xCB97528E, 0x2B230E94, 0x0996597A, 0x1221C2E5, 0x69CDE2E6, 0xA2B9D072, 0xE1F559AB, 0x8F9158E4, 0xB4B25ABA, 0xE629BC96, 0x5DE84B88};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 219 ");
	}
	{
		static const bigint_t var_a = {0xEF21BC6C, 0xCD3D4E52, 0x44B0B6A9, 0x88617211, 0x7F60D583, 0x75A259E3, 0x8CA268D5, 0xC030E21F};
		static const bigint_t var_b = {0xD83C0596, 0x87B612ED, 0x931D78B5, 0xB0573D21, 0x86A1A072, 0xC9C75496, 0x5A7D3D74, 0xCE5C1CE1};
		word_t var_expected[16] = {0x0FC28348, 0x73EB0E23, 0xC3D12941, 0x0870662F, 0xC30E9E8B, 0x8EC66FBA, 0x9575E392, 0xEB7CD923, 0xC9EA9615, 0x06D6C4B3, 0x94B4B38E, 0x241D007D, 0xC3CB13DF, 0xA3F12D29, 0x2E22A156, 0x9AEC7D35};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 220 ");
	}
	{
		static const bigint_t var_a = {0xB52DBE1D, 0x623A9CB4, 0x87C5D40E, 0xD518C506, 0x16547E3E, 0x5407B7E8, 0x1C3C647B, 0x99723399};
		static const bigint_t var_b = {0xCDD6D362, 0x69A3260C, 0x3058E5FA, 0x1AC1CC8D, 0x50F00809, 0xB8D561AF, 0x13AEB637, 0x6745E68B};
		word_t var_expected[16] = {0x3472AE1A, 0xD7923B58, 0xA746F8BC, 0x3150BD52, 0x5F98BABC, 0xB3DBA42A, 0x48C1097B, 0xFD36901B, 0x3E145C19, 0x76A118ED, 0xEDD498CB, 0xC92DF208, 0x4B40169D, 0x5149B5AA, 0x79CAAEE1, 0x3DE6D8BA};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 221 ");
	}
	{
		static const bigint_t var_a = {0x0B915B04, 0x5AC6BE07, 0xA3CA8CCC, 0x33F32F1C, 0xBF02E1E4, 0x081F6C01, 0x415F0002, 0xD5ADC1FF};
		static const bigint_t var_b = {0x7CDC050A, 0x29951B5A, 0x797332B4, 0xEC96ED8F, 0xCDD48DCB, 0x4D41C603, 0xEDECC7E5, 0x5360547E};
		word_t var_expected[16] = {0x71E4A228, 0x282953E8, 0x3DE41B48, 0x25316ADF, 0x023985EC, 0x0632723C, 0xDB01A016, 0xCFD0904A, 0x2CBE329C, 0x175CC0C0, 0xACD1FFA3, 0x5C63FE76, 0x3039E337, 0x9FB53CF3, 0x77AF0D57, 0x4597BD95};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 222 ");
	}
	{
		static const bigint_t var_a = {0xD2A00659, 0x7B118956, 0x5037F3BC, 0xA0E75B93, 0x4BA59AB2, 0x05D772B6, 0x236A3EE3, 0xA31397CD};
		static const bigint_t var_b = {0xE4FD94D8, 0x2C0F4FA9, 0x49C51BE9, 0xC2D25F65, 0xED70F214, 0x9F511E73, 0x31D40625, 0x5EF7C2D6};
		word_t var_expected[16] = {0xC4A5CF18, 0x21676894, 0x3F0D549D, 0x8F593D63, 0x7C5799C1, 0xD7A72C35, 0xEC927A31, 0x92385C6B, 0x408FF829, 0xD744E873, 0x7236281B, 0xB2981625, 0x7E64D4EA, 0x8E319C94, 0x1516591E, 0x3C7F05C2};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 223 ");
	}
	{
		static const bigint_t var_a = {0x2CAC642B, 0xCAC63D8C, 0x88E3FD07, 0x58A6C134, 0xCB4ABC23, 0x00641F3C, 0x2C97C726, 0x6F7A103C};
		static const bigint_t var_b = {0x47EDBA6D, 0x17384A88, 0xB8CB724F, 0x7A0FF936, 0xE2443A38, 0x013D2A12, 0x6922B8B5, 0x95611854};
		word_t var_expected[16] = {0xEEFCE44F, 0x913ADD5C, 0x520DA39A, 0xE351EFA3, 0x8804F1E8, 0x33650EDE, 0x96E0B87B, 0x926F001F, 0x5535A9C0, 0x6FC9DA9A, 0x588545AD, 0x3721FF41, 0xBE1569AF, 0xD3E45887, 0x601C63A5, 0x410C534B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 224 ");
	}
	{
		static const bigint_t var_a = {0x790C01FA, 0x8A5C6448, 0x84979CFB, 0xD8680A94, 0x91E86C0E, 0xEE914046, 0x048D9CE8, 0xE62DD19E};
		static const bigint_t var_b = {0x266FF6CF, 0xCF29F19C, 0x1FBDB837, 0x32594F1A, 0x1D3F7DC6, 0x0879A824, 0x5C4AE1A8, 0x47D3628D};
		word_t var_expected[16] = {0x6201D526, 0x6EAE8DC3, 0xA1CFE6A5, 0x1E8B6708, 0xAC8071A9, 0x8B4A95AC, 0x765883E8, 0xCCD9F25A, 0x35951535, 0x28D299C4, 0x05D22FA4, 0xC32F4050, 0xA048070A, 0x6273FA94, 0x3CF7C47C, 0x4094C583};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 225 ");
	}
	{
		static const bigint_t var_a = {0x5A35E4DC, 0x43649292, 0xBD9B155B, 0xDDC1446E, 0x2D6A2FA9, 0x0414F464, 0x95EEC82A, 0xF4BE4AA3};
		static const bigint_t var_b = {0x426A740D, 0x7941266A, 0x17187D15, 0x45FDB713, 0x4ECCDF31, 0x8B0A6482, 0x1403DEBE, 0xFF2D8A8C};
		word_t var_expected[16] = {0x7B884F2C, 0xDC866CB8, 0x6EB5427E, 0x07A237DC, 0x785A8BA4, 0x6532858D, 0x976277D2, 0x0D12F311, 0x635FF1AB, 0xA1C11D6A, 0xC07B0B12, 0xC86AAC1B, 0xE5953DE0, 0x9673A136, 0x9089C5A6, 0xF3F51640};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 226 ");
	}
	{
		static const bigint_t var_a = {0xB1C40EC4, 0xB7DA2853, 0xEC48A67E, 0x656DED3E, 0x70C1CCEE, 0xB8D42E7F, 0x07EB1ABB, 0xC8D3D8C1};
		static const bigint_t var_b = {0x9CF7DC08, 0x796FE104, 0x7A33801C, 0x505A9AD5, 0x67E7AE5E, 0x9DD5769C, 0xDBD779D6, 0x8AD015B9};
		word_t var_expected[16] = {0xB9ECE620, 0x4593AB9B, 0x27AFFAFE, 0xE9A7D702, 0xDBE164A5, 0x0C058670, 0xAF437519, 0xF519F270, 0xFD6869DB, 0xB4B78819, 0xF94659CD, 0x0EB87330, 0x4F65C6FC, 0x967FDAF3, 0x5970E880, 0x6CE57003};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 227 ");
	}
	{
		static const bigint_t var_a = {0x9E92D88A, 0xED7705B6, 0x099867DC, 0xAC20CC68, 0x6BF6E110, 0xBE45F93F, 0xC4CDDE35, 0xCFF7706D};
		static const bigint_t var_b = {0x75728453, 0x7687BB7D, 0x60CE99AB, 0x32B0163A, 0x9829A0F3, 0x93EDBF97, 0x38B88D95, 0xF6660640};
		word_t var_expected[16] = {0xA0B75CBE, 0xDCFB47B6, 0xAE1D591D, 0x1D149323, 0x5C4EEFE5, 0x05DDD395, 0x0CE91C1A, 0x2E25E222, 0x0112AB8F, 0xA9522786, 0x730B8345, 0x6F3C508C, 0xBEE368D2, 0xD2FD786C, 0x3F6CF911, 0xC82AA7B4};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 228 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 181 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 182 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		word_t var_expected[16] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 183 ");
	}
	{
		static const bigint_t var_a = {0xA8C695A4, 0x6EA60236, 0xE0A18201, 0x6B58C595, 0x75B299C5, 0xEEEBF59E, 0xF59A0400, 0x05D60350};
		word_t var_expected[16] = {0x11285110, 0xBE12EFA3, 0x11C22BB9, 0x29B305F4, 0xED563879, 0x45BF0095, 0xC5BA73DE, 0x38D1DA20, 0x96FCFD37, 0xB21B67F9, 0x52AEF591, 0x9A11AB1B, 0x4B4019E3, 0xC2DF5898, 0xB4FDA102, 0x00220F0A};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 184 ");
	}
	{
		static const bigint_t var_a = {0x09BFE261, 0x38AF210C, 0x76B8B1F0, 0xB3291131, 0x7F1655A0, 0x29F63BF6, 0xD4D18964, 0x88E461D8};
		word_t var_expected[16] = {0x66ED68C1, 0x535748D6, 0xED3FFA56, 0x7B8025F9, 0xDD081734, 0x39C1049E, 0xFA3D4ED4, 0xC1602455, 0x4733B0C3, 0x3E3CC427, 0x0D4A9A99, 0x2D95034E, 0xA3D8CA81, 0xC3A1D633, 0xD1BFC025, 0x493373B4};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 185 ");
	}
	{
		static const bigint_t var_a = {0x5D9C83A8, 0xDEAE5DED, 0x6FC4F265, 0x8A51FFB8, 0x5635B9BD, 0x594932A1, 0x965061EE, 0xE4A4A5CD};
		word_t var_expected[16] = {0xC8755E40, 0x860EEC68, 0x8F2689C4, 0x9B18C748, 0x0E7808BF, 0x67DB93BF, 0xCDDBB562, 0x1B4A0D93, 0x61D4CB9D, 0x75010AC8, 0xB58ACCE2, 0x3E2E4F1E, 0x45D549DD, 0xBBA92ACC, 0x0E8A6E4B, 0xCC35B13B};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 186 ");
	}
	{
		static const bigint_t var_a = {0x0B6D4C00, 0xD36E639D, 0xAEC8BF9B, 0xEB2E6454, 0x1F1504F6, 0xE78661F8, 0x2C90DA95, 0x9A13B8AA};
		word_t var_expected[16] = {0xCE900000, 0xDD59CB31, 0x5050DC62, 0xC2F46D1E, 0xBC6B3509, 0xA6199666, 0xFE47DF51, 0x9497A4FC, 0x006DC879, 0x5CFA1846, 0xBF95BBB4, 0x0326E012, 0xE6670043, 0x3F29F4D3, 0xAC15F5AC, 0x5CBBBBB1};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 187 ");
	}
	{
		static const bigint_t var_a = {0x61587261, 0x8076D333, 0x5BD5515F, 0xA6685CEE, 0xA4CE6840, 0xF3D670CF, 0x8C8A0BF7, 0xC05F92FD};
		word_t var_expected[16] = {0x57CA88C1, 0x2C399DE2, 0x466432B0, 0x127D90F2, 0xCE1D4101, 0xDFFAF47F, 0x8A50F136, 0x9570A496, 0x16AA25BF, 0x07F21A2E, 0x55A5B71B, 0x225BA1A6, 0xDA6E6DAB, 0x5B72641F, 0xBF638FD5, 0x908F802A};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 188 ");
	}
	{
		static const bigint_t var_a = {0x0D5718C4, 0xC255F8FD, 0x60EC9338, 0xE09396B1, 0xD3BDF955, 0xCF8AA412, 0x2E575636, 0x80291214};
		word_t var_expected[16] = {0xBF9D5610, 0xA0FCA98D, 0x585A0F1B, 0x2635D077, 0x8F1D5619, 0x080380B6, 0xE9C91E41, 0x5B6FABE8, 0x3BA3B0CA, 0xF62B7501, 0x8A9E50A5, 0x30B41E52, 0xB761D747, 0xFB41CD02, 0xFA15064B, 0x402918AA};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 189 ");
	}
	{
		static const bigint_t var_a = {0xA47B8A32, 0x6ABF0B14, 0xECF5DDF2, 0x8F2ABB3B, 0x3F4278A8, 0x818F9EB7, 0x90D75590, 0x9710A79E};
		word_t var_expected[16] = {0x26A5F1C4, 0x5978687E, 0x9B5E211E, 0x9CDAB511, 0x19808252, 0x7183F69A, 0x4204EF23, 0x1E237B37, 0x865F4970, 0x93235FB0, 0x8E078FEC, 0xDEF07F27, 0xB8F7CAC6, 0x384ABBFC, 0x7070650B, 0x5924A6D2};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 190 ");
	}
	{
		static const bigint_t var_a = {0x1ECB69EF, 0xBC7314D7, 0xF4C46931, 0xFFD16CF0, 0x9E0F2C8E, 0x45B0CA59, 0xB2730355, 0xD792B38C};
		word_t var_expected[16] = {0x30DFED21, 0xBAA795E7, 0x24EF5B6A, 0x8B00DD7E, 0x9AA98DD8, 0xF0FBC2EA, 0xE180FE6F, 0xB893FF2B, 0xCCD72F8A, 0x3CABEC6D, 0x091848DD, 0x0924A1FF, 0x5D9DFD79, 0x892B7A91, 0x9E26C9A9, 0xB587BDA7};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 191 ");
	}
	{
		static const bigint_t var_a = {0x58A54A67, 0xF0FAA663, 0xAD2BB466, 0x4FF19A88, 0x490E24C6, 0x09A920BE, 0x9BE62776, 0xA53ABB47};
		word_t var_expected[16] = {0xCE65B571, 0x7C332D89, 0xF5562DEE, 0x44CF60BC, 0xEB8BF006, 0xBB0F8537, 0xD1B78450, 0xE76083B2, 0xEFE70CD6, 0x66ACB8EE, 0x06E4508F, 0x2F1FAD23, 0x6FECD503, 0x20313D22, 0xB46B04F2, 0x6AA4C2E3};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 192 ");
	}
	{
		static const bigint_t var_a = {0x91BD8753, 0xB52F1385, 0x13203C7A, 0xF5972018, 0xBFCB82C2, 0xF0082685, 0xD21A6901, 0x7B1DB83B};
		word_t var_expected[16] = {0x1E16A4E9, 0xF2772DDB, 0xF3728161, 0x2E8F82EA, 0xAA6B2E4B, 0x56EC1B73, 0xDFF3BAE6, 0xEE1EF621, 0xE87D08CB, 0xAA1F1818, 0xEAC7090F, 0x9E7F88B6, 0x4901C0E3, 0x22A6BDCE, 0xBE0906E4, 0x3B35927C};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 193 ");
	}
	{
		static const bigint_t var_a = {0xEDA24BAA, 0xA999C8DB, 0x66F051A4, 0x36B4E948, 0x227BB878, 0xD0E45985, 0xE51687D6, 0x67AA314C};
		word_t var_expected[16] = {0x9D850CE4, 0xEBB0FBD8, 0x96CD39F2, 0x2451D5F6, 0xEBDD6F72, 0x15B8297A, 0x837A8590, 0x19F0A699, 0x08885E62, 0xC0B650A0, 0xAA22E5C0, 0xE2F8FFB6, 0x6B242CFB, 0xB7C763D5, 0x63F6EA06, 0x29FA64D1};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 194 ");
	}
	{
		static const bigint_t var_a = {0xF5D812B6, 0xE297FBB8, 0xA887E88B, 0xAF991878, 0xB885CCD1, 0xB35974A3, 0xE5F999AA, 0x8BC8EE6E};
		word_t var_expected[16] = {0xF07E1964, 0x721713CF, 0xB449EF4B, 0xC139D832, 0x3ACCDC57, 0x2E8E27D0, 0x7C0A589F, 0x423F1B06, 0x677CE895, 0xE10069AC, 0xAC38A54F, 0x84A1AF94, 0x2F1EB02C, 0x044D54E4, 0xD916C686, 0x4C53D0A1};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 195 ");
	}
	{
		static const bigint_t var_a = {0x158028F5, 0x685BD5A8, 0x20C29A7E, 0xCFD7E5B6, 0x6BAB1837, 0x5ADF2381, 0xE80763F1, 0x9B455D26};
		word_t var_expected[16] = {0x2D8D7A79, 0xAC59BA71, 0xD80BA1B3, 0x172678B4, 0x4AE2DED0, 0x03A04D64, 0x6B04D0B7, 0xF372B651, 0xF46D02F4, 0x5BBF17D0, 0x5995CDD4, 0x3C3BD1CA, 0x091BC498, 0x37419E51, 0x75D75181, 0x5E2D1198};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 196 ");
	}
	{
		static const bigint_t var_a = {0x1D8EDF2F, 0xB8B1B8C3, 0xD9D156AF, 0x5A60346E, 0x4AB31722, 0xB56A3206, 0x86C60296, 0x629408FF};
		word_t var_expected[16] = {0x00B6EAA1, 0x9AE33FE7, 0xFDAC05D9, 0xC7C305A1, 0x0C13CC5F, 0x2D40D18E, 0xE6391156, 0x3706A4AF, 0xDADB45B0, 0xA193F9D3, 0x00793C99, 0xC8DD7C0C, 0x7C3A0A2F, 0x86BD8888, 0x0AF46668, 0x25F5AC7E};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 197 ");
	}
	{
		static const bigint_t var_a = {0xC1968A8A, 0x439F65A6, 0x23B361C4, 0xE7FD1389, 0x06AC2908, 0x6C603C9B, 0x5D29A684, 0x3DDBB984};
		word_t var_expected[16] = {0xB8B11264, 0xBE5CE462, 0xB352FE34, 0x958F7E9C, 0x622D33D4, 0x51DD0B5C, 0x6E9A8F6E, 0x7D6C9FF8, 0x5EA725CB, 0x4CCDD308, 0xDF484694, 0xF4DED395, 0x66BAA988, 0x69BDB07F, 0x034DD1B4, 0x0EF27300};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 198 ");
	}
	{
		static const bigint_t var_a = {0x19247436, 0xECC90560, 0x11B1A4A1, 0x631AAC97, 0x76BC6F75, 0x595763E8, 0x8ECEFCE6, 0x9E521B5D};
		word_t var_expected[16] = {0x6FF0FB64, 0x57256863, 0xD2CAF27C, 0x751A6664, 0x81F9D249, 0xCF6DA184, 0xA87DF820, 0x228E1660, 0x5782574D, 0x29CBA8D5, 0x4ED9B174, 0xB4B35C01, 0xD3B954E1, 0x153FB96F, 0x0723DB17, 0x61E9741D};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 199 ");
	}
	{
		static const bigint_t var_a = {0x219F59CB, 0x8EB36BBC, 0xFAF97648, 0x8DD54851, 0x138421AC, 0x0CABA60D, 0x3D4B8A9D, 0x8AF3F856};
		static const bigint_t var_expected = {0x219F59CB, 0x8EB36BBC, 0xFAF97648, 0x8DD54851, 0x138421AC, 0x0CABA60D, 0x3D4B8A9D, 0x8AF3F856};
		bi_shift_right(var_res, var_a, 0);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 200 ");
	}
	{
		static const bigint_t var_a = {0x3AC82A41, 0x74C40E10, 0xF94355DA, 0x776B8439, 0x7C0BFEA7, 0x46DECB95, 0x148824F0, 0x1C767846};
		static const bigint_t var_expected = {0x1D641520, 0x3A620708, 0xFCA1AAED, 0xBBB5C21C, 0xBE05FF53, 0x236F65CA, 0x0A441278, 0x0E3B3C23};
		bi_shift_right(var_res, var_a, 1);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 201 ");
	}
	{
		static const bigint_t var_a = {0xA7BF0FF8, 0xDF258E12, 0x6D813948, 0x0BEBC6F1, 0xF344BAF7, 0x7ECD00D8, 0xC02D31A8, 0x00A0E277};
		static const bigint_t var_expected = {0x8E12A7BF, 0x3948DF25, 0xC6F16D81, 0xBAF70BEB, 0x00D8F344, 0x31A87ECD, 0xE277C02D, 0x000000A0};
		bi_shift_right(var_res, var_a, 16);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 202 ");
	}
	{
		static const bigint_t var_a = {0x119EF73A, 0x846CC463, 0x79A584FC, 0x843C96ED, 0xDF1C8F78, 0x5FB1A117, 0x732174C7, 0xF8E2D75B};
		static const bigint_t var_expected = {0x846CC463, 0x79A584FC, 0x843C96ED, 0xDF1C8F78, 0x5FB1A117, 0x732174C7, 0xF8E2D75B, 0x00000000};
		bi_shift_right(var_res, var_a, 32);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 203 ");
	}
	{
		static const bigint_t var_a = {0x049D312F, 0x0B13B60E, 0x8578ACD9, 0xF17770D5, 0x481A49A2, 0x48F1CC74, 0x611181D6, 0x5B4B0AD1};
		static const bigint_t var_expected = {0x8578ACD9, 0xF17770D5, 0x481A49A2, 0x48F1CC74, 0x611181D6, 0x5B4B0AD1, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 64);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 204 ");
	}
	{
		static const bigint_t var_a = {0x70CFD231, 0x91C4E4BC, 0xBB7C1F3C, 0xB58B2AE1, 0x5E8F7BBC, 0xCAC5AEAB, 0x43112256, 0x91BED618};
		static const bigint_t var_expected = {0x2725E386, 0xE0F9E48E, 0x59570DDB, 0x7BDDE5AC, 0x2D755AF4, 0x8912B656, 0xF6B0C218, 0x0000048D};
		bi_shift_right(var_res, var_a, 21);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 205 ");
	}
	{
		static const bigint_t var_a = {0x823FCAE8, 0x286AEA39, 0x2777D153, 0x8BE2104A, 0x09330DD8, 0xF359B907, 0x2EABAEB3, 0xD7464537};
		static const bigint_t var_expected = {0x5F108251, 0x49986EC4, 0x9ACDC838, 0x755D759F, 0xBA3229B9, 0x00000006, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 93);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 206 ");
	}
	{
		static const bigint_t var_a = {0x1BBF9216, 0xF5E7626F, 0x669CC6F4, 0x5056B765, 0x278D1EC0, 0x793C2A32, 0xFC33F59F, 0xEDA3E88A};
		static const bigint_t var_expected = {0x6D1F4457, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 221);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 207 ");
	}
	{
		static const bigint_t var_a = {0x6BB77BC4, 0xDB973328, 0xA97DE655, 0x45F8CBF7, 0x877DC935, 0x08270396, 0x6320A40B, 0x13946B9F};
		static const bigint_t var_expected = {0x8D73EC64, 0x00000272, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 211);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 208 ");
	}
	{
		static const bigint_t var_a = {0x0CA3F828, 0xA42C0488, 0x689B7080, 0xEEBCA6C0, 0x466BA191, 0xB7827D0F, 0x6746C64A, 0x7BE7E137};
		static const bigint_t var_expected = {0x6ECE8D8C, 0x00F7CFC2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 199);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 209 ");
	}
	{
		static const bigint_t var_a = {0xAAAA59C4, 0xD4B21FC9, 0x2A9F4A32, 0x1595BCE5, 0x2342B98F, 0xCCC6B27A, 0xC1D0AC57, 0xC5A11C64};
		static const bigint_t var_expected = {0xAC57CCC6, 0x1C64C1D0, 0x0000C5A1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 176);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 210 ");
	}
	{
		static const bigint_t var_a = {0xCB32192B, 0x4C04C0B0, 0x7CBBD8CF, 0xFD05E6BB, 0x35BDC4FE, 0x40F8834E, 0xA0D84BE3, 0xFAD1960D};
		static const bigint_t var_expected = {0x7F7E82F3, 0xA71ADEE2, 0xF1A07C41, 0x06D06C25, 0x007D68CB, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 105);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 211 ");
	}
	{
		static const bigint_t var_a = {0x8D4359E2, 0x452F35E9, 0x32F940AB, 0x51BA9F5D, 0x4F7DE1CB, 0xA4D507E1, 0x4DD7F8C5, 0x6D13CE23};
		static const bigint_t var_expected = {0xD26A83F0, 0xA6EBFC62, 0x3689E711, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 161);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 212 ");
	}
	{
		static const bigint_t var_a = {0x1AEACB52, 0x56649537, 0x63CE806C, 0x35D5CFA0, 0x467CEEC6, 0x0739E055, 0x3C5684EB, 0xE9F21AFA};
		static const bigint_t var_expected = {0x495371AE, 0xE806C566, 0x5CFA063C, 0xCEEC635D, 0x9E055467, 0x684EB073, 0x21AFA3C5, 0x00000E9F};
		bi_shift_right(var_res, var_a, 20);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 213 ");
	}
	{
		static const bigint_t var_a = {0x243FF85F, 0x4670B5A4, 0x289E9DF2, 0x76AB73BC, 0x806B6E1B, 0x706EA196, 0x3F47DDDC, 0x61A94F13};
		static const bigint_t var_expected = {0x000061A9, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 240);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 214 ");
	}
	{
		static const bigint_t var_a = {0x660856C7, 0x640387FE, 0x04352978, 0x1B46C889, 0x150DD52C, 0x132D2FA5, 0x8AFEF51C, 0xC62231C4};
		static const bigint_t var_expected = {0x18C44638, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 227);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 215 ");
	}
	{
		static const bigint_t var_a = {0x806BAC87, 0x1CA6668B, 0x7178957C, 0xF472C749, 0xBDBFFF74, 0x9D89E45F, 0x418FF397, 0x728BC44E};
		static const bigint_t var_expected = {0x139063FC, 0x001CA2F1, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 202);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 216 ");
	}
	{
		static const bigint_t var_a = {0xD85F84F5, 0x5474631E, 0x0A239F47, 0x4C05EAB2, 0x9BCCA59B, 0x8E570278, 0xACBB4212, 0x32C22077};
		static const bigint_t var_expected = {0x72B813C4, 0x65DA1094, 0x961103BD, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 157);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 217 ");
	}
	{
		static const bigint_t var_a = {0x2078E520, 0x466FE03C, 0xBA56A41C, 0xA6612DB6, 0x8A13AEB2, 0xE0E4762F, 0x82EDD2F1, 0xA6068C82};
		static const bigint_t var_expected = {0xA320A0BB, 0x00002981, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 210);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 218 ");
	}
	{
		static const bigint_t var_a = {0xB86B8B96, 0x10CCF442, 0x62DC40C2, 0x83B27508, 0xE9F16FD0, 0xD74DCC9B, 0x9187DCA7, 0x836FA438};
		static const bigint_t var_expected = {0x00836FA4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 232);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 219 ");
	}
	{
		static const bigint_t var_a = {0x10C47694, 0xEA003BDB, 0xA92FA2BA, 0x3F83DAD7, 0x3713C730, 0xCEBDE400, 0x6E2E6850, 0xDC61A6B5};
		static const bigint_t var_expected = {0x7B62188E, 0x575D4007, 0x5AF525F4, 0xE607F07B, 0x8006E278, 0x0A19D7BC, 0xD6ADC5CD, 0x001B8C34};
		bi_shift_right(var_res, var_a, 11);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 220 ");
	}
	{
		static const bigint_t var_a = {0xF71BCBF4, 0xB2665471, 0x3C9E7C5F, 0xB81A855C, 0x13A4ABFB, 0x9132F751, 0xD9C5903E, 0xA3DD48F1};
		static const bigint_t var_expected = {0xFB8DE5FA, 0xD9332A38, 0x1E4F3E2F, 0xDC0D42AE, 0x89D255FD, 0x48997BA8, 0xECE2C81F, 0x51EEA478};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 221 ");
	}
	{
		static const bigint_t var_a = {0x9C19B784, 0x8A3A3F78, 0x6346ED56, 0xDB96596C, 0xB7C30E3B, 0xFF0AF04A, 0x8DEDF2C1, 0x596051F0};
		static const bigint_t var_expected = {0x4E0CDBC2, 0x451D1FBC, 0x31A376AB, 0xEDCB2CB6, 0x5BE1871D, 0xFF857825, 0x46F6F960, 0x2CB028F8};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 222 ");
	}
	{
		static const bigint_t var_a = {0x84EBBE1C, 0xC610ADEA, 0xDCAFD10E, 0x0726C9F7, 0x2A1C9934, 0x23BAC211, 0xF5D7D333, 0x8C16604F};
		static const bigint_t var_expected = {0x4275DF0E, 0x630856F5, 0xEE57E887, 0x039364FB, 0x950E4C9A, 0x91DD6108, 0xFAEBE999, 0x460B3027};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 223 ");
	}
	{
		static const bigint_t var_a = {0x5425281D, 0x86B78B58, 0x64790703, 0x03F9F921, 0x0E9D2640, 0x5433ED49, 0x1CD4842E, 0xC9892F53};
		static const bigint_t var_expected = {0x2A12940E, 0xC35BC5AC, 0xB23C8381, 0x01FCFC90, 0x874E9320, 0x2A19F6A4, 0x8E6A4217, 0x64C497A9};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 224 ");
	}
	{
		static const bigint_t var_a = {0x135F366C, 0x5E24A010, 0x806E3877, 0xEB755E34, 0x2A7C359F, 0x1EC2B339, 0x95D95FAA, 0xB18B128B};
		static const bigint_t var_expected = {0x09AF9B36, 0xAF125008, 0x40371C3B, 0xF5BAAF1A, 0x953E1ACF, 0x0F61599C, 0xCAECAFD5, 0x58C58945};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 225 ");
	}
	{
		static const bigint_t var_a = {0xAEDD19B9, 0xD86EB05C, 0xF7DB8174, 0xAD0E7F9E, 0xE655F3F9, 0xBE5C385F, 0xF4949A76, 0x7AA4A58F};
		static const bigint_t var_expected = {0x576E8CDC, 0x6C37582E, 0x7BEDC0BA, 0xD6873FCF, 0xF32AF9FC, 0x5F2E1C2F, 0xFA4A4D3B, 0x3D5252C7};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 226 ");
	}
	{
		static const bigint_t var_a = {0x75CBDA31, 0xF09A020A, 0x52F40120, 0x8F67B8CB, 0xD2DD9DD7, 0xA7C63991, 0x5284BE2F, 0x6DD1CF43};
		static const bigint_t var_expected = {0x3AE5ED18, 0x784D0105, 0xA97A0090, 0xC7B3DC65, 0xE96ECEEB, 0xD3E31CC8, 0xA9425F17, 0x36E8E7A1};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 227 ");
	}
	{
		static const bigint_t var_a = {0x9C0043B9, 0x9633FA85, 0x6344FDBA, 0xA7CD27DB, 0x1F1F1933, 0xFF82A46A, 0xCD23583D, 0x6993ACB4};
		static const bigint_t var_expected = {0xCE0021DC, 0x4B19FD42, 0xB1A27EDD, 0xD3E693ED, 0x0F8F8C99, 0xFFC15235, 0x6691AC1E, 0x34C9D65A};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 228 ");
	}
	{
		static const bigint_t var_a = {0x32111998, 0x92219AD1, 0x31A6AAC3, 0x28F7BF7B, 0x6CE99953, 0x67C61F31, 0x0F800DC0, 0x1DE7ADCA};
		static const bigint_t var_expected = {0xBB5B0888, 0x30B5DE45, 0xBB378E41, 0x62FD3FD3, 0x244DDDC6, 0x22975FBB, 0x052AAF40, 0x5F4D39EE};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 229 ");
	}
	{
		static const bigint_t var_a = {0xEF002C9E, 0x41583CD8, 0x9807319B, 0xFAAA429D, 0x8E6ADA89, 0x5A59FF93, 0xE57DCB12, 0x7ED89DB2};
		static const bigint_t var_expected = {0x4FAAB98A, 0x15C81448, 0x32AD1089, 0xFE38C0DF, 0xDA239E2D, 0x1E1DFFDB, 0xA1D49906, 0xD4F2DF3B};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 230 ");
	}
	{
		static const bigint_t var_a = {0xA5639234, 0x39E1FCB4, 0x2AD333D9, 0x2F0D1693, 0x2588E87D, 0xA3F2D228, 0x58CE387A, 0x2612AC01};
		static const bigint_t var_expected = {0x372130BC, 0x134B543C, 0x639BBBF3, 0x0FAF0786, 0x61D84D7F, 0x36A6460D, 0xC844BD7E, 0x62063955};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 231 ");
	}
	{
		static const bigint_t var_a = {0xA6309596, 0xBB88EFD5, 0x894F4EE3, 0xFA92FE80, 0x6CCC18EE, 0x2148F07E, 0xFAC36557, 0xA4B9DCB9};
		static const bigint_t var_expected = {0x37658732, 0xE92DA547, 0x2DC51A4B, 0xFE30FF80, 0x79995DA4, 0x606DA57F, 0xA8EBCC72, 0x36E89EE8};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 232 ");
	}
	{
		static const bigint_t var_a = {0x686B9BB6, 0x6A518839, 0x9A7B0E47, 0x8FAB3969, 0x1FE1179A, 0x560B42AE, 0xD913D32A, 0xBD5D466C};
		static const bigint_t var_expected = {0x7823DE92, 0xCE1B2D68, 0x337E5A17, 0x85391323, 0x0AA05D33, 0xC759163A, 0xF3069BB8, 0x94746CCE};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 233 ");
	}
	{
		static const bigint_t var_a = {0x12AF2372, 0xBADF459C, 0x187EC781, 0x9CCBEA14, 0xD66E1AED, 0xDD732992, 0x17872526, 0xEFD602D4};
		static const bigint_t var_expected = {0x063A6126, 0xE8F51734, 0x5D7F97D5, 0x3443F8B1, 0x9CCF5E4F, 0x49D10DDB, 0x5D2D0C62, 0x4FF200F1};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 234 ");
	}
	{
		static const bigint_t var_a = {0xF4512B8B, 0x82576F2A, 0x0162EE4B, 0xCE4A9988, 0x9FB426F7, 0xEC0F1D4D, 0x5FC1BFFC, 0xF3F5AADA};
		static const bigint_t var_expected = {0x517063D9, 0xD61D250E, 0x55CBA4C3, 0xEF6E332D, 0xDFE6B7A7, 0xF95A5F19, 0x1FEB3FFE, 0x5151E39E};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 235 ");
	}
	{
		static const bigint_t var_a = {0x093E8909, 0x76B1EBD5, 0x22EBECB9, 0x4B6FE3FF, 0x6FC03145, 0xDA33D1FA, 0x664B8106, 0x4D2CDBA8};
		static const bigint_t var_expected = {0xADBF8303, 0x2790A3F1, 0x0BA3F993, 0x6E7AA155, 0x2540106C, 0x9E1145FE, 0x776E8057, 0x19B99E8D};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 236 ");
	}
	{
		static const bigint_t var_a = {0x76816EE2, 0xA56CB3F4, 0x97A02BC2, 0x341363CB, 0xA9657845, 0x9BB4D626, 0x72CE61AB, 0xA93596E7};
		static const bigint_t var_expected = {0xD22B24F6, 0xE1CEE6A6, 0x328AB940, 0xBC067699, 0xE321D2C1, 0x33E6F20C, 0x2644CB39, 0x3867324D};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 237 ");
	}
	{
		static const bigint_t var_a = {0x14831BDC, 0xF2D27B99, 0x41111925, 0x2B8B4939, 0x9DDE3220, 0x31171FCD, 0xD0691123, 0x7B978AE9};
		static const bigint_t var_expected = {0x5C2BB3F4, 0xFB9B7E88, 0xC05B0861, 0xB92E6DBD, 0x349F660A, 0x65B25FEF, 0xF02305B6, 0xD3DD2E4D};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 238 ");
	}
	{
		static const bigint_t var_a = {0xE2E19C38, 0xA78B3100, 0x574A568A, 0xC9477D2C, 0x021A973A, 0x48518C62, 0x62677E12, 0x6D289097};
		static const bigint_t var_expected = {0x4BA08968, 0xE283BB00, 0x726E1CD8, 0x986D29B9, 0x5608DD13, 0x181B2ECB, 0x20CD2A06, 0x2462DADD};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 239 ");
	}
	{
		static const bigint_t var_a = {0x90211F88, 0xE8A5DFAB, 0xD15D4155, 0x2581E5C3, 0x80C39D5E, 0xA6C89D3C, 0x05D9320F, 0xED60E458};
		static const bigint_t var_expected = {0x85605FD8, 0xF8374A8E, 0x45C9C071, 0x61D5F741, 0x2AEBDF1F, 0xE242DF14, 0x01F310AF, 0xF9CAF6C8};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 240 ");
	}
	{
		static const bigint_t var_a = {0xF0EBC93B, 0x322DCE47, 0xFB35AB0C, 0x51C05EC6, 0x29E94C96, 0xAAE62CB8, 0x32AC9135, 0x9DDD06A6};
		static const bigint_t var_expected = {0x504E9869, 0x10B9EF6D, 0xFE673904, 0x709574EC, 0xB8A31987, 0x8E4CB992, 0x663985BC, 0x349F0237};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 241 ");
	}
	{
		static const bigint_t var_a = {0x8802C565, 0xDCF512FC, 0xEAAF33F3, 0xDE725CE7, 0xFC753FE5, 0xD30721CD, 0x69C5A8F5, 0xDC8C2EC5};
		static const bigint_t var_expected = {0xD800EC77, 0xF451B0FE, 0xA38FBBFB, 0xF4D0C9A2, 0xA97C6AA1, 0x9BAD0B44, 0x2341E2FC, 0x49840F97};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 242 ");
	}
	{
		static const bigint_t var_a = {0x0FF47B5A, 0x9E25C2BE, 0x009BC657, 0x5550873E, 0x621EB790, 0x31F23126, 0xB54D3AD5, 0x4BF59579};
		static const bigint_t var_expected = {0xAFFC291E, 0xDF61EB94, 0x0033ECC7, 0x71C5826A, 0xCB5F9285, 0xBB50BB0C, 0x91C468F1, 0xC3FC8728};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 243 ");
	}
	{
		static const bigint_t var_a = {0xD6745523, 0x0EE5A128, 0x6D354380, 0xBDC3874E, 0xB342906F, 0xFD98C109, 0x2C4ECF40, 0x3E637BC5};
		static const bigint_t var_expected = {0x477C1C61, 0x04F735B8, 0x24671680, 0x3F412D1A, 0x91163025, 0x54884058, 0x0EC4EFC0, 0xBF767E97};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 244 ");
	}
#elif PRECISION == 160
	{
		static const bigint_t var_a = {0x2350BA01, 0x3DE32B77, 0x6A8E616D, 0xB0AFAACA, 0xA97AC72D};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 1 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 2 ");
	}
	{
		static const bigint_t var_a = {0x23ED10A7, 0xA03F4B0C, 0x66A02F03, 0x3E7B92ED, 0xD1718E59};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 3 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 4 ");
	}
	{
		static const bigint_t var_a = {0xAFF50AFB, 0xBB718AC5, 0x88129EF8, 0x1B8D08DD, 0xBEE36526};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 5 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 6 ");
	}
	{
		static const bigint_t var_a = {0xA13350FB, 0x576596B7, 0x6FB81ACD, 0x12C4E535, 0xD7DFAD17};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 7 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 8 ");
	}
	{
		static const bigint_t var_a = {0x6EF22D3D, 0x49606902, 0x52CC3BBF, 0x73087168, 0xF9863282};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 9 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 10 ");
	}
	{
		static const bigint_t var_a = {0xCE2A1845, 0x4F8A38E1, 0xF112BB50, 0xA5A1BD40, 0x46933E28};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 11 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 12 ");
	}
	{
		static const bigint_t var_a = {0xAFA73CD2, 0xC1B53A4C, 0x9916DB98, 0xCFEA7FA7, 0x131F5CAE};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 13 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 14 ");
	}
	{
		static const bigint_t var_a = {0xBFEB4EDF, 0xB283C8F5, 0x4706F8FC, 0x1B7EB12E, 0x301E0BE4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 15 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 16 ");
	}
	{
		static const bigint_t var_a = {0x1FAB5F2E, 0x065C823D, 0x8E051B7B, 0xDDF6C780, 0x6C181C66};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 17 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 18 ");
	}
	{
		static const bigint_t var_a = {0xFA44917C, 0x3486AB97, 0x3517A359, 0x426C8498, 0x7CF15371};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 19 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 20 ");
	}
	{
		static const bigint_t var_a = {0xACDD11CB, 0xAFEC6039, 0xD173002D, 0x225318F1, 0xF016A850};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 21 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 22 ");
	}
	{
		static const bigint_t var_a = {0xB48640CC, 0x96A38772, 0x5AAE711D, 0x316F6A7E, 0x911D88C4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 23 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 24 ");
	}
	{
		static const bigint_t var_a = {0x170E8CA7, 0xF46FAA64, 0x2A7619A5, 0x46B28BD9, 0xDB56AA97};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 25 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 26 ");
	}
	{
		static const bigint_t var_a = {0x4B57404A, 0x9DC1F8BE, 0xF2025482, 0xD6CD43CF, 0xA8F93A6A};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 27 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 28 ");
	}
	{
		static const bigint_t var_a = {0x1951BE16, 0x6ECE86B0, 0x8F439CC3, 0xC8147D59, 0xCCC39CD4};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 29 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 30 ");
	}
	{
		static const bigint_t var_a = {0x358C951B, 0xF6EAACFB, 0xEC7BD506, 0xAAB2EF23, 0x93F9EF42};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_copy(var_tmp, var_a);
		assert_bi_equal(var_tmp, var_a, "bi_clear 31 ");
		bi_clear(var_tmp);
		assert_bi_equal(var_expected, var_tmp, "bi_clear 32 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 33 ");
		assert_true(carry == 0, "bi_add 34 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 35 ");
		assert_true(carry == 0, "bi_add 36 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 37 ");
		assert_true(carry == 0, "bi_add 38 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 39 ");
		assert_true(carry == 0, "bi_add 40 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 41 ");
		assert_true(carry == 1, "bi_add 42 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 43 ");
		assert_true(carry == 1, "bi_add 44 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 45 ");
		assert_true(carry == 1, "bi_add 46 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 47 ");
		assert_true(carry == 0, "bi_add 48 (carry)");
	}
	{
		static const bigint_t var_a = {0x462CC1BF, 0x576EDBFD, 0x5E101BD9, 0x9D6D549F, 0xB7E0EAA8};
		static const bigint_t var_b = {0x09FA74D5, 0x9EC1258B, 0xACC4EF5F, 0xE09CDFC6, 0xFC0B7D8F};
		static const bigint_t var_expected = {0x50273694, 0xF6300188, 0x0AD50B38, 0x7E0A3466, 0xB3EC6838};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 49 ");
		assert_true(carry == 1, "bi_add 50 (carry)");
	}
	{
		static const bigint_t var_a = {0x155EFC97, 0x708F5C03, 0xEF76DEF2, 0x7DF34538, 0xB6F4FD49};
		static const bigint_t var_b = {0x4A76713F, 0xC61B3681, 0xEB500879, 0xC9B72B31, 0x601F0C6F};
		static const bigint_t var_expected = {0x5FD56DD6, 0x36AA9284, 0xDAC6E76C, 0x47AA706A, 0x171409B9};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 51 ");
		assert_true(carry == 1, "bi_add 52 (carry)");
	}
	{
		static const bigint_t var_a = {0xB1446249, 0xC884192B, 0xF41C9CD5, 0xE40A2F3A, 0xD133FF2A};
		static const bigint_t var_b = {0x1470128F, 0x503F08DB, 0x891B1935, 0x4856305B, 0x5D728C13};
		static const bigint_t var_expected = {0xC5B474D8, 0x18C32206, 0x7D37B60B, 0x2C605F96, 0x2EA68B3E};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 53 ");
		assert_true(carry == 1, "bi_add 54 (carry)");
	}
	{
		static const bigint_t var_a = {0x89F6CA4C, 0xE179411C, 0x432418FC, 0x1F899D74, 0x3218B58D};
		static const bigint_t var_b = {0xE4A04C59, 0x57154D1E, 0x639E6260, 0x8263FC12, 0x062C27EA};
		static const bigint_t var_expected = {0x6E9716A5, 0x388E8E3B, 0xA6C27B5D, 0xA1ED9986, 0x3844DD77};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 55 ");
		assert_true(carry == 0, "bi_add 56 (carry)");
	}
	{
		static const bigint_t var_a = {0xB2DA60E1, 0x12118CBC, 0xEDEE6497, 0xDB26E450, 0x5EA7BE82};
		static const bigint_t var_b = {0x12F5003B, 0x58DE03DA, 0x5B65047D, 0x3CE7CB04, 0x57F3C322};
		static const bigint_t var_expected = {0xC5CF611C, 0x6AEF9096, 0x49536914, 0x180EAF55, 0xB69B81A5};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 57 ");
		assert_true(carry == 0, "bi_add 58 (carry)");
	}
	{
		static const bigint_t var_a = {0x9344A8C9, 0x1A6BBFC7, 0xDFA1BFAA, 0x026148B5, 0x6740424B};
		static const bigint_t var_b = {0xB0FBFBF3, 0x01B99F6F, 0x33C56106, 0x7A93179C, 0x09E91979};
		static const bigint_t var_expected = {0x4440A4BC, 0x1C255F37, 0x136720B0, 0x7CF46052, 0x71295BC4};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 59 ");
		assert_true(carry == 0, "bi_add 60 (carry)");
	}
	{
		static const bigint_t var_a = {0x7F15A5AF, 0x3B1C6E82, 0x5FEE683B, 0xFB509222, 0x3A9B31CF};
		static const bigint_t var_b = {0xEB7F13E8, 0xAC801A49, 0xF8368C0D, 0x5A021079, 0x4E15581B};
		static const bigint_t var_expected = {0x6A94B997, 0xE79C88CC, 0x5824F448, 0x5552A29C, 0x88B089EB};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 61 ");
		assert_true(carry == 0, "bi_add 62 (carry)");
	}
	{
		static const bigint_t var_a = {0x2300FCEF, 0x57C9E5C5, 0x19D24BBF, 0x8041FA82, 0x772634D1};
		static const bigint_t var_b = {0x2B72C6F7, 0x0876671A, 0x0133D0E0, 0x4DA6806B, 0x3C1BB363};
		static const bigint_t var_expected = {0x4E73C3E6, 0x60404CDF, 0x1B061C9F, 0xCDE87AED, 0xB341E834};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 63 ");
		assert_true(carry == 0, "bi_add 64 (carry)");
	}
	{
		static const bigint_t var_a = {0xEE8CAA89, 0xE1AF89A3, 0xA17E60CA, 0xA6830691, 0x6CC0A05C};
		static const bigint_t var_b = {0x788D9BE3, 0x919B0249, 0xD2327C50, 0x10C4F195, 0xF665C2E6};
		static const bigint_t var_expected = {0x671A466C, 0x734A8BED, 0x73B0DD1B, 0xB747F827, 0x63266342};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 65 ");
		assert_true(carry == 1, "bi_add 66 (carry)");
	}
	{
		static const bigint_t var_a = {0xE4BB6929, 0xAAC54252, 0x9044EC1C, 0xD0575F89, 0x2F312385};
		static const bigint_t var_b = {0xF63D70C0, 0xB800997A, 0x6B4FBCDA, 0x15EDCA9D, 0xD2170742};
		static const bigint_t var_expected = {0xDAF8D9E9, 0x62C5DBCD, 0xFB94A8F7, 0xE6452A26, 0x01482AC7};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 67 ");
		assert_true(carry == 1, "bi_add 68 (carry)");
	}
	{
		static const bigint_t var_a = {0x77E7A574, 0xC879F579, 0xAA831AB5, 0x9D30188C, 0xEB9ECEF0};
		static const bigint_t var_b = {0x76C7C694, 0xE831FAF8, 0xC4D14C35, 0x41AA174D, 0x065A6D53};
		static const bigint_t var_expected = {0xEEAF6C08, 0xB0ABF071, 0x6F5466EB, 0xDEDA2FDA, 0xF1F93C43};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 69 ");
		assert_true(carry == 0, "bi_add 70 (carry)");
	}
	{
		static const bigint_t var_a = {0x5DADAC7D, 0x2FFEFF93, 0xAD101B40, 0x193A8B64, 0xE0C280EF};
		static const bigint_t var_b = {0x6B97B843, 0xD3F8F1C7, 0x808D8073, 0x272A90B7, 0xAF53047A};
		static const bigint_t var_expected = {0xC94564C0, 0x03F7F15A, 0x2D9D9BB4, 0x40651C1C, 0x90158569};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 71 ");
		assert_true(carry == 1, "bi_add 72 (carry)");
	}
	{
		static const bigint_t var_a = {0x7AEDDA85, 0xB17164EB, 0xB78A5370, 0xB3759C0B, 0xA0BC903B};
		static const bigint_t var_b = {0xC19BB82C, 0xAB575439, 0x2A1267A9, 0x2923680D, 0x289959A9};
		static const bigint_t var_expected = {0x3C8992B1, 0x5CC8B925, 0xE19CBB1A, 0xDC990418, 0xC955E9E4};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 73 ");
		assert_true(carry == 0, "bi_add 74 (carry)");
	}
	{
		static const bigint_t var_a = {0x58B4ABFB, 0x81D4A1F7, 0x688D80A4, 0xC6F3DF1E, 0x8C524530};
		static const bigint_t var_b = {0x7078EEC0, 0x2E833B40, 0x6F357D7D, 0x2081719C, 0x0461CE83};
		static const bigint_t var_expected = {0xC92D9ABB, 0xB057DD37, 0xD7C2FE21, 0xE77550BA, 0x90B413B3};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 75 ");
		assert_true(carry == 0, "bi_add 76 (carry)");
	}
	{
		static const bigint_t var_a = {0xC3F5617B, 0x6D75C34E, 0x2CDA559E, 0xC04D8602, 0xAB09A1B3};
		static const bigint_t var_b = {0xBF175C9B, 0xB2628A16, 0x3441F773, 0x8237C0A3, 0x34CA5B97};
		static const bigint_t var_expected = {0x830CBE16, 0x1FD84D65, 0x611C4D12, 0x428546A5, 0xDFD3FD4B};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 77 ");
		assert_true(carry == 0, "bi_add 78 (carry)");
	}
	{
		static const bigint_t var_a = {0x83A5E517, 0x6C0C57F5, 0x4D4AE0BF, 0x1C9033A9, 0x451465AE};
		static const bigint_t var_b = {0x8C653D82, 0x961A5EAC, 0x7EBA36C8, 0x207CECD1, 0x1B0F1970};
		static const bigint_t var_expected = {0x100B2299, 0x0226B6A2, 0xCC051788, 0x3D0D207A, 0x60237F1E};
		int carry = bi_add(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_add 79 ");
		assert_true(carry == 0, "bi_add 80 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 81 ");
		assert_true(carry == 0, "bi_subtract 82 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 83 ");
		assert_true(carry == 0, "bi_subtract 84 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 85 ");
		assert_true(carry == 1, "bi_subtract 86 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 87 ");
		assert_true(carry == 0, "bi_subtract 88 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 89 ");
		assert_true(carry == 0, "bi_subtract 90 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_expected = {0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 91 ");
		assert_true(carry == 1, "bi_subtract 92 (carry)");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_expected = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 93 ");
		assert_true(carry == 0, "bi_subtract 94 (carry)");
	}
	{
		static const bigint_t var_a = {0x4BCFB6A6, 0x320F619C, 0xBDECFE22, 0xD8D1BF1E, 0xEA756797};
		static const bigint_t var_b = {0x1B9C68F2, 0xBB2C29AF, 0x7C529A4D, 0xE813337E, 0x9E33ACF0};
		static const bigint_t var_expected = {0x30334DB4, 0x76E337ED, 0x419A63D4, 0xF0BE8BA0, 0x4C41BAA6};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 95 ");
		assert_true(carry == 0, "bi_subtract 96 (carry)");
	}
	{
		static const bigint_t var_a = {0x551C6BC5, 0xE486E8F1, 0xBEED0987, 0x0AD7429A, 0xD234343C};
		static const bigint_t var_b = {0x387163C4, 0xF91B0CCD, 0x3EB19194, 0x550A8585, 0x6FA04933};
		static const bigint_t var_expected = {0x1CAB0801, 0xEB6BDC24, 0x803B77F2, 0xB5CCBD15, 0x6293EB08};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 97 ");
		assert_true(carry == 0, "bi_subtract 98 (carry)");
	}
	{
		static const bigint_t var_a = {0x418C4A92, 0x2DDAAFFA, 0xCD1B4477, 0xBCDE723E, 0xB7D3E605};
		static const bigint_t var_b = {0xB33C4698, 0xAA0A860D, 0xD6790972, 0x7A754438, 0x2CC40FC8};
		static const bigint_t var_expected = {0x8E5003FA, 0x83D029EC, 0xF6A23B04, 0x42692E05, 0x8B0FD63D};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 99 ");
		assert_true(carry == 0, "bi_subtract 100 (carry)");
	}
	{
		static const bigint_t var_a = {0x33589462, 0x372D6F49, 0x7ADC4F26, 0x40309C85, 0x94ECC8FD};
		static const bigint_t var_b = {0x78EDE50B, 0xC2D1154E, 0xFCB91F66, 0xBC9B80FB, 0x014BC4E8};
		static const bigint_t var_expected = {0xBA6AAF57, 0x745C59FA, 0x7E232FBF, 0x83951B89, 0x93A10414};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 101 ");
		assert_true(carry == 0, "bi_subtract 102 (carry)");
	}
	{
		static const bigint_t var_a = {0x48D2343D, 0x59391C46, 0x167D3173, 0x91B21519, 0xF26B27AA};
		static const bigint_t var_b = {0xD4E0A47F, 0x0D5DFE52, 0x68FB93EC, 0xC23D45ED, 0xED57241F};
		static const bigint_t var_expected = {0x73F18FBE, 0x4BDB1DF3, 0xAD819D87, 0xCF74CF2B, 0x0514038A};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 103 ");
		assert_true(carry == 0, "bi_subtract 104 (carry)");
	}
	{
		static const bigint_t var_a = {0xD3E8BED2, 0x7F6040CA, 0x5ECE10AA, 0x84E05D53, 0xA8ED32A3};
		static const bigint_t var_b = {0xAA7FD2A5, 0x84022BFC, 0x7BF31EFE, 0x23BEED7B, 0xE676C0D5};
		static const bigint_t var_expected = {0x2968EC2D, 0xFB5E14CE, 0xE2DAF1AB, 0x61216FD7, 0xC27671CE};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 105 ");
		assert_true(carry == 1, "bi_subtract 106 (carry)");
	}
	{
		static const bigint_t var_a = {0x03944891, 0x8F54AA38, 0x8A37E373, 0xD156E218, 0x3FE7AC24};
		static const bigint_t var_b = {0xA477F336, 0xE2DDDF7E, 0xFA65F7A5, 0xD6B192D7, 0x664D9049};
		static const bigint_t var_expected = {0x5F1C555B, 0xAC76CAB9, 0x8FD1EBCD, 0xFAA54F40, 0xD99A1BDA};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 107 ");
		assert_true(carry == 1, "bi_subtract 108 (carry)");
	}
	{
		static const bigint_t var_a = {0xE12DE0C9, 0x5A813FE8, 0x6BB4B0E2, 0x4015A77B, 0x4EF14C0A};
		static const bigint_t var_b = {0x9E8AE61F, 0xDB462353, 0xE0C92F04, 0x73DF3638, 0x246F8618};
		static const bigint_t var_expected = {0x42A2FAAA, 0x7F3B1C95, 0x8AEB81DD, 0xCC367142, 0x2A81C5F1};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 109 ");
		assert_true(carry == 0, "bi_subtract 110 (carry)");
	}
	{
		static const bigint_t var_a = {0xCE577B71, 0xDE8F618C, 0x79D36265, 0x7FEAA504, 0x9170FCBF};
		static const bigint_t var_b = {0xE0D4B290, 0x9D0F37FC, 0x8FAB3A1D, 0xC028369B, 0x0FBF3F0D};
		static const bigint_t var_expected = {0xED82C8E1, 0x4180298F, 0xEA282848, 0xBFC26E68, 0x81B1BDB1};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 111 ");
		assert_true(carry == 0, "bi_subtract 112 (carry)");
	}
	{
		static const bigint_t var_a = {0xE1EDDEE8, 0xDD633545, 0x0894305B, 0x6072B3A0, 0x8A683EEA};
		static const bigint_t var_b = {0xE722D76E, 0x8FAA1F8A, 0xEE351BE2, 0x2C194651, 0xBF78550A};
		static const bigint_t var_expected = {0xFACB077A, 0x4DB915BA, 0x1A5F1479, 0x34596D4E, 0xCAEFE9E0};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 113 ");
		assert_true(carry == 1, "bi_subtract 114 (carry)");
	}
	{
		static const bigint_t var_a = {0xCF6FFD25, 0x1DF12E44, 0xF549DF79, 0x9E204F32, 0xE7343378};
		static const bigint_t var_b = {0xC80922FB, 0x6571E448, 0x35CCD883, 0x1B2D845F, 0xFEF4B786};
		static const bigint_t var_expected = {0x0766DA2A, 0xB87F49FC, 0xBF7D06F5, 0x82F2CAD3, 0xE83F7BF2};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 115 ");
		assert_true(carry == 1, "bi_subtract 116 (carry)");
	}
	{
		static const bigint_t var_a = {0x5488AF99, 0xC6C3342E, 0x8A3BACE7, 0x5B16852B, 0x0894B898};
		static const bigint_t var_b = {0x7101A8BB, 0xFB5C3502, 0x74C08D83, 0x31298B56, 0x0F84A1BD};
		static const bigint_t var_expected = {0xE38706DE, 0xCB66FF2B, 0x157B1F63, 0x29ECF9D5, 0xF91016DB};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 117 ");
		assert_true(carry == 1, "bi_subtract 118 (carry)");
	}
	{
		static const bigint_t var_a = {0x2DC7D421, 0xBE272010, 0x73D7A7A7, 0xE486912C, 0x55A46C7F};
		static const bigint_t var_b = {0x574E3847, 0x9E5CC06A, 0x1A070432, 0xFF551FB1, 0xE1E21B93};
		static const bigint_t var_expected = {0xD6799BDA, 0x1FCA5FA5, 0x59D0A375, 0xE531717B, 0x73C250EB};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 119 ");
		assert_true(carry == 1, "bi_subtract 120 (carry)");
	}
	{
		static const bigint_t var_a = {0x1E875BEB, 0xF10CADD0, 0xF1F39F2A, 0x8F4801AF, 0x4587D35D};
		static const bigint_t var_b = {0x5328C858, 0xAD74122B, 0x04DEA934, 0xC5FB43A6, 0x55EC1B3A};
		static const bigint_t var_expected = {0xCB5E9393, 0x43989BA4, 0xED14F5F6, 0xC94CBE09, 0xEF9BB822};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 121 ");
		assert_true(carry == 1, "bi_subtract 122 (carry)");
	}
	{
		static const bigint_t var_a = {0x9F2883E8, 0xE52AE515, 0xB2D5E6D8, 0xAB689539, 0x47187B22};
		static const bigint_t var_b = {0xB7CE8A9C, 0xADAF805E, 0xE0C55A88, 0x205B6C73, 0x32C60275};
		static const bigint_t var_expected = {0xE759F94C, 0x377B64B6, 0xD2108C50, 0x8B0D28C5, 0x145278AD};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 123 ");
		assert_true(carry == 0, "bi_subtract 124 (carry)");
	}
	{
		static const bigint_t var_a = {0x2793AE0F, 0x0E0CDBEF, 0xF49337A2, 0xD245B886, 0xECDA6CC2};
		static const bigint_t var_b = {0xE62D47CF, 0x4E0A7352, 0xE576068B, 0xD66A7BC8, 0x8DF95222};
		static const bigint_t var_expected = {0x41666640, 0xC002689C, 0x0F1D3116, 0xFBDB3CBE, 0x5EE11A9F};
		int carry = bi_subtract(var_res, var_a, var_b);
		assert_bi_equal(var_expected, var_res, "bi_subtract 125 ");
		assert_true(carry == 0, "bi_subtract 126 (carry)");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 127 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 128 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 129 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 130 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 131 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 132 ");
	}
	{
		static const bigint_t var_a = {0x29227CE2, 0xBAA1A6CB, 0xE02093C2, 0x28624212, 0x01C37CD8};
		static const bigint_t var_b = {0x29227CE2, 0xBAA1A6CB, 0xE02093C2, 0x28624212, 0x01C37CD8};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 133 ");
	}
	{
		static const bigint_t var_a = {0xF4F0DAFD, 0xF7A9C234, 0x31B64B03, 0x312852D9, 0xA638FC25};
		static const bigint_t var_b = {0xF4F0DAFD, 0xF7A9C234, 0x31B64B03, 0x312852D9, 0xA638FC25};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 134 ");
	}
	{
		static const bigint_t var_a = {0x401078A1, 0x915B0925, 0x40984BEB, 0x46DF7877, 0x7E124B2D};
		static const bigint_t var_b = {0x401078A1, 0x915B0925, 0x40984BEB, 0x46DF7877, 0x7E124B2D};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 135 ");
	}
	{
		static const bigint_t var_a = {0x176226E2, 0xC52E866E, 0x4BAF54B8, 0x7A168995, 0x8618E0FD};
		static const bigint_t var_b = {0x176226E2, 0xC52E866E, 0x4BAF54B8, 0x7A168995, 0x8618E0FD};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 136 ");
	}
	{
		static const bigint_t var_a = {0x22EA2D02, 0xFB89B3C3, 0xFBCBABD6, 0xE0F77C79, 0x6B0C62D5};
		static const bigint_t var_b = {0x22EA2D02, 0xFB89B3C3, 0xFBCBABD6, 0xE0F77C79, 0x6B0C62D5};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 137 ");
	}
	{
		static const bigint_t var_a = {0xF0E6DBF8, 0x2B9D4E8D, 0x96C5DE9F, 0x8EF35120, 0xE74ACB30};
		static const bigint_t var_b = {0xF0E6DBF8, 0x2B9D4E8D, 0x96C5DE9F, 0x8EF35120, 0xE74ACB30};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 138 ");
	}
	{
		static const bigint_t var_a = {0x49E469DA, 0xEAA0C85E, 0xFD245823, 0x6DDF8CCA, 0x36F94D60};
		static const bigint_t var_b = {0x49E469DA, 0xEAA0C85E, 0xFD245823, 0x6DDF8CCA, 0x36F94D60};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 139 ");
	}
	{
		static const bigint_t var_a = {0xFA41CD9B, 0x9780CF53, 0xC543C28C, 0xB77AB8FF, 0x30FD5C1D};
		static const bigint_t var_b = {0xFA41CD9B, 0x9780CF53, 0xC543C28C, 0xB77AB8FF, 0x30FD5C1D};
		assert_true(bi_compare(var_a, var_b) == 0, "bi_compare 140 ");
	}
	{
		static const bigint_t var_a = {0x7AE9636A, 0xD6D09071, 0x7628D3B7, 0x57C6EDB4, 0x0BC0C948};
		static const bigint_t var_b = {0x98A0849F, 0xC157A294, 0x85F3E48B, 0x1B9CD851, 0x837B4480};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 141 ");
	}
	{
		static const bigint_t var_a = {0x912DDA35, 0xF6ED31A5, 0x9214E5C6, 0x7D694B27, 0x2B7ADD9F};
		static const bigint_t var_b = {0x9FED4036, 0x9164E33B, 0xF70D7CCD, 0x87A65C1B, 0x3523ECCC};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 142 ");
	}
	{
		static const bigint_t var_a = {0x3ACF10A7, 0xF6D1D1F6, 0x1D6503FD, 0x0B1EDB35, 0x53B0EA88};
		static const bigint_t var_b = {0x55723D8A, 0xC26C4A7D, 0xB92DF13A, 0x67D26394, 0x249E9090};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 143 ");
	}
	{
		static const bigint_t var_a = {0x7EEC4E49, 0xB5DAA3B7, 0xAB77C553, 0xF6C6D23B, 0xB7B7D5AE};
		static const bigint_t var_b = {0x29942AE4, 0xAA25D15E, 0x8985B6F1, 0x1B383952, 0xCB60499D};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 144 ");
	}
	{
		static const bigint_t var_a = {0x4C515934, 0xDBF010BE, 0x3B48A03A, 0xA11F84E4, 0x1DB3D969};
		static const bigint_t var_b = {0xC503A784, 0xCBBCD1B2, 0xC6AA3058, 0x15D1F213, 0x0207A144};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 145 ");
	}
	{
		static const bigint_t var_a = {0x6DE4FF7F, 0x3E2B7D0B, 0x772A88F7, 0x72577373, 0x1866A03F};
		static const bigint_t var_b = {0x1D0A3915, 0x2280673C, 0x5F519842, 0x60821004, 0xC87F53F4};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 146 ");
	}
	{
		static const bigint_t var_a = {0x7CFE47E2, 0x6FC0A31E, 0xF9C8D6F5, 0x5EAC866B, 0x741B9675};
		static const bigint_t var_b = {0xAA5ADA62, 0x4CE45128, 0xED768119, 0x7CA87B7E, 0x968E1FFC};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 147 ");
	}
	{
		static const bigint_t var_a = {0xDB37A4CA, 0xEF155E07, 0x3663AAEF, 0xBC96E199, 0x55AD40FB};
		static const bigint_t var_b = {0xF8FD3DDE, 0xF05BFD27, 0x0B3D8D40, 0xBFFF9187, 0xF81010CB};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 148 ");
	}
	{
		static const bigint_t var_a = {0xBFC5255F, 0xD66C7EF2, 0x098C4CEF, 0xD9BE67D7, 0x9514264E};
		static const bigint_t var_b = {0x231618DF, 0x1673363E, 0x2D274254, 0x8D6103C1, 0x904157AF};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 149 ");
	}
	{
		static const bigint_t var_a = {0xC6832EA4, 0xE97DB31B, 0xF35DD823, 0x246DE563, 0x63161000};
		static const bigint_t var_b = {0x047FCF42, 0x5BBA4998, 0x802626E7, 0x2976130A, 0xABED8EAA};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 150 ");
	}
	{
		static const bigint_t var_a = {0xB4164ABC, 0x855B6623, 0x8487D6A5, 0xEFFF97B8, 0x3582EF49};
		static const bigint_t var_b = {0x1A2E27E8, 0x1511D0C2, 0x9BE68576, 0xF67BC0A3, 0x0AD1B8EA};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 151 ");
	}
	{
		static const bigint_t var_a = {0x4E7ECB35, 0xBCB5FDF3, 0x8E890738, 0x123E31A3, 0x88470877};
		static const bigint_t var_b = {0x6CCA727D, 0xE61A5B88, 0x09B8FC57, 0x5370B212, 0x921B0B39};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 152 ");
	}
	{
		static const bigint_t var_a = {0x68BF90E2, 0x963554E3, 0x115287E8, 0xF7AB8460, 0x054AA108};
		static const bigint_t var_b = {0xFECA616B, 0x59F423A5, 0xF451DC79, 0x858B9C22, 0xFE16F8B2};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 153 ");
	}
	{
		static const bigint_t var_a = {0xA05CCC1B, 0x5F9EA664, 0xFED9B88D, 0xD9689319, 0x0094F616};
		static const bigint_t var_b = {0x8E92A542, 0x71DB2706, 0x7A0258D9, 0x3EF0F2F3, 0xCC06734F};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 154 ");
	}
	{
		static const bigint_t var_a = {0x5EEBC291, 0x5BD0F9DF, 0x47E12224, 0x371CAF8C, 0x732AACED};
		static const bigint_t var_b = {0xB209E1EA, 0x5B4C3792, 0x70D5F4C5, 0xCEF8BABA, 0xF6428E29};
		assert_true(bi_compare(var_a, var_b) == -1, "bi_compare 155 ");
	}
	{
		static const bigint_t var_a = {0x14845FC9, 0x633691BB, 0xD52379BE, 0xCD2F11D2, 0xDFA21BA4};
		static const bigint_t var_b = {0x9134BFC4, 0x9E57BE89, 0xA44BC93E, 0xFB7EEBA6, 0x3C4662E3};
		assert_true(bi_compare(var_a, var_b) == 1, "bi_compare 156 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 157 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 158 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 159 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 160 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		const word_t var_expected[10] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 161 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		const word_t var_expected[10] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 162 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 163 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		static const bigint_t var_b = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 164 ");
	}
	{
		static const bigint_t var_a = {0xCFE76302, 0x32A80819, 0x55BB26EA, 0x9688A3F1, 0xB382B9D9};
		static const bigint_t var_b = {0xC5BF9E74, 0x7E862D08, 0xD980513B, 0x1029A030, 0x0383EE4F};
		const word_t var_expected[10] = {0x6C7218E8, 0x8C1138E6, 0x00B43AA5, 0x2459C1BC, 0xC96227DD, 0x2F38993F, 0x8482D43A, 0x87854C46, 0xA090A1D1, 0x02770B2D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 165 ");
	}
	{
		static const bigint_t var_a = {0x954A57C5, 0x69ED1696, 0x04A5003F, 0x9839EAF2, 0x36B1C277};
		static const bigint_t var_b = {0x3790DBD0, 0x72CB0C4D, 0x0EA5E664, 0xADFDCDF1, 0x1D5ECB8C};
		const word_t var_expected[10] = {0x974CD710, 0xA86CC0FD, 0x15D496A2, 0x135D65B4, 0xA71AB53A, 0x5795E388, 0x21C97BED, 0xB7A26294, 0xF7BFFE16, 0x064663C9};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 166 ");
	}
	{
		static const bigint_t var_a = {0x2E91B988, 0x98E15196, 0xE0DF5A22, 0x93D53943, 0xFEAF0148};
		static const bigint_t var_b = {0xE493FE42, 0xD48F2B79, 0xDC853DA7, 0x55916DA4, 0xF13C3172};
		const word_t var_expected[10] = {0x40BEC510, 0x53C31B1F, 0x919FF138, 0xCD88C2F1, 0x22B1E700, 0x385E682F, 0xC1855B95, 0x51C1AB0E, 0xDE7CA121, 0xEFFEA26A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 167 ");
	}
	{
		static const bigint_t var_a = {0x41CAFFB5, 0xD04F258A, 0xE11E626F, 0xC92048AC, 0x79338929};
		static const bigint_t var_b = {0xF4750D4A, 0x3C3DCE0A, 0xE31EEB9D, 0xCFDB5F4A, 0xD83458FF};
		const word_t var_expected[10] = {0xB5631B52, 0x70810FDF, 0x8287B880, 0x876A5FCC, 0xF1524AFB, 0xE159504E, 0xFA13E84A, 0xC5E6D620, 0xF2149DBF, 0x665C4455};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 168 ");
	}
	{
		static const bigint_t var_a = {0xEF8DD383, 0x81046984, 0x2CEC88D2, 0x7682110C, 0x1AE41AE4};
		static const bigint_t var_b = {0x8DFE3D36, 0x2378510F, 0x9FD48F4C, 0xD878A4BD, 0xB82BA490};
		const word_t var_expected[10] = {0x564AD4A2, 0x258D9303, 0xFCDD5A84, 0x1B862DC7, 0xCD04495F, 0x479B4590, 0xBE9E072B, 0x04EC744B, 0x11D40373, 0x135888EE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 169 ");
	}
	{
		static const bigint_t var_a = {0x510C6A30, 0xB3DEE091, 0x6625CD22, 0xAFC5B53A, 0x20DAA0A2};
		static const bigint_t var_b = {0x3FDF3616, 0xBAF2A202, 0x26AB9ACF, 0xB796FB30, 0x152E2418};
		const word_t var_expected[10] = {0xE5474020, 0x98B8CFE7, 0x5B199175, 0xE3CCA93C, 0xB8EAEB9E, 0x2C7A3F4E, 0xF68B5355, 0x97521571, 0x204C6687, 0x02B7DB18};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 170 ");
	}
	{
		static const bigint_t var_a = {0x89BA0371, 0xE6E556E6, 0x7F3EC455, 0xC60BF473, 0x1A99146A};
		static const bigint_t var_b = {0x06070DC9, 0x271A7F14, 0x948AAA06, 0xAC6E42AD, 0x36F5CBE6};
		const word_t var_expected[10] = {0x535070B9, 0x51BA63FF, 0x2BFECEE1, 0xDD4575BD, 0x78BABEA7, 0xD6E22F48, 0xB27ACF78, 0xBC0B96BB, 0x6A996066, 0x05B5D3FE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 171 ");
	}
	{
		static const bigint_t var_a = {0x3C0FDC87, 0x1328D8DD, 0xBB87BE05, 0x6556A69C, 0x8D3D8B45};
		static const bigint_t var_b = {0x296559F9, 0x7A35F81B, 0x2D0592B3, 0x5BA64043, 0x112023B7};
		const word_t var_expected[10] = {0x8F5B6E4F, 0x85491FE1, 0x607B10BC, 0x0D98E5E2, 0xEC146EF3, 0xB52B2654, 0xAD998D84, 0xF28D30CB, 0x98011139, 0x0972D1A5};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 172 ");
	}
	{
		static const bigint_t var_a = {0xB96AED8C, 0xA073622F, 0xC21CDFEC, 0xFB55F7DF, 0x6706B3FA};
		static const bigint_t var_b = {0x8DD0474D, 0x1AAD3F21, 0x8C27E497, 0x9BB60F1F, 0x1B0C3656};
		const word_t var_expected[10] = {0x8ACB471C, 0x49B0638A, 0x4A81433F, 0x63ED974E, 0x791061B5, 0xC155D836, 0x6228D66E, 0xCA7F91D8, 0x2D279453, 0x0AE29F2A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 173 ");
	}
	{
		static const bigint_t var_a = {0x176C82F7, 0x5073AC29, 0xF7F55485, 0x2E41943D, 0x2EB5E7C1};
		static const bigint_t var_b = {0x2CA9390F, 0x7F6A6480, 0x4D31699E, 0x533BE69B, 0x2F978C4A};
		const word_t var_expected[10] = {0x7193AB79, 0x0BF35144, 0x44B76DB8, 0x1E5FD064, 0x965BCFBD, 0x8DB24C39, 0x5892A694, 0xDD0F923C, 0x34F2DE2C, 0x08AF0C71};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 174 ");
	}
	{
		static const bigint_t var_a = {0x09644804, 0x7456418B, 0x6A227E77, 0x74F41B98, 0xFF3AA131};
		static const bigint_t var_b = {0xD04BB360, 0x7263631F, 0x10BD57A8, 0x4D31E198, 0x24F23FC0};
		const word_t var_expected[10] = {0xFD21CD80, 0xA8144B14, 0x64DCBA9B, 0x3286B092, 0x0AB242C9, 0xD21BC043, 0x83AFC5D2, 0x2CB1CEC1, 0x7BCD5122, 0x24D5C3A6};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 175 ");
	}
	{
		static const bigint_t var_a = {0x409F51C2, 0xDF9563EE, 0x22481F63, 0x0385D451, 0xE31D297F};
		static const bigint_t var_b = {0x46A40C72, 0x25C1C10B, 0xD2680170, 0x20727840, 0xD21B3BF8};
		const word_t var_expected[10] = {0xAB0F8064, 0x4C4066E1, 0x5241EDBE, 0xEC5DCD39, 0xE7DE9CF2, 0x59FE78CD, 0x0758EAC4, 0xBCAA8F8F, 0x6AE2D2FE, 0xBA661551};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 176 ");
	}
	{
		static const bigint_t var_a = {0x91B5EF40, 0x6F9E6223, 0x9679F4D7, 0xAB60F9A0, 0xFDC0B710};
		static const bigint_t var_b = {0x9FA0FD38, 0xE97ABD1B, 0xEC8B3DC0, 0xAA839C63, 0x8D2EF30B};
		const word_t var_expected[10] = {0xF53E9600, 0x53B02BD6, 0xA98FEE2A, 0x6E56C48D, 0xB5101394, 0x851810EC, 0x892F798A, 0xF2BD1863, 0x91745381, 0x8BF1AE5E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 177 ");
	}
	{
		static const bigint_t var_a = {0x3B387A9E, 0x36C4986C, 0x7F0A5DC7, 0x6A14633A, 0xA193AAE1};
		static const bigint_t var_b = {0x4610D6FD, 0x47FDDAC3, 0x33863DB4, 0xABDF5E03, 0x6A6E5B9F};
		const word_t var_expected[10] = {0x9B314226, 0xCB4033E0, 0x17A1B66A, 0x15A2214D, 0x546FBD7E, 0xB14E22AF, 0xEFA5DA67, 0xA7E23EB0, 0x07B7E6AB, 0x432CCC09};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 178 ");
	}
	{
		static const bigint_t var_a = {0xFDD01369, 0x75EDB947, 0x79A3F07E, 0xA875141D, 0x5AEE40F3};
		static const bigint_t var_b = {0xE12355CA, 0xC3617078, 0x0DC4A57F, 0x80813EDD, 0xC18C83D8};
		const word_t var_expected[10] = {0x4CFC2DDA, 0xEED4B7CE, 0xFC6121CA, 0xAB6897C0, 0xDAC7FB26, 0x3111D0B1, 0x15A26450, 0x0C36A0C6, 0x0928E9D8, 0x44BF8818};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 179 ");
	}
	{
		static const bigint_t var_a = {0xDC742C8A, 0x0B73B8F3, 0x093391DD, 0x893EE909, 0x5862DFAE};
		static const bigint_t var_b = {0x655F630D, 0x9E202BF6, 0x83457E77, 0x119BA6E9, 0xCCED476A};
		const word_t var_expected[10] = {0x1855A102, 0x463D51EE, 0x18815E17, 0x88962038, 0x2DCE4F7C, 0xC0F46BFD, 0x43F1ABCC, 0xF9863C76, 0x3501859E, 0x46C0B670};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 180 ");
	}
	{
		static const bigint_t var_a = {0xCF88AA1F, 0x14D4B976, 0xFBD3421E, 0xB4C3FA84, 0xF246B313};
		static const bigint_t var_b = {0xC5EDEEE0, 0x4BD56893, 0x8D5AFB8E, 0x691F39F0, 0x54771F6A};
		const word_t var_expected[10] = {0xFF70AD20, 0x70A25122, 0x9ADA099F, 0xF4415F31, 0xEE50D51F, 0x21A26C3B, 0x3D40F177, 0xD563CD38, 0xF9EB6B31, 0x4FEFEF5A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 181 ");
	}
	{
		static const bigint_t var_a = {0xA60BE519, 0xBE9C9D82, 0x3B24B22D, 0x7B524F22, 0x12B28366};
		static const bigint_t var_b = {0x19F6A605, 0x6DF7412F, 0x2AEDC929, 0x9D28E97D, 0xC79B406F};
		const word_t var_expected[10] = {0x8BCFAF7D, 0x966DEC9D, 0x2041498B, 0x840A2DC1, 0x12ABBA4D, 0x55BA2833, 0x650EA2AC, 0x91B60A8A, 0x00A4B625, 0x0E941AEF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 182 ");
	}
	{
		static const bigint_t var_a = {0xE6D7BE13, 0x9E5448F5, 0x9B24EBCE, 0x50906F1F, 0xC993EDFE};
		static const bigint_t var_b = {0x3B64101C, 0x9F1D648C, 0x0C2A5546, 0xE76F779A, 0x3383D8C1};
		const word_t var_expected[10] = {0x5BE5FA14, 0x9B6B9CCB, 0x57055C92, 0x53B3F33F, 0xAF4B9B56, 0xCC877836, 0xF19192E2, 0x7FE51A81, 0xF2C141D2, 0x289049C9};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 183 ");
	}
	{
		static const bigint_t var_a = {0x73295E4C, 0x14FF84B5, 0x15617174, 0xE2F08E06, 0x5DB200F3};
		static const bigint_t var_b = {0x269BE3B8, 0x5BCC1490, 0xD532C9F6, 0x16EA8C95, 0xF473187D};
		const word_t var_expected[10] = {0xD45D2AA0, 0x1E7C2053, 0x844CB40A, 0xB070AE73, 0x4E146B4C, 0x0C259048, 0x324E0161, 0xF9782181, 0x5A40B207, 0x5977C8D5};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 184 ");
	}
	{
		static const bigint_t var_a = {0x3F964DE9, 0x77C0A812, 0x97226795, 0x65961D78, 0x8F93D77E};
		static const bigint_t var_b = {0xA24DDDB4, 0xADCA5CD0, 0x41D18F0F, 0xD16F73A8, 0x1A7FB4AA};
		const word_t var_expected[10] = {0x5805ECD4, 0x3B41348C, 0xA534615C, 0xD4D38838, 0x56618E77, 0xE05E2290, 0xD9E8AC24, 0x490FB350, 0x7F2DD2BA, 0x0EDCA38E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 185 ");
	}
	{
		static const bigint_t var_a = {0x56E6C4D8, 0x26259D55, 0x5B964898, 0xBEBF7385, 0xEC48E8C9};
		static const bigint_t var_b = {0xF651D842, 0x9FC71BE9, 0xAB70F9E3, 0x3CF8C2A0, 0xCE082DE9};
		const word_t var_expected[10] = {0xF5ECFFB0, 0xF6A8C216, 0x7F860683, 0x4FDB3A12, 0x8C67E288, 0xE6F7981F, 0x8F1286B0, 0x87C963CF, 0xB55A0BEB, 0xBE2A37F9};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 186 ");
	}
	{
		static const bigint_t var_a = {0xFB7E2B9F, 0xAC63DA9F, 0x4F7C232B, 0xBCDA9A53, 0x6268A5DC};
		static const bigint_t var_b = {0xC23F8E14, 0x7E96BC1E, 0xD103B3BE, 0xF3A54A8E, 0x469BB5C9};
		const word_t var_expected[10] = {0xDC2E9A6C, 0xD70233BC, 0x63602F20, 0xA77A7C80, 0x9912B18A, 0x827728EC, 0x75FF7FB2, 0xA3CD0889, 0x676249F1, 0x1B247898};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 187 ");
	}
	{
		static const bigint_t var_a = {0xBDB53CE8, 0x9851C003, 0x20DD7004, 0x7E74C4A1, 0x7987C1A9};
		static const bigint_t var_b = {0x2B133154, 0x63BDD9D4, 0xC27EDE91, 0x8D895141, 0x029B4D3C};
		const word_t var_expected[10] = {0x6D586420, 0xEBB75658, 0x4E45AFA6, 0x4BEC4FD6, 0x2AFEFDEF, 0x8D9D687B, 0xB431FD12, 0x3CC212AB, 0x28DECEE3, 0x013CC960};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 188 ");
	}
	{
		static const bigint_t var_a = {0xA22B444B, 0xC4B2034C, 0xE6D1471C, 0xB0285A4F, 0xD4261BC6};
		static const bigint_t var_b = {0xFD7E0941, 0xB2507934, 0x5F4181E7, 0xF1D9E31C, 0x6B7D1AF5};
		const word_t var_expected[10] = {0x6E4CFA0B, 0x70CE6E2E, 0x1C1BDFFE, 0xA68740D2, 0xECD68659, 0xC4C799E0, 0xB841E509, 0x1345AD9D, 0x4B5C1527, 0x59139A8F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 189 ");
	}
	{
		static const bigint_t var_a = {0xDB9547E7, 0x0F9D5FB2, 0x835AE497, 0x54682E59, 0xED6C980B};
		static const bigint_t var_b = {0x731729C4, 0x636F8DEA, 0xD2C4DCBC, 0x4C4AA955, 0x091FDB5E};
		const word_t var_expected[10] = {0x41900BDC, 0x8BBDA7F7, 0x39178CE3, 0xDD712960, 0xAC11C65C, 0xC4574DF3, 0x7F5FF4F6, 0x7999A539, 0x2A09E330, 0x08765CF2};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 190 ");
	}
	{
		static const bigint_t var_a = {0xA6E898FE, 0xDBEE6DF2, 0x2BED0771, 0x220BA813, 0x2D2A51F2};
		static const bigint_t var_b = {0xC1A162F4, 0x4CF78D63, 0xE52681EC, 0x6C66417B, 0xE9547D9C};
		const word_t var_expected[10] = {0xD6010E18, 0xA8111305, 0x9DD70B51, 0x3BDEE7D8, 0xB686C9DF, 0xDF678BE6, 0xB955B393, 0x70D8E9B8, 0x875CD6F5, 0x292A6CA1};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 191 ");
	}
	{
		static const bigint_t var_a = {0x44029B05, 0xDDDC9496, 0xB9A04902, 0xCD2A821F, 0xC3B52018};
		static const bigint_t var_b = {0x9BA8C72D, 0xD5859031, 0x2858F636, 0xC4493706, 0xF4E4A23F};
		const word_t var_expected[10] = {0xBD3E22E1, 0x235C9ECE, 0x8ED42F18, 0x390D031F, 0x685F34AB, 0x7950B820, 0x15A5B6C6, 0x481FA287, 0x97947B1B, 0xBB376BF1};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 192 ");
	}
	{
		static const bigint_t var_a = {0x2B8701E6, 0xED7395D8, 0xB8E47E58, 0xAE5547A9, 0xF111E1CE};
		static const bigint_t var_b = {0x418CC3FF, 0xB0605077, 0x42CE93AD, 0x69EA4897, 0x3B431350};
		const word_t var_expected[10] = {0xA1B5161A, 0xA924C2B5, 0xF6B67F28, 0xA050DAB4, 0x08EF739D, 0xF7D298B0, 0x0C4E2195, 0x5263D4A3, 0xC85B23AE, 0x37CE48E8};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 193 ");
	}
	{
		static const bigint_t var_a = {0xDAED7E86, 0xFE25F31D, 0x4C756BCC, 0xA1C6977D, 0xA9BFFC38};
		static const bigint_t var_b = {0xE6ACB0D0, 0x8DC391A5, 0xDE392C89, 0xC9609C77, 0x87D60177};
		const word_t var_expected[10] = {0x8DFAECE0, 0x8E88F860, 0xBCBF49C0, 0xD697947E, 0x47550849, 0xE40135C3, 0x19076227, 0x35847CDF, 0xE26939A2, 0x5A122577};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 194 ");
	}
	{
		static const bigint_t var_a = {0x05901079, 0x702527FE, 0x59EE153C, 0x1D92EB23, 0xA58C4EDF};
		static const bigint_t var_b = {0x6598F32C, 0xE91A3721, 0x14F08358, 0xEE5DDA3C, 0xB0AC5B3D};
		const word_t var_expected[10] = {0x393DAFCC, 0xFAC44193, 0x21D742D5, 0x5EF2551C, 0xB4D971AF, 0x88F840B9, 0xDFEACE72, 0xF94F020B, 0x4EDA1D77, 0x723FEB7F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 195 ");
	}
	{
		static const bigint_t var_a = {0xE8474DE8, 0x4800445A, 0xA1E0E6FA, 0xC8ACCD64, 0x69C41EFA};
		static const bigint_t var_b = {0x9F60668E, 0x6139A5C6, 0x4909FF49, 0x8035AE36, 0x897FFE9E};
		const word_t var_expected[10] = {0x8F97A6B0, 0x00C25089, 0x25F683A5, 0xD26A2C03, 0x3200A8BD, 0xE394AD14, 0x797E87DE, 0x96DA44DF, 0xA68E3699, 0x38CED611};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 196 ");
	}
	{
		static const bigint_t var_a = {0x027CDF4E, 0x25ADAB03, 0xAFE4D9A4, 0x1BE6EDBA, 0xCE532E0B};
		static const bigint_t var_b = {0xFFFD57C7, 0x3064FA2A, 0xC8BB259F, 0xEDCD4541, 0x5E45511B};
		const word_t var_expected[10] = {0xC10B17A2, 0x85989BD2, 0xE48F8A65, 0x4C5B1030, 0x6EB642FD, 0xE0518337, 0x0E5B307C, 0x3A843758, 0x513D2196, 0x4BFA68B2};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 197 ");
	}
	{
		static const bigint_t var_a = {0x8DD04562, 0xDF9D2956, 0xC0AA44B1, 0xCF79C507, 0x07F083E4};
		static const bigint_t var_b = {0xEEF151CA, 0xCA7C568D, 0xB2BEB862, 0x60402510, 0x5A547CBB};
		const word_t var_expected[10] = {0x398CC154, 0x90E745B7, 0xD508FAF2, 0x5C911C12, 0xF568FA74, 0x30A74635, 0xEF22A759, 0xF84EC08D, 0x07943E98, 0x02CD2D28};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 198 ");
	}
	{
		static const bigint_t var_a = {0x6AD52E36, 0x30805D91, 0x15C427D3, 0x29456B82, 0x3BFD403D};
		static const bigint_t var_b = {0x40CF22FE, 0xAB60D61B, 0xF099DF22, 0x6643480B, 0x53EEE4AB};
		const word_t var_expected[10] = {0x2D510594, 0x0E71D818, 0x6C4AEFCB, 0x8F443C68, 0xD7BC388E, 0xB9417FAF, 0x767EDF42, 0xB9E567A9, 0x4494EDC3, 0x13AB16DB};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 199 ");
	}
	{
		static const bigint_t var_a = {0x5C40EB43, 0xE7AADC59, 0x50A90217, 0x69090631, 0x2C16F6D5};
		static const bigint_t var_b = {0xE8F234FF, 0xCD25BE5D, 0x49420B6F, 0x7976DEFE, 0xC6EAB249};
		const word_t var_expected[10] = {0x31C9F3BD, 0x19E7DFAA, 0x3E405BD6, 0x35179BF3, 0x4ADDEB08, 0x9F7EA3BE, 0xDAB9D62C, 0x61CF1370, 0x4D671695, 0x22422E9B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 200 ");
	}
	{
		static const bigint_t var_a = {0xC566718C, 0x66DE7644, 0xC2A2017C, 0xD502C1FC, 0x8585AE73};
		static const bigint_t var_b = {0x6B1DB471, 0x72F1534C, 0xD54C0817, 0xC899F50F, 0x0EB774EC};
		const word_t var_expected[10] = {0x8AEA8ECC, 0x05ACD6C7, 0xBEFE32E0, 0x0EC80B35, 0x7ACB2B65, 0x9890B31A, 0xCD8AD21E, 0x1073C6FF, 0x1D5D77E3, 0x07ACFF16};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 201 ");
	}
	{
		static const bigint_t var_a = {0x4207C463, 0x7D892E56, 0xE1826400, 0x488CC25E, 0xC20A5268};
		static const bigint_t var_b = {0xEAD505CE, 0x191855B4, 0x57F36566, 0xF47CDE05, 0x1A19F045};
		const word_t var_expected[10] = {0x2D74F6AA, 0x2E5DF748, 0xADF4CC44, 0xCDFE3787, 0x3C6913F3, 0xC3A5CAC6, 0x062F52A0, 0x7251F1EE, 0x56E7D770, 0x13C8B57F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 202 ");
	}
	{
		static const bigint_t var_a = {0xDCDA48C3, 0xE63F69E8, 0x31E86AF9, 0x2919577F, 0xD3B70AA1};
		static const bigint_t var_b = {0xC819330E, 0xD7D0A05F, 0x4C23AF40, 0x99489642, 0x2E974FDF};
		const word_t var_expected[10] = {0x0379D3AA, 0xC3C42942, 0xADAFC321, 0x28297830, 0x5796F813, 0xDC521AB7, 0x5263C49D, 0x795865AE, 0xA1F036D6, 0x268806EE};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 203 ");
	}
	{
		static const bigint_t var_a = {0xA726E24B, 0xE80DDF51, 0x6ECB7A27, 0x2E947252, 0xE1E14591};
		static const bigint_t var_b = {0x27E8ED1A, 0x715B1DBF, 0xB3736E34, 0xDB890FE0, 0x752F9C80};
		const word_t var_expected[10] = {0x7A6A6A9E, 0xE4EC02B5, 0x4C8D6746, 0x6183BA40, 0x47E3CA73, 0x6A971D2E, 0x0B80A124, 0x4DBA6400, 0x18AD4C8E, 0x6765F73E};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 204 ");
	}
	{
		static const bigint_t var_a = {0x0272ED2E, 0xECE42781, 0xBDC79B4B, 0x62B7150A, 0xE2D6098C};
		static const bigint_t var_b = {0xDB465B41, 0xE7D76638, 0xCD315F95, 0x5764C593, 0x69B468AD};
		const word_t var_expected[10] = {0xAE1192AE, 0x719E1603, 0x2D374B2C, 0x9BE6D136, 0x324FDF7B, 0xE3869D4A, 0x9E02674F, 0x661E54F4, 0xD7280441, 0x5DA9A529};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 205 ");
	}
	{
		static const bigint_t var_a = {0xD8EA42FC, 0x0C0F6FC2, 0x229EEA9F, 0x3F4A6729, 0xE99AD358};
		static const bigint_t var_b = {0x7F7E67EB, 0x4D87F924, 0x774B8782, 0x1B56424C, 0x60BFBB01};
		const word_t var_expected[10] = {0x5C06E154, 0x6EA27F1B, 0xCE86F3EE, 0xAC71A011, 0xBB1E3437, 0x3A5D5949, 0x5D7123A1, 0xFCF35EA5, 0xE1817392, 0x58490469};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 206 ");
	}
	{
		static const bigint_t var_a = {0x94B031DF, 0xE27B3B7E, 0x9142F182, 0xE2EC056F, 0x452B10AA};
		static const bigint_t var_b = {0xD50DA421, 0x2C917D1A, 0xC2C57EC1, 0x9D5A445A, 0xBF4863B5};
		const word_t var_expected[10] = {0x1DFC49BF, 0x30B1DCA9, 0x973CB8AB, 0xC3150314, 0x2694DED9, 0x0CB06F10, 0xB06C8CF4, 0x1B2B8FC1, 0xE8C695D8, 0x33AEB07C};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 207 ");
	}
	{
		static const bigint_t var_a = {0xA487287D, 0x1F5F2772, 0x5A18DF4E, 0x9A435E93, 0xF1FA6174};
		static const bigint_t var_b = {0x93489746, 0xBC05F126, 0xF43881FF, 0xC7C48DA1, 0xA0A5027B};
		const word_t var_expected[10] = {0xDFFECD2E, 0xE09FFA35, 0x28342C11, 0xD46BC47C, 0xF7C00C10, 0x6624CDD6, 0xA9BDD2D9, 0xF0914107, 0xA574B016, 0x97D875A2};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 208 ");
	}
	{
		static const bigint_t var_a = {0xBE2A8E91, 0xB711F559, 0xBF3478C5, 0x6784B30B, 0xEA5A4ED4};
		static const bigint_t var_b = {0x4B4C8715, 0xB57C0040, 0x1D8750FC, 0x892D4749, 0xF07C5A04};
		const word_t var_expected[10] = {0xD8B828E5, 0xBC16044B, 0x4BA4F88D, 0x37831E0F, 0x5A8B1114, 0x997C5656, 0x90F7DFCD, 0x83587028, 0x36A23B29, 0xDC26800D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 209 ");
	}
	{
		static const bigint_t var_a = {0x45DC44A9, 0xA0004ED1, 0xEB5971A1, 0x28A87AE3, 0x609A069D};
		static const bigint_t var_b = {0x17FE2B6D, 0x8CB1E892, 0xE340BA08, 0x9E23002C, 0x4B4A3816};
		const word_t var_expected[10] = {0x0CFF9EF5, 0x88FA20F0, 0x356D9BDD, 0x72675251, 0x373E2274, 0x6374A7BB, 0x97904804, 0x7C0055AD, 0x2EB2544F, 0x1C6921A0};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 210 ");
	}
	{
		static const bigint_t var_a = {0x80D1200A, 0x74C00A27, 0xAF310FDA, 0x7D633080, 0xDEAD27A9};
		static const bigint_t var_b = {0x26AEFD5A, 0x58A98798, 0x2EFC9361, 0x5E32AD9B, 0x2BCB7611};
		const word_t var_expected[10] = {0x38FB2584, 0xF42F8107, 0x61F1FF75, 0x7AF75B3A, 0xEFFAFBAC, 0xEF4DF4F9, 0xC993BB7A, 0x1A11F92C, 0xD72D823E, 0x26180FAA};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 211 ");
	}
	{
		static const bigint_t var_a = {0x82E22568, 0x84ABB9FC, 0xA6EEFA33, 0xB39F49C9, 0xD969397D};
		static const bigint_t var_b = {0x67DA93A2, 0xAD9344B8, 0xDDD247E9, 0xD028F05C, 0x1A4B6D6E};
		const word_t var_expected[10] = {0x612663D0, 0x715AA553, 0x5FF09AE6, 0x601D6280, 0x78BCC495, 0x092D017D, 0x95A6CBA6, 0xBB932894, 0x858B49EF, 0x1654BE9A};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 212 ");
	}
	{
		static const bigint_t var_a = {0xF1640E05, 0x0DD070CF, 0xBA339C75, 0x310258B4, 0x51A46E89};
		static const bigint_t var_b = {0xDBE78DB5, 0x3687B739, 0xB3638FE1, 0x6697EF8C, 0x09BEC45F};
		const word_t var_expected[10] = {0xB4F9AA89, 0xF995665D, 0xCA7026EE, 0x6D08253C, 0x07C70F2E, 0xF8865568, 0x852B3C7B, 0x6B3E65B4, 0x2DE97BB8, 0x031B9E8D};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 213 ");
	}
	{
		static const bigint_t var_a = {0x138D1160, 0xB2F65D20, 0x1AC57135, 0x3B39C7B0, 0x5D328B3B};
		static const bigint_t var_b = {0x5D9A6F34, 0xD3C33884, 0x0E969774, 0xFD115B0A, 0xFF039790};
		const word_t var_expected[10] = {0x76F02780, 0x257BCAAA, 0xB2E121A1, 0x567356F4, 0xE5DCA775, 0x83E3D4AC, 0xA72FC72F, 0x90424CD9, 0x3A5FC5EF, 0x5CD6A775};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 214 ");
	}
	{
		static const bigint_t var_a = {0xC3EF7BCE, 0x753D9E6B, 0x1763F8F7, 0x08CF63A3, 0xDC81D7EB};
		static const bigint_t var_b = {0xDD24C6D4, 0x801758A2, 0x31192DFE, 0x1A35C88E, 0xBA1F17AE};
		const word_t var_expected[10] = {0xBB0BDA98, 0x7E78FEB3, 0xD6F3F063, 0x5ADAE97E, 0x639470D6, 0x6FB3ABFB, 0x093D3B0E, 0xAC35A8E2, 0x8B17229B, 0xA0511EFF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 215 ");
	}
	{
		static const bigint_t var_a = {0x4419A012, 0xB2B9483D, 0x99165CC8, 0x8540FD83, 0xABD485A0};
		static const bigint_t var_b = {0x61F016E1, 0x5BB084F0, 0x26B274AA, 0x7F88E01E, 0xF7A9CD49};
		const word_t var_expected[10] = {0xF1273BD2, 0x723AA83F, 0xD6D83FD9, 0xBFB5B789, 0xCD61DCEB, 0x19C8DDD5, 0x49850148, 0x304EC903, 0x9BBF9F9C, 0xA63C0604};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 216 ");
	}
	{
		static const bigint_t var_a = {0x0770A19E, 0xF5DBDB77, 0xF7773D9D, 0x3093472C, 0x02B2175E};
		static const bigint_t var_b = {0x4F3EE559, 0x79DDE2E1, 0x82F70A79, 0x856EF0E0, 0x7DED487B};
		const word_t var_expected[10] = {0x3CFE85EE, 0x32F1DD0E, 0x59F24D4D, 0xFCF7C2D8, 0x13AF6B1E, 0xA0993F22, 0xBE4E9B2C, 0xE91157B4, 0x03764B37, 0x0153750C};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 217 ");
	}
	{
		static const bigint_t var_a = {0xDD172984, 0xA27A1B68, 0x7DE45D98, 0xF5B50DAD, 0xEB4BCE0C};
		static const bigint_t var_b = {0xC2A20299, 0x70512D1B, 0x90A8D53E, 0xE92E542D, 0x21ECE550};
		const word_t var_expected[10] = {0x9EB2D7E4, 0x259A3E70, 0x624FC6EB, 0x30646781, 0x451EAF1D, 0x029C17E3, 0x838FA8D8, 0x49D630F3, 0xCCF3690B, 0x1F2E8236};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 218 ");
	}
	{
		static const bigint_t var_a = {0x33118676, 0xBF840150, 0xEC7B4DB0, 0xF62AE7FA, 0xF629C403};
		static const bigint_t var_b = {0xFE8D1BFA, 0xBC343AEF, 0xAF6D22B9, 0xE5241906, 0x56A33112};
		const word_t var_expected[10] = {0xDB49C13C, 0xDCAF85EE, 0x1E1272D5, 0xA33B040B, 0x4E052ABE, 0xFB786C9C, 0x6D0E4AE5, 0x2332CE5D, 0x4D02C3ED, 0x534EF3A1};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 219 ");
	}
	{
		static const bigint_t var_a = {0x42B1C062, 0x6AFC91CB, 0xACEE1815, 0x9DDC8656, 0x8CB7355D};
		static const bigint_t var_b = {0x45C84473, 0x6E0BC84B, 0xE6118150, 0xCFFBC730, 0x0F4FAF74};
		const word_t var_expected[10] = {0xE3837406, 0x9E8B6C74, 0x04356C3C, 0x444EEBE1, 0xBF0A621E, 0xBEEC1F4B, 0xCF7EAAF5, 0x215E88AC, 0x66F55987, 0x086A891B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 220 ");
	}
	{
		static const bigint_t var_a = {0x619B092A, 0xBE085D3F, 0x8FEEFE13, 0x77264547, 0x9C2B60E4};
		static const bigint_t var_b = {0x8F71611F, 0xBFF0438F, 0xFF394CA9, 0x9402A2C9, 0xFBB350D4};
		const word_t var_expected[10] = {0x11C90616, 0xC5381AAC, 0x8CD12C08, 0x498E563D, 0x975C9CAF, 0xECD83E44, 0x2724FFEE, 0xC03D9289, 0xFD1027C7, 0x998BEBA3};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 221 ");
	}
	{
		static const bigint_t var_a = {0xD7E84F09, 0x304161AA, 0x594753EA, 0x9612FF87, 0x6BF0DF2B};
		static const bigint_t var_b = {0xFBD61F99, 0x8644493A, 0xA4D3B5A2, 0xC8C5A159, 0x5DB60492};
		const word_t var_expected[10] = {0x0FEF5361, 0xC5F7C9FA, 0x7D3C2044, 0x777B04E9, 0xFA3DDE3C, 0xD829DB55, 0xF61EBDA5, 0xCADD21A6, 0x26051047, 0x2783403F};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 222 ");
	}
	{
		static const bigint_t var_a = {0xDAFB35EA, 0xB0D8AA4C, 0x62918C94, 0x9A268CFC, 0xD10D7175};
		static const bigint_t var_b = {0xF4D1ABBC, 0x9869AC98, 0x50FF92B9, 0x26A1DF2B, 0x1041DBB0};
		const word_t var_expected[10] = {0xA988E5D8, 0xBCAFD820, 0x80B8966F, 0x245A4AE6, 0xC8CEA94E, 0xCAE0AAAD, 0xDCFA5B02, 0x6C6F0872, 0x815856DC, 0x0D469EE7};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 223 ");
	}
	{
		static const bigint_t var_a = {0xA6E38365, 0x0E95E828, 0x0DE8572F, 0x8FE76A98, 0x356D43D3};
		static const bigint_t var_b = {0x577989AA, 0xA3F14E7F, 0x1CA2D537, 0xB1A40183, 0x80D054CB};
		const word_t var_expected[10] = {0x02234E12, 0x92B4149A, 0x78E5B65D, 0xB4B74936, 0xB9812DA8, 0x180EA0FD, 0x2CF9F9AF, 0x32298C57, 0x40D19B83, 0x1AE21C63};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 224 ");
	}
	{
		static const bigint_t var_a = {0xD20AAF48, 0x7697485F, 0xF35E013A, 0x3E0A8B06, 0xEFED12B8};
		static const bigint_t var_b = {0x2543853F, 0x005A66C2, 0xA6284C4E, 0xD44E2D22, 0x9467B14F};
		const word_t var_expected[10] = {0x85898AB8, 0x9F83A065, 0x55EC3A0C, 0xBE04341C, 0x17874D92, 0x9A9F7B99, 0x7A93511C, 0xD0E2F95B, 0xC712D067, 0x8B163D62};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 225 ");
	}
	{
		static const bigint_t var_a = {0x44762567, 0x0275104A, 0xE6EB8795, 0xA425A8B4, 0x0E7AC730};
		static const bigint_t var_b = {0x805D3663, 0x8C9EC8D5, 0xAAE2D6F1, 0x340CB6CE, 0xE0589420};
		const word_t var_expected[10] = {0x7BFF30D5, 0x5F027F7B, 0x8ADE0A6E, 0x19DE733F, 0x0C8638D8, 0x113C6C71, 0xFAD1A037, 0xC42DB667, 0xD5CC0E18, 0x0CB070DF};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 226 ");
	}
	{
		static const bigint_t var_a = {0x75F2B5BF, 0xAA0A5E45, 0x42719621, 0xB03F2649, 0x8C6EB514};
		static const bigint_t var_b = {0x0C9004A9, 0x9532CF7F, 0x03CF867F, 0x1977D8F3, 0x9BB40E79};
		const word_t var_expected[10] = {0xD780F717, 0x2196A57E, 0xFFCE24E7, 0xBC74144C, 0x4D5EF7DB, 0x304B89DE, 0xB0A7FE83, 0xF2792AE2, 0x55756F27, 0x5569CD6B};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 227 ");
	}
	{
		static const bigint_t var_a = {0xF07D232C, 0x2666898F, 0x1F535A6D, 0x72C094C9, 0x72076B64};
		static const bigint_t var_b = {0xE472F0FF, 0x4BB5EBEC, 0x29423DB1, 0x89C375DA, 0x2864ECE0};
		const word_t var_expected[10] = {0xB73748D4, 0x2A245372, 0xFDE2448F, 0x5B803437, 0x9B9962B5, 0xE6A15BB9, 0xD79BACFD, 0x9CD46170, 0x800684C5, 0x11FE1D30};
		bi_multiply(var_res, var_a, var_b);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_multiply 228 ");
	}
	{
		static const bigint_t var_a = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 229 ");
	}
	{
		static const bigint_t var_a = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		const word_t var_expected[10] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 230 ");
	}
	{
		static const bigint_t var_a = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		const word_t var_expected[10] = {0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 231 ");
	}
	{
		static const bigint_t var_a = {0x23DBD81A, 0x731DE1D0, 0x65DB99D6, 0x60CE9EB6, 0x82E79618};
		const word_t var_expected[10] = {0x8EE7E2A4, 0x0E06B822, 0xECE78BB1, 0x9D3C5ED6, 0xA0AC2786, 0xFE686382, 0x7BB888DD, 0x19F5F9EA, 0xFA5121D8, 0x42F005F0};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 232 ");
	}
	{
		static const bigint_t var_a = {0xC1C6FFBE, 0x64C6F65C, 0x7695CC8B, 0x9AF26870, 0x3D96CB43};
		const word_t var_expected[10] = {0x15641104, 0x571EA0DD, 0xECD225FA, 0x541E9452, 0xBBC71737, 0x50E48F96, 0xB4170C6B, 0xE69BED26, 0x0C75636E, 0x0ED135B1};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 233 ");
	}
	{
		static const bigint_t var_a = {0xFDC87711, 0x2111A774, 0xD173D362, 0x67DEF8D3, 0x5B9467F8};
		const word_t var_expected[10] = {0xDBF0CF21, 0xB6DBEDB9, 0x51886AE8, 0xD7F328D9, 0xE33DFE66, 0x014F0213, 0x2540DC42, 0x22344194, 0xFB4A7355, 0x20C2D7F2};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 234 ");
	}
	{
		static const bigint_t var_a = {0x0F4AB16C, 0xCE08D4E6, 0xA693C670, 0x7C1E5714, 0xDD2A2B79};
		const word_t var_expected[10] = {0xB5668590, 0x17BB84A5, 0xFDE150C8, 0xD07DEEA4, 0xFD0A567A, 0x7C270616, 0x84EF9417, 0xFC7E768B, 0x0B8B25A6, 0xBF11D602};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 235 ");
	}
	{
		static const bigint_t var_a = {0xF8C04E20, 0x96E955B5, 0x69BABA5E, 0xD4ECA13F, 0x35AB87F8};
		const word_t var_expected[10] = {0x47D78400, 0x1BC4E113, 0x46B261A5, 0x6B438F80, 0x86D19E05, 0xB2EC0BCE, 0xA8CC1B4A, 0x7A20A2CA, 0xF6CED152, 0x0B40793B};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 236 ");
	}
	{
		static const bigint_t var_a = {0xF81875E4, 0xA674A460, 0x76AFB0B0, 0x4BC222DE, 0xCEDCFB00};
		const word_t var_expected[10] = {0x110A3310, 0xE073F1C0, 0x44A08B28, 0xDF399A59, 0x0E44C602, 0x58385D6D, 0xB772E417, 0xBC2A4EB7, 0xD8883A58, 0xA72862B4};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 237 ");
	}
	{
		static const bigint_t var_a = {0x73924F6D, 0xDE359238, 0xF87B0C34, 0x5E70CF77, 0xA5F770C2};
		const word_t var_expected[10] = {0x9EF87469, 0x95E9DAAA, 0xF4F688E3, 0x885C4C65, 0xBE09E177, 0x09CFE2F4, 0x4539A11E, 0xFB2A9080, 0x567A4F56, 0x6B98E685};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 238 ");
	}
	{
		static const bigint_t var_a = {0xBA8A86AF, 0xCDE64537, 0x54CB1BCB, 0xB01BBF57, 0x2F064649};
		const word_t var_expected[10] = {0xC787ABA1, 0xA481CBDD, 0x3540A6D8, 0xA43D8EBD, 0x5644D2BF, 0xFA008AA4, 0x92381A6C, 0x1ED79A01, 0x6D6AD314, 0x08A34DF6};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 239 ");
	}
	{
		static const bigint_t var_a = {0x90966AEB, 0xCEFA3B00, 0x7C01C018, 0xDD361AEF, 0x1045B688};
		const word_t var_expected[10] = {0xD80B73B9, 0xADEDE2A9, 0x6DD04890, 0x308DCC13, 0xC475FA27, 0x9853028A, 0xC237168C, 0x2B88A9AB, 0x0394E63D, 0x0108C9CD};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 240 ");
	}
	{
		static const bigint_t var_a = {0xB824B1C1, 0xCA3393DD, 0x71857D54, 0xCFF91A6C, 0x50A0E034};
		const word_t var_expected[10] = {0xE9B47381, 0xFED95201, 0xE88EC94C, 0xCB69E8F7, 0x73DADD67, 0xD654099D, 0x2B31348B, 0xE2E6A309, 0x085C1EBD, 0x1964F13A};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 241 ");
	}
	{
		static const bigint_t var_a = {0xF1D4C53D, 0x7C4BBE68, 0xB9A8F69E, 0x6C0B514A, 0xAF0C44FF};
		const word_t var_expected[10] = {0x1EFEF089, 0xDFD719C4, 0x41287707, 0xB21DBEC7, 0x12F7B98B, 0xE367C08F, 0x914D9B18, 0x382B9B9A, 0xC0424A72, 0x77B1C6EB};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 242 ");
	}
	{
		static const bigint_t var_a = {0x27B4E658, 0xEB34009E, 0xBF29ECBC, 0x224C8A44, 0x0C935792};
		const word_t var_expected[10] = {0x8B023E40, 0x2D34F2A3, 0x8FBB3358, 0xA436EB9B, 0x031CD072, 0x37FD41D6, 0xC8044177, 0x66C0544C, 0x62FF3798, 0x009E2503};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 243 ");
	}
	{
		static const bigint_t var_a = {0x0819C002, 0x5D407E1C, 0x49C5FC92, 0x09D8F57B, 0x51D5005B};
		const word_t var_expected[10] = {0x30670004, 0x93E59707, 0x407D4FB4, 0xC53470DA, 0x8A7F9B44, 0x541EB248, 0x33F52D9F, 0x84778C13, 0x33B9CEC0, 0x1A287B73};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 244 ");
	}
	{
		static const bigint_t var_a = {0x4E79FC51, 0xB42141E2, 0x9FABB91C, 0x21DD1A09, 0x261EC206};
		const word_t var_expected[10] = {0xD94191A1, 0x8E7330E5, 0x773ABDE5, 0xEABCD7FB, 0xBDC29725, 0xFB03E131, 0x1B3E2EB7, 0xABF6F554, 0xDE8ADF05, 0x05AD254B};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 245 ");
	}
	{
		static const bigint_t var_a = {0xD6F84610, 0x85E0B573, 0xE2165D3C, 0xF5F8D0A0, 0x4487EB33};
		const word_t var_expected[10] = {0x922CC100, 0x26A5984A, 0xDABBA52D, 0x89D75CA5, 0xAAD0DA36, 0x07B17A5C, 0x73858597, 0x3E4B0576, 0x83920B64, 0x12587D1D};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 246 ");
	}
	{
		static const bigint_t var_a = {0xAC9B103A, 0x205D2A2C, 0x44EB22F1, 0xF0A73CA9, 0x7B2FB54B};
		const word_t var_expected[10] = {0x97434D24, 0xF52557AA, 0x9D4ED25A, 0x5C6E944B, 0x8E73EFC6, 0x1B28197A, 0xFF436E4F, 0x4E60278A, 0x0B878A86, 0x3B46E11B};
		bi_square(var_res, var_a);
		assert_bi_equal_var(var_expected, var_res, 2*BI_WORDS, "bi_square 247 ");
	}
	{
		static const bigint_t var_a = {0x48F9C739, 0xE26033EC, 0xA40A86CF, 0x593EC358, 0x07EEC639};
		static const bigint_t var_expected = {0x48F9C739, 0xE26033EC, 0xA40A86CF, 0x593EC358, 0x07EEC639};
		bi_shift_right(var_res, var_a, 0);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 248 ");
	}
	{
		static const bigint_t var_a = {0x816CD0D9, 0x457DD6D3, 0x1D1F79F7, 0x717511A3, 0x0B6398D3};
		static const bigint_t var_expected = {0xC0B6686C, 0xA2BEEB69, 0x8E8FBCFB, 0xB8BA88D1, 0x05B1CC69};
		bi_shift_right(var_res, var_a, 1);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 249 ");
	}
	{
		static const bigint_t var_a = {0xA0A1A2DB, 0x630FAB6E, 0xB25083BE, 0x02B13C20, 0xB872BB1D};
		static const bigint_t var_expected = {0xAB6EA0A1, 0x83BE630F, 0x3C20B250, 0xBB1D02B1, 0x0000B872};
		bi_shift_right(var_res, var_a, 16);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 250 ");
	}
	{
		static const bigint_t var_a = {0x8D5D98EB, 0x560DEB23, 0xC10FA66A, 0x5BB4D4FB, 0x27463B0B};
		static const bigint_t var_expected = {0x560DEB23, 0xC10FA66A, 0x5BB4D4FB, 0x27463B0B, 0x00000000};
		bi_shift_right(var_res, var_a, 32);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 251 ");
	}
	{
		static const bigint_t var_a = {0x803E4863, 0x6D64C8F5, 0x675C833A, 0x342968C4, 0x5995BAED};
		static const bigint_t var_expected = {0x675C833A, 0x342968C4, 0x5995BAED, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 64);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 252 ");
	}
	{
		static const bigint_t var_a = {0x0694FD75, 0x1B2D534E, 0x37FDBF77, 0x51213D29, 0x42D5AF36};
		static const bigint_t var_expected = {0x00085AB5, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 139);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 253 ");
	}
	{
		static const bigint_t var_a = {0x391C08E9, 0x939E2149, 0x109B07AA, 0xDAFCDDFE, 0xD7322210};
		static const bigint_t var_expected = {0x549CF10A, 0xF084D83D, 0x86D7E6EF, 0x06B99110, 0x00000000};
		bi_shift_right(var_res, var_a, 37);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 254 ");
	}
	{
		static const bigint_t var_a = {0x9B288D64, 0x0851F67E, 0x0FB4A02B, 0x510E5A8F, 0x890E7F77};
		static const bigint_t var_expected = {0x0158428F, 0xD4787DA5, 0xFBBA8872, 0x00044873, 0x00000000};
		bi_shift_right(var_res, var_a, 45);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 255 ");
	}
	{
		static const bigint_t var_a = {0x0529E099, 0x10E4C3E0, 0x0FF3F037, 0xF005C128, 0xD1E88F30};
		static const bigint_t var_expected = {0xF30F005C, 0x000D1E88, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 108);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 256 ");
	}
	{
		static const bigint_t var_a = {0x0D88BACA, 0xC55286C1, 0xC0EFC966, 0xFA8886C5, 0x37770C76};
		static const bigint_t var_expected = {0x00006EEE, 0x00000000, 0x00000000, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 143);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 257 ");
	}
	{
		static const bigint_t var_a = {0xCAE8AF22, 0xD5B50870, 0x9C8AB4E0, 0x933213E1, 0x6C15C9D3};
		static const bigint_t var_expected = {0xB6A10E19, 0x91569C1A, 0x66427C33, 0x82B93A72, 0x0000000D};
		bi_shift_right(var_res, var_a, 27);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 258 ");
	}
	{
		static const bigint_t var_a = {0x66D96005, 0xED03DD90, 0x3A54E422, 0xDB4465F3, 0x9EE0E161};
		static const bigint_t var_expected = {0x8CBE674A, 0x1C2C3B68, 0x000013DC, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 83);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 259 ");
	}
	{
		static const bigint_t var_a = {0x2C3C6D24, 0xFA65CD14, 0x004DB332, 0x2AD09DBD, 0x3A93F3F1};
		static const bigint_t var_expected = {0xCCBE9973, 0x6F40136C, 0xFC4AB427, 0x000EA4FC, 0x00000000};
		bi_shift_right(var_res, var_a, 42);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 260 ");
	}
	{
		static const bigint_t var_a = {0x145BB6B0, 0x34C85510, 0x5BA2BE8E, 0x7BA7DEF6, 0x954577CB};
		static const bigint_t var_expected = {0x1A642A88, 0x2DD15F47, 0xBDD3EF7B, 0x4AA2BBE5, 0x00000000};
		bi_shift_right(var_res, var_a, 33);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 261 ");
	}
	{
		static const bigint_t var_a = {0x00BAD3AF, 0xF6C9A4C0, 0x0FA55C0C, 0x6A80BA44, 0x3FD4D3B9};
		static const bigint_t var_expected = {0xBA440FA5, 0xD3B96A80, 0x00003FD4, 0x00000000, 0x00000000};
		bi_shift_right(var_res, var_a, 80);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 262 ");
	}
	{
		static const bigint_t var_a = {0x1ADAC108, 0xC2DDE1F5, 0x3818A1FE, 0x526A6FC5, 0xE26612E5};
		static const bigint_t var_expected = {0xA8D6D608, 0xF616EF0F, 0x29C0C50F, 0x2A93537E, 0x07133097};
		bi_shift_right(var_res, var_a, 5);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 263 ");
	}
	{
		static const bigint_t var_a = {0x1D4DEF27, 0x16A00188, 0x13BBC48A, 0x6D2B5633, 0xFD7A2258};
		static const bigint_t var_expected = {0x003103A9, 0x789142D4, 0x6AC66277, 0x444B0DA5, 0x00001FAF};
		bi_shift_right(var_res, var_a, 19);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 264 ");
	}
	{
		static const bigint_t var_a = {0x75414A82, 0xCDF6D4C6, 0xAB9F205B, 0x055CF27E, 0xE27B4B74};
		static const bigint_t var_expected = {0x2DE6FB6A, 0x3F55CF90, 0xBA02AE79, 0x00713DA5, 0x00000000};
		bi_shift_right(var_res, var_a, 41);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 265 ");
	}
	{
		static const bigint_t var_a = {0x68287A63, 0x41BCE88E, 0xF90E56F2, 0x1117585E, 0xBA65E8C5};
		static const bigint_t var_expected = {0x9D11CD05, 0xCADE4837, 0xEB0BDF21, 0xBD18A222, 0x0000174C};
		bi_shift_right(var_res, var_a, 19);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 266 ");
	}
	{
		static const bigint_t var_a = {0xD1CDD8B4, 0x7660FD71, 0x1E77FCBB, 0xE11C5F58, 0x7BC39E21};
		static const bigint_t var_expected = {0x60FD71D1, 0x77FCBB76, 0x1C5F581E, 0xC39E21E1, 0x0000007B};
		bi_shift_right(var_res, var_a, 24);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 267 ");
	}
	{
		static const bigint_t var_a = {0x1B3DC268, 0xEA578404, 0xBABAB3DF, 0x941F78D6, 0x1598EA29};
		static const bigint_t var_expected = {0x57567BFD, 0x83EF1AD7, 0xB31D4532, 0x00000002, 0x00000000};
		bi_shift_right(var_res, var_a, 59);
		assert_bi_equal(var_expected, var_res, "bi_shiftRight 268 ");
	}
	{
		static const bigint_t var_a = {0x6EB1C0DC, 0xE532F60D, 0x964051B2, 0x9AF290DE, 0x4401A94C};
		static const bigint_t var_expected = {0xB758E06E, 0x72997B06, 0x4B2028D9, 0x4D79486F, 0x2200D4A6};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 269 ");
	}
	{
		static const bigint_t var_a = {0x5621739A, 0x0DE99FA0, 0x6E4D5E54, 0xC9AEB3E2, 0x70DBDFC5};
		static const bigint_t var_expected = {0x2B10B9CD, 0x06F4CFD0, 0x3726AF2A, 0xE4D759F1, 0x386DEFE2};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 270 ");
	}
	{
		static const bigint_t var_a = {0x03A338E3, 0x440F7EBB, 0xF3320FD3, 0x1BB12706, 0x559F5255};
		static const bigint_t var_expected = {0x81D19C71, 0xA207BF5D, 0x799907E9, 0x8DD89383, 0x2ACFA92A};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 271 ");
	}
	{
		static const bigint_t var_a = {0x6E44917C, 0xC0C91815, 0xD3D7C87A, 0x4D34656F, 0xA74619B4};
		static const bigint_t var_expected = {0xB72248BE, 0x60648C0A, 0xE9EBE43D, 0x269A32B7, 0x53A30CDA};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 272 ");
	}
	{
		static const bigint_t var_a = {0x060AE0B5, 0x649D9805, 0xE884B1F5, 0x10E66A0C, 0x4C4C240E};
		static const bigint_t var_expected = {0x8305705A, 0xB24ECC02, 0x744258FA, 0x08733506, 0x26261207};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 273 ");
	}
	{
		static const bigint_t var_a = {0xCFE3805B, 0x9F9C6920, 0x48EB49CC, 0xC7E9043C, 0x93E79806};
		static const bigint_t var_expected = {0x67F1C02D, 0x4FCE3490, 0x2475A4E6, 0x63F4821E, 0x49F3CC03};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 274 ");
	}
	{
		static const bigint_t var_a = {0x5FCA638C, 0xAAF4FFAB, 0xA3A190D2, 0x18488008, 0x5B1874C4};
		static const bigint_t var_expected = {0xAFE531C6, 0x557A7FD5, 0x51D0C869, 0x0C244004, 0x2D8C3A62};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 275 ");
	}
	{
		static const bigint_t var_a = {0x2D9B4055, 0x844EECE9, 0x4F74A2BA, 0xB6F5B731, 0xC7CA15FA};
		static const bigint_t var_expected = {0x96CDA02A, 0x42277674, 0xA7BA515D, 0x5B7ADB98, 0x63E50AFD};
		bi_shift_right_one(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_shiftRightOne 276 ");
	}
	{
		static const bigint_t var_a = {0x7EA531C1, 0xBC734A8C, 0x045D6608, 0xCB1C49A4, 0x4E41FCCC};
		static const bigint_t var_expected = {0x7F8C65EB, 0x3ED118D9, 0x01747758, 0x43B4188C, 0x6F6B5444};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 277 ");
	}
	{
		static const bigint_t var_a = {0x5271B8A1, 0x4D5C0353, 0x7BB9C18F, 0xEA7EFA81, 0x23B406E6};
		static const bigint_t var_expected = {0x1B7B3D8B, 0x19C95671, 0x7E934085, 0x4E2A5380, 0xB69157A2};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 278 ");
	}
	{
		static const bigint_t var_a = {0xB71E0952, 0xF02E1C0A, 0xAC2D2BAA, 0x1C78E320, 0x838C3718};
		static const bigint_t var_expected = {0xE7B4ADC6, 0xFABA0958, 0x8EB9B938, 0xB4284BB5, 0x2BD967B2};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 279 ");
	}
	{
		static const bigint_t var_a = {0x2A6B4D04, 0x9BB8C58A, 0x0C5577AD, 0xA30292EB, 0x99D044BB};
		static const bigint_t var_expected = {0x637919AC, 0xDE92EC83, 0x041C7D39, 0x365630F9, 0xDDF016E9};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 280 ");
	}
	{
		static const bigint_t var_a = {0x3F416419, 0xAA629675, 0xC60613C3, 0x38AF096E, 0xC2DDB8E5};
		static const bigint_t var_expected = {0xBFC076B3, 0x8E20DCD1, 0x42020696, 0x683A587A, 0x9649E84C};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 281 ");
	}
	{
		static const bigint_t var_a = {0x5C34BA60, 0xDD19E3E3, 0xB0F6903C, 0x5C09454F, 0x2C431718};
		static const bigint_t var_expected = {0x1EBC3E20, 0xF45DF6A1, 0x3AFCDABE, 0x1EADC1C5, 0x64165D08};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 282 ");
	}
	{
		static const bigint_t var_a = {0x6389ABBD, 0x193CC925, 0xAD93BEE8, 0x60E79ADC, 0xC8CF302C};
		static const bigint_t var_expected = {0x7683393F, 0xB314430C, 0x8F313FA2, 0xCAF7DE49, 0x9845100E};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 283 ");
	}
	{
		static const bigint_t var_a = {0xBABAD3C8, 0xA8E1097C, 0xB09C1841, 0x6E9780CB, 0x15171722};
		static const bigint_t var_expected = {0x3E3E4698, 0xE2F5ADD4, 0x90340815, 0x24DD2AEE, 0x5C5D07B6};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 284 ");
	}
	{
		static const bigint_t var_a = {0xDC5BC51D, 0xDE4B025D, 0x5508778B, 0x05315DAC, 0xB2CD016A};
		static const bigint_t var_expected = {0x4973EC5F, 0x9F6E561F, 0x71AD7D2E, 0x01BB1F39, 0xE64455CE};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 285 ");
	}
	{
		static const bigint_t var_a = {0x494F9DE9, 0xBCB678AC, 0x9B193B38, 0x23060481, 0x1545D8C1};
		static const bigint_t var_expected = {0x6DC534A3, 0xE9922839, 0x89086912, 0x61020180, 0x07174840};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 286 ");
	}
	{
		static const bigint_t var_a = {0x454503D5, 0x5994F9A2, 0xFB668F5E, 0x2BFE9925, 0x68F1F2EE};
		static const bigint_t var_expected = {0x17170147, 0x1DDC5336, 0xA9222FCA, 0x0EAA330C, 0x22FB50FA};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 287 ");
	}
	{
		static const bigint_t var_a = {0x398C8F2B, 0xD8842DC3, 0x0E62326B, 0x5F5A186C, 0x45A8B6A4};
		static const bigint_t var_expected = {0x68842FB9, 0x9D816496, 0xAF7610CE, 0x1FC8B2CE, 0xC1E2E78C};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 288 ");
	}
	{
		static const bigint_t var_a = {0xDFE98995, 0xCF6070A1, 0xE3D54EA2, 0xC88AE2C6, 0x8E2E7B67};
		static const bigint_t var_expected = {0xF54DD887, 0xEFCAD035, 0x4BF1C4E0, 0x42D8F642, 0x2F64D3CD};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 289 ");
	}
	{
		static const bigint_t var_a = {0xAF2710F7, 0xBA86C962, 0xDBAE0AD8, 0x7326B4BA, 0xAE024978};
		static const bigint_t var_expected = {0x3A625AFD, 0xE8D79876, 0x9E8F58F2, 0x7BB79193, 0x8F56187D};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 290 ");
	}
	{
		static const bigint_t var_a = {0x0FE4A3C7, 0x41C0B95F, 0xB2891135, 0xACF20740, 0x1D4ED4AB};
		static const bigint_t var_expected = {0x5AA18BED, 0x6B403DCA, 0x3B8305BC, 0x8EFB57C0, 0x09C4F18E};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 291 ");
	}
	{
		static const bigint_t var_a = {0x3194CEB3, 0xE2040804, 0xD7DC15CC, 0x9390929D, 0x0C48F492};
		static const bigint_t var_expected = {0x1086EF91, 0xA0AC02AC, 0x9D495C99, 0x86858634, 0x596DA6DB};
		bi_div3(var_res, var_a);
		assert_bi_equal(var_expected, var_res, "bi_div3 292 ");
	}
#endif
	return 0;
}
