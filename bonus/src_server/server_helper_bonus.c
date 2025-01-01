/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:53:08 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/01 19:54:55 by yaajagro         ###   ########.fr       */
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

void	ft_hand_help(char *bit, int *count, t_buffer **buffer, int pid)
{
	if (*bit == '\0')
		ft_print_buffer(buffer, pid);
	else
		ft_lstadd_back(buffer, ft_lstnew(*bit));
	ft_reset(count, bit, 0);
}
