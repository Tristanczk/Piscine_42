/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:57:44 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/22 12:59:28 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_front(t_list **begin_list, void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*node;
	t_list	*ptr;

	if (!begin_list || !cmp)
		return ;
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if ((*cmp)((*begin_list)->data, data) > 0)
	{
		list_push_front(begin_list, data);
		return ;
	}
	ptr = *begin_list;
	node = ft_create_elem(data);
	while (ptr->next && (*cmp)(ptr->next->data, node->data) < 0)
		ptr = ptr->next;
	node->next = ptr->next;
	ptr->next = node;
}

void	list_push_front(t_list **begin_list, void *data)
{
	t_list	*node;

	if (!begin_list)
		return ;
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
