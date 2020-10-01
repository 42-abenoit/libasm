/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:53:56 by abenoit           #+#    #+#             */
/*   Updated: 2020/10/01 16:26:10 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	call_strlen(int *state)
{
	char	*str;

	ft_putstr("ft_strlen(char *str):\n*str = ");
	if (rec_gnl(0, &str) < 0)
		return (-1);
	if (ft_strcmp(str, "exit") == 0)
	{
		free(str);
		*state = 0;
		return (0);
	}
	else
		printf("return = %d\n", ft_strlen(str));
	free(str);
	return (0);
}

static int	call_strcpy(int *state)
{
	char	*dest;
	char	*src;

	ft_putstr("ft_strcpy(char *dest, char *src):\n*dest = ");
	if (rec_gnl(0, &dest) < 0)
		return (-1);
	if (ft_strcmp(dest, "exit") == 0)
	{
		free(dest);
		*state = 0;
		return (0);
	}
	ft_putstr("*src = ");
	if (rec_gnl(0, &src) < 0)
		return (-1);
	if (ft_strcmp(src, "exit") == 0)
	{
		free(dest);
		free(src);
		*state = 0;
		return (0);
	}
	else
		printf("return = %s\n", ft_strcpy(dest, src));
	return (0);
}

static int	call_strcmp(int *state)
{
	char	*s1;
	char	*s2;

	ft_putstr("ft_strcmp(char *s1, char *s2):\n*s1 = ");
	if (rec_gnl(0, &s1) < 0)
		return (-1);
	if (ft_strcmp(s1, "exit") == 0)
	{
		free(s1);
		*state = 0;
		return (0);
	}
	ft_putstr("*s2 = ");
	if (rec_gnl(0, &s2) < 0)
		return (-1);
	if (ft_strcmp(s2, "exit") == 0)
	{
		free(s1);
		free(s2);
		*state = 0;
		return (0);
	}
	else
		printf("return = %d\n", ft_strcmp(s1, s2));
	return (0);
}

static int	call_write(int *state)
{
	char	*tmp;
	char	*buff;
	int		fd;
	int		count;
	int		ret;

	ft_putstr("ft_write(int fd, char *buff, int count):\nfd = ");
	if (rec_gnl(0, &tmp) < 0)
		return (-1);
	if (ft_strcmp(tmp, "exit") == 0)
	{
		free(tmp);
		*state = 0;
		return (0);
	}
	else if (ft_strcmp(tmp, "STDOUT") == 0)
		fd = 1;
	else
	{
		if ((fd = open(tmp, O_WRONLY)) <= 0)
		{
			free(tmp);
			tmp = NULL;
			perror(tmp);
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	ft_putstr("buff = ");
	if (rec_gnl(0, &buff) < 0)
		return (-1);
	if (ft_strcmp(buff, "exit") == 0)
	{
		free(buff);
		*state = 0;
		return (0);
	}
	ft_putstr("count = ");
	if (rec_gnl(0, &tmp) < 0)
	{
		free(buff);
		return (-1);
	}
	if (ft_strcmp(tmp, "exit") == 0)
	{
		free(buff);
		free(tmp);
		*state = 0;
		return (0);
	}
	if ((count = ft_atoi(tmp)) <= 0)
	{
		printf("Invalid size\n");
		free(buff);
		free(tmp);
		return (0);
	}
	else
	{
		free (tmp);
		ft_putstr("write: ");
		ret = ft_write(fd, buff, count);
		ft_putstr("\t");
		printf("return = %d\n", ret);
	}
	free(buff);
	return (0);
}

static int	call_read(int *state)
{
	char	*tmp;
	char	*buff;
	int		fd;
	int		count;
	int		ret;

	ft_putstr("ft_read(int fd, char *buff, int count):\nfd = ");
	if (rec_gnl(0, &tmp) < 0)
		return (-1);
	if (ft_strcmp(tmp, "exit") == 0)
	{
		free(tmp);
		*state = 0;
		return (0);
	}
	else if (ft_strcmp(tmp, "STDIN") == 0)
		fd = 0;
	else
	{
		if ((fd = open(tmp, O_RDONLY)) <= 0)
		{
			free(tmp);
			tmp = NULL;
			perror(tmp);
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	ft_putstr("buff_size = ");
	if (rec_gnl(0, &tmp) < 0)
		return (-1);
	if (ft_strcmp(tmp, "exit") == 0)
	{
		free(tmp);
		*state = 0;
		return (0);
	}
	if ((count = ft_atoi(tmp)) <= 0)
	{
		printf("Invalid size\n");
		free(tmp);
		return (0);
	}
	if (!(buff = malloc(count * sizeof(char))))
	{
		free(tmp);
		printf("Malloc error\n");
		return (-1);
	}
	ft_putstr("count = ");
	if (rec_gnl(0, &tmp) < 0)
	{
		free(buff);
		return (-1);
	}
	if (ft_strcmp(tmp, "exit") == 0)
	{
		free(buff);
		free(tmp);
		*state = 0;
		return (0);
	}
	if ((count = ft_atoi(tmp)) <= 0)
	{
		printf("Invalid size\n");
		free(buff);
		free(tmp);
		return (0);
	}
	else
	{
		free (tmp);
		ret = ft_read(fd, buff, count);
		printf("buff = %s\n", buff);
		printf("return = %d\n", ret);
	}
	free(buff);
	return (0);
}

static int	call_strdup(int *state)
{
	char	*str;
	char	*cpy;

	ft_putstr("ft_strdup(char *str):\n*str = ");
	if (rec_gnl(0, &str) < 0)
		return (-1);
	if (ft_strcmp(str, "exit") == 0)
	{
		free(str);
		*state = 0;
		return (0);
	}
	else
	{
		cpy = ft_strdup(str);
		printf("return: *cpy = %s at adress %p\n", cpy, &cpy);
	}
	free(str);
	free(cpy);
	return (0);
}

static int	call_atoi_base(int *state)
{
	char	*str;
	char	*base;
	int		nbr;

	ft_putstr("ft_atoi_base(char *str, char *base):\n*str = ");
	if (rec_gnl(0, &str) < 0)
		return (-1);
	if (ft_strcmp(str, "exit") == 0)
	{
		free(str);
		*state = 0;
		return (0);
	}
	ft_putstr("*base = ");
	if (rec_gnl(0, &base) < 0)
		return (-1);
	if (ft_strcmp(base, "exit") == 0)
	{
		free(str);
		free(base);
		*state = 0;
		return (0);
	}
	else
	{
		nbr = ft_atoi_base(str, base);
		printf("return: nbr =  %d\n", nbr);
	}
	free(str);
	free(base);
	return (0);
}

static int	get_input(int *state)
{
	char	*line;

	ft_putstr("Enter name or number of tested funtion:\n"
				"1.strlen\n"
				"2.strcpy\n"
				"3.strcmp\n"
				"4.write\n"
				"5.read\n"
				"6.strdup\n"
				"7.atoi_base\n"
				"8.exit\n"
				"user: ");
	rec_gnl(0, &line);
	if (ft_strcmp(line, "exit") == 0 || ft_strcmp(line, "8") == 0)
		*state = -1;
	else if (ft_strcmp(line, "strlen") == 0 || ft_strcmp(line, "1") == 0)
		*state = 1;
	else if (ft_strcmp(line, "strcpy") == 0 || ft_strcmp(line, "2") == 0)
		*state = 2;
	else if (ft_strcmp(line, "strcmp") == 0 || ft_strcmp(line, "3") == 0)
		*state = 3;
	else if (ft_strcmp(line, "write") == 0 || ft_strcmp(line, "4") == 0)
		*state = 4;
	else if (ft_strcmp(line, "read") == 0 || ft_strcmp(line, "5") == 0)
		*state = 5;
	else if (ft_strcmp(line, "strdup") == 0 || ft_strcmp(line, "6") == 0)
		*state = 6;
	else if (ft_strcmp(line, "atoi_base") == 0 || ft_strcmp(line, "7") == 0)
		*state = 7;
	else
		return (-1);
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	int		state;
	const t_func fsm[8] = {get_input, call_strlen, call_strcpy, call_strcmp, call_write, call_read, call_strdup, call_atoi_base};

	state = 0;
	if (ac != 1)
	{
		printf("Error: argument\n");
		return (-1);
	}
	while (state != -1)
	{
		if (fsm[state](&state) < 0)
			printf("Error: input\n");
	}
	return (0);
}
