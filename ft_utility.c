/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:44:48 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/07 18:53:08 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utility.h"

t_bool	ft_is_printable(char c)
{
	if (c < 0x20 || c == 0x7f)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_isspace(char c)
{
	if (c == ' ')
		return (TRUE);
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	else
		return (FALSE);
}

t_bool	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_last_char_a_line_break(char *line)
{
	int	len;

	if (!line)
		return (FALSE);
	len = ft_strlen(line);
	if (len < 1)
		return (FALSE);
	if (line[len - 1] != '\n')
		return (FALSE);
	return (TRUE);
}
