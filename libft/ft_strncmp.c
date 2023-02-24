/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:56:43 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 19:33:28 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((n > 1 && *s1 == *s2) && (*s1 || *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned const char)*s1 - (unsigned const char)*s2);
}
