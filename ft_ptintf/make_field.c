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
	else if (tools->modifiers & M_HH && tools->type == 'u')
		field->number.uc = (unsigned char)va_arg(tools->ap, unsigned int);
	else if (tools->modifiers & M_HH)
		field->number.c = (char)va_arg(tools->ap, int);

	/////////////////////////??????
}

_Bool	fill_union_csp(t_mkfld *field, t_prsng *tools)
{
	field->number.ull = 0;

	if (tools->type == 'c')
	{
		if((field->number.c = (char)va_arg(tools->ap, int)) == 0)
			tools->flags |= M_ZERO_CHAR; //  we need it?
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

	if (tools->modifiers & M_UPPER_L)
		field->number.ldb = va_arg(tools->ap, long double);
	else
		field->number.db = va_arg(tools->ap, double);
}

void	set_flags(t_mkfld *field, t_prsng *tools)
{
	if (tools->flags & M_SHARP && tools->type == 'o' && field->lennum >= (size_t)tools->precision && which_sign(&field->number, tools) != 0)
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
	else if (/*(tools->flags & M_SHARP) && */tools->type == 'p')
	{
		ft_strncpy(&field->str[field->len - 2], "0x", 2);
		field->len -= 2;
	}
	/** дополнить # для других флагов*/

	if (tools->flags & M_ZERO)
	{
		while (field->len)
			field->str[--field->len] = '0';
		if ((tools->flags & M_PLUS && field->number.i >= 0) ||
				which_sign(&field->number, tools) < 0 || tools->flags & M_SPACE)
			field->len++;
	}
	/** дополнить для других флагов кроме diouxX*/

	/** пишем поверх нулей "0x"*/
	if ((tools->flags & M_SHARP && (tools->flags & M_ZERO) != 0 &&
			  ((tools->type == 'x' || tools->type == 'X') && field->number.i)))
	{
		field->str[0] = '0';
		field->str[1] = tools->type;
		field->len -= 2;
	}


	if (tools->flags & M_PLUS &&  is_signed(tools->type) && which_sign(&field->number, tools) >= 0)
		field->str[--field->len] = '+';
	else if (is_signed(tools->type) && which_sign(&field->number, tools) < 0)
		field->str[--field->len] = '-';
	else if (tools->flags & M_SPACE)
		field->str[--field->len] = ' ';

}





void	len_counting_diouxxcsp(t_prsng *tools, t_mkfld *field)
{
	if ((tools->precision > 0 && (size_t)tools->precision > field->lennum)
		&& tools->type != 's'
		&& tools->type != 'c')
		field->len += tools->precision - field->lennum;
	field->len += define_flaglen(field, tools);
	if (tools->field > field->lennum + field->len)
		field->len_empty_field = tools->field - field->lennum - field->len;
	field->len += field->len_empty_field;
}

void	prepare_diouxxcsp(t_prsng *tools, t_mkfld *field)
{
	if (is_ddioouuxx(tools->type))
		fill_union_diouxx(field, tools);
	else if (is_csp(tools->type))
		fill_union_csp(field, tools); /// need protection strdup (malloc)

	field->base = define_base(tools);

	if (tools->type && (tools->type == 'c' || !is_flag(tools->type)))
		field->lennum = 1;

/*	else if ((((is_ddioouuxx(tools->type) && tools->type != 'o' && !which_sign(&field->number, tools)) || tools->type == 'p') || (tools->type == 'o' && !(tools->flags & M_SHARP))) && (!tools->precision && !(tools->flags & M_PRECISION_NOT_ADDED)))
		field->lennum = 0;*/

	else if (((is_ddioouuxx(tools->type) && tools->type != 'o' && !which_sign(&field->number, tools)) || tools->type == 'p') && (!tools->precision && !(tools->flags & M_PRECISION_NOT_ADDED)))
		field->lennum = 0;
	else if (tools->type == 'o' && !(tools->flags & M_SHARP) && (!tools->precision && !(tools->flags & M_PRECISION_NOT_ADDED)))
		field->lennum = 0;

	else if (tools->type == 's')
		{
			field->lennum = ft_strlen(field->number.cptr);
			if (field->lennum > (size_t)tools->precision && !(tools->flags & M_PRECISION_NOT_ADDED))
				field->lennum = tools->precision;
		}
	else if (is_ddioouuxx(tools->type) || tools->type == 'p')
			field->lennum = count_lennum(field, tools);

	len_counting_diouxxcsp(tools, field);
}

void	prepare_aaeeffgg(t_prsng *tools, t_mkfld *field)
{
	fill_union_aaeeffgg(field, tools);
	///вызов PrintDouble/LDouble(tools, field->number.db(ldb));
	///protect
	if (tools->modifiers & M_UPPER_L)
		field->str = print_long_double(tools, field, field->number.ldb);
	else if (tools->modifiers & M_L || !tools->modifiers)
		field->str = print_double(tools, field, field->number.db);

	/// delete this
	field->lennum = strlen(field->str);
	///////////////

	if (field->lennum < tools->field)
		field->len = tools->field - field->lennum ;
	else if (field->lennum >= tools->field && (tools->flags & M_SPACE || tools->flags & M_PLUS || which_sign(&field->number, tools) < 0))
		field->len++;
}

void	zeroing_mkfield(t_mkfld *fld)
{
	fld->base = 0;
	fld->len = 0;
	fld->len_empty_field = 0;
	fld->lennum = 0;
	fld->number.i = 0;
	fld->str = NULL;
}

int 	organozation_by_flags_to_buff(t_prsng *tools)
{
	t_mkfld field;

	zeroing_mkfield(&field);
	if (is_aaeeffgg(tools->type))
	{
		prepare_aaeeffgg(tools, &field);
		if (tools->type && !set_buff_float(&field, tools))
			return (0);
	}
	else if (is_ddioouuxx(tools->type) || is_csp(tools->type) || !is_flag(tools->type))
	{
		prepare_diouxxcsp(tools, &field);
		if (tools->type && !set_buff(&field, tools))
			return (0);
	}
	return (1);
}
