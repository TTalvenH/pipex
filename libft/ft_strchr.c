/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:49 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/04 09:31:58 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s) + 1;
	while (slen)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
		slen--;
	}
	return (0);
}
