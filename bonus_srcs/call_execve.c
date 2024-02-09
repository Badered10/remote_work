/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:14:07 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 16:06:54 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	call_execev(char **env, char *argv)
{
	char	*cat[2];
	char	*founded_path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	founded_path = cmd_path(argv, env);
	if (!founded_path)
		show_err(argv);											
	// else if (!founded_path)
	// 	exit(EXIT_FAILURE);
	//--> NO CMD and fd is right , 
	/*
														|| case 4: in : true && cmd true  && out : true  : 1
														|| case 2: in : false && cmd true && out : true  : 1
														|| case 1: in : false && cmd false && out : true : 1
														|| case 3: in : true && cmd false && out : true  : 1
														
														|| case 6: in : false && cmd true && out : false : 1
														|| case 8: in: true && cmd true   && out : false : 1
														|| case 5: in false && cmd false && out : flase  : 1
														|| case 7: in : true && cmd false && out : false : 0
	*/
	cat[0] = "cat";
	cat[1] = NULL;
	if (*argv == '\0')
	{
		fprintf(stderr, "here pid: %d\n",getpid());
		free(founded_path);
		free_double(cmd);
		execve(cmd_path("cat", env), cat, env);
	}
	else
	{
		fprintf(stderr,"-------------------->path :%s, cmd : %s\n",founded_path,*cmd);
		// while(1);
		execve(founded_path, cmd, env);
	}
	print_err("pipex: permission denied: ", argv);
	exit(EXIT_FAILURE);
}