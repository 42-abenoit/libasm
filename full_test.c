/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:26:25 by abenoit           #+#    #+#             */
/*   Updated: 2020/10/07 17:57:15 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	cmp_strlen(void)
{
	printf("ft_strlen = %d\n", ft_strlen("Hello World"));
	printf("strlen = %ld\n", strlen("Hello World"));
	return (0);
}

static int	test_strlen(void)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (cmp_strlen())
			return (-1);
	}
	else
	{
		wait(&status);
		if (WIFSIGNALED(status))
			printf("Segfault in ft_strlen()\n");
	}
	return (0);
}

int		full_test(void)
{
	int	a;
}
