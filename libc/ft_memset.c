/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:39:09 by nliu              #+#    #+#             */
/*   Updated: 2023/03/30 20:11:54 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

int main() {
    char buffer[20];

    // Set the first 10 bytes in buffer to the character 'A'
    ft_memset(buffer, 'A', 10);
    buffer[10] = '\0';  // Add a null terminator at the 11th byte position to treat it as a string

    printf("Buffer content: %s\n", buffer);

    return 0;
}
