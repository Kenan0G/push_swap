/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:14:41 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:11:47 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_list **lst_a, t_list **lst_b, t_init *init)
{
	init_tab(*lst_a, *lst_b, init);
	if (init->tab_len == 3)
		tri_3(lst_a, init);
	else if (init->tab_len == 5)
		tri_5(lst_a, lst_b, init);
	else
		tri(lst_a, lst_b, init);
	free(init->tab);
}

void	tri(t_list **lst_a, t_list **lst_b, t_init *init)
{
	t_list	*temp;
	int		calculateur;
	int		i;

	pre_tri(lst_a, lst_b, init);
	while (ft_lstsize(*lst_b) >= 1)
	{
		i = 1;
		temp = *lst_b;
		calculateur = calculator(lst_a, lst_b, init);
		while (i < calculateur)
		{
			temp = temp->next;
			i++;
		}
		put_top_a(lst_a, find_sup(*lst_a, temp->nb));
		put_top_b(lst_b, temp->nb);
		push(lst_b, lst_a, 'a');
	}
	tri_final(lst_a, init);
}

void	pre_tri(t_list **lst_a, t_list **lst_b, t_init *init)
{
	while ((*lst_a)->next != NULL)
	{	
		if ((*lst_a)->nb == init->plus_grand)
			rotate(lst_a, 'a');
		push(lst_a, lst_b, 'b');
		if ((*lst_b)->nb < init->tab[init->mediane])
			rotate(lst_b, 'b');
	}
}

void	tri_final(t_list **lst, t_init *init)
{
	t_list	*temp;
	int		i;

	temp = *lst;
	i = 0;
	while (temp->nb != init->tab[0])
	{
		i++;
		temp = temp->next;
	}
	while ((*lst)->nb != init->tab[0])
	{
		if (i <= ft_lstsize(*lst) / 2)
			rotate(lst, 'a');
		else
			r_rotate(lst, 'a');
	}
}
