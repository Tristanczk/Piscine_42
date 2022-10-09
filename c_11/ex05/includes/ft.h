/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:51 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/19 18:42:19 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_isspace(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	addition(long a, long b);
void	substraction(long a, long b);
void	multiplication(long a, long b);
void	division(long a, long b);
void	modulo(long a, long b);
int		is_operator(char c);

#endif