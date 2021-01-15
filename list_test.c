#include "lib_lst.h"
#include "libasm.h"
#include <time.h>

int		ft_int_comp(void *n1, void *n2)
{
	int	nb1;
	int	nb2;
	int	res;

	nb1 = *((int*)n1);
	nb2 = *((int*)n2);
	res = nb1 - nb2;
	return (res);
}

int		print_lst(t_list *first)
{
	t_list	*lst;
	int		*ptr;

	lst = first;
	printf("size = %d\n", ft_list_size(lst));
	while (lst != NULL)
	{
		ptr = lst->data;
		printf("|================|\n");
		printf("|%16p|\n", lst);
		printf("|================|\n");
		printf("|data = %6d|\n", *ptr);
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

int		*new_rand_num(void)
{
	int		*new;

	new = malloc(sizeof(int));
	if (new == NULL)
		return (NULL);
	*new = rand() % 100;
	return (new);
}

t_list	*new_rand_list(void)
{
	t_list	*new;
	int		*content;

	content = new_rand_num();
	new = ft_lstnew(content);
	if (new == NULL)
		return (NULL);
	return (new);
}

int		list_test(int size)
{
	t_list	*lst;
	int		i;
	int		remove;

	srand(time(NULL));
	lst = NULL;
	i = 0;
	while (i < size)
	{
		ft_lstadd_front(&lst, new_rand_list());
		i++;
	}
	print_lst(lst);
	ft_list_sort(&lst, ft_int_comp);
	print_lst(lst);
	remove = *((int*)(ft_lstlast(lst)->data));
	ft_list_remove_if(&lst, &remove, ft_int_comp, free);
//	print_lst(lst);
	return (0);
//	ft_lstclear(&lst, free);
//	printf("%d\n", ft_int_comp(lst->data, lst->next->data));
}
