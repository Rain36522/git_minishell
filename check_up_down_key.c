/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up_down_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:48:15 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 12:59:16 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"

int	find_str(char *str, char *to_find)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (strncmp(str + i, to_find, ft_strlen(to_find)) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_up_down_key(char *str)
{
	if (find_str(str, "\e[A") == 1)
	   return (1);
	else if (find_str(str, "\e[B") == 1)
		return (1);
	return (0);	
}
