/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:53:08 by nliu              #+#    #+#             */
/*   Updated: 2023/08/10 18:57:59 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;

    if (*src == NULL)
        return ;
    tmp = (*src) -> next;
    (*src) -> next = *dest;
    *dest = *src;
    *src = tmp;
}

void    do_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr("pa\n");
}

void    do_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr("pb\n");
}