/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:49 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/31 14:54:58 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "signal.h"
# include "unistd.h"
# include "stdlib.h"

void	ft_puterr(char *s);
int		ft_isnum(char *s);
int		pid_checker(char *s);
int		ft_err(int err);
int		ft_atoi(char *s);

#endif