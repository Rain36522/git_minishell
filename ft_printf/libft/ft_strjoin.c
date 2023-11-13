/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:05:36 by pudry             #+#    #+#             */
/*   Updated: 2023/10/11 15:31:48 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		isize;
	char	*mem_str;
	char	*str;

	isize = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(isize + 1);
	if (!str)
		return (NULL);
	str[isize] = '\0';
	mem_str = str;
	ft_strlcpy(str, s1, isize + 1);
	ft_strlcat(str, s2, isize + 1);
	return (mem_str);
}
