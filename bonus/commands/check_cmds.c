/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:06:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 12:00:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

/*
	* We consederd that the start of command is always start from 2. 
	so if we need to skip the fisrt cmd we need to add 1 to 2 so it will be 3;
	index = 3; ---> skip first command.
	
	* Also it is important to know that the cmds sum that i pass to this funcs,
	i exclude the last one from counting.
	
	* so if i want to exclude the last one i leave cmds at the current value ,
	under one condition if that the index is equal to 2.
	otherways in case of index = 3 (skip first cmd), i need to
	substract 1 from cmds.
	
	 case 1: infile true , outfile true --> check all cmds. ---> 0 <--> 0 + 0
	 case 2: infile false , outfile true --> skip first cmd. ---> 1 <--> 0 + 1
	 case 3: infile true , outfile false --> skip last cmd. ---> 3 <--> 3 + 0
	 case 4: infile false , outfile false --> sipk both ---> 4 <--> 3 + 1
	 	(first and last).
*/

static void	check_sum_cases(int *index, int *cmds, int mod)
{
	if (*index == CHECK_ALL)
	{
		(*cmds)++;
		(*index) = 2;
	}
	else if (*index == SKIP_FIRST)
		(*index) = 3;
	else if (*index == SKIP_LAST)
		(*index) = 2;
	else if (*index == SKIP_FAL)
	{
		(*index) = 3;
		(*cmds)--;
	}
	if (mod)
		(*index)++;
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
	check_sum_cases(&i, &cmds, mod);
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
