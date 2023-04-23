NAME = rush-02
SRCS = rush_02.c rm_spc.c ft_print.c create_list.c split.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

fclean:
	rm -f ${OBJS}

