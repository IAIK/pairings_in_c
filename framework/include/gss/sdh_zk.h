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

#ifndef INCLUDE_SDH_SDH_ZK_H_
#define INCLUDE_SDH_SDH_ZK_H_

#include "types.h"
#include "ec/ec.h"

struct group_public_key_s {
  ecpoint_fp g1, h, u, v;
  ecpoint_fp2 g2, w;
};

struct group_secret_key_s {
  ecpoint_fp A;
  bigint_t x;
};

struct group_master_secret_key_s {
  bigint_t xi1;
  bigint_t xi2;
};

struct sdh_signiture_s {
  bigint_t c, s_alpha, s_beta, s_x, s_delta1, s_delta2;
  ecpoint_fp T_1, T_2, T_3;
};

typedef struct group_public_key_s group_public_key;
typedef struct group_secret_key_s group_secret_key;
typedef struct group_master_secret_key_s group_master_secret_key;
typedef struct sdh_signiture_s sdh_signiture;


void sgs_init(length_t number_of_members, group_public_key *gpk, group_master_secret_key *gmsk, group_secret_key *gsk);

void sgs_sign(group_public_key gpk, group_secret_key gsk, sdh_signiture *sig, const char *message);

sbyte sgs_verify(group_public_key gpk, sdh_signiture sig, const char *message);

void sgs_open(group_master_secret_key gmsk, sdh_signiture sig, ecpoint_fp *A);

#endif /* INCLUDE_SDH_SDH_ZK_H_ */
