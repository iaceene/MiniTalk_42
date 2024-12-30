/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:05 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 09:58:05 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void ft_send(int pid, char c)
{
	int 	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR1);
			write(1, "1", 1);
		}
		else
		{
			kill(pid, SIGUSR2);
			write(1, "0", 1);
		}
		i--;
	}
}

int	ft_send_msg(int pid, char *msg)
{
	while (*msg)
		ft_send(pid, *(msg)++);
	ft_send(pid, '\0');
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