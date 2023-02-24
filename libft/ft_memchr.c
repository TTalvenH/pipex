/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:58:41 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 12:41:10 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ps;

	ps = s;
	while (n != 0)
	{
		if (*ps == (unsigned char) c)
			return ((void *)ps);
		ps++;
		n--;
	}
	return (0);
}
