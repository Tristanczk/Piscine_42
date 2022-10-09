/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:02:44 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:02:37 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*functions to check each row from left and from right
and each column top bottom and bottom up*/
int	check_row_left(int *result, int row, int *input)
{
	int	input_val;
	int	i;
	int	visible;
	int	max_size;

	input_val = input[2 * SIZE + row];
	i = row * SIZE;
	visible = 0;
	max_size = 0;
	while (i < ((row + 1) * SIZE))
	{
		if (result[i] > max_size)
		{
			max_size = result[i];
			visible++;
		}
		i++;
	}
	if (visible == input_val)
		return (1);
	else
		return (0);
}

int	check_row_right(int *result, int row, int *input)
{
	int	input_val;
	int	i;
	int	visible;
	int	max_size;

	input_val = input[3 * SIZE + row];
	i = (row + 1) * SIZE - 1;
	visible = 0;
	max_size = 0;
	while (i >= row * SIZE)
	{
		if (result[i] > max_size)
		{
			max_size = result[i];
			visible++;
		}
		i--;
	}
	if (visible == input_val)
		return (1);
	else
		return (0);
}

int	check_column_up(int *result, int column, int *input)
{
	int	input_val;
	int	i;
	int	visible;
	int	max_size;

	input_val = input[column];
	i = column;
	visible = 0;
	max_size = 0;
	while (i <= column + (SIZE - 1) * SIZE)
	{
		if (result[i] > max_size)
		{
			max_size = result[i];
			visible++;
		}
		i += SIZE;
	}
	if (visible == input_val)
		return (1);
	else
		return (0);
}

int	check_column_down(int *result, int column, int *input)
{
	int	input_val;
	int	i;
	int	visible;
	int	max_size;

	input_val = input[column + SIZE];
	i = column + (SIZE - 1) * SIZE;
	visible = 0;
	max_size = 0;
	while (i >= column)
	{
		if (result[i] > max_size)
		{
			max_size = result[i];
			visible++;
		}
		i -= SIZE;
	}
	if (visible == input_val)
		return (1);
	else
		return (0);
}

int	is_valid_array(int *result, int *input)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (check_row_left(result, i, input) == 0
			|| check_row_right(result, i, input) == 0
			|| check_column_up(result, i, input) == 0
			|| check_column_down(result, i, input) == 0)
			return (0);
		i++;
	}
	return (1);
}
