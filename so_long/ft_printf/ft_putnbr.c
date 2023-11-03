/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:43:27 by nliu              #+#    #+#             */
/*   Updated: 2023/10/01 20:14:57 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num, size_t *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr((num / 10), counter);
		ft_putchar('8', counter);
	}
	else if (num < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-num, counter);
	}
	else
	{
		if (num > 9)
			ft_putnbr((num / 10), counter);
		ft_putchar(('0' + num % 10), counter);
	}
}
