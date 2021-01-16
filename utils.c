/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:15:19 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/16 20:19:17 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#define ISNUM "0123456789"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi(char *str)
{
	unsigned int	nbr;
	int				tmp;
	int				i;

	nbr = 0;
	i = 0;
	while ((tmp = ft_isset(str[i], ISNUM)) >= 0)
	{
		nbr *= 10;
		nbr += tmp;
		i++;
	}
	return (nbr);
}

int			get_str(int *state, char **str)
{
	if (rec_gnl(0, str) < 0)
		return (-1);
	if (ft_strcmp(*str, "exit") == 0 || ft_strcmp(*str, "..") == 0)
	{
		free(*str);
		*state = 0;
		return (0);
	}
	else if (ft_strcmp(*str, "null") == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int			get_num(int *state)
{
	char	*tmp;
	int		count;

	if (rec_gnl(0, &tmp) < 0)
		return (-1);
	if (ft_strcmp(tmp, "exit") == 0 || ft_strcmp(tmp, "..") == 0)
	{
		free(tmp);
		*state = 0;
		return (-1);
	}
	if ((count = ft_atoi(tmp)) < 0)
	{
		printf("Invalid size\n");
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (count);
}

int			get_fd(int *state, int mode)
{
	int		fd;
	char	*tmp;
	int		flags;

	if (mode == 0)
		flags = O_WRONLY;
	else
		flags = O_RDONLY;
	if (rec_gnl(0, &tmp) < 0)
		return (-1);
	if (ft_strcmp(tmp, "exit") == 0 || ft_strcmp(tmp, "..") == 0)
	{
		free(tmp);
		*state = 0;
		return (-1);
	}
	if (ft_strcmp(tmp, "STDOUT") == 0 || ft_strcmp(tmp, "1") == 0)
		return (1);
	else if (ft_strcmp(tmp, "STDIN") == 0 || ft_strcmp(tmp, "0") == 0)
		return (0);
	else
	{
		if ((fd = open(tmp, flags)) <= 0)
		{
			free(tmp);
			tmp = NULL;
			perror(tmp);
			free(tmp);
			return (-1);
		}
	}
	return (fd);
}
