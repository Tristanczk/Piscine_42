/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:14:02 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/11 16:20:12 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len_dest;
	unsigned int len_src;
	int i = 0;
	int max_append;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	max_append = size - len_dest - 1;
	if (size == 0)
	{
		return (len_dest + len_src);
	}
	if (size < len_dest + 1)
	{
		return (size);
	}
	while (src[i] != '\0' && i < (max_append))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
