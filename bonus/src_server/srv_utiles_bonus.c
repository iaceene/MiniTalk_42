/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_utiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:14:00 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/01 21:45:11 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
		ft_hand_help(&bit, &count, &buffer, info->si_pid);
	usleep(700);
	kill(info->si_pid, SIGUSR2);
}
