/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 13:07:37 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern int	g_max;
extern int	g_col;
extern int	g_row;

int			ft_map_colsize(char **map)
{
	int	col;

	if (!map || !map[0] || !map[1] || !map[1][0])
		return (-1);
	col = ft_strlen(map[1]);
	return (col);
}

void		ft_set_tempcrs(t_tempcrs *p_tempcrs)
{
	p_tempcrs->row = 1;
	p_tempcrs->col = 0;
	p_tempcrs->size = 0;
}

int			ft_check_1(char **map, int col, int row, t_map_info *p_info)
{
	if (col == ft_map_colsize(map))
		return (0);
	if (row == p_info->rows + 1)
		return (0);
	if (map[row][col] == p_info->obstacle || map[row][col] == '\0')
		return (0);
	return (1);
}

void		ft_set_bsq(t_bsq *p_bsq)
{
	p_bsq->x = g_col;
	p_bsq->y = g_row;
	p_bsq->size = g_max;
}
