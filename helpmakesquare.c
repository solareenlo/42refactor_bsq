/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 14:45:44 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern int	g_max;
extern int	g_col;
extern int	g_row;

int			ft_map_col_size(char **map)
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
	p_tempcrs->max_size = 0;
}

t_bool		ft_is_empty_char(char **map, int col, int row, t_map_info *p_info)
{
	if (col == p_info->cols)
		return (FALSE);
	if (row == p_info->rows + 1)
		return (FALSE);
	if (map[row][col] == p_info->obstacle || map[row][col] == '\0')
		return (FALSE);
	return (TRUE);
}

void		ft_set_bsq(t_bsq *p_bsq)
{
	p_bsq->x = g_col;
	p_bsq->y = g_row;
	p_bsq->max_size = g_max;
}
