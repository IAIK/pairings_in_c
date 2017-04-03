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
#include "hash/hashing.h"
#include "types.h"
#include "gss/sdh_zk.h"
#include "bigint/bi.h"
#include "util.h"

#include <string.h>

int main(void) {

  const unsigned int length = 4;
  group_public_key gpk;
  group_secret_key gsk[length];
  group_master_secret_key gmsk;
  sgs_init(length, &gpk, &gmsk, gsk);


  sdh_signiture sig;
  static const char *var_a = "Hallo";
  sgs_sign(gpk, gsk[2], &sig, var_a);
  sbyte verify = sgs_verify(gpk, sig, var_a);

  ecpoint_fp A;
  sgs_open(gmsk, sig, &A);
  print("   A:   "); print_value(A.x, BI_WORDS); print("\n");
  print("        "); print_value(A.y, BI_WORDS); print("\n");
  int i = 0;
  for(i = 0; i < 10; ++i) {
    sgs_sign(gpk, gsk[3], &sig, var_a);
    verify = sgs_verify(gpk, sig, var_a);
    if(verify == 0) {
      print("valid\n");
    } else {
      print("invalid\n");
    }
  }
  return 0;
}
