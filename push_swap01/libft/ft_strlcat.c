/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:52:33 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 17:23:04 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src && !dst)
		return (0);
	if (destsize == 0)
		return (ft_strlen(src));
	while (dst[j] && j < destsize)
		j++;
	while ((i + j + 1) < destsize && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j != destsize)
		dst[j + i] = '\0';
	return (j + (ft_strlen(src)));
}
