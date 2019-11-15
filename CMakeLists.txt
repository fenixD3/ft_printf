cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
file (GLOB SRC ft_ptintf/libft/*.c)


add_executable(ft_printf ${SRC} ft_ptintf/main.c ft_ptintf/ft_printf.c ft_ptintf/ft_ptintf.h ft_ptintf/ft_itoa_base_printf.c
        ft_ptintf/parsing.c ft_ptintf/to_buff.c ft_ptintf/field_len.c ft_ptintf/make_field.c ft_ptintf/is.c ft_ptintf/set_buff.c
        ft_ptintf/myfloat.h ft_ptintf/get_dbl_values.c ft_ptintf/high_precision.c ft_ptintf/high_precision.h
        ft_ptintf/print_reserve_dbl.c ft_ptintf/my_float.c ft_ptintf/high_precision_intf.c)
