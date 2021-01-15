/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:18:24 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/15 15:47:47 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LST_H
# define LIB_LST_H

#include <unistd.h>

# ifndef T_LIST_FORMAT
#  define T_LIST_FORMAT

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

# endif

t_list				*ft_lstnew(void *data);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void(*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
#endif
