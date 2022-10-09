/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:51:43 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/07 11:18:25 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		nb_len(int n);

void	display_int(int nb, int is_neg, int nb_len);

// manage edge case then display int
void	ft_putnbr(int nb)
{
	int	digits;
	int	is_neg;

	digits = nb_len(nb);
	is_neg = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	display_int(nb, is_neg, digits);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// return the number of digits in an int
int	nb_len(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
	{
		return (10);
	}
	if (n < 0)
	{
		n = -n;
	}
	n /= 10;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

//display an int inputted as an array of char, an int is maximum 10 digits
void	display_int(int nb, int is_neg, int nb_len)
{
	int		i;
	int		j;
	int		num[10];

	i = nb_len;
	j = 0;
	while (nb != 0)
	{
		num[i - 1] = nb % 10;
		nb /= 10;
		i--;
	}
	if (is_neg == 1)
	{
		ft_putchar('-');
	}
	while (j < nb_len)
	{
		ft_putchar(num[j] + '0');
		j++;
	}
}
