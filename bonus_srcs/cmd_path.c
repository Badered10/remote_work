/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:07:20 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 16:15:08 by baouragh         ###   ########.fr       */
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
	{
		fprintf(stderr,"---------------------> 0  cmd : |%s| argv: |%s| , pid: %d return always (cat) \n",*cmd, argv, getpid());
		return (free_double(cmd),free_double(paths),ft_strdup("cat"));
	}
	else if (*argv == '/' && access(*cmd, X_OK) == 0)
	{
		fprintf(stderr,"---------------------> 1  cmd : |%s| argv: |%s| , pid: %d \n",*cmd, argv, getpid());
		return (free_double(paths),free_double(cmd),get_command(argv));
	}
	else if(access(*cmd, F_OK) == 0)
	{
		fprintf(stderr,"---------------------> 2 cmd : |%s| argv: |%s| , pid: %d\n",*cmd, argv, getpid());
		return (free_double(paths),free_double(cmd),get_command(argv));
	}
	else
	{
		while (paths_num-- > 0 && !fullpath)
		{
			fullpath = check_path(paths[i++], *cmd);
			// fprintf(stderr,"---------------------> 2 , |fullpath:%s| |cmd:%s|\n",fullpath, *cmd);			
		}
	}
		fprintf(stderr,"---------------------> 3 cmd : |%s| argv: |%s| , pid: %d\n",*cmd, argv, getpid());
	return (free_double(cmd),free_double(paths),fullpath);
}
