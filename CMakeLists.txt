cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

file (GLOB SRC ft_ptintf/libft/*.c)

add_executable(ft_printf ${SRC} ft_ptintf/main.c ft_ptintf/ft_printf.c
        ft_ptintf/ft_ptintf.h
        ft_ptintf/ft_itoa_base_printf.c ft_ptintf/parsing.c ft_ptintf/to_buff.c
        ft_ptintf/field_len.c ft_ptintf/make_field.c ft_ptintf/is.c
        ft_ptintf/set_buff.c ft_ptintf/ft_log2.c 
        ft_ptintf/ft_reverse.c
        ft_ptintf/get_dbl_values.c
        ft_ptintf/get_ldbl_values.c
        ft_ptintf/high_precision.c
        ft_ptintf/high_precision.h
        ft_ptintf/high_precision_intf.c
        ft_ptintf/my_float.c
        ft_ptintf/myfloat.h
        ft_ptintf/print_reserve_dbl.c
		ft_ptintf/ft_ceil.c ft_ptintf/high_precision_intf_long.c ft_ptintf/high_precision_long.c ft_ptintf/ft_log10.c ft_ptintf/ft_floor.c ft_ptintf/ft_round.c ft_ptintf/check_float_res.c ft_ptintf/float_rounding.c)
