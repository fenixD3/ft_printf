//
// Created by da.filiptsev on 13.11.2019.
//

#include "libft/libft.h"

char		*print_nan(_Bool sign)
{
	char	*result;

	if (!(result = ft_strnew(4)))
		return (NULL);
	return (sign ? ft_strcpy(result, "-NaN") : ft_strcpy(result, "+NaN"));
}

char		*print_inf(_Bool sign)
{
	char	*result;

	if (!(result = ft_strnew(4)))
		return (NULL);
	return (sign ? ft_strcpy(result, "-Inf") : ft_strcpy(result, "+Inf"));
}

char		*print_zero(_Bool sign)
{
	char	*result;

	if (!(result = ft_strnew(2)))
		return (NULL);
	return (sign ? ft_strcpy(result, "-0") : ft_strcpy(result, "+0"));
}