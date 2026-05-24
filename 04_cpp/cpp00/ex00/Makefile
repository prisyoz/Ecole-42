CC = c++
CFLAGS = -Wextra -Werror -Wall  -std=c++98

NAME = megaphone

all: $(NAME)

SRC = megaphone.cpp

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC:.cpp=.o)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus