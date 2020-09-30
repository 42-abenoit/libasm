#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
int	ft_write(int fd, char *str, int size);
char	*ft_strcpy(char *s1, char *s2);
int		ft_read(int fd, char *buff, int	count);
char	*ft_strdup(char *str);
int		ft_atoi_base(char *str, char *base);

int				rec_gnl(int fd, char **line);

int	main(int ac, char **av)
{
	char	tab[128];
	char	buff[128];
	char	*str;
	int		plop;
	int		fd;
	int		nbr;
	char	end;
	char	*line;

	end = 0;
	if (ac != 10)
	{
		printf("Error: argument\n");
		return (1);
	}
	printf("ft_strlen(av[1]) = %d\n", ft_strlen(av[1]));
	printf("ft_strcmp(av[2], av[3]) = %d\n", ft_strcmp(av[2], av[3]));
	printf("ft_write(av[4]) = %d\n", ft_write(1, av[4], ft_strlen(av[4])));
	printf("ft_strcpy(av[5]) = %s\n", ft_strcpy(av[5], tab));
	printf("tab = %s at address %p\n", tab, &tab);
	fd = open(av[6], O_RDONLY);
	printf("ft_read(av[6]) = %d\n", ft_read(fd, buff, 128));
	printf("buff = \n\"%s\" at address %p\n", buff, &buff);
	str = ft_strdup(av[7]);
	if (str != NULL)
		printf("str = %s at address %p\n", str, &str);
	nbr = ft_atoi_base(av[8], av[9]);
	printf("ft_atoi_base(av[8], av[9]) = %d\n", nbr);
	while (!end)
	{
		rec_gnl(0, &line);
		if (ft_strcmp(line, "end") == 0)
			end = 1;
	}
	return (0);
}
