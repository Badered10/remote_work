/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:24:48 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/05 11:57:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef LAST_CMD
#  define LAST_CMD 1
# endif

# ifndef INFILE_NOT_FOUND
#  define INFILE_NOT_FOUND 127
# endif

typedef struct s_openfd
{
	int	outfile;
	int	infile;
}				t_fd;

#endif