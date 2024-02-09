/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/09 11:13:38 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../headers/libft.h"
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

# ifndef LAST_CMD
#  define LAST_CMD 1
# endif

# ifndef NOT_FOUND
#  define NOT_FOUND 127
# endif


typedef struct s_openfd
{
	int	check_in;
	int	check_out;
	int	infile;
	int	outfile;
}				t_fd;

void	call_execev(char **env, char *argv);
char	*check_path(char *path, char *cmd);
void	child(t_fd fd, char *argv, char **env, int mod);
char	*cmd_path(char *argv, char **env);
int		creat_infile_fd(t_fd *fd, char **argv);
int		creat_outfile_fd(int argc, t_fd *fd, char **argv, char **env);
int		dup_2(int old, int new, int mod);
void	fd_duper(t_fd fd, int mod, int *pfd);
void	free_double(char **ptr);
char	*get_command(char *argv);
char	**get_env_paths(char **env);
int		here_doc(char **argv, int *i, int *cmds);
t_fd	open_fds_doc(int argc, char **argv);
t_fd	open_fds(int argc,char **argv, char **env ,int here_doc_check);
void	open_pipe(int *pfd);
void	print_err(char *message, char *word);
void	show_err(char *argv);
int		strings_count(char **str);

#endif