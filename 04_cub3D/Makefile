# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 19:45:51 by pang              #+#    #+#              #
#    Updated: 2026/05/12 19:45:51 by pang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wextra -Werror -Wall

NAME    = cub3d

LIBFT_DIR    = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR      = ./libft/gnl
MLX_DIR      = ./mlx
MLX_URL      = https://github.com/42Paris/minilibx-linux
SRC_DIR      = src
OBJ_DIR      = obj
INC_DIR      = include

LIBFT_LIB     = $(LIBFT_DIR)/libft.a
GNL_LIB       = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

MLX_A         = $(MLX_DIR)/libmlx.a
MLX_LINUX_A   = $(MLX_DIR)/libmlx_Linux.a

MINILIBX_FLAGS = -L$(MLX_DIR) -lmlx -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT_FLAGS    = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS      = -L$(GNL_DIR) -lftgnl

HEADERS = $(INC_DIR)/cub3d.h \
          $(INC_DIR)/map.h

INCLUDES = -I$(SRC_DIR) \
           -I./$(INC_DIR) \
           -I$(LIBFT_DIR) \
           -I$(FTPRINTF_DIR) \
           -I$(GNL_DIR) \
           -I$(MLX_DIR)

SRC_FILES = main.c \
            map/start_parse.c \
            map/file_process.c \
            map/file_path.c \
            map/file_rgb.c \
            map/map_storage.c \
            map/map_validity.c \
            map/texture_validity.c \
            map/exit_utils.c \
            map/utils.c \
            game/init.c \
            game/events.c \
            game/move.c \
            render/render.c \
            render/raycast.c \
            render/draw.c \
            render/texture.c \
            mlx/mini.c \
            mlx/mini_mini.c

SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB) $(MLX_A) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS) -no-pie

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(MLX_A)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	@make -C $(FTPRINTF_DIR)

$(MLX_A):
	@if [ ! -f $(MLX_DIR)/configure ]; then \
		echo "Cloning minilibx-linux..."; \
		git clone $(MLX_URL) $(MLX_DIR); \
	fi
	@echo "Building mlx..."
	@cd $(MLX_DIR) && ./configure

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	-@[ -f $(MLX_DIR)/Makefile ] && make -C $(MLX_DIR) clean 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re