/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 17:05:31 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "ft_atoi.h"
# include "ft_map_info.h"
# include "ft_split.h"
# include "ft_str.h"
# include "ft_utility.h"
# include "makesquare.h"
# include <fcntl.h>
# include <libgen.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_BUFSIZ 32768
# define FT_ERR_MAP "map error\n"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		g_max_size;
int		g_col;
int		g_row;
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
int		ft_validate_map(char **map, t_map_info *info);

#endif
