/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:46:41 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 14:13:46 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

t_args	get_size_to_print(int argc, char **argv)
{
	t_args	args;
	int		i;

	args.size = -1;
	args.size_error = 0;
	args.nb_files = count_files_to_open(argc, argv);
	args.files = 0;
	i = 1;
	while (i < argc)
	{
		if (is_size_arg(argv[i]) == 0)
			i++;
		else
		{
			check_size(&args, argv, i);
			if (args.size < 0)
				return (args);
			else
				i++;
		}
	}
	if (args.nb_files > 0 && args.size >= 0)
		args.files = get_files_to_open(args.nb_files, argc, argv);
	return (args);
}

void	check_size(t_args *args, char **argv, int i)
{
	if (is_size_arg(argv[i]) == 1)
	{
		args->size = get_number(argv[i] + 2);
		args->size_error = argv[i] + 2;
	}
	else if (argv[i + 1])
	{
		args->size = get_number(argv[i + 1]);
		args->size_error = argv[i + 1];
	}
	else
		args->size = -2;
}

// returns 0 if arg is not -c arg, else returns 1 if size is
// next to -c or 2 if size is the following arg
int	is_size_arg(char *str)
{
	if (strlen(str) < 2 || str[0] != '-' || str[1] != 'c')
		return (0);
	else if (strlen(str) > 2)
		return (1);
	else
		return (2);
}

int	count_files_to_open(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (is_size_arg(argv[i]) == 0)
		{
			count++;
			i++;
		}
		else
			i += is_size_arg(argv[i]);
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
		if (is_size_arg(argv[i]) == 0)
		{
			files[j] = argv[i];
			i++;
			j++;
		}
		else
			i += is_size_arg(argv[i]);
	}
	return (files);
}
