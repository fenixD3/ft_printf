//
// Created by da.filiptsev on 09.12.2019.
//

#include "ft_ptintf.h"

char	*get_binary(uint64_t *num, size_t bit_size, const char type)
{
	char		*res;
	uint64_t	tmp;
	char 		bit;
	size_t		space;
	ssize_t 	size;

	if (!(res = ft_strnew(bit_size + 3)))
		return (NULL);
	space = 0;
	size = bit_size;
	while (--size >= 0)
	{
		tmp = *num >> size & 1;
		bit = tmp + '0';
		ft_strncat(res + space, &bit, 1);
		++space;
		if (!(space % 8) && space != bit_size)
			ft_strncat(res + space, " ", 1);
	}
	return (res);
}
