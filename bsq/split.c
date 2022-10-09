/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlesage <nlesage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:33:17 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/25 20:16:01 by nlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_word;
	int		i;

	i = 0;
	nb_word = ft_count_nb_word(str, charset, 0);
	if (str[0] == '\0' || nb_word == 0)
	{
		tab = malloc(1 * sizeof(*tab));
		tab[0] = 0;
		return (tab);
	}
	tab = malloc((nb_word + 1) * sizeof(*tab));
	while (str[i] != '\0' && ft_is_in_charset(str[i], charset) == 1)
		i++;
	tab = ft_complete_table(str, charset, tab, i);
	return (tab);
}

char	**ft_complete_table(char *str, char *charset, char **tab, int i)
{
	int	curr_word;
	int	j;
	int	nb_char;

	curr_word = 0;
	while (str[i] != '\0')
	{
		if (ft_is_in_charset(str[i], charset) == 0)
		{
			nb_char = ft_nb_char_in_word(str, charset, i);
			tab[curr_word] = malloc((nb_char + 1) * sizeof(char));
			j = -1;
			while (++j < nb_char)
				tab[curr_word][j] = str[i + j];
			tab[curr_word][j] = '\0';
			curr_word++;
			i = i + nb_char;
		}
		while (str[i] != '\0' && ft_is_in_charset(str[i], charset) == 1)
			i++;
	}
	tab[curr_word] = 0;
	return (tab);
}

int	ft_nb_char_in_word(char *str, char *charset, int i)
{
	int	nb_char;

	nb_char = 0;
	while (str[i] != '\0' && ft_is_in_charset(str[i], charset) != 1)
	{
		nb_char++;
		i++;
	}
	return (nb_char);
}

int	ft_count_nb_word(char *str, char *charset, int nb_mot)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0' && ft_is_in_charset(str[i], charset) == 1)
		i++;
	while (str[i] != '\0')
	{
		if (ft_is_in_charset(str[i], charset) == 1)
		{
			nb_mot++;
			while (str[i] != '\0' && ft_is_in_charset(str[i], charset) == 1)
				i++;
			i--;
		}
		i++;
	}
	if (ft_is_in_charset(str[i - 1], charset) == 0)
		nb_mot++;
	return (nb_mot);
}

int	ft_is_in_charset(char character, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (character == charset[i])
			return (1);
		i++;
	}
	return (0);
}
