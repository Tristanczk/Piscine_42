/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:51:19 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/19 13:14:46 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascend;
	int	descend;

	ascend = 1;
	descend = 1;
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0 && descend == 1)
			descend = 0;
		else if (f(tab[i - 1], tab[i]) > 0 && ascend == 1)
			ascend = 0;
		i++;
	}
	if (ascend == 0 && descend == 0)
		return (0);
	else
		return (1);
}
