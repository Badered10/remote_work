/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 02:48:23 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;

	i = 0;
	if (argc != 5)
		return (print_err("Invaild number of arguments.\n Check how much args you enterd !, For successful run it must be 5 !",NULL),INVALID_ARGUMENTS);
	cmds = argc - (4);
	fd = open_fds(argc, argv, env, Madantory);
	i += 2;
	child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!get_fullpath(argv[argc - 2], env))
		return (NOT_FOUND);
	return (0);
}

// case 7: in : true && cmd false && out : false : 0  solved !!!
// to fix : add envp as arg solved !!!
// ./ls --> CMD_false -->check if  / and check exe ,

//  --> check exe directly  solved !!!