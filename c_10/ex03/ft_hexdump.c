/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:22:02 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 16:15:56 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	main(int argc, char **argv)
{
	t_file_pars	parsing;

	parsing = init_struct(argc, argv);
	ft_parse_files(parsing);
	free(parsing.files);
	return (0);
}

void	ft_parse_files(t_file_pars parsing)
{
	int		i;
	int		len;
	char	*buf;

	i = 0;
	len = 0;
	buf = malloc(17 * sizeof(char));
	if (!buf)
		return ;
	buf[16] = '\0';
	if (parsing.nb_files == 0 || (parsing.nb_files == 1
			&& is_std_input(parsing.files[0]) == 1))
	{
		read_std_input(&parsing, &buf);
		return ;
	}
	while (i < parsing.nb_files)
		i = manage_file(&parsing, i, &buf, &len);
	free(buf);
}
