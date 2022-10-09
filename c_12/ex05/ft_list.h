/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 08:44:06 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/21 08:47:30 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef struct t_list
{
	void			*data;
	struct t_list	*next;
}	t_list;
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);

#endif