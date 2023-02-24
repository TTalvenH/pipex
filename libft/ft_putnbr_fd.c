/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:53:44 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/02/15 18:03:30 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n < -9)
	{
		count += ft_putchar_fd('-', fd);
		count += ft_putnbr_fd((n / 10) * (-1), fd);
		count += ft_putnbr_fd((n % 10) * (-1), fd);
	}
	else if (n < 0 && n > -10)
	{
		count += ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	else if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9 && n >= 0)
		count += ft_putchar_fd(n + '0', fd);
	return (count);
}
