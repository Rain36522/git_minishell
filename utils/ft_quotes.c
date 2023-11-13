/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:09:03 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 18:29:31 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*
 *	Check if single or double quotes aren't close
 *	return != 0 if quotes aren't closed
 *	2 = double
 *	1 = simple
 */
int	ft_quotes(char *str, int istatus)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && itatus == 2)
			istatus = 0;
		else if (str[i] == '\"' && itatus == 0)
			istatus = 2;
		else if (str[i] == '\'' && itatus == 1)
			istatus = 0;
		else if (str[i] == '\'' && itatus == 0)
			istatus = 1;
		i++;
	}
	return (istatus);
}
