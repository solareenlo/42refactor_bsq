/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 13:48:19 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		free_map(char ***map)
{
	long int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

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

int			ft_main_1(void)
{
	char		*content;
	char		**map;
	t_map_info	*map_info;

	content = read_to_eof(STDIN);
	if (ft_is_last_char_a_line_break(content) == FALSE)
	{
		free(content);
		return (FAIL);
	}
	map = ft_split(content, (char *)"\n");
	free(content);
	if (ft_is_valid_map_info(map) == FALSE)
	{
		free_map(&map);
		return (FAIL);
	}
	map_info = ft_parse_map_info(map);
	if (map_info == NULL)
	{
		free_map(&map);
		return (FAIL);
	}
	if (ft_validate_map(map, map_info) == FAIL)
	{
		free_map(&map);
		free(map_info);
		return (FAIL);
	}
	ft_make_map(map, map_info);
	ft_put_map(map, map_info);
	free_map(&map);
	free(map_info);
	return (SUCCESS);
}

int			ft_main_2(int argc, char *argv[], int i)
{
	int			ifd;
	char		*content;
	char		**map;
	t_map_info	*map_info;

	ifd = open(argv[i], O_RDONLY);
	if (ifd == -1)
		return (FAIL);
	content = read_to_eof(ifd);
	if (ft_is_last_char_a_line_break(content) == FALSE)
	{
		free(content);
		return (FAIL);
	}
	close(ifd);
	map = ft_split(content, (char *)"\n");
	free(content);
	if (ft_is_valid_map_info(map) == FAIL)
	{
		free_map(&map);
		return (FAIL);
	}
	map_info = ft_parse_map_info(map);
	if (map_info == NULL)
	{
		free_map(&map);
		return (FAIL);
	}
	if (ft_validate_map(map, map_info) == FAIL)
	{
		free_map(&map);
		free(map_info);
		return (FAIL);
	}
	ft_make_map(map, map_info);
	ft_put_map(map, map_info);
	if (!(i + 1 == argc))
		ft_putstr((char *)"\n");
	free_map(&map);
	free(map_info);
	return (SUCCESS);
}

int			main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		if (ft_main_1() == FAIL)
			ft_puterror((char *)FT_ERR_MAP);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (ft_main_2(argc, argv, i) == FAIL)
				ft_puterror((char *)FT_ERR_MAP);
		}
	}
	return (0);
}
