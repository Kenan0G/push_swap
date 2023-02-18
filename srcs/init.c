/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:20:25 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 19:46:48 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_init(t_init *init)
{
	init->check = 1;
	init->ptr = &(init->check);
	init->k = 1;
}

t_list	*init(int ac, char **av, t_init *init)
{
	t_list	*lst;
	int		i;
	int		j;

	init_init(init);
	i = 1;
	lst = NULL;
	while (i < ac)
	{
		(init)->str = ft_split(av[i], ' ');
		j = 0;
		ft_check_vide_and_my_atoi(init, &lst, 0, 0);
		while ((init)->str[j])
		{
			ft_check_vide_and_my_atoi(init, &lst, 1, j);
			j++;
			init->k++;
		}
		ft_free_map((init)->str);
		i++;
	}
	(init)->tab_len = init->k - 1;
	ft_check(&lst);
	return (lst);
}

void	init_tab(t_list *lst_a, t_list *lst_b, t_init *init)
{
	int		i;
	t_list	*temp;

	i = 0;
	(void)lst_b;
	init->tab = malloc(sizeof(int) * init->tab_len);
	temp = lst_a;
	while (temp != NULL)
	{
		init->tab[i] = temp->nb;
		temp = temp->next;
		i++;
	}
	my_sort_int_tab(init->tab, init->tab_len);
	init->mediane = ((init->tab_len / 2));
	init->plus_grand = init->tab[i - 1];
}

void	my_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j += 1;
		}
		i += 1;
	}
}
