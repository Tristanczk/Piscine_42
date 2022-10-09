/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:53:24 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 18:01:36 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

int		is_in_charset(char c, char *charset);

int		count_strings(char *str, char *charset);

char	*store_word(char *str, char	*to_find);

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		str_nb;
	int		i;

	i = 0;
	str_nb = count_strings(str, charset);
	strs = malloc((str_nb + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (i < str_nb)
	{
		while (is_in_charset(*str, charset) == 1 && *str != '\0')
			str++;
		if (*str != '\0')
			strs[i] = store_word(str, charset);
		while (is_in_charset(*str, charset) == 0 && *str != '\0')
			str++;
		i++;
	}
	strs[i] = 0;
	return (strs);
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

// return the position of the next occurence of to_find in str
int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (is_in_charset(str[i], charset) == 1 && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			count++;
			i++;
		}
		while (is_in_charset(str[i], charset) == 0 && str[i] != '\0')
			i++;
	}
	return (count);
}

char	*store_word(char *str, char	*charset)
{
	int		end;
	int		start;
	char	*word;

	end = 0;
	start = 0;
	while (str[end] != '\0' && is_in_charset(str[end], charset) == 0)
		end++;
	word = malloc((end + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[start] = str[start];
		start++;
	}
	word[start] = '\0';
	return (word);
}
