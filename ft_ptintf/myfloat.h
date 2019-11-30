//
// Created by da.filiptsev on 13.11.2019.
//

#ifndef MYFLOAT_H
# define MYFLOAT_H

# include <stdint.h>
# include <string.h>
# define OFFSET_DBL 1023
# define OFFSET_LDBL 16383

typedef struct	s_dbl_comp
{
	_Bool		sign;
	int32_t		exp_val;
	uint64_t	mant_val;
	uint32_t	mant_High_Bits;
	uint32_t	mant_Low_Bits;
}				t_dbl_comp;

typedef struct	s_result
{
	char	*result;
	char 	*begin;
	size_t	len;
}				t_result;

_Bool			get_sign(uint64_t *dbl);
int32_t			get_exp(uint64_t *dbl);
uint64_t		get_mantissa(uint64_t *dbl);
_Bool			get_lsign(uint64_t *ldbl);
int32_t			get_lexp(uint64_t *ldbl);
uint64_t		get_lmantissa(uint64_t *ldbl);
char			*print_nan(t_result *res, _Bool sign);
char			*print_inf(t_result *res, _Bool sign);
char			*print_zero(t_result *res, _Bool sign);
void			check_result(t_result *res);
void			float_round(t_result *res, size_t *oft);

#endif
