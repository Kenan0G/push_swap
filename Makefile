# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 16:59:04 by kgezgin           #+#    #+#              #
#    Updated: 2023/01/25 13:49:16 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
SRCS		=	push_swap.c\
				liste.c\
				parsing.c
			
OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	cd libft && make && cd ../ft_printf && make
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a ft_printf/libftprintf.a

all:		${NAME}

clean:	
	cd libft && make fclean && cd ../ft_printf && make fclean
	${RM} ${OBJS}

fclean:		clean			
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re