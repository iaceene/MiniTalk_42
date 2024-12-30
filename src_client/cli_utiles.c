/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:58:15 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 09:58:16 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void ft_puterr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

int ft_isnum(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}

int pid_checker(char *s)
{
	if (!ft_isnum(s) || kill(atoi(s), 0) == -1)
		return (1);
	return (kill(atoi(s), 0));
}

int ft_err(int err)
{
	if (err == 1)
		ft_puterr("Usage : ./client <PID> <text>\n");
	else if (err == 2)
		ft_puterr("Invalid PID :)\n");
	return (1);
}
