/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:03:59 by mdeanne           #+#    #+#             */
/*   Updated: 2019/12/05 23:04:02 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (((is_ddioouuxx(tls->type) && tls->type != 'o' &&
		!which_sign(&fld->number, tls)) || tls->type == 's') &&
		(tls->precision == 0 && !(tls->flags & M_PRECISION_NOT_ADDED)))
		;
	else if (is_ddioouuxx(tls->type) || tls->type == 'p')
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

void	get_value_float(t_mkfld *fld, t_prsng *tls, char *str)
{
	if (tls->flags & M_MINUS)
		fld->len_empty_field = ((tls->flags & M_SPACE || tls->flags & M_PLUS ||
								 which_sign(&fld->number, tls) < 0) ? 1 : 0);
	else
		fld->len_empty_field = fld->len;
	ft_strncpy(&str[fld->len_empty_field], fld->str, fld->lennum);
}

_Bool	set_buff(t_mkfld *fld, t_prsng *tls)
{
	if (!(fld->str = (char*)malloc(sizeof(char) * (fld->lennum + fld->len + 1))))
		return (0);
	ft_memset(fld->str, ' ', fld->lennum + fld->len);
	fld->str[fld->lennum + fld->len] = '\0';
	if (tls->flags & M_MINUS)
		fld->len -= fld->len_empty_field;
	get_value_by_type(fld, tls);
	if (tls->precision > 0 && fld->lennum && (size_t)tls->precision > fld->lennum && tls->type != 's')
	{
		fld->len -= tls->precision - fld->lennum;
		ft_memset(&fld->str[fld->len], '0', tls->precision - fld->lennum);
	}
	set_flags(fld, tls);
	to_buff(fld->str, tls, fld);
	free(fld->str);
	return (1);
}

_Bool	set_buff_float(t_mkfld *fld, t_prsng *tls)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * (fld->lennum + fld->len + 1))))
		return (0);
	ft_memset(str, ' ', fld->lennum + fld->len);
	str[fld->lennum + fld->len] = '\0';
	get_value_float(fld, tls, str);
	if (tls->flags & M_ZERO && !ft_isalpha(*fld->str) && *fld->str != '-')
		{
			ft_memset(str, '0', fld->len_empty_field);
			fld->len_empty_field = 1;
		}
	if (!ft_isalpha(*fld->str) && *fld->str != '-' && which_sign(&fld->number,tls) < 0)
		str[fld->len_empty_field - 1] = '-';
	else if (!ft_isalpha(*fld->str) && *fld->str != '-' && tls->flags & M_PLUS)
		str[fld->len_empty_field - 1] = '+';
	else if (tls->flags & M_SPACE /*&& is_signed(tls->type)*/)
		str[fld->len_empty_field - 1] = ' ';
	to_buff(str, tls, fld);
	free(fld->str);
	free(str);
	return (1);
}
