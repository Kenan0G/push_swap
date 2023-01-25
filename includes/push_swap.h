/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:07:33 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 12:50:35 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"


t_list	*init_pile(int ac, char **av);
t_list	*init(int ac, char **av);
t_list	*my_lstnew(int nb);
int		my_atoi(char *nptr);
void 	my_lstadd_back(t_list **lst, t_list *new);
int		check_doublon(t_list *lst);
int		check_tri(t_list *lst);

#endif