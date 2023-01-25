/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:50:58 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 14:01:33 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	my_atoi(char *nptr)
{
	long int	num;
	int			sign;
	char		*str;

	if (!nptr)
	{
		ft_putstr_fd("Error\nvide\n", 2);
		exit (0);
	}
	str = (char *)nptr;
	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str + 1 == '-' || *str + 1 == '+')
		return (0);
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			exit(0);
		str++;
	}
	if (*str)
		exit(0);
	return (num * sign);
}





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
			{
				ft_putstr_fd("Error\ndoublon", 2);
				// return (0);
				exit (0);
			}
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
	ft_putstr_fd("Error\ntri", 2);
	// return (0);
	exit (0);
}
