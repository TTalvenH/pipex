/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:59:26 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 16:48:55 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	int		i;

	n = ft_strlen(needle);
	i = 0;
	if (!(haystack) && len == 0)
		return (NULL);
	while (*needle != '\0')
	{
		if (ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
		if (*haystack == '\0' || ((i + n) > len))
			return (0);
	}
	return ((char *)haystack);
}
