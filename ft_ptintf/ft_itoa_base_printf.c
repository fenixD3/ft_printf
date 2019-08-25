//
// Created by Mort Deanne on 2019-08-20.
//

//#include "libft.h"
#include "ft_ptintf.h"

char *itoa_base_printf(long long n, int base, char *str, int lennum)
{
	int		negative;

	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (lennum--)
	{
		str[lennum] = n % base + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char *itoa_base_printf_unsigned(unsigned long long n, int base,
								char *str, int lennum)
{
	while (lennum--)
	{
		str[lennum] = n % base + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
	}
	return (str);
}