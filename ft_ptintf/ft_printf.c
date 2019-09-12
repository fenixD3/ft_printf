//
// Created by Mort Deanne on 2019-08-20.
//

#include "ft_ptintf.h"

void		param_processing(char **format, t_prsng *tools)
{
	(*format)++;
	if (!parsing(format, tools))
		;
	organozation_by_flags_to_buff(tools);
}

void 	zeroing_tools(t_prsng *tools)
{
	tools->flags = 0;
	tools->field = 0;
	tools->precision = -1;
	tools->modifiers = 0;
	tools->type = 0;
	tools->counter = 0;
}

int		ft_printf(const char* format, ...)
{
	va_list	ap;
	t_prsng	tools;
	char	*f_not_const;

	f_not_const = (char*)format;
	zeroing_tools(&tools);
	tools.buff[0] = '\0';
	va_start(tools.ap, format);
	while (*f_not_const)
	{
		if (*f_not_const == '%')
			param_processing(&f_not_const, &tools);
		else
			add_str_to_buff(&f_not_const, &tools);
	}
	va_end(tools.ap);

	write(1, tools.buff, ft_strlen(tools.buff));
	return (tools.counter);
}
