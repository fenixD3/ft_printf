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
# define M_ZERO 8

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

typedef union	u_un
{
	int					i;
	unsigned int		ui;
	long 				l;
	unsigned long		ul;
	short				sh;
	unsigned short		ush;
	long long			ll;
	unsigned long long	ull;
	char				c;
	unsigned char		uc;
}				t_un;

typedef struct	s_mkfld
{
	size_t	lennum;
	size_t 	len;
	size_t 	len_empty_field;
	t_un	number;
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
size_t count_lennum(t_mkfld *field, t_prsng *tools);
int 	define_base_diouxx(t_prsng *tools);
int define_flaglen(t_mkfld *field, t_prsng *tools);

unsigned long long reverse_if_negative(t_un *number, t_prsng *tools);

/*////meh
char *itoa_base_printf(long long n, int base, char *str, int lennum);
char *itoa_base_printf_unsigned(unsigned long long n, int base, char *str, int lennum);*/
char *itoa_base_union(t_prsng *tools, t_mkfld *field, char *str);

_Bool	ft_putptr_buff(void *ptr, t_prsng *tools);

/// is
_Bool	is_signed(char c);
_Bool	is_typeflag(char c);
_Bool 	is_diouxx(char c);


#endif
