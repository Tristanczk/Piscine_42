/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:17:42 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/26 16:28:31 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**complete_matrix(char **lines, t_point coord, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < coord.length)
	{
		j = 0;
		while (j < coord.length)
		{
			lines[coord.x + i + 1][coord.y + j] = map.solid;
			j++;
		}
		i++;
	}
	return (lines);
}

void	print_matrix(char **lines, t_map map)
{
	int	i;

	i = 1;
	while (i <= map.height)
	{
		write(1, lines[i], map.length);
		ft_putchar('\n');
		i++;
	}
}
