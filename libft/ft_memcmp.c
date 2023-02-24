/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:43:12 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/10/31 10:00:55 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	if (ps1 == ps2 || n == 0)
		return (0);
	while (n != 1 && (*ps1 == *ps2))
	{
		ps1++;
		ps2++;
		n--;
	}
	return (*ps1 - *ps2);
}
