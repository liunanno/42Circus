/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:43:30 by nliu              #+#    #+#             */
/*   Updated: 2023/08/10 22:58:03 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return ;
    while (*stack)
    {
        tmp = (*stack) -> next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

void    exit_error(t_stack **stack_a, t_stack **stack_b)
{
    if (stack_a == NULL || *stack_a != NULL)
        free_stack(stack_a);
    if (stack_b == NULL || *stack_b != NULL)
        free_stack(stack_b);
    write(2, "Error\n", 6);
    exit (1);
}

long int    ft_atoi(const char *str)
{
    long int    nb;
    int isneg;
    int i;

    nb = 0;
    isneg = 1;
    i = 0;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        isneg *= -1;
        i++:
    }
    return (nb * isneg);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int nb_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    return (nb);
}