/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:15:19 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/15 17:54:19 by abenoit          ###   ########.fr       */
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
	if (ft_strcmp(*str, "exit") == 0)
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
