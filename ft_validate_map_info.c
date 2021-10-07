/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:25:28 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 23:08:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ft_map_info.h"

static t_bool	is_valid_map_rows(char *first_line, int len)
{
	int	i;

	if (!first_line)
		return (FALSE);
	i = -1;
	while (++i < len - 3)
		if (!ft_isdigit(first_line[i]))
			return (FALSE);
	return (TRUE);
}

static t_bool	is_valid_map_info_chars(char *chars)
{
	int		len;
	char	empty;
	char	obstacle;
	char	full;

	if (!chars)
		return (FALSE);
	len = ft_strlen(chars);
	if (len != 3)
		return (FALSE);
	empty = chars[0];
	obstacle = chars[1];
	full = chars[2];
	if (!ft_is_printable(empty) || !ft_is_printable(obstacle)
		|| !ft_is_printable(full))
		return (FALSE);
	if (empty == obstacle || obstacle == full || full == empty)
		return (FALSE);
	return (TRUE);
}

int	ft_validate_map_info(char **map)
{
	int	len;

	if (!map || !map[0])
		return (FAIL);
	len = ft_strlen(map[0]);
	if (len < 4)
		return (FAIL);
	if (is_valid_map_rows(map[0], len) == FALSE)
		return (FAIL);
	if (is_valid_map_info_chars(&map[0][len - 3]) == FALSE)
		return (FAIL);
	return (SUCCESS);
}
