/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:05:16 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/07 14:10:11 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	display_tab(int *tab, int n);

void	init_tab(int *tab, int *max, int n);

int		increment(int *tab, int *max, int n);

void	ft_print_combn(int n)
{
	int	tab[9];
	int	max[9];

	init_tab(tab, max, n);
	while (tab[0] != max[0])
	{
		display_tab(tab, n);
		write(1, ", ", 2);
		tab[n - 1]++;
		if (tab[n - 1] > max[n - 1])
		{
			increment(tab, max, n);
		}
	}
	display_tab(tab, n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// display a n digit integer (n <= 9) stored in a table
void	display_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + tab[i]);
		i++;
	}
}

void	init_tab(int *tab, int *max, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		max[i] = 10 - n + i;
		i++;
	}
}

int	increment(int *tab, int *max, int n)
{
	int	j;

	j = n - 1;
	while (tab[j] >= max[j] && j >= 0)
	{
		j--;
	}
	if (j >= 0)
	{
		tab[j]++;
		while (j < n - 1)
		{
			j++;
			tab[j] = tab[j - 1] + 1;
		}
	}
}
