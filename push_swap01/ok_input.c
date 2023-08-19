/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:52 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:52:53 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ok_input(char **matrix, int i)
{
	int	j;
	int	tmp;

	tmp = i;
	if (matrix[++i] == NULL)
		return (-1);
	i = tmp;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if ((matrix[i][j] < 58 && matrix[i][j] > 47)
				|| ((matrix[i][j] == 45) && j == 0))
				j++;
			else
				return (-1);
		}
		i++;
	}
	if (double_n(matrix, tmp) == -1)
		return (-1);
	if (min_max(matrix, tmp) == -1)
		return (-1);
	return (1);
}

int	double_n(char **matrix, int i)
{
	int	j;

	while (matrix[i])
	{
		j = i + 1;
		while (matrix[j])
		{
			if (atoi(matrix[i]) != atoi(matrix[j]))
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	min_max(char **matrix, int i)
{
	long	value;

	while (matrix[i])
	{
		value = ft_atoi(matrix[i]);
		if (value > 2147483647 || value < -2147483648)
			return (-1);
		i++;
	}
	return (1);
}

int	okorko2(t_listx **stack_a)
{
	t_listx	*tmp;
	t_listx	*succ;

	tmp = *stack_a;
	succ = (*stack_a)->next;
	while (succ)
	{
		if (tmp->content < succ->content)
		{
			tmp = tmp->next;
			succ = succ->next;
		}
		else
			return (-1);
	}
	return (0);
}
