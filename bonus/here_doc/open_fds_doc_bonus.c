/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:09:05 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 10:28:59 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

t_fd	open_fds_doc(int argc, char **argv, char **env)
{
	t_fd	doc_fd;

	(void)env;
	doc_fd.outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (doc_fd.outfile < 0)
		doc_fd.check_out = 3;
	doc_fd.check_out = 0;
	return (doc_fd);
}
