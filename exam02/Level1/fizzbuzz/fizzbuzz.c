/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:40:40 by nliu              #+#    #+#             */
/*   Updated: 2023/06/25 22:04:17 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	p_number(number)
{
	char	str[10] = "0123456789"

	if (number > 9)
		p_number(number / 10);
	write(1, &str[number % 10], 1);
}

int	main()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			p_number(i);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
