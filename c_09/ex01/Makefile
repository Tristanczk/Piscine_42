# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:46:33 by tczarnia          #+#    #+#              #
#    Updated: 2022/07/19 10:53:10 by tczarnia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

NAME		= libft.a

HEADERS 	= includes/

FLAGS		= -Wall -Wextra -Werror

OBJS 		= ${SRCS:.c=.o}

.c.o:		
			gcc ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all