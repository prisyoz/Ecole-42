# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pang@student.42singapore.sg <pang>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 14:37:34 by pang@studen       #+#    #+#              #
#    Updated: 2025/10/29 14:37:34 by pang@studen      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall

NAME = philo

DEPS = philo.h

all: $(NAME)

SRC = philo_init.c philo_main.c philo_parse.c philo_routine.c philo_time.c philo_utils.c philo_death.c philo_fork.c philo_ticket.c philo_free.c philo_food.c

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(SRC:.c=.o)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
