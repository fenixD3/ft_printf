//
// Created by Mort Deanne on 2019-08-22.
//

#include "ft_ptintf.h"

void	zeroing_buf(char *str, size_t i)
{
	while (i < BUFF_SIZE)
		str[i++] = '\0';
}

char	*strncropcat(char *dst_start, char *src, int n)
{
	size_t	i;
	char	*s1_ret;

	s1_ret = dst_start;
	i = 0;
	while (src[i] && i < n)
	{
		*dst_start++ = src[i];
		i++;
	}
	*dst_start = '\0';
	return (s1_ret);
}


void	buff_fill_selection(char *str, t_prsng *tools, int len, int zerochar)
{
	int lenbuff;

	lenbuff = ft_strlen(tools->buff);
	if (tools->flags & M_OLD_FLAG_CHAR)
		lenbuff++;
	while (str[len] && str[len] != '%')
		len++;
	if (len > BUFF_SIZE)
	{
		tools->counter += write(1, tools->buff, lenbuff);
		zeroing_buf(tools->buff ,0);
		tools->counter += write(1, str, len);
	}
	else if (len < BUFF_SIZE - lenbuff)
		strncropcat(ft_strchr(tools->buff, '\0') + zerochar, str, len);
//		ft_strncat(tools->buff, str, len);
	else
	{
		tools->counter += write(1, tools->buff, lenbuff);
		zeroing_buf(tools->buff, len);
		ft_strncpy(tools->buff, str, len);
	}
}

void add_str_to_buff(char **format, t_prsng *tools)
{
	int len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;

	buff_fill_selection(*format, tools, len, (tools->flags & M_OLD_FLAG_CHAR ? 1 : 0));
	*format += len;
	tools->flags &= ~M_OLD_FLAG_CHAR;
}

void to_buff(char *str, t_prsng *tools, t_mkfld *field) {
	int	len;

	len = ft_strlen(str);
	buff_fill_selection(str, tools, len, 0);
	(tools->type == 'c' && !field->number.c) ?
	(tools->flags |= M_OLD_FLAG_CHAR) : (tools->flags &= ~M_OLD_FLAG_CHAR);
}

/*
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
		zeroing_buf(tools->buff ,0);
		tools->counter += write(1, *format, len);
	}
	else if (len < BUFF_SIZE - lenbuff)
		ft_strncat(tools->buff, *format, len);
	else
	{
		tools->counter += write(1, tools->buff, lenbuff);
		zeroing_buf(tools->buff, len);
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
		zeroing_buf(tools->buff, 0);
		tools->counter += write(1, str, len);
	}
	else if (len < BUFF_SIZE - lenbuff)
		ft_strcat(tools->buff, str);
	else
	{
		tools->counter += write(1, tools->buff, lenbuff);
		zeroing_buf(tools->buff, len);
		ft_strcpy(tools->buff, str);
	}
}*/
