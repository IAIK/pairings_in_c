/*
 * pbc_bn_std.h
 *
 *  Created on: Apr 24, 2013
 *      Author: thomas
 */

#ifndef PBC_BN_STD_H_
#define PBC_BN_STD_H_

void pbc_map_opt_ate_std(fp12_t res, ecfp_pt p, ecfp2_pt q);
void pbc_map_opt_ate_optimized_std(fp12_t res, ecfp_pt p, ecfp2_pt q);
void pbc_map_opt_ate_mul_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2);
void pbc_map_opt_ate_div_std(fp12_t res, ecfp_pt p1, ecfp2_pt q1, ecfp_pt p2, ecfp2_pt q2);

#endif /* PBC_BN_STD_H_ */
