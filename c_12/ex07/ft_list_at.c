/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:50:15 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 10:47:30 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*ptr;
	unsigned int	i;

	i = 0;
	ptr = begin_list;
	while (ptr && i < nbr)
	{
		ptr = ptr->next;
		i++;
	}
	return (ptr);
}
