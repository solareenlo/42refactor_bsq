/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 15:20:28 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern int		g_max_size;
extern int		g_col;
extern int		g_row;

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
	while (row < g_max_size)
	{
		col = 0;
		while (col < g_max_size)
		{
			map[g_row + row][g_col + col] = p_info->full;
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
	while (i <= p_square->max_size)
	{
		if (ft_is_empty_char(map,
								p_square->col + i,
								p_square->row + p_square->max_size,
								p_info) == FALSE)
			return (FALSE);
		i++;
	}
	i = 0;
	while (i <= p_square->max_size)
	{
		if (ft_is_empty_char(map,
								p_square->col + p_square->max_size,
								p_square->row + i,
								p_info) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void		find_biggest_square_info(char **map,
										t_square *p_square,
										t_map_info *p_info)
{
	p_square->max_size = 0;
	while (extend_square(map, p_square, p_info) == TRUE)
		p_square->max_size++;
	if (g_max_size < p_square->max_size)
	{
		g_max_size = p_square->max_size;
		g_col = p_square->col;
		g_row = p_square->row;
	}
}

void			ft_find_biggest_square(char **map, t_map_info *p_info)
{
	t_square	*p_square;

	g_max_size = 0;
	g_col = 0;
	g_row = 0;
	p_square = (t_square *)malloc(sizeof(t_square));
	if (p_square == NULL)
		return ;
	ft_init_square(p_square);
	while (p_square->row <= p_info->rows)
	{
		p_square->col = 0;
		while (p_square->col < p_info->cols)
		{
			if (ft_is_empty_char(map, p_square->col, p_square->row, p_info) ==
				TRUE)
				find_biggest_square_info(map, p_square, p_info);
			p_square->col++;
		}
		p_square->row++;
	}
	free(p_square);
	return ;
}
