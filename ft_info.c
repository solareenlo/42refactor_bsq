/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 18:43:04 by tayamamo         ###   ########.fr       */
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

t_map_info		*ft_parse_map_info(char **map)
{
	t_map_info	*info;
	char		*first_line;
	int			len;
	int			i;
	char		*number_of_lines;

	first_line = map[0];
	len = ft_strlen(first_line);
	info = (t_map_info *)malloc(sizeof(t_map_info *));
	number_of_lines = (char *)malloc(sizeof(char) * (len - 3) + 1);
	i = -1;
	while (++i < len - 3)
		number_of_lines[i] = first_line[i];
	number_of_lines[i] = '\0';
	info->number_of_rows = ft_atoi(number_of_lines);
	info->empty = first_line[len - 3];
	info->obstacle = first_line[len - 2];
	info->full = first_line[len - 1];
	free(number_of_lines);
	return (info);
}
