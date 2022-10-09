/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:57:58 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/25 19:03:53 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_free_double(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_double_int(int **tab, t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_c_is_printable(char c)
{
	int	status;

	status = 1;
	if (!(c >= 32 && c <= 126))
		status = 0;
	return (status);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
