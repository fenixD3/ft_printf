//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

size_t count_lennum(t_mkfld *field, t_prsng *tools)
{
	size_t				lennum;
	unsigned long long	number;



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

int 	define_base(t_prsng *tools)
{
	if (tools->type == 'd' || tools->type == 'i' || tools->type == 'u')
		return (10);
	else if (tools->type == 'o' || tools->type == 'p')
		return (8);
	else
		return (16);
}

int define_flaglen(t_mkfld *field, t_prsng *tools)
{
	int len;

	len = 0;
	if (tools->flags & M_SHARP || tools->type == 'p')
	{
		if (tools->type == 'o' && field->lennum <= tools->precision)
			len++;
		else if (tools->type == 'x' || tools->type == 'X' || tools->type == 'p')
			len = 2;
	}
	if ((tools->flags & M_SPACE && is_signed(tools->type)) || (tools->flags & M_PLUS && field->number.i > 0 && is_signed(tools->type)) || (is_signed(tools->type) && field->number.i < 0))
		len++;
	return (len);
}

