/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 18:29:06 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makesquare.h"

extern int		g_size_biggest_square;
extern int		g_col0_biggest_square;
extern int		g_row0_biggest_square;

void			ft_put_map(char **map, t_map_info *p_info)
{
	int	row;
	int	col;

	row = 1;
	while (row <= p_info->rows)
	{
		col = 0;
		while (col < p_info->cols)
		{
			write(1, &map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void			ft_write_biggest_square(char **map, t_map_info *p_info)
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
				p_info->full;
			col++;
		}
		row++;
	}
	return ;
}

static t_bool	extend_square(char **map, t_square *p_square, t_map_info *p_info)
{
	int	i;

	i = 0;
	while (i <= p_square->size)
	{
		if (ft_is_empty_char(
				map, p_square->col0 + i, p_square->row0 + p_square->size, p_info) ==
			FALSE)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= p_square->size)
	{
		if (ft_is_empty_char(
				map, p_square->col0 + p_square->size, p_square->row0 + i, p_info) ==
			FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void		make_biggest_square_info(char **map,
										t_square *p_square,
										t_map_info *p_info)
{
	p_square->size = 0;
	while (extend_square(map, p_square, p_info) == TRUE)
		p_square->size++;
	if (g_size_biggest_square < p_square->size)
	{
		g_size_biggest_square = p_square->size;
		g_col0_biggest_square = p_square->col0;
		g_row0_biggest_square = p_square->row0;
	}
}

void			ft_make_biggest_square(char **map, t_map_info *p_info)
{
	t_square	*p_square;

	g_size_biggest_square = 0;
	g_col0_biggest_square = 0;
	g_row0_biggest_square = 0;
	p_square = (t_square *)malloc(sizeof(t_square));
	if (p_square == NULL)
		return ;
	ft_init_square(p_square);
	while (p_square->row0 <= p_info->rows)
	{
		p_square->col0 = 0;
		while (p_square->col0 < p_info->cols)
		{
			if (ft_is_empty_char(map, p_square->col0, p_square->row0, p_info) ==
				TRUE)
				make_biggest_square_info(map, p_square, p_info);
			p_square->col0++;
		}
		p_square->row0++;
	}
	free(p_square);
	return ;
}
