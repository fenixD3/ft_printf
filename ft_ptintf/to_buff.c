//
// Created by Mort Deanne on 2019-08-22.
//

#include "ft_ptintf.h"

char *ft_strncropcat(char *dst_start, char *src, size_t n)
{
	size_t	i;
	char	*s1_ret;

	s1_ret = dst_start;
	i = 0;
	while (i < n)
	{
		*dst_start++ = src[i];
		i++;
	}
	return (s1_ret);
}

void	write_str(t_prsng *tools, char *str, int *len)
{

	tools->counter += write(1, str, *len);
	ft_bzero(str, *len);
	*len = 0;
}

void	buffer_managment(t_prsng *tools, char *str, int len, _Bool last_output)
{
	static int lenbuf;

	if (len + lenbuf >= BUFF_SIZE || last_output)
		write_str(tools, tools->buff, &lenbuf);
	if (len >= BUFF_SIZE && !last_output)
		write_str(tools, str, &len);
	else if (!last_output)
	{
		if (lenbuf == 1)
			memset(&tools->buff[lenbuf], '*', BUFF_SIZE - lenbuf);
		ft_strncropcat(&tools->buff[lenbuf], str, len);
		lenbuf += len;
		tools->flags &= ~M_ZERO_CHAR;
	}

}

void add_str_to_buff(char **format, t_prsng *tools)
{
	int len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	buffer_managment(tools, *format, len, 0);
	*format += len;
}

void to_buff(char *str, t_prsng *tools, t_mkfld *field) {
	int	len;

	len = ft_strlen(str) + ((tools->type == 'c' && !field->number.c) ? 1 : 0);
	buffer_managment(tools, str, len, 0);

}

