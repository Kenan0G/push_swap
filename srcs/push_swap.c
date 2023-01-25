/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:05:45 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 14:31:42 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list *lst)
{
	t_list *temp;

	temp = lst;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 0);
	init(ac, av);
	return (0);
}

int	check_vide(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '\0')
		{
			return (ft_putstr_fd("Error\nvide", 2), 0);
		}
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


t_list	*init(int ac, char **av)
{
	char	**str;
	t_list	*lst;
	int		i;
	int		j;
	int		nb;

	i = 1;
	lst = NULL;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		j = 0;
		if (!str[0])
		{
			ft_putstr_fd("Error\nvide ou space\n", 2);
			exit (0);
		}
		while (str[j])
		{
			nb = my_atoi(str[j]);
			my_lstadd_back(&lst, my_lstnew(nb));
			j++;
		}
		i++;
	}
	print_list(lst);
	check_doublon(lst);
	check_tri(lst);
	return (lst);
}

