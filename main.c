/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 17:01:58 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_free(char ***map)
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
	char	*content;
	char	**map;
	t_info	*info;

	content = read_to_eof(STDIN);
	if (ft_is_last_char_a_line_break(content) == FALSE)
		return (FAIL);
	map = ft_split(content, (char *)"\n");
	free(content);
	if (ft_is_valid_map_info(map) == FAIL)
		return (FAIL);
	if ((info = ft_prse(map)) == FAIL)
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	ft_free(&map);
	free(info);
	return (SUCCESS);
}

int			ft_main_2(int argc, char *argv[], int i)
{
	int		ifd;
	char	*content;
	char	**map;
	t_info	*info;

	if ((ifd = open(argv[i], O_RDONLY)) == -1)
		return (FAIL);
	content = read_to_eof(ifd);
	if (ft_is_last_char_a_line_break(content) == FALSE)
		return (FAIL);
	close(ifd);
	map = ft_split(content, (char *)"\n");
	free(content);
	if (ft_is_valid_map_info(map) == FAIL)
		return (FAIL);
	if (!(info = ft_prse(map)))
		return (FAIL);
	if (ft_validate(map, info) == FAIL)
		return (FAIL);
	ft_make_map(map, info);
	if (!(i + 1 == argc))
		ft_putstr((char *)"\n");
	ft_free(&map);
	free(info);
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
