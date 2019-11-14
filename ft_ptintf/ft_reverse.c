//
// Created by Yeste Lila on 2019-11-14.
//

#include "libft/libft.h"

char	*ft_reverse(char *str)
{
	size_t	len;
	char	tmp;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		++i;
	}
	return (str);
}