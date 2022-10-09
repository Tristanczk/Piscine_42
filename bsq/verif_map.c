/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:46:58 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/26 16:09:32 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	ft_check_matrix(char **table)
{
	t_map	map;
	int		nb;

	map = ft_import_row(table, ft_strlen(table[0]), 0);
	nb = ft_strlen(table[0]);
	if (ft_check_first_row(map, nb) == 0)
		map.height = -1;
	if (ft_check_core(table, map) == 0)
		map.height = -1;
	return (map);
}

t_map	ft_import_row(char **table, int len, int i)
{
	t_map	map;
	char	*nb_a;

	map.height = -1;
	if (len <= 3)
		return (map);
	nb_a = malloc((len - 3 + 1) * sizeof(char));
	nb_a[len - 3] = '\0';
	if (!nb_a)
		return (map);
	while (i < len - 3)
	{
		nb_a[i] = table[0][i];
		i++;
	}
	map.height = ft_atoi(nb_a);
	if (table[1] == 0)
		map.height = -1;
	else
		map.length = ft_strlen(table[1]);
	map.empty = table[0][len - 3];
	map.obstacle = table[0][len - 2];
	map.solid = table[0][len - 1];
	free(nb_a);
	return (map);
}

int	ft_check_core(char **table, t_map map)
{
	int	i;
	int	j;
	int	len_row;

	i = 1;
	while (table[i] != 0)
	{
		j = 0;
		len_row = ft_strlen(table[i]);
		if (len_row != map.length)
			return (0);
		while (j < map.length)
		{
			if (table[i][j] != map.empty && table[i][j] != map.obstacle)
				return (0);
			j++;
		}
		i++;
	}
	if (i - 1 != map.height)
		return (0);
	return (1);
}

int	ft_check_first_row(t_map map, int len)
{
	if (ft_c_is_printable(map.empty) == 0)
		return (0);
	if (ft_c_is_printable(map.obstacle) == 0)
		return (0);
	if (ft_c_is_printable(map.solid) == 0)
		return (0);
	if (map.empty == map.obstacle || map.empty == map.solid)
		return (0);
	if (map.obstacle == map.solid)
		return (0);
	if (ft_nb_digits(map.height) + 3 != len)
		return (0);
	return (1);
}
