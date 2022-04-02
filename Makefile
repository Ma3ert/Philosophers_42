# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:58:25 by yait-iaz          #+#    #+#              #
#    Updated: 2022/03/22 19:01:08 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c
SRC_B = 
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
NAME = philo
BONUS = philo_bonus
HEADER = philosopher.h

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_B) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_B) -o $(BONUS)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all