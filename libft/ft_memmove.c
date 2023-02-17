/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:51:21 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/17 16:43:17 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t;
	unsigned char	*s;

	if (src == dest || !n)
		return (dest);
	if (dest < src)
	{
		t = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			*t++ = *s++;
	}
	else
	{
		t = (unsigned char *)dest + (n - 1);
		s = (unsigned char *)src + (n - 1);
		while (n--)
			*t-- = *s--;
	}
	return (dest);
}
