/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_outfile_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:22 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:11:24 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	creat_outfile_fd(int argc, t_fd *fd, char **argv)
{
	fd->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile < 0)
	{
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (-1);
	}
	return (0);
}
