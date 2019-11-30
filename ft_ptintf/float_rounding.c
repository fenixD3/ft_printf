//
// Created by Yeste Lila on 2019-11-30.
//

#include "myfloat.h"
#include "libft/libft.h"

void	float_round(t_result *res, size_t *oft)
{
	int		nu;

	while (*(res->result + res->len - *(++oft)) == '9')
	{
		*(res->result + res->len - *oft) = '0';
		++*(res->result + res->len - *oft - 1);
	}
	if ((*(res->result + res->len - *oft) == '.' && *(res->result + res->len - *oft + 1) == '0') ||
		(!*(res->result + res->len - *oft + 1) && (ft_isdigit(*(res->result + res->len - *oft)) || *(res->result + res->len - *oft) == '.')))
	{
		if (*(res->result + res->len - *oft) == '.')
			++oft;
		nu = ft_atoi(res->result + res->len - *oft);
		if (nu % 2)
			++*(res->result + res->len - *oft);
		else if (nu == 9)
		{
			*(res->result + res->len - *(++oft)) = '0';
			while (*(res->result + res->len - *(++oft)) == '0')
				++*(res->result + res->len - *oft);
		}
	}
}