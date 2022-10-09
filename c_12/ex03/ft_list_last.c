/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:59:46 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 15:12:56 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;

	ptr = begin_list;
	if (!ptr)
		return (ptr);
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
