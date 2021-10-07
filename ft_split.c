/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:55:41 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/07 20:48:41 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

static char		**free_and_return_null(char **s, size_t size)
{
	if (!s || !*s)
		return (NULL);
	while (size--)
		free(*s++);
	free(s);
	return (NULL);
}

static size_t	str_len(char const *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static size_t	cnt_word(char const *s, char c)
{
	size_t	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			cnt++;
		while (*s != c && *s)
			s++;
	}
	return (cnt);
}

static void		copy_str(char *dst, const char **src, const char c)
{
	char	*d;

	if (!dst || !src || !*src)
		return ;
	d = dst;
	while (**src == c)
		(*src)++;
	while (**src != c && **src)
		*(d++) = *((*src)++);
	*d = '\0';
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	char	**front;
	size_t	cnt;
	size_t	i;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	cnt = cnt_word(s, c);
	front = strs;
	i = -1;
	while (++i < cnt)
	{
		*strs = (char *)malloc(sizeof(char) * (str_len(s, c) + 1));
		if (*strs == NULL)
			return (free_and_return_null(strs, i));
		copy_str(*strs, &s, c);
		strs++;
	}
	*strs = NULL;
	return (front);
}
