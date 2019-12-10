//
// Created by Mort Deanne on 2019-08-20.
//

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <stdint.h>
# include <float.h>
# define BUFF_SIZE 10

# define M_MINUS 1
# define M_PLUS 2
# define M_SHARP 4
# define M_ZERO 8
# define M_SPACE 16
# define M_PRECISION_NOT_ADDED 32
# define M_ZERO_CHAR 64

# define M_HH 1
# define M_H 2
# define M_L 4
# define M_LL 8
# define M_UPPER_L 16


#define NON_FORMAT 0
#define FORMAT 1
#define LAST 2

# define LOG10_2 0.30103
# define get_binaryd(num, size) get_binary(num, size, 'i')

#include "libft/libft.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct	s_prsng
{
	char	flags;
	size_t	field;
	int 	precision;
	unsigned char 	modifiers;
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
	unsigned long long	ull; //for p -flag
	char				c; // for c -flag also
	unsigned char		uc;
	double				db;
	long double			ldb;

	char 				*cptr;
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

int 	parsing(char **format, t_prsng *tools);
void to_buff(char *str, t_prsng *tools, t_mkfld *field);
void add_str_to_buff(char **format, t_prsng *tools);

void	set_flags(t_mkfld *field, t_prsng *tools);

_Bool	set_buff(t_mkfld *fld, t_prsng *tls);
_Bool	set_buff_float(t_mkfld *fld, t_prsng *tls);
void	buffer_managment(t_prsng *tools, char *str, int len, int type_output);

void zeroing_tools(t_prsng *tools, _Bool zeroing_counter);

///make field
int 	organozation_by_flags_to_buff(t_prsng *tools);

///field_len
size_t count_lennum(t_mkfld *field, t_prsng *tools);
int 	define_base(t_prsng *tools);
int define_flaglen(t_mkfld *field, t_prsng *tools);

unsigned long long reverse_if_negative(t_un *number, t_prsng *tools);

char *itoa_base_union(t_prsng *tools, t_mkfld *field, char *str);


/// is
_Bool	is_signed(char c);
_Bool	is_typeflag(char c);
_Bool 	is_ddioouuxx(char c);
_Bool 	is_aaeeffgg(char c);
_Bool 	is_csp(char c);
_Bool	is_signflag(char c);
_Bool	is_modifiers(char c);
_Bool	is_flag(char c);


int which_sign(t_un *number, t_prsng *tools);


/// for double
char		*print_double(t_prsng *tools, t_mkfld *fld, double number);
double		ft_log2(long double num);
double		ft_log10(long double num);
char		*ft_reverse(char *str);
char		*print_long_double(t_prsng *tools, t_mkfld *fld,
								long double number);
double		ft_ceil(double num);
long double	ft_ceill(long double num);
double		ft_floor(double num);
long double	ft_floorl(long double num);
double		ft_round(double num);
long double	ft_roundl(long double num);
char		*get_binary(uint64_t *num, size_t bit_size, const char type,
						t_mkfld *fld);

#endif
