/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:17:17 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/18 09:43:09 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

int		ft_strlen(char *str);

char	*store_word(char *str);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	if (ac < 1)
		ac = 0;
	ret = malloc((ac + 1) * sizeof(t_stock_str));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = store_word(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
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

char	*store_word(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(str);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
