/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:05:55 by nliu              #+#    #+#             */
/*   Updated: 2023/10/01 20:14:27 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_aux(num, "0123456789");
	ft_putstr(str, counter);
	free(str);
}
