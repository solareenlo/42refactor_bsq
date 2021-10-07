/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:26:51 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 21:28:12 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ft_put_map.h"

void	ft_put_map(char **map, t_map_info *map_info)
{
	int	row;
	int	col;

	row = 1;
	while (row <= map_info->rows)
	{
		col = 0;
		while (col < map_info->cols)
		{
			write(1, &map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
