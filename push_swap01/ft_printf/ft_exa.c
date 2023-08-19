/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:20:05 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:58:46 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_exa_pf(unsigned int nb, const char format, int i)
{
	if (nb >= 16)
	{
		i++;
		i = ft_exa_pf(nb / 16, format, i);
	}
	if (format == 'x')
		ft_putchar_pf("0123456789abcdef"[nb % 16]);
	if (format == 'X')
		ft_putchar_pf("0123456789ABCDEF"[nb % 16]);
	return (i);
}
