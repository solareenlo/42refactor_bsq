/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 16:32:16 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int			g_word_index = 0;
int			g_start = 0;
int			g_end = 0;
int			g_state = 0;

static int	get_wc(char *str, char *charset)
{
	int	wc;
	int	state;

	wc = 0;
	state = OUT;
	while (*str)
	{
		if (ft_strchr(charset, *str))
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}
	return (wc);
}

static void	update_in_word(int i)
{
	if (g_state == OUT)
	{
		g_state = IN;
		g_start = i;
		g_end = i;
	}
	else
		g_end = i;
}

static void	add_last_word(char **res, char *str, int i)
{
	int	j;

	if (g_state == IN)
	{
		res[g_word_index] = (char *)malloc(sizeof(char) * ((i - g_start) + 1));
		j = -1;
		while (g_start <= i)
			res[g_word_index][++j] = str[g_start++];
		res[g_word_index][++j] = '\0';
		g_word_index++;
	}
	res[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
}

char		**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (get_wc(str, charset) + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (ft_strchr(charset, str[i]))
		{
			if (g_state == OUT)
				continue ;
			g_state = OUT;
			res[g_word_index] =
				(char *)malloc(sizeof(char) * ((g_end - g_start) + 1));
			j = -1;
			while (g_start <= g_end)
				res[g_word_index][++j] = str[g_start++];
			res[g_word_index][++j] = '\0';
			g_word_index++;
		}
		else
			update_in_word(i);
	}
	add_last_word(res, str, i);
	return (res);
}
