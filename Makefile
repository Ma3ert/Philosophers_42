# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:58:25 by yait-iaz          #+#    #+#              #
#    Updated: 2022/04/12 23:04:04 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c philo_operation.c simulation.c fork_operation.c arg_checker.c utils.c \
		time_status.c
SRC_B = 
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = philo
BONUS = philo_bonus
HEADER = philosopher.h

CC = gcc

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_B) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_B)  -o $(BONUS)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -lpthread -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all