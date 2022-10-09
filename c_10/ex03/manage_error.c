/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:17:32 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 15:56:01 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	ft_handle_error(char *filename, char *program_name)
{
	ft_putstr_err(basename(program_name));
	write(2, ": ", 2);
	ft_putstr_err(basename(filename));
	write(2, ": ", 2);
	ft_putstr_err(strerror(errno));
	write(2, "\n", 1);
}

int	check_last_f(char **files, int count)
{
	int	i;
	int	last;
	int	fd;

	i = 0;
	last = -1;
	while (i < count)
	{
		fd = open(files[i], O_RDONLY);
		if (fd > 0)
		{
			last = i;
			close(fd);
		}
		i++;
	}
	return (last);
}
