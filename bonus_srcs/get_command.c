/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:13:44 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 16:00:02 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*get_command(char *argv)
{
	char	*cmd;
	int 	i;

	i = 0;
	while (argv[i] != ' ' && argv[i] != '\0')
			i++;
	cmd = malloc(i + 1);
	ft_memmove(cmd ,argv, i);
	cmd[i] = '\0';
	return (cmd);
}
