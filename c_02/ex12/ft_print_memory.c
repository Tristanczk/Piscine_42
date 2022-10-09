/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:28:25 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/10 18:23:56 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_CHAR 16

void	print_to_hex(unsigned long long n, unsigned int size, int space);

void	print_t_h(unsigned int j, unsigned int i, unsigned int size, char *str);

void	print_char_point(char c);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned long long	mem_addr;
	char				*str;

	i = 0;
	mem_addr = (unsigned long long) addr;
	str = (char *)addr;
	while (i < size)
	{
		j = i;
		print_to_hex(mem_addr + i, MAX_CHAR, 0);
		print_t_h(j, i, size, str);
		while (j < size && j / MAX_CHAR == i / MAX_CHAR)
		{
			print_char_point(str[j]);
			j++;
		}
		write(1, "\n", 1);
		i = j;
	}
	return (addr);
}

//convert a number to hexadecimal format (add leading 0 to reach size)
void	print_to_hex(unsigned long long n, unsigned int size, int space)
{
	unsigned int	i;
	unsigned int	hex[16];
	char			*hex_tab;

	i = 0;
	hex_tab = "0123456789abcdef";
	while (i < MAX_CHAR)
	{
		hex[MAX_CHAR - i - 1] = n % MAX_CHAR;
		n /= MAX_CHAR;
		i++;
	}
	i = 0;
	while (i < size)
	{
		write(1, &hex_tab[hex[MAX_CHAR - size + i]], 1);
		i++;
	}
	if (size == MAX_CHAR)
		write(1, ": ", 2);
	if (space == 1)
		write(1, " ", 1);
}

void	print_t_h(unsigned int j, unsigned int i, unsigned int size, char *str)
{
	while (j < size && j / MAX_CHAR == i / MAX_CHAR)
	{
		print_to_hex((unsigned long long) str[j], 2, j % 2);
		j++;
	}
	while (j % 16 != 0)
	{
		write(1, "  ", 2);
		if (j % 2 == 1)
		{
			write(1, " ", 1);
		}
		j++;
	}
}

// print char if printable, else print "."
void	print_char_point(char c)
{
	if (c < ' ' || c > '~')
	{
		write(1, ".", 1);
	}
	else
	{
		write(1, &c, 1);
	}
}
