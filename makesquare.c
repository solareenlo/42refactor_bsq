/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 21:13:27 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makesquare.h"

extern int		g_size_biggest_square;
extern int		g_col0_biggest_square;
extern int		g_row0_biggest_square;

void			ft_put_map(char **map, t_map_info *map_info)
{
	int	row;
	int	col;

	row = 1;
	while (row <= map_info->rows)
	{
		col = 0;
		while (col < map_info->cols)
		{
			write(1, &map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void			ft_write_biggest_square(char **map, t_map_info *map_info)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_size_biggest_square)
	{
		col = 0;
		while (col < g_size_biggest_square)
		{
			map[g_row0_biggest_square + row][g_col0_biggest_square + col] =
				map_info->full;
			col++;
		}
		row++;
	}
	return ;
}

static t_bool	extend_square(char **map, t_square *square, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i <= square->size)
	{
		if (ft_is_empty_char(
				map, square->col0 + i, square->row0 + square->size, map_info) ==
			FALSE)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= square->size)
	{
		if (ft_is_empty_char(
				map, square->col0 + square->size, square->row0 + i, map_info) ==
			FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void		make_biggest_square_info(char **map,
										t_square *square,
										t_map_info *map_info)
{
	square->size = 0;
	while (extend_square(map, square, map_info) == TRUE)
		square->size++;
	if (g_size_biggest_square < square->size)
	{
		g_size_biggest_square = square->size;
		g_col0_biggest_square = square->col0;
		g_row0_biggest_square = square->row0;
	}
}

void			ft_make_biggest_square(char **map, t_map_info *map_info)
{
	t_square	*square;

	g_size_biggest_square = 0;
	g_col0_biggest_square = 0;
	g_row0_biggest_square = 0;
	square = (t_square *)malloc(sizeof(t_square));
	if (square == NULL)
		return ;
	ft_init_square(square);
	while (square->row0 <= map_info->rows)
	{
		square->col0 = 0;
		while (square->col0 < map_info->cols)
		{
			if (ft_is_empty_char(map, square->col0, square->row0, map_info) ==
				TRUE)
				make_biggest_square_info(map, square, map_info);
			square->col0++;
		}
		square->row0++;
	}
	free(square);
	return ;
}
