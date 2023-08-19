/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <nliu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:53:57 by nliu              #+#    #+#             */
/*   Updated: 2023/08/19 17:22:58 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while ((ptr1[i] != '\0' || ptr2[i] != '\0') && i < n)
	{
		if (ptr1[i] > ptr2[i])
		{
			return (1);
		}
		else if (ptr1[i] < ptr2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
