/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:16:07 by nlesage           #+#    #+#             */
/*   Updated: 2022/07/26 15:31:02 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

# define BUFFER_SIZE 16384

typedef struct t_point
{
	int	x;
	int	y;
	int	length;
}	t_point;

typedef struct s_map
{
	int		height;
	int		length;
	char	empty;
	char	obstacle;
	char	solid;
}	t_map;

int		min_3_val(int val1, int val2, int val3);
int		**dp_matrix(char **lines, t_map map);
int		**dp_matrix_first(char **lines, t_map map);
int		**init_matrix(int height, int length);
int		get_max_coord(t_point *point, int **dp_matrix, int height, int length);
void	solve_matrix(char **lines, t_map map);
char	**ft_return_file(char *pathname);
int		ft_get_len_file(char *pathname);
char	*ft_manage_file_errors(int fd, int len_file);
char	*ft_return_path(char *argv_i);
int		ft_c_buffer(char *buf);
char	**ft_split(char *str, char *charset);
int		ft_count_nb_word(char *str, char *charset, int nb_mot);
int		ft_is_in_charset(char character, char *charset);
int		ft_nb_char_in_word(char *str, char *charset, int i);
char	**ft_complete_table(char *str, char *charset, char **tab, int i);
int		ft_strlen(char *str);
void	ft_free_double(char **tab);
void	ft_free_double_int(int **tab, t_map map);
int		ft_c_is_printable(char c);
void	ft_putchar(char c);
int		ft_handle(char *argv_i);
int		ft_atoi(const char *str);
int		ft_nb_digits(int nb);
t_map	ft_check_matrix(char **table);
t_map	ft_import_row(char **table, int len, int i);
int		ft_check_first_row(t_map map, int len);
int		ft_check_core(char **table, t_map map);
void	print_matrix(char **lines, t_map map);
char	**complete_matrix(char **lines, t_point coord, t_map map);
int		read_std_input(void);

#endif
