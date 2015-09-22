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

#ifndef GSS_HWANG_H_
#define GSS_HWANG_H_

#include "types.h"
#include "ec/ec.h"

/** Private signing key. */

struct hwang_signing_key_s {
  bigint_t x, y, z;
  ecpoint_fp A;
};
typedef struct hwang_signing_key_s hwang_signing_key;
typedef struct hwang_signing_key_s *hwang_signing_key_ptr;


/** Resulting group signature. */

struct hwang_signature_s {
  bigint_t c, s_alpha, s_x, s_gamma, s_y;
  ecpoint_fp D_1, D_2, D_3;
};
typedef struct hwang_signature_s hwang_signature;
typedef struct hwang_signature_s *hwang_signature_ptr;


/** Public parameters. */

struct hwang_public_parameters_s {
  bigint_t order_p, theta;
  ecpoint_fp g, u, w, d, g1, g2;
  ecpoint_fp2 h1, h_theta, U;
};
typedef struct hwang_public_parameters_s hwang_public_parameters;
typedef struct hwang_public_parameters_s *hwang_public_parameters_ptr;

/**
 * Generates a signature according to the scheme of HWANG.
 * @param sig    [out] computed signature.
 * @param data   [in]  public data of HWANG scheme.
 * @param usk    [in]  user secret key to generate a valid signature.
 *
 * @return       1 on success; -1 on ERROR;
 */
sbyte hwang_sign(hwang_signature_ptr sig, hwang_public_parameters_ptr data, hwang_signing_key_ptr usk);

/**
 * Verify a group signature.
 *
 * @param data the parameters of the group-signature scheme.
 * @param sig the generated signature to be verified.
 *
 * @return 1 if the signature is VALID; -1 otherwise.
 */
sbyte hwang_verify(hwang_public_parameters_ptr data, hwang_signature_ptr sig);

/**
 * Generates a tuple (x, y, z, A) --- with x, y, z \in \mathbb{Z}_p^*
 * and A \in \mathbb{G}_1 --- that acts as a user's signing key.
 * @param usk  [out] the generated signing key for one user.
 * @param data [in] the public parameters.
 */
void hwang_generate_usk(hwang_signing_key_ptr usk, hwang_public_parameters_ptr data);

/**
 * Initializes the public parameters, the master issuing key (MIK),
 * the master opening key (MOK), and the master linking key (MLK).
 *
 */
void hwang_init_parameters(hwang_public_parameters_ptr data);

#endif /* GSS_HWANG_H_ */
