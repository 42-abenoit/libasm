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

typedef int	(*t_func)(int *state);

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
**	util functions
*/

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isset(char c, char *set);
int		ft_atoi(char *str);
int		get_str(int *state, char **str);
int		get_num(int *state);
int		get_fd(int *state, int mode);


/*
**	test functions
*/

int		rec_gnl(int fd, char **line);
int		full_test(void);

#endif
