/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_make_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 21:40:31 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_make_square.h"

void	ft_init_square(t_square *p_square)
{
	p_square->row0 = 1;
	p_square->col0 = 0;
	p_square->size = 0;
}

t_bool	ft_is_empty_char(char **map, int col, int row, t_map_info *p_info)
{
	if (col == p_info->cols)
		return (FALSE);
	if (row == p_info->rows + 1)
		return (FALSE);
	if (map[row][col] == p_info->obstacle || map[row][col] == '\0')
		return (FALSE);
	return (TRUE);
}

void	ft_write_biggest_square(char **map, t_map_info *map_info)
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
