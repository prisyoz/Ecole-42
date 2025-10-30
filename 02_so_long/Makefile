CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long
BONUS_NAME = so_long_bonus

BONUS = ./bonus
MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR = ./libft/gnl

LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_LIB = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/libmlx.a

MINILIBX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS = -L$(GNL_DIR) -lftgnl

INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR)
BONUS_INCLUDES = -I$(MLX_DIR) -I$(BONUS) -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR)

SRC_DIR = ./src/
SRC = img_loading.c img_utils.c keypress_eventhandle.c main.c \
      map_check_utils.c map_common_utils.c map_helper.c map_process.c map_route_check.c \
      map_validity.c img_hack.c

BONUS_SRC_DIR = ./bonus/src_bonus/
BONUS_SRC = img_loading_bonus.c img_utils_bonus.c keypress_eventhandle_bonus.c keypress_movement_bonus.c \
      main_bonus.c map_check_utils_bonus.c map_common_utils_bonus.c map_helper_bonus.c map_process_bonus.c \
      map_route_check_bonus.c map_validity_bonus.c img_hack_bonus.c img_animationload_bonus.c \
      enemy_movement.c enemy_init.c

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC:.c=.o)

BONUS_SRC := $(addprefix $(BONUS_SRC_DIR), $(BONUS_SRC))
BONUS_OBJ := $(BONUS_SRC:.c=.o)

all: $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB) $(NAME)

# Build MiniLibX
$(MLX_LIB):
	make -C $(MLX_DIR)

# Build Libft, GNL, FT_PRINTF
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	make -C $(FTPRINTF_DIR)

# Build main executable
$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS)

$(BONUS_SRC_DIR)%.o: $(BONUS_SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INCLUDES)

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(MLX_DIR) clean

# Full clean
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB) $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re bonus
