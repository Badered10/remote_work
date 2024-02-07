/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 12:03:05 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
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
	exit(NOT_FOUND);
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
	cmd = ft_split(argv, ' ');
	if (!*cmd)
		return (ft_strdup(""));
	if (*argv == '/' && access(*cmd, X_OK) == 0)
		return (ft_strdup(*cmd));
	else
	{
		while (paths_num-- > 0 && !fullpath)
			fullpath = check_path(paths[i++], *cmd);
	}
	return (fullpath);
}

static void	print_err(char *message, char *word)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(word, 2);
	write(2, "\n", 1);
}
int	dup_2(int old, int new, int mod)
{
	if (dup2(old, new) < 0)
	{
		if (mod == 0)
			perror("dup2 -> infile ");
		if (mod == 1)
			perror("dup2 -> outfile ");
		if (mod == 2)
			perror("dup2 -> pipe ");
			return(-1);
	}
	close(old);
	return (0);
}

static t_fd	open_fds_doc(int argc, char **argv)
{
	t_fd	doc_fd;
	int		fd1;

	doc_fd.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (doc_fd.outfile < 0)
	{
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		doc_fd.check_out = -1;
		exit(EXIT_FAILURE);
	}
	fd1 = open("tmp.txt",O_CREAT | O_RDONLY , 0777);
		dup_2(fd1, 0, 0);
	doc_fd.check_out = 0;
	doc_fd.check_in = 0;
	return (doc_fd);
}

int	infile(t_fd *fd, char **argv)
{
	fd->infile = open(argv[1], O_RDONLY);
	if (fd->infile < 0)
	{
		if (access(argv[1], F_OK))
			print_err("pipex: no such file or directory: ", argv[1]);
		else
			print_err("pipex: permission denied: ", argv[1]);
		return (-1);
	}
	return (0);
}

int	outfile(int argc, t_fd *fd, char **argv)
{
	fd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile < 0)
	{
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (-1);
	}
	return (0);
}



static t_fd	open_fds(int argc, char **argv, int here_doc_check)
{
	t_fd	fd;
	int		fd1;
	if (!here_doc_check)
	{
		fd.check_in = infile(&fd, argv);
		fd.check_out = outfile(argc, &fd, argv);
		if (fd.check_out)
			exit(EXIT_FAILURE);
		if (!fd.check_in)
			dup_2(fd.infile, 0, 0);
		else
		{
			fd1 = open("tmp.txt",O_CREAT | O_RDONLY , 0777);
			dup_2(fd1, 0, 0);
		}
		return (fd);
	}
	else
		return (open_fds_doc(argc, argv));
}
void	fd_duper(t_fd fd, int mod, int *pfd)
{
	if (mod == LAST_CMD)
	{
		close(pfd[1]);
		close(pfd[0]);
		if(dup_2(fd.outfile, 1, 1))
			exit(EXIT_FAILURE);
	}
	else
	{
		close(fd.outfile);
		close(pfd[0]);
		if(dup_2(pfd[1], 1, 3))
			exit(EXIT_FAILURE);
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

char	**get_command(char *argv) // argv : "grep 'hello' "
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	return (cmd);
}

void	call_execev(char **env, char *argv, t_fd fd)
{
	char	*cat[2];
	char	*founded_path;
	char	**cmd;

	cmd = get_command(argv);
	founded_path = cmd_path(argv, env);
	if (!founded_path && !fd.check_in)
		show_err(argv);
	else if (!founded_path)
		exit(EXIT_FAILURE);
	cat[0] = "cat";
	cat[1] = NULL;
	if (*argv == '\0')
		execve(cmd_path("cat", env), cat, NULL);
	else
		execve(founded_path, cmd, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	child(t_fd fd, char *argv, char **env, int mod)
{
	char	*founded_path;
	int		id;
	int		pfd[2];

	open_pipe(pfd);
	id = fork();
	if (id == 0)
	{
		fd_duper(fd, mod, pfd);
		call_execev(env, argv, fd);
	}
	else
	{
		close(pfd[1]);
		dup_2(pfd[0], 0, 3);
	}
}

int	here_doc(char **argv, int *i, int *cmds)
{
	int		pipetimes;
	int		doc;
	char	read_buf[(MAX_INPUT + 1)];

	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	read_buf[0] = '\0';
	if (!doc)
	{
		while (ft_strncmp(argv[2], read_buf, ft_strlen(argv[2])))
		{
			pipetimes = (*cmds) - 1;
			while (pipetimes--)
				write(1, "pipe ", 5);
			write(1, "heredoc> ", sizeof("heredoc> "));
			read(0, read_buf, MAX_INPUT);
			read_buf[MAX_INPUT] = 0;
		}
		(*i) ++;
		(*cmds) --;
		return (1);
	}
	*i = 0;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		id;
	int		cmds;
	t_fd	fd;
	int		i;
	int		here_doc_check;
	int 	fd1;

	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !\n", 2), 1);
	cmds = argc - (4);
	here_doc_check = here_doc(argv, &i, &cmds);
	i += 2;
	fd = open_fds(argc, argv, here_doc_check);
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!cmd_path(argv[argc - 2], env))
		return (NOT_FOUND);
	unlink("tmp.txt");
	system("leaks a.out");
	return (0);
}


// fprintf(stderr,"argv :|%s|\n",argv);
// while (cmd[i])
// {
// 	fprintf(stderr,"%s\n",cmd[i]);
// 	i++;
// }
// exit(200);
// int		i = 0;

// char 	*search_replace(char *string , int target, int substitute)
// {
// 	int		i;
// 	int		apostrophes;
// 	int		len;

// 	apostrophes = 0;
// 	i = 0;

// 	while((string)[i])
// 	{
// 		fprintf(stderr,"char is '%c'\n",(string)[i]);
// 		if ((string)[i] == target)
// 			apostrophes++;
// 		i++;
// 	}
// 	i = 0;
// 	len = ft_strlen(string) - apostrophes;
// 	while((string)[i])
// 	{
// 		while (string[i] != 39)
// 		fprintf(stderr,"char is '%c'\n",(string)[i]);

// 		i++;
// 	}
// 	return (string);
// }

// char 	*tmp;
// int		apostrophe;
// int		args;

// apostrophe = 0;
// if (ft_strchr(argv, 39))
// 		apostrophe = 1;
// if (apostrophe)
// {
// 	tmp = search_replace(argv , 39, 34);
// }