/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 02:28:12 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

static int	open_hidden_file(void)
{
	int fd;

	fd = open(".tmp.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
	if (fd < 0)
	{
		perror("here_doc failed to get input");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

t_fd	open_fds(int argc, char **argv, char **env, int here_doc_check)
{
	t_fd	fd;
	int		fd1;

	if (here_doc_check)
	{
		fd.check_in = creat_infile_fd(argc, &fd, argv, env);
		fd.check_out = creat_outfile_fd(argc, &fd, argv, env);
		if (fd.check_out)
			exit(EXIT_FAILURE);
		if (!fd.check_in)
			dup_2(fd.infile, 0, 0);
		else
		{
			fd1 = open_hidden_file();
			dup_2(fd1, 0, 0);
		}
		return (fd);
	}
	else
		return (open_fds_doc(argc, argv, env));
}
