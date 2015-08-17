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

/**
 * Defines big integer constants for one and zero that depend on the datatype's size.
 */
#if BYTES_PER_WORD == 4
  #if PRECISION == 256
    const bigint_t bi_one = {0x00000001, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000, 0x00000000,0x00000000, 0x00000000};
    const bigint_t bi_zero= {0x00000000, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000, 0x00000000,0x00000000, 0x00000000};
  #elif PRECISION == 160
    const bigint_t bi_one = {0x00000001, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000};
    const bigint_t bi_zero= {0x00000000, 0x00000000, 0x00000000, 0x00000000,
    						 0x00000000};
  #endif
#endif
