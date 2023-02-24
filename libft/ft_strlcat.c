/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:10:15 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/10 17:41:58 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;

	if (!(dst) && dstsize == 0)
		return (ft_strlen(src));
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstsize != 0 && dstsize > dstl)
	{
		dst += dstl;
		while ((dstsize - dstl - 1) != 0 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			dstsize--;
		}
		*dst = '\0';
		return (srcl + dstl);
	}
	return (srcl + dstsize);
}
