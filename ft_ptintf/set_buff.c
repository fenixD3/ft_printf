//
// Created by Mort Deanne on 2019-09-03.
//

#include "ft_ptintf.h"

void	str_tolower(char *str)
{
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
}

void	get_value_by_type(t_mkfld *fld, t_prsng *tls)
{
	if (is_ddioouuxx(tls->type) || tls->type == 'p')
		{
			itoa_base_union(tls, fld, &fld->str[fld->len]);
			if (tls->type == 'x' || tls->type == 'p')
				str_tolower(&fld->str[fld->len]);
		}
	else if (tls->type == 's')
		ft_strncpy(&fld->str[fld->len], fld->number.cptr, fld->lennum);
	else if (tls->type == 'c')
		fld->str[fld->len] = fld->number.c;
	else if (!is_flag(tls->type))
		fld->str[fld->len] = tls->type;
}

_Bool	set_buff(t_mkfld *fld, t_prsng *tls)
{
	if (!(fld->str = (char*)malloc(sizeof(char) * (fld->lennum + fld->len + 1))))
		return (0);
	ft_memset(fld->str, ' ', fld->lennum + fld->len);//// или нулями?
	fld->str[fld->lennum + fld->len] = '\0';
	if (tls->flags & M_MINUS)
		fld->len -= fld->len_empty_field;
	get_value_by_type(fld, tls);
	/// заполнение нулями избытка точности
	if ((size_t)tls->precision > fld->lennum)
	{
		fld->len -= tls->precision - fld->lennum;
		ft_memset(&fld->str[fld->len], '0', tls->precision - fld->lennum);
	}
	set_flags(fld, tls);
	to_buff(fld->str, tls);
	free(fld->str);
	return (1);
}