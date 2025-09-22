SRCS = *.cpp
OBJS = *.o
INCS = .
NAME = a.out
CC = c++ -Wall -Werror -Wextra

all : ${NAME}

${NAME} :
	${CC} -c -I${INCS} ${SRCS}
	${CC} ${OBJS} -o ${NAME}

clean :
	rm -rf ${OBJS}

fclean :
	rm -rf ${OBJS}
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean re bonus