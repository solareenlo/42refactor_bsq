/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:51:29 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 18:02:49 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef MAKESQUARE_H
# define MAKESQUARE_H

# include "ft_map_info.h"
# include "ft_str.h"
# include <unistd.h>

typedef struct	s_square
{
	int			col;
	int			row;
	int			max_size;
}				t_square;

int				g_max_size;
int				g_col;
int				g_row;

void			ft_put_map(char **map, t_map_info *p_info);
void			ft_write_biggest_square(char **map, t_map_info *p_info);
void			ft_make_biggest_square(char **map, t_map_info *p_info);

void			ft_init_square(t_square *p_square);
t_bool			ft_is_empty_char(char **map, int col, int row, t_map_info *p_info);

#endif
