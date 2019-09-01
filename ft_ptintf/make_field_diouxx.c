//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

void	fill_union(t_mkfld *field, t_prsng *tools)
{
	field->number.ull = 0;
	if (tools->modifiers == 0 && tools->type == 'u')
		field->number.ui = va_arg(tools->ap, unsigned int);
	else if (tools->modifiers == 0)
		field->number.i = va_arg(tools->ap, int);
	else if (tools->modifiers & M_L && tools->type == 'u')
		field->number.ul = va_arg(tools->ap, unsigned long);
	else if (tools->modifiers & M_L)
		field->number.l = va_arg(tools->ap, long);
	else if (tools->modifiers & M_LL && tools->type == 'u')
		field->number.ull = va_arg(tools->ap, unsigned long long);
	else if (tools->modifiers & M_LL)
		field->number.ll = va_arg(tools->ap, long long);
	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number.ush = (unsigned short)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number.sh = (short)va_arg(tools->ap, int);
/*	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number.uc = (unsigned char)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number.c = (char)va_arg(tools->ap, int);*/
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

_Bool	set_buff_diouxx(t_mkfld *fld, t_prsng *tls)
{
	if (!(fld->str = (char*)malloc(sizeof(char) * (fld->lennum + fld->len + 1))))
		return (0);
	ft_memset(fld->str, ' ', fld->lennum + fld->len);//// или нулями?
	if (tls->flags & M_MINUS)
		fld->len -= fld->len_empty_field;

	itoa_base_union(tls, fld, &fld->str[fld->len]);

/*	if (tls->type == 'u')
		itoa_base_printf_unsigned(fld->number.ui, fld->base, &fld->str[fld->len], fld->lennum);
	else
		itoa_base_printf(fld->number, fld->base, &fld->str[fld->len], fld->lennum);*/


	/// заполнение нулями избытка точности
	if (tls->precision > fld->lennum)
	{
		fld->len -= tls->precision - fld->lennum;
		ft_memset(&fld->str[fld->len], '0', tls->precision - fld->lennum);
	}
	set_flags(fld, tls);
	to_buff(fld->str, tls);
	free(fld->str);
}
int 	make_field_diouxx(t_prsng *tools)
{
	t_mkfld field;

	fill_union(&field, tools);
	field.base = define_base_diouxx(tools);
	field.lennum = count_lennum(&field, tools);
	field.len = 0;
	field.len_empty_field = 0;
	if (tools->precision > field.lennum)
		field.len += tools->precision - field.lennum;
	field.len += define_flaglen(&field, tools);
	if (tools->field > field.lennum + field.len)
		field.len_empty_field = tools->field - field.lennum - field.len;
	field.len += field.len_empty_field;
	set_buff_diouxx(&field, tools);


	return (1);
}
