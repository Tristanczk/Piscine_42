/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tczarnia <tczarnia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:44:20 by tczarnia          #+#    #+#             */
/*   Updated: 2022/07/27 08:36:37 by tczarnia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <libgen.h>
# include <string.h>
# include <errno.h>

void	ft_display_file(int fd);
void	ft_handle_error(char *filename, char *program_name);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);

#endif