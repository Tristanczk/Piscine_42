/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:03:36 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 15:55:51 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_cpy_n(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	is_std_input(char *str)
{
	if (ft_strlen(str) == 2 && str[0] == '-' && str[1] == '-')
		return (1);
	else
		return (0);
}

int	is_c_flag(char *str)
{
	if (ft_strlen(str) == 2 && str[0] == '-' && str[1] == 'C')
		return (1);
	else
		return (0);
}
