# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:55:12 by minseok2          #+#    #+#              #
#    Updated: 2023/06/19 16:56:03 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bank
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
SRCS =  tests.cpp\
		Account.cpp\

all: $(NAME)
$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: clean fclean all re
