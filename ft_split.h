/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:17:11 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 19:52:22 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# define IN 1
# define OUT 0

# include "ft_str.h"
# include "ft_utility.h"
# include <stdlib.h>

// char	**ft_split(char *str, char *charset);
char	**ft_split(char const *s, char c);

#endif
