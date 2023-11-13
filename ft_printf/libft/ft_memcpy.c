/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:25:16 by paul              #+#    #+#             */
/*   Updated: 2023/10/13 14:17:06 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*mem_dest;

	if (!dest && !src)
		return (dest);
	mem_dest = dest;
	while (n > 0)
	{
		n --;
		*(unsigned char *)dest = *(unsigned char *)src;
		dest ++;
		src ++;
	}
	return (mem_dest);
}
