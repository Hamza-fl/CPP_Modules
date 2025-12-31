NAME = ex01
SRCS = main.cpp Bureaucrat.cpp Form.cpp
HEADERS = Bureaucrat.hpp Form.hpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re