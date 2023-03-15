# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:50:23 by eslamber          #+#    #+#              #
#    Updated: 2023/03/15 16:11:15 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS := -Wall -Wextra -Werror

NAME := megaphone

SRC := megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $@

#
### Cleanup rules
#

clean:
	@rm -rfv $(NAME)

re: clean all

.PHONY: all clean all
