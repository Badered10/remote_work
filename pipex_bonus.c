/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 16:08:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;
	int		here_doc_check;


	fprintf(stderr,"parent pid: %d\n",getpid());
	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !\n", 2), 1);
	cmds = argc - (4);
	here_doc_check = here_doc(argv, &i, &cmds);
	i += 2;
	fd = open_fds( argc, argv ,env , here_doc_check);
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!cmd_path(argv[argc - 2], env))
		return (NOT_FOUND);

	// while(1);
	// system("leaks pipex");
	return (0);
}







// case 7: in : true && cmd false && out : false : 0  solved !!!
// to fix : add envp as arg solved !!!
// ./ls --> CMD_false -->check if  / and check exe ,














//  --> check exe directly  solved !!! 