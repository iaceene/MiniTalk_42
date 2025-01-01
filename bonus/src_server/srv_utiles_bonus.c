/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_utiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:14:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/01 04:13:37 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	ft_print_pid(void)
{
	ft_putstr("\nServer PID : ");
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
		ft_putstr("\n->> ");
	*count = 0;
	*bit = 0;
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		count;
	static char		bit;
	static t_buffer	*buffer;
	static int		pid;

	(void)ucontext;
	if (pid != info->si_pid)
	{
		if (count < 8 && count > 0)
			write(2, "[ Message incomplited ! ]", 25);
		ft_reset(&count, &bit, 1);
		pid = info->si_pid;
		ft_lstclear(&buffer);
	}
	if (sig == SIGUSR1)
		bit |= (1 << count);
	count++;
	if (count == 8)
	{
		if (bit == '\0')
			ft_print_buffer(&buffer, info->si_pid);
		else
			ft_lstadd_back(&buffer, ft_lstnew(bit));
		ft_reset(&count, &bit, 0);
	}
	usleep(500);
	kill(info->si_pid, SIGUSR2);
}
