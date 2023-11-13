/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:55 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 13:35:35 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_quotes(char *str)
{
	int		i;
	int		i_double;
	int		i_single;

	i_double = 0;
	i_single = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			i_double++;
		else if (str[i] == 39)
			i_single++;
		i++;
	}
	if ((i_double % 2) != 0)
		return (1);
	else if ((i_single % 2) != 0)
		return (1);
	return (0);
}

