/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:53:49 by tayamamo          #+#    #+#             */
/*   Updated: 2021/10/08 09:07:35 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = ft_strlen(src);
	copy = (char *)malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*join;
	int			i;
	int			j;
	const int	len = ft_strlen(s1) + ft_strlen(s2) + 1;

	join = (char *)malloc(sizeof(char) * len);
	if (join == NULL)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			join[i++] = s2[j++];
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if (*s == c)
		return ((char *)s);
	else
	{
		while (*(s++))
			if (*s == c)
				return ((char *)s);
	}
	return (NULL);
}
