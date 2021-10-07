/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:02:55 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 16:10:33 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef FT_UTILITY_H
# define FT_UTILITY_H

# define TRUE 1
# define FALSE 0

# include "ft_str.h"

typedef int	t_bool;

t_bool		ft_is_printable(char c);
t_bool		ft_isspace(char c);
t_bool		ft_isdigit(char c);
t_bool		ft_is_last_char_a_line_break(char *line);

#endif
