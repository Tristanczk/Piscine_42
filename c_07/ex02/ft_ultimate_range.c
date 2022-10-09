/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:27:34 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/16 09:57:35 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	i;
	long	res;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(((long)max - (long)min) * sizeof(int));
	if (!*range)
	{
		return (-1);
	}
	res = (long)max - (long)min;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (res);
}
