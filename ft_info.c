/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 18:17:40 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_bool	is_valid_number_of_line(char *first_line, int len)
{
	int	i;

	if (!first_line)
		return (FALSE);
	i = -1;
	while (++i < len - 3)
		if (ft_isdigit(first_line[i]) == FALSE)
			return (FALSE);
	return (TRUE);
}

static t_bool	is_valid_map_info_chars(char *chars)
{
	char	empty;
	char	obstacle;
	char	full;

	if (!chars)
		return (FALSE);
	empty = chars[0];
	obstacle = chars[1];
	full = chars[2];
	if (!ft_is_printable(empty) || !ft_is_printable(obstacle) ||
		!ft_is_printable(full))
		return (FALSE);
	if (empty == obstacle || obstacle == full || full == empty)
		return (FALSE);
	return (TRUE);
}

int				ft_validate_map_info(char **map)
{
	int	len;

	if (!map || !map[0])
		return (FAIL);
	len = ft_strlen(map[0]);
	if (len < 4)
		return (FAIL);
	if (is_valid_number_of_line(map[0], len) == FALSE)
		return (FAIL);
	if (is_valid_map_info_chars(&map[0][len - 3]) == FALSE)
		return (FAIL);
	return (SUCCESS);
}

static int		get_map_rows(char *first_line, int len)
{
	int		i;
	char	*number_of_lines;
	int		rows;

	number_of_lines = (char *)malloc(sizeof(char) * (len - 3) + 1);
	if (number_of_lines == NULL)
		return (-1);
	i = -1;
	while (++i < len - 3)
		number_of_lines[i] = first_line[i];
	number_of_lines[i] = '\0';
	rows = ft_atoi(number_of_lines);
	free(number_of_lines);
	return (rows);
}

t_map_info		*ft_parse_map_info(char **map)
{
	t_map_info	*map_info;
	int			len;

	map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (map_info == NULL)
		return (NULL);
	len = ft_strlen(map[0]);
	map_info->rows = get_map_rows(map[0], len);
	if (map_info->rows < 0)
	{
		free(map_info);
		return (NULL);
	}
	map_info->cols = ft_get_map_cols(map);
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
