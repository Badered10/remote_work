/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:14:27 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:14:30 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	child(t_fd fd, char *argv, char **env, int mod)
{
	char	*founded_path;
	int		id;
	int		pfd[2];

	open_pipe(pfd);
	id = fork();
	if (id == 0)
	{
		fd_duper(fd, mod, pfd);
		call_execev(env, argv, fd);
	}
	else
	{
		close(pfd[1]);
		dup_2(pfd[0], 0, 3);
		unlink("tmp.txt");
	}
}
