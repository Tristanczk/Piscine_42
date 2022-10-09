/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:06 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/07 08:57:06 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_three_digits(int n1, int n2, int n3);

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 0;
	n2 = 1;
	n3 = 2;
	while (n1 < 8)
	{
		while (n2 < 9)
		{
			while (n3 < 10)
			{
				print_three_digits(n1, n2, n3);
				n3++;
			}
			n2++;
			n3 = n2 + 1;
		}
		n1++;
		n2 = n1 + 1;
		n3 = n1 + 2;
	}
}

// convert 3 digits to corresponding ASCII table and write to screen 
// additionnally write ", " if n1 is not 7, ie if number is not 789
void	print_three_digits(int n1, int n2, int n3)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = n1 + 48;
	c2 = n2 + 48;
	c3 = n3 + 48;
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (n1 != 7)
	{
		write(1, ", ", 2);
	}
}
