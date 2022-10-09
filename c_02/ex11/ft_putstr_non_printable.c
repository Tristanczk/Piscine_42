/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:12:00 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/10 17:51:37 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_printable(char c);

void	print_char_to_hex(char n);

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_printable(str[i]) == 1)
		{
			write(1, &str[i], 1);
		}
		else
		{
			print_char_to_hex(str[i]);
		}
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	print_char_to_hex(char n)
{
	char				*hex_char;
	unsigned char		c;

	hex_char = "0123456789abcdef";
	c = (unsigned char) n;
	ft_putchar('\\');
	ft_putchar(hex_char[c / 16]);
	ft_putchar(hex_char[c % 16]);
}
