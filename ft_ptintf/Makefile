
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylila <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 03:21:36 by ylila             #+#    #+#              #
#    Updated: 2019/08/17 21:15:43 by mdeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB_NAME = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./
HEAD_PATH = ./
LIB_PATH = ./libft/

SRC_FILES = check_float_res.c field_len.c float_rounding.c ft_ceil.c ft_floor.c ft_itoa_base_printf.c ft_log10.c \
    ft_log2.c ft_printf.c ft_reverse.c ft_round.c get_dbl_values.c get_ldbl_values.c high_precision.c \
    high_precision_intf.c high_precision_intf_long.c high_precision_long.c is.c make_field.c my_float.c parsing.c \
    print_reserve_dbl.c set_buff.c to_buff.c

SRCS = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS):
	@gcc -c $(SRCS) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all