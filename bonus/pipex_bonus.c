/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 10:18:01 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	cmds_checker(t_fd fd, int argc, char **argv, char **env)
{
	fd.check_sum = fd.check_in + fd.check_out;
	if (fd.i_place != 1)
		check_cmds(fd, argc, argv, env);
	else
		check_cmds(fd, argc, argv, env);
}

static int	check_out_fd(int check, int argc, char **argv)
{
	if (check)
	{
		if (*argv[argc - 1] == '\0')
			print_err("pipex: no such file or directory: ", argv[argc - 1]);
		else
			print_err("pipex: permission denied: ", argv[argc - 1]);
		return (1);
	}
	return (0);
}

static int	check_last_cmd(char *cmd_set)
{
	char	*last_cmd;

	last_cmd = get_command(cmd_set);
	if (access(last_cmd, F_OK))
		return (free(last_cmd), NOT_FOUND);
	else
	{
		if (access(last_cmd, X_OK))
			return (free(last_cmd), PERMISSION_DENIED);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		cmds;
	t_fd	fd;
	int		i;
	int		doc;

	i = 0;
	if (argc < 5)
		return (ft_putstr_fd("Not enough arguments !", 2), INV_ARGS);
	doc = ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]));
	cmds = argc - (4);
	if (!doc)
		here_doc(&fd, argv, &i, &cmds);
	fd = open_fds(argc, argv, env, doc);
	fd.i_place = i;
	cmds_checker(fd, argc, argv, env);
	i += 2;
	while (cmds--)
		child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	if (!fd.check_out)
		return (check_last_cmd(argv[argc - 2]));
	return (check_out_fd(fd.check_out, argc, argv));
}
