/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:16:33 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:37:56 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	char	*pathname;
	char	**lines;
	t_dict	*dict;
	t_dict	*number;

	number = NULL;
	pathname = "numbers.dict";
	if (check_argcs(argc, argv) != 0)
		return (1);
	if (argc == 3)
		pathname = argv[1];
	lines = parse_dict(pathname);
	if (!lines)
		return (2);
	dict = create_dict(lines);
	parse_number(check_number_input(argv[argc - 1]), &number, dict);
	if (check_dict(number) == 0)
		return (3);
	ft_print_number(number);
	ft_dict_value_clear(dict);
	ft_dict_clear(number);
	return (0);
}

int	check_argcs(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_number_input(argv[argc - 1]) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
