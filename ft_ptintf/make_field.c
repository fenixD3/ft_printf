//
// Created by Mort Deanne on 2019-08-25.
//

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
	//////////////////////////??????
	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number.uc = (unsigned char)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number.c = (char)va_arg(tools->ap, int);
	/////////////////////////??????
}

void	set_flags(t_mkfld *field, t_prsng *tools)
{
	if (tools->flags & M_SHARP && tools->type == 'o' && field->lennum >= tools->precision)
	{
		field->str[field->len - 1] = '0';
		field->len--;
	}
	else if (tools->flags & M_SHARP && (tools->type == 'x' || tools->type == 'X'))
	{
		ft_strncpy(&field->str[field->len - 2], "0x", 2);
		field->len -= 2;
	}
	/** дополнить # для других флагов*/

	if (tools->flags & M_ZERO && !tools->precision && is_diouxx(tools->type))
	{
		while (--field->len)
			field->str[field->len] = '0';
		if ((tools->flags & M_PLUS && field->number.i > 0) || field->number.i < 0)
			field->len++;
	}
	/** дополнить для других флагов кроме diouxX*/


	if (tools->flags & M_PLUS && is_signed(tools->type) && field->number.i > 0)
		field->str[--field->len] = '+';
	else if (is_signed(tools->flags) && field->number.i < 0)
		field->str[--field->len] = '-';

}





void	len_counting(t_prsng *tools, t_mkfld *field)
{
	field->len = 0;
	field->len_empty_field = 0;
	if (tools->precision > field->lennum)
		field->len += tools->precision - field->lennum;
	field->len += define_flaglen(&field, tools);
	if (tools->field > field->lennum + field->len)
		field->len_empty_field = tools->field - field->lennum - field->len;
	field->len += field->len_empty_field;
}


void	diouxx(t_prsng *tools, t_mkfld *field)
{
	fill_union_diouxx(&field, tools);
	field->base = define_base_diouxx(tools);
	field->lennum = count_lennum(&field, tools);
	len_counting(tools, &field);
}


int 	organozation_by_flags_to_buff(t_prsng *tools)
{
	t_mkfld field;
	
	if (is_diouxx(tools->type)) 
	{
		diouxx(tools, &field);
		if (!set_buff_diouxx(&field, tools))
			return (0);
	}
	else if (!(tools->type == 'c' || tools->type == 's' || tools->type == 'p'))
		;
	else if (!is_typeflag(tools->type))
		;
	return (1);
}
