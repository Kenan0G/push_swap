/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:37:58 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 11:45:19 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = malloc(sizeof(*liste));
	liste->content = content;
	liste->next = NULL;
	return (liste);
}
