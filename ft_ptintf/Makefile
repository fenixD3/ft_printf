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

SRC_GEN = ./srcs/
SRC_FLOAT = ./srcsFloat/
HEAD_PATH = ./includes/
LIB_PATH = ./libft/
#OBJS_PATH = ./tmp/

SRC_FILES_GEN = field_len.c ft_itoa_base_printf.c ft_printf.c is.c make_field.c parsing.c \
	set_buff.c to_buff.c

SRC_FILES_FLOAT = float_rounding.c get_dbl_values.c get_ldbl_values.c high_precision.c \
	high_precision_intf.c high_precision_intf_long.c high_precision_long.c print_reserve_dbl.c ft_log2.c ft_log10.c \
	my_float.c

SRCS_GEN = $(addprefix $(SRC_GEN),$(SRC_FILES_GEN))
SRCS_FLOAT = $(addprefix $(SRC_FLOAT),$(SRC_FILES_FLOAT))

OBJS = $(SRC_FILES_GEN:.c=.o) $(SRC_FILES_FLOAT:.c=.o)

print-%:
	@echo $*=$($*)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

$(OBJS):
	@gcc -c $(SRCS_GEN) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)
	@gcc -c $(SRCS_FLOAT) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all