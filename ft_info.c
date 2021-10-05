/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 05:37:33 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_bool	is_valid_number_of_line(char *first_line, int len)
{
	int	i;

	i = -1;
	while (++i < len - 3)
		if (ft_isdigit(first_line[i]) == FALSE)
			return (FALSE);
	return (TRUE);
}

static t_bool	is_valid_map_info_char(char *info_char)
{
	char	empty;
	char	obstacle;
	char	full;

	empty = info_char[0];
	obstacle = info_char[1];
	full = info_char[2];
	if (!ft_is_printable(empty) || !ft_is_printable(obstacle) ||
		!ft_is_printable(full))
		return (FALSE);
	if (empty == obstacle || obstacle == full || full == empty)
		return (FALSE);
	return (TRUE);
}

t_bool			ft_is_valid_map_info(char **map)
{
	char	*first_line;
	int		len;

	if (!map[0])
		return (FALSE);
	first_line = map[0];
	len = ft_strlen(first_line);
	if (len < 4)
		return (FALSE);
	if (is_valid_number_of_line(first_line, len) == FALSE)
		return (FALSE);
	if (is_valid_map_info_char(&first_line[len - 3]) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int		get_number_of_rows(char *first_line, int len)
{
	int		i;
	char	*number_of_lines;
	int		number_of_rows;

	number_of_lines = (char *)malloc(sizeof(char) * (len - 3) + 1);
	if (number_of_lines == NULL)
		return (-1);
	i = -1;
	while (++i < len - 3)
		number_of_lines[i] = first_line[i];
	number_of_lines[i] = '\0';
	number_of_rows = ft_atoi(number_of_lines);
	free(number_of_lines);
	return (number_of_rows);
}

t_map_info		*ft_parse_map_info(char **map)
{
	t_map_info	*map_info;
	char		*first_line;
	int			len;

	map_info = (t_map_info *)malloc(sizeof(t_map_info *));
	if (map_info == NULL)
		return (NULL);
	first_line = map[0];
	len = ft_strlen(first_line);
	map_info->number_of_rows = get_number_of_rows(first_line, len);
	if (map_info->number_of_rows < 0)
	{
		free(map_info);
		return (NULL);
	}
	map_info->empty = first_line[len - 3];
	map_info->obstacle = first_line[len - 2];
	map_info->full = first_line[len - 1];
	return (map_info);
}
