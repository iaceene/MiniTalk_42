/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:13:18 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 12:36:19 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SERVER_H
# define SERVER_H

# include "signal.h"
# include "unistd.h"
# include "string.h"
# include "stdlib.h"

void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_print_pid(void);
void	ft_handler(int sig, siginfo_t *info, void *ucontext);

#endif