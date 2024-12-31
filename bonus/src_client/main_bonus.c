/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:05 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/31 14:32:36 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("sent successfully...\n");
}

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(300);
		i++;
	}
}

int	ft_send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	signal(SIGUSR1, ft_handler);
	while (*msg)
		ft_send(pid, *(msg)++);
	ft_send(pid, '\0');
	while (i == 0)
	{
		pause();
		i++;
	}
	return (0);
}

int	main(int c, char **v)
{
	if (c != 3)
		return (ft_err(1));
	else if (pid_checker(v[1]))
		return (ft_err(2));
	else
		return (ft_putstr("Sending...\n"),
			ft_send_msg(ft_atoi(v[1]), v[2]));
	return (0);
}
