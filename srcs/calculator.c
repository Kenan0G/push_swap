/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:48:38 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:07:55 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculator(t_list **lst_x, t_list **lst_y, t_init *init)
{
	t_list	*temp;
	int		nb_top_temp;
	int		nb_top_total;
	int		i;

	temp = *lst_y;
	i = 1;
	calculator_utils(lst_x, lst_y, init);
	nb_top_total = init->index_a + init->index_b;
	while (temp != NULL)
	{
		init->pos = get_pos(*lst_x, find_sup(*lst_x, temp->nb)) - 1;
		init->index_a = calcul_top(*lst_x, init);
		init->pos = i - 1;
		init->index_b = calcul_top(*lst_y, init);
		nb_top_temp = init->index_a + init->index_b;
		if (nb_top_temp < nb_top_total)
		{
			nb_top_total = nb_top_temp;
			init->index = i;
		}
		i++;
		temp = temp->next;
	}
	return (init->index);
}

void	calculator_utils(t_list **lst_x, t_list **lst_y, t_init *init)
{
	t_list	*temp;

	temp = *lst_y;
	init->index = 1;
	init->pos = 0;
	init->index_b = calcul_top(*lst_y, init);
	init->pos = get_pos(*lst_x, find_sup(*lst_x, temp->nb)) - 1;
	init->index_a = calcul_top(*lst_x, init);
}

int	calcul_top(t_list *lst, t_init *init)
{
	int	i;

	i = 0;
	if (init->pos < ft_lstsize(lst) / 2)
		i = init->pos;
	else
		i = ft_lstsize(lst) - init->pos;
	return (i);
}

int	find_sup(t_list *lst, int nb)
{
	t_list	*temp;
	int		nb_tmp;

	temp = lst;
	while (temp->next != NULL && temp->nb < nb)
		temp = temp->next;
	nb_tmp = temp->nb;
	while (temp != NULL)
	{
		if (temp->nb > nb && temp->nb < nb_tmp)
			nb_tmp = temp->nb;
		temp = temp->next;
	}
	return (nb_tmp);
}

int	get_pos(t_list *lst, int content)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = lst;
	while (temp != NULL && temp->nb != content)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
