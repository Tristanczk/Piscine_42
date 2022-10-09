# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 17:15:38 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/26 17:22:47 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_cat.c ft_display_file.c ft.c

NAME		= ft_cat

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