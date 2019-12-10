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
OBJS_PATH = ./tmp/

SRC_FILES_GEN = field_len.c ft_itoa_base_printf.c ft_printf.c is.c make_field.c parsing.c \
	set_buff.c to_buff.c

SRC_FILES_FLOAT = float_rounding.c get_dbl_values.c get_ldbl_values.c high_precision.c \
	high_precision_intf.c high_precision_intf_long.c high_precision_long.c print_reserve_dbl.c ft_log2.c ft_log10.c \
	my_float.c

SRCS_GEN = $(addprefix $(SRC_GEN),$(SRC_FILES_GEN))
SRCS_FLOAT = $(addprefix $(SRC_FLOAT),$(SRC_FILES_FLOAT))

#OBJS = $(addprefix $(OBJS_PATH),$(SRC_FILES_GEN:.c=.o)) $(addprefix $(OBJS_PATH),$(SRC_FILES_FLOAT:.c=.o))
OBJS_GEN = $(addprefix $(OBJS_PATH),$(SRC_FILES_GEN:.c=.o))
OBJS_FLOAT = $(addprefix $(OBJS_PATH),$(SRC_FILES_FLOAT:.c=.o))

print-%:
	@echo $*=$($*)

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS_GEN) $(OBJS_FLOAT)
	@ranlib $(NAME)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

#$(OBJS):

$(OBJS_GEN):
	@mkdir -p $(OBJS_PATH)
	@gcc -c $(SRCS_GEN) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(OBJS_FLOAT):
	@mkdir -p $(OBJS_PATH)
	@gcc -c $(SRCS_FLOAT) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

#$(OBJS):
#	@mkdir -p $(OBJS_PATH)
#	@gcc -c $(SRCS_GEN) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)
#	@gcc -c $(SRCS_FLOAT) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

clean:
	@rm -f $(OBJS_GEN) $(OBJS_FLOAT)
	@rm -rf $(OBJS_PATH)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all