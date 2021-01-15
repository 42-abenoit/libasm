#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define _XOPEN_SOURCE

# ifndef T_LIST_FORMAT
#  define T_LIST_FORMAT

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

# endif

typedef int	(*t_func)(int *state);

typedef int	(*t_list_func)(int *state, t_list **lst);

/*
**	asm functions
*/

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *str, int size);
char	*ft_strcpy(char *dest, char *src);
int		ft_read(int fd, char *buff, int	count);
char	*ft_strdup(char *str);

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
**	util functions
*/

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isset(char c, char *set);
int		ft_atoi(char *str);
int		get_str(int *state, char **str);


/*
**	test functions
*/

int		rec_gnl(int fd, char **line);
int		full_test(void);
int		list_test(int size);
int		call_list_test(int *state);

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
