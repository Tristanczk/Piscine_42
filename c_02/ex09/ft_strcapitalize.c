/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:15:11 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/10 14:32:08 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha_num(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (new_word == 1 && ft_is_alpha_num(str[i]) == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
			new_word = 0;
		}
		else if (new_word == 0 && str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] -= 'A' - 'a';
		}
		else if (new_word == 0 && ft_is_alpha_num(str[i]) == 0)
		{
			new_word = 1;
		}
		i++;
	}
	return (str);
}

int	ft_is_alpha_num(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
