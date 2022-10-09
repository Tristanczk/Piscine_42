/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:24:08 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:55 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_strjoin(char **strs)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(calculate_total_memory(strs) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	while (strs[i])
	{
		ft_strcat(ret, strs[i]);
		if (strs[i + 1])
			ft_strcat(ret, " ");
		i++;
	}
	return (ret);
}

int	calculate_total_memory(char **strs)
{
	int	mem;
	int	i;

	i = 0;
	mem = 0;
	while (strs[i])
	{
		mem += ft_strlen(strs[i]) + 1;
		i++;
	}
	return (mem);
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
