/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_remov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:41 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/24 15:21:29 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

// attention return error malloc
char	*ft_strdup_remov(char *str)
{
	int		last;
	int		i;
	char	*dup;

	last = ft_strlen(str);
	dup = NULL;
	if (str[last - 1] == '\n')
	{
		dup = malloc(sizeof(char) * last);
		if  (!dup)
			return (NULL);
		i = 0;
		while (str[i + 1])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
		free(str);
		return (dup);
	}
	return (str);
}

/*int		main(void)
{
	printf ("%s", ft_strdup_remov("Bijour\n\n\n\n"));
	return (0);
}*/
