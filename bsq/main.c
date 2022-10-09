/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:02:57 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/26 10:57:24 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (read_std_input() == 0)
			return (1);
		else
		{
			ft_handle("stdinput.txt");
			return (0);
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_handle(argv[i]);
		if (argc > 2)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
