/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:19:38 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 17:19:54 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	int		s1_len;

	s1_len = ft_strlen(s1);
	s1_dup = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (s1_dup == NULL)
		return (NULL);
	ft_strlcpy(s1_dup, s1, s1_len + 1);
	return (s1_dup);
}
