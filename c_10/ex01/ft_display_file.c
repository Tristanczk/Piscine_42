/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:46:46 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 08:37:05 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	ft_display_file(int fd)
{
	char	buf[16384];
	int		length;

	length = 1;
	while (length > 0)
	{
		length = read(fd, buf, 16384);
		write(1, buf, length);
	}
	if (fd != 0)
		close(fd);
}

void	ft_handle_error(char *filename, char *program_name)
{
	ft_putstr_err(basename(program_name));
	write(2, ": ", 2);
	ft_putstr_err(basename(filename));
	write(2, ": ", 2);
	ft_putstr_err(strerror(errno));
	write(2, "\n", 1);
}
