#ifndef LIBASM_BONUS_H
# define	LIBASM_BONUS_H

# ifndef T_LIST_FORMAT
#  define T_LIST_FORMAT

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

# endif


typedef int	(*t_list_func)(int *state, t_list **lst);

/*
**	test functions
*/

int		list_test(int size);
int		call_list_test(int *state);

/*
**	bonus asm functions
*/

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int(*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void*));


/*
**	list utils
*/

int		ft_int_comp(void *n1, void *n2);
int		print_lst(t_list *first);
int		*new_fixed_num(int val);
t_list	*new_fixed_elem(int val);
int		*new_rand_num(void);
t_list	*new_rand_elem(void);

#endif
