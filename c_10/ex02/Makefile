# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 12:15:59 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/27 12:48:28 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_tail.c check_args.c display_file.c error_management.c ft.c

NAME		= ft_tail

FLAGS		= -Wall -Wextra -Werror

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