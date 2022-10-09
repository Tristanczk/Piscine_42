/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:15:26 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/26 15:30:00 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**dp_matrix(char **lines, t_map map)
{
	int	**matrix;
	int	i;
	int	j;

	i = 1;
	matrix = dp_matrix_first(lines, map);
	while (i < map.height)
	{
		j = 1;
		while (j < map.length)
		{
			if (lines[i + 1][j] == map.empty)
				matrix[i][j] = min_3_val(matrix[i - 1][j - 1],
						matrix[i - 1][j], matrix[i][j - 1]) + 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

int	**dp_matrix_first(char **lines, t_map map)
{
	int	**matrix;
	int	i;

	i = 0;
	matrix = init_matrix(map.height, map.length);
	while (i < map.length)
	{
		if (lines[1][i] == map.empty)
			matrix[0][i] = 1;
		i++;
	}
	i = 0;
	while (i < map.height)
	{
		if (lines[i + 1][0] == map.empty)
			matrix[i][0] = 1;
		i++;
	}
	return (matrix);
}

int	**init_matrix(int height, int length)
{
	int	**matrix;
	int	i;
	int	j;

	i = 0;
	matrix = malloc(height * sizeof(int *));
	if (!matrix)
		return (NULL);
	while (i < height)
	{
		j = 0;
		matrix[i] = malloc(length * sizeof(int));
		if (!matrix[i])
			return (NULL);
		while (j < length)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

int	get_max_coord(t_point *point, int **dp_matrix, int height, int length)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			if (dp_matrix[i][j] > max)
			{
				max = dp_matrix[i][j];
				point->x = i - (max - 1);
				point->y = j - (max - 1);
				point->length = max;
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	solve_matrix(char **lines, t_map map)
{
	int		**matrix;
	t_point	coord;

	matrix = dp_matrix(lines, map);
	if (get_max_coord(&coord, matrix, map.height, map.length) != 0)
		lines = complete_matrix(lines, coord, map);
	print_matrix(lines, map);
	ft_free_double_int(matrix, map);
}
