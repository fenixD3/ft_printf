cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
file (GLOB SRC ft_ptintf/libft/*.c)

<<<<<<< HEAD
add_executable(ft_printf ${SRC} ft_ptintf/main.c ft_ptintf/ft_printf.c ft_ptintf/float.c ft_ptintf/ft_ptintf.h ft_ptintf/ft_putptr.c ft_ptintf/ft_itoa_base_printf.c ft_ptintf/parsing.c ft_ptintf/to_buff.c ft_ptintf/field_len.c ft_ptintf/make_field.c ft_ptintf/is.c ft_ptintf/set_buff.c ft_ptintf/print_float.c)
=======
add_executable(ft_printf ${SRC} ft_ptintf/main.c ft_ptintf/ft_printf.c ft_ptintf/ft_ptintf.h ft_ptintf/ft_itoa_base_printf.c ft_ptintf/parsing.c ft_ptintf/to_buff.c ft_ptintf/field_len.c ft_ptintf/make_field.c ft_ptintf/is.c ft_ptintf/set_buff.c)
>>>>>>> master
