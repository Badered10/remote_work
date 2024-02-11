/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_outfile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:22 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 01:35:35 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	creat_outfile_fd(int argc, t_fd *fd, char **argv, char **env)
{
	fd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile < 0)
	{
		check_cmds(OUTFILE_CHECK, argc, argv, env);
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (-1);
	}
	else
		check_cmds(OUTFILE_CHECK, argc, argv, env);
	return (0);
}
