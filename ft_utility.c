/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:44:48 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/06 05:43:54 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
