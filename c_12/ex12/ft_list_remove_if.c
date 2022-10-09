/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:42:19 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/22 14:07:12 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!begin_list)
		return ;
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(tmp->data);
		free(tmp);
	}
	ptr = *begin_list;
	while (ptr && ptr->next)
	{
		while (ptr->next && (*cmp)(ptr->next->data, data_ref) == 0)
		{
			tmp = ptr->next;
			ptr->next = ptr->next->next;
			(*free_fct)(tmp->data);
			free(tmp);
		}
		if (ptr->next)
			ptr = ptr->next;
	}
}
