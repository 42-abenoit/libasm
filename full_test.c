/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 19:26:25 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/18 11:14:27 by abenoit          ###   ########.fr       */
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
		free(dest);
		free(src);
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
			free(dest);
			free(src);
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
			free(dest);
			free(src);
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
		free(s1);
		free(s2);
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
			free(s1);
			free(s2);
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
			free(s1);
			free(s2);
		}
	}
	return (0);
}

#include <time.h>

int	test_write(char *path, char *buff, int count)
{
	pid_t	pid;
	int		ret;
	int		fd;

	if (ft_strcmp(path, "STDOUT") == 0 || ft_strcmp(path, "1") == 0)
		fd = 1;
	else if (ft_strcmp(path, "invalid fd") == 0)
	{
		srand(time(NULL));
		fd = rand() % 253 + 2;
	}
	else
	{
		if ((fd = open(path, O_WRONLY)) < 0)
		{
			perror(path);
			return (0);
		}
	}
	pid = fork();
	if (pid == 0)
	{
	  	ft_putstr("ft_write = ");
	  	ret = ft_write(fd, buff, count);
	  	ft_putstr("\t");
	  	printf("return = %d\n", ret);
		if (ret < 0)
			perror("Error: ft_write");
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
				ft_putstr("segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
	  		ft_putstr("   write = ");
	  		ret = write(fd, buff, count);
	  		ft_putstr("\t");
	  		printf("return = %d\n", ret);
			if (ret < 0)
				perror("Error:    write");
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("segfault\n");
				}
			}
		}
	}
	return (0);
}

int	test_read(char *path, int buff_size, int count)
{
	pid_t	pid;
	char	*buff;
	int		ret;
	int		fd;

	if (ft_strcmp(path, "STDIN") == 0 || ft_strcmp(path, "0") == 0)
		fd = 0;
	else if (ft_strcmp(path, "invalid fd") == 0)
	{
		srand(time(NULL));
		fd = rand() % 253 + 2;
	}
	else
	{
		if ((fd = open(path, O_RDONLY)) < 0)
		{
			perror(path);
			return (0);
		}
	}
	if (buff_size > 0)
	{
		buff = malloc(buff_size * sizeof(char));
		if (buff == NULL)
		{
			if (fd != 0)
				close(fd);
			exit(0);
		}
	}
	else
		buff = NULL;
	pid = fork();
	if (pid == 0)
	{
	  	ft_putstr("ft_read = ");
	  	ret = ft_read(fd, buff, count);
		ft_putstr(buff);
	  	ft_putstr("\t");
	  	printf("return = %d\n", ret);
		if (ret < 0)
			perror("Error: ft_read");
		free(buff);
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
				ft_putstr("segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
	  		ft_putstr("   read = ");
	  		ret = read(fd, buff, count);
			ft_putstr(buff);
	  		ft_putstr("\t");
	  		printf("return = %d\n", ret);
			if (ret < 0)
				perror("Error:    read");
			free(buff);
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("segfault\n");
				}
			}
			free(buff);
		}
	}
	return (0);
}

int	test_strdup(char *str)
{
	pid_t	pid;
	int		ret;
	char	*cpy;

	pid = fork();
	if (pid == 0)
	{
		cpy = ft_strdup(str);
		printf("ft_strdup = %s\n", cpy);
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_strdup = segfault\n");
			}
		}
		pid = fork();
		if (pid == 0)
		{
			cpy = strdup(str);
			printf("   strdup = %s\n", cpy);
			exit (0);
		}
		else
		{
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
			{
				if (WTERMSIG(ret) == SIGSEGV)
				{
					ft_putstr("   strdup = segfault\n");
				}
			}
		}
	}
	return (0);
}

int	test_atoi_base(char *str, char *base)
{
	pid_t	pid;
	int		ret;
	int		nbr;
	
	pid = fork();
	if (pid == 0)
	{
		nbr = ft_atoi_base(str, base);
		printf("ft_atoi_base = %d\n", nbr);
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_atoi_base = segfault\n");
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

	test_write("STDOUT", "HELLO WORLD", 11);
	test_write("STDOUT", "HELLO WORLD", 0);
	test_write("invalid fd", "HELLO WORLD", 11);

	ft_putstr("\n");

	test_read("main.c", 11, 11);
	test_read("main.c", 5, 11);
	test_read("main.c", 0, 11);
	test_read("main.c", 0, 0);
	test_read("invalid fd", 11, 11);

	ft_putstr("\n");

	test_strdup("");
	test_strdup("HELLO WORLD");
	test_strdup(NULL);

	ft_putstr("\n");

	test_atoi_base("0", "0123456789");
	test_atoi_base("10", "0123456789");
	test_atoi_base("-10", "0123456789");
	test_atoi_base("2146473647", "0123456789");
	test_atoi_base("-2146473648", "0123456789");
	test_atoi_base("8", "0123456789abcdef");
	test_atoi_base("a", "0123456789abcdef");
	test_atoi_base("10", "0123456789abcdef");
	test_atoi_base("7fffffff", "0123456789abcdef");

	return (list_test(4));
}
