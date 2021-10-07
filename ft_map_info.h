/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:38:16 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 23:08:25 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef FT_MAP_INFO_H
# define FT_MAP_INFO_H

# include "ft_atoi.h"
# include "ft_utility.h"
# include <stdlib.h>

# define SUCCESS 1
# define FAIL 0

typedef struct s_map_info
{
	int			rows;
	int			cols;
	char		empty;
	char		obstacle;
	char		full;
}				t_map_info;

int				ft_validate_map_info(char **map);
t_map_info		*ft_parse_map_info(char **map);

#endif
