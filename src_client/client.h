/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:53:49 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/30 09:59:18 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#include "signal.h"
#include "unistd.h"
#include "string.h"
#include "stdlib.h"

void    ft_puterr(char *s);
int     ft_isnum(char *s);
int     pid_checker(char *s);
int     ft_err(int err);

#endif