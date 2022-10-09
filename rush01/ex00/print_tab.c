/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:26:07 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:03:18 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//print the result table
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printtab(int *tab)
{
	int	i;

	i = 0;
	while (i < SIZE * SIZE)
	{
		ft_putchar(tab[i] + 48);
		if ((i + 1) % SIZE == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
