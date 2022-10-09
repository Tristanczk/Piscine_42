/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 09:25:47 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/24 20:38:02 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_dict
{
	long			key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

int		get_len_file(char *pathname);
int		is_space(char c);
int		ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
int		is_in_charset(char c, char *charset);
int		count_strings(char *str, char *charset);
char	*store_word(char *str, char	*charset);
char	*ft_strjoin(char **strs);
int		calculate_total_memory(char **strs);
char	*ft_strcat(char *dest, char *src);
long	ft_atoi(char *str);
char	**parse_dict(char *pathname);
int		get_len_file(char *pathname);
char	*get_value_dict(char *str);
t_dict	*create_dict(char **lines);
t_dict	*ft_create_elem(long key, char *value);
void	ft_sorted_dict_insert(t_dict **begin_dict, long key, char *value);
void	ft_dict_push_front(t_dict **begin_dict, long key, char *value);
void	ft_dict_push_back(t_dict **begin_dict, long key, char *value);
void	ft_dict_clear(t_dict *begin_dict);
void	ft_dict_value_clear(t_dict *begin_dict);
char	*get_value_for_key(long key, t_dict *dict);
void	parse_triplet(long n, t_dict **number, t_dict *dict);
void	parse_number(long n, t_dict **number, t_dict *dict);
long	check_number_input(char *str);
int		check_dict(t_dict *begin_dict);
void	ft_putstr(char *str);
void	ft_print_number(t_dict *number);
int		check_argcs(int argc, char **argv);
int		manage_file_errors(int fd, char **buf, int len_file);
char	*ft_atoi_str(char *str);
int		ft_strcmp_const(char *s1, const char *s2);
int		check_all_keys(char **lines);

#endif
