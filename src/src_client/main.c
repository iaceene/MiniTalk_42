/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:05 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/01 22:00:39 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_reciver(int sig)
{
	if (sig == SIGUSR1)
		return ;
}

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	signal(SIGUSR1, ft_reciver);
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(ft_err(3));
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(ft_err(3));
		}
		pause();
		i++;
	}
}

int	ft_send_msg(int pid, char *msg)
{
	while (*msg)
		ft_send(pid, *(msg)++);
	ft_send(pid, '\0');
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
			ft_send_msg(ft_atoi(v[1]), v[2]), ft_putstr("Done 🥂\n"), 0);
	return (0);
}
