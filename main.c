/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 17:53:28 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*read_to_eof(int ifd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	content = NULL;
	while ((n = read(ifd, buf, FT_BUFSIZ)) > 0)
	{
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}

static int	bsq(int ifd)
{
	char		*content;
	char		**map;
	t_map_info	*map_info;

	if (ifd < 0)
		return (FAIL);
	content = read_to_eof(ifd);
	if (ft_is_last_char_a_line_break(content) == FALSE)
	{
		free(content);
		return (FAIL);
	}
	map = ft_split(content, (char *)"\n");
	free(content);
	if (ft_validate_map_info(map) == FAIL)
	{
		ft_free_split(&map);
		return (FAIL);
	}
	map_info = ft_parse_map_info(map);
	if (map_info == NULL)
	{
		ft_free_split(&map);
		return (FAIL);
	}
	if (ft_validate_map(map, map_info) == FAIL)
	{
		ft_free_split(&map);
		free(map_info);
		return (FAIL);
	}
	ft_find_biggest_square(map, map_info);
	ft_write_biggest_square(map, map_info);
	ft_put_map(map, map_info);
	ft_free_split(&map);
	free(map_info);
	return (SUCCESS);
}

int			main(int argc, char *argv[])
{
	int	i;
	int	ifd;

	if (argc < 2)
	{
		if (bsq(STDIN) == FAIL)
			ft_puterror((char *)FT_ERR_MAP);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			ifd = open(argv[i], O_RDONLY);
			if (bsq(ifd) == FAIL)
				ft_puterror((char *)FT_ERR_MAP);
			if (i + 1 != argc)
				ft_putstr((char *)"\n");
		}
	}
	return (0);
}
