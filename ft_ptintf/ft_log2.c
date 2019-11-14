//
// Created by Yeste Lila on 2019-11-14.
//

#include <stdint.h>
#define LOG10 0.30103

uint32_t	ft_log2(uint32_t num)
{
	static const char	log_table256[256] = {
		#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
			0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
			LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
			LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
	};
	uint32_t			tmp;

	if (tmp = num >> 24)
		return (24 + log_table256[tmp]);
	if (tmp = num >> 16)
		return (16 + log_table256[tmp]);
	if (tmp = num >> 8)
		return (8 + log_table256[tmp]);
	return (log_table256[num]);
}

