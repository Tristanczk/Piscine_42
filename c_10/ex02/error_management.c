/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:14:09 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 11:08:46 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_handle_opening_error(char *filename, char *program_name)
{
	ft_putstr_err(basename(program_name));
	write(2, ": cannot open '", 15);
	ft_putstr_err(basename(filename));
	write(2, "' for reading: ", 15);
	ft_putstr_err(strerror(errno));
	write(2, "\n", 1);
}

void	ft_handle_size_error(t_args args, char *program_name)
{
	if (args.size == -2)
	{
		ft_putstr_err(basename(program_name));
		write(2, ": option requires an argument -- 'c'\n", 37);
	}
	else if (args.size == -1)
	{
		ft_putstr_err(basename(program_name));
		write(2, ": invalid number of bytes: '", 28);
		write(2, args.size_error, ft_strlen(args.size_error));
		write(2, "'\n", 2);
	}
}
