/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:17:12 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
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

#endif