/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:08:48 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 12:25:05 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*ptr;

	if (!begin_list)
		return ;
	ptr = *begin_list;
	node = ft_create_elem(data);
	if (node)
	{
		if (*begin_list)
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = node;
		}
		else
			*begin_list = node;
	}
}
