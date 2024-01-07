NAME = PmergeMe
CPP = c++
#CPPFLAGS = -Wall -Wextra -Werror -std=c++11	# TODO 수정!
CPPFLAGS = -std=c++11 # TODO 수정!
#CPPFLAGS = -std=c++11 -fsanitize=address
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp \
	   PmergeMe.cpp

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