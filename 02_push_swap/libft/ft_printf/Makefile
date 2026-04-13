
CC = cc
CFLAGS = -Wextra -Werror -Wall

NAME = libftprintf.a

DEPS = ft_printf.h
SRC = ft_printf.c ft_characters.c ft_numbers.c common.c ft_hex.c ft_address.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
