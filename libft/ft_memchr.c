/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:25:16 by paul              #+#    #+#             */
/*   Updated: 2023/10/10 09:59:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t n)
{
	unsigned char	*s;

	s = str;
	while (n > 0 && *s != (unsigned char)c)
	{
		n --;
		s ++;
	}
	if (n == 0)
		return (NULL);
	return ((void *)s);
}
