# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 11:35:58 by eslamber          #+#    #+#              #
#    Updated: 2024/02/21 09:46:24 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror -std=c++98

NAME := BraiiiiiiinnnzzzZ

HEADERS := Zombie.hpp
SRC := Zombie.cpp \
	   newZombie.cpp \
	   randomChump.cpp \
	   main.cpp
OBJ := $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@

#
### Debug rules
#

debug:
	make "FLAGS = -Wall -Wextra -Werror -g3"

ASan:
	make "FLAGS = -Wall -Wextra -Werror -fsanitize=address"

UBSan:
	make "FLAGS = -Wall -Wextra -Werror -fsanitize=undefined"

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ)

fclean: clean
	@rm -rfv $(NAME)

re: fclean all

re_deb: fclean debug

re_ASan: fclean ASan

re_UBSan: fclean UBSan

.PHONY: all clean fclean re debug re_deb
