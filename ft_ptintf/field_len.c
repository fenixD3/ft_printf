//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

size_t count_lennum(t_mkfld *field, t_prsng *tools)
{
	size_t				lennum;
	unsigned long long	number;


	if (which_sign(&field->number, tools) == 0)
		return (1);
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
	if (tools->type == 'd' || tools->type == 'i' || tools->type == 'u' || tools->type == 'f' || tools->type == 'F' || tools->type == 'e' || tools->type == 'E' || tools->type == 'g' || tools->type == 'G')
		return (10);
	else if (tools->type == 'o')
		return (8);
	else
		return (16);
}

int		define_flaglen(t_mkfld *field, t_prsng *tools)
{
	int len;

	len = 0;
	if (tools->flags & M_SHARP || tools->type == 'p')
	{
		if (tools->type == 'o')
		{
			if (!tools->precision && !(tools->flags & M_PRECISION_NOT_ADDED) && !which_sign(&field->number, tools))
				;
			else if (field->lennum >= (size_t)tools->precision && (which_sign(&field->number, tools) || !(tools->flags & M_PRECISION_NOT_ADDED))) ////////////////////// ERROR!!!
				len++;
		}
		else if (((tools->type == 'x' || tools->type == 'X') && field->number.i) || tools->type == 'p')
			len = 2;
	}
	if ((tools->flags & M_SPACE && is_signed(tools->type)) || (tools->flags & M_PLUS && which_sign(&field->number, tools) >= 0 && is_signed(tools->type)) || (is_signed(tools->type) &&
			which_sign(&field->number, tools) < 0))
		len++;
	return (len);
}

