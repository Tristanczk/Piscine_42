/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:37:58 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:38:01 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

long	ft_atoi(char *str)
{
	long	result;
	int		len;

	result = 0;
	while (is_space(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		len++;
	}
	if (result > 4294967295 || len > 10)
		return (-1);
	return (result);
}

void	parse_triplet(long n, t_dict **number, t_dict *dict)
{
	int	nb;

	nb = n / 100;
	if (nb != 0)
	{
		ft_dict_push_back(number, nb, get_value_for_key(nb, dict));
		ft_dict_push_back(number, 100, get_value_for_key(100, dict));
	}	
	n = n - nb * 100;
	if (n > 0 && n < 20)
		ft_dict_push_back(number, n, get_value_for_key(n, dict));
	else if (n >= 20)
	{
		nb = n / 10 * 10;
		ft_dict_push_back(number, nb, get_value_for_key(nb, dict));
		n = n - nb;
		if (n != 0)
			ft_dict_push_back(number, n, get_value_for_key(n, dict));
	}
}

void	parse_number(long n, t_dict **number, t_dict *dict)
{
	int	divider;
	int	nb;

	divider = 1000000000;
	if (n == 0)
		ft_dict_push_back(number, n, get_value_for_key(n, dict));
	else
	{
		while (divider > 0)
		{
			nb = n / divider;
			if (nb != 0)
			{
				parse_triplet(nb, number, dict);
				if (divider > 1)
					ft_dict_push_back(number, divider,
						get_value_for_key(divider, dict));
				n -= nb * divider;
			}
			divider /= 1000;
		}
	}
}

long	check_number_input(char *str)
{
	long	result;
	int		len;

	result = 0;
	if (*str < '0' || *str > '9')
	{
		return (-1);
	}
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		len++;
	}
	if (result > 4294967295 || len > 10)
		return (-1);
	if (*str != '\0')
		return (-1);
	return (result);
}
