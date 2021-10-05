/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 17:18:39 by tayamamo         ###   ########.fr       */
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
	char	empty_char;
	char	obstacle_char;
	char	full_char;

	empty_char = info_char[0];
	obstacle_char = info_char[1];
	full_char = info_char[2];
	if (ft_is_printable(empty_char) == FALSE)
		return (FALSE);
	if (ft_is_printable(obstacle_char) == FALSE)
		return (FALSE);
	if (ft_is_printable(full_char) == FALSE)
		return (FALSE);
	if (empty_char == obstacle_char)
		return (FALSE);
	if (obstacle_char == full_char)
		return (FALSE);
	if (full_char == empty_char)
		return (FALSE);
	return (TRUE);
}

int				ft_is_valid_map_info(char **map)
{
	char	*first_line;
	int		len;

	if (!map[0])
		return (FAIL);
	first_line = map[0];
	len = ft_strlen(first_line);
	if (len < 4)
		return (FALSE);
	if (is_valid_number_of_line(first_line, len) == FALSE)
		return (FAIL);
	if (is_valid_map_info_char(&first_line[len - 3]) == FALSE)
		return (FAIL);
	return (SUCCESS);
}

t_info			*ft_prse(char **map)
{
	t_info	*info;
	char	*line;
	int		len;
	int		i;
	char	*num;

	line = map[0];
	len = ft_strlen(line);
	info = (t_info *)malloc(sizeof(t_info *));
	num = (char *)malloc(sizeof(char) * (len - 3) + 1);
	i = -1;
	while (++i < len - 3)
		num[i] = line[i];
	num[i] = '\0';
	info->num_rows = ft_atoi(num);
	info->empty = line[len - 3];
	info->obstacle = line[len - 2];
	info->full = line[len - 1];
	free(num);
	return (info);
}
