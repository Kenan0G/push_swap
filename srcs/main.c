/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:05:45 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:52 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		ft_printf("%d\n", temp->nb);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*liste_a;
	t_list	*liste_b;
	t_init	data_init;

	liste_b = NULL;
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	liste_a = init(ac, av, &data_init);
	algo(&liste_a, &liste_b, &data_init);
	ft_free_list(&liste_a);
	if (liste_b)
		ft_free_list(&liste_b);
	return (0);
}
