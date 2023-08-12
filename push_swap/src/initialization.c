/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:57:49 by nliu              #+#    #+#             */
/*   Updated: 2023/08/09 21:11:25 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *fill_stack_values(int ac, char **av)
{
    t_stack *stack_a;
    long int    nb;
    int i;

    stack_a = NULL;
    nb = 0;
    i = 1;
    while (i < ac)
    {
        nb = ft_atoi(av[i]);
        if (nb > INT_MAX || nb < INT_MIN)
            exit_error(&stack_a, NULL);
        if (i == 1)
            stack_a = stack_new((int)nb);
        else
            stack_add_bottom(&stack_a, stack_new((int)nb));
        i++;
    }
    return (stack_a);
}

void    assign_index(t_stack *stack_a, int stack_size)
{
    t_stack *ptr;
    t_stack *highest;
    int value;

    while (--stack_size > 0)
    {
        ptr = stack_a;
        value = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr -> value == INT_MIN && ptr -> index == 0)
                ptr -> index = 1;
            if (ptr -> value > value && ptr -> index == 0)
            {
                value = ptr -> value;
                highest = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr -> next;
        }
        if (highest != NULL)
            highest -> index = stack_size;
    }
}