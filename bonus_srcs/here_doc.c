/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:15:09 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 23:34:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	here_doc(char **argv, int *i, int *cmds)
{
	int		pipetimes;
	int		doc;
	char	read_buf[(MAX_INPUT + 1)];
	int		bytes_readed;

	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	read_buf[0] = '\0';
	printf("%s\n",read_buf);
	if (!doc)
	{
		while (ft_strncmp(argv[2], read_buf, (ft_strlen(read_buf) - 1)))
		{
			pipetimes = (*cmds) - 1;
			if (read_buf[0] != '\0')
			{
				while (pipetimes--)
					write(1, "pipe ", 5);
				write(1, "heredoc> ", sizeof("heredoc> "));
			}
			bytes_readed = read(0, read_buf, MAX_INPUT);
			read_buf[bytes_readed] = 0;
		}
		(*i) = 1;
		(*cmds)--;
		return (1);
	}
	*i = 0;
	return (0);
}
