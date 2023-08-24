/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:16:59 by nliu              #+#    #+#             */
/*   Updated: 2023/08/04 18:36:07 by nliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_delimiter(str[i]))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && !is_delimiter(str[i]))
			i++;
	}
	return (count);
}

char	*copy_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_delimiter(str[i]))
		i++;
	word = (char *)malloc(i + 1);
	i = 0;
	while (str[i] && !is_delimiter(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		word_count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word_count = count_words(str);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	while (str[i])
	{
		while (is_delimiter(str[i]))
			i++;
		if (str[i] != '\0')
		{
			result[j] = copy_word(str + i);
			j++;
		}
		while (str[i] && !is_delimiter(str[i]))
			i++;
	}
	result[j] = NULL;
	return (result);
}
