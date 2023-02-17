/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:47:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:04:47 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_top_a(t_list **lst, int content)
{
	while (get_pos(*lst, content) != 1)
	{
		if (get_pos(*lst, content) < ft_lstsize(*lst) / 2)
			rotate(lst, 'a');
		else
			r_rotate(lst, 'a');
	}
}

void	put_top_b(t_list **lst, int content)
{
	while (get_pos(*lst, content) != 1)
	{
		if (get_pos(*lst, content) < ft_lstsize(*lst) / 2)
			rotate(lst, 'b');
		else
			r_rotate(lst, 'b');
	}
}

int	tri_5(t_list **lst_a, t_list **lst_b, t_init *init)
{
	put_top_a(lst_a, init->tab[0]);
	push(lst_a, lst_b, 'b');
	put_top_a(lst_a, init->tab[1]);
	push(lst_a, lst_b, 'b');
	tri_3(lst_a, init);
	push(lst_b, lst_a, 'a');
	push(lst_b, lst_a, 'a');
	return (0);
}

int	tri_3(t_list **lst_a, t_init *init)
{
	if ((*lst_a)->nb == init->plus_grand)
		rotate(lst_a, 'a');
	else if ((*lst_a)->next->nb == init->plus_grand)
		r_rotate(lst_a, 'a');
	if ((*lst_a)->nb < (*lst_a)->next->nb
		&& (*lst_a)->next->nb < (*lst_a)->next->next->nb)
		return (1);
	swap(lst_a, 'a');
	return (1);
}
