/*
 * bench_util.h
 *
 *  Created on: May 14, 2013
 *      Author: thomas
 */

#ifndef BENCH_UTIL_H_
#define BENCH_UTIL_H_

#include "config.h"

#if (BENCHMARK_SRC == BM_CYCLE)
typedef unsigned long long bm_time_t;
#elif (BENCHMARK_SRC == BM_CLOCK)
#include <sys/time.h>
#include <time.h>
typedef struct timespec bm_time_t;
#endif

void benchmark_start();
void benchmark_stop();
void benchmark_compute(int iterations);
void benchmark_compute_single();
void benchmark_print(const char *msg);

#endif /* BENCH_UTIL_H_ */
