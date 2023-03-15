# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:59:24 by eslamber          #+#    #+#              #
#    Updated: 2023/03/15 16:03:50 by eslamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phone_book

HEADERS := 
SRC := 

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	c++ $(SRC) -o $@

#
### Cleanup rules
#

clean:
	rm -rfv $(NAME)

re: clean all

.PHONY: all clean re
