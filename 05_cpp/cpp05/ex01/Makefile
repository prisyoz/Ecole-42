NAME = bureaucrat
CC = c++
CFLAGS = -Wextra -Werror -Wall  -std=c++98

OBJ_DIR = obj/

SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDES = Bureaucrat.hpp Form.hpp

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
$(OBJ_DIR)%.o: %.cpp $(INCLUDES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus