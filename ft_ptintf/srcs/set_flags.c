/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:28:06 by mdeanne           #+#    #+#             */
/*   Updated: 2019/12/10 22:28:09 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

void	set_hex_prefix(t_mkfld *field, t_prsng *tools)
{
	if (tools->flags & M_SHARP && tools->type == 'o' &&
							field->lennum >= (size_t)tools->precision &&
							which_sign(&field->number, tools) != 0)
	{
		field->str[field->len - 1] = '0';
		field->len--;
	}
	else if ((tools->flags & M_SHARP) && !(tools->flags & M_ZERO) &&
			(((tools->type == 'x' || tools->type == 'X') && field->number.i)))
	{
		field->str[field->len - 2] = '0';
		field->str[field->len - 1] = tools->type;
		field->len -= 2;
	}
	else if (tools->type == 'p')
	{
		ft_strncpy(&field->str[field->len - 2], "0x", 2);
		field->len -= 2;
	}
}

void	set_flags(t_mkfld *field, t_prsng *tools)
{
	set_hex_prefix(field, tools);
	if (tools->flags & M_ZERO)
	{
		while (field->len)
			field->str[--field->len] = '0';
		if ((tools->flags & M_PLUS && field->number.i >= 0) ||
			which_sign(&field->number, tools) < 0 || tools->flags & M_SPACE)
			field->len++;
	}
	if ((tools->flags & M_SHARP && (tools->flags & M_ZERO) != 0 &&
			((tools->type == 'x' || tools->type == 'X') && field->number.i)))
	{
		field->str[0] = '0';
		field->str[1] = tools->type;
		field->len -= 2;
	}
	if (tools->flags & M_PLUS && is_signed(tools->type) &&
									which_sign(&field->number, tools) >= 0)
		field->str[--field->len] = '+';
	else if (is_signed(tools->type) && which_sign(&field->number, tools) < 0)
		field->str[--field->len] = '-';
	else if (tools->flags & M_SPACE && is_signed(tools->type))
		field->str[--field->len] = ' ';
}
