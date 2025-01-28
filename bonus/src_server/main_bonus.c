/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:08:52 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/28 21:27:20 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	ft_exit(int sig)
{
	if (sig == SIGINT)
	{
		ft_handler(-1, NULL, NULL);
		ft_putstr("Good Bye !\n");
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_print_pid();
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, ft_exit);
	while (1)
		pause();
	return (0);
}
