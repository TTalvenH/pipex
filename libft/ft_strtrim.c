/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:17:10 by ttalvenh          #+#    #+#             */
/*   Updated: 2022/11/04 12:38:39 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		rev;
	int		copy_size;
	char	*copy;

	if (!(s1))
		return (0);
	rev = ft_strlen(s1);
	index = 0;
	while (ft_strchr(set, s1[index]) && s1[index] != '\0')
		index++;
	while (ft_strchr(set, s1[rev - 1]) && index != rev)
		rev--;
	copy_size = rev - index;
	copy = malloc(sizeof(char) * (copy_size + 1));
	if (!(copy))
		return (NULL);
	ft_strlcpy(copy, s1 + index, (copy_size + 1));
	return (copy);
}
