/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 21:04:00 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validate_map.h"

static int	validate_exist_of_map(char **map, t_map_info *info)
{
	if (!map || !map[0] || !map[1])
		return (FAIL);
	if (!(map[1][0] == info->empty || map[1][0] == info->obstacle ||
			map[1][0] == info->full))
		return (FAIL);
	return (SUCCESS);
}

static int	validate_char_of_map(char **map, t_map_info *info)
{
	int	row;
	int	col;

	row = 0;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (!(map[row][col] == info->empty || map[row][col] == info->obstacle))
				return (FAIL);
		}
	}
	return (SUCCESS);
}

static int	validate_col_and_row_of_map(char **map, t_map_info *info)
{
	int	row;

	row = 1;
	while (map[row])
	{
		if (info->cols != ft_strlen(map[row]))
			return (FAIL);
		row++;
	}
	if (row - 1 != info->rows)
		return (FAIL);
	return (SUCCESS);
}

int			ft_validate_map(char **map, t_map_info *map_info)
{
	if (validate_exist_of_map(map, map_info) == FAIL)
		return (FAIL);
	if (validate_char_of_map(map, map_info) == FAIL)
		return (FAIL);
	if (validate_col_and_row_of_map(map, map_info) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
