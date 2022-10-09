/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:55:08 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:48:33 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	is_error(char *base, int len);

int	ft_strlen(char *str);

int	get_memory(long n, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ret;
	int		len_output;
	long	n_to_display;

	if (is_error(base_from, ft_strlen(base_from)) == 1
		|| is_error(base_to, ft_strlen(base_to)) == 1)
		return (NULL);
	n_to_display = (long) ft_atoi_base(nbr, base_from);
	len_output = get_memory(n_to_display, base_to);
	ret = malloc(len_output * sizeof(char));
	ret[0] = base_to[0];
	if (n_to_display < 0)
	{
		ret[0] = '-';
		n_to_display = -n_to_display;
	}
	ret[len_output - 1] = '\0';
	while (n_to_display > 0)
	{
		ret[len_output - 2] = base_to[n_to_display % ft_strlen(base_to)];
		n_to_display /= ft_strlen(base_to);
		len_output--;
	}
	return (ret);
}

int	get_memory(long n, char *base_to)
{
	int	length;
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	length = ft_strlen(base_to);
	while (n > length - 1)
	{
		n /= length;
		i++;
	}
	return (i + 1);
}
