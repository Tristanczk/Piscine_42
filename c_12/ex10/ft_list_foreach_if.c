/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:46:28 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 12:32:51 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
	t_list	*ptr;

	if (!f || !cmp)
		return ;
	ptr = begin_list;
	while (ptr)
	{
		if ((*cmp)(ptr->data, data_ref) == 0)
			(*f)(ptr->data);
		ptr = ptr->next;
	}
}
