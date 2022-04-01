
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 00:43:14 by milmi             #+#    #+#              #
#    Updated: 2022/02/10 10:13:29 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container_test
NAMESTD = container_test_std

FLAGS = -Wall -Wextra -Werror -std=c++98

CP = c++

SRC = main.cpp

HEADER = map/map.hpp vector/vector.hpp stack/stack.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CP) -D STD=1 $(FLAGS) $(SRC) -o $(NAMESTD)
	$(CP) -D STD=0 $(FLAGS) $(SRC) -o $(NAME)

clean:
	@echo "No object files to be cleaned!"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAMESTD)

re: fclean all

.PHONY: all clean fclean re