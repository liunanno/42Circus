/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:14:31 by nliu              #+#    #+#             */
/*   Updated: 2023/06/25 22:25:14 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	printnbr(number)
{
	char str;

	str[10] = "0123456789";
	if (number > 9)
		printnbr(number / 10);
	write(1, &str[number % 10], 1);
}

int	main()
{
	int	i;

	i = 0;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			printnbr(i);
		i++;
		write(1, "\n", 1);
	}
}
