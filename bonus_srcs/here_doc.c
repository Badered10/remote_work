/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:15:09 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:36 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	here_doc(char **argv, int *i, int *cmds)
{
	int		pipetimes;
	int		doc;
	char	read_buf[(MAX_INPUT + 1)];

	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	read_buf[0] = '\0';
	if (!doc)
	{
		while (ft_strncmp(argv[2], read_buf, ft_strlen(argv[2])))
		{
			pipetimes = (*cmds) - 1;
			while (pipetimes--)
				write(1, "pipe ", 5);
			write(1, "heredoc> ", sizeof("heredoc> "));
			read(0, read_buf, MAX_INPUT);
			read_buf[MAX_INPUT] = 0;
		}
		(*i)++;
		(*cmds)--;
		return (1);
	}
	*i = 0;
	return (0);
}
