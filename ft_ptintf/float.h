#ifndef FLOAT_H
# define FLOAT_H

# include <stdint.h>

# define OFFSET64 1023
# define OFFSET80 16384

typedef struct	s_dbls
{
	_Bool		sign;
	uint32_t	exp;
	uint64_t	mant;
	uint64_t	val_mant;
	uint32_t	val_exp;
}				t_dbls;

#endif
