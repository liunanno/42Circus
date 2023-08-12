/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src:rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:13:42 by nliu              #+#    #+#             */
/*   Updated: 2023/08/10 19:17:48 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tmp = *stack;
    *stack = (*stack) -> next;
    tail = get_stack_bottom(*stack);
    tmp -> next = NULL;
    tail -> next = tmp;
}

void    do_ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr("ra\n");
}

void    fo_rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr("rb\n");
}

void    fo_rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr\n");
}