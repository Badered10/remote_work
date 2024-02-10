/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:14:27 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/10 15:31:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child(t_fd fd, char *argv, char **env, int mod)
{
	int		id;
	int		pfd[2];

	open_pipe(pfd);
	id = fork();
	if (id < 0 )
	{
		print_err("pipex: error occuerd with fork!",NULL);
		exit(EXIT_FAILURE);
	}
	if (id == 0)
	{
		fd_duper(fd, mod, pfd);
		// while(1);
		call_execev(env, argv);
	}
	else
	{
		// wait(NULL); /// to remvoe 
		close(pfd[1]);
		dup_2(pfd[0], 0, 3);
		unlink("tmp.txt");
	}
}
