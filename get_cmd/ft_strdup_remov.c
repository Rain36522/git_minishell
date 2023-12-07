/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_remov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:51:41 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/07 12:51:49 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include <stdio.h>

static char	*ft_remove_dup(t_acmd *cmd)
{
	ft_free_array(cmd->array);
	cmd->array = NULL;
	free(cmd);
	cmd = NULL;
	ft_error_ptr(12, 1, NULL, NULL);
	return (NULL);
}

// attention return error malloc
char	*ft_strdup_remov(char *str, t_acmd	*cmd)
{
	int		last;
	int		i;
	char	*dup;

	last = ft_strlen(str);
	dup = NULL;
	if (!(str[last - 1] == '\n'))
		return (str);
	dup = malloc(sizeof(char) * (last));
	if (!dup)
		return (ft_remove_dup(cmd));
	dup[last - 1] = '\0';
	i = 0;
	while (str[i + 1])
	{
		dup[i] = str[i];
		i++;
	}
	str = ft_free_str(str);
	return (dup);
}

/*int		main(void)
{
	printf ("%s", ft_strdup_remov("Bijour\n\n\n\n"));
	return (0);
}*/
