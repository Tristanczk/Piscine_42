/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:30:19 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/11 17:27:57 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);

int		is_error(char *base, int len);

void	ft_putchar(char c);

void	write_number_base(long n, char *base, int len);

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	long	n;

	n = nbr;
	len_base = ft_strlen(base);
	if (is_error(base, len_base) == 1)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	write_number_base(n, base, len_base);
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

// return 1 if there is an error in base, else return 0
int	is_error(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len <= 1)
		return (1);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_number_base(long n, char *base, int len)
{
	if (n > len - 1)
	{
		write_number_base(n / len, base, len);
		write_number_base(n % len, base, len);
	}
	else
	{
		ft_putchar(base[n]);
	}
}
