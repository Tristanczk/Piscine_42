/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:00 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/14 15:46:57 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		calculate_total_memory(int size, char **strs, char *sep);

int		ft_strlen(char *str);

char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(calculate_total_memory(size, strs, sep) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i < size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}

int	calculate_total_memory(int size, char **strs, char *sep)
{
	int	mem;
	int	i;

	if (size == 0)
	{
		return (1);
	}
	i = 0;
	mem = 0;
	while (i < size - 1)
	{
		mem += ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	mem += ft_strlen(strs[size - 1]) + 1;
	return (mem);
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
