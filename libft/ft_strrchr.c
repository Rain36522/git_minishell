/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:33:07 by paul              #+#    #+#             */
/*   Updated: 2023/10/05 10:57:58 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*chr;

	ptr = (char *)s;
	chr = NULL;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			chr = ptr;
		ptr ++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (chr);
}
