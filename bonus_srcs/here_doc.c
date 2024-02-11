/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:15:09 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/10 23:42:31 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	open_hidden_file(t_fd *doc_fd)
{
	doc_fd->infile = open(".tmp.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
	if (doc_fd->infile < 0)
	{
		perror("here_doc failed to get input");
		exit(EXIT_FAILURE);
	}
	doc_fd->check_in = 0;
}

static int	re_open_hidden_file(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror("here_doc failed to get input");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static void	read_input(char *read_buf)
{
	int	bytes_readed;

	bytes_readed = 0;
	bytes_readed = read(0, read_buf, MAX_INPUT);
	read_buf[bytes_readed] = 0;
	if (read_buf[bytes_readed - 1] != '\n')
		write(1, "\n", 1);
}

void	here_doc(t_fd *fd, char **argv, int *i, int *cmds)
{
	int		pipetimes;
	char	read_buf[(MAX_INPUT + 1)];
	int		fd_hidden;

	open_hidden_file(fd);
	read_buf[0] = '\0';
	while (1)
	{
		pipetimes = (*cmds) - 1;
		while (pipetimes--)
			write(1, "pipe ", 5);
		write(1, "heredoc> ", sizeof("heredoc> "));
		read_input(read_buf);
		while (read_buf[0] == '\0')
			read_input(read_buf);
		if (ft_strncmp(argv[2], read_buf, (ft_strlen(read_buf) - 1)))
			write(fd->infile, read_buf, ft_strlen(read_buf));
		else
			break ;
	}
	fd_hidden = re_open_hidden_file(".tmp.txt");
	dup_2(fd_hidden, 0, 0);
	(*i) = 1;
	(*cmds)--;
}
