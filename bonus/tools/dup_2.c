/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:08:11 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/12 09:34:14 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	dup_2(int old, int new)
{
	if (dup2(old, new) < 0)
		return (-1);
	close(old);
	return (0);
}
