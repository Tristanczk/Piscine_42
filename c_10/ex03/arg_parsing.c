/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:05:12 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 16:21:28 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{		
		if (is_c_flag(argv[i]) == 1)
		{
			i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

int	manage_file(t_file_pars *parsing, int i, char **buf, int *len)
{
	int	fd;

	fd = open(parsing->files[i], O_RDONLY);
	if (fd < 0)
	{
		ft_handle_error(parsing->files[i], parsing->program_name);
		i++;
	}
	else if (i != parsing->last_valid_file)
	{
		*len = ft_dsp_file(fd, parsing, *len, buf);
		i++;
	}
	else
	{
		*len = ft_dsp_file(fd, parsing, *len, buf);
		while (i + 1 < parsing->nb_files)
		{
			ft_handle_error(parsing->files[i + 1], parsing->program_name);
			i++;
		}
		ft_dsp_last_line(parsing, *len, buf);
		i++;
	}
	return (i);
}

int	count_files_to_open(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (is_c_flag(argv[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

char	**get_files_to_open(int count, int argc, char **argv)
{
	char	**files;
	int		i;
	int		j;

	i = 1;
	j = 0;
	files = malloc(count * sizeof(char *));
	if (!files)
		return (NULL);
	while (i < argc)
	{
		if (is_c_flag(argv[i]) == 0)
		{
			files[j] = argv[i];
			i++;
			j++;
		}
		else
			i++;
	}
	return (files);
}
