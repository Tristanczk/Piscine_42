/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:27:49 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 15:22:50 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_lines(char *str, int length, t_file_pars parsing)
{
	int	i;

	i = 0;
	if (parsing.same == 1)
		ft_putstr("*\n");
	else if (parsing.same > 1)
		return ;
	else
	{
		if (parsing.flag > 0)
		{
			while (i++ < parsing.flag)
			{
				print_to_hex(parsing.mem, 8, parsing.flag);
				print_hex_flag(str, length);
				print_final_text(str, length);
			}
		}
		else
		{
			print_to_hex(parsing.mem, 7, parsing.flag);
			print_hex_no_flag(str, length);
		}
	}
}

//convert a number to hexadecimal format (add leading 0 to reach size)
void	print_to_hex(unsigned long long n, unsigned int size, int flag)
{
	unsigned int	i;
	unsigned int	hex[8];
	char			*hex_tab;

	i = 0;
	hex_tab = "0123456789abcdef";
	while (i < 8)
	{
		hex[8 - i - 1] = n % MAX_CHAR;
		n /= MAX_CHAR;
		i++;
	}
	i = -1;
	while (++i < size)
		write(1, &hex_tab[hex[8 - size + i]], 1);
	if (size >= 7)
	{
		if (flag == 0)
			ft_putchar(' ');
		else if (flag > 0)
			ft_putstr("  ");
		else
			ft_putchar('\n');
	}
}

void	print_hex_flag(char	*str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		print_to_hex((unsigned long long) str[i], 2, 0);
		ft_putchar(' ');
		if (i == 7 || i == 15)
			ft_putchar(' ');
		i++;
	}
	while (i < MAX_CHAR)
	{
		ft_putstr("   ");
		if (i == 7 || i == 15)
			ft_putchar(' ');
		i++;
	}
}

void	print_hex_no_flag(char	*str, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (i + 1 < length)
		{
			print_to_hex((unsigned long long) str[i + 1], 2, 0);
			print_to_hex((unsigned long long) str[i], 2, 0);
			if (i + 2 >= length)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			i += 2;
		}
		else
		{
			print_to_hex((unsigned long long) 0, 2, 0);
			print_to_hex((unsigned long long) str[i], 2, 0);
			ft_putchar('\n');
			i++;
		}
	}
}

void	print_final_text(char *str, int length)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i < length)
	{
		print_char_point(str[i]);
		i++;
	}
	ft_putstr("|\n");
}
