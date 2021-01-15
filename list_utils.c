#include "lib_lst.h"
#include "libasm.h"

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

int		*new_fixed_num(int val)
{
	int		*new;

	new = malloc(sizeof(int));
	if (new == NULL)
		return (NULL);
	*new = val;
	return (new);
}

t_list	*new_fixed_elem(int val)
{
	t_list	*new;
	int		*content;

	content = new_fixed_num(val);
	new = ft_lstnew(content);
	if (new == NULL)
		return (NULL);
	return (new);
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

t_list	*new_rand_elem(void)
{
	t_list	*new;
	int		*content;

	content = new_rand_num();
	new = ft_lstnew(content);
	if (new == NULL)
		return (NULL);
	return (new);
}
