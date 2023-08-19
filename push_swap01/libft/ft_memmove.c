/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:47:48 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 17:23:25 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		i;

	i = 0;
	tmp_dst = (char *) dst;
	tmp_src = (const char *) src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	return ((void *) dst);
}
