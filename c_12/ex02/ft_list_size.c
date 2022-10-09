/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:40:24 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/20 18:05:16 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
