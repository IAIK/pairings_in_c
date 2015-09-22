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


#include "pbc/pbc.h"
#include "types.h"

int main(void) {
	fp12_t var_res;

#if (BNCURVE == BN256)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static const ecpoint_fp2 var_b = { { {0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4, 0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564},
	{0x3CFD9384, 0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A, 0x1C964417} } ,
	 { {0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D, 0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78},
	{0x351ED5CC, 0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422, 0x539E24DF} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xE27FD955, 0xF40A2688, 0x62E84E21, 0x8C2E649A, 0xFD7B4254, 0xED02FABF, 0x186C431E, 0x805BC2EF},
	{0xC7360055, 0x84267F6B, 0x12980D2D, 0x982AB5CC, 0xC84CD076, 0xC5184346, 0xFA60A8DD, 0x18C79FEB} } ,
	 { {0x72032997, 0xD86D4C6B, 0x206BBEEE, 0x8475AC4A, 0x93D1E9B3, 0xDDF051F6, 0xDD06E8E3, 0x986BBF00},
	{0x18D88CCD, 0x6C1A670C, 0x11B94B74, 0xFF2A61A1, 0x5EE91878, 0x17DF38D5, 0x0BB337C3, 0xB7B19B4B} }  } ,
	 {  { {0x88F8A370, 0x6A98E874, 0x077BCF03, 0xAAD9A3B4, 0x67E52A32, 0x2ED91B5F, 0x86DDBDD7, 0x64B97D87},
	{0x84B32B66, 0xCA05D64C, 0x890CDB46, 0x51F72F94, 0x28391BFF, 0x11866729, 0x5BC266FB, 0x896852DE} } ,
	 { {0xC63126C1, 0xA50EB483, 0x06C28F2F, 0x15BC4334, 0x2FBE001C, 0x992D1D12, 0x2C712320, 0x462E1ED7},
	{0x9BC57DCA, 0xB60324DA, 0x2A89CF3C, 0xD2BF7E1E, 0x4372D5DC, 0x7BD6669E, 0xAA10CF74, 0x4FE65C8C} }  } ,
	 {  { {0x5938C374, 0xF4CEAF5F, 0xDEAEF799, 0xEACE57CD, 0x772C72B7, 0xD28C24D8, 0x50C15966, 0x06A30D97},
	{0x57D9159D, 0x5BA63966, 0x97974415, 0x1026770A, 0x00C84DAF, 0xD0CC4EE2, 0xDCE5EA54, 0x875D89FD} } ,
	 { {0xDA03AD91, 0x43BFDA25, 0xD264BF5B, 0xB0CF3D90, 0x11B19B37, 0x25161995, 0x37EC3568, 0x8CFEB4AB},
	{0x49AF51EB, 0xF479D2C7, 0xA8B59B5C, 0x717629E3, 0x82EF2C50, 0xF9ACC153, 0xAEEA7F27, 0x61558BCD} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5832 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5833 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5834 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5835 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5836 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5837 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5838 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5839 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5840 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5841 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5842 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5843 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F, 0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D},
	{0x3BA796CA, 0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE, 0x8BD8C27B},
	0};
		static const ecpoint_fp2 var_b = { { {0x0064FD84, 0x8B135350, 0xEA32A23E, 0x3857748A, 0xC9A5CA82, 0x69B5A041, 0x944FDA38, 0x1781A4FD},
	{0xFE2CFE50, 0x05D4DDB8, 0xF6FEDAAE, 0x93C0FD19, 0x63EFFDE3, 0x46DAEA5A, 0xDA84A42C, 0x1BEFBA94} } ,
	 { {0xAC17408E, 0x81D4EACB, 0xE0A423F4, 0x251CBE89, 0x17BA8F0E, 0x284D1C44, 0xC66A4521, 0x5C4B58D2},
	{0xF259F224, 0x3E705BE3, 0x92FA9BC8, 0x85F8C96F, 0x593A4B3A, 0xC5079ABA, 0x69AEF095, 0x22E51011} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x2D480C3D, 0xFB87E2CB, 0x314448BE, 0xEC0B1C8B, 0xA38D81EF, 0x2C848102, 0xE42D71D6, 0x17226B48},
	{0xAD90F954, 0x0DF878B2, 0x4C165E03, 0xAC5A76B8, 0x1537E497, 0x9EA233C6, 0xC94AF3FF, 0x50313736} } ,
	 { {0xDC16ABED, 0xED970200, 0x4694AC55, 0xF81F5B27, 0x79352FB2, 0x6F361FAF, 0x1B9F7B30, 0x5A91BC2D},
	{0x5F26598E, 0x6939E69D, 0x59F3D454, 0x29A71A67, 0xE1F69943, 0x3CCF0581, 0x85BB28CD, 0x8940209A} }  } ,
	 {  { {0x4E370FDE, 0x9026E1DB, 0x905EAB89, 0xD5DDC3E1, 0xF19DDA88, 0xA544DD45, 0xDAA15F42, 0xA544CD69},
	{0xC5B0E7D1, 0x11DDCBEE, 0x78660A9F, 0xA7D9003D, 0xDF847DAC, 0xD8554BDD, 0x04EAAB45, 0x2E4D6402} } ,
	 { {0x78A689A8, 0x2D144765, 0x54C9CEAD, 0x36330FA2, 0xF6D1859D, 0x4DC8DCFB, 0xAD58BECC, 0x030A1791},
	{0xB436795C, 0x17C47C36, 0x8E647CD0, 0xD6BD10B5, 0x1BBAFFB8, 0xE5B0636A, 0x83B273CC, 0x1C402D6C} }  } ,
	 {  { {0x715DB8E5, 0xF757F52B, 0x52F6913B, 0xD88EDA4B, 0x7A719F73, 0xD1B963A3, 0x722C321C, 0x0BAA22E6},
	{0x8AA6A71A, 0x649C8F9A, 0x1ABF47D7, 0x04567971, 0x43DC94AB, 0xCBC59903, 0x3E3A1F0D, 0x8BA37020} } ,
	 { {0x8238A6FF, 0xD56EBFF6, 0x9A5868C7, 0x2B7DB352, 0xB2253BD1, 0x9D36F878, 0x7B90BDE4, 0x5FB5CBE1},
	{0xB0266115, 0xBF49759D, 0xBDA18E62, 0x75406022, 0x886B75B5, 0x208F20A3, 0xE5E12AD5, 0x25D941F2} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5844 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5845 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5846 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5847 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5848 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5849 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5850 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5851 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5852 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5853 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5854 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5855 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x7F388B97, 0xB0923FD2, 0x56F38373, 0xF8AEFC88, 0x368EE2E8, 0x9C2A6CB5, 0x102AC5E2, 0x191C1818},
	{0xE30F1178, 0x4310DF43, 0x27831EDA, 0xEB3B92FD, 0x5FE6A244, 0x5BC09A80, 0x5916C522, 0x7DF76E8E},
	0};
		static const ecpoint_fp2 var_b = { { {0x5B8F1830, 0xABEE7967, 0xFF3F6547, 0xBE6508AE, 0xAF81CE2E, 0x0608FD04, 0x08151BDC, 0x126DA2BE},
	{0x9EE8A17A, 0xA649E833, 0x35533C95, 0x0587B6A7, 0x30DA4553, 0xDB056BD5, 0x67EB6898, 0x161A48A0} } ,
	 { {0x1C9946AB, 0x9BCC2942, 0x4A7988DD, 0x5896C70F, 0x51356FF1, 0xA5EC3F89, 0x4AC9087F, 0x40A57F78},
	{0xA5511A80, 0x46F621E9, 0xC22099D0, 0x9BD1A89E, 0xCF31715E, 0xABFA0F2F, 0x2D27C327, 0x65559FA9} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF4332411, 0x5358C476, 0xA8835D35, 0xA372DF81, 0x5B98DA67, 0x1518F85C, 0xFBB8D085, 0x6D10F4A8},
	{0xA7392CB0, 0x995C9BEE, 0x53BEF0B8, 0x322AA7EC, 0xACEF6D58, 0x1AE8F9D2, 0x03EC4660, 0x4F7E0F3A} } ,
	 { {0xCA8AC841, 0x9D20A1B1, 0xFDC7B659, 0x220838FF, 0xFA54FB20, 0x2E289178, 0x63D62E3D, 0x3F756335},
	{0x4F88F55A, 0xCD58E91B, 0x655E6562, 0x12BB41E9, 0x1319DA08, 0xC79ED22B, 0x18467C91, 0x9BD322CF} }  } ,
	 {  { {0xBCD5F423, 0x585CB1C0, 0x9A49170A, 0x8E9F89D5, 0xC82F3682, 0x99D82891, 0xE16211DC, 0x5FB056F9},
	{0x5C976280, 0xDDCBD8FF, 0xEB0932FB, 0x016ED7E3, 0xAC1BE499, 0xEAA2C9B9, 0xF3B90AE1, 0x56CCA8E6} } ,
	 { {0x720F9F79, 0x5DC7DDC3, 0x3A547918, 0x5C974CAD, 0x8C9A3B26, 0xCD1581BD, 0x6ABE47B8, 0x691A5765},
	{0x659FDA0E, 0x01884007, 0xB430F40D, 0xF59635AF, 0xDD366383, 0x63B82067, 0x81557F74, 0x8539073E} }  } ,
	 {  { {0x0A1EDB4D, 0xB3DDF704, 0x1AA41B53, 0xACDF74F4, 0x4B7D7874, 0x677BA01A, 0x1270B006, 0x78809D38},
	{0xE9351FCA, 0x760951DD, 0x5AA378F3, 0xCCE9AB77, 0x12E6A887, 0xA90D8F75, 0x78DB3B57, 0x1CF541BE} } ,
	 { {0x9CF098F6, 0x45AA593F, 0x9573DCD4, 0x4D96BF8E, 0x5560E405, 0xF9E5533D, 0x24C38F90, 0xAE00F195},
	{0x0D080781, 0xD926EBA0, 0x1019F1B9, 0x69D2C116, 0x968A6480, 0x645289AB, 0x24133FF9, 0x080E4A2B} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5856 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5857 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5858 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5859 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5860 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5861 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5862 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5863 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5864 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5865 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5866 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5867 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x88C8E869, 0x67ABFFDD, 0xA52FF07D, 0xA9949A5E, 0xBF3FA78D, 0xC17CBC63, 0x6C01B7D3, 0x62BEA003},
	{0xBAA078FE, 0xC7BA4DAA, 0xD8477481, 0xA4D2D4D8, 0x718E5EB1, 0xF79E1FD8, 0xF50E5A32, 0x1E73BADF},
	0};
		static const ecpoint_fp2 var_b = { { {0x3F458B6E, 0x49A89F88, 0x917BF73B, 0x4EFFEFE7, 0xAA99C02B, 0x9ADA15EB, 0xDB79E685, 0x4D3BF23F},
	{0xCA8AD05C, 0x9A9527AF, 0x8D565FF4, 0x66BE327C, 0x44C396C8, 0xC0B7DB19, 0x27FCEC6E, 0x07162042} } ,
	 { {0xF5496553, 0xDB100AA3, 0xBD89DA6A, 0xF88671BA, 0xC98831A8, 0x07346A32, 0xB440D53E, 0x28239EB8},
	{0x49EE4B75, 0x59230681, 0xB7CCA3DA, 0x5E1F1FDF, 0xED49D71E, 0xC5B669CC, 0xA1E31FD1, 0x65B8E631} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x147769DD, 0x49D5DA7C, 0x9DDB4C37, 0xEA9D1B58, 0x15A54827, 0x6643D3C9, 0x5DB8F77C, 0x05B473D2},
	{0x6E6FB5ED, 0x3FBFD48F, 0xE225CF9D, 0x4BC75938, 0x1EB776B0, 0x34C086B2, 0x849FA889, 0xADEB522F} } ,
	 { {0xE2D9F895, 0xBE045A1E, 0x4312F7B5, 0x24E67376, 0x7AA010D3, 0xAE296D80, 0x79DC67E9, 0x8E468B01},
	{0x6D2F82E6, 0x8D9985C2, 0x5B64C30B, 0x2F120662, 0xB1BEE98C, 0x7919F3A9, 0xCB5DB4A5, 0x8F5F2023} }  } ,
	 {  { {0x5CD24F9D, 0xFEFCE1EB, 0xAAC3C252, 0xACFF100D, 0xF0681F88, 0x2262C014, 0x38C8FCF5, 0x7ED8DAD2},
	{0x5CB7C732, 0x0EDE04D2, 0x47E042D7, 0x6F7DC337, 0x1C80B5F5, 0x21899E76, 0xA09A71E0, 0x25F3FA0B} } ,
	 { {0x9B3613C0, 0x7AC6DE4A, 0x005AE92B, 0x722B0BA0, 0x045BCEF7, 0xF143B7AF, 0xBC244975, 0xB70AD96A},
	{0x9CC400EE, 0x7D379BFD, 0x4DF5038B, 0x1D63BEA6, 0x9A088829, 0x7665A4D5, 0x60EF7717, 0x98E72DA7} }  } ,
	 {  { {0xCA3B3E56, 0x9CB2C732, 0x44316FBE, 0xD0CF2EBE, 0x681F6DA0, 0x10912A0A, 0xB76FD695, 0xA399E939},
	{0x42F90B91, 0x1B4BE287, 0xC5C9ADC7, 0x0F36137A, 0x40D0E78D, 0x96DD7B91, 0xB47709DD, 0x25AC9138} } ,
	 { {0x7CDCBDE6, 0x1D46AE92, 0xF1E291DC, 0xD5B4188F, 0xAEEE990B, 0xBBF2768B, 0xAE489396, 0x504ABFA9},
	{0x12D25B9F, 0x7EC29451, 0xF885B69D, 0xBDDAD26F, 0x78EAD264, 0x16BB453B, 0x3A24FA7F, 0xB2B7B2B0} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5868 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5869 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5870 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5871 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5872 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5873 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5874 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5875 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5876 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5877 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5878 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5879 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x89DE861E, 0x377052E6, 0x3758C93E, 0x58ED6F3C, 0x441563F6, 0xE7FFCD68, 0x8AD94B58, 0x15E535ED},
	{0xF1F69585, 0x53AE9561, 0x45F77944, 0x78FE9074, 0x5BB84BDE, 0x618F0FBA, 0xC152160D, 0x6A1CFF50},
	0};
		static const ecpoint_fp2 var_b = { { {0xAC8F4843, 0x6F8F7703, 0x7B1EAEDB, 0x050C486F, 0x2C1D3644, 0x44BAEE24, 0xB542D259, 0x3A2CEA7B},
	{0x3DBC4482, 0x0676D59E, 0xA654C0BD, 0x3A026DD1, 0xD61EFC12, 0x91B5D65E, 0xC3C48A22, 0x15D85C8D} } ,
	 { {0x118DB407, 0xC8A996F1, 0xC6C75D56, 0xA6226F7C, 0x6F09D59B, 0xEA5D5E7C, 0x9D2BE4CB, 0x8AF7A1CB},
	{0x9EB3D760, 0xF6308F7A, 0x3567B04C, 0xD18C224C, 0xB5260FB6, 0xB17F8033, 0x4602E43B, 0x99B7C3E1} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xEADEB821, 0x29D6E412, 0xF12E5FE3, 0x2E58CC0E, 0xB4EFB21D, 0xFDE11991, 0xB61919BD, 0x30CA39B0},
	{0xF4368E03, 0xD1A69162, 0x9E806FCD, 0x41A1992F, 0x9F4213CB, 0xEB3EC124, 0xEAECF4EE, 0x74343935} } ,
	 { {0x23D7D90F, 0x2FF91E22, 0x343E58C0, 0xF053D7E3, 0x0F690145, 0xB574042A, 0x4456F4E6, 0x5B58F6BF},
	{0x2EBC4282, 0x118FB581, 0x6A5BF8F9, 0x80B4C9AB, 0x0AB70654, 0xF141D32B, 0x732B9357, 0x2915DB1C} }  } ,
	 {  { {0x8FAC637C, 0x4559DDE0, 0x5093E7C6, 0x4789C9AA, 0x917D1CEC, 0x459B1942, 0xFD4CD31C, 0x03F74970},
	{0xC1D09933, 0xBF117F58, 0x0F229C3F, 0x98FF56FF, 0x7D561033, 0xFE43EF2A, 0xE8FA417B, 0x658540F7} } ,
	 { {0xE3225A5B, 0x3AF8587D, 0x05622EAA, 0x603465FB, 0x4A326693, 0xB46AA075, 0x22507A0B, 0x0F184ABC},
	{0xBC7F745B, 0x348E3064, 0x2F27896C, 0x108A29D4, 0xFEC3F570, 0x6AC0D7B5, 0xDD80572E, 0x57BED101} }  } ,
	 {  { {0xFCCB898F, 0x4C3CD051, 0x57B026C7, 0x4FF70E47, 0x9B4E83D8, 0x28F3A65A, 0x869417A7, 0x738826AF},
	{0xD5CED170, 0x30A7ECF9, 0x5EF74203, 0x5BAC76C5, 0x052418E2, 0xCA6B58DD, 0x0425A867, 0xA6F747AB} } ,
	 { {0xBDB5D5F1, 0xEB18539C, 0x128A2E5D, 0x28D08DA9, 0x758C96A0, 0x9C52595F, 0x4FF97CC2, 0x83FCB56B},
	{0x7A6B4DC9, 0xDCC421BB, 0x6443BA7C, 0x21CADFED, 0x2074F195, 0xCCDD9B8E, 0xE45FB0FA, 0x1B3B7E48} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5880 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5881 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5882 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5883 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5884 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5885 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5886 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5887 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5888 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5889 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5890 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5891 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x77D40CD5, 0xBFE11037, 0x2CD7D9FC, 0x7BB0A22A, 0x671F3C8E, 0x749296AA, 0x05A52CD8, 0x9DC46469},
	{0xD8D3457E, 0xCCA6F1D8, 0x5EB7A1B7, 0x450A2267, 0xEC555E08, 0x75D824C2, 0x605D315D, 0x05637D10},
	0};
		static const ecpoint_fp2 var_b = { { {0xFD98C6CF, 0xBFA7A0C0, 0x9F9FD764, 0xA64076D0, 0x52EB13F7, 0x446F1390, 0x16ADAA22, 0x4EE4F5BA},
	{0xA6869CE6, 0x364391B6, 0x076E38FE, 0x955CEB61, 0x094A52BE, 0x609B0422, 0xB2786D9C, 0x73A021FC} } ,
	 { {0x11CCCB45, 0x6E301119, 0xFC02ABC2, 0x57479E48, 0x04F29C35, 0x2A174870, 0x1AC307D5, 0x8771F8C1},
	{0xF23D9F94, 0x3F02DD17, 0x225B6391, 0xCB39E430, 0xA6D57E34, 0xB1EABF1A, 0x12242E34, 0xB5A40644} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB0A26AA2, 0x016D0FF8, 0x92557584, 0xD85A3C33, 0x016F6ECC, 0x8AE9FC9F, 0x55CF3E45, 0x2C4F8C70},
	{0x39A3E69C, 0xD6482F65, 0xCD2212DF, 0x3BDB1F95, 0xAF5A092A, 0x0650768B, 0xD7AAFA4E, 0x51E41269} } ,
	 { {0x5D451BE4, 0x327232C3, 0xA962C71F, 0x7173B351, 0xA806CE20, 0x5B3D03D9, 0xF0CA1AE6, 0x4163F085},
	{0x40376B36, 0x5286F203, 0xC52EC3F5, 0x11535D4D, 0xE7D970D7, 0x4F4D3CE9, 0x183D71BA, 0x5E138C51} }  } ,
	 {  { {0x4E73307A, 0xE072A061, 0x7D20048C, 0x7D4E8F77, 0x8A30735E, 0xED539447, 0x5B0E2250, 0x36C26B8D},
	{0x536B5BAE, 0xE0DB5476, 0x006681D3, 0xD8FD08AF, 0x2FA40C95, 0xEF165C26, 0xD06AEA62, 0x5A779737} } ,
	 { {0x7BB41CDA, 0x3BDD078D, 0xB7514A09, 0x76A9453B, 0x1E4DE4CE, 0x6B84B951, 0xFC1ACFA0, 0x29A99357},
	{0x2E90BF07, 0x637B4A7E, 0x64037E27, 0x6132EC45, 0x36086561, 0x79FD77EF, 0x6111EE62, 0x553BC431} }  } ,
	 {  { {0x78541B04, 0x3016A334, 0x71D814F6, 0x6898DBFA, 0x549E9E1E, 0x9282861B, 0xB56A1F82, 0x68E461B1},
	{0x9D5B8FF7, 0x091745DD, 0xFA004970, 0x75815208, 0x39C78B39, 0x6A2AADCC, 0x3DD47D35, 0xB77684B7} } ,
	 { {0x0338CF78, 0x4BC97B5E, 0xA2EFB39E, 0x401ED184, 0x4E9445C3, 0x37B6D5A2, 0xAE587396, 0x1EF7BA99},
	{0xD2040BC1, 0x982DF3FB, 0xCD9F6789, 0x89D02AA8, 0x9AFB802C, 0xD7F0E4C8, 0xE38DE5B4, 0xB094CE2F} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5892 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5893 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5894 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5895 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5896 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5897 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5898 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5899 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5900 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5901 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5902 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5903 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x48DAF16D, 0xC1BE2E93, 0xFDBA3BE9, 0x1CED10D5, 0x5407EFF0, 0x63EC2F5D, 0x62741008, 0x16DF3C19},
	{0x18B6E231, 0x9919FA7B, 0x2667AD2C, 0xC39186B2, 0x356B4BB7, 0x7F9D86D0, 0xB06FC99F, 0x03FA1053},
	0};
		static const ecpoint_fp2 var_b = { { {0x21312962, 0x59037359, 0xBFEA975B, 0x16B0F953, 0xE59AA2AF, 0x9D11A664, 0x0FDB9A53, 0x4C9C4A5E},
	{0x8566A100, 0xF5869CB0, 0x1930AB7D, 0xA1BF4B88, 0x3E70F582, 0x294486A5, 0xA66170A0, 0x3F08B316} } ,
	 { {0x9685A003, 0xCF032116, 0xFE3FC27E, 0xC9AB8A20, 0x651F6C32, 0x6123D99F, 0x36186812, 0xA23A35BD},
	{0x66CE7AA0, 0xC7EC81D0, 0x65CB827B, 0x961534B5, 0x80ADB6B9, 0x680A5788, 0xE6A3B1F3, 0xB45FE0E1} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x49DB4C9F, 0x0894F8EF, 0xC10F08E8, 0xD2D0C803, 0xEBE7FC7E, 0x739A4007, 0xFCBAADBB, 0x1685F62B},
	{0x44A9907D, 0x357E0541, 0x2B96D1C0, 0xCFBF228D, 0xFFA884A9, 0xEA938F2B, 0x5FCF7AAA, 0x075FA3BA} } ,
	 { {0xE66BDC1D, 0xB0240E72, 0x70327345, 0x83919797, 0x2BBB58FA, 0x5BFB1572, 0x6ED29E81, 0x825E4403},
	{0x57F3D143, 0x640299B6, 0x7AD1A022, 0x51D5723E, 0xF9BD840A, 0x5C7F807B, 0x1B5E77CF, 0x882B4CB9} }  } ,
	 {  { {0xA34FFD0D, 0x25968C25, 0x5748A409, 0xDDF185CA, 0x4E9BC859, 0x141B6340, 0x2D855FA7, 0x2494CDCE},
	{0xD70CD20E, 0xB6434EA3, 0xEF3881FB, 0x8C4466B5, 0x5C2ADF28, 0x7F289248, 0x479B0A49, 0x687DB02A} } ,
	 { {0xBEFAEF2E, 0xA43F5021, 0x4355DD1B, 0x44441384, 0x49BE55F9, 0x2DEEDB6B, 0x998F6076, 0xAAAA5291},
	{0xBB7C23B6, 0x83705704, 0x2015419A, 0x4872D2F7, 0x9E299ED6, 0x261AA28D, 0xB5269847, 0x0404E2B9} }  } ,
	 {  { {0xE0B3E3CE, 0x001BF9F2, 0x53AD8CCE, 0xAEC0D593, 0x2CABD4B5, 0x5439B2AE, 0xC8D99AFA, 0x6411049D},
	{0x827E63BA, 0x3CB35499, 0x1504B2F2, 0xE3D5723B, 0x977CA630, 0x2C8B12D3, 0x8FCA9EFA, 0x29FE9D3A} } ,
	 { {0x33490B5F, 0xF3AF8C73, 0xDB736A2A, 0x36AF4964, 0x54018481, 0x0E32C084, 0xE4A75D49, 0x4BEF0047},
	{0x1BDE9E9E, 0xAEABA1CA, 0x5E044A3F, 0x07B73C81, 0xD1845946, 0x379DD05A, 0x19B3066F, 0x39B0EF5F} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5904 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5905 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5906 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5907 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5908 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5909 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5910 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5911 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5912 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5913 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5914 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5915 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xBE4E2B91, 0x97EF46CF, 0xDDD43470, 0xCD4869C6, 0x83FCC997, 0x713F0464, 0x4F05406E, 0xB17F8E07},
	{0x3EC86669, 0xDD65AF41, 0x63FD4013, 0xC1CFC289, 0x1C95E665, 0x4C1AA230, 0x52166AF1, 0x6D1FC727},
	0};
		static const ecpoint_fp2 var_b = { { {0xCF060BF4, 0xE7151648, 0xF1470BD8, 0xB6419C04, 0x0D600083, 0x615FD50E, 0x2B4CA137, 0x1DBCC71F},
	{0x1F58FC41, 0x8BE2E5CC, 0x7FEC1317, 0x1C695269, 0xAEE20DF4, 0x2D9A0907, 0xF2CF33D7, 0x7565BC86} } ,
	 { {0xAA01EBAE, 0x4E15C4A7, 0xCBD606E5, 0x766BDB13, 0x4B8775BA, 0x01641EE2, 0xBD58C34E, 0x13046F39},
	{0x8B2EC45B, 0xF163EC7E, 0x1A5A4974, 0x5E8DD637, 0x1D060584, 0x46FDF82F, 0x64494C4D, 0x60A91866} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x3726568B, 0x1D0D3284, 0x6BD0AB33, 0x97FC8845, 0x3C0B86C4, 0x644DFC2F, 0x2219F715, 0xB7C17C4B},
	{0xDE362F17, 0x824F01B5, 0x6ECADD28, 0x5F86EE72, 0xF5191F24, 0x251D3B70, 0x41909A87, 0xB5760F56} } ,
	 { {0x02EB66DB, 0x65AD0A25, 0xFCD8B477, 0xC5C65EC8, 0xCEABCD1A, 0x1BB5A13D, 0x605ED9CA, 0xB90A02CB},
	{0x02D5EB4B, 0x42E95E82, 0x04D185AB, 0xD9F3A7F4, 0x3B4DB1EC, 0xC062539E, 0xAEF26EBC, 0xB702BDDE} }  } ,
	 {  { {0x6E9FE732, 0x8C8A9857, 0xD8BB9B79, 0x3E63B14B, 0x86376605, 0x579B9731, 0xABCE5EE3, 0x58845E48},
	{0x6BD1D114, 0x7FAF528B, 0xE044723C, 0x6F0F04F9, 0xF4354363, 0x4A15BE35, 0x5D4D9FDF, 0x3DB5AB70} } ,
	 { {0xAC85C395, 0x8A70D4EB, 0xEA8877CF, 0x4747E996, 0x6D9162F2, 0xE968B853, 0x149407FC, 0x4F3F9608},
	{0x5B8400CF, 0xDF00BDA7, 0x45D4D6E4, 0x536EA4BF, 0xFA770E6A, 0xCFFA8530, 0x0F6261EE, 0x6260153A} }  } ,
	 {  { {0x138D2BB3, 0x1847F375, 0x5DA4B12F, 0x8339848B, 0xFFF73DD8, 0x2E0B11A8, 0xC1ED2926, 0x4DB69958},
	{0x1911E61B, 0x75BD4242, 0x540E8352, 0xD3AC473C, 0xCC1A5C0D, 0x0BDD956A, 0xE57F9796, 0x5BFFE28E} } ,
	 { {0x68AA3152, 0x99ACA4CD, 0x2751B99E, 0x1C938B3D, 0x257E4917, 0x964094C9, 0x8BA039AC, 0x3398777A},
	{0xC0109811, 0x579FE4DD, 0x05CBFE93, 0x5B9F4B2F, 0xF9D7D4B7, 0xB67A3C6E, 0x9691E838, 0x88270819} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5916 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5917 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5918 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5919 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5920 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5921 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5922 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5923 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5924 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5925 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5926 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5927 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x543E0F71, 0x4A303258, 0x50C0A944, 0x9D8D0172, 0x7249EB87, 0x6E978A89, 0xA84B9EE8, 0x3A12AD9B},
	{0xFB8A10F6, 0x622EF303, 0x7860C1DF, 0x0473C6EB, 0x4BCEAE48, 0x9A4248D6, 0xA3CA4268, 0x9290BC82},
	0};
		static const ecpoint_fp2 var_b = { { {0x7B72A0A1, 0x66100C81, 0x5E1AD0C9, 0x860778BC, 0x5E1C9F83, 0x6AF51F7E, 0x1C4A706D, 0x3C3DE281},
	{0x78EA6CDB, 0xDD02BCE0, 0x3AF20DFC, 0x8AEA15FE, 0xBE4FCF6A, 0xC4D7179D, 0x955299BE, 0x9D39ACC2} } ,
	 { {0xCFD891FD, 0x68BF289B, 0x1CF7026C, 0x72D5E1FB, 0xD59A2080, 0x2C30A5CB, 0x8AF32E2F, 0x0EEB2348},
	{0x593FC0A2, 0x2C0E91B7, 0x34F9BCBA, 0xF8AB63C4, 0x0210F9A4, 0x6A0161D0, 0x9EEBC403, 0x2C1B1A7F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x23C99078, 0xCA317629, 0xF6220601, 0xABBA1270, 0x1FB1F4EB, 0xE62A0D93, 0x8EBB9954, 0xB25B01B9},
	{0x1017BEA0, 0xC761C31D, 0xB7D7C785, 0xF6B648FF, 0xC6B8252F, 0xEF47252A, 0x066BA94B, 0x6D894CE4} } ,
	 { {0xCB564B6E, 0x508FD587, 0x815CFB4B, 0x309AC258, 0xD4B12B21, 0xCB9F28C1, 0xF996BF10, 0x6151E4DB},
	{0x2B797EEC, 0x608A6225, 0x726C5531, 0x4952CA92, 0xD36A8FC9, 0xCE698E5D, 0x14F6D447, 0x38629BA9} }  } ,
	 {  { {0x27A7D041, 0x95B71E27, 0x0F941373, 0x004937FA, 0x8DFA9073, 0x9D028764, 0xE5619639, 0x1294A13A},
	{0x96E41451, 0xA228040A, 0x6C405DA3, 0x57B98E3B, 0x57F49385, 0xC7696A17, 0xE46E9D79, 0x52BE93D0} } ,
	 { {0x7DE13FEB, 0x68027193, 0x17E6B658, 0xAD342D78, 0x615F8F28, 0xB3C15C5D, 0xB22B0BBE, 0x62E2BBD9},
	{0x0A33F36E, 0x79D15306, 0x52A0F687, 0x47F817F5, 0x49C115B0, 0xC8A4E730, 0xD462FF8E, 0x9C27E7CD} }  } ,
	 {  { {0x4BAB5A2D, 0xF30165A0, 0x0B286D75, 0x3678F12F, 0xE392285A, 0xB21B6F92, 0xAC8A2ED4, 0x33A7D872},
	{0x74A5D383, 0x4FFD35EF, 0xF4DD7802, 0xAD0E252A, 0x5F91238D, 0x239D6459, 0x0C8A1524, 0x94F562D2} } ,
	 { {0xF2D56FC0, 0x3A3D1071, 0x3CA98453, 0xFADA9C30, 0x307A8904, 0xB7BB66CD, 0x18A10498, 0x8C7DA24B},
	{0x87D3FE45, 0xDDFB665D, 0xFEF360A1, 0xF4E6EC95, 0x8EF608AB, 0x434A0804, 0x10904CD5, 0x929F4CD5} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5928 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5929 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5930 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5931 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5932 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5933 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5934 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5935 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5936 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5937 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5938 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5939 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xFB39130E, 0x0543A436, 0x409B2352, 0xA186ADDC, 0x7D652C17, 0x21A790D2, 0xCFA031FD, 0x445F2CEF},
	{0x1D6D5156, 0x17165D61, 0x2D49131E, 0x2285B251, 0xFF61A5C9, 0x10B46391, 0x197C95B4, 0x820D79F8},
	0};
		static const ecpoint_fp2 var_b = { { {0xB76FBD94, 0xFB5EEDE2, 0xA5DA6BB6, 0x8DA98043, 0xDF3334D9, 0x64973F94, 0x77E00916, 0xB2024D71},
	{0xF6921BC7, 0x770CCB42, 0xBCF34F48, 0x63CC7DD8, 0x67F6329D, 0xE202014D, 0x41C9E6B4, 0xAEDBEBD3} } ,
	 { {0x946B11F2, 0x35C4E0F1, 0xC4D7AFA0, 0x010D581E, 0x93F8CD7A, 0xAF339B05, 0x1E3F6136, 0x653D5148},
	{0x5C81B029, 0x6251FA31, 0xAA9107FC, 0x6BFE4495, 0xCBB41D32, 0x0DAD97C8, 0x03F98427, 0x1E56468D} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x395807F4, 0x7F821DAB, 0x96D291F0, 0xF7963967, 0xAE1D50FB, 0xD311D3CD, 0x603FF94C, 0x0E512FE8},
	{0xBE560F62, 0xC1F63A20, 0x611DCC24, 0x2D3BC6AE, 0xF64F994B, 0x333D11F7, 0xCD9A23D3, 0x5F27CB64} } ,
	 { {0x57E888DA, 0xE8F4DE19, 0xE81C6D85, 0x8951697C, 0x9E070CC4, 0xD1F4B7CD, 0x35856D3C, 0x9554E908},
	{0xF039F41E, 0xAF8283E1, 0x4BC36AAC, 0x75C26E3A, 0x427C96D6, 0xF0A709E6, 0x658F187F, 0x59433334} }  } ,
	 {  { {0xFD89FC75, 0xD520D6C3, 0xD7A6D010, 0x89D391C0, 0x228A67B8, 0x7A75B417, 0xE5D23E5E, 0x9390CE30},
	{0x5CB2E26A, 0x543264BC, 0x02047934, 0x4ADDA6A6, 0xA8C36157, 0xF02D029B, 0xF7344CA1, 0x041AE556} } ,
	 { {0xDC6F790F, 0x7AB03582, 0x1FB1B675, 0x6FBBEEF7, 0x4A872FBB, 0x1E1948F6, 0xB68C610A, 0xA5A6F7FA},
	{0xC9C1DE8C, 0xE5DF5B89, 0x2E829D88, 0x67835F84, 0xB2F020C7, 0xFB902334, 0xAB9DFF88, 0x01B6F81E} }  } ,
	 {  { {0xECEFA660, 0x6BE25661, 0xEDB65578, 0xA40EB5FF, 0x4745F25C, 0x9A5C3420, 0x35D4BC39, 0xACA9E6DF},
	{0x237EEDFE, 0xFB2D79C2, 0x971D025E, 0x1F78902D, 0x92573B04, 0xF30FCF84, 0x7CFAD85A, 0x6772EB08} } ,
	 { {0x56CD94F4, 0x6A3FD8E9, 0xD76D0324, 0x832A893B, 0xB19417D1, 0x86BDE14B, 0x782FA46D, 0x380B7451},
	{0xFF42FD2F, 0x30D3C97A, 0x6E321790, 0xCECF5EDF, 0x2AA234C1, 0xB6313FC9, 0x469DD850, 0x93799BC8} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5940 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5941 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5942 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5943 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5944 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5945 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5946 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5947 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5948 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5949 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5950 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5951 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x377A8D9A, 0x7964E15D, 0x8D325062, 0x885A1E59, 0x71BF2F62, 0x570AB53D, 0xB37F35A2, 0x05807687},
	{0xA1668D81, 0xFED02E78, 0x03621ABC, 0x1D4B719D, 0x4DD3E51C, 0xC9EB01E2, 0xEF193238, 0x7171B83E},
	0};
		static const ecpoint_fp2 var_b = { { {0x1AE8CEAE, 0xC673F12A, 0xDFD30D27, 0x17100592, 0x01879753, 0x17E54DAC, 0x98DEA43E, 0x698B1B4D},
	{0x51EA8469, 0x3AFC8550, 0x3E57AF31, 0x65BE47AA, 0x04B48AB1, 0x194159F7, 0x2F862D08, 0x3707C036} } ,
	 { {0xAFC1DB79, 0x615A5F37, 0x9136AA43, 0xF7760973, 0xCB225440, 0x15196A11, 0x562BFCD0, 0x62AF43EB},
	{0xF96ECB7B, 0x941FFA4F, 0xF29A55D2, 0x08AC071A, 0xD133D45E, 0x1FD19CB3, 0x88218168, 0x938E67A3} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x58FF1977, 0xDEF53CEF, 0x03BDF154, 0x1559B7FF, 0xBBE8B4CB, 0x3A27FE7A, 0xFEFB6CE9, 0x3DEC8BEC},
	{0x09A687CF, 0xAA7A591D, 0xBAF8C6E2, 0xBFB23E15, 0xC9E110F3, 0x3975799F, 0x6B1F2A7D, 0x73B82145} } ,
	 { {0x8F726026, 0x5FC4E8C6, 0x934E768C, 0xA0504417, 0x44EA8DA9, 0xF6563496, 0x57CC376F, 0x170CA83C},
	{0x211CB01D, 0x52B7BF3E, 0x2209EE62, 0xD25743BE, 0x5B074050, 0xE135F70B, 0x11328B82, 0x0AE9D4B8} }  } ,
	 {  { {0x52A81003, 0x4BEF0961, 0x9B0BD6CE, 0xEC015C24, 0x3C313F97, 0x08610DB9, 0x880E43EA, 0x78172E57},
	{0x4DFD53D5, 0xA25F1D3E, 0x5C320CA8, 0x04344ECD, 0x16A8917F, 0x1F19F13B, 0x87670A1B, 0x2F93A460} } ,
	 { {0xDB148741, 0xA3A94212, 0xA99F5085, 0xB09581B4, 0x35F6BF69, 0x2A2DEB46, 0x4359F227, 0x9AE9E0AA},
	{0xE940C7A0, 0xE49AB40F, 0x27703C91, 0x6EC8454F, 0xF1D39677, 0xF4952B32, 0xD7A95729, 0x3CC6E74F} }  } ,
	 {  { {0xD14774B4, 0x49F1AFF9, 0xE3139C01, 0x19A33963, 0x41BAF42B, 0xF9B49515, 0x24A4420A, 0x8B4A993A},
	{0x07A1B4DD, 0x0BFEDEAA, 0xF8ECD96C, 0x1A7B9B6B, 0xDAD4900C, 0x813C3819, 0x44D3B9D5, 0x42AA8FE2} } ,
	 { {0x7FD335BD, 0xFA80E432, 0x05EADC9F, 0xE3F861EA, 0x5916F5D4, 0x98DC1CA7, 0x45DC7DFD, 0x0E13A80B},
	{0x23BFBEC4, 0x1C47892A, 0x7E1CBB34, 0x3C4F447B, 0x8168CB9D, 0xD5D1FE42, 0xC89DE92E, 0x83106CB8} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5952 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5953 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5954 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5955 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5956 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5957 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5958 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5959 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5960 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5961 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5962 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5963 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x6803DD00, 0x23212580, 0xFE521222, 0x0FBABCEE, 0x86FCF620, 0xB378B314, 0x31EA2A1B, 0x5D356A2E},
	{0xECF283E7, 0x4C2DC768, 0xFCB945D3, 0xCF3705FD, 0x87745D85, 0xE5DD34FA, 0x3012C223, 0x45CF4176},
	0};
		static const ecpoint_fp2 var_b = { { {0x7EF269EB, 0x45C80F34, 0xBC6D997C, 0xB8D47E70, 0xCE862867, 0x0692BCD4, 0x116F794D, 0x4E398A4F},
	{0x4A4A4184, 0x0A4374F2, 0xC4CEEFF8, 0x9CC759B5, 0x55861DBE, 0x6F96BC27, 0xD6E90428, 0x2151F280} } ,
	 { {0xB9AE3136, 0x5EA26BA8, 0x5590D1E7, 0x5344A662, 0x68D6298C, 0xEA8BD0A9, 0xCBB22FE0, 0x93FC34E5},
	{0x00A38B4E, 0xE5562C7F, 0xCFBDDD61, 0x65662A27, 0xE84BEF0E, 0x08B4AA60, 0x021DA0BA, 0x7DA0BD34} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x9ED983F4, 0x62436E49, 0x0F045097, 0x62B6D9B2, 0x5AD5F013, 0xA6E7E494, 0x42CAF312, 0x8AAF7293},
	{0x3FE3439E, 0xDD628024, 0xF63AC5C9, 0x2B1243EC, 0x3207D04E, 0xDC8FCD2F, 0xA6949556, 0x1CFBC94F} } ,
	 { {0xECE3A847, 0x6B7DA169, 0xF237DF22, 0xBEC87807, 0xBB36B4FC, 0xE46C0E71, 0x79668C3D, 0x680297D0},
	{0x6B849559, 0x0325DD3F, 0x55AD8579, 0xA44BD69F, 0xA1587410, 0x6F4BF4FE, 0x214ACAED, 0x8A2AC0A6} }  } ,
	 {  { {0x5E9E27BC, 0xE4D74917, 0xB4511A0D, 0x1DC8355A, 0x6DE9E373, 0x17B16EC5, 0x8D793061, 0x26E98AF8},
	{0xE6C3D2F0, 0x01B9F452, 0x56854E2E, 0xEABE876F, 0x263BEDAA, 0x010A0448, 0x0F118BDE, 0x3C6853FB} } ,
	 { {0xFC27213C, 0x3F3B5321, 0x7D0EE808, 0x055836A5, 0xE78C09E6, 0xED767F0B, 0x55FA10C0, 0xAD48F93C},
	{0x8BF645B2, 0x2C9542BD, 0xA771448D, 0xA706AC89, 0xDB832903, 0xD60205BE, 0x5B5F497D, 0x2736DC73} }  } ,
	 {  { {0x6245BF8D, 0x7F04C9CA, 0x7EA4AFA3, 0xC42B0D79, 0xAAF8D88B, 0x11A51BF9, 0x653AE7EF, 0x70DCF1F1},
	{0x872E7309, 0x5BA3D2C8, 0xC21657C8, 0xB7ADD8E9, 0xDE46AB2C, 0x402BFCE6, 0x8F3C03F7, 0x825E7E1F} } ,
	 { {0x95ED33CB, 0x64E50AC3, 0xA17B7B64, 0xC9B67EA9, 0x53211CFF, 0x8F9471C2, 0xB7374CC5, 0x1E5C90D7},
	{0xA536A413, 0xFAD3EAB1, 0x9D01FD5D, 0x8749602B, 0x606A3272, 0xF243A3E8, 0x47D1FCE6, 0xAC344018} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5964 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5965 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5966 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5967 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5968 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5969 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5970 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5971 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5972 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5973 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5974 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5975 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x91DD0079, 0xE27EF42E, 0x7C9C579A, 0xB2A1AD01, 0x3EC4C749, 0x730D57B7, 0x751662C0, 0x26EC3994},
	{0xAD9E710A, 0xADFA6241, 0x8FF83D6E, 0xFEF5C3D6, 0xF86322B9, 0x6BCABA94, 0x1E863991, 0x1159A2B3},
	0};
		static const ecpoint_fp2 var_b = { { {0x71ED7852, 0xF992C630, 0xCDBD43B4, 0xFB4CDA92, 0x10516102, 0xF342CEE8, 0x8201063C, 0xA11E8C52},
	{0x543BE990, 0x08336D2F, 0xE64C1C7F, 0xA888A934, 0x307C67A4, 0xB175F94B, 0x3C858DCB, 0x0BDDB220} } ,
	 { {0x36C62E5C, 0x612B1D68, 0xE69DC3A8, 0x005A6856, 0x7FA33EB1, 0x05290397, 0x438C7602, 0x02C579F1},
	{0x44D61C40, 0x0F3C5087, 0x71A67E32, 0x26D1FDA3, 0x216CABB7, 0x03695E33, 0xB2262F8A, 0x3BC965AC} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x88C93E73, 0xEBC5253E, 0x4C56BB9B, 0xDFF7A3B8, 0x8ECCFE4D, 0x01808254, 0x3D0890AD, 0x969B3DA8},
	{0x42F5152A, 0x5F844FD8, 0x2FA37426, 0x93BC0957, 0xE2A30471, 0x92F37C84, 0x644AB949, 0x3373AB6D} } ,
	 { {0x0449C82B, 0x40A6153F, 0x34A960B7, 0xA28C3C8E, 0xFCF7E39B, 0xD8FF99B7, 0x70CA3F4A, 0x266E4A29},
	{0x462F3708, 0xD6CE63F9, 0xC9349ADB, 0xFA384078, 0x1269A1B2, 0xF44F11D0, 0xAB93DB6D, 0x7DA5ECD2} }  } ,
	 {  { {0x0B62EDA6, 0xBA962FDC, 0xA25B5D0E, 0xDF6EB630, 0x4E1FBAA4, 0xB8BEB5A8, 0x80E91CFC, 0xA7370585},
	{0xF67EE748, 0x24D1F84B, 0xDE6E428E, 0xF86335D6, 0xA36D51A9, 0xC051EF30, 0xCBED8E9C, 0xB0425A42} } ,
	 { {0x8C05783A, 0x7D329423, 0x131F3530, 0x032A4C42, 0xA249EDD9, 0xA3E66F6B, 0xAD501324, 0x33260B12},
	{0x4AEE196B, 0xA2442A17, 0x26963CD7, 0xCC4DEA0F, 0x724F7D45, 0xC56A75B6, 0xAF26B1FF, 0x5BE0F54F} }  } ,
	 {  { {0xA1A48AFF, 0x2EA899F9, 0x9FC840C1, 0x2A8C3E80, 0xC99B7C28, 0xD6E764DF, 0xE8A7B379, 0x66A7B3B5},
	{0x2914224D, 0x6EC1246A, 0xFD156A69, 0x799C98D4, 0x5A6C9C2B, 0xD4F73549, 0x7B6851A5, 0x2DD27F79} } ,
	 { {0xB640DE9A, 0xB3653DEC, 0x7EBEB90D, 0x9C99C88D, 0x782E3997, 0xA1E4DE18, 0xDD1A795C, 0xB4A36F3A},
	{0xC36AAAC0, 0xE14F419E, 0xB85F90C4, 0x7057839F, 0x2B7E09BC, 0xCD5C54BC, 0x06830B51, 0x499159D9} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5976 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5977 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5978 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5979 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5980 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5981 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5982 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5983 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5984 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5985 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5986 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5987 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x825A04B9, 0x002C1AC1, 0xBCA39243, 0xAC9F2638, 0x99F0B2BA, 0xB4FC56EC, 0x20F9F7B3, 0x94707A44},
	{0x98491722, 0x1A2D31DA, 0xF3EF2856, 0x4D470844, 0xBC48DF50, 0xCE249E6D, 0x0D0F031E, 0x377F16F3},
	0};
		static const ecpoint_fp2 var_b = { { {0xE54B0B1C, 0x36EB8746, 0x7AE6022E, 0x1BFB2173, 0x8FBDDE43, 0xF0E0086F, 0xF20CC016, 0x2E772C77},
	{0x925BC646, 0x58D41416, 0x0A47DFDC, 0xE00B4201, 0xF68FFB75, 0x8B7DAAC3, 0x426BF452, 0x61A50FC6} } ,
	 { {0x5E3679F2, 0x7A79625D, 0xB47D1094, 0x497EC4F5, 0xC3410C26, 0xB2FB2E6B, 0xE64A918E, 0x0A0CCE88},
	{0xFED5ABB1, 0x8A622BF6, 0x7AF41287, 0x4DFD9A33, 0x83D64689, 0x713A4D46, 0x0C67098C, 0x05B98D48} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xEA1490C8, 0x8DE5686D, 0xAD8327E3, 0x67143074, 0x128B636E, 0x743A0CBD, 0xE79B57B0, 0x6F63BD17},
	{0xC4F96D29, 0x4208580E, 0x5D3FDF6C, 0xBB30A9D2, 0x7034EE63, 0x3A2C8699, 0xA35143B4, 0x0A8BC7C9} } ,
	 { {0x8281DA83, 0x0CD6BDC8, 0x5D235B0A, 0xD84B5CD4, 0x23BB3E01, 0x84A5A0BD, 0xF05EC9E6, 0x2D323A7B},
	{0x1081371F, 0xE4E44951, 0x15754386, 0x3D39D399, 0xBCE3D869, 0xDF90038C, 0xB7279BEE, 0xB2F1F44E} }  } ,
	 {  { {0xFE628EBF, 0xC35738A1, 0x187619D6, 0x5A3A0839, 0x5B7BF6CA, 0xCFC20838, 0xEA37836D, 0x7C358E45},
	{0x856859FD, 0xBFEC304A, 0xA0C01BC5, 0x90F0B45F, 0x8443B0DE, 0x1F2FC0C9, 0x909A6D97, 0x55A32988} } ,
	 { {0x299FE4E0, 0x498C855A, 0xC9E61D32, 0x3B3EBE28, 0x93CB6134, 0xE1C28208, 0x93A46BB0, 0x72B20E3F},
	{0x03315F7A, 0x0ABD6052, 0xB18616FF, 0x15423607, 0xD87AA4A0, 0x9D76006F, 0xA08E9C5C, 0x7CF3EBE9} }  } ,
	 {  { {0x8D4DF5E9, 0x429B7B0C, 0xA3B2F9BB, 0x58175D1C, 0x04AA8370, 0x1FF3C56F, 0x2355867D, 0x77547803},
	{0xFEA1E663, 0xD7AD9EDA, 0x1F38A5E2, 0x243C303D, 0xCA402638, 0x4EE40736, 0xB1AA1CC4, 0x4E9F8AA7} } ,
	 { {0xA76380ED, 0xD9C5356A, 0x91FD55E1, 0x93BE9E9B, 0x50043DA0, 0xADAED995, 0x9DC3869A, 0x1EB2E170},
	{0x4E0880D1, 0xA4650E0A, 0xE44C3408, 0xD27806E6, 0x57FF402F, 0xCD9E9BAE, 0x9B0EBF03, 0x2F50E2E4} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 5988 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 5989 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 5990 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 5991 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 5992 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 5993 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 5994 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 5995 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 5996 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 5997 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 5998 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 5999 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x2D1E0175, 0x4B26D169, 0xB6DCFB6A, 0x59D622E6, 0x6290AF22, 0x7C20D229, 0x126E3C1A, 0x89BCDEAB},
	{0x4C2BC261, 0xE917A5C9, 0x918EC5B3, 0x2D9B79EF, 0x2FE771FB, 0x250ECC33, 0xAB97A208, 0xAF6FEAD7},
	0};
		static const ecpoint_fp2 var_b = { { {0x3F3DC86A, 0x14142FFC, 0x84DEA4AB, 0xD752CEE4, 0xE2D05BCB, 0x75490150, 0xC3E005EE, 0xAC225EC9},
	{0x9D80516B, 0x3FA80A8E, 0xFF85E91B, 0xDED70734, 0xB08DF7F6, 0x4731DD38, 0x97B32CB1, 0x8EB23353} } ,
	 { {0x6B99AFF0, 0x6AAFDE1A, 0xCE23CEA4, 0xE12E3336, 0xBA3F8786, 0x28940AF9, 0x053ADF78, 0x5D9DB686},
	{0x6FE07AB8, 0x8300592A, 0x0353B6D1, 0x6D519084, 0x4AC55BCD, 0xE642CC34, 0xED5C1FDF, 0x1C069395} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x9129B0E7, 0xAFA381D4, 0xE78B4782, 0x1DF8863A, 0x694B90B3, 0x54BCB40C, 0x89D44098, 0xAF77E0E9},
	{0xB94FCDE4, 0x4B039759, 0x4C4198EF, 0xC31FF141, 0xF8669153, 0x84CB0E58, 0x310344C8, 0x5EAF4759} } ,
	 { {0xE3B1816D, 0xB9164B46, 0x7148480E, 0xE46A74D3, 0x8E24A5F9, 0xB95D4745, 0xF8907330, 0x39C1CB48},
	{0x9A9BDBFA, 0xA110094D, 0x6420E64A, 0x9F64FD44, 0xE31C7A5B, 0xD0CE0E88, 0xA22A1923, 0x5E547F63} }  } ,
	 {  { {0x874ED10D, 0xE404949A, 0x962B072D, 0xFF46D9C5, 0xF8107E4F, 0x247C1B70, 0x516E62F9, 0x1B40E698},
	{0x3E220C8B, 0x0F25E164, 0xBAC3217D, 0xB8A2C41F, 0x29C82638, 0x71FF6CE5, 0xD333D85D, 0x8F2AA179} } ,
	 { {0xEFAAF54C, 0x8364BCB6, 0xFF091099, 0x6F65A1C4, 0x8B55A9C7, 0x8B4F1A49, 0x1E56286F, 0x2E4625EE},
	{0xC8CBF3FE, 0xF33D0112, 0x8311C580, 0xB4239654, 0xB980FFB6, 0xFAF970CD, 0xA45B3523, 0xA040FC42} }  } ,
	 {  { {0x13450810, 0x80688CC8, 0xABB3E226, 0x243B308C, 0x711E539E, 0xC00A06F7, 0xE0E0EC6A, 0x3865DF44},
	{0x51FC3808, 0xB0B56FA9, 0xE8D8A7F6, 0x830E32CC, 0x8FC9F4D9, 0xE86C49AE, 0x45497E10, 0xA171785E} } ,
	 { {0x0372B629, 0xEA94CCF1, 0xF0AA81B4, 0x8002DFA4, 0xC7502B1A, 0x9ED65D77, 0x6E91F346, 0xAC3CF27D},
	{0x89ADFF5D, 0xB89EDB02, 0x52A60451, 0x8779C967, 0x09B741C8, 0x05B7A144, 0xFA6FA3C1, 0x9F461FE9} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 6000 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 6001 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 6002 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 6003 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 6004 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 6005 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 6006 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 6007 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 6008 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 6009 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 6010 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 6011 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x20783104, 0x96D13A44, 0x90664C80, 0xB3B1AD31, 0xED95B60B, 0x244EF96E, 0x91FAB36A, 0x80AE5516},
	{0x88C4C966, 0xD0113C73, 0x3300A99B, 0xFEB93482, 0xEC00EFAF, 0xD4E35D88, 0xDA4EB889, 0x9838B2F0},
	0};
		static const ecpoint_fp2 var_b = { { {0xEB2A8C7B, 0x592A9A72, 0x74429D78, 0xAEEB0E80, 0x91B24F23, 0x8FFE2D4E, 0x4EEB1FCC, 0x2BB0422A},
	{0x36A70D79, 0xAFF29550, 0xF03B7139, 0xA894CEB3, 0x62F3CEA4, 0x6188BBD6, 0x52728E7F, 0x0CFDFD1B} } ,
	 { {0x9EEDD29A, 0x75B06389, 0x01D67759, 0x5FE371C8, 0x72E266E5, 0x3F43A4FE, 0x104591DE, 0x0FAE1A7C},
	{0xCC1D083F, 0x2CE17E1F, 0xC6F682E0, 0xDADA4AB3, 0x6652DDB2, 0x625E361F, 0x34BC972D, 0x45A7071F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x3C70AB0A, 0xAA44C80C, 0x025313AD, 0x35287ADB, 0x2270F0D8, 0x45778605, 0x0FEA75E1, 0x0DDDA4BC},
	{0x19141EB8, 0x22CFAA08, 0x589F34E1, 0x0B58D0EE, 0x7CD84E67, 0xAC363332, 0x7A37C336, 0x134E3C9F} } ,
	 { {0xFC47609D, 0xD57E1646, 0x785E7B76, 0xB256AFEE, 0xBCB7482D, 0x9EE0AA92, 0xF9357FCF, 0x542958FD},
	{0x1F2B967C, 0xF086AB0A, 0xE6817140, 0xD7CA1E0A, 0xF05BD58F, 0x2B2C2EAE, 0xFE0BD42E, 0x73C9E876} }  } ,
	 {  { {0x4339D9DD, 0x9C84EE94, 0x9F6ACDAE, 0x1479033E, 0x4831563C, 0xF1A6AB79, 0x2A977D5D, 0x5697E5F3},
	{0x55D7B81B, 0x1838F212, 0x7C7EEC0D, 0x934A595D, 0x6CACB505, 0x5FCF207D, 0xE34F5BE5, 0x3E43950E} } ,
	 { {0xB88226BA, 0x9314CE80, 0xC510A1BD, 0x2712DC89, 0x64D2551D, 0x1AE01B42, 0x9A78DA4E, 0x2DCB8A52},
	{0xA7277A46, 0x93113CF6, 0x3FE3F047, 0xD3F1C850, 0x96518723, 0xAE6D4E42, 0x909BC671, 0x5572F9D4} }  } ,
	 {  { {0x00153E5F, 0x90CFEB0B, 0x9828A91A, 0x2BB846C8, 0x79BACE1A, 0x0E450F5F, 0xAD564659, 0x602E046A},
	{0x01B637E3, 0x9242A1B2, 0xD961EB8E, 0xE54A059D, 0xC3822F4F, 0xA970CBC5, 0x090B7608, 0x3AE41A55} } ,
	 { {0x68804450, 0x207E10DD, 0x70AEDD54, 0x63470A2A, 0xC5142879, 0x02759E13, 0x2711E0C2, 0x0FA6DD79},
	{0xC1E4217F, 0x4ACB3501, 0x91130CE8, 0x102FBDD8, 0x6D6CD56E, 0x58836D4D, 0xCCECB65D, 0x7F817941} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 6012 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 6013 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 6014 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 6015 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 6016 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 6017 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 6018 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 6019 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 6020 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 6021 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 6022 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 6023 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x978EAE60, 0x06FFC635, 0x94C90F7F, 0x6012C642, 0x11F66884, 0x9915DB1E, 0x9262D169, 0x63B179EB},
	{0xBDDCC871, 0xE2591B45, 0xDA7D484A, 0xFF61888E, 0xAC82B999, 0xD4EE8478, 0xFDD740E5, 0x6C283407},
	0};
		static const ecpoint_fp2 var_b = { { {0xDA732B9A, 0x1ED2AD9D, 0x8617A71B, 0xD42DCD25, 0x2C3A782F, 0xC1760C2F, 0x6960468B, 0x1D517984},
	{0x5916AD15, 0xCB498258, 0x59D6BE09, 0x50D16243, 0x4E48C824, 0xCF2E8D1B, 0x04960627, 0x7C33D0F7} } ,
	 { {0xF9B472B2, 0xB5105858, 0x970D855A, 0xBC28DC98, 0x1B448C8A, 0x269A205C, 0x621CCE05, 0x1347DB71},
	{0x8422DCEC, 0x2C81EE42, 0xCF7C4045, 0xF76529F1, 0x4F6A85E8, 0xA0082D95, 0x8108BB0D, 0x9C048802} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x005752DC, 0x34FCF3E1, 0x6F8FB5B0, 0x6782484A, 0x0EE7C39F, 0xE455252F, 0xF5F8CE13, 0x3A19A8FA},
	{0x20F25806, 0x94C00381, 0xFFCED2FA, 0xE9E9D0C4, 0x8F54C90F, 0x5443C3D0, 0x9FA5E234, 0x3DF89D87} } ,
	 { {0x30A361ED, 0x5134697A, 0x7E0E5D5F, 0x57F7089D, 0x0D0CD088, 0x3CAA8E61, 0x137C7D92, 0x4323D602},
	{0x9106A43A, 0x5EE28631, 0xD7F4D444, 0xEAA8E623, 0x02DA3AB2, 0x70720EC7, 0x40C612F3, 0x029AB08B} }  } ,
	 {  { {0x502EA6F7, 0x692F76B1, 0x51AF5E25, 0xFF84D4E8, 0x17767615, 0x79D1A80C, 0x7A81F7C5, 0x57BB5E3B},
	{0xB691EC1C, 0x9B833140, 0x284FC224, 0xFF367BEE, 0x15ACC7D7, 0x9C8B8503, 0x26B88896, 0x458396FF} } ,
	 { {0x3CB4EA7C, 0x48649C0F, 0x9D81E6F1, 0x2241CCA3, 0x8CFA226E, 0xCF8E0763, 0x9E0654A3, 0x38A89164},
	{0xC96DC447, 0xFD606383, 0x903A515A, 0x4FC2DB9F, 0xCD546B77, 0xB938A52B, 0x2629B9E1, 0x76BA9CE9} }  } ,
	 {  { {0xC4DB1651, 0x0DADA1DE, 0x81BF4107, 0x8086C87C, 0xDA1B02E3, 0xB71FCE66, 0x036108A3, 0x4E2DA5BD},
	{0xB6E4C90E, 0x90991E55, 0xF6C785AF, 0xCD8463B7, 0x1AC0686F, 0xA9E422A7, 0xA05880D8, 0x211EEF6D} } ,
	 { {0x1EECB4D9, 0x324810DA, 0xA4018E00, 0xF6AAB29D, 0xE5FCA9BD, 0x1E163249, 0xDEB779F7, 0x4420FACD},
	{0xE2281F1A, 0x47FBDA62, 0x257E4D94, 0x46236CBB, 0x4037D03C, 0x72EC9D3A, 0xF8FDA043, 0x6B9D0E5C} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 6024 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 6025 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 6026 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 6027 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 6028 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 6029 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 6030 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 6031 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 6032 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 6033 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 6034 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 6035 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x0F4228F9, 0xD6C259DF, 0x92FEA6AA, 0x212CD044, 0x5D9710B5, 0x227CD935, 0x226E51E0, 0x535F02E7},
	{0x1F301BCE, 0xBAC62234, 0x6FFA5B66, 0x6938A648, 0xE20F3ABC, 0x9F486DF6, 0xB21BDF77, 0x2B29E595},
	0};
		static const ecpoint_fp2 var_b = { { {0xAC6D342B, 0x3D400A5C, 0x210FA23F, 0x1E41085E, 0xAAB8F14F, 0x3B0E1A69, 0x0772B793, 0x6F361802},
	{0x83E422DF, 0xB211A186, 0xAE903143, 0xDC3103E6, 0x65D1D878, 0x2CCF8FD0, 0xCE1C637A, 0x0F8ADAFC} } ,
	 { {0x2164D961, 0xAE1EF543, 0xE0210DCB, 0x3205B564, 0x1276E0E9, 0x3E8A91A3, 0x27C231E0, 0x71FE49D6},
	{0xAB985507, 0x1A9BBAEE, 0xD80A1346, 0xDDFFF87A, 0x93B33DF1, 0xDD6A817F, 0x807180BA, 0x8E52128D} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF9331472, 0x265387DE, 0x977B23AF, 0x0D877F81, 0xD32B5370, 0x02747884, 0x602B6572, 0x74D798D9},
	{0x15C133B5, 0x55B5C5F1, 0xA6E0E775, 0x53B2F56A, 0xEF251AFC, 0xCFE05BA8, 0x3CFAD3F3, 0x7696D8FE} } ,
	 { {0x18B2C659, 0xEF8DF318, 0x23A3B73A, 0x44DD6C78, 0x1E3E37BB, 0xF8381732, 0xFD404A58, 0x042169B7},
	{0xDEF42B3C, 0x9BBB41A5, 0x50129C2C, 0x938FF53F, 0xE1F791E0, 0xDABD6615, 0x87118696, 0x48CB0B9C} }  } ,
	 {  { {0xCDA33182, 0xB5C359DE, 0xC1693D65, 0x669D268B, 0xF8DC719A, 0x6DC1214A, 0x98816142, 0x1BD1FFD1},
	{0xADECADBD, 0x6DFB9611, 0x8B63E36E, 0xC177D94C, 0x6CD04108, 0x344DB6EC, 0x31B29528, 0x8748B93C} } ,
	 { {0x9A832994, 0x74CFFE77, 0x426C6EC5, 0x9771620A, 0x748FE2FE, 0xDCA5E888, 0x2276ED46, 0x5F5988EF},
	{0xFF399569, 0x5021EABF, 0x7503A9D7, 0x3A35C095, 0x6443B74F, 0x4CDEBFA1, 0xE6754986, 0x67396518} }  } ,
	 {  { {0xE8690073, 0x1F5D759F, 0x940EFEA3, 0xCBA33D73, 0x283E0FE4, 0x17C373AE, 0x54E228C3, 0x2F0085DF},
	{0xB55147B7, 0xA9BD1F8C, 0xFAB89512, 0xFA372366, 0xB0BA7D4F, 0x564EE617, 0x39C02B3D, 0x43EEF952} } ,
	 { {0x9E333240, 0x91677664, 0xB6D9457A, 0xC48A2604, 0xA2EBFD7C, 0x33DE2968, 0x92EF9B50, 0x7BFF06F1},
	{0x441F5F60, 0xB912286A, 0x4837A8F3, 0x892620B8, 0x37EC15E9, 0x33D54F8D, 0x344E4D59, 0x0DEA1989} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 6036 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 6037 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 6038 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 6039 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 6040 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 6041 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 6042 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 6043 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 6044 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 6045 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 6046 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 6047 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xB38D3E22, 0x1466CE01, 0x3309C5D8, 0x59CF869B, 0xE9D46A95, 0x07CCCFD1, 0x0F675565, 0x82719AC4},
	{0xA11E7B03, 0xA3C28C43, 0xBCF0EDFA, 0x5166CCAB, 0x9185CF41, 0x242307EB, 0x2A3E4584, 0x26671B38},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x0F37B9BF, 0xDDD4BDA7, 0x37990D7D, 0xDF3B94F9, 0x24DFCF7B, 0x3B7E1F6D, 0x110422C8, 0xB9B79286},
	{0x09114A17, 0x865083C8, 0x38E21364, 0xF70BF94F, 0x30D85CF4, 0x60D33D04, 0xC78651CC, 0x03C20F0E} } ,
	 { {0x4514BFBD, 0x5B0A97FD, 0xD92C9EC5, 0x797A9824, 0x4AED3133, 0xC06FEF65, 0x42673373, 0x0F190004},
	{0x7683E2B5, 0x961F6FC9, 0x8920912C, 0x18BC7B83, 0x882D5DB9, 0xD0C0A9F5, 0x385555C6, 0x8BC52867} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x65197380, 0xB569BC80, 0x36EF42FF, 0xE722C630, 0x7BF158F0, 0x410D01AE, 0x5FAEC14C, 0x9D2E5C1E},
	{0x05929794, 0x1E9243DF, 0x9772A3F1, 0xEFEF87AC, 0x826EF563, 0x3A96A4DB, 0x14B3D3D5, 0xA09F0176},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xA3902D1D, 0x2D31E2F1, 0x1936842B, 0xC09DA9CB, 0xB9C5039B, 0xBDC66B59, 0x995789DB, 0x5A22F846},
	{0xB9490299, 0x860C38AE, 0x7CBCECD3, 0x42346711, 0x7D073D79, 0x361C60EA, 0xD05A9FAA, 0x1ACD7BD3} } ,
	 { {0x8E33E396, 0x1E010CAB, 0xD99080C8, 0x8CC28B27, 0x926A3398, 0x2274012E, 0x122EA8DB, 0x1D95ED4F},
	{0xE816A809, 0xECA8BB71, 0x79821C51, 0x25F69271, 0x94902202, 0x22D3AF61, 0xB24099EB, 0xA8D2E34F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x2326C508, 0xDE836D24, 0x8314D105, 0x90EE326B, 0xDA3609A8, 0x93667992, 0xA3AF8C5C, 0x6652F7F1},
	{0x2C7ABE31, 0xAF805388, 0x73D9D6C8, 0xB65295D5, 0xB98DF53B, 0x8C70DD46, 0xF2CF4AA6, 0x801CFA98} } ,
	 { {0xE0E8337E, 0xDAD4F8D1, 0xA11EECF9, 0x29CEFB81, 0x494E1A82, 0x4749BFDD, 0x3DC4D85F, 0x16FE7754},
	{0xF0A257FA, 0x8ED4FBBF, 0x580179E6, 0x3A966C3F, 0x9C5FD16E, 0xD5B131B8, 0x79F46B0E, 0x9BE66E77} }  } ,
	 {  { {0x1C92F5CC, 0x4036DED1, 0x02E81530, 0xE5DD1113, 0x34318975, 0xE66BB9F3, 0x7F85A296, 0x48A07C27},
	{0xC8E32297, 0x1ECB0E3D, 0xDCAC3F52, 0xD8EDA7F6, 0x323B90A3, 0x291FF418, 0x5469E95E, 0x6203C9B8} } ,
	 { {0x63275743, 0x04EC7A8E, 0x159D1B13, 0xAABE6C2F, 0x0E5DD263, 0x40897D88, 0x02C80931, 0x22433E5C},
	{0x571EDED9, 0xB02B89CF, 0x39EA81BA, 0x523BB012, 0x41FFED10, 0x1F55451E, 0xB3E752D5, 0x4AE18F8A} }  } ,
	 {  { {0x9A92F02A, 0xCF0F92E1, 0xBEC965FD, 0x1FB10D74, 0x7FDC59F8, 0xBA84981A, 0x7FEB6820, 0x86CD0076},
	{0x246A727B, 0xCBAED9F3, 0xD1267C62, 0x31B7FE68, 0x82A78B8A, 0x07443B57, 0x4AB1F011, 0xAC0B0CB0} } ,
	 { {0xDD80293C, 0x216CF46F, 0xEA29A92F, 0xE4EE6DF8, 0x534B63F8, 0xC1CF902C, 0x8CA80E6D, 0x4B5D94E1},
	{0xAA5833DB, 0x8DB73D81, 0xD02555B6, 0x8D48D7F1, 0x7D777475, 0xAC8F5C22, 0xB799B912, 0x27E32FEB} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6048 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6049 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6050 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6051 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6052 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6053 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6054 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6055 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6056 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6057 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6058 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6059 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x5CA6C786, 0xCBECA88C, 0xE92B97F9, 0xC063EC26, 0x4924BBCB, 0x5719B7E2, 0xF056F337, 0x81F5DF7A},
	{0x698D601E, 0xBD581ADB, 0x11CBFF2C, 0x8FDB4C57, 0x527BA411, 0xB8EF6C16, 0x7408C969, 0x0D95433C},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xEB44C5FE, 0x6E6AA23D, 0x1F251B8A, 0xBBDE144D, 0x740E4E20, 0x13BDB882, 0xCA7D125E, 0x28497136},
	{0xE14F909F, 0x2E6AB1A4, 0x667966E6, 0x5DC55356, 0xB693A4C9, 0x6A21B9D4, 0x1C63E9B7, 0x1A606D9D} } ,
	 { {0x8920D128, 0x93304F1A, 0x369762D6, 0x456A1EBE, 0x605D3489, 0x1C17596A, 0x2080DE53, 0x10D2CAB3},
	{0x21FED69D, 0x100BD5E1, 0xAE02C658, 0x11B9FBA0, 0x61692399, 0x6766AC56, 0x7CB90CF4, 0x956BDA62} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x1B2E14A7, 0x44E87F98, 0x37397ACD, 0xDFB5839D, 0xD2547BE7, 0xA932EB30, 0xA6695DB0, 0x5554E498},
	{0x4429D983, 0x2AB9A661, 0xA91846BA, 0x6E34842D, 0x7066F3F5, 0x70C0377E, 0x8FF57C2C, 0x7854DC61},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xA90B2F7A, 0xA4423272, 0xB34A75D3, 0xEFD0D692, 0xF0575339, 0x1B4D6F1B, 0xEF1F7498, 0x8AAC277D},
	{0x0A570C57, 0xB31920F4, 0x99D82F44, 0x4161CF0F, 0x2F38A3B4, 0xF4A54075, 0xB21119F2, 0x526A1E32} } ,
	 { {0xBAF306E8, 0x59CB1A53, 0x20D09805, 0x8E261CFA, 0xFC27BFF6, 0x1D4EBF3F, 0x1FD7B5CF, 0x72908544},
	{0xC3EA2DF3, 0x13C37A56, 0xF79021BD, 0x32AA13EF, 0x2F2B70A4, 0x7481C6B0, 0x44FBD7E6, 0x6FECFEA9} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF299FEA4, 0xD466CB06, 0x3E71DBAA, 0x6934FEAD, 0x91665028, 0xBA8B2860, 0xD6776F24, 0x54B99417},
	{0x10FEBBFF, 0xC44FB29C, 0x95D69448, 0xCD3E3C59, 0x8F3A4113, 0x1ED5EF42, 0xF21327A0, 0x96B043CB} } ,
	 { {0xF63D451A, 0x75D11C3D, 0x71889471, 0x39658265, 0xD2ECBFF3, 0x58FF4550, 0x65169FE6, 0x0D4DB308},
	{0x7FE39BF7, 0x2860E79F, 0x2E881F0D, 0x9A8B3F87, 0xC167F7B7, 0xFB773501, 0x7BCC06A1, 0x93B2F769} }  } ,
	 {  { {0x92D87A2C, 0x9C5EFBF3, 0xF19AAB5C, 0x924C0FA1, 0x02242723, 0x4ABD3B54, 0x46746CFA, 0x9E71F1D3},
	{0xA76F02BD, 0x16B7BED0, 0xCE78883F, 0x96375140, 0x3A05F08D, 0xAE15934E, 0xCD238347, 0x3DA8F4B4} } ,
	 { {0x8567C0B7, 0x63764C25, 0x9C6E3CF1, 0xEA54F812, 0xC459617C, 0x473DB839, 0x45460986, 0x4507DF57},
	{0x2456A23D, 0x2B0B0FCF, 0x9E4D6B0F, 0x4AC5D856, 0xBCBFD1E1, 0x3E5B5208, 0x28BC4AA4, 0x553469BA} }  } ,
	 {  { {0xD7D28977, 0x82580CAC, 0xE3D04B06, 0xF3A58264, 0x64E5C0C2, 0xE8984082, 0xEEDEA940, 0x932A84B2},
	{0x178E11C8, 0xE5BAED81, 0xA4271781, 0xF317EA3A, 0xC1D53E1F, 0x21955D6E, 0x709961B7, 0x3FD55B2D} } ,
	 { {0x4A0A4329, 0x95E55016, 0x59F5137E, 0xE63A6ED8, 0xFAF76846, 0x8FD0676E, 0xD8A87F17, 0x3E4A0C6A},
	{0x112B93EC, 0xFD313E54, 0xA4024537, 0xE8556D4D, 0x2E8D5B7D, 0xA0CBB244, 0x8C3EE245, 0x4477644F} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6060 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6061 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6062 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6063 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6064 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6065 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6066 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6067 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6068 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6069 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6070 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6071 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xCCC63CFA, 0xF0847F30, 0xEDE1E49E, 0x7B1E378A, 0x2A7E24CF, 0x7E067FE2, 0xDE9B4366, 0x29F7EC6E},
	{0x317E18AE, 0x53F1E831, 0x85E8E18D, 0x67022890, 0x4CDA1186, 0x67750240, 0xD916A993, 0x7E935466},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xCE232467, 0xD76A63A7, 0xF253C1B8, 0x6D0FF459, 0x4915A501, 0x05E61B44, 0x71BCD6FF, 0x07665081},
	{0x65F3B496, 0xDBA0266D, 0x3C1763BB, 0x172A8D71, 0x66ECC5C2, 0xA38B8F9E, 0x9260CE30, 0x7E539B86} } ,
	 { {0x24AE878B, 0xB00D6A77, 0x8953970E, 0xFCBDD816, 0x77E50EF6, 0x4BF4D4E8, 0xA9188F1E, 0x45D5F518},
	{0xBD8C2C49, 0xBC6103B2, 0x0CF32171, 0xE9A72CE1, 0x4BF3B965, 0x601CB182, 0xF0A4B4DF, 0x303C1835} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x2D2DF565, 0xFE4F4EB9, 0xDA6DA5BB, 0xE787EFD8, 0x83E4E298, 0xC9F252C2, 0x76F3878F, 0x44CAC26E},
	{0xFD6B8D08, 0xD1691153, 0x69FE8A75, 0x0DC1F3F0, 0x875FF34F, 0x27A6A927, 0xF36681D5, 0x95B06CBD},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x15E4BD43, 0x486D9513, 0x138748ED, 0x0BD2BC39, 0x0074D59E, 0xA73B142D, 0x42BFF80F, 0x8F4F11BB},
	{0x35F551A4, 0x2F4E0495, 0x7ACD4AC1, 0x6749D141, 0x01CC2E18, 0x55B5388D, 0xB6DFC86C, 0x56DE5ECE} } ,
	 { {0x8B79E44A, 0xBCBF1047, 0x4E655561, 0xB5E2FCC4, 0x7F061D0A, 0xE1FF8D15, 0x54701A0A, 0x04982250},
	{0xAB5D892D, 0x0522FFFA, 0xA9DF46E0, 0x8ECA5E5E, 0x3F495AAF, 0xC117B9BD, 0xEC321A1D, 0x5F98A5A5} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xFFD5017A, 0xCAD09754, 0x013CBF0D, 0xE80C61E2, 0xD7D0C8FA, 0xCB478A01, 0xB1CCA7B8, 0xA517B935},
	{0x6772B3AF, 0xA33DBF24, 0xDDDF7709, 0xFC535B00, 0x8224A2AC, 0x69B1222B, 0xE1E13CE1, 0x6F4DBCF4} } ,
	 { {0x5C3C0703, 0xD655A6D2, 0xE6E93242, 0x604EB471, 0x0EDB4053, 0x856BEA95, 0x52383DDD, 0x17F3182A},
	{0xEF16DF83, 0x7964AC43, 0x11095BB0, 0xFD8B5698, 0xCFEEC677, 0xE00AE74A, 0x4886E072, 0x94F71469} }  } ,
	 {  { {0xE37B0469, 0xFB121A60, 0xCF8CCA58, 0x3B09B817, 0xBDA81C6F, 0x3332B968, 0x34A63B23, 0x03AC8229},
	{0x8945C48C, 0x067E15FD, 0xFC4B4150, 0x7A214109, 0xD00885AA, 0x15FCB744, 0xCD481F9D, 0x4F98D4BF} } ,
	 { {0x642E0DA6, 0x7AF0BAFF, 0x28F06B66, 0xC68D2CF6, 0x764A1F67, 0x9B22A403, 0xC36D59AA, 0x566EE232},
	{0x228EEBD3, 0x3FE767CC, 0x437171F1, 0xEB78679D, 0x8B59303C, 0xDEB50207, 0x1214DC06, 0x04DA1951} }  } ,
	 {  { {0x74217E8C, 0xF0803243, 0x53F7D930, 0xBB0F1C08, 0xAFE6EFF5, 0x3A375F14, 0x16E6C408, 0xA8F63D48},
	{0xE89B9050, 0xE265C2F3, 0xDB2A5F1C, 0x3FFE3107, 0xBF507C7F, 0x99C1D958, 0xD490401C, 0x84576C42} } ,
	 { {0x41988DBD, 0xEE0B4D90, 0xBC0559BF, 0x3DDE59B7, 0x8CD9EDD5, 0xC0774027, 0x403ECFD4, 0x744D4448},
	{0xD23EDD7A, 0xB2A844AF, 0xC6F3FC23, 0xB4F2F34B, 0x61DDC704, 0x69EA0DEA, 0xD01F01A1, 0x942889F2} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6072 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6073 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6074 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6075 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6076 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6077 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6078 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6079 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6080 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6081 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6082 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6083 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xC5C5AAF5, 0x7E897EE1, 0xB0AC0BD2, 0xA3177FEF, 0xD8571340, 0xB98AA344, 0x40619949, 0x159A20CB},
	{0x3F7F4B08, 0x72C72FC7, 0xD080C3CC, 0xCBCD2F90, 0x9E1096CF, 0xDC147A15, 0x1D5E4342, 0xA9800047},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xAB816323, 0x31989976, 0xC1DC52E6, 0xB313A080, 0xEB39FE42, 0x175B4F9F, 0xF6DA085F, 0xA44120A6},
	{0xAE8C70AF, 0x347CA46A, 0x475A0241, 0x8ABD0B7F, 0x31BEC8B5, 0x90532735, 0x6B4A95F9, 0x438AF2C0} } ,
	 { {0xBAE11597, 0x60A66009, 0xDB176438, 0x101A909C, 0x028025C7, 0x3C2ECC9D, 0x27BB7BD4, 0x7EAC2003},
	{0xF418F0E6, 0x08503C4D, 0x07A2DB0E, 0x80F45B19, 0x8C0C370F, 0xB87B3862, 0xBF4A3E59, 0xAE4E36F7} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xD01CAB4C, 0xC949616D, 0x69130FDB, 0x60727366, 0xEAE20563, 0x24A55269, 0x3DA6EC55, 0x5D592C7D},
	{0xB29433FB, 0x561E0FB5, 0x2B62258A, 0x1A745F0B, 0xAD6422C6, 0x7D7B14EC, 0x3A219419, 0x3C638D0F},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x50F469D0, 0xAD4A0673, 0xF30599CA, 0x2642A7C0, 0x601E4C9A, 0x76883054, 0x1893592B, 0x27C80A6D},
	{0x63FF75E2, 0x8186F872, 0x21096976, 0xE65FDF87, 0xC11D9A7C, 0x8405ECF1, 0x1FE3D467, 0x7D9E0525} } ,
	 { {0xE95B791B, 0x5DB9248B, 0x9B0C67CA, 0x6A93399F, 0xAB85A9FB, 0xF7E4B9F7, 0xC267CBF8, 0x7840E960},
	{0xF49283EE, 0xE927408B, 0x2C108E24, 0x23DAB59C, 0x429ED3D4, 0xB3B35D1F, 0x3A38D831, 0x016CCBFC} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x553D2D31, 0x7C22E124, 0xEF20A35A, 0x708E7ACD, 0xFF2911FE, 0xFAB19079, 0x7FCA543D, 0x9C25EB58},
	{0xF82C241F, 0x87168171, 0xAAB3E503, 0x4FF70C65, 0x9A11A69A, 0x7FDD0714, 0x61A20F70, 0x2752DC22} } ,
	 { {0xBA0DE4D9, 0x046AEB7A, 0xD8BD6311, 0x87EA29BE, 0xF11E0292, 0xBD0A84FA, 0xF2AB09EC, 0x22326163},
	{0xB2279699, 0xD3B825D2, 0xC876A94A, 0x684AE3B4, 0xAB8AF92D, 0x04C697E8, 0x5281420E, 0x8669D521} }  } ,
	 {  { {0x4027A66A, 0x79C5DB84, 0xECECA552, 0xD13E3ACE, 0xBE04CECC, 0xD1D90EE1, 0x19FD91C6, 0x57D571EE},
	{0x24E886FC, 0xF96D21D8, 0x8D30D6AB, 0xC42D74A5, 0x4605C42E, 0xA5C41590, 0x5B921A85, 0x4C704319} } ,
	 { {0x0165B12E, 0xD76D275F, 0x8A7991A4, 0x8499A295, 0x27388F3A, 0x82E2D833, 0xCFF01EEC, 0xA240436A},
	{0x4BBCA092, 0xBEBD65CF, 0x9182AD72, 0xE3483937, 0xCA51B63D, 0x3F8EF9C2, 0x1AF687B8, 0x13FC8731} }  } ,
	 {  { {0x98CDD3DB, 0x8DF95D83, 0xB8A14D5B, 0xD96A19FC, 0x554AFAEF, 0xD6DC88BD, 0x167ECD00, 0x826E6880},
	{0x4312A450, 0x71A46C5F, 0x39E57DAE, 0x21D8A9AF, 0x3E515E17, 0xE9900A66, 0x8344FAA1, 0x398F7A94} } ,
	 { {0xA77A1AA6, 0x0F2B263C, 0x776AB208, 0xF585614E, 0x35CB2713, 0x688AA5ED, 0x23C3038F, 0x67748CF1},
	{0x98496080, 0x7C1E8D75, 0x4B45F3D8, 0x2CDCA801, 0x18CD9AC7, 0xDD1B47E4, 0xA0F0AB3C, 0x43821B65} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6084 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6085 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6086 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6087 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6088 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6089 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6090 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6091 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6092 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6093 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6094 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6095 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xD719EAF0, 0x2C259B56, 0x8F332CEA, 0xB1983885, 0x2C7E309B, 0x124137F1, 0x61545D0A, 0x5E9463C9},
	{0x1DEBB6B4, 0xB78A135F, 0xEB21B34F, 0x18576F36, 0x8B74B7A6, 0xBA67C34F, 0x21FA8434, 0x2D4CB0DB},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x84C186FE, 0xEEF295BA, 0x8E05D64A, 0x1F815221, 0x71950C68, 0xE43075DD, 0x80BDD6CB, 0x18502E95},
	{0x893CE4E2, 0xA39599FF, 0x489E5683, 0x6F6D9687, 0x8C437699, 0xA18077E4, 0x7C1EC3B5, 0xA4BC48EA} } ,
	 { {0x94034A29, 0xE02090F1, 0x311F4DAA, 0x3D48BE83, 0x3438D834, 0x0417B0F3, 0xC3E67C9A, 0xB525C681},
	{0x268167B5, 0x32881A79, 0xDD6CE33B, 0x96083804, 0xEEA67B9E, 0x66864C6D, 0x1417E564, 0x79FFD95E} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xF9013805, 0xB17D10E5, 0xF2414D43, 0x409BCAEA, 0x8DDE7FC6, 0x60E23170, 0x86C97B59, 0x1A00F1A6},
	{0xB2E3020D, 0x344B6417, 0xD757C67D, 0x7157FC3F, 0x6B45A7FC, 0x2ABF84E5, 0x8C588915, 0xA4201920},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x0F1F0EB2, 0x45056BC1, 0xECBF7C73, 0x9AA56AB4, 0x22CFDEAB, 0x94A1F095, 0x608A28A5, 0xB932FE6A},
	{0xF6B8CE60, 0x4AB72E90, 0xEC1E406D, 0x5C8DFE54, 0x2FCDB3C7, 0xD29B8285, 0x43523B76, 0x004228DC} } ,
	 { {0xC51FF64D, 0x98E703EB, 0x67B41A44, 0x1A6FC02E, 0x665E4568, 0x4BC3BB11, 0x78262C4F, 0x62BF43E2},
	{0x713C2B75, 0x655A56CD, 0x43A1EAA7, 0x931ADBD1, 0xBC06493E, 0x38D94B2A, 0x5F89CF24, 0x585C61F7} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x5A73A46F, 0xD68ADAC0, 0x36A4D463, 0xAC839DA1, 0x4B453427, 0x169475C3, 0xBA5F45EB, 0x68388C27},
	{0xA8346449, 0x3A1D2FDF, 0xD0E0CFCC, 0x1EDD79D3, 0xD1E4A8B3, 0x146DEE5F, 0x9A21DCAF, 0x63CAF847} } ,
	 { {0xAE2CE7AE, 0x6AF72F8D, 0x3EAC99BB, 0x45ACA449, 0x4D8E4C8C, 0x9E51D55A, 0x75FF9C26, 0x786BBDD7},
	{0x41B2CB5F, 0x3DF29419, 0xCAF95403, 0xD6953A2A, 0x1D84D18F, 0x243EF686, 0xAD9CF0E0, 0x2E24C88D} }  } ,
	 {  { {0x18861A65, 0x4D3F56EE, 0x1993B92B, 0x19A19018, 0x35BF7BA4, 0xF08951E9, 0x4E8E03AE, 0xAA915E7A},
	{0x46621261, 0x5143BB22, 0xC8A35AC6, 0xADD3D6B5, 0x750CCC26, 0x77645B09, 0x6C7E74B7, 0xB2EE6B26} } ,
	 { {0x28A59530, 0xC567F0CC, 0x8CCF4B33, 0x736CFA2A, 0xADB111F5, 0x976F5CB9, 0xD6407C88, 0x26348664},
	{0xDBF418C9, 0x205B7B24, 0x43C5A9B8, 0x3FEADB72, 0x3844A7C4, 0x3076C9F3, 0xE9E5BC8E, 0x3A51BA28} }  } ,
	 {  { {0xBF2EAFA3, 0xF4ECE970, 0xFC536A95, 0xC6A2A1DD, 0x76BAE233, 0xCB8321BF, 0x741F3709, 0x2A243327},
	{0xB1D89DC5, 0xBAEE892E, 0xCD60ACAD, 0xB9CD18DC, 0xA3EF09B2, 0xFA845F2F, 0x52BFEAF2, 0x1C7A1172} } ,
	 { {0x467E8156, 0xC24820BC, 0x85C508C6, 0xDF18CF3E, 0x43C87546, 0x3DE8B7DF, 0x118E4057, 0x1B1C589A},
	{0x74C380F7, 0x74646D2A, 0x62B374C4, 0x5A287B5F, 0xE5682C0F, 0x49CAB36E, 0xF91E1334, 0xB327CF41} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6096 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6097 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6098 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6099 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6100 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6101 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6102 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6103 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6104 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6105 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6106 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6107 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x25062D97, 0x47607B6E, 0x488453D9, 0x5B3EAC7C, 0x703635AF, 0xEE93A627, 0xF4DFA9A8, 0x49F51437},
	{0xD9D90D40, 0xA49E944E, 0xC40C7E71, 0x866A27C8, 0xA1AAF5F3, 0x4193C692, 0xE3AD3C26, 0x37B6C42D},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x654C0108, 0x5A6903BA, 0x90F778DA, 0x822177D4, 0x8B79292D, 0xF0FF8E0A, 0xCF3563D7, 0xB26E7089},
	{0x30BA21A7, 0xDC1F6FCA, 0x41B32C50, 0xFF815083, 0xB03018E4, 0x1F26508B, 0xF52623F3, 0x9C23B48E} } ,
	 { {0xE7B6DBD1, 0xB61D3FA3, 0x415B7BC7, 0x0F249024, 0xC5246CDB, 0xB923E04D, 0x59F16B04, 0x477F0BDF},
	{0xC96035EA, 0xCC16CF3E, 0xC04C3941, 0xA5C3C197, 0xA924E435, 0x4B577138, 0x9BBE72CE, 0x1C43BA4C} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xBE152F23, 0x120A851C, 0xA938B890, 0xB451BF6D, 0x66FEED6A, 0x7FFA03F0, 0xFB2502C2, 0x4FC3BFE6},
	{0x468FE227, 0xD0384F58, 0x441B344B, 0xB704937B, 0x15574B5C, 0xEAE6DD34, 0x41CC9B58, 0xB4FB5551},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x8410AF19, 0x678432D6, 0xD442C8FF, 0xEE08BCAC, 0xEA7AFA9C, 0x2E6F81B9, 0xB5EFA8A0, 0x2A7990EB},
	{0x91B6E94C, 0x9088C7E2, 0x9D4EB10F, 0xC965E574, 0x3C7F8483, 0x6A650373, 0x5E709EFE, 0x4F10791E} } ,
	 { {0xDDC39F51, 0x00144118, 0xB4E9DF48, 0x796C6CE3, 0xF13AFBC6, 0xC0F69BBC, 0x8E6AF976, 0x4BF81B90},
	{0xB6E3D5E7, 0x27661787, 0x83749A6B, 0x3901D7CE, 0xA342771A, 0x79AF8DE5, 0x9CC88219, 0x040CFFAA} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD7E57C81, 0xDBD05C6F, 0x53D5A406, 0xB49C9430, 0xF4494596, 0xA8F74024, 0xF1F059D4, 0x22C01EB4},
	{0xA72DBDBA, 0x11ADA741, 0x93CD3D68, 0x516E1B2C, 0xAE56EA8E, 0x93D4D5D6, 0x6CDEA466, 0x032FDA23} } ,
	 { {0x0F7CFA4D, 0x69616BB0, 0xEEDE6DAB, 0x33000B89, 0x48E9B3AE, 0xCC50B2B8, 0x188AE1D2, 0x841D193E},
	{0xDEB593BA, 0xC2A0208B, 0x8E2B1180, 0xB807589E, 0x0E1B7935, 0x36A2688D, 0x54B3B4D1, 0x41EACA5D} }  } ,
	 {  { {0x78090DC6, 0x0FA1BE00, 0x0C8D5460, 0x106DDCBF, 0x56E54249, 0x80576BAC, 0x1C02D478, 0x3F88D275},
	{0xEE0DF340, 0xEF343CAC, 0xFC59009D, 0x6DAD70DC, 0xAF9B2BEC, 0xDCFC0037, 0x7668E059, 0x3E23A3CA} } ,
	 { {0x1CBD2E69, 0x46FC1810, 0x84DB74D0, 0x1BFC0A3C, 0x809E9420, 0x9088DDB4, 0x1ABDD5E2, 0x9BB70BB0},
	{0xEBCB69BA, 0x856C54C8, 0x732C3601, 0x3014045A, 0x5EE5A607, 0x7298FA0D, 0x1A083BBC, 0x6494C0FB} }  } ,
	 {  { {0xC58B2872, 0xE28DA418, 0x70AEE80A, 0xB0B3A8B7, 0xD6B26416, 0x606C1071, 0x5448782A, 0x08EB8F23},
	{0x3C03B66E, 0xD02B23AC, 0xDFF572FF, 0xCEF36A53, 0xCFCE5A16, 0x095C779A, 0x4CA85149, 0x324EFD86} } ,
	 { {0xC89A3DB6, 0x293BF5CA, 0xB343557C, 0xA31C3FEB, 0x8CCB9FC6, 0x7D6D65B4, 0x3C29C762, 0xB1295EAA},
	{0x511A6DBD, 0x5A16EC49, 0x79C9033F, 0x33D00603, 0x3ACDE22E, 0xC920C71A, 0x0D89B609, 0x0A7E86C3} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6108 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6109 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6110 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6111 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6112 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6113 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6114 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6115 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6116 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6117 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6118 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6119 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x51910CF3, 0xDE29F78C, 0xDB8264C0, 0x7083C3B1, 0xDBC54974, 0x51FBBCD6, 0x761AFF67, 0x0EF0E82F},
	{0x9E282ED6, 0x2C0A022F, 0x67151C59, 0xA88CE943, 0xD3AAB95C, 0xE726AE49, 0xE9320EBD, 0x77CE596B},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x3153E40F, 0xF4C4CF68, 0xFE5BE7BA, 0x8BE25884, 0x1AA1E8AA, 0xA195244C, 0x42A275F8, 0x20E62106},
	{0x5E46917A, 0x498DEFBF, 0x6C8C5BF7, 0x1EE7A289, 0x97D7B16D, 0x24DFFEAA, 0x4ECA5EBD, 0x2B373CBB} } ,
	 { {0xA337B25D, 0x1E8F503B, 0x59C70A69, 0xBF83419A, 0x41F8B5B9, 0x8776328D, 0xF735A834, 0x7A29E869},
	{0x47C63DC7, 0x68DF01A0, 0x1EACEDC4, 0x2139269B, 0x57B8555D, 0xE92597E8, 0x97578D41, 0xAE025321} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x5679B6E9, 0x5E1E1635, 0xEE898B33, 0x8F018D92, 0x929EC5BE, 0x2F1E40EA, 0x9F0E2150, 0xA7977CE7},
	{0xA7D0B29E, 0x7F974211, 0x6B96E608, 0x2CF0F491, 0x70749045, 0x2EB53B60, 0xC5D4B6A4, 0x84415361},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x65DE52EE, 0x04D7EE38, 0xF5D54068, 0x369AEF53, 0xB6187E0C, 0xE2E33CC4, 0xAE07F88D, 0x111F8F62},
	{0x02B25889, 0x8F44A65D, 0xDD5ACBB9, 0x956734DD, 0xCE15F8CE, 0x6486C407, 0x35DFA848, 0xA46A0405} } ,
	 { {0x131C376B, 0x40C83559, 0xD1B4709C, 0xA39AC76D, 0x7727B252, 0x10287B24, 0x7340FF38, 0x54EC2C01},
	{0xC04526FC, 0x527CC313, 0x452151DC, 0x0F818C76, 0x7079FB95, 0xD134C794, 0x9B408982, 0x8021C9E5} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF5BCAD12, 0x374AC5EB, 0xE72821F4, 0x562BAD62, 0x8BF6CFC7, 0x7E188D70, 0xD7C50D7C, 0x7DF72478},
	{0xFB35FBF2, 0x6E903FED, 0x60C421AD, 0x8A9F732F, 0xB3DC5D0C, 0x11FE1FDF, 0x970D6FF5, 0x74AE457F} } ,
	 { {0xC2548969, 0x3325C5CC, 0x7127ADD0, 0xC33D8C07, 0xCE77951D, 0x9693C5E2, 0xA9CF7EF1, 0xB99E3B05},
	{0x21F20331, 0x04AA975F, 0x8799D84D, 0xD284E059, 0xA0583039, 0x353329FD, 0x7CEC9DE2, 0x92FEA2F9} }  } ,
	 {  { {0x7C2D9DE9, 0xD7C93DDA, 0xB161A259, 0xA538D103, 0x0453F7A3, 0x92113505, 0x98C3F934, 0xA9A32BFD},
	{0x7773BC52, 0x3051A088, 0x356F0F81, 0x46AA7C98, 0x1F7BF6CF, 0xE1FD6717, 0x11B769C0, 0xA446E2CB} } ,
	 { {0x31D91DF2, 0x9008F4C3, 0xAB5123FD, 0xECB4A88F, 0x20B58F85, 0x0C706A7F, 0x7BE3ECB2, 0x01F917F5},
	{0x8A831060, 0xE6A799C9, 0x4DA0091D, 0x84130C26, 0x32FE72B3, 0x7831784D, 0x069EC248, 0x7EAB5F3B} }  } ,
	 {  { {0xE80B322A, 0x3D5C906B, 0x7EC4274A, 0x6782E3CB, 0x0FF34C83, 0xDD74FDA1, 0xF815793A, 0x2C2433EB},
	{0x45DACC49, 0x23CF86DA, 0x3AE47CB1, 0x152E8E38, 0x24446237, 0xF057BFD6, 0x4B28ABCE, 0x75637173} } ,
	 { {0x073A34E7, 0x34F0D996, 0xA56148C7, 0xF36FB95D, 0x1E137773, 0xD135B646, 0x00715080, 0x375956D4},
	{0x03FF9C1A, 0xB5794242, 0x5E113884, 0x2EC86765, 0x81CAFD1B, 0x24C8823B, 0xCEDD0874, 0x2A12C3AA} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6120 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6121 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6122 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6123 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6124 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6125 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6126 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6127 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6128 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6129 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6130 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6131 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x8F1AF8E5, 0x91522B64, 0x399466F4, 0xAFFCFAD2, 0xFDC0D561, 0x4553BC37, 0x3D777142, 0x4FD8E25B},
	{0x1E132C7C, 0x9C7762D1, 0x6B1B310C, 0xFA9D6F32, 0x96FD8A19, 0xCE7E3088, 0x65C25104, 0x18A73428},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF2FD7529, 0xFAE45E97, 0x7CD69752, 0x3378F634, 0x8FD5B1E6, 0x0D7944FF, 0x98FBFFFB, 0x60344C0C},
	{0x992BED93, 0xD80EA6D6, 0x96F2EB32, 0xFA4A4AFE, 0x2B8DB5B9, 0xF0656D0F, 0xCAC78ABE, 0x0F9B92B4} } ,
	 { {0x72CC34D2, 0x3036E83B, 0x29979210, 0x75DEFF42, 0xB1F35B64, 0xCC50BCC4, 0x28EB46F7, 0x3DC75D81},
	{0x42DC66CF, 0x9D40D62C, 0xB1352AA4, 0x60B0F331, 0xC8E99B26, 0x8F5ABC1E, 0x17279F35, 0x3ADE13C2} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x70376C52, 0x95559EFC, 0x48BD5DDD, 0x667B5108, 0xE3E0CF5C, 0xCD63212E, 0xC93A5451, 0x8D254ECD},
	{0xDDA67778, 0xA9E05051, 0x6873C83F, 0x95376F1B, 0x8A2724CB, 0x6E9DD7F4, 0x2780971C, 0x8A22AC05},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xF4B3794C, 0x515AEC2C, 0xD9B31EBA, 0xCD6B5B67, 0xFFC79B58, 0x6C8D8F3E, 0xC06FB581, 0x63633C19},
	{0x884D6914, 0xD554AEBC, 0xE7AE74E7, 0x76A21813, 0x4F4F3883, 0x62FAE296, 0xB35F124D, 0x1B4026C3} } ,
	 { {0x27218C4F, 0x573475D8, 0x417F0FBF, 0x3CD104D4, 0x30C06C7A, 0xDB9DFA5C, 0xA74D9DE3, 0x445EF3FA},
	{0x0623788B, 0x841382B5, 0x340C29F9, 0x04A9B397, 0xB785E299, 0x451F1D3A, 0x0FD5BC60, 0x181BA6FB} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xBA7E21B7, 0x88DD67B0, 0xF48621F0, 0xDAAFB9AF, 0xB0E91607, 0xB10484BA, 0xF04DA8F8, 0x706EFD47},
	{0x5D7052D1, 0xA6682DFB, 0xCB3879B6, 0xFDA81991, 0x66C6AFF1, 0x2838F37F, 0xD95A83EF, 0x2726459D} } ,
	 { {0xDE86C71F, 0x05E69F58, 0x4C0D9DF5, 0xE4396C1B, 0xEF02F076, 0xD287D675, 0x9D16BA64, 0x8C97F666},
	{0xB9B7E7F5, 0x459B8899, 0x98341682, 0xA22F6520, 0x2352FF4B, 0xC9D3BD87, 0x88DB8DB7, 0x8159AF5D} }  } ,
	 {  { {0x79C20214, 0x46FEE6BD, 0x0067B65A, 0xD872E81D, 0x070B2123, 0x27A56918, 0x08E67648, 0x3D258008},
	{0x3F15D0C7, 0xA340308C, 0x02EE1E7B, 0x9B48F6A6, 0x6A44682C, 0x3546B8F1, 0x06652F27, 0x9EBDF0F7} } ,
	 { {0xF7908382, 0xE6CBE8B5, 0x25C75606, 0x5C9A0226, 0x048A1F40, 0x8E92FFCB, 0xDEF8C0DF, 0x80EFE43C},
	{0xB3886CA9, 0x77B0FA21, 0x4B8E57BF, 0x91F4ED08, 0x9BDCC2E2, 0xD639A1A9, 0x2560CA7F, 0x573E6198} }  } ,
	 {  { {0x8DF809A3, 0xEA7598E5, 0xBB9D1E9C, 0x94A98885, 0x2ED8BBB1, 0x9FBE3480, 0xB0F50A51, 0x3B67741D},
	{0x8D0C17CA, 0xB2866609, 0x4082F665, 0x6EBB7847, 0xC287E22C, 0xEA4E0C01, 0x8EC1D99A, 0x8E3C1F13} } ,
	 { {0xF536EF28, 0xBCC819B9, 0xC0978D0E, 0x4D4EF6E4, 0x4E1BDF69, 0xF840741C, 0x88CFC748, 0x1EA589B3},
	{0x5F396C99, 0x5B21B1C8, 0xCAC33579, 0x4F10C3A5, 0x73FDDF53, 0xD04B29A7, 0xDB7FADF0, 0x1D624437} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 6132 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 6133 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 6134 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 6135 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 6136 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 6137 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 6138 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 6139 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 6140 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 6141 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 6142 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 6143 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xF7C48345, 0xFA166116, 0xD3651683, 0x874DA6FE, 0x41D823F1, 0x1B4065A6, 0xEB07E4CD, 0x04CE4614},
	{0x279D2365, 0xE3499106, 0xCB423D01, 0x644BFF6A, 0x0219226A, 0xE99368FF, 0x3FB4BEF0, 0x8F5BF329},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x30BC75EB, 0xB875B232, 0x12251EB1, 0xA70A9B0C, 0x3FF04786, 0xD1047B02, 0x83FFFE33, 0x99344249},
	{0x4CEAC90D, 0x42F64C4A, 0xAF848D3A, 0x30A0A97F, 0x9985894A, 0x79932656, 0xFC32EC18, 0x61498FF0} } ,
	 { {0xBBABCC85, 0xE813661F, 0x0A690FFF, 0x7403A437, 0x34AD2477, 0x0A83284D, 0x05289A74, 0x705687FF},
	{0x81473842, 0x37D2D5D6, 0x6D5008E0, 0x09391F30, 0xD977EFB9, 0xC3AE059A, 0x02A098F7, 0xA95083BE} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x61C627E9, 0xBD68CAE2, 0x9ADB1AD7, 0x62E9AC80, 0x28B9851E, 0x72F02657, 0xAF98145B, 0x280E19A9},
	{0xFE54755F, 0xFFFFBB59, 0x29D6AB07, 0xF7840AC8, 0x1EE9BB82, 0x36A83718, 0x1E4C83B1, 0x5E4755C0},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xB70C8337, 0x52C22F35, 0x7553AB49, 0xD5EEB06E, 0x6E90E05A, 0xEFA8BD8A, 0x53244EB1, 0x8EA49ADF},
	{0xD1A2DE81, 0xCD41AC17, 0x3D3F6005, 0xC3BE39F9, 0x9508DD04, 0x0A20F070, 0x4DFAC7A9, 0x90CB1039} } ,
	 { {0x4894063D, 0x1851D10F, 0x825727A7, 0x2E4E65BE, 0x0318AC49, 0xFB107D0D, 0x5A0F6CBA, 0x77380C08},
	{0x2BF04A48, 0x4D2EED00, 0x94E9200B, 0xCD60F485, 0x8BA994E8, 0xD8FCFE49, 0x98017CA5, 0x33DC7895} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF04E9278, 0x3BDF99F2, 0x3F48F043, 0x77D0946B, 0x9D237E03, 0xB359581A, 0x0B2A7F00, 0x06F298CD},
	{0x5A4AA7C8, 0x9DB17AB9, 0xA49FF5A9, 0x9DFEA366, 0x5CFF9241, 0xA7E20C34, 0xEB0383A6, 0x61B234A3} } ,
	 { {0x04D11C6B, 0x98F0862A, 0x1E2459C7, 0x2AE34A4D, 0xC677CD0E, 0x0B9C09A1, 0x14C156BD, 0x5D8344E3},
	{0x45398262, 0xD511DCB6, 0xD4F2E077, 0xD6736236, 0x07771459, 0x0F106328, 0x9CFC13EF, 0xA8377A28} }  } ,
	 {  { {0x476B9BE9, 0x11AEDCCC, 0xEEF701F7, 0x5321809B, 0x383AD4FD, 0x2513091B, 0xE8432981, 0x79649E4A},
	{0xF216D083, 0x5272C281, 0x57268A29, 0x09E1A6C2, 0x8C2F7A85, 0xFF0560D6, 0x8B508D2C, 0x3FDA9FC5} } ,
	 { {0x29ED432F, 0x4DE460EF, 0x88079F38, 0x488D33CE, 0x6D9413D4, 0xCED4898E, 0xAF9988FA, 0xA9AF555C},
	{0xECA4C78D, 0x5E43753D, 0xA16C33B4, 0x7F451F92, 0xEBBF1F15, 0xE5150952, 0x19382118, 0x39E5B947} }  } ,
	 {  { {0xD3BCC8C0, 0xDFA8A324, 0xE518B60A, 0x723439CB, 0x5EBD9CEC, 0x38B9C1EA, 0x36A89946, 0x6E8ED742},
	{0x4B104AA0, 0x6EBC1D35, 0x2CA6488A, 0x25F0F727, 0x43744153, 0x7A6683BA, 0x806FF4A9, 0x769C65DD} } ,
	 { {0xA5EF1BE9, 0x8A0C7C75, 0x8C94626F, 0x257A9AA1, 0x0B9AC432, 0x561A7DF0, 0x2A145142, 0x7EC656B8},
	{0xBC3F3D29, 0x6868A9DB, 0xBB9A0D61, 0x3AF5DCE5, 0x0C72B41C, 0x845494A3, 0xE3A66656, 0x0AE63518} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6144 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6145 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6146 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6147 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6148 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6149 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6150 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6151 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6152 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6153 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6154 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6155 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xABE98937, 0x5E93380A, 0x18D727DE, 0x2E87D29B, 0x925F59D0, 0x5BF41B17, 0xCB69FF60, 0x4F179178},
	{0xF3707BFF, 0xD362025E, 0xD0479C12, 0xC383470C, 0xEBAC063B, 0x2F7B48A4, 0x808D3F68, 0x740EDA34},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x6FFE4FA9, 0x26B1A7EF, 0x0F364D81, 0x3259B4FC, 0xF464A413, 0xDB5ABB8F, 0xDACD79FA, 0xA1C6346E},
	{0xE945C3F1, 0xFF1641DC, 0xEA68F879, 0x6D226E7C, 0xFA46DE67, 0x9937165A, 0xA1984CC1, 0x9871F339} } ,
	 { {0x1A7F7EDC, 0x60BFCEC2, 0xDCAD33A0, 0x55C9BF81, 0xE87307FC, 0x56379AEC, 0x84E12290, 0x60318DE7},
	{0xA3F46F80, 0x0516FBE7, 0xE6C90D5A, 0x0FFC1059, 0x70D10050, 0xC90C0E05, 0x1050D77C, 0x778E27D0} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x7BA81CEE, 0x7DBD98BE, 0x47B7FB99, 0x5DFD8D65, 0x9739DE93, 0x3CCE59E4, 0x548F6FE7, 0x3064D585},
	{0xE4A8B384, 0x99FB61E2, 0x644B322C, 0x7C1EAD6F, 0xABFE4802, 0x31BCB808, 0x67B6038F, 0xA54AF0B3},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x1764F656, 0x83E040E7, 0xA9E95742, 0x75CC9BF3, 0xC2D609BB, 0x259920DC, 0xBF9BB7FF, 0x4AF5760C},
	{0x4006188F, 0x7080EBC3, 0xADC65C53, 0x2C8DC875, 0x65ADC3E2, 0x15AEF55B, 0x3C3C4320, 0x2E4686AA} } ,
	 { {0xFCC360E4, 0x70A2A25A, 0x17887B9B, 0x8F463A31, 0x66918981, 0xB1AA5EAB, 0x3439CE42, 0x7C2B7E24},
	{0x4B6487CE, 0x155D9DF6, 0xFB8E1F11, 0x91017BF6, 0x7DF2AE19, 0x17A39C7A, 0x09148CDB, 0x4F203F6C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xA2ED0489, 0xCDF66F18, 0xBCDB46B7, 0x6948D67C, 0x3B064C88, 0x29CCF6E4, 0xC0E94372, 0xA06BC4FD},
	{0x57122C93, 0x3AECB81A, 0x1657418B, 0x601D208A, 0x74AE8DBB, 0xD7B48C08, 0x414C6952, 0x7BCD0A8D} } ,
	 { {0x929F3A5C, 0xD714FCA1, 0xDF6C68C9, 0x487F89B3, 0x77771148, 0x0F9A3222, 0x665699AC, 0x909BAE7A},
	{0xB15A5922, 0x3E22F23E, 0x75F1787A, 0x1C960AB2, 0xD3A62C8E, 0x27D60BD2, 0x914E5757, 0x772D02AD} }  } ,
	 {  { {0xCD327C8E, 0x694506B1, 0xB0935DFD, 0xD4474503, 0x0F048CFE, 0xE25818D7, 0xE20644EB, 0x51915194},
	{0xBF9236E7, 0xDFF8EB06, 0x22B53B06, 0xEF4FBA7E, 0x730FF1A3, 0x0956615C, 0x78CA8A76, 0x2A389B73} } ,
	 { {0xA4406BBA, 0x063CF0A9, 0x50EB579C, 0x004EF5D1, 0xEBC76486, 0x631C6DB1, 0xA2372BB0, 0x1912AF99},
	{0x85E3E89E, 0x83DF5B38, 0x6758960E, 0xC747D529, 0x46A83EDE, 0xDF8289F0, 0xDB118680, 0x02B05FA2} }  } ,
	 {  { {0x5EA6A9F2, 0x6DC544D1, 0x81B7A8C0, 0xC9ADF126, 0x4B1EF33A, 0x0353FBEB, 0x809F9581, 0x05716C15},
	{0xAFA176FD, 0xAC2E041B, 0xE9A89240, 0xCF429E94, 0x6FA0EC26, 0x3BBBA1CC, 0x9B4993C9, 0x64A886E8} } ,
	 { {0x48C6A8D6, 0x02993F1E, 0xA88F2F5D, 0x1B53489C, 0x518D2618, 0x526CF835, 0xF1157C1D, 0x4A91FDFB},
	{0xD5189538, 0x22D388AC, 0xE3D83665, 0x0087AD94, 0xC582B25E, 0x9A596187, 0xBF0DC38B, 0x6247C618} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6156 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6157 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6158 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6159 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6160 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6161 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6162 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6163 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6164 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6165 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6166 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6167 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xCE1AA8CD, 0x3CC6A601, 0xA638ACAF, 0x7FA145E2, 0xF6D0B110, 0x0A3C013B, 0x181E6C37, 0x8B310504},
	{0x75C11905, 0xC4FE8E62, 0x8A4B52C1, 0xE0C30805, 0xB6C69B20, 0x9A086E26, 0x27A5ED46, 0xB010A139},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xD2864F3E, 0x10D77E61, 0xD17EC606, 0xB9F4CECB, 0x04052B99, 0x21D7C538, 0x0E7735B4, 0x9D57466A},
	{0xEC8C4367, 0xD3C40BA0, 0xF8A36AFA, 0x43FB4B15, 0xF2775D0B, 0xA9592C9A, 0x566A5550, 0xB32809F6} } ,
	 { {0x974B4D45, 0x5C7E9CC8, 0xF8263731, 0x6C8453E9, 0x24CD0F4C, 0x1818E42A, 0x49462766, 0x34B78198},
	{0x9A3F20A6, 0x09CF0221, 0xB64C5358, 0xCB31301D, 0x80559722, 0x9E20EDF9, 0x86FFD80B, 0xB94D989F} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x865D9C3E, 0xF0E251E4, 0xB50FF8E3, 0x4E480376, 0x6BECB999, 0x678E5403, 0x663CD8EE, 0x9FDD12B7},
	{0xB12DACF4, 0xA4542FBF, 0xB491DF37, 0x9EA38D42, 0x8C0816BB, 0x6B703B1A, 0xEF1C0CD0, 0x79C9941F},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x668121FA, 0xEE73AE00, 0x751C9B02, 0xCB4B0BCA, 0x5AA66444, 0x4C379221, 0x53526C3B, 0x3CB21B29},
	{0x00F72A38, 0x524B3129, 0x5F98B70C, 0x883F322D, 0x7D428EE1, 0x4A17A68B, 0x0CF09767, 0x0D440D1B} } ,
	 { {0xDD4836C6, 0xE4D3BC9B, 0xC21DEB56, 0x411FA80B, 0x32F7B38F, 0x6919CF30, 0x464BAE80, 0x515FC704},
	{0x6E9FE30D, 0xD473BC15, 0xF6FDFC7F, 0xEF6D4980, 0x81D60CC7, 0x45258989, 0xD0D945EB, 0xAF48E48D} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD4B311DA, 0x9B796DC1, 0xD2764131, 0xC6EBE1E3, 0x58F74D63, 0x00F26C7B, 0xD66D7362, 0x1A2982B8},
	{0x61F39CAA, 0x7A73701A, 0x46668206, 0x575A29B3, 0x9965E477, 0x9FBA92C9, 0x67123F86, 0xB4DF1F4B} } ,
	 { {0xBED078E5, 0xD3200378, 0xD950029D, 0x31332AAF, 0xD65B2A55, 0x3AD61CFD, 0x9CDDE3E9, 0xB90947FD},
	{0xACAFD01E, 0x7F470258, 0x97AA3CB4, 0x622FF860, 0xF80597E3, 0x15FF9DC4, 0xBF373BDE, 0x9391E38D} }  } ,
	 {  { {0x26023EBC, 0x87AE82C6, 0x8030D07C, 0x3B084492, 0xEBFD0A0B, 0xD9EC1007, 0x4F750707, 0x5FD98A08},
	{0x6BFF75AE, 0x461C83EE, 0xEDEE2F3A, 0xDEF51EB8, 0x79B16D98, 0x6E018108, 0xAEE06A5F, 0x5FFA119E} } ,
	 { {0x342ABE1B, 0xD10171E3, 0xC4D851E7, 0xD2715671, 0x65B74CA0, 0x94874811, 0x1F3E29F9, 0x8EDD1929},
	{0xE6D6456F, 0x376110F4, 0xC3A1CE25, 0x849567D6, 0x7392EB30, 0x38466644, 0xC76CA06E, 0x3CBC125A} }  } ,
	 {  { {0x3AFCA53A, 0x0E567B05, 0xE914E6BE, 0x368ED985, 0x7975AF2F, 0x39811D0A, 0xD26C5604, 0x50E71A5C},
	{0x1E5D942C, 0x99454A1C, 0xF5A74592, 0x00881AFB, 0x52742622, 0xA95751A9, 0x20942EE8, 0x446E0389} } ,
	 { {0x35D9D706, 0x940E40B4, 0xABE11D3D, 0x76CCB213, 0xC750235D, 0xA79048FD, 0x66AF4D66, 0x79C12278},
	{0x411F6555, 0xC2A37C5A, 0x64500822, 0x6D8D2F97, 0xBEC5F3E0, 0x105B0B89, 0xC9C7AB38, 0x8C3B43C3} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6168 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6169 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6170 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6171 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6172 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6173 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6174 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6175 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6176 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6177 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6178 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6179 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xB7116AF8, 0x6F1F6E34, 0x14E5F802, 0x3F6D9B3A, 0xDE62A836, 0x4FDE3C9B, 0xD3E1BE0C, 0x49CF9C59},
	{0xCA62838A, 0x36209C28, 0x2BC4C12E, 0xDCABE160, 0x23DAFB92, 0xB7064435, 0x9BD51A62, 0x01D07FFB},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF140066C, 0x558367D2, 0xBD736F94, 0xA3A19169, 0xCFC6896F, 0x56DFAC28, 0x5AC6C843, 0x06A3D3C1},
	{0xBCBCA74C, 0x467FDC14, 0xB283B633, 0x26AD7209, 0x112681D6, 0x7DA88721, 0xE5754600, 0xB80A1D43} } ,
	 { {0xB5DA660C, 0x58F273BC, 0xE9A03745, 0x2D459632, 0x9A637A6E, 0x28C70BE0, 0x180A6F1F, 0x0AA90376},
	{0x8D36BFB9, 0xD68ABBA1, 0x4BDE3CAA, 0xD1225E8D, 0xBE289290, 0x069DEFA4, 0x35761B7C, 0x3111A1A0} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x9524A748, 0xEE22469E, 0xA3A703A7, 0xF9F95494, 0x3106DD35, 0xEEF605A8, 0xE45E624C, 0x38C3B815},
	{0x5AB435BB, 0x4079878D, 0x195CE761, 0xA92DEDE7, 0xB5A7071E, 0x4D1B8095, 0x7D549C5E, 0x0761A3FD},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x34D3704C, 0x2C24A591, 0x71BA2E18, 0x90D3D823, 0x8BCCC5DC, 0xD451A85A, 0x829E3E0F, 0x087A31D7},
	{0x47BEDF13, 0x567FCF99, 0x76165E9C, 0xDD67FD83, 0x1C3458C4, 0xDC5AEEFD, 0xA50B7A11, 0x721629CE} } ,
	 { {0xF0644B1A, 0xA5C0118F, 0xCCA162B0, 0x4FCB756E, 0x4C5851AB, 0x7D838876, 0x291814BA, 0x95660B12},
	{0x64A79427, 0xDAD64E43, 0x690E1663, 0x88CC07A2, 0xB11875EF, 0x61FE6715, 0xE385FE7A, 0x81798781} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB34324B7, 0x7A0CFEC8, 0xAF202F15, 0xEB2CB619, 0xDE04DE17, 0xF2A05A51, 0xDE9CFEF8, 0x81277417},
	{0x8C179F7B, 0x4CDB1A60, 0x51E0BC6B, 0xC5043511, 0xC025BAAB, 0x5ED44E62, 0x6689EF43, 0x8148BCB7} } ,
	 { {0xD8275982, 0xF53BEEF9, 0xC04D5E82, 0xF6C50815, 0x7F129EA2, 0x7F083926, 0x54C2D027, 0x09D9F2D1},
	{0xC91F5E50, 0x08725523, 0xA12FBB50, 0x186E4AB3, 0xB79775B8, 0xBCD4D7F9, 0x3E6DF0CF, 0x6A1F8F5D} }  } ,
	 {  { {0xEAE2B918, 0x35B6ED54, 0x78A23741, 0x60B75E6C, 0xC7E31551, 0x2615B7EB, 0xB0F7FF1F, 0xA0FFA869},
	{0xC2758822, 0x4B1B603F, 0xFEBEB2A0, 0x7443F5F0, 0x3678FF9E, 0x9479BD9E, 0x1219CBDB, 0x812750EA} } ,
	 { {0xB78B7A6B, 0xA8D23CCD, 0x87E7FA62, 0x02A8C5FA, 0x9DC2BB8E, 0x9E09C597, 0x6B309768, 0x1A8E2A83},
	{0xE015EEB3, 0x89EAC21B, 0x906EF587, 0x8CD94FEA, 0x4BB5F896, 0xFB153F38, 0x9177AC65, 0x31BCA144} }  } ,
	 {  { {0x625F0B2F, 0x20BFCD58, 0x63E9F61B, 0x4F16E55C, 0x81273B8B, 0x26104904, 0x542A779F, 0x936B4213},
	{0xDE506A6D, 0xF64D331A, 0xFF786089, 0x86787A57, 0x63DA3E1F, 0x0276BF75, 0x4CAF664F, 0x4FFBD957} } ,
	 { {0x2898B19F, 0xD82033B9, 0x1E4B2A3E, 0x611CE703, 0xB71EC980, 0xE3D6DD87, 0x8979891F, 0x4BF6F6F6},
	{0x220B66F0, 0x890887E0, 0x21AA7DB5, 0x4260AF1F, 0x76C6BE18, 0x2C1B9402, 0xEF2F8747, 0x2809AAF0} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6180 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6181 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6182 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6183 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6184 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6185 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6186 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6187 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6188 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6189 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6190 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6191 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x49AEB1BA, 0xD99562A4, 0xF8BDD690, 0xA7C07663, 0x6CFE20DE, 0x7E400635, 0x83D496C5, 0xB2248FC7},
	{0x6D98ADC2, 0xEDC31AF3, 0xFBCEA339, 0xD340415A, 0x7F25BC2E, 0x8A7DBF69, 0x458D7C3C, 0x3B05FB33},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xB386884E, 0x80E9597E, 0x08F0DE38, 0x5AB77888, 0x200C9E82, 0x904D4526, 0x9D8CFCF1, 0x420FAD84},
	{0x44EC7CB2, 0x58524DD8, 0x2F08882C, 0x553A0C1B, 0x21332CD7, 0xF2939BF4, 0xB87BF7E7, 0x1EFF9DF5} } ,
	 { {0xC56A761E, 0x1B0DBD9D, 0x67BA16A6, 0xE82B72AD, 0x1C7EE8F1, 0x5B45F63C, 0xDA627D39, 0x73CAAB6E},
	{0x7DFE3CA9, 0xFECC6E6B, 0x6B9183E7, 0x8DFCFBAC, 0x75BEEC47, 0xBD96A3BA, 0x24A87101, 0x23AC4ED9} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x2ECAEB65, 0xB12FC746, 0x0FA4D5A7, 0x560F28D9, 0x2F09B5E5, 0x60DCDDEC, 0x14E44382, 0x0F9560D5},
	{0xE600D801, 0x231CDFEE, 0xEA85E7B6, 0xEC36976B, 0x5843789F, 0xB6890823, 0x6E8B8219, 0x341AE4B7},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xD1E648EE, 0xCC6B01C8, 0x8EF0F823, 0x9D86B969, 0x7718A120, 0x7B37BE7F, 0x0DD78675, 0x38901DCC},
	{0x483D0583, 0xAF62186D, 0xA0760925, 0xDC33944D, 0x9F5E6C06, 0x885CCBAF, 0x1DF5C824, 0x0595E00C} } ,
	 { {0xB0C75E38, 0x3F60CD04, 0x6E6E3DE6, 0x7D3A0C1F, 0xA1BF2DA8, 0xEB465360, 0x13749454, 0x7BDADFD0},
	{0xB2CB5136, 0x2F5E0CC1, 0x2905F8E0, 0x1CA776FC, 0x1B90B12E, 0x112DAD2D, 0x2470BC97, 0x8FCB94B2} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x0E8D7E66, 0xF2C13C74, 0xC336F589, 0x86DE1D55, 0x8DD2D135, 0xF36D37F2, 0x32760AF4, 0x6C3E67BD},
	{0xBE0BAF71, 0x6AE7055A, 0xE1291B91, 0xB52EF89C, 0xC8AC0912, 0x3F1EBE26, 0xB267A2E9, 0x9AFB1F6C} } ,
	 { {0xE1EE321F, 0x5ECF8580, 0xC6A6AEFB, 0xD09F2B77, 0x898D68AF, 0x9A70D5A7, 0xBD304816, 0x1DA99BE3},
	{0x8EEC3851, 0x33AE63B8, 0x32957F1F, 0xD4FC8AA2, 0x4C1830AA, 0x193D9B61, 0xAD314142, 0x15C9B3B3} }  } ,
	 {  { {0x749F95F9, 0x3A5093B8, 0xC9DC94F2, 0xD91FC34A, 0xDA5EE907, 0x8DC4BFB1, 0x5B1FA1F3, 0x2F71274E},
	{0xF0E17B90, 0x9DBF0BB9, 0x0FE2FF24, 0x608FD487, 0x69A5BB39, 0x2835AE68, 0x45C62011, 0x134C2729} } ,
	 { {0x778C94CF, 0x5FD904CF, 0x96FEE3D4, 0xDC685694, 0x13F131E8, 0xF27BB951, 0x43F14B44, 0x5797A9A4},
	{0x09C1FC9B, 0xAF270D49, 0x178EDA9D, 0x2555112C, 0x4AD15930, 0xAFC41E0C, 0x383ED83B, 0x3FA0CAC1} }  } ,
	 {  { {0x18FFB29D, 0x51B8B6F5, 0x69750E05, 0xEDF43749, 0x30F9AEC9, 0xB5B7ACE8, 0xA7A21165, 0x39D4C176},
	{0x2A7A884D, 0xA890E7DD, 0x917AA241, 0x32416B28, 0xA1347DA1, 0xD18DE68A, 0xF7A7253E, 0x2A96F105} } ,
	 { {0xE611FF9C, 0x14424080, 0x13CF94CE, 0x79F725FE, 0x41BA6A9F, 0x366D6154, 0x9E0828C8, 0xAD237D8A},
	{0x7EDD51C6, 0xD3CE2B03, 0x678C1859, 0xD55CF54F, 0xF3FB7E68, 0x2C2E4DAD, 0xDFDC6D45, 0xA49FD890} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6192 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6193 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6194 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6195 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6196 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6197 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6198 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6199 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6200 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6201 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6202 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6203 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x8B8A3B1D, 0x2D6FBAD6, 0x53186031, 0xB8866C93, 0x3CCB04C6, 0x3769845C, 0xC0A3F7A3, 0xB8351473},
	{0xB7D99D1C, 0xAA08756F, 0xFA348D6D, 0xC201ED27, 0x160D096F, 0xB8D20CD0, 0xA532AD46, 0xB811416C},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xC48976C2, 0x51ED149C, 0x03AF6AD2, 0xBF25FD6E, 0x79155FF7, 0xCF2D35B9, 0x4B086690, 0x194E4704},
	{0x11BDE056, 0xF683D68E, 0x3D562DC0, 0x2FBD7F1A, 0xCF00FE8F, 0x3960605E, 0xD0EEAE6A, 0xABA447A1} } ,
	 { {0x7A272ED7, 0xE3C7D6BC, 0x27B408C9, 0x2FFB0A8E, 0x58C597D0, 0x45E8DF5A, 0x4942460D, 0x2A0FECB2},
	{0x9C536B37, 0x0CCDD94B, 0x778BAC8F, 0xE8B27590, 0x1F006E0A, 0xDDDC025E, 0xA725B345, 0xA6B156DC} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xE61808FF, 0x813C3EC6, 0x3DA18B26, 0x87C9BA1C, 0xB670D56F, 0x35001C5E, 0xDD25910D, 0x316B42C6},
	{0xDA2409A4, 0xA9E43C82, 0x50B84B41, 0x0D4AE7B6, 0xC7CCB129, 0x41535B15, 0x4F191DE5, 0xA411A72B},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x64251048, 0x8B203AAB, 0x51C6D771, 0xC691AAAF, 0x1A95DD75, 0x4B4E6BFA, 0x2E7E0EE0, 0x9E530385},
	{0xD83600BB, 0xDB97D732, 0xD27C57BE, 0x4FF73975, 0x4FBD8615, 0xD898C188, 0xE70EC995, 0x7A18FD97} } ,
	 { {0xBF0E467C, 0x9A9FB147, 0x5364AC4C, 0x52823A9C, 0x943B38EA, 0xDA2BE9EE, 0xDAF175E6, 0xB95F52E6},
	{0x055293CE, 0xBE03C0C4, 0xF4790C1F, 0x69D6C19F, 0x99916476, 0x6BA74805, 0xD616E8A0, 0xB357E913} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x711D5F76, 0x7836724B, 0x0AF516A2, 0x107F5833, 0x54289667, 0x7920ECE1, 0x589763BC, 0x8EFF73E1},
	{0x08E97042, 0xE3EBF327, 0xFAE493CA, 0x527E9B45, 0x8A69056A, 0x3442B5A1, 0x1800C0C2, 0x05C2C50E} } ,
	 { {0xF7341A9E, 0x3A17608E, 0xFDD0DA0A, 0x5B1094C4, 0x6B19B945, 0x92B769F7, 0x31355C47, 0x18DE4A44},
	{0xAD01CC58, 0x9C871D78, 0x8D069549, 0x96CAE9A5, 0xA1D099F4, 0x23894A2A, 0xCD660D86, 0x3B38EB46} }  } ,
	 {  { {0x670AC433, 0xAF55B1FF, 0x7D16D987, 0x75BEF138, 0xF2254E0F, 0x67F49F7E, 0x54FB345A, 0x97268F09},
	{0xB4A7F541, 0xA6A5517E, 0x99E56D14, 0x18088EAC, 0x482D6EDC, 0x612E006C, 0x5971EB74, 0x60C192E1} } ,
	 { {0x4E125248, 0x6C364EE7, 0xEF59A137, 0xEAC7A451, 0x72B2ABF9, 0x63228DC9, 0xADF9CBA3, 0x833660CB},
	{0x11E59213, 0xDF7C4FF2, 0x55E8CF2B, 0x0ED78E9D, 0xA28922C2, 0xCFD3E3A0, 0x4A5CE54E, 0x257F8D7D} }  } ,
	 {  { {0x9E797FF4, 0xD27EC317, 0xB53EECC1, 0xA276472E, 0x6AACA1A1, 0x44FCE74B, 0xF09F6CC1, 0x5863B782},
	{0x6C56D058, 0x039E23AB, 0x10C50AFB, 0x27188FB0, 0x1C55A9DA, 0xD6AA4C41, 0x5C5A6A78, 0x52DD776B} } ,
	 { {0xC68C43BF, 0x3600F081, 0xEB2D3380, 0xF95F01AE, 0x6D8E9A50, 0x20A02A70, 0xB22A9EC9, 0x7E5C2215},
	{0xA23E901C, 0x10F451FE, 0xF93FC3BB, 0x20FE707D, 0x5399C41A, 0x0183EB56, 0x9F869004, 0x54005FA9} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6204 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6205 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6206 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6207 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6208 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6209 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6210 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6211 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6212 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6213 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6214 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6215 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x24B62240, 0xBB75299F, 0x2EC4F41E, 0xF7286045, 0x94223A4C, 0xE0101A91, 0x64D5358C, 0x7DA50061},
	{0x82C363D5, 0xEB3FEA3E, 0xE7C44FA9, 0xC465220A, 0x2E5B27AF, 0x80702149, 0x88E381AC, 0x9E658206},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x3E04312C, 0x4C6B046C, 0xE6D85772, 0x2428F877, 0xDD3090A8, 0x661FCE60, 0x364A72F5, 0x8322BC17},
	{0x0A593A2D, 0xCC7C2E5C, 0xB112E7FB, 0x18BAB95E, 0xCC946C6C, 0xB14C3492, 0x9834C0B0, 0xB747C9A9} } ,
	 { {0x6BAC7A2E, 0x0E7E6EEB, 0xA0CFF049, 0x94704AF3, 0xB70E971A, 0xBEB401BF, 0xED3CC347, 0x42B71119},
	{0xCB9192F4, 0x256A72C1, 0xE016183B, 0x0A60D30E, 0x04316691, 0x82E5DC38, 0xA824343A, 0x7910C092} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xCB3C0FA9, 0xAF7B7145, 0xFF685FDF, 0x26959C24, 0xA35900B2, 0x66ADE881, 0x374E29E5, 0x4B291266},
	{0x995812BB, 0xC3CFD51D, 0xB4F6CF08, 0x0AAB3AA0, 0x4161325B, 0x5C4A3D20, 0x3A86552D, 0x925ED34C},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x2F24AEE2, 0x1CC62509, 0xB1B42FE1, 0xB37ED808, 0xE52A18FD, 0xCED4629C, 0x15152EBF, 0x6579696C},
	{0xE72069B0, 0x0C4D41D1, 0xDA4F3CFB, 0xBB38A9AD, 0xC67A5106, 0x16ADF680, 0xDA1A2C45, 0x6151FA3A} } ,
	 { {0xEA156CDB, 0x1AC1D4F6, 0x6B9B67DC, 0x69CD2BC4, 0xDDC28E79, 0xF2BB7E5D, 0xE6B87951, 0xA2705252},
	{0x51458EB9, 0x469233B6, 0x7021E1B7, 0x29755413, 0xEC3E30B7, 0x8FE99C36, 0xB38CF3A1, 0x5002A44C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x764483BF, 0x5E79CAC5, 0x7D0A4ACF, 0xB61661E2, 0xABCEA9E1, 0x5938A2E7, 0xC5DDD0AF, 0xA44F518B},
	{0x493EDED8, 0xCB297F6C, 0x3C77CB89, 0x18400947, 0x6CDF1354, 0x90E714F0, 0xEBEA1D6B, 0xA6986FA8} } ,
	 { {0x05C02AF0, 0x7EE429CD, 0xFFD92E15, 0xD08447F2, 0x3CF7C8E4, 0x36B6C784, 0xC9C72F0A, 0x06B36956},
	{0xB0F3FF33, 0x4A0F46C3, 0x3FF8EBB6, 0xB39D748D, 0x839FFD9F, 0xF7015516, 0xCF1CC84C, 0x8BB797BB} }  } ,
	 {  { {0x28F096FC, 0xD95DBE38, 0xB30988FB, 0x7A8192AD, 0x69F34C37, 0xD4AB69B3, 0x93AE2058, 0x0F417B09},
	{0x728F2695, 0xF2ABC5BF, 0x791AC276, 0x39BE82B3, 0x79076C6F, 0x89C4A844, 0x7F4A9540, 0xB6A5E1B5} } ,
	 { {0x25B2D5D9, 0x6CCB712D, 0x9645224F, 0x7B021C24, 0x31D0738C, 0xC18E8A19, 0x5E246939, 0x021B7CE7},
	{0xCF6B10C4, 0xB120AED2, 0xC725B956, 0xBE5929ED, 0x273E594C, 0x4BB36476, 0x267E2F22, 0x4060652E} }  } ,
	 {  { {0x432CEDD8, 0x24F6F9B0, 0xB85A8493, 0xFD78A506, 0x8A4AC662, 0xC7139CAF, 0xCD9F0608, 0x9A3AD2F2},
	{0xD13337B1, 0x4C7EED6A, 0x94417F7A, 0xF5E08DBC, 0x85DD8D67, 0x225F7011, 0x213239CE, 0x158874A4} } ,
	 { {0x7BD5507C, 0x4FDECF92, 0xFC1921B6, 0x32EEA8B5, 0xF364BD6A, 0x6C5BEA24, 0xE8BEFFC4, 0x9841BE4E},
	{0xE56F7B65, 0x67421C50, 0xBD9E8D15, 0x51771772, 0xAD1378F4, 0xCFAEB991, 0x0F752E87, 0xA196C885} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6216 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6217 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6218 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6219 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6220 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6221 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6222 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6223 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6224 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6225 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6226 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6227 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x6714D39C, 0x96930B20, 0xD06A3FF0, 0x57716945, 0x050C6817, 0xA9B108BA, 0xCAA9C0FA, 0x53EC5AAC},
	{0x084FAEA5, 0x58300E19, 0x0C81CE2C, 0x07EC4C86, 0x5C139A76, 0x1D27A649, 0xA0F73821, 0x6B202F89},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xD034610E, 0x686D21CE, 0xDC0E2996, 0x201A4792, 0xF8472376, 0xCD543094, 0xCD1774F8, 0x1BDEB921},
	{0x24DFCC1C, 0x0AB7E687, 0x275F228B, 0x4514EDDF, 0x14F7D520, 0xD7C8F6A2, 0xB9A9007C, 0x8E61E959} } ,
	 { {0x93457D80, 0x6E080759, 0x56F278DD, 0xFCFA8F94, 0x7EC30A34, 0xA6F4AD97, 0x3F9DF2E7, 0x281037CB},
	{0x8ACAE381, 0xE43E7458, 0x5BBA0CCA, 0xFE48F36E, 0x56FBDCB1, 0x8DFB32FD, 0x61D711DD, 0x79857E77} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x30BC15B9, 0x40971315, 0x69300C9D, 0x83366BCD, 0x3B46A0CB, 0x47B628B8, 0xBE87D585, 0x7648BB12},
	{0xA717E248, 0xE318675C, 0x22D00BEE, 0xAAE168C9, 0x018F3DF6, 0xA6224A77, 0x865A6F9F, 0x8EA46EC3},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xBF8B49CC, 0x7036B32B, 0x974526AD, 0x196B631D, 0x5B98D531, 0xB9AA64BD, 0x9C6B494C, 0x9A323E21},
	{0xED8ABC4F, 0x8CA0F3DF, 0x1593736A, 0x830AFC38, 0x30473E8F, 0xB427575F, 0x04CB9178, 0x7F2983CE} } ,
	 { {0xA4C42EE0, 0xE70A33DF, 0xE7050FEB, 0xEAE834EC, 0x19A423C9, 0xA5617775, 0xC89DE6A3, 0x03C5415B},
	{0x33BD76F2, 0xFF094F62, 0xB75636CE, 0x928639E6, 0x817E9165, 0x6CA0F654, 0x4EB887D0, 0x4ECBEF19} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x3CF9DD56, 0x305C0899, 0xE10FFCCD, 0xF053813B, 0x4C8715A8, 0x6B06A1D9, 0x9F7D4B14, 0x344541F5},
	{0xDEBF5D91, 0x17966179, 0x0A1EA86A, 0x25793F44, 0x437F9E0C, 0x53F8C3A5, 0x7528EDCF, 0x9AFD15CA} } ,
	 { {0x736A6EF7, 0x1616919C, 0xB294489E, 0x004616E8, 0x2DEF2C79, 0x9B39A481, 0x662B272B, 0x1411FDE4},
	{0x312D1868, 0x6A3339C2, 0xBF3E11D3, 0x5798310D, 0xF2AC7792, 0x7F21831D, 0x132557E4, 0x6CAAFDAE} }  } ,
	 {  { {0x29E8F797, 0x55AC63AA, 0xC568C261, 0x61E4D945, 0x4EF05C85, 0xAB38AB8A, 0xD7781C26, 0x73097A3A},
	{0x245847D3, 0x65BA0D76, 0xAE510EE7, 0xA89DC759, 0xD5265F89, 0xFA319E0A, 0xC00A8D49, 0x41C561E5} } ,
	 { {0x6B31A37B, 0xE6E8936A, 0xBF24DE83, 0xFE612734, 0xF7803F51, 0xFEFB02CC, 0x24409905, 0x9C7A17B2},
	{0x488D70C7, 0xD874E5B1, 0xD4DDDDE9, 0x8C995103, 0x82F38A33, 0x7286E29A, 0xD331F882, 0xA98B1E69} }  } ,
	 {  { {0x6DA61D9A, 0xF20F22FE, 0x983B71EC, 0xB8276A34, 0x10D8C5CF, 0x8333FCAB, 0xA939D418, 0x0E554A5B},
	{0x4A38AD7F, 0x320730EB, 0x65371544, 0x9EBE880C, 0xB96C2911, 0x68C143DC, 0x3F414086, 0xB6B48E0D} } ,
	 { {0xDAA03D3D, 0xE1CB1D16, 0xBFCF85C6, 0x0C3B9205, 0x4C011E22, 0xB85A2630, 0xB50F782E, 0x014C29F4},
	{0xE2AD903C, 0xA8BC450E, 0xB9AD8D0C, 0xE80DCAAC, 0xD5EE6622, 0xE21131F0, 0x3DB24D90, 0x5D4DD34F} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 6228 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 6229 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 6230 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 6231 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 6232 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 6233 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 6234 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 6235 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 6236 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 6237 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 6238 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 6239 a211");
	}
#else
	{
		static ecpoint_fp var_a = { { 0x00000001, 0x00000000, 0x00000000,
				0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, {
				0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
				0x00000000, 0x00000000, 0x00000000 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xDE4A4459, 0x88C92DD4, 0xCE4795B0,
				0xB846C760, 0x38A24199, 0xFAC26057, 0x7A55BD79, 0x4C9C2176 }, {
				0x9D78F5BE, 0x16CD6F5A, 0x026563F7, 0xE39EE7FA, 0x03EBD2F2,
				0xB6436EE8, 0x2180F37C, 0x6B994492 } }, { { 0xBDEEBD2F,
				0x8567D8AB, 0x1577FAAB, 0x1D03D47D, 0x54B79EAE, 0x0C4D961E,
				0xF9E1F786, 0x1C93D08B }, { 0x1F3F2BCD, 0x55AA4FEE, 0x76EE60E0,
				0x22251003, 0x4D2D4AEB, 0x3CDC5A4E, 0x80D133C6, 0x00892633 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x49807E59, 0xF7F390A5, 0xB333A5FB, 0xBE998450,
						0x2488CDAB, 0xFBDF81FD, 0xC4F4AEF8, 0x000AACEF }, {
						0x29CE2476, 0xF68BB9EF, 0xBF361C80, 0x62D1A43E,
						0x6689442F, 0x6B4A5683, 0xBF7CB5DB, 0x82C570C8 } }, { {
						0x9BE719DD, 0x0246F5C8, 0xE268C39C, 0x3592E150,
						0x85158430, 0xC6E05731, 0xC8D431B5, 0x1C03F3A2 }, {
						0xB0FE957A, 0x80CB6C1C, 0x1B111508, 0x42C94B5F,
						0x42C2DF42, 0x052E7405, 0x5150485C, 0x02051C71 } } }, {
						{
								{ 0xEBC0CDC5, 0xED93105B, 0x10D41928,
										0x159EDE75, 0x0BD9C548, 0xD294B60A,
										0x200D48BD, 0x8C7E0F5A }, { 0x0AADFAE7,
										0x75808A10, 0x4B0A8C91, 0x062511DB,
										0x8E221799, 0x972FFA27, 0x618753B3,
										0x12E15410 } },
						{
								{ 0x890C4F31, 0x5CD19C60, 0xC69B30E4,
										0xDDFDB011, 0xC9B38409, 0x8B40D324,
										0x4195EB3D, 0xB359FF22 }, { 0xBDEEAADF,
										0xB102F895, 0xDF7EFABD, 0xEF26EC4F,
										0x2C4C1BF3, 0x44471577, 0x8E6D9C05,
										0x3AC70264 } } }, { { { 0x0DBF5F76,
						0x7752CCC2, 0x7AE5B076, 0x399BED08, 0x5AB12ED3,
						0xBD631B54, 0x0EF14B0E, 0xB31EBB42 }, { 0x380FB934,
						0x737B676C, 0x45EB5206, 0x23144999, 0xEAAC3F4E,
						0xDC225B96, 0xB528EC6F, 0x27F8D8E8 } }, { { 0xAD6BF123,
						0x24334270, 0x020DC770, 0x92229046, 0xA8A9CFC4,
						0x7457B158, 0x3D578BBE, 0x5CD0562D }, { 0xF70FE8BB,
						0xCB2CE032, 0x42347E4C, 0x6D94E531, 0x201389F8,
						0x35306AA4, 0x38AAD244, 0xB59879D9 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 1 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 2 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 3 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 4 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 5 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 6 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 7 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 8 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 9 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 10 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 11 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 12 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x00000001, 0x00000000, 0x00000000,
				0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 }, {
				0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
				0x00000000, 0x00000000, 0x00000000 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x9B4B229E, 0x8713215B, 0x21DCAC37,
				0x14CC2C47, 0xE12F7342, 0x2F532213, 0x4645A982, 0x875EF897 }, {
				0x01ABC06C, 0x63C4341E, 0x8B8051C9, 0x21990463, 0xD16ED649,
				0xF0B6C9D8, 0x8B772478, 0x9B10B6EF } }, { { 0xCD6CB02B,
				0xA5F80739, 0x4E5473B8, 0x9E92767F, 0x504677FB, 0x3BED2325,
				0x12D4A179, 0x77A1FA06 }, { 0xEBDB98CF, 0x677B616A, 0x999D473E,
				0x0DBDF309, 0x26925630, 0x310B9879, 0x3C2B5FA4, 0x9A8805F7 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x1723AB25, 0xFF610CA1, 0x078EC43F, 0x6C64201A,
						0x24796DE6, 0x7EE6BD48, 0x4A49BB4A, 0x2CB6AE20 }, {
						0xB5422ECB, 0x3F496717, 0xDF1BFAB4, 0x6BCEF543,
						0x33C86C3B, 0xD655B10B, 0xC0B54961, 0x7943977B } }, { {
						0x76CFEE2F, 0x25C06E96, 0xA55AD6CB, 0xB07E1C8F,
						0xE81389CA, 0x805E806A, 0xD9AE4AF5, 0x01A18588 }, {
						0x931F217D, 0xFD1B2130, 0x7431881B, 0xA384474C,
						0x04C025C1, 0x6AE1C28A, 0xB81664E4, 0xB74835A5 } } }, {
						{
								{ 0x5586E497, 0x433EC447, 0x76AA868D,
										0xA7AE95B7, 0x9CFC4D66, 0xEFC8F243,
										0x25326498, 0x705E69ED }, { 0x471844BE,
										0x4A1F40F4, 0x690881F3, 0xE545C179,
										0x7FE095E0, 0x37879A21, 0x142003CF,
										0x49EAFCE3 } },
						{
								{ 0xD2A6F3F5, 0xE556D738, 0xF9AD53A4,
										0x6CE9C72D, 0xD5B602AB, 0x2491BC70,
										0xF9A32289, 0xABC0E9CE }, { 0xAD43B57F,
										0x825CF747, 0xD0E7B8E0, 0x816BB37C,
										0xC95C4A6D, 0x42F153B4, 0x3001712E,
										0x3F2C0489 } } }, { { { 0x1F1AFF08,
						0xC0DF5DB5, 0x41BDD899, 0x524543ED, 0x2460562B,
						0x6FBDE3E7, 0x2645C3E1, 0x43BDEFCA }, { 0xACC5EFA9,
						0x60321DB7, 0xA26B1C87, 0x78EB4A4B, 0xDE859BA1,
						0xB5FEC577, 0xEFF9469E, 0x998050C8 } }, { { 0x1B1ECB7D,
						0x81168A4E, 0x6E2E3ECF, 0xFB005068, 0xE11C1A38,
						0xFC7B0657, 0x6E7F5258, 0xA6BDD560 }, { 0x8241AABE,
						0xB980C0B5, 0xE52940F9, 0xFE40F5D0, 0xC8C214C3,
						0x66986B18, 0x3B901651, 0x1774AEF9 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 13 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 14 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 15 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 16 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 17 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 18 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 19 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 20 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 21 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 22 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 23 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 24 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x2C7A24A6, 0xE34CE96A, 0x7372BDD8,
				0x07E8A227, 0x0FE3E4D2, 0xAE53B8D6, 0x550190F3, 0x9C14CD0F }, {
				0x98A3D295, 0x3BA444BF, 0x82F05E42, 0x2E56AC52, 0x36E8F6FB,
				0xB58C8980, 0x292D2E25, 0x3005F576 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x5B4197F9, 0xF1B6F53B, 0x873200DD,
				0x5DF0803D, 0x446AD4A2, 0xF31A66D7, 0xA9B4D922, 0x58E96B51 }, {
				0x2A2320EE, 0x03C60415, 0x096CD312, 0xFCD8891E, 0xC4DB5935,
				0xD4FAC6AA, 0x3D6D2C15, 0x6EE67510 } }, { { 0xB1079A62,
				0xF06C1590, 0x49A176D6, 0xF3EFBF8F, 0xD134DD74, 0x2ABEF612,
				0x4CB327F0, 0x0F1EAFEE }, { 0x63477BE3, 0x89A60E2A, 0xC2BA1EFA,
				0xC8E145E8, 0x088F978E, 0x8ABDFBDA, 0x036D3C4C, 0x1A5B7742 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x8D47895C, 0x3E234614, 0x55A5C85A, 0x9C138C8B,
						0x56337898, 0xAE153089, 0xED0F8A9B, 0x742593DB }, {
						0x4E39B5C5, 0x412DF7A0, 0xD796B56E, 0xAEE8A20B,
						0xA449C67B, 0x8BB50529, 0xB9D4101E, 0x2F1C7DED } }, { {
						0xBE5F847F, 0xCB769F69, 0xD16F67FB, 0xEC1D7189,
						0xD89C6EA9, 0x4E2FEF1E, 0xEC767F94, 0x32E94804 }, {
						0x7F5A8361, 0x5B61837A, 0xA1539CA9, 0x19C519F9,
						0x015996E3, 0x48E6FDAB, 0x0AD96E46, 0x0BC04416 } } }, {
						{
								{ 0x8FB70947, 0x9460E37B, 0xC7B1A7DE,
										0x8A37C82B, 0x910CB80B, 0x75166B9A,
										0x3B4C6781, 0x89B46A87 }, { 0x17501FEE,
										0x2A1E2683, 0xF7432AA7, 0x4059840C,
										0x8AD13448, 0xBFC80D31, 0xF9B323DA,
										0x9701C619 } },
						{
								{ 0x845CFD59, 0x04186E75, 0x1B36B8FD,
										0xDAD111A5, 0x7B6B5DEF, 0x08EFED10,
										0x88A0B7F0, 0x873C6929 }, { 0x179049F2,
										0x65B6B297, 0xFB4F6233, 0x2505A4E6,
										0xF5651436, 0xAD49A27C, 0x50BA5F71,
										0x1E1DD21B } } }, { { { 0x055E67B5,
						0xEDEF8930, 0x1ACC5D16, 0x75937AB7, 0x3D423794,
						0x8D00FB2A, 0xDE1BF680, 0x4721754E }, { 0x4DCD5BAE,
						0x9D27F93D, 0x9C3849CC, 0x366B9F53, 0x8513C300,
						0x67154853, 0x55C577AD, 0x765B33BF } }, { { 0x7C1BDEBC,
						0xBEBC9A95, 0x67891E20, 0x5573D2E0, 0x5130DE6E,
						0xCA496729, 0xEBEAB156, 0x0243132E }, { 0x4962D0E1,
						0x35422B67, 0xD9F07677, 0x46F21462, 0x191AE493,
						0xB5C0AABC, 0x46B4AB92, 0x9E3635D7 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 25 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 26 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 27 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 28 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 29 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 30 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 31 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 32 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 33 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 34 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 35 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 36 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x988CA7C9, 0xD5220DD7, 0xCAFE9C0C,
				0x97BB8060, 0x56F38470, 0x1D85A82B, 0x86E3D911, 0x82DB6B6F }, {
				0x96D068D2, 0x5F1B7D8F, 0xB5413B1C, 0x0A6FCBF9, 0x4B917E16,
				0x500EE1F4, 0xF07B00FC, 0x2D5549BA }, 0 };
		static ecpoint_fp2 var_b = { { { 0x10F8EA13, 0x2355FB14, 0xA0A95F68,
				0x247F6EEB, 0x556C569A, 0x052CD073, 0x7DA24F43, 0xA484298D }, {
				0xFC9EBE12, 0x6C36680D, 0x18620BD1, 0x14D84E5F, 0xA1D008E8,
				0x5C72254E, 0xB3D08A59, 0x676571FF } }, { { 0xBDA76C94,
				0x190BF403, 0x25192FA2, 0xCC1FBE2C, 0xDA59413B, 0x213CC808,
				0x2EF8335B, 0xAF343AAC }, { 0xE61D316E, 0x9134D1DB, 0x4C19E11B,
				0xDEB505D5, 0x17D5F561, 0x34B4EC61, 0xA72F8A7D, 0x08701ACA } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x97391DEB, 0xF9D7D3AF, 0x5A7E03B4, 0x45076175,
						0x86C860AC, 0xA637F26D, 0x7DD99115, 0x3910E622 }, {
						0x31464884, 0xEAF41032, 0x2F7FB47F, 0x3B0887F5,
						0xA8676F47, 0x6232C9B4, 0xCD255176, 0x882078F7 } }, { {
						0x644B243F, 0x8E111461, 0xDA4E8266, 0xA0E2F589,
						0x8C98E941, 0xA7CAF1C3, 0x00C0F7F4, 0x4136A7EB }, {
						0xA9A8795F, 0x6470861D, 0xE96BABB2, 0x64449BD3,
						0xD1EFE662, 0xE3486B32, 0x145D8572, 0x773DF86E } } }, {
						{
								{ 0x50CA5C3F, 0x9974B74B, 0x045AD8C6,
										0x8A0B8AE6, 0x4E8F6B6B, 0xAD056F1E,
										0x776C731B, 0x054C4AC9 }, { 0xD57B3AD8,
										0x8582D26C, 0xE427FC10, 0xEBED2346,
										0x7A4E0E86, 0xFC6198A8, 0x19B02F57,
										0x17C6DDCF } },
						{
								{ 0xEED8FCA9, 0xEFE1E1C8, 0x7C500C13,
										0x56764C89, 0xF878E255, 0xE4ABBBCC,
										0x5573A447, 0xA4CE4457 }, { 0x74AE6B61,
										0xB967693E, 0xDB75DE9D, 0x4B188AB2,
										0xCC4EB81B, 0xF723F3BE, 0xEDBD30EE,
										0x33B85C42 } } }, { { { 0x4ADF149B,
						0xD02D1385, 0x00DB599B, 0x763C4EE3, 0x310E516F,
						0x96D83084, 0x729D1E99, 0x10707A1D }, { 0x0577A415,
						0x31BABD26, 0x16CC36DC, 0x078991ED, 0x86331978,
						0x9F13330A, 0x03559FD0, 0x2BD708D2 } }, { { 0x5CCAE9BF,
						0x0E2F0985, 0x97C9BD99, 0x1B640E6A, 0x933A6C7B,
						0x60A949F3, 0x9AFD4873, 0x08085FFE }, { 0xD5531BA1,
						0xEF92059C, 0xED327A6B, 0xD8795A15, 0xC866041C,
						0x79175781, 0x8C7CD744, 0x9CC942E3 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 37 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 38 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 39 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 40 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 41 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 42 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 43 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 44 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 45 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 46 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 47 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 48 a211");
	}
	{
		static ecpoint_fp var_a = { { 0xC0554FC6, 0xA431BAD3, 0x750579B0,
				0x5018A5F7, 0xD1B3000F, 0x3DA4AA0F, 0x2C4763C6, 0x8B1543FD }, {
				0x77F0FB76, 0xDBD45D6A, 0x20B558C7, 0x8894CE1E, 0xC63FFCE0,
				0x31167E61, 0xED069BC2, 0x4EB65A95 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x04A8C740, 0x790D4368, 0x0B248856,
				0x3DC0B660, 0xF2B4DDDB, 0x8C4AC4F5, 0xA32B09E3, 0x785FA110 }, {
				0xE172EF74, 0xB5D5D232, 0x69B92A6D, 0xC3EA184E, 0x2C46B42B,
				0x03EF84FC, 0x6623892E, 0x189CBBA0 } }, { { 0xE13AB146,
				0x22A0FF48, 0x0CEBE6C3, 0xF8292960, 0x21F38981, 0x57097DEA,
				0xBB456B96, 0xAD83F5DD }, { 0x6477E6F6, 0x11D94570, 0xAD9BEC05,
				0xFC3DFF8A, 0x543B9724, 0x7C357996, 0x6BE0083C, 0xB7302C50 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x3BB97DF8, 0x77399F28, 0x915408D1, 0x06F40EF9,
						0xA479347B, 0xBC61879F, 0x386477FD, 0x3BA01512 }, {
						0xBCEAE628, 0x938E83C0, 0xC2DAF78B, 0x5AA34F5F,
						0x7559E03A, 0x166CF387, 0xCB254C5D, 0x9BCBFC66 } }, { {
						0xF11AF712, 0x7002DB56, 0x32388885, 0x3234C84F,
						0x0496694B, 0x222178BF, 0xDA695FD8, 0xADEB22F9 }, {
						0x1FA2CD4D, 0x2D8D1B71, 0x6A61224E, 0xE2BC174C,
						0xAA7EAA68, 0x8B8E95EC, 0xE2459E3D, 0x405E8D49 } } }, {
						{
								{ 0x20283D1B, 0x4BF2D669, 0x8EF906C9,
										0xC9E842F9, 0x53ECE645, 0x72475A06,
										0xF99A7A80, 0x9CFB7940 }, { 0x5CE9F39E,
										0x891EF249, 0x501F5BC7, 0x285C230B,
										0x834DD7E6, 0x9FC6D800, 0x86C237C8,
										0x2C490CD0 } },
						{
								{ 0x4B5ECD85, 0xD5B208DC, 0x7A1A56CB,
										0xA818F264, 0xE6D5879C, 0xD14C0F0A,
										0xC51AD421, 0x981D08BC }, { 0xB92FD93A,
										0x49017E50, 0xFF685690, 0xBCABFF92,
										0x2AD8ED60, 0xECF776A3, 0xD96FDBC0,
										0x2A3C9269 } } }, { { { 0x60B52FC8,
						0xF74A6443, 0x54BE26C6, 0x1D7E0BA8, 0xBD670F5C,
						0x08F846F0, 0x047500F6, 0xB9BC33F3 }, { 0x101CBE04,
						0xE0B70F04, 0xB9DE2639, 0x0A48AFA9, 0x4769619F,
						0xD8124A6A, 0xCDB77E6A, 0x46235BD5 } }, { { 0x36E44EA7,
						0x0D2A552A, 0x30A6555D, 0x40F70846, 0x0F5D698B,
						0x027ADD96, 0x734393B5, 0x4203D581 }, { 0x43560584,
						0xB1E0A0FD, 0xECA18EA3, 0xB65C0116, 0xB8158C16,
						0xE51D221C, 0xF8918DDE, 0x01EAD57C } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 49 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 50 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 51 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 52 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 53 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 54 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 55 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 56 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 57 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 58 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 59 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 60 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x4F2FE7D8, 0x8D116273, 0x174B0395,
				0x173BE315, 0xB4A9687C, 0x5F0108D5, 0x3A81AE72, 0x984EE162 }, {
				0x6F339C7B, 0x34F7B9A5, 0xE81D4DC5, 0x03D2A9FE, 0x18BEC56D,
				0x1B009D0C, 0x7ABB396B, 0x2903E2F4 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x0749EB12, 0xE9B33367, 0xCACDB675,
				0xE03BB82F, 0xF93EB3AA, 0x1D479FB4, 0xCB948DE4, 0x72D2C9C8 }, {
				0x02BF3058, 0x28F1A05D, 0x9B870B0D, 0xB68D5E8A, 0xC4F27BAC,
				0xD04BDD7C, 0x801CB780, 0xB5E0FF38 } }, { { 0x5F4BA478,
				0x29B22ACE, 0xA20C0E54, 0x6C1170D1, 0x93C5683F, 0x52C916F1,
				0x37DFE097, 0x76FF7B97 }, { 0xFCD8213B, 0xE675C870, 0xFFBE8973,
				0x8F7A40FC, 0x42F1D013, 0x26CAB2E9, 0xF785903D, 0x4FDAF395 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x21DAAD68, 0x34DA558B, 0x9220C846, 0xDDC7E208,
						0x973C5F4A, 0xD825F32E, 0x704E616A, 0x09171A4A }, {
						0x6CB2EF1C, 0x9C65D0E2, 0xD1401A94, 0x18466363,
						0x63C992EF, 0x1F454640, 0xDEED355D, 0x19B41915 } }, { {
						0x5A594036, 0x3669FD11, 0xA648BAE8, 0x6A2A35EF,
						0x1324A199, 0x5BC79450, 0xF21792F6, 0xA6BB6E65 }, {
						0x43DB0104, 0xE7006ABB, 0xD65EB2F3, 0x7D46C2E5,
						0xF4C74C1F, 0x22E09CFC, 0x4E75431D, 0x325ACD78 } } }, {
						{
								{ 0xF15B4D85, 0x9C4939F5, 0x29156A25,
										0x6417ECD4, 0x5F4AA330, 0x54A347F2,
										0x11DD31F9, 0x3BF8E1C9 }, { 0x0A75CF96,
										0x4CD6B94F, 0x721896DD, 0x2515D13C,
										0x6DAD7343, 0x6703E422, 0xA03AD8F5,
										0x5C47C211 } },
						{
								{ 0x1D68E457, 0x03944145, 0x928B6D80,
										0x8D672482, 0xAD8F8921, 0xAB53A715,
										0xA06E7CC7, 0x863E7A1D }, { 0xE5E39804,
										0x00C86AFE, 0x8B752766, 0x3AD30AE5,
										0xC997813F, 0x3289182E, 0xF7FE104C,
										0xA4EFC8F9 } } }, { { { 0x4E64B6B0,
						0x40FF5C23, 0x96C03B36, 0xD1C7EEF5, 0x19B69247,
						0x02F9F55C, 0x405A4262, 0x0A25D087 }, { 0xBB72699E,
						0x2667A439, 0x4AE22F88, 0xD1065CB5, 0x301A34CF,
						0xD24C8604, 0xB5541839, 0x14B1ADED } }, { { 0x0D902B7E,
						0x7420EB02, 0xC0963A4B, 0x40021642, 0xDCB0AF14,
						0x05AEA438, 0xF6497C38, 0x0CDE4331 }, { 0xF20F0A9E,
						0x75D28CBE, 0x2EC0F71F, 0x66939F05, 0x74A4CEC9,
						0x81F08E62, 0xC1D53D32, 0x2CE8D42A } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 61 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 62 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 63 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 64 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 65 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 66 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 67 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 68 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 69 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 70 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 71 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 72 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x1403DA8B, 0x73CAAF1D, 0x2C2FB73B,
				0x9E320D11, 0x3BA6CBB6, 0x30A2E4F6, 0xF4D0D824, 0x80841AEF }, {
				0xB0560C8E, 0xC197B1B3, 0x81A44979, 0x16972DBD, 0x3BC60F90,
				0x0C2FFC95, 0x0B9982B3, 0x70C26409 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xD2853480, 0xDB1D880C, 0x8B5C2EB5,
				0xB2F444C2, 0xD14C7217, 0x024C9571, 0x28F93B61, 0x2C9EFFFB }, {
				0x83043524, 0x381F87B0, 0x07DD13EB, 0x4623ACAF, 0x02147760,
				0x992585DA, 0x44DA31D6, 0x3BC0973F } }, { { 0xE2A219AF,
				0x92BC3D1F, 0xEE2C0CEE, 0xFC4D7CA2, 0xB2F92A69, 0xB771555B,
				0xFBFB4321, 0x4E93E738 }, { 0xA5F07B30, 0xD78E11DC, 0x527FFCEF,
				0x1DEB5775, 0x32C9486E, 0x46EFD78F, 0x9A85DC58, 0x00FE7D54 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x256A9EDB, 0xA1EB440F, 0x0BF13DFC, 0x023ECC50,
						0x676C4AE2, 0xFE8FCA1D, 0x97663B87, 0x5F99BAD5 }, {
						0xFD715C90, 0x7BE2033D, 0xEDB48A96, 0x44891FE0,
						0x23BEEEDD, 0x2BE23807, 0x71D2EF78, 0x3445BF3C } }, { {
						0x17E10D2B, 0xAA6F378C, 0x7E234AB8, 0xB5E19279,
						0x244D8959, 0x88D0F84C, 0xECEB18ED, 0x795C4C7D }, {
						0x7881707D, 0x6B4F3AF8, 0xC926E5EA, 0xAFA12DAB,
						0xE57D0D76, 0x633831F0, 0x92597FC0, 0x7BF40E9B } } }, {
						{
								{ 0x7E9AA7E7, 0xB8095A15, 0xE99E4B14,
										0xCF47034D, 0x5CD3D8AD, 0xDE6B8DCE,
										0xCCA72254, 0x67B1E9C6 }, { 0xDF2F9EB1,
										0x08A12CF2, 0xD1ADE766, 0xABDB1605,
										0xA6AE56D2, 0x142F5E03, 0xCF3856DF,
										0x0FD4010B } },
						{
								{ 0x2DEF7E51, 0x63F42934, 0xE4F65B22,
										0xFADFF960, 0x0B352B7D, 0x6594FCEC,
										0x805AE2E9, 0xB0B84B79 }, { 0xC09248F0,
										0x3AB29AE9, 0x02B1C57A, 0x4D300D94,
										0x3A1B0F78, 0x0B2B34D4, 0xA5B8B7D6,
										0xA5E98780 } } }, { { { 0x0DB880D2,
						0x0DAB2E44, 0xDA1E033C, 0x98015E88, 0x5C0BE8C3,
						0x721CC3B8, 0x4EEF04AF, 0x49C1B4AF }, { 0x7846A68B,
						0x4A5BA137, 0x70CDC261, 0x07268EE9, 0xBF82DED0,
						0xF5151FFE, 0x8DE77595, 0x258CDF74 } }, { { 0xEBA336AA,
						0x0ABF33F9, 0x5654E69B, 0xD2048C93, 0x22D9A37C,
						0x1D575EA4, 0x921E38B5, 0x14714213 }, { 0x1A645C37,
						0x220171AE, 0x6C27EDD6, 0xBE3001DC, 0xE1215418,
						0x8BF60367, 0x725165B1, 0x8BFA4BE1 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 73 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 74 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 75 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 76 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 77 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 78 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 79 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 80 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 81 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 82 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 83 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 84 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x5B8769B9, 0xED5982AC, 0x1917871C,
				0x7644D8E3, 0x64472A83, 0xB4655042, 0x847A28F8, 0x3EA49343 }, {
				0x2F620BC1, 0x000EC799, 0xB50E775A, 0x11422F98, 0xD65E560E,
				0x4B5B0718, 0xD4117BEB, 0x22C599E8 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xF930E2B9, 0x6A96C429, 0xD902B0D7,
				0x30B9F796, 0xE9CCB72A, 0xAD1E8CDF, 0x7F411627, 0xA2467CB5 }, {
				0x0C0BBF47, 0x4F8B725E, 0xAF0235B8, 0xD29119C7, 0xA0C510F3,
				0xC35FE8A0, 0x9C8FF30A, 0xB52A4180 } }, { { 0xE6FC9D3E,
				0xFDD37994, 0xFF64B65B, 0x161EAE50, 0xEF3A13EA, 0x35FF5F86,
				0x03FC765B, 0x676C9D8E }, { 0xCE0B1142, 0x9750730C, 0x8EB116A5,
				0x10D1B43A, 0x52D07A9A, 0x2B44BC9B, 0x7A264C9D, 0x8726F27F } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xA1313237, 0x57EEEE04, 0xE3DB5155, 0xE8CC05B9,
						0xA110E0C5, 0xDE20182D, 0x305DB418, 0x1D86830F }, {
						0x5BE391DD, 0x51B521E6, 0xEA226DC7, 0x36D03CAA,
						0xF1775084, 0x210BD443, 0xC1D72223, 0xAA74DA33 } }, { {
						0xD4231FB0, 0x0B781856, 0x8299FEE1, 0x4A619CDE,
						0x7F4F8FB5, 0x06EB6697, 0x4AD21B63, 0x3D5170D7 }, {
						0x946C0684, 0x2BDCAC2B, 0xCECB0706, 0x97B7D9E1,
						0xB8652350, 0xE70A17BA, 0x0FFA695B, 0x0C22945E } } }, {
						{
								{ 0xD05F7E26, 0x9317CFDF, 0x35D9528A,
										0x1F6591A9, 0xAE9A5576, 0x33F90CD8,
										0x604DB095, 0x1D9549C0 }, { 0x776F4029,
										0x8C49AB50, 0x3EF5D055, 0x7193EBA1,
										0x7C7C9292, 0x54C2233E, 0x2ABDFEE0,
										0x201C7B4F } },
						{
								{ 0x40388019, 0xA600627F, 0xB7A2F9CE,
										0xFC121C09, 0x6EBB7C35, 0x9C7CF3A2,
										0x86A7B315, 0x6BE5613F }, { 0xBEE63327,
										0x98CAD725, 0xC2B9E817, 0x636477E7,
										0xEDA73FE2, 0x503E6964, 0x82975182,
										0x29539F73 } } }, { { { 0x47BFAE66,
						0xE5F15076, 0x438F4C07, 0xEE958B9A, 0x183D2FC3,
						0x440AF478, 0x204702D5, 0xA5949100 }, { 0x9C91CB11,
						0x84964B69, 0x0A096D5A, 0x1F875398, 0x528D9B86,
						0xE3EA9D18, 0xC67B9DE3, 0xB31AFB04 } }, { { 0x463BA9EE,
						0x7678C7EE, 0xD75F6B52, 0x85716692, 0xDE68D581,
						0x10929DDD, 0x2CDF27D0, 0x6C0926D1 }, { 0xBE331030,
						0x6E002F39, 0xC095AFD5, 0x81138E89, 0x24AB274C,
						0x4D32AF75, 0x3B90829E, 0x3DC24DEB } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 85 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 86 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 87 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 88 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 89 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 90 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 91 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 92 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 93 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 94 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 95 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 96 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x4943D8B0, 0x64EAC75E, 0x5022CAA5,
				0x48E2F287, 0x7EF8BB93, 0x9C4CD41B, 0x847618F9, 0x134C7741 }, {
				0x210515AD, 0x6A7FC8AC, 0xC2F5ECBE, 0x0DDF7BA1, 0xF4107FC8,
				0x92CEDF2B, 0xA94BE7B5, 0x20B3590A }, 0 };
		static ecpoint_fp2 var_b = { { { 0x50AE331C, 0xCD4075D9, 0x64C34043,
				0xE32329B3, 0x7061724C, 0x6DC2A53D, 0x6BE4CD60, 0x991C6EFF }, {
				0x1B28FD07, 0xA7AE52EA, 0x0BE3242A, 0x2F53AFE7, 0xA4DBB2B5,
				0xDCE56348, 0x5189B071, 0x524C3B6B } }, { { 0x4F8E35F6,
				0x28847CD4, 0x6A59455C, 0x0910FC4A, 0xEF1B7D8A, 0x390CFA31,
				0x9348D7A4, 0x3B2999E0 }, { 0x95DD177D, 0x44866CB7, 0xD2920D16,
				0x1718AC7F, 0x2444D618, 0x2B75021F, 0x8D6AC6D0, 0x36EEA4E5 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x9079EC40, 0x620A9D41, 0x0FAC2CD3, 0xC379D1D6,
						0x351E81D6, 0x2C2D8EC2, 0xB28A2567, 0xB4A20854 }, {
						0x54AF7E94, 0x9247DBFE, 0xA242AB58, 0xBD61144D,
						0x9EB6BC22, 0x0A725E3D, 0xDB5E8C8B, 0x835F4211 } }, { {
						0x4D454218, 0x25758634, 0x7FB6DA68, 0x6FCF3F0D,
						0x0C1BE931, 0x086FFC4B, 0x2E61AA4E, 0x98D297B2 }, {
						0x8E284BB9, 0xDBA49AFA, 0xFC1FECFC, 0x6932EC9D,
						0x7B831F39, 0x11B3265D, 0xF1E3D51F, 0x0F38C6B7 } } }, {
						{
								{ 0x942A6AB8, 0x2A903C0F, 0x6D5B4DBF,
										0xF2DAC515, 0xF7456D13, 0xCF2242FB,
										0x1B28A482, 0x6405B685 }, { 0x36027D05,
										0x4A34726A, 0xCADB1BA6, 0x4BA871C8,
										0xF935C132, 0xE1C653A1, 0x6609799E,
										0x8AAFD3D2 } },
						{
								{ 0xEB9E69F9, 0x2C954447, 0x88FFC45A,
										0x6C4005B9, 0x6F79A36E, 0xB130EB61,
										0x7DBD661C, 0x6BF0C330 }, { 0xE412DB84,
										0x548330BE, 0x73BA0999, 0xDD9EBD96,
										0x9BDA7BD3, 0xDCFBB2FC, 0x8F354912,
										0x3F748AB4 } } }, { { { 0xFA25AE1C,
						0x0EDE0143, 0x87AFDEFB, 0xA7089545, 0xB2CB1E6F,
						0x7E6DDF2F, 0x3233AD01, 0x0F953ECC }, { 0xCEF009DC,
						0x46E27DA4, 0x37E3DB38, 0x7783CFEF, 0x51C21E78,
						0x6984B661, 0xA29B9D73, 0xA99CBD59 } }, { { 0x3EE86406,
						0x409933D6, 0xA4BCE62C, 0x66FF8DB9, 0x79299CA1,
						0xD5305EB6, 0xC222CC09, 0x5BAE7AD6 }, { 0xFCA6EC5D,
						0x4B7545CC, 0x7C6B3E59, 0x4EB877D9, 0xAE8F9BC9,
						0xE66C8CE8, 0x296EA78A, 0x6E03EF43 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 97 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 98 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 99 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 100 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 101 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 102 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 103 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 104 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 105 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 106 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 107 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 108 a211");
	}
	{
		static ecpoint_fp var_a = { { 0xBFE17721, 0xAA922334, 0x398D81D8,
				0x295B540F, 0x32554F1B, 0x35C45F71, 0xC5686F9A, 0x458E3711 }, {
				0x39AB206A, 0x225E4317, 0xA52E777A, 0x89CFA2C7, 0x84A41581,
				0x3B356950, 0xEEE2CD6E, 0x37D66C72 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xA79A62F1, 0xDC725AA3, 0xA4B2E0A6,
				0x6B728534, 0xFD284F93, 0xB61956C5, 0x99C7C341, 0x28474DBC }, {
				0xC5C0BE14, 0xB4B14F05, 0x355EE2DA, 0xEF862EDC, 0xBCE83E19,
				0xB5A29B98, 0xC7906691, 0x34573915 } }, { { 0xE223B4D5,
				0x3CD34BC2, 0xA708E3A3, 0x514D56EB, 0x25340043, 0xD1853F6C,
				0x95961867, 0x4855F1F8 }, { 0xFE5E1562, 0x8A65FC29, 0x538EDB2C,
				0x453FE706, 0xD5E869A6, 0xC5046071, 0x52BECA8B, 0x813C434E } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x5AC66655, 0xE346776F, 0xE7922288, 0x79C9D25E,
						0x74185825, 0x09CD0A4A, 0xE1931C68, 0xA5544F96 }, {
						0xAD0FB4D8, 0xE2FC749A, 0x2E1F7BC7, 0xB10C421E,
						0xFC3AFB0D, 0x453F3D48, 0x0A623CEE, 0x04975196 } }, { {
						0x7145914A, 0xB4377942, 0xC0D8F836, 0x6E9C1B4E,
						0x7DA8A5E0, 0xB5004368, 0xEEF04082, 0x260210C7 }, {
						0x6DABDEE2, 0xC7867A33, 0x96F48631, 0x8299ECF3,
						0xB346A806, 0x1AF086B8, 0x521EFD31, 0x9A64A785 } } }, {
						{
								{ 0x6901DD4F, 0xFB62917B, 0x98D35EE5,
										0xAB2CCB7A, 0xFE8C7F74, 0x8B257159,
										0x6922508C, 0x703390C8 }, { 0x98E3ED68,
										0x38718BCF, 0x0DCBBA07, 0xA5C1B87A,
										0x620A68C2, 0x2E7B2F37, 0x888CF507,
										0x28C66258 } },
						{
								{ 0x0297EAE7, 0x86C166D6, 0x8E7A8C3A,
										0x1AEF5190, 0x207EF8E6, 0x9EA739C4,
										0xBB66C71D, 0x0CDA5FF5 }, { 0xE9596459,
										0xC842E427, 0x1D8C9074, 0x75190457,
										0x40A396E9, 0xDD737256, 0x7CB57F36,
										0x67AFBE38 } } }, { { { 0x16EBBD60,
						0x716D06AE, 0x772496BC, 0x9907B2EF, 0x1C1B2911,
						0x80E50565, 0x9816244A, 0xB0BB2513 }, { 0xD8A2DA23,
						0xD51AD44F, 0x18336402, 0xA5E7A423, 0x37E847BC,
						0x1E56B16F, 0x5029B036, 0x3F5F4788 } }, { { 0x5D2C187F,
						0xF09D9A51, 0x7041F0CE, 0xD809A918, 0x1187EABE,
						0x78C5E497, 0x9FB3BE5B, 0x2D0710A6 }, { 0x1B117A2C,
						0x47FDECD8, 0x26A745F9, 0x75DBF111, 0x9DC58252,
						0xD2BE14FE, 0x5486AF9B, 0x6699EC52 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 109 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 110 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 111 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 112 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 113 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 114 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 115 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 116 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 117 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 118 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 119 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 120 a211");
	}
	{
		static ecpoint_fp var_a = { { 0xAFE220B5, 0x8B5A8013, 0xEDA348A1,
				0x7DA5CC9E, 0x103436F3, 0xA538BFC7, 0xD4FFA3C0, 0x92300979 }, {
				0xDE57C413, 0xDA2D36DD, 0x9D712336, 0xF396BBBF, 0x75ECEFEA,
				0x52DD8F1E, 0x4B14EC13, 0x1A4B9215 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x37CFDBF0, 0x8F59E631, 0x6B353AB5,
				0x267E7E3D, 0x3AAC3B1B, 0x2F89DC8B, 0x03EC1CBA, 0x36BABD14 }, {
				0xC6AEFB95, 0x9E84B93A, 0x39D319FB, 0xFB4A01D3, 0x3C0A05B6,
				0x10417049, 0xD7587CC2, 0x26686418 } }, { { 0xCD6D1FC1,
				0x886C6D2E, 0x7E8D0BA1, 0x34043B45, 0x343CB346, 0xB0FFF5B8,
				0x1D8EE7A2, 0xB8F36858 }, { 0xF8A67C2C, 0x4162AA6B, 0xBC4CB7AF,
				0xC5653452, 0xCEC76D34, 0x378806D3, 0x25294150, 0xAD0AE122 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x88B5DFDC, 0xD8E33B9E, 0x1A7AED7F, 0x561594CD,
						0x36AFA147, 0x4C1DDB32, 0x56854B75, 0x464A8111 }, {
						0x48B50068, 0xBC892ECC, 0x2E5E4431, 0xA935997B,
						0xE954A2A9, 0x0DC84529, 0xE54041AD, 0x2BB7D422 } }, { {
						0x85EBE61C, 0xD3BCDB5F, 0xCF3005D7, 0xCE5CC489,
						0xF17E36B9, 0x4A51E688, 0xCC49307E, 0x753902F3 }, {
						0xC604157F, 0x187996FE, 0xA14ED8AD, 0x302F2B34,
						0x6423FD6C, 0xFC3CBFDC, 0x5754F157, 0x5E9A0226 } } }, {
						{
								{ 0xF7F2FD89, 0x6C1CB174, 0xA36B64F3,
										0x39D3CC0D, 0x226344F5, 0xCDE4B900,
										0xFE1E7978, 0x038C78C9 }, { 0x2AFAADF6,
										0xD1AD9694, 0xFF687696, 0x1A80C86F,
										0x5553887E, 0xFCC945E6, 0x27EF3899,
										0x1D296A59 } },
						{
								{ 0xB236E9BC, 0x8D846E80, 0x00E8B065,
										0xE355AD82, 0x5D99344B, 0x47599D68,
										0xE6ACA19C, 0x37C4C6C2 }, { 0xE8BB987C,
										0xF9E9970D, 0x2FC73FF2, 0xC5B76956,
										0x04D4648C, 0x29A840C6, 0x19105E71,
										0x01903EB4 } } }, { { { 0x881670E4,
						0xEBE02B72, 0x343E496C, 0x58ACA690, 0x2E415527,
						0x22C999A7, 0x7D75FD68, 0x3A4F9368 }, { 0xFD143F46,
						0xD5F4F593, 0xA92F159D, 0x5346FD22, 0x2CE79232,
						0xF5E2D71E, 0xE275CA00, 0xB6742422 } }, { { 0x2548EA6E,
						0xF59F7697, 0xFE363153, 0x681AB146, 0x8E4FFE74,
						0x62171F9D, 0xF4FBC541, 0x7DF8D80B }, { 0xFCDB092D,
						0xA0A48B8E, 0x7F525CAC, 0x96EB9FFB, 0xC9F27FE1,
						0x6D1B8915, 0x7C55B783, 0x4EBE5B84 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 121 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 122 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 123 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 124 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 125 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 126 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 127 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 128 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 129 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 130 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 131 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 132 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x8338CF39, 0x0702F2D4, 0x862D2456,
				0x11D49ED7, 0x79A4D02C, 0xF7E5894C, 0xE0677B95, 0x1CC98E1C }, {
				0x5B0BE1B8, 0x757D29EF, 0xC6B7C0AA, 0x51EF7864, 0x5482DA4E,
				0x658F0D0A, 0xC16E5958, 0x4F17C5D9 }, 0 };
		static ecpoint_fp2 var_b = { { { 0x39EB9C7F, 0xD44F11B2, 0x0E3D8721,
				0x37E4D043, 0xC604A62F, 0xF9A4568E, 0x7A63D0C7, 0x9B343784 }, {
				0x5D03FAB8, 0x8859E64A, 0x7DB6653C, 0xEAEF3BC8, 0x09D932ED,
				0xCD035E42, 0x5C388693, 0x52AC7E0C } }, { { 0x283CFD20,
				0xFA112446, 0x750B4EAC, 0x452B4509, 0xF53EEA88, 0x6623CD40,
				0x00BBEED9, 0xAF041791 }, { 0x8EBC2386, 0x09A1FB79, 0x549D8325,
				0xAA3F488D, 0x4268E2A8, 0x4652C849, 0x3FBDC4A5, 0x6973E6AE } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xD88DD692, 0x4FA7DF5F, 0xD40E031A, 0xD09EEB66,
						0x9DDB6CEC, 0x4C56FC50, 0x71E935DB, 0x3A014AEB }, {
						0xA15B7592, 0x019E0FFD, 0x8D357AA2, 0x1EA42A69,
						0x0C154249, 0x2A31456E, 0x314A8DD8, 0x17845929 } }, { {
						0xAA49B4B1, 0xF8BE6D4E, 0x49D726EE, 0x9F1F8ED5,
						0x428AD760, 0xEB9BF769, 0x08E5D90F, 0x41E5B6E5 }, {
						0x73D054D7, 0xA43AC765, 0xBD1ADA5D, 0x22DD11BE,
						0x68329A5C, 0x9BF2AF30, 0xD3549910, 0x56CE6DE7 } } }, {
						{
								{ 0x44C2E9E2, 0x388861E8, 0xCA13833E,
										0x0DAA2536, 0x1550968B, 0xFDAAD1EC,
										0xDDCD688B, 0x032E0571 }, { 0xB9C54659,
										0x4DCC1A83, 0x3311713E, 0xEC19CA90,
										0xDBFF2762, 0x5AA5C938, 0x3198391B,
										0x7DCD1F6B } },
						{
								{ 0x3E4F2D56, 0x5001840D, 0x86760830,
										0x5CE85C25, 0x7D2BEF5F, 0x521D79BE,
										0x4F04086D, 0x82B475F1 }, { 0x53A42625,
										0xBF0EE5A0, 0x46866225, 0x52653493,
										0xE63E05AD, 0x891E7CF6, 0x28BCE38D,
										0x73A18A84 } } }, { { { 0xD5337001,
						0xF11C8091, 0xE6BE06B3, 0x572D64C6, 0x5DF38650,
						0x513370C0, 0x74886EC4, 0xB195A1E0 }, { 0xCE4F2269,
						0x1D0ED8C4, 0xE81141A2, 0x45BEE849, 0x4F2C7656,
						0x2D3EBEF4, 0xA8029263, 0x98CE13A0 } }, { { 0xB5907927,
						0x081C1FAE, 0x3208991E, 0xE0B48661, 0x9068E6E2,
						0x2B49BCCA, 0x8A7C7ACE, 0x06DD26F1 }, { 0x081D1FA2,
						0x10928E35, 0x302BED48, 0xDD881822, 0x4F1D8066,
						0x4C5D51F6, 0x4A4A8387, 0x0D82D8CC } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 133 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 134 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 135 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 136 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 137 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 138 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 139 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 140 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 141 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 142 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 143 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 144 a211");
	}
	{
		static ecpoint_fp var_a = { { 0xFD7B3B8A, 0x2319014C, 0xDAFFD54A,
				0xD129D947, 0xDF329FE0, 0xBAA84C66, 0xD2AD5C48, 0xA698C703 }, {
				0x6729BB46, 0xFCE9DCD4, 0xEE8AA3EF, 0x14FB2E23, 0xD26F3114,
				0x709069CA, 0x9D1EDD56, 0x6A1D4726 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xD927455D, 0x072DB81E, 0x4E043879,
				0x5154F2D6, 0xC7D5B3F6, 0xACBD9C35, 0x0D35C83F, 0x15C520F3 }, {
				0xD868A837, 0x4DE46DD6, 0x839550D8, 0xB4A32CB3, 0x728A5960,
				0x13D8547D, 0xA2343126, 0x38059A57 } }, { { 0x3BEA2199,
				0x0CC09116, 0xC4D2928B, 0xB1F8E586, 0x9BD41D52, 0xCAD48306,
				0xE1E218BD, 0x5C889174 }, { 0x51566C29, 0x96B0525A, 0xDB732298,
				0x2B560F4F, 0x5C2C5332, 0x93B4C07B, 0x0138F6E1, 0x3A26E85F } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xF5650604, 0x9CD95852, 0xAB345EA6, 0x4E0ED0B0,
						0x17036736, 0xA7D9E43F, 0xE46FBF42, 0x8EB7BFE0 }, {
						0x6AC25B32, 0xE5061877, 0x6AF28EB8, 0x402CA601,
						0x9B1148E5, 0x4038A12A, 0x8EAEDADB, 0x2B99A386 } }, { {
						0x47EB6CCD, 0xB6462ADE, 0x8D25CFE9, 0xE41D6EE8,
						0x1EDF7018, 0xB1575C68, 0x4C805ACA, 0x84E1B143 }, {
						0x87AB3DA1, 0x5230723A, 0xB5BB2936, 0x76B5F098,
						0x551DC3AA, 0x757E4489, 0xCCF4D9C9, 0xA5CE29BD } } }, {
						{
								{ 0x79436C60, 0xD5CDDEFD, 0x02AB1951,
										0xEBA75DA2, 0x037BD4AF, 0x51623E07,
										0x32BAF4C9, 0x7CDEA167 }, { 0x1A01EBE5,
										0x5A8163EA, 0x02353F33, 0x0BEB859F,
										0xC426CE1B, 0xAF69E57F, 0xB7DB8A99,
										0x44D158AA } },
						{
								{ 0x09F256A3, 0x2B5509E0, 0x6CD3B1C4,
										0x3F500848, 0x37DF8916, 0x6B1C337C,
										0x4C53B755, 0x05872474 }, { 0x85E01CA1,
										0x167C94B4, 0x1304716D, 0x0F74A3BD,
										0x564850EF, 0x46678248, 0xC8B61572,
										0x0106F8F2 } } }, { { { 0xFE54A9D6,
						0x08CEF6B0, 0x2A3BC456, 0xCF347AAB, 0x0BBFF70C,
						0xC8205D57, 0x94060E1B, 0xA4F4C8A9 }, { 0x86889F18,
						0x366F59A4, 0x8358A494, 0x5B220805, 0xF61FF5D7,
						0xBE872B27, 0xF5D231DE, 0xADE207A3 } }, { { 0xFA10696E,
						0x91288815, 0x50F6552A, 0x5C744E9B, 0x3FA66E25,
						0x6C80E793, 0x2EDDB2A5, 0x1F0A7F44 }, { 0xC8B181CE,
						0x0046C666, 0x07526F0B, 0x25AACF97, 0x496A0B5B,
						0xA60FA94F, 0xB883227D, 0xA3BE6CF6 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 145 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 146 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 147 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 148 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 149 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 150 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 151 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 152 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 153 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 154 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 155 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 156 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x14AA047E, 0x6137BF9D, 0x8129C2A2,
				0x9C5740D4, 0x66619BD7, 0x1BD8F123, 0x870D6E5C, 0x6283B676 }, {
				0x70DF2D22, 0x5CB92DB0, 0x7DE35BE1, 0x50ACB1EA, 0x49EE9921,
				0xAF993720, 0x9D07ED52, 0x35E8E06C }, 0 };
		static ecpoint_fp2 var_b = { { { 0xBC954A52, 0x1F1135B1, 0x61791D35,
				0x201111C6, 0xB54B1008, 0xD0A6231F, 0x6581EA5B, 0x82ADEC4F }, {
				0x835C4D66, 0x844CD145, 0x8DCB58E9, 0x9A7B3AAA, 0xA643F99B,
				0x49A10849, 0x3DD92F48, 0x382BA8BC } }, { { 0xB33627B9,
				0x42444D09, 0xC672A91C, 0xE9CA9D3F, 0x9C36762B, 0xEFD2EE21,
				0x878573CD, 0x4A3F67C9 }, { 0x6A60484D, 0xE1B8005C, 0x55603277,
				0xF11BB8F2, 0x775A077E, 0x3E820415, 0x88793486, 0x96EE0EE5 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x2FB8BE03, 0xB8153FB0, 0xBA1FD0A4, 0x2E6EE0FE,
						0xFBE6FA86, 0xC9CF63B3, 0x2C0E1A0C, 0x7B54BA35 }, {
						0xDE57D230, 0x357ABC1D, 0x2F5C7B66, 0x1EA82AD4,
						0x7C71BFA8, 0xF51D43F4, 0x952F4F9D, 0x6EAC180E } }, { {
						0x039303E1, 0x7A0BF393, 0x789C041A, 0xEFB8877D,
						0xE0BE8756, 0xB1839749, 0xC7D7FF75, 0x3329C74F }, {
						0x2D0371E3, 0x4339627A, 0xB8579E10, 0xA1957E40,
						0xB9929AC8, 0x4FBC4717, 0x39094FB4, 0x92954905 } } }, {
						{
								{ 0xB761F85E, 0xCCF2EF78, 0xC14D9E58,
										0x4EFDE6A1, 0x4104CECE, 0x55A89335,
										0x483712DE, 0x2895554C }, { 0xF0753F97,
										0x358B8EA4, 0xFCC091C9, 0xFB96B72E,
										0x04A58D32, 0x9326388C, 0x560D9B1B,
										0x7C54CD35 } },
						{
								{ 0xF916A0DD, 0xAF97908E, 0xBEB8FFB0,
										0xAF0A0B8F, 0x0EDFB9F3, 0x85C65BD4,
										0x5C29AB02, 0xABB44B15 }, { 0x74E46E5B,
										0x726327C0, 0xF1862E5D, 0x3E72530E,
										0xF8B7AD3B, 0x197A0FBD, 0x32B779B2,
										0x76104908 } } }, { { { 0x1FA1CAC3,
						0x8DDE1A48, 0xF1444FFD, 0x9B45AE71, 0x205325C4,
						0xDFE9BFBB, 0x4DECB25C, 0x91282236 }, { 0x455F097C,
						0x69D3B98E, 0x5E899DE8, 0x172F2669, 0x04CE3972,
						0x79C6FFF9, 0x703170EC, 0xB94500CC } }, { { 0x5B8664BF,
						0xA1193DCE, 0x94CF2580, 0x4228A794, 0x0FC8C8A1,
						0x1FA0E6C8, 0x1C2D198D, 0x8CFD18D0 }, { 0x5B78D06D,
						0xE60C4FD5, 0xA7EEE1E4, 0x1A663F38, 0x2C600629,
						0xA60C0A6B, 0xD0B09F25, 0x69C9BE1B } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 157 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 158 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 159 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 160 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 161 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 162 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 163 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 164 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 165 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 166 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 167 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 168 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x90D498BB, 0xA29E4276, 0x5485288C,
				0x169D763E, 0x2B4C9CD2, 0xF15B3AE5, 0x42070664, 0x3C3BBD8B }, {
				0x8FB31BDC, 0x75D5B1E5, 0x99DC27F2, 0xFA913927, 0x0D16AC86,
				0x7B1E11DB, 0x07028511, 0x25248F6D }, 0 };
		static ecpoint_fp2 var_b = { { { 0x3643BB4D, 0x67FF9901, 0xF72C21DE,
				0xC8EDD8C7, 0xF44D7D66, 0xBDA616A0, 0x01010396, 0x7D41D73E }, {
				0x8EA92966, 0xBB069948, 0xFB66D4CE, 0x73C1EFD2, 0x0F6816C3,
				0x15D3A2B0, 0xC1127A0A, 0x1DA21D86 } }, { { 0x76D0790A,
				0xEB3977CF, 0xAFA72CA6, 0xE7F105BA, 0x031B111F, 0xBB445AB2,
				0x3F551756, 0x87DA2CAC }, { 0x3CDCC977, 0xEEFFBB08, 0xC00CAAD6,
				0x911BEE6D, 0x2FF9F367, 0xBFD9199E, 0xBA53AB22, 0x422BA19D } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x8792D13A, 0xA3626554, 0x7E304433, 0xE2BDC71F,
						0x29D8B189, 0x34C462C9, 0x7EBDC4B9, 0x9818D73A }, {
						0xE2AD7261, 0xC6B4533F, 0x07E0AE90, 0x6240D973,
						0x987808E9, 0xF2E24E1D, 0x42FF83A5, 0x83B8109F } }, { {
						0x8BB79D98, 0x6EA9B5B1, 0xCEF0464A, 0xB4603F44,
						0x5903C06D, 0xE77FBB98, 0x7E15769C, 0x3A88DE88 }, {
						0xAC906F49, 0x779096C2, 0x1D94A8A3, 0xBFB04044,
						0x3EB6F7AE, 0x6BF45D3D, 0x61547B9E, 0x14C6C8F2 } } }, {
						{
								{ 0xD65A3D84, 0xA20D3C76, 0x4A46DF84,
										0xB2F20176, 0x4A97C70F, 0xAB4A5A9F,
										0x205E6A14, 0x8E3A90E6 }, { 0x8A08276F,
										0x3C0B6704, 0xFFE91CEB, 0x527137DA,
										0xBB72DA5F, 0x97C2190A, 0x95401477,
										0xAF47C18D } },
						{
								{ 0x3626EDEA, 0xF76AB5D3, 0xE03FA09A,
										0x51E89518, 0x9676035D, 0x283B7E9D,
										0x51F1E4DA, 0x4234A774 }, { 0x6D361E14,
										0x99081402, 0x48BCA2B5, 0x629BD6B7,
										0xA5291D08, 0xB35A054C, 0xB33BCA63,
										0x8A938899 } } }, { { { 0x662A6F4D,
						0xFD4BDAB8, 0xF8AE6815, 0x40E649CE, 0x9E055D13,
						0x828A14EA, 0x0628ABF7, 0x603D9BC3 }, { 0x21C3C0CF,
						0xB000F883, 0xF25ED0B2, 0x28E22A1F, 0x91DD346A,
						0x7CC9A642, 0x88231B2A, 0x28427FE5 } }, { { 0x5B590C2D,
						0x50481063, 0x31D66B06, 0xCBE1E1AB, 0x5B062968,
						0x1AC99B26, 0x49A93512, 0x8EC9D57C }, { 0xEA32C860,
						0xAB248C58, 0x4B37D4E5, 0xF79CB094, 0x5603140A,
						0x412C6B01, 0x62DDEB57, 0xB7753BBA } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 169 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 170 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 171 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 172 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 173 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 174 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 175 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 176 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 177 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 178 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 179 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 180 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x5A4BDA02, 0xE63EB9B1, 0xA074A8A5,
				0xA4447063, 0x6ECE610F, 0xC90796E7, 0x2F575C24, 0xABFB6873 }, {
				0x9E72E192, 0x899486EE, 0x771524D1, 0x5F0488CE, 0x721AE0FF,
				0x4BC3A37B, 0x0CEC6559, 0x4CD34401 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xFEF98A02, 0xD51DA3AF, 0xF9EAD772,
				0x8C4F780C, 0x0733DA30, 0xE0EA735F, 0xAD765891, 0x110A8B8A }, {
				0xFE144A03, 0x8906243D, 0x40BF7BF1, 0xA7AAA857, 0x6BC8222C,
				0xA11FA2D5, 0x59B5E919, 0xB4806A1E } }, { { 0xBBEE18E4,
				0x4A060E2E, 0x212356A0, 0xD8A41DDA, 0x9D34FDE7, 0xC08DADB5,
				0xCED26013, 0x2AA2C11B }, { 0x991707BC, 0x712C0A4E, 0x90EC3B4E,
				0x69983109, 0xB8B1C7EE, 0xBC63540F, 0x5FC01608, 0x5FB4FC52 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x8FC58BFF, 0x95F35A83, 0x345500F2, 0x4B077054,
						0x41B9BAF4, 0x40E8EEFB, 0x84E5683D, 0x034EA62C }, {
						0xBB4424CB, 0x16AAAA19, 0xC69263EF, 0x14D1FFBD,
						0x8EF92E9B, 0x74437AE0, 0x56C2C35E, 0x6629F8C7 } }, { {
						0xE2635B2C, 0x44C48F9A, 0xA62DC316, 0xCEA24E20,
						0xA88DB776, 0x670EBD80, 0x319F3579, 0x54CFD54D }, {
						0x749962D0, 0x19FFBD53, 0x36AE442F, 0x2A898F7A,
						0xA4C176E5, 0xEEDE756F, 0x7D4331AA, 0x20575FE5 } } }, {
						{
								{ 0x2987F5D0, 0xBD6CE6DF, 0x2143EF6C,
										0x16D0488F, 0xE1FEA105, 0xC64BDCFA,
										0x8B8A21CB, 0x41E5F168 }, { 0x73BF6A76,
										0x8EBA0019, 0x234A0831, 0x2BAAD3F8,
										0x87A5600D, 0x279D1609, 0x0E58C41E,
										0x8B8E04E1 } },
						{
								{ 0x78B12B54, 0xA6DB7E34, 0xF193FED3,
										0xED6F592C, 0x89BC86B6, 0xE4BE9222,
										0x8BE89674, 0x5CBF9EE1 }, { 0x9ECF2529,
										0xCEE19715, 0x628E3846, 0x509AC225,
										0x433C43BC, 0xC03336C4, 0x8BE89FC5,
										0x524C76C1 } } }, { { { 0xD0791D26,
						0xE280ACF8, 0xE77F77ED, 0xFBD8D6DC, 0x28947E6E,
						0x5253378D, 0x3C6F7F09, 0x8A15AB3B }, { 0x7C53F512,
						0xB0F44300, 0x5D718435, 0x69CABD41, 0x89511C57,
						0x12EFE9FC, 0x77AEAE9B, 0xB96981DF } }, { { 0xBD4B8666,
						0xA53BCDE3, 0x9BED59DB, 0x30EBB34A, 0xE4F710FB,
						0xAC784EC5, 0x6E54BE5B, 0xB3564AFB }, { 0x1E792567,
						0xA59B91EC, 0xD79A16CD, 0x8C64DB2E, 0x93EA1D23,
						0x89600AC1, 0x0D4BC347, 0x27C7ED8F } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 181 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 182 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 183 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 184 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 185 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 186 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 187 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 188 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 189 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 190 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 191 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 192 a211");
	}
	{
		static ecpoint_fp var_a = { { 0x1145C525, 0xC43E8520, 0xB783A03B,
				0xF7AF45D6, 0x0DC0258A, 0xF402A8DC, 0x147760F7, 0x4C6C7285 }, {
				0x9A6DE261, 0x403B2F20, 0x35099269, 0xE9F69901, 0x72C32182,
				0xB03D606D, 0x6EA423D6, 0x78FD599D }, 0 };
		static ecpoint_fp2 var_b = { { { 0x022994CB, 0x87FD809F, 0x812EBA92,
				0xA8DF8DB2, 0x817966B3, 0x9B5FE57F, 0x63E09563, 0x9246470E }, {
				0xA0F85EF6, 0x0113941C, 0xB466ABDE, 0x818DD468, 0xD82E7401,
				0x69F3CFB6, 0xB0C45967, 0x175AA5DB } }, { { 0x4044FC8E,
				0xFE1C5589, 0x4565DCAA, 0x505FD22A, 0x77214375, 0x33E4A8CC,
				0xEC8C1A77, 0xB937AE71 }, { 0x783C5662, 0xBF0C26FD, 0xD7B47770,
				0x329D630D, 0x0EBFB88A, 0xD25B2102, 0x11D03928, 0xAB4490EF } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x53C0C53C, 0xC98304B7, 0xC6DFCF69, 0x5517A59F,
						0x7BC70DAC, 0x3898364C, 0xF87AA2BA, 0x278C2920 }, {
						0xDC6E2D0E, 0x203E84ED, 0x11F63005, 0x871A5138,
						0x926BCF9A, 0x62A3F82C, 0xBF6D79F0, 0x3B0C735B } }, { {
						0x980E08ED, 0x700A98BC, 0x72CA926E, 0x3A4066F2,
						0x6FCA8F74, 0x0A5F50FF, 0x3DAD071D, 0x4B432B70 }, {
						0xBC8870EA, 0x84BBA4AB, 0xC96EA381, 0x295AAF15,
						0x0E65AD24, 0xF1F44493, 0xECDCD8FC, 0x79667769 } } }, {
						{
								{ 0x743B3598, 0x9B600E70, 0xD1C2AB9E,
										0x545C780D, 0x78642009, 0x013047CC,
										0x276AE0BC, 0x953A9C43 }, { 0xE0FA8EC1,
										0x179CD31C, 0x4D724F02, 0x448774DB,
										0xBFCFBDDE, 0x65FF147B, 0x58B4CDC6,
										0x50525109 } },
						{
								{ 0x8324FDE8, 0x04C3B217, 0x8885C32D,
										0xE56526FC, 0x1FB27885, 0xDE61BAA4,
										0xDC72014B, 0x0DC0C255 }, { 0x3223AE64,
										0x79FEFA6B, 0xABAA77B3, 0x7117CAAE,
										0x04EAD7A6, 0x487FED87, 0xEC71F7E6,
										0x6FB1587F } } }, { { { 0x079BA3F6,
						0x73025C65, 0x6436BF81, 0xB9F2991F, 0x4A84FE31,
						0x849E6CB3, 0x137C68A9, 0xA1CEB4B3 }, { 0x3958A386,
						0x5A106226, 0x46E69DFC, 0x7EA380A1, 0xCAFD4523,
						0x79F0CA32, 0xE349B110, 0x00C3CBF6 } }, { { 0x9240ED5B,
						0x13161A1A, 0x1FECA695, 0x14D84CD3, 0xCDDEC803,
						0x6E082A33, 0xDFBFBA7F, 0x356B1F27 }, { 0xB479A29F,
						0x30BCA93C, 0x74B8F033, 0x83416836, 0x82544BA5,
						0xF3AD77BE, 0xD803D621, 0x70399143 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 193 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 194 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 195 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 196 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 197 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 198 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 199 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 200 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 201 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 202 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 203 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 204 a211");
	}
	{
		static ecpoint_fp var_a = { { 0xAC97BDDB, 0x2D87E8E2, 0xDA19ED15,
				0xBE3A69CE, 0x7161A635, 0xFA1121EA, 0x0A9C9BF6, 0x5240BE40 }, {
				0x180F8694, 0x93BE77FE, 0x629A2BB9, 0x5916FD9B, 0xB34C258D,
				0x31B2DFFD, 0xDA91357A, 0xAD2CD9C6 }, 0 };
		static ecpoint_fp2 var_b = { { { 0xE6362F54, 0x36BCAB65, 0xC6704EA9,
				0xFF0AB639, 0xD9B7FB13, 0x8657E40B, 0x057CB8CC, 0x3B90C2F6 }, {
				0x9A72280C, 0x058E44D8, 0x2E0D79A7, 0x6920EDB5, 0x5C0FD3B5,
				0xB9CFE9FB, 0x8DF16ED0, 0x6338C8BF } }, { { 0x3EB78774,
				0x73BD1FD9, 0xFFAB62B9, 0x1713B856, 0xA816A8CE, 0xBDD7EDE0,
				0x4E92C69E, 0x0E745C6A }, { 0xD5ACA2BB, 0x7270605C, 0x016D92A9,
				0x4D3A1519, 0x7F373422, 0xC6BD2EB0, 0xB77EECD5, 0x687D77DA } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x0D110351, 0xD9184102, 0x167DB339, 0x7C933C46,
						0xDE3CBB6B, 0x15C60FE7, 0xE0F2DAE6, 0x463308FB }, {
						0xBEAB2732, 0xA5DBF5C4, 0xFBC97D77, 0xB2CFC92B,
						0x57983816, 0xD9E5C5B6, 0x122D3C4C, 0x79655B0F } }, { {
						0xF53518AF, 0xFB06F493, 0x021F82AF, 0x31169AA1,
						0x16D6D169, 0x6521540F, 0xDBF8A785, 0x47B239CD }, {
						0x78933AFE, 0x2F10D83C, 0x96A3A3A9, 0xF9DEF923,
						0xD7A7C7E2, 0xAD5AE77E, 0x4603110B, 0x1BB5FC30 } } }, {
						{
								{ 0x031F182F, 0xCA4E9242, 0xE718BB3D,
										0x7FD0C3C0, 0x3347D8A4, 0x837B497A,
										0xB453D72E, 0x5839D16B }, { 0x3363F481,
										0x5BDA0850, 0x61709272, 0xCC676791,
										0x7D08E3AB, 0xF335BCAB, 0x82E76419,
										0x1B19796C } },
						{
								{ 0xC8D5E7F2, 0x758A0CC8, 0xAB856589,
										0x2F477F28, 0xA0E81993, 0xBF42D210,
										0x0B01AAB0, 0x84BE9A35 }, { 0x5BD9EBFF,
										0xA8255233, 0x4534D2E3, 0x4EC6B212,
										0xD0796825, 0x5BFDFB4A, 0xE1BE12A9,
										0x8FD0591A } } }, { { { 0xCBC91CDE,
						0x490ADD3F, 0xF513789F, 0x814C42F9, 0x3AC5BABD,
						0x6DF4392F, 0x92AD549C, 0x26601C23 }, { 0x272E43BF,
						0x2D437EE9, 0x5F5ED115, 0xB0083C60, 0xDB303FB8,
						0x6924C266, 0x72609E56, 0x02207C31 } }, { { 0xF66AC37C,
						0x418A1DC7, 0xB1AD45C4, 0x3D1625ED, 0x6D79AAC4,
						0x9F2097DB, 0xCBF2B1E2, 0x2F98C675 }, { 0x44024E52,
						0x0D3484FA, 0xB8086513, 0x35021FC6, 0x711A9114,
						0xE0A7FB32, 0x2D9E8281, 0x682A30C7 } } } };
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate 205 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate 206 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate 207 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate 208 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate 209 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate 210 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate 211 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate 212 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate 213 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate 214 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate 215 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate 216 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x397314A6, 0xC3240078, 0x3D468246,
				0x0942420F, 0x7A4ACCF6, 0x5D6F1C3C, 0x37848AFC, 0x308E62A7 }, {
				0x54B5F13D, 0xEFBE15E3, 0x2DA6F0F8, 0x9E7BF5F8, 0xEE14480B,
				0x5E75DAC8, 0x0E103BD9, 0x9E686280 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0xF8282EE9, 0xBB526467, 0x7A03D5CB,
				0x9250E458, 0xB2058675, 0xD1EB7513, 0x9721CC44, 0x19D9118F }, {
				0x29ECB97C, 0x813B892A, 0x0541C267, 0xE17C9364, 0x8328571D,
				0x76A8E889, 0xE6D1B45F, 0x7B29D4CC } }, { { 0x99B3CD80,
				0xE737275F, 0xAE85C617, 0x1C1229CE, 0x71B868CE, 0x426153E1,
				0xC106721A, 0x4120693A }, { 0x3002D659, 0x8D518ADB, 0x907786DC,
				0xFAEF6CC4, 0xFBFE3D68, 0x97168306, 0x896BE833, 0x29C9330C } },
				0 };
		static ecpoint_fp var_a2 = { { 0xBFAB40C2, 0x89929551, 0xA784D207,
				0xA0328AAE, 0x8F53863C, 0x75D162CD, 0x69A64F2F, 0x5943028F }, {
				0x980CD2AB, 0xB561FEE1, 0x33C74BFC, 0x421A0D94, 0xE90B2BAD,
				0x75A14087, 0x9C6E86A0, 0x74AFBCEE }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x116B92D3, 0x0632852C, 0xBE6B156A,
				0x50A9C314, 0x4AB6752C, 0x799423A5, 0x85344D88, 0x5D709D69 }, {
				0x8E7F2D45, 0xA728A5AA, 0x73800E9A, 0x26E4D21B, 0xE8738CAD,
				0x4073EB35, 0xC539CA9E, 0xA2DEE3E2 } }, { { 0xF3559B07,
				0x2BDEFB09, 0xC3C23B55, 0x1F0E5AB9, 0xF4570A0B, 0xD266C436,
				0x1B2994F2, 0x0E28E6A4 }, { 0xB4594D58, 0x42AA4C50, 0xA50B5013,
				0x46CBFF1F, 0x75B60267, 0x8B489FA9, 0x88A9806D, 0x646DD76A } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xE0CCAC85, 0xBDAD8C34, 0xF3A33965, 0x8B3AF5CE,
						0x2E25C574, 0x0F1ECB0C, 0x1C9BE0A1, 0x77F905ED }, {
						0x6D274A94, 0x3EC5543C, 0xA464EEDF, 0x3B349E64,
						0x42CAC8C0, 0xB3CA1CC3, 0xE46A9076, 0x4A984FFC } }, { {
						0xCCF0E58B, 0x3DFED6D1, 0x7676EB2B, 0x8C76B3F6,
						0x1028B7AE, 0xCC7B1274, 0xFB272FDA, 0x081907B3 }, {
						0xAF0D1DBA, 0x073D7B6B, 0xDDEAB6CE, 0x56801709,
						0x7F9392E4, 0x23C1BE9F, 0xACF82C5B, 0x7633295E } } }, {
						{
								{ 0xEA0D2FA9, 0xE3D1B48B, 0xF66117CE,
										0x77D14C3A, 0x986F31C6, 0x8A574ECC,
										0xB0DEB395, 0x4E71BE2D }, { 0xC1E34784,
										0xC7601922, 0xFE72B491, 0xBD55A8A2,
										0xC1784BBF, 0x242767EF, 0x12CD4CC3,
										0x47932DDC } },
						{
								{ 0x6F2A4E61, 0x5FD52893, 0x89A73F61,
										0x337F2172, 0x8CE29FAF, 0x87595CE3,
										0x1EA260E6, 0x6A8D24A5 }, { 0x7B4F44B2,
										0x4B78F1C5, 0x1532D2F9, 0xB0AFC2DF,
										0x13ED9030, 0x8ABE778D, 0x730249ED,
										0x19431F1A } } }, { { { 0x4691F065,
						0xA0125AE2, 0x4F0BDAC0, 0xCCC627A1, 0x5572D973,
						0x813B1A97, 0xE1348330, 0x6926C305 }, { 0x5989D0D1,
						0x863718F2, 0x7CA0EBAE, 0x0D5AAFED, 0x304F4C91,
						0x7B9CCDD2, 0xEA559162, 0x6CB321DB } }, { { 0x622F5F12,
						0x53CEC332, 0x1189070A, 0x7C5AA218, 0xDC3BC2C0,
						0x0215432D, 0xCC6EBDDF, 0x529A203C }, { 0xEB73BD13,
						0xA50F5E8E, 0x9FA871C7, 0x523A04DD, 0xC7B646C4,
						0x460A771C, 0xD9DF55B4, 0x1AD9D7B5 } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 217 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 218 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 219 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 220 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 221 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 222 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 223 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 224 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 225 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 226 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 227 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 228 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x29E1ECF4, 0x86474F93, 0xD86B9285,
				0x317B01CF, 0xC2F1D173, 0x06D9E479, 0x0D4018C8, 0x0BA01B3B }, {
				0xA2178B73, 0x4DBE3EEE, 0x61DFA237, 0x08059FD8, 0xB7A7A809,
				0x57257B5F, 0xC23C6103, 0x70870980 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0xEA578D4D, 0x432D3D45, 0xFEED32DF,
				0x9BA918E7, 0xC6D2FD1B, 0x36EB2164, 0x34C90813, 0x5AEBCC55 }, {
				0x3A8C796B, 0xEFEFD910, 0x19C61A26, 0xEBD94139, 0xE52754D8,
				0x95BE9F5A, 0x374CAA36, 0x890634D8 } }, { { 0xD5104115,
				0xE062F953, 0x161A0F98, 0xD433F957, 0xAF3B5E65, 0x86745140,
				0x57018BB8, 0x6DDB40EC }, { 0x6B9F6511, 0xC44AC159, 0x401140A7,
				0xAF9D4CC1, 0xF9EDCDCF, 0xBBD0D25B, 0xF1546688, 0x1191AF35 } },
				0 };
		static ecpoint_fp var_a2 = { { 0x71DD7975, 0x7438C15F, 0xCDACB589,
				0x7267F12F, 0xA4C64A26, 0x7CE2776E, 0x8940F734, 0x5E732510 }, {
				0x21AFA02F, 0x536F00F8, 0xB6A91FDD, 0x981D04AC, 0x81CE1236,
				0x30C3B704, 0x3AB89642, 0xB128B74F }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x82623D3A, 0x87D5579A, 0xE972471E,
				0x8300CB9C, 0x5BD28717, 0x2C7CBA53, 0x264E8BA4, 0xB2CE04B5 }, {
				0x4D394881, 0x255D2DA2, 0xDCCB1DD1, 0x207F7FEC, 0xBAE1CD94,
				0xF8787E05, 0xD6A00696, 0xA84522C2 } }, { { 0x791385BB,
				0xCFBF1FB1, 0x894FE552, 0xEDF59CB5, 0xD1C764D6, 0xA8C87B7B,
				0xE0F9F325, 0xAC7F999A }, { 0x93A89EEF, 0x523F6492, 0x560FFFEF,
				0xD6519A52, 0x8287C2E3, 0x863EB383, 0x6C9915F0, 0x3DC49B86 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x045ED3FE, 0x80EEA8CB, 0x611A1523, 0xF08B6D2F,
						0xF6B98059, 0x048D6CB4, 0xF4418298, 0x7BF40842 }, {
						0x360011DC, 0xB1A4CE2F, 0xDCAAB58B, 0x40A01F7B,
						0xCC053873, 0xB221079E, 0x27B258FE, 0x02CC5FF7 } }, { {
						0x06B6DE93, 0x59071F9C, 0xD4205A06, 0xD02BEEB1,
						0x2EDA8A59, 0x0A1479D0, 0x5C76697C, 0x1D8C107C }, {
						0xDB7BD582, 0x22C6238B, 0x5143714E, 0x9AA74A64,
						0xBFC2E3F5, 0x7A756B24, 0xD8C59144, 0x9421A4AE } } }, {
						{
								{ 0x3E9D2B7A, 0x720C9C5C, 0xA69D051D,
										0x3AE381F5, 0x75BB73FA, 0xD025E957,
										0x5F8D86C8, 0x1F06B880 }, { 0x0371E159,
										0xB05F68A2, 0x5D8EEACB, 0xACC88ACD,
										0x701C69BD, 0x1CEF193F, 0xBFEC009F,
										0xABF59ABE } },
						{
								{ 0x057F12A2, 0x98FC3FAB, 0xC569C45B,
										0x7832D92B, 0xCCD0D7BC, 0x7D2E5A8D,
										0xB7939AFE, 0x98CC453E }, { 0x62B31E26,
										0xC32F1F50, 0xFD47656A, 0x3A48AFED,
										0x2C61F513, 0x66493483, 0x794BFB06,
										0x207ED858 } } }, { { { 0x4423F9BF,
						0x84920EAB, 0x8988F158, 0xEB07493E, 0x541D0000,
						0xE4FAECEA, 0x406AC399, 0x7D07FE3A }, { 0xB613ED83,
						0x07564FB0, 0xE0622BD8, 0x4381229A, 0x941C933F,
						0x44A743EB, 0x15875713, 0x86C98749 } }, { { 0xD4B6EE47,
						0xDA53BB8A, 0xB5844290, 0x108BC9B4, 0x03019553,
						0x739CF2BA, 0xF4BFC9EB, 0x9C15FDB5 }, { 0xAE7802B0,
						0x1D4EA6A6, 0x97EB8612, 0xF315636F, 0x178AEE75,
						0x418559C0, 0x48DC2A9C, 0x83819B80 } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 229 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 230 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 231 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 232 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 233 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 234 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 235 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 236 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 237 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 238 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 239 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 240 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0xD7AAC82A, 0x374081AE, 0x5AD0BD4C,
				0x1DA26B51, 0x55C8B39F, 0x8E882F16, 0xA5A4CD4B, 0x291D1FA2 }, {
				0x3F807DE8, 0x1B8B4355, 0x6D7575B9, 0x592F6938, 0x81E5E590,
				0x252F4082, 0xAF5E57BD, 0x1689AEBD }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0xE4F33E8B, 0x8EE6DF1D, 0x66F4786A,
				0x6E7881A2, 0x212DD07F, 0xFE879047, 0x209A83DB, 0x4CDDE05D }, {
				0xBB6FF243, 0x301E24A2, 0x40B33FCC, 0x83C82988, 0x014D05C5,
				0xAB6C931B, 0x2F28B870, 0xB5059FB3 } }, { { 0x3AA2089D,
				0x940F676F, 0xDF47178B, 0xD9E4B2C4, 0x0FDCCB56, 0x424BF1B1,
				0x547A1203, 0x643D169E }, { 0xF2CF507A, 0xA0B2D44A, 0x71938480,
				0x398233EC, 0x152C62BF, 0xD7CF8C3E, 0x4E7B5930, 0xA6AA0214 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xEC86916A, 0xAE46AD89, 0x076BFFDF,
				0x7071209B, 0x728D8934, 0xF3C58B37, 0x0EE20FFD, 0x819BC59F }, {
				0x3DE1E376, 0x26C6BF04, 0x13AF9066, 0x5E06872F, 0x409F5DC5,
				0x10C0B6DB, 0xA732ABDE, 0x7A171182 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x88B9E7DD, 0x2CFB9644, 0xB72D0FA8,
				0x24DA7AA2, 0x90F29432, 0x848528BD, 0xA0EDD490, 0x633800A3 }, {
				0xA60F2B92, 0x0497AF6B, 0xC8FD3C07, 0x51FEC88D, 0x4388EA0E,
				0x4C1FF44C, 0x7BC09913, 0x95A85204 } }, { { 0x85266F3C,
				0x0E1D7A5E, 0x117C9288, 0xAEBE1AB2, 0x90F78499, 0x75282A22,
				0xA120AE80, 0x89D85399 }, { 0x9696C071, 0xAF815323, 0xF6BBBE82,
				0x00232337, 0xFF9E2C33, 0x94E52B76, 0xE8391E71, 0x24FC25E1 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x1171D930, 0x59AC0D6D, 0x281AD266, 0xB6B0A1B1,
						0xC9811000, 0x1F85BA2F, 0xA297E515, 0xB58AB968 }, {
						0x4EF94058, 0xA93B922D, 0x9BBAD3E9, 0x2C1BC5B4,
						0xE758DEA0, 0xFE3B1445, 0x3EE07847, 0xA51C788B } }, { {
						0x45814662, 0x07F53F1B, 0x9BFE2273, 0x9473E338,
						0x0522B65A, 0xCD8FD209, 0xFA575D77, 0xB52C1C35 }, {
						0x763F6944, 0x6752D945, 0x17D3BAF5, 0xE27BDACB,
						0x705895BF, 0x511C398C, 0x454BAFFA, 0xA4011A45 } } }, {
						{
								{ 0x01BCF66B, 0x50F72C27, 0x0E594CCA,
										0x018E8B86, 0x5C4CBA60, 0x4A7FA04D,
										0xC5861E8A, 0x34CC8B5C }, { 0x020D37C2,
										0x2F64755F, 0xA5DB1511, 0xB7607418,
										0x7D708134, 0x06D11FBA, 0x0CC7B6F7,
										0x65E0B68F } },
						{
								{ 0xAC32E9AD, 0x83204F20, 0x714D694D,
										0x1CC78F46, 0x266B51B9, 0x44353938,
										0x614A7A18, 0x6920DD9A }, { 0x9E956818,
										0xABBE1E19, 0x67D60FC5, 0x5E2AA44F,
										0x9070618A, 0xD1C5C430, 0x3C5E7819,
										0x23EE21B3 } } }, { { { 0xD05644FA,
						0x44DC3865, 0x549FF1F0, 0x93235FAC, 0x5FF040C8,
						0xDD8EA67E, 0x9B1E69A9, 0x009603BA }, { 0x09719C77,
						0x96ABBA57, 0x5D0DEF06, 0x4A15A846, 0x6055C136,
						0xB173FF9C, 0xBA312B0A, 0x21171205 } }, { { 0xE1575EB1,
						0xC619DF26, 0x16C6A65E, 0xA8D4593A, 0xD5CD08ED,
						0x46DA57A5, 0x1FD74329, 0x903F6893 }, { 0xBBBC679E,
						0xB0611C1C, 0x19C4D483, 0x77995E50, 0x68964C59,
						0xF1240FBD, 0xABC193E6, 0x6550224B } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 241 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 242 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 243 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 244 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 245 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 246 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 247 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 248 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 249 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 250 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 251 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 252 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x6028346E, 0xBC6E2B18, 0x02D4B09F,
				0xC0C04E10, 0x887B5565, 0x869B81E2, 0x50F53DA1, 0x3B6EC661 }, {
				0x230DD873, 0x3A481039, 0xC05D6705, 0xBE301ECC, 0xA892635E,
				0x5B01FCF6, 0xDA7B9012, 0x44FD60E7 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x98B9110F, 0x7FB60A2F, 0x392EF77E,
				0xC2A8DA3E, 0x5598B84A, 0xC94C84A0, 0x5766AD49, 0x035E4164 }, {
				0x4534B13A, 0xD46C2428, 0x389149D2, 0x3DC84131, 0x710E6A42,
				0xDF1F974B, 0xB8736C4E, 0x197C3B61 } }, { { 0x43CD4BE7,
				0x2C559FFA, 0x6D724BAA, 0xC5925E36, 0xB744E870, 0xFB46DAC9,
				0x691E1DF3, 0x9BB9889A }, { 0x38965916, 0x2E5BBE1D, 0x3F1C1B87,
				0xC6FCCE11, 0xD7C7A7DB, 0xC2715B99, 0x7C5D8F4A, 0x262B7DCC } },
				0 };
		static ecpoint_fp var_a2 = { { 0x26BDE59B, 0x659D7877, 0x8D29B4F9,
				0x22A2488D, 0x76BFE6A2, 0xCAB84CF6, 0x97F622AE, 0x9E92C497 }, {
				0x778D8DED, 0x33813ACF, 0x4A35CE05, 0xCD447B9E, 0x07AC6661,
				0x1E6C99E4, 0xDBC784FA, 0x0EBA9449 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x2D293BBA, 0xE6C009DC, 0x5630E626,
				0x9C70FE12, 0x1E7578EC, 0xD0C5147C, 0xF76B112E, 0x4D868D17 }, {
				0x6B0947ED, 0xC13A7C6B, 0x3A4FBB67, 0x440F6E1B, 0xFCA2ADE4,
				0x804F9E88, 0x3CCC28D8, 0x014315C5 } }, { { 0x2286D376,
				0x38E9B059, 0xD75CB576, 0xE5FCDD38, 0x49DE0FCF, 0x201C16BD,
				0x60DAA61B, 0xA5E38327 }, { 0xC503C027, 0xDAE350A2, 0xB00B65A8,
				0xD0B2848E, 0xE8CE8B09, 0xA54C7457, 0xE8EC18D0, 0x210F04FB } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xBEAC223B, 0x08C98293, 0xC53CBFD0, 0x97436311,
						0x83155F93, 0x123D57F8, 0xBF382513, 0x22F84145 }, {
						0x7C06BA8F, 0x0849124A, 0xF13A7694, 0x00436CF2,
						0x9ABCFE66, 0xB97B9815, 0xA0C555EA, 0x6062D9EC } }, { {
						0x81BA1F21, 0xFAD24B1C, 0x35EB7913, 0x6840208D,
						0x67EB956A, 0xFC7E5623, 0xB7C2A5AA, 0x39719AAF }, {
						0x87EE86F2, 0xEA8E19E3, 0x8C9A43FC, 0x0B490496,
						0x6AB5A68A, 0xAB4514EF, 0x33462745, 0x77AA669E } } }, {
						{
								{ 0xB74C2779, 0x9EE5FE12, 0x24DDC3A6,
										0x45E18FC5, 0x607B32C5, 0x694586FF,
										0x52DFB62F, 0x84701008 }, { 0xABE8551C,
										0x0EAAF8A4, 0x9AFE5051, 0xACD1CE7D,
										0x63D2F92F, 0xCFBC47E5, 0xD48ED91A,
										0x005BA3F4 } },
						{
								{ 0xA9B89CEF, 0xF2226B9E, 0x5D377FBA,
										0x0DCF5453, 0x2F44C505, 0x06B53C59,
										0x15505094, 0x69DC21CC }, { 0x75A5ED03,
										0xC9F620DA, 0xF647AF13, 0xD6CE127A,
										0xB5F7D4BB, 0xE8F9D7E4, 0xF95EEB8E,
										0x9248C188 } } }, { { { 0x1D6E9B2C,
						0xE7A79FD7, 0x781F820C, 0x086A73EB, 0x6A86B211,
						0x3B376BC4, 0x5840308E, 0x56C82D25 }, { 0xCF64841F,
						0x39FFFD4F, 0x3BFA0ABD, 0x577B7EAC, 0x6AC2C6B5,
						0x407B0380, 0x70201027, 0x593D0632 } }, { { 0xE84753A1,
						0x7C3660A7, 0x7BD82E65, 0xC559AE2D, 0xEB624C83,
						0x89C3F3D3, 0x0057DF75, 0x769C6C82 }, { 0x9268CBA5,
						0xCCFC10BF, 0x46954210, 0x5D12343E, 0x4856E771,
						0x894D39B2, 0xAFE124BC, 0x2C0FA8A7 } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 253 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 254 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 255 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 256 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 257 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 258 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 259 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 260 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 261 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 262 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 263 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 264 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0xF979B442, 0xCED10701, 0xDF0E60A3,
				0x25786554, 0xEAE72BF7, 0x580E220B, 0xDA2DC16A, 0x3AB062DD }, {
				0xFE5F5911, 0x51674360, 0xFC6C280D, 0xB6852ACA, 0x0AA1ED34,
				0x461F38DA, 0x288441F8, 0x79DD2522 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x5C81F1AC, 0x968B68DC, 0x599EF54F,
				0x77897063, 0x48654EDD, 0x50AC163E, 0x58AB4467, 0x8130479E }, {
				0x03E82393, 0xCC8641D4, 0x4EF17613, 0x328B5F2B, 0x28120AF6,
				0x28E7EEE4, 0xA6B6374D, 0x4E78A493 } }, { { 0x3AB7EE33,
				0x9B4422E2, 0xB26869EE, 0xA0618321, 0xAF45034C, 0xBCA3C182,
				0xB97B6E04, 0x8F0BACD8 }, { 0x82A47244, 0x6ED4D98F, 0x8FD0F043,
				0x26D1E7A5, 0xFFC2CEAC, 0x34AE2898, 0x0E955C9C, 0x87774A59 } },
				0 };
		static ecpoint_fp var_a2 = { { 0x8A1843D4, 0x20A3EE68, 0x24FB093B,
				0x448D90C7, 0xE12589DA, 0x74BB241D, 0x2FB08D30, 0x9971FB24 }, {
				0xFD3AD80E, 0x9EA8AF01, 0x5931B6C6, 0x77C9FB75, 0xF438D3ED,
				0x0B4427EC, 0x014E61EE, 0x165E1971 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x8F699DF0, 0x2FA76453, 0xAD84BE54,
				0xA5F7D1BA, 0x61234B73, 0xF583F88F, 0xF8FAC83D, 0x8357C135 }, {
				0xD69F8FEF, 0x65C82719, 0x67E2A42D, 0x3091E7F2, 0x48EBE7C8,
				0x5AF45E7C, 0xC7C918F4, 0x3294AD5C } }, { { 0x00C8F8E5,
				0x71768B3D, 0x3CA70297, 0x2595A11D, 0x25EE7488, 0x06B764BC,
				0x4230C904, 0x9ED9B7E8 }, { 0x415B00CD, 0x9D3F1290, 0xE5D9CAC6,
				0x4E6C2DFE, 0x5A38DF01, 0xE2ADDC8C, 0xE397FF2E, 0x864BB3D1 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xA103B5ED, 0x1BD7A0F3, 0xF3A6BA9B, 0xBB7FB4CF,
						0xB5B39526, 0xC46D3E5B, 0x49B3695B, 0x8831C477 }, {
						0x2AB69520, 0xB884D523, 0x373F68C7, 0xCF58DDA6,
						0xCA470896, 0xFC5AB2B0, 0x650B9991, 0x9E762F05 } }, { {
						0x2E230A91, 0xC02456AE, 0x7F38FAD1, 0x9199F5BB,
						0xA4A299C5, 0x06F3FBC1, 0xC158C293, 0x2F9E3271 }, {
						0x01C88C2E, 0xA76C2174, 0xC4677CE9, 0xA97B89C5,
						0xB3E62404, 0xC4BCF8F2, 0xB63A32C9, 0x52FB6023 } } }, {
						{
								{ 0xD8DD13AE, 0xC060BCC1, 0xFC3BFB59,
										0x5DB70E78, 0x9492D8FE, 0x9029B7F7,
										0x6EBD9935, 0x0026D6E7 }, { 0x744787A5,
										0x0E3508C1, 0xC96B4A13, 0x017894D8,
										0xCB1AB846, 0x22178206, 0x2F936320,
										0x73FC20CE } },
						{
								{ 0x69CD81E7, 0x88F22C8F, 0x0F16EECA,
										0x71955CFB, 0xE46DCA69, 0x47C70A29,
										0x5A9505C6, 0x2F521A07 }, { 0x4C1A2AF7,
										0x3A87191E, 0x32B31211, 0x6388A23D,
										0xFE3F67B4, 0xCA88D97F, 0x2DECA986,
										0x4CBF6BC9 } } }, { { { 0xE20E9B70,
						0x95E15A1A, 0xCBA13A74, 0x69808069, 0x573C0257,
						0x60E784A9, 0x21ED2BBE, 0x9D8BDAFA }, { 0xAA30D4FC,
						0x92B7108F, 0x9F45FEE6, 0x619A311F, 0x4E395E48,
						0xAB6E663F, 0xF7876748, 0x37743FD3 } }, { { 0x592B6592,
						0xCA770516, 0x759A74CE, 0x7979E38D, 0xAB61610A,
						0xF0281278, 0x5FC2A236, 0xA6F3EF19 }, { 0x4D675359,
						0x45E82232, 0xEF250359, 0x2C07804D, 0x54476FF5,
						0xD041FCEA, 0xE46051A5, 0x0F941BFB } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 265 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 266 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 267 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 268 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 269 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 270 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 271 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 272 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 273 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 274 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 275 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 276 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0xC7E140DE, 0xE0185C68, 0x72200DAD,
				0xCDD5582E, 0x2884AA00, 0xA7A3DF8E, 0xF63E3F75, 0x150763F0 }, {
				0xF363D005, 0x93691539, 0x21E95BD1, 0xBA9FCC43, 0xA4C6AAF6,
				0xA39D9C22, 0x406AA7D6, 0x688C635A }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x30AC74C3, 0x7DB024A6, 0x4DA1C732,
				0xF7D435EF, 0x95EFEBA8, 0xF9946333, 0x77B7CCE9, 0x722C1814 }, {
				0x4F16E939, 0xCD68E563, 0x1489B8FD, 0x7E4CCA1B, 0xE1BD76E1,
				0x316B0924, 0xC77D9F2C, 0x4E74B980 } }, { { 0x959D23E0,
				0xB5B7C1E7, 0xB4689CFA, 0xC0D5A03D, 0xA7D3600B, 0x6B99C736,
				0xD08BFCF2, 0x9CB58CA6 }, { 0x7382CCF8, 0x33CBD2E2, 0xA09AAB35,
				0x677BA904, 0x8A20898D, 0x6AB747AD, 0xA73CFCF1, 0x95B74986 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xE622FE24, 0x678B0EE8, 0x3F6AC535,
				0x06CB5A6E, 0xAEB0EEBB, 0xCB851481, 0xB0616ACF, 0xB6BEA77F }, {
				0x4136151F, 0x57022DFA, 0x8F3ECE1E, 0xBC91379C, 0xE71FA033,
				0x7AE56D2F, 0x9904942E, 0x5B2AD4D7 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xD2C5E8A0, 0x7D13FA38, 0x9C497CB2,
				0x652600F8, 0x63F8713E, 0x0608AFD6, 0xE983F74F, 0x29160724 }, {
				0xBE9D8C43, 0x8D6463CC, 0x5EC608F3, 0x464F2EFB, 0xECDEC3AD,
				0x6EE69BC7, 0xEF3014C3, 0x4B786751 } }, { { 0xC9C77726,
				0xEB7EF2D9, 0xFBCE1A77, 0xA4597D8E, 0x72A6E297, 0xC3DD5C5A,
				0xE456BAFB, 0x114E7722 }, { 0x75ADF774, 0x5FAD49B5, 0x99236FDE,
				0x5F79DCB3, 0xF5889E88, 0xA613092A, 0xAD710BB9, 0xABD92BE5 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xFCA2E663, 0x853E40D1, 0x62E0BB07, 0xA00C003F,
						0xD4750186, 0xA66C951B, 0x232D7A84, 0x4FD84D76 }, {
						0xD05472E2, 0xE1E5CD8C, 0xB69AA6E0, 0xC762A37B,
						0x25ADE888, 0x9A69E5E9, 0xD4022EA6, 0xAC33945E } }, { {
						0x0B0D77AB, 0xC7CAF0D3, 0x82E8118B, 0x18EE8DDB,
						0xD165716D, 0x153FB302, 0xE7D02261, 0xAD10BDE7 }, {
						0xFDA9E2B7, 0x447314BF, 0x3DB00000, 0x9726E530,
						0x39913C81, 0x31C5C676, 0x9C3C189F, 0x4E04F83D } } }, {
						{
								{ 0x0092C19A, 0x1C4C470D, 0x2AD8291B,
										0x0CBD7FE0, 0x5B6A5082, 0x0EFA189F,
										0x9C911C7C, 0x446253E8 }, { 0x66FCC9FD,
										0x268DF8AD, 0x62ED9182, 0x5667861A,
										0x83415746, 0x138E6E74, 0xF4215745,
										0x7076F0E9 } },
						{
								{ 0x1F34C367, 0x4D1C2CE7, 0x25259C28,
										0xF2FF1764, 0xEBF1A512, 0xB00F40EE,
										0x1E9BC82B, 0x9510A177 }, { 0x4B811538,
										0xC67D7BFB, 0x01D73962, 0xA5ED7ECF,
										0x67C6C693, 0x1D22D9C3, 0x2762D402,
										0xB1D0CD5A } } }, { { { 0x873CDEE1,
						0x531B0F78, 0x0BECF4B2, 0x4F9FBE1F, 0x46BE41B1,
						0x29FD5D98, 0x94F4FF75, 0x38F92749 }, { 0x18C75CE9,
						0x50951140, 0xC05566CE, 0x62A058B0, 0x1F8A0209,
						0x51E68003, 0xEF90C913, 0x54CDE438 } }, { { 0xBBFFB705,
						0x94710C49, 0x6B6EB461, 0x0FE7D1DA, 0x053D8C7C,
						0x7C76DB6C, 0x027374CC, 0x09C44992 }, { 0x615842C7,
						0x05C76636, 0x37E22A48, 0x48829D5D, 0x600752B3,
						0xD2770D31, 0x3F196365, 0x3B0FB8B0 } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 277 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 278 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 279 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 280 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 281 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 282 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 283 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 284 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 285 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 286 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 287 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 288 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x50DA33CF, 0x02F2A469, 0xEDC98F61,
				0xED919F74, 0x78AB0112, 0xC411D999, 0x5A85BD78, 0x07C4A65C }, {
				0x2DB2595C, 0xDDB30B92, 0x9817649B, 0x0CDDAFDA, 0x4E9357EA,
				0xE849D47F, 0xC6F66E61, 0x5FD5E307 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x6850FDCD, 0x1CDADD32, 0xE2014EBC,
				0xC80365A5, 0xD1341A5A, 0xCF2920B9, 0xCB4AEA0D, 0x19495A02 }, {
				0x1A95759A, 0x9F56987B, 0xC9A4951C, 0x5D850D3A, 0xA0EA5BA0,
				0xB4763AE3, 0x7E11E8CD, 0xB0C35E82 } }, { { 0x6EA5693E,
				0x5DEC452E, 0x42D395B7, 0xD647B2CA, 0xA27A7DBA, 0x46E67F15,
				0x1AD97A4D, 0x0695B91A }, { 0x9AA23BA4, 0x956D255A, 0xD0B04B61,
				0x4BEA8C1C, 0x73BD33C1, 0x5516DD42, 0x9CD89800, 0x16D77886 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xE7D22F84, 0xCE218999, 0x9510AAEE,
				0xCDB52AF5, 0x00503EC5, 0x3BF6ED4C, 0x0BFA9554, 0x278414C3 }, {
				0xBA481F9A, 0x2A27B4A8, 0x8641D073, 0xC95B1196, 0x774F0E05,
				0xDD30B99C, 0x93FD62F9, 0x3C2B3024 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xDDC9D309, 0xACF42DCC, 0x7A8B47D6,
				0xBBD5646F, 0x46A000B5, 0xE6BACD65, 0x11475BF0, 0x8436867E }, {
				0xBFE39665, 0x24990324, 0xEE7B3FBC, 0x57D11B73, 0xF0ED6D64,
				0x661D4A9A, 0x88BF3B26, 0x5404ABDB } }, { { 0xF06D1125,
				0x2371CABB, 0x31BA96AB, 0xA41F2405, 0x9EC64DA7, 0xE037023A,
				0x29D96A0B, 0x39D7D6E0 }, { 0x91E4A7E9, 0x11242502, 0x1251F593,
				0xE69DE904, 0x8944AD9F, 0x77DE0313, 0x2ED5C3F5, 0xA035992F } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x27487F89, 0xDAE7FDAE, 0xE3C1B96E, 0x3A0AE417,
						0x86689990, 0x4ECD06F0, 0x6F4DA96C, 0x65DB9432 }, {
						0x5B69D514, 0x3B5A60AB, 0x3A97306E, 0xDBA93B0D,
						0x0899A914, 0x6D3FDE9E, 0x32BC1F8B, 0x8E6AA2DF } }, { {
						0xAE497DBE, 0x03166C15, 0x5114C9BB, 0x5043D3A0,
						0x7C540CB2, 0x3BD3BE83, 0x449C069C, 0x32D4A13F }, {
						0x5D6E0554, 0xFAADD280, 0xC200B053, 0x194BC26A,
						0xE5AEF4C3, 0x576DD07E, 0x9734C920, 0x36D56797 } } }, {
						{
								{ 0x6788DDDF, 0xB7B12608, 0xB2D5CF06,
										0xCE470A49, 0xE6AD4B93, 0xAF1E34AE,
										0x8921A52D, 0x6FB0C125 }, { 0x596AEA5B,
										0x2163A1F9, 0xD501D058, 0x7A5B6FE4,
										0x4B99184D, 0x71765690, 0x0BF98E79,
										0x08A57E56 } },
						{
								{ 0x1BA780B0, 0xEB83448E, 0x6BEF0729,
										0xD8EC02C1, 0x1F7547DB, 0xA2626B3C,
										0xC1429FD6, 0x603D956D }, { 0x86BC526C,
										0x02AD146B, 0x748F4CB1, 0xEBF4EB85,
										0x73C09071, 0x70CAB526, 0x2F837F1D,
										0x125484E0 } } }, { { { 0x2212326F,
						0xB4CD8322, 0x2111CEB2, 0x8C686383, 0x7AEF2CBC,
						0x212FC2E4, 0xB29337E4, 0x640BE849 }, { 0xB51E072E,
						0x90B25F7F, 0x7BD8C93E, 0x1E5F4F57, 0x765C7D75,
						0x959B21B1, 0xD12E177D, 0xAF2A5190 } }, { { 0x1E266DB1,
						0xE5F80A7C, 0x9C82F670, 0x30FC9B9A, 0x68AB45D4,
						0xD0CF55BA, 0x5FAEADED, 0x1760F212 }, { 0x0478D797,
						0x0E0F08DE, 0xF275BB0C, 0xF5AEA41E, 0xCF0F0EA8,
						0x0E195EA7, 0x35A2AEE2, 0x81A12686 } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 289 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 290 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 291 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 292 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 293 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 294 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 295 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 296 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 297 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 298 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 299 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 300 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x0807CCBF, 0xDC99BF45, 0xA588815B,
				0x8E934466, 0x60C88DD3, 0x007FC8CD, 0xF11CCBBC, 0x2F66BF76 }, {
				0x9E55A5B2, 0x50136441, 0x464B181A, 0xEEC75C2C, 0xB4FB0EC7,
				0xECDEF8B0, 0xAB7564C7, 0xAFC6E8F2 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x37B75081, 0x1D9BE815, 0x34D1E3F7,
				0x4278D261, 0x15D109E9, 0x5398C5A1, 0x43688149, 0x2AD81CEC }, {
				0x342C5A95, 0x5F3C2710, 0x4D4613C0, 0xEDA6FFC4, 0x242AE7B1,
				0x811FC0A2, 0x134A9DE3, 0x5F4D13A3 } }, { { 0xC2D74632,
				0x93011AA8, 0x19D7CCD8, 0x091C70CA, 0x0E1BFC3A, 0x255868EE,
				0x0B28858D, 0x96303FEA }, { 0xA7EFE5BA, 0x2596BB34, 0xFEB0E651,
				0xCB7D6627, 0x16C6F05D, 0x8CC7EA30, 0x25AD6F1F, 0xB6FEB853 } },
				0 };
		static ecpoint_fp var_a2 = { { 0x90094C0D, 0xCFC80BA9, 0x7D330E05,
				0x1FD30B45, 0x9DC87329, 0x6A360F37, 0xD3EB887C, 0x1EE45910 }, {
				0x2B6A6292, 0xC2108203, 0x6DF7F6FF, 0xA65D5DAD, 0x3361ADE9,
				0x0BA34540, 0x33352DFD, 0xB242FEE1 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xAE2B5E5A, 0x9C499DDC, 0xF4CD81F2,
				0xED095A85, 0x28814C5A, 0xB880B32C, 0x42B6A709, 0x1AF5E41B }, {
				0x9BF4284B, 0xBBA3E2C6, 0xFA1DF1A2, 0xF5A2A1D2, 0xFBED2531,
				0x73EE94BC, 0xA17AB8DE, 0x1B689433 } }, { { 0xD7BA5E31,
				0x582E38A9, 0x9B9A52B7, 0xDF0B4070, 0xBB78A332, 0x9268F854,
				0x7E708BA7, 0x03D01511 }, { 0x8EE365F5, 0x0E7AE3DE, 0x7FC36F6E,
				0x28FBAA87, 0xBC16208D, 0x5E9B95CA, 0x2AEC858B, 0x2D2FD99B } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xE82FECEB, 0xCBBB02D2, 0xC1C04507, 0x2C442BB3,
						0xA0001F69, 0x06773447, 0x830293F7, 0x4448CD75 }, {
						0x3ECD4DD6, 0x26FC2DBF, 0x352C56CE, 0xE7283053,
						0xA5436939, 0x529BFCDC, 0xF2EA471C, 0x58AD37EB } }, { {
						0x91CA5A47, 0x11690B22, 0xEC0D223C, 0xF5D75B0B,
						0x0D321138, 0xA1E934E1, 0x8154F8D2, 0x36D3EDA3 }, {
						0x59EA6D63, 0x77A1B6C2, 0x1DE54B76, 0x8FE2F70F,
						0xDE599695, 0xFDD03181, 0x089AA2E6, 0x6C7879A2 } } }, {
						{
								{ 0xB7BE7222, 0xEE8B089A, 0xBDA03F8B,
										0xE6D4387F, 0xE6D87392, 0x497EEF6C,
										0x68BBE86B, 0x5921EA8C }, { 0x79FC8540,
										0xD2CD9968, 0xA04E1318, 0x94C7A494,
										0xCE9FEDF4, 0x854D1B1B, 0x0113883F,
										0x633B57B5 } },
						{
								{ 0xCF32075D, 0x3D67639E, 0x3344120C,
										0xD8C667CF, 0x56A19A59, 0xF652E0A2,
										0x54825231, 0x03C37D0B }, { 0x6850B7D1,
										0x5CCC354E, 0xCBE0FC74, 0x3915B0F3,
										0xCD44AF4F, 0x729BFDCE, 0xC4ED2D6E,
										0x73E416C7 } } }, { { { 0x589029A2,
						0xE347CA71, 0xF1707ED9, 0xD7C72789, 0x02694E15,
						0x23617A78, 0x03F22DD5, 0xAC5BCD96 }, { 0x20ECB399,
						0x6B30189F, 0xAF8A37BF, 0xB4218524, 0x633126A5,
						0x7CE73D90, 0x4B1D2674, 0x491198A2 } }, { { 0x0166B4D3,
						0x5248D1C3, 0xEE36313D, 0x531C63D7, 0x8906175F,
						0x0AD9EDB4, 0xC24ECF8E, 0x6182C4CB }, { 0x3EAB69C9,
						0xB339A179, 0x1823D023, 0x42FD074C, 0xD53A772A,
						0x07C6B928, 0x414E6BA2, 0x83AC507A } } } };
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_mul 301 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_mul 302 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_mul 303 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_mul 304 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_mul 305 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_mul 306 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_mul 307 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_mul 308 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_mul 309 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_mul 310 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_mul 311 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_mul 312 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0xB12F043C, 0xFDF76472, 0x6B3F1784,
				0xDF839B24, 0x677DE4C2, 0x78EA55AC, 0x8E694A42, 0x0EEC0CF4 }, {
				0x022C3C86, 0x28DDC3AA, 0x3933FBBB, 0x81697606, 0x558D2D93,
				0x485CDA50, 0x4E3745BC, 0x5262EF03 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x20F9654A, 0x7510635B, 0x2504F24C,
				0x024DEA50, 0x232230AF, 0x5CB83E87, 0xC7743978, 0x333B4651 }, {
				0xD7243C8B, 0x8A723EC0, 0xBEB618EF, 0xDD9C54F7, 0x88F35AC2,
				0xF7B25A98, 0x6FE3796C, 0x69977F3E } }, { { 0x39484D00,
				0x417F8191, 0x7B8B3AFF, 0x2A559122, 0x9836F703, 0xC4004FAE,
				0xF7D966D1, 0x98271BDC }, { 0x0E734372, 0x3EECA3C5, 0x7AB15C9D,
				0xFF43C37F, 0x9A845F48, 0x45C064D9, 0xA301B0D9, 0x77C7C386 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xCEDB3844, 0x7C65A3CF, 0x7588A074,
				0x335121D0, 0xFD579961, 0x37A7E2DB, 0x802A0383, 0x9F46C5F0 }, {
				0x2F0BC071, 0x6444A4F4, 0x02E85683, 0xD6BC1730, 0x25DFC365,
				0x753CE237, 0x39C8BD6C, 0x55576E52 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x13A6A199, 0x32B42C75, 0x69AEE970,
				0x567CEAD9, 0x53C7DBB2, 0x49D5F1E1, 0x66234A5A, 0x5017BB52 }, {
				0x9CC42356, 0xF078CB63, 0xC4C74D24, 0x33349A2F, 0xA7EDD376,
				0xD623C20A, 0xBB54B769, 0x1D0182CA } }, { { 0x453A09B1,
				0x84F507D6, 0x1BA2E63B, 0x3CC7843E, 0x546BA067, 0x05F87D16,
				0x14BE1144, 0x40D89555 }, { 0x2816B13E, 0x7C261F69, 0xFB1215D1,
				0x07E049DD, 0xF79F474D, 0x947FEC86, 0xE4EF3ABE, 0x15559846 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xC4153B8C, 0xC96EC33E, 0xB2ED2D70, 0xF8612459,
						0x469E9264, 0x4ABBAF91, 0xAF89FA23, 0x440B5148 }, {
						0x517073D4, 0xC553CD15, 0x8865CDEE, 0x2BA32A29,
						0x740A82BB, 0x63247ECC, 0xDCBAFFBE, 0x1B3257B5 } }, { {
						0x6DBEC022, 0x961C681C, 0xFA74273E, 0xD2C45CAA,
						0xD7904173, 0xA73EFE53, 0xC26F7064, 0x98DC99D9 }, {
						0x8B4A2C99, 0x30077C95, 0xCECCD3A3, 0x263A7C37,
						0xF1EEDB42, 0x4A9F02CC, 0xFB97B687, 0xB2ADA206 } } }, {
						{
								{ 0x9529A7C4, 0x988F05F0, 0xA76D8A18,
										0xBF4126C3, 0x5B8C009A, 0x0D82036D,
										0x9EC32656, 0x50C98764 }, { 0xAA07EE10,
										0xCC0A6810, 0x9D333B82, 0x228D3B6F,
										0x54D7828B, 0xED03D047, 0x7149B1E9,
										0x7B09B40B } },
						{
								{ 0x2406870C, 0xF819C2DF, 0xBB99DA69,
										0x2E1E455E, 0x14843AEF, 0x1FB6C6CD,
										0x75A13D83, 0x94D9D481 }, { 0x8DA341E4,
										0x213167D7, 0x68E99A4B, 0x568AE797,
										0xA0D668A2, 0x51BF2B7A, 0x0ABB4044,
										0x0FD15963 } } }, { { { 0x7B0D6C19,
						0x26683891, 0xAEEC3082, 0xB3959B26, 0xA008E8FE,
						0x55E96EF0, 0xEE3EF8F6, 0x387E5BDB }, { 0x21366A11,
						0x5D5D24E8, 0x91BBD0C4, 0xEE445E17, 0x0F45E63A,
						0xCA6075A8, 0x52C88382, 0x7F7EDB7B } }, { { 0x43461F6B,
						0x543C8523, 0xAF5BEDC3, 0xA4888047, 0xD9C46A2C,
						0x4F0085BE, 0x69370005, 0x3DFCBD3D }, { 0xFCF34B05,
						0x010402AB, 0x4AC6F6F6, 0xC661708F, 0x4068E987,
						0x7E930A21, 0x47E7B7CD, 0x0BB48C55 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 313 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 314 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 315 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 316 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 317 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 318 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 319 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 320 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 321 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 322 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 323 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 324 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x1CA974A4, 0x2548288B, 0x9CBE251A,
				0x6EAED96E, 0xEE786DFD, 0xFB5F2680, 0xEC96F7A9, 0x071F2CA0 }, {
				0xEFA965F8, 0x09C62EDF, 0x072A7551, 0x9777DB51, 0xB9C82599,
				0xB14C96FF, 0x360184DB, 0x1683411F }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x16F4510F, 0x41FDC84B, 0x5A0F3041,
				0xC52C705C, 0x59EB3C50, 0xA6D401F1, 0xB9A3D102, 0x7314F6D8 }, {
				0xA9382446, 0x6B4C1958, 0xB094E3B8, 0x0B12BFCE, 0xCB978EDC,
				0x67200E2B, 0x64954413, 0x5B393866 } }, { { 0x6756719F,
				0xE8A97EA9, 0x2480EB96, 0x6AAD6232, 0x2A6ED587, 0xED51712D,
				0x66397A8F, 0x1C7DE3C3 }, { 0x56D59716, 0x99A005AB, 0x6367DD79,
				0x35DD4571, 0xF0A379CC, 0x81E2C971, 0x3CC363FC, 0x571F9A13 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xE76B5DA1, 0x097E45FF, 0x2AB9AAA6,
				0x565BF50D, 0x8E8B639C, 0x16F6FA55, 0x468F101F, 0x4859DC74 }, {
				0x26E552DC, 0xB099C2B4, 0x8C1FEB66, 0x234C7E02, 0x46A9C77A,
				0xAEFA186D, 0xD5BEC25B, 0xA102F768 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x20BFE4A1, 0xE2A6138A, 0x1002AE18,
				0x3DD1C3D3, 0xD5D97BA4, 0x916646BB, 0x895DBF25, 0x68D98D85 }, {
				0xFFF31D76, 0xF5E3C947, 0x2A5A0468, 0xE56E80B8, 0x8EE945EB,
				0x204F6CBF, 0x1029A74E, 0x9C6B2734 } }, { { 0x8D56E5FC,
				0x5BAD52A2, 0x4E323D69, 0x11327E22, 0x7A30D246, 0x0DE3ED3A,
				0xDE99964E, 0x2F46471D }, { 0x55F02ABB, 0x3163E87E, 0x07A1F900,
				0xF6DA2729, 0x6CB02FA7, 0x0CE99051, 0xB9E85303, 0xADB70A99 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xB123BBCD, 0x2523A50F, 0x45D6B5A8, 0x2FA37757,
						0xDDBA95A4, 0xCFBB0FB8, 0xA003CEFF, 0x9A9CCBFB }, {
						0x5E9323D7, 0xAE60FE65, 0xB90F4227, 0x122548E8,
						0xDA19F071, 0x4589C8E4, 0x3BBEADB7, 0x7ADBC6C7 } }, { {
						0x95B4048B, 0x55C38C98, 0xBD9B64B7, 0x83A5D2BB,
						0x19125781, 0x931A1868, 0x53A5DA09, 0xA8E01C45 }, {
						0xB5B06B4B, 0xE647ED1D, 0x4C4B2E8F, 0xFCF8F32A,
						0xDD1C8818, 0x6E70CBA6, 0xE5C9A0DC, 0x193804BC } } }, {
						{
								{ 0xD728E947, 0x58DC389C, 0x8840BEB3,
										0x54FEBA2F, 0xCA60FDF2, 0x1B5E095C,
										0x780D7549, 0x7DCE32D4 }, { 0x1432D761,
										0x81DF24E9, 0xC49C46FD, 0x56CB65CA,
										0x9435F6A0, 0x37E4C501, 0x17CF4639,
										0xAF0F5E4B } },
						{
								{ 0x90D2B491, 0xA3B4D8CD, 0xB813FA48,
										0x287A5F9B, 0x9E19574E, 0xEAE72D05,
										0xCF767C53, 0x404BDD65 }, { 0xB4A26CA7,
										0x562F757F, 0x5AA548F8, 0xEDE9C205,
										0xE8CF21C1, 0xFC7A3354, 0x6D673FD9,
										0x9931B828 } } }, { { { 0x8E677AC2,
						0x83C7C8C6, 0x68D525BE, 0xCAE26505, 0x04C8EC0A,
						0xF5155E8E, 0x85238AEB, 0x446CE5C8 }, { 0xB35BAD62,
						0x5F14F819, 0x01D48C14, 0x494B9919, 0xE0B0FEA4,
						0xF4DBDE30, 0xE60173A6, 0xA435E0F3 } }, { { 0x41229D82,
						0x80149B58, 0x0E2530C4, 0xC52A18FC, 0x7E85BCB4,
						0xF242A74D, 0x68B3CE66, 0x7B676BF1 }, { 0x45D4874F,
						0xC71D7DF4, 0x8DCF522E, 0x900AB4C7, 0xABDB9676,
						0x14EDCC69, 0x7D5C7B79, 0x3B4F27F4 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 325 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 326 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 327 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 328 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 329 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 330 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 331 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 332 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 333 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 334 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 335 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 336 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0xFCA3E4CE, 0x037F31FF, 0x5CC2FF8E,
				0x7B5216B5, 0x14D74820, 0x990EB61F, 0x6F89B00B, 0x5B7363CB }, {
				0x51FA0E1E, 0xD43D63FE, 0x742068A3, 0xDD9968D4, 0x66B8D4E9,
				0x033C8FFA, 0x17B4AFB2, 0x69C04705 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0xDE24310F, 0xBCD7A14D, 0x3E5DFDAC,
				0x7D85D014, 0xAA6BF336, 0xB7375DF4, 0xA73782EB, 0x2202A16F }, {
				0xFB287E09, 0xEB305CBA, 0x4C1BE120, 0xD36A0762, 0x0276EB2E,
				0xFD8582B1, 0x33051FAF, 0x226BE154 } }, { { 0xC75BD7E5,
				0x84306F31, 0x33263792, 0xD55CF91D, 0xF784E5D5, 0xBAD4561E,
				0x52B3E7F6, 0x00499992 }, { 0xA9F51FFE, 0x0103979D, 0x2617F5AE,
				0x25B5E004, 0xA504717A, 0xD47B6061, 0x534B0D75, 0x47E3009B } },
				0 };
		static ecpoint_fp var_a2 = { { 0x1793A590, 0xC8C6CA5B, 0x7C1454F0,
				0x49EABD3A, 0x1ECF2C3C, 0x7D249C4E, 0x52131E2A, 0xB4AC26E2 }, {
				0x5DA8FDE9, 0xF0631278, 0x96780680, 0x222C5D57, 0x70D51D31,
				0xACE463E4, 0x2BE681D4, 0x6820FF3F }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xD7D749A4, 0x721F500F, 0xAA978AB3,
				0x071781A7, 0x059CA646, 0xAF3C46DD, 0x5A0C6E5E, 0x8E341A07 }, {
				0xC6CBE774, 0x3AF8CB51, 0xE657E494, 0x0C0E6339, 0x530A7A29,
				0x98B24BCA, 0x70074806, 0x94D282C8 } }, { { 0x2C6543F2,
				0xCC5A079E, 0x8770CF81, 0x25712189, 0x877C539A, 0x6C6B4977,
				0x9ACB93C7, 0x4611A271 }, { 0xB54880AA, 0x8A73879B, 0xD48C4378,
				0x06CAB2E1, 0x977F2452, 0xAF2C35CD, 0x8474CF53, 0xACC0F90E } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xB02A0B3D, 0x4763AC18, 0x43DED8CE, 0xFD5C44AE,
						0x84734E98, 0x56100B12, 0x5D81F230, 0xA57F72F6 }, {
						0x1C1F36FC, 0x24708901, 0x78C836A4, 0x4DAB5A52,
						0xCBEC1F86, 0x495B7BAF, 0xE0B2E992, 0x4AA4EE23 } }, { {
						0x703EFB51, 0x2C368353, 0x453F6366, 0x8AB934EB,
						0x54551C2B, 0xBD356DEB, 0x5E7D5B3C, 0x65D8142B }, {
						0xDF8D4F58, 0xCC91C28C, 0xD359563C, 0x1EDD4D91,
						0xCABE5813, 0xD8C2C0E0, 0xEEF13B56, 0x90A1A7A1 } } }, {
						{
								{ 0x238A29CC, 0x85B54EFE, 0x162C1B90,
										0xDEA6E465, 0xF4EA8BA0, 0x9EF6529C,
										0xA16BF7B6, 0x2150914C }, { 0xC6B31B1E,
										0x2F16F7F9, 0xF5240AA8, 0x32E10EE0,
										0xCEBD0326, 0x21215198, 0xAFC37E2C,
										0x0633B4EB } },
						{
								{ 0xA259B79A, 0xCA5890B0, 0x6198F1A6,
										0x9B0F3A9F, 0x3756D852, 0xC986D4EE,
										0xFF5C52ED, 0x69CE07C1 }, { 0x34028099,
										0x85A80290, 0x09907C6F, 0xDF8166D7,
										0x223AF1D1, 0xAC312159, 0x1338E6E5,
										0x9C4D18F8 } } }, { { { 0xCB841B54,
						0x0B7AAFA2, 0x109B18DC, 0xC988C839, 0x89547847,
						0x5E90D6EE, 0xFC761AF5, 0x9B609DB1 }, { 0xB59614A0,
						0x2F358759, 0x4FD8DF30, 0xE7548926, 0x35FD93AF,
						0x6D4E923F, 0xB2D86459, 0x1F980443 } }, { { 0x238E60ED,
						0x3F601160, 0x7ED648E6, 0xB061DBB4, 0x3D9198A3,
						0x6088CC30, 0x311EB284, 0x5C155714 }, { 0x69EEA5F5,
						0xB67DF569, 0x57150CC2, 0x9000CCB6, 0xCFCEF598,
						0xD62A7BB2, 0xA3A088DB, 0x0359EC24 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 337 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 338 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 339 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 340 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 341 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 342 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 343 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 344 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 345 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 346 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 347 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 348 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x53D9CC0E, 0xA2BEE908, 0xECEE817A,
				0x86053964, 0xC7C1C560, 0xC12FA1A6, 0x58302438, 0x0ED1441F }, {
				0xDFA3CB80, 0x16F7B5C9, 0x46F76F78, 0xEE7FAC37, 0x3E3EFCC5,
				0x97166195, 0x5BAB27C7, 0xADAD9C13 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x532029A6, 0x0CEC486F, 0x75FBE027,
				0x2BD5672B, 0xD68259B1, 0x005EF3A9, 0x2957207A, 0x2A730B8A }, {
				0xC078379A, 0xD400EE92, 0x3A7E3A06, 0x73812B96, 0x4D0BF622,
				0x6D9DF743, 0xA3AF0A01, 0x1F62A2A9 } }, { { 0xFBA7D1F2,
				0x2AFB1306, 0x5C6E5B69, 0xFD0F1EA3, 0x088B845B, 0x561F4495,
				0x9A4E47E8, 0x99B9CD30 }, { 0x8690D707, 0x69F0A34C, 0x72D50295,
				0xC7E4BD35, 0xF405C195, 0x46DFA0F1, 0x66421C33, 0xB3ACC6DD } },
				0 };
		static ecpoint_fp var_a2 = { { 0x153CF797, 0x625F5A2F, 0xCC3C4778,
				0xE5816450, 0x68551791, 0x5B13D34F, 0x26C9E832, 0x85A97DEB }, {
				0xDE0C582F, 0xEA27A772, 0x23D6062B, 0x17A30CA8, 0x79AEC04C,
				0x6C536C6F, 0xA304C826, 0x5ED1F6BD }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xB3C61350, 0x1ABCA207, 0xAA34B96D,
				0xF3B67CC2, 0x1BFC7944, 0xFB043CA9, 0xA1BD7836, 0x3D63BFD1 }, {
				0x090BF4D0, 0x6898983D, 0x8263F9C0, 0xF4B86D93, 0x7D5B8ECA,
				0xA9A7A7A2, 0x8A63015D, 0x16C5B35B } }, { { 0xDDB84BBE,
				0x91FB4E37, 0x8678E671, 0xFF17E3C9, 0x7C63F301, 0x2C8AF80A,
				0x18516FBF, 0x5250CB61 }, { 0x786945A0, 0xA02C4574, 0xEB2DBD2F,
				0x445AF58A, 0x02F54468, 0x2CB97A8F, 0x6C49DEF6, 0x42A13226 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x54CAC3B6, 0x8F68E776, 0x05DDCEE9, 0xD9387650,
						0xFE400C16, 0xDBAB48D5, 0x7D552F57, 0x3D3D1C93 }, {
						0x1455824D, 0xBC499FA6, 0xBE3F4CC7, 0x92AC4CA1,
						0x2BCAA273, 0xD0045006, 0xD155C370, 0x621F2535 } }, { {
						0x3D5F6FCC, 0x40C3A926, 0x8E3EB1F6, 0xDC3A1A0E,
						0x73E0973B, 0x27A9C773, 0x8057744B, 0x7B87FEDF }, {
						0x69C43048, 0x6FEF7C52, 0x8A710D73, 0x8A205EC5,
						0xFFA8BD1E, 0x531A23B7, 0x83FF9753, 0x5DCB46BE } } }, {
						{
								{ 0x7AACA3D7, 0x4B5E3E34, 0xF5B8FC24,
										0x5A8CA1C2, 0xE72CA7C5, 0xAD575E91,
										0x073318AC, 0x340648F3 }, { 0x0E1937F3,
										0x42B1EF99, 0xFDC91CD6, 0xB156ACC0,
										0x1CD7BF01, 0x6466B08A, 0xA4EF1D52,
										0x0384C69A } },
						{
								{ 0x969E5C68, 0x9D42B8CD, 0x3765AEB2,
										0x34B72757, 0xF1231010, 0x4B1C2D06,
										0x15E2B180, 0x64C5AABD }, { 0x772F80F6,
										0x5A2FEB07, 0xB2347016, 0xA2F9E05C,
										0xCF1EACE4, 0x86D72891, 0xBBFC2828,
										0xB459154A } } }, { { { 0xBDBABAB8,
						0x5BD186B2, 0xA3FDAE0C, 0x4A1F63DB, 0xDB472E51,
						0xA076E7C7, 0x7D4F2EC7, 0x7800C36B }, { 0xBA264611,
						0xF52B5043, 0x5FAD28AD, 0xD6E78299, 0x7A8A0915,
						0xBC1B9EEC, 0xCB18524E, 0x0FBB81A9 } }, { { 0x9CA74C34,
						0x75E0F0C4, 0x27772D1A, 0x36A5A458, 0xA77A0DCC,
						0xC3279AE9, 0x7D73E57B, 0x80937402 }, { 0xDD3EF402,
						0x64AA64D2, 0xDDF06DDE, 0x4FAAA6D2, 0x025300F9,
						0xB04C3CBC, 0xCF6E382D, 0x3895814D } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 349 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 350 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 351 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 352 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 353 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 354 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 355 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 356 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 357 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 358 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 359 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 360 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x6A039E2A, 0x5CFE0EA3, 0x8DA52D11,
				0x7361605E, 0x86BE0150, 0x5C181565, 0x0820F246, 0x892E9FF8 }, {
				0x988777CF, 0x96B13B86, 0x2D652FFF, 0x17BD00EC, 0x73586BA1,
				0x0698D13E, 0xA83CEFB0, 0x1F0EC58B }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x2D154B4B, 0x2FAEBB50, 0xC0CF45DA,
				0x69002806, 0x99280953, 0x272452FB, 0x602BE8AA, 0x402DAB53 }, {
				0xF1B7736F, 0x0D95BAF2, 0x7E18C023, 0x88DC43D6, 0xA3A5BC1B,
				0xE0E0A520, 0x0EB5E061, 0x09871ABA } }, { { 0x8CF9B425,
				0xD47D6BBD, 0xD2FC2BB1, 0x96F2510F, 0xFBD7AFDE, 0xB955F933,
				0x0A3CD379, 0xA79B3E66 }, { 0xEC708832, 0x330C0082, 0x74DC945F,
				0xB597C369, 0xA9E76579, 0xC30ED813, 0xD562385E, 0x780BC121 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xDE51F00F, 0x0E55E1BA, 0x24344491,
				0x411E0C9B, 0x8944EEC4, 0x63FED4E2, 0xFD716216, 0x36CAD51C }, {
				0x05518C80, 0xBE2BAEF7, 0xB6CCBF4E, 0x6852BB42, 0x0DECB660,
				0x4EBDE2B4, 0x17944A90, 0x49C5E6EE }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xF02BA675, 0xFE30617B, 0xFFCA8925,
				0x4F08751F, 0x4F2DFFF1, 0x974C4C88, 0x50B3207E, 0x5CAD7B14 }, {
				0xA180CFE4, 0x60066F83, 0xD8565E06, 0x545EF2CA, 0x44368020,
				0xD05BA0C6, 0x2D8A19E8, 0x44C429CD } }, { { 0xC5DB2FD7,
				0x666D88C2, 0xCD455C88, 0x1D757829, 0x872D118F, 0x075E4928,
				0x866E99FE, 0x2A26A7BF }, { 0xE05FEE7F, 0xD4DBD085, 0x5F41FA17,
				0x75DFDDC4, 0x5BA23F51, 0xD735DC61, 0x21C9F0BD, 0x0F3964E6 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x81E302F2, 0x483637A9, 0x116484B0, 0x2E0BA220,
						0xD21CDC24, 0x40744EF0, 0x0643E57E, 0x2E9B2285 }, {
						0x67AB4C7A, 0x87D61D45, 0x29D6B5B0, 0x14D64ED8,
						0x9BCA00B7, 0x069B850C, 0x8F47F23D, 0x65044E91 } }, { {
						0xC717A160, 0x96273B00, 0xEC2FB649, 0xA933B115,
						0x79110573, 0x3D7CA806, 0x018F9272, 0x4338049D }, {
						0xA46CEB13, 0x7885EA14, 0x054876C5, 0xC84B8955,
						0x4AF37B84, 0xF350209E, 0x69254129, 0x1D5C52DA } } }, {
						{
								{ 0x1D672CDB, 0x772E648A, 0xF01913EA,
										0x12284DD2, 0x40853E04, 0x48EB4116,
										0xA2694D01, 0x53F8AF15 }, { 0x5600B2E6,
										0x4957D41E, 0x42EBD704, 0xE5C2D813,
										0x85A705AA, 0x64911612, 0x1AA10302,
										0x18443E42 } },
						{
								{ 0xBBA07CDE, 0x4CB1EA7C, 0xA258517C,
										0x16FD1A00, 0xAA0D994F, 0xCE016DA1,
										0xEFCD0289, 0x96DAF7B8 }, { 0x921CCFC0,
										0xAC2D3F6C, 0xF1D208FC, 0xB8A88D8E,
										0xCCD1BB11, 0xF2DC40A5, 0x98998B3E,
										0x8AF8D31A } } }, { { { 0xB17727E1,
						0xC62DBC90, 0x4238BBB4, 0x2411F54F, 0xB3AD8A97,
						0x840B269A, 0x7DBC4EA5, 0x21DFE589 }, { 0x01D48B19,
						0x895C8EE3, 0x1C831827, 0x12A5FF27, 0x2FCD7423,
						0x5AD20592, 0x86BCAA9F, 0xB258D457 } }, { { 0x9EB5D9B6,
						0xF34131D4, 0x1288E8E4, 0xB7A004B4, 0x7BD046CD,
						0x583F3893, 0x3445D773, 0x39D8190A }, { 0x2E73D7FC,
						0x6C02D6CC, 0x129B58B8, 0x8C3F1114, 0x0D2CCC21,
						0x892F878B, 0xDE5BC384, 0x2BB6A5D6 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 361 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 362 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 363 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 364 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 365 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 366 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 367 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 368 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 369 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 370 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 371 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 372 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x24DE0AE5, 0x642CA77C, 0xFB4A079F,
				0x79393DC6, 0xE79DB551, 0x24DDAE70, 0x0949528B, 0x36F1962C }, {
				0x221D9657, 0xE8973D29, 0xF3932B3B, 0x33803EF1, 0xE0FC71F9,
				0x7AC9D971, 0x568C77AD, 0x6548D4DE }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x6D5333A1, 0x3864DC8A, 0xE12947BB,
				0x87D35784, 0xB38F035F, 0x155BE8B0, 0x71A02A21, 0x023C6492 }, {
				0x99D61206, 0x3DBB3DD6, 0xCFC712CA, 0x87B1A30F, 0x4D928A92,
				0x0076B2D9, 0xBD59FCB9, 0x25CAE803 } }, { { 0x572528AD,
				0x248ABCAA, 0x719CC7BC, 0x8722ADF4, 0xFF0D0125, 0x2E727F33,
				0x7DFCF86F, 0x4A801FC2 }, { 0x602DFBAC, 0x4BDEF6A8, 0x02CD8E29,
				0x9A0918B2, 0x5E566F2A, 0xEBF76BB1, 0x2FE88BA0, 0xA8C5ECB0 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xB0BF7169, 0x3A0845E0, 0xD2C7CCC6,
				0xACC04502, 0xB534A31A, 0xF0FE265C, 0x1EF08636, 0x278A0809 }, {
				0x532F960E, 0x05059514, 0x34F82CA9, 0x7774423D, 0x3A5CD758,
				0xD1ADBE7F, 0xB934869B, 0x7696C2DD }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x68F65608, 0xD7529E31, 0xBBA8254C,
				0xC723BA89, 0xD4580536, 0x185E02DA, 0xCB51AD30, 0x6A897A40 }, {
				0x9E8DA6D5, 0x86627782, 0x346E07E6, 0x386CCE35, 0x54C97811,
				0x506A922B, 0x688EA827, 0x86E704FC } }, { { 0xE26B9EF8,
				0x8263B041, 0x6EEECCDE, 0x47B44634, 0xAB7326C9, 0x67D97F2A,
				0xB6869B2F, 0x08FD1DD3 }, { 0x51161F22, 0x46B98CAF, 0x7D914480,
				0xEE4B2D5E, 0x93FA8520, 0x2F38329F, 0xB4448B29, 0x30FF4F0C } },
				0 };
		static fp12_t var_expected = {
				{ { { 0xC888F40C, 0x93509F7E, 0x86D737A8, 0x9BF82200,
						0xB6934FCF, 0x90FBD6A2, 0x39636C21, 0x1EE0B2A9 }, {
						0x29199214, 0x0208450D, 0x7F3AC07E, 0x96191356,
						0x379036BA, 0x49C20C3E, 0x84746254, 0x0A45375D } }, { {
						0xD158C057, 0x267A01C3, 0xF7170D63, 0xE9A4C5BB,
						0xC2E90D80, 0xE0F1A828, 0xE1E4DE18, 0x4CC51E55 }, {
						0x362BE258, 0x3BCAD4ED, 0xC5996530, 0x85646613,
						0x7FF47DDA, 0x8C9AAD40, 0xF5F0591F, 0xB1231255 } } }, {
						{
								{ 0x43E018BA, 0x6C6BF758, 0x5B3BA528,
										0x766306E0, 0x63D2E63F, 0xB8AC4ADF,
										0x8A711150, 0x903DE86C }, { 0x3329EC35,
										0xE13A3ED8, 0x2F34EBC0, 0xD66BAD93,
										0x0FB42210, 0x8EF33839, 0xE193AA2F,
										0x0019ABE2 } },
						{
								{ 0xFA689751, 0xDFA5A339, 0xDD0AFB30,
										0xC171DF80, 0x658D26E8, 0xD083FE6C,
										0x4A1BA87E, 0x977C6E05 }, { 0xE3FB46D6,
										0xBE28A767, 0xC1F3FFCD, 0x4A3632F4,
										0x61EE6747, 0xD81CBF64, 0x0ECF1034,
										0x285860A3 } } }, { { { 0xF83CE6A2,
						0x17BEEDBB, 0xB874DAA6, 0x63B0677C, 0x8A470AAA,
						0xB00DD619, 0x730A7231, 0x75265AD6 }, { 0x11D53963,
						0x8812D5ED, 0x9DDF1901, 0x17FD218C, 0x2687E735,
						0x7DFA102E, 0x700F7580, 0xB8116289 } }, { { 0xEE0B7C1A,
						0xB7AD3534, 0x84BEC510, 0xAB5D3494, 0x43A6E85A,
						0xFE08FA8D, 0x23352EA3, 0x6C6B0882 }, { 0x78FB68C1,
						0x362CEAD5, 0x5B5D2F86, 0xA599D435, 0x2D28E1FC,
						0x17A3131C, 0xD201B479, 0x0AE0A1F5 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 373 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 374 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 375 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 376 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 377 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 378 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 379 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 380 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 381 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 382 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 383 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 384 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x5AB0AFF3, 0xC72E4BD8, 0x6EDA5AF1,
				0x1E6CE19F, 0x5ED47497, 0xB9219365, 0x6DE04F8E, 0x9439DBE9 }, {
				0x32CEF75A, 0x55AF5567, 0x272A4960, 0x9C740D8F, 0x178CC9BC,
				0x3F397A7B, 0xFD49CEDD, 0x9F563035 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0xD3A24D96, 0x65C38B34, 0x88776DB7,
				0xCFF4DBD1, 0xF0701F37, 0xAE84C7F7, 0x02241AD3, 0x0ABC9AC3 }, {
				0xCE9B2CFD, 0x8165E29B, 0xA152A467, 0xE661DB70, 0xBA29A03B,
				0x86BF7374, 0xCFAF0D6B, 0x62E09A85 } }, { { 0x0A0E550A,
				0x386B440D, 0x91BFE5F1, 0x3756090C, 0xFEABE08C, 0x569051F6,
				0xA65F7CDE, 0x6765C0B8 }, { 0xDC04CEC2, 0x35F756DB, 0x2B9B21E8,
				0xA73DCAFA, 0xD15E983F, 0x3804FA54, 0xE50ED44B, 0x2979E913 } },
				0 };
		static ecpoint_fp var_a2 = { { 0x587FA493, 0x1D90ADFF, 0x935EEF45,
				0x8AE26452, 0x630EE27B, 0xDDC5A9BE, 0x5517659D, 0x74B09116 }, {
				0xB026D093, 0xB3E0436C, 0xF13B324D, 0xCFCFEE9B, 0xF3A2AD08,
				0x408A6E26, 0x9CCBE274, 0x1B15F7A4 }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0x2997EC2A, 0xD2D2C87F, 0xDF4CC138,
				0x7FDF5A58, 0xF6DDBFE7, 0x05130B80, 0x1E4CFBA8, 0xAEFABFC4 }, {
				0x9A0F8E96, 0xD87BE74A, 0x755CC55C, 0x44C28FC5, 0x205EBEDD,
				0xFD9300F1, 0xD092DC3C, 0x9284075A } }, { { 0x6BEBFDCA,
				0x484ACFCB, 0x32EEABAE, 0x01E62456, 0x23CB85C1, 0x81FDBB3B,
				0x7B177619, 0x63F271CB }, { 0x27704D17, 0x37343116, 0x1CD24E0F,
				0xE6D7657F, 0x239547BF, 0xD22BC562, 0x26D1FF14, 0x325A827B } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x191AAE67, 0xA788C5A6, 0x26B364C0, 0xC56773D0,
						0xC6C5F904, 0xDD2CDF2C, 0x408F6AC5, 0xAC062FA4 }, {
						0x222B831D, 0x0341D387, 0xAE95A955, 0x8ADACEB7,
						0xA903AA33, 0x38246DDE, 0x3EDB1081, 0x10C41545 } }, { {
						0x582937F1, 0x222DEABE, 0x2961D68C, 0x0C7D46C3,
						0xE628CE5B, 0x17609F38, 0x1556C0B9, 0x31C12499 }, {
						0x16B02500, 0xFCBE474F, 0x3F8AAF29, 0xA0BBACD8,
						0x278EACD9, 0x3E43ADFA, 0x1FAE5A00, 0x3DA69D8E } } }, {
						{
								{ 0x9782D16C, 0x231E8C9F, 0x7D8E62C9,
										0xB6BB6E82, 0xB68ECA4F, 0x1594A620,
										0xDD4B0581, 0x3B8209AC }, { 0x29AC8FD7,
										0xA0BBACE8, 0x11654FE6, 0x28D918AE,
										0xF813DCFE, 0x951E935D, 0x4A2F8D4B,
										0x6D79B58D } },
						{
								{ 0x5182EBFF, 0xF0CDCCA2, 0xEEECD195,
										0x6651BC06, 0x805693EC, 0x82BB964D,
										0x07C46EC5, 0xB548B00C }, { 0xBCFFF6BD,
										0x4125B0D0, 0x88847DDD, 0xC9D84EB9,
										0xB97B6089, 0xC60A9D9A, 0x6FE7D87F,
										0x3D0741CC } } }, { { { 0xC1931781,
						0xF9912EA4, 0xEFCB40F9, 0x67122B92, 0x5230882D,
						0x374C160C, 0x38708201, 0x4ED72271 }, { 0x80C226F7,
						0xF702ABFE, 0x281AA0DD, 0x899CAFBA, 0x4771F62E,
						0x32BCC097, 0x311B94EE, 0xB52FC050 } }, { { 0x9ED081D8,
						0xCF22B314, 0x90E3DED1, 0x0338D81A, 0x73602C4C,
						0x6563D0FA, 0xCE1EC445, 0x305C718F }, { 0xA1C9B4A3,
						0xF4C5D4E6, 0xF30024E9, 0x2032B3E7, 0x4565A909,
						0x98A37201, 0xAB551E48, 0x672AF2E4 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 385 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 386 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 387 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 388 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 389 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 390 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 391 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 392 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 393 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 394 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 395 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 396 a211");
	}
	{
		static ecpoint_fp var_a1 = { { 0x4583A43B, 0xD13D2FA6, 0x7D335811,
				0x2ABDB267, 0x8782EE4A, 0x92703C26, 0x14BEB628, 0x9A7767C7 }, {
				0xEBC372B3, 0x34D65710, 0x5B00F2B2, 0x266D9998, 0x432A61F1,
				0x7BE6C0DB, 0x53693214, 0x6D2183B1 }, 0 };
		static ecpoint_fp2 var_b1 = { { { 0x9C4E30F6, 0xBF832B5B, 0xBEC2760C,
				0xA86991F2, 0x0C2F3211, 0x17563627, 0x0DED3C8B, 0x9C48B962 }, {
				0x4CD45C2B, 0x44F64FD8, 0x004173F3, 0xDD0D675D, 0xD4C55AB6,
				0xCC0459DE, 0x9A92F7F4, 0x2F865757 } }, { { 0x59C7FE75,
				0x4E07DD3D, 0x8D0AB05E, 0x018F16C8, 0x99132435, 0xB10C8850,
				0x14F8EFEF, 0x9967656F }, { 0x2E604B54, 0xD1F3C867, 0x8C4D6BF6,
				0x81F16884, 0x62FB5CF6, 0x5127A1A5, 0xA9CBAC06, 0x88441BC7 } },
				0 };
		static ecpoint_fp var_a2 = { { 0xBA26F864, 0xCAB2595C, 0x3DDCBF05,
				0xDDCE9466, 0x60A03336, 0x6543903D, 0xA88457C4, 0xA4C3DCDC }, {
				0x23C15EFB, 0x1A273451, 0x4A6259C4, 0xB9A60CB0, 0x93391D78,
				0x2AE1BF99, 0xD8E6ABC2, 0x88069D7D }, 0 };
		static ecpoint_fp2 var_b2 = { { { 0xF3331910, 0xEB350279, 0x75BF2220,
				0x9081FF28, 0xFE50C3AA, 0xED72BDAC, 0x10469058, 0x6D975C98 }, {
				0xFD4C8C0C, 0x5B7CE499, 0xDFFF80CB, 0x32E46A6B, 0x467C4DB1,
				0x079E117B, 0x6F8862BF, 0x12EA2E07 } }, { { 0xE6C32C00,
				0x6B64EA92, 0xA9732530, 0x3720C4F3, 0x7EA30E3B, 0xF51865F2,
				0x4FF90813, 0x98433DB2 }, { 0x773C5D37, 0x0AAAB34C, 0xCF1D6B4C,
				0x14AA433D, 0xBE3938F7, 0x6360AC03, 0xFBE4654D, 0xB7E40274 } },
				0 };
		static fp12_t var_expected = {
				{ { { 0x3DA0DA4C, 0x96FEB09D, 0xD55C0DFE, 0xFA46BBF8,
						0xF81D2537, 0x27836EC7, 0x791085B9, 0x10DB8E9B }, {
						0x19797601, 0x15F72F34, 0x026785C0, 0x41E0B94D,
						0xC94C2FAF, 0x41104B0D, 0x3AD1603F, 0x71088D5E } }, { {
						0xDF2270A7, 0x177AD93D, 0x6260B060, 0x5E82596E,
						0xCE4FAD3C, 0xF590BAD8, 0xC5958ECC, 0x0E4CC1BE }, {
						0xC30685A4, 0xAC9D07B8, 0x26A0E704, 0x8685D9E2,
						0x169E36F1, 0x50BAF19D, 0xEEBBC9ED, 0x1E8DCF1C } } }, {
						{
								{ 0x9FDCA15B, 0x2E4902E2, 0x95613C48,
										0xEE1E6CD6, 0x86A041D0, 0xB53C4B38,
										0x0B33A869, 0x9BE2C35F }, { 0xA74DC478,
										0x81A34B91, 0x38DF03F4, 0x2F367C95,
										0x70E1DC0E, 0x16F0CEDE, 0x1055C7BE,
										0x2E9BAB82 } },
						{
								{ 0x7C462815, 0xC73A4B6A, 0xEFAFF5F8,
										0xF46F3805, 0xD35F3510, 0x49B13A6C,
										0x71546247, 0xB77D3B31 }, { 0xF22B2A7F,
										0x70BDC06F, 0x29D23827, 0x3F529CB1,
										0x69C5D2D2, 0x6593F3DD, 0xC1FC9C8D,
										0x616124C3 } } }, { { { 0xF061C9D8,
						0x7C7429C0, 0x4ECDF8A9, 0xAD7CAB27, 0x8C8212FD,
						0xB0DCEA22, 0xA356C75A, 0x358E4AE8 }, { 0xC97B6563,
						0x579B5642, 0x1FFE2B71, 0x80928D32, 0x34926A93,
						0x90F45B48, 0xF275C4D6, 0x4F9406AA } }, { { 0xBE9A7557,
						0x9EE062B8, 0x22F6DFB5, 0xF531942F, 0xB2D9FF64,
						0xCA7E5986, 0xBA4C8E98, 0x78EB3EAB }, { 0x056F906B,
						0x72A106A6, 0x70D62DE5, 0x15BDC891, 0x8CC3D27B,
						0xAF252DF4, 0xF0BA95EB, 0x78CD76C5 } } } };
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0],
				"pbc_map_opt_ate_div 397 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1],
				"pbc_map_opt_ate_div 398 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0],
				"pbc_map_opt_ate_div 399 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1],
				"pbc_map_opt_ate_div 400 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0],
				"pbc_map_opt_ate_div 401 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1],
				"pbc_map_opt_ate_div 402 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0],
				"pbc_map_opt_ate_div 403 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1],
				"pbc_map_opt_ate_div 404 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0],
				"pbc_map_opt_ate_div 405 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1],
				"pbc_map_opt_ate_div 406 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0],
				"pbc_map_opt_ate_div 407 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1],
				"pbc_map_opt_ate_div 408 a211");
	}
#endif
#elif (BNCURVE == BN254)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static const ecpoint_fp2 var_b = { { {0x63659E66, 0xAF45AAAF, 0x3D01BC7C, 0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
	{0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382, 0x6630C4E9, 0x10C76BD0} } ,
	 { {0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7, 0x9215E25E, 0x1C2D120D, 0x182C7A58},
	{0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0, 0x781D1A20, 0x1598CFFE} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xBDA4E05F, 0x0D784EF4, 0x64BAB152, 0x4F2CDCB9, 0x00198E3A, 0xE64006BD, 0x2329C635, 0x041A8741},
	{0xD3B7AFCF, 0xF38E4CBF, 0x266FB9CB, 0x383794C0, 0x8BA33041, 0xD8A56F94, 0xD3629146, 0x0FAC8CE6} } ,
	 { {0x935E782C, 0x7789284A, 0x85C6F658, 0x8E89FF36, 0x8A4AB9C3, 0x778D8B5E, 0xFC4A300F, 0x234654C8},
	{0xB8888E05, 0xFADDDE4E, 0xDDCB18FB, 0xA8FCAFE8, 0x9E7AC2ED, 0x73E17AC4, 0x30B1C274, 0x1B3EB5ED} }  } ,
	 {  { {0x501A9532, 0x9D29C866, 0x715AAAD0, 0x150E9133, 0xF498D834, 0x3716382A, 0x2F4DEB2B, 0x126532DE},
	{0x37110A0C, 0xF7615A5B, 0xD171432A, 0x65DC774D, 0xFCB063A1, 0x816BC003, 0x077FE744, 0x1245C66C} } ,
	 { {0x053C9447, 0x99D3AA6F, 0x4672BCA6, 0x3AD616A8, 0x91398302, 0x033EC3B6, 0x385EEF4D, 0x0BCDBAD4},
	{0x01D96991, 0x7C87468F, 0xF78945FB, 0x1EE9E50C, 0x95B4589C, 0xA23383D7, 0x93E998A5, 0x0F250343} }  } ,
	 {  { {0xA1E617B5, 0xBE6ACA36, 0x97EB951C, 0xFA882493, 0x1FA92778, 0x769BA367, 0xF127FD3A, 0x14CEAAB8},
	{0x382DD884, 0x28289C27, 0x3802131D, 0xB59B202B, 0xFD5AB98B, 0x2F88F88C, 0xC794B525, 0x1D68A188} } ,
	 { {0x8A6D06A1, 0xCEDB332C, 0xB336E8EC, 0x0E239A1F, 0x765A5284, 0x5DF01A42, 0x0461990D, 0x08724A28},
	{0x080B618A, 0x2DD389C7, 0x977F5185, 0x8237F6DD, 0x6445E8CB, 0x4D3CE7B5, 0xF0B5E80A, 0x0E0D1082} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 539 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 540 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 541 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 542 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 543 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 544 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 545 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 546 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 547 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 548 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 549 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 550 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F},
	{0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2},
	0};
		static const ecpoint_fp2 var_b = { { {0x960F14FF, 0x8AA6ABD6, 0x87EFEFE5, 0x16F4A65A, 0xC857B2F0, 0x7A9E7DF1, 0x03B186C6, 0x12562644},
	{0x8EB899FA, 0x7D9A9BDC, 0x782B19CD, 0x55956D8D, 0x19D2FE11, 0xE6B96044, 0x79D9BDEF, 0x0601323C} } ,
	 { {0xDA674DEE, 0x187C276E, 0xF35872B7, 0xC043B8D9, 0x67A35C1F, 0x5EFAC0F8, 0x3CAFCF7B, 0x084A96C2},
	{0xBE7030AA, 0x71453EE4, 0x04EF2AA9, 0xDBB33875, 0x990571EB, 0x9DCC4511, 0x74A0A3B6, 0x108174C7} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xC164110F, 0x7762B348, 0x9066F748, 0x0BCB5A54, 0xBE85C156, 0xA910EA68, 0x49F1A36F, 0x22A44AA3},
	{0xA2656039, 0xB4FF7765, 0x09C98770, 0x86EA34ED, 0x6C5C8FF2, 0x254E6632, 0x1545EA06, 0x17F271E5} } ,
	 { {0x3315A104, 0x67C89D65, 0xFAE75C2C, 0xCDAC4C48, 0x261FC39E, 0xA17019DD, 0x77027559, 0x0B90B544},
	{0x14280651, 0xBAA22B71, 0x4AD5E40E, 0xB83BED44, 0x36D63A2E, 0xF225D8A3, 0x4DF3A43A, 0x03A1B486} }  } ,
	 {  { {0xE70806D4, 0x332BD58A, 0xE571B165, 0x76163796, 0x9DF65B14, 0x480269B2, 0xC17845D3, 0x1BF24AB1},
	{0x37FA0FE2, 0xE7D20B3A, 0x6D374034, 0x94E45C51, 0x65B66252, 0x6A5B53B0, 0xF24CDE2F, 0x1AFC8D5F} } ,
	 { {0x664C4B95, 0x88457DD7, 0xB6A8BFC7, 0x1D78892E, 0x9135C63C, 0xC303274F, 0x0BEA1E76, 0x0C49954B},
	{0xF25393E4, 0xE5266CD1, 0x21001675, 0x87F8CD0D, 0xC661CC83, 0x12C7CE57, 0x1EB35E44, 0x1D0E915D} }  } ,
	 {  { {0xC6BEEA70, 0xC20808FE, 0xC7C2929D, 0xC495214B, 0x0A180564, 0x41495189, 0x4FD6BF8F, 0x022C839B},
	{0xBDEC5DF1, 0x61767953, 0x879460AB, 0x3F623AB7, 0xD6A6BA68, 0x1DE5249D, 0x479B5F50, 0x1973A8E4} } ,
	 { {0xF34E4E1F, 0xC095D900, 0x9D159BAF, 0xAB294306, 0xBF83F113, 0xF5A05A7F, 0x54D3314E, 0x222CB39C},
	{0x338A3499, 0x685FD288, 0x383C2229, 0x34B2E96A, 0xEFA7A106, 0x61442880, 0x532D0333, 0x09332A0D} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 551 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 552 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 553 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 554 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 555 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 556 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 557 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 558 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 559 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 560 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 561 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 562 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x741E8FB9, 0x4F209240, 0x37C381C4, 0xB0BBAE37, 0xA490987B, 0xB8D5900B, 0xDBE04253, 0x23DE4FF4},
	{0x18EF46B2, 0x161CF81D, 0x3149DE29, 0xD33A70FB, 0x3FBF4C73, 0xB4CCE669, 0xDEE9773E, 0x1CBE038E},
	0};
		static const ecpoint_fp2 var_b = { { {0xF09F75C8, 0xD6F44E22, 0x24C250D2, 0x2721DEEE, 0x52069434, 0x489CCC9A, 0xB4A80550, 0x0733957C},
	{0x1B99786D, 0x23B3E516, 0x885D46DB, 0x3B7F3208, 0x2E8E98FD, 0x194425A5, 0x6D3B0E97, 0x05E53D9C} } ,
	 { {0xAEB63C93, 0x200FD9D5, 0xF911E8BE, 0x58F4CB78, 0x47C7366A, 0x8086AA92, 0x4C9EB2AB, 0x1801B0A6},
	{0xF823133B, 0xD6E6DF83, 0x18301F6D, 0xEBB3A7B3, 0x456D4586, 0xD0E3D15A, 0x32A2FEB2, 0x01CA28FE} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x0F9A9C84, 0xB1CD3256, 0x4644ADAD, 0x03D3631C, 0xF02AD1EF, 0xB986A6F1, 0x7255BE54, 0x1C9649B7},
	{0xC05C3A13, 0x931643F8, 0x0AF9D093, 0x6A798C29, 0x9A4A28AA, 0xA94A0288, 0xEDA8F98C, 0x071BDC97} } ,
	 { {0x29EA96F4, 0x89115FBA, 0x7C3AC0AF, 0x9131BC8E, 0x25C8AB15, 0xB594E658, 0x527F356E, 0x1CE5CFD2},
	{0xB1349055, 0x5D772076, 0x3F81D193, 0x16A4F7BC, 0xB7B1156C, 0xF9E0081A, 0x35E74C07, 0x0047D210} }  } ,
	 {  { {0x4441ECF5, 0x26277097, 0x4610B684, 0x32A2708F, 0x7AC50356, 0xFAAD5D9B, 0x6139EA8B, 0x2109F34D},
	{0xC8F2CBA8, 0x95B800CA, 0x8561EEB8, 0xE71BE078, 0x2D00C686, 0xA626CA5E, 0x614482F6, 0x12CAB574} } ,
	 { {0x4523292E, 0x91AF4048, 0xB8E81409, 0x12A04289, 0xE3A5C0E2, 0x8A89C55D, 0x5C41BD66, 0x08B2A841},
	{0x1BAC0C2F, 0x96EA3E45, 0x5FF3639B, 0x2F302055, 0x322D71DD, 0xBE43DFD1, 0x2C69F5CF, 0x1CBE9F99} }  } ,
	 {  { {0x8826D6DF, 0x53726637, 0xADBCB50C, 0x2F4D7944, 0x09A13F19, 0xBA7547C2, 0xA1ECDE8D, 0x025ABA3F},
	{0x901D1AB0, 0x288745D0, 0xDF31F998, 0xBF871D91, 0x8C825997, 0x170B36DC, 0x8526F009, 0x1F6A4CDE} } ,
	 { {0x14E3DB0E, 0x24590204, 0x7D44C79B, 0x1ACB4A1C, 0xC75A5C1F, 0x8EBE098F, 0x47DCDCD8, 0x120C3161},
	{0x6AECBB5E, 0x3DDF1048, 0x22DEE7BE, 0x96B8D121, 0x5FF7B13C, 0x283DCD6B, 0x3041BDF7, 0x096DF02B} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 563 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 564 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 565 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 566 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 567 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 568 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 569 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 570 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 571 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 572 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 573 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 574 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x887F4278, 0x281F8B82, 0x0C51DBA4, 0x7BBE876C, 0x6769C1CB, 0x6687E803, 0x71C5D0DC, 0x055D57F0},
	{0x633BE608, 0xE1BC9205, 0x29FC0B03, 0x7D001143, 0xA8152406, 0x255209D1, 0x1B542FE6, 0x14290B4A},
	0};
		static const ecpoint_fp2 var_b = { { {0xF73371AD, 0x2C799A2E, 0x50EB0F76, 0xCD5C386A, 0x7DAACF18, 0xA8824390, 0xBB25AAF7, 0x1155DFCD},
	{0xA4D7F294, 0x458BA96D, 0xB8C91E0C, 0x73C1F9C7, 0xA74A61D3, 0xF43EBF67, 0xF277C0C2, 0x062D16E6} } ,
	 { {0xCF5BC83F, 0x04329D71, 0x1D3D0882, 0xBC1C6CE9, 0x083CE10A, 0x3477B3CA, 0xC3162D0D, 0x02B2CCD8},
	{0x994CC3AE, 0xBC7CA00A, 0xF7ACA6F2, 0x0D4D406D, 0x2F83233F, 0x608F276B, 0xCBBAEA36, 0x18B665F0} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x61B0EBCF, 0x54EA485E, 0xB5270497, 0x2C1C452E, 0xD978479D, 0xA4FC3295, 0xA5B8B2A9, 0x18423611},
	{0x2F6F08E0, 0x1DC656E1, 0xAC384D26, 0xA1B2157A, 0xB4F84CD3, 0x76D1F59F, 0x03FCBD4C, 0x1689183F} } ,
	 { {0xA52122BB, 0x96E61B37, 0x4E21B144, 0xF82C9084, 0x0F8B7022, 0xA5FBC62D, 0x932BE512, 0x216ED553},
	{0x1D118460, 0x77D72A5A, 0xB31E0042, 0x8A697528, 0xBF91F990, 0xD407B996, 0xCF38C36D, 0x07A8C510} }  } ,
	 {  { {0x1AC2D357, 0x465041EB, 0x89EFBE1B, 0x0F727CC4, 0x9DA798E3, 0x25166E1B, 0x0A3A06EA, 0x2249D856},
	{0x095DA8CE, 0x1E16C984, 0x69239E33, 0xFF643632, 0x5E83B148, 0xE24F8E63, 0xF79B8CC4, 0x0FBFA046} } ,
	 { {0xE574A833, 0x04BD0938, 0xCB4D641D, 0x00E21FF2, 0xB31DF63C, 0xB7C6DD0C, 0x605C2F12, 0x15AE18E5},
	{0xE3F75E8A, 0xA5D20257, 0x45D62E9D, 0x78213484, 0xE5C030E8, 0x44CE2FF7, 0xA98F0ED6, 0x0D64CB7E} }  } ,
	 {  { {0x2EB9D61B, 0x8B2D2FAA, 0x3F29C452, 0x5B7E58B6, 0x36A97B23, 0x08D4572F, 0xEEEE0AA0, 0x08BFA27F},
	{0xC988025F, 0xDF56B524, 0xE3955B1C, 0x9AF00183, 0xFB5CD4FC, 0xCC14C93F, 0xF0EF29CC, 0x05CA7CC3} } ,
	 { {0x68EB6D27, 0x38D77033, 0xED0A07F6, 0x0EF94CAC, 0xCE1AA3DC, 0xA75B8D11, 0xC650E4CF, 0x11CB3D71},
	{0x322DDD2D, 0x3AC78D32, 0x38FE7EA4, 0x9B345DF9, 0xF30F9686, 0x27EE4961, 0x4CE42C69, 0x06CA44D7} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 575 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 576 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 577 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 578 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 579 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 580 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 581 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 582 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 583 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 584 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 585 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 586 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x4D0A0226, 0x7D7F55B2, 0x4730F738, 0x45514DA4, 0x1AA28DAD, 0xB49E91E7, 0xDE78E279, 0x1E102DBF},
	{0x677618FD, 0xB5517C7F, 0x92C96C47, 0xFF94AB7A, 0x9C246097, 0x449F104C, 0x4CA8038E, 0x07585C42},
	0};
		static const ecpoint_fp2 var_b = { { {0x601CDFC3, 0x2FE47958, 0xF6A16ED0, 0x6EC66A65, 0x048B564D, 0x8D92A4DF, 0xDD53D1AC, 0x1BAA7BB0},
	{0xB9DA3376, 0x81AF5B4A, 0xA260B408, 0x7E3F6339, 0xF4982494, 0xC10F0E0F, 0x68223711, 0x1762BEA1} } ,
	 { {0x91BF481E, 0xFD30F0D3, 0x88B87F4E, 0x3E5169D9, 0xC27753B3, 0xA5CFF6C6, 0xD80EBB62, 0x10DD14C6},
	{0xDCADEBEB, 0x9A7FC3B2, 0x95D3F301, 0xA37CD4D3, 0x260FCF03, 0x2C6EF00C, 0x2B495709, 0x0F2455C1} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xBE136B21, 0xF9260DE9, 0x2F0F92BF, 0xDB95C992, 0xB2A871B5, 0x2EB4A88D, 0xD67AE290, 0x08FA626D},
	{0xAB890108, 0x182D7254, 0xE510A41D, 0xB402DB84, 0x2F48A96D, 0xEDB46D3B, 0x28F97D76, 0x1E59EDE1} } ,
	 { {0x05543F8F, 0x08E02275, 0xDEE814D3, 0x93858842, 0x6B44CA80, 0xB92100CF, 0x91F40839, 0x073D5EBF},
	{0x6A284AC3, 0x46624AFB, 0x1B43368C, 0xE1BA5759, 0xAB6D404B, 0xF1EA834C, 0x672D9B83, 0x0831EEAB} }  } ,
	 {  { {0xE61743A6, 0x8ABFE6C6, 0x313A3F82, 0xCD97FE47, 0x2E306DE9, 0xDC04365E, 0xEFA1DEE9, 0x046280D4},
	{0xC23AFBDE, 0x1E1BA5C1, 0x0AC0B112, 0xB081FFD6, 0x119C76BF, 0x249AD626, 0xB097F093, 0x045C30F7} } ,
	 { {0x785D14FC, 0xF8D1E0D7, 0xAD46F646, 0xCC4C9276, 0x9798FB91, 0x941A1AC5, 0xFD33497B, 0x0A8225E2},
	{0x2192690F, 0xAEA5B66E, 0xB3E3B09C, 0xB32C8992, 0x93578134, 0x4DA0407E, 0x34EBE0B1, 0x1C9851FE} }  } ,
	 {  { {0x3E87DF0B, 0xD0B48179, 0xEAA131EC, 0x3401F5D6, 0xBE05E139, 0xF346EF16, 0xAD5FB0DB, 0x14EB8F5E},
	{0xE9E051C0, 0xAFA58E6B, 0x56532DA4, 0xA5C9ECD8, 0x2BEBBCD3, 0x0997064F, 0x31F9A117, 0x0C457CA9} } ,
	 { {0xA5091C84, 0x2FFD7E3D, 0xB25FE186, 0xC4A51A16, 0xB0CE30DD, 0x3A1CBF3A, 0x723C40DF, 0x0B17CCCF},
	{0x4EA66972, 0xB5E75AE4, 0xAAED626C, 0xD461FE44, 0x41184E61, 0xA97F2AC6, 0xDE3865D5, 0x0E652DBD} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 587 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 588 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 589 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 590 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 591 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 592 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 593 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 594 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 595 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 596 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 597 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 598 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x5059E714, 0x92ABC336, 0xB349D546, 0xA7968C69, 0x7D461CC4, 0xA0362B37, 0x5366A90F, 0x118137FB},
	{0x26FF6C64, 0xF3888646, 0xD8F54162, 0x32705995, 0x60B47225, 0x3498ACFF, 0xCC780E48, 0x0825AF9E},
	0};
		static const ecpoint_fp2 var_b = { { {0x1FB8763D, 0x5F7FA876, 0xDE0727A6, 0xF7B72FE4, 0x903937C3, 0xEC0BF8EE, 0x0ADE6E71, 0x1D4BEBB7},
	{0x2372A97E, 0x28B2674D, 0x09B0CFED, 0x5F8FCDB9, 0xB3E46E4D, 0x8B3DCF9E, 0x87A63C6B, 0x1AF7FB97} } ,
	 { {0xB352D0E0, 0x691949C3, 0x60C55D4E, 0x737BD42C, 0x7CE78D09, 0x09C2A100, 0xBCC63039, 0x0729FC67},
	{0xA2FE595D, 0x7AD833EB, 0x139CCC9D, 0xDDBDFC7C, 0xC57908E9, 0xC3DC0A8E, 0xEAF9BDD6, 0x2376561C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xE8806160, 0xAD6F79D4, 0xC219372E, 0x1AE95982, 0x807DF4F1, 0x3E5585C1, 0x553C0582, 0x24693711},
	{0x290F0F9D, 0x4E47E481, 0x7E7759B9, 0x879BFD62, 0x8438BC53, 0x1904478F, 0xCE2C980B, 0x164B3A3B} } ,
	 { {0x07D95B47, 0x814C334C, 0x3B42C450, 0x111E13FC, 0x402A82CB, 0xB4058DCC, 0x293910DD, 0x10B66C22},
	{0x23516FF2, 0xD97A8C0E, 0xE780BA36, 0xE76C4899, 0x35DD37CA, 0x9F82A78F, 0xDABFC0D4, 0x1BAF7911} }  } ,
	 {  { {0xE08A7427, 0xE6B8E796, 0x618400A8, 0x67D7FD4F, 0x69B3CBBB, 0x0E04B675, 0x2C4A3B9D, 0x004033B0},
	{0x9CC65B11, 0x7C5871C9, 0x723E79FC, 0x901AEA0F, 0xE37AC091, 0xE3CD60D7, 0xD8467D17, 0x0299EF6E} } ,
	 { {0xB94629C8, 0xC4DC60E2, 0x2D1CA297, 0x6DEFEB65, 0xEDC3B751, 0x68A5F900, 0x9200D87C, 0x0E19329D},
	{0x85F13653, 0xC65915AE, 0xE7B097A7, 0x9F9384A8, 0x9FCBADA4, 0x1D798153, 0x9246ABE4, 0x0480886F} }  } ,
	 {  { {0xF1D0CE40, 0x7C3BFC29, 0xD130FF4D, 0x24BCA882, 0x3772E5FF, 0x5D59F752, 0xDCD25039, 0x1F4A2DE8},
	{0xA9F45AEF, 0x681FCD07, 0x56B944BE, 0x4341F13D, 0xAE0CC78F, 0x6C2ACCEA, 0x70B92695, 0x04150AFA} } ,
	 { {0x603A0CCE, 0x3782D274, 0xE744D6D5, 0xFCA169C7, 0x83414198, 0xEAF5214D, 0xE0FC58CB, 0x164D21EE},
	{0x9D2CD792, 0x10F5A325, 0x0F4F4BD1, 0xE41DB175, 0xB8B0A07D, 0xE99D3DE5, 0xCFF013A9, 0x19232D7A} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 599 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 600 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 601 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 602 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 603 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 604 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 605 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 606 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 607 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 608 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 609 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 610 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x708755BF, 0x8282D14C, 0xFD33F08D, 0xA692D639, 0x8C5C1E42, 0xB490CB54, 0x91613D8E, 0x0FA086E9},
	{0x509D404F, 0xA9512C69, 0x0DB4E232, 0xB442CCF0, 0x4EAD8915, 0x3B0CCDE3, 0x0C3229C1, 0x1ACE7E44},
	0};
		static const ecpoint_fp2 var_b = { { {0xAB11CCA6, 0x9405FB64, 0x429F121A, 0x7D89BF54, 0x99842E84, 0xB637B209, 0x026EA3CA, 0x0DB4F613},
	{0xD060E16D, 0x046E62DA, 0x680D607B, 0xAAE6C13B, 0xDBE30139, 0x4B277792, 0x9EEA6BF8, 0x1E872AD6} } ,
	 { {0x1F0DDB46, 0x779C3225, 0xD15729E5, 0xCB73D01B, 0x8EA29508, 0x3679477E, 0x7AD07307, 0x096D9D80},
	{0xC6D8CAC0, 0xE121F9C9, 0x277A97D5, 0x79800B22, 0xEF59F7E6, 0x19F4ADF6, 0xF0A6DAB2, 0x19340559} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x0996F515, 0x4CDC3FD9, 0x3E4A8814, 0x3FB9A576, 0x720402C8, 0xC1049095, 0x877447DE, 0x147AF058},
	{0x5027FD6B, 0x40037821, 0x551F8CA3, 0x1278A066, 0xBB819D7B, 0xFF80C22A, 0xC9467190, 0x1684BE4F} } ,
	 { {0x770EB8C7, 0xBA5F0CB0, 0xA697D6D7, 0xA54BD6CC, 0x75597AF4, 0x655429AD, 0xB74AF9F1, 0x039357B7},
	{0x6B6D6FD3, 0xE7431014, 0xB46C8F77, 0x68007479, 0x89B6B157, 0xB53527D7, 0x434853E9, 0x0D26B13F} }  } ,
	 {  { {0xD6A9D327, 0xD12F803A, 0xA565FFEB, 0x5D33E723, 0xA25F9A14, 0x082542DA, 0xD316B182, 0x1B772EF5},
	{0x0D5AA36C, 0xC5602673, 0x5FA3E792, 0x62E87BB7, 0x07FB7313, 0xD3C912FE, 0xCBEC8558, 0x112558E5} } ,
	 { {0xEA7C40CB, 0x4F52A0C5, 0x8B7BA410, 0x44D844C9, 0xBFA87C7F, 0xA4531C8C, 0x9FD41FC3, 0x0C10F3D1},
	{0xA4C31368, 0x70D09A89, 0xC9749734, 0x67BC3770, 0xC61EC442, 0x3A3CEB48, 0x02B8EB5A, 0x22D45FFD} }  } ,
	 {  { {0xD70CF705, 0x066EF0C5, 0x0D3F277C, 0x7CA410BC, 0xD39932B3, 0xADA6A3C9, 0x8B9031E3, 0x0486C38D},
	{0xAAC96FD5, 0x2B857F5B, 0x07FCFA3C, 0xB7C5A43A, 0x1305A29F, 0x682418B4, 0x01C07C6F, 0x1A667D2E} } ,
	 { {0x584C11F1, 0x716B59DC, 0x9438672C, 0x1602478D, 0x264F198B, 0x4CB71C06, 0x051A0DE0, 0x05816951},
	{0xC92BA1CD, 0xC2CEECC8, 0x9B428D3B, 0x923B7796, 0x9F621A70, 0x5EF094ED, 0xFAA88B06, 0x1472246C} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 611 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 612 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 613 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 614 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 615 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 616 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 617 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 618 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 619 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 620 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 621 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 622 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x444776DE, 0x64866D26, 0xC88E5ECB, 0x826BAF4A, 0xF53476B7, 0x7915F1C6, 0x0D603285, 0x0B8886A4},
	{0x10C927C8, 0x761EB374, 0x8FAAC272, 0x9FD64D1D, 0x2A428FAF, 0xB1F33E60, 0xC2BAE411, 0x04B433E7},
	0};
		static const ecpoint_fp2 var_b = { { {0x8F94C082, 0x39281516, 0x6F555F07, 0xB2168D83, 0x19E0B68C, 0xDECCCC30, 0xBC9C7C5F, 0x1DAC9A51},
	{0xF5966FC9, 0xFF16AD77, 0x64EA5F62, 0x4C9D1C10, 0x584FF603, 0x4028D3AE, 0xE4D46CF5, 0x037296FD} } ,
	 { {0xEE3D9C96, 0x8853E808, 0x39A1A1F9, 0x64EA8370, 0xC74CF700, 0x49F45EDE, 0x27ED8B1C, 0x0DCBC108},
	{0xA596E5A5, 0x520897BD, 0x221C1C1D, 0x055BE9AD, 0xB4F1829E, 0x1B52F1DB, 0xCA13DEEE, 0x1FAA49F3} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xFFD77EFB, 0xCCA9F145, 0xEFD64B78, 0xDE78D156, 0xB86C04B5, 0xAED0EC89, 0x8DC0AA4A, 0x22C6D09B},
	{0xA07A75CC, 0x1AB1A1BE, 0x1C99C453, 0x5E271C3D, 0x03B10404, 0x0A56DC7B, 0xD194BF1E, 0x120E6506} } ,
	 { {0x3ECFCEE6, 0x6F111A22, 0xD1EFE634, 0x92088A68, 0x1A042A6D, 0xF74399EC, 0x39D2BA13, 0x03098593},
	{0x8F5487EC, 0xFB1AC58F, 0xCA422CAB, 0x466001FF, 0xC03AD621, 0x7FDBF3BC, 0xFAB73972, 0x0DA9FA56} }  } ,
	 {  { {0x9BB68342, 0xAD0C6627, 0xD66A76E8, 0xF7C60CEA, 0x80DE02DA, 0xE920E9CD, 0x2CBD6B12, 0x1324CD5A},
	{0x4E53275B, 0x59CACF6D, 0xB1487691, 0xCB1FEEBD, 0x0CD22A10, 0x4423DF84, 0x6A0129B8, 0x17EA1D9F} } ,
	 { {0x8FF6A2C2, 0xBCD97692, 0x48861455, 0x065E2472, 0x6CB7F59A, 0x6CA09AEC, 0x9178EF23, 0x185A95DD},
	{0x344491BD, 0x530FE1B4, 0x15AA6DB9, 0x05C13420, 0x89424810, 0xF7A9DD09, 0x53A75901, 0x09C4338F} }  } ,
	 {  { {0xAE488511, 0x5C65673F, 0xCDA426F8, 0xF910F54F, 0x45231A9D, 0xBD9B8B1A, 0x13E61868, 0x1DE26103},
	{0x16CBAAA5, 0x01DE6987, 0x87D80E65, 0x542F3E76, 0x0836AFD9, 0x20CA5179, 0x40CE5AA8, 0x1036B4E8} } ,
	 { {0x76E3F900, 0xCE438F90, 0xD4F9AAE9, 0x559BAD72, 0xF22DB3DF, 0xE91DC1C4, 0x3E09ACC0, 0x03087693},
	{0x52F1C5AE, 0x65C00DAC, 0x85C74541, 0x08F567A0, 0xF60FE5EC, 0xEE0CD13F, 0x2DABBBFD, 0x0F65AF40} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 623 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 624 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 625 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 626 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 627 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 628 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 629 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 630 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 631 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 632 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 633 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 634 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x087C43D2, 0x42095223, 0xEF028B6E, 0x78E94B42, 0x198E22F4, 0x798855AE, 0x7D867B30, 0x1D7EC8D0},
	{0xD3653DAF, 0xD524ABDA, 0x3D463C8B, 0x9B20DDAB, 0xEFC3C499, 0x6A3095AC, 0x6CE91B61, 0x0B79ECFD},
	0};
		static const ecpoint_fp2 var_b = { { {0x6CFC2618, 0xDE46008D, 0xE69BAC90, 0xFD070279, 0x33425F31, 0x92A95456, 0xB3415CC0, 0x21F849FB},
	{0xEC52AF57, 0xE8897089, 0x2D179F26, 0x715162E6, 0x15F8830B, 0x9900928C, 0x82330EB0, 0x053AA523} } ,
	 { {0x3E3FD236, 0x93A498A3, 0x865F8BAE, 0xCC6D0ECC, 0x8A8E2E9C, 0x8F34C869, 0x4027889D, 0x11099987},
	{0x566C3C20, 0x18822D58, 0xB7005C2A, 0x74400420, 0x6C80B52E, 0x12D1B967, 0xC7A66DBF, 0x01F8135A} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x5CCF525A, 0x9E67D4C6, 0x52C9E842, 0xF881F383, 0xC7E397BC, 0xB7CDA446, 0x1B0CB702, 0x12F7539A},
	{0x84247FBA, 0x7EF920D4, 0x69672998, 0xF437A98F, 0x1FF096F9, 0x39FEF57B, 0xAE811833, 0x1C61DC70} } ,
	 { {0xC2876380, 0x342D20B0, 0x0A1E8D89, 0x50283853, 0xEFAF1E1D, 0xF034047F, 0x20CC06DC, 0x13479198},
	{0x3D67E0B8, 0x8FE4E08B, 0x7B80E19F, 0xE6D3022A, 0x7812A0C3, 0xA1BC13D8, 0x9081B903, 0x1E27891A} }  } ,
	 {  { {0x8C8ECC40, 0xD6191A63, 0x1D1D6C9C, 0xC65D28D6, 0x42E3BD58, 0xF437E26A, 0x35C645CF, 0x13CD6269},
	{0xB5F2B1DB, 0x745F9650, 0x649A7150, 0x8CCB16A6, 0x6EFAEB13, 0xFFDA3141, 0x5D5E7EAD, 0x1EEBA133} } ,
	 { {0x60131BC5, 0x918AB07A, 0x35766C02, 0x903D57B8, 0x61C26827, 0x0AB68A37, 0x88086C6F, 0x0B65096C},
	{0x3D9443DA, 0x7C70200A, 0x4B38EE88, 0x07BFE22D, 0x5154D8F4, 0xA50FBC11, 0xD4895C7A, 0x06E5E579} }  } ,
	 {  { {0xB75C378F, 0xE1816DDA, 0xE4FA10AD, 0xC05A219C, 0xD94AD15C, 0x34379C24, 0x51D3F3EF, 0x24C2E86A},
	{0x86D63ABA, 0xFD3BA4F6, 0x393008F7, 0x5DCB83C3, 0x24553A4A, 0x53FDF0C7, 0xEBF76B56, 0x0BFCCE87} } ,
	 { {0x8741C0BC, 0x9A6A65C5, 0xF710B8C6, 0x089CFFB1, 0x0F97ADB6, 0x07ED8250, 0xC6AB3B9A, 0x1EAC653E},
	{0x5A926803, 0x3A4B8144, 0xBA7D38C5, 0x0AB8E667, 0xE1B694C2, 0x189325D1, 0x3DDB6D25, 0x1E779A9B} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 635 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 636 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 637 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 638 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 639 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 640 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 641 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 642 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 643 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 644 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 645 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 646 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x7E872CE3, 0x74C1AD6B, 0x6544A59D, 0xB2769C08, 0x06B15C19, 0xD4FC5409, 0xC534FE59, 0x06803C42},
	{0x29638CCE, 0x4BE898CE, 0xE1817E9D, 0x7F3634A9, 0x1594F4B2, 0xC3292993, 0x323750C4, 0x1DA09C7C},
	0};
		static const ecpoint_fp2 var_b = { { {0x53BFDA5E, 0x35E50609, 0x1E72CFDA, 0x5A531D24, 0x605D3ED6, 0xB532D2DD, 0xD70B0F52, 0x167F240C},
	{0xCCD781C1, 0x9026E5CA, 0x002C006A, 0xE41FBF1C, 0xCB1D369A, 0xBFE833F0, 0x5F4D4F68, 0x24145946} } ,
	 { {0x1466F50B, 0x66A8B30E, 0xBEFE8E75, 0x4D1246F6, 0x08F2E31B, 0x39CAADA0, 0xB1C43F97, 0x0FF87C99},
	{0xC36E8721, 0x06D3BD1E, 0x78599B64, 0x95795CD8, 0xBB5A5FA5, 0xAAFA9D99, 0xBB58A4B3, 0x108CC1F5} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB37C44C0, 0x9F8065A3, 0x293194DC, 0x8C9FB0E0, 0x1ECD5E71, 0xF57756CF, 0x000EE48F, 0x02C6451F},
	{0x3A59F740, 0x123C46B4, 0xBE2B4B0C, 0x9DD45E60, 0x95512262, 0x12C2589C, 0xAF60A396, 0x0C98FB13} } ,
	 { {0x27995C78, 0x66635E52, 0x55FAEE31, 0x259985E2, 0x522D3943, 0x94ED11E2, 0x37862F71, 0x23FA5FE3},
	{0x3DD6F1DD, 0xEB0E3955, 0xAE2F41CC, 0x2792F250, 0x4D39B2BE, 0xE17A134C, 0x29EBC262, 0x01D94D90} }  } ,
	 {  { {0x9E9564F0, 0xCA18EAB7, 0x011A4CCE, 0x9FC0DE15, 0x6817BF6A, 0xCC29C958, 0x93B5C19A, 0x112761D3},
	{0xFF4618DD, 0x7EB809AB, 0xC4747080, 0x52CB6081, 0xEDEDB616, 0x045DFA0F, 0x17FF53A2, 0x007AB9F9} } ,
	 { {0x0E7719BF, 0x408AA40A, 0xC4109CEB, 0xD338DEA3, 0xE2B91CCC, 0x3C9D73DA, 0xA6ACA306, 0x2110D056},
	{0xEAEA4B26, 0xCA25AD1B, 0x7AE5AA22, 0x9708ABDC, 0x7A6A0DAB, 0x3A78C314, 0x2E052BDB, 0x08C508FB} }  } ,
	 {  { {0x255990A1, 0x3E79A0F0, 0xA48D64BF, 0x7F5A572C, 0xB9F63DB4, 0xBB5AD224, 0xD23684FC, 0x10180F4C},
	{0xD36AA2C4, 0x695E1EB0, 0x643C1EA8, 0x3822DE17, 0x210CAC55, 0x2B1C98E7, 0x3AA6D11D, 0x0A86283C} } ,
	 { {0x9570C5D6, 0x25F3D99C, 0x2083A9DA, 0x7D428A78, 0x60415FAC, 0xF8F98514, 0x53F3B299, 0x138EBAD5},
	{0x6953EAAC, 0x6C46A715, 0x8A8186D3, 0x9E74086C, 0x72731617, 0x8B8C924F, 0x843AB870, 0x1F92F68F} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 647 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 648 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 649 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 650 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 651 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 652 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 653 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 654 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 655 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 656 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 657 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 658 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x6E022F35, 0xCD734B22, 0x262F286A, 0xBD63B540, 0xC1BDBF65, 0x41983D30, 0xB90C7350, 0x192F1056},
	{0x4E91FC33, 0x88E5A6D6, 0x901CD8CC, 0xF937E9C2, 0xF7A230B4, 0xCB01BAE7, 0x1AA3FA77, 0x00554BC9},
	0};
		static const ecpoint_fp2 var_b = { { {0xB96E6004, 0x29D9EF00, 0x41697786, 0xCD5C273F, 0x6D0A6680, 0x8C76CEE5, 0xE88E67C1, 0x08CE050A},
	{0xEC8285F3, 0x42B6A79F, 0xEBA70009, 0xF16D86AD, 0x5A5922E9, 0xE25331A8, 0xED90400D, 0x1252C880} } ,
	 { {0x7C0B5942, 0xAE030737, 0xE2B94573, 0xB22A47B8, 0x46185F39, 0xD49D595D, 0xE10E059F, 0x01421FFC},
	{0x002B7502, 0x715DD42D, 0x5152BDEE, 0x69A08802, 0x7E358697, 0xC19ED550, 0x3C3066A6, 0x03AA252B} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xCB78DDDE, 0x0B4DA1B7, 0x396839F7, 0xA28975F1, 0xEF2FF70D, 0xCF3291F7, 0xB69B4E0F, 0x0A8803B8},
	{0x1A690438, 0x7197FF8E, 0xB28DFA97, 0xA879EB40, 0xE4D7281E, 0x99B42183, 0x6EC5B3C4, 0x146AD734} } ,
	 { {0x0D4D66F4, 0x87056698, 0x49730850, 0x491DC95A, 0xA76E201E, 0xA5D3ECDD, 0xB99F4D8D, 0x1DD919F9},
	{0x3AD9CC4D, 0xA2166A15, 0x87E6C69C, 0xEFCB57AA, 0x3555D95B, 0x6AA37071, 0x78E32AD9, 0x03FEEB73} }  } ,
	 {  { {0x8FA81ECF, 0x6811AD74, 0x2A8CF54B, 0x7976125D, 0x7432CE19, 0x6B96ECFF, 0x6CDC5D44, 0x15576A6C},
	{0xF9D183C0, 0xA09BAA2D, 0x41914BEA, 0xEBCF7FA7, 0x1BBC45F0, 0xF3E3DAAF, 0xCCC89B9D, 0x189A7439} } ,
	 { {0x56462AFC, 0x7E0552F9, 0xBE07B746, 0xE965D887, 0x4650AC6F, 0x68287DB1, 0x727EA74C, 0x044E5255},
	{0xFD74C32E, 0x514F91AB, 0xAE2BB0E7, 0x707AFF62, 0xAF32BF75, 0x00F41376, 0xAD6B27CF, 0x2484E8C0} }  } ,
	 {  { {0xD8CD7A9C, 0x8D5B0A55, 0xC4807004, 0xBDEFA36C, 0x81D5A571, 0x9A184F54, 0x56909CF1, 0x1805F405},
	{0xB64E4A4E, 0x052CC9DB, 0x3D23FEFD, 0x011399A6, 0xFBD6177E, 0x5E0045CB, 0xD60C9A96, 0x02F95AC1} } ,
	 { {0x0CADC588, 0x2AF9A9FD, 0x56DE9E17, 0xE870E0EE, 0xB4635DBA, 0x1A7EE810, 0xED99F3D5, 0x1BC72C99},
	{0x984B1E49, 0xD1C99F08, 0x03CC6853, 0x86F4D3B3, 0xFC8F33CF, 0x5ABBCEF6, 0xB7A0C0D1, 0x076B4576} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 659 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 660 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 661 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 662 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 663 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 664 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 665 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 666 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 667 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 668 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 669 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 670 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x519734C6, 0x7661ABF6, 0x5F0AB4D7, 0x9FB9A950, 0xF5716879, 0x1841925C, 0xAD0BBDEB, 0x1DFF30FB},
	{0x9FA876D9, 0x9FB6B387, 0xB458E52F, 0x4366F130, 0x71C98A9A, 0xF5985105, 0xB1E08434, 0x14808A4E},
	0};
		static const ecpoint_fp2 var_b = { { {0x648641BC, 0xB2297D40, 0x7642BF63, 0xE6A80738, 0x977E33D8, 0xE5552305, 0x690F1E69, 0x1B1FC870},
	{0x4E78F480, 0xB291CF88, 0x06EA5040, 0x4380E8D5, 0xC9AAC97F, 0xE893BC77, 0x9D4E5BED, 0x12125B69} } ,
	 { {0xCC635613, 0x6D206548, 0x858319EB, 0x958B9363, 0xF4CEEC98, 0x81FDE489, 0x18A38B4B, 0x0C0A3CBF},
	{0xCE47563F, 0x93FE177D, 0xB2E29E4F, 0x2DECE231, 0xDB280C34, 0xB36A5527, 0x074D4342, 0x171CACD5} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x180AAFB0, 0x43EA02C5, 0xA37B9D1A, 0xB973FC75, 0x721381EF, 0x9A22ACC6, 0x10DB51A6, 0x0D5E0DD3},
	{0xDC610DB6, 0x96368281, 0x76291CB4, 0x432F4002, 0x21D44412, 0x8406F6B8, 0x43ACCD87, 0x1950AF44} } ,
	 { {0x24A840C8, 0x95EC90FD, 0x9245AD06, 0x967250D6, 0x1F6E5297, 0xC94955C6, 0xF5296B20, 0x06FAD22A},
	{0x40C799E9, 0xE7C0B9E4, 0x6877D90D, 0xBC5F7D62, 0x6606EE41, 0x797361E5, 0x295DD4C3, 0x09A66BE3} }  } ,
	 {  { {0xBA3A2419, 0x70C5F8E0, 0x93A5CC2D, 0xE0650584, 0xAC58D029, 0x226DA225, 0x5124D264, 0x0AE8A483},
	{0x0BA6C94B, 0x2AA2789D, 0x46CF2DD7, 0x635D5C7C, 0x917D85F7, 0x92C3AC73, 0x74A5554A, 0x13569119} } ,
	 { {0x7E04F75D, 0x0607962F, 0x75A65272, 0xD0BDF8C3, 0x560D1F87, 0xFD5D11B8, 0x69D7F36C, 0x0CBE622C},
	{0x917D27E8, 0x1AE1F94B, 0xA67DA7A2, 0xA492333C, 0xE4ADDF3C, 0x6FC27C64, 0x1C5A4542, 0x19E3FEB7} }  } ,
	 {  { {0xB32093FD, 0xF99C9B76, 0x10B06066, 0xC2F0D7B7, 0x93B03BD3, 0x1B100221, 0x7F602B47, 0x15859E89},
	{0x9E63188C, 0x45D16760, 0x1E444938, 0x1761B514, 0xD0D3491A, 0xCBF2ED50, 0x830EC5A0, 0x1FEC69DE} } ,
	 { {0x805CDDDD, 0xE5BE37DC, 0x8BA5B478, 0x11D9691A, 0xB0F37CAC, 0x8E6955D4, 0xA0AAA6BC, 0x24BACE1E},
	{0x63185FD0, 0x6AE28DC4, 0x64B5C947, 0x011E71C5, 0x59C3D684, 0x2E2247FB, 0x49B034A4, 0x20481DD5} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 671 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 672 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 673 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 674 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 675 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 676 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 677 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 678 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 679 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 680 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 681 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 682 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xFD5C8712, 0x25B751B6, 0xB776E9F5, 0x3BD4F0C5, 0x90F4522E, 0x95B5A84F, 0x039175DA, 0x14B6574B},
	{0x0BCF040A, 0x1D5EAB06, 0x82FCE4EF, 0xDB886F80, 0x7AF4EB4F, 0xBCCB9A01, 0x6548679D, 0x248B3AF8},
	0};
		static const ecpoint_fp2 var_b = { { {0xBB07B28D, 0x3050A273, 0x7D5D365F, 0xE0DF5293, 0x54BDD5AA, 0x02D0218C, 0x9EB8C004, 0x00BC5E58},
	{0x2563705D, 0xF0BD7C26, 0xB46A82C4, 0x499401BD, 0xDC22EA26, 0xD2CC3EAA, 0xAB4AE94C, 0x08A73B94} } ,
	 { {0x8CB0405B, 0x817F596D, 0xEFB2A958, 0x031045AF, 0x163C9CF9, 0xCA54C25C, 0x9BB26281, 0x0A9F582D},
	{0x52147DCA, 0x2825DB69, 0x3264A77A, 0x5382500B, 0xACD2D451, 0xC2C79E75, 0x9E2D0F18, 0x05013E2D} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x044A7DC4, 0x18A428AD, 0xEDFC507A, 0xB7C81C65, 0xCDEC7B10, 0x2DB2463E, 0xDEC2ECF9, 0x179CD3B1},
	{0xD999BE46, 0x1512AD35, 0x6C9F91B7, 0x12FFFDCF, 0x217B92EA, 0xF2858B4E, 0xBD882877, 0x0A8DF4B4} } ,
	 { {0xCA647855, 0x178D6932, 0xF36DD56B, 0xF0A7266F, 0x76A03E5D, 0x337D859B, 0x4B6B64F4, 0x22E7DC60},
	{0xA94992F5, 0xB9A62DA2, 0x2E3CC600, 0x834B14A5, 0x6AFF7E1C, 0xF83C2A1A, 0xA5B2D015, 0x1ACF6160} }  } ,
	 {  { {0xF10C52B3, 0xEF2A74A2, 0xFF2F752E, 0xA254C0EE, 0x67339BCF, 0x3EB67655, 0x6D77B01D, 0x252253FE},
	{0x62B984E5, 0xB4E4DB53, 0x503ADCA7, 0x7AE8E18E, 0x80A997A8, 0xA8B1E0A6, 0x7FB13384, 0x17865FE9} } ,
	 { {0x967EF88D, 0xEDFBE2B0, 0x9CD6EA58, 0xDD7869E4, 0x8B95C663, 0x634DB31C, 0xBDD7C955, 0x0C207C70},
	{0x458CE0D6, 0x5B2FB62C, 0xAF949E93, 0xE8CFD3E1, 0x06E75DCC, 0xC0A12E99, 0x930F822F, 0x04325574} }  } ,
	 {  { {0x7C9A831B, 0x9267A21F, 0xCD57B105, 0xF8D7456D, 0x169748BB, 0x2D4DA1C6, 0xB3649520, 0x196A7666},
	{0xB1B0E9CD, 0x9D7B937B, 0x3C3AD578, 0xD9A7E38F, 0x02B9AF66, 0xD8A87F08, 0xB086518C, 0x16160558} } ,
	 { {0x2CEE7B2B, 0x8EC6C3D8, 0x56C9F5AD, 0x68D49781, 0xAB6260D2, 0xE7502523, 0xB79B623B, 0x118243D9},
	{0x140022F8, 0x1A7A75F7, 0x1EB075AB, 0xB021DFCB, 0x09A7D260, 0xE6E1B970, 0xDA63A90B, 0x17AAF103} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 683 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 684 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 685 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 686 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 687 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 688 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 689 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 690 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 691 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 692 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 693 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 694 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x1FEAA0C7, 0x184577AA, 0x0E8DE03C, 0x7DDF9EF1, 0x0DB64F86, 0xABF9906A, 0x2085E4CA, 0x0A5591B9},
	{0xF3825896, 0x0EEE24B7, 0x42CD1624, 0xE912FFC3, 0xF37C9B14, 0xE6925563, 0xE047869C, 0x11BA5708},
	0};
		static const ecpoint_fp2 var_b = { { {0x81FFD399, 0x63186D8A, 0x6439DFB8, 0x32BB0879, 0xD3799FDD, 0x70AC2BBB, 0x5B7D0B62, 0x045B912C},
	{0x66DD0262, 0xF655AEAE, 0x7AE09FF8, 0x942613AA, 0x1EF0D074, 0x36AD6611, 0x8E156EED, 0x12954B38} } ,
	 { {0x328314EC, 0xF5D79F0E, 0xA147EFE6, 0x43E747E6, 0x1BC80800, 0x3BB08DB6, 0xFA22CA79, 0x0C741DCE},
	{0x6645B8D1, 0x40E5BE50, 0x7F2AEE11, 0x3AEE8DB9, 0x8F9EC28F, 0x068CAB60, 0xDCFA7E7B, 0x18F8F11A} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x12EACAFE, 0xB4C8616E, 0x10D3FA94, 0x29A1EB9A, 0x59AF8CDE, 0xA47877B0, 0xC93D280C, 0x0F8209A9},
	{0x78C4F6CA, 0x09327576, 0x87D01B4C, 0xDE45A56B, 0xB18E934C, 0x9732F5E8, 0x574D6CD7, 0x0BF50DE8} } ,
	 { {0x5BA216EC, 0xB03AD46C, 0x1EB8F942, 0x597ADF22, 0xB6C8DB31, 0x426F484D, 0x99351234, 0x0D00F7AB},
	{0x0E80F298, 0x65F97FE1, 0x7D2B0B63, 0xEBD2B431, 0x4FC8D24B, 0xA7DA6B3F, 0xDFEE71B6, 0x0065EA85} }  } ,
	 {  { {0x2346A156, 0x9520E45A, 0xDF8F5570, 0x71A032E3, 0x8FADC423, 0xBD8F1AF0, 0x4EEFD844, 0x1F73D699},
	{0x852F0A7E, 0x7A5F569C, 0xDE32AA94, 0x2BF43A66, 0x70C94414, 0x6023A00F, 0xB6441731, 0x1DC4B0C8} } ,
	 { {0xD13FAA73, 0xE1D30549, 0xB83501AC, 0xF3201E95, 0x3A58ED2E, 0x9B4B05AA, 0x19D89895, 0x1B02F173},
	{0x78566CBB, 0x99C8A820, 0x6CC4C70E, 0x8FAD2DF5, 0xB4A06B5A, 0xBC234DFA, 0xC2F45244, 0x0BAE39C0} }  } ,
	 {  { {0xB0C3334B, 0x8B383BF0, 0xA02FB374, 0x9EB73477, 0xB833BCD0, 0xCD798723, 0x0356B9F0, 0x03AC1453},
	{0x9773F35C, 0x34895F4A, 0x181CE05F, 0xDF8E6E99, 0x1F2A9CD3, 0x4CAB927A, 0x8F58BC66, 0x1F5A0576} } ,
	 { {0xF357DE27, 0xE82293B4, 0xF88B1332, 0xE138348F, 0xEFD4021A, 0x6B7D84C9, 0x145BE380, 0x1DCA06F9},
	{0x4B6D9D82, 0x63AC0110, 0xC114E121, 0x4C9FF870, 0xE3DA685F, 0xD4EBFF40, 0xCBEA51BA, 0x18B99784} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 695 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 696 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 697 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 698 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 699 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 700 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 701 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 702 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 703 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 704 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 705 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 706 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x247D0172, 0xC7905537, 0x941D09F3, 0x92E5FE64, 0xC8E8BF5A, 0xA4E8BAAC, 0x7C8C12DF, 0x072C264D},
	{0xAB2ED817, 0x35507898, 0xB2408C8D, 0x738081D2, 0x3C7F5743, 0x551356B2, 0x2237A728, 0x11A43281},
	0};
		static const ecpoint_fp2 var_b = { { {0x6E55BDC9, 0x53A43FCE, 0x22915EE8, 0xE21573A0, 0x3CD4CF08, 0x4A12F71F, 0x4836E8CC, 0x0A77F5DB},
	{0x80BDBA67, 0x022276B7, 0x6DD8C6DC, 0x25D2F783, 0xBF737508, 0xE617C6DC, 0x9DB3F2AA, 0x1743DB2A} } ,
	 { {0x8888FC4D, 0x9320C7AD, 0xD0C9D489, 0x54F289AE, 0x78EB36AE, 0xAD1C72D4, 0x4DE12AE7, 0x02C559B7},
	{0xABF88C08, 0xBCD79FEE, 0x1B4A4649, 0xDD6DCD07, 0xCCE123B7, 0xD698E0E9, 0x35EC92AB, 0x0EDFD6D7} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB9F8CD31, 0x4E553FF6, 0xC74CE5AE, 0x82FFF834, 0xAC95FE94, 0x33C3437A, 0xE047D988, 0x1D2C9129},
	{0xA61436B1, 0x1CD55EE5, 0x0CCD4E9B, 0x33293AF2, 0x4B438412, 0xC5CF5195, 0xE6BB4049, 0x240A4129} } ,
	 { {0xC176D41D, 0xA68008CD, 0x91B2A0AE, 0xBC9D9AD7, 0x9629D8FC, 0x95BB3A24, 0xF8EDA9C1, 0x0DBC6382},
	{0xED822045, 0x5FCDDD64, 0x4E65E546, 0x2AC04C17, 0x47DBDFD5, 0xFDB326AF, 0x56EB96B8, 0x24748AFE} }  } ,
	 {  { {0x5D6E664B, 0x2BD53EBB, 0x5800C4F9, 0x907528D4, 0x366AD6D2, 0xE90B9BF6, 0xB28C0821, 0x2316AF4F},
	{0xD0A1FB86, 0x2BB5D394, 0x9DCEA246, 0x2F57A289, 0x43B587F7, 0x6C49D4CF, 0xAB34AA11, 0x13A97490} } ,
	 { {0x6CA7C497, 0xE75685C3, 0x7783F48D, 0xAD9D4A82, 0x081A50F6, 0xAB7CF52D, 0x51228FFF, 0x09F6B062},
	{0x4D062C90, 0xF966F5DE, 0xBA6E65D8, 0xAD8D134B, 0xF8006BAF, 0x1E3A6D43, 0xDE9E9D16, 0x132D3FB5} }  } ,
	 {  { {0x47E84653, 0xB037A458, 0x8337DBC7, 0xD33A1989, 0xD581ECC4, 0xF03F8EBB, 0x5DCA3C32, 0x245DE532},
	{0xE1F5C68F, 0x6B38FFE7, 0x8F57B0F3, 0xF7E3B02D, 0xE586D08B, 0xD2A8F554, 0xF438DFEA, 0x0E92B578} } ,
	 { {0x58E8F942, 0x5C447237, 0xFB519FE5, 0x6F45D314, 0x1021119F, 0x3E08EF27, 0x2A800AEC, 0x1E272678},
	{0xB8760D47, 0xC5857EB2, 0xC1D38FE5, 0xEF8C3D7A, 0x3812D6FE, 0x4F5A3410, 0x470D45ED, 0x1D335123} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 707 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 708 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 709 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 710 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 711 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 712 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 713 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 714 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 715 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 716 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 717 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 718 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x62BFD718, 0xCF4938D9, 0x707CCBB1, 0xB1603B90, 0xE3238F3F, 0x498EFAD7, 0x4A81B56A, 0x20EDCE3D},
	{0x35D0A360, 0xAFD6E3F2, 0x3776E79D, 0x73B0ED42, 0xD986D9C3, 0x8D2B575F, 0x938B5EA3, 0x06DEBB45},
	0};
		static const ecpoint_fp2 var_b = { { {0x4704D71B, 0xDB6BC3FE, 0x7C767BF2, 0x7E45A781, 0xB24D788F, 0x47C2999D, 0xFAAF3D47, 0x21A41E4E},
	{0x3E9295AB, 0x1230E488, 0xBE6FF381, 0x50F9A0F2, 0xDA73CBB0, 0xCDE31F66, 0x4C0F074C, 0x0DF4CC54} } ,
	 { {0xB825DD00, 0x7F95BD99, 0x173C8C58, 0x8E76AB62, 0x7562DF60, 0x49440238, 0x893FE34B, 0x1C2E5B84},
	{0x6C3F1F89, 0x8B822A9D, 0xD064CF5C, 0x15A878E3, 0x5E7F85EC, 0xF566AC8F, 0xD87FAD2C, 0x1BBEEEFF} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x80390BB6, 0x8390CA91, 0x6E2AF974, 0x8533B862, 0xF631EA25, 0x315F2452, 0x13039899, 0x2237D297},
	{0x52944773, 0xC3C97B17, 0x33387213, 0xD8E306A2, 0x990EE04D, 0x70C2248F, 0x44F021B1, 0x17FB7CF1} } ,
	 { {0x59E97ED6, 0xAA3EDC84, 0xF5695AF9, 0xE520E53E, 0xF5CDE3BC, 0xBDAB71B6, 0x3F5B055E, 0x187CA124},
	{0x571297F3, 0x85F60128, 0x39505EFC, 0x05CB29BA, 0xB154CAEA, 0xAE567BE4, 0x1A34A497, 0x0080C5F2} }  } ,
	 {  { {0xEE81F564, 0x5B148F8E, 0xB9BD6FA4, 0x89D7E846, 0x3558DB64, 0x1B937999, 0xFCFC9B9F, 0x0808DA9D},
	{0x6C3C0B05, 0x3ED1A378, 0xA7C27611, 0x7E948F78, 0xC5B70E40, 0xC151E2DC, 0xFEE28E6B, 0x1486AB20} } ,
	 { {0x82B93C0D, 0x74F3B3BE, 0xC339837B, 0x278A1C70, 0x57DCCF78, 0x39E7EB1F, 0x15DFDF2F, 0x12C8FD52},
	{0x35981A89, 0xD0D4F98F, 0xD5D4BEA3, 0xAA636F7B, 0x2BA5E5AD, 0x58E349CA, 0x67EC3D82, 0x091E32A5} }  } ,
	 {  { {0xECF97811, 0x28498F6F, 0x28C6A97F, 0x052BF98A, 0x5FBD221E, 0xAEBE72A8, 0x7CEBD732, 0x247025A4},
	{0x2A2E7001, 0xF6F1BD00, 0x0DFCE09B, 0xF110C2E9, 0xFC77DE11, 0x1EB08DCE, 0xBC9CEC0B, 0x13D95D5A} } ,
	 { {0x7DD0D8ED, 0xBC3045BC, 0xEAD6BC58, 0x63F08813, 0x0758C45D, 0x449F30A1, 0x7FF762E0, 0x08D3F645},
	{0x4B5A65CC, 0x4E39A5B7, 0xB9EB381A, 0x78A203F9, 0x9190CB01, 0x514F10A1, 0x1B128D53, 0x06953A46} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 719 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 720 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 721 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 722 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 723 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 724 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 725 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 726 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 727 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 728 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 729 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 730 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xE5F97F16, 0x5EF4EC07, 0x6A8BF4A7, 0xF94BE322, 0x695C48A5, 0x2622BFCF, 0x8E220FF9, 0x080F4B5D},
	{0x008D6791, 0x8BE8C916, 0x370B2247, 0xE8BEAA09, 0xDB4A9C65, 0x3851CCEA, 0x207C5475, 0x01EE1DA2},
	0};
		static const ecpoint_fp2 var_b = { { {0xA0CD66DF, 0x160222C8, 0x26C1B50B, 0xEDEE3994, 0xE0472367, 0xA052A395, 0x3505EB8F, 0x0F3FCCA2},
	{0xEF214BD8, 0x2C2AE886, 0xF5900E84, 0x2541B600, 0x86D5FA4C, 0x5B0AC7E9, 0xF8370920, 0x179447A2} } ,
	 { {0xF38786DE, 0x9260C278, 0x36C883E1, 0x677B25EE, 0xD4012623, 0xF5764CA8, 0xFFB62914, 0x1CD226F8},
	{0x0335B81F, 0xC23C52C4, 0x3C9E142F, 0xA90CD4D3, 0x82C036AB, 0x6BD47B10, 0x35C2AE5F, 0x19672D09} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x1D21AD2C, 0xABC6207B, 0xC1DCFBBE, 0x96E46118, 0x44C06D3D, 0xE3A0EB53, 0x27161224, 0x0379264B},
	{0xB923E4B2, 0x3E443D04, 0x565FC1A1, 0x663E2269, 0x0D5489F3, 0x4B8673C3, 0xFB110674, 0x01D069A0} } ,
	 { {0x581F10B6, 0x37C86BB6, 0x5FBC851A, 0x5C890B5F, 0xBE08B875, 0xC4520C05, 0x64378A7A, 0x24040FB7},
	{0x893DE2A2, 0x73B99E35, 0x51AAF3E3, 0x93E4C77A, 0xCD6E54F6, 0x46F0DB41, 0xD6FDA014, 0x09B82C46} }  } ,
	 {  { {0x7F18155E, 0x41815803, 0x5D2A40DE, 0x186F43CE, 0x9D02E598, 0x8137A6FA, 0xBF0A4171, 0x0A3DCB6F},
	{0xD9A0AE93, 0x8ECF9455, 0x9AB134CA, 0x9C674E18, 0x52E1C9AC, 0xFAE3DF48, 0xE54FFD5D, 0x01371C47} } ,
	 { {0x6E07EF7B, 0xFF66EB71, 0xD204FB14, 0x79CEEBE6, 0xE2040B1E, 0x5B28E7C0, 0xB35B7DC6, 0x0E73AB5E},
	{0xA2807DB9, 0x09ED1CEC, 0xE366F9D5, 0x06BF4762, 0x34236344, 0xA3703578, 0x4CF52B7C, 0x19AF491D} }  } ,
	 {  { {0x7DB4D46B, 0xEA781DCB, 0x99D2AF2C, 0xE98697B1, 0xC0CFC2DC, 0xB43B4909, 0x7615098A, 0x24B95F25},
	{0x0BBAA0B2, 0x4E3287DB, 0x862FE774, 0xC46ABA1F, 0xD5FE3F4C, 0x43A7370E, 0x7873F026, 0x02539BC9} } ,
	 { {0xE2A64882, 0x3C593C71, 0x1F5BA91C, 0x9E33D682, 0xB05D8B1E, 0x1F902E5C, 0x18B3E902, 0x055B4BD6},
	{0x5D270E17, 0xD5C7B917, 0xF99D257F, 0x4622AC6F, 0x2CD3FF89, 0x445D5FD5, 0x35ED239B, 0x206BEA73} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 731 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 732 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 733 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 734 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 735 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 736 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 737 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 738 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 739 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 740 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 741 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 742 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x434FEB82, 0x778894A8, 0x923E2F6A, 0x0A899706, 0xA99CA348, 0x27E42CEC, 0x7F642ABA, 0x0A3DC6E4},
	{0x99088AD5, 0xA3B7AA49, 0x429D1488, 0x744AEEDE, 0x94113E86, 0x8B6E899A, 0x0CF56708, 0x1C1DBFFB},
	0};
		static const ecpoint_fp2 var_b = { { {0xB86F2519, 0x1243AE20, 0x305866B3, 0x7F399D71, 0xB49E585D, 0xC277990B, 0xF1C4B44C, 0x22B1215C},
	{0x4452F225, 0xE0477B1F, 0x8E689E9F, 0xFDF5FA81, 0xCBEAC604, 0xDA060323, 0x655B8D93, 0x1F433C65} } ,
	 { {0x97E26DD8, 0xD5F82AA8, 0x71209F82, 0x8E4A5A31, 0xD6497CF5, 0x62B4F9B7, 0x428FC237, 0x1D82D624},
	{0x38E5965D, 0xA67B1665, 0x443161C5, 0xD56A0C56, 0x17E43F4E, 0x401BAB3C, 0xEDDB3CB8, 0x012F4A3C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x992BF0D2, 0x69535C6F, 0xBF25CA6F, 0x5A56556C, 0x0AB53F3C, 0xD31631E7, 0x304265BF, 0x00FF22BA},
	{0x2C44B678, 0xE6462018, 0xA6AA3EF3, 0xD38FED5D, 0x5615C049, 0x1EB9AF8C, 0x3FBB3FAB, 0x2193E206} } ,
	 { {0xB7FD679C, 0xE23C1644, 0x94769370, 0x96A59200, 0xD802791A, 0x7B4C03EF, 0x0BF26A14, 0x07CA0CF3},
	{0x7D042354, 0xB121C7EA, 0xB481B7DD, 0x82E6BC80, 0xA38EF8A2, 0xAA68A87D, 0xD5E1597A, 0x1006CA61} }  } ,
	 {  { {0xEACDC473, 0x629E2401, 0xE7480B4A, 0x41883542, 0xF0EC5DF0, 0x8F1A2B38, 0xB6116040, 0x050AC823},
	{0xD871E340, 0x1AD1C414, 0x9E112C63, 0x9F7BEC47, 0xCE53D38C, 0xA1804E32, 0x3FC88086, 0x1A52C9D2} } ,
	 { {0x0E556FED, 0x2CDF68CD, 0xE8D89029, 0x92C77B74, 0x5E1C21C7, 0x8BEFF56D, 0xADFC69D9, 0x0B0B99E3},
	{0x349E8354, 0x0F624F0C, 0xA677BD99, 0x1A5BBF54, 0xAD1953C6, 0xEAB2D3C3, 0x8CC4EB55, 0x00532A4E} }  } ,
	 {  { {0x01F37878, 0x7D20377F, 0x96967A2A, 0x2A9F1AF7, 0xE1DCB948, 0xB91A9A4B, 0xB02DBAAD, 0x19767EA3},
	{0xC5ACA70D, 0x84AC59AF, 0xC69333AD, 0x888F1D36, 0xB27F1064, 0xFC3D2838, 0xBAB907CE, 0x0ED2C24C} } ,
	 { {0x740006DB, 0xB2894408, 0x092DE70F, 0x3249D22C, 0x1E8CF5C7, 0xC0F52B64, 0x648A56D3, 0x1E1E460D},
	{0x8F934746, 0x4C08927F, 0xF9394894, 0x75DA40C4, 0x72045FE1, 0x009ED52E, 0xC01E362A, 0x03A252D8} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 743 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 744 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 745 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 746 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 747 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 748 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 749 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 750 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 751 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 752 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 753 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 754 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x9CC8B985, 0x261F8E41, 0xB3806457, 0x08AE8BFF, 0x5D05B038, 0xA687DB67, 0x12FD04C2, 0x144B8E56},
	{0xE0F2061B, 0xFD6E3A46, 0x47960D5B, 0x3FFC6D59, 0xDF575064, 0xF4C77BFA, 0x9ECB2B47, 0x05548FB9},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x977434CE, 0x72079C46, 0x5EAA7852, 0xC867D07E, 0x7ED55369, 0x86925C0D, 0x62F79BDF, 0x03F633BF},
	{0x318D731F, 0xB64081F2, 0x13B8F52F, 0x4D2809FA, 0x336B895A, 0x01255D33, 0x8F3F5641, 0x145B32DE} } ,
	 { {0x3D23DD98, 0x5BE02886, 0xC6678415, 0xF46BC9F8, 0xE9F5D13E, 0x4FF4A69C, 0xE0F6E931, 0x202F689A},
	{0xB3F8D9BC, 0x52AB7711, 0xEDB5ED7A, 0x97D11E8F, 0x64E904DC, 0xADD895D0, 0xCA048D23, 0x0653648D} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x0C1121E8, 0xC22AF2A2, 0x52ECFC56, 0x25815F5D, 0x09D454AF, 0xB735BAD7, 0xD1C601B8, 0x1F89A073},
	{0xF8A581D0, 0x772E4E33, 0x3243C648, 0x8421F1ED, 0xCD3D32F9, 0x965640DB, 0xF1924D75, 0x10421335},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xCE2B526D, 0x40BA4DDA, 0x13725E91, 0x71FB14A6, 0xE798ED2E, 0x33BD0C11, 0x8284CFFB, 0x01E1F0D9},
	{0x8FC54636, 0x2A57460E, 0x35DA2D03, 0x019D884A, 0x121AA26C, 0x69A42305, 0x32C508D8, 0x08736105} } ,
	 { {0xBC0005D6, 0x4430CF97, 0x915C446D, 0x17313643, 0x09FD5591, 0xE6113756, 0xB0ED1CBD, 0x0CA56C5E},
	{0x863CF935, 0x889E06DC, 0x07EAC9A2, 0x595096E4, 0x6D0C6058, 0x5E4F4FF5, 0x6BA4A15D, 0x07F1DE38} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x08477093, 0x9E267A11, 0xD78F8937, 0xB19A9265, 0xB5898B9C, 0x188CF9ED, 0x1023A5C9, 0x22C91D81},
	{0xA5C865A0, 0x7EA8D706, 0x44AA72E1, 0x6A1C72F3, 0x89CA6EEA, 0x1509B746, 0xF3887A13, 0x0DC23CEE} } ,
	 { {0x6EB07BB4, 0xA78F9905, 0x59C20164, 0x41BCA272, 0xE5F12220, 0x6A32E1A8, 0xFA650572, 0x1FDBBF0E},
	{0xF4322BAC, 0xB5021D5C, 0x59DB500E, 0x4CDD8C79, 0x689DE47A, 0xCBA34497, 0xFC7349E8, 0x1D6B25D5} }  } ,
	 {  { {0x1ADCBDC1, 0xA777AEB7, 0x8FE2DB4E, 0xC604F185, 0x4E270582, 0xA3891D00, 0x26673D60, 0x1732FE60},
	{0xDBEFE088, 0x4478196A, 0x76892DA7, 0xBDFF99EA, 0x590EC075, 0x25C1266B, 0x27D28ED8, 0x00989E8F} } ,
	 { {0xB0268BA6, 0xA930B5E5, 0xF42D4A85, 0x059EC9FC, 0xBFC6DE6E, 0x6718A56D, 0xD288A7BA, 0x08982941},
	{0xF223EEDF, 0x1A42E424, 0x2B55CAB9, 0x093F9796, 0xE45AAAF3, 0xD7C8EB3D, 0x7E257126, 0x03C99C99} }  } ,
	 {  { {0x9399202E, 0x4337F9F3, 0xCD150004, 0x2509DF24, 0x711B3993, 0x5B557E41, 0xCC0F36C0, 0x024BB171},
	{0x4157B035, 0x50E01B14, 0xD8984224, 0xF3F80A18, 0x3C7A731E, 0x5B497B7E, 0x53D28264, 0x1115B6B5} } ,
	 { {0x740AE37F, 0x662B03F0, 0x04095CC4, 0x3B303BC3, 0xD5E71E73, 0x370BE804, 0x3C555544, 0x23D589ED},
	{0x16CEFDB2, 0xE5DF8104, 0xB46924B8, 0x6DB35CDF, 0x4F3BFCF5, 0x79C535E7, 0x3631A085, 0x09B8A69A} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 755 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 756 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 757 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 758 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 759 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 760 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 761 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 762 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 763 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 764 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 765 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 766 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xA4ACDF7F, 0x7384C97F, 0x3C8A98DD, 0x3C1481ED, 0x3C6444E2, 0x0EAC86E4, 0x3204ABD1, 0x04F87B9D},
	{0xD8218F7E, 0xC6B430EC, 0x104CC9E2, 0x74B70610, 0x69FFDEC5, 0x7C9D0F6E, 0x1397EFB4, 0x0274E138},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x9C334F9F, 0xC8D0C514, 0xB72BD337, 0x2F24477E, 0xAFDA811E, 0xEFBDAB3D, 0xD9ECC086, 0x13F6306C},
	{0x8ED34719, 0x16EEFB65, 0xE6DFD770, 0xD6CD5879, 0xC94E5D6F, 0x7984C2CB, 0x1CD7169C, 0x1092C235} } ,
	 { {0x7ED62A39, 0x85C83281, 0x21231B47, 0x766D27A4, 0xC7C0DFA1, 0xF0BC3B2C, 0x9C4CB486, 0x1DB58F24},
	{0x9A3E36B6, 0x44D2574F, 0x80C92FA9, 0x1BF5FC87, 0x6109E7C2, 0x94FDE2DB, 0xC7BB4336, 0x1AC08B76} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x314AB4AA, 0x6027F1CA, 0x7554540B, 0x682AA28A, 0x2CE319A0, 0x15584978, 0xFB9A19AC, 0x18E49123},
	{0x0E3C0B73, 0xFDF2DB73, 0x0B9D49D2, 0xB6234000, 0x235CD498, 0x9B3ED6A9, 0x80AAB69B, 0x10287EED},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x0543EA7F, 0x23CBEEDE, 0x4920B404, 0xAF4F0810, 0x1A524C41, 0xDC980115, 0xE4710F73, 0x22A59C3C},
	{0xDF16C5D7, 0x7BF4A984, 0xAFA2BA5B, 0xFCF1B7D5, 0x88B988D9, 0x5BD9D01E, 0x59E146DC, 0x11D14291} } ,
	 { {0xB1F3BE57, 0xE8197EDF, 0x9660ED81, 0x6998AF55, 0x700A1BE3, 0x8780BFC6, 0x9975FE78, 0x0379AAF9},
	{0xA2268C2F, 0x2B7BD3F3, 0x69ACAB7B, 0x3F2E37FE, 0x776FB16D, 0xD1E38E3B, 0x2C2CDEB2, 0x05DBA4C7} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xCA4244C7, 0x91F06A12, 0x4DFAF21A, 0xE8B9EBA9, 0x7A959423, 0x5671E1D1, 0x3C9DC7BA, 0x2272985D},
	{0xE89CD04C, 0x809A6F04, 0xE4F067C1, 0xC94312CA, 0x85BDA225, 0xA421A3CF, 0xC620AABC, 0x1693BE54} } ,
	 { {0x6AA9670D, 0xE34A95F7, 0x00186430, 0xBADF6F55, 0x9C5B1AD2, 0x13F76BAA, 0x4715158E, 0x14A4C0C4},
	{0xA0E42311, 0x7FA2F4DE, 0x8B89395D, 0xCD7EE3EA, 0x6013D66D, 0x74A6CAA2, 0x01D20030, 0x00864ACC} }  } ,
	 {  { {0x8EE57995, 0xD4645634, 0x349A5481, 0x69FA0934, 0x49D2F479, 0xE2383866, 0xB6999C89, 0x0FECFD7F},
	{0xDF20557D, 0x32351A18, 0xC88CC75C, 0x210AA79A, 0xBF0356D1, 0x34ECA9DC, 0xAFE51A1E, 0x093A2468} } ,
	 { {0xB855795E, 0x6642AA7D, 0xCA59E4AD, 0x0F57E136, 0xF963AEE0, 0x2A499CD9, 0x949A6BFC, 0x0AEF8629},
	{0x2DC74487, 0x324E7A3B, 0xBAB6B70A, 0xD91E5175, 0xA23C1E93, 0x463F6B1C, 0x2D8C726F, 0x08F6002E} }  } ,
	 {  { {0x2CB4AC72, 0x53E4D668, 0xAB186F95, 0xB0B4781D, 0x52281C8C, 0x19D9A6A9, 0xA7382611, 0x0F355665},
	{0xE9B75D80, 0x7BC0DD4A, 0xFB9DD9A7, 0xEC7F9849, 0x56B4BF79, 0x6F2127DD, 0x0085BAAB, 0x0E92F70F} } ,
	 { {0x0BF0B674, 0x5F10E306, 0xB6C4CC85, 0x1763AF2A, 0x2C1C904B, 0x43307EA8, 0x14CEB488, 0x04693F12},
	{0x6E886F03, 0xAC3BF80B, 0x7E37F26E, 0x34585E07, 0xFD18E464, 0x381DB0FF, 0x351FC986, 0x001056CA} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 767 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 768 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 769 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 770 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 771 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 772 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 773 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 774 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 775 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 776 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 777 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 778 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x6E76B16B, 0x85C2E7B4, 0xD7B4070C, 0xA8469A48, 0x639D541F, 0x444050B4, 0x70EEBB86, 0x0EB1395A},
	{0x0C831CD2, 0x98572E76, 0xBF266B25, 0xCE8F4CAC, 0x7CF8DF7C, 0x2BBA64CA, 0x76EFCDC5, 0x014A593A},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xCE9EE719, 0xF37ACA85, 0xFCC6931E, 0x89A2B987, 0x267EDD01, 0x96867770, 0x986CD563, 0x1F41D1A0},
	{0x447D5C7A, 0x17F8DDFC, 0xB53500F2, 0x016C6E6E, 0xC8830908, 0x46BAD694, 0x23A4156D, 0x0905E8E5} } ,
	 { {0xA453A193, 0x8915488E, 0x45F80A96, 0x87CA46E7, 0xD67A946D, 0x6F489089, 0xA962467C, 0x16BC354E},
	{0xCB938A93, 0xBF86C2B9, 0xBE9E11CE, 0xFD0BA319, 0x2D3E3846, 0x23CB13A6, 0x7DB816B1, 0x176CDCB4} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xFFAA5CD7, 0x0FCC21F6, 0x50FE259C, 0xE76502DB, 0x5F80151B, 0xC448808B, 0xA1BDBA62, 0x16864B7F},
	{0x4D530965, 0x1BF5FD9C, 0x3CA40AE3, 0x81339487, 0x36536976, 0x5F016480, 0x83963403, 0x1909C6A2},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x49E38860, 0xB33D5571, 0x68BAB9F8, 0xBF9F60F2, 0x8B42766D, 0x0CB0EA93, 0x36B5CE76, 0x1AAD8395},
	{0xE0F763C5, 0xBAD2112B, 0x3F16C573, 0x5F0C322C, 0x6DB85061, 0x5FB9E408, 0x52BC0F2A, 0x092486F3} } ,
	 { {0xA6EB14AD, 0x21BE1B72, 0x579405A7, 0xFBCD669C, 0xF4B11D5D, 0xADC94652, 0xC65C3E85, 0x11397C88},
	{0xA0402231, 0x0C188857, 0xA6880588, 0x85C9F8B9, 0x4C67F9E5, 0xFCD704E2, 0xB248D54A, 0x10896526} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x24032CE5, 0xCCB21D61, 0xC19EB47D, 0xEAFCDE81, 0xAC642384, 0x33DA755E, 0xE6C48934, 0x1B21F6CF},
	{0xC4A0C627, 0xA75BFBD7, 0x82062BFA, 0xD598D2E0, 0x55B3CA2B, 0xD9F2C55B, 0x8FCE57CB, 0x1C70EB8E} } ,
	 { {0xE8F7714B, 0x3D857398, 0x5D18CC12, 0xCA45EEEA, 0x48E8382B, 0xEE8496DD, 0xF90E1757, 0x038B9761},
	{0xADAED95E, 0xC8428553, 0xC33F392C, 0x2FCA4205, 0xAEA46F97, 0x8874144D, 0xF8177151, 0x097CF190} }  } ,
	 {  { {0x0FE512D2, 0x0EBA6936, 0xCCFA129D, 0x22DE7E36, 0x5D3BF773, 0xA8479DD7, 0xE5635F68, 0x1FD57F66},
	{0x16F7DF57, 0xB26C9CEC, 0x6609C0A7, 0x489F5EC3, 0x2D7047A5, 0xA41976F1, 0x90B39604, 0x064A6DC2} } ,
	 { {0x325D52E0, 0x14FBE505, 0x09B3F918, 0x9C383614, 0x722F1D38, 0x0272576D, 0x0708A6A9, 0x12705DC5},
	{0xC2D58DA4, 0x587ED980, 0x1C1717B3, 0x303C2C50, 0x05A59FBB, 0x3B418428, 0x220A8921, 0x0E6CCD4C} }  } ,
	 {  { {0x06A96A36, 0x7DF64773, 0x7B2CF11D, 0x232D3719, 0xCA2E88BB, 0x73795846, 0x1A06D29A, 0x02B85406},
	{0x333031A6, 0x0D43F597, 0x6461A415, 0xCCA70AE4, 0x20FEBED9, 0xF0EED3BE, 0x2ED46674, 0x0EB4A813} } ,
	 { {0xC4B559C6, 0xF639D37E, 0xE40F2E17, 0xEF41EE89, 0x2B399DCC, 0x222C3967, 0x0544CD69, 0x13C77228},
	{0x618B5ED6, 0x06567350, 0xD5F1D677, 0xAA796A16, 0x474103A0, 0xC178FE73, 0x5904FAB8, 0x245C8AFF} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 779 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 780 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 781 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 782 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 783 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 784 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 785 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 786 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 787 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 788 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 789 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 790 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x7A47F35B, 0x95128D2C, 0x60AAD8E7, 0x10E2C584, 0xF8E8C987, 0x8E050B84, 0xE585197C, 0x1554563C},
	{0xC07CE7AE, 0xD81ED2AF, 0x1F7496FE, 0x0AAD9865, 0x42D52B60, 0x6DF62697, 0xD2266E5A, 0x12970924},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x55142B1F, 0x7D677AE5, 0xAF452C72, 0x1E8EF75B, 0xC2FB3D24, 0x1322EEAB, 0xBA724629, 0x20BFE09E},
	{0x7E0C985C, 0x6D1B5C5C, 0x317CE9F2, 0x5432AD62, 0xF0B116C0, 0x702A7ED2, 0xB5408611, 0x23A72498} } ,
	 { {0xAB7EBBDB, 0x568D8180, 0xE715BFA6, 0xE710F9BE, 0x81DE22BF, 0xB69DDE23, 0xCDDD63E6, 0x17B71C38},
	{0x1D19F91C, 0x86E22BC3, 0x100B4DE7, 0x3EAB14E1, 0x0C34D39E, 0xE24CF83B, 0xADDF5C86, 0x0F50A66E} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x5C134594, 0x6BF9BF71, 0xCEFBAABE, 0xB6521F18, 0x07DC8EBF, 0x46828124, 0x22D0EECD, 0x03FEFFA0},
	{0x12A5ECE5, 0xC595B865, 0xF90ED73E, 0x4317630C, 0x0AB9DBB0, 0x3768FF39, 0x7909A5E1, 0x12E36428},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x9255CC61, 0x6D000218, 0xB7A4F870, 0x65C73AF3, 0xC80FE189, 0x182E7D2D, 0xF6F49CF1, 0x07743749},
	{0xF1B62904, 0x4575A0C1, 0x771FDC4C, 0x9D41630C, 0x876C08E4, 0xC8E26A17, 0x51019F24, 0x04B6378A} } ,
	 { {0xF4C7429B, 0x3D36371F, 0xAC7B35CD, 0x46D2196C, 0xDFDCED16, 0x551F3676, 0x07127414, 0x1252F3C6},
	{0xF48308F1, 0x5875D439, 0x0F1D7DDC, 0xF733CFAA, 0xA581B1E4, 0x1EB0288F, 0x1F199ED4, 0x113F3F5C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x8A3AF29C, 0x5F6A7C89, 0x41D92F68, 0x69ED6D57, 0x412BD45C, 0x4E50F03A, 0x8F970133, 0x188424B5},
	{0x4E8C8AF7, 0x842C0F11, 0x7F615B43, 0xAF57984E, 0x70825BB4, 0x704BEED5, 0x0035436B, 0x03E01A93} } ,
	 { {0x2B1A2702, 0x41F44BE4, 0x5C1DC557, 0xC395FCFA, 0xC47D2A46, 0x60674C2A, 0x9634C996, 0x0940FBDC},
	{0xCF63BB39, 0x2A7EF89D, 0x08651833, 0x7BDDA956, 0xC9817E4E, 0xF93C83EB, 0x8D7CFBEF, 0x1E7F6AC7} }  } ,
	 {  { {0x979E8FD7, 0x2442183C, 0x481558F6, 0x13475D90, 0xA388AEBC, 0xBC51C7BC, 0xD2A5BC10, 0x20D19E08},
	{0x592A5317, 0x184749D0, 0xD95E4CAD, 0xDAAE2DD6, 0x68ADB99F, 0xE2CD5089, 0x46478A3F, 0x1B262022} } ,
	 { {0xBEA3B1EF, 0x9FAAB016, 0x69D635AC, 0xEAD5463C, 0xDF00598B, 0x91A2287F, 0x344DAC13, 0x10EC415F},
	{0x55DFD342, 0x959D80E3, 0xBB3465CA, 0x53B6AB56, 0xA380DE1D, 0xE8B4A1A3, 0x151A9A50, 0x14529618} }  } ,
	 {  { {0x698782B2, 0x490C0968, 0x9841FB2D, 0xA09253AC, 0x8DC9E309, 0x41CC497C, 0x60DBAED3, 0x1970449D},
	{0x7A047F8F, 0x7804F694, 0x6C755B5E, 0xF12A2772, 0x7CBF7BC8, 0x024254AF, 0x4DB34020, 0x0B40F577} } ,
	 { {0x35CA0910, 0x9CE7E784, 0x8471765F, 0x0425457F, 0xF905436B, 0x1E690A4B, 0xE2FA5465, 0x237E313A},
	{0xA94BB25F, 0x81E2017D, 0xA651A6A1, 0x7EFD4C2A, 0x348E97CA, 0x5C08E5B2, 0xA10C74AA, 0x05382D1C} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 791 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 792 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 793 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 794 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 795 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 796 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 797 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 798 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 799 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 800 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 801 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 802 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x584DC45C, 0x5F2C4B3C, 0x45154107, 0xB0FB69E1, 0x84A491B7, 0x4CC60A09, 0x0B250A9C, 0x0092FAC9},
	{0xDEBDE980, 0x68075E9B, 0x30931EDD, 0x8B8FB7C1, 0x62CA6E00, 0x6603C3D7, 0x634D12A6, 0x1D53A8ED},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xD8ACB77A, 0x28D6E7BA, 0x818A517D, 0xB08C12E7, 0x26BA310D, 0xB8871922, 0x89CEC2C9, 0x1EE061A8},
	{0xC4B699FB, 0x4447C4C3, 0x7125D437, 0x55C90E96, 0x1BBA4949, 0xC7771504, 0xF652645E, 0x229FD27E} } ,
	 { {0x2A91748F, 0x00262023, 0x59239C78, 0xB0ECC893, 0x56238672, 0xCF632245, 0xBEECDCC1, 0x0BE17965},
	{0xF2024DCD, 0x4712E943, 0xCD6722B6, 0x02C29D4A, 0x5B63C080, 0x42A3038C, 0x4A1307B0, 0x17E31F98} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x81A4623A, 0xD3BE8BB4, 0x29CD7414, 0xBE43B6FB, 0x45E598DB, 0x3F789F3B, 0xC7AABBFC, 0x0FF1D320},
	{0xE2DD7F7E, 0x212D2B75, 0x4FD50404, 0xA3EEDDC8, 0x631B1334, 0x242779C1, 0x5C85E256, 0x202E01B4},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x7E11CA81, 0x50CC4D92, 0xC3FC2712, 0xD258823E, 0x1C564E03, 0xDF3C786A, 0x858D2A93, 0x1211B9AA},
	{0xC499D25C, 0x4E4CDADE, 0xB417D5AE, 0xEB3982E9, 0xE3A558BC, 0x2285019F, 0xDE4A0ADE, 0x1581AF0D} } ,
	 { {0x4FE4B304, 0x5B1F7A55, 0x39FC3CF0, 0x80B0909B, 0x4E84CAF4, 0x8210C441, 0x0C3798D1, 0x17DFF633},
	{0x87720EF0, 0xD171A8CE, 0x6D7F98A6, 0xFE77E159, 0xEF49947A, 0x1DB95013, 0x89673433, 0x076D3CEE} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xCF4192F0, 0xB8A6D502, 0xEDE95092, 0x31E06BC1, 0x31346CFB, 0xA78BCDFD, 0xAD9B556E, 0x0762171E},
	{0xD7A88948, 0xBB9937EC, 0x4D669E3B, 0xC85B4C8D, 0x9A2FA36B, 0x748DE213, 0x809C2417, 0x187880EA} } ,
	 { {0x9A4A95A4, 0x8DE65D8F, 0x323F8F1F, 0xA0400936, 0x53E4708A, 0x06DEA42F, 0xDBFF025F, 0x08C8C938},
	{0x36EFD667, 0x2274CED0, 0xCEA389A2, 0x8A2F5DEB, 0xF77CA58C, 0x9B4349E8, 0x44FA74D4, 0x1B1364E0} }  } ,
	 {  { {0x4A74ABC2, 0x614750FA, 0x73412937, 0xC7762297, 0xBF8BCE52, 0x7CC67A96, 0x44A2A573, 0x196CA1C5},
	{0x95669491, 0xCC2B9602, 0xA6927CDE, 0x655D5843, 0x1F4656C3, 0x56761E07, 0xA06CC0D3, 0x12BEB346} } ,
	 { {0xD322BE61, 0x6432D743, 0xF3260932, 0x7A40A65C, 0x551EAB51, 0x8E2415FE, 0xBA6CE597, 0x06488F44},
	{0xF104C3CB, 0x0252A774, 0x8437F450, 0x404E59C6, 0xEF260800, 0xBAEC06A2, 0x410D2A8C, 0x2275CBD4} }  } ,
	 {  { {0xDE59A18E, 0x15B4CFCC, 0x4C6895B4, 0x3DD18086, 0x103D45AC, 0x6A8463AA, 0xCD7818CA, 0x0DC9989A},
	{0xD9717185, 0xCDAB2E08, 0x68A41452, 0x9D61EE2A, 0x8CB4B18F, 0xAACBE27A, 0xA4D50611, 0x18D35BA8} } ,
	 { {0x30C10325, 0xBAB38CDF, 0x7B285966, 0x11F38338, 0x3F5D1925, 0xF60EA4E6, 0x7CD5520B, 0x10FC028B},
	{0x49457311, 0xEA824757, 0xF8906697, 0x2524EAC9, 0x2D9F00A3, 0xA6F04621, 0x3572EC1C, 0x132CC093} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 803 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 804 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 805 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 806 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 807 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 808 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 809 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 810 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 811 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 812 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 813 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 814 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x608C0A5F, 0xBFA3A069, 0xA2AE4E4C, 0xF5F1D1BB, 0x03CAECF0, 0xC1E97BB5, 0x5F9E2D49, 0x049FB1DC},
	{0xACB1834E, 0x8ADC1F7A, 0x50741C4C, 0x51AD6FBA, 0xB4B362F7, 0x8FAA43B8, 0x9E2541E0, 0x1FED5303},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xE5C13414, 0x2D02CA2C, 0x86B8200B, 0x7C81F3E4, 0xC13072D6, 0xD3C927BC, 0x97D5A061, 0x1F374F3E},
	{0x291C4E43, 0x35E88162, 0xB38409CE, 0x11CC5366, 0x3AE0AF99, 0x5DE8BFF1, 0xAA208FFF, 0x038E1F08} } ,
	 { {0xAF80ED20, 0xC87CC332, 0x58D79A98, 0x58607D7E, 0x90167278, 0x45D3FE45, 0x6F4C4A47, 0x084CAD58},
	{0xD0ADAD52, 0x1BE6B6E0, 0x0A87A0AC, 0x6C2586C2, 0x978AC030, 0x2C865B03, 0x9E699ECD, 0x20FDBEED} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x61FDF386, 0x6E7E78AF, 0x0359AA64, 0x0AA7D5D5, 0x575394A3, 0x23737354, 0xE836F4FD, 0x13D00F81},
	{0x9B83438B, 0x654673AA, 0xA7E65892, 0x55207AA3, 0xCC4EFB46, 0xBE553903, 0xAAB8B08C, 0x097A2D53},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x1AA6EDC5, 0x3E0A9B06, 0x8E75BBF6, 0xF1D70649, 0x9A563CA5, 0xDB9FBB05, 0xBD0EA32E, 0x11693469},
	{0x4490775C, 0xA790C701, 0x12CC4679, 0x6588FDF5, 0x164EFF5C, 0xA5E4ADC6, 0x2274FBA6, 0x1F8B4CEA} } ,
	 { {0x062AB06C, 0x8D564D91, 0x1EE53975, 0x864ABA63, 0xB2D9D1C4, 0x66536F81, 0xCD78841E, 0x17C04762},
	{0x95621E58, 0xDA13F33A, 0xB54C6E81, 0x60C4F04F, 0xF364B1FB, 0x2F0EC8AC, 0x5F51CCA8, 0x0F8D9C47} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xAEAB6E34, 0x33045B02, 0xADC26999, 0x14639CE9, 0x718F6F56, 0x876C8750, 0x72A9B205, 0x2486E1CC},
	{0x99C03171, 0xD1F0CCC8, 0xFC61B334, 0x41B96808, 0xA9FC007D, 0x57316F54, 0xD6211636, 0x1062BECF} } ,
	 { {0x2607CB63, 0x821170A0, 0x84008C47, 0x4CCCC21B, 0x75DA24C5, 0xE948519E, 0xACE5DA30, 0x20864124},
	{0x96730F29, 0x6706576D, 0x488A96CB, 0xF7A77B30, 0xC85AEFD1, 0xBDE77FB5, 0x5C08E8BB, 0x1C57CD91} }  } ,
	 {  { {0x2AADE59F, 0x594E0384, 0x83FD5FFF, 0xA63D1943, 0xCEFCBC1F, 0x940CEF32, 0x217F6A7E, 0x19BBF53A},
	{0x550BE5FE, 0xAD008B8E, 0x6702F27A, 0x95F89A14, 0xF296019A, 0xB0F38298, 0x01183574, 0x0C249A36} } ,
	 { {0xA56BAF5F, 0x5DA7172E, 0x8087000D, 0x8651B96E, 0x458505BC, 0x519AE857, 0x68847409, 0x0B42342E},
	{0x8A5FCD21, 0xDFD75A68, 0x5D717063, 0x36916405, 0x5EC8440E, 0x5E56D474, 0x519BE7BD, 0x150C1D7F} }  } ,
	 {  { {0xA96B7627, 0x83297218, 0x99509429, 0xEEF25345, 0x80AE6104, 0x01EFB23E, 0xF8D24028, 0x127056E2},
	{0xC93388F6, 0x0C3CCF3D, 0xAF00D8BE, 0xDD0B127F, 0xD2ABF84F, 0x19819D39, 0x2DCFB2D5, 0x13DEA9F4} } ,
	 { {0x46223BDB, 0x0B82328D, 0xCA3F9031, 0x635BD60B, 0x25AC5907, 0x21BDE7A2, 0x138D38D4, 0x10ADEAD8},
	{0x7938B06F, 0x3BFC3679, 0xE99AC76A, 0xF5E8EC17, 0xAE545F59, 0xFE0914B1, 0x486F0092, 0x0650DA84} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 815 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 816 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 817 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 818 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 819 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 820 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 821 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 822 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 823 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 824 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 825 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 826 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x9EEA38CF, 0xBE5DE1B6, 0x01A067EB, 0xCE91CC54, 0x6587B637, 0x4B55CC78, 0x24E972CC, 0x180779E1},
	{0xDF708260, 0x37C6CCE1, 0xE3D62E72, 0x74D5E27C, 0xE72DB28E, 0x18D0E670, 0x20EDFAAD, 0x1798F484},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xDC8F0F73, 0x48998231, 0x2EB2A4C3, 0xB5260016, 0xA44548BD, 0x88054393, 0x16043852, 0x19C5999A},
	{0x35698D92, 0x3AFD7F77, 0xF65E8201, 0xCA07280A, 0x4EDB411E, 0x28E42A27, 0xF6003741, 0x0D445754} } ,
	 { {0x938DA817, 0x4A1F4FFB, 0x00AE906E, 0x26B9854E, 0xA39C9077, 0x790214A8, 0x8C2F8644, 0x0BF27AEB},
	{0x6DC381DD, 0x2D864765, 0x71FAD670, 0xDBB228AC, 0x177FAD44, 0xF7AC47BE, 0xD463AC1C, 0x1E8A7338} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xA4672475, 0x15C96A76, 0x0D5014EE, 0x78E5E99C, 0xDE3E1551, 0x213FF5EC, 0xA8EC71A2, 0x222226B4},
	{0x3602D27A, 0xDE6CA50E, 0x3AB47CFA, 0x50DDA13A, 0x2A0A6809, 0x5CF88D97, 0x3C82DFB8, 0x066CEA75},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x6FD21473, 0xD5CED777, 0xB82E626F, 0x74979F83, 0xC8071FD7, 0x1F9285C0, 0xCEDEE85B, 0x1E5C5A42},
	{0x941DA434, 0x480A70FA, 0x50D49C8E, 0x63D55450, 0x0A548A3A, 0x61C7CFD7, 0x6409F0B9, 0x0DFFB3D5} } ,
	 { {0xAB2619E2, 0x49E4B439, 0x315F261C, 0x93F70939, 0xDED664EE, 0x0F36C588, 0x507D668C, 0x1521FE52},
	{0x4347E877, 0x92CA0E7F, 0x091FF4BD, 0x6D14800D, 0xCE408059, 0x6EEC4BAF, 0xD160A368, 0x1AC04380} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB3CCEFB3, 0x1BF49C68, 0x66D9D560, 0x661F0D64, 0x6EE8F5AD, 0x1A4A959B, 0x83AF8296, 0x1B964516},
	{0xFBD54FC4, 0xC14F5171, 0x6F157882, 0xCF144BCA, 0xB60F7B51, 0xC6AD70DE, 0x9E7B986A, 0x0D043D86} } ,
	 { {0x902868A2, 0xC3040595, 0x0F77824C, 0x803DECDC, 0xB31C07B9, 0xBD4A63B8, 0xE307C9B5, 0x20D4A69E},
	{0xA2061677, 0x5747984F, 0x02775E06, 0x837E992B, 0xF733A430, 0x7A5B39C4, 0x944450DD, 0x0FDDA768} }  } ,
	 {  { {0xD315821C, 0x3211F824, 0xB7581638, 0x69233148, 0xC317092A, 0xBEEBFD5E, 0x677FDCE1, 0x018210FE},
	{0x3D7C0DD9, 0xA34BEA1F, 0x78324C4A, 0xD4C7D1DF, 0x48E98B3A, 0x64E04471, 0x6CC34305, 0x0D3FFD45} } ,
	 { {0x71AB42EF, 0x9E0CC439, 0x2661B271, 0x2AF37C04, 0x80FEE4D4, 0xF2CECBB5, 0x53CAF4F2, 0x0FBF17A6},
	{0xB7B4D0ED, 0x3D725FA5, 0x037FD5CB, 0x95E7EB5A, 0x1637CE24, 0x051FE0E3, 0xCCC20BDD, 0x1FD7D7A7} }  } ,
	 {  { {0x9C57F303, 0x95D2D9D6, 0x5CEAC205, 0x96B633FC, 0xB1F32185, 0x235BF7E8, 0x5CB772FC, 0x11834071},
	{0x307DAA1B, 0x70C4FAF2, 0x1A225474, 0x32CD9392, 0xBE9876A8, 0x559101C1, 0x6B723A7C, 0x152BF06E} } ,
	 { {0x5C6176C0, 0xC704E79B, 0x87B05A82, 0xAA20AE5C, 0xD259B9C0, 0x6BE33194, 0x26CE2DF6, 0x1D08D20E},
	{0xBFAAF591, 0x58A56AF6, 0x968DFB35, 0xF8B5DD23, 0x3AA8C964, 0x4380F6E4, 0x34855E5E, 0x186F6D33} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 827 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 828 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 829 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 830 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 831 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 832 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 833 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 834 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 835 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 836 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 837 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 838 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xA34BD2A3, 0xCF6FE0D0, 0x2DBDCA40, 0xF0F4F5A6, 0x6CAF4396, 0x9F859ECC, 0x379E0CB4, 0x16FC3389},
	{0x1265F600, 0xFFC4E205, 0x13E7009A, 0x65E04721, 0xF64948FD, 0xF5648AA9, 0x99B86C64, 0x1096C91A},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xE7F41279, 0xA482B606, 0x4C7FF9B1, 0xB6EC1A24, 0x75E78F37, 0xF7A57B0D, 0x6C2BBB70, 0x026EDB9D},
	{0x47641888, 0xF7B4C208, 0xA8144040, 0xC76972ED, 0x80B68B38, 0x965DE62C, 0x9CCB9371, 0x2392296F} } ,
	 { {0x7E41E3C2, 0x4D0BA5D1, 0xC761C4D9, 0x1EC56099, 0x1CE6C2B4, 0xF1CB0607, 0x1F0C04BA, 0x0192BF95},
	{0xBD22B4C3, 0xE645356F, 0x168F76E2, 0x7B641795, 0x17BE6F49, 0x223B4ACD, 0xF32C2105, 0x027A1A75} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x101C8D6A, 0xD300BFC9, 0xF0FFA33A, 0x163232AD, 0x11E07FD1, 0x0B24DB56, 0xABA65397, 0x1D6628BB},
	{0xD4F063FB, 0x0D6C91F5, 0x58384008, 0x7074FB7C, 0xCB884450, 0x1B8D7A45, 0xCEB841E0, 0x141BD8AB},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x72C61768, 0xE5308D5B, 0xF7AA5DC2, 0x7B920014, 0xB612F0F9, 0x53BF5513, 0x6C72895F, 0x07603B09},
	{0x8F5FBC42, 0xDACA4842, 0xCFCA0D0D, 0xE7FF608A, 0xDFE12946, 0x42E26B18, 0x457C5F35, 0x251CCA37} } ,
	 { {0x097B86D9, 0xFBB6D2D3, 0x141FB4C3, 0x850628D7, 0x088CCF49, 0x9AC60588, 0xEEC4F740, 0x13AEAE57},
	{0xE9CE0D88, 0xF563A501, 0xF8239115, 0x2BB66B49, 0x2023089D, 0x41B183AB, 0x34D12B5F, 0x16F66CF4} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x3ADE975C, 0xA39EEC64, 0x018CDB9E, 0x9CF3F5B0, 0xC8CB1E54, 0xAB7FF4B7, 0x33BCBCD9, 0x12AD3F3B},
	{0x682CF151, 0x4F61C928, 0xA2EAAC5D, 0x3ADAB665, 0x0B83B36C, 0xFD514850, 0x9FDC54BC, 0x050F5977} } ,
	 { {0xCAB799A5, 0x7D09F5C1, 0x67AAD224, 0x632C962B, 0x47183917, 0x298B4A8A, 0x24445440, 0x1D7665A8},
	{0x66468D69, 0xF23B50B4, 0xF586BF1D, 0x78849469, 0xA5474736, 0x05E18C05, 0x0E0F1B4E, 0x0E38B2F0} }  } ,
	 {  { {0xD59B2C82, 0x30A92255, 0x75F8A98F, 0x0CBE03E1, 0xCD9BFCC8, 0x80B94F42, 0x4E1C257F, 0x11E63E67},
	{0x84861061, 0x7B148E02, 0xC131A85A, 0x307DE8D0, 0x194B7E8F, 0xD79F2FD3, 0x85E913DF, 0x15121631} } ,
	 { {0x936FF3AD, 0xADFC21F6, 0x87C4F72F, 0x552E64D3, 0xB96A2549, 0x434F3643, 0x5016061B, 0x1D04F131},
	{0x09449290, 0x1921A315, 0xED9AC98F, 0x68DFE3D9, 0x0FF0A45B, 0xC80D5AA3, 0xD72F4282, 0x0CF62E56} }  } ,
	 {  { {0x60E80C13, 0x709BD3E1, 0x3F4BAC34, 0xA09981AF, 0x21F4E0F6, 0x006125D4, 0x1056C109, 0x0639CA4E},
	{0xC3DFC43D, 0xB29A5F86, 0xAF477805, 0x1BEBC84A, 0x69BD72B6, 0xE37E4A36, 0x2C7C24E8, 0x0D0A1406} } ,
	 { {0x3A9CD35C, 0x15E5F200, 0xD61ADCD0, 0x99FC0BA4, 0x8E9EFE75, 0xD22B5D99, 0xB612DA15, 0x1827796D},
	{0x1B61372F, 0x01756F78, 0x7FEC5DCF, 0xD817E495, 0xDCC67ACE, 0x2AF1BC64, 0x898F76C0, 0x21BD05E4} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 839 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 840 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 841 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 842 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 843 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 844 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 845 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 846 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 847 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 848 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 849 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 850 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x5C0211AC, 0x28834D57, 0x5CE8165F, 0xA356AFB5, 0xA4E38377, 0x4B981C87, 0x777905E4, 0x0758B067},
	{0xB8BFC876, 0x33F3EC44, 0xD6C7434E, 0xE650EAA5, 0xFB330C59, 0x896DD20F, 0x23E5B9E3, 0x0EF09926},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xD6C563FF, 0x3218B77D, 0x3BDF48F4, 0x76EFDA63, 0xCA5B6AEB, 0xE1ED490A, 0xE74C5545, 0x143E6F70},
	{0x784C334A, 0x18D92651, 0xBCE4E705, 0x8EE55BDE, 0x0A0AC0C9, 0x817268E4, 0x3AEF8C64, 0x201C5EC6} } ,
	 { {0x7C9394B3, 0x98B8C0E6, 0xC553405D, 0x8F3FAB09, 0xEDCDB9F5, 0xF21436D2, 0xDD4A8A83, 0x0BD0C059},
	{0x6644B0FD, 0x398E67CB, 0x486A8412, 0x59C3975B, 0xE8CAE526, 0xD26FBEC2, 0xE68738D3, 0x02622B96} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xBB7CC9E0, 0xBED84F0D, 0x604782AC, 0xD93BDF63, 0x95A285A3, 0x5EDAB33A, 0x64336179, 0x0EF0F3E6},
	{0xE2C922DD, 0x6CA4A980, 0x14AE3342, 0xE9D45516, 0x2DD84DBE, 0x0C541A8B, 0x0246CD26, 0x01019AFC},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x85730594, 0x38DAD94A, 0x29B10578, 0xF45ACB7C, 0xF44ECACD, 0x9D2E47ED, 0xB33ADB5B, 0x14AD5D20},
	{0xF2D2E77F, 0xBB70103F, 0x65582936, 0xC868A6F2, 0xB160444C, 0x1E50A252, 0xF09A367E, 0x0533E121} } ,
	 { {0x5AC0563B, 0xDF7D2EFB, 0xCB468540, 0x4FE29894, 0xE3BAF7E5, 0x8A9BF72B, 0xDAF1DEC7, 0x024AD04F},
	{0x6B1BCF47, 0x939E13FD, 0x0E33F005, 0xCE4FA9C1, 0xAD9A069B, 0x682858BB, 0xAAB97354, 0x1F79B7D3} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x12BED866, 0xCE5201EF, 0x9188F7B3, 0x9FBDA5C7, 0x66553A66, 0x386B2443, 0xC0685A0C, 0x0C7FD2EE},
	{0x80F3A353, 0x33D80258, 0x3539C122, 0x502699FD, 0x101F924B, 0x33556137, 0x2E4F481B, 0x16233CA9} } ,
	 { {0x9B364516, 0x3191CC9E, 0x1328A097, 0x0F809FE7, 0xE00974E1, 0x07F524ED, 0x29B510EE, 0x01110933},
	{0xB4734E98, 0xA012BBBA, 0xD3435C51, 0x1B9C1B77, 0x831FA290, 0x0DC30728, 0xA1C14496, 0x039ADC8C} }  } ,
	 {  { {0x381A188B, 0x28681576, 0xEE3935D1, 0x9FFD0D24, 0xC293512D, 0xC6AB9983, 0x25026627, 0x05AE4632},
	{0x825B08B6, 0xFFA21D2D, 0xAD381152, 0xA2C38262, 0xD04A3B07, 0x5C4FC46E, 0x8ED62281, 0x15218E28} } ,
	 { {0xAC2C2E27, 0x2056C501, 0xB6C17FD4, 0x4D24FC10, 0x14514B15, 0x72859C0E, 0xB5CA52A3, 0x14DF9220},
	{0x3035B4A5, 0x6C0B308F, 0x8B37153E, 0x98539F5C, 0x13BB71AC, 0x39B4111F, 0x0E2843C5, 0x1FA3CF40} }  } ,
	 {  { {0x41B0942B, 0x343B46BD, 0x82DC9643, 0x9EE2C9E1, 0xEC5FC462, 0xC6F71D8B, 0x0B0BD6C3, 0x039E9910},
	{0x80073321, 0x1AB69297, 0x9B98852D, 0x3550C098, 0x8B7E3403, 0x97DEC6E6, 0x3F55CA61, 0x229D3AD9} } ,
	 { {0x6865BC8E, 0x51A07F4C, 0x9313A36C, 0xB4189A67, 0xF8E428C2, 0xE776B140, 0xEE4E17D7, 0x085FD504},
	{0xCD991AA0, 0x17764FB8, 0xD14F7E25, 0x5A66305D, 0xBFB53514, 0x25FA26D8, 0x03AAC247, 0x186F4555} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 851 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 852 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 853 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 854 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 855 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 856 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 857 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 858 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 859 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 860 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 861 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 862 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x73C36B51, 0xF12AD6ED, 0xAD849F8E, 0x491ABF0B, 0x2029C2A7, 0x8E4955B9, 0xD6C73C90, 0x214F89DB},
	{0x7820DE7C, 0x15655CB7, 0x3C2F721F, 0xF453CBF3, 0x003587CF, 0x6133D39D, 0xC2D5F1AC, 0x0D52D177},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x6C5E5FD5, 0xCA2D1B44, 0xE9B54178, 0x06B23AAA, 0xCAE88D7B, 0x6D9FEBB1, 0xC5184819, 0x0D27F49F},
	{0xA9CD38CF, 0x8E40BCF7, 0x8B632821, 0xE3508E67, 0xE2D1620D, 0x09546FA6, 0xE4642AEF, 0x0F517B81} } ,
	 { {0xBA9CA265, 0x681CFF10, 0x37C0C17C, 0x118362AB, 0x8A497532, 0x6CB18E21, 0xC45C821B, 0x0EBC9FBE},
	{0xABE76666, 0x8257752B, 0xAEC4D59E, 0xE27C2CC2, 0xE92ECBC3, 0xAA69B39D, 0xC51281DC, 0x0054E3AC} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xAEBEE6CA, 0x763AC2AF, 0x4BE6A59A, 0xCB5D7CBF, 0xAEC6C40A, 0xD42404D1, 0xBCA8DE76, 0x1623B522},
	{0x865EA020, 0xE61B8373, 0x300FE84C, 0x3D48E8EE, 0xFDC61A44, 0x162285B3, 0x553CD42D, 0x1E3C2CDF},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xCC176CB6, 0x2C7C9F2E, 0xEF68C8F7, 0x08C65340, 0x70C8A4A9, 0x947D8497, 0x3268162D, 0x1D49D48E},
	{0xF92B4C20, 0x290DF4E1, 0x977DE66C, 0x806CED52, 0x32A40BA4, 0xE121B77A, 0xCC43BA5D, 0x02EDD2DF} } ,
	 { {0xE8A936F0, 0x2121C9CC, 0x970721B7, 0xC3F15B26, 0x0E6549DD, 0xE70E7757, 0xDA718237, 0x1C694C89},
	{0x7AFD4479, 0x5E631FB7, 0x08299914, 0x9239F463, 0x283687F1, 0x4D5AB62B, 0x1290741F, 0x10E2AD2E} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xBA777752, 0x7EB72169, 0xAF605B8D, 0x60537A50, 0xF99271D4, 0xA45503A4, 0x014BD256, 0x060080AA},
	{0xB63FF15C, 0x4C7007C4, 0x35B94D77, 0xA377EEB5, 0x3923E6E1, 0x237D8F79, 0x828586DF, 0x0DF2635A} } ,
	 { {0x777369A5, 0x16F3DA0B, 0xC7FCA72C, 0xBA3C8610, 0xA903EFE8, 0x44153737, 0x8A33C0E3, 0x177F6DA9},
	{0xFA191F56, 0x951B2D7D, 0x44B43168, 0xFC6D907A, 0xC8429444, 0xD8C348D7, 0x104D8D98, 0x23CB906F} }  } ,
	 {  { {0x2F775D12, 0xD72AEE29, 0x30424F04, 0x6EAADCAF, 0x473748C6, 0x4E6426F9, 0xBBE964A7, 0x1F32E565},
	{0x539532D0, 0x30C69E7A, 0x505640FE, 0x1CA1379B, 0xA0795D6A, 0xA76945D6, 0x4B74C353, 0x23EEE2A9} } ,
	 { {0xFCAEE4D3, 0xF184BC94, 0xDC47C7E8, 0xDA48878A, 0xA21B8FAB, 0x2D83C18E, 0x4FED4E03, 0x01044C3E},
	{0x3B46607F, 0x3A4A0210, 0xA327D628, 0xC215C97B, 0xCAE6FF3C, 0xDE1FBC20, 0xD062D62A, 0x02F926AE} }  } ,
	 {  { {0x3D127A8C, 0xC95D9F41, 0xDC8693D9, 0x0C0E5092, 0x5492531A, 0xB0D1D7BB, 0x3A921429, 0x10A707B3},
	{0xC40C65BE, 0x5B15CF2A, 0x28777EA4, 0x3C2D601D, 0xC4C5DED7, 0x05257DB3, 0xC622197E, 0x1AF6826C} } ,
	 { {0x0EFB2412, 0x3F5539B6, 0xF3CA6566, 0x98993187, 0xEFC46264, 0xFBA71AAA, 0xB00444BF, 0x0F10311C},
	{0xC6A50786, 0xED165BA6, 0x68B2290C, 0x827CD2FC, 0xB19D1A19, 0x943D614E, 0x7A9A4B47, 0x0089D2F2} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 863 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 864 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 865 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 866 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 867 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 868 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 869 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 870 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 871 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 872 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 873 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 874 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xDC164724, 0x8432D9C8, 0x2ED38191, 0x8D10BECE, 0xACE2C494, 0xFB0B2F27, 0x942A61AF, 0x14B85F56},
	{0xB2C179AE, 0xCA7032A7, 0x8D395A98, 0x69E371E8, 0x8AE6220C, 0x7C37F1CF, 0x908BC5E2, 0x0987B3BF},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x151CE8F5, 0x2E0D7302, 0x3682DBF5, 0xC5055095, 0x01C1D892, 0x61EB3632, 0x9AA553AF, 0x0775C613},
	{0x88A72CD1, 0x56A7A3B9, 0x8AEEFF48, 0xBE90DD2B, 0x94562B56, 0xEE8C5DE5, 0xA7132523, 0x204EB472} } ,
	 { {0xA13CDB4E, 0x202FE69C, 0x4239A328, 0x9518701C, 0x70D8A091, 0x8859D481, 0x2A8FB89C, 0x1DD18F11},
	{0xAB2E67A0, 0x282DAF52, 0x62770ECB, 0x2368B2E1, 0x3BB65FE5, 0xF6364E8E, 0x6B6FFD91, 0x1EF90A47} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xCF7B4471, 0x7CCFC894, 0x4FD9678A, 0x34B82E22, 0xFF5B02A1, 0x22D444AA, 0x9C88457F, 0x232EDF2B},
	{0x7B6EB361, 0xFCC82042, 0x719BF9DA, 0x78C6810B, 0x763F0C38, 0x9A86FF24, 0x47B98F22, 0x2441265D},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x15487959, 0x4B7DBB20, 0x4DAF4BC8, 0xFA40BCB6, 0xBA1F4159, 0x780AC7C6, 0xEA7B63CE, 0x02361D75},
	{0xE1D78B65, 0xE50C128E, 0x887EC0BB, 0x0DE8A667, 0xA13DE924, 0x7CEBDCD2, 0x679AB4B3, 0x0DE50395} } ,
	 { {0x09BE918C, 0xD524BE33, 0xB029E1E4, 0x74EDBA7C, 0xD00333EA, 0x79316342, 0xA138C938, 0x08A18A27},
	{0x4FD9C542, 0x03B39C78, 0x875EE88E, 0x16807F37, 0x6530267B, 0x7652A6E1, 0x6737B0BC, 0x2463A610} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x3FF5233E, 0xE0F73105, 0x40182D98, 0x4E4C5912, 0x1F949D3F, 0x95F3D955, 0xB2DCF0B9, 0x165BD75E},
	{0xCE67F1A9, 0x5C1C3F2A, 0x2E6B3583, 0xA3BE1D21, 0x4BDA6EB0, 0x67AE600A, 0x599CE528, 0x1B5C0D46} } ,
	 { {0x546809EF, 0xD78D6B67, 0x7B211367, 0x3FACC182, 0x0B5D4E09, 0x1142929E, 0xD5CD0314, 0x241A5B7C},
	{0xB5039A4B, 0x0E17C509, 0x20B5603A, 0xE1FD6CA0, 0x3135675E, 0x936F2F5A, 0x27F0D53F, 0x05E228DA} }  } ,
	 {  { {0x8DD4C406, 0x1B5FEB4F, 0x3BD6D2B7, 0x372ADD9D, 0xD7EC779C, 0x934464C4, 0x53B81E88, 0x0472A787},
	{0xA79CDA46, 0x359F0579, 0x3B73E509, 0xE0B66A6E, 0xF1F2F122, 0x0F4108E7, 0xE458E43F, 0x15894702} } ,
	 { {0x26F61C4C, 0x402AABA5, 0x1984734E, 0x508879B3, 0xF38FE07F, 0xCAF5324E, 0xB4CF7929, 0x0F243CA7},
	{0x9371A265, 0xA0310E87, 0x486BA81A, 0x4A8B0E65, 0x549EDF54, 0x48999B6E, 0x43BDBAA1, 0x1B8625F8} }  } ,
	 {  { {0x29D81F95, 0x2E477A14, 0xB0B8F6A7, 0xE0A74131, 0xDC9B5669, 0x591FFCF1, 0xF2DBA45A, 0x1E1CEB2C},
	{0x182C0C06, 0xD73712B1, 0xC2101DCA, 0xE5F2DD06, 0xAE7C41D5, 0x0AC4774C, 0xBD6E0811, 0x0935201F} } ,
	 { {0xAC8B661C, 0xAA893561, 0xC1CCD40C, 0xA53C2AD3, 0x89F686CE, 0xB4898E73, 0x9322D4D2, 0x1DD5C652},
	{0x9E63C800, 0x8668EBB4, 0xA213F6BC, 0x951470DF, 0xD3726CC8, 0xD8DB7577, 0xDA8B56BF, 0x064A4072} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 875 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 876 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 877 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 878 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 879 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 880 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 881 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 882 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 883 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 884 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 885 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 886 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xF16A497A, 0x098F66F6, 0xB7ADEC70, 0xD6562D49, 0xCCDAC7CA, 0x58FBBC40, 0xD9F22326, 0x138C6BA5},
	{0x918FD408, 0x4D21A836, 0xAC54479C, 0x00DCD410, 0xAE81D438, 0x17F65D5D, 0x8C213B92, 0x0A4A2DC9},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x8D5F1D2F, 0x1B7E61C7, 0xAEFAE04F, 0x0A80C244, 0x2CA89445, 0xA867CDD7, 0xD6B140DC, 0x0811CA52},
	{0x77B4D90A, 0x044A022B, 0x6DB9BD65, 0x594C5A83, 0x0594CE8E, 0x18E3F6E9, 0x36567FD4, 0x080AD73E} } ,
	 { {0xF72FE039, 0x391F9228, 0x2A3C4204, 0x98252C73, 0x02708717, 0x6360F2B1, 0x631BF037, 0x1D236967},
	{0x9B57A54D, 0x52F5B55A, 0x36B0A178, 0x2E132BCE, 0xFD177477, 0x075A1683, 0xAB02D24D, 0x162CCCFC} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x862BC2C4, 0x1286434A, 0x21C92C2D, 0xC963C7AA, 0x90A04BAD, 0xE2AA3E50, 0xD5724AAF, 0x085F08F0},
	{0x9D5E3387, 0xFD12322D, 0xDA008405, 0x0FBAF597, 0x5271547A, 0x8620DE58, 0x4D155556, 0x06A0B69B},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xC2541689, 0x15E7C38C, 0x78FDF76F, 0x9DF5C17D, 0x09B9669A, 0xB0B4EC15, 0x47F9E6D2, 0x17BE6C11},
	{0x7B4D1319, 0xE659B156, 0xA09A2894, 0x288B25B9, 0x49A1700B, 0x9C96564D, 0x04115219, 0x0E66389D} } ,
	 { {0x8D020A74, 0x079788AB, 0xD15E87C3, 0x351B5751, 0x24B289FE, 0x001DF140, 0xD689F6D4, 0x0DE34D57},
	{0x6E3EEC06, 0xE173FFE2, 0x9BB8E90E, 0xD2D6DC1B, 0x97E476B8, 0xD6884C2D, 0x05CFCE27, 0x14E61577} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF8C0FB35, 0x9C11BB51, 0x0F12010F, 0xF99BA6E0, 0xD0382FA8, 0x80A15FF8, 0x4EC875D4, 0x02B8AB86},
	{0x00ADF463, 0x2EE45A69, 0x611E3C0F, 0x13BED83B, 0x35BC4812, 0x3F8C6DD8, 0x64DD6997, 0x18648BFE} } ,
	 { {0x6FED9F6D, 0xE6825636, 0x762A3D3E, 0x89F2B428, 0x90880F06, 0xA82BCEF2, 0x4F0D8071, 0x206FFF4C},
	{0xA0F5F446, 0x8FB3F35C, 0xBBDACDB2, 0xFED2BE87, 0x8E935810, 0x8C3F6298, 0x15614B28, 0x228DCDFE} }  } ,
	 {  { {0xFF39AF87, 0xD53CF8A7, 0x5E2FB382, 0x7184F5AC, 0xC9133A73, 0xF9F2CC97, 0x002AA67E, 0x138D5C45},
	{0x04473A8F, 0xAB3782BF, 0x4A4584A1, 0xC377C20C, 0x2A439638, 0xA1F0013B, 0xA72521EF, 0x1B21F05A} } ,
	 { {0xD3EB2F18, 0x37CE58B3, 0x1BA3FF54, 0x6900FEAC, 0x22E9E435, 0x5947D1D6, 0x51179BC1, 0x0EBE6B24},
	{0x42E088A0, 0xE3448178, 0xDA57C2EF, 0x6C4B68BA, 0xBEC92FF3, 0xC1962375, 0x7FF05ABF, 0x233C8D23} }  } ,
	 {  { {0xB6E82A5D, 0x276E18F1, 0xA5C6115E, 0xFA302558, 0x5CA0DA65, 0x56CE5B05, 0x57C84924, 0x0EA730D7},
	{0xCDA05B52, 0x36AC1BC1, 0xEBD230DD, 0x46357602, 0x764D0EDB, 0x6305994A, 0x870883FE, 0x1B3D54CE} } ,
	 { {0xACB1A529, 0x0562939B, 0xAD8E8B2C, 0xAF4D21BF, 0x096CA87D, 0x992C218A, 0x4E0D4E49, 0x14DC678E},
	{0x5A028D18, 0xF9A1795B, 0xAE28009F, 0x80075726, 0x1168C956, 0x33D45B6D, 0x6A59F6E7, 0x09085F07} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 887 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 888 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 889 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 890 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 891 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 892 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 893 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 894 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 895 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 896 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 897 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 898 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x5E788EB3, 0xC44654E7, 0x085F81F2, 0xF40C5625, 0xF614C94C, 0x15EC4D11, 0x708F38A7, 0x046E1748},
	{0x49EBF88A, 0xF367A5CA, 0x084F4045, 0x7C8C4C63, 0x1BB61353, 0x3D906DE7, 0x04038100, 0x1DE7D4D4},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x56CBA5C5, 0xDC89486D, 0x7F7F4AD7, 0x0AAEBDB3, 0x836B816D, 0xF3AF20F6, 0x24A7EE28, 0x17A9F875},
	{0x8289D250, 0xC50013D8, 0xAADF1144, 0x5B5A0DD4, 0x6389DAA4, 0x06AC3DDA, 0xBAAF1C48, 0x1C8885E6} } ,
	 { {0x86236F72, 0xB53E3B98, 0x3E4C0E4B, 0x9A2F72C1, 0x8E054EDD, 0x98CAC9B4, 0xC1494091, 0x179FA9ED},
	{0x316F39CB, 0xD496A31D, 0xF410CFB1, 0x56A8F2CA, 0x84F90C6B, 0x15FD65AD, 0xD478A756, 0x0D0BD8AD} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x1D653760, 0x5E08597C, 0x21635301, 0x4D20A215, 0xC048889E, 0x9FBBC15D, 0x0418E721, 0x1D432329},
	{0x7CE031F8, 0x75DDD944, 0x22FAD161, 0xBF2DAB8A, 0xC534E6DC, 0x5DB0CF17, 0xD4A9A625, 0x1D44AE10},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x84414ADE, 0x688C079D, 0xF30CE2DA, 0x8241CE7A, 0x0877B83B, 0x68FDC4BF, 0x5DFCC260, 0x11CA109B},
	{0x289CFCB1, 0x5FCB092C, 0x3B115A9E, 0x7B9F9896, 0x8CA25E21, 0xB42440D8, 0xBBFD3E0B, 0x1BF7DA66} } ,
	 { {0x9326A266, 0xA10C791F, 0x5930E382, 0x963595BA, 0xC899E295, 0x111B5B8F, 0xFFF88C2C, 0x1CC602C9},
	{0xA6182D67, 0xC713159C, 0xBF454A05, 0xB628AE5B, 0xB6744A66, 0xA1FE16DE, 0x7F2ECE3B, 0x02AA9CFB} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xFE78A668, 0x094A9FF6, 0x01470D03, 0x667701F9, 0x1B28FE49, 0x4469D314, 0xE27EDFBE, 0x207EA5C2},
	{0x3E0BBC36, 0x33EE51ED, 0xFB1FB875, 0x1A9F7A33, 0xBAD661BA, 0x9B9B6920, 0xBE36F459, 0x1F86E096} } ,
	 { {0x6E280E06, 0x38844B17, 0xD260B841, 0x50178870, 0x56846B14, 0x354B5074, 0x765A78A1, 0x1CBC269C},
	{0xDB2FEC7E, 0xF2D0855B, 0x8FFC4296, 0xD1039294, 0x2972990A, 0x32C7C03B, 0x11F45ACB, 0x20E868A2} }  } ,
	 {  { {0x860FEEA8, 0x380D17B8, 0x809BBA5B, 0xF70B0A00, 0xB2058CD4, 0x468A7598, 0xECF882AE, 0x11EA1FCF},
	{0x126DFB45, 0x03DE1BD4, 0xD67D8A99, 0x943F221F, 0x3DEB7E68, 0xBB76E9B8, 0x08C2008B, 0x115F0E38} } ,
	 { {0x1389FC77, 0x37B20E0E, 0x1C276F5C, 0x590AD98A, 0xBE75032C, 0x3B81FD8E, 0xC8CDAF88, 0x0ABC1F38},
	{0x8C20A3F1, 0xD7EAB5F1, 0x716697B3, 0x3303CDCD, 0x3D519CCA, 0xA6F008C7, 0x7225E389, 0x0BD44386} }  } ,
	 {  { {0x549E6CD1, 0xF0B59417, 0xA682FB3E, 0xA28586B0, 0x42C40621, 0x945FA475, 0x4033426C, 0x0C881AAF},
	{0x1C7BE9F7, 0xD459AC24, 0xCB063FED, 0x23B9933E, 0x3E59EE1F, 0x654F3210, 0xDB466237, 0x0AFBD50F} } ,
	 { {0xEC8E1951, 0x95CEA5EA, 0x0901B545, 0x6C365974, 0x960FB41C, 0xE7270F2E, 0x4F68A63C, 0x18084F87},
	{0x61BA6F55, 0xCA93D5E6, 0x6ABB7F4F, 0x91D0A6A0, 0xC4AD5269, 0xE97E2003, 0x6542DCB9, 0x1546580C} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 899 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 900 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 901 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 902 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 903 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 904 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 905 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 906 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 907 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 908 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 909 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 910 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x171A530B, 0x981A0770, 0x0EA7985B, 0xA80F67CA, 0x44AE8A97, 0x60115E68, 0x31F033BA, 0x12C3AA86},
	{0xED373CDA, 0x4B50BB96, 0xCD240499, 0x375051CA, 0x5D8C221C, 0xEC1EEAD3, 0x0A0596E2, 0x0BC1827C},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF584C18B, 0x495803CB, 0x5657608E, 0x5F369D16, 0x10081EE2, 0xED01BE26, 0x283F9258, 0x1CD9DC17},
	{0xD1D80D02, 0xC8141324, 0xBC039B8C, 0x6288207D, 0xBB38AF8A, 0x82AD1783, 0x056BBAE9, 0x0EC18994} } ,
	 { {0xC460B563, 0x5C0427B2, 0x6160BC45, 0x3EB47265, 0x0746DA6A, 0x2BAAE1CD, 0x5DDA2CBF, 0x07FEAAA3},
	{0x10F005CB, 0x3CC01B0C, 0x64894593, 0x535B0FEA, 0xB3B63946, 0x93D8793C, 0x29356042, 0x04378C7E} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xD6ED9FC8, 0xE1923B5E, 0x6379596E, 0x0635AEC4, 0x8A355081, 0x949A457C, 0x5B2F6AA6, 0x021227EB},
	{0x31A8DE97, 0x35C272AA, 0x9468CE5E, 0x453FC7D6, 0xF3E22DF2, 0xCCBD0400, 0x4F2487E9, 0x011F7C2E},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xAC7148F2, 0x8EB5281A, 0x1AFEF12A, 0x9F018985, 0xAB87070E, 0x31051360, 0xC3A036A9, 0x0A71C8FA},
	{0x61F4866E, 0x2DC0828E, 0xDC706974, 0x8B341632, 0xB9A74564, 0x66D37718, 0x8D3E6919, 0x0F03EE6B} } ,
	 { {0xA647891A, 0x79A860DF, 0xAFD14ABE, 0x26C2286A, 0xC91A4351, 0x2B9265C9, 0xA9AB9C28, 0x01000095},
	{0xDBAA432C, 0x123CE52A, 0x68B39CAE, 0xD2DDEFF6, 0xA835ADFF, 0xF7A9AA3E, 0x8C5CF091, 0x1C85D8DA} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x981C4155, 0xDD60C1AF, 0xDABC941C, 0xB7FA9AA0, 0xB5917EF0, 0x3FF0A121, 0x9DC9BC8F, 0x1C74B4BD},
	{0xFA1C05D2, 0x4D32C886, 0x9328BBB1, 0x77F1D295, 0xFD86A1C7, 0x75E46A69, 0x0D7EFE2D, 0x0E3F5BB8} } ,
	 { {0x18AEB46D, 0xCF4616B9, 0xB8AC175A, 0x5D4A16EF, 0x9061322A, 0x38703C63, 0xBB8AB976, 0x1A494786},
	{0x1EA48314, 0xC522CDF6, 0xB66F63D5, 0xE85889B8, 0xBBB794AA, 0x043857F5, 0xF4B698D4, 0x0BF02953} }  } ,
	 {  { {0x1E3846CF, 0x6118C2D6, 0xEA1BA50A, 0xD12346AC, 0x4A5B81E8, 0xE2BF6217, 0x883D9DB4, 0x035934FC},
	{0x7CFBD3F5, 0x4CB32D69, 0x99F7F3EE, 0x7B20929B, 0x1DC3D588, 0x94FC6202, 0x5969DE84, 0x05371EE8} } ,
	 { {0xC14D1367, 0xB3C16D42, 0x2148B76F, 0xF4E723B1, 0x9495E2C8, 0x6BADE7CA, 0x3518F509, 0x151A177E},
	{0x13737966, 0xBEA1A062, 0xCA6578D9, 0x1B849F38, 0x34284E21, 0xD38248B5, 0xE97C9EFA, 0x1D5BFB3C} }  } ,
	 {  { {0xFD1C8F98, 0x5A76F3D2, 0x706A6809, 0xF6E56421, 0x55D464AC, 0x738F0A0F, 0x56FD5B15, 0x0D6EF4B3},
	{0xA0802D90, 0xD8D5B1E6, 0x10A92F09, 0x10637E47, 0xBB162A1E, 0xC753BD23, 0x357D7177, 0x1B318686} } ,
	 { {0x2FB21CF5, 0x94B528E9, 0xF7533CEA, 0xA5B25233, 0xF93CB95E, 0x370F9563, 0x0B6D1275, 0x16EECA47},
	{0xED91F680, 0x667592D0, 0x835EFB7F, 0x39173B43, 0xA78ED956, 0x3DDCF416, 0x3FDEA8D5, 0x1F38888B} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 911 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 912 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 913 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 914 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 915 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 916 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 917 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 918 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 919 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 920 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 921 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 922 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xC5BDC92F, 0x417BE0DA, 0x9ECD6840, 0x7B9C2DD3, 0xAD820AEA, 0xDE739B13, 0x1E3C7F68, 0x056F03DA},
	{0xC2B59933, 0xEBF2E62A, 0xBA3CC895, 0xB0BC2D8E, 0xCDC1D5F1, 0x7DF58C06, 0xED0CF8FD, 0x22049C7E},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x6C0DDC90, 0xA7433C0D, 0x2C265F74, 0x9889F7DE, 0xECA1FCD9, 0x9FAC290D, 0x379B000D, 0x06258873},
	{0x8C190FA5, 0x50F2DCDF, 0x10F2ABF2, 0xBB296501, 0x6EED46EF, 0xB0831D36, 0x0AA6AA16, 0x03EB0C6A} } ,
	 { {0xC74A93D8, 0x9106500D, 0x9D768BF4, 0xC7E58312, 0x9C21B6D9, 0x4B5AF69D, 0xF0E7D879, 0x221234ED},
	{0x6023BB75, 0xF4311895, 0x5EF22DC7, 0xCDDA629E, 0xA5383BA3, 0xB2F42D65, 0x655C8D4A, 0x07994BD4} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x5CBBECA2, 0xF8B281E4, 0x3D52A076, 0x374E00DD, 0xFB288968, 0x31BB2C9B, 0xB8C554BC, 0x06967AD6},
	{0x1A7923B8, 0x9AD7CFC0, 0x65B45A9C, 0xFFAF1B20, 0x2F2E1616, 0x3B6B5112, 0xCE31D410, 0x15DE74C7},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x8529C8CE, 0x1889D386, 0x2F679804, 0x5D8DBEA3, 0x0D284056, 0xCE51F2A8, 0xA426538A, 0x0F34E234},
	{0xBF743B5E, 0x82A22089, 0xE981648D, 0x8181F173, 0xFE8F2151, 0xA4EA8109, 0x46433B52, 0x08CA7348} } ,
	 { {0x3D31C064, 0x2F6F569A, 0x90932900, 0xF44068B8, 0xE42A828C, 0x1ABBF36D, 0x0FD78B43, 0x1F270802},
	{0xA04763F7, 0x0D671BC3, 0x9895120B, 0x6B055F59, 0x5FC9B695, 0xEDC6B141, 0xDAAB1A4E, 0x0E0B9700} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD23B76EE, 0xB7262E71, 0x608BB502, 0xA7A682BC, 0x42338A93, 0x6EAA3668, 0x43AEB734, 0x06B3F110},
	{0x536952C1, 0xD64E1471, 0x4A694658, 0x6C1CCBD3, 0xFBE870BB, 0xBA703C03, 0x5A6E5641, 0x0C10B029} } ,
	 { {0xCB205282, 0x90DB9CFF, 0x23908FBA, 0xC27EE75D, 0xDD68996E, 0xF1678261, 0x436A2680, 0x0564083A},
	{0xAA3E3A50, 0x52BB101A, 0x9CA582E5, 0xB0895AE2, 0x9F9398A3, 0xBB856AA6, 0xB0B013E8, 0x0CEE86A7} }  } ,
	 {  { {0xF7226317, 0xA095AB58, 0xB377FD17, 0x80DEF1FB, 0x662CD62A, 0x1154B149, 0x81842A92, 0x0DC98F58},
	{0xE6134F37, 0xE1F2B47B, 0xDBD6541E, 0xDF2BA9BC, 0xB755F56F, 0x693195C6, 0x2E81FB25, 0x2050CF38} } ,
	 { {0xCB1C5FCB, 0xD931F061, 0x1324473C, 0x0909D030, 0xF8ACD3FA, 0xA1D22A13, 0x6198337C, 0x17D25C2A},
	{0x246FC519, 0x1E379984, 0x2F04F599, 0xC8BBEE2F, 0x0AA6C512, 0xD2431C22, 0x8D3427A0, 0x151F1F6A} }  } ,
	 {  { {0x118DB054, 0x5A2F03E6, 0xD28EBDBF, 0xB8AACE60, 0xDB9E93E1, 0xEEDAFFA9, 0x66E7B217, 0x14975CD0},
	{0x19A78E79, 0x28D767D9, 0x1F87FB26, 0x2F17ABE3, 0xC54C9BAE, 0xDFC5D453, 0x4F5A9CF8, 0x0C1EC045} } ,
	 { {0xE6CE247D, 0x593D55F5, 0xB8761C5C, 0x1833F4D6, 0x0653944B, 0xC3687F77, 0x4854265D, 0x093DFD16},
	{0x8DFFF0D8, 0x0AA14DB9, 0x4DDE78ED, 0x5705BEF9, 0xECAFDD97, 0xFD25B46A, 0x9FE3882D, 0x2165BBDF} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 923 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 924 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 925 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 926 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 927 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 928 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 929 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 930 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 931 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 932 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 933 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 934 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x19785391, 0x7DFC6220, 0xEF005C84, 0xB67AF309, 0x48B6401B, 0xCBA14BCB, 0x84DEAD83, 0x21700134},
	{0x46FEE5B7, 0x7B54B66F, 0xF02B8626, 0xACB21D0B, 0x1B41D1D6, 0xC76EE4EE, 0xD384A0A3, 0x03507D4D},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x2008B7E5, 0xB8E557D2, 0xD61F96F8, 0xF40BE70C, 0x619FC98C, 0xC96EF746, 0x9713B35B, 0x177FC3EB},
	{0x156F293B, 0x07797020, 0x0665A826, 0x21F6AF5E, 0x1C7BD59B, 0xFB335A8D, 0xB459B0D8, 0x224B8917} } ,
	 { {0xF476D740, 0x28691A1E, 0x2171BFC2, 0xCD080E45, 0x8BFE71C6, 0xC28CE2E2, 0xAF8A62E4, 0x0B019E12},
	{0x214B3186, 0x3FA7827B, 0xB8E364F4, 0x73FB0864, 0x0D2179AC, 0x6D60B1AA, 0x5BA7E6F6, 0x13A53A05} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xF37C942C, 0xCF2B13B9, 0x51E2584A, 0xB164BF72, 0xE783957C, 0xA07760A3, 0xBDE05F52, 0x12C23E3E},
	{0x085F4CEB, 0x85994669, 0xB879E7B2, 0x0F2EC2C9, 0xF55D1B01, 0x0527CBCB, 0xD29DFAD1, 0x24A15147},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xBC52008D, 0x82DBB8F0, 0x18E7D4BF, 0x11C293C3, 0xBF5BF21B, 0x5B99364E, 0x248C5F9C, 0x00D7073D},
	{0x3BC3C24F, 0x97B43527, 0xFBA73F6D, 0x638E1EC6, 0x39B47413, 0x7A15104D, 0x709BB7F7, 0x0E397FC7} } ,
	 { {0xF1D6BE06, 0x77EB19C6, 0xCEA52244, 0xBC9714C2, 0x1F2B5AA4, 0x6269032F, 0xD34DEB5A, 0x0B2CD69B},
	{0x86FA851E, 0xEE26B0EF, 0xAA8EA758, 0xBCFE9858, 0x5AE9E4D4, 0xEBB958A2, 0xF835206A, 0x06105D80} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xAF8409F6, 0xFEF8DA8C, 0x01656D57, 0x4F1FBA93, 0x419E9F9B, 0xD88C7A87, 0xD3099227, 0x03B22470},
	{0x075C53CA, 0xA87C4654, 0x85AE8CA3, 0xB34EE0B2, 0x01645B91, 0x9C75F7A2, 0x53373230, 0x0055BD28} } ,
	 { {0xB7F56922, 0x06D0CCE3, 0xE7D80892, 0x80C2DCF8, 0x25A79CE6, 0x34EA4324, 0x930FD0CF, 0x0561721D},
	{0x298A3F66, 0x2D1AF104, 0x0ECD22CB, 0xC937D86C, 0xB7700702, 0x802BEF58, 0x4290AA26, 0x120D593D} }  } ,
	 {  { {0xF12E9501, 0x928FB5DE, 0xF182A499, 0x141BCBC9, 0xC5804B3C, 0x19B1DFAF, 0x6ED9C4E3, 0x0D9F3117},
	{0x70F1E9F1, 0x5EBE9192, 0x5EE5BA05, 0x5DF84C66, 0xE2BAFEF3, 0x92868969, 0x6BC4AC7B, 0x10ECBBB9} } ,
	 { {0x1090188E, 0xB9DEF6A5, 0xDD459377, 0x6FB73E08, 0xBC6D7AFA, 0x0614D613, 0x0EDA4C6B, 0x1864A09E},
	{0x40977B30, 0x42403859, 0x4C1B138D, 0x69D0F421, 0x6EB32335, 0x0A3FFA81, 0xB6E0BA0A, 0x11B7A785} }  } ,
	 {  { {0xCF03D892, 0x593E27E3, 0xF997934F, 0x9788FE6D, 0xC88C45EB, 0x636B6F26, 0x7359B042, 0x13E80084},
	{0x45C0A580, 0xA91693E1, 0x925A7DF4, 0x818DCF97, 0x0D4D705D, 0x7BBEE743, 0xA2E24632, 0x08B99631} } ,
	 { {0x82EC0646, 0xACAA0BA0, 0x1EC9650A, 0x0638D857, 0xD0922E16, 0xF9F1BDBE, 0x26584CB4, 0x181B436F},
	{0x1771AD16, 0xA420A3B1, 0x70C856F2, 0xC4F607FA, 0x45C8884B, 0x4739D735, 0x97D933A5, 0x0313F417} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 935 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 936 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 937 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 938 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 939 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 940 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 941 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 942 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 943 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 944 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 945 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 946 a211");
	}
#endif
#elif (BNCURVE == BN158)
#ifdef MONTGOMERY_ARITHMETIC
	{
		static const ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static const ecpoint_fp2 var_b = { { {0x7EF67F7E, 0xEB786BEB, 0xFA868838, 0x07AA5972, 0x08CEB873},
	{0x5B5E9933, 0x5461A237, 0xC890D90F, 0x0CE80187, 0x1F34E570} } ,
	 { {0x744E7891, 0x11FDCA56, 0x4B369FFE, 0x5DBDD859, 0x0C1E282B},
	{0x81C379E5, 0x8EE47E6F, 0xB0BBE950, 0xD019932D, 0x16C1019A} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xCB6E5CED, 0x9A6DA16A, 0xCE54D2D4, 0xF8371EFF, 0x055405F2},
	{0x3460B15E, 0x138185E5, 0xED26BB07, 0xAFA9A250, 0x10EDCD33} } ,
	 { {0x1669E6C6, 0xFA94E3D8, 0x519A0298, 0x4492134A, 0x0C0A8254},
	{0x36FB1DA8, 0x907F8C07, 0x27A1DCA7, 0xAB31B5C3, 0x06857EC7} }  } ,
	 {  { {0xD8DFC7F4, 0x5FDAD886, 0x8E3EE901, 0x60572E20, 0x10EBA1B1},
	{0x6A3CF12D, 0x032E50CA, 0x26AA561E, 0x9E8EEA81, 0x0F609AB3} } ,
	 { {0x1374F047, 0x81FBA9E1, 0x892890C2, 0x786DAC4B, 0x019CA8E1},
	{0xF77F1DF5, 0xC3880439, 0xB6B30F3D, 0x2BC25DBB, 0x0076E9A1} }  } ,
	 {  { {0x5F631F35, 0xBDCDFDE0, 0x341BEF18, 0x87E13863, 0x0C0447CA},
	{0x012C60F1, 0x2D180809, 0x463C8C35, 0x61786871, 0x07F53542} } ,
	 { {0xCD0DDDA9, 0x58880531, 0xE4067EB5, 0xE936A1EC, 0x08FBA75D},
	{0x2C8AE44B, 0x93787948, 0x139FE372, 0x904B0308, 0x1BB15D20} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 539 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 540 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 541 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 542 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 543 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 544 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 545 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 546 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 547 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 548 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 549 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 550 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x628292D8, 0xF16AA502, 0xCA5604F0, 0x7AB2DF31, 0x2009001D},
	{0xE9CDBF83, 0x2CC2AF9D, 0x6EF4BBAD, 0x34A37CB4, 0x03F81FE6},
	0};
		static const ecpoint_fp2 var_b = { { {0xEE4EFE3F, 0x3A409E98, 0x08F069CB, 0x7CB616CF, 0x07F6DC45},
	{0xBAEB2292, 0x05C6B853, 0x60D4DD6C, 0xEF06B458, 0x15DE4EE9} } ,
	 { {0x46B81F17, 0xD41429BF, 0x431C5942, 0x0A9937BC, 0x10D5B467},
	{0x46D88A9D, 0x12DDBBA0, 0xD24ADAD3, 0x305B58E6, 0x1E5970F9} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x03770EE1, 0x159C66AD, 0x80EB5D18, 0xBC263A32, 0x0626EF67},
	{0x22167B30, 0xA4611452, 0x7CB43E2F, 0xF1705D2D, 0x1507F233} } ,
	 { {0xA1EFB82C, 0x47022B7D, 0xB1A1A592, 0xEDAF166D, 0x23B34F6C},
	{0x07FDD97F, 0xE70364E0, 0x381F28B9, 0xD7970183, 0x10214198} }  } ,
	 {  { {0xA0074551, 0x2A27D377, 0x787CF04F, 0xE69CF5B5, 0x1F5BD340},
	{0x3F941805, 0x0C530369, 0xBD3C1B02, 0x56FA347D, 0x05179533} } ,
	 { {0xB25D7DD8, 0xB7B127D0, 0xB53C4A31, 0xBC0FEFA3, 0x12740FDB},
	{0x92E1A7D6, 0xF3A46573, 0x57C8CD22, 0x80987BC9, 0x18E346B3} }  } ,
	 {  { {0xC35EDDBA, 0xDAA93770, 0x11F0528C, 0xA0AC5AB5, 0x07055A27},
	{0x53EAB0F3, 0xF5717280, 0xE31079E9, 0x15B7041F, 0x13C5822A} } ,
	 { {0x6611876B, 0xBB4E9060, 0x642AD061, 0xCD397CDA, 0x08203352},
	{0x983CB462, 0x6D183A8F, 0xF0226D5A, 0xC3BF9F31, 0x1A9B8126} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 551 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 552 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 553 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 554 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 555 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 556 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 557 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 558 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 559 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 560 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 561 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 562 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x2084ADD2, 0xC977F07F, 0x3CF54622, 0xF3B7199C, 0x1AC5BF21},
	{0x85828F80, 0x4E91AE07, 0x6107471F, 0x76B08A99, 0x18BF9A6C},
	0};
		static const ecpoint_fp2 var_b = { { {0xECBCC292, 0xA01FB85D, 0x0E5B6C0A, 0xC2F391DF, 0x1D1A5F99},
	{0x729F1EFF, 0xC67FD060, 0xA3D23056, 0x14E17803, 0x07823440} } ,
	 { {0x4CD12B32, 0x8A2B7F3F, 0xA4D5364E, 0x7E832055, 0x06F211EB},
	{0x64DB363C, 0xC59711C4, 0x375420C9, 0x2BFC4F42, 0x1FB498BF} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x5AF72E6E, 0xA93120B3, 0xF1107A6E, 0x5C9A8B62, 0x0700070A},
	{0x4A7E7E14, 0xFABF0F87, 0x9EFF0431, 0x8779F304, 0x1655EB65} } ,
	 { {0x5EC6F8F0, 0xEA6C2E9B, 0x2E1E2354, 0x6958963F, 0x059C6210},
	{0xA52FC280, 0xD97C44B5, 0xB5463EBE, 0xF719742C, 0x12BFD530} }  } ,
	 {  { {0xC43D584B, 0x7E80A94C, 0x7AB516FC, 0xF6AB2E69, 0x08776EBB},
	{0xD9F5F682, 0x33494D52, 0xF924E6A2, 0x87F584C1, 0x1C3C51C7} } ,
	 { {0x4635FA3B, 0xA06F8397, 0xEF24F27D, 0xECEA2A56, 0x04FD5A0E},
	{0xC70EECF7, 0x399366E7, 0x681F7E7F, 0x3282F61F, 0x014ACD8B} }  } ,
	 {  { {0x437BC377, 0xC81F7151, 0xE1107D18, 0xB6A24F9B, 0x038C28F4},
	{0x5D04D8F2, 0xABB22D5C, 0x904832AE, 0xF311FC7D, 0x0FF27999} } ,
	 { {0x7A6A9D2C, 0x47AE16ED, 0xA88E1CF9, 0x88746BBF, 0x0F39ADC2},
	{0x028681E8, 0xED749EA5, 0xDCE3F4F7, 0x1601CC94, 0x0DF94AA5} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 563 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 564 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 565 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 566 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 567 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 568 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 569 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 570 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 571 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 572 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 573 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 574 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x29F297D0, 0xF0AD76BC, 0x5BDBAA23, 0x9CF5DE84, 0x21536281},
	{0x53062DF0, 0x1B427DB4, 0x0503073A, 0xCE064976, 0x13C595A9},
	0};
		static const ecpoint_fp2 var_b = { { {0x39C353FC, 0x239330DE, 0xAAAC47C4, 0x89C3EF0A, 0x1ACE4217},
	{0xEF7D1BFD, 0x29CEF585, 0xAE36D2DD, 0xC591D276, 0x07F0BE85} } ,
	 { {0xB7BEB976, 0x72EAE151, 0x7CC6CCB2, 0xC1E9A0DE, 0x131F9C19},
	{0x42D27155, 0x53BF78B3, 0xA9012549, 0x055CCC8A, 0x01AA9279} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x578F3247, 0x75F91162, 0x04AA7437, 0x89057F95, 0x1CC55869},
	{0x402AD4AC, 0x05294122, 0x71687DBB, 0xF7002210, 0x0F471082} } ,
	 { {0xA46B0D7D, 0xECB97469, 0x0134A377, 0xD9A6C2FF, 0x0FA09C17},
	{0xB83CC191, 0xE6AEFD38, 0xD9690956, 0xBFB00757, 0x1A00F77B} }  } ,
	 {  { {0x7CC64A74, 0xA7E625D3, 0x793AD9F3, 0xFEC235BB, 0x1C4CB27E},
	{0xC5930EC5, 0x1D72621C, 0x8CBB1F96, 0x97D5FE8C, 0x22EF23F7} } ,
	 { {0x644DDB97, 0x7C1D7993, 0x59CF847B, 0x52C9D60E, 0x145DA161},
	{0xFD66ADC8, 0x3193B7A3, 0xD7BADA90, 0xC5E2BF30, 0x07364EB9} }  } ,
	 {  { {0x46040F8C, 0xEE417D87, 0xD073312A, 0x89800308, 0x07956F82},
	{0x89F3A2AA, 0x8C6A529E, 0xFB3B200C, 0xE554400E, 0x150C7F81} } ,
	 { {0xBD35C992, 0x7BC39A30, 0x9CF34D82, 0x59F6149A, 0x15BD7CE9},
	{0x37D831FB, 0xA941F185, 0x278F4C35, 0x6B53B4D2, 0x01EFD02F} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 575 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 576 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 577 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 578 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 579 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 580 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 581 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 582 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 583 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 584 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 585 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 586 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xA55E9515, 0x809E362A, 0x8C799225, 0xA1D7B59C, 0x157C38E7},
	{0x079291FD, 0xF6D27392, 0xB334467C, 0xBFC1979C, 0x1B6280A5},
	0};
		static const ecpoint_fp2 var_b = { { {0xB3BB8EE4, 0x2FB819D2, 0x7714F32A, 0x8E953F90, 0x020D3616},
	{0x40F90454, 0xABFD531C, 0x6C170E4E, 0x66EF1DE9, 0x227F4C38} } ,
	 { {0xEE4967B5, 0x785C73B9, 0x94344348, 0x9A5CE1B2, 0x128F7DD7},
	{0xD3F92424, 0xFC78B693, 0x9027D91A, 0x605F5B63, 0x0A3A7004} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x214435C6, 0xFB4209AC, 0x01523D0D, 0x8731E243, 0x21BD17FD},
	{0xAB68C3EC, 0x971F6EBC, 0x63B41DD1, 0xA7722E79, 0x21451BAB} } ,
	 { {0x71225872, 0x69026066, 0xA5FDFABD, 0x4B612A9C, 0x10FBA9F0},
	{0x7ECB3505, 0x74B56CCF, 0x9BB33861, 0x76FDC819, 0x0AE296BB} }  } ,
	 {  { {0x0953570C, 0x9954A6D8, 0x8ACEBB62, 0xC886A26D, 0x07ED4A57},
	{0x22608BD5, 0x7AFA0261, 0x730F5EF2, 0xBBC3085B, 0x23B921E4} } ,
	 { {0x18CAB236, 0xAC35AB74, 0x16C8A74E, 0x146F0B55, 0x08A0DD63},
	{0xF3D3AC39, 0xDBD7DF74, 0xC93EDBC2, 0x6BE2137A, 0x2263D764} }  } ,
	 {  { {0xDE8237EF, 0xD683914E, 0xAFAA0091, 0x91B39908, 0x08F80DC6},
	{0x651ED814, 0xD33CD34D, 0x92A3FBB5, 0x65811EB8, 0x215F8D6C} } ,
	 { {0x1CB7B06A, 0x46832DC1, 0x0E6C150F, 0x2E20367A, 0x1627EEF1},
	{0x3DDC5B66, 0xB8D183F4, 0xBCD1D336, 0x9DAFACD3, 0x09FAB212} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 587 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 588 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 589 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 590 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 591 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 592 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 593 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 594 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 595 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 596 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 597 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 598 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xB280134C, 0x91FD26E6, 0xCAE1B44A, 0x3E1AB53E, 0x201E87D3},
	{0xAA9AA136, 0xBCCB6859, 0xFE4A3946, 0xFEEBF6A4, 0x052249E7},
	0};
		static const ecpoint_fp2 var_b = { { {0x9C6B8DEB, 0x7EBE0119, 0x0200C02B, 0x2DDE9C6B, 0x1B295404},
	{0x2A69385F, 0xF8A4CA7E, 0x646C49A9, 0xBBD12B90, 0x02FE630C} } ,
	 { {0x2C4E88EC, 0x8ED06945, 0xF5889BD2, 0x620E144E, 0x16830636},
	{0x457000BE, 0xABB84E26, 0xFF7F3F12, 0xB934F111, 0x153439B1} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xE5E72380, 0x9264908B, 0xFFB4B541, 0x4B05A8F2, 0x1CB26E21},
	{0x0326BD2F, 0x4D3F8A14, 0x348CBD7F, 0xBDD38F5F, 0x007914E8} } ,
	 { {0xBEE1FFDB, 0x31ECE3A5, 0x8D7031D3, 0x4E5DA161, 0x204814FF},
	{0x6206F4A2, 0x8B429A71, 0xED4C6E15, 0x9FAF6C4B, 0x04829952} }  } ,
	 {  { {0x1D03B550, 0x8EBA9A49, 0xF766C2AC, 0xCA606D27, 0x234ED395},
	{0x7FBE42BF, 0xAD9B0A75, 0x9713C41A, 0x7B95DFA6, 0x109E1250} } ,
	 { {0xB1E33DE6, 0x54428680, 0x692FC619, 0x0A5BC312, 0x23AB1C04},
	{0x0A2527FF, 0x834E34A1, 0x2F51DAA3, 0x27B8A6FE, 0x0FE0864A} }  } ,
	 {  { {0x6A95CA82, 0x9241BC28, 0xCCAE264D, 0x891BD6C5, 0x160C5EA0},
	{0x6B9EADB6, 0x7340E177, 0x03ABDF68, 0xE56B8247, 0x01B2AA1B} } ,
	 { {0xD7DFCE87, 0x05B6CE68, 0x772C5D33, 0xA33DD332, 0x018F8F57},
	{0x59FAB064, 0x2099001E, 0xB7FBC26E, 0x0897A86D, 0x080D180C} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 599 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 600 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 601 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 602 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 603 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 604 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 605 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 606 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 607 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 608 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 609 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 610 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x85CD06BC, 0x95A73D9F, 0x583157FC, 0xA3F44EEC, 0x15D95047},
	{0x7A6053A3, 0xE69284B1, 0x5C8805BA, 0x204E039A, 0x0181EC18},
	0};
		static const ecpoint_fp2 var_b = { { {0x96EA670D, 0x1E693FFB, 0x402DD2EA, 0x4BBBBCB7, 0x104DE310},
	{0x7CAE55C2, 0x93B98307, 0xFC385057, 0xE92AC98F, 0x19F5F58F} } ,
	 { {0x2A6B1D9A, 0x19F0E398, 0x642D4366, 0x5E3A3C12, 0x089DA126},
	{0x0A518811, 0x4199D665, 0x5A8D65C6, 0x0706A3F4, 0x09A8ABB1} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x6604643F, 0x9EEF2EF1, 0xAB7991CF, 0x10CAD102, 0x1E432744},
	{0xD20859A4, 0x4EECBEC6, 0xDD092E42, 0x60001D54, 0x01BD5177} } ,
	 { {0x7D8381BA, 0xDBD95B65, 0xEF6B00E8, 0x3B950371, 0x15737949},
	{0xD14CACCD, 0x5ECA8C59, 0xA6D0AF0E, 0x9C615AE6, 0x21AEDC25} }  } ,
	 {  { {0x47A45C1C, 0x02F9513F, 0x886DFB27, 0x8CE69EF6, 0x0C5F7708},
	{0x39E0AD67, 0x9D29DEDE, 0xE05FC4C8, 0x760F7BEC, 0x0E7A6210} } ,
	 { {0x2214B65B, 0x612872CD, 0x36DC1E53, 0x0B9790C5, 0x0B81EDF7},
	{0x57EBA6DE, 0xB436FFCB, 0x8BCB0D92, 0x89D08D69, 0x17DB2002} }  } ,
	 {  { {0xC7F5D251, 0x0E7146B7, 0x66717A86, 0x7D2AFA1C, 0x158E60E0},
	{0x260D880A, 0xF680D469, 0xCA19D858, 0x8A916733, 0x196AD5D1} } ,
	 { {0x4FBAEA51, 0x5D10F17B, 0xA5E37219, 0x4BDEC175, 0x1A8C2C31},
	{0xA3194656, 0x027C6922, 0x0B255F6B, 0x1ADC2A76, 0x00B340EA} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 611 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 612 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 613 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 614 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 615 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 616 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 617 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 618 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 619 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 620 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 621 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 622 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x02BAC655, 0x585A9C3F, 0x84BCC2D3, 0x06E49539, 0x114D9A85},
	{0xF08690A4, 0xFAC7CD5C, 0x02DEEE3F, 0x156223AC, 0x056DF778},
	0};
		static const ecpoint_fp2 var_b = { { {0x93473C2C, 0xFD02E566, 0xADA9A873, 0x194422EC, 0x0B8FBD8F},
	{0x35FD4842, 0xE5768034, 0xB5728049, 0x27D8AC98, 0x126B186F} } ,
	 { {0x849ED787, 0x672ECBC1, 0x927CAC5D, 0xC1CFA0A9, 0x1BA524D4},
	{0x0D5087C1, 0x33BE0FDE, 0x853C41A3, 0x07A9C0A0, 0x23B7923C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x99A94C45, 0x6A0FE707, 0xEC795494, 0xF1BBB3C2, 0x0A8A188B},
	{0x2AB82E20, 0x3BBC9766, 0x8EE9E724, 0xB179A598, 0x0AF34214} } ,
	 { {0x879929F8, 0x3856E97D, 0x622D1556, 0xB15C4FDC, 0x0BFAB597},
	{0x9324F787, 0x7FE2F990, 0x9F1651C1, 0xC5EBF244, 0x20C9FC60} }  } ,
	 {  { {0x8496427E, 0xB3CC3DF9, 0x76742223, 0x7CADEF19, 0x125CB05E},
	{0xFDD50358, 0x2DC3FDD2, 0x039E91A4, 0x3F9DE3AC, 0x0E18FCE3} } ,
	 { {0x1A8E49E6, 0xCC25509F, 0x2318D8AB, 0x00392ED5, 0x05C1B302},
	{0xCC1045FB, 0x27004F89, 0x6C304FCC, 0xEA7DBD1A, 0x163C787C} }  } ,
	 {  { {0x9482455B, 0xEA5A2CA8, 0x809F66DB, 0xA91EA8E5, 0x0EB1337B},
	{0xE735497D, 0x4D6C2AE3, 0xFA2DEDEC, 0x7CB00402, 0x186A5F3F} } ,
	 { {0xF4988F5D, 0x941FC83E, 0x0E76596B, 0xB6256B41, 0x098453C5},
	{0x029CB9F2, 0x3C0112BA, 0x156723D3, 0x0748A316, 0x23B58FE2} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 623 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 624 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 625 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 626 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 627 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 628 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 629 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 630 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 631 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 632 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 633 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 634 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x5AF6580D, 0xC079314E, 0xEC869B45, 0x320C672B, 0x07C35B9C},
	{0xA3C5C5D3, 0xF4EB00D5, 0xA15318D7, 0x80CD7C65, 0x13CB33B9},
	0};
		static const ecpoint_fp2 var_b = { { {0xCE3A2582, 0xAF43060A, 0xB796F253, 0xA4739447, 0x200A3E25},
	{0x546B838D, 0x2D2E07A6, 0x927E5DBC, 0xA4110A22, 0x074C70F4} } ,
	 { {0x7CD3DD03, 0x729AA711, 0xFFA5496F, 0x72A81DB3, 0x0E570236},
	{0x51109829, 0x028FAB4F, 0x4BF29D36, 0x0678B096, 0x2055BE7C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x765D750C, 0x42A89655, 0x2E8D813A, 0xBBFD828A, 0x0950E569},
	{0xE8711730, 0x5BD14B0D, 0x33032172, 0x816F9F9E, 0x06F61264} } ,
	 { {0x17EA435B, 0xAE83AB9C, 0xDF27F57D, 0xB90AFFF4, 0x1E8812A1},
	{0xDD63C6C9, 0xA490A25C, 0x912A9203, 0x69301AE9, 0x03C549EC} }  } ,
	 {  { {0x338FE2CC, 0x61E41977, 0x67F067B2, 0x4DC4A263, 0x1D979C66},
	{0x4A9267DB, 0x939B9C7D, 0x3BA19105, 0x61D21540, 0x10EBED47} } ,
	 { {0x207171F0, 0xB4791171, 0xF2400667, 0x95234981, 0x106836B0},
	{0x2322BDCB, 0xFF6687A4, 0xE874D501, 0xE332BEA7, 0x09A5028C} }  } ,
	 {  { {0xA6859FA2, 0x209106C9, 0xE511F504, 0xEBE6BD22, 0x16974760},
	{0x98B57EC3, 0xC189D01D, 0x5F00AC89, 0x105ADB4A, 0x10B59E07} } ,
	 { {0x2B0A09CF, 0xC4BCAC70, 0xE08D0801, 0xA8F6831C, 0x08CAF4C8},
	{0x8DD4B082, 0xA89BD460, 0xCFE60E8B, 0x5A8ADC7F, 0x1812D1F6} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 635 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 636 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 637 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 638 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 639 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 640 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 641 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 642 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 643 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 644 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 645 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 646 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x4B07D090, 0xC9B57FA5, 0x2540E544, 0x3DEB9092, 0x09843798},
	{0x7FA16E4B, 0x0564074D, 0xD1B28CCD, 0x77C9DCB5, 0x055FD6F1},
	0};
		static const ecpoint_fp2 var_b = { { {0x0EF06CA7, 0x6EC9F694, 0x5C6F4E7C, 0xD409701D, 0x09A81393},
	{0x7EF04BDE, 0xDBEC92AA, 0xABE51C50, 0xC5A02845, 0x15981879} } ,
	 { {0xAC0528CF, 0xD4137480, 0x7454F1EA, 0xBADE723E, 0x1422949A},
	{0x38A68470, 0xF88AB47D, 0x0F772C29, 0xAB7BF679, 0x1510152F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD1D8C513, 0x32657FD5, 0xB756D6BC, 0x144F6684, 0x0F326A5F},
	{0xB8FD6DB3, 0x27DF2EDF, 0x57E536BC, 0x0AFA52A1, 0x1CAB6C7A} } ,
	 { {0xD7B6BB3F, 0xB3E26305, 0x76ECF8DA, 0x64A49986, 0x1F525865},
	{0xC2337C14, 0x85943DA1, 0x6C21E720, 0xDB376750, 0x0F246152} }  } ,
	 {  { {0x2FB07C32, 0xF7B9C7B4, 0xF8D66633, 0xAFEA4929, 0x11ED9CE5},
	{0x69AA0D6B, 0x59CCA1BC, 0x36B29A67, 0xB763DDEC, 0x1762CBF6} } ,
	 { {0x213E5437, 0x4E40E514, 0x5B7AE361, 0xFC0F2B13, 0x0819388F},
	{0xAD936BAF, 0x964DDC8B, 0x0151AB87, 0x75EE9D43, 0x23A28D05} }  } ,
	 {  { {0x9AF929DD, 0x50AC4AF2, 0xDBE8794C, 0x40516EF0, 0x1D3BF1A6},
	{0x4887544B, 0xD591BDD3, 0x60CF9ADE, 0x2F70B997, 0x196C8096} } ,
	 { {0x27696417, 0xFFA61AE7, 0xEB0E8825, 0x00E59B30, 0x049C29E0},
	{0x7957B10C, 0x8DC80A7A, 0x0B83A4C0, 0xEB1C4C74, 0x06442E5D} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 647 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 648 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 649 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 650 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 651 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 652 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 653 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 654 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 655 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 656 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 657 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 658 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x46344057, 0x7C1FF02F, 0x59E00422, 0xC300EACB, 0x16A791EF},
	{0x55D186E7, 0x331B6FF2, 0x453C245B, 0x61254892, 0x19E5EB7C},
	0};
		static const ecpoint_fp2 var_b = { { {0x082C88F2, 0x99875EEC, 0xB0EF0809, 0x9893D7AE, 0x17956501},
	{0xB99ED339, 0xC9355CE3, 0x38852D9C, 0xBEFADA10, 0x20265BF2} } ,
	 { {0xB0E31660, 0x132835F6, 0x524051D1, 0x77199A82, 0x1B7A4B3D},
	{0x074043D4, 0x921A053B, 0x7E071AF4, 0x5ED0A913, 0x0421EDD6} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF5677D64, 0xA099FEA3, 0x77CECBB5, 0x672D5BB8, 0x0EBC0933},
	{0x9C43F44D, 0x8FD029EC, 0x314773AE, 0x3CA3D5BD, 0x1CD5533F} } ,
	 { {0x08B72844, 0xCEA34669, 0x2B5D0B5D, 0x9BDB412C, 0x13471BAA},
	{0xFD3BC233, 0x56412F5C, 0x16A6AB10, 0x397076AA, 0x1F789597} }  } ,
	 {  { {0x15681082, 0x21761E66, 0x24C338E1, 0xA6CC214D, 0x1997604E},
	{0x638AFF48, 0x781AA3FA, 0xACDA3346, 0x7DE46062, 0x178EC2BD} } ,
	 { {0xDBAB1713, 0xB39B3339, 0x060BD714, 0x70F4246D, 0x1F107A3A},
	{0x9FA21115, 0xA0313399, 0x048A8266, 0x6423B277, 0x14BF97B5} }  } ,
	 {  { {0x68373EAF, 0x684C19A6, 0x2616C0A9, 0xB078CD67, 0x1833AFE0},
	{0x4265D6B7, 0x76E9D279, 0x52FC5C88, 0x97B1F1E1, 0x0B506892} } ,
	 { {0x1A2CAE3D, 0x6E605078, 0x5CEF8746, 0x4C5152CA, 0x23A60DB0},
	{0x8F5851C3, 0xCD8AD4F2, 0xAD58ECFE, 0xC3665B19, 0x1B26267B} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 659 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 660 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 661 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 662 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 663 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 664 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 665 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 666 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 667 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 668 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 669 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 670 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x38B92F88, 0xFADB3E1F, 0x6E589111, 0xA81EAE77, 0x06664582},
	{0x9BF50038, 0x44AABBE4, 0xC203FEC1, 0x6CA362EE, 0x1B936EF8},
	0};
		static const ecpoint_fp2 var_b = { { {0xDF681BBD, 0x263C119B, 0x93B91424, 0xA4CE2E24, 0x240022C3},
	{0x64225D6F, 0x9674B10F, 0x4D2FE9F1, 0x46760470, 0x10FA5273} } ,
	 { {0xEF593833, 0xDA6CD9F7, 0x6DF70672, 0x3734ACCB, 0x146626DF},
	{0xE09B3203, 0x876A560F, 0xEFED56F3, 0x4A026735, 0x15F3A301} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xAA77B03E, 0x6E6A4B22, 0xA5117CAB, 0x53577F51, 0x0E187C9A},
	{0x39DB220C, 0x97B85002, 0x4622726F, 0xFCFC0120, 0x098257FC} } ,
	 { {0x2C950883, 0xB11B3D91, 0x28969516, 0x9E9EA6E1, 0x21433642},
	{0x6DCE26E7, 0x37C5862B, 0xB477D15F, 0x6ABB2CF3, 0x13573FFA} }  } ,
	 {  { {0xDC56CF85, 0x860EBDC2, 0x27EB34C5, 0xD974A2C0, 0x1668F4B5},
	{0x80817652, 0x1D5A23A4, 0x9673D5AC, 0x8F16321F, 0x133568CD} } ,
	 { {0xB05158EA, 0xD6F23235, 0xBEF363D2, 0x11BF9894, 0x1D434FAD},
	{0x45CA4459, 0xE6062CAA, 0xA5DDF205, 0x8D49F8E5, 0x06BA3336} }  } ,
	 {  { {0xC42B9706, 0x5E3C5A90, 0x1AE49838, 0x33AD364B, 0x004E63C2},
	{0xCAA17F51, 0xE8F1B68E, 0x4B0C9D35, 0x078FC7D9, 0x1BD51C80} } ,
	 { {0x67E0CC77, 0x3DA50B4C, 0xDC2B10BB, 0xBFE33229, 0x0581EB2F},
	{0xD60B03D0, 0x7937775D, 0xCC99C502, 0x974E0D3F, 0x02013571} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 671 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 672 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 673 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 674 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 675 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 676 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 677 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 678 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 679 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 680 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 681 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 682 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x48B9C183, 0xCE527F16, 0x40C35695, 0xC42B1326, 0x1FF12D62},
	{0x3614A412, 0xDAE14149, 0x4245E33F, 0x3479FC19, 0x1B643A10},
	0};
		static const ecpoint_fp2 var_b = { { {0x0E98AC76, 0x7573537C, 0xC2C24C58, 0xC0DB5239, 0x14822FF0},
	{0xF0D251BE, 0xFCBB711B, 0x44122294, 0xEA0E4D88, 0x1E95DD23} } ,
	 { {0x31C71E27, 0x10A25001, 0x85028E28, 0x44431E47, 0x0F3A827E},
	{0x7C793DBF, 0x7642844D, 0x1723FF5B, 0x71E8DDDB, 0x0D5BE2AB} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD4EE516E, 0x73085A3D, 0xDB32D887, 0xD436472E, 0x17AEC929},
	{0x8AA3D1E5, 0x96AC4501, 0x5B6A833B, 0x1FA858FF, 0x08A174A0} } ,
	 { {0x0BFBE750, 0xB3E683D7, 0xF39963DF, 0x8582BD27, 0x104DE9AD},
	{0xE458C54F, 0x9BA384DA, 0x55885D49, 0x0FAD76F8, 0x1689CA58} }  } ,
	 {  { {0x1DBA9BBD, 0x99A6FF82, 0x8F4FF221, 0xA7A35FCB, 0x0BC8F759},
	{0xBC3B889D, 0xDD72912A, 0xB0BB6B4E, 0x4CD24466, 0x1D3BA929} } ,
	 { {0x1F46CCBB, 0x99376937, 0xE8896DFC, 0x19DA9C76, 0x0B9DE0DC},
	{0x44184F1E, 0x5C8D718C, 0x6AD662D5, 0x44829777, 0x0CDA619E} }  } ,
	 {  { {0x2EA26229, 0x2D6450F1, 0x328E211E, 0xD3BDB39F, 0x204A8729},
	{0x7646A5AA, 0x412A21FA, 0x4733B788, 0x36082ACD, 0x217B0526} } ,
	 { {0x2237C7C5, 0x65A6FA01, 0x6D235C7D, 0x64A3B809, 0x1885AD92},
	{0xC9FBC475, 0xDFC59A93, 0x06B876B6, 0x6676A7CD, 0x117FCA9E} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 683 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 684 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 685 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 686 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 687 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 688 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 689 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 690 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 691 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 692 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 693 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 694 a211");
	}
	{
		static const ecpoint_fp var_a = {{0xC3C2A760, 0xEC2558A6, 0x7B0C5A3F, 0xDF922A4F, 0x216B9C11},
	{0x000EC492, 0x2E3A16FE, 0x7516C59D, 0x68DFF2A3, 0x1B75D52A},
	0};
		static const ecpoint_fp2 var_b = { { {0xFBE7F0EE, 0x9A3B3A4C, 0xC5704E84, 0x135CAFBE, 0x1C075E05},
	{0x347F391E, 0x708BDF5D, 0x56088822, 0x032FA669, 0x0B85EB1F} } ,
	 { {0x3A1B0B24, 0x179BC0BE, 0x60AC5A8C, 0xA6917F82, 0x0B081512},
	{0x5F0DCE4B, 0x7789A3B2, 0x26DEBD5D, 0xCCA8B47F, 0x1312E954} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xD1841F2B, 0x5F815FAB, 0x3DB6F1F5, 0xD625D078, 0x2113B551},
	{0xAE3F0345, 0x9E98EF40, 0x8976A27C, 0x267F3E45, 0x17413EA6} } ,
	 { {0x53FDD7CF, 0xA5B6BC4A, 0x5E551047, 0xB00E8918, 0x1AFD7C72},
	{0x7A85F453, 0xFC63FAC8, 0x004AFA4B, 0x6025AB25, 0x1274F0CD} }  } ,
	 {  { {0xC2D15775, 0x7A589561, 0xE658B6B4, 0x4FEF41AB, 0x1F0D3BD6},
	{0xFE5690CE, 0xF8856997, 0x7F1148C4, 0xF720A5D1, 0x097E316C} } ,
	 { {0x535A8557, 0x7B84964B, 0x6486A319, 0x990E5BC1, 0x1DB61273},
	{0xF5B8F0AE, 0x3332A57B, 0xD82FA890, 0xD4D7A828, 0x2128C259} }  } ,
	 {  { {0xE723DE5F, 0x20606EBA, 0x846E7B5D, 0x0165B049, 0x1855E657},
	{0x6EDF60A0, 0x4A8749FB, 0x7B731CA2, 0xA6551CD7, 0x1E44AD2F} } ,
	 { {0xBA1449DD, 0x19841F30, 0xF2F5138B, 0xE93D73B0, 0x005DF1FA},
	{0xAE62A21A, 0xCF8FA68B, 0x2DC04A52, 0x1CC189DA, 0x1430A3DD} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 695 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 696 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 697 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 698 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 699 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 700 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 701 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 702 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 703 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 704 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 705 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 706 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x51FA1454, 0x23952630, 0x4D8695A7, 0xE0CA52D9, 0x09CA0288},
	{0x9BB56204, 0x03D640BC, 0xBBA2141C, 0x75DB65B8, 0x0AB9957A},
	0};
		static const ecpoint_fp2 var_b = { { {0x854E5640, 0xB74B929A, 0xCE283863, 0xD0F5A8A1, 0x09BE4CB6},
	{0x6CEC72D3, 0xF103684A, 0x30EDFC3F, 0x42493E74, 0x0CDE1D41} } ,
	 { {0x18AACC56, 0x84AAD269, 0xC1860A49, 0x16FE1CB1, 0x235D3602},
	{0x24B6C8C6, 0x7AF6F705, 0x6338E85B, 0x22A94659, 0x0167FD08} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x6EF08DA8, 0x604F91DC, 0x440AA2D6, 0x79E66309, 0x1142A577},
	{0xC33E6648, 0xB23CDC6B, 0x79412B03, 0xE1104CBE, 0x1A61A455} } ,
	 { {0x31C87E30, 0x16A6A19F, 0x09319AEF, 0xA9A1C320, 0x0253809B},
	{0xAAAC990E, 0xC851D7A9, 0x95D6B830, 0x1F63F937, 0x1AE627CF} }  } ,
	 {  { {0x0A95A810, 0x50E1A828, 0x2367EBA9, 0xD473BF7E, 0x0C59ABDC},
	{0xCC466698, 0xAE68E3EA, 0xF1448B1A, 0x430DBCA6, 0x0C42C4F9} } ,
	 { {0x5C7114C2, 0x1F9C43B7, 0x66F23456, 0x9CD97285, 0x1CB16F90},
	{0x1066D0CE, 0x96570C3D, 0x7115DC21, 0x7EE3E3D1, 0x1407DC6F} }  } ,
	 {  { {0x556A77B2, 0x8213ADCE, 0xEBED5F22, 0x9B9FD35B, 0x1DD301A3},
	{0x9F7B2209, 0x4E5379FE, 0xC7AECD29, 0x2AFDA5AA, 0x0F26F1D9} } ,
	 { {0xB718687F, 0x121F6E89, 0x9D56D1CE, 0x38860DD0, 0x1C03ED8F},
	{0x4343DAF9, 0x1153DDA1, 0xEF1D663D, 0x8724FCD2, 0x1136148C} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 707 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 708 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 709 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 710 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 711 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 712 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 713 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 714 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 715 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 716 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 717 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 718 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x30B314C4, 0xE602EDFB, 0xB29033CB, 0x2DA7DD3F, 0x0BC59606},
	{0x1F6C45F6, 0x627D8AA3, 0xA05E2F9D, 0x18565A8E, 0x05F99986},
	0};
		static const ecpoint_fp2 var_b = { { {0xA76F1A95, 0x0FE7EDF3, 0xA6BF00CF, 0xE8768C8E, 0x0B0DB12A},
	{0xD7833797, 0x236C591B, 0xBAF303A1, 0xD3611247, 0x0F93A633} } ,
	 { {0x3D092E2E, 0xA61B2086, 0x1FC88D24, 0x7BFC7BFD, 0x0BC12568},
	{0xAF4A45DB, 0x87591489, 0xB00467FB, 0x0177FC9A, 0x0F042D9A} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x69ED4373, 0x750653B3, 0x52CD6A91, 0x9C5DC49C, 0x0CEDDE18},
	{0xFBD217B2, 0xAB02DE1B, 0xF0A2019C, 0x29111345, 0x01BE389E} } ,
	 { {0x51A27C23, 0x39B02A54, 0x3EC58162, 0xF42B253D, 0x0959C0CD},
	{0x4FC6307A, 0xF7EE5C21, 0x204DD069, 0xA52F36FD, 0x231DF19C} }  } ,
	 {  { {0x5FD4A9AB, 0x3231B95A, 0x2046DF24, 0xE0779501, 0x079A4801},
	{0x2EEC3C8B, 0x931E2E33, 0xEB96F49B, 0x82EE5D84, 0x166AFFD9} } ,
	 { {0x1A8978B3, 0x6CDE1A1F, 0x02E51FDB, 0xE133B0D1, 0x1306DE40},
	{0x609A0ABE, 0x8627BCF4, 0x615AFAA4, 0x705924F2, 0x00E1BA2C} }  } ,
	 {  { {0xEB1E35E7, 0x51071859, 0x0CFCD4E7, 0x9F7F20B9, 0x082AEBB5},
	{0x9B7A254F, 0x03C62E1E, 0x2A2BB951, 0xBCD42A20, 0x1E05396C} } ,
	 { {0xEC8E3764, 0x865A56CF, 0x0B5FBA63, 0xEE76753E, 0x1FEB3955},
	{0x2015B1F7, 0x9FF5AB05, 0x44229279, 0x003239FB, 0x098B19F3} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 719 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 720 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 721 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 722 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 723 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 724 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 725 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 726 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 727 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 728 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 729 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 730 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x38789B5E, 0x925C53D6, 0x0DE5ADE4, 0xCDAF98FB, 0x024A15B0},
	{0xB08111C7, 0x225B8B1E, 0x37E96776, 0xF4038A95, 0x167BE6C7},
	0};
		static const ecpoint_fp2 var_b = { { {0x2025F39B, 0x2AC91FC8, 0x5C6484F3, 0x54282F0E, 0x22E192B6},
	{0x659F8C00, 0x2232D71A, 0x24106F1D, 0x482598A8, 0x0C863EBE} } ,
	 { {0xB751EBAC, 0x9A4A3B78, 0x9565D88D, 0x0C9AE376, 0x112F2811},
	{0xD0DE6921, 0xA6C20FAD, 0xB88FB4C0, 0x283B7A4E, 0x231A90FC} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x97531D69, 0x7CCEFA0C, 0x12A5FE5F, 0x77114D44, 0x0B892333},
	{0x308CCD3F, 0xAE6D8C2B, 0x5E67D06F, 0x578DEF4B, 0x115E342A} } ,
	 { {0xE1ECD14C, 0xD8B545EA, 0x4DFB5563, 0x242091AC, 0x1381A926},
	{0x1A234F6F, 0xE651AE73, 0xE45748EB, 0x0D56ADAF, 0x14DE96F6} }  } ,
	 {  { {0xCAC674CD, 0x50270599, 0xC25D130B, 0xDF92E859, 0x017E05DD},
	{0x7341656F, 0xA1B32FB6, 0x33EB38B1, 0xE1017DF0, 0x121172D9} } ,
	 { {0x358C2557, 0x6F7C8577, 0x93169E06, 0x3383109D, 0x12EED9B2},
	{0x496E2F61, 0x93710462, 0x76827D47, 0x1BA10428, 0x172F8EDE} }  } ,
	 {  { {0x45D30F9F, 0x39DDAAE0, 0x3BEF1827, 0xA846DB03, 0x020B7633},
	{0x22810FC0, 0x9403C862, 0x8EDE61B7, 0x8899F00E, 0x08F7617F} } ,
	 { {0x2F19FE85, 0x61BBA486, 0x82AECB6B, 0x8DF47A3B, 0x232BFC0A},
	{0xCCDB252E, 0x09BA855C, 0xB8232D71, 0x15DE8AA3, 0x20C34BFA} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 731 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 732 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 733 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 734 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 735 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 736 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 737 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 738 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 739 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 740 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 741 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 742 a211");
	}
	{
		static const ecpoint_fp var_a = {{0x92F8EC1F, 0x14C6524D, 0xB50E5AF0, 0xB6FED0E6, 0x197DA09B},
	{0x1AD447F6, 0x63215D71, 0x4E45E1DF, 0x0EA5D662, 0x17CE11AB},
	0};
		static const ecpoint_fp2 var_b = { { {0xA9614702, 0x4347B68D, 0x49AE54E2, 0x7A4CA05F, 0x1D3483D9},
	{0xAF7330F8, 0x8FA577B9, 0x64F8536A, 0x9DBD4940, 0x12ED6694} } ,
	 { {0xC617DC90, 0x422FF6C0, 0xA2CED451, 0x11E4B664, 0x0316CA6F},
	{0xE5C2CA6A, 0xB440EE30, 0xA4B0DC9A, 0xEE200B4F, 0x205F6F0E} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x601A0E01, 0xA479CDE9, 0xF93C3CCF, 0x99ADA046, 0x0B9F785F},
	{0x1BE92B7A, 0xF5BF0368, 0x2B0882DC, 0x3C73697E, 0x15D9B688} } ,
	 { {0x183ABE5F, 0x7618BC3C, 0xC704B929, 0x62B0EC74, 0x18302669},
	{0xEEB5EC75, 0xCECE2293, 0x41555AC4, 0xF2CE4277, 0x116C19D0} }  } ,
	 {  { {0x42A2C9B2, 0x2416CE90, 0xB1B24A87, 0x5F422BC9, 0x12E3CDA1},
	{0x5D385B39, 0x1802E026, 0x73A74BAF, 0x29B44749, 0x20B06864} } ,
	 { {0xBC497931, 0xA1910398, 0xC7E10120, 0xB57D5D71, 0x1984F74E},
	{0xA80EDF70, 0x0A944B07, 0xC2E5D3C8, 0x7E8BC9A0, 0x0A9E3328} }  } ,
	 {  { {0x0C1A90B3, 0x56BCF15E, 0x18D2A3CD, 0x40FDD696, 0x15846744},
	{0xAECD0043, 0xA8BC7D83, 0xB8E04649, 0xFBA8A817, 0x19CE0BA6} } ,
	 { {0x42AF25A0, 0x80D9C65B, 0x59D8E064, 0xB57D2E05, 0x06910FE9},
	{0x468B2457, 0x8B0D8F97, 0xABB8D912, 0xD3560C08, 0x0BB3AAA7} }  }  } ;
		pbc_map_opt_ate(&var_res, &var_a, &var_b);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate 743 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate 744 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate 745 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate 746 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate 747 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate 748 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate 749 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate 750 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate 751 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate 752 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate 753 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate 754 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xE3690619, 0x690BAE3E, 0xFC7FBB2A, 0x69DDCF91, 0x1A73983E},
	{0x926ED06D, 0x3AA7BB07, 0xAD49B23B, 0xF999C4B1, 0x1EAE79B3},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xDD9B588F, 0x60F8F5B5, 0x39378A99, 0xAAAEF6F8, 0x13038021},
	{0x16480553, 0x36C86F0C, 0x535584B2, 0x041642A8, 0x1868A983} } ,
	 { {0xEEF9793D, 0x5A3FAB2D, 0x35A871A0, 0x899A51B2, 0x199EE35B},
	{0x6E5E1607, 0xFC042DEF, 0x03DD8975, 0x0FC57593, 0x05DC9072} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xCCB2A123, 0xBAFDA49A, 0xC0CFE377, 0x022AA316, 0x1E625D52},
	{0x71CBC5E7, 0x40255BB5, 0xF6910DC3, 0xB454EAFD, 0x09F3407F},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xE8AC9CBE, 0x6631AD5D, 0x80E8FA1D, 0xCF90B171, 0x22A042E6},
	{0x0FB0D02D, 0x22B67D5F, 0x5F36922E, 0x878A0987, 0x15EB16BC} } ,
	 { {0xEA0ED1C0, 0xF4EE20C1, 0x9D438D6E, 0x0DAB0585, 0x1ECEE419},
	{0xDB44C46B, 0xC24F1A2B, 0xC5C14E24, 0x1788CEA0, 0x1D862407} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x8543EE95, 0x78B3134C, 0xBA518F2C, 0x6EC15BAF, 0x16A93694},
	{0xC44D9339, 0x4CA5567B, 0x45824F9D, 0xC6870F51, 0x0002E274} } ,
	 { {0x3B4097D7, 0x21E10FFB, 0xF942BE7C, 0xCC8F090F, 0x23B68BEE},
	{0x5E0B395A, 0xFE584A09, 0x257E2234, 0xBFBB0A43, 0x159017C8} }  } ,
	 {  { {0xC4E4F6DC, 0xBCC9C6A3, 0x770A84DD, 0x607F877F, 0x1F29FD6D},
	{0xE4230689, 0xD304A4D7, 0x6BB7F9EF, 0x6A19CC9C, 0x1948A2FB} } ,
	 { {0x3927F099, 0x6A18E836, 0x10F6958F, 0xAD9C34BB, 0x1E8A9127},
	{0x1718B083, 0x4B4ACF17, 0x97DE787D, 0x010E641D, 0x066446E6} }  } ,
	 {  { {0x11958FAD, 0xF27EB97D, 0x8F9282E1, 0x7348A8C2, 0x01C8FAEB},
	{0x44A590B1, 0x5C6D1210, 0x78670D67, 0x57709F21, 0x21ED62F0} } ,
	 { {0x9E91A4A0, 0x2E669921, 0xAAEF5CC8, 0x45635B70, 0x0D8ACD67},
	{0x72032466, 0xB2F7109D, 0x6E2D7776, 0x62A4734C, 0x1D367C7F} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 755 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 756 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 757 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 758 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 759 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 760 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 761 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 762 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 763 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 764 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 765 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 766 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xF8CE70C4, 0x86A1FA27, 0xC4E8DF03, 0xF1BB9EE2, 0x03E1B872},
	{0x1436FA36, 0x415F2073, 0x00679B17, 0x5DFBB01E, 0x17E58680},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xC839A9A6, 0x6D9EBFAE, 0x000C47D2, 0x4ED05AC6, 0x03A3102E},
	{0x7ABC7757, 0x8BFF3261, 0xC9C2526D, 0x071852E3, 0x1CF728D5} } ,
	 { {0x554B34F6, 0x7106EB70, 0x3B9C9B1B, 0x3779DF99, 0x13D1CEEC},
	{0x87DDD0D6, 0x1AB466CE, 0x08303B33, 0x90BF28EE, 0x0CB44E8B} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x747CBE7B, 0x945FFD13, 0x46857923, 0xD251A7B2, 0x0178741E},
	{0x5FA75B2D, 0x32AE87A8, 0x092C0440, 0x5B7C4BE7, 0x1958E6C8},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xF924F132, 0x36F493F2, 0x753202A3, 0x95DB6E60, 0x2373B518},
	{0x3F1D64C3, 0xAB384870, 0xA37C7BB6, 0x6EEA5994, 0x00073B39} } ,
	 { {0x99C1D4C0, 0x5077C51B, 0xEBCA4169, 0x888A5A49, 0x1F40DC0B},
	{0x0E0AD879, 0x72DDB545, 0x3E115E79, 0xC9B70016, 0x04510F6F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x4C674634, 0x2892BA06, 0x46703482, 0xFE407CB4, 0x11F270AB},
	{0xE9A4A4B9, 0xAF122BE9, 0xCF0BE5B2, 0x3DB3ED81, 0x0CED14E0} } ,
	 { {0x3ADDE1BF, 0xC8DB6D2E, 0xD971122F, 0x3502A7E7, 0x0EEB4FDE},
	{0x660A4ACE, 0xED2F7B8F, 0x54C868E9, 0x7730E711, 0x10BFE1DC} }  } ,
	 {  { {0x561B2FB3, 0x0480C7EF, 0x78D61EC5, 0x97CF3105, 0x052A6587},
	{0x141FEC35, 0x1764C0D8, 0x521BE4B5, 0xD3FE6F85, 0x12806338} } ,
	 { {0x38B35B0C, 0xDF33295C, 0xD6F689A1, 0x987E085F, 0x212D01D3},
	{0xC8C2E261, 0xD4C95921, 0xC8A826A4, 0xF35AE8BB, 0x0468DE33} }  } ,
	 {  { {0xEF4356DB, 0xD3A7A6DF, 0x5C0686CA, 0x70D0C575, 0x1CC75CC8},
	{0x139763C2, 0x39D80F1B, 0xB53AEC8D, 0x527EB293, 0x0E9700AA} } ,
	 { {0xE15735FE, 0xDB1A0662, 0x6902F7B4, 0x7344ABEC, 0x1CC6C999},
	{0x40C4AC4D, 0x3CF3CF3F, 0x82F81ADB, 0x710E16BF, 0x085CC53A} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 767 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 768 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 769 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 770 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 771 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 772 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 773 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 774 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 775 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 776 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 777 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 778 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x835C45EA, 0x9644E2DB, 0xCA6E57DD, 0xB7588E55, 0x2125018A},
	{0xE81347B5, 0x792EBE3B, 0x4AE3FACC, 0xB4032EB4, 0x1D0AAB9E},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x7873C245, 0x728B3F6D, 0x44FA07AB, 0xAE35EC3A, 0x0ED9993D},
	{0x94673E9A, 0xF05A1E21, 0x81E813CA, 0xD33B71BB, 0x0010D7CA} } ,
	 { {0xB6487478, 0x9B6DB8BA, 0x37D9E863, 0x66D37A5C, 0x15811DC4},
	{0xA0229A76, 0xFD4DD9C0, 0xFEC5D4DE, 0x3CD7C00E, 0x21A8C48C} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xDF1AE558, 0x597B0FEC, 0xEEF357EC, 0x927F3947, 0x19B99B40},
	{0x562D64C8, 0xFF29D9E9, 0x9D36424B, 0x5966083A, 0x1795847F},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x5EAEBFB0, 0x646E9A13, 0xB61FCDF8, 0x7BFFB42B, 0x11EE4A53},
	{0x984FECF7, 0x72486FDE, 0xE3995A43, 0x840199DE, 0x1C640CB5} } ,
	 { {0xE3DCE7AA, 0x3956DAA4, 0x93A5A002, 0x22B07D08, 0x2270DE77},
	{0x157BD004, 0x8E429503, 0xF2CC705E, 0x6F826E7D, 0x1A7AEB68} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xF86CF1A5, 0x5F748E28, 0xFF34C0EB, 0x7EA9EB73, 0x0642D3EC},
	{0xE1EB5D2D, 0x3F5B7AEA, 0x455D5996, 0x741E1282, 0x20F3AE31} } ,
	 { {0xD6CFA2A0, 0x2E84DC0E, 0x93D8AC6A, 0x372E6AA9, 0x1313AD01},
	{0x856DA35D, 0x07550921, 0xD7AEBA93, 0xAE1CFE6D, 0x15BCFD42} }  } ,
	 {  { {0x11CF30FC, 0x6A429615, 0x2851FB4C, 0x8B3B6CAD, 0x0DF723C0},
	{0x11875A90, 0x15E3BC4B, 0x34E57DDD, 0xC9A4285D, 0x0DB4325A} } ,
	 { {0xB9A2EB6E, 0x7353B544, 0x8B3DF96E, 0x25ADFC6C, 0x0FFCCDEA},
	{0xE5F9FF45, 0x61A9A3AE, 0x050BB70D, 0x866B6A73, 0x058B2D48} }  } ,
	 {  { {0x0E665866, 0x6D5CE70E, 0xFF1A08E0, 0x73AD4353, 0x1394FEE1},
	{0x97B90566, 0xE1E80D23, 0xF436CA0E, 0xE0AE8862, 0x01DDCE3F} } ,
	 { {0x894C75DB, 0xEA97003A, 0x34DA41EC, 0xF21BC42F, 0x0B41BA8F},
	{0x65229D1A, 0x0621DD59, 0x62C4F17A, 0xB06F65F5, 0x09AEE3EE} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 779 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 780 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 781 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 782 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 783 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 784 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 785 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 786 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 787 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 788 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 789 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 790 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x9C56C272, 0x372176E5, 0x34AB59A5, 0xED27F592, 0x1E5C5130},
	{0x1FF1541D, 0xAA1C8A10, 0x518FB25B, 0x0F5E5615, 0x0A8383E2},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xA981A775, 0x924DC698, 0x792940E1, 0xEC17AEE0, 0x012C427F},
	{0x76377DA5, 0x193901FE, 0xA90CF235, 0x58A66067, 0x1776D4F3} } ,
	 { {0xE4247955, 0xE5746CCC, 0xECC787DF, 0xA47EB97B, 0x00157C3D},
	{0x2CE9662A, 0x334DCF5E, 0x636C129D, 0x3B530E57, 0x1E5EC6E2} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x5E14CD0F, 0xB634F348, 0xE43B16B1, 0x121CDB35, 0x193B920F},
	{0x0810406A, 0x56045291, 0x48D3ADAA, 0xA251C600, 0x1CD5AB5B},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xE2C3D11B, 0xA63C8022, 0x3587877F, 0x551E683E, 0x07A91F0F},
	{0xC5D24AB8, 0xA440982A, 0xBEAA8B3F, 0x7C186240, 0x059618E5} } ,
	 { {0x20965C02, 0x14A71657, 0x17DBF6B2, 0x1FE05245, 0x0B4BEDBD},
	{0x93FC07CD, 0x6D8DBC26, 0x03D6420A, 0xF1E9C734, 0x22047E14} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x9F666002, 0xFE1829E4, 0xB2A3582A, 0x8F0E2D83, 0x09A13ED0},
	{0x4DBC601B, 0xBCA48710, 0x7D3FE9BF, 0xC2B21071, 0x0B6D3ED1} } ,
	 { {0xA6709BB1, 0xC7038E10, 0x485EAA42, 0x25CC8BB7, 0x1F8ECDAE},
	{0xDC434227, 0x702C1A55, 0xC9862539, 0x0090AB57, 0x13BC8202} }  } ,
	 {  { {0xE59630EF, 0x4B34EB75, 0xAFF9A759, 0x4350E250, 0x18C54E4E},
	{0xB40AFC73, 0x2D143044, 0x6BB57CC4, 0xFF4040EB, 0x17DEFA6E} } ,
	 { {0x2F101C30, 0x323A4615, 0xD7389AFA, 0x9947A1F4, 0x1776694C},
	{0x22DECF04, 0x1439F7BC, 0xFE969BDB, 0x57EF9531, 0x1B157F32} }  } ,
	 {  { {0x6CAFAC2C, 0xE6397C80, 0x6ACC4C0D, 0x4CFC5996, 0x1CDDF165},
	{0x2B81A165, 0x4A6C8FEF, 0xD11EEA18, 0xC5481202, 0x0785DAE0} } ,
	 { {0x8A30F70B, 0x755F963A, 0xCD2AE256, 0x7DAF9D4E, 0x1D9A9C10},
	{0x162AE8B4, 0x6662A90E, 0x82AA41D7, 0xD4734551, 0x1B35189D} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 791 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 792 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 793 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 794 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 795 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 796 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 797 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 798 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 799 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 800 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 801 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 802 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xBA4A09FD, 0x12236807, 0xE227ED71, 0x8D37C8D7, 0x23E25DC7},
	{0x634ABC1F, 0x88DD4D5A, 0x740B27EB, 0xBD362B2F, 0x11E2FD06},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xC69E9EC5, 0xB7D72D58, 0xC799EEA7, 0x85FF42F6, 0x1D037C0B},
	{0xA540CFB1, 0xACC55DCB, 0x6F2C7837, 0x1D299743, 0x1FF5754A} } ,
	 { {0xDC878842, 0xF0B0656B, 0xD623E99E, 0xBA557E1D, 0x13DEAF7B},
	{0x2521C5D2, 0x4133003F, 0xC2B20A4C, 0x4E633ADA, 0x17F7509A} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x1D62D796, 0xB763A5B1, 0xE6581843, 0xAB824540, 0x1D08C2A0},
	{0x665C5881, 0x8EC817E7, 0x058BEAB3, 0xCFB85858, 0x124D498B},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x959D1886, 0x24C6ED0C, 0x3863AD75, 0x11D08EFC, 0x16E25632},
	{0x45C36AC1, 0x5C2096E0, 0x76922A48, 0x0311D7F3, 0x124AF500} } ,
	 { {0xD6035C07, 0xD1ADF380, 0x35F89643, 0x910727C4, 0x05E69F54},
	{0x0119E7AE, 0xD0130892, 0x3E900E7B, 0x2F303E69, 0x021BF49D} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xCE86DEF3, 0x657BF423, 0x6B263693, 0xFB248ED8, 0x02D50C13},
	{0xC7509A1F, 0x98E8FDCC, 0x6E6107F1, 0x4FD489EF, 0x0E3144EC} } ,
	 { {0xFD1C7BD8, 0x6183A07A, 0x548EAA4A, 0xCB9AA2C5, 0x0C2DFB62},
	{0x7DF3C7B3, 0x16F55537, 0xDAE74F27, 0x0ED9711B, 0x19B565C1} }  } ,
	 {  { {0xD69FA01D, 0x5D69B2BA, 0x6E79EEFE, 0x4C37B8ED, 0x15F11BF0},
	{0x6270B6EE, 0x8F31BED0, 0xCDB20DAE, 0x992F5460, 0x188D2544} } ,
	 { {0xB0516845, 0x0E0B76F2, 0x28D08305, 0xDD5F4612, 0x0AC4A15B},
	{0xE31569CA, 0xDF8932EF, 0x05F492A8, 0x326E027F, 0x0EB70A84} }  } ,
	 {  { {0xE3E6B4D4, 0xCD3AC51C, 0xC77E1BA3, 0x5A5374FB, 0x0CB95B76},
	{0x01484115, 0x060CD07A, 0xB68CE0A6, 0xD459D054, 0x0D6A7306} } ,
	 { {0xA6D9BB2D, 0x77A85A31, 0x18373854, 0x55872E90, 0x16CD2670},
	{0xAE2261FB, 0x8EEF3A43, 0x4F00D560, 0x95A97505, 0x1619ECAF} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 803 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 804 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 805 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 806 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 807 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 808 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 809 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 810 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 811 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 812 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 813 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 814 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xDC83E8C7, 0x7F3790F7, 0x9F70FD14, 0x7FE9747E, 0x086F4F2F},
	{0xB118B719, 0x9CCF737F, 0x5D206B5F, 0xB6A26261, 0x14F9CFE2},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF7A52BD1, 0x59CDEBA2, 0x46F2D764, 0xFD0CE601, 0x0E76DDDF},
	{0x82326B2E, 0xF62E3B91, 0xA5111A94, 0x7E7301B9, 0x1C8FD369} } ,
	 { {0xAD5BE2F6, 0x8C1B4B95, 0x30E49D51, 0xE06C7B8F, 0x0DA89D2D},
	{0x70558391, 0x74A0F2A6, 0x4537B8B4, 0xCB90B720, 0x1952219C} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x438C074A, 0x1AD8495C, 0x7BAEC778, 0xAAB36365, 0x180374DC},
	{0xEC13D4C1, 0xEF54F83D, 0x519D5AF2, 0xBD2E474C, 0x077F1D79},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x66D40E4D, 0xDFED3777, 0x498D60BC, 0x3510739A, 0x207C741C},
	{0xC39B5031, 0xCF50BBBF, 0xF3A6246D, 0x856165E7, 0x034A2E1E} } ,
	 { {0x1B2CE935, 0x972FA015, 0xAB9D0530, 0xA31E1A0A, 0x138FB210},
	{0xB3805C09, 0x389D26CC, 0xD4A7C442, 0xF3E59F42, 0x10212043} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x33E587B5, 0xAC46C3BF, 0x576D4ABD, 0xC8512566, 0x191D7CAE},
	{0xA4CD0B17, 0xC961021D, 0x2705204D, 0x8E679A95, 0x02A70CA3} } ,
	 { {0x18DD95FC, 0x2E72C138, 0x078DA6D7, 0x4CF6C7D3, 0x11FEE51E},
	{0x7C331577, 0xDA6AFFC7, 0x38831D34, 0x7B8F1A0F, 0x12A6287F} }  } ,
	 {  { {0x8B457ABC, 0x037EE457, 0xB5F66103, 0x6FA8A262, 0x0AFD6656},
	{0x1A21AC63, 0x745DE1D6, 0x43094E57, 0xDB7B6ACF, 0x06397C6F} } ,
	 { {0x20FE94CD, 0xCDFABF8C, 0x25C0BF2A, 0xBA9A7C7C, 0x0A9895F1},
	{0x74C5812C, 0x2A341C0E, 0x88F6788E, 0x09CC4AC7, 0x1BBE4ADB} }  } ,
	 {  { {0x2906138B, 0x89DBDF33, 0x53393803, 0xF5F2125E, 0x01BD0CA0},
	{0x4816FCCF, 0x84C5A170, 0x47C43122, 0x7A9980B7, 0x19531E95} } ,
	 { {0xDF97C597, 0x35651954, 0xD0FE00CA, 0x6A4CF1A7, 0x1368C43D},
	{0x7CDB8ADF, 0x48A0B9A7, 0x03E567BA, 0x66386222, 0x085D30BE} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 815 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 816 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 817 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 818 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 819 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 820 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 821 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 822 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 823 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 824 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 825 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 826 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x85811B92, 0x6BD6DBC0, 0x8CC01746, 0x66E38127, 0x114980BE},
	{0x00455AF6, 0x44B3B8BC, 0x0073B097, 0x15F1FCF0, 0x20AC9FE3},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x1858A641, 0x09FC4A99, 0xE1C97D80, 0xA0947F83, 0x0409EA4C},
	{0x531EB88F, 0x12B85E4B, 0x5AFEF29D, 0xD138492A, 0x0CB958A2} } ,
	 { {0xCEFB08BE, 0x0AE0DB25, 0x22DC8B52, 0x16F50BA9, 0x18916888},
	{0xE7DE532F, 0xC909D337, 0xB78BE984, 0xDD5976AE, 0x062D4F05} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x64B3B9F6, 0x89C243A4, 0x1DDA47BA, 0x840E810B, 0x0EA1442E},
	{0x54393DA3, 0xCDC670E5, 0x922D9AD4, 0xC199E40D, 0x0F9C2300},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x1DE03404, 0xA57513B2, 0x96718AAA, 0x6FA49A0C, 0x14B48B60},
	{0xB4B9F2F1, 0xB264ED15, 0x100ED3C3, 0x678F3F15, 0x1136DF0E} } ,
	 { {0x8FF2E72C, 0xB497950E, 0x2C94C525, 0x6290A6D7, 0x00B1CE72},
	{0xC8F07A5E, 0x7D2B2CD7, 0xCBAF0716, 0xE0A6729F, 0x20DFCDDA} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x6A6E9425, 0x1358962A, 0xFCD7C6EC, 0x8052A752, 0x05708B0C},
	{0x644A050D, 0x69C4F82F, 0x91D3BAA5, 0x5B722828, 0x19EF2F2F} } ,
	 { {0xEEF0C80D, 0xC670336C, 0xC4A15DA7, 0x8F66AA45, 0x14BDFB11},
	{0xA5DC3924, 0x79A18AA5, 0x5AC150BC, 0xA75CAB34, 0x04D54731} }  } ,
	 {  { {0x66639351, 0x953FC127, 0xDFEFE15E, 0xA262DBAA, 0x0BAEA4C2},
	{0x98D82BB0, 0x6C0FFAC8, 0x8A252D2B, 0x9FDC911D, 0x16930D55} } ,
	 { {0xC075E2C7, 0x04981055, 0x47F460F6, 0x6D277C78, 0x101BE737},
	{0x7C121112, 0x96E95C1E, 0x2DA9B58A, 0x040F487D, 0x067B96EB} }  } ,
	 {  { {0x7F80B8F2, 0x6AD3B1CC, 0x29FAABEC, 0x026B0D8F, 0x1AA8A182},
	{0x9499B16B, 0xDB48B372, 0x27B69762, 0x8BF4DE69, 0x162B4A4A} } ,
	 { {0xF15671E1, 0x61D692A4, 0x7B69799A, 0x700674CE, 0x1A29CED6},
	{0x7FEF5444, 0x3ABD8828, 0x3CCB460B, 0xF8401C18, 0x01C97DDE} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 827 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 828 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 829 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 830 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 831 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 832 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 833 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 834 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 835 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 836 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 837 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 838 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x0B23C80C, 0x20E78E03, 0xAB0A47AE, 0x9A6F6CEF, 0x017DEA6C},
	{0xDFB84E13, 0x024CEB72, 0x83D7D55F, 0xC381E918, 0x0FB1AEAA},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x18098487, 0x1F6B3B95, 0xA34FE546, 0x3F5C2811, 0x0A9E1EEA},
	{0x3423A805, 0xDF7156F9, 0xF47C78C2, 0xC0CAAF81, 0x1E015808} } ,
	 { {0x2E73F411, 0xCA99BC03, 0xA93ECB8F, 0xB2666C2E, 0x04A9A410},
	{0x885C6C65, 0xB794D4AC, 0xA6C8A2B7, 0x27A24EC6, 0x0635EE71} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x016F22EF, 0x736BA227, 0xC3B99136, 0xAAC9A4B7, 0x22F26069},
	{0x28C796E8, 0xB5B8B436, 0xB5DB48B2, 0x0F18CAF7, 0x1EEA6603},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xE18B9811, 0x35B7C916, 0x819BF021, 0xB8E56D05, 0x17002EC0},
	{0xE1662680, 0xDF7644F5, 0xB1BCEB1C, 0x54D52413, 0x16AD9DDD} } ,
	 { {0x78697582, 0xDCBF7529, 0x12820E87, 0xB935DC84, 0x00832F85},
	{0xE403F117, 0x06BDECCC, 0x1885CAFD, 0x399BF08A, 0x068AA78C} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x9CB15D68, 0xD582D5CA, 0x97CF934C, 0x060DC75C, 0x0B869DB9},
	{0x91CD556D, 0xC149ED10, 0xC1197547, 0xC1519F68, 0x0AC37D28} } ,
	 { {0x6EB72FAD, 0x24315474, 0x10DCFD7E, 0x716538FA, 0x21343036},
	{0x2BCBAAFC, 0xDAE6A8B2, 0xAE7478AD, 0x921B6F97, 0x00034D50} }  } ,
	 {  { {0x1C65497E, 0x5A8909A5, 0x8A980312, 0xB7354096, 0x04D32C62},
	{0xF4E70982, 0xE09FD109, 0x9DD031AA, 0x8A14520F, 0x18FF1CC8} } ,
	 { {0x3C3F56FC, 0x58CF942E, 0x18684A50, 0x1CD9AA5B, 0x1DA1841F},
	{0xFA00C124, 0x63B36211, 0x7D448C9D, 0x9E02E92F, 0x06E43C34} }  } ,
	 {  { {0xA71527F1, 0x81EE3192, 0x372828D2, 0x27BCC045, 0x0AEA9120},
	{0x293C33E7, 0x3DD80A0D, 0xD8A25FF5, 0x1AB0136B, 0x17F331B9} } ,
	 { {0xEBACC8C9, 0x54A64B24, 0xCAF44588, 0x14AAF938, 0x1CDAD30E},
	{0xA5880EB0, 0x8341308D, 0x1BA6CB2E, 0xD27B082E, 0x0D36518E} }  }  } ;
		pbc_map_opt_ate_mul(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_mul 839 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_mul 840 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_mul 841 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_mul 842 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_mul 843 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_mul 844 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_mul 845 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_mul 846 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_mul 847 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_mul 848 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_mul 849 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_mul 850 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xD4699377, 0x73A04801, 0x0778A3EB, 0x697E3472, 0x16D003A5},
	{0xF70FC144, 0x8A7AFE6B, 0xC2EB7A54, 0x83106E16, 0x0EDDACAA},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xA3E595C6, 0x55FBF702, 0x17A8A2D1, 0xB877D242, 0x0D0B80CF},
	{0x1EB336E0, 0x35F1DF56, 0x154E86B8, 0xAE000A6B, 0x1B4107DB} } ,
	 { {0xB27F10E9, 0x976387E4, 0x2D71DEF4, 0x7CAA5B57, 0x22375D4B},
	{0xB031E580, 0xF7D3A221, 0xE72CC992, 0x1D71DFA3, 0x109729D2} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x87AD58EB, 0x613EFF22, 0x8BE2365A, 0x581BAB64, 0x1D696B41},
	{0x2D76B423, 0xBBEE500F, 0x47ABC48B, 0x25EE18C3, 0x0B55F632},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x7C9C50A2, 0x810A2723, 0x0919D550, 0xFB39C764, 0x11E00854},
	{0x38C65CD1, 0x42461D30, 0x506B877C, 0xEAD0CA26, 0x1B46150D} } ,
	 { {0xAD41E0CE, 0x00DB09A8, 0x559379F4, 0x8A39818F, 0x12E7F1A8},
	{0x3DFFE668, 0xA8E2CD7B, 0x20FACDC9, 0x27A1A478, 0x1F1C9434} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xC7440EBA, 0xD6145CC8, 0x373DC916, 0x4D9B20E7, 0x22F8328F},
	{0xAE9F0A10, 0x2F6B5012, 0xA6F743C5, 0xBDD1CDD7, 0x17F89D44} } ,
	 { {0xB370767F, 0xCBB97066, 0xE15A3A5F, 0xAFF0B5E1, 0x1368860C},
	{0xEA200A06, 0x1A482075, 0x41611B03, 0x0EC80176, 0x1D63B1A8} }  } ,
	 {  { {0x40465476, 0xD88519F2, 0xB4A468A8, 0x19FCCA35, 0x1789B884},
	{0x22BB9846, 0xCA8A4515, 0x6304E7DB, 0x416B5240, 0x176D4237} } ,
	 { {0x7D533205, 0xCA0F18F1, 0xDC6C157F, 0x5C457FAB, 0x10E40D9C},
	{0xE9EA4BBF, 0x2B920937, 0xD4DBD3ED, 0xCC722A68, 0x03B1021D} }  } ,
	 {  { {0x0A68234F, 0x0B30A6D6, 0x8B108402, 0xE56157E1, 0x1AC82DC6},
	{0xF407E10E, 0xD01AD257, 0xC13BB85B, 0xB4E6D28F, 0x1E342838} } ,
	 { {0x9A081951, 0x4B755C31, 0xF9A6289E, 0xD1240662, 0x13A765DC},
	{0xEBAF18C3, 0xCF6694CE, 0xBA6A47DE, 0x79618A19, 0x200B1CD4} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 851 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 852 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 853 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 854 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 855 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 856 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 857 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 858 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 859 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 860 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 861 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 862 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x18799269, 0x335A8B37, 0xA09E32B4, 0x05EDA50C, 0x03D0917B},
	{0xC8EE0F46, 0x178D9837, 0xA39FA796, 0x31524A39, 0x17404E85},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x527F55BD, 0x56A6DCD9, 0xC202B54F, 0x28FE8DAB, 0x22FAD1A4},
	{0x739B6C24, 0x2CD96F12, 0xD29E8CAB, 0x413A3499, 0x2043C914} } ,
	 { {0xC0478629, 0x1DE766C1, 0x17377B03, 0xB701BA7F, 0x18DDEF7D},
	{0x308C6971, 0x20E99BFF, 0x50CFC8E4, 0xB9019B01, 0x22417E03} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xE707830F, 0x0C8EB4F3, 0xBD4CDB3A, 0xB53A0942, 0x056A74A3},
	{0x0D50B8EC, 0x4150A900, 0x8B3218D5, 0xBCACA18F, 0x1AD5E86B},
	0};
		static const ecpoint_fp2 var_b2 = { { {0x7AD876F1, 0x466E54A5, 0x224836D0, 0x8E1EDEEC, 0x13C7997E},
	{0x6FEFD2EC, 0x7EED476F, 0xC9124A86, 0xC30CC7B7, 0x0164F885} } ,
	 { {0xB921FFD4, 0x812C0C6C, 0xD9F8AABE, 0x969E3EFC, 0x1143AC84},
	{0x9E5B18E0, 0x67D83D3F, 0x4B01B024, 0x85E80BCE, 0x12D58379} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x684DEB1D, 0x7F6ECA47, 0x60772525, 0x6B866369, 0x01D8EF38},
	{0xB71F0633, 0x9F3D174D, 0xD4CD5A0D, 0x6A78EE2C, 0x14E63532} } ,
	 { {0xB2A60C9D, 0xC3856076, 0x77F0728A, 0x8368285B, 0x026013D5},
	{0x2D5C3EF0, 0x3D9B7E92, 0x612D3108, 0xA887E1E2, 0x23A78566} }  } ,
	 {  { {0xD4D007A4, 0x463F2D6A, 0x5CD690A4, 0xB2906C15, 0x0811FF1D},
	{0x71E645D2, 0xC2F7E967, 0x4B20BEDE, 0x32CED6A3, 0x12E0FF0B} } ,
	 { {0x89BF0F34, 0xE139F3F0, 0x87A29F02, 0x69101CCF, 0x01AE9595},
	{0x5F223C87, 0x97C790CD, 0x0E79895B, 0x9970DBC1, 0x1E1A0403} }  } ,
	 {  { {0xFC72118C, 0xDE0E77EB, 0xA5EEDF5D, 0xAC765723, 0x04331049},
	{0x97097F18, 0xC0379B90, 0x05297847, 0x3503FBAC, 0x22D835B1} } ,
	 { {0x1AEF1E4A, 0x90C49857, 0x6A29DF63, 0xCC35578A, 0x0C91218B},
	{0x3EE04F26, 0x8CBF448C, 0xC5FF4A4E, 0x963D021E, 0x188A85CA} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 863 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 864 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 865 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 866 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 867 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 868 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 869 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 870 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 871 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 872 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 873 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 874 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x4ADEC7C9, 0xD113C9E2, 0xB1219440, 0x2E759C88, 0x07B1AEB0},
	{0x5734DCA9, 0x39436955, 0xE0F9EE60, 0x2D959D5F, 0x103A614B},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x94F33F17, 0xEF424290, 0x3A2DCAA8, 0x9DBE4A5C, 0x219FFA1B},
	{0x852D2733, 0x12777FF5, 0xD1F0670E, 0x1E6DE3D5, 0x05A46A40} } ,
	 { {0x5AD869A3, 0xA14C95AC, 0x2BD6B55B, 0x95B5B9E1, 0x1898F0C2},
	{0x72E47764, 0xDBACFF8F, 0x992D54E8, 0x48154F34, 0x138CE5D7} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xDAB88326, 0xBD60AE89, 0xBEF970EA, 0x8230E30F, 0x02B47D4B},
	{0x0FD790F1, 0x27C2A5A8, 0x9D0EE6F5, 0xE8824FE5, 0x1D33ADDD},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xC700BFFE, 0x2639DF1E, 0xDE79048D, 0xAE3E443B, 0x05513E08},
	{0x12AA720B, 0xC531F673, 0x4829D1E7, 0x6468A4F5, 0x053EE827} } ,
	 { {0x3528AFC2, 0x3E13B373, 0x0F3BFA14, 0xEF566382, 0x202D8DA5},
	{0x25C59B35, 0xAF6EF57D, 0x00277DD6, 0xA1125AFE, 0x046C07F8} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x499B3C1A, 0x9F021656, 0x61FB8F30, 0x35760913, 0x1FAA9BDC},
	{0x559B34BF, 0x712334C4, 0xACE85249, 0xBCDCD1B4, 0x0DBD7AFE} } ,
	 { {0x96D089C1, 0x5BD38B93, 0xD1B25D41, 0xD9450365, 0x11B76F0B},
	{0x520C0B07, 0x7E5E22AA, 0x01584A60, 0xDAFA5AB7, 0x11866458} }  } ,
	 {  { {0xD864FF5F, 0x16EB8D5B, 0x1C9AFC9F, 0x1CCF360F, 0x1C755E5F},
	{0x79AFFFC5, 0x24C6F00E, 0xBE7EC2FA, 0x31AB28B1, 0x1288CC43} } ,
	 { {0x5B3AE977, 0xD51333E3, 0x8C0DA1F1, 0x90AAC883, 0x1103E508},
	{0x1AEA2B07, 0x2402CB5D, 0x348F8E05, 0xB3F2003F, 0x0CE17F98} }  } ,
	 {  { {0x7FC374D7, 0xFF5A3D2D, 0xA7E98A2E, 0xCEBF09E4, 0x16CFF3BA},
	{0x0F6DE0BD, 0xD54E588A, 0xE3912FF1, 0xDE3A3B52, 0x1DD33654} } ,
	 { {0x27B5EA64, 0x3B53DB40, 0x681E9787, 0xC0EC7B0F, 0x1A2601B2},
	{0x0374B53A, 0xBAF8784B, 0x1C3BBE12, 0xDE741B1A, 0x22E0021B} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 875 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 876 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 877 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 878 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 879 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 880 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 881 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 882 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 883 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 884 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 885 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 886 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x2B3C8890, 0xF1ACA77A, 0x0B36B3A6, 0x4DBED6EE, 0x18C07E5A},
	{0xDD1945A0, 0xF2B68468, 0xBE3B0E8D, 0x4E6B365B, 0x1AC3185E},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF31D295A, 0x30D1E3EB, 0xF129294D, 0x124E6FE4, 0x0B2F9048},
	{0x65A85069, 0xD9EDE144, 0x2FCA3B7A, 0xD90317C4, 0x22665210} } ,
	 { {0x3118CD5B, 0x0E2761F9, 0x62E93CD7, 0xA84D4B61, 0x0147570D},
	{0xDE2AFC65, 0x3C9CB811, 0x9FF29762, 0x4E6078BB, 0x06B742A0} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xB9E2FFE2, 0xBB3D48D3, 0x635B9821, 0x4EC7C731, 0x00CBE05A},
	{0x2F7C6C76, 0x83FEBD3A, 0x926DA080, 0x46246F9A, 0x080172C6},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xEDA69A22, 0x3389B720, 0x2360FC9D, 0xD5581E3C, 0x12FE5CF4},
	{0xFED23F79, 0x81C7E620, 0x422344A7, 0xAD4D296F, 0x060AE61F} } ,
	 { {0xC1CDD949, 0x0CA63B26, 0xF14097CD, 0x01D4506F, 0x037AFF69},
	{0x7CFB10DB, 0x4D266278, 0xD41A8CEA, 0xA9624A47, 0x1141AC1E} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x2B3CA896, 0xFD2E3CFD, 0x719C7FC6, 0xC768A0D2, 0x1B839CF9},
	{0xC1DC44B8, 0x8BBA7A59, 0xB8B61E92, 0xAC9BDA4F, 0x15008D41} } ,
	 { {0xC1CE15B4, 0x30AB5A9A, 0xD752EBBB, 0xA3FE34EC, 0x00846F40},
	{0x9F13B3ED, 0xC6A966B0, 0xA406E192, 0xE881A4EB, 0x071A2D81} }  } ,
	 {  { {0xAADCCE51, 0xCB014654, 0x881A48C4, 0x3080BFC2, 0x1DCC8223},
	{0x15A784F7, 0xE1A04B71, 0x0D7E4C8C, 0x1A837C93, 0x08BE3D3A} } ,
	 { {0x213BA37A, 0x4410D008, 0x2CFB4C11, 0xC98AFF43, 0x033FE562},
	{0x273CCA46, 0x7F709388, 0xBDDE1D19, 0xF20D9C87, 0x023DA459} }  } ,
	 {  { {0x121A82F6, 0x1B95FE3A, 0xC534B778, 0xBA80D098, 0x164DEAB3},
	{0xD7CFBDA0, 0x58645328, 0x081E3F6D, 0x5C4CF4A8, 0x04D71A74} } ,
	 { {0xEE0D1F68, 0xC9463D35, 0x2E8B0174, 0xF3C72670, 0x08D77755},
	{0xCC977FA3, 0x4655194A, 0xB671A6C9, 0xADC7C70A, 0x1E734BF3} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 887 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 888 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 889 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 890 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 891 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 892 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 893 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 894 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 895 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 896 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 897 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 898 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x4B09D7E9, 0x6D459509, 0xCCCB0B4E, 0xDDF478A0, 0x14CDE875},
	{0x6E97AE0B, 0x84046D9F, 0xEE8309F7, 0x57C9AB90, 0x1B887C93},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xF2EF0E61, 0xFEF0EA81, 0xE4213446, 0xD30D8DFC, 0x1C1AA6AD},
	{0x6720486B, 0x6B3D1810, 0x58C82560, 0x64D9A0A1, 0x1DB9CA77} } ,
	 { {0x85F545B1, 0xE66CB3A6, 0x8FF02A1D, 0xF49EBD01, 0x0B0C0C62},
	{0xB6B046CB, 0xC466FCC4, 0x92180288, 0x2A215731, 0x01D705C3} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x60BA7B0D, 0x9F693A07, 0x708E2614, 0x467118D9, 0x11527F50},
	{0x0013157A, 0x84F5C862, 0xE05FD494, 0xF2987448, 0x018FEC2C},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xCE6363EA, 0x3A640314, 0xF3795B38, 0x08C9A5DA, 0x2372A45D},
	{0x774C6835, 0xE3B70DCE, 0x71B1C8D8, 0x7029E418, 0x08E108F2} } ,
	 { {0x0E7EF847, 0xF88A7312, 0x060D7850, 0xE867709E, 0x1C875CC9},
	{0x3F7F42FE, 0x47E71CBE, 0xB7CB10A2, 0xCE6486CF, 0x081D8C5F} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0xB8CE3927, 0xE7E902C2, 0x31684791, 0x87E7EC05, 0x1B9D3B8E},
	{0x83800908, 0x42908B08, 0x270FEFDA, 0x41F2A4B6, 0x005B28BC} } ,
	 { {0xDF67C4C1, 0x1357A726, 0x7BF958D9, 0x0BF3E856, 0x11B04CE7},
	{0x26E76AB7, 0xDFBADEF1, 0x744C6774, 0xC18C2387, 0x161F4DC0} }  } ,
	 {  { {0x6AB496B6, 0x1CA423B1, 0xDE7FD0D9, 0xEB399BD1, 0x0944793B},
	{0xB94BB60B, 0xFC0AC406, 0xE3C9D832, 0x495E5D7D, 0x22C533AF} } ,
	 { {0x1ED83679, 0x3351B519, 0xFB040A3C, 0xAB1DD06A, 0x1E95ACD1},
	{0xBB8DAD5D, 0xEC7E1721, 0x7038EF38, 0x0FA224E3, 0x183FD7E6} }  } ,
	 {  { {0x6E637BF2, 0x778FCD32, 0xE7C3182E, 0xC6807E5E, 0x0B0C873F},
	{0x42EDE6B7, 0x32F8AB45, 0xD0050298, 0xB2764B8C, 0x00BE439D} } ,
	 { {0x97D30011, 0x4DCB5ACC, 0x76301366, 0x587946DC, 0x0A973F7F},
	{0xCFF99FAF, 0x208FE5CA, 0xFF384189, 0x15D2591F, 0x12013987} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 899 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 900 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 901 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 902 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 903 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 904 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 905 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 906 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 907 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 908 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 909 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 910 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x65AFDDD8, 0x300CE3B7, 0xE526F276, 0xAFBC3CFE, 0x044CC088},
	{0x61AB8F72, 0x5E30C5A1, 0x55D80342, 0x389A4B70, 0x0B0A7641},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x29BC0B18, 0xC63B726D, 0xC10FC0FD, 0xF3ACBEAB, 0x16AB6901},
	{0xB1BE8BEB, 0x1B2EC144, 0x569B283E, 0xBF50D7C8, 0x150B17FE} } ,
	 { {0x098BEAF3, 0x043E823C, 0x4D2E1C35, 0x024097A3, 0x0CF2CB96},
	{0xD2C2856E, 0xB235C82D, 0xDDF3FC1B, 0xA23B4FD9, 0x0C3D0A4C} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x613A8E7F, 0xA5444CB6, 0xD691F32D, 0x22F82995, 0x1ED72357},
	{0x6FBC30C6, 0x28A86B60, 0xCE125F83, 0x88F395C3, 0x1F32E410},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xB345416C, 0x89F1C0BF, 0x47CC50C3, 0x7FB75713, 0x07688C4B},
	{0xE9CBFAF5, 0xA5181018, 0x3F3F8227, 0x0B3B6146, 0x1C1154F1} } ,
	 { {0x33CD3CC2, 0x2B0C7FF4, 0x6647F319, 0x67DED385, 0x20FEA8B3},
	{0x20C94FA8, 0xE9FA058E, 0x4CF4F1BF, 0xF76DA858, 0x1B42B340} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x5A099FC7, 0xEB682B8A, 0xCF2AE781, 0x4D87040F, 0x1C70B46B},
	{0x32D6032E, 0x82F75C4A, 0x86F0F180, 0xEC7360DE, 0x045B971B} } ,
	 { {0xF911E0E7, 0xCCECF0D4, 0x90F1A50A, 0xFE40C3FE, 0x17E7C643},
	{0x366FFAD0, 0xE35722F1, 0x6879438A, 0x25B2D1D4, 0x1C0B6C9A} }  } ,
	 {  { {0x1CD01890, 0x3EC5B6DA, 0x9121D306, 0xD53F299C, 0x0FD8D4D6},
	{0x85971A1F, 0x9FAD5E82, 0x4D015B10, 0x9C3A3E10, 0x0933E808} } ,
	 { {0x85EB5535, 0x55470599, 0xF8131639, 0x30031C35, 0x087B7959},
	{0x7C74E0CD, 0x5F1E9176, 0xF46F07BD, 0x7DEE3D84, 0x234E6116} }  } ,
	 {  { {0x323800C2, 0xD1E7ADD4, 0xABAB21EF, 0x4F250A70, 0x0EA09F96},
	{0x38E86992, 0x77D5EC69, 0x0547F280, 0xF5760055, 0x175D364B} } ,
	 { {0x1BB896FF, 0x3CAA8697, 0xC059B495, 0xA65B6B19, 0x065DA335},
	{0x7F95F90A, 0x5DCB86CA, 0xEC05BF2F, 0x36A6AC79, 0x0333FC8E} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 911 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 912 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 913 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 914 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 915 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 916 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 917 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 918 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 919 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 920 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 921 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 922 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0xCA8B084C, 0x4E9AC9FB, 0xEA5FAC80, 0x6A77AAC6, 0x019E2960},
	{0x488AC3E7, 0xE0764A0D, 0x87006070, 0x51DC6A1B, 0x1350EA0A},
	0};
		static const ecpoint_fp2 var_b1 = { { {0xE7C76CF7, 0x77DC8FB1, 0x794629CD, 0x5CCE2BAC, 0x19174388},
	{0x13527D0C, 0x6D6FB628, 0xBE0348F8, 0x4D5E4225, 0x23691C3B} } ,
	 { {0x018B17A6, 0xF00AE722, 0xC0345E7B, 0xF49EC25D, 0x11E0E5EC},
	{0x54C718F7, 0x782D53CC, 0x98CC4AF1, 0xAE348115, 0x147AABED} } ,
	0};
		static const ecpoint_fp var_a2 = {{0xDDEC9713, 0x51105B96, 0xEE228DB2, 0x1CA8731E, 0x0F44B8F4},
	{0x35573354, 0x1C33375A, 0x25447B3C, 0x1D5A96D2, 0x08C271F4},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xDEBC8BEC, 0xD1296859, 0xD9DE923C, 0x8889544F, 0x0E76C346},
	{0x7A5A7F0C, 0x0DA412C3, 0x3C4A2C07, 0x1AB66234, 0x01E52631} } ,
	 { {0xD0CFE351, 0xED36D6AB, 0xEF1AE4BD, 0x16E50D48, 0x09245354},
	{0xDA11B8AA, 0x5B889E43, 0x43AB0C49, 0xBEFD26E2, 0x03E32E66} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x020315DB, 0x9A1493CB, 0x0AF3E22B, 0xA4C9F729, 0x1D67D2D7},
	{0x94BA1C24, 0x7FE91FAF, 0x66604CAA, 0x289141AF, 0x0C4563A1} } ,
	 { {0xF443DE42, 0xDDAF87E5, 0x6E27839B, 0xA788A0F0, 0x20987163},
	{0x37FF0C44, 0x133E124B, 0xD40BF438, 0xF7DED93E, 0x15362A27} }  } ,
	 {  { {0xF107CECB, 0x5B1F331D, 0x08828250, 0x3968E43B, 0x13722AF3},
	{0x2470E50C, 0x7F44E69C, 0x907FF1FF, 0xB931CE33, 0x1803FBDD} } ,
	 { {0x376432D7, 0xBA55C1E4, 0x85541781, 0x88AE9955, 0x09E498DA},
	{0xF9CD9625, 0x9C9F9FF1, 0xB093DEE1, 0x7402584C, 0x06BFB08E} }  } ,
	 {  { {0x1301CAD8, 0x2D2DF11A, 0xCD134A19, 0xF92DB493, 0x08CA79AF},
	{0x23638CA1, 0xE48C049B, 0x60D39425, 0xFE0FAF64, 0x21FA743D} } ,
	 { {0x38986FB7, 0xF6406040, 0x766DE925, 0x55A56395, 0x007D72D9},
	{0x0E71BA6C, 0xE3E5998C, 0xAEE18F29, 0x3F824414, 0x007F69A0} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 923 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 924 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 925 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 926 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 927 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 928 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 929 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 930 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 931 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 932 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 933 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 934 a211");
	}
	{
		static const ecpoint_fp var_a1 = {{0x3D53126B, 0x10329D85, 0x33521331, 0xAED48C99, 0x1D65A566},
	{0x5347AEF1, 0xDD12D01F, 0x1DA5DD33, 0xEBF80F5B, 0x20182AA1},
	0};
		static const ecpoint_fp2 var_b1 = { { {0x9A7BD73B, 0x97264E08, 0x352D5E7A, 0x5CF062C9, 0x19FD3612},
	{0xDDAEC0B6, 0x4F93839F, 0x735A5653, 0x2BBBE8E0, 0x03556E26} } ,
	 { {0x158F8C04, 0x923536F2, 0xE30F769A, 0xC8157A06, 0x03FADD37},
	{0x70CFD2F3, 0xA90E4F39, 0x4B1F0433, 0x33695DA5, 0x0415038F} } ,
	0};
		static const ecpoint_fp var_a2 = {{0x6DC0B91F, 0x0B36E11F, 0x22A8E534, 0xCADF8247, 0x1E23D739},
	{0xA93D0D4E, 0xC0665A79, 0x6E433CB5, 0x14F67391, 0x0B01BAAC},
	0};
		static const ecpoint_fp2 var_b2 = { { {0xC1757502, 0x883DF09E, 0x22DB3B06, 0xEBA2BFDB, 0x0ADE58E5},
	{0xC6680C55, 0xC63B280B, 0x155644FB, 0xE421A6B5, 0x0348EFD9} } ,
	 { {0xCA8269D6, 0x7D49EF43, 0xCAB4ACBF, 0x6A04000C, 0x23AA1CF6},
	{0x02A60669, 0x95C74BB5, 0x60734A15, 0xE1D35DDC, 0x02CAA7BE} } ,
	0};
		static const fp12_t var_expected =  {  {  { {0x93EF91EC, 0xAA2C55CD, 0x34867B4B, 0x4E56C9F7, 0x0758DD33},
	{0xE3842BB1, 0xCCCEA074, 0xA3E00B5D, 0x73DCA487, 0x13772850} } ,
	 { {0x2200A85C, 0x31D11B57, 0x2C4C87E7, 0xE7E718CF, 0x2363B8F2},
	{0xABDAE750, 0x95F7EB4B, 0x9E621887, 0x410D48D3, 0x21587846} }  } ,
	 {  { {0xC2452E5A, 0x4FCBD9DE, 0x3273D6E9, 0x6FAE9031, 0x01EDE5CC},
	{0xEC9E1F90, 0xBA869DF9, 0x685A21C9, 0xD8959799, 0x1F739462} } ,
	 { {0x2885B9E7, 0x2F2337E1, 0x8BA6E7D9, 0x73B8DA7F, 0x057DDC3F},
	{0xAAB471EE, 0xEACE645F, 0xB76C1BB7, 0x8B984837, 0x15287AE1} }  } ,
	 {  { {0x0415F077, 0x758059A5, 0x7B9A91BB, 0xBBB6E889, 0x046F09CB},
	{0x47B6E077, 0x32784BBF, 0x6667AE1E, 0x4A154FEC, 0x1D58F725} } ,
	 { {0x3DC93545, 0xDE972B39, 0x289AE56C, 0x09E7F84E, 0x034A649D},
	{0xCC2E32DB, 0xE706D73A, 0xDE6A3994, 0xEE661D65, 0x146A1EA8} }  }  } ;
		pbc_map_opt_ate_div(&var_res, &var_a1, &var_b1, &var_a2, &var_b2);
		assert_bi_equal(var_expected[0][0][0], var_res[0][0][0], "pbc_map_opt_ate_div 935 a000");
		assert_bi_equal(var_expected[0][0][1], var_res[0][0][1], "pbc_map_opt_ate_div 936 a001");
		assert_bi_equal(var_expected[0][1][0], var_res[0][1][0], "pbc_map_opt_ate_div 937 a010");
		assert_bi_equal(var_expected[0][1][1], var_res[0][1][1], "pbc_map_opt_ate_div 938 a011");
		assert_bi_equal(var_expected[1][0][0], var_res[1][0][0], "pbc_map_opt_ate_div 939 a100");
		assert_bi_equal(var_expected[1][0][1], var_res[1][0][1], "pbc_map_opt_ate_div 940 a101");
		assert_bi_equal(var_expected[1][1][0], var_res[1][1][0], "pbc_map_opt_ate_div 941 a110");
		assert_bi_equal(var_expected[1][1][1], var_res[1][1][1], "pbc_map_opt_ate_div 942 a111");
		assert_bi_equal(var_expected[2][0][0], var_res[2][0][0], "pbc_map_opt_ate_div 943 a200");
		assert_bi_equal(var_expected[2][0][1], var_res[2][0][1], "pbc_map_opt_ate_div 944 a201");
		assert_bi_equal(var_expected[2][1][0], var_res[2][1][0], "pbc_map_opt_ate_div 945 a210");
		assert_bi_equal(var_expected[2][1][1], var_res[2][1][1], "pbc_map_opt_ate_div 946 a211");
	}
#endif
#endif
	return 0;
}
