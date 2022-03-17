# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2022/02/22 17:24:32 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

FLAGS = -std=c++98  #-Wall -Wextra -Werror -std=c++98

DEBUG =# -fsanitize=address

CP = c++

SRC = main.cpp

HEADER = 

all: $(NAME)
	./$(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CP) $(FLAGS) $(DEBUG) $(SRC) -o $(NAME)

clean:
	@echo "No object files to be cleaned!"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
