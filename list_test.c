#include "lib_lst.h"
#include "libasm.h"
#include <time.h>

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
		ft_lstadd_front(&lst, new_rand_elem());
		i++;
	}
	print_lst(lst);
	remove = *((int*)(ft_lstlast(lst)->data));
	ft_list_sort(&lst, ft_int_comp);
	print_lst(lst);
	i = 0;
	while (i < size)
	{
		ft_lstadd_front(&lst, new_fixed_elem(remove));
		i++;
	}
	print_lst(lst);
	ft_list_remove_if(&lst, &remove, ft_int_comp, free);
	print_lst(lst);
	ft_lstclear(&lst, free);
	print_lst(lst);
	return (0);
}
