/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:48:12 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/17 17:03:27 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header file with all prototypes
#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# include <stdlib.h>
# define SIZE 4

void	ft_backtracking(int *result, int position, int *input, int *found);
int		ft_strlen(char *str);
int		check_args(char *str);
int		check_row_left(int *result, int row, int *input);
int		check_row_right(int *result, int row, int *input);
int		check_column_up(int *result, int column, int *input);
int		check_column_down(int *result, int column, int *input);
int		is_valid_array(int *result, int *input);
int		check_value_left(int *result, int value, int position);
int		check_value_up(int *result, int value, int position);
int		is_valid_value(int *result, int value, int position);
void	printtab(int *tab);
void	ft_putchar(char c);
int		*init_inputs_tabs(char *str);
int		*init_result_tabs(void);
#endif