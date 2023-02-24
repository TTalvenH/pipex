/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:48:00 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/06 11:48:03 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	char		*psrc;

	pdst = (char *) dst;
	psrc = (char *)src;
	if (psrc < pdst)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	else
		ft_memcpy(pdst, psrc, len);
	return (pdst);
}
