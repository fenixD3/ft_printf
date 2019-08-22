//
// Created by Mort Deanne on 2019-08-20.
//

//#include "libft/libft.h"
#include "ft_ptintf.h"

_Bool	ft_putptr_buff(void *ptr, t_prsng *tools)
{
	char 		*str;
	int			i;

	if (!(str = ft_itoa_base((long long)ptr, 16)))
		return (0);
	i = 0;
	while (str[i])
	{
		str[i] = (char)ft_tolower(str[i]);
		i++;
	}
	to_buff("0x", tools);
	to_buff(str, tools);
	free(str);
	return (1);
}