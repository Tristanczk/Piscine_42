/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:05:33 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:51 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*get_value_for_key(long key, t_dict *begin_dict)
{
	while (begin_dict)
	{
		if (begin_dict->key == key)
			return (begin_dict->value);
		begin_dict = begin_dict->next;
	}
	return (NULL);
}

int	check_dict(t_dict *begin_dict)
{
	while (begin_dict)
	{
		if (!begin_dict->value)
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
		begin_dict = begin_dict->next;
	}
	return (1);
}

void	ft_dict_value_clear(t_dict *begin_dict)
{
	if (!begin_dict)
		return ;
	ft_dict_value_clear(begin_dict->next);
	free(begin_dict->value);
	free(begin_dict);
}

void	ft_dict_clear(t_dict *begin_dict)
{
	if (!begin_dict)
		return ;
	ft_dict_clear(begin_dict->next);
	free(begin_dict);
}
