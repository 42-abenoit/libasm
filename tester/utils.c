/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:15:19 by abenoit           #+#    #+#             */
/*   Updated: 2020/09/30 15:58:46 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define ISNUM "0123456789"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
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

	nbr = 0;
	while ((tmp = ft_isset(*str, ISNUM)) >= 0)
	{
		nbr *= 10;
		nbr += tmp;
		*str++;
	}
	return (nbr);
}
