# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 16:59:04 by kgezgin           #+#    #+#              #
#    Updated: 2023/02/22 10:51:24 by kgezgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs
SRCS		=	main.c\
				liste.c\
				init.c\
				my_atoi.c\
				parsing.c\
				swap.c\
				swap_2.c\
				free.c\
				algo.c\
				algo_utils.c\
				calculator.c

OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))
NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
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