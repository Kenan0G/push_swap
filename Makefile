# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 16:59:04 by kgezgin           #+#    #+#              #
#    Updated: 2023/02/17 16:13:24 by kgezgin          ###   ########.fr        #
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
#DEPS.d			=	./includes/push_swap.h
NAME			=	push_swap
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3 #-MMD -MP
RM				=	rm -f

.c.o: #Makefile
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

# -include $(DEPS)
.PHONY: 	all clean fclean re