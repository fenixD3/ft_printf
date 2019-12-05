//
// Created by da.filiptsev on 13.11.2019.
//

#ifndef MYFLOAT_H
# define MYFLOAT_H

# include <stdint.h>
# include <string.h>
# include "ft_ptintf.h"
# define OFFSET_DBL 1023
# define OFFSET_LDBL 16383
# define ABS(x) (x >= 0) ? x : -x

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
	ssize_t	len;
	int32_t	lg_10;
	char 	*buff;
	size_t	bf_len;
}				t_result;

_Bool			get_sign(uint64_t *dbl);
int32_t			get_exp(uint64_t *dbl);
uint64_t		get_mantissa(uint64_t *dbl);
_Bool			get_lsign(uint64_t *ldbl);
int32_t			get_lexp(uint64_t *ldbl);
uint64_t		get_lmantissa(uint64_t *ldbl);
char			*print_nan(t_result *res, const char type);
char			*print_inf(t_result *res, _Bool sign, const char type);
char			*print_zero(t_result *res, t_prsng *tools);
void			check_result(t_result *res);
void			float_round(t_result *res, const int nxt_nu, const int precision);
t_result		create_str(const int32_t lg_10, t_prsng *tools, t_mkfld *fld);
void			check_e_intg_res(t_result *res);
void			clear_res_buff(t_result *res);
void			fill_exp_chars(t_result *res, const char type);
void			add_point(t_result *res, t_prsng *tools);
void			fill_fucking_first_char(t_result *res, t_prsng *tools);

#endif
