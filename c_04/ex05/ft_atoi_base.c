/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:19:51 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/11 17:25:43 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_error(char *base, int len);

int	ft_strlen(char *str);

int	ft_isspace(char c);

int	value_in_base(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	len_base;
	int	sign;
	int	result;
	int	i;

	len_base = ft_strlen(base);
	result = 0;
	sign = 1;
	i = 0;
	if (is_error(base, len_base) == 1)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (value_in_base(str[i], base) != -1)
	{
		result = result * len_base + value_in_base(str[i], base);
		i++;
	}
	return (result * sign);
}

// check base string for error
int	is_error(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len <= 1)
		return (1);
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]) == 1)
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// return length of string
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

// check if character is whitespace
int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// return the value of the character in the given base
int	value_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
