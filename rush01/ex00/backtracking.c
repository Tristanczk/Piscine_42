/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:35:04 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:02:40 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

/* backtracking function checking all possibilities. For each value we check
if it is possible based on values already present in rows and columns.
When we finish a line, we check if it respects the constraints of the line.
Then when we complete the table, we check the constraints for the whole
table. If good we print the condition and indicate we found it */
void	ft_backtracking(int *result, int position, int *input, int *found)
{
	int	value;

	if (*found == 1)
		return ;
	if (position == SIZE * SIZE)
	{
		if (is_valid_array(result, input) == 1)
		{
			printtab(result);
			*found = 1;
		}
		return ;
	}
	else if (position % SIZE == 0 && position > 0
		&& (check_row_left(result, (position / SIZE) - 1, input) == 0
			|| check_row_right(result, (position / SIZE) - 1, input) == 0))
		return ;
	value = 1;
	while (value < SIZE + 1)
	{
		result[position] = value;
		if (is_valid_value(result, value, position) == 1)
			ft_backtracking(result, position + 1, input, found);
		value++;
	}
}
