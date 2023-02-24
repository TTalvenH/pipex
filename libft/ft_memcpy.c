/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:57 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 12:26:50 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*tmp2;

	tmp = dst;
	tmp2 = src;
	if (!(tmp) && !(tmp2))
		return (NULL);
	while (n > 0)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		n--;
	}
	return (dst);
}
