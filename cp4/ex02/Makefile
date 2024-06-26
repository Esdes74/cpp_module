# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 16:47:52 by eslamber          #+#    #+#              #
#    Updated: 2024/04/23 16:54:51 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror -std=c++98

NAME := Animal

HEADERS := Animal.hpp \
		   Brain.hpp \
		   Dog.hpp \
		   Cat.hpp \
		   WrongAnimal.hpp \
		   WrongCat.hpp
SRC := main.cpp \
	   Animal.cpp \
	   Brain.cpp \
	   Dog.cpp \
	   Cat.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp
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
	make "FLAGS = -Wall -Wextra -Werror -std=c++98 -g3"

ASan:
	make "FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3"

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
