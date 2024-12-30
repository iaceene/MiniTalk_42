/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:14:00 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 12:35:40 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print_pid(void)
{
	ft_putstr("Server PID > ");
	ft_putnbr(getpid());
	ft_putstr("\n");
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_reset(int *count, char *bit, int flag)
{
	if (flag == 1)
		ft_putstr("\n");
	*count = 0;
	*bit = 0;
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	count;
	static char	bit;
	static int	pid;

	(void)ucontext;
	if (pid != info->si_pid)
	{
		ft_reset(&count, &bit, 1);
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		bit |= (1 << count);
	count++;
	if (count == 8)
	{
		write(1, &bit, 1);
		ft_reset(&count, &bit, 0);
	}
}
