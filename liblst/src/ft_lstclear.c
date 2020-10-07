/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:39 by abenoit           #+#    #+#             */
/*   Updated: 2020/10/07 16:20:18 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}
