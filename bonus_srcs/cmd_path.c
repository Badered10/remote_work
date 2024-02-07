/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:07:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:12 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*cmd_path(char *argv, char **env)
{
	int		paths_num;
	char	**cmd;
	char	**paths;
	char	*fullpath;
	int		i;

	i = 0;
	fullpath = NULL;
	paths = get_env_paths(env);
	paths_num = strings_count(paths);
	cmd = ft_split(argv, ' ');
	if (!*cmd)
		return (free_double(cmd),free_double(paths),ft_strdup(""));
	if (*argv == '/' && access(*cmd, X_OK) == 0)
		return (ft_strdup(*cmd));
	else
	{
		while (paths_num-- > 0 && !fullpath)
			fullpath = check_path(paths[i++], *cmd);
	}
	return (free_double(cmd),fullpath);
}
