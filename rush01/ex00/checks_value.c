/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:57:51 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:02:35 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//check if a value is possible based on the values already in place
int	check_value_left(int *result, int value, int position)
{
	int	row_nb;
	int	i;

	row_nb = position / SIZE;
	i = row_nb * SIZE;
	while (i < position)
	{
		if (result[i] == value)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_value_up(int *result, int value, int position)
{
	int	column_nb;
	int	i;

	column_nb = position % SIZE;
	i = column_nb;
	while (i < position)
	{
		if (result[i] == value)
		{
			return (0);
		}
		i += SIZE;
	}
	return (1);
}

int	is_valid_value(int *result, int value, int position)
{
	if (check_value_left(result, value, position) == 1
		&& check_value_up(result, value, position) == 1)
		return (1);
	return (0);
}
