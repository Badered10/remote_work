/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/05 12:33:32 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int	strings_count(char **str)
{
	char	**save;

	if (!str)
		return (-1);
	save = str;
	while (*str)
		str++;
	return (str - save);
}

static void	free_double(char **ptr)
{
	char	**save;

	save = ptr;
	while (*save)
	{
		free(*save);
		save++;
	}
	free(ptr);
}

static char	**get_env_paths(char **env)
{
	char	**res;

	while (*env && !ft_strnstr(*env, "PATH", 5))
		env++;
	if (!*env)
		return (NULL);
	res = ft_split(*env, ':');
	*res = ft_strchr(*res, '/');
	return (res);
}

static char	*check_path(char *path, char *cmd)
{
	char	*a_path;
	char	*fullpath;

	a_path = (ft_strjoin(path, "/"));
	fullpath = ft_strjoin(a_path, cmd);
	if (!access(fullpath, X_OK))
		return (free(a_path), fullpath);
	else
		return (free(fullpath), free(a_path), NULL);
}

static void	show_err(char *argv)
{
	char	*err;
	char	*display;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	err = ft_strjoin("pipex: command not found: ", *cmd);
	display = ft_strjoin(err, "\n");
	write(2, display, ft_strlen(display));
	free(err);
	free(display);
	free_double(cmd);
}

static char	*cmd_path(char *argv, char **env)
{
	int		paths_num;
	char	**cmd;
	char	**paths;
	char	*fullpath;
	int		i;

	i = 0;
	fullpath = NULL;
	paths = get_env_paths(env);
	paths_num = strings_count(paths);
	if (paths_num == -1)
		return (NULL);
	cmd = ft_split(argv, ' ');
	if (!*cmd)
		return (ft_strdup(""));
	if (*argv == '/' && access(*cmd, X_OK) == 0)
		return (ft_strdup(*cmd));
	else
	{
		while (paths_num-- > 0 && !fullpath)
			fullpath = check_path(paths[i++], *cmd);
		return (fullpath);
	}
	show_err(argv);
	exit(1);
}

t_fd	open_fds(int argc, char **argv)
{
	t_fd	fd;

	fd.outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd.outfile < 0)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(argv[argc - 1], 2);
		write(2, "\n", 1);
		exit(1);
	}
	fd.infile = open(argv[1], O_RDONLY);
	if (fd.infile < 0)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		write(2, "\n", 1);
		exit(INFILE_NOT_FOUND);
	}
	return (fd);
}

void	dup_2(int old, int new)
{
	if (dup2(old, new) < 0)
	{
		perror("dup2 failed");
		exit(errno);
	}
	close(old);
}

void	fd_manager(t_fd fd, int mod, int *pfd)
{
	if (mod == LAST_CMD)
	{
		dup_2(fd.outfile, 1);
		close(pfd[1]);
	}
	else
	{
		dup_2(pfd[1], 1);
		close(fd.outfile);
	}
}

void	open_pipe(int *pfd)
{
	if (pipe(pfd))
	{
		perror("pipe:");
		exit(errno);
	}
}

void	call_execev(char **env, char **cmd, char *argv, char *founded_path)
{
	char	*cat[2];

	cat[0] = "cat";
	cat[1] = NULL;
	if (*argv == '\0')
		execve(cmd_path("cat", env), cat, NULL);
	else
		execve(founded_path, cmd, NULL);
}

void	child(t_fd fd, char *argv, char **env, int mod)
{
	char	**cmd;
	char	*founded_path;
	int		id;
	int		pfd[2];

	open_pipe(pfd);
	id = fork();
	if (id == 0)
	{
		cmd = ft_split(argv, ' ');
		founded_path = cmd_path(argv, env);
		fd_manager(fd, mod, pfd);
		call_execev(env, cmd, argv, founded_path);
	}
	else
	{
		close(pfd[1]);
		wait(NULL);
		dup_2(pfd[0], 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		id;
	int		cmds;
	t_fd	fd;
	int		i;
	char 	*buffer;
	char	*read_buf;

	buffer  = ft_strnstr(argv[1],"here_doc",strlen(argv[1]));
	read	
	i = 0;
	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !\n", 2), 1);
	if (buffer)
	{
		write(1,"herdoc> ",sizeof("herdoc> "));
		while(read(0,NULL,strlen(buffer)) > 0)
			printf("hello\n");
	}
	if (buffer)
		i+=1;
	i += 2;
	cmds = argc - (4);
	fd = open_fds(argc, argv);
	dup_2(fd.infile, 0);
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	return (0);
}
