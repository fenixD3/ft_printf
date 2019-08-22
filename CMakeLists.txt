cmake_minimum_required(VERSION 3.14)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
file (GLOB SRC ft_ptintf/libft/*.c)

add_executable(ft_printf ${SRC} ft_ptintf/main.c ft_ptintf/ft_printf.c ft_ptintf/ft_ptintf.h ft_ptintf/ft_putptr.c ft_ptintf/ft_itoa_base.c ft_ptintf/parsing.c ft_ptintf/to_buff.c ft_ptintf/field.c)