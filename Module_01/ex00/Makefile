NAME = zombie
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
HEADERS = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	c++ -Wall -Wextra -Werror $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	c++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re