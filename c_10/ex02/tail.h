/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:30:40 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 12:34:12 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 16384

typedef struct t_args
{
	long	size;
	char	*size_error;
	int		nb_files;
	char	**files;
}	t_args;

t_args	get_size_to_print(int argc, char **argv);
void	check_size(t_args *args, char **argv, int i);
int		is_size_arg(char *str);
int		count_files_to_open(int argc, char **argv);
char	**get_files_to_open(int count, int argc, char **argv);
void	display_file(int fd, int size_to_print);
char	*ft_concatenate_buffers(char *dest, char *buf, int length);
void	display_header(char *filename, int i);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr_err(char *str);
long	get_number(char *str);
void	ft_handle_opening_error(char *filename, char *program_name);
void	ft_handle_size_error(t_args args, char *program_name);
int		check_opening(char *filename, int i);
void	manage_file(t_args args, char **argv, int i);

#endif