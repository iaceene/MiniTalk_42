/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:08:52 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 10:17:30 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int main(void)
{
	struct	sigaction sig;

	ft_print_pid();
	sig.sa_handler = ft_handler;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		pause();
	return (0);
}
