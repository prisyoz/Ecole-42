NAME = animal
CC = c++
CFLAGS = -Wextra -Werror -Wall  -std=c++98

OBJ_DIR = obj/

SRC = Animal.cpp Dog.cpp main.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDES = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

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