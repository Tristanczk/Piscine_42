/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:58:56 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/26 17:33:36 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_print_error(char *str);

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[1];

	if (argc < 2)
	{
		ft_print_error("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_print_error("Too many arguments.\n");
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_print_error("Cannot read file.\n");
		return (3);
	}
	while (read(fd, buf, 1) == 1)
	{
		write(1, buf, 1);
	}
	close(fd);
	return (0);
}

void	ft_print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}
