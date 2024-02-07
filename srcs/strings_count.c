/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:02:34 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:08:17 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
