/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_union.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:15:34 by mdeanne           #+#    #+#             */
/*   Updated: 2019/12/10 22:15:36 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

void	fill_union_diouxx(t_mkfld *field, t_prsng *tools)
{
	field->number.ull = 0;
	if (tools->modifiers == 0 && tools->type == 'u')
		field->number.ui = va_arg(tools->ap, unsigned int);
	else if (tools->modifiers == 0)
		field->number.i = va_arg(tools->ap, int);
	else if (tools->modifiers & M_LL && tools->type == 'u')
		field->number.ull = va_arg(tools->ap, unsigned long long);
	else if (tools->modifiers & M_LL)
		field->number.ll = va_arg(tools->ap, long long);
	else if (tools->modifiers & M_L && tools->type == 'u')
		field->number.ul = va_arg(tools->ap, unsigned long);
	else if (tools->modifiers & M_L)
		field->number.l = va_arg(tools->ap, long);
	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number.ush = (unsigned short)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number.sh = (short)va_arg(tools->ap, int);
	else if (tools->modifiers & M_HH && tools->type == 'u')
		field->number.uc = (unsigned char)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_HH)
		field->number.c = (char)va_arg(tools->ap, int);
}

_Bool	fill_union_csp(t_mkfld *field, t_prsng *tools)
{
	field->number.ull = 0;
	if (tools->type == 'c')
	{
		if ((field->number.c = (char)va_arg(tools->ap, int)) == 0)
			tools->flags |= M_ZERO_CHAR;
	}
	else if (tools->type == 's')
	{
		field->number.cptr = va_arg(tools->ap, char*);
		if (!field->number.cptr && !(field->number.cptr = ft_strdup("(null)")))
			return (0);
	}
	else if (tools->type == 'p')
		field->number.ull = va_arg(tools->ap, unsigned long long);
	return (1);
}

void	fill_union_aaeeffgg(t_mkfld *field, t_prsng *tools)
{
	field->number.db = 0.0;
	field->number.ldb = 0.0;
	if (tools->modifiers & M_UPPER_L)
		field->number.ldb = va_arg(tools->ap, long double);
	else
		field->number.db = va_arg(tools->ap, double);
}
