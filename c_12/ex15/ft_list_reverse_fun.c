/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:26:45 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 16:55:41 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list);

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*tmp;
	t_list	*ptr;
	t_list	*rev_ptr;

	i = 0;
	size = ft_list_size(begin_list);
	ptr = begin_list;
	while (i < size / 2)
	{
		rev_ptr = ft_list_at(begin_list, size - i - 1);
		tmp = ptr->data;
		ptr->data = rev_ptr->data;
		rev_ptr->data = tmp;
		i++;
		ptr = ptr->next;
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
