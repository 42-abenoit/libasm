/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:26:25 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/14 17:12:07 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	test_strlen(char *str)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		printf("ft_strlen = %d\n", ft_strlen(str));
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_strlen = segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
			printf("   strlen = %ld\n", strlen(str));
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("   strlen = segfault\n");
				}
			}
		}
	}
	return (0);
}

int	test_strcpy(char *s1, char *s2)
{
	pid_t	pid;
	int		ret;
	char	*dest;
	char	*src;
	
	if (s1 != NULL)
		dest = strdup(s1);
	else
		dest = NULL;
	if (s2 != NULL)
		src = strdup(s2);
	else
		src = NULL;
	pid = fork();
	if (pid == 0)
	{
		printf("ft_strcpy = %s\n", strcpy(dest, src));
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_strcpy = segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
			printf("   strcpy = %s\n", strcpy(dest, src));
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("   strcpy = segfault\n");
				}
			}
		}
	}
	return (0);
}

int	test_strcmp(char *str1, char *str2)
{
	pid_t	pid;
	int		ret;
	char	*s1;
	char	*s2;
	
	if (str1 != NULL)
		s1 = strdup(str1);
	else
		s1 = NULL;
	if (str2 != NULL)
		s2 = strdup(str2);
	else
		s2 = NULL;
	pid = fork();
	if (pid == 0)
	{
		printf("ft_strcmp = %d\n", strcmp(s1, s2));
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_strcmp = segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
			printf("   strcmp = %d\n", strcmp(s1, s2));
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("   strcmp = segfault\n");
				}
			}
		}
	}
	return (0);
}

int		full_test(void)
{
	test_strlen("");
	test_strlen("HELLO WORLD");
	test_strlen(NULL);

	ft_putstr("\n");

	test_strcpy("", "HELLO WORLD");
	test_strcpy("HELLO WORLD", "");
	test_strcpy("123456789", "abcde");
	test_strcpy("abcde", "123456789");
	test_strcpy(NULL, "abcde");
	test_strcpy(NULL, NULL);

	ft_putstr("\n");

	test_strcmp("", "HELLO WORLD");
	test_strcmp("HELLO WORLD", "");
	test_strcmp("123456789", "abcde");
	test_strcmp("abcde", "123456789");
	test_strcmp(NULL, "abcde");
	test_strcmp(NULL, NULL);

	ft_putstr("\n");
	
	return (0);
}
