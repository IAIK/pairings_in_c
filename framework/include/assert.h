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

#ifndef ASSERT_H_
#define ASSERT_H_

#include "types.h"

int assert_true(const int c, const char *msg);
int assert_bytearr_equal(const byte* ex, const byte* tst, length_t bytes, const char *msg);
int assert_bi_equal(const bigint_t ex, const bigint_t tst, const char *msg);
int assert_bi_equal_var(const word_t *ex, const word_t *tst, length_t len, const char *msg);
int assert_equal(word_t ex, word_t tst, const char *msg);

#endif /* ASSERT_H_ */
