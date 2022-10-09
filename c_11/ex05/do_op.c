/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:02:50 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/20 14:55:19 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	main(int argc, char **argv)
{
	void	(*f[5])(long, long);

	f[0] = addition;
	f[1] = substraction;
	f[2] = multiplication;
	f[3] = division;
	f[4] = modulo;
	if (argc != 4)
		return (1);
	if (is_operator(argv[2][0]) == -1)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (1);
	}
	else
	{
		f[is_operator(argv[2][0])](ft_atoi(argv[1]), ft_atoi(argv[3]));
		ft_putchar('\n');
		return (0);
	}
}

int	is_operator(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (-1);
}
