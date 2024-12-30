/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:58:15 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 10:09:55 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_puterr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int	ft_isnum(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

int	pid_checker(char *s)
{
	if (!ft_isnum(s) || kill(ft_atoi(s), 0) == -1)
		return (1);
	return (kill(ft_atoi(s), 0));
}

int	ft_err(int err)
{
	if (err == 1)
		ft_puterr("Usage : ./client <PID> <text>\n");
	else if (err == 2)
		ft_puterr("Invalid PID :)\n");
	return (1);
}

int	ft_atoi(char *s)
{
	int	i;
	int	res;
	int	sing;

	res = 0;
	sing = 1;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sing);
}
