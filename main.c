/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 18:38:36 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char	*read_to_eof(int fd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	if (fd < 0 || read(fd, buf, 0) < 0 || FT_BUFSIZ < 0)
		return (NULL);
	content = NULL;
	while ((n = read(fd, buf, FT_BUFSIZ)) > 0)
	{
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}

static int	bsq(int fd)
{
	char		*content;
	char		**map;
	t_map_info	*map_info;

	content = read_to_eof(fd);
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
	ft_make_biggest_square(map, map_info);
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
