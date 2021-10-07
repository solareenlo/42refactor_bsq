/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 17:35:16 by tayamamo         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map[i][j] == info->empty || map[i][j] == info->obstacle))
				return (FAIL);
		}
	}
	return (SUCCESS);
}

static int	validate_col_and_row_of_map(char **map, t_map_info *info)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (info->cols != ft_strlen(map[i]))
			return (FAIL);
		i++;
	}
	if (i - 1 != info->rows)
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
