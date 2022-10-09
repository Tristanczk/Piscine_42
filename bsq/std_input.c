/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:36:20 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/26 11:02:47 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_std_input(void)
{
	char	buf[1];
	int		fd;
	char	*pathname;
	int		length;

	length = 1;
	pathname = "stdinput.txt";
	fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	while (length > 0)
	{
		length = read(0, buf, 1);
		write(fd, buf, length);
	}
	close(fd);
	return (1);
}
