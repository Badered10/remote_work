/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:15:09 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/10 22:51:49 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	here_doc(t_fd fd, char **argv, int *i, int *cmds)
{
	int		pipetimes;
	char	read_buf[(MAX_INPUT + 1)];
	int		bytes_readed;
	int		fd;

	read_buf[0] = '\0';
		while (1)
		{
			pipetimes = (*cmds) - 1;
				while (pipetimes--)
					write(1, "pipe ", 5);
				write(1, "heredoc> ", sizeof("heredoc> "));
				bytes_readed = read(0, read_buf, MAX_INPUT);
				read_buf[bytes_readed] = 0;
			while (read_buf[0] == '\0')
			{
				bytes_readed = read(0, read_buf, MAX_INPUT);
				read_buf[bytes_readed] = 0;
			}
			if(ft_strncmp(argv[2], read_buf, (ft_strlen(read_buf) - 1)))
				write(fd.infile,read_buf,ft_strlen(read_buf));
			else
				break;
		}
		fd = open("tmp.txt", O_RDONLY);
		dup_2(k, 0, 0);
		(*i) = 1;
		(*cmds)--;
}
