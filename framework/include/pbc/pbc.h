/*
 * pbc.h
 *
 *  Created on: Apr 24, 2013
 *      Author: thomas
 */

#ifndef PBC_H_
#define PBC_H_

#define pbc_map_opt_ate(res, p1, p2)				pbc_map_opt_ate_optimized_std(res, p1, p2)
#define pbc_map_opt_ate_mul(res, p1, q1, p2, q2)	pbc_map_opt_ate_mul_std(res, p1, q1, p2, q2)
#define pbc_map_opt_ate_div(res, p1, q1, p2, q2)	pbc_map_opt_ate_div_std(res, p1, q1, p2, q2)

#endif /* PBC_H_ */
