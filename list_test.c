#include "lib_lst.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int		ft_int_comp(void *n1, void *n2)
{
	int	nb1;
	int	nb2;
	int	res;

	nb1 = *((int*)n1);
	nb2 = *((int*)n2);
	res = nb1 - nb2;
//	printf("%d", nb1);
//	printf("%d", nb2);
//	printf("%d", res);

	return (res);
}

void	ft_free(void *content)
{
	free(content);
	if  (errno != 0)
		perror("NO");
}

int		print_lst(t_list *first)
{
	t_list	*lst;
	int		*ptr;

	lst = first;
	printf("size = %d\n", ft_list_size(lst));
	while (lst != NULL)
	{
		ptr = lst->content;
		printf("|================|\n");
		printf("|%16p|\n", lst);
		printf("|================|\n");
		printf("|content = %6d|\n", *ptr);
		printf("|    next        |\n");
		printf("|_____||_________|\n");
		printf("      ||          \n");
		printf("      \\/          \n");
		if (lst->next == NULL)
		{
			printf("|================|\n");
			printf("|    NULL        |\n");
			printf("|================|\n\n");
		}
		lst = lst->next;
	}
	return (0);
}
/*
void	sort(t_list	**lst, int(*cmp)())
{
	int		i;
	t_list	*ptr;
	void	*tmp;

	i = 0;
	while (i < 100)
	{
	ptr = *lst;
	while (ptr->next != NULL)
	{
		if (cmp(ptr->content, ptr->next->content) > 0)
		{
			tmp = ptr->content;
			ptr->content = ptr->next->content;
			ptr->next->content = tmp;
		}
		ptr = ptr->next;
	}
	i++;
	}
}
*/

void	ff_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void*))
{
	t_list	*ptr;
	t_list	*tmp;

	while (cmp((*begin_list)->content, data_ref) == 0)
	{
		free_fct((*begin_list)->content);
		ptr = (*begin_list)->next;
		free(*begin_list);
		*begin_list = ptr;
		return ;
	}
	tmp = *begin_list;
	ptr = tmp->next;
	while (ptr != NULL)
	{
		if (cmp(ptr->content, data_ref) == 0)
		{
			free_fct(ptr->content);
			tmp->next = ptr->next;
			free(ptr);
			return ;
		}
		tmp = tmp->next;
		if (tmp == NULL)
			return ;
		ptr = tmp->next;
	}
	return ;
}

int		main(void)
{
	t_list	*lst;
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;
	int		g;
	int		h;
	int		*i;
	int		j;

	a = 8;
	b = 4;
	c = 6;
	d = 2;
	e = 51;
	f = 47;
	g = 63;
	h = 91;
	i = malloc(sizeof(int*));
	*i = 1;
	j = 1;
	lst = ft_lstnew(&a);
	ft_lstadd_front(&lst, ft_lstnew(&b));
	ft_lstadd_front(&lst, ft_lstnew(&c));
	ft_lstadd_front(&lst, ft_lstnew(&d));
	ft_list_push_front(&lst, &e);
	ft_list_push_front(&lst, &f);
	ft_list_push_front(&lst, &g);
	ft_list_push_front(&lst, &h);
	ft_list_push_front(&lst, i);
	print_lst(lst);
	ft_list_sort(&lst, ft_int_comp);
//	sort(&lst, &ft_int_comp);
	print_lst(lst);
	ft_list_remove_if(&lst, &j, ft_int_comp, ft_free);
//	ff_list_remove_if(&lst, &j, ft_int_comp, free);
	print_lst(lst);
//	ft_lstclear(&lst, free);
//	printf("%d\n", ft_int_comp(lst->content, lst->next->content));
}

int		list_test_it(void)
{

}
