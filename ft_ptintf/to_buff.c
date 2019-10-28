//
// Created by Mort Deanne on 2019-08-22.
//

#include "ft_ptintf.h"

void	add_str_to_buff(char **format, t_prsng *tools)
{
	int len;
	int lenbuff;

	lenbuff = ft_strlen(tools->buff);
	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	if (len > BUFF_SIZE)
	{
		tools->counter += write(1, tools->buff, lenbuff);
		tools->buff[0] = '\0';
		tools->counter += write(1, *format, len);
	}
	else if (len < BUFF_SIZE - lenbuff)
		ft_strncat(tools->buff, *format, len);
	else
	{
		tools->counter += write(1, tools->buff, lenbuff);
		ft_strncpy(tools->buff, *format, len);
	}
	*format += len;
}

void to_buff(char *str, t_prsng *tools)
{
	int	len;
	int	lenbuff;

	len = ft_strlen(str);
	lenbuff = ft_strlen(tools->buff);
	if (len > BUFF_SIZE)
	{
		tools->counter += write(1, tools->buff, lenbuff);
		tools->buff[0] = '\0';
		tools->counter += write(1, str, len);
	}
	else if (len < BUFF_SIZE - lenbuff)
		ft_strcat(tools->buff, str);
	else
	{
		tools->counter += write(1, tools->buff, lenbuff);
		ft_strcpy(tools->buff, str);
	}
}