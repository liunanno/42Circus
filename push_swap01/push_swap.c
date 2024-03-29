/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:00:55 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:53:07 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_listx	*stack_a;
	t_listx	*stack_b;
	t_memo	mem;
	t_inst	inst;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (ft_strlen(av[1]) == 0)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	inst_init(&inst);
	if (list_init(ac, av, &stack_a) == -1)
	{
		write(2, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (okorko2(&stack_a) == 0)
		return (free_all(&stack_a));
	init_b(&stack_a, &stack_b, &mem);
	algoritm(&stack_a, &stack_b, &inst, &mem);
	return (free_all(&stack_a));
}
