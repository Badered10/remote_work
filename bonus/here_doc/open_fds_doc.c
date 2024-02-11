/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:09:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 01:31:46 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

t_fd	open_fds_doc(int argc, char **argv, char **env)
{
	t_fd	doc_fd;

	doc_fd.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (doc_fd.outfile < 0)
	{
		check_cmds(INFILE_CHECK, argc, argv, env);
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		doc_fd.check_out = -1;
		exit(EXIT_FAILURE);
	}
	else
		check_cmds(INFILE_CHECK, argc, argv, env);
	doc_fd.check_out = 0;
	return (doc_fd);
}
