/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makesquare2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 14:13:11 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern int	g_max;
extern int	g_col;
extern int	g_row;

int			ft_check_2(char **map, t_tempcrs *p_tempcrs, t_map_info *p_info)
{
	int	i;

	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_is_empty_char(map,
								p_tempcrs->col + i,
								p_tempcrs->row + p_tempcrs->size,
								p_info) == FALSE)
			return (0);
		i++;
	}
	i = 0;
	while (i <= p_tempcrs->size)
	{
		if (ft_is_empty_char(map,
								p_tempcrs->col + p_tempcrs->size,
								p_tempcrs->row + i,
								p_info) == FALSE)
			return (0);
		i++;
	}
	return (1);
}

void		ft_check_3(char **map, t_tempcrs *p_tempcrs, t_map_info *p_info)
{
	p_tempcrs->size = 0;
	while (ft_check_2(map, p_tempcrs, p_info) == 1)
		p_tempcrs->size++;
	if (g_max < p_tempcrs->size)
	{
		g_max = p_tempcrs->size;
		g_col = p_tempcrs->col;
		g_row = p_tempcrs->row;
	}
}

void		ft_put_map(char **map, t_map_info *p_info)
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

static void	change_map(char **map, t_map_info *p_info)
{
	int	row;
	int	col;

	row = 0;
	while (row < g_max)
	{
		col = 0;
		while (col < g_max)
		{
			map[g_row + row][g_col + col] = p_info->full;
			col++;
		}
		row++;
	}
	return ;
}

void		ft_make_map(char **map, t_map_info *p_info)
{
	t_tempcrs	*p_tempcrs;

	g_max = 0;
	g_col = 0;
	g_row = 0;
	p_tempcrs = (t_tempcrs *)malloc(sizeof(t_tempcrs));
	if (p_tempcrs == NULL)
		return ;
	ft_set_tempcrs(p_tempcrs);
	while (p_tempcrs->row <= p_info->rows)
	{
		p_tempcrs->col = 0;
		while (p_tempcrs->col < p_info->cols)
		{
			if (ft_is_empty_char(map, p_tempcrs->col, p_tempcrs->row, p_info) ==
				TRUE)
				ft_check_3(map, p_tempcrs, p_info);
			p_tempcrs->col++;
		}
		p_tempcrs->row++;
	}
	change_map(map, p_info);
	free(p_tempcrs);
	return ;
}
