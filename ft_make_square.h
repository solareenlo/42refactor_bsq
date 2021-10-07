/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_square.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:51:29 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 21:39:19 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef FT_MAKE_SQUARE_H
# define FT_MAKE_SQUARE_H

# include "ft_map_info.h"
# include "ft_str.h"
# include <unistd.h>

typedef struct	s_square
{
	int			col0;
	int			row0;
	int			size;
}				t_square;

int				g_size_biggest_square;
int				g_col0_biggest_square;
int				g_row0_biggest_square;

void			ft_make_biggest_square(char **map, t_map_info *p_info);

void			ft_init_square(t_square *p_square);
t_bool			ft_is_empty_char(char **map, int col, int row, t_map_info *p_info);
void			ft_write_biggest_square(char **map, t_map_info *p_info);

#endif
