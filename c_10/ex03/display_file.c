/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:28:33 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 16:04:35 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	ft_dsp_file(int fd, t_file_pars *parsing, int len, char **buf)
{
	len += read(fd, *buf + len, MAX_CHAR - len);
	while (len == MAX_CHAR)
	{
		if (ft_strncmp(*buf, parsing->str_prev, MAX_CHAR) == 0)
			parsing->same++;
		else
		{
			parsing->same = 0;
			parsing->str_prev = ft_cpy_n(parsing->str_prev, *buf, MAX_CHAR);
		}
		print_lines(*buf, len, *parsing);
		parsing->mem += len;
		len = read(fd, *buf, MAX_CHAR);
	}
	return (len);
	if (fd > 0)
		close(fd);
}

t_file_pars	init_struct(int argc, char **argv)
{
	t_file_pars	parsing;

	parsing.program_name = argv[0];
	parsing.flag = check_args(argc, argv);
	parsing.same = 0;
	parsing.mem = 0;
	parsing.str_prev = malloc(17 * sizeof(char));
	parsing.str_prev[16] = '\0';
	parsing.nb_files = count_files_to_open(argc, argv);
	parsing.files = get_files_to_open(parsing.nb_files, argc, argv);
	parsing.last_valid_file = check_last_f(parsing.files, parsing.nb_files);
	return (parsing);
}

void	ft_dsp_last_line(t_file_pars *parsing, int len, char **buf)
{
	if (ft_strncmp(*buf, parsing->str_prev, len) == 0)
		parsing->same++;
	else
	{
		parsing->same = 0;
		parsing->str_prev = ft_cpy_n(parsing->str_prev, *buf, len);
	}
	print_lines(*buf, len, *parsing);
	parsing->mem += len;
	if (parsing->flag > 0)
		print_to_hex(parsing->mem, 8, -1);
	else
		print_to_hex(parsing->mem, 7, -1);
}

void	read_std_input(t_file_pars *parsing, char **buf)
{
	int		len_prev;
	int		len;

	len = read(0, *buf, MAX_CHAR);
	len_prev = 0;
	while (len > 0)
	{
		len_prev += len;
		if (len_prev == MAX_CHAR)
		{
			if (ft_strncmp(*buf, parsing->str_prev, MAX_CHAR) == 0)
				parsing->same++;
			else
			{
				parsing->same = 0;
				parsing->str_prev = ft_cpy_n(parsing->str_prev, *buf, MAX_CHAR);
			}
			print_lines(*buf, len_prev, *parsing);
			parsing->mem += len_prev;
			len_prev = 0;
		}
		len = read(0, *buf + len_prev, MAX_CHAR - len_prev);
	}
	ft_dsp_last_line(parsing, len_prev, buf);
}
