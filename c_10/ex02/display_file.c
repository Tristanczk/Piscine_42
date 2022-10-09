/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:16:38 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 14:19:05 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	display_file(int fd, int size_to_print)
{
	char	buf[BUFFER_SIZE];
	char	*file_content;
	int		length;

	file_content = malloc(sizeof(char));
	file_content[0] = '\0';
	length = 1;
	while (length > 0)
	{
		length = read(fd, buf, BUFFER_SIZE);
		if (length > 0)
			file_content = ft_concatenate_buffers(file_content, buf, length);
	}
	length = ft_strlen(file_content);
	if (length <= size_to_print)
		write(1, file_content, length);
	else
		write(1, file_content + length - size_to_print, size_to_print);
	free(file_content);
	if (fd != 0)
		close(fd);
}

char	*ft_concatenate_buffers(char *dest, char *buf, int length)
{
	int		i;
	int		j;
	char	*concat_buf;

	i = 0;
	j = 0;
	concat_buf = malloc((ft_strlen(dest) + length + 1) * sizeof(char));
	if (!concat_buf)
		return (NULL);
	while (dest[i] != '\0')
	{
		concat_buf[i] = dest[i];
		i++;
	}
	while (j < length)
	{
		concat_buf[i] = buf[j];
		i++;
		j++;
	}
	concat_buf[i] = '\0';
	free(dest);
	return (concat_buf);
}

void	display_header(char *filename, int i)
{
	if ((ft_strlen(filename) == 1 && filename[0] == '-')
		|| (ft_strlen(filename) == 2 && filename[0] == '-'
			&& filename[1] == '-' && i == 0))
	{
		if (i > 0)
			write(1, "\n", 1);
		write(1, "==> standard input <==\n", 24);
	}
	else
	{
		write(1, "==> ", 4);
		ft_putstr(basename(filename));
		write(1, " <==\n", 5);
	}
}

int	check_opening(char *filename, int i)
{
	int	fd;

	fd = 0;
	if ((ft_strlen(filename) == 1 && filename[0] == '-')
		|| (ft_strlen(filename) == 2 && filename[0] == '-'
			&& filename[1] == '-' && i == 0))
		return (fd);
	else
	{
		fd = open(filename, O_RDONLY);
		return (fd);
	}
}
