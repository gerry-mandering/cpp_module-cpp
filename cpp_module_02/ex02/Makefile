# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 18:28:41 by minseok2          #+#    #+#              #
#    Updated: 2023/06/26 18:28:41 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
SRCS =  main.cpp \
		Fixed.cpp \

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
