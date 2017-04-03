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

#ifndef PBC_H_
#define PBC_H_

#include "pbc_bn_std.h"

#define pbc_map_opt_ate(res, p1, p2)				pbc_map_opt_ate_optimized_std(res, p1, p2)
#define pbc_map_opt_ate_mul(res, p1, q1, p2, q2)	pbc_map_opt_ate_mul_std(res, p1, q1, p2, q2)
#define pbc_map_opt_ate_div(res, p1, q1, p2, q2)	pbc_map_opt_ate_div_std(res, p1, q1, p2, q2)

#endif /* PBC_H_ */
