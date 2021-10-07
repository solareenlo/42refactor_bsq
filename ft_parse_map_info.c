/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 20:55:35 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_info.h"

static int	get_map_cols(char **map)
{
	int	col;

	if (!map || !map[0] || !map[1] || !map[1][0])
		return (-1);
	col = ft_strlen(map[1]);
	return (col);
}

static int	get_map_rows(char *first_line, int len)
{
	int		i;
	char	*rows;
	int		map_rows;

	rows = (char *)malloc(sizeof(char) * len + 1);
	if (rows == NULL)
		return (-1);
	i = -1;
	while (++i < len)
		rows[i] = first_line[i];
	rows[i] = '\0';
	map_rows = ft_atoi(rows);
	free(rows);
	return (map_rows);
}

t_map_info	*ft_parse_map_info(char **map)
{
	t_map_info	*map_info;
	int			len;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (map_info == NULL)
		return (NULL);
	len = ft_strlen(map[0]);
	map_info->rows = get_map_rows(map[0], len - 3);
	if (map_info->rows < 0)
	{
		free(map_info);
		return (NULL);
	}
	map_info->cols = get_map_cols(map);
	if (map_info->cols < 0)
	{
		free(map_info);
		return (NULL);
	}
	map_info->empty = map[0][len - 3];
	map_info->obstacle = map[0][len - 2];
	map_info->full = map[0][len - 1];
	return (map_info);
}
