#include "lib_lst.h"
#include "libasm.h"
#include "libasm_bonus.h"
#include <time.h>

int		list_test(int size)
{
	t_list	*lst;
	int		i;
	int		remove;
	int		*val;

	srand(time(NULL));
	lst = NULL;
	i = 0;
	while (i < size)
	{
		ft_lstadd_front(&lst, new_rand_elem());
		i++;
	}
	ft_putstr("\n");
	ft_putstr("\033[0;31m");
	ft_putstr("ORIGINAL LIST\n");
	ft_putstr("\033[0m\n");
	print_lst(lst);
	remove = *((int*)(ft_lstlast(lst)->data));
	ft_list_sort(&lst, ft_int_comp);
	ft_putstr("\033[0;31m");
	ft_putstr("FT_LIST_SORT\n");
	ft_putstr("\033[0m\n");
	print_lst(lst);
	i = 0;
	while (i < size)
	{
		val = malloc(sizeof(int));
		if (val == NULL)
			return (-1);
		*val = remove;
		ft_list_push_front(&lst, val);
		i++;
	}
	ft_putstr("\033[0;31m");
	ft_putstr("FT_LIST_PUSH_FRONT\n");
	ft_putstr("\033[0m\n");
	print_lst(lst);
	ft_list_remove_if(&lst, &remove, ft_int_comp, free);
	ft_putstr("\033[0;31m");
	ft_putstr("FT_LIST_REMOVE_IF\n");
	ft_putstr("\033[0m\n");
	print_lst(lst);
	ft_lstclear(&lst, free);
	ft_putstr("\033[0;31m");
	ft_putstr("FT_LST_CLEAR\n");
	ft_putstr("\033[0m\n");
	print_lst(lst);
	return (0);
}
