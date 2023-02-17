/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:18:38 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:03:24 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **lst_a, t_list **lst_b, char w)
{
	t_list	*temp;

	if (!(*lst_a))
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = *lst_b;
	*lst_b = temp;
	if (w == 'a')
		write(1, "pa\n", 3);
	else if (w == 'b')
		write(1, "pb\n", 3);
}

void	swap(t_list **lst, char w)
{
	t_list	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst);
	(*lst) = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	if (w == 'a')
		write(1, "sa\n", 3);
	else if (w == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a, 'c');
	swap(lst_b, 'c');
	write(1, "ss\n", 3);
}

void	rotate(t_list **lst, char w)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	my_lstadd_back(lst, temp);
	if (w == 'a')
		write(1, "ra\n", 3);
	else if (w == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a, 'c');
	rotate(lst_b, 'c');
	write(1, "rr\n", 3);
}
