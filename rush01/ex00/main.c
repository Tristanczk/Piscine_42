/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:39:13 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 16:30:50 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	*inputs;
	int	*results;
	int	found;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check_args(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (2);
	}
	inputs = init_inputs_tabs(argv[1]);
	results = init_result_tabs();
	found = 0;
	ft_backtracking(results, 0, inputs, &found);
	if (found == 0)
		write(1, "Error\n", 6);
	free(inputs);
	free(results);
	return (0);
}
