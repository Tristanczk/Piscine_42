/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:55:05 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 17:21:20 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list);

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		size;
	t_list	*ptr;
	void	*tmp;

	if (!begin_list)
		return ;
	i = 0;
	size = ft_list_size(*begin_list);
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

int	ft_list_size(t_list *begin_list)
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
