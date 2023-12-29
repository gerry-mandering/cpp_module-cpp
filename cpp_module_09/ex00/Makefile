NAME = btc
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp \
		BitcoinExchange.cpp \
		./database/Database.cpp \
		./parser/Parser.cpp \
		./parser/ParserFactory.cpp \
		./parser/CSVParser.cpp \
		./parser/TXTParser.cpp \
		./validator/Validator.cpp \
		./validator/CSVValidator.cpp \
		./validator/TXTValidator.cpp \
		./util/StringTrimmer.cpp

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