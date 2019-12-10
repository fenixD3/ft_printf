//
// Created by Yeste Lila on 2019-12-05.
//

#include "high_precision.h"

void	clear_res_buff(t_result *res)
{
	free(res->buff);
	res->buff = NULL;
	res->bf_len = 0;
}

void	free_hp(t_high *hp)
{
	free(hp);
	hp = NULL;
}

void	free_l_hp(t_highl *hp)
{
	free(hp);
	hp = NULL;
}