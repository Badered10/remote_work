/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:06:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 10:23:28 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

static void	check_sum_cases(int *i, int *cmds, int mod)
{
	if (*i == 0)
	{
		*cmds++;
		*i = 2;
	}
	else if (*i == 1)
		*i = 3;
	else if (*i == 3)
		*i = 2;
	else if (*i == 4)
	{
		*i = 3;
		*cmds--;
	}
	if (mod)
		*i++;
}

void	check_cmds(t_fd fd, int argc, char **argv, char **env)
{
	int		cmds;
	char	*cmd;
	int		mod;
	int		i;

	i = fd.check_sum;
	mod = fd.i_place;
	cmds = argc - 4;
	check_sum_cases(i, cmds, mod);
	while (cmds--)
	{
		cmd = get_fullpath(argv[i], env);
		if (access(cmd, F_OK) && *argv[i] != '\0')
			print_err("pipex: command not found: ", argv[i]);
		else if (access(cmd, X_OK) && *argv[i] != '\0')
			print_err("pipex: permission denied: ", argv[i]);
		free(cmd);
		i++;
	}
}

// case 4: infile true , outfile true --> check all cmds. ---> 0
// case 2: infile false , outfile true --> skip first cmd. ---> 1
// case 3: infile true , outfile false --> skip last cmd. ---> 3
// case 1: infile false , outfile false --> sipk both first and last. ---> 4
