/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:30:48 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/22 13:00:55 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr)
	{
		if ((*cmp)(ptr->data, data_ref) == 0)
		{
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (ptr);
}
