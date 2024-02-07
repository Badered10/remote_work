/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:02:29 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:29 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	free_double(char **ptr)
{
	char	**save;

	save = ptr;
	while (*save)
	{
		free(*save);
		save++;
	}
	free(ptr);
}
