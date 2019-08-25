//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

void	get_field_values(t_mkfld *field, t_prsng *tools)
{
	if (tools->modifiers == 0 && tools->type == 'u')
		field->number = va_arg(tools->ap, unsigned int);
	else if (tools->modifiers == 0)
		field->number = va_arg(tools->ap, int);
	else if (tools->modifiers & M_L && tools->type == 'u')
		field->number = va_arg(tools->ap, unsigned long);
	else if (tools->modifiers & M_L)
		field->number = va_arg(tools->ap, long);
	else if (tools->modifiers & M_LL && tools->type == 'u')
		field->number = va_arg(tools->ap, unsigned long long);
	else if (tools->modifiers & M_LL)
		field->number = va_arg(tools->ap, long long);
	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number = (unsigned short)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number = (short)va_arg(tools->ap, int);
	else if (tools->modifiers & M_H && tools->type == 'u')
		field->number = (unsigned char)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_H)
		field->number = (char)va_arg(tools->ap, int);
	field->base = define_base(tools);
	field->lennum = ft_lennum(field->number , field->base);
	field->len = 0;
}

void	set_flags(t_mkfld *field, t_prsng *tools)
{
	if (tools->flags & M_SHARP && tools->type == 'o' && field->lennum >= tools->precision)
	{
		field->str[field->len - 1] = '0';
		field->len--;
	}
	else if (tools->flags & M_SHARP && (tools->type == 'x' || tools->type == 'X'))
		;
	else if (tools->flags & M_SHARP && is_signed(tools->type) && field->number > 0)
	{
		field->str[field->len - 1] = '+';
		field->len--;
	}

}

_Bool	set_buff_diouxx(t_mkfld *field, t_prsng *tools)
{

	if (!(field->str = (char*)malloc(sizeof(char) * (field->lennum + field->len + 1))))
		return (0);
	/////////////
	ft_memset(field->str, '-', field->lennum + field->len);
	/////////////
	if (tools->type == 'u')
		itoa_base_printf_unsigned(field->number, field->base, &field->str[field->len],
								  field->lennum);
	else
		itoa_base_printf(field->number, field->base, &field->str[field->len], field->lennum);
	/// заполнение нулями избыток точности
	if (tools->precision > field->lennum)
	{
		field->len -=  tools->precision - field->lennum;
		ft_memset(&field->str[field->len], '0', tools->precision - field->lennum);
	}
	set_flags(field, tools);


}
int 	make_field_diouxx(t_prsng *tools)
{
	t_mkfld field;

	get_field_values(&field, tools);
	if (tools->precision > field.lennum)
		field.len += tools->precision - field.lennum;
	field.len += define_flaglen(&field, tools);
	if (tools->field > field.lennum + field.len)
		field.len += tools->field - field.lennum;
	set_buff_diouxx(&field, tools);


	return (1);
}
