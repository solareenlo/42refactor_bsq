/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmakesquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:46:00 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 18:29:26 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "makesquare.h"

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
