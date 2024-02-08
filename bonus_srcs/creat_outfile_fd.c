/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_outfile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:22 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/08 22:59:05 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	creat_outfile_fd(int argc, t_fd *fd, char **argv, char **env)
{
	int cmds;
	int i;

	i = 2;
	cmds = argc - 4;
	fd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile < 0)
	{
			while(cmds--)
			{
				if (access(cmd_path(argv[i],env),F_OK))
					print_err("pipex: command not found: ", argv[i]);
					else if (access(cmd_path(argv[i],env),X_OK))
						print_err("pipex: permission denied: ", argv[i]);
				i++;
			}
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (-1);
	}
	return (0);
}
