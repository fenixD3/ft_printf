//
// Created by Mort Deanne on 2019-08-20.
//

//#include "libft/libft.h"
#include "ft_ptintf.h"

_Bool	ft_putptr(void *ptr, t_prsng *tools)
{
	char 		*str;
	int			i;

	if (!(str = ft_itoa_base((long long)ptr, 16)))
		return (0);
	ft_putstr("0x");
	i = 2;
	while (*str)
	{
		ft_putchar((char)ft_tolower(*str++));
		i++;
	}
	free(str - i + 2);
	tools->counter += i;
	return (1);
}