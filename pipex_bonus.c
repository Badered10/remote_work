/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:52:30 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;
	int		here_doc_check;

	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !\n", 2), 1);
	cmds = argc - (4);
	here_doc_check = here_doc(argv, &i, &cmds);
	i += 2;
	fd = open_fds(argc, argv, here_doc_check);
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!cmd_path(argv[argc - 2], env))
		return (NOT_FOUND);
	// system("leaks a.out");
	return (0);
}
