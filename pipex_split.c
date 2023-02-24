#include "libft/libft.h"

static int	count_words(char *str, char chr)
{
	int	wordcount;
	int	i;
	int single_quote;

	single_quote = 0;
	i = 0;
	wordcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			i++;
		if (str[i] == '\'')
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
	// ft_printf("%d\n", wordcount);
	return (wordcount);
}

static int	count_wordlen(char *s, char c)
{
	int	count;
	int single_quote;

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

char	**pipex_split(char const *s, char c)
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
		while (*s == c || *s == '\'')
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