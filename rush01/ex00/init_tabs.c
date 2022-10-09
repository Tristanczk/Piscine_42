/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:22:18 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:03:09 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
//initialize the input table
int	*init_inputs_tabs(char *str)
{
	int	*inputs;
	int	i;

	i = 0;
	inputs = malloc(SIZE * SIZE * sizeof(*inputs));
	if (!inputs)
		return (NULL);
	while (i < SIZE * SIZE)
	{
		inputs[i] = str[i * 2] - '0';
		i++;
	}
	return (inputs);
}

//initialize the result table
int	*init_result_tabs(void)
{
	int	*results;
	int	i;

	i = 0;
	results = malloc(SIZE * SIZE * sizeof(*results));
	if (!results)
		return (NULL);
	while (i < SIZE * SIZE)
	{
		results[i] = 0;
		i++;
	}
	return (results);
}
