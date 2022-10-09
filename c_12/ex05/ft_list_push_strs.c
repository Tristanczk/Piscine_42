/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 08:44:40 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 10:10:22 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	int		i;

	begin_list = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&begin_list, strs[i]);
		i++;
	}
	return (begin_list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	node = ft_create_elem(data);
	if (node)
	{
		if (*begin_list)
		{
			node->next = *begin_list;
		}
		*begin_list = node;
	}
}
