//
// Created by Mort Deanne on 2019-08-20.
//

//#include "libft.h"
#include "ft_ptintf.h"

unsigned long long reverse_if_negative(t_un *number, t_prsng *tools)
{
	unsigned long long ret;

	ret = 0;
	if (!is_signed(tools->type) || (is_signed(tools->type) && number->i > 0))
		ret = number->ull;
	else
	{
		if (tools->modifiers == 0)
			ret = (unsigned long long)-number->i;
		else if (tools->modifiers & M_L)
			ret = (unsigned long long)-number->l;
		else if (tools->modifiers & M_H)
			ret = (unsigned long long)-number->sh;
		else if (tools->modifiers & M_LL)
			ret = (unsigned long long)-number->ll;
	}
	return (ret);

}

char *itoa_base_union(t_prsng *tools, t_mkfld *field, char *str)
{
	unsigned long long	n;
	size_t				lennum;

	lennum = field->lennum;
	n = reverse_if_negative(&field->number, tools);
	while (lennum--)
	{
		str[lennum] = n % field->base + (n % field->base > 9 ? 'A' - 10 : '0');
		n /= field->base;
	}
	return (str);
}