/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:06:48 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/20 14:49:09 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

void	addition(long a, long b)
{
	ft_putnbr(a + b);
}

void	substraction(long a, long b)
{
	ft_putnbr(a - b);
}

void	multiplication(long a, long b)
{
	ft_putnbr(a * b);
}

void	division(long a, long b)
{
	if (b == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	modulo(long a, long b)
{
	if (b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}
