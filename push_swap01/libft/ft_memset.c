/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:48:10 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 17:23:23 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = NULL;
	tmp = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char) c;
		i++;
	}
	return ((void *) b);
}
