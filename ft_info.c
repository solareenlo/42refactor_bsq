/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 15:21:58 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_validate_5(char **map)
{
	int		len;
	char	*line;
	int		i;

	if (!map[0])
		return (FAIL);
	line = map[0];
	len = ft_strlen(line);
	if (len < 4)
		return (FAIL);
	i = -1;
	while (++i < len - 3)
		if (ft_isdigit(line[i]) == FALSE)
			return (FAIL);
	if (!(ft_is_printable(line[len - 1]) && ft_is_printable(line[len - 2]) &&
			ft_is_printable(line[len - 3])))
		return (FAIL);
	if (line[len - 1] == line[len - 2] || line[len - 2] == line[len - 3] ||
		line[len - 3] == line[len - 1])
		return (FAIL);
	return (SUCCESS);
}

t_info	*ft_prse(char **map)
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
