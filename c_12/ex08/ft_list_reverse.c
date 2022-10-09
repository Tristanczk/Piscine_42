/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:51:13 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/22 10:35:17 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	if (!begin_list)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*begin_list = prev;
}
