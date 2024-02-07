/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:03:04 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 17:57:34 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	**get_env_paths(char **env)
{
	char	**res;

	while (*env && !ft_strnstr(*env, "PATH", 5))
		env++;
	if (!*env)
		return (NULL);
	res = ft_split(*env, ':');
	*res = ft_strchr(*res, '/');
	return (res);
}
