# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:39:49 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/19 18:43:39 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= do_op.c ft_atoi.c ft.c operators.c

NAME	= do-op

OBJS	= ${SRCS:.c=.o}

HEADERS	= includes/

FLAGS	= -Wall -Wextra -Werror

.c.o 	:
		gcc ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}	: ${OBJS}
		gcc ${FLAGS} -I ${HEADERS} -o ${NAME} ${OBJS} 

all		: ${NAME}

clean	:
		rm -f ${OBJS}

fclean	: clean
		rm -f ${NAME}

re		: fclean all