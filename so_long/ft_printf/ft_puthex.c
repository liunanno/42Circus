/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:35:44 by nliu              #+#    #+#             */
/*   Updated: 2023/10/01 20:15:06 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, size_t *counter, char *base)
{
	char	*str;

	str = ft_aux(num, base);
	ft_putstr(str, counter);
	free(str);
}
