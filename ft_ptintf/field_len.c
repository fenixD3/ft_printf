//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

int ft_lennum(long long n, int base)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= base)
		len++;
	return (len);
}

int 	define_base(t_prsng *tools)
{
	if (tools->type == 'd' || tools->type == 'i' || tools->type == 'u')
		return (10);
	else if (tools->type == 'o')
		return (8);
	else if (tools->type == 'x' || tools->type == 'X')
		return (16);
}

int define_flaglen(t_mkfld *field, t_prsng *tools)
{
	int len;

	len = 0;
	if (tools->flags & M_SHARP)
	{
		if (tools->type == 'o' && field->lennum <= tools->precision)
			len++;
		else if (tools->type == 'x' || tools->type == 'X')
			len = 2;
	}
	if (tools->flags & M_PLUS && field->number > 0 && is_signed(tools->type))
		len++;
	return (len);
}

