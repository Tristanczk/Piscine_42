/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:27:03 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/11 09:11:20 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	get_first_occ(char *str, char *to_find, int len);

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	first_occ;

	len = ft_strlen(to_find);
	if (len == 0)
	{
		return (str);
	}
	first_occ = get_first_occ(str, to_find, len);
	if (first_occ == -1)
	{
		return (0);
	}
	else
	{
		return (str + first_occ);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	get_first_occ(char *str, char *to_find, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		if (j == len)
		{
			return (i - len + 1);
		}
		i++;
	}
	return (-1);
}
