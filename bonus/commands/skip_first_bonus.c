/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:58:11 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/14 14:24:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	skip_first(t_fd *fd, int *i, int *cmds)
{
	fd->i_place = *i;
	if (fd->check_in)
	{
		(*i)++;
		if (cmds)
			(*cmds)--;
	}
}
