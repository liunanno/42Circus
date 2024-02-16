/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:06:36 by nliu              #+#    #+#             */
/*   Updated: 2024/02/15 22:49:12 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_valid(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		check_args();
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (!is_digit(argv[i]) || (!ft_atoi(argv[i])))
		{
			printf("Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_arg	args;

	if (ft_check_valid(argc, argv))
		return (1);
	if (init_args(&args, argc, argv) == 1)
		return (1);
	init_mutex(&args);
	init_philosophers(&args);
	init_threads(&args);
	end_threads(&args);
	unlock_and_destroy_mutex(&args);
	free_all(&args);
	return (0);
}
