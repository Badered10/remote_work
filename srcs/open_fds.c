/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:11:57 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_fd	open_fds(int argc, char **argv, int here_doc_check)
{
	t_fd	fd;
	int		fd1;

	if (!here_doc_check)
	{
		fd.check_in = crear_infile_fd(&fd, argv);
		fd.check_out = creat_outfile_fd(argc, &fd, argv);
		if (fd.check_out)
			exit(EXIT_FAILURE);
		if (!fd.check_in)
			dup_2(fd.infile, 0, 0);
		else
		{
			fd1 = open("tmp.txt", O_CREAT | O_RDONLY, 0777);
			dup_2(fd1, 0, 0);
		}
		return (fd);
	}
	else
		return (open_fds_doc(argc, argv));
}
