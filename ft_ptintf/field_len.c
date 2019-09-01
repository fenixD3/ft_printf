//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

size_t count_lennum(t_mkfld *field, t_prsng *tools)
{
	size_t lennum;
	unsigned long long number;

	number = reverse_if_negative(&field->number, tools);
	lennum = 1;
	while (number /= field->base)
		lennum++;
	return (lennum);
}

/*size_t count_lennum(t_mkfld *field, t_prsng *tools)
{
	int len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}*/

int 	define_base_diouxx(t_prsng *tools)
{
	if (tools->type == 'd' || tools->type == 'i' || tools->type == 'u')
		return (10);
	else if (tools->type == 'o')
		return (8);
	else
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
	if (tools->flags & M_PLUS && field->number.i > 0 && is_signed(tools->type))
		len++;
	if (is_signed(tools->flags) && field->number.i < 0)
		len++;
	return (len);
}

