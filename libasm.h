#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *str, int size);
char	*ft_strcpy(char *dest, char *src);
int		ft_read(int fd, char *buff, int	count);
char	*ft_strdup(char *str);
int		ft_atoi_base(char *str, char *base);

int		rec_gnl(int fd, char **line);

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isset(char c, char *set);
int		ft_atoi(char *str);

typedef int	(*t_func)(int *state);