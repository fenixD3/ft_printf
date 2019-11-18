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

//# define div_ret_remainder(hp) div_ret_remainder(hp, 10)

#include <stdio.h>

typedef struct	u_high
{
	unsigned	data_intg[ARRSIZE_INTG_DBL];
	unsigned	data_frct[ARRSIZE_FRCT_DBL];
	const int	word_shift;
	_Bool		intg;
}				t_high;

t_high			*hp_initializ(void);
_Bool			hp_is_zero(t_high *hp, _Bool intg);
void			insert_low_bits(t_high *hp, uint32_t value, int shift_amount, _Bool intg);
void			insert_top_bits(t_high *hp, uint32_t value, int shift_amount, _Bool intg);
uint32_t		div_ret_remainder(t_high *hp, uint32_t divisor);
uint32_t		mul_ret_overflow(t_high *hp, uint32_t multipl);
char			*fill_result(char *result, t_high *hp, _Bool intg);

#endif
