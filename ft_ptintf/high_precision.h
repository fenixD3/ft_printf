//
// Created by da.filiptsev on 13.11.2019.
//

#ifndef DTOA_HIGH_PRECISION_H
# define DTOA_HIGH_PRECISION_H

# define ARRSIZE_INTG_DBL 32
# define ARRSIZE_FRCT_DBL 34
# define ARRSIZE_INTG_LDBL 512
# define ARRSIZE_FRCT_LDBL 514
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"
# include "ft_ptintf.h"

#include <stdio.h>

typedef struct	u_high
{
	unsigned	data_intg[ARRSIZE_INTG_DBL];
	unsigned	data_frct[ARRSIZE_FRCT_DBL];
	const int	word_shift;
	_Bool		intg;
}				t_high;

typedef struct	u_highl
{
	unsigned	data_intg[ARRSIZE_INTG_LDBL];
	unsigned	data_frct[ARRSIZE_FRCT_LDBL];
	const int	word_shift;
	_Bool		intg;
}				t_highl;

t_high			*hp_initializ(void);
t_highl			*hp_ldbl_initializ(void);
_Bool			hp_is_zero(t_high *hp, _Bool intg);
_Bool			hp_is_lzero(t_highl *hp, _Bool intg);
void			insert_low_bits(t_high *hp, uint32_t value, int shift_amount, _Bool intg);
void			insert_low_lbits(t_highl *hp, uint32_t value, int32_t shift_amount, _Bool intg);
void			insert_top_bits(t_high *hp, uint32_t value, int shift_amount, _Bool intg);
void			insert_top_lbits(t_highl *hp, uint32_t value, int shift_amount, _Bool intg);
uint32_t		div_ret_remainder(t_high *hp, uint32_t divisor);
uint32_t		div_ret_lremainder(t_highl *hp, uint32_t divisor);
uint32_t		mul_ret_overflow(t_high *hp, uint32_t multipl);
uint32_t		mul_ret_loverflow(t_highl *hp, uint32_t multipl);
void			fill_result(char *result, t_high *hp, _Bool intg, int precision);
char			*fill_lresult(char *result, t_highl *hp, _Bool intg);

#endif
