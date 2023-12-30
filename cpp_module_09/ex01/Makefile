NAME = RPN
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp \
	   RPN.cpp \
	   ./validator/ExpressionValidator.cpp \
	   ./calculator/RPNCalculator.cpp

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