/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:28:23 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/22 11:21:04 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_merge(t_list **begin_list1, t_list *begin_list2);
int		list_size(t_list *begin_list);
void	list_sort(t_list **begin_list, int (*cmp)());

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	if (!begin_list1)
		return ;
	list_merge(begin_list1, begin_list2);
	list_sort(begin_list1, cmp);
}

void	list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*ptr;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	ptr = *begin_list1;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = begin_list2;
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		size;
	t_list	*ptr;
	void	*tmp;

	if (!begin_list)
		return ;
	i = 0;
	size = list_size(*begin_list);
	while (i < size)
	{
		ptr = *begin_list;
		while (ptr && ptr->next)
		{
			if ((*cmp)(ptr->data, ptr->next->data) > 0)
			{
				tmp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tmp;
			}
			ptr = ptr->next;
		}
		i++;
	}
}

int	list_size(t_list *begin_list)
{
	int		count;
	t_list	*ptr;

	count = 0;
	ptr = begin_list;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
