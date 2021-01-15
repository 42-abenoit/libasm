/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:26:16 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/15 15:12:38 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_lst.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *data)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
