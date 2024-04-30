# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 14:01:21 by eslamber          #+#    #+#              #
#    Updated: 2024/04/30 19:26:36 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror -std=c++98

NAME := Bureaucrat

HEADERS := AForm.hpp \
		   Bureaucrat.hpp \
		   PresidentialPardonForm.hpp \
		   RobotomyRequestForm.hpp \
		   ShrubberyCreationForm.hpp
SRC := main.cpp \
	   AForm.cpp \
	   Bureaucrat.cpp \
	   PresidentialPardonForm.cpp \
	   RobotomyRequestForm.cpp \
	   ShrubberyCreationForm.cpp
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
	make "FLAGS = -Wall -Wextra -Werror -fsanitize=address"

UBSan:
	make "FLAGS = -Wall -Wextra -Werror -fsanitize=undefined"

#
### Cleanup rules
#

clean:
	@rm -rfv $(OBJ)

fclean: clean
	@rm -rfv $(NAME) *_shrubbery

re: fclean all

re_deb: fclean debug

re_ASan: fclean ASan

re_UBSan: fclean UBSan

.PHONY: all clean fclean re debug re_deb
