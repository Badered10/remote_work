/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:08:11 by baouragh          #+#    #+#             */
/*   Updated: 2024/02/07 16:08:15 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	dup_2(int old, int new, int mod)
{
	if (dup2(old, new) < 0)
	{
		if (mod == 0)
			perror("dup2 -> infile ");
		if (mod == 1)
			perror("dup2 -> outfile ");
		if (mod == 2)
			perror("dup2 -> pipe ");
		return (-1);
	}
	close(old);
	return (0);
}
