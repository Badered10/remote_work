/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/10 15:31:49 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;
	int		doc;

	i = 0;
	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !\n", 2), 1);
	cmds = argc - (4);
	fd = open_fds( argc, argv ,env , doc);
	if (!doc)
		here_doc(fd ,argv, &i, &cmds);
	i += 2;
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!cmd_path(argv[argc - 2], env))
		return (NOT_FOUND);
	return (0);
}







// case 7: in : true && cmd false && out : false : 0  solved !!!
// to fix : add envp as arg solved !!!
// ./ls --> CMD_false -->check if  / and check exe ,














//  --> check exe directly  solved !!! 