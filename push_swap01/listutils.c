/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:54:47 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:52:50 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listx	*ps_lstnew(int content)
{
	t_listx	*tmp;

	tmp = malloc(sizeof(t_listx));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}

int	ps_lstsize(t_listx *lst)
{
	t_listx	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ps_lstadd_front(t_listx **lst, t_listx *new)
{
	new->next = *lst;
	*lst = new;
}

void	ps_lstadd_back(t_listx **lst, t_listx *new)
{
	t_listx	*tmp;

	if (*lst)
	{
		tmp = ps_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

t_listx	*ps_lstlast(t_listx *lst)
{
	t_listx	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
