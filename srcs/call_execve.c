/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:14:07 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:14:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	call_execev(char **env, char *argv, t_fd fd)
{
	char	*cat[2];
	char	*founded_path;
	char	**cmd;

	cmd = get_command(argv);
	founded_path = cmd_path(argv, env);
	if (!founded_path && !fd.check_in)
		show_err(argv);
	else if (!founded_path)
		exit(EXIT_FAILURE);
	cat[0] = "cat";
	cat[1] = NULL;
	if (*argv == '\0')
		execve(cmd_path("cat", env), cat, NULL);
	else
		execve(founded_path, cmd, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}
