/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:51:50 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/27 07:47:38 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_handle(char *argv_i)
{
	char	**table;
	char	*pathname;
	t_map	map;

	pathname = ft_return_path(argv_i);
	table = ft_return_file(pathname);
	if (!table)
	{
		free(pathname);
		return (-1);
	}
	map = ft_check_matrix(table);
	if (map.height == -1)
	{
		write(2, "map error\n", 10);
		free(pathname);
		ft_free_double(table);
		return (-1);
	}
	solve_matrix(table, map);
	ft_free_double(table);
	free(pathname);
	return (1);
}
