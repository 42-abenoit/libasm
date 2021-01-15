#include "libasm.h"

int	new_rand_list(int *state, t_list **lst)
{
	ft_putstr("rand\n");
	*state = 0;
	return (0);
}

int	new_fixed_list(int *state, t_list **lst)
{
	ft_putstr("fixed\n");
	*state = 0;
	return (0);
}

int	call_push_front(int *state, t_list **lst)
{
	ft_putstr("push\n");
	*state = 0;
	return (0);
}

int	call_size(int *state, t_list **lst)
{
	ft_putstr("size\n");
	*state = 0;
	return (0);
}

int	call_sort(int *state, t_list **lst)
{
	ft_putstr("sort\n");
	*state = 0;
	return (0);
}

int	call_remove(int *state, t_list **lst)
{
	ft_putstr("remove\n");
	*state = 0;
	return (0);
}

int	call_print(int *state, t_list **lst)
{
	ft_putstr("print\n");
	*state = 0;
	return (0);
}

static int	get_list_input(int *state, t_list **lst)
{
	char	*line;

	(void)lst;
	ft_putstr("List test:\n"
				"1.New random list (rand)\n"
				"2.Set new list (fixed)\n"
				"3.list_push_front (front)\n"
				"4.list_size (size)\n"
				"5.list_sort (sort)\n"
				"6.list_remove_if (remove)\n"
				"7.print list (print)\n"
				"8.exit\n"
				"user: ");
	rec_gnl(0, &line);
	if (ft_strcmp(line, "exit") == 0 || ft_strcmp(line, "8") == 0)
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
	else
		return (-1);
	free(line);
	return (0);
}

int	call_list_test(int *state)
{
	int		substate;
	t_list	*lst;
	const	t_list_func	fsm[] = {get_list_input, new_rand_list, new_fixed_list, call_push_front, call_size, call_sort, call_remove, call_print};

	substate = 0;
	lst = NULL;
	while (substate != -1)
	{
		if (fsm[substate](&substate, &lst) < 0)
			printf("Error: input\n");
	}
	*state = 0;
	return (0);
}
