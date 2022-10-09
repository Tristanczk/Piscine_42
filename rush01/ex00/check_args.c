/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:29:17 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:02:38 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//function checks if argument in main respects constraints
int	check_args(char *str)
{
	int	i;

	i = 0;
	while (i < 4 * SIZE)
	{
		if ((str[i * 2] >= '1' || str[i * 2] <= '0' + SIZE)
			&& (str[i * 2 + 1] == ' ' || str[i * 2 + 1] == '\0'))
		{
			i++;
		}
		else
		{		
			return (0);
		}
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
