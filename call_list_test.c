#include "lib_lst.h"
#include "libasm.h"
#include "libasm_bonus.h"

int	new_rand_list(int *state, t_list **lst)
{
	int		size;
	int		i;

	if (*lst != NULL)
		ft_lstclear(lst, free);
	ft_putstr("New random list\n");
	ft_putstr("size = ");
	size = get_num(state);
	i = 0;
	while (i < size)
	{
		ft_lstadd_front(lst, new_rand_elem());
		i++;
	}
	*state = 0;
	return (0);
}

int	new_fixed_list(int *state, t_list **lst)
{
	int		size;
	int		val;
	int		i;

	if (*lst != NULL)
		ft_lstclear(lst, free);
	ft_putstr("New fixed list\n");
	ft_putstr("size = ");
	size = get_num(state);
	i = 0;
	while (i < size)
	{
		printf("===Elem %d===\n", i + 1);
		ft_putstr("val = ");
		val = get_num(state);
		ft_lstadd_back(lst, new_fixed_elem(val));
		i++;
	}
	*state = 0;
	return (0);
}

int	call_push_front(int *state, t_list **lst)
{
	int		*val;

	ft_putstr("Push new list element\n");
	ft_putstr("val = ");
	val = malloc(sizeof(int));
	if (val == NULL)
		return (0);
	*val = get_num(state);
	ft_list_push_front(lst, val);
	*state = 0;
	return (0);
}

int	call_size(int *state, t_list **lst)
{
	int		size;

	ft_putstr("List size\n");
	size = ft_list_size(*lst);
	printf("size = %d\n", size);
	*state = 0;
	return (0);
}

int	call_sort(int *state, t_list **lst)
{
	ft_putstr("Sorting list...\n");
	ft_list_sort(lst, ft_int_comp);
	ft_putstr("Done !\n");
	*state = 0;
	return (0);
}

int	call_remove(int *state, t_list **lst)
{
	int		*val;

	ft_putstr("val = ");
	val = malloc(sizeof(int));
	if (val == NULL)
		return (0);
	*val = get_num(state);
	ft_list_remove_if(lst, val, ft_int_comp, free);
	*state = 0;
	return (0);
}

int	call_print(int *state, t_list **lst)
{
	print_lst(*lst);
	*state = 0;
	return (0);
}

int	call_clear(int *state, t_list **lst)
{
	ft_lstclear(lst, free);
	*state = 0;
	return (0);
}

static int	get_list_input(int *state, t_list **lst)
{
	char	*line;

	ft_putstr("\n");
	ft_putstr("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
	ft_putstr("\"\"\"\"\"\"\"\" List tester \"\"\"\"\"\"\"\"\n");
	ft_putstr("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
	ft_putstr("1.New random list (rand)\n"
				"2.Set new list (fixed)\n"
				"3.list_push_front (front)\n"
				"4.list_size (size)\n"
				"5.list_sort (sort)\n"
				"6.list_remove_if (remove)\n"
				"7.print list (print)\n"
				"8.clear list (clear)\n"
				"9.exit\n"
				"$ ");
	rec_gnl(0, &line);
	if (ft_strcmp(line, "exit") == 0 || ft_strcmp(line, "9") == 0
		|| ft_strcmp(line, "..") == 0)
		*state = -1;
	else if (ft_strcmp(line, "rand") == 0 || ft_strcmp(line, "1") == 0)
		*state = 1;
	else if (ft_strcmp(line, "fixed") == 0 || ft_strcmp(line, "2") == 0)
		*state = 2;
	else if (ft_strcmp(line, "push") == 0 || ft_strcmp(line, "3") == 0)
		*state = 3;
	else if (ft_strcmp(line, "size") == 0 || ft_strcmp(line, "4") == 0)
		*state = 4;
	else if (ft_strcmp(line, "sort") == 0 || ft_strcmp(line, "5") == 0)
		*state = 5;
	else if (ft_strcmp(line, "remove") == 0 || ft_strcmp(line, "6") == 0)
		*state = 6;
	else if (ft_strcmp(line, "print") == 0 || ft_strcmp(line, "7") == 0)
		*state = 7;
	else if (ft_strcmp(line, "clear") == 0 || ft_strcmp(line, "8") == 0)
		*state = 8;
	else
		return (-1);
	free(line);
	return (0);
}

int	call_list_test(int *state)
{
	int		substate;
	t_list	*lst;
	const	t_list_func	fsm[] = {get_list_input, new_rand_list, new_fixed_list, call_push_front, call_size, call_sort, call_remove, call_print, call_clear};

	substate = 0;
	lst = NULL;
	while (substate != -1)
	{
		if (fsm[substate](&substate, &lst) < 0)
			printf("Error: input\n");
	}
	ft_lstclear(&lst, free);
	*state = 0;
	return (0);
}
