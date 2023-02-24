/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:29:35 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/04 12:39:54 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char chr)
{
	int	wordcount;
	int	i;

	i = 0;
	wordcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			i++;
		while (str[i] != chr && str[i] != '\0')
			i++;
		if (str[i - 1] != chr)
			wordcount++;
	}
	return (wordcount);
}

static int	count_wordlen(char *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordcount;
	int		wordlen;
	char	**array;

	wordcount = count_words((char *)s, c);
	i = 0;
	array = malloc(sizeof(char *) * (wordcount + 1));
	if (array == NULL)
		return (NULL);
	while (i < wordcount)
	{
		while (*s == c)
			s++;
		wordlen = count_wordlen((char *)s, c);
		array[i] = malloc (sizeof(char) * (wordlen + 1));
		if (array [i] == NULL)
			return (NULL);
		array[i] = ft_memcpy(array[i], s, wordlen);
		array[i++][wordlen] = '\0';
		while (*s != c && *s != '\0')
			s++;
	}
	array[i] = NULL;
	return (array);
}
