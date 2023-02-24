/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:32:06 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/07 11:57:10 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n < 10 && n > -10)
		count++;
	else
	{
		while (n / 10)
		{
			count++;
			n = n / 10;
		}
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		n_len;
	int		sign;
	int		i;
	char	*new_str;

	sign = 1;
	n_len = intlen(n);
	i = n_len;
	new_str = malloc(sizeof(char) * (n_len + 1));
	if (!(new_str))
		return (NULL);
	new_str[n_len--] = '\0';
	if (n < 0)
	{
		sign = -1;
		new_str[0] = '-';
		i--;
	}
	while (i-- > 0)
	{
		new_str[n_len--] = (n % 10) * sign + '0';
		if (n / 10)
			n = n / 10;
	}
	return (new_str);
}
