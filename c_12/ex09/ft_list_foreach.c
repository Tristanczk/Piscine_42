/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:32:10 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 12:27:15 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*ptr;

	if (!f)
		return ;
	ptr = begin_list;
	while (ptr)
	{
		(*f)(ptr->data);
		ptr = ptr->next;
	}
}
