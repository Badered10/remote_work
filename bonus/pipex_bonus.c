/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:53 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 16:18:28 by baouragh         ###   ########.fr       */
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

/*
	for this project the the main key of succeed is execve()
	it needs 3 arguments , fullpath of executable file (cmd)
	and the cmd plus its args(double char pointer), and the
	last argument of this func is environment pointer .
	if execve() obtained all its args succefully it will 
	be the end of the current process that call execve() and it will
	lunch new process that replace the old one with the cmd
	we asking for.
	

	almost same algo as madantory part despite checking in args 
	msut be at least 5 and (here_doc case and multiple pipes)...
	
	pseudocode:
	
	1 ---> check args must be at least 5; otherways threw error.
	
	2 ---> if the arg 2 not "here_doc"open fd for infile 
	and outfile ; if fd is right dup it to stdin to pass its content
	as input to the pipe; otherways if fd false open a tmp file to
	pass its empty content to hundle such cases like command cat taht
	need input or will hang.
	in here_doc case open fd for a hidden file to write in it 
	the input that user write in stdin, and open outfile file
	
	2.1 ---> re open the hidden file to get a new file pointer 
	the offset of it will be 0 to past it as input to the first cmd 
	
	3 ---> check cmds if they are right depending of mods cases,
	print in stderr error if command not found and continue the process
	
	4 ---> create pipe to contact with processes
	
	5 ---> fork the code to make copy of its ressources.
	
	6 --->  in child close inused fds and write output to pipe
	
	7 ---> in parent close inused write to pipe fd , 
	and dup stdin to pipe , and unlink the hidden file if exist.
	
	8 ---> repeat from 4 to 7 (cmds -1) times 
	
	8.1 ----> in last cmd case in 6 write to outfile file instead of pipe.
	
	9 ---> in parent wait for all childs processes to finsh
	
	10 ---> if outfile created succeesfully check last cmd 
	if its true ot false , if its true do nothing , else threw the 
	the right return value (126 permission denied)(127 cmd not found)
	or 0 (succeed)
*/