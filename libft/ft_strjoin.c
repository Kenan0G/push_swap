/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:57:30 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/24 19:41:47 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				j;
	unsigned char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = ' ';
	i++;
	res[i] = '\0';
	return ((char *)res);
}

/*
int	main()
{
	printf("resultat :%s\n", ft_strjoin("salut", ""));
	return (0);
}
*/