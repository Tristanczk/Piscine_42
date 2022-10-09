SRCS	= main.c

NAME	= ft_display_file

OBJS	= ${SRCS:.c=.o}

FLAGS	= -Wall -Wextra -Werror

.c.o	:
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}	: ${OBJS}
		gcc ${FLAGS} -o ${NAME} ${OBJS}

all		: ${NAME}

clean	:
		rm -f ${OBJS}

fclean	: clean
		rm -f ${NAME}