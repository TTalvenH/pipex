/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:47:38 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/03 19:22:34 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr_fd("(null)", 1);
		return (count);
	}
	while (*s)
		count += ft_putchar_fd(*s++, fd);
	return (count);
}
