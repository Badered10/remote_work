/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:09:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/08 15:51:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

t_fd	open_fds_doc(int argc, char **argv)
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
		doc_fd.check_in = -1;
		exit(EXIT_FAILURE);
	}
	fd1 = open("tmp.txt", O_CREAT | O_RDONLY, 0777);
	dup_2(fd1, 0, 0);
	doc_fd.check_out = 0;
	doc_fd.check_in = -1;
	return (doc_fd);
}
