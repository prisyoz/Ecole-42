# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 02:12:42 by pang              #+#    #+#              #
#    Updated: 2026/07/02 22:32:08 by pang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serial
CC = c++
CFLAGS = -Wextra -Werror -Wall -std=c++98

OBJ_DIR = obj/

SRC = main.cpp Serialize.cpp 
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDES = Serialize.hpp Data.hpp

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

.PHONY: all clean fclean re