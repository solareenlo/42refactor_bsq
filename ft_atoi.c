/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:51:43 by louisnop          #+#    #+#             */
/*   Updated: 2021/10/05 15:08:38 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_bool	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	return (FALSE);
}

int				ft_atoi(char *str)
{
	int	integer;
	int	sign;
	int	i;

	integer = 0;
	sign = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (str[i] != '\0' && is_digit(str[i]))
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1)
		return (integer * -1);
	else
		return (integer);
}
