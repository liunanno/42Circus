/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:20:39 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:58:49 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int nb, int i)
{
	if (nb == -2147483648)
	{
		ft_putstr_pf("-2147483648");
		return (11);
	}
	else if (nb < 0)
	{
		i++;
		ft_putchar_pf('-');
		i = ft_putnbr_pf(-nb, i);
	}
	else
	{
		if (nb > 9)
		{
			i++;
			i = ft_putnbr_pf(nb / 10, i);
		}
		ft_putchar_pf(nb % 10 + 48);
	}
	return (i);
}

int	ft_putnbr_un_pf(unsigned int nb, int i)
{
	if (nb > 9)
	{
		i++;
		i = ft_putnbr_un_pf(nb / 10, i);
	}
	ft_putchar_pf(nb % 10 + 48);
	return (i);
}
