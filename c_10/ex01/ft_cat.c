/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:22:42 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 11:07:13 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	main(int argc, char **av)
{
	int	fd;
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_display_file(0);
		return (0);
	}
	while (i < argc)
	{
		if ((ft_strlen(av[i]) == 1 && av[i][0] == '-') || (ft_strlen(av[i])
				== 2 && av[i][0] == '-' && av[i][1] == '-' && i == 1))
			ft_display_file(0);
		else
		{
			fd = open(av[i], O_RDONLY);
			if (fd < 0)
				ft_handle_error(av[i], av[0]);
			else
				ft_display_file(fd);
		}
		i++;
	}
	return (0);
}
