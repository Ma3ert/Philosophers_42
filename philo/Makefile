# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:58:25 by yait-iaz          #+#    #+#              #
#    Updated: 2022/04/21 23:06:35 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c philo_operation.c simulation.c fork_operation.c arg_checker.c utils.c \
		time_status.c
OBJ = $(SRC:.c=.o)
NAME = philo
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