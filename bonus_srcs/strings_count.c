/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:02:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:54 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	strings_count(char **str)
{
	char	**save;

	if (!str)
		return (-1);
	save = str;
	while (*str)
		str++;
	return (str - save);
}
