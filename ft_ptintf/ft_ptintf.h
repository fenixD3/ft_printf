//
// Created by Mort Deanne on 2019-08-20.
//

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# define BUFF_SIZE 100

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
	int 	buff_count;
	char 	buff[BUFF_SIZE];
	va_list	ap;
}				t_prsng;

int		ft_printf(const char* format, ...);
void 	parsing(char **format, t_prsng *tools);


//// to libft
char	*ft_itoa_base(long long n, int base);
_Bool	ft_putptr(void *ptr, t_prsng *tools);




#endif
