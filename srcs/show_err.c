/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:06:37 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:08:18 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	show_err(char *argv)
{
	char	*err;
	char	*display;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	err = ft_strjoin("pipex: command not found: ", *cmd);
	display = ft_strjoin(err, "\n");
	write(2, display, ft_strlen(display));
	free(err);
	free(display);
	free_double(cmd);
	exit(NOT_FOUND);
}
