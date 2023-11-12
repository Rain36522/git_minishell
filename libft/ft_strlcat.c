/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:33:07 by paul              #+#    #+#             */
/*   Updated: 2023/10/12 12:40:24 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((!src && n == 0) || (!dest && n == 0))
		return (0);
	while (*dest != '\0' && i < n)
	{
		dest ++;
		i ++;
	}
	while (*src != '\0' && i + 1 < n)
	{
		*dest ++ = *src ++;
		i ++;
	}	
	if (i < n)
		*dest = '\0';
	while (*src ++ != '\0')
		i ++;
	return (i);
}
