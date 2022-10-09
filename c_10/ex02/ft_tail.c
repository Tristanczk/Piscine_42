/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:39:57 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 14:49:56 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	main(int argc, char **argv)
{
	t_args	args;
	int		i;

	args = get_size_to_print(argc, argv);
	if (args.size < 0)
	{
		ft_handle_size_error(args, argv[0]);
		return (1);
	}
	if (args.nb_files == 0)
	{
		display_file(0, args.size);
		return (0);
	}	
	i = 0;
	while (i < args.nb_files)
	{
		manage_file(args, argv, i);
		i++;
	}
	free(args.files);
	return (0);
}

void	manage_file(t_args args, char **argv, int i)
{
	int	fd;

	fd = check_opening(args.files[i], i);
	if (fd < 0)
	{
		ft_handle_opening_error(args.files[i], argv[0]);
		return ;
	}
	if (args.nb_files == 1)
		display_file(fd, args.size);
	else
	{
		display_header(args.files[i], i);
		display_file(fd, args.size);
		close(fd);
	}
}
