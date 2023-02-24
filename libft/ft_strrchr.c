/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:19:10 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/09 16:14:05 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s) + 1;
	s += slen - 1;
	while (slen)
	{
		if ((char)c == *s)
			return ((char *)s);
		slen--;
		s--;
	}
	return (0);
}
