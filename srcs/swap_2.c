/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:54:51 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/13 17:53:33 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_list **lst, char w)
{
	t_list	*temp;
	t_list	*temp_2;

	if (!(*lst))
		return ;
	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp_2 = temp->next;
	temp->next = NULL;
	temp_2->next = *lst;
	*lst = temp_2;
	if (w == 'a')
		write(1, "rra\n", 4);
	else if (w == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_list **lst_a, t_list **lst_b)
{
	r_rotate(lst_a, 'c');
	r_rotate(lst_b, 'c');
	write(1, "rrr\n", 4);
}
