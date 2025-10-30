# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 17:53:16 by pang              #+#    #+#              #
#    Updated: 2025/08/26 17:53:16 by pang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall

NAME = pipex
BONUS_NAME = pipex_bonus

DEPS = ./src/pipex.h
DEPS_BONUS = ./bonus/pipex_bonus.h

LIBFT_DIR = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR = ./libft/gnl

LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_LIB = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS = -L$(GNL_DIR) -lftgnl

INCLUDES = -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR)

all: $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB) $(NAME)

SRC_DIR = ./src/
SRC = command_process.c paths.c main.c utils.c quote_split.c main_helper.c quote_split_helper.c

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC:.c=.o)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(LIBFT_BONUS_LIB):
	make bonus -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	make -C $(FTPRINTF_DIR)

LIBFT_OBJ := $(LIBFT_DIR:.c=.o)
GNL_OBJ := $(GNL_OBJ:.c=.o)
FT_PRINTF_OBJ := $(FT_PRINTF_OBJ:.c=.o)

$(NAME): $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -f $(LIBFT_DIR)/src/*.o $(GNL_DIR)/*.o $(FTPRINTF_DIR)/*.o $(LIBFT_BONUS_DIR)/*.o
	rm -f $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
