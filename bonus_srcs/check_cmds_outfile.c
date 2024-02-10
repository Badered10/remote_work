/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds_outfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:06:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 22:41:03 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	check_cmds_outfile(int i , int argc ,char **argv,char **env)
{
	int cmds;
	char *cmd;

	cmds = argc - 4;
		while(cmds--)
			{
				cmd = cmd_path(argv[i],env);
				if (access(cmd,F_OK) && *argv[i] != '\0')
					print_err("pipex: command not found: ", argv[i]);
					else if (access(cmd,X_OK) && *argv[i] != '\0')
						print_err("pipex: permission denied: ", argv[i]);
				free(cmd);
				i++;
			}
}