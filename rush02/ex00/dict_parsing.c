/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:33:00 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:52 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/*parses the dict file into a buffer, then split the buffer string by '\n'
characters, returning a list of strings containing each distinct, non-empty
line of the file*/
char	**parse_dict(char *pathname)
{
	int		fd;
	int		len_file;
	char	*buf;
	char	**lines;

	len_file = get_len_file(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd < 0 || len_file == -1)
	{
		write(2, "Dict Error\n", 11);
		close(fd);
		return (0);
	}
	buf = malloc((len_file + 1) * sizeof(char));
	if (manage_file_errors(fd, &buf, len_file) == 0)
		return (0);
	close(fd);
	lines = ft_split(buf, "\n");
	free(buf);
	return (lines);
}

int	manage_file_errors(int fd, char **buf, int len_file)
{
	char	buf_check[1];

	if (read(fd, *buf, len_file) != len_file)
	{
		write(2, "Dict Error\n", 11);
		close(fd);
		return (0);
	}
	if (read(fd, buf_check, 1) == -1)
	{
		write(2, "Dict Error\n", 11);
		close(fd);
		return (0);
	}
	return (1);
}

//get the length (number of characters) of a file
int	get_len_file(char *pathname)
{
	char	buf[1];
	int		len;
	int		fd;

	len = 0;
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, buf, 1) == 1)
		len++;
	close(fd);
	return (len);
}

char	*get_value_dict(char *str)
{	
	char	**strs;
	char	*res;
	int		i;

	while (*str != ':')
		str++;
	str++;
	while (is_space(*str) == 1)
		str++;
	strs = ft_split(str, " \t\n\v\f\r");
	res = ft_strjoin(strs);
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (res);
}

t_dict	*create_dict(char **lines)
{
	t_dict	*begin_dict;
	int		i;
	int		key;
	char	*value;

	begin_dict = NULL;
	i = 0;
	while (lines[i])
	{
		key = ft_atoi(lines[i]);
		value = get_value_dict(lines[i]);
		if (key != -1)
			ft_sorted_dict_insert(&begin_dict, key, value);
		free(lines[i]);
		i++;
	}
	free(lines);
	return (begin_dict);
}
