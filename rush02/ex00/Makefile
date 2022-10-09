# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 14:29:07 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/24 20:37:59 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c chained_list.c chained_list2.c dict_parsing.c ft.c join.c number_parsing.c split.c

NAME		= rush-02

GCC 		= gcc

FLAGS		= -Wall -Wextra -Werror

OBJS 		= ${SRCS:.c=.o}

.c.o:		
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all