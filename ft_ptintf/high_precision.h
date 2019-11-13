//
// Created by da.filiptsev on 13.11.2019.
//

#ifndef DTOA_HIGH_PRECISION_H
# define DTOA_HIGH_PRECISION_H

# define ARRSIZE_INTG_DBL 32
# define ARRSIZE_FRCT_DBL 34
# include <stdlib.h>
# include "libft/libft.h"

#include <stdio.h>

typedef struct	s_high
{
	unsigned data_intg[ARRSIZE_INTG_DBL];
	unsigned data_frct[ARRSIZE_FRCT_DBL];
}				t_high;

t_high			hp_initialz(_Bool intg);
_Bool			is_zero(t_high *hp, _Bool intg);

#endif
