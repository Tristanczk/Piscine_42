/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:24:55 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/06 19:41:37 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_two_numbers(int n1, int n2);

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 1;
	while (n1 < 99)
	{
		while (n2 < 100)
		{
			print_two_numbers(n1, n2);
			n2++;
		}
		n1++;
		n2 = n1 + 1;
	}
}

// convert 2 numbers to characters and write to screen with a space between
// additionnally write ", " if n1 is different than 98 (last combination)
void	print_two_numbers(int n1, int n2)
{
	char	units1;
	char	tens1;
	char	units2;
	char	tens2;

	units1 = n1 % 10 + 48;
	tens1 = n1 / 10 + 48;
	units2 = n2 % 10 + 48;
	tens2 = n2 / 10 + 48;
	write(1, &tens1, 1);
	write(1, &units1, 1);
	write(1, " ", 1);
	write(1, &tens2, 1);
	write(1, &units2, 1);
	if (n1 != 98)
	{
		write(1, ", ", 2);
	}
}
