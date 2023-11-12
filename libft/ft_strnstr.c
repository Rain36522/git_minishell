/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:03:05 by paul              #+#    #+#             */
/*   Updated: 2023/10/13 14:17:54 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *ref, size_t n)
{
	size_t	i;

	i = 0;
	if (!*ref)
		return ((char *)str);
	else if ((!str && !n) || (!ref && !n))
		return (NULL);
	while (*str && i < n)
	{
		if (*str == *ref)
		{
			if (ft_strncmp(str, ref, ft_strlen(ref)) == 0 && \
			(ft_strlen(ref) + i) <= n)
				return ((char *)str);
		}
		str ++;
		i ++;
	}
	return (NULL);
}
