/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:19:08 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/20 14:52:43 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_str_swap(char **s1, char **s2);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (tab[size])
		size++;
	while (i < size - 1)
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			ft_str_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	ft_str_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
