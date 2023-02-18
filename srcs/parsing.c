/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:50:58 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 19:46:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_doublon(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp_2;

	tmp = lst;
	while (tmp)
	{
		tmp_2 = tmp->next;
		while (tmp_2)
		{
			if (tmp->nb == tmp_2->nb)
				return (ft_putstr_fd("Error\n", 2), 0);
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_tri(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check(t_list **lst)
{
	if (!check_doublon(*lst))
	{
		ft_free_list(lst);
		exit (0);
	}
	if (!check_tri(*lst))
	{
		ft_free_list(lst);
		exit (0);
	}
	return (1);
}

void	ft_check_vide_and_my_atoi(t_init *init, t_list **lst, int d, int j)
{
	if (d == 0)
	{
		if (!init->str[0])
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_list(lst);
			ft_free_map(init->str);
			exit (0);
		}
	}
	else if (d == 1)
	{
		init->nb = my_atoi(init->str[j], init->ptr);
		if (init->check == 0)
			ft_free_1(init->str, lst);
		my_lstadd_back(lst, my_lstnew(init->nb));
	}
}
