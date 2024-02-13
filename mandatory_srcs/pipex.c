/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/13 19:02:20 by baouragh         ###   ########.fr       */
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

static int	check_last_cmd(char *cmd_set, int not_same)
{
	char	*last_cmd;

	last_cmd = get_command(cmd_set);
	if (access(last_cmd, F_OK) || !not_same)
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
	t_fd	fd;
	int		i;
	int		len;

	i = 0;
	if (argc != 5)
		return (print_err("Invaild number of args .", NULL), INV_ARGS);
	fd = open_fds(argc, argv, env, MADANTORY);
	fd.i_place = i;
	cmds_checker(fd, argc, argv, env);
	i += 2;
	child(fd, argv[i++], env, 0);
	child(fd, argv[i], env, 1);
	while (waitpid(-1, NULL, 0) != -1)
		;
	len = ft_strlen(argv[argc - 2]) + ft_strlen(argv[argc -1]);
	len = ft_strncmp(argv[argc - 2], argv[argc - 1], len);
	if (!fd.check_out)
		return (check_last_cmd(argv[argc - 2], len));
	return (check_out_fd(fd.check_out, argc, argv));
}

/*
	for this project the the main key of succeed is execve()
	it needs 3 arguments , fullpath of executable file (cmd)
	and the cmd plus its args(double char pointer), and the
	last argument of this func is environment pointer .
	if execve() obtained all its args succefully it will 
	be the end of the current process that call execve() and it will
	lunch new process that replace the old one with the cmd
	we asking for.
	
	pseudocode;
	
	1 ---> check args must be  5; otherways threw error.
	
	2 ---> open fd for infile and outfile ; if fd is right 
	dup it to stdin to pass its content as input to the pipe;
	otherways if fd false open a tmp file to pass its empty content 
	to hundle such cases like command cat taht need input or will hang.
	
	3 ---> check cmds if they are right depending of mods cases,
	print in stderr error if command not found and continue the process
	
	4 ---> create pipe to contact with processes
	
	5 ---> fork the code to make copy of its ressources.
	
	6 --->  in child close inused fds and write output to pipe
	
	7 ---> in parent close inused write to pipe fd , 
	and dup stdin to pipe , and unlink the hidden file if exist.
	
	8 ---> repeat from 4 to 7 but in 6 write to outfile file instead of pipe.
	
	9 ---> in parent wait for all childs processes to finsh
	
	10 ---> if outfile created succeesfully check last cmd 
	if its true ot false , if its true do nothing , else threw the 
	the right return value (126 permission denied)(127 cmd not found)
	or 0 (succeed)
*/