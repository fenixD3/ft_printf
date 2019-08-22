//
// Created by Mort Deanne on 2019-08-20.
//

#include "ft_ptintf.h"

void		param_processing(char **format, t_prsng *tools)
{
	char *str;

	(*format)++;
	if (**format == '%')
		add_str_to_buff(format, tools);
	else
	{
		parsing(format, tools);
		if (**format == 'c')
			ft_putchar(va_arg(tools->ap, int)); // unsigned char??
		else if (**format == 's')
		{
			str = va_arg(tools->ap,char*); /// здесь выделяется память? Нужно фришить?
			ft_putstr(str);
			tools->counter += ft_strlen(str) - 1;
		}
		else if (tools->type == 'p')
		{
			if (!(ft_putptr_buff(va_arg(tools->ap, void*), tools)))
				exit(1);
		}
	}
}

void 	init_tools(t_prsng *tools)
{
	tools->flags = 0;
	tools->field = 0;
	tools->precision = 0;
	tools->type = 0;
	tools->counter = 0;
	tools->buff[0] = '\0';
}

int		ft_printf(char* format, ...)
{
	va_list	ap;
	t_prsng	tools;


	/// need validation????
	init_tools(&tools);
	va_start(tools.ap, format);
	while (*format)
	{
		if (*format == '%')
			param_processing(&format, &tools);
		else
			add_str_to_buff(&format, &tools);
	}
	va_end(tools.ap);
	write(1, tools.buff, ft_strlen(tools.buff));
	return (tools.counter);
}
