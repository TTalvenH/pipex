/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:20:54 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/06 10:55:42 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	s_len;
	size_t	diff;

	if (!(s))
		return (0);
	s_len = ft_strlen(s);
	diff = s_len;
	if (start <= s_len)
		diff = diff - start;
	i = 0;
	if (len < diff)
		sub_s = malloc(sizeof(char) * (len + 1));
	else
		sub_s = malloc(sizeof(char) * (diff + 1));
	if (!(sub_s))
		return (NULL);
	while ((i < len && s[start] != '\0') && start < s_len)
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}
