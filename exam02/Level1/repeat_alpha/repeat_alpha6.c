/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:31:51 by nliu              #+#    #+#             */
/*   Updated: 2023/07/01 16:55:18 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_n(char c, int n);
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	repeat_alpha(char *str)
{
	while (*str)
	{
		if (*str > 'a' && *str < 'z')
			ft_putchar_n(*str, *str + 1 - "a");
		else if (*str > 'A' && *str < 'Z')
			ft_putchar_n(*str, *str + 1 - "A");
		else
			write(1, str, 1);
		++str;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
