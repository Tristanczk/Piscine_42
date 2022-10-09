/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:26:47 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/28 16:15:31 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_CHAR 16

typedef struct t_file_pars
{
	int					same;
	unsigned long long	mem;
	int					flag;
	char				*str_prev;
	int					nb_files;
	char				**files;
	int					last_valid_file;
	char				*program_name;
}	t_file_pars;

void		ft_putstr(char *str);
void		ft_putchar(char c);
int			ft_strlen(char *str);
void		ft_putstr_err(char *str);
void		print_char_point(char c);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*ft_cpy_n(char *dest, char *src, unsigned int n);
void		print_lines(char *str, int length, t_file_pars parsing);
void		print_to_hex(unsigned long long n, unsigned int size, int flag);
void		print_hex_flag(char	*str, int length);
void		print_hex_no_flag(char	*str, int length);
void		print_final_text(char *str, int length);
int			check_args(int argc, char **argv);
int			is_c_flag(char *str);
int			count_files_to_open(int argc, char **argv);
char		**get_files_to_open(int count, int argc, char **argv);
int			ft_dsp_file(int fd, t_file_pars *parsing, int len, char **buf);
void		ft_dsp_last_line(t_file_pars *parsing, int len, char **buf);
int			is_std_input(char *str);
void		ft_handle_error(char *filename, char *program_name);
int			check_last_f(char **files, int count);
t_file_pars	init_struct(int argc, char **argv);
void		ft_parse_files(t_file_pars parsing);
void		read_std_input(t_file_pars *parsing, char **buf);
int			manage_file(t_file_pars *parsing, int i, char **buf, int *len);

#endif