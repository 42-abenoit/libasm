/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:53:56 by abenoit           #+#    #+#             */
/*   Updated: 2021/01/18 12:11:01 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	call_strlen(int *state)
{
	char	*str;
	pid_t	pid;
	int		ret;

	ft_putstr("int\tft_strlen(char *str):\n*str = ");
	ret = get_str(state, &str);
	if (ret != 1)
		return (ret);
	pid = fork();
	if (pid == 0)
	{
		printf("ft_strlen = %d\n", ft_strlen(str));
		free(str);
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
			free(str);
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
	free(str);
	return (0);
}

static int	call_strcpy(int *state)
{
	int		ret;
	pid_t	pid;
	char	*dest;
	char	*src;

	ft_putstr("char\t*ft_strcpy(char *dest, char *src):\n");
	ft_putstr("*dest = ");
	ret = get_str(state, &dest);
	if (ret != 1)
		return (ret);
	ft_putstr("*src = ");
	ret = get_str(state, &src);
	if (ret != 1)
	{
		free(dest);
		return (ret);
	}
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

static int	call_strcmp(int *state)
{
	int		ret;
	pid_t	pid;
	char	*s1;
	char	*s2;

	ft_putstr("ft_strcmp(char *s1, char *s2):\n");
	ft_putstr("*s1 = ");
	ret = get_str(state, &s1);
	if (ret != 1)
		return (ret);
	ft_putstr("*s2 = ");
	ret = get_str(state, &s2);
	if (ret != 1)
	{
		free(s1);
		return (ret);
	}
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

static int	call_write(int *state)
{
	char	*buff;
	int		fd;
	int		count;
	pid_t	pid;
	int		ret;

	ft_putstr("ft_write(int fd, char *buff, int count):\nfd = ");
	fd = get_fd(state, 0);
	if (fd < 0)
		return (0);
	ft_putstr("buff = ");
	ret = get_str(state, &buff);
	if (ret != 1)
		return (ret);
	ft_putstr("count = ");
	count = get_num(state);
	if (count < 0)
	{
		free(buff);
		return (0);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			ft_putstr("ft_write = ");
			ret = ft_write(fd, buff, count);
			ft_putstr("\t");
			printf("return = %d\n", ret);
			free(buff);
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
				free(buff);
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
		free(buff);
		return (0);
	}
}

static int	call_read(int *state)
{
	char	*buff;
	pid_t	pid;
	int		fd;
	int		count;
	int		ret;

	ft_putstr("ft_read(int fd, char *buff, int count):\nfd = ");
	fd = get_fd(state, 1);
	if (fd < 0)
		return (0);
	ft_putstr("buff_size = ");
	count = get_num(state);
	if (count < 0)
		return (0);
	if (!(buff = malloc(count * sizeof(char))))
	{
		printf("Malloc error\n");
		return (-1);
	}
	ft_putstr("count = ");
	count = get_num(state);
	if (count < 0)
	{
		free(buff);
		return (0);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (fd == 0)
				ft_putstr("> ");
			ret = ft_read(fd, buff, count);
			ft_putstr("ft_read = ");
			ft_putstr(buff);
			ft_putstr("\t");
			printf("return = %d\n", ret);
			if (ret < 0)
				perror("Error: ft_read");
			free(buff);
			if (fd == 0)
			{
				ret = rec_gnl(0, &buff);
				if (ret < 0)
					return (0);
				free(buff);
			}
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
				if (fd == 0)
					ft_putstr("> ");
				ret = read(fd, buff, count);
				ft_putstr("   read = ");
				ft_putstr(buff);
				ft_putstr("\t");
				printf("return = %d\n", ret);
				if (ret < 0)
					perror("Error:    read");
				free(buff);
				if (fd == 0)
				{
					ret = rec_gnl(0, &buff);
					if (ret < 0)
						return (0);
					free(buff);
				}
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
	}
	return (0);
}

static int	call_strdup(int *state)
{
	char	*str;
	char	*cpy;
	pid_t	pid;
	int		ret;

	ft_putstr("ft_strdup(char *str):\n*str = ");
	ret = get_str(state, &str);
	if (ret != 1)
		return (ret);
	pid = fork();
	if (pid == 0)
	{
		cpy = ft_strdup(str);
		printf("ft_strdup = %s\n", cpy);
		free(str);
		free(cpy);
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
			free(str);
			free(cpy);
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
		free(str);
	}
	return (0);
}

static int	call_atoi_base(int *state)
{
	char	*str;
	char	*base;
	int		nbr;
	int		ret;
	pid_t	pid;

	ft_putstr("ft_atoi_base(char *str, char *base):\n*str = ");
	ret = get_str(state, &str);
	if (ret != 1)
		return (ret);
	ft_putstr("*base = ");
	ret = get_str(state, &base);
	if (ret != 1)
	{
		free(str);
		return (ret);
	}
	pid = fork();
	if (pid == 0)
	{
		nbr = ft_atoi_base(str, base);
		printf("return: nbr =  %d\n", nbr);
		free(str);
		free(base);
		exit (0);
	}
	else
	{
		waitpid(pid, &ret, 0);
		if (WIFSIGNALED(ret))
		{
			if (WTERMSIG(ret) == SIGSEGV)
			{
	  			ft_putstr("ft_atoi_base: segfault\n");
			}
		}
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
				"8.list test\n"
				"9.exit\n"
				"$ ");
	rec_gnl(0, &line);
	if (ft_strcmp(line, "exit") == 0 || ft_strcmp(line, "9") == 0)
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
	else if (ft_strcmp(line, "list test") == 0 || ft_strcmp(line, "8") == 0)
		*state = 8;
	else
		return (-1);
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	int		state;
	const t_func fsm[] = {get_input, call_strlen, call_strcpy, call_strcmp, call_write, call_read, call_strdup, call_atoi_base, call_list_test};

	state = 0;
	ft_putstr("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	ft_putstr("-_-_-_-_-_-_-_-_-_LIBASM_TESTER_-_-_-_-_-_-_-_-_-\n");
	ft_putstr("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	ft_putstr("\n");
	if (ac < 1 || ac > 2)
	{
		printf("Error: argument\n");
		return (-1);
	}
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "-i") == 0)
		{
			while (state != -1)
			{
				if (fsm[state](&state) < 0)
					printf("Error: input\n");
			}
			return (0);
		}
		else
		{
			printf("Error: argument\n");
			return (-1);
		}
	}
	else
		return (full_test());
}
