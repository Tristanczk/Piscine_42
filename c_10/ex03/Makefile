# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 12:48:02 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/28 14:41:48 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_hexdump.c arg_parsing.c display_file.c ft.c ft2.c manage_error.c print_memory.c

NAME		= ft_hexdump

FLAGS		= -Wall -Wextra -Werror -g3

GCC			= gcc

OBJS		= ${SRCS:.c=.o}

.c.o:	
			${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all