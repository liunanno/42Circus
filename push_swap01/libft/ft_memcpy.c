# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.c                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 16:46:07 by nliu              #+#    #+#              #
#    Updated: 2023/08/19 16:46:07 by nliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	i = 0;
	if (!(void *) dst && !(void *) src)
		return (NULL);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned const char *) src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return ((void *) dst);
}
