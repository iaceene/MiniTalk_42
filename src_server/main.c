/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:08:52 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/29 16:10:48 by yaajagro         ###   ########.fr       */
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

static void ft_handler(int signal)
{
    static char c = 0;  // To store the current character
    static int bit = 0; // To count the bits

    // Handle signal based on its type
    if (signal == SIGUSR1) {
        c |= (1 << (7 - bit));  // Set the corresponding bit to 1
    }

    // Increment the bit counter
    bit++;

    // Once 8 bits are received (a full byte)
    if (bit == 8) {
        // If the character is not null, print it
        if (c != '\0') {
            write(1, &c, 1);  // Print the character
        }

        // Reset bit counter and character
        bit = 0;
        c = 0;
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