/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:40:09 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:10:52 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*my_atoi_utils(char	*str, int *sign, int **check)
{
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
	{
		*sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if ((*str < '0' && *str > '9') || *str == '\0')
		**check = 0;
	return (str);
}

int	my_atoi(char *nptr, int *check)
{
	long int	num;
	int			sign;
	int			*ptr;
	char		*str;

	str = (char *)nptr;
	num = 0;
	sign = 1;
	ptr = &sign;
	str = my_atoi_utils(str, ptr, &check);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			*check = 0;
		str++;
	}
	if (*str)
		*check = 0;
	return (num * sign);
}
