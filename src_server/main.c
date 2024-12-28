/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:08:52 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/28 17:40:27 by yaajagro         ###   ########.fr       */
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

void ft_handler(int c)
{
    static int count;
    static char byte;

    if (c == SIGUSR1)
        byte &= ~(1 << (7 - count));  // Set the bit at position 'count' to 0
    else if (c == SIGUSR2)
        byte |= (1 << (7 - count));   // Set the bit at position 'count' to 1

    count++;

    // If we've received 8 bits, process the byte
    if (count == 8)
    {
        write(1, &byte, 1);  // Print the character corresponding to the byte
        count = 0;            // Reset the count for the next byte
        byte = 0;             // Reset the byte for the next message
    }
}

int main(void)
{
	struct sigaction sig;
	ft_print_pid();
	sig.sa_handler = ft_handler;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		pause();
}