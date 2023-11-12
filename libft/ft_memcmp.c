/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:25:16 by paul              #+#    #+#             */
/*   Updated: 2023/10/12 10:58:37 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > i && *(unsigned char *)str1 == *(unsigned char *)str2)
	{
		i ++;
		if (n > i && *(unsigned char *)str1 == *(unsigned char *)str2)
		{
			str1 ++;
			str2 ++;
		}
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
