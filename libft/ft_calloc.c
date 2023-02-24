/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:25:58 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/06 11:05:13 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((count * size) / size != count)
		return (NULL);
	a = malloc (count * size);
	if (!a)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}
