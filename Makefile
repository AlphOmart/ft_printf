NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
HDRS = printf.h

SRC_PART =	./ft_printf.c\
			./ft_print_str.c\
			./ft_print_nbr.c

OBJ_SRC = $(SRC_PART:.c=.o)

all :$(NAME)

$(NAME):	$(OBJ_SRC)
	ar -rcs $(NAME) $(OBJ_SRC)

%.o : %.c $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_SRC)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
