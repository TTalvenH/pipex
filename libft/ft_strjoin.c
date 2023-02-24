/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:26:15 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/04 12:38:03 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*prefix;
	char	*suffix;
	char	*joined;
	int		prefix_len;
	int		suffix_len;

	if (!(s1))
		return (0);
	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	prefix = (char *)s1;
	suffix = (char *)s2;
	joined = malloc(sizeof(char) * (prefix_len + suffix_len) + 1);
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, prefix, prefix_len + 1);
	joined += prefix_len;
	ft_strlcpy(joined, suffix, suffix_len + 1);
	joined += suffix_len;
	*joined = '\0';
	joined -= (prefix_len + suffix_len);
	return (joined);
}
