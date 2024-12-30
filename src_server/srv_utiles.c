/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:14:00 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 10:14:38 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void ft_print_pid(void)
{
	ft_putstr("Server PID > ");
	ft_putnbr(getpid());
	ft_putstr("\n");
}

void ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void ft_handler(int signal)
{
}