//
// Created by Mort Deanne on 2019-08-20.
//

#include "ft_ptintf.h"

void 	parsing_flags(char **format, t_prsng *tools)
{
	while (1)
	{
		if (**format == '-')
			tools->flags |= M_MINUS;
		else if (**format == '+')
			tools->flags |= M_PLUS;
		else if (**format == '#')
			tools->flags |= M_SHARP;
		else if (**format == '0')
			tools->flags |= M_ZERO;
		else if (**format == ' ')
			tools->flags |= M_SPACE;
		else if (!is_signflag(**format))
			break ;
		(*format)++;
	}
}

void	parsing_modifiers(char **format, t_prsng *tools)
{
	if (**format == 'h' && *(*format + 1) == 'h')
		tools->modifiers |= M_HH;
	else if (**format == 'l' && *(*format + 1) == 'l')
		tools->modifiers |= M_LL;
	else if (**format == 'h')
		tools->modifiers |= M_H;
	else if (**format =='l')
		tools->modifiers |= M_L;
	else if (**format == 'L')
		tools->modifiers |= M_UPPER_L;

	if (*(*format + 1) == 'h' || *(*format + 1) == 'l')
		(*format) += 2;
	else
		(*format)++;
}

void	parsing_field(char **format, t_prsng *tools)
{
	if (**format == '*')
		tools->field = va_arg(tools->ap, int);
	else
		tools->field = ft_atoi(*format);
	while ((**format >= '0' && **format <= '9') || **format == '*')
		(*format)++;
}

void	parsing_precision(char **format, t_prsng *tools)
{
	(*format)++;
	if (**format == '*')
		tools->precision = va_arg(tools->ap, int);
	else
		tools->precision = ft_atoi(*format);
	while ((**format >= '1' && **format <= '9') || **format == '*')
		(*format)++;
}

void	parsing_typeflag(char **format, t_prsng *tools)
{

	if (ft_islower(**format) || (**format != 'C' && **format != 'S'))
		tools->type = **format;
	else
	{
		tools->modifiers |= M_L;
		tools->type = ft_tolower(**format);
	}
	(*format)++;
}

int		parsing(char **format, t_prsng *tools)
{
	zeroing_tools(tools, 0);
	while (**format && is_flag(**format))
	{
		if (is_signflag(**format))
			parsing_flags(format, tools);
		else if (((**format >= '1' && **format <= '9') || **format == '*') && *(*format - 1) != '.')
			parsing_field(format, tools);
		else if (**format == '.')
			parsing_precision(format, tools);
		else if (is_modifiers(**format))
			parsing_modifiers(format, tools);
		else if (is_typeflag(**format))
			parsing_typeflag(format, tools);
	}
	if (!tools->type && **format)
		tools->type = *((*format)++);
	if (tools->precision != -1 && tools->flags & M_ZERO)
		tools->flags &= ~M_ZERO;
	if (tools->precision == -1)
	{
		tools->flags |= M_PRECISION;
		tools->precision++;
	}
	return (0);
}