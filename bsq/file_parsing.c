/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:35:22 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/27 07:56:02 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_return_file(char *pathname)
{
	char	**table;
	char	*buf;
	int		len_file;
	int		fd;

	len_file = ft_get_len_file(pathname);
	fd = open(pathname, O_RDONLY);
	if (fd < 0 || len_file < 4)
	{
		write(2, "map error\n", 10);
		if (fd > 0)
			close(fd);
		return (0);
	}
	buf = ft_manage_file_errors(fd, len_file);
	if (!buf || ft_c_buffer(buf) == 0)
	{
		close(fd);
		free(buf);
		return (0);
	}
	table = ft_split(buf, "\n");
	free(buf);
	return (table);
}

int	ft_c_buffer(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			write(2, "map error\n", 10);
			return (0);
		}
		i++;
	}
	if (buf[i - 1] != '\n')
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

int	ft_get_len_file(char *pathname)
{
	char	buf[BUFFER_SIZE];
	int		len;
	int		fd;
	int		read_bytes;

	read_bytes = 1;
	len = 0;
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		len += read_bytes;
	}
	close(fd);
	return (len);
}

char	*ft_manage_file_errors(int fd, int len_file)
{
	char	*buf;
	char	buf_check[1];
	int		length;

	buf = malloc((len_file + 1) * sizeof(char));
	buf[len_file] = '\0';
	if (!buf)
		return (NULL);
	length = read(fd, buf, len_file);
	if (length != len_file)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	if (read(fd, buf_check, 1) == -1)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	close(fd);
	return (buf);
}

char	*ft_return_path(char *argv_i)
{
	int		i;
	int		len_argv;
	char	*pathname;

	i = 0;
	len_argv = ft_strlen(argv_i);
	pathname = malloc((len_argv + 1) * sizeof(char));
	while (argv_i[i] != '\0')
	{
		pathname[i] = argv_i[i];
		i++;
	}
	pathname[i] = '\0';
	return (pathname);
}
