/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:24:50 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/31 20:05:01 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"
#include "server_bonus.h"

t_buffer	*ft_lstlast(t_buffer *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst-> next)
		lst = lst -> next;
	return (lst);
}

t_buffer	*ft_lstnew(char chara)
{
	t_buffer	*new_node;

	new_node = malloc(sizeof(t_buffer));
	if (!new_node)
		return (NULL);
	new_node -> c = chara;
	new_node -> next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_buffer **lst, t_buffer *new)
{
	t_buffer	*last_node;

	if (!lst || !new)
	{
		ft_lstclear(lst);
		return ;
	}
	if (!*lst)
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		if (!last_node)
			return ;
		last_node -> next = new;
	}
}

void	ft_lstclear(t_buffer **lst)
{
	t_buffer	*tmp;

	if (!lst || !(*lst))
		return ;
	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
	*lst = NULL;
}

void	ft_print_buffer(t_buffer **head, int pid)
{
	t_buffer	*tmp;

	tmp = *head;
	while (tmp)
	{
		write(1, &tmp->c, 1);
		tmp = tmp->next;
	}
	usleep(800);
	kill(pid, SIGUSR1);
}
