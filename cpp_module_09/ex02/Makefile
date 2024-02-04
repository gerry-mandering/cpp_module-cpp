NAME = PmergeMe
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp \
	   PmergeMe.cpp \
	   validator/ArgumentValidator.cpp \
	   sorter/VectorSorter.cpp \
	   sorter/DequeSorter.cpp

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