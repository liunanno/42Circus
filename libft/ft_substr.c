/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:17:54 by nliu              #+#    #+#             */
/*   Updated: 2023/05/31 11:56:05 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	else
		str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (len > 0 && start <= ft_strlen(s))
	{
		str[j] = s[start];
		j++;
		len--;
		start++;
	}
	str[j] = 0;
	return (str);
}
