/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:11:45 by nliu              #+#    #+#             */
/*   Updated: 2023/08/14 20:40:26 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct  s_stack
{
    int                 value;
    int                 index;
    int                 pos;
    int                 target_pos;
    int                 cost_a;
    int                 cost_b;
    struct s_stack  *next;
}   t_stack;

/* initialization */
t_stack *fill_stack_values(int ac, char **av);
void    assign_index(t_stack *stack_a, int ac);

/* sorting algorithms */
int         is_sorted(t_stack *stack);
void    tiny_sort(t_stack **stack);
void    sort(t_stack **stack_a, t_stack **stack_b);

/* position */
int     get_lowest_index_position(t_stack **stack);
void    get_target_position(t_stack **stack_a, t_stack **stack_b);

/* cost */
void    get_cost(t_stack **stack_a, t_stack **stack_b);
void    do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* calculate move */
void    do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* operations */
void    do_pa(t_stack **stack_a, t_stack **stack_b);
void    do_pb(t_stack **stack_a, t_stack **stack_b);
void    do_sa(t_stack **stack_a);
void    do_sb(t_stack **stack_b);
void    do_ss(t_stack **stack_a, t_stack **stack_b);
void    do_ra(t_stack **stack_a);
void    do_rb(t_stack **stack_b);
void    do_rr(t_stack **stack_a, t_stack **stack_b);
void    do_rrr(t_stack **stack_a, t_stack **stack_b);
void    do_rra(t_stack **stack_a);
void    do_rrb(t_stack **stack_b);

/* stack functions */
t_stack *get_stack_bottom(t_stack *stack);
t_stack *get_stack_before_bottom(t_stack *stack);
t_stack *stack_new(int value);
void    stack_add_bottom(t_stack **stack, t_stack *new);
int     get_stack_size(t_stack *stack);

/* utils */
void    free_stack(t_stack **stack);
long int    ft_atoi(const char *str);
void    ft_putstr(char *str);
int     nb_abs(int nb);

/* error */
void    exit_error(t_stack **stack_a, t_stack **stack_b);

/* input check */
int     is_correct_input(char **av);
int     is_digit(char c);
int     is_sign(char c);
int     nbstr_cmp(const char *s1, const char *s2);

#endif