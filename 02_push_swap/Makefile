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

NAME = push_swap
BONUS_NAME = checker

DEPS = push_swap.h
BONUS_DEPS = push_swap_bonus.h

LIBFT_DIR = ./libft/libft01
LIBFT_BONUS_DIR = ./libft/libft01/bonus
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR = ./libft/gnl

LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_BONUS_LIB = $(LIBFT_DIR)/libft_bonus.a
GNL_LIB = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS = -L$(GNL_DIR) -lftgnl

INCLUDES = -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_BONUS_DIR)
BONUS_INCLUDES = -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_BONUS_DIR)

all: $(LIBFT_LIB) $(LIBFT_BONUS_LIB) $(GNL_LIB) $(FT_PRINTF_LIB) $(NAME)

SRC_DIR = ./src/
SRC = push_instructions_1.c push_instructions_2.c push_instructions_3.c push_instructions_write.c push_main.c \
		push_utils.c push_validity.c push_argumentcheck.c push_create_nodes.c push_basic_sort.c push_main_helper.c \
		push_sort_helper.c push_sort_array.c push_sort_data.c push_lis.c push_first_push_b.c push_first_push_b_helper.c \
		push_sort_to_a_cal.c push_push_back_a.c push_sort_to_a_cal2.c 

BONUS_SRC_DIR = ./bonus/
BONUS_SRC = push_bonus_main.c push_bonus_main_helper.c push_bonus_utils.c push_bonus_argumentcheck.c push_bonus_create_nodes.c \
				push_bonus_validity.c push_bonus_instructions_1.c push_bonus_instructions_2.c push_bonus_instructions_3.c push_bonus_stdin.c

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC:.c=.o)

BONUS_SRC := $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC))
BONUS_OBJ := $(BONUS_SRC:.c=.o)

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

$(NAME): $(OBJ) $(LIBFT_LIB) $(LIBFT_BONUS_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_LIB) $(LIBFT_BONUS_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

bonus: $(BONUS_NAME)
$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -f $(LIBFT_DIR)/src/*.o $(GNL_DIR)/*.o $(FTPRINTF_DIR)/*.o $(LIBFT_BONUS_DIR)/*.o
	rm -f $(LIBFT_LIB) $(LIBFT_BONUS_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
