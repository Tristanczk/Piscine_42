/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:10:11 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:49 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_dict	*ft_create_elem(long key, char *value)
{
	t_dict	*node;

	node = malloc(sizeof(t_dict *));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_sorted_dict_insert(t_dict **begin_dict, long key, char *value)
{
	t_dict	*node;
	t_dict	*ptr;

	if (!begin_dict)
		return ;
	if (!*begin_dict)
	{
		*begin_dict = ft_create_elem(key, value);
		return ;
	}
	if ((*begin_dict)->key > key)
	{
		ft_dict_push_front(begin_dict, key, value);
		return ;
	}
	ptr = *begin_dict;
	node = ft_create_elem(key, value);
	while (ptr->next && (ptr->next->key < node->key))
		ptr = ptr->next;
	node->next = ptr->next;
	ptr->next = node;
}

void	ft_dict_push_front(t_dict **begin_dict, long key, char *value)
{
	t_dict	*node;

	if (!begin_dict)
		return ;
	node = ft_create_elem(key, value);
	if (node)
	{
		if (*begin_dict)
		{
			node->next = *begin_dict;
		}
		*begin_dict = node;
	}
}

void	ft_dict_push_back(t_dict **begin_dict, long key, char *value)
{
	t_dict	*node;
	t_dict	*ptr;

	if (!begin_dict)
		return ;
	ptr = *begin_dict;
	node = ft_create_elem(key, value);
	if (node)
	{
		if (*begin_dict)
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = node;
		}
		else
			*begin_dict = node;
	}
}

void	ft_print_number(t_dict *number)
{
	while (number)
	{
		ft_putstr(number->value);
		if (number->next)
			ft_putstr(" ");
		else
			ft_putstr("\n");
		number = number->next;
	}
}
