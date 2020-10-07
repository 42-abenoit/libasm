/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:31:51 by abenoit           #+#    #+#             */
/*   Updated: 2020/10/07 16:20:00 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_lst.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *first;

	if (new == NULL || alst == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		first = *alst;
		while (first->next != NULL)
			first = first->next;
		first->next = new;
		new->next = NULL;
	}
}
