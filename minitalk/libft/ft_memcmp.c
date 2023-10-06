/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:01:44 by nliu              #+#    #+#             */
/*   Updated: 2023/03/30 14:03:27 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(ptr1 + i) != *(unsigned char *)(ptr2 + i))
		{
			return (*(unsigned char *)(ptr1 + i) -
			*(unsigned char *)(ptr2 + i));
		}
		i++;
	}
	return (0);
}
