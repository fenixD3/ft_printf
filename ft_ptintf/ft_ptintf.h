//
// Created by Mort Deanne on 2019-08-20.
//

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# define BUFF_SIZE 10

# define M_MINUS 1
# define M_PLUS 2
# define M_SHARP 4
# define M_NUL 8

# define M_HH 1
# define M_H 2
# define M_L 4
# define M_LL 8
# define M_UPPER_L 16

#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_prsng
{
	char	flags;
	int		field;
	int 	precision;
	char 	modifiers;
	char 	type;
	size_t	counter;
	char 	buff[BUFF_SIZE + 1];
	va_list	ap;
}				t_prsng;

typedef struct	s_mkfld
{
	int		lennum;
	int 	len;
	int		number;
	int		base;
	char	*str;
}				t_mkfld;

int		ft_printf(const char* format, ...);
void 	parsing(char **format, t_prsng *tools);
void	to_buff(char *str, t_prsng *tools);
void	add_str_to_buff(char **format, t_prsng *tools);

///make field
int 	make_field_diouxx(t_prsng *tools);

///field_len
int ft_lennum(long long n, int base);
int 	define_base(t_prsng *tools);
int define_flaglen(t_mkfld *field, t_prsng *tools);

////meh
char *itoa_base_printf(long long n, int base, char *str, int lennum);
char *itoa_base_printf_unsigned(unsigned long long n, int base, char *str, int lennum);

_Bool	ft_putptr_buff(void *ptr, t_prsng *tools);

/// is
_Bool is_signed(char c);


#endif
