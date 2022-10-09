/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:24:22 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/10 17:20:43 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int length, char first, char middle, char last);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	print_line(x, 'A', 'B', 'A');
	i++;
	while (i < y - 1)
	{
		print_line(x, 'B', ' ', 'B');
		i++;
	}
	if (i < y)
	{
		print_line(x, 'C', 'B', 'C');
	}
}

void	print_line(int length, char first, char middle, char last)
{
	int	i;

	i = 0;
	ft_putchar(first);
	i++;
	while (i < length - 1)
	{
		ft_putchar(middle);
		i++;
	}
	if (i < length)
	{
		ft_putchar(last);
	}
	ft_putchar('\n');
}
