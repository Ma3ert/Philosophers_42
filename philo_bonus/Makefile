# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 23:05:22 by yait-iaz          #+#    #+#              #
#    Updated: 2022/05/13 17:41:18 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c utils.c arg_checker.c philo_operation_bonus.c fork_operation_bonus.c \
	simulation_bonus.c time_status_bonus.c hostess_bonus.c extra_utils.c 
OBJ = $(SRC:.c=.o)
NAME = philo_bonus
HEADER = philosopher.h

CC = gcc

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -lpthread -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all