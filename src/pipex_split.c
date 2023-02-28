/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:01 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/02/28 13:15:03 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

static int	count_words(char *str, char chr)
{
	int	wordcount;
	int	i;
	int	single_quote;

	single_quote = 0;
	i = 0;
	wordcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			i++;
		if (str[i] == '\'' && str[i] != '\0')
			single_quote = 1;
		while ((str[i] != chr || single_quote) && str[i] != '\0')
		{
			i++;
			if (str[i] == '\'')
				single_quote = 0;
		}
		if (str[i - 1] != chr)
			wordcount++;
	}
	return (wordcount);
}

static int	count_wordlen(char *s, char c)
{
	int	count;
	int	single_quote;

	single_quote = 0;
	count = 0;
	while ((*s != c || single_quote) && *s != '\0')
	{
		if (*s == '\'')
		{
			single_quote = !single_quote;
			s++;
		}
		else
		{
			if (*(s - 1) == '\'')
				single_quote = !single_quote;
			count++;
			s++;
		}
	}
	return (count);
}

char	**error_free(char **array, int size)
{	
	size--;
	while (size > -1)
		free(array[size--]);
	free(array);
	return (NULL);
}

char	**pipex_split(char const *s, char c)
{
	t_split	var;

	var.i = 0;
	var.wordcount = count_words((char *)s, c);
	if (!var.wordcount)
		return (NULL);
	var.array = malloc(sizeof(char *) * (var.wordcount + 1));
	if (!var.array)
		return (NULL);
	while (var.i < var.wordcount)
	{
		while (*s == c || *s == '\'')
			s++;
		var.wordlen = count_wordlen((char *)s, c);
		var.array[var.i] = malloc (sizeof(char) * (var.wordlen + 1));
		if (var.array [var.i] == NULL)
			return (error_free(var.array, var.i));
		var.array[var.i] = ft_memcpy(var.array[var.i], s, var.wordlen);
		var.array[var.i++][var.wordlen] = '\0';
		while (*s != c && *s != '\0')
			s++;
	}
	var.array[var.i] = NULL;
	return (var.array);
}
