/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:30 by nliu              #+#    #+#             */
/*   Updated: 2023/10/02 18:41:18 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_address;

	ptr_address = (unsigned long)ptr;
	ft_putstr("0x", counter);
	str = ft_aux(ptr_address, HEX_LOW_BASE);
	ft_putstr(str, counter);
	free(str);
}
