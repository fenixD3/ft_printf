NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = field_len.c \
       ft_itoa_base_printf.c \
       ft_printf.c \
       is.c \
       make_field.c parsing.c set_buff.c to_buff.c

OBJECTS = $(SRCS:.c=.o)

INCLUDE = libft/libft.a

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(FLAGS) -I$(INCLUDE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
