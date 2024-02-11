/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:47 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/11 01:33:33 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

void	check_split(char **cmd)
{
	if (!cmd)
	{
		print_err("malloc failed in ft_split !!", NULL);
		exit(EXIT_FAILURE);
	}
}
