/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:01:13 by mdeanne           #+#    #+#             */
/*   Updated: 2019/12/05 23:01:17 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

void	prepare_diouxxcsp(t_prsng *tools, t_mkfld *field)
{
	if (is_ddioouuxx(tools->type))
		fill_union_diouxx(field, tools);
	else if (is_csp(tools->type))
		fill_union_csp(field, tools); /// need protection strdup (malloc)
	field->base = define_base(tools);
	diouxxcsp_lennum(tools, field);
	len_counting_diouxxcsp(tools, field);
}

void	prepare_aaeeffgg(t_prsng *tools, t_mkfld *field)
{
	fill_union_aaeeffgg(field, tools);
	if (!(tools->flags & M_B))
	{
		if ((tools->modifiers & M_UPPER_L))
			field->str = print_long_double(tools, field, field->number.ldb);
		else
			field->str = print_double(tools, field, field->number.db);
	}
	else
	{
		field->lennum = 3 + ((tools->modifiers & M_UPPER_L)) ?
										80 : sizeof(double);
		if (tools->modifiers & M_UPPER_L)
			field->str = get_binary( (uint64_t *)&field->number.ldb,
					80, field, 'd');
		else
			field->str = get_binary( (uint64_t *)&field->number.db,
						sizeof(double) * 8, field, 'f');
	}
	aaeeffgg_lennum_len(tools, field);
}

int		organozation_by_flags_to_buff(t_prsng *tools)
{
	t_mkfld field;

	zeroing_mkfield(&field);
	if (is_aaeeffgg(tools->type))
	{
		prepare_aaeeffgg(tools, &field);
		if (!set_buff_float(&field, tools))
			return (0);
	}
	else if (is_ddioouuxx(tools->type) || is_csp(tools->type)
			 										|| !is_flag(tools->type))
	{
		prepare_diouxxcsp(tools, &field);
		if (tools->type && !set_buff(&field, tools))
			return (0);
	}
	return (1);
}
