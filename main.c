/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 20:38:21 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*read_to_eof(int fd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	if (fd < 0 || read(fd, buf, 0) < 0 || FT_BUFSIZ < 0)
		return (NULL);
	content = NULL;
	while (42)
	{
		n = read(fd, buf, FT_BUFSIZ);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		if (content == NULL)
			content = ft_strdup(buf);
		else
			content = ft_strjoin(content, buf);
	}
	return (content);
}

t_bool		free_and_return_fail(char *str, char **map, t_map_info *map_info)
{
	free(str);
	ft_free_split(&map);
	free(map_info);
	return (FAIL);
}

static int	bsq(int fd)
{
	char		*content;
	char		**map;
	t_map_info	*map_info;

	content = read_to_eof(fd);
	if (ft_is_last_char_a_line_break(content) == FALSE)
		return (free_and_return_fail(content, NULL, NULL));
	map = ft_split(content, '\n');
	free(content);
	if (ft_validate_map_info(map) == FAIL)
		return (free_and_return_fail(NULL, map, NULL));
	map_info = ft_parse_map_info(map);
	if (map_info == NULL)
		return (free_and_return_fail(NULL, map, NULL));
	if (ft_validate_map(map, map_info) == FAIL)
		return (free_and_return_fail(NULL, map, map_info));
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
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		ifd = open(argv[i], O_RDONLY);
		if (bsq(ifd) == FAIL)
			ft_puterror((char *)FT_ERR_MAP);
		if (i + 1 != argc)
			ft_putstr((char *)"\n");
	}
	return (0);
}
