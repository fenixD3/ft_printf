//
// Created by Mort Deanne on 2019-08-25.
//

#include "ft_ptintf.h"

_Bool is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'f' || c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'F' || c == 'g' || c == 'G')
		return (1);
	return (0);
}

_Bool	is_typeflag(char c)
{
	if (is_csp(c) || is_ddioouuxx(c) || is_aaeeffgg(c))
		return (1);
	return (0);
}

_Bool 	is_ddioouuxx(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'D' || c == 'O' || c == 'U')
		return (1);
	return (0);
}

_Bool 	is_aaeeffgg(char c)
{
	if (c == 'f' /*aAeEFgG*/)
		return (1);
	return (0);
}

_Bool 	is_csp(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	return (0);
}

_Bool	is_signflag(char c)
{
	if (c == '0' || c == '+' || c == '-' || c == '#' || c == ' ')
		return (1);
	return (0);
}

_Bool	is_modifiers(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

_Bool	is_flag(char c)
{
	if (is_typeflag(c) || is_signflag(c) || ft_isdigit(c) || c == '.' || is_modifiers(c))
		return (1);
	return (0);
}

int		which_sign(t_un *number, t_prsng *tools)
{
	if (!is_aaeeffgg(tools->type))
	{
		if ((tools->modifiers == 0 && number->i < 0) ||
			(tools->modifiers & M_L && number->l < 0) ||
			(tools->modifiers & M_H && number->sh < 0) ||
			(tools->modifiers & M_LL && number->ll < 0) ||
			(tools->modifiers & M_HH && number->c < 0))
			return (-1);
		else if ((tools->modifiers == 0 && number->i > 0) ||
			(tools->modifiers & M_L && number->l > 0) ||
			(tools->modifiers & M_H && number->sh > 0) ||
			(tools->modifiers & M_LL && number->ll > 0) ||
			(tools->modifiers & M_HH && number->c > 0))
			return (1);
	}
	else
	{
		if (((tools->modifiers == 0 || tools->modifiers & M_L)
			&& number->db < 0) ||
			(tools->modifiers & M_UPPER_L && number->ldb < 0))
			return (-1);
		else if (((tools->modifiers == 0 || tools->modifiers & M_L)
				  && number->db > 0) ||
				 (tools->modifiers & M_UPPER_L && number->ldb > 0))
			return (1);
	}
	return (0);
}