/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:49 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/16 17:47:29 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	if (min >= max)
	{
		return (NULL);
	}
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
	{
		return (NULL);
	}
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
