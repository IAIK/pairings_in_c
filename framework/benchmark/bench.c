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

#include "bench_util.h"
#include "types.h"
#include "fp/fp.h"
#include "fp/fp2.h"
#include "fp/fp12.h"
#include "ec/ec.h"
#include "pbc/pbc.h"
#include "bigint/bi.h"
#include "ibe/bbkem.h"

#define benchmark_call(msg, function)						\
	benchmark_start();														\
	benchmark_start();														\
	function;																      \
	benchmark_stop();														  \
	benchmark_compute_single();										\
	benchmark_print(msg);													\

#if PRECISION == 256
void benchmark_bi() {
	print("Benchmark for Bi\n");

	static const bigint_t var_a = { 0xCE6DAB5C, 0x2587CAB3, 0xA009F826,
			0xB0000145, 0xEF2FB831, 0x411B3B01, 0x26CA1422, 0xFABBC18D };
	static const bigint_t var_b = { 0x20055C46, 0x1C4826CA, 0xF70F7773,
			0xD7EFEA0D, 0x243BF18B, 0xB9F4580D, 0x5C61EC83, 0x1E138820 };
	static const bigint_t var_exp = { 0x55AED7A4, 0xBC6EAECD, 0x98E6EF94,
			0x6287AD04, 0x12293515, 0x2BF8414A, 0xF15BAEA7, 0xB4812FBD };

	word_t var_res[2*BI_WORDS];

	benchmark_call("Addition:       ", bi_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", bi_subtract(var_res, var_a, var_b));
	benchmark_call("Copy:           ", bi_copy(var_res, var_a));
	benchmark_call("Compare (equal):", bi_compare(var_a, var_a));
	benchmark_call("Compare (diff): ", bi_compare(var_a, var_b));
	benchmark_call("Clear:          ", bi_clear(var_res));
	benchmark_call("Negation:       ", bi_negate(var_res, var_a));
	benchmark_call("Multiplication: ", bi_multiply(var_res, var_a, var_b));
	benchmark_call("Square:         ", bi_square(var_res, var_a));
	benchmark_call("Shift Right 1:  ", bi_shift_right_one(var_res, var_a));
	benchmark_call("Shift Right 63: ", bi_shift_right(var_res, var_a, 63));
}

void benchmark_fp() {
	print("Benchmark for Fp\n");

	static const bigint_t var_a = { 0x52766F6A, 0xACBDC62E, 0x32D23576,
			0x600D522F, 0x19049F3B, 0xC4B0D05E, 0xC0FE0998, 0xB70E64D5 };
	static const bigint_t var_b = { 0x8FE44968, 0xDEF5AF3C, 0x3D568ABD,
			0x09372473, 0x9AF4FFC7, 0x3A822C26, 0x522D6E14, 0x2DAAB214 };
	static const bigint_t var_exp = { 0x55AED7A4, 0xBC6EAECD, 0x98E6EF94,
			0x6287AD04, 0x12293515, 0x2BF8414A, 0xF15BAEA7, 0xB4812FBD };

	bigint_t var_res;

	benchmark_call("Addition:       ", fp_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp_mul(var_res, var_a, var_b));
	benchmark_call("Multiplication (Barrett): ", fp_mul(var_res, var_a, var_b));
	benchmark_call("Multiplication (Monty): ", fp_mul_monty(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp_exp(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp_inv(var_res, var_a));
}

void benchmark_fp2() {
	print("Benchmark for Fp2\n");

	static const fp2_t var_a =  { {0xF92FF612, 0x91437C32, 0xA6010AB9, 0x63568CCC, 0x146E49A0, 0x89442241, 0xE7BD6D92, 0x8E5D3686},
{0x06F42307, 0xB919EE8D, 0x562A93A0, 0x3BD26EC2, 0x7F724A54, 0x8C24B5AD, 0x89F76175, 0x5F8DF627} } ;
	static const fp2_t var_b =  { {0x93B130DF, 0xF2D579FB, 0x4962FDC7, 0xAF18B0AD, 0xF8D3D796, 0xF9C237A8, 0x36E865FC, 0x50EE1A6F},
{0xCDF59262, 0x972C63E0, 0xAF383B22, 0x9410E4E5, 0x6A83C6BB, 0x6049C4BA, 0xD189C01D, 0x94E7BD09} } ;
	static const bigint_t var_exp = {0x8433AA26, 0x8AEE519E, 0x315B2CB4, 0xC575E060, 0xDDF14DF6, 0x1CC5133C, 0x1B7CA017, 0xBA5CCA8F};

	fp2_t var_res;

	benchmark_call("Addition:       ", fp2_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp2_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp2_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp2_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp2_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp2_mul(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp2_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp2_exp(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp2_inv(var_res, var_a));
}

void benchmark_g1() {
	static ecpoint_fp var_a = {{0x920C375C, 0xA2AEB97B, 0xAA9CE5E2, 0xCD92F393,
							   0x6CA2951A, 0x9AE8C0B3, 0x93ACFC1D, 0x12C359CE},
			                   {0x91E36C9D, 0x28E16D84, 0x3367F638, 0xE4FF5005,
			                    0x3560D8DB, 0x5C4F4496, 0xBE01C0D2, 0x15B1255F}, 0};
	static const ecpoint_fp var_b = { { 0xE800E66D, 0x436B43C8, 0x09D61556,
			0x4391CCBE, 0x2013C6D6, 0x486C33DD, 0xC26C7026, 0x28B07195 }, {
			0x2AAAEED2, 0x473D10A0, 0x7C840A6A, 0x5069D71E, 0x715AF055,
			0x9DF87E97, 0x9289090E, 0x888A2294 }, 0 };
	static const bigint_t var_k = {0xE4F1B68E, 0x9C1ED28A, 0x5BCA32C0, 0xBEA93771,
			0x9D27E570, 0xCA990488, 0xC124E9D2, 0x196798D0};

	print("Benchmark for G1 ( E(Fp) )\n");
	ecpoint_fp var_res;

	benchmark_call("Addition:       ",
			ecfp_add_affine(&var_res, (const ecfp_pt) &var_a, (const ecfp_pt) &var_b));
	benchmark_call("Double:         ", ecfp_dbl_affine(&var_res, (const ecfp_pt) &var_a));
	benchmark_call("Multiplication: ", ecfp_mul(&var_res, (const ecfp_pt) &var_a, var_k));
	benchmark_call("Hash to point:  ", ecfp_hash_to_point(&var_res, var_k));
}

void benchmark_g2() {
	static ecpoint_fp2 var_a = { { {0x2F4FD05A, 0xDD366ECC, 0x2D438E27, 0x8C3DCCBE,
			0x814B9B43, 0x06444764, 0x39A9DB1E, 0x007C86BD},
			{0x8C87A86D, 0xFA9FF14E, 0x348172AF, 0x4A1C8F26,
			0x7B9B8D90, 0x284ADFBC, 0x8762B70A, 0x07EF95BE} } ,
			{ {0xEE8042D5, 0x2F1B341D, 0x50158CDE, 0xEE587D51,
				0x8FD2BC7A, 0x2503B1B4, 0xCB8FB2FB, 0x11980EE7},
				{0x452F7B0D, 0x99DD45B2, 0xE835A5E3, 0x220B0FAC,
				0x139F3492, 0x0DC3E5CC, 0xA5066A4B, 0x09E88E4D} } ,
				0};
	static const ecpoint_fp2 var_b = { { { 0x08F5A42D, 0x7E23949F, 0x8099B0C2,
			0x575274A1, 0x8022F358, 0x56C01070, 0x8C63D629, 0x8B7D1449 }, {
			0x1CC1829B, 0xB8F4C7A0, 0xC3C5A3B6, 0xE05EFED0, 0x7DC1B60F,
			0xF5DE17A7, 0xEE3F46D6, 0x8A8C8B4D } }, { { 0x088BD6E3, 0x32DC4037,
			0x6BA41EDD, 0xCE5DA3E9, 0xDDCEDFDF, 0x453BA5B6, 0x428C275A,
			0x26059928 }, { 0x65C3C3F1, 0x7810932C, 0xC1F16AC6, 0x0525E756,
			0x228FF513, 0xAFEE4D2D, 0x6E5D5FF1, 0x700EDF93 } }, 0 };
	static const bigint_t var_k = {0xE4F1B68E, 0x9C1ED28A, 0x5BCA32C0, 0xBEA93771,
			0x9D27E570, 0xCA990488, 0xC124E9D2, 0x196798D0};

	print("Benchmark for G2 ( E(Fp2) )\n");
	ecpoint_fp2 var_res;

	benchmark_call("Addition:       ",
			ecfp2_add_affine(&var_res, (const ecfp2_pt) &var_a, (const ecfp2_pt) &var_b));
	benchmark_call("Double:         ", ecfp2_dbl_affine(&var_res, (const ecfp2_pt) &var_a));
	benchmark_call("Multiplication: ", ecfp2_mul(&var_res, (const ecfp2_pt) &var_a, var_k));
	benchmark_call("Hash to point:  ", ecfp2_hash_to_point(&var_res, var_k));
}

void benchmark_gt() {
	static const fp12_t var_a = { { { { 0xEF392128, 0x2A933140, 0x555834F5,
			0x2F2E5453, 0x69E2D288, 0xA25FA88C, 0xCFAFD5FC, 0xADA3989F }, {
			0xA7C9311F, 0xFB1C9BCA, 0x16D83263, 0x9095F70F, 0x0A744516,
			0x1E21CBA5, 0x9E2D36B2, 0x065379A9 } }, { { 0xA5297340, 0x5EE10E8E,
			0xB36F4BD5, 0x7F5614EC, 0x8790B54F, 0x9C79CE43, 0x40CEC2F3,
			0x977415E2 }, { 0x87DF1B65, 0xC99B8F92, 0x787503CC, 0xFA473950,
			0x9D2BD3F2, 0xAC0B626D, 0x46152526, 0x449E4C5F } } }, { { {
			0x6756327E, 0xF2F29B28, 0xDAD4FE34, 0xED6DEEF1, 0x0F2338F9,
			0xCE80D85D, 0xD8FF50EB, 0x415B9603 }, { 0x11643E77, 0x5503A765,
			0xF82075A0, 0x44FD7F0B, 0x2BD3120C, 0x0F219C1B, 0xADC7DF39,
			0x2F190C75 } }, { { 0x69803551, 0xAE3F551A, 0x4223818B, 0xC8B6D4C5,
			0xF134DBAB, 0x73A0917D, 0xD44E613A, 0x42843E3A }, { 0x04124FB4,
			0x8205032B, 0xD40A7753, 0x3D1D705F, 0xEAF448EE, 0x8D3B99C7,
			0xEE9C6F01, 0x1FADC4C7 } } }, { { { 0xA6683C82, 0x9AFB13BF,
			0xF54212B3, 0xE995DF8D, 0xAFC524DB, 0xF9C3BF83, 0xB157847D,
			0x5A212E42 }, { 0xAE652BF9, 0x7F1737AE, 0xBDF07440, 0x6C737A98,
			0x04EE0141, 0xCD9C4E7C, 0xA713EAF3, 0x98F6B6CF } }, { { 0x0D659842,
			0x005BFE01, 0x438AFAA7, 0xF9EDB553, 0x11B26A06, 0x256762AE,
			0xADEA597D, 0x2AB4EF38 }, { 0x26D4CCB1, 0xB2462B8D, 0xF41490AD,
			0xE505B431, 0x30F87A9A, 0xA39ED2E2, 0xB4F828A4, 0x442FF96E } } } };
	static const fp12_t var_b = { { { { 0x546C1CED, 0x6A6EAE9F, 0x0E3C0F6A,
			0x2AE45E91, 0x70DB5638, 0xEBE558C4, 0x440AF735, 0x7FE3E21B }, {
			0x623D9F3A, 0xC41D55EE, 0x26B77587, 0xE8CA5F64, 0x140EF1EA,
			0x2863A5B1, 0xF49A1482, 0x55DB4B22 } }, { { 0x118832F5, 0x9F0CD78F,
			0xA20033BD, 0xE095D335, 0x120C4BFD, 0x852CF255, 0xF3233A06,
			0xA928081C }, { 0x9668CA3D, 0x9F2336B5, 0x405C06FB, 0xF7CADE35,
			0x951D991E, 0xB5C4E712, 0x82BA6A64, 0x3CEDCC5D } } }, { { {
			0x19515EB4, 0xAA50A2CF, 0x8D2D2746, 0xB93A8390, 0x7C29F444,
			0x6CA7E40E, 0x78FE1B3E, 0x39F32404 }, { 0x3654FA62, 0x6B6B532A,
			0x6F9EB149, 0xD4305900, 0xD8578344, 0xE4E5F94A, 0xBD58FD39,
			0xAAD52F14 } }, { { 0x803FBF0C, 0xD3290B9B, 0x9C959100, 0x98340E40,
			0x72844724, 0x59D32E7C, 0xCF89F80A, 0x00B9EDC8 }, { 0xF985DBC1,
			0x922431D0, 0x20FD65AC, 0x7E59CBB7, 0x4281F274, 0x8DC1DD83,
			0x408845C8, 0x8F9319BC } } }, { { { 0x9CFAC6F0, 0xA2EBBAEF,
			0xDB581682, 0x9E1FE585, 0xF9287451, 0x45CD3B4B, 0x35AFAB47,
			0x0F06D4B7 }, { 0xD45A4B2C, 0xBD2A52AE, 0x01AD1412, 0x37E476CC,
			0x7841273C, 0xC9BA5D76, 0xE93C4A74, 0x1CC4A0A4 } }, { { 0x02A92385,
			0xE2DD6AC2, 0x98B48577, 0x2BE2CBFF, 0x572EC8BE, 0x68E24BDB,
			0x282182CD, 0xB78C7835 }, { 0x982A080A, 0xD5A6B1EA, 0x28EFEA7F,
			0x6DB10B2B, 0x0B9115D9, 0xF6CC9B7E, 0x93FCFF29, 0x0A9F52E7 } } } };

	static const bigint_t var_exp = { 0x55AED7A4, 0xBC6EAECD, 0x98E6EF94,
			0x6287AD04, 0x12293515, 0x2BF8414A, 0xF15BAEA7, 0xB4812FBD };

	fp12_t var_res;

	print("Benchmark for GT ( GFp12 )\n");

	benchmark_call("Addition:       ", fp12_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp12_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp12_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp12_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp12_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp12_mul(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp12_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp12_exp(var_res, var_a, var_exp));
	benchmark_call("Exp. cyclotomic:", fp12_exp_cyclotomic(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp12_inv(var_res, var_a));
}

void benchmark_pairing() {

	static const ecpoint_fp var_a = { { 0x00000001, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, {
			0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000 }, 0 };
	static const ecpoint_fp2 var_b = { { { 0xDE4A4459, 0x88C92DD4, 0xCE4795B0,
			0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176 }, {
			0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2,
			0xB6436EE8, 0x2180F37C, 0x6B994492 } }, { { 0xBDEEBD2F, 0x8567D8AB,
			0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E, 0xF9E1F786,
			0x1C93D08B }, { 0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0, 0x22251003,
			0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633 } }, 0 };
	static const ecpoint_fp var_a1 = { { 0x0BD9C43A, 0xB14BE470, 0x7736D0EF,
			0x048C7188, 0x242D442F, 0x64F01347, 0xB18E3471, 0x0647FB21 }, {
			0x24B4B3CA, 0xB0D93FEC, 0xA3979405, 0x031513A4, 0x453083AF,
			0x200A78E4, 0xC85DC2CF, 0x2591A1E2 }, 0 };
	static const ecpoint_fp2 var_b1 = { { { 0x4C80DAD2, 0x5DCE2E27, 0xDA9B6D3F,
			0x0F5E247F, 0xC2E632EB, 0x0A89589B, 0x7B514419, 0x729C32CB }, {
			0x4999A149, 0x304E902A, 0xDCFCA3F4, 0x74F1DCBF, 0xB4CD2356,
			0xD0C15C9F, 0x953A93AD, 0x9067DD0F } }, { { 0x88122481, 0xE6502005,
			0xA6EC6E9D, 0x7A185801, 0xFC76058D, 0x83021EC6, 0x62C2CEA6,
			0x636ABFB7 }, { 0x8A91EAAF, 0x4CD7937D, 0x6F4BDAC7, 0x92AC7DCD,
			0x9F122968, 0xB744F7BD, 0x8F8BC7CB, 0x05F7EF78 } }, 0 };
	static const ecpoint_fp var_a2 = { { 0xEC5FBD06, 0x906B237F, 0xE3013822,
			0x652A861F, 0x1467D181, 0x160AC4B9, 0xA4A830D0, 0x44C5B9DF }, {
			0x33EBBFDB, 0x464D0AED, 0xC089D616, 0x82F34EC7, 0x6C5CC02A,
			0xE05C4A4E, 0x866EF296, 0x62E01918 }, 0 };
	static const ecpoint_fp2 var_b2 = { { { 0x62E37E53, 0x9B4FE0C1, 0xEDC1A661,
			0x58B71BFD, 0x5BE9BFF5, 0x231900EF, 0x73324684, 0x1A17C2C0 }, {
			0x2AF901A5, 0x904FA853, 0xD22A84E8, 0x97CB59E0, 0xE5942D97,
			0x32861A8C, 0xBFFFCFE5, 0x736A16B7 } }, { { 0x0FF04B89, 0x0D940B2E,
			0x2A0490EC, 0x94353753, 0x8532E8CC, 0xDD7162B4, 0x0292B2FA,
			0x872B489F }, { 0xD5D0DD18, 0x1AAA0F9F, 0x4A6197A5, 0x32A482A9,
			0x2C0ACA68, 0xF9EC2FAC, 0x137DEF9A, 0x8CE1E90F } }, 0 };

	fp12_t var_res;

	print("Benchmark for pairing \n");

	benchmark_call("Optimal Ate:    ",
			pbc_map_opt_ate(&var_res, &var_a, &var_b));
	benchmark_call("Optimal Ate Mul:",
			pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2));
	benchmark_call("Optimal Ate Div:",
			pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2));
}

void benchmark_ibe() {
	byte key1[16], key2[16];
	bbkem_ciphertext cipher;
	const char *id = "cm0 in public";

	print("Benchmark for BB1-KEM IBE \n");

	benchmark_call("Encapsulate: ", encapsulate_key(key1, &cipher, id));

	benchmark_call("Decapsulate: ", decapsulate_key(key2, &cipher, id));

	assert_bytearr_equal(key1, key2, 16, "key equal");
}
#elif PRECISION == 160
void benchmark_bi() {
	print("Benchmark for Bi\n");

	static const bigint_t var_a = {0x1ADAC108, 0xC2DDE1F5, 0x3818A1FE, 0x526A6FC5, 0xE26612E5};
	static const bigint_t var_b = {0x1D4DEF27, 0x16A00188, 0x13BBC48A, 0x6D2B5633, 0xFD7A2258};
	static const bigint_t var_exp = {0x75414A82, 0xCDF6D4C6, 0xAB9F205B, 0x055CF27E, 0xE27B4B74};

	word_t var_res[2*BI_WORDS];

	benchmark_call("Addition:       ", bi_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", bi_subtract(var_res, var_a, var_b));
	benchmark_call("Copy:           ", bi_copy(var_res, var_a));
	benchmark_call("Compare (equal):", bi_compare(var_a, var_a));
	benchmark_call("Compare (diff): ", bi_compare(var_a, var_b));
	benchmark_call("Clear:          ", bi_clear(var_res));
	benchmark_call("Negation:       ", bi_negate(var_res, var_a));
	benchmark_call("Multiplication: ", bi_multiply(var_res, var_a, var_b));
	benchmark_call("Square:         ", bi_square(var_res, var_a));
	benchmark_call("Shift Right 1:  ", bi_shift_right_one(var_res, var_a));
	benchmark_call("Shift Right 63: ", bi_shift_right(var_res, var_a, 63));
}

void benchmark_fp() {
	print("Benchmark for Fp\n");

	static const bigint_t var_a = {0xD1CDD8B4, 0x7660FD71, 0x1E77FCBB, 0xE11C5F58, 0x7BC39E21};
	static const bigint_t var_b = {0x1B3DC268, 0xEA578404, 0xBABAB3DF, 0x941F78D6, 0x1598EA29};
	static const bigint_t var_exp = {0x6EB1C0DC, 0xE532F60D, 0x964051B2, 0x9AF290DE, 0x4401A94C};

	bigint_t var_res;

	benchmark_call("Addition:       ", fp_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp_mul(var_res, var_a, var_b));
	benchmark_call("Multiplication (Barrett): ", fp_mul(var_res, var_a, var_b));
	benchmark_call("Multiplication (Monty): ", fp_mul_monty(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp_exp(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp_inv(var_res, var_a));
}

void benchmark_fp2() {
	print("Benchmark for Fp2\n");

	static const fp2_t var_a =  { {0xF81CB2EF, 0x03EF55CB, 0x6A091E37, 0x1C14DA87, 0x20624C0C},
			{0x28C49847, 0x83B74C97, 0x8D57C481, 0x89D9DA21, 0x0384C0D1} } ;
	static const fp2_t var_b =  { {0x6CFE4C71, 0xD2B6C965, 0x77129B3A, 0x427C95CC, 0x0802835B},
			{0x9CD5D452, 0x840FCA12, 0x5D2B319B, 0xF31735AC, 0x1D6B4E2D} } ;
	static const bigint_t var_exp = {0x05B36C5B, 0x36A668AF, 0x830E8281, 0xFF351C89, 0xA03F9492};

	fp2_t var_res;

	benchmark_call("Addition:       ", fp2_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp2_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp2_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp2_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp2_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp2_mul(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp2_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp2_exp(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp2_inv(var_res, var_a));
}

void benchmark_g1() {
	static const ecpoint_fp var_a = {{0xAAC303ED, 0x104C8AF7, 0x2686AFF6, 0xC279B52D, 0x0D014E37},
			{0x63F92CE6, 0xF854723C, 0xC890AE43, 0xA201D72D, 0x08C0DAC2},
			0};
	static const ecpoint_fp var_b = {{0x396E55C6, 0x283C6F2A, 0xB13889DB, 0xD1765DF4, 0x0A15C212},
			{0x1BF413EE, 0x921732C4, 0x2E8CE955, 0x006DFA7F, 0x1607FFCB},
			0};
	static const bigint_t var_k = {0x53EAE0FE, 0x3F62CB24, 0x6703B6C1, 0x5D3886A9, 0x12CD6D2E};

	print("Benchmark for G1 ( E(Fp) )\n");
	ecpoint_fp var_res;

	benchmark_call("Addition:       ",
			ecfp_add_affine(&var_res, (const ecfp_pt) &var_a, (const ecfp_pt) &var_b));
	benchmark_call("Double:         ", ecfp_dbl_affine(&var_res, (const ecfp_pt) &var_a));
	benchmark_call("Multiplication: ", ecfp_mul(&var_res, (const ecfp_pt) &var_a, var_k));
	benchmark_call("Hash to point:  ", ecfp_hash_to_point(&var_res, var_k));
}

void benchmark_g2() {
	static const ecpoint_fp2 var_a = { { {0xF2F1E596, 0xFC3250A4, 0x2B5E15E2, 0xBAFBD11C, 0x0E0BDCEC},
			{0x192D93F7, 0x642B49E0, 0x31C6EA1E, 0x7FA6FE53, 0x09B96004} } ,
			 { {0xD045944F, 0x848DD218, 0xE8BD75FB, 0x53C0D000, 0x01199AD1},
			{0x00997E9E, 0x677D856B, 0xEA5B5E37, 0x12DC56FF, 0x07CD6147} } ,
			0};
	static const ecpoint_fp2 var_b =  { { {0x4F5B11F6, 0x9F061A1D, 0x48B2582D, 0x22A889CE, 0x1EA3F22E},
			{0x6D74F03F, 0xA8E7C7DB, 0x5A6E8A4B, 0x9474F33C, 0x0C068E2B} } ,
			 { {0xC6CE3C5B, 0x999423A9, 0x265F001B, 0x523A264A, 0x0DB9195E},
			{0xBB378A4E, 0x2F7ECA15, 0x0121A158, 0xE031F6AA, 0x06660169} } ,
			0};
	static const bigint_t var_k = {0x3BF08627, 0xDF8B5908, 0xBBB33C94, 0xBC5ECD1F, 0xEC9D0A38};

	print("Benchmark for G2 ( E(Fp2) )\n");
	ecpoint_fp2 var_res;

	benchmark_call("Addition:       ",
			ecfp2_add_affine(&var_res, (const ecfp2_pt) &var_a, (const ecfp2_pt) &var_b));
	benchmark_call("Double:         ", ecfp2_dbl_affine(&var_res, (const ecfp2_pt) &var_a));
	benchmark_call("Multiplication: ", ecfp2_mul(&var_res, (const ecfp2_pt) &var_a, var_k));
	benchmark_call("Hash to point:  ", ecfp2_hash_to_point(&var_res, var_k));
}

void benchmark_gt() {
	static const fp12_t var_a = {  {  { {0xDA2646F2, 0x766DA97F, 0xA9EFA225, 0xF85C3CA6, 0x188F949B},
			{0x06B48250, 0xBAEE62F2, 0xC764A04C, 0x9BC1137F, 0x0037DCA7} } ,
			 { {0x6CB9442D, 0xD3AB9688, 0x3C572258, 0x347B9A7E, 0x1E06DF14},
			{0x96A5C8B0, 0x55E232B8, 0x03FE98F4, 0x5FF260C9, 0x0CBF4C24} }  } ,
			 {  { {0xF12799EB, 0xA2EE0AE8, 0x3F0046CF, 0x01219A18, 0x1C92A53C},
			{0x4003E514, 0x10AC9B19, 0x2424AF71, 0xC98593C6, 0x19E287A9} } ,
			 { {0xE75980DC, 0x3DDB6D0F, 0xE3FAE839, 0x10A8F6CC, 0x19ACDA77},
			{0x631082E3, 0x271D9366, 0x5F9C76A8, 0x966E8FB4, 0x1628B4A0} }  } ,
			 {  { {0x56B465FE, 0xA81983FA, 0xD1256050, 0x07DD40D2, 0x025884CB},
			{0xD8C14BD4, 0xCC71BD05, 0x1DB7DCD1, 0xEF5152CF, 0x21CE8912} } ,
			 { {0x17F53D48, 0xD79BDB9A, 0xE7E417F4, 0x5D89DFA4, 0x1B09A068},
			{0x0F8FEBFC, 0x8BCB2F84, 0x6E719723, 0x85A07682, 0x1B940429} }  }  };
	static const fp12_t var_b = {  {  { {0x4858E80E, 0xE534892F, 0x6CAE4E8C, 0xB2EB1EC6, 0x013BE966},
			{0xFFE670DE, 0x809DE509, 0x6B961A2F, 0xB0CA6087, 0x0E5BBA62} } ,
			 { {0xFB3ADD60, 0x6C0F0B6C, 0x5C71C2E9, 0x4E50C28A, 0x15213E47},
			{0x4484A65B, 0x804BD5D2, 0xD3F638EC, 0x424BEAD5, 0x0BA0264F} }  } ,
			 {  { {0xC3750D03, 0xAD7856D6, 0x83E614EF, 0x0469864B, 0x046003E8},
			{0xADD85DFB, 0x1A1CE69F, 0xEE143153, 0x5CC7A874, 0x1E8C5796} } ,
			 { {0xEDA95E15, 0x01AB48DB, 0x87618547, 0x524F5EBD, 0x0206FEFA},
			{0xC6F7D1B1, 0xC3A98A1D, 0x696EFB16, 0xE560F1BE, 0x152375DC} }  } ,
			 {  { {0xDC8014F2, 0x20AD7718, 0x595AFD65, 0x7361B881, 0x062A9F87},
			{0xE4E33C77, 0x64808477, 0x831FE0FB, 0xC026AB96, 0x124A624D} } ,
			 { {0xC3B4A742, 0xF920D141, 0xEAB70F99, 0xB5ACFDEA, 0x0064AA20},
			{0x21C1A924, 0x2F401E86, 0x85158307, 0xC1E96CEF, 0x0AD0536F} }  }  };

	static const bigint_t var_exp = {0xD3FD65B9, 0xEEC8E675, 0x6B28DF12, 0x5F9D54EC, 0xCB038DD2};

	fp12_t var_res;

	print("Benchmark for GT ( GFp12 )\n");

	benchmark_call("Addition:       ", fp12_add(var_res, var_a, var_b));
	benchmark_call("Subtraction:    ", fp12_sub(var_res, var_a, var_b));
	benchmark_call("Halve:          ", fp12_hlv(var_res, var_a));
	benchmark_call("Double:         ", fp12_dbl(var_res, var_a));
	benchmark_call("Negation:       ", fp12_neg(var_res, var_a));
	benchmark_call("Multiplication: ", fp12_mul(var_res, var_a, var_b));
	benchmark_call("Square:         ", fp12_sqr(var_res, var_a));
	benchmark_call("Exponentiation: ", fp12_exp(var_res, var_a, var_exp));
	benchmark_call("Exp. cyclotomic:", fp12_exp_cyclotomic(var_res, var_a, var_exp));
	benchmark_call("Inversion:      ", fp12_inv(var_res, var_a));
}

void benchmark_pairing() {

	static const ecpoint_fp var_a = {{0x3D53126B, 0x10329D85, 0x33521331, 0xAED48C99, 0x1D65A566},
			{0x5347AEF1, 0xDD12D01F, 0x1DA5DD33, 0xEBF80F5B, 0x20182AA1},
			0};
	static const ecpoint_fp2 var_b ={ { {0x9A7BD73B, 0x97264E08, 0x352D5E7A, 0x5CF062C9, 0x19FD3612},
			{0xDDAEC0B6, 0x4F93839F, 0x735A5653, 0x2BBBE8E0, 0x03556E26} } ,
			 { {0x158F8C04, 0x923536F2, 0xE30F769A, 0xC8157A06, 0x03FADD37},
			{0x70CFD2F3, 0xA90E4F39, 0x4B1F0433, 0x33695DA5, 0x0415038F} } ,
			0};
	static const ecpoint_fp var_a1 = {{0x6DC0B91F, 0x0B36E11F, 0x22A8E534, 0xCADF8247, 0x1E23D739},
			{0xA93D0D4E, 0xC0665A79, 0x6E433CB5, 0x14F67391, 0x0B01BAAC},
			0};
	static const ecpoint_fp2 var_b1 = { { {0xC1757502, 0x883DF09E, 0x22DB3B06, 0xEBA2BFDB, 0x0ADE58E5},
			{0xC6680C55, 0xC63B280B, 0x155644FB, 0xE421A6B5, 0x0348EFD9} } ,
			 { {0xCA8269D6, 0x7D49EF43, 0xCAB4ACBF, 0x6A04000C, 0x23AA1CF6},
			{0x02A60669, 0x95C74BB5, 0x60734A15, 0xE1D35DDC, 0x02CAA7BE} } ,
			0};
	static const ecpoint_fp var_a2 = {{0xCA8B084C, 0x4E9AC9FB, 0xEA5FAC80, 0x6A77AAC6, 0x019E2960},
			{0x488AC3E7, 0xE0764A0D, 0x87006070, 0x51DC6A1B, 0x1350EA0A},
			0};
	static const ecpoint_fp2 var_b2 =  { { {0xE7C76CF7, 0x77DC8FB1, 0x794629CD, 0x5CCE2BAC, 0x19174388},
			{0x13527D0C, 0x6D6FB628, 0xBE0348F8, 0x4D5E4225, 0x23691C3B} } ,
			 { {0x018B17A6, 0xF00AE722, 0xC0345E7B, 0xF49EC25D, 0x11E0E5EC},
			{0x54C718F7, 0x782D53CC, 0x98CC4AF1, 0xAE348115, 0x147AABED} } ,
			0};

	fp12_t var_res;

	print("Benchmark for pairing \n");

	benchmark_call("Optimal Ate:    ",
			pbc_map_opt_ate(&var_res, &var_a, &var_b));
	benchmark_call("Optimal Ate Mul:",
			pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2));
	benchmark_call("Optimal Ate Div:",
			pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2));
}

void benchmark_ibe() {
	byte key1[16], key2[16];
	bbkem_ciphertext cipher;
	const char *id = "cm0 in public";

	print("Benchmark for BB1-KEM IBE \n");

	benchmark_call("Encapsulate: ", encapsulate_key(key1, &cipher, id));

	benchmark_call("Decapsulate: ", decapsulate_key(key2, &cipher, id));

	assert_bytearr_equal(key1, key2, 16, "key equal");
}
#endif
int main() {

	benchmark_bi();
	print("\n\n");

	benchmark_fp();
	print("\n\n");

	benchmark_g1();
	print("\n\n");

	benchmark_g2();
	print("\n\n");

	benchmark_fp2();
	print("\n\n");

	benchmark_gt();
	print("\n\n");

	benchmark_pairing();
	print("\n\n");

	return 0;
}
