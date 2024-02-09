/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_infile_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:00 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 22:40:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	creat_infile_fd(int argc, t_fd *fd, char **argv, char **env)
{
	fd->infile = open(argv[1], O_RDONLY);
	if (fd->infile < 0)
	{
		if (access(argv[1], F_OK))
			print_err("pipex: no such file or directory: ", argv[1]);
		else
			print_err("pipex: permission denied: ", argv[1]);
		check_cmds_outfile(3,argc ,argv,env);
		return (-1);
	}
	return (0);
}
