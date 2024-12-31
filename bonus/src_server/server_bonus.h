/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:13:18 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/31 19:17:54 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "signal.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_buffer
{
	char			c;
	struct s_buffer	*next;
}	t_buffer;

void		ft_putnbr(int n);
void		ft_putstr(char *s);
void		ft_print_pid(void);
void		ft_handler(int sig, siginfo_t *info, void *ucontext);
t_buffer	*ft_lstlast(t_buffer *lst);
t_buffer	*ft_lstnew(char chara);
void		ft_lstadd_back(t_buffer **lst, t_buffer *new);
void		ft_print_buffer(t_buffer **head, int pid);
void		ft_lstclear(t_buffer **lst);

#endif