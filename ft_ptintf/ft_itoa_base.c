//
// Created by Mort Deanne on 2019-08-20.
//

//#include "libft.h"
#include "ft_ptintf.h"

static size_t	ft_lennum(long long n, base)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= base)
		len++;
	return (len);
}

char			*ft_itoa_base(long long n, int base)
{
	char	*str;
	int		len;
	int		negative;

	len = ft_lennum(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (len--)
	{
		str[len] = n % base + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
