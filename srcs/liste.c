/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:39:24 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 14:31:29 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*my_lstnew(int nb)
{
	t_list	*liste;

	liste = malloc(sizeof(*liste));
	liste->nb = nb;
	liste->next = NULL;
	return (liste);	
}


void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_node;

	current_node = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new;
}

