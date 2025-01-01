/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:58:15 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/01 22:06:50 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_puterr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int	ft_isnum(char *s)
{
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || (*s == '-' || *s == '+')))
			return (0);
		s++;
	}
	return (1);
}

int	pid_checker(char *s)
{
	if (!ft_isnum(s) || ft_atoi(s) < 0)
		return (1);
	return (0);
}

int	ft_err(int err)
{
	if (err == 1)
		ft_puterr("Usage : ./client <PID> <text>\n");
	else if (err == 2)
		ft_puterr("Invalid PID :)\n");
	else if (err == 3)
		ft_puterr("Fail to send > - <\n");
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
