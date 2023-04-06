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
#include "libft.h"

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

static int	count_wordlen(char *s, char c, t_split *var)
{
	int	count;
	int	single_quote;

	single_quote = var->single_quote;
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
			if (*(s - 1) == '\'' && !single_quote)
				single_quote = !single_quote;
			count++;
			s++;
		}
	}
	return (count);
}

int	split_init(t_split *var, char const *s, char c)
{
	var->single_quote = 0;
	var->i = 0;
	var->wordcount = count_words((char *)s, c);
	if (!var->wordcount)
		return (-1);
	var->array = malloc(sizeof(char *) * (var->wordcount + 1));
	if (!var->array)
		return (-1);
	return (0);
}

const char	*check_single_quote(const char *s, char c, t_split *var)
{
	while ((*s == c || (*s == '\'' && *(s -1) != '\'')) && !var->single_quote)
	{
		if (*s == '\'')
			var->single_quote = 1;
		s++;
	}
	return (s);
}

char	**pipex_split(char const *s, char c)
{
	t_split	var;

	if (split_init(&var, s, c))
		return (NULL);
	while (var.i < var.wordcount)
	{
		s = check_single_quote(s, c, &var);
		var.wordlen = count_wordlen((char *)s, c, &var);
		var.array[var.i] = malloc (sizeof(char) * (var.wordlen + 1));
		if (var.array [var.i] == NULL)
			return (error_free(var.array, var.i));
		var.array[var.i] = ft_memcpy(var.array[var.i], s, var.wordlen);
		var.array[var.i++][var.wordlen] = '\0';
		while ((*s != c || var.single_quote) && *s != '\0')
		{
			if (*s == '\'')
				var.single_quote = 0;
			s++;
		}
	}
	var.array[var.i] = NULL;
	return (var.array);
}
