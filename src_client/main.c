/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:05 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/28 17:32:19 by yaajagro         ###   ########.fr       */
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

void ft_send(int pid, char c)
{
	int 	i;
	char	bit;

	i = 7;
	while(i >= 0)
	{
		bit = (c >> i) & 1;
		if (!bit)
		{
			if (kill(pid, SIGUSR1))
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2))
				exit(1);
		}
		i--;
		usleep(800);
	}
}

int	ft_send_msg(int pid, char *msg)
{
	while (*msg)
		ft_send(pid, *(msg)++);
	ft_send(pid, '\n');
	return (0);	
}

int main(int c, char **v)
{
	if (c != 3)
		return (ft_err(1));
	else if (pid_checker(v[1]))
		return (ft_err(2));
	else
		return (ft_send_msg(atoi(v[1]), v[2]));
	return (0);
}