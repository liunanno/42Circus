/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:21:07 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 18:58:51 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char c, int *nchar)
{
	int	x;

	x = 1;
	if (c == 'c')
		*nchar += ft_putchar_pf(va_arg(args, int));
	if (c == 's')
		*nchar += ft_putstr_pf(va_arg(args, char *));
	if (c == 'p')
	{
		*nchar += ft_putstr_pf("0x");
		*nchar += ft_putptr_pf(va_arg(args, unsigned long long), x);
	}
	if (c == 'd')
		*nchar += ft_putnbr_pf(va_arg(args, int), x);
	if (c == 'i')
		*nchar += ft_putnbr_pf(va_arg(args, int), x);
	if (c == 'u')
		*nchar += ft_putnbr_un_pf(va_arg(args, unsigned int), x);
	if (c == 'x' || c == 'X')
		*nchar += ft_exa_pf(va_arg(args, unsigned int), c, x);
	if (c == '%')
		*nchar += ft_putchar_pf('%');
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nchar;

	nchar = 0;
	i = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(args, str[++i], &nchar);
			i++;
		}
		else
		{
			ft_putchar_pf(str[i]);
			i++;
			nchar++;
		}
	}
	va_end(args);
	return (nchar);
}
