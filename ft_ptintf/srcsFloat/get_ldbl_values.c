//
// Created by Yeste Lila on 2019-11-18.
//

#include "myfloat.h"

_Bool		get_lsign(uint64_t *ldbl)
{
	return (*(ldbl + 1) & (1 << 15));
}

int32_t		get_lexp(uint64_t *ldbl)
{
	return (*(ldbl + 1) & 0x7FFF);
}

uint64_t	get_lmantissa(uint64_t *ldbl)
{
	return (*ldbl & 0xFFFFFFFFFFFFFFFF);
}
