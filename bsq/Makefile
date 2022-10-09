# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 19:14:35 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/27 08:26:15 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c basics_functions.c file_parsing.c handle.c numbers.c print_matrix.c solve.c split.c verif_map.c std_input.c

NAME		= bsq

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

.PHONY:		all clean fclean re