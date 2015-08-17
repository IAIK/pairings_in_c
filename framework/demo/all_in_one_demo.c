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
#include "ec/ec.h"
#include "fp/fp12.h"
#include "types.h"

#if PRECISION == 256
ecpoint_fp var_a = { { 0x9DD3CB65, 0x0111764E, 0x2B8820B9, 0xECEE535F,
		0xAC1D764A, 0x049FA394, 0xBFE123D7, 0x45EC613D }, { 0x3BA796CA,
		0x0222EC9D, 0x57104172, 0xD9DCA6BE, 0x583AEC95, 0x093F4729, 0x7FC247AE,
		0x8BD8C27B }, 0 };
ecpoint_fp2 var_b = { { { 0xF0027F36, 0xF03BB5B4, 0x5E64CF15, 0x20F0A9E4,
		0x302897A9, 0xC51C2261, 0x42283BE2, 0x9DC57564 }, { 0x3CFD9384,
		0x5A7A6E16, 0xE9EF308B, 0xD13A5856, 0x6EBD5BCB, 0x1B5C63F5, 0xB29BF82A,
		0x1C964417 } }, { { 0x94F7E929, 0xAA2CB61F, 0xDBFBF4C3, 0xDB6ACD7D,
		0x0B78C7FA, 0xD83E266D, 0x0DB38D76, 0x9D629E78 }, { 0x351ED5CC,
		0xEF57FE9E, 0x21ED4712, 0xF7F522EC, 0x5F6B1AA9, 0x51DEB3E4, 0x77E63422,
		0x539E24DF } }, 0 };
bigint_t var_k = {0xE4F1B68E, 0x9C1ED28A, 0x5BCA32C0, 0xBEA93771, 0x9D27E570, 0xCA990488, 0xC124E9D2, 0x196798D0};
#elif PRECISION == 160
ecpoint_fp var_a = {{0xCA8B084C, 0x4E9AC9FB, 0xEA5FAC80, 0x6A77AAC6, 0x019E2960},
		{0x488AC3E7, 0xE0764A0D, 0x87006070, 0x51DC6A1B, 0x1350EA0A},
		0};
ecpoint_fp2 var_b =  { { {0xE7C76CF7, 0x77DC8FB1, 0x794629CD, 0x5CCE2BAC, 0x19174388},
		{0x13527D0C, 0x6D6FB628, 0xBE0348F8, 0x4D5E4225, 0x23691C3B} } ,
		 { {0x018B17A6, 0xF00AE722, 0xC0345E7B, 0xF49EC25D, 0x11E0E5EC},
		{0x54C718F7, 0x782D53CC, 0x98CC4AF1, 0xAE348115, 0x147AABED} } ,
		0};
bigint_t var_k = {0x917BC168, 0x8685329C, 0xEC87C5DD, 0x8FC42FE1, 0x09256C46};
#endif

int main(void) {
	fp12_t var_res, tmp;
	ecpoint_fp t1;
	ecpoint_fp2 t2;

	fp12_clear(tmp);
	pbc_map_opt_ate(&var_res, &var_a, &var_b);
	fp12_sqr(tmp, (const fp4_t*) var_res);
	fp12_mul(tmp, (const fp4_t*) tmp, (const fp4_t *) var_res);
	fp12_exp_cyclotomic(tmp, (const fp4_t*) tmp, var_k);

	ecfp_mul(&t1, &var_a, var_k);
	ecfp_add_affine(&t1, &t1, &var_a);
	ecfp_neg_affine(&t1);
	ecfp2_mul(&t2, &var_b, var_k);
	ecfp2_add_affine(&t2, &t2, &var_b);
	ecfp2_neg_affine(&t2);
}
