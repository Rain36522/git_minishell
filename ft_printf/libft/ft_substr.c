/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:55:21 by pudry             #+#    #+#             */
/*   Updated: 2023/10/13 18:11:11 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s) || len == 0)
		return (ft_calloc(1, sizeof(char)));
	while (i < start)
		i ++;
	s += i;
	if (ft_strlen(s) < len)
		len = ft_strlen(s) + 1;
	else
		len += 1;
	str = (char *) malloc(len);
	if (! str)
		return (NULL);
	len --;
	str[len] = '\0';
	ft_strlcpy(str, s, len + 1);
	return (str);
}
/*
int	main(void)
{
	ft_substr("hola", 2, 3);
	return (0);
}
*/