/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 10:29:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../headers/libft.h"
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>

/*
	Flag stands for the exit value 10 in case
		of the arguments are less or great than 5 for Mandotory,
		In bonus case it just means less than 5.
*/
# define INV_ARGS 10 
/*
	Flag to tell open_fds() taht there is 
		no here_doc here because its jut a mandatory !
*/
# define MADANTORY -1
/*
	Flag to tell child() its now the last command to write
		the output to the outfile; output taken perviousely from pipe.
*/
# define LAST_CMD 1
/*
	Stands for argv[2], to start from the fisrt
		command (cmds - 1) times to exclude the last command.
*/
# define OUTFILE_CHECK 2
/*
	Stands for argv[3], to start from the second
		command (cmds - 1) times to exclude the first command.
*/
# define INFILE_CHECK 3
# define NOT_FOUND 127
# define PERMISSION_DENIED 126

typedef struct s_openfd
{
	int	check_in;
	int	check_out;
	int	infile;
	int	outfile;
	int	check_sum;
	int	i_place;
}				t_fd;
/*
	Open fds for "Multiple pipes" case.
*/
t_fd	open_fds(int argc, char **argv, char **env, int here_doc_check);
int		create_infile_fd(t_fd *fd, char **argv);
int		create_outfile_fd(int argc, t_fd *fd, char **argv, char **env);
/*
	Open fds for "her_doc" case.
*/
void	here_doc(t_fd *fd, char **argv, int *i, int *cmds);
t_fd	open_fds_doc(int argc, char **argv, char **env);
/*
	Commands funcs.
*/
char	*add_slash_cmd(char *path, char *cmd);
char	*get_fullpath(char *argv, char **env);
char	*get_command(char *argv);
char	**get_env_paths(char **env);
void	check_cmds(t_fd fd, int argc, char **argv, char **env);
/*
	Safe dup2 that close the old fd after dup it to new.
*/
/*
	Child process funcs.
*/
void	child(t_fd fd, char *argv, char **env, int mod);
void	open_pipe(int *pfd);
void	fd_duper(t_fd fd, int mod, int *pfd);
void	call_execev(char **env, char *argv);
/*
	Tools funcs.
*/
int		dup_2(int old, int new);
int		strings_count(char **str);
void	check_split(char **cmd);
void	free_double(char **ptr);
void	print_err(char *message, char *word);

#endif