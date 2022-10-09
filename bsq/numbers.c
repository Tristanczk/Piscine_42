/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:43:56 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/27 11:02:23 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (nb == 0 || nb > 2147483647)
		nb = -1;
	return (nb);
}

int	ft_nb_digits(int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb <= 9)
		return (1);
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	i++;
	return (i);
}

int	min_3_val(int val1, int val2, int val3)
{
	if (val1 <= val2 && val1 <= val3)
		return (val1);
	else if (val2 <= val3 && val2 < val1)
		return (val2);
	else
		return (val3);
}
