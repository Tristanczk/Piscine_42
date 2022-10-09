/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:41:17 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/13 11:03:32 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid_position(char pos, char *tab, int column);

void	print_solution(char *tab);

void	ft_backtracking(char *tab, int column, int *max);

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		max_comb;

	max_comb = 0;
	ft_backtracking(board, 0, &max_comb);
	return (max_comb);
}

// check if given position for given column is valid
int	is_valid_position(char pos, char *tab, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (pos == tab[i])
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < column)
	{
		if (pos == tab[i] + (column - i) || pos == tab[i] - (column - i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	print_solution(char *tab)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		write(1, &tab[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_backtracking(char *tab, int column, int *max)
{
	char	c;

	c = '0';
	if (column == 10)
	{
		print_solution(tab);
		*max = *max + 1;
		return ;
	}
	while (c <= '9')
	{
		tab[column] = c;
		if (is_valid_position(c, tab, column) == 1)
		{
			ft_backtracking(tab, column + 1, max);
		}
		c++;
	}
}
