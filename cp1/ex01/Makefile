# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:59:24 by eslamber          #+#    #+#              #
#    Updated: 2023/03/15 16:17:25 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror

NAME := phone_book

HEADERS := class.hpp
SRC := contact.cpp \
	   phonebook.cpp \
	   main.cpp

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	c++ $(FLAGS) $(SRC) -o $@

#
### Cleanup rules
#

clean:
	rm -rfv $(NAME)

re: clean all

.PHONY: all clean re
