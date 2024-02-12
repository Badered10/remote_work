/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:14:07 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 11:50:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	call_execev(char **env, char *argv)
{
	char	*cat[2];
	char	*founded_path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	check_split(cmd);
	founded_path = get_fullpath(argv, env);
	if (!founded_path)
		exit(EXIT_FAILURE);
	cat[0] = "cat";
	cat[1] = NULL;
	if (*argv == '\0')
	{
		free(founded_path);
		free_double(cmd);
		execve(get_fullpath("cat", env), cat, env);
	}
	else
		execve(founded_path, cmd, env);
	exit(EXIT_FAILURE);
}

/*
while(1);
else if (!founded_path)
	exit(EXIT_FAILURE);
--> NO CMD and fd is right ,
|| case 4: in : true && cmd true && out : true  : 0
|| case 2: in : false && cmd true && out : true  : 0
|| case 1: in : false && cmd false && out : true : 0
|| case 3: in : true && cmd false && out : true  : 0
|| case 6: in : false && cmd true && out : false : 0
|| case 8: in: true && cmd true   && out : false : 0
|| case 5: in false && cmd false && out : flase  : 0
|| case 7: in : true && cmd false && out : false : 0
*/