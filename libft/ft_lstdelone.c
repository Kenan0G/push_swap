/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:17:45 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/25 11:32:28 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;

	del(lst->content);
	temp = lst->next;
	free (lst);
	lst = temp;
}
