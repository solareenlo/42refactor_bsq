/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 23:13:53 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_make_square.h"

extern int	g_size_biggest_square;
extern int	g_col0_biggest_square;
extern int	g_row0_biggest_square;

static void	init_biggest_square(void)
{
	g_size_biggest_square = 0;
	g_col0_biggest_square = 0;
	g_row0_biggest_square = 0;
}

static t_bool	extend_square(char **map, t_square *square,
					t_map_info *map_info)
{
	int	i;
	int	col;
	int	row;

	i = 0;
	while (i <= square->size)
	{
		col = square->col0 + i;
		row = square->row0 + square->size;
		if (ft_is_empty_char(map, col, row, map_info) == FALSE)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= square->size)
	{
		col = square->col0 + square->size;
		row = square->row0 + i;
		if (ft_is_empty_char(map, col, row, map_info) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	make_biggest_square_info(char **map,
				t_square *square,
				t_map_info *map_info)
{
	if (ft_is_empty_char(map, square->col0, square->row0, map_info) == TRUE)
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
}

void	ft_make_biggest_square(char **map, t_map_info *map_info)
{
	t_square	*square;

	square = (t_square *)malloc(sizeof(t_square));
	if (square == NULL)
		return ;
	init_biggest_square();
	ft_init_square(square);
	while (square->row0 <= map_info->rows)
	{
		square->col0 = 0;
		while (square->col0 < map_info->cols)
		{
			make_biggest_square_info(map, square, map_info);
			square->col0++;
		}
		square->row0++;
	}
	free(square);
	return ;
}
